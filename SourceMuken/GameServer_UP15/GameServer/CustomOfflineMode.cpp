#include "stdafx.h"
#include "CustomOfflineMode.h"
#include "DefaultClassInfo.h"
#include "ItemManager.h"
#include "SkillManager.h"
#include "Util.h"
#include "Message.h"
#include "Notice.h"
#include "MapManager.h"
#include "CustomAttack.h"
#include "MasterSkillTree.h"
#include "Map.h"
#include "EffectManager.h"
#include "Party.h"
#include "SocketManager.h"

#if(OFFLINE_MODE_NEW)

cOfflineMode gOfflineMode;

cOfflineMode::cOfflineMode()
{
	this->m_Skills.clear();
}

void cOfflineMode::LoadSkillsInfo(char* path)
{

	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(path);

	if (res.status != pugi::status_ok)
	{
		ErrorMessageBox("%s file load fail (%s)", path, res.description());
	}

	pugi::xml_node MainNode = file.child("OfflineMode");

	for (pugi::xml_node buff = MainNode.child("Buff"); buff; buff = buff.next_sibling())
	{
		SKILLS_INFO Info;

		Info.SkillID = buff.attribute("SkillID").as_int();
		Info.SkillEffect = gSkillManager.GetSkillEffect(Info.SkillID);
		Info.Class = buff.attribute("Class").as_int();

		this->m_Skills.push_back(Info);
	}
}

void cOfflineMode::Load(char* section, char* path)
{

	//pugi::xml_document file;
	//pugi::xml_parse_result res = file.load_file(path);
	//if (res.status != pugi::status_ok)
	//{
	//	ErrorMessageBox("File %s load fail. Error: %s", path, res.description());
	//	return;
	//}

	this->CanUseBuffs[0] = GetPrivateProfileInt(section, "CanUseBuffs_AL0", 0, path);
	this->CanUseBuffs[1] = GetPrivateProfileInt(section, "CanUseBuffs_AL1", 0, path);
	this->CanUseBuffs[2] = GetPrivateProfileInt(section, "CanUseBuffs_AL2", 0, path);
	this->CanUseBuffs[3] = GetPrivateProfileInt(section, "CanUseBuffs_AL3", 0, path);

	this->CanUsePick[0] = GetPrivateProfileInt(section, "CanUsePick_AL0", 0, path);
	this->CanUsePick[1] = GetPrivateProfileInt(section, "CanUsePick_AL1", 0, path);
	this->CanUsePick[2] = GetPrivateProfileInt(section, "CanUsePick_AL2", 0, path);
	this->CanUsePick[3] = GetPrivateProfileInt(section, "CanUsePick_AL3", 0, path);
}


bool cOfflineMode::CheckSkill(LPOBJ lpObj, int SkillNumber)
{

	SKILL_INFO SkillInfo;
	CSkill* lpSkill = 0;

	lpSkill = gSkillManager.GetSkill(lpObj, SkillNumber);

	if (lpSkill == 0)
	{
		return 0;
	}

	if (gSkillManager.GetInfo(SkillNumber, &SkillInfo) == 0)
	{
		return 0;
	}

	if (lpObj->Level < SkillInfo.RequireLevel)
	{
		return 0;
	}

	if (lpObj->Energy < SkillInfo.RequireEnergy)
	{
		return 0;
	}

	if (lpObj->Leadership < SkillInfo.RequireLeadership)
	{
		return 0;
	}

	return 1;
}

