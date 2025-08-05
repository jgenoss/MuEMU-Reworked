#include "stdafx.h"
#include "CustomPing.h"
#include "Common.h"
#include "Util.h"
#include "Protocol.h"
#include "Protect.h"

CCustomPing gCustomPing;

CCustomPing::CCustomPing()
{
    this->PingDelaySend = GetTickCount();
    this->PingDelaySend = 0;
    this->PingDelayRecv = -1;
    this->RealPingDelaySend = 0;
    this->RealPingDelayRecv = -1;
    this->m_fpscount = 0;
    this->m_fps = 0;
    this->TickCount = GetTickCount();
    this->PingStart = 0;

    // Configuración por defecto
    this->m_showFPS = true;
    this->m_showPing = true;
    this->m_posX = 500;
    this->m_posY = 4;
    this->m_fpsColor = 0xFFFFD700; // Dorado
    this->m_pingColor = 0xFFFFD700; // Dorado
}

CCustomPing::~CCustomPing()
{
    // Destructor
}

void CCustomPing::ShowPing()
{
    // Actualizar contador FPS
    DWORD elapsed = GetTickCount() - this->TickCount;
    this->m_fpscount++;

    // Actualizar FPS cada segundo
    if (elapsed > 1000)
    {
        this->m_fps = m_fpscount;
        this->m_fpscount = 0;
        this->TickCount = GetTickCount();
    }

    // Solo mostrar si hay información de ping válida O si solo queremos FPS
    if ((int)this->RealPingDelayRecv >= 0 || this->m_showFPS)
    {
        int currentX = m_posX;
        int currentY = m_posY;

        // Dibujar fondo si hay información que mostrar
        if (this->m_showPing && (int)this->RealPingDelayRecv >= 0)
        {
            DrawBackground(currentX - 10, currentY - 2, 160, 18);
        }
        else if (this->m_showFPS)
        {
            DrawBackground(10, 10, 100, 18);
            currentX = 15;
            currentY = 12;
        }

        // Mostrar RTT si está disponible - USANDO DrawCustomText
        if (this->m_showPing && (int)this->RealPingDelayRecv >= 0)
        {
            DrawCustomText(currentX, currentY, m_pingColor, "RTT: %d ms", this->RealPingDelayRecv);
            currentX += 70;
        }

        // Mostrar PING si está disponible - USANDO DrawCustomText
        if (this->m_showPing && (int)this->PingDelayRecv >= 0)
        {
            DrawCustomText(currentX, currentY, m_pingColor, "PING: %d ms", this->PingDelayRecv);
            currentX += 80;
        }

        // Mostrar FPS - USANDO DrawCustomText
        if (this->m_showFPS)
        {
            if (this->m_showPing && (int)this->RealPingDelayRecv >= 0)
            {
                DrawCustomText(currentX, currentY, GetFPSColor(), "FPS: %d", this->m_fps);
            }
            else
            {
                DrawCustomText(currentX, currentY, GetFPSColor(), "FPS: %d", this->m_fps);
            }
        }
    }
}

void CCustomPing::ShowFPS()
{
    // Solo mostrar FPS, sin ping
    DWORD elapsed = GetTickCount() - this->TickCount;
    this->m_fpscount++;

    if (elapsed > 1000)
    {
        this->m_fps = m_fpscount;
        this->m_fpscount = 0;
        this->TickCount = GetTickCount();
    }

    if (this->m_showFPS)
    {
        DrawBackground(10, 10, 100, 18);
        DrawCustomText(15, 12, GetFPSColor(), "FPS: %d", this->m_fps);
    }
}

void CCustomPing::PingRecv(PMSG_PING_RESPONSE_RECV* lpMsg)
{
    if (lpMsg->clientTime == this->RealPingDelaySend)
    {
        this->RealPingDelayRecv = GetTickCount() - lpMsg->clientTime;
    }
}
void CCustomPing::PingSend()
{
    this->RealPingDelaySend = GetTickCount();

    PMSG_PING_SEND lpMsg;
    lpMsg.header.set(0xF3, 0xF1, sizeof(lpMsg));
    lpMsg.time = this->RealPingDelaySend;

    // NECESITAS IMPLEMENTAR DataSend() - ver más abajo
    DataSend((LPBYTE)&lpMsg, lpMsg.header.size);
}

