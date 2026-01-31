#pragma once

#define WIN32_LEAN_AND_MEAN

#define _WIN32_WINNT _WIN32_WINNT_WINXP

#define cliente = layergain:
#define CONNECTSERVER_VERSION "CS"

#define GAMESERVER_TYPE2 1

#if(GAMESERVER_TYPE2 == 0)
	#define CONNECTSERVER_CLIENT "VIERJA&HIGHLEVEL"
#elif(GAMESERVER_TYPE2 == 1)
	#define CONNECTSERVER_CLIENT "HAI DAI SU"
#else
#define CONNECTSERVER_CLIENT "REAL GAMING"
#endif

#ifndef CONNECTSERVER_UPDATE
#define CONNECTSERVER_UPDATE 803
#endif

#ifndef PROTECT_STATE
#define PROTECT_STATE 0
#endif

// System Include
#include <windows.h>
#include <winsock2.h>
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
#pragma comment(lib,"Rpcrt4.lib")
#pragma comment(lib,"dbghelp.lib")
#pragma comment(lib,"Psapi.lib")

extern char CustomerName[32];
extern char CustomerHardwareId[36];
extern long MaxIpConnection;

typedef unsigned __int64 QWORD;
