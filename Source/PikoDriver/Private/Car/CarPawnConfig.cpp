#include "CarPawnConfig.h"

namespace CarPawnConfig
{
	extern const float MouseLookSensitivity = 1.0f;
	extern const float MinCameraPitch = -35.0f;
	extern const float MaxCameraPitch = 10.0f;
	extern const float InitialCameraPitch = -18.0f;

	extern const float AccelerationForce = 4000000.0f;
	extern const float SteeringTorque = 300000000.0f;
	extern const float LinearDamping = 0.005f;
	extern const float AngularDamping = 5.0f;
	extern const float CarMassKg = 1633.0f;
	extern const float LateralGrip = 3.5f;

	extern const float MaxForwardSpeed = 7500.0f;
	extern const float SteeringInputInterpSpeed = 10.0f;

	extern const float ReverseAccelerationForce = 2800000.0f;
	extern const float BrakeForce = 4500000.0f;
	extern const float CoastingDragForce = 100000.0f;
	extern const float MaxReverseSpeed = 3000.0f;
	extern const float AccelerationFalloffExponent = 1.6f;
	extern const float MinAccelerationFactor = 0.12f;

	extern const bool bUseKeyboardFallback = true;
	extern const bool bShowDebugInput = true;

	extern const float HandbrakeBrakeForce = 3500000.0f;
	extern const float HandbrakeLateralGrip = 2.0f;
}