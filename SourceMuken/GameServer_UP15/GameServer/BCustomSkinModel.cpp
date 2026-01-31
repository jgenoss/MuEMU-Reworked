#include "stdafx.h"
#include "BCustomSkinModel.h"
#include "Message.h"
#include "DSProtocol.h"
#include "Notice.h"
#include "ItemManager.h"
#include "DSProtocol.h"
#include "GameMain.h"
#include "Util.h"
#include "Log.h"
#include "ItemLevel.h"
#include "ObjectManager.h"
#include "Map.h"
#include "ServerInfo.h"
#include "MapServerManager.h"
#include "ItemOption.h"


BCustomSkinModel gBCustomSkinModel;

void BCustomSkinModel::Load(char* FilePath)
{
	
	this->m_Config = new CUSTOM_SKIN_CONFIG;

	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(FilePath);
	if (res.status != pugi::status_ok) {
		ErrorMessageBox("File %s load fail. Error: %s", FilePath, res.description());
		return;
	}
	pugi::xml_node oCustomSkinModel = file.child("CustomSkinModel");
	this->m_Config->Enable = oCustomSkinModel.attribute("Enable").as_int();
	this->m_Config->Firework = oCustomSkinModel.attribute("Firework").as_int();
	this->m_Config->Notice = oCustomSkinModel.attribute("Notice").as_int();
	strncpy_s(this->m_Config->Msg, oCustomSkinModel.attribute("Msg").as_string(), sizeof(this->m_Config->Msg));

	this->m_MessageInfoBP.clear();
	pugi::xml_node Message = oCustomSkinModel.child("MessageInfo");
	for (pugi::xml_node msg = Message.child("Message"); msg; msg = msg.next_sibling())
	{
		CUSTOM_SKIN_MESSAGE info;

		info.Index = msg.attribute("Index").as_int();

		strncpy_s(info.Message, msg.attribute("Text").as_string(), sizeof(info.Message));

		this->m_MessageInfoBP.insert(std::pair<int, CUSTOM_SKIN_MESSAGE>(info.Index, info));
	}

	this->m_SkinModelData.clear();
	pugi::xml_node SkinModel = oCustomSkinModel.child("SkinModel");
	for (pugi::xml_node list = SkinModel.child("List"); list; list = list.next_sibling())
	{
		SKIN_MODEL_DATA info;
		static int SkinModeCount = 0;
		info.Index = SkinModeCount;
		info.SkinIndex = list.attribute("SkinIndex").as_int();
		info.Coin = list.attribute("WcoinP").as_int(0);
		info.ValueOp[0] = list.attribute("ValueOp1").as_int(0);
		//==
		info.ValueOp[1] = list.attribute("ValueOp2").as_int(0);
		//==
		info.ValueOp[2] = list.attribute("ValueOp3").as_int(0);
		//==
		info.ValueOp[3] = list.attribute("ValueOp4").as_int(0);

		strncpy_s(info.NameSkin, list.attribute("NameSkin").as_string(), sizeof(info.NameSkin));
		this->m_SkinModelData.push_back(info);
	}


	LogAdd(LOG_BLUE, "[SkinModel] Enable (%d) Load Count %d Item Skin %d", this->m_Config->Enable, this->m_SkinModelData.size());
}

