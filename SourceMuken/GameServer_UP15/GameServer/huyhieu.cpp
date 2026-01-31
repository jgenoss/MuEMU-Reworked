#include "StdAfx.h"
#include "HuyHieu.h"
#include "MemScript.h"
#include "Message.h"
#include "Notice.h"
#include "Util.h"

HuyHieu gHuyHieu;

HuyHieu::HuyHieu(void)
{
}


HuyHieu::~HuyHieu(void)
{
}

void HuyHieu::Init()
{
	this->m_HuyHieu.Enabled = 0;
	this->m_HuyHieu.dong1 = 0;
	this->m_HuyHieu.dong2 = 0;
	this->m_HuyHieu.dong3 = 0;
	this->m_HuyHieu.dong4 = 0;
	this->m_HuyHieu.dong5 = 0;
}

void HuyHieu::Load(char* path) // OK
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

			m_HuyHieu.Enabled = lpMemScript->GetNumber();

			m_HuyHieu.dong1 = lpMemScript->GetAsNumber();

			m_HuyHieu.dong2 = lpMemScript->GetAsNumber();

			m_HuyHieu.dong3 = lpMemScript->GetAsNumber();

			m_HuyHieu.dong4 = lpMemScript->GetAsNumber();

			m_HuyHieu.dong5 = lpMemScript->GetAsNumber();
		}
	}
	catch (...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}


void HuyHieu::Option(LPOBJ lpObj, bool flag)
{
	if (!this->m_HuyHieu.Enabled) return;

	if (flag != 0)
	{
		return;
	}

	int huyhieu = 0;


	if (this->CountItem(lpObj, 11) >= 5)
	{
		huyhieu = 1;
	}

	if (this->CountItem(lpObj, 12) >= 5)
	{
		huyhieu = 2;
	}

	if (this->CountItem(lpObj, 13) >= 5)
	{
		huyhieu = 3;
	}

	if (this->CountItem(lpObj, 14) >= 5)
	{
		huyhieu = 4;
	}

	if (this->CountItem(lpObj, 15) >= 5)
	{
		huyhieu = 5;
	}

	PMSG_HUYHIEU_REQ pRequest;
	pRequest.Head.set(0xFB, 0xE8, sizeof(pRequest));
	pRequest.huyhieu = huyhieu;
	pRequest.dong1 = this->m_HuyHieu.dong1;
	pRequest.dong2 = this->m_HuyHieu.dong2;
	pRequest.dong3 = this->m_HuyHieu.dong3;
	pRequest.dong4 = this->m_HuyHieu.dong4;
	pRequest.dong5 = this->m_HuyHieu.dong5;

	DataSend(lpObj->Index, (LPBYTE)&pRequest, sizeof(pRequest));

	switch (huyhieu)
	{
	case 1:
		lpObj->AddLife += this->m_HuyHieu.dong1;
		break;
	case 2:
		lpObj->Defense += this->m_HuyHieu.dong2;
		lpObj->AddLife += this->m_HuyHieu.dong1;
		break;
	case 3:
		lpObj->PhysiDamageMinLeft += this->m_HuyHieu.dong3;
		lpObj->PhysiDamageMinRight += this->m_HuyHieu.dong3;
		lpObj->PhysiDamageMaxLeft += this->m_HuyHieu.dong3;
		lpObj->PhysiDamageMaxRight += this->m_HuyHieu.dong3;
		lpObj->Defense += this->m_HuyHieu.dong2;
		lpObj->AddLife += this->m_HuyHieu.dong1;
		break;
	case 4:
		lpObj->DoubleDamageRate += this->m_HuyHieu.dong4;
		lpObj->PhysiDamageMinLeft += this->m_HuyHieu.dong3;
		lpObj->PhysiDamageMinRight += this->m_HuyHieu.dong3;
		lpObj->PhysiDamageMaxLeft += this->m_HuyHieu.dong3;
		lpObj->PhysiDamageMaxRight += this->m_HuyHieu.dong3;
		lpObj->Defense += this->m_HuyHieu.dong2;
		lpObj->AddLife += this->m_HuyHieu.dong1;
		break;
	case 5:
		lpObj->IgnoreDefenseRate += this->m_HuyHieu.dong5;
		lpObj->DoubleDamageRate += this->m_HuyHieu.dong4;
		lpObj->PhysiDamageMinLeft += this->m_HuyHieu.dong3;
		lpObj->PhysiDamageMinRight += this->m_HuyHieu.dong3;
		lpObj->PhysiDamageMaxLeft += this->m_HuyHieu.dong3;
		lpObj->PhysiDamageMaxRight += this->m_HuyHieu.dong3;
		lpObj->Defense += this->m_HuyHieu.dong2;
		lpObj->AddLife += this->m_HuyHieu.dong1;
		break;

	default:
		break;
	}
}

int HuyHieu::CountItem(LPOBJ lpObj, int level)
{
	int count = 0;

	CItem* VK1 = &lpObj->Inventory[0];
	CItem* VK2 = &lpObj->Inventory[1];
	CItem* Helm = &lpObj->Inventory[2];
	CItem* Armor = &lpObj->Inventory[3];
	CItem* Pants = &lpObj->Inventory[4];
	CItem* Gloves = &lpObj->Inventory[5];
	CItem* Boots = &lpObj->Inventory[6];

	if (lpObj->DBClass == 48 || lpObj->DBClass == 49 || lpObj->DBClass == 50)
	{
		if ((VK1->m_Level >= level && VK1->m_NewOption) || (VK2->m_Level >= level && VK2->m_NewOption))
		{
			count += 2;
		}
	}
	else
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

	if (Helm->m_Level >= level && Helm->m_NewOption)
	{
		count++;;
	}
	if (Armor->m_Level >= level && Armor->m_NewOption)
	{
		count++;;
	}
	if (Pants->m_Level >= level && Pants->m_NewOption)
	{
		count++;;
	}
	if (Gloves->m_Level >= level && Gloves->m_NewOption)
	{
		count++;;
	}
	if (Boots->m_Level >= level && Boots->m_NewOption)
	{
		count++;;
	}

	return count;
}