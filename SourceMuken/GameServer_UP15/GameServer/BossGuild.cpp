// CTCMini.cpp: Evento CTC Mini by CuongBeo
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DSProtocol.h"
#include "GuildClass.h"
#include "Map.h"
#include "MapServerManager.h"
#include "MemScript.h"
#include "Message.h"
#include "ServerInfo.h"
#include "SkillManager.h"
#include "ScheduleManager.h"
#include "Notice.h"
#include "Util.h"
#include "CommandManager.h"
#include "DSProtocol.h"
#include "GameMain.h"
#include "Guild.h"
#include "BossGuild.h"
#include "CashShop.h"
#include "Monster.h"
#include "ItemBagManager.h"
#include "Gate.h"
#include "Log.h"
#include "ESProtocol.h"

#include <fstream>
using namespace std;

#if(BOSS_GUILD == 1)
CBossGuild gBossGuild;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBossGuild::CBossGuild() // OK
{

	this->m_State = BOSSGUILD_STATE_BLANK;
	this->m_RemainTime = 0;
	this->m_TargetTime = 0;
	this->m_TickCount = GetTickCount();
	this->MinutesLeft = -1;

	this->m_RemainTimeWinner = 0;

	this->GuildKillBoss = 0;

	this->WinnerNumber = -1;

	ZeroMemory(this->WinnerName, sizeof(this->WinnerName));
	ZeroMemory(this->WinnerNameOLD, sizeof(this->WinnerNameOLD));

	ZeroMemory(&this->GateMove, sizeof(this->GateMove));
	this->m_BossGuildStartTime.clear();
	this->Class = -1;
	this->Map = 0;
	this->X = 0;
	this->Y = 0;
	this->GuildMinPlayer = 0;

	this->Clear();
}


void CBossGuild::Clear()
{
	for (int n = 0; n < MAX_GUILD; n++)
	{
		this->Guild[n].Reset();
	}

	for (int n = 0; n < MAX_CHAR; n++)
	{
		this->Char[n].Reset();
	}

	this->m_RemainTimeWinner = 0;

	this->GuildKillBoss = 0;

	this->WinnerNumber = -1;

	this->m_Active = 0;

}
CBossGuild::~CBossGuild() // OK
{

}

