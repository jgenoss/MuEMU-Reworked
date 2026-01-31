#include "stdafx.h"
#include "Util.h"
#include "User.h"
#include "MocNap.h"
#include "CashShop.h"
#include "MemScript.h"
#include "Notice.h"
#include "DSProtocol.h"
#include "ItemManager.h"
#include "ServerInfo.h"
#include "SocketItemType.h"
#include "Path.h"
#include "GameMain.h"

#if(MOCNAP == 1)

CMocNap gMocNap;

CMocNap::CMocNap() // OK
{
	this->Init();
}

CMocNap::~CMocNap() // OK
{

}

void CMocNap::Init() // OK
{
	for (int n = 0; n < MAX_CLASS; n++)
	{
		this->m_MocNapInfo[n].Class1 = -1;
		this->m_MocNapInfo[n].Class2 = -1;
		this->m_MocNapInfo[n].Class3 = -1;
		this->m_MocNapInfo[n].Class4 = -1;
		this->m_MocNapInfo[n].Class5 = -1;
		this->m_MocNapInfo[n].Class6 = -1;
		this->m_MocNapInfo[n].Class7 = -1;
		this->m_MocNapInfo[n].Class8 = -1;
		this->m_MocNapInfo[n].Class9 = -1;
		this->m_MocNapInfo[n].Class10 = -1;
		this->m_MocNapInfo[n].Class11 = -1;
		this->m_MocNapInfo[n].Class12 = -1;
		this->m_MocNapInfo[n].Class13 = -1;

		this->m_MocNapInfo[n].MOCNAP1.clear(); // ok
		this->m_MocNapInfo[n].MOCNAP2.clear(); // ok
		this->m_MocNapInfo[n].MOCNAP3.clear(); // ok
		this->m_MocNapInfo[n].MOCNAP4.clear();
		this->m_MocNapInfo[n].MOCNAP5.clear();
		this->m_MocNapInfo[n].MOCNAP6.clear();
		this->m_MocNapInfo[n].MOCNAP7.clear();
		this->m_MocNapInfo[n].MOCNAP8.clear();
		this->m_MocNapInfo[n].MOCNAP9.clear();
		this->m_MocNapInfo[n].MOCNAP10.clear();
		this->m_MocNapInfo[n].MOCNAP11.clear();
		this->m_MocNapInfo[n].MOCNAP12.clear();
		this->m_MocNapInfo[n].MOCNAP13.clear();

	}
}

