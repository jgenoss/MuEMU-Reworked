#include "stdafx.h"
#if(CHIEN_TRUONG_CO)
#include "Util.h"
#include "ChienTruongCo.h"
#include "DSProtocol.h"
#include "CashShop.h"
#include "Notice.h"
#include "Party.h"
#include "ItemBagManager.h"
#include "Message.h"

cChienTruongCo	gChienTruongCo;


cChienTruongCo::cChienTruongCo()
{
}

cChienTruongCo::~cChienTruongCo()
{

}
void cChienTruongCo::LoadData(char * FilePath){
	//====================
	this->Enabled = 0;
	this->TimeBuyMin = 0;
	this->WCoinBuy = 0;
	this->MaxBuyDay = 0;

	this->Class = 0;
	this->Map = 0;
	this->X = 0;
	this->Y = 0;

	this->PointKillMonter = 0;
	this->PartyKillPoint = 0;
	ZeroMemory(this->MsgTPoint, sizeof(this->MsgTPoint));

	this->SLQuaiYeuCau = 0;
	this->IndexType = 0;
	ZeroMemory(this->MsgTKill, sizeof(this->MsgTKill));

	//======================
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(FilePath);
	if (res.status != pugi::status_ok){
		ErrorMessageBox("File %s load fail. Error: %s", FilePath, res.description());
		return;
	}
	pugi::xml_node oChienTruongCo = file.child("ChienTruongCo");

	pugi::xml_node eBatTat = oChienTruongCo.child("BatTat");
	for (pugi::xml_node rBatTat = eBatTat.child("Setting"); rBatTat; rBatTat = rBatTat.next_sibling()){
		this->Enabled = rBatTat.attribute("Enabled").as_int();
		this->TimeBuyMin = rBatTat.attribute("TimeBuyMin").as_int();
		this->WCoinBuy = rBatTat.attribute("WCoinBuy").as_int();
		this->MaxBuyDay = rBatTat.attribute("MaxBuyDay").as_int();
	}

	pugi::xml_node eNPCTalk = oChienTruongCo.child("NPCTalk");
	for (pugi::xml_node rNPCTalk = eNPCTalk.child("NPC"); rNPCTalk; rNPCTalk = rNPCTalk.next_sibling()){
		this->Class = rNPCTalk.attribute("Class").as_int();
		this->Map = rNPCTalk.attribute("Map").as_int();
		this->X = rNPCTalk.attribute("X").as_int();
		this->Y = rNPCTalk.attribute("Y").as_int();
	}

	pugi::xml_node ePointReward = oChienTruongCo.child("PointReward");
	for (pugi::xml_node rPointReward = ePointReward.child("Config"); rPointReward; rPointReward = rPointReward.next_sibling()){
		this->LoaiTien = rPointReward.attribute("LoaiTien").as_int();
		this->PointKillMonter = rPointReward.attribute("PointKillMonter").as_int();
		this->PartyKillPoint = rPointReward.attribute("PartyKillPoint").as_int();
		strncpy_s(this->MsgTPoint, rPointReward.attribute("MSG").as_string(), sizeof(this->MsgTPoint));
	}

	pugi::xml_node eItemReward = oChienTruongCo.child("ItemReward");
	for (pugi::xml_node rItemReward = eItemReward.child("Config"); rItemReward; rItemReward = rItemReward.next_sibling()){
		this->SLQuaiYeuCau = rItemReward.attribute("SLQuaiYeuCau").as_int();
		this->IndexType = rItemReward.attribute("IndexType").as_int();
		strncpy_s(this->MsgTKill, rItemReward.attribute("MSG").as_string(), sizeof(this->MsgTKill));
	}

}
void cChienTruongCo::CapNhatTimeCTC(CAPNHAT_CTC_0H* lpMsg)
{
	if (gObjIsConnectedGP(lpMsg->index) == 0)
	{
		return;
	}

	LPOBJ lpObj = &gObj[lpMsg->index];
	lpObj->CTCTime = lpMsg->TimeCTC;
	lpObj->CTCRegDay = 0;
	this->SendInfoCTC(lpObj->Index, 0); //Cap Nhat

}
void cChienTruongCo::SendInfoCTC(int aIndex, int Type)
{


	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	INFOCTC_SENDCLIENT pMsg;
	pMsg.header.set(0xF4, 0x8, sizeof(pMsg));
	pMsg.TimeConLai = lpObj->CTCTime;
	pMsg.PointKillQuai = this->PointKillMonter;
	pMsg.PartyKillPoint = this->PartyKillPoint;
	pMsg.MonterYeuCau = this->SLQuaiYeuCau;
	pMsg.TYPE = Type;
	DataSend(lpObj->Index, (BYTE*)&pMsg, pMsg.header.size);
}
bool cChienTruongCo::Dialog(int aIndex, int aNpcIndex)
{
	if (!this->Enabled)
	{
		return false;
	}
	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return false;
	}
	LPOBJ lpUser = &gObj[aIndex];
	LPOBJ lpNpc = &gObj[aNpcIndex];

	if (lpNpc->Class == this->Class
		&&	lpNpc->Map == this->Map
		&&	lpNpc->X == this->X
		&&	lpNpc->Y == this->Y)
	{
		this->SendInfoCTC(aIndex, 1);
		return true;
	}

	return false;
}