void CBossGuild::Init() // OK
{
	if (this->m_Enabled == 0)
	{
		this->SetState(BOSSGUILD_STATE_BLANK);
	}
	else
	{
		this->SetState(BOSSGUILD_STATE_EMPTY);
	}
}
void CBossGuild::Load(char* path) // OK
{
	this->m_BossGuildStartTime.clear();
	ZeroMemory(this->WinnerNameOLD, sizeof(this->WinnerNameOLD));
	this->Clear();
	this->m_Enabled = 0;
	this->m_EventTime = 0;
	this->m_WarningTime = 0;

	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(path);
	if (res.status != pugi::status_ok)
	{
		ErrorMessageBox("File %s load fail. Error: %s", path, res.description());
		return;
	}

	//--
	pugi::xml_node oBossGuild = file.child("BossGuild");
	//--
	pugi::xml_node eBossGuild = oBossGuild.child("EventTime");
	for (pugi::xml_node rBossGuild = eBossGuild.child("Time"); rBossGuild; rBossGuild = rBossGuild.next_sibling()){
		BOSSGUILD_START_TIME info;
		info.Year = rBossGuild.attribute("Year").as_int();
		info.Month = rBossGuild.attribute("Month").as_int();
		info.Day = rBossGuild.attribute("Day").as_int();
		info.DayOfWeek = rBossGuild.attribute("DayOfWeek").as_int();
		info.Hour = rBossGuild.attribute("Hour").as_int();
		info.Minute = rBossGuild.attribute("Minute").as_int();
		info.Second = rBossGuild.attribute("Second").as_int();
		this->m_BossGuildStartTime.push_back(info);
	}
	//--
	pugi::xml_node eNPCTalk = oBossGuild.child("NPCTalk");
	for (pugi::xml_node rNPCTalk = eNPCTalk.child("NPC"); rNPCTalk; rNPCTalk = rNPCTalk.next_sibling()){
		this->Class = rNPCTalk.attribute("Class").as_int();
		this->Map = rNPCTalk.attribute("Map").as_int();
		this->X = rNPCTalk.attribute("X").as_int();
		this->Y = rNPCTalk.attribute("Y").as_int();
	}
	//--
	pugi::xml_node eCauHinhTime = oBossGuild.child("Time");
	for (pugi::xml_node rTimeConfig = eCauHinhTime.child("Config"); rTimeConfig; rTimeConfig = rTimeConfig.next_sibling()){

		this->m_Enabled = rTimeConfig.attribute("Enabled").as_int();
		this->m_MapBossGuild = rTimeConfig.attribute("MapDienRa").as_int();
		this->m_WarningTime = rTimeConfig.attribute("TimeChuanBi").as_int();
		this->m_EventTime = rTimeConfig.attribute("TimeSuKien").as_int();
		this->GuildMinPlayer = rTimeConfig.attribute("GuildMinPlayer").as_int();
	}
	//====
	pugi::xml_node eCauHinhGate = oBossGuild.child("CauHinhGate");
	for (pugi::xml_node rGateConfig = eCauHinhGate.child("Config"); rGateConfig; rGateConfig = rGateConfig.next_sibling())
	{
		this->GateMove[0] = rGateConfig.attribute("GateVaoMap").as_int();
	}
	//====
	pugi::xml_node eCheDoBoss = oBossGuild.child("CheDoBoss");
	for (pugi::xml_node rCheDoBoss = eCheDoBoss.child("Config"); rCheDoBoss; rCheDoBoss = rCheDoBoss.next_sibling()){

		this->CheDo1 = rCheDoBoss.attribute("CheDo1").as_int();
		this->CheDo2 = rCheDoBoss.attribute("CheDo2").as_int();
	}
	//===
	pugi::xml_node eDieuKiemGuildWin = oBossGuild.child("DieuKienGuildWin");
	for (pugi::xml_node rDieuKienGuildWin = eDieuKiemGuildWin.child("Config"); rDieuKienGuildWin; rDieuKienGuildWin = rDieuKienGuildWin.next_sibling()){

		this->KillBoss = rDieuKienGuildWin.attribute("KillBoss").as_int();
	}
	//===
	pugi::xml_node eGuildWin = oBossGuild.child("GuildWin");
	for (pugi::xml_node rGuildWin = eGuildWin.child("Config"); rGuildWin; rGuildWin = rGuildWin.next_sibling()){

		GuildWin.Score = rGuildWin.attribute("Score").as_int();
		GuildWin.WCoin = rGuildWin.attribute("WCoin").as_int();
		GuildWin.WCoinP = rGuildWin.attribute("WCoinP").as_int();
		GuildWin.GobinP = rGuildWin.attribute("GobinP").as_int();
		GuildWin.IndexBonus = rGuildWin.attribute("IndexBonus").as_int();
		GuildWin.IndexItemBag = rGuildWin.attribute("IndexItemBag").as_int();
		//LogAdd(LOG_RED, "[GuildWin] Score %d, WCoin %d, WCoinP %d, GobinP %d, IndexBonus %d, IndexItemBag %d", GuildWin.Score, GuildWin.WCoin, GuildWin.WCoinP, GuildWin.GobinP, GuildWin.IndexBonus, GuildWin.IndexItemBag);
	}
	//===
	pugi::xml_node eBossPhuThuy = oBossGuild.child("BossPhuThuy");
	for (pugi::xml_node rBossPhuThuy = eBossPhuThuy.child("Config"); rBossPhuThuy; rBossPhuThuy = rBossPhuThuy.next_sibling()){

		BossPhuThuy.WCoin = rBossPhuThuy.attribute("WCoin").as_int();
		BossPhuThuy.WCoinP = rBossPhuThuy.attribute("WCoinP").as_int();
		BossPhuThuy.GobinP = rBossPhuThuy.attribute("GobinP").as_int();
		BossPhuThuy.IndexBonus = rBossPhuThuy.attribute("IndexBonus").as_int();
		BossPhuThuy.IndexType = rBossPhuThuy.attribute("IndexType").as_int();
		BossPhuThuy.IndexItem = rBossPhuThuy.attribute("IndexItem").as_int();
	}
	//===
	pugi::xml_node eBossChienBinh = oBossGuild.child("BossChienBinh");
	for (pugi::xml_node rBossChienBinh = eBossChienBinh.child("Config"); rBossChienBinh; rBossChienBinh = rBossChienBinh.next_sibling()){

		BossChienBinh.WCoin = rBossChienBinh.attribute("WCoin").as_int();
		BossChienBinh.WCoinP = rBossChienBinh.attribute("WCoinP").as_int();
		BossChienBinh.GobinP = rBossChienBinh.attribute("GobinP").as_int();
		BossChienBinh.IndexBonus = rBossChienBinh.attribute("IndexBonus").as_int();
		BossChienBinh.IndexType = rBossChienBinh.attribute("IndexType").as_int();
		BossChienBinh.IndexItem = rBossChienBinh.attribute("IndexItem").as_int();
	}
	//===
	pugi::xml_node eBossTienNu = oBossGuild.child("BossTienNu");
	for (pugi::xml_node rBossTienNu = eBossTienNu.child("Config"); rBossTienNu; rBossTienNu = rBossTienNu.next_sibling()){

		BossTienNu.WCoin = rBossTienNu.attribute("WCoin").as_int();
		BossTienNu.WCoinP = rBossTienNu.attribute("WCoinP").as_int();
		BossTienNu.GobinP = rBossTienNu.attribute("GobinP").as_int();
		BossTienNu.IndexBonus = rBossTienNu.attribute("IndexBonus").as_int();
		BossTienNu.IndexType = rBossTienNu.attribute("IndexType").as_int();
		BossTienNu.IndexItem = rBossTienNu.attribute("IndexItem").as_int();
	}
	//===
	pugi::xml_node eBossThuatSi = oBossGuild.child("BossThuatSi");
	for (pugi::xml_node rBossThuatSi = eBossThuatSi.child("Config"); rBossThuatSi; rBossThuatSi = rBossThuatSi.next_sibling()){

		BossThuatSi.WCoin = rBossThuatSi.attribute("WCoin").as_int();
		BossThuatSi.WCoinP = rBossThuatSi.attribute("WCoinP").as_int();
		BossThuatSi.GobinP = rBossThuatSi.attribute("GobinP").as_int();
		BossThuatSi.IndexBonus = rBossThuatSi.attribute("IndexBonus").as_int();
		BossThuatSi.IndexType = rBossThuatSi.attribute("IndexType").as_int();
		BossThuatSi.IndexItem = rBossThuatSi.attribute("IndexItem").as_int();
	}
	//===
	pugi::xml_node eBossThietBinh = oBossGuild.child("BossThietBinh");
	for (pugi::xml_node rBossThietBinh = eBossThietBinh.child("Config"); rBossThietBinh; rBossThietBinh = rBossThietBinh.next_sibling()){

		BossThietBinh.WCoin = rBossThietBinh.attribute("WCoin").as_int();
		BossThietBinh.WCoinP = rBossThietBinh.attribute("WCoinP").as_int();
		BossThietBinh.GobinP = rBossThietBinh.attribute("GobinP").as_int();
		BossThietBinh.IndexBonus = rBossThietBinh.attribute("IndexBonus").as_int();
		BossThietBinh.IndexType = rBossThietBinh.attribute("IndexType").as_int();
		BossThietBinh.IndexItem = rBossThietBinh.attribute("IndexItem").as_int();
	}
	//===
	pugi::xml_node eBossDauSi = oBossGuild.child("BossDauSi");
	for (pugi::xml_node rBossDauSi = eBossDauSi.child("Config"); rBossDauSi; rBossDauSi = rBossDauSi.next_sibling()){

		BossDauSi.WCoin = rBossDauSi.attribute("WCoin").as_int();
		BossDauSi.WCoinP = rBossDauSi.attribute("WCoinP").as_int();
		BossDauSi.GobinP = rBossDauSi.attribute("GobinP").as_int();
		BossDauSi.IndexBonus = rBossDauSi.attribute("IndexBonus").as_int();
		BossDauSi.IndexType = rBossDauSi.attribute("IndexType").as_int();
		BossDauSi.IndexItem = rBossDauSi.attribute("IndexItem").as_int();
	}
	//===
	pugi::xml_node eBossChuaTe = oBossGuild.child("BossChuaTe");
	for (pugi::xml_node rBossChuaTe = eBossChuaTe.child("Config"); rBossChuaTe; rBossChuaTe = rBossChuaTe.next_sibling()){

		BossChuaTe.WCoin = rBossChuaTe.attribute("WCoin").as_int();
		BossChuaTe.WCoinP = rBossChuaTe.attribute("WCoinP").as_int();
		BossChuaTe.GobinP = rBossChuaTe.attribute("GobinP").as_int();
		BossChuaTe.IndexBonus = rBossChuaTe.attribute("IndexBonus").as_int();
		BossChuaTe.IndexType = rBossChuaTe.attribute("IndexType").as_int();
		BossChuaTe.IndexItem = rBossChuaTe.attribute("IndexItem").as_int();
	}
	//===
	//==============================
	GetPrivateProfileString("GuildWinOLD", "GuildName", "", this->WinnerNameOLD, sizeof(this->WinnerNameOLD), "..\\Data\\Event\\BossGuild\\GuildWin.ini");
	//LogAdd(LOG_RED, "Debug  GuildWinOLD %s", this->WinnerNameOLD);
	//==============================
}

