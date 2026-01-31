// ServerDisplayer.cpp: implementation of the CServerDisplayer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ServerDisplayer.h"
#include "AccountManager.h"
#include "JoinServerProtocol.h"
#include "Log.h"
#include "Protect.h"
#include "ServerManager.h"
#include "SocketManager.h"

CServerDisplayer gServerDisplayer;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CServerDisplayer::CServerDisplayer() // OK
{
	for(int n=0;n < MAX_LOG_TEXT_LINE;n++)
	{
		memset(&this->m_log[n],0,sizeof(this->m_log[n]));
	}

	this->m_font = CreateFont(50,0,0,0,FW_THIN,0,0,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_DONTCARE,"Times");

#if(GAMESERVER_TYPE2 == 0)
	this->m_brush[0] = CreateSolidBrush(RGB(105,105,105)); //-- cuando esta activo
	this->m_brush[1] = CreateSolidBrush(RGB(105,105,105)); //-- cuando esta desactivado
	this->m_brush[2] = CreateSolidBrush(RGB(0, 152, 239)); //-- Encabezado
	this->m_brush[3] = CreateSolidBrush(RGB(41, 37, 44)); //-- Fondo Principal
	this->m_brush[4] = CreateSolidBrush(RGB(0, 0, 0)); //-- fondo de eventos e informacion
#elif(GAMESERVER_TYPE2 == 1)
	this->m_brush[0] = CreateSolidBrush(RGB(60, 255, 51)); //-- cuando esta activo
	this->m_brush[1] = CreateSolidBrush(RGB(120, 120, 120)); //-- cuando esta desactivado
	this->m_brush[2] = CreateSolidBrush(RGB(0, 152, 239)); //-- Encabezado
	this->m_brush[3] = CreateSolidBrush(RGB(255, 255, 255)); //-- Fondo Principal
	this->m_brush[4] = CreateSolidBrush(RGB(210, 210, 210)); //-- fondo de eventos e informacion
#else
	this->m_brush[0] = CreateSolidBrush(RGB(201, 214, 223)); //-- cuando esta activo
	this->m_brush[1] = CreateSolidBrush(RGB(201, 214, 223)); //-- cuando esta desactivado
	this->m_brush[2] = CreateSolidBrush(RGB(82, 97, 107)); //-- Encabezado
	this->m_brush[3] = CreateSolidBrush(RGB(27, 38, 44)); //-- Fondo Principal
	this->m_brush[4] = CreateSolidBrush(RGB(48, 56, 65)); //-- fondo de eventos e informacion
#endif

	strcpy_s(this->m_DisplayerText[0],"STANDBY MODE");
	strcpy_s(this->m_DisplayerText[1],"ACTIVE MODE");
}

CServerDisplayer::~CServerDisplayer() // OK
{
	DeleteObject(this->m_font);
	DeleteObject(this->m_brush[0]);
	DeleteObject(this->m_brush[1]);
	DeleteObject(this->m_brush[2]);
	DeleteObject(this->m_brush[3]);
	DeleteObject(this->m_brush[4]);
}

void CServerDisplayer::Init(HWND hWnd) // OK
{
	PROTECT_START

	this->m_hwnd = hWnd;

	PROTECT_FINAL

	gLog.AddLog(1,"LOG");

	gLog.AddLog(1,"LOG_ACCOUNT");
}

void CServerDisplayer::Run() // OK
{
	this->SetWindowName();
	this->PaintAllInfo();
	this->LogTextPaint();
	this->PaintName();
}

void CServerDisplayer::SetWindowName() // OK
{
	char buff[256];

    wsprintf(buff,"[%s] %s JoinServer (QueueSize : %d) (AccountCount : %d/%d)",JOINSERVER_VERSION,JOINSERVER_CLIENT,gSocketManager.GetQueueSize(),
        gAccountManager.GetAccountCount(),
#if    PROTECT_STATE
        gJoinServerMaxAccount[gProtect.m_AuthInfo.PackageType][gProtect.m_AuthInfo.PlanType]
#else
        MAX_ACCOUNT
#endif
    );

	SetWindowText(this->m_hwnd,buff);
}

