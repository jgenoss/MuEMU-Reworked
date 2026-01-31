
#include "stdafx.h"
#include "FakeOnline.h"
#include "ItemManager.h"
#include "Map.h"
#include "MasterSkillTree.h"
#include "Notice.h"
#include "SkillManager.h"
#include "SocketManager.h"
#include "Viewport.h"
//#include "Reconnect.h"
#include "Util.h"
#include "MemScript.h"
#include "Path.h"
#include "Party.h"
#include "EffectManager.h"
#include "MapManager.h"
#include "Message.h"
#include "Monster.h"
#include "DSProtocol.h"
//#include <iomanip>
//#include <stdlib.h>
#include "Quest.h"
#include "QuestObjective.h"
#include <list>
#include <string>
#include "JSProtocol.h"
#include "ObjectManager.h"
#include "OfflineMode.h"
#include "Move.h"
#include "CommandManager.h"
#include "Gate.h"
#include "ItemLevel.h"
#include "ServerInfo.h"
#include "MapServerManager.h"
//#include "CustomAttack.h"
#include "Attack.h"
#include "Party.h"

#if USE_FAKE_ONLINE == TRUE
//========================================================================================================================
CFakeOnline s_FakeOnline;

CFakeOnline::CFakeOnline() // OK
{
	this->m_Data.clear();
	this->IndexMsgMax = 0;
	this->IndexMsgMin = 0;
}

//========================================================================================================================

void CFakeOnline::LoadFakeData(char* path)
{
	this->m_Data.clear();
	this->IndexMsgMax = 0;
	this->IndexMsgMin = 0;

	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(path);
	if (res.status != pugi::status_ok){
		ErrorMessageBox("File %s load fail. Error: %s", path, res.description());
		return;
	}
	pugi::xml_node Recipe = file.child("MSGThongBao");
	this->IndexMsgMin = Recipe.attribute("IndexMesMin").as_int();
	this->IndexMsgMax = Recipe.attribute("IndexMesMax").as_int();

	pugi::xml_node oFakeOnlineData = file.child("FakeOnlineData");
	for (pugi::xml_node rInfoData = oFakeOnlineData.child("Info"); rInfoData; rInfoData = rInfoData.next_sibling()){
		OFFEXP_DATA info;
		memset(&info, 0, sizeof(info));


		strncpy(info.Account, rInfoData.attribute("Account").as_string(), sizeof(info.Account));
		strncpy(info.Password, rInfoData.attribute("Password").as_string(), sizeof(info.Password));
		strncpy(info.Name, rInfoData.attribute("Name").as_string(), sizeof(info.Name));

		info.SkillID = rInfoData.attribute("SkillID").as_int();
		info.UseBuffs[0] = rInfoData.attribute("UseBuffs_0").as_int();
		info.UseBuffs[1] = rInfoData.attribute("UseBuffs_1").as_int();
		info.UseBuffs[2] = rInfoData.attribute("UseBuffs_2").as_int();
		info.GateNumber = rInfoData.attribute("GateNumber").as_int();
		info.MapX = rInfoData.attribute("MapX").as_int();
		info.MapY = rInfoData.attribute("MapY").as_int();
		info.PhamViTrain = rInfoData.attribute("PhamViTrain").as_int();
		info.MoveRange = rInfoData.attribute("MoveRange").as_int();
		info.TimeReturn = rInfoData.attribute("TimeReturn").as_int();
		info.TuNhatItem = rInfoData.attribute("TuNhatItem").as_int();
		info.TuDongReset = rInfoData.attribute("TuDongReset").as_int();
		info.PartyMode = rInfoData.attribute("PartyMode").as_int();
		info.PVPMode = rInfoData.attribute("PVPMode").as_int();
		info.PostKhiDie = rInfoData.attribute("PostKhiDie").as_int();
		this->m_Data.insert(std::pair<std::string, OFFEXP_DATA>(info.Account, info));

	}
	LogAdd(LOG_BLUE, "[FakeOnline] Load Data OK");
}
void CFakeOnline::RestoreFakeOnline()
{
	//	for (int i=0;i<this->m_Data.size();i++)
	for (std::map<std::string, OFFEXP_DATA>::iterator it = this->m_Data.begin(); it != this->m_Data.end(); it++)
	{
		if (gObjFindByAcc(it->second.Account) != 0)
		{
			continue;
		}

		int aIndex = gObjAddSearch(0, "127.0.0.1");

		//LogAdd(LOG_RED,"aIndex = %d",aIndex);
		if (aIndex >= 0)
		{

			char account[11] = { 0 };
			memcpy(account, it->second.Account, (sizeof(account) - 1));

			char password[11] = { 0 };
			memcpy(password, it->second.Password, (sizeof(password) - 1));


			gObjAdd(0, "127.0.0.1", aIndex);
			gObj[aIndex].LoginMessageSend++;
			gObj[aIndex].LoginMessageSend++;
			gObj[aIndex].LoginMessageCount++;
			gObj[aIndex].ConnectTickCount = GetTickCount();
			gObj[aIndex].ClientTickCount = GetTickCount();
			gObj[aIndex].ServerTickCount = GetTickCount();

			gObj[aIndex].MapServerMoveRequest = 0;
			gObj[aIndex].LastServerCode = -1;
			gObj[aIndex].DestMap = -1;
			gObj[aIndex].DestX = 0;
			gObj[aIndex].DestY = 0;

			GJConnectAccountSend(aIndex, account, password, "127.0.0.1");

			gObj[aIndex].Socket = INVALID_SOCKET;

			LogAdd(LOG_RED, "[FakeOnline]  [TK: %s NV: %s] Da Online Vao Server", it->second.Account, it->second.Name);
		}
	}
}

OFFEXP_DATA* CFakeOnline::GetOffExpInfo(LPOBJ lpObj)
{
	std::map<std::string, OFFEXP_DATA>::iterator it = this->m_Data.find(lpObj->Account);

	if (it != this->m_Data.end())
	{
		if (strcmp(lpObj->Name, it->second.Name) == 0)
		{
			return &it->second;

		}
	}

	return 0;
}


OFFEXP_DATA* CFakeOnline::GetOffExpInfoByAccount(LPOBJ lpObj)
{
	std::map<std::string, OFFEXP_DATA>::iterator it = this->m_Data.find(lpObj->Account);

	if (it != this->m_Data.end())
	{
		return &it->second;
	}

	return 0;
}


