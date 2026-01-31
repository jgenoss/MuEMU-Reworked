//////////////////////////////////////////////////////////////////////

#pragma once

#if(BOSS_GUILD == 1)

#include "User.h"
#include "Protocol.h"

#define MAX_GUILD 20
#define MAX_CHAR 100


struct BOSSGUILD_CGPACKET
{
	PSBMSG_HEAD header; // C3:F3:03
	BYTE CongVao;

};

struct INFOBOSSGUILD_SENDCLIENT
{
	PSBMSG_HEAD header; // C3:F3:03
	BYTE OpenWindow;
};

struct BOSSGUILDTIME_SENDCLIENT
{
	PSBMSG_HEAD header; // C3:F3:03
	int	TimeBossGuild;
};

enum eBOSGUILDState
{
	BOSSGUILD_STATE_BLANK = 0,
	BOSSGUILD_STATE_EMPTY = 1,
	BOSSGUILD_STATE_START = 2,
};

struct BOSSGUILD_START_TIME
{
	int Year;
	int Month;
	int Day;
	int DayOfWeek;
	int Hour;
	int Minute;
	int Second;
};


//**********************************************//
//********** GameServer -> DataServer **********//
//**********************************************//

//struct SDHP_RANKING_CTC_GUILD_SAVE_SEND
//{
//	PBMSG_HEAD header; // C1:74
//	char name[9];
//	DWORD score;
//};
//
//struct SDHP_RANKING_CTC_PLAYER_SAVE_SEND
//{
//	PBMSG_HEAD header; // C1:75
//	WORD index;
//	char account[11];
//	char name[11];
//	DWORD score;
//};


struct BOSSGUILD_GUILD
{
	void Reset() // OK
	{
		this->Number = -1;
		this->Owner = 0; //Chiem tru
		ZeroMemory(GuildOwner, sizeof(GuildOwner));
	}
	int Number;
	int Owner;
	char GuildOwner[9];
};

struct BOSSGUILD_CHAR
{
	void Reset() // OK
	{
		memset(this->Name, 0, sizeof(this->Name));
		this->Index = -1;
		this->CongVao = 0;
	}

	int Index;
	char Name[11];
	int CongVao;
};

struct BONUS_POINT_MONSTER
{
	int WCoin;
	int WCoinP;
	int GobinP;
	int IndexBonus;
	int IndexType;
	int IndexItem;
};

struct BONUS_POINT_GUILD // ok
{
	int Score;
	int WCoin;
	int WCoinP;
	int GobinP;
	int IndexBonus;
	int IndexItemBag;
};

void BossGuildDataSend(int aIndex);
//---
class CBossGuild
{
public:
	CBossGuild();
	virtual ~CBossGuild();
	//---

	void Init();
	void Load(char* path);
	void MainProc();
	void ProcState_BLANK();
	void ProcState_EMPTY();
	void ProcState_START();
	void SetState(int state);
	void SetState_BLANK();
	void SetState_EMPTY();
	void SetState_START();
	void CheckSync();
	void Clear();
	bool Dialog(int aIndex, int aNpcIndex);
	bool CheckPlayerTarget(LPOBJ lpObj, LPOBJ lpTarget, int Type);
	void SetGuild(int gIndex);
	void AddGuild(int gIndex);
	bool GetGuild(int gIndex);
	void SetChar(int cIndex, int CongVao);
	void AddChar(int cIndex, int CongVao);
	int GetCongVao(int cIndex);
	bool GetChar(int cIndex);
	void CheckChar();
	void SetGuildTop();
	int m_Active;

	int m_RemainTimeWinner;

	int GuildKillBoss;

	void StartBossGuild(); // ok

	void StartBossChienBinh();
	void StartBossPhuThuy();
	void StartBossTienNu();
	void StartBossThuatSi();
	void StartBossThietBinh();
	void StartBossDauSi();
	void StartBossChuaTe();


	void ClearMonster(); // ok

	int GateMove[5]; // ok

	int m_MapBossGuild;

	int KillBoss;

	int CheDo1;
	int CheDo2;

	bool GetUserRespawnLocation(LPOBJ lpObj, int* gate, int* map, int* x, int* y, int* dir, int* level);
	void CGPacketBossGuild(BOSSGUILD_CGPACKET* aRecv, int aIndex);

	void SendTimeBossGuild(int aIndex, int Type);

	bool MonsterDie(int aIndexMonster, int aIndexUser);

	BONUS_POINT_MONSTER BossPhuThuy;
	BONUS_POINT_MONSTER BossChienBinh;
	BONUS_POINT_MONSTER BossTienNu;
	BONUS_POINT_MONSTER BossThuatSi;
	BONUS_POINT_MONSTER BossThietBinh;
	BONUS_POINT_MONSTER BossDauSi;
	BONUS_POINT_MONSTER BossChuaTe;

	BONUS_POINT_GUILD GuildWin; // ok

private:

	int m_Enabled;
	int m_State;
	int m_RemainTime;
	int m_TargetTime;
	int m_TickCount;
	int m_WarningTime;
	int m_EventTime;
	int MinutesLeft;
	int WinnerNumber;
	char WinnerName[9];
	char WinnerNameOLD[9];
	//---
	std::vector<BOSSGUILD_START_TIME> m_BossGuildStartTime;

	BOSSGUILD_GUILD Guild[MAX_GUILD];
	BOSSGUILD_CHAR Char[MAX_CHAR];

	int Class;
	int Map;
	int X;
	int Y;
	int GuildMinPlayer;
};

extern CBossGuild gBossGuild;

#endif
