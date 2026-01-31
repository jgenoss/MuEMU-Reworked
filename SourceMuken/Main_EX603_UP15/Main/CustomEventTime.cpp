#include "stdafx.h"
#include "CustomEventTime.h"
#include "CustomMessage.h"
#include "Defines.h"
#include "HealthBar.h"
#include "Interface.h"
#include "Util.h"
#include "Object.h"
#include "Import.h"
#include "Central.h"
#include "Protocol.h"
#include "CustomFont.h"
#include "User.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "DanhHieu.h"
#include "SItemOption.h"
CCustomEventTime::CCustomEventTime()
{
}

CCustomEventTime gCustomEventTime;

void CCustomEventTime::Load(CUSTOM_EVENT_INFO* info) // OK
{
	for (int n = 0; n < MAX_EVENTTIME; n++)
	{
		this->SetInfo(info[n]);
	}
}

void CCustomEventTime::SetInfo(CUSTOM_EVENT_INFO info) // OK
{
	if (info.Index < 0 || info.Index >= MAX_EVENTTIME)
	{
		return;
	}

	this->m_CustomEventInfo[info.Index] = info;
}

void CCustomEventTime::ClearCustomEventTime() // OK
{
	for (int n = 0; n < MAX_EVENTTIME; n++)
	{
		gCustomEventTime[n].time = -1;
	}
	this->count = 0;
	this->EventTimeEnable = 0;
}

void CCustomEventTime::GCReqEventTime(PMSG_CUSTOM_EVENTTIME_RECV* lpMsg) // OK
{
	this->count = lpMsg->count;

	for (int n = 0; n < lpMsg->count; n++)
	{
		CUSTOM_EVENTTIME_DATA* lpInfo = (CUSTOM_EVENTTIME_DATA*)(((BYTE*)lpMsg) + sizeof(PMSG_CUSTOM_EVENTTIME_RECV) + (sizeof(CUSTOM_EVENTTIME_DATA)*n));

		this->gCustomEventTime[n].index = lpInfo->index;
		this->gCustomEventTime[n].time = lpInfo->time;

		if (this->gCustomEventTime[n].index >= 28 && this->gCustomEventTime[n].time != -1) this->Arena = 1;
	}

	this->EventTimeEnable = 1;
}

int NextEvent = 0;
int PreventEvent = 0;
int ObjectBtnIDs[41] =
{
	eMenu_OPT21, eMenu_OPT22, eMenu_OPT23, eMenu_OPT24, eMenu_OPT25, eMenu_OPT26, eMenu_OPT27, eMenu_OPT28, eMenu_OPT29, eMenu_OPT30, eMenu_OPT31,
	eMenu_OPT32, eMenu_OPT33, eMenu_OPT34, eMenu_OPT35, eMenu_OPT36, eMenu_OPT37, eMenu_OPT38, eMenu_OPT39, eMenu_OPT40, eMenu_OPT41, eMenu_OPT42,
	eMenu_OPT43, eMenu_OPT44, eMenu_OPT45, eMenu_OPT46, eMenu_OPT47, eMenu_OPT48, eMenu_OPT49, eMenu_OPT50, eMenu_OPT51, eMenu_OPT52, eMenu_OPT53,
	eMenu_OPT54, eMenu_OPT55, eMenu_OPT56, eMenu_OPT57, eMenu_OPT58, eMenu_OPT59, eMenu_OPT60, eMenu_OPT61,

};


