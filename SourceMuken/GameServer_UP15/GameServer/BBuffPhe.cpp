#include "stdafx.h"
#include "BBuffPhe.h"
#include "DSProtocol.h"
#include "EffectManager.h"
#include "Map.h"
#include "MemScript.h"
#include "Notice.h"
#include "Util.h"
#include "ItemOptionRate.h"
#include "ObjectManager.h"
#include "CashShop.h"
#include "DSProtocol.h"
#include "GameMain.h"
#include "Monster.h"
#include "Guild.h"
#include "GuildClass.h"
#include "ESProtocol.h"
#include "CustomRankUser.h"

CBBuffPhe gBBuffPhe;

CBBuffPhe::CBBuffPhe()
{
	this->InitData();
}

CBBuffPhe::~CBBuffPhe()
{

}

void CBBuffPhe::InitData()
{
	this->mDBMonterPoint.clear();
	this->mDataConfigCuongHoa.clear();
	this->mDataConfigBuffPhe.clear();
	this->DelayGetTop = 0;
	this->TuongMap = 0;
	for (int n = 0; n < 2; n++)
	{
		this->TuongX[n] = 0;
		this->TuongY[n] = 0;
		this->TuongDir[n] = 0;
		this->CacheIndex[n] = -1;
	}
	//===
	this->DT_TongPoint = 0;
	this->DT_Top1Point = 0;
	this->DT_CapDo = 0;
	memset(&this->DT_Top1Name, 0, sizeof(this->DT_Top1Name));
	//===
	this->BT_TongPoint = 0;
	this->BT_Top1Point = 0;
	this->BT_CapDo = 0;
	memset(&this->BT_Top1Name, 0, sizeof(this->BT_Top1Name));
	this->CacheTimeGetTop = GetTickCount()+10000;
}

void TestSaveXML()
{
	pugi::xml_document doc;

	auto declarationNode = doc.append_child(pugi::node_declaration);
	declarationNode.append_attribute("version") = "1.0";
	declarationNode.append_attribute("encoding") = "UTF-8";

	pugi::xml_node DBSuKienChienPhe = doc.append_child("DBSuKienChienPhe");
	DBSuKienChienPhe.append_attribute("Note") = "Đây là File lưu dữ liệu Sự Kiện , sẽ tự thay đổi mỗi khi kết thúc Sự Kiện !";

	pugi::xml_node DBTeamWin = DBSuKienChienPhe.append_child("DBTeamWin");
	DBTeamWin.append_attribute("PheWin") = "1";
	DBTeamWin.append_attribute("GPheWin") = "AAAAAAAAA";

	doc.save_file("EmployeeDetails.xml");
}

