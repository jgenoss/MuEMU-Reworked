
#include "User.h"

#if(BOTHUMUADORAC == 1)

#define MAX_BOTTHUMUA	30
#define MAX_BOTTHUMUASKILLS	5


struct BotThuMuaBodyItems
{
	int num;
	int level;
	int opt;
	int Enabled;
};

struct botThuMuaSkill
{
	int BotIndex;
	WORD skill;
	int time;
	int power;

};


struct botThuMuaStruct
{
	int Class;
	char Name[11];
	BYTE Map;
	BYTE X;
	BYTE Y;
	BYTE Dir;
	int OnlyVip;
	int ActiveGensFamily;
	int ContributionGens;
	int GensFamily;
	int Enabled;
	int Zen;
	int WCoinCMin;
	int WCoinCMax;
	int WCoinP;
	int ChangeColorName;
	int index;
	BOOL OnlySameType;
	BOOL OnlyLowerIndex;
	BOOL AcceptAncient;
	WORD MaxLevel;
	BYTE MaxExc;
	BotThuMuaBodyItems body[9];
	botThuMuaSkill skill[MAX_BOTTHUMUASKILLS];
	BYTE SkillCount;
	BYTE Rate;

	BOOL AllowLevel;
	BOOL AllowOpt;
	BOOL AllowLuck;
	BOOL AllowSkill;
	BOOL AllowExc;
	//BOOL AllowFFFF;
};

class BotThuMuaer
{
public:
	//int Enabled;
	void Read(char * path);
	void MakeBot();
	//int GetBotIndex(int aIndex);
	BOOL IsInTrade(int aIndex);
	BOOL TradeOpen(int index, int nindex);
	void TradeOk(int aIndex);
	void TradeCancel(int aIndex);
	//	BOOL TradeOpen(int index, int nindex);
	//botThuMuaStruct bot[MAX_BOTTHUMUA];
	short Max_Normal_Level;
	BYTE gObjInventoryInsertItemPos(int aIndex, CItem item, int pos, BOOL RequestCheck);

private:
	int GetBotIndex(int aIndex);
	bool Enabled;
	int	getNumberOfExcOptions(int checksum);
	bool AllowExc(BYTE BotNum, BYTE ExcOpt);
	BYTE Alchemy(int aIndex, int BotNum);
	botThuMuaStruct bot[MAX_BOTTHUMUA];
};

extern  BotThuMuaer BotThuMua;

#endif