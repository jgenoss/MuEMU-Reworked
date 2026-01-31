#pragma once

typedef unsigned __int64 QWORD;

#define WIN32_LEAN_AND_MEAN

#define _WIN32_WINNT _WIN32_WINNT_WINXP

#define VERSION	"1.0.0.0"
// System Include
#include <windows.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <winsock2.h>
#include <Mmsystem.h>
#include <time.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include "detours.h"
#include <Shellapi.h>
#include <vector>
#include <map>
#include <Windows.h>
#include <algorithm>
#include <winioctl.h>
#include <algorithm>
#include <stdio.h>
#define va_start _crt_va_start
#define va_arg _crt_va_arg
#define va_end _crt_va_end

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"Winmm.lib")
#pragma comment(lib,"Opengl32.lib")
#pragma comment(lib,"detours.lib")
#pragma comment(lib,"wzMUQuiz.lib") //soiitem
#define SOIITEM 0
#define PREMIUN	1
#define MAX_CHAT_TYPE1			10

#define MAX_CUSTOM_GLOVES	50
#define MAX_CUSTOM_BOW		50
#define MAX_PET_ITEM		300
#define MAX_CUSTOMCLOAK		20
	

#define MAX_CUSTOM_WING			150
#define MAX_REMAKE_EFFECT		100
#define MAX_CUSTOM_ITEM_INFO	5000
#define MAX_POSITION_ITEM		1000
//--
#define MAX_CUSTOPETEFFECT			3000
#define MAX_DYNAMIC_WING_EFFECT		15000
#define MAX_CUSTOM_WING_EFFECT		15000

#define MODELSKINFIX 8000

#define UPDATE 15

#define ADD_PARTY_LEADER			0

#define LODWORD(h)					((DWORD)(__int64(h) & __int64(0xffffffff)))

//===Custom

#define NOTICE_MES				1
#define TEXT_IN_GAME			1
#define HA_CPU					1
#define PARTYSEARCH             1
#define CAMERA					1 // code button camera
#define SHOWNAME				1
#define THONG_BAO_PLUGIN_ERROR	1
#ifndef TEXTVN_NEW
#define TEXTVN_NEW				1
#endif
#define RECONNECT 1

#define THANMA                  1 // ON
#define DANH_HIEU_NEW	            1
#define TU_LUYEN_NEW                0

#define ANTI_CRACK_MAIN				0
#define TAT_QUEST_T					1
#define TAT_kEY_U					1
#define TAT_kEY_F					1

#define RANKINGGOC 0
#define RANKING_NEW 1

#define FIX_MONTER_TRABE			1
#define FIX_LAG_QOAI				1
#define FIX_GIAM_LAG_MAIN			0
#define FIX_ITEM_STACK_SHOP			1
#define VONGQUAY_NEW				1 //  
#define DOI_GIOI_TINH				1 //  
#define NGAN_HANG_NGOC				1 //  
#define CUSTOM_FLAGS				1  
#define ANTIHACK					0
#define OANTUTY						1
#define EXBEXO_LOAD_SEND_TINH_NANG         1 
#define NUT_TINH_NANG			    1
#define VANTHANH_CHUCHAY            1
#define CHIEN_TRUONG_CO			    1
#define PKEVENT						1
#define VANTHANH_FLAG               1
#define BOSS_GUILD					1
#define MOCNAP                      1 // ON
#define TINHNANG_NEW				1
#define PKEVENT						1
#define VANTHANH_LAMMOWING			1
#define TVTEVENT					1
#define HIDE_VT						 0
#define FIXVT						 1
#define OFFLINE_MODE_NEW	        1
//Fixx
#define FIX_QUAY_LAI_TIEP_THEO_TAO_GUILD_INTERFACE_1_2		1			


#define SACHTHUOCTINH_NEW           1

#define CHONPHEDOILAP				1
#define EVENT_MAPBAOTIEU   				1

#define B_HON_HOAN			1
#define B_BUFF_PHE			1

#define FLAG_SKIN					1

#define CUSTOM_EVENTBOSS_BB 1

#define EVENT_END_LESS    1 //New