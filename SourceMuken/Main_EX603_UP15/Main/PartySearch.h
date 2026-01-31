#pragma once

#include "Protocol.h"
#include "Interface.h"

#if(PARTYSEARCH==1)

#define MAX_PARTYLIST 100

struct PARTYLIST{
	int Index;
	char Name[11];
	int Map;
	int X;
	int Y;
	int Level;
	bool DarkWizard;
	bool DarkKnight;
	bool Elf;
	bool MagicGladiator;
	bool DarkLord;
	bool Summoner;
	bool RageFighter;
	bool OnlyGuild;
	bool IsSameGuild;
	int Count;
	bool ButtonActive;
};

struct PMSG_PARTY_REQ_SEND{
	PSBMSG_HEAD header;
	char Name[11];
};

class cPartySearch{
public:
	cPartySearch();
	~cPartySearch();
	void ClearPartyList();
	void InsertPartyList(PMSG_PARTYSEARCH_PARTYLIST* lpInfo);
	/*Draw*/
	void		DrawPartySettingsWindow();
	void		SwitchPartySettingsWindowState();
	bool		EventPartySettingsWindow_Main(DWORD Event);
	bool		EventPartySettingsWindow_Close(DWORD Event);
	bool		EventPartySettingsWindow_All(DWORD Event);
	void		DrawPartySearchWindow();
	void		SwitchPartySearchWindowState() { (gInterface.Data[ePARTYSEARCH_MAIN].OnShow == true) ? gInterface.Data[ePARTYSEARCH_MAIN].Close() : gInterface.Data[ePARTYSEARCH_MAIN].Open(); };

	void		EventPartySearchWindow_All(DWORD Event);
	int			DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...);
	bool		IsWorkZone(float X, float Y, float MaxX, float MaxY);
	void		DrawColoredButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color);
	void        loadBind();
	/*FinDraw*/
	PARTYLIST* GetPartyList(int index);
	void SendPartyRequest(int index);
	PARTYLIST gPartyList[MAX_PARTYLIST];
	int ListsCount;
	int Page;
	int CountPages;
}; extern cPartySearch gPartySearch;

#endif