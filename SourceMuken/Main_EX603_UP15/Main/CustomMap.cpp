#include "stdafx.h"
#include "CustomMap.h"
#include "Defines.h"
#include "TMemory.h"
#include "Util.h"
#include "Import.h"

#include "Interface.h"

CCustomMap gCustomMap;

// ----------------------------------------------------------------------------------------------

//char * Map5 = "NewMap05.tga";
//char * Map82 = "NewMap82.tga";
//char * Map83 = "NewMap83.tga";
//char * Map84 = "NewMap84.tga";
//char * Map85 = "NewMap85.tga";
//char * Map86 = "NewMap86.tga";
//char * Map87 = "NewMap87.tga";
//char * Map88 = "NewMap88.tga";
//char * Map89 = "NewMap89.tga";
//char * Map90 = "NewMap90.tga";
//char * Map91 = "NewMap91.tga";
//char * Map92 = "NewMap92.tga";
//char * Map93 = "NewMap93.tga";
//char * Map94 = "NewMap94.tga";
//char * Map95 = "NewMap95.tga";
//char * Map96 = "NewMap96.tga";
//char * Map97 = "ChienTruongCo.tga";
//char * Map98 = "NewMap98.tga";
//char * Map99 = "NewMap99.tga";
//char * Map100 = "NewMap100.tga";



char * Map5 = "NewMap05.tga";

char * Map82 = "CustomMap1.tga";
char * Map83 = "CustomMap2.tga";
char * Map84 = "CustomMap3.tga";
char * Map85 = "CustomMap4.tga";
char * Map86 = "CustomMap5.tga";
char * Map87 = "CustomMap6.tga";
char * Map88 = "CustomMap7.tga";
char * Map89 = "CustomMap8.tga";
char * Map90 = "CustomMap9.tga";
char * Map91 = "CustomMap10.tga";
char * Map92 = "CustomMap11.tga";
char * Map93 = "CustomMap12.tga";
char * Map94 = "CustomMap13.tga";
char * Map95 = "CustomMap14.tga";
char * Map96 = "CustomMap15.tga";
char * Map97 = "CustomMap16.tga";
char * Map98 = "CustomMap17.tga";
char * Map99 = "CustomMap18.tga";
char * Map100 = "CustomMap19.tga";
char * Map101 = "Map101.tga";
char * Map103 = "CustomMap19.tga";
char * Map104 = "losttower.tga";
char * Map106 = "ThanMaChien.tga";
char * Map110 = "MapBaoTieu.tga";
char * Map111 = "MapDaoTac.tga";
char * Map112 = "MapChungBD.tga";










char* CCustomMap::LoadMapName(signed int MapNumber)
{
	switch (MapNumber)
	{
		case 110:
		{
			return "Map Bao Tieu";

		}
		break;
		case 111:
		{
			return  "Map Dao Tac";

		}
		break;
		case 112:
		{
			return "Map Chung BD";
		}
		break;
	}

	if (MapNumber >= 82 && MapNumber <= 107)
	{
		return pGetTextLine(pTextLineThis, (3182 + MapNumber - 82));
	}

	return pMapName(MapNumber);
}

