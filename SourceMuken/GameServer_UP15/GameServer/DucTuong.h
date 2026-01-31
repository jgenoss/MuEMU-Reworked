#include "StdAfx.h"
#include "user.h"
#include "Protocol.h"

#define MAX_DucTuong	30


struct DucTuongBodyItems
{
	int num;
	int level;
	int opt;
	int Enabled;
};

struct DucTuongStruct
{
	int Class;
	char Name[50];
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
	int PCPoints;
	int ChangeColorName;
	int index;
	WORD MaxLevel;
	DWORD rDanhHieu;
	DucTuongBodyItems body[9];
};

struct PMSG_DUCTUONG_SEN
{
	PSBMSG_HEAD	Head;
	int Enabled;
	int Index;
	char Name[11];
};

class DucTuong
{
public:
	int Enabled;
	void LoadConfig();
	void SaveConfig(int aIndex);
	void LoadTuong(int aIndex);
	void TuongSend(int aIndex);
	void MakeBot();
	DucTuongStruct Tuong;
	short Max_Normal_Level;
	BYTE gObjInventoryInsertItemPos(int aIndex, CItem item, int pos, BOOL RequestCheck);

private:

};

extern  DucTuong gDucTuong;