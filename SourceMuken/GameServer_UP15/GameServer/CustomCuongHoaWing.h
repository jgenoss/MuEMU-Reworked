#pragma once
#include "StdAfx.h"
#include "user.h"
#include "Protocol.h"

struct CUONGHOAWING
{
	int	Enabled;
	int Damage1;
	int Damage2;
	int Damage3;
	int Damage4;
	int Damage5;
};

struct PMSG_CUONGHOAWING_REQ
{
	PSBMSG_HEAD	Head;
	int cuonghoawing;
	int dong1;
	int dong2;
	int dong3;
	int dong4;
	int dong5;
};

class CuongHoaWing
{
public:
	CuongHoaWing(void);
	~CuongHoaWing(void);
	void	Init();
	void	Load(char *path);
	void	Option(LPOBJ lpObj, bool flag);
	int CountItem(LPOBJ lpObj, int level);
	// --
	CUONGHOAWING m_CuongHoaWing;
};

extern CuongHoaWing gCuongHoaWing;