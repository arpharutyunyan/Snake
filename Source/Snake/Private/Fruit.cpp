// Snake game. All rights reserved.


#include "Fruit.h"
#include "SnakeHeadPawn.h"
#include "SnakeGameModeBase.h"

DEFINE_LOG_CATEGORY_STATIC(Fruit, All, All);

AFruit::AFruit()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> BaseMaterial(TEXT("Material'/Game/Materials/M_Head.M_Head'"));
	if (BaseMaterial.Succeeded())
	{
		DynMaterial = Mesh->CreateDynamicMaterialInstance(0, BaseMaterial.Object);
		Mesh->SetMaterial(0, DynMaterial);
	}

	SetActorScale3D(FVector(0.3f, 0.3f, 0.1f));

	Color = FLinearColor::MakeRandomColor();
	SetColor(Color);
}

void AFruit::OverlapedWithSnakeHead(class ASnakeHeadPawn* SnakeHead)
{
	Destroy();
	SnakeHead->EatFruit();
	
	ASnakeGameModeBase* GameMode = Cast<ASnakeGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		GameMode->SpawnFruit();	
	}	
}

void AFruit::SetColor(FLinearColor FruitColor)
{
	MID = Mesh->CreateAndSetMaterialInstanceDynamic(0);
	if (MID)
	{
		MID->SetVectorParameterValue("Color", Color);
	}
}