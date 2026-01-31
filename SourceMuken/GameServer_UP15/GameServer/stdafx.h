#pragma once

#define WIN32_LEAN_AND_MEAN

#define _WIN32_WINNT _WIN32_WINNT_WINXP

#define GAMESERVER_STATUS "STANDBY MODE"

#define GAMESERVER_STATUS_MODE "ACTIVE MODE"

#define ISPREMIUN 1


#define HWID_VPS "3C1C1EDD-FE2EF569-F45BE30A-8A40D8E7"

#define CheckLicHWID 0 // Bật Nếu Check License

//extern int Conectar;

#define GAMESERVER_NOMBRE 1

#if(GAMESERVER_NOMBRE == 0)
	#define GAMESERVER_CLIENT "VIERJA&HIGHLEVEL"
#elif(GAMESERVER_NOMBRE == 1)
	#define GAMESERVER_CLIENT "SDT: 0971.834.407"
#else
#define GAMESERVER_CLIENT "REAL GAMING"
#endif

#define UPDATE_GAMING 15
#define GAMESERVER_CLIENTE_UPDATE 17
#define GAMESERVER_CLIENTE_PREMIUM 0


#if(GAMESERVER_TYPE==0)
#define GAMESERVER_VERSION "GS"
#else
#define GAMESERVER_VERSION "GSCS"
#endif

#ifndef GAMESERVER_TYPE
#define GAMESERVER_TYPE 0
#endif

#ifndef GAMESERVER_EXTRA
#define GAMESERVER_EXTRA 1
#endif

#ifndef GAMESERVER_UPDATE
#define GAMESERVER_UPDATE 803
#endif

#if(GAMESERVER_UPDATE==401)
#define GAMESERVER_SEASON "SEASON 4"
#endif

#if(GAMESERVER_UPDATE==603)
#define GAMESERVER_SEASON "SEASON 6"

#if(GAMESERVER_UPDATE==803)
#define GAMESERVER_SEASON "SEASON 8"
#endif
#endif
#define VERSION "1.0.0.0"
#ifndef GAMESERVER_LANGUAGE
#define GAMESERVER_LANGUAGE 1
#endif

#ifndef PROTECT_STATE
#define PROTECT_STATE 1
#endif

#ifndef ENCRYPT_STATE
#define ENCRYPT_STATE 1
#endif

#if(PROTECT_STATE==0)
#define GAMESERVER_NAME "Free"
#else
#define GAMESERVER_NAME "Premium"
#endif
#define THANMA           1 // ON

#define MOCNAP           1 // ON

#define RANKINGGOC  					0 // Mới

#define RANKING_NEW 					1 // Mới

#define HIDE_HDC						0 // Mới

#define TAT_1							0 // ON 

#define FIXEPSOCKET						1 // Add them roolback

//=============================================================================================>
#define CUSTOM_PET						1 // Mới

#define OFFLINE_MODE					1 // Mới

#define PC_POINT						2 // Mới

#define PARTYSEARCH          			1 // Mới

#define GuardMessage 					1 // Mới

#define DANHHIEU_NEW					1 // Mới

#define TULUYEN_NEW						1 // Mới

#define OFFLINE_MODE_NEW        1 // ON

#define GHRS_TOP1_NEW					1 // ON 

#define	FIX_DUPE_DUEL					1 // Mới

#define FIX_DAME_SOI_HK					1 // Mới

#define CHANGE_FIX_POINT				0 // Mới

#define FIX_TELE_KHONG_DUNG_SKILL		1 // Mới

#define FIX_CHOANG_MUI_TEN_BANG			1 // Mới

#define FIX_ELF_KHONG_MAT_TEN			1 // Mới

#define DROP_ITEMBAG					1 // Mới

#define TAT_NHIEM_VU_ELF_BUFFER			1 // Mới

#define POST_HIEN_SUB					1 // Mới

#define CHECK_ELF_BUFF_KHONG_QUA_2_LAN	1 // Mới

#define PARTYSETPASS					1 // Mới

#define	CUSTOM_MIX_WING_CUSTOM			1 // Mới

#define	CUSTOM_MIX_WING_SEASON13		1 // Mới

