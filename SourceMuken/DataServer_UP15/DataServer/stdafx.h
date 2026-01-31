#pragma once

#define WIN32_LEAN_AND_MEAN

#define _WIN32_WINNT _WIN32_WINNT_WINXP

#define DATASERVER_VERSION "DS"
#define GAMESERVER_TYPE2 0

#define GAMESERVER_NOMBRE 1

#if(GAMESERVER_NOMBRE == 0)
	#define DATASERVER_CLIENT "VIERJA&HIGHLEVEL"
#elif(GAMESERVER_NOMBRE == 1)
	#define DATASERVER_CLIENT "MrHiep"
#else
#define DATASERVER_CLIENT "REAL GAMING"
#endif
#define MOCNAP	    1

#define DANHHIEU_NEW	    1

#define TULUYEN_NEW	    1


#define CHIEN_TRUONG_CO	    1

#define NEWBOSSGUILD 1

#define RANKINGGOC  0

#define RANKING_NEW 1
#define GHRS_TOP1_NEW               1
#define HIDE_VT 0 

#define CHIENTRUONGCO 1

#define SACHTHUOCTINH_NEW           1

#define CHONPHEDOILAP		1

#define B_HON_HOAN	1

#define EVENT_END_LESS 1

#define FLAG_SKIN					1

#ifndef BOT_STATUE
#define BOT_STATUE 1
#endif

#ifndef DATASERVER_UPDATE
#define DATASERVER_UPDATE 803
#endif

#ifndef PROTECT_STATE
#define PROTECT_STATE 1
#endif

// System Include
#include <windows.h>
#include <winsock2.h>
#include <commctrl.h>
#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>
#include <process.h>
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <Rpc.h>
#include <dbghelp.h>
#include <Psapi.h>

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"comctl32.lib")
#pragma comment(lib,"Rpcrt4.lib")
#pragma comment(lib,"dbghelp.lib")
#pragma comment(lib,"Psapi.lib")

extern char CustomerName[32];
extern char CustomerHardwareId[36];

typedef unsigned __int64 QWORD;
