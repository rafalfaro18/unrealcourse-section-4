// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay(){
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));

	if (GetControlledTank() != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Tank %s controlled"), *GetControlledTank()->GetName());
	}
}
