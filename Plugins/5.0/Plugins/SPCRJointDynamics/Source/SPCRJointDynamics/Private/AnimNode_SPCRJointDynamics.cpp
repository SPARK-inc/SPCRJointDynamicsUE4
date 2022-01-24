//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#include "AnimNode_SPCRJointDynamics.h"
#include "Animation/AnimInstanceProxy.h"
#include "Animation/AnimTypes.h"
#include "AnimationRuntime.h"
#include "DrawDebugHelpers.h"
#include "Engine.h"

static const float SPCR_EPSILON = 0.0001f;

/////////////////////////////////////////////////////
// FAnimNode_SPCRJointDynamics

DECLARE_CYCLE_STAT(TEXT("SPCR JointDynamics"), STAT_SPCRJointDynamics_Eval, STATGROUP_Anim);

FAnimNode_SPCRJointDynamics::FAnimNode_SPCRJointDynamics()
{
	_bRequireResetPose = true;
	_ResetDelay = 0.3f;
	_DeltaTime = 0.0f;
	_WindForceRadians = 0.0f;

	_PointsTbl.Empty();
	_Constraints.Empty();
	_PointAccessTbl.Empty();
	_ColliderInfos.Empty();
	_Colliders.Empty();
	_SurfaceConstraints.Empty();
}

bool FAnimNode_SPCRJointDynamics::RequireResetCheck(FComponentSpacePoseContext& Output)
{
	if ((jointDynamicsComponent != nullptr) && jointDynamicsComponent->isReset)
	{
		// リセット処理を行う
		_bRequireResetPose = true;
		_ResetDelay = 0.0f;
		_DeltaTime = 0.0f;

		// リセットを行ったことを通知
		jointDynamicsComponent->OnFinishReset();
	}

	if (_bRequireResetPose)
	{
		// リセット時間経過
		_ResetDelay -= _DeltaTime;
		if (_ResetDelay > 0.0f)
		{
			return true;
		}
		// リセット処理
		else
		{
			_bRequireResetPose = false;
			OnResetAll(Output);
		}
	}

	return false;
}

void FAnimNode_SPCRJointDynamics::OnResetAll(FComponentSpacePoseContext& Output)
{
	// 初期化
	_PointsTbl.Empty();
	_PointAccessTbl.Empty();
	_Constraints.Empty();
	_SurfaceConstraints.Empty();

	// 制御点の生成
	CreateControlPoints(Output);

	// 拘束を作る
	CreateConstraints();

	// コリジョン
	CreateColliders();

	//表面コリジョン
	CreateSurfaceConstraints();
}

void FAnimNode_SPCRJointDynamics::EvaluateSkeletalControl_AnyThread(FComponentSpacePoseContext& Output, TArray<FBoneTransform>& OutBoneTransforms)
{
	// 制御点と拘束の更新
	if (RequireResetCheck(Output))
	{
		return;
	}

	// コリジョン
	UpdateColliders(Output);

	// 全制御点の更新
	_RestDeltaTime += _DeltaTime;
	_DeltaTime = 0.0f;

	static const int SIMULATION_FPS = 120;
	static const float ONE_STEP_DELTA = 1.0f / (float)SIMULATION_FPS;
	int LoopCount = (int)(_RestDeltaTime / ONE_STEP_DELTA);

	for (int i = LoopCount - 1; i >= 0; --i)
	{
		_RestDeltaTime -= ONE_STEP_DELTA;

		// 風
		FVector ActiveWindForce = FVector::ZeroVector;
		if (WindForceSpeed > 0.0f)
		{
			_WindForceRadians += ONE_STEP_DELTA * WindForceSpeed;
			while (_WindForceRadians > +3.141592f) _WindForceRadians -= 3.141592f * 2.0f;
			while (_WindForceRadians < -3.141592f) _WindForceRadians += 3.141592f * 2.0f;
			ActiveWindForce = WindForce * (FMath::Sin(_WindForceRadians) * 0.5f + 0.5f);
		}
		UpdateControlPoints(Output, ActiveWindForce, ONE_STEP_DELTA);

		// 拘束の更新
		for (int32 iRelax = MaxIterations - 1; iRelax >= 0; --iRelax)
		{
			UpdateConstraints();
		}

		// コリジョン
		if ((i % CollisionLOD) == 0)
		{
			UpdateCollision();

			if (bUseSurfaceCollision)
			{
				UpdateSurfaceCollision();
			}
		}
	}

	// 絶対長さが伸びるのは許さない
	if (bForceLengthLimit)
	{
		ForceFixConstraints();
	}

	// 骨のトランスフォームに適用
	ApplyToBone(Output, OutBoneTransforms);

	HandleDebugDraw();
}

bool FAnimNode_SPCRJointDynamics::IsValidToEvaluate(const USkeleton* Skeleton, const FBoneContainer& RequiredBones)
{
	for (auto&& Pair : JointPairs)
	{
		if (!Pair.RootBone.IsValidToEvaluate(RequiredBones)) return false;
		if (!Pair.EndBone.IsValidToEvaluate(RequiredBones)) return false;
		if (!RequiredBones.BoneIsChildOf(Pair.EndBone.BoneIndex, Pair.RootBone.BoneIndex)) return false;
	}
	return true;
}

void FAnimNode_SPCRJointDynamics::InitializeBoneReferences(const FBoneContainer& RequiredBones)
{
	for (auto&& Pair : JointPairs)
	{
		Pair.RootBone.Initialize(RequiredBones);
		Pair.EndBone.Initialize(RequiredBones);
	}
	for (auto&& Body : Bodies)
	{
		Body.TargetBone.Initialize(RequiredBones);
	}
}

void FAnimNode_SPCRJointDynamics::Initialize_AnyThread(const FAnimationInitializeContext& Context)
{
	FAnimNode_SkeletalControlBase::Initialize_AnyThread(Context);

	_bRequireResetPose = true;
	_ResetDelay = 0.3f;
	_DeltaTime = 0.0f;
	_RestDeltaTime = 0.0f;
	_WindForceRadians = 0.0f;

	_PointsTbl.Empty();
	_Constraints.Empty();
	_PointAccessTbl.Empty();
	_ColliderInfos.Empty();
	_Colliders.Empty();
	_SurfaceConstraints.Empty();
}

void FAnimNode_SPCRJointDynamics::CacheBones_AnyThread(const FAnimationCacheBonesContext& Context)
{
	FAnimNode_SkeletalControlBase::CacheBones_AnyThread(Context);
}

void FAnimNode_SPCRJointDynamics::ResetDynamics(ETeleportType InTeleportType)
{
	Super::ResetDynamics(InTeleportType);

	_bRequireResetPose = true;
	_ResetDelay = 0.3f;
	_DeltaTime = 0.0f;
	_RestDeltaTime = 0.0f;
}

void FAnimNode_SPCRJointDynamics::UpdateInternal(const FAnimationUpdateContext& Context)
{
	FAnimNode_SkeletalControlBase::UpdateInternal(Context);

	_DeltaTime = Context.GetDeltaTime();
}

void FAnimNode_SPCRJointDynamics::GatherDebugData(FNodeDebugData& DebugData)
{
	FString DebugLine = DebugData.GetNodeName(this);

	DebugData.AddDebugItem(DebugLine);
	ComponentPose.GatherDebugData(DebugData);
}

