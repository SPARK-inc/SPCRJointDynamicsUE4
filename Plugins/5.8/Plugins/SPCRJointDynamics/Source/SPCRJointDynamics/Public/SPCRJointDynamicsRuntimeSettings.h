//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#pragma once

//======================================================================================
//
//======================================================================================
#include "SPCRJointDynamicsRuntimeSettings.generated.h" 

//======================================================================================
//
//======================================================================================
/**
* @class	UBYBLOSRuntimeSettings
* @brief	Rutime用Configのエントリーとなるクラス
*/
UCLASS(config = Game, defaultconfig)
class SPCRJOINTDYNAMICS_API USPCRJointDynamicsRuntimeSettings : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	/**
	* @brief	UObjectメソッドオーバーライド
	*/
	virtual void PostLoad() override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};

//======================================================================================
// EOF
//======================================================================================
