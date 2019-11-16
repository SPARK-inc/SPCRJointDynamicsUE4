//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#include "SPCRJointDynamicsMngComponent.h"

// Sets default values for this component's properties
USPCRJointDynamicsMngComponent::USPCRJointDynamicsMngComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USPCRJointDynamicsMngComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	jointDynamicsComponents.Empty();
}


// Called every frame
void USPCRJointDynamicsMngComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USPCRJointDynamicsMngComponent::SetActors() {
	AActor* actor = GetOwner();
	TArray<AActor*> attachedActors;
	attachedActors.Empty();
	actor->GetAttachedActors(attachedActors);
	jointDynamicsComponents.Empty();

	//アタッチされたアクターたち
	for (int i = 0; i < attachedActors.Num();i++) {
		USPCRJointDynamicsComponent* component = (USPCRJointDynamicsComponent*)(attachedActors[i]->GetComponentByClass(USPCRJointDynamicsComponent::StaticClass()));
		if (component != NULL) {
			jointDynamicsComponents.Add(component);
		}
	}

	//自身
	USPCRJointDynamicsComponent* component = (USPCRJointDynamicsComponent*)(actor->GetComponentByClass(USPCRJointDynamicsComponent::StaticClass()));
	if (component != NULL) {
		jointDynamicsComponents.Add(component);
	}
}

void USPCRJointDynamicsMngComponent::OnReset() {
	for (int i = 0; i < jointDynamicsComponents.Num();i++) {
		//jointDynamicsComponents[i]->OnFinishReset();
		jointDynamicsComponents[i]->OnStartReset();
	}
}