void PingTest(LPVOID lpThreadParameter)
{
    while (TRUE)
    {
        gCustomPing.PingSend();

        SOCKET m_socket = socket(PF_INET, SOCK_STREAM, 0);
        if (m_socket == INVALID_SOCKET)
        {
            return;
        }

        SOCKADDR_IN target;
        target.sin_family = AF_INET;
        target.sin_port = htons(gProtect.m_MainInfo.IpAddressPort); // Puerto por defecto
        target.sin_addr.s_addr = inet_addr(gProtect.m_MainInfo.IpAddress); // IP por defecto

        // TODO: Obtener IP y puerto del servidor desde configuración
        // target.sin_port = htons(gProtect.m_MainInfo.IpAddressPort);
        // target.sin_addr.s_addr = inet_addr(gProtect.m_MainInfo.IpAddress);

        if (target.sin_addr.s_addr == INADDR_NONE)
        {
            HOSTENT* host = gethostbyname(gProtect.m_MainInfo.IpAddress);
            if (host != 0)
            {
                memcpy(&target.sin_addr.s_addr, (*host->h_addr_list), host->h_length);
            }
        }

        gCustomPing.PingDelaySend = GetTickCount();

        if (connect(m_socket, (SOCKADDR*)&target, sizeof(target)) != SOCKET_ERROR)
        {
            gCustomPing.PingDelayRecv = GetTickCount() - gCustomPing.PingDelaySend + 1;
            Sleep(100);
            closesocket(m_socket);
        }
        else
        {
            closesocket(m_socket);
        }

        Sleep(5000); // Ping cada 5 segundos
    }
}

void CCustomPing::StartPing()
{
    if (this->PingStart == 1)
        return;

    // Solo iniciar ping si está habilitado
    if (this->m_showPing)
    {
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)PingTest, 0, 0, 0);
    }

    this->PingStart = 1;
}

void CCustomPing::SetFPSVisible(bool visible)
{
    m_showFPS = visible;
}

void CCustomPing::SetPingVisible(bool visible)
{
    m_showPing = visible;
}

void CCustomPing::SetPosition(int x, int y)
{
    m_posX = x;
    m_posY = y;
}

void CCustomPing::SetFPSColor(DWORD color)
{
    m_fpsColor = color;
}

void CCustomPing::SetPingColor(DWORD color)
{
    m_pingColor = color;
}

// FUNCIÓN RENOMBRADA PARA EVITAR CONFLICTOS CON Windows API DrawText
void CCustomPing::DrawCustomText(int x, int y, DWORD color, const char* format, ...)
{
    char buffer[256];
    va_list args;
    va_start(args, format);
    vsprintf_s(buffer, sizeof(buffer), format, args);
    va_end(args);

    HDC hdc = GetDC(GetActiveWindow());
    if (!hdc) return;

    // Convertir color DWORD a COLORREF
    COLORREF textColor = RGB(
        (color >> 16) & 0xFF,  // R
        (color >> 8) & 0xFF,   // G
        color & 0xFF           // B
    );

    SetTextColor(hdc, textColor);
    SetBkMode(hdc, TRANSPARENT);

    // Crear fuente
    HFONT hFont = CreateFontA(
        14, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
        ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial"
    );

    HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);
    TextOutA(hdc, x, y, buffer, strlen(buffer));
    SelectObject(hdc, hOldFont);
    DeleteObject(hFont);

    ReleaseDC(GetActiveWindow(), hdc);
}

void CCustomPing::DrawBackground(int x, int y, int width, int height, float alpha)
{
    HDC hdc = GetDC(GetActiveWindow());
    if (!hdc) return;

    RECT rect = { x, y, x + width, y + height };

    // Crear brush semi-transparente
    BYTE alphaValue = (BYTE)(alpha * 255);
    HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));

    // TODO: Implementar transparencia real si es necesario
    // Por ahora usar fondo sólido negro
    FillRect(hdc, &rect, hBrush);

    DeleteObject(hBrush);
    ReleaseDC(GetActiveWindow(), hdc);
}

DWORD CCustomPing::GetFPSColor() const
{
    if (m_fps >= 60)
        return 0xFF00FF00;      // Verde
    else if (m_fps >= 30)
        return 0xFFFFFF00;      // Amarillo
    else if (m_fps >= 15)
        return 0xFFFFA500;      // Naranja
    else
        return 0xFFFF0000;      // Rojo
}