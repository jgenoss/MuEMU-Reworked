#include "stdafx.h"
#include "CustomMenu.h"
#include "MuClientAPI.h"
#include "MuConstants.h"
#include "UIBase.h"
#include "Protect.h"
#include "CustomEventTime.h"

CCustomMenu gCustomMenu;

// -------------------------------------------------------------------------------
// Constructor / Destructor
// -------------------------------------------------------------------------------

CCustomMenu::CCustomMenu()
{
	m_isVisible = true;
	m_initialized = false;
	m_wasMousePressed = false;
	m_lastClickTime = 0;
	m_visibleButtonCount = 0;

	// Posicion de la barra (esquina superior derecha)
	m_barX = 490.0f;
	m_barY = 40.0f;
	m_barHeight = 20.0f;
	m_buttonSpacing = 5.0f;

	// Inicializar botones
	memset(m_buttons, 0, sizeof(m_buttons));

	for (int i = 0; i < MAX_CUSTOM_MENU_BUTTONS; i++)
	{
		m_buttons[i].Type = i;
		m_buttons[i].Enabled = false;
		m_buttons[i].Visible = false;
		m_buttons[i].Width = 85.0f;
		m_buttons[i].Height = 18.0f;
		m_buttons[i].NormalColor = 0xFF000000;
		m_buttons[i].HoverColor = 0xFF1A2550;
		m_buttons[i].TextColor = g_muColors.Gold;
	}
}

CCustomMenu::~CCustomMenu()
{
}

// -------------------------------------------------------------------------------
// Inicializacion
// -------------------------------------------------------------------------------

void CCustomMenu::Load()
{
	if (m_initialized)
		return;

	// Configurar boton de EventTime desde Main.emu
	if (gProtect.m_MainInfo.EnableEventTimeButton)
	{
		SetButton(MENU_BUTTON_EVENTTIME, "Event Time", true, true);
	}

	// Aqui puedes agregar mas botones en el futuro:
	// SetButton(MENU_BUTTON_CUSTOM1, "Stats", true, true);
	// SetButton(MENU_BUTTON_CUSTOM2, "Shop", true, true);

	CalculateButtonPositions();
	m_initialized = true;
}

// -------------------------------------------------------------------------------
// Configurar un boton
// -------------------------------------------------------------------------------

void CCustomMenu::SetButton(int type, const char* name, bool enabled, bool visible)
{
	if (type < 0 || type >= MAX_CUSTOM_MENU_BUTTONS)
		return;

	strncpy_s(m_buttons[type].Name, name, 31);
	m_buttons[type].Name[31] = '\0';
	m_buttons[type].Enabled = enabled;
	m_buttons[type].Visible = visible;

	CalculateButtonPositions();
}

// -------------------------------------------------------------------------------
// Obtener estado de un boton
// -------------------------------------------------------------------------------

bool CCustomMenu::IsButtonEnabled(int type)
{
	if (type < 0 || type >= MAX_CUSTOM_MENU_BUTTONS)
		return false;

	return m_buttons[type].Enabled;
}

// -------------------------------------------------------------------------------
// Calcular posiciones de los botones
// -------------------------------------------------------------------------------

void CCustomMenu::CalculateButtonPositions()
{
	m_visibleButtonCount = 0;
	float currentX = m_barX;

	for (int i = 0; i < MAX_CUSTOM_MENU_BUTTONS; i++)
	{
		if (m_buttons[i].Visible && m_buttons[i].Enabled)
		{
			m_buttons[i].X = currentX;
			m_buttons[i].Y = m_barY;
			currentX += m_buttons[i].Width + m_buttonSpacing;
			m_visibleButtonCount++;
		}
	}

	// Calcular ancho total de la barra
	if (m_visibleButtonCount > 0)
	{
		m_barWidth = currentX - m_barX - m_buttonSpacing;
	}
	else
	{
		m_barWidth = 0;
	}
}

// -------------------------------------------------------------------------------
// Renderizado principal
// -------------------------------------------------------------------------------

void CCustomMenu::Render()
{
	if (!m_initialized)
		Load();

	if (!m_isVisible || m_visibleButtonCount == 0)
		return;

	// Verificar ventanas criticas
	bool criticalWindowOpen = (
		gUIBase.CheckWindow(static_cast<int>(WindowType::CashShop)) ||
		gUIBase.CheckWindow(static_cast<int>(WindowType::FullMap)) ||
		gUIBase.CheckWindow(static_cast<int>(WindowType::Store)) ||
		gUIBase.CheckWindow(static_cast<int>(WindowType::Inventory))
	);

	if (criticalWindowOpen)
		return;

	// Procesar input
	ProcessInput();

	// Dibujar la barra de botones
	DrawButtonBar();
}

// -------------------------------------------------------------------------------
// Renderizado de la barra de botones
// -------------------------------------------------------------------------------

