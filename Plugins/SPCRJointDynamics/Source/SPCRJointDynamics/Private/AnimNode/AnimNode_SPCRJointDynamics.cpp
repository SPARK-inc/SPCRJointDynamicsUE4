//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#include "AnimNode_SPCRJointDynamics.h"
#include "Animation/AnimInstanceProxy.h"
#include "Animation/AnimTypes.h"
#include "AnimationRuntime.h"
#include "DrawDebugHelpers.h"
#include "SPCRJointDynamicsModulePCH.h"

static const float SPCR_EPSILON = 0.0001f;

/////////////////////////////////////////////////////
// FAnimNode_SPCRJointDynamics

DECLARE_CYCLE_STAT(TEXT("SPCRJointDynamics"), STAT_SPCRJointDynamics_Eval, STATGROUP_Anim);

FAnimNode_SPCRJointDynamics::FAnimNode_SPCRJointDynamics()
{
	_bRequireResetPose = true;
	_ResetDelay = 1.0f;
	_DeltaTime = 0.0f;
	_WindForceRadians = 0.0f;

	//AirResistance.Begin = 0.90f;
	//AirResistance.End = 0.98f;

	_PointsTbl.Empty();
	_Constraints.Empty();
	_PointAccessTbl.Empty();
	_ColliderInfos.Empty();
	_Colliders.Empty();
}

bool FAnimNode_SPCRJointDynamics::RequireResetCheck(FComponentSpacePoseContext& Output)
{
	if ((jointDynamicsComponent != NULL) && jointDynamicsComponent->isReset)
	{
		// リセット処理を行う
		_bRequireResetPose = true;
		_ResetDelay = 1.0f;
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
	_ColliderInfos.Empty();
	_Colliders.Empty();

	// 制御点の生成
	CreateControlPoints(Output);

	// 拘束を作る
	CreateConstraints();

	// コリジョン
	CreateColliders(Output);
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

	// 制御点にかかる力
	FVector ActiveWindForce = FVector::ZeroVector;
	if (WindForceSpeed > 0.0f)
	{
		_WindForceRadians += _DeltaTime * WindForceSpeed;
		while (_WindForceRadians > +3.141592f) _WindForceRadians -= 3.141592f * 2.0f;
		while (_WindForceRadians < -3.141592f) _WindForceRadians += 3.141592f * 2.0f;
		ActiveWindForce = WindForce * (FMath::Sin(_WindForceRadians) * 0.5f + 0.5f);
	}

	// 全制御点の更新
	UpdateControlPoints(Output, ActiveWindForce);

	// 拘束の更新
	for (int32 iRelax = 0; iRelax < MaxIterations; ++iRelax)
	{
		UpdateConstraints();
	}

	// 絶対長さが伸びるのは許さない
	if (bForceLengthLimit)
	{
		ForceFixConstraints();
	}

	// 骨のトランスフォームに適用
	ApplyToBone(Output, OutBoneTransforms);

	// 拘束のデバッグ表示
	//if (bDebugDraw)
	//{
	//	for (int32 iConstraint = 0; iConstraint < _Constraints.Num(); ++iConstraint)
	//	{
	//		auto& Constraint = _Constraints[iConstraint];
	//		auto pPointA = Constraint.pPointA;
	//		auto pPointB = Constraint.pPointB;
	//
	//		DrawDebugLine(
	//			GWorld,
	//			pPointA->Position,
	//			pPointB->Position,
	//			FColor::Blue);
	//	}
	//}
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
	_ResetDelay = 1.0f;
	_DeltaTime = 0.0f;
	_WindForceRadians = 0.0f;

	_PointsTbl.Empty();
	_Constraints.Empty();
	_PointAccessTbl.Empty();
	_ColliderInfos.Empty();
	_Colliders.Empty();
}

void FAnimNode_SPCRJointDynamics::CacheBones_AnyThread(const FAnimationCacheBonesContext& Context)
{
	FAnimNode_SkeletalControlBase::CacheBones_AnyThread(Context);
}

void FAnimNode_SPCRJointDynamics::ResetDynamics(ETeleportType InTeleportType)
{
	Super::ResetDynamics(InTeleportType);

	_bRequireResetPose = true;
	_ResetDelay = 1.0f;
	_DeltaTime = 0.0f;
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

			//if (bDebugDraw)
			//{
			//	DrawDebugCapsule(
			//		GWorld,
			//		ColliderTransformInWorldSpace.GetLocation(),
			//		_Colliders[i].Height * 0.5f,
			//		_Colliders[i].Radius,
			//		ColliderTransformInWorldSpace.GetRotation(),
			//		FColor::Red);
			//}
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

			//if (bDebugDraw)
			//{
			//	DrawDebugSphere(
			//		GWorld,
			//		_Colliders[i].Position,
			//		_Colliders[i].Radius,
			//		16,
			//		FColor::Red);
			//}
		}
	}

	if (WriteID != 0)
	{
		SetGlobalColliders(WriteID, _Colliders);
	}
}