void FAnimNode_SPCRJointDynamics::UpdateColliders(FComponentSpacePoseContext& Output)
{
	auto UpdateSphereTransform = [](
		FSPCRCollider& Target,
		const FVector& Base,
		const FVector& X, const FVector& Y, const FVector& Z,
		float Radius)
	{
		const auto Origin = Base;
		const auto XAxis = X.GetSafeNormal();
		const auto YAxis = Y.GetSafeNormal();
		const auto ZAxis = Z.GetSafeNormal();

		const auto XScale = X.Size();
		const auto YScale = Y.Size();
		const auto ZScale = Z.Size();
		const auto SphereRadius = Radius * FMath::Max(XScale, FMath::Max(YScale, ZScale));
		Target.Radius = SphereRadius;
		Target.Height = 0.0f;
		Target.Position = Origin;
	};

	auto UpdateCapsuleTransform = [](
		FSPCRCollider& Target,
		const FVector& Base,
		const FVector& X, const FVector& Y, const FVector& Z,
		float Radius, float HalfHeight)
	{
		const auto Origin = Base;
		const auto XAxis = X.GetSafeNormal();
		const auto YAxis = Y.GetSafeNormal();
		const auto ZAxis = Z.GetSafeNormal();

		const auto XScale = X.Size();
		const auto YScale = Y.Size();
		const auto ZScale = Z.Size();
		const auto CapsuleRadius = Radius * FMath::Max(XScale, YScale);
		HalfHeight *= ZScale;

		const auto TopEnd = Origin + (HalfHeight * ZAxis);
		const auto BottomEnd = Origin - (HalfHeight * ZAxis);

		Target.Radius = CapsuleRadius;
		Target.Height = HalfHeight * 2.0f;
		Target.Position = BottomEnd;
		Target.Direction = TopEnd - BottomEnd;
	};

	const auto& Pose = Output.Pose.GetPose();
	const auto& BoneContainer = Pose.GetBoneContainer();

	const int32 ColliderInfosNum = _ColliderInfos.Num();
	for (int32 i = 0; i < ColliderInfosNum; ++i)
	{
		auto& Info = _ColliderInfos[i];
		const FCompactPoseBoneIndex BoneIndex = Info.TargetBone.GetCompactPoseIndex(BoneContainer);
		if (BoneIndex == -1) continue;

		const auto& BoneCSTransform = Output.Pose.GetComponentSpaceTransform(BoneIndex);
		const auto BoneTransformInWorldSpace = BoneCSTransform * Output.AnimInstanceProxy->GetComponentTransform();
		const auto ColliderTransformInWorldSpace = Info.LocalTransform * BoneTransformInWorldSpace;

		_Colliders[i].bCapsule = Info.Height > SPCR_EPSILON;

		if (_Colliders[i].bCapsule)
		{
			UpdateCapsuleTransform(
				_Colliders[i],
				ColliderTransformInWorldSpace.GetLocation(),
				ColliderTransformInWorldSpace.GetScaledAxis(EAxis::X),
				ColliderTransformInWorldSpace.GetScaledAxis(EAxis::Y),
				ColliderTransformInWorldSpace.GetScaledAxis(EAxis::Z),
				Info.Radius,
				Info.Height * 0.5f);

			if (bDebugDrawColliders && GWorld->IsPlayInEditor())
			{
				DrawDebugCapsule(
					GWorld,
					ColliderTransformInWorldSpace.GetLocation(),
					_Colliders[i].Height * 0.5f + _Colliders[i].Radius,
					_Colliders[i].Radius,
					ColliderTransformInWorldSpace.GetRotation(),
					FColor::Red);
			}
		}
		else
		{
			UpdateSphereTransform(
				_Colliders[i],
				ColliderTransformInWorldSpace.GetLocation(),
				ColliderTransformInWorldSpace.GetScaledAxis(EAxis::X),
				ColliderTransformInWorldSpace.GetScaledAxis(EAxis::Y),
				ColliderTransformInWorldSpace.GetScaledAxis(EAxis::Z),
				Info.Radius);

			if (bDebugDrawColliders && GWorld->IsPlayInEditor())
			{
				DrawDebugSphere(
					GWorld,
					_Colliders[i].Position,
					_Colliders[i].Radius,
					16,
					FColor::Red);
			}
		}
	}

	if (WriteID != 0)
	{
		SetGlobalColliders(WriteID, _Colliders);
	}
}

void FAnimNode_SPCRJointDynamics::UpdateControlPoints(FComponentSpacePoseContext& Output, const FVector& Wind, float DeltaTime)
{
	const auto& ToWorld = Output.AnimInstanceProxy->GetComponentTransform();
	const int32 PointTblNum = _PointsTbl.Num();
	const float StepTime_x2_Half = DeltaTime * DeltaTime * 0.5f;

	for (auto&& Points : _PointsTbl)
	{
		int32 iPoint = 0;

		// 先端制御点の更新（骨に忠実）
		while (iPoint <= FixedPointIndex)
		{
			auto& Point = Points[iPoint];

			const auto& BoneCSTransform = Output.Pose.GetComponentSpaceTransform(Point.BoneIndex);
			auto BoneTransformInWorldSpace = BoneCSTransform * ToWorld;

			Point.Position = BoneTransformInWorldSpace.GetLocation();
			Point.PositionPrev = Point.Position;

			++iPoint;
		}

		// 先端以外の制御点の移動更新
		const int32 PointNum = Points.Num();
		while (iPoint < PointNum)
		{
			auto& Point = Points[iPoint];

			FVector Displacement;
			Displacement  = Gravity * Point.Gravity;
			Displacement += Wind;
			Displacement *= StepTime_x2_Half;
			Displacement += Point.Position - Point.PositionPrev;
			Displacement *= Point.Resistance;
			Displacement *= 1.0f - FMath::Clamp(Point.Friction, 0.0f, 1.0f);

			Point.PositionPrev = Point.Position;
			Point.Position += Displacement;
			Point.Friction = 0.0f;

			if (Point.Hardness > 0.0f)
			{
				if (Point.bVirtual)
				{
					auto& Parent = *Point.pParent;
					const auto& BoneCSTransform = Output.Pose.GetComponentSpaceTransform(Parent.BoneIndex);
					auto BoneTransformInWorldSpace = BoneCSTransform * ToWorld;
					auto Target = BoneTransformInWorldSpace.TransformPosition(Parent.CSBoneDirection);
					Point.Position += (Target - Point.Position) * Point.Hardness;
				}
				else
				{
					const auto& BoneCSTransform = Output.Pose.GetComponentSpaceTransform(Point.BoneIndex);
					auto BoneTransformInWorldSpace = BoneCSTransform * ToWorld;
					Point.Position += (BoneTransformInWorldSpace.GetLocation() - Point.Position) * Point.Hardness;
				}
			}

			++iPoint;
		}
	}
}

void FAnimNode_SPCRJointDynamics::UpdateConstraints()
{
	const int32 ConstraintsNum = _Constraints.Num();
	for (int32 iConstraint = 0; iConstraint < ConstraintsNum; ++iConstraint)
	{
		auto GetConstraintPower = [&](bool IsShrink, float Rate, const SPCRConstraint& Constraint) {
			switch (Constraint.Type)
			{
			case SPCRConstraint::Structural_Vertical:
				return IsShrink
					? Structural_Vertical_Shrink.ComputeCurve(Rate)
					: Structural_Vertical_Stretch.ComputeCurve(Rate);
			case SPCRConstraint::Structural_Horizontal:
				return IsShrink
					? Structural_Horizontal_Shrink.ComputeCurve(Rate)
					: Structural_Horizontal_Stretch.ComputeCurve(Rate);
			case SPCRConstraint::Shear:
				return IsShrink
					? Shear_Shrink.ComputeCurve(Rate)
					: Shear_Stretch.ComputeCurve(Rate);
			case SPCRConstraint::Bending_Vertical:
				return IsShrink
					? Bending_Vertical_Shrink.ComputeCurve(Rate)
					: Bending_Vertical_Stretch.ComputeCurve(Rate);
			case SPCRConstraint::Bending_Horizontal:
				return IsShrink
					? Bending_Horizontal_Shrink.ComputeCurve(Rate)
					: Bending_Horizontal_Stretch.ComputeCurve(Rate);
			}
			return 0.0f;
		};

		auto& Constraint = _Constraints[iConstraint];
		auto pPointA = Constraint.pPointA;
		auto pPointB = Constraint.pPointB;

		auto WeightA = pPointA->Weight;
		auto WeightB = pPointB->Weight;
		if (WeightA + WeightB < 0.001f) continue;

		auto OrderRate = (pPointA->OrderRate + pPointB->OrderRate) * 0.5f;

		auto Direction = pPointB->Position - pPointA->Position;
		auto Distance = Direction.Size();
		auto Force = Distance - Constraint.Length;

		auto ConstraintPower = GetConstraintPower(Force >= 0.0f, OrderRate, Constraint);
		if (ConstraintPower > 0.0f)
		{
			auto Displacement = Direction.GetSafeNormal() * (Force * ConstraintPower);

			float WightAB = WeightA + WeightB;
			pPointA->Position += Displacement * WeightA / WightAB;
			pPointB->Position -= Displacement * WeightB / WightAB;
		}
	}
}

