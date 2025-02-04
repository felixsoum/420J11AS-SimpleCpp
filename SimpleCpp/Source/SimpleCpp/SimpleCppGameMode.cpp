// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "SimpleCppGameMode.h"
#include "SimpleCppHUD.h"
#include "SimpleCppCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASimpleCppGameMode::ASimpleCppGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASimpleCppHUD::StaticClass();
}
