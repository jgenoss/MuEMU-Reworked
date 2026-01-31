#include "stdafx.h"
#include "CustomJewelBank.h"
#include "Defines.h"
#include "Import.h"
#include "Interface.h"
#include "Offset.h"
#include "Protect.h"
#include "Util.h"
#include "HealthBar.h"
#include "Import.h"
#include "Object.h"
#include "PrintPlayer.h"
#include "User.h"
#include "Item.h"

CCustomJewelBank gCustomJewelBank;

CCustomJewelBank::CCustomJewelBank()
{
	this->m_Data.Bless = 0;
	this->m_Data.Soul = 0;
	this->m_Data.Life = 0;
	this->m_Data.Creation = 0;
	this->m_Data.Guardian = 0;
	this->m_Data.GemStone = 0;
	this->m_Data.Harmony = 0;
	this->m_Data.Chaos = 0;
	this->m_Data.LowStone = 0;
	this->m_Data.HighStone = 0;
	this->Page = 0;
}

void CCustomJewelBank::DrawNewStatus()
{
	//if(gProtect.m_MainInfo.CustomAdvancedStausEnable != 1)
	//{
	//	return;
	//}

}

void CCustomJewelBank::JewelBankSend(int slot)
{
	if ((GetTickCount() - this->StatusTick) < 400)
	{
		//gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
		return;
	}

	if (slot < 0)
	{
		return;
	}

	this->StatusTick = GetTickCount();

	//this->JewelEnable = false;

	PSBMSG_JEWELBANK_SEND pMsg;

	pMsg.slot = slot;

	pMsg.header.set(0xF3, 0xF5, sizeof(pMsg));

	DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CCustomJewelBank::GCCustomJewelBankInfoRecv(PSBMSG_JEWELBANK_RECV* lpMsg) // OK
{
	this->m_Data.Bless = lpMsg->Bless;
	this->m_Data.Soul = lpMsg->Soul;
	this->m_Data.Life = lpMsg->Life;
	this->m_Data.Creation = lpMsg->Creation;
	this->m_Data.Guardian = lpMsg->Guardian;
	this->m_Data.GemStone = lpMsg->GemStone;
	this->m_Data.Harmony = lpMsg->Harmony;
	this->m_Data.Chaos = lpMsg->Chaos;
	this->m_Data.LowStone = lpMsg->LowStone;
	this->m_Data.HighStone = lpMsg->HighStone;

	this->JewelEnable = 1;
}

void InvetoryItemOver(int This)
{
	lpItemObj item = (lpItemObj)*(DWORD*)(This + 84);

	if (item)
	{
		if (GetKeyState(VK_RBUTTON) & 0x8000 && GetKeyState(VK_SHIFT) & 0x8000)
		{
			int start = 12;
			if (*(DWORD*)(This + 44) == 200)
			{
				start = 12;
			}
			else if (*(DWORD*)(This + 44) == 44)
			{
				start = 76;
			}
			else if (*(DWORD*)(This + 44) == 131)
			{
				start = 108;
			}

			int Slot = item->PosX + (item->PosY * 8) + start;

			gCustomJewelBank.JewelBankSend(Slot);
		}
	}

	((void(__thiscall*)(int))0x007DCF20)(This);
}

void CCustomJewelBank::Load()
{
	SetCompleteHook(0xE8, 0x007DD0D9, &InvetoryItemOver);
}

void CCustomJewelBank::DrawJewelBankWindow()
{

	if (gInterface.Data[eJewelBank_MAIN].OnShow == false)
	{
		return;
	}

	if (gInterface.CheckWindow(SkillTree) || gInterface.CheckWindow(Character) || gInterface.CheckWindow(Shop) || gInterface.CheckWindow(CreateGuild) || gInterface.CheckWindow(ChatWindow) || gInterface.CheckWindow(FriendList) || gInterface.CheckWindow(MuHelper) || gInterface.CheckWindow(Store) || gInterface.CheckWindow(Warehouse) || gInterface.CheckWindow(Trade) || gInterface.CheckWindow(CashShop) || gInterface.CheckWindow(MoveList) || gInterface.CheckWindow(ChaosBox))
	{
		if (gInterface.Data[eJewelBank_MAIN].OnShow == true)
		{
			gInterface.Data[eJewelBank_MAIN].OnShow = false;
			pSetCursorFocus = false;
			return;
		}
	}

	int BackSpace = 0;

	if (gInterface.CheckWindow(ExpandInventory))
	{
		BackSpace = 180.0;
	}

	pSetCursorFocus = true;
	float MainWidth = 230.0;
	float MainHeight = 180.0;
	float StartBody = 55.0;
	float StartY = 55.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2) - BackSpace;
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	// ----
	gInterface.DrawGUI(eJewelBank_MAIN, StartX, StartY + (float)2.0);
	gInterface.DrawGUI(eJewelBank_TITLE, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(eJewelBank_FRAME, StartX, StartY + (float)5.0, 13);
	gInterface.DrawGUI(eJewelBank_FOOTER, StartX, StartY);

	//pDrawGUFULL(0x9333, StartX - 10, StartY - 5, 250, 260, 0, 0, 1, 1, 1, 1, 0.0); // MENU


	gInterface.DrawGUI(eJewelBank_CLOSE, StartX + MainWidth - gInterface.Data[eJewelBank_CLOSE].Width, StartBody);
	// ----
	DWORD Color = eGray100;
	if (gInterface.IsWorkZone(eJewelBank_CLOSE))
	{
		// ----
		if (gInterface.Data[eJewelBank_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI(eJewelBank_CLOSE, gInterface.Data[eJewelBank_CLOSE].X, StartBody, Color);
		gInterface.DrawToolTip((int)gInterface.Data[eJewelBank_CLOSE].X + 5, (int)gInterface.Data[eJewelBank_CLOSE].Y + 25, gCustomMessage.GetMessageB(388));
	}

	gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, "Ngân Hàng Ngọc");

	if (this->JewelEnable == 1)
	{
		StartBody -= 15;

		if (this->Page == 0)
		{
			gInterface.DrawGUI(eJewelBank_NEXT, StartX + MainWidth - gInterface.Data[eSAMPLEBUTTON].Width - 10, 170);
			gInterface.ResetDrawIMG(eJewelBank_PREV);
		}
		else
		{
			gInterface.DrawGUI(eJewelBank_PREV, StartX + MainWidth - gInterface.Data[eSAMPLEBUTTON].Width - 8, 170);
			gInterface.ResetDrawIMG(eJewelBank_NEXT);
		}

		for (int i = (5 * this->Page); i < (5 * this->Page) + 5; i++)
		{


			int posxx = 0;
			int WidthValue = 18;
			int HeightValue = 20;
			int ItemType;
			int ItemIndex;
			ItemBmdStruct* ItemInfo = pGetItemBmdStruct(ITEM(12, 15));
			int posyy = (i >= 5) ? (i - 5) : i;

			if (i == 0)
			{


				float barWidth = WidthValue*ItemInfo->ItemWidth;
				float barHeight = HeightValue*ItemInfo->ItemHeight;

				gInterface.DrawItem2(StartX + 15, StartBody + 55 + (34 * posyy), barWidth, barHeight, GET_ITEM(14, 13), 0, 0, 0, 0);

				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 57 + (36 * posyy), 52, 1, gCustomMessage.GetMessageB(1806));
				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 67 + (36 * posyy), 52, 1, "x %d", this->m_Data.Bless);
			}
			if (i == 1)
			{

				float barWidth = WidthValue*ItemInfo->ItemWidth;
				float barHeight = HeightValue*ItemInfo->ItemHeight;

				gInterface.DrawItem2(StartX + 15, StartBody + 55 + (34 * posyy), barWidth, barHeight, GET_ITEM(14, 14), SET_ITEMOPT_LEVEL(0), 0, 0, 0);

				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 57 + (36 * posyy), 52, 1, gCustomMessage.GetMessageB(1807));
				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 67 + (36 * posyy), 52, 1, "x %d", this->m_Data.Soul);
			}
			if (i == 2)
			{

				float barWidth = WidthValue*ItemInfo->ItemWidth;
				float barHeight = HeightValue*ItemInfo->ItemHeight;

				gInterface.DrawItem2(StartX + 15, StartBody + 60 + (34 * posyy), barWidth, barHeight, GET_ITEM(14, 16), SET_ITEMOPT_LEVEL(0), 0, 0, 0);

				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 57 + (36 * posyy), 52, 1, gCustomMessage.GetMessageB(3312));
				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 67 + (36 * posyy), 52, 1, "x %d", this->m_Data.Life);
			}
			if (i == 3)
			{

				float barWidth = WidthValue*ItemInfo->ItemWidth;
				float barHeight = HeightValue*ItemInfo->ItemHeight;

				gInterface.DrawItem2(StartX + 15, StartBody + 60 + (34 * posyy), barWidth, barHeight, GET_ITEM(14, 22), SET_ITEMOPT_LEVEL(0), 0, 0, 0);

				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 57 + (36 * posyy), 60, 1, gCustomMessage.GetMessageB(3313));
				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 67 + (36 * posyy), 52, 1, "x %d", this->m_Data.Creation);
			}
			if (i == 4)
			{

				float barWidth = WidthValue*ItemInfo->ItemWidth;
				float barHeight = HeightValue*ItemInfo->ItemHeight;

				gInterface.DrawItem2(StartX + 15, StartBody + 55 + (34 * posyy), barWidth, barHeight, GET_ITEM(14, 31), SET_ITEMOPT_LEVEL(0), 0, 0, 0);

				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 57 + (36 * posyy), 60, 1, gCustomMessage.GetMessageB(3314));
				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 67 + (36 * posyy), 52, 1, "x %d", this->m_Data.Guardian);
			}
			if (i == 5)
			{


				float barWidth = WidthValue*ItemInfo->ItemWidth;
				float barHeight = HeightValue*ItemInfo->ItemHeight;

				gInterface.DrawItem2(StartX + 15, StartBody + 55 + (34 * posyy), barWidth, barHeight, GET_ITEM(14, 41), SET_ITEMOPT_LEVEL(0), 0, 0, 0);

				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 57 + (36 * posyy), 60, 1, "GemStone");
				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 67 + (36 * posyy), 52, 1, "x %d", this->m_Data.GemStone);
			}
			if (i == 6)
			{

				float barWidth = WidthValue*ItemInfo->ItemWidth;
				float barHeight = HeightValue*ItemInfo->ItemHeight;

				gInterface.DrawItem2(StartX + 15, StartBody + 60 + (34 * posyy), barWidth, barHeight, GET_ITEM(14, 42), SET_ITEMOPT_LEVEL(0), 0, 0, 0);

				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 57 + (36 * posyy), 60, 1, gCustomMessage.GetMessageB(3315));
				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 67 + (36 * posyy), 52, 1, "x %d", this->m_Data.Harmony);
			}
			if (i == 7)
			{

				float barWidth = WidthValue*ItemInfo->ItemWidth;
				float barHeight = HeightValue*ItemInfo->ItemHeight;

				gInterface.DrawItem2(StartX + 15, StartBody + 55 + (34 * posyy), barWidth, barHeight, GET_ITEM(12, 15), SET_ITEMOPT_LEVEL(0), 0, 0, 0);

				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 57 + (36 * posyy), 52, 1, gCustomMessage.GetMessageB(3316));
				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 67 + (36 * posyy), 52, 1, "x %d", this->m_Data.Chaos);
			}
			if (i == 8)
			{

				float barWidth = WidthValue*ItemInfo->ItemWidth;
				float barHeight = HeightValue*ItemInfo->ItemHeight;

				gInterface.DrawItem2(StartX + 15, StartBody + 60 + (34 * posyy), barWidth, barHeight, GET_ITEM(14, 43), SET_ITEMOPT_LEVEL(0), 0, 0, 0);

				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 57 + (36 * posyy), 60, 1, gCustomMessage.GetMessageB(3317));
				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 67 + (36 * posyy), 52, 1, "x %d", this->m_Data.LowStone);
			}
			if (i == 9)
			{

				float barWidth = WidthValue*ItemInfo->ItemWidth;
				float barHeight = HeightValue*ItemInfo->ItemHeight;

				gInterface.DrawItem2(StartX + 15, StartBody + 60 + (34 * posyy), barWidth, barHeight, GET_ITEM(14, 44), SET_ITEMOPT_LEVEL(0), 0, 0, 0);

				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 57 + (36 * posyy), 60, 1, gCustomMessage.GetMessageB(3318));
				gInterface.DrawFormat(eGold, StartX + 35, StartBody + 67 + (36 * posyy), 52, 1, "x %d", this->m_Data.HighStone);
			}

			for (int j = (i * 5); j < (i * 5) + 5; j++)
			{
				gInterface.DrawGUI(eJewelBank_WITHDRAW + j, StartX + 100 + (18 * posxx), StartBody + 55 + (36 * posyy));

				if (posxx == 0)
					gInterface.DrawFormat(eGold, StartX + 105 + (18 * posxx), StartBody + 59 + (36 * posyy), 52, 1, "01");
				if (posxx == 1)
					gInterface.DrawFormat(eGold, StartX + 105 + (18 * posxx), StartBody + 59 + (36 * posyy), 52, 1, "10");
				if (posxx == 2)
					gInterface.DrawFormat(eGold, StartX + 105 + (18 * posxx), StartBody + 59 + (36 * posyy), 52, 1, "20");
				if (posxx == 3)
					gInterface.DrawFormat(eGold, StartX + 105 + (18 * posxx), StartBody + 59 + (36 * posyy), 52, 1, "30");
				if (posxx == 4)
					gInterface.DrawFormat(eGold, StartX + 105 + (18 * posxx), StartBody + 59 + (36 * posyy), 52, 1, "**");

				posxx++;
			}
		}

		gInterface.DrawFormat(eExcellent, StartX, StartBody + 240, 230, 3, " SHIFT + Right Click Để Gửi Ngọc!");
	}
	else
	{
		if (this->Loading == 1)
		{
			gInterface.DrawFormat(eGold, MainCenter + 30, StartBody + 100, 52, 1, gCustomMessage.GetMessage(133), "..");
			this->Loading = 2;
		}
		else if (this->Loading == 2)
		{
			gInterface.DrawFormat(eGold, MainCenter + 30, StartBody + 100, 52, 1, gCustomMessage.GetMessage(133), "...");
			this->Loading = 3;
		}
		else if (this->Loading == 3)
		{
			gInterface.DrawFormat(eGold, MainCenter + 30, StartBody + 100, 52, 1, gCustomMessage.GetMessage(133), "....");
			this->Loading = 4;
		}
		else if (this->Loading == 4)
		{
			gInterface.DrawFormat(eGold, MainCenter + 30, StartBody + 100, 52, 1, gCustomMessage.GetMessage(133), ".....");
			this->Loading = 0;
		}
		else
		{
			gInterface.DrawFormat(eGold, MainCenter + 30, StartBody + 100, 52, 1, gCustomMessage.GetMessage(133), ".");
			this->Loading = 1;
		}
	}
}

