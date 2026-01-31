#include "stdafx.h"
#if(SKY_EVENT == 1)
#include "Util.h"
#include "GameMain.h"
#include "SkyEvent.h"
#include "Notice.h"
#include "Message.h"
#include "readscript.h"
#include "Monster.h"
#include "MonsterSetBase.h"
#include "MapServerManager.h"
#include "DSProtocol.h"
#include "Event.h"
#include "DSProtocol.h"
#include "ItemManager.h"
#include "NewsProtocol.h"
#include "MemScript.h"
#include "ScheduleManager.h"
#include "ServerInfo.h"
#include "SocketItemType.h"
#include "CashShop.h"
#include "CommandManager.h"
#include "NewCustomFunctions.h"
cSkyEvent SkyEvent;

BOOL SetPosMonsterSkyEvent(int aIndex, int PosTableNum){
	if (((aIndex<0) ? FALSE : (aIndex > MAX_OBJECT - 1) ? FALSE : TRUE) == FALSE){
		LogAdd(LOG_RED, "Lỗi : %s %d", __FILE__, __LINE__);
		return FALSE;
	}
	if (((PosTableNum<0) ? FALSE : (PosTableNum > OBJ_MAXMONSTER - 1) ? FALSE : TRUE) == FALSE){
		LogAdd(LOG_RED, "Lỗi : %s %d", __FILE__, __LINE__);
		return FALSE;
	}
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->PosNum = PosTableNum;
	lpObj->X = gMonsterSetBase.m_MonsterSetBaseInfo[PosTableNum].X;// Sửa chổ này
	lpObj->Y = gMonsterSetBase.m_MonsterSetBaseInfo[PosTableNum].Y;//Sửa chổ này
	lpObj->Map = gMonsterSetBase.m_MonsterSetBaseInfo[PosTableNum].Map;//Sửa chổ này
	lpObj->TX = lpObj->X;
	lpObj->TY = lpObj->Y;
	lpObj->OldX = lpObj->X;
	lpObj->OldY = lpObj->Y;
	lpObj->Dir = gMonsterSetBase.m_MonsterSetBaseInfo[PosTableNum].Dir;//Sửa chổ này
	lpObj->StartX = lpObj->X;
	lpObj->StartY = lpObj->Y;
	if (lpObj->Class == 44 || lpObj->Class == 53 || lpObj->Class == 54 || lpObj->Class == 55 || lpObj->Class == 56 || lpObj->Class == 492){
		//Empty
	}
	else if (lpObj->Class >= 78 && lpObj->Class <= 83){
		//Empty
	}
	return true;
}

BOOL gObjIsNewClass(LPOBJ lpObj){
	int Class = lpObj->DBClass;
	if (Class == DB_GRAND_MASTER || Class == DB_BLADE_MASTER || Class == DB_HIGH_ELF || Class == DB_DUEL_MASTER || Class == DB_DUEL_MASTER + 1 ||
		Class == DB_LORD_EMPEROR || Class == DB_LORD_EMPEROR + 1 || Class == DB_DIMENSION_MASTER || Class == DB_RAGEFIGHER_EVO ||
		Class == DB_RAGEFIGHER_EVO + 1){
		return 1;
	}
	else{
		return 0;
	}
}

int gObjMonsterAdd(WORD Type, BYTE Map, BYTE X, BYTE Y){
	if (gMonsterSetBase.m_count >= MAX_MSB_MONSTER){
		return -1;
	}
	if (gMapServerManager.CheckMapServer(Map) == FALSE){
		LogAdd(LOG_BLACK, "[MonsterAdd] Không Cần Load Qoái Vật for Map %d [%d,%d,%d]", Map, Type, X, Y);
		return -1;
	}
	gMonsterSetBase.m_count++;
	gMonsterSetBase.m_MonsterSetBaseInfo[gMonsterSetBase.m_count].Dis = 30;
	gMonsterSetBase.m_MonsterSetBaseInfo[gMonsterSetBase.m_count].Type = Type;
	gMonsterSetBase.m_MonsterSetBaseInfo[gMonsterSetBase.m_count].Map = Map;
	gMonsterSetBase.m_MonsterSetBaseInfo[gMonsterSetBase.m_count].TY = X;
	gMonsterSetBase.m_MonsterSetBaseInfo[gMonsterSetBase.m_count].TX = Y;
	gMonsterSetBase.m_MonsterSetBaseInfo[gMonsterSetBase.m_count].X = X;
	gMonsterSetBase.m_MonsterSetBaseInfo[gMonsterSetBase.m_count].Y = Y;
	gMonsterSetBase.m_MonsterSetBaseInfo[gMonsterSetBase.m_count].Value = 1;
	gMonsterSetBase.m_MonsterSetBaseInfo[gMonsterSetBase.m_count].Dir = 3;
	return gMonsterSetBase.m_count;
}

