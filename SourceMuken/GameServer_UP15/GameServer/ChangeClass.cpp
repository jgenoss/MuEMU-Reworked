#include "stdafx.h"
#include "ChangeClass.h"
#include "Notice.h"
#include "MasterSkillTree.h"
#include "ObjectManager.h"
#include "ServerInfo.h"
#include "DSProtocol.h"
#include "Util.h"
//#include "ResetSystem.h"
#include "CashShop.h"
#include "Message.h"

cChangeClass gChangeClass;

cChangeClass::cChangeClass()
{
	this->Init();
}

cChangeClass::~cChangeClass()
{

}

void cChangeClass::Init()
{
	//for (int i=0; i<MAX_ACCOUNT_LEVEL;i++)
	//{
	//	this->m_Price[i] = 0;
	//	this->m_PriceType[i] = 0;
	//}
	this->m_WCoinC = 0;
}

void cChangeClass::Load(char* path)
{
	//this->m_PriceType[0] = GetPrivateProfileInt("Common", "PriceType_AL0", 0, path);
	//this->m_PriceType[1] = GetPrivateProfileInt("Common", "PriceType_AL1", 0, path);
	//this->m_PriceType[2] = GetPrivateProfileInt("Common", "PriceType_AL2", 0, path);
	//this->m_PriceType[3] = GetPrivateProfileInt("Common", "PriceType_AL3", 0, path);

	//this->m_Price[0] = GetPrivateProfileInt("Common", "Price_AL0", 0, path);
	//this->m_Price[1] = GetPrivateProfileInt("Common", "Price_AL1", 0, path);
	//this->m_Price[2] = GetPrivateProfileInt("Common", "Price_AL2", 0, path);
	//this->m_Price[3] = GetPrivateProfileInt("Common", "Price_AL3", 0, path);

	this->m_WCoinC = GetPrivateProfileInt("Common", "m_WCoinC", 0, path);
}

void cChangeClass::SendData(int aIndex)
{
	PMSG_CHANGECLASS_DATA pRequest;
	pRequest.Head.set(0xFB, 0x08, sizeof(pRequest));

	//pRequest.PriceType = this->m_PriceType[gObj[aIndex].AccountLevel];
	//pRequest.Price = this->m_Price[gObj[aIndex].AccountLevel];

	pRequest.m_WCoinC = this->m_WCoinC;

	DataSend(aIndex, (LPBYTE)&pRequest, sizeof(pRequest));
}

void cChangeClass::RecvChangeClass(CG_CHANGECLASS_RECV* Data, int aIndex)
{
	;
	gCashShop.GDCashShopRecievePointSend(aIndex, (DWORD)&cChangeClass::ChangeClassCallback, (DWORD)Data->Type, 0);
}

void cChangeClass::ChangeClassCallback(LPOBJ lpObj, int Class, DWORD null, DWORD WCoinC, DWORD WCoinP, DWORD GoblinPoint)
{
	/*if (gChangeClass.m_PriceType[lpObj->AccountLevel] == 0)
	{
	if (lpObj->Money < gChangeClass.m_Price[lpObj->AccountLevel])
	{
	gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "You do not have enough %s!", gMessage.GetMessage(868));
	return;
	}
	}
	else if (gChangeClass.m_PriceType[lpObj->AccountLevel] == 1)
	{
	if (WCoinC < gChangeClass.m_Price[lpObj->AccountLevel])
	{
	gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "You do not have enough %s!", gMessage.GetMessage(869));
	return;
	}
	}
	else if (gChangeClass.m_PriceType[lpObj->AccountLevel] == 2)
	{
	if (WCoinP < gChangeClass.m_Price[lpObj->AccountLevel])
	{
	gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "You do not have enough %s!", gMessage.GetMessage(870));
	return;
	}
	}
	else if (gChangeClass.m_PriceType[lpObj->AccountLevel] == 3)
	{
	if (GoblinPoint < gChangeClass.m_Price[lpObj->AccountLevel])
	{
	gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "You do not have enough %s!",gMessage.GetMessage(871));
	return;
	}
	}*/
	if (lpObj->Coin1 < gChangeClass.m_WCoinC)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(924), gChangeClass.m_WCoinC);
		return;
	}
	// ----
	for (int i = 0; i < 12; i++)
	{
		if (lpObj->Inventory[i].IsItem())
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(925));
			return;
		}
	}

	gChangeClass.ChangeClass(lpObj, Class);
}

