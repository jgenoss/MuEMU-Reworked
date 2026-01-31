#include "stdafx.h"
#if(FLAG_SKIN)
#include "ThueFlag.h"
#include "MemScript.h"
#include "Util.h"
#include "ObjectManager.h"
#include "Notice.h"
#include "Viewport.h"
#include "DSProtocol.h"
#include "Message.h"
#include "ItemManager.h"
#include "CustomRankUser.h"

cThueFlag ThueFlag;

cThueFlag::cThueFlag()
{
}

cThueFlag::~cThueFlag()
{
}

void cThueFlag::Read(char* path)
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

	this->m_Data.clear();

	int type = -1;

	int sNum = 1;
	int lNum = 1;

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

					THUE_FLAG_DATA skin;

					skin.Id = this->m_Data.size();

					skin.Skin = lpMemScript->GetNumber();

					skin.Price = lpMemScript->GetAsNumber();

					skin.Value1 = lpMemScript->GetAsNumber();

					skin.Value2 = lpMemScript->GetAsNumber();

					skin.Value3 = lpMemScript->GetAsNumber();

					skin.Value4 = lpMemScript->GetAsNumber();

					skin.Value5 = lpMemScript->GetAsNumber();

					skin.Value6 = lpMemScript->GetAsNumber();

					skin.Value7 = lpMemScript->GetAsNumber();

					this->m_Data.push_back(skin);
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

void cThueFlag::CGRequestRecv(BYTE* a, int aIndex)
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return;
	}

	PMSG_THUE_FLAG_RECV* Data = (PMSG_THUE_FLAG_RECV*)a;

	switch (Data->Type)
	{
	case 0x0:
		this->GCInfoSend(Data->Value, aIndex);
		break;
	case 0x1:
		this->BuyProc(Data->Value, aIndex);
		break;
	case 0x2:
		gObjViewportListProtocolCreate(&gObj[aIndex]);
		break;
	case 0x3:
		this->SkinState(Data->Value, aIndex);
		break;
	default:
		break;
	}
}


void cThueFlag::GCInfoSend(int a, int aIndex, bool changeskin)
{
	LPOBJ lpObj = &gObj[aIndex];

	PMSG_THUE_FLAG_SEND rSend;

	rSend.h.set((LPBYTE)&rSend, 0xFB, 0x15, sizeof(rSend));

	if (!OBJECT_USER_RANGE(aIndex))
	{
		return;
	}

	rSend.Skin = lpObj->Flag;

	if (a == -1)
	{
		rSend.Data.Id = -1;
	}
	else
	{

		if (a < 0 || a >= this->m_Data.size())
		{
			rSend.Data.Id = -1;
		}
		else
		{
			THUE_FLAG_DATA* skin = &this->m_Data[a];

			rSend.Data.Id = skin->Id;
			rSend.Data.Skin = skin->Skin;
			rSend.Data.Price = skin->Price;
			rSend.Data.Value1 = skin->Value1;
			rSend.Data.Value2 = skin->Value2;
			rSend.Data.Value3 = skin->Value3;
			rSend.Data.Value4 = skin->Value4;
			rSend.Data.Value5 = skin->Value5;
			rSend.Data.Value6 = skin->Value6;
			rSend.Data.Value7 = skin->Value7;
		}
	}

	DataSend(aIndex, (LPBYTE)&rSend, sizeof(rSend));


	/*if (rSend.Data.Id != -1 && changeskin)
	{
		gViewport.GCViewportSimpleChangeSend(aIndex, rSend.Data.Skin); //làm hóa thú khi chọn mua
	}*/
}

void cThueFlag::SkinState(bool state, int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Flag == 0)
	{
		return;
	}

	THUE_FLAG_DATA* skin = this->FindSkin(abs(lpObj->Flag));

	if (skin == 0)
	{
		return;
	}
	lpObj->Flag *= -1;

	gObjViewportListProtocolCreate(lpObj);

	gObjectManager.CharacterUpdateMapEffect(lpObj);

	gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);

	this->GCInfoSend(skin->Id, aIndex);

	gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Hủy Sử Dụng Thời Trang");

}

