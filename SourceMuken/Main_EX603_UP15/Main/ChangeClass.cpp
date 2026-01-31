
#include "stdafx.h"
#include "ChangeClass.h"
#include "Interface.h"
#if (DOI_GIOI_TINH)
cChangeClass gChangeClass;

cChangeClass::cChangeClass()
{
	//this->m_Price = 0;
	this->m_WCoinC = 0;
}

cChangeClass::~cChangeClass()
{

}

void cChangeClass::RecvData(PMSG_CHANGECLASS_DATA* Data)
{
	//this->m_PriceType = Data->PriceType;
	//this->m_Price = Data->Price;
	this->m_WCoinC = Data->m_WCoinC;
}

void cChangeClass::SendChangeClass(int Type)
{
	gInterface.Data[eCHANGINGCLASS_MAIN].Close();
	CG_CHANGECLASS_SEND pRequest;
	pRequest.Head.set(0xFF, 0x06, sizeof(pRequest));

	pRequest.Type = Type;

	DataSend((BYTE*)&pRequest, pRequest.Head.size);
}
#endif