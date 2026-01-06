#include "stdafx.h"
#include "EventMenu.h"
#include "MuClientAPI.h"
#include "MuConstants.h"
#include "UIBase.h"
#include <ctime>
#include <sstream>
#include <iomanip>

#define RenderColor(r, g, b, a) ((DWORD)((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))
// -------------------------------------------------------------------------------
// Instancia global
// -------------------------------------------------------------------------------
CEventMenu gEventMenu;

// -------------------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------------------
CEventMenu::CEventMenu()
{
	m_isOpen = false;
	m_initialized = false;
	m_wasMousePressed = false;
	m_lastClickTime = 0;
	m_lastUpdateTick = 0;
	// Posicion del boton (esquina superior derecha, debajo del ping)
	m_buttonX = 640.0f - 80.0f;  // Ajustar segun resolucion
	m_buttonY = 20.0f;
	m_buttonWidth = 70.0f;
	m_buttonHeight = 20.0f;
	// Posicion del panel (centrado)
	m_panelX = 200.0f;
	m_panelY = 100.0f;
	m_panelWidth = 250.0f;
	m_panelHeight = 280.0f;
}

// -------------------------------------------------------------------------------

// Destructor

// -------------------------------------------------------------------------------

CEventMenu::~CEventMenu()
{
	m_events.clear();
}

// -------------------------------------------------------------------------------

// Inicializacion

// -------------------------------------------------------------------------------

void CEventMenu::Initialize()
{
	if (m_initialized)
		return;
	// Inicializar lista de eventos con horarios de ejemplo
	// Estos horarios pueden ser cargados desde un archivo de configuracion
	// o recibidos del servidor via paquete custom
	UpdateEventSchedules();
	m_initialized = true;
}

// -------------------------------------------------------------------------------
// Actualizar horarios de eventos
// -------------------------------------------------------------------------------

