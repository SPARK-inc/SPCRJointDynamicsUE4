//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#pragma once

//======================================================================================
//
//======================================================================================
#include "CoreMinimal.h"
#include "SPCRJointDynamics_EditorBase.h"
#include "AnimGraphNode_SPCRJointDynamics.h"
#include "AnimNode_SPCRJointDynamics.h"

//======================================================================================
//
//======================================================================================
class UDebugSkelMeshComponent;
class FCanvas;

//======================================================================================
//
//======================================================================================
class SPCRJOINTDYNAMICSED_API SPCRJointDynamics_Editor : public SPCRJointDynamics_EditorBase
{
public:
	SPCRJointDynamics_Editor();
	~SPCRJointDynamics_Editor();

	//IAnimNodeEditMode interface
	virtual ECoordSystem GetWidgetCoordinateSystem() const override;
	virtual void EnterMode(class UAnimGraphNode_Base* InEditorNode, struct FAnimNode_Base* InRuntimeNode) override;
	virtual void ExitMode() override;
	virtual void DoTranslation(FVector& InTranslation) override;
	virtual void DoRotation(FRotator& InRotation) override;
	virtual void DoScale(FVector& InScale) override;

	//FEdMode interface
	virtual bool InputDelta(FEditorViewportClient* InViewportClient, FViewport* InViewport, FVector& InDrag, FRotator& InRot, FVector& InScale) override;
	virtual void Render(const FSceneView* View, FViewport* Viewport, FPrimitiveDrawInterface* PDI) override;
	virtual bool HandleClick(FEditorViewportClient* InViewportClient, HHitProxy* HitProxy, const FViewportClick& Click) override;
	virtual FVector GetWidgetLocation() const override;
	virtual bool GetCustomDrawingCoordinateSystem(FMatrix& InMatrix, void* InData) override;
	virtual void DrawHUD(FEditorViewportClient* ViewportClient, FViewport* Viewport, const FSceneView* View, FCanvas* Canvas) override;

private:
	void RenderCapculeColliders(FPrimitiveDrawInterface* PDI, FSPCRJointDynamicsBody& OutCollider, const int ColliderIndex, const FTransform& BoneTransform, const float Radius, const float Height);
	void RenderSphereColliders(FPrimitiveDrawInterface* PDI, FSPCRJointDynamicsBody& OutCollider, const int ColliderIndex, const FTransform& BoneTransform, const float Radius);

protected:
	FSPCRJointDynamicsBody* GetCurrColliderRuntimeNode();
	FSPCRJointDynamicsBody* GetCurrColliderGraphNode();

	void DrawHUDText(FCanvas* Canvas, const UFont* Font, const float& charHeight, FText Text, FVector2D& TextPosition);

public:
	static const FName REGISTER_MODE_ID;

private:
	UAnimGraphNode_SPCRJointDynamics* SPCRAnimGraphNode;
	struct FAnimNode_SPCRJointDynamics* SPCRRuntimeAnimNode;
};
