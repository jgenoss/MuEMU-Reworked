#include "user.h"
#include "Protocol.h"

#define CHANBUG    1

#pragma once


struct REQUEST_HACK_REQ
{
	PSBMSG_HEAD h; // C1:BF:51
	int Number;
};


class Lee
{
public:
	Lee();
	virtual ~Lee();
	void ReqHackRequest(LPOBJ lpObj, REQUEST_HACK_REQ* aRecv);
}; extern Lee gLee;