void cOfflineMode::GCOfflineModeSend(int aIndex)
{

	LPOBJ lpObj = &gObj[aIndex];

	PMSG_OFFLINEMODE_REQ pMsg;
	pMsg.OffType = 0;


	if (lpObj->Class == CLASS_DW)
	{
		pMsg.OffType = TYPE_DW;
		pMsg.SkillData[0] = this->CheckSkill(lpObj, SKILL_ICE_STORM);
		pMsg.SkillData[1] = this->CheckSkill(lpObj, SKILL_EVIL_SPIRIT);
		pMsg.SkillData[2] = this->CheckSkill(lpObj, SKILL_INFERNO);
		pMsg.SkillIndex[0] = SKILL_ICE_STORM;
		pMsg.SkillIndex[1] = SKILL_EVIL_SPIRIT;
		pMsg.SkillIndex[2] = SKILL_INFERNO;

		for (int i = 0; i <= 2; i++)
		{
			SKILL_INFO Info;
			gSkillManager.GetInfo(pMsg.SkillIndex[i], &Info);
			memcpy(pMsg.SkillName[i], Info.Name, sizeof(pMsg.SkillName[i]));
		}
	}
	else if (lpObj->Class == CLASS_DK)
	{
		pMsg.OffType = TYPE_DK;
		pMsg.SkillData[0] = this->CheckSkill(lpObj, SKILL_TWISTING_SLASH);
		pMsg.SkillData[1] = this->CheckSkill(lpObj, SKILL_RAGEFUL_BLOW);
		pMsg.SkillData[2] = this->CheckSkill(lpObj, SKILL_FROZEN_STAB);
		pMsg.SkillIndex[0] = SKILL_TWISTING_SLASH;
		pMsg.SkillIndex[1] = SKILL_RAGEFUL_BLOW;
		pMsg.SkillIndex[2] = SKILL_FROZEN_STAB;

		for (int i = 0; i <= 2; i++)
		{
			SKILL_INFO Info;
			gSkillManager.GetInfo(pMsg.SkillIndex[i], &Info);
			memcpy(pMsg.SkillName[i], Info.Name, sizeof(pMsg.SkillName[i]));
		}
	}
	else if (lpObj->Class == CLASS_FE)
	{
		pMsg.OffType = TYPE_FE;
		pMsg.SkillData[0] = this->CheckSkill(lpObj, SKILL_TRIPLE_SHOT);
		pMsg.SkillData[1] = this->CheckSkill(lpObj, SKILL_FIVE_SHOT);
		pMsg.SkillData[2] = this->CheckSkill(lpObj, SKILL_ICE_ARROW);
		pMsg.SkillIndex[0] = SKILL_TRIPLE_SHOT;
		pMsg.SkillIndex[1] = SKILL_FIVE_SHOT;
		pMsg.SkillIndex[2] = SKILL_ICE_ARROW;

		for (int i = 0; i <= 2; i++)
		{
			SKILL_INFO Info;
			gSkillManager.GetInfo(pMsg.SkillIndex[i], &Info);
			memcpy(pMsg.SkillName[i], Info.Name, sizeof(pMsg.SkillName[i]));
		}
	}
	else if (lpObj->Class == CLASS_MG)
	{
		//if (lpObj->Inventory[0].m_Index >= GET_ITEM(5, 0) && lpObj->Inventory[0].m_Index < GET_ITEM(6, 0))
		//{
		//	pMsg.OffType = TYPE_EMG;
		//	pMsg.SkillData[0] = this->CheckSkill(lpObj, SKILL_LIGHTNING_STORM);
		//	pMsg.SkillData[1] = this->CheckSkill(lpObj, SKILL_EVIL_SPIRIT);
		//	pMsg.SkillData[2] = this->CheckSkill(lpObj, SKILL_INFERNO);
		//	pMsg.SkillIndex[0] = SKILL_LIGHTNING_STORM;
		//	pMsg.SkillIndex[1] = SKILL_EVIL_SPIRIT;
		//	pMsg.SkillIndex[2] = SKILL_INFERNO;

		//	for (int i = 0; i <= 2; i++)
		//	{
		//		SKILL_INFO Info;
		//		gSkillManager.GetInfo(pMsg.SkillIndex[i], &Info);
		//		memcpy(pMsg.SkillName[i], Info.Name, sizeof(pMsg.SkillName[i]));
		//	}
		//}
		//else
		//{
		pMsg.OffType = TYPE_BMG;
		pMsg.SkillData[0] = this->CheckSkill(lpObj, SKILL_SWORD_SLASH);
		pMsg.SkillData[1] = this->CheckSkill(lpObj, SKILL_POWER_SLASH);
		pMsg.SkillData[2] = this->CheckSkill(lpObj, SKILL_LIGHTNING_STORM);
		pMsg.SkillIndex[0] = SKILL_SWORD_SLASH;
		pMsg.SkillIndex[1] = SKILL_POWER_SLASH;
		pMsg.SkillIndex[2] = SKILL_LIGHTNING_STORM;

		for (int i = 0; i <= 2; i++)
		{
			SKILL_INFO Info;
			gSkillManager.GetInfo(pMsg.SkillIndex[i], &Info);
			memcpy(pMsg.SkillName[i], Info.Name, sizeof(pMsg.SkillName[i]));
		}
		//}
	}
	else if (lpObj->Class == CLASS_DL)
	{
		pMsg.OffType = TYPE_DL;
		pMsg.SkillData[0] = this->CheckSkill(lpObj, SKILL_BIRDS);
		pMsg.SkillData[1] = this->CheckSkill(lpObj, SKILL_FIRE_BURST);
		pMsg.SkillData[2] = this->CheckSkill(lpObj, SKILL_FIRE_SCREAM);
		pMsg.SkillIndex[0] = SKILL_BIRDS;
		pMsg.SkillIndex[1] = SKILL_FIRE_BURST;
		pMsg.SkillIndex[2] = SKILL_FIRE_SCREAM;

		for (int i = 0; i <= 2; i++)
		{
			SKILL_INFO Info;
			gSkillManager.GetInfo(pMsg.SkillIndex[i], &Info);
			memcpy(pMsg.SkillName[i], Info.Name, sizeof(pMsg.SkillName[i]));
		}
	}
	else if (lpObj->Class == CLASS_SU)
	{
		pMsg.OffType = TYPE_SU;
		pMsg.SkillData[0] = this->CheckSkill(lpObj, SKILL_RED_STORM);
		pMsg.SkillData[1] = this->CheckSkill(lpObj, SKILL_CHAIN_LIGHTNING);
		pMsg.SkillData[2] = this->CheckSkill(lpObj, SKILL_DRAIN_LIFE); // SKILL_GHOST_PHANTOM
		pMsg.SkillIndex[0] = SKILL_RED_STORM;
		pMsg.SkillIndex[1] = SKILL_CHAIN_LIGHTNING;
		pMsg.SkillIndex[2] = SKILL_DRAIN_LIFE; // SKILL_GHOST_PHANTOM

		for (int i = 0; i <= 2; i++)
		{
			SKILL_INFO Info;
			gSkillManager.GetInfo(pMsg.SkillIndex[i], &Info);
			memcpy(pMsg.SkillName[i], Info.Name, sizeof(pMsg.SkillName[i]));
		}
	}
	else if (lpObj->Class == CLASS_RF)
	{
		pMsg.OffType = TYPE_RF;
		pMsg.SkillData[0] = this->CheckSkill(lpObj, SKILL_DRAGON_LORE);
		pMsg.SkillData[1] = this->CheckSkill(lpObj, SKILL_DARK_SIDE);
		pMsg.SkillIndex[0] = SKILL_DRAGON_LORE;
		pMsg.SkillIndex[1] = SKILL_DARK_SIDE;

		for (int i = 0; i <= 1; i++)
		{
			SKILL_INFO Info;
			gSkillManager.GetInfo(pMsg.SkillIndex[i], &Info);
			memcpy(pMsg.SkillName[i], Info.Name, sizeof(pMsg.SkillName[i]));
		}
	}

	pMsg.DrawBuffs = this->CanUseBuffs[lpObj->AccountLevel];
	pMsg.DrawPick = this->CanUsePick[lpObj->AccountLevel];

	pMsg.Head.set(0xFB, 0x00, sizeof(pMsg));

	DataSend(aIndex, (LPBYTE)&pMsg, sizeof(pMsg));
}

