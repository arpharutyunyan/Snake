// Snake game. All rights reserved.


#include "CameraPawn.h"
#include <Components/SceneComponent.h>
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include "SnakeHeadPawn.h"
#include <Engine/World.h>
#include <Components/InputComponent.h>

DEFINE_LOG_CATEGORY_STATIC(CameraLog, All, All);

// Sets default values
ACameraPawn::ACameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(CameraLog, Display, TEXT("scene"));
	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	UE_LOG(CameraLog, Display, TEXT("arm"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetRootComponent());

	UE_LOG(CameraLog, Display, TEXT("camera"));
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

	UE_LOG(CameraLog, Display, TEXT("location"));
	SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 1500.0f));
	SpringArm->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));
}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(CameraLog, Display, TEXT("beginplay"));

	//ASnakeHeadPawn* Head = GetWorld()->SpawnActor<ASnakeHeadPawn>(ASnakeHeadPawn::StaticClass(), FVector(0.0f, 0.0f, 11.0f), FRotator(0.0f, 0.0f, 0.0f));

}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