void CBossGuild::MainProc() // OK
{
	DWORD elapsed = GetTickCount() - this->m_TickCount;

	if (elapsed < 1000)
	{
		return;
	}

	this->m_TickCount = GetTickCount();

	this->m_RemainTime = (int)difftime(this->m_TargetTime, time(0));


	if (this->m_Enabled == 0)
	{
		if (gServerDisplayer.EventBossGuild != -1)
		{
			gServerDisplayer.EventBossGuild = -1;
		}
	}
	else
	{
		if (this->m_State == BOSSGUILD_STATE_EMPTY)
		{
			gServerDisplayer.EventBossGuild = this->m_RemainTime;
		}
		else
		{
			if (gServerDisplayer.EventBossGuild != 0)
			{
				gServerDisplayer.EventBossGuild = 0;
			}
		}
	}

	switch (this->m_State)
	{
	case BOSSGUILD_STATE_BLANK:
		this->ProcState_BLANK();
		break;
	case BOSSGUILD_STATE_EMPTY:
		this->ProcState_EMPTY();
		break;
	case BOSSGUILD_STATE_START:
		this->ProcState_START();
		break;
	}

	//==Tien hanh tong ket va trao thuong
	if (this->m_RemainTimeWinner > 0)
	{
		if (this->WinnerNumber >= 0)
		{
			if (this->m_RemainTimeWinner == 40)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "[BossGuild] Chuẩn bị tiến hành trao thưởng!");
			}

			if (this->m_RemainTimeWinner == 15) //Trao thuong cho Guild
			{
				GUILD_INFO_STRUCT* lpGuildInfo = gGuildClass.SearchGuild_Number(this->WinnerNumber);

				if (lpGuildInfo == 0)
				{
				}
				else
				{
					LogAdd(LOG_EVENT, "[BossGuild] Guild chiến thắng: %s", lpGuildInfo->Name);
					gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "[BossGuild] Guild [%s] đã chiến thắng", lpGuildInfo->Name);
					//===============================================
					// Phần thưởng cống hiến cho guild
					for (int n = 0; n < MAX_OBJECT; n++)
					{
						if (gObjIsConnectedGP(n) != 0 && gObj[n].Type == OBJECT_USER)
						{
							if (strcmp(gObj[n].GuildName, lpGuildInfo->Name) == 0)
							{
								LPOBJ lpObj = &gObj[n];
								lpObj->Guild->TotalScore += GuildWin.Score;
								DGGuildScoreUpdate(lpObj->Guild->Name, lpObj->Guild->TotalScore);
							}
						}
					}
					gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Guild [%s] mỗi thành viên cống hiến %d điểm Guild", lpGuildInfo->Name, GuildWin.Score);
					//===============================================
					// Phần thưởng cho mỗi thành viên
					for (int n = OBJECT_START_USER; n < MAX_OBJECT; n++)
					{
						if (gObjIsConnectedGP(n) != 0 && gObj[n].Type == OBJECT_USER)
						{
							if (strcmp(gObj[n].GuildName, lpGuildInfo->Name) == 0)
							{
								LogAdd(LOG_EVENT, "[BossGuild] Phần thưởng thành viên Guild chiến thắng: %s", gObj[n].Name);

								GDSetCoinSend(gObj[n].Index, +(GuildWin.WCoin), +(GuildWin.WCoinP), +(GuildWin.GobinP), "BossGuild");
								gCashShop.CGCashShopPointRecv(gObj[n].Index);

								if (GuildWin.IndexBonus > 0)
								{
									gItemBagManager.DropItemByIndexItemBag(GuildWin.IndexItemBag, &gObj[n]); // Gui Item cho NV
								}
							}
						}
					}
					gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Guild Chiến thắng, Mỗi thành viên tham gia sẽ nhận được [ %d WC, %d WP, %d GP ]", GuildWin.WCoin, GuildWin.WCoinP, GuildWin.GobinP);
					//===============================================
					// Sét điểm Guild về 0
					for (int n = 0; n < MAX_OBJECT; n++)
					{
						if (gObjIsConnectedGP(n) == 0)
						{
							continue;
						}
						LPOBJ lpObj = &gObj[n];
						if (lpObj->Guild != 0)
						{
							lpObj->Guild->TotalScore1 = 0;
							DGGuildScoreUpdate1(lpObj->Guild->Name, lpObj->Guild->TotalScore1);
						}
					}
					//===============================================
				}
			}
			this->m_RemainTimeWinner--;

			if (this->m_RemainTimeWinner <= 0)
			{
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "[BossGuild] Đã kết thúc !");
				LogAdd(LOG_EVENT, "[BossGuild] Finish 1");
				for (int n = 0; n < MAX_CHAR; n++)
				{
					if (this->Char[n].Index == -1)
					{
						continue;
					}
					gObjMoveGate(this->Char[n].Index, 22); //Move tat ca cac thanh nien ve 
				}
				this->Clear();
				this->ClearMonster();
				//=== test ghi vao file txt
				char	Stringg[20] = { 0 };
				wsprintf(Stringg, "GuildName =");
				ofstream myfile;
				myfile.open("..\\Data\\Event\\BossGuild\\GuildWin.ini");
				myfile << "[GuildWinOLD]\n";
				myfile << Stringg;
				myfile.close();
				//=== test ghi vao file txt
			}
		}
		else
		{
			LogAdd(LOG_EVENT, "[BossGuild] Finish 2");
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "[BossGuild] Đã kết thúc không có Guild chiến thắng !");
			// set diem kill boss ve 0
			for (int n = OBJECT_START_USER; n < MAX_OBJECT; n++)
			{
				if (gObjIsConnectedGP(n) == 0)
				{
					continue;
				}

				LPOBJ lpObj = &gObj[n];

				if (lpObj->Guild != 0)
				{
					lpObj->Guild->TotalScore1 = 0;
					DGGuildScoreUpdate1(lpObj->Guild->Name, lpObj->Guild->TotalScore1);
				}
			}
			for (int n = 0; n < MAX_CHAR; n++)
			{
				if (this->Char[n].Index == -1)
				{
					continue;
				}
				gObjMoveGate(this->Char[n].Index, 22); //Move tat ca cac thanh nien ve 
			}
			this->m_RemainTimeWinner = 0;
			this->Clear();
			this->ClearMonster();
			//=== test ghi vao file txt
			char	Stringg[20] = { 0 };
			wsprintf(Stringg, "GuildName =");
			ofstream myfile;
			myfile.open("..\\Data\\Event\\BossGuild\\GuildWin.ini");
			myfile << "[GuildWinOLD]\n";
			myfile << Stringg;
			myfile.close();
			//=== test ghi vao file txt
		}
	}
}

void CBossGuild::ProcState_BLANK() // OK
{

}

