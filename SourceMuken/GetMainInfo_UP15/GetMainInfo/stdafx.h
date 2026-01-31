#pragma once

// System Include
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <stdlib.h>
#include <map>
#include <fstream>
#include "pugixml.hpp"
#include <iostream>
using namespace std;
#define PREMIUN	1

#if(PREMIUN == 1)
	#define MAX_CUSTOM_GLOVES	50
	#define MAX_CUSTOM_BOW		50
	#define MAX_PET_ITEM		300
	#define MAX_CUSTOMCLOAK		20
	#define MAX_CUSTOPETEFFECT	3000
#else
	#define MAX_CUSTOM_GLOVES	20
	#define MAX_CUSTOM_BOW		20
	#define MAX_PET_ITEM		150
	#define MAX_CUSTOMCLOAK		10
	#define MAX_CUSTOPETEFFECT		500
#endif

#define MAX_CUSTOM_WING			150
#define MAX_REMAKE_EFFECT		100
#define MAX_CUSTOM_ITEM_INFO	5000
#define MAX_POSITION_ITEM		1000
#define MAX_DYNAMIC_WING_EFFECT	15000
#define MAX_CUSTOM_WING_EFFECT	15000

#define GET_ITEM(x, y)	((x * 512) + y)

#define CUSTOM_EVENTBOSS_BB 1