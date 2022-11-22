// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SPCRJointDynamicsEd/Public/AnimGraphNode_SPCRJointDynamics.h"
#include "SPCRJointDynamics/Public/AnimNode_SPCRJointDynamics.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimGraphNode_SPCRJointDynamics() {}
// Cross Module References
	ANIMGRAPH_API UClass* Z_Construct_UClass_UAnimGraphNode_SkeletalControlBase();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	SPCRJOINTDYNAMICS_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics();
	SPCRJOINTDYNAMICSED_API UClass* Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics();
	SPCRJOINTDYNAMICSED_API UClass* Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SPCRJointDynamicsEd();
// End Cross Module References
	void UAnimGraphNode_SPCRJointDynamics::StaticRegisterNativesUAnimGraphNode_SPCRJointDynamics()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAnimGraphNode_SPCRJointDynamics);
	UClass* Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_NoRegister()
	{
		return UAnimGraphNode_SPCRJointDynamics::StaticClass();
	}
	struct Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Node_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Node;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LastPreviewComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LastPreviewComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimGraphNode_SkeletalControlBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SPCRJointDynamicsEd,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::Class_MetaDataParams[] = {
		{ "Comment", "//======================================================================================\n//\n//======================================================================================\n" },
		{ "IncludePath", "AnimGraphNode_SPCRJointDynamics.h" },
		{ "ModuleRelativePath", "Public/AnimGraphNode_SPCRJointDynamics.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::NewProp_Node_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/AnimGraphNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::NewProp_Node = { "Node", nullptr, (EPropertyFlags)0x0010008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UAnimGraphNode_SPCRJointDynamics, Node), Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics, METADATA_PARAMS(Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::NewProp_Node_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::NewProp_Node_MetaData)) }; // 3276718777
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::NewProp_LastPreviewComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/AnimGraphNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::NewProp_LastPreviewComponent = { "LastPreviewComponent", nullptr, (EPropertyFlags)0x0040000000082008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UAnimGraphNode_SPCRJointDynamics, LastPreviewComponent), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::NewProp_LastPreviewComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::NewProp_LastPreviewComponent_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::NewProp_Node,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::NewProp_LastPreviewComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAnimGraphNode_SPCRJointDynamics>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::ClassParams = {
		&UAnimGraphNode_SPCRJointDynamics::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::PropPointers),
		0,
		0x008000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics()
	{
		if (!Z_Registration_Info_UClass_UAnimGraphNode_SPCRJointDynamics.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAnimGraphNode_SPCRJointDynamics.OuterSingleton, Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UAnimGraphNode_SPCRJointDynamics.OuterSingleton;
	}
	template<> SPCRJOINTDYNAMICSED_API UClass* StaticClass<UAnimGraphNode_SPCRJointDynamics>()
	{
		return UAnimGraphNode_SPCRJointDynamics::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAnimGraphNode_SPCRJointDynamics);
	UAnimGraphNode_SPCRJointDynamics::~UAnimGraphNode_SPCRJointDynamics() {}
	struct Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamicsEd_Public_AnimGraphNode_SPCRJointDynamics_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamicsEd_Public_AnimGraphNode_SPCRJointDynamics_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UAnimGraphNode_SPCRJointDynamics, UAnimGraphNode_SPCRJointDynamics::StaticClass, TEXT("UAnimGraphNode_SPCRJointDynamics"), &Z_Registration_Info_UClass_UAnimGraphNode_SPCRJointDynamics, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAnimGraphNode_SPCRJointDynamics), 190721820U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamicsEd_Public_AnimGraphNode_SPCRJointDynamics_h_977864895(TEXT("/Script/SPCRJointDynamicsEd"),
		Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamicsEd_Public_AnimGraphNode_SPCRJointDynamics_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamicsEd_Public_AnimGraphNode_SPCRJointDynamics_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
