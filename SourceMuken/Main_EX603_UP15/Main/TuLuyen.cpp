#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "TuLuyen.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "CustomMessage.h"
#include "Defines.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "Interface.h"
#include "User.h"
#include "Protocol.h"
#include "PrintPlayer.h"
#include "SItemOption.h"
#include "Config.h"


#if(TU_LUYEN_NEW == 1)

//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_TU_LUYEN G_BEXO_TU_LUYEN;
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#define MAX_TRANG_TU_LUYEN    10  // OK

//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_TU_LUYEN::BEXO_TU_LUYEN()
{
	TRANG_TU_LUYEN = 1;
	//--------------------------------------------------------------
	HIENTHITU_LUYEN = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_TU_LUYEN::DRAW_TU_LUYEN()
{
	DRAW_WINDOW_TU_LUYEN();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_TU_LUYEN::BEXO_CLICK_TRANG_TU_LUYEN(DWORD ClickMouse)
{
	if (!gInterface.Data[EXBEXO_TU_LUYEN_MAIN].OnShow)
	{
		return;
	}
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - ClickTick);
	if (gInterface.Data[EXBEXO_TU_LUYEN_MAIN].OnShow && gInterface.IsWorkZone(eTU_LUYEN1))
	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (1 < TRANG_TU_LUYEN && TRANG_TU_LUYEN <= MAX_TRANG_TU_LUYEN)
		{
			TRANG_TU_LUYEN--;
		}
		ClickTick = GetTickCount();
	}
	if (gInterface.Data[EXBEXO_TU_LUYEN_MAIN].OnShow && gInterface.IsWorkZone(eTU_LUYEN2))

	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (1 <= TRANG_TU_LUYEN && TRANG_TU_LUYEN < MAX_TRANG_TU_LUYEN)
		{
			TRANG_TU_LUYEN++;
		}
		ClickTick = GetTickCount();
	}
	if (TRANG_TU_LUYEN < 1)
	{
		TRANG_TU_LUYEN = 1;
	}
	if (TRANG_TU_LUYEN > TRANG_TU_LUYEN)
	{
		TRANG_TU_LUYEN = TRANG_TU_LUYEN;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void BEXO_TU_LUYEN::DRAW_WINDOW_TU_LUYEN()
{

	if (gInterface.CheckWindow(CashShop)
		|| gInterface.CheckWindow(SkillTree)
		|| gInterface.CheckWindow(FullMap)
		|| gInterface.CheckWindow(MoveList)
		|| gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(Party)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ExpandWarehouse))
	{
		return;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (!gInterface.Data[EXBEXO_TU_LUYEN_MAIN].OnShow)
	{
		return;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		pDrawGUFULL(0x0899, StartX + 70, StartY + 50, 900, 550, 0, 0, 1, 1, 1, 1, 0.0); // MENU
	}
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		gCItemSetOption.ItemTooltipS15(StartX + 70, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 50, 495, 300, 0.0, 0);

		gCItemSetOption.ItemTooltipS15(StartX + 95, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 85, 450, 60, 0.0, 0);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.IsWorkZone(StartX, StartY, StartX + MainWidth, StartY + MainHeight)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//pDrawMessage("", 0); // Không Cho Hiện Thông Báo Trên Màn Hình
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eWhite, StartX + 280, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 60, 210, 1, "Nâng cấp Tu Luyện");

	gInterface.DrawFormat(eWhite, StartX + 115, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 90, 210, 1, gConfig.TextVN_TuLuyen[0]);

	//---- wcoin nâng cấp
	if (gInterface.m_TuLuyen == 0)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_01);
	}
	if (gInterface.m_TuLuyen == 1)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_02);
	}
	if (gInterface.m_TuLuyen == 2)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_03);
	}
	if (gInterface.m_TuLuyen == 3)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_04);
	}
	if (gInterface.m_TuLuyen == 4)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_05);
	}
	if (gInterface.m_TuLuyen == 5)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_06);
	}
	if (gInterface.m_TuLuyen == 6)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_07);
	}
	if (gInterface.m_TuLuyen == 7)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_08);
	}
	if (gInterface.m_TuLuyen == 8)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_09);
	}
	if (gInterface.m_TuLuyen == 9)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_10);
	}
	if (gInterface.m_TuLuyen == 10)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_11);
	}
	if (gInterface.m_TuLuyen == 11)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_12);
	}
	if (gInterface.m_TuLuyen == 12)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_13);
	}
	if (gInterface.m_TuLuyen == 13)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_14);
	}
	if (gInterface.m_TuLuyen == 14)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_15);
	}
	if (gInterface.m_TuLuyen == 15)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_16);
	}
	if (gInterface.m_TuLuyen == 16)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_17);
	}
	if (gInterface.m_TuLuyen == 17)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_18);
	}
	if (gInterface.m_TuLuyen == 18)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_19);
	}
	if (gInterface.m_TuLuyen == 19)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_20);
	}
	if (gInterface.m_TuLuyen == 20)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_21);
	}
	if (gInterface.m_TuLuyen == 21)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_22);
	}
	if (gInterface.m_TuLuyen == 22)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_23);
	}
	if (gInterface.m_TuLuyen == 23)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_24);
	}
	if (gInterface.m_TuLuyen == 24)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_25);
	}
	if (gInterface.m_TuLuyen == 25)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_26);
	}
	if (gInterface.m_TuLuyen == 26)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_27);
	}
	if (gInterface.m_TuLuyen == 27)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_28);
	}
	if (gInterface.m_TuLuyen == 28)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_29);
	}
	if (gInterface.m_TuLuyen == 29)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_30);
	}
	if (gInterface.m_TuLuyen == 30)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_31);
	}
	if (gInterface.m_TuLuyen == 31)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_32);
	}
	if (gInterface.m_TuLuyen == 32)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_33);
	}
	if (gInterface.m_TuLuyen == 33)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_34);
	}
	if (gInterface.m_TuLuyen == 34)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_35);
	}
	if (gInterface.m_TuLuyen == 35)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_36);
	}
	if (gInterface.m_TuLuyen == 36)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_37);
	}
	if (gInterface.m_TuLuyen == 37)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_38);
	}
	if (gInterface.m_TuLuyen == 38)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_39);
	}
	if (gInterface.m_TuLuyen == 39)
	{
		gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC_40);
	}
	//----
	gInterface.DrawFormat(eSocket, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 120, 210, 1, gConfig.TextVN_TuLuyen[2]);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_TU_LUYEN_NANG_CAP, StartX + 435, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 100);

	if (gInterface.IsWorkZone(EXBEXO_TU_LUYEN_NANG_CAP))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(EXBEXO_TU_LUYEN_NANG_CAP, gInterface.Data[EXBEXO_TU_LUYEN_NANG_CAP].X, gInterface.Data[EXBEXO_TU_LUYEN_NANG_CAP].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eAncient, StartX + 455, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 110, 210, 1, gConfig.TextVN_TuLuyen[3]);

	gInterface.DrawFormat(eYellow, StartX + 270, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 132, 210, 1, gConfig.TextVN_TuLuyen[4], gInterface.m_TuLuyen);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eTU_LUYEN1, StartX + 70, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210);

	if (gInterface.IsWorkZone(eTU_LUYEN1))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eTU_LUYEN1, gInterface.Data[eTU_LUYEN1].X, gInterface.Data[eTU_LUYEN1].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eTU_LUYEN2, StartX + 535, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210);

	if (gInterface.IsWorkZone(eTU_LUYEN2))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eTU_LUYEN2, gInterface.Data[eTU_LUYEN2].X, gInterface.Data[eTU_LUYEN2].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_TU_LUYEN_CLOSE, StartX + 532, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 52);
	if (gInterface.IsWorkZone(EXBEXO_TU_LUYEN_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(EXBEXO_TU_LUYEN_CLOSE, gInterface.Data[EXBEXO_TU_LUYEN_CLOSE].X, gInterface.Data[EXBEXO_TU_LUYEN_CLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	// Thanh Xanh Coin
	RenderBitmap(0x0897, StartX + 197, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 109, 210, 14, 0, 0, 1, 1, 1, 1, 0.0);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eRed, StartX + 270, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 108, 210, 1, "WCoinC %d", Coin1);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		// Nền đen nằm text
		RenderBitmap(0x0896, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(0x0896, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(0x0896, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(0x0896, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	switch (TRANG_TU_LUYEN) //====================================================================================================================================
	{
		//=============================================================================================================================================================	
	case 1:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 1)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 2)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 3)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 4)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10128, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10129, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10130, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10131, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);

		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[6]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[7]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[8]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[9]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[10]);

		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[11]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[12]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[13]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[14]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[15]);

		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[16]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[17]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[18]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[19]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[20]);

		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[21]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[22]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[23]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[24]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[25]);

		//=============================================================================================================================================================	
		break;
	case 2:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 5)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 6)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 7)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 8)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10132, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10133, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10134, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10135, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[26]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[27]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[28]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[29]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[30]);

		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[31]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[32]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[33]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[34]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[35]);

		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[36]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[37]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[38]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[39]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[40]);

		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[41]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[42]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[43]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[44]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[45]);
		//=============================================================================================================================================================	
		break;
	case 3:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 9)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 10)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 11)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 12)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10136, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10137, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10138, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10139, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[46]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[47]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[48]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[49]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[50]);

		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[51]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[52]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[53]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[54]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[55]);

		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[56]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[57]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[58]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[59]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[60]);

		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[61]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[62]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[63]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[64]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[65]);
		//=============================================================================================================================================================	
		break;
	case 4:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 13)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 14)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 15)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 16)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10140, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10141, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10142, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10143, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[66]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[67]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[68]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[69]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[70]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[71]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[72]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[73]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[74]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[75]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[76]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[77]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[78]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[79]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[80]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[81]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[82]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[83]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[84]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[85]);
		//=============================================================================================================================================================	
		break;
	case 5:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 17)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 18)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 19)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 20)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10144, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10145, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10146, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10147, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[86]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[87]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[88]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[89]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[90]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[91]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[92]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[93]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[94]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[95]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[96]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[97]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[98]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[99]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[100]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[101]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[102]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[103]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[104]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[105]);
		//=============================================================================================================================================================	
		break;
	case 6:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 21)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 22)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 23)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 24)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10148, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10149, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10150, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10151, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[106]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[107]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[108]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[109]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[110]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[111]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[112]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[113]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[114]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[115]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[116]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[117]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[118]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[119]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[120]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[121]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[122]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[123]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[124]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[125]);
		//=============================================================================================================================================================	
		break;
	case 7:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 25)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 26)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 27)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 28)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10152, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10153, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10154, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10155, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[126]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[127]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[128]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[129]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[130]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[131]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[132]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[133]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[134]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[135]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[136]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[137]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[138]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[139]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[140]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[141]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[142]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[143]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[144]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[145]);
		//=============================================================================================================================================================	
		break;
	case 8:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 29)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 30)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 31)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 32)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10156, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10157, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10158, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10159, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[146]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[147]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[148]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[149]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[150]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[151]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[152]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[153]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[154]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[155]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[156]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[157]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[158]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[159]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[160]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[161]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[162]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[163]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[164]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[165]);
		//=============================================================================================================================================================	
		break;
	case 9:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 33)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 34)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 35)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 36)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10160, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10161, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10162, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10163, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[166]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[167]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[168]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[169]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[170]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[171]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[172]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[173]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[174]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[175]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[176]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[177]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[178]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[179]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[180]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[181]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[182]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[183]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[184]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[185]);
		//=============================================================================================================================================================	
		break;
	case 10:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 37)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 38)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 39)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 40)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10164, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10165, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10166, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10167, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[186]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[187]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[188]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[189]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[190]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[191]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[192]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[193]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[194]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[195]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[196]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[197]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[198]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[199]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[200]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[201]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[202]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[203]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[204]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[205]);
		//=============================================================================================================================================================	
		break;
	default:
		break;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_TU_LUYEN::MAIN_TU_LUYEN(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	this->CLOSE_TU_LUYEN(Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	// TRANG 1
	if (gInterface.Data[EXBEXO_TU_LUYEN_MAIN].OnShow && gInterface.IsWorkZone(EXBEXO_TU_LUYEN_NANG_CAP))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_TU_LUYEN_NANG_CAP].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[EXBEXO_TU_LUYEN_NANG_CAP].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[EXBEXO_TU_LUYEN_NANG_CAP].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[EXBEXO_TU_LUYEN_NANG_CAP].EventTick = GetTickCount();

		this->BUY_TU_LUYEN(1);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_TU_LUYEN::CLOSE_TU_LUYEN(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_TU_LUYEN_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_TU_LUYEN_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_TU_LUYEN_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_TU_LUYEN_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_TU_LUYEN_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_TU_LUYEN_CLOSE].EventTick = GetTickCount();
	G_BEXO_TU_LUYEN.CLOSE_WINDOW_TU_LUYEN();
	// ----
	return false;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_TU_LUYEN::BUY_TU_LUYEN(int Number)
{
	BUY_TU_LUYEN_REQ pMsg;
	pMsg.h.set(0xFC, 0x05, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#endif