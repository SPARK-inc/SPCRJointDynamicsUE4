// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SPCRJointDynamics/Public/SPCRJointDynamicsComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSPCRJointDynamicsComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	SPCRJOINTDYNAMICS_API UClass* Z_Construct_UClass_USPCRJointDynamicsComponent();
	SPCRJOINTDYNAMICS_API UClass* Z_Construct_UClass_USPCRJointDynamicsComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SPCRJointDynamics();
// End Cross Module References
	void USPCRJointDynamicsComponent::StaticRegisterNativesUSPCRJointDynamicsComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USPCRJointDynamicsComponent);
	UClass* Z_Construct_UClass_USPCRJointDynamicsComponent_NoRegister()
	{
		return USPCRJointDynamicsComponent::StaticClass();
	}
	struct Z_Construct_UClass_USPCRJointDynamicsComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isReset_MetaData[];
#endif
		static void NewProp_isReset_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isReset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USPCRJointDynamicsComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_SPCRJointDynamics,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USPCRJointDynamicsComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "Comment", "//======================================================================================\n//\n//======================================================================================\n" },
		{ "IncludePath", "SPCRJointDynamicsComponent.h" },
		{ "ModuleRelativePath", "Public/SPCRJointDynamicsComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USPCRJointDynamicsComponent_Statics::NewProp_isReset_MetaData[] = {
		{ "Category", "SPCRJointDynamicsComponent" },
		{ "Comment", "//\xe3\x83\xaa\xe3\x82\xbb\xe3\x83\x83\xe3\x83\x88\xe3\x83\x95\xe3\x83\xa9\xe3\x82\xb0\n" },
		{ "ModuleRelativePath", "Public/SPCRJointDynamicsComponent.h" },
		{ "ToolTip", "\xe3\x83\xaa\xe3\x82\xbb\xe3\x83\x83\xe3\x83\x88\xe3\x83\x95\xe3\x83\xa9\xe3\x82\xb0" },
	};
#endif
	void Z_Construct_UClass_USPCRJointDynamicsComponent_Statics::NewProp_isReset_SetBit(void* Obj)
	{
		((USPCRJointDynamicsComponent*)Obj)->isReset = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USPCRJointDynamicsComponent_Statics::NewProp_isReset = { "isReset", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USPCRJointDynamicsComponent), &Z_Construct_UClass_USPCRJointDynamicsComponent_Statics::NewProp_isReset_SetBit, METADATA_PARAMS(Z_Construct_UClass_USPCRJointDynamicsComponent_Statics::NewProp_isReset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USPCRJointDynamicsComponent_Statics::NewProp_isReset_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USPCRJointDynamicsComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USPCRJointDynamicsComponent_Statics::NewProp_isReset,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USPCRJointDynamicsComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USPCRJointDynamicsComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USPCRJointDynamicsComponent_Statics::ClassParams = {
		&USPCRJointDynamicsComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USPCRJointDynamicsComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USPCRJointDynamicsComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_USPCRJointDynamicsComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USPCRJointDynamicsComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USPCRJointDynamicsComponent()
	{
		if (!Z_Registration_Info_UClass_USPCRJointDynamicsComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USPCRJointDynamicsComponent.OuterSingleton, Z_Construct_UClass_USPCRJointDynamicsComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USPCRJointDynamicsComponent.OuterSingleton;
	}
	template<> SPCRJOINTDYNAMICS_API UClass* StaticClass<USPCRJointDynamicsComponent>()
	{
		return USPCRJointDynamicsComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USPCRJointDynamicsComponent);
	USPCRJointDynamicsComponent::~USPCRJointDynamicsComponent() {}
	struct Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_SPCRJointDynamicsComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_SPCRJointDynamicsComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USPCRJointDynamicsComponent, USPCRJointDynamicsComponent::StaticClass, TEXT("USPCRJointDynamicsComponent"), &Z_Registration_Info_UClass_USPCRJointDynamicsComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USPCRJointDynamicsComponent), 1540647113U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_SPCRJointDynamicsComponent_h_2984044092(TEXT("/Script/SPCRJointDynamics"),
		Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_SPCRJointDynamicsComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_SPCRJointDynamicsComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
