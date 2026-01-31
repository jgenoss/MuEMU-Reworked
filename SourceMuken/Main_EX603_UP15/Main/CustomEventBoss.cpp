#include "stdafx.h"
#include "Defines.h"
#include "Import.h"
#include "CustomEventBoss.h"

cCustomEventBoss gCustomEventBoss;

cCustomEventBoss::cCustomEventBoss() // OK
{
	this->m_EventData.clear();
	this->m_InfoTextData.clear();
	this->m_InfoRewardData.clear();
}

cCustomEventBoss::~cCustomEventBoss() // OK
{

}

void cCustomEventBoss::LoadEventData(EventGroupData* info) // OK
{
	for (int n = 0; n < MAX_CUSTOM_EVENTBOSS; n++)
	{
		if (info[n].Index < 0 || info[n].Index >= MAX_CUSTOM_EVENTBOSS)
		{
			return;
		}
		this->m_EventData.insert(std::pair<int, EventGroupData>(info[n].Group, info[n]));
	}
}

void cCustomEventBoss::LoadInfoTextData(InfoTextData* info) // OK
{
	for (int n = 0; n < MAX_DATA_INFOTEXT; n++)
	{
		if (info[n].Index < 0 || info[n].Index >= MAX_DATA_INFOTEXT)
		{
			return;
		}
		this->m_InfoTextData.insert(std::pair<int, InfoTextData>(info[n].TypeInfo, info[n]));
	}
}

void cCustomEventBoss::LoadInfoRewardData(InfoRewardData* info) // OK
{
	for (int n = 0; n < MAX_DATA_INFOREWARD; n++)
	{
		if (info[n].Index < 0 || info[n].Index >= MAX_DATA_INFOREWARD)
		{
			return;
		}
		this->m_InfoRewardData.insert(std::pair<int, InfoRewardData>(info[n].TypeListItem, info[n]));
	}
}