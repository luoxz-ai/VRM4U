﻿// VRM4U Copyright (c) 2021-2024 Haruyoshi Yamamoto. This software is released under the MIT License.

#include "VrmUtil.h"

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "VrmAssetListObject.h"
#include "VrmMetaObject.h"


void FImportOptionData::init() {
}



const TArray<VRMUtil::VRMBoneTable> VRMUtil::table_ue4_vrm = {
	{"Root",""},
	{"Pelvis","hips"},
	{"spine_01","spine"},
	{"spine_02","chest"},
	{"spine_03","upperChest"},
	{"clavicle_l","leftShoulder"},
	{"UpperArm_L","leftUpperArm"},
	{"lowerarm_l","leftLowerArm"},
	{"Hand_L","leftHand"},
	{"index_01_l","leftIndexProximal"},
	{"index_02_l","leftIndexIntermediate"},
	{"index_03_l","leftIndexDistal"},
	{"middle_01_l","leftMiddleProximal"},
	{"middle_02_l","leftMiddleIntermediate"},
	{"middle_03_l","leftMiddleDistal"},
	{"pinky_01_l","leftLittleProximal"},
	{"pinky_02_l","leftLittleIntermediate"},
	{"pinky_03_l","leftLittleDistal"},
	{"ring_01_l","leftRingProximal"},
	{"ring_02_l","leftRingIntermediate"},
	{"ring_03_l","leftRingDistal"},
	{"thumb_01_l","leftThumbProximal"},
	{"thumb_02_l","leftThumbIntermediate"},
	{"thumb_03_l","leftThumbDistal"},
	{"lowerarm_twist_01_l",""},
	{"upperarm_twist_01_l",""},
	{"clavicle_r","rightShoulder"},
	{"UpperArm_R","rightUpperArm"},
	{"lowerarm_r","rightLowerArm"},
	{"Hand_R","rightHand"},
	{"index_01_r","rightIndexProximal"},
	{"index_02_r","rightIndexIntermediate"},
	{"index_03_r","rightIndexDistal"},
	{"middle_01_r","rightMiddleProximal"},
	{"middle_02_r","rightMiddleIntermediate"},
	{"middle_03_r","rightMiddleDistal"},
	{"pinky_01_r","rightLittleProximal"},
	{"pinky_02_r","rightLittleIntermediate"},
	{"pinky_03_r","rightLittleDistal"},
	{"ring_01_r","rightRingProximal"},
	{"ring_02_r","rightRingIntermediate"},
	{"ring_03_r","rightRingDistal"},
	{"thumb_01_r","rightThumbProximal"},
	{"thumb_02_r","rightThumbIntermediate"},
	{"thumb_03_r","rightThumbDistal"},
	{"lowerarm_twist_01_r",""},
	{"upperarm_twist_01_r",""},
	{"neck_01","neck"},
	{"head","head"},
	{"Thigh_L","leftUpperLeg"},
	{"calf_l","leftLowerLeg"},
	{"calf_twist_01_l",""},
	{"Foot_L","leftFoot"},
	{"ball_l","leftToes"},
	{"thigh_twist_01_l",""},
	{"Thigh_R","rightUpperLeg"},
	{"calf_r","rightLowerLeg"},
	{"calf_twist_01_r",""},
	{"Foot_R","rightFoot"},
	{"ball_r","rightToes"},
	{"thigh_twist_01_r",""},
	{"ik_foot_root",""},
	{"ik_foot_l",""},
	{"ik_foot_r",""},
	{"ik_hand_root",""},
	{"ik_hand_gun",""},
	{"ik_hand_l",""},
	{"ik_hand_r",""},
	{"Custom_1",""},
	{"Custom_2",""},
	{"Custom_3",""},
	{"Custom_4",""},
	{"Custom_5",""},
};

