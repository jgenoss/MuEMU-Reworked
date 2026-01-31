// JewelMix.h: interface for the CJewelMix class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "Protocol.h"
#include "User.h"
#define JEWELSBANK_DIR	"..\\Data\\Custom\\JewelsBank.ini"

//**********************************************//
//************ Client -> GameServer ************//
//**********************************************//

struct PSBMSG_JEWELBANK_RECV
{
	PSBMSG_HEAD header; // C1:F3:F4
	int slot;
};

struct PSBMSG_JEWELBANKWITHDRAW_RECV
{
	PSBMSG_HEAD header; // C1:F3:F4
	int type;
	int count;
};

struct PSBMSG_JEWELBANK_UPDATE_RECV
{
	PSBMSG_HEAD header; // C1:F3:F4
};

//**********************************************//
//************ GameServer -> Client ************//
//**********************************************//

struct PSBMSG_JEWELBANK_SEND
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

//**********************************************//
//********** GameServer -> DataServer **********//
//**********************************************//
struct SDHP_CUSTOM_JEWELBANK_SEND
{
	PSBMSG_HEAD header;
	WORD index;
	char account[11];
	WORD type;
	DWORD count;
};

struct SDHP_CUSTOM_JEWELBANK_INFO_SEND
{
	PSBMSG_HEAD header; // C1:F5
	WORD index;
	char account[11];
};

//**********************************************//
//********** DataServer -> GameServer **********//
//**********************************************//
struct SDHP_CUSTOM_JEWELBANK_INFO_RECV
{
	PSBMSG_HEAD header; // C1:F5
	WORD index;
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
//**********************************************//
//**********************************************//
//**********************************************//

class CCustomJewelBank
{
public:
	bool Enable;
	void Load();
	CCustomJewelBank();
	virtual ~CCustomJewelBank();
	int GetJewelSimpleType(int ItemIndex);
	int GetJewelSimpleIndex(int type);
	int GetJewelBundleIndex(int type);
	void JewelBankRecv(PSBMSG_JEWELBANK_RECV* lpMsg, int aIndex);
	void JewelBankWithDrawRecv(PSBMSG_JEWELBANKWITHDRAW_RECV* lpMsg, int aIndex);
	void CustomJewelBankInfoSend(int index);
	void CustomJewelBankInfoRecv(SDHP_CUSTOM_JEWELBANK_INFO_RECV* lpMsg);
	void GCCustomJewelBankInfoSend(LPOBJ lpObj);
	void GDCustomJewelBankAddJewel(LPOBJ lpObj, int type, int qtd);
	void GDCustomJewelBankDelJewel(LPOBJ lpObj, int type, int qtd);
};

extern CCustomJewelBank gCustomJewelBank;
