// =============================================
// CustomPing.h - COMPLETO BASADO EN SourceLuis15
// =============================================

#pragma once
#include "stdafx.h"
#include "Protocol.h"
#include <Ipexport.h>

struct PMSG_PING_SEND
{
    PSBMSG_HEAD header; // C1:F3:F1
    DWORD time;
};

struct PMSG_PING_RESPONSE_RECV
{
    PSBMSG_HEAD header; // C1:F3:F1
    DWORD clientTime;
    DWORD serverTime;
};

class CCustomPing
{
public:
    CCustomPing();
    ~CCustomPing();

    // Funciones principales
    void ShowPing();
    void ShowFPS();          // Solo FPS sin ping
    void PingRecv(PMSG_PING_RESPONSE_RECV* lpMsg);
    void PingSend();
    void StartPing();

    // Configuración
    void SetFPSVisible(bool visible);
    void SetPingVisible(bool visible);
    void SetPosition(int x, int y);
    void SetFPSColor(DWORD color);
    void SetPingColor(DWORD color);

    // Getters
    unsigned int GetCurrentFPS() const { return m_fps; }
    DWORD GetCurrentPing() const { return RealPingDelayRecv; }
    bool IsFPSVisible() const { return m_showFPS; }
    bool IsPingVisible() const { return m_showPing; }

public:
    DWORD PingDelay;
    DWORD PingDelaySend;
    DWORD PingDelayRecv;
    DWORD RealPingDelaySend;
    DWORD RealPingDelayRecv;

private:
    // Variables FPS
    unsigned int m_fps;
    unsigned int m_fpscount;
    DWORD TickCount;

    // Variables de ping
    int PingStart;

    // Configuración visual
    bool m_showFPS;
    bool m_showPing;
    int m_posX;
    int m_posY;
    DWORD m_fpsColor;
    DWORD m_pingColor;

    // Funciones de dibujo (renombradas para evitar conflictos con Windows API)
    void DrawCustomText(int x, int y, DWORD color, const char* format, ...);
    void DrawBackground(int x, int y, int width, int height, float alpha = 0.7f);
    DWORD GetFPSColor() const;
};

extern CCustomPing gCustomPing;