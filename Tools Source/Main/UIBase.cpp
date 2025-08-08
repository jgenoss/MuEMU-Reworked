#include "stdafx.h"
#include "UIBase.h"
#include "Offset.h"
#include "MuClientAPI.h"

// Implementación base
UIBase::UIBase() {
	for (int i = 0; i < MAX_UI_OBJECTS; ++i) {
		Objects[i].OnShow = false;
		Objects[i].OnClick = false;
		Objects[i].EventTick = 0;
	}
}

void UIBase::BindObject(short id, DWORD ModelID, float Width, float Height, float X, float Y) {
	Objects[id].ModelID = ModelID;
	Objects[id].Width = Width;
	Objects[id].Height = Height;
	Objects[id].X = X;
	Objects[id].Y = Y;
	Objects[id].MaxX = X + Width;
	Objects[id].MaxY = Y + Height;
	Objects[id].OnShow = false;
	Objects[id].OnClick = false;
	Objects[id].Attribute = 0;
}

void UIBase::DrawGUI(short id, float x, float y) {
	if (Objects[id].X == -1 || Objects[id].Y == -1) {
		Objects[id].X = x;
		Objects[id].Y = y;
		Objects[id].MaxX = x + Objects[id].Width;
		Objects[id].MaxY = y + Objects[id].Height;
	}
	MuClientAPIExtended::DrawGUI(Objects[id].ModelID, x, y, Objects[id].Width, Objects[id].Height);
}

void UIBase::DrawButton(short id, float x, float y, float scaleX, float scaleY) {
	if (Objects[id].X == -1 || Objects[id].Y == -1) {
		Objects[id].X = x;
		Objects[id].Y = y;
		Objects[id].MaxX = x + Objects[id].Width;
		Objects[id].MaxY = y + Objects[id].Height;
	}
	MuClientAPIExtended::DrawButton(Objects[id].ModelID, x, y, Objects[id].Width, Objects[id].Height, scaleX, scaleY);
}

void UIBase::DrawColoredGUI(short id, float x, float y, DWORD color) {
	if (Objects[id].X == -1 || Objects[id].Y == -1) {
		Objects[id].X = x;
		Objects[id].Y = y;
		Objects[id].MaxX = x + Objects[id].Width;
		Objects[id].MaxY = y + Objects[id].Height;
	}
	MuClientAPIExtended::DrawColorButton(Objects[id].ModelID, x, y, Objects[id].Width, Objects[id].Height, 0, 0, color);
}

void UIBase::ResetDrawIMG(short id) {
	Objects[id].X = -1;
	Objects[id].Y = -1;
	Objects[id].MaxX = -1;
	Objects[id].MaxY = -1;
}

float UIBase::DrawRepeatGUI(short id, float x, float y, int count) {
	float startY = y;
	for (int i = 0; i < count; ++i) {
		MuClientAPIExtended::DrawGUI(Objects[id].ModelID, x, startY, Objects[id].Width, Objects[id].Height);
		startY += Objects[id].Height;
	}
	return startY;
}

//bool UIBase::IsWorkZone(short id) {
//	if ((gObjUser.m_CursorX < Objects[id].X || gObjUser.m_CursorX > Objects[id].MaxX) ||
//		(gObjUser.m_CursorY < Objects[id].Y || gObjUser.m_CursorY > Objects[id].MaxY)) {
//		return false;
//	}
//	return true;
//}

float UIBase::GetResizeX(short id) {
	if (MuClientAPIExtended::WinWidth() == 800)
		return Objects[id].X + 16.0f;
	else if (MuClientAPIExtended::WinWidth() != 1024)
		return Objects[id].X - 16.0f;
	return Objects[id].X;
}