const TArray<VRMUtil::VRMBoneTable> VRMUtil::table_ue4_pmx = {
	{"Root",TEXT("全ての親")},
	{"Pelvis",TEXT("センター")},
	{"spine_01",TEXT("上半身")},
	{"spine_02",TEXT("上半身")},
	{"spine_03",TEXT("上半身2")},
	{"clavicle_l",TEXT("左肩")},
	{"UpperArm_L",TEXT("左腕")},
	{"lowerarm_l",TEXT("左ひじ")},
	{"Hand_L",TEXT("左手首")},
	{"index_01_l",TEXT("左人指１")},
	{"index_02_l",TEXT("左人指２")},
	{"index_03_l",TEXT("左人指３")},
	{"middle_01_l",TEXT("左中指１")},
	{"middle_02_l",TEXT("左中指２")},
	{"middle_03_l",TEXT("左中指３")},
	{"pinky_01_l",TEXT("左小指１")},
	{"pinky_02_l",TEXT("左小指２")},
	{"pinky_03_l",TEXT("左小指３")},
	{"ring_01_l",TEXT("左薬指１")},
	{"ring_02_l",TEXT("左薬指２")},
	{"ring_03_l",TEXT("左薬指３")},
	{"thumb_01_l",TEXT("左親指０")},
	{"thumb_02_l",TEXT("左親指１")},
	{"thumb_03_l",TEXT("左親指２")},
	{"lowerarm_twist_01_l",TEXT("")},
	{"upperarm_twist_01_l",TEXT("")},
	{"clavicle_r",TEXT("右肩")},
	{"UpperArm_R",TEXT("右腕")},
	{"lowerarm_r",TEXT("右ひじ")},
	{"Hand_R",TEXT("右手首")},
	{"index_01_r",TEXT("右人指１")},
	{"index_02_r",TEXT("右人指２")},
	{"index_03_r",TEXT("右人指３")},
	{"middle_01_r",TEXT("右中指１")},
	{"middle_02_r",TEXT("右中指２")},
	{"middle_03_r",TEXT("右中指３")},
	{"pinky_01_r",TEXT("右小指１")},
	{"pinky_02_r",TEXT("右小指２")},
	{"pinky_03_r",TEXT("右小指３")},
	{"ring_01_r",TEXT("右薬指１")},
	{"ring_02_r",TEXT("右薬指２")},
	{"ring_03_r",TEXT("右薬指３")},
	{"thumb_01_r",TEXT("右親指０")},
	{"thumb_02_r",TEXT("右親指１")},
	{"thumb_03_r",TEXT("右親指２")},
	{"lowerarm_twist_01_r",TEXT("")},
	{"upperarm_twist_01_r",TEXT("")},
	{"neck_01",TEXT("首")},
	{"head",TEXT("頭")},
	{"Thigh_L",TEXT("左足")},
	{"calf_l",TEXT("左ひざ")},
	{"calf_twist_01_l",TEXT("")},
	{"Foot_L",TEXT("左足首")},
	{"ball_l",TEXT("左つま先")},
	{"thigh_twist_01_l",TEXT("")},
	{"Thigh_R",TEXT("右足")},
	{"calf_r",TEXT("右ひざ")},
	{"calf_twist_01_r",TEXT("")},
	{"Foot_R",TEXT("右足首")},
	{"ball_r",TEXT("右つま先")},
	{"thigh_twist_01_r",TEXT("")},
	{"ik_foot_root",TEXT("")},
	{"ik_foot_l",TEXT("")},
	{"ik_foot_r",TEXT("")},
	{"ik_hand_root",TEXT("")},
	{"ik_hand_gun",TEXT("")},
	{"ik_hand_l",TEXT("")},
	{"ik_hand_r",TEXT("")},
	{"Custom_1",TEXT("")},
	{"Custom_2",TEXT("")},
	{"Custom_3",TEXT("")},
	{"Custom_4",TEXT("")},
	{"Custom_5",TEXT("")},
};

bool VRMUtil::GetReplacedPMXBone(FString& replaced, const FString& base){
	bool ret = false;
	replaced = base;

	struct Table{
		FString a;
		FString b;
	};
	const Table t[] = {
		{TEXT("左足"),		TEXT("左足D")},
		{TEXT("左ひざ"),		TEXT("左ひざD")},
		{TEXT("左足首"),		TEXT("左足首D")},
		{TEXT("左つま先"),	TEXT("左足先EX")},

		{TEXT("右足"),		TEXT("右足D")},
		{TEXT("右ひざ"),		TEXT("右ひざD")},
		{TEXT("右足首"),		TEXT("右足首D")},
		{TEXT("右つま先"),	TEXT("右足先EX")},

		{TEXT("センター"),	TEXT("腰")},
	};

	for (auto &a : t) {
		if (base.Compare(a.a) == 0) {
			replaced = a.b;
			return true;
		}
	}
	return false;
}


