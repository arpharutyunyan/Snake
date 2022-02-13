// Snake game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "OverlapedActors.h"
#include "DeadZone.generated.h"


UCLASS()
class SNAKE_API ADeadZone : public AOverlapedActors
{
	GENERATED_BODY()

public:
	virtual void OverlapedWithSnakeHead(class ASnakeHeadPawn* SnakeHead) override;
};
