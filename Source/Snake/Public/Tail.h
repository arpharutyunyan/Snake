// Snake game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DeadZone.h"
#include "Tail.generated.h"

UCLASS()
class SNAKE_API ATail : public ADeadZone
{
	GENERATED_BODY()

public:
	ATail();

protected:
	
	virtual void BeginPlay() override;
	
};
