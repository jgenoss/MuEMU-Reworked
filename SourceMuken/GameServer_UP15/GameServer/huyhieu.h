#pragma once
#include "StdAfx.h"
#include "user.h"
#include "Protocol.h"

struct HUYHIEU
{
	int	Enabled;
	int dong1;
	int dong2;
	int dong3;
	int dong4;
	int dong5;
};

struct PMSG_HUYHIEU_REQ
{
	PSBMSG_HEAD	Head;
	int huyhieu;
	int dong1;
	int dong2;
	int dong3;
	int dong4;
	int dong5;
};

class HuyHieu
{
public:
	HuyHieu(void);
	~HuyHieu(void);
	void	Init();
	void	Load(char *path);
	void	Option(LPOBJ lpObj, bool flag);
	int CountItem(LPOBJ lpObj, int level);
	// --
	HUYHIEU m_HuyHieu;
};

extern HuyHieu gHuyHieu;