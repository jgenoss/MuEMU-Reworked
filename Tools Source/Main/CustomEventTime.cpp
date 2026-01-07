// CustomEventTime.cpp: implementation of the CCustomEventTime class (Client)
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CustomEventTime.h"
#include "MuClientAPI.h"
#include "MuConstants.h"
#include "UIBase.h"
#include "Protocol.h"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <iostream>

CCustomEventTime gCustomEventTime;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomEventTime::CCustomEventTime()
{
	this->Init();
}

CCustomEventTime::~CCustomEventTime()
{
}

void CCustomEventTime::Init()
{
	this->m_Page = 0;
	this->m_Arena = 0;
	this->m_EventTimeLoad = 0;
	this->m_EventTimeEnable = 0;
	this->m_EventTimeTickCount = 0;
	this->m_count = 0;
	this->m_isOpen = false;
	this->m_LastRequestTick = 0;

	for (int n = 0; n < MAX_EVENTTIME; n++)
	{
		this->m_CustomEventInfo[n].Index = -1;
		memset(this->m_CustomEventInfo[n].Name, 0, sizeof(this->m_CustomEventInfo[n].Name));
		this->m_gCustomEventTime[n].index = -1;
		this->m_gCustomEventTime[n].time = -1;
	}
}

void CCustomEventTime::Load(CUSTOM_EVENT_INFO* info)
{
	for (int n = 0; n < MAX_EVENTTIME; n++)
	{
		this->SetInfo(info[n]);
	}
}

void CCustomEventTime::SetInfo(CUSTOM_EVENT_INFO info)
{
	if (info.Index < 0 || info.Index >= MAX_EVENTTIME)
	{
		return;
	}

	this->m_CustomEventInfo[info.Index] = info;
}

void CCustomEventTime::ClearCustomEventTime()
{
	for (int n = 0; n < MAX_EVENTTIME; n++)
	{
		this->m_gCustomEventTime[n].time = -1;
	}

	this->m_count = 0;
	this->m_EventTimeEnable = 0;
}

