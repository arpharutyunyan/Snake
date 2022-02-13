// Snake game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SnakeGameModeBase.generated.h"

UCLASS()
class SNAKE_API ASnakeGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASnakeGameModeBase();

	void GameOver();

protected:
	virtual void StartPlay();

};
