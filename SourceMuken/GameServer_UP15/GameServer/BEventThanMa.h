#pragma once
#if(THANMA)
#include "User.h"
#include "Protocol.h"
#include "OfflineMode.h"

#define MAX_THANMACHIEN_USER 100

enum eThanMaChienState
{
	TM_EVENT_STATE_BLANK = 0,
	TM_EVENT_STATE_EMPTY = 1,
	TM_EVENT_STATE_STAND = 2,
	TM_EVENT_STATE_START = 3,
	TM_EVENT_STATE_CLEAN = 4,
};

enum eTMTeams
{
	TM_TEAMTHIENTHAN = 1,
	TM_TEAMACQUY = 2,
};

struct TM_EVENT_START_TIME
{
	int Year;
	int Month;
	int Day;
	int DayOfWeek;
	int Hour;
	int Minute;
	int Second;
};

struct TM_EVENT_USER
{
	void Reset() // OK
	{
		this->Index = -1;
		this->Available = false;
		this->Team = -1;
		this->Kills = 0;
		this->Deaths = 0;
		this->Rank = 0;
	}

	int Index;
	bool Available;
	int Team;
	int Kills;
	int Deaths;
	int Rank;
};

struct TM_TIME
{
	int Year;
	int Month;
	int Day;
	int DayOfWeek;
	int Hour;
	int Minute;
	int Second;
};

struct MESSAGE_INFO_THANMACHIEN
{
	int Index;
	char Message[256];
};

struct PMSG_COUNTLIST_TM
{
	PSWMSG_HEAD header;
	int Count;
	int ScoreThienThan;
	int ScoreAcQuy;
	BYTE OpenBXHWindow;
};
struct EVENTHANMA_BXH
{
	char Name[11];
	int Kill;
	int Team;
};


class CThanMaChien
{
public:
	CThanMaChien();
	virtual ~CThanMaChien();
	void Init();
	void Clear();
	void Load(char * FilePath);
	void MainProc();
	void ProcState_BLANK();
	void ProcState_EMPTY();
	void ProcState_STAND();
	void ProcState_START();
	void ProcState_CLEAN();
	void SetState(int state);
	void SetState_BLANK();
	void SetState_EMPTY();
	void SetState_STAND();
	void SetState_START();
	void SetState_CLEAN();
	void CheckSync();
	int GetState();
	bool Dialog(LPOBJ lpObj, LPOBJ lpNpc);
	bool CheckEnterEnabled(LPOBJ lpObj);
	bool CheckReqItems(LPOBJ lpObj);
	int GetEnterEnabled();
	int GetEnteredUserCount();
	bool CheckEnteredUser(int aIndex);
	bool CheckPlayerTarget(LPOBJ lpObj);
	bool CheckPlayerJoined(LPOBJ lpObj, LPOBJ lpTarget);
	bool CheckSelfTeam(LPOBJ lpObj, LPOBJ lpTarget);
	bool AddUser(int aIndex);
	bool DelUser(int aIndex);
	TM_EVENT_USER* GetUser(int aIndex);
	void CleanUser();
	void ClearUser();
	void CheckUser();
	int GetUserCount();
	bool GetUserRespawnLocation(LPOBJ lpObj, int* gate, int* map, int* x, int* y, int* dir, int* level);
	void DivisionTeam();
	int ReturnMaxReset();
	void UserDieProc(LPOBJ lpObj, LPOBJ lpTarget);
	void NoticeSendToAll(int type, char* message, ...);
	void StartTM();

	int TotalPlayer;
	int ScoreBlue;
	int ScoreRed;

	int m_RemainTime;
	int m_State;
	int m_EventTime;

	int m_ThanMaChienEnable;
	int m_ThanMaChienMinUsers;
	int m_ThanMaChienMaxUsers;
	int m_ThanMaChienNPC;
	int m_ThanMaChienNPCMap;
	int m_ThanMaChienNPCX;
	int m_ThanMaChienNPCY;
	int m_ThanMaChienNPCDir;
	void CGOpenWindowNPC(XULY_CGPACKET* aRecv, int aIndex);
	void SendTimeEventAll(int time, int State);
	void CalcUserRank();
	void SendBXHVeClient(BYTE OpenWindow);
	int EventMap;
private:


	//	int m_State;
	//int m_RemainTime;
	int m_StandTime;
	int m_CloseTime;
	int m_TickCount;
	int m_WarningTime;
	//int m_EventTime;
	int EnterEnabled;
	int AlarmMinSave;
	int AlarmMinLeft;
	int TargetTime;
	void ClearConfigCache();
	;



	int WaitingGate;
	int TEAMTHIENTHANGate;
	int TEAMACQUYGate;
	int SetSkin;
	//=== Yeu Cau
	int ReqZen;
	int ReqWC;
	int ReqWP;
	int ReqGP;
	int ReqItemIndex;
	int ReqItemLevel;
	int ReqItemCount;
	int MinLevel;
	int MaxLevel;
	int MinReset;
	int MaxReset;
	int MinMasterReset;
	int MaxMasterReset;

	int BonusKill[3];

	int Coin1;
	int Coin2;
	int Coin3;
	int mIndexRank[10];

	TM_EVENT_USER User[MAX_THANMACHIEN_USER];
	std::vector<TM_TIME> m_TMStartTime;
	//===Mess
	std::map<int, MESSAGE_INFO_THANMACHIEN> m_MessageInfoBP;
	char* GetMessage(int index);
};
extern CThanMaChien gThanMaChien;
#endif