#pragma once

// -------------------------------------------------------------------------------
// CustomCommands.h - Panel de Comandos del Jugador
// Muestra lista de comandos disponibles con descripcion
// -------------------------------------------------------------------------------

#include <windows.h>
#include <vector>
#include <string>
#include "Protocol.h"

// -------------------------------------------------------------------------------
// Constantes
// -------------------------------------------------------------------------------

#define MAX_COMMANDS 50
#define MAX_VISIBLE_COMMANDS 18

// -------------------------------------------------------------------------------
// Tipos de comandos
// -------------------------------------------------------------------------------

enum eCommandType
{
	CMD_TYPE_NORMAL = 0,   // Comando normal (blanco/amarillo)
	CMD_TYPE_VIP1 = 1,     // Comando VIP1 (verde)
	CMD_TYPE_VIP2 = 2,     // Comando VIP2 (verde)
	CMD_TYPE_ADMIN = 3,    // Comando Admin (rojo)
};

// -------------------------------------------------------------------------------
// Estructura para un comando
// -------------------------------------------------------------------------------

struct COMMAND_INFO
{
	char Command[32];      // Texto del comando (ej: "/move <Map>")
	char Description[64];  // Descripcion del comando
	int Type;              // Tipo (normal, VIP, admin)
	bool Available;        // Si esta disponible para el jugador
};

// -------------------------------------------------------------------------------
// Protocolo - Solicitud de comandos
// -------------------------------------------------------------------------------

struct PMSG_CUSTOM_COMMANDS_SEND
{
	PBMSG_HEAD header;
};

// -------------------------------------------------------------------------------
// Protocolo - Datos de un comando
// -------------------------------------------------------------------------------

struct CUSTOM_COMMAND_DATA
{
	char Command[32];
	char Description[64];
	BYTE Type;
};

// -------------------------------------------------------------------------------
// Protocolo - Respuesta de comandos
// -------------------------------------------------------------------------------

struct PMSG_CUSTOM_COMMANDS_RECV
{
	PWMSG_HEAD header;
	BYTE count;
	// CUSTOM_COMMAND_DATA data[count]
};

// -------------------------------------------------------------------------------
// Clase principal del Panel de Comandos
// -------------------------------------------------------------------------------

class CCustomCommands
{
public:
	CCustomCommands();
	~CCustomCommands();

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
	void GCReqCommands(PMSG_CUSTOM_COMMANDS_RECV* lpMsg);

	// Solicitar comandos al servidor
	void RequestCommands();

private:
	// Renderizado
	void DrawPanel();
	void DrawTitleBar();
	void DrawCommandList();
	void DrawScrollBar();

	// Input
	void ProcessInput();
	bool IsMouseOver(float x, float y, float w, float h);
	bool IsMouseClicked();

	// Scroll
	void ScrollUp();
	void ScrollDown();

private:
	// Estado
	bool m_isOpen;
	bool m_initialized;

	// Posicion del panel
	float m_panelX;
	float m_panelY;
	float m_panelWidth;
	float m_panelHeight;

	// Lista de comandos
	std::vector<COMMAND_INFO> m_commands;
	int m_scrollOffset;

	// Control de clicks
	bool m_wasMousePressed;
	DWORD m_lastClickTime;
};

// -------------------------------------------------------------------------------
// Instancia global
// -------------------------------------------------------------------------------

extern CCustomCommands gCustomCommands;
