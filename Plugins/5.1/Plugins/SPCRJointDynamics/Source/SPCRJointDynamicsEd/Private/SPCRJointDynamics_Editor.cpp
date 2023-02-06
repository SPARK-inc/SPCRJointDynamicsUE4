//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#include "SPCRJointDynamics_Editor.h"
#include "AnimNode_SPCRJointDynamics.h"
#include "AnimGraphNode_SPCRJointDynamics.h"
#include "Engine/Engine.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "IPersonaPreviewScene.h"
#include "Animation/DebugSkelMeshComponent.h"
#include "AssetEditorModeManager.h"
#include "CanvasItem.h"
#include "CanvasTypes.h"

const FName SPCRJointDynamics_Editor::REGISTER_MODE_ID = "AnimGraph.SkeletalControl.SPCRJointDynamics";

SPCRJointDynamics_Editor::SPCRJointDynamics_Editor()
	:SPCRAnimGraphNode(nullptr),
	SPCRRuntimeAnimNode(nullptr)
{
}

SPCRJointDynamics_Editor::~SPCRJointDynamics_Editor()
{
}

ECoordSystem SPCRJointDynamics_Editor::GetWidgetCoordinateSystem() const
{
	return ECoordSystem::COORD_Local;
}

void SPCRJointDynamics_Editor::EnterMode(class UAnimGraphNode_Base* InEditorNode, struct FAnimNode_Base* InRuntimeNode)
{
	SPCRJointDynamics_EditorBase::EnterMode(InEditorNode, InRuntimeNode);

	SPCRAnimGraphNode = CastChecked<UAnimGraphNode_SPCRJointDynamics>(InEditorNode);
	SPCRRuntimeAnimNode = static_cast<FAnimNode_SPCRJointDynamics*>(InRuntimeNode);
}

void SPCRJointDynamics_Editor::DoTranslation(FVector& InTranslation)
{
	if (IsValidColliderIndex() && SPCRAnimGraphNode != nullptr && SPCRRuntimeAnimNode != nullptr)
	{
		UDebugSkelMeshComponent* PreviewMeshComponent = GetAnimPreviewScene().GetPreviewMeshComponent();

		FSPCRJointDynamicsBody* CTransform_RuntimeNode = GetCurrColliderRuntimeNode();
		FSPCRJointDynamicsBody* CTransform_GraphNode = GetCurrColliderGraphNode();

		if (CTransform_RuntimeNode == nullptr || CTransform_GraphNode == nullptr)return;

		FTransform BoneTransform = PreviewMeshComponent->GetBoneTransform(CTransform_RuntimeNode->TargetBone.BoneIndex);

		FVector Translation = BoneTransform.InverseTransformVector(InTranslation);

		CTransform_RuntimeNode->Transform.AddToTranslation(Translation);
		CTransform_GraphNode->Transform.SetLocation(CTransform_RuntimeNode->Transform.GetLocation());
	}
}

void SPCRJointDynamics_Editor::DoRotation(FRotator& InRotation)
{
	if (IsValidColliderIndex() && SPCRAnimGraphNode != nullptr && SPCRRuntimeAnimNode != nullptr)
	{
		FSPCRJointDynamicsBody* Collider_RuntimeNode = GetCurrColliderRuntimeNode();
		FSPCRJointDynamicsBody* Colldier_GraphNode = GetCurrColliderGraphNode();

		UDebugSkelMeshComponent* PreviewMeshComponent = GetAnimPreviewScene().GetPreviewMeshComponent();

		if (Collider_RuntimeNode == nullptr || Colldier_GraphNode == nullptr || PreviewMeshComponent == nullptr) return;

		FVector RotAxis;
		float RotAngle;
		InRotation.Quaternion().ToAxisAndAngle(RotAxis, RotAngle);
		auto MeshBases = SPCRRuntimeAnimNode->ForwardedPose;
		const FMeshPoseBoneIndex MeshBoneIndex(PreviewMeshComponent->GetBoneIndex(Collider_RuntimeNode->TargetBone.BoneName));
		const FCompactPoseBoneIndex BoneIndex = MeshBases.GetPose().GetBoneContainer().MakeCompactPoseIndex(MeshBoneIndex);

		const FTransform& BoneTM = BoneIndex >= 0 ? MeshBases.GetComponentSpaceTransform(BoneIndex) : FTransform::Identity;
		FVector4 BoneSpaceAxis = BoneTM.InverseTransformVectorNoScale(RotAxis);
		FQuat newRotation(BoneSpaceAxis, RotAngle);
		newRotation.Normalize();
		newRotation = newRotation * Collider_RuntimeNode->Transform.GetRotation();
		Collider_RuntimeNode->Transform.SetRotation(newRotation);
		Colldier_GraphNode->Transform.SetRotation(newRotation);
	}
}

