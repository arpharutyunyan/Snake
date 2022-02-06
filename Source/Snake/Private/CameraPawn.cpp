// Snake game. All rights reserved.


#include "CameraPawn.h"
#include <Camera/CameraComponent.h>
#include <Components/SceneComponent.h>
#include <Engine/World.h>
#include <GameFramework/SpringArmComponent.h>
#include "EatPawn.h"

DEFINE_LOG_CATEGORY_STATIC(LogGamemode, All, All);

// Sets default values
ACameraPawn::ACameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	SpringArmComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 1500.0f));
	SpringArmComponent->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));

}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}