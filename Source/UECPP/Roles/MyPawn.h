// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class UECPP_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

	UPROPERTY(VisibleAnywhere, Category = "MyPawnComponents | Component")
	UStaticMeshComponent *MyStaticMesh;
	UPROPERTY(VisibleAnywhere, Category = "MyPawnComponents | Component")
	class UCameraComponent* MyCamera; // 增加class告诉编译器这个变量会在后面进行包含，前置声明
	UPROPERTY(VisibleAnywhere, Category = "MyPawnComponents | Component")
	class USpringArmComponent* MySpringArm;	// 用于设置摇臂

	UPROPERTY(EditAnywhere, Category = "MyPawnMovement")
	float MaxSpeed;

	FORCEINLINE UStaticMeshComponent* GetStatciMeshComp()
	{
		return MyStaticMesh; 
	}

	FORCEINLINE USpringArmComponent* GetSpringArmComp()
	{
		return MySpringArm;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float inVal);
	void MoveRight(float inVal);
	FVector Velocity;

	void LookUp(float inVal);
	void LookRight(float inVal);
	FVector2D CameraRotation;

};