// ok
void CBossGuild::ProcState_EMPTY() // OK
{

	if (this->m_RemainTime > 0 && this->m_RemainTime <= (this->m_WarningTime * 60))
	{
		int minutes = this->m_RemainTime / 60;

		if ((this->m_RemainTime % 60) == 0)
		{
			minutes--;
		}

		if (this->MinutesLeft != minutes)
		{
			this->MinutesLeft = minutes;

			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "[BossGuild] Bắt đầu sau %d phút !", (MinutesLeft + 1));
		}
		if (this->m_Active == 0) { this->m_Active = 1; }
	}

	if (this->m_RemainTime > 0 && this->m_RemainTime <= 5)
	{
		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "[BossGuild] Bắt đầu sau %d giây !", m_RemainTime);
	}

	if (this->m_RemainTime <= 0)
	{
		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "[BossGuild] Sự kiện bắt đầu !"); //Bat Dau Su Kien

		this->SetState(BOSSGUILD_STATE_START);
	}
}

// ok
void CBossGuild::ProcState_START() // OK
{
	if (this->m_RemainTime > 0 && this->m_RemainTime <= 300)
	{
		int minutes = this->m_RemainTime / 60;

		if (this->MinutesLeft != minutes)
		{
			this->MinutesLeft = minutes;

			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "[BossGuild] Sẽ kết thúc sau %d phút !", (MinutesLeft + 1));
		}
	}

	if (this->m_RemainTime <= 0)
	{
		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "[BossGuild] Đã kết thúc !");

		this->m_RemainTimeWinner = 40; //Thoi Gian dem nguoc trao thuong

		this->m_Active = 0;

		this->SetState(BOSSGUILD_STATE_EMPTY);
	}
}

// ok
void CBossGuild::SetState(int state) // OK
{
	this->m_State = state;

	switch (this->m_State)
	{
	case BOSSGUILD_STATE_BLANK:
		this->SetState_BLANK();
		break;
	case BOSSGUILD_STATE_EMPTY:
		this->SetState_EMPTY();
		break;
	case BOSSGUILD_STATE_START:
		this->SetState_START();
		break;
	}
}

// ok
void CBossGuild::SetState_BLANK() // OK
{

}

// ok
void CBossGuild::SetState_EMPTY() // OK
{
	this->CheckSync();
}

// ok
void CBossGuild::SetState_START() // OK
{
	this->m_Active = 2;

	this->m_RemainTime = this->m_EventTime * 60;

	this->m_TargetTime = (int)(time(0) + this->m_RemainTime);

	if (this->CheDo1 == 1)
	{
		this->StartBossPhuThuy(); // Boss xuất hiện đầu tiên
	}

	if (this->CheDo2 == 1)
	{
		this->StartBossThuatSi(); // Boss xuất hiện đầu tiên
	}

	this->SendTimeBossGuild(0, 0);

	LogAdd(LOG_EVENT, "[BossGuild] Bắt Đầu Event Boss Guild");

}

// ok
void CBossGuild::CheckSync() // OK
{
	if (this->m_BossGuildStartTime.empty() != 0)
	{
		this->SetState(BOSSGUILD_STATE_BLANK);
		return;
	}

	CTime ScheduleTime;

	CScheduleManager ScheduleManager;

	for (std::vector<BOSSGUILD_START_TIME>::iterator it = this->m_BossGuildStartTime.begin(); it != this->m_BossGuildStartTime.end(); it++)
	{
		ScheduleManager.AddSchedule(it->Year, it->Month, it->Day, it->Hour, it->Minute, it->Second, it->DayOfWeek);
	}

	if (ScheduleManager.GetSchedule(&ScheduleTime) == 0)
	{
		this->SetState(BOSSGUILD_STATE_BLANK);
		return;
	}

	this->m_RemainTime = (int)difftime(ScheduleTime.GetTime(), time(0));

	this->m_TargetTime = (int)ScheduleTime.GetTime();

}

// ok
void CBossGuild::CGPacketBossGuild(BOSSGUILD_CGPACKET* aRecv, int aIndex)
{
	if (!this->m_Enabled)
	{
		return;
	}
	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}
	LPOBJ lpObj = &gObj[aIndex];

	if ((GetTickCount() - lpObj->ClickClientSend) < 2000) {
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đang Thao Tác Qúa Nhanh Vui Lòng Chờ Đợi !");
		return;
	}

	GUILD_INFO_STRUCT * lpGuildInfo = lpObj->Guild;

	if (this->m_Active == 0 || this->m_Active == 2) //Verifica se o evento está em andamento
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chưa đến thời gian sự kiện");
		return;
	}

	if (lpGuildInfo == NULL)
	{

		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "[BossGuild] Không thấy thông tin Guild của bạn");
		return;
	}

	if (lpObj->GuildNumber == 0) //Verifica se o personagem faz parte de uma guild
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "[BossGuild] Bạn chưa vào Guild nên không thể tham gia !");
		return;
	}

	if (lpGuildInfo->TotalCount < this->GuildMinPlayer) //So Thanh Vien Toi Thieu Tham Gia
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "[BossGuild] Guild bạn không đủ người than gia !");
		return;
	}
	int CongVao = aRecv->CongVao;
	this->SetChar(lpObj->Index, CongVao);
	gObjMoveGate(lpObj->Index, this->GateMove[CongVao]);
	this->SendTimeBossGuild(lpObj->Index, 1);

}

// ok
void CBossGuild::SendTimeBossGuild(int aIndex, int Type) //Gui thong tin ve CLient
{
	BOSSGUILDTIME_SENDCLIENT pMsg;
	pMsg.header.set(0xF3, 0x36, sizeof(pMsg));

	if (Type == 1)
	{
		//=== Send 1 Client===//
		if (gObjIsConnectedGP(aIndex) == 0)
		{
			return;
		}
		LPOBJ lpObj = &gObj[aIndex];
		pMsg.TimeBossGuild = this->m_RemainTime;
		DataSend(lpObj->Index, (BYTE*)&pMsg, pMsg.header.size);
	}
	else
	{
		//=== Send All ==//
		for (int n = OBJECT_START_USER; n < MAX_OBJECT; n++)
		{
			if (gObjIsConnectedGP(n) != 0 && gObj[n].Map == this->m_MapBossGuild)
			{
				pMsg.TimeBossGuild = this->m_RemainTime;
				DataSend(n, (BYTE*)&pMsg, pMsg.header.size);
			}
		}
	}
}

// ok
void SendInfoBossGuild(int aIndex) // ok
{
	// Gửi Lên Client
	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	INFOBOSSGUILD_SENDCLIENT pMsg;

	pMsg.header.set(0xF3, 0x35, sizeof(pMsg)); // sửa lại

	pMsg.OpenWindow = 1;

	DataSend(lpObj->Index, (BYTE*)&pMsg, pMsg.header.size);
}

