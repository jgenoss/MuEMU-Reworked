#include "stdafx.h"
#if(THANMA)
#include "BEventThanMa.h"
#include "Guild.h"
#include "EffectManager.h"
#include "Notice.h"
#include "ObjectManager.h"
#include "CashShop.h"
#include "Gate.h"
#include "ScheduleManager.h"
#include "MemScript.h"
#include "DSProtocol.h"
#include "ItemManager.h"
#include "Message.h"
#include "ServerInfo.h"
#include "Util.h"
#include "DucTuong.h"
#include "DanhHieu.h"

CThanMaChien gThanMaChien;

CThanMaChien::CThanMaChien()
{
	this->m_TickCount = GetTickCount();
	this->m_State = 0;
	this->m_RemainTime = 0;
	this->m_StandTime = 0;
	this->m_CloseTime = 0;
	this->m_TickCount = 0;
	this->m_WarningTime = 0;
	this->m_EventTime = 0;


	this->ScoreBlue = 0;
	this->ScoreRed = 0;
	this->TotalPlayer = 0;

	this->Coin1 = 0;
	this->Coin2 = 0;
	this->Coin3 = 0;

	this->CleanUser();

}

CThanMaChien::~CThanMaChien()
{

}

void CThanMaChien::Init()
{
	if (this->m_ThanMaChienEnable == 0)
	{
		this->SetState(TM_EVENT_STATE_BLANK);
	}
	else
	{
		this->SetState(TM_EVENT_STATE_EMPTY);
	}
}
void CThanMaChien::ClearConfigCache()
{
	this->m_TickCount = GetTickCount();
	this->m_State = 0;
	this->m_RemainTime = 0;
	this->m_StandTime = 0;
	this->m_CloseTime = 0;
	this->m_TickCount = 0;
	this->m_WarningTime = 0;
	this->m_EventTime = 0;


	this->ScoreBlue = 0;
	this->ScoreRed = 0;
	this->TotalPlayer = 0;

	this->Coin1 = 0;
	this->Coin2 = 0;
	this->Coin3 = 0;

	this->CleanUser();

	//===Mess Clear
	this->m_MessageInfoBP.clear();
	this->m_TMStartTime.clear();
	this->m_ThanMaChienEnable = 0;
	this->m_ThanMaChienNPC = 0;
	this->m_ThanMaChienNPCMap = 0;
	this->m_ThanMaChienNPCX = 0;
	this->m_ThanMaChienNPCY = 0;
	this->m_ThanMaChienNPCDir = 0;
	this->BonusKill[0] = 0;
	this->BonusKill[1] = 0;
	this->BonusKill[2] = 0;
	for (int stt = 0; stt < 10; stt++)
	{
		this->mIndexRank[stt] = -1;
	}
}
void CThanMaChien::Clear()
{
	this->ScoreBlue = 0;
	this->ScoreRed = 0;
	this->TotalPlayer = 0;

	this->CleanUser();
}

