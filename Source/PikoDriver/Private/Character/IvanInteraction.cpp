#include "IvanCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "Interactable.h"

void AIvanCharacter::InteractInput(const FInputActionValue& Value)
{
	bInteractPressed = Value.Get<bool>();
	bLastInteractTraceHit = false;
	bLastInteractResolved = false;
	bLastInteractCanInteract = false;
	LastInteractHitActorName = TEXT("None");
	LastInteractHitComponentName = TEXT("None");
	LastInteractResolvedActorName = TEXT("None");

	if (!bInteractPressed || !Controller || !GetWorld())
	{
		return;
	}

	FVector ViewLocation = FVector::ZeroVector;
	FRotator ViewRotation = FRotator::ZeroRotator;
	Controller->GetPlayerViewPoint(ViewLocation, ViewRotation);

	const FVector TraceEnd = ViewLocation + (ViewRotation.Vector() * InteractionDistance);

	FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(IvanCharacterInteractTrace), false, this);
	QueryParams.AddIgnoredActor(this);

	FHitResult HitResult;

	const bool bHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		ViewLocation,
		TraceEnd,
		ECC_Visibility,
		QueryParams
	);

	if (!bHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("IvanCharacter: Interact trace found no hit."));
		return;
	}

	bLastInteractTraceHit = true;
	LastInteractHitActorName = GetNameSafe(HitResult.GetActor());
	LastInteractHitComponentName = GetNameSafe(HitResult.GetComponent());

	UE_LOG(LogTemp, Log, TEXT("IvanCharacter: Interact trace hit actor '%s'."), *GetNameSafe(HitResult.GetActor()));

	AActor* HitActor = ResolveInteractableActor(HitResult);
	bLastInteractResolved = HitActor != nullptr;
	LastInteractResolvedActorName = GetNameSafe(HitActor);

	if (!HitActor || !HitActor->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
	{
		UE_LOG(LogTemp, Warning, TEXT("IvanCharacter: Interact trace hit '%s' but no interactable actor was resolved."), *GetNameSafe(HitResult.GetActor()));
		return;
	}

	bLastInteractCanInteract = IInteractable::Execute_CanInteract(HitActor, this);

	if (!bLastInteractCanInteract)
	{
		UE_LOG(LogTemp, Warning, TEXT("IvanCharacter: '%s' rejected interaction from '%s'."), *GetNameSafe(HitActor), *GetName());
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("IvanCharacter: Interacting with '%s'."), *GetNameSafe(HitActor));
	IInteractable::Execute_Interact(HitActor, this);
}

AActor* AIvanCharacter::ResolveInteractableActor(const FHitResult& HitResult) const
{
	AActor* CandidateActor = HitResult.GetActor();

	if (!CandidateActor && HitResult.GetComponent())
	{
		CandidateActor = HitResult.GetComponent()->GetOwner();
	}

	for (int32 Depth = 0; CandidateActor && Depth < 8; ++Depth)
	{
		if (CandidateActor->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
		{
			return CandidateActor;
		}

		AActor* ParentActor = CandidateActor->GetParentActor();

		if (ParentActor && ParentActor != CandidateActor)
		{
			CandidateActor = ParentActor;
			continue;
		}

		AActor* OwnerActor = CandidateActor->GetOwner();

		if (OwnerActor && OwnerActor != CandidateActor)
		{
			CandidateActor = OwnerActor;
			continue;
		}

		CandidateActor = CandidateActor->GetAttachParentActor();
	}

	return nullptr;
}

void AIvanCharacter::ApplyInputMappingContext(APlayerController* PlayerController) const
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

void AIvanCharacter::RemoveInputMappingContext(APlayerController* PlayerController) const
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