// ok
bool CBossGuild::Dialog(int aIndex, int aNpcIndex) // ok
{
	// Click NPC
	if (!this->m_Enabled)
	{
		return false;
	}
	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return false;
	}
	LPOBJ lpUser = &gObj[aIndex];
	LPOBJ lpNpc = &gObj[aNpcIndex];

	if (lpNpc->Class == this->Class
		&&	lpNpc->Map == this->Map
		&&	lpNpc->X == this->X
		&&	lpNpc->Y == this->Y)
	{
		//=== Gui Info ve CLient
		SendInfoBossGuild(aIndex);
		return true;
	}
	// ----
	return false;
}

// ok
void CBossGuild::AddGuild(int gIndex) // Set Guild tham gia Su Kien
{

	LPOBJ lpObj = &gObj[gIndex];
	for (int n = 0; n < MAX_GUILD; n++)
	{
		if (this->Guild[n].Number >= 0)
		{
			continue;
		}

		this->Guild[n].Number = lpObj->GuildNumber;
		this->Guild[n].Owner = 0;
		memcpy(this->Guild[n].GuildOwner, lpObj->GuildName, sizeof(this->Guild[n].GuildOwner));
		return;
	}
}

// ok
bool CBossGuild::GetGuild(int gIndex) // OK
{
	for (int n = 0; n < MAX_GUILD; n++)
	{
		if (this->Guild[n].Number == gIndex)
		{
			return 1;
		}
	}
	return 0;
}

// ok
void CBossGuild::SetChar(int cIndex, int CongVao) // OK
{

	if (this->GetChar(cIndex) == 0)
	{
		this->AddChar(cIndex, CongVao);
	}

}

// ok
void CBossGuild::AddChar(int cIndex, int CongVao) // OK
{
	for (int n = 0; n < MAX_CHAR; n++)
	{
		if (this->Char[n].Index >= 0)
		{
			continue;
		}

		this->Char[n].Index = cIndex;
		memcpy(this->Char[n].Name, gObj[cIndex].Name, sizeof(gObj[cIndex].Name));
		this->Char[n].CongVao = CongVao;
		LogAdd(LOG_RED, "Add Nhân Vật %s Cổng %d", this->Char[n].Name, CongVao);
		return;
	}
}

// ok
int CBossGuild::GetCongVao(int cIndex) // OK
{
	for (int n = 0; n < MAX_CHAR; n++)
	{
		if (this->Char[n].Index == cIndex)
		{
			return this->Char[n].CongVao;
		}
	}
	return 0;
}

// ok
bool CBossGuild::GetChar(int cIndex) // OK
{
	for (int n = 0; n < MAX_CHAR; n++)
	{
		if (this->Char[n].Index == cIndex)
		{
			return 1;
		}
	}
	return 0;
}

// ok
void CBossGuild::CheckChar() // OK
{
	for (int n = 0; n < MAX_CHAR; n++)
	{
		if (OBJECT_RANGE(this->Char[n].Index) == 0)
		{
			continue;
		}
		if (strcmp(this->Char[n].Name, gObj[this->Char[n].Index].Name) == 0)
		{
			this->Char[n].Reset();
			return;
		}
	}
	return;
}

// chua ro lam
bool CBossGuild::CheckPlayerTarget(LPOBJ lpObj, LPOBJ lpTarget, int Type) // OK
{
	if (Type == 1) //Attack
	{
		if (lpObj->Map == this->m_MapBossGuild)
		{
			///	LogAdd(LOG_RED, "DEBUG 1 Attack %d", lpObj->GuildNumber);
			if (lpObj->GuildNumber == 0 && lpObj->Type == OBJECT_USER)
			{
				gObjMoveGate(lpObj->Index, 17); //Move tat ca cac thanh nien ve 
				return 1;
			}
			if (lpObj->Type == OBJECT_USER && lpTarget->Type == OBJECT_MONSTER)
			{
				if (lpObj->GuildNumber == lpTarget->GuildNumber &&  lpObj->GuildNumber)
				{
					return 1;
				}
			}

		}
	}
	else //View PK
	{
		if (lpObj->Map == this->m_MapBossGuild)
		{
			if (lpTarget->GuildNumber != lpObj->GuildNumber)
			{
				return 1;
			}
		}

	}
	return 0;
}

// ok
bool CBossGuild::GetUserRespawnLocation(LPOBJ lpObj, int* gate, int* map, int* x, int* y, int* dir, int* level) // OK
{

	if (this->m_Enabled == 0)
	{
		return 0;
	}

	if (this->GetChar(lpObj->Index) == 0)
	{
		return 0;
	}

	int CongVao = this->GetCongVao(lpObj->Index);

	{
		if (gGate.GetGate(this->GateMove[CongVao], gate, map, x, y, dir, level) != 0)
		{
			return 1;
		}
	}

	return 0;
}

void CBossGuild::StartBossPhuThuy() // OK
{
	LogAdd(LOG_RED, "[BossGuild] Bắt Đầu Boss Pháp Sư");
	int qtd = 1;
	qtd = (qtd > 0) ? qtd : 1;
	for (int n = 0; n < qtd; n++)
	{
		int index = gObjAddMonster(this->m_MapBossGuild);
		if (OBJECT_RANGE(index) == 0)
		{
			continue;
		}
		LPOBJ lpObj = &gObj[index];
		// Tọa Độ
		int px = 67;
		int py = 158;
		lpObj->PosNum = -1;
		lpObj->X = px;
		lpObj->Y = py;
		lpObj->TX = px;
		lpObj->TY = py;
		lpObj->OldX = px;
		lpObj->OldY = py;
		lpObj->StartX = px;
		lpObj->StartY = py;
		lpObj->Dir = GetLargeRand() % 8;
		lpObj->Map = this->m_MapBossGuild;
		lpObj->MonsterDeleteTime = GetTickCount() + 1800000;
		if (gObjSetMonster(index, 701) == 0)
		{
			gObjDel(index);
			continue;
		}
		lpObj->DieRegen = 0;
		lpObj->RegenTime = 1;
		lpObj->MoveRange = 10;
		lpObj->Attribute = 701;
		lpObj->MaxRegenTime = 1000;
		lpObj->LastCheckTick = GetTickCount();
	}
}

void CBossGuild::StartBossChienBinh() // OK
{
	LogAdd(LOG_RED, "[BossGuild] Bắt Đầu Boss Chiến Binh");
	int qtd = 1;
	qtd = (qtd > 0) ? qtd : 1;
	for (int n = 0; n < qtd; n++)
	{
		int index = gObjAddMonster(this->m_MapBossGuild);
		if (OBJECT_RANGE(index) == 0)
		{
			continue;
		}
		LPOBJ lpObj = &gObj[index];
		// Tọa Độ
		int px = 67;
		int py = 158;
		lpObj->PosNum = -1;
		lpObj->X = px;
		lpObj->Y = py;
		lpObj->TX = px;
		lpObj->TY = py;
		lpObj->OldX = px;
		lpObj->OldY = py;
		lpObj->StartX = px;
		lpObj->StartY = py;
		lpObj->Dir = GetLargeRand() % 8;
		lpObj->Map = this->m_MapBossGuild;
		lpObj->MonsterDeleteTime = GetTickCount() + 1800000;
		if (gObjSetMonster(index, 700) == 0)
		{
			gObjDel(index);
			continue;
		}
		lpObj->DieRegen = 0;
		lpObj->RegenTime = 1;
		lpObj->MoveRange = 10;
		lpObj->Attribute = 700;
		lpObj->MaxRegenTime = 1000;
		lpObj->LastCheckTick = GetTickCount();
	}
}

