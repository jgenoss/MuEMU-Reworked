#pragma once
#include "Protocol.h"
#include "Defines.h"

struct REQUEST_HACK_OPTION_SEND
{
	PSBMSG_HEAD header; // C1:BF:511
	int Number;
};
class MSGCommon
{
public:
	MSGCommon();
	~MSGCommon();
	void SendHack(int Number);
public:
}; extern MSGCommon gMSGCommon;



