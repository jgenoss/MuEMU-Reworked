#pragma once

// -------------------------------------------------------------------------------
// CustomMenu.h - Menu Custom con Botones Personalizables
// Barra de botones horizontal para acceder a diferentes funcionalidades
// -------------------------------------------------------------------------------

#include <windows.h>
#include <vector>
#include <string>
#include <functional>

// -------------------------------------------------------------------------------
// Tipos de botones del menu
// -------------------------------------------------------------------------------

enum eCustomMenuButtonType
{
	MENU_BUTTON_EVENTTIME = 0,    // Boton para CustomEventTime
	MENU_BUTTON_CUSTOM1 = 1,      // Boton personalizable 1
	MENU_BUTTON_CUSTOM2 = 2,      // Boton personalizable 2
	MENU_BUTTON_CUSTOM3 = 3,      // Boton personalizable 3
	MENU_BUTTON_CUSTOM4 = 4,      // Boton personalizable 4
	MAX_CUSTOM_MENU_BUTTONS = 5
};

// -------------------------------------------------------------------------------
// Estructura para un boton del menu
// -------------------------------------------------------------------------------

struct CUSTOM_MENU_BUTTON
{
	int Type;                      // Tipo de boton (eCustomMenuButtonType)
	char Name[32];                 // Nombre/texto del boton
	float X;                       // Posicion X
	float Y;                       // Posicion Y
	float Width;                   // Ancho
	float Height;                  // Alto
	bool Enabled;                  // Si el boton esta habilitado
	bool Visible;                  // Si el boton es visible
	DWORD NormalColor;             // Color normal
	DWORD HoverColor;              // Color al pasar el mouse
	DWORD TextColor;               // Color del texto
};

// -------------------------------------------------------------------------------
// Clase principal del Menu Custom
// -------------------------------------------------------------------------------

class CCustomMenu
{
public:
	CCustomMenu();
	~CCustomMenu();

	// Inicializacion
	void Load();

	// Renderizado principal - llamar cada frame
	void Render();

	// Manejo de input
	void ProcessInput();

	// Configurar un boton
	void SetButton(int type, const char* name, bool enabled, bool visible);

	// Obtener estado de un boton
	bool IsButtonEnabled(int type);

	// Activar/desactivar visibilidad general del menu
	void SetVisible(bool visible) { m_isVisible = visible; }
	bool IsVisible() const { return m_isVisible; }

private:
	// Renderizado de la barra de botones
	void DrawButtonBar();

	// Renderizado de un boton individual
	void DrawButton(CUSTOM_MENU_BUTTON* pButton);

	// Detectar si el mouse esta sobre un rectangulo
	bool IsMouseOver(float x, float y, float width, float height);

	// Detectar click del mouse
	bool IsMouseClicked();

	// Ejecutar accion del boton
	void ExecuteButtonAction(int buttonType);

	// Calcular posiciones de los botones
	void CalculateButtonPositions();

private:
	// Estado del menu
	bool m_isVisible;
	bool m_initialized;

	// Posicion de la barra
	float m_barX;
	float m_barY;
	float m_barWidth;
	float m_barHeight;
	float m_buttonSpacing;

	// Control de clicks
	bool m_wasMousePressed;
	DWORD m_lastClickTime;

	// Lista de botones
	CUSTOM_MENU_BUTTON m_buttons[MAX_CUSTOM_MENU_BUTTONS];
	int m_visibleButtonCount;
};

// -------------------------------------------------------------------------------
// Instancia global
// -------------------------------------------------------------------------------

extern CCustomMenu gCustomMenu;
