// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class UNREALLEARNINGKIT_API AMovingPlatform : public AActor
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

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector MovementVelocity = FVector(0, 0, 100); // Move in the X direction in cm/s

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovementDistance = 1000; // Move 1000 cm (10 m) in the X direction

	UPROPERTY(EditAnywhere, Category = "Rotation")
	FRotator RotationVelocity;

	FVector StartLocation = FVector(0, 0, 0);

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	bool ShouldReverseDirection() const;
	float GetDistanceMoved() const;
};
