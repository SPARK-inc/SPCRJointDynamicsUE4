// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SPCRJointDynamics/Public/SPCRJointDynamicsMngComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSPCRJointDynamicsMngComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	SPCRJOINTDYNAMICS_API UClass* Z_Construct_UClass_USPCRJointDynamicsMngComponent();
	SPCRJOINTDYNAMICS_API UClass* Z_Construct_UClass_USPCRJointDynamicsMngComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SPCRJointDynamics();
// End Cross Module References
	DEFINE_FUNCTION(USPCRJointDynamicsMngComponent::execOnReset)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnReset();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USPCRJointDynamicsMngComponent::execSetActors)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetActors();
		P_NATIVE_END;
	}
	void USPCRJointDynamicsMngComponent::StaticRegisterNativesUSPCRJointDynamicsMngComponent()
	{
		UClass* Class = USPCRJointDynamicsMngComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnReset", &USPCRJointDynamicsMngComponent::execOnReset },
			{ "SetActors", &USPCRJointDynamicsMngComponent::execSetActors },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USPCRJointDynamicsMngComponent_OnReset_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USPCRJointDynamicsMngComponent_OnReset_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SPCRJointDynamicsMngComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USPCRJointDynamicsMngComponent_OnReset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USPCRJointDynamicsMngComponent, nullptr, "OnReset", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USPCRJointDynamicsMngComponent_OnReset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USPCRJointDynamicsMngComponent_OnReset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USPCRJointDynamicsMngComponent_OnReset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USPCRJointDynamicsMngComponent_OnReset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USPCRJointDynamicsMngComponent_SetActors_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USPCRJointDynamicsMngComponent_SetActors_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SPCRJointDynamicsMngComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USPCRJointDynamicsMngComponent_SetActors_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USPCRJointDynamicsMngComponent, nullptr, "SetActors", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USPCRJointDynamicsMngComponent_SetActors_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USPCRJointDynamicsMngComponent_SetActors_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USPCRJointDynamicsMngComponent_SetActors()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USPCRJointDynamicsMngComponent_SetActors_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USPCRJointDynamicsMngComponent);
	UClass* Z_Construct_UClass_USPCRJointDynamicsMngComponent_NoRegister()
	{
		return USPCRJointDynamicsMngComponent::StaticClass();
	}
	struct Z_Construct_UClass_USPCRJointDynamicsMngComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USPCRJointDynamicsMngComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_SPCRJointDynamics,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USPCRJointDynamicsMngComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USPCRJointDynamicsMngComponent_OnReset, "OnReset" }, // 909676970
		{ &Z_Construct_UFunction_USPCRJointDynamicsMngComponent_SetActors, "SetActors" }, // 1794831739
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USPCRJointDynamicsMngComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "Comment", "//======================================================================================\n//\n//======================================================================================\n" },
		{ "IncludePath", "SPCRJointDynamicsMngComponent.h" },
		{ "ModuleRelativePath", "Public/SPCRJointDynamicsMngComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USPCRJointDynamicsMngComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USPCRJointDynamicsMngComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USPCRJointDynamicsMngComponent_Statics::ClassParams = {
		&USPCRJointDynamicsMngComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_USPCRJointDynamicsMngComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USPCRJointDynamicsMngComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USPCRJointDynamicsMngComponent()
	{
		if (!Z_Registration_Info_UClass_USPCRJointDynamicsMngComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USPCRJointDynamicsMngComponent.OuterSingleton, Z_Construct_UClass_USPCRJointDynamicsMngComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USPCRJointDynamicsMngComponent.OuterSingleton;
	}
	template<> SPCRJOINTDYNAMICS_API UClass* StaticClass<USPCRJointDynamicsMngComponent>()
	{
		return USPCRJointDynamicsMngComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USPCRJointDynamicsMngComponent);
	USPCRJointDynamicsMngComponent::~USPCRJointDynamicsMngComponent() {}
	struct Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_SPCRJointDynamicsMngComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_SPCRJointDynamicsMngComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USPCRJointDynamicsMngComponent, USPCRJointDynamicsMngComponent::StaticClass, TEXT("USPCRJointDynamicsMngComponent"), &Z_Registration_Info_UClass_USPCRJointDynamicsMngComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USPCRJointDynamicsMngComponent), 3676324388U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_SPCRJointDynamicsMngComponent_h_1940486715(TEXT("/Script/SPCRJointDynamics"),
		Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_SPCRJointDynamicsMngComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_SPCRJointDynamicsMngComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
