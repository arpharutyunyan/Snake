// Snake game. All rights reserved.


#include "OverlapedActors.h"
#include <Components/StaticMeshComponent.h>
#include <Components/SceneComponent.h>
#include "SnakeHeadPawn.h"

DEFINE_LOG_CATEGORY_STATIC(Overlap, All, All);

// Sets default values
AOverlapedActors::AOverlapedActors()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(GetRootComponent());

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("StaticMesh'/Engine/EditorMeshes/EditorCube.EditorCube'"));
	if (StaticMesh.Succeeded())
	{
		Mesh->SetStaticMesh(StaticMesh.Object);
	}

	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
}

// Called when the game starts or when spawned
void AOverlapedActors::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOverlapedActors::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOverlapedActors::NotifyActorBeginOverlap(AActor* OtherActor)
{
	UE_LOG(Overlap, Display, TEXT("begin overlap"));
	ASnakeHeadPawn* SnakeHead = Cast<ASnakeHeadPawn>(OtherActor);
	if (SnakeHead)
	{
		OverlapedWithSnakeHead(SnakeHead);
	}

}

void AOverlapedActors::OverlapedWithSnakeHead(class ASnakeHeadPawn* SnakeHead){}