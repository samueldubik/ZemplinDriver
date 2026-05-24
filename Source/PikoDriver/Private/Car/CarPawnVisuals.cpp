#include "CarPawn.h"

void ACarPawn::UpdateWheelVisuals(float DeltaTime)
{
	const FCarMovementState MovementState = GetMovementState();

	const float SpeedCmS = MovementState.HorizontalSpeed;
	const float SpeedKmh = MovementState.ForwardSpeed * 0.036f;

	// Example wheel radius. Adjust to your mesh.
	const float WheelRadiusCm = 34.0f;
	const float WheelCircumferenceCm = 2.0f * PI * WheelRadiusCm;

	// How many full rotations this frame?
	const float RotationsThisFrame = SpeedCmS * DeltaTime / WheelCircumferenceCm;

	// Convert to degrees.
	WheelSpinAngle += RotationsThisFrame * 360.0f;

	// Prevent float from growing forever.
	WheelSpinAngle = FMath::Fmod(WheelSpinAngle, 360.0f);

	const float MaxVisualSteerAngle = 32.0f;

	WheelSteerAngle = FMath::FInterpTo(
		WheelSteerAngle,
		MovementState.SmoothedSteeringInput * MaxVisualSteerAngle,
		DeltaTime,
		12.0f
	);

	// You may need to change axes depending on your wheel mesh orientation.
	const FRotator SpinRotation(WheelSpinAngle, 0.0f, 0.0f);
	const FRotator FrontWheelRotation(WheelSpinAngle, WheelSteerAngle, 0.0f);

	LeftFrontWheelMesh->SetRelativeRotation(FrontWheelRotation);
	RightFrontWheelMesh->SetRelativeRotation(FrontWheelRotation);

	LeftRearWheelMesh->SetRelativeRotation(SpinRotation);
	RightRearWheelMesh->SetRelativeRotation(SpinRotation);
}