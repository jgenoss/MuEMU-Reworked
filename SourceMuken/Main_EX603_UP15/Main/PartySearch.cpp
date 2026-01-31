#include "stdafx.h"
#include "PartySearch.h"
#include "User.h"
#include "Interface.h"
#include "PartySearchSettings.h"
#include "Defines.h"
#include "Offset.h"

#if(PARTYSEARCH==1)

cPartySearch gPartySearch;

cPartySearch::cPartySearch(){
	this->ClearPartyList();
}

cPartySearch::~cPartySearch(){
}

void cPartySearch::loadBind(){
#if(PARTYSEARCH)
	gInterface.BindObject(ePARTYSETTINGS_MAIN, 0x7A5A, 222, 345, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_SYSTEM_ACTIVE, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_ONLY_GUILD, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_ONE_CLASS, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_DARK_WIZARD, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_DARK_KNIGHT, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_ELF, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_MAGIC_GLADIATOR, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_DARK_LORD, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_SUMMONER, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_RAGE_FIGHTER, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_LEVEL_MINUS, 0x7C0D, 16, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_LEVEL_PLUS, 0x7AA4, 16, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_OK, 0x7A5B, 54, 30, -1, -1);
	gInterface.BindObject(ePARTYSEARCH_MAIN, 0x7A5A, 222, 345, -1, -1);
	gInterface.BindObject(ePARTYSEARCH_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(ePARTYSEARCH_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(ePARTYSEARCH_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(ePARTYSEARCH_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(ePARTYSEARCH_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(ePARTYSEARCH_LEFT, 0x7E56, 20, 23, -1, -1);
	gInterface.BindObject(ePARTYSEARCH_RIGHT, 0x7E57, 20, 23, -1, -1);
#endif
}

void cPartySearch::ClearPartyList(){
	for (int i = 0; i<MAX_PARTYLIST; i++){
		this->gPartyList[i].Index = 0xFFFF;
		memset(&this->gPartyList[i].Name, 0, sizeof(this->gPartyList[i].Name));
		this->gPartyList[i].Map = -1;
		this->gPartyList[i].X = -1;
		this->gPartyList[i].Y = -1;
		this->gPartyList[i].Count = -1;
		this->gPartyList[i].ButtonActive = true;
	}
	this->Page = 0;
	this->CountPages = 0;
	this->ListsCount = 0;
}

void cPartySearch::InsertPartyList(PMSG_PARTYSEARCH_PARTYLIST* lpInfo){
	memcpy(this->gPartyList[this->ListsCount].Name, lpInfo->Name, sizeof(this->gPartyList[this->ListsCount].Name));
	this->gPartyList[this->ListsCount].Map = lpInfo->Map;
	this->gPartyList[this->ListsCount].X = lpInfo->X;
	this->gPartyList[this->ListsCount].Y = lpInfo->Y;
	this->gPartyList[this->ListsCount].Level = lpInfo->Level;
	this->gPartyList[this->ListsCount].DarkWizard = lpInfo->DarkWizard;
	this->gPartyList[this->ListsCount].DarkKnight = lpInfo->DarkKnight;
	this->gPartyList[this->ListsCount].Elf = lpInfo->Elf;
	this->gPartyList[this->ListsCount].MagicGladiator = lpInfo->MagicGladiator;
	this->gPartyList[this->ListsCount].DarkLord = lpInfo->DarkLord;
	this->gPartyList[this->ListsCount].Summoner = lpInfo->Summoner;
	this->gPartyList[this->ListsCount].RageFighter = lpInfo->RageFighter;
	this->gPartyList[this->ListsCount].OnlyGuild = lpInfo->OnlyGuild;
	this->gPartyList[this->ListsCount].IsSameGuild = lpInfo->IsSameGuild;
	this->gPartyList[this->ListsCount].Count = lpInfo->Count;
	this->gPartyList[this->ListsCount].Index = this->ListsCount;
	this->ListsCount++;
}

PARTYLIST* cPartySearch::GetPartyList(int index){
	if (this->gPartyList[index].Index == 0xFFFF){
		return 0;
	}
	this->CountPages = ((this->ListsCount - 1) / 10) + 1;
	if (this->CountPages <= 0){
		this->CountPages = 1;
	}
	for (int i = 0; i<this->ListsCount; i++){
		if (strcmp(this->gPartyList[i].Name, gObjUser.lpPlayer->Name) == 0){
			gPartySearchSettings.m_SystemActive = true;
			break;
		}
	}
	switch (gObjUser.lpPlayer->Class & 7){
	    case 0:{
		    if (this->gPartyList[index].DarkWizard == false){
			    this->gPartyList[index].ButtonActive = false;
			}
	    }
		break;
	    case 1:{
		    if (this->gPartyList[index].DarkKnight == false){
			    this->gPartyList[index].ButtonActive = false;
			}
	    }
		break;
	    case 2:{
			if (this->gPartyList[index].Elf == false){
				this->gPartyList[index].ButtonActive = false;
			}
	    }
		break;
        case 3:{
			if (this->gPartyList[index].MagicGladiator == false){
				this->gPartyList[index].ButtonActive = false;
			}
	    }
		break;
	    case 4:{
			if (this->gPartyList[index].DarkLord == false){
				this->gPartyList[index].ButtonActive = false;
			}
	    }
		break;
	    case 5:{
			if (this->gPartyList[index].Summoner == false){
				this->gPartyList[index].ButtonActive = false;
			}
	    }
		break;
	    case 6:{
			if (this->gPartyList[index].RageFighter == false){
				this->gPartyList[index].ButtonActive = false;
			}
	    }
		break;
	}
	if (gPartyList[index].OnlyGuild == true && gPartyList[index].IsSameGuild == false){
		this->gPartyList[index].ButtonActive = false;
	}
	if (gPartyList[index].Count >= 10){
		gPartyList[index].ButtonActive = false;
	}
	if (*(DWORD*)(MAIN_PARTY_MEMBER_COUNT) > 0){
		gPartyList[index].ButtonActive = false;
	}
	if (gObjUser.lpPlayer->Level > gPartyList[index].Level){
		gPartyList[index].ButtonActive = false;
	}
	if (gPartySearchSettings.m_SystemActive == true){
		gPartyList[index].ButtonActive = false;
	}
	return &this->gPartyList[index];
}

void cPartySearch::SendPartyRequest(int index){
	PARTYLIST* info = gPartySearch.GetPartyList(index);
	if (info == 0){
		return;
	}
	PMSG_PARTY_REQ_SEND pMsg;
	pMsg.header.set(0xF3, 0xF2, sizeof(pMsg));
	memcpy(pMsg.Name, info->Name, sizeof(pMsg.Name));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void cPartySearch::SwitchPartySettingsWindowState(){
	gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == true ? gInterface.Data[ePARTYSETTINGS_MAIN].Close() : gInterface.Data[ePARTYSETTINGS_MAIN].Open();
}

void cPartySearch::DrawPartySettingsWindow(){

	

	if (!gInterface.Data[ePARTYSETTINGS_MAIN].OnShow){
		return;
	}

	if ( gInterface.CheckWindow(Inventory)
	|| gInterface.CheckWindow(Character) //-- 13 & 16
	|| gInterface.CheckWindow(Warehouse) //-- 8
	|| gInterface.CheckWindow(Shop) //-- 12
	|| gInterface.CheckWindow(ChaosBox) //-- 9
	|| gInterface.CheckWindow(Trade) //-- 7
	|| gInterface.CheckWindow(Store) //-- 14
	|| gInterface.CheckWindow(OtherStore) //-- 15
	|| gInterface.CheckWindow(LuckyCoin1) //-- 60
	|| gInterface.CheckWindow(NPC_ChaosMix) 
	|| gInterface.CheckWindow(MoveList) 
	) //-- 76
	{
		gInterface.Data[ePARTYSETTINGS_MAIN].OnShow = false;
		return;
	}




	pSetCursorFocus = true;

	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 50.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	gInterface.DrawGUI(ePARTYSETTINGS_MAIN, StartX, StartY + 2);
	gInterface.DrawGUI(ePARTYSETTINGS_TITLE, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(ePARTYSETTINGS_FRAME, StartX, StartY + 67.0, 16);
	gInterface.DrawGUI(ePARTYSETTINGS_FOOTER, StartX, StartY);

	//pDrawGUFULL(0x9333, StartX - 10, StartY - 15, 250, 380, 0, 0, 1, 1, 1, 1, 0.0); // MENU



	gInterface.DrawGUI(ePARTYSETTINGS_CLOSE, StartX + MainWidth - gInterface.Data[ePARTYSETTINGS_CLOSE].Width + 2, 49);

	if (gInterface.IsWorkZone(ePARTYSETTINGS_CLOSE)){
		DWORD Color = eGray100;
		if (gInterface.Data[ePARTYSETTINGS_CLOSE].OnClick){
			Color = eGray150;
		}
		gInterface.DrawColoredGUI(ePARTYSETTINGS_CLOSE, gInterface.Data[ePARTYSETTINGS_CLOSE].X, gInterface.Data[ePARTYSETTINGS_CLOSE].Y, Color);
		gInterface.DrawToolTip(gInterface.Data[ePARTYSETTINGS_CLOSE].X + 5, gInterface.Data[ePARTYSETTINGS_CLOSE].Y + 25, "ÄÃ³ng");
	}
	gInterface.DrawFormat(eGold, StartX + 10, 60, 210, 3, "Cai dat");
	gInterface.DrawFormat(eWhite, StartX + 40, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 33, 200, 1, "KÃ­ch hoáº¡t");
	if (gPartySearchSettings.m_SystemActive == false){
		gInterface.DrawButton(ePARTYSETTINGS_SYSTEM_ACTIVE, ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 30, 0, 0);
	}else{
		gInterface.DrawButton(ePARTYSETTINGS_SYSTEM_ACTIVE, ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 30, 0, 15);
	}
	gInterface.DrawGUI(ePARTYSETTINGS_DIV, StartX, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 40);
	gInterface.DrawFormat(eWhite, StartX + 40, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 60, 200, 1, "Level cao nháº¥t");
	gInterface.DrawGUI(ePARTYSETTINGS_DIV, StartX, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 67);
	gInterface.DrawToolTip(StartX + 174, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 62, "%d", gPartySearchSettings.m_Level);
	if (gPartySearchSettings.m_SystemActive == 0){
		this->DrawColoredButton(ePARTYSETTINGS_LEVEL_MINUS, StartX + 150, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 0, eGray150);
	}else{
		gInterface.DrawButton(ePARTYSETTINGS_LEVEL_MINUS, StartX + 150, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 0);
		if (gInterface.IsWorkZone(ePARTYSETTINGS_LEVEL_MINUS)){
			if (gInterface.Data[ePARTYSETTINGS_LEVEL_MINUS].OnClick){
				gInterface.DrawButton(ePARTYSETTINGS_LEVEL_MINUS, StartX + 150, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 16);
			}
		}
	}
	if (gPartySearchSettings.m_SystemActive == 0){
		DrawColoredButton(ePARTYSETTINGS_LEVEL_PLUS, StartX + 193, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 0, eGray150);
	}else{
		gInterface.DrawButton(ePARTYSETTINGS_LEVEL_PLUS, StartX + 193, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 0);
		if (gInterface.IsWorkZone(ePARTYSETTINGS_LEVEL_PLUS)){
			if (gInterface.Data[ePARTYSETTINGS_LEVEL_PLUS].OnClick){
				gInterface.DrawButton(ePARTYSETTINGS_LEVEL_PLUS, StartX + 193, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 16);
			}
		}
	}
	gInterface.DrawFormat(eWhite, StartX + 40, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 87, 200, 1, "CÃ¹ng Guild");
	if (gPartySearchSettings.m_SystemActive){
		if (gPartySearchSettings.m_OnlyGuild == false){
			gInterface.DrawButton(ePARTYSETTINGS_ONLY_GUILD, ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 83, 0, 0);
		}else{
			gInterface.DrawButton(ePARTYSETTINGS_ONLY_GUILD, ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 83, 0, 15);
		}
	}else{
		gInterface.DrawButton(ePARTYSETTINGS_ONLY_GUILD, ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 83, 0, 30);
	}
	pDrawGUI(0x7B5E, StartX + 30, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 100, 82.0, 2.0);
	pDrawGUI(0x7B5E, StartX + 30 + 82, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 100, 82.0, 2.0);
	gInterface.DrawFormat(eWhite, StartX + 40, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 109, 200, 1, "CÃ¹ng Class");
	if (gPartySearchSettings.m_SystemActive){
		if (gPartySearchSettings.m_OneClass == false){
			gInterface.DrawButton(ePARTYSETTINGS_ONE_CLASS, ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 105, 0, 0);
		}else{
			gInterface.DrawButton(ePARTYSETTINGS_ONE_CLASS, ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 105, 0, 15);
		}
	}else{
		gInterface.DrawButton(ePARTYSETTINGS_ONE_CLASS, ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 105, 0, 30);
	}
	gInterface.DrawGUI(ePARTYSETTINGS_DIV, StartX, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 115);
	char szCharNames[7][32] ={"PhÃ¹ thá»§y","Chiáº¿n binh","TiÃªn ná»¯","Äáº¥u sÄ©","ChÃºa te","Thuáº­t sÄ©","Thiáº¿t binh"};
	int ObjectIDs[7] ={
		ePARTYSETTINGS_DARK_WIZARD,
		ePARTYSETTINGS_DARK_KNIGHT,
		ePARTYSETTINGS_ELF,
		ePARTYSETTINGS_MAGIC_GLADIATOR,
		ePARTYSETTINGS_DARK_LORD,
		ePARTYSETTINGS_SUMMONER,
		ePARTYSETTINGS_RAGE_FIGHTER
	};
	for (int i = 0; i<7; i++){
		gInterface.DrawFormat(eWhite, StartX + 40, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 135 + (i * 22), 200, 1, szCharNames[i]);
		bool ClassValue = 0;
		switch (i){
		case 0:
			ClassValue = gPartySearchSettings.m_DarkWizard;
			break;
		case 1:
			ClassValue = gPartySearchSettings.m_DarkKnight;
			break;
		case 2:
			ClassValue = gPartySearchSettings.m_Elf;
			break;
		case 3:
			ClassValue = gPartySearchSettings.m_MagicGladiator;
			break;
		case 4:
			ClassValue = gPartySearchSettings.m_DarkLord;
			break;
		case 5:
			ClassValue = gPartySearchSettings.m_Summoner;
			break;
		case 6:
			ClassValue = gPartySearchSettings.m_RageFighter;
			break;
		}
		if (gPartySearchSettings.m_SystemActive){
			if (ClassValue == false){
				gInterface.DrawButton(ObjectIDs[i], ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 131 + (i * 22), 0, 0);
			}else{
				gInterface.DrawButton(ObjectIDs[i], ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 131 + (i * 22), 0, 15);
			}
		}else{
			gInterface.DrawButton(ObjectIDs[i], ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 131 + (i * 22), 0, 30);
		}
		pDrawGUI(0x7B5E, StartX + 30, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 148 + (i * 22), 82.0, 2.0);
		pDrawGUI(0x7B5E, StartX + 30 + 82, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 148 + (i * 22), 82.0, 2.0);
	}
	gInterface.DrawGUI(ePARTYSETTINGS_DIV, StartX, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 290);
	gInterface.DrawButton(ePARTYSETTINGS_OK, StartX + gInterface.Data[ePARTYSETTINGS_MAIN].Width / 2 - gInterface.Data[ePARTYSETTINGS_OK].Width / 2, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 310, 0, 0);
	if (gInterface.IsWorkZone(ePARTYSETTINGS_OK)){
		int ScaleY = 30;
		if (gInterface.Data[ePARTYSETTINGS_OK].OnClick){
			ScaleY = 60;
		}
		gInterface.DrawButton(ePARTYSETTINGS_OK, StartX + gInterface.Data[ePARTYSETTINGS_MAIN].Width / 2 - gInterface.Data[ePARTYSETTINGS_OK].Width / 2, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 310, 0, ScaleY);
	}
}

bool cPartySearch::EventPartySettingsWindow_Main(DWORD Event){
	this->EventPartySettingsWindow_Close(Event);
	this->EventPartySettingsWindow_All(Event);
	return true;
}

bool cPartySearch::EventPartySettingsWindow_All(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	if (!gInterface.Data[ePARTYSETTINGS_MAIN].OnShow){
		return false;
	}
	if (gInterface.IsWorkZone(ePARTYSETTINGS_SYSTEM_ACTIVE)){
		DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSETTINGS_SYSTEM_ACTIVE].EventTick);
		if (Event == WM_LBUTTONDOWN){
			gInterface.Data[ePARTYSETTINGS_SYSTEM_ACTIVE].OnClick = true;
			return true;
		}
		gInterface.Data[ePARTYSETTINGS_SYSTEM_ACTIVE].OnClick = false;
		if (Delay < 500){
			return false;
		}
		gInterface.Data[ePARTYSETTINGS_SYSTEM_ACTIVE].EventTick = GetTickCount();
		gPartySearchSettings.m_SystemActive ^= 1;
		for (int i = 0; i<7; i++){
			gPartySearchSettings.m_SystemActive == true ? gPartySearchSettings.SetClassValue(i, true) : gPartySearchSettings.SetClassValue(i, false);
		}
	}
	if (gInterface.IsWorkZone(ePARTYSETTINGS_LEVEL_MINUS)){
		if (gPartySearchSettings.m_SystemActive == 0){
			return false;
		}
		DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSETTINGS_LEVEL_MINUS].EventTick);
		if (Event == WM_LBUTTONDOWN){
			gInterface.Data[ePARTYSETTINGS_LEVEL_MINUS].OnClick = true;
			return false;
		}
		gInterface.Data[ePARTYSETTINGS_LEVEL_MINUS].OnClick = false;
		if (Delay < 200){
			return false;
		}
		gInterface.Data[ePARTYSETTINGS_LEVEL_MINUS].EventTick = GetTickCount();
		gPartySearchSettings.m_Level -= 10;
		if (gPartySearchSettings.m_Level <= 0){
			gPartySearchSettings.m_Level = 0;
		}
	}
	if (gInterface.IsWorkZone(ePARTYSETTINGS_LEVEL_PLUS)){
		if (gPartySearchSettings.m_SystemActive == 0){
			return false;
		}
		DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSETTINGS_LEVEL_PLUS].EventTick);
		if (Event == WM_LBUTTONDOWN){
			gInterface.Data[ePARTYSETTINGS_LEVEL_PLUS].OnClick = true;
			return false;
		}
		gInterface.Data[ePARTYSETTINGS_LEVEL_PLUS].OnClick = false;
		if (Delay < 200){
			return false;
		}
		gInterface.Data[ePARTYSETTINGS_LEVEL_PLUS].EventTick = GetTickCount();
		gPartySearchSettings.m_Level += 10;
		if (gPartySearchSettings.m_Level >= 400){
			gPartySearchSettings.m_Level = 400;
		}
	}
	if (gInterface.IsWorkZone(ePARTYSETTINGS_ONLY_GUILD)){
		DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSETTINGS_ONLY_GUILD].EventTick);
		if (Event == WM_LBUTTONDOWN){
			gInterface.Data[ePARTYSETTINGS_ONLY_GUILD].OnClick = true;
			return true;
		}
		gInterface.Data[ePARTYSETTINGS_ONLY_GUILD].OnClick = false;
		if (Delay < 500){
			return false;
		}
		gInterface.Data[ePARTYSETTINGS_ONLY_GUILD].EventTick = GetTickCount();
		gPartySearchSettings.m_OnlyGuild ^= 1;
	}
	if (gInterface.IsWorkZone(ePARTYSETTINGS_ONE_CLASS)){
		DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSETTINGS_ONE_CLASS].EventTick);
		if (Event == WM_LBUTTONDOWN){
			gInterface.Data[ePARTYSETTINGS_ONE_CLASS].OnClick = true;
			return true;
		}
		gInterface.Data[ePARTYSETTINGS_ONE_CLASS].OnClick = false;
		if (Delay < 500){
			return false;
		}
		gInterface.Data[ePARTYSETTINGS_ONE_CLASS].EventTick = GetTickCount();
		gPartySearchSettings.m_OneClass ^= 1;
		for (int i = 0; i<7; i++){
			gPartySearchSettings.m_OneClass == false ? gPartySearchSettings.SetClassValue(i, true) : gPartySearchSettings.SetClassValue(i, false);
		}
	}
	if (gInterface.IsWorkZone(ePARTYSETTINGS_OK)){
		DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSETTINGS_OK].EventTick);
		if (Event == WM_LBUTTONDOWN){
			gInterface.Data[ePARTYSETTINGS_OK].OnClick = true;
			return false;
		}
		gInterface.Data[ePARTYSETTINGS_OK].OnClick = false;
		if (Delay < 500){
			return false;
		}
		gInterface.Data[ePARTYSETTINGS_OK].EventTick = GetTickCount();
		gPartySearchSettings.CGSendPartySearchAdd();
		this->SwitchPartySettingsWindowState();
	}
	int ObjectIDs[7] ={
		ePARTYSETTINGS_DARK_WIZARD,
		ePARTYSETTINGS_DARK_KNIGHT,
		ePARTYSETTINGS_ELF,
		ePARTYSETTINGS_MAGIC_GLADIATOR,
		ePARTYSETTINGS_DARK_LORD,
		ePARTYSETTINGS_SUMMONER,
		ePARTYSETTINGS_RAGE_FIGHTER
	};
	for (int i = 0; i<7; i++){
		if (gInterface.IsWorkZone(ObjectIDs[i])){
			DWORD Delay = (CurrentTick - gInterface.Data[ObjectIDs[i]].EventTick);
			if (Event == WM_LBUTTONDOWN){
				gInterface.Data[ObjectIDs[i]].OnClick = true;
				return true;
			}
			gInterface.Data[ObjectIDs[i]].OnClick = false;
			if (Delay < 500){
				return false;
			}
			gInterface.Data[ObjectIDs[i]].EventTick = GetTickCount();
			gPartySearchSettings.ChangeClassValue(i);
			if (gPartySearchSettings.m_OneClass == true){
				gPartySearchSettings.m_OneClass = false;
			}
		}
	}
	return false;
}

