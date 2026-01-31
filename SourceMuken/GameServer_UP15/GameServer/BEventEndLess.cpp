#include "stdafx.h"
#include "BEventEndLess.h"
#include "DSProtocol.h"
#include "EffectManager.h"
#include "Map.h"
#include "MemScript.h"
#include "Notice.h"
#include "Util.h"
#include "ItemOptionRate.h"
#include "ObjectManager.h"
#include "Guild.h"
#include "Move.h"
#include "Monster.h"
#include "ItemBagManager.h"
#include "Party.h"

CBEventEndLess gBEventEndLess;

CBEventEndLess::CBEventEndLess()
{
	this->mEventConfigNPC = new ENDLESS_NPC;
	this->mEventConfigMAP = new ENDLESS_MAP;
	this->mEventConfig = new ENDLESS_CONFIG;
	this->aIndexNPC = -1;
	this->CacheListDmgDefHP = -1;
}

CBEventEndLess::~CBEventEndLess()
{

}

void CBEventEndLess::LoadFileXML(char* FilePath)
{
	if (gObjIsConnected(this->aIndexNPC) == 1) //Neu Da Co NPC thi del
	{
		gObjDel(this->aIndexNPC);
	}
	this->CacheListDmgDefHP = -1;
	this->m_State = 0;
	this->m_RemainTime = 0;
	this->m_TargetTime = 0;
	this->DelayRaWave = 0;
	this->CacheWaveCount = 0;
	this->EventIsWave = 0;

	this->aIndexNPC = -1;
	this->Enable = 0;
	this->MaxEventDay = 0;
	this->TimeEventWait = 0;
	this->TimeEventMax = 0;
	this->mMonterCount = 0;
	this->mMonterRand = 0;
	this->mWaveNextBoss = 10;
	this->mBossCount = 0;
	this->mBossRand = 0;
	this->TotalPlayer = 0;

	this->mEventConfigNPC->Clear();
	this->mEventConfigMAP->Clear();
	this->mEventConfig->Clear();
	this->mMonterDB.clear();
	this->mBossDB.clear();
	this->mDameDefMobDB.clear();
	this->mRewardDB.clear();
	this->mCacheSpotMob.clear();
	this->ClearAllUser();

	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(FilePath);
	if (res.status != pugi::status_ok) {
		ErrorMessageBox("File %s load fail. Error: %s", FilePath, res.description());
		return;
	}
	//--
	pugi::xml_node oEndLessTowerEvent = file.child("EndLessTowerEvent");
	//--
	this->Enable = oEndLessTowerEvent.attribute("Enable").as_int();
	this->MaxEventDay = oEndLessTowerEvent.attribute("MaxEventDay").as_int();
	this->TimeEventWait = oEndLessTowerEvent.attribute("TimeEventWait").as_int();
	this->TimeEventMax = oEndLessTowerEvent.attribute("TimeEventMax").as_int();

	//= Mess Load
	pugi::xml_node Message = oEndLessTowerEvent.child("Message");
	for (pugi::xml_node msg = Message.child("Msg"); msg; msg = msg.next_sibling())
	{
		MESSAGE_INFO_ENDLESS info;

		info.Index = msg.attribute("Index").as_int();

		strcpy_s(info.Message, msg.attribute("Text").as_string());

		this->m_MessageInfoBP.insert(std::pair<int, MESSAGE_INFO_ENDLESS>(info.Index, info));
	}
	//= Config NPC
	pugi::xml_node EventConfigNPC = oEndLessTowerEvent.child("EventConfigNPC");
	this->mEventConfigNPC->NPCClass = EventConfigNPC.attribute("NPCClass").as_int();
	this->mEventConfigNPC->NPCMap = EventConfigNPC.attribute("NPCMap").as_int();
	this->mEventConfigNPC->NPCX = EventConfigNPC.attribute("NPCX").as_int();
	this->mEventConfigNPC->NPCY = EventConfigNPC.attribute("NPCY").as_int();
	this->mEventConfigNPC->NPCDir = EventConfigNPC.attribute("NPCDir").as_int();
	//= Config Map
	pugi::xml_node EventConfigMap = oEndLessTowerEvent.child("EventConfigMap");
	this->mEventConfigMAP->EventMap = EventConfigMap.attribute("EventMap").as_int();
	this->mEventConfigMAP->PosX = EventConfigMap.attribute("PosX").as_int();
	this->mEventConfigMAP->PosY = EventConfigMap.attribute("PosY").as_int();
	this->mEventConfigMAP->PosXX = EventConfigMap.attribute("PosXX").as_int();
	this->mEventConfigMAP->PosYY = EventConfigMap.attribute("PosYY").as_int();
	//= Config Event
	pugi::xml_node EventConfig = oEndLessTowerEvent.child("EventConfig");
	this->mEventConfig->EventItemID = EventConfig.attribute("EventItemID").as_int();
	this->mEventConfig->EventItemCount = EventConfig.attribute("EventItemCount").as_int();
	this->mEventConfig->SetPointUp = EventConfig.attribute("SetPointUp").as_int();
	this->mEventConfig->TypeBonusPoint = EventConfig.attribute("TypeBonusPoint").as_int();
	this->mEventConfig->PointBonus = EventConfig.attribute("PointBonus").as_int();
	//==Load DB Monter
	pugi::xml_node MonterDB = oEndLessTowerEvent.child("MonterDB");
	this->mMonterCount = MonterDB.attribute("Count").as_int();
	this->mMonterRand = MonterDB.attribute("Rand").as_int();
	this->mWaveNextBoss = MonterDB.attribute("WaveNextBoss").as_int(10);

	for (pugi::xml_node rMonterDB = MonterDB.child("Mob"); rMonterDB; rMonterDB = rMonterDB.next_sibling())
	{
		ENDLESS_MOBBOSSDB infoMobDB;
		infoMobDB.MonterID = rMonterDB.attribute("MonterID").as_int();
		this->mMonterDB.push_back(infoMobDB);
	}
	//==Load DB Boss
	pugi::xml_node BossDB = oEndLessTowerEvent.child("BossDB");
	this->mBossCount = BossDB.attribute("Count").as_int();
	this->mBossRand = BossDB.attribute("Rand").as_int();

	for (pugi::xml_node rBossDB = BossDB.child("Mob"); rBossDB; rBossDB = rBossDB.next_sibling())
	{
		ENDLESS_MOBBOSSDB infoBossDB;
		infoBossDB.MonterID = rBossDB.attribute("MonterID").as_int();
		this->mBossDB.push_back(infoBossDB);
	}
	//==Load DmgDef Mob
	pugi::xml_node DameDefMobDB = oEndLessTowerEvent.child("DameDefMobDB");

	for (pugi::xml_node rDameDefMobDB = DameDefMobDB.child("List"); rDameDefMobDB; rDameDefMobDB = rDameDefMobDB.next_sibling())
	{
		ENDLESS_DMGDEFDB infoDameDefMobDB;
		infoDameDefMobDB.WaveMin = rDameDefMobDB.attribute("WaveMin").as_int();
		infoDameDefMobDB.WaveMax = rDameDefMobDB.attribute("WaveMax").as_int();
		infoDameDefMobDB.DmgRate = rDameDefMobDB.attribute("DmgRate").as_int();
		infoDameDefMobDB.DefRate = rDameDefMobDB.attribute("DefRate").as_int();
		infoDameDefMobDB.HPRate = rDameDefMobDB.attribute("HPRate").as_int();
		this->mDameDefMobDB.push_back(infoDameDefMobDB);
	}
	//==Load RewardDB
	pugi::xml_node RewardDB = oEndLessTowerEvent.child("RewardDB");

	for (pugi::xml_node rRewardDB = RewardDB.child("List"); rRewardDB; rRewardDB = rRewardDB.next_sibling())
	{
		ENDLESS_REWARDDB infoRewardDB;
		infoRewardDB.CountWave = rRewardDB.attribute("CountWave").as_int();
		infoRewardDB.EventItemBag = rRewardDB.attribute("EventItemBag").as_int();
		infoRewardDB.WC = rRewardDB.attribute("WC").as_int();
		infoRewardDB.WP = rRewardDB.attribute("WP").as_int();
		infoRewardDB.GP = rRewardDB.attribute("GP").as_int();
		infoRewardDB.RU = rRewardDB.attribute("RU").as_int();

		this->mRewardDB.push_back(infoRewardDB);
	}
	this->aIndexNPC = gObjAddMonster(this->mEventConfigNPC->NPCMap);


	LogAdd(LOG_BLUE, "[EndLessEvent] Load OK Enable = %d", this->Enable);
}