void FAnimNode_SPCRJointDynamics::UpdateCollision()
{
	const int32 ConstraintsNum = _Constraints.Num();
	for (int32 iConstraint = 0; iConstraint < ConstraintsNum; ++iConstraint)
	{
		auto& Constraint = _Constraints[iConstraint];
		if (!Constraint.IsCollision) continue;

		auto pPointA = Constraint.pPointA;
		auto pPointB = Constraint.pPointB;

		auto WeightA = pPointA->Weight;
		auto WeightB = pPointB->Weight;
		if (WeightA + WeightB < 0.001f) continue;

		auto PointCollisionExe = [&](const TArray<FSPCRCollider>& ColliderTbl)
		{
			for (auto&& Collider : ColliderTbl)
			{
				if (WeightA > 0.0f)
				{
					PushoutFromCollider(Collider, pPointA->Position);
				}
				if (WeightB > 0.0f)
				{
					PushoutFromCollider(Collider, pPointB->Position);
				}
			}
		};

		auto LineCollisionExe = [&](const TArray<FSPCRCollider>& ColliderTbl, float& Friction)
		{
			for (auto&& Collider : ColliderTbl)
			{
				float Radius;
				FVector pointOnLine, pointOnCollider;
				if (CollisionDetection(Collider, pPointA->Position, pPointB->Position, pointOnLine, pointOnCollider, Radius))
				{
					auto Pushout = pointOnLine - pointOnCollider;
					auto PushoutDistance = Pushout.Size();

					auto pointDistance = (pPointB->Position - pPointA->Position).Size() * 0.5f;
					auto rateP1 = FMath::Clamp((pointOnLine - pPointA->Position).Size() / pointDistance, 0.0f, 1.0f);
					auto rateP2 = FMath::Clamp((pointOnLine - pPointB->Position).Size() / pointDistance, 0.0f, 1.0f);

					Pushout /= PushoutDistance;
					Pushout *= FMath::Max(Radius - PushoutDistance, 0.0f);
					if (WeightA > 0.0f)
					{
						pPointA->Position += Pushout * rateP2;
					}
					if (WeightB > 0.0f)
					{
						pPointB->Position += Pushout * rateP1;
					}

					auto Dot = FVector::DotProduct(FVector::UpVector, (pointOnLine - pointOnCollider).GetSafeNormal());
					Friction = FMath::Max(Friction, Collider.Friction * FMath::Clamp(FMath::Abs(Dot), 0.0f, 1.0f));
				}
			}
		};

		if (ReadID.Num() > 0)
		{
			for (auto&& ID : ReadID)
			{
				GetGlobalColliders(ID, _ExternalColliders);
				PointCollisionExe(_ExternalColliders);
			}
		}
		PointCollisionExe(_Colliders);

		{
			float Friction = 0.0f;
			if (ReadID.Num() > 0)
			{
				for (auto&& ID : ReadID)
				{
					GetGlobalColliders(ID, _ExternalColliders);
					LineCollisionExe(_ExternalColliders, Friction);
				}
			}
			LineCollisionExe(_Colliders, Friction);
			pPointA->Friction = FMath::Max(Friction, pPointA->Friction);
			pPointB->Friction = FMath::Max(Friction, pPointB->Friction);
		}
	}
}

void FAnimNode_SPCRJointDynamics::ForceFixConstraints()
{
	const int32 ConstraintsNum = _Constraints.Num();
	for (int32 iConstraint = 0; iConstraint < ConstraintsNum; ++iConstraint)
	{
		auto& Constraint = _Constraints[iConstraint];

		auto pPointA = Constraint.pPointA;
		auto pPointB = Constraint.pPointB;

		auto Direction = pPointB->Position - pPointA->Position;
		auto Distance = Direction.Size();

		if (Distance > Constraint.Length)
		{
			pPointB->Position = pPointA->Position + (Direction.GetSafeNormal() * Constraint.Length);
		}
	}
}

