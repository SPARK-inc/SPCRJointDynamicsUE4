//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#include "SPCRJointDynamics_EditorBase.h"
#include "IPersonaPreviewScene.h"
#include "AssetEditorModeManager.h"
#include "AnimGraphNode_Base.h"
#include "Animation/DebugSkelMeshComponent.h"

#include "AnimGraphNode_SkeletalControlBase.h"
#include "AnimNode_SPCRJointDynamics.h"

#define LOCTEXT_NAMESPACE "AnimNodeEditMode"

IMPLEMENT_HIT_PROXY(HSPCRColliderHitProxy, HHitProxy);

SPCRJointDynamics_EditorBase::SPCRJointDynamics_EditorBase()
	:AnimGraphNode(nullptr),
	RuntimeNode(nullptr),
	CurrentWidgetMode(UE::Widget::EWidgetMode::WM_Translate),
	SelectedColliderIndex(SPCR_INVALID_COLLIDER_INDEX)
{
}

SPCRJointDynamics_EditorBase::~SPCRJointDynamics_EditorBase()
{
}

ECoordSystem SPCRJointDynamics_EditorBase::GetWidgetCoordinateSystem() const
{
	UAnimGraphNode_SkeletalControlBase* skeletalControl = Cast<UAnimGraphNode_SkeletalControlBase>(AnimGraphNode);
	if (skeletalControl != nullptr)
	{
		PRAGMA_DISABLE_DEPRECATION_WARNINGS
		return (ECoordSystem)skeletalControl->GetWidgetCoordinateSystem(GetAnimPreviewScene().GetPreviewMeshComponent());
		PRAGMA_ENABLE_DEPRECATION_WARNINGS
	}
	return ECoordSystem::COORD_None;
}

UE::Widget::EWidgetMode SPCRJointDynamics_EditorBase::GetWidgetMode() const
{
	if (IsValidColliderIndex())
		return CurrentWidgetMode;
	else
		return UE::Widget::EWidgetMode::WM_None;
}

UE::Widget::EWidgetMode SPCRJointDynamics_EditorBase::ChangeToNextWidgetMode(UE::Widget::EWidgetMode CurWidgetMode)
{
	return UE::Widget::EWidgetMode::WM_None;
}

bool SPCRJointDynamics_EditorBase::SetWidgetMode(UE::Widget::EWidgetMode InWidgetMode)
{
	if (AnimGraphNode != nullptr)
	{
		UAnimGraphNode_SkeletalControlBase* SkeletalControl = Cast<UAnimGraphNode_SkeletalControlBase>(AnimGraphNode);
		if (SkeletalControl != nullptr)
		{
			PRAGMA_DISABLE_DEPRECATION_WARNINGS
			SkeletalControl->SetWidgetMode(GetAnimPreviewScene().GetPreviewMeshComponent(), InWidgetMode);
			PRAGMA_ENABLE_DEPRECATION_WARNINGS
		}
	}
	return false;
}

FName SPCRJointDynamics_EditorBase::GetSelectedBone() const
{
	UAnimGraphNode_SkeletalControlBase* SkeletalController = Cast<UAnimGraphNode_SkeletalControlBase>(AnimGraphNode);
	if (SkeletalController != nullptr)
	{
		PRAGMA_DISABLE_DEPRECATION_WARNINGS
		return SkeletalController->FindSelectedBone();
		PRAGMA_ENABLE_DEPRECATION_WARNINGS
	}
	return FName("");
}

void SPCRJointDynamics_EditorBase::DoTranslation(FVector& InTranslation)
{
	UAnimGraphNode_SkeletalControlBase* SkelControl = Cast<UAnimGraphNode_SkeletalControlBase>(AnimGraphNode);
	if (SkelControl != nullptr)
	{
		PRAGMA_DISABLE_DEPRECATION_WARNINGS
			SkelControl->DoTranslation(GetAnimPreviewScene().GetPreviewMeshComponent(), InTranslation, (FAnimNode_SkeletalControlBase*)RuntimeNode);
		PRAGMA_ENABLE_DEPRECATION_WARNINGS
	}
}

