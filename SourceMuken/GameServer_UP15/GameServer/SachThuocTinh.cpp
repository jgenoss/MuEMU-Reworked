#include "StdAfx.h"
#include "user.h"
#include "SachThuocTinh.h"
#include "DSProtocol.h"
#include "GameMain.h"
#include "Path.h"
#include "MemScript.h"
#include "Util.h"
#include "CashShop.h"
#include "Message.h"
#include "Notice.h"
#include "ItemBagManager.h"
#include "ItemManager.h"
#include "ObjectManager.h"

#if (SACHTHUOCTINH_NEW == 1)

SachThuocTinh gSachThuocTinh;

SachThuocTinh::SachThuocTinh() // OK
{

}

SachThuocTinh::~SachThuocTinh() // OK
{

}



//===============================================================================================================================
void SachThuocTinh::GDSaveData(int aIndex)
{
	// ----
	LPOBJ lpUser = &gObj[aIndex];
	// ----
	SACHTHUOCTINH_GD_SAVE_DATA pRequest;
	pRequest.header.set(0xB0, 0x04, sizeof(pRequest));
	memcpy(pRequest.Name, lpUser->Name, 11);
	pRequest.index = aIndex;
	//----
	pRequest.SACHTHUOCTINH_01 = lpUser->SACHTHUOCTINH.SACHTHUOCTINH_01;
	pRequest.SACHTHUOCTINH_02 = lpUser->SACHTHUOCTINH.SACHTHUOCTINH_02;
	pRequest.SACHTHUOCTINH_03 = lpUser->SACHTHUOCTINH.SACHTHUOCTINH_03;
	pRequest.SACHTHUOCTINH_04 = lpUser->SACHTHUOCTINH.SACHTHUOCTINH_04;
	pRequest.SACHTHUOCTINH_05 = lpUser->SACHTHUOCTINH.SACHTHUOCTINH_05;
	pRequest.SACHTHUOCTINH_06 = lpUser->SACHTHUOCTINH.SACHTHUOCTINH_06;
	pRequest.SACHTHUOCTINH_07 = lpUser->SACHTHUOCTINH.SACHTHUOCTINH_07;
	//----
	gDataServerConnection.DataSend((BYTE*)&pRequest, pRequest.header.size);
}
// -------------------------------------------------------------------------------
void SachThuocTinh::GDReqData(int aIndex)
{

	LPOBJ lpObj = &gObj[aIndex];
	SACHTHUOCTINH_GD_REQ_DATA pMsg;
	pMsg.header.set(0xB0, 0x03, sizeof(pMsg));
	pMsg.index = aIndex;
	memcpy(pMsg.name, lpObj->Name, sizeof(pMsg.name));
	gDataServerConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);

}
// -------------------------------------------------------------------------------
void SachThuocTinh::GDSaveUserInfo(int aIndex)	//-> Complete
{
	this->GDSaveData(aIndex);
}
// -------------------------------------------------------------------------------
void SachThuocTinh::GDReqUserInfo(int aIndex)	//-> Complete
{
	// ----
	this->GDReqData(aIndex);
}
// -------------------------------------------------------------------------------
void SachThuocTinh::DGGetData(SACHTHUOCTINH_DG_GET_DATA * aRecv)
{
	// ----
	LPOBJ lpUser = &gObj[aRecv->index];
	// ----

	if (aRecv->SACHTHUOCTINH_01 < 0)
	{
		aRecv->SACHTHUOCTINH_01 = 0;
	}
	else if (aRecv->SACHTHUOCTINH_02 < 0)
	{
		aRecv->SACHTHUOCTINH_02 = 0;
	}
	else if (aRecv->SACHTHUOCTINH_03 < 0)
	{
		aRecv->SACHTHUOCTINH_03 = 0;
	}
	else if (aRecv->SACHTHUOCTINH_04 < 0)
	{
		aRecv->SACHTHUOCTINH_04 = 0;
	}
	else if (aRecv->SACHTHUOCTINH_05 < 0)
	{
		aRecv->SACHTHUOCTINH_05 = 0;
	}
	else if (aRecv->SACHTHUOCTINH_06 < 0)
	{
		aRecv->SACHTHUOCTINH_06 = 0;
	}
	else if (aRecv->SACHTHUOCTINH_07 < 0)
	{
		aRecv->SACHTHUOCTINH_07 = 0;
	}
	// ----
	lpUser->SACHTHUOCTINH.SACHTHUOCTINH_01 = aRecv->SACHTHUOCTINH_01;
	lpUser->SACHTHUOCTINH.SACHTHUOCTINH_02 = aRecv->SACHTHUOCTINH_02;
	lpUser->SACHTHUOCTINH.SACHTHUOCTINH_03 = aRecv->SACHTHUOCTINH_03;
	lpUser->SACHTHUOCTINH.SACHTHUOCTINH_04 = aRecv->SACHTHUOCTINH_04;
	lpUser->SACHTHUOCTINH.SACHTHUOCTINH_05 = aRecv->SACHTHUOCTINH_05;
	lpUser->SACHTHUOCTINH.SACHTHUOCTINH_06 = aRecv->SACHTHUOCTINH_06;
	lpUser->SACHTHUOCTINH.SACHTHUOCTINH_07 = aRecv->SACHTHUOCTINH_07;
	//----
}
// -------------------------------------------------------------------------------
void SachThuocTinh::Load()
{
	this->MAX_THUOC_TINH_02 = GetPrivateProfileInt("Config", "MAX_THUOC_TINH_02", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->MAX_THUOC_TINH_03 = GetPrivateProfileInt("Config", "MAX_THUOC_TINH_03", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->MAX_THUOC_TINH_04 = GetPrivateProfileInt("Config", "MAX_THUOC_TINH_04", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->MAX_THUOC_TINH_05 = GetPrivateProfileInt("Config", "MAX_THUOC_TINH_05", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->MAX_THUOC_TINH_06 = GetPrivateProfileInt("Config", "MAX_THUOC_TINH_06", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->MAX_THUOC_TINH_07 = GetPrivateProfileInt("Config", "MAX_THUOC_TINH_07", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));

	GetPrivateProfileString("Text", "MSG_01", "BAN DA DAT CAP DO TOI DA", MSG_01, 1024, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	GetPrivateProfileString("Text", "MSG_02", "BAN CAN 1 %s SACH THUOC TINH", MSG_02, 1024, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));

	this->OPTION_LEVEL_01 = GetPrivateProfileInt("Option", "OPTION_LEVEL_01", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_LEVEL_02 = GetPrivateProfileInt("Option", "OPTION_LEVEL_02", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_LEVEL_03 = GetPrivateProfileInt("Option", "OPTION_LEVEL_03", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_LEVEL_04 = GetPrivateProfileInt("Option", "OPTION_LEVEL_04", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_LEVEL_05 = GetPrivateProfileInt("Option", "OPTION_LEVEL_05", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_LEVEL_06 = GetPrivateProfileInt("Option", "OPTION_LEVEL_06", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_LEVEL_07 = GetPrivateProfileInt("Option", "OPTION_LEVEL_07", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_LEVEL_08 = GetPrivateProfileInt("Option", "OPTION_LEVEL_08", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_LEVEL_09 = GetPrivateProfileInt("Option", "OPTION_LEVEL_09", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_LEVEL_10 = GetPrivateProfileInt("Option", "OPTION_LEVEL_10", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_LEVEL_11 = GetPrivateProfileInt("Option", "OPTION_LEVEL_11", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_LEVEL_12 = GetPrivateProfileInt("Option", "OPTION_LEVEL_12", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));

	this->OPTION_ACTIVE_01 = GetPrivateProfileInt("Option", "OPTION_ACTIVE_01", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_ACTIVE_02 = GetPrivateProfileInt("Option", "OPTION_ACTIVE_02", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_ACTIVE_03 = GetPrivateProfileInt("Option", "OPTION_ACTIVE_03", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_ACTIVE_04 = GetPrivateProfileInt("Option", "OPTION_ACTIVE_04", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_ACTIVE_05 = GetPrivateProfileInt("Option", "OPTION_ACTIVE_05", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_ACTIVE_06 = GetPrivateProfileInt("Option", "OPTION_ACTIVE_06", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_ACTIVE_07 = GetPrivateProfileInt("Option", "OPTION_ACTIVE_07", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_ACTIVE_08 = GetPrivateProfileInt("Option", "OPTION_ACTIVE_08", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_ACTIVE_09 = GetPrivateProfileInt("Option", "OPTION_ACTIVE_09", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_ACTIVE_10 = GetPrivateProfileInt("Option", "OPTION_ACTIVE_10", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_ACTIVE_11 = GetPrivateProfileInt("Option", "OPTION_ACTIVE_11", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
	this->OPTION_ACTIVE_12 = GetPrivateProfileInt("Option", "OPTION_ACTIVE_12", 0, gPath.GetFullPath("Custom\\CustomSachThuocTinh.ini"));
}
// -------------------------------------------------------------------------------

// -------------------------------------------------------------------------------
void SachThuocTinh::BUG_SACHTHUOCTINH(LPOBJ lpObj, SACHTHUOCTINH_REQ *aRecv)
{
	//-----------------------------------------------
	if (aRecv->Number == 1)
	{
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 300)
		{
			//gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		if (lpObj->SACHTHUOCTINH.SACHTHUOCTINH_01 >  0) // < 30
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->MSG_01);
			return;
		}

		int SachThuocTinh1 = 0;
		for (int x = 12; x < INVENTORY_MAIN_SIZE; x++)
		{
			if (lpObj->Inventory[x].IsItem() == TRUE)
			{
				if (lpObj->Inventory[x].m_Index == GET_ITEM(14, 450))
				{
					SachThuocTinh1 = 1;
					gItemManager.InventoryDelItem(lpObj->Index, x);
					gItemManager.GCItemDeleteSend(lpObj->Index, x, 1);
					lpObj->SACHTHUOCTINH.SACHTHUOCTINH_01 += 1; // Thay Đổi
					this->GDSaveUserInfo(lpObj->Index);
					gObjectManager.CharacterCalcAttribute(lpObj->Index);
					break;
				}
			}
		}
		if (SachThuocTinh1 == 0)
		{
			char text[100];
			wsprintf(text, this->MSG_02, gItemManager.GetItemName(GET_ITEM(14, 450)));
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, text);
		}
		GetInfoThuocTinh(lpObj);
		GetInfoThuocTinhAtive(lpObj);
		//Set Delay
		//lpObj->ClickClientSend = GetTickCount();
	}
	//-----
	else if (aRecv->Number == 2)
	{
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		if (lpObj->SACHTHUOCTINH.SACHTHUOCTINH_02 >  this->MAX_THUOC_TINH_02) // < 30
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->MSG_01);
			return;
		}

		int SachThuocTinh1 = 0;
		for (int x = 12; x < INVENTORY_MAIN_SIZE; x++)
		{
			if (lpObj->Inventory[x].IsItem() == TRUE)
			{
				if (lpObj->Inventory[x].m_Index == GET_ITEM(14, 451))
				{
					SachThuocTinh1 = 1;
					gItemManager.InventoryDelItem(lpObj->Index, x);
					gItemManager.GCItemDeleteSend(lpObj->Index, x, 1);
					lpObj->SACHTHUOCTINH.SACHTHUOCTINH_02 += 1; // Thay Đổi
					this->GDSaveUserInfo(lpObj->Index);
					gObjectManager.CharacterCalcAttribute(lpObj->Index);
					break;
				}
			}
		}
		if (SachThuocTinh1 == 0)
		{
			char text[100];
			wsprintf(text, this->MSG_02, gItemManager.GetItemName(GET_ITEM(14, 451)));
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, text);
		}
		GetInfoThuocTinh(lpObj);
		GetInfoThuocTinhAtive(lpObj);
		//Set Delay
		//lpObj->ClickClientSend = GetTickCount();

	}
	//-------------------------------------------------------------------------------------------------------------
	else if (aRecv->Number == 3)
	{
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		if (lpObj->SACHTHUOCTINH.SACHTHUOCTINH_03 >  this->MAX_THUOC_TINH_03) // < 45
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->MSG_01);
			return;
		}

		int SachThuocTinh1 = 0;
		for (int x = 12; x < INVENTORY_MAIN_SIZE; x++)
		{
			if (lpObj->Inventory[x].IsItem() == TRUE)
			{
				if (lpObj->Inventory[x].m_Index == GET_ITEM(14, 452))
				{
					SachThuocTinh1 = 1;
					gItemManager.InventoryDelItem(lpObj->Index, x);
					gItemManager.GCItemDeleteSend(lpObj->Index, x, 1);
					lpObj->SACHTHUOCTINH.SACHTHUOCTINH_03 += 1; // Thay Đổi
					this->GDSaveUserInfo(lpObj->Index);
					gObjectManager.CharacterCalcAttribute(lpObj->Index);
					break;
				}
			}
		}
		if (SachThuocTinh1 == 0)
		{
			char text[100];
			wsprintf(text, this->MSG_02, gItemManager.GetItemName(GET_ITEM(14, 452)));
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, text);
		}
		GetInfoThuocTinh(lpObj);
		GetInfoThuocTinhAtive(lpObj);
		//Set Delay
		//lpObj->ClickClientSend = GetTickCount();

	}
	//-------------------------------------------------------------------------------------------------------------
	else if (aRecv->Number == 4)
	{
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		if (lpObj->SACHTHUOCTINH.SACHTHUOCTINH_04 >  this->MAX_THUOC_TINH_04) // < 45
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->MSG_01);
			return;
		}

		int SachThuocTinh1 = 0;
		for (int x = 12; x < INVENTORY_MAIN_SIZE; x++)
		{
			if (lpObj->Inventory[x].IsItem() == TRUE)
			{
				if (lpObj->Inventory[x].m_Index == GET_ITEM(14, 453))
				{
					SachThuocTinh1 = 1;
					gItemManager.InventoryDelItem(lpObj->Index, x);
					gItemManager.GCItemDeleteSend(lpObj->Index, x, 1);
					lpObj->SACHTHUOCTINH.SACHTHUOCTINH_04 += 1; // Thay Đổi
					this->GDSaveUserInfo(lpObj->Index);
					gObjectManager.CharacterCalcAttribute(lpObj->Index);
					break;
				}
			}
		}
		if (SachThuocTinh1 == 0)
		{
			char text[100];
			wsprintf(text, this->MSG_02, gItemManager.GetItemName(GET_ITEM(14, 453)));
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, text);
		}
		GetInfoThuocTinh(lpObj);
		GetInfoThuocTinhAtive(lpObj);
		//Set Delay
		//lpObj->ClickClientSend = GetTickCount();

	}
	//-------------------------------------------------------------------------------------------------------------
	else if (aRecv->Number == 5)
	{
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		if (lpObj->SACHTHUOCTINH.SACHTHUOCTINH_05 >  this->MAX_THUOC_TINH_05) // < 45
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->MSG_01);
			return;
		}

		int SachThuocTinh1 = 0;
		for (int x = 12; x < INVENTORY_MAIN_SIZE; x++)
		{
			if (lpObj->Inventory[x].IsItem() == TRUE)
			{
				if (lpObj->Inventory[x].m_Index == GET_ITEM(14, 454))
				{
					SachThuocTinh1 = 1;
					gItemManager.InventoryDelItem(lpObj->Index, x);
					gItemManager.GCItemDeleteSend(lpObj->Index, x, 1);
					lpObj->SACHTHUOCTINH.SACHTHUOCTINH_05 += 1; // Thay Đổi
					this->GDSaveUserInfo(lpObj->Index);
					gObjectManager.CharacterCalcAttribute(lpObj->Index);
					break;
				}
			}
		}
		if (SachThuocTinh1 == 0)
		{
			char text[100];
			wsprintf(text, this->MSG_02, gItemManager.GetItemName(GET_ITEM(14, 454)));
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, text);
		}
		GetInfoThuocTinh(lpObj);
		GetInfoThuocTinhAtive(lpObj);
		//Set Delay
		//lpObj->ClickClientSend = GetTickCount();

	}
	//-------------------------------------------------------------------------------------------------------------
	else if (aRecv->Number == 6)
	{
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		if (lpObj->SACHTHUOCTINH.SACHTHUOCTINH_06 >  this->MAX_THUOC_TINH_06) // < 45
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->MSG_01);
			return;
		}

		int SachThuocTinh1 = 0;
		for (int x = 12; x < INVENTORY_MAIN_SIZE; x++)
		{
			if (lpObj->Inventory[x].IsItem() == TRUE)
			{
				if (lpObj->Inventory[x].m_Index == GET_ITEM(14, 455))
				{
					SachThuocTinh1 = 1;
					gItemManager.InventoryDelItem(lpObj->Index, x);
					gItemManager.GCItemDeleteSend(lpObj->Index, x, 1);
					lpObj->SACHTHUOCTINH.SACHTHUOCTINH_06 += 1; // Thay Đổi
					this->GDSaveUserInfo(lpObj->Index);
					gObjectManager.CharacterCalcAttribute(lpObj->Index);
					break;
				}
			}
		}
		if (SachThuocTinh1 == 0)
		{
			char text[100];
			wsprintf(text, this->MSG_02, gItemManager.GetItemName(GET_ITEM(14, 455)));
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, text);
		}
		GetInfoThuocTinh(lpObj);
		GetInfoThuocTinhAtive(lpObj);
		//Set Delay
		//lpObj->ClickClientSend = GetTickCount();

	}
	//-------------------------------------------------------------------------------------------------------------
	else if (aRecv->Number == 7)
	{
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
#endif
		if (lpObj->SACHTHUOCTINH.SACHTHUOCTINH_07 >  this->MAX_THUOC_TINH_07) // < 45
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->MSG_01);
			return;
		}

		int SachThuocTinh1 = 0;
		for (int x = 12; x < INVENTORY_MAIN_SIZE; x++)
		{
			if (lpObj->Inventory[x].IsItem() == TRUE)
			{
				if (lpObj->Inventory[x].m_Index == GET_ITEM(14, 456))
				{
					SachThuocTinh1 = 1;
					gItemManager.InventoryDelItem(lpObj->Index, x);
					gItemManager.GCItemDeleteSend(lpObj->Index, x, 1);
					lpObj->SACHTHUOCTINH.SACHTHUOCTINH_07 += 1; // Thay Đổi
					this->GDSaveUserInfo(lpObj->Index);
					gObjectManager.CharacterCalcAttribute(lpObj->Index);
					break;
				}
			}
		}
		if (SachThuocTinh1 == 0)
		{
			char text[100];
			wsprintf(text, this->MSG_02, gItemManager.GetItemName(GET_ITEM(14, 456)));
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, text);
		}
		GetInfoThuocTinh(lpObj);
		GetInfoThuocTinhAtive(lpObj);
		//Set Delay
		//lpObj->ClickClientSend = GetTickCount();

	}
	//-------------------------------------------------------------------------------------------------------------
	else if (aRecv->Number == 8)
	{
		GetInfoThuocTinh(lpObj);
		GetInfoThuocTinhAtive(lpObj);
	}
	//-------------------------------------------------------------------------------------------------------------
}

// -------------------------------------------------------------------------------
void SachThuocTinh::Option(LPOBJ lpObj, bool flag)
{
	if (flag != 0)
	{
		return;
	}
	if (lpObj->CB_Status1 != 0)
	{
		return; //
	}

	//--------------------------------------------------------------------------------
	if (lpObj->SACHTHUOCTINH.SACHTHUOCTINH_02 == this->OPTION_LEVEL_01)
	{
		lpObj->TripleDamageRate += this->OPTION_ACTIVE_01; // sát thương x3
	}
	//--------------------------------------------------------------------------------
	if (lpObj->SACHTHUOCTINH.SACHTHUOCTINH_02 == this->OPTION_LEVEL_02)
	{
		lpObj->CriticalDamageRate += this->OPTION_ACTIVE_02; // bạo kích x3
	}
	//--------------------------------------------------------------------------------
	if (lpObj->SACHTHUOCTINH.SACHTHUOCTINH_03 >= this->OPTION_LEVEL_03)
	{
		lpObj->DamageReflect += this->OPTION_ACTIVE_03; // Phản hồi sát thương
	}
	//--------------------------------------------------------------------------------
	if (lpObj->SACHTHUOCTINH.SACHTHUOCTINH_03 >= this->OPTION_LEVEL_04)
	{
		lpObj->ResistStunRate += this->OPTION_ACTIVE_04; // Chống choáng %
	}
	//--------------------------------------------------------------------------------
	if (lpObj->SACHTHUOCTINH.SACHTHUOCTINH_04 >= this->OPTION_LEVEL_05)
	{
		lpObj->MagicDamageMin += this->OPTION_ACTIVE_04;
		lpObj->MagicDamageMax += this->OPTION_ACTIVE_04;
		lpObj->PhysiDamageMinLeft += this->OPTION_ACTIVE_04;
		lpObj->PhysiDamageMinRight += this->OPTION_ACTIVE_04;
		lpObj->PhysiDamageMaxLeft += this->OPTION_ACTIVE_04;
		lpObj->PhysiDamageMaxRight += this->OPTION_ACTIVE_04;
	}
	//--------------------------------------------------------------------------------
	if (lpObj->SACHTHUOCTINH.SACHTHUOCTINH_04 >= this->OPTION_LEVEL_06)
	{
		lpObj->IgnoreDefenseRate += this->OPTION_ACTIVE_06; // Loại bỏ phòng ngự %
	}
	//--------------------------------------------------------------------------------
	if (lpObj->SACHTHUOCTINH.SACHTHUOCTINH_05 >= this->OPTION_LEVEL_07)
	{
		lpObj->DefenseSuccessRate += this->OPTION_ACTIVE_07; // Phòng thủ thành công
	}
	//--------------------------------------------------------------------------------
	if (lpObj->SACHTHUOCTINH.SACHTHUOCTINH_05 >= this->OPTION_LEVEL_08)
	{
		lpObj->FullDamageReflectRate += this->OPTION_ACTIVE_08; // Phòng thủ toàn phần
	}
	//--------------------------------------------------------------------------------
	if (lpObj->SACHTHUOCTINH.SACHTHUOCTINH_06 >= this->OPTION_LEVEL_09)
	{
		lpObj->AddStrength += this->OPTION_ACTIVE_09; // Sức Mạnh
	}
	//--------------------------------------------------------------------------------
	if (lpObj->SACHTHUOCTINH.SACHTHUOCTINH_06 >= this->OPTION_LEVEL_10)
	{
		lpObj->AddDexterity += this->OPTION_ACTIVE_10; // Nhanh Nhẹn
	}
	//--------------------------------------------------------------------------------
	if (lpObj->SACHTHUOCTINH.SACHTHUOCTINH_07 >= this->OPTION_LEVEL_11)
	{
		lpObj->AddVitality += this->OPTION_ACTIVE_11; // Thể Lực
	}
	//--------------------------------------------------------------------------------
	if (lpObj->SACHTHUOCTINH.SACHTHUOCTINH_07 >= this->OPTION_LEVEL_12)
	{
		lpObj->AddEnergy += this->OPTION_ACTIVE_12; // Năng lượng
	}
	//--------------------------------------------------------------------------------
}

//===============================================================================================================================
#endif


