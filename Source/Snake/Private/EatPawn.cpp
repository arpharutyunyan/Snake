// Snake game. All rights reserved.


#include "EatPawn.h"
#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>

// Sets default values
AEatPawn::AEatPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	SetRootComponent(StaticMesh);

	//BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	//BoxComponent->InitBoxExtent(FVector(100.0f, 100.0f, 10.0f));
	//BoxComponent->SetupAttachment(StaticMeshComponent);
	
	//StaticMeshComponent->SetupAttachment(BoxComponent);
	
}

// Called when the game starts or when spawned
void AEatPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEatPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


