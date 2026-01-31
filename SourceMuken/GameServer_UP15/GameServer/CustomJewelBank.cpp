// JewelMix.cpp: implementation of the CJewelMix class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CustomJewelBank.h"
#include "CommandManager.h"
#include "DSProtocol.h"
//#include "EventBattleRoyale.h"
#include "GameMain.h"
#include "ItemManager.h"
#include "Message.h"
#include "Notice.h"
#include "Util.h"

CCustomJewelBank gCustomJewelBank;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
void CCustomJewelBank::Load()
{
	this->Enable = GetPrivateProfileInt("HieuDaiCa", "Enable", 0, JEWELSBANK_DIR);
}
CCustomJewelBank::CCustomJewelBank() // OK
{

}

CCustomJewelBank::~CCustomJewelBank() // OK
{

}

int CCustomJewelBank::GetJewelSimpleType(int ItemIndex) // OK
{  // if(!this->Enable) return;
	switch (ItemIndex)
	{
	case GET_ITEM(14, 13):
		return 0;
	case GET_ITEM(14, 14):
		return 1;
	case GET_ITEM(14, 16):
		return 2;
	case GET_ITEM(14, 22):
		return 3;
	case GET_ITEM(14, 31):
		return 4;
	case GET_ITEM(14, 41):
		return 5;
	case GET_ITEM(14, 42):
		return 6;
	case GET_ITEM(12, 15):
		return 7;
	case GET_ITEM(14, 43):
		return 8;
	case GET_ITEM(14, 44):
		return 9;
	case GET_ITEM(12, 30):
		return 10;
	case GET_ITEM(12, 31):
		return 11;
	case GET_ITEM(12, 136):
		return 12;
	case GET_ITEM(12, 137):
		return 13;
	case GET_ITEM(12, 138):
		return 14;
	case GET_ITEM(12, 139):
		return 15;
	case GET_ITEM(12, 140):
		return 16;
	case GET_ITEM(12, 141):
		return 17;
	case GET_ITEM(12, 142):
		return 18;
	case GET_ITEM(12, 143):
		return 19;
	}

	return -1;
}

int CCustomJewelBank::GetJewelSimpleIndex(int type) // OK
{  //if(!this->Enable) return;
	switch (type)
	{
	case 0:
		return GET_ITEM(14, 13);
	case 1:
		return GET_ITEM(14, 14);
	case 2:
		return GET_ITEM(14, 16);
	case 3:
		return GET_ITEM(14, 22);
	case 4:
		return GET_ITEM(14, 31);
	case 5:
		return GET_ITEM(14, 41);
	case 6:
		return GET_ITEM(14, 42);
	case 7:
		return GET_ITEM(12, 15);
	case 8:
		return GET_ITEM(14, 43);
	case 9:
		return GET_ITEM(14, 44);
	}

	return -1;
}

int CCustomJewelBank::GetJewelBundleIndex(int type) // OK
{
	switch (type)
	{
	case 0:
		return GET_ITEM(12, 30);
	case 1:
		return GET_ITEM(12, 31);
	case 2:
		return GET_ITEM(12, 136);
	case 3:
		return GET_ITEM(12, 137);
	case 4:
		return GET_ITEM(12, 138);
	case 5:
		return GET_ITEM(12, 139);
	case 6:
		return GET_ITEM(12, 140);
	case 7:
		return GET_ITEM(12, 141);
	case 8:
		return GET_ITEM(12, 142);
	case 9:
		return GET_ITEM(12, 143);
	}

	return -1;
}