const TArray<FString> VRMUtil::vrm_humanoid_bone_list = {
	"hips",
	"leftUpperLeg",
	"rightUpperLeg",
	"leftLowerLeg",
	"rightLowerLeg",
	"leftFoot",
	"rightFoot",
	"spine",
	"chest",
	"neck",
	"head",
	"leftShoulder",
	"rightShoulder",
	"leftUpperArm",
	"rightUpperArm",
	"leftLowerArm",
	"rightLowerArm",
	"leftHand",
	"rightHand",
	"leftToes",
	"rightToes",
	"leftEye",
	"rightEye",
	"jaw",
	"leftThumbProximal",
	"leftThumbIntermediate",
	"leftThumbDistal",
	"leftIndexProximal",
	"leftIndexIntermediate",
	"leftIndexDistal",
	"leftMiddleProximal",
	"leftMiddleIntermediate",
	"leftMiddleDistal",
	"leftRingProximal",
	"leftRingIntermediate",
	"leftRingDistal",
	"leftLittleProximal",
	"leftLittleIntermediate",
	"leftLittleDistal",
	"rightThumbProximal",
	"rightThumbIntermediate",
	"rightThumbDistal",
	"rightIndexProximal",
	"rightIndexIntermediate",
	"rightIndexDistal",
	"rightMiddleProximal",
	"rightMiddleIntermediate",
	"rightMiddleDistal",
	"rightRingProximal",
	"rightRingIntermediate",
	"rightRingDistal",
	"rightLittleProximal",
	"rightLittleIntermediate",
	"rightLittleDistal",
	"upperChest"
};

const TArray<FName> VRMUtil::vrm_humanoid_bone_list_name = {
	"hips",
	"leftUpperLeg",
	"rightUpperLeg",
	"leftLowerLeg",
	"rightLowerLeg",
	"leftFoot",
	"rightFoot",
	"spine",
	"chest",
	"neck",
	"head",
	"leftShoulder",
	"rightShoulder",
	"leftUpperArm",
	"rightUpperArm",
	"leftLowerArm",
	"rightLowerArm",
	"leftHand",
	"rightHand",
	"leftToes",
	"rightToes",
	"leftEye",
	"rightEye",
	"jaw",
	"leftThumbProximal",	// 24
	"leftThumbIntermediate",
	"leftThumbDistal",
	"leftIndexProximal",
	"leftIndexIntermediate",
	"leftIndexDistal",
	"leftMiddleProximal",
	"leftMiddleIntermediate",
	"leftMiddleDistal",
	"leftRingProximal",
	"leftRingIntermediate",
	"leftRingDistal",
	"leftLittleProximal",
	"leftLittleIntermediate",
	"leftLittleDistal",
	"rightThumbProximal",
	"rightThumbIntermediate",
	"rightThumbDistal",
	"rightIndexProximal",
	"rightIndexIntermediate",
	"rightIndexDistal",
	"rightMiddleProximal",
	"rightMiddleIntermediate",
	"rightMiddleDistal",
	"rightRingProximal",
	"rightRingIntermediate",
	"rightRingDistal",
	"rightLittleProximal",
	"rightLittleIntermediate",
	"rightLittleDistal",
	"upperChest"
};


