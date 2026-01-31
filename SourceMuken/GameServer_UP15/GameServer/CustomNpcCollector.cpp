#include "stdafx.h"
#include "DSProtocol.h"
#include "MemScript.h"
#include "Message.h"
#include "Notice.h"
#include "ItemManager.h"
#include "Path.h"
#include "ServerInfo.h"
#include "User.h"
#include "Util.h"
#include "CustomNpcCollector.h"


CCustomNpcCollector gCustomNpcCollector;

void CCustomNpcCollector::Load(char* path)
{

	CMemScript* lpMemScript = new CMemScript;

	if (lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR, path);
		return;
	}

	if (lpMemScript->SetBuffer(path) == 0)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	for (int n = 0; n < MAX_ITEM_LIST; n++)
	{

		this->m_Data[this->m_count].m_Cat = -1;

		this->m_Data[this->m_count].m_Item = -1;

		this->m_Data[this->m_count].m_Coin1 = 0;

		this->m_Data[this->m_count].m_Coin2 = 0;

		this->m_Data[this->m_count].m_Coin3 = 0;

		this->m_Data[this->m_count].m_ItemIndex = -1;
	}

	this->m_count = 0;

	try
	{
		while (true)
		{
			if (lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			int section = lpMemScript->GetNumber();

			while (true)
			{
				if (section == 0)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					this->m_Data[this->m_count].m_Cat = lpMemScript->GetNumber();

					this->m_Data[this->m_count].m_Item = lpMemScript->GetAsNumber();

					this->m_Data[this->m_count].m_Coin1 = lpMemScript->GetAsNumber();

					this->m_Data[this->m_count].m_Coin2 = lpMemScript->GetAsNumber();

					this->m_Data[this->m_count].m_Coin3 = lpMemScript->GetAsNumber();

					this->m_Data[this->m_count].m_ItemIndex = SafeGetItem(GET_ITEM(lpMemScript->GetAsNumber(), lpMemScript->GetAsNumber()));

					this->m_count++;
				}
			}
		}
	}
	catch (...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;

	//LogAdd(LOG_BLUE, "[ServerInfo] CustomNpcCollector Info loaded successfully");
}


void CCustomNpcCollector::NpcTalk(LPOBJ lpNpc, LPOBJ lpObj)
{
#if (GAMESERVER_CLIENTE_UPDATE >= 4)

	if (gServerInfo.m_CustomNpcCollectorSwitch == 0)
	{
		GCChatTargetSend(lpObj, lpNpc->Index, gMessage.GetMessage(740));
		return;
	}

	if (lpObj->Interface.use != 0)
	{
		return;
	}

	int ItemIndex;
	int Count = 0;

	/*
	#define INVENTORY_MAIN_SIZE_CUSTOM gServerInfo.m_InventoryMainGetGift	24
	#define INVENTORY_WEAR_SIZE_CUSTOM gServerInfo.m_InventoryWearGetGift	12
	*/


	if (lpObj->Inventory[INVENTORY_WEAR_SIZE_CUSTOM].IsItem() == TRUE)
	{
		ItemIndex = lpObj->Inventory[gServerInfo.m_NumBerGetGift].m_Index;
	}
	else
	{
		GCChatTargetSend(lpObj, lpNpc->Index, gMessage.GetMessage(741));
		return;
	}

	for (int i = INVENTORY_WEAR_SIZE_CUSTOM; i < INVENTORY_MAIN_SIZE_CUSTOM; i++)
	{
		if (lpObj->Inventory[i].IsItem() == TRUE)
		{
			if (lpObj->Inventory[i].m_Index == ItemIndex)
			{
				Count++;
			}
			else
			{
				GCChatTargetSend(lpObj, lpNpc->Index, gMessage.GetMessage(741));
				return;
			}
		}
		else
		{
			GCChatTargetSend(lpObj, lpNpc->Index, gMessage.GetMessage(741));
			return;
		}
	}

	if (Count == gServerInfo.m_NumBerGetGift)
	{
		int Box = 0;
		unsigned char ItemsIndex[5] = { 8, 9, 10, 11, 12 };
		Box = ItemsIndex[rand() % 5];
		for (int i = 0; i < MAX_ITEM_LIST; i++)
		{
			if (ItemIndex == GET_ITEM(this->m_Data[i].m_Cat, this->m_Data[i].m_Item))
			{
				//-- Reward
				GCChatTargetSend(lpObj, lpNpc->Index, gMessage.GetMessage(742));

				GCFireworksSend(lpNpc, lpNpc->X, lpNpc->Y);

				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(744));

				GDSetCoinSend(lpObj->Index, this->m_Data[i].m_Coin1, this->m_Data[i].m_Coin2, this->m_Data[i].m_Coin3, "NpCCollector");

				GDCreateItemSend(lpObj->Index, 0xEB, 0, 0, this->m_Data[i].m_ItemIndex, Box, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);

				for (int i = INVENTORY_WEAR_SIZE_CUSTOM; i < INVENTORY_MAIN_SIZE_CUSTOM; i++)
				{
					gItemManager.InventoryDelItem(lpObj->Index, i);
					gItemManager.GCItemDeleteSend(lpObj->Index, i, 1);
				}

				return;
			}
		}
	}

	GCChatTargetSend(lpObj, lpNpc->Index, gMessage.GetMessage(743));
	return;

#endif
}