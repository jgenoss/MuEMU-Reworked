// CustomStartItem.h: interface for the CustomStartItem class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#define MAX_CLASS 7


struct CUSTOM_START_ITEM_DAME_INFO
{
	int ItemType;
	int ItemIndex;
	int ItemLevel;
	int ItemDurability;
	int ItemSkill;
	int ItemLuck;
	int ItemOption;
	int ItemExcellent;
	int TypeBuff;
	int EffectBuff;
	int DupeDame;
	int TripDame;
	int DameRate;
	int DefDameRate;
	int Power1Buff;
	int Power2Buff;
	int TimeBuff;
};

struct CustomStartItemDame_INFO
{
	int Class;
	std::vector<CUSTOM_START_ITEM_DAME_INFO> ItemDameStart;
};


class CCustomStartItemDame
{
public:
	CCustomStartItemDame();
	virtual ~CCustomStartItemDame();
	void Init();
	void LoadItemDame(char* path);
	void SetInfo(CustomStartItemDame_INFO infoDame);
	bool CheckSkillEffectDame(int m_index);
	void CaclCharacter(LPOBJ lpObj, bool flag);
	//void GiftItemDame(LPOBJ lpObj);
public:
	CustomStartItemDame_INFO m_CustomStartItemDameInfo[MAX_CLASS];
};

extern CCustomStartItemDame gCustomStartItemDame;
