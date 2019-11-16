//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#pragma once

#include "AnimGraphNode_Base.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "AnimNode_SPCRJointDynamics.h"

#include "AnimGraphNode_SPCRJointDynamics.generated.h"
UCLASS()
class UAnimGraphNode_SPCRJointDynamics : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, Category = Settings)
	FAnimNode_SPCRJointDynamics Node;

public:
	// UEdGraphNode interface
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	//virtual FText GetTooltipText() const override;
	//virtual FText GetMenuCategory() const;
	// End of UEdGraphNode

	// UAnimGraphNode_SkeletalControlBase interface
	//virtual FText GetControllerDescription() const override;
	virtual void Draw(FPrimitiveDrawInterface* PDI, USkeletalMeshComponent* PreviewSkelMeshComp) const override;
	virtual void GetOnScreenDebugInfo(TArray<FText>& DebugInfo, FAnimNode_Base* RuntimeAnimNode, USkeletalMeshComponent* PreviewSkelMeshComp) const override;
	virtual const FAnimNode_SkeletalControlBase* GetNode() const override { return &Node; }
	// End of UAnimGraphNode_SkeletalControlBase interface

private:
	UPROPERTY(Transient)
	mutable USkeletalMeshComponent* LastPreviewComponent = nullptr;

	FAnimNode_SPCRJointDynamics* GetPreviewNode() const;
};