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

	FString name = GetName();

	UE_LOG(LogTemp, Display, TEXT("BeginPlay on %s"), *name);

	startLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float deltaTime) 
{
	if (HasPlatformReachedMaxDistance()) {
		FVector moveDirection = platformVelocity.GetSafeNormal();
		startLocation += moveDirection * maxMoveDistance;
		SetActorLocation(startLocation);

		platformVelocity = -platformVelocity;
	}

	FVector location = GetActorLocation();
	location += platformVelocity * deltaTime;

	SetActorLocation(location);
}

void AMovingPlatform::RotatePlatform(float deltaTime)
{
	AddActorLocalRotation(rotationVelocity * deltaTime);
}

bool AMovingPlatform::HasPlatformReachedMaxDistance() const
{
	FVector currentLocation = GetActorLocation();
	float distance = FVector::Distance(currentLocation, startLocation);

	return distance >= maxMoveDistance;
}