const TArray<FString> VRMUtil::vrm_humanoid_parent_list = {
	"", //"hips",
	"hips",//"leftUpperLeg",
	"hips",//"rightUpperLeg",
	"leftUpperLeg",//"leftLowerLeg",
	"rightUpperLeg",//"rightLowerLeg",
	"leftLowerLeg",//"leftFoot",
	"rightLowerLeg",//"rightFoot",
	"hips",//"spine",
	"spine",//"chest",
	"chest",//"neck",
	"neck",//"head",
	"chest",//"leftShoulder",			// <-- upper..
	"chest",//"rightShoulder",
	"leftShoulder",//"leftUpperArm",
	"rightShoulder",//"rightUpperArm",
	"leftUpperArm",//"leftLowerArm",
	"rightUpperArm",//"rightLowerArm",
	"leftLowerArm",//"leftHand",
	"rightLowerArm",//"rightHand",
	"leftFoot",//"leftToes",
	"rightFoot",//"rightToes",
	"head",//"leftEye",
	"head",//"rightEye",
	"head",//"jaw",
	"leftHand",//"leftThumbProximal",
	"leftThumbProximal",//"leftThumbIntermediate",
	"leftThumbIntermediate",//"leftThumbDistal",
	"leftHand",//"leftIndexProximal",
	"leftIndexProximal",//"leftIndexIntermediate",
	"leftIndexIntermediate",//"leftIndexDistal",
	"leftHand",//"leftMiddleProximal",
	"leftMiddleProximal",//"leftMiddleIntermediate",
	"leftMiddleIntermediate",//"leftMiddleDistal",
	"leftHand",//"leftRingProximal",
	"leftRingProximal",//"leftRingIntermediate",
	"leftRingIntermediate",//"leftRingDistal",
	"leftHand",//"leftLittleProximal",
	"leftLittleProximal",//"leftLittleIntermediate",
	"leftLittleIntermediate",//"leftLittleDistal",
	"rightHand",//"rightThumbProximal",
	"rightThumbProximal",//"rightThumbIntermediate",
	"rightThumbIntermediate",//"rightThumbDistal",
	"rightHand",//"rightIndexProximal",
	"rightIndexProximal",//"rightIndexIntermediate",
	"rightIndexIntermediate",//"rightIndexDistal",
	"rightHand",//"rightMiddleProximal",
	"rightMiddleProximal",//"rightMiddleIntermediate",
	"rightMiddleIntermediate",//"rightMiddleDistal",
	"rightHand",//"rightRingProximal",
	"rightRingProximal",//"rightRingIntermediate",
	"rightRingIntermediate",//"rightRingDistal",
	"rightHand",//"rightLittleProximal",
	"rightLittleProximal",//"rightLittleIntermediate",
	"rightLittleIntermediate",//"rightLittleDistal",
	"chest",//"upperChest"
};

//

const TArray<FString> VRMUtil::ue4_humanoid_bone_list = {
	"Root",
	"Pelvis",
	"spine_01",
	"spine_02",
	"spine_03",
	"clavicle_l",
	"UpperArm_L",
	"lowerarm_l",
	"Hand_L","leftHand",
	"index_01_l",
	"index_02_l",
	"index_03_l",
	"middle_01_l",
	"middle_02_l",
	"middle_03_l",
	"pinky_01_l",
	"pinky_02_l",
	"pinky_03_l",
	"ring_01_l",
	"ring_02_l",
	"ring_03_l",
	"thumb_01_l",
	"thumb_02_l",
	"thumb_03_l",
	"lowerarm_twist_01_l",
	"upperarm_twist_01_l",
	"clavicle_r",
	"UpperArm_R",
	"lowerarm_r",
	"Hand_R",
	"index_01_r",
	"index_02_r",
	"index_03_r",
	"middle_01_r",
	"middle_02_r",
	"middle_03_r",
	"pinky_01_r",
	"pinky_02_r",
	"pinky_03_r",
	"ring_01_r",
	"ring_02_r",
	"ring_03_r",
	"thumb_01_r",
	"thumb_02_r",
	"thumb_03_r",
	"lowerarm_twist_01_r",
	"upperarm_twist_01_r",
	"neck_01",
	"head",
	"Thigh_L",
	"calf_l",
	"calf_twist_01_l",
	"Foot_L",
	"ball_l",
	"thigh_twist_01_l",
	"Thigh_R",
	"calf_r",
	"calf_twist_01_r",
	"Foot_R",
	"ball_r",
	"thigh_twist_01_r",
	"ik_foot_root",
	"ik_foot_l",
	"ik_foot_r",
	"ik_hand_root",
	"ik_hand_gun",
	"ik_hand_l",
	"ik_hand_r",
	"Custom_1",
	"Custom_2",
	"Custom_3",
	"Custom_4",
	"Custom_5",
};

