#include "StdAfx.h"
#include "CustomVKR.h"
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
//#include "Other.h"

VuKhiRong gVuKhiRong;

VuKhiRong::VuKhiRong(void)
{
}

VuKhiRong::~VuKhiRong(void)
{
}

void VuKhiRong::ImageLoad()
{

}

void VuKhiRong::BinObeject()
{

}

void VuKhiRong::DrawHuyHieu()
{

}
void VuKhiRong::DrawChiSo()
{

}

void VuKhiRong::GCData(PMSG_VUKHIRONG_RECV* lpMsg)
{
	this->vukhirong = lpMsg->vukhirong;
	this->dong1 = lpMsg->dong1;
	this->dong2 = lpMsg->dong2;
	this->dong3 = lpMsg->dong3;
}