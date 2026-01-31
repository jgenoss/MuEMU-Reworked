#include "StdAfx.h"
#include "CustomVKR.h"
#include "MemScript.h"
#include "Message.h"
#include "Notice.h"
#include "Util.h"
#include "ItemManager.h"
VuKhiRong gVuKhiRong;

VuKhiRong::VuKhiRong(void)
{
}


VuKhiRong::~VuKhiRong(void)
{
}

void VuKhiRong::Init()
{
	this->m_VuKhiRong.Enabled = 0;
	this->m_VuKhiRong.Dame3 = 0;
	this->m_VuKhiRong.Dame5 = 0;
	this->m_VuKhiRong.Dame7 = 0;
}

void VuKhiRong::Load(char* path) // OK
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

			if (strcmp("end", lpMemScript->GetString()) == 0)
			{
				break;
			}

			m_VuKhiRong.Enabled = lpMemScript->GetNumber();

			m_VuKhiRong.Dame3 = lpMemScript->GetAsNumber();

			m_VuKhiRong.Dame5 = lpMemScript->GetAsNumber();

			m_VuKhiRong.Dame7 = lpMemScript->GetAsNumber();

		}
	}
	catch (...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}


void VuKhiRong::Option(LPOBJ lpObj, bool flag)
{
	if (!this->m_VuKhiRong.Enabled) return;

	if (flag != 0)
	{
		return;
	}

	int VuKhiRong = 0;


	if (this->CountItem(lpObj, 13) >= 1)
	{
		VuKhiRong = 1;
	}

	if (this->CountItem(lpObj, 14) >= 1)
	{
		VuKhiRong = 2;
	}

	if (this->CountItem(lpObj, 15) >= 1)
	{
		VuKhiRong = 3;
	}

	PMSG_VUKHIRONG_REQ pRequest;
	pRequest.Head.set(0xFB, 0xE6, sizeof(pRequest));
	pRequest.vukhirong = VuKhiRong;
	pRequest.dong1 = this->m_VuKhiRong.Dame3;
	pRequest.dong2 = this->m_VuKhiRong.Dame5;
	pRequest.dong3 = this->m_VuKhiRong.Dame7;

	DataSend(lpObj->Index, (LPBYTE)&pRequest, sizeof(pRequest));

	switch (VuKhiRong)
	{
	case 1:
		lpObj->PhysiDamageMinRight += (lpObj->PhysiDamageMinRight	*this->m_VuKhiRong.Dame3) / 100;
		lpObj->PhysiDamageMaxRight += (lpObj->PhysiDamageMaxRight	*this->m_VuKhiRong.Dame3) / 100;
		lpObj->PhysiDamageMinLeft += (lpObj->PhysiDamageMinLeft	*this->m_VuKhiRong.Dame3) / 100;
		lpObj->PhysiDamageMaxLeft += (lpObj->PhysiDamageMaxLeft	*this->m_VuKhiRong.Dame3) / 100;
		lpObj->MagicDamageMin += (lpObj->MagicDamageMin		*this->m_VuKhiRong.Dame3) / 100;
		lpObj->MagicDamageMax += (lpObj->MagicDamageMax		*this->m_VuKhiRong.Dame3) / 100;
		break;
	case 2:
		lpObj->PhysiDamageMinRight += (lpObj->PhysiDamageMinRight*this->m_VuKhiRong.Dame5) / 100;
		lpObj->PhysiDamageMaxRight += (lpObj->PhysiDamageMaxRight*this->m_VuKhiRong.Dame5) / 100;
		lpObj->PhysiDamageMinLeft += (lpObj->PhysiDamageMinLeft*this->m_VuKhiRong.Dame5) / 100;
		lpObj->PhysiDamageMaxLeft += (lpObj->PhysiDamageMaxLeft*this->m_VuKhiRong.Dame5) / 100;
		lpObj->MagicDamageMin += (lpObj->MagicDamageMin*this->m_VuKhiRong.Dame5) / 100;
		lpObj->MagicDamageMax += (lpObj->MagicDamageMax*this->m_VuKhiRong.Dame5) / 100;
		lpObj->PhysiDamageMinRight += (lpObj->PhysiDamageMinRight*this->m_VuKhiRong.Dame3) / 100;
		lpObj->PhysiDamageMaxRight += (lpObj->PhysiDamageMaxRight*this->m_VuKhiRong.Dame3) / 100;
		lpObj->PhysiDamageMinLeft += (lpObj->PhysiDamageMinLeft*this->m_VuKhiRong.Dame3) / 100;
		lpObj->PhysiDamageMaxLeft += (lpObj->PhysiDamageMaxLeft*this->m_VuKhiRong.Dame3) / 100;
		lpObj->MagicDamageMin += (lpObj->MagicDamageMin*this->m_VuKhiRong.Dame3) / 100;
		lpObj->MagicDamageMax += (lpObj->MagicDamageMax*this->m_VuKhiRong.Dame3) / 100;
		break;
	case 3:
		lpObj->PhysiDamageMinRight += (lpObj->PhysiDamageMinRight*this->m_VuKhiRong.Dame7) / 100;
		lpObj->PhysiDamageMaxRight += (lpObj->PhysiDamageMaxRight*this->m_VuKhiRong.Dame7) / 100;
		lpObj->PhysiDamageMinLeft += (lpObj->PhysiDamageMinLeft*this->m_VuKhiRong.Dame7) / 100;
		lpObj->PhysiDamageMaxLeft += (lpObj->PhysiDamageMaxLeft*this->m_VuKhiRong.Dame7) / 100;
		lpObj->MagicDamageMin += (lpObj->MagicDamageMin*this->m_VuKhiRong.Dame7) / 100;
		lpObj->MagicDamageMax += (lpObj->MagicDamageMax*this->m_VuKhiRong.Dame7) / 100;
		lpObj->PhysiDamageMinRight += (lpObj->PhysiDamageMinRight*this->m_VuKhiRong.Dame5) / 100;
		lpObj->PhysiDamageMaxRight += (lpObj->PhysiDamageMaxRight*this->m_VuKhiRong.Dame5) / 100;
		lpObj->PhysiDamageMinLeft += (lpObj->PhysiDamageMinLeft*this->m_VuKhiRong.Dame5) / 100;
		lpObj->PhysiDamageMaxLeft += (lpObj->PhysiDamageMaxLeft*this->m_VuKhiRong.Dame5) / 100;
		lpObj->MagicDamageMin += (lpObj->MagicDamageMin*this->m_VuKhiRong.Dame5) / 100;
		lpObj->MagicDamageMax += (lpObj->MagicDamageMax*this->m_VuKhiRong.Dame5) / 100;
		lpObj->PhysiDamageMinRight += (lpObj->PhysiDamageMinRight*this->m_VuKhiRong.Dame3) / 100;
		lpObj->PhysiDamageMaxRight += (lpObj->PhysiDamageMaxRight*this->m_VuKhiRong.Dame3) / 100;
		lpObj->PhysiDamageMinLeft += (lpObj->PhysiDamageMinLeft*this->m_VuKhiRong.Dame3) / 100;
		lpObj->PhysiDamageMaxLeft += (lpObj->PhysiDamageMaxLeft*this->m_VuKhiRong.Dame3) / 100;
		lpObj->MagicDamageMin += (lpObj->MagicDamageMin*this->m_VuKhiRong.Dame3) / 100;
		lpObj->MagicDamageMax += (lpObj->MagicDamageMax*this->m_VuKhiRong.Dame3) / 100;
		break;
	default:
		break;
	}
}