void CThanMaChien::Load(char* FilePath)
{

	//Clear
	this->ClearConfigCache();
	//=============


	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(FilePath);
	if (res.status != pugi::status_ok) {
		ErrorMessageBox("File %s load fail. Error: %s", FilePath, res.description());
		return;
	}

	//--
	pugi::xml_node oEventThanMa = file.child("EventThanMa");
	//--
	//==== Load Time
	pugi::xml_node eThanMaTime = oEventThanMa.child("EventTime");
	for (pugi::xml_node rThanMaTime = eThanMaTime.child("Time"); rThanMaTime; rThanMaTime = rThanMaTime.next_sibling()) {
		TM_TIME info;
		info.Year = rThanMaTime.attribute("Year").as_int();
		info.Month = rThanMaTime.attribute("Month").as_int();
		info.Day = rThanMaTime.attribute("Day").as_int();
		info.DayOfWeek = rThanMaTime.attribute("DayOfWeek").as_int();
		info.Hour = rThanMaTime.attribute("Hour").as_int();
		info.Minute = rThanMaTime.attribute("Minute").as_int();
		info.Second = rThanMaTime.attribute("Second").as_int();
		this->m_TMStartTime.push_back(info);
	}
	//-Config
	pugi::xml_node eEvenNPC = oEventThanMa.child("EvenNPC");
	this->m_ThanMaChienEnable = eEvenNPC.attribute("EnabledEvent").as_int();
	this->m_ThanMaChienNPC = eEvenNPC.attribute("NPCClass").as_int();
	this->m_ThanMaChienNPCMap = eEvenNPC.attribute("NPCMap").as_int();
	this->m_ThanMaChienNPCX = eEvenNPC.attribute("NPCX").as_int();
	this->m_ThanMaChienNPCY = eEvenNPC.attribute("NPCY").as_int();
	this->m_ThanMaChienNPCDir = eEvenNPC.attribute("NPCDir").as_int();

	//-Config Time
	pugi::xml_node eEventStage = oEventThanMa.child("EventStage");
	this->m_WarningTime = eEventStage.attribute("WarningTime").as_int();
	this->m_StandTime = eEventStage.attribute("StandTime").as_int();
	this->m_EventTime = eEventStage.attribute("EventTime").as_int();
	this->m_CloseTime = eEventStage.attribute("CloseTime").as_int();

	//-Config All
	pugi::xml_node eEvenConfigAll = oEventThanMa.child("EventConfig");
	this->EventMap = eEvenConfigAll.attribute("EventMap").as_int();
	this->WaitingGate = eEvenConfigAll.attribute("WaitingGate").as_int();
	this->TEAMTHIENTHANGate = eEvenConfigAll.attribute("AngelTeamGate").as_int();
	this->TEAMACQUYGate = eEvenConfigAll.attribute("DevilTeamGate").as_int();
	this->SetSkin = eEvenConfigAll.attribute("SetSkin").as_int();
	this->m_ThanMaChienMinUsers = eEvenConfigAll.attribute("MinUser").as_int();
	this->m_ThanMaChienMaxUsers = eEvenConfigAll.attribute("MaxUser").as_int();
	if (this->m_ThanMaChienMaxUsers > MAX_THANMACHIEN_USER) { this->m_ThanMaChienMaxUsers = MAX_THANMACHIEN_USER; }

	//-Config Yeu Cau
	pugi::xml_node eEventYeuCau = oEventThanMa.child("EventYeuCau");
	this->ReqZen = eEventYeuCau.attribute("ReqZen").as_int();
	this->ReqWC = eEventYeuCau.attribute("ReqWC").as_int();
	this->ReqWP = eEventYeuCau.attribute("ReqWP").as_int();
	this->ReqGP = eEventYeuCau.attribute("ReqGP").as_int();
	this->ReqItemIndex = eEventYeuCau.attribute("ReqItemIndex").as_int();
	this->ReqItemLevel = eEventYeuCau.attribute("ReqItemLevel").as_int();
	this->ReqItemCount = eEventYeuCau.attribute("ReqItemCount").as_int();
	this->MinLevel = eEventYeuCau.attribute("MinLevel").as_int();
	this->MaxLevel = eEventYeuCau.attribute("MaxLevel").as_int();
	this->MinReset = eEventYeuCau.attribute("MinReset").as_int();
	this->MaxReset = eEventYeuCau.attribute("MaxReset").as_int();
	this->MinMasterReset = eEventYeuCau.attribute("MinMasterReset").as_int();
	this->MaxMasterReset = eEventYeuCau.attribute("MaxMasterReset").as_int();
	//-Config Phan Thuong Khi Kill
	pugi::xml_node eEventRewardKill = oEventThanMa.child("EventRewardKill");
	this->BonusKill[0] = eEventRewardKill.attribute("WC").as_int();
	this->BonusKill[1] = eEventRewardKill.attribute("WP").as_int();
	this->BonusKill[2] = eEventRewardKill.attribute("GP").as_int();
	//-Config Phan Thuong Khi Team WIn
	pugi::xml_node eEventRewardTeam = oEventThanMa.child("EventRewardTeam");
	this->Coin1 = eEventRewardTeam.attribute("WC").as_int();
	this->Coin2 = eEventRewardTeam.attribute("WP").as_int();
	this->Coin3 = eEventRewardTeam.attribute("GP").as_int();
	//============

	pugi::xml_node Message = oEventThanMa.child("MessageInfo");
	for (pugi::xml_node msg = Message.child("Message"); msg; msg = msg.next_sibling())
	{
		MESSAGE_INFO_THANMACHIEN info;

		info.Index = msg.attribute("Index").as_int();

		strcpy_s(info.Message, msg.attribute("Text").as_string());

		this->m_MessageInfoBP.insert(std::pair<int, MESSAGE_INFO_THANMACHIEN>(info.Index, info));
	}

	this->Init();

	LogAdd(LOG_BLUE, "[EventThanMaChien] On: %d UserMinMax (%d/%d), MapEvent %d Time %d", this->m_ThanMaChienEnable, this->m_ThanMaChienMinUsers, this->m_ThanMaChienMaxUsers, this->EventMap, this->m_TMStartTime.size());
}