void FAnimNode_SPCRJointDynamics::UpdateSurfaceCollision()
{
	struct SPCRRay
	{
		FVector RayOrigin, RayDirection;
	public:
		SPCRRay()
		{
			RayOrigin = RayDirection = FVector::ZeroVector;
		}
		SPCRRay(FVector Origin, FVector Direction)
		{
			RayOrigin = Origin;
			RayDirection = Direction;
		}

		FVector GetPointAt(float Enter)
		{
			return RayOrigin + Enter * RayDirection;
		}

		bool SimpleRaycast(FVector& PlaneNormal, float& PlaneDistance, float& enter)
		{
			float vDot = FVector::DotProduct(RayDirection, PlaneNormal);
			float nDot = -FVector::DotProduct(RayOrigin, PlaneNormal) - PlaneDistance;

			if (FMath::Abs(vDot) <= 0.001)
			{
				enter = 0.0;
				return false;
			}
			enter = nDot / vDot;
			return enter > 0.001f;
		}
	};

	auto CenterOfTheTriangle = [](FVector& v1, FVector& v2, FVector& v3)
	{
		FVector v12 = FMath::Lerp(v1, v2, 0.5);
		FVector v13 = FMath::Lerp(v1, v3, 0.5);
		return FMath::Lerp(v12, v13, 0.5);
	};

	auto TriangleContainsPoint = [](FVector& A, FVector& B, FVector& C, FVector& P)
	{
		FVector AP = A - P;
		FVector BP = B - P;
		FVector CP = C - P;

		FVector U = FVector::CrossProduct(AP, BP);
		FVector V = FVector::CrossProduct(BP, CP);
		FVector W = FVector::CrossProduct(CP, AP);

		if (FVector::DotProduct(U, V) < 0.0f)
			return false;
		if (FVector::DotProduct(V, W) < 0.0f)
			return false;
		return true;
	};

	auto GetPlaneNormal = [](FVector& A, FVector& B, FVector& C)
	{
		FVector AB = (B - A).GetSafeNormal();
		FVector CA = (C - A).GetSafeNormal();

		return FVector::CrossProduct(AB, CA);
	};

	auto CheckCollision = [&](FVector& PointPosA, FVector& PointPosB, FVector& PointPosC, FSPCRCollider& Collider, FVector& OutIntersectionPoint, FVector& OutPointOnCollider, FVector& OutPushOut, float& OutRadius)
	{
		SPCRRay Ray;
		float Enter = 0;
		OutPointOnCollider = Collider.Position;
		OutRadius = Collider.Radius;

		const FVector ColliderDir = Collider.Direction.GetSafeNormal();

		FVector TriangleCenter = CenterOfTheTriangle(PointPosA, PointPosB, PointPosC);
		FVector ColliderDirFromTriCenter = (Collider.Position - TriangleCenter);
		ColliderDirFromTriCenter.Normalize();

		FVector PlaneNormal = GetPlaneNormal(PointPosA, PointPosB, PointPosC);
		PlaneNormal.Normalize();
		float PlaneDistanceFromOrigin = -FVector::DotProduct(PlaneNormal, PointPosA);
		PlaneNormal *= -1;

		float TriCenterDotP = FVector::DotProduct(ColliderDirFromTriCenter, PlaneNormal);

		if (Collider.bCapsule)
		{
			float Side = FVector::DotProduct(ColliderDir, PlaneNormal) * TriCenterDotP;
			ColliderDirFromTriCenter = PlaneNormal * TriCenterDotP * -1;
			ColliderDirFromTriCenter.Normalize();

			FVector TempPointOnCollider = OutPointOnCollider;
			if (Side < 0)
			{
				OutRadius = Collider.Radius;
				OutPointOnCollider = Collider.Position + (Collider.Direction * 0.5) * 2;
			}
			else
			{
				OutRadius = Collider.Radius;
			}

			Ray = SPCRRay(OutPointOnCollider, ColliderDirFromTriCenter);
			FVector PlaneNormalInverse = PlaneNormal * -1;

			if (Ray.SimpleRaycast(PlaneNormalInverse, PlaneDistanceFromOrigin, /*Out*/Enter))
			{
				OutIntersectionPoint = Ray.GetPointAt(Enter);
				if (TriangleContainsPoint(PointPosA, PointPosB, PointPosC, OutIntersectionPoint))
				{
					OutPushOut = OutIntersectionPoint - OutPointOnCollider;
					FVector TowardsCollider = OutPointOnCollider - OutIntersectionPoint;
					return TowardsCollider.SizeSquared() <= OutRadius * OutRadius;
				}
			}
			else
			{
				//When The collider at the center of the cloth
				if (Collider.SurfaceColliderType != 0)
				{
					OutPointOnCollider = TempPointOnCollider;
					FVector EndVec = Collider.Position + (Collider.Direction * 0.5f) * 2;
					FVector CollDirVec = Collider.Direction;

					if (Collider.SurfaceColliderType == 2)//Pull
					{
						FVector Temp = OutPointOnCollider;
						OutPointOnCollider = EndVec;
						EndVec = Temp;
						CollDirVec *= -1;
					}

					Ray = SPCRRay(OutPointOnCollider, CollDirVec);
					FVector InversePlane = PlaneNormal * -1;

					if (Ray.SimpleRaycast(InversePlane, PlaneDistanceFromOrigin, Enter))
					{
						OutIntersectionPoint = Ray.GetPointAt(Enter);

						if (TriangleContainsPoint(PointPosA, PointPosB, PointPosC, OutIntersectionPoint))
						{
							FVector IntersecToEnd = EndVec - OutIntersectionPoint;
							FVector ColliderToEndVec = EndVec - OutPointOnCollider;
							FVector ColliderToIntersecVec = OutIntersectionPoint - OutPointOnCollider;

							float PointDot = FVector::DotProduct(IntersecToEnd, ColliderToIntersecVec);
							float LineDot = FVector::DotProduct(ColliderToEndVec, ColliderToEndVec);

							if (!(PointDot >= 0 && PointDot <= LineDot))
							{
								OutPushOut = FVector::ZeroVector;
								return false;
							}

							float CEDotCI = FVector::DotProduct(ColliderToEndVec, ColliderToIntersecVec);

							EndVec = (OutPointOnCollider + ColliderToEndVec.GetSafeNormal() * -OutRadius);
							OutPushOut = OutIntersectionPoint - EndVec;

							OutPointOnCollider += ColliderToEndVec * (CEDotCI / LineDot);
							FVector TowardsCollider = OutPointOnCollider - OutIntersectionPoint;
							return TowardsCollider.SizeSquared() <= OutRadius * OutRadius;
							return false;
						}
					}
				}
			}
		}
		else
		{
			//Handling Sphere Surface collision here
			ColliderDirFromTriCenter = PlaneNormal * TriCenterDotP * -1;

			Ray = SPCRRay(Collider.Position, ColliderDirFromTriCenter);
			FVector PlaneNormalInverse = PlaneNormal * -1;

			if (Ray.SimpleRaycast(PlaneNormalInverse, PlaneDistanceFromOrigin, /*Out*/Enter))
			{
				OutIntersectionPoint = Ray.GetPointAt(Enter);

				if (TriangleContainsPoint(PointPosA, PointPosB, PointPosC, OutIntersectionPoint))
				{
					OutPushOut = OutIntersectionPoint - OutPointOnCollider;
					FVector TowardsCollider = OutPointOnCollider - OutIntersectionPoint;
					return TowardsCollider.SizeSquared() <= OutRadius * OutRadius;
				}
			}
		}

		OutIntersectionPoint = FVector::ZeroVector;
		OutPushOut = FVector::ZeroVector;
		return false;
	};

	auto HandleSurfaceCollision = [&](TArray<SPCRPoint*>& TrianglePoints, FSPCRCollider& Collider)
	{
		FVector IntersectionPoint = FVector::ZeroVector;
		FVector PointOnCollider = FVector::ZeroVector;
		FVector PushOut = FVector::ZeroVector;
		float Radius = 0;

		for (int32 iTriangle = 0; iTriangle < TrianglePoints.Num(); iTriangle += 3)
		{
			auto& pointA = TrianglePoints[iTriangle + 0];
			auto& pointB = TrianglePoints[iTriangle + 1];
			auto& pointC = TrianglePoints[iTriangle + 2];

			if (CheckCollision(pointA->Position, pointB->Position, pointC->Position, Collider, IntersectionPoint, PointOnCollider, PushOut, Radius))
			{
				FVector TriangleCenter = CenterOfTheTriangle(pointA->Position, pointB->Position, pointC->Position);
				float PushOutmagnitude = PushOut.Size();
				PushOut.Normalize();

				for (int32 iVertex = 0; iVertex < 3; iVertex++)
				{
					auto& Point = TrianglePoints[iTriangle + iVertex];
					FVector CenterToPoint = Point->Position - TriangleCenter;
					FVector IntersectionToPoint = Point->Position - IntersectionPoint;

					float Rate = CenterToPoint.Size() / IntersectionToPoint.Size();
					Rate = FMath::Clamp(FMath::Abs(Rate), 0.0f, 1.0f);
					FVector PushVec = PushOut * (Radius - PushOutmagnitude);
					Point->Position += PushVec * Rate;
				}
			}
		}
	};

	const int32 ConstraintsNum = _SurfaceConstraints.Num();
	TArray<SPCRPoint*> TrianglePoints;

	const int32 ColliderNum = _Colliders.Num();
	for (int32 iConstraint = 0; iConstraint < ConstraintsNum; ++iConstraint)
	{
		auto& Constraint = _SurfaceConstraints[iConstraint];
		TrianglePoints.Empty();
		TrianglePoints.Add(Constraint.PointA);
		TrianglePoints.Add(Constraint.PointB);
		TrianglePoints.Add(Constraint.PointC);

		TrianglePoints.Add(Constraint.PointC);
		TrianglePoints.Add(Constraint.PointD);
		TrianglePoints.Add(Constraint.PointA);

		for (int32 iCollider = 0; iCollider < ColliderNum; iCollider++)
		{
			auto& Collider = _Colliders[iCollider];
			HandleSurfaceCollision(TrianglePoints, Collider);
		}

		if (ReadID.Num() > 0)
		{
			for (auto&& ID : ReadID)
			{
				GetGlobalColliders(ID, _ExternalColliders);
				for (int32 iCollider = 0; iCollider < _ExternalColliders.Num(); iCollider++)
				{
					auto& Collider = _ExternalColliders[iCollider];
					HandleSurfaceCollision(TrianglePoints, Collider);
				}
			}
		}
	}
}

