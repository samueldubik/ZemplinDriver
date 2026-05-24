#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BMWVisualAssembly.generated.h"

class UStaticMeshComponent;

UCLASS()
class PIKODRIVER_API ABMWVisualAssembly : public AActor
{
	GENERATED_BODY()

public:
	ABMWVisualAssembly();

	void UpdateWheelVisuals(float DeltaTime, float ForwardSpeedCmS, float SteeringInput);

protected:
	virtual void BeginPlay() override;

private:
	UStaticMeshComponent* FrontLeftTyreMesh = nullptr;
	UStaticMeshComponent* FrontRightTyreMesh = nullptr;
	UStaticMeshComponent* RearLeftTyreMesh = nullptr;
	UStaticMeshComponent* RearRightTyreMesh = nullptr;

	FQuat FrontLeftTyreInitialRotation = FQuat::Identity;
	FQuat FrontRightTyreInitialRotation = FQuat::Identity;
	FQuat RearLeftTyreInitialRotation = FQuat::Identity;
	FQuat RearRightTyreInitialRotation = FQuat::Identity;

	float WheelSpinAngle = 0.0f;
	float WheelSteerAngle = 0.0f;

	UStaticMeshComponent* FindStaticMeshComponentByName(FName ComponentName) const;
};