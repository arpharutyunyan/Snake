// Snake game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SnakeGameModeBase.generated.h"

class AFruit;

UCLASS()
class SNAKE_API ASnakeGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASnakeGameModeBase();

	void GameOver();
	void SpawnFruit();

	AFruit* Fruit;
	FVector RandomSpawnLocation;

protected:
	virtual void StartPlay();

	float MinX = -690.0f;
	float MaxX = 690.0f;

	float MinY = -690.0f;
	float MaxY = 690.0f;

	float SpawnZ = 0.0f;

};