void FAnimNode_SPCRJointDynamics::ApplyToBone(FComponentSpacePoseContext& Output, TArray<FBoneTransform>& OutBoneTransforms)
{
	const auto& CompT = Output.AnimInstanceProxy->GetComponentTransform();

	if (Alpha < 1.0f)
	{
		for (auto&& Points : _PointsTbl)
		{
			for (auto&& Point : Points)
			{
				const auto& BoneCSTransform = Output.Pose.GetComponentSpaceTransform(Point.BoneIndex);
				auto Localtion = BoneCSTransform.GetLocation();
				auto CSPosition = CompT.InverseTransformPosition(Point.Position);
				Point.CSPosition = Localtion + (CSPosition - Localtion) * Alpha;
			}
		}
	}
	else
	{
		for (auto&& Points : _PointsTbl)
		{
			for (auto&& Point : Points)
			{
				Point.CSPosition = CompT.InverseTransformPosition(Point.Position);
			}
		}
	}

	for (auto&& Points : _PointsTbl)
	{
		for (auto&& Point : Points)
		{
			if (Point.bVirtual) continue;

			const auto& BoneCSTransform = Output.Pose.GetComponentSpaceTransform(Point.BoneIndex);
			Point.Transform = BoneCSTransform;

			if (Point.pChild != nullptr)
			{
				FVector ToTarget, ToCurrent;
				ToTarget = Point.CSPosition - Point.pChild->CSPosition;
				if (Point.pChild->bVirtual)
				{
					ToCurrent = BoneCSTransform.GetRotation() * Point.CSBoneDirection;
				}
				else
				{
					const auto& ChildBoneCSTransform = Output.Pose.GetComponentSpaceTransform(Point.pChild->BoneIndex);
					ToCurrent = BoneCSTransform.GetLocation() - ChildBoneCSTransform.GetLocation();
				}
				auto AddRotation = FQuat::FindBetweenNormals(ToCurrent.GetSafeNormal(), ToTarget.GetSafeNormal());
				Point.Transform.SetRotation(AddRotation * BoneCSTransform.GetRotation());
			}

			Point.Transform.SetLocation(Point.CSPosition);
			LockAngles(&Point);
		}
	}

	const int32 PointAccessTblNum = _PointAccessTbl.Num();
	for (int32 iTable = 0; iTable < PointAccessTblNum; ++iTable)
	{
		const auto& Point = *_PointAccessTbl[iTable];
		OutBoneTransforms.Add(FBoneTransform(Point.BoneIndex, Point.Transform));
	}
}

void FAnimNode_SPCRJointDynamics::LockAngles(SPCRPoint* spcrPoint)
{
	if (spcrPoint->pParent == nullptr || !bLimitAngle)
		return;

	FVector SuperParentPosition = spcrPoint->pParent->pParent != nullptr ? spcrPoint->pParent->pParent->Position : spcrPoint->pParent->Position;

	FVector boneDir = spcrPoint->Position - spcrPoint->pParent->Position;
	FVector parentBoneDir = spcrPoint->pParent->Position - SuperParentPosition;

	if (parentBoneDir.Size() == 0 || bLimitFromRoot)
	{
		parentBoneDir = spcrPoint->InitialWorldPosition - spcrPoint->pParent->InitialWorldPosition;
	}

	float angle = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(parentBoneDir.GetSafeNormal(), boneDir.GetSafeNormal())));
	float remainingAngle = angle - AngleLimitInDegree;
	if (remainingAngle > 0.0f)
	{
		FVector handleAxis = FVector::CrossProduct(parentBoneDir, boneDir).GetSafeNormal();
		spcrPoint->Position = spcrPoint->pParent->Position + boneDir.RotateAngleAxis(-remainingAngle, handleAxis);
	}
}

void FAnimNode_SPCRJointDynamics::PushoutFromSphere(const FVector& Center, float Radius, FVector& Point)
{
	auto direction = Point - Center;
	auto sqrDirectionLength = direction.SizeSquared();
	if (sqrDirectionLength > SPCR_EPSILON)
	{
		if (sqrDirectionLength < Radius * Radius)
		{
			auto directionLength = FMath::Sqrt(sqrDirectionLength);
			Point = Center + direction * Radius / directionLength;
			return;
		}
	}
}

void FAnimNode_SPCRJointDynamics::PushoutFromSphere(const FSPCRCollider& Collider, FVector& Point)
{
	PushoutFromSphere(Collider.Position, Collider.Radius, Point);
}

void FAnimNode_SPCRJointDynamics::PushoutFromCapsule(const FSPCRCollider& Collider, FVector& Point)
{
	auto capsuleVec = Collider.Direction;
	auto capsuleVecNormal = capsuleVec;
	capsuleVecNormal.Normalize();
	auto capsulePos = Collider.Position;
	auto targetVec = Point - capsulePos;
	auto distanceOnVec = FVector::DotProduct(capsuleVecNormal, targetVec);
	if (distanceOnVec <= 0.0f)
	{
		PushoutFromSphere(capsulePos, Collider.Radius, Point);
		return;
	}
	else
	if (distanceOnVec >= Collider.Height)
	{
		PushoutFromSphere(capsulePos + capsuleVec, Collider.Radius, Point);
		return;
	}
	else
	{
		auto positionOnVec = capsulePos + (capsuleVecNormal * distanceOnVec);
		auto pushoutVec = Point - positionOnVec;
		auto sqrPushoutDistance = pushoutVec.SizeSquared();
		if (sqrPushoutDistance > 0.001f)
		{
			if (sqrPushoutDistance < Collider.Radius * Collider.Radius)
			{
				auto pushoutDistance = FMath::Sqrt(sqrPushoutDistance);
				Point = positionOnVec + pushoutVec * Collider.Radius / pushoutDistance;
				return;
			}
		}
	}
}

void FAnimNode_SPCRJointDynamics::PushoutFromCollider(const FSPCRCollider& Collider, FVector& Point)
{
	if (Collider.bCapsule)
	{
		PushoutFromCapsule(Collider, Point);
	}
	else
	{
		PushoutFromSphere(Collider, Point);
	}
}

bool FAnimNode_SPCRJointDynamics::CollisionDetection(const FSPCRCollider& Collider, const FVector& point1, const FVector& point2, FVector& pointOnLine, FVector& pointOnCollider, float& Radius)
{
	auto CollisionDetection_Sphere = [](const FVector& SphereCenter, float SphereRadius, const FVector& point1, const FVector& point2, FVector& pointOnLine, FVector& pointOnCollider, float& Radius)
	{
		auto direction = point2 - point1;
		auto directionLength = direction.Size();
		direction /= directionLength;

		auto toCenter = SphereCenter - point1;
		auto dot = FVector::DotProduct(direction, toCenter);
		auto pointOnDirection = direction * FMath::Clamp(dot, 0.0f, directionLength);

		pointOnCollider = SphereCenter;
		pointOnLine = pointOnDirection + point1;
		Radius = SphereRadius;

		return (pointOnCollider - pointOnLine).SizeSquared() <= Radius * Radius;
	};

	if (Collider.bCapsule)
	{
		auto capsuleDir = Collider.Direction;
		auto capsulePos = Collider.Position;
		auto pointDir = point2 - point1;

		if (CollisionDetection_Sphere(capsulePos, Collider.Radius, point1, point2, pointOnLine, pointOnCollider, Radius))
		{
			return true;
		}
		if (CollisionDetection_Sphere(capsulePos + capsuleDir, Collider.Radius, point1, point2, pointOnLine, pointOnCollider, Radius))
		{
			return true;
		}

		float t1, t2;
		auto sqrDistance = ComputeNearestPoints(capsulePos, capsuleDir, point1, pointDir, t1, t2, pointOnCollider, pointOnLine);
		t1 = FMath::Clamp(t1, 0.0f, 1.0f);
		Radius = Collider.Radius;

		if (sqrDistance > Radius * Radius)
		{
			pointOnCollider = FVector::ZeroVector;
			pointOnLine = FVector::ZeroVector;
			return false;
		}

		t2 = FMath::Clamp(t2, 0.0f, 1.0f);

		pointOnCollider = capsulePos + capsuleDir * t1;
		pointOnLine = point1 + pointDir * t2;

		return (pointOnCollider - pointOnLine).SizeSquared() <= Radius * Radius;
	}
	else
	{
		return CollisionDetection_Sphere(Collider.Position, Collider.Radius, point1, point2, pointOnLine, pointOnCollider, Radius);
	}
}