void CCustomEventTime::DrawEventTimePanelWindow()
{
	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow)
	{
		return;
	}
	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper)
		) //-- 76
	{
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
		return;
	}

	float MainWidth = 400.0;
	float MainHeight = 360.0;
	float StartBody = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);

	if (gInterface.IsWorkZone2(StartX, StartY, StartX + MainWidth, StartY + MainHeight))
	{
		pSetCursorFocus = true;
	}
	else { pSetCursorFocus = false; }
	// ----
	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);


	//pDrawGUFULL(0x9333, StartX - 20, StartY - 5, 450, 370, 0, 0, 1, 1, 1, 1, 0.0); // MENU


	DWORD Color = eGray100;


	//=============nut next trang ============
	/*if ((this->Page == 0) || (this->Page == 1 && this->Arena==1))
	{
	gInterface.DrawGUI(eNextEvent, StartX + MainWidth - 38, 50);
	}
	else
	{
	gInterface.ResetDrawIMG(eNextEvent);
	}

	if (this->Page == 1 || this->Page == 2)
	{
	gInterface.DrawGUI(ePrevEvent, StartX + 20, 50);
	}
	else
	{
	gInterface.ResetDrawIMG(ePrevEvent);
	}*/
	//=====================================

	gInterface.DrawFormat(eGold, (int)StartX + 100, (int)StartBody + 15, 210, 3, gCustomMessage.GetMessage(148));
	
	//CustomFont.DrawMultipleColor(CustomFont.FontBold, (int)StartX + 170, (int)StartBody + 20, 0x0, 0, 0, 1, "Bang Su Kien Ingame");

	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 35, 200, 1); //-- Divisor


	if (this->EventTimeEnable == 1)
	{

		gInterface.DrawFormat(eGold, StartX + 13, StartBody + 47, 52, 1, gCustomMessage.GetMessage(149));

		gInterface.DrawFormat(eGold, StartX + 100, StartBody + 47, 52, 1, gCustomMessage.GetMessage(150));

		gInterface.DrawFormat(eGold, StartX + 200, StartBody + 47, 52, 1, gCustomMessage.GetMessage(151));

		gInterface.DrawFormat(eGold, StartX + 300, StartBody + 47, 52, 1, gCustomMessage.GetMessage(152));

		gInterface.DrawFormat(eGold, StartX + 350, StartBody + 47, 52, 1, gCustomMessage.GetMessage(153));


		//gInterface.DrawFormat(eGold,  StartX + 295, StartBody + 47, 52, 1,gCustomMessage.GetMessage(153));

		if ((GetTickCount() - this->EventTimeTickCount) > 1000)
		{
			for (int i = 0; i < this->count; i++)
			{
				if (this->gCustomEventTime[i].time > 0)
				{
					this->gCustomEventTime[i].time = this->gCustomEventTime[i].time - 1;
				}
			}
			this->EventTimeTickCount = GetTickCount();
		}

		char text1[20];
		char text2[30];
		int totalseconds;
		int hours;
		int minutes;
		int seconds;
		int days;

		int line = 0;

		float CurrentMove = 0.0;


		//for( int i = (14*Page)+0; i < (14*Page)+14; i++ )
		//41 event
		//for (int i = 0; i < 41; i++)
		for (int i = 0; i < 28; i++)
		{
			if (this->gCustomEventTime[i].time <= -1)
			{
				//wsprintf(text2, "Disabled");
				continue;
			}
			else if (this->gCustomEventTime[i].time == 0)
			{
				wsprintf(text2, "Hoạt Động");
			}
			else
			{
				totalseconds = this->gCustomEventTime[i].time;
				hours = totalseconds / 3600;
				minutes = (totalseconds / 60) % 60;
				seconds = totalseconds % 60;
				wsprintf(text2, "%02d:%02d:%02d", hours, minutes, seconds);

				if (hours > 23)
				{
					days = hours / 24;
					wsprintf(text2, "%d day(s)+", days);
				}
				else
				{
					wsprintf(text2, "%02d:%02d:%02d", hours, minutes, seconds);
				}
			}

			if (this->gCustomEventTime[i].time <= -1)
			{
				Color = eRed2;
			}
			else if (this->gCustomEventTime[i].time == 0)
			{
				Color = eExcellent;
			}
			else if (this->gCustomEventTime[i].time < 300)
			{
				Color = eExcellent;
			}
			else
			{
				Color = eYellow;
			}

			gInterface.DrawFormat(eWhite, StartX + 10, StartBody + 65 + (line), 80, 1, this->m_CustomEventInfo[i].Name);

			gInterface.DrawFormat(eWhite, StartX + 100, StartBody + 65 + (line), 60, 1, this->m_CustomEventInfo[i].Note);

			gInterface.DrawFormat(eExcellentS15, StartX + 170, StartBody + 65 + (line), 140, 1, this->m_CustomEventInfo[i].Gift);

			gInterface.DrawFormat(Color, StartX + 300, StartBody + 65 + (line), 52, 1, text2);


			//gInterface.DrawFormat(eExcellentS15,  StartX + 330, StartBody + 65 + (line), 85, 1,this->m_CustomEventInfo[i].BtnClick);

			CurrentMove = 0.0;


			if (i == 0){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT21, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 1){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT22, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 2){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT23, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 3){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT24, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 4){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT25, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 5){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT26, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 6){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT27, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 7){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT28, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 8){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT29, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 9){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT30, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 10){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT31, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 11){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT32, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 12){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT33, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 13){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT34, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 14){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT35, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 15){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT36, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 16){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT37, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 17){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT38, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 18){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT39, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 19){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT40, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 20){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT41, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 21){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT42, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 22){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT43, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 23){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT44, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 24){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT45, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 25){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT46, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 26){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT47, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 27){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT48, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 28){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT49, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 29){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT50, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 30){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT51, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 31){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT52, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 32){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT53, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 33){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT54, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 34){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT55, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 35){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT56, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 36){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT57, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 37){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT58, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 38){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT59, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 39){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT60, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 40){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT61, StartX + 360, StartBody + 63 + (line)); } }
			if (i == 41){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eMenu_OPT62, StartX + 360, StartBody + 63 + (line)); } }
			line += 12;





		}
	}
	else
	{
		if (this->EventTimeLoad == 1)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartBody + 120, 52, 1, gCustomMessage.GetMessage(154), "..");
			this->EventTimeLoad = 2;
		}
		else if (this->EventTimeLoad == 2)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartBody + 120, 52, 1, gCustomMessage.GetMessage(154), " ...");
			this->EventTimeLoad = 3;
		}
		else if (this->EventTimeLoad == 3)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartBody + 120, 52, 1, gCustomMessage.GetMessage(154), " ....");
			this->EventTimeLoad = 4;
		}
		else if (this->EventTimeLoad == 4)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartBody + 120, 52, 1, gCustomMessage.GetMessage(154), " .....");
			this->EventTimeLoad = 0;
		}
		else
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartBody + 120, 52, 1, gCustomMessage.GetMessage(154), " .");
			this->EventTimeLoad = 1;
		}
	}

	//gInterface.DrawFormat(eGold, (int)StartX + 80, (int)StartBody + 270, 210, 3, gCustomMessage.GetMessage(155));
	//gInterface.DrawFormat(eGold, (int)StartX + 80, (int)StartBody + 280, 210, 3, gCustomMessage.GetMessage(156));



	HFONT TextFontBold_BAN_POINT_7 = CreateFontA(18, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
	pSetTextSize(pTextThis(), TextFontBold_BAN_POINT_7); //set font
	pSetTextColor(pTextThis(), 255, 255, 255, 255); // 
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	//CustomFont.DrawMultipleColor(CustomFont.FontBold, (int)StartX + 160, (int)StartBody + 290, 0x0, 0, 0, 1, "THANK YOU!");
	DeleteObject(TextFontBold_BAN_POINT_7);

	//CustomFont.Draw(CustomFont.FontBold,   (int)StartX + 200, (int)StartBody + 270, 0xFF00FFFF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(155));
	//CustomFont.Draw(CustomFont.FontNormal, (int)StartX + 200, (int)StartBody + 270, 0xFF00FFFF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(155));
	//CustomFont.Draw(CustomFont.FontSize15,  (int)StartX + 200, (int)StartBody + 270, 0xFF00FFFF, 0xFF000033, 0, 0, 0, gCustomMessage.GetMessage(155));
	//CustomFont.Draw(CustomFont.FontSize18, (int)StartX + 200, (int)StartBody + 270, 0xFF00FFFF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(155));


	//line gach chan 
	//pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 210, 200, 1); //-- Divisor

}

