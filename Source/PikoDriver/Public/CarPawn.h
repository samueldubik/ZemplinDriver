#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "CarPawn.generated.h"

// Forward declarations
class UBoxComponent;
class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class UCurveFloat;

struct FCarMovementState
{
	FVector Velocity = FVector::ZeroVector;
	FVector HorizontalVelocity = FVector::ZeroVector;

	FVector ForwardVector = FVector::ForwardVector;
	FVector RightVector = FVector::RightVector;

	float HorizontalSpeed = 0.0f;
	float ForwardSpeed = 0.0f;
	float SideSpeed = 0.0f;
	float AbsForwardSpeed = 0.0f;
	float NormalizedSpeed = 0.0f;

	float RawSteeringInput = 0.0f;
	float SmoothedSteeringInput = 0.0f;
};

// This is an unreal engine class
UCLASS()


class PIKODRIVER_API ACarPawn : public APawn
{
	// Insert Unreal Engine's generated code for reflection and other features 
	GENERATED_BODY()

public:
	ACarPawn();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAcces = "true"))
	TObjectPtr<UInputAction> LookAction;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> PhysicsBody;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> CarMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	float ThrottleInput = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	float SteeringInput = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	float MouseLookSensitivity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	float MinCameraPitch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	float MaxCameraPitch;

	float CameraYaw = 0.0f;
	float CameraPitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving", meta = (AllowPrivateAccess = "true"))
	float AccelerationForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving", meta = (AllowPrivateAccess = "true"))
	float SteeringTorque;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving", meta = (AllowPrivateAccess = "true"))
	float LinearDamping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving", meta = (AllowPrivateAccess = "true"))
	float AngularDamping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving", meta = (AllowPrivateAccess = "true"))
	float CarMassKg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving", meta = (AllowPrivateAccess = "true"))
	float LateralGrip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Steering", meta = (AllowPrivateAccess = "true"))
	float MaxForwardSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Steering", meta = (AllowPrivateAccess = "true"))
	float SteeringInputInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Steering", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCurveFloat> SteeringEfficiencyCurve;

	float SmoothedSteeringInput = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Acceleration", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCurveFloat> AccelerationForceCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Acceleration", meta = (AllowPrivateAccess = "true"))
	float ReverseAccelerationForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Acceleration", meta = (AllowPrivateAccess = "true"))
	float BrakeForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Acceleration", meta = (AllowPrivateAccess = "true"))
	float CoastingDragForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Acceleration", meta = (AllowPrivateAccess = "true"))
	float MaxReverseSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Acceleration", meta = (AllowPrivateAccess = "true"))
	float AccelerationFalloffExponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Acceleration", meta = (AllowPrivateAccess = "true"))
	float MinAccelerationFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug", meta = (AllowPrivateAccess = "true"))
	bool bUseKeyboardFallback;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug", meta = (AllowPrivateAccess = "true"))
	bool bShowDebugInput;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> HandbrakeAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	bool bHandbrakeActive = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Braking", meta = (AllowPrivateAccess = "true"))
	float HandbrakeBrakeForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Braking", meta = (AllowPrivateAccess = "true"))
	float HandbrakeLateralGrip;

private:		
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Handbrake(const FInputActionValue& Value);

	void ShowDebugInput();

	FCarMovementState GetMovementState() const;
	void ApplyDrivingForces(float DeltaTime);
	void ApplyLateralGrip(const FCarMovementState& MovementState, const float DeltaTime);
	FVector CalculateTorque(const FCarMovementState& MovementState) const;
	FVector CalculateAccelerationForce(const FCarMovementState& MovementState) const;
};