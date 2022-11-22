// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SPCRJointDynamics/Public/SPCRJointDynamicsRuntimeSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSPCRJointDynamicsRuntimeSettings() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	SPCRJOINTDYNAMICS_API UClass* Z_Construct_UClass_USPCRJointDynamicsRuntimeSettings();
	SPCRJOINTDYNAMICS_API UClass* Z_Construct_UClass_USPCRJointDynamicsRuntimeSettings_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SPCRJointDynamics();
// End Cross Module References
	void USPCRJointDynamicsRuntimeSettings::StaticRegisterNativesUSPCRJointDynamicsRuntimeSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USPCRJointDynamicsRuntimeSettings);
	UClass* Z_Construct_UClass_USPCRJointDynamicsRuntimeSettings_NoRegister()
	{
		return USPCRJointDynamicsRuntimeSettings::StaticClass();
	}
	struct Z_Construct_UClass_USPCRJointDynamicsRuntimeSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USPCRJointDynamicsRuntimeSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_SPCRJointDynamics,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USPCRJointDynamicsRuntimeSettings_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n* @class\x09UBYBLOSRuntimeSettings\n* @brief\x09Rutime\xe7\x94\xa8""Config\xe3\x81\xae\xe3\x82\xa8\xe3\x83\xb3\xe3\x83\x88\xe3\x83\xaa\xe3\x83\xbc\xe3\x81\xa8\xe3\x81\xaa\xe3\x82\x8b\xe3\x82\xaf\xe3\x83\xa9\xe3\x82\xb9\n*/" },
		{ "IncludePath", "SPCRJointDynamicsRuntimeSettings.h" },
		{ "ModuleRelativePath", "Public/SPCRJointDynamicsRuntimeSettings.h" },
		{ "ToolTip", "@class       UBYBLOSRuntimeSettings\n@brief       Rutime\xe7\x94\xa8""Config\xe3\x81\xae\xe3\x82\xa8\xe3\x83\xb3\xe3\x83\x88\xe3\x83\xaa\xe3\x83\xbc\xe3\x81\xa8\xe3\x81\xaa\xe3\x82\x8b\xe3\x82\xaf\xe3\x83\xa9\xe3\x82\xb9" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USPCRJointDynamicsRuntimeSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USPCRJointDynamicsRuntimeSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USPCRJointDynamicsRuntimeSettings_Statics::ClassParams = {
		&USPCRJointDynamicsRuntimeSettings::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A2u,
		METADATA_PARAMS(Z_Construct_UClass_USPCRJointDynamicsRuntimeSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USPCRJointDynamicsRuntimeSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USPCRJointDynamicsRuntimeSettings()
	{
		if (!Z_Registration_Info_UClass_USPCRJointDynamicsRuntimeSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USPCRJointDynamicsRuntimeSettings.OuterSingleton, Z_Construct_UClass_USPCRJointDynamicsRuntimeSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USPCRJointDynamicsRuntimeSettings.OuterSingleton;
	}
	template<> SPCRJOINTDYNAMICS_API UClass* StaticClass<USPCRJointDynamicsRuntimeSettings>()
	{
		return USPCRJointDynamicsRuntimeSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USPCRJointDynamicsRuntimeSettings);
	USPCRJointDynamicsRuntimeSettings::~USPCRJointDynamicsRuntimeSettings() {}
	struct Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_SPCRJointDynamicsRuntimeSettings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_SPCRJointDynamicsRuntimeSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USPCRJointDynamicsRuntimeSettings, USPCRJointDynamicsRuntimeSettings::StaticClass, TEXT("USPCRJointDynamicsRuntimeSettings"), &Z_Registration_Info_UClass_USPCRJointDynamicsRuntimeSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USPCRJointDynamicsRuntimeSettings), 151916085U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_SPCRJointDynamicsRuntimeSettings_h_2983369268(TEXT("/Script/SPCRJointDynamics"),
		Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_SPCRJointDynamicsRuntimeSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_SPCRJointDynamicsRuntimeSettings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
