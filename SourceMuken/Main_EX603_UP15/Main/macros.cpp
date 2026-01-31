#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include "VirtualMachine.h"
#include "macros.h"

using namespace std;

class Test
{
public:
	static void ValidateDataStream(CallContext callContext);
};

VirtualMachine* vm;
void PrintNumber(CallContext callContext);
void SleepAndClear(CallContext callContext);
void CheckForDebugger(CallContext callContext);
void ProtectMemory(CallContext callContext);

// Protection shit
int GetProcAddr(char* dll, char* name);
__declspec(noinline) HMODULE WINAPI LoadLibraryWrapper(LPCWSTR lpLibFilename);
void GetProcAsm();
__declspec(noinline) void Encrypt(char* dst, int maxSize);
//LONG WINAPI UnhandledExcepFilter(PEXCEPTION_POINTERS pExcepPointers);
bool HideThread(HANDLE hThread);
inline bool CheckOutputDebugString(LPCTSTR String);
bool IsDbgPresentPrefixCheck();
inline bool DebugObjectCheck();
bool MemoryBreakpointDebuggerCheck();
int CheckHardwareBreakpoints();
inline bool CheckProcessDebugFlags();
inline bool CanOpenCsrss();
bool CheckForCCBreakpointXor55(void* pMemory, size_t SizeToCheck);
void Myfunction_Trap_Debugger();
void DebugSelf();
inline void ErasePEHeaderFromMemory();
inline bool Int2DCheck();

int globals[] = { (int)PrintNumber, (int)SleepAndClear, (int)ProtectMemory };
int globals1[] = { 0, (int)CheckForDebugger };
int globals2[] = { 1337, (int)Test::ValidateDataStream };
int* _globals[] = { globals, globals1, globals2 };

#define JUNK_CODE_ONE        \
	__asm{push eax}            \
	__asm{xor eax, eax}        \
	__asm{setpo al}            \
	__asm{push edx}            \
	__asm{xor edx, eax}        \
	__asm{sal edx, 2}        \
	__asm{xchg eax, edx}    \
	__asm{pop edx}            \
	__asm{or eax, ecx}        \
	__asm{pop eax}

#define JUNK_CODE_TWO \
	__asm{push eax} \
	__asm{xor eax, eax} \
	__asm{mov eax, 12} \
	__asm{pop eax}

#define THE_VALUE 1337

#ifdef OBFUSCATE
int data[] = {
	// OPCODE	// HASH		SIZE	STORED	OFFSET	GLOBALS	PARAMETER
	-0x2, 0x1337, 0, 0, 0, 1, 0,					// LABEL 0 = Store label in slot 0 (we use globals 1 here)
	-0x4, 0x1337, 0, 0, 0, 2, 0, THE_VALUE,	// STORE 1337 GLOBALS2[0] = Store 1337 in globals2 at slot 0
	-0x7, 0x1337, 0, 0, 0, 2, 0,					// LOAD GLOBALS2[0] = Load variable from globals 2 slot 0
	-0x6, 0x1337, 0, 0, 0, 0,							// PUSH = Push loaded variable onto stack
	-0x1, 0x55, 0x1, 0, 0, 1, 1,					// CALL GLOBALS1[1]		(CheckForDebugger)
	-0x8, 0x1337, 0, 0, 0, 0, 10,					// INT3 (we pass a parameter to break the offset after being executed)
	-0x1, 0x55, 0x1, 0, 0, 2, 1,					// CALL GLOBALS2[1]			(ValidateDataStream)
	/*CHANGED*/-0x6, 0x1337, 0x6, 0, 0, 0, 0,					// CALLS 0 = Call 0 from globals0 using stack (PrintNumber)
	-0x1, 0x55, 0x1, 0, 0, 0, 1, 10,			// CALL 1 10 = Call second function with 10 as param (we use globals 0 here) (SleepAndClear)
	-0x1, 0x55, 0x1, 0, 0, 0, 2,					// CALL globals0[2] = ProtectMemory
	/*GLOBALS CHANGED*/		-0x3, 0x1337, 0, 0, 0, 2, 0,					// JMP 0 = Jump to label 0 (we use globals 1 here)


	-0xDEAD, 0xDEAD, 0xDEAD, 0xDEAD, 0xDEAD, 0xDEAD	// END
};
#elif !OBFUSCATE
int data[] = {
	// OPCODE	// HASH		SIZE	STORED	OFFSET	GLOBALS	PARAMETER
	-0x2, 0x1337, 0, 0, 0, 1, 0,					// LABEL 0 = Store label in slot 0 (we use globals 1 here)
	-0x4, 0x1337, 0, 0, 0, 2, 0, 1337,		// STORE 1337 GLOBALS2[0] = Store 1337 in globals2 at slot 0
	//-0x1,		0x1337,		0,		0,		0,		0,		0,		1337,		// CALL 0 1337 = Call first function with 1337 as param (we use globals 0 here)
	-0x7, 0x1337, 0, 0, 0, 2, 0,					// LOAD GLOBALS2[0] = Load variable from globals 2 slot 0
	-0x6, 0x1337, 0, 0, 0, 0,							// PUSH = Push loaded variable onto stack
	-0x1, 0x482, 0x8, 0, 0, 1, 1,					// CALL GLOBALS1[1]		(CheckForDebugger)
	-0x8, 0x1337, 0, 0, 0, 0, 10,					// INT3 (we pass a parameter to break the offset after being executed)
	-0x1, 0x482, 0x8, 0, 0, 2, 1,					// CALL GLOBALS2[1]		(ValidateDataStream)
	-0x5, 0x1337, 0, 0, 0, 0, 0,					// CALLS 0 = Call 0 from globals0 using stack (PrintNumber)
	-0x1, 0x482, 0x8, 0, 0, 0, 1, 10,			// CALL 1 10 = Call second function with 10 as param (we use globals 0 here) (SleepAndClear)
	-0x1, 0x482, 0x8, 0, 0, 0, 2,					// CALL globals0[2] = ProtectMemory
	-0x3, 0x1337, 0, 0, 0, 1, 0,					// JMP 0 = Jump to label 0 (we use globals 1 here)


	-0xDEAD, 0xDEAD, 0xDEAD, 0xDEAD, 0xDEAD, 0xDEAD	// END
};

#endif

int main()
{
	FindWindowA("", NULL);

	// Force load DLL
	FindWindowA("", NULL);

	// Create VM
	vm = new VirtualMachine();
	vm->Initialize((void*)data, sizeof(data));

	for (int i = 0; i < 3; i++)
	{
		vm->AddGlobals(_globals[i]);
	}

	//_globals[2][0] = 1337;

	while (true)
	{
		if (!vm->Run())
		{
			break;
		}
	}

	vm->Shutdown();
	delete vm;
	vm = NULL;
}

void PrintNumber(CallContext callContext)
{
	cout << callContext.arguments[1];

#ifdef OBFUSCATE
	vm->AdjustInstructionCode(-0x1);
#endif

	// Adjust (two arguments)
	vm->AdjustDataOffset(0);
}

void SleepAndClear(CallContext callContext)
{
	Sleep(callContext.arguments[1]);
	system("cls");

	// Adjust (two arguments)
	vm->AdjustDataOffset(8);
}

