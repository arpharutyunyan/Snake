// Snake game. All rights reserved.


#include "SnakeGameModeBase.h"
#include "SnakeHeadPawn.h"
#include <Kismet/GameplayStatics.h>
#include <Camera/CameraActor.h>
#include <Fruit.h>

DEFINE_LOG_CATEGORY_STATIC(GameMode, All, All);

ASnakeGameModeBase::ASnakeGameModeBase()
{
	DefaultPawnClass = ASnakeHeadPawn::StaticClass();
}

void ASnakeGameModeBase::StartPlay()
{
	Super::StartPlay();

	FVector Location(0.0f, 0.0f, 1500.0f);
	FRotator Rotation(-90.0f, 0.0f, 0.0f);

	ACameraActor* Camera = GetWorld()->SpawnActor<ACameraActor>(ACameraActor::StaticClass(), Location, Rotation, FActorSpawnParameters());

	APlayerController* Player = UGameplayStatics::GetPlayerController(this, 0);
	if (Player)
	{
		Camera->SetOwner(Player);
		Player->SetViewTarget(Camera);
	}

	SpawnFruit();
}

void ASnakeGameModeBase::GameOver()
{
	UGameplayStatics::SetGamePaused(this, true);
	UE_LOG(GameMode, Display, TEXT("Game over."));
}

void ASnakeGameModeBase::SpawnFruit()
{
	float SpawnX = FMath::FRandRange(MinX, MaxX);
	float SpawnY = FMath::FRandRange(MinY, MaxY);
	RandomSpawnLocation = FVector(SpawnX, SpawnY, SpawnZ);
		
	FTransform SpawnLocation = FTransform(RandomSpawnLocation);

	GetWorld()->SpawnActor<AFruit>(AFruit::StaticClass(), SpawnLocation, FActorSpawnParameters());

}
