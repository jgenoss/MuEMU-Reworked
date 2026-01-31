#include "user.h"
#include "Protocol.h"

#define MAX_SURVIVOR_SCHEDULE 199
#define MAX_SURVIVOR_COMPETITORS 64

enum Survivor_States
{
	SURVIVOR_STATE_IDLE = 0,
	SURVIVOR_STATE_JOIN_TIMER = 1,
	SURVIVOR_STATE_PREPARE = 2,
	SURVIVOR_STATE_BATTLE = 3,
};

struct INFOPKEVENT_SENDCLIENT
{
	PSBMSG_HEAD header; // C3:F3:03
	DWORD TimeConLaiPKEvent;
};

struct SURVIVOR_SCHEDULE
{
	int DayOfWeek;
	int Hour;
	int Minute;
	int Type;
	int Enable;
};

void PKEventDataSend(int aIndex);

class CSurvivor
{
public:
	CSurvivor();
	virtual ~CSurvivor();

	void Run();
	void LoadSchedule();

	void ClearSchedule();
	void StartCycle(int i, int Type);
	void NoticeSend(BYTE type, char* message, ...);
	bool IsInSurvivorArea(LPOBJ lpObj);
	void ClearEventData();
	void RunningBattle();
	void ClearPlayerData(LPOBJ lpObj);
	bool IsIntruder(LPOBJ lpObj);
	bool IsOutruder(LPOBJ lpObj);
	bool GetUserRespawnLocation(LPOBJ lpObj, int* gate, int* map, int* x, int* y, int* dir, int* level);
	void PrepareToBattle();
	SURVIVOR_SCHEDULE SurvivorSchedule[MAX_SURVIVOR_SCHEDULE];

	int ActiveEvent;
	int JoiningTimer;
	int EventType;
	DWORD StartedAtTick;
	int MinutesShowing;
	int State;
	DWORD BattleStartTick;
	int PlayerCount;
	int WinnerIndex;

	void GiveWinnerPrize(LPOBJ lpObj);

	void TimePkEvent(int aIndex);
	void SendInfoTimePKEvent(int aIndex);


};

extern CSurvivor g_Survivor;