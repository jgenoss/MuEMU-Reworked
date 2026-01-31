#pragma once

#include "User.h"
#include "Protocol.h"

#define MAX_CTC_CHAR 100

struct CTCMINI_CGPACKET
{
	PSBMSG_HEAD header; // C3:F3:03
	BYTE CongVao;

};

struct INFOCTCMINI_SENDCLIENT
{
	PSBMSG_HEAD header; // C3:F3:03
	BYTE OpenWindow;
	BYTE GuildWinOld;

};

struct CTCMINIKILL_SENDCLIENT
{
	PSBMSG_HEAD header; // C3:F3:03
	int	TimeCTCMini;
	BYTE Cong[3];
	BYTE Tru[3];
	char GNameTru1[9];
	char GNameTru2[9];
	char GNameTru3[9];

};
enum eCTCState
{
	CTC_STATE_BLANK = 0,
	CTC_STATE_EMPTY = 1,
	CTC_STATE_START = 2,
};

struct CTC_START_TIME
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

struct SDHP_RANKING_CTC_GUILD_SAVE_SEND
{
	PBMSG_HEAD header; // C1:74
	char name[9];
	DWORD score;
};

struct SDHP_RANKING_CTC_PLAYER_SAVE_SEND
{
	PBMSG_HEAD header; // C1:75
	WORD index;
	char account[11];
	char name[11];
	DWORD score;
};


struct CTC_CHAR
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

struct BONUS_POINT
{
	int WCoin;
	int WCoinP;
	int GobinP;
	int Ruud;
	int IndexBonus;
};

class CCTCmini
{
public:
	CCTCmini();
	virtual ~CCTCmini();
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
	void SetChar(int cIndex, int CongVao);
	void AddChar(int cIndex, int CongVao);
	int GetCongVao(int cIndex);
	bool GetChar(int cIndex);
	void CheckChar();
	void SavePheWinIni();

	int m_Active;
	void StartCTCMini();
	void TestCTCMini();
	bool MonsterDie(int aIndexMonster, int aIndexUser);

	int m_Enabled;

	BONUS_POINT b_PhaTru;
	BONUS_POINT b_PhaCong;
	BONUS_POINT b_GuildWin;
	int GateMove[5];
	bool GetUserRespawnLocation(LPOBJ lpObj, int* gate, int* map, int* x, int* y, int* dir, int* level);
	void CGPacketCTCMini(CTCMINI_CGPACKET* aRecv, int aIndex);
	void SendKillCTCMini(int aIndex, int Type);
	int WinnerNumberOLD;
	bool CCTCmini::CheckReqItems(LPOBJ lpObj);
	bool CCTCmini::CheckMapWin(int aIndex,int MapCheck);

private:
	int IDMapWin;
	int m_State;
	int m_RemainTime;
	int m_TargetTime;
	int m_TickCount;
	int m_WarningTime;
	int m_EventTime;
	int MinutesLeft;
	int WinnerNumber;
	int WinnerTime;
	
	//==Check Item
	int EventItemID;
	int EventItemCount;
	int mWC;
	int mWP;
	int mGP;

	int m_RemainTimeWinner;

	std::vector<CTC_START_TIME> m_CTCMinitartTime;
	CTC_CHAR Char[MAX_CTC_CHAR];

	void SetEntranceZone();
	void DelEntranceZone();
	void XoaTruChiDinh(BYTE n);
	void ThemTruPhe(int n, int Phe);
	int SoTruDaChiem(int Phe, int aIndex);
	int IndexCong[3];
	int IndexTru[3];

	int Class;
	int Map;
	int X;
	int Y;
	int MinPlayer;
	bool CCTCmini::DelUser(int aIndex); // OK
	CTC_CHAR* CCTCmini::GetUser(int aIndex); // OK
	int TotalPlayer;
};

extern CCTCmini gCTCMini;
static char* NamePhe[2] = { "Đạo Tặc","Bảo Tiêu" };
static const BYTE MapCTC = 98;
static const int ClassCong = 525;
static const int ClassTru = 800;
//Tru 1 : 96, 165 / Tru 2: 128,165 / Tru 3: 159,165
static const BYTE XoaTru[3][4] = { { 96, 165, 96, 165 }, { 128, 165, 128, 165 }, { 159, 165, 159, 165 } };  //att = 6
static const BYTE ThemTru[3][2] = { { 96, 165 }, { 128, 165 }, { 159, 165 } };

static const BYTE XoaCong[3][4] = { { 94, 131, 98, 133 }, { 126, 131, 130, 133 }, { 159, 131, 163, 133 } };
static const BYTE ThemCong[3][2] = { { 96, 131 }, { 128, 131 }, { 161, 131 } };

static const BYTE XoaDuongVao[5][4] = { { 79, 31, 85, 33 }, { 108, 31, 114, 33 }, { 138, 31, 144, 332 }, { 171, 31, 176, 33 }, { 122, 231, 136, 233 } }; //att = 16

