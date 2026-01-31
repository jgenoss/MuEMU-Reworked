#include "stdafx.h"
#include "BotAlchemist.h"
#include "Monster.h"
#include "ItemManager.h"
#include "ObjectManager.h"
#include "SkillManager.h"
#include "EffectManager.h"
#include "MasterSkillTree.h"
#include "ServerInfo.h"
#include "MemScript.h"
#include "Util.h"
#include "CashShop.h"
#include "readscript.h"
#include "Message.h"
#include "Notice.h"
#include "Trade.h"
#include "DSProtocol.h"

ObjBotAlchemist BotAlchemist;

void ObjBotAlchemist::Read(char * FilePath)
{
	if (this->Enabled == 1)
	{
		for (int botNum = 0; botNum<MAX_BOTALCHEMIST; botNum++)
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
					if (BotNum < 0 || BotNum > MAX_BOTALCHEMIST - 1)
					{
						ErrorMessageBox("Cộng Hưởng Lỗi 1: Cộng Hưởng Index: %d Ngoài Phạm Vi!", BotNum);
						return;
					}

					this->bot[BotNum].Class = lpMemScript->GetAsNumber();
					this->bot[BotNum].Enabled = lpMemScript->GetAsNumber();
					this->bot[BotNum].ChangeColorName = lpMemScript->GetAsNumber();
					this->bot[BotNum].Rate = lpMemScript->GetAsNumber();
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
					if (BotNum < 0 || BotNum > MAX_BOTALCHEMIST - 1)
					{
						LogAdd(LOG_RED, "Cộng Hưởng Lỗi 3: Cộng Hưởng Index: %d Không Tồn Tại", BotNum);
						return;
					}

					int Slot = lpMemScript->GetAsNumber();

					if (Slot < 0 || Slot > 8)
					{
						ErrorMessageBox("Cộng Hưởng Lỗi: Min Slot 0 ; Max Slot 8");
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
					if (BotNum < 0 || BotNum > MAX_BOTALCHEMIST - 1)
					{
						LogAdd(LOG_RED, "Cộng Hưởng Lỗi 4: Cộng Hưởng Index: %d Không Tồn Tại!", BotNum);
						return;
					}

					this->bot[BotNum].AllowLevel = lpMemScript->GetAsNumber();
					this->bot[BotNum].AllowOpt = lpMemScript->GetAsNumber();
					this->bot[BotNum].AllowLuck = lpMemScript->GetAsNumber();
					this->bot[BotNum].AllowSkill = lpMemScript->GetAsNumber();
					this->bot[BotNum].AllowExc = lpMemScript->GetAsNumber();
					this->bot[BotNum].AllowFFFF = lpMemScript->GetAsNumber();

				}
				else if (section == 4)
				{
					this->Enabled = 1;
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					int BotNum = lpMemScript->GetNumber();
					if (BotNum < 0 || BotNum > MAX_BOTALCHEMIST - 1)
					{
						LogAdd(LOG_RED, "Cộng Hưởng Lỗi 4: Cộng Hưởng Index: %d Không Tồn Tại!", BotNum);
						return;
					}

					this->bot[BotNum].OnlyVip = lpMemScript->GetAsNumber();

					this->bot[BotNum].Coin1 = lpMemScript->GetAsNumber();

					this->bot[BotNum].Zen = lpMemScript->GetAsNumber();

					this->bot[BotNum].Coin2 = lpMemScript->GetAsNumber();

					this->bot[BotNum].OnlySameType = lpMemScript->GetAsNumber();

					this->bot[BotNum].OnlyLowerIndex = lpMemScript->GetAsNumber();

					this->bot[BotNum].AcceptAncient = lpMemScript->GetAsNumber();

					this->bot[BotNum].MaxLevel = lpMemScript->GetAsNumber();

					this->bot[BotNum].MaxExc = lpMemScript->GetAsNumber();

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

int ObjBotAlchemist::GetBotIndex(int aIndex)
{
	for (int i = 0; i<MAX_BOTALCHEMIST; i++)
	{
		if (this->bot[i].Enabled == 1)
		{
			if (this->bot[i].index == aIndex)
				return i;
		}
	}
	return -1;
}

void ObjBotAlchemist::MakeBot()
{

	if (this->Enabled == 1)
	{

		for (int botNum = 0; botNum<MAX_BOTALCHEMIST; botNum++)
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

BYTE ObjBotAlchemist::gObjInventoryInsertItemPos(int aIndex, CItem item, int pos, BOOL RequestCheck) //OK
{

	if (OBJECT_RANGE(aIndex) == 0)
	{
		return -1;
	}

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

BOOL ObjBotAlchemist::IsInTrade(int aIndex)
{
	int number = this->GetBotIndex(gObj[aIndex].TargetNumber);
	if (number != -1)
		return 1;
	else
		return 0;
}

int ObjBotAlchemist::getNumberOfExcOptions(int checksum)
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


bool ObjBotAlchemist::AllowExc(BYTE BotNum, BYTE ExcOpt)
{
	int dwExOpCount = this->getNumberOfExcOptions(ExcOpt);

	if (dwExOpCount < this->bot[BotNum].MaxExc)
	{
		return true;
	}
	return false;
}

BYTE ObjBotAlchemist::Alchemy(int aIndex, int BotNum)
{
	char sbuf[512] = { 0 };
	int fitem = -1;
	int sitem = -1;
	int count = 0;

	LPOBJ lpObj = &gObj[aIndex];

#if(Fix_Dupe)
	if (
		lpObj->Inventory == 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "MuOnlineVN");
		return 1;
	}
#endif


	if (gObjIsConnected(aIndex) == 0)
	{
		return 0;
	}

	if ((lpObj->TradeMoney - this->bot[BotNum].Zen) < 0)
	{
		wsprintf(sbuf, "I Need %d Zen!", this->bot[BotNum].Zen);
		ChatSend(&gObj[this->bot[BotNum].index], sbuf);
		//LogAdd(LOG_RED,"[Cộng Hưởng][Bot:%d](%s) Insuficent Zen",BotNum,lpObj->Account);
		goto Cancel;
	}

	if (this->bot[BotNum].Coin2 > 0)
	{
		if (lpObj->Coin2 < this->bot[BotNum].Coin2)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Cần %d WcoinP Để Cộng Hưởng!", this->bot[BotNum].Coin2);
			goto Cancel;
		}
	}

	if (this->bot[BotNum].Coin1 > 0)
	{
		if (lpObj->Coin1 < this->bot[BotNum].Coin1)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Cần %d WcoinC Để Cộng Hưởng!", this->bot[BotNum].Coin1);
			LogAdd(LOG_RED, "[Cộng Hưởng] [Bot:%d] NV: (%s) Bạn Không Đủ WcoinC Để Cộng Hưởng!", BotNum, lpObj->Account);
			goto Cancel;
		}
	}

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
	if (count != 2)
	{
		ChatSend(&gObj[this->bot[BotNum].index], "Bạn Chỉ Được Đặt 2 item!");
		LogAdd(LOG_RED, "[Cộng Hưởng] Account:(%s) Name:(%s) Bạn Chỉ Được Đặt 2 item (%d)", lpObj->Account, lpObj->Name, count);
		goto Cancel;
	}
	if ((lpObj->Trade[fitem].m_Index >= 6144) || (lpObj->Trade[sitem].m_Index >= 6144))
	{
		ChatSend(&gObj[this->bot[BotNum].index], "Chỉ Vũ Khí Và Bộ Đồ Được Phép Cộng Hưởng!");
		LogAdd(LOG_RED, "[Cộng Hưởng] Account:(%s) Name:(%s) Chỉ Vũ Khí Và Bộ Đồ Được Phép Cộng Hưởng", lpObj->Account, lpObj->Name);
		goto Cancel;
	}

	if (fitem == -1 || sitem == -1)
	{
		ChatSend(&gObj[this->bot[BotNum].index], "Bạn Phải Đặt 2 Mục Xa Nhau!");
		LogAdd(LOG_RED, "[Cộng Hưởng] Account:(%s) Name:(%s) Bạn Phải Đặt 2 Mục Xa Nhau!", lpObj->Account, lpObj->Name);
		goto Cancel;
	}

	if (this->bot[BotNum].OnlySameType == 1)
	{
		int fType = lpObj->Trade[fitem].m_Index / 512;
		int sType = lpObj->Trade[sitem].m_Index / 512;
		if (fType != sType)
		{
			ChatSend(&gObj[this->bot[BotNum].index], "Bạn Phải Đặt Hai Món Đồ Cùng Loại!");
			LogAdd(LOG_RED, "[Cộng Hưởng] Account:(%s) Name:(%s) Bạn Phải Đặt Hai Món Đồ Cùng Loại!", lpObj->Account, lpObj->Name);
			goto Cancel;
		}
	}

	if (this->bot[BotNum].OnlyLowerIndex == 1)
	{
		int fLevel = gItemManager.m_ItemInfo[lpObj->Trade[fitem].m_Index].Level;
		int sLevel = gItemManager.m_ItemInfo[lpObj->Trade[sitem].m_Index].Level;

		if (fLevel > sLevel)
		{
			if (fLevel > (sLevel + 10))
			{
				ChatSend(&gObj[this->bot[BotNum].index], "Item Cấp Cao Hơn Không Được Cộng Hưởng Từ item Cấp Thấp Hơn!");
				LogAdd(LOG_RED, "[Cộng Hưởng] Account:(%s) Name:(%s) Item Cấp Cao Hơn Không Được Cộng Hưởng Cấp Thấp Hơn!", lpObj->Account, lpObj->Name);
				goto Cancel;
			}
		}
	}

	if (this->bot[BotNum].AcceptAncient == 0 && lpObj->Trade[fitem].m_SetOption > 0)
	{
		ChatSend(&gObj[this->bot[BotNum].index], "Item Thần Thánh Tôi Không Chấp Nhận Nó, Hãy Đặt Item Khác Vào!");
		LogAdd(LOG_RED, "[Cộng Hưởng] Account:(%s) Name:(%s) Item Thần Thánh Tôi Không Chấp Nhận Nó, Hãy Đặt Item Khác Vào!", lpObj->Account, lpObj->Name);
		goto Cancel;
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
		if (lpObj->Trade[fitem].m_Option2 == 0 && lpObj->Trade[sitem].m_Option2 == 1)
		{
			if (!failed)
				lpObj->Trade[fitem].m_Option2 = 1;
			lpObj->Trade[sitem].m_Option2 = 0;
		}
	}
	if (this->bot[BotNum].AllowLevel == 1)
	{
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
		int fOpt = lpObj->Trade[fitem].m_Option3;
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
		}
	}
	if (this->bot[BotNum].AllowExc == 1)
	{
		if (lpObj->Trade[fitem].m_NewOption != 63)
		{
			if (lpObj->Trade[sitem].m_NewOption != 0)
			{
				if (this->AllowExc(BotNum, lpObj->Trade[fitem].m_NewOption) == true)
				{
					BYTE fLife = lpObj->Trade[fitem].IsExtLifeAdd();
					BYTE fMana = lpObj->Trade[fitem].IsExtManaAdd();
					BYTE fDmg = lpObj->Trade[fitem].IsExtDamageMinus();
					BYTE fReflect = lpObj->Trade[fitem].IsExtDamageReflect();
					BYTE fDef = lpObj->Trade[fitem].IsExtDefenseSuccessfull();
					BYTE fMoney = lpObj->Trade[fitem].IsExtMonsterMoney();

					BYTE sLife = lpObj->Trade[sitem].IsExtLifeAdd();
					BYTE sMana = lpObj->Trade[sitem].IsExtManaAdd();
					BYTE sDmg = lpObj->Trade[sitem].IsExtDamageMinus();
					BYTE sReflect = lpObj->Trade[sitem].IsExtDamageReflect();
					BYTE sDef = lpObj->Trade[sitem].IsExtDefenseSuccessfull();
					BYTE sMoney = lpObj->Trade[sitem].IsExtMonsterMoney();


					if (fLife == 0 && sLife != 0)
					{
						if (!failed)
							lpObj->Trade[fitem].m_NewOption |= 0x20;
						lpObj->Trade[sitem].m_NewOption &= ~0x20;
					}
					if (this->AllowExc(BotNum, lpObj->Trade[fitem].m_NewOption) == true)
					{
						if (fMana == 0 && sMana != 0)
						{
							if (!failed)
								lpObj->Trade[fitem].m_NewOption |= 0x10;
							lpObj->Trade[sitem].m_NewOption &= ~0x10;
						}
					}

					if (this->AllowExc(BotNum, lpObj->Trade[fitem].m_NewOption) == true)
					{
						if (fDmg == 0 && sDmg != 0)
						{
							if (!failed)
								lpObj->Trade[fitem].m_NewOption |= 8;
							lpObj->Trade[sitem].m_NewOption &= ~8;
						}
					}

					if (this->AllowExc(BotNum, lpObj->Trade[fitem].m_NewOption) == true)
					{
						if (fReflect == 0 && sReflect != 0)
						{
							if (!failed)
								lpObj->Trade[fitem].m_NewOption |= 4;
							lpObj->Trade[sitem].m_NewOption &= ~4;
						}
					}

					if (this->AllowExc(BotNum, lpObj->Trade[fitem].m_NewOption) == true)
					{
						if (fDef == 0 && sDef != 0)
						{
							if (!failed)
								lpObj->Trade[fitem].m_NewOption |= 2;
							lpObj->Trade[sitem].m_NewOption &= ~2;
						}
					}

					if (this->AllowExc(BotNum, lpObj->Trade[fitem].m_NewOption) == true)
					{
						if (fMoney == 0 && sMoney != 0)
						{
							if (!failed)
								lpObj->Trade[fitem].m_NewOption |= 1;
							lpObj->Trade[sitem].m_NewOption &= ~1;
						}
					}
				}
			}
		}
	}

	int a = gItemManager.InventoryInsertItem(aIndex, lpObj->Trade[fitem]);
	int b = gItemManager.InventoryInsertItem(aIndex, lpObj->Trade[sitem]);
	if (a == 255 || b == 255)
	{
		ChatSend(&gObj[this->bot[BotNum].index], "Thùng Đồ Không Đủ Chỗ Trống!");
		LogAdd(LOG_RED, "[Cộng Hưởng] Account:(%s) Name:(%s) Thùng Đồ Không Đủ Chỗ Trống!", lpObj->Account, lpObj->Name);
		goto Cancel;
	}

	if (failed)
	{
		ChatSend(&gObj[this->bot[BotNum].index], "Cộng Hưởng Thất Bại!");
		LogAdd(LOG_RED, "[Cộng Hưởng] [Bot:%d] Account:(%s) Name:(%s) Cộng Hưởng Thất Bại!", BotNum, lpObj->Account, lpObj->Name);
	}
	else
	{
		ChatSend(&gObj[this->bot[BotNum].index], "Cộng Hưởng Thành Công!");
		LogAdd(LOG_RED, "[Cộng Hưởng] [Bot:%d] Account:(%s) Name:(%s) Cộng Hưởng Thành Công!", BotNum, lpObj->Account, lpObj->Name);
	}

	lpObj->Money -= this->bot[BotNum].Zen;

	if (this->bot[BotNum].Coin1 > 0)

	{
		gCashShop.GDCashShopSubPointSaveSend(lpObj->Index, 0, this->bot[BotNum].Coin1, 0, 0, 0);
		gCashShop.CGCashShopPointRecv(lpObj->Index);//
	}

	else if (this->bot[BotNum].Coin2 > 0)
	{
		gCashShop.GDCashShopSubPointSaveSend(lpObj->Index, 0, this->bot[BotNum].Coin2, 0, 0, 0); //
		gCashShop.CGCashShopPointRecv(lpObj->Index);
	}

	gObjInventoryCommit(aIndex);
	gObjectManager.CharacterMakePreviewCharSet(aIndex);
	GDCharacterInfoSaveSend(aIndex);

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
	gObjNotifyUpdateUnionV1(&gObj[aIndex]);
	gObjNotifyUpdateUnionV2(&gObj[aIndex]);
	return 1;

Cancel:
	this->TradeCancel(aIndex);
	return 1;
}


void ObjBotAlchemist::TradeOk(int aIndex)
{
	int MixNum = -1;
	int MixItem = -1;

	int number = this->GetBotIndex(gObj[aIndex].TargetNumber);

	if (number == -1)
	{
		gObj[aIndex].Interface.state = 0;
		gObj[aIndex].Interface.type = 0;
		gObj[aIndex].TargetShopNumber = OBJECT_BOTS;
		gObj[aIndex].Transaction = 0;
		gObj[aIndex].TradeOkTime = GetTickCount();
		gObj[aIndex].TradeMoney = 1;
		gObj[aIndex].TradeOk = 1;
		return;
	}
	this->Alchemy(aIndex, number);
}

BOOL ObjBotAlchemist::TradeOpen(int index, int nindex)
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

#if(Fix_Dupe)
	if (
		lpObj->Interface.type == INTERFACE_TRADE
		|| lpObj->Interface.type == INTERFACE_WAREHOUSE
		|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
		|| lpObj->Interface.type == INTERFACE_CASH_SHOP
		|| lpObj->Interface.type == INTERFACE_TRAINER
		|| lpObj->DieRegen != 0
		|| lpObj->Teleport != 0
		|| lpObj->PShopOpen != 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "MuOnlineVN");
		return true;
	}
#endif



	if (this->bot[number].OnlyVip == 1 && gObj[index].AccountLevel == 0)
	{
		ChatSend(&gObj[this->bot[number].index], "Bạn Hãy Là Vip Rồi Qoay Lại Gặp Tôi!");
		LogAdd(LOG_RED, "[Cộng Hưởng] [Bot:%d] Account:(%s) Bạn Hãy Là Vip Rồi Qoay Lại Gặp Tôi!", number, gObj[index].Account);
		return 1;
	}

	if ((lpObj->Coin1 - this->bot[number].Coin1) < 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Cần %d WcoinC Để Cộng Hưởng!", this->bot[number].Coin1);
		LogAdd(LOG_RED, "[Cộng Hưởng] [Bot:%d] Account:(%s) Bạn Cần %d WcoinC Để Cộng Hưởng!", number, gObj[index].Account);
		return 1;
	}

	if ((gObj[index].Coin2 - this->bot[number].Coin2) < 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Cần %d WcoinP Để Cộng Hưởng!", this->bot[number].Coin2);
		return 1;
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
			gTrade.GCTradeResponseSend(lpObj->Index, 1, lpBot->Name, 400, 0);
			gTrade.GCTradeOkButtonSend(lpObj->Index, 1);
			lpObj->Interface.state = 1;
			lpObj->Interface.use = 1;
			lpObj->Interface.type = 1;
			lpObj->TradeMoney = 1;
			lpObj->TargetNumber = lpBot->Index;
			lpObj->Transaction = 1;

			char wbuf[1024] = { 0 };
			wsprintf(wbuf, "[Cộng Hưởng] Account:(%s) Name:(%s) OPEN", gObj[index].Account, gObj[index].Name);
			LogAdd(LOG_RED, wbuf);
			ChatSend(&gObj[this->bot[number].index], "Tôi Đã Sẵn Sàng!");

			if (this->bot[number].Coin1 > 0)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Cần %d WcoinC Để Cộng Hưởng!", this->bot[number].Coin1);
			}

			if (this->bot[number].Coin2 > 0)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Cần %d WcoinP Để Cộng Hưởng!", this->bot[number].Coin2);

			}

			if (this->bot[number].Zen > 0)
			{
				//wsprintf(sbuf,"I Need %d Zen!",this->bot[number].Zen );
				//GCServerMsgStringSend(sbuf,index, 0x01);
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Cần %d Zen!", this->bot[number].Zen);
			}
		}
	}
	return 1;
}

void ObjBotAlchemist::TradeCancel(int aIndex)
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