BOOL DeleteItemByLevel(int iIndex, DWORD itemId, BYTE ItemLevel){
	if (OBJMAX_RANGE(iIndex) == 0){
		return false;
	}
	for (BYTE ItemPos = INVENTORY_WEAR_SIZE; ItemPos < MAIN_INVENTORY_NORMAL_SIZE; ItemPos++){
		if (gObj[iIndex].Inventory[ItemPos].m_Index == itemId){
			if (gObj[iIndex].Inventory[ItemPos].m_Level == ItemLevel){
				gItemManager.InventoryDelItem(iIndex, ItemPos);
				gItemManager.GCItemDeleteSend(iIndex, ItemPos, 1);
				return 1;
			}
		}
	}
	return 0;
}

int ItemGetNumberMake1(int type, int index){
	int make;
	make = type*MAX_ITEM_TYPE + index;
	if (make < 0 || make >= MAX_ITEM){
		return -1;
	}
	if (ItemAttribute[make].Width < 1 || ItemAttribute[make].Height < 1){
		return -1;
	}
	return make;
}

BOOL SKYEVENT_MAP_RANGE(int Map, BYTE X, BYTE Y){
	if (Map != 10){
		return FALSE;
	}
	else{
		if (X >= 130)
			return TRUE;
	}
	return FALSE;
}

cSkyEvent::cSkyEvent(){
#if(GAMESERVER_TYPE==0)
	this->m_State = SKY_STATE_BLANK;
	this->m_RemainTime = 0;
	this->m_TargetTime = 0;
	this->m_TickCount = GetTickCount();
#endif
}

cSkyEvent::~cSkyEvent(){

}

void cSkyEvent::Init(){
#if(GAMESERVER_TYPE==0)
	if (this->Enabled == 0){
		this->SetState(SKY_STATE_BLANK);
	}
	else{
		this->SetState(SKY_STATE_EMPTY);
	}
	this->MonsterLoaded = 0;
#endif
}

void cSkyEvent::LoadData(char * FilePath){
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(FilePath);
	if (res.status != pugi::status_ok){
		ErrorMessageBox("File %s load fail. Lỗi: %s", FilePath, res.description());
		return;
	}
	for (int iLevel; iLevel < MAX_SKY_EVENT_LEVEL; iLevel++){
		for (int Stage = 0; Stage < MAX_SKY_EVENT_STAGES; Stage++){
			iLevel = 0;
			this->Level_Min[iLevel] = 0;
			this->Level_Max[iLevel] = 0;
			this->ExtraExp[iLevel][Stage] = 0;
			this->ItemWinType[iLevel] = 0;
			this->ItemWinIndex[iLevel] = 0;
			this->ItemWinLevel[iLevel] = 0;
			this->ItemWinDur[iLevel] = 0;
			this->ItemWinLuck[iLevel] = 0;
			this->ItemWinSkill[iLevel] = 0;
			this->ItemWinOpt[iLevel] = 0;
			this->ItemWinExc[iLevel] = 0;
			this->WCoinCWin[iLevel] = 0;
			this->WCoinPWin[iLevel] = 0;
			this->GoblinPointWin[iLevel] = 0;
		}
	}
	this->m_SkyEventTime.clear();
	//--
	pugi::xml_node oSkyEvent = file.child("SkyEvent");
	//--
	pugi::xml_node eSkyTime = oSkyEvent.child("EventTime");
	for (pugi::xml_node rSkyTime = eSkyTime.child("Time"); rSkyTime; rSkyTime = rSkyTime.next_sibling()){
		SKY_EVENT_START_TIME info;
		info.Year = rSkyTime.attribute("Year").as_int();
		info.Month = rSkyTime.attribute("Month").as_int();
		info.Day = rSkyTime.attribute("Day").as_int();
		info.DayOfWeek = rSkyTime.attribute("DayOfWeek").as_int();
		info.Hour = rSkyTime.attribute("Hour").as_int();
		info.Minute = rSkyTime.attribute("Minute").as_int();
		info.Second = rSkyTime.attribute("Second").as_int();
		this->m_SkyEventTime.push_back(info);
	}
	//-
	pugi::xml_node eSkyStage = oSkyEvent.child("EventStage");
	for (pugi::xml_node rSkyStage = eSkyStage.child("Stage"); rSkyStage; rSkyStage = rSkyStage.next_sibling()){
		this->Enabled = rSkyStage.attribute("Enabled").as_int();
		this->StageMinutes[0] = rSkyStage.attribute("StageMin0").as_int();
		this->StageMinutes[1] = rSkyStage.attribute("StageMin1").as_int();
		this->StageMinutes[2] = rSkyStage.attribute("StageMin2").as_int();
		this->Start = 0;
	}
	//-
	pugi::xml_node eSkyWin = oSkyEvent.child("EventWin");
	for (pugi::xml_node rSkyWin = eSkyWin.child("Win"); rSkyWin; rSkyWin = rSkyWin.next_sibling()){
		int iLevel = rSkyWin.attribute("iLevel").as_int();
		this->Level_Min[iLevel] = rSkyWin.attribute("LevelMin").as_int();
		this->Level_Max[iLevel] = rSkyWin.attribute("LevelMax").as_int();
		this->ExtraExp[iLevel][0] = rSkyWin.attribute("ExtraExpStage0").as_int();
		this->ExtraExp[iLevel][1] = rSkyWin.attribute("ExtraExpStage1").as_int();
		this->ExtraExp[iLevel][2] = rSkyWin.attribute("ExtraExpStage2").as_int();
		this->ItemWinType[iLevel] = rSkyWin.attribute("ItemType").as_int();
		this->ItemWinIndex[iLevel] = rSkyWin.attribute("ItemIndex").as_int();
		this->ItemWinLevel[iLevel] = rSkyWin.attribute("ItemLevel").as_int();
		this->ItemWinDur[iLevel] = rSkyWin.attribute("ItemDur").as_int();
		this->ItemWinLuck[iLevel] = rSkyWin.attribute("ItemLuck").as_int();
		this->ItemWinSkill[iLevel] = rSkyWin.attribute("ItemSkill").as_int();
		this->ItemWinOpt[iLevel] = rSkyWin.attribute("ItemOpt").as_int();
		this->ItemWinExc[iLevel] = rSkyWin.attribute("ItemExc").as_int();
		this->WCoinCWin[iLevel] = rSkyWin.attribute("WcoinC").as_int();
		this->WCoinPWin[iLevel] = rSkyWin.attribute("WcoinP").as_int();
		this->GoblinPointWin[iLevel] = rSkyWin.attribute("GPoint").as_int();
	}
}

