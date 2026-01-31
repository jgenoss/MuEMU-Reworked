#include "StdAfx.h"
#include "CustomLuckySpin.h"
#include "DSProtocol.h"
#include "MemScript.h"
#include "Util.h"
#include "ItemManager.h"
#include "CashShop.h"
#include "User.h"
#include "Notice.h"
#include "Message.h"
#include "ServerInfo.h"
#include "Path.h"

#if(VONGQUAY_NEW)

CLuckySpin gLuckySpin;

CLuckySpin::CLuckySpin()
{
	this->Init();
}

CLuckySpin::~CLuckySpin()
{
}

void CLuckySpin::Init()
{
	this->itemdata.clear();
	this->TicketType = 0;
	this->TicketIndex = 0;
	this->number = -1;
}

void CLuckySpin::Load()
{
	this->Init();
	this->Read(gPath.GetFullPath("Custom\\VongQoayMayMan.txt"));
}

void CLuckySpin::Read(char* path)
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

					this->TicketType = lpMemScript->GetNumber();
					this->TicketIndex = lpMemScript->GetAsNumber();
					this->TicketCount = lpMemScript->GetAsNumber();
					this->TicketWcoinC = lpMemScript->GetAsNumber();
				}
				else if (section == 1)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					LuckySpin_Data info;

					info.ItemType = lpMemScript->GetNumber();

					info.ItemIndex = lpMemScript->GetAsNumber();

					info.ItemLevel = lpMemScript->GetAsNumber();

					info.ItemSkill = lpMemScript->GetAsNumber();

					info.ItemLuck = lpMemScript->GetAsNumber();

					info.ItemOption = lpMemScript->GetAsNumber();

					info.ItemExc = lpMemScript->GetAsNumber();

					info.ItemTime = lpMemScript->GetAsNumber();

					this->itemdata.push_back(info);
				}
				else
				{
					break;
				}
			}
		}
	}
	catch (...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void CLuckySpin::GCInitItem(int aIndex)
{
	if (gObjIsConnected(aIndex) == 0)
	{
		return;
	}

	GC_LuckySpinInit pMsg;
	pMsg.h.set(0xFB, 0x34, sizeof(pMsg));
	pMsg.result = true;
	DataSend(aIndex, (LPBYTE)&pMsg, sizeof(pMsg));
}

void CLuckySpin::GCItemSend(int aIndex)
{
	if (gObjIsConnected(aIndex) == 0)
	{
		return;
	}

	GC_LuckySpin_Data pMsg;
	pMsg.h.set(0xFB, 0x33, sizeof(pMsg));
	for (int i = 0; i < itemdata.size(); i++)
	{
		pMsg.ItemType = itemdata[i].ItemType;
		pMsg.ItemIndex = itemdata[i].ItemIndex;
		pMsg.ItemLevel = itemdata[i].ItemLevel;
		pMsg.ItemExc = itemdata[i].ItemExc;
		pMsg.WCoinC = this->TicketWcoinC;
		DataSend(aIndex, (BYTE*)&pMsg, sizeof(pMsg));
	}

	this->GCInitItem(aIndex);
}

int CLuckySpin::GetItemCount(int UserIndex)
{
	if (!OBJMAX_RANGE(UserIndex))
	{
		return -1;
	}
	// ----
	int ItemCount = 0;
	LPOBJ lpUser = &gObj[UserIndex];
	// ----
	for (int i = INVENTORY_WEAR_SIZE; i < INVENTORY_MAIN_SIZE; i++)
	{
		if (!lpUser->Inventory[i].IsItem())
		{
			continue;
		}
		// ----
		if (lpUser->Inventory[i].m_Index == GET_ITEM(this->TicketType, this->TicketIndex))
		{
			ItemCount++;
		}
	}
	// ----
	return ItemCount;
}

int CLuckySpin::CheckItem(int UserIndex, int ItemID, BYTE ItemLevel)
{
	if (!OBJMAX_RANGE(UserIndex))
	{
		return -1;
	}
	// ----
	LPOBJ lpUser = &gObj[UserIndex];
	// ----
	for (int i = INVENTORY_WEAR_SIZE; i < INVENTORY_MAIN_SIZE; i++)
	{
		if (!lpUser->Inventory[i].IsItem())
		{
			continue;
		}
		// ----
		if (lpUser->Inventory[i].m_Index == ItemID
			&&  lpUser->Inventory[i].m_Level == ItemLevel)
		{
			return i;
		}
	}
	// ----
	return -1;
}


bool CLuckySpin::DeleteItemCount(int UserIndex, int SoulCount)
{
	if (!OBJMAX_RANGE(UserIndex))
	{
		return false;
	}
	// ----
	if (this->GetItemCount(UserIndex) < SoulCount)
	{
		return false;
	}
	// ----
	int DeletedItem = 0;
	int CheckedItem = 0;
	LPOBJ lpUser = &gObj[UserIndex];
	// ----CHECK IF SOUL ARE OK BEFORE REMOVING
	while (true)
	{
		int needed = SoulCount - CheckedItem;

		// ----
		if (needed <= 0)
		{
			break;
		}
		// ----
		bool hassoul = FALSE;

		if (this->CheckItem(UserIndex, GET_ITEM(this->TicketType, this->TicketIndex), 0) != -1)
		{
			int ItemPos = this->CheckItem(UserIndex, GET_ITEM(this->TicketType, this->TicketIndex), 0);
			CheckedItem++;
			hassoul = TRUE;
		}
		if (hassoul == FALSE)
		{
			gNotice.GCNoticeSend(lpUser->Index, 1, 0, 0, 0, 0, 0, "Ban can giai nen ngoc");

			return false;
		}
	}
	// ----
	while (true)
	{
		int ItemDiff = SoulCount - DeletedItem;
		// ----
		if (ItemDiff <= 0)
		{
			break;
		}
		// ----
		if (this->CheckItem(UserIndex, GET_ITEM(this->TicketType, this->TicketIndex), 0) != -1)
		{
			int ItemPos = this->CheckItem(UserIndex, GET_ITEM(this->TicketType, this->TicketIndex), 0);
			gItemManager.DeleteInventoryItemCount(lpUser, ItemPos, 0, this->TicketCount);
			DeletedItem++;
		}
	}

	return true;
}

void CLuckySpin::StartRoll(LPOBJ lpObj)
{
	//if (this->GetItemCount(lpObj->Index) < this->TicketCount)
	//{
	//	gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(404), this->TicketCount);
	//	return;
	//}
	if (lpObj->Coin1 < this->TicketWcoinC)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(919), this->TicketWcoinC);
		return;
	}
	this->DeleteItemCount(lpObj->Index, this->TicketCount);
	gCashShop.GDCashShopSubPointSaveSend(lpObj->Index, 0, this->TicketWcoinC, 0, 0, 0);
	gCashShop.CGCashShopPointRecv(lpObj->Index);
	lpObj->LuckySpinTime = GetTickCount();

	GC_LuckySpinRoll pMsg;
	pMsg.header.set(0xFB, 0x32, sizeof(pMsg));
	DataSend(lpObj->Index, (BYTE*)&pMsg, pMsg.header.size);
	//
	gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(920), lpObj->Name);
}

void CLuckySpin::MakeItem(int aIndex)
{
	srand(time(NULL));
	number = rand() % 11;
	time_t t = time(NULL);
	localtime(&t);
	DWORD iTime = (DWORD)t + this->itemdata[number].ItemTime * 86400;

	GDCreateItemSend(aIndex, 0xEB, 0, 0, GET_ITEM(this->itemdata[number].ItemType, this->itemdata[number].ItemIndex), this->itemdata[number].ItemLevel, 0, this->itemdata[number].ItemSkill, this->itemdata[number].ItemLuck, this->itemdata[number].ItemOption, -1, this->itemdata[number].ItemExc, 0, 0, 0, 0, 0xFF, 0);
}
#endif