float FAnimNode_SPCRJointDynamics::ComputeNearestPoints(FVector posP, FVector dirP, FVector posQ, FVector dirQ, float& tP, float& tQ, FVector& pointOnP, FVector& pointOnQ)
{
	auto n1 = FVector::CrossProduct(dirP, FVector::CrossProduct(dirQ, dirP));
	auto n2 = FVector::CrossProduct(dirQ, FVector::CrossProduct(dirP, dirQ));

	tP = FVector::DotProduct((posQ - posP), n2) / FVector::DotProduct(dirP, n2);
	tQ = FVector::DotProduct((posP - posQ), n1) / FVector::DotProduct(dirQ, n1);
	pointOnP = posP + dirP * tP;
	pointOnQ = posQ + dirQ * tQ;

	return (pointOnQ - pointOnP).SizeSquared();
}

void FAnimNode_SPCRJointDynamics::CreateColliders()
{
	//const auto& Pose = Output.Pose.GetPose();
	//const auto& BoneContainer = Pose.GetBoneContainer();
	_ColliderInfos.Empty();
	_Colliders.Empty();

	for (auto&& Body : Bodies)
	{
		SPCRColliderInfo Info;
		Info.TargetBone = Body.TargetBone;
		Info.LocalTransform = Body.Transform;
		Info.Radius = Body.Radius;
		Info.Height = Body.Height;
		_ColliderInfos.Add(Info);

		FSPCRCollider Collider;
		Collider.bCapsule = Body.Height > SPCR_EPSILON;
		Collider.Friction = Body.Friction;
		Collider.SurfaceColliderType = (int8)Body.SurfaceColliderType;
		_Colliders.Add(Collider);
	}
}

void FAnimNode_SPCRJointDynamics::CreateControlPoints(FComponentSpacePoseContext& Output)
{
	const auto& Pose = Output.Pose.GetPose();
	const auto& BoneContainer = Pose.GetBoneContainer();

	TArray<TArray<FCompactPoseBoneIndex>> BoneIndicesTbl;

	auto CheckSameBone = [&](FCompactPoseBoneIndex In) {
		for (auto&& localTbl : BoneIndicesTbl) {
			for (auto&& localIdx : localTbl) {
				if (In == localIdx) {
					return true;
				}
			}
		}
		return false;
	};

	// 親⇒子のテーブルを作成
	for (auto&& Pair : JointPairs)
	{
		TArray<FCompactPoseBoneIndex> BoneIndices;

		const FCompactPoseBoneIndex RootIndex = Pair.RootBone.GetCompactPoseIndex(BoneContainer);
		FCompactPoseBoneIndex BoneIndex = Pair.EndBone.GetCompactPoseIndex(BoneContainer);
		do
		{
			if (CheckSameBone(BoneIndex))
			{
				FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("同一ボーンが設定されています。")));
				return;
			}
			BoneIndices.Insert(BoneIndex, 0);
			BoneIndex = Pose.GetParentBoneIndex(BoneIndex);
		} while (BoneIndex != RootIndex);
		BoneIndices.Insert(BoneIndex, 0);

		BoneIndicesTbl.Add(BoneIndices);
	}

	// 作ったテーブルに合わせて制御点を作成
	const bool NeedVirtualBone = VirtualBoneLength > 0.0f;
	for (auto&& Indices : BoneIndicesTbl)
	{
		const int32 IndicesNum = Indices.Num();
		if (IndicesNum < 2) continue;

		TArray<SPCRPoint> Points;

		for (int32 iIndex = 0; iIndex < IndicesNum; ++iIndex)
		{
			const auto& BoneIndex = Indices[iIndex];
			const auto Weight = iIndex <= FixedPointIndex ? 0.0f : 1.0f;

			SPCRPoint Pt;
			Pt.BoneIndex = BoneIndex;
			Pt.ParentBoneIndex = Pose.GetParentBoneIndex(BoneIndex);
			Pt.Weight = Weight;
			Pt.OrderRate = (float)iIndex / (float)(NeedVirtualBone ? IndicesNum : IndicesNum - 1);
			Pt.Resistance = 1.0f - FMath::Clamp(Resistance.ComputeCurve(Pt.OrderRate) * 0.01f, 0.0f, 1.0f);
			Pt.Gravity = GravityCurve.ComputeCurve(Pt.OrderRate);
			Pt.Hardness = FMath::Clamp(Hardness.ComputeCurve(Pt.OrderRate) * 0.01f, 0.0f, 1.0f);
			Pt.LimitStrength = LimitCurve.ComputeCurve(Pt.OrderRate);
			Pt.bVirtual = false;
			Points.Add(Pt);
		}

		if (NeedVirtualBone)
		{
			SPCRPoint Pt;
			Pt.BoneIndex = FCompactPoseBoneIndex(-1);
			Pt.ParentBoneIndex = Pose.GetParentBoneIndex(Indices[IndicesNum - 1]);
			Pt.Weight = 1.0f;
			Pt.OrderRate = 1.0f;
			Pt.Resistance = 1.0f - FMath::Clamp(Resistance.ComputeCurve(Pt.OrderRate) * 0.01f, 0.0f, 1.0f);
			Pt.Gravity = GravityCurve.ComputeCurve(Pt.OrderRate);
			Pt.Hardness = FMath::Clamp(Hardness.ComputeCurve(Pt.OrderRate) * 0.01f, 0.0f, 1.0f);
			Pt.LimitStrength = LimitCurve.ComputeCurve(Pt.OrderRate);
			Pt.bVirtual = true;
			Points.Add(Pt);
		}

		_PointsTbl.Add(Points);
	}

	// 制御点の初期化
	for (auto&& Points : _PointsTbl)
	{
		const int32 PointNum = Points.Num();
		// 初期位置
		for (int32 iPoint = 0; iPoint < PointNum; ++iPoint)
		{
			auto& Point = Points[iPoint];

			if (Point.bVirtual)
			{
				auto& PrevPoint0 = Points[iPoint - 2];
				auto& PrevPoint1 = Points[iPoint - 1];

				const auto& BoneCSTransform = Output.Pose.GetComponentSpaceTransform(PrevPoint1.BoneIndex);
				const auto Direction = (PrevPoint1.Position - PrevPoint0.Position).GetSafeNormal();
				Point.Position = PrevPoint1.Position + Direction * VirtualBoneLength;
				PrevPoint1.CSBoneDirection = BoneCSTransform.GetRotation().Inverse() * (PrevPoint1.Position - Point.Position);
			}
			else
			{
				const auto& BoneCSTransform = Output.Pose.GetComponentSpaceTransform(Point.BoneIndex);
				const auto BoneTransformInWorldSpace = BoneCSTransform * Output.AnimInstanceProxy->GetComponentTransform();

				Point.Position = BoneTransformInWorldSpace.GetLocation();
			}

			Point.PositionPrev = Point.Position;
			Point.InitialWorldPosition = Point.Position;
		}

		// 子供のポインタを持つ
		for (int32 iPoint = 0; iPoint < PointNum - 1; ++iPoint)
		{
			Points[iPoint].pChild = &Points[iPoint + 1];
		}

		// 親のポインタを持つ
		for (int32 iPoint = 1; iPoint < PointNum; ++iPoint)
		{
			Points[iPoint].pParent = &Points[iPoint - 1];
		}
	}

	// 骨のインデックスの若い方から積まないと怒られるのでアクセス用のテーブル
	for (auto&& Points : _PointsTbl)
	{
		for (auto&& Point : Points)
		{
			if (Point.bVirtual) continue;
			_PointAccessTbl.Add(&Point);
		}
	}

	_PointAccessTbl.Sort(
		[](const SPCRPoint& lhs, const SPCRPoint& rhs)
		{
			return lhs.BoneIndex < rhs.BoneIndex;
		}
	);
}

