//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#pragma once

//======================================================================================
//
//======================================================================================
#include "AnimGraphNode_Base.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "AnimNode_SPCRJointDynamics.h"
#include "AnimGraphNode_SPCRJointDynamics.generated.h"

//======================================================================================
//
//======================================================================================
class FCompilerResultsLog;

//======================================================================================
//
//======================================================================================
UCLASS()
class UAnimGraphNode_SPCRJointDynamics : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, Category = Settings)
	FAnimNode_SPCRJointDynamics Node;

public:
	// UEdGraphNode interface
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	// End of UEdGraphNode

	// UAnimGraphNode_SkeletalControlBase interface
	virtual FEditorModeID GetEditorMode() const override;
	virtual void Draw(FPrimitiveDrawInterface* PDI, USkeletalMeshComponent* PreviewSkelMeshComp) const override;
	virtual void GetOnScreenDebugInfo(TArray<FText>& DebugInfo, FAnimNode_Base* RuntimeAnimNode, USkeletalMeshComponent* PreviewSkelMeshComp) const override;
	virtual const FAnimNode_SkeletalControlBase* GetNode() const override { return &Node; }
	// End of UAnimGraphNode_SkeletalControlBase interface

	// UObject interface
	//virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

	virtual void CopyNodeDataToPreviewNode(FAnimNode_Base* InPreviewNode) override;

private:
	UPROPERTY(Transient)
	mutable USkeletalMeshComponent* LastPreviewComponent = nullptr;

	FAnimNode_SPCRJointDynamics* SPCRAnimNode = nullptr;

	void Debug_DrawSurfaceTriangle(FPrimitiveDrawInterface* PDI, FVector& a, FVector& b, FVector& c);
};