void cChangeClass::ChangeClass(LPOBJ lpObj, int Class)
{
	int NextClass = 0;
	switch (Class)
	{
	case 0:
		NextClass = CLASS_DW;
		break;
	case 16:
		NextClass = CLASS_DK;
		break;
	case 32:
		NextClass = CLASS_FE;
		break;
	case 48:
		NextClass = CLASS_MG;
		break;
	case 64:
		NextClass = CLASS_DL;
		break;
	case 80:
		NextClass = CLASS_SU;
		break;
	case 96:
		NextClass = CLASS_RF;
		break;
	}

	//lpObj->Level = 200;
	//lpObj->Experience = 0;
	//lpObj->MasterLevel = 0;
	//lpObj->MasterExperience = 0;
	//lpObj->MasterNextExperience = gMasterSkillTree.GetMasterLevelExpTlbInfo(lpObj->MasterExperience + 1);
	//lpObj->MasterPoint = 0;


	int CurrentPoint = lpObj->MasterLevel;

	lpObj->MasterPoint = CurrentPoint;


	for (int n = 0; n < MAX_SKILL_LIST; n++)
	{
		lpObj->Skill[n].Clear();
	}

	for (int n = 0; n < MAX_MASTER_SKILL_LIST; n++)
	{
		lpObj->MasterSkill[ n].Clear();
	}

	gMasterSkillTree.GCMasterSkillListSend(lpObj->Index);
	gSkillManager.GCSkillListSend(lpObj, 0);
	gMasterSkillTree.GCMasterInfoSend(lpObj);

	gCashShop.GDCashShopSubPointSaveSend(lpObj->Index, 0, gChangeClass.m_WCoinC, 0, 0, 0);
	gCashShop.CGCashShopPointRecv(lpObj->Index);

	lpObj->DBClass = Class;

	memset(lpObj->Quest, (BYTE)-1, sizeof(lpObj->Quest));

	if (lpObj->PartyNumber >= 0)
	{
		gParty.DelMember(lpObj->PartyNumber, lpObj->Index);
		lpObj->PartyTargetUser = -1;
	}
	//----------------------------------------------------------------------
	int NewPoints = lpObj->Strength + lpObj->Dexterity + lpObj->Vitality + lpObj->Energy;

	if (lpObj->Class == CLASS_DL)
	{
		NewPoints += lpObj->Leadership;
	}

	lpObj->LevelUpPoint += (NewPoints - (gDefaultClassInfo.m_DefaultClassInfo[lpObj->Class].Strength + gDefaultClassInfo.m_DefaultClassInfo[lpObj->Class].Dexterity +
		gDefaultClassInfo.m_DefaultClassInfo[lpObj->Class].Energy + gDefaultClassInfo.m_DefaultClassInfo[lpObj->Class].Vitality + gDefaultClassInfo.m_DefaultClassInfo[lpObj->Class].Leadership));

	lpObj->Strength = gDefaultClassInfo.m_DefaultClassInfo[lpObj->Class].Strength;
	lpObj->Dexterity = gDefaultClassInfo.m_DefaultClassInfo[lpObj->Class].Dexterity;
	lpObj->Energy = gDefaultClassInfo.m_DefaultClassInfo[lpObj->Class].Energy;
	lpObj->Vitality = gDefaultClassInfo.m_DefaultClassInfo[lpObj->Class].Vitality;
	lpObj->Leadership = gDefaultClassInfo.m_DefaultClassInfo[lpObj->Class].Leadership;

	//----------------------------------------------------------------------

	gObjectManager.CharacterCalcAttribute(lpObj->Index);

	GCNewCharacterInfoSend(lpObj);

	GDCharacterInfoSaveSend(lpObj->Index);
	// ----
	switch (Class)
	{
	case CLASS_DW:
		gObjMoveGate(lpObj->Index, 17);
		break;
	case CLASS_DK:
		gObjMoveGate(lpObj->Index, 17);
		break;
	case CLASS_FE:
		gObjMoveGate(lpObj->Index, 27);
		break;
	case CLASS_MG:
		gObjMoveGate(lpObj->Index, 17);
		break;
	case CLASS_DL:
		gObjMoveGate(lpObj->Index, 17);
		break;
	case CLASS_SU:
		gObjMoveGate(lpObj->Index, 267);
		break;
	case CLASS_RF:
		gObjMoveGate(lpObj->Index, 17);
		break;
	}

	gObjectManager.CharacterGameCloseSet(lpObj->Index, 1);
}