bool CCustomEventTime::EventEventTimeWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eEventTime_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eEventTime_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eEventTime_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eEventTime_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eEventTime_CLOSE].EventTick = GetTickCount();
	gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;

	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}
void CCustomEventTime::OpenInterFace()
{

	if (gInterface.CheckWindow(ObjWindow::CreateGuild) || gInterface.CheckWindow(ObjWindow::ChatWindow) || gInterface.CheckWindow(ObjWindow::FriendList) || gInterface.CheckWindow(ObjWindow::NPC_Dialog) || gInterface.CheckWindow(ObjWindow::MuHelper) || gInterface.CheckWindow(ObjWindow::Store) || gInterface.CheckWindow(ObjWindow::Warehouse) || gInterface.CheckWindow(ObjWindow::Trade) || gInterface.CheckWindow(ObjWindow::CashShop))
	{
		return;
	}

	if ((GetTickCount() - gInterface.Data[eEventTimePANEL_MAIN].EventTick) < 500)
	{
		return;
	}

	gInterface.Data[eEventTimePANEL_MAIN].EventTick = GetTickCount();


	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
	{
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;

		if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
		{
			pSetCursorFocus = false;
		}
		return;
	}

	gInterface.CloseCustomWindow();

	this->ClearCustomEventTime();

	PMSG_CUSTOM_EVENTTIME_SEND pMsg;

	pMsg.header.set(0xF3, 0xE8, sizeof(pMsg));

	DataSend((BYTE*)&pMsg, pMsg.header.size);
	gInterface.Data[eEventTimePANEL_MAIN].OnShow = true;

	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}

}

