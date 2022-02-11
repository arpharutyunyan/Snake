// Snake game. All rights reserved.


#include "SnakeHeadPawn.h"
#include <Components/StaticMeshComponent.h>
#include <Components/InputComponent.h>
#include "CameraPawn.h"
#include <Components/SceneComponent.h>
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <GameFramework/Controller.h>

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
	//HeadMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 11.5f));
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
	
	UE_LOG(HeadPawn, Display, TEXT("beginplay"));
	//GetWorld()->SpawnActor<ACameraPawn>(ACameraPawn::StaticClass());
}

// Called every frame
void ASnakeHeadPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!MovementDiraction.IsZero())
	{
		const FVector NewLocation = GetActorLocation() + MovementDiraction * Speed * DeltaTime;
		SetActorLocation(NewLocation);
	}

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

/*void ASnakeHeadPawn::CameraViewer()
{
	UE_LOG(HeadPawn, Display, TEXT("arm"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetRootComponent());

	UE_LOG(HeadPawn, Display, TEXT("camera"));
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

	UE_LOG(HeadPawn, Display, TEXT("location"));
	SpringArm->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));
	SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 1500.0f));
}*/
