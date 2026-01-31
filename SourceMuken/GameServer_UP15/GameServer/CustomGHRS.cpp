#include "stdafx.h"
#include "DSProtocol.h"
#include "GameMain.h"
#include "Util.h"
#include "Message.h"
#include "User.h"
#include "Path.h"
#include "ServerInfo.h"
#include "MemScript.h"
#include "CustomGHRS.h"
#include "Notice.h"

#if (GHRS_TOP1_NEW == 1)

CCustomGHRS gCustomGHRS;
DWORD WINAPI Sync(LPVOID lpParam);

CCustomGHRS::CCustomGHRS()
{
	this->serverStart = false;
	this->Day = 0;
	CreateThread(NULL, 0, &Sync, NULL, 0, NULL);
}
CCustomGHRS::~CCustomGHRS() {
};

void CCustomGHRS::Load(char* path) {
	this->GHRS_WEEK[1] = GetPrivateProfileInt("WEEK", "Monday", 0, path);
	this->GHRS_WEEK[2] = GetPrivateProfileInt("WEEK", "Tuesday", 0, path);
	this->GHRS_WEEK[3] = GetPrivateProfileInt("WEEK", "Wednesday", 0, path);
	this->GHRS_WEEK[4] = GetPrivateProfileInt("WEEK", "Thursday", 0, path);
	this->GHRS_WEEK[5] = GetPrivateProfileInt("WEEK", "Friday", 0, path);
	this->GHRS_WEEK[6] = GetPrivateProfileInt("WEEK", "Saturday", 0, path);
	this->GHRS_WEEK[0] = GetPrivateProfileInt("WEEK", "Sunday", 0, path);


	this->Update_Hour = GetPrivateProfileInt("TIMEUPDATE", "Hour", 0, path);
	this->Update_Min = GetPrivateProfileInt("TIMEUPDATE", "Min", 0, path);
	this->Update_Sec = GetPrivateProfileInt("TIMEUPDATE", "Sec", 0, path);
};

void CCustomGHRS::GDCustomGHRSReq()
{

	time_t t = time(NULL) + 7 * 3600;
	localtime(&t);
	struct tm* ServerT;
	ServerT = gmtime(&t);

	if (!this->Compare(ServerT->tm_hour, ServerT->tm_min, ServerT->tm_sec))
	{
		t = time(NULL) - 17 * 3600;
		localtime(&t);
		ServerT = gmtime(&t);
	}

	SDHP_CUSTOM_GHRS_SEND pMsg;

	pMsg.header.set(0xF8, sizeof(pMsg));

	pMsg.time = (ServerT->tm_year + 1900) * 10000 + (ServerT->tm_mon + 1) * 100 + ServerT->tm_mday;

	gDataServerConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CCustomGHRS::GDCustomGHRSRecv(SDHP_CUSTOM_GHRS_RECV* lpMsg) {
	if (lpMsg == NULL)
	{
		return;
	}

	time_t t = time(NULL) + 7 * 3600;
	localtime(&t);
	struct tm* ServerT;
	ServerT = gmtime(&t);

	if (!this->Compare(ServerT->tm_hour, ServerT->tm_min, ServerT->tm_sec))
	{
		t = time(NULL) - 17 * 3600;
		localtime(&t);
		ServerT = gmtime(&t);
	}

	int curTime = (ServerT->tm_year + 1900) * 10000 + (ServerT->tm_mon + 1) * 100 + ServerT->tm_mday;

	this->maxResets = lpMsg->resets + this->GHRS_WEEK[ServerT->tm_wday];
	this->Day = lpMsg->time;
	LogAdd(LOG_RED, "[%02d:%02d:%04d][GHRS] Cap nhat GHRS hom nay: %d (Top 1 00h duoc reset +%d)", ServerT->tm_mday, ServerT->tm_mon + 1, ServerT->tm_year + 1900, this->maxResets, this->GHRS_WEEK[ServerT->tm_wday]);
	this->GHRSTOP = lpMsg->resets;
	this->GHRSPLUS = this->GHRS_WEEK[ServerT->tm_wday];
}

bool CCustomGHRS::Compare(int H, int M, int S) {
	if (H * 10000 + M * 100 + S >= this->Update_Hour * 10000 + this->Update_Min * 100 + this->Update_Sec)
		return true;
	return false;
}

DWORD WINAPI Sync(LPVOID lpParam) {
	while (!gCustomGHRS.serverStart) {
		Sleep(250);
	}

	Sleep(1000);
	gCustomGHRS.GDCustomGHRSReq();

	time_t t = time(NULL) + 7 * 3600;
	localtime(&t);
	struct tm* ServerT;
	ServerT = gmtime(&t);
	int curTime = 1;
	while (true)
	{
		Sleep(10 * 1000);
		//---
		t = time(NULL) + 7 * 3600;
		localtime(&t);
		ServerT = gmtime(&t);

		curTime = (ServerT->tm_year + 1900) * 10000 + (ServerT->tm_mon + 1) * 100 + ServerT->tm_mday;

		if (!gCustomGHRS.Day || gCustomGHRS.Day < curTime)
			gCustomGHRS.GDCustomGHRSReq();

	}
	return 1;
}

#endif