void cSkyEvent::MainProc(){
#if(GAMESERVER_TYPE==0)
	DWORD elapsed = GetTickCount() - this->m_TickCount;
	if (elapsed < 1000){
		return;
	}
	this->m_TickCount = GetTickCount();
	this->m_RemainTime = (int)difftime(this->m_TargetTime, time(0));
	switch (this->m_State){
	case SKY_STATE_BLANK:
		this->ProcState_BLANK();
		break;
	case SKY_STATE_EMPTY:
		this->ProcState_EMPTY();
		break;
	case SKY_STATE_START:
		this->ProcState_START();
		break;
	}
#endif
}

void cSkyEvent::ProcState_BLANK(){

}

void cSkyEvent::ProcState_EMPTY(){
#if(GAMESERVER_TYPE==0)
	if (this->Start == 0){
		if (this->m_RemainTime <= 0){
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(1009));
			this->SetState(SKY_STATE_START);
		}
	}
#endif
}

void cSkyEvent::ProcState_START(){
	if (this->Start == 0){
		if (this->m_RemainTime <= 0){
			this->SetState(SKY_STATE_EMPTY);
		}
	}
}

void cSkyEvent::SetState(int state){
	this->m_State = state;
	switch (this->m_State){
	case SKY_STATE_BLANK:
		this->SetState_BLANK();
		break;
	case SKY_STATE_EMPTY:
		this->SetState_EMPTY();
		break;
	case SKY_STATE_START:
		this->SetState_START();
		break;
	}
}

void cSkyEvent::SetState_BLANK(){
	LogAdd(LOG_BLACK, "[SkyEvent (Thiên Giới)] SetState_BLANK");
}

void cSkyEvent::SetState_EMPTY(){
	if (this->Start == 1){
		return;
	}
	else{
		this->CheckSync();
	}
	LogAdd(LOG_BLACK, "[SkyEvent (Thiên Giới)] SetState_EMPTY");
}

void cSkyEvent::SetState_START(){
	if (this->Enabled == 1){
		this->StartEvent();
	}
	this->m_RemainTime = this->StageMinutes[3];
	this->m_TargetTime = (int)(time(0) + this->m_RemainTime);
}

void cSkyEvent::CheckSync(){
	if (this->m_SkyEventTime.empty() != 0)
	{
		this->SetState(SKY_STATE_BLANK);
		return;
	}
	CTime ScheduleTime;
	CScheduleManager ScheduleManager;
	for (std::vector<SKY_EVENT_START_TIME>::iterator it = this->m_SkyEventTime.begin(); it != this->m_SkyEventTime.end(); it++){
		ScheduleManager.AddSchedule(it->Year, it->Month, it->Day, it->Hour, it->Minute, it->Second, it->DayOfWeek);
	}
	if (ScheduleManager.GetSchedule(&ScheduleTime) == 0){
		this->SetState(SKY_STATE_BLANK);
		return;
	}
	this->m_RemainTime = (int)difftime(ScheduleTime.GetTime(), time(0));
	this->m_TargetTime = (int)ScheduleTime.GetTime();
	LogAdd(LOG_BLACK, "[SkyEvent (Thiên Giới)] Thời Gian Bắt Đầu Còn Lại [%d] Phút", this->m_RemainTime / 60);
}

