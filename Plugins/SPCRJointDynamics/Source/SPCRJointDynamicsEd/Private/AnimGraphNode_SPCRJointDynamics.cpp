//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#include "AnimGraphNode_SPCRJointDynamics.h"
#include "EngineGlobals.h"
#include "SceneManagement.h"

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
	FAnimNode_SPCRJointDynamics* ActivePreviewNode = GetPreviewNode();
	if (ActivePreviewNode)
	{
		TSet<FVector> AlreadyDrawedPoint;
		const float PointSize = 2.5f;
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

		for (auto& Body : ActivePreviewNode->Bodies)
		{
			FTransform BodyJointTransform = Body.Transform * PreviewSkelMeshComp->GetBoneTransform(Body.TargetBone.BoneIndex);

			if (Body.Height > 0.0f)
			{
				DrawWireCapsule(
					PDI,
					BodyJointTransform.GetLocation(),
					BodyJointTransform.GetScaledAxis(EAxis::X),
					BodyJointTransform.GetScaledAxis(EAxis::Y),
					BodyJointTransform.GetScaledAxis(EAxis::Z),
					FLinearColor::Yellow,
					Body.Radius,
					Body.Radius + (Body.Height * 0.5f),
					24,
					SDPG_World);
			}
			else
			{
				DrawWireSphere(
					PDI,
					BodyJointTransform,
					FLinearColor::Yellow,
					Body.Radius,
					24,
					SDPG_World);
			}
		}
	}
}
void UAnimGraphNode_SPCRJointDynamics::GetOnScreenDebugInfo(TArray<FText>& DebugInfo, FAnimNode_Base* RuntimeAnimNode, USkeletalMeshComponent* PreviewSkelMeshComp) const
{
	Super::GetOnScreenDebugInfo(DebugInfo, RuntimeAnimNode, PreviewSkelMeshComp);
}

//FText UAnimGraphNode_SPCRJointDynamics::GetTooltipText() const
//{
//	return LOCTEXT("NodeTooltip", "");
//}
//
//FText UAnimGraphNode_SPCRJointDynamics::GetMenuCategory() const
//{
//	return LOCTEXT("NodeCategory", "SPCR");
//}


FAnimNode_SPCRJointDynamics* UAnimGraphNode_SPCRJointDynamics::GetPreviewNode() const
{
	FAnimNode_SPCRJointDynamics* PreviewNode = nullptr;
	if (LastPreviewComponent && LastPreviewComponent->GetAnimInstance())
	{
		UAnimInstance* Instance = LastPreviewComponent->GetAnimInstance();
		if (UAnimBlueprintGeneratedClass* Class = Cast<UAnimBlueprintGeneratedClass>(Instance->GetClass()))
		{
			PreviewNode = Class->GetPropertyInstance<FAnimNode_SPCRJointDynamics>(Instance, NodeGuid);
		}
	}
	return PreviewNode;
}

#undef LOCTEXT_NAMESPACE
