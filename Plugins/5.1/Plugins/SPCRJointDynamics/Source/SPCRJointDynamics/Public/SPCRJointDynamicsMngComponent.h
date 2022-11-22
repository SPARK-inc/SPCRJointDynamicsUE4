//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#pragma once

//======================================================================================
//
//======================================================================================
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "SPCRJointDynamicsComponent.h"
#include "SPCRJointDynamicsMngComponent.generated.h"

//======================================================================================
//
//======================================================================================
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPCRJOINTDYNAMICS_API USPCRJointDynamicsMngComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USPCRJointDynamicsMngComponent();

	TArray<USPCRJointDynamicsComponent*> jointDynamicsComponents;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetActors();
	
	UFUNCTION(BlueprintCallable)
	void OnReset();
};