void SPCRJointDynamics_Editor::DoScale(FVector& InScale)
{
	if (IsValidColliderIndex() && SPCRAnimGraphNode != nullptr && SPCRRuntimeAnimNode != nullptr)
	{
		UDebugSkelMeshComponent* PreviewMeshComponent = GetAnimPreviewScene().GetPreviewMeshComponent();

		FSPCRJointDynamicsBody* CTransform_RuntimeNode = GetCurrColliderRuntimeNode();
		FSPCRJointDynamicsBody* CTransform_GraphNode = GetCurrColliderGraphNode();

		if (CTransform_RuntimeNode == nullptr || CTransform_GraphNode == nullptr)return;

		FTransform BoneTransform = PreviewMeshComponent->GetBoneTransform(CTransform_RuntimeNode->TargetBone.BoneIndex);

		CTransform_RuntimeNode->Transform.SetScale3D(CTransform_RuntimeNode->Transform.GetScale3D() + InScale);
		CTransform_GraphNode->Transform.SetScale3D(CTransform_RuntimeNode->Transform.GetScale3D());
	}
}

void SPCRJointDynamics_Editor::ExitMode()
{
	SPCRAnimGraphNode = nullptr;
	SPCRRuntimeAnimNode = nullptr;
	SPCRJointDynamics_EditorBase::ExitMode();
}

bool SPCRJointDynamics_Editor::InputDelta(FEditorViewportClient* InViewportClient, FViewport* InViewport, FVector& InDrag, FRotator& InRot, FVector& InScale)
{
	bool result = SPCRJointDynamics_EditorBase::InputDelta(InViewportClient, InViewport, InDrag, InRot, InScale);
	if (SPCRRuntimeAnimNode != nullptr)
		SPCRRuntimeAnimNode->SyncColliderPositions();
	return result;
}

void SPCRJointDynamics_Editor::Render(const FSceneView* View, FViewport* Viewport, FPrimitiveDrawInterface* PDI)
{
	SPCRJointDynamics_EditorBase::Render(View, Viewport, PDI);

	const UDebugSkelMeshComponent* PreviewMeshComponent = GetAnimPreviewScene().GetPreviewMeshComponent();

	if (SPCRRuntimeAnimNode != nullptr)
	{
		const TArray<FSPCRCollider> Colliders = SPCRRuntimeAnimNode->GetColliderArray();
		uint32 BodyCount = FMath::Min(SPCRRuntimeAnimNode->Bodies.Num(), Colliders.Num());

		for (uint32 i = 0; i < BodyCount; ++i)
		{
			const FSPCRCollider& Collider = Colliders[i];
			FSPCRJointDynamicsBody& Body = SPCRRuntimeAnimNode->Bodies[i];
			const FTransform& BoneTransform = PreviewMeshComponent->GetBoneTransform(Body.TargetBone.BoneIndex);
			if (Body.Height > 0)
			{
				RenderCapculeColliders(PDI, Body, i, BoneTransform, Collider.Radius, Collider.Height);
			}
			else
			{
				RenderSphereColliders(PDI, Body, i, BoneTransform, Collider.Radius);
			}
		}

		if (IsValidColliderIndex())
		{
			FSPCRJointDynamicsBody* Body = GetCurrColliderRuntimeNode();
			if (Body != nullptr)
			{
				FTransform BoneTransform = FTransform::Identity;
				if (Body->TargetBone.BoneIndex >= 0)
				{
					const auto& BoneContainer = SPCRRuntimeAnimNode->ForwardedPose.GetPose().GetBoneContainer();
					const FCompactPoseBoneIndex BoneIndex = Body->TargetBone.GetCompactPoseIndex(BoneContainer);
					BoneTransform = SPCRRuntimeAnimNode->ForwardedPose.GetComponentSpaceTransform(BoneIndex);

					if (SelectedColliderIndex < SPCRRuntimeAnimNode->Bodies.Num())
					{
						FTransform BodyJointTransform = SPCRRuntimeAnimNode->Bodies[SelectedColliderIndex].Transform * BoneTransform;
						PDI->DrawPoint(BoneTransform.GetLocation(), FLinearColor::White, 10.0f, SDPG_Foreground);
						DrawDashedLine(PDI, BoneTransform.GetLocation(), BodyJointTransform.GetLocation(), FLinearColor::Gray, 5.0f, SDPG_Foreground);
					}
				}
			}
		}
	}
}

