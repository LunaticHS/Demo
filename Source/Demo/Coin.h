// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Coin.generated.h"

UCLASS()
class DEMO_API ACoin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle DeathTimerHandle;

	void DeathTimerComplete();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* CoinMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Dead;

	UFUNCTION(BlueprintCallable)
	void PlayCustomDeath();

	UFUNCTION(BlueprintNativeEvent)
	void OnOverlap(AActor* OverlappedActor, AActor* OtherActor);
};
