// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

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

	StartLocation = GetActorLocation(); // Get the current location of the actor
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime); // Call the MovePlatform function to update the platform's position

	RotatePlatform(DeltaTime); // Call the RotatePlatform function to update the platform's rotation

}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	
	

	if(ShouldReverseDirection()) // If the distance moved is greater than the movement distance
	{

		FVector MoveDirection = MovementVelocity.GetSafeNormal(); // Get the normalized direction of movement

		StartLocation = StartLocation + MoveDirection * MovementDistance; // Update the start location to the new position
		SetActorLocation(StartLocation);

		// Reverse the direction of movement
		MovementVelocity = -MovementVelocity;
	}
	else{

		FVector CurrentLocation = GetActorLocation(); // Get the current location of the actor

    	CurrentLocation = CurrentLocation + (MovementVelocity * DeltaTime); // Update the location based on velocity and delta time;

		SetActorLocation(CurrentLocation); // Set the actor's location to new location
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity * DeltaTime); // Rotate the platform based on the rotation velocity and delta time
}

bool AMovingPlatform::ShouldReverseDirection() const
{

	float DistanceMoved = GetDistanceMoved();
	return DistanceMoved > MovementDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(GetActorLocation(), StartLocation); // Calculate the distance from the start location
}