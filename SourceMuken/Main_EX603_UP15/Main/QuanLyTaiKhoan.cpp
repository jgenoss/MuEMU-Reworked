
#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "QuanLyTaiKhoan.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "CustomMessage.h"
#include "Defines.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "Interface.h"
#include "User.h"
#include "Protocol.h"
#include "PrintPlayer.h"
#include "SItemOption.h"
#include "Import.h"
#include "Central.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------
QUAN_LY_TK G_QUAN_LY_TK;
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#define MAX_TRANG_QUAN_LY    10  // OK

//-----------------------------------------------------------------------------------------------------------------------------------------------------
QUAN_LY_TK::QUAN_LY_TK()
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void QUAN_LY_TK::DRAW_QUAN_LY()
{
	DRAW_WINDOW_CHANGEPASS();
}

void QUAN_LY_TK::BinObeject()
{
	gInterface.BindObject(eChangePass_Main, 31461, 640, 419, -1, -1);  // 31461
	gInterface.BindObject(eChangePass_BTCLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(eChangePass_OLD, 0x7AA3, 170, 21, -1, -1);
	gInterface.BindObject(eChangePass_NEW, 0x7AA3, 170, 21, -1, -1);
	gInterface.BindObject(eChangePass_BTOK, 0x7A5B, 54, 30, -1, -1);
}
void QUAN_LY_TK::LoadImages()
{

}

//-----------------------------------------------------------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------------------------------------------------------

bool QUAN_LY_TK::EVENT_CLICK_CHANGEPASS(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eChangePass_BTCLOSE].EventTick);
	DWORD Delay_2 = (CurrentTick - gInterface.Data[eChangePass_BTOK].EventTick);
	// ----
	if (!gInterface.Data[eChangePass_Main].OnShow)
	{
		return false;
	}

	if (gInterface.IsWorkZone(eChangePass_OLD))
	{
		gInterface.Data[eChangePass_OLD].Attribute = 1;
	}
	else
	{
		gInterface.Data[eChangePass_OLD].Attribute = 0;
	}

	if (gInterface.IsWorkZone(eChangePass_NEW))
	{
		gInterface.Data[eChangePass_NEW].Attribute = 1;
	}
	else
	{
		gInterface.Data[eChangePass_NEW].Attribute = 0;
	}

	if (gInterface.IsWorkZone(eChangePass_BTCLOSE))
	{
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eChangePass_BTCLOSE].OnClick = true;
			return true;
		}
		// ----
		gInterface.Data[eChangePass_BTCLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		// ----
		gInterface.Data[eChangePass_BTCLOSE].EventTick = GetTickCount();
		G_QUAN_LY_TK.OPEN_WINDOW_CHANGEPASS();
		sprintf(gInterface.Data[eChangePass_OLD].StatValue, ""); //NONE
		sprintf(gInterface.Data[eChangePass_OLD_HIDE].StatValue, ""); //NONE
		sprintf(gInterface.Data[eChangePass_NEW].StatValue, ""); //NONE
		sprintf(gInterface.Data[eChangePass_NEW_HIDE].StatValue, ""); //NONE
	}
	else if (gInterface.IsWorkZone(eChangePass_BTOK))
	{
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eChangePass_BTOK].OnClick = true;
			return true;
		}
		// ----
		gInterface.Data[eChangePass_BTOK].OnClick = false;
		// ----
		if (Delay_2 < 500)
		{
			return false;
		}
		// ----
		gInterface.Data[eChangePass_BTOK].EventTick = GetTickCount();
		//=== SEND GS
		CSENDGS_DOIMK pMsg;
		pMsg.TYPE = 0x01;
		memcpy(pMsg.PASS_OLD, gInterface.Data[eChangePass_OLD].StatValue, sizeof(pMsg.PASS_OLD));
		memcpy(pMsg.PASS_NEW, gInterface.Data[eChangePass_NEW].StatValue, sizeof(pMsg.PASS_NEW));
		pMsg.Head.set(0xFF, 0x91, sizeof(pMsg));
		DataSend((BYTE*)& pMsg, pMsg.Head.size);
		//===========
		G_QUAN_LY_TK.OPEN_WINDOW_CHANGEPASS();


		sprintf(gInterface.Data[eChangePass_OLD].StatValue, ""); //NONE
		sprintf(gInterface.Data[eChangePass_OLD_HIDE].StatValue, ""); //NONE
		sprintf(gInterface.Data[eChangePass_NEW].StatValue, ""); //NONE
		sprintf(gInterface.Data[eChangePass_NEW_HIDE].StatValue, ""); //NONE
	}
	// ----
	return false;
}
#include "Util.h"

