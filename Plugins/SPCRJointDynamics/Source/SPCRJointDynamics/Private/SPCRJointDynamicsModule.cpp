//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#include "SPCRJointDynamicsModulePCH.h"
#include "ISPCRJointDynamicsModule.h"
#include "ISettingsModule.h"

//======================================================================================
//
//======================================================================================
#define LOCTEXT_NAMESPACE "SPCRJointDynamicsModule"

class FSPCRJointDynamicsModule : public ISPCRJointDynamicsModule
{
public:
	//=========================================================================================================
	// PublicMethods
	//=========================================================================================================
	/**
	* @brief	Startup module.
	*/
	virtual void StartupModule() override;

	/**
	* @brief	Shutdown module.
	*/
	virtual void ShutdownModule() override;

private:


public:

};


//======================================================================================
//
//======================================================================================
IMPLEMENT_MODULE(FSPCRJointDynamicsModule, SPCRJointDynamics)

//=========================================================================================================
// PublicMethods
//=========================================================================================================

void FSPCRJointDynamicsModule::StartupModule()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "SPCRJointDynamics",
			LOCTEXT("SPCRJointDynamicsRuntimeSettingsName", "SPCRJointDynamics Runtime"),
			LOCTEXT("SPCRJointDynamicsRuntimeSettingsDescription", "Configure the SPCRJointDynamics"),
			GetMutableDefault<USPCRJointDynamicsRuntimeSettings>());
	}
}

void FSPCRJointDynamicsModule::ShutdownModule()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "SPCRJointDynamics");
	}
}

#undef LOCTEXT_NAMESPACE

//=========================================================================================================
// EOF
//=========================================================================================================
