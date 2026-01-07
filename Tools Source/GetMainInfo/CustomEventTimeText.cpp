// CustomEventTimeText.cpp: implementation of the CCustomEventTimeText class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CustomEventTimeText.h"
#include "MemScript.h"

CCustomEventTimeText gCustomEventTimeText;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomEventTimeText::CCustomEventTimeText()
{
	this->Init();
}

CCustomEventTimeText::~CCustomEventTimeText()
{
}

void CCustomEventTimeText::Init()
{
	for (int n = 0; n < MAX_EVENTTIME; n++)
	{
		this->m_CustomEventInfo[n].Index = -1;
		memset(this->m_CustomEventInfo[n].Name, 0, sizeof(this->m_CustomEventInfo[n].Name));
	}
}

void CCustomEventTimeText::Load(char* path)
{
	CMemScript* lpMemScript = new CMemScript;

	if (lpMemScript->SetBuffer(path) == 0)
	{
		printf(MEM_SCRIPT_ERROR_CODE0, path);
		delete lpMemScript;
		return;
	}

	this->Init();

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

		CUSTOM_EVENT_INFO info;
		memset(&info, 0, sizeof(info));

		info.Index = lpMemScript->GetNumber();

		lpMemScript->GetToken();
		strcpy_s(info.Name, lpMemScript->GetString());

		this->SetInfo(info);
	}

	delete lpMemScript;

	printf("[CustomEventTimeText] Loaded %s\n", path);
}

void CCustomEventTimeText::SetInfo(CUSTOM_EVENT_INFO info)
{
	if (info.Index < 0 || info.Index >= MAX_EVENTTIME)
	{
		return;
	}

	this->m_CustomEventInfo[info.Index] = info;
}
