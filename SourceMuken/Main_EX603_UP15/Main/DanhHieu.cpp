#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "DanhHieu.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "CustomMessage.h"
#include "Defines.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "Interface.h"
#include "User.h"
#include "Protocol.h"
#include "Config.h"
#include "PrintPlayer.h"
#include "SItemOption.h"
#include "Central.h"
#include "CustomFont.h"

#if(DANH_HIEU_NEW == 1)
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_DANH_HIEU G_BEXO_DANH_HIEU;
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#define MAX_TRANG_DANH_HIEU    5  // OK

int ImgTagExDanhHieu1 = 90101; //Rank Dynamic
int ImgTagExDanhHieu2 = 90102; //Rank Dynamic
int ImgTagExDanhHieu3 = 90103; //Rank Dynamic
int ImgTagExDanhHieu4 = 90104; //Rank Dynamic
int ImgTagExDanhHieu5 = 90105; //Rank Dynamic
int ImgTagExDanhHieu6 = 90106; //Rank Dynamic
int ImgTagExDanhHieu7 = 90107; //Rank Dynamic
int ImgTagExDanhHieu8 = 90108; //Rank Dynamic
int ImgTagExDanhHieu9 = 90109; //Rank Dynamic
int ImgTagExDanhHieu10 = 90110; //Rank Dynamic
int ImgTagExDanhHieu11 = 90111; //Rank Dynamic
int ImgTagExDanhHieu12 = 90112; //Rank Dynamic
int ImgTagExDanhHieu13 = 90113; //Rank Dynamic
int ImgTagExDanhHieu14 = 90114; //Rank Dynamic
int ImgTagExDanhHieu15 = 90115; //Rank Dynamic
int ImgTagExDanhHieu16 = 90116; //Rank Dynamic
int ImgTagExDanhHieu17 = 90117; //Rank Dynamic
int ImgTagExDanhHieu18 = 90118; //Rank Dynamic
int ImgTagExDanhHieu19 = 90119; //Rank Dynamic
int ImgTagExDanhHieu20 = 90120; //Rank Dynamic
int ImgTagExDanhHieu21 = 90121; //Rank Dynamic
int ImgTagExDanhHieu22 = 90122; //Rank Dynamic
int ImgTagExDanhHieu23 = 90123; //Rank Dynamic
int ImgTagExDanhHieu24 = 90124; //Rank Dynamic
int ImgTagExDanhHieu25 = 90125; //Rank Dynamic
int ImgTagExDanhHieu26 = 90126; //Rank Dynamic
int ImgTagExDanhHieu27 = 90127; //Rank Dynamic
int ImgTagExDanhHieu28 = 90128; //Rank Dynamic
int ImgTagExDanhHieu29 = 90129; //Rank Dynamic
int ImgTagExDanhHieu30 = 90130; //Rank Dynamic
int ImgTagExDanhHieu31 = 90131; //Rank Dynamic
int ImgTagExDanhHieu32 = 90132; //Rank Dynamic
int ImgTagExDanhHieu33 = 90133; //Rank Dynamic
int ImgTagExDanhHieu34 = 90134; //Rank Dynamic
int ImgTagExDanhHieu35 = 90135; //Rank Dynamic
int ImgTagExDanhHieu36 = 90136; //Rank Dynamic
int ImgTagExDanhHieu37 = 90137; //Rank Dynamic
int ImgTagExDanhHieu38 = 90138; //Rank Dynamic
int ImgTagExDanhHieu39 = 90139; //Rank Dynamic
int ImgTagExDanhHieu40 = 90140; //Rank Dynamic
int ImgTagExDanhHieu41 = 90141; //Rank Dynamic
int ImgTagExDanhHieu42 = 90142; //Rank Dynamic
int ImgTagExDanhHieu43 = 90143; //Rank Dynamic
int ImgTagExDanhHieu44 = 90144; //Rank Dynamic
int ImgTagExDanhHieu45 = 90145; //Rank Dynamic
int ImgTagExDanhHieu46 = 90146; //Rank Dynamic
int ImgTagExDanhHieu47 = 90147; //Rank Dynamic
int ImgTagExDanhHieu48 = 90148; //Rank Dynamic
int ImgTagExDanhHieu49 = 90149; //Rank Dynamic
int ImgTagExDanhHieu50 = 90150; //Rank Dynamic
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_DANH_HIEU::BEXO_DANH_HIEU()
{
	TRANG_DANH_HIEU = 1;
	//--------------------------------------------------------------
	HIENTHIDANH_HIEU = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_DANH_HIEU::DRAW_DANH_HIEU()
{
	DRAW_WINDOW_DANH_HIEU();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_DANH_HIEU::BEXO_CLICK_TRANG_DANH_HIEU(DWORD ClickMouse)
{
	if (!gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow)
	{
		return;
	}
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - ClickTick);
	if (gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow && gInterface.IsWorkZone(eDANH_HIEU1))
	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			gInterface.Data[eDANH_HIEU1].OnClick = true;
			return;
		}
		pSetCursorFocus = false;
		gInterface.Data[eDANH_HIEU1].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		if (1 < TRANG_DANH_HIEU && TRANG_DANH_HIEU <= MAX_TRANG_DANH_HIEU)
		{
			TRANG_DANH_HIEU--;
		}
		ClickTick = GetTickCount();
	}
	if (gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow && gInterface.IsWorkZone(eDANH_HIEU2))

	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			gInterface.Data[eDANH_HIEU2].OnClick = true;
			return;
		}
		pSetCursorFocus = false;
		gInterface.Data[eDANH_HIEU2].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		if (1 <= TRANG_DANH_HIEU && TRANG_DANH_HIEU < MAX_TRANG_DANH_HIEU)
		{
			TRANG_DANH_HIEU++;
		}
		ClickTick = GetTickCount();
	}
	if (TRANG_DANH_HIEU < 1)
	{
		TRANG_DANH_HIEU = 1;
	}
	if (TRANG_DANH_HIEU > TRANG_DANH_HIEU)
	{
		TRANG_DANH_HIEU = TRANG_DANH_HIEU;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void BEXO_DANH_HIEU::DRAW_WINDOW_DANH_HIEU()
{

	if (gInterface.CheckWindow(CashShop)
		|| gInterface.CheckWindow(SkillTree)
		|| gInterface.CheckWindow(FullMap)
		|| gInterface.CheckWindow(MoveList)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(Party)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ExpandWarehouse)
		)
	{
		G_BEXO_DANH_HIEU.CLOSE_WINDOW_DANH_HIEU();

	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (!gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow)
	{
		return;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType <= 4)
	{
		pDrawGUFULL(37899999, StartX + 80, StartY + 30, 470.0f, 370.0f, 0, 0, 1, 1, 1, 1, 0.0);

		gCItemSetOption.ItemTooltipS15(StartX + 91, StartY + 79, 190, 100, 0.0, 0);
		gInterface.DrawFormat(eShinyGreen, StartX + 91 + 80, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 85, 210, 1, "•Hướng Dẫn•");

		gCItemSetOption.ItemTooltipS15(StartX + 91, StartY + 79 + 100, 210, 210, 0.0, 0);

		gInterface.DrawFormat(eShinyGreen, StartX + 91 + 65, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 85 + 100, 210, 1, "•Thông Tin Danh Hiệu•");

		gInterface.DrawFormat(eSocket, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 200, 210, 1, "•Mỗi Cấp Được Cộng :");

		gCItemSetOption.ItemTooltipS15(StartX + 91 + 190, StartY + 79, 255, 310, 0.0, 0);

	}
	gCItemSetOption.ItemTooltipS15(StartX + 291, StartY + 95, 110, 50, 0.0, 0);

	gCItemSetOption.ItemTooltipS15(StartX + 291, StartY + 150, 110, 50, 0.0, 0);

	gCItemSetOption.ItemTooltipS15(StartX + 291, StartY + 205, 110, 50, 0.0, 0);

	gCItemSetOption.ItemTooltipS15(StartX + 291, StartY + 260, 110, 50, 0.0, 0);

	gCItemSetOption.ItemTooltipS15(StartX + 291, StartY + 315, 110, 50, 0.0, 0);
	//------------------------------------------------------------------------------------------------------
	gCItemSetOption.ItemTooltipS15(StartX + 291 + 120, StartY + 95, 110, 50, 0.0, 0);

	gCItemSetOption.ItemTooltipS15(StartX + 291 + 120, StartY + 150, 110, 50, 0.0, 0);

	gCItemSetOption.ItemTooltipS15(StartX + 291 + 120, StartY + 205, 110, 50, 0.0, 0);

	gCItemSetOption.ItemTooltipS15(StartX + 291 + 120, StartY + 260, 110, 50, 0.0, 0);

	gCItemSetOption.ItemTooltipS15(StartX + 291 + 120, StartY + 315, 110, 50, 0.0, 0);

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.IsWorkZone(StartX, StartY, StartX + MainWidth, StartY + MainHeight, 0))		// nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;

	gInterface.DrawFormat(eGold, StartX + 280, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 59, 210, 1, "Nâng cấp Danh Hiệu");

	gInterface.DrawGUI(EXBEXO_DANH_HIEU_CLOSE, StartX + 519, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 55);
	RenderBitmap(61529, StartX + 519, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 55, 11, 11, 0.0, 0.0, 0.6535385251, 0.1583384364, 1, 1, 0);
	if (gInterface.IsWorkZone(EXBEXO_DANH_HIEU_CLOSE))
	{
		DWORD Color = eGray100;
		if (gInterface.Data[EXBEXO_DANH_HIEU_CLOSE].OnClick)
		{
			Color = eGray150;
			PlayBuffer(25, 0, 0);
		}

		gInterface.DrawColoredGUI(EXBEXO_DANH_HIEU_CLOSE, gInterface.Data[EXBEXO_DANH_HIEU_CLOSE].X, gInterface.Data[EXBEXO_DANH_HIEU_CLOSE].Y, Color);
	}

	gInterface.DrawGUI(eDANH_HIEU1, StartX + 291 + 65, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 366);

	if (gInterface.IsWorkZone(eDANH_HIEU1))
	{
		DWORD Color = eGray100;
		if (gInterface.Data[eDANH_HIEU1].OnClick)
		{
			Color = eGray150;
			PlayBuffer(25, 0, 0);
		}

		gInterface.DrawColoredGUI(eDANH_HIEU1, gInterface.Data[eDANH_HIEU1].X, gInterface.Data[eDANH_HIEU1].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eDANH_HIEU2, StartX + 291 + 150, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 366);

	if (gInterface.IsWorkZone(eDANH_HIEU2))
	{
		DWORD Color = eGray100;
		if (gInterface.Data[eDANH_HIEU2].OnClick)
		{
			Color = eGray150;
			PlayBuffer(25, 0, 0);
		}

		gInterface.DrawColoredGUI(eDANH_HIEU2, gInterface.Data[eDANH_HIEU2].X, gInterface.Data[eDANH_HIEU2].Y, Color);
	}

	gInterface.DrawFormat(eGold, StartX + 291 + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 373, 210, 1, "Trang : %d", TRANG_DANH_HIEU);

	gInterface.DrawGUI(EXBEXO_DANH_HIEU_NANG_CAP, StartX + 135, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 341);
	gInterface.DrawFormat(eGold, StartX + 175, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 351, 210, 1, "Nâng Cấp");

	if (gInterface.IsWorkZone(EXBEXO_DANH_HIEU_NANG_CAP))
	{
		DWORD Color = eGray100;
		if (gInterface.Data[EXBEXO_DANH_HIEU_NANG_CAP].OnClick)
		{
			Color = eGray150;
			PlayBuffer(25, 0, 0);
		}

		gInterface.DrawColoredGUI(EXBEXO_DANH_HIEU_NANG_CAP, gInterface.Data[EXBEXO_DANH_HIEU_NANG_CAP].X, gInterface.Data[EXBEXO_DANH_HIEU_NANG_CAP].Y, Color);
	}

	gInterface.DrawFormat(eWhite, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gConfig.TextVN_DanhHieu[0]);


	//---- wcoin nâng cấp

	int v1 = gObjUser.DANH_HIEU % 10;
	int v2 = (gObjUser.DANH_HIEU - (v1)) / 10;

	gInterface.DrawFormat(eYellow, StartX + 145, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gConfig.TextVN_DanhHieu[1], gObjUser.rCoint);
	gInterface.DrawFormat(eYellow, StartX + 145, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 210, 1, ": %d", gObjUser.rCount);

	gInterface.DrawItem2(StartX + 135, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 130, 0, 0, GET_ITEM(gObjUser.rType, gObjUser.rIndex), 0, 1, 0, 0);


	gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 220, 300, 1, gConfig.TextVN_DanhHieu[6], gObjUser.SatThuong);
	gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 235, 300, 1, gConfig.TextVN_DanhHieu[7], gObjUser.SatThuongX2);
	gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 300, 1, gConfig.TextVN_DanhHieu[8], gObjUser.PhongThu);
	gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 265, 300, 1, gConfig.TextVN_DanhHieu[9], gObjUser.HP);
	gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 280, 300, 1, gConfig.TextVN_DanhHieu[10], gObjUser.SD);
	gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 295, 300, 1, gConfig.TextVN_DanhHieu[11], gObjUser.GST);



	gInterface.DrawFormat(eSocket, StartX + 215, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gConfig.TextVN_DanhHieu[2]);

	////-----------------------------------------------------------------------------------------------------------------------------------------------------
	switch (TRANG_DANH_HIEU)
	{
	case 1:

		if (v2 >= 1)
		{
			pDrawMapObject(531145, 1, -135, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 2)
		{
			pDrawMapObject(531145, 1, -75, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 3)
		{
			pDrawMapObject(531145, 1, -20, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);

		}


		if (v2 >= 4)
		{
			pDrawMapObject(531145, 1, 37, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 5)
		{
			pDrawMapObject(531145, 1, 90, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);

		}


		if (v2 >= 6)
		{
			pDrawMapObject(531145, 125, -135, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 7)
		{
			pDrawMapObject(531145, 125, -75, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 8)
		{
			pDrawMapObject(531145, 125, -20, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 9)
		{
			pDrawMapObject(531145, 125, 37, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 10)
		{
			pDrawMapObject(531145, 125, 90, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		for (int zI = 0; zI < 5; zI++)
		{

			RenderBitmap(ImgTagExDanhHieu1 + zI, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 95 + 55 * zI, 146, 75, 0, 0, 1, 1, 1, 1, v2 == (zI + 1) ? 0.0 : 0.35);

			RenderBitmap(ImgTagExDanhHieu6 + zI, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 95 + 55 * zI, 146, 75, 0, 0, 1, 1, 1, 1, v2 == (zI + 6) ? 0.0 : 0.35);
		}

		if (v2 < 1)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 1)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 2)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 3)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 4)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 5)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 6)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 7)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 8)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 9)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		break;
	case 2:
		if (v2 >= 11)
		{
			pDrawMapObject(531145, 1, -135, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 12)
		{
			pDrawMapObject(531145, 1, -75, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 13)
		{
			pDrawMapObject(531145, 1, -20, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);

		}


		if (v2 >= 14)
		{
			pDrawMapObject(531145, 1, 37, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 15)
		{
			pDrawMapObject(531145, 1, 90, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);

		}


		if (v2 >= 16)
		{
			pDrawMapObject(531145, 125, -135, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 17)
		{
			pDrawMapObject(531145, 125, -75, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 18)
		{
			pDrawMapObject(531145, 125, -20, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 19)
		{
			pDrawMapObject(531145, 125, 37, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 20)
		{
			pDrawMapObject(531145, 125, 90, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		for (int zI = 0; zI < 5; zI++)
		{

			RenderBitmap(ImgTagExDanhHieu11 + zI, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 95 + 55 * zI, 146, 75, 0, 0, 1, 1, 1, 1, v2 == (zI + 11) ? 0.0 : 0.35);

			RenderBitmap(ImgTagExDanhHieu16 + zI, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 95 + 55 * zI, 146, 75, 0, 0, 1, 1, 1, 1, v2 == (zI + 16) ? 0.0 : 0.35);
		}

		if (v2 == 10)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 11)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 12)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 13)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 14)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 15)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 16)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 17)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 18)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 19)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		break;
	case 3:
		if (v2 >= 21)
		{
			pDrawMapObject(531145, 1, -135, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 22)
		{
			pDrawMapObject(531145, 1, -75, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 23)
		{
			pDrawMapObject(531145, 1, -20, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);

		}


		if (v2 >= 24)
		{
			pDrawMapObject(531145, 1, 37, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 25)
		{
			pDrawMapObject(531145, 1, 90, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);

		}


		if (v2 >= 26)
		{
			pDrawMapObject(531145, 125, -135, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 27)
		{
			pDrawMapObject(531145, 125, -75, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 28)
		{
			pDrawMapObject(531145, 125, -20, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 29)
		{
			pDrawMapObject(531145, 125, 37, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 30)
		{
			pDrawMapObject(531145, 125, 90, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		for (int zI = 0; zI < 5; zI++)
		{

			RenderBitmap(ImgTagExDanhHieu21 + zI, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 95 + 55 * zI, 146, 75, 0, 0, 1, 1, 1, 1, v2 == (zI + 21) ? 0.0 : 0.35);

			RenderBitmap(ImgTagExDanhHieu26 + zI, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 95 + 55 * zI, 146, 75, 0, 0, 1, 1, 1, 1, v2 == (zI + 26) ? 0.0 : 0.35);
		}

		if (v2 == 20)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 21)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 22)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 23)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 24)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 25)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 26)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 27)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 28)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 29)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		break;
	case 4:
		if (v2 >= 31)
		{
			pDrawMapObject(531145, 1, -135, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 32)
		{
			pDrawMapObject(531145, 1, -75, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 33)
		{
			pDrawMapObject(531145, 1, -20, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);

		}


		if (v2 >= 34)
		{
			pDrawMapObject(531145, 1, 37, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 35)
		{
			pDrawMapObject(531145, 1, 90, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);

		}


		if (v2 >= 36)
		{
			pDrawMapObject(531145, 125, -135, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 37)
		{
			pDrawMapObject(531145, 125, -75, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 38)
		{
			pDrawMapObject(531145, 125, -20, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 39)
		{
			pDrawMapObject(531145, 125, 37, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 40)
		{
			pDrawMapObject(531145, 125, 90, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		for (int zI = 0; zI < 5; zI++)
		{

			RenderBitmap(ImgTagExDanhHieu31 + zI, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 95 + 55 * zI, 146, 75, 0, 0, 1, 1, 1, 1, v2 == (zI + 31) ? 0.0 : 0.35);

			RenderBitmap(ImgTagExDanhHieu36 + zI, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 95 + 55 * zI, 146, 75, 0, 0, 1, 1, 1, 1, v2 == (zI + 36) ? 0.0 : 0.35);
		}

		if (v2 == 30)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 31)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 32)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 33)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 34)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 35)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 36)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 37)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 38)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 39)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		break;
	case 5:


		if (v2 >= 41)
		{
			pDrawMapObject(531145, 1, -135, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 42)
		{
			pDrawMapObject(531145, 1, -75, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 43)
		{
			pDrawMapObject(531145, 1, -20, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);

		}


		if (v2 >= 44)
		{
			pDrawMapObject(531145, 1, 37, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 45)
		{
			pDrawMapObject(531145, 1, 90, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);

		}


		if (v2 >= 46)
		{
			pDrawMapObject(531145, 125, -135, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 47)
		{
			pDrawMapObject(531145, 125, -75, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 48)
		{
			pDrawMapObject(531145, 125, -20, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 49)
		{
			pDrawMapObject(531145, 125, 37, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		if (v2 >= 50)
		{
			pDrawMapObject(531145, 125, 90, 185, 135, 0, 0, 0, 0, 0, 33, 1.0, 1.0, 0);
		}


		for (int zI = 0; zI < 5; zI++)
		{

			RenderBitmap(ImgTagExDanhHieu41 + zI, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 95 + 55 * zI, 146, 75, 0, 0, 1, 1, 1, 1, v2 == (zI + 41) ? 0.0 : 0.35);

			RenderBitmap(ImgTagExDanhHieu46 + zI, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 95 + 55 * zI, 146, 75, 0, 0, 1, 1, 1, 1, v2 == (zI + 46) ? 0.0 : 0.35);
		}

		if (v2 == 40)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 41)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 42)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 43)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 44)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 45)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 125, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 46)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 175, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 47)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 225, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 48)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 275, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		if (v2 == 49)
		{
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0xcccccc80, 100, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0x0, 0x22ff2280, 10 * v1, 7, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, StartX + 294 + 120, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 325, 0xffffffff, 0x0, 100, 15, 3, "%d%%", v1 * 10);
		}
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	default:
		break;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_DANH_HIEU::MAIN_DANH_HIEU(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	this->CLOSE_DANH_HIEU(Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	// TRANG 1
	if (gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow && gInterface.IsWorkZone(EXBEXO_DANH_HIEU_NANG_CAP))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_DANH_HIEU_NANG_CAP].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[EXBEXO_DANH_HIEU_NANG_CAP].OnClick = true;

			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[EXBEXO_DANH_HIEU_NANG_CAP].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[EXBEXO_DANH_HIEU_NANG_CAP].EventTick = GetTickCount();

		this->BUY_DANH_HIEU(1);

		if (gObjUser.DANH_HIEU == 99)
		{
			TRANG_DANH_HIEU = 2;
		}

		if (gObjUser.DANH_HIEU == 199)
		{
			TRANG_DANH_HIEU = 3;
		}

		if (gObjUser.DANH_HIEU == 299)
		{
			TRANG_DANH_HIEU = 4;
		}

		if (gObjUser.DANH_HIEU == 399)
		{
			TRANG_DANH_HIEU = 5;
		}

	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_DANH_HIEU::CLOSE_DANH_HIEU(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_DANH_HIEU_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_DANH_HIEU_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_DANH_HIEU_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_DANH_HIEU_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_DANH_HIEU_CLOSE].EventTick = GetTickCount();
	G_BEXO_DANH_HIEU.CLOSE_WINDOW_DANH_HIEU();
	// ----
	return false;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_DANH_HIEU::BUY_DANH_HIEU(int Number)
{
	BUY_DANH_HIEU_REQ pMsg;
	pMsg.h.set(0xFC, 0x03, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#endif