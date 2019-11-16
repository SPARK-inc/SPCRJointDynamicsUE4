//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#include "SPCRJointDynamicsComponent.h"
//#include "Actor.h"

// Sets default values for this component's properties
USPCRJointDynamicsComponent::USPCRJointDynamicsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USPCRJointDynamicsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	OnInit();
}


// Called every frame
void USPCRJointDynamicsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	OnUpdateReset();
}


void USPCRJointDynamicsComponent::OnInit() {
	isReset = false;
	isFinishReset = false;
}

void USPCRJointDynamicsComponent::OnUpdateReset() {
	if (isFinishReset) {
		OnInit();
	}

}

void USPCRJointDynamicsComponent::OnStartReset() {
	isReset = true;
}

void USPCRJointDynamicsComponent::OnFinishReset() {
	isFinishReset = true;
}