void CCustomJewelBank::OpenWindow()
{
	if (gInterface.CheckWindow(SkillTree) || gInterface.CheckWindow(Shop) || gInterface.CheckWindow(CreateGuild) || gInterface.CheckWindow(ChatWindow) || gInterface.CheckWindow(FriendList) || gInterface.CheckWindow(MuHelper) || gInterface.CheckWindow(Store) || gInterface.CheckWindow(Warehouse) || gInterface.CheckWindow(Trade) || gInterface.CheckWindow(CashShop) || gInterface.CheckWindow(GuardNPC))
	{
		return;
	}

	if ((GetTickCount() - gInterface.Data[eJewelBank_MAIN].EventTick) < 500)
	{
		return;
	}

	gInterface.Data[eJewelBank_MAIN].EventTick = GetTickCount();

	if (gInterface.Data[eJewelBank_MAIN].OnShow == true)
	{
		gInterface.Data[eJewelBank_MAIN].OnShow = false;
		pSetCursorFocus = false;
		return;
	}

	gInterface.CloseCustomWindow();

	gInterface.OpenWindow(Inventory);
	gInterface.CloseWindow(Character);
	gInterface.Data[eJewelBank_MAIN].OnShow = true;
	pSetCursorFocus = true;

}

bool CCustomJewelBank::CommandNext(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJewelBank_NEXT].EventTick);
	DWORD Delay2 = (CurrentTick - gInterface.Data[eJewelBank_PREV].EventTick);

	if (!gInterface.Data[eJewelBank_MAIN].OnShow)
	{
		return false;
	}

	if (!gInterface.IsWorkZone(eJewelBank_NEXT))
	{
		return false;
	}

	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJewelBank_NEXT].OnClick = true;
		return true;
	}

	if (Delay < 300 || Delay2 < 300)
	{
		return false;
	}

	gInterface.Data[eJewelBank_NEXT].OnClick = false;

	this->Page++;

	gInterface.Data[eJewelBank_NEXT].EventTick = GetTickCount();


	return true;
}

