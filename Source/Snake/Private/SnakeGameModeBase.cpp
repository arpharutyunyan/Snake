// Snake game. All rights reserved.


#include "SnakeGameModeBase.h"
#include "SnakeHeadPawn.h"
#include "SnakePlayerController.h"


ASnakeGameModeBase::ASnakeGameModeBase()
{
	DefaultPawnClass = ASnakeHeadPawn::StaticClass();
	PlayerControllerClass = ASnakePlayerController::StaticClass();
}
