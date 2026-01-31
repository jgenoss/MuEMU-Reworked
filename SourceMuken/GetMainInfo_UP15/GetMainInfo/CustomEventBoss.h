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
	void Init();
	void Load(char* FilePath);
public:
	EventGroupData	m_EventData[MAX_CUSTOM_EVENTBOSS];
	InfoTextData	m_InfoTextData[MAX_DATA_INFOTEXT];
	InfoRewardData	m_InfoRewardData[MAX_DATA_INFOREWARD];
	void cCustomEventBoss::SetInfoReward(InfoRewardData info);
	void cCustomEventBoss::SetInfoText(InfoTextData info);
	void cCustomEventBoss::SetInfoEvent(EventGroupData info);
}; extern cCustomEventBoss gCustomEventBoss;