#pragma once

#include "User.h"

#define MAX_MONSTER_REWARD		1024

struct MONSTER_REWARD_INFO
{
	DWORD	MonsterID;
	int		MapNumber;
	int		AddCoinC;
	int		AddCoinP;
	int		AddGoblinP;
};


class CMonsterReward
{
public:
	CMonsterReward();
	virtual~CMonsterReward();
	void	Init();
	void	Load(char* path);
	int		GetMonsterSlot(int Class, int Map);
	void	AddMonsterBonus(LPOBJ lpObj, LPOBJ lpTarget);
	void	AddMonsterBonusPCPoint(int aIndex, int MonsterIndex);	
public:
	bool	m_IsLoaded;
	int		m_MonsterLoaded;

	std::vector<MONSTER_REWARD_INFO> m_MobsData;

}; extern CMonsterReward gMonsterReward;