void CServerDisplayer::PaintAllInfo() // OK
{
	RECT rect;

	GetClientRect(this->m_hwnd,&rect);

	rect.top = 50;
	rect.bottom = 100;

	HDC hdc = GetDC(this->m_hwnd);

	int OldBkMode = SetBkMode(hdc,TRANSPARENT);

	HFONT OldFont = (HFONT)SelectObject(hdc,this->m_font);

	int state = 0;

	for(int n=0;n < MAX_SERVER;n++)
	{
		if(gServerManager[n].CheckState() == 0)
		{
			continue;
		}

		if((GetTickCount()-gServerManager[n].m_PacketTime) <= 60000)
		{
			state = 1;
			break;
		}
	}


	if(state == 0)
	{
		SetTextColor(hdc,RGB(200,200,200));
		FillRect(hdc,&rect,this->m_brush[1]);
		TextOut(hdc,120,50,this->m_DisplayerText[0],strlen(this->m_DisplayerText[0]));
	}
	else
	{
		SetTextColor(hdc,RGB(250,250,250));
		FillRect(hdc,&rect,this->m_brush[0]);
		TextOut(hdc,150,50,this->m_DisplayerText[1],strlen(this->m_DisplayerText[1]));
	}



	SelectObject(hdc,OldFont);
	SetBkMode(hdc,OldBkMode);
	ReleaseDC(this->m_hwnd,hdc);

}

void CServerDisplayer::PaintName() // OK
{
	RECT rect;


	GetClientRect(this->m_hwnd,&rect);

	rect.top = 0;
	rect.bottom = 50;

	HDC hdc = GetDC(this->m_hwnd);

	int OldBkMode = SetBkMode(hdc,TRANSPARENT);

	HFONT OldFont = (HFONT)SelectObject(hdc,this->m_font);

	SetTextColor(hdc,RGB(255,255,255));
	FillRect(hdc,&rect,this->m_brush[2]);

	DrawText(hdc, JOINSERVER_CLIENT, sizeof(JOINSERVER_CLIENT), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	SelectObject(hdc,OldFont);
	SetBkMode(hdc,OldBkMode);
	ReleaseDC(this->m_hwnd,hdc);

}

void CServerDisplayer::LogTextPaint() // OK
{
	RECT rect;

	GetClientRect(this->m_hwnd,&rect);

	rect.top = 100;

	HDC hdc = GetDC(this->m_hwnd);

	int OldBkMode = SetBkMode(hdc,TRANSPARENT);

	FillRect(hdc,&rect,this->m_brush[3]);

	int line = MAX_LOG_TEXT_LINE;

	int count = (((this->m_count-1)>=0)?(this->m_count-1):(MAX_LOG_TEXT_LINE-1));

	for(int n=0;n < MAX_LOG_TEXT_LINE;n++)
	{
		switch(this->m_log[count].color)
		{
			case LOG_BLACK:
				SetTextColor(hdc,RGB(0,0,0));
				break;
			case LOG_RED:
				SetTextColor(hdc,RGB(239,0,0));
				break;
			case LOG_GREEN:
				SetTextColor(hdc,RGB(0,255,0));
				break;
			case LOG_BLUE:
				SetTextColor(hdc,RGB(0, 152, 239));
				break;
		}

		int size = strlen(this->m_log[count].text);

		if(size > 1)
		{
			TextOut(hdc,0,(85+(line*15)),this->m_log[count].text,size);
			line--;
		}

		count = (((--count)>=0)?count:(MAX_LOG_TEXT_LINE-1));
	}

	ReleaseDC(this->m_hwnd,hdc);
}

void CServerDisplayer::LogAddText(eLogColor color,char* text,int size) // OK
{
	PROTECT_START

	size = ((size>=MAX_LOG_TEXT_SIZE)?(MAX_LOG_TEXT_SIZE-1):size);

	memset(&this->m_log[this->m_count].text,0,sizeof(this->m_log[this->m_count].text));

	memcpy(&this->m_log[this->m_count].text,text,size);

	this->m_log[this->m_count].color = color;

	this->m_count = (((++this->m_count)>=MAX_LOG_TEXT_LINE)?0:this->m_count);

	PROTECT_FINAL

	gLog.Output(LOG_GENERAL,"%s",&text[9]);
}
