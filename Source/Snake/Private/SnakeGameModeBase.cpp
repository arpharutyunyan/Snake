// Snake game. All rights reserved.


#include "SnakeGameModeBase.h"
#include "SnakeHeadPawn.h"
#include <Kismet/GameplayStatics.h>
#include <Camera/CameraActor.h>


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
}