void CBossGuild::StartBossTienNu() // OK
{
	LogAdd(LOG_RED, "[BossGuild] Bắt Đầu Boss Tiên Nữ");
	int qtd = 1;
	qtd = (qtd > 0) ? qtd : 1;
	for (int n = 0; n < qtd; n++)
	{
		int index = gObjAddMonster(this->m_MapBossGuild);

		if (OBJECT_RANGE(index) == 0)
		{
			continue;
		}
		LPOBJ lpObj = &gObj[index];
		int px = 67;
		int py = 158;
		lpObj->PosNum = -1;
		lpObj->X = px;
		lpObj->Y = py;
		lpObj->TX = px;
		lpObj->TY = py;
		lpObj->OldX = px;
		lpObj->OldY = py;
		lpObj->StartX = px;
		lpObj->StartY = py;
		lpObj->Dir = GetLargeRand() % 8;
		lpObj->Map = this->m_MapBossGuild;
		lpObj->MonsterDeleteTime = GetTickCount() + 1800000;
		if (gObjSetMonster(index, 702) == 0)
		{
			gObjDel(index);
			continue;
		}
		lpObj->DieRegen = 0;
		lpObj->RegenTime = 1;
		lpObj->MoveRange = 10;
		lpObj->Attribute = 702;
		lpObj->MaxRegenTime = 1000;
		lpObj->LastCheckTick = GetTickCount();
	}
}

void CBossGuild::StartBossThuatSi() // OK
{
	LogAdd(LOG_RED, "[BossGuild] Bắt Đầu Boss Thuật Sĩ");
	int qtd = 1;
	qtd = (qtd > 0) ? qtd : 1;
	for (int n = 0; n < qtd; n++)
	{
		int index = gObjAddMonster(this->m_MapBossGuild);
		if (OBJECT_RANGE(index) == 0)
		{
			continue;
		}
		LPOBJ lpObj = &gObj[index];
		// Tọa Độ
		int px = 67;
		int py = 158;
		lpObj->PosNum = -1;
		lpObj->X = px;
		lpObj->Y = py;
		lpObj->TX = px;
		lpObj->TY = py;
		lpObj->OldX = px;
		lpObj->OldY = py;
		lpObj->StartX = px;
		lpObj->StartY = py;
		lpObj->Dir = GetLargeRand() % 8;
		lpObj->Map = this->m_MapBossGuild;
		lpObj->MonsterDeleteTime = GetTickCount() + 1800000;
		if (gObjSetMonster(index, 705) == 0)
		{
			gObjDel(index);
			continue;
		}
		lpObj->DieRegen = 0;
		lpObj->RegenTime = 1;
		lpObj->MoveRange = 10;
		lpObj->Attribute = 705;
		lpObj->MaxRegenTime = 1000;
		lpObj->LastCheckTick = GetTickCount();
	}
}

void CBossGuild::StartBossThietBinh() // OK
{
	LogAdd(LOG_RED, "[BossGuild] Bắt Đầu Boss Thiết Binh");
	int qtd = 1;
	qtd = (qtd > 0) ? qtd : 1;
	//----------------------------------
	for (int n = 0; n < qtd; n++)
	{
		int index = gObjAddMonster(this->m_MapBossGuild);
		if (OBJECT_RANGE(index) == 0)
		{
			continue;
		}
		LPOBJ lpObj = &gObj[index];
		// Tọa Độ
		int px = 74;
		int py = 165;
		lpObj->PosNum = -1;
		lpObj->X = px;
		lpObj->Y = py;
		lpObj->TX = px;
		lpObj->TY = py;
		lpObj->OldX = px;
		lpObj->OldY = py;
		lpObj->StartX = px;
		lpObj->StartY = py;
		lpObj->Dir = GetLargeRand() % 8;
		lpObj->Map = this->m_MapBossGuild;
		lpObj->MonsterDeleteTime = GetTickCount() + 1800000;
		if (gObjSetMonster(index, 706) == 0)
		{
			gObjDel(index);
			continue;
		}
		lpObj->DieRegen = 0;
		lpObj->RegenTime = 1;
		lpObj->MoveRange = 10;
		lpObj->Attribute = 706;
		lpObj->MaxRegenTime = 1000;
		lpObj->LastCheckTick = GetTickCount();
	}
}

void CBossGuild::StartBossDauSi() // OK
{
	LogAdd(LOG_RED, "[BossGuild] Bắt Đầu Boss Đấu Sĩ ");
	int qtd = 1;
	qtd = (qtd > 0) ? qtd : 1;
	for (int n = 0; n < qtd; n++)
	{
		int index = gObjAddMonster(this->m_MapBossGuild);
		if (OBJECT_RANGE(index) == 0)
		{
			continue;
		}
		LPOBJ lpObj = &gObj[index];
		// Tọa Độ
		int px = 67;
		int py = 158;
		lpObj->PosNum = -1;
		lpObj->X = px;
		lpObj->Y = py;
		lpObj->TX = px;
		lpObj->TY = py;
		lpObj->OldX = px;
		lpObj->OldY = py;
		lpObj->StartX = px;
		lpObj->StartY = py;
		lpObj->Dir = GetLargeRand() % 8;
		lpObj->Map = this->m_MapBossGuild;
		lpObj->MonsterDeleteTime = GetTickCount() + 1800000;
		if (gObjSetMonster(index, 703) == 0)
		{
			gObjDel(index);
			continue;
		}
		lpObj->DieRegen = 0;
		lpObj->RegenTime = 1;
		lpObj->MoveRange = 10;
		lpObj->Attribute = 703;
		lpObj->MaxRegenTime = 1000;
		lpObj->LastCheckTick = GetTickCount();
	}
}

void CBossGuild::StartBossChuaTe() // OK
{
	LogAdd(LOG_RED, "[BossGuild] Bắt Đầu Boss Chúa Tể");
	int qtd = 1;
	qtd = (qtd > 0) ? qtd : 1;
	for (int n = 0; n < qtd; n++)
	{
		int index = gObjAddMonster(this->m_MapBossGuild);
		if (OBJECT_RANGE(index) == 0)
		{
			continue;
		}
		LPOBJ lpObj = &gObj[index];
		// Tọa Độ
		int px = 74;
		int py = 165;
		lpObj->PosNum = -1;
		lpObj->X = px;
		lpObj->Y = py;
		lpObj->TX = px;
		lpObj->TY = py;
		lpObj->OldX = px;
		lpObj->OldY = py;
		lpObj->StartX = px;
		lpObj->StartY = py;
		lpObj->Dir = GetLargeRand() % 8;
		lpObj->Map = this->m_MapBossGuild;
		lpObj->MonsterDeleteTime = GetTickCount() + 1800000;
		if (gObjSetMonster(index, 704) == 0)
		{
			gObjDel(index);
			continue;
		}
		lpObj->DieRegen = 0;
		lpObj->RegenTime = 1;
		lpObj->MoveRange = 10;
		lpObj->Attribute = 704;
		lpObj->MaxRegenTime = 1000;
		lpObj->LastCheckTick = GetTickCount();
	}
}

