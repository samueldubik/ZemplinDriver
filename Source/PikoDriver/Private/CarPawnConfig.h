#pragma once

namespace CarPawnConfig
{
    extern const float MouseLookSensitivity;
    extern const float MinCameraPitch;
    extern const float MaxCameraPitch;
    extern const float InitialCameraPitch;

    extern const float AccelerationForce;
    extern const float SteeringTorque;
    extern const float LinearDamping;
    extern const float AngularDamping;
    extern const float CarMassKg;
    extern const float LateralGrip;

    extern const float MaxForwardSpeed;
    extern const float SteeringInputInterpSpeed;

    extern const float ReverseAccelerationForce;
    extern const float BrakeForce;
    extern const float CoastingDragForce;
    extern const float MaxReverseSpeed;
    extern const float AccelerationFalloffExponent;
    extern const float MinAccelerationFactor;

    extern const bool bUseKeyboardFallback;
    extern const bool bShowDebugInput;

    extern const float HandbrakeBrakeForce;
    extern const float HandbrakeLateralGrip;
}