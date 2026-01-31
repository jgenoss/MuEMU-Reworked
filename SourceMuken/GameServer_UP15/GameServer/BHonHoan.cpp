#include "stdafx.h"
#include "BHonHoan.h"
#include "DSProtocol.h"
#include "EffectManager.h"
#include "Map.h"
#include "MemScript.h"
#include "Notice.h"
#include "Util.h"
#include "ItemOptionRate.h"
#include "ObjectManager.h"
#include "Path.h"
#include "ItemLevel.h"
#include "CustomRankUser.h"

CBHonHoan gBHonHoan;

CBHonHoan::CBHonHoan()
{
	this->Enable = false;
	this->ThongBao = false;
	gBHonHoan.mDataConfigHonHoan.clear();
}

CBHonHoan::~CBHonHoan()
{

}


void CBHonHoan::LoadConfig(char* FilePath)
{
	gBHonHoan.mDataConfigHonHoan.clear();
	this->Enable = false;
	this->ThongBao = false;

	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(FilePath);
	if (res.status != pugi::status_ok) {
		ErrorMessageBox("File %s load fail. Error: %s", FilePath, res.description());
		return;
	}
	//--
	pugi::xml_node oHonHoan = file.child("HonHoan");

	this->Enable = oHonHoan.attribute("Enable").as_int();
	this->ThongBao = oHonHoan.attribute("Enable").as_int();

	//= Mess Load
	pugi::xml_node Message = oHonHoan.child("Message");
	for (pugi::xml_node msg = Message.child("Msg"); msg; msg = msg.next_sibling())
	{
		MESSAGE_INFO_HONHOAN info;

		info.Index = msg.attribute("Index").as_int();

		strcpy_s(info.Message, msg.attribute("Text").as_string());

		this->m_MessageInfoBP.insert(std::pair<int, MESSAGE_INFO_HONHOAN>(info.Index, info));
	}
	//==Load Config
	pugi::xml_node ConfigHonHoan = oHonHoan.child("ConfigHonHoan");
	for (pugi::xml_node CapDo = ConfigHonHoan.child("CapDo"); CapDo; CapDo = CapDo.next_sibling())
	{
		CONFIDATA_HONHOAN InfoHonHoan;
		InfoHonHoan.LvHonHoan = CapDo.attribute("LvHonHoan").as_int();
		InfoHonHoan.YCItemSL = CapDo.attribute("YCItemSL").as_int();
		InfoHonHoan.YCItemID = CapDo.attribute("YCItemID").as_int();
		InfoHonHoan.YCItemLv = CapDo.attribute("YCItemLv").as_int();
		InfoHonHoan.YCWC = CapDo.attribute("YCWC").as_int();
		InfoHonHoan.YCWP = CapDo.attribute("YCWP").as_int();
		InfoHonHoan.YCGP = CapDo.attribute("YCGP").as_int();
		InfoHonHoan.TangMau = CapDo.attribute("TangMau").as_int();
		InfoHonHoan.TangSD = CapDo.attribute("TangSD").as_int();
		InfoHonHoan.TangST = CapDo.attribute("TangST").as_int();
		InfoHonHoan.TangPT = CapDo.attribute("TangPT").as_int();
		this->mDataConfigHonHoan.insert(std::pair<int, CONFIDATA_HONHOAN>(InfoHonHoan.LvHonHoan, InfoHonHoan));
	}
		
	LogAdd(LOG_BLUE, "[HonHoan] Enable %d Size %d", this->Enable, this->mDataConfigHonHoan.size());
}

char* CBHonHoan::GetMessage(int index) // OK
{
	std::map<int, MESSAGE_INFO_HONHOAN>::iterator it = this->m_MessageInfoBP.find(index);

	if (it == this->m_MessageInfoBP.end())
	{
		char Error[256];
		wsprintf(Error, "Could not find message %d!", index);
		return Error;
	}
	else
	{
		return it->second.Message;
	}
}

CONFIDATA_HONHOAN* CBHonHoan::GetConfigLvHonHoan(int LvHonHoan)
{
	std::map<int, CONFIDATA_HONHOAN>::iterator it = this->mDataConfigHonHoan.find(LvHonHoan);

	if (it == this->mDataConfigHonHoan.end())
	{
		return 0;
	}
	else
	{
		return &it->second;
	}

}