void CCustomJewelBank::JewelBankRecv(PSBMSG_JEWELBANK_RECV* lpMsg, int aIndex)
{
	if (!this->Enable) return;
	LPOBJ lpObj = &gObj[aIndex];

	int Slot = lpMsg->slot;

	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}

	//if(gBattleRoyale.CheckEnteredUser(aIndex) != 0)
	//{
	//	return;
	//}

	if (lpObj->Interface.use != 0)
	{
		return;
	}

	if (lpObj->TradeDuel == 1)
	{
		return;
	}

	if (lpObj->ChaosLock != 0)
	{
		return;
	}



	//#if(GAMESERVER_UPDATE >= 803)
	//
	//	int S8JewelIndex = this->GetJewelSimpleIndex(Slot);
	//
	//	if( S8JewelIndex == -1 )
	//	{
	//		return;
	//	}
	//
	//	Slot = gItemManager.GetInventoryItemSlot(lpObj,S8JewelIndex,-1);
	//	
	//#endif

	if (INVENTORY_FULL_RANGE(Slot) == 0)
	{
		return;
	}

	if (lpObj->Inventory[Slot].IsItem() == 0)
	{
		return;
	}

	int JewelIndex = this->GetJewelSimpleType(lpObj->Inventory[Slot].m_Index);

	if (JewelIndex >= 0)
	{
		int JewelType;
		int JewelCount;

		if (JewelIndex >= 10)
		{
			JewelType = JewelIndex - 10;
			JewelCount = 10 * (lpObj->Inventory[Slot].m_Level + 1);
		}
		else
		{
			JewelType = JewelIndex;
			JewelCount = 1;
		}

		if (JewelCount < 0 || JewelCount > 160)
		{
			return;
		}

		switch (JewelType)
		{
		case 0:
			lpObj->JewelBlessCount += JewelCount;
			break;
		case 1:
			lpObj->JewelSoulCount += JewelCount;
			break;
		case 2:
			lpObj->JewelLifeCount += JewelCount;
			break;
		case 3:
			lpObj->JewelCreationCount += JewelCount;
			break;
		case 4:
			lpObj->JewelGuardianCount += JewelCount;
			break;
		case 5:
			lpObj->JewelGemStoneCount += JewelCount;
			break;
		case 6:
			lpObj->JewelHarmonyCount += JewelCount;
			break;
		case 7:
			lpObj->JewelChaosCount += JewelCount;
			break;
		case 8:
			lpObj->JewelLowStoneCount += JewelCount;
			break;
		case 9:
			lpObj->JewelHighStoneCount += JewelCount;
			break;
		}

		gItemManager.InventoryDelItem(aIndex, Slot);
		gItemManager.GCItemDeleteSend(aIndex, Slot, 1);

		SDHP_CUSTOM_JEWELBANK_SEND pMsg = { 0 };

		pMsg.header.set(0xF7, 0x04, sizeof(pMsg));

		pMsg.index = lpObj->Index;

		memcpy(pMsg.account, lpObj->Account, sizeof(pMsg.account));

		pMsg.type = JewelType;

		pMsg.count = JewelCount;

		gDataServerConnection.DataSend((BYTE*)&pMsg, sizeof(pMsg));

		this->GCCustomJewelBankInfoSend(lpObj);

	}
}

void CCustomJewelBank::JewelBankWithDrawRecv(PSBMSG_JEWELBANKWITHDRAW_RECV* lpMsg, int aIndex)
{
	if (!this->Enable) return;
	LPOBJ lpObj = &gObj[aIndex];

	int Type = lpMsg->type;
	int Count = lpMsg->count;

	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}
	if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
		|| lpObj->Interface.type == INTERFACE_TRADE
		|| lpObj->Interface.type == INTERFACE_CASH_SHOP
		|| lpObj->Interface.type == INTERFACE_TRAINER
		){
		return;
	}

	//if(gObjCheckEventJoin(lpObj) != 0)
	//{
	//	return;
	//}

	if (lpObj->Interface.use != 0)
	{
		return;
	}

	if (lpObj->ChaosLock != 0)
	{
		return;
	}

	if (lpObj->TradeDuel == 1)
	{
		return;
	}

	if (Type < 0 || Count < 0)
	{
		return;
	}

	int FreeSpaces = gItemManager.CheckItemInventorySpaceCount(lpObj, 1, 1);

	if (FreeSpaces <= 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(512));
		return;
	}

	int JewelCount = Count;

	if (Count == 99)
	{
		JewelCount = FreeSpaces;
	}

#if(GAMESERVER_UPDATE<=401)
	if (Type >= 2 && (JewelCount == 10 || JewelCount == 20 || JewelCount == 30))
	{
		if (FreeSpaces < Count)
			return;
	}