char* CThanMaChien::GetMessage(int index) // OK
{
	std::map<int, MESSAGE_INFO_THANMACHIEN>::iterator it = this->m_MessageInfoBP.find(index);

	if (it == this->m_MessageInfoBP.end())
	{
		char Error[256];
		wsprintf(Error, "Could not find message %d!", index);
		return Error;
	}
	else
	{
		return it->second.Message;
	}
}
void CThanMaChien::MainProc()
{
	if ((GetTickCount() - this->m_TickCount) >= 1000)
	{
		this->m_TickCount = GetTickCount();

		this->m_RemainTime = (int)difftime(this->TargetTime, time(0));

		if (this->m_ThanMaChienEnable == 0)
		{
			if (gServerDisplayer.BEventThanMa != -1)
			{
				gServerDisplayer.BEventThanMa = -1;
			}
		}
		else
		{
			if (this->m_State == TM_EVENT_STATE_EMPTY)
			{
				gServerDisplayer.BEventThanMa = this->m_RemainTime;
			}
			else
			{
				if (gServerDisplayer.BEventThanMa != 0)
				{
					gServerDisplayer.BEventThanMa = 0;
				}
			}
		}

		switch (this->m_State)
		{
		case TM_EVENT_STATE_BLANK:
			this->ProcState_BLANK();
			break;
		case TM_EVENT_STATE_EMPTY:
			this->ProcState_EMPTY();
			break;
		case TM_EVENT_STATE_STAND:
			this->ProcState_STAND();
			break;
		case TM_EVENT_STATE_START:
			this->ProcState_START();
			break;
		case TM_EVENT_STATE_CLEAN:
			this->ProcState_CLEAN();
			break;
		}
	}
}

void CThanMaChien::ProcState_BLANK() // OK
{

}

void CThanMaChien::ProcState_EMPTY() // OK
{
	if (this->m_RemainTime > 0 && this->m_RemainTime <= (this->m_WarningTime * 60))
	{
		this->CheckUser();

		this->EnterEnabled = 1;

		if ((this->AlarmMinSave = (((this->m_RemainTime % 60) == 0) ? ((this->m_RemainTime / 60) - 1) : (this->m_RemainTime / 60))) != this->AlarmMinLeft)
		{
			this->AlarmMinLeft = this->AlarmMinSave;

			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(0), (this->AlarmMinLeft + 1));
			//gNotice.GCNoticeSendToAll(0,0,0,0,0,0,gMessage.GetMessage(826));
		}
	}

	if (this->m_RemainTime <= 0)
	{
		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(2));
		this->NoticeSendToAll(1, this->GetMessage(3), this->m_StandTime);
		this->SetState(TM_EVENT_STATE_STAND);
	}
}

void CThanMaChien::ProcState_STAND() // OK
{
	this->CheckUser();

	//if(this->GetUserCount() < this->m_ThanMaChienMinUsers)
	//{
	//	this->NoticeSendToAll(0, this->GetMessage(5));
	//	this->SetState(TM_EVENT_STATE_EMPTY);
	//	return;
	//}

	if (this->m_RemainTime <= 0)
	{
		if (this->TotalPlayer >= this->m_ThanMaChienMinUsers)
		{
			this->DivisionTeam();
			this->NoticeSendToAll(0, this->GetMessage(4));
			this->SetState(TM_EVENT_STATE_START);
		}
		else
		{
			this->NoticeSendToAll(0, this->GetMessage(1));
			this->SetState(TM_EVENT_STATE_EMPTY);
		}
	}
}

void CThanMaChien::ProcState_START() // OK
{
	this->CheckUser();

	if (this->GetUserCount() == 0)
	{
		this->SetState(TM_EVENT_STATE_EMPTY);
		return;
	}

	if (this->GetUserCount() == 1)
	{
		this->SetState(TM_EVENT_STATE_CLEAN);
		return;
	}

	if (this->m_RemainTime <= 0)
	{
		this->NoticeSendToAll(0, this->GetMessage(5));
		this->SetState(TM_EVENT_STATE_CLEAN);
	}
}

void CThanMaChien::ProcState_CLEAN() // OK
{
	this->CheckUser();

	if (this->m_RemainTime <= 0)
	{
		this->SetState(TM_EVENT_STATE_EMPTY);
	}
}