int cSkyEvent::GetWinner(BYTE iLevel){
	int MaxKillMob = 0;
	int WinUser = -1;
	for (int iUser = 0; iUser < MAX_SKY_EVENT_SUB_LEVEL; iUser++){
		if (this->m_UserData[iLevel][iUser].m_Index > -1){
			int PlayerKillMobs = 0;
			for (int iStage = 0; iStage < MAX_SKY_EVENT_STAGES; iStage++){
				PlayerKillMobs += (this->m_UserData[iLevel][iUser].KillCount[iStage] * (iStage + 1));
			}
			if (PlayerKillMobs > MaxKillMob)
				MaxKillMob = PlayerKillMobs;
			WinUser = iUser;
		}
	}
	return WinUser;
}

int cSkyEvent::GetPlayerSubIndex(LPOBJ lpObj, BYTE iLevel){
	for (int iUser = 0; iUser < MAX_SKY_EVENT_SUB_LEVEL; iUser++){
		int m_Index = this->m_UserData[iLevel][iUser].m_Index;
		if (m_Index == lpObj->Index){
			return iUser;
		}
	}
	return -1;
}

int cSkyEvent::GetLevel(LPOBJ lpObj){
	int Err = -1;
	if ((this->Enabled == 1) && (this->Start == 1)){
		if ((lpObj->Map == MAP_ICARUS) && (lpObj->X >= 130)){
			int X = lpObj->X;
			int Y = lpObj->Y;
			if (X >= 130 && X <= 166){
				if (Y >= 188 && Y <= 228){/*Lvl 1*/
					return 0;
				}
				else if (Y >= 128 && Y <= 170){/*Lvl 3*/
					return 2;
				}
			}
			else if (X >= 193 && X <= 228){
				if (Y >= 188 && Y <= 228){/*Lvl 2*/
					return 1;
				}
				else if (Y >= 128 && Y <= 170){/*Lvl 4*/
					return 3;
				}
				else if (Y >= 68 && Y <= 111){/*Lvl 5*/
					return 4;
				}
			}
		}
	}
	return Err;
}

int cSkyEvent::MonsterDie(LPOBJ lpObj){
	int iLevel = this->GetLevel(lpObj);
	if (iLevel > -1){
		int iUser = this->GetPlayerSubIndex(lpObj, iLevel);
		if (iUser > -1){
			if (this->CurrentStage > 0){
				this->m_UserData[iLevel][iUser].KillCount[(this->CurrentStage - 1)]++;
				return (this->ExtraExp[iLevel][(this->CurrentStage - 1)]);
			}
		}
		else{
			LogAdd(LOG_EVENT, "Lỗi-L3 : [Sky Event (Thiên Giới)­] (%d) Không Phù Hớp Với Người Chơi (%d) %s",
				iLevel + 1, lpObj->Index, lpObj->Name);
		}
	}
	return 1;
}

void cSkyEvent::DropWinnerItem(int iLevel, int iUser, BYTE SocketBonus, LPBYTE SocketOptions){
	int iIndex = this->m_UserData[iLevel][iUser].m_Index;
	if (OBJMAX_RANGE(iIndex) == FALSE){
		return;
	}
	int iType = ItemGetNumberMake1(this->ItemWinType[iLevel], this->ItemWinIndex[iLevel]);
	GDCreateItemSend(gObj[iIndex].Index, 0xEB, gObj[iIndex].X, gObj[iIndex].Y, GET_ITEM(this->ItemWinType[iLevel],
		this->ItemWinIndex[iLevel]), this->ItemWinLevel[iLevel], 0, this->ItemWinSkill[iLevel], this->ItemWinLuck[iLevel],
		this->ItemWinOpt[iLevel],
		-1, this->ItemWinExc[iLevel], 0, 0, SocketBonus, SocketOptions, 0xFE, 0);
	SkyEvent.SendNotify(gObj[iIndex].Index, this->WCoinCWin[iLevel], this->WCoinPWin[iLevel], this->GoblinPointWin[iLevel]);
	gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(1010), &gObj[iIndex].Name);
	gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(1011), iLevel + 1);
}