void cChienTruongCo::MonsterDie(LPOBJ Player)
{
	if (gObjIsConnectedGP(Player->Index) == 0 || Player->CTCTime < 1)
	{
		return;
	}

	if (Player->Map == 97 && Player->CTCTime > 0) {

		//==== Thuong Point BT
		if (this->PointKillMonter > 0)
		{
			if (this->LoaiTien == 0)
			{
				gCashShop.GDCashShopAddPointSaveSend(Player->Index, 0, this->PointKillMonter, 0, 0, 0);
				//-- WCoinC Update
				gNotice.GCNoticeSend(Player->Index, 1, 0, 0, 0, 0, 0, this->MsgTPoint, this->PointKillMonter);
			}
			if (this->LoaiTien == 1)
			{
				gCashShop.GDCashShopAddPointSaveSend(Player->Index, 0, 0, this->PointKillMonter, 0, 0);
				//-- WCoinP Update
				gNotice.GCNoticeSend(Player->Index, 1, 0, 0, 0, 0, 0, this->MsgTPoint, this->PointKillMonter);
			}
			if (this->LoaiTien == 2)
			{
				gCashShop.GDCashShopAddPointSaveSend(Player->Index, 0, 0, 0, this->PointKillMonter, 0);
				//-- GobilCoin Update
				gNotice.GCNoticeSend(Player->Index, 1, 0, 0, 0, 0, 0, this->MsgTPoint, this->PointKillMonter);

			}
			if (this->LoaiTien == 3)
			{
				gCashShop.GDCashShopAddPointSaveSend(Player->Index, 0, 0, 0, 0, this->PointKillMonter);
				//-- Ruud Update
				gNotice.GCNoticeSend(Player->Index, 1, 0, 0, 0, 0, 0, this->MsgTPoint, this->PointKillMonter);

			}
			gCashShop.CGCashShopPointRecv(Player->Index);
		}

		//==== THuong POint khi parrty
		if ((OBJECT_RANGE(Player->PartyNumber) != 0) && this->PartyKillPoint > 0)
		{
			PARTY_INFO* lpParty = &gParty.m_PartyInfo[Player->PartyNumber];
			for (int n = 0; n < MAX_PARTY_USER; n++)
			{
				if (OBJECT_RANGE(lpParty->Index[n]) != 0 && Player->Index != lpParty->Index[n])
				{
					if (Player->Map == gObj[lpParty->Index[n]].Map && gObjCalcDistance(Player, &gObj[lpParty->Index[n]]) < MAX_PARTY_DISTANCE)
					{
						gCashShop.GDCashShopSubPointSaveSend(lpParty->Index[n], 0, 0, 0, 0, this->PartyKillPoint);
						//-- Ruud Update
						gCashShop.CGCashShopPointRecv(lpParty->Index[n]);
						gNotice.GCNoticeSend(lpParty->Index[n], 1, 0, 0, 0, 0, 0, this->MsgTPoint, this->PartyKillPoint);
					}
				}
			}
		}

		//=== Thuong Item khi giet du quai
		if (Player->CTCKill >= this->SLQuaiYeuCau - 1)
		{
			gItemBagManager.DropItemByIndexItemBag(this->IndexType, Player); //Gui Item cho NV
			gNotice.GCNoticeSend(Player->Index, 0, 0, 0, 0, 0, 0, this->MsgTKill);
			Player->CTCKill = 0;
		}
		else
		{
			Player->CTCKill++;
		}


		this->SendKillCTC(Player->Index);

	}

	return;
}
void cChienTruongCo::SendKillCTC(int aIndex)
{
	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}
	LPOBJ lpUser = &gObj[aIndex];

	CTCKILL_SENDCLIENT pMsg;

	pMsg.header.set(0xF4, 0x9, sizeof(pMsg));

	pMsg.QuaiKill = lpUser->CTCKill;

	DataSend(lpUser->Index, (BYTE*)&pMsg, pMsg.header.size);

}
void cChienTruongCo::CheckTimeInCTC(int aIndex)
{

	if (!this->Enabled)
	{
		return;
	}
	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->CTCTime < 0) { lpObj->CTCTime = 0; }

	if (lpObj->Map != 97)
	{
		return;
	}
	if (lpObj->CTCTime < 1)
	{
		gObjMoveGate(lpObj->Index, 17);
		this->SendInfoCTC(lpObj->Index, 0); //Cap Nhat
	}
	if (lpObj->CTCTime >= 1) {
		lpObj->CTCTime = lpObj->CTCTime - 1;
	}

	return;

}
void cChienTruongCo::CGPacketCTC(XULY_CGPACKET* aRecv, int aIndex)
{

	if (!this->Enabled)
	{
		return;
	}
	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if ((GetTickCount() - lpObj->ClickClientSend) < 2000) {
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(980));
		return;
	}

	int ThaoTac = aRecv->ThaoTac;

	if (ThaoTac == 1 && lpObj->CTCTime > 0) //Vao CTC
	{
		gObjMoveGate(lpObj->Index, 828); //sua gate nay
		this->SendKillCTC(lpObj->Index);
		this->SendInfoCTC(lpObj->Index, 0); //Cap Nhat
		return;
	}
	else if (ThaoTac == 2)
	{
		if (lpObj->CTCRegDay >= this->MaxBuyDay) //Vuot gioi han luot mua
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(981), this->MaxBuyDay);
			return;
		}
		if (lpObj->Coin1 < this->WCoinBuy) {
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(982), this->WCoinBuy);
			return;
		}
		GDSetCoinSend(lpObj->Index, -(this->WCoinBuy), 0, 0, gMessage.GetMessage(983));
		lpObj->CTCTime += (this->TimeBuyMin * 60);
		lpObj->CTCRegDay++;
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(984), this->TimeBuyMin);
		this->SendInfoCTC(lpObj->Index, 1); //Cap Nhat
		return;

	}
	lpObj->ClickClientSend = GetTickCount();
	return;
}
#endif