void Test::ValidateDataStream(CallContext callContext)
{
	// Undone at the end
	vm->AdjustCallTarget(-1);

	// Perform anti debugging check
#ifdef OBFUSCATE
	_asm
	{
		MOV		ebx, DWORD PTR FS : [18h]
			ADD		ebx, 13h // === Useless; add 10h to TEB
			MOV ebx, DWORD PTR DS : [ebx + 1Dh] // === PEB; would be MOV EAX, DWORD PTR DS:[EAX+30] if we hadn't already added 10
			MOVZX ebx, BYTE PTR DS : [ebx + 2]
			test	ebx, ebx
			jz		NoDebugger
	}
	return;
#endif

NoDebugger:

	// Hash is different when obfuscated data is used. We subtract the hash of the data
#ifdef OBFUSCATE
	vm->AdjustDataOffset(-34778 - THE_VALUE);
	vm->AdjustCallTarget(0x5);
#elif !OBFUSCATE
	vm->AdjustDataOffset(-40413);
#endif

	JUNK_CODE_ONE
#ifdef OBFUSCATE
		HideThread(NULL);
#endif
	int* data = (int*)vm->GetDataStream();

	// Hash
	int hash = 0;
	for (int i = 0; i < 80; i++)
	{
		hash += data[i];
	}

	// We add the hash of the data back. If data has been changed, offset will be wrong
	vm->AdjustDataOffset(hash + 4);

	// If obfuscated, this is needed in order to turn the next instruction in the data into a valid one
#ifdef OBFUSCATE
	vm->AdjustInstructionCode(0x1);
#endif

	// If no differnce, 1 will be added. If there is a difference, 0 will be added
	int difference = _globals[2][0] == THE_VALUE;
	vm->AdjustCallTarget(difference);
}

void CheckForDebugger(CallContext callContext)
{
	// Skip own argument
	vm->AdjustDataOffset(4);

	char ollyDbg[] = "DGGROIL";

	char className[] = "\\beod|"; // "Window";
	char cheatEngine60Name[] = "Hcnj+Nelben+=%;"; ////"Cheat Engine 6.0";
	char cheatEngine61Name[] = "Hcnj+Nelben+=%:"; ////"Cheat Engine 6.1";
	char cheatEngine62Name[] = "Hcnj+Nelben+=%9"; ////"Cheat Engine 6.2";
	char cheatEngine63Name[] = "Hcnj+Nelben+=%8"; ////"Cheat Engine 6.3";
	char cheatEngine71Name[] = "Hcnj+Nelben+=%"; ////"Cheat Engine 7.1";
	Encrypt(className, sizeof(className));
	Encrypt(cheatEngine60Name, sizeof(cheatEngine60Name));
	Encrypt(cheatEngine61Name, sizeof(cheatEngine61Name));
	Encrypt(cheatEngine62Name, sizeof(cheatEngine62Name));
	Encrypt(cheatEngine63Name, sizeof(cheatEngine63Name));
	Encrypt(cheatEngine71Name, sizeof(cheatEngine71Name));

	JUNK_CODE_ONE

		char user32Dll[] = "^xny89%ogg";
	char FindWindowA[] = "Mbeo\\beod|J";
	char GetWindowTextA[] = "Ln\\beod|_nsJ";
	Encrypt(user32Dll, sizeof(user32Dll));
	Encrypt(FindWindowA, sizeof(FindWindowA));
	Encrypt(GetWindowTextA, sizeof(GetWindowTextA));

	HWND(WINAPI *address)(LPCSTR, LPCSTR) = (HWND(WINAPI*)(LPCSTR, LPCSTR))GetProcAddr(user32Dll, FindWindowA);
	HWND cheatEngineWindow = address(className, NULL);
	if (cheatEngineWindow != NULL)
	{
		char windowText[128] = {};
		int (WINAPI *address2)(HWND, LPSTR, int) = (int (WINAPI*)(HWND, LPSTR, int))GetProcAddr(user32Dll, GetWindowTextA);
		address2(cheatEngineWindow, windowText, sizeof(windowText));
		if (strcmp(windowText, cheatEngine60Name) == 0 ||
			strcmp(windowText, cheatEngine61Name) == 0 ||
			strcmp(windowText, cheatEngine62Name) == 0 ||
			strcmp(windowText, cheatEngine63Name) == 0 ||
			strcmp(windowText, cheatEngine71Name) == 0)
		{
			return;
		}
	}

	Encrypt(ollyDbg, sizeof(ollyDbg));

	if (address(ollyDbg, NULL) != NULL)
	{
		return;
	}

	// Skip half of instruction INT 3 (20 bytes)
	vm->AdjustDataOffset(_globals[2][0] - (THE_VALUE - 20));
#ifdef OBFUSCATE
	if (DebugObjectCheck())
	{
		vm->AdjustInstructionCode(0x3);
	}
#endif

	JUNK_CODE_ONE

		// Skip other half of instruction INT 3 (8 bytes)
		vm->AdjustDataOffset(8 + IsDbgPresentPrefixCheck());
}

void ProtectMemory(CallContext callContext)
{
	typedef LPTOP_LEVEL_EXCEPTION_FILTER(WINAPI *pSetUnhandledExceptionFilter)(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter);

	char kernel32[] = "`nyeng89%ogg";
	char SetUnhandledExceptionFilter[] = "Xn^ecjeognoNshn{bdeMbgny";
	Encrypt(kernel32, sizeof(kernel32));
	Encrypt(SetUnhandledExceptionFilter, sizeof(SetUnhandledExceptionFilter));

#ifdef OBFUSCATE
	// Changed back in hide thread
	vm->AdjustCallTarget(0x5);

	// Since data is changed, we have to adjust the globals here
	vm->AdjustGlobalsOffset(-0x1);
	//	((pSetUnhandledExceptionFilter)GetProcAddr(kernel32, SetUnhandledExceptionFilter))(UnhandledExcepFilter);
	__asm{xor eax, eax}
	__asm{div eax}
#endif

	JUNK_CODE_TWO
#ifdef OBFUSCATE
		HideThread(NULL);
#endif
	JUNK_CODE_ONE

		// Skip own argument
		vm->AdjustDataOffset(4);
}
/*
LONG WINAPI UnhandledExcepFilter(PEXCEPTION_POINTERS pExcepPointers)
{
typedef LPTOP_LEVEL_EXCEPTION_FILTER(WINAPI *pSetUnhandledExceptionFilter)(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter);

char kernel32[] = "`nyeng89%ogg";
char SetUnhandledExceptionFilter[] = "Xn^ecjeognoNshn{bdeMbgny";
Encrypt(kernel32, sizeof(kernel32));
Encrypt(SetUnhandledExceptionFilter, sizeof(SetUnhandledExceptionFilter));

JUNK_CODE_TWO

// Restore old UnhandledExceptionFilter
((pSetUnhandledExceptionFilter)GetProcAddr(kernel32, SetUnhandledExceptionFilter))((LPTOP_LEVEL_EXCEPTION_FILTER)pExcepPointers->ContextRecord->Eax);


// Skip the exception code
pExcepPointers->ContextRecord->Eip += 2;

return EXCEPTION_CONTINUE_EXECUTION;
}
*/
// HideThread will attempt to use
// NtSetInformationThread to hide a thread
// from the debugger, Passing NULL for
// hThread will cause the function to hide the thread
// the function is running in. Also, the function returns
// false on failure and true on success
__forceinline bool HideThread(HANDLE hThread)
{
	typedef NTSTATUS(NTAPI *pNtSetInformationThread)(HANDLE, UINT, PVOID, ULONG);
	NTSTATUS Status;

	typedef HANDLE(WINAPI *pGetCurrentThread)(void);

	char ntdll[] = "eogg%ogg";
	char NtSetInformationThread[] = "EXnBemdyfjbde_cynjo";
	Encrypt(ntdll, sizeof(ntdll));
	Encrypt(NtSetInformationThread, sizeof(NtSetInformationThread));

	char kernel32[] = "`nyeng89%ogg";
	char GetCurrentThread[] = "LnH~yyne_cynjo";
	Encrypt(kernel32, sizeof(kernel32));
	Encrypt(GetCurrentThread, sizeof(GetCurrentThread));

	JUNK_CODE_TWO

		// Get NtSetInformationThread
		pNtSetInformationThread NtSIT = (pNtSetInformationThread)GetProcAddr(ntdll, NtSetInformationThread);
	pGetCurrentThread getCurrentThread = (pGetCurrentThread)GetProcAddr(kernel32, GetCurrentThread);

	JUNK_CODE_TWO

		// Set the thread info
	if (hThread == NULL)
	{
		JUNK_CODE_ONE
			vm->AdjustCallTarget(-0x5);
		Status = NtSIT(getCurrentThread(), 0x11, 0, 0); // HideThreadFromDebugger
	}
	else
	{
		vm->AdjustCallTarget(-0x5);
		Status = NtSIT(hThread, 0x11, 0, 0);
	}


	if (Status != 0x00000000)
		return false;
	else
		return true;
}