const TArray<FName> VRMUtil::ue4_humanoid_bone_list_name = {
	"Root",
	"Pelvis",
	"spine_01",
	"spine_02",
	"spine_03",
	"clavicle_l",
	"UpperArm_L",
	"lowerarm_l",
	"Hand_L","leftHand",
	"index_01_l",
	"index_02_l",
	"index_03_l",
	"middle_01_l",
	"middle_02_l",
	"middle_03_l",
	"pinky_01_l",
	"pinky_02_l",
	"pinky_03_l",
	"ring_01_l",
	"ring_02_l",
	"ring_03_l",
	"thumb_01_l",
	"thumb_02_l",
	"thumb_03_l",
	"lowerarm_twist_01_l",
	"upperarm_twist_01_l",
	"clavicle_r",
	"UpperArm_R",
	"lowerarm_r",
	"Hand_R",
	"index_01_r",
	"index_02_r",
	"index_03_r",
	"middle_01_r",
	"middle_02_r",
	"middle_03_r",
	"pinky_01_r",
	"pinky_02_r",
	"pinky_03_r",
	"ring_01_r",
	"ring_02_r",
	"ring_03_r",
	"thumb_01_r",
	"thumb_02_r",
	"thumb_03_r",
	"lowerarm_twist_01_r",
	"upperarm_twist_01_r",
	"neck_01",
	"head",
	"Thigh_L",
	"calf_l",
	"calf_twist_01_l",
	"Foot_L",
	"ball_l",
	"thigh_twist_01_l",
	"Thigh_R",
	"calf_r",
	"calf_twist_01_r",
	"Foot_R",
	"ball_r",
	"thigh_twist_01_r",
	"ik_foot_root",
	"ik_foot_l",
	"ik_foot_r",
	"ik_hand_root",
	"ik_hand_gun",
	"ik_hand_l",
	"ik_hand_r",
	"Custom_1",
	"Custom_2",
	"Custom_3",
	"Custom_4",
	"Custom_5",
};

#if	UE_VERSION_OLDER_THAN(5,0,0)

#elif UE_VERSION_OLDER_THAN(5,2,0)

#include "IKRigDefinition.h"
#include "IKRigSolver.h"
#if WITH_EDITOR
#include "RigEditor/IKRigController.h"
#include "RetargetEditor/IKRetargeterController.h"
#include "Retargeter/IKRetargeter.h"
#include "Solvers/IKRig_PBIKSolver.h"
#endif

#elif UE_VERSION_OLDER_THAN(5,3,0)

#include "IKRigDefinition.h"
#include "IKRigSolver.h"
#if WITH_EDITOR
#include "RigEditor/IKRigController.h"
#include "RetargetEditor/IKRetargeterController.h"
#include "Retargeter/IKRetargeter.h"
#endif

#else

#include "Rig/IKRigDefinition.h"
#include "Rig/Solvers/IKRigSolver.h"
#if WITH_EDITOR
#include "RigEditor/IKRigController.h"
#include "RetargetEditor/IKRetargeterController.h"
#include "Retargeter/IKRetargeter.h"
#endif

#endif


#if	UE_VERSION_OLDER_THAN(5,0,0)
#else

void VRMAddRetargetChain(UIKRigController* con, FName name, FName begin, FName end) {
#if WITH_EDITOR
#if	UE_VERSION_OLDER_THAN(5,1,0)
	con->AddRetargetChain(name, begin, end);
#else
	FBoneChain c;
	FBoneReference r1, r2;
	r1.BoneName = begin;
	r2.BoneName = end;

	auto k = con->GetAsset()->GetPreviewMesh()->GetSkeleton();

	r1.Initialize(k);
	r2.Initialize(k);

	c.ChainName = name;
	c.StartBone = r1;
	c.EndBone = r2;
#if	UE_VERSION_OLDER_THAN(5,4,0)
	con->AddRetargetChain(c);
#else
	con->AddRetargetChain(name, begin, end, NAME_None);
#endif

#endif
#endif
}