void SPCRJointDynamics_EditorBase::DoRotation(FRotator& InRotation)
{
	UAnimGraphNode_SkeletalControlBase* SkelControl = Cast<UAnimGraphNode_SkeletalControlBase>(AnimGraphNode);
	if (SkelControl != nullptr)
	{
		PRAGMA_DISABLE_DEPRECATION_WARNINGS
			SkelControl->DoRotation(GetAnimPreviewScene().GetPreviewMeshComponent(), InRotation, (FAnimNode_SkeletalControlBase*)RuntimeNode);
		PRAGMA_ENABLE_DEPRECATION_WARNINGS
	}
}

void SPCRJointDynamics_EditorBase::DoScale(FVector& InTranslation)
{
	UAnimGraphNode_SkeletalControlBase* SkelControl = Cast<UAnimGraphNode_SkeletalControlBase>(AnimGraphNode);
	if (SkelControl != nullptr)
	{
		PRAGMA_DISABLE_DEPRECATION_WARNINGS
			SkelControl->DoTranslation(GetAnimPreviewScene().GetPreviewMeshComponent(), InTranslation, (FAnimNode_SkeletalControlBase*)RuntimeNode);
		PRAGMA_ENABLE_DEPRECATION_WARNINGS
	}
}

void SPCRJointDynamics_EditorBase::EnterMode(class UAnimGraphNode_Base* InEditorNode, struct FAnimNode_Base* InRuntimeNode)
{
	AnimGraphNode = InEditorNode;
	RuntimeNode = InRuntimeNode;

	GetModeManager()->SetCoordSystem(GetWidgetCoordinateSystem());
	GetModeManager()->SetWidgetMode(GetWidgetMode());
}

void SPCRJointDynamics_EditorBase::ExitMode()
{
	AnimGraphNode = nullptr;
	RuntimeNode = nullptr;
}

bool SPCRJointDynamics_EditorBase::GetCameraTarget(FSphere& OutTarget) const
{
	FVector Location(GetWidgetLocation());
	OutTarget.Center = Location;
	OutTarget.W = 50.0f;

	return true;
}

IPersonaPreviewScene& SPCRJointDynamics_EditorBase::GetAnimPreviewScene() const
{
	return *static_cast<IPersonaPreviewScene*>(static_cast<FAssetEditorModeManager*>(Owner)->GetPreviewScene());
}

void SPCRJointDynamics_EditorBase::GetOnScreenDebugInfo(TArray<FText>& OutDebugInfo) const
{
	if (AnimGraphNode != nullptr)
	{
		AnimGraphNode->GetOnScreenDebugInfo(OutDebugInfo, RuntimeNode, GetAnimPreviewScene().GetPreviewMeshComponent());
	}
}

void SPCRJointDynamics_EditorBase::DrawHUD(FEditorViewportClient* ViewportClient, FViewport* Viewport, const FSceneView* View, FCanvas* Canvas)
{
	if (AnimGraphNode != nullptr)
	{
		AnimGraphNode->DrawCanvas(*Viewport, *const_cast<FSceneView*>(View), *Canvas, GetAnimPreviewScene().GetPreviewMeshComponent());
	}
}

bool SPCRJointDynamics_EditorBase::HandleClick(FEditorViewportClient* InViewportClient, HHitProxy* HitProxy, const FViewportClick& Click)
{
	bool isValid = false;
	if (HitProxy != nullptr && HitProxy->IsA(HSPCRColliderHitProxy::StaticGetType()))
	{
		HSPCRColliderHitProxy* spcrColliderHitProxy = static_cast<HSPCRColliderHitProxy*>(HitProxy);
		if (spcrColliderHitProxy != nullptr)
		{
			SelectedColliderIndex = spcrColliderHitProxy->ColliderIndex;
			CurrentWidgetMode = UE::Widget::EWidgetMode::WM_Translate;
			isValid = true;
		}
	}

	if(!isValid)
	{
		SelectedColliderIndex = SPCR_INVALID_COLLIDER_INDEX;
		CurrentWidgetMode = UE::Widget::EWidgetMode::WM_None;
	}

	SetWidgetMode(CurrentWidgetMode);
	GetModeManager()->SetWidgetMode(GetWidgetMode());
	return isValid;
}

