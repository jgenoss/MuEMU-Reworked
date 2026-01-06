#include "stdafx.h"
#include "EventMenu.h"
#include "MuClientAPI.h"
#include "MuConstants.h"
#include "UIBase.h"
#include <ctime>
#include <sstream>
#include <iomanip>

CEventMenu gEventMenu;

CEventMenu::CEventMenu()
{
	m_isOpen = false;
	m_initialized = false;
	m_wasMousePressed = false;
	m_lastClickTime = 0;
	m_lastUpdateTick = 0;

	m_buttonX = 490.0f;
	m_buttonY = 20.0f;
	m_buttonWidth = 80.0f;
	m_buttonHeight = 15.0f;

	// Definimos el tamaño del panel primero
	m_panelWidth = 250.0f;
	m_panelHeight = 280.0f;

	// LÓGICA DE CENTRADO (Igual que en Reconnect.cpp)
	// MU usa un espacio virtual de 640.0f x 480.0f para la UI
	m_panelX = (640.0f / 2.0f) - (m_panelWidth / 2.0f);
	m_panelY = (480.0f / 2.0f) - (m_panelHeight / 2.0f);
}

CEventMenu::~CEventMenu()
{
	m_events.clear();
}

void CEventMenu::Initialize()
{
	if (m_initialized)
		return;

	UpdateEventSchedules();
	m_initialized = true;
}

void CEventMenu::UpdateEventSchedules()
{
	DWORD currentTick = GetTickCount();
	if (currentTick - m_lastUpdateTick < 30000 && !m_events.empty())
		return;

	m_lastUpdateTick = currentTick;
	m_events.clear();

	time_t now = time(nullptr);
	struct tm localTime;
	localtime_s(&localTime, &now);
	int currentHour = localTime.tm_hour;
	int currentMinute = localTime.tm_min;

	// Blood Castle
	EVENT_SCHEDULE_INFO bcEvent;
	bcEvent.Name = "Blood Castle";
	bcEvent.Color = g_muColors.Red;
	bcEvent.IsActive = false;
	int nextHour = ((currentHour / 2) + 1) * 2;
	if (nextHour >= 24) nextHour = 0;
	int minutesLeft = (nextHour - currentHour) * 60 - currentMinute;
	if (minutesLeft <= 0) minutesLeft += 120;
	bcEvent.NextTime = FormatTimeRemaining(minutesLeft);
	if (minutesLeft <= 5) bcEvent.IsActive = true;
	m_events.push_back(bcEvent);

	// Devil Square
	EVENT_SCHEDULE_INFO dsEvent;
	dsEvent.Name = "Devil Square";
	dsEvent.Color = g_muColors.Blue;
	dsEvent.IsActive = false;
	nextHour = ((currentHour / 2) * 2) + 1;
	if (nextHour <= currentHour) nextHour += 2;
	if (nextHour >= 24) nextHour -= 24;
	minutesLeft = (nextHour - currentHour) * 60 - currentMinute;
	if (minutesLeft <= 0) minutesLeft += 120;
	dsEvent.NextTime = FormatTimeRemaining(minutesLeft);
	if (minutesLeft <= 5) dsEvent.IsActive = true;
	m_events.push_back(dsEvent);
}

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

void CEventMenu::Render()
{
	if (!m_initialized)
		Initialize();

	// --- BLOQUEO DE CLICK HACIA EL FONDO ---
	// Si el mouse está sobre el botón principal
	if (IsMouseOver(m_buttonX, m_buttonY, m_buttonWidth, m_buttonHeight))
	{
		gMuClientApi.SetCursorFocus() = 1;
	}
	// Si el panel está abierto y el mouse está sobre el panel
	else if (m_isOpen && IsMouseOver(m_panelX, m_panelY, m_panelWidth, m_panelHeight))
	{
		gMuClientApi.SetCursorFocus() = 1;
	}
	// ----------------------------------------

	// Verificar ventanas críticas (Cerrar si hay inventario, etc)
	bool criticalWindowOpen = (
		gUIBase.CheckWindow(static_cast<int>(WindowType::CashShop)) ||
		gUIBase.CheckWindow(static_cast<int>(WindowType::FullMap)) ||
		gUIBase.CheckWindow(static_cast<int>(WindowType::Store)) ||
		gUIBase.CheckWindow(static_cast<int>(WindowType::Inventory))
		);

	if (criticalWindowOpen && m_isOpen) {
		m_isOpen = false;
		gMuClientApi.SetCursorFocus() = 0;
	}

	ProcessInput();
	DrawButton();

	if (m_isOpen) {
		UpdateEventSchedules();
		DrawEventPanel();
	}
}

