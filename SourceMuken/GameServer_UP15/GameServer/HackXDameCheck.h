// HackXDameCheck.h: implementation of the CHackXDameCheck class.
//
//////////////////////////////////////////////////////////////////////
#include "StdAfx.h"

struct HACK_XDAME_INFO
{
	int Index;
	int MinSpeed;
	int MaxSpeed;
	int Delay;
	int MaxCount;
};

class CHackXDameCheck
{
public:
	CHackXDameCheck();
	virtual ~CHackXDameCheck();
	void Load(char* path);
	bool GetInfo(int index, HACK_XDAME_INFO* lpInfo);
	bool GetInfoByXDame(int Speed, HACK_XDAME_INFO* lpInfo);
	bool CheckXDameHack(LPOBJ lpObj, int skill);
private:
	std::map<int, HACK_XDAME_INFO> m_HackXDameInfo;
	int ShowMsg;
};

extern CHackXDameCheck gHackXDameCheck;