#pragma once

// -------------------------------------------------------------------------------
// CustomRanking.h - Panel de Ranking de Jugadores
// Muestra top jugadores con paginacion
// -------------------------------------------------------------------------------

#include <windows.h>
#include <vector>
#include <string>
#include "Protocol.h"

// -------------------------------------------------------------------------------
// Constantes
// -------------------------------------------------------------------------------

#define MAX_RANKING_ENTRIES 100
#define RANKING_PER_PAGE 5
#define MAX_RANKING_PAGES 10

// -------------------------------------------------------------------------------
// Estructura para entrada de ranking
// -------------------------------------------------------------------------------

struct RANKING_ENTRY
{
	int Rank;
	char Name[11];
	char Class[20];
	WORD Level;
	DWORD Reset;
	char Map[20];
	char Guild[9];
};

// -------------------------------------------------------------------------------
// Protocolo - Solicitud de ranking
// -------------------------------------------------------------------------------

struct PMSG_CUSTOM_RANKING_SEND
{
	PBMSG_HEAD header;
	BYTE page;
};

// -------------------------------------------------------------------------------
// Protocolo - Datos de ranking
// -------------------------------------------------------------------------------

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

// -------------------------------------------------------------------------------
// Protocolo - Respuesta de ranking
// -------------------------------------------------------------------------------

struct PMSG_CUSTOM_RANKING_RECV
{
	PWMSG_HEAD header;
	BYTE page;
	BYTE totalPages;
	BYTE count;
	char WelcomeMessage[64];
	// CUSTOM_RANKING_DATA data[count]
};

// -------------------------------------------------------------------------------
// Clase principal del Panel de Ranking
// -------------------------------------------------------------------------------

class CCustomRanking
{
public:
	CCustomRanking();
	~CCustomRanking();

	// Inicializacion
	void Load();

	// Renderizado principal
	void Render();

	// Abrir/cerrar panel
	void OpenPanel();
	void ClosePanel();
	void TogglePanel();

	// Estado
	bool IsOpen() const { return m_isOpen; }

	// Recibir datos del servidor
	void GCReqRanking(PMSG_CUSTOM_RANKING_RECV* lpMsg);

	// Solicitar ranking al servidor
	void RequestRanking(int page = 1);

private:
	// Renderizado
	void DrawPanel();
	void DrawTitleBar();
	void DrawTableHeader();
	void DrawRankingList();
	void DrawWelcomeMessage();
	void DrawPagination();

	// Input
	void ProcessInput();
	bool IsMouseOver(float x, float y, float w, float h);
	bool IsMouseClicked();

	// Paginacion
	void PrevPage();
	void NextPage();

	// Utilidades
	const char* GetClassName(int classId);
	const char* GetMapName(int mapId);
	DWORD GetRankColor(int rank);

private:
	// Estado
	bool m_isOpen;
	bool m_initialized;

	// Posicion del panel
	float m_panelX;
	float m_panelY;
	float m_panelWidth;
	float m_panelHeight;

	// Datos de ranking
	std::vector<RANKING_ENTRY> m_entries;
	int m_currentPage;
	int m_totalPages;
	char m_welcomeMessage[64];

	// Control de clicks
	bool m_wasMousePressed;
	DWORD m_lastClickTime;
};

// -------------------------------------------------------------------------------
// Instancia global
// -------------------------------------------------------------------------------

extern CCustomRanking gCustomRanking;