void CMocNap::Load(char* path) // OK
{
	CMemScript* lpMemScript = new CMemScript;

	if (lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR, path);
		return;
	}

	if (lpMemScript->SetBuffer(path) == 0)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	this->Init();

	try
	{
		while (true)
		{
			if (lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			int section = lpMemScript->GetNumber();

			while (true)
			{
				if (section == 0)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
					CUSTOM_MOC_NAP_INFO Items;

					int Class1 = lpMemScript->GetNumber();

					Items.ItemIndex = lpMemScript->GetAsNumber();

					Items.ItemLevel = lpMemScript->GetAsNumber();

					Items.ItemLuck = lpMemScript->GetAsNumber();

					Items.ItemDurability = lpMemScript->GetAsNumber();

					Items.ItemSkill = lpMemScript->GetAsNumber();

					Items.ItemOption = lpMemScript->GetAsNumber();

					Items.ItemExcellent = lpMemScript->GetAsNumber();

					Items.ItemAncient = lpMemScript->GetAsNumber();

					Items.ItemJOH = lpMemScript->GetAsNumber();

					Items.ItemOpEx = lpMemScript->GetAsNumber();

					Items.ItemSocket1 = lpMemScript->GetAsNumber();

					Items.ItemSocket2 = lpMemScript->GetAsNumber();

					Items.ItemSocket3 = lpMemScript->GetAsNumber();

					Items.ItemSocket4 = lpMemScript->GetAsNumber();

					Items.ItemSocket5 = lpMemScript->GetAsNumber();

					this->m_MocNapInfo[Class1].MOCNAP1.push_back(Items);
				}

				else if (section == 1)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
					CUSTOM_MOC_NAP_INFO Items;

					int Class2 = lpMemScript->GetNumber();

					Items.ItemIndex = lpMemScript->GetAsNumber();

					Items.ItemLevel = lpMemScript->GetAsNumber();

					Items.ItemLuck = lpMemScript->GetAsNumber();

					Items.ItemDurability = lpMemScript->GetAsNumber();

					Items.ItemSkill = lpMemScript->GetAsNumber();

					Items.ItemOption = lpMemScript->GetAsNumber();

					Items.ItemExcellent = lpMemScript->GetAsNumber();

					Items.ItemAncient = lpMemScript->GetAsNumber();

					Items.ItemJOH = lpMemScript->GetAsNumber();

					Items.ItemOpEx = lpMemScript->GetAsNumber();

					Items.ItemSocket1 = lpMemScript->GetAsNumber();

					Items.ItemSocket2 = lpMemScript->GetAsNumber();

					Items.ItemSocket3 = lpMemScript->GetAsNumber();

					Items.ItemSocket4 = lpMemScript->GetAsNumber();

					Items.ItemSocket5 = lpMemScript->GetAsNumber();

					this->m_MocNapInfo[Class2].MOCNAP2.push_back(Items);
				}

				else if (section == 2)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
					CUSTOM_MOC_NAP_INFO Items;

					int Class3 = lpMemScript->GetNumber();

					Items.ItemIndex = lpMemScript->GetAsNumber();

					Items.ItemLevel = lpMemScript->GetAsNumber();

					Items.ItemLuck = lpMemScript->GetAsNumber();

					Items.ItemDurability = lpMemScript->GetAsNumber();

					Items.ItemSkill = lpMemScript->GetAsNumber();

					Items.ItemOption = lpMemScript->GetAsNumber();

					Items.ItemExcellent = lpMemScript->GetAsNumber();

					Items.ItemAncient = lpMemScript->GetAsNumber();

					Items.ItemJOH = lpMemScript->GetAsNumber();

					Items.ItemOpEx = lpMemScript->GetAsNumber();

					Items.ItemSocket1 = lpMemScript->GetAsNumber();

					Items.ItemSocket2 = lpMemScript->GetAsNumber();

					Items.ItemSocket3 = lpMemScript->GetAsNumber();

					Items.ItemSocket4 = lpMemScript->GetAsNumber();

					Items.ItemSocket5 = lpMemScript->GetAsNumber();

					this->m_MocNapInfo[Class3].MOCNAP3.push_back(Items);
				}

				else if (section == 3)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
					CUSTOM_MOC_NAP_INFO Items;

					int Class4 = lpMemScript->GetNumber();

					Items.ItemIndex = lpMemScript->GetAsNumber();

					Items.ItemLevel = lpMemScript->GetAsNumber();

					Items.ItemLuck = lpMemScript->GetAsNumber();

					Items.ItemDurability = lpMemScript->GetAsNumber();

					Items.ItemSkill = lpMemScript->GetAsNumber();

					Items.ItemOption = lpMemScript->GetAsNumber();

					Items.ItemExcellent = lpMemScript->GetAsNumber();

					Items.ItemAncient = lpMemScript->GetAsNumber();

					Items.ItemJOH = lpMemScript->GetAsNumber();

					Items.ItemOpEx = lpMemScript->GetAsNumber();

					Items.ItemSocket1 = lpMemScript->GetAsNumber();

					Items.ItemSocket2 = lpMemScript->GetAsNumber();

					Items.ItemSocket3 = lpMemScript->GetAsNumber();

					Items.ItemSocket4 = lpMemScript->GetAsNumber();

					Items.ItemSocket5 = lpMemScript->GetAsNumber();

					this->m_MocNapInfo[Class4].MOCNAP4.push_back(Items);
				}

				else if (section == 4)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
					CUSTOM_MOC_NAP_INFO Items;

					int Class5 = lpMemScript->GetNumber();

					Items.ItemIndex = lpMemScript->GetAsNumber();

					Items.ItemLevel = lpMemScript->GetAsNumber();

					Items.ItemLuck = lpMemScript->GetAsNumber();

					Items.ItemDurability = lpMemScript->GetAsNumber();

					Items.ItemSkill = lpMemScript->GetAsNumber();

					Items.ItemOption = lpMemScript->GetAsNumber();

					Items.ItemExcellent = lpMemScript->GetAsNumber();

					Items.ItemAncient = lpMemScript->GetAsNumber();

					Items.ItemJOH = lpMemScript->GetAsNumber();

					Items.ItemOpEx = lpMemScript->GetAsNumber();

					Items.ItemSocket1 = lpMemScript->GetAsNumber();

					Items.ItemSocket2 = lpMemScript->GetAsNumber();

					Items.ItemSocket3 = lpMemScript->GetAsNumber();

					Items.ItemSocket4 = lpMemScript->GetAsNumber();

					Items.ItemSocket5 = lpMemScript->GetAsNumber();

					this->m_MocNapInfo[Class5].MOCNAP5.push_back(Items);
				}

				else if (section == 5)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
					CUSTOM_MOC_NAP_INFO Items;

					int Class6 = lpMemScript->GetNumber();

					Items.ItemIndex = lpMemScript->GetAsNumber();

					Items.ItemLevel = lpMemScript->GetAsNumber();

					Items.ItemLuck = lpMemScript->GetAsNumber();

					Items.ItemDurability = lpMemScript->GetAsNumber();

					Items.ItemSkill = lpMemScript->GetAsNumber();

					Items.ItemOption = lpMemScript->GetAsNumber();

					Items.ItemExcellent = lpMemScript->GetAsNumber();

					Items.ItemAncient = lpMemScript->GetAsNumber();

					Items.ItemJOH = lpMemScript->GetAsNumber();

					Items.ItemOpEx = lpMemScript->GetAsNumber();

					Items.ItemSocket1 = lpMemScript->GetAsNumber();

					Items.ItemSocket2 = lpMemScript->GetAsNumber();

					Items.ItemSocket3 = lpMemScript->GetAsNumber();

					Items.ItemSocket4 = lpMemScript->GetAsNumber();

					Items.ItemSocket5 = lpMemScript->GetAsNumber();

					this->m_MocNapInfo[Class6].MOCNAP6.push_back(Items);
				}

				else if (section == 6)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
					CUSTOM_MOC_NAP_INFO Items;

					int Class7 = lpMemScript->GetNumber();

					Items.ItemIndex = lpMemScript->GetAsNumber();

					Items.ItemLevel = lpMemScript->GetAsNumber();

					Items.ItemLuck = lpMemScript->GetAsNumber();

					Items.ItemDurability = lpMemScript->GetAsNumber();

					Items.ItemSkill = lpMemScript->GetAsNumber();

					Items.ItemOption = lpMemScript->GetAsNumber();

					Items.ItemExcellent = lpMemScript->GetAsNumber();

					Items.ItemAncient = lpMemScript->GetAsNumber();

					Items.ItemJOH = lpMemScript->GetAsNumber();

					Items.ItemOpEx = lpMemScript->GetAsNumber();

					Items.ItemSocket1 = lpMemScript->GetAsNumber();

					Items.ItemSocket2 = lpMemScript->GetAsNumber();

					Items.ItemSocket3 = lpMemScript->GetAsNumber();

					Items.ItemSocket4 = lpMemScript->GetAsNumber();

					Items.ItemSocket5 = lpMemScript->GetAsNumber();

					this->m_MocNapInfo[Class7].MOCNAP7.push_back(Items);
				}

				else if (section == 7)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
					CUSTOM_MOC_NAP_INFO Items;

					int Class8 = lpMemScript->GetNumber();

					Items.ItemIndex = lpMemScript->GetAsNumber();

					Items.ItemLevel = lpMemScript->GetAsNumber();

					Items.ItemLuck = lpMemScript->GetAsNumber();

					Items.ItemDurability = lpMemScript->GetAsNumber();

					Items.ItemSkill = lpMemScript->GetAsNumber();

					Items.ItemOption = lpMemScript->GetAsNumber();

					Items.ItemExcellent = lpMemScript->GetAsNumber();

					Items.ItemAncient = lpMemScript->GetAsNumber();

					Items.ItemJOH = lpMemScript->GetAsNumber();

					Items.ItemOpEx = lpMemScript->GetAsNumber();

					Items.ItemSocket1 = lpMemScript->GetAsNumber();

					Items.ItemSocket2 = lpMemScript->GetAsNumber();

					Items.ItemSocket3 = lpMemScript->GetAsNumber();

					Items.ItemSocket4 = lpMemScript->GetAsNumber();

					Items.ItemSocket5 = lpMemScript->GetAsNumber();

					this->m_MocNapInfo[Class8].MOCNAP8.push_back(Items);
				}

				else if (section == 8)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
					CUSTOM_MOC_NAP_INFO Items;

					int Class9 = lpMemScript->GetNumber();

					Items.ItemIndex = lpMemScript->GetAsNumber();

					Items.ItemLevel = lpMemScript->GetAsNumber();

					Items.ItemLuck = lpMemScript->GetAsNumber();

					Items.ItemDurability = lpMemScript->GetAsNumber();

					Items.ItemSkill = lpMemScript->GetAsNumber();

					Items.ItemOption = lpMemScript->GetAsNumber();

					Items.ItemExcellent = lpMemScript->GetAsNumber();

					Items.ItemAncient = lpMemScript->GetAsNumber();

					Items.ItemJOH = lpMemScript->GetAsNumber();

					Items.ItemOpEx = lpMemScript->GetAsNumber();

					Items.ItemSocket1 = lpMemScript->GetAsNumber();

					Items.ItemSocket2 = lpMemScript->GetAsNumber();

					Items.ItemSocket3 = lpMemScript->GetAsNumber();

					Items.ItemSocket4 = lpMemScript->GetAsNumber();

					Items.ItemSocket5 = lpMemScript->GetAsNumber();

					this->m_MocNapInfo[Class9].MOCNAP9.push_back(Items);
				}

				else if (section == 9)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
					CUSTOM_MOC_NAP_INFO Items;

					int Class10 = lpMemScript->GetNumber();

					Items.ItemIndex = lpMemScript->GetAsNumber();

					Items.ItemLevel = lpMemScript->GetAsNumber();

					Items.ItemLuck = lpMemScript->GetAsNumber();

					Items.ItemDurability = lpMemScript->GetAsNumber();

					Items.ItemSkill = lpMemScript->GetAsNumber();

					Items.ItemOption = lpMemScript->GetAsNumber();

					Items.ItemExcellent = lpMemScript->GetAsNumber();

					Items.ItemAncient = lpMemScript->GetAsNumber();

					Items.ItemJOH = lpMemScript->GetAsNumber();

					Items.ItemOpEx = lpMemScript->GetAsNumber();

					Items.ItemSocket1 = lpMemScript->GetAsNumber();

					Items.ItemSocket2 = lpMemScript->GetAsNumber();

					Items.ItemSocket3 = lpMemScript->GetAsNumber();

					Items.ItemSocket4 = lpMemScript->GetAsNumber();

					Items.ItemSocket5 = lpMemScript->GetAsNumber();

					this->m_MocNapInfo[Class10].MOCNAP10.push_back(Items);
				}

				else if (section == 10)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
					CUSTOM_MOC_NAP_INFO Items;

					int Class11 = lpMemScript->GetNumber();

					Items.ItemIndex = lpMemScript->GetAsNumber();

					Items.ItemLevel = lpMemScript->GetAsNumber();

					Items.ItemLuck = lpMemScript->GetAsNumber();

					Items.ItemDurability = lpMemScript->GetAsNumber();

					Items.ItemSkill = lpMemScript->GetAsNumber();

					Items.ItemOption = lpMemScript->GetAsNumber();

					Items.ItemExcellent = lpMemScript->GetAsNumber();

					Items.ItemAncient = lpMemScript->GetAsNumber();

					Items.ItemJOH = lpMemScript->GetAsNumber();

					Items.ItemOpEx = lpMemScript->GetAsNumber();

					Items.ItemSocket1 = lpMemScript->GetAsNumber();

					Items.ItemSocket2 = lpMemScript->GetAsNumber();

					Items.ItemSocket3 = lpMemScript->GetAsNumber();

					Items.ItemSocket4 = lpMemScript->GetAsNumber();

					Items.ItemSocket5 = lpMemScript->GetAsNumber();

					this->m_MocNapInfo[Class11].MOCNAP11.push_back(Items);
				}

				else if (section == 11)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
					CUSTOM_MOC_NAP_INFO Items;

					int Class12 = lpMemScript->GetNumber();

					Items.ItemIndex = lpMemScript->GetAsNumber();

					Items.ItemLevel = lpMemScript->GetAsNumber();

					Items.ItemLuck = lpMemScript->GetAsNumber();

					Items.ItemDurability = lpMemScript->GetAsNumber();

					Items.ItemSkill = lpMemScript->GetAsNumber();

					Items.ItemOption = lpMemScript->GetAsNumber();

					Items.ItemExcellent = lpMemScript->GetAsNumber();

					Items.ItemAncient = lpMemScript->GetAsNumber();

					Items.ItemJOH = lpMemScript->GetAsNumber();

					Items.ItemOpEx = lpMemScript->GetAsNumber();

					Items.ItemSocket1 = lpMemScript->GetAsNumber();

					Items.ItemSocket2 = lpMemScript->GetAsNumber();

					Items.ItemSocket3 = lpMemScript->GetAsNumber();

					Items.ItemSocket4 = lpMemScript->GetAsNumber();

					Items.ItemSocket5 = lpMemScript->GetAsNumber();

					this->m_MocNapInfo[Class12].MOCNAP12.push_back(Items);
				}

				else if (section == 12)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
					CUSTOM_MOC_NAP_INFO Items;

					int Class13 = lpMemScript->GetNumber();

					Items.ItemIndex = lpMemScript->GetAsNumber();

					Items.ItemLevel = lpMemScript->GetAsNumber();

					Items.ItemLuck = lpMemScript->GetAsNumber();

					Items.ItemDurability = lpMemScript->GetAsNumber();

					Items.ItemSkill = lpMemScript->GetAsNumber();

					Items.ItemOption = lpMemScript->GetAsNumber();

					Items.ItemExcellent = lpMemScript->GetAsNumber();

					Items.ItemAncient = lpMemScript->GetAsNumber();

					Items.ItemJOH = lpMemScript->GetAsNumber();

					Items.ItemOpEx = lpMemScript->GetAsNumber();

					Items.ItemSocket1 = lpMemScript->GetAsNumber();

					Items.ItemSocket2 = lpMemScript->GetAsNumber();

					Items.ItemSocket3 = lpMemScript->GetAsNumber();

					Items.ItemSocket4 = lpMemScript->GetAsNumber();

					Items.ItemSocket5 = lpMemScript->GetAsNumber();

					this->m_MocNapInfo[Class13].MOCNAP13.push_back(Items);
				}

				else
				{
					break;
				}
			}
		}
	}
	catch (...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}


