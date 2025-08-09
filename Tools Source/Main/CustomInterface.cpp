#include "stdafx.h"
#include "CustomInterface.h"
#include "MuClientAPI.h"
#include <iostream>
#include "CustomPing.h"
#include <thread>
#include "Util.h"

CustomInterface gCustomInterface;

CustomInterface::CustomInterface() : initialized(false) {}

CustomInterface::~CustomInterface()
{
    if (initialized)
        Cleanup();
}

bool CustomInterface::Initialize()
{
    SetCompleteHook(0xE8, 0x0080F7FE, &RunHook);

    initialized = true;
    return initialized;
}

int __fastcall CustomInterface::RunHook(void* this_ptr)
{
    // Aquí tu lógica
    if (gMuClientApi.PlayerState() == 5) {
        gCustomPing.StartPing();
        gCustomPing.ShowPing();
    }

    // Llamada directa a la función original (sin pasar por el hook)
    return reinterpret_cast<int(__thiscall*)(void*)>(0x0080F8E0)(this_ptr);
}

void CustomInterface::Cleanup()
{
    std::cout << "Limpiando CustomInterface...\n";
    initialized = false;
}
