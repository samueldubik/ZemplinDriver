#include "CarPawn.h"
#include "CarPawnConfig.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputCoreTypes.h"

ACarPawn::ACarPawn()
{
	MouseLookSensitivity = CarPawnConfig::MouseLookSensitivity;
	MinCameraPitch = CarPawnConfig::MinCameraPitch;
	MaxCameraPitch = CarPawnConfig::MaxCameraPitch;
	CameraPitch = CarPawnConfig::InitialCameraPitch;

	AccelerationForce = CarPawnConfig::AccelerationForce;
	SteeringTorque = CarPawnConfig::SteeringTorque;
	LinearDamping = CarPawnConfig::LinearDamping;
	AngularDamping = CarPawnConfig::AngularDamping;
	CarMassKg = CarPawnConfig::CarMassKg;
	LateralGrip = CarPawnConfig::LateralGrip;
	MaxForwardSpeed = CarPawnConfig::MaxForwardSpeed;
	SteeringInputInterpSpeed = CarPawnConfig::SteeringInputInterpSpeed;

	ReverseAccelerationForce = CarPawnConfig::ReverseAccelerationForce;
	BrakeForce = CarPawnConfig::BrakeForce;
	CoastingDragForce = CarPawnConfig::CoastingDragForce;
	MaxReverseSpeed = CarPawnConfig::MaxReverseSpeed;
	AccelerationFalloffExponent = CarPawnConfig::AccelerationFalloffExponent;
	MinAccelerationFactor = CarPawnConfig::MinAccelerationFactor;

	bUseKeyboardFallback = CarPawnConfig::bUseKeyboardFallback;
	bShowDebugInput = CarPawnConfig::bShowDebugInput;

	HandbrakeBrakeForce = CarPawnConfig::HandbrakeBrakeForce;
	HandbrakeLateralGrip = CarPawnConfig::HandbrakeLateralGrip;

	// Can be updated every frame
	PrimaryActorTick.bCanEverTick = true;
	
	// Use a simple box as the physics body for the car
	PhysicsBody = CreateDefaultSubobject<UBoxComponent>(TEXT("PhysicsBody"));
	RootComponent = PhysicsBody;

	PhysicsBody->SetSimulatePhysics(true);
	PhysicsBody->SetEnableGravity(true);
	PhysicsBody->SetCollisionProfileName(TEXT("PhysicsActor"));
	PhysicsBody->SetMassOverrideInKg(NAME_None, CarMassKg);
	PhysicsBody->SetLinearDamping(LinearDamping);
	PhysicsBody->SetAngularDamping(AngularDamping);

	CarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CarMesh"));
	CarMesh->SetupAttachment(PhysicsBody);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(PhysicsBody);
	SpringArm->TargetArmLength = 600.0f;
	SpringArm->SetRelativeLocation(FVector(-200.0f, 0.0f, 120.0f));
	SpringArm->SetRelativeRotation(FRotator(CameraPitch, CameraYaw, 0.0f));

	SpringArm->bUsePawnControlRotation = false;

	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = true;
	SpringArm->bInheritRoll = false;

	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 8.0f;
	SpringArm->bEnableCameraRotationLag = true;
	SpringArm->CameraRotationLagSpeed = 8.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void ACarPawn::BeginPlay()
{
	Super::BeginPlay();

	if (PhysicsBody)
	{
		PhysicsBody->SetMassOverrideInKg(NAME_None, CarMassKg);
		PhysicsBody->SetLinearDamping(LinearDamping);
		PhysicsBody->SetAngularDamping(AngularDamping);
	}


	APlayerController* PlayerController = Cast<APlayerController>(GetController());

	if (PlayerController)
	{
		PlayerController->SetInputMode(FInputModeGameOnly());
		PlayerController->bShowMouseCursor = false;
	}
}

void ACarPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ApplyDrivingForces(DeltaTime);
	ShowDebugInput();

}

void ACarPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	APlayerController* PlayerController = Cast<APlayerController>(GetController());

	if (PlayerController)
	{
		ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();

		if (LocalPlayer)
		{
			UEnhancedInputLocalPlayerSubsystem* Subsystem =
				ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

			if (Subsystem && InputMappingContext)
			{
				Subsystem->AddMappingContext(InputMappingContext, 100);
			}
		}
	}

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (EnhancedInputComponent && MoveAction)
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACarPawn::Move);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &ACarPawn::Move);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Canceled, this, &ACarPawn::Move);
	}
	if (EnhancedInputComponent && LookAction)
	{
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACarPawn::Look);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Completed, this, &ACarPawn::Look);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Canceled, this, &ACarPawn::Look);
	}
	if (EnhancedInputComponent && HandbrakeAction)
	{
		EnhancedInputComponent->BindAction(HandbrakeAction, ETriggerEvent::Triggered, this, &ACarPawn::Handbrake);
		EnhancedInputComponent->BindAction(HandbrakeAction, ETriggerEvent::Completed, this, &ACarPawn::Handbrake);
		EnhancedInputComponent->BindAction(HandbrakeAction, ETriggerEvent::Canceled, this, &ACarPawn::Handbrake);
	}	
}

void ACarPawn::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	ThrottleInput = MovementVector.Y;
	SteeringInput = MovementVector.X;
}

void ACarPawn::Look(const FInputActionValue& Value)
{
	const FVector2D LookVector = Value.Get<FVector2D>();

	CameraYaw += LookVector.X * MouseLookSensitivity;
	CameraPitch += LookVector.Y * MouseLookSensitivity;
	
	CameraPitch = FMath::Clamp(CameraPitch, MinCameraPitch, MaxCameraPitch);
	
	SpringArm->SetRelativeRotation(FRotator(CameraPitch, CameraYaw, 0.0f));
}

void ACarPawn::Handbrake(const FInputActionValue& Value)
{
	bHandbrakeActive = Value.Get<bool>();
}