void CThanMaChien::SetState(int state) // OK
{
	switch ((this->m_State = state))
	{
	case TM_EVENT_STATE_BLANK:
		this->SetState_BLANK();
		break;
	case TM_EVENT_STATE_EMPTY:
		this->SetState_EMPTY();
		break;
	case TM_EVENT_STATE_STAND:
		this->SetState_STAND();
		break;
	case TM_EVENT_STATE_START:
		this->SetState_START();
		break;
	case TM_EVENT_STATE_CLEAN:
		this->SetState_CLEAN();
		break;
	}
}

void CThanMaChien::SetState_BLANK() // OK
{

}

void CThanMaChien::SetState_EMPTY() // OK
{
	this->EnterEnabled = 0;
	this->AlarmMinSave = -1;
	this->AlarmMinLeft = -1;

	this->ClearUser();
	this->ScoreBlue = 0;
	this->ScoreRed = 0;

	this->CheckSync();
}

void CThanMaChien::SetState_STAND() // OK
{
	this->EnterEnabled = 0;
	this->AlarmMinSave = -1;
	this->AlarmMinLeft = -1;

	this->m_RemainTime = this->m_StandTime * 60;

	this->TargetTime = (int)(time(0) + this->m_RemainTime);
}

void CThanMaChien::SetState_START() // OK
{
	this->EnterEnabled = 0;
	this->AlarmMinSave = -1;
	this->AlarmMinLeft = -1;

	this->m_RemainTime = this->m_EventTime * 60;

	this->SendTimeEventAll(this->m_RemainTime, this->m_State);

	this->TargetTime = (int)(time(0) + this->m_RemainTime);
}

void CThanMaChien::SendTimeEventAll(int time, int State)
{
	//LogAdd(LOG_RED, "DEBUG SendTimeEventAll");
	PMSG_TIMEEVENT_CUSTOM pMsg;
	pMsg.h.set(0xFB, 0x62, sizeof(pMsg));
	pMsg.Map = this->EventMap;
	pMsg.TimeCount = time;
	pMsg.State = State;

	for (int n = 0; n < MAX_THANMACHIEN_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) != 0)
		{
			DataSend(this->User[n].Index, (LPBYTE)& pMsg, pMsg.h.size);
		}

	}
}


void CThanMaChien::SetState_CLEAN() // OK
{
	this->EnterEnabled = 0;
	this->AlarmMinSave = -1;
	this->AlarmMinLeft = -1;

	int TeamReward = 0;

	if (this->ScoreBlue > this->ScoreRed)
	{
		TeamReward = TM_TEAMTHIENTHAN;
		this->NoticeSendToAll(0, "Win Team Thien Than!");
	}
	else if (this->ScoreRed > this->ScoreBlue)
	{
		TeamReward = TM_TEAMACQUY;
		this->NoticeSendToAll(0, "Win Team Ac Quy!");
	}


	for (int n = 0; n < MAX_THANMACHIEN_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) != 0)
		{
			gObjViewportListProtocolCreate(&gObj[this->User[n].Index]);
			gObjectManager.CharacterUpdateMapEffect(&gObj[this->User[n].Index]);

			if (this->User[n].Team == TeamReward)
			{
				LPOBJ lpObj = &gObj[this->User[n].Index];

				if (this->Coin1 > 0 || this->Coin2 > 0 || this->Coin3 > 0)
				{
					GDSetCoinSend(lpObj->Index, this->Coin1, this->Coin2, this->Coin3, "ThanMaChien");
				}


				GDRankingThanMaChienSaveSend(lpObj->Index, this->User[n].Kills, this->User[n].Deaths); //Update Ranking DB

				gDucTuong.SaveConfig(lpObj->Index);
				gDucTuong.LoadTuong(lpObj->Index);
				gDucTuong.MakeBot();

			}
			//else
			//{
			//GDRankingCustomArenaSaveSend(lpInfo->User[n].Index,lpInfo->Index,lpInfo->User[n].Score,lpInfo->User[n].Rank);

			//gNotice.GCNoticeSend(lpInfo->User[n].Index,1,0,0,0,0,0,this->m_CustomArenaText7,lpInfo->RuleInfo.Name,lpInfo->User[n].Rank,lpInfo->User[n].Score);
			//}
		}


	}

	this->m_RemainTime = this->m_CloseTime * 60;

	this->TargetTime = (int)(time(0) + this->m_RemainTime);
}

