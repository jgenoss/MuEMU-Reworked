#pragma once
#include "Protocol.h"
#include "JCOptionBox.h"

//#define takumi12 1
//#define MAX_USER_IN_PARTY 5

#define sub_4DB0E0					((BOOL(__cdecl*)(int a1))0x004DB0E0)
#define sub_59A8B0					((bool(__stdcall*)())0x0059A8B0)
//-- Cursor
#define sub_637E80					((void(__cdecl*)(int x, float y, float w, float h, float giro, float a9, float a10, float a11, float a12, float a13))0x00637E80)
#define sub_4F6170					((void(__cdecl*)(float a1))0x004F6170)
#define sub_83C310					((char(__thiscall*)(DWORD * This))0x0083C310)
#define sub_861260					((int(__thiscall*)(int This))0x00861260)

#define sub_78ECE0					((int(__thiscall*)(int This))0x0078ECE0)
#define sub_8615E0					((int(__thiscall*)(int This))0x008615E0)
#define GetWindowShop				((int(__thiscall*)(int This))0x00861280)
#define CheckRepairInv				((int(__thiscall*)(int This))0x00834550)
#define CheckRepairShop				((int(__thiscall*)(int This))0x00847EF0)

#define CursorX					*(DWORD*)0x879340C
#define CursorY					*(DWORD*)0x8793410
#define ItemTarget				*(DWORD*)0xE61728
#define NpcTarget				*(DWORD*)0xE6172C
#define PlayerTarget			*(DWORD*)0xE61730
//--
#define sub_861A60					((int(__thiscall*)(int This))0x00861A60)
#define sub_7D6270					((int(__thiscall*)(int This, int a5))0x007D6270)
//-- Offset Ventanas
#define getWindowConfig_35 ((int(__thiscall*)(int This))0x00861620)
#define sub_9CEFB0        ((int(__thiscall*)(int a1)) 0x009CF130) //1
//**********************************************//
//************ Takumi12 -> Client ************//
//**********************************************//
//#if (takumi12 == 1)
//struct PMSG_PARTY_LIST_SEND
//{
//	PBMSG_HEAD header; // C1:42
//	BYTE result;
//	BYTE count;
//};
//
//struct PMSG_PARTY_LIST
//{
//	char name[10];
//	BYTE number;
//	DWORD CurMana;
//	DWORD MaxMana;
//};
//struct PMSG_PARTY_LIST_VIEW
//{
//	DWORD ViewportID;
//};
////---
//struct PMSG_PARTY_LIFE_SEND
//{
//	PBMSG_HEAD header; // C1:44
//	BYTE count;
//};
//
//struct PMSG_PARTY_LIFE
//{
//	BYTE mana;
//	char name[11];
//};
//#endif

struct uintInput
{
	bool	selected;
	UINT	value;
	UINT	max;
	int		delay;
	DWORD	lastActionTime;

	uintInput()
	{
		selected = false;
		value = 0;
		max = UINT_MAX;
		delay = 150;
		lastActionTime = GetTickCount();
	}
	uintInput(UINT a1, UINT a2, int a3)
	{
		selected = false;
		value = a1;
		max = a2;
		delay = a3;
		lastActionTime = GetTickCount();
	}
};

struct textSize
{
	float	width;
	float	height;
	float	resize_width;
	float	resize_height;
};

class Centralizado
{
public:
	Centralizado();
	virtual ~Centralizado();
	void InitCentral();
	void RenderCursor();
	static void RenderGame();
	void PrintDropBox(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6);
	static signed int MoveRenderCameraDefault();
	bool EventPushCursor(int x, int y, int w, int h);


	void gDrawWindowCustom(float StartX, float StartY, float CuaSoW, float CuaSoH, int eNumWindow, bool LockClose, LPCSTR Text, ...);
	void gInfoBox(float PosX, float PosY, float Width, float Height, DWORD bkcolor, float Arg5, int Arg6);
	bool gDrawButton(float PosX, float PosY, float SizeButton, int FontSize,LPCSTR Text, ...);
	bool gDrawButton(float PosX, float PosY, float SizeButton, float mSizeButtonH, int FontSize, LPCSTR Text, ...);
	void DrawFrame(DWORD ModelID, float X, float Y, float W, float H, float SourceX = 0, float SourceY = 0, float SourceW = 225, float SourceH = 225, float ScaleW = 1.5f, float ScaleH = 1.5f, bool ScaleUp = 0);
	DWORD LockMouseMoveClick;

	float		resizeX(float);
	float		resizeY(float);
	
//#if (takumi12 == 1)
//	void ClearPartyInfo();
//	void CGPartyListRecv(PMSG_PARTY_LIST_SEND * lpMsg);
//	void InsertPartyInfo(PMSG_PARTY_LIST* lpMsg);
//	void ClearPartyLife();
//	void CGPartyLifeRecv(PMSG_PARTY_LIFE_SEND * lpMsg);
//	void InsertPartyLife(PMSG_PARTY_LIFE * lpInfo);
//public:
//	int m_PartyCount;
//	PMSG_PARTY_LIST m_PartyInfo[MAX_USER_IN_PARTY];
//	PMSG_PARTY_LIST_VIEW m_PartyViewPort[MAX_USER_IN_PARTY];
//	PMSG_PARTY_LIFE m_PartyLife[MAX_USER_IN_PARTY];
//#endif
public:
	float JTMoveX; // ST08_4@1
	float JTMoveY; // ST04_4@1
	bool isOpenWinCustom();
	bool CheckMouseOverWinCustom();
	void MoverWinCustom(int x, int y);
	JCOptionBox JCOption[10];
	int TimerPush;

	bool IsWorkZone(float a1, float a2, float a3, float a4);
	textSize	getTextSize(char*);
	void DrawInput(float a1, float a2, float a3, float a4, BYTE a5, uintInput* a6, DWORD a7, DWORD a8, DWORD a9);
	uintInput* bufferUint;
	void keyPressed(DWORD a1);

};
extern Centralizado gCentral;