#define	CUSTOM_MIX_WING_SEASON8			1 // Mới

#define	CUSTOM_MIX_WING_VIP				1 // Mới

#define	CUSTOM_MIX_PET_CAP2				1 // Mới

#define	CUSTOM_MIX_PET_CAP3				1 // Mới

#define	CUSTOM_MIX_PET_CAP4				1 // Mới

#define	CUSTOM_MIX_PET_CAP5				1 // Mới

#define	CUSTOM_MIX_PET_CAP6				1 // Mới

#define	CUSTOM_MIX_PET_CAP7				1 // Mới

#define	CUSTOM_MIX_PET_CAP8				1 // Mới

#define	CUSTOM_MIX_PET_CAP9				1 // Mới

#define	CUSTOM_MIX_PET_CAP10		    1 // Mới

#define	CUSTOM_MIX_PET_CAP11		    1 // Mới

#define SOIITEM							0 // Mới

#define	MEMBER_ONLINE				    1 // Mới

#define VONGQUAY_NEW                    1 // Mới

#define NGAN_HANG_NGOC                  1 // Mới

#define BUFF_VUKHI_ICON					1 // Mới

#define BUFF_SET_ICON     				1 // Mới

#define CHIEN_TRUONG_CO					0 // Mới

#define BOSS_GUILD						0 // Mới

#define NEWBOSSGUILD					0 // Mới

#define SKY_EVENT						1 // Mới

#define	FixDupeItem  					1 // Mới

#define	MOVE_ITEM  						1 // Mới

#define BUY_TINH_NANG_NEW				1 // Mới

#define CHECK_USER						1 // Mới

#define CTCMINI							1 // Mới

#define MOVETAP 						1 // Mới

#define TEAMVSTEAM						1 // Mới

#define HONCHIENCLASS					1 // Mới

#define FIXVT   						1 //Mới

#define Fix_Dupe						1 //Mới

#define ANTIHACKGS						1

#define SACHTHUOCTINH_NEW				1 

#define EVENT_MAPBAOTIEU   				1

#define Delay_Skill_Custom				0	//CustomAttackDelay Custom.ini ( 1: Custom | 0: Gốc )
//=============================================================================================>
#define HAISLOTRING      1 // ON

#define USE_FAKE_ONLINE						TRUE



#define FLAG					1

#define CHONPHEDOILAP		1
//=============================================================================================>
//-- Need All Types
#define PG_CUSTOM			 1
#define ALLBOTSSTRUC		 1

#define BOT_BUFFER			 1

#ifndef BOTHUMUADORAC
#define BOTHUMUADORAC		 1

#ifndef BOTCONGHUONG
#define BOTCONGHUONG		1
#endif
#endif

#ifndef BOT_STATUE
#define BOT_STATUE 1
#endif

#define BOT_STORE            1

#define BOT_ONLINE           1

#define BOT_ATTACK   		 1


#ifndef OANTUTI
#define OANTUTI 1
#endif

#define B_HON_HOAN	1
#define B_BUFF_PHE	1
#define CUSTOM_EVENTBOSS_BB	1
#define EVENT_END_LESS    1

#define FLAG_SKIN							1
//=============================================================================================>



#include <windows.h>
#include <winsock2.h>
#include <mswSock.h>
#include <commctrl.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <random>
#include <Rpc.h>
#include <algorithm>
#include <string>
#include <atltime.h>
#include <dbghelp.h>
#include <Psapi.h>
#include "pugixml.hpp"

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"Rpcrt4.lib")
#pragma comment(lib,"dbghelp.lib")
#pragma comment(lib,"Psapi.lib")

#if(GAMESERVER_UPDATE>=701)
#if(NDEBUG==0)
#pragma comment(lib,"..\\..\\Util\\cryptopp\\Debug\\cryptlib.lib")
#else
#pragma comment(lib,"..\\..\\Util\\cryptopp\\Release\\cryptlib.lib")
#endif
#pragma comment(lib,"..\\..\\Util\\mapm\\mapm.lib")
#endif

typedef char chr;

typedef float flt;

typedef short shrt;

typedef unsigned __int64 QWORD;