void cSkyEvent::SendNotify(int aIndex, int WCoinC, int WCoinP, int GoblinPoint){
	LPOBJ lpObj = &gObj[aIndex];
	SDHP_CASH_SHOP_ADD_POINT_SAVE_SEND pMsg;
	pMsg.header.set(0x18, 0x30, sizeof(pMsg));
	pMsg.index = gObj[aIndex].Index;
	memcpy(pMsg.account, gObj[aIndex].Account, sizeof(pMsg.account));
	pMsg.AddWCoinC = WCoinC;
	pMsg.AddWCoinP = WCoinP;
	pMsg.AddGoblinPoint = GoblinPoint;
	gDataServerConnection.DataSend((BYTE*)&pMsg, sizeof(pMsg));
	if (WCoinC > 0){
		gNotice.NewNoticeSend(aIndex, 0, 0, 0, 0, 0, gMessage.GetMessage(1020), WCoinC);
		gCashShop.CGCashShopPointRecv(lpObj->Index);
	}
	if (WCoinP > 0){
		gNotice.NewNoticeSend(aIndex, 0, 0, 0, 0, 0, gMessage.GetMessage(1021), WCoinP);
		gCashShop.CGCashShopPointRecv(lpObj->Index);
	}
	if (GoblinPoint > 0){
		gNotice.NewNoticeSend(aIndex, 0, 0, 0, 0, 0, gMessage.GetMessage(1022), GoblinPoint);
		gCashShop.CGCashShopPointRecv(lpObj->Index);
	}
}

void cSkyEvent::MsgStringSend(LPSTR  szMsg, BYTE type){
	for (int n = OBJECT_START_USER; n < MAX_OBJECT; n++){
		if (gObj[n].Connected == OBJECT_ONLINE){
			if ((gObj[n].Type == OBJECT_USER) && (gObj[n].Map == MAP_ICARUS) && (gObj[n].X >= 130)){
				gNotice.GCNoticeSend(gObj[n].Index, 1, 0, 0, 0, 0, 0, szMsg);
			}
		}
	}
}

void cSkyEvent::ClearAllMonsters(){
	for (int iStage = 0; iStage < MAX_SKY_EVENT_STAGES; iStage++){
		for (int iLevel = 0; iLevel < MAX_SKY_EVENT_LEVEL; iLevel++){
			for (int MobCount = 0; MobCount < this->MonsterStageCount[iLevel][iStage]; MobCount++){
				if (this->m_MonsterData[iLevel][iStage][MobCount].ID >= 0){
					int aIndex = this->m_MonsterData[iLevel][iStage][MobCount].ID;
					if (gObj[aIndex].Class == this->m_MonsterData[iLevel][iStage][MobCount].Number &&
						SKYEVENT_MAP_RANGE(gObj[aIndex].Map, gObj[aIndex].X, gObj[aIndex].Y)){
						gObjDel(aIndex);
					}
					this->m_MonsterData[iLevel][iStage][MobCount].ID = -1;
				}
			}
		}
	}
}

void cSkyEvent::ClearMonsters(BYTE iLevel, BYTE iStage){
	if (this->Enabled == 1 && this->Start == 1){
		for (int MobCount = 0; MobCount < this->MonsterStageCount[iLevel][iStage]; MobCount++){
			if (this->m_MonsterData[iLevel][iStage][MobCount].ID >= 0){
				int aIndex = this->m_MonsterData[iLevel][iStage][MobCount].ID;
				if (gObj[aIndex].Class == this->m_MonsterData[iLevel][iStage][MobCount].Number &&
					SKYEVENT_MAP_RANGE(gObj[aIndex].Map, gObj[aIndex].X, gObj[aIndex].Y)){
					gObjDel(aIndex);
				}
				this->m_MonsterData[iLevel][iStage][MobCount].ID = -1;
			}
		}
	}
}

void cSkyEvent::SetMonsters(BYTE iLevel, BYTE iStage){
	if (this->Enabled == 1 && this->Start == 1){
		for (int MobCount = 0; MobCount < this->MonsterStageCount[iLevel][iStage]; MobCount++){
			int MobID = gObjAddMonster(MAP_ICARUS);
			if (MobID >= 0){
				this->m_MonsterData[iLevel][iStage][MobCount].ID = MobID;
				gObjSetMonster(MobID, gMonsterSetBase.m_MonsterSetBaseInfo[this->m_MonsterData[iLevel][iStage][MobCount].Pos].Type);
				SetPosMonsterSkyEvent(MobID, this->m_MonsterData[iLevel][iStage][MobCount].Pos);
				LPOBJ lpObj = &gObj[MobID];
				if (lpObj->Class == 275 && this->CurrentStage == 3){

				}
				else {
					gObj[MobID].Attribute = 62;
					gObj[MobID].DieRegen = 0;
					gObj[MobID].MaxRegenTime = 1000;
					gObj[MobID].LastCheckTick = GetTickCount();
				}
			}
		}
	}
}