void CEventMenu::DrawButton()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	// Coordenadas fijas para el botón de la esquina
	float btnX = 490.0f;
	float btnY = 17.0f;
	float btnW = 135.0f;
	float btnH = 18.0f;

	m_buttonX = btnX;
	m_buttonY = btnY;
	m_buttonWidth = btnW;
	m_buttonHeight = btnH;

	bool isHover = IsMouseOver(btnX, btnY, btnW, btnH);

	gMuClientApi.SetBlend(1);

	// 1. Borde Exterior (Gris Metálico)
	glColor4f(0.4f, 0.4f, 0.4f, 1.0f);
	gMuClientApi.DrawBarForm(btnX, btnY, btnW, btnH, 0.0f, 0);

	// 2. Fondo (Negro o Azulado si hay Hover)
	if (isHover)
		glColor4f(0.1f, 0.15f, 0.3f, 0.95f); // Azul oscuro sutil
	else
		glColor4f(0.0f, 0.0f, 0.0f, 0.9f);

	gMuClientApi.DrawBarForm(btnX + 1, btnY + 1, btnW - 2, btnH - 2, 0.0f, 0);

	// 3. Efecto de "Cristal" (Brillo en la mitad superior)
	glColor4f(1.0f, 1.0f, 1.0f, isHover ? 0.15f : 0.05f);
	gMuClientApi.DrawBarForm(btnX + 1, btnY + 1, btnW - 2, btnH / 2.0f, 0.0f, 0);

	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();

	// 4. Texto centrado
	char text[64];
	sprintf_s(text, "EVENTOS (%d)", (int)m_events.size());
	DWORD textColor = isHover ? g_muColors.White : g_muColors.Gold;

	// El parámetro '3' en DrawFormat suele ser para centrar horizontalmente
	gUIBase.DrawFormat(textColor, (int)btnX, (int)btnY + 5, (int)btnW, 3, text);

	glPopAttrib();
}

void CEventMenu::DrawEventPanel()
{
	// 1. CONFIGURACIÓN DE ESPACIO VIRTUAL (640x480)
	// -------------------------------------------------------------------------
	float fBaseW = 640.0f;
	float fBaseH = 480.0f;

	m_panelWidth = 230.0f;
	float rowHeight = 22.0f;
	m_panelHeight = 50.0f + (m_events.size() * rowHeight);

	// Centrado exacto
	m_panelX = (fBaseW - m_panelWidth) / 2.0f;
	m_panelY = (fBaseH - m_panelHeight) / 2.0f;

	glPushAttrib(GL_ALL_ATTRIB_BITS);
	gMuClientApi.SetBlend(1);

	// 2. DIBUJO DEL CUERPO (Usamos solo la API para evitar rectángulos extra)
	// -------------------------------------------------------------------------

	// Borde exterior (Simulado con BarForm para no romper el buffer)
	glColor4f(0.5f, 0.4f, 0.2f, 1.0f); // Dorado oscuro
	gMuClientApi.DrawBarForm(m_panelX - 1, m_panelY - 1, m_panelWidth + 2, m_panelHeight + 2, 0, 0);

	// Fondo principal
	glColor4f(0.0f, 0.0f, 0.0f, 0.95f);
	gMuClientApi.DrawBarForm(m_panelX, m_panelY, m_panelWidth, m_panelHeight, 0, 0);

	// Cabecera
	glColor4f(0.15f, 0.15f, 0.15f, 1.0f);
	gMuClientApi.DrawBarForm(m_panelX + 2, m_panelY + 2, m_panelWidth - 4, 25.0f, 0, 0);

	// Botón Cerrar [X] (Coordenadas unificadas con ProcessInput)
	float closeSize = 15.0f;
	float cX = m_panelX + m_panelWidth - closeSize - 5;
	float cY = m_panelY + 5;
	bool isCloseHover = IsMouseOver(cX, cY, closeSize, closeSize);

	glColor4f(isCloseHover ? 1.0f : 0.7f, 0.1f, 0.1f, 1.0f);
	gMuClientApi.DrawBarForm(cX, cY, closeSize, closeSize, 0, 0);

	// 3. RENDERIZADO DE TEXTO (Sincronización Vital)
	// -------------------------------------------------------------------------

	// Sincronizar texturas para fuentes
	gMuClientApi.GLSwitch();

	// Reset de color para que el texto NO sea invisible
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	// Título (Alineación 3 = Centro)
	gUIBase.DrawFormat(g_muColors.Gold, (int)m_panelX, (int)m_panelY + 10, (int)m_panelWidth, 3, "HORARIOS DE EVENTOS");

	// La "X" del botón
	gUIBase.DrawFormat(g_muColors.White, (int)cX, (int)cY + 2, (int)closeSize, 3, "X");

	float currentY = m_panelY + 40.0f;

	for (size_t i = 0; i < m_events.size(); i++)
	{
		// Nombre del Evento (Alineación 1 = Izquierda)
		gUIBase.DrawFormat(m_events[i].Color, (int)m_panelX + 15, (int)currentY, 100, 1, (char*)m_events[i].Name.c_str());

		// Tiempo (Alineación 4 = Derecha)
		DWORD timeColor = m_events[i].IsActive ? g_muColors.Green : g_muColors.White;
		gUIBase.DrawFormat(timeColor, (int)(m_panelX + m_panelWidth - 85), (int)currentY, 70, 4, (char*)m_events[i].NextTime.c_str());

		currentY += rowHeight;
	}

	gMuClientApi.GLSwitchBlend();
	glPopAttrib();
}

