// CustomEventTime.h: interface for the CCustomEventTime class (Client)
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "Protocol.h"
#include "Protect.h"

//**********************************************//
//********** GameServer -> Client     **********//
//**********************************************//
struct PMSG_CUSTOM_EVENTTIME_RECV
{
	PSWMSG_HEAD header;  // C2:F3:E8
	int count;
};

//**********************************************//
//********** Client -> GameServer     **********//
//**********************************************//
struct PMSG_CUSTOM_EVENTTIME_SEND
{
	PSBMSG_HEAD header;  // C1:F3:E8
};

struct CUSTOM_EVENTTIME_DATA
{
	int index;
	int time;
};

class CCustomEventTime
{
public:
	CCustomEventTime();
	virtual ~CCustomEventTime();

	void Init();
	void Load(CUSTOM_EVENT_INFO* info);
	void SetInfo(CUSTOM_EVENT_INFO info);
	void ClearCustomEventTime();
	void GCReqEventTime(PMSG_CUSTOM_EVENTTIME_RECV* lpMsg);
	void DrawEventTimePanelWindow();
	bool EventEventTimeWindow_Close(DWORD Event);
	void OpenWindow();
	bool EventNext(DWORD Event);
	bool EventPrev(DWORD Event);
	void RequestEventTime();

private:
	CUSTOM_EVENT_INFO m_CustomEventInfo[MAX_EVENTTIME];
	int m_count;
	CUSTOM_EVENTTIME_DATA m_gCustomEventTime[MAX_EVENTTIME];
	int m_EventTimeLoad;
	int m_EventTimeEnable;
	DWORD m_EventTimeTickCount;
	int m_Page;
	int m_Arena;
	bool m_isOpen;
	DWORD m_LastRequestTick;
};

extern CCustomEventTime gCustomEventTime;