#endif

	switch (Type)
	{
	case 0:
		if (Count == 99 && lpObj->JewelBlessCount < JewelCount)
		{
			JewelCount = lpObj->JewelBlessCount;
			lpObj->JewelBlessCount = 0;
		}
		else if (lpObj->JewelBlessCount < JewelCount)
		{
			return;
		}
		else
		{
			lpObj->JewelBlessCount -= JewelCount;
		}
		break;
	case 1:
		if (Count == 99 && lpObj->JewelSoulCount < JewelCount)
		{
			JewelCount = lpObj->JewelSoulCount;
			lpObj->JewelSoulCount = 0;
		}
		else if (lpObj->JewelSoulCount < JewelCount)
		{
			return;
		}
		else
		{
			lpObj->JewelSoulCount -= JewelCount;
		}
		break;
	case 2:
		if (Count == 99 && lpObj->JewelLifeCount < JewelCount)
		{
			JewelCount = lpObj->JewelLifeCount;
			lpObj->JewelLifeCount = 0;
		}
		else if (lpObj->JewelLifeCount < JewelCount)
		{
			return;
		}
		else
		{
			lpObj->JewelLifeCount -= JewelCount;
		}
		break;
	case 3:
		if (Count == 99 && lpObj->JewelCreationCount < JewelCount)
		{
			JewelCount = lpObj->JewelCreationCount;
			lpObj->JewelCreationCount = 0;
		}
		else if (lpObj->JewelCreationCount < JewelCount)
		{
			return;
		}
		else
		{
			lpObj->JewelCreationCount -= JewelCount;
		}
		break;
	case 4:
		if (Count == 99 && lpObj->JewelGuardianCount < JewelCount)
		{
			JewelCount = lpObj->JewelGuardianCount;
			lpObj->JewelGuardianCount = 0;
		}
		else if (lpObj->JewelGuardianCount < JewelCount)
		{
			return;
		}
		else
		{
			lpObj->JewelGuardianCount -= JewelCount;
		}
		break;
	case 5:
		if (Count == 99 && lpObj->JewelGemStoneCount < JewelCount)
		{
			JewelCount = lpObj->JewelGemStoneCount;
			lpObj->JewelGemStoneCount = 0;
		}
		else if (lpObj->JewelGemStoneCount < JewelCount)
		{
			return;
		}
		else
		{
			lpObj->JewelGemStoneCount -= JewelCount;
		}
		break;
	case 6:
		if (Count == 99 && lpObj->JewelHarmonyCount < JewelCount)
		{
			JewelCount = lpObj->JewelHarmonyCount;
			lpObj->JewelHarmonyCount = 0;
		}
		else if (lpObj->JewelHarmonyCount < JewelCount)
		{
			return;
		}
		else
		{
			lpObj->JewelHarmonyCount -= JewelCount;
		}
		break;
	case 7:
		if (Count == 99 && lpObj->JewelChaosCount < JewelCount)
		{
			JewelCount = lpObj->JewelChaosCount;
			lpObj->JewelChaosCount = 0;
		}
		else if (lpObj->JewelChaosCount < JewelCount)
		{
			return;
		}
		else
		{
			lpObj->JewelChaosCount -= JewelCount;
		}
		break;
	case 8:
		if (Count == 99 && lpObj->JewelLowStoneCount < JewelCount)
		{
			JewelCount = lpObj->JewelLowStoneCount;
			lpObj->JewelLowStoneCount = 0;
		}
		else if (lpObj->JewelLowStoneCount < JewelCount)
		{
			return;
		}
		else
		{
			lpObj->JewelLowStoneCount -= JewelCount;
		}
		break;
	case 9:
		if (Count == 99 && lpObj->JewelHighStoneCount < JewelCount)
		{
			JewelCount = lpObj->JewelHighStoneCount;
			lpObj->JewelHighStoneCount = 0;
		}
		else if (lpObj->JewelHighStoneCount < JewelCount)
		{
			return;
		}
		else
		{
			lpObj->JewelHighStoneCount -= JewelCount;
		}
		break;
	}