bool CEventMenu::IsMouseClicked()
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

bool CEventMenu::IsMouseOver(float x, float y, float width, float height)
{
	// Obtenemos la posición real del mouse desde la API del cliente
	int mouseX = gMuClientApi.CursorX();
	int mouseY = gMuClientApi.CursorY();

	// Verificamos si el mouse está dentro del recuadro
	return (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);
}

void CEventMenu::ProcessInput()
{
	if (IsMouseClicked())
	{
		// Click en el Botón Principal
		if (IsMouseOver(m_buttonX, m_buttonY, m_buttonWidth, m_buttonHeight))
		{
			Toggle();
			// Importante: Al hacer click, forzamos el focus para evitar el movimiento
			gMuClientApi.SetCursorFocus() = 1;
			return;
		}

		if (m_isOpen)
		{
			// Click en botón Cerrar [X]
			float closeSize = 15.0f;
			float cX = m_panelX + m_panelWidth - closeSize - 5;
			float cY = m_panelY + 5;

			if (IsMouseOver(cX, cY, closeSize, closeSize))
			{
				m_isOpen = false;
				gMuClientApi.SetCursorFocus() = 0;
				return;
			}

			// Si hacemos click dentro del panel (pero no en botones), bloqueamos el fondo
			if (IsMouseOver(m_panelX, m_panelY, m_panelWidth, m_panelHeight))
			{
				return; // Consumimos el click para que no se mueva el personaje
			}

			// Si hacemos click fuera del panel estando abierto, lo cerramos
			m_isOpen = false;
			gMuClientApi.SetCursorFocus() = 0;
		}
	}

	// Tecla ESC para cerrar
	if (m_isOpen && (GetAsyncKeyState(VK_ESCAPE) & 0x8000))
	{
		m_isOpen = false;
		gMuClientApi.SetCursorFocus() = 0;
	}
}

void CEventMenu::Toggle()
{
	m_isOpen = !m_isOpen;

	char debug[256];
	sprintf_s(debug, "[EventMenu] Toggled: %s\n", m_isOpen ? "OPEN" : "CLOSED");
	OutputDebugStringA(debug);

	if (m_isOpen)
	{
		m_lastUpdateTick = 0;
		UpdateEventSchedules();
		gMuClientApi.SetCursorFocus() = 1;
	}
	else
	{
		gMuClientApi.SetCursorFocus() = 0;
	}
}