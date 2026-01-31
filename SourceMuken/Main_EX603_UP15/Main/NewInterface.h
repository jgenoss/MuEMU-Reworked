#pragma once

#define MAX_OBJECT 500
#include "offset.h"
#if(NEWINTERFACE)
struct MU_4float
{
	float Red;
	float Green;
	float Blue;
	float Alpha;
};

enum ObjectIndex
{
	eUserPanelOpen = 0,
	eUserPanel,
	eUserPanelBtn1,
	eUserPanelBtn2,
	eUserPanelBtn3,
	eUserPanelBtn4,
	eUserPanelBtn5,
	eUserPanelBtn6,
	eUserPanelBtn7,
	eUserPanelBtn8,
	eUserPanelBtn9,
	eUserPanelBtn10,
	eUserPanelBtn11,
	eUserPanelBtn12,
	eSettingsMain,
	eSettingsClose,
	eSettingsChat,
	eSettingsHPBar,
	eSettingsCamera,
	eSettingsMinimap,
	eSettingsEffects,
	eSettingsTime,
	eSettingsFog,
	ePack,
	ePackJewelPack,
	ePackJewelUnPack,
	ePackJewel1,
	ePackJewel2,
	ePackJewel3,
	ePackJewel4,
	ePackJewel5,
	ePackJewel6,
	ePackJewel7,
	ePackJewel8,
	ePackJewel9,
	ePackJewel10,
	ePackJewel11,
	ePackJewel12,
	ePackJewel13,
	ePackJewel14,
	ePackJewel15,
	ePackConfirm10,
	ePackConfirm20,
	ePackConfirm30,
	eBankEx,
	eBankExClose,
	eMessageBoxButton,
};


enum ObjType
{
	objButton,
	objSelectBox,
};

struct InterfaceObj
{
	int		BgIndex;
	float	Width;
	float	Height;
	float	X;
	float	Y;
	float	MaxX;
	float	MaxY;
	DWORD	EventTick;
	bool	OnClick;
	bool	OnShow;
	bool	State;
	int		Type;
	int		OpenedValue;
	bool	leftButtonState;

	void Open()
	{
		this->OnShow = true;
		//pSetCursorFocus = true;
	}

	void Open(int Value)
	{
		this->OnShow = true;
		this->OpenedValue = Value;
	}

	void Close(int Value)
	{
		this->OpenedValue = Value;
		this->OnShow = false;
	}

	void Close()
	{
		this->OnShow = false;
		//pSetCursorFocus = false;
	}

	void Clear()
	{
		this->Width = 0;
		this->Height = 0;
		this->X = 0;
		this->Y = 0;
		this->MaxX = 0;
		this->MaxY = 0;
		this->OnClick = 0;
		this->OnShow = 0;
		this->State = 0;
		this->Type = 0;
	}
};

class CNewInterface
{
public:
	CNewInterface();
	// ----
	void Load();
	void Work();
	void Bind(DWORD objId, float X, float Y, float Height, float Width);
	// ----
	void DrawSettingsWindow();
	bool EventSettingsWindow(DWORD Event);
	void SwitchSettingsWindowState() { (m_Data[eSettingsMain].OnShow == true) ? m_Data[eSettingsMain].Close() : m_Data[eSettingsMain].Open(); };
	// ----
	//void DrawBankEx();
	//bool EventBankExWindow(DWORD Event);
	//void SwitchBankExWindowState() { (m_Data[eBankEx].OnShow == true) ? m_Data[eBankEx].Close() : m_Data[eBankEx].Open(); };
	// ----
	char MsgBoxCaption[50];
	char MsgBoxText[128];
	bool MsgBoxState;
	void OpenMessageBox(char* caption, char* text, ...);
	void DrawMessageBox();
	void EventMessageBox(DWORD Event);
	// ----
	// Misc functions
	// ----
	void DrawClose(int index, int PosX, int PosY, int Color);
	void TextDraw(int PosX, int PosY, int Width, int Arg5, int Color, int Arg7, int Align, HGDIOBJ Font, LPCTSTR Format, ...);
	void DrawBackground(DWORD Object, float PosX, float PosY, float Width, float Height, LPCTSTR Format, ...);
	void DrawButton(int Index, float PosX, float PosY, float Width, float Height, MU_4float* Base, MU_4float* OnClick, MU_4float* Hover, LPCTSTR Text = NULL/*, ...*/);
	static void DrawBarForm(float PosX, float PosY, float Width, float Height, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	void DrawSelectBox(int Index, float PosX, float PosY, float Width, float Height, LPCTSTR Text = NULL);
	void DrawGUI(short ObjectID, float PosX, float PosY);
	bool CheckWindow(int index);
	// ----
	bool IsWorkZone(int Index);
	bool IsWorkZone(int x, int y, int maxX, int maxY);
	//bool EventAllWindow(DWORD Event, MOUSEHOOKSTRUCTEX* Mouse);
	MU_4float Button;
	MU_4float ButtonOnClick;
	MU_4float ButtonHover;
	// ----
	bool leftButtonState;
	// ----
	InterfaceObj m_Data[MAX_OBJECT];
}; extern CNewInterface gNewInterface;
#endif