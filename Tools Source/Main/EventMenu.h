#pragma once

// -------------------------------------------------------------------------------
// EventMenu.h - Menu de Horarios de Eventos Custom
// Muestra un boton que al hacer click despliega los horarios de eventos
// -------------------------------------------------------------------------------

#include <windows.h>
#include <vector>
#include <string>

//--------------------------------------------------------------------------------
// Estructura para almacenar informacion de un evento
// -------------------------------------------------------------------------------

struct EVENT_SCHEDULE_INFO
{
	std::string Name;           // Nombre del evento
	std::string NextTime;       // Proxima hora del evento
	DWORD Color;                // Color del texto
	bool IsActive;              // Si el evento esta activo ahora
};

// -------------------------------------------------------------------------------
// Clase principal del Menu de Eventos
// -------------------------------------------------------------------------------

class CEventMenu
{
public:
	CEventMenu();
	~CEventMenu();
	// Inicializacion
	void Initialize();
	// Renderizado principal - llamar cada frame
	void Render();
	// Manejo de input
	void ProcessInput();
	// Toggle del menu (abrir/cerrar)
	void Toggle();
	// Verificar si el menu esta abierto
	bool IsOpen() const { return m_isOpen; }
private:
	// Renderizado del boton principal
	void DrawButton();
	// Renderizado del panel de eventos
	void DrawEventPanel();
	// Detectar si el mouse esta sobre un rectangulo
	bool IsMouseOver(float x, float y, float width, float height);
	// Detectar click del mouse
	bool IsMouseClicked();
	// Obtener horarios de eventos (simulado - puedes conectar con el servidor)
	void UpdateEventSchedules();
	// Formatear tiempo restante
	std::string FormatTimeRemaining(int minutes);

private:
	// Estado del menu
	bool m_isOpen;
	bool m_initialized;
	// Posicion del boton
	float m_buttonX;
	float m_buttonY;
	float m_buttonWidth;
	float m_buttonHeight;
	// Posicion del panel
	float m_panelX;
	float m_panelY;
	float m_panelWidth;
	float m_panelHeight;
	// Control de clicks
	bool m_wasMousePressed;
	DWORD m_lastClickTime;
	// Lista de eventos programados
	std::vector<EVENT_SCHEDULE_INFO> m_events;
	// Tick para actualizar eventos
	DWORD m_lastUpdateTick;
};

// -------------------------------------------------------------------------------
// Instancia global
// -------------------------------------------------------------------------------

extern CEventMenu gEventMenu;