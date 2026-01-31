#pragma once

#define MAX_CUSTOMMONSTER 200
#define MAX_BOSSCLASS  20
struct CUSTOMMONSTER_DATA
{
	int Index;
	WORD ID;
	BYTE Type;
	char Name[25];
	char Dir[50];
	char Folder[50];
	char BMDFile[50];
	float Size;
};

struct BOSSCLASS_DATA
{
	int Index;
	WORD ID;
	char Name[25];
	int IndexSet;
	int IndexTayPhai;
	int IndexTayTrai;
	int IndexWing;
	float Size;
};
class cCustomMonsters
{
public:
	cCustomMonsters();
	virtual ~cCustomMonsters();
	void Init();
	void Load(char* path);
	void SetInfo(CUSTOMMONSTER_DATA info);
	void SetInfoBossClass(BOSSCLASS_DATA info);
public:
	CUSTOMMONSTER_DATA m_Monsters[MAX_CUSTOMMONSTER];
	BOSSCLASS_DATA m_BossClass[MAX_BOSSCLASS];
}; extern cCustomMonsters gMonsters;