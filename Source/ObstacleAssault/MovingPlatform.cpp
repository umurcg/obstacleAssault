// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform(): AActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	InitialPosition = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector Location = GetActorLocation();
	
	SetActorLocation(Location + PlatformVelocity * DeltaTime);

	const float distance=FVector::Distance(Location,InitialPosition);
	if(distance>MoveDistance)
	{
		InitialPosition = InitialPosition + PlatformVelocity.GetSafeNormal()*MoveDistance;
		PlatformVelocity = PlatformVelocity * -1;
		
		
	}
	

}

