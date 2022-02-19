// Snake game. All rights reserved.


#include "SnakeHeadPawn.h"
#include <Components/StaticMeshComponent.h>
#include <Components/SceneComponent.h>
#include <Components/InputComponent.h>
#include "Tail.h"
#include "SnakeGameModeBase.h"

DEFINE_LOG_CATEGORY_STATIC(HeadPawn, All, All);

// Sets default values
ASnakeHeadPawn::ASnakeHeadPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(HeadPawn, Display, TEXT("constructor"));
	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);
	
	HeadMesh = CreateDefaultSubobject<UStaticMeshComponent>("HeadMesh");
	HeadMesh->SetupAttachment(GetRootComponent());	

	static ConstructorHelpers::FObjectFinder<UStaticMesh> HeadStaticMesh(TEXT("StaticMesh'/Engine/EditorMeshes/EditorCube.EditorCube'"));
	if (HeadStaticMesh.Succeeded())
	{
		HeadMesh->SetStaticMesh(HeadStaticMesh.Object);
	}
	
	static ConstructorHelpers::FObjectFinder<UMaterial> HeadMaterial(TEXT("Material'/Game/Materials/M_Head.M_Head'"));
	if (HeadMaterial.Succeeded())
	{
		DynMaterial = HeadMesh->CreateDynamicMaterialInstance(0, HeadMaterial.Object);
		HeadMesh->SetMaterial(0, DynMaterial);
	}

	SetActorScale3D(FVector(0.3f, 0.3f, 0.1f));
	
	HeadMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	HeadMesh->SetCollisionObjectType(ECC_Pawn);
	HeadMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

}

// Called when the game starts or when spawned
void ASnakeHeadPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASnakeHeadPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!MovementDiraction.IsZero())
	{
		NewLocation = GetActorLocation() + MovementDiraction * Speed * DeltaTime;
		SetActorLocation(NewLocation);
	}


	/*for (int32 i = 0; i < Tails.Num(); i++)
	{
		FVector CurrentLocation = Tails[i]->GetActorLocation();
		Tails[i]->SetActorLocation(PreviousLocation);
		PreviousLocation = CurrentLocation;
	}*/
	
}

// Called to bind functionality to input
void ASnakeHeadPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (PlayerInputComponent)
	{
		PlayerInputComponent->BindAxis("MoveForward", this, &ASnakeHeadPawn::MoveForward);
		PlayerInputComponent->BindAxis("MoveRight", this, &ASnakeHeadPawn::MoveRight);
	}
}

void ASnakeHeadPawn::MoveForward(float Amount)
{
	MovementDiraction.X = FMath::Clamp(Amount, -1.0f, 1.0f);
}

void ASnakeHeadPawn::MoveRight(float Amount)
{
	MovementDiraction.Y = FMath::Clamp(Amount, -1.0f, 1.0f);
}

void ASnakeHeadPawn::EatFruit()
{
	Score++;
	UE_LOG(HeadPawn, Display, TEXT("Eat fruit score: %i"), Score);
	UE_LOG(HeadPawn, Display, TEXT("Eat tails score: %i"), Tails.Num());

	FActorSpawnParameters Params;
	Params.Owner = this;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	FVector PreviousLocation = NewLocation;

	ASnakeGameModeBase* GameMode = Cast<ASnakeGameModeBase>(GetWorld()->GetAuthGameMode());
 
	SetActorLocation(GameMode->RandomSpawnLocation);

	if (MovementDiraction.X != 0.0f)
	{
		TailSpawnLocation.X = PreviousLocation.X - MovementDiraction.X * 10;
		TailSpawnLocation.Y = GetActorLocation().Y;
	}
	else if (MovementDiraction.Y != 0.0f)
	{
		TailSpawnLocation.Y = PreviousLocation.Y - MovementDiraction.Y * 10;
		TailSpawnLocation.X = GetActorLocation().X;
	}

	TailSpawnLocation.Z = GetActorLocation().Z;

	ATail* Tail = GetWorld()->SpawnActor<ATail>(ATail::StaticClass(), TailSpawnLocation, FRotator(0.0f, 0.0f, 0.0f), Params);
}
