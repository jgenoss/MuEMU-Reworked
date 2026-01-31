#include "stdafx.h"
#include "CustomLuckySpin.h"
#include "Interface.h"
#include "Defines.h"
#include "Item.h"
#include "User.h"
#include "CustomWing.h"
#include "Protect.h"
#include "Protocol.h"
#include "Config.h"
#include "SItemOption.h"

#if(VONGQUAY_NEW)
CLuckySpin gLuckySpin;

CLuckySpin::CLuckySpin()
{
	this->StartRoll = 0;
	this->RollNumber = -1;
	this->itemdata.clear();
}

CLuckySpin::~CLuckySpin()
{
}

void CLuckySpin::SwitchLuckySpinWindowState()
{
	(gInterface.Data[eLuckySpin].OnShow == true) ? gInterface.Data[eLuckySpin].Close() : this->CGLuckySpinSend();
}

void CLuckySpin::GCLuckySpinInit(GC_LuckySpinInit* aRecv)
{
	if (aRecv->result)
	{
		gInterface.Data[eLuckySpin].Open();
	}
}

void CLuckySpin::GCItemSend(GC_LuckySpin_Data* aRecv)
{
	LuckySpin_Data pData;
	pData.ItemType = aRecv->ItemType;
	pData.ItemIndex = aRecv->ItemIndex;
	pData.ItemLevel = aRecv->ItemLevel;
	pData.ItemExc = aRecv->ItemExc;
	this->WCoinC = aRecv->WCoinC;
	this->itemdata.push_back(pData);
}

void CLuckySpin::CGLuckySpinSend()
{
	CG_LUCKYSPIN_REQ pRequest;
	pRequest.h.set(0xFC, 0x17, sizeof(pRequest));
	DataSend((LPBYTE)&pRequest, pRequest.h.size);
}

void CLuckySpin::LuckySpinData(GC_LuckySpinUpdateData * aRecv)
{
	this->StartRoll = 0;
	this->RollNumber = aRecv->RollNumber;
}


