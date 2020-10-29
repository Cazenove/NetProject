// Copyright Epic Games, Inc. All Rights Reserved.

#include "NetProjectGameMode.h"
#include "NetProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANetProjectGameMode::ANetProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
