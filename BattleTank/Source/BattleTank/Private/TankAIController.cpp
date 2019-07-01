// Fill out your copyright notice in the Description page of Project Settings.


#include "Classes/Engine/World.h"
#include "Classes/GameFramework/PlayerController.h"
#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	UE_LOG(LogTemp, Warning, TEXT("TankAIController Begin Play"));

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController not possesing a tank."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController possesing: %s"), *ControlledTank->GetName());
	}

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController can't find player tank."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController found player tank: %s"), *PlayerTank->GetName());
	}
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) {
		return nullptr;
	}
	
	return Cast<ATank>(PlayerPawn);
}