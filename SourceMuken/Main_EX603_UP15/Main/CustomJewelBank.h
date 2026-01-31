#pragma once

#include "Protocol.h"
#include "Object.h"



#define ITEM_BASE_MODEL 1171
// ---

#define pGetItemBmdStruct(ItemId)   (ItemBmdStruct*)(*(DWORD*)0x8128AC0 + sizeof(ItemBmdStruct) * ItemId)
#define SET_ITEMOPT_LEVEL(x)  (x << 3)

struct CUSTOM_JEWELBANK_DATA
{
	int Bless;
	int Soul;
	int Life;
	int Creation;
	int Guardian;
	int GemStone;
	int Harmony;
	int Chaos;
	int LowStone;
	int HighStone;
};

struct PSBMSG_JEWELBANK_SEND
{
	PSBMSG_HEAD header; // C1:F3:F4
	int slot;
};

struct PSBMSG_JEWELBANKWITHDRAW_SEND
{
	PSBMSG_HEAD header; // C1:F3:F4
	int type;
	int count;
};

struct PSBMSG_JEWELBANK_UPDATE_SEND
{
	PSBMSG_HEAD header; // C1:F3:F4
};

struct PSBMSG_JEWELBANK_RECV
{
	PSBMSG_HEAD h;
	int Bless;
	int Soul;
	int Life;
	int Creation;
	int Guardian;
	int GemStone;
	int Harmony;
	int Chaos;
	int LowStone;
	int HighStone;
};
// ---
class CCustomJewelBank
{
public:
	CCustomJewelBank();
	void Load();
	// ---
	void DrawNewStatus();
	void DrawJewelBankWindow();
	void OpenWindow();
	bool CommandNext(DWORD Event);
	bool CommandPrev(DWORD Event);
	bool EventJewelBankWindow_Close(DWORD Event);
	bool EventJewelBankWithDraw(DWORD Event);
	void JewelBankWithDrawSend(int type, int count);
	// ---
	void JewelBankSend(int slot);
	void GCCustomJewelBankInfoRecv(PSBMSG_JEWELBANK_RECV* lpMsg);


private:
	// ---
	CUSTOM_JEWELBANK_DATA m_Data;
	bool IsOpen;
	short StatusLoad;
	DWORD StatusTick;
	int Loading;
	int JewelEnable;
	int Bless;
	int Soul;
	int Life;
	int Creation;
	int Guardian;
	int GemStone;
	int Harmony;
	int Chaos;
	int LowStone;
	int HighStone;
	int Page;
};
extern CCustomJewelBank gCustomJewelBank;
