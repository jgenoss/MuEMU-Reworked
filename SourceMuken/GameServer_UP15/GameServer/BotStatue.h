
#include "User.h"
#include "DSProtocol.h"
#if(BOT_STATUE == 1)

#define MAX_BOTSTATUE	30
#define MAX_TIME_RELOAD 30

struct STATUE_START_TIME
{
	int Year;
	int Month;
	int Day;
	int DayOfWeek;
	int Hour;
	int Minute;
	int Second;
};

struct BOTSTATUEStruct
{
	int index;
	int Enabled;
	char Name[11];
	BYTE Map;
	BYTE X;
	BYTE Y;
	BYTE Dir;
	WORD Rank;
	WORD Type;
};
//=====================================
struct SDHP_BOT_INFO_RECV
{
	PWMSG_HEAD header; // C2:04
	WORD index;
	BYTE result;
	char name[11];
	BYTE Class;
	WORD Level;
	DWORD LevelUpPoint;
	DWORD Experience;
	DWORD Money;
	DWORD Strength;
	DWORD Dexterity;
	DWORD Vitality;
	DWORD Energy;
	DWORD Leadership;
	DWORD Life;
	DWORD MaxLife;
	DWORD Mana;
	DWORD MaxMana;
	DWORD BP;
	DWORD MaxBP;
	DWORD Shield;
	DWORD MaxShield;
	BYTE Inventory[INVENTORY_SIZE][16];
	BYTE Skill[MAX_SKILL_LIST][3];
	BYTE Dir;
	DWORD PKCount;
	DWORD PKLevel;
	DWORD PKTime;
	BYTE CtlCode;
	WORD FruitAddPoint;
	WORD FruitSubPoint;
	BYTE Effect[MAX_EFFECT_LIST][13];
	DWORD Kills;
	DWORD Deads;
	int rDanhHieu;
	// GUild
	char GuildName[9];
	int GuildNumber;
	int GuildStatus;;
};
//==============================
class ObjBOTSTATUE
{
public:
	void Init();
	void MainProc();
	int Enabled;
	void Read(char * path);
	void MakeBot();
	void CheckSync();
	BOTSTATUEStruct bot[MAX_BOTSTATUE];
	void BotGetInfoSet(SDHP_BOT_INFO_RECV* lpMsg);
	std::vector<STATUE_START_TIME> m_TimeReloadInfo;
private:
	int GetBotIndex(int aIndex);
	int m_RemainTime;
	int TargetTime;
	DWORD m_TickCount;
};

extern  ObjBOTSTATUE ObjBotStatue;

#endif