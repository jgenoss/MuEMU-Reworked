#include "stdafx.h"
#include "MemScript.h"
#include "Util.h"
#include "Defines.h"
#include "Reconnect.h"
#include "CustomMonster.h"
#include "CustomNpcName.h"
#include "Import.h"
#include "Defines.h"
#include "TMemory.h"
#include "Item.h"
#include "User.h"
#include "Pet.h"

CCustomMonster gCustomMonster;

CCustomMonster::CCustomMonster()
{
	this->Init();
}

CCustomMonster::~CCustomMonster()
{

}

void CCustomMonster::Init()
{
	for (int i = 0; i<MAX_CUSTOMMONSTER; i++)
	{
		this->m_CustomMonster[i].Index = -1;
	}
	//======Bosss Class
	for (int i = 0; i<MAX_BOSSCLASS; i++)
	{
		this->m_CustomBossClass[i].Index = -1;
	}
	memset(this->m_NpcName, 0, sizeof(this->m_NpcName));
}
//===============Boss Class
void CCustomMonster::LoadBossClass(BOSSCLASS_DATA* info)
{
	for (int i = 0; i<MAX_BOSSCLASS; i++)
	{
		this->SetInfoBossClass(info[i]);
	}
}

void CCustomMonster::SetInfoBossClass(BOSSCLASS_DATA info)
{
	if (info.Index < 0 || info.Index >= MAX_BOSSCLASS)
	{
		return;
	}

	this->m_CustomBossClass[info.Index] = info;
}

