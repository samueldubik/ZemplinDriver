#include "IvanCharacter.h"
#include "Engine/Engine.h"
#include "InputAction.h"

void AIvanCharacter::ShowDebugInput()
{
	if (!bShowDebugInput || !GEngine)
	{
		return;
	}

	GEngine->AddOnScreenDebugMessage(
		101,
		0.0f,
		FColor::Yellow,
		FString::Printf(
			TEXT("[Ivan] Move: (%.2f, %.2f) | Look: (%.2f, %.2f)"),
			MoveInputValue.X,
			MoveInputValue.Y,
			LookInputValue.X,
			LookInputValue.Y
		)
	);

	GEngine->AddOnScreenDebugMessage(
		102,
		0.0f,
		FColor::Cyan,
		FString::Printf(
			TEXT("[Ivan] Jump: %s | Sprint: %s | Crouch: %s | Interact: %s"),
			bJumpPressed ? TEXT("ON") : TEXT("off"),
			bIsSprinting ? TEXT("ON") : TEXT("off"),
			bCrouchPressed ? TEXT("ON") : TEXT("off"),
			bInteractPressed ? TEXT("ON") : TEXT("off")
		)
	);

	GEngine->AddOnScreenDebugMessage(
		103,
		0.0f,
		FColor::Green,
		FString::Printf(
			TEXT("[Ivan] Interact Trace Hit: %s | Actor: %s | Component: %s"),
			bLastInteractTraceHit ? TEXT("YES") : TEXT("no"),
			*LastInteractHitActorName,
			*LastInteractHitComponentName
		)
	);

	GEngine->AddOnScreenDebugMessage(
		104,
		0.0f,
		FColor::Emerald,
		FString::Printf(
			TEXT("[Ivan] Interact Resolved: %s | Actor: %s | CanInteract: %s"),
			bLastInteractResolved ? TEXT("YES") : TEXT("no"),
			*LastInteractResolvedActorName,
			bLastInteractCanInteract ? TEXT("YES") : TEXT("no")
		)
	);
}