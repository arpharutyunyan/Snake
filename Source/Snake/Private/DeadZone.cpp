// Snake game. All rights reserved.


#include "DeadZone.h"
#include "SnakeGameModeBase.h"
#include "SnakeHeadPawn.h"

void ADeadZone::OverlapedWithSnakeHead(class ASnakeHeadPawn* SnakeHead)
{
	ASnakeGameModeBase* GameMode = Cast<ASnakeGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		GameMode->GameOver();
	}
}