char* CBEventEndLess::GetMessage(int index) // OK
{
	std::map<int, MESSAGE_INFO_ENDLESS>::iterator it = this->m_MessageInfoBP.find(index);

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



void CBEventEndLess::MainProc()
{
	if (!this->Enable) return;

	//this->CacheTimeEvent();
	//=== Tao NPC
	if (this->aIndexNPC != -1)
	{

		if (gObjIsConnected(this->aIndexNPC) == 0) //Chua Co NPC
		{
			if (!this->AddMob(this->aIndexNPC, this->mEventConfigNPC->NPCClass, this->mEventConfigNPC->NPCMap, this->mEventConfigNPC->NPCX, this->mEventConfigNPC->NPCY, this->mEventConfigNPC->NPCDir))
			{
				LogAdd(LOG_RED, "[EndLess] Ko tao duoc NPC");
			}
			//gObjDel(bIndex);
		}
	}
	if (this->m_State == 0) return;

	if ((GetTickCount() - this->m_TickCount) >= 1000)
	{
		this->m_TickCount = GetTickCount();

		this->m_RemainTime = (int)difftime(this->m_TargetTime, time(0));

		this->CheckUserIsEvent();

		if (this->DelayRaWave >= 1)
		{
			this->DelayRaWave--;
		}
		//== Trang Thai Cho Bat Dau Event
		if (((this->m_RemainTime % 10) == 0) && this->m_State == 1)
		{
			this->NoticeSendToAll(0, this->GetMessage(2), (this->m_RemainTime));//
		}


		//LogAdd(LOG_RED, "EndLess State %d Time %d Wave %d User %d", this->m_State, this->m_RemainTime, this->CacheWaveCount, this->TotalPlayer);


		//=== Ko Con Ai
		if (this->TotalPlayer == 0)
		{

			if (this->mCacheSpotMob.size() > 0)
			{
				//==Clear Monter
				for (std::vector<ENDLESS_MOBBOSSDB>::iterator it = this->mCacheSpotMob.begin(); it != this->mCacheSpotMob.end(); it++)
				{
					//if (OBJECT_RANGE(it->MonterID) != 0)
					{
						gObjDel(it->MonterID);
					}
				}
				this->mCacheSpotMob.clear();
			}


			this->ClearAllUser();
			this->CountMonterWaveIs = 0;
			this->CacheListDmgDefHP = -1;
			this->TotalPlayer = 0;
			this->m_State = 0;
			this->m_RemainTime = 0;
			this->m_TargetTime = 0;
			this->DelayRaWave = 0;
			this->CacheWaveCount = 0;
			this->EventIsWave = 0;

			//LogAdd(LOG_RED, "EndLess No User Clear()");
		}

		//== Sap Ket Thuc Event
		if ((int)this->m_RemainTime > 0 && (int)this->m_RemainTime <= (3 * 60) && this->m_State == 2)
		{
			if ((this->AlarmMinSave = (((this->m_RemainTime % 60) == 0) ? ((this->m_RemainTime / 60) - 1) : (this->m_RemainTime / 60))) != this->AlarmMinLeft)
			{
				this->AlarmMinLeft = this->AlarmMinSave;

				this->NoticeSendToAll(0, this->GetMessage(6), (this->AlarmMinLeft + 1));//
			}
		}

		switch (this->m_State)
		{
		case 1:
		{
			if ((int)this->m_RemainTime <= 0)
			{
				//== Neu dang la trang thai cho
				//== Set Time Event
				this->m_RemainTime = this->TimeEventMax * 60;
				this->m_TargetTime = (int)(time(0) + this->m_RemainTime);
				this->m_State = 2;
				this->SetMonterWave();
				this->NoticeSendToAll(0, this->GetMessage(8), this->TimeEventMax);//tb ket thuc

			}

		}
		break;

		case 2:
		{
			this->SendInfoEvent();
			if ((int)this->m_RemainTime <= 0)
			{
				//== ket Thuc Event	
				this->NoticeSendToAll(0, this->GetMessage(4), this->CacheWaveCount);//tb ket thuc
				this->NoticeSendToAll(0, this->GetMessage(5));//tb ket thuc
				this->m_RemainTime = 1 * 60; //1 phut trao thuong
				this->m_TargetTime = (int)(time(0) + this->m_RemainTime);
				this->m_State = 3;
				this->CountMonterWaveIs = 0;

				this->TraoThuongEvent();
			}

			if (this->CountMonterWaveIs <= 0 && this->DelayRaWave == 0)
			{
				//==Next Wave
				this->SetMonterWave();
			}
		}
		break;
		case 3:
		{
			if (this->mCacheSpotMob.size() != NULL)
			{
				//==Clear Monter
				for (std::vector<ENDLESS_MOBBOSSDB>::iterator it = this->mCacheSpotMob.begin(); it != this->mCacheSpotMob.end(); it++)
				{
					//if (OBJECT_RANGE(it->MonterID) != 0)
					{
						gObjDel(it->MonterID);
					}

				}
				this->mCacheSpotMob.clear();
			}

			if ((int)this->m_RemainTime <= 0)
			{

				this->ClearAllUser();
				this->CountMonterWaveIs = 0;
				this->CacheListDmgDefHP = -1;
				this->TotalPlayer = 0;
				this->m_State = 0;
				this->m_RemainTime = 0;
				this->m_TargetTime = 0;
				this->DelayRaWave = 0;
				this->CacheWaveCount = 0;
				this->EventIsWave = 0;
			}
		}
		break;
		}
		//LogAdd(LOG_RED, "EndLess State %d RmT %d", this->m_State, (int)this->m_RemainTime);
	}

}
ENDLESS_REWARDDB* CBEventEndLess::GetReWardWave()
{
	int GetL = 0;
	for (std::vector<ENDLESS_REWARDDB>::iterator it = this->mRewardDB.begin(); it != this->mRewardDB.end(); it++)
	{
		if (this->CacheWaveCount >= it->CountWave)
		{
			GetL++;
		}
	}
	return &this->mRewardDB[GetL];
}

void CBEventEndLess::TraoThuongEvent()
{
	for (int n = 0; n < MAX_ENDLESS_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) != 0)
		{

			this->CacheUserState(this->User[n].Index, 0); //Khoi Phuc Do
			//=== Trao Thuong
			LPOBJ lpObj = &gObj[this->User[n].Index];
			ENDLESS_REWARDDB* RewardB = this->GetReWardWave();

			if (RewardB->WC > 0 || RewardB->WP > 0 || RewardB->GP > 0)
			{
				//GDSetCoinSend(lpObj->Index, RewardB->WC, RewardB->WP, RewardB->GP, RewardB->RU, "EndLessReCoin");
				GDSetCoinSend(lpObj->Index, RewardB->WC, RewardB->WP, RewardB->GP, "EndLessReCoin");
			}
			if (RewardB->EventItemBag != -1)
			{
				gItemBagManager.DropItemByIndexItemBag(RewardB->EventItemBag, lpObj); //Gui Item cho NV
			}
			//LogAdd(LOG_RED, "[EndLess]Trao Thuong Count %d Bag %d", this->CacheWaveCount, RewardB->EventItemBag);

		}
	}


}
bool CBEventEndLess::UserDieProc(LPOBJ lpObj, LPOBJ lpTarget) // OK
{
	if (this->Enable == 0)
	{
		return 0;
	}

	if (this->m_State == 0 || lpObj->Map != this->mEventConfigMAP->EventMap)
	{
		return 0;
	}

	ENDLESS_USER* lpUserA = this->GetUser(lpObj->Index);

	if (lpUserA == 0)
	{
		return 0;
	}
	if (this->TotalPlayer <= 1)
	{
		//LogAdd(LOG_RED, "UserDieProc 1");
		this->m_RemainTime = 5;
		this->m_TargetTime = (int)(time(0) + this->m_RemainTime);
	}

	//=== Set Tang Hinh Nhan Vat Vua Chet
	lpUserA->Available = 0;
	lpUserA->DieTime = GetTickCount() + 5000;
	LogAdd(LOG_RED, "UserDieProc [%s] %d", lpObj->Name, lpUserA->Available);
	return 1;

}
bool CBEventEndLess::MonsterKill(int aIndexMonster, int aIndexUser)
{
	bool Result = false;

	if (!this->Enable)
	{
		return Result;
	}

	LPOBJ lpUser = &gObj[aIndexUser];
	LPOBJ lpMonster = &gObj[aIndexMonster];

	for (std::vector<ENDLESS_MOBBOSSDB>::iterator it = this->mCacheSpotMob.begin(); it != this->mCacheSpotMob.end(); it++)
	{
		if (it->MonterID == aIndexMonster)
		{
			if (this->CountMonterWaveIs == 1)
			{
				XULY_CGPACKET pMsg;
				pMsg.header.set(0xD3, 0x30, sizeof(pMsg));
				pMsg.ThaoTac = 2; //1 Open Window , 2 Show Img Clean Wave
				this->DataSendToAll((BYTE*)& pMsg, pMsg.header.size);

				this->DelayRaWave = 5;
				this->NoticeSendToAll(0, this->GetMessage(10), this->CacheWaveCount);//tb ra Wave
			}
			this->CountMonterWaveIs--;
			gObjDel(aIndexMonster);

			//LogAdd(LOG_RED, "EndLess %d Monter", this->CountMonterWaveIs);

		}
	}
	return Result;
}
void CBEventEndLess::CleanEffectUserDie()
{
	for (int n = 0; n < MAX_ENDLESS_USER; n++)
	{
		LPOBJ lpObj = &gObj[this->User[n].Index];

		if (this->User[n].Available == 0)
		{
			gEffectManager.ClearAllEffect(lpObj);
			gObjViewportListProtocolCreate(lpObj);
			this->User[n].Available = 1;
		}
	}
}
void CBEventEndLess::GetWaveDmgDefHP()
{
	int GetDmg = 0;
	for (std::vector<ENDLESS_DMGDEFDB>::iterator it = this->mDameDefMobDB.begin(); it != this->mDameDefMobDB.end(); it++)
	{
		if ((this->CacheWaveCount + 1) >= it->WaveMin && (this->CacheWaveCount + 1) <= it->WaveMax)
		{
			GetDmg++;
		}
	}
	this->CacheListDmgDefHP = GetDmg;
}

