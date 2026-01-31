#pragma once

#include "StdAfx.h"
#include "Protocol.h"

#if(BUFF_SET_ICON)

struct CustomStartSetItemDame_Data
{
	int ItemType;
	int ItemIndex;
	int Effect;
	int Level;
	int Option;
	int Dame;
	int IncSD;
	int IncLife;
	int IncMana;
	int Defense;

	int ExcellentDamageRate;
	int CriticalDamageRate;
	int DoubleDamageRate;
	int IncResistDoubleDamage;
	int IncResistIgnoreDefense;
	int IncResistIgnoreSD;
	int IncResistCriticalDamage;
	int IncResisteExcellentDamage;
	int IncBlockStuck;
	int IncReflectRate;
	int Time;
};


class CCustomStartSetItemDame
{
public:
	CCustomStartSetItemDame();
	~CCustomStartSetItemDame();
	void Init();
	void Load();
	void Read(char* filename);
	void CalcCustomSetItemOption(LPOBJ lpObj, bool flag);
	std::vector<CustomStartSetItemDame_Data> itemdata;
};
extern CCustomStartSetItemDame gCustomStartSetItemDame;

#endif