///===============================================================
void CMocNap::GDSaveData(int aIndex)
{
	// ----
	LPOBJ lpUser = &gObj[aIndex];
	// ----
	MOCNAP_GD_SAVE_DATA pRequest;
	pRequest.header.set(0xB0, 0x14, sizeof(pRequest));
	memcpy(pRequest.Name, lpUser->Name, 11);
	pRequest.index = aIndex;
	//--
	pRequest.MOCNAP1 = lpUser->QUANAP.MOCNAP1;
	pRequest.MOCNAP2 = lpUser->QUANAP.MOCNAP2;
	pRequest.MOCNAP3 = lpUser->QUANAP.MOCNAP3;
	pRequest.MOCNAP4 = lpUser->QUANAP.MOCNAP4;
	pRequest.MOCNAP5 = lpUser->QUANAP.MOCNAP5;
	pRequest.MOCNAP6 = lpUser->QUANAP.MOCNAP6;
	pRequest.MOCNAP7 = lpUser->QUANAP.MOCNAP7;
	pRequest.MOCNAP8 = lpUser->QUANAP.MOCNAP8;
	pRequest.MOCNAP9 = lpUser->QUANAP.MOCNAP9;
	pRequest.MOCNAP10 = lpUser->QUANAP.MOCNAP10;
	pRequest.MOCNAP11 = lpUser->QUANAP.MOCNAP11;
	pRequest.MOCNAP12 = lpUser->QUANAP.MOCNAP12;
	pRequest.MOCNAP13 = lpUser->QUANAP.MOCNAP13;
	//--
	gDataServerConnection.DataSend((BYTE*)&pRequest, pRequest.header.size);
}
// -------------------------------------------------------------------------------
void CMocNap::GDReqData(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];
	MOCNAP_GD_REQ_DATA pMsg;
	pMsg.header.set(0xB0, 0x13, sizeof(pMsg));
	pMsg.index = aIndex;
	memcpy(pMsg.name, lpObj->Name, sizeof(pMsg.name));
	gDataServerConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}
// -------------------------------------------------------------------------------
void CMocNap::GDSaveUserInfo(int aIndex)	//-> Complete
{
	this->GDSaveData(aIndex);
}
// -------------------------------------------------------------------------------
void CMocNap::GDReqUserInfo(int aIndex)	//-> Complete
{
	// ----
	this->GDReqData(aIndex);
}
// -------------------------------------------------------------------------------
void CMocNap::DGGetData(MOCNAP_DG_GET_DATA * aRecv)
{
	// ----
	LPOBJ lpUser = &gObj[aRecv->index];
	// ----
	if (aRecv->MOCNAP1 < 0)
	{
		aRecv->MOCNAP1 = 0;
	}
	else if (aRecv->MOCNAP2 < 0)
	{
		aRecv->MOCNAP2 = 0;
	}
	else if (aRecv->MOCNAP3 < 0)
	{
		aRecv->MOCNAP3 = 0;
	}
	else if (aRecv->MOCNAP4 < 0)
	{
		aRecv->MOCNAP4 = 0;
	}
	else if (aRecv->MOCNAP5 < 0)
	{
		aRecv->MOCNAP5 = 0;
	}
	else if (aRecv->MOCNAP6 < 0)
	{
		aRecv->MOCNAP6 = 0;
	}
	else if (aRecv->MOCNAP7 < 0)
	{
		aRecv->MOCNAP7 = 0;
	}
	else if (aRecv->MOCNAP8 < 0)
	{
		aRecv->MOCNAP8 = 0;
	}
	else if (aRecv->MOCNAP9 < 0)
	{
		aRecv->MOCNAP9 = 0;
	}
	else if (aRecv->MOCNAP10 < 0)
	{
		aRecv->MOCNAP10 = 0;
	}
	else if (aRecv->MOCNAP11 < 0)
	{
		aRecv->MOCNAP11 = 0;
	}
	else if (aRecv->MOCNAP12 < 0)
	{
		aRecv->MOCNAP12 = 0;
	}
	else if (aRecv->MOCNAP13 < 0)
	{
		aRecv->MOCNAP13 = 0;
	}
	// ----
	lpUser->QUANAP.MOCNAP1 = aRecv->MOCNAP1;
	lpUser->QUANAP.MOCNAP2 = aRecv->MOCNAP2;
	lpUser->QUANAP.MOCNAP3 = aRecv->MOCNAP3;
	lpUser->QUANAP.MOCNAP4 = aRecv->MOCNAP4;
	lpUser->QUANAP.MOCNAP5 = aRecv->MOCNAP5;
	lpUser->QUANAP.MOCNAP6 = aRecv->MOCNAP6;
	lpUser->QUANAP.MOCNAP7 = aRecv->MOCNAP7;
	lpUser->QUANAP.MOCNAP8 = aRecv->MOCNAP8;
	lpUser->QUANAP.MOCNAP9 = aRecv->MOCNAP9;
	lpUser->QUANAP.MOCNAP10 = aRecv->MOCNAP10;
	lpUser->QUANAP.MOCNAP11 = aRecv->MOCNAP11;
	lpUser->QUANAP.MOCNAP12 = aRecv->MOCNAP12;
	lpUser->QUANAP.MOCNAP13 = aRecv->MOCNAP13;
}
// -------------------------------------------------------------------------------
//===============================================================================================================================

