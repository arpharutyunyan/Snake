// Snake game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "OverlapedActors.h"
#include "Fruit.generated.h"

//class ASnakeHeadPawn;

UCLASS()
class SNAKE_API AFruit : public AOverlapedActors
{
	GENERATED_BODY()

public:
	AFruit();

	virtual void OverlapedWithSnakeHead(class ASnakeHeadPawn* SnakeHead) override;
	
};
