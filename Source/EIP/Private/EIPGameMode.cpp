// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "EIP.h"
#include "EIPGameMode.h"
#include "EIPPlayerController.h"
#include "EIPCharacter.h"

AEIPGameMode::AEIPGameMode(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{
	// use our custom PlayerController class
	PlayerControllerClass = AEIPPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/MyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}