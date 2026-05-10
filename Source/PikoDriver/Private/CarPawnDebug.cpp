#include "CarPawn.h"

#include "Components/BoxComponent.h"
#include "Curves/CurveFloat.h"
#include "Engine/Engine.h"

void ACarPawn::ShowDebugInput()
{
	if (!bShowDebugInput || !GEngine)
	{
		return;
	}

	if (!PhysicsBody || !PhysicsBody->IsSimulatingPhysics())
	{
		GEngine->AddOnScreenDebugMessage(
			1,
			0.0f,
			FColor::Red,
			TEXT("[Car Debug] PhysicsBody missing or not simulating physics")
		);

		return;
	}

	const FCarMovementState MovementState = GetMovementState();

	float SteeringEfficiency = 1.0f;

	if (SteeringEfficiencyCurve)
	{
		SteeringEfficiency = SteeringEfficiencyCurve->GetFloatValue(MovementState.NormalizedSpeed);
	}

	const float SpeedKmh = MovementState.HorizontalSpeed * 0.036f;
	const float ForwardSpeedKmh = MovementState.ForwardSpeed * 0.036f;
	const float SideSpeedKmh = MovementState.SideSpeed * 0.036f;

	const float CurrentMass = PhysicsBody->GetMass();

	const float CurrentAngularVelocityZ =
		PhysicsBody->GetPhysicsAngularVelocityInRadians().Z;

	const float CurrentSteeringTorque =
		MovementState.SmoothedSteeringInput * SteeringTorque * SteeringEfficiency;

	const float CurrentThrottleForce =
		ThrottleInput * AccelerationForce;

	// ---------------------------------------------------------------------
	// INPUT
	// ---------------------------------------------------------------------

	GEngine->AddOnScreenDebugMessage(
		1,
		0.0f,
		FColor::Yellow,
		FString::Printf(
			TEXT("[Input] Throttle: %.2f | Steering Raw: %.2f | Steering Smooth: %.2f"),
			ThrottleInput,
			SteeringInput,
			MovementState.SmoothedSteeringInput
		)
	);

	// ---------------------------------------------------------------------
	// STEERING
	// ---------------------------------------------------------------------

	GEngine->AddOnScreenDebugMessage(
		2,
		0.0f,
		FColor::Green,
		FString::Printf(
			TEXT("[Steering] Efficiency: %.2f | Torque Setting: %.0f | Applied Torque Z: %.0f | Angular Vel Z: %.2f"),
			SteeringEfficiency,
			SteeringTorque,
			CurrentSteeringTorque,
			CurrentAngularVelocityZ
		)
	);

	GEngine->AddOnScreenDebugMessage(
		3,
		0.0f,
		FColor::Green,
		FString::Printf(
			TEXT("[Steering Tune] InterpSpeed: %.2f | Curve Speed X: %.2f"),
			SteeringInputInterpSpeed,
			MovementState.NormalizedSpeed
		)
	);

	// ---------------------------------------------------------------------
	// ACCELERATION / SPEED
	// ---------------------------------------------------------------------

	GEngine->AddOnScreenDebugMessage(
		4,
		0.0f,
		FColor::Cyan,
		FString::Printf(
			TEXT("[Speed] Total: %.1f km/h | Forward: %.1f km/h | Side: %.1f km/h | Normalized: %.2f"),
			SpeedKmh,
			ForwardSpeedKmh,
			SideSpeedKmh,
			MovementState.NormalizedSpeed
		)
	);

	GEngine->AddOnScreenDebugMessage(
		5,
		0.0f,
		FColor::Cyan,
		FString::Printf(
			TEXT("[Acceleration] Force Setting: %.0f | Applied Force: %.0f | MaxForwardSpeed: %.0f cm/s"),
			AccelerationForce,
			CurrentThrottleForce,
			MaxForwardSpeed
		)
	);

	// ---------------------------------------------------------------------
	// GRIP / SLIDING
	// ---------------------------------------------------------------------

	GEngine->AddOnScreenDebugMessage(
		6,
		0.0f,
		FColor::Orange,
		FString::Printf(
			TEXT("[Grip] LateralGrip: %.2f | SideSpeed: %.1f km/h | Side/Total Ratio: %.2f"),
			LateralGrip,
			SideSpeedKmh,
			MovementState.HorizontalSpeed > KINDA_SMALL_NUMBER
			? FMath::Abs(MovementState.SideSpeed) / MovementState.HorizontalSpeed
			: 0.0f
		)
	);

	// ---------------------------------------------------------------------
	// PHYSICS
	// ---------------------------------------------------------------------

	GEngine->AddOnScreenDebugMessage(
		7,
		0.0f,
		FColor::Silver,
		FString::Printf(
			TEXT("[Physics] Mass: %.0f kg | LinearDamping: %.2f | AngularDamping: %.2f"),
			CurrentMass,
			LinearDamping,
			AngularDamping
		)
	);

	GEngine->AddOnScreenDebugMessage(
		8,
		0.0f,
		FColor::Silver,
		FString::Printf(
			TEXT("[Velocity] X: %.0f | Y: %.0f | Z: %.0f"),
			MovementState.Velocity.X,
			MovementState.Velocity.Y,
			MovementState.Velocity.Z
		)
	);
}