void CBBuffPhe::LoadFileXML(char* FilePath)
{
	for (int n = 0; n < 2; n++)
	{
		if (gObjIsConnected(this->CacheIndex[n]) == 1)
		{
			gObjDel(this->CacheIndex[n]);
		}
	
	}
	this->InitData();
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(FilePath);
	if (res.status != pugi::status_ok) {
		ErrorMessageBox("File %s load fail. Error: %s", FilePath, res.description());
		return;
	}
	//--

	pugi::xml_node oMonterSetPoint = file.child("MonterSetPoint");
	for (pugi::xml_node Monter = oMonterSetPoint.child("Monter"); Monter; Monter = Monter.next_sibling())
	{

		LISTMONTER_POINT infoMonter;
		infoMonter.MonterClass = Monter.attribute("MonterClass").as_int();
		infoMonter.Map = Monter.attribute("Map").as_int();
		infoMonter.Point = Monter.attribute("Point").as_int();
		this->mDBMonterPoint.push_back(infoMonter);
	}
	//==BuffPheData
	pugi::xml_node oBuffPheData = file.child("BuffPheData");

	this->DelayGetTop	=		oBuffPheData.attribute("DelayGetTop").as_int();
	this->TuongMap =		oBuffPheData.attribute("Map").as_int();
	//===Dao Tac
	this->TuongX[0] =		oBuffPheData.attribute("DT_X").as_int();
	this->TuongY[0] =		oBuffPheData.attribute("DT_Y").as_int();
	this->TuongDir[0] =		oBuffPheData.attribute("DT_Dir").as_int();
	//===Bao TIeu
	this->TuongX[1] = oBuffPheData.attribute("BT_X").as_int();
	this->TuongY[1] = oBuffPheData.attribute("BT_Y").as_int();
	this->TuongDir[1] = oBuffPheData.attribute("BT_Dir").as_int();

	for (pugi::xml_node CapDo = oBuffPheData.child("CapDo"); CapDo; CapDo = CapDo.next_sibling())
	{
		CONFIDATA_BUFFPHE infoDBBuffPhe;
		infoDBBuffPhe.TongPoint = CapDo.attribute("TongPoint").as_int();
		infoDBBuffPhe.CapDoPhe = CapDo.attribute("CapDoPhe").as_int();
		this->mDataConfigBuffPhe.insert(std::pair<int, CONFIDATA_BUFFPHE>(infoDBBuffPhe.CapDoPhe, infoDBBuffPhe));
	}

	//==CuongHoa DB
	pugi::xml_node CuongHoaBanThan = file.child("CuongHoaBanThan");
	for (pugi::xml_node CapDoCH = CuongHoaBanThan.child("CapDo"); CapDoCH; CapDoCH = CapDoCH.next_sibling())
	{
		CONFIDATA_CUONGHOA infoDBCH;
		infoDBCH.LvCuongHoa = CapDoCH.attribute("LvCuongHoa").as_int();
		infoDBCH.CongHienYC = CapDoCH.attribute("CongHienYC").as_int();
		infoDBCH.TangMau = CapDoCH.attribute("TangMau").as_int();
		infoDBCH.TangSD = CapDoCH.attribute("TangSD").as_int();
		infoDBCH.TangST = CapDoCH.attribute("TangST").as_int();
		infoDBCH.TangPT = CapDoCH.attribute("TangPT").as_int();
		this->mDataConfigCuongHoa.insert(std::pair<int, CONFIDATA_CUONGHOA>(infoDBCH.LvCuongHoa, infoDBCH));
	}

	LogAdd(LOG_BLUE, "[BuffPhe] Monter Point %d", this->mDBMonterPoint.size());

}
bool CBBuffPhe::CongHienBuffPhe(int aIndex, int Point) // OK
{

	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}
	if (gObjIsConnected(aIndex) == false)
	{
		return 0;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (Point > lpObj->Ruud) //Ko Du Diem De Nop Cong Hien
	{
		return 0;
	}

	this->CongTruRuud(lpObj, Point, 1);

	//====
	lpObj->PointUsePhe += Point;
	lpObj->LvCuongHoaHienTai = (int)this->GetCapCHInPoint(lpObj->PointUsePhe);
	

	if (lpObj->ChonPheHanhTau == 1)
	{
		this->DT_TongPoint += Point;
		this->DT_CapDo = this->GetCapDoPhe(this->DT_TongPoint);
	}
	else if (lpObj->ChonPheHanhTau == 2)
	{
		this->BT_TongPoint += Point;
		this->BT_CapDo = this->GetCapDoPhe(this->BT_TongPoint);
	}
	gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
	gObjectManager.CharacterCalcAttribute(lpObj->Index);
	this->SendInfoClient(lpObj->Index);
	return 1;
}
void CBBuffPhe::GetOptionCuongHoa(LPOBJ lpObj, bool flag)
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

	if (OBJECT_RANGE(lpObj->Index) == 0)
	{
		return;
	}
	if (gObjIsConnected(lpObj->Index) == false)
	{
		return;
	}
	CONFIDATA_CUONGHOA* BGetDataCH = this->GetInfoCuongHoaInCapDo(lpObj->LvCuongHoaHienTai);
	if (BGetDataCH == 0)
	{
		return;
	}
	// Sat Thuong
	lpObj->MagicDamageMin += BGetDataCH->TangST;
	lpObj->MagicDamageMax += BGetDataCH->TangST;
	lpObj->PhysiDamageMinLeft += BGetDataCH->TangST;
	lpObj->PhysiDamageMinRight += BGetDataCH->TangST;
	lpObj->PhysiDamageMaxLeft += BGetDataCH->TangST;
	lpObj->PhysiDamageMaxRight += BGetDataCH->TangST;
	// PT
	lpObj->Defense += BGetDataCH->TangPT;
	// MAU
	lpObj->AddLife += BGetDataCH->TangMau;
	// SD
	lpObj->AddShield += BGetDataCH->TangSD;
}
void CBBuffPhe::SendInfoClient(int aIndex) // OK
{

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

	BUFFPHE_DATASEND pMsg;

	pMsg.header.set(0xD3, 0x05, 0);

	int size = sizeof(pMsg);

	//=========================================
	pMsg.mDT_Top1Point = this->DT_Top1Point;
	pMsg.mDT_TongPoint = this->DT_TongPoint;
	pMsg.mDT_CapDo = this->GetCapDoPhe(this->DT_TongPoint);
	pMsg.mDT_PointNext = this->GetPointInCapDo(this->DT_CapDo +1);
	memcpy(&pMsg.mDT_Top1Name, this->DT_Top1Name, sizeof(pMsg.mDT_Top1Name));
	//===
	pMsg.mBT_Top1Point = this->BT_Top1Point;
	pMsg.mBT_TongPoint = this->BT_TongPoint;
	pMsg.mBT_CapDo = this->GetCapDoPhe(this->BT_TongPoint);
	pMsg.mBT_PointNext = this->GetPointInCapDo(this->BT_CapDo + 1);
	memcpy(&pMsg.mBT_Top1Name, this->BT_Top1Name, sizeof(pMsg.mBT_Top1Name));


	pMsg.Count = 0;
	//== Data CH Ca Nhan
	lpObj->LvCuongHoaHienTai = (int)this->GetCapCHInPoint(lpObj->PointUsePhe);
	pMsg.mLvCuongHoaHienTai = lpObj->LvCuongHoaHienTai;
	pMsg.mPointUsePhe = lpObj->PointUsePhe;
	//LogAdd(LOG_RED, "GET INFO %d Point %d", lpObj->LvCuongHoaHienTai, lpObj->PointUsePhe);
	for (int i = 0; i < this->mDataConfigCuongHoa.size(); i++)
	{
		if (size + sizeof(this->mDataConfigCuongHoa[i]) > 4096)
		{
			LogAdd(LOG_RED, "(%s %d) Data qua dai !!", __FILE__, __LINE__);
			return;
		}
		memcpy(&send[size], &this->mDataConfigCuongHoa[i], sizeof(this->mDataConfigCuongHoa[i]));
		size += sizeof(this->mDataConfigCuongHoa[i]);

		pMsg.Count++;
	}


	pMsg.header.size[0] = SET_NUMBERHB(size);

	pMsg.header.size[1] = SET_NUMBERLB(size);

	memcpy(send, &pMsg, sizeof(pMsg));
	DataSend(aIndex, send, size);
}
void CBBuffPhe::MainProc()
{
	if ((GetTickCount() > this->CacheTimeGetTop))
	{
		this->CacheTimeGetTop = GetTickCount() + ((this->DelayGetTop * 60) * 1000);
		//==Send DS Get Danh Sach Skin Da Mua
		BUFFPHE_REQUESTDS pMsg;

		pMsg.header.set(0xD9, 0x18, sizeof(pMsg));
		pMsg.aIndex = 0;
		gDataServerConnection.DataSend((BYTE*)& pMsg, pMsg.header.size);
		//LogAdd(LOG_RED, "SEnd DS Lay Data Buff Phe");

	}
}