// CheckOutputDebugString checks whether or 
// OutputDebugString causes an error to occur
// and if the error does occur then we know 
// there's no debugger, otherwise if there IS
// a debugger no error will occur
inline bool CheckOutputDebugString(LPCTSTR String)
{
	return false;
	char kernel32[] = "`nyeng89%ogg";
	char OutputDebugStringW[] = "D~{~Oni~lXybel\\";
	char GetLastError[] = "LnGjxNyydy";
	Encrypt(kernel32, sizeof(kernel32));
	Encrypt(OutputDebugStringW, sizeof(OutputDebugStringW));
	Encrypt(GetLastError, sizeof(GetLastError));

	typedef void (WINAPI *pOutputDebugString)(PCTSTR lpOutputString);
	(((pOutputDebugString)GetProcAddr(kernel32, OutputDebugStringW))(String));

	JUNK_CODE_TWO

		typedef DWORD(WINAPI *pGetLastError)(void);

	if ((((pGetLastError)GetProcAddr(kernel32, GetLastError))()) == 0)
		return true;
	else
		return false;
}

// This function uses NtQuerySystemInformation
// to try to retrieve a handle to the current
// process's debug object handle. If the function
// is successful it'll return true which means we're
// being debugged or it'll return false if it fails
// or the process isn't being debugged
__forceinline bool DebugObjectCheck()
{
	// Much easier in ASM but C/C++ looks so much better
	typedef NTSTATUS(WINAPI *pNtQueryInformationProcess)
		(HANDLE, UINT, PVOID, ULONG, PULONG);

	typedef HANDLE(WINAPI *pGetCurrentProcess)(void);

	HANDLE hDebugObject = NULL;
	NTSTATUS Status;

	char ntdll[] = "eogg%ogg";
	char NtQueryInformationProcess[] = "EZ~nyrBemdyfjbde[ydhnxx";
	char GetCurrentProcess[] = "LnH~yyne[ydhnxx";
	char kernel32[] = "`nyeng89%ogg";
	Encrypt(ntdll, sizeof(ntdll));
	Encrypt(NtQueryInformationProcess, sizeof(NtQueryInformationProcess));
	Encrypt(GetCurrentProcess, sizeof(GetCurrentProcess));
	Encrypt(kernel32, sizeof(kernel32));

	// Get NtQueryInformationProcess
	pNtQueryInformationProcess NtQIP = (pNtQueryInformationProcess)GetProcAddr(ntdll, NtQueryInformationProcess);
	pGetCurrentProcess GetCurrProc = (pGetCurrentProcess)GetProcAddr(kernel32, GetCurrentProcess);

	Status = NtQIP(GetCurrProc(),
		0x1e, // ProcessDebugObjectHandle
		&hDebugObject, 4, NULL);

	if (Status != 0x00000000)
		return false;

	if (hDebugObject)
		return true;
	else
		return false;
}

// The IsDbgPresentPrefixCheck works in at least two debuggers
// OllyDBG and VS 2008, by utilizing the way the debuggers handle
// prefixes we can determine their presence. Specifically if this code
// is ran under a debugger it will simply be stepped over;
// however, if there is no debugger SEH will fire :D
__forceinline bool IsDbgPresentPrefixCheck()
{
#ifdef OBFUSCATE
	__try
	{
		__asm pushad
		__asm popad
		__asm __emit 0xF3 // 0xF3 0x64 disassembles as PREFIX REP:
		__asm __emit 0x64
		__asm __emit 0xF1 // One byte INT 1
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return false;
	}

	return true;
#elif !OBFSUCATE
	return false;
#endif
}

int __cdecl GetProcAddr(char* dll, char* name)
{
	int address = 0;
	_asm
	{
		push dll
			push name
			call GetProcAsm
			mov	address, eax
	}

	return address;
}

__declspec(noinline) HMODULE WINAPI LoadLibraryWrapper(LPCWSTR lpLibFilename)
{
	return 0;
	//return LoadLibraryW(lpLibFilename);
}