bool SPCRJointDynamics_Editor::HandleClick(FEditorViewportClient* InViewportClient, HHitProxy* HitProxy, const FViewportClick& Click)
{
	return SPCRJointDynamics_EditorBase::HandleClick(InViewportClient, HitProxy, Click);
}

void SPCRJointDynamics_Editor::RenderCapculeColliders(FPrimitiveDrawInterface* PDI, FSPCRJointDynamicsBody& Collider, const int ColliderIndex, const FTransform& BoneTransform, const float Radius, const float Height)
{
	FTransform BodyJointTransform = Collider.Transform * BoneTransform;

	FVector Position = BodyJointTransform.GetLocation();
	FQuat Rotation = BodyJointTransform.GetRotation();

	FVector XAxis = Rotation.GetAxisX();
	FVector YAxis = Rotation.GetAxisY();
	FVector ZAxis = Rotation.GetAxisZ();

	PDI->SetHitProxy(new HSPCRColliderHitProxy(ColliderIndex));

	DrawCylinder(PDI, Position, XAxis, YAxis, ZAxis, Radius, Height * 0.5f, 25,
		GEngine->ConstraintLimitMaterialPrismatic->GetRenderProxy(), SDPG_World);
	DrawSphere(PDI, Position + ZAxis * Height * 0.5f, Rotation.Rotator(), FVector(Radius),
		24, 6, GEngine->ConstraintLimitMaterialPrismatic->GetRenderProxy(), SDPG_World);
	DrawSphere(PDI, Position - ZAxis * Height * 0.5f, Rotation.Rotator(), FVector(Radius),
		24, 6, GEngine->ConstraintLimitMaterialPrismatic->GetRenderProxy(), SDPG_World);

	DrawWireCapsule(PDI, Position, XAxis, YAxis, ZAxis,
		FLinearColor::Black, Radius, 0.5f * Height + Radius, 25, SDPG_World);

	DrawCoordinateSystem(PDI, Position, Rotation.Rotator(), Radius, SDPG_Foreground);
}

void SPCRJointDynamics_Editor::RenderSphereColliders(FPrimitiveDrawInterface* PDI, FSPCRJointDynamicsBody& Collider, const int ColliderIndex, const FTransform& BoneTransform, const float Radius)
{
	FTransform BodyJointTransform = Collider.Transform * BoneTransform;

	FVector Position = BodyJointTransform.GetLocation();
	FRotator Rotation = BodyJointTransform.GetRotation().Rotator();

	PDI->SetHitProxy(new HSPCRColliderHitProxy(ColliderIndex));

	DrawSphere(PDI, Position, Rotation, FVector(Radius),
		24, 6, GEngine->ConstraintLimitMaterialPrismatic->GetRenderProxy(), SDPG_World);
	DrawWireSphere(PDI, Position, FLinearColor::Black, Radius, 24, SDPG_World);

	DrawCoordinateSystem(PDI, Position, Rotation, Radius, SDPG_Foreground);
}

FVector SPCRJointDynamics_Editor::GetWidgetLocation() const
{
	if (IsValidColliderIndex())
	{
		if (SelectedColliderIndex < SPCRRuntimeAnimNode->Bodies.Num())
		{
			UDebugSkelMeshComponent* PreviewMeshComponent = GetAnimPreviewScene().GetPreviewMeshComponent();
			const FSPCRJointDynamicsBody& Body = SPCRRuntimeAnimNode->Bodies[SelectedColliderIndex];

			FTransform BodyJointTransform = Body.Transform * PreviewMeshComponent->GetBoneTransform(Body.TargetBone.BoneIndex);
			return BodyJointTransform.GetLocation();
		}
	}

	return FEdMode::GetWidgetLocation();
}

