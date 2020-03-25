// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Components\StaticMeshComponent.h"


// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMesh"));
	InitLocation = FVector(0.0f);
	PlaceLocation = FVector(0.0f);
	bShouldInitLoc = false;
	WorldOrigin = FVector(0.0f);
	TickOffset = FVector(1.0f);
	IintForce = FVector(0.0f);
	InitTorque = FVector(0.0f);
	bAccel = false;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	PlaceLocation = GetActorLocation();

	if (bShouldInitLoc)
	{
		SetActorLocation(InitLocation);
	}

	//MyStaticMesh->AddForce(IintForce, "NAME_None", bAccel);
	//MyStaticMesh->AddTorque(InitTorque, "NAME_None", bAccel);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bMovePerTick) 
	{
		FHitResult tHitResult;
		//SetActorLocation(GetActorLocation() + TickOffset, true);
		AddActorLocalOffset(TickOffset, true, &tHitResult);
		//UE_LOG(LogTemp, Warning, TEXT("X: %f, Y: %f, Z: %f"), tHitResult.Location.X, tHitResult.Location.Y, tHitResult.Location.Z);
	}
	

}

