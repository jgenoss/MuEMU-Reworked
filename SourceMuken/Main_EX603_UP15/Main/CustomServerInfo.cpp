#include "stdafx.h"
#include "CustomServerInfo.h"
#include "Util.h"
#include "TMemory.h"
#include "Defines.h"
#include "Import.h"
#include "ReadScript.h"


CMSGServerInfo g_MSGServerInfo;

CMSGServerInfo::CMSGServerInfo()
{
	this->m_data.clear();
}

CMSGServerInfo::~CMSGServerInfo()
{
}

void CMSGServerInfo::Load()
{
	//00953CFC - hook
	this->m_data.clear();

	this->Read("Data/Custom/ServerListInfo.txt");

	SetOp((LPVOID)0x009540B8, this->ServerDrawTextHook, ASM::CALL); //1.04E
	SetOp((LPVOID)0x009540EE, this->ServerDrawTextHook, ASM::CALL); //1.04E
	SetOp((LPVOID)0x00954121, this->ServerDrawTextHook, ASM::CALL); //1.04E
	SetOp((LPVOID)0x00954154, this->ServerDrawTextHook, ASM::CALL); //1.04E
}

void CMSGServerInfo::Read(char* filename)
{
	SMDToken Token;

	SMDFile = fopen(filename, "r");

	if (!SMDFile)
	{
		return;
	}

	while (true)
	{
		Token = GetToken();

		if (Token == END || !strcmp(TokenString, "end"))
		{
			break;
		}

		SERVERINFO_DATA list;

		memcpy(list.ServerName, TokenString, sizeof(list.ServerName));

		Token = GetToken();
		list.SubServerNum = TokenNumber;

		Token = GetToken();
		memcpy(list.ServerText, TokenString, sizeof(list.ServerText));

		this->m_data.push_back(list);
	}

	fclose(SMDFile);
}

void CMSGServerInfo::ServerDrawTextHook(int a1, char* a2, char* ServerName, int SubServerNum, char* TextConnect)
{
	for (int i = 0; i < g_MSGServerInfo.m_data.size(); i++)
	{
		if (!strcmp(ServerName, g_MSGServerInfo.m_data[i].ServerName))
		{
			if (SubServerNum == g_MSGServerInfo.m_data[i].SubServerNum)
			{
				pSetItemTextLine(a1, g_MSGServerInfo.m_data[i].ServerText);
				return;
			}
		}
	}

	pSetItemTextLine(a1, a2, ServerName, SubServerNum, TextConnect);


}