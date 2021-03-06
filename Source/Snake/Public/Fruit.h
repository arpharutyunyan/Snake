// Snake game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "OverlapedActors.h"
#include "Fruit.generated.h"


UCLASS()
class SNAKE_API AFruit : public AOverlapedActors
{
	GENERATED_BODY()

public:
	AFruit();

	virtual void OverlapedWithSnakeHead(class ASnakeHeadPawn* SnakeHead) override;

	void SetColor(FLinearColor FruitColor);

	FLinearColor Color;

private:
	
	UMaterialInstanceDynamic* MID;
	
};
