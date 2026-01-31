// ChaosBox.cpp: implementation of the CChaosBox class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ChaosBox.h"
#include "CastleSiegeSync.h"
#include "CustomWingMix.h"
#include "DSProtocol.h"
#include "ItemBagManager.h"
#include "ItemOptionRate.h"
#include "JewelOfHarmonyOption.h"
#include "JewelOfHarmonyType.h"
#include "Log.h"
#include "LuckyItem.h"
#include "Notice.h"
#include "PentagramSystem.h"
#include "RandomManager.h"
#include "ServerInfo.h"
#include "SetItemType.h"
#include "Shop.h"
#include "SocketItemOption.h"
#include "SocketItemType.h"
#include "Util.h"
#include "CustomMix.h"
#include "Message.h"
#include "ItemManager.h"
#include "MapServerManager.h"

CChaosBox gChaosBox;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChaosBox::CChaosBox() // OK
{
	this->m_SeniorMixLimitDay = 0;

	this->m_SeniorMixLimitMonth = 0;

	this->m_SeniorMixLimitYear = 0;
}

CChaosBox::~CChaosBox() // OK
{

}

void CChaosBox::ChaosBoxInit(LPOBJ lpObj) // OK
{
	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		lpObj->ChaosBox[n].Clear();
		lpObj->ChaosBoxMap[n] = 0xFF;
	}
}

void CChaosBox::ChaosBoxItemDown(LPOBJ lpObj, int slot) // OK
{
	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (n != slot)
		{
			lpObj->ChaosBox[n].Clear();
			lpObj->ChaosBoxMap[n] = 0xFF;
			continue;
		}

		CItem* lpItem = &lpObj->ChaosBox[n];

		lpItem->m_Level = 0;

		float dur = (float)gItemManager.GetItemDurability(lpItem->m_Index, lpItem->m_Level, lpItem->IsExcItem(), lpItem->IsSetItem());

		lpItem->m_Durability = dur*(lpItem->m_Durability / lpItem->m_BaseDurability);

		lpItem->Convert(lpItem->m_Index, lpItem->m_Option1, lpItem->m_Option2, lpItem->m_Option3, lpItem->m_NewOption, lpItem->m_SetOption, lpItem->m_JewelOfHarmonyOption, lpItem->m_ItemOptionEx, lpItem->m_SocketOption, lpItem->m_SocketOptionBonus);
	}
}

void CChaosBox::ChaosBoxItemKeep(LPOBJ lpObj, int slot) // OK
{
	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (n != slot)
		{
			lpObj->ChaosBox[n].Clear();
			lpObj->ChaosBoxMap[n] = 0xFF;
			continue;
		}
	}
}

void CChaosBox::ChaosBoxItemSave(LPOBJ lpObj) // OK
{
	if (gObjInventoryCommit(lpObj->Index) != 0)
	{
		for (int n = 0; n < CHAOS_BOX_SIZE; n++)
		{
			if (lpObj->ChaosBox[n].IsItem() != 0)
			{
				gItemManager.InventoryInsertItem(lpObj->Index, lpObj->ChaosBox[n]);
			}
		}
	}
}

bool CChaosBox::GetTalismanOfLuckRate(LPOBJ lpObj, int* rate) // OK
{
	int count = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 53)) // Talisman of Luck
		{
			count += (int)lpObj->ChaosBox[n].m_Durability;
		}
	}

	(*rate) += count;

	return ((count>MAX_TALISMAN_OF_LUCK) ? 0 : 1);
}

bool CChaosBox::GetElementalTalismanOfLuckRate(LPOBJ lpObj, int* rate) // OK
{
	int count = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 189)) // Elemental Talisman of Luck
		{
			count += (int)lpObj->ChaosBox[n].m_Durability;
		}
	}

	(*rate) += count;

	return ((count>MAX_TALISMAN_OF_LUCK) ? 0 : 1);
}

void CChaosBox::ChaosItemMix(LPOBJ lpObj) // OK
{
	int ChaosCount = 0;
	int ItemCount = 0;
	int ItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
			lpObj->ChaosBox[n].OldValue();
			ItemMoney += lpObj->ChaosBox[n].m_OldBuyMoney;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 13) || lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 14))
		{
			ItemCount++;
			lpObj->ChaosBox[n].OldValue();
			ItemMoney += lpObj->ChaosBox[n].m_OldBuyMoney;
		}
		else if (lpObj->ChaosBox[n].m_Level >= 4 && lpObj->ChaosBox[n].m_Option3 >= 1)
		{
			ItemCount++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosCount == 0 || ItemCount == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_ChaosItemMixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 20000);
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_ChaosItemMixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	lpObj->ChaosMoney = lpObj->ChaosSuccessRate * 10000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;
		BYTE ItemLevel = 0;
		BYTE ItemOption1 = 0;
		BYTE ItemOption2 = 0;
		BYTE ItemOption3 = 0;

		CRandomManager RandomManager;

		RandomManager.AddElement(GET_ITEM(2, 6), 1);

		RandomManager.AddElement(GET_ITEM(4, 6), 1);

		RandomManager.AddElement(GET_ITEM(5, 7), 1);

		RandomManager.GetRandomElement(&ItemIndex);

		gItemOptionRate.GetItemOption0(3, &ItemLevel);

		gItemOptionRate.GetItemOption1(3, &ItemOption1);

		gItemOptionRate.GetItemOption2(3, &ItemOption2);

		gItemOptionRate.GetItemOption3(3, &ItemOption3);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, ItemLevel, 0, ItemOption1, ItemOption2, ItemOption3, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gLog.Output(LOG_CHAOS_MIX, "[ChaosItemMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gLog.Output(LOG_CHAOS_MIX, "[ChaosItemMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

void CChaosBox::DevilSquareMix(LPOBJ lpObj) // OK
{
	int ChaosCount = 0;
	int EyeCount = 0;
	int EyeLevel = 0;
	int KeyCount = 0;
	int KeyLevel = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 17))
		{
			EyeCount++;
			EyeLevel = lpObj->ChaosBox[n].m_Level;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 18))
		{
			KeyCount++;
			KeyLevel = lpObj->ChaosBox[n].m_Level;
		}
	}

	if (ChaosCount != 1 || EyeCount != 1 || KeyCount != 1 || EyeLevel != KeyLevel)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (EyeLevel > 7 || KeyLevel > 7)
	{
		this->GCChaosMixSend(lpObj->Index, 8, 0);
		return;
	}

	switch (EyeLevel)
	{
	case 1:
		lpObj->ChaosSuccessRate = gServerInfo.m_DevilSquareMixRate1[lpObj->AccountLevel];
		lpObj->ChaosMoney = 100000;
		break;
	case 2:
		lpObj->ChaosSuccessRate = gServerInfo.m_DevilSquareMixRate2[lpObj->AccountLevel];
		lpObj->ChaosMoney = 200000;
		break;
	case 3:
		lpObj->ChaosSuccessRate = gServerInfo.m_DevilSquareMixRate3[lpObj->AccountLevel];
		lpObj->ChaosMoney = 400000;
		break;
	case 4:
		lpObj->ChaosSuccessRate = gServerInfo.m_DevilSquareMixRate4[lpObj->AccountLevel];
		lpObj->ChaosMoney = 700000;
		break;
	case 5:
		lpObj->ChaosSuccessRate = gServerInfo.m_DevilSquareMixRate5[lpObj->AccountLevel];
		lpObj->ChaosMoney = 1100000;
		break;
	case 6:
		lpObj->ChaosSuccessRate = gServerInfo.m_DevilSquareMixRate6[lpObj->AccountLevel];
		lpObj->ChaosMoney = 1600000;
		break;
	case 7:
		lpObj->ChaosSuccessRate = gServerInfo.m_DevilSquareMixRate7[lpObj->AccountLevel];
		lpObj->ChaosMoney = 2000000;
		break;
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, GET_ITEM(14, 19), EyeLevel, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gLog.Output(LOG_CHAOS_MIX, "[DevilSquareMix][Thành Công] Account:[%s] Name:[%s]- (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gLog.Output(LOG_CHAOS_MIX, "[DevilSquareMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

void CChaosBox::PlusItemLevelMix(LPOBJ lpObj, int type) // OK
{
	int ChaosCount = 0;
	int BlessCount = 0;
	int SoulCount = 0;
	int ItemCount = 0;
	int ItemSlot = 0;
	int ChaosAmulet = 0;
	int ElementalChaosAmulet = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 13))
		{
			BlessCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 14))
		{
			SoulCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 96))
		{
			ChaosAmulet++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 190))
		{
			ElementalChaosAmulet++;
		}
		else if (lpObj->ChaosBox[n].m_Level == (9 + type))
		{
			ItemCount++;
			ItemSlot = n;
		}
	}

	if (ChaosCount != 1 || SoulCount < (type + 1) || BlessCount < (type + 1) || ItemCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	switch (type)
	{
	case 0:
		lpObj->ChaosSuccessRate = gServerInfo.m_PlusItemLevelMixRate1[lpObj->AccountLevel];
		break;
	case 1:
		lpObj->ChaosSuccessRate = gServerInfo.m_PlusItemLevelMixRate2[lpObj->AccountLevel];
		break;
	case 2:
		lpObj->ChaosSuccessRate = gServerInfo.m_PlusItemLevelMixRate3[lpObj->AccountLevel];
		break;
	case 3:
		lpObj->ChaosSuccessRate = gServerInfo.m_PlusItemLevelMixRate4[lpObj->AccountLevel];
		break;
	case 4:
		lpObj->ChaosSuccessRate = gServerInfo.m_PlusItemLevelMixRate5[lpObj->AccountLevel];
		break;
	case 5:
		lpObj->ChaosSuccessRate = gServerInfo.m_PlusItemLevelMixRate6[lpObj->AccountLevel];
		break;
	}

	if (lpObj->ChaosBox[ItemSlot].m_Option2 != 0)
	{
		lpObj->ChaosSuccessRate += gServerInfo.m_AddLuckSuccessRate2[lpObj->AccountLevel];
	}

	if (lpObj->ChaosBox[ItemSlot].IsPentagramItem() == 0 && this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (lpObj->ChaosBox[ItemSlot].IsPentagramItem() != 0 && this->GetElementalTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	lpObj->ChaosMoney = 2000000 * (type + 1);

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		CItem item = lpObj->ChaosBox[ItemSlot];

		item.m_Level++;

		item.m_Durability = (float)gItemManager.GetItemDurability(item.m_Index, item.m_Level, item.IsExcItem(), item.IsSetItem());

		item.m_Durability = (item.m_Durability*lpObj->ChaosBox[ItemSlot].m_Durability) / item.m_BaseDurability;

		this->ChaosBoxInit(lpObj);

		gItemManager.ChaosBoxAddItem(lpObj->Index, item, 0);

		this->GCChaosMixSend(lpObj->Index, 1, &item);

		gObjCustomLogPlusChaosMix(lpObj, type, item.m_Index);


		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(994), lpObj->Name, gItemManager.GetItemName(item.m_Index), item.m_Level);


		gLog.Output(LOG_CHAOS_MIX, "[PlusItemLevelMix][Thành Công] Account:[%s] Name:[%s] - (Type: %d, ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, type, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		if (ChaosAmulet == 0 && ElementalChaosAmulet == 0)
		{
#if(GAMESERVER_UPDATE>=701)

			gPentagramSystem.DelAllPentagramJewelInfo(lpObj, &lpObj->ChaosBox[ItemSlot], 0);

#endif
			CItem item = lpObj->ChaosBox[ItemSlot];

			item.m_Level++;

			this->ChaosBoxInit(lpObj);

			this->GCChaosBoxSend(lpObj, 0);

			this->GCChaosMixSend(lpObj->Index, 0, 0);

			gObjCustomLogPlusChaosMix(lpObj, type, item.m_Index);

			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(995), lpObj->Name, gItemManager.GetItemName(item.m_Index), item.m_Level);

			gLog.Output(LOG_CHAOS_MIX, "[PlusItemLevelMix][Thất Bại] Account:[%s] Name:[%s] - (Type: %d, ChaosSuccessRate: %d, ChaosMoney: %d, ChaosAmulet: %d)", lpObj->Account, lpObj->Name, type, lpObj->ChaosSuccessRate, lpObj->ChaosMoney, (ChaosAmulet + ElementalChaosAmulet));
		}
		else
		{

			CItem item = lpObj->ChaosBox[ItemSlot];

			item.m_Level++;

			this->ChaosBoxItemDown(lpObj, ItemSlot);

			this->GCChaosBoxSend(lpObj, 0);

			this->GCChaosMixSend(lpObj->Index, 0, 0);

			gObjCustomLogPlusChaosMix(lpObj, type, item.m_Index);

			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(995), lpObj->Name, gItemManager.GetItemName(item.m_Index), item.m_Level);

			gLog.Output(LOG_CHAOS_MIX, "[PlusItemLevelMix][Thất Bại] Account:[%s] Name:[%s] - (Type: %d, ChaosSuccessRate: %d, ChaosMoney: %d, ChaosAmulet: %d)", lpObj->Account, lpObj->Name, type, lpObj->ChaosSuccessRate, lpObj->ChaosMoney, (ChaosAmulet + ElementalChaosAmulet));
		}
	}
}


