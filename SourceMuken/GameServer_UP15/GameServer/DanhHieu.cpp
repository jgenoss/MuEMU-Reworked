#include "StdAfx.h"
#include "user.h"
#include "DanhHieu.h"
#include "DSProtocol.h"
#include "GameMain.h"
#include "Path.h"
#include "MemScript.h"
#include "Util.h"
#include "CashShop.h"
#include "Message.h"
#include "Notice.h"
#include "CustomRankUser.h"
#include "ObjectManager.h"
#include "ItemManager.h"

#define MAX_DANH_HIEU    500

DanhHieu gDanhHieu;
// -------------------------------------------------------------------------------
DanhHieu::DanhHieu() // OK
{
}
// -------------------------------------------------------------------------------
DanhHieu::~DanhHieu() // OK
{
}

void DanhHieu::Init() // OK
{

	this->m_DanhHieu.gemcount = 0;
	this->m_DanhHieu.rType = 0;
	this->m_DanhHieu.rIndex = 0;

	this->m_DanhHieu.SatThuong = 0;
	this->m_DanhHieu.SatThuongX2 = 0;
	this->m_DanhHieu.PhongThu = 0;
	this->m_DanhHieu.HP = 0;
	this->m_DanhHieu.SD = 0;
	this->m_DanhHieu.GST = 0;
}