void cOfflineMode::CGOfflineModeRecv(int aIndex)
{

	this->GCOfflineModeSend(aIndex);
}

void cOfflineMode::CGOfflineModeStartRecv(PMSG_OFFLINEMODE_DATA_RECV* Data, int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	//if (gCustomAttack.m_CustomAttackOfflineSwitch == 0)
	//{
	//	return;
	//}

	//if (((int)lpObj->Coin1) < gCustomAttack.m_CustomAttackOfflineRequireMoney[lpObj->AccountLevel])
	//{
	//	gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gCustomAttack.m_CustomAttackOfflineText, gCustomAttack.m_CustomAttackOfflineRequireMoney[lpObj->AccountLevel]);
	//	return;
	//}

	if (gMap[lpObj->Map].CheckAttr(lpObj->X, lpObj->Y, 1) != 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(797));
		return;
	}

	if (CA_MAP_RANGE(lpObj->Map) != 0 || DS_MAP_RANGE(lpObj->Map) != 0 || BC_MAP_RANGE(lpObj->Map) != 0 || CC_MAP_RANGE(lpObj->Map) != 0 || IT_MAP_RANGE(lpObj->Map) != 0 || DA_MAP_RANGE(lpObj->Map) != 0 || DG_MAP_RANGE(lpObj->Map) != 0 || IG_MAP_RANGE(lpObj->Map) != 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(797));
		return;
	}

	lpObj->Socket = INVALID_SOCKET;

	if (lpObj->CloseCount > 0)
	{
		return;
	}