__declspec(naked) __forceinline void GetProcAsm()
{
	_asm
	{
		add    esp, -2 * 4 - 4 * 4; room for 4 registers and 2 local variables
			mov[esp + 2 * 4 + 0 * 4], edi; saving registers
			mov[esp + 2 * 4 + 1 * 4], ebp;
		mov[esp + 2 * 4 + 2 * 4], esi;
		mov[esp + 2 * 4 + 3 * 4], ebx;
		mov    dword ptr[esp + 1 * 4], 0; [esp + 1 * 4]->clear flag for forwarded proc
		GetStart : ;
		mov    edx, [esp + 2 * 4 + 4 * 4 + 2 * 4]; edx->lp Dll name
			mov    ebp, 20h; ebp->BaseDllName address(Unicode)
			cmp    byte ptr[edx + 1], 3Ah; "c:\...." Is it full path or just dll name ?
			jne    a;
		mov    ebp, 18h; ebp->FullDllName(Unicode)
		a:;
		; Get module base address...............;
		mov    eax, fs:[30h]; PEB base in eax
			cmp    dword ptr[esp + 1 * 4], -1; If it is forwarded esi->ntdll.dll
			mov    eax, [eax + 0Ch]; eax->PEB_LDR_DATA
			mov    edi, edx; edi->lp Dll name
			mov    esi, [eax + 1Ch]; esi-> 1st entry in InitOrderModuleList
			je     b; else
			mov    esi, [esi]; esi->Kernel32.dll
		b : ;
		mov    eax, [esi + ebp]; eax->BaseDllName or FullDllName(Unicode)
			mov    ebx, esi; ebx->the 1st LDR_MODULE in the chain
			; Comparing strings ....................;
		;
	FindNextCharw:;
		mov    ch, [eax]; eax->BaseDllName or FullDllName(Unicode)
			add    eax, 2;
		cmp    ch, 5Ah;
		ja     c;
		cmp    ch, 41h;
		jl     c;
		or     ch, 20h;
	c:;
		mov    cl, [edx]; edx->lp dll name string "." or zero ended
			add    edx, 1;
		cmp    cl, 5Ah;
		ja     d;
		cmp    cl, 41h;
		jl     d;
		or     cl, 20h;
	d:;
		cmp    cl, ch;
		jne    Next_LDRw;
		test   ch, ch;
		je     e;
		cmp    ch, 2Eh; "."
			jne    FindNextCharw;
		cmp    dword ptr[esp + 1 * 4], -1; flag for forwarded proc->If it is forwarded
			jne    FindNextCharw;           copy until ".", else until zero
		e : ;
		mov    ebx, [esi + 8]; ebx->Base Dll Name address
			je     GetNextApi;
		;
		; Next forward LDR_MODULE ..............;
	Next_LDRw:;
		mov    esi, [esi]; we go forwards
			mov    edx, edi; edx->lp Dll name
			mov    eax, [esi + ebp]; eax->BaseDllName or FullDllName(Unicode) address
			test   eax, eax
			jz	  Next_LDRw
			cmp    ebx, esi; If current module = 1st module->Dll is Not Loaded
			jne    FindNextCharw;
		;
		; The module is not loaded in memory and;
		; we will try LoadLibrary to load it....;
		jmp End_NotFound;  Disabled for now
			cmp    dword ptr[esp + 1 * 4], -1; If it is forwarded
			je     Forwarded_Dll; copy dll name in the stack and call oadLibrary
			xor    ebx, ebx; ebx = 0
			push		edx
			call LoadLibraryWrapper; call API
			add    ebx, eax; ebx->BaseDllName address or zero
			je     End_NotFound; No such dll->exit with ebx = 0->error
			; End of Get module base address........;
		;
	GetNextApi:;
		mov    edx, [ebx + 3Ch]; edx->beginning of PE header
			mov    esi, ebx; ebp->current dll base address
			mov    edi, [ebx + edx + 78h]; edi->RVA of ExportDirectory -> 78h
			mov    ecx, [ebx + edx + 7Ch]; ecx->RVA of ExportDirectorySize ->7Ch
			add    esi, [ebx + edi + 20h]; esi->AddressOfNames ->20h
			add    edi, ebx; ebx->current dll base address
			movd   MM5, edi; MM5->edi->ExportDirectory
			mov    ebp, [esp + 1 * 4 + (4 * 4 + 2 * 4)]; ebp->proc name address or ordinal value
			add    ecx, edi; ecx = ExportDirectory address + ExportDirectorySize
			mov    eax, [edi + 18h]; eax = num of API Names->nMax NumberOfNames->18h
			test   ebp, 0ffff0000h; is it proc name address or ordinal value ?
			mov[esp + 0 * 4], ecx; [esp + 0 * 4] = ExportDirectory address + ExportDirectorySize
			je     GetByOrdinal; GetProcAddress by Ordinal
			;
		; Binary search ........................; GetProcAddress by Name
			movd   MM7, esp; save the stack here
			movzx  ecx, byte ptr[ebp]; ebp->proc name address
			lea    edi, [esi + 4];      cl-> 1st character of the proc name
			mov    esp, ebx; esp->current dll base address
			neg    edi; set carry flag
			movd   MM6, edi; MM6 = -(esi + 4]
		Bin_Search:;
			; cmova  esi, edx; see Note 1
				sbb    edi, edi; edi->mask - 1 or 0
				xor    esi, edx; mix esi and edx
				and    esi, edi; esi = esi or esi = 0
				mov    ebx, esp; ebx->current dll base address
				xor    esi, edx; esi = esi or esi = edx
				shr    eax, 1;
			je     End_ZeroIndex;
		IndexIsZero:;
			add    ebx, [esi + 4 * eax];
			lea    edx, [esi + 4 * eax + 4];
			cmp    cl, [ebx]; ebx->API Names Table
				jne    Bin_Search;
			; End Binary search ....................;
			;
			; Compare next bytes of two strings.....;
			lea    edi, [ebp + 1];
		f:;
			mov    ch, [edi]; comparing bytes
				add    ebx, 1;
			cmp    ch, [ebx]; ebx->API Names Table
				jne    Bin_Search;
			add    edi, 1;
			test   ch, ch;
			jne    f;
			;
			; Extract the index from EDX to get proc address
				movd   esi, MM5; esi->ExportDirectory
				movd   eax, MM6; eax-> - (AddressOfNames + 4)
				mov    edi, [esi + 24h]; edi->AddressOfNameOrdinals ->24h
				mov    ecx, esp; ecx->current dll base address
				add    ecx, [esi + 1Ch]; ecx->AddressOfFunctions->1Ch
				add    eax, edx; edx->[esi + 4 * eax + 4]
				shr    eax, 1; eax->index->eax * 2 for word table
				add    edi, esp; esp->current dll base address
				movzx  eax, word ptr[eax + edi]; eax = Ordinal number for this index
				mov    ebx, esp; ebx->current dll base address
				add    ebx, [ecx + eax * 4]; ebx->proc address
				movd   esp, MM7; restore the stack
				; .......................................;
		Is_it_Forwarded:; check if proc address is inside export directory
			cmp    esi, ebx; esi->ExportDirectory
			jnl    EndProc;
						cmp    ebx, [esp + 0 * 4]; [esp + 0 * 4] = ExportDirectory address + ExportDirectorySize
							jl     Forwarded;
						; .......................................;
					EndProc:;
						mov    edi, [esp + 2 * 4 + 0 * 4]; restoring registers
							mov    eax, ebx; eax->proc address  or zero
							mov    ebp, [esp + 2 * 4 + 1 * 4];
						mov    esi, [esp + 2 * 4 + 2 * 4];
						mov    ebx, [esp + 2 * 4 + 3 * 4];
						add    esp, 2 * 4 + 4 * 4;
						ret    2 * 4;
						; .......................................;
					End_ZeroIndex:;
						jc     IndexIsZero; if it is 1st time zero->return,
							movd   esp, MM7; else (2nd time zero)->restore the stack
						End_NotFound : ; and exit
									   xor    ebx, ebx; ebx = 0->flag not found
									   je     EndProc;
						; .......................................;
					GetByOrdinal:;
						cmp    ebp, [esi + 14h]
							jnl    End_NotFound; esi->ExportDirectory
							sub    ebp, [esi + 10h]
							mov    eax, ebx; eax->current dll base address
							add    eax, [esi + 1Ch]
							add    ebx, [eax + ebp * 4]; ebx->proc address
							jne    Is_it_Forwarded;
						; .......................................;
					Forwarded_Dll:;
						; Copy dll name in the stack............;
						xor    eax, eax; eax->index = 0
							sub    esp, 2048; room for dll name in the stack
							xor    ebx, ebx; ebx = 0
						g:;
						mov    cl, [edx + eax]; edx->lp Dll name->source
							add    eax, 1;
						mov[esp + eax - 1], cl; esp->lp target buffer
							test   cl, cl;
						je     h;
						cmp    cl, 2Eh; "."
							jne    g;
						mov[esp + eax - 1], ebx; ebx = 0
						h:;
						push esp
							call LoadLibraryWrapper; call API
							add    esp, 2048; restore the stack
							add    ebx, eax; ebx->BaseDllName address or zero
							jne    GetNextApi;
						je     End_NotFound; No such dll->exit with ebx = 0->error
							; .......................................;
					Forwarded:;
						mov    eax, ebx; eax->proc address
							; Call the proc "recursively"...........;
					i:;
						cmp    byte ptr[eax], 2Eh; looking for "."
							lea    eax, [eax + 1];
						jne    i;
						cmp    byte ptr[eax], 23h; Is it forwarded by ordinal ? Ex : "ntdll.#12"
							je     j;
					GetProc:;
						mov    dword ptr[esp + 1 * 4], -1; set flag->it is forwarded
							mov[esp + 1 * 4 + (4 * 4 + 2 * 4)], eax; eax->offset of proc name or ordinal value
							mov[esp + 2 * 4 + (4 * 4 + 2 * 4)], ebx; ebx->lp Dll name
							jmp    GetStart; start it again with new proc name and Dll name and flag
						j : ;
						; A2Dw..................................;
						lea    edx, [eax + 1];
						xor    eax, eax;
					k:;
						movzx  ecx, byte ptr[edx];
						add    edx, 1;
						test   ecx, ecx;
						je     GetProc;
						lea    eax, [eax + 4 * eax];
						lea    eax, [ecx + 2 * eax - 30h]; eax = (eax * 10 + ecx - 30h)
							jne    k;
						; End A2Dw..............................;
	}
}

