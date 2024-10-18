//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#include "AnimGraphNode_SPCRJointDynamics.h"
#include "SPCRJointDynamics_Editor.h"
#include "EngineGlobals.h"
#include "SceneManagement.h"
#include "Kismet2/CompilerResultsLog.h"

#include "PropertyHandle.h"
#include "Animation/AnimInstance.h"

#define LOCTEXT_NAMESPACE "SPCRJointDynamicsAnimNode"

UAnimGraphNode_SPCRJointDynamics::UAnimGraphNode_SPCRJointDynamics(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FText UAnimGraphNode_SPCRJointDynamics::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("NodeTitle", "SPCR Joint Dynamics");
}
void UAnimGraphNode_SPCRJointDynamics::Draw(FPrimitiveDrawInterface* PDI, USkeletalMeshComponent* PreviewSkelMeshComp) const
{
	if (LastPreviewComponent != PreviewSkelMeshComp)
	{
		LastPreviewComponent = PreviewSkelMeshComp;
	}

	Super::Draw(PDI, PreviewSkelMeshComp);
	FAnimNode_SPCRJointDynamics* ActivePreviewNode = SPCRAnimNode;
	if (ActivePreviewNode)
	{
		TSet<FVector> AlreadyDrawedPoint;
		const float PointSize = 2.5f;
		if (ActivePreviewNode->IsDebugDraw())
		{
			for (auto& Constraint : ActivePreviewNode->GetConstraints())
			{
				if (Constraint.pPointA != nullptr)
				{
					bool AlreadyExist = false;
					AlreadyDrawedPoint.Add(Constraint.pPointA->Position, &AlreadyExist);
					if (!AlreadyExist)
					{
						PDI->DrawPoint(Constraint.pPointA->Position, FLinearColor::Green, PointSize, SDPG_Foreground);
					}
				}
				if (Constraint.pPointB != nullptr)
				{
					bool AlreadyExist = false;
					AlreadyDrawedPoint.Add(Constraint.pPointB->Position, &AlreadyExist);
					if (!AlreadyExist)
					{
						PDI->DrawPoint(Constraint.pPointB->Position, FLinearColor::Green, PointSize, SDPG_Foreground);
					}
				}
				if (Constraint.pPointA != nullptr && Constraint.pPointB != nullptr)
				{
					PDI->DrawLine(Constraint.pPointA->Position, Constraint.pPointB->Position, Constraint.IsCollision ? FLinearColor::Green : FLinearColor::Yellow, SDPG_Foreground);
				}
			}
		}

		if (ActivePreviewNode->IsDebugDrawSurfaceCollision())
		{
			auto DrawTriangle = [&](FVector& A, FVector& B, FVector& C)
			{
				PDI->DrawLine(A, B, FLinearColor::Red, SDPG_Foreground);
				PDI->DrawLine(B, C, FLinearColor::Red, SDPG_Foreground);
				PDI->DrawLine(C, A, FLinearColor::Red, SDPG_Foreground);

				FVector ab = FMath::Lerp(A, B, 0.5);
				FVector ac = FMath::Lerp(A, C, 0.5);
				FVector center = FMath::Lerp(ab, ac, 0.5);
				FVector normal = FVector::CrossProduct((B - A).GetSafeNormal(), (C - A).GetSafeNormal()).GetSafeNormal();
				PDI->DrawLine(center, center + normal, FLinearColor::Red, SDPG_Foreground);
			};

			for (auto& Constraint : ActivePreviewNode->GetSurfaceConstraints())
			{
				if (Constraint.PointA != nullptr && Constraint.PointB != nullptr)
				{
					DrawTriangle(Constraint.PointA->Position, Constraint.PointB->Position, Constraint.PointC->Position);
					DrawTriangle(Constraint.PointC->Position, Constraint.PointD->Position, Constraint.PointA->Position);
				}
			}
		}
	}
}

void UAnimGraphNode_SPCRJointDynamics::Debug_DrawSurfaceTriangle(FPrimitiveDrawInterface* PDI, FVector& a, FVector& b, FVector& c)
{
	PDI->DrawLine(a, b, FLinearColor::Red, SDPG_Foreground);
	PDI->DrawLine(a, c, FLinearColor::Red, SDPG_Foreground);

	FVector ab = FMath::Lerp(a, b, 0.5);
	FVector ac = FMath::Lerp(a, c, 0.5);
	FVector center = FMath::Lerp(ab, ac, 0.5);
	FVector normal = FVector::CrossProduct((b - a).GetSafeNormal(), (c - a).GetSafeNormal()).GetSafeNormal();
	PDI->DrawLine(center, center + normal, FLinearColor::Red, SDPG_Foreground);
}

void UAnimGraphNode_SPCRJointDynamics::GetOnScreenDebugInfo(TArray<FText>& DebugInfo, FAnimNode_Base* RuntimeAnimNode, USkeletalMeshComponent* PreviewSkelMeshComp) const
{
	Super::GetOnScreenDebugInfo(DebugInfo, RuntimeAnimNode, PreviewSkelMeshComp);
}

FEditorModeID UAnimGraphNode_SPCRJointDynamics::GetEditorMode() const
{
	return SPCRJointDynamics_Editor::REGISTER_MODE_ID;
}

//void UAnimGraphNode_SPCRJointDynamics::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
//{
//	Super::PostEditChangeProperty(PropertyChangedEvent);
//}

void UAnimGraphNode_SPCRJointDynamics::CopyNodeDataToPreviewNode(FAnimNode_Base* InPreviewNode)
{
	SPCRAnimNode = (FAnimNode_SPCRJointDynamics*)InPreviewNode;
}

#undef LOCTEXT_NAMESPACE
