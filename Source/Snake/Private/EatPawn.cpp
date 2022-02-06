// Snake game. All rights reserved.


#include "EatPawn.h"
#include <Components/SceneComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Materials/MaterialInstanceDynamic.h>

DEFINE_LOG_CATEGORY_STATIC(LogEatPawn, All, All);

// Sets default values
AEatPawn::AEatPawn()
{
	//UE_LOG(LogEatPawn, Display, TEXT("Constructor"));
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(SceneComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> EatMesh (TEXT("StaticMesh'/Engine/EditorMeshes/EditorCube.EditorCube'"));
	StaticMeshComponent->SetStaticMesh(EatMesh.Object);
	
	SetActorScale3D(FVector(0.2f, 0.2f, 0.1f));

	//UE_LOG(LogEatPawn, Display, TEXT("umaterial"));
	static ConstructorHelpers::FObjectFinder<UMaterial> BaseMaterial(TEXT("Material'/Game/Materials/M_Base.M_Base'"));
	//UE_LOG(LogEatPawn, Display, TEXT("set material"));
	if (BaseMaterial.Object)
	{
		MID = StaticMeshComponent->CreateDynamicMaterialInstance(0, BaseMaterial.Object);
		StaticMeshComponent->SetMaterial(0, MID);
	}
	
	//UE_LOG(LogEatPawn, Display, TEXT("call material in constructor"));
	SetMaterialColor();
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

void AEatPawn::SetMaterialColor()
{
	Color = FLinearColor::MakeRandomColor();
	
	MID = StaticMeshComponent->CreateAndSetMaterialInstanceDynamic(0);
	
	if (MID)
	{
		MID->SetVectorParameterValue("Color", Color);
	}
}