void cSkyEvent::ReadMonsters(char * FilePath){
#if(SKY_EVENT == 1)
	if (this->Enabled == 1){
		int Token;
		if (FilePath == NULL || !strcmp(FilePath, "")){
			ErrorMessageBox("[Sky Event (Thiên Giới)] file load Lỗi - File Name Lỗi");
			return;
		}
		SMDFile = fopen(FilePath, "r");
		if (!SMDFile){
			ErrorMessageBox("[Sky Event (Thiên Giới)] file load Lỗi - fopen In: %s", FilePath);
			return;
		}
		for (int Stages = 0; Stages < MAX_SKY_EVENT_STAGES; Stages++){
			for (int Level = 0; Level < MAX_SKY_EVENT_LEVEL; Level++){
				this->MonsterStageCount[Level][Stages] = 0;
			}
		}
		for (int iL = 0; iL < MAX_SKY_EVENT_LEVEL; iL++){
			for (int iS = 0; iS < MAX_SKY_EVENT_STAGES; iS++){
				for (int iM = 0; iM <MAX_SKY_EVENT_STAGE_MOB_COUNT; iM++){
					this->m_MonsterData[iL][iS][iM].ID = -1;
					this->m_MonsterData[iL][iS][iM].Pos = -1;
					this->m_MonsterData[iL][iS][iM].Number = -1;
				}
			}
		}
		this->MonsterLoaded = 0;
		while (true){
			for (int iStages = 1; iStages < (MAX_SKY_EVENT_STAGES + 1); iStages++){
				int iType = GetToken();
				while (true){
					Token = GetToken();
					if (strcmp("end", TokenString) == 0){
						break;
					}
					SKYEVENT_INFO info;
					memset(&info, 0, sizeof(info));
					info.Level = TokenNumber;
					Token = GetToken();
					this->MobID = TokenNumber;
					Token = GetToken();
					info.X = TokenNumber;
					Token = GetToken();
					info.Y = TokenNumber;
					Token = GetToken();
					this->Count = TokenNumber;
					this->MonsterLoaded++;
					for (int i = 0; i < this->Count; i++){
						int MobCount = this->MonsterStageCount[(info.Level - 1)][(iStages - 1)];
						if (info.Level <= MAX_SKY_EVENT_LEVEL && iStages <= MAX_SKY_EVENT_STAGES && MobCount < MAX_SKY_EVENT_STAGE_MOB_COUNT){
							int MobPos = gObjMonsterAdd(this->MobID, 10, info.X, info.Y);
							if (MobPos >= 0){
								this->m_MonsterData[(info.Level - 1)][(iStages - 1)][MobCount].ID = -1;
								this->m_MonsterData[(info.Level - 1)][(iStages - 1)][MobCount].Pos = MobPos;
								this->m_MonsterData[(info.Level - 1)][(iStages - 1)][MobCount].Number = this->MobID;
								this->MonsterStageCount[(info.Level - 1)][(iStages - 1)]++;
							}
							else {
								LogAdd(LOG_EVENT, "[Sky Event (Thiên Giới)] - Không Thẻ Thêm Qoái Vật Vào Lvl:%d, Stage:%d, Count:%d [ID:%d:,X:%d,Y:%d] Pos:%d",
									info.Level, iStages, MobCount, this->MobID, info.X, info.Y, MobPos);
							}
						}
						else{
							LogAdd(LOG_EVENT, "[Sky Event (Thiên Giới)][Overflow] - Không Thẻ Thêm Qoái Vật Vào Lvl:%d, Stage:%d, Count:%d [ID:%d:,X:%d,Y:%d]",
								info.Level, iStages, MobCount, this->MobID, info.X, info.Y);
						}
					}
				}
			}
			break;
		}
		fclose(SMDFile);
		LogAdd(LOG_RED, "[Sky Event (Thiên Giới)] Monster Loaded: +(%d)", this->MonsterLoaded++);
	}
#endif
}

void cSkyEvent::StartEvent(){
	if (gServerInfo.SkyEnabled != 0){
		if ((this->Start == 0) && (this->Enabled == 1))
			_beginthread(cSkyEvent__InsideTrigger, 0, NULL);
	}
}