void CEventMenu::UpdateEventSchedules()
{
	// Actualizar cada 30 segundos
	DWORD currentTick = GetTickCount();
	if (currentTick - m_lastUpdateTick < 30000 && !m_events.empty())
		return;
	m_lastUpdateTick = currentTick;
	m_events.clear();
	// Obtener hora actual
	time_t now = time(nullptr);
	struct tm localTime;
	localtime_s(&localTime, &now);
	int currentHour = localTime.tm_hour;
	int currentMinute = localTime.tm_min;

	// =====================================================
	// CONFIGURACION DE HORARIOS DE EVENTOS
	// Modifica estos horarios segun tu servidor
	// =====================================================
	// Blood Castle - cada 2 horas (00:00, 02:00, 04:00, etc.)

	EVENT_SCHEDULE_INFO bcEvent;
	bcEvent.Name = "Blood Castle";
	bcEvent.Color = g_muColors.Red;
	bcEvent.IsActive = false;
	{
		int nextHour = ((currentHour / 2) + 1) * 2;
		if (nextHour >= 24) nextHour = 0;
		int minutesLeft = (nextHour - currentHour) * 60 - currentMinute;
		if (minutesLeft <= 0) minutesLeft += 120;
		bcEvent.NextTime = FormatTimeRemaining(minutesLeft);
		if (minutesLeft <= 5) bcEvent.IsActive = true;
	}

	m_events.push_back(bcEvent);
	// Devil Square - cada 2 horas desfasado (01:00, 03:00, 05:00, etc.)
	EVENT_SCHEDULE_INFO dsEvent;
	dsEvent.Name = "Devil Square";
	dsEvent.Color = g_muColors.Blue;
	dsEvent.IsActive = false;
	{
		int nextHour = ((currentHour / 2) * 2) + 1;
		if (nextHour <= currentHour) nextHour += 2;
		if (nextHour >= 24) nextHour -= 24;
		int minutesLeft = (nextHour - currentHour) * 60 - currentMinute;
		if (minutesLeft <= 0) minutesLeft += 120;
		dsEvent.NextTime = FormatTimeRemaining(minutesLeft);
		if (minutesLeft <= 5) dsEvent.IsActive = true;
	}

	m_events.push_back(dsEvent);
	// Chaos Castle - cada 2 horas (00:30, 02:30, 04:30, etc.)
	EVENT_SCHEDULE_INFO ccEvent;
	ccEvent.Name = "Chaos Castle";
	ccEvent.Color = g_muColors.Socket;
	ccEvent.IsActive = false;
	{
		int nextHour = (currentHour / 2) * 2;
		int nextMinute = 30;
		if (currentHour % 2 == 0 && currentMinute >= 30) nextHour += 2;
		if (currentHour % 2 == 1) nextHour += 2;
		if (nextHour >= 24) nextHour -= 24;
		int minutesLeft = (nextHour - currentHour) * 60 + (nextMinute - currentMinute);
		if (minutesLeft <= 0) minutesLeft += 120;
		ccEvent.NextTime = FormatTimeRemaining(minutesLeft);
		if (minutesLeft <= 5) ccEvent.IsActive = true;
	}

	m_events.push_back(ccEvent);
	// Illusion Temple - cada 3 horas
	EVENT_SCHEDULE_INFO itEvent;
	itEvent.Name = "Illusion Temple";
	itEvent.Color = g_muColors.Yellow;
	itEvent.IsActive = false;
	{
		int nextHour = ((currentHour / 3) + 1) * 3;
		if (nextHour >= 24) nextHour -= 24;
		int minutesLeft = (nextHour - currentHour) * 60 - currentMinute;
		if (minutesLeft <= 0) minutesLeft += 180;
		itEvent.NextTime = FormatTimeRemaining(minutesLeft);
		if (minutesLeft <= 5) itEvent.IsActive = true;
	}

	m_events.push_back(itEvent);
	// Crywolf - 21:00 cada dia
	EVENT_SCHEDULE_INFO cwEvent;
	cwEvent.Name = "Crywolf";
	cwEvent.Color = g_muColors.Excellent;
	cwEvent.IsActive = false;
	{
		int targetHour = 21;
		int minutesLeft = (targetHour - currentHour) * 60 - currentMinute;
		if (minutesLeft <= 0) minutesLeft += 24 * 60;
		cwEvent.NextTime = FormatTimeRemaining(minutesLeft);
		if (minutesLeft <= 10) cwEvent.IsActive = true;
	}

	m_events.push_back(cwEvent);
	// Castle Siege - Domingo 20:00
	EVENT_SCHEDULE_INFO csEvent;
	csEvent.Name = "Castle Siege";
	csEvent.Color = g_muColors.Orange;
	csEvent.IsActive = false;
	{
		int daysUntilSunday = (7 - localTime.tm_wday) % 7;
		if (daysUntilSunday == 0 && (currentHour > 20 || (currentHour == 20 && currentMinute > 0)))
			daysUntilSunday = 7;
		int minutesLeft = daysUntilSunday * 24 * 60 + (20 - currentHour) * 60 - currentMinute;
		if (minutesLeft < 0) minutesLeft += 7 * 24 * 60;
		csEvent.NextTime = FormatTimeRemaining(minutesLeft);
	}

	m_events.push_back(csEvent);
	// Kanturu - cada 4 horas
	EVENT_SCHEDULE_INFO ktEvent;
	ktEvent.Name = "Kanturu";
	ktEvent.Color = g_muColors.Ancient;
	ktEvent.IsActive = false;
	{
		int nextHour = ((currentHour / 4) + 1) * 4;
		if (nextHour >= 24) nextHour -= 24;
		int minutesLeft = (nextHour - currentHour) * 60 - currentMinute;
		if (minutesLeft <= 0) minutesLeft += 240;
		ktEvent.NextTime = FormatTimeRemaining(minutesLeft);
		if (minutesLeft <= 10) ktEvent.IsActive = true;
	}

	m_events.push_back(ktEvent);
	// Raklion - cada 6 horas
	EVENT_SCHEDULE_INFO rkEvent;
	rkEvent.Name = "Raklion";
	rkEvent.Color = g_muColors.Blue250;
	rkEvent.IsActive = false;
	{
		int nextHour = ((currentHour / 6) + 1) * 6;
		if (nextHour >= 24) nextHour -= 24;
		int minutesLeft = (nextHour - currentHour) * 60 - currentMinute;
		if (minutesLeft <= 0) minutesLeft += 360;
		rkEvent.NextTime = FormatTimeRemaining(minutesLeft);
		if (minutesLeft <= 10) rkEvent.IsActive = true;
	}

	m_events.push_back(rkEvent);
}