bool cPartySearch::EventPartySettingsWindow_Close(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSETTINGS_CLOSE].EventTick);
	if (!gInterface.Data[ePARTYSETTINGS_MAIN].OnShow || !gInterface.IsWorkZone(ePARTYSETTINGS_CLOSE)){
		return false;
	}
	if (Event == WM_LBUTTONDOWN){
		gInterface.Data[ePARTYSETTINGS_CLOSE].OnClick = true;
		return true;
	}
	gInterface.Data[ePARTYSETTINGS_CLOSE].OnClick = false;
	if (Delay < 500){
		return false;
	}
	gInterface.Data[ePARTYSETTINGS_CLOSE].EventTick = GetTickCount();
	gInterface.Data[ePARTYSETTINGS_MAIN].Close();
	return false;
}

void cPartySearch::DrawPartySearchWindow(){
	if (!gInterface.Data[ePARTYSEARCH_MAIN].OnShow){
		return;
	}
	pSetCursorFocus = true;


	if ( gInterface.CheckWindow(Inventory)
	|| gInterface.CheckWindow(Character) //-- 13 & 16
	|| gInterface.CheckWindow(Warehouse) //-- 8
	|| gInterface.CheckWindow(Shop) //-- 12
	|| gInterface.CheckWindow(ChaosBox) //-- 9
	|| gInterface.CheckWindow(Trade) //-- 7
	|| gInterface.CheckWindow(Store) //-- 14
	|| gInterface.CheckWindow(OtherStore) //-- 15
	|| gInterface.CheckWindow(LuckyCoin1) //-- 60
	|| gInterface.CheckWindow(NPC_ChaosMix) 
	|| gInterface.CheckWindow(MoveList) 
	) //-- 76
	{
		gInterface.Data[ePARTYSEARCH_MAIN].OnShow = false;
	}


	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 50.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	gInterface.DrawGUI(ePARTYSEARCH_MAIN, StartX, StartY + 2);
	gInterface.DrawGUI(ePARTYSEARCH_TITLE, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(ePARTYSEARCH_FRAME, StartX, StartY + 67.0, 16);
	gInterface.DrawGUI(ePARTYSEARCH_FOOTER, StartX, StartY);

	//pDrawGUFULL(0x9333, StartX - 10, StartY - 15, 250, 365, 0, 0, 1, 1, 1, 1, 0.0); // MENU

	gInterface.DrawGUI(ePARTYSEARCH_CLOSE, StartX + MainWidth - gInterface.Data[ePARTYSEARCH_CLOSE].Width + 2, 49);
	if (gInterface.IsWorkZone(ePARTYSEARCH_CLOSE)){
		DWORD Color = eGray100;
		if (gInterface.Data[ePARTYSEARCH_CLOSE].OnClick){
			Color = eGray150;
		}
		gInterface.DrawColoredGUI(ePARTYSEARCH_CLOSE, gInterface.Data[ePARTYSEARCH_CLOSE].X, gInterface.Data[ePARTYSEARCH_CLOSE].Y, Color);
		gInterface.DrawToolTip(gInterface.Data[ePARTYSEARCH_CLOSE].X + 5, gInterface.Data[ePARTYSEARCH_CLOSE].Y + 25, "ÄÃ³ng");
	}
	gInterface.DrawFormat(eGold, StartX + 10, 60, 210, 3, "TÃ¬m NhÃ³m");
	int x = 200;
	int y = 50;
	gInterface.DrawFormat(eWhite, StartX + 20, gInterface.Data[ePARTYSEARCH_MAIN].Y + 34, 80, 1, "Status:");
	if (gPartySearchSettings.m_SystemActive == false){
		gInterface.DrawFormat(eRed, StartX + 72, gInterface.Data[ePARTYSEARCH_MAIN].Y + 34, 20, 1, "OFF");
	}else{
		gInterface.DrawFormat(eShinyGreen, StartX + 72, gInterface.Data[ePARTYSEARCH_MAIN].Y + 34, 20, 1, "ON");
	}
	gInterface.DrawGUI(ePARTYSETTINGS_DIV, StartX, gInterface.Data[ePARTYSEARCH_MAIN].Y + 40);
	gInterface.DrawFormat(eWhite, StartX + 5, gInterface.Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Player");
	gInterface.DrawFormat(eWhite, StartX + 45, gInterface.Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Map");
	gInterface.DrawFormat(eWhite, StartX + 95, gInterface.Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "X");
	gInterface.DrawFormat(eWhite, StartX + 115, gInterface.Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Y");
	gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "SL");
	gInterface.DrawFormat(eWhite, StartX + 170, gInterface.Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "VÃ o");
	gInterface.DrawGUI(ePARTYSETTINGS_DIV, StartX, gInterface.Data[ePARTYSEARCH_MAIN].Y + 60);
	if (gPartySearch.CountPages>1){
		gInterface.DrawFormat(eGold, StartX + 104, 379, 20, 3, "%d/%d", gPartySearch.Page + 1, gPartySearch.CountPages);
	}
	if (gPartySearch.Page + 1 > 1){
		gInterface.DrawButton(ePARTYSEARCH_LEFT, StartX + 73, 372, 0, 0);
	}
	if (gPartySearch.Page + 1 < gPartySearch.CountPages){
		gInterface.DrawButton(ePARTYSEARCH_RIGHT, StartX + 73 + 60, 372, 0, 0);
	}
	int DrawnItems = 0;
	for (int i = 0; i<gPartySearch.ListsCount; i++){
		if (DrawnItems >= 10){
			break;
		}
		PARTYLIST* info = gPartySearch.GetPartyList(i + (10 * gPartySearch.Page));
		if (info == 0){
			continue;
		}
		pDrawGUI(0x7E98, StartX + 10, gInterface.Data[ePARTYSEARCH_MAIN].Y + 80 + (20 * i), 170, 21);
		gInterface.DrawFormat(eYellow, StartX + 15, gInterface.Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 1, info->Name);
		gInterface.DrawFormat(eWhite, StartX + 45, gInterface.Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, pGetMapName(info->Map));
		gInterface.DrawFormat(eWhite, StartX + 95, gInterface.Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, "%d", info->X);
		gInterface.DrawFormat(eWhite, StartX + 115, gInterface.Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, "%d", info->Y);
		gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, "%d / 10", info->Count);
		pDrawGUI(81521, StartX + 178, gInterface.Data[ePARTYSEARCH_MAIN].Y + 84 + (i * 20), 14, 14);
		if (info->ButtonActive == true){
			pDrawButton(0x7AA4, StartX + 203, gInterface.Data[ePARTYSEARCH_MAIN].Y + 82 + (i * 20), 16, 15, 0, 0);
		}
		int X = StartX + 203;
		int Y = gInterface.Data[ePARTYSEARCH_MAIN].Y + 82 + (i * 20);
		int MaxX = X + 16;
		int MaxY = Y + 15;
		if (info->ButtonActive == true){
			if (this->IsWorkZone(X, Y, MaxX, MaxY)){
				pDrawColorButton(0x7AA4, X, Y, 16, 15, 0, 16, eGray100);
			}
		}
		DrawnItems++;
	}
	DrawnItems = 0;
	for (int i = 0; i<gPartySearch.ListsCount; i++){
		if (DrawnItems >= 10){
			break;
		}
		PARTYLIST* info = gPartySearch.GetPartyList(i + (10 * gPartySearch.Page));
		if (info == 0){
			continue;
		}
		int X = StartX + 178;
		int Y = gInterface.Data[ePARTYSEARCH_MAIN].Y + 80 + (i * 20);
		int MaxX = X + 22;
		int MaxY = Y + 19;
		if (this->IsWorkZone(X, Y, MaxX, MaxY)){
			char szText[2048];
			sprintf(szText, "__________________\n\nLevel:%d\n", info->Level);
			if (info->DarkWizard == true){
				strcat(szText, "\nPhÃ¹ thá»§y");
			}
			if (info->DarkKnight == true){
				strcat(szText, "\nChiáº¿n binh");
			}
			if (info->Elf == true){
				strcat(szText, "\nTiÃªn ná»¯");
			}
			if (info->MagicGladiator == true){
				strcat(szText, "\nÄáº¥u sÄ©");
			}
			if (info->DarkLord == true){
				strcat(szText, "\nChÃºa te");
			}
			if (info->Summoner == true){
				strcat(szText, "\nThuáº­t sÄ©");
			}
			if (info->RageFighter == true){
				strcat(szText, "\nThiáº¿t binh");
			}
			if (info->OnlyGuild == true){
				strcat(szText, "\nCÃ¹ng Guild");
			}
			strcat(szText, "\n__________________");
			this->DrawToolTipEx(eWhite, StartX + 230, gInterface.Data[ePARTYSEARCH_MAIN].Y + 32 + (i * 20), 120, 30, 3, szText);
		}
		DrawnItems++;
	}
	if (gPartySearch.Page + 1 > 1){
		if (gInterface.IsWorkZone(ePARTYSEARCH_LEFT)){
			if (gInterface.Data[ePARTYSEARCH_LEFT].OnClick){
				gInterface.DrawButton(ePARTYSEARCH_LEFT, StartX + 73, 372, 0, 46);
				return;
			}
			gInterface.DrawButton(ePARTYSEARCH_LEFT, StartX + 73, 372, 0, 23);
		}
	}
	if (gPartySearch.Page + 1 < gPartySearch.CountPages){
		if (gInterface.IsWorkZone(ePARTYSEARCH_RIGHT)){
			if (gInterface.Data[ePARTYSEARCH_RIGHT].OnClick){
				gInterface.DrawButton(ePARTYSEARCH_RIGHT, StartX + 73 + 60, 372, 0, 46);
				return;
			}
			gInterface.DrawButton(ePARTYSEARCH_RIGHT, StartX + 73 + 60, 372, 0, 23);
		}
	}
}

void cPartySearch::EventPartySearchWindow_All(DWORD Event){
	float StartX = (MAX_WIN_WIDTH / 2) - (230.0 / 2);
	DWORD CurrentTick = GetTickCount();
	if (!gInterface.Data[ePARTYSEARCH_MAIN].OnShow){
		return;
	}
	if (gInterface.IsWorkZone(ePARTYSEARCH_CLOSE)){
		DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSEARCH_CLOSE].EventTick);
		if (Event == WM_LBUTTONDOWN){
			gInterface.Data[ePARTYSEARCH_CLOSE].OnClick = true;
			return;
		}
		gInterface.Data[ePARTYSEARCH_CLOSE].OnClick = false;
		if (Delay < 500){
			return;
		}
		gInterface.Data[ePARTYSEARCH_CLOSE].EventTick = GetTickCount();
		this->SwitchPartySearchWindowState();
	}
	if (gInterface.IsWorkZone(ePARTYSEARCH_LEFT) && gPartySearch.Page + 1 > 1){
		DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSEARCH_LEFT].EventTick);
		if (Event == WM_LBUTTONDOWN){
			gInterface.Data[ePARTYSEARCH_LEFT].OnClick = true;
			return;
		}
		gInterface.Data[ePARTYSEARCH_LEFT].OnClick = false;
		if (Delay < 100){
			return;
		}
		gInterface.Data[ePARTYSEARCH_LEFT].EventTick = GetTickCount();
		gPartySearch.Page--;
	}
	if (gInterface.IsWorkZone(ePARTYSEARCH_RIGHT) && gPartySearch.Page + 1 < gPartySearch.CountPages){
		DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSEARCH_RIGHT].EventTick);
		if (Event == WM_LBUTTONDOWN){
			gInterface.Data[ePARTYSEARCH_RIGHT].OnClick = true;
			return;
		}
		gInterface.Data[ePARTYSEARCH_RIGHT].OnClick = false;
		if (Delay < 100){
			return;
		}
		gInterface.Data[ePARTYSEARCH_RIGHT].EventTick = GetTickCount();
		gPartySearch.Page++;
	}
	int DrawnItems = 0;
	for (int i = 0; i<gPartySearch.ListsCount; i++){
		if (DrawnItems >= 10){
			break;
		}
		if (this->IsWorkZone(StartX + 203, gInterface.Data[ePARTYSEARCH_MAIN].Y + 82 + (i * 20), StartX + 203 + 16, gInterface.Data[ePARTYSEARCH_MAIN].Y + 82 + (i * 20) + 15)){
			DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSEARCH_RIGHT].EventTick);
			if (Event == WM_LBUTTONDOWN){
				gInterface.Data[ePARTYSEARCH_RIGHT].OnClick = true;
				return;
			}
			gInterface.Data[ePARTYSEARCH_RIGHT].OnClick = false;
			if (Delay < 100){
				return;
			}
			if (gPartySearch.gPartyList[i + (10 * gPartySearch.Page)].ButtonActive == false){
				return;
			}
			gInterface.Data[ePARTYSEARCH_RIGHT].EventTick = GetTickCount();
			gPartySearch.SendPartyRequest(i + (10 * gPartySearch.Page));
		}
	}
}