bool QUAN_LY_TK::CHANGEPASS_TEXTBOX(DWORD Event)
{
	if (gInterface.Data[eChangePass_Main].OnShow && gInterface.Data[eChangePass_OLD].Attribute == 1)
	{
		char value[20];
		int is_backspace = false;
		int is_enter = false;
		int IsDelete = false;

		if (Event == VK_BACK)
		{
			is_backspace = true;
		}
		else if (Event == VK_RETURN)
		{
			is_enter = true;
		}
		else if (Event == VK_DELETE)
		{
			IsDelete = true;
		}
		else if ((Event >= 0x30 && Event <= 0x39) || (Event >= 0x60 && Event <= 0x69) || (Event >= 0x41 && Event <= 0x5A))
		{
			const int symbol = GetSymbolFromVK(Event);
			if (symbol == 0)
			{
				return 1;
			}
			char buff[10];
			sprintf(buff, "%c", symbol);
			strcpy_s(value, buff);
		}
		else
		{
			return true;
		}

		if (is_backspace == true)
		{
			if (!strcmp(gInterface.Data[eChangePass_OLD].StatValue, ""))
			{
				return true;
			}
			gInterface.Data[eChangePass_OLD].StatValue[strlen(gInterface.Data[eChangePass_OLD].StatValue) - 1] = '\0';
			gInterface.Data[eChangePass_OLD_HIDE].StatValue[strlen(gInterface.Data[eChangePass_OLD_HIDE].StatValue) - 1] = '\0';
		}
		else if (IsDelete == true)
		{
			strcpy_s(gInterface.Data[eChangePass_OLD].StatValue, "");
			strcpy_s(gInterface.Data[eChangePass_OLD_HIDE].StatValue, "");
		}
		else
		{
			if (strlen(gInterface.Data[eChangePass_OLD].StatValue) < 10)
			{
				if (!strcmp(gInterface.Data[eChangePass_OLD].StatValue, ""))
				{
					strcpy_s(gInterface.Data[eChangePass_OLD].StatValue, value);
					strcpy_s(gInterface.Data[eChangePass_OLD_HIDE].StatValue, "*");
				}
				else
				{
					strcat_s(gInterface.Data[eChangePass_OLD].StatValue, value);
					strcat_s(gInterface.Data[eChangePass_OLD_HIDE].StatValue, "*");
				}
			}
		}
	}
	
	else if (gInterface.Data[eChangePass_Main].OnShow && gInterface.Data[eChangePass_NEW].Attribute == 1)
	{
		char value[20];
		int is_backspace = false;
		int is_enter = false;
		int IsDelete = false;

		if (Event == VK_BACK)
		{
			is_backspace = true;
		}
		else if (Event == VK_RETURN)
		{
			is_enter = true;
		}
		else if (Event == VK_DELETE)
		{
			IsDelete = true;
		}
		else if ((Event >= 0x30 && Event <= 0x39) || (Event >= 0x60 && Event <= 0x69) || (Event >= 0x41 && Event <= 0x5A))
		{
			const int symbol = GetSymbolFromVK(Event);
			if (symbol == 0)
			{
				return 1;
			}
			char buff[10];
			sprintf(buff, "%c", symbol);
			strcpy_s(value, buff);
		}
		else
		{
			return true;
		}

		if (is_backspace == true)
		{
			if (!strcmp(gInterface.Data[eChangePass_NEW].StatValue, ""))
			{
				return true;
			}
			gInterface.Data[eChangePass_NEW].StatValue[strlen(gInterface.Data[eChangePass_NEW].StatValue) - 1] = '\0';
			gInterface.Data[eChangePass_NEW_HIDE].StatValue[strlen(gInterface.Data[eChangePass_NEW_HIDE].StatValue) - 1] = '\0';
		}
		//else if (is_enter == true)
		//{
		//	//gPartySearch.SendPartyRequest(gPartySearch.currentIndex, gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].StatValue);
		//	//gPartySearch.party_search_password_switch_state();
		//	return 1;
		//}
		else if (IsDelete == true)
		{
			strcpy_s(gInterface.Data[eChangePass_NEW].StatValue, "");
			strcpy_s(gInterface.Data[eChangePass_NEW_HIDE].StatValue, "");
		}
		else
		{
			if (strlen(gInterface.Data[eChangePass_NEW].StatValue) < 10)
			{
				if (!strcmp(gInterface.Data[eChangePass_NEW].StatValue, ""))
				{
					strcpy_s(gInterface.Data[eChangePass_NEW].StatValue, value);
					strcpy_s(gInterface.Data[eChangePass_NEW_HIDE].StatValue, "*");
				}
				else
				{
					strcat_s(gInterface.Data[eChangePass_NEW].StatValue, value);
					strcat_s(gInterface.Data[eChangePass_NEW_HIDE].StatValue, "*");
				}
			}
		}
	}
	return false;
}