//Qoay Qoái Điểu
void CChaosBox::DinorantMix(LPOBJ lpObj) // OK
{
	int ChaosCount = 0;
	int UniriaCount = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 2) && lpObj->ChaosBox[n].m_Durability == 255)
		{
			UniriaCount++;
		}
	}

	if (ChaosCount != 1 || UniriaCount != 10)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	lpObj->ChaosSuccessRate = gServerInfo.m_DinorantMixRate[lpObj->AccountLevel];

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	lpObj->ChaosMoney = 500000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = GET_ITEM(13, 3);
		BYTE ItemNewOption = 0;

		gItemOptionRate.GetItemOption4(3, &ItemNewOption);

		gItemOptionRate.MakeNewOption(ItemIndex, ItemNewOption, &ItemNewOption);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 255, 0, 0, 0, -1, ItemNewOption, 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(998), lpObj->Name);

		gLog.Output(LOG_CHAOS_MIX, "[DinorantMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(893), lpObj->Name);

		gLog.Output(LOG_CHAOS_MIX, "[DinorantMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

void CChaosBox::FruitMix(LPOBJ lpObj) // OK
{
	int ChaosCount = 0;
	int CreationCount = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 22))
		{
			CreationCount++;
		}
	}

	if (ChaosCount != 1 || CreationCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	lpObj->ChaosSuccessRate = gServerInfo.m_FruitMixRate[lpObj->AccountLevel];

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	lpObj->ChaosMoney = 3000000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		BYTE ItemLevel = GetLargeRand() % 5;

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, GET_ITEM(13, 15), ItemLevel, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gLog.Output(LOG_CHAOS_MIX, "[FruitMix][Thành Công] Account:[%s] Name:[%s]- (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gLog.Output(LOG_CHAOS_MIX, "[FruitMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

void CChaosBox::Wing2Mix(LPOBJ lpObj, int type) // OK
{
	int ChaosCount = 0;
	int FeatherCount = 0;
	int SleeveCount = 0;
	int WingItemCount = 0;
	int WingItemMoney = 0;
	int ItemCount = 0;
	int ItemMoney = 0;
	int TalismanOfWingType = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 14) && lpObj->ChaosBox[n].m_Level == 0)
		{
			FeatherCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 14) && lpObj->ChaosBox[n].m_Level == 1)
		{
			SleeveCount++;
		}
		else if ((lpObj->ChaosBox[n].m_Index >= GET_ITEM(12, 0) && lpObj->ChaosBox[n].m_Index <= GET_ITEM(12, 2)) || lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 41))
		{
			WingItemCount++;
			WingItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
		else if (lpObj->ChaosBox[n].IsExcItem() != 0 && lpObj->ChaosBox[n].m_Level >= 4)
		{
			ItemCount++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(13, 88) && lpObj->ChaosBox[n].m_Index >= GET_ITEM(13, 92))
		{
			TalismanOfWingType = lpObj->ChaosBox[n].m_Index - GET_ITEM(13, 87);
		}
	}

	if (ChaosCount != 1 || (type == 0 && FeatherCount != 1) || (type == 1 && SleeveCount != 1) || WingItemCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_Wing2MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (WingItemMoney / 4000000) + (ItemMoney / 40000);
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_Wing2MixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_Wing2MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>90) ? 90 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = 5000000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		if (type == 0)
		{
			WORD ItemIndex = 0;
			BYTE ItemOption2 = 0;
			BYTE ItemOption3 = 0;
			BYTE ItemNewOption = 0;

			CRandomManager RandomManager;

			RandomManager.AddElement(GET_ITEM(12, 3), 1);

			RandomManager.AddElement(GET_ITEM(12, 4), 1);

			RandomManager.AddElement(GET_ITEM(12, 5), 1);

			RandomManager.AddElement(GET_ITEM(12, 6), 1);

			if (gServerInfo.m_DisableWingMixSU != 1)
			{
				RandomManager.AddElement(GET_ITEM(12, 42), 1);
			}

			RandomManager.GetRandomElement(&ItemIndex);

			switch (TalismanOfWingType)
			{
			case 1:
				ItemIndex = GET_ITEM(12, 5);
				break;
			case 2:
				ItemIndex = GET_ITEM(12, 4);
				break;
			case 3:
				ItemIndex = GET_ITEM(12, 3);
				break;
			case 4:
				if (gServerInfo.m_DisableWingMixSU != 1)
				{
					ItemIndex = GET_ITEM(12, 42); // Asa de SU
				}
				else
				{
					ItemIndex = GET_ITEM(12, 5); // Asa de SM
				}
				break;
			case 5:
				ItemIndex = GET_ITEM(12, 6);
				break;
			}

			ITEM_INFO ItemInfo;

			gItemOptionRate.GetItemOption2(4, &ItemOption2);

			gItemOptionRate.GetItemOption3(4, &ItemOption3);

			gItemOptionRate.GetItemOption4(4, &ItemNewOption);

			gItemOptionRate.MakeNewOption(ItemIndex, ItemNewOption, &ItemNewOption);

			GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, ItemOption2, ItemOption3, -1, (ItemNewOption + (32 * (GetLargeRand() % 2))), 0, 0, 0, 0, 0xFF, 0);

			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(1000), lpObj->Name, gItemManager.GetItemName(ItemIndex));

			gLog.Output(LOG_CHAOS_MIX, "[Wing2Mix][Thành Công] Account:[%s] Name:[%s] - (Type: %d, ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, type, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
		}
		else
		{
			WORD ItemIndex = 0;
			BYTE ItemOption2 = 0;
			BYTE ItemOption3 = 0;
			BYTE ItemNewOption = 0;

			CRandomManager RandomManager;

#if(GAMESERVER_UPDATE>=601)

			if (gServerInfo.m_DisableWingMixRF != 1)
			{
				RandomManager.AddElement(GET_ITEM(12, 49), 1);
			}

#endif

			if (gServerInfo.m_DisableWingMixDL != 1)
			{
				RandomManager.AddElement(GET_ITEM(13, 30), 1);
			}
			else
			{
				RandomManager.AddElement(GET_ITEM(12, 3), 1);
			}

			ITEM_INFO ItemInfo;

			RandomManager.GetRandomElement(&ItemIndex);

			gItemOptionRate.GetItemOption2(4, &ItemOption2);

			gItemOptionRate.GetItemOption3(4, &ItemOption3);

			gItemOptionRate.GetItemOption4(5, &ItemNewOption);

			gItemOptionRate.MakeNewOption(ItemIndex, ItemNewOption, &ItemNewOption);

			GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, ItemOption2, ItemOption3, -1, (ItemNewOption + 32), 0, 0, 0, 0, 0xFF, 0);

			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(1000), lpObj->Name, gItemManager.GetItemName(ItemIndex));

			gLog.Output(LOG_CHAOS_MIX, "[Wing2Mix][Thành Công] Account:[%s] Name:[%s] - (Type: %d, ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, type, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
		}
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(890), lpObj->Name);

		gLog.Output(LOG_CHAOS_MIX, "[Wing2Mix][Thất Bại] Account:[%s] Name:[%s] - (Type: %d, ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, type, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

void CChaosBox::BloodCastleMix(LPOBJ lpObj) // OK
{
	int ChaosCount = 0;
	int ScrollCount = 0;
	int ScrollLevel = 0;
	int BoneCount = 0;
	int BoneLevel = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 16))
		{
			ScrollCount++;
			ScrollLevel = lpObj->ChaosBox[n].m_Level;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 17))
		{
			BoneCount++;
			BoneLevel = lpObj->ChaosBox[n].m_Level;
		}
	}

	if (ChaosCount != 1 || ScrollCount != 1 || BoneCount != 1 || ScrollLevel != BoneLevel)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (ScrollLevel > 8 || BoneLevel > 8)
	{
		this->GCChaosMixSend(lpObj->Index, 8, 0);
		return;
	}

	switch (ScrollLevel)
	{
	case 1:
		lpObj->ChaosSuccessRate = gServerInfo.m_BloodCastleMixRate1[lpObj->AccountLevel];
		lpObj->ChaosMoney = 50000;
		break;
	case 2:
		lpObj->ChaosSuccessRate = gServerInfo.m_BloodCastleMixRate2[lpObj->AccountLevel];
		lpObj->ChaosMoney = 80000;
		break;
	case 3:
		lpObj->ChaosSuccessRate = gServerInfo.m_BloodCastleMixRate3[lpObj->AccountLevel];
		lpObj->ChaosMoney = 150000;
		break;
	case 4:
		lpObj->ChaosSuccessRate = gServerInfo.m_BloodCastleMixRate4[lpObj->AccountLevel];
		lpObj->ChaosMoney = 250000;
		break;
	case 5:
		lpObj->ChaosSuccessRate = gServerInfo.m_BloodCastleMixRate5[lpObj->AccountLevel];
		lpObj->ChaosMoney = 400000;
		break;
	case 6:
		lpObj->ChaosSuccessRate = gServerInfo.m_BloodCastleMixRate6[lpObj->AccountLevel];
		lpObj->ChaosMoney = 600000;
		break;
	case 7:
		lpObj->ChaosSuccessRate = gServerInfo.m_BloodCastleMixRate7[lpObj->AccountLevel];
		lpObj->ChaosMoney = 850000;
		break;
	case 8:
		lpObj->ChaosSuccessRate = gServerInfo.m_BloodCastleMixRate8[lpObj->AccountLevel];
		lpObj->ChaosMoney = 1050000;
		break;
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) <= lpObj->ChaosSuccessRate)
	{
		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, GET_ITEM(13, 18), ScrollLevel, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gLog.Output(LOG_CHAOS_MIX, "[BloodCastleMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gLog.Output(LOG_CHAOS_MIX, "[BloodCastleMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

void CChaosBox::Wing1Mix(LPOBJ lpObj) // OK
{
	int ChaosCount = 0;
	int ChaosItem = 0;
	int ItemCount = 0;
	int ItemMoney = 0;
	int TalismanOfWingType = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
			lpObj->ChaosBox[n].OldValue();
			ItemMoney += lpObj->ChaosBox[n].m_OldBuyMoney;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 13) || lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 14))
		{
			ItemCount++;
			lpObj->ChaosBox[n].OldValue();
			ItemMoney += lpObj->ChaosBox[n].m_OldBuyMoney;
		}
		else if ((lpObj->ChaosBox[n].m_Index == GET_ITEM(2, 6) || lpObj->ChaosBox[n].m_Index == GET_ITEM(4, 6) || lpObj->ChaosBox[n].m_Index == GET_ITEM(5, 7)) && lpObj->ChaosBox[n].m_Level >= 4 && lpObj->ChaosBox[n].m_Option3 >= 1)
		{
			ChaosItem++;
			ItemCount++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
		else if (lpObj->ChaosBox[n].m_Level >= 4 && lpObj->ChaosBox[n].m_Option3 >= 1)
		{
			ItemCount++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(13, 83) && lpObj->ChaosBox[n].m_Index >= GET_ITEM(13, 86))
		{
			TalismanOfWingType = lpObj->ChaosBox[n].m_Index - GET_ITEM(13, 82);
		}
	}

	if (ChaosCount == 0 || ChaosItem == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_Wing1MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 20000);
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_Wing1MixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	lpObj->ChaosMoney = lpObj->ChaosSuccessRate * 10000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;
		BYTE ItemOption2 = 0;
		BYTE ItemOption3 = 0;

		CRandomManager RandomManager;

		RandomManager.AddElement(GET_ITEM(12, 0), 1);

		RandomManager.AddElement(GET_ITEM(12, 1), 1);

		RandomManager.AddElement(GET_ITEM(12, 2), 1);

		if (gServerInfo.m_DisableWingMixSU != 1)
		{
			RandomManager.AddElement(GET_ITEM(12, 41), 1);
		}

		RandomManager.GetRandomElement(&ItemIndex);

		switch (TalismanOfWingType)
		{
		case 1:
			ItemIndex = GET_ITEM(12, 2);
			break;
		case 2:
			ItemIndex = GET_ITEM(12, 1);
			break;
		case 3:
			ItemIndex = GET_ITEM(12, 0);
			break;
		case 4:
			if (gServerInfo.m_DisableWingMixSU != 1)
			{
				ItemIndex = GET_ITEM(12, 41); //asa de SU
			}
			else
			{
				ItemIndex = GET_ITEM(12, 0); // Asa de SM
			}
			break;
		}
		ITEM_INFO ItemInfo;

		gItemOptionRate.GetItemOption2(5, &ItemOption2);

		gItemOptionRate.GetItemOption3(5, &ItemOption3);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, ItemOption2, ItemOption3, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(1000), lpObj->Name, gItemManager.GetItemName(ItemIndex));

		gLog.Output(LOG_CHAOS_MIX, "[Wing1Mix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(889), lpObj->Name);

		gLog.Output(LOG_CHAOS_MIX, "[Wing1Mix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

//Qoay Linh Hồn Chiến Mã + Qụa Tinh
void CChaosBox::PetMix(LPOBJ lpObj, int type) // OK
{
	int ChaosCount = 0;
	int SoulOfDarkHorseCount = 0;
	int SoulOfDarkSpiritCount = 0;
	int BlessCount = 0;
	int SoulCount = 0;
	int CreationCount = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 31) && lpObj->ChaosBox[n].m_Level == 0)
		{
			SoulOfDarkHorseCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 31) && lpObj->ChaosBox[n].m_Level == 1)
		{
			SoulOfDarkSpiritCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 13))
		{
			BlessCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 14))
		{
			SoulCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 22))
		{
			CreationCount++;
		}
	}

	if (ChaosCount != 1 || (type == 0 && SoulOfDarkHorseCount != 1) || (type == 1 && SoulOfDarkSpiritCount != 1) || BlessCount != (5 - (type * 3)) || SoulCount != (5 - (type * 3)) || CreationCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	lpObj->ChaosSuccessRate = gServerInfo.m_PetMixRate[lpObj->AccountLevel];

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	lpObj->ChaosMoney = 5000000 - (4000000 * type);

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		GDCreateItemSend(lpObj->Index, 0xFE, 0, 0, (GET_ITEM(13, 4) + type), 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gLog.Output(LOG_CHAOS_MIX, "[PetMix][Thành Công] Account:[%s] Name:[%s] - (Type: %d, ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, type, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 1);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(894), lpObj->Name);

		gLog.Output(LOG_CHAOS_MIX, "[PetMix][Thất Bại] Account:[%s] Name:[%s] - (Type: %d, ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, type, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

void CChaosBox::SiegePotionMix(LPOBJ lpObj, int type) // OK
{
	int BlessCount = 0;
	int SoulCount = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 13))
		{
			BlessCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 14))
		{
			SoulCount++;
		}
	}

	if ((type == 0 && (BlessCount == 0 || BlessCount > 25)) || (type == 1 && (SoulCount == 0 || SoulCount > 25)))
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	lpObj->ChaosMoney = 100000 - (50000 * type);

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, GET_ITEM(14, 7), type, ((BlessCount + SoulCount) * 10), 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

	gLog.Output(LOG_CHAOS_MIX, "[SiegePotionMix][Thành Công] Account:[%s] Name:[%s] - (Type: %d, ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, type, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
}

void CChaosBox::LifeStoneMix(LPOBJ lpObj) // OK
{
	int ChaosCount = 0;
	int BlessCount = 0;
	int SoulCount = 0;
	int GuardianCount = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 13))
		{
			BlessCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 14))
		{
			SoulCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 31))
		{
			GuardianCount++;
		}
	}

	if (ChaosCount != 1 || BlessCount != 5 || SoulCount != 5 || GuardianCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	lpObj->ChaosMoney = 5000000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, GET_ITEM(13, 11), 1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

	gLog.Output(LOG_CHAOS_MIX, "[LifeStoneMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
}

void CChaosBox::SeniorMix(LPOBJ lpObj) // OK
{
	if (gCastleSiegeSync.CheckCastleOwnerMember(lpObj->Index) == 0 || lpObj->GuildStatus != 0x80)
	{
		this->GCChaosMixSend(lpObj->Index, 0, 0);
		return;
	}

	SYSTEMTIME SystemTime;

	GetSystemTime(&SystemTime);

	if (this->m_SeniorMixLimitDay == SystemTime.wDay && this->m_SeniorMixLimitMonth == SystemTime.wMonth && this->m_SeniorMixLimitYear == SystemTime.wYear)
	{
		this->GCChaosMixSend(lpObj->Index, 0, 0);
		return;
	}

	int SoulPack10 = 0;
	int BlessPack10 = 0;
	int GuardianCount = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 30))
		{
			BlessPack10 += lpObj->ChaosBox[n].m_Level + 1;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 31))
		{
			SoulPack10 += lpObj->ChaosBox[n].m_Level + 1;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 31))
		{
			GuardianCount++;
		}
	}

	if (SoulPack10 != 3 || BlessPack10 != 3 || GuardianCount != 30)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	lpObj->ChaosMoney = 1000000000;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	CItem item;

	if (gItemBagManager.GetItemBySpecialValue(ITEM_BAG_SENIOR_MIX, lpObj, &item) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 0, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	this->m_SeniorMixLimitDay = SystemTime.wDay;

	this->m_SeniorMixLimitMonth = SystemTime.wMonth;

	this->m_SeniorMixLimitYear = SystemTime.wYear;

	GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, item.m_Index, (BYTE)item.m_Level, 0, (BYTE)item.m_Option1, (BYTE)item.m_Option2, (BYTE)item.m_Option3, -1, item.m_NewOption, item.m_SetOption, item.m_JewelOfHarmonyOption, item.m_ItemOptionEx, item.m_SocketOption, item.m_SocketOptionBonus, 0);

	gLog.Output(LOG_CHAOS_MIX, "[SeniorMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
}