void CCustomEventTime::RequestEventTime()
{
	// Anti-spam: 1 segundo entre requests
	DWORD currentTick = GetTickCount();
	if (currentTick - this->m_LastRequestTick < 1000)
	{
		return;
	}

	this->m_LastRequestTick = currentTick;

	// Verificar que estemos conectados
	int playerState = gMuClientApi.PlayerState();
	if (playerState != 5)
	{
		return;
	}

	PMSG_CUSTOM_EVENTTIME_SEND pMsg;
	pMsg.header.set(0xF3, 0xE8, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CCustomEventTime::GCReqEventTime(PMSG_CUSTOM_EVENTTIME_RECV* lpMsg)
{
	this->m_count = lpMsg->count;
	this->m_Arena = 0;

	for (int n = 0; n < lpMsg->count && n < MAX_EVENTTIME; n++)
	{
		CUSTOM_EVENTTIME_DATA* lpInfo = (CUSTOM_EVENTTIME_DATA*)(((BYTE*)lpMsg) +
			sizeof(PMSG_CUSTOM_EVENTTIME_RECV) + (sizeof(CUSTOM_EVENTTIME_DATA) * n));

		this->m_gCustomEventTime[n].index = lpInfo->index;
		this->m_gCustomEventTime[n].time = lpInfo->time;

		// Detectar si hay eventos de Arena
		if (this->m_gCustomEventTime[n].index >= 28 && this->m_gCustomEventTime[n].time != -1)
		{
			this->m_Arena = 1;
		}
	}

	this->m_EventTimeEnable = 1;

	std::cout << "[CustomEventTime] Received " << lpMsg->count << " events from server" << std::endl;
}

void CCustomEventTime::OpenWindow()
{
	// Verificar ventanas conflictivas
	if (gUIBase.CheckWindow(static_cast<int>(WindowType::CashShop)) ||
		gUIBase.CheckWindow(static_cast<int>(WindowType::Store)) ||
		gUIBase.CheckWindow(static_cast<int>(WindowType::Trade)))
	{
		return;
	}

	// Anti-spam: 1 segundo entre aperturas
	DWORD currentTick = GetTickCount();
	if (currentTick - this->m_LastRequestTick < 1000)
	{
		return;
	}

	// Toggle ventana
	if (this->m_isOpen)
	{
		this->m_isOpen = false;
		gMuClientApi.SetCursorFocus() = 0;
		return;
	}

	// Limpiar datos y solicitar nuevos
	this->ClearCustomEventTime();
	this->RequestEventTime();

	this->m_isOpen = true;
	gMuClientApi.SetCursorFocus() = 1;
}

void CCustomEventTime::DrawEventTimePanelWindow()
{
	if (!this->m_isOpen)
	{
		return;
	}

	// Verificar estado del jugador
	int playerState = gMuClientApi.PlayerState();
	if (playerState != 5)
	{
		this->m_isOpen = false;
		return;
	}

	float MainWidth = 250.0f;
	float MainHeight = 300.0f;
	float StartBody = 80.0f;
	float StartY = 80.0f;
	float StartX = (640.0f / 2.0f) - (MainWidth / 2.0f);

	// BLOQUEAR CLICKS HACIA EL FONDO SI EL MOUSE ESTA SOBRE EL PANEL
	int mouseX = gMuClientApi.CursorX();
	int mouseY = gMuClientApi.CursorY();
	if (mouseX >= StartX && mouseX <= StartX + MainWidth &&
		mouseY >= StartY && mouseY <= StartY + MainHeight)
	{
		gMuClientApi.SetCursorFocus() = 1;
	}

	// Dibujar fondo del panel
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	gMuClientApi.SetBlend(1);

	// Borde dorado
	glColor4f(0.5f, 0.4f, 0.2f, 1.0f);
	gMuClientApi.DrawBarForm(StartX - 1, StartY - 1, MainWidth + 2, MainHeight + 2, 0, 0);

	// Fondo negro
	glColor4f(0.0f, 0.0f, 0.0f, 0.95f);
	gMuClientApi.DrawBarForm(StartX, StartY, MainWidth, MainHeight, 0, 0);

	// Barra de titulo
	glColor4f(0.15f, 0.15f, 0.15f, 1.0f);
	gMuClientApi.DrawBarForm(StartX + 2, StartY + 2, MainWidth - 4, 25.0f, 0, 0);

	// Boton cerrar
	float closeSize = 15.0f;
	float cX = StartX + MainWidth - closeSize - 5;
	float cY = StartY + 5;

	// Cambiar color si mouse esta sobre el boton X
	bool isOverClose = (mouseX >= cX && mouseX <= cX + closeSize &&
		mouseY >= cY && mouseY <= cY + closeSize);
	if (isOverClose)
		glColor4f(1.0f, 0.2f, 0.2f, 1.0f);
	else
		glColor4f(0.7f, 0.1f, 0.1f, 1.0f);
	gMuClientApi.DrawBarForm(cX, cY, closeSize, closeSize, 0, 0);

	gMuClientApi.GLSwitch();

	// Titulo
	gUIBase.DrawFormat(g_muColors.Gold, (int)StartX, (int)StartY + 10, (int)MainWidth, 3, "EVENT TIMES");
	gUIBase.DrawFormat(g_muColors.White, (int)cX, (int)cY + 2, (int)closeSize, 3, "X");

	// Botones de paginacion
	float navY = StartY + 35.0f;
	if (this->m_Page > 0)
	{
		gUIBase.DrawFormat(g_muColors.Yellow, (int)StartX + 10, (int)navY, 50, 1, "< Prev");
	}
	if (this->m_Page == 0 || (this->m_Page == 1 && this->m_Arena == 1))
	{
		gUIBase.DrawFormat(g_muColors.Yellow, (int)(StartX + MainWidth - 60), (int)navY, 50, 4, "Next >");
	}

	// Encabezados
	float headerY = StartY + 55.0f;
	gUIBase.DrawFormat(g_muColors.Gold, (int)StartX + 20, (int)headerY, 100, 1, "Event");
	gUIBase.DrawFormat(g_muColors.Gold, (int)(StartX + MainWidth - 100), (int)headerY, 80, 4, "Time");

	if (this->m_EventTimeEnable == 1)
	{
		// Decrementar tiempo cada segundo
		DWORD currentTick = GetTickCount();
		if (currentTick - this->m_EventTimeTickCount > 1000)
		{
			for (int i = 0; i < this->m_count; i++)
			{
				if (this->m_gCustomEventTime[i].time > 0)
				{
					this->m_gCustomEventTime[i].time--;
				}
			}
			this->m_EventTimeTickCount = currentTick;
		}

		char text2[30];
		float currentY = StartY + 75.0f;
		float rowHeight = 18.0f;

		// Mostrar 14 eventos por pagina
		int startIdx = 14 * this->m_Page;
		int endIdx = startIdx + 14;

		for (int i = startIdx; i < endIdx && i < this->m_count; i++)
		{
			int eventIndex = this->m_gCustomEventTime[i].index;

			// Saltar eventos reservados/no implementados (indices 8-13)
			if (eventIndex >= 8 && eventIndex <= 13)
			{
				continue;
			}

			// Para invasiones y arena (14+), solo mostrar si tienen tiempo valido
			if (eventIndex >= 14 && this->m_gCustomEventTime[i].time <= -1)
			{
				continue;
			}

			// Formatear tiempo
			if (this->m_gCustomEventTime[i].time <= -1)
			{
				sprintf_s(text2, "N/A");
			}
			else if (this->m_gCustomEventTime[i].time == 0)
			{
				sprintf_s(text2, "Online");
			}
			else
			{
				int total = this->m_gCustomEventTime[i].time;
				int hours = total / 3600;
				int minutes = (total / 60) % 60;
				int seconds = total % 60;

				if (hours > 23)
				{
					sprintf_s(text2, "%d day(s)+", hours / 24);
				}
				else
				{
					sprintf_s(text2, "%02d:%02d:%02d", hours, minutes, seconds);
				}
			}

			// Color segun estado
			DWORD Color;
			if (this->m_gCustomEventTime[i].time <= -1)
			{
				Color = g_muColors.Gray;  // Gris para no disponible
			}
			else if (this->m_gCustomEventTime[i].time == 0 || this->m_gCustomEventTime[i].time < 300)
			{
				Color = g_muColors.Green;  // Verde para activo o proximo
			}
			else
			{
				Color = g_muColors.Yellow;  // Amarillo para eventos lejanos
			}

			// Nombre del evento
			if (eventIndex >= 0 && eventIndex < MAX_EVENTTIME)
			{
				gUIBase.DrawFormat(g_muColors.White, (int)StartX + 20, (int)currentY, 130, 1,
					this->m_CustomEventInfo[eventIndex].Name);
			}

			// Tiempo
			gUIBase.DrawFormat(Color, (int)(StartX + MainWidth - 100), (int)currentY, 80, 4, text2);

			currentY += rowHeight;
		}
	}
	else
	{
		// Mostrar "Loading..."
		gUIBase.DrawFormat(g_muColors.Yellow, (int)StartX + 20, (int)(StartY + 120), (int)MainWidth - 40, 3, "Loading...");
	}

	gMuClientApi.GLSwitchBlend();
	glPopAttrib();
}

bool CCustomEventTime::EventEventTimeWindow_Close(DWORD Event)
{
	if (!this->m_isOpen)
	{
		return false;
	}

	float MainWidth = 250.0f;
	float StartY = 80.0f;
	float StartX = (640.0f / 2.0f) - (MainWidth / 2.0f);

	float closeSize = 15.0f;
	float cX = StartX + MainWidth - closeSize - 5;
	float cY = StartY + 5;

	int mouseX = gMuClientApi.CursorX();
	int mouseY = gMuClientApi.CursorY();

	bool isOverClose = (mouseX >= cX && mouseX <= cX + closeSize &&
		mouseY >= cY && mouseY <= cY + closeSize);

	if (!isOverClose)
	{
		return false;
	}

	if (Event == WM_LBUTTONDOWN || Event == WM_LBUTTONUP)
	{
		this->m_isOpen = false;
		gMuClientApi.SetCursorFocus() = 0;
		return true;
	}

	return false;
}

bool CCustomEventTime::EventNext(DWORD Event)
{
	if (!this->m_isOpen)
	{
		return false;
	}

	// Verificar si podemos ir a la siguiente pagina
	int maxPages = (this->m_Arena == 1) ? 3 : 2;
	if (this->m_Page >= maxPages - 1)
	{
		return false;
	}

	float MainWidth = 250.0f;
	float StartY = 80.0f;
	float StartX = (640.0f / 2.0f) - (MainWidth / 2.0f);
	float navY = StartY + 35.0f;

	int mouseX = gMuClientApi.CursorX();
	int mouseY = gMuClientApi.CursorY();

	bool isOverNext = (mouseX >= StartX + MainWidth - 60 && mouseX <= StartX + MainWidth - 10 &&
		mouseY >= navY && mouseY <= navY + 20);

	if (!isOverNext)
	{
		return false;
	}

	if (Event == WM_LBUTTONDOWN || Event == WM_LBUTTONUP)
	{
		this->m_Page++;
		return true;
	}

	return false;
}

bool CCustomEventTime::EventPrev(DWORD Event)
{
	if (!this->m_isOpen)
	{
		return false;
	}

	if (this->m_Page <= 0)
	{
		return false;
	}

	float MainWidth = 250.0f;
	float StartY = 80.0f;
	float StartX = (640.0f / 2.0f) - (MainWidth / 2.0f);
	float navY = StartY + 35.0f;

	int mouseX = gMuClientApi.CursorX();
	int mouseY = gMuClientApi.CursorY();

	bool isOverPrev = (mouseX >= StartX + 10 && mouseX <= StartX + 60 &&
		mouseY >= navY && mouseY <= navY + 20);

	if (!isOverPrev)
	{
		return false;
	}

	if (Event == WM_LBUTTONDOWN || Event == WM_LBUTTONUP)
	{
		this->m_Page--;
		return true;
	}

	return false;
}
