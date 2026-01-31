#pragma once
#include "stdafx.h"
#include "Protocol.h"

#if(RANKING_NEW == 1)

#define MAXTOP	150

struct CharTop
{
	char Name[11];
	BYTE Class;
	int level;
	int Reset;
	int Relifes;
	int Time;
	int Map;
	char Guild[9];
};

struct DGCharTop
{
	PWMSG_HEAD h;
	CharTop	tp[MAXTOP];
};

class cRanking
{
public:
	cRanking();
	~cRanking();

	void RecvInfo(DGCharTop * lpMsg);
	void Draw();

	bool Active;
	bool Show;
	int StartX;
	int StartY;
	int Page;
	DWORD ClickTime;

	CharTop	RankingChar[MAXTOP];
};
extern cRanking gRanking;
#endif