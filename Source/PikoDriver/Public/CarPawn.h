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
	float MouseLookSensitivity = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	float MinCameraPitch = -35.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	float MaxCameraPitch = 10.0f;

	float CameraYaw = 0.0f;
	float CameraPitch = -18.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving", meta = (AllowPrivateAccess = "true"))
	float AccelerationForce = 3500000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving", meta = (AllowPrivateAccess = "true"))
	float SteeringTorque = 250000000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving", meta = (AllowPrivateAccess = "true"))
	float LinearDamping = 0.4f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving", meta = (AllowPrivateAccess = "true"))
	float AngularDamping = 1.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving", meta = (AllowPrivateAccess = "true"))
	float CarMassKg = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving", meta = (AllowPrivateAccess = "true"))
	float LateralGrip = 8.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Steering", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCurveFloat> SteeringEfficiencyCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Steering", meta = (AllowPrivateAccess = "true"))
	float MaxForwardSpeed = 6000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Steering", meta = (AllowPrivateAccess = "true"))
	float SteeringInputInterpSpeed = 14.0f;

	float SmoothedSteeringInput = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Acceleration", meta = (AllowPrivateAccess = "true"))
	float ReverseAccelerationForce = 1800000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Acceleration", meta = (AllowPrivateAccess = "true"))
	float BrakeForce = 5000000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Acceleration", meta = (AllowPrivateAccess = "true"))
	float CoastingDragForce = 350000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Acceleration", meta = (AllowPrivateAccess = "true"))
	float MaxReverseSpeed = 2500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Acceleration", meta = (AllowPrivateAccess = "true"))
	float AccelerationFalloffExponent = 1.6f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Driving|Acceleration", meta = (AllowPrivateAccess = "true"))
	float MinAccelerationFactor = 0.12f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug", meta = (AllowPrivateAccess = "true"))
	bool bUseKeyboardFallback = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug", meta = (AllowPrivateAccess = "true"))
	bool bShowDebugInput = true;

private:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	void ShowDebugInput();

	FCarMovementState GetMovementState() const;
	void ApplyDrivingForces(float DeltaTime);
	void ApplyLateralGrip(const FCarMovementState& MovementState);
	FVector GetTorque(float DeltaTime);
	FVector CalculateTorque(const FCarMovementState& MovementState) const;
};