void CBEventEndLess::SetMobDmgDefHp(int aIndex)
{
	if (this->CacheListDmgDefHP == -1)
	{
		return;
	}
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return;
	}
	int n = this->CacheListDmgDefHP;
	LPOBJ lpObj = &gObj[aIndex];
	if (this->mDameDefMobDB[n].HPRate > 0)
	{
		lpObj->Life = (float)((__int64)lpObj->Life + ((lpObj->Life * this->mDameDefMobDB[n].HPRate) / 100));

		lpObj->MaxLife = (float)((__int64)lpObj->MaxLife + ((lpObj->MaxLife * this->mDameDefMobDB[n].HPRate) / 100));

		lpObj->ScriptMaxLife = (float)((__int64)lpObj->ScriptMaxLife + ((lpObj->ScriptMaxLife * this->mDameDefMobDB[n].HPRate) / 100));

	}
	if (this->mDameDefMobDB[n].DmgRate > 0)
	{

		lpObj->PhysiDamageMin = ((__int64)lpObj->PhysiDamageMin + ((lpObj->PhysiDamageMin * this->mDameDefMobDB[n].DmgRate) / 100));

		lpObj->PhysiDamageMax = ((__int64)lpObj->PhysiDamageMax + ((lpObj->PhysiDamageMax * this->mDameDefMobDB[n].DmgRate) / 100));

		lpObj->AttackSuccessRate = ((__int64)lpObj->AttackSuccessRate + ((lpObj->AttackSuccessRate * this->mDameDefMobDB[n].DmgRate) / 100));
	}
	if (this->mDameDefMobDB[n].DefRate > 0)
	{
		lpObj->Defense = ((__int64)lpObj->Defense + ((lpObj->Defense * this->mDameDefMobDB[n].DefRate) / 100));

		lpObj->DefenseSuccessRate = ((__int64)lpObj->DefenseSuccessRate + ((lpObj->DefenseSuccessRate * this->mDameDefMobDB[n].DefRate) / 100));
	}

}

