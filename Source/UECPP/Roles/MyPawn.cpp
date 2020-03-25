// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Components\StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "UObject/ConstructorHelpers.h"




// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	MyStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMesh"));
	MyStaticMesh->SetupAttachment(GetRootComponent());
	RootComponent = GetStatciMeshComp();

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialInterfaceAsset(TEXT("Material'/Engine/MapTemplates/Sky/Desert_Outer_HDR_Mat.Desert_Outer_HDR_Mat'"));
	if (StaticMeshAsset.Succeeded() && MaterialInterfaceAsset.Succeeded()) 
	{
		GetStatciMeshComp()->SetStaticMesh(StaticMeshAsset.Object);
		GetStatciMeshComp()->SetMaterial(0, MaterialInterfaceAsset.Object);
	}
	MyStaticMesh->SetCollisionProfileName(TEXT("Pawn"));


	MySpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("MySpringArm"));
	MySpringArm->SetupAttachment(GetStatciMeshComp());
	MySpringArm->bEnableCameraLag = true;
	MySpringArm->CameraLagSpeed = 3.0f;
	MySpringArm->TargetArmLength = 500.0f;
	MySpringArm->RelativeRotation = FRotator(-50.0f, 0.0f, 0.0f);


	MyCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MyCamera"));
	MyCamera->SetupAttachment(GetSpringArmComp());
	//MyCamera->SetRelativeLocation(FVector(-300.0f, 0.0f, 300.0f));
	//MyCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	bUseControllerRotationYaw = true;

	MaxSpeed = 1000.0f;
	Velocity = FVector::ZeroVector;
	CameraRotation = FVector2D::ZeroVector;
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();


	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalOffset(Velocity * DeltaTime, true);

	AddControllerYawInput(CameraRotation.X);

	FRotator tPawnRotator = GetSpringArmComp()->GetComponentRotation();
	tPawnRotator.Pitch = FMath::Clamp((tPawnRotator.Pitch + CameraRotation.Y), -80.0f, 15.0f);
	GetSpringArmComp()->SetWorldRotation(tPawnRotator);
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyPawn::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyPawn::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMyPawn::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &AMyPawn::LookRight);
}

void AMyPawn::MoveForward(float inVal)
{
	Velocity.X = FMath::Clamp(inVal, -1.0f, 1.0f) * MaxSpeed;
}

void AMyPawn::MoveRight(float inVal)
{
	Velocity.Y = FMath::Clamp(inVal, -1.0f, 1.0f) * MaxSpeed;
}

void AMyPawn::LookUp(float inVal)
{
	CameraRotation.Y = FMath::Clamp(inVal, -1.0f, 1.0f);
}

void AMyPawn::LookRight(float inVal)
{
	CameraRotation.X = FMath::Clamp(inVal, -1.0f, 1.0f);
}

