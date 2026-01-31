#include "stdafx.h"
#include "CustomNameColor.h"
#include "MemScript.h"

cCustomNameColor gCustomNameColor;

cCustomNameColor::cCustomNameColor()
{
	
}

cCustomNameColor::~cCustomNameColor()
{

}

void cCustomNameColor::Init()
{
	for (int n = 0; n < MAX_CUSTOM_NAMECOLOR; n++)
	{
		this->m_CustomNameColor[n].Index = -1;
	}
}
void cCustomNameColor::Load(char* path) // OK
{
	CMemScript* lpMemScript = new CMemScript;

	if(lpMemScript == 0)
	{
		printf(MEM_SCRIPT_ALLOC_ERROR,path);
		return;
	}

	if(lpMemScript->SetBuffer(path) == 0)
	{
		printf(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	this->Init();

	try
	{
		while(true)
		{
			if(lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}
			if(strcmp("end",lpMemScript->GetString()) == 0)
			{
				break;
			}

			NAMECOLOR_DATA_INFO info;

			memset(&info,0,sizeof(info));

			static int CustomIndexCount = 0;

			info.Index = lpMemScript->GetNumber();

			info.ItemIndex = lpMemScript->GetNumber();

			info.Color = lpMemScript->GetAsNumber();

			//strcpy_s(info.Color,lpMemScript->GetAsString());

			this->SetInfo(info);
		}
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void cCustomNameColor::SetInfo(NAMECOLOR_DATA_INFO info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOM_NAMECOLOR)
	{
		return;
	}

	this->m_CustomNameColor[info.Index] = info;
}