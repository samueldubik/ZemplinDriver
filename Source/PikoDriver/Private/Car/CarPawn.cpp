#include "CarPawn.h"
#include "CarPawnConfig.h"
#include "BMWVisualAssembly.h"
#include "IvanCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Components/ChildActorComponent.h"
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
	Camera->PostProcessBlendWeight = 1.0f;
	Camera->PostProcessSettings.bOverride_MotionBlurAmount = true;
	Camera->PostProcessSettings.MotionBlurAmount = 0.0f;
	Camera->PostProcessSettings.bOverride_MotionBlurMax = true;
	Camera->PostProcessSettings.MotionBlurMax = 0.0f;

	AutoPossessPlayer = EAutoReceiveInput::Disabled;
}

void ACarPawn::BeginPlay()
{
	Super::BeginPlay();
	
	UChildActorComponent* BMWVisualChildComponent = FindComponentByClass<UChildActorComponent>();

	if (BMWVisualChildComponent)
	{
		BMWVisualAssemblyActor = Cast<ABMWVisualAssembly>(BMWVisualChildComponent->GetChildActor());
	}

	if (!BMWVisualAssemblyActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("CarPawn: BMW visual assembly actor was not found."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("CarPawn: BMW visual assembly actor found."));
	}

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

	if (BMWVisualAssemblyActor)
	{
		const FVector Velocity =
			PhysicsBody
			? PhysicsBody->GetPhysicsLinearVelocity()
			: GetVelocity();

		const FVector ForwardVector =
			PhysicsBody
			? PhysicsBody->GetForwardVector()
			: GetActorForwardVector();

		const float ForwardSpeedCmS = FVector::DotProduct(Velocity, ForwardVector);

		BMWVisualAssemblyActor->UpdateWheelVisuals(
			DeltaTime,
			ForwardSpeedCmS,
			SmoothedSteeringInput
		);
	}

}

void ACarPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

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

	if (EnhancedInputComponent && ExitAction)
	{
		EnhancedInputComponent->BindAction(ExitAction, ETriggerEvent::Started, this, &ACarPawn::ExitVehicle);
       EnhancedInputComponent->BindAction(ExitAction, ETriggerEvent::Triggered, this, &ACarPawn::ExitVehicle);
		EnhancedInputComponent->BindAction(ExitAction, ETriggerEvent::Completed, this, &ACarPawn::ExitVehicle);
		EnhancedInputComponent->BindAction(ExitAction, ETriggerEvent::Canceled, this, &ACarPawn::ExitVehicle);
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

bool ACarPawn::CanInteract_Implementation(AActor* InteractingActor) const
{
	const APawn* InteractingPawn = Cast<APawn>(InteractingActor);
	const bool bHasInteractingPawn = InteractingPawn != nullptr;
	const bool bInteractingPawnHasController =
		bHasInteractingPawn && InteractingPawn->GetController() != nullptr;
	const bool bCarHasNoController = GetController() == nullptr;

	UE_LOG(
		LogTemp,
		Warning,
		TEXT("CarPawn CanInteract | Pawn=%s | PawnController=%s | CarController=%s | Result=%s"),
		bHasInteractingPawn ? TEXT("YES") : TEXT("NO"),
		bInteractingPawnHasController ? TEXT("YES") : TEXT("NO"),
		bCarHasNoController ? TEXT("YES") : TEXT("NO"),
		(bHasInteractingPawn && bInteractingPawnHasController && bCarHasNoController) ? TEXT("YES") : TEXT("NO")
	);

	return bHasInteractingPawn
		&& bInteractingPawnHasController
		&& bCarHasNoController;
}

void ACarPawn::Interact_Implementation(AActor* InteractingActor)
{
	if (!CanInteract_Implementation(InteractingActor))
	{
		return;
	}

	APawn* InteractingPawn = Cast<APawn>(InteractingActor);

	if (!InteractingPawn)
	{
		return;
	}

	AController* InteractingController = InteractingPawn->GetController();

	if (!InteractingController)
	{
		return;
	}

	APlayerController* PlayerController = Cast<APlayerController>(InteractingController);
	AIvanCharacter* IvanCharacter = Cast<AIvanCharacter>(InteractingPawn);

	DriverPawn = InteractingPawn;
	DriverPawn->SetActorHiddenInGame(true);
	DriverPawn->SetActorEnableCollision(false);
   ThrottleInput = 0.0f;
	SteeringInput = 0.0f;
	bHandbrakeActive = false;
	bExitPressed = false;
	bExitInputReleasedSincePossess = false;

	if (IvanCharacter)
	{
     IvanCharacter->bInteractPressed = false;
		IvanCharacter->RemoveInputMappingContext(PlayerController);
	}

	InteractingController->Possess(this);

	if (PlayerController)
	{
       ApplyInputMappingContext(PlayerController);
		PlayerController->SetInputMode(FInputModeGameOnly());
		PlayerController->bShowMouseCursor = false;
	}

	UE_LOG(LogTemp, Log, TEXT("CarPawn: %s possessed %s"), *GetNameSafe(InteractingActor), *GetName());
}

void ACarPawn::ExitVehicle(const FInputActionValue& Value)
{
   bExitPressed = Value.Get<bool>();

	if (!bExitPressed)
	{
		bExitInputReleasedSincePossess = true;
		return;
	}

	if (!bExitInputReleasedSincePossess)
	{
		return;
	}

	APlayerController* PlayerController = Cast<APlayerController>(GetController());

	if (!PlayerController || !DriverPawn)
	{
      bExitPressed = false;
		return;
	}

	APawn* ExitingPawn = DriverPawn;
 AIvanCharacter* IvanCharacter = Cast<AIvanCharacter>(ExitingPawn);
	const FVector ExitLocation = GetExitLocation();
	const FRotator ExitRotation = GetActorRotation();

	ThrottleInput = 0.0f;
	SteeringInput = 0.0f;
	bHandbrakeActive = true;

	ExitingPawn->SetActorHiddenInGame(false);
	ExitingPawn->SetActorEnableCollision(true);
	ExitingPawn->SetActorLocationAndRotation(
		ExitLocation,
		ExitRotation,
		false,
		nullptr,
		ETeleportType::TeleportPhysics
	);

	RemoveInputMappingContext(PlayerController);
	PlayerController->Possess(ExitingPawn);

	if (IvanCharacter)
	{
		IvanCharacter->ApplyInputMappingContext(PlayerController);
	}

	UE_LOG(LogTemp, Log, TEXT("CarPawn: %s exited %s"), *GetNameSafe(ExitingPawn), *GetName());

	DriverPawn = nullptr;
	bExitPressed = false;
   bExitInputReleasedSincePossess = false;
}

void ACarPawn::ApplyInputMappingContext(APlayerController* PlayerController) const
{
	if (!PlayerController || !InputMappingContext)
	{
		return;
	}

	ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();

	if (!LocalPlayer)
	{
		return;
	}

	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	if (Subsystem)
	{
		Subsystem->AddMappingContext(InputMappingContext, 100);
	}
}

void ACarPawn::RemoveInputMappingContext(APlayerController* PlayerController) const
{
	if (!PlayerController || !InputMappingContext)
	{
		return;
	}

	ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();

	if (!LocalPlayer)
	{
		return;
	}

	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	if (Subsystem)
	{
		Subsystem->RemoveMappingContext(InputMappingContext);
	}
}

FVector ACarPawn::GetExitLocation() const
{
	return GetActorTransform().TransformPosition(ExitLocationOffset);
}