void CBossGuild::ClearMonster() // OK
{
	for (int n = 0; n < MAX_OBJECT_MONSTER; n++)
	{
		if (gObjIsConnected(n) != 0 && gObj[n].Attribute == 700)
		{
			gObjDel(n);
		}
	}
	for (int n = 0; n < MAX_OBJECT_MONSTER; n++)
	{
		if (gObjIsConnected(n) != 0 && gObj[n].Attribute == 701)
		{
			gObjDel(n);
		}
	}
	for (int n = 0; n < MAX_OBJECT_MONSTER; n++)
	{
		if (gObjIsConnected(n) != 0 && gObj[n].Attribute == 702)
		{
			gObjDel(n);
		}
	}
	for (int n = 0; n < MAX_OBJECT_MONSTER; n++)
	{
		if (gObjIsConnected(n) != 0 && gObj[n].Attribute == 703)
		{
			gObjDel(n);
		}
	}
	for (int n = 0; n < MAX_OBJECT_MONSTER; n++)
	{
		if (gObjIsConnected(n) != 0 && gObj[n].Attribute == 704)
		{
			gObjDel(n);
		}
	}
	for (int n = 0; n < MAX_OBJECT_MONSTER; n++)
	{
		if (gObjIsConnected(n) != 0 && gObj[n].Attribute == 705)
		{
			gObjDel(n);
		}
	}
	for (int n = 0; n < MAX_OBJECT_MONSTER; n++)
	{
		if (gObjIsConnected(n) != 0 && gObj[n].Attribute == 706)
		{
			gObjDel(n);
		}
	}
	LogAdd(LOG_RED, "[BossGuild] Xóa Qoái Vật Boss Guild");
}

// dang lam dở
bool CBossGuild::MonsterDie(int aIndexMonster, int aIndexUser)
{
	bool Result = false;

	if (!this->m_Enabled)
	{
		return false;
	}

	LPOBJ lpUser = &gObj[aIndexUser];
	LPOBJ lpMonster = &gObj[aIndexMonster];

	int GuildNumber;

	//------------------------------------------
	if ((lpMonster->Class == 701) && lpMonster->Map == this->m_MapBossGuild)
	{
		gObjDel(701);

		if (lpUser->Guild != 0)
		{
			lpUser->Guild->TotalScore1 += 1;
			DGGuildScoreUpdate1(lpUser->Guild->Name, lpUser->Guild->TotalScore1);
		}

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "[BossGuild] Guild %s đã tiêu diệt Boss Phù Thủy", lpUser->GuildName, (lpUser->GuildNumber, lpUser->Index));

		GDSetCoinSend(lpUser->Index, +(BossPhuThuy.WCoin), +(BossPhuThuy.WCoinP), +(BossPhuThuy.GobinP), "BossPhuThuy");
		gCashShop.CGCashShopPointRecv(lpUser->Index);

		if (BossPhuThuy.IndexBonus > 0)
		{
			GDCreateItemSend(lpUser->Index, 0xEB, 0, 0, GET_ITEM(BossPhuThuy.IndexType, BossPhuThuy.IndexItem), 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);
		}

		this->StartBossChienBinh(); // Tạo ra Boss

		Result = true;
	}
	//------------------------------------------
	if ((lpMonster->Class == 700) && lpMonster->Map == this->m_MapBossGuild)
	{
		gObjDel(700);

		if (lpUser->Guild != 0)
		{
			lpUser->Guild->TotalScore1 += 1;
			DGGuildScoreUpdate1(lpUser->Guild->Name, lpUser->Guild->TotalScore1);
		}

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "[BossGuild] Guild %s đã tiêu diệt Boss Chiến Binh", lpUser->GuildName, (lpUser->GuildNumber, lpUser->Index));

		GDSetCoinSend(lpUser->Index, +(BossChienBinh.WCoin), +(BossChienBinh.WCoinP), +(BossChienBinh.GobinP), "BossChienBinh");
		gCashShop.CGCashShopPointRecv(lpUser->Index);

		if (BossChienBinh.IndexBonus > 0)
		{
			GDCreateItemSend(lpUser->Index, 0xEB, 0, 0, GET_ITEM(BossChienBinh.IndexType, BossChienBinh.IndexItem), 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);
		}

		this->StartBossTienNu(); // Tạo ra Boss

		Result = true;
	}
	//------------------------------------------
	if ((lpMonster->Class == 702) && lpMonster->Map == this->m_MapBossGuild)
	{
		gObjDel(702);

		if (lpUser->Guild != 0)
		{
			lpUser->Guild->TotalScore1 += 1;
			DGGuildScoreUpdate1(lpUser->Guild->Name, lpUser->Guild->TotalScore1);
		}

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "[BossGuild] Guild %s đã tiêu diệt Boss Tiên Nữ", lpUser->GuildName, (lpUser->GuildNumber, lpUser->Index));

		GDSetCoinSend(lpUser->Index, +(BossTienNu.WCoin), +(BossTienNu.WCoinP), +(BossTienNu.GobinP), "BossTienNu");
		gCashShop.CGCashShopPointRecv(lpUser->Index);

		if (BossTienNu.IndexBonus > 0)
		{
			GDCreateItemSend(lpUser->Index, 0xEB, 0, 0, GET_ITEM(BossTienNu.IndexType, BossTienNu.IndexItem), 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);
		}
		Result = true;
	}
	//------------------------------------------
	//------------------------------------------
	// Boss Thuật Sĩ
	if ((lpMonster->Class == 705) && lpMonster->Map == this->m_MapBossGuild)
	{
		gObjDel(705);

		if (lpUser->Guild != 0)
		{
			lpUser->Guild->TotalScore1 += 1;
			DGGuildScoreUpdate1(lpUser->Guild->Name, lpUser->Guild->TotalScore1);
		}

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "[BossGuild] Guild %s đã tiêu diệt Boss Thuật Sĩ", lpUser->GuildName, (lpUser->GuildNumber, lpUser->Index));

		GDSetCoinSend(lpUser->Index, +(BossThuatSi.WCoin), +(BossThuatSi.WCoinP), +(BossThuatSi.GobinP), "BossThuatSi");
		gCashShop.CGCashShopPointRecv(lpUser->Index);

		if (BossThuatSi.IndexBonus > 0)
		{
			GDCreateItemSend(lpUser->Index, 0xEB, 0, 0, GET_ITEM(BossThuatSi.IndexType, BossThuatSi.IndexItem), 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);
		}

		this->StartBossThietBinh(); //  Tạo ra Boss

		Result = true;
	}
	//------------------------------------------
	// Boss Thiết Binh
	if ((lpMonster->Class == 706) && lpMonster->Map == this->m_MapBossGuild)
	{
		gObjDel(706);

		if (lpUser->Guild != 0)
		{
			lpUser->Guild->TotalScore1 += 1;
			DGGuildScoreUpdate1(lpUser->Guild->Name, lpUser->Guild->TotalScore1);
		}

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "[BossGuild] Guild %s đã tiêu diệt Boss Thiết Binh", lpUser->GuildName, (lpUser->GuildNumber, lpUser->Index));

		GDSetCoinSend(lpUser->Index, +(BossThietBinh.WCoin), +(BossThietBinh.WCoinP), +(BossThietBinh.GobinP), "BossThietBinh");
		gCashShop.CGCashShopPointRecv(lpUser->Index);

		if (BossThietBinh.IndexBonus > 0)
		{
			GDCreateItemSend(lpUser->Index, 0xEB, 0, 0, GET_ITEM(BossThietBinh.IndexType, BossThietBinh.IndexItem), 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);
		}

		this->StartBossDauSi(); //  Tạo ra Boss

		Result = true;
	}
	//------------------------------------------
	// Boss Đấu Sĩ
	if ((lpMonster->Class == 703) && lpMonster->Map == this->m_MapBossGuild)
	{
		gObjDel(703);

		if (lpUser->Guild != 0)
		{
			lpUser->Guild->TotalScore1 += 1;
			DGGuildScoreUpdate1(lpUser->Guild->Name, lpUser->Guild->TotalScore1);
		}

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "[BossGuild] Guild %s đã tiêu diệt Boss Đấu Sĩ", lpUser->GuildName, (lpUser->GuildNumber, lpUser->Index));

		GDSetCoinSend(lpUser->Index, +(BossDauSi.WCoin), +(BossDauSi.WCoinP), +(BossDauSi.GobinP), "BossDauSi");
		gCashShop.CGCashShopPointRecv(lpUser->Index);

		if (BossDauSi.IndexBonus > 0)
		{
			GDCreateItemSend(lpUser->Index, 0xEB, 0, 0, GET_ITEM(BossDauSi.IndexType, BossDauSi.IndexItem), 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);
		}

		this->StartBossChuaTe(); //  Tạo ra Boss

		Result = true;
	}
	//------------------------------------------
	// Boss Đấu Sĩ
	if ((lpMonster->Class == 704) && lpMonster->Map == this->m_MapBossGuild)
	{
		gObjDel(704);

		if (lpUser->Guild != 0)
		{
			lpUser->Guild->TotalScore1 += 1;
			DGGuildScoreUpdate1(lpUser->Guild->Name, lpUser->Guild->TotalScore1);
		}

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "[BossGuild] Guild %s đã tiêu diệt Boss Chúa Tể", lpUser->GuildName, (lpUser->GuildNumber, lpUser->Index));

		GDSetCoinSend(lpUser->Index, +(BossChuaTe.WCoin), +(BossChuaTe.WCoinP), +(BossChuaTe.GobinP), "BossChuaTe");
		gCashShop.CGCashShopPointRecv(lpUser->Index);

		if (BossChuaTe.IndexBonus > 0)
		{
			GDCreateItemSend(lpUser->Index, 0xEB, 0, 0, GET_ITEM(BossChuaTe.IndexType, BossChuaTe.IndexItem), 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0xFF, 0);
		}


		Result = true;
	}
	//------------------------------------------
	// Điều kiện guild win
	for (int n = 0; n < MAX_GUILD; n++)
	{
		if (this->GetGuild(GuildNumber) == 0)
		{
			this->AddGuild(aIndexUser);
		}
		if (lpUser->Guild != 0)
		{
			if (lpUser->Guild->TotalScore1 >= this->KillBoss) // set guild win
			{
				this->WinnerNumber = this->Guild[n].Number;
				memcpy(this->WinnerName, lpUser->GuildName, sizeof(this->WinnerName));
				WritePrivateProfileStringA("GuildWinOLD", "GuildName", this->WinnerName, "..\\Data\\Event\\BossGuild\\GuildWin.ini");
			}
		}
	}
	return Result;
}