void CCustomEventTime::OpenWindow()
{

	if (gInterface.CheckWindow(ObjWindow::CreateGuild) || gInterface.CheckWindow(ObjWindow::ChatWindow) || gInterface.CheckWindow(ObjWindow::FriendList) || gInterface.CheckWindow(ObjWindow::NPC_Dialog) || gInterface.CheckWindow(ObjWindow::MuHelper) || gInterface.CheckWindow(ObjWindow::Store) || gInterface.CheckWindow(ObjWindow::Warehouse) || gInterface.CheckWindow(ObjWindow::Trade) || gInterface.CheckWindow(ObjWindow::CashShop))
	{
		return;
	}

	if ((GetTickCount() - gInterface.Data[eEventTimePANEL_MAIN].EventTick) < 500)
	{
		return;
	}

	gInterface.Data[eEventTimePANEL_MAIN].EventTick = GetTickCount();


	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
	{
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;

		if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
		{
			pSetCursorFocus = false;
		}
		return;
	}

	gInterface.CloseCustomWindow();

	this->ClearCustomEventTime();

	PMSG_CUSTOM_EVENTTIME_SEND pMsg;

	pMsg.header.set(0xF3, 0xE8, sizeof(pMsg));

	DataSend((BYTE*)&pMsg, pMsg.header.size);
	gInterface.Data[eEventTimePANEL_MAIN].OnShow = true;

	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}

}

void CCustomEventTime::Notice()
{
	if (gInterface.CheckWindow(ChatWindow) || gInterface.CheckWindow(Trade) || gInterface.CheckWindow(ChaosBox)) //-- 76
	{
		return;
	}

	PMSG_CUSTOM_EVENTTIME_SEND pMsg;
	pMsg.header.set(0xF3, 0xE8, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);

	this->EventTimeTickCount = GetTickCount();
	char text1[20];
	char text2[30];
	int totalseconds, hours, minutes, seconds, days, line = 0;

	for (int i = 0; i < this->count; i++)

	{
		if (this->gCustomEventTime[i].time <= -1){
			continue;
		}
		else if (this->gCustomEventTime[i].time == 0){
			wsprintf(text2, "Online");
		}
		else{
			totalseconds = this->gCustomEventTime[i].time;
			hours = totalseconds / 3600;
			minutes = (totalseconds / 60) % 60;
			seconds = totalseconds % 60;
			wsprintf(text2, gTime, minutes, seconds);
			if (hours > 23){
				days = hours / 24;
				wsprintf(text2, "%d day(s)+", days);
			}
			else{
				wsprintf(text2, gTime, minutes, seconds);
			}
		}
		DWORD Color;
		if (this->gCustomEventTime[i].time <= -1){
			Color = eRed2;
		}
		else if (this->gCustomEventTime[i].time == 0)
		{
			Color = eExcellent;
		}

		else if (this->gCustomEventTime[i].time < 300)
		{
			Color = eExcellent;
			float StartX = MAX_WIN_WIDTH;
			float StartY = MAX_WIN_HEIGHT;

			gCItemSetOption.ItemTooltipS15(StartX / 5 + 90, StartY / 4 + 280, 205, 20, 0.0, 0);

			gInterface.DrawFormat(eExcellent, StartX / 5 + 95, StartY / 4 + 284, 120, 1, this->m_CustomEventInfo[i].Name);

			gInterface.DrawFormat(eYellow, StartX / 5 + 210, StartY / 4 + 284, 100, 1, text2);

			gInterface.DrawFormat(eWhite, StartX / 5 + 254, StartY / 4 + 284, 100, 1, gSy2);

		}
		else
		{
			Color = eYellow;
		}

		line += 0;
	}
}