bool CBEventEndLess::AddMob(int aIndex, int Class, int Map, int PosX, int PosY, int Dir)
{

	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}

	LPOBJ lpMonster = &gObj[aIndex];

	int px = PosX;
	int py = PosY;

	lpMonster->PosNum = -1;
	lpMonster->X = px;
	lpMonster->Y = py;
	lpMonster->TX = px;
	lpMonster->TY = py;
	lpMonster->OldX = px;
	lpMonster->OldY = py;
	lpMonster->StartX = px;
	lpMonster->StartY = py;
	lpMonster->MaxRegenTime = 0;
	lpMonster->RegenTime = GetTickCount();
	lpMonster->ActionState.Emotion = 1;
	lpMonster->ActionState.EmotionCount = 15;
	lpMonster->Dir = (Dir == 99) ? rand() % 8 : Dir;
	lpMonster->Map = Map;
	if (Dir == 99)
	{
		lpMonster->MonsterDeleteTime = GetTickCount() + (this->m_RemainTime * 1000);
	}
	if (gObjSetMonster(aIndex, Class) == 0)
	{
		gObjDel(aIndex);
		return 0;
	}
	return 1;
}
void CBEventEndLess::SetMonterWave()
{
	if (this->m_State != 2)
	{
		return;
	}
	this->mCacheSpotMob.clear();
	this->CleanEffectUserDie(); //Xoa Tang Hinh NV Da Chet
	this->GetWaveDmgDefHP();
	if ((this->CacheWaveCount % this->mWaveNextBoss) == 0 && this->CacheWaveCount > 0)
	{
		this->NoticeSendToAll(0, this->GetMessage(3));//Boss sap xuat hien

		int GetList = (GetLargeRand() % this->mBossDB.size());
		//==10 Wave Ra Boss
		int BossIDClass = this->mBossDB[GetList].MonterID;
		for (int n = 0; n < this->mBossCount; n++)
		{
			if (this->mBossRand == 1)
			{
				BossIDClass = this->mBossDB[(GetLargeRand() % this->mBossDB.size())].MonterID;
			}

			int index = gObjAddMonster(this->mEventConfigMAP->EventMap);

			if (OBJECT_RANGE(index) == 0)
			{
				continue;
			}

			int px = 0;
			int py = 0;

			if (this->GetPosRandom(&px, &py) == 0)
			{
				continue;
			}

			if (!this->AddMob(index, BossIDClass, this->mEventConfigMAP->EventMap, px, py))
			{
				continue;
			}
			this->SetMobDmgDefHp(index);//Tang Mau Dmg Def
			this->CountMonterWaveIs++;

			ENDLESS_MOBBOSSDB infoMobBoss;
			infoMobBoss.MonterID = index;
			this->mCacheSpotMob.push_back(infoMobBoss);
			//LogAdd(LOG_RED, "Endless Boss %d", this->CountMonterWaveIs);
		}
	}
	else
	{
		//Ra Quai BT
		int GetList = (GetLargeRand() % this->mMonterDB.size());
		//==10 Wave Ra Boss
		int MobIDClass = this->mMonterDB[GetList].MonterID;
		for (int n = 0; n < this->mMonterCount; n++)
		{
			if (this->mMonterRand == 1)
			{
				MobIDClass = this->mMonterDB[(GetLargeRand() % this->mMonterDB.size())].MonterID;
			}

			int index = gObjAddMonster(this->mEventConfigMAP->EventMap);

			if (OBJECT_RANGE(index) == 0)
			{
				continue;
			}

			LPOBJ lpMonster = &gObj[index];

			int px = 0;
			int py = 0;

			if (this->GetPosRandom(&px, &py) == 0)
			{
				continue;
			}
			if (!this->AddMob(index, MobIDClass, this->mEventConfigMAP->EventMap, px, py))
			{
				continue;
			}
			this->SetMobDmgDefHp(index);//Tang Mau Dmg Def

			this->CountMonterWaveIs++;
			ENDLESS_MOBBOSSDB infoMobMonter;
			infoMobMonter.MonterID = index;
			this->mCacheSpotMob.push_back(infoMobMonter);
			//LogAdd(LOG_RED, "Endless AddMonter %d", this->CountMonterWaveIs);
		}
	}


	this->CacheWaveCount++;
	this->NoticeSendToAll(0, this->GetMessage(9), this->CacheWaveCount);//tb ra Wave
}
void CBEventEndLess::NoticeSendToAll(int type, char* message, ...) // OK
{
	char buff[256];

	va_list arg;
	va_start(arg, message);
	vsprintf_s(buff, message, arg);
	va_end(arg);

	for (int n = 0; n < MAX_ENDLESS_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) != 0)
		{
			gNotice.GCNoticeSend(this->User[n].Index, type, 0, 0, 0, 0, 0, buff);
		}
	}
}