__declspec(noinline) void Encrypt(char* dst, int maxSize)
{
	for (int i = 0; i < maxSize; i++)
	{
		char chr = dst[i];
		if (chr == '\0')
		{
			break;
		}

		chr = chr ^ 11;
		dst[i] = chr;
	}
}
//====================================
bool MemoryBreakpointDebuggerCheck()	//ok
{
	unsigned char *pMem = NULL;
	SYSTEM_INFO sysinfo = { 0 };
	DWORD OldProtect = 0;
	void *pAllocation = NULL; // kh?i t?o 1 vùng nh? 

	GetSystemInfo(&sysinfo); // Allocate memory 

	pAllocation = VirtualAlloc(NULL, sysinfo.dwPageSize,
		MEM_COMMIT | MEM_RESERVE,
		PAGE_EXECUTE_READWRITE);
	//c?p phát vùng nh? cho pAllocation     
	if (pAllocation == NULL)
		return false;

	pMem = (unsigned char*)pAllocation;
	*pMem = 0xc3;
	//vi?t l?i opcode cho vùng nh? này,m?c ?ích là ? b??c detect ta s? PUSH ??a ch? nhãn MemBpBeingDebugged        
	//vì th? khi th?c hi?n l?nh RET thì thanh ghi con trò l?nh IP s? tr? ch? th? ti?p theo v? nhãn này

	if (VirtualProtect(pAllocation, sysinfo.dwPageSize,
		PAGE_EXECUTE_READWRITE | PAGE_GUARD,
		&OldProtect) == 0)
	{
		return false;
	}
	// t?o ra thu?c tính PAGE_GUARD cho vùng nh? ?ã c?p phát
	__try
	{
		__asm
		{
			mov eax, pAllocation
				push MemBpBeingDebugged
				//l?u address c?a MemBpBeingDebugged,n?u là debugger,sau khi truy c?p vào vùng nh? c?a pAllocation 
				//nó s? return l?i t?i ??a ch? này
				jmp eax // X?y ra exception n?u nh? không ch?y trong debug,và s? t?o breakpoint trên vùng nh? c?a
				// pAllocation  n?u nh? ch?y trên Ollydebug
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		// Exception này sinh ra n?u nh? ta truy c?p trái phép vào vùng nh? PAGE_GUARD
		//vi?c này x?y ra khi ta ch?y bình th??ng,no in debugger
		VirtualFree(pAllocation, NULL, MEM_RELEASE);
		return false;
	}

	__asm{MemBpBeingDebugged:}
	VirtualFree(pAllocation, NULL, MEM_RELEASE);
	return true;
}

bool CheckForCCBreakpoint(void* pMemory, size_t SizeToCheck)
{
	unsigned char *pTmp = (unsigned char*)pMemory;
	for (size_t i = 0; i < SizeToCheck; i++)
	{
		if (pTmp[i] == 0xCC)
			return true;
	}
	return false;
}

int CheckHardwareBreakpoints()	//OK
{
	unsigned int NumBps = 0;
	// This structure is key to the function and is the 
	// medium for detection and removal
	CONTEXT ctx;
	ZeroMemory(&ctx, sizeof(CONTEXT));

	// The CONTEXT structure is an in/out parameter therefore we have
	// to set the flags so Get/SetThreadContext knows what to set or get.
	ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS;

	// Get a handle to our thread
	HANDLE hThread = GetCurrentThread();

	// Get the registers
	if (GetThreadContext(hThread, &ctx) == 0)
		return -1;

	// Now we can check for hardware breakpoints, its not 
	// necessary to check Dr6 and Dr7, however feel free to
	if (ctx.Dr0 != 0)
		++NumBps;
	if (ctx.Dr1 != 0)
		++NumBps;
	if (ctx.Dr2 != 0)
		++NumBps;
	if (ctx.Dr3 != 0)
		++NumBps;

	return NumBps;
}

inline bool CheckProcessDebugFlags()
{
	// Much easier in ASM but C/C++ looks so much better
	typedef NTSTATUS(WINAPI *pNtQueryInformationProcess)
		(HANDLE, UINT, PVOID, ULONG, PULONG);
	DWORD NoDebugInherit = 0;
	NTSTATUS Status;

	// Get NtQueryInformationProcess
	pNtQueryInformationProcess NtQIP = (pNtQueryInformationProcess)
		GetProcAddress(GetModuleHandle(TEXT("ntdll.dll")),
		"NtQueryInformationProcess");

	Status = NtQIP(GetCurrentProcess(),
		0x1f, //offset c?a Debug flag
		&NoDebugInherit, 4, NULL);
	/*

	Status = NtQIP(GetCurrentProcess(),
	0x1e, // offset Debug Object Handle
	&hDebugObject, 4, NULL);
	*/
	if (Status != 0x00000000)
		return false;

	if (NoDebugInherit == FALSE)
		return true;
	else
		return false;
}


int  GetCsrssProcessId();

inline bool CanOpenCsrss()
{
	HANDLE Csrss = 0;
	// If we're being debugged and the process has
	// SeDebugPrivileges privileges then this call
	// will be successful, note that this only works
	// with PROCESS_ALL_ACCESS.
	Csrss = OpenProcess(PROCESS_ALL_ACCESS,
		FALSE, GetCsrssProcessId());

	if (Csrss != NULL)
	{
		CloseHandle(Csrss);
		return true;
	}
	else
		return false;
}


bool CheckForCCBreakpointXor55(void* pMemory, size_t SizeToCheck)
{
	unsigned char *pTmp = (unsigned char*)pMemory;
	unsigned char tmpchar = 0;

	for (size_t i = 0; i < SizeToCheck; i++)
	{
		tmpchar = pTmp[i];
		if (0x99 == (tmpchar ^ 0x55)) // 0xCC xor 0x55 = 0x99
			return true;
	}
	return false;
}

void Myfunction_Trap_Debugger()
{
	int a = 1;
	int b = 2;
	int c = a + b;
	printf("%d", a + b + c);
}
void Myfunction_Adresss_Next() { };
int main1()
{
	size_t nSizeScan = (size_t)(Myfunction_Adresss_Next)-(size_t)(Myfunction_Trap_Debugger);
	if (CheckForCCBreakpointXor55(&Myfunction_Trap_Debugger, nSizeScan))
	{
		printf("detecting INT 3");
		system("PAUSE");
		return 1;
	}
	printf("NO INT 3");
	return 0;
}

#include <windows.h>
#include <stdio.h>
#include <iostream>


int main2(void)
{
	typedef unsigned long(__stdcall *pfnNtQueryInformationProcess)(IN  HANDLE, IN  unsigned int, OUT PVOID, IN ULONG, OUT PULONG);

	pfnNtQueryInformationProcess NtQueryInfoProcess = NULL;
	unsigned long Ret;
	unsigned long IsRemotePresent = 0;

	HMODULE hNtDll = LoadLibrary(TEXT("ntdll.dll"));
	NtQueryInfoProcess = (pfnNtQueryInformationProcess)
		GetProcAddress(hNtDll, "NtQueryInformationProcess");

	if (NtQueryInfoProcess == NULL)
	{
		// Handle however it fits your needs but as before,
		// if this is missing there are some SERIOUS issues with the OS
	}

	Ret = NtQueryInfoProcess(GetCurrentProcess(), 0x1f, &IsRemotePresent, 4, NULL);
	if (Ret == 0x00000000 && IsRemotePresent != 1)
	{
		// Debugger is present
		MessageBox(NULL, "Please close your debugging application and restart the program", "Debugger Found!", 0);

		ExitProcess(0);

	}
	return 0;
}
//============Test
// Debug self is a function that uses CreateProcess
// to create an identical copy of the current process
// and debugs it
void DebugSelf()
{
	HANDLE hProcess = NULL;
	DEBUG_EVENT de;
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
	ZeroMemory(&si, sizeof(STARTUPINFO));
	ZeroMemory(&de, sizeof(DEBUG_EVENT));

	GetStartupInfo(&si);

	// Create the copy of ourself
	CreateProcess(NULL, GetCommandLine(), NULL, NULL, FALSE,
		DEBUG_PROCESS, NULL, NULL, &si, &pi);

	// Continue execution
	ContinueDebugEvent(pi.dwProcessId, pi.dwThreadId, DBG_CONTINUE);

	// Wait for an event
	WaitForDebugEvent(&de, INFINITE);
}

//==============


typedef struct _OBJECT_TYPE_INFORMATION {

	UNICODE_STRING TypeName;

	ULONG TotalNumberOfHandles;

	ULONG TotalNumberOfObjects;

}OBJECT_TYPE_INFORMATION, *POBJECT_TYPE_INFORMATION;



// ObjectListCheck uses NtQueryObject to check the environments

// list of objects and more specifically for the number of



// debug objects. This function can cause an exception (although rarely)

// so either surround it in a try catch or __try __except block

// but that shouldn't happen unless one tinkers with the function

typedef struct _OBJECT_ALL_INFORMATION {
	ULONG NumberOfObjects;
	OBJECT_TYPE_INFORMATION ObjectTypeInformation[1];
}OBJECT_ALL_INFORMATION, *POBJECT_ALL_INFORMATION;
inline bool ObjectListCheck()

{

	typedef NTSTATUS(NTAPI *pNtQueryObject)

		(HANDLE, UINT, PVOID, ULONG, PULONG);



	POBJECT_ALL_INFORMATION pObjectAllInfo = NULL;

	void *pMemory = NULL;

	NTSTATUS Status;

	unsigned long Size = 0;



	// Get NtQueryObject

	pNtQueryObject NtQO = (pNtQueryObject)GetProcAddress(

		GetModuleHandle(TEXT("ntdll.dll")),

		"NtQueryObject");



	// Get the size of the list

	Status = NtQO(NULL, 3, //ObjectAllTypesInformation

		&Size, 4, &Size);



	// Allocate room for the list

	pMemory = VirtualAlloc(NULL, Size, MEM_RESERVE | MEM_COMMIT,

		PAGE_READWRITE);



	if (pMemory == NULL)

		return false;



	// Now we can actually retrieve the list

	Status = NtQO((HANDLE)-1, 3, pMemory, Size, NULL);



	// Status != STATUS_SUCCESS

	if (Status != 0x00000000)

	{

		VirtualFree(pMemory, 0, MEM_RELEASE);

		return false;

	}



	// We have the information we need

	pObjectAllInfo = (POBJECT_ALL_INFORMATION)pMemory;



	unsigned char *pObjInfoLocation =

		(unsigned char*)pObjectAllInfo->ObjectTypeInformation;



	ULONG NumObjects = pObjectAllInfo->NumberOfObjects;



	for (UINT i = 0; i < NumObjects; i++)

	{



		POBJECT_TYPE_INFORMATION pObjectTypeInfo =

			(POBJECT_TYPE_INFORMATION)pObjInfoLocation;



		// The debug object will always be present

		if (wcscmp(L"DebugObject", pObjectTypeInfo->TypeName.Buffer) == 0)



		{

			// Are there any objects?

			if (pObjectTypeInfo->TotalNumberOfObjects > 0)

			{

				VirtualFree(pMemory, 0, MEM_RELEASE);

				return true;

			}

			else

			{

				VirtualFree(pMemory, 0, MEM_RELEASE);

				return false;

			}

		}



		// Get the address of the current entries

		// string so we can find the end

		pObjInfoLocation =

			(unsigned char*)pObjectTypeInfo->TypeName.Buffer;



		// Add the size

		pObjInfoLocation +=

			pObjectTypeInfo->TypeName.Length;



		// Skip the trailing null and alignment bytes

		ULONG tmp = ((ULONG)pObjInfoLocation) & -4;



		// Not pretty but it works

		pObjInfoLocation = ((unsigned char*)tmp) +

			sizeof(unsigned long);

	}



	VirtualFree(pMemory, 0, MEM_RELEASE);

	return true;

}

// This function will erase the current images

// PE header from memory preventing a successful image

// if dumped

inline void ErasePEHeaderFromMemory()

{

	DWORD OldProtect = 0;



	// Get base address of module

	char *pBaseAddr = (char*)GetModuleHandle(NULL);



	// Change memory protection

	VirtualProtect(pBaseAddr, 4096, // Assume x86 page size

		PAGE_READWRITE, &OldProtect);



	// Erase the header

	ZeroMemory(pBaseAddr, 4096);

}

// The Int2DCheck function will check to see if a debugger

// is attached to the current process. It does this by setting up

// SEH and using the Int 2D instruction which will only cause an

// exception if there is no debugger. Also when used in OllyDBG

// it will skip a byte in the disassembly and will create

// some havoc.

inline bool Int2DCheck()

{

	__try

	{

		__asm

		{

			int 0x2d

				xor eax, eax

				add eax, 2

		}

	}

	__except (EXCEPTION_EXECUTE_HANDLER)

	{

		return false;

	}



	return true;

}

inline void PushPopSS()

{



	__asm

	{

		push ss

			pop ss

			mov eax, 9 // This line executes but is stepped over

			xor edx, edx // This is where the debugger will step to

	}

}

#include "AccCtrl.h"
#include "Aclapi.h"

BOOL EL_DenyProcessAccess(void)
{
	BYTE    abyBuffer[0x200];
	PACL    pACL;
	SID_IDENTIFIER_AUTHORITY stIdentifierAuthority = SECURITY_WORLD_SID_AUTHORITY;
	PSID pSid = NULL;
	BOOL bRet = FALSE;
	DWORD dwSize = 0;
	HANDLE hToken = NULL;
	HANDLE hProcess = ::GetCurrentProcess();
	PTOKEN_USER pUserInfo = NULL;

	if (::AllocateAndInitializeSid(&stIdentifierAuthority, 1, SECURITY_WORLD_RID, 0, 0, 0, 0, 0, 0, 0, &pSid) == FALSE)
		goto Cleanup;
	if (::OpenProcessToken(hProcess, TOKEN_QUERY, &hToken) == FALSE)
		goto Cleanup;
	::GetTokenInformation(hToken, TokenUser, NULL, NULL, &dwSize);
	if (dwSize > 1024)
		goto Cleanup;
	pUserInfo = (PTOKEN_USER) ::GlobalAlloc(GPTR, dwSize);
	if (pUserInfo == NULL)
		goto Cleanup;
	if (::GetTokenInformation(hToken, TokenUser, pUserInfo, dwSize, &dwSize) == FALSE)
		goto Cleanup;
	pACL = (PACL)&abyBuffer;
	if (::InitializeAcl(pACL, 0x200, ACL_REVISION) == FALSE)
		goto Cleanup;
	// Deny except PROCESS_TERMINATE and PROCESS_SET_SESSIONID
	if (::AddAccessDeniedAce(pACL, ACL_REVISION, PROCESS_CREATE_PROCESS | PROCESS_DUP_HANDLE | PROCESS_VM_WRITE | PROCESS_VM_READ | PROCESS_VM_OPERATION | PROCESS_CREATE_THREAD, pSid) == FALSE)
		goto Cleanup;
	// Allow SYNCHRONIZE, PROCESS_QUERY_INFORMATION, PROCESS_SET_INFORMATION, PROCESS_SET_QUOTA and PROCESS_TERMINATE
	if (::AddAccessAllowedAce(pACL, ACL_REVISION, SYNCHRONIZE | PROCESS_QUERY_INFORMATION | PROCESS_SET_INFORMATION | PROCESS_SET_QUOTA | PROCESS_TERMINATE, pUserInfo->User.Sid) == FALSE)
		goto Cleanup;
	if (::SetSecurityInfo(hProcess, SE_KERNEL_OBJECT, PROTECTED_DACL_SECURITY_INFORMATION | DACL_SECURITY_INFORMATION, 0, 0, pACL, 0) != ERROR_SUCCESS)
		goto Cleanup;
	bRet = TRUE;
Cleanup:
	if (hToken)
		::CloseHandle(hToken);
	if (pSid)
		::FreeSid(pSid);
	return bRet;
}


#define DETOUR_TRACE(x) printf x

struct _DETOUR_ALIGN
{
	BYTE    obTarget : 3;
	BYTE    obTrampoline : 5;
};

C_ASSERT(sizeof(_DETOUR_ALIGN) == 1);

//////////////////////////////////////////////////////////////////////////////
//
static bool detour_is_imported(PBYTE pbCode, PBYTE pbAddress)
{
	MEMORY_BASIC_INFORMATION mbi;
	VirtualQuery((PVOID)pbCode, &mbi, sizeof(mbi));
	__try {
		PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)mbi.AllocationBase;
		if (pDosHeader->e_magic != IMAGE_DOS_SIGNATURE) {
			return false;
		}

		PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)((PBYTE)pDosHeader +
			pDosHeader->e_lfanew);
		if (pNtHeader->Signature != IMAGE_NT_SIGNATURE) {
			return false;
		}

		if (pbAddress >= ((PBYTE)pDosHeader +
			pNtHeader->OptionalHeader
			.DataDirectory[IMAGE_DIRECTORY_ENTRY_IAT].VirtualAddress) &&
			pbAddress < ((PBYTE)pDosHeader +
			pNtHeader->OptionalHeader
			.DataDirectory[IMAGE_DIRECTORY_ENTRY_IAT].VirtualAddress +
			pNtHeader->OptionalHeader
			.DataDirectory[IMAGE_DIRECTORY_ENTRY_IAT].Size)) {
			return true;
		}
		return false;
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		return false;
	}
}