bool CCustomEventTime::EventNext(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eNextEvent].EventTick);
	DWORD Delay2 = (CurrentTick - gInterface.Data[ePrevEvent].EventTick);

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || NextEvent == -1)
	{
		return false;
	}

	if (!gInterface.IsWorkZone(eNextEvent))
	{
		return false;
	}

	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eNextEvent].OnClick = true;
		return true;
	}

	if (Delay < 100 || Delay2 < 100)
	{
		return false;
	}

	gInterface.Data[eNextEvent].OnClick = false;

	this->Page++;

	gInterface.Data[eNextEvent].EventTick = GetTickCount();


	return true;
}

bool CCustomEventTime::EventPrev(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[ePrevEvent].EventTick);
	DWORD Delay2 = (CurrentTick - gInterface.Data[eNextEvent].EventTick);

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || PreventEvent == -1)
	{
		return false;
	}

	if (!gInterface.IsWorkZone(ePrevEvent))
	{
		return false;
	}

	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[ePrevEvent].OnClick = true;
		return true;
	}

	if (Delay < 100 || Delay2 < 100)
	{
		return false;
	}

	gInterface.Data[ePrevEvent].OnClick = false;

	gInterface.Data[ePrevEvent].EventTick = GetTickCount();

	this->Page--;

	return true;
}


void CCustomEventTime::MOVE_EVENT(int MOVE_EVENT)
{
	MOVE_EVENT_REQ pRequest;
	pRequest.h.set(0xF3, 0x27, sizeof(pRequest));
	pRequest.MOVE_EVENT = MOVE_EVENT;
	DataSend((LPBYTE)&pRequest, pRequest.h.size);
	//DataSend((BYTE*)&pMsg, pMsg.header.size);*/
}

