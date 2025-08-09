#pragma once
#include <windows.h>

#define MAX_UI_OBJECTS 256

struct UIObject {
	DWORD ModelID;
	float Width;
	float Height;
	float X;
	float Y;
	float MaxX;
	float MaxY;
	DWORD EventTick;
	bool OnClick;
	bool OnShow;
	BYTE Attribute;
};

class UIBase {
public:
	UIBase();

	void BindObject(short ObjectID, DWORD ModelID, float Width, float Height, float X, float Y);
	void DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	int DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	void DrawGUI(short ObjectID, float PosX, float PosY);
	void DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color);
	void ResetDrawIMG(short ObjectID);
	float DrawRepeatGUI(short ObjectID, float X, float Y, int Count);

	//bool IsWorkZone(short ObjectID);
	float GetResizeX(short ObjectID);

protected:
	UIObject Objects[MAX_UI_OBJECTS];
};

extern UIBase gUIBase;
