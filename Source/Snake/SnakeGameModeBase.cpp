// Copyright Epic Games, Inc. All Rights Reserved.


#include "SnakeGameModeBase.h"
#include "CameraPawn.h"

ASnakeGameModeBase::ASnakeGameModeBase()
{
	DefaultPawnClass = ACameraPawn::StaticClass();
}