void CBBuffPhe::RecvCharInfoAddBot(INFOCHAR_BUFFPHE* lpMsg)
{
	if (lpMsg->result)
	{
		int Phe = (lpMsg->ChonPheHanhTau-1);

		if (gObjIsConnected(this->CacheIndex[Phe]) == 1)
		{
			gObjDel(this->CacheIndex[Phe]);
		}

		this->CacheIndex[Phe] = gObjAddSummon();

		int result = this->CacheIndex[Phe];

		//LogAdd(LOG_RED, "RecvCharInfoAddBot %d %d Phe %d", lpMsg->result, result, lpMsg->ChonPheHanhTau);

		gObjCharZeroSet(result);
		gObj[result].PosNum = (WORD)-1;
		gObj[result].X = this->TuongX[Phe];
		gObj[result].Y = this->TuongY[Phe];
		gObj[result].OldX = this->TuongX[Phe];
		gObj[result].OldY = this->TuongY[Phe];
		gObj[result].TX = this->TuongX[Phe];
		gObj[result].TY = this->TuongY[Phe];
		gObj[result].MTX = this->TuongX[Phe];
		gObj[result].MTY = this->TuongY[Phe];
		gObj[result].Dir = this->TuongDir[Phe];
		gObj[result].Map = this->TuongMap;
		gObj[result].Live = 1;
		gObj[result].PathCount = 0;
		gObj[result].IsBot = 0xA;
		gObj[result].BotPower = 0;
		gObj[result].ChonPheHanhTau = lpMsg->ChonPheHanhTau;
		gObj[result].PointUsePhe = lpMsg->PointUsePhe;
		gObjSetBots(result, lpMsg->Class);

		gObj[result].ChangeUp = lpMsg->Class;
		gObj[result].Class = lpMsg->Class;
		gObj[result].Level = lpMsg->Level;
		gObj[result].Life = 1;
		gObj[result].MaxLife = 2;
		gObj[result].Mana = 1;
		gObj[result].MaxMana = 2;
		gObj[result].Experience = 0;
		gObj[result].DBClass = lpMsg->Class;
		gObj[result].Class = lpMsg->Class / 16;
		gObj[result].ChangeUp = lpMsg->Class % 16;
		gObj[result].GuildNumber = 0;
		gObj[result].Guild = 0;
		gObj[result].GuildStatus = -1;
		gObj[result].GuildUnionTimeStamp = 0;
		memset(gObj[result].GuildName, 0, sizeof(gObj[result].GuildName));
		gObj[result].Authority = 1;
		if (strlen(lpMsg->GuildName) > 1)
		{
			//LogAdd(LOG_RED,"[BotGetInfoSet] 2Set Guild (%s)",lpMsg->GuildName);
			memcpy(gObj[result].GuildName, lpMsg->GuildName, 9); //MAX_GUILD_NAME define
			gObj[result].Guild = gGuildClass.SearchGuild(gObj[result].GuildName);
			gObj[result].GuildNumber = lpMsg->GuildNumber;
			gObj[result].GuildStatus = lpMsg->GuildStatus;

			DGGuildMemberInfoRequest(result);

		}


		gObj[result].Inventory = new CItem[INVENTORY_SIZE];
		gObj[result].Inventory1 = new CItem[INVENTORY_SIZE];
		gObj[result].InventoryMap1 = new BYTE[INVENTORY_SIZE];
		gObj[result].InventoryMap = new BYTE[INVENTORY_SIZE];


		for (int i = 0; i < INVENTORY_SIZE; i++)
		{
			gObj[result].Inventory[i].Clear();
			gObj[result].Inventory1[i].Clear();
		}

		memset(&gObj[result].InventoryMap[0], (BYTE)-1, INVENTORY_SIZE);
		memset(&gObj[result].InventoryMap1[0], (BYTE)-1, INVENTORY_SIZE);



		//char szTEMP[11] = {0};
		memset(&gObj[result].Name, 0, sizeof(gObj[result].Name));
		wsprintf(gObj[result].Name," %s",lpMsg->name);
		//strcpy_s(gObj[result].Name, lpMsg->name);

		for (int n = 0; n < INVENTORY_SIZE; n++)
		{
			CItem item;

			gObj[result].Inventory[n].Clear();

			if (gItemManager.ConvertItemByte(&item, lpMsg->Inventory[n]) == 0)
			{
				continue;
			}

			gItemManager.InventoryAddItem(result, item, n);
		}

		for (int n = 0; n < MAX_EFFECT_LIST; n++)
		{
			CEffect effect;

			gObj[result].Effect[n].Clear();

			if (gEffectManager.ConvertEffectByte(&effect, lpMsg->Effect[n]) == 0)
			{
				continue;
			}

			gEffectManager.AddEffect(&gObj[result], 1, effect.m_index, effect.m_count, effect.m_value[0], effect.m_value[1], effect.m_value[2], effect.m_value[3]);
		}

		gObj[result].Inventory1 = gObj[result].Inventory;
		gObj[result].InventoryMap1 = gObj[result].InventoryMap;
		gObjectManager.CharacterMakePreviewCharSet(result);

		gObj[result].AttackType = 0;
		gObj[result].BotSkillAttack = 0;

		gObj[result].Attribute = 100;
		gObj[result].TargetNumber = (WORD)-1;
		gObj[result].ActionState.Emotion = 0;
		gObj[result].ActionState.Attack = 0;
		gObj[result].ActionState.EmotionCount = 0;
		gObj[result].PathCount = 0;
		gObj[result].BotPower = 0;
		gObj[result].BotDefense = 0;
		gObj[result].BotLife = 1;
		gObj[result].BotMaxLife = 1;

		gObj[result].BotLvlUpDefense = 1;
		gObj[result].BotLvlUpPower = 1;
		gObj[result].BotLvlUpLife = 1;
		gObj[result].BotLvlUpMana = 1;
		gObj[result].BotLvlUpExp = 1;
		gObj[result].BotLvlUpMaxLevel = 1;

		gObj[result].MoveRange = 1;
		gObj[result].BotFollowMe = 0;
		gObj[result].NextExperience = gLevelExperience[gObj[result].Level];


		GCSummonLifeSend(gObj[result].SummonIndex, (int)gObj[result].MaxLife, (int)gObj[result].Life);

		GCActionSend(&gObj[result], ACTION_SALUTE1, result, result);
		gCustomRankUser.GCReqRankLevelUser(result, result);

	}
}
void CBBuffPhe::GetInfoCharTop(int Type)
{
	BUFFPHE_REQUESTDS pMsg;
	pMsg.header.set(0xD9, 0x19, sizeof(pMsg));
	if (Type == 1)
	{
		pMsg.aIndex = this->CacheIndex[0];
		memcpy(&pMsg.Name, this->DT_Top1Name, sizeof(pMsg.Name));
	}
	else {
		pMsg.aIndex = this->CacheIndex[1];
		memcpy(&pMsg.Name, this->BT_Top1Name, sizeof(pMsg.Name));
	}
	gDataServerConnection.DataSend((BYTE*)& pMsg, pMsg.header.size);
}
void CBBuffPhe::CacheDataBuffPhe(BUFFPHE_REQUESTDS_SETINFO* lpMsg) // OK
{
	//===
	this->DT_TongPoint = 0;
	this->DT_Top1Point = 0;
	this->DT_CapDo = 0;
	memset(&this->DT_Top1Name, 0, sizeof(this->DT_Top1Name));
	//===
	this->BT_TongPoint = 0;
	this->BT_Top1Point = 0;
	this->BT_CapDo = 0;
	memset(&this->BT_Top1Name, 0, sizeof(this->BT_Top1Name));
	//=========================================
	this->DT_TongPoint = lpMsg->mDT_TongPoint;
	this->DT_Top1Point = lpMsg->mDT_Top1Point;
	this->DT_CapDo = this->GetCapDoPhe(this->DT_TongPoint);
	memcpy(&this->DT_Top1Name, lpMsg->mDT_Top1Name, sizeof(this->DT_Top1Name));
	//===
	this->BT_TongPoint = lpMsg->mBT_TongPoint;
	this->BT_Top1Point = lpMsg->mBT_Top1Point;
	this->BT_CapDo = this->GetCapDoPhe(this->BT_TongPoint);
	memcpy(&this->BT_Top1Name, lpMsg->mBT_Top1Name, sizeof(this->BT_Top1Name));

	this->GetInfoCharTop(1);
	this->GetInfoCharTop(2);

	//LogAdd(LOG_RED, "DT (%d) [%s - %d] (%d) - BT (%d) [%s - %d] (%d)",
	//	this->DT_TongPoint, this->DT_Top1Name, lpMsg->mDT_Top1Point, this->DT_CapDo,
	//	this->BT_TongPoint, this->BT_Top1Name, lpMsg->mBT_Top1Point, this->BT_CapDo);

}
int CBBuffPhe::GetCapDoPhe(int TongPoint)
{
	int CapDoGet = 0;
	for (std::map<int, CONFIDATA_BUFFPHE>::iterator it = this->mDataConfigBuffPhe.begin(); it != this->mDataConfigBuffPhe.end(); it++)
	{
		if (TongPoint >= it->second.TongPoint)
		{
			CapDoGet = it->second.CapDoPhe;
		}
	}
	return CapDoGet;
}

