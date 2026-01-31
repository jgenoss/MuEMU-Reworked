#include "stdafx.h"
#include "Common.h"
#include "Offset.h"
#include "Util.h"
#include "CustomInterface.h"
#include "MuConstants.h"
#include <thread>

BYTE GensBattleMapCount = 0;
BYTE GensMoveIndexCount = 0;
BYTE GensBattleMap[120];
BYTE GensMoveIndex[120];

int DisablePing;

// Nueva variable para controlar FPS
// NUEVAS VARIABLES PARA GRAPHICS SYSTEM

#define pWinWidth *(GLsizei*)0x0E61E58

void __declspec(naked) FixMU_TITLEPostion()
{
	static DWORD RETURN = 0x004830DB;
	static DWORD CALLFC = 0x00416640;
	static DWORD JUMPER = 0x004830DD;
	static DWORD REJMPR = 0x004830BB;

	if (pWinWidth == 1366 || pWinWidth == 1600 || pWinWidth == 1920)
	{
		_asm
		{
			PUSH 0x3
			PUSH 0x1CF
			PUSH 0x214
			MOV EAX, DWORD PTR SS : [EBP - 0x48]
			MOV ECX, DWORD PTR DS : [EAX + 0x9184]
			ADD ECX, 0x150
			CALL[CALLFC]
			JMP[RETURN]
		}
	}
	else if (pWinWidth == 1440 || pWinWidth == 1680)
	{
		_asm
		{
			PUSH 0x3
			PUSH 0x212
			PUSH 0x214
			MOV EAX, DWORD PTR SS : [EBP - 0x48]
			MOV ECX, DWORD PTR DS : [EAX + 0x9184]
			ADD ECX, 0x150
			CALL[CALLFC]
			JMP[RETURN]
		}
	}
	else if (pWinWidth == 1280)
	{
		_asm { JMP[REJMPR] }
	}
	else
	{
		_asm { JMP[JUMPER] }
	}
}