void cSkyEvent__InsideTrigger(void * lpParam){
	SkyEvent.Start = 1;
	SkyEvent.NPCEnabled = 1;
	char sBuf[1024] = { 0 };
	SkyEvent.CurrentStage = 0;
	BYTE ActiveLevelsSum = 0;
	for (int i = 5; i > 0; i--) {
		LogAdd(LOG_EVENT, "[Sky Event (Thiên Giới)] Sẽ Đóng Sau %d Phút", i);
		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(1012), i);
		Sleep(60000);
	}
	SkyEvent.NPCEnabled = 0;
	LogAdd(LOG_EVENT, "[Sky Event (Thiên Giới)­] Đã Đóng Cửa!");
	gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(1013));
	for (int iStages = 0; iStages < MAX_SKY_EVENT_STAGES; iStages++){
		SkyEvent.CurrentStage++;
		ActiveLevelsSum = 0;
		for (int iLevel = 0; iLevel < MAX_SKY_EVENT_LEVEL; iLevel++){
			int ActiveUsers = SkyEvent.CheckUsersAlive(iLevel);
			if (ActiveUsers > 0){
				if (iLevel > 0 && iStages > 0)
					SkyEvent.ClearMonsters((iLevel - 1), (iStages - 1));
				SkyEvent.SetMonsters(iLevel, iStages);
				ActiveLevelsSum++;
			}
			else{
				if (iLevel > 0 && iStages > 0)
					SkyEvent.ClearMonsters((iLevel - 1), (iStages - 1));
				SkyEvent.ClearLevelData(iLevel);
			}
			SkyEvent.SendUserExpInfo(iLevel);
		}
		SkyEvent.MsgStringSend(gMessage.GetMessage(1019), 0x01);
		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(1014), iStages + 1, SkyEvent.StageMinutes[iStages]);
		if (ActiveLevelsSum > 0)
			Sleep(SkyEvent.StageMinutes[iStages] * 60000);
		else
			break;
	}
	SkyEvent.ClearAllMonsters();
	for (int iLevel = 0; iLevel < MAX_SKY_EVENT_LEVEL; iLevel++){
		int ActiveUsers = SkyEvent.CheckUsersAlive(iLevel);
		if (ActiveUsers > 0){
			int WinUser = SkyEvent.GetWinner(iLevel);
			if (WinUser > -1)
				SkyEvent.DropWinnerItem(iLevel, WinUser, 0, 0);
		}
	}
	LogAdd(LOG_EVENT, "[Sky Event (Thiên Giới)­] Kết Thúc");
	//gNotice.GCNoticeSendToAll(0,0,0,0,0,0,gMessage.GetMessage(1014));
	for (int i = 2; i > 0; i--){
		wsprintf(sBuf, "%d Sẽ Move Về Devias", i * 10);
		SkyEvent.MsgStringSend(sBuf, 0x01);
		Sleep(10000);
	}
	SkyEvent.ExitPlayers();
	for (int iLevel = 0; iLevel < MAX_SKY_EVENT_LEVEL; iLevel++){
		SkyEvent.ClearLevelData(iLevel);
	}
	SkyEvent.Start = 0;
	_endthread();
}

void cSkyEvent::ExitPlayers(){
	for (int n = OBJECT_START_USER; n < MAX_OBJECT; n++){
		if (gObj[n].Connected == OBJECT_ONLINE){
			if ((gObj[n].Type == OBJECT_USER) && (gObj[n].Map == MAP_ICARUS) && (gObj[n].X >= 130)){
				this->Teleport(&gObj[n], 255);
			}
		}
	}
}

void cSkyEvent::SendUserExpInfo(BYTE iLevel){
	for (int iUser = 0; iUser < MAX_SKY_EVENT_SUB_LEVEL; iUser++){
		int Stage = MAX_SKY_EVENT_STAGES;
		int m_Index = this->m_UserData[iLevel][iUser].m_Index;
		if (m_Index != -1){
			if (gObj[m_Index].Connected >= OBJECT_CONNECTED){
				if (this->m_UserData[iLevel][iUser].DBNumber == gObj[m_Index].DBNumber){
					if ((gObj[this->m_UserData[iLevel][iUser].m_Index].Map == MAP_ICARUS) && (gObj[this->m_UserData[iLevel][iUser].m_Index].X >= 130)) {
						if (this->CurrentStage == 1){
							gNotice.NewNoticeSend(this->m_UserData[iLevel][iUser].m_Index, 0, 0, 0, 0, 0, "[Sky Event (Thiên Giới)] - Kinh Nghiệm: %d", this->ExtraExp[iLevel][0]);
						}
						if (this->CurrentStage == 2){
							gNotice.NewNoticeSend(this->m_UserData[iLevel][iUser].m_Index, 0, 0, 0, 0, 0, "[Sky Event (Thiên Giới)] - Kinh Nghiệm: %d", this->ExtraExp[iLevel][1]);
						}
						if (this->CurrentStage == 3){
							gNotice.NewNoticeSend(this->m_UserData[iLevel][iUser].m_Index, 0, 0, 0, 0, 0, "[Sky Event (Thiên Giới)] - Kinh Nghiệm: %d", this->ExtraExp[iLevel][2]);
						}

					}
				}
			}
		}
	}
}

int cSkyEvent::CheckUsersAlive(BYTE iLevel){
	int UserCount = 0;
	for (int iUser = 0; iUser < MAX_SKY_EVENT_SUB_LEVEL; iUser++){
		int m_Index = this->m_UserData[iLevel][iUser].m_Index;
		if (m_Index != -1){
			if (gObj[m_Index].Connected >= OBJECT_CONNECTED){
				if (this->m_UserData[iLevel][iUser].DBNumber != gObj[m_Index].DBNumber){
					this->RemoveUser(iLevel, iUser);
				}
				else{
					if ((gObj[this->m_UserData[iLevel][iUser].m_Index].Map == MAP_ICARUS) && (gObj[this->m_UserData[iLevel][iUser].m_Index].X >= 130)) {
						UserCount++;
					}
					else {
						this->RemoveUser(iLevel, iUser);
					}
				}
			}
			else{
				this->RemoveUser(iLevel, iUser);
			}
		}
	}
	return UserCount;
}