int CBBuffPhe::GetPointInCapDo(int CapDo)
{
	std::map<int, CONFIDATA_BUFFPHE>::iterator it = this->mDataConfigBuffPhe.find(CapDo);

	if (it == this->mDataConfigBuffPhe.end())
	{
		return -1;
	}
	else
	{
		return it->second.TongPoint;
	}
	return 0;
}
//====
int CBBuffPhe::GetCapCHInPoint(int Point)
{
	int CapDoCH = 0;
	for (std::map<int, CONFIDATA_CUONGHOA>::iterator it = this->mDataConfigCuongHoa.begin(); it != this->mDataConfigCuongHoa.end(); it++)
	{
		if (Point >= it->second.CongHienYC)
		{
			CapDoCH = it->second.LvCuongHoa;
		}
	}
	return CapDoCH;
}
CONFIDATA_CUONGHOA* CBBuffPhe::GetInfoCuongHoaInCapDo(int CapDoCuongHoa)
{
	std::map<int, CONFIDATA_CUONGHOA>::iterator it = this->mDataConfigCuongHoa.find(CapDoCuongHoa);

	if (it == this->mDataConfigCuongHoa.end())
	{
		return 0;
	}
	else
	{
		return &it->second;
	}

}


void CBBuffPhe::CongTruRuud(LPOBJ lpObj,int Point, int TruCoin)
{
	//=== COng 
	if (TruCoin == 1)
	{
		gCashShop.GDCashShopSubPointSaveSend(lpObj->Index, 0, 0, 0, 0, Point);
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "[Ruud] -%d Point", Point);
	}
	else 
	{
		if ((lpObj->Ruud + Point) > 2000000000) 
		{
			return;
		}
		gCashShop.GDCashShopAddPointSaveSend(lpObj->Index, 0, 0, 0, 0, Point);
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "[Ruud] %d Point", lpObj->Ruud + Point);
	}
	gCashShop.CGCashShopPointRecv(lpObj->Index);
	

}
bool CBBuffPhe::CheckMonterPoint(LPOBJ lpObj, LPOBJ Target)
{
	//==Target la nguoi giet
	for (std::vector<LISTMONTER_POINT>::iterator it = this->mDBMonterPoint.begin(); it != this->mDBMonterPoint.end(); it++)
	{
		if (it->Map == -1 && it->MonterClass == -1 || 
			(it->Map == lpObj->Map && it->MonterClass == -1) || 
			(it->Map == lpObj->Map && it->MonterClass == lpObj->Class) ||
			(it->Map == -1 && it->MonterClass == lpObj->Class))
		{
			if (it->Point > 0)
			{
				gNotice.GCNoticeSend(Target->Index, 1, 0, 0, 0, 0, 0, "Kill %s +%d Ruud", lpObj->Name, it->Point);
				this->CongTruRuud(Target, it->Point);
			}
			return 1;
		}

	}
	return 0;
}