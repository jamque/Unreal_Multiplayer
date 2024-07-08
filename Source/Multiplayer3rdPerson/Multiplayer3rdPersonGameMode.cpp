// Copyright Epic Games, Inc. All Rights Reserved.

#include "Multiplayer3rdPersonGameMode.h"
#include "Multiplayer3rdPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMultiplayer3rdPersonGameMode::AMultiplayer3rdPersonGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
