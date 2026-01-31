#include "user.h"
#include "stdafx.h"

#if (BOT_STORE == 1)

#define MAX_BOTONLINE	100

struct BotOnlineBodyItems
{
	int num;
	int level;
	int opt;
	bool Enabled;
};

struct BotOnlineStruct
{
	int index;
	int Class;
	int OnlyVip;
	char Name[11];
	BYTE Map;
	BYTE X;
	BYTE Y;
	BYTE Dir;
	bool Enabled;
	BotOnlineBodyItems body[9];
	BYTE ItemCount;
};

class ObjBotOnline
{
public:
	bool Enabled;
	void Read(char * FilePath);
	void MakeBot();
	//void AddItem(int bIndex, int botNum);
	//BYTE CheckSpace(LPOBJ lpObj, int type, BYTE * TempMap);
	BotOnlineStruct bot[MAX_BOTONLINE];
};
extern ObjBotOnline BotOnline;
//void gObjTempInventoryItemBoxSet(LPOBJ lpObj, BYTE * TempMap, int itempos, int xl, int yl, BYTE set_byte);
unsigned char gObjInventoryInsertItemPos1(int aIndex, class CItem item, int pos, int RequestCheck);
#endif