void DanhHieu::Load1(char* path) // OK
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
			m_DanhHieu.rCoin = lpMemScript->GetNumber();

			m_DanhHieu.minlv = lpMemScript->GetAsNumber();

			m_DanhHieu.maxlv = lpMemScript->GetAsNumber();

			m_DanhHieu.gemcount = lpMemScript->GetAsNumber();

			m_DanhHieu.rType = lpMemScript->GetAsNumber();

			m_DanhHieu.rIndex = lpMemScript->GetAsNumber();

			m_DanhHieu.SatThuong = lpMemScript->GetAsNumber();

			m_DanhHieu.SatThuongX2 = lpMemScript->GetAsNumber();

			m_DanhHieu.PhongThu = lpMemScript->GetAsNumber();

			m_DanhHieu.HP = lpMemScript->GetAsNumber();

			m_DanhHieu.SD = lpMemScript->GetAsNumber();

			m_DanhHieu.GST = lpMemScript->GetAsNumber();

			this->m_DanhHieuInfo.push_back(m_DanhHieu);
		}
	}
	catch (...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

int DanhHieu::GetCoint(LPOBJ lpObj) // OK
{
	for (std::vector<DANH_HIEU_INFO>::iterator it = this->m_DanhHieuInfo.begin(); it != this->m_DanhHieuInfo.end(); it++)
	{
		if ((lpObj->rDanhHieu + 1) >= it->minlv && (lpObj->rDanhHieu + 1) <= it->maxlv)
		{
			if (it->rCoin == -1)
			{
				return m_DanhHieu.rCoin;
			}
			else
			{
				return it->rCoin;
			}
		}
	}
	return 0;
}

int DanhHieu::GetMaxLv(LPOBJ lpObj) // OK
{
	for (std::vector<DANH_HIEU_INFO>::iterator it = this->m_DanhHieuInfo.begin(); it != this->m_DanhHieuInfo.end(); it++)
	{
		if ((lpObj->rDanhHieu + 1) >= it->minlv && (lpObj->rDanhHieu + 1) <= it->maxlv)
		{
			if (it->maxlv == -1)
			{
				return m_DanhHieu.maxlv;
			}
			else
			{
				return it->maxlv;
			}
		}
	}
	return 0;
}

int DanhHieu::GetCount(LPOBJ lpObj) // OK
{
	for (std::vector<DANH_HIEU_INFO>::iterator it = this->m_DanhHieuInfo.begin(); it != this->m_DanhHieuInfo.end(); it++)
	{
		if ((lpObj->rDanhHieu + 1) >= it->minlv && (lpObj->rDanhHieu + 1) <= it->maxlv)
		{
			if (it->gemcount == -1)
			{
				return m_DanhHieu.gemcount;
			}
			else
			{
				return it->gemcount;
			}
		}
	}
	return 0;
}

int DanhHieu::GetType(LPOBJ lpObj) // OK
{
	for (std::vector<DANH_HIEU_INFO>::iterator it = this->m_DanhHieuInfo.begin(); it != this->m_DanhHieuInfo.end(); it++)
	{
		if ((lpObj->rDanhHieu + 1) >= it->minlv && (lpObj->rDanhHieu + 1) <= it->maxlv)
		{
			if (it->rType == -1)
			{
				return m_DanhHieu.rType;
			}
			else
			{
				return it->rType;
			}
		}
	}
	return 0;
}
int DanhHieu::GetIndex(LPOBJ lpObj) // OK
{
	for (std::vector<DANH_HIEU_INFO>::iterator it = this->m_DanhHieuInfo.begin(); it != this->m_DanhHieuInfo.end(); it++)
	{

		if ((lpObj->rDanhHieu + 1) >= it->minlv && (lpObj->rDanhHieu + 1) <= it->maxlv)
		{
			if (it->rIndex == -1)
			{
				return m_DanhHieu.rIndex;
			}
			else
			{
				return it->rIndex;
			}
		}
	}
	return 0;
}

int DanhHieu::SatThuong(LPOBJ lpObj) // OK
{
	for (std::vector<DANH_HIEU_INFO>::iterator it = this->m_DanhHieuInfo.begin(); it != this->m_DanhHieuInfo.end(); it++)
	{

		if ((lpObj->rDanhHieu + 1) >= it->minlv && (lpObj->rDanhHieu + 1) <= it->maxlv)
		{
			if (it->SatThuong == -1)
			{
				return m_DanhHieu.SatThuong;
			}
			else
			{
				return it->SatThuong;
			}
		}
	}
	return 0;
}

int DanhHieu::SatThuongX2(LPOBJ lpObj) // OK
{
	for (std::vector<DANH_HIEU_INFO>::iterator it = this->m_DanhHieuInfo.begin(); it != this->m_DanhHieuInfo.end(); it++)
	{

		if ((lpObj->rDanhHieu + 1) >= it->minlv && (lpObj->rDanhHieu + 1) <= it->maxlv)
		{
			if (it->SatThuongX2 == -1)
			{
				return m_DanhHieu.SatThuongX2;
			}
			else
			{
				return it->SatThuongX2;
			}
		}
	}
	return 0;
}
int DanhHieu::PhongThu(LPOBJ lpObj) // OK
{
	for (std::vector<DANH_HIEU_INFO>::iterator it = this->m_DanhHieuInfo.begin(); it != this->m_DanhHieuInfo.end(); it++)
	{


		if ((lpObj->rDanhHieu + 1) >= it->minlv && (lpObj->rDanhHieu + 1) <= it->maxlv)
		{
			if (it->PhongThu == -1)
			{
				return m_DanhHieu.PhongThu;
			}
			else
			{
				return it->PhongThu;
			}
		}
	}
	return 0;
}

int DanhHieu::HP(LPOBJ lpObj) // OK
{
	for (std::vector<DANH_HIEU_INFO>::iterator it = this->m_DanhHieuInfo.begin(); it != this->m_DanhHieuInfo.end(); it++)
	{
		if ((lpObj->rDanhHieu + 1) >= it->minlv && (lpObj->rDanhHieu + 1) <= it->maxlv)
		{
			if (it->HP == -1)
			{
				return m_DanhHieu.HP;
			}
			else
			{
				return it->HP;
			}
		}
	}
	return 0;
}

int DanhHieu::GST(LPOBJ lpObj) // OK
{
	for (std::vector<DANH_HIEU_INFO>::iterator it = this->m_DanhHieuInfo.begin(); it != this->m_DanhHieuInfo.end(); it++)
	{
		if ((lpObj->rDanhHieu + 1) >= it->minlv && (lpObj->rDanhHieu + 1) <= it->maxlv)
		{
			if (it->GST == -1)
			{
				return m_DanhHieu.GST;
			}
			else
			{
				return it->GST;
			}
		}
	}
	return 0;
}

int DanhHieu::SD(LPOBJ lpObj) // OK
{
	for (std::vector<DANH_HIEU_INFO>::iterator it = this->m_DanhHieuInfo.begin(); it != this->m_DanhHieuInfo.end(); it++)
	{
		if ((lpObj->rDanhHieu + 1) >= it->minlv && (lpObj->rDanhHieu + 1) <= it->maxlv)
		{
			if (it->SD == -1)
			{
				return m_DanhHieu.SD;
			}
			else
			{
				return it->SD;
			}
		}
	}
	return 0;
}



// -------------------------------------------------------------------------------
void DanhHieu::DANH_HIEU_OPTION(LPOBJ lpObj, bool flag)
{
	if (flag != 0)
	{
		return;
	}
	//-----
	if (lpObj->rDanhHieu > 0)
	{
		// Sát Thương	
		lpObj->PhysiDamageMinLeft += lpObj->PhysiDamageMinLeft * lpObj->DHSatThuong / 100;
		lpObj->PhysiDamageMinRight += lpObj->PhysiDamageMinRight * lpObj->DHSatThuong / 100;
		lpObj->PhysiDamageMaxLeft += lpObj->PhysiDamageMaxLeft * lpObj->DHSatThuong / 100;
		lpObj->PhysiDamageMaxRight += lpObj->PhysiDamageMaxRight * lpObj->DHSatThuong / 100;
		lpObj->PhysiDamageMin += lpObj->PhysiDamageMin * lpObj->DHSatThuong / 100;
		lpObj->PhysiDamageMax += lpObj->PhysiDamageMax * lpObj->DHSatThuong / 100;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += lpObj->DHSatThuongX2;
		// Phòng Thủ
		lpObj->Defense += lpObj->DHPhongThu;
		// THỂ LỰC
		lpObj->AddLife += lpObj->DHHP;
		// SD
		lpObj->AddShield += lpObj->DHSD;
		//GST
		lpObj->DamageReduction[5] += lpObj->DHGST;
	}

}
// -------------------------------------------------------------------------------


void DanhHieu::Load()
{
	GetPrivateProfileString("MESSAGES", "Msg01", "Ban can %d nguyen lieu", this->TitleCheck, sizeof(this->TitleCheck), gPath.GetFullPath("Custom\\DanhHieu\\Messages.ini"));
	GetPrivateProfileString("MESSAGES", "Msg02", "Ban can %d nguyen lieu", this->TitleCheck1, sizeof(this->TitleCheck1), gPath.GetFullPath("Custom\\DanhHieu\\Messages.ini"));
	GetPrivateProfileString("MESSAGES", "Msg03", "Ban can %d nguyen lieu", this->TitleCheck2, sizeof(this->TitleCheck2), gPath.GetFullPath("Custom\\DanhHieu\\Messages.ini"));
	GetPrivateProfileString("MESSAGES", "Msg04", "Ban can %d nguyen lieu", this->TitleCheck3, sizeof(this->TitleCheck3), gPath.GetFullPath("Custom\\DanhHieu\\Messages.ini"));

}
// -------------------------------------------------------------------------------
void DanhHieu::BUY_DANH_HIEU(LPOBJ lpObj, BUY_DANH_HIEU_REQ* aRecv)
{
	if (aRecv->Number == 1)
	{
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
		if ((GetTickCount() - lpObj->ClickClientSend) < 500)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(59));
			return;
		}
		//---------------------------------------------------------
		if (true)
		{
			if (lpObj->rDanhHieu > MAX_DANH_HIEU)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã đạt cấp độ tối đa");
				return;
			}

			int gemc = gItemManager.GetInventoryItemCount(lpObj, GET_ITEM(GetType(lpObj), GetIndex(lpObj)), 0);


			if (gemc < GetCount(lpObj))
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, TitleCheck, GetCount(lpObj));

				return;
			}

			if (lpObj->Coin1 < GetCoint(lpObj))
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Không đủ %d WcoinC để nâng cấp!!!", GetCoint(lpObj));
				return;
			}
			else
			{
				lpObj->Coin1 -= GetCoint(lpObj);
			}

			GDSetCoinSend(lpObj->Index, -GetCoint(lpObj), 0, 0, "Danh Hieu");
			gItemManager.DeleteInventoryItemCount(lpObj, GET_ITEM(GetType(lpObj), GetIndex(lpObj)), 0, GetCount(lpObj));
			lpObj->rDanhHieu++; // Thay Đổi
			lpObj->DHSatThuong += SatThuong(lpObj);
			lpObj->DHSatThuongX2 += SatThuongX2(lpObj);
			lpObj->DHPhongThu += PhongThu(lpObj);
			lpObj->DHHP += HP(lpObj);
			lpObj->DHSD += SD(lpObj);
			lpObj->DHGST += GST(lpObj);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);

		}
		RegDataSend(lpObj->Index);
		//Set Delay
		lpObj->ClickClientSend = GetTickCount();
	}

	if (aRecv->Number == 2)
	{
		RegDataSend(lpObj->Index);
	}

}

