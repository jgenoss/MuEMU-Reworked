#include "stdafx.h"
#include "ThuMuaDoExc.h"
#include "Monster.h"
#include "Protocol.h"
#include "Util.h"
#include "MemScript.h"
#include "Message.h"
#include "Notice.h"
#include "User.h"
#include "ItemManager.h"
#include "Map.h"
#include "ScheduleManager.h"
#include "ObjectManager.h"
#include "DSProtocol.h"
#include "SkillManager.h"
#include "MuunSystem.h"
#include "GensSystem.h"
#include "PcPoint.h"
#include "Trade.h"
#include "CashShop.h"
#include "Log.h"


#if (BOTHUMUADORAC == 1)

BotThuMuaer BotThuMua;

//CMemScript objScript;

void BotThuMuaer::Read(char * FilePath)
{
	if (this->Enabled == 1)
	{
		for (int botNum = 0; botNum<MAX_BOTTHUMUA; botNum++)
		{
			if (this->bot[botNum].Enabled == 1)
			{
				int bIndex = this->bot[botNum].index;
				if (gObjIsConnected(bIndex) == 1)
				{
					gObjDel(bIndex);
				}
			}
		}
	}
	/*for (int i = 0; i<MAX_BOTTHUMUA; i++)
	{
	this->bot[i].index = -1;
	this->bot[i].SkillCount = 0;
	this->bot[i].MaxLevel = BotThuMua.Max_Normal_Level;
	memset(&this->bot[i].skill, 0, sizeof(this->bot[i].skill));
	this->bot[i].Enabled = 0;
	for (int j = 0; j<9; j++)
	this->bot[i].body[j].num = -1;
	}*/

	this->Enabled = 0;

	CMemScript* lpMemScript = new CMemScript;

	if (lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR, FilePath);
		return;
	}

	if (lpMemScript->SetBuffer(FilePath) == 0)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

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
				if (section == 1)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					int BotNum = lpMemScript->GetNumber();
					if (BotNum < 0 || BotNum > MAX_BOTTHUMUA - 1)
					{
						ErrorMessageBox("ThuMuaDoExc Lỗi 1: ThuMuaDoExcIndex: %d Ngoài Phạm Vi!", BotNum);
						return;
					}

					this->bot[BotNum].Class = lpMemScript->GetAsNumber();
					this->bot[BotNum].Enabled = lpMemScript->GetAsNumber();
					this->bot[BotNum].ChangeColorName = lpMemScript->GetAsNumber();
					this->bot[BotNum].Rate = lpMemScript->GetAsNumber();
					//this->bot[BotNum].PCPoints = lpMemScript->GetAsNumber();
					//this->bot[BotNum].MaxLevel = lpMemScript->GetAsNumber();
					strncpy_s(this->bot[BotNum].Name, lpMemScript->GetAsString(), sizeof(this->bot[BotNum].Name));
					this->bot[BotNum].Map = lpMemScript->GetAsNumber();
					this->bot[BotNum].X = lpMemScript->GetAsNumber();
					this->bot[BotNum].Y = lpMemScript->GetAsNumber();
					this->bot[BotNum].Dir = lpMemScript->GetAsNumber();

				}

				else if (section == 2)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					int BotNum = lpMemScript->GetNumber();
					if (BotNum < 0 || BotNum > MAX_BOTTHUMUA - 1)
					{
						LogAdd(LOG_RED, "ThuMuaDoExc Lỗi 3: ThuMuaDoExcIndex: %d Không Tồn Tại", BotNum);
						return;
					}

					int Slot = lpMemScript->GetAsNumber();

					if (Slot < 0 || Slot > 8)
					{
						ErrorMessageBox("ThuMuaDoExc Lỗi: Min Slot 0 ; Max Slot 8");
						return;
					}

					int iType = lpMemScript->GetAsNumber();
					int iIndex = lpMemScript->GetAsNumber();

					this->bot[BotNum].body[Slot].num = GET_ITEM(iType, iIndex);
					this->bot[BotNum].body[Slot].level = lpMemScript->GetAsNumber();
					this->bot[BotNum].body[Slot].opt = lpMemScript->GetAsNumber();
					this->bot[BotNum].body[Slot].Enabled = 1;

				}

				else if (section == 3)
				{
					this->Enabled = 1;
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					int BotNum = lpMemScript->GetNumber();
					if (BotNum < 0 || BotNum > MAX_BOTTHUMUA - 1)
					{
						LogAdd(LOG_RED, "ThuMuaDoExc Lỗi 4: ThuMuaDoExcIndex: %d Không Tồn Tại", BotNum);
						return;
					}

					/*if (this->bot[BotNum].SkillCount < 0 || this->bot[BotNum].SkillCount > MAX_BOTTHUMUASKILLS - 1)
					{
					LogAdd(LOG_RED, "ThuMuaDoExc Lỗi: Skill Buff out of range (MAX BUFF PER BOT = %d)!", this->bot[BotNum].SkillCount);
					return;
					}*/

					this->bot[BotNum].AllowLevel = lpMemScript->GetAsNumber();
					this->bot[BotNum].AllowOpt = lpMemScript->GetAsNumber();
					this->bot[BotNum].AllowLuck = lpMemScript->GetAsNumber();
					this->bot[BotNum].AllowSkill = lpMemScript->GetAsNumber();
					this->bot[BotNum].AllowExc = lpMemScript->GetAsNumber();
					//this->bot[BotNum].AllowFFFF = lpMemScript->GetAsNumber();

				}
				else if (section == 4)
				{
					this->Enabled = 1;
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					int BotNum = lpMemScript->GetNumber();
					if (BotNum < 0 || BotNum > MAX_BOTTHUMUA - 1)
					{
						LogAdd(LOG_RED, "ThuMuaDoExc Lỗi 4: ThuMuaDoExcIndex: %d Không Tồn Tại!", BotNum);
						return;
					}

					if (this->bot[BotNum].SkillCount < 0 || this->bot[BotNum].SkillCount > MAX_BOTTHUMUASKILLS - 1)
					{
						LogAdd(LOG_RED, "ThuMuaDoExc Lỗi: Skill Buff Ngoài Phạm Vi (MAX BUFF PER BOT = %d)!", this->bot[BotNum].SkillCount);
						return;
					}

					this->bot[BotNum].OnlyVip = lpMemScript->GetAsNumber();
					this->bot[BotNum].WCoinCMin = lpMemScript->GetAsNumber();
					this->bot[BotNum].WCoinCMax = lpMemScript->GetAsNumber();
					this->bot[BotNum].WCoinP = lpMemScript->GetAsNumber();

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

int BotThuMuaer::GetBotIndex(int aIndex)
{
	for (int i = 0; i<MAX_BOTTHUMUA; i++)
	{
		if (this->bot[i].Enabled == 1)
		{
			if (this->bot[i].index == aIndex)
				return i;
		}
	}
	return -1;
}

void BotThuMuaer::MakeBot()
{

	if (this->Enabled == 1)
	{

		for (int botNum = 0; botNum<MAX_BOTTHUMUA; botNum++)
		{
			if (this->bot[botNum].Enabled == 1)
			{

				int result = gObjAddSummon();

				if (result >= 0)
				{
					this->bot[botNum].index = result;
					gObj[result].PosNum = (WORD)-1;
					gObj[result].X = this->bot[botNum].X;
					gObj[result].Y = this->bot[botNum].Y;
					gObj[result].OldX = this->bot[botNum].X;
					gObj[result].OldY = this->bot[botNum].Y;
					gObj[result].TX = this->bot[botNum].X;
					gObj[result].TY = this->bot[botNum].Y;
					gObj[result].MTX = this->bot[botNum].X;
					gObj[result].MTY = this->bot[botNum].Y;
					gObj[result].Dir = this->bot[botNum].Dir;
					gObj[result].Map = this->bot[botNum].Map;
					gObj[result].Live = 1;
					gObj[result].PathCount = 0;
					gObj[result].IsBot = 2;
					gObj[result].BotPower = 0;

					gObjSetBots(result, this->bot[botNum].Class);

					gObj[result].ChangeUp = this->bot[botNum].Class;
					gObj[result].Class = this->bot[botNum].Class;
					gObj[result].Level = 400;
					gObj[result].Life = 1;
					gObj[result].MaxLife = 2;
					gObj[result].Mana = 1;
					gObj[result].MaxMana = 2;
					gObj[result].Experience = 0;
					gObj[result].DBClass = this->bot[botNum].Class;
					gObj[result].PKLevel = this->bot[botNum].ChangeColorName;
					gObj[result].GensFamily = this->bot[botNum].GensFamily;
					gObj[result].Inventory = new CItem[INVENTORY_SIZE];
					gObj[result].Inventory1 = new CItem[INVENTORY_SIZE];
					gObj[result].InventoryMap1 = new BYTE[INVENTORY_SIZE];
					gObj[result].InventoryMap = new BYTE[INVENTORY_SIZE];


					for (int i = 0; i<INVENTORY_SIZE; i++)
					{
						gObj[result].Inventory[i].Clear();
						gObj[result].Inventory1[i].Clear();
					}

					memset(&gObj[result].InventoryMap[0], (BYTE)-1, INVENTORY_SIZE);
					memset(&gObj[result].InventoryMap1[0], (BYTE)-1, INVENTORY_SIZE);

#if (GAMESERVER_UPDATE >= 801)
					gObj[result].MuunInventory = new CItem[MUUN_INVENTORY_SIZE];
					gObj[result].MuunInventoryMap = new BYTE[MUUN_INVENTORY_SIZE];

					for (int i = 0; i<MUUN_INVENTORY_SIZE; i++)
					{
						gObj[result].MuunInventory[i].Clear();
					}

					memset(&gObj[result].MuunInventoryMap[0], (BYTE)-1, MUUN_INVENTORY_SIZE); //novo
#endif

					strcpy_s(gObj[result].Name, this->bot[botNum].Name);

					for (int i = 0; i<9; i++)
					{
						if (this->bot[botNum].body[i].num >= 0 && this->bot[botNum].body[i].Enabled == 1)
						{
							CItem item;
							item.m_Level = this->bot[botNum].body[i].level;
							item.m_Option1 = 0;
							item.m_Option2 = 1;
							item.m_Option3 = this->bot[botNum].body[i].opt;
							item.m_Durability = 255.0f;
							item.m_JewelOfHarmonyOption = 0;
							item.m_ItemOptionEx = 0;
							item.m_SocketOption[1] = 0;
							item.m_SocketOption[2] = 0;
							item.m_SocketOption[3] = 0;
							item.m_SocketOption[4] = 0;
							item.m_SocketOption[5] = 0;
							item.Convert(this->bot[botNum].body[i].num, item.m_Option1, item.m_Option2, item.m_Option3, item.m_NewOption, item.m_SetOption, item.m_JewelOfHarmonyOption, item.m_ItemOptionEx, item.m_SocketOption, item.m_SocketOptionBonus);
							gObj[result].Inventory[i].m_Option1 = item.m_Option1;
							gObj[result].Inventory[i].m_Option2 = item.m_Option2;
							gObj[result].Inventory[i].m_Option3 = item.m_Option3;
							gObj[result].Inventory[i].m_JewelOfHarmonyOption = item.m_JewelOfHarmonyOption;
							gObj[result].Inventory[i].m_ItemOptionEx = item.m_ItemOptionEx;

							item.m_Number = 0;
							gObjInventoryInsertItemPos(gObj[result].Index, item, i, 0);
						}
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
					gObj[result].BotDefense = this->bot[botNum].OnlyVip;
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

				}
			}
		}
	}
}


BYTE BotThuMuaer::gObjInventoryInsertItemPos(int aIndex, CItem item, int pos, BOOL RequestCheck) //OK
{

	if (OBJECT_RANGE(aIndex) == 0)
	{
		return -1;
	}

	/*if(pos < 0 || pos > INVENTORY_SIZE_CUSTOM(aIndex,false))
	{
	return -1;
	}*/

	LPOBJ lpObj;

	int useClass = 0;

	lpObj = &gObj[aIndex];

	if (lpObj->Inventory[pos].IsItem() == 1)
	{
		return -1;
	}

	if (item.IsItem() == 0)
	{
		return -1;
	}

	if (pos < 12)
	{
		if (lpObj->IsBot == 0)
		{
			useClass = item.IsClassBot((char)lpObj->Class, lpObj->ChangeUp);

			if (useClass == 0)
			{
				LogAdd(LOG_BLUE, "[Using Class Error] Error UseClass %d", useClass);
				return -1;
			}

		}
	}

	lpObj->Inventory[pos] = item;

	return pos;
}

BOOL BotThuMuaer::IsInTrade(int aIndex)
{
	int number = this->GetBotIndex(gObj[aIndex].TargetNumber);
	if (number != -1)
		return 1;
	else
		return 0;
}

//int BotThuMuaer::GetBotIndex(int aIndex)
//{
//	for (int i = 0; i<MAX_BOTTHUMUA; i++)
//	{
//		if (this->bot[i].Enabled == true)
//		{
//			if (this->bot[i].index == aIndex)
//				return i;
//		}
//	}
//	return -1;
//}

int BotThuMuaer::getNumberOfExcOptions(int checksum)
{
	int optionscount = 0;
	int ExcOrgArr[6];

	ExcOrgArr[0] = 1;
	ExcOrgArr[1] = 2;
	ExcOrgArr[2] = 4;
	ExcOrgArr[3] = 8;
	ExcOrgArr[4] = 16;
	ExcOrgArr[5] = 32;

	if (checksum>0)
	{
		for (int i = 0; i<6; i++)
		{
			int and_val = checksum & ExcOrgArr[i];
			if (and_val != 0)
				optionscount += 1;
		}
	}

	return optionscount;
}


bool BotThuMuaer::AllowExc(BYTE BotNum, BYTE ExcOpt)
{
	int dwExOpCount = this->getNumberOfExcOptions(ExcOpt);

	if (dwExOpCount < this->bot[BotNum].MaxExc)
	{
		return true;
	}
	return false;
}

BYTE BotThuMuaer::Alchemy(int aIndex, int BotNum)
{
	char sbuf[512] = { 0 };
	int fitem = -1;
	int sitem = -1;
	int count = 0;

	if (gObjIsConnected(aIndex) == 0)
	{
		return 0;
	}

	LPOBJ lpObj = &gObj[aIndex];


	for (int n = 0; n < TRADE_SIZE; n++)
	{
		if (lpObj->Trade[n].IsItem() != 0)
		{
			if ((n >= 0 && n <= 3) || (n >= 8 && n <= 11) || (n >= 16 && n <= 19) || (n >= 24 && n <= 27))
			{
				fitem = n;
			}
			else
			{
				sitem = n;
			}

			count++;
		}
	}

	srand(static_cast<int>(time(NULL)));
	int random = rand() % 100;
	bool failed = false;

	if (random > this->bot[BotNum].Rate)
	{
		failed = true;
	}

	if (this->bot[BotNum].AllowLuck == 1)
	{
		LogAdd(LOG_RED, "[BotThuMuaDoExc] AllowLuck");
		if (lpObj->Trade[fitem].m_Option2 == 0 && lpObj->Trade[sitem].m_Option2 == 1)
		{
			if (!failed)
				lpObj->Trade[fitem].m_Option2 = 1;
			lpObj->Trade[sitem].m_Option2 = 0;
		}
	}
	if (this->bot[BotNum].AllowLevel == 1)
	{
		LogAdd(LOG_RED, "[BotThuMuaDoExc] AllowLevel");
		int fLevel = lpObj->Trade[fitem].m_Level;
		if (fLevel < this->bot[BotNum].MaxLevel)
		{
			int sLevel = lpObj->Trade[sitem].m_Level;
			if ((fLevel + sLevel) > this->bot[BotNum].MaxLevel)
			{
				sLevel -= (this->bot[BotNum].MaxLevel - fLevel);
				if (!failed)
					fLevel = this->bot[BotNum].MaxLevel;
			}
			else
			{
				if (!failed)
					fLevel += sLevel;
				sLevel = 0;
			}
			lpObj->Trade[fitem].m_Level = fLevel;
			lpObj->Trade[sitem].m_Level = sLevel;
		}
	}
	if (this->bot[BotNum].AllowSkill == 1)
	{
		LogAdd(LOG_RED, "[BotThuMuaDoExc] AllowSkill");
		if (lpObj->Trade[fitem].m_Index < 3584)
		{
			if (lpObj->Trade[fitem].m_Option1 == 0 && lpObj->Trade[sitem].m_Option1 == 1)
			{
				if (!failed)
					lpObj->Trade[fitem].m_Option1 = 1;
				lpObj->Trade[sitem].m_Option1 = 0;
			}
		}
	}
	if (this->bot[BotNum].AllowOpt == 1)
	{
		LogAdd(LOG_RED, "[BotThuMuaDoExc] AllowOpt [Check]");
		/*int fOpt = lpObj->Trade[fitem].m_Option3;
		if (fOpt < 7)
		{
		int sOpt = lpObj->Trade[sitem].m_Option3;
		if ((fOpt + sOpt) > 7)
		{
		sOpt -= (7 - fOpt);
		if (!failed)
		fOpt = 7;
		}
		else
		{
		if (!failed)
		fOpt += sOpt;
		sOpt = 0;
		}
		lpObj->Trade[fitem].m_Option3 = fOpt;
		lpObj->Trade[sitem].m_Option3 = sOpt;
		}*/
		if (lpObj->Trade[fitem].m_Index < 5832)
		{
			if (lpObj->Trade[fitem].m_Option3 >= 1 && lpObj->Trade[sitem].m_Option3 <= 63)
			{
				if (!failed)
					lpObj->Trade[fitem].m_Option3 <= 1;
				lpObj->Trade[sitem].m_Option3 = 0;
			}
		}
	}
	if (lpObj->Trade[BotNum].m_NewOption == 0 && lpObj->Trade[fitem].m_SetOption == 0)
	{
		this->TradeCancel(aIndex);
		return 0;
	}

	LogAdd(LOG_RED, "[BotThuMuaDoExc]  AllowOpt [Recv]");

	if (failed)
	{
		ChatSend(&gObj[this->bot[BotNum].index], "Đổi Đồ Exc Thất Bại!");
	}
	else
	{
		ChatSend(&gObj[this->bot[BotNum].index], "Đổi Đồ Exc Thành Công!");

		int RandomWC = rand() % (this->bot[BotNum].WCoinCMax - this->bot[BotNum].WCoinCMin + 1) + this->bot[BotNum].WCoinCMin; //(b-a+1) +a <--> tu a den b

		GDSetCoinSend(lpObj->Index, +(RandomWC), +(this->bot[BotNum].WCoinP), +(0), "ThuMuaDoExc");
		gCashShop.CGCashShopPointRecv(lpObj->Index);

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, gMessage.GetMessage(565), lpObj->Name, RandomWC, this->bot[BotNum].WCoinP, 0);
	}

	gObjInventoryCommit(aIndex);
	gObjectManager.CharacterMakePreviewCharSet(aIndex);
	//GDCharacterInfoSaveSend(aIndex);
	GDPetItemInfoSend(aIndex, 0);
	lpObj->Interface.use = 0;
	lpObj->Interface.type = INTERFACE_NONE;
	lpObj->Interface.state = 0;
	lpObj->TargetNumber = -1;
	lpObj->TradeOk = 0;
	lpObj->TradeOkTime = 0;
	lpObj->TradeMoney = 0;
	GCMoneySend(aIndex, lpObj->Money);
	gTrade.GCTradeResultSend(aIndex, 1);
	gItemManager.GCItemListSend(aIndex);
	gTrade.ClearTrade(lpObj);
	return 1;

Cancel:
	this->TradeCancel(aIndex);
	return 0;
}


void BotThuMuaer::TradeOk(int aIndex)
{
	int MixNum = -1;
	int MixItem = -1;

	int number = this->GetBotIndex(gObj[aIndex].TargetNumber);

	if (number == -1)
	{
		gObj[aIndex].Interface.state = 0;
		gObj[aIndex].Interface.type = 0;
		gObj[aIndex].TargetShopNumber = -1;
		gObj[aIndex].Transaction = 0;

		return;
	}
	this->Alchemy(aIndex, number);
}

BOOL BotThuMuaer::TradeOpen(int index, int nindex)
{
	if (gObjIsConnected(index) == 0)
	{
		return 0;
	}
	if (gObjIsConnected(nindex) == 0)
	{
		return 0;
	}

	int number = this->GetBotIndex(nindex);
	if (number == -1)
		return 0;
	char sbuf[512] = { 0 };
	LPOBJ lpObj = &gObj[index];
	LPOBJ lpBot = &gObj[nindex];

	if (this->bot[number].OnlyVip == 1 && gObj[index].AccountLevel == 0)
	{
		ChatSend(&gObj[this->bot[number].index], "Chỉ Hoạt Động Cho VIPs!");
		LogAdd(LOG_RED, "[BotThuMuaDoExc]  [Bot:%d] Account:(%s) AccountKhông Phải Là VIPs!", number, gObj[index].Account);
		return 0;
	}

	if (this->Enabled == TRUE)
	{
		if (lpObj->Interface.use > 0)
		{
			return 0;
		}
		else
		{
			for (int n = 0; n < TRADE_SIZE; n++)
			{
				lpObj->Trade[n].Clear();
			}
			memset(lpObj->TradeMap, (BYTE)-1, TRADE_SIZE);

			gObjInventoryTransaction(lpObj->Index);
			//GCTradeResponseSend(true, lpObj->m_Index, lpBot->Name, 400, 0);
			//GCTradeOkButtonSend(lpObj->m_Index, 1);
			gTrade.GCTradeResponseSend(lpObj->Index, 1, lpBot->Name, 400, 0);
			gTrade.GCTradeOkButtonSend(lpObj->Index, 1);
			lpObj->Interface.state = 1;
			lpObj->Interface.use = 1;
			lpObj->Interface.type = 1;
			lpObj->TradeMoney = 0;
			lpObj->TargetNumber = lpBot->Index;
			lpObj->Transaction = 1;

			char wbuf[1024] = { 0 };
			wsprintf(wbuf, "[BotThuMuaDoExc] (Account:(%s) Name:(%s) Open", gObj[index].Account, gObj[index].Name);
			LogAdd(LOG_RED, wbuf);
			ChatSend(&gObj[this->bot[number].index], "Tôi Đã Sẵn Sàng!");
			gLog.Output(LOG_THU_MUA, "[BotThuMua] (Account:(%s) Name:(%s) Open", gObj[index].Account, gObj[index].Name);


		}
	}
	return 1;
}

void BotThuMuaer::TradeCancel(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}

	if (lpObj->Interface.use == 0 || lpObj->Interface.type != INTERFACE_TRADE || lpObj->Interface.state == 0)
	{
		return;
	}

	gTrade.ResetTrade(aIndex);
	gTrade.GCTradeResultSend(aIndex, 0);
}


#endif
