#include "ChatPosition.h"
#include "Util.h"
#include "CChatEx.h"
#include "stdafx.h"



__declspec(naked) void ChatWindowPosition() 
{
	static DWORD m_ReturnOriginalChat = 0x0085A42C;

	_asm {
		PUSH 0x17E; //Position X
		PUSH 0xB3;   //Position Y
		JMP[m_ReturnOriginalChat];
	}
}

void ChatCenter()
{
	SetCompleteHook(0xE9, 0x0085A425, &ChatWindowPosition);
}