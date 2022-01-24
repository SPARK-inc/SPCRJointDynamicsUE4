//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#pragma once

//======================================================================================
//
//======================================================================================
#include "CoreMinimal.h"
#include "Animation/AnimNodeBase.h"
#include "BoneContainer.h"
#include "BonePose.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "SPCRJointDynamicsComponent.h"
#include "Curves/CurveFloat.h"

#include "AnimNode_SPCRJointDynamics.generated.h"

//======================================================================================
//
//======================================================================================

#define SPCR_COLLIDER_SCALE_FACTOR 100

USTRUCT(BlueprintType)
struct SPCRJOINTDYNAMICS_API FSPCRCollider
{
	GENERATED_USTRUCT_BODY()

	bool bCapsule;
	float Radius;
	float Height;
	float Friction;
	FVector Position;
	FVector Direction;
	int8 SurfaceColliderType;
};

USTRUCT()
struct SPCRJOINTDYNAMICS_API FSPCRJointPair
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = Solver)
	FBoneReference RootBone;

	UPROPERTY(EditAnywhere, Category = Solver)
	FBoneReference EndBone;
};

USTRUCT()
struct SPCRJOINTDYNAMICS_API FSPCRCurve
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = Curve)
	class UCurveFloat* Curve;

	UPROPERTY(EditAnywhere, Category = Curve)
	float Power = 1.0f;

	float ComputeCurve(float Rate)
	{
		if (Curve != nullptr)
			return Curve->GetFloatValue(Rate) * Power;
		return Power;
	}
};

USTRUCT()
struct SPCRJOINTDYNAMICS_API FSPCRCurveZero
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = Curve)
	class UCurveFloat* Curve;

	UPROPERTY(EditAnywhere, Category = Curve)
	float Power = 0.0f;

	float ComputeCurve(float Rate)
	{
		if (Curve != nullptr)
			return Curve->GetFloatValue(Rate) * Power;
		return Power;
	}
};

UENUM()
enum SurfaceColliderType
{
	OFF,
	PUSH,
	PULL,
};

USTRUCT()
struct SPCRJOINTDYNAMICS_API FSPCRJointDynamicsBody
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = Body)
	FBoneReference TargetBone;

	UPROPERTY(EditAnywhere, Category = Body)
	FTransform Transform = FTransform::Identity;

	UPROPERTY(EditAnywhere, Category = Body, meta = (UIMin = 0.0f, ClampMin = 0.0f, UIMax = 50.0f, ClampMax = 50.0f))
	float Height = 0.0f;

	UPROPERTY(EditAnywhere, Category = Body, meta = (UIMin = 0.0f, ClampMin = 0.0f, UIMax = 100.0f, ClampMax = 100.0f))
	float Radius = 1.0f;
		
	UPROPERTY(EditAnywhere, Category = Body, meta = (UIMin = 0.0f, ClampMin = 0.0f, UIMax = 1.0f, ClampMax = 1.0f))
	float Friction = 0.1f;

	UPROPERTY()
	FVector Location;

	UPROPERTY()
	FQuat Rotation;

	UPROPERTY(EditAnywhere, Category = Body, meta = (EditCondition = "Height > 0.0", ToolTip = "Force the surface out while the collider penetrates"))
	TEnumAsByte<SurfaceColliderType> SurfaceColliderType = SurfaceColliderType::OFF;

	float GetRadius() const
	{
		return Radius;// *SPCR_COLLIDER_SCALE_FACTOR;
	}
};

//======================================================================================
//
//======================================================================================
struct SPCRPoint
{
	FCompactPoseBoneIndex BoneIndex;
	FCompactPoseBoneIndex ParentBoneIndex;
	FTransform Transform;
	SPCRPoint* pChild;
	SPCRPoint* pParent;

	FVector CSPosition;
	FVector CSBoneDirection;
	FVector Position;
	FVector PositionPrev;
	FVector InitialWorldPosition;
	float OrderRate;
	float Weight;
	float Resistance;
	float Gravity;
	float Friction;
	float Hardness;
	float LimitStrength;

	bool bVirtual;

	SPCRPoint()
		: BoneIndex(INDEX_NONE)
		, ParentBoneIndex(INDEX_NONE)
		, pChild(nullptr)
		, pParent(nullptr)
		, OrderRate(1.0f)
		, Weight(1.0f)
		, Resistance(1.0f)
		, Gravity(1.0f)
		, Friction(0.0f)
		, Hardness(0.0f)
		, LimitStrength(0.0f)
		, bVirtual(false)
	{
	}
};