void CChaosBox::PieceOfHornMix(LPOBJ lpObj) // OK
{
	int ChaosCount = 0;
	int SplinterOfArmorCount = 0;
	int BlessOfGuardianCount = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 32))
		{
			SplinterOfArmorCount += (int)lpObj->ChaosBox[n].m_Durability;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 33))
		{
			BlessOfGuardianCount += (int)lpObj->ChaosBox[n].m_Durability;
		}
	}

	if (ChaosCount != 1 || SplinterOfArmorCount != 20 || BlessOfGuardianCount != 20)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	lpObj->ChaosSuccessRate = gServerInfo.m_PieceOfHornMixRate[lpObj->AccountLevel];

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, GET_ITEM(13, 35), 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);



		gLog.Output(LOG_CHAOS_MIX, "[PieceOfHornMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gLog.Output(LOG_CHAOS_MIX, "[PieceOfHornMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

//Qoay Sừng Gẫy
void CChaosBox::BrokenHornMix(LPOBJ lpObj) // OK
{
	int ChaosCount = 0;
	int ClawOfBeastCount = 0;
	int PieceOfHornCount = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 34))
		{
			ClawOfBeastCount += (int)lpObj->ChaosBox[n].m_Durability;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 35))
		{
			PieceOfHornCount++;
		}
	}

	if (ChaosCount != 1 || ClawOfBeastCount != 10 || PieceOfHornCount != 5)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	lpObj->ChaosSuccessRate = gServerInfo.m_BrokenHornMixRate[lpObj->AccountLevel];

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, GET_ITEM(13, 36), 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(997), lpObj->Name); //Qoay Lên

		gLog.Output(LOG_CHAOS_MIX, "[BrokenHornMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(895), lpObj->Name);  // Ép Xịt

		gLog.Output(LOG_CHAOS_MIX, "[BrokenHornMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

void CChaosBox::HornOfFenrirMix(LPOBJ lpObj) // OK
{
	int ChaosCount = 0;
	int BrokenHornCount = 0;
	int LifeCount = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 36))
		{
			BrokenHornCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 16))
		{
			LifeCount++;
		}
	}

	if (ChaosCount != 1 || BrokenHornCount != 1 || LifeCount != 3)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	lpObj->ChaosSuccessRate = gServerInfo.m_HornOfFenrirMixRate[lpObj->AccountLevel];

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	lpObj->ChaosMoney = 10000000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, GET_ITEM(13, 37), 0, 255, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(999), lpObj->Name);

		gLog.Output(LOG_CHAOS_MIX, "[HornOfFenrirMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(897), lpObj->Name);

		gLog.Output(LOG_CHAOS_MIX, "[HornOfFenrirMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

void CChaosBox::HornOfFenrirUpgradeMix(LPOBJ lpObj) // OK
{
	int ChaosCount = 0;
	int HornOfFenrirCount = 0;
	int LifeCount = 0;
	int WeaponCount = 0;
	int WeaponMoney = 0;
	int ArmorCount = 0;
	int ArmorMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 37))
		{
			HornOfFenrirCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 16))
		{
			LifeCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(0, 0) && lpObj->ChaosBox[n].m_Index < GET_ITEM(6, 0) && lpObj->ChaosBox[n].m_Level >= 4 && lpObj->ChaosBox[n].m_Option3 >= 1)
		{
			WeaponCount++;
			WeaponMoney = lpObj->ChaosBox[n].m_BuyMoney;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(6, 0) && lpObj->ChaosBox[n].m_Index < GET_ITEM(12, 0) && lpObj->ChaosBox[n].m_Level >= 4 && lpObj->ChaosBox[n].m_Option3 >= 1)
		{
			ArmorCount++;
			ArmorMoney = lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosCount != 1 || HornOfFenrirCount != 1 || LifeCount != 5 || (WeaponCount == 0 && ArmorCount == 0) || (WeaponCount != 0 && ArmorCount != 0))
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_HornOfFenrirUpgradeMixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (WeaponMoney + ArmorMoney) / 10000;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_HornOfFenrirUpgradeMixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_HornOfFenrirUpgradeMixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>80) ? 80 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = 10000000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		BYTE ItemNewOption = ((WeaponCount == 0) ? ((ArmorCount == 0) ? 0 : 2) : 1);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, GET_ITEM(13, 37), 0, 255, 1, 0, 0, -1, ItemNewOption, 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(999), lpObj->Name);

		gLog.Output(LOG_CHAOS_MIX, "[HornOfFenrirUpgradeMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(897), lpObj->Name);

		gLog.Output(LOG_CHAOS_MIX, "[HornOfFenrirUpgradeMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

//Qoay Sói Hoàng Kim
void CChaosBox::HornOfFenrirGoldMix(LPOBJ lpObj) // OK
{
	int FenrirThuong = 0;
	int FenrirTC = 0;
	int FenrirPT = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 37) && lpObj->ChaosBox[n].m_NewOption == 0)
		{
			FenrirThuong++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 37) && lpObj->ChaosBox[n].m_NewOption == 1)
		{
			FenrirTC++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 37) && lpObj->ChaosBox[n].m_NewOption == 2)
		{
			FenrirPT++;
		}
	}

	if (FenrirThuong != 1 || FenrirTC != 1 || FenrirPT != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	lpObj->ChaosSuccessRate = gServerInfo.m_HornOfFenrirGoldMixRate[lpObj->AccountLevel];

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	lpObj->ChaosMoney = 10000000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, GET_ITEM(13, 37), 0, 255, 1, 0, 0, -1, 4, 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(996), lpObj->Name);

		gLog.Output(LOG_CHAOS_MIX, "[HornOfFenrirGoldMix][Success][%s][%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(896), lpObj->Name);

		gLog.Output(LOG_CHAOS_MIX, "[HornOfFenrirGoldMix][Failure][%s][%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}



void CChaosBox::ShieldPotionMix(LPOBJ lpObj, int type) // OK
{
	int LargeHealingPotionCount = 0;
	int SmallCompoundPotionCount = 0;
	int MediumCompoundPotionCount = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 3))
		{
			LargeHealingPotionCount += (int)lpObj->ChaosBox[n].m_Durability;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 38))
		{
			SmallCompoundPotionCount += (int)lpObj->ChaosBox[n].m_Durability;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 39))
		{
			MediumCompoundPotionCount += (int)lpObj->ChaosBox[n].m_Durability;
		}
	}

	if ((type == 0 && LargeHealingPotionCount != 3) || (type == 1 && SmallCompoundPotionCount != 3) || (type == 2 && MediumCompoundPotionCount != 3))
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	switch (type)
	{
	case 0:
		lpObj->ChaosSuccessRate = gServerInfo.m_ShieldPotionMixRate1[lpObj->AccountLevel];
		break;
	case 1:
		lpObj->ChaosSuccessRate = gServerInfo.m_ShieldPotionMixRate2[lpObj->AccountLevel];
		break;
	case 2:
		lpObj->ChaosSuccessRate = gServerInfo.m_ShieldPotionMixRate3[lpObj->AccountLevel];
		break;
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	lpObj->ChaosMoney = ((type == 0) ? 100000 : (500000 * type));

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, (GET_ITEM(14, 35) + type), 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gLog.Output(LOG_CHAOS_MIX, "[ShieldPotionMix][Thành Công] Account:[%s] Name:[%s] - (Type: %d, ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, type, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gLog.Output(LOG_CHAOS_MIX, "[ShieldPotionMix][Thất Bại] Account:[%s] Name:[%s] - (Type: %d, ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, type, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

void CChaosBox::JewelOfHarmonyItemPurityMix(LPOBJ lpObj) // OK
{
	int GemStoneCount = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 41))
		{
			GemStoneCount++;
		}
	}

	if (GemStoneCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	lpObj->ChaosSuccessRate = gServerInfo.m_JewelOfHarmonyItemPurityMixRate[lpObj->AccountLevel];

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, GET_ITEM(14, 42), 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gLog.Output(LOG_CHAOS_MIX, "[JewelOfHarmonyItemPurityMix][Thành Công] Account:[%s] Name:[%s]- (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gLog.Output(LOG_CHAOS_MIX, "[JewelOfHarmonyItemPurityMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

void CChaosBox::JewelOfHarmonyItemSmeltMix(LPOBJ lpObj) // OK
{
	int ItemCount = 0;
	int ItemSlot = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (gJewelOfHarmonyType.CheckJewelOfHarmonyItemType(&lpObj->ChaosBox[n]) != 0 && lpObj->ChaosBox[n].IsSetItem() == 0 && lpObj->ChaosBox[n].IsJewelOfHarmonyItem() == 0)
		{
			ItemCount++;
			ItemSlot = n;
		}
	}

	if (ItemCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (lpObj->ChaosBox[ItemSlot].IsExcItem() == 0)
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_JewelOfHarmonyItemSmeltMixRate1[lpObj->AccountLevel];
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_JewelOfHarmonyItemSmeltMixRate2[lpObj->AccountLevel];
	}

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = ((lpObj->ChaosBox[ItemSlot].IsExcItem() == 0) ? GET_ITEM(14, 43) : GET_ITEM(14, 44));

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gLog.Output(LOG_CHAOS_MIX, "[JewelOfHarmonyItemSmeltMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gLog.Output(LOG_CHAOS_MIX, "[JewelOfHarmonyItemSmeltMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

void CChaosBox::JewelOfHarmonyItemRestoreMix(LPOBJ lpObj) // OK
{
	int ItemCount = 0;
	int ItemSlot = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].IsJewelOfHarmonyItem() != 0)
		{
			ItemCount++;
			ItemSlot = n;
		}
	}

	if (ItemCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	lpObj->ChaosMoney = gJewelOfHarmonyOption.GetJewelOfHarmonyItemRestoreMoney(&lpObj->ChaosBox[ItemSlot]);

	if (lpObj->ChaosMoney == -1)
	{
		this->GCChaosMixSend(lpObj->Index, 0, 0);
		return;
	}

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	CItem item = lpObj->ChaosBox[ItemSlot];

	item.m_JewelOfHarmonyOption = JEWEL_OF_HARMONY_OPTION_NONE;

	this->ChaosBoxInit(lpObj);

	gItemManager.ChaosBoxAddItem(lpObj->Index, item, 0);

	this->GCChaosMixSend(lpObj->Index, 1, &item);

	gLog.Output(LOG_CHAOS_MIX, "[JewelOfHarmonyItemRestoreMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
}

void CChaosBox::Item380Mix(LPOBJ lpObj) // OK
{
	int GuardianCount = 0;
	int HarmonyCount = 0;
	int ItemCount = 0;
	int ItemSlot = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 31))
		{
			GuardianCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 42))
		{
			HarmonyCount++;
		}
		else if (lpObj->ChaosBox[n].Is380Item() == 0 && lpObj->ChaosBox[n].m_Level >= 4 && lpObj->ChaosBox[n].m_Option3 >= 1)
		{
			ItemCount++;
			ItemSlot = n;
		}
	}

	if (GuardianCount != 1 || HarmonyCount != 1 || ItemCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (lpObj->ChaosBox[ItemSlot].m_Level >= 7)
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_Item380MixRate2[lpObj->AccountLevel];
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_Item380MixRate1[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	lpObj->ChaosMoney = 10000000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		CItem item = lpObj->ChaosBox[ItemSlot];

		item.m_ItemOptionEx |= 0x80;

		this->ChaosBoxInit(lpObj);

		gItemManager.ChaosBoxAddItem(lpObj->Index, item, 0);

		this->GCChaosMixSend(lpObj->Index, 1, &item);

		gLog.Output(LOG_CHAOS_MIX, "[Item380Mix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxItemKeep(lpObj, ItemSlot);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gLog.Output(LOG_CHAOS_MIX, "[Item380Mix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

void CChaosBox::IllusionTempleMix(LPOBJ lpObj) // OK
{
	int ChaosCount = 0;
	int ScrollCount = 0;
	int ScrollLevel = 0;
	int PotionCount = 0;
	int PotionLevel = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 49))
		{
			ScrollCount++;
			ScrollLevel = lpObj->ChaosBox[n].m_Level;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 50))
		{
			PotionCount++;
			PotionLevel = lpObj->ChaosBox[n].m_Level;
		}
	}

	if (ChaosCount != 1 || ScrollCount != 1 || PotionCount != 1 || ScrollLevel != PotionLevel)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (ScrollLevel > 6 || PotionLevel > 6)
	{
		this->GCChaosMixSend(lpObj->Index, 8, 0);
		return;
	}

	switch (ScrollLevel)
	{
	case 1:
		lpObj->ChaosSuccessRate = gServerInfo.m_IllusionTempleMixRate1[lpObj->AccountLevel];
		lpObj->ChaosMoney = 3000000;
		break;
	case 2:
		lpObj->ChaosSuccessRate = gServerInfo.m_IllusionTempleMixRate2[lpObj->AccountLevel];
		lpObj->ChaosMoney = 5000000;
		break;
	case 3:
		lpObj->ChaosSuccessRate = gServerInfo.m_IllusionTempleMixRate3[lpObj->AccountLevel];
		lpObj->ChaosMoney = 7000000;
		break;
	case 4:
		lpObj->ChaosSuccessRate = gServerInfo.m_IllusionTempleMixRate4[lpObj->AccountLevel];
		lpObj->ChaosMoney = 9000000;
		break;
	case 5:
		lpObj->ChaosSuccessRate = gServerInfo.m_IllusionTempleMixRate5[lpObj->AccountLevel];
		lpObj->ChaosMoney = 11000000;
		break;
	case 6:
		lpObj->ChaosSuccessRate = gServerInfo.m_IllusionTempleMixRate6[lpObj->AccountLevel];
		lpObj->ChaosMoney = 13000000;
		break;
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, GET_ITEM(13, 51), ScrollLevel, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gLog.Output(LOG_CHAOS_MIX, "[IllusionTempleMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gLog.Output(LOG_CHAOS_MIX, "[IllusionTempleMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

void CChaosBox::FeatherOfCondorMix(LPOBJ lpObj) // OK
{
	int ChaosCount = 0;
	int CreationCount = 0;
	int SoulPack10 = 0;
	int WingCount = 0;
	int ItemCount = 0;
	int ItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 22))
		{
			CreationCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 31) && lpObj->ChaosBox[n].m_Level == 0)
		{
			SoulPack10++;
		}
		else if (((lpObj->ChaosBox[n].m_Index >= GET_ITEM(12, 3) && lpObj->ChaosBox[n].m_Index <= GET_ITEM(12, 6)) || lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 42) || lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 49) || lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 30)) && (lpObj->ChaosBox[n].m_Level >= 9 && lpObj->ChaosBox[n].m_Option3 >= 1))
		{
			WingCount++;
		}
		else if (lpObj->ChaosBox[n].IsSetItem() != 0 && lpObj->ChaosBox[n].m_Level >= 7 && lpObj->ChaosBox[n].m_Option3 >= 1)
		{
			ItemCount++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosCount != 1 || CreationCount != 1 || SoulPack10 != 1 || WingCount != 1 || ItemCount == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_FeatherOfCondorMixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 300000) + 1;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_FeatherOfCondorMixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_FeatherOfCondorMixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>60) ? 60 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = lpObj->ChaosSuccessRate * 200000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, GET_ITEM(13, 53), 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gLog.Output(LOG_CHAOS_MIX, "[FeatherOfCondorMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gLog.Output(LOG_CHAOS_MIX, "[FeatherOfCondorMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

void CChaosBox::Wing3Mix(LPOBJ lpObj) // OK
{
	int ChaosCount = 0;
	int CreationCount = 0;
	int SoulPack10 = 0;
	int BlessPack10 = 0;
	int FlameCount = 0;
	int FeatherCount = 0;
	int ItemCount = 0;
	int ItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 22))
		{
			CreationCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 31) && lpObj->ChaosBox[n].m_Level == 0)
		{
			SoulPack10++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 30) && lpObj->ChaosBox[n].m_Level == 0)
		{
			BlessPack10++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 52))
		{
			FlameCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 53))
		{
			FeatherCount++;
		}
		else if (lpObj->ChaosBox[n].IsExcItem() != 0 && lpObj->ChaosBox[n].m_Level >= 9 && lpObj->ChaosBox[n].m_Option3 >= 1)
		{
			ItemCount++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosCount != 1 || CreationCount != 1 || SoulPack10 != 1 || BlessPack10 != 1 || FlameCount != 1 || FeatherCount != 1 || ItemCount == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_Wing3MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 3000000) + 1;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_Wing3MixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_Wing3MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>40) ? 40 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = lpObj->ChaosSuccessRate * 200000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;
		BYTE ItemOption2 = 0;
		BYTE ItemOption3 = 0;
		BYTE ItemNewOption = 0;

		CRandomManager RandomManager;

		RandomManager.AddElement(GET_ITEM(12, 36), 1);

		RandomManager.AddElement(GET_ITEM(12, 37), 1);

		RandomManager.AddElement(GET_ITEM(12, 38), 1);

		RandomManager.AddElement(GET_ITEM(12, 39), 1);

		for (int i = 0; i < gCustomWingMix.m_count; i++)
		{
			RandomManager.AddElement(GET_ITEM(gCustomWingMix.m_Data[i].m_Category, gCustomWingMix.m_Data[i].m_Index), 1);
		}

		if (gServerInfo.m_DisableWingMixDL != 1)
		{
			RandomManager.AddElement(GET_ITEM(12, 40), 1);
		}

		if (gServerInfo.m_DisableWingMixSU != 1)
		{
			RandomManager.AddElement(GET_ITEM(12, 43), 1);
		}

#if(GAMESERVER_UPDATE>=601)

		if (gServerInfo.m_DisableWingMixRF != 1)
		{
			RandomManager.AddElement(GET_ITEM(12, 50), 1);
		}

