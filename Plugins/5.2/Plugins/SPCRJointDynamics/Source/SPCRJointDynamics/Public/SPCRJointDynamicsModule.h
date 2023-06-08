//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#pragma once

//======================================================================================
//
//======================================================================================
#include "Engine.h"
#include "Modules/ModuleManager.h"

//======================================================================================
//
//======================================================================================
class USPCRJointDynamicsData;

//======================================================================================
//
//======================================================================================
/**
 * @class	SPCRJointDynamicsModule
 * @brief	The public interface to this module.  In most cases, this interface is only public to sibling modules\n
 *			within this plugin.
 */
class SPCRJointDynamicsModule : public IModuleInterface
{
public:

public:
	//=========================================================================================================
	// PublicMethods
	//=========================================================================================================
	/**
	* Called right after the module DLL has been loaded and the module object has been created
	*/
	virtual void StartupModule() = 0;

	/**
	* Called before the module is unloaded, right before the module object is destroyed.
	*/
	virtual void ShutdownModule() = 0;

protected:

public:
};

//======================================================================================
// EOF
//======================================================================================
