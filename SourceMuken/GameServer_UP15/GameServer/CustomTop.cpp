#include "stdafx.h"
#include "CommandManager.h"
#include "CustomTop.h"
#include "Log.h"
#include "MemScript.h"
#include "Message.h"
#include "Notice.h"
#include "Util.h"

CCustomTop gCustomTop;

CCustomTop::CCustomTop(){
	this->m_CustomTopInfo.clear();
}

CCustomTop::~CCustomTop(){

}

void CCustomTop::Load(char* path){
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(path);
	if (res.status != pugi::status_ok){
		ErrorMessageBox("File %s load fail. Error: %s", path, res.description());
		return;
	}
	this->m_CustomTopInfo.clear();
	pugi::xml_node CustomTop = file.child("CustomTop");
	for (pugi::xml_node top = CustomTop.child("Top"); top; top = top.next_sibling()){
		CUSTOMTOP_INFO info;
		info.Index = top.attribute("Index").as_int();
		strcpy_s(info.Name, top.attribute("Command").as_string());
		strcpy_s(info.Title, top.attribute("Title").as_string());
		this->m_CustomTopInfo.insert(std::pair<int, CUSTOMTOP_INFO>(info.Index, info));
	}
}

bool CCustomTop::GetInfo(int index, CUSTOMTOP_INFO* lpInfo){
	std::map<int, CUSTOMTOP_INFO>::iterator it = this->m_CustomTopInfo.find(index);
	if (it == this->m_CustomTopInfo.end()){
		return 0;
	}
	else{
		(*lpInfo) = it->second;
		return 1;
	}
}

bool CCustomTop::GetInfoByName(char* message, CUSTOMTOP_INFO* lpInfo){
	for (std::map<int, CUSTOMTOP_INFO>::iterator it = this->m_CustomTopInfo.begin(); it != this->m_CustomTopInfo.end(); it++){
		if (_stricmp(it->second.Name, message) == 0){
			(*lpInfo) = it->second;
			return 1;
		}
	}
	return 0;
}

void CCustomTop::GetTop(LPOBJ lpObj, int index){
	CUSTOMTOP_INFO CustomTopInfo;
	if (this->GetInfo(index, &CustomTopInfo) == 0){
		return;
	}
}