#endif

		ITEM_INFO ItemInfo;

		RandomManager.GetRandomElement(&ItemIndex);

		gItemOptionRate.GetItemOption2(6, &ItemOption2);

		gItemOptionRate.GetItemOption3(6, &ItemOption3);

		gItemOptionRate.GetItemOption4(6, &ItemNewOption);

		gItemOptionRate.MakeNewOption(ItemIndex, ItemNewOption, &ItemNewOption);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, ItemOption2, ItemOption3, -1, (ItemNewOption + (16 * (GetLargeRand() % 3))), 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(1000), lpObj->Name, gItemManager.GetItemName(ItemIndex));

		gLog.Output(LOG_CHAOS_MIX, "[Wing3Mix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(891), lpObj->Name);

		gLog.Output(LOG_CHAOS_MIX, "[Wing3Mix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}




//----------------------------------------------------------------------------------
#if(CUSTOM_MIX_WING_CUSTOM)
void CChaosBox::WingCustomMix(LPOBJ lpObj) // OK
{
	int ChaosPack30 = 0;
	int CreationPack30 = 0;
	int SoulPack30 = 0;
	int BlessPack30 = 0;
	int LifePack30 = 0;
	int ItemMix = 0;
	int GarudaFeatherCount = 0;
	int ItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 141) && lpObj->ChaosBox[n].m_Level == 2)
		{
			ChaosPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 137) && lpObj->ChaosBox[n].m_Level == 2)
		{
			CreationPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 31) && lpObj->ChaosBox[n].m_Level == 2)
		{
			SoulPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 30) && lpObj->ChaosBox[n].m_Level == 2)
		{
			BlessPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 136) && lpObj->ChaosBox[n].m_Level == 2)
		{
			LifePack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(14, 181))
		{
			ItemMix++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosPack30 != 1 || CreationPack30 != 1 || SoulPack30 != 1 || BlessPack30 != 1 || LifePack30 != 1 || ItemMix != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_WingCustomMixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 3000000) + 1;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_WingCustomMixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_WingCustomMixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>40) ? 40 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = lpObj->ChaosSuccessRate * 200000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;
		BYTE ItemOption2 = 0;
		BYTE ItemOption3 = 0;
		BYTE ItemNewOption = 0;

		CRandomManager RandomManager;

		RandomManager.AddElement(GET_ITEM(12, 180), 1);

		RandomManager.AddElement(GET_ITEM(12, 181), 1);

		RandomManager.AddElement(GET_ITEM(12, 182), 1);

		RandomManager.AddElement(GET_ITEM(12, 183), 1);

		RandomManager.AddElement(GET_ITEM(12, 184), 1);

		RandomManager.AddElement(GET_ITEM(12, 185), 1);

		RandomManager.AddElement(GET_ITEM(12, 186), 1);

		RandomManager.AddElement(GET_ITEM(12, 187), 1);

		RandomManager.AddElement(GET_ITEM(12, 188), 1);

		RandomManager.AddElement(GET_ITEM(12, 189), 1);

		RandomManager.AddElement(GET_ITEM(12, 190), 1);

		RandomManager.AddElement(GET_ITEM(12, 191), 1);

		RandomManager.AddElement(GET_ITEM(12, 192), 1);

		RandomManager.AddElement(GET_ITEM(12, 193), 1);

		RandomManager.AddElement(GET_ITEM(12, 194), 1);

		RandomManager.AddElement(GET_ITEM(12, 195), 1);

		RandomManager.AddElement(GET_ITEM(12, 196), 1);

		RandomManager.AddElement(GET_ITEM(12, 197), 1);

		RandomManager.AddElement(GET_ITEM(12, 198), 1);

		RandomManager.AddElement(GET_ITEM(12, 199), 1);



		RandomManager.GetRandomElement(&ItemIndex);

		gItemOptionRate.GetItemOption2(6, &ItemOption2);

		gItemOptionRate.GetItemOption3(6, &ItemOption3);

		gItemOptionRate.GetItemOption4(6, &ItemNewOption);

		gItemOptionRate.MakeNewOption(ItemIndex, ItemNewOption, &ItemNewOption);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, ItemOption2, ItemOption3, -1, (ItemNewOption + (16 * (GetLargeRand() % 3))), 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(910), lpObj->Name, gItemManager.GetItemName(ItemIndex));

		gLog.Output(LOG_CHAOS_MIX, "[WingCustomMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(911), lpObj->Name); // 751	"[%s] Chế tạo thất bại Cánh Custom!"

		gLog.Output(LOG_CHAOS_MIX, "[WingCustomMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}
#endif
//----------------------------------------------------------------------------------
#if(CUSTOM_MIX_WING_SEASON13)
void CChaosBox::WingSeason13Mix(LPOBJ lpObj) // OK
{
	int ChaosPack30 = 0;
	int CreationPack30 = 0;
	int SoulPack30 = 0;
	int BlessPack30 = 0;
	int LifePack30 = 0;
	int ItemMix = 0;
	int GarudaFeatherCount = 0;
	int ItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 141) && lpObj->ChaosBox[n].m_Level == 2)
		{
			ChaosPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 137) && lpObj->ChaosBox[n].m_Level == 2)
		{
			CreationPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 31) && lpObj->ChaosBox[n].m_Level == 2)
		{
			SoulPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 30) && lpObj->ChaosBox[n].m_Level == 2)
		{
			BlessPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 136) && lpObj->ChaosBox[n].m_Level == 2)
		{
			LifePack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(14, 182))
		{
			ItemMix++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosPack30 != 1 || CreationPack30 != 1 || SoulPack30 != 1 || BlessPack30 != 1 || LifePack30 != 1 || ItemMix != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_WingSeason13MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 3000000) + 1;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_WingSeason13MixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_WingSeason13MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>40) ? 40 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = lpObj->ChaosSuccessRate * 200000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;
		BYTE ItemOption2 = 0;
		BYTE ItemOption3 = 0;
		BYTE ItemNewOption = 0;

		CRandomManager RandomManager;

		RandomManager.AddElement(GET_ITEM(12, 156), 1);

		RandomManager.AddElement(GET_ITEM(12, 157), 1);

		RandomManager.AddElement(GET_ITEM(12, 158), 1);

		RandomManager.AddElement(GET_ITEM(12, 159), 1);

		RandomManager.AddElement(GET_ITEM(12, 160), 1);

		RandomManager.AddElement(GET_ITEM(12, 161), 1);

		RandomManager.AddElement(GET_ITEM(12, 162), 1);

		RandomManager.GetRandomElement(&ItemIndex);

		gItemOptionRate.GetItemOption2(6, &ItemOption2);

		gItemOptionRate.GetItemOption3(6, &ItemOption3);

		gItemOptionRate.GetItemOption4(6, &ItemNewOption);

		gItemOptionRate.MakeNewOption(ItemIndex, ItemNewOption, &ItemNewOption);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, ItemOption2, ItemOption3, -1, (ItemNewOption + (16 * (GetLargeRand() % 5))), 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(912), lpObj->Name, gItemManager.GetItemName(ItemIndex));

		gLog.Output(LOG_CHAOS_MIX, "[WingSeason13Mix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(913), lpObj->Name); // 753	"[%s] Chế tạo thất bại Cánh Season 13!"

		gLog.Output(LOG_CHAOS_MIX, "[WingSeason13Mix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}
#endif
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
#if(CUSTOM_MIX_WING_SEASON8)
void CChaosBox::WingSeason8Mix(LPOBJ lpObj) // OK
{
	int ChaosPack30 = 0;
	int CreationPack30 = 0;
	int SoulPack30 = 0;
	int BlessPack30 = 0;
	int LifePack30 = 0;
	int ItemMix = 0;
	int GarudaFeatherCount = 0;
	int ItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 141) && lpObj->ChaosBox[n].m_Level == 2)
		{
			ChaosPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 137) && lpObj->ChaosBox[n].m_Level == 2)
		{
			CreationPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 31) && lpObj->ChaosBox[n].m_Level == 2)
		{
			SoulPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 30) && lpObj->ChaosBox[n].m_Level == 2)
		{
			BlessPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 136) && lpObj->ChaosBox[n].m_Level == 2)
		{
			LifePack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(14, 183))
		{
			ItemMix++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosPack30 != 1 || CreationPack30 != 1 || SoulPack30 != 1 || BlessPack30 != 1 || LifePack30 != 1 || ItemMix != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_WingSeason8MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 3000000) + 1;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_WingSeason8MixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_WingSeason8MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>40) ? 40 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = lpObj->ChaosSuccessRate * 200000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;
		BYTE ItemOption2 = 0;
		BYTE ItemOption3 = 0;
		BYTE ItemNewOption = 0;

		CRandomManager RandomManager;

		RandomManager.AddElement(GET_ITEM(12, 153), 1);

		RandomManager.AddElement(GET_ITEM(12, 154), 1);

		RandomManager.GetRandomElement(&ItemIndex);

		gItemOptionRate.GetItemOption2(6, &ItemOption2);

		gItemOptionRate.GetItemOption3(6, &ItemOption3);

		gItemOptionRate.GetItemOption4(6, &ItemNewOption);

		gItemOptionRate.MakeNewOption(ItemIndex, ItemNewOption, &ItemNewOption);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, ItemOption2, ItemOption3, -1, (ItemNewOption + (16 * (GetLargeRand() % 5))), 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(914), lpObj->Name, gItemManager.GetItemName(ItemIndex));

		gLog.Output(LOG_CHAOS_MIX, "[WingSeason8Mix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(915), lpObj->Name); // 757	"[%s] Chế tạo thất bại Cánh Season 8!"

		gLog.Output(LOG_CHAOS_MIX, "[WingSeason8Mix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}
#endif
//----------------------------------------------------------------------------------

#if(CUSTOM_MIX_WING_VIP)
void CChaosBox::WingVipMix(LPOBJ lpObj) // OK
{
	int ChaosPack30 = 0;
	int CreationPack30 = 0;
	int SoulPack30 = 0;
	int BlessPack30 = 0;
	int LifePack30 = 0;
	int ItemMix = 0;
	int GarudaFeatherCount = 0;
	int ItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 141) && lpObj->ChaosBox[n].m_Level == 2)
		{
			ChaosPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 137) && lpObj->ChaosBox[n].m_Level == 2)
		{
			CreationPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 31) && lpObj->ChaosBox[n].m_Level == 2)
		{
			SoulPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 30) && lpObj->ChaosBox[n].m_Level == 2)
		{
			BlessPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 136) && lpObj->ChaosBox[n].m_Level == 2)
		{
			LifePack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(14, 183))
		{
			ItemMix++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosPack30 != 1 || CreationPack30 != 1 || SoulPack30 != 1 || BlessPack30 != 1 || LifePack30 != 1 || ItemMix != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_WingSeason8MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 3000000) + 1;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_WingSeason8MixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_WingSeason8MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>40) ? 40 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = lpObj->ChaosSuccessRate * 200000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;
		BYTE ItemOption2 = 0;
		BYTE ItemOption3 = 0;
		BYTE ItemNewOption = 0;

		CRandomManager RandomManager;

		RandomManager.AddElement(GET_ITEM(12, 403), 1);
		RandomManager.AddElement(GET_ITEM(12, 404), 1);
		RandomManager.AddElement(GET_ITEM(12, 405), 1);
		RandomManager.AddElement(GET_ITEM(12, 406), 1);
		RandomManager.AddElement(GET_ITEM(12, 407), 1);
		RandomManager.AddElement(GET_ITEM(12, 408), 1);
		RandomManager.AddElement(GET_ITEM(12, 409), 1);
		RandomManager.AddElement(GET_ITEM(12, 410), 1);
		RandomManager.AddElement(GET_ITEM(12, 411), 1);
		RandomManager.AddElement(GET_ITEM(12, 412), 1);
		RandomManager.AddElement(GET_ITEM(12, 413), 1);
		RandomManager.AddElement(GET_ITEM(12, 414), 1);
		RandomManager.AddElement(GET_ITEM(12, 415), 1);
		RandomManager.AddElement(GET_ITEM(12, 416), 1);
		RandomManager.AddElement(GET_ITEM(12, 417), 1);
		RandomManager.AddElement(GET_ITEM(12, 418), 1);
		RandomManager.AddElement(GET_ITEM(12, 419), 1);
		RandomManager.AddElement(GET_ITEM(12, 420), 1);
		RandomManager.AddElement(GET_ITEM(12, 421), 1);
		RandomManager.AddElement(GET_ITEM(12, 422), 1);
		RandomManager.AddElement(GET_ITEM(12, 423), 1);
		RandomManager.AddElement(GET_ITEM(12, 424), 1);
		RandomManager.AddElement(GET_ITEM(12, 425), 1);
		RandomManager.AddElement(GET_ITEM(12, 426), 1);
		RandomManager.AddElement(GET_ITEM(12, 427), 1);
		RandomManager.AddElement(GET_ITEM(12, 428), 1);
		RandomManager.AddElement(GET_ITEM(12, 429), 1);
		RandomManager.AddElement(GET_ITEM(12, 430), 1);
		RandomManager.AddElement(GET_ITEM(12, 431), 1);
		RandomManager.AddElement(GET_ITEM(12, 432), 1);
		RandomManager.AddElement(GET_ITEM(12, 433), 1);
		RandomManager.AddElement(GET_ITEM(12, 434), 1);
		RandomManager.AddElement(GET_ITEM(12, 435), 1);
		RandomManager.AddElement(GET_ITEM(12, 436), 1);
		RandomManager.AddElement(GET_ITEM(12, 437), 1);
		RandomManager.AddElement(GET_ITEM(12, 438), 1);
		RandomManager.AddElement(GET_ITEM(12, 439), 1);
		RandomManager.AddElement(GET_ITEM(12, 440), 1);
		RandomManager.AddElement(GET_ITEM(12, 441), 1);
		RandomManager.AddElement(GET_ITEM(12, 442), 1);
		RandomManager.AddElement(GET_ITEM(12, 443), 1);
		RandomManager.AddElement(GET_ITEM(12, 444), 1);
		RandomManager.AddElement(GET_ITEM(12, 445), 1);
		RandomManager.AddElement(GET_ITEM(12, 446), 1);
		RandomManager.AddElement(GET_ITEM(12, 447), 1);
		RandomManager.AddElement(GET_ITEM(12, 448), 1);
		RandomManager.AddElement(GET_ITEM(12, 449), 1);
		RandomManager.AddElement(GET_ITEM(12, 450), 1);
		RandomManager.AddElement(GET_ITEM(12, 451), 1);
		RandomManager.AddElement(GET_ITEM(12, 452), 1);
		RandomManager.AddElement(GET_ITEM(12, 453), 1);

		RandomManager.GetRandomElement(&ItemIndex);

		gItemOptionRate.GetItemOption2(6, &ItemOption2);

		gItemOptionRate.GetItemOption3(6, &ItemOption3);

		gItemOptionRate.GetItemOption4(6, &ItemNewOption);

		gItemOptionRate.MakeNewOption(ItemIndex, ItemNewOption, &ItemNewOption);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, ItemOption2, ItemOption3, -1, (ItemNewOption + (16 * (GetLargeRand() % 5))), 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(916), lpObj->Name, gItemManager.GetItemName(ItemIndex));

		gLog.Output(LOG_CHAOS_MIX, "[WingVipMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(917), lpObj->Name); // 757	"[%s] Chế tạo thất bại Cánh Season 8!"

		gLog.Output(LOG_CHAOS_MIX, "[WingVipMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}
#endif
//----------------------------------------------------------------------------------
#if(CUSTOM_MIX_PET_CAP2)
void CChaosBox::Muun2Mix(LPOBJ lpObj) // OK
{
	int ChaosPack30 = 0;
	int CreationPack30 = 0;
	int SoulPack30 = 0;
	int BlessPack30 = 0;
	int ItemMix = 0;
	int ItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 141) && lpObj->ChaosBox[n].m_Level == 2)
		{
			ChaosPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 137) && lpObj->ChaosBox[n].m_Level == 2)
		{
			CreationPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 31) && lpObj->ChaosBox[n].m_Level == 2)
		{
			SoulPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 30) && lpObj->ChaosBox[n].m_Level == 2)
		{
			BlessPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(13, 200) && lpObj->ChaosBox[n].m_Index <= GET_ITEM(13, 230))
		{
			ItemMix++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosPack30 != 1 || CreationPack30 != 1 || SoulPack30 != 1 || BlessPack30 != 1 || ItemMix != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_Muun2MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 3000000) + 1;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_Muun2MixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_Muun2MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>40) ? 40 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = lpObj->ChaosSuccessRate * 200000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;

		CRandomManager RandomManager;

		RandomManager.AddElement(GET_ITEM(13, 255), 1);

		RandomManager.AddElement(GET_ITEM(13, 256), 1);

		RandomManager.AddElement(GET_ITEM(13, 257), 1);

		RandomManager.AddElement(GET_ITEM(13, 258), 1);

		RandomManager.AddElement(GET_ITEM(13, 259), 1);


		RandomManager.GetRandomElement(&ItemIndex);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(898), lpObj->Name, gItemManager.GetItemName(ItemIndex));

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap2][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(899), lpObj->Name); // 751	"[%s] Chế tạo thất bại Pet cap 2"

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap2][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}
//
#endif
#if(CUSTOM_MIX_PET_CAP3)
void CChaosBox::Muun3Mix(LPOBJ lpObj) // OK
{
	int ChaosPack30 = 0;
	int CreationPack30 = 0;
	int SoulPack30 = 0;
	int BlessPack30 = 0;
	int ItemMix = 0;
	int ItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 141) && lpObj->ChaosBox[n].m_Level == 2)
		{
			ChaosPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 137) && lpObj->ChaosBox[n].m_Level == 2)
		{
			CreationPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 31) && lpObj->ChaosBox[n].m_Level == 2)
		{
			SoulPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 30) && lpObj->ChaosBox[n].m_Level == 2)
		{
			BlessPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(13, 255) && lpObj->ChaosBox[n].m_Index <= GET_ITEM(13, 259))
		{
			ItemMix++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosPack30 != 1 || CreationPack30 != 1 || SoulPack30 != 1 || BlessPack30 != 1 || ItemMix != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_Muun3MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 3000000) + 1;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_Muun3MixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_Muun3MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>40) ? 40 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = lpObj->ChaosSuccessRate * 200000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;

		CRandomManager RandomManager;

		RandomManager.AddElement(GET_ITEM(13, 260), 1);

		RandomManager.AddElement(GET_ITEM(13, 261), 1);

		RandomManager.AddElement(GET_ITEM(13, 262), 1);

		RandomManager.AddElement(GET_ITEM(13, 263), 1);

		RandomManager.AddElement(GET_ITEM(13, 264), 1);

		RandomManager.AddElement(GET_ITEM(13, 265), 1);

		RandomManager.AddElement(GET_ITEM(13, 266), 1);



		RandomManager.GetRandomElement(&ItemIndex);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(900), lpObj->Name, gItemManager.GetItemName(ItemIndex));

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap3][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(901), lpObj->Name); // 751	"[%s] Chế tạo thất bại Pet cap 3"

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap3][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}
#endif

//
#if(CUSTOM_MIX_PET_CAP4)
void CChaosBox::Muun4Mix(LPOBJ lpObj) // OK
{
	int ChaosPack30 = 0;
	int CreationPack30 = 0;
	int SoulPack30 = 0;
	int BlessPack30 = 0;
	int ItemMix = 0;
	int ItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 141) && lpObj->ChaosBox[n].m_Level == 2)
		{
			ChaosPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 137) && lpObj->ChaosBox[n].m_Level == 2)
		{
			CreationPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 31) && lpObj->ChaosBox[n].m_Level == 2)
		{
			SoulPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 30) && lpObj->ChaosBox[n].m_Level == 2)
		{
			BlessPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(13, 260) && lpObj->ChaosBox[n].m_Index <= GET_ITEM(13, 266))
		{
			ItemMix++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosPack30 != 1 || CreationPack30 != 1 || SoulPack30 != 1 || BlessPack30 != 1 || ItemMix != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_Muun4MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 3000000) + 1;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_Muun4MixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_Muun4MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>40) ? 40 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = lpObj->ChaosSuccessRate * 200000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;

		CRandomManager RandomManager;

		RandomManager.AddElement(GET_ITEM(13, 267), 1);

		RandomManager.AddElement(GET_ITEM(13, 267), 1);

		RandomManager.AddElement(GET_ITEM(13, 268), 1);

		RandomManager.AddElement(GET_ITEM(13, 269), 1);

		RandomManager.AddElement(GET_ITEM(13, 270), 1);

		RandomManager.AddElement(GET_ITEM(13, 271), 1);

		RandomManager.AddElement(GET_ITEM(13, 272), 1);



		RandomManager.GetRandomElement(&ItemIndex);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(902), lpObj->Name, gItemManager.GetItemName(ItemIndex));

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap4][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(903), lpObj->Name); // 751	"[%s] Chế tạo thất bại Pet cap 4"

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap4][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}
//
#endif

#if(CUSTOM_MIX_PET_CAP5)
void CChaosBox::Muun5Mix(LPOBJ lpObj) // OK
{
	int ChaosPack30 = 0;
	int CreationPack30 = 0;
	int SoulPack30 = 0;
	int BlessPack30 = 0;
	int ItemMix = 0;
	int ItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 141) && lpObj->ChaosBox[n].m_Level == 2)
		{
			ChaosPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 137) && lpObj->ChaosBox[n].m_Level == 2)
		{
			CreationPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 31) && lpObj->ChaosBox[n].m_Level == 2)
		{
			SoulPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 30) && lpObj->ChaosBox[n].m_Level == 2)
		{
			BlessPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(13, 267) && lpObj->ChaosBox[n].m_Index <= GET_ITEM(13, 272))
		{
			ItemMix++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosPack30 != 1 || CreationPack30 != 1 || SoulPack30 != 1 || BlessPack30 != 1 || ItemMix != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_Muun5MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 3000000) + 1;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_Muun5MixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_Muun5MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>40) ? 40 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = lpObj->ChaosSuccessRate * 200000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;

		CRandomManager RandomManager;

		RandomManager.AddElement(GET_ITEM(13, 273), 1);

		RandomManager.AddElement(GET_ITEM(13, 274), 1);

		RandomManager.AddElement(GET_ITEM(13, 275), 1);

		RandomManager.AddElement(GET_ITEM(13, 276), 1);


		RandomManager.GetRandomElement(&ItemIndex);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(904), lpObj->Name, gItemManager.GetItemName(ItemIndex));

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap5][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(905), lpObj->Name); // 751	"[%s] Chế tạo thất bại Pet cap 5"

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap5][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}
//
#endif

#if(CUSTOM_MIX_PET_CAP6)
void CChaosBox::Muun6Mix(LPOBJ lpObj) // OK
{
	int ChaosPack30 = 0;
	int CreationPack30 = 0;
	int SoulPack30 = 0;
	int BlessPack30 = 0;
	int ItemMix = 0;
	int ItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 141) && lpObj->ChaosBox[n].m_Level == 2)
		{
			ChaosPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 137) && lpObj->ChaosBox[n].m_Level == 2)
		{
			CreationPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 31) && lpObj->ChaosBox[n].m_Level == 2)
		{
			SoulPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 30) && lpObj->ChaosBox[n].m_Level == 2)
		{
			BlessPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(13, 273) && lpObj->ChaosBox[n].m_Index <= GET_ITEM(13, 276))
		{
			ItemMix++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosPack30 != 1 || CreationPack30 != 1 || SoulPack30 != 1 || BlessPack30 != 1 || ItemMix != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_Muun6MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 3000000) + 1;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_Muun6MixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_Muun6MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>40) ? 40 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = lpObj->ChaosSuccessRate * 200000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;

		CRandomManager RandomManager;

		RandomManager.AddElement(GET_ITEM(13, 277), 1);

		RandomManager.AddElement(GET_ITEM(13, 278), 1);

		RandomManager.AddElement(GET_ITEM(13, 279), 1);

		RandomManager.AddElement(GET_ITEM(13, 280), 1);



		RandomManager.GetRandomElement(&ItemIndex);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(906), lpObj->Name, gItemManager.GetItemName(ItemIndex));

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap6][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(907), lpObj->Name); // 751	"[%s] Chế tạo thất bại Pet cap 4"

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap6][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}
//

#endif

#if(CUSTOM_MIX_PET_CAP7)
void CChaosBox::Muun7Mix(LPOBJ lpObj) // OK
{
	int ChaosPack30 = 0;
	int CreationPack30 = 0;
	int SoulPack30 = 0;
	int BlessPack30 = 0;
	int ItemMix = 0;
	int ItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 141) && lpObj->ChaosBox[n].m_Level == 2)
		{
			ChaosPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 137) && lpObj->ChaosBox[n].m_Level == 2)
		{
			CreationPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 31) && lpObj->ChaosBox[n].m_Level == 2)
		{
			SoulPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 30) && lpObj->ChaosBox[n].m_Level == 2)
		{
			BlessPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(13, 277) && lpObj->ChaosBox[n].m_Index <= GET_ITEM(13, 280))
		{
			ItemMix++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosPack30 != 1 || CreationPack30 != 1 || SoulPack30 != 1 || BlessPack30 != 1 || ItemMix != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_Muun7MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 3000000) + 1;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_Muun7MixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_Muun7MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>40) ? 40 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = lpObj->ChaosSuccessRate * 200000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;

		CRandomManager RandomManager;

		RandomManager.AddElement(GET_ITEM(13, 281), 1);

		RandomManager.AddElement(GET_ITEM(13, 282), 1);

		RandomManager.AddElement(GET_ITEM(13, 283), 1);


		RandomManager.GetRandomElement(&ItemIndex);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(908), lpObj->Name, gItemManager.GetItemName(ItemIndex));

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap7][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(909), lpObj->Name); // 751	"[%s] Chế tạo thất bại Pet cap 4"

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap7][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}
//