bool CBEventEndLess::CheckReqItems(LPOBJ lpObj)
{
	lpObj->ChaosLock = 1;

	int count = gItemManager.GetInventoryItemCount(lpObj, this->mEventConfig->EventItemID, 0);
	int DiemNgoc = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int level = 0; level < 16; level++)
		{
			DiemNgoc = gItemManager.GetInventoryItemCount(lpObj, GET_ITEM(14, i), level);
			gItemManager.DeleteInventoryItemCount(lpObj, GET_ITEM(14, i), level, DiemNgoc);
		}

	}
	if (count < this->mEventConfig->EventItemCount)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(1), this->mEventConfig->EventItemCount, gItemManager.GetItemName(this->mEventConfig->EventItemID));
		return false;
	}

	gItemManager.DeleteInventoryItemCount(lpObj, this->mEventConfig->EventItemID, 0, this->mEventConfig->EventItemCount);

	lpObj->ChaosLock = 0;
	return true;
}

bool CBEventEndLess::Dialog(LPOBJ lpObj, LPOBJ lpNpc)
{
	if (!this->Enable) return false;

	if (lpNpc->Class == this->mEventConfigNPC->NPCClass &&
		lpNpc->Map == this->mEventConfigNPC->NPCMap &&
		lpNpc->X == this->mEventConfigNPC->NPCX &&
		lpNpc->Y == this->mEventConfigNPC->NPCY)
	{
		XULY_CGPACKET pMsg;
		pMsg.header.set(0xD3, 0x30, sizeof(pMsg));
		pMsg.ThaoTac = 1; //1 Open Window , 2 Show Img Clean Wave
		DataSend(lpObj->Index, (BYTE*)& pMsg, pMsg.header.size);

	}

	return false;
}
//== Tham Gia Event
void CBEventEndLess::CGOpenWindowNPC(XULY_CGPACKET * aRecv, int aIndex)
{
	//LogAdd(LOG_RED, "DEBUG CGOpenWindowNPC");
	if (!this->Enable)
	{
		return;
	}
	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (this->m_State != 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(0));
		return;
	}
	//=== Send Client Open Windows

	if (!this->CheckEnterEnabled(lpObj))
	{
		return;
	}

	if (OBJECT_RANGE(lpObj->PartyNumber) != 0)
	{
		PARTY_INFO* lpParty = &gParty.m_PartyInfo[lpObj->PartyNumber];
		for (int n = 0; n < MAX_PARTY_USER; n++)
		{
			if (OBJECT_RANGE(lpParty->Index[n]) != 0 && lpObj->Index != lpParty->Index[n])
			{
				if (lpObj->Map == gObj[lpParty->Index[n]].Map && gObjCalcDistance(lpObj, &gObj[lpParty->Index[n]]) < MAX_PARTY_DISTANCE)
				{
					if (!this->CheckEnterEnabled(&gObj[lpParty->Index[n]])) //Check may thang trong nhom vao Event
					{
						continue;
					}
					this->AddUser(lpParty->Index[n]);
				}
			}
		}
	}
	//==Set user vao Event
	this->AddUser(lpObj->Index);