void cThueFlag::BuyProc(int a, int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (a < 0 || a >= this->m_Data.size())
	{
		//khong co skin nay
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Thông Tin Không Hợp Lệ");
		return;
	}


	THUE_FLAG_DATA* skin = &this->m_Data[a];

	if (skin->Skin == abs(lpObj->Flag))
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đang Sở Hữu Thời Trang Này");
		return;
	}

	//if (skin->Value7 > 0 ) 
	//	{
	//		if(gItemManager.GetInventoryItemCount(lpObj,GET_ITEM(skin->Value5, skin->Value6),0) < skin->Value7)
	//			{
	//			gNotice.GCNoticeSend(lpObj->Index,1,0,0,0,0,0, gMessage.GetMessage(877),skin->Value7,gItemManager.GetItemName(GET_ITEM(skin->Value5, skin->Value6)));
	//			return;
	//			}
	//
	//			gItemManager.DeleteInventoryItemCount(lpObj,GET_ITEM(skin->Value5, skin->Value6),0,skin->Value7);
	//	}
	//

	if (lpObj->Coin1 < skin->Price) //check tien te skin->Price;
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Không Đủ Tiền");
		return;
	}

	GDSetCoinSend(lpObj->Index, -skin->Price, 0, 0, "Skin");

	lpObj->Flag = skin->Skin;

	gObjViewportListProtocolCreate(lpObj);

	gObjectManager.CharacterUpdateMapEffect(lpObj);

	gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);

	gObjectManager.CharacterCalcAttribute(aIndex);

	this->GCInfoSend(skin->Id, aIndex);

	gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Mua Thời Trang Thành Công");
}

THUE_FLAG_DATA* cThueFlag::FindSkin(int id)
{
	for (int i = 0; i < this->m_Data.size(); i++)
	{
		if (this->m_Data[i].Skin == id)
		{
			return &this->m_Data[i];
		}
	}
	return 0;
}

void cThueFlag::OnLogin(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (!OBJECT_USER_RANGE(aIndex))
	{
		return;
	}

	THUE_FLAG_DATA* data = this->FindSkin(abs(lpObj->Flag));
	if (data != 0)
	{
		gObjViewportListProtocolCreate(lpObj);

		gObjectManager.CharacterUpdateMapEffect(lpObj);
		return;
	}
}

void cThueFlag::CharacterCalc(int aIndex, bool flag)
{

	if (flag != 0)
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (!OBJECT_USER_RANGE(aIndex))
	{
		return;
	}

	THUE_FLAG_DATA* data = this->FindSkin(abs(lpObj->Flag));
	if (data == 0)
	{
		return;
	}

	THUE_FLAG_DATA* skin = &this->m_Data[aIndex];

	for (std::vector<THUE_FLAG_DATA>::iterator it = ThueFlag.m_Data.begin(); it != ThueFlag.m_Data.end(); it++)
	{

		if (it->Skin == abs(lpObj->Flag))
		{
			lpObj->PhysiDamageMinLeft += it->Value1;
			lpObj->PhysiDamageMinRight += it->Value1;
			lpObj->PhysiDamageMaxLeft += it->Value1;
			lpObj->PhysiDamageMaxRight += it->Value1;
			lpObj->PhysiDamageMin += it->Value1;
			lpObj->PhysiDamageMax += it->Value1;
			// Phòng Thủ
			lpObj->Defense += it->Value2;
			// THỂ LỰC
			lpObj->AddLife += it->Value3;
			lpObj->AddMana += it->Value4;
		}


	}

}


//void cRentSkin::CharacterCalc(int aIndex,bool flag)
//{
//
//	if (flag != 0)
//	{
//		return;
//	}
//
//	LPOBJ lpObj = &gObj[aIndex];
//
//	if (!OBJECT_USER_RANGE(aIndex))
//	{
//		return;
//	}
//
//	RENT_SKIN_DATA* it = this->FindSkin(abs(lpObj->RentSkin));
//	if (it == 0)
//	{
//		return;
//	}
//
//	for (std::vector<RENT_SKIN_DATA>::iterator it = RentSkin.m_Data.begin(); it != RentSkin.m_Data.end(); it++)
//	{
//		if (lpObj->RentSkin = it->Skin)
//		{
//
//		lpObj->PhysiDamageMinLeft += lpObj->PhysiDamageMinLeft * it->Value1 / 100;
//		lpObj->PhysiDamageMinRight += lpObj->PhysiDamageMinRight *it->Value1 / 100;
//		lpObj->PhysiDamageMaxLeft += lpObj->PhysiDamageMaxLeft *it->Value1 / 100;
//		lpObj->PhysiDamageMaxRight += lpObj->PhysiDamageMaxRight *it->Value1 / 100;
//		lpObj->PhysiDamageMin += lpObj->PhysiDamageMin *it->Value1 / 100;
//		lpObj->PhysiDamageMax += lpObj->PhysiDamageMax *it->Value1 / 100;
//		// Phòng Thủ
//		lpObj->Defense += it->Value2;
//		// THỂ LỰC
//		lpObj->AddLife += it->Value3;
//		lpObj->AddMana += it->Value4;
//		}
//	}		
//}

#endif