// CustomMenuSystem.h: Custom Menu System Protocol Headers
// Handles Finances, Commands, and Ranking requests
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "Protocol.h"

// -------------------------------------------------------------------------------
// Protocolo de Finanzas (0xF3, 0xE9)
// -------------------------------------------------------------------------------

struct PMSG_CUSTOM_FINANCES_RECV
{
	PSBMSG_HEAD header;  // C1:F3:E9
};

struct PMSG_CUSTOM_FINANCES_SEND
{
	PSBMSG_HEAD header;  // C1:F3:E9
	int Cash;
	int Gold;
	int PcPoint;
};

// -------------------------------------------------------------------------------
// Protocolo de Comandos (0xF3, 0xEA) - Opcional
// -------------------------------------------------------------------------------

struct PMSG_CUSTOM_COMMANDS_RECV
{
	PSBMSG_HEAD header;  // C1:F3:EA
};

struct CUSTOM_COMMAND_DATA
{
	char Command[32];
	char Description[64];
	BYTE Type;
};

struct PMSG_CUSTOM_COMMANDS_SEND
{
	PSWMSG_HEAD header;  // C2:F3:EA
	BYTE count;
	// CUSTOM_COMMAND_DATA data[count]
};

// -------------------------------------------------------------------------------
// Protocolo de Ranking (0xF3, 0xEB)
// -------------------------------------------------------------------------------

struct PMSG_CUSTOM_RANKING_RECV
{
	PSBMSG_HEAD header;  // C1:F3:EB
	BYTE page;
};

struct CUSTOM_RANKING_DATA
{
	BYTE Rank;
	char Name[11];
	BYTE Class;
	WORD Level;
	DWORD Reset;
	BYTE Map;
	char Guild[9];
};

struct PMSG_CUSTOM_RANKING_SEND
{
	PSWMSG_HEAD header;  // C2:F3:EB
	BYTE page;
	BYTE totalPages;
	BYTE count;
	char WelcomeMessage[64];
	// CUSTOM_RANKING_DATA data[count]
};

// -------------------------------------------------------------------------------
// Clase del Sistema de Menu Custom
// -------------------------------------------------------------------------------

class CCustomMenuSystem
{
public:
	CCustomMenuSystem();
	~CCustomMenuSystem();

	// Procesar solicitud de finanzas
	void GCReqFinances(int aIndex, PMSG_CUSTOM_FINANCES_RECV* lpMsg);

	// Procesar solicitud de ranking
	void GCReqRanking(int aIndex, PMSG_CUSTOM_RANKING_RECV* lpMsg);

private:
	// Configuracion
	char m_WelcomeMessage[64];
};

extern CCustomMenuSystem gCustomMenuSystem;
