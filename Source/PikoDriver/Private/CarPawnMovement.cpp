
#include "CarPawn.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"



void ACarPawn::ApplyDrivingForces(float DeltaTime)
{
	if (!PhysicsBody || !PhysicsBody->IsSimulatingPhysics())
	{
		return;
	}
	
	const FCarMovementState	MovementState = GetMovementState();

	const FVector ForceToApply =
		MovementState.ForwardVector * ThrottleInput * AccelerationForce;


	const FVector TorqueToApply = GetTorque(DeltaTime);

	PhysicsBody->AddForce(ForceToApply);
	PhysicsBody->AddTorqueInRadians(TorqueToApply);
	ApplyLateralGrip(MovementState);
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

FVector ACarPawn::GetTorque(float DeltaTime)
{
	SmoothedSteeringInput = FMath::FInterpTo(
		SmoothedSteeringInput,
		SteeringInput,
		DeltaTime,
		SteeringInputInterpSpeed
	);

	FCarMovementState MovementState = GetMovementState();

	MovementState.RawSteeringInput = SteeringInput;
	MovementState.SmoothedSteeringInput = SmoothedSteeringInput;

	return CalculateTorque(MovementState);

}

FVector ACarPawn::CalculateTorque(const FCarMovementState& MovementState) const
{
	float SteeringEfficiency = 1.0f;

	if (SteeringEfficiencyCurve)
	{
		SteeringEfficiency =
			SteeringEfficiencyCurve->GetFloatValue(MovementState.NormalizedSpeed);
	}

	return FVector(
		0.0f,
		0.0f,
		MovementState.SmoothedSteeringInput * SteeringTorque * SteeringEfficiency
	);
}

void ACarPawn::ApplyLateralGrip(const FCarMovementState& MovementState)
{
	const UWorld* World = GetWorld();

	if (!World)
	{
		return;
	}

	const float DeltaTime = World->GetDeltaSeconds();

	FVector ForwardVector = MovementState.ForwardVector;
	FVector RightVector = MovementState.RightVector;

	ForwardVector.Z = 0.0f;
	RightVector.Z = 0.0f;

	ForwardVector.Normalize();
	RightVector.Normalize();

	const FVector VerticalVelocity = FVector(0.0f, 0.0f, MovementState.Velocity.Z);
	const FVector HorizontalVelocity = MovementState.Velocity - VerticalVelocity;

	const float ForwardSpeed = FVector::DotProduct(HorizontalVelocity, ForwardVector);
	const float SideSpeed = FVector::DotProduct(HorizontalVelocity, RightVector);

	const FVector ForwardVelocity = ForwardVector * ForwardSpeed;
	const FVector SideVelocity = RightVector * SideSpeed;

	const float GripAlpha = FMath::Clamp(LateralGrip * DeltaTime, 0.0f, 1.0f);

	const FVector CorrectedSideVelocity =
		FMath::Lerp(SideVelocity, FVector::ZeroVector, GripAlpha);

	const FVector NewVelocity =
		ForwardVelocity + CorrectedSideVelocity + VerticalVelocity;

	PhysicsBody->SetPhysicsLinearVelocity(NewVelocity);
}