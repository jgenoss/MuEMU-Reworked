#include "StdAfx.h"
#include "MonsterReward.h"
#include "user.h"
#include "MemScript.h"
#include "Util.h"
#include "CashShop.h"
#include "Monster.h"
#include "Notice.h"
#include "Message.h"
#include "DSProtocol.h"
#include "GameMain.h"

CMonsterReward gMonsterReward;

CMonsterReward::CMonsterReward()
{
	this->Init();
}

CMonsterReward::~CMonsterReward()
{
}

void CMonsterReward::Init()
{
	this->m_IsLoaded			= false;
	this->m_MonsterLoaded		= 0;
	this->m_MobsData.clear();
}

void CMonsterReward::Load(char* path)
{
	CMemScript* lpMemScript = new CMemScript;

	if(lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR,path);
		return;
	}

	if(lpMemScript->SetBuffer(path) == 0)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	for(int n=0;n < MAX_MONSTER_REWARD;n++)
	{
		this->Init();
	}
	
	try
	{
		while(true)
		{
			if(lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}
		
			int section = lpMemScript->GetNumber();

			while(true)
			{
				if(section == 0)
				{
					if(strcmp("end",lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					MONSTER_REWARD_INFO info;

					info.Type = lpMemScript->GetNumber();

					info.Index = lpMemScript->GetAsNumber();

					info.Effect = lpMemScript->GetAsNumber();

					info.Dame = lpMemScript->GetAsNumber();

					info.Time = lpMemScript->GetAsNumber();

					this->m_MobsData.push_back(info);
				}
				else
				{
					break;
				}
			}
		}
	}
	catch(...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
	this->m_IsLoaded = true;
}

int CMonsterReward::GetMonsterSlot(int Class, int Map)
{
	for( int i = 0; i < this->m_MobsData.size(); i++ )
	{
		if( this->m_MobsData[i].MonsterID != Class )
		{
			continue;
		}
		if( this->m_MobsData[i].MapNumber != Map && this->m_MobsData[i].MapNumber != -1 )
		{
			continue;
		}
		return i;
	}
	return -1;
}

void CMonsterReward::AddMonsterBonus(LPOBJ lpMonster, LPOBJ lpObj)
{
	if( !this->m_IsLoaded )
	{
		return;
	}
	int MonsterSlot = this->GetMonsterSlot(gObj[lpMonster->Index].Class, gObj[lpMonster->Index].Map);
	if( MonsterSlot == -1 )
	{
		return;
	}

	int aIndex = gObjMonsterGetTopHitDamageUser(lpObj);

	if(OBJECT_RANGE(aIndex) != 0)
	{
		lpObj = &gObj[aIndex];
	}

	GDSetCoinSend(lpObj->Index, this->m_MobsData[MonsterSlot].AddCoinC, this->m_MobsData[MonsterSlot].AddCoinP, this->m_MobsData[MonsterSlot].AddGoblinP, "Monster Reward");
}
