#pragma once

#include "StdAfx.h"
#include "Protocol.h"

#if(VONGQUAY_NEW)

struct LuckySpin_Data
{
	int ItemType;
	int ItemIndex;
	int ItemLevel;
	int ItemSkill;
	int ItemLuck;
	int ItemOption;
	int ItemExc;
	int ItemTime;
};

struct GC_LuckySpin_Data
{
	PSBMSG_HEAD h;
	int ItemType;
	int ItemIndex;
	int ItemLevel;
	int ItemSkill;
	int ItemLuck;
	int ItemOption;
	int ItemExc;
	int ItemTime;
	int WCoinC;
};

struct GC_LuckySpinInit
{
	PSBMSG_HEAD h;
	bool result;
};

struct GC_LuckySpinRoll
{
	PSBMSG_HEAD header;
};

struct GC_LuckySpinUpdateData
{
	PSBMSG_HEAD header; // C1:F3:E3
	int	RollNumber;
};

class CLuckySpin
{
public:
	CLuckySpin();
	~CLuckySpin();
	void Init();
	void Load();
	void Read(char* filename);
	void GCInitItem(int aIndex);
	int	GetItemCount(int UserIndex);
	int CheckItem(int UserIndex, int ItemID, BYTE ItemLevel);
	bool DeleteItemCount(int UserIndex, int SoulCount);
	void GCItemSend(int aIndex);
	void StartRoll(LPOBJ lpObj);
	void MakeItem(int aIndex);
	int number;
	int TicketType;
	int TicketIndex;
	int TicketCount;
	int TicketWcoinC;
	std::vector<LuckySpin_Data> itemdata;
};
extern CLuckySpin gLuckySpin;

#endif