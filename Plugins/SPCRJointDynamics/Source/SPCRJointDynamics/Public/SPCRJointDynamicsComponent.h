//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SPCRJointDynamicsComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPCRJOINTDYNAMICS_API USPCRJointDynamicsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USPCRJointDynamicsComponent();

	//リセットを行うフラグをオンにする
	//UFUNCTION(BlueprintCallable)
	void OnStartReset();

	//AnimBPのJointDynamicsノードでリセットを行ったときに呼ばれる
	void OnFinishReset();

	//リセットフラグ
	UPROPERTY(BlueprintReadOnly)
	bool isReset;

protected:
	//リセット処理終了確認のフラグ
	bool isFinishReset;

	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void OnInit();
	void OnUpdateReset();

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