///////////////////////////////////////////////////////////////////////// X86.
//

struct _DETOUR_TRAMPOLINE
{
	BYTE            rbCode[30];     // target code + jmp to pbRemain
	BYTE            cbCode;         // size of moved target code.
	BYTE            cbCodeBreak;    // padding to make debugging easier.
	BYTE            rbRestore[22];  // original target code.
	BYTE            cbRestore;      // size of original target code.
	BYTE            cbRestoreBreak; // padding to make debugging easier.
	_DETOUR_ALIGN   rAlign[8];      // instruction alignment array.
	PBYTE           pbRemain;       // first instruction after moved code. [free list]
	PBYTE           pbDetour;       // first instruction of detour function.
};

C_ASSERT(sizeof(_DETOUR_TRAMPOLINE) == 72);

enum {
	SIZE_OF_JMP = 5
};

inline PBYTE detour_gen_jmp_immediate(PBYTE pbCode, PBYTE pbJmpVal)
{
	PBYTE pbJmpSrc = pbCode + 5;
	*pbCode++ = 0xE9;   // jmp +imm32
	*((INT32*&)pbCode)++ = (INT32)(pbJmpVal - pbJmpSrc);
	return pbCode;
}

inline PBYTE detour_gen_jmp_indirect(PBYTE pbCode, PBYTE *ppbJmpVal)
{
	PBYTE pbJmpSrc = pbCode + 6;
	*pbCode++ = 0xff;   // jmp [+imm32]
	*pbCode++ = 0x25;
	*((INT32*&)pbCode)++ = (INT32)((PBYTE)ppbJmpVal - pbJmpSrc);
	return pbCode;
}

