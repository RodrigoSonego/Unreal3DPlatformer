// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category="MovingPlatform")
	FVector platformVelocity = FVector(0, 2, 0);

	UPROPERTY(EditAnywhere, Category="MovingPlatform")
	float maxMoveDistance = 1000;

	UPROPERTY(EditAnywhere, Category="MovingPlatform")
	FRotator rotationVelocity;

	FVector startLocation;

	void MovePlatform(float deltaTime);
	void RotatePlatform(float deltaTime);

	bool HasPlatformReachedMaxDistance() const;
};