#endif


void VRMRetargetData::Remove(FString BoneUE4) {
	for (auto r : retargetTable) {
		if (BoneUE4.Compare(r.BoneUE4, ESearchCase::IgnoreCase) == 0) {
			retargetTable.Remove(r);
			return;
		}
	}
}

void VRMRetargetData::Setup(UVrmAssetListObject* InVrmAssetList, bool bVRM, bool bBVH, bool bPMX) {
	vrmAssetList = InVrmAssetList;
	if (bVRM || bBVH) {
		{
			RetargetParts t;
			t.BoneUE4 = TEXT("UpperArm_R");
			t.rot = FRotator(50, 0, 0);
			retargetTable.Push(t);

			t.BoneUE4 = TEXT("UpperArm_L");
			t.rot = FRotator(-50, 0, 0);
			retargetTable.Push(t);

			t.BoneUE4 = TEXT("lowerarm_r");
			t.rot = FRotator(0, -30, 0);
			retargetTable.Push(t);

			t.BoneUE4 = TEXT("lowerarm_l");
			t.rot = FRotator(0, 30, 0);
			retargetTable.Push(t);
		}
		{
			RetargetParts t;
			t.BoneUE4 = TEXT("Hand_R");
			t.rot = FRotator(0, 0, 0);
			retargetTable.Push(t);

			t.BoneUE4 = TEXT("Hand_L");
			t.rot = FRotator(0, 0, 0);
			retargetTable.Push(t);
		}

		{
			RetargetParts t;
			t.BoneUE4 = TEXT("pinky_01_r");
			t.rot = FRotator(18, 12, 0);
			retargetTable.Push(t);

			t.BoneUE4 = TEXT("pinky_01_l");
			t.rot = FRotator(-18, -12, 0);
			retargetTable.Push(t);

			t.BoneUE4 = TEXT("ring_01_r");
			t.rot = FRotator(18, 6, 0);
			retargetTable.Push(t);

			t.BoneUE4 = TEXT("ring_01_l");
			t.rot = FRotator(-18, -6, 0);
			retargetTable.Push(t);

			t.BoneUE4 = TEXT("index_01_r");
			t.rot = FRotator(20, -6, 0);
			retargetTable.Push(t);

			t.BoneUE4 = TEXT("index_01_l");
			t.rot = FRotator(-20, 6, 0);
			retargetTable.Push(t);

			t.BoneUE4 = TEXT("middle_01_r");
			t.rot = FRotator(20, 0, 0);
			retargetTable.Push(t);

			t.BoneUE4 = TEXT("middle_01_l");
			t.rot = FRotator(-20, 0, 0);
			retargetTable.Push(t);


			t.BoneUE4 = TEXT("thumb_01_r");
			t.rot = FRotator(0, 8, 20);
			retargetTable.Push(t);

			t.BoneUE4 = TEXT("thumb_01_l");
			t.rot = FRotator(0, -8, 20);
			retargetTable.Push(t);

			{
				FString tmpTable[] = {
					//"index_01_r",
					"index_02_r",
					"index_03_r",
					//"middle_01_r",
					"middle_02_r",
					"middle_03_r",
				};
				for (auto& a : tmpTable) {
					t.BoneUE4 = a;
					t.rot = FRotator(20, 0, 0);
					retargetTable.Push(t);

					t.BoneUE4 = a.Replace(TEXT("_r"), TEXT("_l"));
					t.rot = FRotator(-20, 0, 0);
					retargetTable.Push(t);
				}
			}
			{

				FString tmpTable[] = {
					"ring_02_r",
					"ring_03_r",
					//"pinky_01_r",
					"pinky_02_r",
					"pinky_03_r",
				};
				for (auto& a : tmpTable) {
					t.BoneUE4 = a;
					t.rot = FRotator(18, 0, 0);
					retargetTable.Push(t);

					t.BoneUE4 = a.Replace(TEXT("_r"), TEXT("_l"));
					t.rot = FRotator(-18, 0, 0);
					retargetTable.Push(t);
				}
			}
			{
				FString tmpTable[] = {
					//"thumb_01_r",
					"thumb_02_r",
					"thumb_03_r",
				};
				for (auto& a : tmpTable) {
					t.BoneUE4 = a;
					t.rot = FRotator(0, 10, 0);
					retargetTable.Push(t);

					t.BoneUE4 = a.Replace(TEXT("_r"), TEXT("_l"));
					t.rot = FRotator(0, -10, 0);
					retargetTable.Push(t);
				}
			}
		}
	} // vrm, bvh

	if (bPMX) {
		{
			RetargetParts t;
			t.BoneUE4 = TEXT("lowerarm_r");
			t.rot = FRotator(0, -30, 0);
			retargetTable.Push(t);

			t.BoneUE4 = TEXT("Hand_R");
			t.rot = FRotator(10, 0, 0);
			retargetTable.Push(t);
		}
		{
			RetargetParts t;
			t.BoneUE4 = TEXT("lowerarm_l");
			t.rot = FRotator(-0, 30, 0);
			retargetTable.Push(t);

			t.BoneUE4 = TEXT("Hand_L");
			t.rot = FRotator(-10, 0, 0);
			retargetTable.Push(t);
		}
	}
	// foot
	{
		RetargetParts t;
		t.BoneUE4 = TEXT("Thigh_R");
		t.rot = FRotator(-5, 0, 0);
		retargetTable.Push(t);

		t.BoneUE4 = TEXT("Thigh_L");
		t.rot = FRotator(5, 0, 0);
		retargetTable.Push(t);

		t.BoneUE4 = TEXT("calf_r");
		t.rot = FRotator(0, 0, 5);
		retargetTable.Push(t);

		t.BoneUE4 = TEXT("calf_l");
		t.rot = FRotator(0, 0, 5);
		retargetTable.Push(t);

		t.BoneUE4 = TEXT("Foot_R");
		t.rot = FRotator(5, 0, -5);
		retargetTable.Push(t);

		t.BoneUE4 = TEXT("Foot_L");
		t.rot = FRotator(-5, 0, -5);
		retargetTable.Push(t);
	}

	UpdateBoneName();
}

