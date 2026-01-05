#include "stdafx.h"
#include "UIBase.h"
#include "Offset.h"
#include "MuClientAPI.h"
#include "MuConstants.h"

UIBase gUIBase;

// Implementación base
UIBase::UIBase() {
	for (int i = 0; i < MAX_UI_OBJECTS; ++i) {
		Objects[i].OnShow = false;
		Objects[i].OnClick = false;
		Objects[i].EventTick = 0;
	}
}

bool UIBase::CheckWindow(int WindowID)
{
	return gMuClientApi.CheckWindow(WindowID);
}

int UIBase::CloseWindow(int WindowID)
{
	return gMuClientApi.CloseWindow(WindowID);
}
int UIBase::OpenWindow(int WindowID)
{
	return gMuClientApi.OpenWindow(WindowID);
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

void UIBase::DrawIMG(short id, float PosX, float PosY, float ScaleX, float ScaleY) {
	if (Objects[id].X == -1 || Objects[id].Y == -1)
	{
		Objects[id].X = PosX;
		Objects[id].Y = PosY;
		Objects[id].MaxX = PosX + Objects[id].Width;
		Objects[id].MaxY = PosY + Objects[id].Height;
	}

	gMuClientApi.DrawImage(Objects[id].ModelID, PosX, PosY, Objects[id].Width, Objects[id].Height, 0, 0, ScaleX, ScaleY, 1, 1, 0);
}

int UIBase::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff) - 1;
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	int LineCount = 0;

	char* Line = strtok(Buff, "\n");

	while (Line != NULL)
	{
		gMuClientApi.DrawColorText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}

	return PosY;
}

void UIBase::DrawGUI(short id, float x, float y) {
	if (Objects[id].X == -1 || Objects[id].Y == -1) {
		Objects[id].X = x;
		Objects[id].Y = y;
		Objects[id].MaxX = x + Objects[id].Width;
		Objects[id].MaxY = y + Objects[id].Height;
	}
	gMuClientApi.RenderImage(Objects[id].ModelID, x, y, Objects[id].Width, Objects[id].Height);
}

void UIBase::DrawButton(short id, float x, float y, float scaleX, float scaleY) {
	if (Objects[id].X == -1 || Objects[id].Y == -1) {
		Objects[id].X = x;
		Objects[id].Y = y;
		Objects[id].MaxX = x + Objects[id].Width;
		Objects[id].MaxY = y + Objects[id].Height;
	}
	gMuClientApi.DrawButton(Objects[id].ModelID, x, y, Objects[id].Width, Objects[id].Height, scaleX, scaleY);
}

void UIBase::DrawColoredGUI(short id, float x, float y, DWORD color) {
	if (Objects[id].X == -1 || Objects[id].Y == -1) {
		Objects[id].X = x;
		Objects[id].Y = y;
		Objects[id].MaxX = x + Objects[id].Width;
		Objects[id].MaxY = y + Objects[id].Height;
	}
	gMuClientApi.DrawColorButton(Objects[id].ModelID, x, y, Objects[id].Width, Objects[id].Height, 0, 0, color);
}

void UIBase::ResetDrawIMG(short id) {
	if (Objects[id].X != -1 || Objects[id].Y != -1)
	{
		Objects[id].X = -1;
		Objects[id].Y = -1;
		Objects[id].MaxX = -1;
		Objects[id].MaxY = -1;
	}
}

float UIBase::DrawRepeatGUI(short id, float x, float y, int count) {
	float startY = y;
	for (int i = 0; i < count; ++i) {
		gMuClientApi.RenderImage(Objects[id].ModelID, x, startY, Objects[id].Width, Objects[id].Height);
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
	if (gMuClientApi.WinWidth() == 800)
		return Objects[id].X + 16.0f;
	else if (gMuClientApi.WinWidth() != 1024)
		return Objects[id].X - 16.0f;
	return Objects[id].X;
}

void UIBase::CheckAndReport() {
	for (int id = 1; id <= 79; ++id) {
		if (gUIBase.CheckWindow(id)) {
			if (lastReportedWindowID != id) {
				lastReportedWindowID = id;
				std::cout << "Ventana abierta: " << GetWindowName(id) << " (ID: " << id << ")" << std::endl;
			}
			return; // Solo mostrar mensaje para la primera ventana abierta encontrada
		}
	}
	// Si llegamos aquí, no hay ventanas abiertas, reiniciamos la cache para permitir futuros mensajes
	lastReportedWindowID = 0;
}

bool UIBase::NotAllWindowsOpen() {
	bool _return = false;
	const int Windows[] = { 3,4,7,8,9,10,12,13,14,15,16,21,22,36 };
	for (int v : Windows) {
		if (gUIBase.CheckWindow(v)) {
			_return = true;
			break;
		}
	}
	return _return;
}

std::string UIBase::GetWindowName(int id) {
	// Mapea algunos nombres claves, puedes completar con todos del enum
	switch (id) {
	case 1: return "FriendList";
	case 2: return "MoveList";
	case 3: return "Party";
	case 4: return "Quest";
	case 5: return "NPC_Devin";
	case 6: return "Guild";
	case 7: return "Trade";
	case 8: return "Warehouse";
	case 9: return "ChaosBox";
	case 10: return "CommandWindow";
	case 11: return "PetInfo";
	case 12: return "Shop";
	case 13: return "Inventory";
	case 14: return "Store";
	case 15: return "OtherStore";
	case 16: return "Character";
	case 19: return "DevilSquare";
	case 20: return "BloodCastle";
	case 21: return "CreateGuild";
	case 22: return "GuardNPC";
	case 23: return "SeniorNPC";
	case 24: return "GuardNPC2";
	case 25: return "CastleGateSwitch";
	case 26: return "CatapultNPC";
	case 29: return "CrywolfGate";
	case 30: return "IllusionTemple";
	case 32: return "HeroList";
	case 33: return "ChatWindow";
	case 34: return "FastMenu";
	case 35: return "Options";
	case 36: return "Help";
	case 39: return "FastDial";
	case 41: return "InGame";
	case 49: return "DuelScore";
	case 57: return "SkillTree";
	case 58: return "GoldenArcher1";
	case 59: return "GoldenArcher2";
	case 60: return "LuckyCoin1";
	case 61: return "LuckyCoin2";
	case 62: return "NPC_Duel";
	case 63: return "NPC_Titus";
	case 65: return "CashShop";
	case 66: return "Lugard";
	case 68: return "QuestList1";
	case 69: return "QuestList2";
	case 70: return "Jerint";
	case 72: return "FullMap";
	case 73: return "NPC_Dialog";
	case 74: return "GensInfo";
	case 75: return "NPC_Julia";
	case 76: return "NPC_ChaosMix";
	case 77: return "ExpandInventory";
	case 78: return "ExpandWarehouse";
	case 79: return "MuHelper";
	default: return "UnknownWindow";
	}
}