struct SPCRConstraint
{
	enum eType
	{
		Structural_Vertical,
		Structural_Horizontal,
		Shear,
		Bending_Vertical,
		Bending_Horizontal,
	};

	eType Type;
	SPCRPoint* pPointA;
	SPCRPoint* pPointB;
	float Length;
	bool IsCollision;

	SPCRConstraint(eType InType, SPCRPoint* pInPointA, SPCRPoint* pInPointB, bool InIsCollision)
		: Type(InType)
		, pPointA(pInPointA)
		, pPointB(pInPointB)
		, Length((pPointA->Position - pPointB->Position).Size())
		, IsCollision(InIsCollision)
	{
	}
};

struct SPCRColliderInfo
{
	FBoneReference TargetBone;
	FTransform LocalTransform;
	float Radius;
	float Height;

	SPCRColliderInfo()
	{
	}
};

struct SPCRSurfaceConstraint
{
	SPCRPoint* PointA;
	SPCRPoint* PointB;
	SPCRPoint* PointC;
	SPCRPoint* PointD;

	SPCRSurfaceConstraint(SPCRPoint* PointA, SPCRPoint* PointB, SPCRPoint* PointC, SPCRPoint* PointD)
		: PointA(PointA)
		, PointB(PointB)
		, PointC(PointC)
		, PointD(PointD)
	{
	}
};

