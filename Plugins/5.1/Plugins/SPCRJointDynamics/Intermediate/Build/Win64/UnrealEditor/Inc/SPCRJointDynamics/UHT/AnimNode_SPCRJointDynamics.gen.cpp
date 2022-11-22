// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SPCRJointDynamics/Public/AnimNode_SPCRJointDynamics.h"
#include "Engine/Public/BoneContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimNode_SPCRJointDynamics() {}
// Cross Module References
	ANIMGRAPHRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_SkeletalControlBase();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FBoneReference();
	SPCRJOINTDYNAMICS_API UClass* Z_Construct_UClass_USPCRJointDynamicsComponent_NoRegister();
	SPCRJOINTDYNAMICS_API UEnum* Z_Construct_UEnum_SPCRJointDynamics_SurfaceColliderType();
	SPCRJOINTDYNAMICS_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics();
	SPCRJOINTDYNAMICS_API UScriptStruct* Z_Construct_UScriptStruct_FSPCRCollider();
	SPCRJOINTDYNAMICS_API UScriptStruct* Z_Construct_UScriptStruct_FSPCRCurve();
	SPCRJOINTDYNAMICS_API UScriptStruct* Z_Construct_UScriptStruct_FSPCRCurveZero();
	SPCRJOINTDYNAMICS_API UScriptStruct* Z_Construct_UScriptStruct_FSPCRJointDynamicsBody();
	SPCRJOINTDYNAMICS_API UScriptStruct* Z_Construct_UScriptStruct_FSPCRJointPair();
	UPackage* Z_Construct_UPackage__Script_SPCRJointDynamics();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SPCRCollider;