void VRMRetargetData::UpdateBoneName() {

#pragma warning(push)
#pragma warning(disable: 4702)
	for (auto& a : retargetTable) {
		bool bFound = false;
		//vrm
		for (auto& t : VRMUtil::table_ue4_vrm) {
			if (t.BoneUE4.Compare(a.BoneUE4) != 0) {
				continue;
			}
			auto* m = vrmAssetList->VrmMetaObject->humanoidBoneTable.Find(t.BoneVRM);
			if (m) {
				bFound = true;
				a.BoneVRM = t.BoneVRM;
				a.BoneModel = *m;
			}
			break;
		}
		if (bFound) {
			continue;
		}
#if	UE_VERSION_OLDER_THAN(5,4,0)
		//pmx
		for (auto& t : VRMUtil::table_ue4_pmx) {
			if (t.BoneUE4.Compare(a.BoneUE4) != 0) {
				continue;
			}
			FString pmxBone;
			VRMUtil::GetReplacedPMXBone(pmxBone, t.BoneVRM);

			FString target[2] = {
				pmxBone,
				t.BoneVRM,
			};
			bool finish = false;
			for (int i = 0; i < 2; ++i) {
				auto* m = vrmAssetList->VrmMetaObject->humanoidBoneTable.Find(target[i]);
				if (m) {
					bFound = true;
					a.BoneVRM = target[i];
					a.BoneModel = *m;
				}
				finish = true;
				break;
			}

			if (finish) break;
		}
#endif
		if (bFound) {
			continue;
		}
	}
#pragma warning(pop)
}



int32 VRMUtil::GetDirectChildBones(FReferenceSkeleton& refs, int32 ParentBoneIndex, TArray<int32>& Children) {
	Children.Reset();

	const int32 NumBones = refs.GetNum();
	for (int32 ChildIndex = ParentBoneIndex + 1; ChildIndex < NumBones; ChildIndex++)
	{
		if (ParentBoneIndex == refs.GetParentIndex(ChildIndex))
		{
			Children.Add(ChildIndex);
		}
	}

	return Children.Num();
}
