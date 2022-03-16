// Snake game. All rights reserved.


#include "Tail.h"

ATail::ATail()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> TailMaterial(TEXT("Material'/Game/Materials/M_Head.M_Head'"));
	if (TailMaterial.Succeeded())
	{
		DynMaterial = Mesh->CreateDynamicMaterialInstance(0, TailMaterial.Object);
		Mesh->SetMaterial(0, DynMaterial);
	}

	SetActorScale3D(FVector(0.3f, 0.3f, 0.1f));
	Color = FLinearColor::MakeRandomColor();
	SetColor(Color);
}

void ATail::BeginPlay()
{
	Super::BeginPlay();
}

void ATail::SetColor(FLinearColor FruitColor)
{
	MID = Mesh->CreateAndSetMaterialInstanceDynamic(0);
	if (MID)
	{
		MID->SetVectorParameterValue("Color", FruitColor);
	}
}