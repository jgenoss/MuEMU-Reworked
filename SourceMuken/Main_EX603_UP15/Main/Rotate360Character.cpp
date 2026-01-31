#include"stdafx.h"
#include "Offset.h"
#include "Import.h"
#include "Rotate360Character.h"
#include "Util.h"

void RotateCharacter()
{
		if (pCursorX > 108 && pCursorX < 188 && pCursorY > 292 && pCursorY < 413) //Primeiro Slot
		{	
			int v5 = pGetPreviewStruct(pPreviewThis(),0);
			int v8 = v5 + 776;
			*(float *)(v8 + 272) = *(float *)(v8 + 272) - 5.0;
		}
		else
		{
			int v5 = pGetPreviewStruct(pPreviewThis(),0);
			int v8 = v5 + 776;
			*(float *)(v8 + 272) = 90;
		}
		if (pCursorX > 203 && pCursorX < 275 && pCursorY > 280 && pCursorY < 393) //Segundo Slot
		{	
			int v5 = pGetPreviewStruct(pPreviewThis(),1);
			int v8 = v5 + 776;
			*(float *)(v8 + 272) = *(float *)(v8 + 272) - 5.0;
		}
		else
		{
			int v5 = pGetPreviewStruct(pPreviewThis(),1);
			int v8 = v5 + 776;
			*(float *)(v8 + 272) = 75;
		}
		if (pCursorX > 296 && pCursorX < 373 && pCursorY > 270 && pCursorY < 388) //Terceiro Slot
		{	
			int v5 = pGetPreviewStruct(pPreviewThis(),2);
			int v8 = v5 + 776;
			*(float *)(v8 + 272) = *(float *)(v8 + 272) - 5.0;
		}
		else
		{
			int v5 = pGetPreviewStruct(pPreviewThis(),2);
			int v8 = v5 + 776;
			*(float *)(v8 + 272) = 45;
		}
		if (pCursorX > 390 && pCursorX < 457 && pCursorY > 271 && pCursorY < 391) //Quarto Slot
		{	
			int v5 = pGetPreviewStruct(pPreviewThis(),3);
			int v8 = v5 + 776;
			*(float *)(v8 + 272) = *(float *)(v8 + 272) - 5.0;
		}
		else
		{
			int v5 = pGetPreviewStruct(pPreviewThis(),3);
			int v8 = v5 + 776;
			*(float *)(v8 + 272) = 25;
		}
		if (pCursorX > 474 && pCursorX < 547 && pCursorY > 273 && pCursorY < 408) //Quinto Slot
		{	
			int v5 = pGetPreviewStruct(pPreviewThis(),4);
			int v8 = v5 + 776;
			*(float *)(v8 + 272) = *(float *)(v8 + 272) - 5.0;
		}
		else
		{
			int v5 = pGetPreviewStruct(pPreviewThis(),4);
			int v8 = v5 + 776;
			*(float *)(v8 + 272) = 0;
		}
}

__declspec(naked) void SelectCharacterPosition()
{
   RotateCharacter();

	static DWORD Return_Adress = 0x004D84ED;

	_asm
	{
	 PUSH EBP                            
	 MOV EBP,ESP
	 SUB ESP,0x0D8
	 MOV BYTE PTR SS:[EBP-0x1],0x0
	jmp [Return_Adress]
	}
}

void CustomRotateChar()
{
    SetCompleteHook(0xE9, 0x004D84E0, &SelectCharacterPosition);
}