int VuKhiRong::CountItem(LPOBJ lpObj, int level)
{
	int count = 0;

	CItem* VK1 = &lpObj->Inventory[0];
	CItem* VK2 = &lpObj->Inventory[1];
	if (lpObj->Inventory[0].m_Index == GET_ITEM(0, 19)
		|| lpObj->Inventory[0].m_Index == GET_ITEM(0, 51)

		|| lpObj->Inventory[0].m_Index == GET_ITEM(0, 60)
		|| lpObj->Inventory[0].m_Index == GET_ITEM(0, 61)

		|| lpObj->Inventory[0].m_Index == GET_ITEM(2, 13)
		|| lpObj->Inventory[0].m_Index == GET_ITEM(2, 25)

		|| lpObj->Inventory[0].m_Index == GET_ITEM(3, 26)
		|| lpObj->Inventory[0].m_Index == GET_ITEM(3, 27)

		|| lpObj->Inventory[0].m_Index == GET_ITEM(4, 18)
		|| lpObj->Inventory[0].m_Index == GET_ITEM(4, 30)

		|| lpObj->Inventory[0].m_Index == GET_ITEM(5, 49)
		|| lpObj->Inventory[0].m_Index == GET_ITEM(5, 50)
//============================================================
		|| lpObj->Inventory[1].m_Index == GET_ITEM(0, 19)
		|| lpObj->Inventory[1].m_Index == GET_ITEM(0, 51)

		|| lpObj->Inventory[1].m_Index == GET_ITEM(0, 60)
		|| lpObj->Inventory[1].m_Index == GET_ITEM(0, 61)

		|| lpObj->Inventory[1].m_Index == GET_ITEM(2, 13)
		|| lpObj->Inventory[1].m_Index == GET_ITEM(2, 25)

		|| lpObj->Inventory[1].m_Index == GET_ITEM(3, 26)
		|| lpObj->Inventory[1].m_Index == GET_ITEM(3, 27)

		|| lpObj->Inventory[1].m_Index == GET_ITEM(4, 18)
		|| lpObj->Inventory[1].m_Index == GET_ITEM(4, 30)

		|| lpObj->Inventory[1].m_Index == GET_ITEM(5, 49)
		|| lpObj->Inventory[1].m_Index == GET_ITEM(5, 50)

	
		)
	{
		if (VK1->m_Level >= level && VK1->m_NewOption)
		{
			count++;;
		}

		if (VK2->m_Level >= level && VK2->m_NewOption)
		{
			count++;;
		}
	}

	return count;
}