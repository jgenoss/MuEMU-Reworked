#include "stdafx.h"
#include "MemoryPatcher.h"


void MemoryPatcher::CommandLineToArg(char* Command, char*** argv) {
    if (!Command) return;

    bool Quote = false, Content = false;
    size_t CommandLen = strlen(Command);
    int NumCommands = 1;

    for (size_t i = 0; i < CommandLen; i++) {
        if (Command[i] == '"') Quote = !Quote, Content = true;
        else if (Command[i] == ' ' && !Quote && Content) {
            Content = false;
            NumCommands++;
        }
        else Content = true;
    }

    *argv = new char* [NumCommands];
    size_t StrBegin = 0, StrLen = 0, CommandNum = 0;

    for (size_t i = 0; i < CommandLen; i++) {
        if (Command[i] == '"') Quote = !Quote, Content = true;
        else if (Command[i] == ' ') {
            if (!Quote && Content) {
                Content = false;
                StrLen = i - StrBegin;

                if (Command[StrBegin] == '"') { StrBegin++; StrLen--; }
                if (Command[StrBegin + StrLen - 1] == '"') StrLen--;

                char* Argument = new char[StrLen + 1];
                memcpy(Argument, Command + StrBegin, StrLen);
                Argument[StrLen] = '\0';

                (*argv)[CommandNum++] = Argument;
                StrBegin = i + 1;
            }
            else if (!Quote) StrBegin++;
        }
        else Content = true;
    }

    StrLen = CommandLen - StrBegin;
    if (Command[StrBegin] == '"') { StrBegin++; StrLen--; }
    if (Command[StrBegin + StrLen - 1] == '"') StrLen--;

    char* Argument = new char[StrLen + 1];
    memcpy(Argument, Command + StrBegin, StrLen);
    Argument[StrLen] = '\0';

    (*argv)[CommandNum] = Argument;
}

DWORD MemoryPatcher::WriteMemory(const LPVOID lpAddress, const LPVOID lpBuf, const UINT uSize) {
    DWORD dwOldProtect;
    if (!VirtualProtect(lpAddress, uSize, PAGE_EXECUTE_READWRITE, &dwOldProtect))
        return GetLastError();

    memcpy(lpAddress, lpBuf, uSize);

    DWORD dwBytes;
    if (!VirtualProtect(lpAddress, uSize, dwOldProtect, &dwBytes))
        return GetLastError();

    return 0;
}

DWORD MemoryPatcher::ReadMemory(const LPVOID lpAddress, LPVOID lpBuf, const UINT uSize) {
    DWORD dwOldProtect;
    if (!VirtualProtect(lpAddress, uSize, PAGE_EXECUTE_READWRITE, &dwOldProtect))
        return GetLastError();

    memcpy(lpBuf, lpAddress, uSize);

    DWORD dwBytes;
    if (!VirtualProtect(lpAddress, uSize, dwOldProtect, &dwBytes))
        return GetLastError();

    return 0;
}

DWORD MemoryPatcher::SetByte(const LPVOID dwOffset, const BYTE btValue) {
    return WriteMemory(dwOffset, (LPVOID)& btValue, sizeof(BYTE));
}

DWORD MemoryPatcher::GetByte(const LPVOID dwOffset, BYTE& btValue) {
    return ReadMemory(dwOffset, &btValue, sizeof(BYTE));
}

DWORD MemoryPatcher::SetWord(const LPVOID dwOffset, const WORD wValue) {
    return WriteMemory(dwOffset, (LPVOID) & wValue, sizeof(WORD));
}

DWORD MemoryPatcher::GetWord(const LPVOID dwOffset, WORD& wValue) {
    return ReadMemory(dwOffset, &wValue, sizeof(WORD));
}

DWORD MemoryPatcher::SetDword(const LPVOID dwOffset, const DWORD dwValue) {
    return WriteMemory(dwOffset, (LPVOID) & dwValue, sizeof(DWORD));
}

DWORD MemoryPatcher::GetDword(const LPVOID dwOffset, DWORD& dwValue) {
    return ReadMemory(dwOffset, &dwValue, sizeof(DWORD));
}

DWORD MemoryPatcher::SetFloat(const LPVOID dwOffset, float fValue) {
    return WriteMemory(dwOffset, &fValue, sizeof(float));
}

DWORD MemoryPatcher::GetFloat(const LPVOID dwOffset, float& fValue) {
    return ReadMemory(dwOffset, &fValue, sizeof(float));
}

DWORD MemoryPatcher::SetDouble(const LPVOID dwOffset, double dValue) {
    return WriteMemory(dwOffset, &dValue, sizeof(double));
}

DWORD MemoryPatcher::SetJmp(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress) {
    BYTE btBuf[5];
    DWORD dwShift = (ULONG_PTR)dwJMPAddress - (ULONG_PTR)dwEnterFunction - 5;

    btBuf[0] = 0xE9;
    memcpy(&btBuf[1], &dwShift, 4);

    return WriteMemory(dwEnterFunction, btBuf, sizeof(btBuf));
}

DWORD MemoryPatcher::SetJg(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress) {
    BYTE btBuf[6];
    DWORD dwShift = (ULONG_PTR)dwJMPAddress - (ULONG_PTR)dwEnterFunction - 6;

    btBuf[0] = 0x0F;
    btBuf[1] = 0x8F;
    memcpy(&btBuf[2], &dwShift, 4);

    return WriteMemory(dwEnterFunction, btBuf, sizeof(btBuf));
}

DWORD MemoryPatcher::SetJa(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress) {
    BYTE btBuf[6];
    DWORD dwShift = (ULONG_PTR)dwJMPAddress - (ULONG_PTR)dwEnterFunction - 6;

    btBuf[0] = 0x0F;
    btBuf[1] = 0x87;
    memcpy(&btBuf[2], &dwShift, 4);

    return WriteMemory(dwEnterFunction, btBuf, sizeof(btBuf));
}

DWORD MemoryPatcher::SetOp(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress, const BYTE cmd) {
    BYTE btBuf[5];
    DWORD dwShift = (ULONG_PTR)dwJMPAddress - (ULONG_PTR)dwEnterFunction - 5;

    btBuf[0] = cmd;
    memcpy(&btBuf[1], &dwShift, 4);

    return WriteMemory(dwEnterFunction, btBuf, sizeof(btBuf));
}

DWORD MemoryPatcher::SetRange(const LPVOID dwAddress, const USHORT wCount, const BYTE btValue) {
    BYTE* lpBuf = new BYTE[wCount];
    memset(lpBuf, btValue, wCount);

    DWORD result = WriteMemory(dwAddress, lpBuf, wCount);
    delete[] lpBuf;
    return result;
}

DWORD MemoryPatcher::SetHook(const LPVOID dwMyFuncOffset, const LPVOID dwJmpOffset, const BYTE cmd) {
    BYTE btBuf[5];
    DWORD dwShift = (ULONG_PTR)dwMyFuncOffset - ((ULONG_PTR)dwJmpOffset + 5);

    btBuf[0] = cmd;
    memcpy(&btBuf[1], &dwShift, 4);

    return WriteMemory(dwJmpOffset, btBuf, sizeof(btBuf));
}