void CThanMaChien::CheckSync() // OK
{
	if (this->m_TMStartTime.empty() != 0)
	{
		this->SetState(TM_EVENT_STATE_BLANK);
		return;
	}

	CTime ScheduleTime;

	CScheduleManager ScheduleManager;

	for (std::vector<TM_TIME>::iterator it = this->m_TMStartTime.begin(); it != this->m_TMStartTime.end(); it++)
	{
		ScheduleManager.AddSchedule(it->Year, it->Month, it->Day, it->Hour, it->Minute, it->Second, it->DayOfWeek);
	}

	if (ScheduleManager.GetSchedule(&ScheduleTime) == 0)
	{
		this->SetState(TM_EVENT_STATE_BLANK);
		return;
	}

	this->m_RemainTime = (int)difftime(ScheduleTime.GetTime(), time(0));

	this->TargetTime = (int)ScheduleTime.GetTime();
}

int CThanMaChien::GetState() // OK
{
	return this->m_State;
}

bool CThanMaChien::Dialog(LPOBJ lpObj, LPOBJ lpNpc)
{
	if (!this->m_ThanMaChienEnable) return false;

	if (lpNpc->Class == this->m_ThanMaChienNPC &&
		lpNpc->Map == this->m_ThanMaChienNPCMap &&
		lpNpc->X == this->m_ThanMaChienNPCX &&
		lpNpc->Y == this->m_ThanMaChienNPCY)
	{
		//GCChatTargetSend(lpObj, lpNpc->Index, gMessage.GetMessage(826));
		XULY_CGPACKET pMsg;
		pMsg.header.set(0xFB, 0x61, sizeof(pMsg));
		pMsg.ThaoTac = 1;
		DataSend(lpObj->Index, (BYTE*)& pMsg, pMsg.header.size);

		return 1;
	}

	return false;
}

void CThanMaChien::CGOpenWindowNPC(XULY_CGPACKET* aRecv, int aIndex)
{
	//LogAdd(LOG_RED, "DEBUG CGOpenWindowNPC");
	if (!this->m_ThanMaChienEnable)
	{
		return;
	}
	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if ((GetTickCount() - lpObj->ClickClientSend) < 2000) {
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(963));
		return;
	}
	//=== Send Client Open Windows
	if (!this->CheckEnterEnabled(lpObj))
	{
		return;
	}
	//=== Send Time & Stage ve Client

	lpObj->ClickClientSend = GetTickCount();
	return;
}
bool CThanMaChien::CheckEnterEnabled(LPOBJ lpObj)
{
	if (this->GetEnterEnabled() == 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(7));
		return 0;
	}
	if (OBJECT_RANGE(lpObj->PartyNumber) != 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(6));
		return 0;
	}

	if (lpObj->Guild != 0 && lpObj->Guild->WarState == 1)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(6));
		return 0;
	}

	if (OBJECT_RANGE(lpObj->DuelUser) != 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(6));
		return 0;
	}

	if (lpObj->PShopOpen != 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(6));
		return 0;
	}

	if (this->GetUserCount() >= this->m_ThanMaChienMaxUsers)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(6));
		return 0;
	}

	if (this->MinLevel != -1 && this->MinLevel > lpObj->Level)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(224), this->MinLevel);
		return 0;
	}

	if (this->MaxLevel != -1 && this->MaxLevel < lpObj->Level)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(230), this->MaxLevel);
		return 0;
	}

	if (this->MinReset != -1 && this->MinReset > lpObj->Reset)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(231), this->MinReset);
		return 0;
	}

	if (this->MaxReset != -1 && this->MaxReset < lpObj->Reset)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(232), this->MaxReset);
		return 0;
	}

	if (this->MinMasterReset != -1 && this->MinMasterReset > lpObj->MasterReset)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(818), this->MinMasterReset);
		return 0;
	}

	if (this->MaxMasterReset != -1 && this->MaxMasterReset < lpObj->MasterReset)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(819), this->MaxMasterReset);
		return 0;
	}

	if (this->CheckReqItems(lpObj) == 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(8));
		return 0;
	}

	gEffectManager.ClearAllEffect(lpObj);


	return this->AddUser(lpObj->Index);
}

bool CThanMaChien::CheckReqItems(LPOBJ lpObj)
{

	if (lpObj->Money < this->ReqZen)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(9));
		return false;
	}
	lpObj->Money -= this->ReqZen;
	GCMoneySend(lpObj->Index, lpObj->Money);

	if (lpObj->Coin1 < this->ReqWC || lpObj->Coin2 < this->ReqWP || lpObj->Coin3 < this->ReqGP)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(9));
		return false;
	}
	if (this->ReqWC > 0 || this->ReqWP > 0 || this->ReqGP > 0)
	{
		GDSetCoinSend(lpObj->Index, -(this->ReqWC), -(this->ReqWP), -(this->ReqGP), "TruCoinThanMaChien");
	}

	lpObj->ChaosLock = 1;

	int count = gItemManager.GetInventoryItemCount(lpObj, this->ReqItemIndex, this->ReqItemLevel);

	if (count < this->ReqItemCount)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(8));
		return false;
	}

	gItemManager.DeleteInventoryItemCount(lpObj, this->ReqItemIndex, this->ReqItemLevel, this->ReqItemCount);

	lpObj->ChaosLock = 0;
	return true;
}