inline PBYTE detour_gen_brk(PBYTE pbCode, PBYTE pbLimit)
{
	while (pbCode < pbLimit) {
		*pbCode++ = 0xcc;   // brk;
	}
	return pbCode;
}

inline PBYTE detour_skip_jmp(PBYTE pbCode, PVOID *ppGlobals)
{
	if (pbCode == NULL) {
		return NULL;
	}
	if (ppGlobals != NULL) {
		*ppGlobals = NULL;
	}

	// First, skip over the import vector if there is one.
	if (pbCode[0] == 0xff && pbCode[1] == 0x25) {   // jmp [imm32]
		// Looks like an import alias jump, then get the code it points to.
		PBYTE pbTarget = *(PBYTE *)&pbCode[2];
		if (detour_is_imported(pbCode, pbTarget)) {
			PBYTE pbNew = *(PBYTE *)pbTarget;
			DETOUR_TRACE(("%p->%p: skipped over import table.\n", pbCode, pbNew));
			pbCode = pbNew;
		}
	}

	// Then, skip over a patch jump
	if (pbCode[0] == 0xeb) {   // jmp +imm8
		PBYTE pbNew = pbCode + 2 + *(CHAR *)&pbCode[1];
		DETOUR_TRACE(("%p->%p: skipped over short jump.\n", pbCode, pbNew));
		pbCode = pbNew;

		// First, skip over the import vector if there is one.
		if (pbCode[0] == 0xff && pbCode[1] == 0x25) {   // jmp [imm32]
			// Looks like an import alias jump, then get the code it points to.
			PBYTE pbTarget = *(PBYTE *)&pbCode[2];
			if (detour_is_imported(pbCode, pbTarget)) {
				PBYTE pbNew = *(PBYTE *)pbTarget;
				DETOUR_TRACE(("%p->%p: skipped over import table.\n", pbCode, pbNew));
				pbCode = pbNew;
			}
		}
		// Finally, skip over a long jump if it is the target of the patch jump.
		else if (pbCode[0] == 0xe9) {   // jmp +imm32
			PBYTE pbNew = pbCode + 5 + *(INT32 *)&pbCode[1];
			DETOUR_TRACE(("%p->%p: skipped over long jump.\n", pbCode, pbNew));
			pbCode = pbNew;
		}
	}
	return pbCode;
}