BOSSCLASS_DATA* CCustomMonster::GetInfoByIDBoss(int MonsterID)
{
	for (int n = 0; n < MAX_BOSSCLASS; n++)
	{
		BOSSCLASS_DATA* lpInfo = this->GetInfoBossByIndex(n);

		if (lpInfo == 0)
		{
			continue;
		}

		if (MonsterID == lpInfo->ID)
		{
			return lpInfo;
		}
	}

	return 0;
}
BOSSCLASS_DATA* CCustomMonster::GetInfoBossByIndex(int index)
{
	if (index < 0 || index >= MAX_BOSSCLASS)
	{
		return 0;
	}

	if (this->m_CustomBossClass[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomBossClass[index];
}
//=======================
void CCustomMonster::Load(CUSTOMMONSTER_DATA* info)
{
	for (int i = 0; i<MAX_CUSTOMMONSTER; i++)
	{
		this->SetInfo(info[i]);
	}
}



void CCustomMonster::SetInfo(CUSTOMMONSTER_DATA info)
{
	if (info.Index < 0 || info.Index >= MAX_CUSTOMMONSTER)
	{
		return;
	}

	this->m_CustomMonster[info.Index] = info;
}

CUSTOMMONSTER_DATA* CCustomMonster::GetInfoByMonsterID(int MonsterID)
{
	for (int n = 0; n < MAX_CUSTOMMONSTER; n++)
	{
		CUSTOMMONSTER_DATA* lpInfo = this->GetInfoByIndex(n);

		if (lpInfo == 0)
		{
			continue;
		}

		if (MonsterID == lpInfo->ID)
		{
			return lpInfo;
		}
	}

	return 0;
}

int CCustomMonster::CheckCustomMonster(int MonsterID)
{
	if (MonsterID < 580)
	{
		return 0;
	}

	for (int n = 0; n < MAX_CUSTOMMONSTER; n++)
	{
		CUSTOMMONSTER_DATA* lpInfo = this->GetInfoByIndex(n);

		if (lpInfo == 0)
		{
			continue;
		}

		if (MonsterID == lpInfo->ID && lpInfo->Type == 1) // Type 1 = Monster / Type 0 = NPC
		{
			return 1;
		}
	}

	return 0;
}

CUSTOMMONSTER_DATA* CCustomMonster::GetInfoByIndex(int index)
{
	if (index < 0 || index >= MAX_CUSTOMMONSTER)
	{
		return 0;
	}

	if (this->m_CustomMonster[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomMonster[index];
}

void CCustomMonster::LoadMonsterBMD(signed int Class, char* FileDir, char* BmdName, signed int BmdType)
{
	int MonsterID = Class - MAX_MONSTER_MODEL;
	// ----
	CUSTOMMONSTER_DATA* lpInfo = gCustomMonster.GetInfoByMonsterID(MonsterID);

	if (lpInfo == 0)
	{
		pLoadModel(Class, FileDir, BmdName, BmdType);
	}
	else
	{
		pLoadModel(Class, lpInfo->Dir, lpInfo->BMDFile, -1);
	}
}

void CCustomMonster::LoadMonsterTexture(signed int Class, char* FolderDir, int a3, int a4)
{
	int MonsterID = Class - MAX_MONSTER_MODEL;

	CUSTOMMONSTER_DATA* lpInfo = gCustomMonster.GetInfoByMonsterID(MonsterID);

	if (lpInfo == 0)
	{
		pLoadTexture(Class, FolderDir, a3, a4, 0);
	}
	else
	{
		pLoadTexture(Class, lpInfo->Folder, a3, a4, 0);
	}
}

lpViewObj CCustomMonster::ShowMonster(int MonsterID, int a2, int a3, int a4)
{
	int v8; // [sp+Ch] [bp-4h]@1


	//===Set Skin

	if (MonsterID >= 2000)
	{
		lpViewObj Object = pGetViewStruct(a4, 1163, a2, a3, 0.0);
		v8 = pGetViewStruct2(a4, 1163, a2, a3, 0.0);


		if (Object == nullptr) {
			return pShowMonster(MonsterID, a2, a3, a4);
		}
		*((DWORD*)v8 + 207) = MonsterID + MODELSKINFIX;
		Object->m_Model.ObjectType = emMonster;
		//Object->m_Model.Scale = 2.0;
		Object->m_Model.Scale = 1.0;
		//memcpy(Object->Name, InfoModeSkin->TextSkinName, sizeof(Object->Name));
		Object->ID = MonsterID;
		return Object;

	}



	BOSSCLASS_DATA* BossClass = gCustomMonster.GetInfoByIDBoss(MonsterID);

	if (BossClass != 0) {

		lpViewObj Object = pGetViewStruct(a4, 1163, a2, a3, 0.0);
		v8 = pGetViewStruct2(a4, 1163, a2, a3, 0.0);

		if (Object == nullptr){
			return pShowMonster(MonsterID, a2, a3, a4);
		}

		// ----
		Object->HelmSlot = GET_ITEM_MODEL(7, BossClass->IndexSet);
		Object->HelmLevel = 15;
		Object->HelmAncient = 1;
		Object->HelmExcellent = 1;
		// ----
		Object->ArmorSlot = GET_ITEM_MODEL(8, BossClass->IndexSet);
		Object->ArmorLevel = 15;
		Object->ArmorAncient = 1;
		Object->ArmorExcellent = 1;
		// ----
		Object->PantsSlot = GET_ITEM_MODEL(9, BossClass->IndexSet);
		Object->PantsLevel = 15;
		Object->PantsAncient = 1;
		Object->PantsExcellent = 1;
		// ----
		Object->GlovesSlot = GET_ITEM_MODEL(10, BossClass->IndexSet);
		Object->GlovesLevel = 15;
		Object->GlovesAncient = 1;
		Object->GlovesExcellent = 1;
		// ----
		Object->BootsSlot = GET_ITEM_MODEL(11, BossClass->IndexSet);
		Object->BootsLevel = 15;
		Object->BootsAncient = 1;
		Object->BootsExcellent = 1;
		// ----
		Object->WeaponFirstSlot = (BossClass->IndexTayPhai + ITEM_BASE_MODEL);
		Object->WeaponFirstLevel = 15;
		Object->WeaponFirstAncient = 1;
		Object->WeaponFirstExcellent = 1;
		// ----
		Object->WeaponSecondSlot = (BossClass->IndexTayTrai + ITEM_BASE_MODEL);
		Object->WeaponSecondLevel = 15;
		Object->WeaponSecondAncient = 1;
		Object->WeaponSecondExcellent = 1;
		// ----
		Object->WingsSlot = GET_ITEM_MODEL(12, BossClass->IndexWing);

		Object->m_Model.AnimationID = 11;
		Object->m_Model.Scale = BossClass->Size;
		memcpy(Object->Name, BossClass->Name, sizeof(BossClass->Name));
		*(DWORD *)(v8 + 840) = 100;
		Object->m_Model.ObjectType = emMonster;
		Object->ID = MonsterID;
		return Object;

	}

	CUSTOMMONSTER_DATA* lpInfo = gCustomMonster.GetInfoByMonsterID(MonsterID);

	if (lpInfo == nullptr)
	{
		return pShowMonster(MonsterID, a2, a3, a4);
	}
	if (lpInfo->Type == 0)
	{
		int ModelID = MonsterID + MAX_MONSTER_MODEL;
		int BMD = sub_969C50_Addr(sub_4CDA10_Addr(), ModelID);

		pLoadModel(ModelID, lpInfo->Dir, lpInfo->BMDFile, -1);
		pLoadTexture(ModelID, lpInfo->Folder, 0x2901, 0x2600, 1);

		for (int m = 0;; ++m)
		{
			if (m >= *(signed __int16 *)(BMD + 38))
				break;
			*(float *)(*(DWORD *)(BMD + 48) + 16 * m + 4) = 0.25;
		}
	}
	else
	{
		pOpenMonsterModel(MonsterID);
	}

	lpViewObj Object = pGetViewStruct(a4, MonsterID + MAX_MONSTER_MODEL, a2, a3, 0.0);

	v8 = pGetViewStruct2(a4, MonsterID + MAX_MONSTER_MODEL, a2, a3, 0.0);

	if (Object == nullptr)
	{
		return pShowMonster(MonsterID, a2, a3, a4);
	}
	// ----
	memcpy(Object->Name, lpInfo->Name, sizeof(lpInfo->Name));
	// ----
	NPCNAME_DATA* NpcName = gNPCName.GetNPCName(MonsterID, pMapNumber, Object->RespawnPosX, Object->RespawnPosY);

	if (NpcName != 0)
	{
		sprintf(Object->Name, NpcName->Name);
	}

	if (lpInfo->Type == 0)
	{
		Object->m_Model.ObjectType = emNPC;
	}
	else
	{
		*(DWORD *)(v8 + 840) = 100;
		Object->m_Model.ObjectType = emMonster;
	}

	Object->ID = MonsterID;

	Object->m_Model.Scale = lpInfo->Size;


	return Object;
}

void CCustomMonster::SetMainAttribute(lpViewObj Object, int MonsterID)
{
	sub_580BB0((int)Object, MonsterID);

	NPCNAME_DATA* NpcName = gNPCName.GetNPCName(MonsterID, pMapNumber, Object->RespawnPosX, Object->RespawnPosY);

	if (NpcName != 0)
	{
		sprintf(Object->Name, NpcName->Name);
	}
}

void RenderModelAnimation(int Preview, int ModelID)
{
	lpModelObj gModel = &*(ObjectModel*)ModelID;

	lpViewObj lpObj = &*(ObjectPreview*)(Preview);

	if (!gModel || !lpObj)
	{
		return;
	}

	if (gModel->Unknown48 == 232)
	{
		gModel->AnimationID = 1;
	}
	else if (sub_8CF110(Preview, ModelID) == 1)
	{
		pCharacterAnimation(Preview, ModelID);
	}
	else if (pMapNumber != 1 || gModel->Unknown48 != 40)
	{
		if ((gModel->Unknown48 < 644 || gModel->Unknown48 >= 1044) && gCustomMonster.CheckCustomMonster(lpObj->ID) == 0)
		{
			if (gModel->Unknown48 > 1049)
			{
				switch (gModel->Unknown48)
				{
				case 1116:
					if (pRenderRand() % 16 >= 4 || gModel->Unknown52)
					{
						pActionModelSend(ModelID, 0, 1);
						gModel->Unknown52 = 0;
					}
					else
					{
						pActionModelSend(ModelID, 1, 1);
						gModel->Unknown52 = 1;
					}
					break;
				case 1126:
				case 1127:
					if (pRenderRand() % 5 >= 4 && gModel->AnimationID != 1)
						pActionModelSend(ModelID, 1, 1);
					else
						pActionModelSend(ModelID, 0, 1);
					break;
				case 1117:
					if (pRenderRand() % 5 >= 4)
						pActionModelSend(ModelID, 1, 1);
					else
						pActionModelSend(ModelID, 0, 1);
					break;
				case 1131:
					if (pRenderRand() % 3 < 2 || gModel->AnimationID)
					{
						pActionModelSend(ModelID, 0, 1);
					}
					else
					{
						pActionModelSend(ModelID, (pRenderRand() % 3) + 1, 1);
					}
					break;
				case 1132:
					if (pRenderRand() % 3 >= 2 && gModel->AnimationID != 1)
						pActionModelSend(ModelID, 1, 1);
					else
						pActionModelSend(ModelID, 0, 1);
					break;
				case 1133:
				case 1134:
				case 1135:
				case 1136:
					if (pRenderRand() % 5 >= 2)
					{
						pActionModelSend(ModelID, (pRenderRand() % 3) + 2, 1);
					}
					else
					{
						pActionModelSend(ModelID, 0, 1);
					}
					break;
				case 1137:
				case 1138:
				case 1139:
				case 1140:
					if (pRenderRand() % 5 >= 2)
					{
						pActionModelSend(ModelID, (pRenderRand() % 3) + 2, 1);
					}
					else
					{
						pActionModelSend(ModelID, 1, 1);
					}
					break;
				case 1145:
					if (pRenderRand() % 3 >= 2 && gModel->AnimationID != 1 && gModel->AnimationID != 2)
					{
						pActionModelSend(ModelID, (pRenderRand() % 2) + 1, 1);
					}
					else
					{
						pActionModelSend(ModelID, 0, 1);
					}
					break;
				case 1144:
					pActionModelSend(ModelID, 0, 1);
					break;
				case 1147:
				case 1158:
					if (pRenderRand() % 5 >= 4 && gModel->AnimationID != 1)
						pActionModelSend(ModelID, 1, 1);
					else
						pActionModelSend(ModelID, 0, 1);
					break;
				case 1151:
				case 1152:
					if (pRenderRand() % 5 >= 4)
					{
						pActionModelSend(ModelID, (pRenderRand() % 2) + 1, 1);
					}
					else
					{
						pActionModelSend(ModelID, 0, 1);
					}
					break;
				case 1154:
				case 1155:
					if (pRenderRand() % 5 >= 4)
					{
						pActionModelSend(ModelID, (pRenderRand() % 2) + 1, 1);
					}
					else
					{
						pActionModelSend(ModelID, 0, 1);
					}
					break;
				case 1153:
				case 1159:
					if (pRenderRand() % 5 >= 3)
						pActionModelSend(ModelID, 1, 1);
					else
						pActionModelSend(ModelID, 0, 1);
					break;
				case 1156:
					if (pRenderRand() % 5 >= 4)
					{
						pActionModelSend(ModelID, (pRenderRand() % 2) + 1, 1);
					}
					else
					{
						pActionModelSend(ModelID, 0, 1);
					}
					break;
				case 1160:
					if (pRenderRand() % 5 >= 4)
						pActionModelSend(ModelID, 1, 1);
					else
						pActionModelSend(ModelID, 0, 1);
					break;
				case 1161:
					if (pRenderRand() % 5 >= 4 && gModel->AnimationID != 1)
						pActionModelSend(ModelID, 1, 1);
					else
						pActionModelSend(ModelID, 0, 1);
					break;
				default:
					goto LABEL_110;
				}
			}
			else if (gModel->Unknown48 >= 1048)
			{
				if (pRenderRand() % 16 >= 12)
				{
					pActionModelSend(ModelID, (pRenderRand() % 2) + 1, 1);
				}
				else
				{
					pActionModelSend(ModelID, 0, 1);
				}
			}
			else if (gModel->Unknown48 < 168 || gModel->Unknown48 > 174)
			{
			LABEL_110:
				pActionModelSend(ModelID, (pRenderRand() % 2), 1);
			}
		}
		else if (gModel->AnimationID == 6)
		{
			if (!*(BYTE *)(Preview + 4))
			{
				*(BYTE *)(Preview + 4) = 1;
				sub_72A3D0(ModelID);
			}
		}
		else
		{
			if (gModel->AnimationID == 1
				|| gModel->AnimationID == 5
				|| gModel->AnimationID == 3
				|| gModel->AnimationID == 4
				|| gModel->AnimationID == 8
				|| gModel->AnimationID == 9
				|| gModel->AnimationID == 11)
			{
				pActionModelSend(ModelID, 0, 1);
			}
			if (gModel->AnimationID == 7 && (gModel->Unknown48 == 762 || gModel->Unknown48 == 763 || gModel->Unknown48 == 794))
			{
				if (gModel->Unknown48 == 794)
				{
					gModel->AnimationID = 0;
				}
				pActionModelSend(ModelID, 0, 1);
			}
		}
	}
	else
	{
		pActionModelSend(Preview + 776, 0, 1);
	}
}

BOOL CCustomMonster::CheckCustomSkinModel(int ModelID) // OK
{
	if (ModelID == 537)
	{
		return 1;
	}

	if (ModelID >= 10000)
	{
		//g_Console.AddMessage(1, "ModelID %d", ModelID);
		return 1;
	}

	return 0;
}
__declspec(naked) void LoadNewSkin1() // OK 
{
	static DWORD CheckIndexAddress1 = 0x0057301F;
	static DWORD CheckIndexAddress2 = 0x0057306B;//JNZ SHORT Main.0057306B

	_asm
	{
		Mov Eax, Dword Ptr Ss : [ECX + 0x34]
			Push Eax
			Lea Ecx, gCustomMonster
			Call[CCustomMonster::CheckCustomSkinModel]
			Test Eax, Eax
			Je EXIT
			Jmp[CheckIndexAddress1]
		EXIT:
			Jmp[CheckIndexAddress2]
	}
}


void CCustomMonster::InitMonster()
{
	SetCompleteHook(0xE9, 0x00573016, &LoadNewSkin1);

	SetCompleteHook(0xE8, 0x0055A35F, &RenderModelAnimation);

	SetOp((LPVOID)0x0061FE3F, (LPVOID)&this->LoadMonsterBMD, ASM::CALL);

	SetOp((LPVOID)0x0061B410, (LPVOID)&this->LoadMonsterTexture, ASM::CALL);
	SetOp((LPVOID)0x0061FEEA, (LPVOID)&this->LoadMonsterTexture, ASM::CALL);

	SetCompleteHook(0xE8, 0x004E199D, &this->ShowMonster);
	SetCompleteHook(0xE8, 0x00587049, &this->ShowMonster);
	SetCompleteHook(0xE8, 0x00590CCC, &this->ShowMonster);
	SetCompleteHook(0xE8, 0x005BBEE6, &this->ShowMonster);
	SetCompleteHook(0xE8, 0x0064229D, &this->ShowMonster);
	SetCompleteHook(0xE8, 0x00642D51, &this->ShowMonster);
	SetCompleteHook(0xE8, 0x00643229, &this->ShowMonster);
	SetCompleteHook(0xE8, 0x0065EA86, &this->ShowMonster);
	SetCompleteHook(0xE8, 0x00911A53, &this->ShowMonster);
	SetCompleteHook(0xE8, 0x00911A6D, &this->ShowMonster);
	SetCompleteHook(0xE8, 0x00911A87, &this->ShowMonster);
	SetCompleteHook(0xE8, 0x00911AA1, &this->ShowMonster);
	SetCompleteHook(0xE8, 0x00911ABB, &this->ShowMonster);

	SetOp((LPVOID)0x0058101A, (LPVOID)this->SetMainAttribute, ASM::CALL);
	SetOp((LPVOID)0x0058105B, (LPVOID)this->SetMainAttribute, ASM::CALL);
	SetOp((LPVOID)0x0058109C, (LPVOID)this->SetMainAttribute, ASM::CALL);
	SetOp((LPVOID)0x005810DD, (LPVOID)this->SetMainAttribute, ASM::CALL);
	SetOp((LPVOID)0x0058111E, (LPVOID)this->SetMainAttribute, ASM::CALL);
	SetOp((LPVOID)0x0058115F, (LPVOID)this->SetMainAttribute, ASM::CALL);
	SetOp((LPVOID)0x005811A0, (LPVOID)this->SetMainAttribute, ASM::CALL);
	SetOp((LPVOID)0x005811E1, (LPVOID)this->SetMainAttribute, ASM::CALL);
	SetOp((LPVOID)0x00581222, (LPVOID)this->SetMainAttribute, ASM::CALL);
	SetOp((LPVOID)0x00581263, (LPVOID)this->SetMainAttribute, ASM::CALL);
	SetOp((LPVOID)0x005812A8, (LPVOID)this->SetMainAttribute, ASM::CALL);
	SetOp((LPVOID)0x005812ED, (LPVOID)this->SetMainAttribute, ASM::CALL);
	SetOp((LPVOID)0x0058132E, (LPVOID)this->SetMainAttribute, ASM::CALL);
	SetOp((LPVOID)0x0058136F, (LPVOID)this->SetMainAttribute, ASM::CALL);
	SetOp((LPVOID)0x005813B4, (LPVOID)this->SetMainAttribute, ASM::CALL);
	SetOp((LPVOID)0x005813F9, (LPVOID)this->SetMainAttribute, ASM::CALL);
	SetOp((LPVOID)0x00586859, (LPVOID)this->SetMainAttribute, ASM::CALL);
}
int CCustomMonster::CreateMonster(int Class, int a2, int a3, int a4)
{
	return (int)this->ShowMonster(Class, a2, a3, a4);
}