#include "stdafx.h"
#include "WingInvisible.h"
#include "Offset.h"
#include "Util.h"
#include "TMemory.h"
#include "Import.h"
#include "Defines.h"

#if(VANTHANH_LAMMOWING == 1)

DWORD	WingsSetInvisibleEffect_Pointer;
DWORD	WingsSetInvisibleEffect_Buff;


Naked(WingsSetInvisibleEffect) // -> 12 -> 005EC31D
{
	_asm
	{
		mov WingsSetInvisibleEffect_Buff, esi
			// ----
			mov ecx, dword ptr ss : [ebp + 8]
			mov esi, dword ptr ds : [ecx + 0x30]
			mov WingsSetInvisibleEffect_Pointer, esi
			// ----
			mov esi, WingsSetInvisibleEffect_Buff
	}
	// ----
	if (WingsSetInvisibleEffect_Pointer == 0x1EA5
		//|| WingsSetInvisibleEffect_Pointer == ITEM2(12, 185)
		//|| WingsSetInvisibleEffect_Pointer == ITEM2(12, 186)
		//|| WingsSetInvisibleEffect_Pointer == ITEM2(12, 203)
		//|| WingsSetInvisibleEffect_Pointer == ITEM2(12, 204)
		|| WingsSetInvisibleEffect_Pointer == ITEM2(12, 161))
	{
		_asm
		{
			mov WingsSetInvisibleEffect_Buff, 0x0060B37A
				jmp WingsSetInvisibleEffect_Buff
		}
	}
	else
	{
		_asm
		{
			mov WingsSetInvisibleEffect_Buff, 0x0060B41D
				jmp WingsSetInvisibleEffect_Buff
		}
	}
}

void WingInvisible()
{
	SetRange((LPVOID)0x0060B36A, 12, ASM::NOP);
	SetOp((LPVOID)0x0060B36A, WingsSetInvisibleEffect, ASM::JMP);
}

#endif