void FAnimNode_SPCRJointDynamics::UpdateControlPoints(FComponentSpacePoseContext& Output, const FVector& Wind)
{
	const auto& ToWorld = Output.AnimInstanceProxy->GetComponentTransform();
	const int32 PointTblNum = _PointsTbl.Num();

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
		const float StepTime_x2_Half = _DeltaTime * _DeltaTime * 0.5f;
		const int32 PointNum = Points.Num();
		while (iPoint < PointNum)
		{
			auto& Point = Points[iPoint];

			FVector Displacement;
			Displacement = Point.Position - Point.PositionPrev;
			Displacement += ((Gravity * Point.Gravity) + Wind) * StepTime_x2_Half;
			Displacement *= Point.Resistance;
			Displacement *= 1.0f - Point.Friction;

			Point.PositionPrev = Point.Position;
			Point.Position += Displacement;
			Point.Friction = 0.0f;

			if (Point.Softness > 0.0f)
			{
				const auto& BoneCSTransform = Output.Pose.GetComponentSpaceTransform(Point.BoneIndex);
				auto BoneTransformInWorldSpace = BoneCSTransform * ToWorld;
				Point.Position += (BoneTransformInWorldSpace.GetLocation() - Point.Position) * Point.Softness;
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
		if ((WeightA == 0.0f) && (WeightB == 0.0f)) continue;

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

		if (!Constraint.IsCollision) continue;

		auto PointCollisionExe = [&](const TArray<FSPCRCollider>& ColliderTbl, SPCRPoint* pA, SPCRPoint* B)
		{
			for (auto&& Collider : ColliderTbl)
			{
				if (pPointA->Weight > 0.0f)
				{
					PushoutFromCollider(Collider, pPointA->Position);
				}
				if (pPointB->Weight > 0.0f)
				{
					PushoutFromCollider(Collider, pPointB->Position);
				}
			}
		};

		auto LineCollisionExe = [&](const TArray<FSPCRCollider>& ColliderTbl, float& Friction, SPCRPoint* pA, SPCRPoint* B)
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
					Friction = FMath::Max(Friction, Collider.Friction * FMath::Clamp(Dot, 0.0f, 1.0f));
				}
			}
		};

		if (bPointCollision)
		{
			if (ReadID.Num() > 0)
			{
				for (auto&& ID : ReadID)
				{
					GetGlobalColliders(ID, _ExternalColliders);
					PointCollisionExe(_ExternalColliders, pPointA, pPointB);
				}
			}
			PointCollisionExe(_Colliders, pPointA, pPointB);
		}
		else
		{
			float Friction = 0.0f;
			if (ReadID.Num() > 0)
			{
				for (auto&& ID : ReadID)
				{
					GetGlobalColliders(ID, _ExternalColliders);
					LineCollisionExe(_ExternalColliders, Friction, pPointA, pPointB);
				}
			}
			LineCollisionExe(_Colliders, Friction, pPointA, pPointB);
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

void FAnimNode_SPCRJointDynamics::ApplyToBone(FComponentSpacePoseContext& Output, TArray<FBoneTransform>& OutBoneTransforms)
{
	const auto& CompT = Output.AnimInstanceProxy->GetComponentTransform();

	for (auto&& Points : _PointsTbl)
	{
		for (auto&& Point : Points)
		{
			Point.CSPosition = CompT.InverseTransformPosition(Point.Position);
		}
	}

	for (auto&& Points : _PointsTbl)
	{
		for (auto&& Point : Points)
		{
			const auto& BoneCSTransform = Output.Pose.GetComponentSpaceTransform(Point.BoneIndex);
			Point.Transform = BoneCSTransform;

			if (Point.pChild != nullptr)
			{
				const auto& ChildBoneCSTransform = Output.Pose.GetComponentSpaceTransform(Point.pChild->BoneIndex);

				auto ToTarget  = Point.CSPosition - Point.pChild->CSPosition;
				auto ToCurrent = BoneCSTransform.GetLocation() - ChildBoneCSTransform.GetLocation();
				auto AddRotation = FQuat::FindBetweenNormals(
											ToCurrent.GetSafeNormal(),
											ToTarget.GetSafeNormal());
				Point.Transform.SetRotation(AddRotation * BoneCSTransform.GetRotation());
			}

			Point.Transform.SetLocation(Point.CSPosition);
		}
	}

	const int32 PointAccessTblNum = _PointAccessTbl.Num();
	for (int32 iTable = 0; iTable < PointAccessTblNum; ++iTable)
	{
		const auto& Point = *_PointAccessTbl[iTable];
		OutBoneTransforms.Add(FBoneTransform(Point.BoneIndex, Point.Transform));
	}
}

void FAnimNode_SPCRJointDynamics::PushoutFromSphere(const FVector& Center, float Radius, FVector& Point)
{
	auto direction = Point - Center;
	auto sqrDirectionLength = direction.SizeSquared();
	if (sqrDirectionLength > 0.0001f)
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
	if (Collider.bCapsule)
	{
		auto capsuleDir = Collider.Direction;
		auto capsulePos = Collider.Position;
		auto pointDir = point2 - point1;

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
		auto direction = point2 - point1;
		auto directionLength = direction.Size();
		direction /= directionLength;

		auto toCenter = Collider.Position - point1;
		auto dot = FVector::DotProduct(direction, toCenter);
		auto pointOnDirection = direction * FMath::Clamp(dot, 0.0f, directionLength);

		pointOnCollider = Collider.Position;
		pointOnLine = pointOnDirection + point1;
		Radius = Collider.Radius;

		return (pointOnCollider - pointOnLine).SizeSquared() <= Radius * Radius;
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

void FAnimNode_SPCRJointDynamics::CreateColliders(FComponentSpacePoseContext& Output)
{
	const auto& Pose = Output.Pose.GetPose();
	const auto& BoneContainer = Pose.GetBoneContainer();

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
		}
		while (BoneIndex != RootIndex);
		BoneIndices.Insert(BoneIndex, 0);

		BoneIndicesTbl.Add(BoneIndices);
	}

	// 作ったテーブルに合わせて制御点を作成
	for (auto&& Indices : BoneIndicesTbl)
	{
		TArray<SPCRPoint> Points;

		const int32 IndicesNum = Indices.Num();
		for (int32 iIndex = 0; iIndex < IndicesNum; ++iIndex)
		{
			const auto& BoneIndex = Indices[iIndex];
			const auto Weight = iIndex <= FixedPointIndex ? 0.0f : 1.0f;

			SPCRPoint Pt;
			Pt.BoneIndex = BoneIndex;
			Pt.ParentBoneIndex = Pose.GetParentBoneIndex(BoneIndex);
			Pt.Weight = Weight;
			Pt.OrderRate = (float)iIndex / (float)(IndicesNum - 1);
			Pt.Resistance = AirResistance.ComputeCurve(Pt.OrderRate);
			Pt.Gravity = GravityCurve.ComputeCurve(Pt.OrderRate);
			Pt.Softness = 1.0f - Softness.ComputeCurve(Pt.OrderRate);
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

			const auto& BoneCSTransform = Output.Pose.GetComponentSpaceTransform(Point.BoneIndex);
			auto BoneTransformInWorldSpace = BoneCSTransform * Output.AnimInstanceProxy->GetComponentTransform();

			Point.Position = BoneTransformInWorldSpace.GetLocation();
			Point.PositionPrev = Point.Position;
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
			_PointAccessTbl.Add(&Point);
		}
	}
	_PointAccessTbl.Sort([](const SPCRPoint& lhs, const SPCRPoint& rhs) {
		return lhs.BoneIndex < rhs.BoneIndex;
	});
}

void FAnimNode_SPCRJointDynamics::CreateConstraints()
{
	if (bShear)
	{
		CreateConstraintShear(_Constraints, _PointsTbl, bShear_Collision);
	}
	if (bBending_Horizontal)
	{
		CreateConstraintBendingHorizontal(_Constraints, _PointsTbl, bBending_Horizontal_Collision);
	}
	if (bBending_Vertical)
	{
		CreateConstraintBendingVertical(_Constraints, _PointsTbl, bBending_Vertical_Collision);
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

TMap<int32, TArray<FSPCRCollider>> FAnimNode_SPCRJointDynamics::_GlobalColliders;
FCriticalSection FAnimNode_SPCRJointDynamics::_GlobalCollidersLock;