void FAnimNode_SPCRJointDynamics::CreateConstraints()
{
	if (bBending_Horizontal)
	{
		CreateConstraintBendingHorizontal(_Constraints, _PointsTbl, false);
	}
	if (bBending_Vertical)
	{
		CreateConstraintBendingVertical(_Constraints, _PointsTbl, false);
	}
	if (bShear)
	{
		CreateConstraintShear(_Constraints, _PointsTbl, bShear_Collision);
	}
	if (bStructural_Horizontal)
	{
		CreateConstraintStructuralHorizontal(_Constraints, _PointsTbl, bStructural_Horizontal_Collision);
	}
	if (bStructural_Vertical)
	{
		for (int i = 0; i < Structural_Vertical_StepCount; ++i)
		{
			CreateConstraintStructuralVertical(_Constraints, _PointsTbl, bStructural_Vertical_Collision);
		}
	}
}

void FAnimNode_SPCRJointDynamics::CreateConstraintStructuralVertical(TArray<SPCRConstraint>& Out, TArray<TArray<SPCRPoint>>& PointsTbl, bool IsCollision)
{
	const int32 PointsTblNum = PointsTbl.Num();
	for (int32 iTable = 0; iTable < PointsTblNum; ++iTable)
	{
		auto& Points = PointsTbl[iTable];
		const int32 PointNum = Points.Num();
		for (int32 iPoint = 0; iPoint < PointNum - 1; ++iPoint)
		{
			auto& PointA = Points[iPoint];
			auto& PointB = Points[iPoint + 1];
			if ((PointA.Weight > 0.0f) || (PointB.Weight > 0.0f))
			{
				Out.Add(SPCRConstraint(SPCRConstraint::Structural_Vertical, &PointA, &PointB, IsCollision));
			}
		}
	}
}

void FAnimNode_SPCRJointDynamics::CreateConstraintStructuralHorizontal(TArray<SPCRConstraint>& Out, TArray<TArray<SPCRPoint>>& PointsTbl, bool IsCollision)
{
	const int32 PointsTblNum = PointsTbl.Num();
	if (PointsTblNum < 2) return;

	if (bJointLoop)
	{
		for (int32 iTable = 0; iTable < PointsTblNum; ++iTable)
		{
			auto& PointsA = PointsTbl[iTable];
			auto& PointsB = PointsTbl[(iTable + 1) % PointsTblNum];
			const int32 PointNumA = PointsA.Num();
			const int32 PointNumB = PointsB.Num();
			const int32 PointNum = FMath::Max(PointNumA, PointNumB);
			for (int32 iPoint = 0; iPoint < PointNum; ++iPoint)
			{
				auto& PointA = PointsA[FMath::Min(iPoint, PointNumA - 1)];
				auto& PointB = PointsB[FMath::Min(iPoint, PointNumB - 1)];
				if ((PointA.Weight > 0.0f) || (PointB.Weight > 0.0f))
				{
					Out.Add(SPCRConstraint(SPCRConstraint::Structural_Horizontal, &PointA, &PointB, IsCollision));
				}
			}
		}
	}
	else
	{
		for (int32 iTable = 0; iTable < PointsTblNum - 1; ++iTable)
		{
			auto& PointsA = PointsTbl[iTable];
			auto& PointsB = PointsTbl[iTable + 1];
			const int32 PointNumA = PointsA.Num();
			const int32 PointNumB = PointsB.Num();
			const int32 PointNum = FMath::Max(PointNumA, PointNumB);
			for (int32 iPoint = 0; iPoint < PointNum; ++iPoint)
			{
				auto& PointA = PointsA[FMath::Min(iPoint, PointNumA - 1)];
				auto& PointB = PointsB[FMath::Min(iPoint, PointNumB - 1)];
				if ((PointA.Weight > 0.0f) || (PointB.Weight > 0.0f))
				{
					Out.Add(SPCRConstraint(SPCRConstraint::Structural_Horizontal, &PointA, &PointB, IsCollision));
				}
			}
		}
	}
}

void FAnimNode_SPCRJointDynamics::CreateConstraintBendingVertical(TArray<SPCRConstraint>& Out, TArray<TArray<SPCRPoint>>& PointsTbl, bool IsCollision)
{
	const int32 PointsTblNum = PointsTbl.Num();
	for (int32 iTable = 0; iTable < PointsTblNum; ++iTable)
	{
		auto& Points = PointsTbl[iTable];
		const int32 PointNum = Points.Num();
		for (int32 iPoint = 0; iPoint < PointNum - 2; ++iPoint)
		{
			auto& PointA = Points[iPoint];
			auto& PointB = Points[iPoint + 2];
			if ((PointA.Weight > 0.0f) || (PointB.Weight > 0.0f))
			{
				Out.Add(SPCRConstraint(SPCRConstraint::Bending_Vertical, &PointA, &PointB, IsCollision));
			}
		}
	}
}

void FAnimNode_SPCRJointDynamics::CreateConstraintBendingHorizontal(TArray<SPCRConstraint>& Out, TArray<TArray<SPCRPoint>>& PointsTbl, bool IsCollision)
{
	const int32 PointsTblNum = PointsTbl.Num();
	if (PointsTblNum < 2) return;

	if (bJointLoop)
	{
		for (int32 iTable = 0; iTable < PointsTblNum; ++iTable)
		{
			auto& PointsA = PointsTbl[iTable];
			auto& PointsB = PointsTbl[(iTable + 2) % PointsTblNum];
			const int32 PointNumA = PointsA.Num();
			const int32 PointNumB = PointsB.Num();
			const int32 PointNum = FMath::Max(PointNumA, PointNumB);
			for (int32 iPoint = 0; iPoint < PointNum; ++iPoint)
			{
				auto& PointA = PointsA[FMath::Min(iPoint, PointNumA - 1)];
				auto& PointB = PointsB[FMath::Min(iPoint, PointNumB - 1)];
				if ((PointA.Weight > 0.0f) || (PointB.Weight > 0.0f))
				{
					Out.Add(SPCRConstraint(SPCRConstraint::Bending_Horizontal, &PointA, &PointB, IsCollision));
				}
			}
		}
	}
	else
	{
		for (int32 iTable = 0; iTable < PointsTblNum - 2; ++iTable)
		{
			auto& PointsA = PointsTbl[iTable];
			auto& PointsB = PointsTbl[iTable + 2];
			const int32 PointNumA = PointsA.Num();
			const int32 PointNumB = PointsB.Num();
			const int32 PointNum = FMath::Max(PointNumA, PointNumB);
			for (int32 iPoint = 0; iPoint < PointNum; ++iPoint)
			{
				auto& PointA = PointsA[FMath::Min(iPoint, PointNumA - 1)];
				auto& PointB = PointsB[FMath::Min(iPoint, PointNumB - 1)];
				if ((PointA.Weight > 0.0f) || (PointB.Weight > 0.0f))
				{
					Out.Add(SPCRConstraint(SPCRConstraint::Bending_Horizontal, &PointA, &PointB, IsCollision));
				}
			}
		}
	}
}

