#include "Project_Pawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "UObject/ConstructorHelpers.h"


AProject_Pawn::AProject_Pawn()
{
    PrimaryActorTick.bCanEverTick = true;

    // Box Collision (Root)
    BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
    RootComponent = BoxComp;

    BoxComp->InitBoxExtent(FVector(50.f, 50.f, 50.f));
    BoxComp->SetCollisionProfileName(TEXT("Pawn"));
    BoxComp->SetSimulatePhysics(false);
    BoxComp->SetEnableGravity(false);

    // Static Mesh
    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
    MeshComp->SetupAttachment(BoxComp);

    MeshComp->SetSimulatePhysics(false);
    MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(
        TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube'")
    );

    if (CubeMesh.Succeeded())
    {
        MeshComp->SetStaticMesh(CubeMesh.Object);
    }

    // SpringArm
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(BoxComp);
    SpringArm->TargetArmLength = 300.f;
    SpringArm->bUsePawnControlRotation = true;

    // Camera
    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
    CameraComp->SetupAttachment(SpringArm);
    CameraComp->bUsePawnControlRotation = false;

    AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void AProject_Pawn::BeginPlay()
{
    Super::BeginPlay();
}

void AProject_Pawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AProject_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}
