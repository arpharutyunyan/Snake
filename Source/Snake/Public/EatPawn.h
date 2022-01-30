// Snake game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EatPawn.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class SNAKE_API AEatPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEatPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Component")
		UBoxComponent* BoxComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Component")
		UStaticMeshComponent* StaticMesh;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