#endif

#if(CUSTOM_MIX_PET_CAP8)
void CChaosBox::Muun8Mix(LPOBJ lpObj) // OK
{
	int ChaosPack30 = 0;
	int CreationPack30 = 0;
	int SoulPack30 = 0;
	int BlessPack30 = 0;
	int ItemMix = 0;
	int ItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 141) && lpObj->ChaosBox[n].m_Level == 2)
		{
			ChaosPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 137) && lpObj->ChaosBox[n].m_Level == 2)
		{
			CreationPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 31) && lpObj->ChaosBox[n].m_Level == 2)
		{
			SoulPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 30) && lpObj->ChaosBox[n].m_Level == 2)
		{
			BlessPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(13, 281) && lpObj->ChaosBox[n].m_Index <= GET_ITEM(13, 283))
		{
			ItemMix++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosPack30 != 1 || CreationPack30 != 1 || SoulPack30 != 1 || BlessPack30 != 1 || ItemMix != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_Muun8MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 3000000) + 1;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_Muun8MixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_Muun8MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>40) ? 40 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = lpObj->ChaosSuccessRate * 200000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;

		CRandomManager RandomManager;

		RandomManager.AddElement(GET_ITEM(13, 284), 1);

		RandomManager.AddElement(GET_ITEM(13, 285), 1);

		RandomManager.AddElement(GET_ITEM(13, 286), 1);


		RandomManager.GetRandomElement(&ItemIndex);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(966), lpObj->Name, gItemManager.GetItemName(ItemIndex));

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap8][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(967), lpObj->Name); // 751	"[%s] Chế tạo thất bại Pet cap 4"

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap8][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}
//
#endif


#if(CUSTOM_MIX_PET_CAP9)
void CChaosBox::Muun9Mix(LPOBJ lpObj) // OK
{
	int ChaosPack30 = 0;
	int CreationPack30 = 0;
	int SoulPack30 = 0;
	int BlessPack30 = 0;
	int ItemMix = 0;
	int ItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 141) && lpObj->ChaosBox[n].m_Level == 2)
		{
			ChaosPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 137) && lpObj->ChaosBox[n].m_Level == 2)
		{
			CreationPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 31) && lpObj->ChaosBox[n].m_Level == 2)
		{
			SoulPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 30) && lpObj->ChaosBox[n].m_Level == 2)
		{
			BlessPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(13, 284) && lpObj->ChaosBox[n].m_Index <= GET_ITEM(13, 286))
		{
			ItemMix++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosPack30 != 1 || CreationPack30 != 1 || SoulPack30 != 1 || BlessPack30 != 1 || ItemMix != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_Muun9MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 3000000) + 1;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_Muun9MixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_Muun9MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>40) ? 40 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = lpObj->ChaosSuccessRate * 200000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;

		CRandomManager RandomManager;

		RandomManager.AddElement(GET_ITEM(13, 287), 1);

		RandomManager.AddElement(GET_ITEM(13, 288), 1);

		RandomManager.AddElement(GET_ITEM(13, 289), 1);


		RandomManager.GetRandomElement(&ItemIndex);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(968), lpObj->Name, gItemManager.GetItemName(ItemIndex));

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap9][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(969), lpObj->Name); // 751	"[%s] Chế tạo thất bại Pet cap 4"

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap9][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}
//
#endif

#if(CUSTOM_MIX_PET_CAP10)
void CChaosBox::Muun10Mix(LPOBJ lpObj) // OK
{
	int ChaosPack30 = 0;
	int CreationPack30 = 0;
	int SoulPack30 = 0;
	int BlessPack30 = 0;
	int ItemMix = 0;
	int ItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 141) && lpObj->ChaosBox[n].m_Level == 2)
		{
			ChaosPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 137) && lpObj->ChaosBox[n].m_Level == 2)
		{
			CreationPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 31) && lpObj->ChaosBox[n].m_Level == 2)
		{
			SoulPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 30) && lpObj->ChaosBox[n].m_Level == 2)
		{
			BlessPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(13, 287) && lpObj->ChaosBox[n].m_Index <= GET_ITEM(13, 289))
		{
			ItemMix++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosPack30 != 1 || CreationPack30 != 1 || SoulPack30 != 1 || BlessPack30 != 1 || ItemMix != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_Muun10MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 3000000) + 1;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_Muun10MixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_Muun10MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>40) ? 40 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = lpObj->ChaosSuccessRate * 200000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;

		CRandomManager RandomManager;

		RandomManager.AddElement(GET_ITEM(13, 380), 1);
		RandomManager.AddElement(GET_ITEM(13, 381), 1);
		RandomManager.AddElement(GET_ITEM(13, 382), 1);
		RandomManager.AddElement(GET_ITEM(13, 383), 1);
		RandomManager.AddElement(GET_ITEM(13, 384), 1);
		RandomManager.AddElement(GET_ITEM(13, 385), 1);
		RandomManager.AddElement(GET_ITEM(13, 386), 1);
		RandomManager.AddElement(GET_ITEM(13, 387), 1);
		RandomManager.AddElement(GET_ITEM(13, 388), 1);
		RandomManager.AddElement(GET_ITEM(13, 389), 1);
		RandomManager.AddElement(GET_ITEM(13, 390), 1);
		RandomManager.AddElement(GET_ITEM(13, 391), 1);
		RandomManager.AddElement(GET_ITEM(13, 392), 1);
		RandomManager.AddElement(GET_ITEM(13, 393), 1);
		RandomManager.AddElement(GET_ITEM(13, 394), 1);
		RandomManager.AddElement(GET_ITEM(13, 396), 1);
		RandomManager.AddElement(GET_ITEM(13, 397), 1);
		RandomManager.AddElement(GET_ITEM(13, 398), 1);

		RandomManager.GetRandomElement(&ItemIndex);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(970), lpObj->Name, gItemManager.GetItemName(ItemIndex));

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap10][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(971), lpObj->Name); // 751	"[%s] Chế tạo thất bại Pet cap Víp"

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap10][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}
//
#endif


#if(CUSTOM_MIX_PET_CAP11)
void CChaosBox::Muun11Mix(LPOBJ lpObj) // OK
{
	int ChaosPack30 = 0;
	int CreationPack30 = 0;
	int SoulPack30 = 0;
	int BlessPack30 = 0;
	int ItemMix = 0;
	int ItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 141) && lpObj->ChaosBox[n].m_Level == 2)
		{
			ChaosPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 137) && lpObj->ChaosBox[n].m_Level == 2)
		{
			CreationPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 31) && lpObj->ChaosBox[n].m_Level == 2)
		{
			SoulPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 30) && lpObj->ChaosBox[n].m_Level == 2)
		{
			BlessPack30++;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(13, 380) && lpObj->ChaosBox[n].m_Index <= GET_ITEM(13, 398))
		{
			ItemMix++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosPack30 != 1 || CreationPack30 != 1 || SoulPack30 != 1 || BlessPack30 != 1 || ItemMix != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_Muun11MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 3000000) + 1;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_Muun9MixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_Muun11MixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>40) ? 40 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = lpObj->ChaosSuccessRate * 200000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;

		CRandomManager RandomManager;

		RandomManager.AddElement(GET_ITEM(13, 401), 1);
		RandomManager.AddElement(GET_ITEM(13, 402), 1);
		RandomManager.AddElement(GET_ITEM(13, 403), 1);
		RandomManager.AddElement(GET_ITEM(13, 404), 1);
		RandomManager.AddElement(GET_ITEM(13, 405), 1);
		RandomManager.AddElement(GET_ITEM(13, 406), 1);
		RandomManager.AddElement(GET_ITEM(13, 407), 1);
		RandomManager.AddElement(GET_ITEM(13, 408), 1);
		RandomManager.AddElement(GET_ITEM(13, 409), 1);
		RandomManager.AddElement(GET_ITEM(13, 410), 1);
		RandomManager.AddElement(GET_ITEM(13, 411), 1);
		RandomManager.AddElement(GET_ITEM(13, 412), 1);
		RandomManager.AddElement(GET_ITEM(13, 413), 1);
		RandomManager.AddElement(GET_ITEM(13, 414), 1);
		RandomManager.AddElement(GET_ITEM(13, 415), 1);
		RandomManager.AddElement(GET_ITEM(13, 416), 1);
		RandomManager.AddElement(GET_ITEM(13, 417), 1);
		RandomManager.AddElement(GET_ITEM(13, 418), 1);
		RandomManager.AddElement(GET_ITEM(13, 419), 1);
		RandomManager.AddElement(GET_ITEM(13, 421), 1);
		RandomManager.AddElement(GET_ITEM(13, 422), 1);
		RandomManager.AddElement(GET_ITEM(13, 423), 1);
		RandomManager.AddElement(GET_ITEM(13, 424), 1);
		RandomManager.AddElement(GET_ITEM(13, 425), 1);
		RandomManager.AddElement(GET_ITEM(13, 426), 1);
		RandomManager.AddElement(GET_ITEM(13, 427), 1);
		RandomManager.AddElement(GET_ITEM(13, 428), 1);
		RandomManager.AddElement(GET_ITEM(13, 429), 1);
		RandomManager.AddElement(GET_ITEM(13, 430), 1);
		RandomManager.AddElement(GET_ITEM(13, 431), 1);
		RandomManager.AddElement(GET_ITEM(13, 432), 1);
		RandomManager.AddElement(GET_ITEM(13, 433), 1);
		RandomManager.AddElement(GET_ITEM(13, 434), 1);
		RandomManager.AddElement(GET_ITEM(13, 435), 1);
		RandomManager.AddElement(GET_ITEM(13, 436), 1);
		RandomManager.AddElement(GET_ITEM(13, 440), 1);
		RandomManager.AddElement(GET_ITEM(13, 441), 1);
		RandomManager.AddElement(GET_ITEM(13, 442), 1);
		RandomManager.AddElement(GET_ITEM(13, 443), 1);
		RandomManager.AddElement(GET_ITEM(13, 453), 1);
 		RandomManager.AddElement(GET_ITEM(13, 454), 1);


		RandomManager.GetRandomElement(&ItemIndex);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(972), lpObj->Name, gItemManager.GetItemName(ItemIndex));

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap11][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(973), lpObj->Name); // 751	"[%s] Chế tạo thất bại Pet cap Víp"

		gLog.Output(LOG_CHAOS_MIX, "[MuunPetCap11][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}
//
#endif

//CustomMix
void CChaosBox::CustomItemMix(LPOBJ lpObj, int HeadCode) // OK
{
	CUSTOM_MIX* CustomMix = gCustomMix.GetCustomMix(HeadCode);

	if (CustomMix != 0)
	{
		int OptionExcelente1[6] = { 1, 2, 4, 8, 16, 32 };

		int OptionExcelente2[15] = { 3, 5, 6, 9, 10, 12, 17, 18, 20, 24, 33, 34, 36, 40, 48 };

		int OptionExcelente3[20] = { 7, 11, 13, 14, 19, 21, 22, 25, 26, 28, 35, 37, 38, 41, 42, 44, 49, 50, 52, 56 };

		int OptionExcelente4[15] = { 15, 23, 27, 29, 30, 39, 43, 45, 46, 51, 53, 54, 57, 58, 60 };

		int OptionExcelente5[6] = { 31, 47, 55, 59, 61, 62 };

		int itemMixCount = 0;

		int RenderGroup = -1;

		int ItemBagMixCount = 0;

		int ItemMixGroupCount = CustomMix->m_CountItem - gCustomMix.GetCountItemBagMix(HeadCode);

		//-- primera comprobación de item bag no cambiantes
		for (int slot = 0; slot < CHAOS_BOX_SIZE; slot++)
		{
			if (lpObj->ChaosBox[slot].IsItem() == 0)
			{
				continue;
			}

			if (gCustomMix.istItemBagMix(HeadCode, lpObj->ChaosBox[slot]))
			{
				ItemBagMixCount++;
			}
		}
		//validación de item por grupos existentes
		for (int Group = 0; Group < CustomMix->m_CountGroup; Group++)
		{
			itemMixCount = 0;

			for (int slot = 0; slot < CHAOS_BOX_SIZE; slot++)
			{
				if (lpObj->ChaosBox[slot].IsItem() == 0)
				{
					continue;
				}

				if (gCustomMix.istItemMix(CustomMix->m_Index, Group, lpObj->ChaosBox[slot]))	// validación si existe el item
				{
					itemMixCount++;
				}
			}

			if (itemMixCount == ItemMixGroupCount)
			{
				RenderGroup = Group;
				Group = CustomMix->m_CountGroup;
			}
		}

		if ((itemMixCount + ItemBagMixCount) != CustomMix->m_CountItem) // falló la combinación
		{
			this->GCChaosMixSend(lpObj->Index, 7, 0);
			return;
		}

		if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
		{
			this->GCChaosMixSend(lpObj->Index, 240, 0);
			return;
		}

		switch (lpObj->AccountLevel)
		{
		case 1:
			lpObj->ChaosSuccessRate = ((CustomMix->m_MixRate_AL1 < 0 || CustomMix->m_MixRate_AL1 > 100) ? 90 : CustomMix->m_MixRate_AL1);
			break;
		case 2:
			lpObj->ChaosSuccessRate = ((CustomMix->m_MixRate_AL2 < 0 || CustomMix->m_MixRate_AL2 > 100) ? 90 : CustomMix->m_MixRate_AL2);
			break;
		case 3:
			lpObj->ChaosSuccessRate = ((CustomMix->m_MixRate_AL3 < 0 || CustomMix->m_MixRate_AL3 > 100) ? 90 : CustomMix->m_MixRate_AL3);
			break;
		default:
			lpObj->ChaosSuccessRate = ((CustomMix->m_MixRate_AL0 < 0 || CustomMix->m_MixRate_AL0 > 100) ? 90 : CustomMix->m_MixRate_AL0);
			break;
		}

		lpObj->ChaosMoney = lpObj->ChaosSuccessRate * ((CustomMix->m_MixMoney < 0) ? 1000 : CustomMix->m_MixMoney);

		int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

		lpObj->ChaosMoney += TaxMoney;

		if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
		{
			this->GCChaosMixSend(lpObj->Index, 2, 0);
			return;
		}

		lpObj->Money -= lpObj->ChaosMoney;

		GCMoneySend(lpObj->Index, lpObj->Money);

		gCastleSiegeSync.AddTributeMoney(TaxMoney);

		if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
		{
			WORD ItemIndex = 0;
			BYTE ItemLevel = 0;
			BYTE ItemSkill = 0;
			BYTE ItemLuck = 0;
			BYTE ItemOption = 0;
			BYTE ItemExcellent = 0;
			BYTE ItemSetAncestral = 0;
			BYTE ItemSocketOption[MAX_SOCKET_OPTION] = { SOCKET_ITEM_OPTION_NONE, SOCKET_ITEM_OPTION_NONE, SOCKET_ITEM_OPTION_NONE, SOCKET_ITEM_OPTION_NONE, SOCKET_ITEM_OPTION_NONE };

			CRandomManager RandomManager = gCustomMix.RandomManager(HeadCode, RenderGroup);

			RandomManager.GetRandomElement(&ItemIndex);

			CUSTOM_ITEM_MIX_RESULT * ItemCreate = gCustomMix.GetItemResult(HeadCode, RenderGroup, ItemIndex);

			if (CustomMix->m_OpcionExeRand == 0)
			{
				ItemExcellent = (ItemCreate->m_Excelent < 0) ? 0 : ItemCreate->m_Excelent;
			}
			else
			{
				switch (ItemCreate->m_Excelent)
				{
				case 1:
					ItemExcellent = OptionExcelente1[rand() % 6];
					break;
				case 2:
					ItemExcellent = OptionExcelente2[rand() % 15];
					break;
				case 3:
					ItemExcellent = OptionExcelente3[rand() % 20];
					break;
				case 4:
					ItemExcellent = OptionExcelente4[rand() % 15];
					break;
				case 5:
					ItemExcellent = OptionExcelente5[rand() % 6];
					break;
				case 6:
					ItemExcellent = 63;
					break;
				default:
					ItemExcellent = 0;
					break;
				}
			}

			if (ItemCreate->m_Opcion > 7)
			{
				ItemOption = 7;
			}
			else if (ItemCreate->m_Opcion < 0)
			{
				ItemOption = 0;
			}
			else
			{
				ItemOption = ItemCreate->m_Opcion;
			}


			int qtd = gSocketItemType.GetSocketItemMaxSocket(ItemIndex);

			ItemSocketOption[0] = (BYTE)((qtd > 0) ? ((ItemCreate->Socket1 != 255) ? ItemCreate->Socket1 : 255) : SOCKET_ITEM_OPTION_NONE);
			ItemSocketOption[1] = (BYTE)((qtd > 1) ? ((ItemCreate->Socket2 != 255) ? ItemCreate->Socket2 : 255) : SOCKET_ITEM_OPTION_NONE);
			ItemSocketOption[2] = (BYTE)((qtd > 2) ? ((ItemCreate->Socket3 != 255) ? ItemCreate->Socket3 : 255) : SOCKET_ITEM_OPTION_NONE);
			ItemSocketOption[3] = (BYTE)((qtd > 3) ? ((ItemCreate->Socket4 != 255) ? ItemCreate->Socket4 : 255) : SOCKET_ITEM_OPTION_NONE);
			ItemSocketOption[4] = (BYTE)((qtd > 4) ? ((ItemCreate->Socket5 != 255) ? ItemCreate->Socket5 : 255) : SOCKET_ITEM_OPTION_NONE);

			GDCreateItemSend(lpObj->Index,
				0xFF, 0, 0, ItemIndex,
				(ItemCreate->m_ItemLevel != -1) ? ItemCreate->m_ItemLevel : rand() % 6, 0,
				((ItemCreate->m_Skill != 0) ? gItemManager.CheckItemSkill(ItemIndex) : 0),
				(ItemCreate->m_Luck != -1) ? 1 : rand() % 2,
				ItemOption,
				-1, ItemExcellent,
				(ItemCreate->m_SetACC != -1) ? ItemCreate->m_SetACC : rand() % 2,
				0, 0, ItemSocketOption, 0xFF, 0);


			//15-04-2022
			// Thông Báo Thành Công kèm tên Item
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, CustomMix->m_MixSuccess, lpObj->Name, gItemManager.GetItemName(ItemIndex));

			gLog.Output(LOG_CHAOS_MIX, "[CustomMix][Success][%s][%s] [%d] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, ItemIndex, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
		}
		else
		{
			this->ChaosBoxInit(lpObj);

			this->GCChaosBoxSend(lpObj, 0);

			this->GCChaosMixSend(lpObj->Index, 0, 0);

			//15-04-2022
			// Thông Báo Thất Bại
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, CustomMix->m_MixFailure, lpObj->Name);


			gLog.Output(LOG_CHAOS_MIX, "[CustomMix][Failure][%s][%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
		}
	}
	else
	{
		gLog.Output(LOG_CHAOS_MIX, "[CustomMix][Failure][%s][%s] - CustomMix No Existente", lpObj->Account, lpObj->Account, lpObj->Name);
	}
}
//=================================================================================================

void CChaosBox::ChaosCardMix(LPOBJ lpObj, int type) // OK
{
	int ChaosCardCount = 0;
	int ChaosCardGoldCount = 0;
	int ChaosCardRareCount = 0;
	int ChaosCardMiniCount = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 54))
		{
			type = 1;
			ChaosCardCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 92))
		{
			type = 2;
			ChaosCardGoldCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 93))
		{
			type = 3;
			ChaosCardRareCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 95))
		{
			type = 4;
			ChaosCardMiniCount++;
		}
	}

	if (type == 0 || (type == 1 && ChaosCardCount != 1) || (type == 2 && ChaosCardGoldCount != 1) || (type == 3 && ChaosCardRareCount != 1) || (type == 4 && ChaosCardMiniCount != 1))
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	CItem item;

	if (gItemBagManager.GetItemBySpecialValue((ITEM_BAG_CHAOS_CARD_MIX1 + (type - 1)), lpObj, &item) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 0, 0);
		return;
	}

	GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, item.m_Index, (BYTE)item.m_Level, 0, (BYTE)item.m_Option1, (BYTE)item.m_Option2, (BYTE)item.m_Option3, -1, item.m_NewOption, item.m_SetOption, item.m_JewelOfHarmonyOption, item.m_ItemOptionEx, item.m_SocketOption, item.m_SocketOptionBonus, 0);

	gLog.Output(LOG_CHAOS_MIX, "[ChaosCardMix][Thành Công] Account:[%s] Name:[%s] - (Type: %d, ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, type, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
}

