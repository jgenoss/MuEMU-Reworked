#include "stdafx.h"
#include "CustomPing.h"
#include "MuClientAPI.h"
#include "UIBase.h"
#include "MuConstants.h"
#include "Protect.h"
#include "Common.h"

CCustomPing gCustomPing;

CCustomPing::CCustomPing()
{
	PingDelaySend = GetTickCount();
	PingDelaySend = 0;
	PingDelayRecv = -1;
	RealPingDelaySend = 0;
	RealPingDelayRecv = -1;
	m_fpscount = 0;
	m_fps = 0;
	TickCount = GetTickCount();
	PingStart = 0;
}

CCustomPing::~CCustomPing()
{
}

void CCustomPing::ShowPing()
{
	if ((int)RealPingDelayRecv >= 0)
	{
		gMuClientApi.SetBlend(1);
		glColor4f(0.0, 0.0, 0.0, 0.8);
		gMuClientApi.DrawBarForm((float)490, (float)0, 150.0f, 15.0f, 0.0f, 0);
		gMuClientApi.GLSwitchBlend();
		gMuClientApi.GLSwitch();
		glColor4f(1.0, 1.0, 1.0, 1.0);

		gMuClientApi.SetBlend(1);

		DWORD elapsed = GetTickCount() - TickCount;

		m_fpscount++;

		// one second elapsed? (= 1000 milliseconds)
		if (elapsed > 1000)
		{
			// save the current counter value to m_fps
			m_fps = m_fpscount;
			// reset the counter and the interval
			m_fpscount = 0;
			// set tick count
			TickCount = GetTickCount();
		}

		gUIBase.DrawFormat(g_muColors.Gold, 500, 4, 100, 1, "RTT: %d ms",RealPingDelayRecv);

		gUIBase.DrawFormat(g_muColors.Gold, 550, 4, 100, 1, "PING: %d ms", PingDelayRecv);

		gUIBase.DrawFormat(g_muColors.Gold, 600, 4, 100, 1, "FPS: %d", m_fps);
	}
}

void CCustomPing::PingRecv()
{
	RealPingDelayRecv = (GetTickCount() - RealPingDelaySend) + 1;
}

void CCustomPing::PingSend()
{
	RealPingDelaySend = GetTickCount();

	PMSG_PING_SEND lpMsg;

	lpMsg.header.set(0xF3, 0xF1, sizeof(lpMsg));

	DataSend((LPBYTE)&lpMsg, lpMsg.header.size);
}

void PingTest(LPVOID lpThreadParameter)
{
	std::cout << "PingTest Start" << std::endl;
	while (TRUE)
	{
		gCustomPing.PingSend();

		SOCKET m_socket;

		m_socket = socket(PF_INET, SOCK_STREAM, 0);

		if (m_socket == INVALID_SOCKET)
		{
			return;
		}

		SOCKADDR_IN target;

		target.sin_family = AF_INET;
		target.sin_port = htons(gProtect.m_MainInfo.IpAddressPort);
		target.sin_addr.s_addr = inet_addr(gProtect.m_MainInfo.IpAddress);

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
			m_socket == INVALID_SOCKET;
		}

		Sleep(5000);
	}
}

void CCustomPing::StartPing()
{
	if (PingStart == 1)
		return;
	
	if (gProtect.m_MainInfo.PingTest == 1)
	{
		if (DisablePing == 0)
		{
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)PingTest, 0, 0, 0);
		}
	}
	PingStart = 1;
}
