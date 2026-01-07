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
	gEventMenu.Initialize();

	// Cargar nombres de eventos desde MainInfo
	gCustomEventTime.Load(gProtect.m_MainInfo.CustomEventInfo);

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
		// Renderizar menu de eventos custom
		gEventMenu.Render();

		// Renderizar panel de tiempos de eventos (CustomEventTime)
		gCustomEventTime.DrawEventTimePanelWindow();

		// Tecla 'H' para abrir/cerrar panel de eventos (solo si EnableEventTimeButton está activo)
		static bool keyWasPressed = false;
		bool keyIsPressed = (GetAsyncKeyState('H') & 0x8000) != 0;

		if (keyIsPressed && !keyWasPressed && gProtect.m_MainInfo.EnableEventTimeButton)
		{
			gCustomEventTime.OpenWindow();
		}
		keyWasPressed = keyIsPressed;

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
	char text[500];
	sprintf_s(text, sizeof(text), "|| Server: %s || Name: || Level: || Resets: ||", gProtect.m_MainInfo.WindowName);
	SetWindowText(gMuClientApi.GameWindow(), text);
}

void CustomInterface::Cleanup()
{
	std::cout << "Limpiando CustomInterface...\n";
	initialized = false;
}