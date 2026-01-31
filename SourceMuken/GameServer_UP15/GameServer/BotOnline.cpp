
#include "stdafx.h"
//#include "GameServer.h"
#include "GameMain.h"
#include "User.h"
#include "BotOnline.h"
//#include "..\..\Util\include\readscript.h"
#include "readscript.h"
#include "Util.h"
#include "ItemManager.h"
#include "Monster.h"
#include "ObjectManager.h"
#include "MuunSystem.h"
#include "MemScript.h"
#include "CustomPet.h"
#include "Notice.h"

#if (BOT_STORE == 1)

ObjBotOnline BotOnline;

void ObjBotOnline::Read(char * FilePath)
{
	for (int botNum = 0; botNum < MAX_BOTONLINE; botNum++)
	{
		int bIndex = this->bot[botNum].index;

		if (gObjIsConnected(bIndex) == TRUE)
		{
			gObjDel(bIndex);
		}
	}

	for (int i = 0; i < MAX_BOTONLINE; i++)
	{
		this->bot[i].index = -1;
		this->bot[i].ItemCount = 0;
		for (int j = 0; j < 9; j++)
			this->bot[i].body[j].num = -1;
	}

	int Token;
	SMDFile = fopen(FilePath, "r");

	if (SMDFile == NULL)
	{
		ErrorMessageBox("BotOnline data load error %s", FilePath);
		return;
	}

	while (true)
	{
		int iType = GetToken();

		if (iType == 1)
		{
			while (true)
			{
				Token = GetToken();
				if (strcmp("end", TokenString) == 0)
				{
					break;
				}

				int BotNum = TokenNumber;
				if (BotNum < 0 || BotNum > MAX_BOTONLINE - 1)
				{
					ErrorMessageBox("BotOnline error: BotPetIndex:%d out of range!", BotNum);
					return;
				}

				Token = GetToken();
				this->bot[BotNum].Class = TokenNumber;

				Token = GetToken();
				this->bot[BotNum].OnlyVip = TokenNumber;

				Token = GetToken();
				strncpy(this->bot[BotNum].Name, TokenString, sizeof(this->bot[BotNum].Name));

				Token = GetToken();
				this->bot[BotNum].Map = TokenNumber;

				Token = GetToken();
				this->bot[BotNum].X = TokenNumber;

				Token = GetToken();
				this->bot[BotNum].Y = TokenNumber;

				Token = GetToken();
				this->bot[BotNum].Dir = TokenNumber;

			}
		}

		iType = GetToken();
		iType = TokenNumber;
		if (iType == 2)
		{
			while (true)
			{
				Token = GetToken();
				if (strcmp("end", TokenString) == 0)
				{
					break;
				}

				int BotNum = TokenNumber;
				if (BotNum < 0 || BotNum > MAX_BOTONLINE - 1)
				{
					ErrorMessageBox("BotOnline error: BotPetIndex:%d doesnt exist", BotNum);
					return;
				}

				Token = GetToken();
				int Slot = TokenNumber;

				if (Slot < 0 || Slot > 8)
				{
					ErrorMessageBox("BotOnline error: Min Slot 0 ; Max Slot 8");
					return;
				}

				Token = GetToken();
				int iType = TokenNumber;

				Token = GetToken();
				int iIndex = TokenNumber;

				this->bot[BotNum].body[Slot].num = GET_ITEM(iType, iIndex);

				Token = GetToken();
				this->bot[BotNum].body[Slot].level = TokenNumber;

				Token = GetToken();
				this->bot[BotNum].body[Slot].opt = TokenNumber;

			}
		}
		break;
	}

	//LogAdd(LOG_BOT,"[BotOnline] - %s file is Loaded",FilePath);
	LogAdd(LOG_BLUE, "[BotOnline] Loaded Thành Công %s ", FilePath);
	fclose(SMDFile);
}

BYTE gObjInventoryInsertItemPos1(int aIndex, CItem item, int pos, BOOL RequestCheck) //OK
{

	if (OBJECT_RANGE(aIndex) == 0)
	{
		return -1;
	}

	LPOBJ lpObj;

	int useClass = -1;

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
			useClass = item.IsClassBot(lpObj->Class, lpObj->ChangeUp);

			if (useClass == -1)
			{
				LogAdd(LOG_BLUE, "[Using Class Error] Error UseClass %s", useClass);
				return -1;
			}

		}
	}

	lpObj->Inventory[pos] = item;

	return pos;
}

void ObjBotOnline::MakeBot()
{
	for (int botNum = 0; botNum < MAX_BOTONLINE; botNum++)
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
			gObj[result].Live = TRUE;
			gObj[result].PathCount = 0;
			gObj[result].IsBot = 6;

			gObjSetBots(result, this->bot[botNum].Class);
			gObj[result].ChangeUp = this->bot[botNum].Class;	// Set Second Type of Character
			gObj[result].Class = this->bot[botNum].Class;
			gObj[result].Level = 400;
			gObj[result].Life = 1;
			gObj[result].MaxLife = 2;
			gObj[result].Mana = 1;
			gObj[result].MaxMana = 2;
			gObj[result].Experience = 0;
			gObj[result].DBClass = this->bot[botNum].Class;
			gObj[result].PKLevel = 3;

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
			strncpy(gObj[result].Name, this->bot[botNum].Name, sizeof(gObj[result].Name));


			for (int i = 0; i < 9; i++)
			{
				if (this->bot[botNum].body[i].num >= 0)
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

					gObjInventoryInsertItemPos1(gObj[result].Index, item, i, 0);
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

			GCSummonLifeSend(gObj[result].SummonIndex, gObj[result].MaxLife, gObj[result].Life);	//OK

			GCActionSend(&gObj[result], ACTION_SALUTE1, result, result);
		}
	}
}

#endif