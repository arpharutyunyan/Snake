// Snake game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EatPawn.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class UMaterialInstanceDynamic;

UCLASS()
class SNAKE_API AEatPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEatPawn();

	
	void SetMaterialColor();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Component")
		USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, Category = "Component")
		UStaticMeshComponent* StaticMeshComponent;

	FLinearColor Color;
	UMaterialInstanceDynamic* MID;
	
	


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
