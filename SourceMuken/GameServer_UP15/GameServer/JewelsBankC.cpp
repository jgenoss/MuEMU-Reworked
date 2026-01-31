#include "stdafx.h"
#include "JewelsBankC.h"
#include "GameMain.h"
#include "ItemManager.h"
#include "ServerInfo.h"
#include "Notice.h"
#include "Util.h"

CBankEx gBankEx;

CBankEx::CBankEx()
{
	
}

CBankEx::~CBankEx()
{
	
}

void CBankEx::InitUser(LPOBJ lpObj)
{
	lpObj->BankEx.Money			= 0;
	lpObj->BankEx.JBless		= 0;
	lpObj->BankEx.JSoul			= 0;
	lpObj->BankEx.JChaos		= 0;
	lpObj->BankEx.JCreation		= 0;
	lpObj->BankEx.JLife			= 0;
	lpObj->BankEx.JHarmony		= 0;
}

void CBankEx::GDSavePoint(int aIndex)
{
	if( !gObjIsConnected(aIndex) )
	{
		return;
	}
	// ----
	LPOBJ lpUser = &gObj[aIndex];
	// ----
	BANKEX_GD_SAVE_POINT pRequest;
	pRequest.h.set(0xFB, 0x06, sizeof(pRequest));
	memcpy(pRequest.AccountID, lpUser->Account, sizeof(lpUser->Account));
	pRequest.UserIndex	= aIndex;
	pRequest.Money		= lpUser->BankEx.Money;
	pRequest.Bless		= lpUser->BankEx.JBless;
	pRequest.Soul		= lpUser->BankEx.JSoul;
	pRequest.Chaos		= lpUser->BankEx.JChaos;
	pRequest.Creation	= lpUser->BankEx.JCreation;
	pRequest.Life		= lpUser->BankEx.JLife;
	pRequest.Harmony	= lpUser->BankEx.JHarmony;
	gDataServerConnection.DataSend((BYTE*)&pRequest,pRequest.h.size);
}
// -------------------------------------------------------------------------------

void CBankEx::GDReqPoint(int aIndex)
{
	// ----
	LPOBJ lpUser = &gObj[aIndex];
	// ----
	BANKEX_GD_REQ_POINT pRequest;
	pRequest.h.set(0xFB, 0x05, sizeof(pRequest));
	memcpy(pRequest.AccountID, lpUser->Account, sizeof(lpUser->Account));
	pRequest.UserIndex = aIndex;
	gDataServerConnection.DataSend((BYTE*)&pRequest,pRequest.h.size);
}
// -------------------------------------------------------------------------------

void CBankEx::DGGetPoint(BANKEX_DG_GET_POINT * aRecv)
{
	// ----
	LPOBJ lpUser = &gObj[aRecv->UserIndex];
	// ----

	if( aRecv->Bless < 0 )
	{
		aRecv->Bless = 0;
	}
	if( aRecv->Soul < 0 )
	{
		aRecv->Soul = 0;
	}
	if (aRecv->Chaos < 0)
	{
		aRecv->Chaos = 0;
	}
	if (aRecv->Creation < 0)
	{
		aRecv->Creation = 0;
	}
	if( aRecv->Life < 0 )
	{
		aRecv->Life = 0;
	}
	if( aRecv->Harmony < 0 )
	{
		aRecv->Harmony = 0;
	}
	// ----
	lpUser->BankEx.Money		= aRecv->Money;
	lpUser->BankEx.JBless		= aRecv->Bless;
	lpUser->BankEx.JSoul		= aRecv->Soul;
	lpUser->BankEx.JChaos		= aRecv->Chaos;
	lpUser->BankEx.JCreation	= aRecv->Creation;
	lpUser->BankEx.JLife		= aRecv->Life;
	lpUser->BankEx.JHarmony		= aRecv->Harmony;

	gBankEx.GCUpdateBankEx(lpUser->Index);
}
// -------------------------------------------------------------------------------

void CBankEx::GCUpdateBankEx(int aIndex)
{
	if (!gObjIsConnectedGP(aIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	PMSG_BANKEX_UPDATE_SEND pMsg;
	pMsg.header.set(0xFB, 0x06, sizeof(pMsg));
	// ----
	pMsg.Money = lpObj->BankEx.Money;
	pMsg.Bless = lpObj->BankEx.JBless;
	pMsg.Soul = lpObj->BankEx.JSoul;
	pMsg.Chaos = lpObj->BankEx.JChaos;
	pMsg.Creation = lpObj->BankEx.JCreation;
	pMsg.Life = lpObj->BankEx.JLife;
	pMsg.Harmony = lpObj->BankEx.JHarmony;
	pMsg.MaxWarehouse = gServerInfo.m_CustomWarehouseMaxNumber[lpObj->AccountLevel];
	// ----
	DataSend(aIndex, (LPBYTE)&pMsg, sizeof(pMsg));
}

void CBankEx::Make(int aIndex, int Count, int Type)
{
	LPOBJ lpObj = &gObj[aIndex];
	int Item = 0;
	char Name[25];

	if (Type == BANKEX_BLESS)
	{
		if((lpObj->BankEx.JBless - Count) < 0 )
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "You dont have enough Bless");
			return;
		}
		else
		{
			sprintf(Name, "Bless");
			Item = GET_ITEM(14, 13);
		}
	}
	else if (Type == BANKEX_SOUL)
	{
		if((gObj[aIndex].BankEx.JSoul - Count) < 0 )
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "You dont have enough Soul");
			return;
		}
		else
		{
			sprintf(Name, "Soul");
			Item = GET_ITEM(14, 14);
		}
	}
	else if (Type == BANKEX_CHAOS)
	{
		if((gObj[aIndex].BankEx.JChaos - Count) < 0 )
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "You dont have enough Chaos");
			return;
		}
		else
		{
			sprintf(Name, "Chaos");
			Item = GET_ITEM(12, 15);
		}
	}
	else if (Type == BANKEX_CREATION)
	{
		if((gObj[aIndex].BankEx.JCreation - Count) < 0 )
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "You dont have enough Creation");
			return;
		}
		else
		{
			sprintf(Name, "Creation");
			Item = GET_ITEM(14, 22);
		}
	}
	else if (Type == BANKEX_LIFE)
	{
		if((gObj[aIndex].BankEx.JLife - Count) < 0 )
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "You dont have enough Life");
			return;
		}
		else
		{
			sprintf(Name, "Life");
			Item = GET_ITEM(14, 16);
		}
	}
	else if (Type == BANKEX_HARMONY)
	{
		if((gObj[aIndex].BankEx.JHarmony - Count) < 0 )
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "You dont have enough Harmony");
			return;
		}
		else
		{
			sprintf(Name, "Harmony");
			Item = GET_ITEM(14, 42);
		}
	}

	lpObj->ChaosLock = 1;

	int iEmptyCount = gItemManager.GetInventoryEmptySlotCount(lpObj);

	if( iEmptyCount < Count )
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "You dont have empty space!");
		gObj[aIndex].ChaosLock = 0;
		return;
	}


}

void CBankEx::Change(int aIndex, int Count, int Type)
{
	
}