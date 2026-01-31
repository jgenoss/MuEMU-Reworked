#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "MOCNAP.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "CustomMessage.h"
#include "Defines.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "Interface.h"
#include "User.h"
#include "Protocol.h"
//#include "Other.h"
#include "PrintPlayer.h"
#include "SItemOption.h"
#include "Import.h"
#include "Central.h"
#include "User.h"
#include "Config.h"

#if(MOCNAP == 1)
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_MOCNAP G_BEXO_MOCNAP;
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_MOCNAP::BEXO_MOCNAP()
{
	//--------------------------------------------------------------
	HIENTHIMOCNAP = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void BEXO_MOCNAP::BIND()
{
	gInterface.BindObject(EXBEXO_MOCNAP_MAIN, 31461, 640, 419, -1, -1);  // 31461
	gInterface.BindObject(EXBEXO_MOCNAP_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(MOCNAP1, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP2, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP3, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP4, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP5, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP6, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP7, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP8, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP9, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP10, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP11, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP12, 10099, 30, 20, -1, -1);
	gInterface.BindObject(MOCNAP13, 10099, 30, 20, -1, -1);
}
// ----------------------------------------------------------------------------------------------


void BEXO_MOCNAP::DRAW_MOCNAP()
{
	DRAW_WINDOW_MOCNAP();
}

void BEXO_MOCNAP::DRAW_WINDOW_MOCNAP()
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
	if (!gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow)
	{
		return;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.IsWorkZone(StartX, StartY, StartX + MainWidth, StartY + MainHeight)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	float MainWidthX = 250.0;
	float MainHeightX = 280.0;
	float StartY1 = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeightX / 2);
	float StartX1 = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//RenderBitmap(500001,StartX + 180, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 25, 315, 580, 0, 0, 1, 1, 1, 1, 0.0);
	gCentral.PrintDropBox(StartX1 + 160, StartY1 - 50, MainWidthX + 70, MainHeightX + 100, 0, 0);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_MOCNAP_CLOSE, StartX + 420, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 25);
	if (gInterface.IsWorkZone(EXBEXO_MOCNAP_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(EXBEXO_MOCNAP_CLOSE, gInterface.Data[EXBEXO_MOCNAP_CLOSE].X, gInterface.Data[EXBEXO_MOCNAP_CLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float XMOCNAP = 150;
	gInterface.DrawFormat(eGold, XMOCNAP + 55, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 33, 200, 3, gConfig.HIEPMOCNAP[0]);
	gInterface.DrawFormat(eRed, XMOCNAP + 55, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 47, 200, 3, gConfig.HIEPMOCNAP[67]);
	/// Moc Nap 1
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 60, 200, 15, 0.0, 0);
	//----
	int MocNap1;
	if (gObjUser.MocNapCheck1 > 0)
	{
		MocNap1 = (gObjUser.MOCNAPCOIN * gObjUser.MocNapCheck1) / gObjUser.MocNapCheck1;
		if (MocNap1 > gObjUser.MocNapCheck1)
		{
			MocNap1 = gObjUser.MocNapCheck1;
		}
	}

	float TyLeNap1 = (199.0 * MocNap1) / gObjUser.MocNapCheck1;
	if (TyLeNap1 > 199.0) { TyLeNap1 = 199.0; }
	pDrawGUI(0x0897, 201.0f, 60.0f, TyLeNap1, 14.0f);
	gInterface.DrawFormat(gcolor, XMOCNAP - 70, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 62 + add1, 200, 3, gConfig.HIEPMOCNAP[66], gObjUser.MocNapCheck1);
	if (gObjUser.MOCNAP1 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 62 + add1, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP1 == 0)
	{
		if (gObjUser.MOCNAPCOIN >= gObjUser.MocNapCheck1)
		{
			gInterface.DrawGUI(MOCNAP1, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 57);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 62 + add1, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP1))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP1, gInterface.Data[MOCNAP1].X, gInterface.Data[MOCNAP1].Y, Color);
			}
		}
	}

	gInterface.DrawFormat(eExcellent, XMOCNAP + 200, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 62 + add1, 200, 3, "Chi tiết...");
	if (pCheckMouseOver(XMOCNAP + 290, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 62 + add1, 15, 10) == 1)
	{
		gCItemSetOption.ItemTooltipS15		(XMOCNAP + 340, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 62 + add1, 135, 65, 0.0, 0);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 70 + add1, 300, 1, gConfig.HIEPMOCNAP[1]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 80 + add1, 300, 1, gConfig.HIEPMOCNAP[2]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 90 + add1, 300, 1, gConfig.HIEPMOCNAP[3]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 100 + add1, 300, 1,gConfig.HIEPMOCNAP[4]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 110 + add1, 300, 1,gConfig.HIEPMOCNAP[5]);
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 2
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 85, 200, 15, 0.0, 0);
	//----
	int MocNap2;
	if (gObjUser.MocNapCheck2 > 0)
	{
		MocNap2 = (gObjUser.MOCNAPCOIN * gObjUser.MocNapCheck2) / gObjUser.MocNapCheck2;
		if (MocNap2 > gObjUser.MocNapCheck2)
		{
			MocNap2 = gObjUser.MocNapCheck2;
		}
	}
	float TyLeNap2 = (199.0 * MocNap2) / gObjUser.MocNapCheck2;
	if (TyLeNap2 > 199.0) { TyLeNap2 = 199.0; }
	pDrawGUI(0x0897, 201.0f, 85.0f, TyLeNap2, 14.0f);
	gInterface.DrawFormat(gcolor, XMOCNAP - 70, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 87 + add1, 200, 3, gConfig.HIEPMOCNAP[66], gObjUser.MocNapCheck2);
	//----
	if (gObjUser.MOCNAP2 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 87, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP2 == 0)
	{
		if (gObjUser.MOCNAPCOIN >= gObjUser.MocNapCheck2)
		{
			gInterface.DrawGUI(MOCNAP2, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 82);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 87 + add1, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP2))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP2, gInterface.Data[MOCNAP2].X, gInterface.Data[MOCNAP2].Y, Color);
			}
		}
	}
	gInterface.DrawFormat(eExcellent, XMOCNAP + 200, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 87 + add1, 200, 3, "Chi tiết...");
	if (pCheckMouseOver(XMOCNAP + 290, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 87 + add1, 15, 10) == 1)
	{
		gCItemSetOption.ItemTooltipS15		(XMOCNAP + 340, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 87 + add1, 135, 65, 0.0, 0);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 95 + add1, 300,  1 ,gConfig.HIEPMOCNAP[6]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 105 + add1, 300, 1 ,gConfig.HIEPMOCNAP[7]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 115 + add1, 300, 1 ,gConfig.HIEPMOCNAP[8]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 125 + add1, 300, 1 ,gConfig.HIEPMOCNAP[9]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 135 + add1, 300, 1 ,gConfig.HIEPMOCNAP[10]);
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 3
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 110, 200, 15, 0.0, 0);
	//----
	int MocNap3;
	if (gObjUser.MocNapCheck3 > 0)
	{
		MocNap3 = (gObjUser.MOCNAPCOIN * gObjUser.MocNapCheck3) / gObjUser.MocNapCheck3;
		if (MocNap3 > gObjUser.MocNapCheck3)
		{
			MocNap3 = gObjUser.MocNapCheck3;
		}
	}
	float TyLeNap3 = (199.0 * MocNap3) / gObjUser.MocNapCheck3;
	if (TyLeNap3 > 199.0) { TyLeNap3 = 199.0; }
	pDrawGUI(0x0897, 201.0f, 110.0f, TyLeNap3, 14.0f);
	gInterface.DrawFormat(gcolor, XMOCNAP - 70, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 112 + add1, 200, 3, gConfig.HIEPMOCNAP[66], gObjUser.MocNapCheck3);
	//----
	if (gObjUser.MOCNAP3 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 112 + add1, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP3 == 0)
	{
		if (gObjUser.MOCNAPCOIN >= gObjUser.MocNapCheck3)
		{
			gInterface.DrawGUI(MOCNAP3, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 107);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 112 + add1, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP3))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP3, gInterface.Data[MOCNAP3].X, gInterface.Data[MOCNAP3].Y, Color);
			}
		}
	}
	gInterface.DrawFormat(eExcellent, XMOCNAP + 200, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 112 + add1, 200, 3, "Chi tiết...");
	if (pCheckMouseOver(XMOCNAP + 290, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 112 + add1, 15, 10) == 1)
	{
		gCItemSetOption.ItemTooltipS15		(XMOCNAP + 340, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 112 + add1, 135, 65, 0.0, 0);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 120 + add1, 300, 1 ,gConfig.HIEPMOCNAP[11]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 130 + add1, 300, 1 ,gConfig.HIEPMOCNAP[12]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 140 + add1, 300, 1 ,gConfig.HIEPMOCNAP[13]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 150 + add1, 300, 1 ,gConfig.HIEPMOCNAP[14]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 160 + add1, 300, 1 ,gConfig.HIEPMOCNAP[15]);
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 4
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 135, 200, 15, 0.0, 0);
	//----
	int MocNap4;
	if (gObjUser.MocNapCheck4 > 0)
	{
		MocNap4 = (gObjUser.MOCNAPCOIN * gObjUser.MocNapCheck4) / gObjUser.MocNapCheck4;
		if (MocNap4 > gObjUser.MocNapCheck4)
		{
			MocNap4 = gObjUser.MocNapCheck4;
		}
	}
	float TyLeNap4 = (199.0 * MocNap4) / gObjUser.MocNapCheck4;
	if (TyLeNap4 > 199.0) { TyLeNap4 = 199.0; }
	pDrawGUI(0x0897, 201.0f, 135.0f, TyLeNap4, 14.0f);
	gInterface.DrawFormat(gcolor, XMOCNAP - 70, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 137 + add1, 200, 3, gConfig.HIEPMOCNAP[66], gObjUser.MocNapCheck4);
	if (gObjUser.MOCNAP4 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 137 + add1, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP4 == 0)
	{
		if (gObjUser.MOCNAPCOIN >= gObjUser.MocNapCheck4)
		{
			gInterface.DrawGUI(MOCNAP4, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 132);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 137 + add1, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP4))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP4, gInterface.Data[MOCNAP4].X, gInterface.Data[MOCNAP4].Y, Color);
			}
		}
	}
	gInterface.DrawFormat(eExcellent, XMOCNAP + 200, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 137 + add1, 200, 3, "Chi tiết...");
	if (pCheckMouseOver(XMOCNAP + 290, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 137 + add1, 15, 10) == 1)
	{
		gCItemSetOption.ItemTooltipS15		(XMOCNAP + 340, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 137 + add1, 135, 65, 0.0, 0);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 140 + add1, 300, 1 ,gConfig.HIEPMOCNAP[16]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 150 + add1, 300, 1 ,gConfig.HIEPMOCNAP[17]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 160 + add1, 300, 1 ,gConfig.HIEPMOCNAP[18]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 170 + add1, 300, 1 ,gConfig.HIEPMOCNAP[19]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 180 + add1, 300, 1 ,gConfig.HIEPMOCNAP[20]);
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 5
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 160, 200, 15, 0.0, 0);
	//----
	int MocNap5;
	if (gObjUser.MocNapCheck5 > 0)
	{
		MocNap5 = (gObjUser.MOCNAPCOIN * gObjUser.MocNapCheck5) / gObjUser.MocNapCheck5;
		if (MocNap5 > gObjUser.MocNapCheck5)
		{
			MocNap5 = gObjUser.MocNapCheck5;
		}
	}
	float TyLeNap5 = (199.0 * MocNap5) / gObjUser.MocNapCheck5;
	if (TyLeNap5 > 199.0) { TyLeNap5 = 199.0; }
	pDrawGUI(0x0897, 201.0f, 160.0f, TyLeNap5, 14.0f);
	gInterface.DrawFormat(gcolor, XMOCNAP - 70, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 162 + add1, 200, 3, gConfig.HIEPMOCNAP[66], gObjUser.MocNapCheck5);
	//----
	if (gObjUser.MOCNAP5 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 162 + add1, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP5 == 0)
	{
		if (gObjUser.MOCNAPCOIN >= gObjUser.MocNapCheck5)
		{
			gInterface.DrawGUI(MOCNAP5, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 157);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 162 + add1, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP5))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP5, gInterface.Data[MOCNAP5].X, gInterface.Data[MOCNAP5].Y, Color);
			}
		}
	}
	gInterface.DrawFormat(eExcellent, XMOCNAP + 200, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 162 + add1, 200, 3, "Chi tiết...");
	if (pCheckMouseOver(XMOCNAP + 290, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 162 + add1, 15, 10) == 1)
	{
		gCItemSetOption.ItemTooltipS15		(XMOCNAP + 340, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 162 + add1, 135, 65, 0.0, 0);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 170 + add1, 300, 1 ,gConfig.HIEPMOCNAP[21]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 180 + add1, 300, 1 ,gConfig.HIEPMOCNAP[22]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 190 + add1, 300, 1 ,gConfig.HIEPMOCNAP[23]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 200 + add1, 300, 1 ,gConfig.HIEPMOCNAP[24]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 210 + add1, 300, 1 ,gConfig.HIEPMOCNAP[25]);
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 6
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 185, 200, 15, 0.0, 0);
	//----
	int MocNap6;
	if (gObjUser.MocNapCheck6 > 0)
	{
		MocNap6 = (gObjUser.MOCNAPCOIN * gObjUser.MocNapCheck6) / gObjUser.MocNapCheck6;
		if (MocNap6 > gObjUser.MocNapCheck6)
		{
			MocNap6 = gObjUser.MocNapCheck6;
		}
	}
	float TyLeNap6 = (199.0 * MocNap6) / gObjUser.MocNapCheck6;
	if (TyLeNap6 > 199.0) { TyLeNap6 = 199.0; }
	pDrawGUI(0x0897, 201.0f, 185.0f, TyLeNap6, 14.0f);
	gInterface.DrawFormat(gcolor, XMOCNAP - 70, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 187 + add1, 200, 3, gConfig.HIEPMOCNAP[66], gObjUser.MocNapCheck6);
	if (gObjUser.MOCNAP6 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 187 + add1, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP6 == 0)
	{
		if (gObjUser.MOCNAPCOIN >= gObjUser.MocNapCheck6)
		{
			gInterface.DrawGUI(MOCNAP6, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 182);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 187 + add1, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP6))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP6, gInterface.Data[MOCNAP6].X, gInterface.Data[MOCNAP6].Y, Color);
			}
		}
	}
	gInterface.DrawFormat(eExcellent, XMOCNAP + 200, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 187 + add1, 200, 3, "Chi tiết...");
	if (pCheckMouseOver(XMOCNAP + 290, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 187 + add1, 15, 10) == 1)
	{
		gCItemSetOption.ItemTooltipS15		(XMOCNAP + 340, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 187 + add1, 135, 65, 0.0, 0);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 195 + add1, 300, 1 ,gConfig.HIEPMOCNAP[26]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 205 + add1, 300, 1 ,gConfig.HIEPMOCNAP[27]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 215 + add1, 300, 1 ,gConfig.HIEPMOCNAP[28]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 225 + add1, 300, 1 ,gConfig.HIEPMOCNAP[29]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 235 + add1, 300, 1 ,gConfig.HIEPMOCNAP[30]);
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 7
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 210, 200, 15, 0.0, 0);
	//----
	int MocNap7;
	if (gObjUser.MocNapCheck7 > 0)
	{
		MocNap7 = (gObjUser.MOCNAPCOIN * gObjUser.MocNapCheck7) / gObjUser.MocNapCheck7;
		if (MocNap7 > gObjUser.MocNapCheck7)
		{
			MocNap7 = gObjUser.MocNapCheck7;
		}
	}
	float TyLeNap7 = (199.0 * MocNap7) / gObjUser.MocNapCheck7;
	if (TyLeNap7 > 199.0) { TyLeNap7 = 199.0; }
	pDrawGUI(0x0897, 201.0f, 210.0f, TyLeNap7, 14.0f);
	gInterface.DrawFormat(gcolor, XMOCNAP - 70, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 212 + add1, 200, 3, gConfig.HIEPMOCNAP[66], gObjUser.MocNapCheck7);
	//----
	if (gObjUser.MOCNAP7 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 212 + add1, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP7 == 0)
	{
		if (gObjUser.MOCNAPCOIN >= gObjUser.MocNapCheck7)
		{
			gInterface.DrawGUI(MOCNAP7, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 207);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 212 + add1, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP7))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP7, gInterface.Data[MOCNAP7].X, gInterface.Data[MOCNAP7].Y, Color);
			}
		}
	}
	gInterface.DrawFormat(eExcellent, XMOCNAP + 200, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 212 + add1, 200, 3, "Chi tiết...");
	if (pCheckMouseOver(XMOCNAP + 290, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 212 + add1, 15, 10) == 1)
	{
		gCItemSetOption.ItemTooltipS15		(XMOCNAP + 340, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 212 + add1, 135, 65, 0.0, 0);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 220 + add1, 300, 1 ,gConfig.HIEPMOCNAP[31]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 230 + add1, 300, 1 ,gConfig.HIEPMOCNAP[32]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 240 + add1, 300, 1 ,gConfig.HIEPMOCNAP[33]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 250 + add1, 300, 1 ,gConfig.HIEPMOCNAP[34]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 260 + add1, 300, 1 ,gConfig.HIEPMOCNAP[35]);
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 8
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 235, 200, 15, 0.0, 0);
	//----
	int MocNap8;
	if (gObjUser.MocNapCheck8 > 0)
	{
		MocNap8 = (gObjUser.MOCNAPCOIN * gObjUser.MocNapCheck8) / gObjUser.MocNapCheck8;
		if (MocNap8 > gObjUser.MocNapCheck8)
		{
			MocNap8 = gObjUser.MocNapCheck8;
		}
	}
	float TyLeNap8 = (199.0 * MocNap8) / gObjUser.MocNapCheck8;
	if (TyLeNap8 > 199.0) { TyLeNap8 = 199.0; }
	pDrawGUI(0x0897, 201.0f, 235.0f, TyLeNap8, 14.0f);
	gInterface.DrawFormat(gcolor, XMOCNAP - 70, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 237 + add1, 200, 3, gConfig.HIEPMOCNAP[66], gObjUser.MocNapCheck8);
	if (gObjUser.MOCNAP8 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 237 + add1, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP8 == 0)
	{
		if (gObjUser.MOCNAPCOIN >= gObjUser.MocNapCheck8)
		{
			gInterface.DrawGUI(MOCNAP8, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 232);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 237 + add1, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP8))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP8, gInterface.Data[MOCNAP8].X, gInterface.Data[MOCNAP8].Y, Color);
			}
		}
	}
	gInterface.DrawFormat(eExcellent, XMOCNAP + 200, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 237 + add1, 200, 3, "Chi tiết...");
	if (pCheckMouseOver(XMOCNAP + 290, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 237 + add1, 15, 10) == 1)
	{
		gCItemSetOption.ItemTooltipS15		(XMOCNAP + 340, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 237 + add1, 135, 65, 0.0, 0);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 245 + add1, 300, 1 ,gConfig.HIEPMOCNAP[36]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 255 + add1, 300, 1 ,gConfig.HIEPMOCNAP[37]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 265 + add1, 300, 1 ,gConfig.HIEPMOCNAP[38]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 275 + add1, 300, 1 ,gConfig.HIEPMOCNAP[39]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 285 + add1, 300, 1 ,gConfig.HIEPMOCNAP[40]);
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 9
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 260, 200, 15, 0.0, 0);
	//----
	int MocNap9;
	if (gObjUser.MocNapCheck9 > 0)
	{
		MocNap9 = (gObjUser.MOCNAPCOIN * gObjUser.MocNapCheck9) / gObjUser.MocNapCheck9;
		if (MocNap9 > gObjUser.MocNapCheck9)
		{
			MocNap9 = gObjUser.MocNapCheck9;
		}
	}
	float TyLeNap9 = (199.0 * MocNap9) / gObjUser.MocNapCheck9;
	if (TyLeNap9 > 199.0) { TyLeNap9 = 199.0; }
	pDrawGUI(0x0897, 201.0f, 260.0f, TyLeNap9, 14.0f);
	gInterface.DrawFormat(gcolor, XMOCNAP - 70, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 262 + add1, 200, 3, gConfig.HIEPMOCNAP[66], gObjUser.MocNapCheck9);
	if (gObjUser.MOCNAP9 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 262 + add1, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP9 == 0)
	{
		if (gObjUser.MOCNAPCOIN >= gObjUser.MocNapCheck9)
		{
			gInterface.DrawGUI(MOCNAP9, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 257);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 262 + add1, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP9))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP9, gInterface.Data[MOCNAP9].X, gInterface.Data[MOCNAP9].Y, Color);
			}
		}
	}
	gInterface.DrawFormat(eExcellent, XMOCNAP + 200, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 262 + add1, 200, 3, "Chi tiết...");
	if (pCheckMouseOver(XMOCNAP + 290, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 262 + add1, 15, 10) == 1)
	{
		gCItemSetOption.ItemTooltipS15		(XMOCNAP + 340, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 262 + add1, 135, 65, 0.0, 0);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 270 + add1, 300, 1 ,gConfig.HIEPMOCNAP[41]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 280 + add1, 300, 1 ,gConfig.HIEPMOCNAP[42]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 290 + add1, 300, 1 ,gConfig.HIEPMOCNAP[43]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 300 + add1, 300, 1 ,gConfig.HIEPMOCNAP[44]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 310 + add1, 300, 1 ,gConfig.HIEPMOCNAP[45]);
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 10
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 285, 200, 15, 0.0, 0);
	//----
	int MocNap10;
	if (gObjUser.MocNapCheck10 > 0)
	{
		MocNap10 = (gObjUser.MOCNAPCOIN * gObjUser.MocNapCheck10) / gObjUser.MocNapCheck10;
		if (MocNap10 > gObjUser.MocNapCheck10)
		{
			MocNap10 = gObjUser.MocNapCheck10;
		}
	}
	float TyLeNap10 = (199.0 * MocNap10) / gObjUser.MocNapCheck10;
	if (TyLeNap10 > 199.0) { TyLeNap10 = 199.0; }
	pDrawGUI(0x0897, 201.0f, 285.0f, TyLeNap10, 14.0f);
	gInterface.DrawFormat(gcolor, XMOCNAP - 70, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 287 + add1, 200, 3, gConfig.HIEPMOCNAP[66], gObjUser.MocNapCheck10);
	if (gObjUser.MOCNAP10 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 287 + add1, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP10 == 0)
	{
		if (gObjUser.MOCNAPCOIN >= gObjUser.MocNapCheck10)
		{
			gInterface.DrawGUI(MOCNAP10, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 282);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 287 + add1, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP10))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP10, gInterface.Data[MOCNAP10].X, gInterface.Data[MOCNAP10].Y, Color);
			}
		}
	}
	gInterface.DrawFormat(eExcellent, XMOCNAP + 200, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 287 + add1, 200, 3, "Chi tiết...");
	if (pCheckMouseOver(XMOCNAP + 290, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 287 + add1, 15, 10) == 1)
	{
		gCItemSetOption.ItemTooltipS15		(XMOCNAP + 340, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 287 + add1, 135, 65, 0.0, 0);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 295 + add1, 300, 1 ,gConfig.HIEPMOCNAP[46]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 305 + add1, 300, 1 ,gConfig.HIEPMOCNAP[47]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 315 + add1, 300, 1 ,gConfig.HIEPMOCNAP[48]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 325 + add1, 300, 1 ,gConfig.HIEPMOCNAP[49]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 335 + add1, 300, 1 ,gConfig.HIEPMOCNAP[50]);
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 11
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 310, 200, 15, 0.0, 0);
	//----
	int MocNap11;
	if (gObjUser.MocNapCheck11 > 0)
	{
		MocNap11 = (gObjUser.MOCNAPCOIN * gObjUser.MocNapCheck11) / gObjUser.MocNapCheck11;
		if (MocNap11 > gObjUser.MocNapCheck11)
		{
			MocNap11 = gObjUser.MocNapCheck11;
		}
	}
	float TyLeNap11 = (199.0 * MocNap11) / gObjUser.MocNapCheck11;
	if (TyLeNap11 > 199.0) { TyLeNap11 = 199.0; }
	pDrawGUI(0x0897, 201.0f, 310.0f, TyLeNap11, 14.0f);
	gInterface.DrawFormat(gcolor, XMOCNAP - 70, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 312 + add1, 200, 3, gConfig.HIEPMOCNAP[66], gObjUser.MocNapCheck11);
	if (gObjUser.MOCNAP11 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 312 + add1, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP11 == 0)
	{
		if (gObjUser.MOCNAPCOIN >= gObjUser.MocNapCheck11)
		{
			gInterface.DrawGUI(MOCNAP11, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 307);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 312 + add1, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP11))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP11, gInterface.Data[MOCNAP11].X, gInterface.Data[MOCNAP11].Y, Color);
			}
		}
	}
	gInterface.DrawFormat(eExcellent, XMOCNAP + 200, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 312 + add1, 200, 3, "Chi tiết...");
	if (pCheckMouseOver(XMOCNAP + 290, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 312 + add1, 15, 10) == 1)
	{
		gCItemSetOption.ItemTooltipS15		(XMOCNAP + 340, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 312 + add1, 135, 65, 0.0, 0);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 320 + add1, 300, 1 ,gConfig.HIEPMOCNAP[51]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 330 + add1, 300, 1 ,gConfig.HIEPMOCNAP[52]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 340 + add1, 300, 1 ,gConfig.HIEPMOCNAP[53]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 350 + add1, 300, 1 ,gConfig.HIEPMOCNAP[54]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 360 + add1, 300, 1 ,gConfig.HIEPMOCNAP[55]);
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 12
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 335, 200, 15, 0.0, 0);
	//----
	int MocNap12;
	if (gObjUser.MocNapCheck12 > 0)
	{
		MocNap12 = (gObjUser.MOCNAPCOIN * gObjUser.MocNapCheck12) / gObjUser.MocNapCheck12;
		if (MocNap12 > gObjUser.MocNapCheck12)
		{
			MocNap12 = gObjUser.MocNapCheck12;
		}
	}
	float TyLeNap12 = (199.0 * MocNap12) / gObjUser.MocNapCheck12;
	if (TyLeNap12 > 199.0) { TyLeNap12 = 199.0; }
	pDrawGUI(0x0897, 201.0f, 335.0f, TyLeNap12, 14.0f);
	gInterface.DrawFormat(gcolor, XMOCNAP - 70, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 337 + add1, 200, 3, gConfig.HIEPMOCNAP[66], gObjUser.MocNapCheck12);
	if (gObjUser.MOCNAP12 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 337 + add1, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP12 == 0)
	{
		if (gObjUser.MOCNAPCOIN >= gObjUser.MocNapCheck12)
		{
			gInterface.DrawGUI(MOCNAP12, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 332);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 337 + add1, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP12))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP12, gInterface.Data[MOCNAP12].X, gInterface.Data[MOCNAP12].Y, Color);
			}
		}
	}
	gInterface.DrawFormat(eExcellent, XMOCNAP + 200, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 337 + add1, 200, 3, "Chi tiết...");
	if (pCheckMouseOver(XMOCNAP + 290, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 337 + add1, 15, 10) == 1)
	{
		gCItemSetOption.ItemTooltipS15		(XMOCNAP + 340, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 337 + add1, 135, 65, 0.0, 0);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 345 + add1, 300, 1 ,gConfig.HIEPMOCNAP[56]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 355 + add1, 300, 1 ,gConfig.HIEPMOCNAP[57]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 365 + add1, 300, 1 ,gConfig.HIEPMOCNAP[58]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 375 + add1, 300, 1 ,gConfig.HIEPMOCNAP[59]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 385 + add1, 300, 1 ,gConfig.HIEPMOCNAP[60]);
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 13
	gCItemSetOption.ItemTooltipS15(XMOCNAP + 50, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 360, 200, 15, 0.0, 0);
	//----
	int MocNap13;
	if (gObjUser.MocNapCheck13 > 0)
	{
		MocNap13 = (gObjUser.MOCNAPCOIN * gObjUser.MocNapCheck13) / gObjUser.MocNapCheck13;
		if (MocNap13 > gObjUser.MocNapCheck13)
		{
			MocNap13 = gObjUser.MocNapCheck13;
		}
	}
	float TyLeNap13 = (199.0 * MocNap13) / gObjUser.MocNapCheck13;
	if (TyLeNap13 > 199.0) { TyLeNap13 = 199.0; }
	pDrawGUI(0x0897, 201.0f, 360.0f, TyLeNap13, 14.0f);
	gInterface.DrawFormat(gcolor, XMOCNAP - 70, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 362 + add1, 200, 3, gConfig.HIEPMOCNAP[66], gObjUser.MocNapCheck13);
	if (gObjUser.MOCNAP13 == 1)
	{
		gInterface.DrawFormat(eExcellent, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 362 + add1, 200, 3, "Đã Nhận");
	}
	if (gObjUser.MOCNAP13 == 0)
	{
		if (gObjUser.MOCNAPCOIN >= gObjUser.MocNapCheck13)
		{
			gInterface.DrawGUI(MOCNAP13, XMOCNAP + 250, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 357);
			gInterface.DrawFormat(eGold, XMOCNAP + 168, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 362 + add1, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(MOCNAP13))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(MOCNAP13, gInterface.Data[MOCNAP13].X, gInterface.Data[MOCNAP13].Y, Color);
			}
		}
	}
	gInterface.DrawFormat(eExcellent, XMOCNAP + 200, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 362 + add1, 200, 3, "Chi tiết...");
	if (pCheckMouseOver(XMOCNAP + 290, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 362 + add1, 15, 10) == 1)
	{
		gCItemSetOption.ItemTooltipS15		(XMOCNAP + 340, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 362 + add1, 135, 65, 0.0, 0);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 370 + add1, 300, 1 ,gConfig.HIEPMOCNAP[61]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 380 + add1, 300, 1 ,gConfig.HIEPMOCNAP[62]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 390 + add1, 300, 1 ,gConfig.HIEPMOCNAP[63]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 400 + add1, 300, 1 ,gConfig.HIEPMOCNAP[64]);
		gInterface.DrawFormat(eWhite, XMOCNAP + 345, gInterface.Data[EXBEXO_MOCNAP_MAIN].Y + 410 + add1, 300, 1 ,gConfig.HIEPMOCNAP[65]);
	}
	/// ket thuc
	//======================================================================================================================
	//======================================================================================================================
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_MOCNAP::MAIN_MOCNAP(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	this->CLOSE_MOCNAP(Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP1))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP1].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP1].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP1].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP1].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(20);
	}
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP2))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP2].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP2].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP2].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP2].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(21);
	}
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP3))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP3].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP3].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP3].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP3].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(22);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP4))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP4].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP4].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP4].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP4].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(23);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP5))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP5].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP5].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP5].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP5].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(24);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP6))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP6].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP6].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP6].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP6].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(25);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP7))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP7].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP7].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP7].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP7].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(26);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP8))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP8].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP8].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP8].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP8].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(27);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP9))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP9].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP9].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP9].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP9].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(28);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP10))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP10].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP10].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP10].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP10].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(29);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP11))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP11].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP11].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP11].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP11].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(30);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP12))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP12].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP12].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP12].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP12].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(31);
	}
	//------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow && gInterface.IsWorkZone(MOCNAP13))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[MOCNAP13].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[MOCNAP13].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[MOCNAP13].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[MOCNAP13].EventTick = GetTickCount();
		this->CLOSE_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(32);
	}
	//------------------------------------------------------------------------------------------
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_MOCNAP::CLOSE_MOCNAP(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_MOCNAP_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_MOCNAP_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_MOCNAP_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_MOCNAP_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_MOCNAP_CLOSE].EventTick = GetTickCount();
	G_BEXO_MOCNAP.CLOSE_WINDOW_MOCNAP();
	// ----
	return false;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
#endif