bool CCustomJewelBank::CommandPrev(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJewelBank_PREV].EventTick);
	DWORD Delay2 = (CurrentTick - gInterface.Data[eJewelBank_NEXT].EventTick);

	if (!gInterface.Data[eJewelBank_MAIN].OnShow)
	{
		return false;
	}

	if (!gInterface.IsWorkZone(eJewelBank_PREV))
	{
		return false;
	}

	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJewelBank_PREV].OnClick = true;
		return true;
	}

	if (Delay < 300 || Delay2 < 300)
	{
		return false;
	}

	gInterface.Data[eJewelBank_PREV].OnClick = false;

	this->Page--;

	gInterface.Data[eJewelBank_PREV].EventTick = GetTickCount();


	return true;
}

bool CCustomJewelBank::EventJewelBankWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJewelBank_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eJewelBank_MAIN].OnShow || !gInterface.IsWorkZone(eJewelBank_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJewelBank_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJewelBank_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJewelBank_CLOSE].EventTick = GetTickCount();
	gInterface.Data[eJewelBank_MAIN].OnShow = false;
	pSetCursorFocus = false;
	// ----
	return false;
}

bool CCustomJewelBank::EventJewelBankWithDraw(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	//DWORD Delay			= (CurrentTick - this->Data[eDIABLO_CLOSE].EventTick);

	if (!gInterface.Data[eJewelBank_MAIN].OnShow)
	{
		return false;
	}

	for (int i = 25 * Page; i<(25 * Page) + 25; i++)
	{
		if (gInterface.IsWorkZone(eJewelBank_WITHDRAW + i))
		{
			DWORD Delay = (CurrentTick - gInterface.Data[eJewelBank_WITHDRAW + i].EventTick);

			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[eJewelBank_WITHDRAW + i].OnClick = true;
				return true;
			}
			// ----
			gInterface.Data[eJewelBank_WITHDRAW + i].OnClick = false;
			// ----
			if (Delay < 300)
			{
				return false;
			}
			// ----

			int type = 0;
			int num = -1;
			int count = -1;

			if (i >= 45 && i < 50)
			{
				type = 9;
				num = i - 45;
			}
			if (i >= 40 && i < 45)
			{
				type = 8;
				num = i - 40;
			}
			if (i >= 35 && i < 40)
			{
				type = 7;
				num = i - 35;
			}
			if (i >= 30 && i < 35)
			{
				type = 6;
				num = i - 30;
			}
			if (i >= 25 && i < 30)
			{
				type = 5;
				num = i - 25;
			}
			if (i >= 20 && i < 25)
			{
				type = 4;
				num = i - 20;
			}
			if (i >= 15 && i < 20)
			{
				type = 3;
				num = i - 15;
			}
			if (i >= 10 && i < 15)
			{
				type = 2;
				num = i - 10;
			}
			if (i >= 5 && i < 10)
			{
				type = 1;
				num = i - 5;
			}
			if (i >= 0 && i < 5)
			{
				type = 0;
				num = i;
			}

			if (num == 0) count = 1;
			if (num == 1) count = 10;
			if (num == 2) count = 20;
			if (num == 3) count = 30;
			if (num == 4) count = 99;

			if (count <= 0)
				return false;

			this->JewelBankWithDrawSend(type, count);
			gInterface.Data[eJewelBank_WITHDRAW + i].EventTick = GetTickCount();
		}
	}
	return false;
}

void CCustomJewelBank::JewelBankWithDrawSend(int type, int count)
{
	if ((GetTickCount() - this->StatusTick) < 400)
	{
		return;
	}

	if ((GetTickCount() - gInterface.Data[eJewelBank_MAIN].EventTick) < 400)
	{
		return;
	}

	if (type < 0 || count < 0)
	{
		return;
	}

	this->StatusTick = GetTickCount();

	//this->JewelEnable = false;

	PSBMSG_JEWELBANKWITHDRAW_SEND pMsg;

	pMsg.type = type;

	pMsg.count = count;

	pMsg.header.set(0xF3, 0xF6, sizeof(pMsg));

	DataSend((BYTE*)&pMsg, pMsg.header.size);
}