void CLuckySpin::Draw()
{
	if (gInterface.CheckWindow(CashShop) ||
		gInterface.CheckWindow(ChaosBox) ||
		gInterface.CheckWindow(FullMap) ||
		gInterface.CheckWindow(MoveList) ||
		gInterface.CheckWindow(Party) ||
		gInterface.CheckWindow(Trade) ||
		gInterface.CheckWindow(ExpandInventory) ||
		gInterface.CheckWindow(Store) ||
		gInterface.CheckWindow(Character) ||

		gInterface.CheckWindow(SkillTree))
		return;

	if (!gInterface.Data[eLuckySpin].OnShow)
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 80.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);

	//---------------------------------------------------------------------------------------//
	if (gInterface.IsWorkZone(eLuckySpin)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//---------------------------------------------------------------------------------------//
	//pDrawMessage("", 0); // Không Cho Hiện Thông Báo Trên Màn Hình
	//---------------------------------------------------------------------------------------//
	//gInterface.DrawGUI(eLuckySpin, StartX - 62, StartY - 15);
	gCItemSetOption.ItemTooltipS15(StartX - 55, gInterface.Data[eLuckySpin].Y + 60, 300, 290, 0.0, 0);

	//--------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eWhite, 200, 71, 210, 3, "Vòng Quay May Mắn"); // "Vòng Quay May Mắn"
	//--------------------------------------------------------------------------------------------
	//
	gCItemSetOption.ItemTooltipS15(StartX - 45, gInterface.Data[eLuckySpin].Y + 100, 70, 57, 0.0, 0);
	gCItemSetOption.ItemTooltipS15(StartX + 25, gInterface.Data[eLuckySpin].Y + 100, 70, 57, 0.0, 0);
	gCItemSetOption.ItemTooltipS15(StartX + 95, gInterface.Data[eLuckySpin].Y + 100, 70, 57, 0.0, 0);
	gCItemSetOption.ItemTooltipS15(StartX + 165, gInterface.Data[eLuckySpin].Y + 100, 70, 57, 0.0, 0);

	gCItemSetOption.ItemTooltipS15(StartX + 165, gInterface.Data[eLuckySpin].Y + 157, 70, 57, 0.0, 0);
	gCItemSetOption.ItemTooltipS15(StartX + 165, gInterface.Data[eLuckySpin].Y + 214, 70, 57, 0.0, 0);

	gCItemSetOption.ItemTooltipS15(StartX - 45, gInterface.Data[eLuckySpin].Y + 271, 70, 57, 0.0, 0);
	gCItemSetOption.ItemTooltipS15(StartX + 25, gInterface.Data[eLuckySpin].Y + 271, 70, 57, 0.0, 0);
	gCItemSetOption.ItemTooltipS15(StartX + 95, gInterface.Data[eLuckySpin].Y + 271, 70, 57, 0.0, 0);
	gCItemSetOption.ItemTooltipS15(StartX + 165, gInterface.Data[eLuckySpin].Y + 271, 70, 57, 0.0, 0);

	gCItemSetOption.ItemTooltipS15(StartX - 45, gInterface.Data[eLuckySpin].Y + 157, 70, 57, 0.0, 0);
	gCItemSetOption.ItemTooltipS15(StartX - 45, gInterface.Data[eLuckySpin].Y + 214, 70, 57, 0.0, 0);

	if (this->StartRoll >= 1)
	{
		pSetBlend(true);
		glColor4f(1.0, 1.0, 0.0, 0.3);
		int ran = rand() % 11;
		pSetBlend(true);
		switch (ran)
		{
		case 0:
			pDrawBarForm(160, 100, 70, 57, 0, 0);
			break;
		case 1:
			pDrawBarForm(230, 100, 70, 57, 0, 0);
			break;
		case 2:
			pDrawBarForm(300, 100, 70, 57, 0, 0);
			break;
		case 3:
			pDrawBarForm(370, 100, 70, 57, 0, 0);
			break;
		case 4:
			pDrawBarForm(370, 157, 70, 57, 0, 0);
			break;
		case 5:
			pDrawBarForm(370, 214, 70, 57, 0, 0);
			break;
		case 6:
			pDrawBarForm(370, 271, 70, 57, 0, 0);
			break;
		case 7:
			pDrawBarForm(300, 271, 70, 57, 0, 0);
			break;
		case 8:
			pDrawBarForm(230, 271, 70, 57, 0, 0);
			break;
		case 9:
			pDrawBarForm(160, 271, 70, 57, 0, 0);
			break;
		case 10:
			pDrawBarForm(160, 157, 70, 57, 0, 0);
			break;
		case 11:
			pDrawBarForm(160, 214, 70, 57, 0, 0);
			break;
			pGLSwitchBlend();
			glColor3f(1.0, 1.0, 1.0);
		}
	}

	if (this->RollNumber >= 0)
	{
		pSetBlend(true);
		glColor4f(1.0, 1.0, 0.0, 0.3);
		switch (RollNumber)
		{
		case 0:
			pDrawBarForm(160, 100, 70, 57, 0, 0);
			break;
		case 1:
			pDrawBarForm(230, 100, 70, 57, 0, 0);
			break;
		case 2:
			pDrawBarForm(300, 100, 70, 57, 0, 0);
			break;
		case 3:
			pDrawBarForm(370, 100, 70, 57, 0, 0);
			break;
		case 4:
			pDrawBarForm(370, 157, 70, 57, 0, 0);
			break;
		case 5:
			pDrawBarForm(370, 214, 70, 57, 0, 0);
			break;
		case 6:
			pDrawBarForm(370, 271, 70, 57, 0, 0);
			break;
		case 7:
			pDrawBarForm(300, 271, 70, 57, 0, 0);
			break;
		case 8:
			pDrawBarForm(230, 271, 70, 57, 0, 0);
			break;
		case 9:
			pDrawBarForm(160, 271, 70, 57, 0, 0);
			break;
		case 10:
			pDrawBarForm(160, 157, 70, 57, 0, 0);
			break;
		case 11:
			pDrawBarForm(160, 214, 70, 57, 0, 0);
			break;
			pGLSwitchBlend();
			glColor3f(1.0, 1.0, 1.0);
		}
	}

	gInterface.DrawItem2(170, 100, 70, 50, ITEM(this->itemdata[0].ItemType, this->itemdata[0].ItemIndex), SET_ITEMOPT_LEVEL(this->itemdata[0].ItemLevel), this->itemdata[0].ItemExc, 0, 0);
	gInterface.DrawItem2(240, 100, 65, 47, ITEM(this->itemdata[1].ItemType, this->itemdata[1].ItemIndex), SET_ITEMOPT_LEVEL(this->itemdata[1].ItemLevel), this->itemdata[1].ItemExc, 0, 0);
	gInterface.DrawItem2(310, 100, 65, 47, ITEM(this->itemdata[2].ItemType, this->itemdata[2].ItemIndex), SET_ITEMOPT_LEVEL(this->itemdata[2].ItemLevel), this->itemdata[2].ItemExc, 0, 0);
	gInterface.DrawItem2(380, 100, 65, 50, ITEM(this->itemdata[3].ItemType, this->itemdata[3].ItemIndex), SET_ITEMOPT_LEVEL(this->itemdata[3].ItemLevel), this->itemdata[3].ItemExc, 0, 0);
	gInterface.DrawItem2(380, 157, 65, 50, ITEM(this->itemdata[4].ItemType, this->itemdata[4].ItemIndex), SET_ITEMOPT_LEVEL(this->itemdata[4].ItemLevel), this->itemdata[4].ItemExc, 0, 0);
	gInterface.DrawItem2(380, 214, 63, 50, ITEM(this->itemdata[5].ItemType, this->itemdata[5].ItemIndex), SET_ITEMOPT_LEVEL(this->itemdata[5].ItemLevel), this->itemdata[5].ItemExc, 0, 0);
	gInterface.DrawItem2(380, 271, 70, 45, ITEM(this->itemdata[6].ItemType, this->itemdata[6].ItemIndex), SET_ITEMOPT_LEVEL(this->itemdata[6].ItemLevel), this->itemdata[6].ItemExc, 0, 0);
	gInterface.DrawItem2(310, 271, 70, 45, ITEM(this->itemdata[7].ItemType, this->itemdata[7].ItemIndex), SET_ITEMOPT_LEVEL(this->itemdata[7].ItemLevel), this->itemdata[7].ItemExc, 0, 0);
	gInterface.DrawItem2(240, 271, 70, 45, ITEM(this->itemdata[8].ItemType, this->itemdata[8].ItemIndex), SET_ITEMOPT_LEVEL(this->itemdata[8].ItemLevel), this->itemdata[8].ItemExc, 0, 0);
	gInterface.DrawItem2(170, 271, 70, 45, ITEM(this->itemdata[9].ItemType, this->itemdata[9].ItemIndex), SET_ITEMOPT_LEVEL(this->itemdata[9].ItemLevel), this->itemdata[9].ItemExc, 0, 0);
	gInterface.DrawItem2(170, 157, 70, 50, ITEM(this->itemdata[10].ItemType, this->itemdata[10].ItemIndex), SET_ITEMOPT_LEVEL(this->itemdata[10].ItemLevel), this->itemdata[10].ItemExc, 0, 0);
	gInterface.DrawItem2(170, 214, 70, 50, ITEM(this->itemdata[11].ItemType, this->itemdata[11].ItemIndex), SET_ITEMOPT_LEVEL(this->itemdata[11].ItemLevel), this->itemdata[11].ItemExc, 0, 0);
	//--------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eWhite, 200, 170, 210, 3,"Phần Thưởng"); // "Phần thưởng"
	//--------------------------------------------------------------------------------------------
	//
	// item nhận thưởng
	if (this->RollNumber >= 0)
	{
		gInterface.DrawItem2(280, 170, 50, 50, ITEM(this->itemdata[RollNumber].ItemType, this->itemdata[RollNumber].ItemIndex), SET_ITEMOPT_LEVEL(this->itemdata[RollNumber].ItemLevel), this->itemdata[RollNumber].ItemExc, 0, 0);
	}
	//
	gInterface.DrawGUI(eLuckySpinRoll, StartX + 45, StartY + 160);
	if (gInterface.IsWorkZone(eLuckySpinRoll))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eLuckySpinRoll, gInterface.Data[eLuckySpinRoll].X, gInterface.Data[eLuckySpinRoll].Y, Color);
	}
	//--------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eYellow, 200, 222, 210, 3, "Yêu Cầu %d WCoinC /Lượt", this->WCoinC); // "Giá"
	//--------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eYellow, 186, 249, 210, 3, "Click để QUAY"); // "Quay"
	//--------------------------------------------------------------------------------------------
	//
	gInterface.DrawGUI(eLuckySpinClose, StartX + 215, StartY - 23);

	if (gInterface.IsWorkZone(eLuckySpinClose))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eLuckySpinClose, gInterface.Data[eLuckySpinClose].X, gInterface.Data[eLuckySpinClose].Y, Color);
	}

}

void CLuckySpin::EventWindow_Main(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if (!gInterface.Data[eLuckySpin].OnShow)
	{
		return;
	}

	if (gInterface.IsWorkZone(eLuckySpinRoll))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[eLuckySpinRoll].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eLuckySpinRoll].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		gInterface.Data[eLuckySpinRoll].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 6000)
		{
			return;
		}
		// ----
		gInterface.Data[eLuckySpinRoll].EventTick = GetTickCount();
		//Func
		RollNumber = -1;
		CG_LUCKYSPIN_REQ pRequest;
		pRequest.h.set(0xFC, 0x16, sizeof(pRequest));
		DataSend((LPBYTE)&pRequest, pRequest.h.size);
	}

	if (gInterface.IsWorkZone(eLuckySpinClose))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[eLuckySpinClose].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eLuckySpinClose].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		gInterface.Data[eLuckySpinClose].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[eLuckySpinClose].EventTick = GetTickCount();
		//Func
		this->SwitchLuckySpinWindowState();
	}
}
#endif