int CThanMaChien::GetEnterEnabled() // OK
{
	return this->EnterEnabled;
}

int CThanMaChien::GetEnteredUserCount() // OK
{
	return this->GetUserCount();
}

bool CThanMaChien::CheckEnteredUser(int aIndex) // OK
{
	return ((this->GetUser(aIndex) == 0) ? 0 : 1);
}

bool CThanMaChien::CheckPlayerTarget(LPOBJ lpObj) // OK
{
	if (this->GetState() == TM_EVENT_STATE_START)
	{
		if (this->EventMap == lpObj->Map)
		{
			if (this->CheckEnteredUser(lpObj->Index) != 0)
			{
				return 1;
			}
		}
	}
	return 0;
}

bool CThanMaChien::CheckPlayerJoined(LPOBJ lpObj, LPOBJ lpTarget) // OK
{
	if (this->GetState() != TM_EVENT_STATE_BLANK)
	{
		if (this->EventMap == lpObj->Map)
		{
			if (this->CheckEnteredUser(lpObj->Index) != 0)
			{
				return 1;
			}
		}
	}
	return 0;
}

bool CThanMaChien::CheckSelfTeam(LPOBJ lpObj, LPOBJ lpTarget)
{
	if (this->GetState() == TM_EVENT_STATE_START)
	{
		TM_EVENT_USER* lpUserA = this->GetUser(lpObj->Index);
		TM_EVENT_USER* lpUserB = this->GetUser(lpTarget->Index);

		if (lpUserA == 0 || lpUserB == 0)
		{
			return 1;
		}

		if (lpUserA->Team == lpUserB->Team)
		{
			return 1;
		}
	}
	return 0;
}

bool CThanMaChien::AddUser(int aIndex) // OK
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}

	if (this->GetUser(aIndex) != 0)
	{
		return 0;
	}

	for (int n = 0; n < MAX_THANMACHIEN_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) != 0)
		{
			continue;
		}

		this->User[n].Index = aIndex;
		this->User[n].Available = 1;
		this->TotalPlayer++;
		gObjMoveGate(aIndex, this->WaitingGate);
		return 1;
	}
	return 0;
}

bool CThanMaChien::DelUser(int aIndex) // OK
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}

	TM_EVENT_USER* lpUser = this->GetUser(aIndex);

	if (lpUser == 0)
	{
		return 0;
	}

	lpUser->Reset();
	this->TotalPlayer--;
	return 1;
}

TM_EVENT_USER* CThanMaChien::GetUser(int aIndex) // OK
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}

	for (int n = 0; n < MAX_THANMACHIEN_USER; n++)
	{
		if (this->User[n].Index == aIndex)
		{
			return &this->User[n];
		}
	}
	return 0;
}

void CThanMaChien::CleanUser() // OK
{
	for (int n = 0; n < MAX_THANMACHIEN_USER; n++)
	{
		this->User[n].Reset();
		this->TotalPlayer = 0;
	}
}

void CThanMaChien::ClearUser() // OK
{
	for (int n = 0; n < MAX_THANMACHIEN_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) == 0)
		{
			continue;
		}

		gObjMoveGate(this->User[n].Index, 17);

		if (this->SetSkin == 1)
		{
			gObj[this->User[n].Index].Change = -1;
		}

		gObjViewportListProtocolCreate(&gObj[this->User[n].Index]);
		gObjectManager.CharacterUpdateMapEffect(&gObj[this->User[n].Index]);

		this->User[n].Reset();

		this->TotalPlayer--;
	}
}

void CThanMaChien::CheckUser() // OK
{
	for (int n = 0; n < MAX_THANMACHIEN_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) == 0)
		{
			continue;
		}

		if (gObjIsConnected(this->User[n].Index) == 0)
		{
			this->DelUser(this->User[n].Index);
			continue;
		}

		if (gObj[this->User[n].Index].Map != this->EventMap)
		{
			this->DelUser(this->User[n].Index);
			continue;
		}
	}
}

int CThanMaChien::GetUserCount() // OK
{
	int count = 0;

	for (int n = 0; n < MAX_THANMACHIEN_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) != 0)
		{
			count++;
		}
	}

	return count;
}

