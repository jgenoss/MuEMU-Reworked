#include "user.h"

#if (SKY_EVENT == 1)

#define MAX_SKY_EVENT_SUB_LEVEL			 10
#define MAX_SKY_EVENT_LEVEL				  5
#define MAX_SKY_EVENT_STAGES			  3
#define MAX_SKY_EVENT_STAGE_MOB_COUNT	100
#define MAIN_INVENTORY_NORMAL_SIZE	(INVENTORY_SIZE - 32)

enum StateSkyEvent{
	SKY_STATE_BLANK = 0,
	SKY_STATE_EMPTY = 1,
	SKY_STATE_START = 2,
};

struct SKY_EVENT_START_TIME{
	int Year;
	int Month;
	int Day;
	int DayOfWeek;
	int Hour;
	int Minute;
	int Second;
};

struct SkyEventMob{
	short Number;
	short ID;
	short Pos;
};

struct SKYEVENT_INFO{
	int Level;
	int X;
	int Y;
};


struct SkyEventStruct
{
	short m_Index;
	short DBNumber;
	short KillCount[MAX_SKY_EVENT_STAGES];
};

class cSkyEvent
{
public:
	cSkyEvent();
	virtual ~cSkyEvent();

	void LoadData(char * FilePath);
	void Init();
	void DropWinnerItem(int iLevel, int iUser, BYTE SocketBonus, LPBYTE SocketOptions);
	int GetWinner(BYTE iLevel);
	int GetPlayerSubIndex(LPOBJ lpObj, BYTE iLevel);
	int GetLevel(LPOBJ lpObj);
	int MonsterDie(LPOBJ lpObj);
	void ExitPlayers();
	void MsgStringSend(LPSTR  szMsg, BYTE type);
	void AddUser(BYTE iLevel, int iIndex, LPOBJ lpObj);
	BOOL NpcTalk(LPOBJ lpNpc, LPOBJ lpObj);
	int CheckEnterLevel(int iIndex);
	void Teleport(LPOBJ lpObj, BYTE iLevel);
	void SetMonsters(BYTE iLevel, BYTE iStage);
	void ClearAllMonsters();
	void ClearMonsters(BYTE iLevel, BYTE iStage);
	void ReadMonsters(char * FilePath);
	void StartEvent();
	void SendUserExpInfo(BYTE iLevel);
	int CheckUsersAlive(BYTE iLevel);
	void ClearLevelData(BYTE iLevel);
	void RemoveUser(BYTE iLevel, int iUser);
	int ExtraExp[MAX_SKY_EVENT_LEVEL][MAX_SKY_EVENT_STAGES];
	// - Runing
	void MainProc();
	void ProcState_BLANK();
	void ProcState_EMPTY();
	void ProcState_START();
	void SetState(int state);
	void SetState_BLANK();
	void SetState_EMPTY();
	void SetState_START();
	void CheckSync();

	BYTE CurrentStage;
	SkyEventStruct m_UserData[MAX_SKY_EVENT_LEVEL][MAX_SKY_EVENT_SUB_LEVEL];
	SkyEventMob m_MonsterData[MAX_SKY_EVENT_LEVEL][MAX_SKY_EVENT_STAGES][MAX_SKY_EVENT_STAGE_MOB_COUNT];
	SKYEVENT_INFO m_MonsterInfo[MAX_SKY_EVENT_STAGE_MOB_COUNT];

	BOOL Start;
	BOOL Enabled;
	BOOL NPCEnabled;
	BYTE StageMinutes[MAX_SKY_EVENT_STAGES];
	short MonsterStageCount[MAX_SKY_EVENT_LEVEL][MAX_SKY_EVENT_STAGES];
	int Level_Max[MAX_SKY_EVENT_LEVEL];
	int Level_Min[MAX_SKY_EVENT_LEVEL];
	short PlayerCount[MAX_SKY_EVENT_LEVEL];

	short ItemWinType[MAX_SKY_EVENT_LEVEL];
	short ItemWinIndex[MAX_SKY_EVENT_LEVEL];
	short ItemWinLevel[MAX_SKY_EVENT_LEVEL];
	short ItemWinDur[MAX_SKY_EVENT_LEVEL];
	short ItemWinLuck[MAX_SKY_EVENT_LEVEL];
	short ItemWinSkill[MAX_SKY_EVENT_LEVEL];
	short ItemWinOpt[MAX_SKY_EVENT_LEVEL];
	short ItemWinExc[MAX_SKY_EVENT_LEVEL];
	int WCoinCWin[MAX_SKY_EVENT_LEVEL];
	int WCoinPWin[MAX_SKY_EVENT_LEVEL];
	int GoblinPointWin[MAX_SKY_EVENT_LEVEL];
	int Count;
	int MobID;
	int MonsterLoaded;

	void	SendNotify(int aIndex, int WCoinC, int WCoinP, int GoblinPoint);
	bool	CommandAddPK(LPOBJ lpObj, char* arg, int Npc);

private:
	int m_State;
	int m_RemainTime;
	int m_TargetTime;
	int m_TickCount;

	std::vector<SKY_EVENT_START_TIME> m_SkyEventTime;

};

void cSkyEvent__InsideTrigger(void * lpParam);
BOOL SKYEVENT_MAP_RANGE(int Map, BYTE X, BYTE Y);
BOOL SetPosMonsterSkyEvent(int aIndex, int PosTableNum);
BOOL gObjIsNewClass(LPOBJ lpObj);
int gObjMonsterAdd(WORD Type, BYTE Map, BYTE X, BYTE Y);
BOOL DeleteItemByLevel(int iIndex, DWORD itemId, BYTE ItemLevel);
int ItemGetNumberMake1(int type, int index);

extern cSkyEvent SkyEvent;

#endif