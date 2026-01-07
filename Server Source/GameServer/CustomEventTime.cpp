// CustomEventTime.cpp: implementation of the CCustomEventTime class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CustomEventTime.h"
#include "DSProtocol.h"
#include "GameMain.h"
#include "ServerDisplayer.h"
#include "ServerInfo.h"
#include "User.h"

CCustomEventTime gCustomEventTime;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomEventTime::CCustomEventTime()
{
	this->Init();
}

CCustomEventTime::~CCustomEventTime()
{
}

void CCustomEventTime::Init()
{
	this->m_count = 0;

	for (int n = 0; n < MAX_EVENTTIME; n++)
	{
		this->m_Data[n].index = -1;
		this->m_Data[n].time = -1;
	}
}

void CCustomEventTime::GCReqEventTime(int aIndex, PMSG_CUSTOM_EVENTTIME_RECV* lpMsg)
{
	// Verificar si está habilitado
	if (gServerInfo.m_CustomEventTimeSwitch == 0)
	{
		return;
	}

	// Verificar conexión
	if (gObjIsConnected(aIndex) == false)
	{
		return;
	}

	BYTE send[4096];
	PMSG_CUSTOM_EVENTTIME_SEND pMsg;
	pMsg.header.set(0xF3, 0xE8, 0);

	int size = sizeof(pMsg);
	pMsg.count = 0;

	CUSTOM_EVENTTIME_DATA info;

	// EVENTOS PRINCIPALES (índices 0-13)
	for (int n = 0; n < 14; n++)
	{
		info.index = n;

		switch (n)
		{
		case 0:  info.time = gServerDisplayer.EventBc; break;           // Blood Castle
		case 1:  info.time = gServerDisplayer.EventDs; break;           // Devil Square
		case 2:  info.time = gServerDisplayer.EventCc; break;           // Chaos Castle
		case 3:  info.time = gServerDisplayer.EventIt; break;           // Illusion Temple
		case 4:  info.time = gServerDisplayer.EventCustomLottery; break;
		case 5:  info.time = gServerDisplayer.EventCustomQuiz; break;
		case 6:  info.time = gServerDisplayer.EventCustomBonus; break;
		case 7:  info.time = gServerDisplayer.EventMoss; break;
		case 8:  info.time = gServerDisplayer.EventDrop; break;
		case 9:  info.time = gServerDisplayer.EventKing; break;
		case 10: info.time = gServerDisplayer.EventTvT; break;
		default: info.time = -1; break;  // Reservados
		}

		pMsg.count++;
		memcpy(&send[size], &info, sizeof(info));
		size += sizeof(info);
	}

	// INVASIONES (índices 14-27)
	for (int n = 0; n < 14; n++)
	{
		info.index = n + 14;
		info.time = gServerDisplayer.EventInvasion[n];

		pMsg.count++;
		memcpy(&send[size], &info, sizeof(info));
		size += sizeof(info);
	}

	// ARENA CUSTOM (índices 28-41)
	for (int n = 0; n < 14; n++)
	{
		info.index = n + 28;
		info.time = gServerDisplayer.EventCustomArena[n];

		pMsg.count++;
		memcpy(&send[size], &info, sizeof(info));
		size += sizeof(info);
	}

	// Establecer tamaño final
	pMsg.header.size[0] = SET_NUMBERHB(size);
	pMsg.header.size[1] = SET_NUMBERLB(size);

	memcpy(send, &pMsg, sizeof(pMsg));
	DataSend(aIndex, send, size);
}