bool CThanMaChien::GetUserRespawnLocation(LPOBJ lpObj, int* gate, int* map, int* x, int* y, int* dir, int* level) // OK
{
	if (this->m_ThanMaChienEnable == 0)
	{
		return 0;
	}

	if (this->GetState() != TM_EVENT_STATE_START)
	{
		return 0;
	}

	TM_EVENT_USER* lpUser = this->GetUser(lpObj->Index);

	if (lpUser == 0)
	{
		return 0;
	}

	if (lpUser->Team == TM_TEAMTHIENTHAN)
	{
		if (gGate.GetGate(this->TEAMTHIENTHANGate, gate, map, x, y, dir, level) != 0)
		{
			return 1;
		}
	}
	else if (lpUser->Team == TM_TEAMACQUY)
	{
		if (gGate.GetGate(this->TEAMACQUYGate, gate, map, x, y, dir, level) != 0)
		{
			return 1;
		}
	}
	else
	{
		if (gGate.GetGate(this->WaitingGate, gate, map, x, y, dir, level) != 0)
		{
			return 1;
		}
	}

	return 0;
}

void CThanMaChien::DivisionTeam()
{
	int iTeam = 1;
	int Index = 0;

	for (int i = 0; i<MAX_THANMACHIEN_USER; i++)
	{
		Index = this->ReturnMaxReset();
		this->User[i].Team = iTeam;
		if (iTeam == 1) iTeam = 2;
		else iTeam = 1;
	}

	for (int n = 0; n<MAX_THANMACHIEN_USER; n++)
	{
		if (this->User[n].Team == 1)
		{
			gObjMoveGate(this->User[n].Index, this->TEAMTHIENTHANGate);

			if (this->SetSkin == 1)
			{
				gObj[this->User[n].Index].Change = 405;
			}

			gObjViewportListProtocolCreate(&gObj[this->User[n].Index]);
			gObjectManager.CharacterUpdateMapEffect(&gObj[this->User[n].Index]);

			gNotice.GCNoticeSend(this->User[n].Index, 0, 0, 0, 0, 0, 0, "[TEAMTHIENTHAN]: %d Vs [TEAMACQUY]: %d", this->ScoreBlue, this->ScoreRed);
		}
		else if (this->User[n].Team == 2)
		{
			gObjMoveGate(this->User[n].Index, this->TEAMACQUYGate);

			if (this->SetSkin == 1)
			{
				gObj[this->User[n].Index].Change = 404;
			}

			gObjViewportListProtocolCreate(&gObj[this->User[n].Index]);
			gObjectManager.CharacterUpdateMapEffect(&gObj[this->User[n].Index]);

			gNotice.GCNoticeSend(this->User[n].Index, 0, 0, 0, 0, 0, 0, "[TEAMACQUY]: %d Vs [TEAMTHIENTHAN]: %d", this->ScoreRed, this->ScoreBlue);
		}


	}
}

int CThanMaChien::ReturnMaxReset()
{
	int MaxRes = 0;
	int Index = 0;
	int UserIndex = 0;

	for (int n = 0; n < MAX_THANMACHIEN_USER; n++)
	{
		LPOBJ lpObj = &gObj[this->User[n].Index];
		if (OBJECT_RANGE(lpObj->Index) == 0)
		{
			continue;
		}

		if (!this->User[n].Available)
		{
			continue;
		}

		if (lpObj->Reset >= MaxRes)
		{
			MaxRes = lpObj->Reset;
			Index = lpObj->Index;
			UserIndex = n;
		}
	}
	this->User[UserIndex].Available = 0;
	return Index;
}

void CThanMaChien::UserDieProc(LPOBJ lpObj, LPOBJ lpTarget) // OK
{
	if (this->m_ThanMaChienEnable == 0)
	{
		return;
	}

	if (this->GetState() != TM_EVENT_STATE_START)
	{
		return;
	}

	TM_EVENT_USER* lpUserA = this->GetUser(lpObj->Index);

	if (lpUserA == 0)
	{
		return;
	}

	TM_EVENT_USER* lpUserB = this->GetUser(lpTarget->Index);

	if (lpUserB == 0)
	{
		return;
	}

	if (lpUserA->Team == TM_TEAMTHIENTHAN && lpUserB->Team == TM_TEAMACQUY)
	{
		this->ScoreRed++;
	}
	else if (lpUserA->Team == TM_TEAMACQUY && lpUserB->Team == TM_TEAMTHIENTHAN)
	{
		this->ScoreBlue++;
	}

	lpUserA->Deaths++;
	lpUserB->Kills++;
	//=== Cong Coin Kill
	if (this->BonusKill[0] > 0 || this->BonusKill[1] > 0 || this->BonusKill[2] > 0)
	{
		GDSetCoinSend(lpUserB->Index, this->BonusKill[0], this->BonusKill[1], this->BonusKill[2], "ThanMaChienCoinKill");
	}
	//== Tinh Toan Rank
	this->CalcUserRank();
	this->SendBXHVeClient(0);
}

