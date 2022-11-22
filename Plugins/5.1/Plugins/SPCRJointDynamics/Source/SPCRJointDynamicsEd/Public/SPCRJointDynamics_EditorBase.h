//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#pragma once

//======================================================================================
//
//======================================================================================
#include "CoreMinimal.h"
#include "IAnimNodeEditMode.h"
#include "UnrealWidgetFwd.h"

#include "AnimationEditMode.h"

//======================================================================================
//
//======================================================================================
#define SPCR_INVALID_COLLIDER_INDEX -1
#define SPCR_IS_VALID_INDEX(index) (index != SPCR_INVALID_COLLIDER_INDEX)

//======================================================================================
//
//======================================================================================
struct HSPCRColliderHitProxy : public HHitProxy
{
	DECLARE_HIT_PROXY();

	HSPCRColliderHitProxy(int ColliderIndex)
		:HHitProxy(EHitProxyPriority::HPP_Wireframe),
		ColliderIndex(ColliderIndex)
	{
	}

	virtual EMouseCursor::Type GetMouseCursor() override
	{
		return EMouseCursor::Hand;
	}

	int ColliderIndex = SPCR_INVALID_COLLIDER_INDEX;
};

//======================================================================================
//
//======================================================================================
/**
 * 
 */
class SPCRJOINTDYNAMICSED_API SPCRJointDynamics_EditorBase : public IAnimNodeEditMode
{
public:
	SPCRJointDynamics_EditorBase();
	~SPCRJointDynamics_EditorBase();

	//--------------IAnimNodeEditMode interface
	virtual ECoordSystem GetWidgetCoordinateSystem() const override;
	virtual UE::Widget::EWidgetMode GetWidgetMode() const override;
	virtual UE::Widget::EWidgetMode ChangeToNextWidgetMode(UE::Widget::EWidgetMode CurWidgetMode) override;
	virtual bool SetWidgetMode(UE::Widget::EWidgetMode InWidgetMode) override;
	virtual FName GetSelectedBone() const override;
	virtual void DoTranslation(FVector& InTranslation) override;
	virtual void DoRotation(FRotator& InRotation) override;
	virtual void DoScale(FVector& InScale) override;
	virtual void EnterMode(class UAnimGraphNode_Base* InEditorNode, struct FAnimNode_Base* InRuntimeNode) override;
	virtual void ExitMode() override;

	virtual bool SupportsPoseWatch() override { return false; };
	virtual void RegisterPoseWatchedNode(UAnimGraphNode_Base* InEditorNode, FAnimNode_Base* InRuntimeNode) override;

	//--------------IPersonaEditMode interface
	virtual bool GetCameraTarget(FSphere& OutTarget) const override;
	virtual class IPersonaPreviewScene& GetAnimPreviewScene() const override;
	virtual void GetOnScreenDebugInfo(TArray<FText>& OutDebugInfo) const override;

	//--------------EDMode
	virtual void DrawHUD(FEditorViewportClient* ViewportClient, FViewport* Viewport, const FSceneView* View, FCanvas* Canvas) override;
	virtual bool HandleClick(FEditorViewportClient* InViewportClient, HHitProxy* HitProxy, const FViewportClick& Click) override;
	virtual bool InputDelta(FEditorViewportClient* InViewportClient, FViewport* InViewport, FVector& InDrag, FRotator& InRot, FVector& InScale) override;
	virtual void Render(const FSceneView* View, FViewport* Viewport, FPrimitiveDrawInterface* PDI) override;
	virtual bool StartTracking(FEditorViewportClient* InViewportClient, FViewport* InViewport) override;
	virtual bool EndTracking(FEditorViewportClient* InViewportClient, FViewport* InViewport) override;
	virtual bool ShouldDrawWidget() const override;
	virtual bool InputKey(FEditorViewportClient* InViewportClient, FViewport* InViewport, FKey InKey, EInputEvent InEvent) override;
	virtual bool GetCustomDrawingCoordinateSystem(FMatrix& InMatrix, void* InData) override;
	virtual bool GetCustomInputCoordinateSystem(FMatrix& InMatrix, void* InData) override;
	//virtual FVector GetWidgetLocation() const override;

protected:
	FORCEINLINE bool IsValidColliderIndex() const;

protected:
	class UAnimGraphNode_Base* AnimGraphNode;
	struct FAnimNode_Base* RuntimeNode;

	UE::Widget::EWidgetMode CurrentWidgetMode;

	int SelectedColliderIndex;
};
