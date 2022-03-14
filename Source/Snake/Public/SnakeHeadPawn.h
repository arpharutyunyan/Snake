// Snake game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tail.h"
#include "SnakeHeadPawn.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class UMaterialInstanceDynamic;
class UCameraComponent;
class USpringArmComponent;
class ABaseStaticMeshActor;
class AFruit;
class ASnakeGameModeBase;

UCLASS()
class SNAKE_API ASnakeHeadPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASnakeHeadPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(VisibleAnywhere)
		USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* HeadMesh;

	UPROPERTY(VisibleAnywhere)
		UMaterialInstanceDynamic* DynMaterial;


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Amount);
	void MoveRight(float Amount);
	void EatFruit();

	TArray<ATail*> Tails;

private:

	FVector NewLocation;
	FVector MovementDiraction;
	FVector TailSpawnLocation;
	float Speed = 20.0f;
	int32 Score = 0;
	float Box;
};