void FAnimNode_SPCRJointDynamics::CreateConstraintShear(TArray<SPCRConstraint>& Out, TArray<TArray<SPCRPoint>>& PointsTbl, bool IsCollision)
{
	const int32 PointsTblNum = PointsTbl.Num();
	if (PointsTblNum < 2) return;

	if (bJointLoop)
	{
		for (int32 iTable = 0; iTable < PointsTblNum; ++iTable)
		{
			auto& PointsA = PointsTbl[iTable];
			auto& PointsB = PointsTbl[(iTable + 1) % PointsTblNum];
			const int32 PointNumA = PointsA.Num();
			const int32 PointNumB = PointsB.Num();
			const int32 PointNum = FMath::Max(PointNumA, PointNumB);
			for (int32 iPoint = 0; iPoint < PointNum; ++iPoint)
			{
				auto& PointA = PointsA[FMath::Min(iPoint + 1, PointNumA - 1)];
				auto& PointB = PointsB[FMath::Min(iPoint, PointNumB - 1)];
				if ((PointA.Weight > 0.0f) || (PointB.Weight > 0.0f))
				{
					Out.Add(SPCRConstraint(SPCRConstraint::Shear, &PointA, &PointB, IsCollision));
				}
			}
			for (int32 iPoint = 0; iPoint < PointNum; ++iPoint)
			{
				auto& PointA = PointsA[FMath::Min(iPoint, PointNumA - 1)];
				auto& PointB = PointsB[FMath::Min(iPoint + 1, PointNumB - 1)];
				if ((PointA.Weight > 0.0f) || (PointB.Weight > 0.0f))
				{
					Out.Add(SPCRConstraint(SPCRConstraint::Shear, &PointA, &PointB, IsCollision));
				}
			}
		}
	}
	else
	{
		for (int32 iTable = 0; iTable < PointsTblNum - 1; ++iTable)
		{
			auto& PointsA = PointsTbl[iTable];
			auto& PointsB = PointsTbl[iTable + 1];
			const int32 PointNumA = PointsA.Num();
			const int32 PointNumB = PointsB.Num();
			const int32 PointNum = FMath::Max(PointNumA, PointNumB);
			for (int32 iPoint = 0; iPoint < PointNum; ++iPoint)
			{
				auto& PointA = PointsA[FMath::Min(iPoint + 1, PointNumA - 1)];
				auto& PointB = PointsB[FMath::Min(iPoint, PointNumB - 1)];
				if ((PointA.Weight > 0.0f) || (PointB.Weight > 0.0f))
				{
					Out.Add(SPCRConstraint(SPCRConstraint::Shear, &PointA, &PointB, IsCollision));
				}
			}
			for (int32 iPoint = 0; iPoint < PointNum; ++iPoint)
			{
				auto& PointA = PointsA[FMath::Min(iPoint, PointNumA - 1)];
				auto& PointB = PointsB[FMath::Min(iPoint + 1, PointNumB - 1)];
				if ((PointA.Weight > 0.0f) || (PointB.Weight > 0.0f))
				{
					Out.Add(SPCRConstraint(SPCRConstraint::Shear, &PointA, &PointB, IsCollision));
				}
			}
		}
	}
}

void FAnimNode_SPCRJointDynamics::CreateSurfaceConstraints()
{
	const int32 PointsTblNum = _PointsTbl.Num();
	for (int32 iTable = 0; iTable < PointsTblNum - 1; ++iTable)
	{
		auto& PointsA = _PointsTbl[iTable];
		auto& PointsB = _PointsTbl[iTable + 1];
		const int32 PointNumA = PointsA.Num();
		const int32 PointNumB = PointsB.Num();
		const int32 PointNum = FMath::Max(PointNumA, PointNumB);
		for (int32 iPoint = 0; iPoint < PointNum; ++iPoint)
		{
			auto& PointA = PointsA[FMath::Min(iPoint, PointNumA - 1)];
			auto& PointB = PointsB[FMath::Min(iPoint, PointNumB - 1)];

			auto& PointAC = PointsA[FMath::Min(iPoint + 1, PointNumA - 1)];
			auto& PointBC = PointsB[FMath::Min(iPoint + 1, PointNumB - 1)];

			if ((PointA.Weight > 0.0f) || (PointB.Weight > 0.0f) || (PointAC.Weight > 0.0f) || (PointBC.Weight > 0.0f))
			{
				_SurfaceConstraints.Add(SPCRSurfaceConstraint(&PointA, &PointB, &PointBC, &PointAC));
			}
		}
	}
}

void FAnimNode_SPCRJointDynamics::Debug_DrawSurfaceTriangle(FVector a, FVector b, FVector c)
{
#if WITH_EDITOR
	DrawDebugLine(GWorld, a, b, FColor::Red);
	DrawDebugLine(GWorld, b, c, FColor::Red);
	DrawDebugLine(GWorld, c, a, FColor::Red);

	FVector ab = FMath::Lerp(a, b, 0.5);
	FVector ac = FMath::Lerp(a, c, 0.5);
	FVector center = FMath::Lerp(ab, ac, 0.5);
	FVector normal = FVector::CrossProduct((b - a).GetSafeNormal(), (c - a).GetSafeNormal()).GetSafeNormal();
	DrawDebugLine(GWorld, center, center + normal, FColor::Red);
#endif
}

void FAnimNode_SPCRJointDynamics::SetGlobalColliders(int32 Guid, const TArray<FSPCRCollider>& Colliders)
{
	FScopeLock Lock(&_GlobalCollidersLock);
	auto* pCollder = _GlobalColliders.Find(Guid);
	if (pCollder == nullptr)
	{
		_GlobalColliders.Add(Guid, Colliders);
	}
	else
	{
		*pCollder = Colliders;
	}
}

void FAnimNode_SPCRJointDynamics::GetGlobalColliders(int32 Guid, TArray<FSPCRCollider>& Output)
{
	FScopeLock Lock(&_GlobalCollidersLock);
	auto* pCollder = _GlobalColliders.Find(Guid);
	if (pCollder == nullptr)
	{
		Output.Empty();
	}
	else
	{
		Output = *pCollder;
	}
}

void FAnimNode_SPCRJointDynamics::HandleDebugDraw()
{
	DebugDrawConstraints();
	DebugDrawColliders();
	DebugDrawSurfaceCollision();
}

void FAnimNode_SPCRJointDynamics::DebugDrawConstraints()
{
	// 拘束のデバッグ表示
	if (bDebugDrawConstraints)
	{
		for (int32 iConstraint = 0; iConstraint < _Constraints.Num(); ++iConstraint)
		{
			auto& Constraint = _Constraints[iConstraint];
			auto pPointA = Constraint.pPointA;
			auto pPointB = Constraint.pPointB;

			DrawDebugLine(
				GWorld,
				pPointA->Position,
				pPointB->Position,
				FColor::Blue);
		}
	}
}

void FAnimNode_SPCRJointDynamics::DebugDrawColliders()
{

}

void FAnimNode_SPCRJointDynamics::DebugDrawSurfaceCollision()
{
	if (bDebugDrawSurfaceCollision)
	{
		for (int32 iConstraint = 0; iConstraint < _SurfaceConstraints.Num(); ++iConstraint)
		{
			auto& SurfaceCollider = _SurfaceConstraints[iConstraint];
			Debug_DrawSurfaceTriangle(SurfaceCollider.PointA->Position, SurfaceCollider.PointB->Position, SurfaceCollider.PointC->Position);
			Debug_DrawSurfaceTriangle(SurfaceCollider.PointC->Position, SurfaceCollider.PointD->Position, SurfaceCollider.PointA->Position);
		}
	}
}

void FAnimNode_SPCRJointDynamics::SyncColliderPositions()
{
	if (_Colliders.Num() <= 0 || _ColliderInfos.Num() <= 0)
	{
		CreateColliders();
	}

	for (int i = 0; i < Bodies.Num(); ++i)
	{
		_ColliderInfos[i].LocalTransform = Bodies[i].Transform;
		_ColliderInfos[i].Height = Bodies[i].Height;
		_ColliderInfos[i].Radius = Bodies[i].Radius;
	}
}

TMap<int32, TArray<FSPCRCollider>> FAnimNode_SPCRJointDynamics::_GlobalColliders;
FCriticalSection FAnimNode_SPCRJointDynamics::_GlobalCollidersLock;
