#include "user.h"
#include "Protocol.h"
#pragma once
#if(BUY_TINH_NANG_NEW)
// -------------------------------------------------------------------------------
struct BUY_TINH_NANG_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
// -------------------------------------------------------------------------------
class BUY_TINH_NANG
{
public:
	// ----
	BUY_TINH_NANG();
	virtual ~BUY_TINH_NANG();
	void		BUY_TINH_NANG_GAME(LPOBJ lpObj, BUY_TINH_NANG_REQ *aRecv);
	// ----
}; extern BUY_TINH_NANG gBUY_TINH_NANG;

#endif
// -------------------------------------------------------------------------------