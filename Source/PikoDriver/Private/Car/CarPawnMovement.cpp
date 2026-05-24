#include "CarPawn.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"



void ACarPawn::ApplyDrivingForces(float DeltaTime)
{
	if (!PhysicsBody || !PhysicsBody->IsSimulatingPhysics())
	{
		return;
	}
	
	// Update smoothed steering input
	SmoothedSteeringInput = FMath::FInterpTo(
		SmoothedSteeringInput,
		SteeringInput,
		DeltaTime,
		SteeringInputInterpSpeed
	);

	// Movement state getter
	FCarMovementState MovementState = GetMovementState();

	// Steering calculations
	const FVector TorqueToApply = CalculateTorque(MovementState);


	// Acceleration calculations
	const FVector ForceToApply = CalculateAccelerationForce(MovementState);


	// Apply forces and torque to the physics body
	PhysicsBody->AddForce(ForceToApply);
	PhysicsBody->AddTorqueInRadians(TorqueToApply);
	ApplyLateralGrip(MovementState, DeltaTime);
}

FCarMovementState ACarPawn::GetMovementState() const
{
	FCarMovementState State;

	if (!PhysicsBody)
	{
		return State;
	}

	State.Velocity = PhysicsBody->GetPhysicsLinearVelocity();
	State.HorizontalVelocity = FVector(State.Velocity.X, State.Velocity.Y, 0.0f);

	State.ForwardVector = PhysicsBody->GetForwardVector();
	State.RightVector = PhysicsBody->GetRightVector();

	// Keep movement calculations horizontal for now.
	State.ForwardVector.Z = 0.0f;
	State.RightVector.Z = 0.0f;

	State.ForwardVector.Normalize();
	State.RightVector.Normalize();

	State.HorizontalSpeed = State.HorizontalVelocity.Size();

	State.ForwardSpeed = FVector::DotProduct(
		State.HorizontalVelocity,
		State.ForwardVector
	);

	State.SideSpeed = FVector::DotProduct(
		State.HorizontalVelocity,
		State.RightVector
	);

	State.AbsForwardSpeed = FMath::Abs(State.ForwardSpeed);

	State.NormalizedSpeed = FMath::Clamp(
		State.AbsForwardSpeed / MaxForwardSpeed,
		0.0f,
		1.0f
	);

	State.RawSteeringInput = SteeringInput;
	State.SmoothedSteeringInput = SmoothedSteeringInput;

	return State;
}

FVector ACarPawn::CalculateTorque(const FCarMovementState& MovementState) const
{
	float SteeringEfficiency = 1.0f;

	if (SteeringEfficiencyCurve)
	{
		SteeringEfficiency =
			SteeringEfficiencyCurve->GetFloatValue(MovementState.NormalizedSpeed);
	}

	const float ReverseSteeringSpeedThreshold = 10.0f;

	const float SteeringDirectionMultiplier =
		MovementState.ForwardSpeed < -ReverseSteeringSpeedThreshold
		? -1.0f
		: 1.0f;

	return FVector(
		0.0f,
		0.0f,
		MovementState.SmoothedSteeringInput
		* SteeringDirectionMultiplier
		* SteeringTorque
		* SteeringEfficiency
	);
}

FVector ACarPawn::CalculateAccelerationForce(const FCarMovementState& MovementState) const
{
	if (bHandbrakeActive)
	{
		const float HandbrakeSpeedThreshold = 10.0f;

		if (FMath::Abs(MovementState.ForwardSpeed) <= HandbrakeSpeedThreshold)
		{
			return FVector::ZeroVector;
		}

		return
			-MovementState.ForwardVector
			* FMath::Sign(MovementState.ForwardSpeed)
			* HandbrakeBrakeForce;
	}

	const float InputDeadzone = 0.05f;
	const float DirectionChangeSpeedThreshold = 50.0f;

	if (FMath::Abs(ThrottleInput) <= InputDeadzone)
	{
		return FVector::ZeroVector;
	}

	const bool bWantsToMoveForward = ThrottleInput > 0.0f;
	const bool bWantsToMoveBackward = ThrottleInput < 0.0f;

	const bool bMovingForward = MovementState.ForwardSpeed > DirectionChangeSpeedThreshold;
	const bool bMovingBackward = MovementState.ForwardSpeed < -DirectionChangeSpeedThreshold;

	const bool bNeedsToBrakeBeforeForward =
		bWantsToMoveForward && bMovingBackward;

	const bool bNeedsToBrakeBeforeReverse =
		bWantsToMoveBackward && bMovingForward;

	if (bNeedsToBrakeBeforeForward || bNeedsToBrakeBeforeReverse)
	{
		return
			-MovementState.ForwardVector
			* FMath::Sign(MovementState.ForwardSpeed)
			* BrakeForce
			* FMath::Abs(ThrottleInput);
	}

	const float BaseAccelerationForce =
		ThrottleInput >= 0.0f
		? AccelerationForce
		: ReverseAccelerationForce;

	const float MaxDirectionalSpeed =
		ThrottleInput >= 0.0f
		? MaxForwardSpeed
		: MaxReverseSpeed;

	const float CurrentDirectionalSpeed =
		ThrottleInput >= 0.0f
		? FMath::Max(MovementState.ForwardSpeed, 0.0f)
		: FMath::Max(-MovementState.ForwardSpeed, 0.0f);

	const float NormalizedDirectionalSpeed = FMath::Clamp(
		CurrentDirectionalSpeed / MaxDirectionalSpeed,
		0.0f,
		1.0f
	);

	float AccelerationMultiplier = 1.0f;

	if (AccelerationForceCurve)
	{
		AccelerationMultiplier =
			AccelerationForceCurve->GetFloatValue(NormalizedDirectionalSpeed);
	}
	else
	{
		AccelerationMultiplier = FMath::Lerp(
			MinAccelerationFactor,
			1.0f,
			FMath::Pow(1.0f - NormalizedDirectionalSpeed, AccelerationFalloffExponent)
		);
	}

	return
		MovementState.ForwardVector
		* ThrottleInput
		* BaseAccelerationForce
		* AccelerationMultiplier;
}

void ACarPawn::ApplyLateralGrip(const FCarMovementState& MovementState, const float DeltaTime)
{
	const FVector VerticalVelocity = FVector(0.0f, 0.0f, MovementState.Velocity.Z);

	const FVector ForwardVelocity =
		MovementState.ForwardVector * MovementState.ForwardSpeed;

	const FVector SideVelocity =
		MovementState.RightVector * MovementState.SideSpeed;

	const float EffectiveLateralGrip =
		bHandbrakeActive
		? HandbrakeLateralGrip
		: LateralGrip;

	const float GripAlpha = FMath::Clamp(EffectiveLateralGrip * DeltaTime, 0.0f, 1.0f);

	const FVector CorrectedSideVelocity =
		FMath::Lerp(SideVelocity, FVector::ZeroVector, GripAlpha);

	const FVector NewVelocity =
		ForwardVelocity + CorrectedSideVelocity + VerticalVelocity;

	PhysicsBody->SetPhysicsLinearVelocity(NewVelocity);
}