//======================================================================================
//
//======================================================================================
USTRUCT(BlueprintInternalUseOnly)
struct SPCRJOINTDYNAMICS_API FAnimNode_SPCRJointDynamics : public FAnimNode_SkeletalControlBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = Dynamics)
	TArray<FSPCRJointPair> JointPairs;

	UPROPERTY(EditAnywhere, Category = Dynamics)
	float VirtualBoneLength = 0.0f;

	UPROPERTY(EditAnywhere, Category = Dynamics)
	int FixedPointIndex = 0;

	UPROPERTY(EditAnywhere, Category = Dynamics)
	int Structural_Vertical_StepCount = 1;

	UPROPERTY(EditAnywhere, Category = Dynamics)
	bool bJointLoop = false;

	UPROPERTY(EditAnywhere, Category = Structural)
	bool bStructural_Vertical = true;
	UPROPERTY(EditAnywhere, Category = Structural, meta = (EditCondition = bStructural_Vertical))
	bool bStructural_Vertical_Collision = true;
	UPROPERTY(EditAnywhere, Category = Structural, meta = (EditCondition = bStructural_Vertical))
	FSPCRCurve Structural_Vertical_Shrink;
	UPROPERTY(EditAnywhere, Category = Structural, meta = (EditCondition = bStructural_Vertical))
	FSPCRCurve Structural_Vertical_Stretch;

	UPROPERTY(EditAnywhere, Category = Structural)
	bool bStructural_Horizontal = false;
	UPROPERTY(EditAnywhere, Category = Structural, meta = (EditCondition = bStructural_Horizontal))
	bool bStructural_Horizontal_Collision = false;
	UPROPERTY(EditAnywhere, Category = Structural, meta = (EditCondition = bStructural_Horizontal))
	FSPCRCurve Structural_Horizontal_Shrink;
	UPROPERTY(EditAnywhere, Category = Structural, meta = (EditCondition = bStructural_Horizontal))
	FSPCRCurve Structural_Horizontal_Stretch;

	UPROPERTY(EditAnywhere, Category = Shear)
	bool bShear = false;
	UPROPERTY(EditAnywhere, Category = Shear, meta = (EditCondition = bShear))
	bool bShear_Collision = false;
	UPROPERTY(EditAnywhere, Category = Shear, meta = (EditCondition = bShear))
	FSPCRCurve Shear_Shrink;
	UPROPERTY(EditAnywhere, Category = Shear, meta = (EditCondition = bShear))
	FSPCRCurve Shear_Stretch;

	UPROPERTY(EditAnywhere, Category = Bending)
	bool bBending_Vertical = false;
	UPROPERTY(EditAnywhere, Category = Bending, meta = (EditCondition = bBending_Vertical))
	FSPCRCurve Bending_Vertical_Shrink;
	UPROPERTY(EditAnywhere, Category = Bending, meta = (EditCondition = bBending_Vertical))
	FSPCRCurve Bending_Vertical_Stretch;

	UPROPERTY(EditAnywhere, Category = Bending)
	bool bBending_Horizontal = false;
	UPROPERTY(EditAnywhere, Category = Bending, meta = (EditCondition = bBending_Horizontal))
	FSPCRCurve Bending_Horizontal_Shrink;
	UPROPERTY(EditAnywhere, Category = Bending, meta = (EditCondition = bBending_Horizontal))
	FSPCRCurve Bending_Horizontal_Stretch;

	UPROPERTY(EditAnywhere, Category = Parameters, meta = (ClampMin = "1", ClampMax = "16", UIMin = "1", UIMax = "16"))
	int32 MaxIterations = 1;

	UPROPERTY(EditAnywhere, Category = Parameters, meta = (ClampMin = "1", ClampMax = "4", UIMin = "1", UIMax = "4"))
	int32 CollisionLOD = 2;

	UPROPERTY(EditAnywhere, Category = Parameters)
	bool bForceLengthLimit = false;

	UPROPERTY(EditAnywhere, Category = Parameters)
	FSPCRCurveZero Resistance;

	UPROPERTY(EditAnywhere, Category = Parameters)
	FSPCRCurveZero Hardness;

	UPROPERTY(EditAnywhere, Category = Parameters)
	FVector Gravity = FVector(0.0f, 0.0f, -980.0f);

	UPROPERTY(EditAnywhere, Category = Parameters)
	FSPCRCurve GravityCurve;
	
	UPROPERTY(EditAnywhere, Category = Parameters)
	FVector WindForce = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, Category = Parameters)
	float WindForceSpeed = 1.0f;

	UPROPERTY(EditAnywhere, Category = Parameters)
	bool bUseSurfaceCollision;

	UPROPERTY(EditAnywhere, Category = Colliders)
	int32 WriteID = 0.0f;

	UPROPERTY(EditAnywhere, Category = Colliders)
	TArray<int32> ReadID;

	UPROPERTY(EditAnywhere, Category = Colliders)
	TArray<FSPCRJointDynamicsBody> Bodies;

	UPROPERTY(EditAnywhere, Category = Link, meta = (AlwaysAsPin))
	USPCRJointDynamicsComponent* jointDynamicsComponent;

	UPROPERTY(EditAnywhere, Category = Limit)
	bool bLimitAngle = false;

	UPROPERTY(EditAnywhere, Category = Limit, meta = (EditCondition = bLimitAngle, ClampMin = 0, ClampMax = 180))
	float AngleLimitInDegree = 0.0f;

	UPROPERTY(EditAnywhere, Category = Limit, meta = (EditCondition = bLimitAngle))
	FSPCRCurve LimitCurve;

	UPROPERTY(EditAnywhere, Category = Limit, meta = (EditCondition = bLimitAngle))
	bool bLimitFromRoot = false;

	UPROPERTY(EditAnywhere, Category = Debug_Draw)
	bool bDebugDrawConstraints = false;

	UPROPERTY(EditAnywhere, Category = Debug_Draw)
	bool bDebugDrawColliders = false;

	UPROPERTY(EditAnywhere, Category = Debug_Draw)
	bool bDebugDrawSurfaceCollision;

private:
	bool							_bRequireResetPose = true;
	float							_ResetDelay = 0.5f;
	float							_DeltaTime;
	float							_RestDeltaTime;
	float							_WindForceRadians;
	TArray<TArray<SPCRPoint>>		_PointsTbl;
	TArray<SPCRConstraint>			_Constraints;
	TArray<SPCRPoint*>				_PointAccessTbl;
	TArray<SPCRColliderInfo>		_ColliderInfos;
	TArray<FSPCRCollider>			_Colliders;
	TArray<FSPCRCollider>			_ExternalColliders;
	TArray<SPCRSurfaceConstraint>	_SurfaceConstraints;

private:
	static TMap<int32, TArray<FSPCRCollider>> _GlobalColliders;
	static FCriticalSection _GlobalCollidersLock;

public:
	static void SetGlobalColliders(int32 Guid, const TArray<FSPCRCollider>& Colliders);
	static void GetGlobalColliders(int32 Guid, TArray<FSPCRCollider>& Output);