void CChaosBox::CherryBlossomMix(LPOBJ lpObj, int type) // OK
{
	int WhiteCherryBlossomCount = 0;
	int RedCherryBlossomCount = 0;
	int GoldenCherryBlossomCount = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 88))
		{
			type = 1;
			WhiteCherryBlossomCount += (int)lpObj->ChaosBox[n].m_Durability;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 89))
		{
			type = 2;
			RedCherryBlossomCount += (int)lpObj->ChaosBox[n].m_Durability;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 90))
		{
			type = 3;
			GoldenCherryBlossomCount += (int)lpObj->ChaosBox[n].m_Durability;
		}
	}

	if (type == 0 || (type == 1 && WhiteCherryBlossomCount != 10) || (type == 2 && RedCherryBlossomCount != 30) || (type == 3 && GoldenCherryBlossomCount != 255))
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	CItem item;

	if (gItemBagManager.GetItemBySpecialValue((ITEM_BAG_CHERRY_BLOSSOM_MIX1 + (type - 1)), lpObj, &item) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 0, 0);
		return;
	}

	GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, item.m_Index, (BYTE)item.m_Level, 0, (BYTE)item.m_Option1, (BYTE)item.m_Option2, (BYTE)item.m_Option3, -1, item.m_NewOption, item.m_SetOption, item.m_JewelOfHarmonyOption, item.m_ItemOptionEx, item.m_SocketOption, item.m_SocketOptionBonus, 0);

	gLog.Output(LOG_CHAOS_MIX, "[CherryBlossomMix][Thành Công] Account:[%s] Name:[%s] - (Type: %d, ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, type, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
}

void CChaosBox::SocketItemCreateSeedMix(LPOBJ lpObj) // OK
{
	int ChaosCount = 0;
	int CreationCount = 0;
	int HarmonyCount = 0;
	int ExcItemCount = 0;
	int SetItemCount = 0;
	int ItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 22))
		{
			CreationCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 42))
		{
			HarmonyCount++;
		}
		else if (lpObj->ChaosBox[n].IsExcItem() != 0 && lpObj->ChaosBox[n].m_Level >= 4 && ExcItemCount == 0)
		{
			ExcItemCount++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
		else if (lpObj->ChaosBox[n].IsSetItem() != 0 && lpObj->ChaosBox[n].m_Level >= 4 && SetItemCount == 0)
		{
			SetItemCount++;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosCount != 1 || CreationCount != 1 || HarmonyCount != 1 || ExcItemCount != 1 || SetItemCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_SocketItemCreateSeedMixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 2000000) + 80;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_SocketItemCreateSeedMixRate[lpObj->AccountLevel];
	}

	if (gServerInfo.m_SocketItemCreateSeedMixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>90) ? 90 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = 1000000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		int SocketOptionType = 1 + (GetLargeRand() % MAX_SOCKET_ITEM_OPTION_TYPE);

		int SocketOptionIndex = gSocketItemOption.GetSocketItemRandomOption(SocketOptionType);

		int SocketOptionValue = gSocketItemOption.GetSocketItemSeedOption(SocketOptionIndex, SocketOptionType);

		if (SocketOptionIndex == -1 || SocketOptionValue == -1)
		{
			this->GCChaosMixSend(lpObj->Index, 0, 0);
			return;
		}

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, (GET_ITEM(12, 60) + (SocketOptionType - 1)), SocketOptionValue, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gLog.Output(LOG_CHAOS_MIX, "[SocketItemCreateSeedMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gLog.Output(LOG_CHAOS_MIX, "[SocketItemCreateSeedMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

void CChaosBox::SocketItemCreateSeedSphereMix(LPOBJ lpObj) // OK
{
	int ChaosCount = 0;
	int CreationCount = 0;
	int SeedCount = 0;
	int SeedType = 0;
	int SeedLevel = 0;
	int SphereCount = 0;
	int SphereType = 0;
	int ItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 22))
		{
			CreationCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(12, 60) && lpObj->ChaosBox[n].m_Index <= GET_ITEM(12, 66))
		{
			SeedCount++;
			SeedType = lpObj->ChaosBox[n].m_Index - GET_ITEM(12, 60);
			SeedLevel = lpObj->ChaosBox[n].m_Level;
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(12, 70) && lpObj->ChaosBox[n].m_Index <= GET_ITEM(12, 74))
		{
			SphereCount++;
			SphereType = lpObj->ChaosBox[n].m_Index - GET_ITEM(12, 70);
			ItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
		}
	}

	if (ChaosCount != 1 || CreationCount != 1 || SeedCount != 1 || SphereCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_SocketItemCreateSeedSphereMixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = (ItemMoney / 200000) + 80;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_SocketItemCreateSeedSphereMixRate[lpObj->AccountLevel];
	}

	if (gServerInfo.m_SocketItemCreateSeedSphereMixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>90) ? 90 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = 1000000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, (GET_ITEM(12, 100) + (SphereType * 6) + SeedType), SeedLevel, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gLog.Output(LOG_CHAOS_MIX, "[SocketItemCreateSeedSphereMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gLog.Output(LOG_CHAOS_MIX, "[SocketItemCreateSeedSphereMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
}

void CChaosBox::SocketItemMountSeedSphereMix(LPOBJ lpObj, BYTE info) // OK
{
	if (info >= MAX_SOCKET_ITEM_OPTION_TABLE)
	{
		this->GCChaosMixSend(lpObj->Index, 0, 0);
		return;
	}

	int ChaosCount = 0;
	int CreationCount = 0;
	int SeedSphereCount = 0;
	int SeedSphereType = 0;
	int SeedSphereLevel = 0;
	int SeedSphereOption = 0;
	int ItemCount = 0;
	int ItemSlot = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 22))
		{
			CreationCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(12, 100) && lpObj->ChaosBox[n].m_Index <= GET_ITEM(12, 129))
		{
			SeedSphereCount++;
			SeedSphereType = (lpObj->ChaosBox[n].m_Index - GET_ITEM(12, 100)) % MAX_SOCKET_ITEM_OPTION_TYPE;
			SeedSphereLevel = (lpObj->ChaosBox[n].m_Index - GET_ITEM(12, 100)) / MAX_SOCKET_ITEM_OPTION_TYPE;
			SeedSphereOption = lpObj->ChaosBox[n].m_Level;
		}
		else if (gSocketItemType.CheckSocketItemType(lpObj->ChaosBox[n].m_Index) != 0 && lpObj->ChaosBox[n].m_SocketOption[info] == SOCKET_ITEM_OPTION_EMPTY)
		{
			ItemCount++;
			ItemSlot = n;
		}
	}

	if (ChaosCount != 1 || CreationCount != 1 || SeedSphereCount != 1 || ItemCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	//limite socket
	if (info >= gSocketItemType.GetSocketItemMaxSocket(lpObj->ChaosBox[ItemSlot].m_Index))
	{
		this->GCChaosMixSend(lpObj->Index, 0, 0);
		return;
	}

	lpObj->ChaosMoney = 1000000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	BYTE SocketOption = gSocketItemOption.GetSocketItemOption(&lpObj->ChaosBox[ItemSlot], (SeedSphereType + 1), SeedSphereOption, SeedSphereLevel);

	if (SocketOption == SOCKET_ITEM_OPTION_NONE)
	{
		this->GCChaosMixSend(lpObj->Index, 0, 0);
		return;
	}

	CItem item = lpObj->ChaosBox[ItemSlot];

	item.m_SocketOption[info] = SocketOption;

	item.m_SocketOptionBonus = gSocketItemOption.GetSocketItemBonusOption(&item);

	this->ChaosBoxInit(lpObj);

	gItemManager.ChaosBoxAddItem(lpObj->Index, item, 0);

	this->GCChaosMixSend(lpObj->Index, 1, &item);

	gLog.Output(LOG_CHAOS_MIX, "[SocketItemMountSeedSphereMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
}

void CChaosBox::SocketItemUnMountSeedSphereMix(LPOBJ lpObj, BYTE info) // OK
{
	if (info >= MAX_SOCKET_ITEM_OPTION_TABLE)
	{
		this->GCChaosMixSend(lpObj->Index, 0, 0);
		return;
	}

	int ItemCount = 0;
	int ItemSlot = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_SocketOption[info] != SOCKET_ITEM_OPTION_NONE && lpObj->ChaosBox[n].m_SocketOption[info] != SOCKET_ITEM_OPTION_EMPTY)
		{
			ItemCount++;
			ItemSlot = n;
		}
	}

	if (ItemCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	lpObj->ChaosMoney = 1000000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	CItem item = lpObj->ChaosBox[ItemSlot];

	item.m_SocketOption[info] = SOCKET_ITEM_OPTION_EMPTY;

	item.m_SocketOptionBonus = gSocketItemOption.GetSocketItemBonusOption(&item);

	this->ChaosBoxInit(lpObj);

	gItemManager.ChaosBoxAddItem(lpObj->Index, item, 0);

	this->GCChaosMixSend(lpObj->Index, 1, &item);
}

void CChaosBox::ImperialGuardianMix(LPOBJ lpObj) // OK
{
#if(GAMESERVER_UPDATE>=501)

	int DimensionalPart1Count = 0;
	int DimensionalPart2Count = 0;
	int DimensionalPart3Count = 0;
	int DimensionalPart4Count = 0;
	int DimensionalPart5Count = 0;
	int DimensionalPart6Count = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 103))
		{
			DimensionalPart1Count++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 104))
		{
			DimensionalPart2Count++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 105))
		{
			DimensionalPart3Count++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 106))
		{
			DimensionalPart4Count++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 107))
		{
			DimensionalPart5Count++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 108))
		{
			DimensionalPart6Count++;
		}
	}

	if (DimensionalPart1Count != 1 && DimensionalPart2Count != 1 && DimensionalPart3Count != 1 && DimensionalPart4Count != 1 && DimensionalPart5Count != 1 && DimensionalPart6Count != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	lpObj->ChaosMoney = 1000000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, GET_ITEM(14, 109), 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

	gLog.Output(LOG_CHAOS_MIX, "[ImperialGuardianMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);

#endif
}

void CChaosBox::ChestMix(LPOBJ lpObj) // OK
{
#if(GAMESERVER_UPDATE>=501)

	int GoldKeyCount = 0;
	int GoldChestCount = 0;
	int SilverKeyCount = 0;
	int SilverChestCount = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 112))
		{
			SilverKeyCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 113))
		{
			GoldKeyCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 121))
		{
			GoldChestCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 122))
		{
			SilverChestCount++;
		}
	}

	if ((GoldKeyCount != 1 && SilverKeyCount != 1) || (GoldKeyCount == 1 && GoldChestCount != 1) || (SilverKeyCount == 1 && SilverChestCount != 1))
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, (GET_ITEM(14, 123) + SilverKeyCount), 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

	gLog.Output(LOG_CHAOS_MIX, "[ChestMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);

#endif
}

void CChaosBox::SummonScrollMix(LPOBJ lpObj, int type) // OK
{
#if(GAMESERVER_UPDATE>=801)

	int SummonScroll1Count = 0;
	int SummonScroll2Count = 0;
	int SummonScroll3Count = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 210))
		{
			type = 1;
			SummonScroll1Count++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 211))
		{
			type = 2;
			SummonScroll2Count++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 212))
		{
			type = 3;
			SummonScroll3Count++;
		}
	}

	if (type == 0 || (type == 1 && SummonScroll1Count != 2) || (type == 2 && (SummonScroll1Count != 1 || SummonScroll2Count != 1)) || (type == 3 && (SummonScroll1Count != 1 || SummonScroll3Count != 1)))
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	switch (type)
	{
	case 1:
		lpObj->ChaosSuccessRate = gServerInfo.m_SummonScrollMixRate1[lpObj->AccountLevel];
		lpObj->ChaosMoney = 100000;
		break;
	case 2:
		lpObj->ChaosSuccessRate = gServerInfo.m_SummonScrollMixRate2[lpObj->AccountLevel];
		lpObj->ChaosMoney = 200000;
		break;
	case 3:
		lpObj->ChaosSuccessRate = gServerInfo.m_SummonScrollMixRate3[lpObj->AccountLevel];
		lpObj->ChaosMoney = 300000;
		break;
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, (GET_ITEM(14, 210) + type), 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gLog.Output(LOG_CHAOS_MIX, "[SummonScrollMix][Thành Công] Account:[%s] Name:[%s] - (Type: %d, ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, type, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gLog.Output(LOG_CHAOS_MIX, "[SummonScrollMix][Thất Bại] Account:[%s] Name:[%s] - (Type: %d, ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, type, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}

#endif
}

void CChaosBox::LuckyItemCreateMix(LPOBJ lpObj) // OK
{
#if(GAMESERVER_UPDATE>=602)

	int LuckyTicketCount = 0;
	int LuckyTicketGroup = 0;
	int LuckyTicketSection = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 135))
		{
			LuckyTicketCount++;
			LuckyTicketGroup = 0;
			LuckyTicketSection = 8;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 136))
		{
			LuckyTicketCount++;
			LuckyTicketGroup = 0;
			LuckyTicketSection = 9;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 137))
		{
			LuckyTicketCount++;
			LuckyTicketGroup = 0;
			LuckyTicketSection = 7;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 138))
		{
			LuckyTicketCount++;
			LuckyTicketGroup = 0;
			LuckyTicketSection = 10;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 139))
		{
			LuckyTicketCount++;
			LuckyTicketGroup = 0;
			LuckyTicketSection = 11;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 140))
		{
			LuckyTicketCount++;
			LuckyTicketGroup = 1;
			LuckyTicketSection = 8;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 141))
		{
			LuckyTicketCount++;
			LuckyTicketGroup = 1;
			LuckyTicketSection = 9;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 142))
		{
			LuckyTicketCount++;
			LuckyTicketGroup = 1;
			LuckyTicketSection = 7;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 143))
		{
			LuckyTicketCount++;
			LuckyTicketGroup = 1;
			LuckyTicketSection = 10;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 144))
		{
			LuckyTicketCount++;
			LuckyTicketGroup = 1;
			LuckyTicketSection = 11;
		}
	}

	if (LuckyTicketCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	WORD ItemIndex = 0;
	BYTE ItemLevel = 0;
	BYTE ItemOption1 = 0;
	BYTE ItemOption2 = 0;
	BYTE ItemOption3 = 0;
	BYTE ItemNewOption = 0;
	BYTE ItemSetOption = 0;
	BYTE ItemSocketOption[MAX_SOCKET_OPTION] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

	if (gLuckyItem.GetLuckyItemIndex(lpObj, LuckyTicketSection, LuckyTicketGroup, &ItemIndex) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 0, 0);
		return;
	}

	gLuckyItem.GetLuckyItemOption0(ItemIndex, &ItemLevel);

	gLuckyItem.GetLuckyItemOption1(ItemIndex, &ItemOption1);

	gLuckyItem.GetLuckyItemOption2(ItemIndex, &ItemOption2);

	gLuckyItem.GetLuckyItemOption3(ItemIndex, &ItemOption3);

	gLuckyItem.GetLuckyItemOption4(ItemIndex, &ItemNewOption);

	gLuckyItem.GetLuckyItemOption5(ItemIndex, &ItemSetOption);

	gLuckyItem.GetLuckyItemOption6(ItemIndex, &ItemSocketOption[0]);

	gItemOptionRate.MakeNewOption(ItemIndex, ItemNewOption, &ItemNewOption);

	gItemOptionRate.MakeSetOption(ItemIndex, ItemSetOption, &ItemSetOption);

	gItemOptionRate.MakeSocketOption(ItemIndex, ItemSocketOption[0], &ItemSocketOption[0]);

	GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, ItemLevel, 255, ItemOption1, ItemOption2, ItemOption3, -1, ItemNewOption, ItemSetOption, 0, 0, ItemSocketOption, 0xFF, 0);

	gLog.Output(LOG_CHAOS_MIX, "[LuckyItemCreateMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);

#endif
}

