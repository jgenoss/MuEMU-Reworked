#pragma once

#include "Protocol.h"
#if(PARTYSETPASS)

struct PMSG_RECV_SETPASS_ADD
{
	PSBMSG_HEAD header;
	bool SystemActive;
	char Password[20];
};

struct PMSG_SEND_PARTYLIST_SETPASS
{
	PSWMSG_HEAD header;
	int Count;
};

struct PMSG_PARTYLIST_SETPASS
{
	char Name[11];
	int Map;
	int X;
	int Y;
	bool RequirePassword;
	int Count;
};

struct PMSG_PARTYSETTINGS_SEND_SETPASS
{
	PSBMSG_HEAD header;
	bool SystemActive;
	bool RequiredPassword;
	char Password[20];
};

struct PMSG_PARTY_SETPASS_REQ_REQ_SETPASS
{
	PSBMSG_HEAD header;
	char Name[11];
	bool RequirePassword;
	char Password[20];
};

struct REGISTERED_INFO_SETPASS
{
	char Name[11];
	int aIndex;
	BYTE IsOnline;
	bool RequirePassword;
	char Password[20];
};

class CPartySetPass
{
public:
	CPartySetPass();
	~CPartySetPass();

	void PartySetPassSearchAddToList(PMSG_RECV_SETPASS_ADD lpMsg, int aIndex);
	void PartySetPassSearchDelFromList(char* Name);
	void RequestParty(PMSG_PARTY_SETPASS_REQ_REQ_SETPASS lpMsg, int aIndex);
	// ----
	std::map<std::string, REGISTERED_INFO_SETPASS> m_Registered;
}; extern CPartySetPass gPartySetPass;
#endif