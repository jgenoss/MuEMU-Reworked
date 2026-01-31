#include "stdafx.h"
#include "BCustomEdit.h"
#include "GameMain.h"
#include "Util.h"
#include "Path.h"
#include "Util.h"

BCustomEdit gBCustomEdit;
// -------------------------------------------------------------------------------

BCustomEdit::BCustomEdit()
{

}
// -------------------------------------------------------------------------------

BCustomEdit::~BCustomEdit()
{

}
// -------------------------------------------------------------------------------

void BCustomEdit::Load()
{
	this->m_SetSkillTeleFix.clear();

	this->SkillFixData(gPath.GetFullPath("Custom\\BCustomEdit.xml")); //Fix Skill Tele

}
// -------------------------------------------------------------------------------

void BCustomEdit::SkillFixData(char * FilePath)
{

	int sk_Index = 0;
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(FilePath);
	if (res.status != pugi::status_ok){
		ErrorMessageBox("File %s load fail. Error: %s", FilePath, res.description());
		return;
	}
	//--
	pugi::xml_node oBCustomEdit = file.child("BCustomEdit");
	//--

	pugi::xml_node eSkillSuDungKhiTele = oBCustomEdit.child("SkillSuDungKhiTele");
	for (pugi::xml_node rSkillSuDungKhiTele = eSkillSuDungKhiTele.child("Skill"); rSkillSuDungKhiTele; rSkillSuDungKhiTele = rSkillSuDungKhiTele.next_sibling()){
		SKILKTELEFIX_DATA info;
		info.Index = sk_Index;
		info.IDSkill = rSkillSuDungKhiTele.attribute("IDSkill").as_int();
		this->m_SetSkillTeleFix.insert(std::pair<int, SKILKTELEFIX_DATA>(info.IDSkill, info));
		sk_Index++;
	}
}

BOOL BCustomEdit::CheckSkillOK(int Skill) //Get Skill Co trong Data hay khong
{
	std::map<int, SKILKTELEFIX_DATA>::iterator it = this->m_SetSkillTeleFix.find(Skill);
	if (it == this->m_SetSkillTeleFix.end())
	{
		return TRUE;
	}
	return FALSE;
}

