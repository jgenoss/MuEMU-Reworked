#include "StdAfx.h"
#pragma once
#include "Protocol.h"


struct MOVE_EVENT_REQ
{
	PSBMSG_HEAD h;
	int	MOVE_EVENT;
	//int	MOVE_MAP;
};

class CCustomMoveEvent
{
	public:
		CCustomMoveEvent();
		virtual ~CCustomMoveEvent();
		void MOVE_EVENT(LPOBJ lpObj, MOVE_EVENT_REQ *lpMsg, int aIndex);

};
extern CCustomMoveEvent gCustomMoveEvent;
//-----------------------------------