void CThanMaChien::NoticeSendToAll(int type, char* message, ...) // OK
{
	char buff[256];

	va_list arg;
	va_start(arg, message);
	vsprintf_s(buff, message, arg);
	va_end(arg);

	for (int n = 0; n < MAX_THANMACHIEN_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) != 0)
		{
			gNotice.GCNoticeSend(this->User[n].Index, type, 0, 0, 0, 0, 0, buff);
		}
	}
}

void CThanMaChien::StartTM()
{
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	//int day = aTime->tm_mday;
	//int month = aTime->tm_mon + 1;
	//int year = aTime->tm_year + 1900;

	int hour = aTime->tm_hour;
	int minute = aTime->tm_min + 2;


	if (minute >= 60)
	{
		hour++;
		minute = minute - 60;
	}

	TM_TIME info;

	info.Year = -1;

	info.Month = -1;

	info.Day = -1;

	info.DayOfWeek = -1;

	info.Hour = hour;

	info.Minute = minute;

	info.Second = 0;

	this->m_TMStartTime.push_back(info);

	LogAdd(LOG_EVENT, "[Set ThanMaChien] At %2d:%2d:00", hour, minute);

	this->Init();
}

void CThanMaChien::CalcUserRank() // OK
{
	for (int stt = 0; stt < 10; stt++)
	{
		this->mIndexRank[stt] = -1;
	}
	for (int n = 0; n < MAX_THANMACHIEN_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) == 0)
		{
			continue;
		}

		int rank = MAX_THANMACHIEN_USER;

		for (int i = 0; i < MAX_THANMACHIEN_USER; i++)
		{
			if (OBJECT_RANGE(this->User[i].Index) == 0)
			{
				rank--;
				continue;
			}

			if (this->User[n].Index == this->User[i].Index)
			{
				rank--;
				continue;
			}

			if (this->User[n].Kills > this->User[i].Kills)
			{
				rank--;
				continue;
			}

			if (this->User[n].Kills == this->User[i].Kills && n < i)
			{
				rank--;
				continue;
			}
		}

		this->User[n].Rank = (rank + 1);
		if (this->User[n].Rank >= 1 && this->User[n].Rank <= 10)
		{
			int Stt = this->User[n].Rank - 1;
			this->mIndexRank[Stt] = n;
			//LogAdd(LOG_RED, "GETRANK %d ~ %d", this->mIndexRank[Stt], n);
		}
	}
}

void CThanMaChien::SendBXHVeClient(BYTE OpenWindow)
{

	BYTE send[4096];

	PMSG_COUNTLIST_TM pMsg;

	pMsg.header.set(0xFB, 0x63, 0);

	int size = sizeof(pMsg);

	pMsg.Count = 0;

	pMsg.ScoreThienThan = this->ScoreBlue;
	pMsg.ScoreAcQuy = this->ScoreRed;
	pMsg.OpenBXHWindow = OpenWindow;

	EVENTHANMA_BXH info;

	for (int n = 0; n < 10; n++)
	{
		if (OBJECT_RANGE(this->User[this->mIndexRank[n]].Index) == 0)
		{
			continue;
		}
		if (this->User[this->mIndexRank[n]].Rank > 0 && this->User[this->mIndexRank[n]].Rank <= 10)
		{
			memcpy(info.Name, gObj[this->User[this->mIndexRank[n]].Index].Name, sizeof(info.Name));
			info.Kill = this->User[this->mIndexRank[n]].Kills;
			info.Team = this->User[this->mIndexRank[n]].Team;
			pMsg.Count++;

			memcpy(&send[size], &info, sizeof(info));
			size += sizeof(info);
		}

	}
	pMsg.header.size[0] = SET_NUMBERHB(size);
	pMsg.header.size[1] = SET_NUMBERLB(size);
	// ---
	memcpy(send, &pMsg, sizeof(pMsg));

	for (int n = 0; n < MAX_THANMACHIEN_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) != 0)
		{
			DataSend(this->User[n].Index, send, size);
		}
	}
}
#endif