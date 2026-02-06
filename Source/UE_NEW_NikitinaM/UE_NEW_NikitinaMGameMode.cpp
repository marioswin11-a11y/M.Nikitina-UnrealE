// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE_NEW_NikitinaMGameMode.h"
#include "UE_NEW_NikitinaMCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE_NEW_NikitinaMGameMode::AUE_NEW_NikitinaMGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
