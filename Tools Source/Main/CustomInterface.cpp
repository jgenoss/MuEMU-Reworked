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
    if (gMuClientApi.PlayerState() == static_cast<int>(GameState::GameProcess)) {
        
        gUIBase.CheckAndReport();

        setWindowText();

        if (gUIBase.NotAllWindowsOpen() == false) {
            gCustomPing.StartPing();
            gCustomPing.ShowPing();
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
