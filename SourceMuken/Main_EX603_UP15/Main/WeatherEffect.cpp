#include "stdafx.h"
#include "BuffIcon.h"
#include "Interface.h"
#include "Defines.h"
#include <process.h>
#include "Offset.h"
#include "Interface.h"
#include <time.h>
#include "User.h"
#include "Util.h"
#include "TMemory.h"
#include "WeatherEffect.h"

__declspec(naked) void FixEffects()
{
static DWORD JmpBack = 0x0062F6CA;

	_asm
	{
		Cmp Dword Ptr Ds:[0x00E61E18], 0;
		Je EXIT;
		Cmp Dword Ptr Ds:[0x00E61E18], 3;
		Je EXIT;
		Push Dword Ptr[0x00D3D5E4];
		Jmp JmpBack;
	EXIT:
		Push Dword Ptr[0x00D3D5D4];
		Jmp JmpBack;
	}
}
void FixEffectCitys()
{
	SetCompleteHook(0xE9, 0x0062F6C5, &FixEffects);
}