#if ThanhTuu
	gAchievements.ThamGiaVT(lpObj->Index);
#endif
	this->EventIsWave = 1;
	//== Set Time Cho
	this->m_RemainTime = this->TimeEventWait * 60;
	this->m_TargetTime = (int)(time(0) + this->m_RemainTime);
	this->m_State = 1;

	return;
}
bool CBEventEndLess::CheckEnterEnabled(LPOBJ lpObj)
{
	if (lpObj->mLuotDiEndLess >= this->MaxEventDay)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(0));
		return 0;
	}
	if (lpObj->Guild != 0 && lpObj->Guild->WarState == 1)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(7));
		return 0;
	}

	if (OBJECT_RANGE(lpObj->DuelUser) != 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(7));
		return 0;
	}

	if (lpObj->PShopOpen != 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(7));
		return 0;
	}

	if (this->TotalPlayer >= MAX_ENDLESS_USER)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(0));
		return 0;
	}

	if (this->CheckReqItems(lpObj) == 0)
	{
		return 0;
	}


	return 1;
}
bool CBEventEndLess::GetPosRandom(int* x, int* y)
{
	int px, py;

	for (int n = 0; n < 50; n++)
	{
		if ((this->mEventConfigMAP->PosXX - this->mEventConfigMAP->PosX) > 0)
		{
			px = this->mEventConfigMAP->PosX + (GetLargeRand() % (this->mEventConfigMAP->PosXX - this->mEventConfigMAP->PosX));
		}
		else
		{
			px = this->mEventConfigMAP->PosX;
		}

		if ((this->mEventConfigMAP->PosYY - this->mEventConfigMAP->PosY) > 0)
		{
			py = this->mEventConfigMAP->PosY + (GetLargeRand() % (this->mEventConfigMAP->PosYY - this->mEventConfigMAP->PosY));
		}
		else
		{
			py = this->mEventConfigMAP->PosY;
		}

		if (gMap[this->mEventConfigMAP->EventMap].CheckAttr(px, py, 4) == 0 && gMap[this->mEventConfigMAP->EventMap].CheckAttr(px, py, 8) == 0)
		{
			(*x) = px;
			(*y) = py;
			return 1;
		}
	}
	return 0;
}