inline BOOL detour_does_code_end_function(PBYTE pbCode)
{
	if (pbCode[0] == 0xeb ||    // jmp +imm8
		pbCode[0] == 0xe9 ||    // jmp +imm32
		pbCode[0] == 0xe0 ||    // jmp eax
		pbCode[0] == 0xc2 ||    // ret +imm8
		pbCode[0] == 0xc3 ||    // ret
		pbCode[0] == 0xcc) {    // brk
		return TRUE;
	}
	else if (pbCode[0] == 0xff && pbCode[1] == 0x25) {  // jmp [+imm32]
		return TRUE;
	}
	else if ((pbCode[0] == 0x26 ||      // jmp es:
		pbCode[0] == 0x2e ||      // jmp cs:
		pbCode[0] == 0x36 ||      // jmp ss:
		pbCode[0] == 0xe3 ||      // jmp ds:
		pbCode[0] == 0x64 ||      // jmp fs:
		pbCode[0] == 0x65) &&     // jmp gs:
		pbCode[1] == 0xff &&       // jmp [+imm32]
		pbCode[2] == 0x25) {
		return TRUE;
	}
	return FALSE;
}

inline ULONG detour_is_code_filler(PBYTE pbCode)
{
	if (pbCode[0] == 0x90) { // nop
		return 1;
	}
	return 0;
}

//================test hong thi lam lai
#include <stdio.h>
#include <Windows.h>
#include <TlHelp32.h>

__declspec(naked) void AntiAttach() {
	__asm {
		jmp ExitProcess
	}
}

int AntiAttachmain() {
	HANDLE hProcess = GetCurrentProcess();

	HMODULE hMod = GetModuleHandleW(L"ntdll.dll");
	FARPROC func_DbgUiRemoteBreakin = GetProcAddress(hMod, "DbgUiRemoteBreakin");

	WriteProcessMemory(hProcess, func_DbgUiRemoteBreakin, AntiAttach, 6, NULL);

	int a, b;
	scanf("%d %d", &a, &b);

	printf("result : %d\n", a + b);

	system("pause");
	return 0;
}


#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>
#include <TlHelp32.h>

#define MAKEULONGLONG(ldw, hdw) ((ULONGLONG(hdw) << 32) | ((ldw) & 0xFFFFFFFF))
DWORD GetMainThreadId(DWORD pid) {
	THREADENTRY32 th32;
	memset(&th32, 0, sizeof(THREADENTRY32));
	th32.dwSize = sizeof(THREADENTRY32);

	DWORD dwMainThreadID = -1;

	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, NULL);
	if (Thread32First(hSnapshot, &th32)) {
		DWORD64 ullMinCreateTime = 0xFFFFFFFFFFFFFFFF;

		do {
			if (th32.th32OwnerProcessID == pid) {
				HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE, th32.th32ThreadID);

				if (hThread) {
					FILETIME afTimes[4] = { 0 };
					if (GetThreadTimes(hThread, &afTimes[0], &afTimes[1], &afTimes[2], &afTimes[3])) {
						ULONGLONG ullTest = MAKEULONGLONG(afTimes[0].dwLowDateTime, afTimes[0].dwHighDateTime);
						if (ullTest && ullTest < ullMinCreateTime) {
							ullMinCreateTime = ullTest;
							dwMainThreadID = th32.th32ThreadID;
						}
					}
					CloseHandle(hThread);
				}
			}
		} while (Thread32Next(hSnapshot, &th32));
	}

	CloseHandle(hSnapshot);
	return dwMainThreadID;
}


DWORD GetPidByProcessName(WCHAR* name) {
	PROCESSENTRY32W entry;
	memset(&entry, 0, sizeof(entry));
	entry.dwSize = sizeof(PROCESSENTRY32W);

	DWORD pid = -1;
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (Process32FirstW(hSnapShot, &entry)) {
		do {
			if (!wcscmp(name, entry.szExeFile)) {
				pid = entry.th32ProcessID;
				break;
			}
		} while (Process32NextW(hSnapShot, &entry));
	}

	CloseHandle(hSnapShot);
	return pid;
}

int wmain(int argc, WCHAR *argv[]) {
	if (argc < 2) {
		printf("USAGE : exec PROCESSNAME\n");
		return 1;
	}

	DWORD pid = GetPidByProcessName(argv[1]);
	DWORD tid = GetMainThreadId(pid);

	HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE, tid);

	CONTEXT ctx;
	memset(&ctx, 0, sizeof(CONTEXT));
	ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS;

	ctx.Dr0 = 0;
	ctx.Dr1 = 0;
	ctx.Dr2 = 0;
	ctx.Dr3 = 0;
	ctx.Dr7 &= (0xffffffffffffffff ^ (0x1 | 0x4 | 0x10 | 0x40));

	SetThreadContext(hThread, &ctx);
	CloseHandle(hThread);
}

typedef struct {
	LPVOID lpVirtualAddress;
	DWORD dwSizeOfRawData;
} SECTIONINFO, *PSECTIONINFO;

typedef struct {
	DWORD64 dwRealHash;
	SECTIONINFO SectionInfo;
} HASHSET, *PHASHSET;

int GetAllModule(std::vector<LPVOID>& modules) {
	MODULEENTRY32W mEntry;
	memset(&mEntry, 0, sizeof(mEntry));
	mEntry.dwSize = sizeof(MODULEENTRY32);

	DWORD curPid = GetCurrentProcessId();

	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, NULL);
	if (Module32FirstW(hSnapshot, &mEntry)) {
		do {
			modules.emplace_back(mEntry.modBaseAddr);
		} while (Module32NextW(hSnapshot, &mEntry));
	}

	CloseHandle(hSnapshot);

	if (modules.empty()) {
		return -1;
	}

	return 0;
}


DWORD64 HashSection(LPVOID lpSectionAddress, DWORD dwSizeOfRawData) {
	DWORD64 hash = 0;
	BYTE *str = (BYTE *)lpSectionAddress;
	for (int i = 0; i < dwSizeOfRawData; ++i, ++str) {
		if (*str) {
			hash = *str + (hash << 6) + (hash << 16) - hash;
		}
	}

	return hash;
}

bool bTerminateThread = false;

void CheckTextHash(PHASHSET pHashSet) {
	DWORD64 dwRealHash = pHashSet->dwRealHash;
	DWORD dwSizeOfRawData = pHashSet->SectionInfo.dwSizeOfRawData;
	LPVOID lpVirtualAddress = pHashSet->SectionInfo.lpVirtualAddress;

	while (1) {
		Sleep(1000);

		DWORD64 dwCurrentHash = HashSection(lpVirtualAddress, dwSizeOfRawData);
		if (dwRealHash != dwCurrentHash) {
			MessageBoxW(NULL, L"DebugAttached", L"WARN", MB_OK);
			exit(1);
		}

		if (bTerminateThread) {
			return;
		}
	}
}


