//#include "stdafx.h"
//#include "GameServer.h"
//#include "GameMain.h"
//#include "User.h"
//#include "BotStore.h"
//#include "Util.h"
//#include "Item.h"
//#include "ItemManager.h"
//#include "PG_Custom.h"
//#include "Monster.h"
//#include "ObjectManager.h"
//#include "MuunSystem.h"
//#include "MemScript.h"
//#include "..\..\Util\common\winutil.h"
//#include "..\..\Util\common\SetItemOption.h"
//#include "..\..\Util\include\readscript.h"

#include "stdafx.h"
//#include "GameServer.h"
#include "GameMain.h"
#include "User.h"
#include "BotStore.h"
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

ObjBotStore BotStore;

void ObjBotStore::Read(char * FilePath)
{
	if (this->Enabled == true)
	{
		for (int botNum = 0; botNum<MAX_BOTSTORE; botNum++)
		{
			if (this->bot[botNum].Enabled == true)
			{
				int bIndex = this->bot[botNum].index;
				if (gObjIsConnected(bIndex) == TRUE)
				{
					gObjDel(bIndex);
				}
			}
		}
	}
	for (int i = 0; i<MAX_BOTSTORE; i++)
	{
		this->bot[i].index = -1;
		this->bot[i].Enabled = false;
		this->bot[i].ItemCount = 0;
		for (int j = 0; j<9; j++)
			this->bot[i].body[j].num = -1;
	}

	this->Enabled = FALSE;
	int Token;
	SMDFile = fopen(FilePath, "r");

	if (SMDFile == NULL)
	{
		ErrorMessageBox("BotStore data load error %s", FilePath);
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
				if (BotNum < 0 || BotNum > MAX_BOTSTORE - 1)
				{
					ErrorMessageBox("BotStore error: BotPetIndex:%d out of range!", BotNum);
					return;
				}

				Token = GetToken();
				this->bot[BotNum].Class = TokenNumber;

				Token = GetToken();
				this->bot[BotNum].OnlyVip = TokenNumber;

				Token = GetToken();
				this->bot[BotNum].UseVipMoney = TokenNumber;

				Token = GetToken();
				strncpy(this->bot[BotNum].Name, TokenString, sizeof(this->bot[BotNum].Name));

				Token = GetToken();
				strncpy(this->bot[BotNum].StoreName, TokenString, sizeof(this->bot[BotNum].StoreName));

				Token = GetToken();
				this->bot[BotNum].Map = TokenNumber;

				Token = GetToken();
				this->bot[BotNum].X = TokenNumber;

				Token = GetToken();
				this->bot[BotNum].Y = TokenNumber;

				Token = GetToken();
				this->bot[BotNum].Dir = TokenNumber;

				this->bot[BotNum].Enabled = true;
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
				if (BotNum < 0 || BotNum > MAX_BOTSTORE - 1)
				{
					ErrorMessageBox("BotStore error: BotPetIndex:%d doesnt exist", BotNum);
					return;
				}
				if (this->bot[BotNum].Enabled == false)
				{
					ErrorMessageBox("BotStore error: BotPetIndex:%d doesnt exist", BotNum);
					return;
				}
				Token = GetToken();
				int Slot = TokenNumber;

				if (Slot < 0 || Slot > 8)
				{
					ErrorMessageBox("BotStore error: Min Slot 0 ; Max Slot 8");
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

				this->bot[BotNum].body[Slot].Enabled = true;
			}
		}

		iType = GetToken();
		iType = TokenNumber;
		if (iType == 3)
		{

			CItem item;
			this->Enabled = TRUE;
			while (true)
			{
				Token = GetToken();
				if (strcmp("end", TokenString) == 0)
				{
					break;
				}

				int BotNum = TokenNumber;
				if (BotNum < 0 || BotNum > MAX_BOTSTORE - 1)
				{
					ErrorMessageBox("BotStore error: BotPetIndex:%d doesnt exist", BotNum);
					return;
				}
				if (this->bot[BotNum].Enabled == false)
				{
					ErrorMessageBox("BotStore error: BotPetIndex:%d doesnt exist", BotNum);
					return;
				}
				int Num = this->bot[BotNum].ItemCount;

				Token = GetToken();
				this->bot[BotNum].storeItem[Num].ValueZen = TokenNumber;

				Token = GetToken();
				int iType = TokenNumber;

				Token = GetToken();
				int iIndex = TokenNumber;

				this->bot[BotNum].storeItem[Num].num = GET_ITEM(iType, iIndex);

				Token = GetToken();
				this->bot[BotNum].storeItem[Num].Level = TokenNumber;

				Token = GetToken();
				this->bot[BotNum].storeItem[Num].Opt = TokenNumber;

				Token = GetToken();
				this->bot[BotNum].storeItem[Num].Luck = TokenNumber;

				Token = GetToken();
				this->bot[BotNum].storeItem[Num].Skill = TokenNumber;

				Token = GetToken();
				this->bot[BotNum].storeItem[Num].Dur = TokenNumber;

				Token = GetToken();
				this->bot[BotNum].storeItem[Num].Exc = TokenNumber;

				Token = GetToken();
				this->bot[BotNum].storeItem[Num].Anc = TokenNumber;


				for (int i = 0; i<5; i++)
				{
					Token = GetToken();
					this->bot[BotNum].storeItem[Num].Sock[i] = TokenNumber;
				}
				this->bot[BotNum].ItemCount++;
			}
		}

		break;
	}

	//LogAdd(LOG_BOT,"[BotStore] - %s file is Loaded",FilePath);
	LogAdd(LOG_BLUE, "[BotStore] Loaded Thành Công %s ", FilePath);
	fclose(SMDFile);
}

