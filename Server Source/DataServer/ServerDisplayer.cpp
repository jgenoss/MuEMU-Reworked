// ServerDisplayer.cpp: implementation of the CServerDisplayer class.
// Enhanced DataServer Version
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ServerDisplayer.h"
#include "Log.h"
#include "ServerManager.h"
#include "SocketManager.h"

CServerDisplayer gServerDisplayer;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CServerDisplayer::CServerDisplayer() // OK
{
	for (int n = 0; n < MAX_LOG_TEXT_LINE; n++)
	{
		memset(&this->m_log[n], 0, sizeof(this->m_log[n]));
	}

	// Fuentes mejoradas
	this->m_titleFont = CreateFont(16, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_MODERN, "Segoe UI");
	this->m_font = CreateFont(22, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_MODERN, "Segoe UI");
	this->m_infoFont = CreateFont(12, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_MODERN, "Segoe UI");

	// Colores modernos (mismo esquema que ConnectServer)
	this->m_brush[0] = CreateSolidBrush(RGB(127, 140, 141)); // Standby - Gris moderno
	this->m_brush[1] = CreateSolidBrush(RGB(39, 174, 96));   // Active - Verde moderno
	this->m_brush[2] = CreateSolidBrush(RGB(52, 73, 94));    // Título - Azul oscuro
	this->m_brush[3] = CreateSolidBrush(RGB(44, 62, 80));    // Info bar - Azul más oscuro
	this->m_brush[4] = CreateSolidBrush(RGB(26, 26, 26));    // Fondo logs - Negro suave
	this->m_brush[5] = CreateSolidBrush(RGB(52, 152, 219));  // Accent - Azul brillante

	// Pens para bordes
	this->m_pen[0] = CreatePen(PS_SOLID, 1, RGB(52, 152, 219));  // Border azul
	this->m_pen[1] = CreatePen(PS_SOLID, 2, RGB(52, 152, 219));  // Border grueso
	this->m_pen[2] = CreatePen(PS_SOLID, 1, RGB(189, 195, 199)); // Border claro
	this->m_pen[3] = CreatePen(PS_SOLID, 1, RGB(149, 165, 166)); // Border gris

	strcpy_s(this->m_DisplayerText[0], "STANDBY MODE");
	strcpy_s(this->m_DisplayerText[1], "ACTIVE MODE");

	this->m_startTime = GetTickCount();
	this->m_animationCounter = 0;
}