#if(GAMESERVER_UPDATE>=603)

	int ItemIndex = this->GetJewelSimpleIndex(Type);

	int ItemLevel = 0;

	if (Count != 99)
	{
		if (JewelCount == 10)
		{
			ItemIndex = this->GetJewelBundleIndex(Type);
		}
		else if (JewelCount == 20)
		{
			ItemIndex = this->GetJewelBundleIndex(Type);
			ItemLevel = 1;
		}
		else if (JewelCount == 30)
		{
			ItemIndex = this->GetJewelBundleIndex(Type);
			ItemLevel = 2;
		}
	}

	if (ItemIndex < 0)
	{
		return;
	}

	if (Count == 99)
	{
		for (int i = 0; i < JewelCount; i++)
		{
			GDCreateItemSend(aIndex, 0xEB, 0, 0, ItemIndex, ItemLevel, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);
		}
	}
	else
	{
		GDCreateItemSend(aIndex, 0xEB, 0, 0, ItemIndex, ItemLevel, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);
	}

#else

	int ItemIndex = this->GetJewelSimpleIndex(Type);

	int ItemLevel = 0;

	if ((Type == 0 || Type == 1) && Count != 99)
	{
		if (JewelCount == 10)
		{
			ItemIndex = this->GetJewelBundleIndex(Type);
		}
		else if (JewelCount == 20)
		{
			ItemIndex = this->GetJewelBundleIndex(Type);
			ItemLevel = 1;
		}
		else if (JewelCount == 30)
		{
			ItemIndex = this->GetJewelBundleIndex(Type);
			ItemLevel = 2;
		}
	}

	if (ItemIndex < 0)
	{
		return;
	}

	if ((Type != 0 && Type != 1) || Count == 99)
	{
		for (int i = 0; i < JewelCount; i++)
		{
			GDCreateItemSend(aIndex, 0xEB, 0, 0, ItemIndex, ItemLevel, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);
		}
	}
	else
	{
		GDCreateItemSend(aIndex, 0xEB, 0, 0, ItemIndex, ItemLevel, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);
	}

#endif



	SDHP_CUSTOM_JEWELBANK_SEND pMsg = { 0 };

	pMsg.header.set(0xF7, 0x04, sizeof(pMsg));

	pMsg.index = lpObj->Index;

	memcpy(pMsg.account, lpObj->Account, sizeof(pMsg.account));

	pMsg.type = Type;

	pMsg.count = -(JewelCount);

	gDataServerConnection.DataSend((BYTE*)&pMsg, sizeof(pMsg));

	this->GCCustomJewelBankInfoSend(lpObj);


}

void CCustomJewelBank::CustomJewelBankInfoSend(int index)
{
	LPOBJ lpObj = &gObj[index];

	if (gObjIsConnectedGP(index) == 0)
	{
		return;
	}

	SDHP_CUSTOM_JEWELBANK_INFO_SEND pMsg = { 0 };

	pMsg.header.set(0xF7, 0x05, sizeof(pMsg));

	pMsg.index = lpObj->Index;

	memcpy(pMsg.account, lpObj->Account, sizeof(pMsg.account));

	gDataServerConnection.DataSend((BYTE*)&pMsg, sizeof(pMsg));
}

void CCustomJewelBank::CustomJewelBankInfoRecv(SDHP_CUSTOM_JEWELBANK_INFO_RECV* lpMsg)
{
	LPOBJ lpObj = &gObj[lpMsg->index];

	if (gObjIsConnectedGP(lpMsg->index) == 0)
	{
		return;
	}

	lpObj->JewelBlessCount = lpMsg->Bless;
	lpObj->JewelSoulCount = lpMsg->Soul;
	lpObj->JewelLifeCount = lpMsg->Life;
	lpObj->JewelCreationCount = lpMsg->Creation;
	lpObj->JewelGuardianCount = lpMsg->Guardian;
	lpObj->JewelGemStoneCount = lpMsg->GemStone;
	lpObj->JewelHarmonyCount = lpMsg->Harmony;
	lpObj->JewelChaosCount = lpMsg->Chaos;
	lpObj->JewelLowStoneCount = lpMsg->LowStone;
	lpObj->JewelHighStoneCount = lpMsg->HighStone;

	this->GCCustomJewelBankInfoSend(lpObj);
}