void QUAN_LY_TK::DRAW_WINDOW_CHANGEPASS()
{

	if (gInterface.CheckWindow(CashShop)
		|| gInterface.CheckWindow(SkillTree)
		|| gInterface.CheckWindow(FullMap)
		|| gInterface.CheckWindow(MoveList)
		|| (gInterface.CheckWindow(Inventory)
			&& gInterface.CheckWindow(ExpandInventory)
			&& gInterface.CheckWindow(Store))
		|| (gInterface.CheckWindow(Inventory)
			&& gInterface.CheckWindow(Warehouse)
			&& gInterface.CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (!gInterface.Data[eChangePass_Main].OnShow)
	{
		return;
	}

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	int JCResto = pWinWidth / pWinHeightReal / 2 - 320;
	float MainW = 200;
	float MainH = 170;
	float CP_StartX = (MAX_WIN_WIDTH / 2) - (MainW / 2)+JCResto;
	float MainCenter = StartX + (MainWidth / 2);
	float ButtonX = MainCenter - (29.0 / 2);

	float CuaSoW = 200.0;
	float CuaSoH = 170.0;
	//int JCResto = pWinWidth / pWinHeightReal / 2 - 320;
	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2)+JCResto;
	float StartY = 50.0;
	//gCentral.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eChangePass_Main, "Thay Đổi Mật Khẩu Tài Khoản");

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	
		pSetCursorFocus = true;
	
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gCItemSetOption.ItemTooltipS15(CP_StartX, gInterface.Data[eChangePass_Main].Y + 50, MainW, MainH, 0.0, 0);

	float CP_StartY = gInterface.Data[eChangePass_Main].Y + 50;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eChangePass_BTCLOSE, CP_StartX+ MainW-34, gInterface.Data[eChangePass_Main].Y + 50);
	if (gInterface.IsWorkZone(eChangePass_BTCLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(eChangePass_BTCLOSE, gInterface.Data[eChangePass_BTCLOSE].X, gInterface.Data[eChangePass_BTCLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eWhite, CP_StartX, gInterface.Data[eChangePass_Main].Y + 70, MainW, 3, "Thay Đổi Mật Khẩu Tài Khoản");
	if (gInterface.Data[eChangePass_Main].FirstLoad == true)
	{
		if (strlen(gInterface.Data[eChangePass_OLD].StatValue) == 0)
			sprintf(gInterface.Data[eChangePass_OLD].StatValue, ""); //NONE

		if (strlen(gInterface.Data[eChangePass_NEW].StatValue) == 0)
			sprintf(gInterface.Data[eChangePass_NEW].StatValue, ""); //NONE
	}
	//=== Pass Cu
	gInterface.DrawGUI(eChangePass_OLD, CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_OLD].Width / 2), CP_StartY + 50);
	if (gInterface.Data[eChangePass_OLD].Attribute == 1)
	{
		gInterface.DrawColoredGUI(eChangePass_OLD, CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_OLD].Width / 2), CP_StartY + 50, eGray190);
	}
	gInterface.DrawText(eWhite, CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_OLD].Width / 2)+10, CP_StartY + 55, 170, 1, "Mật Khẩu (Cũ)");
	gInterface.DrawText(eWhite, (CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_NEW].Width / 2)) + 60, CP_StartY + 55, 100, 3, gInterface.Data[eChangePass_OLD_HIDE].StatValue);
	//=== Pass Moi
	gInterface.DrawGUI(eChangePass_NEW, CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_NEW].Width / 2), CP_StartY + 80);

	if (gInterface.Data[eChangePass_NEW].Attribute == 1)
	{
		gInterface.DrawColoredGUI(eChangePass_NEW, CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_NEW].Width / 2), CP_StartY + 80, eGray190);
	}

	gInterface.DrawText(eWhite, CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_NEW].Width / 2) + 10, CP_StartY + 85, 170, 1, "Mật Khẩu (Mới)");
	gInterface.DrawText(eWhite, (CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_NEW].Width / 2))+60, CP_StartY + 85, 100, 3, gInterface.Data[eChangePass_NEW_HIDE].StatValue);
	gInterface.DrawButton(eChangePass_BTOK, CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_BTOK].Width / 2), CP_StartY+ MainH -(50), 0, 0);

	if (gInterface.IsWorkZone(eChangePass_BTOK))
	{
		int ScaleY = 30;
		// ----
		if (gInterface.Data[eChangePass_BTOK].OnClick)
		{
			ScaleY = 60;
		}
		// ----
		gInterface.DrawButton(eChangePass_BTOK, CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_BTOK].Width / 2), CP_StartY + MainH - (50), 0, ScaleY);
	}
	//==============
	if (gInterface.Data[eChangePass_Main].FirstLoad == true)
	{
		gInterface.Data[eChangePass_Main].FirstLoad = false;
	}
}
