// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"
#include "DemoCharacter.h"

// Sets default values
ACoin::ACoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>("CoinMesh");
	CoinMesh->SetupAttachment(Root);
	CoinMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	RotationRate = 100;
	Dead = 0;

	OnActorBeginOverlap.AddDynamic(this, &ACoin::OnOverlap);
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	AddActorLocalRotation(FRotator(0, RotationRate * DeltaTime, 0));

}

void ACoin::DeathTimerComplete()
{
	Destroy();
}

void ACoin::PlayCustomDeath()
{
	RotationRate = 1500;
	GetWorldTimerManager().SetTimer(DeathTimerHandle, this, &ACoin::DeathTimerComplete, 0.5f, false);
}

void ACoin::OnOverlap_Implementation(AActor* OverlappedActor, AActor* OtherActor)
{
	if (Cast<ADemoCharacter>(OtherActor) != nullptr && Dead == 0)
	{
		Dead = 1;
		PlayCustomDeath();
		Destroy();
	}
}