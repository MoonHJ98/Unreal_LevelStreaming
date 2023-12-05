// Copyright Epic Games, Inc. All Rights Reserved.

#include "LevelStreamingGameMode.h"
#include "LevelStreamingCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALevelStreamingGameMode::ALevelStreamingGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
