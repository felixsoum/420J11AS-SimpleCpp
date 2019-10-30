// Fill out your copyright notice in the Description page of Project Settings.


#include "Dummy.h"
#include "SimpleCppProjectile.h"

// Sets default values
ADummy::ADummy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshComponent;
}

// Called when the game starts or when spawned
void ADummy::BeginPlay()
{
	Super::BeginPlay();
	DummyMaterial = MeshComponent->CreateDynamicMaterialInstance(0);
}

// Called every frame
void ADummy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	HitValue = FMath::Clamp(HitValue - 4 * DeltaTime, 0.0f, 1.0f);
	UpdateMaterial();
}

void ADummy::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	if (Cast<ASimpleCppProjectile>(Other) == nullptr)
	{
		return;
	}

	Other->Destroy();

	if (--Hp == 0)
	{
		if (GEngine != nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, TEXT("OOF"));
		}

		Destroy();
	}
	else
	{
		HitValue = 1;
		UpdateMaterial();
	}
}

void ADummy::UpdateMaterial()
{
	if (DummyMaterial != nullptr)
	{
		DummyMaterial->SetScalarParameterValue(TEXT("HitValue"), HitValue);
	}
}