struct MOCNAP_UPDATE  // ok
{
	PBMSG_HEAD3 h;
	int MocNapCheck1;
	int MocNapCheck2;
	int MocNapCheck3;
	int MocNapCheck4;
	int MocNapCheck5;
	int MocNapCheck6;
	int MocNapCheck7;
	int MocNapCheck8;
	int MocNapCheck9;
	int MocNapCheck10;
	int MocNapCheck11;
	int MocNapCheck12;
	int MocNapCheck13;
	//---
	int	MOCNAPCOIN;
	int	MOCNAP1;
	int	MOCNAP2;
	int	MOCNAP3;
	int	MOCNAP4;
	int	MOCNAP5;
	int	MOCNAP6;
	int	MOCNAP7;
	int	MOCNAP8;
	int	MOCNAP9;
	int	MOCNAP10;
	int	MOCNAP11;
	int	MOCNAP12;
	int	MOCNAP13;
};
void MocNapDataSend(int aIndex) // ok
{
	MOCNAP_UPDATE rSend;
	LPOBJ lpObj = &gObj[aIndex];
	rSend.h.set((LPBYTE)&rSend, 0xF3, 104, sizeof(rSend));
	rSend.MocNapCheck1 = gMocNap.MocNapCheck1;
	rSend.MocNapCheck2 = gMocNap.MocNapCheck2;
	rSend.MocNapCheck3 = gMocNap.MocNapCheck3;
	rSend.MocNapCheck4 = gMocNap.MocNapCheck4;
	rSend.MocNapCheck5 = gMocNap.MocNapCheck5;
	rSend.MocNapCheck6 = gMocNap.MocNapCheck6;
	rSend.MocNapCheck7 = gMocNap.MocNapCheck7;
	rSend.MocNapCheck8 = gMocNap.MocNapCheck8;
	rSend.MocNapCheck9 = gMocNap.MocNapCheck9;
	rSend.MocNapCheck10 = gMocNap.MocNapCheck10;
	rSend.MocNapCheck11 = gMocNap.MocNapCheck11;
	rSend.MocNapCheck12 = gMocNap.MocNapCheck12;
	rSend.MocNapCheck13 = gMocNap.MocNapCheck13;
	//---
	rSend.MOCNAPCOIN = lpObj->MOCNAPCOIN;
	rSend.MOCNAP1 = lpObj->QUANAP.MOCNAP1;
	rSend.MOCNAP2 = lpObj->QUANAP.MOCNAP2;
	rSend.MOCNAP3 = lpObj->QUANAP.MOCNAP3;
	rSend.MOCNAP4 = lpObj->QUANAP.MOCNAP4;
	rSend.MOCNAP5 = lpObj->QUANAP.MOCNAP5;
	rSend.MOCNAP6 = lpObj->QUANAP.MOCNAP6;
	rSend.MOCNAP7 = lpObj->QUANAP.MOCNAP7;
	rSend.MOCNAP8 = lpObj->QUANAP.MOCNAP8;
	rSend.MOCNAP9 = lpObj->QUANAP.MOCNAP9;
	rSend.MOCNAP10 = lpObj->QUANAP.MOCNAP10;
	rSend.MOCNAP11 = lpObj->QUANAP.MOCNAP11;
	rSend.MOCNAP12 = lpObj->QUANAP.MOCNAP12;
	rSend.MOCNAP13 = lpObj->QUANAP.MOCNAP13;
	DataSend(aIndex, (LPBYTE)&rSend, sizeof(rSend));
}

void CMocNap::Load()
{
	this->MocNapCheck1 = GetPrivateProfileInt("Config", "MocNapCheck1", 0, gPath.GetFullPath("Custom\\MocNap\\MocNapSendClient.ini"));
	this->MocNapCheck2 = GetPrivateProfileInt("Config", "MocNapCheck2", 0, gPath.GetFullPath("Custom\\MocNap\\MocNapSendClient.ini"));
	this->MocNapCheck3 = GetPrivateProfileInt("Config", "MocNapCheck3", 0, gPath.GetFullPath("Custom\\MocNap\\MocNapSendClient.ini"));
	this->MocNapCheck4 = GetPrivateProfileInt("Config", "MocNapCheck4", 0, gPath.GetFullPath("Custom\\MocNap\\MocNapSendClient.ini"));
	this->MocNapCheck5 = GetPrivateProfileInt("Config", "MocNapCheck5", 0, gPath.GetFullPath("Custom\\MocNap\\MocNapSendClient.ini"));
	this->MocNapCheck6 = GetPrivateProfileInt("Config", "MocNapCheck6", 0, gPath.GetFullPath("Custom\\MocNap\\MocNapSendClient.ini"));
	this->MocNapCheck7 = GetPrivateProfileInt("Config", "MocNapCheck7", 0, gPath.GetFullPath("Custom\\MocNap\\MocNapSendClient.ini"));
	this->MocNapCheck8 = GetPrivateProfileInt("Config", "MocNapCheck8", 0, gPath.GetFullPath("Custom\\MocNap\\MocNapSendClient.ini"));
	this->MocNapCheck9 = GetPrivateProfileInt("Config", "MocNapCheck9", 0, gPath.GetFullPath("Custom\\MocNap\\MocNapSendClient.ini"));
	this->MocNapCheck10 = GetPrivateProfileInt("Config", "MocNapCheck10", 0, gPath.GetFullPath("Custom\\MocNap\\MocNapSendClient.ini"));
	this->MocNapCheck11 = GetPrivateProfileInt("Config", "MocNapCheck11", 0, gPath.GetFullPath("Custom\\MocNap\\MocNapSendClient.ini"));
	this->MocNapCheck12 = GetPrivateProfileInt("Config", "MocNapCheck12", 0, gPath.GetFullPath("Custom\\MocNap\\MocNapSendClient.ini"));
	this->MocNapCheck13 = GetPrivateProfileInt("Config", "MocNapCheck13", 0, gPath.GetFullPath("Custom\\MocNap\\MocNapSendClient.ini"));
}