bool SPCRJointDynamics_Editor::GetCustomDrawingCoordinateSystem(FMatrix& InMatrix, void* InData)
{
	if (!IsValidColliderIndex() || SPCRAnimGraphNode == nullptr || SPCRRuntimeAnimNode == nullptr)
	{
		return false;
	}

	FSPCRJointDynamicsBody* CTransform_RuntimeNode = GetCurrColliderRuntimeNode();
	UDebugSkelMeshComponent* PreviewMeshComponent = GetAnimPreviewScene().GetPreviewMeshComponent();

	if (CTransform_RuntimeNode == nullptr || PreviewMeshComponent == nullptr)return false;

	FTransform BoneTransform = PreviewMeshComponent->GetBoneTransform(CTransform_RuntimeNode->TargetBone.BoneIndex);
	FQuat Rotation = BoneTransform.GetRotation() * CTransform_RuntimeNode->Transform.GetRotation();
	InMatrix = FTransform(Rotation).ToMatrixNoScale();
	return true;
}

void SPCRJointDynamics_Editor::DrawHUD(FEditorViewportClient* ViewportClient, FViewport* Viewport, const FSceneView* View, FCanvas* Canvas)
{
	const UFont* Font = GEngine->GetSmallFont();
	float CharWidth, CharHeight;
	Font->GetCharSize('O', CharWidth, CharHeight);
	FVector2D TextPosition(0.0f, 0.0f);
	TextPosition.X = 15.0;
	TextPosition.Y = Viewport->GetSizeXY().Y - 220.0;

	FString TempString("-------- SPCR Joint Dynamics Info --------");

	DrawHUDText(Canvas, Font, CharHeight, FText::FromString(TempString), TextPosition);

	ECoordSystem CoordSystem = GetModeManager()->GetCoordSystem();

	if (IsValidColliderIndex())
	{
		FSPCRJointDynamicsBody* collider = GetCurrColliderRuntimeNode();
		if (collider != nullptr)
		{
			FString colliderType = collider->Height > 0.0f ? "Capsule" : "Sphere";
			TempString = colliderType + " [" + FString::FromInt(SelectedColliderIndex) + "]";
		}
		else
		{
			SelectedColliderIndex = SPCR_INVALID_COLLIDER_INDEX;
			TempString = "NONE";
		}
	}
	else
	{
		TempString = "NONE";
	}
	DrawHUDText(Canvas, Font, CharHeight, FText::FromString(FString("Collider : ") + TempString), TextPosition);

	TempString = (CoordSystem == ECoordSystem::COORD_Local) ? "Local Space" : "World Space";
	DrawHUDText(Canvas, Font, CharHeight, FText::FromString(FString("(Q) Coord System : ") + TempString), TextPosition);

	DrawHUDText(Canvas, Font, CharHeight, FText::FromString(FString("--------------------")), TextPosition);
	DrawHUDText(Canvas, Font, CharHeight, FText::FromString(FString("(W) Transform")), TextPosition);
	DrawHUDText(Canvas, Font, CharHeight, FText::FromString(FString("(E) Rotate")), TextPosition);
	DrawHUDText(Canvas, Font, CharHeight, FText::FromString(FString("(R) Scale")), TextPosition);
	DrawHUDText(Canvas, Font, CharHeight, FText::FromString(FString("(Space) switch [Transform->Rotate->Scale]")), TextPosition);
}

void SPCRJointDynamics_Editor::DrawHUDText(FCanvas* Canvas, const UFont* Font, const float& charHeight, FText Text, FVector2D& TextPosition)
{
	FCanvasTextItem TextItem(TextPosition, Text, Font, FLinearColor::Black);
	Canvas->DrawItem(TextItem);
	TextPosition.Y += charHeight * 1.2f/*Offset factor*/;
}

FSPCRJointDynamicsBody* SPCRJointDynamics_Editor::GetCurrColliderRuntimeNode()
{
	if (!IsValidColliderIndex()) return nullptr;
	if (SPCRRuntimeAnimNode->Bodies.Num() <= SelectedColliderIndex) return nullptr;
	return &SPCRRuntimeAnimNode->Bodies[SelectedColliderIndex];
}

FSPCRJointDynamicsBody* SPCRJointDynamics_Editor::GetCurrColliderGraphNode()
{
	if (!IsValidColliderIndex()) return nullptr;
	if (SPCRAnimGraphNode->Node.Bodies.Num() <= SelectedColliderIndex) return nullptr;
	return &SPCRAnimGraphNode->Node.Bodies[SelectedColliderIndex];
}

