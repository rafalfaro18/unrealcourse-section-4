// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Math/UnrealMathUtility.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed) {
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

	auto RawNewElevation = FMath::Clamp(
		RelativeRotation.Pitch + ElevationChange,
		MinElevationDegrees,
		MaxElevationDegrees
	);

	SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
}