//========================================================================================================================
bool CCustomEventTime::EventDrawMenu_Op21(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT21].EventTick);
	// ----
	//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT21))
	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT21))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT21].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT21].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT21].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();
	MOVE_EVENT(1);
	gInterface.CloseEventTimeWindow();



	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op22(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT22].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT22))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT22].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT22].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT22].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(2);

	gInterface.CloseEventTimeWindow();


	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op23(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT23].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT23))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT23].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT23].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT23].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(3);

	gInterface.CloseEventTimeWindow();

	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op24(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT24].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT24))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT24].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT24].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT24].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(4);

	gInterface.CloseEventTimeWindow();

	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op25(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT25].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT25))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT25].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT25].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT25].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(5);

	gInterface.CloseEventTimeWindow();


	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op26(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT26].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT26))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT26].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT26].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT26].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(6);

	gInterface.CloseEventTimeWindow();
	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op27(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT27].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT27))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT27].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT27].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT27].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(7);

	gInterface.CloseEventTimeWindow();


	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op28(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT28].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT28))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT28].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT28].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT28].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(8);

	gInterface.CloseEventTimeWindow();


	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op29(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT29].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT29))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT29].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT29].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT29].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(9);

	gInterface.CloseEventTimeWindow();


	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op30(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT30].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT30))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT30].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT30].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT30].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(10);

	gInterface.CloseEventTimeWindow();


	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op31(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT31].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT31))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT31].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT31].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT31].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(11);

	gInterface.CloseEventTimeWindow();
	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op32(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT32].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT32))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT32].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT32].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT32].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(12);

	gInterface.CloseEventTimeWindow();


	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op33(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT33].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT33))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT33].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT33].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT33].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(13);

	gInterface.CloseEventTimeWindow();


	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op34(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT34].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT34))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT34].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT34].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT34].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(14);

	gInterface.CloseEventTimeWindow();
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op35(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT35].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT35))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT35].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT35].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT35].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(15);

	gInterface.CloseEventTimeWindow();
	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op36(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT36].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT36))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT36].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT36].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT36].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(16);

	gInterface.CloseEventTimeWindow();
	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op37(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT37].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT37))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT37].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT37].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT37].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(17);

	gInterface.CloseEventTimeWindow();

	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op38(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT38].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT38))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT38].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT38].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT38].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(18);

	gInterface.CloseEventTimeWindow();
	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op39(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT39].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT39))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT39].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT39].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT39].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(19);

	gInterface.CloseEventTimeWindow();
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op40(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT40].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT40))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT40].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT40].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT40].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(20);

	gInterface.CloseEventTimeWindow();

	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op41(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT41].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT41))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT41].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT41].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT41].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(21);

	gInterface.CloseEventTimeWindow();
	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op42(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT42].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT42))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT42].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT42].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT42].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(22);

	gInterface.CloseEventTimeWindow();


	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op43(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT43].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT43))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT43].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT43].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT43].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(23);

	gInterface.CloseEventTimeWindow();
	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op44(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT44].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT44))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT44].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT44].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT44].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(24);

	gInterface.CloseEventTimeWindow();
	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op45(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT45].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT45))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT45].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT45].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT45].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(25);

	gInterface.CloseEventTimeWindow();


	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op46(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT46].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT46))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT46].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT46].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT46].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(26);

	gInterface.CloseEventTimeWindow();
	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op47(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT47].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT47))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT47].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT47].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT47].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(27);

	gInterface.CloseEventTimeWindow();


	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op48(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT48].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT48))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT48].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT48].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT48].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(28);

	gInterface.CloseEventTimeWindow();
	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op49(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT49].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT49))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT49].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT49].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT49].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(29);

	gInterface.CloseEventTimeWindow();


	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op50(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT50].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT50))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT50].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT50].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT50].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(30);

	gInterface.CloseEventTimeWindow();

	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op51(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT51].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT51))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT51].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT51].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT51].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(31);

	gInterface.CloseEventTimeWindow();


	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op52(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT52].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT52))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT52].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT52].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT52].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(32);

	gInterface.CloseEventTimeWindow();

	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op53(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT53].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT53))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT53].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT53].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT53].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(33);

	gInterface.CloseEventTimeWindow();

	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op54(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT54].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT54))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT54].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT54].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT54].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(34);

	gInterface.CloseEventTimeWindow();
	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op55(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT55].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT55))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT55].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT55].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT55].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(35);

	gInterface.CloseEventTimeWindow();

	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op56(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT56].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT56))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT56].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT56].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT56].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(36);

	gInterface.CloseEventTimeWindow();
	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op57(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT57].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT57))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT57].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT57].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT57].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(37);

	gInterface.CloseEventTimeWindow();


	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op58(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT58].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT58))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT58].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT58].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT58].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(38);

	gInterface.CloseEventTimeWindow();
	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op59(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT59].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT59))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT59].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT59].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT59].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(39);

	gInterface.CloseEventTimeWindow();
	//	
	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op60(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT60].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT60))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT60].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT60].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT60].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(40);

	gInterface.CloseEventTimeWindow();

	// ----
	return false;

}
bool CCustomEventTime::EventDrawMenu_Op61(DWORD Event)
{
	//

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eMenu_OPT61].EventTick);
	// ----

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eMenu_OPT61))
		//if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(ObjectBtnIDs[btnEv]))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eMenu_OPT61].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eMenu_OPT61].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eMenu_OPT61].EventTick = GetTickCount();

	gInterface.CloseMenuWindow();

	MOVE_EVENT(41);

	gInterface.CloseEventTimeWindow();
	return false;

}

