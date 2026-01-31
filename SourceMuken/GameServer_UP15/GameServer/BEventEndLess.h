#pragma once
#include "DefaultClassInfo.h"
#include "User.h"
#include "Protocol.h"
#include "SkillManager.h"

#define MAX_ENDLESS_USER  5

struct MESSAGE_INFO_ENDLESS
{
	int Index;
	char Message[256];
};

struct ENDLESS_NPC
{
	int NPCClass;
	int NPCMap;
	int NPCX;
	int NPCY;
	int NPCDir;
	void Clear()
	{
		NPCClass = -1;
		NPCMap = 0;
		NPCX = 0;
		NPCY = 0;
		NPCDir = 0;
	}
};

struct ENDLESS_MAP
{
	int EventMap;
	int PosX;
	int PosY;
	int PosXX;
	int PosYY;
	void Clear()
	{
		EventMap = -1;
		PosX = 0;
		PosY = 0;
		PosXX = 0;
		PosYY = 0;
	}
};
struct ENDLESS_CONFIG
{
	int EventItemID;
	int EventItemCount;
	int SetPointUp;
	int TypeBonusPoint;
	int PointBonus;
	void Clear()
	{
		EventItemID = -1;
		EventItemCount = 0;
		SetPointUp = 0;
		TypeBonusPoint = 0;
		PointBonus = 0;
	}
};

struct ENDLESS_MOBBOSSDB
{
	int MonterID;
};

struct ENDLESS_DMGDEFDB
{
	int WaveMin;
	int WaveMax;
	int DmgRate;
	int DefRate;
	int HPRate;
};
struct ENDLESS_REWARDDB
{
	int CountWave;
	int EventItemBag;
	int WC;
	int WP;
	int GP;
	int RU;
};
struct ENDLESS_USER
{
	void Clear() // OK
	{
		this->Index = -1;
		this->Available = false;
		this->DieTime = 0;
	}
	DWORD DieTime;
	int Index;
	bool Available;

};
#pragma pack(push, 1)
struct ENDLESSEVENT_INFO
{
	PSBMSG_HEAD	 header;
	WORD		Wave;
	WORD		LiveMob;
	DWORD		Time;
	BYTE		State;
};
#pragma pack(pop)

class CBEventEndLess
{
public:
	CBEventEndLess();
	virtual ~CBEventEndLess();
	void LoadFileXML(char* FilePath);

	int Enable;
	int aIndexNPC;
	int MaxEventDay;
	int SoLanDaDiEvent;
	int TimeEventWait;
	int TimeEventMax;
	int DelayRaWave;

	ENDLESS_NPC* mEventConfigNPC;
	ENDLESS_MAP* mEventConfigMAP;
	ENDLESS_CONFIG* mEventConfig;

	int mMonterCount;
	int mMonterRand;
	int mWaveNextBoss;
	std::vector<ENDLESS_MOBBOSSDB> mMonterDB;


	int mBossCount;
	int mBossRand;
	std::vector<ENDLESS_MOBBOSSDB> mBossDB;

	std::vector<ENDLESS_MOBBOSSDB> mCacheSpotMob;

	std::vector<ENDLESS_DMGDEFDB> mDameDefMobDB;
	std::vector<ENDLESS_REWARDDB> mRewardDB;


	void MainProc();

	bool AddUser(int aIndex);
	bool DelUser(int aIndex);
	ENDLESS_USER User[MAX_ENDLESS_USER];
	ENDLESS_USER* GetUser(int aIndex);
	ENDLESS_REWARDDB* GetReWardWave();
	int TotalPlayer;
	void ClearAllUser();
	void CheckUserIsEvent();



	DWORD m_RemainTime;
	DWORD m_TargetTime;
	DWORD m_TickCount;
	int AlarmMinSave;
	int AlarmMinLeft;

	void NoticeSendToAll(int type, char* message, ...);
	bool CheckEnterEnabled(LPOBJ lpObj);
	bool CheckReqItems(LPOBJ lpObj);
	void CGOpenWindowNPC(XULY_CGPACKET* aRecv, int aIndex);
	void CacheUserState(int aIndex, int TypeState = 1);
	bool GetPosRandom(int* x, int* y);
	void SetMonterWave();
	int CountMonterWaveIs;
	bool MonsterKill(int aIndexMonster, int aIndexUser);
	bool UserDieProc(LPOBJ lpObj, LPOBJ lpTarget);
	void TraoThuongEvent();
	void CleanEffectUserDie();
	bool AddMob(int aIndex, int Class, int Map, int PosX, int PosY, int Dir = 99);
	bool Dialog(LPOBJ lpObj, LPOBJ lpNpc);
	void SetMobDmgDefHp(int aIndex);
	void GetWaveDmgDefHP();
	int CacheListDmgDefHP;
	bool CheckUserInEvent(int aIndex);
	void DataSendToAll(BYTE* lpMsg, int size);
	void SendInfoEvent();
	void CapNhatLuotDi(LPOBJ lpObj);
	void CacheTimeEvent();
private:
	int m_State;
	bool BackUpDataChar(int aIndex);
	bool KhoiPhucDataChar(int aIndex);
	int CacheWaveCount;
	bool EventIsWave;
	//===Mess
	std::map<int, MESSAGE_INFO_ENDLESS> m_MessageInfoBP;
	char* GetMessage(int index);
};

extern CBEventEndLess gBEventEndLess;
