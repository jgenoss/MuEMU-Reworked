#pragma once

// -------------------------------------------------------------------------------
// CustomMenuPanel.h - Panel de Menu Principal con Botones
// Basado en el diseño del menu del juego original
// -------------------------------------------------------------------------------

#include <windows.h>
#include <vector>
#include <string>

// -------------------------------------------------------------------------------
// Constantes
// -------------------------------------------------------------------------------

#define MAX_MENU_BUTTONS 3

// -------------------------------------------------------------------------------
// Tipos de botones del menu
// -------------------------------------------------------------------------------

enum eMenuPanelButton
{
	MENU_BTN_EVENTS = 0,
	MENU_BTN_RANKING = 1,
	MENU_BTN_COMMANDS = 2,
};

// -------------------------------------------------------------------------------
// Estructura para boton del menu
// -------------------------------------------------------------------------------

struct MENU_PANEL_BUTTON
{
	int Type;
	char Name[32];
	float X;
	float Y;
	float Width;
	float Height;
	bool Enabled;
	bool Hover;
};

// -------------------------------------------------------------------------------
// Clase principal del Panel de Menu
// -------------------------------------------------------------------------------

class CCustomMenuPanel
{
public:
	CCustomMenuPanel();
	~CCustomMenuPanel();

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

private:
	// Renderizado
	void DrawPanel();
	void DrawTitleBar();
	void DrawButtons();
	void DrawButton(MENU_PANEL_BUTTON* pBtn);

	// Input
	void ProcessInput();
	bool IsMouseOver(float x, float y, float w, float h);
	bool IsMouseClicked();

	// Ejecutar accion de boton
	void ExecuteButtonAction(int btnType);

private:
	// Estado
	bool m_isOpen;
	bool m_initialized;

	// Posicion del panel
	float m_panelX;
	float m_panelY;
	float m_panelWidth;
	float m_panelHeight;

	// Botones
	MENU_PANEL_BUTTON m_buttons[MAX_MENU_BUTTONS];

	// Control de clicks
	bool m_wasMousePressed;
	DWORD m_lastClickTime;
};

// -------------------------------------------------------------------------------
// Instancia global
// -------------------------------------------------------------------------------

extern CCustomMenuPanel gCustomMenuPanel;