// -------------------------------------------------------------------------------
// Formatear tiempo restante
// -------------------------------------------------------------------------------

std::string CEventMenu::FormatTimeRemaining(int totalMinutes)
{
	std::stringstream ss;

	if (totalMinutes >= 24 * 60)
	{
		int days = totalMinutes / (24 * 60);
		int hours = (totalMinutes % (24 * 60)) / 60;
		ss << days << "d " << hours << "h";
	}
	else if (totalMinutes >= 60)
	{
		int hours = totalMinutes / 60;
		int minutes = totalMinutes % 60;
		ss << hours << "h " << std::setfill('0') << std::setw(2) << minutes << "m";
	}
	else
	{
		ss << totalMinutes << " min";
	}

	return ss.str();
}

// -------------------------------------------------------------------------------
// Renderizado principal
// -------------------------------------------------------------------------------

void CEventMenu::Render()
{
	// ═══════════════════════════════════════════
	// VERIFICACIONES DE SEGURIDAD
	// ═══════════════════════════════════════════

	// 1. Verificar que estamos en el juego
	if (gMuClientApi.PlayerState() != static_cast<int>(GameState::GameProcess))
		return;

	// 2. Verificar que no hay ventanas críticas abiertas
	if (gUIBase.CheckWindow(static_cast<int>(WindowType::CashShop)) ||
		gUIBase.CheckWindow(static_cast<int>(WindowType::FullMap)) ||
		gUIBase.CheckWindow(static_cast<int>(WindowType::Store)) ||
		gUIBase.CheckWindow(static_cast<int>(WindowType::Inventory)))
	{
		if (m_isOpen)
		{
			m_isOpen = false;
			gMuClientApi.SetCursorFocus() = 0;
		}
		// Solo dibujar el botón, no el panel
		if (!m_initialized)
			Initialize();
		DrawButton();
		return;
	}

	if (!m_initialized)
		Initialize();

	// Procesar input primero
	ProcessInput();

	// Siempre dibujar el boton
	DrawButton();

	// Dibujar panel si esta abierto
	if (m_isOpen)
	{
		UpdateEventSchedules();
		DrawEventPanel();
	}
}

// -------------------------------------------------------------------------------

// Dibujar el boton principal

// -------------------------------------------------------------------------------