void CMocNap::MocNap1(LPOBJ lpObj)  // ok
{
	int SetMocNap1 = 0;
	if (lpObj->MOCNAPCOIN >= this->MocNapCheck1)
	{
		if (lpObj->QUANAP.MOCNAP1 == 1)
		{	
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã nhận quà không thể nhận lại!");
			return;
		}
		if (gItemManager.CheckItemInventorySpace(lpObj, 4, 4) == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Hòm đồ đã đầy !");
			return;
		}
		MOCNAP_INFO* lpInfo = &this->m_MocNapInfo[lpObj->Class];
		for (std::vector<CUSTOM_MOC_NAP_INFO>::iterator it = lpInfo->MOCNAP1.begin(); it != lpInfo->MOCNAP1.end(); it++)
		{
			BYTE ItemSocketOption[MAX_SOCKET_OPTION] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
			if (gSocketItemType.CheckSocketItemType(it->ItemIndex) == 1)
			{
				int qtd = gSocketItemType.GetSocketItemMaxSocket(it->ItemIndex);
				ItemSocketOption[0] = (BYTE)((qtd > 0) ? ((it->ItemSocket1 != 255) ? it->ItemSocket1 : 255) : 255);
				ItemSocketOption[1] = (BYTE)((qtd > 1) ? ((it->ItemSocket2 != 255) ? it->ItemSocket2 : 255) : 255);
				ItemSocketOption[2] = (BYTE)((qtd > 2) ? ((it->ItemSocket3 != 255) ? it->ItemSocket3 : 255) : 255);
				ItemSocketOption[3] = (BYTE)((qtd > 3) ? ((it->ItemSocket4 != 255) ? it->ItemSocket4 : 255) : 255);
				ItemSocketOption[4] = (BYTE)((qtd > 4) ? ((it->ItemSocket5 != 255) ? it->ItemSocket5 : 255) : 255);
			}
			SetMocNap1++;
			GDCreateItemSend(lpObj->Index, 0xEB, 0, 0, it->ItemIndex, it->ItemLevel, 0, it->ItemSkill, it->ItemLuck, it->ItemOption, -1, it->ItemExcellent, it->ItemAncient, it->ItemJOH, it->ItemOpEx, ItemSocketOption, 0xFF, 0);
		}
		if (SetMocNap1 != 0)
		{
			lpObj->QUANAP.MOCNAP1 = 1;
			this->GDSaveUserInfo(lpObj->Index);
		}
	}
}
void CMocNap::MocNap2(LPOBJ lpObj)  // ok
{
	int SetMocNap2 = 0;
	if (lpObj->MOCNAPCOIN >= this->MocNapCheck2)
	{
		if (lpObj->QUANAP.MOCNAP2 == 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã nhận quà không thể nhận lại!");
			return;
		}
		if (gItemManager.CheckItemInventorySpace(lpObj, 4, 4) == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Hòm đồ đã đầy !");
			return;
		}
		MOCNAP_INFO* lpInfo = &this->m_MocNapInfo[lpObj->Class];
		for (std::vector<CUSTOM_MOC_NAP_INFO>::iterator it = lpInfo->MOCNAP2.begin(); it != lpInfo->MOCNAP2.end(); it++)
		{
			BYTE ItemSocketOption[MAX_SOCKET_OPTION] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
			if (gSocketItemType.CheckSocketItemType(it->ItemIndex) == 1)
			{
				int qtd = gSocketItemType.GetSocketItemMaxSocket(it->ItemIndex);
				ItemSocketOption[0] = (BYTE)((qtd > 0) ? ((it->ItemSocket1 != 255) ? it->ItemSocket1 : 255) : 255);
				ItemSocketOption[1] = (BYTE)((qtd > 1) ? ((it->ItemSocket2 != 255) ? it->ItemSocket2 : 255) : 255);
				ItemSocketOption[2] = (BYTE)((qtd > 2) ? ((it->ItemSocket3 != 255) ? it->ItemSocket3 : 255) : 255);
				ItemSocketOption[3] = (BYTE)((qtd > 3) ? ((it->ItemSocket4 != 255) ? it->ItemSocket4 : 255) : 255);
				ItemSocketOption[4] = (BYTE)((qtd > 4) ? ((it->ItemSocket5 != 255) ? it->ItemSocket5 : 255) : 255);
			}
			SetMocNap2++;
			GDCreateItemSend(lpObj->Index, 0xEB, 0, 0, it->ItemIndex, it->ItemLevel, 0, it->ItemSkill, it->ItemLuck, it->ItemOption, -1, it->ItemExcellent, it->ItemAncient, it->ItemJOH, it->ItemOpEx, ItemSocketOption, 0xFF, 0);
		}
		if (SetMocNap2 != 0)
		{
			lpObj->QUANAP.MOCNAP2 = 1;
			this->GDSaveUserInfo(lpObj->Index);
		}
	}
}
void CMocNap::MocNap3(LPOBJ lpObj)  // ok
{
	int SetMocNap3 = 0;
	if (lpObj->MOCNAPCOIN >= this->MocNapCheck3)
	{
		if (lpObj->QUANAP.MOCNAP3 == 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã nhận quà không thể nhận lại!");
			return;
		}
		if (gItemManager.CheckItemInventorySpace(lpObj, 4, 4) == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Hòm đồ đã đầy !");
			return;
		}
		MOCNAP_INFO* lpInfo = &this->m_MocNapInfo[lpObj->Class];
		for (std::vector<CUSTOM_MOC_NAP_INFO>::iterator it = lpInfo->MOCNAP3.begin(); it != lpInfo->MOCNAP3.end(); it++)
		{
			BYTE ItemSocketOption[MAX_SOCKET_OPTION] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
			if (gSocketItemType.CheckSocketItemType(it->ItemIndex) == 1)
			{
				int qtd = gSocketItemType.GetSocketItemMaxSocket(it->ItemIndex);
				ItemSocketOption[0] = (BYTE)((qtd > 0) ? ((it->ItemSocket1 != 255) ? it->ItemSocket1 : 255) : 255);
				ItemSocketOption[1] = (BYTE)((qtd > 1) ? ((it->ItemSocket2 != 255) ? it->ItemSocket2 : 255) : 255);
				ItemSocketOption[2] = (BYTE)((qtd > 2) ? ((it->ItemSocket3 != 255) ? it->ItemSocket3 : 255) : 255);
				ItemSocketOption[3] = (BYTE)((qtd > 3) ? ((it->ItemSocket4 != 255) ? it->ItemSocket4 : 255) : 255);
				ItemSocketOption[4] = (BYTE)((qtd > 4) ? ((it->ItemSocket5 != 255) ? it->ItemSocket5 : 255) : 255);
			}
			SetMocNap3++;
			GDCreateItemSend(lpObj->Index, 0xEB, 0, 0, it->ItemIndex, it->ItemLevel, 0, it->ItemSkill, it->ItemLuck, it->ItemOption, -1, it->ItemExcellent, it->ItemAncient, it->ItemJOH, it->ItemOpEx, ItemSocketOption, 0xFF, 0);
		}
		if (SetMocNap3 != 0)
		{
			lpObj->QUANAP.MOCNAP3 = 1;
			this->GDSaveUserInfo(lpObj->Index);
		}
	}
}
void CMocNap::MocNap4(LPOBJ lpObj)  // ok
{
	int SetMocNap4 = 0;
	if (lpObj->MOCNAPCOIN >= this->MocNapCheck4)
	{
		if (lpObj->QUANAP.MOCNAP4 == 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã nhận quà không thể nhận lại!");
			return;
		}
		if (gItemManager.CheckItemInventorySpace(lpObj, 4, 4) == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Hòm đồ đã đầy !");
			return;
		}
		MOCNAP_INFO* lpInfo = &this->m_MocNapInfo[lpObj->Class];
		for (std::vector<CUSTOM_MOC_NAP_INFO>::iterator it = lpInfo->MOCNAP4.begin(); it != lpInfo->MOCNAP4.end(); it++)
		{
			BYTE ItemSocketOption[MAX_SOCKET_OPTION] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
			if (gSocketItemType.CheckSocketItemType(it->ItemIndex) == 1)
			{
				int qtd = gSocketItemType.GetSocketItemMaxSocket(it->ItemIndex);
				ItemSocketOption[0] = (BYTE)((qtd > 0) ? ((it->ItemSocket1 != 255) ? it->ItemSocket1 : 255) : 255);
				ItemSocketOption[1] = (BYTE)((qtd > 1) ? ((it->ItemSocket2 != 255) ? it->ItemSocket2 : 255) : 255);
				ItemSocketOption[2] = (BYTE)((qtd > 2) ? ((it->ItemSocket3 != 255) ? it->ItemSocket3 : 255) : 255);
				ItemSocketOption[3] = (BYTE)((qtd > 3) ? ((it->ItemSocket4 != 255) ? it->ItemSocket4 : 255) : 255);
				ItemSocketOption[4] = (BYTE)((qtd > 4) ? ((it->ItemSocket5 != 255) ? it->ItemSocket5 : 255) : 255);
			}
			SetMocNap4++;
			GDCreateItemSend(lpObj->Index, 0xEB, 0, 0, it->ItemIndex, it->ItemLevel, 0, it->ItemSkill, it->ItemLuck, it->ItemOption, -1, it->ItemExcellent, it->ItemAncient, it->ItemJOH, it->ItemOpEx, ItemSocketOption, 0xFF, 0);
		}
		if (SetMocNap4 != 0)
		{
			lpObj->QUANAP.MOCNAP4 = 1;
			this->GDSaveUserInfo(lpObj->Index);
		}
	}
}
void CMocNap::MocNap5(LPOBJ lpObj)  // ok
{
	int regalo = 0;
	if (lpObj->MOCNAPCOIN >= this->MocNapCheck5)
	{
		if (lpObj->QUANAP.MOCNAP5 == 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã nhận quà không thể nhận lại!");
			return;
		}
		if (gItemManager.CheckItemInventorySpace(lpObj, 4, 4) == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Hòm đồ đã đầy !");
			return;
		}
		MOCNAP_INFO* lpInfo = &this->m_MocNapInfo[lpObj->Class];
		for (std::vector<CUSTOM_MOC_NAP_INFO>::iterator it = lpInfo->MOCNAP5.begin(); it != lpInfo->MOCNAP5.end(); it++)
		{
			BYTE ItemSocketOption[MAX_SOCKET_OPTION] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
			if (gSocketItemType.CheckSocketItemType(it->ItemIndex) == 1)
			{
				int qtd = gSocketItemType.GetSocketItemMaxSocket(it->ItemIndex);
				ItemSocketOption[0] = (BYTE)((qtd > 0) ? ((it->ItemSocket1 != 255) ? it->ItemSocket1 : 255) : 255);
				ItemSocketOption[1] = (BYTE)((qtd > 1) ? ((it->ItemSocket2 != 255) ? it->ItemSocket2 : 255) : 255);
				ItemSocketOption[2] = (BYTE)((qtd > 2) ? ((it->ItemSocket3 != 255) ? it->ItemSocket3 : 255) : 255);
				ItemSocketOption[3] = (BYTE)((qtd > 3) ? ((it->ItemSocket4 != 255) ? it->ItemSocket4 : 255) : 255);
				ItemSocketOption[4] = (BYTE)((qtd > 4) ? ((it->ItemSocket5 != 255) ? it->ItemSocket5 : 255) : 255);
			}
			regalo++;
			GDCreateItemSend(lpObj->Index, 0xEB, 0, 0, it->ItemIndex, it->ItemLevel, 0, it->ItemSkill, it->ItemLuck, it->ItemOption, -1, it->ItemExcellent, it->ItemAncient, it->ItemJOH, it->ItemOpEx, ItemSocketOption, 0xFF, 0);
		}
		if (regalo != 0)
		{
			lpObj->QUANAP.MOCNAP5 = 1;
			this->GDSaveUserInfo(lpObj->Index);
		}
	}
}
void CMocNap::MocNap6(LPOBJ lpObj)  // ok
{
	int regalo = 0;
	if (lpObj->MOCNAPCOIN >= this->MocNapCheck6)
	{
		if (lpObj->QUANAP.MOCNAP6 == 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã nhận quà không thể nhận lại!");
			return;
		}
		if (gItemManager.CheckItemInventorySpace(lpObj, 4, 4) == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Hòm đồ đã đầy !");
			return;
		}
		MOCNAP_INFO* lpInfo = &this->m_MocNapInfo[lpObj->Class];
		for (std::vector<CUSTOM_MOC_NAP_INFO>::iterator it = lpInfo->MOCNAP6.begin(); it != lpInfo->MOCNAP6.end(); it++)
		{
			BYTE ItemSocketOption[MAX_SOCKET_OPTION] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
			if (gSocketItemType.CheckSocketItemType(it->ItemIndex) == 1)
			{
				int qtd = gSocketItemType.GetSocketItemMaxSocket(it->ItemIndex);
				ItemSocketOption[0] = (BYTE)((qtd > 0) ? ((it->ItemSocket1 != 255) ? it->ItemSocket1 : 255) : 255);
				ItemSocketOption[1] = (BYTE)((qtd > 1) ? ((it->ItemSocket2 != 255) ? it->ItemSocket2 : 255) : 255);
				ItemSocketOption[2] = (BYTE)((qtd > 2) ? ((it->ItemSocket3 != 255) ? it->ItemSocket3 : 255) : 255);
				ItemSocketOption[3] = (BYTE)((qtd > 3) ? ((it->ItemSocket4 != 255) ? it->ItemSocket4 : 255) : 255);
				ItemSocketOption[4] = (BYTE)((qtd > 4) ? ((it->ItemSocket5 != 255) ? it->ItemSocket5 : 255) : 255);
			}
			regalo++;
			GDCreateItemSend(lpObj->Index, 0xEB, 0, 0, it->ItemIndex, it->ItemLevel, 0, it->ItemSkill, it->ItemLuck, it->ItemOption, -1, it->ItemExcellent, it->ItemAncient, it->ItemJOH, it->ItemOpEx, ItemSocketOption, 0xFF, 0);
		}
		if (regalo != 0)
		{
			lpObj->QUANAP.MOCNAP6 = 1;
			this->GDSaveUserInfo(lpObj->Index);
		}
	}
}
void CMocNap::MocNap7(LPOBJ lpObj)  // ok
{
	int regalo = 0;
	if (lpObj->MOCNAPCOIN >= this->MocNapCheck7)
	{
		if (lpObj->QUANAP.MOCNAP7 == 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã nhận quà không thể nhận lại!");
			return;
		}
		if (gItemManager.CheckItemInventorySpace(lpObj, 4, 4) == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Hòm đồ đã đầy !");
			return;
		}
		MOCNAP_INFO* lpInfo = &this->m_MocNapInfo[lpObj->Class];
		for (std::vector<CUSTOM_MOC_NAP_INFO>::iterator it = lpInfo->MOCNAP7.begin(); it != lpInfo->MOCNAP7.end(); it++)
		{
			BYTE ItemSocketOption[MAX_SOCKET_OPTION] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
			if (gSocketItemType.CheckSocketItemType(it->ItemIndex) == 1)
			{
				int qtd = gSocketItemType.GetSocketItemMaxSocket(it->ItemIndex);
				ItemSocketOption[0] = (BYTE)((qtd > 0) ? ((it->ItemSocket1 != 255) ? it->ItemSocket1 : 255) : 255);
				ItemSocketOption[1] = (BYTE)((qtd > 1) ? ((it->ItemSocket2 != 255) ? it->ItemSocket2 : 255) : 255);
				ItemSocketOption[2] = (BYTE)((qtd > 2) ? ((it->ItemSocket3 != 255) ? it->ItemSocket3 : 255) : 255);
				ItemSocketOption[3] = (BYTE)((qtd > 3) ? ((it->ItemSocket4 != 255) ? it->ItemSocket4 : 255) : 255);
				ItemSocketOption[4] = (BYTE)((qtd > 4) ? ((it->ItemSocket5 != 255) ? it->ItemSocket5 : 255) : 255);
			}
			regalo++;
			GDCreateItemSend(lpObj->Index, 0xEB, 0, 0, it->ItemIndex, it->ItemLevel, 0, it->ItemSkill, it->ItemLuck, it->ItemOption, -1, it->ItemExcellent, it->ItemAncient, it->ItemJOH, it->ItemOpEx, ItemSocketOption, 0xFF, 0);
		}
		if (regalo != 0)
		{
			lpObj->QUANAP.MOCNAP7 = 1;
			this->GDSaveUserInfo(lpObj->Index);
		}
	}
}
void CMocNap::MocNap8(LPOBJ lpObj)  // ok
{
	int regalo = 0;
	if (lpObj->MOCNAPCOIN >= this->MocNapCheck8)
	{
		if (lpObj->QUANAP.MOCNAP8 == 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã nhận quà không thể nhận lại!");
			return;
		}
		if (gItemManager.CheckItemInventorySpace(lpObj, 4, 4) == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Hòm đồ đã đầy !");
			return;
		}
		MOCNAP_INFO* lpInfo = &this->m_MocNapInfo[lpObj->Class];
		for (std::vector<CUSTOM_MOC_NAP_INFO>::iterator it = lpInfo->MOCNAP8.begin(); it != lpInfo->MOCNAP8.end(); it++)
		{
			BYTE ItemSocketOption[MAX_SOCKET_OPTION] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
			if (gSocketItemType.CheckSocketItemType(it->ItemIndex) == 1)
			{
				int qtd = gSocketItemType.GetSocketItemMaxSocket(it->ItemIndex);
				ItemSocketOption[0] = (BYTE)((qtd > 0) ? ((it->ItemSocket1 != 255) ? it->ItemSocket1 : 255) : 255);
				ItemSocketOption[1] = (BYTE)((qtd > 1) ? ((it->ItemSocket2 != 255) ? it->ItemSocket2 : 255) : 255);
				ItemSocketOption[2] = (BYTE)((qtd > 2) ? ((it->ItemSocket3 != 255) ? it->ItemSocket3 : 255) : 255);
				ItemSocketOption[3] = (BYTE)((qtd > 3) ? ((it->ItemSocket4 != 255) ? it->ItemSocket4 : 255) : 255);
				ItemSocketOption[4] = (BYTE)((qtd > 4) ? ((it->ItemSocket5 != 255) ? it->ItemSocket5 : 255) : 255);
			}
			regalo++;
			GDCreateItemSend(lpObj->Index, 0xEB, 0, 0, it->ItemIndex, it->ItemLevel, 0, it->ItemSkill, it->ItemLuck, it->ItemOption, -1, it->ItemExcellent, it->ItemAncient, it->ItemJOH, it->ItemOpEx, ItemSocketOption, 0xFF, 0);
		}
		if (regalo != 0)
		{
			lpObj->QUANAP.MOCNAP8 = 1;
			this->GDSaveUserInfo(lpObj->Index);
		}
	}
}
void CMocNap::MocNap9(LPOBJ lpObj)  // ok
{
	int regalo = 0;
	if (lpObj->MOCNAPCOIN >= this->MocNapCheck9)
	{
		if (lpObj->QUANAP.MOCNAP9 == 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã nhận quà không thể nhận lại!");
			return;
		}
		if (gItemManager.CheckItemInventorySpace(lpObj, 4, 4) == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Hòm đồ đã đầy !");
			return;
		}
		MOCNAP_INFO* lpInfo = &this->m_MocNapInfo[lpObj->Class];
		for (std::vector<CUSTOM_MOC_NAP_INFO>::iterator it = lpInfo->MOCNAP9.begin(); it != lpInfo->MOCNAP9.end(); it++)
		{
			BYTE ItemSocketOption[MAX_SOCKET_OPTION] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
			if (gSocketItemType.CheckSocketItemType(it->ItemIndex) == 1)
			{
				int qtd = gSocketItemType.GetSocketItemMaxSocket(it->ItemIndex);
				ItemSocketOption[0] = (BYTE)((qtd > 0) ? ((it->ItemSocket1 != 255) ? it->ItemSocket1 : 255) : 255);
				ItemSocketOption[1] = (BYTE)((qtd > 1) ? ((it->ItemSocket2 != 255) ? it->ItemSocket2 : 255) : 255);
				ItemSocketOption[2] = (BYTE)((qtd > 2) ? ((it->ItemSocket3 != 255) ? it->ItemSocket3 : 255) : 255);
				ItemSocketOption[3] = (BYTE)((qtd > 3) ? ((it->ItemSocket4 != 255) ? it->ItemSocket4 : 255) : 255);
				ItemSocketOption[4] = (BYTE)((qtd > 4) ? ((it->ItemSocket5 != 255) ? it->ItemSocket5 : 255) : 255);
			}
			regalo++;
			GDCreateItemSend(lpObj->Index, 0xEB, 0, 0, it->ItemIndex, it->ItemLevel, 0, it->ItemSkill, it->ItemLuck, it->ItemOption, -1, it->ItemExcellent, it->ItemAncient, it->ItemJOH, it->ItemOpEx, ItemSocketOption, 0xFF, 0);
		}
		if (regalo != 0)
		{
			lpObj->QUANAP.MOCNAP9 = 1;
			this->GDSaveUserInfo(lpObj->Index);
		}
	}
}
void CMocNap::MocNap10(LPOBJ lpObj)  // ok
{
	int regalo = 0;
	if (lpObj->MOCNAPCOIN >= this->MocNapCheck10)
	{
		if (lpObj->QUANAP.MOCNAP10 == 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã nhận quà không thể nhận lại!");
			return;
		}
		if (gItemManager.CheckItemInventorySpace(lpObj, 4, 4) == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Hòm đồ đã đầy !");
			return;
		}
		MOCNAP_INFO* lpInfo = &this->m_MocNapInfo[lpObj->Class];
		for (std::vector<CUSTOM_MOC_NAP_INFO>::iterator it = lpInfo->MOCNAP10.begin(); it != lpInfo->MOCNAP10.end(); it++)
		{
			BYTE ItemSocketOption[MAX_SOCKET_OPTION] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
			if (gSocketItemType.CheckSocketItemType(it->ItemIndex) == 1)
			{
				int qtd = gSocketItemType.GetSocketItemMaxSocket(it->ItemIndex);
				ItemSocketOption[0] = (BYTE)((qtd > 0) ? ((it->ItemSocket1 != 255) ? it->ItemSocket1 : 255) : 255);
				ItemSocketOption[1] = (BYTE)((qtd > 1) ? ((it->ItemSocket2 != 255) ? it->ItemSocket2 : 255) : 255);
				ItemSocketOption[2] = (BYTE)((qtd > 2) ? ((it->ItemSocket3 != 255) ? it->ItemSocket3 : 255) : 255);
				ItemSocketOption[3] = (BYTE)((qtd > 3) ? ((it->ItemSocket4 != 255) ? it->ItemSocket4 : 255) : 255);
				ItemSocketOption[4] = (BYTE)((qtd > 4) ? ((it->ItemSocket5 != 255) ? it->ItemSocket5 : 255) : 255);
			}
			regalo++;
			GDCreateItemSend(lpObj->Index, 0xEB, 0, 0, it->ItemIndex, it->ItemLevel, 0, it->ItemSkill, it->ItemLuck, it->ItemOption, -1, it->ItemExcellent, it->ItemAncient, it->ItemJOH, it->ItemOpEx, ItemSocketOption, 0xFF, 0);
		}
		if (regalo != 0)
		{
			lpObj->QUANAP.MOCNAP10 = 1;
			this->GDSaveUserInfo(lpObj->Index);
		}
	}
}
void CMocNap::MocNap11(LPOBJ lpObj)  // ok
{
	int regalo = 0;
	if (lpObj->MOCNAPCOIN >= this->MocNapCheck11)
	{
		if (lpObj->QUANAP.MOCNAP11 == 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã nhận quà không thể nhận lại!");
			return;
		}
		if (gItemManager.CheckItemInventorySpace(lpObj, 4, 4) == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Hòm đồ đã đầy !");
			return;
		}
		MOCNAP_INFO* lpInfo = &this->m_MocNapInfo[lpObj->Class];
		for (std::vector<CUSTOM_MOC_NAP_INFO>::iterator it = lpInfo->MOCNAP11.begin(); it != lpInfo->MOCNAP11.end(); it++)
		{
			BYTE ItemSocketOption[MAX_SOCKET_OPTION] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
			if (gSocketItemType.CheckSocketItemType(it->ItemIndex) == 1)
			{
				int qtd = gSocketItemType.GetSocketItemMaxSocket(it->ItemIndex);
				ItemSocketOption[0] = (BYTE)((qtd > 0) ? ((it->ItemSocket1 != 255) ? it->ItemSocket1 : 255) : 255);
				ItemSocketOption[1] = (BYTE)((qtd > 1) ? ((it->ItemSocket2 != 255) ? it->ItemSocket2 : 255) : 255);
				ItemSocketOption[2] = (BYTE)((qtd > 2) ? ((it->ItemSocket3 != 255) ? it->ItemSocket3 : 255) : 255);
				ItemSocketOption[3] = (BYTE)((qtd > 3) ? ((it->ItemSocket4 != 255) ? it->ItemSocket4 : 255) : 255);
				ItemSocketOption[4] = (BYTE)((qtd > 4) ? ((it->ItemSocket5 != 255) ? it->ItemSocket5 : 255) : 255);
			}
			regalo++;
			GDCreateItemSend(lpObj->Index, 0xEB, 0, 0, it->ItemIndex, it->ItemLevel, 0, it->ItemSkill, it->ItemLuck, it->ItemOption, -1, it->ItemExcellent, it->ItemAncient, it->ItemJOH, it->ItemOpEx, ItemSocketOption, 0xFF, 0);
		}
		if (regalo != 0)
		{
			lpObj->QUANAP.MOCNAP11 = 1;
			this->GDSaveUserInfo(lpObj->Index);
		}
	}
}
void CMocNap::MocNap12(LPOBJ lpObj)  // ok
{
	int regalo = 0;
	if (lpObj->MOCNAPCOIN >= this->MocNapCheck12)
	{
		if (lpObj->QUANAP.MOCNAP12 == 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã nhận quà không thể nhận lại!");
			return;
		}
		if (gItemManager.CheckItemInventorySpace(lpObj, 4, 4) == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Hòm đồ đã đầy !");
			return;
		}
		MOCNAP_INFO* lpInfo = &this->m_MocNapInfo[lpObj->Class];
		for (std::vector<CUSTOM_MOC_NAP_INFO>::iterator it = lpInfo->MOCNAP12.begin(); it != lpInfo->MOCNAP12.end(); it++)
		{
			BYTE ItemSocketOption[MAX_SOCKET_OPTION] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
			if (gSocketItemType.CheckSocketItemType(it->ItemIndex) == 1)
			{
				int qtd = gSocketItemType.GetSocketItemMaxSocket(it->ItemIndex);
				ItemSocketOption[0] = (BYTE)((qtd > 0) ? ((it->ItemSocket1 != 255) ? it->ItemSocket1 : 255) : 255);
				ItemSocketOption[1] = (BYTE)((qtd > 1) ? ((it->ItemSocket2 != 255) ? it->ItemSocket2 : 255) : 255);
				ItemSocketOption[2] = (BYTE)((qtd > 2) ? ((it->ItemSocket3 != 255) ? it->ItemSocket3 : 255) : 255);
				ItemSocketOption[3] = (BYTE)((qtd > 3) ? ((it->ItemSocket4 != 255) ? it->ItemSocket4 : 255) : 255);
				ItemSocketOption[4] = (BYTE)((qtd > 4) ? ((it->ItemSocket5 != 255) ? it->ItemSocket5 : 255) : 255);
			}
			regalo++;
			GDCreateItemSend(lpObj->Index, 0xEB, 0, 0, it->ItemIndex, it->ItemLevel, 0, it->ItemSkill, it->ItemLuck, it->ItemOption, -1, it->ItemExcellent, it->ItemAncient, it->ItemJOH, it->ItemOpEx, ItemSocketOption, 0xFF, 0);
		}
		if (regalo != 0)
		{
			lpObj->QUANAP.MOCNAP12 = 1;
			this->GDSaveUserInfo(lpObj->Index);
		}
	}
}
void CMocNap::MocNap13(LPOBJ lpObj)  // ok
{
	int regalo = 0;
	if (lpObj->MOCNAPCOIN >= this->MocNapCheck13)
	{
		if (lpObj->QUANAP.MOCNAP13 == 1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã nhận quà không thể nhận lại!");
			return;
		}
		if (gItemManager.CheckItemInventorySpace(lpObj, 4, 4) == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Hòm đồ đã đầy !");
			return;
		}
		MOCNAP_INFO* lpInfo = &this->m_MocNapInfo[lpObj->Class];
		for (std::vector<CUSTOM_MOC_NAP_INFO>::iterator it = lpInfo->MOCNAP13.begin(); it != lpInfo->MOCNAP13.end(); it++)
		{
			BYTE ItemSocketOption[MAX_SOCKET_OPTION] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
			if (gSocketItemType.CheckSocketItemType(it->ItemIndex) == 1)
			{
				int qtd = gSocketItemType.GetSocketItemMaxSocket(it->ItemIndex);
				ItemSocketOption[0] = (BYTE)((qtd > 0) ? ((it->ItemSocket1 != 255) ? it->ItemSocket1 : 255) : 255);
				ItemSocketOption[1] = (BYTE)((qtd > 1) ? ((it->ItemSocket2 != 255) ? it->ItemSocket2 : 255) : 255);
				ItemSocketOption[2] = (BYTE)((qtd > 2) ? ((it->ItemSocket3 != 255) ? it->ItemSocket3 : 255) : 255);
				ItemSocketOption[3] = (BYTE)((qtd > 3) ? ((it->ItemSocket4 != 255) ? it->ItemSocket4 : 255) : 255);
				ItemSocketOption[4] = (BYTE)((qtd > 4) ? ((it->ItemSocket5 != 255) ? it->ItemSocket5 : 255) : 255);
			}
			regalo++;
			GDCreateItemSend(lpObj->Index, 0xEB, 0, 0, it->ItemIndex, it->ItemLevel, 0, it->ItemSkill, it->ItemLuck, it->ItemOption, -1, it->ItemExcellent, it->ItemAncient, it->ItemJOH, it->ItemOpEx, ItemSocketOption, 0xFF, 0);
		}
		if (regalo != 0)
		{
			lpObj->QUANAP.MOCNAP13 = 1;
			this->GDSaveUserInfo(lpObj->Index);
		}
	}
}
#endif