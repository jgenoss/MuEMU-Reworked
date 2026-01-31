#include "StdAfx.h"
#include "CustomCuongHoaWing.h"
#include "MemScript.h"
#include "Message.h"
#include "Notice.h"
#include "Util.h"
#include "ItemManager.h"
CuongHoaWing gCuongHoaWing;

CuongHoaWing::CuongHoaWing(void)
{
}


CuongHoaWing::~CuongHoaWing(void)
{
}

void CuongHoaWing::Init()
{
	this->m_CuongHoaWing.Enabled = 0;
	this->m_CuongHoaWing.Damage1 = 0;
	this->m_CuongHoaWing.Damage2 = 0;
	this->m_CuongHoaWing.Damage3 = 0;
	this->m_CuongHoaWing.Damage4 = 0;
	this->m_CuongHoaWing.Damage5 = 0;
}

void CuongHoaWing::Load(char* path) // OK
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

			m_CuongHoaWing.Enabled = lpMemScript->GetNumber();

			m_CuongHoaWing.Damage1 = lpMemScript->GetAsNumber();

			m_CuongHoaWing.Damage2 = lpMemScript->GetAsNumber();

			m_CuongHoaWing.Damage3 = lpMemScript->GetAsNumber();

			m_CuongHoaWing.Damage4 = lpMemScript->GetAsNumber();

			m_CuongHoaWing.Damage5 = lpMemScript->GetAsNumber();
		}
	}
	catch (...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}


void CuongHoaWing::Option(LPOBJ lpObj, bool flag)
{
	if (!this->m_CuongHoaWing.Enabled) return;

	if (flag != 0)
	{
		return;
	}

	int CuongHoaWing = 0;


	if (this->CountItem(lpObj, 11) >= 1)
	{
		CuongHoaWing = 1;
	}

	if (this->CountItem(lpObj, 12) >= 1)
	{
		CuongHoaWing = 2;
	}

	if (this->CountItem(lpObj, 13) >= 1)
	{
		CuongHoaWing = 3;
	}

	if (this->CountItem(lpObj, 14) >= 1)
	{
		CuongHoaWing = 4;
	}

	if (this->CountItem(lpObj, 15) >= 1)
	{
		CuongHoaWing = 5;
	}

	PMSG_CUONGHOAWING_REQ pRequest;
	pRequest.Head.set(0xFB, 0xE7, sizeof(pRequest));
	pRequest.cuonghoawing = CuongHoaWing;
	pRequest.dong1 = this->m_CuongHoaWing.Damage1;
	pRequest.dong2 = this->m_CuongHoaWing.Damage2;
	pRequest.dong3 = this->m_CuongHoaWing.Damage3;
	pRequest.dong4 = this->m_CuongHoaWing.Damage4;
	pRequest.dong5 = this->m_CuongHoaWing.Damage5;

	DataSend(lpObj->Index, (LPBYTE)&pRequest, sizeof(pRequest));

	switch (CuongHoaWing)
	{
	case 1:
		lpObj->Defense += this->m_CuongHoaWing.Damage1; //Phòng Thủ
		break;
	case 2:
		lpObj->AddLife += (int)((lpObj->Life * this->m_CuongHoaWing.Damage2) / 100); //Tăng Máu
		lpObj->Defense += this->m_CuongHoaWing.Damage1; //Phòng Thủ
		break;
	case 3:
		lpObj->DefenseSuccessRatePvP += this->m_CuongHoaWing.Damage3; // Phản sát thương
		lpObj->AddLife += (int)((lpObj->Life * this->m_CuongHoaWing.Damage2) / 100); //Tăng Máu
		lpObj->Defense += this->m_CuongHoaWing.Damage1;  //Phòng Thủ
		break;
	case 4:
		lpObj->DamageReflect += this->m_CuongHoaWing.Damage4; // Phản sát thương
		lpObj->DefenseSuccessRatePvP += this->m_CuongHoaWing.Damage3; // Phản sát thương
		lpObj->AddLife += (int)((lpObj->Life * this->m_CuongHoaWing.Damage2) / 100); //Tăng Máu
		lpObj->Defense += this->m_CuongHoaWing.Damage1; //Phòng Thủ
		break;
	case 5:
		lpObj->DamageReduction[5] += this->m_CuongHoaWing.Damage5; //Giảm sát thương
		lpObj->DamageReflect += this->m_CuongHoaWing.Damage4; // Phản sát thương
		lpObj->DefenseSuccessRatePvP += this->m_CuongHoaWing.Damage3; // Khả Năng Phòng Thủ
		lpObj->AddLife += (int)((lpObj->Life * this->m_CuongHoaWing.Damage2) / 100); //Tăng Máu
		lpObj->Defense += this->m_CuongHoaWing.Damage1; //Phòng Thủ
		break;

	default:
		break;
	}
}

int CuongHoaWing::CountItem(LPOBJ lpObj, int level)
{
	int count = 0;

	CItem* Wing = &lpObj->Inventory[7];
		if (lpObj->Inventory[7].m_Index == GET_ITEM(12, 36)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 37)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 38)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 39)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 40)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 43)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 50)

		//-----------------------------------------------
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 153)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 154)
		//----------------------------------------------
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 156)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 157)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 158)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 159)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 160)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 161)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 162)
		//----------------------------------------------
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 180)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 181)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 182)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 183)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 184)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 185)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 186)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 187)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 188)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 189)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 190)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 191)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 192)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 193)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 194)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 195)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 196)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 197)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 198)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 199)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 200)

		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 200)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 201)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 202)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 203)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 204)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 205)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 206)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 207)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 208)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 209)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 210)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 211)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 212)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 213)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 214)
		|| lpObj->Inventory[7].m_Index == GET_ITEM(12, 215)


		)
	{
		if (Wing->m_Level >= level)
		{
			count++;;
		}

	}

	return count;
}