void InitCommon() // OK
{
	CreateConsole();

	SetCompleteHook(ASM::JMP, 0x0040B154, &LoginTab);

	SetCompleteHook(ASM::CALLI, 0x0064A79A, &CheckMasterLevel); // C1:16

	SetCompleteHook(ASM::CALLI, 0x0064A85F, &CheckMasterLevel); // C1:16

	SetCompleteHook(ASM::CALLI, 0x00656E03, &CheckMasterLevel); // C1:48

	SetCompleteHook(ASM::CALLI, 0x0064AB3D, &CheckMasterLevel); // C1:9C

	SetCompleteHook(ASM::CALLI, 0x0064AC02, &CheckMasterLevel); // C1:9C

	SetCompleteHook(ASM::CALLI, 0x0063DDF2, &CheckMasterLevel); // C1:F3:03

	SetCompleteHook(ASM::CALLI, 0x0063DF89, &CheckMasterLevel); // C1:F3:03

	SetCompleteHook(ASM::CALLI, 0x0063EA4C, &CheckMasterLevel); // C1:F3:04

	SetCompleteHook(ASM::CALLI, 0x0064CA0C, &CheckMasterLevel); // LevelUp

	SetCompleteHook(ASM::CALLI, 0x0077FAF9, &CheckMasterLevel); // Print Level

	SetCompleteHook(ASM::CALLI, 0x0081071B, &CheckMasterLevel); // Experience Bar

	SetCompleteHook(ASM::CALLI, 0x0081079B, &CheckMasterLevel); // Experience Bar

	SetCompleteHook(ASM::CALLI, 0x0047FE31, &CheckGensBattleMap);

	SetCompleteHook(ASM::CALLI, 0x0059890D, &CheckGensBattleMap);

	SetCompleteHook(ASM::CALLI, 0x0059A399, &CheckGensBattleMap);

	SetCompleteHook(ASM::CALLI, 0x0059A93C, &CheckGensBattleMap);

	SetCompleteHook(ASM::CALLI, 0x0059B13B, &CheckGensBattleMap);

	SetCompleteHook(ASM::CALLI, 0x005A4261, &CheckGensBattleMap);

	SetCompleteHook(ASM::CALLI, 0x005A4D52, &CheckGensBattleMap);

	SetCompleteHook(ASM::CALLI, 0x005B6117, &CheckGensBattleMap);

	SetCompleteHook(ASM::CALLI, 0x0065A6CE, &CheckGensBattleMap);

	SetCompleteHook(ASM::CALLI, 0x00727987, &CheckGensBattleMap);

	SetCompleteHook(ASM::CALLI, 0x007861F1, &CheckGensBattleMap);

	SetCompleteHook(ASM::CALLI, 0x007D32FA, &CheckGensBattleMap);

	SetCompleteHook(ASM::CALLI, 0x007D3B0D, &CheckGensBattleMap);

	SetCompleteHook(ASM::JMP, 0x008317BD, &CompareGensMoveIndex);

	SetCompleteHook(ASM::JMP, 0x004D1CF0, 0x004D1DC2); //-- Remoce MuError.DMP

	MemorySet(0x00D20170, 0x90, 0x1B); //-- Remove Creation MuError.log

	SetCompleteHook(ASM::JMP, 0x0082A983, 0x0082A9F3); //-- Fix Send NpcTalk

	//Small correction in the text
	SetDword(0x00796079, (DWORD)"%s - %s");
	SetDword(0x007962E9, (DWORD)"%s - %s");
	SetDword(0x00796559, (DWORD)"%s - %s");
	SetDword(0x007967C9, (DWORD)"%s - %s");
	SetDword(0x00796A39, (DWORD)"%s - %s");

	SetByte(0x007D56D3, static_cast<BYTE>(0x10C));

	//-> Personal Store Name (Buyer) Text Position
	SetByte(0x0084F587, static_cast<BYTE>(0x10D));

	//-> Personal Store Name (Seller) Text Position
	SetByte(0x00841FE1, static_cast<BYTE>(0x10D));

	SetCompleteHook(ASM::JMP, 0x0082A983, 0x0082A9F3);

	SetCompleteHook(ASM::JMP, 0x004830AE, &FixMU_TITLEPostion);

	//Fix Visual Agility MuEMU
	SetByte(0x00649E24 + 3, static_cast<BYTE>(14));

	//Remove Creation MuError

	//Offset Fix RF Skill
	SetCompleteHook(ASM::JMP, 0x0071AE92, 0x00720894); //Fix RF Skill
	SetCompleteHook(ASM::JMP, 0x0071B1A3, 0x00720894); //Fix RF Skill
	SetCompleteHook(ASM::JMP, 0x0095DFBE, 0x0095DFD3); //-- Fix RF

	//Offset fix move skill
	MemorySet(0x005AD691, 0x90, 0x05); //fix move skill
	//Botón de corrección de desplazamiento del guardián de Crywolf (tercera misión)
	MemorySet(0x00792B7F, 0x90, 0x05);	// Fix Button Crywolf Gatekeeper (Third Quest)

	//mini buff icons
	SetFloat(0x00D43220, 10);
	SetFloat(0x00D43224, 14);
	SetByte(0x00777E70, 0x16);

	SetDword(0x0077823A + 1, (DWORD)"Custom\\Interface\\small_newui_statusicon.jpg");
	SetDword(0x0077825A + 1, (DWORD)"Custom\\Interface\\small_newui_statusicon2.jpg");
	SetDword(0x0077827A + 1, (DWORD)"Custom\\Interface\\small_newui_statusicon3.jpg");
}

void CreateConsole()
{
	AllocConsole();
	FILE* fDummy;
	freopen_s(&fDummy, "CONIN$", "r", stdin);
	freopen_s(&fDummy, "CONOUT$", "w", stdout);
	freopen_s(&fDummy, "CONOUT$", "w", stderr);

	SetConsoleTitleA("Consola Debug");
	std::cout.clear();
	std::clog.clear();
	std::cerr.clear();
	std::cin.clear();

	std::cout << "[*] Consola inicializada.\n";
}

