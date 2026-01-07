// CustomEventTime.h: interface for the CCustomEventTime class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "Protocol.h"
#include "Connection.h"

#define MAX_EVENTTIME 42

struct CUSTOM_EVENTTIME_DATA
{
	int index;
	int time;
};

//**********************************************//
//********** GameServer -> Client     **********//
//**********************************************//
struct PMSG_CUSTOM_EVENTTIME_SEND
{
	PSWMSG_HEAD header;  // C2:F3:E8 - Variable size header
	int count;
};

//**********************************************//
//********** Client -> GameServer     **********//
//**********************************************//
struct PMSG_CUSTOM_EVENTTIME_RECV
{
	PSBMSG_HEAD header;  // C1:F3:E8
};

class CCustomEventTime
{
public:
	CCustomEventTime();
	virtual ~CCustomEventTime();
	void Init();
	void GCReqEventTime(int aIndex, PMSG_CUSTOM_EVENTTIME_RECV* lpMsg);

private:
	int m_count;
	CUSTOM_EVENTTIME_DATA m_Data[MAX_EVENTTIME];
};

extern CCustomEventTime gCustomEventTime;
