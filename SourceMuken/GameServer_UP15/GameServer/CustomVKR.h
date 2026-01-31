#pragma once
#include "StdAfx.h"
#include "user.h"
#include "Protocol.h"

struct VUKHIRONG
{
	int	Enabled;
	int Dame3;
	int Dame5;
	int Dame7;
};

struct PMSG_VUKHIRONG_REQ
{
	PSBMSG_HEAD	Head;
	int vukhirong;
	int dong1;
	int dong2;
	int dong3;
};

class VuKhiRong
{
public:
	VuKhiRong(void);
	~VuKhiRong(void);
	void	Init();
	void	Load(char *path);
	void	Option(LPOBJ lpObj, bool flag);
	int CountItem(LPOBJ lpObj, int level);
	// --
	VUKHIRONG m_VuKhiRong;
};

extern VuKhiRong gVuKhiRong;