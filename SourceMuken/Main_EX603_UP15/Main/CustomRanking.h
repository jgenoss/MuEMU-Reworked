

#pragma once
#include "stdafx.h"
#include "Protocol.h"
#include "Import.h"
#include "Interface.h"

#if(RANKINGGOC == 1)

#define MAX_RANK 10

struct PMSG_CUSTOM_RANKING_RECV
{
	PSWMSG_HEAD h;
	int index;
	char rankname[20];
	char col1[20];
	char col2[20];
	int count;
};

struct PMSG_CUSTOM_RANKING_COUNT_RECV
{
	PSBMSG_HEAD header; // C1:BF:51
	int count;
};

struct PMSG_CUSTOM_RANKING_COUNT_SEND
{
	PSBMSG_HEAD header; // C1:BF:51
};

struct PMSG_CUSTOM_RANKING_SEND
{
	PSBMSG_HEAD header; // C1:BF:51
	BYTE type;
};

struct CUSTOM_RANKING_DATA
{
	char szName[20];
	int valor;
};

class CCustomRanking
{
public:
	CCustomRanking();

	void		OPEN_WINDOW_RANKING() { gInterface.Data[eRankPANEL_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_WINDOW_RANKING() { gInterface.Data[eRankPANEL_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_WINDOW_RANKING() { return gInterface.Data[eRankPANEL_MAIN].OnShow; };


	void ClearCustomRanking();
	void GCReqRanking(PMSG_CUSTOM_RANKING_RECV* lpMsg);
	void GCReqRankingCount(PMSG_CUSTOM_RANKING_COUNT_RECV* lpMsg);
	void DrawRankPanelWindow();
	bool EventRankingNext(DWORD Event);
	bool EventRankingBack(DWORD Event);
	int RankingType;
	int RankEnable;
	int RankingCount;
	bool EventRankingWindow_Close(DWORD Event);
	void OpenWindow();

private:
	char rankname[20];
	char col1[20];
	char col2[20];
	int count;
	CUSTOM_RANKING_DATA gCustomRanking[MAX_RANK];
	int RankLoad;

};
extern CCustomRanking gCustomRanking;
#endif