BYTE gObjInventoryInsertItemPos(int aIndex, CItem item, int pos, BOOL RequestCheck) //OK
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
BYTE PSInventoryRectCheck(int aIndex, int x, int y, int width, int height) // OK
{
	int slot = ((y * 8) + x) + INVENTORY_WEAR_SIZE;

	if (INVENTORY_MAIN_RANGE(slot) != 0 && ((x + width) > 8 || (y + height) > 8))
	{
		return 0xFF;
	}

	if (INVENTORY_EXT1_RANGE(slot) != 0 && ((x + width) > 8 || (y + height) > 12))
	{
		return 0xFF;
	}

	if (INVENTORY_EXT2_RANGE(slot) != 0 && ((x + width) > 8 || (y + height) > 16))
	{
		return 0xFF;
	}

	if (INVENTORY_EXT3_RANGE(slot) != 0 && ((x + width) > 8 || (y + height) > 20))
	{
		return 0xFF;
	}

	if (INVENTORY_EXT4_RANGE(slot) != 0 && ((x + width) > 8 || (y + height) > 24))
	{
		return 0xFF;
	}

	if (INVENTORY_SHOP_RANGE(slot) != 0 && ((x + width) > 8 || (y + height) > 28))
	{
		return 0xFF;
	}

	for (int sy = 0; sy < height; sy++)
	{
		for (int sx = 0; sx < width; sx++)
		{
			if (gObj[aIndex].InventoryMap[(((sy + y) * 8) + (sx + x))] != 0xFF)
			{
				return 0xFF;
			}
		}
	}

	return slot;
}
BYTE gObjTempPShopRectCheck(BYTE * TempMap, int sx, int sy, int width, int height)
{

	int x, y, blank = 0;

	if (sx + width > 12)
	{
		return -1;
	}
	if (sy + height > 8)
	{
		return -2;
	}

	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			if (*(BYTE*)(TempMap + (sy + y) * 8 + (sx + x)) != 255)
			{
				blank += 1;
				//LogAdd(LOG_RED,"DEBUG gObjTempPShopRectCheck blank %d",blank);
				return -1;
			}
		}
	}
	if (blank == 0)
	{
		//LogAdd(LOG_RED,"DEBUG gObjTempPShopRectCheck blank %d return %d",blank,sx+sy*8+INVENTORY_WEAR_SIZE);
		return sx + sy * 8 + INVENTORY_WEAR_SIZE;
	}
	return -1;
}

void gObjTempInventoryItemBoxSet(BYTE * TempMap, int itempos, int xl, int yl, BYTE set_byte)
{
	int itemposx = (itempos - INVENTORY_WEAR_SIZE) % 8;
	int itemposy = (itempos - INVENTORY_WEAR_SIZE) / 8;

	for (int y = 0; y < yl; y++)
	{
		for (int x = 0; x < xl; x++)
		{
			*(BYTE*)(TempMap + (itemposy + y) * 8 + (itemposx + x)) = set_byte;
		}
	}
}
BYTE ObjBotStore::CheckSpace(LPOBJ lpObj, int type, BYTE * TempMap)
{
	int w, h, iwidth, iheight;
	BYTE blank = 0;

	ITEM_INFO ItemInfo;

	if (gItemManager.GetInfo(type, &ItemInfo) == 0)
	{
		return 0;
	}
	//iwidth=ItemAttribute[type].Width;
	//iheight=ItemAttribute[type].Height;

	iwidth = ItemInfo.Width;
	iheight = ItemInfo.Height;

	//LogAdd(LOG_RED,"DEBUG CheckSpace ItmeNUm %d W %d H %d",type,iwidth,iheight);

	for (h = 0; h < 4; h++)
	{
		for (w = 0; w < 8; w++)
		{
			if (*(BYTE*)(TempMap + h * 8 + w) == 255)
				//if(gObj[aIndex].InventoryMap[((y*8)+x)] == 0xFF)
			{
				//blank = gItemManager.InventoryRectCheck(lpObj->Index,w,h,iwidth,iheight);
				blank = gObjTempPShopRectCheck(TempMap, w, h, iwidth, iheight);
				//LogAdd(LOG_RED,"DEBUG CheckSpace %d w %d h %d",blank,iwidth,iheight);
				if (blank == 254)
				{
					goto GOTO_EndFunc;
				}
				if (blank != 255)
				{
					//lpObj->InventoryMap[blank + (INVENTORY_SIZE-(PSHOP_SIZE+INVENTORY_WEAR_SIZE))] = type;
					gObjTempInventoryItemBoxSet(TempMap, blank, iwidth, iheight, type);
					return blank;
				}
			}
		}
	}
GOTO_EndFunc:
	return -1;
}

