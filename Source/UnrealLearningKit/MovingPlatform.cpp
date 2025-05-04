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
	FVector CurrentLocation = GetActorLocation(); // Get the current location of the actor

    CurrentLocation = CurrentLocation + (MovementVelocity * DeltaTime); // Update the location based on velocity and delta time;

	SetActorLocation(CurrentLocation); // Set the actor's location to new location

	float DistanceMoved = FVector::Dist(CurrentLocation, StartLocation); // Calculate the distance from the start location

	if(DistanceMoved > MovementDistance) // If the distance moved is greater than the movement distance
	{

		FString Name = GetName(); // Get the name of the actor
		float OverShoot = DistanceMoved - MovementDistance; // Calculate the overshoot distance
		UE_LOG(LogTemp, Warning, TEXT("Actor: %s Overshot by distance: %f"), *Name, OverShoot); // Log the overshoot distance

		FVector MoveDirection = MovementVelocity.GetSafeNormal(); // Get the normalized direction of movement

		StartLocation = StartLocation + MoveDirection * MovementDistance; // Update the start location to the new position
		SetActorLocation(StartLocation);

		// Reverse the direction of movement
		MovementVelocity = -MovementVelocity;
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("Function RotatePlatform called")); // Log the function call
}