void cSkyEvent::RemoveUser(BYTE iLevel, int iUser){
	this->m_UserData[iLevel][iUser].m_Index = -1;
	this->m_UserData[iLevel][iUser].DBNumber = -1;
	for (int iStages = 0; iStages < MAX_SKY_EVENT_STAGES; iStages++){
		this->m_UserData[iLevel][iUser].KillCount[iStages] = 0;
	}
}

void cSkyEvent::ClearLevelData(BYTE iLevel){
	this->PlayerCount[iLevel] = 0;
	for (int iUser = 0; iUser < MAX_SKY_EVENT_SUB_LEVEL; iUser++){
		this->m_UserData[iLevel][iUser].m_Index = -1;
		this->m_UserData[iLevel][iUser].DBNumber = -1;
		for (int iStages = 0; iStages < MAX_SKY_EVENT_STAGES; iStages++){
			this->m_UserData[iLevel][iUser].KillCount[iStages] = 0;
		}
	}
}

void cSkyEvent::Teleport(LPOBJ lpObj, BYTE iLevel){
	int rNum = rand() % 5;
	switch (iLevel){
	case 0:{
		gObjTeleport(lpObj->Index, 10, 148 + rNum, 209 + rNum);
	}break;
	case 1:{
		gObjTeleport(lpObj->Index, 10, 210 + rNum, 209 + rNum);
	}break;
	case 2:{
		gObjTeleport(lpObj->Index, 10, 147 + rNum, 148 + rNum);
	}break;
	case 3:{
		gObjTeleport(lpObj->Index, 10, 211 + rNum, 148 + rNum);
	}break;
	case 4:{
		gObjTeleport(lpObj->Index, 10, 210 + rNum, 88 + rNum);
	}break;
	case 255:{
		gObjMoveGate(lpObj->Index, 22);
	}break;
	}
}

int cSkyEvent::CheckEnterLevel(int iIndex){
	if (OBJMAX_RANGE(iIndex) == FALSE){
		return -1;
	}
	if (gObj[iIndex].Type != OBJECT_USER || gObj[iIndex].Connected <= OBJECT_LOGGED){
		return -1;
	}
	if (gObjIsNewClass(&gObj[iIndex]) == 1){
		return (MAX_SKY_EVENT_LEVEL - 1);
	}
	int pLevel = gObj[iIndex].Level;
	for (int iLevel = 0; iLevel < MAX_SKY_EVENT_LEVEL; iLevel++){
		if (pLevel >= Level_Min[iLevel] && pLevel <= Level_Max[iLevel])
			return iLevel;
		LogAdd(LOG_BLACK, "[Sky Event (Thiên Giới)] Level %d", iLevel + 1);
	}
	return -1;
}

BOOL cSkyEvent::NpcTalk(LPOBJ lpNpc, LPOBJ lpObj){
	int iIndex = lpObj->Index;
	if ((this->Enabled == 1) && (this->Start == 1) && (this->NPCEnabled == 1)){
		int iLevel = this->CheckEnterLevel(iIndex);
		if (iLevel > -1){
			if (this->PlayerCount[iLevel] < MAX_SKY_EVENT_SUB_LEVEL){
				if (DeleteItemByLevel(iIndex, 0x1C33, iLevel + 1) == 1){ // Chistmas Star item 14-51 (0x65B9)
					lpObj->Interface.use = 0;
					this->AddUser(iLevel, iIndex, lpObj);
					this->Teleport(&gObj[iIndex], iLevel);
					return 1;
				}
				else{
					gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(1016), iLevel + 1, iLevel + 1);
				}
			}
			else{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(1017), iLevel + 1);
			}
		}
	}
	return 0;
}

void cSkyEvent::AddUser(BYTE iLevel, int iIndex, LPOBJ lpObj){
	int iUser = this->PlayerCount[iLevel];
	this->m_UserData[iLevel][iUser].m_Index = iIndex;
	this->m_UserData[iLevel][iUser].DBNumber = gObj[iIndex].DBNumber;
	for (int iStages = 0; iStages < MAX_SKY_EVENT_STAGES; iStages++){
		this->m_UserData[iLevel][iUser].KillCount[iStages] = 0;
	}
	this->PlayerCount[iLevel]++;
	gNotice.NewNoticeSend(lpObj->Index, 0, 0, 0, 0, 0, gMessage.GetMessage(1018), this->PlayerCount[iLevel]);
	LogAdd(LOG_BLACK, "[Sky Event (Thiên Giới)­] [Level %d] - Số Người Tham Gia %d", iLevel + 1, this->PlayerCount[iLevel]);
}
#endif
