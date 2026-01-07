#include "stdafx.h"
#include "CustomInterface.h"
#include "MuClientAPI.h"
#include "MuConstants.h"
#include "UIBase.h"
#include <iostream>
#include "CustomPing.h"
#include <thread>
#include "Util.h"
#include "Protect.h"
#include "MemoryPatcher.h"
#include "EventMenu.h"
#include "CustomEventTime.h"
#include "CustomMenu.h"
#include "Offset.h"
#include "PrintPlayer.h"

CustomInterface gCustomInterface;

CustomInterface::CustomInterface() : initialized(false) {}

CustomInterface::~CustomInterface()
{
	if (initialized)
		Cleanup();
}

bool CustomInterface::Initialize()
{
	SetCompleteHook(ASM::CALL, 0x0080F7FE, &DrawInterface);

	// Cargar nombres de eventos desde MainInfo
	gCustomEventTime.Load(gProtect.m_MainInfo.CustomEventInfo);

	// Inicializar menu custom
	gCustomMenu.Load();

	initialized = true;
	return initialized;
}

int __fastcall CustomInterface::DrawInterface(void* this_ptr)
{
	if (gMuClientApi.PlayerState() == static_cast<int>(GameState::GameProcess)) {
		gUIBase.CheckAndReport();

		setWindowText();

		if (gUIBase.NotAllWindowsOpen() == false) {
			gCustomPing.StartPing();
			gCustomPing.ShowPing();
		}

		// Renderizar menu custom con botones
		gCustomMenu.Render();

		// Renderizar panel de tiempos de eventos (CustomEventTime)
		gCustomEventTime.DrawEventTimePanelWindow();

		// Procesar clicks del mouse para el panel de eventos
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			gCustomEventTime.EventEventTimeWindow_Close(WM_LBUTTONDOWN);
			gCustomEventTime.EventNext(WM_LBUTTONDOWN);
			gCustomEventTime.EventPrev(WM_LBUTTONDOWN);
		}
	}

	return reinterpret_cast<int(__thiscall*)(void*)>(0x0080F8E0)(this_ptr);
}

void CustomInterface::setWindowText()
{
	// Obtener puntero a la estructura del personaje
	DWORD charStruct = *(DWORD*)(MAIN_CHARACTER_STRUCT);
	if (charStruct == 0)
	{
		return;
	}

	// Obtener nombre del personaje (offset 0x00, max 10 chars)
	char playerName[11] = { 0 };
	memcpy(playerName, (void*)(charStruct + 0x00), 10);

	// Obtener nivel del personaje (offset 0x0E, WORD)
	WORD playerLevel = *(WORD*)(charStruct + 0x0E);

	// Obtener resets (variable global de PrintPlayer)
	DWORD playerResets = ViewReset;

	char text[500];
	sprintf_s(text, sizeof(text), "|| Server: %s || Name: %s || Level: %d || Resets: %d ||",
		gProtect.m_MainInfo.WindowName,
		playerName,
		playerLevel,
		playerResets);
	SetWindowText(gMuClientApi.GameWindow(), text);
}

void CustomInterface::Cleanup()
{
	std::cout << "Limpiando CustomInterface...\n";
	initialized = false;
}