void CEventMenu::DrawButton()
{
	// Obtener posicion ajustada a la resolucion
	float screenWidth = (float)gMuClientApi.WinWidth();
	float btnX = screenWidth - 90.0f;
	float btnY = 20.0f;
	float btnW = 80.0f;
	float btnH = 18.0f;

	// Guardar posicion para deteccion de clicks
	m_buttonX = btnX;
	m_buttonY = btnY;
	m_buttonWidth = btnW;
	m_buttonHeight = btnH;

	// Color del boton (cambia si el mouse esta encima)
	bool isHover = IsMouseOver(btnX, btnY, btnW, btnH);

	// Fondo del boton
	gMuClientApi.SetBlend(1);

	if (isHover)
		glColor4f(0.2f, 0.2f, 0.4f, 0.9f);
	else if (m_isOpen)
		glColor4f(0.1f, 0.3f, 0.1f, 0.9f);
	else
		glColor4f(0.0f, 0.0f, 0.0f, 0.8f);

	gMuClientApi.DrawBarForm(btnX, btnY, btnW, btnH, 0.0f, 0);
	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	// Borde del boton
	gMuClientApi.SetBlend(1);
	glColor4f(0.6f, 0.6f, 0.6f, 1.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(btnX, btnY);
	glVertex2f(btnX + btnW, btnY);
	glVertex2f(btnX + btnW, btnY + btnH);
	glVertex2f(btnX, btnY + btnH);
	glEnd();

	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	// Texto del boton
	DWORD textColor = isHover ? g_muColors.Yellow : g_muColors.Gold;
	gUIBase.DrawFormat(textColor, (int)btnX + 5, (int)btnY + 3, (int)btnW - 10, 0, "EVENTOS");

	gMuClientApi.DrawBarForm(m_buttonX, m_buttonY, m_buttonWidth, m_buttonHeight, 0.0f, RenderColor(0, 0, 0, 150));
	gMuClientApi.DrawColorText("Eventos", (int)m_buttonX, (int)m_buttonY + 5, (int)m_buttonWidth, 0, 0, 1, 0);
}

// -------------------------------------------------------------------------------
// Dibujar el panel de eventos
// -------------------------------------------------------------------------------

void CEventMenu::DrawEventPanel()
{
	// Centrar el panel en pantalla
	float screenWidth = (float)gMuClientApi.WinWidth();
	float screenHeight = (float)gMuClientApi.WinHeight();
	float panelW = 260.0f;
	float panelH = 30.0f + (m_events.size() * 28.0f) + 20.0f;  // Header + eventos + padding
	float panelX = (screenWidth - panelW) / 2.0f;
	float panelY = (screenHeight - panelH) / 2.0f;

	// Guardar posicion del panel
	m_panelX = panelX;
	m_panelY = panelY;
	m_panelWidth = panelW;
	m_panelHeight = panelH;

	// Fondo del panel
	gMuClientApi.SetBlend(1);
	glColor4f(0.05f, 0.05f, 0.1f, 0.95f);
	gMuClientApi.DrawBarForm(panelX, panelY, panelW, panelH, 0.0f, 0);
	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	// Borde del panel
	gMuClientApi.SetBlend(1);
	glColor4f(0.5f, 0.4f, 0.2f, 1.0f);
	glLineWidth(2.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(panelX, panelY);
	glVertex2f(panelX + panelW, panelY);
	glVertex2f(panelX + panelW, panelY + panelH);
	glVertex2f(panelX, panelY + panelH);
	glEnd();

	glLineWidth(1.0f);
	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	// Titulo del panel
	float titleY = panelY + 8.0f;
	gUIBase.DrawFormat(g_muColors.Gold, (int)panelX + 10, (int)titleY, (int)panelW - 20, 1, "HORARIOS DE EVENTOS");

	// Linea separadora
	gMuClientApi.SetBlend(1);
	glColor4f(0.5f, 0.4f, 0.2f, 0.8f);
	glBegin(GL_LINES);
	glVertex2f(panelX + 10, panelY + 28);
	glVertex2f(panelX + panelW - 10, panelY + 28);
	glEnd();

	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	// Dibujar cada evento
	float eventY = panelY + 38.0f;
	float eventSpacing = 28.0f;

	for (size_t i = 0; i < m_events.size(); i++)
	{
		const EVENT_SCHEDULE_INFO& evt = m_events[i];
		// Fondo alternado para mejor lectura
		if (i % 2 == 0)
		{
			gMuClientApi.SetBlend(1);
			glColor4f(0.1f, 0.1f, 0.15f, 0.5f);
			gMuClientApi.DrawBarForm(panelX + 5, eventY - 2, panelW - 10, eventSpacing - 4, 0.0f, 0);
			gMuClientApi.GLSwitchBlend();
			gMuClientApi.GLSwitch();
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		}
		// Indicador de evento activo
		if (evt.IsActive)
		{
			gMuClientApi.SetBlend(1);
			glColor4f(0.0f, 1.0f, 0.0f, 0.3f);
			gMuClientApi.DrawBarForm(panelX + 5, eventY - 2, panelW - 10, eventSpacing - 4, 0.0f, 0);
			gMuClientApi.GLSwitchBlend();
			gMuClientApi.GLSwitch();
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		}
		// Nombre del evento
		gUIBase.DrawFormat(evt.Color, (int)panelX + 15, (int)eventY + 3, 130, 0, evt.Name.c_str());
		// Tiempo restante
		DWORD timeColor = evt.IsActive ? g_muColors.ShinyGreen : g_muColors.White;
		gUIBase.DrawFormat(timeColor, (int)panelX + 150, (int)eventY + 3, 100, 0, evt.NextTime.c_str());
		eventY += eventSpacing;
	}

	// Boton de cerrar [X]
	float closeX = panelX + panelW - 25;
	float closeY = panelY + 5;
	float closeSize = 18;
	bool closeHover = IsMouseOver(closeX, closeY, closeSize, closeSize);

	gMuClientApi.SetBlend(1);

	if (closeHover)
		glColor4f(0.8f, 0.2f, 0.2f, 0.9f);
	else
		glColor4f(0.4f, 0.1f, 0.1f, 0.9f);

	gMuClientApi.DrawBarForm(closeX, closeY, closeSize, closeSize, 0.0f, 0);
	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	gUIBase.DrawFormat(g_muColors.White, (int)closeX + 5, (int)closeY + 2, (int)closeSize - 10, 0, "X");
}

// -------------------------------------------------------------------------------
// Verificar si el mouse esta sobre un area
// -------------------------------------------------------------------------------

bool CEventMenu::IsMouseOver(float x, float y, float width, float height)
{
	int mouseX = gMuClientApi.CursorX();
	int mouseY = gMuClientApi.CursorY();
	return (mouseX >= x && mouseX <= x + width &&
		mouseY >= y && mouseY <= y + height);
}

// -------------------------------------------------------------------------------
// Verificar si se hizo click
// -------------------------------------------------------------------------------

bool CEventMenu::IsMouseClicked()
{
	// ═══════════════════════════════════════════
	// AGREGAR: Verificar que el juego permite input
	// ═══════════════════════════════════════════
	if (gMuClientApi.PlayerState() != static_cast<int>(GameState::GameProcess))
		return false;

	// Detectar boton izquierdo del mouse
	bool isPressed = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;

	// Detectar flanco de subida (momento del click)
	bool clicked = isPressed && !m_wasMousePressed;
	m_wasMousePressed = isPressed;

	// Anti-spam de clicks
	if (clicked)
	{
		DWORD currentTime = GetTickCount();
		if (currentTime - m_lastClickTime < 200)  // 200ms entre clicks
			return false;
		m_lastClickTime = currentTime;
	}

	return clicked;
}

// -------------------------------------------------------------------------------
// Procesar input del usuario
// -------------------------------------------------------------------------------

void CEventMenu::ProcessInput()
{
	if (IsMouseClicked())
	{
		// Click en el botón principal
		if (IsMouseOver(m_buttonX, m_buttonY, m_buttonWidth, m_buttonHeight))
		{
			Toggle();
			return;
		}

		// Si el menu esta abierto
		if (m_isOpen)
		{
			// Click en boton cerrar [X]
			float closeX = m_panelX + m_panelWidth - 25;
			float closeY = m_panelY + 5;
			if (IsMouseOver(closeX, closeY, 18, 18))
			{
				m_isOpen = false;
				gMuClientApi.SetCursorFocus() = 0;  // ← AGREGAR ESTO
				return;
			}

			// Click fuera del panel cierra el menu
			if (!IsMouseOver(m_panelX, m_panelY, m_panelWidth, m_panelHeight))
			{
				m_isOpen = false;
				gMuClientApi.SetCursorFocus() = 0;  // ← AGREGAR ESTO
				return;
			}
		}
	}

	// Tecla ESC cierra el menu
	if (m_isOpen && (GetAsyncKeyState(VK_ESCAPE) & 0x8000))
	{
		m_isOpen = false;
		gMuClientApi.SetCursorFocus() = 0;  // ← AGREGAR ESTO
	}
}

void CEventMenu::Toggle()
{
	m_isOpen = !m_isOpen;

	if (m_isOpen)
	{
		// Forzar actualizacion de eventos al abrir
		m_lastUpdateTick = 0;
		UpdateEventSchedules();

		// ═══════════════════════════════════════════
		// AGREGAR: Activar cursor focus
		// ═══════════════════════════════════════════
		gMuClientApi.SetCursorFocus() = 1;
	}
	else
	{
		// ═══════════════════════════════════════════
		// AGREGAR: Desactivar cursor focus
		// ═══════════════════════════════════════════
		gMuClientApi.SetCursorFocus() = 0;
	}
}