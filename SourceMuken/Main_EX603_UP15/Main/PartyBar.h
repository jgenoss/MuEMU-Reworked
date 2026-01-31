#pragma once

#include "stdafx.h"
#include "Protocol.h"
#include "Object.h"

#define MAX_USER_IN_PARTY	10

//----- (0064E1F0) --------------------------------------------------------
#define sub_4DB1F0			((int(__cdecl*)( )) 0x004DB1F0)
#define sub_64E1F0			((int(__cdecl*)(int a1)) 0x0064E1F0)
#define sub_9CF130			((int(__cdecl*)(int a1)) 0x009CF130)
#define sub_420120			((int(__thiscall*)(LPVOID This, int a2)) 0x420120)
#define sub_4200B0			((int(__thiscall*)(LPVOID This, unsigned __int8 a2, unsigned __int8 a3, unsigned __int8 a4, unsigned __int8 a5)) 0x4200B0)
#define sub_4C8640			((char(__thiscall*)(LPVOID This, char a2)) 0x4C8640)
#define sub_637A30			((void(__cdecl*)()) 0x637A30)
#define sub_420080			((int(__thiscall*)(LPVOID This, int a2)) 0x420080)
#define sub_5996A0			((int(__cdecl*)(int a1, const CHAR *a2, int a3, int a4, int a5)) 0x5996A0)
#define sub_84C8B0			((char(__stdcall*)(int a1)) 0x0084C8B0)
#define sub_5B7900			((int(__cdecl*)(unsigned __int8 a1)) 0x5B7900 )
#define sub_84B0B0			((char(__thiscall*)(int a1, int a2)) 0x0084B0B0)

#define sub_64E120			((int(__cdecl*)( int a1)) 0x0064E120)//-- recv party list

#define sub_84A930			((void(__thiscall*)(signed int a4, signed int a5, int a6, int a7, int a8, signed int a9)) 0x0084A930)
#define sub_84AD10			((char(__thiscall*)(int a1, int a5, int a6, char a7)) 0x0084AD10)
#define GetInstance					((int(__cdecl*)()) 0x00861110)

struct PMSG_PARTYDELUSER
{
	PBMSG_HEAD h;
	BYTE Number;	// 3
};

struct PMSG_PARTYLIST
{
	char szId[10];
	BYTE Number;
	BYTE MapNumber;
	BYTE X;
	BYTE Y;
	int Life;
	int MaxLife;
};

struct PMSG_PARTYLISTCOUNT
{
	PBMSG_HEAD h;
	BYTE Result;
	BYTE Count;
};

struct PMSG_DEFAULT_COUNT
{
	PBMSG_HEAD h;
	BYTE Count;	// 3
};

struct PMSG_PARTYLIFEALL
{
	BYTE Number;	// 0
};

struct PartyUser //-> Complete (size: 32)
{
	/*+0*/	char	Name[10];
	/*+10*/	BYTE	Unknown10;
	/*+11*/	BYTE	Unknown11;
	/*+12*/	BYTE	MapNumber;
	/*+13*/	BYTE	PosX;
	/*+14*/	BYTE	PosY;
	/*+15*/ char 	gap01;
	/*+16*/	int		Life;
	/*+20*/	int		MaxLife;
	/*+24*/	BYTE	LifePercent;
	/*+25*/ BYTE	gap02[3];
	/*+28*/	int		ViewportID;
};

struct GC_PARTYNEWLEADER
{
	PBMSG_HEAD2 h;
	BYTE id;
};

class PartyBar10
{
public:
	PartyBar10();
	virtual ~PartyBar10();

	void Init();
	void Load();

	static void JCGCPartyListAll(LPBYTE aRecv);
	static int MainPartyVieweID();
	static int JCGetViewID(unsigned __int8 a1);
	static void GetCoordPanelD(int a1, float a2, float a3, float a4, float a5);
	static void DrawPanelD();
	static int PartyMemberLifeRecv(LPBYTE aRecv);

	int JCPartStructID();
	int FilterPartyNumber(int a1, int a2, unsigned int a3);
	int FilterPartyNumberEx(PartyUser* lpUser, char* Name, unsigned int a3);

	int PartyMemberCount;
	DWORD ClickTick;
	int OnClick;
	int OnClickD;
	int Page;
	bool PartyShow;

	PartyUser JCPartyDB[MAX_USER_IN_PARTY];
	BYTE LifePercent[MAX_USER_IN_PARTY * 32];
	int ViewportID[MAX_USER_IN_PARTY * 8];
};

extern PartyBar10 QTPary;

