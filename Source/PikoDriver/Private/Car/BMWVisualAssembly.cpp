#include "BMWVisualAssembly.h"
#include "Components/StaticMeshComponent.h"

ABMWVisualAssembly::ABMWVisualAssembly()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ABMWVisualAssembly::BeginPlay()
{
	Super::BeginPlay();

	FrontLeftTyreMesh = FindStaticMeshComponentByName(TEXT("SK_Tyre_Front_Left"));
	FrontRightTyreMesh = FindStaticMeshComponentByName(TEXT("SK_Tyre_Front_Right"));
	RearLeftTyreMesh = FindStaticMeshComponentByName(TEXT("SK_Tyre_Rear_Left"));
	RearRightTyreMesh = FindStaticMeshComponentByName(TEXT("SK_Tyre_Rear_Right"));

	if (!FrontLeftTyreMesh || !FrontRightTyreMesh || !RearLeftTyreMesh || !RearRightTyreMesh)
	{
		UE_LOG(LogTemp, Warning, TEXT("BMWVisualAssembly: Could not find one or more tyre mesh components."));
	}
	else
	{
		FrontLeftTyreInitialRotation = FrontLeftTyreMesh->GetRelativeRotation().Quaternion();
		FrontRightTyreInitialRotation = FrontRightTyreMesh->GetRelativeRotation().Quaternion();
		RearLeftTyreInitialRotation = RearLeftTyreMesh->GetRelativeRotation().Quaternion();
		RearRightTyreInitialRotation = RearRightTyreMesh->GetRelativeRotation().Quaternion();

		UE_LOG(LogTemp, Warning, TEXT("BMWVisualAssembly: All tyre mesh components found."));
	}
}

UStaticMeshComponent* ABMWVisualAssembly::FindStaticMeshComponentByName(FName ComponentName) const
{
	TArray<UStaticMeshComponent*> MeshComponents;
	GetComponents<UStaticMeshComponent>(MeshComponents);

	for (UStaticMeshComponent* MeshComponent : MeshComponents)
	{
		if (MeshComponent && MeshComponent->GetFName() == ComponentName)
		{
			return MeshComponent;
		}
	}

	return nullptr;
}

void ABMWVisualAssembly::UpdateWheelVisuals(float DeltaTime, float ForwardSpeedCmS, float SteeringInput)
{
	if (!FrontLeftTyreMesh || !FrontRightTyreMesh || !RearLeftTyreMesh || !RearRightTyreMesh)
	{
		return;
	}

	const float WheelRadiusCm = 34.0f;
	const float WheelCircumferenceCm = 2.0f * PI * WheelRadiusCm;
	const float RotationsThisFrame = ForwardSpeedCmS * DeltaTime / WheelCircumferenceCm;

	WheelSpinAngle += RotationsThisFrame * 360.0f;
	WheelSpinAngle = FMath::Fmod(WheelSpinAngle, 360.0f);

	const float MaxVisualSteerAngle = 32.0f;

	WheelSteerAngle = FMath::FInterpTo(
		WheelSteerAngle,
		SteeringInput * MaxVisualSteerAngle,
		DeltaTime,
		12.0f
	);

	const FQuat SpinRotation(FVector::ForwardVector, FMath::DegreesToRadians(-WheelSpinAngle));
	const FQuat SteerRotation(FVector::RightVector, FMath::DegreesToRadians(-WheelSteerAngle));

	FrontLeftTyreMesh->SetRelativeRotation((FrontLeftTyreInitialRotation * SteerRotation * SpinRotation).Rotator());
	FrontRightTyreMesh->SetRelativeRotation((FrontRightTyreInitialRotation * SteerRotation * SpinRotation).Rotator());

	RearLeftTyreMesh->SetRelativeRotation((RearLeftTyreInitialRotation * SpinRotation).Rotator());
	RearRightTyreMesh->SetRelativeRotation((RearRightTyreInitialRotation * SpinRotation).Rotator());
}