void CBHonHoan::SendInfoClient(int aIndex) // OK
{
	if (!this->Enable)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, this->GetMessage(0));
		return;
	}

	if (OBJECT_RANGE(aIndex) == 0)
	{
		return;
	}
	if (gObjIsConnected(aIndex) == false)
	{
		return;
	}
	
	LPOBJ lpObj = &gObj[aIndex];


	BYTE send[4096];

	CSEV_COUNTLIST pMsg;

	pMsg.header.set(0xD3, 0x01, 0);

	int size = sizeof(pMsg);

	pMsg.Count = 0;

	for (int i = 0; i < this->mDataConfigHonHoan.size(); i++)
	{
		if (size + sizeof(this->mDataConfigHonHoan[i]) > 4096)
		{
			LogAdd(LOG_RED, "(%s %d) Data qua dai !!", __FILE__, __LINE__);
			return;
		}
		memcpy(&send[size], &this->mDataConfigHonHoan[i], sizeof(this->mDataConfigHonHoan[i]));
		size += sizeof(this->mDataConfigHonHoan[i]);

		pMsg.Count++;
	}
	pMsg.header.size[0] = SET_NUMBERHB(size);

	pMsg.header.size[1] = SET_NUMBERLB(size);

	memcpy(send, &pMsg, sizeof(pMsg));
	DataSend(aIndex, send, size);
}
void CBHonHoan::GetOptionHonHoan(LPOBJ lpObj, bool flag)
{
	if (flag != 0)
	{
		return;
	}
	//--
	if (lpObj->CB_Status1 != 0)
	{
		return; //
	}

	if (!this->Enable)
	{
		return;
	}
	if (OBJECT_RANGE(lpObj->Index) == 0)
	{
		return;
	}
	if (gObjIsConnected(lpObj->Index) == false)
	{
		return;
	}
	CONFIDATA_HONHOAN* BGetDataHonHoan = this->GetConfigLvHonHoan(lpObj->CapDoHonHoan);
	if(BGetDataHonHoan ==0)
	{
		return;
	}
	// Sat Thuong
	lpObj->MagicDamageMin		+= BGetDataHonHoan->TangST;
	lpObj->MagicDamageMax		+= BGetDataHonHoan->TangST;
	lpObj->PhysiDamageMinLeft	+= BGetDataHonHoan->TangST;
	lpObj->PhysiDamageMinRight	+= BGetDataHonHoan->TangST;
	lpObj->PhysiDamageMaxLeft	+= BGetDataHonHoan->TangST;
	lpObj->PhysiDamageMaxRight	+= BGetDataHonHoan->TangST;
	// PT
	lpObj->Defense += BGetDataHonHoan->TangPT;
	// MAU
	lpObj->AddLife += BGetDataHonHoan->TangMau;
	// SD
	lpObj->AddShield += BGetDataHonHoan->TangSD;
}
bool CBHonHoan::NangCapHonHoan(int aIndex) // OK
{
	if (!this->Enable)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, this->GetMessage(0));
		return 0;
	}

	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}
	if (gObjIsConnected(aIndex) == false)
	{
		return 0;
	}

	LPOBJ lpObj = &gObj[aIndex];

	CONFIDATA_HONHOAN* GetDataHonHoan = this->GetConfigLvHonHoan(lpObj->CapDoHonHoan);

	if (!GetDataHonHoan)
	{
		return 0;
	}

	

	if (GetDataHonHoan->YCItemSL > 0)
	{
		lpObj->ChaosLock = 1;
		int count = gItemManager.GetInventoryItemCount(lpObj, GetDataHonHoan->YCItemID, GetDataHonHoan->YCItemLv);

		if (count < GetDataHonHoan->YCItemSL)
		{
			lpObj->ChaosLock = 0;
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(1), GetDataHonHoan->YCItemSL, gItemLevel.GetItemName(GetDataHonHoan->YCItemID, GetDataHonHoan->YCItemLv));
			return false;
		}

		
	}
	int CheckWC = GetDataHonHoan->YCWC;
	int CheckWP = GetDataHonHoan->YCWP;
	int CheckGP = GetDataHonHoan->YCGP;

	if (CheckWC > lpObj->Coin1)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(2), CheckWC, "WC");
		return false;
	}
	if (CheckWP > lpObj->Coin2)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(2), CheckWP, "WP");
		return false;
	}
	if (CheckGP > lpObj->Coin3)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(2), CheckGP, "GP");
		return false;
	}
	if (CheckWC > 0 || CheckWP > 0 || CheckGP > 0)
	{
		GDSetCoinSend(lpObj->Index, (CheckWC > 0 ? -CheckWC : 0), (CheckWP > 0 ? -CheckWP : 0), (CheckGP > 0 ? -CheckGP : 0), "HonHoanTruCoin");
	}
	
	gItemManager.DeleteInventoryItemCount(lpObj, GetDataHonHoan->YCItemID, GetDataHonHoan->YCItemLv, GetDataHonHoan->YCItemSL);
		lpObj->ChaosLock = 0;

	lpObj->CapDoHonHoan++;
	if (this->ThongBao)
	{
		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(4), lpObj->Name, lpObj->CapDoHonHoan);
	}
	gNotice.GCNoticeSend(aIndex,1, 0, 0, 0, 0, 0, this->GetMessage(3), lpObj->CapDoHonHoan);
	gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
	gObjectManager.CharacterCalcAttribute(lpObj->Index);

	return 1;

}