BOOL CheckGensBattleMap(int map) // OK
{
	for (int n = 0; n < GensBattleMapCount; n++)
	{
		if (GensBattleMap[n] == map)
		{
			return 1;
		}
	}

	return 0;
}

BOOL CheckGensMoveIndex(int idx) // OK
{
	for (int n = 0; n < GensMoveIndexCount; n++)
	{
		if (GensMoveIndex[n] == idx)
		{
			return 1;
		}
	}

	return 0;
}

__declspec(naked) void LoginTab() // OK
{
	static DWORD LoginTabAddress1 = 0x0040B16F;

	__asm
	{
		Push 0
		Mov Eax, Dword Ptr Ss : [Ebp - 0x38]
		Mov Ecx, Dword Ptr Ds : [Eax + 0x350]
		Mov Edx, Dword Ptr Ss : [Ebp - 0x38]
		Mov Eax, Dword Ptr Ds : [Edx + 0x350]
		Mov Edx, Dword Ptr Ds : [Eax]
		Call Dword Ptr Ds : [Edx + 0x30]
		Mov Eax, Dword Ptr Ss : [Ebp - 0x38]
		Mov Ecx, Dword Ptr Ds : [Eax + 0x354]
		Push Ecx
		Mov Edx, Dword Ptr Ss : [Ebp - 0x38]
		Mov Ecx, Dword Ptr Ds : [Edx + 0x350]
		Mov Eax, Dword Ptr Ss : [Ebp - 0x38]
		Mov Edx, Dword Ptr Ds : [Eax + 0x350]
		Mov Eax, Dword Ptr Ds : [Edx]
		Call Dword Ptr Ds : [Eax + 0x58]
		Mov Ecx, Dword Ptr Ss : [Ebp - 0x38]
		Mov Edx, Dword Ptr Ds : [Ecx + 0x350]
		Push Edx
		Mov Eax, Dword Ptr Ss : [Ebp - 0x38]
		Mov Ecx, Dword Ptr Ds : [Eax + 0x354]
		Mov Edx, Dword Ptr Ss : [Ebp - 0x38]
		Mov Eax, Dword Ptr Ds : [Edx + 0x354]
		Mov Edx, Dword Ptr Ds : [Eax]
		Call Dword Ptr Ds : [Edx + 0x58]
		Jmp[LoginTabAddress1]
	}
}

__declspec(naked) void CheckMasterLevel() // OK
{
	static DWORD CheckMasterLevelAddress1 = 0x005875A0;

	_asm
	{
		Push Ebp
		Mov Ebp, Esp
		Mov Eax, Dword Ptr Ds : [MAIN_CHARACTER_STRUCT]
		Xor Ecx, Ecx
		Mov Cx, Word Ptr Ds : [Eax + 0x0E]
		Cmp Ecx, 0x190
		Je NEXT
		Xor Eax, Eax
		Jmp EXIT
		NEXT :
		Xor Edx, Edx
			Mov Dl, Byte Ptr Ss : [Ebp + 0x08]
			Push Edx
			Call[CheckMasterLevelAddress1]
			Add Esp, 0x04
			EXIT :
			Pop Ebp
			Retn
	}
}

__declspec(naked) void CompareGensMoveIndex() // OK
{
	static DWORD CheckGensMoveIndexAddress1 = 0x0051B090;
	static DWORD CheckGensMoveIndexAddress2 = 0x008317FC;
	static DWORD CheckGensMoveIndexAddress3 = 0x008317EA;

	__asm
	{
		Lea Ecx, Dword Ptr Ss : [Ebp - 0x08]
		Call[CheckGensMoveIndexAddress1]
		Mov Ecx, Dword Ptr Ds : [Eax]
		Mov Edx, Dword Ptr Ds : [Ecx]
		Push Edx
		Call[CheckGensMoveIndex]
		Add Esp, 0x04
		Test Eax, Eax
		Jnz EXIT
		Jmp[CheckGensMoveIndexAddress2]
		EXIT:
		Jmp[CheckGensMoveIndexAddress3]
	}
}