#if (USE_OFFLINEMODE_HELPER_PICK == TRUE)
	this->GetSelectedItems(lpObj);
#endif

	int SkillNumber = Data->SkillID;

	lpObj->AttackCustom = 1;

	lpObj->AttackCustomSkill = SkillNumber;

	lpObj->AttackCustomDelay = GetTickCount();

	lpObj->AttackCustomZoneX = lpObj->X;

	lpObj->AttackCustomZoneY = lpObj->Y;

	lpObj->AttackCustomZoneMap = lpObj->Map;

	lpObj->AttackCustomOffline = 1;

	//16-04-2022(TAT)
	//lpObj->AttackCustomOfflineTime = 0;

	//lpObj->AttackCustomOfflineMoneyDelay = GetTickCount();

	//lpObj->Coin1 -= gCustomAttack.m_CustomAttackOfflineRequireMoney[lpObj->AccountLevel];

	lpObj->OfflineMode.UseBuff = Data->UseBuff;
	lpObj->OfflineMode.PickZen = Data->PickZen;
	lpObj->OfflineMode.PickJewels = Data->PickJewels;
	lpObj->OfflineMode.PickExe = Data->PickExe;
	lpObj->OfflineMode.PickAnc = Data->PickAnc;
	lpObj->OfflineMode.PickSelected = Data->PickSelected;

	closesocket(lpObj->PerSocketContext->Socket);

	return;
}

void cOfflineMode::PickItems(LPOBJ lpObj)
{
	for (int c = 0; c<MAX_MAP_ITEM; c++)
	{
		if (gMap[lpObj->Map].m_Item[c].IsItem() == 0)
		{
			continue;
		}

		for (int i = -3; i<4; i++)
		{
			for (int j = -1; j<4; j++)
			{
				if (gMap[lpObj->Map].m_Item[c].m_X == (lpObj->X + i) && gMap[lpObj->Map].m_Item[c].m_Y == (lpObj->Y + j))
				{
					PMSG_ITEM_GET_RECV pMsg;
					pMsg.index[0] = SET_NUMBERHB(c);
					pMsg.index[1] = SET_NUMBERLB(c);

					if (lpObj->OfflineMode.PickZen != 0 && gMap[lpObj->Map].m_Item[c].m_Index == GET_ITEM(14, 15))
					{
						gItemManager.CGItemGetRecv(&pMsg, lpObj->Index);
					}

					if (lpObj->OfflineMode.PickJewels != 0 && gMap[lpObj->Map].m_Item[c].IsJewel() != 0)
					{
						gItemManager.CGItemGetRecv(&pMsg, lpObj->Index);
					}

					if (lpObj->OfflineMode.PickExe != 0 && gMap[lpObj->Map].m_Item[c].IsExcItem() != 0)
					{
						gItemManager.CGItemGetRecv(&pMsg, lpObj->Index);
					}

					if (lpObj->OfflineMode.PickAnc != 0 && gMap[lpObj->Map].m_Item[c].IsSetItem() != 0)
					{
						gItemManager.CGItemGetRecv(&pMsg, lpObj->Index);
					}
#if (USE_OFFLINEMODE_HELPER_PICK == TRUE)
					for (int count = 0; count<lpObj->MuHelperItemsCount; count++)
					{
						if (lpObj->MuHelperItems[count] == -1)
						{
							continue;
						}

						if (lpObj->OfflineMode.PickSelected != 0 && gMap[lpObj->Map].m_Item[c].m_Index == lpObj->MuHelperItems[count])
						{
							gItemManager.CGItemGetRecv(&pMsg, lpObj->Index);
						}
					}
#endif
				}
			}
		}
	}
}

