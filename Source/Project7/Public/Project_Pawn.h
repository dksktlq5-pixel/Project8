#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Project_Pawn.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class PROJECT7_API AProject_Pawn : public APawn
{
    GENERATED_BODY()

public:
    AProject_Pawn();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
    // 🔴 루트 충돌 컴포넌트 (Box)
    UPROPERTY(VisibleAnywhere)
    UBoxComponent* BoxComp;

    // 🔵 외형용 메쉬
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* MeshComp;

    // 🟡 3인칭 카메라
    UPROPERTY(VisibleAnywhere)
    USpringArmComponent* SpringArm;

    UPROPERTY(VisibleAnywhere)
    UCameraComponent* CameraComp;
};