CServerDisplayer::~CServerDisplayer() // OK
{
	DeleteObject(this->m_titleFont);
	DeleteObject(this->m_font);
	DeleteObject(this->m_infoFont);

	for (int i = 0; i < 6; i++)
	{
		DeleteObject(this->m_brush[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		DeleteObject(this->m_pen[i]);
	}
}

void CServerDisplayer::Init(HWND hWnd) // OK
{
	this->m_hwnd = hWnd;
	gLog.AddLog(1, "LOG");
}

void CServerDisplayer::Run() // OK
{
	this->SetWindowName();
	this->PaintAllInfo();
	this->m_animationCounter++;
}

void CServerDisplayer::SetWindowName() // OK
{
	char buff[256];
	wsprintf(buff, "Enhanced DataServer v2.0 - PREMIUM Edition (Queue: %d)", gSocketManager.GetQueueSize());
	SetWindowText(this->m_hwnd, buff);
}

void CServerDisplayer::PaintAllInfo() // OK
{
	this->PaintTitleBar();
	this->PaintStatusSection();
	this->PaintInfoBar();
	this->LogTextPaint();
}

void CServerDisplayer::PaintTitleBar() // OK
{
	RECT rect;
	GetClientRect(this->m_hwnd, &rect);
	rect.bottom = 40;

	HDC hdc = GetDC(this->m_hwnd);

	// Gradiente para la barra de título
	this->DrawGradientRect(hdc, rect, RGB(52, 152, 219), RGB(41, 128, 185), false);

	// Borde inferior
	HPEN oldPen = (HPEN)SelectObject(hdc, this->m_pen[0]);
	MoveToEx(hdc, rect.left, rect.bottom - 1, NULL);
	LineTo(hdc, rect.right, rect.bottom - 1);
	SelectObject(hdc, oldPen);

	// Texto del título
	int OldBkMode = SetBkMode(hdc, TRANSPARENT);
	HFONT OldFont = (HFONT)SelectObject(hdc, this->m_titleFont);
	SetTextColor(hdc, RGB(255, 255, 255));

	char titleText[] = "DATASERVER - PREMIUM EDITION";
	RECT textRect = rect;
	DrawText(hdc, titleText, -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	SelectObject(hdc, OldFont);
	SetBkMode(hdc, OldBkMode);
	ReleaseDC(this->m_hwnd, hdc);
}

void CServerDisplayer::PaintStatusSection() // OK
{
	RECT rect;
	GetClientRect(this->m_hwnd, &rect);
	rect.top = 40;
	rect.bottom = 120;

	HDC hdc = GetDC(this->m_hwnd);

	// Lógica original del DataServer para determinar estado
	int state = 0;
	for (int n = 0; n < MAX_SERVER; n++)
	{
		if (gServerManager[n].CheckState() == 0)
		{
			continue;
		}

		if ((GetTickCount() - gServerManager[n].m_PacketTime) <= 60000)
		{
			state = 1;
			break;
		}
	}

	// Determinar colores basado en el estado
	bool isActive = (state != 0);
	COLORREF baseColor = isActive ? RGB(39, 174, 96) : RGB(127, 140, 141);
	COLORREF lightColor = isActive ? RGB(46, 204, 113) : RGB(149, 165, 166);

	// Gradiente de fondo
	this->DrawGradientRect(hdc, rect, baseColor, lightColor, true);

	// Bordes
	HPEN oldPen = (HPEN)SelectObject(hdc, this->m_pen[0]);
	MoveToEx(hdc, rect.left, rect.top, NULL);
	LineTo(hdc, rect.right, rect.top);
	MoveToEx(hdc, rect.left, rect.bottom - 1, NULL);
	LineTo(hdc, rect.right, rect.bottom - 1);
	SelectObject(hdc, oldPen);

	// Texto del estado
	int OldBkMode = SetBkMode(hdc, TRANSPARENT);
	HFONT OldFont = (HFONT)SelectObject(hdc, this->m_font);
	SetTextColor(hdc, RGB(255, 255, 255));

	char* statusText = isActive ? this->m_DisplayerText[1] : this->m_DisplayerText[0];
	TextOut(hdc, 80, rect.top + 30, statusText, strlen(statusText));

	SelectObject(hdc, OldFont);
	SetBkMode(hdc, OldBkMode);
	ReleaseDC(this->m_hwnd, hdc);
}

void CServerDisplayer::PaintInfoBar() // OK
{
	RECT rect;
	GetClientRect(this->m_hwnd, &rect);
	rect.top = 120;
	rect.bottom = 150;

	HDC hdc = GetDC(this->m_hwnd);

	// Fondo degradado
	this->DrawGradientRect(hdc, rect, RGB(52, 73, 94), RGB(44, 62, 80), false);

	// Bordes
	HPEN oldPen = (HPEN)SelectObject(hdc, this->m_pen[0]);
	MoveToEx(hdc, rect.left, rect.top, NULL);
	LineTo(hdc, rect.right, rect.top);
	MoveToEx(hdc, rect.left, rect.bottom - 1, NULL);
	LineTo(hdc, rect.right, rect.bottom - 1);
	SelectObject(hdc, oldPen);

	// Información del servidor
	int OldBkMode = SetBkMode(hdc, TRANSPARENT);
	HFONT OldFont = (HFONT)SelectObject(hdc, this->m_infoFont);

	// Queue
	SetTextColor(hdc, RGB(52, 152, 219));
	TextOut(hdc, 100, rect.top + 8, "Queue:", 6);
	SetTextColor(hdc, RGB(255, 255, 255));
	char queueStr[32];
	wsprintf(queueStr, "%d", gSocketManager.GetQueueSize());
	TextOut(hdc, 140, rect.top + 8, queueStr, strlen(queueStr));

	// Uptime
	SetTextColor(hdc, RGB(52, 152, 219));
	TextOut(hdc, 260, rect.top + 8, "Uptime:", 7);
	SetTextColor(hdc, RGB(255, 255, 255));

	DWORD uptime = this->GetUptime();
	int hours = uptime / 3600;
	int minutes = (uptime % 3600) / 60;
	int seconds = uptime % 60;
	char uptimeStr[32];
	wsprintf(uptimeStr, "%02d:%02d:%02d", hours, minutes, seconds);
	TextOut(hdc, 305, rect.top + 8, uptimeStr, strlen(uptimeStr));

	SelectObject(hdc, OldFont);
	SetBkMode(hdc, OldBkMode);
	ReleaseDC(this->m_hwnd, hdc);
}

void CServerDisplayer::LogTextPaint() // FIXED - Logs de abajo hacia arriba
{
	RECT rect;
	GetClientRect(this->m_hwnd, &rect);
	rect.top = 150;

	HDC hdc = GetDC(this->m_hwnd);

	// Fondo degradado para logs
	this->DrawGradientRect(hdc, rect, RGB(26, 26, 26), RGB(15, 15, 15), true);

	// Calcular líneas visibles
	int availableHeight = rect.bottom - rect.top - 20;
	int lineHeight = 16;
	int maxVisibleLines = availableHeight / lineHeight;
	int linesToShow = min(maxVisibleLines, MAX_LOG_TEXT_LINE);

	// Empezar desde el log más reciente
	int count = (((this->m_count - 1) >= 0) ? (this->m_count - 1) : (MAX_LOG_TEXT_LINE - 1));

	// Fuente para logs
	HFONT logFont = CreateFont(11, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_MODERN, "Consolas");
	HFONT oldFont = (HFONT)SelectObject(hdc, logFont);
	SetBkMode(hdc, TRANSPARENT);

	// Renderizar desde abajo hacia arriba (log más reciente abajo)
	for (int n = 0; n < linesToShow; n++)
	{
		// Calcular posición Y desde abajo hacia arriba
		int yPos = rect.bottom - 10 - ((n + 1) * lineHeight);

		// Verificar que esté dentro del área visible
		if (yPos < rect.top + 10) break;

		// Color de fondo alternado
		if (n % 2 == 0)
		{
			RECT lineRect = { rect.left + 5, yPos - 2, rect.right - 5, yPos + 14 };
			HBRUSH altBrush = CreateSolidBrush(RGB(30, 30, 30));
			FillRect(hdc, &lineRect, altBrush);
			DeleteObject(altBrush);
		}

		// Colorear según tipo de log
		HBRUSH lineBrush = NULL;
		switch (this->m_log[count].color)
		{
		case LOG_WHITE:
			SetTextColor(hdc, RGB(255, 255, 255));
			lineBrush = CreateSolidBrush(RGB(255, 255, 255));
			break;
		case LOG_RED:
			SetTextColor(hdc, RGB(231, 76, 60));
			lineBrush = CreateSolidBrush(RGB(231, 76, 60));
			break;
		case LOG_GREEN:
			SetTextColor(hdc, RGB(46, 204, 113));
			lineBrush = CreateSolidBrush(RGB(46, 204, 113));
			break;
		case LOG_BLUE:
			SetTextColor(hdc, RGB(52, 152, 219));
			lineBrush = CreateSolidBrush(RGB(52, 152, 219));
			break;
		}

		// Barra lateral de color
		if (lineBrush)
		{
			RECT sideBar = { rect.left + 8, yPos, rect.left + 11, yPos + 12 };
			FillRect(hdc, &sideBar, lineBrush);
			DeleteObject(lineBrush);
		}

		// Renderizar texto si existe
		int size = strlen(this->m_log[count].text);
		if (size > 1)
		{
			TextOut(hdc, rect.left + 20, yPos, this->m_log[count].text, size);
		}

		// Siguiente log (hacia atrás en el buffer circular para mostrar logs más antiguos arriba)
		count = (((--count) >= 0) ? count : (MAX_LOG_TEXT_LINE - 1));
	}

	SelectObject(hdc, oldFont);
	DeleteObject(logFont);
	ReleaseDC(this->m_hwnd, hdc);
}

void CServerDisplayer::LogAddText(eLogColor color, char* text, int size) // OK
{

	size = ((size >= MAX_LOG_TEXT_SIZE) ? (MAX_LOG_TEXT_SIZE - 1) : size);

	memset(&this->m_log[this->m_count].text, 0, sizeof(this->m_log[this->m_count].text));

	memcpy(&this->m_log[this->m_count].text, text, size);

	this->m_log[this->m_count].color = color;

	this->m_count = (((++this->m_count) >= MAX_LOG_TEXT_LINE) ? 0 : this->m_count);

	gLog.Output(LOG_GENERAL, "%s", &text[9]);
}


void CServerDisplayer::DrawGradientRect(HDC hdc, RECT rect, COLORREF color1, COLORREF color2, bool vertical) // OK
{
	int steps = 64;
	int r1 = GetRValue(color1), g1 = GetGValue(color1), b1 = GetBValue(color1);
	int r2 = GetRValue(color2), g2 = GetGValue(color2), b2 = GetBValue(color2);

	for (int i = 0; i < steps; i++)
	{
		int r = r1 + (r2 - r1) * i / steps;
		int g = g1 + (g2 - g1) * i / steps;
		int b = b1 + (b2 - b1) * i / steps;

		HBRUSH brush = CreateSolidBrush(RGB(r, g, b));
		RECT stepRect = rect;

		if (vertical)
		{
			stepRect.top = rect.top + (rect.bottom - rect.top) * i / steps;
			stepRect.bottom = rect.top + (rect.bottom - rect.top) * (i + 1) / steps;
		}
		else
		{
			stepRect.left = rect.left + (rect.right - rect.left) * i / steps;
			stepRect.right = rect.left + (rect.right - rect.left) * (i + 1) / steps;
		}

		FillRect(hdc, &stepRect, brush);
		DeleteObject(brush);
	}
}

DWORD CServerDisplayer::GetUptime() // OK
{
	return (GetTickCount() - this->m_startTime) / 1000;
}