void ObjBotStore::AddItem(int bIndex, int botNum)
{
	LPOBJ lpObj = &gObj[bIndex];

	for (int i = 0; i<this->bot[botNum].ItemCount; i++)
	{
		int blank = this->CheckSpace(&gObj[bIndex], this->bot[botNum].storeItem[i].num, &gObj[bIndex].InventoryMap[INVENTORY_SIZE - PSHOP_SIZE]);
		if (blank != 255)
		{
			blank += INVENTORY_SIZE - (PSHOP_SIZE + INVENTORY_WEAR_SIZE);

			CItem item;
			item.m_Level = this->bot[botNum].storeItem[i].Level;
			item.m_Option1 = this->bot[botNum].storeItem[i].Skill;
			item.m_Option2 = this->bot[botNum].storeItem[i].Luck;
			item.m_Option3 = this->bot[botNum].storeItem[i].Opt;
			item.m_Durability = this->bot[botNum].storeItem[i].Dur;
			item.m_JewelOfHarmonyOption = 0;
			item.m_NewOption = this->bot[botNum].storeItem[i].Exc;
			item.m_ItemOptionEx = 0;
			item.m_SetOption = this->bot[botNum].storeItem[i].Anc;
			item.m_SocketOption[0] = (this->bot[botNum].storeItem[i].Sock[0] != -1) ? this->bot[botNum].storeItem[i].Sock[0] : 255;
			item.m_SocketOption[1] = (this->bot[botNum].storeItem[i].Sock[1] != -1) ? this->bot[botNum].storeItem[i].Sock[1] : 255;
			item.m_SocketOption[2] = (this->bot[botNum].storeItem[i].Sock[2] != -1) ? this->bot[botNum].storeItem[i].Sock[2] : 255;
			item.m_SocketOption[3] = (this->bot[botNum].storeItem[i].Sock[3] != -1) ? this->bot[botNum].storeItem[i].Sock[3] : 255;
			item.m_SocketOption[4] = (this->bot[botNum].storeItem[i].Sock[4] != -1) ? this->bot[botNum].storeItem[i].Sock[4] : 255;
			item.m_PShopValue = this->bot[botNum].storeItem[i].ValueZen;	//OK
			item.Convert(this->bot[botNum].storeItem[i].num, item.m_Option1, item.m_Option2, item.m_Option3, item.m_NewOption, item.m_SetOption, item.m_JewelOfHarmonyOption, item.m_ItemOptionEx, item.m_SocketOption, item.m_SocketOptionBonus);

			gObj[bIndex].Inventory[blank].m_Option1 = item.m_Option1;
			gObj[bIndex].Inventory[blank].m_Option2 = item.m_Option2;
			gObj[bIndex].Inventory[blank].m_Option3 = item.m_Option3;
			gObj[bIndex].Inventory[blank].m_JewelOfHarmonyOption = item.m_JewelOfHarmonyOption;
			gObj[bIndex].Inventory[blank].m_ItemOptionEx = item.m_ItemOptionEx;

			item.m_Number = 0;

			gObj[bIndex].Inventory[blank] = item;
		}
	}
}
void ObjBotStore::MakeBot()
{
	if (this->Enabled == true)
	{
		for (int botNum = 0; botNum < MAX_BOTSTORE; botNum++)
		{
			if (this->bot[botNum].Enabled == true)
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
					for (int i = 0; i<INVENTORY_SIZE; i++)
					{
						gObj[result].Inventory[i].Clear();
						gObj[result].Inventory1[i].Clear();

					}

					memset(&gObj[result].InventoryMap[0], (BYTE)-1, INVENTORY_SIZE);
					memset(&gObj[result].InventoryMap1[0], (BYTE)-1, INVENTORY_SIZE);
					strncpy(gObj[result].Name, this->bot[botNum].Name, sizeof(gObj[result].Name));


					for (int i = 0; i<9; i++)
					{
						if (this->bot[botNum].body[i].num >= 0 && this->bot[botNum].body[i].Enabled == true)
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
					this->AddItem(result, botNum);

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
					gObj[result].BotPower = this->bot[botNum].UseVipMoney;
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

					gObj[result].PShopOpen = true;

					gObj[result].PShopCustom = 1;

					gObj[result].PShopCustomType = this->bot[botNum].UseVipMoney; //Loai Tien Te

					gObj[result].PShopCustomOffline = 0;

					gObj[result].PShopCustomOfflineTime = 0;

					memcpy(gObj[result].PShopText, this->bot[botNum].StoreName, sizeof(gObj[result].PShopText));

					GCActionSend(&gObj[result], ACTION_SALUTE1, result, result);
				}
			}
		}
	}
}
#endif