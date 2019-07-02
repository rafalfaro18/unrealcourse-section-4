// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay(){
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank."));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing: %s"), *ControlledTank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}



ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) { return; }

	FVector HitLocation;// Out parameter
	UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	// Get world location of linetrace through crosshair
	// If it hits the landscape
		// Tell controlled tank to aim at this point
}