// ok
void CBossGuild::StartBossGuild() // ok
{
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	int hour = aTime->tm_hour;
	int minute = aTime->tm_min + 2;

	if (minute >= 60)
	{
		hour++;
		minute = minute - 60;
	}

	BOSSGUILD_START_TIME info;

	info.Year = -1;

	info.Month = -1;

	info.Day = -1;

	info.DayOfWeek = -1;

	info.Hour = hour;

	info.Minute = minute;

	info.Second = 0;

	this->m_BossGuildStartTime.push_back(info);

	LogAdd(LOG_EVENT, "[Set Boss Guild Bắt Đầu] At %2d:%2d:00", hour, minute);

	this->Init();
}


struct BOSSGUILD_UPDATE
{
	PBMSG_HEAD3 h;
	int CheDo1;
	int CheDo2;
	int KillBoss;
	int Score;
	int WCoinC;
	int PhuThuyWCoinC;
	int ChienBinhWCoinC;
	int TienNuWCoinC;
	int ThuatSiWCoinC;
	int ThietBinhWCoinC;
	int DauSiWCoinC;
	int ChuaTeWCoinC;
};

void BossGuildDataSend(int aIndex)
{
	BOSSGUILD_UPDATE rSend;
	LPOBJ lpObj = &gObj[aIndex];
	rSend.h.set((LPBYTE)&rSend, 0xF3, 110, sizeof(rSend));

	rSend.CheDo1 = gBossGuild.CheDo1;
	rSend.CheDo2 = gBossGuild.CheDo2;
	rSend.KillBoss = gBossGuild.KillBoss;
	rSend.Score = gBossGuild.GuildWin.Score;
	rSend.WCoinC = gBossGuild.GuildWin.WCoin;
	rSend.PhuThuyWCoinC = gBossGuild.BossPhuThuy.WCoin;
	rSend.ChienBinhWCoinC = gBossGuild.BossChienBinh.WCoin;
	rSend.TienNuWCoinC = gBossGuild.BossTienNu.WCoin;
	rSend.ThuatSiWCoinC = gBossGuild.BossThuatSi.WCoin;
	rSend.ThietBinhWCoinC = gBossGuild.BossThietBinh.WCoin;
	rSend.DauSiWCoinC = gBossGuild.BossDauSi.WCoin;
	rSend.ChuaTeWCoinC = gBossGuild.BossChuaTe.WCoin;

	DataSend(aIndex, (LPBYTE)&rSend, sizeof(rSend));
}

#endif
