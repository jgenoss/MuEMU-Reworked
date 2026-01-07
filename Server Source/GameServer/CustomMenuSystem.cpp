// CustomMenuSystem.cpp: Custom Menu System Implementation
// Handles Finances, Commands, and Ranking requests
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CustomMenuSystem.h"
#include "Connection.h"
#include "GameMain.h"
#include "User.h"
#include "Util.h"
#include "DSProtocol.h"
#include "Map.h"

CCustomMenuSystem gCustomMenuSystem;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomMenuSystem::CCustomMenuSystem()
{
	strcpy_s(this->m_WelcomeMessage, "Bienvenido a MU Online!");
}

CCustomMenuSystem::~CCustomMenuSystem()
{
}

//////////////////////////////////////////////////////////////////////
// Solicitud de Finanzas
//////////////////////////////////////////////////////////////////////

void CCustomMenuSystem::GCReqFinances(int aIndex, PMSG_CUSTOM_FINANCES_RECV* lpMsg)
{
	if (gObjIsConnected(aIndex) == false)
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	PMSG_CUSTOM_FINANCES_SEND pMsg;
	pMsg.header.set(0xF3, 0xE9, sizeof(pMsg));

	// Obtener valores de monedas del jugador
	// Nota: Ajustar segun la estructura del servidor
	pMsg.Cash = lpObj->AccountExtraInfo.WCoinC;      // WCoin/Cash
	pMsg.Gold = lpObj->AccountExtraInfo.WCoinP;      // WCoinP/Gold
	pMsg.PcPoint = lpObj->AccountExtraInfo.GoblinPoint; // PcPoint/GoblinPoint

	DataSend(aIndex, (BYTE*)&pMsg, sizeof(pMsg));
}

//////////////////////////////////////////////////////////////////////
// Solicitud de Ranking
//////////////////////////////////////////////////////////////////////

void CCustomMenuSystem::GCReqRanking(int aIndex, PMSG_CUSTOM_RANKING_RECV* lpMsg)
{
	if (gObjIsConnected(aIndex) == false)
	{
		return;
	}

	int page = lpMsg->page;
	if (page < 1) page = 1;

	// Buffer para enviar ranking
	BYTE buffer[2048];
	memset(buffer, 0, sizeof(buffer));

	PMSG_CUSTOM_RANKING_SEND* pMsg = (PMSG_CUSTOM_RANKING_SEND*)buffer;
	CUSTOM_RANKING_DATA* pData = (CUSTOM_RANKING_DATA*)(buffer + sizeof(PMSG_CUSTOM_RANKING_SEND));

	int count = 0;
	int entriesPerPage = 5;
	int startIndex = (page - 1) * entriesPerPage;
	int totalPlayers = 0;

	// Contar jugadores conectados para el ranking
	for (int n = OBJECT_START_USER; n < MAX_OBJECT; n++)
	{
		if (gObjIsConnected(n) && gObj[n].Type == OBJECT_USER)
		{
			totalPlayers++;
		}
	}

	int totalPages = (totalPlayers + entriesPerPage - 1) / entriesPerPage;
	if (totalPages < 1) totalPages = 1;
	if (page > totalPages) page = totalPages;

	// Recopilar datos de ranking (ordenados por resets y nivel)
	// Nota: En una implementacion real, esto deberia venir de la base de datos

	int currentIndex = 0;
	for (int n = OBJECT_START_USER; n < MAX_OBJECT && count < entriesPerPage; n++)
	{
		if (gObjIsConnected(n) && gObj[n].Type == OBJECT_USER)
		{
			if (currentIndex >= startIndex)
			{
				LPOBJ lpPlayer = &gObj[n];

				pData[count].Rank = (BYTE)(startIndex + count + 1);
				strncpy(pData[count].Name, lpPlayer->Name, 10);
				pData[count].Name[10] = 0;
				pData[count].Class = lpPlayer->Class;
				pData[count].Level = lpPlayer->Level;
				pData[count].Reset = lpPlayer->Reset;
				pData[count].Map = (BYTE)lpPlayer->Map;

				// Obtener nombre del guild
				if (lpPlayer->GuildNumber > 0)
				{
					// Aqui deberia obtener el nombre del guild
					strncpy(pData[count].Guild, "", 8);
				}
				else
				{
					pData[count].Guild[0] = 0;
				}

				count++;
			}
			currentIndex++;
		}
	}

	pMsg->page = (BYTE)page;
	pMsg->totalPages = (BYTE)totalPages;
	pMsg->count = (BYTE)count;
	strncpy(pMsg->WelcomeMessage, this->m_WelcomeMessage, 63);
	pMsg->WelcomeMessage[63] = 0;

	int size = sizeof(PMSG_CUSTOM_RANKING_SEND) + (sizeof(CUSTOM_RANKING_DATA) * count);
	pMsg->header.set(0xF3, 0xEB, size);

	DataSend(aIndex, buffer, size);
}
