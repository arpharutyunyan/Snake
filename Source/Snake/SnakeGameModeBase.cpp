// Copyright Epic Games, Inc. All Rights Reserved.


#include "SnakeGameModeBase.h"
#include "CameraPawn.h"
#include "EatPawn.h"
#include <Engine/World.h>

DEFINE_LOG_CATEGORY_STATIC(LogGamemode, All, All);

ASnakeGameModeBase::ASnakeGameModeBase()
{
	DefaultPawnClass = ACameraPawn::StaticClass();
}

void ASnakeGameModeBase::StartPlay()
{
	UE_LOG(LogGamemode, Display, TEXT("start play"));
	CreateEat();
	UE_LOG(LogGamemode, Display, TEXT("finish"));
}

void ASnakeGameModeBase::CreateEat()
{
	UE_LOG(LogGamemode, Display, TEXT("Create eat"));
	if (!GetWorld()) return;

	for (int32 i = 0; i < 4; i++)
	{
		FTransform Position = SetEatCreatingPosition();
		UWorld* World = GetWorld();
		UE_LOG(LogGamemode, Display, TEXT("spawn"));
		World->SpawnActor<AEatPawn>(AEatPawn::StaticClass(), Position);
		//World->SpawnActor<AEatPawn>(Eat, Position);
	}

}

FTransform ASnakeGameModeBase::SetEatCreatingPosition() const
{
	FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f);

	float SpawnX = FMath::FRandRange(MinX, MaxX);
	float SpawnY = FMath::FRandRange(MinY, MaxY);

	FVector Location = FVector(SpawnX, SpawnY, SpawnZ);
	FTransform Position = FTransform(Rotation, Location);

	return Position;

}