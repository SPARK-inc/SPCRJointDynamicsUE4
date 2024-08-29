//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#include "SPCRJointDynamicsEd.h"
#include "Modules/ModuleManager.h"
#include "Textures/SlateIcon.h"
#include "SPCRJointDynamics_Editor.h"


#define LOCTEXT_NAMESPACE "SPCRJOINTDYNAMICS_MODULE_ED"

//======================================================================================
//
//======================================================================================
class FSPCRJointDynamicsEd : public SPCRJointDynamicsEd
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

//======================================================================================
//
//======================================================================================
IMPLEMENT_MODULE(FSPCRJointDynamicsEd, SPCRJointDynamicsEd)

//======================================================================================
//
//======================================================================================
void FSPCRJointDynamicsEd::StartupModule()
{
	FEditorModeRegistry::Get().RegisterMode<SPCRJointDynamics_Editor>(SPCRJointDynamics_Editor::REGISTER_MODE_ID, 
		LOCTEXT("SPCRJointDynamics_Editor", "SPCR Joint Dynamics"), FSlateIcon(), false);
}

void FSPCRJointDynamicsEd::ShutdownModule()
{
	FEditorModeRegistry::Get().UnregisterMode(SPCRJointDynamics_Editor::REGISTER_MODE_ID);
}

//======================================================================================
//
//======================================================================================

#undef LOCTEXT_NAMESPACE