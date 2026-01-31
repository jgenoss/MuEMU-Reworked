#pragma once
//----

#include "User.h"
#include "Protocol.h"
//----

struct BANKEX_GD_SAVE_POINT
{
	PSBMSG_HEAD	h;
	// ----
	WORD	UserIndex;
	char	AccountID[11];
	long	Money;
	long	Bless;
	long	Soul;
	long	Chaos;
	long	Creation;
	long	Life;
	long	Harmony;
};
// -------------------------------------------------------------------------------

struct BANKEX_GD_REQ_POINT
{
	PSBMSG_HEAD	h;
	// ----
	WORD	UserIndex;
	char	AccountID[11];
};
// -------------------------------------------------------------------------------

struct BANKEX_DG_GET_POINT
{
	PSBMSG_HEAD	h;
	// ----
	WORD	UserIndex;
	long	Money;
	long	Bless;
	long	Soul;
	long	Chaos;
	long	Creation;
	long	Life;
	long	Harmony;
};

struct PMSG_BANKEX_UPDATE_SEND
{
	PSBMSG_HEAD header;
	long	Money;
	long	Bless;
	long	Soul;
	long	Chaos;
	long	Creation;
	long	Life;
	long	Harmony;
	int		MaxWarehouse;
};
// -------------------------------------------------------------------------------

enum eBankExType
{
	BANKEX_BLESS = 0,
	BANKEX_SOUL = 1,
	BANKEX_CHAOS = 2,
	BANKEX_CREATION = 3,
	BANKEX_LIFE = 4,
	BANKEX_HARMONY = 5,
};

class CBankEx
{
public:
	CBankEx();
	virtual ~CBankEx();
	void InitUser(LPOBJ lpObj);
	void GDSavePoint(int aIndex);
	void GDReqPoint(int aIndex);
	void DGGetPoint(BANKEX_DG_GET_POINT * aRecv);
	void GCUpdateBankEx(int aIndex);
	void Make(int aIndex, int Count, int Type);
	void Change(int aIndex, int Count, int Type);
}; extern CBankEx gBankEx;