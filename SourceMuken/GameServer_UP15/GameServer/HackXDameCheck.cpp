// HackXDameCheck.cpp: implementation of the CHackXDameCheck class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CommandManager.h"
#include "HackXDameCheck.h"
#include "GensSystem.h"
#include "Map.h"
#include "MapManager.h"
#include "MemScript.h"
#include "Message.h"
#include "Notice.h"
#include "ServerInfo.h"
#include "Util.h"
#include "Log.h"
//
#include "EffectManager.h"

CHackXDameCheck gHackXDameCheck;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CHackXDameCheck::CHackXDameCheck() // OK
{
	this->m_HackXDameInfo.clear();
}

CHackXDameCheck::~CHackXDameCheck() // OK
{

}

void CHackXDameCheck::Load(char* path) // OK
{
	CMemScript* lpMemScript = new CMemScript;

	if (lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR, path);
		return;
	}

	if (lpMemScript->SetBuffer(path) == 0)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	this->m_HackXDameInfo.clear();

	int count = 0;

	try
	{
		while (true)
		{
			if (lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if (strcmp("end", lpMemScript->GetString()) == 0)
			{
				break;
			}

			HACK_XDAME_INFO info;

			info.Index = count;

			info.MinSpeed = lpMemScript->GetNumber();

			info.MaxSpeed = lpMemScript->GetAsNumber();

			info.Delay = lpMemScript->GetAsNumber();

			info.MaxCount = lpMemScript->GetAsNumber();

			this->m_HackXDameInfo.insert(std::pair<int, HACK_XDAME_INFO>(info.Index, info));

			count++;
		}
	}
	catch (...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

bool CHackXDameCheck::GetInfo(int index, HACK_XDAME_INFO* lpInfo) // OK
{
	std::map<int, HACK_XDAME_INFO>::iterator it = this->m_HackXDameInfo.find(index);

	if (it == this->m_HackXDameInfo.end())
	{
		return 0;
	}
	else
	{
		(*lpInfo) = it->second;
		return 1;
	}
}

bool CHackXDameCheck::GetInfoByXDame(int Speed, HACK_XDAME_INFO* lpInfo) // OK
{
	for (std::map<int, HACK_XDAME_INFO>::iterator it = this->m_HackXDameInfo.begin(); it != this->m_HackXDameInfo.end(); it++)
	{
		if (Speed >= it->second.MinSpeed && (Speed <= it->second.MaxSpeed || it->second.MaxSpeed == -1))
		{
			(*lpInfo) = it->second;
			return 1;
		}
	}

	return 0;
}

bool CHackXDameCheck::CheckXDameHack(LPOBJ lpObj, int skill) // OK
{
	if (gServerInfo.m_XdameHackSkillEnable != 1)
	{
		return 0;
	}

	HACK_XDAME_INFO HackXDameInfo;

	if (this->GetInfoByXDame(lpObj->PhysiSpeed, &HackXDameInfo) == 0)
	{
		return 0;
	}

	//LogAdd(LOG_RED,"Skill DL = %d", skill);

	/*if(lpObj->XdameHackSkill != skill)		// fix ẩn xdame
	{
	lpObj->XdameHackSkill = skill;
	lpObj->XdameHackCount = 0;
	lpObj->XdameHackDelay = GetTickCount();
	lpObj->XdameHackDialog = 0;
	}*/

	//if(skill == 235 || skill ==24 || skill == 418)
	if ((lpObj->DBClass == DB_CLASS_FE) || (lpObj->DBClass == DB_CLASS_ME) || (lpObj->DBClass == DB_CLASS_HE) || skill == 78 || skill == 518 || skill == 238)
	{
		HackXDameInfo.MaxCount = HackXDameInfo.MaxCount * 2.5;
	}

	if (gServerInfo.m_XdameHackSkillDebug == 1)
	{
		//LogAdd(LOG_RED,"Count / MaxCount :  %d/ %d", lpObj->XdameHackCount, HackXDameInfo.MaxCount);
		/*LogAdd(LOG_RED,"Type: %d", gServerInfo.m_XdameHackSkillType);
		LogAdd(LOG_RED,"Dialog: %d", lpObj->XdameHackDialog);*/
	}

	if (lpObj->XdameHackCount > HackXDameInfo.MaxCount)
	{
		if (lpObj->XdameHackDialog == 0)
		{
			//LogAdd(LOG_RED,"[XdameHackDetected][%s][%s] Skill: %d",lpObj->Account,lpObj->Name,skill);

			if (gServerInfo.m_XdameHackSkillDialog == 1)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(843));
				//LogAdd(LOG_RED,"[XdameHackDetected][%s][%s] Skill: %d",lpObj->Account,lpObj->Name,skill);
			}
			lpObj->XdameHackDialog = 1;
		}

		if (gServerInfo.m_XdameHackSkillType == 1)
		{
			GCCloseClientSend(lpObj->Index, 0);
			//gLog.Output(HACK_D,
			return 1;

		}
		else if (gServerInfo.m_XdameHackSkillType == 2)
		{
			if (gServerInfo.m_XdameHackSkillDialog == 1)
			{
				gEffectManager.AddEffect(lpObj, 0, 61, gServerInfo.m_timedongbang, 0, 0, 0, 0);
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "[MuSolar] Bạn đang sử dụng skill quá nhanh, Vô hiệu hóa tấn công !");
			}
			return 1;

		}
		else if (gServerInfo.m_XdameHackSkillType == 3)
		{
			if (GetTickCount() > (lpObj->XdameHackDelay + HackXDameInfo.Delay + (DWORD)gServerInfo.m_XdameHackSkillPenalty))
			{
				lpObj->XdameHackCount = 0;
				lpObj->XdameHackDelay = GetTickCount();
				lpObj->XdameHackDialog = 0;
				if (gServerInfo.m_XdameHackSkillDialog == 1)
				{
					gEffectManager.AddEffect(lpObj, 0, 61, gServerInfo.m_timedongbang, 0, 0, 0, 0);
					gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "[MuSolar] Bạn đang sử dụng skill quá nhanh, Vô hiệu hóa tấn công!"/*, gServerInfo.m_XdameHackSkillPenalty*/);
				}
			}
			return 1;
		}
		else
		{
			if (GetTickCount() > (lpObj->XdameHackDelay + HackXDameInfo.Delay))
			{
				lpObj->XdameHackCount = 0;
				lpObj->XdameHackDelay = GetTickCount();
			}
		}
		return 0;

	}

	if (GetTickCount() < (lpObj->XdameHackDelay + HackXDameInfo.Delay))
	{
		lpObj->XdameHackCount++;
		return 0;
	}
	else
	{
		if (gServerInfo.m_XdameHackSkillDebug == 1)
		{
			//LogAdd(LOG_RED,"[XdameHackTeste] Skill: %d | AttackSpeed: %d | Count: %d",skill,lpObj->PhysiSpeed,lpObj->XdameHackCount);
			//LogAdd(LOG_RED,"%d/%d", lpObj->XdameHackCount, HackXDameInfo.MaxCount);
		}
	}

	lpObj->XdameHackCount = 0;
	lpObj->XdameHackDelay = GetTickCount();

	return 0;
}