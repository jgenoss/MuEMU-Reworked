#pragma once


struct SKILKTELEFIX_DATA{
	int Index;
	int IDSkill;
};


class BCustomEdit
{
public:
	BCustomEdit();
	~BCustomEdit();
	// ----
	void	Load();
	//====
	void	SkillFixData(char * FilePath);
	BOOL	CheckSkillOK(int Skill);
	//===
	// ----Mapping
	std::map<int, SKILKTELEFIX_DATA> m_SetSkillTeleFix;
private:

	// ----
}; extern BCustomEdit gBCustomEdit;