void CChaosBox::LuckyItemRefineMix(LPOBJ lpObj) // OK
{
#if(GAMESERVER_UPDATE>=602)

	int LuckyItemCount = 0;
	int LuckyItemSlot = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].IsLuckyItem() != 0)
		{
			LuckyItemCount++;
			LuckyItemSlot = n;
		}
	}

	if (LuckyItemCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (lpObj->ChaosBox[LuckyItemSlot].m_Durability == 255)
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_LuckyItemRefineMixRate1[lpObj->AccountLevel];
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_LuckyItemRefineMixRate2[lpObj->AccountLevel];
	}

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, GET_ITEM(14, 160), 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

		gLog.Output(LOG_CHAOS_MIX, "[LuckyItemRefineMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gLog.Output(LOG_CHAOS_MIX, "[LuckyItemRefineMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}

#endif
}

void CChaosBox::MonsterWingMix(LPOBJ lpObj) // OK
{
#if(GAMESERVER_UPDATE>=701)

	int ChaosCount = 0;
	int CreationCount = 0;
	int MaterialType = 0;
	int WingItemCount = 0;
	int WingItemMoney = 0;
	int WingItemType = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 22))
		{
			CreationCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 176))
		{
			MaterialType = 1;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 177))
		{
			MaterialType = 2;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 178))
		{
			MaterialType = 3;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 179))
		{
			MaterialType = 4;
		}
		else if ((lpObj->ChaosBox[n].m_Index >= GET_ITEM(12, 3) && lpObj->ChaosBox[n].m_Index <= GET_ITEM(12, 6)) || lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 42))
		{
			WingItemCount++;
			WingItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
			WingItemType = 0;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 49) || lpObj->ChaosBox[n].m_Index == GET_ITEM(13, 30))
		{
			WingItemCount++;
			WingItemMoney += lpObj->ChaosBox[n].m_BuyMoney;
			WingItemType = 1;
		}
	}

	if (ChaosCount != 1 || CreationCount != 1 || MaterialType == 0 || WingItemCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_MonsterWingMixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = WingItemMoney / ((WingItemType == 0) ? 9000000 : 500000);
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_MonsterWingMixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_MonsterWingMixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>60) ? 60 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = lpObj->ChaosSuccessRate * 100000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;
		BYTE ItemOption2 = 0;
		BYTE ItemOption3 = 0;
		BYTE ItemNewOption = 0;

		switch (MaterialType)
		{
		case 1:
			ItemIndex = GET_ITEM(12, 262);
			break;
		case 2:
			ItemIndex = GET_ITEM(12, 263);
			break;
		case 3:
			ItemIndex = GET_ITEM(12, 264);
			break;
		case 4:
			ItemIndex = GET_ITEM(12, 265);
			break;
		}

		gItemOptionRate.GetItemOption2(7, &ItemOption2);

		gItemOptionRate.GetItemOption3(7, &ItemOption3);

		gItemOptionRate.GetItemOption4(7, &ItemNewOption);

		gItemOptionRate.MakeNewOption(ItemIndex, ItemNewOption, &ItemNewOption);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, ItemOption2, ItemOption3, -1, (ItemNewOption + (16 * (GetLargeRand() % 2))), 0, 0, 0, 0, 0xFF, 0);

		gLog.Output(LOG_CHAOS_MIX, "[MonsterWingMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gLog.Output(LOG_CHAOS_MIX, "[MonsterWingMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}

#endif
}

void CChaosBox::SocketWeaponMix(LPOBJ lpObj) // OK
{
#if(GAMESERVER_UPDATE>=701)

	int IceWalkerManeCount = 0;
	int MammothBundleOfFurCount = 0;
	int GiantIcicleCount = 0;
	int CoolutinPoisonCount = 0;
	int IronKnightHeartCount = 0;
	int DarkMammothHornCount = 0;
	int DarkGiantAxeCount = 0;
	int DarkCoolutinBloodCount = 0;
	int DarkIronKnightSwordCount = 0;
	int CombinationNoteType = 0;
	int SocketItemCount = 0;
	int SocketItemMoney = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 180))
		{
			IceWalkerManeCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 181))
		{
			MammothBundleOfFurCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 182))
		{
			GiantIcicleCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 183))
		{
			CoolutinPoisonCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 184))
		{
			IronKnightHeartCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 185))
		{
			DarkMammothHornCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 186))
		{
			DarkGiantAxeCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 187))
		{
			DarkCoolutinBloodCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 188))
		{
			DarkIronKnightSwordCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index >= GET_ITEM(14, 191) && lpObj->ChaosBox[n].m_Index <= GET_ITEM(14, 202))
		{
			CombinationNoteType = lpObj->ChaosBox[n].m_Index - GET_ITEM(14, 190);
		}
		else if (gSocketItemType.CheckSocketItemType(lpObj->ChaosBox[n].m_Index) != 0 && lpObj->ChaosBox[n].m_Level >= 7 && lpObj->ChaosBox[n].m_Option3 >= 1)
		{
			SocketItemCount++;
			SocketItemMoney += lpObj->ChaosBox[n].m_Value;
		}
	}

	if (CombinationNoteType == 0 || SocketItemCount == 0 || (CombinationNoteType == 1 && (IceWalkerManeCount != 2 || DarkIronKnightSwordCount != 1)) || (CombinationNoteType == 2 && (MammothBundleOfFurCount != 2 || DarkMammothHornCount != 1)) || (CombinationNoteType == 3 && (GiantIcicleCount != 2 || DarkIronKnightSwordCount != 1)) || (CombinationNoteType == 4 && (CoolutinPoisonCount != 2 || DarkMammothHornCount != 1)) || (CombinationNoteType == 5 && (GiantIcicleCount != 2 || DarkGiantAxeCount != 1)) || (CombinationNoteType == 6 && (IceWalkerManeCount != 2 || DarkMammothHornCount != 1)) || (CombinationNoteType == 7 && (IronKnightHeartCount != 2 || DarkCoolutinBloodCount != 1)) || (CombinationNoteType == 8 && (GiantIcicleCount != 2 || DarkMammothHornCount != 1)) || (CombinationNoteType == 9 && (IronKnightHeartCount != 2 || DarkGiantAxeCount != 1)) || (CombinationNoteType == 10 && (IronKnightHeartCount != 2 || DarkIronKnightSwordCount != 1)) || (CombinationNoteType == 11 && (MammothBundleOfFurCount != 2 || DarkCoolutinBloodCount != 1)) || (CombinationNoteType == 12 && (IronKnightHeartCount != 2 || DarkMammothHornCount != 1)))
	{
		this->GCChaosMixSend(lpObj->Index, 7, 0);
		return;
	}

	if (gServerInfo.m_SocketWeaponMixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = SocketItemMoney / 360000;
	}
	else
	{
		lpObj->ChaosSuccessRate = gServerInfo.m_SocketWeaponMixRate[lpObj->AccountLevel];
	}

	if (this->GetTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	if (gServerInfo.m_SocketWeaponMixRate[lpObj->AccountLevel] == -1)
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>40) ? 40 : lpObj->ChaosSuccessRate);
	}
	else
	{
		lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);
	}

	lpObj->ChaosMoney = 1000000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 2, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;
		BYTE ItemOption2 = 0;
		BYTE ItemSocketOption[MAX_SOCKET_OPTION] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

		switch (CombinationNoteType)
		{
		case 1:
			ItemIndex = GET_ITEM(0, 29);
			break;
		case 2:
			ItemIndex = GET_ITEM(0, 36);
			break;
		case 3:
			ItemIndex = GET_ITEM(0, 37);
			break;
		case 4:
			ItemIndex = GET_ITEM(3, 12);
			break;
		case 5:
			ItemIndex = GET_ITEM(2, 20);
			break;
		case 6:
			ItemIndex = GET_ITEM(4, 25);
			break;
		case 7:
			ItemIndex = GET_ITEM(4, 26);
			break;
		case 8:
			ItemIndex = GET_ITEM(5, 35);
			break;
		case 9:
			ItemIndex = GET_ITEM(5, 37);
			break;
		case 10:
			ItemIndex = GET_ITEM(0, 30);
			break;
		case 11:
			ItemIndex = GET_ITEM(2, 19);
			break;
		case 12:
			ItemIndex = GET_ITEM(5, 32);
			break;
		}

		gItemOptionRate.GetItemOption2(8, &ItemOption2);

		gItemOptionRate.GetItemOption6(((gItemManager.GetItemTwoHand(ItemIndex) == 0) ? 6 : 7), &ItemSocketOption[0]);

		gItemOptionRate.MakeSocketOption(ItemIndex, ItemSocketOption[0], &ItemSocketOption[0]);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 1, ItemOption2, 0, -1, 0, 0, 0, 0, ItemSocketOption, 0xFF, 0);

		gLog.Output(LOG_CHAOS_MIX, "[SocketWeaponMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 0, 0);

		gLog.Output(LOG_CHAOS_MIX, "[SocketWeaponMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}

#endif
}

void CChaosBox::PentagramMithrilMix(LPOBJ lpObj) // OK
{
#if(GAMESERVER_UPDATE>=701)

	int ChaosCount = 0;
	int MithrilFragmentBunchCount = 0;
	int MithrilFragmentBunchType = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 148))
		{
			MithrilFragmentBunchCount++;
			MithrilFragmentBunchType = lpObj->ChaosBox[n].m_SocketOptionBonus;
		}
	}

	if (ChaosCount != 1 || MithrilFragmentBunchCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 250, 0);
		return;
	}

	if (CHECK_RANGE((MithrilFragmentBunchType - 1), MAX_PENTAGRAM_ELEMENTAL_ATTRIBUTE) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 248, 0);
		return;
	}

	lpObj->ChaosSuccessRate = gServerInfo.m_PentagramMithrilMixRate[lpObj->AccountLevel];

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	lpObj->ChaosMoney = 100000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 249, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = GET_ITEM(12, 145);
		BYTE SocketOption[MAX_SOCKET_OPTION] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
		BYTE SocketOptionBonus = MithrilFragmentBunchType;

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, SocketOption, SocketOptionBonus, 0);

		gLog.Output(LOG_CHAOS_MIX, "[PentagramMithrilMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 226, 0);

		gLog.Output(LOG_CHAOS_MIX, "[PentagramMithrilMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}

#endif
}

void CChaosBox::PentagramElixirMix(LPOBJ lpObj) // OK
{
#if(GAMESERVER_UPDATE>=701)

	int ChaosCount = 0;
	int ElixirFragmentBunchCount = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 15))
		{
			ChaosCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 149))
		{
			ElixirFragmentBunchCount++;
		}
	}

	if (ChaosCount != 1 || ElixirFragmentBunchCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 250, 0);
		return;
	}

	lpObj->ChaosSuccessRate = gServerInfo.m_PentagramElixirMixRate[lpObj->AccountLevel];

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	lpObj->ChaosMoney = 100000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 249, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = GET_ITEM(12, 147);
		BYTE SocketOption[MAX_SOCKET_OPTION] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
		BYTE SocketOptionBonus = 0xFF;

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, SocketOption, SocketOptionBonus, 0);

		gLog.Output(LOG_CHAOS_MIX, "[PentagramElixirMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 226, 0);

		gLog.Output(LOG_CHAOS_MIX, "[PentagramElixirMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}

#endif
}

void CChaosBox::PentagramJewelMix(LPOBJ lpObj) // OK
{
#if(GAMESERVER_UPDATE>=701)

	int BlessCount = 0;
	int MithrilCount = 0;
	int MithrilType = 0;
	int ElixirCount = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 13))
		{
			BlessCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 145))
		{
			MithrilCount++;
			MithrilType = lpObj->ChaosBox[n].m_SocketOptionBonus;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 147))
		{
			ElixirCount++;
		}
	}

	if (BlessCount != 1 || MithrilCount != 1 || ElixirCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 250, 0);
		return;
	}

	if (CHECK_RANGE((MithrilType - 1), MAX_PENTAGRAM_ELEMENTAL_ATTRIBUTE) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 251, 0);
		return;
	}

	lpObj->ChaosSuccessRate = gServerInfo.m_PentagramJewelMixRate[lpObj->AccountLevel];

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	lpObj->ChaosMoney = 100000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 249, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;
		BYTE SocketOption[MAX_SOCKET_OPTION] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
		BYTE SocketOptionBonus = MithrilType | 16;

		CRandomManager RandomManager;

		RandomManager.AddElement(GET_ITEM(12, 221), 4000);

		RandomManager.AddElement(GET_ITEM(12, 231), 3000);

		RandomManager.AddElement(GET_ITEM(12, 241), 1500);

		RandomManager.AddElement(GET_ITEM(12, 251), 1000);

		RandomManager.AddElement(GET_ITEM(12, 261), 500);

		RandomManager.GetRandomElement(&ItemIndex);

		if (gPentagramSystem.GetPentagramRandomJewelOption(ItemIndex, 1, &SocketOption[0]) == 0)
		{
			this->GCChaosMixSend(lpObj->Index, 248, 0);
			return;
		}

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, SocketOption, SocketOptionBonus, 0);

		gLog.Output(LOG_CHAOS_MIX, "[PentagramJewelMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 226, 0);

		gLog.Output(LOG_CHAOS_MIX, "[PentagramJewelMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}

#endif
}

void CChaosBox::PentagramDecompositeMix(LPOBJ lpObj, int type) // OK
{
#if(GAMESERVER_UPDATE>=701)

	int HarmonyCount = 0;
	int PentagramItemType = 0;
	int PentagramItemSlot = 0;
	int PentagramDecompositeType = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 42))
		{
			HarmonyCount++;
		}
		if (lpObj->ChaosBox[n].IsPentagramItem() != 0)
		{
			PentagramItemType = lpObj->ChaosBox[n].m_SocketOptionBonus % 16;
			PentagramItemSlot = n;
			PentagramDecompositeType = lpObj->ChaosBox[n].m_Index - GET_ITEM(12, 199);
		}
	}

	if (HarmonyCount != 1 || PentagramDecompositeType == 0 || (PentagramDecompositeType != (type + 1)))
	{
		this->GCChaosMixSend(lpObj->Index, 250, 0);
		return;
	}

	if (CHECK_RANGE((PentagramItemType - 1), MAX_PENTAGRAM_ELEMENTAL_ATTRIBUTE) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 251, 0);
		return;
	}

	lpObj->ChaosSuccessRate = gServerInfo.m_PentagramDecompositeMixRate[lpObj->AccountLevel];

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	lpObj->ChaosMoney = 100000;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 249, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	gPentagramSystem.DelAllPentagramJewelInfo(lpObj, &lpObj->ChaosBox[PentagramItemSlot], 0);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		WORD ItemIndex = 0;
		BYTE SocketOption[MAX_SOCKET_OPTION] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
		BYTE SocketOptionBonus = 0xFF;

		CRandomManager RandomManager;

		RandomManager.AddElement(GET_ITEM(12, 144), 5000);

		RandomManager.AddElement(GET_ITEM(12, 145), 1500);

		RandomManager.AddElement(GET_ITEM(12, 146), 2500);

		RandomManager.AddElement(GET_ITEM(12, 147), 500);

		RandomManager.AddElement(GET_ITEM(12, 150), 500);

		RandomManager.GetRandomElement(&ItemIndex);

		SocketOptionBonus = ((ItemIndex == GET_ITEM(12, 144)) ? PentagramItemType : SocketOptionBonus);

		SocketOptionBonus = ((ItemIndex == GET_ITEM(12, 145)) ? PentagramItemType : SocketOptionBonus);

		GDCreateItemSend(lpObj->Index, 0xFF, 0, 0, ItemIndex, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, SocketOption, SocketOptionBonus, 0);

		gLog.Output(LOG_CHAOS_MIX, "[PentagramDecompositeMix][Thành Công] Account:[%s] Name:[%s] - (Type: %d, ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, type, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 226, 0);

		gLog.Output(LOG_CHAOS_MIX, "[PentagramDecompositeMix][Thất Bại] Account:[%s] Name:[%s] - (Type: %d, ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, type, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}

#endif
}

void CChaosBox::PentagramJewelUpgradeLevelMix(LPOBJ lpObj, BYTE info) // OK
{
#if(GAMESERVER_UPDATE>=701)

	int BlessCount = 0;
	int JewelCombinationFrameCount = 0;
	int PentagramJewelCount = 0;
	int PentagramJewelSlot = 0;
	int ElementalChaosAmulet = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 13))
		{
			BlessCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 150))
		{
			JewelCombinationFrameCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 190))
		{
			ElementalChaosAmulet++;
		}
		else if (lpObj->ChaosBox[n].IsPentagramJewel() != 0)
		{
			PentagramJewelCount++;
			PentagramJewelSlot = n;
		}
	}

	if (BlessCount != 1 || JewelCombinationFrameCount != 1 || PentagramJewelCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 250, 0);
		return;
	}

	if (CHECK_RANGE(((lpObj->ChaosBox[PentagramJewelSlot].m_SocketOptionBonus / 16) - 1), MAX_PENTAGRAM_JEWEL_RANK) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 252, 0);
		return;
	}

	if (CHECK_RANGE(lpObj->ChaosBox[PentagramJewelSlot].m_Level, (MAX_PENTAGRAM_JEWEL_LEVEL - 1)) == 0 || lpObj->ChaosBox[PentagramJewelSlot].m_Level != (info - 1))
	{
		this->GCChaosMixSend(lpObj->Index, 252, 0);
		return;
	}

	PENTAGRAM_JEWEL_UPGRADE_LEVEL_INFO PentagramJewelUpgradeLevelInfo;

	if (gPentagramSystem.GetPentagramJewelUpgradeLevelInfo((info - 1), &PentagramJewelUpgradeLevelInfo) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 248, 0);
		return;
	}

	lpObj->ChaosSuccessRate = PentagramJewelUpgradeLevelInfo.MixRate[((lpObj->ChaosBox[PentagramJewelSlot].m_SocketOptionBonus / 16) - 1)] / 100;

	if (this->GetElementalTalismanOfLuckRate(lpObj, &lpObj->ChaosSuccessRate) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 240, 0);
		return;
	}

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	lpObj->ChaosMoney = PentagramJewelUpgradeLevelInfo.MixMoney;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 249, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		CItem item = lpObj->ChaosBox[PentagramJewelSlot];

		item.m_Level++;

		item.m_SocketOption[((item.m_SocketOptionBonus / 16) - 1)] += 16;

		this->ChaosBoxInit(lpObj);

		gItemManager.ChaosBoxAddItem(lpObj->Index, item, 0);

		this->GCChaosMixSend(lpObj->Index, 1, &item);

		gLog.Output(LOG_CHAOS_MIX, "[PentagramJewelUpgradeLevelMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		if (ElementalChaosAmulet == 0)
		{
			this->ChaosBoxInit(lpObj);

			this->GCChaosBoxSend(lpObj, 0);

			this->GCChaosMixSend(lpObj->Index, 225, 0);

			gLog.Output(LOG_CHAOS_MIX, "[PentagramJewelUpgradeLevelMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d, ChaosAmulet: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney, ElementalChaosAmulet);
		}
		else
		{
			this->ChaosBoxItemDown(lpObj, PentagramJewelSlot);

			this->GCChaosBoxSend(lpObj, 0);

			this->GCChaosMixSend(lpObj->Index, 225, 0);

			gLog.Output(LOG_CHAOS_MIX, "[PentagramJewelUpgradeLevelMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d, ChaosAmulet: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney, ElementalChaosAmulet);
		}
	}

#endif
}

void CChaosBox::PentagramJewelUpgradeRankMix(LPOBJ lpObj, BYTE info) // OK
{
#if(GAMESERVER_UPDATE>=701)

	int BlessCount = 0;
	int SoulCount = 0;
	int SpiritPowderCount = 0;
	int PentagramJewelCount = 0;
	int PentagramJewelSlot = 0;
	int SetItemCount = 0;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 13))
		{
			BlessCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(14, 14))
		{
			SoulCount++;
		}
		else if (lpObj->ChaosBox[n].m_Index == GET_ITEM(12, 151))
		{
			SpiritPowderCount++;
		}
		else if (lpObj->ChaosBox[n].IsPentagramJewel() != 0 && lpObj->ChaosBox[n].m_Level >= 7)
		{
			PentagramJewelCount++;
			PentagramJewelSlot = n;
		}
		else if (lpObj->ChaosBox[n].IsSetItem() != 0 && lpObj->ChaosBox[n].m_Level >= 7 && lpObj->ChaosBox[n].m_Option3 >= 1)
		{
			SetItemCount++;
		}
	}

	if (BlessCount != (info - 1) || SoulCount != (info - 1) || SpiritPowderCount != (info - 1) || PentagramJewelCount != 1 || SetItemCount != 1)
	{
		this->GCChaosMixSend(lpObj->Index, 250, 0);
		return;
	}

	if (CHECK_RANGE(((lpObj->ChaosBox[PentagramJewelSlot].m_SocketOptionBonus / 16) - 1), (MAX_PENTAGRAM_JEWEL_RANK - 1)) == 0 || (lpObj->ChaosBox[PentagramJewelSlot].m_SocketOptionBonus / 16) != (info - 1))
	{
		this->GCChaosMixSend(lpObj->Index, 252, 0);
		return;
	}

	PENTAGRAM_JEWEL_UPGRADE_RANK_INFO PentagramJewelUpgradeRankInfo;

	if (gPentagramSystem.GetPentagramJewelUpgradeRankInfo((info - 1), &PentagramJewelUpgradeRankInfo) == 0)
	{
		this->GCChaosMixSend(lpObj->Index, 248, 0);
		return;
	}

	lpObj->ChaosSuccessRate = PentagramJewelUpgradeRankInfo.MixRate / 100;

	lpObj->ChaosSuccessRate = ((lpObj->ChaosSuccessRate>100) ? 100 : lpObj->ChaosSuccessRate);

	lpObj->ChaosMoney = PentagramJewelUpgradeRankInfo.MixMoney;

	int TaxMoney = (lpObj->ChaosMoney*gCastleSiegeSync.GetTaxRateChaos(lpObj->Index)) / 100;

	lpObj->ChaosMoney += TaxMoney;

	if (lpObj->Money < ((DWORD)lpObj->ChaosMoney))
	{
		this->GCChaosMixSend(lpObj->Index, 249, 0);
		return;
	}

	lpObj->Money -= lpObj->ChaosMoney;

	GCMoneySend(lpObj->Index, lpObj->Money);

	gCastleSiegeSync.AddTributeMoney(TaxMoney);

	if ((GetLargeRand() % 100) < lpObj->ChaosSuccessRate)
	{
		CItem item = lpObj->ChaosBox[PentagramJewelSlot];

		item.m_Level = 0;

		item.m_SocketOptionBonus += 16;

		if (gPentagramSystem.GetPentagramRandomJewelOption(item.m_Index, (item.m_SocketOptionBonus / 16), &item.m_SocketOption[((item.m_SocketOptionBonus / 16) - 1)]) == 0)
		{
			this->GCChaosMixSend(lpObj->Index, 248, 0);
			return;
		}

		this->ChaosBoxInit(lpObj);

		gItemManager.ChaosBoxAddItem(lpObj->Index, item, 0);

		this->GCChaosMixSend(lpObj->Index, 1, &item);

		gLog.Output(LOG_CHAOS_MIX, "[PentagramJewelUpgradeRankMix][Thành Công] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}
	else
	{
		this->ChaosBoxInit(lpObj);

		this->GCChaosBoxSend(lpObj, 0);

		this->GCChaosMixSend(lpObj->Index, 225, 0);

		gLog.Output(LOG_CHAOS_MIX, "[PentagramJewelUpgradeRankMix][Thất Bại] Account:[%s] Name:[%s] - (ChaosSuccessRate: %d, ChaosMoney: %d)", lpObj->Account, lpObj->Name, lpObj->ChaosSuccessRate, lpObj->ChaosMoney);
	}

#endif
}

void CChaosBox::CGChaosMixRecv(PMSG_CHAOS_MIX_RECV* lpMsg, int aIndex) // OK
{
	LPOBJ lpObj = &gObj[aIndex];

#if(CHECK_USER == 1)
	if (lpObj->Interface.type == INTERFACE_TRADE
		|| lpObj->Interface.type == INTERFACE_PARTY
		|| lpObj->Interface.type == INTERFACE_WAREHOUSE
		|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
		|| lpObj->Interface.type == INTERFACE_CASH_SHOP
		)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
		return;
	}
#endif



	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}

	if (lpObj->ChaosLock != 0)
	{
		return;
	}

	if (lpObj->PShopOpen != 0)
	{
		return;
	}

	lpObj->ChaosLock = 1;

	lpObj->ChaosMoney = 0;

	lpObj->ChaosSuccessRate = 0;

	lpObj->IsChaosMixCompleted = 1;

	switch (lpMsg->type)
	{
	case CHAOS_MIX_CHAOS_ITEM:
		this->ChaosItemMix(lpObj);
		break;
	case CHAOS_MIX_DEVIL_SQUARE:
		this->DevilSquareMix(lpObj);
		break;
	case CHAOS_MIX_PLUS_ITEM_LEVEL1:
		this->PlusItemLevelMix(lpObj, 0);
		break;
	case CHAOS_MIX_PLUS_ITEM_LEVEL2:
		this->PlusItemLevelMix(lpObj, 1);
		break;
	case CHAOS_MIX_DINORANT:
		this->DinorantMix(lpObj);
		break;
	case CHAOS_MIX_FRUIT:
		this->FruitMix(lpObj);
		break;
	case CHAOS_MIX_WING1:
		this->Wing2Mix(lpObj, 0);
		break;
	case CHAOS_MIX_BLOOD_CASTLE:
		this->BloodCastleMix(lpObj);
		break;
	case CHAOS_MIX_WING2:
		this->Wing1Mix(lpObj);
		break;
	case CHAOS_MIX_PET1:
		this->PetMix(lpObj, 0);
		break;
	case CHAOS_MIX_PET2:
		this->PetMix(lpObj, 1);
		break;
	case CHAOS_MIX_SIEGE_POTION1:
		this->SiegePotionMix(lpObj, 0);
		break;
	case CHAOS_MIX_SIEGE_POTION2:
		this->SiegePotionMix(lpObj, 1);
		break;
	case CHAOS_MIX_LIFE_STONE:
		this->LifeStoneMix(lpObj);
		break;
	case CHAOS_MIX_SENIOR:
		this->SeniorMix(lpObj);
		break;
	case CHAOS_MIX_PLUS_ITEM_LEVEL3:
		this->PlusItemLevelMix(lpObj, 2);
		break;
	case CHAOS_MIX_PLUS_ITEM_LEVEL4:
		this->PlusItemLevelMix(lpObj, 3);
		break;
	case CHAOS_MIX_WING3:
		this->Wing2Mix(lpObj, 1);
		break;
	case CHAOS_MIX_PIECE_OF_HORN:
		this->PieceOfHornMix(lpObj);
		break;
	case CHAOS_MIX_BROKEN_HORN:
		this->BrokenHornMix(lpObj);
		break;
	case CHAOS_MIX_HORN_OF_FENRIR:
		this->HornOfFenrirMix(lpObj);
		break;
	case CHAOS_MIX_HORN_OF_FENRIR_UPGRADE:
		this->HornOfFenrirUpgradeMix(lpObj);
		break;
	case CHAOS_MIX_SHIELD_POTION1:
		this->ShieldPotionMix(lpObj, 0);
		break;
	case CHAOS_MIX_SHIELD_POTION2:
		this->ShieldPotionMix(lpObj, 1);
		break;
	case CHAOS_MIX_SHIELD_POTION3:
		this->ShieldPotionMix(lpObj, 2);
		break;
	case CHAOS_MIX_JEWEL_OF_HARMONY_ITEM_PURITY:
		this->JewelOfHarmonyItemPurityMix(lpObj);
		break;
	case CHAOS_MIX_JEWEL_OF_HARMONY_ITEM_SMELT:
		this->JewelOfHarmonyItemSmeltMix(lpObj);
		break;
	case CHAOS_MIX_JEWEL_OF_HARMONY_ITEM_RESTORE:
		this->JewelOfHarmonyItemRestoreMix(lpObj);
		break;
	case CHAOS_MIX_ITEM_380:
		this->Item380Mix(lpObj);
		break;
	case CHAOS_MIX_ILLUSION_TEMPLE:
		this->IllusionTempleMix(lpObj);
		break;
	case CHAOS_MIX_FEATHER_OF_CONDOR:
		this->FeatherOfCondorMix(lpObj);
		break;
	case CHAOS_MIX_WING4:
		this->Wing3Mix(lpObj);
		break;
	case CHAOS_MIX_CHAOS_CARD:
		this->ChaosCardMix(lpObj, 0);
		break;
	case CHAOS_MIX_CHERRY_BLOSSOM:
		this->CherryBlossomMix(lpObj, 0);
		break;
	case CHAOS_MIX_SOCKET_ITEM_CREATE_SEED:
		this->SocketItemCreateSeedMix(lpObj);
		break;
	case CHAOS_MIX_SOCKET_ITEM_CREATE_SEED_SPHERE:
		this->SocketItemCreateSeedSphereMix(lpObj);
		break;
	case CHAOS_MIX_SOCKET_ITEM_MOUNT_SEED_SPHERE:
		this->SocketItemMountSeedSphereMix(lpObj, lpMsg->info);
		break;
	case CHAOS_MIX_SOCKET_ITEM_UN_MOUNT_SEED_SPHERE:
		this->SocketItemUnMountSeedSphereMix(lpObj, lpMsg->info);
		break;
	case CHAOS_MIX_IMPERIAL_GUARDIAN:
		this->ImperialGuardianMix(lpObj);
		break;
	case CHAOS_MIX_CHEST:
		this->ChestMix(lpObj);
		break;
	case CHAOS_MIX_SUMMON_SCROLL:
		this->SummonScrollMix(lpObj, 0);
		break;
	case CHAOS_MIX_PLUS_ITEM_LEVEL5:
		this->PlusItemLevelMix(lpObj, 4);
		break;
	case CHAOS_MIX_PLUS_ITEM_LEVEL6:
		this->PlusItemLevelMix(lpObj, 5);
		break;
	case CHAOS_MIX_LUCKY_ITEM_CREATE:
		this->LuckyItemCreateMix(lpObj);
		break;
	case CHAOS_MIX_LUCKY_ITEM_REFINE:
		this->LuckyItemRefineMix(lpObj);
		break;
	case CHAOS_MIX_MONSTER_WING:
		this->MonsterWingMix(lpObj);
		break;
	case CHAOS_MIX_SOCKET_WEAPON:
		this->SocketWeaponMix(lpObj);
		break;
	case CHAOS_MIX_FENRIR_GOLD:
		this->HornOfFenrirGoldMix(lpObj);
		break;
	default:
		this->CustomItemMix(lpObj, lpMsg->type);
		break;

#if(CUSTOM_MIX_WING_CUSTOM)
	case CHAOS_MIX_WING_CUSTOM:
		this->WingCustomMix(lpObj);
		break;
#endif
		//-----------------------------------------------------------------------
#if(CUSTOM_MIX_WING_SEASON13)
	case CHAOS_MIX_WING_SEASON13:
		this->WingSeason13Mix(lpObj);
		break;
#endif
		//-----------------------------------------------------------------------

		//-----------------------------------------------------------------------
#if(CUSTOM_MIX_WING_SEASON8)
	case CHAOS_MIX_WING_SEASON8:
		this->WingSeason8Mix(lpObj);
		break;
#endif

#if(CUSTOM_MIX_WING_VIP)
	case CHAOS_MIX_WING_VIP:
		this->WingVipMix(lpObj);
		break;
#endif

#if(CUSTOM_MIX_PET_CAP2)
	case CHAOS_MIX_MUUN_2:
		this->Muun2Mix(lpObj);
		break;
#endif
#if(CUSTOM_MIX_PET_CAP3)
	case CHAOS_MIX_MUUN_3:
		this->Muun3Mix(lpObj);
		break;
#endif
#if(CUSTOM_MIX_PET_CAP4)
	case CHAOS_MIX_MUUN_4:
		this->Muun4Mix(lpObj);
		break;
#endif
#if(CUSTOM_MIX_PET_CAP5)
	case CHAOS_MIX_MUUN_5:
		this->Muun5Mix(lpObj);
		break;
#endif
#if(CUSTOM_MIX_PET_CAP6)
	case CHAOS_MIX_MUUN_6:
		this->Muun6Mix(lpObj);
		break;
#endif

#if(CUSTOM_MIX_PET_CAP7)
	case CHAOS_MIX_MUUN_7:
		this->Muun7Mix(lpObj);
		break;
#endif

#if(CUSTOM_MIX_PET_CAP8)
	case CHAOS_MIX_MUUN_8:
		this->Muun8Mix(lpObj);
		break;
#endif

#if(CUSTOM_MIX_PET_CAP9)
	case CHAOS_MIX_MUUN_9:
		this->Muun9Mix(lpObj);
		break;
#endif

#if(CUSTOM_MIX_PET_CAP10)
	case CHAOS_MIX_MUUN_10:
		this->Muun10Mix(lpObj);
		break;
#endif

#if(CUSTOM_MIX_PET_CAP11)
	case CHAOS_MIX_MUUN_11:
		this->Muun11Mix(lpObj);
		break;
#endif

	}
}

