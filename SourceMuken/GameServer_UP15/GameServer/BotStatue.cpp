#include "stdafx.h"
#include "BotStatue.h"
#include "Monster.h"
#include "Protocol.h"
#include "Util.h"
#include "MemScript.h"
#include "Message.h"
#include "Notice.h"
#include "User.h"
#include "ItemManager.h"
#include "Map.h"
#include "ScheduleManager.h"
#include "ObjectManager.h"
#include "DSProtocol.h"
#include "SkillManager.h"
#include "MuunSystem.h"
#include "GensSystem.h"
#include "PcPoint.h"
#include "ESProtocol.h"
#include "GuildClass.h"
#include "CustomRankUser.h"

#if (BOT_STATUE == 1)

ObjBOTSTATUE ObjBotStatue;

void ObjBOTSTATUE::Init()
{
	for (int botNum = 0; botNum<MAX_BOTSTATUE; botNum++)
	{
		if (this->bot[botNum].Enabled == 1)
		{
			int bIndex = this->bot[botNum].index;
			if (gObjIsConnected(bIndex) == 1)
			{
				gObjDel(bIndex);
			}
		}
	}
	//LogAdd(LOG_RED,"DEBUG BOT TUONG Init");
	this->CheckSync();
}

void ObjBOTSTATUE::Read(char * FilePath)
{
	//if(this->Enabled == 1)
	{
		for (int botNum = 0; botNum<MAX_BOTSTATUE; botNum++)
		{
			if (this->bot[botNum].Enabled == 1)
			{
				int bIndex = this->bot[botNum].index;
				if (gObjIsConnected(bIndex) == 1)
				{
					gObjDel(bIndex);
				}
			}
		}
	}
	for (int i = 0; i<MAX_BOTSTATUE; i++)
	{
		this->bot[i].index = -1;
		this->bot[i].Enabled = 0;
	}

	this->m_TimeReloadInfo.clear();
	this->Enabled = 0;
	CMemScript* lpMemScript = new CMemScript;

	if (lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR, FilePath);
		return;
	}

	if (lpMemScript->SetBuffer(FilePath) == 0)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}



	try
	{
		while (true)
		{
			if (lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			int section = lpMemScript->GetNumber();

			while (true)
			{
				if (section == 0)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					STATUE_START_TIME info;

					//int index = lpMemScript->GetNumber();

					info.Year = lpMemScript->GetNumber();

					info.Month = lpMemScript->GetAsNumber();

					info.Day = lpMemScript->GetAsNumber();

					info.DayOfWeek = lpMemScript->GetAsNumber();

					info.Hour = lpMemScript->GetAsNumber();

					info.Minute = lpMemScript->GetAsNumber();

					info.Second = lpMemScript->GetAsNumber();

					this->m_TimeReloadInfo.push_back(info);
				}
				else if (section == 1)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					int BotNum = lpMemScript->GetNumber();
					if (BotNum < 0 || BotNum > MAX_BOTSTATUE - 1)
					{
						ErrorMessageBox("BOTSTATUE error 1: BOTSTATUEIndex: %d out of range!", BotNum);
						return;
					}
					this->bot[BotNum].Enabled = lpMemScript->GetAsNumber();
					this->bot[BotNum].Map = lpMemScript->GetAsNumber();
					this->bot[BotNum].X = lpMemScript->GetAsNumber();
					this->bot[BotNum].Y = lpMemScript->GetAsNumber();
					this->bot[BotNum].Dir = lpMemScript->GetAsNumber();
					this->bot[BotNum].Rank = lpMemScript->GetAsNumber();
					this->bot[BotNum].Type = lpMemScript->GetAsNumber();

					//strncpy_s(this->bot[BotNum].Name,lpMemScript->GetAsString(),sizeof(this->bot[BotNum].Name));

					//LogAdd(LOG_RED,"[BOTSTATUE] Ena %d Name %s", this->bot[BotNum].Enabled,this->bot[BotNum].Name);
				}
				else
				{
					break;
				}
			}
		}
	}
	catch (...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void ObjBOTSTATUE::MainProc()
{
	if ((GetTickCount() - this->m_TickCount) >= 1000)
	{
		this->m_TickCount = GetTickCount();

		this->m_RemainTime = (int)difftime(this->TargetTime, time(0));

		if (this->m_RemainTime <= 0) {

			this->Init(); //Set Lai Time
			this->MakeBot();
			return;

		}
	}
}
void ObjBOTSTATUE::CheckSync() // OK
{
	if (this->m_TimeReloadInfo.empty() != 0)
	{
		return;
	}

	CTime ScheduleTime;

	CScheduleManager ScheduleManager;

	for (std::vector<STATUE_START_TIME>::iterator it = this->m_TimeReloadInfo.begin(); it != this->m_TimeReloadInfo.end(); it++)
	{
		ScheduleManager.AddSchedule(it->Year, it->Month, it->Day, it->Hour, it->Minute, it->Second, it->DayOfWeek);
	}

	if (ScheduleManager.GetSchedule(&ScheduleTime) == 0)
	{
		return;
	}

	this->m_RemainTime = (int)difftime(ScheduleTime.GetTime(), time(0));

	this->TargetTime = (int)ScheduleTime.GetTime();
}

int ObjBOTSTATUE::GetBotIndex(int aIndex)
{
	for (int i = 0; i<MAX_BOTSTATUE; i++)
	{
		if (this->bot[i].Enabled == 1)
		{
			if (this->bot[i].index == aIndex)
				return i;
		}
	}
	return -1;
}
void ObjBOTSTATUE::BotGetInfoSet(SDHP_BOT_INFO_RECV* lpMsg) // OK
{
	int result = lpMsg->index;

	gObjSetBots(result, lpMsg->Class);

	gObj[result].ChangeUp = lpMsg->Class;
	gObj[result].Class = lpMsg->Class;
	gObj[result].Level = lpMsg->Level;
	gObj[result].Life = 1;
	gObj[result].MaxLife = 2;
	gObj[result].Mana = 1;
	gObj[result].MaxMana = 2;
	gObj[result].Experience = 0;
	gObj[result].DBClass = lpMsg->Class;
	gObj[result].Class = lpMsg->Class / 16;
	gObj[result].ChangeUp = lpMsg->Class % 16;

	gObj[result].PKCount = (char)lpMsg->PKCount;
	gObj[result].PKLevel = (char)lpMsg->PKLevel;
	gObj[result].PKTime = lpMsg->PKTime;
	gObj[result].GuildNumber = 0;
	gObj[result].Guild = 0;
	gObj[result].GuildStatus = -1;
	gObj[result].GuildUnionTimeStamp = 0;


	gObj[result].Authority = 1;

	if ((lpMsg->CtlCode & 8) != 0)
	{
		gObj[result].Authority = 2;
	}

	if ((lpMsg->CtlCode & 32) != 0)
	{
		gObj[result].Authority = 32;
	}

	gObj[result].Penalty = 0;

	if ((lpMsg->CtlCode & 2) != 0)
	{
		gObj[result].Penalty = 4;
	}

	//LogAdd(LOG_RED,"[BotGetInfoSet] Set Guild (%s)",lpMsg->GuildName);
	if (strlen(lpMsg->GuildName) > 1)
	{
		//LogAdd(LOG_RED,"[BotGetInfoSet] 2Set Guild (%s)",lpMsg->GuildName);
		memcpy(gObj[result].GuildName, lpMsg->GuildName, 9); //MAX_GUILD_NAME define
		gObj[result].Guild = gGuildClass.SearchGuild(gObj[result].GuildName);
		gObj[result].GuildNumber = lpMsg->GuildNumber;
		gObj[result].GuildStatus = lpMsg->GuildStatus;

		DGGuildMemberInfoRequest(result);

	}


	gObj[result].Inventory = new CItem[INVENTORY_SIZE];
	gObj[result].Inventory1 = new CItem[INVENTORY_SIZE];
	gObj[result].InventoryMap1 = new BYTE[INVENTORY_SIZE];
	gObj[result].InventoryMap = new BYTE[INVENTORY_SIZE];


	for (int i = 0; i<INVENTORY_SIZE; i++)
	{
		gObj[result].Inventory[i].Clear();
		gObj[result].Inventory1[i].Clear();
	}

	memset(&gObj[result].InventoryMap[0], (BYTE)-1, INVENTORY_SIZE);
	memset(&gObj[result].InventoryMap1[0], (BYTE)-1, INVENTORY_SIZE);

#if (GAMESERVER_UPDATE >= 801)
	gObj[result].MuunInventory = new CItem[MUUN_INVENTORY_SIZE];
	gObj[result].MuunInventoryMap = new BYTE[MUUN_INVENTORY_SIZE];

	for (int i = 0; i<MUUN_INVENTORY_SIZE; i++)
	{
		gObj[result].MuunInventory[i].Clear();
	}

	memset(&gObj[result].MuunInventoryMap[0], (BYTE)-1, MUUN_INVENTORY_SIZE); //novo
#endif

	//char szTEMP[11] = {0};
	//wsprintf(szTEMP,"[Top1]<%s>",lpMsg->name);
	strcpy_s(gObj[result].Name, lpMsg->name);
	//wsprintf(gObj[result].Name,"<%s>",lpMsg->name);

	for (int n = 0; n < INVENTORY_SIZE; n++)
	{
		CItem item;

		gObj[result].Inventory[n].Clear();

		if (gItemManager.ConvertItemByte(&item, lpMsg->Inventory[n]) == 0)
		{
			continue;
		}

		gItemManager.InventoryAddItem(result, item, n);
	}

	for (int n = 0; n < MAX_EFFECT_LIST; n++)
	{
		CEffect effect;

		gObj[result].Effect[n].Clear();

		if (gEffectManager.ConvertEffectByte(&effect, lpMsg->Effect[n]) == 0)
		{
			continue;
		}

		gEffectManager.AddEffect(&gObj[result], 1, effect.m_index, effect.m_count, effect.m_value[0], effect.m_value[1], effect.m_value[2], effect.m_value[3]);
	}

	gObj[result].Inventory1 = gObj[result].Inventory;
	gObj[result].InventoryMap1 = gObj[result].InventoryMap;
	gObjectManager.CharacterMakePreviewCharSet(result);

	//gObj[result].AttackType = 0;
	//gObj[result].BotSkillAttack = 0;	

	//gObj[result].Attribute = 100;
	//gObj[result].TargetNumber = (WORD)-1;
	//gObj[result].ActionState.Emotion = 0;
	//gObj[result].ActionState.Attack = 0;
	//gObj[result].ActionState.EmotionCount = 0;
	//gObj[result].PathCount = 0;
	//gObj[result].BotPower = 0;
	//gObj[result].BotDefense = 0;
	//gObj[result].BotLife = 1;
	//gObj[result].BotMaxLife = 1;
	//
	//gObj[result].BotLvlUpDefense = 1;
	//gObj[result].BotLvlUpPower = 1;
	//gObj[result].BotLvlUpLife = 1;
	//gObj[result].BotLvlUpMana = 1;
	//gObj[result].BotLvlUpExp = 1;
	//gObj[result].BotLvlUpMaxLevel = 1;

	//gObj[result].MoveRange = 1;
	//gObj[result].BotFollowMe = 0;
	//gObj[result].NextExperience = gLevelExperience[gObj[result].Level];


	//GCSummonLifeSend(gObj[result].SummonIndex,(int)gObj[result].MaxLife,(int)gObj[result].Life);

	//GCActionSend(&gObj[result],ACTION_SALUTE1,result,result);

	//gObj[result].rDanhHieu = lpMsg->rDanhHieu;

	//this->Init(); //Set Lai Time

	//gObjViewportListProtocolCreate(&gObj[result]);

	//gObjectManager.CharacterUpdateMapEffect(&gObj[result]);

	gCustomRankUser.GCReqRankLevelUser(result, lpMsg->rDanhHieu);

	//LogAdd(LOG_RED,"[BotGetInfoSet] SSSSSSSSSSSS [%d](%s)",lpMsg->index,lpMsg->name);


}
void ObjBOTSTATUE::MakeBot()
{

	//if(this->Enabled == 1)
	{

		for (int botNum = 0; botNum<MAX_BOTSTATUE; botNum++)
		{
			if (this->bot[botNum].Enabled == 1)
			{

				int result = gObjAddSummon();



				if (result >= 0)
				{
					this->bot[botNum].index = result;
					gObjCharZeroSet(result);
					gObj[result].PosNum = (WORD)-1;
					gObj[result].X = this->bot[botNum].X;
					gObj[result].Y = this->bot[botNum].Y;
					gObj[result].OldX = this->bot[botNum].X;
					gObj[result].OldY = this->bot[botNum].Y;
					gObj[result].TX = this->bot[botNum].X;
					gObj[result].TY = this->bot[botNum].Y;
					gObj[result].MTX = this->bot[botNum].X;
					gObj[result].MTY = this->bot[botNum].Y;
					gObj[result].Dir = this->bot[botNum].Dir;
					gObj[result].Map = this->bot[botNum].Map;
					gObj[result].Live = 1;
					gObj[result].PathCount = 0;
					gObj[result].IsBot = 2;
					gObj[result].BotPower = 0;

					//gObjSetBots(result,2);

					GDBotInfoSend(result, this->bot[botNum].Rank, this->bot[botNum].Type); //Get DS

				}
			}
		}
	}
}

#endif