Naked(LoadInterfaceMapName)
{
	_asm
	{
		MOV DWORD PTR SS : [EBP - 0x848], 0x51
			PUSH 0x00D25498
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x05 //DARE DEVIL 
			PUSH Map5
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//---
			MOV DWORD PTR SS : [EBP - 0x848], 0x52
			PUSH Map82
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x53		// 83 Arkania Custom Map
			PUSH Map83								// Interface Name
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x54		// 84 Arkania Custom Map
			PUSH Map84								// Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x55		// 85 Arkania Custom Map
			PUSH Map85								// Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x56		// 86 Arkania Custom Map
			PUSH Map86								// Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x57		// 87 Arkania Custom Map
			PUSH Map87								// Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x58		// 88 Arkania Custom Map
			PUSH Map88								// Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x59		// 89 Arkania Custom Map
			PUSH Map89								// Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x5A		// 90 Arkania Custom Map
			PUSH Map90								// Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x5B		// 91 Arkania Custom Map
			PUSH Map91								// Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x5C		// 92 Arkania Custom Map
			PUSH Map92								// Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x5D		// 93 Arkania Custom Map
			PUSH Map93								// Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x5E		// 94 Arkania Custom Map
			PUSH Map94								// Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x5F		// 95 Arkania Custom Map
			PUSH Map95								// Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x60		// 96 Arkania Custom Map
			PUSH Map96								// Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x61		// 97 Arkania Custom Map
			PUSH Map97								// Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x62		// 98 Arkania Custom Map
			PUSH Map98								// Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x63		// 99 Arkania Custom Map
			PUSH Map99								// Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x64		// 100 Arkania Custom Map
			PUSH Map100								// Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			// ----
			//----
			MOV DWORD PTR SS : [EBP - 0x848] , 0x65		// 101 Arkania Custom Map
			PUSH Map101								// Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74] , EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78] , EDX
			MOV BYTE PTR SS : [EBP - 0x4] , 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4] , 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4] , -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			// ----
			//----Chien Truong THan Ma
			MOV DWORD PTR SS : [EBP - 0x848], 0x6A		// 106
			PUSH Map106								    // Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS : [EBP - 0x848] , 0x6E		// 110 Map bao Tieu
			PUSH Map110								// Interface Name 
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74] , EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78] , EDX
			MOV BYTE PTR SS : [EBP - 0x4] , 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4] , 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4] , -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			// ----
			//----
				MOV DWORD PTR SS : [EBP - 0x848] , 0x6F		// 111 Map dao tac
				PUSH Map111							// Interface Name 
				LEA EAX, DWORD PTR SS : [EBP - 0x28]
				PUSH EAX
				LEA ECX, DWORD PTR SS : [EBP - 0x864]
				PUSH ECX
				CALL InterfaceLoad1
				ADD ESP, 0x0C
				MOV DWORD PTR SS : [EBP - 0xA74] , EAX
				MOV EDX, DWORD PTR SS : [EBP - 0xA74]
				MOV DWORD PTR SS : [EBP - 0xA78] , EDX
				MOV BYTE PTR SS : [EBP - 0x4] , 0x43
				MOV EAX, DWORD PTR SS : [EBP - 0xA78]
				PUSH EAX
				LEA ECX, DWORD PTR SS : [EBP - 0x848]
				PUSH ECX
				MOV ECX, DWORD PTR SS : [EBP - 0x868]
				ADD ECX, 0x4
				CALL InterfaceLoad2
				MOV ECX, EAX
				CALL InterfaceLoad3
				MOV BYTE PTR SS : [EBP - 0x4] , 0x2
				LEA ECX, DWORD PTR SS : [EBP - 0x864]
				CALL InterfaceLoad4
				MOV DWORD PTR SS : [EBP - 0x4] , -0x1
				LEA ECX, DWORD PTR SS : [EBP - 0x28]
				// ----
			//----
				MOV DWORD PTR SS : [EBP - 0x848] , 0x70		// 112 Map chung bd
				PUSH Map112								// Interface Name 
				LEA EAX, DWORD PTR SS : [EBP - 0x28]
				PUSH EAX
				LEA ECX, DWORD PTR SS : [EBP - 0x864]
				PUSH ECX
				CALL InterfaceLoad1
				ADD ESP, 0x0C
				MOV DWORD PTR SS : [EBP - 0xA74] , EAX
				MOV EDX, DWORD PTR SS : [EBP - 0xA74]
				MOV DWORD PTR SS : [EBP - 0xA78] , EDX
				MOV BYTE PTR SS : [EBP - 0x4] , 0x43
				MOV EAX, DWORD PTR SS : [EBP - 0xA78]
				PUSH EAX
				LEA ECX, DWORD PTR SS : [EBP - 0x848]
				PUSH ECX
				MOV ECX, DWORD PTR SS : [EBP - 0x868]
				ADD ECX, 0x4
				CALL InterfaceLoad2
				MOV ECX, EAX
				CALL InterfaceLoad3
				MOV BYTE PTR SS : [EBP - 0x4] , 0x2
				LEA ECX, DWORD PTR SS : [EBP - 0x864]
				CALL InterfaceLoad4
				MOV DWORD PTR SS : [EBP - 0x4] , -0x1
				LEA ECX, DWORD PTR SS : [EBP - 0x28]
				// ----
			CALL InterfaceLoad4
			MOV ECX, DWORD PTR SS : [EBP - 0xC]
			MOV DWORD PTR FS : [0x0], ECX

			MOV EDI, 0x0047FD08
			JMP EDI

		InterfaceLoad1 :
		MOV EDI, 0x0047C220
			JMP EDI

		InterfaceLoad2 :
		MOV EDI, 0x00480160
			JMP EDI

		InterfaceLoad3 :
		MOV EDI, 0x00409AF0
			JMP EDI

		InterfaceLoad4 :
		MOV EDI, 0x00409AD0
			JMP EDI

			MOV ESP, EBP
			POP EBP
			RETN
	}
}

