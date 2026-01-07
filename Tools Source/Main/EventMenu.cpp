#include "stdafx.h"
#include "EventMenu.h"
#include "MuClientAPI.h"
#include "MuConstants.h"
#include "UIBase.h"
#include "Protocol.h"
#include <ctime>
#include <sstream>
#include <iomanip>

CEventMenu gEventMenu;
// Funcion externa llamada por Protocol.cpp cuando se reciben datos de eventos
void ProcessEventScheduleData(PMSG_EVENT_SCHEDULE_INFO_RECV* lpMsg)
{
	if (lpMsg == nullptr)
		return;
	EVENT_SCHEDULE_DATA* pData = (EVENT_SCHEDULE_DATA*)(((BYTE*)lpMsg) + sizeof(PMSG_EVENT_SCHEDULE_INFO_RECV));
	gEventMenu.OnEventScheduleReceived(lpMsg->EventCount, pData);
}

CEventMenu::CEventMenu()
{
	m_isOpen = false;
	m_initialized = false;
	m_wasMousePressed = false;
	m_lastClickTime = 0;
	m_lastUpdateTick = 0;
	m_requestPending = false;
	m_lastServerUpdate = 0;
	m_hasServerData = false;
	m_buttonX = 490.0f;
	m_buttonY = 20.0f;
	m_buttonWidth = 80.0f;
	m_buttonHeight = 15.0f;
	m_panelWidth = 250.0f;
	m_panelHeight = 280.0f;
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

	RequestServerUpdate();
	m_initialized = true;
}

void CEventMenu::RequestServerUpdate()
{
	if (m_requestPending)
		return;

	// Verificar que estemos conectados (PlayerState == 5 significa en juego)
	int playerState = gMuClientApi.PlayerState();
	if (playerState != 5)
		return;

	{
		char debug[256];
		sprintf_s(debug, "[EventMenu] RequestServerUpdate blocked - PlayerState=%d (need 5)\n", playerState);
		std::cout << debug << std::endl;
		return;
	}

	std::cout << "[EventMenu] Sending CGEventScheduleRequestSend\n" << std::endl;

	CGEventScheduleRequestSend();
	m_requestPending = true;
}

void CEventMenu::OnEventScheduleReceived(BYTE eventCount, void* pEventData)
{
	m_requestPending = false;
	m_lastServerUpdate = GetTickCount();
	m_hasServerData = true;
	m_events.clear();

	if (eventCount == 0 || pEventData == nullptr)
		return;

	EVENT_SCHEDULE_DATA* pData = (EVENT_SCHEDULE_DATA*)pEventData;

	for (BYTE i = 0; i < eventCount && i < MAX_EVENT_SCHEDULE_INFO; i++)
	{
		EVENT_SCHEDULE_INFO eventInfo;
		eventInfo.Name = pData[i].EventName;
		eventInfo.EventType = pData[i].EventType;
		eventInfo.State = pData[i].State;
		eventInfo.Color = GetEventColor(pData[i].EventType);

		// Determinar si esta activo (estados 2=STAND o 3=START indican que esta proximo o activo)
		eventInfo.IsActive = (pData[i].State >= 2 && pData[i].State <= 3);

		// Formatear tiempo restante
		if (pData[i].RemainTime > 0)
		{
			eventInfo.NextTime = FormatTimeRemainingSeconds(pData[i].RemainTime);
		}
		else
		{
			// Si el tiempo es 0, mostrar el estado
			switch (pData[i].State)
			{
			case 0: eventInfo.NextTime = "Disabled"; break;
			case 1: eventInfo.NextTime = "Waiting"; break;
			case 2: eventInfo.NextTime = "Open"; eventInfo.IsActive = true; break;
			case 3: eventInfo.NextTime = "In Progress"; eventInfo.IsActive = true; break;
			case 4: eventInfo.NextTime = "Ending"; break;
			default: eventInfo.NextTime = "Active"; break;
			}
		}
		m_events.push_back(eventInfo);
	}

	char debug[256];
	sprintf_s(debug, "[EventMenu] Received %d events from server\n", eventCount);
	std::cout << debug << std::endl;
}

