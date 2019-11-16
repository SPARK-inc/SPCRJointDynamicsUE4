//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#include "SPCRJointDynamicsRuntimeSettings.h"
#include "SPCRJointDynamicsModulePCH.h"

//======================================================================================
//
//======================================================================================
USPCRJointDynamicsRuntimeSettings::USPCRJointDynamicsRuntimeSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
void USPCRJointDynamicsRuntimeSettings::PostLoad()
{
	Super::PostLoad();

}

//======================================================================================
//
//======================================================================================
#if WITH_EDITOR
void USPCRJointDynamicsRuntimeSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (!PropertyChangedEvent.MemberProperty)
		return;

	FName Name = PropertyChangedEvent.MemberProperty->GetFName();
}
#endif

//======================================================================================
// EOF
//======================================================================================
