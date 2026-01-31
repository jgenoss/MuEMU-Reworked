#pragma once

#include "Protocol.h"

#define MAX_EVENTTIME 42

struct PMSG_CUSTOM_EVENTTIME_RECV
{
	PSWMSG_HEAD h;
	int count;
};

struct PMSG_CUSTOM_EVENTTIME_SEND
{
	PSBMSG_HEAD header; // C1:BF:51

};


struct MOVE_EVENT_REQ
{
	PSBMSG_HEAD h;
	int	MOVE_EVENT;
	int MOVE_MAP;
};

struct CUSTOM_EVENTTIME_DATA
{
	int index;
	int time;
};

struct CUSTOM_EVENT_INFO
{
	int Index;
	char Name[40];
	char Note[40];
	char Gift[200];
	char BtnClick[40];
};


class CCustomEventTime
{
public:
	CCustomEventTime();
	void Load(CUSTOM_EVENT_INFO* info);
	void SetInfo(CUSTOM_EVENT_INFO info);
	void ClearCustomEventTime();
	void GCReqEventTime(PMSG_CUSTOM_EVENTTIME_RECV* lpMsg);
	void DrawEventTimePanelWindow();
	bool EventEventTimeWindow_Close(DWORD Event);
	void OpenWindow();
	void Notice();
	void OpenInterFace();
	bool EventNext(DWORD Event);
	bool EventPrev(DWORD Event);
	//bool EventDrawMenu_ButtonEvent(DWORD Event);
	bool EventDrawMenu_Op21(DWORD Event);
	bool EventDrawMenu_Op22(DWORD Event);
	bool EventDrawMenu_Op23(DWORD Event);
	bool EventDrawMenu_Op24(DWORD Event);
	bool EventDrawMenu_Op25(DWORD Event);
	bool EventDrawMenu_Op26(DWORD Event);
	bool EventDrawMenu_Op27(DWORD Event);
	bool EventDrawMenu_Op28(DWORD Event);
	bool EventDrawMenu_Op29(DWORD Event);
	bool EventDrawMenu_Op30(DWORD Event);
	bool EventDrawMenu_Op31(DWORD Event);
	bool EventDrawMenu_Op32(DWORD Event);
	bool EventDrawMenu_Op33(DWORD Event);
	bool EventDrawMenu_Op34(DWORD Event);
	bool EventDrawMenu_Op35(DWORD Event);
	bool EventDrawMenu_Op36(DWORD Event);
	bool EventDrawMenu_Op37(DWORD Event);
	bool EventDrawMenu_Op38(DWORD Event);
	bool EventDrawMenu_Op39(DWORD Event);
	bool EventDrawMenu_Op40(DWORD Event);
	bool EventDrawMenu_Op41(DWORD Event);
	bool EventDrawMenu_Op42(DWORD Event);
	bool EventDrawMenu_Op43(DWORD Event);
	bool EventDrawMenu_Op44(DWORD Event);
	bool EventDrawMenu_Op45(DWORD Event);
	bool EventDrawMenu_Op46(DWORD Event);
	bool EventDrawMenu_Op47(DWORD Event);
	bool EventDrawMenu_Op48(DWORD Event);
	bool EventDrawMenu_Op49(DWORD Event);
	bool EventDrawMenu_Op50(DWORD Event);
	bool EventDrawMenu_Op51(DWORD Event);
	bool EventDrawMenu_Op52(DWORD Event);
	bool EventDrawMenu_Op53(DWORD Event);
	bool EventDrawMenu_Op54(DWORD Event);
	bool EventDrawMenu_Op55(DWORD Event);
	bool EventDrawMenu_Op56(DWORD Event);
	bool EventDrawMenu_Op57(DWORD Event);
	bool EventDrawMenu_Op58(DWORD Event);
	bool EventDrawMenu_Op59(DWORD Event);
	bool EventDrawMenu_Op60(DWORD Event);
	bool EventDrawMenu_Op61(DWORD Event);
	//	bool EventDrawMenu_Op62(DWORD Event);

	void MOVE_EVENT(int MOVE_EVENT);
private:
	CUSTOM_EVENT_INFO m_CustomEventInfo[MAX_EVENTTIME];
	int count;
	CUSTOM_EVENTTIME_DATA gCustomEventTime[MAX_EVENTTIME];
	int EventTimeLoad;
	int EventTimeEnable;
	int EventTimeTickCount;
	int Page;
	int Arena;

};
extern CCustomEventTime gCustomEventTime;


static char gTime[255] = "%02d:%02d";
static char gSy1[255] = "Sự kiện ";
static char gSy2[255] = "Phím H";



