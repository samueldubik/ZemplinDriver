// Fill out your copyright notice in the Description page of Project Settings.


#include "IvanCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/Engine.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "InputAction.h"
#include "Interactable.h"
#include "Math/RotationMatrix.h"

AIvanCharacter::AIvanCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	bUseControllerRotationYaw = false;

	if (GetCharacterMovement())
	{
		GetCharacterMovement()->bOrientRotationToMovement = true;
		GetCharacterMovement()->NavAgentProps.bCanCrouch = true;
	}
}

void AIvanCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	}
}

void AIvanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ShowDebugInput();
}

void AIvanCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	ApplyInputMappingContext(Cast<APlayerController>(GetController()));

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (!EnhancedInputComponent)
	{
		return;
	}

	if (MoveAction)
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AIvanCharacter::Move);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &AIvanCharacter::Move);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Canceled, this, &AIvanCharacter::Move);
	}

	if (LookAction)
	{
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AIvanCharacter::Look);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Completed, this, &AIvanCharacter::Look);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Canceled, this, &AIvanCharacter::Look);
	}

	if (JumpAction)
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AIvanCharacter::JumpInput);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AIvanCharacter::JumpInput);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Canceled, this, &AIvanCharacter::JumpInput);
	}

	if (SprintAction)
	{
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Triggered, this, &AIvanCharacter::SprintInput);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &AIvanCharacter::SprintInput);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Canceled, this, &AIvanCharacter::SprintInput);
	}

	if (CrouchAction)
	{
		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Triggered, this, &AIvanCharacter::CrouchInput);
		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Completed, this, &AIvanCharacter::CrouchInput);
		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Canceled, this, &AIvanCharacter::CrouchInput);
	}

	if (InteractAction)
	{
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &AIvanCharacter::InteractInput);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Completed, this, &AIvanCharacter::InteractInput);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Canceled, this, &AIvanCharacter::InteractInput);
	}
}

void AIvanCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	LookInputValue = LookAxisVector;
	bLookInputActive = !LookAxisVector.IsNearlyZero();

	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}

void AIvanCharacter::JumpInput(const FInputActionValue& Value)
{
	bJumpPressed = Value.Get<bool>();

	if (bJumpPressed)
	{
		Jump();
	}
	else
	{
		StopJumping();
	}
}

void AIvanCharacter::SprintInput(const FInputActionValue& Value)
{
	bSprintPressed = Value.Get<bool>();
	bIsSprinting = bSprintPressed;

	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = bIsSprinting ? SprintSpeed : WalkSpeed;
	}
}

void AIvanCharacter::CrouchInput(const FInputActionValue& Value)
{
	bCrouchPressed = Value.Get<bool>();

	if (bCrouchPressed)
	{
		Crouch();
	}
	else
	{
		UnCrouch();
	}
}