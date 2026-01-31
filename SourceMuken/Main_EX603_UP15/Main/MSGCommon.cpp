#include "StdAfx.h"
#include "MSGCommon.h"
#include "Interface.h"
#include "Import.h"
#include "Util.h"
#include "TMemory.h"
#include "Offset.h"
#include "Object.h"
#include "Defines.h"
#include "PrintPlayer.h"
#include "User.h"
#include "Common.h"
#include "OffTrade.h"
#include "Protect.h"
#include "postInterface.h"
#include "Protocol.h"
#include "WindowsStruct.h"
#include "Defines.h"



MSGCommon gMSGCommon;

MSGCommon::MSGCommon()
{
}

MSGCommon::~MSGCommon()
{
}


void MSGCommon::SendHack(int Number)
{
	REQUEST_HACK_OPTION_SEND pRequest;
	pRequest.header.set(0xFC, 0x07, sizeof(pRequest));
	pRequest.Number = Number;
	DataSend((LPBYTE)&pRequest, pRequest.header.size);

}
