#include "StdAfx.h"
#include "CustomCuongHoaWing.h"
#include "Util.h"
#include "Object.h"
#include "Import.h"
#include "Central.h"
#include "User.h"
#include "CustomMessage.h"
#include "Defines.h"
#include "Protect.h"
#include "CustomFont.h"
#include "GLFont.h"
//#include "WideScreen.h"
//#include "Other.h"

CuongHoaWing gCuongHoaWing;

CuongHoaWing::CuongHoaWing(void)
{
}

CuongHoaWing::~CuongHoaWing(void)
{
}

void CuongHoaWing::ImageLoad()
{

}

void CuongHoaWing::BinObeject()
{

}

void CuongHoaWing::DrawHuyHieu()
{

}
void CuongHoaWing::DrawChiSo()
{

}

void CuongHoaWing::GCData(PMSG_CUONGHOAWING_RECV* lpMsg)
{
	this->cuonghoawing = lpMsg->cuonghoawing;
	this->dong1 = lpMsg->dong1;
	this->dong2 = lpMsg->dong2;
	this->dong3 = lpMsg->dong3;
	this->dong4 = lpMsg->dong4;
	this->dong5 = lpMsg->dong5;
}