public:
	FAnimNode_SPCRJointDynamics();

	// FAnimNode_Base interface
	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
	virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) override;
	virtual bool NeedsDynamicReset() const override { return true; }
	virtual void ResetDynamics(ETeleportType InTeleportType) override;
	virtual void UpdateInternal(const FAnimationUpdateContext& Context) override;
	virtual void GatherDebugData(FNodeDebugData& DebugData) override;
	// End of FAnimNode_Base interface

	// FAnimNode_SkeletalControlBase interface
	virtual void EvaluateSkeletalControl_AnyThread(FComponentSpacePoseContext& Output, TArray<FBoneTransform>& OutBoneTransforms) override;
	virtual bool IsValidToEvaluate(const USkeleton* Skeleton, const FBoneContainer& RequiredBones) override;
	// End of FAnimNode_SkeletalControlBase interface

private:
	// FAnimNode_SkeletalControlBase interface
	virtual void InitializeBoneReferences(const FBoneContainer& RequiredBones) override;
	// End of FAnimNode_SkeletalControlBase interface

	bool RequireResetCheck(FComponentSpacePoseContext& Output);
	void OnResetAll(FComponentSpacePoseContext& Output);

	void PushoutFromSphere(const FVector& Center, float Radius, FVector& Point);
	void PushoutFromSphere(const FSPCRCollider& Collider, FVector& Point);
	void PushoutFromCapsule(const FSPCRCollider& Collider, FVector& Point);
	void PushoutFromCollider(const FSPCRCollider& Collider, FVector& Point);

	bool CollisionDetection(const FSPCRCollider& Collider, const FVector& point1, const FVector& point2, FVector& pointOnLine, FVector& pointOnCollider, float& Radius);
	float ComputeNearestPoints(FVector posP, FVector dirP, FVector posQ, FVector dirQ, float& tP, float& tQ, FVector& pointOnP, FVector& pointOnQ);

	void CreateControlPoints(FComponentSpacePoseContext& Output);
	void UpdateControlPoints(FComponentSpacePoseContext& Output, const FVector& Wind, float DeltaTime);

	void CreateColliders();
	void UpdateColliders(FComponentSpacePoseContext& Output);

	void CreateConstraints();
	void UpdateConstraints();
	void UpdateCollision();
	void ForceFixConstraints();
	void UpdateSurfaceCollision();

	void CreateSurfaceConstraints();
	void Debug_DrawSurfaceTriangle(FVector a, FVector b, FVector c);

	void HandleDebugDraw();
	void DebugDrawConstraints();
	void DebugDrawColliders();
	void DebugDrawSurfaceCollision();

	void ApplyToBone(FComponentSpacePoseContext& Output, TArray<FBoneTransform>& OutBoneTransforms);

	void CreateConstraintStructuralVertical(TArray<SPCRConstraint>& Out, TArray<TArray<SPCRPoint>>& PointsTbl, bool IsCollision);
	void CreateConstraintStructuralHorizontal(TArray<SPCRConstraint>& Out, TArray<TArray<SPCRPoint>>& PointsTbl, bool IsCollision);
	void CreateConstraintBendingVertical(TArray<SPCRConstraint>& Out, TArray<TArray<SPCRPoint>>& PointsTbl, bool IsCollision);
	void CreateConstraintBendingHorizontal(TArray<SPCRConstraint>& Out, TArray<TArray<SPCRPoint>>& PointsTbl, bool IsCollision);
	void CreateConstraintShear(TArray<SPCRConstraint>& Out, TArray<TArray<SPCRPoint>>& PointsTbl, bool IsCollision);

	void LockAngles(SPCRPoint* spcrPoint);

public:

	TArray<FSPCRCollider> GetColliderArray() const { return _Colliders; }
	TArray<SPCRColliderInfo> GetColliderInfoArray() const { return _ColliderInfos; }
	void SyncColliderPositions();

#if WITH_EDITOR
	const TArray<TArray<SPCRPoint>>& GetPoints() const { return _PointsTbl; }
	const bool IsDebugDraw() const { return bDebugDrawConstraints; }
	const TArray<SPCRConstraint>& GetConstraints() const { return _Constraints; }
	const bool IsDebugDrawCollider() const { return bDebugDrawColliders; }
	const TArray<FSPCRCollider>& GetColliders() const { return _Colliders; }
	const bool IsDebugDrawSurfaceCollision() const { return bDebugDrawSurfaceCollision; }
	const TArray<SPCRSurfaceConstraint>& GetSurfaceConstraints() const { return _SurfaceConstraints; }
#endif//WITH_EDITOR
};

//======================================================================================
// EOF
//======================================================================================
