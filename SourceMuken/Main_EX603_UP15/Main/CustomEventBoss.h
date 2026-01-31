#pragma once
#define MAX_CUSTOM_EVENTBOSS			30
#define MAX_DATA_BOSS					20

#define MAX_DATA_INFOTEXT				20
#define MAX_DATA_INFOTEXTLIST			20

#define MAX_DATA_INFOREWARD				20
#define MAX_DATA_INFOREWARDLIST			20



struct InfoTextDataList
{
	int Index;
	char Text[256];
};

struct InfoTextData
{
	int Index;
	int TypeInfo;
	InfoTextDataList InfoTextList[MAX_DATA_INFOTEXTLIST];
};

struct InfoRewardDataList
{
	int IndexItem;
	int Level;
	float Scale;

};

struct InfoRewardData
{
	int Index;
	int TypeListItem;
	InfoRewardDataList InfoRewardList[MAX_DATA_INFOREWARDLIST];
};
struct ListBossData
{
	int IDBoss;
	float Size;
	int GateMove;
	int TypeListItem;
	int TypeInfo;
	
};

struct EventGroupData
{
	int Index;
	int Group;
	int Enable;
	char TextButton[99];
	ListBossData DataBoss[MAX_DATA_BOSS];
};

class cCustomEventBoss
{
public:
	cCustomEventBoss();
	virtual ~cCustomEventBoss();
public:

	std::map<int, EventGroupData> m_EventData;
	std::map<int, InfoTextData> m_InfoTextData;
	std::map<int, InfoRewardData> m_InfoRewardData;

	void cCustomEventBoss::LoadEventData(EventGroupData* info);
	void cCustomEventBoss::LoadInfoTextData(InfoTextData* info);
	void cCustomEventBoss::LoadInfoRewardData(InfoRewardData* info);
}; extern cCustomEventBoss gCustomEventBoss;