void LoadMapMusic(HDC Arg1)
{
	static PCHAR MusicID;
	// ----
	if (pPlayerState == 5)
	{
		switch (pMapNumber)
		{
		case 82:
		{
			MusicID = "Data\\Music\\Map82.mp3";
			pWzAudioPlay(MusicID, 0);
		}
		break;
		case 83:
		{
			MusicID = "Data\\Music\\Map83.mp3";
			pWzAudioPlay(MusicID, 0);
		}
		break;
		case 84:
		{
			MusicID = "Data\\Music\\Map84.mp3";
			pWzAudioPlay(MusicID, 0);
		}
		break;
		case 85:
		{
			MusicID = "Data\\Music\\Map85.mp3";
			pWzAudioPlay(MusicID, 0);
		}
		break;
		case 86:
		{
			MusicID = "Data\\Music\\Map86.mp3";
			pWzAudioPlay(MusicID, 0);
		}
		break;
		case 87:
		{
			MusicID = "Data\\Music\\Map87.mp3";
			pWzAudioPlay(MusicID, 0);
		}
		break;
		case 88:
		{
			MusicID = "Data\\Music\\Map88.mp3";
			pWzAudioPlay(MusicID, 0);
		}
		break;
		case 89:
		{
			MusicID = "Data\\Music\\Map89.mp3";
			pWzAudioPlay(MusicID, 0);
		}
		break;
		case 90:
		{
			MusicID = "Data\\Music\\Map90.mp3";
			pWzAudioPlay(MusicID, 0);
		}
		break;
		case 91:
		{
			MusicID = "Data\\Music\\Map91.mp3";
			pWzAudioPlay(MusicID, 0);
		}
		break;
		case 92:
		{
			MusicID = "Data\\Music\\Map92.mp3";
			pWzAudioPlay(MusicID, 0);
		}
		break;
		case 93:
		{
			MusicID = "Data\\Music\\Map93.mp3";
			pWzAudioPlay(MusicID, 0);
		}
		break;
		case 94:
		{
			MusicID = "Data\\Music\\Map94.mp3";
			pWzAudioPlay(MusicID, 0);
		}
		break;
		case 95:
		{
			MusicID = "Data\\Music\\Map95.mp3";
			pWzAudioPlay(MusicID, 0);
		}
		break;
		case 96:
		{
			MusicID = "Data\\Music\\Map96.mp3";
			pWzAudioPlay(MusicID, 0);
		}
		break;
		case 97:
		{
			MusicID = "Data\\Music\\Map97.mp3";
			pWzAudioPlay(MusicID, 0);
		}
		break;
		case 98:
		{
			MusicID = "Data\\Music\\Map98.mp3";
			pWzAudioPlay(MusicID, 0);
		}
		break;
		case 99:
		{
			MusicID = "Data\\Music\\Map99.mp3";
			pWzAudioPlay(MusicID, 0);
		}
		break;
		case 100:
		{
			MusicID = "Data\\Music\\Map100.mp3";
			pWzAudioPlay(MusicID, 0);
		}
		break;
		}
	}
	// ----
	pLoadGameStuffs(Arg1);
}

void CCustomMap::Load()
{
	//	SetOp((LPVOID)0x00520ECF, (LPVOID)LoadMapName, ASM::CALL);
	//	SetOp((LPVOID)0x00520F1F, (LPVOID)LoadMapName, ASM::CALL);
	//	SetOp((LPVOID)0x0063E743, (LPVOID)LoadMapName, ASM::CALL);
	//	SetOp((LPVOID)0x00640EB2, (LPVOID)LoadMapName, ASM::CALL);
	//	SetOp((LPVOID)0x007D2DD9, (LPVOID)LoadMapName, ASM::CALL);
	//	SetOp((LPVOID)0x007E6C0F, (LPVOID)LoadMapName, ASM::CALL);
	//	SetOp((LPVOID)0x0084AEF7, (LPVOID)LoadMapName, ASM::CALL);

	SetCompleteHook(0xFF, 0x00520ECF, &this->LoadMapName);
	SetCompleteHook(0xFF, 0x00520F1F, &this->LoadMapName);
	SetCompleteHook(0xFF, 0x0063E743, &this->LoadMapName);
	SetCompleteHook(0xFF, 0x00640EB2, &this->LoadMapName);
	SetCompleteHook(0xFF, 0x007D2DD9, &this->LoadMapName);
	SetCompleteHook(0xFF, 0x007E6C0F, &this->LoadMapName);
	SetCompleteHook(0xFF, 0x0084AEF7, &this->LoadMapName);

	SetRange((LPVOID)0x0047FC85, 131, ASM::NOP);
	SetOp((LPVOID)0x0047FC85, (LPVOID)LoadInterfaceMapName, ASM::JMP);

	//Bypass in terrains files
	SetByte((LPVOID)0x0062EBF8, 0xEB);
	SetByte((LPVOID)0x0062EBFE, 0xEB);
	SetByte((LPVOID)0x0062EE42, 0xEB);
	SetByte((LPVOID)0x0062EE48, 0xEB);
	SetByte((LPVOID)0x0062EEE5, 0xEB);
	SetByte((LPVOID)0x0062EEEB, 0xEB);

	//Increase terrains amount
	SetByte((LPVOID)0x0062EBF7, 0x69);
	SetByte((LPVOID)0x0062EE41, 0x69);
	SetByte((LPVOID)0x0062EEE4, 0x69);

	//Set Music
	SetOp((LPVOID)0x004DADA4, (LPVOID)LoadMapMusic, ASM::CALL);
}