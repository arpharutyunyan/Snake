// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EatPawn.h"
#include "SnakeGameModeBase.generated.h"


UCLASS()
class SNAKE_API ASnakeGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASnakeGameModeBase();

protected:
	virtual void StartPlay();

	float MinX = -690.0f;
	float MaxX = 690.0f;

	float MinY = -690.0f;
	float MaxY = 690.0f;

	float SpawnZ = 25.0f;
	void CreateEat();

private:
	FTransform SetEatCreatingPosition() const;

};
