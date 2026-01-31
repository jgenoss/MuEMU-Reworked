#include "stdafx.h"
#include "PartySetPass.h"
#include "Util.h"
#include "Party.h"
#include "DefaultClassInfo.h"
#include "Notice.h"
#include "Guild.h"
#include "MapManager.h"
#include "Message.h"


#if(PARTYSETPASS)
CPartySetPass gPartySetPass;

CPartySetPass::CPartySetPass()
{
	this->m_Registered.clear();
}

CPartySetPass::~CPartySetPass()
{

}

void CPartySetPass::PartySetPassSearchAddToList(PMSG_RECV_SETPASS_ADD lpMsg, int aIndex)
{
	LPOBJ lpTarget = gObjFind(gObj[aIndex].Name);

	if (gParty.IsParty(lpTarget->PartyNumber) == 1 && gParty.IsLeader(lpTarget->PartyNumber, lpTarget->Index) == 0) {
		gNotice.GCNoticeSend(lpTarget->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(1018));
		return;
	}

	REGISTERED_INFO_SETPASS info;

	memcpy(info.Name, gObj[aIndex].Name, sizeof(info.Name));
	info.aIndex = aIndex;

	memcpy(info.Password, lpMsg.Password, sizeof(info.Password));

	if (lpMsg.SystemActive == true)
	{
		std::string nme(info.Name);

		std::transform(nme.begin(), nme.end(), nme.begin(), tolower);

		std::map<std::string, REGISTERED_INFO_SETPASS>::iterator it = this->m_Registered.find(nme);

		info.IsOnline = true;

		if (it == this->m_Registered.end())
		{
			this->m_Registered.insert(std::pair<std::string, REGISTERED_INFO_SETPASS>(nme, info));
			gNotice.GCNoticeSend(gObj[aIndex].Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(1001), lpMsg.Password);
		}
		else
		{
			it->second = info;
		}
	}
	else
	{
		std::string nme(info.Name);

		std::transform(nme.begin(), nme.end(), nme.begin(), tolower);

		std::map<std::string, REGISTERED_INFO_SETPASS>::iterator it = this->m_Registered.find(nme);

		if (it != this->m_Registered.end())
		{
			this->m_Registered.erase(it);
		}

		//gNotice.GCNoticeSend(gObj[aIndex].Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(1018));
	}
}

void CPartySetPass::PartySetPassSearchDelFromList(char* Name)
{
	std::string nme(Name);

	std::transform(nme.begin(), nme.end(), nme.begin(), tolower);

	std::map<std::string, REGISTERED_INFO_SETPASS>::iterator it = this->m_Registered.find(nme);

	if (it != this->m_Registered.end())
	{
		this->m_Registered.erase(it);
	}
}

void CPartySetPass::RequestParty(PMSG_PARTY_SETPASS_REQ_REQ_SETPASS lpMsg, int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];
	LPOBJ lpTarget = gObjFind(lpMsg.Name);

	if (lpTarget == 0)
	{
		return;
	}
#if(CHONPHEDOILAP)
	if (!CheckChonPhe(lpObj->Index, lpTarget->Index))
	{
		return;
	}
#endif
	std::string name(lpTarget->Name);

	std::transform(name.begin(), name.end(), name.begin(), tolower);

	std::map<std::string, REGISTERED_INFO_SETPASS>::iterator info = this->m_Registered.find(name);

	if (info == this->m_Registered.end())
	{
		return;
	}

	if (strcmp(info->second.Password, lpMsg.Password) != 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(1002));
		return;
	}


	if (lpObj->PartyNumber >= 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(1003));
		return;
	}

	if (!strcmp(lpObj->Name, lpTarget->Name))
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(1004));
		return;
	}

	if (lpTarget->PartyNumber >= 0)
	{
		if (lpObj->PartyNumber == lpTarget->PartyNumber)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(1005));
			return;
		}
	}

	if (gParty.Create(lpTarget->Index) == 0)
	{
		if (gParty.AddMember(lpTarget->PartyNumber, lpObj->Index) == 0)
		{
			gParty.GCPartyResultSend(lpObj->Index, 2);
			gParty.GCPartyResultSend(lpTarget->Index, 2);
		}
	}
	else
	{
		if (gParty.AddMember(lpTarget->PartyNumber, lpObj->Index) == 0)
		{
			gParty.GCPartyResultSend(lpObj->Index, 2);
			gParty.GCPartyResultSend(lpTarget->Index, 2);
			gParty.Destroy(lpTarget->PartyNumber);
		}
	}
}
#endif