struct DANHHIEU_UPDATE
{
	PBMSG_HEAD3 h;

	int rCoint;

	int rCount;
	int rType;
	int rIndex;

	int SatThuong;
	int SatThuongX2;
	int PhongThu;
	int HP;
	int SD;
	int GST;
	//4-04-2022
	int DANH_HIEU;
};

void RegDataSend(int aIndex)
{
	DANHHIEU_UPDATE rSend;
	LPOBJ lpObj = &gObj[aIndex];
	rSend.h.set((LPBYTE)&rSend, 0xF3, 15, sizeof(rSend));

	rSend.rCoint = gDanhHieu.GetCoint(lpObj);

	rSend.rCount = gDanhHieu.GetCount(lpObj);
	rSend.rType = gDanhHieu.GetType(lpObj);
	rSend.rIndex = gDanhHieu.GetIndex(lpObj);

	rSend.SatThuong = gDanhHieu.SatThuong(lpObj);
	rSend.SatThuongX2 = gDanhHieu.SatThuongX2(lpObj);
	rSend.PhongThu = gDanhHieu.PhongThu(lpObj);
	rSend.HP = gDanhHieu.HP(lpObj);
	rSend.SD = gDanhHieu.SD(lpObj);
	rSend.GST = gDanhHieu.GST(lpObj);

	rSend.DANH_HIEU = lpObj->rDanhHieu;

	DataSend(aIndex, (LPBYTE)&rSend, sizeof(rSend));
}