char* BCustomSkinModel::GetMessage(int index) // OK
{
	std::map<int, CUSTOM_SKIN_MESSAGE>::iterator it = this->m_MessageInfoBP.find(index);

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


void BCustomSkinModel::GDGetListBuy(int aIndex)
{
	if (!this->m_Config->Enable)
	{
		return;
	}

	if (gObjIsConnected(aIndex) == false)
	{
		return;
	}

	//==Send DS Get Danh Sach Skin Da Mua
	GSSENDDS_GETLISTISBUYSKIN pMsg;

	pMsg.header.set(0xD9, 0x01, sizeof(pMsg));

	memcpy(pMsg.AccountID, gObj[aIndex].Account, sizeof(pMsg.AccountID));
	pMsg.aIndex = aIndex;
	gDataServerConnection.DataSend((BYTE*)& pMsg, pMsg.header.size);
	//	LogAdd(LOG_RED, "GDGetListBuy %d [%s]", pMsg.aIndex, pMsg.AccountID);
}
void BCustomSkinModel::GDSaveSkinBuy(int aIndex, int SkinIndex)
{
	if (!this->m_Config->Enable)
	{
		return;
	}

	if (gObjIsConnected(aIndex) == false)
	{
		return;
	}

	//==Send DS Get Danh Sach Skin Da Mua
	GSSENDDS_GETLISTISBUYSKIN pMsg;

	pMsg.header.set(0xD9, 0x02, sizeof(pMsg));

	memcpy(pMsg.AccountID, gObj[aIndex].Account, sizeof(pMsg.AccountID));
	pMsg.aIndex = SkinIndex; //===Save Skin Da Mua
	gDataServerConnection.DataSend((BYTE*)& pMsg, pMsg.header.size);
	//	LogAdd(LOG_RED, "GDGetListBuy %d [%s]", pMsg.aIndex, pMsg.AccountID);
}

void BCustomSkinModel::RecvGDGetListBuy(CBCUSTOM_LOAD_COUNT * lpMsg)
{
	if (!this->m_Config->Enable)
	{
		return;
	}

	if (gObjIsConnected(lpMsg->aIndex) == false)
	{
		return;
	}
	LPOBJ lpObj = &gObj[lpMsg->aIndex];

	for (int n = 0; n < lpMsg->count; n++)
	{
		BCUSTOM_SKINMODEL_DATA* lpInfo = (BCUSTOM_SKINMODEL_DATA*)(((BYTE*)lpMsg) + sizeof(CBCUSTOM_LOAD_COUNT) + (sizeof(BCUSTOM_SKINMODEL_DATA) * n));

		this->UpdateListSkinBuy(lpMsg->aIndex, lpInfo->SkinIndex);
		//LogAdd(LOG_RED, "RecvGDGetListBuy %d", lpInfo->SkinIndex);
	}
	gBCustomSkinModel.CGListSkinModelSend(lpObj->Index);//Send List Skin
}
//==== Update Vao List Khi Thao Tac Mua Skin
bool BCustomSkinModel::UpdateListSkinBuy(int aIndex, int SkinIndex)
{
	if (!this->m_Config->Enable)
	{
		return 0;
	}

	if (gObjIsConnected(aIndex) == false)
	{
		return 0;
	}
	LPOBJ lpObj = &gObj[aIndex];
	//==CBLoadCustom
	for (int n = 0; n < MAX_BUYSKIN_CB; n++)
	{
		if (lpObj->mInfoBuySkin[n].SkinIndex == -1)
		{
			lpObj->mInfoBuySkin[n].AddListBuySkin(SkinIndex);
			return 1;
		}
	}
	return 0;
}
bool BCustomSkinModel::CheckSkinIsBuy(int aIndex, int SkinIndex)
{
	if (!this->m_Config->Enable)
	{
		return 0;
	}

	if (gObjIsConnected(aIndex) == false)
	{
		return 0;
	}

	LPOBJ lpObj = &gObj[aIndex];
	for (int n = 0; n < MAX_BUYSKIN_CB; n++)
	{
		if (lpObj->mInfoBuySkin[n].IsBuy(SkinIndex))
		{
			return 1;
		}

	}
	return 0;
}

int BCustomSkinModel::GetCBSkinChange(int aIndex)
{
	if (!this->m_Config->Enable)
	{
		return -1;
	}

	if (gObjIsConnected(aIndex) == false)
	{
		return -1;
	}
	LPOBJ lpObj = &gObj[aIndex];
	//=== Set Skin CBLoad
	if (lpObj->UserSkinPick > 0)
	{
		return lpObj->UserSkinPick;
	}
	return -1;
}
//===Get List > Send Client
void BCustomSkinModel::CGListSkinModelSend(int Index)
{
	if (!this->m_Config->Enable || !this->m_SkinModelData.size())
	{
		return;
	}

	if (gObjIsConnected(Index) == false)
	{
		return;
	}

	BYTE send[4096];

	BPMSG_CUSTOM_SKIN_SEND pMsg;

	pMsg.header.set(0xD3, 0x10, 0);

	int size = sizeof(pMsg);

	pMsg.count = 0;

	BCUSTOM_SKINMODEL_DATA info;

	for (int i = 0; i < this->m_SkinModelData.size(); i++)
	{
		info.SkinIndex = this->m_SkinModelData[i].SkinIndex;

		info.StatusBuy = this->CheckSkinIsBuy(Index, this->m_SkinModelData[i].SkinIndex);

		pMsg.count++;

		memcpy(&send[size], &info, sizeof(info));
		size += sizeof(info);

	}

	pMsg.header.size[0] = SET_NUMBERHB(size);
	pMsg.header.size[1] = SET_NUMBERLB(size);
	// ---
	memcpy(send, &pMsg, sizeof(pMsg));

	DataSend(Index, send, size);

	//LogAdd(LOG_RED, "SendList Model Skin OK !!");
}
SKIN_MODEL_DATA* BCustomSkinModel::GetInfoSkinModel(int SkinIndex)
{
	for (int i = 0; i < this->m_SkinModelData.size(); i++)
	{
		if (this->m_SkinModelData[i].SkinIndex == SkinIndex)
		{
			return &this->m_SkinModelData[i];
		}
	}
	return 0;
}
//=== Send Info Model Select
void BCustomSkinModel::CGGetInfoSelectSkin(int Index, int SkinIndex)
{
	if (!this->m_Config->Enable)
	{
		return;
	}

	if (gObjIsConnected(Index) == false)
	{
		return;
	}
	//LogAdd(LOG_RED, "CGGetInfoSelectSkin %d", SkinIndex);
	SKIN_MODEL_DATA* GetInfoSkin = this->GetInfoSkinModel(SkinIndex);

	if (!GetInfoSkin) { return; }

	BYTE send[4096];

	BPMSG_CUSTOM_SKIN_SEND pMsg;

	pMsg.header.set(0xD3, 0x12, 0);

	int size = sizeof(pMsg);

	pMsg.count = 0;

	SKIN_MODEL_DATA info = *GetInfoSkin;

	pMsg.count++;

	memcpy(&send[size], &info, sizeof(info));
	size += sizeof(info);

	pMsg.header.size[0] = SET_NUMBERHB(size);
	pMsg.header.size[1] = SET_NUMBERLB(size);
	// ---
	memcpy(send, &pMsg, sizeof(pMsg));

	DataSend(Index, send, size);

	//LogAdd(LOG_RED, "Send Info Select !!");
}
//===Active Dmg Bonus
void BCustomSkinModel::ActiveBonusSkin(LPOBJ lpObj, bool flag)
{
	if (flag != 0)
	{
		return;
	}
	if (lpObj->CB_Status1 != 0)
	{
		return; //
	}

	//if (lpObj->UserSkinPick > 0)
	{
		//SKIN_MODEL_DATA* GetInfoSkin = this->GetInfoSkinModel(lpObj->UserSkinPick);
		//if (!GetInfoSkin) { return; }
		//lpObj->PhysiDamageMinLeft += lpObj->PhysiDamageMinLeft * GetInfoSkin->ValueOp[0] / 100;
		//lpObj->PhysiDamageMinRight += lpObj->PhysiDamageMinRight * GetInfoSkin->ValueOp[0] / 100;
		//lpObj->PhysiDamageMaxLeft += lpObj->PhysiDamageMaxLeft * GetInfoSkin->ValueOp[0] / 100;
		//lpObj->PhysiDamageMaxRight += lpObj->PhysiDamageMaxRight * GetInfoSkin->ValueOp[0] / 100;
		//lpObj->PhysiDamageMin += lpObj->PhysiDamageMin * GetInfoSkin->ValueOp[0] / 100;
		//lpObj->PhysiDamageMax += lpObj->PhysiDamageMax * GetInfoSkin->ValueOp[0] / 100;
		//// 
		//lpObj->Defense += GetInfoSkin->ValueOp[1];
		//// 
		//lpObj->AddLife += GetInfoSkin->ValueOp[2];
		//lpObj->AddMana += GetInfoSkin->ValueOp[3];
		for (int i = 0; i < this->m_SkinModelData.size(); i++)
		{
			if (this->CheckSkinIsBuy(lpObj->Index, this->m_SkinModelData[i].SkinIndex) == 1)
			{
				lpObj->PhysiDamageMinLeft += lpObj->PhysiDamageMinLeft * this->m_SkinModelData[i].ValueOp[0] / 100;
				lpObj->PhysiDamageMinRight += lpObj->PhysiDamageMinRight * this->m_SkinModelData[i].ValueOp[0] / 100;
				lpObj->PhysiDamageMaxLeft += lpObj->PhysiDamageMaxLeft * this->m_SkinModelData[i].ValueOp[0] / 100;
				lpObj->PhysiDamageMaxRight += lpObj->PhysiDamageMaxRight * this->m_SkinModelData[i].ValueOp[0] / 100;
				lpObj->PhysiDamageMin += lpObj->PhysiDamageMin * this->m_SkinModelData[i].ValueOp[0] / 100;
				lpObj->PhysiDamageMax += lpObj->PhysiDamageMax * this->m_SkinModelData[i].ValueOp[0] / 100;
				// 
				lpObj->Defense += this->m_SkinModelData[i].ValueOp[1];
				// 
				lpObj->AddLife += this->m_SkinModelData[i].ValueOp[2];
				lpObj->AddMana += this->m_SkinModelData[i].ValueOp[3];
			}
		}

	}
	//LogAdd(LOG_RED, "ActiveBonusSkin");
}
//===Thao Tac Mua & Kich Hoat Skin
void BCustomSkinModel::RecvActionSkin(int aIndex, int SkinIndexAction)
{
	if (!this->m_Config->Enable)
	{
		return;
	}

	if (gObjIsConnected(aIndex) == false)
	{
		return;
	}
	LPOBJ lpObj = &gObj[aIndex];
	//LogAdd(LOG_RED, "RecvActionSkin [%s] %d", lpObj->Name,SkinIndexAction);
	if (SkinIndexAction == -1)
	{
		goto ChangeSkin;
		return;
	}
	bool StatusBuy = this->CheckSkinIsBuy(aIndex, SkinIndexAction);


	if (!StatusBuy && SkinIndexAction != -1) //==Check Buy Skin
	{
		//LogAdd(LOG_RED, "Skin Chua Mua");

		SKIN_MODEL_DATA* GetInfoSkin = this->GetInfoSkinModel(SkinIndexAction);
		if (!GetInfoSkin) { return; }
		//===Del Coin
		if (lpObj->Coin2 < GetInfoSkin->Coin)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(1), GetInfoSkin->Coin);
			return;
		}
		if (GetInfoSkin->Coin > 0 )
		{
			GDSetCoinSend(lpObj->Index, 0, -(GetInfoSkin->Coin), 0, "TruCoinMuaSkin");
		}
		//==Send Effect
		if (this->m_Config->Firework == 1)
		{
			GCServerCommandSend(lpObj->Index, 0, lpObj->X, lpObj->Y);
		}
		else if (this->m_Config->Firework == 2)
		{
			GCServerCommandSend(lpObj->Index, 2, lpObj->X, lpObj->Y);
		}
		else if (this->m_Config->Firework == 3)
		{
			GCServerCommandSend(lpObj->Index, 58, SET_NUMBERHB(lpObj->Index), SET_NUMBERLB(lpObj->Index));
		}
		char tmp[255];
		char tmp2[255];
		if (this->m_Config->Notice == 1) { //Thong Bao trong Sub
			gNotice.GCNoticeSend(lpObj->Index, 0, 0, 0, 0, 0, 0, this->m_Config->Msg, lpObj->Name, GetInfoSkin->NameSkin);
		}
		else if (this->m_Config->Notice == 2)
		{ //Thong Bao Toan Sub
			wsprintf(tmp, this->m_Config->Msg, lpObj->Name, GetInfoSkin->NameSkin);
			GDGlobalNoticeSend(gMapServerManager.GetMapServerGroup(), 0, 0, 0, 0, 0, 0, tmp);
		}
		else if (this->m_Config->Notice == 3)
		{ //Thong Bao Toan Sub
			wsprintf(tmp, this->m_Config->Msg, lpObj->Name, GetInfoSkin->NameSkin);
			wsprintf(tmp2, "%s %s", gServerInfo.m_ServerName, tmp);
			GDGlobalNoticeSend(gMapServerManager.GetMapServerGroup(), 0, 0, 0, 0, 0, 0, tmp2);
		}

		this->UpdateListSkinBuy(aIndex, SkinIndexAction); //=== them vao list da mua
		this->GDSaveSkinBuy(aIndex, SkinIndexAction); //==save sql
		this->CGListSkinModelSend(aIndex);//==Lam moi list
	}
ChangeSkin:
	lpObj->UserSkinPick = (SkinIndexAction == -1) ? 0 : SkinIndexAction;
	gObjectManager.CharacterCalcAttribute(aIndex);
	//===Update Skin Character
	lpObj->Change = SkinIndexAction;
	gObjViewportListProtocolCreate(lpObj);
	gObjectManager.CharacterUpdateMapEffect(lpObj);
}