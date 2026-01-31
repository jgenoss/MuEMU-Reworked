#pragma once

#define MAIN_LANGUAGE 0x00E8C5C4
#define MAIN_CONNECTION_STATUS 0x08793704
#define MAIN_SCREEN_STATE 0x00E609E8
#define MAIN_CHARACTER_STRUCT 0x08128AC8
#define MAIN_VIEWPORT_STRUCT 0x07BC4F04
#define MAIN_PACKET_SERIAL 0x08793700
#define MAIN_HELPER_STRUCT 0x00E8CB7C
#define MAIN_FONT_SIZE 0x081C0380
#define MAIN_RESOLUTION 0x00E8C240
#define MAIN_RESOLUTION_X 0x00E61E58
#define MAIN_RESOLUTION_Y 0x00E61E5C
#define MAIN_PARTY_MEMBER_COUNT 0x081F6B6C

#define ProtocolCore ((BOOL(*)(DWORD,BYTE*,DWORD,DWORD))0x00663B20)
#define DrawInterfaceText ((void(*)(char*,int,int,int,int,int,int,int))0x007D04D0)

#define pSetFont				((int(__thiscall*)(LPVOID This, int a2)) 0x420120)
#define pSetBkColor				((int(__thiscall*)(LPVOID This, BYTE red, BYTE green, BYTE blue, BYTE alpha)) 0x4200B0)
#define pSetTexture				((void(__cdecl*)(int a1)) 0x00635CF0)//sub_635CF0(a1)
#define	pFontNormal				*(HGDIOBJ*)0x00E8C588
#define pFontBold				*(HGDIOBJ*)0x00E8C58C
#define pFontBigBold			*(HGDIOBJ*)0x00E8C590
#define pFontNormal2			*(HGDIOBJ*)0x00E8C594

#define sub_596AC0   ((void(__thiscall*)(int a1)) 0x00596AC0) //1
#define sub_407B20			((int(*)()) 0x00407B20)
#define sub_785870			((void(__thiscall*)(DWORD , int a2, int a3, int a4, int a5)) 0x00785870)
#define sub_861AC0          ((int(__thiscall*) (DWORD)) 0x00861AC0)
#define sub_7F0D40          ((void(__thiscall*) (DWORD)) 0x007F0D40)
#define sub_7F0C80			((void(__thiscall*)(DWORD , int a2, int a3, int a4)) 0x007F0C80)
#define sub_830B70			((void(__thiscall*)(DWORD , int a2, int a3, int a4)) 0x00830B70)
#define dword_81C0380                *(DWORD*)0x81C0380