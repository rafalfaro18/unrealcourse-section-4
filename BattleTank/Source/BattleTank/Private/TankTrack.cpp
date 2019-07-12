// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle) {
	// TODO: Clamp actual throttle value so player can't over-drive

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForcedLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForcedLocation);
}