DWORD CEventMenu::GetEventColor(BYTE eventType)
{
	switch (eventType)
	{
	case EVENT_TYPE_BLOOD_CASTLE:     return g_muColors.Red;
	case EVENT_TYPE_DEVIL_SQUARE:     return g_muColors.Blue;
	case EVENT_TYPE_CHAOS_CASTLE:     return g_muColors.Purple;
	case EVENT_TYPE_ILLUSION_TEMPLE:  return g_muColors.Cyan;
	case EVENT_TYPE_CRYWOLF:          return g_muColors.Orange;
	case EVENT_TYPE_KANTURU:          return g_muColors.Yellow;
	case EVENT_TYPE_IMPERIAL_GUARDIAN:return g_muColors.Green;
	case EVENT_TYPE_DOUBLE_GOER:      return g_muColors.Pink;
	case EVENT_TYPE_RAKLION:          return g_muColors.LightGray;
	case EVENT_TYPE_INVASION:         return g_muColors.Orange;
	default:                          return g_muColors.White;
	}
}

void CEventMenu::UpdateEventSchedules()
{
	DWORD currentTick = GetTickCount();

	// Solicitar actualizacion cada 10 segundos
	if (currentTick - m_lastUpdateTick < 10000 && m_hasServerData)
		return;

	m_lastUpdateTick = currentTick;
	RequestServerUpdate();
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

std::string CEventMenu::FormatTimeRemainingSeconds(int totalSeconds)
{
	std::stringstream ss;
	if (totalSeconds >= 24 * 60 * 60)
	{
		int days = totalSeconds / (24 * 60 * 60);
		int hours = (totalSeconds % (24 * 60 * 60)) / 3600;
		ss << days << "d " << hours << "h";
	}
	else if (totalSeconds >= 3600)
	{
		int hours = totalSeconds / 3600;
		int minutes = (totalSeconds % 3600) / 60;
		ss << hours << "h " << std::setfill('0') << std::setw(2) << minutes << "m";
	}
	else if (totalSeconds >= 60)
	{
		int minutes = totalSeconds / 60;
		int seconds = totalSeconds % 60;
		ss << minutes << "m " << std::setfill('0') << std::setw(2) << seconds << "s";
	}
	else
	{
		ss << totalSeconds << "s";
	}

	return ss.str();
}

void CEventMenu::Render()
{
	if (!m_initialized)
		Initialize();

	// --- BLOQUEO DE CLICK HACIA EL FONDO ---
	if (IsMouseOver(m_buttonX, m_buttonY, m_buttonWidth, m_buttonHeight))
	{
		gMuClientApi.SetCursorFocus() = 1;
	}
	else if (m_isOpen && IsMouseOver(m_panelX, m_panelY, m_panelWidth, m_panelHeight))
	{
		gMuClientApi.SetCursorFocus() = 1;
	}

	// Verificar ventanas criticas
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
	glColor4f(0.4f, 0.4f, 0.4f, 1.0f);
	gMuClientApi.DrawBarForm(btnX, btnY, btnW, btnH, 0.0f, 0);

	if (isHover)
		glColor4f(0.1f, 0.15f, 0.3f, 0.95f);
	else
		glColor4f(0.0f, 0.0f, 0.0f, 0.9f);

	gMuClientApi.DrawBarForm(btnX + 1, btnY + 1, btnW - 2, btnH - 2, 0.0f, 0);
	glColor4f(1.0f, 1.0f, 1.0f, isHover ? 0.15f : 0.05f);
	gMuClientApi.DrawBarForm(btnX + 1, btnY + 1, btnW - 2, btnH / 2.0f, 0.0f, 0);
	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();

	char text[64];
	sprintf_s(text, "EVENTOS (%d)", (int)m_events.size());
	DWORD textColor = isHover ? g_muColors.White : g_muColors.Gold;
	gUIBase.DrawFormat(textColor, (int)btnX, (int)btnY + 5, (int)btnW, 3, text);
	glPopAttrib();
}

void CEventMenu::DrawEventPanel()
{
	float fBaseW = 640.0f;
	float fBaseH = 480.0f;
	m_panelWidth = 250.0f;
	float rowHeight = 22.0f;

	m_panelHeight = 50.0f + (m_events.size() * rowHeight);
	m_panelX = (fBaseW - m_panelWidth) / 2.0f;
	m_panelY = (fBaseH - m_panelHeight) / 2.0f;

	glPushAttrib(GL_ALL_ATTRIB_BITS);
	gMuClientApi.SetBlend(1);
	glColor4f(0.5f, 0.4f, 0.2f, 1.0f);
	gMuClientApi.DrawBarForm(m_panelX - 1, m_panelY - 1, m_panelWidth + 2, m_panelHeight + 2, 0, 0);
	glColor4f(0.0f, 0.0f, 0.0f, 0.95f);
	gMuClientApi.DrawBarForm(m_panelX, m_panelY, m_panelWidth, m_panelHeight, 0, 0);
	glColor4f(0.15f, 0.15f, 0.15f, 1.0f);
	gMuClientApi.DrawBarForm(m_panelX + 2, m_panelY + 2, m_panelWidth - 4, 25.0f, 0, 0);

	float closeSize = 15.0f;
	float cX = m_panelX + m_panelWidth - closeSize - 5;
	float cY = m_panelY + 5;
	bool isCloseHover = IsMouseOver(cX, cY, closeSize, closeSize);

	glColor4f(isCloseHover ? 1.0f : 0.7f, 0.1f, 0.1f, 1.0f);
	gMuClientApi.DrawBarForm(cX, cY, closeSize, closeSize, 0, 0);
	gMuClientApi.GLSwitch();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	gUIBase.DrawFormat(g_muColors.Gold, (int)m_panelX, (int)m_panelY + 10, (int)m_panelWidth, 3, "HORARIOS DE EVENTOS");
	gUIBase.DrawFormat(g_muColors.White, (int)cX, (int)cY + 2, (int)closeSize, 3, "X");

	float currentY = m_panelY + 40.0f;
	for (size_t i = 0; i < m_events.size(); i++)
	{
		gUIBase.DrawFormat(m_events[i].Color, (int)m_panelX + 15, (int)currentY, 120, 1, (char*)m_events[i].Name.c_str());
		DWORD timeColor = m_events[i].IsActive ? g_muColors.Green : g_muColors.White;
		gUIBase.DrawFormat(timeColor, (int)(m_panelX + m_panelWidth - 100), (int)currentY, 85, 4, (char*)m_events[i].NextTime.c_str());
		currentY += rowHeight;

		if (m_events.empty())
		{
			// Mostrar mensaje cuando no hay eventos
			if (m_requestPending)
			{
				gUIBase.DrawFormat(g_muColors.Yellow, (int)m_panelX + 15, (int)currentY, (int)m_panelWidth - 30, 3, "Cargando eventos...");
			}
			else if (!m_hasServerData)
			{
				gUIBase.DrawFormat(g_muColors.Orange, (int)m_panelX + 15, (int)currentY, (int)m_panelWidth - 30, 3, "Esperando respuesta...");
			}
			else
			{
				gUIBase.DrawFormat(g_muColors.Gray190, (int)m_panelX + 15, (int)currentY, (int)m_panelWidth - 30, 3, "No hay eventos activos");
			}
		}
		else
		{
			for (size_t i = 0; i < m_events.size(); i++)
			{
				gUIBase.DrawFormat(m_events[i].Color, (int)m_panelX + 15, (int)currentY, 120, 1, (char*)m_events[i].Name.c_str());
				DWORD timeColor = m_events[i].IsActive ? g_muColors.Green : g_muColors.White;
				gUIBase.DrawFormat(timeColor, (int)(m_panelX + m_panelWidth - 100), (int)currentY, 85, 4, (char*)m_events[i].NextTime.c_str());

				currentY += rowHeight;
			}
		}
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
	int mouseX = gMuClientApi.CursorX();
	int mouseY = gMuClientApi.CursorY();
	return (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);
}

void CEventMenu::ProcessInput()
{
	if (IsMouseClicked())
	{
		if (IsMouseOver(m_buttonX, m_buttonY, m_buttonWidth, m_buttonHeight))
		{
			Toggle();
			gMuClientApi.SetCursorFocus() = 1;
			return;
		}

		if (m_isOpen)
		{
			float closeSize = 15.0f;
			float cX = m_panelX + m_panelWidth - closeSize - 5;
			float cY = m_panelY + 5;
			if (IsMouseOver(cX, cY, closeSize, closeSize))
			{
				m_isOpen = false;
				gMuClientApi.SetCursorFocus() = 0;
				return;
			}
			if (IsMouseOver(m_panelX, m_panelY, m_panelWidth, m_panelHeight))
			{
				return;
			}

			m_isOpen = false;
			gMuClientApi.SetCursorFocus() = 0;
		}
	}

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
	std::cout << debug << std::endl;

	if (m_isOpen)
	{
		m_lastUpdateTick = 0;
		RequestServerUpdate();
		gMuClientApi.SetCursorFocus() = 1;
	}
	else
	{
		gMuClientApi.SetCursorFocus() = 0;
	}
}