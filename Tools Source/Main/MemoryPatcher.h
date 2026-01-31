#pragma once
#include <windows.h>
#include <cstring>

class MemoryPatcher {
public:
    static void CommandLineToArg(char* Command, char*** argv);

    static DWORD WriteMemory(const LPVOID lpAddress, const LPVOID lpBuf, const UINT uSize);
    static DWORD ReadMemory(const LPVOID lpAddress, LPVOID lpBuf, const UINT uSize);

    static DWORD SetByte(const LPVOID dwOffset, const BYTE btValue);
    static DWORD GetByte(const LPVOID dwOffset, BYTE& btValue);

    static DWORD SetWord(const LPVOID dwOffset, const WORD wValue);
    static DWORD GetWord(const LPVOID dwOffset, WORD& wValue);

    static DWORD SetDword(const LPVOID dwOffset, const DWORD dwValue);
    static DWORD GetDword(const LPVOID dwOffset, DWORD& dwValue);

    static DWORD SetFloat(const LPVOID dwOffset, float fValue);
    static DWORD GetFloat(const LPVOID dwOffset, float& fValue);

    static DWORD SetDouble(const LPVOID dwOffset, double dValue);

    static DWORD SetJmp(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress);
    static DWORD SetJg(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress);
    static DWORD SetJa(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress);

    static DWORD SetOp(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress, const BYTE cmd);

    static DWORD SetRange(const LPVOID dwAddress, const USHORT wCount, const BYTE btValue);

    static DWORD SetHook(const LPVOID dwMyFuncOffset, const LPVOID dwJmpOffset, const BYTE cmd);
};

extern MemoryPatcher gMemory;