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
	PBMSG_HEAD header;
};

struct PMSG_CUSTOM_FINANCES_SEND
{
	PBMSG_HEAD header;
	int Cash;
	int Gold;
	int PcPoint;
};

// -------------------------------------------------------------------------------
// Protocolo de Comandos (0xF3, 0xEA) - Opcional
// -------------------------------------------------------------------------------

struct PMSG_CUSTOM_COMMANDS_RECV
{
	PBMSG_HEAD header;
};

struct CUSTOM_COMMAND_DATA
{
	char Command[32];
	char Description[64];
	BYTE Type;
};

struct PMSG_CUSTOM_COMMANDS_SEND
{
	PWMSG_HEAD header;
	BYTE count;
	// CUSTOM_COMMAND_DATA data[count]
};

// -------------------------------------------------------------------------------
// Protocolo de Ranking (0xF3, 0xEB)
// -------------------------------------------------------------------------------

struct PMSG_CUSTOM_RANKING_RECV
{
	PBMSG_HEAD header;
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
	PWMSG_HEAD header;
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
