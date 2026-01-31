#include "user.h"
#include "stdafx.h"

#if (BOT_STORE == 1)

#define MAX_BOTSTORE	100
#define MAIN_INVENTORY_NORMAL_SIZE	(INVENTORY_EXT1_SIZE - PSHOP_SIZE)	// Not included PersonalSh
#define PSHOP_SIZE					32
struct BotStoreBodyItems
{
	int num;
	int level;
	int opt;
	bool Enabled;
};

struct BotStoreItems
{
	int ValueZen;
	WORD num;
	short Level;
	BYTE Opt;
	BYTE Luck;
	BYTE Skill;
	float Dur;
	BYTE Exc;
	BYTE Anc;
	BYTE Sock[5];
};

struct botStoreStruct
{
	int index;
	int Class;
	int OnlyVip;
	int UseVipMoney;
	char Name[11];
	char StoreName[11];
	BYTE Map;
	BYTE X;
	BYTE Y;
	BYTE Dir;
	bool Enabled;
	BotStoreBodyItems body[9];
	BotStoreItems storeItem[32];
	BYTE ItemCount;
};

class ObjBotStore
{
public:
	bool Enabled;
	void Read(char * FilePath);
	void MakeBot();
	void AddItem(int bIndex, int botNum);
	BYTE CheckSpace(LPOBJ lpObj, int type, BYTE * TempMap);
	botStoreStruct bot[MAX_BOTSTORE];
};
extern ObjBotStore BotStore;
void gObjTempInventoryItemBoxSet(LPOBJ lpObj, BYTE * TempMap, int itempos, int xl, int yl, BYTE set_byte);
unsigned char gObjInventoryInsertItemPos(int aIndex, class CItem item, int pos, int RequestCheck);
#endif