void CCustomMenu::DrawButtonBar()
{
	for (int i = 0; i < MAX_CUSTOM_MENU_BUTTONS; i++)
	{
		if (m_buttons[i].Visible && m_buttons[i].Enabled)
		{
			DrawButton(&m_buttons[i]);
		}
	}
}

// -------------------------------------------------------------------------------
// Renderizado de un boton individual
// -------------------------------------------------------------------------------

void CCustomMenu::DrawButton(CUSTOM_MENU_BUTTON* pButton)
{
	if (pButton == nullptr)
		return;

	glPushAttrib(GL_ALL_ATTRIB_BITS);

	float btnX = pButton->X;
	float btnY = pButton->Y;
	float btnW = pButton->Width;
	float btnH = pButton->Height;

	bool isHover = IsMouseOver(btnX, btnY, btnW, btnH);

	// Bloquear click hacia el fondo si el mouse esta sobre el boton
	if (isHover)
	{
		gMuClientApi.SetCursorFocus() = 1;
	}

	gMuClientApi.SetBlend(1);

	// Borde exterior
	glColor4f(0.4f, 0.4f, 0.4f, 1.0f);
	gMuClientApi.DrawBarForm(btnX, btnY, btnW, btnH, 0.0f, 0);

	// Fondo del boton
	if (isHover)
		glColor4f(0.1f, 0.15f, 0.3f, 0.95f);
	else
		glColor4f(0.0f, 0.0f, 0.0f, 0.9f);

	gMuClientApi.DrawBarForm(btnX + 1, btnY + 1, btnW - 2, btnH - 2, 0.0f, 0);

	// Efecto de brillo superior
	glColor4f(1.0f, 1.0f, 1.0f, isHover ? 0.15f : 0.05f);
	gMuClientApi.DrawBarForm(btnX + 1, btnY + 1, btnW - 2, btnH / 2.0f, 0.0f, 0);

	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();

	// Texto del boton
	DWORD textColor = isHover ? g_muColors.White : pButton->TextColor;
	gUIBase.DrawFormat(textColor, (int)btnX, (int)btnY + 5, (int)btnW, 3, pButton->Name);

	glPopAttrib();
}

// -------------------------------------------------------------------------------
// Detectar si el mouse esta sobre un rectangulo
// -------------------------------------------------------------------------------

bool CCustomMenu::IsMouseOver(float x, float y, float width, float height)
{
	int mouseX = gMuClientApi.CursorX();
	int mouseY = gMuClientApi.CursorY();
	return (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);
}

// -------------------------------------------------------------------------------
// Detectar click del mouse
// -------------------------------------------------------------------------------

bool CCustomMenu::IsMouseClicked()
{
	int playerState = gMuClientApi.PlayerState();
	if (playerState != 5)
		return false;

	bool isPressed = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;
	bool clicked = isPressed && !m_wasMousePressed;
	m_wasMousePressed = isPressed;

	if (clicked)
	{
		DWORD currentTime = GetTickCount();
		if (currentTime - m_lastClickTime < 200)
			return false;

		m_lastClickTime = currentTime;
	}
	return clicked;
}

// -------------------------------------------------------------------------------
// Manejo de input
// -------------------------------------------------------------------------------

void CCustomMenu::ProcessInput()
{
	if (!IsMouseClicked())
		return;

	// Verificar click en cada boton visible
	for (int i = 0; i < MAX_CUSTOM_MENU_BUTTONS; i++)
	{
		if (!m_buttons[i].Visible || !m_buttons[i].Enabled)
			continue;

		if (IsMouseOver(m_buttons[i].X, m_buttons[i].Y, m_buttons[i].Width, m_buttons[i].Height))
		{
			ExecuteButtonAction(m_buttons[i].Type);
			gMuClientApi.SetCursorFocus() = 1;
			return;
		}
	}
}

// -------------------------------------------------------------------------------
// Ejecutar accion del boton
// -------------------------------------------------------------------------------

void CCustomMenu::ExecuteButtonAction(int buttonType)
{
	switch (buttonType)
	{
		case MENU_BUTTON_EVENTTIME:
		{
			// Abrir/cerrar panel de CustomEventTime
			gCustomEventTime.OpenWindow();
			break;
		}

		case MENU_BUTTON_CUSTOM1:
		{
			// Accion para boton personalizable 1
			// TODO: Implementar segun necesidad
			break;
		}

		case MENU_BUTTON_CUSTOM2:
		{
			// Accion para boton personalizable 2
			// TODO: Implementar segun necesidad
			break;
		}

		case MENU_BUTTON_CUSTOM3:
		{
			// Accion para boton personalizable 3
			// TODO: Implementar segun necesidad
			break;
		}

		case MENU_BUTTON_CUSTOM4:
		{
			// Accion para boton personalizable 4
			// TODO: Implementar segun necesidad
			break;
		}

		default:
			break;
	}
}
