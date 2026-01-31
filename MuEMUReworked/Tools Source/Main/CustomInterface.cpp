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
#include "Offset.h"
#include "PrintPlayer.h"
#include "Reconnect.h"
#include "User.h"

// Variables externas de Reconnect
extern DWORD ReconnectStatus;
extern DWORD ReconnectProgress;
extern DWORD ReconnectCurTime;
extern DWORD ReconnectMaxTime;
extern DWORD ReconnectCurWait;
extern DWORD ReconnectMaxWait;

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

	initialized = true;
	return initialized;
}

int __fastcall CustomInterface::DrawInterface(void* this_ptr)
{
	// Llamar funcion original primero (como hace ReconnectMainProc)
	int result = reinterpret_cast<int(__thiscall*)(void*)>(0x0080F8E0)(this_ptr);

	gObjUser.Refresh();

	// Procesar interfaz custom
	if (gMuClientApi.PlayerState() == static_cast<int>(GameState::GameProcess)) {
		if (ReconnectStatus == RECONNECT_STATUS_RECONNECT)
		{
			ReconnectDrawInterface();

			if ((GetTickCount() - ReconnectMaxTime) > ReconnectMaxWait)
			{
				ReconnectSetInfo(RECONNECT_STATUS_DISCONNECT, RECONNECT_PROGRESS_NONE, 0, 0);
				((void(__thiscall*)(void*))0x0063A180)((void*)0x08793750);
			}
			else if ((GetTickCount() - ReconnectCurTime) >= ReconnectCurWait)
			{
				switch (ReconnectProgress)
				{
				case RECONNECT_PROGRESS_NONE:
					ReconnecGameServerLoad();
					break;
				case RECONNECT_PROGRESS_CONNECTED:
					ReconnecGameServerAuth();
					break;
				}
				ReconnectCurTime = GetTickCount();
			}
		}

		gUIBase.CheckAndReport();

		setWindowText();

		if (gUIBase.NotAllWindowsOpen() == false) {
			gCustomPing.StartPing();
			gCustomPing.ShowPing();
		}
	}

	return result;
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