int cPartySearch::DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...){
	char Buff[2048];
	char Buff2[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	int LineCount = 0;
	strcpy(Buff2, Buff);
	char * Line = strtok(Buff2, "\n");
	while (Line != NULL){
		LineCount++;
		Line = strtok(NULL, "\n");
	}
	pSetBlend(1);
	glColor4f(0.0, 0.0, 0.0, 0.8);
	pDrawBarForm(PosX - 10, PosY, Width, LineCount * 10, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	gInterface.DrawFormat(eYellow170, PosX, PosY, Width, Align, Buff);
	return 0;
}

bool cPartySearch::IsWorkZone(float X, float Y, float MaxX, float MaxY){
	if ((gObjUser.m_CursorX < X || gObjUser.m_CursorX > MaxX)
		|| (gObjUser.m_CursorY < Y || gObjUser.m_CursorY > MaxY)){
		return false;
	}
	return true;
}

void cPartySearch::DrawColoredButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color){
	if (gInterface.Data[ObjectID].X == -1 || gInterface.Data[ObjectID].Y == -1){
		gInterface.Data[ObjectID].X = PosX;
		gInterface.Data[ObjectID].Y = PosY;
		gInterface.Data[ObjectID].MaxX = PosX + gInterface.Data[ObjectID].Width;
		gInterface.Data[ObjectID].MaxY = PosY + gInterface.Data[ObjectID].Height;
	}
	pDrawColorButton(gInterface.Data[ObjectID].ModelID, PosX, PosY,gInterface.Data[ObjectID].Width, gInterface.Data[ObjectID].Height, ScaleX, ScaleY, Color);
}

#endif