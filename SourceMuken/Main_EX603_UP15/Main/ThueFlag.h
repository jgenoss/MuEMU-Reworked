#include "StdAfx.h"
#if(FLAG_SKIN)

#define MINIDSKIN 950
#define MAXIDSKIN 1000
#include "Protocol.h"
#include <vector>
#define pIsKeyRelease			((bool(__cdecl*)(int)) 0x791050)
typedef void(*PUSHEVENT_CALLBACK_LPVOID)(LPVOID);


struct PMSG_THUE_FLAG_SEND
{
	PBMSG_HEAD2 h;
	BYTE Type;
	int  Value;
};

struct THUE_FLAG_DATA
{
	int		Id;
	int		Skin;
	int		Price;
	int		Value1;
	int		Value2;
	int		Value3;
	int		Value4;
	int		Value5;
	int		Value6;
	int		Value7;
};

struct PMSG_THUE_FLAG_RECV
{
	PBMSG_HEAD2 h;
	int				Skin;
	THUE_FLAG_DATA	Data;
};

class cThueFlag
{
public:
	cThueFlag();
	~cThueFlag();
	void SetRect(float a1, float a2, float a3, float a4);
	bool CheckRect();
	void Init();
	void Draw();
	void Bind();
	void SendRequest(BYTE type, int value);
	void RecvData(BYTE* a);
	void Clear();
	THUE_FLAG_DATA* FindSkin(int id);
	THUE_FLAG_DATA* FindId(int id);
	static void BuyAction(LPVOID pClass);
	static void NextAction(LPVOID pClass);
	static void PrevAction(LPVOID pClass);
	void DrawButton(int IMGcode, float x, float y, float w, float h, float a6, float a7, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc);

	float x;
	float y;
	float w;
	float h;
	bool Drawing;
//	bool Show;
	int	Skin;
	int Selected;
	DWORD TickCount;
	std::vector<THUE_FLAG_DATA> m_Data;
};

extern cThueFlag ThueFlag;
#endif