void FakeAnimationMove(int aIndex, int x, int y, bool dixa)
{
	LPOBJ lpObj = &gObj[aIndex];

	int map_num = gObj[aIndex].Map;

	BYTE path[8];

	if (lpObj->RegenOk > 0)
	{
		return;
	}

	if (lpObj->Teleport != 0)
	{
		return;
	}

	if (gObjCheckMapTile(lpObj, 1) != 0)
	{
		return;
	}

	/*if ((GetTickCount() - lpObj->LastMoveTime) < 100)
	{
	return;
	}*/

	if (gEffectManager.CheckStunEffect(lpObj) != 0 || gEffectManager.CheckImmobilizeEffect(lpObj) != 0)
	{
		return;
	}

	if (lpObj->SkillSummonPartyTime != 0)
	{
		lpObj->SkillSummonPartyTime = 0;
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(272));
	}

	lpObj->Dir = path[0] >> 4;
	lpObj->Rest = 0;
	lpObj->PathCur = 0;
	lpObj->PathCount = path[0] & 0x0F;
	lpObj->LastMoveTime = GetTickCount();

	memset(lpObj->PathX, 0, sizeof(lpObj->PathX));

	memset(lpObj->PathY, 0, sizeof(lpObj->PathY));

	memset(lpObj->PathOri, 0, sizeof(lpObj->PathOri));

	lpObj->TX = x;
	lpObj->TY = y;
	lpObj->PathCur = ((lpObj->PathCount > 0) ? 1 : 0);
	lpObj->PathCount = ((lpObj->PathCount > 0) ? (lpObj->PathCount + 1) : lpObj->PathCount);
	lpObj->PathStartEnd = 1;
	lpObj->PathX[0] = x;
	lpObj->PathY[0] = y;
	lpObj->PathDir[0] = lpObj->Dir;

	for (int n = 1; n < lpObj->PathCount; n++)
	{
		if ((n % 2) == 0)
		{
			lpObj->TX = lpObj->PathX[n - 1] + RoadPathTable[((path[((n + 1) / 2)] & 0x0F) * 2) + 0];
			lpObj->TY = lpObj->PathY[n - 1] + RoadPathTable[((path[((n + 1) / 2)] & 0x0F) * 2) + 1];
			lpObj->PathX[n] = lpObj->PathX[n - 1] + RoadPathTable[((path[((n + 1) / 2)] & 0x0F) * 2) + 0];
			lpObj->PathY[n] = lpObj->PathY[n - 1] + RoadPathTable[((path[((n + 1) / 2)] & 0x0F) * 2) + 1];
			lpObj->PathOri[n - 1] = path[((n + 1) / 2)] & 0x0F;
			lpObj->PathDir[n + 0] = path[((n + 1) / 2)] & 0x0F;
		}
		else
		{
			lpObj->TX = lpObj->PathX[n - 1] + RoadPathTable[((path[((n + 1) / 2)] / 0x10) * 2) + 0];
			lpObj->TY = lpObj->PathY[n - 1] + RoadPathTable[((path[((n + 1) / 2)] / 0x10) * 2) + 1];
			lpObj->PathX[n] = lpObj->PathX[n - 1] + RoadPathTable[((path[((n + 1) / 2)] / 0x10) * 2) + 0];
			lpObj->PathY[n] = lpObj->PathY[n - 1] + RoadPathTable[((path[((n + 1) / 2)] / 0x10) * 2) + 1];
			lpObj->PathOri[n - 1] = path[((n + 1) / 2)] / 0x10;
			lpObj->PathDir[n + 0] = path[((n + 1) / 2)] / 0x10;
		}
	}
	gMap[lpObj->Map].DelStandAttr(lpObj->OldX, lpObj->OldY);
	if (dixa == true) {
		int RandX = rand() % 3 + 1;
		int RandY = rand() % 3 + 1;
		BYTE wall = 0;
		if (x > lpObj->X) {
			wall = gMap[lpObj->Map].CheckWall2(lpObj->X, lpObj->Y, lpObj->X + RandX, lpObj->Y);
			if (wall == 1) lpObj->X += RandX;
		}
		else if (x <  lpObj->X) {
			wall = gMap[lpObj->Map].CheckWall2(lpObj->X, lpObj->Y, lpObj->X - RandX, lpObj->Y);
			if (wall == 1)  lpObj->X -= RandX;
		}
		if (y > lpObj->Y) {
			wall = gMap[lpObj->Map].CheckWall2(lpObj->X, lpObj->Y, lpObj->X, lpObj->Y + RandY);
			if (wall == 1) lpObj->Y += RandY;
		}
		else if (y <  lpObj->Y) {
			wall = gMap[lpObj->Map].CheckWall2(lpObj->X, lpObj->Y, lpObj->X, lpObj->Y - RandY);
			if (wall == 1) lpObj->Y -= RandY;
		}

	}
	else {
		lpObj->X = x;
		lpObj->Y = y;
	}

	//lpObj->Y = y;
	lpObj->TX = lpObj->TX;
	lpObj->TY = lpObj->TY;
	lpObj->OldX = lpObj->TX;
	lpObj->OldY = lpObj->TY;
	lpObj->ViewState = 0;

	gMap[lpObj->Map].SetStandAttr(lpObj->TX, lpObj->TY);

	PMSG_MOVE_SEND pMsg;

	pMsg.header.set(PROTOCOL_CODE1, sizeof(pMsg));

	pMsg.index[0] = SET_NUMBERHB(lpObj->Index);

	pMsg.index[1] = SET_NUMBERLB(lpObj->Index);

	pMsg.x = (BYTE)lpObj->TX;

	pMsg.y = (BYTE)lpObj->TY;

	pMsg.dir = lpObj->Dir << 4;

	//if (!gObjPositionCheck(lpObj))
	{
		lpObj->PathCur = 0;
		lpObj->PathCount = 0;
		lpObj->TX = lpObj->X;
		lpObj->TY = lpObj->Y;
		pMsg.x = (BYTE)lpObj->X;
		pMsg.y = (BYTE)lpObj->Y;
	}

	for (int n = 0; n < MAX_VIEWPORT; n++)
	{
		if (lpObj->VpPlayer2[n].type == OBJECT_USER)
		{
			if (lpObj->VpPlayer2[n].state != OBJECT_EMPTY && lpObj->VpPlayer2[n].state != OBJECT_DIECMD && lpObj->VpPlayer2[n].state != OBJECT_DIED)
			{
				DataSend(lpObj->VpPlayer2[n].index, (BYTE*)&pMsg, pMsg.header.size);
			}
		}
	}
}
void FakeAutoRepair(int aIndex)
{
	if (!gObjIsConnectedGP(aIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	for (int n = 0; n < INVENTORY_WEAR_SIZE; ++n)
	{
		if (lpObj->Inventory[n].IsItem() != 0)
		{
			int money = gItemManager.RepairItem(lpObj, &lpObj->Inventory[n], n, 1);

			if (money != 0)
			{
				gObjectManager.CharacterCalcAttribute(aIndex);
			}
		}
	}
}

void CFakeOnline::FakeAttackProc(LPOBJ lpObj) // OK
{
	if (lpObj->IsFakeOnline != 0)
	{
		lpObj->CheckSumTime = GetTickCount();
		lpObj->ConnectTickCount = GetTickCount();
	}
}
void CFakeOnline::OnAttackAlreadyConnected(LPOBJ lpObj) // OK
{
	if (lpObj->IsFakeOnline != 0)
	{
		lpObj->IsFakeOnline = 0;
		gObjDel(lpObj->Index);
	}
}
void CFakeOnline::Attack(int aIndex)
{
	if (OBJMAX_RANGE(aIndex) == FALSE)
	{
		return;
	}

	if (!gObjIsConnectedGP(aIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->IsFakeOnline == 0 || !lpObj->IsFakeRegen)
	{
		return;
	}

	if (lpObj->State == OBJECT_DELCMD || lpObj->DieRegen != 0 || lpObj->Teleport != 0) {
		return;
	}

	if (gServerInfo.InSafeZone(aIndex) == true)
	{
		//this->OnHelperpAlreadyConnected(lpObj);
		return;
	}


	this->SuDungMauMana(aIndex);

	this->TuDongBuffSkill(aIndex);

	this->TuDongDanhSkill(aIndex);

	FakeAutoRepair(aIndex);
	//LogAdd(LOG_RED,"Fake Online Attack OK");
}


bool FakeisJewels(int index)
{
	if (index == GET_ITEM(12, 15) ||
		index == GET_ITEM(14, 13) ||
		index == GET_ITEM(14, 14) ||
		index == GET_ITEM(14, 16) ||
		index == GET_ITEM(14, 22) ||
		index == GET_ITEM(14, 31) ||
		index == GET_ITEM(14, 42))
	{
		return true;
	}

	return false;
}

bool FakeitemListPickUp(int Index, int Level, LPOBJ lpObj)
{
	for (int i = 0; i < lpObj->ObtainPickExtraCount; i++)
	{
		if (strstr(gItemLevel.GetItemName(Index, Level), lpObj->ObtainPickItemList[i]) != NULL)
		{
			return true;
		}
	}
	return false;
}

int CFakeOnline::NhatItem(int aIndex)
{
	if (OBJMAX_RANGE(aIndex) == FALSE)
	{
		return 0;
	}

	if (!gObjIsConnectedGP(aIndex))
	{
		return 0;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->IsFakeOnline == 0)
	{
		return 0;
	}

	if (lpObj->State == OBJECT_DELCMD || lpObj->DieRegen != 0 || lpObj->Teleport != 0) {
		return 0;
	}

	if (gServerInfo.InSafeZone(aIndex) == true)
	{
		//this->OnHelperpAlreadyConnected(lpObj);
		return 0;
	}


	CMapItem * lpMapItem;

	int distance = lpObj->ObtainRange;

	int map_num = gObj[aIndex].Map;

	if (gObj[aIndex].DieRegen != 0)
	{
		return 0;
	}

	if (MAP_RANGE(map_num) == FALSE)
	{
		return 0;
	}

	int OldX;
	int OldY;
	bool PickItem;

	for (int n = 0; n < MAX_MAP_ITEM; n++)
	{
		PickItem = false;

		lpMapItem = &gMap[map_num].m_Item[n];

		if (lpMapItem->IsItem() == TRUE  && lpMapItem->m_Give == false && lpMapItem->m_Live == true)
		{
			int dis = (int)sqrt((float)((lpObj->X - lpMapItem->m_X) * (lpObj->X - lpMapItem->m_X) + (lpObj->Y - lpMapItem->m_Y) * (lpObj->Y - lpMapItem->m_Y)));

			if (dis > distance)
			{
				continue;
			}
			OldX = lpObj->X;
			OldY = lpObj->Y;
			if (lpObj->ObtainPickSelected == 1)
			{
				if ((lpObj->ObtainPickMoney == 1 && lpMapItem->m_Index == GET_ITEM(14, 15))
					|| (lpObj->ObtainPickExcellent == 1 && lpMapItem->m_NewOption > 0)
					|| (lpObj->ObtainPickAncient == 1 && lpMapItem->m_SetOption > 0)
					|| (lpObj->ObtainPickJewels == 1 && FakeisJewels(lpMapItem->m_Index) == true))
				{
					PickItem = true;
					FakeAnimationMove(lpObj->Index, lpMapItem->m_X, lpMapItem->m_Y, false);
				}
				else if (lpObj->ObtainPickExtra == 1)
				{
					if (FakeitemListPickUp(lpMapItem->m_Index, lpMapItem->m_Level, lpObj) == true)
					{
						PickItem = true;
						FakeAnimationMove(lpObj->Index, lpMapItem->m_X, lpMapItem->m_Y, false);
					}
				}
				else
				{
					PickItem = false;
					continue;
				}
			}
			else
			{
				PickItem = false;
				continue;
			}

			if (PickItem == false)
			{
				continue;
			}

			if (lpObj->X == lpMapItem->m_X && lpObj->Y == lpMapItem->m_Y)
			{
				//zen item
				if (lpMapItem->m_Index == GET_ITEM(14, 15))
				{
					if (lpObj->ObtainPickMoney == 1)
					{
						gMap[map_num].ItemGive(aIndex, n);

						if (!gObjCheckMaxMoney(aIndex, lpMapItem->m_BuyMoney))
						{
							if (lpObj->Money < MAX_MONEY)
							{
								lpObj->Money = MAX_MONEY;
								continue;
							}
						}
						else
						{
							lpObj->Money += lpMapItem->m_BuyMoney;
						}
						continue;
					}
				}
				//all items
				if (lpMapItem->m_QuestItem != false)
				{
					if (!gQuestObjective.CheckQuestObjectiveItemCount(lpObj, lpMapItem->m_Index, lpMapItem->m_Level))
					{
						continue;
					}
				}

				CItem item = (*lpMapItem);

				BYTE result = gItemManager.InventoryInsertItemStack(&gObj[aIndex], lpMapItem);
				if (result != 0xFF)
				{
					//gPickup.MsgPickUpProc(aIndex,&item);//Thong Bao Khi nhat Item
					gMap[map_num].ItemGive(aIndex, n);
					{
						BYTE pos = gItemManager.InventoryInsertItem(aIndex, item);
						if (pos != 0xFF)
						{
							::GCPartyItemInfoSend(aIndex, lpMapItem);
						}

					}
				}
			}
		}
	}

	return 1;
}
void CFakeOnline::PostChatMSG(LPOBJ lpObj)
{
	OFFEXP_DATA *info = s_FakeOnline.GetOffExpInfo(lpObj);
	if (info != 0 && lpObj->Socket == INVALID_SOCKET)
	{
		if (info->PostKhiDie == 1) {
			Sleep(100);
			if (gServerInfo.m_CommandPostType == 0)
			{
				PostMessage1(lpObj->Name, gMessage.GetMessage(69), gMessage.GetMessage(rand() % (this->IndexMsgMax - this->IndexMsgMin + 1) + this->IndexMsgMin));
			}
			else if (gServerInfo.m_CommandPostType == 1)
			{
				PostMessage2(lpObj->Name, gMessage.GetMessage(69), gMessage.GetMessage(rand() % (this->IndexMsgMax - this->IndexMsgMin + 1) + this->IndexMsgMin));
			}
			else if (gServerInfo.m_CommandPostType == 2)
			{
				PostMessage3(lpObj->Name, gMessage.GetMessage(69), gMessage.GetMessage(rand() % (this->IndexMsgMax - this->IndexMsgMin + 1) + this->IndexMsgMin));
			}
			else if (gServerInfo.m_CommandPostType == 3)
			{
				PostMessage4(lpObj->Name, gMessage.GetMessage(69), gMessage.GetMessage(rand() % (this->IndexMsgMax - this->IndexMsgMin + 1) + this->IndexMsgMin));
			}
			else if (gServerInfo.m_CommandPostType == 4)
			{
				GDGlobalPostSend(gMapServerManager.GetMapServerGroup(), 0, lpObj->Name, gMessage.GetMessage(rand() % (this->IndexMsgMax - this->IndexMsgMin + 1) + this->IndexMsgMin));
			}
			else if (gServerInfo.m_CommandPostType == 5)
			{
				GDGlobalPostSend(gMapServerManager.GetMapServerGroup(), 1, lpObj->Name, gMessage.GetMessage(rand() % (this->IndexMsgMax - this->IndexMsgMin + 1) + this->IndexMsgMin));
			}
			else if (gServerInfo.m_CommandPostType == 6)
			{
				GDGlobalPostSend(gMapServerManager.GetMapServerGroup(), 2, lpObj->Name, gMessage.GetMessage(rand() % (this->IndexMsgMax - this->IndexMsgMin + 1) + this->IndexMsgMin));
			}
			else if (gServerInfo.m_CommandPostType == 7)
			{
				GDGlobalPostSend(gMapServerManager.GetMapServerGroup(), 3, lpObj->Name, gMessage.GetMessage(rand() % (this->IndexMsgMax - this->IndexMsgMin + 1) + this->IndexMsgMin));
			}
		}
	}
	return;
}
int random(int minN, int maxN){
	srand((int)time(0));
	return minN + rand() % (maxN + 1 - minN);
}

void CFakeOnline::QuayLaiToaDoGoc(int aIndex)
{
	if (OBJMAX_RANGE(aIndex) == FALSE)
	{
		return;
	}

	if (!gObjIsConnectedGP(aIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->IsFakeOnline == 0)
	{
		return;
	}


	OFFEXP_DATA *info = s_FakeOnline.GetOffExpInfo(lpObj);
	if (info != 0 && lpObj->Socket == INVALID_SOCKET)
	{
		if (lpObj->State == OBJECT_DELCMD || lpObj->DieRegen != 0 || lpObj->Teleport != 0) {
			return;
		}
		int PhamViDiTrain = (int)sqrt(pow(((float)lpObj->X - (float)info->MapX), 2) + pow(((float)lpObj->Y - (float)info->MapY), 2));

		if ((GetTickCount() >= lpObj->IsFakeTimeLag + 30000) && (GetTickCount() >= lpObj->AttackCustomDelay + 30000) && lpObj->IsFakeRegen && (GetTickCount() >= lpObj->m_OfflineMoveDelay + 30000))
		{
			lpObj->IsFakeRegen = false;
			lpObj->IsFakeTimeLag = GetTickCount();
			lpObj->m_OfflineMoveDelay = GetTickCount();
			lpObj->AttackCustomDelay = GetTickCount();
			PhamViDiTrain = (lpObj->IsFakeMoveRange + 10);
			LogAdd(LOG_BLUE, "[FakeOnline][%s] Fix Lag Reset Move", lpObj->Name);
		}

		if (gGate.MapIsInGate(lpObj, info->GateNumber) == 0 || (PhamViDiTrain >= 100 && !lpObj->IsFakeRegen))
		{

			gObjMoveGate(lpObj->Index, info->GateNumber);
			LogAdd(LOG_BLUE, "[FakeOnline][%s] Move Gate", lpObj->Name);
			return;
		}
		if (GetTickCount() >= lpObj->m_OfflineTimeResetMove + 2000)
		{
			if ((PhamViDiTrain >= (lpObj->IsFakeMoveRange + 5) && !lpObj->IsFakeRegen) || gServerInfo.InSafeZone(lpObj->Index) == true)
			{
				int DiChuyenX = lpObj->X;
				int DiChuyenY = lpObj->Y;
				for (int n = 0; n < 16; n++)
				{
					if (lpObj->X > info->MapX) { DiChuyenX -= random(1, 3); }
					else if (lpObj->X < info->MapX){ DiChuyenX += random(1, 3); }
					else { DiChuyenX = info->MapX; }

					if (lpObj->Y > info->MapY) { DiChuyenY -= random(1, 3); }
					else if (lpObj->Y < info->MapY) { DiChuyenY += random(1, 3); }
					else { DiChuyenY = info->MapY; }

					if (DiChuyenX == info->MapX && DiChuyenY == info->MapY) { lpObj->IsFakeRegen = true; }

					if (gMap[lpObj->Map].CheckAttr(DiChuyenX, DiChuyenY, 2) == 0 && gMap[lpObj->Map].CheckAttr(DiChuyenX, DiChuyenY, 4) == 0 && gMap[lpObj->Map].CheckAttr(DiChuyenX, DiChuyenY, 8) == 0)
					{
						lpObj->m_OfflineTimeResetMove = GetTickCount();
						FakeAnimationMove(lpObj->Index, DiChuyenX, DiChuyenY, false);
						LogAdd(LOG_BLUE, "[FakeOnline][%s] Di Chuyen Ve Vi Tri Mac Dinh (%d/%d)", lpObj->Name, DiChuyenX, DiChuyenY);
						return;
					}
				}
				return;

			}
			else if (!lpObj->IsFakeRegen) {

				lpObj->m_OfflineTimeResetMove = GetTickCount();
				lpObj->IsFakeRegen = true;
			}

		}

		//======================================================================
		//=============== Di Chuyen Chung Quanh Dao Map
		if (lpObj->IsFakeMoveRange != 0) {
			if (GetTickCount() >= lpObj->m_OfflineTimeResetMove + 2000 && lpObj->IsFakeRegen)
			{
				int MoveRange = 3;
				//======Move Range======//
				int maxmoverange = MoveRange * 2 + 1;
				int searchc = 10;
				BYTE tpx;
				BYTE tpy;
				while (searchc-- != 0)
				{
					__try
					{
						tpx = (lpObj->X - MoveRange) + (BYTE)(GetLargeRand() % maxmoverange);
						tpy = (lpObj->Y - MoveRange) + (BYTE)(GetLargeRand() % maxmoverange);
					}
					__except (maxmoverange = 1, 1)
					{

					}
					BYTE attr = gMap[lpObj->Map].GetAttr(tpx, tpy);
					//LogAdd(LOG_BLUE,"[FakeOnline]DEBUG MOVE RANGE 1");
					if ((attr & 1) != 1 && (attr & 2) != 2 && (attr & 4) != 4 && (attr & 8) != 8 && GetTickCount() >= lpObj->m_OfflineMoveDelay + 2000)
					{
						LogAdd(LOG_BLUE, "[FakeOnline]Di Chuyen Range (%d,%d)", tpx, tpy);
						lpObj->m_OfflineMoveDelay = GetTickCount();
						FakeAnimationMove(lpObj->Index, tpx, tpy, false);
						return;

					}
					//=======================//
				}

			}
		}
		//=========================================================================

	}


	//================ Di CHuyen Ve Toa Do Goc Khi Den Thoi Gian Cau Hinh
	if (lpObj->DistanceReturnOn != 0)
	{
		if (GetTickCount() >= lpObj->m_OfflineTimeResetMove + 1000 + ((lpObj->DistanceMin * 60) * 1000))
		{
			if (lpObj->m_OfflineCoordX != lpObj->X && lpObj->m_OfflineCoordY != lpObj->Y)
			{
				LogAdd(LOG_BLUE, "[FakeOnline]Quay Ve Toa Do Goc (%d,%d)", lpObj->m_OfflineCoordX, lpObj->m_OfflineCoordY);
				FakeAnimationMove(lpObj->Index, lpObj->m_OfflineCoordX, lpObj->m_OfflineCoordY, false);
				return;
			}
			lpObj->m_OfflineTimeResetMove = GetTickCount();
		}


	}

}

void CFakeOnline::SuDungMauMana(int aIndex)	//-- OK
{
	if (!gObjIsConnectedGP(aIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	//-- AUTO POTION HP
	if (lpObj->RecoveryPotionOn != 0)
	{
		if (lpObj->Life > 0 && lpObj->Life < ((lpObj->MaxLife * lpObj->RecoveryPotionPercent) / 100))
		{
			PMSG_ITEM_USE_RECV pMsg;

			pMsg.header.set(0x26, sizeof(pMsg));

			pMsg.SourceSlot = 0xFF;

			pMsg.SourceSlot = ((pMsg.SourceSlot == 0xFF) ? gItemManager.GetInventoryItemSlot(lpObj, GET_ITEM(14, 3), -1) : pMsg.SourceSlot);

			pMsg.SourceSlot = ((pMsg.SourceSlot == 0xFF) ? gItemManager.GetInventoryItemSlot(lpObj, GET_ITEM(14, 2), -1) : pMsg.SourceSlot);

			pMsg.SourceSlot = ((pMsg.SourceSlot == 0xFF) ? gItemManager.GetInventoryItemSlot(lpObj, GET_ITEM(14, 1), -1) : pMsg.SourceSlot);

			pMsg.TargetSlot = 0xFF;

			pMsg.type = 0;

			if (INVENTORY_FULL_RANGE(pMsg.SourceSlot) != 0)
			{
				gItemManager.CGItemUseRecv(&pMsg, lpObj->Index);
			}
		}
	}

	//-- RECOVERY HEALING ELF
	if (lpObj->RecoveryHealOn != 0)
	{
		CSkill* RenderSkillHealing;

		RenderSkillHealing = gSkillManager.GetSkill(lpObj, SKILL_HEAL);

		if (RenderSkillHealing != 0)
		{
			if (lpObj->Life < ((lpObj->MaxLife * lpObj->RecoveryHealPercent) / 100))
			{
				if (gEffectManager.CheckEffect(lpObj, gSkillManager.GetSkillEffect(RenderSkillHealing->m_index)) == 0)
				{
					gSkillManager.UseAttackSkill(lpObj->Index, lpObj->Index, RenderSkillHealing);
				}
			}
		}
	}
}

void CFakeOnline::TuDongBuffSkill(int aIndex)	//-- OK
{
	if (!gObjIsConnectedGP(aIndex))
	{
		return;
	}
	LPOBJ lpObj = &gObj[aIndex];
	LPOBJ lpTarget;

	if (gServerInfo.InSafeZone(aIndex) == true)
	{
		return;
	}

	//-- AUTOBUFF ONLY
	if (lpObj->BuffOn != 0)
	{
		CSkill* RenderBuff;
		for (int n = 0; n < 3; n++)
		{
			if (lpObj->BuffSkill[n] > 0)
			{
				RenderBuff = gSkillManager.GetSkill(lpObj, lpObj->BuffSkill[n]);

				if (RenderBuff != 0)
				{
					if (gEffectManager.CheckEffect(lpObj, gSkillManager.GetSkillEffect(RenderBuff->m_index)) == 0)
					{
						gSkillManager.UseAttackSkill(lpObj->Index, lpObj->Index, RenderBuff); //Buff Your self
					}
				}
			}
		}
	}

	//-- PARTY MODE ON
	if (lpObj->PartyModeOn != 0 && lpObj->PartyNumber >= 0)
	{
		//-- PARTY HEAL ELF
		if (lpObj->PartyModeHealOn != 0 && lpObj->Class == CLASS_FE)
		{
			CSkill* RenderPartyHealing;

			for (int i = 0; i < MAX_PARTY_USER; i++)
			{

				if (OBJECT_RANGE(gParty.m_PartyInfo[lpObj->PartyNumber].Index[i]) != 0 && gObjCalcDistance(lpObj, &gObj[gParty.m_PartyInfo[lpObj->PartyNumber].Index[i]]) < MAX_PARTY_DISTANCE)
				{
					RenderPartyHealing = gSkillManager.GetSkill(lpObj, SKILL_HEAL);

					if (RenderPartyHealing != 0)
					{
						lpTarget = &gObj[gParty.m_PartyInfo[lpObj->PartyNumber].Index[i]];

						if (lpTarget->Index == lpObj->Index)
						{
							continue;
						}
						if (lpTarget->Life < ((lpTarget->MaxLife * lpObj->PartyModeHealPercent) / 100))
						{
							if (gEffectManager.CheckEffect(lpTarget, gSkillManager.GetSkillEffect(RenderPartyHealing->m_index)) == 0)
							{
								gSkillManager.UseAttackSkill(lpObj->Index, lpTarget->Index, RenderPartyHealing);
							}
						}
					}
				}
			}
		}
		//-- PARTY BUFF
		if (lpObj->PartyModeBuffOn != 0 && lpObj->PartyNumber >= 0)
		{
			CSkill* RenderPartyBuff;

			for (int i = 0; i < MAX_PARTY_USER; i++)
			{
				if (OBJECT_RANGE(gParty.m_PartyInfo[lpObj->PartyNumber].Index[i]) != 0 && gObjCalcDistance(lpObj, &gObj[gParty.m_PartyInfo[lpObj->PartyNumber].Index[i]]) < MAX_PARTY_DISTANCE)
				{
					for (int n = 0; n < 3; n++)
					{
						if (lpObj->BuffSkill[n] > 0)
						{
							RenderPartyBuff = gSkillManager.GetSkill(lpObj, lpObj->BuffSkill[n]);

							if (RenderPartyBuff != 0)
							{
								lpTarget = &gObj[gParty.m_PartyInfo[lpObj->PartyNumber].Index[i]];

								if (gEffectManager.CheckEffect(lpTarget, gSkillManager.GetSkillEffect(RenderPartyBuff->m_index)) == 0)
								{
									gSkillManager.UseAttackSkill(lpObj->Index, gParty.m_PartyInfo[lpObj->PartyNumber].Index[i], RenderPartyBuff);
								}
							}
						}
					}
				}
			}
		}
	}
}


bool CFakeOnline::GetTargetMonster(LPOBJ lpObj, int SkillNumber, int* MonsterIndex) // OK
{
	int NearestDistance = 100;

	for (int n = 0; n < MAX_VIEWPORT; n++)
	{
		if (lpObj->VpPlayer2[n].state == VIEWPORT_NONE || OBJECT_RANGE(lpObj->VpPlayer2[n].index) == 0 || lpObj->VpPlayer2[n].type != OBJECT_MONSTER)
		{
			continue;
		}

		if (gSkillManager.CheckSkillTarget(lpObj, lpObj->VpPlayer2[n].index, -1, lpObj->VpPlayer2[n].type) == 0)
		{
			continue;
		}

		if (gObjCalcDistance(lpObj, &gObj[lpObj->VpPlayer2[n].index]) >= NearestDistance)
		{
			continue;
		}

		if (gSkillManager.CheckSkillRange(SkillNumber, lpObj->X, lpObj->Y, gObj[lpObj->VpPlayer2[n].index].X, gObj[lpObj->VpPlayer2[n].index].Y) != 0)
		{
			(*MonsterIndex) = lpObj->VpPlayer2[n].index;
			NearestDistance = gObjCalcDistance(lpObj, &gObj[lpObj->VpPlayer2[n].index]);
			continue;
		}

		if (gSkillManager.CheckSkillRadio(SkillNumber, lpObj->X, lpObj->Y, gObj[lpObj->VpPlayer2[n].index].X, gObj[lpObj->VpPlayer2[n].index].Y) != 0)
		{
			(*MonsterIndex) = lpObj->VpPlayer2[n].index;
			NearestDistance = gObjCalcDistance(lpObj, &gObj[lpObj->VpPlayer2[n].index]);
			continue;
		}
	}

	return ((NearestDistance == 100) ? 0 : 1);
}

bool CFakeOnline::GetTargetPlayer(LPOBJ lpObj, int SkillNumber, int* MonsterIndex) // OK
{
	int NearestDistance = 100;
	for (int n = 0; n < MAX_VIEWPORT; n++)
	{
		if (lpObj->VpPlayer2[n].state == VIEWPORT_NONE || OBJECT_RANGE(lpObj->VpPlayer2[n].index) == 0 || lpObj->VpPlayer2[n].type != OBJECT_USER)
		{
			continue;
		}

		if (lpObj->GuildNumber == gObj[lpObj->VpPlayer2[n].index].GuildNumber && lpObj->GuildNumber != 0)
		{
			continue;
		}

		if (gObjCalcDistance(lpObj, &gObj[lpObj->VpPlayer2[n].index]) >= NearestDistance)
		{
			continue;
		}
		if (lpObj->IsFakePartyMode >= 2 && gParty.IsParty(gObj[lpObj->VpPlayer2[n].index].PartyNumber) == 0 && (GetTickCount() >= lpObj->IsFakeSendParty + 5000) && !gObjIsSelfDefense(&gObj[lpObj->VpPlayer2[n].index], lpObj->Index))
		{
			if (lpObj->IsFakePartyMode == 3 && !gObj[lpObj->VpPlayer2[n].index].IsFakeOnline) { return 0; }
			lpObj->IsFakeSendParty = GetTickCount();
			FakeAnimationMove(lpObj->Index, gObj[lpObj->VpPlayer2[n].index].X, gObj[lpObj->VpPlayer2[n].index].Y, false);
			this->GuiYCParty(lpObj->Index, lpObj->VpPlayer2[n].index);
			//LogAdd(LOG_RED,"Send Yeu Cau Party cho %s",gObj[lpObj->VpPlayer2[n].index].Name);
			return 0;
		}
		if (gObjIsSelfDefense(&gObj[lpObj->VpPlayer2[n].index], lpObj->Index))
		{
			(*MonsterIndex) = lpObj->VpPlayer2[n].index;
			NearestDistance = gObjCalcDistance(lpObj, &gObj[lpObj->VpPlayer2[n].index]);
			continue;
		}
		if (gSkillManager.CheckSkillRange(SkillNumber, lpObj->X, lpObj->Y, gObj[lpObj->VpPlayer2[n].index].X, gObj[lpObj->VpPlayer2[n].index].Y) != 0)
		{
			if (lpObj->IsFakePVPMode == 2) {
				(*MonsterIndex) = lpObj->VpPlayer2[n].index;
				NearestDistance = gObjCalcDistance(lpObj, &gObj[lpObj->VpPlayer2[n].index]);
			}
			continue;
		}

		if (gSkillManager.CheckSkillRadio(SkillNumber, lpObj->X, lpObj->Y, gObj[lpObj->VpPlayer2[n].index].X, gObj[lpObj->VpPlayer2[n].index].Y) != 0)
		{
			if (lpObj->IsFakePVPMode == 2) {
				(*MonsterIndex) = lpObj->VpPlayer2[n].index;
				NearestDistance = gObjCalcDistance(lpObj, &gObj[lpObj->VpPlayer2[n].index]);
			}
			continue;
		}


	}

	return ((NearestDistance == 100) ? 0 : 1);
}

void CFakeOnline::TuDongDanhSkill(int aIndex)	//-- INCOMPLETO
{
	if (!gObjIsConnectedGP(aIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];
	int caminar = 0;
	int distance = (lpObj->HuntingRange > 6) ? 6 : lpObj->HuntingRange;

	//-- SKILL ATTACK
	CSkill * SkillRender;

	/*if( lpObj->ComboOn != 0 )
	{

	SkillRender = ( lpObj->orderskill == 0 ) ? gSkillManager.GetSkill(lpObj, lpObj->SkillBasicID) : ( lpObj->orderskill == 1 ) ? gSkillManager.GetSkill(lpObj, lpObj->Skill) : gSkillManager.GetSkill(lpObj, lpObj->SkillBasicID);
	}
	else
	{*/
	SkillRender = (lpObj->Life < ((lpObj->MaxLife * lpObj->RecoveryDrainPercent) / 100) && lpObj->RecoveryDrainOn != 0) ? gSkillManager.GetSkill(lpObj, SKILL_DRAIN_LIFE) : gSkillManager.GetSkill(lpObj, lpObj->SkillBasicID);
	/*}*/


	if (SkillRender == 0)
	{
		return;
	}

	int atacar = 0;

	int tObjNum = -1;
	int KillUser = -1;
	if (this->GetTargetPlayer(lpObj, SkillRender->m_index, &KillUser) != 0 && lpObj->IsFakePVPMode >= 1)
	{
		atacar = 0;
		//LogAdd(LOG_RED,"DEBUG GetTargetPlayer %d / %d / %d",lpObj->IsFakePVPMode,gObjIsSelfDefense(&gObj[KillUser], lpObj->Index),KillUser);

		if (gObj[KillUser].Live == 0 || gObj[KillUser].State == OBJECT_EMPTY || gObj[KillUser].RegenType != 0)
		{
			//LogAdd(LOG_RED,"DEBUG GetTargetPlayer1");
			return;
		}

		if (OBJMAX_RANGE(KillUser) == FALSE)
		{
			//LogAdd(LOG_RED,"DEBUG GetTargetPlayer2");
			return;
		}

		if (gObj[KillUser].Type != OBJECT_USER)
		{
			return;
		}

		if (gServerInfo.InSafeZone(KillUser) == true)
		{
			//LogAdd(LOG_RED,"DEBUG GetTargetPlayer3");
			return;
		}

		int dis = (int)sqrt((float)((lpObj->X - gObj[KillUser].X) * (lpObj->X - gObj[KillUser].X) + (lpObj->Y - gObj[KillUser].Y) * (lpObj->Y - gObj[KillUser].Y)));

		if (dis > distance)
		{
			FakeAnimationMove(lpObj->Index, gObj[KillUser].X, gObj[KillUser].Y, false);
			LogAdd(LOG_RED, "DEBUG GetTargetPlayer4 %d ~ %d", dis, distance);
			return;
		}
		else
		{
			if (gSkillManager.CheckSkillRange(SkillRender->m_index, lpObj->X, lpObj->Y, gObj[KillUser].X, gObj[KillUser].Y) != 0)
			{
				caminar = 0;
			}
			else
			{
				caminar = 1;

			}

			if (gSkillManager.CheckSkillRadio(SkillRender->m_index, lpObj->X, lpObj->Y, gObj[KillUser].X, gObj[KillUser].Y) != 0)
			{
				caminar = 0;
			}
			else
			{
				caminar = 1;
			}
			LogAdd(LOG_RED, "DEBUG caminar %d || Bot[%d,%d] User[%d,%d]", caminar, lpObj->X, lpObj->Y, gObj[KillUser].X, gObj[KillUser].Y);

			if (caminar == 1 /*|| ((GetTickCount() - lpObj->m_OfflineMoveDelay) >= 5000)*/);//Time di chuyen)
			{
				FakeAnimationMove(lpObj->Index, gObj[KillUser].X, gObj[KillUser].Y, false);
			}

			atacar = 1;
		}

		if (atacar != 0)
		{
			if (lpObj->Mana < gSkillManager.GetSkillMana(SkillRender->m_index))
			{
				//-- AUTO POTION MP PRIMERO VALIDA QUE NO ESTE MUERTO
				PMSG_ITEM_USE_RECV pMsgMP;

				pMsgMP.header.set(0x26, sizeof(pMsgMP));

				pMsgMP.SourceSlot = 0xFF;

				pMsgMP.SourceSlot = ((pMsgMP.SourceSlot == 0xFF) ? gItemManager.GetInventoryItemSlot(lpObj, GET_ITEM(14, 6), -1) : pMsgMP.SourceSlot);

				pMsgMP.SourceSlot = ((pMsgMP.SourceSlot == 0xFF) ? gItemManager.GetInventoryItemSlot(lpObj, GET_ITEM(14, 5), -1) : pMsgMP.SourceSlot);

				pMsgMP.SourceSlot = ((pMsgMP.SourceSlot == 0xFF) ? gItemManager.GetInventoryItemSlot(lpObj, GET_ITEM(14, 4), -1) : pMsgMP.SourceSlot);

				pMsgMP.TargetSlot = 0xFF;

				pMsgMP.type = 0;

				if (INVENTORY_FULL_RANGE(pMsgMP.SourceSlot) != 0)
				{
					gItemManager.CGItemUseRecv(&pMsgMP, lpObj->Index);
				}
				else
				{
					return;
				}
			}

			int MultiPlicador = (lpObj->Class == CLASS_RF) ? 1 : 5;

			if ((GetTickCount() - ((DWORD)lpObj->AttackCustomDelay)) >= (((((DWORD)lpObj->PhysiSpeed) * MultiPlicador) > 1500) ? 0 : (1500 - (((DWORD)lpObj->PhysiSpeed) * MultiPlicador))))
			{
				lpObj->AttackCustomDelay = GetTickCount();

				if (SkillRender->m_skill != SKILL_FLAME
					&& SkillRender->m_skill != SKILL_TWISTER
					&& SkillRender->m_skill != SKILL_EVIL_SPIRIT
					&& SkillRender->m_skill != SKILL_HELL_FIRE
					&& SkillRender->m_skill != SKILL_AQUA_BEAM
					&& SkillRender->m_skill != SKILL_BLAST
					&& SkillRender->m_skill != SKILL_INFERNO
					&& SkillRender->m_skill != SKILL_TRIPLE_SHOT
					&& SkillRender->m_skill != SKILL_IMPALE
					&& SkillRender->m_skill != SKILL_MONSTER_AREA_ATTACK
					&& SkillRender->m_skill != SKILL_PENETRATION
					&& SkillRender->m_skill != SKILL_FIRE_SLASH
					&& SkillRender->m_skill != SKILL_FIRE_SCREAM)
				{
					if (SkillRender->m_skill != SKILL_DARK_SIDE)
					{

						PMSG_DURATION_SKILL_ATTACK_RECV pMsg;

						pMsg.header.set(0x1E, sizeof(pMsg));

#if(GAMESERVER_UPDATE>=701)

						pMsg.skillH = SET_NUMBERHB(0);

						pMsg.skillL = SET_NUMBERLB((((GetLargeRand() % 100) >= 25) ? 1 : 0));

#else

						pMsg.skill[0] = SET_NUMBERHB(SkillRender->m_index);

						pMsg.skill[1] = SET_NUMBERLB(SkillRender->m_index);

#endif

						pMsg.x = (BYTE)gObj[KillUser].X;

						pMsg.y = (BYTE)gObj[KillUser].Y;

						pMsg.dir = (gSkillManager.GetSkillAngle(gObj[KillUser].X, gObj[KillUser].Y, lpObj->X, lpObj->Y) * 255) / 360;

						pMsg.dis = 0;

						pMsg.angle = (gSkillManager.GetSkillAngle(lpObj->X, lpObj->Y, gObj[KillUser].X, gObj[KillUser].Y) * 255) / 360;

#if(GAMESERVER_UPDATE>=803)

						pMsg.indexH = SET_NUMBERHB(lpObj->TargetNumber);

						pMsg.indexL = SET_NUMBERLB(lpObj->TargetNumber);

#else

						pMsg.index[0] = SET_NUMBERHB(KillUser);

						pMsg.index[1] = SET_NUMBERLB(KillUser);

#endif

						pMsg.MagicKey = 0;

						gSkillManager.CGDurationSkillAttackRecv(&pMsg, lpObj->Index);
						gAttack.Attack(lpObj, &gObj[KillUser], SkillRender, FALSE, 1, 0, FALSE, 0);
					}
					else
					{
						this->SendRFSkillAttack(lpObj, KillUser, SkillRender->m_index);
					}
				}
				else
				{
					this->SendMultiSkillAttack(lpObj, KillUser, SkillRender->m_index);
				}
			}
		}

		return;
	}
	//=============================================================
	if (this->GetTargetMonster(lpObj, SkillRender->m_index, &tObjNum) != 0)
	{

		atacar = 0;

		if (gObj[tObjNum].Live == 0 || gObj[tObjNum].State == OBJECT_EMPTY || gObj[tObjNum].RegenType != 0)
		{
			return;
		}

		if (OBJMAX_RANGE(tObjNum) == FALSE)
		{
			return;
		}

		if (gObj[tObjNum].Type != OBJECT_MONSTER)
		{
			return;
		}

		if (gServerInfo.InSafeZone(tObjNum) == true)
		{
			return;
		}

		int dis = (int)sqrt((float)((lpObj->X - gObj[tObjNum].X) * (lpObj->X - gObj[tObjNum].X) + (lpObj->Y - gObj[tObjNum].Y) * (lpObj->Y - gObj[tObjNum].Y)));

		if (dis > distance)
		{
			return;
		}
		else
		{
			if (gSkillManager.CheckSkillRange(SkillRender->m_index, lpObj->X, lpObj->Y, gObj[tObjNum].X, gObj[tObjNum].Y) != 0)
			{
				caminar = 0;
			}
			else
			{
				caminar = 1;

			}

			if (gSkillManager.CheckSkillRadio(SkillRender->m_index, lpObj->X, lpObj->Y, gObj[tObjNum].X, gObj[tObjNum].Y) != 0)
			{
				caminar = 0;
			}
			else
			{
				caminar = 1;
			}

			if (caminar == 1 /*|| ((GetTickCount() - lpObj->m_OfflineMoveDelay) >= 5000)*/);//Time di chuyen)
			{
				FakeAnimationMove(lpObj->Index, gObj[tObjNum].X, gObj[tObjNum].Y, false);
			}

			atacar = 1;
		}

		if (atacar != 0)
		{
			if (lpObj->Mana < gSkillManager.GetSkillMana(SkillRender->m_index))
			{
				//-- AUTO POTION MP PRIMERO VALIDA QUE NO ESTE MUERTO
				PMSG_ITEM_USE_RECV pMsgMP;

				pMsgMP.header.set(0x26, sizeof(pMsgMP));

				pMsgMP.SourceSlot = 0xFF;

				pMsgMP.SourceSlot = ((pMsgMP.SourceSlot == 0xFF) ? gItemManager.GetInventoryItemSlot(lpObj, GET_ITEM(14, 6), -1) : pMsgMP.SourceSlot);

				pMsgMP.SourceSlot = ((pMsgMP.SourceSlot == 0xFF) ? gItemManager.GetInventoryItemSlot(lpObj, GET_ITEM(14, 5), -1) : pMsgMP.SourceSlot);

				pMsgMP.SourceSlot = ((pMsgMP.SourceSlot == 0xFF) ? gItemManager.GetInventoryItemSlot(lpObj, GET_ITEM(14, 4), -1) : pMsgMP.SourceSlot);

				pMsgMP.TargetSlot = 0xFF;

				pMsgMP.type = 0;

				if (INVENTORY_FULL_RANGE(pMsgMP.SourceSlot) != 0)
				{
					gItemManager.CGItemUseRecv(&pMsgMP, lpObj->Index);
				}
				else
				{
					return;
				}
			}

			int MultiPlicador = (lpObj->Class == CLASS_RF) ? 1 : 5;

			if ((GetTickCount() - ((DWORD)lpObj->AttackCustomDelay)) >= (((((DWORD)lpObj->PhysiSpeed) * MultiPlicador) > 1500) ? 0 : (1500 - (((DWORD)lpObj->PhysiSpeed) * MultiPlicador))))
			{
				lpObj->AttackCustomDelay = GetTickCount();

				if (SkillRender->m_skill != SKILL_FLAME
					&& SkillRender->m_skill != SKILL_TWISTER
					&& SkillRender->m_skill != SKILL_EVIL_SPIRIT
					&& SkillRender->m_skill != SKILL_HELL_FIRE
					&& SkillRender->m_skill != SKILL_AQUA_BEAM
					&& SkillRender->m_skill != SKILL_BLAST
					&& SkillRender->m_skill != SKILL_INFERNO
					&& SkillRender->m_skill != SKILL_TRIPLE_SHOT
					&& SkillRender->m_skill != SKILL_IMPALE
					&& SkillRender->m_skill != SKILL_MONSTER_AREA_ATTACK
					&& SkillRender->m_skill != SKILL_PENETRATION
					&& SkillRender->m_skill != SKILL_FIRE_SLASH
					&& SkillRender->m_skill != SKILL_FIRE_SCREAM)
				{
					if (SkillRender->m_skill != SKILL_DARK_SIDE)
					{

						PMSG_DURATION_SKILL_ATTACK_RECV pMsg;

						pMsg.header.set(0x1E, sizeof(pMsg));

#if(GAMESERVER_UPDATE>=701)

						pMsg.skillH = SET_NUMBERHB(0);

						pMsg.skillL = SET_NUMBERLB((((GetLargeRand() % 100) >= 25) ? 1 : 0));

#else

						pMsg.skill[0] = SET_NUMBERHB(SkillRender->m_index);

						pMsg.skill[1] = SET_NUMBERLB(SkillRender->m_index);

#endif

						pMsg.x = (BYTE)gObj[tObjNum].X;

						pMsg.y = (BYTE)gObj[tObjNum].Y;

						pMsg.dir = (gSkillManager.GetSkillAngle(gObj[tObjNum].X, gObj[tObjNum].Y, lpObj->X, lpObj->Y) * 255) / 360;

						pMsg.dis = 0;

						pMsg.angle = (gSkillManager.GetSkillAngle(lpObj->X, lpObj->Y, gObj[tObjNum].X, gObj[tObjNum].Y) * 255) / 360;

#if(GAMESERVER_UPDATE>=803)

						pMsg.indexH = SET_NUMBERHB(lpObj->TargetNumber);

						pMsg.indexL = SET_NUMBERLB(lpObj->TargetNumber);

#else

						pMsg.index[0] = SET_NUMBERHB(tObjNum);

						pMsg.index[1] = SET_NUMBERLB(tObjNum);

#endif

						pMsg.MagicKey = 0;

						gSkillManager.CGDurationSkillAttackRecv(&pMsg, lpObj->Index);
						gAttack.Attack(lpObj, &gObj[tObjNum], SkillRender, FALSE, 1, 0, FALSE, 0);
					}
					else
					{
						this->SendRFSkillAttack(lpObj, tObjNum, SkillRender->m_index);
					}
				}
				else
				{
					this->SendMultiSkillAttack(lpObj, tObjNum, SkillRender->m_index);
				}
			}
		}
	}
}
//================ Attack Custom

void CFakeOnline::SendSkillAttack(LPOBJ lpObj, int aIndex, int SkillNumber) // OK
{
	PMSG_SKILL_ATTACK_RECV pMsg;

	pMsg.header.set(0x19, sizeof(pMsg));

#if(GAMESERVER_UPDATE>=701)

	pMsg.skillH = SET_NUMBERHB(SkillNumber);

	pMsg.skillL = SET_NUMBERLB(SkillNumber);

	pMsg.indexH = SET_NUMBERHB(aIndex);

	pMsg.indexL = SET_NUMBERLB(aIndex);

#else

	pMsg.skill[0] = SET_NUMBERHB(SkillNumber);

	pMsg.skill[1] = SET_NUMBERLB(SkillNumber);

	pMsg.index[0] = SET_NUMBERHB(aIndex);

	pMsg.index[1] = SET_NUMBERLB(aIndex);

#endif

	pMsg.dis = 0;
	lpObj->IsFakeTimeLag = GetTickCount();
	gSkillManager.CGSkillAttackRecv(&pMsg, lpObj->Index);
}

void CFakeOnline::SendMultiSkillAttack(LPOBJ lpObj, int aIndex, int SkillNumber) // OK
{
	this->SendDurationSkillAttack(lpObj, aIndex, SkillNumber);

	BYTE send[256];

	PMSG_MULTI_SKILL_ATTACK_RECV pMsg;

	pMsg.header.set(PROTOCOL_CODE4, sizeof(pMsg));

	int size = sizeof(pMsg);

#if(GAMESERVER_UPDATE>=701)

	pMsg.skillH = SET_NUMBERHB(SkillNumber);

	pMsg.skillL = SET_NUMBERLB(SkillNumber);

#else

	pMsg.skill[0] = SET_NUMBERHB(SkillNumber);

	pMsg.skill[1] = SET_NUMBERLB(SkillNumber);

#endif

	pMsg.x = (BYTE)lpObj->X;

	pMsg.y = (BYTE)lpObj->Y;

	pMsg.serial = 0;

	pMsg.count = 0;

	PMSG_MULTI_SKILL_ATTACK info;

	for (int n = 0; n < MAX_VIEWPORT; n++)
	{
		if (lpObj->VpPlayer2[n].state == VIEWPORT_NONE || OBJECT_RANGE(lpObj->VpPlayer2[n].index) == 0 /*|| lpObj->VpPlayer2[n].type != OBJECT_MONSTER*/)
		{
			continue;
		}

		int index = lpObj->VpPlayer2[n].index;

		if (gSkillManager.CheckSkillTarget(lpObj, index, aIndex, lpObj->VpPlayer2[n].type) == 0)
		{
			continue;
		}

		if (gSkillManager.CheckSkillRadio(SkillNumber, lpObj->X, lpObj->Y, gObj[index].X, gObj[index].Y) == 0)
		{
			continue;
		}

#if(GAMESERVER_UPDATE>=701)

		info.indexH = SET_NUMBERHB(index);

		info.indexL = SET_NUMBERLB(index);

#else

		info.index[0] = SET_NUMBERHB(index);

		info.index[1] = SET_NUMBERLB(index);

#endif

		info.MagicKey = 0;

		memcpy(&send[size], &info, sizeof(info));
		size += sizeof(info);

		if (CHECK_SKILL_ATTACK_COUNT(pMsg.count) == 0)
		{
			break;
		}
	}

	pMsg.header.size = size;

	memcpy(send, &pMsg, sizeof(pMsg));
	lpObj->IsFakeTimeLag = GetTickCount();
	gSkillManager.CGMultiSkillAttackRecv((PMSG_MULTI_SKILL_ATTACK_RECV*)send, lpObj->Index, 0);
}

void CFakeOnline::SendDurationSkillAttack(LPOBJ lpObj, int aIndex, int SkillNumber) // OK
{
	PMSG_DURATION_SKILL_ATTACK_RECV pMsg;

	pMsg.header.set(0x1E, sizeof(pMsg));

#if(GAMESERVER_UPDATE>=701)

	pMsg.skillH = SET_NUMBERHB(SkillNumber);

	pMsg.skillL = SET_NUMBERLB(SkillNumber);

#else

	pMsg.skill[0] = SET_NUMBERHB(SkillNumber);

	pMsg.skill[1] = SET_NUMBERLB(SkillNumber);

#endif

	pMsg.x = (BYTE)gObj[aIndex].X;

	pMsg.y = (BYTE)gObj[aIndex].Y;

	pMsg.dir = (gSkillManager.GetSkillAngle(gObj[aIndex].X, gObj[aIndex].Y, lpObj->X, lpObj->Y) * 255) / 360;

	pMsg.dis = 0;

	pMsg.angle = (gSkillManager.GetSkillAngle(lpObj->X, lpObj->Y, gObj[aIndex].X, gObj[aIndex].Y) * 255) / 360;

#if(GAMESERVER_UPDATE>=803)

	pMsg.indexH = SET_NUMBERHB(aIndex);

	pMsg.indexL = SET_NUMBERLB(aIndex);

#else

	pMsg.index[0] = SET_NUMBERHB(aIndex);

	pMsg.index[1] = SET_NUMBERLB(aIndex);

#endif

	pMsg.MagicKey = 0;
	lpObj->IsFakeTimeLag = GetTickCount();
	gSkillManager.CGDurationSkillAttackRecv(&pMsg, lpObj->Index);
}

void CFakeOnline::SendRFSkillAttack(LPOBJ lpObj, int aIndex, int SkillNumber) // OK
{
	PMSG_SKILL_DARK_SIDE_RECV Msg;

	Msg.skill[0] = SET_NUMBERHB(SkillNumber);

	Msg.skill[1] = SET_NUMBERLB(SkillNumber);

	Msg.index[0] = SET_NUMBERHB(aIndex);

	Msg.index[1] = SET_NUMBERLB(aIndex);

	gSkillManager.CGSkillDarkSideRecv(&Msg, lpObj->Index);

	PMSG_RAGE_FIGHTER_SKILL_ATTACK_RECV pMsg;

	pMsg.header.set(0x19, sizeof(pMsg));

#if(GAMESERVER_UPDATE>=701)

	pMsg.skillH = SET_NUMBERHB(SkillNumber);

	pMsg.skillL = SET_NUMBERLB(SkillNumber);

	pMsg.indexH = SET_NUMBERHB(aIndex);

	pMsg.indexL = SET_NUMBERLB(aIndex);

#else

	pMsg.skill[0] = SET_NUMBERHB(SkillNumber);

	pMsg.skill[1] = SET_NUMBERLB(SkillNumber);

	pMsg.index[0] = SET_NUMBERHB(aIndex);

	pMsg.index[1] = SET_NUMBERLB(aIndex);

#endif

	pMsg.dis = 0;

	//gSkillManager.CGSkillAttackRecv(&pMsg,lpObj->Index);
	gSkillManager.CGRageFighterSkillAttackRecv(&pMsg, lpObj->Index);
	lpObj->IsFakeTimeLag = GetTickCount();
	this->SendDurationSkillAttack(lpObj, aIndex, SkillNumber);
}

void CFakeOnline::GuiYCParty(int aIndex, int bIndex) // OK
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}

	if (gObjIsConnectedGP(bIndex) == 0)
	{
		return;
	}

	LPOBJ lpTarget = &gObj[bIndex];

	if (lpObj->Interface.use != 0 || lpTarget->Interface.use != 0)
	{
		return;
	}
#if(CHONPHEDOILAP)
	if (!CheckChonPhe(lpObj->Index, lpTarget->Index))
	{
		return;
	}
#endif
	//-- PatyLevel
	if (gServerInfo.m_PartyRestrict == 1 && gParty.IsParty(lpTarget->PartyNumber) == 0)
	{
		if (gObj[aIndex].PartyNumber >= 0)
		{
			if (gParty.GetLevel(gObj[aIndex].PartyNumber) == TRUE)
			{
				int limmaxlevel;
				int limmaxlevel2;

				if (gParty.maxlevel > gObj[bIndex].Level)
				{
					limmaxlevel = gParty.maxlevel;
					limmaxlevel2 = gObj[bIndex].Level;
				}
				else
				{
					limmaxlevel = gObj[bIndex].Level;
					limmaxlevel2 = gParty.maxlevel;
				}

				if ((limmaxlevel - limmaxlevel2) > gServerInfo.m_DifferenceMaxLevelParty)
				{
					gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 2, 0, gMessage.GetMessage(861), gServerInfo.m_DifferenceMaxLevelParty);
					return;
				}

				int limminlevel;
				int limminlevel2;

				if (gParty.minlevel > gObj[bIndex].Level)
				{
					limminlevel = gParty.minlevel;
					limminlevel2 = gObj[bIndex].Level;
				}
				else
				{
					limminlevel = gObj[bIndex].Level;
					limminlevel2 = gParty.minlevel;
				}
				if ((limminlevel - limminlevel2) > gServerInfo.m_DifferenceMaxLevelParty)
				{
					gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 2, 0, gMessage.GetMessage(861), gServerInfo.m_DifferenceMaxLevelParty);
					return;
				}
			}
		}
		else
		{
			short sMaxMinLevel[2];
			if (gObj[aIndex].Level > gObj[bIndex].Level)
			{
				sMaxMinLevel[1] = gObj[aIndex].Level;
				sMaxMinLevel[0] = gObj[bIndex].Level;
			}
			else
			{
				sMaxMinLevel[1] = gObj[bIndex].Level;
				sMaxMinLevel[0] = gObj[aIndex].Level;
			}
			if ((sMaxMinLevel[1] - sMaxMinLevel[0]) >gServerInfo.m_DifferenceMaxLevelParty)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 2, 0, gMessage.GetMessage(861), gServerInfo.m_DifferenceMaxLevelParty);
				return;
			}
		}
	}
	//--FinPartyLevel

	if (CA_MAP_RANGE(lpTarget->Map) != 0 || CC_MAP_RANGE(lpTarget->Map) != 0 || IT_MAP_RANGE(lpTarget->Map) != 0 || DA_MAP_RANGE(lpTarget->Map) != 0 || DG_MAP_RANGE(lpTarget->Map) != 0 || IG_MAP_RANGE(lpTarget->Map) != 0)
	{
		gParty.GCPartyResultSend(aIndex, 0);
		return;
	}

	if (OBJECT_RANGE(lpObj->PartyTargetUser) != 0 || OBJECT_RANGE(lpTarget->PartyTargetUser) != 0)
	{
		gParty.GCPartyResultSend(aIndex, 0);
		return;
	}

	if (gServerInfo.m_GensSystemPartyLock != 0 && lpObj->GensFamily != lpTarget->GensFamily)
	{
		gParty.GCPartyResultSend(aIndex, 6);
		return;
	}

	if (gParty.AutoAcceptPartyRequest(lpObj, lpTarget) != 0)
	{
		return;
	}

	if (gParty.IsParty(lpObj->PartyNumber) != 0 && gParty.IsLeader(lpObj->PartyNumber, aIndex) == 0)
	{
		gParty.GCPartyResultSend(aIndex, 0);
		return;
	}

	if ((lpTarget->Option & 1) == 0)
	{
		gParty.GCPartyResultSend(aIndex, 1);
		return;
	}

	if (gParty.IsParty(lpTarget->PartyNumber) != 0)
	{
		gParty.GCPartyResultSend(aIndex, 4);
		return;
	}

	lpObj->Interface.use = 1;
	lpObj->Interface.type = INTERFACE_PARTY;
	lpObj->Interface.state = 0;
	lpObj->InterfaceTime = GetTickCount();
	lpObj->TargetNumber = bIndex;
	lpObj->PartyTargetUser = bIndex;

	lpTarget->Interface.use = 1;
	lpTarget->Interface.type = INTERFACE_PARTY;
	lpTarget->Interface.state = 0;
	lpTarget->InterfaceTime = GetTickCount();
	lpTarget->TargetNumber = aIndex;

	PMSG_PARTY_REQUEST_SEND pMsg;

	pMsg.header.set(0x40, sizeof(pMsg));

	pMsg.index[0] = SET_NUMBERHB(aIndex);
	pMsg.index[1] = SET_NUMBERLB(aIndex);

	DataSend(bIndex, (BYTE*)&pMsg, pMsg.header.size);
}


#endif