#include "stdafx.h"
#include "DucTuong.h"
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

DucTuong gDucTuong;


void DucTuong::LoadConfig()
{
	int bIndex = this->Tuong.index;
	if (gObjIsConnected(bIndex) == 1)
	{
		gObjDel(bIndex);
	}

	this->Tuong.index = -1;
	this->Tuong.Enabled = 0;
	for (int j = 0; j<9; j++)
		this->Tuong.body[j].num = -1;

	this->Enabled = GetPrivateProfileIntA("Setting", "Enabled", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.Enabled = GetPrivateProfileIntA("Setting", "Enabled", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.X = GetPrivateProfileIntA("Setting", "X", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.Y = GetPrivateProfileIntA("Setting", "Y", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.Dir = GetPrivateProfileIntA("Setting", "Dir", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.Map = GetPrivateProfileIntA("Setting", "Map", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	//this->Tuong.GensFamily = GetPrivateProfileIntA("Setting","GensFamily",0,"..\\Data\\Custom\\\BotSystem\\DucTuong.ini");

	this->Tuong.Class = GetPrivateProfileIntA("Setting", "Class", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.ChangeColorName = GetPrivateProfileIntA("Setting", "PKLevel", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	GetPrivateProfileString("Setting", "Name", "", this->Tuong.Name, sizeof(this->Tuong.Name), "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");

	this->Tuong.body[0].num = GetPrivateProfileIntA("VK1", "Index", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[0].level = GetPrivateProfileIntA("VK1", "Level", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[0].opt = GetPrivateProfileIntA("VK1", "opt", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[0].Enabled = 1;

	this->Tuong.body[1].num = GetPrivateProfileIntA("VK2", "Index", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[1].level = GetPrivateProfileIntA("VK2", "Level", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[1].opt = GetPrivateProfileIntA("VK2", "opt", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[1].Enabled = 1;

	this->Tuong.body[2].num = GetPrivateProfileIntA("Helm", "Index", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[2].level = GetPrivateProfileIntA("Helm", "Level", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[2].opt = GetPrivateProfileIntA("Helm", "opt", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[2].Enabled = 1;

	this->Tuong.body[3].num = GetPrivateProfileIntA("Armor", "Index", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[3].level = GetPrivateProfileIntA("Armor", "Level", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[3].opt = GetPrivateProfileIntA("Armor", "opt", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[3].Enabled = 1;

	this->Tuong.body[4].num = GetPrivateProfileIntA("Pants", "Index", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[4].level = GetPrivateProfileIntA("Pants", "Level", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[4].opt = GetPrivateProfileIntA("Pants", "opt", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[4].Enabled = 1;

	this->Tuong.body[5].num = GetPrivateProfileIntA("Gloves", "Index", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[5].level = GetPrivateProfileIntA("Gloves", "Level", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[5].opt = GetPrivateProfileIntA("Gloves", "opt", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[5].Enabled = 1;

	this->Tuong.body[6].num = GetPrivateProfileIntA("Boots", "Index", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[6].level = GetPrivateProfileIntA("Boots", "Level", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[6].opt = GetPrivateProfileIntA("Boots", "opt", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[6].Enabled = 1;

	this->Tuong.body[7].num = GetPrivateProfileIntA("Wing", "Index", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[7].level = GetPrivateProfileIntA("Wing", "Level", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[7].opt = GetPrivateProfileIntA("Wing", "opt", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[7].Enabled = 1;

	this->Tuong.body[12].num = GetPrivateProfileIntA("Pet", "Index", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[12].level = GetPrivateProfileIntA("Pet", "Level", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[12].opt = GetPrivateProfileIntA("Pet", "opt", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.body[12].Enabled = 1;
}

void DucTuong::SaveConfig(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	int bIndex = this->Tuong.index;
	if (gObjIsConnected(bIndex) == 1)
	{
		gObjDel(bIndex);
	}

	CItem* VK1 = &lpObj->Inventory[0];
	CItem* VK2 = &lpObj->Inventory[1];
	CItem* Helm = &lpObj->Inventory[2];
	CItem* Armor = &lpObj->Inventory[3];
	CItem* Pants = &lpObj->Inventory[4];
	CItem* Gloves = &lpObj->Inventory[5];
	CItem* Boots = &lpObj->Inventory[6];
	CItem* Wing = &lpObj->Inventory[7];
	CItem* Pet = &lpObj->Inventory[12];

	char Class[20];
	char PKLevel[20];
	itoa(lpObj->DBClass, Class, 10);
	itoa(lpObj->PKCount, PKLevel, 10);

	WritePrivateProfileStringA("Setting", "Class", Class, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("Setting", "PKLevel", PKLevel, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("Setting", "Name", lpObj->Name, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	//Gen
	//char Gen[20];
	//itoa(lpObj->GensFamily, Gen, 10);
	//WritePrivateProfileStringA ("Setting","GensFamily",Gen,"..\\Data\\Custom\\\BotSystem\\DucTuong.ini");

	char num[20];
	char level[20];
	char opt[20];
	itoa(VK1->m_Index, num, 10);
	itoa(VK1->m_Level, level, 10);
	itoa(VK1->m_Option2, opt, 10);

	WritePrivateProfileStringA("VK1", "Index", num, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("VK1", "Level", level, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("VK1", "opt", opt, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");

	char num2[20];
	char level2[20];
	char opt2[20];
	itoa(VK2->m_Index, num2, 10);
	itoa(VK2->m_Level, level2, 10);
	itoa(VK2->m_Option2, opt2, 10);

	WritePrivateProfileStringA("VK2", "Index", num2, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("VK2", "Level", level2, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("VK2", "opt", opt2, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");

	char num3[20];
	char level3[20];
	char opt3[20];
	itoa(Helm->m_Index, num3, 10);
	itoa(Helm->m_Level, level3, 10);
	itoa(Helm->m_Option2, opt3, 10);

	WritePrivateProfileStringA("Helm", "Index", num3, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("Helm", "Level", level3, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("Helm", "opt", opt3, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");

	char num4[20];
	char level4[20];
	char opt4[20];
	itoa(Armor->m_Index, num4, 10);
	itoa(Armor->m_Level, level4, 10);
	itoa(Armor->m_Option2, opt4, 10);

	WritePrivateProfileStringA("Armor", "Index", num4, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("Armor", "Level", level4, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("Armor", "opt", opt4, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");

	char num5[20];
	char level5[20];
	char opt5[20];
	itoa(Pants->m_Index, num5, 10);
	itoa(Pants->m_Level, level5, 10);
	itoa(Pants->m_Option2, opt5, 10);

	WritePrivateProfileStringA("Pants", "Index", num5, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("Pants", "Level", level5, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("Pants", "opt", opt5, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");

	char num6[20];
	char level6[20];
	char opt6[20];
	itoa(Gloves->m_Index, num6, 10);
	itoa(Gloves->m_Level, level6, 10);
	itoa(Gloves->m_Option2, opt6, 10);

	WritePrivateProfileStringA("Gloves", "Index", num6, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("Gloves", "Level", level6, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("Gloves", "opt", opt6, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");

	char num7[20];
	char level7[20];
	char opt7[20];
	itoa(Boots->m_Index, num7, 10);
	itoa(Boots->m_Level, level7, 10);
	itoa(Boots->m_Option2, opt7, 10);

	WritePrivateProfileStringA("Boots", "Index", num7, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("Boots", "Level", level7, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("Boots", "opt", opt7, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");

	char num8[20];
	char level8[20];
	char opt8[20];
	itoa(Wing->m_Index, num8, 10);
	itoa(Wing->m_Level, level8, 10);
	itoa(Wing->m_Option2, opt8, 10);

	WritePrivateProfileStringA("Wing", "Index", num8, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("Wing", "Level", level8, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("Wing", "opt", opt8, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");

	char num9[20];
	char level9[20];
	char opt9[20];
	itoa(Pet->m_Index, num9, 10);
	itoa(Pet->m_Level, level9, 10);
	itoa(Pet->m_Option2, opt9, 10);

	WritePrivateProfileStringA("Pet", "Index", num9, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("Pet", "Level", level9, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	WritePrivateProfileStringA("Pet", "opt", opt9, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");

}

void DucTuong::LoadTuong(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	int bIndex = this->Tuong.index;
	if (gObjIsConnected(bIndex) == 1)
	{
		gObjDel(bIndex);
	}

	this->Enabled = GetPrivateProfileIntA("Setting", "Enabled", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.Enabled = GetPrivateProfileIntA("Setting", "Enabled", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.X = GetPrivateProfileIntA("Setting", "X", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.Y = GetPrivateProfileIntA("Setting", "Y", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.Dir = GetPrivateProfileIntA("Setting", "Dir", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");
	this->Tuong.Map = GetPrivateProfileIntA("Setting", "Map", 0, "..\\Data\\Custom\\\BotSystem\\DucTuong.ini");

	this->Tuong.Class = lpObj->DBClass;
	this->Tuong.ChangeColorName = lpObj->PKLevel;
	//this->Tuong.GensFamily = lpObj->GensFamily;
	strncpy_s(this->Tuong.Name, lpObj->Name, sizeof(this->Tuong.Name));

	CItem* VK1 = &lpObj->Inventory[0];
	CItem* VK2 = &lpObj->Inventory[1];
	CItem* Helm = &lpObj->Inventory[2];
	CItem* Armor = &lpObj->Inventory[3];
	CItem* Pants = &lpObj->Inventory[4];
	CItem* Gloves = &lpObj->Inventory[5];
	CItem* Boots = &lpObj->Inventory[6];
	CItem* Wing = &lpObj->Inventory[7];
	CItem* Pet = &lpObj->Inventory[12];

	this->Tuong.body[0].num = VK1->m_Index;
	this->Tuong.body[0].level = VK1->m_Level;
	this->Tuong.body[0].opt = VK1->m_Option2;
	this->Tuong.body[0].Enabled = 1;

	this->Tuong.body[1].num = VK2->m_Index;
	this->Tuong.body[1].level = VK2->m_Level;
	this->Tuong.body[1].opt = VK2->m_Option2;
	this->Tuong.body[1].Enabled = 1;

	this->Tuong.body[2].num = Helm->m_Index;
	this->Tuong.body[2].level = Helm->m_Level;
	this->Tuong.body[2].opt = Helm->m_Option2;
	this->Tuong.body[2].Enabled = 1;

	this->Tuong.body[3].num = Armor->m_Index;
	this->Tuong.body[3].level = Armor->m_Level;
	this->Tuong.body[3].opt = Armor->m_Option2;
	this->Tuong.body[3].Enabled = 1;

	this->Tuong.body[4].num = Pants->m_Index;
	this->Tuong.body[4].level = Pants->m_Level;
	this->Tuong.body[4].opt = Pants->m_Option2;
	this->Tuong.body[4].Enabled = 1;

	this->Tuong.body[5].num = Gloves->m_Index;
	this->Tuong.body[5].level = Gloves->m_Level;
	this->Tuong.body[5].opt = Gloves->m_Option2;
	this->Tuong.body[5].Enabled = 1;

	this->Tuong.body[6].num = Boots->m_Index;
	this->Tuong.body[6].level = Boots->m_Level;
	this->Tuong.body[6].opt = Boots->m_Option2;
	this->Tuong.body[6].Enabled = 1;

	this->Tuong.body[7].num = Wing->m_Index;
	this->Tuong.body[7].level = Wing->m_Level;
	this->Tuong.body[7].opt = Wing->m_Option2;
	this->Tuong.body[7].Enabled = 1;

	this->Tuong.body[12].num = Pet->m_Index;
	this->Tuong.body[12].level = Pet->m_Level;
	this->Tuong.body[12].opt = Pet->m_Option2;
	this->Tuong.body[12].Enabled = 1;

}
//#include "NewUIMyInventory.h"
void DucTuong::MakeBot()
{
	if (!this->Enabled) return;

	int result = gObjAddSummon();

	if (result >= 0)
	{
		this->Tuong.index = result;
		//gObj[result].DauTruongClass = 1;
		gObj[result].PosNum = (WORD)-1;
		gObj[result].X = this->Tuong.X;
		gObj[result].Y = this->Tuong.Y;
		gObj[result].OldX = this->Tuong.X;
		gObj[result].OldY = this->Tuong.Y;
		gObj[result].TX = this->Tuong.X;
		gObj[result].TY = this->Tuong.Y;
		gObj[result].MTX = this->Tuong.X;
		gObj[result].MTY = this->Tuong.Y;
		gObj[result].Dir = this->Tuong.Dir;
		gObj[result].Map = this->Tuong.Map;
		gObj[result].Live = 1;
		gObj[result].PathCount = 0;
		gObj[result].IsBot = 2;
		gObj[result].BotPower = 0;

		gObjSetBots(result, this->Tuong.Class);

		gObj[result].ChangeUp = this->Tuong.Class;
		gObj[result].Class = this->Tuong.Class;
		gObj[result].Level = 400;
		gObj[result].Life = 1;
		gObj[result].MaxLife = 2;
		gObj[result].Mana = 1;
		gObj[result].MaxMana = 2;
		gObj[result].Experience = 0;
		gObj[result].DBClass = this->Tuong.Class;
		gObj[result].PKLevel = this->Tuong.ChangeColorName;
		gObj[result].GensFamily = 0/*this->Tuong.GensFamily*/;
		gObj[result].Inventory = new CItem[INVENTORY_SIZE];
		gObj[result].Inventory1 = new CItem[INVENTORY_SIZE];
		gObj[result].InventoryMap1 = new BYTE[INVENTORY_SIZE];
		gObj[result].InventoryMap = new BYTE[INVENTORY_SIZE];
		//gObj[result].GuildNumber = 14;
		//gObj[result].GuildStatus = 0;
		//strcpy_s(gObj[result].GuildName,"AAAA");

		for (int i = 0; i<INVENTORY_SIZE; i++)
		{
			gObj[result].Inventory[i].Clear();
			gObj[result].Inventory1[i].Clear();
		}

		memset(&gObj[result].InventoryMap[0], (BYTE)-1, INVENTORY_SIZE);
		memset(&gObj[result].InventoryMap1[0], (BYTE)-1, INVENTORY_SIZE);

#if (GAMESERVER_UPDATE >= 803)
		gObj[result].MuunInventory = new CItem[MUUN_INVENTORY_SIZE];
		gObj[result].MuunInventoryMap = new BYTE[MUUN_INVENTORY_SIZE];

		for (int i = 0; i<MUUN_INVENTORY_SIZE; i++)
		{
			gObj[result].MuunInventory[i].Clear();
		}

		memset(&gObj[result].MuunInventoryMap[0], (BYTE)-1, MUUN_INVENTORY_SIZE); //novo
		//--
#endif

		//gObj[result].EquipInventory = new CItem[EQUIP_INVENTORY_SIZE];
		//gObj[result].EquipInventoryMap = new BYTE[EQUIP_INVENTORY_SIZE];

		//for (int i = 0; i<EQUIP_INVENTORY_SIZE; i++)
		//{
		//	gObj[result].EquipInventory[i].Clear();
		//}

		//memset(&gObj[result].EquipInventoryMap[0], (BYTE)-1, EQUIP_INVENTORY_SIZE); //novo

		strcpy_s(gObj[result].Name, this->Tuong.Name);

		for (int i = 0; i<9; i++)
		{
			if (this->Tuong.body[i].num >= 0 && this->Tuong.body[i].Enabled == 1)
			{
				CItem item;
				item.m_Level = this->Tuong.body[i].level;
				item.m_Option1 = 0;
				item.m_Option2 = 1;
				item.m_Option3 = this->Tuong.body[i].opt;
				item.m_Durability = 255.0f;
				item.m_JewelOfHarmonyOption = 0;
				item.m_ItemOptionEx = 0;
				item.m_SocketOption[1] = 0;
				item.m_SocketOption[2] = 0;
				item.m_SocketOption[3] = 0;
				item.m_SocketOption[4] = 0;
				item.m_SocketOption[5] = 0;
				item.Convert(this->Tuong.body[i].num, item.m_Option1, item.m_Option2, item.m_Option3, item.m_NewOption, item.m_SetOption, item.m_JewelOfHarmonyOption, item.m_ItemOptionEx, item.m_SocketOption, item.m_SocketOptionBonus);
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
		gObj[result].BotDefense = this->Tuong.OnlyVip;
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


BYTE DucTuong::gObjInventoryInsertItemPos(int aIndex, CItem item, int pos, BOOL RequestCheck) //OK
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
				return -1;
			}

		}
	}

	lpObj->Inventory[pos] = item;

	return pos;
}


void DucTuong::TuongSend(int aIndex)
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return;
	}
	LPOBJ lpObj = &gObj[aIndex];

	PMSG_DUCTUONG_SEN pRequest;
	pRequest.Head.set(0x80, 0x10, sizeof(pRequest));
	pRequest.Enabled = this->Tuong.Enabled;
	pRequest.Index = this->Tuong.index;
	memcpy(pRequest.Name, this->Tuong.Name, 11);
	DataSend(lpObj->Index, (LPBYTE)&pRequest, sizeof(pRequest));
}