void CCustomJewelBank::GCCustomJewelBankInfoSend(LPOBJ lpObj)
{
	if (gObjIsConnectedGP(lpObj->Index) == 0)
	{
		return;
	}

	PSBMSG_JEWELBANK_SEND pMsg = { 0 };

	pMsg.h.set(0xF3, 0xF5, sizeof(pMsg));

	pMsg.Bless = lpObj->JewelBlessCount;
	pMsg.Soul = lpObj->JewelSoulCount;
	pMsg.Life = lpObj->JewelLifeCount;
	pMsg.Creation = lpObj->JewelCreationCount;
	pMsg.Guardian = lpObj->JewelGuardianCount;
	pMsg.GemStone = lpObj->JewelGemStoneCount;
	pMsg.Harmony = lpObj->JewelHarmonyCount;
	pMsg.Chaos = lpObj->JewelChaosCount;
	pMsg.LowStone = lpObj->JewelLowStoneCount;
	pMsg.HighStone = lpObj->JewelHighStoneCount;

	DataSend(lpObj->Index, (BYTE*)&pMsg, pMsg.h.size);
}

void CCustomJewelBank::GDCustomJewelBankAddJewel(LPOBJ lpObj, int type, int qtd)
{

	switch (type)
	{
	case 0:
		lpObj->JewelBlessCount += qtd;
		break;
	case 1:
		lpObj->JewelSoulCount += qtd;
		break;
	case 2:
		lpObj->JewelLifeCount += qtd;
		break;
	case 3:
		lpObj->JewelCreationCount += qtd;
		break;
	case 4:
		lpObj->JewelGuardianCount += qtd;
		break;
	case 5:
		lpObj->JewelGemStoneCount += qtd;
		break;
	case 6:
		lpObj->JewelHarmonyCount += qtd;
		break;
	case 7:
		lpObj->JewelChaosCount += qtd;
		break;
	case 8:
		lpObj->JewelLowStoneCount += qtd;
		break;
	case 9:
		lpObj->JewelHighStoneCount += qtd;
		break;
	}

	SDHP_CUSTOM_JEWELBANK_SEND pMsg = { 0 };

	pMsg.header.set(0xF7, 0x04, sizeof(pMsg));

	pMsg.index = lpObj->Index;

	memcpy(pMsg.account, lpObj->Account, sizeof(pMsg.account));

	pMsg.type = type;

	pMsg.count = qtd;

	gDataServerConnection.DataSend((BYTE*)&pMsg, sizeof(pMsg));

	this->GCCustomJewelBankInfoSend(lpObj);
}

void CCustomJewelBank::GDCustomJewelBankDelJewel(LPOBJ lpObj, int type, int qtd)
{
	switch (type)
	{
	case 0:
		lpObj->JewelBlessCount -= qtd;
		break;
	case 1:
		lpObj->JewelSoulCount -= qtd;
		break;
	case 2:
		lpObj->JewelLifeCount -= qtd;
		break;
	case 3:
		lpObj->JewelCreationCount -= qtd;
		break;
	case 4:
		lpObj->JewelGuardianCount -= qtd;
		break;
	case 5:
		lpObj->JewelGemStoneCount -= qtd;
		break;
	case 6:
		lpObj->JewelHarmonyCount -= qtd;
		break;
	case 7:
		lpObj->JewelChaosCount -= qtd;
		break;
	case 8:
		lpObj->JewelLowStoneCount -= qtd;
		break;
	case 9:
		lpObj->JewelHighStoneCount -= qtd;
		break;
	}

	SDHP_CUSTOM_JEWELBANK_SEND pMsg = { 0 };

	pMsg.header.set(0xF7, 0x04, sizeof(pMsg));

	pMsg.index = lpObj->Index;

	memcpy(pMsg.account, lpObj->Account, sizeof(pMsg.account));

	pMsg.type = type;

	pMsg.count = -(qtd);

	gDataServerConnection.DataSend((BYTE*)&pMsg, sizeof(pMsg));

	this->GCCustomJewelBankInfoSend(lpObj);
}