void CChaosBox::CGChaosMixCloseRecv(int aIndex) // OK
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}

	if (lpObj->Interface.use == 0 || lpObj->Interface.type != INTERFACE_CHAOS_BOX)
	{
		return;
	}

	lpObj->Interface.use = 0;
	lpObj->Interface.type = INTERFACE_NONE;
	lpObj->Interface.state = 0;

	this->ChaosBoxInit(lpObj);

	gObjInventoryCommit(aIndex);

	lpObj->ChaosLock = 0;

	lpObj->IsChaosMixCompleted = 0;

	lpObj->IsCastleNPCUpgradeCompleted = 0;

	PBMSG_HEAD pMsg;

	pMsg.set(0x87, sizeof(pMsg));

	DataSend(aIndex, (BYTE*)&pMsg, pMsg.size);
}

void CChaosBox::GCChaosBoxSend(LPOBJ lpObj, BYTE type) // OK
{
	if ((type == 0 && (lpObj->Interface.type != INTERFACE_CHAOS_BOX || lpObj->Interface.state == 1)) || (type != 0 && (lpObj->Interface.type != INTERFACE_TRAINER || lpObj->Interface.state == 1)))
	{
		return;
	}

	BYTE send[2048];

	PMSG_SHOP_ITEM_LIST_SEND pMsg;

	pMsg.header.set(0x31, 0);

	int size = sizeof(pMsg);

	pMsg.type = ((type == 0) ? 3 : 5);

	pMsg.count = 0;

	PMSG_SHOP_ITEM_LIST info;

	for (int n = 0; n < CHAOS_BOX_SIZE; n++)
	{
		if (lpObj->ChaosBox[n].IsItem() == 0)
		{
			continue;
		}

		info.slot = n;

		gItemManager.ItemByteConvert(info.ItemInfo, lpObj->ChaosBox[n]);

		memcpy(&send[size], &info, sizeof(info));
		size += sizeof(info);

		pMsg.count++;
	}

	pMsg.header.size[0] = SET_NUMBERHB(size);
	pMsg.header.size[1] = SET_NUMBERLB(size);

	memcpy(send, &pMsg, sizeof(pMsg));

	DataSend(lpObj->Index, send, size);
}

void CChaosBox::GCChaosMixSend(int aIndex, BYTE result, CItem* lpItem) // OK
{
	PMSG_CHAOS_MIX_SEND pMsg;

	LPOBJ lpObj = &gObj[aIndex];

	/*ITEM_INFO ItemInfo;

	int index;

	char buff[256];
	int type;*/

	pMsg.header.set(0x86, sizeof(pMsg));

	pMsg.result = result;

	if (lpItem == 0)
	{


		memset(pMsg.ItemInfo, 0xFF, sizeof(pMsg.ItemInfo));
		//gNotice.GCNoticeSendToAll(0,0,0,0,0,0,"1"); //quay xit
		//wsprintf(buff,"Ban %s da quay xit",lpObj->Name,ItemInfo.Name);
		//gNotice.GCNoticeSendToAll(0,0,0,0,0,0,buff);

	}
	else
	{
		gItemManager.ItemByteConvert(pMsg.ItemInfo, (*lpItem));
		//gNotice.GCNoticeSendToAll(0,0,0,0,0,0,"2"); // thanhf coong
		//gNotice.GCNoticeSendToAll(0,0,0,0,0,0,"Ban %s da quay thanh cong %s",lpObj->Name,ItemInfo.Name);
		//wsprintf(buff,"Ban %s da quay thanh cong %s",lpObj->Name,ItemInfo.Name);
		//gNotice.GCNoticeSendToAll(0,0,0,0,0,0,buff);
	}



	DataSend(aIndex, (BYTE*)&pMsg, pMsg.header.size);

	gObj[aIndex].ChaosLock = 0;
}
