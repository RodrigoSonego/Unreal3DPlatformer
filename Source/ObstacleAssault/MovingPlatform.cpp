// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

void doStuff() {
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, FString::Printf(TEXT("hey i did stuff")));
}

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	doStuff();

	startLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector location = GetActorLocation();

	float distance = FVector::Distance(location, startLocation);
	
	if (distance >= maxMoveDistance) {
		FVector moveDirection = platformVelocity.GetSafeNormal();
		startLocation += moveDirection * maxMoveDistance;
		SetActorLocation(startLocation);

		platformVelocity = -platformVelocity;
	}

	location += platformVelocity * DeltaTime;

	SetActorLocation(location);

}
