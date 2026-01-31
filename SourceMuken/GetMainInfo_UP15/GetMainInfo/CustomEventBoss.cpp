#include "stdafx.h"
#include "CustomEventBoss.h"
#include "MemScript.h"

cCustomEventBoss gCustomEventBoss;

cCustomEventBoss::cCustomEventBoss() // OK
{
	this->Init();
}

cCustomEventBoss::~cCustomEventBoss() // OK
{

}

void cCustomEventBoss::Init() // OK
{
	for (int n = 0; n < MAX_CUSTOM_EVENTBOSS; n++)
	{
		this->m_EventData[n].Index = -1;
		this->m_EventData[n].Enable = 0;
	}
	for (int n = 0; n < MAX_DATA_INFOTEXT; n++)
	{
		this->m_InfoTextData[n].Index = -1;
	}
	for (int n = 0; n < MAX_DATA_INFOREWARD; n++)
	{
		this->m_InfoRewardData[n].Index = -1;
	}
}
void cCustomEventBoss::SetInfoReward(InfoRewardData info) // OK
{
	if (info.Index < 0 || info.Index >= MAX_DATA_INFOREWARD)
	{
		return;
	}

	this->m_InfoRewardData[info.Index] = info;
}
void cCustomEventBoss::SetInfoText(InfoTextData info) // OK
{
	if (info.Index < 0 || info.Index >= MAX_DATA_INFOTEXT)
	{
		return;
	}

	this->m_InfoTextData[info.Index] = info;
}
void cCustomEventBoss::SetInfoEvent(EventGroupData info) // OK
{
	if (info.Index < 0 || info.Index >= MAX_CUSTOM_EVENTBOSS)
	{
		return;
	}

	this->m_EventData[info.Index] = info;
}
void cCustomEventBoss::Load(char* FilePath) // OK
{
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(FilePath);
	if (res.status != pugi::status_ok) 
	{
		CMemScript* lpMemScript = new CMemScript;
		lpMemScript->ErrorMessageBox("File %s load fail. Error: %s", FilePath, res.description());
		return;
	}
	//--Data Reward
	pugi::xml_node oDataInfoReward = file.child("DataInfoReward");

	for (pugi::xml_node rInfoReward = oDataInfoReward.child("InfoReward"); rInfoReward; rInfoReward = rInfoReward.next_sibling())
	{
		int RCount = 0;
		InfoRewardData info = { 0 };
		static int CustomIndexInfoReward = 0;

		info.Index = CustomIndexInfoReward++;
		info.TypeListItem = rInfoReward.attribute("TypeListItem").as_int();
		//= Mess Load
		for (pugi::xml_node rRList = rInfoReward.child("List"); rRList; rRList = rRList.next_sibling())
		{
			info.InfoRewardList[RCount].IndexItem = rRList.attribute("IndexItem").as_int();
			info.InfoRewardList[RCount].Level = rRList.attribute("Level").as_int();
			info.InfoRewardList[RCount].Scale = rRList.attribute("Scale").as_float();
			RCount++;
			if (RCount > MAX_DATA_INFOREWARDLIST) break;
		}

		SetInfoReward(info);
		std::cout << "rInfoReward " << CustomIndexInfoReward <<"\n";
	}
	//--Data Text
	pugi::xml_node oDataInfoText = file.child("DataInfoText");
	for (pugi::xml_node rInfoText = oDataInfoText.child("InfoText"); rInfoText; rInfoText = rInfoText.next_sibling())
	{
		int TCount = 0;
		InfoTextData infoData = { 0 };
		static int CustomIndexInfoText = 0;

		infoData.Index = CustomIndexInfoText++;
		infoData.TypeInfo = rInfoText.attribute("TypeInfo").as_int();
		//= Mess Load
		for (pugi::xml_node rTextList = rInfoText.child("List"); rTextList; rTextList = rTextList.next_sibling())
		{
			infoData.InfoTextList[TCount].Index = rTextList.attribute("Index").as_int();
			strncpy_s(infoData.InfoTextList[TCount].Text, rTextList.attribute("Text").as_string(), sizeof(infoData.InfoTextList[TCount].Text));
			TCount++;
			if (TCount > MAX_DATA_INFOTEXTLIST) break;
		}
		SetInfoText(infoData);
		std::cout << "rInfoText " << CustomIndexInfoText << "\n";
	}

	//--EventData
	pugi::xml_node oEventBossData = file.child("EventBossData");
	for (pugi::xml_node Event = oEventBossData.child("Event"); Event; Event = Event.next_sibling())
	{
		int ECount = 0;
		EventGroupData infoEvent = { 0 };
		static int CustomIndexInfoEvent = 0;

		infoEvent.Index = CustomIndexInfoEvent++;
		infoEvent.Group = Event.attribute("Group").as_int();
		infoEvent.Enable = Event.attribute("Enable").as_int();
		strncpy_s(infoEvent.TextButton, Event.attribute("Text").as_string(), sizeof(infoEvent.TextButton));
		//= Mess Load
		pugi::xml_node rBossList = Event.child("BossList");
		for (pugi::xml_node rEventList = rBossList.child("List"); rEventList; rEventList = rEventList.next_sibling())
		{
			infoEvent.DataBoss[ECount].IDBoss = rEventList.attribute("IDBoss").as_int();
			infoEvent.DataBoss[ECount].Size = rEventList.attribute("Size").as_float();
			infoEvent.DataBoss[ECount].GateMove = rEventList.attribute("GateMove").as_int();
			infoEvent.DataBoss[ECount].TypeListItem = rEventList.attribute("TypeListItem").as_int();
			infoEvent.DataBoss[ECount].TypeInfo = rEventList.attribute("TypeInfo").as_int();
			ECount++;
			if (ECount > MAX_DATA_BOSS) break;
		}
		SetInfoEvent(infoEvent);
		std::cout << "infoEvent " << CustomIndexInfoEvent << "\n";
	}
}