bool SPCRJointDynamics_EditorBase::InputDelta(FEditorViewportClient* InViewportClient, FViewport* InViewport, FVector& InDrag, FRotator& InRot, FVector& InScale)
{
	const EAxisList::Type CurrentAxis = InViewportClient->GetCurrentWidgetAxis();

	if (IsValidColliderIndex() && CurrentAxis != EAxisList::Type::None)
	{
		const UE::Widget::EWidgetMode WidgetMode = InViewportClient->GetWidgetMode();

		if (WidgetMode != UE::Widget::EWidgetMode::WM_None)
		{
			const bool IsTranslate = WidgetMode == UE::Widget::EWidgetMode::WM_Translate;
			const bool IsRotation = WidgetMode == UE::Widget::EWidgetMode::WM_Rotate;
			const bool IsScale = WidgetMode == UE::Widget::EWidgetMode::WM_Scale;

			if (IsTranslate)
			{
				DoTranslation(InDrag);
			}

			if (IsRotation)
			{
				DoRotation(InRot);
			}

			if (IsScale)
			{
				DoScale(InScale);
			}

			InViewport->Invalidate();
			InViewportClient->Invalidate();
		}
		return true;
	}
	return false;
}

void SPCRJointDynamics_EditorBase::Render(const FSceneView* View, FViewport* Viewport, FPrimitiveDrawInterface* PDI)
{
	if (AnimGraphNode != nullptr)
	{
		AnimGraphNode->Draw(PDI, GetAnimPreviewScene().GetPreviewMeshComponent());
	}
}

bool SPCRJointDynamics_EditorBase::StartTracking(FEditorViewportClient* InViewportClient, FViewport* InViewport)
{
	if (AnimGraphNode == nullptr)return false;

	AnimGraphNode->SetFlags(RF_Transactional);
	AnimGraphNode->Modify();
	return true;
}

bool SPCRJointDynamics_EditorBase::EndTracking(FEditorViewportClient* InViewportClient, FViewport* InViewport)
{
	return true;
}

bool SPCRJointDynamics_EditorBase::ShouldDrawWidget() const
{
	return IsValidColliderIndex();
}

bool SPCRJointDynamics_EditorBase::InputKey(FEditorViewportClient* InViewportClient, FViewport* InViewport, FKey InKey, EInputEvent InEvent)
{
	if (InEvent == IE_Pressed)
	{
		if (InKey == EKeys::Q)
		{
			ECoordSystem CoordSystem = GetModeManager()->GetCoordSystem();
			GetModeManager()->SetCoordSystem(CoordSystem == COORD_Local ? COORD_World : COORD_Local);
		}
	}
	return false;
}

bool SPCRJointDynamics_EditorBase::GetCustomDrawingCoordinateSystem(FMatrix& InMatrix, void* InData)
{
	UDebugSkelMeshComponent* PreviewMeshComponent = GetAnimPreviewScene().GetPreviewMeshComponent();
	FName BoneName = GetSelectedBone();
	int32 BoneIndex = PreviewMeshComponent->GetBoneIndex(BoneName);
	if (BoneIndex != INDEX_NONE)
	{
		FTransform BoneMatrix = PreviewMeshComponent->GetBoneTransform(BoneIndex);
		InMatrix = BoneMatrix.ToMatrixNoScale().RemoveTranslation();
		return true;
	}

	return false;
}

bool SPCRJointDynamics_EditorBase::GetCustomInputCoordinateSystem(FMatrix& InMatrix, void* InData)
{
	return GetCustomDrawingCoordinateSystem(InMatrix, InData);
}

bool SPCRJointDynamics_EditorBase::IsValidColliderIndex() const
{
	return SPCR_IS_VALID_INDEX(SelectedColliderIndex);
}

#undef LOCTEXT_NAMESPACE