class UScriptStruct* FSPCRCollider::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SPCRCollider.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SPCRCollider.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSPCRCollider, Z_Construct_UPackage__Script_SPCRJointDynamics(), TEXT("SPCRCollider"));
	}
	return Z_Registration_Info_UScriptStruct_SPCRCollider.OuterSingleton;
}
template<> SPCRJOINTDYNAMICS_API UScriptStruct* StaticStruct<FSPCRCollider>()
{
	return FSPCRCollider::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSPCRCollider_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSPCRCollider_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSPCRCollider_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSPCRCollider>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSPCRCollider_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SPCRJointDynamics,
		nullptr,
		&NewStructOps,
		"SPCRCollider",
		sizeof(FSPCRCollider),
		alignof(FSPCRCollider),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSPCRCollider_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRCollider_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSPCRCollider()
	{
		if (!Z_Registration_Info_UScriptStruct_SPCRCollider.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SPCRCollider.InnerSingleton, Z_Construct_UScriptStruct_FSPCRCollider_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SPCRCollider.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SPCRJointPair;
class UScriptStruct* FSPCRJointPair::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SPCRJointPair.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SPCRJointPair.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSPCRJointPair, Z_Construct_UPackage__Script_SPCRJointDynamics(), TEXT("SPCRJointPair"));
	}
	return Z_Registration_Info_UScriptStruct_SPCRJointPair.OuterSingleton;
}
template<> SPCRJOINTDYNAMICS_API UScriptStruct* StaticStruct<FSPCRJointPair>()
{
	return FSPCRJointPair::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSPCRJointPair_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RootBone_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RootBone;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EndBone_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_EndBone;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSPCRJointPair_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSPCRJointPair_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSPCRJointPair>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSPCRJointPair_Statics::NewProp_RootBone_MetaData[] = {
		{ "Category", "Solver" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSPCRJointPair_Statics::NewProp_RootBone = { "RootBone", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSPCRJointPair, RootBone), Z_Construct_UScriptStruct_FBoneReference, METADATA_PARAMS(Z_Construct_UScriptStruct_FSPCRJointPair_Statics::NewProp_RootBone_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRJointPair_Statics::NewProp_RootBone_MetaData)) }; // 2906976723
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSPCRJointPair_Statics::NewProp_EndBone_MetaData[] = {
		{ "Category", "Solver" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSPCRJointPair_Statics::NewProp_EndBone = { "EndBone", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSPCRJointPair, EndBone), Z_Construct_UScriptStruct_FBoneReference, METADATA_PARAMS(Z_Construct_UScriptStruct_FSPCRJointPair_Statics::NewProp_EndBone_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRJointPair_Statics::NewProp_EndBone_MetaData)) }; // 2906976723
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSPCRJointPair_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSPCRJointPair_Statics::NewProp_RootBone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSPCRJointPair_Statics::NewProp_EndBone,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSPCRJointPair_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SPCRJointDynamics,
		nullptr,
		&NewStructOps,
		"SPCRJointPair",
		sizeof(FSPCRJointPair),
		alignof(FSPCRJointPair),
		Z_Construct_UScriptStruct_FSPCRJointPair_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRJointPair_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSPCRJointPair_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRJointPair_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSPCRJointPair()
	{
		if (!Z_Registration_Info_UScriptStruct_SPCRJointPair.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SPCRJointPair.InnerSingleton, Z_Construct_UScriptStruct_FSPCRJointPair_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SPCRJointPair.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SPCRCurve;
class UScriptStruct* FSPCRCurve::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SPCRCurve.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SPCRCurve.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSPCRCurve, Z_Construct_UPackage__Script_SPCRJointDynamics(), TEXT("SPCRCurve"));
	}
	return Z_Registration_Info_UScriptStruct_SPCRCurve.OuterSingleton;
}
template<> SPCRJOINTDYNAMICS_API UScriptStruct* StaticStruct<FSPCRCurve>()
{
	return FSPCRCurve::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSPCRCurve_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Curve_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Curve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Power_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Power;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSPCRCurve_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSPCRCurve_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSPCRCurve>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSPCRCurve_Statics::NewProp_Curve_MetaData[] = {
		{ "Category", "Curve" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSPCRCurve_Statics::NewProp_Curve = { "Curve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSPCRCurve, Curve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FSPCRCurve_Statics::NewProp_Curve_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRCurve_Statics::NewProp_Curve_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSPCRCurve_Statics::NewProp_Power_MetaData[] = {
		{ "Category", "Curve" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSPCRCurve_Statics::NewProp_Power = { "Power", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSPCRCurve, Power), METADATA_PARAMS(Z_Construct_UScriptStruct_FSPCRCurve_Statics::NewProp_Power_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRCurve_Statics::NewProp_Power_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSPCRCurve_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSPCRCurve_Statics::NewProp_Curve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSPCRCurve_Statics::NewProp_Power,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSPCRCurve_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SPCRJointDynamics,
		nullptr,
		&NewStructOps,
		"SPCRCurve",
		sizeof(FSPCRCurve),
		alignof(FSPCRCurve),
		Z_Construct_UScriptStruct_FSPCRCurve_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRCurve_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSPCRCurve_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRCurve_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSPCRCurve()
	{
		if (!Z_Registration_Info_UScriptStruct_SPCRCurve.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SPCRCurve.InnerSingleton, Z_Construct_UScriptStruct_FSPCRCurve_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SPCRCurve.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SPCRCurveZero;
class UScriptStruct* FSPCRCurveZero::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SPCRCurveZero.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SPCRCurveZero.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSPCRCurveZero, Z_Construct_UPackage__Script_SPCRJointDynamics(), TEXT("SPCRCurveZero"));
	}
	return Z_Registration_Info_UScriptStruct_SPCRCurveZero.OuterSingleton;
}
template<> SPCRJOINTDYNAMICS_API UScriptStruct* StaticStruct<FSPCRCurveZero>()
{
	return FSPCRCurveZero::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSPCRCurveZero_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Curve_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Curve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Power_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Power;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSPCRCurveZero>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::NewProp_Curve_MetaData[] = {
		{ "Category", "Curve" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::NewProp_Curve = { "Curve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSPCRCurveZero, Curve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::NewProp_Curve_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::NewProp_Curve_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::NewProp_Power_MetaData[] = {
		{ "Category", "Curve" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::NewProp_Power = { "Power", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSPCRCurveZero, Power), METADATA_PARAMS(Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::NewProp_Power_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::NewProp_Power_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::NewProp_Curve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::NewProp_Power,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SPCRJointDynamics,
		nullptr,
		&NewStructOps,
		"SPCRCurveZero",
		sizeof(FSPCRCurveZero),
		alignof(FSPCRCurveZero),
		Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSPCRCurveZero()
	{
		if (!Z_Registration_Info_UScriptStruct_SPCRCurveZero.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SPCRCurveZero.InnerSingleton, Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SPCRCurveZero.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_SurfaceColliderType;
	static UEnum* SurfaceColliderType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_SurfaceColliderType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_SurfaceColliderType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SPCRJointDynamics_SurfaceColliderType, Z_Construct_UPackage__Script_SPCRJointDynamics(), TEXT("SurfaceColliderType"));
		}
		return Z_Registration_Info_UEnum_SurfaceColliderType.OuterSingleton;
	}
	template<> SPCRJOINTDYNAMICS_API UEnum* StaticEnum<SurfaceColliderType>()
	{
		return SurfaceColliderType_StaticEnum();
	}
	struct Z_Construct_UEnum_SPCRJointDynamics_SurfaceColliderType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SPCRJointDynamics_SurfaceColliderType_Statics::Enumerators[] = {
		{ "OFF", (int64)OFF },
		{ "PUSH", (int64)PUSH },
		{ "PULL", (int64)PULL },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SPCRJointDynamics_SurfaceColliderType_Statics::Enum_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
		{ "OFF.Name", "OFF" },
		{ "PULL.Name", "PULL" },
		{ "PUSH.Name", "PUSH" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SPCRJointDynamics_SurfaceColliderType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SPCRJointDynamics,
		nullptr,
		"SurfaceColliderType",
		"SurfaceColliderType",
		Z_Construct_UEnum_SPCRJointDynamics_SurfaceColliderType_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SPCRJointDynamics_SurfaceColliderType_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(Z_Construct_UEnum_SPCRJointDynamics_SurfaceColliderType_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SPCRJointDynamics_SurfaceColliderType_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SPCRJointDynamics_SurfaceColliderType()
	{
		if (!Z_Registration_Info_UEnum_SurfaceColliderType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_SurfaceColliderType.InnerSingleton, Z_Construct_UEnum_SPCRJointDynamics_SurfaceColliderType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_SurfaceColliderType.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SPCRJointDynamicsBody;
class UScriptStruct* FSPCRJointDynamicsBody::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SPCRJointDynamicsBody.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SPCRJointDynamicsBody.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody, Z_Construct_UPackage__Script_SPCRJointDynamics(), TEXT("SPCRJointDynamicsBody"));
	}
	return Z_Registration_Info_UScriptStruct_SPCRJointDynamicsBody.OuterSingleton;
}
template<> SPCRJOINTDYNAMICS_API UScriptStruct* StaticStruct<FSPCRJointDynamicsBody>()
{
	return FSPCRJointDynamicsBody::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetBone_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_TargetBone;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Transform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Transform;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Height;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Friction_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Friction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SurfaceColliderType_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_SurfaceColliderType;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSPCRJointDynamicsBody>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_TargetBone_MetaData[] = {
		{ "Category", "Body" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_TargetBone = { "TargetBone", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSPCRJointDynamicsBody, TargetBone), Z_Construct_UScriptStruct_FBoneReference, METADATA_PARAMS(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_TargetBone_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_TargetBone_MetaData)) }; // 2906976723
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Transform_MetaData[] = {
		{ "Category", "Body" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Transform = { "Transform", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSPCRJointDynamicsBody, Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Transform_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Transform_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Height_MetaData[] = {
		{ "Category", "Body" },
		{ "ClampMax", "50.000000" },
		{ "ClampMin", "0.000000" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
		{ "UIMax", "50.000000" },
		{ "UIMin", "0.000000" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSPCRJointDynamicsBody, Height), METADATA_PARAMS(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Height_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Height_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Radius_MetaData[] = {
		{ "Category", "Body" },
		{ "ClampMax", "100.000000" },
		{ "ClampMin", "0.000000" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
		{ "UIMax", "100.000000" },
		{ "UIMin", "0.000000" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSPCRJointDynamicsBody, Radius), METADATA_PARAMS(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Radius_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Radius_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Friction_MetaData[] = {
		{ "Category", "Body" },
		{ "ClampMax", "1.000000" },
		{ "ClampMin", "0.000000" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
		{ "UIMax", "1.000000" },
		{ "UIMin", "0.000000" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Friction = { "Friction", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSPCRJointDynamicsBody, Friction), METADATA_PARAMS(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Friction_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Friction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Location_MetaData[] = {
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSPCRJointDynamicsBody, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Location_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Rotation_MetaData[] = {
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSPCRJointDynamicsBody, Rotation), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Rotation_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Rotation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_SurfaceColliderType_MetaData[] = {
		{ "Category", "Body" },
		{ "EditCondition", "Height > 0.0" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
		{ "ToolTip", "Force the surface out while the collider penetrates" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_SurfaceColliderType = { "SurfaceColliderType", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSPCRJointDynamicsBody, SurfaceColliderType), Z_Construct_UEnum_SPCRJointDynamics_SurfaceColliderType, METADATA_PARAMS(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_SurfaceColliderType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_SurfaceColliderType_MetaData)) }; // 3877747647
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_TargetBone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Transform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Height,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Radius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Friction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_Rotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewProp_SurfaceColliderType,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SPCRJointDynamics,
		nullptr,
		&NewStructOps,
		"SPCRJointDynamicsBody",
		sizeof(FSPCRJointDynamicsBody),
		alignof(FSPCRJointDynamicsBody),
		Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSPCRJointDynamicsBody()
	{
		if (!Z_Registration_Info_UScriptStruct_SPCRJointDynamicsBody.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SPCRJointDynamicsBody.InnerSingleton, Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SPCRJointDynamicsBody.InnerSingleton;
	}

static_assert(std::is_polymorphic<FAnimNode_SPCRJointDynamics>() == std::is_polymorphic<FAnimNode_SkeletalControlBase>(), "USTRUCT FAnimNode_SPCRJointDynamics cannot be polymorphic unless super FAnimNode_SkeletalControlBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AnimNode_SPCRJointDynamics;
class UScriptStruct* FAnimNode_SPCRJointDynamics::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AnimNode_SPCRJointDynamics.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AnimNode_SPCRJointDynamics.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics, Z_Construct_UPackage__Script_SPCRJointDynamics(), TEXT("AnimNode_SPCRJointDynamics"));
	}
	return Z_Registration_Info_UScriptStruct_AnimNode_SPCRJointDynamics.OuterSingleton;
}
template<> SPCRJOINTDYNAMICS_API UScriptStruct* StaticStruct<FAnimNode_SPCRJointDynamics>()
{
	return FAnimNode_SPCRJointDynamics::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructPropertyParams NewProp_JointPairs_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JointPairs_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_JointPairs;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VirtualBoneLength_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VirtualBoneLength;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FixedPointIndex_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_FixedPointIndex;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Structural_Vertical_StepCount_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_Structural_Vertical_StepCount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bJointLoop_MetaData[];
#endif
		static void NewProp_bJointLoop_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bJointLoop;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bStructural_Vertical_MetaData[];
#endif
		static void NewProp_bStructural_Vertical_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bStructural_Vertical;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bStructural_Vertical_Collision_MetaData[];
#endif
		static void NewProp_bStructural_Vertical_Collision_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bStructural_Vertical_Collision;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Structural_Vertical_Shrink_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Structural_Vertical_Shrink;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Structural_Vertical_Stretch_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Structural_Vertical_Stretch;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bStructural_Horizontal_MetaData[];
#endif
		static void NewProp_bStructural_Horizontal_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bStructural_Horizontal;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bStructural_Horizontal_Collision_MetaData[];
#endif
		static void NewProp_bStructural_Horizontal_Collision_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bStructural_Horizontal_Collision;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Structural_Horizontal_Shrink_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Structural_Horizontal_Shrink;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Structural_Horizontal_Stretch_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Structural_Horizontal_Stretch;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bShear_MetaData[];
#endif
		static void NewProp_bShear_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShear;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bShear_Collision_MetaData[];
#endif
		static void NewProp_bShear_Collision_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShear_Collision;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Shear_Shrink_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Shear_Shrink;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Shear_Stretch_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Shear_Stretch;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bBending_Vertical_MetaData[];
#endif
		static void NewProp_bBending_Vertical_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bBending_Vertical;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Bending_Vertical_Shrink_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Bending_Vertical_Shrink;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Bending_Vertical_Stretch_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Bending_Vertical_Stretch;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bBending_Horizontal_MetaData[];
#endif
		static void NewProp_bBending_Horizontal_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bBending_Horizontal;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Bending_Horizontal_Shrink_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Bending_Horizontal_Shrink;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Bending_Horizontal_Stretch_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Bending_Horizontal_Stretch;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxIterations_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_MaxIterations;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CollisionLOD_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_CollisionLOD;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bForceLengthLimit_MetaData[];
#endif
		static void NewProp_bForceLengthLimit_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceLengthLimit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Resistance_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Resistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Hardness_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Hardness;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Gravity_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Gravity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GravityCurve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GravityCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseDrag_MetaData[];
#endif
		static void NewProp_bUseDrag_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseDrag;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DragCoefficient_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DragCoefficient;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DragCurve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_DragCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseLift_MetaData[];
#endif
		static void NewProp_bUseLift_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseLift;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LiftCoefficient_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_LiftCoefficient;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LiftCurve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LiftCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WindForce_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_WindForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WindForceSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_WindForceSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseSurfaceCollision_MetaData[];
#endif
		static void NewProp_bUseSurfaceCollision_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseSurfaceCollision;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WriteID_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_WriteID;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReadID_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReadID_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReadID;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Bodies_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Bodies_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Bodies;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_jointDynamicsComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_jointDynamicsComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bLimitAngle_MetaData[];
#endif
		static void NewProp_bLimitAngle_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bLimitAngle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AngleLimitInDegree_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AngleLimitInDegree;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LimitCurve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LimitCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bLimitFromRoot_MetaData[];
#endif
		static void NewProp_bLimitFromRoot_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bLimitFromRoot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDebugDrawConstraints_MetaData[];
#endif
		static void NewProp_bDebugDrawConstraints_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebugDrawConstraints;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDebugDrawColliders_MetaData[];
#endif
		static void NewProp_bDebugDrawColliders_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebugDrawColliders;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDebugDrawSurfaceCollision_MetaData[];
#endif
		static void NewProp_bDebugDrawSurfaceCollision_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebugDrawSurfaceCollision;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Comment", "//======================================================================================\n//\n//======================================================================================\n" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnimNode_SPCRJointDynamics>();
	}
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_JointPairs_Inner = { "JointPairs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UScriptStruct_FSPCRJointPair, METADATA_PARAMS(nullptr, 0) }; // 4142831242
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_JointPairs_MetaData[] = {
		{ "Category", "Dynamics" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_JointPairs = { "JointPairs", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, JointPairs), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_JointPairs_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_JointPairs_MetaData)) }; // 4142831242
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_VirtualBoneLength_MetaData[] = {
		{ "Category", "Dynamics" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_VirtualBoneLength = { "VirtualBoneLength", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, VirtualBoneLength), METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_VirtualBoneLength_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_VirtualBoneLength_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_FixedPointIndex_MetaData[] = {
		{ "Category", "Dynamics" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_FixedPointIndex = { "FixedPointIndex", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, FixedPointIndex), METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_FixedPointIndex_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_FixedPointIndex_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Vertical_StepCount_MetaData[] = {
		{ "Category", "Dynamics" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Vertical_StepCount = { "Structural_Vertical_StepCount", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, Structural_Vertical_StepCount), METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Vertical_StepCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Vertical_StepCount_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bJointLoop_MetaData[] = {
		{ "Category", "Dynamics" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bJointLoop_SetBit(void* Obj)
	{
		((FAnimNode_SPCRJointDynamics*)Obj)->bJointLoop = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bJointLoop = { "bJointLoop", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_SPCRJointDynamics), &Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bJointLoop_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bJointLoop_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bJointLoop_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Vertical_MetaData[] = {
		{ "Category", "Structural" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Vertical_SetBit(void* Obj)
	{
		((FAnimNode_SPCRJointDynamics*)Obj)->bStructural_Vertical = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Vertical = { "bStructural_Vertical", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_SPCRJointDynamics), &Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Vertical_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Vertical_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Vertical_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Vertical_Collision_MetaData[] = {
		{ "Category", "Structural" },
		{ "EditCondition", "bStructural_Vertical" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Vertical_Collision_SetBit(void* Obj)
	{
		((FAnimNode_SPCRJointDynamics*)Obj)->bStructural_Vertical_Collision = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Vertical_Collision = { "bStructural_Vertical_Collision", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_SPCRJointDynamics), &Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Vertical_Collision_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Vertical_Collision_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Vertical_Collision_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Vertical_Shrink_MetaData[] = {
		{ "Category", "Structural" },
		{ "EditCondition", "bStructural_Vertical" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Vertical_Shrink = { "Structural_Vertical_Shrink", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, Structural_Vertical_Shrink), Z_Construct_UScriptStruct_FSPCRCurve, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Vertical_Shrink_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Vertical_Shrink_MetaData)) }; // 2414792540
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Vertical_Stretch_MetaData[] = {
		{ "Category", "Structural" },
		{ "EditCondition", "bStructural_Vertical" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Vertical_Stretch = { "Structural_Vertical_Stretch", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, Structural_Vertical_Stretch), Z_Construct_UScriptStruct_FSPCRCurve, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Vertical_Stretch_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Vertical_Stretch_MetaData)) }; // 2414792540
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Horizontal_MetaData[] = {
		{ "Category", "Structural" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Horizontal_SetBit(void* Obj)
	{
		((FAnimNode_SPCRJointDynamics*)Obj)->bStructural_Horizontal = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Horizontal = { "bStructural_Horizontal", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_SPCRJointDynamics), &Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Horizontal_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Horizontal_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Horizontal_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Horizontal_Collision_MetaData[] = {
		{ "Category", "Structural" },
		{ "EditCondition", "bStructural_Horizontal" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Horizontal_Collision_SetBit(void* Obj)
	{
		((FAnimNode_SPCRJointDynamics*)Obj)->bStructural_Horizontal_Collision = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Horizontal_Collision = { "bStructural_Horizontal_Collision", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_SPCRJointDynamics), &Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Horizontal_Collision_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Horizontal_Collision_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Horizontal_Collision_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Horizontal_Shrink_MetaData[] = {
		{ "Category", "Structural" },
		{ "EditCondition", "bStructural_Horizontal" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Horizontal_Shrink = { "Structural_Horizontal_Shrink", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, Structural_Horizontal_Shrink), Z_Construct_UScriptStruct_FSPCRCurve, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Horizontal_Shrink_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Horizontal_Shrink_MetaData)) }; // 2414792540
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Horizontal_Stretch_MetaData[] = {
		{ "Category", "Structural" },
		{ "EditCondition", "bStructural_Horizontal" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Horizontal_Stretch = { "Structural_Horizontal_Stretch", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, Structural_Horizontal_Stretch), Z_Construct_UScriptStruct_FSPCRCurve, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Horizontal_Stretch_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Horizontal_Stretch_MetaData)) }; // 2414792540
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bShear_MetaData[] = {
		{ "Category", "Shear" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bShear_SetBit(void* Obj)
	{
		((FAnimNode_SPCRJointDynamics*)Obj)->bShear = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bShear = { "bShear", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_SPCRJointDynamics), &Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bShear_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bShear_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bShear_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bShear_Collision_MetaData[] = {
		{ "Category", "Shear" },
		{ "EditCondition", "bShear" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bShear_Collision_SetBit(void* Obj)
	{
		((FAnimNode_SPCRJointDynamics*)Obj)->bShear_Collision = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bShear_Collision = { "bShear_Collision", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_SPCRJointDynamics), &Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bShear_Collision_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bShear_Collision_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bShear_Collision_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Shear_Shrink_MetaData[] = {
		{ "Category", "Shear" },
		{ "EditCondition", "bShear" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Shear_Shrink = { "Shear_Shrink", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, Shear_Shrink), Z_Construct_UScriptStruct_FSPCRCurve, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Shear_Shrink_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Shear_Shrink_MetaData)) }; // 2414792540
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Shear_Stretch_MetaData[] = {
		{ "Category", "Shear" },
		{ "EditCondition", "bShear" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Shear_Stretch = { "Shear_Stretch", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, Shear_Stretch), Z_Construct_UScriptStruct_FSPCRCurve, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Shear_Stretch_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Shear_Stretch_MetaData)) }; // 2414792540
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bBending_Vertical_MetaData[] = {
		{ "Category", "Bending" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bBending_Vertical_SetBit(void* Obj)
	{
		((FAnimNode_SPCRJointDynamics*)Obj)->bBending_Vertical = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bBending_Vertical = { "bBending_Vertical", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_SPCRJointDynamics), &Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bBending_Vertical_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bBending_Vertical_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bBending_Vertical_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Vertical_Shrink_MetaData[] = {
		{ "Category", "Bending" },
		{ "EditCondition", "bBending_Vertical" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Vertical_Shrink = { "Bending_Vertical_Shrink", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, Bending_Vertical_Shrink), Z_Construct_UScriptStruct_FSPCRCurve, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Vertical_Shrink_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Vertical_Shrink_MetaData)) }; // 2414792540
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Vertical_Stretch_MetaData[] = {
		{ "Category", "Bending" },
		{ "EditCondition", "bBending_Vertical" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Vertical_Stretch = { "Bending_Vertical_Stretch", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, Bending_Vertical_Stretch), Z_Construct_UScriptStruct_FSPCRCurve, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Vertical_Stretch_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Vertical_Stretch_MetaData)) }; // 2414792540
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bBending_Horizontal_MetaData[] = {
		{ "Category", "Bending" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bBending_Horizontal_SetBit(void* Obj)
	{
		((FAnimNode_SPCRJointDynamics*)Obj)->bBending_Horizontal = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bBending_Horizontal = { "bBending_Horizontal", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_SPCRJointDynamics), &Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bBending_Horizontal_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bBending_Horizontal_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bBending_Horizontal_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Horizontal_Shrink_MetaData[] = {
		{ "Category", "Bending" },
		{ "EditCondition", "bBending_Horizontal" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Horizontal_Shrink = { "Bending_Horizontal_Shrink", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, Bending_Horizontal_Shrink), Z_Construct_UScriptStruct_FSPCRCurve, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Horizontal_Shrink_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Horizontal_Shrink_MetaData)) }; // 2414792540
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Horizontal_Stretch_MetaData[] = {
		{ "Category", "Bending" },
		{ "EditCondition", "bBending_Horizontal" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Horizontal_Stretch = { "Bending_Horizontal_Stretch", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, Bending_Horizontal_Stretch), Z_Construct_UScriptStruct_FSPCRCurve, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Horizontal_Stretch_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Horizontal_Stretch_MetaData)) }; // 2414792540
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_MaxIterations_MetaData[] = {
		{ "Category", "Parameters" },
		{ "ClampMax", "16" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
		{ "UIMax", "16" },
		{ "UIMin", "1" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_MaxIterations = { "MaxIterations", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, MaxIterations), METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_MaxIterations_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_MaxIterations_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_CollisionLOD_MetaData[] = {
		{ "Category", "Parameters" },
		{ "ClampMax", "4" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
		{ "UIMax", "4" },
		{ "UIMin", "1" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_CollisionLOD = { "CollisionLOD", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, CollisionLOD), METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_CollisionLOD_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_CollisionLOD_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bForceLengthLimit_MetaData[] = {
		{ "Category", "Parameters" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bForceLengthLimit_SetBit(void* Obj)
	{
		((FAnimNode_SPCRJointDynamics*)Obj)->bForceLengthLimit = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bForceLengthLimit = { "bForceLengthLimit", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_SPCRJointDynamics), &Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bForceLengthLimit_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bForceLengthLimit_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bForceLengthLimit_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Resistance_MetaData[] = {
		{ "Category", "Parameters" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Resistance = { "Resistance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, Resistance), Z_Construct_UScriptStruct_FSPCRCurveZero, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Resistance_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Resistance_MetaData)) }; // 3458159037
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Hardness_MetaData[] = {
		{ "Category", "Parameters" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Hardness = { "Hardness", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, Hardness), Z_Construct_UScriptStruct_FSPCRCurveZero, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Hardness_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Hardness_MetaData)) }; // 3458159037
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Gravity_MetaData[] = {
		{ "Category", "Parameters" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Gravity = { "Gravity", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, Gravity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Gravity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Gravity_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_GravityCurve_MetaData[] = {
		{ "Category", "Parameters" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_GravityCurve = { "GravityCurve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, GravityCurve), Z_Construct_UScriptStruct_FSPCRCurve, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_GravityCurve_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_GravityCurve_MetaData)) }; // 2414792540
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseDrag_MetaData[] = {
		{ "Category", "Parameters" },
		{ "Comment", "/*UPROPERTY(EditAnywhere, Category = Parameters)\n\x09""bool bUseDamping = false;\n\n\x09UPROPERTY(EditAnywhere, Category = Parameters, meta = (EditCondition = \"bUseDamping\"))\n\x09""float Damping = 0.99;\n\n\x09UPROPERTY(EditAnywhere, Category = Parameters, meta = (EditCondition = \"bUseDamping\"))\n\x09""FSPCRCurve DampingCurve;*/" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
		{ "ToolTip", "UPROPERTY(EditAnywhere, Category = Parameters)\n       bool bUseDamping = false;\n\n       UPROPERTY(EditAnywhere, Category = Parameters, meta = (EditCondition = \"bUseDamping\"))\n       float Damping = 0.99;\n\n       UPROPERTY(EditAnywhere, Category = Parameters, meta = (EditCondition = \"bUseDamping\"))\n       FSPCRCurve DampingCurve;" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseDrag_SetBit(void* Obj)
	{
		((FAnimNode_SPCRJointDynamics*)Obj)->bUseDrag = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseDrag = { "bUseDrag", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_SPCRJointDynamics), &Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseDrag_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseDrag_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseDrag_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_DragCoefficient_MetaData[] = {
		{ "Category", "Parameters" },
		{ "EditCondition", "bUseDrag" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_DragCoefficient = { "DragCoefficient", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, DragCoefficient), METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_DragCoefficient_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_DragCoefficient_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_DragCurve_MetaData[] = {
		{ "Category", "Parameters" },
		{ "EditCondition", "bUseDrag" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_DragCurve = { "DragCurve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, DragCurve), Z_Construct_UScriptStruct_FSPCRCurve, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_DragCurve_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_DragCurve_MetaData)) }; // 2414792540
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseLift_MetaData[] = {
		{ "Category", "Parameters" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseLift_SetBit(void* Obj)
	{
		((FAnimNode_SPCRJointDynamics*)Obj)->bUseLift = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseLift = { "bUseLift", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_SPCRJointDynamics), &Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseLift_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseLift_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseLift_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_LiftCoefficient_MetaData[] = {
		{ "Category", "Parameters" },
		{ "EditCondition", "bUseLift" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_LiftCoefficient = { "LiftCoefficient", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, LiftCoefficient), METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_LiftCoefficient_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_LiftCoefficient_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_LiftCurve_MetaData[] = {
		{ "Category", "Parameters" },
		{ "EditCondition", "bUseLift" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_LiftCurve = { "LiftCurve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, LiftCurve), Z_Construct_UScriptStruct_FSPCRCurve, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_LiftCurve_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_LiftCurve_MetaData)) }; // 2414792540
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_WindForce_MetaData[] = {
		{ "Category", "Parameters" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_WindForce = { "WindForce", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, WindForce), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_WindForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_WindForce_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_WindForceSpeed_MetaData[] = {
		{ "Category", "Parameters" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_WindForceSpeed = { "WindForceSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, WindForceSpeed), METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_WindForceSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_WindForceSpeed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseSurfaceCollision_MetaData[] = {
		{ "Category", "Parameters" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseSurfaceCollision_SetBit(void* Obj)
	{
		((FAnimNode_SPCRJointDynamics*)Obj)->bUseSurfaceCollision = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseSurfaceCollision = { "bUseSurfaceCollision", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_SPCRJointDynamics), &Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseSurfaceCollision_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseSurfaceCollision_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseSurfaceCollision_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_WriteID_MetaData[] = {
		{ "Category", "Colliders" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_WriteID = { "WriteID", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, WriteID), METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_WriteID_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_WriteID_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_ReadID_Inner = { "ReadID", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_ReadID_MetaData[] = {
		{ "Category", "Colliders" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_ReadID = { "ReadID", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, ReadID), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_ReadID_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_ReadID_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bodies_Inner = { "Bodies", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UScriptStruct_FSPCRJointDynamicsBody, METADATA_PARAMS(nullptr, 0) }; // 3247744667
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bodies_MetaData[] = {
		{ "Category", "Colliders" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bodies = { "Bodies", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, Bodies), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bodies_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bodies_MetaData)) }; // 3247744667
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_jointDynamicsComponent_MetaData[] = {
		{ "AlwaysAsPin", "" },
		{ "Category", "Link" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_jointDynamicsComponent = { "jointDynamicsComponent", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, jointDynamicsComponent), Z_Construct_UClass_USPCRJointDynamicsComponent_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_jointDynamicsComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_jointDynamicsComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bLimitAngle_MetaData[] = {
		{ "Category", "Limit" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bLimitAngle_SetBit(void* Obj)
	{
		((FAnimNode_SPCRJointDynamics*)Obj)->bLimitAngle = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bLimitAngle = { "bLimitAngle", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_SPCRJointDynamics), &Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bLimitAngle_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bLimitAngle_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bLimitAngle_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_AngleLimitInDegree_MetaData[] = {
		{ "Category", "Limit" },
		{ "ClampMax", "180" },
		{ "ClampMin", "0" },
		{ "EditCondition", "bLimitAngle" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_AngleLimitInDegree = { "AngleLimitInDegree", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, AngleLimitInDegree), METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_AngleLimitInDegree_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_AngleLimitInDegree_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_LimitCurve_MetaData[] = {
		{ "Category", "Limit" },
		{ "EditCondition", "bLimitAngle" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_LimitCurve = { "LimitCurve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_SPCRJointDynamics, LimitCurve), Z_Construct_UScriptStruct_FSPCRCurve, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_LimitCurve_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_LimitCurve_MetaData)) }; // 2414792540
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bLimitFromRoot_MetaData[] = {
		{ "Category", "Limit" },
		{ "EditCondition", "bLimitAngle" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bLimitFromRoot_SetBit(void* Obj)
	{
		((FAnimNode_SPCRJointDynamics*)Obj)->bLimitFromRoot = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bLimitFromRoot = { "bLimitFromRoot", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_SPCRJointDynamics), &Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bLimitFromRoot_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bLimitFromRoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bLimitFromRoot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawConstraints_MetaData[] = {
		{ "Category", "Debug_Draw" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawConstraints_SetBit(void* Obj)
	{
		((FAnimNode_SPCRJointDynamics*)Obj)->bDebugDrawConstraints = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawConstraints = { "bDebugDrawConstraints", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_SPCRJointDynamics), &Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawConstraints_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawConstraints_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawConstraints_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawColliders_MetaData[] = {
		{ "Category", "Debug_Draw" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawColliders_SetBit(void* Obj)
	{
		((FAnimNode_SPCRJointDynamics*)Obj)->bDebugDrawColliders = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawColliders = { "bDebugDrawColliders", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_SPCRJointDynamics), &Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawColliders_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawColliders_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawColliders_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawSurfaceCollision_MetaData[] = {
		{ "Category", "Debug_Draw" },
		{ "ModuleRelativePath", "Public/AnimNode_SPCRJointDynamics.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawSurfaceCollision_SetBit(void* Obj)
	{
		((FAnimNode_SPCRJointDynamics*)Obj)->bDebugDrawSurfaceCollision = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawSurfaceCollision = { "bDebugDrawSurfaceCollision", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_SPCRJointDynamics), &Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawSurfaceCollision_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawSurfaceCollision_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawSurfaceCollision_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_JointPairs_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_JointPairs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_VirtualBoneLength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_FixedPointIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Vertical_StepCount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bJointLoop,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Vertical,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Vertical_Collision,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Vertical_Shrink,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Vertical_Stretch,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Horizontal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bStructural_Horizontal_Collision,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Horizontal_Shrink,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Structural_Horizontal_Stretch,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bShear,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bShear_Collision,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Shear_Shrink,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Shear_Stretch,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bBending_Vertical,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Vertical_Shrink,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Vertical_Stretch,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bBending_Horizontal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Horizontal_Shrink,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bending_Horizontal_Stretch,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_MaxIterations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_CollisionLOD,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bForceLengthLimit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Resistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Hardness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Gravity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_GravityCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseDrag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_DragCoefficient,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_DragCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseLift,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_LiftCoefficient,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_LiftCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_WindForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_WindForceSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bUseSurfaceCollision,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_WriteID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_ReadID_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_ReadID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bodies_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_Bodies,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_jointDynamicsComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bLimitAngle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_AngleLimitInDegree,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_LimitCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bLimitFromRoot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawConstraints,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawColliders,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewProp_bDebugDrawSurfaceCollision,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SPCRJointDynamics,
		Z_Construct_UScriptStruct_FAnimNode_SkeletalControlBase,
		&NewStructOps,
		"AnimNode_SPCRJointDynamics",
		sizeof(FAnimNode_SPCRJointDynamics),
		alignof(FAnimNode_SPCRJointDynamics),
		Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000205),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics()
	{
		if (!Z_Registration_Info_UScriptStruct_AnimNode_SPCRJointDynamics.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AnimNode_SPCRJointDynamics.InnerSingleton, Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AnimNode_SPCRJointDynamics.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_AnimNode_SPCRJointDynamics_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_AnimNode_SPCRJointDynamics_h_Statics::EnumInfo[] = {
		{ SurfaceColliderType_StaticEnum, TEXT("SurfaceColliderType"), &Z_Registration_Info_UEnum_SurfaceColliderType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3877747647U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_AnimNode_SPCRJointDynamics_h_Statics::ScriptStructInfo[] = {
		{ FSPCRCollider::StaticStruct, Z_Construct_UScriptStruct_FSPCRCollider_Statics::NewStructOps, TEXT("SPCRCollider"), &Z_Registration_Info_UScriptStruct_SPCRCollider, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSPCRCollider), 1429554848U) },
		{ FSPCRJointPair::StaticStruct, Z_Construct_UScriptStruct_FSPCRJointPair_Statics::NewStructOps, TEXT("SPCRJointPair"), &Z_Registration_Info_UScriptStruct_SPCRJointPair, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSPCRJointPair), 4142831242U) },
		{ FSPCRCurve::StaticStruct, Z_Construct_UScriptStruct_FSPCRCurve_Statics::NewStructOps, TEXT("SPCRCurve"), &Z_Registration_Info_UScriptStruct_SPCRCurve, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSPCRCurve), 2414792540U) },
		{ FSPCRCurveZero::StaticStruct, Z_Construct_UScriptStruct_FSPCRCurveZero_Statics::NewStructOps, TEXT("SPCRCurveZero"), &Z_Registration_Info_UScriptStruct_SPCRCurveZero, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSPCRCurveZero), 3458159037U) },
		{ FSPCRJointDynamicsBody::StaticStruct, Z_Construct_UScriptStruct_FSPCRJointDynamicsBody_Statics::NewStructOps, TEXT("SPCRJointDynamicsBody"), &Z_Registration_Info_UScriptStruct_SPCRJointDynamicsBody, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSPCRJointDynamicsBody), 3247744667U) },
		{ FAnimNode_SPCRJointDynamics::StaticStruct, Z_Construct_UScriptStruct_FAnimNode_SPCRJointDynamics_Statics::NewStructOps, TEXT("AnimNode_SPCRJointDynamics"), &Z_Registration_Info_UScriptStruct_AnimNode_SPCRJointDynamics, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAnimNode_SPCRJointDynamics), 3276718777U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_AnimNode_SPCRJointDynamics_h_632772260(TEXT("/Script/SPCRJointDynamics"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_AnimNode_SPCRJointDynamics_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_AnimNode_SPCRJointDynamics_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_AnimNode_SPCRJointDynamics_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_SPCRJointDynamicsUE4_MyProject_Plugins_SPCRJointDynamics_Source_SPCRJointDynamics_Public_AnimNode_SPCRJointDynamics_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
