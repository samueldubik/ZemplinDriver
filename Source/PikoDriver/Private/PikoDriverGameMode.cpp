// Fill out your copyright notice in the Description page of Project Settings.


#include "PikoDriverGameMode.h"
#include "IvanCharacter.h"

APikoDriverGameMode::APikoDriverGameMode()
{
	DefaultPawnClass = AIvanCharacter::StaticClass();
}