#if (USE_OFFLINEMODE_HELPER_PICK == TRUE)
void cOfflineMode::GetSelectedItems(LPOBJ lpObj)
{
	if (gProtection.GetCustomState(CUSTOM_OFFLINE_MODE) == 0)
	{
		return;
	}

	for (int i = 0; i<12; i++)
	{
		if (lpObj->HelperItems[i][0] == 0)
		{
			continue;
		}
		for (int j = 0; j<7680; j++)
		{
			if (lpObj->MuHelperItemsCount < 99)
			{
				ITEM_INFO ItemInfo;
				if (gItemManager.GetInfo(j, &ItemInfo) == 0)
				{
					continue;
				}

				std::string Buff = ItemInfo.Name;
				size_t pos = Buff.find((char*)lpObj->HelperItems[i]);

				if (pos == std::string::npos)
				{
					continue;
				}

				lpObj->MuHelperItems[lpObj->MuHelperItemsCount] = ItemInfo.Index;
				lpObj->MuHelperItemsCount++;
			}
		}
	}
}
#endif

void cOfflineMode::UseBuffs(LPOBJ lpObj)
{
	for (std::vector<SKILLS_INFO>::iterator it = this->m_Skills.begin(); it != this->m_Skills.end(); it++)
	{
		if (it->Class != lpObj->Class)
		{
			continue;
		}

		int partynum = lpObj->PartyNumber;
		if (partynum != -1)
		{
			for (int j = 0; j < MAX_PARTY_USER; j++)
			{
				int number = gParty.m_PartyInfo[partynum].Index[j];

				if (number >= 0)
				{
					LPOBJ lpPartyObj = &gObj[number];
					if (lpObj->Map == lpPartyObj->Map)
					{
						int dis = gObjCalcDistance(lpObj, lpPartyObj);

						if (dis <= 6)
						{
							if (it->SkillEffect == -1 || it->SkillEffect == 0)
							{
								if (it->SkillID == SKILL_HEAL && (lpPartyObj->Life == lpPartyObj->MaxLife + lpPartyObj->AddLife))
								{
									continue;
								}
								CSkill* lpSkill = gSkillManager.GetSkill(lpObj, it->SkillID);
								if (lpSkill != NULL)
								{
									gCustomAttack.SendSkillAttack(lpObj, lpPartyObj->Index, lpSkill->m_index);
								}
							}
							else
							{
								if (!gEffectManager.CheckEffect(lpPartyObj, it->SkillEffect))
								{
									CSkill* lpSkill = gSkillManager.GetSkill(lpObj, it->SkillID);
									if (lpSkill != NULL)
									{
										gCustomAttack.SendSkillAttack(lpObj, lpPartyObj->Index, lpSkill->m_index);
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{
			CSkill* lpSkill = gSkillManager.GetSkill(lpObj, it->SkillID);
			if (lpSkill != NULL)
			{
				int effect = gSkillManager.GetSkillEffect(lpSkill->m_index);

				if (effect == -1 || effect == 0)
				{
					if (lpSkill->m_index == SKILL_HEAL && (lpObj->Life == lpObj->MaxLife + lpObj->AddLife))
					{
						continue;
					}

					gCustomAttack.SendSkillAttack(lpObj, lpObj->Index, lpSkill->m_index);
				}
				else
				{
					if (!gEffectManager.CheckEffect(lpObj, effect))
					{
						gCustomAttack.SendSkillAttack(lpObj, lpObj->Index, lpSkill->m_index/*it->SkillID*/);
					}
				}
			}
		}
	}
}
#endif