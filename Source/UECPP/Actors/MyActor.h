// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"


UCLASS()
class UECPP_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
	UPROPERTY(VisibleAnywhere, Category = "My Actor Variable | Component")
	UStaticMeshComponent *MyStaticMesh;

	UPROPERTY(EditInstanceOnly, Category = "My Actor Variable | Vector")
	FVector InitLocation;

	UPROPERTY(EditDefaultsOnly, Category = "My Actor Variable | Vector")
	bool bShouldInitLoc;
	UPROPERTY(VisibleDefaultsOnly, Category = "My Actor Variable | Vector")
	FVector WorldOrigin;
	UPROPERTY(EditAnywhere, Category = "My Actor Variable | Vector")
	bool bMovePerTick;

	UPROPERTY(EditInstanceOnly, Category = "My Actor Variable | Vector", meta = (ClampMin = -5.0f, ClampMax = 5.0f, UIMin = -5.0f, UIMax = 5.0f))
	FVector TickOffset;
	UPROPERTY(EditInstanceOnly, Category = "My Actor Variable | Physics")
	FVector IintForce;
	UPROPERTY(EditInstanceOnly, Category = "My Actor Variable | Physics")
	FVector InitTorque;
	UPROPERTY(EditInstanceOnly, Category = "My Actor Variable | Physics")
	bool bAccel;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleInstanceOnly, Category = "My Actor Variable | vector")
	FVector PlaceLocation;
};
