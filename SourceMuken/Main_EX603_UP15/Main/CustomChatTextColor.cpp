#include "stdafx.h"
#include "CustomChatTextColor.h"
#include "TMemory.h"
#include "Util.h"
#include "Offset.h"
#include "Object.h"
#include "WindowsStruct.h"

CChatTextColor gCChatTextColor;

CChatTextColor::CChatTextColor()
{
}

CChatTextColor::~CChatTextColor()
{
}


void SetColorChat(int ChatType)
{
	if (ChatType == 1)
	{
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x96u);
		pSetTextColor(pTextThis(), 0xCDu, 0xDCu, 0xEFu, 0xFFu);
	}
	else if (ChatType == 2)
	{
		pSetBackgroundTextColor(pTextThis(), 0xFFu, 0xC8u, 0x32u, 0x96u);
		pSetTextColor(pTextThis(), 0, 0, 0, 0xFFu);
	}
	else if (ChatType == 3)
	{
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x96u);
		pSetTextColor(pTextThis(), 0x64u, 0x96u, 0xFFu, 0xFFu);
	}
	else if (ChatType == 4)
	{
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x96u);
		pSetTextColor(pTextThis(), 0xFFu, 0x1Eu, 0, 0xFFu);
	}
	else if (ChatType == 5) //-- Party
	{
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x96u);
		pSetTextColor(pTextThis(), 0x99u, 0xCCu, 0xFFu, 0xFFu);
		pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	}
	else if (ChatType == 6) //-- Guild
	{
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x96u);
		pSetTextColor(pTextThis(), 0xFFu, 0xCCu, 0x99u, 0xFFu);
		pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	}
	else if (ChatType == 7) //-- Guild Alianza
	{
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x96u);
		pSetTextColor(pTextThis(), 0xE6u, 0xE6u, 0, 0xFFu);
		pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	}
	else if (ChatType == 8) //-- Chat Game Master
	{
		pSetBackgroundTextColor(pTextThis(), 0x1Eu, 0x1Eu, 0x1Eu, 0xC8u);
		pSetTextColor(pTextThis(), 0xFAu, 0xC8u, 0x32u, 0xFFu);
		pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	}
	else if (ChatType == 9) //-- Chat Gens
	{
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x96u);
		pSetTextColor(pTextThis(), 0x99, 0xCCu, 0, 0xFFu);
		pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	}
}

__declspec (naked) void ChatTextColor()
{
	static DWORD main1_Addr = 0x00788F29;
	static DWORD main2_Addr = 0x00788F25;
	static DWORD main1_Call = 0x0078C050;
	static DWORD main_This;

	_asm
	{
		MOV ECX, DWORD PTR SS : [EBP - 0x2C]
			CALL main1_Call
			MOV main_This, EAX
	}

	if (main_This == 1 || main_This == 2
		|| main_This == 3 || main_This == 4
		|| main_This == 5 || main_This == 6
		|| main_This == 7 || main_This == 8
		|| main_This == 9)
	{
		SetColorChat(main_This);

		_asm
		{
			JMP[main1_Addr]
		}
	}
	else
	{
		_asm
		{
			JMP[main2_Addr]
		}
	}
}

void CChatTextColor::Load()
{
	SetCompleteHook(0xE9, 0x00788C59, &ChatTextColor); //-- Text
}