bool CBEventEndLess::KhoiPhucDataChar(int aIndex) // OK
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->CB_Status != 1)
	{
		return 0;
	}
	//===Phuc Hoi Point
	lpObj->LevelUpPoint = lpObj->CB_Point;
	lpObj->Level = lpObj->CB_Level;
	lpObj->Strength = lpObj->CB_Str;
	lpObj->Dexterity = lpObj->CB_Agi;
	lpObj->Vitality = lpObj->CB_Vit;
	lpObj->Energy = lpObj->CB_Ene;
	lpObj->Leadership = lpObj->CB_Cmd;


	//	for (int n = 0; n < INVENTORY_SIZE; n++)
	//	{
	//		lpObj->Inventory2[n].Clear();
	//	}
	//
	//#if(GAMESERVER_UPDATE>=802)
	//
	//	for (int n = 0; n < EVENT_INVENTORY_SIZE; n++)
	//	{
	//		lpObj->EventInventory2[n].Clear();
	//	}
	//
	//#endif
	//
	//	gObjSetInventory1Pointer(lpObj);
	//	//gObjSetEquipInventory1Pointer(lpObj);
	//
	//	gObjSetEventInventory1Pointer(lpObj);
	//
	//	//lpObj->Transaction = 3;

	lpObj->CB_Status = 0; //Set Trang Thai Event

	return 1;
}
bool CBEventEndLess::BackUpDataChar(int aIndex) // OK
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}


	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->CB_Status == 1)
	{
		return 0;
	}

	//===Backup
	lpObj->CB_Level = lpObj->Level;
	lpObj->CB_Point = lpObj->LevelUpPoint;
	lpObj->CB_Str = lpObj->Strength;
	lpObj->CB_Agi = lpObj->Dexterity;
	lpObj->CB_Vit = lpObj->Vitality;
	lpObj->CB_Ene = lpObj->Energy;
	lpObj->CB_Cmd = lpObj->Leadership;


	//	for (int n = 0; n < INVENTORY_SIZE; n++)
	//	{
	//		lpObj->Inventory2[n] = lpObj->Inventory1[n];
	//	}
	//
	//#if(GAMESERVER_UPDATE>=802)
	//
	//	for (int n = 0; n < EVENT_INVENTORY_SIZE; n++)
	//	{
	//		lpObj->EventInventory2[n] = lpObj->EventInventory1[n];
	//	}
	//
	//#endif
	//
	//	memcpy(lpObj->InventoryMap2, lpObj->InventoryMap1, INVENTORY_SIZE);
	//
	//#if(GAMESERVER_UPDATE>=802)
	//
	//	memcpy(lpObj->EventInventoryMap2, lpObj->EventInventoryMap1, EVENT_INVENTORY_SIZE);
	//
	//#endif
	//
	//	gObjSetInventory2Pointer(lpObj);
	//	//gObjSetEquipInventory2Pointer(lpObj);
	//
	//	//lpObj->Transaction = 1;

	lpObj->CB_Status = 1; //Set Trang Thai Event

	return 1;
}
void CBEventEndLess::CacheUserState(int aIndex, int TypeState)
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return;
	}
	LPOBJ lpObj = &gObj[aIndex];
	//=== Set State
	if (TypeState == 1)
	{
		gEffectManager.ClearAllEffect(lpObj);
		int x, y;
		if (this->GetPosRandom(&x, &y) == 0)
		{
			this->DelUser(aIndex);
			return;
		}

		//== Tele vao Event
		gObjTeleport(aIndex, this->mEventConfigMAP->EventMap, x, y);
		//===Backup Lai Du Lieu
		this->BackUpDataChar(aIndex);
		//
		//
		////= == Xoa Thung Do Ca Nhan
		//int MaxValue = gItemManager.GetInventoryMaxValue(lpObj);
		//
		//for (int i = INVENTORY_WEAR_SIZE; i < MaxValue; i++)
		//{
		//	gItemManager.InventoryDelItem(lpObj->Index, i);
		//	gItemManager.GCItemDeleteSend(lpObj->Index, i, 1);
		//}

		//===Set POint Event
		int PointBonusXX = 0;
		if (this->mEventConfig->TypeBonusPoint)
		{
			switch (this->mEventConfig->TypeBonusPoint)
			{
			case 1:
			{
				PointBonusXX = (this->mEventConfig->PointBonus * lpObj->Reset);
			}
			break;
			case 2:
			{
				//== Lay Quest tuy SV
			}
			break;
			default:
				break;
			}
		}
		lpObj->LevelUpPoint = this->mEventConfig->SetPointUp + PointBonusXX;
		lpObj->Strength = 100;
		lpObj->Dexterity = 100;
		lpObj->Vitality = 100;
		lpObj->Energy = 100;
		lpObj->Leadership = 100;

		gItemManager.GCItemListSend(lpObj->Index);
		GCMoneySend(lpObj->Index, lpObj->Money);
		gObjectManager.CharacterMakePreviewCharSet(lpObj->Index);
		gItemManager.GCItemEquipmentSend(lpObj->Index);
		//===Info Char Point
		gObjectManager.CharacterCalcAttribute(lpObj->Index);
		GCNewCharacterInfoSend(lpObj);

	}
	//Clear
	else
	{
		if (!lpObj->CB_Status) return;
		//===Khoi Phuc Lai Item
		this->KhoiPhucDataChar(lpObj->Index);
		//===Xoa Effect
		gEffectManager.ClearAllEffect(lpObj); //Xoa Effect Sinh Ton
		//===Info Item Send
		gItemManager.GCItemListSend(lpObj->Index);
		GCMoneySend(lpObj->Index, lpObj->Money);
		gObjectManager.CharacterMakePreviewCharSet(lpObj->Index);
		gItemManager.GCItemEquipmentSend(lpObj->Index);
		//===Info Char Point Send
		gObjectManager.CharacterCalcAttribute(lpObj->Index);
#if ThanhTuu		
		gAchievements.WinVT(lpObj->Index);
#endif
		GCNewCharacterInfoSend(lpObj);
	}

}
bool CBEventEndLess::AddUser(int aIndex) // OK
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}

	if (this->GetUser(aIndex) != 0)
	{
		return 0;
	}

	for (int n = 0; n < MAX_ENDLESS_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) != 0)
		{
			continue;
		}
		gObj[aIndex].mLuotDiEndLess++;

		GDCharacterInfoSaveSend(aIndex);
		//=== Move vao Event
		this->CacheUserState(aIndex, 1);

		this->User[n].Index = aIndex;
		this->User[n].Available = 1; //== Neu Die thi set = 0 Effect tang hinh
		this->TotalPlayer++;

		//LogAdd(LOG_RED, "Endless AddUser %d", aIndex);
		return 1;
	}
	return 0;
}
bool CBEventEndLess::DelUser(int aIndex) // OK
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}

	ENDLESS_USER* lpUser = this->GetUser(aIndex);

	if (lpUser == 0)
	{
		return 0;
	}

	lpUser->Clear();
	if (this->TotalPlayer > 0)
	{
		this->TotalPlayer--;
	}
	//=== Move vao Event
	this->CacheUserState(aIndex, 0); //Khoi Phuc Do
	gObjMoveGate(aIndex, 17); //move ve lorencia
	GDCharacterInfoSaveSend(aIndex);
	return 1;
}
bool CBEventEndLess::CheckUserInEvent(int aIndex) // OK
{

	return ((this->GetUser(aIndex) == 0) ? 0 : 1);
}
ENDLESS_USER * CBEventEndLess::GetUser(int aIndex) // OK
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}

	for (int n = 0; n < MAX_ENDLESS_USER; n++)
	{
		if (this->User[n].Index == aIndex)
		{
			return &this->User[n];
		}
	}
	return 0;
}
void CBEventEndLess::ClearAllUser() // OK
{
	for (int n = 0; n < MAX_ENDLESS_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) == 1)
		{
			if (gObjIsConnectedGP(this->User[n].Index) == 1)
			{
				//=== Move vao Event
				this->CacheUserState(this->User[n].Index, 0); //Khoi Phuc Do
				gObjMoveGate(this->User[n].Index, 17); //move ve lorencia
				GDCharacterInfoSaveSend(this->User[n].Index);
			}

		}

		this->User[n].Clear();

	}
	this->TotalPlayer = 0;
	this->EventIsWave = 0;


}
void CBEventEndLess::CheckUserIsEvent() // OK
{

	int CountUserDie = 0;

	for (int n = 0; n < MAX_ENDLESS_USER; n++)
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

		if (gObj[this->User[n].Index].Map != this->mEventConfigMAP->EventMap)
		{
			this->DelUser(this->User[n].Index);
			continue;
		}
		if (this->User[n].Available == 0 && this->m_State == 2)
		{
			CountUserDie++;
			if (gObj[this->User[n].Index].State == OBJECT_DELCMD || gObj[this->User[n].Index].DieRegen != 0)
			{
				continue;
			}

			if (gObj[this->User[n].Index].RegenOk > 0)
			{
				continue;
			}

			if (gObj[this->User[n].Index].Teleport != 0)
			{
				continue;
			}

			//this->User[n].Available = 2;
			if (gEffectManager.CheckEffect(&gObj[this->User[n].Index], EFFECT_INVISIBILITY) == 0)
			{
				//=== Set Tang Hinh Nhan Vat Vua Chet
				gEffectManager.AddEffect(&gObj[this->User[n].Index], 0, EFFECT_INVISIBILITY, 0, 0, 0, 0, 0);
				gEffectManager.AddEffect(&gObj[this->User[n].Index], 0, EFFECT_STERN, this->m_RemainTime * 60, 0, 0, 0, 0); //Dong Bang
				gEffectManager.AddEffect(&gObj[this->User[n].Index], 0, 153, this->m_RemainTime * 60, 10000, 0, 0, 0);
				gObjViewportListProtocolDestroy(&gObj[this->User[n].Index]);
				LogAdd(LOG_RED, "[EndLess] Set Effect User %s", gObj[this->User[n].Index].Name);
			}

		}
	}
	if (CountUserDie >= this->TotalPlayer && this->m_RemainTime > 5)
	{
		this->m_RemainTime = 5;
		this->m_TargetTime = (int)(time(0) + this->m_RemainTime);
	}

}
void CBEventEndLess::DataSendToAll(BYTE * lpMsg, int size) // OK
{
	for (int n = 0; n < MAX_ENDLESS_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) != 0)
		{
			DataSend(this->User[n].Index, lpMsg, size);
		}
	}
}
void CBEventEndLess::SendInfoEvent()
{
	//===========Send Info
	ENDLESSEVENT_INFO pMsg;
	pMsg.header.set(0xD3, 0x31, sizeof(pMsg));
	pMsg.Wave = (WORD)this->CacheWaveCount;
	pMsg.State = (BYTE)this->m_State;
	pMsg.Time = (DWORD)this->m_RemainTime;//Time
	pMsg.LiveMob = (WORD)this->CountMonterWaveIs;//So luong quai vat con lai
	this->DataSendToAll((BYTE*)& pMsg, pMsg.header.size);
	//==========		
}

void CBEventEndLess::CapNhatLuotDi(LPOBJ lpObj)
{
	if (gObjIsConnectedGP(lpObj->Index) == 0)
	{
		return;
	}

	lpObj->mLuotDiEndLess = 0;
	this->SendInfoEvent();
}
