#include "stdafx.h"
#include "RespawnLocation.h"
#include "Gate.h"
#include "Map.h"
#include "KanturuBattleUserMng.h"
#include "RaklionBattleUserMng.h"
#include "MemScript.h"
#include "Util.h"

cRespawnLocation gRespawnLocation;

cRespawnLocation::cRespawnLocation(){
	this->m_RespLoc.clear();
}

cRespawnLocation::~cRespawnLocation(){

}

void cRespawnLocation::Load(char* path){
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(path);
	if (res.status != pugi::status_ok){
		ErrorMessageBox("File %s load fail. Error: %s", path, res.description());
		return;
	}
	this->m_RespLoc.clear();
	pugi::xml_node RespawnLoc = file.child("RespawnLocation");
	pugi::xml_node Respawn = RespawnLoc.child("Respawn");
	for (pugi::xml_node xres = Respawn.child("Create"); xres; xres = xres.next_sibling()){
		RESPLOC_DATA info;
		info.Map = xres.attribute("Map").as_int();
		info.MoveGate = xres.attribute("MovGate").as_int();
		info.Gate = xres.attribute("Gate").as_int();
		this->m_RespLoc.push_back(info);
	}
}

bool cRespawnLocation::IsMap(LPOBJ lpObj){
	for (std::vector<RESPLOC_DATA>::iterator it = this->m_RespLoc.begin(); it != this->m_RespLoc.end(); it++){
		if (it->Map == lpObj->Map){
			return true;
		}
	}
	return false;
}

bool cRespawnLocation::GetUserRespawnLocation(LPOBJ lpObj, int* gate, int* map, int* x, int* y, int* dir, int* level){
	bool result = 0;
	for (std::vector<RESPLOC_DATA>::iterator it = this->m_RespLoc.begin(); it != this->m_RespLoc.end(); it++){
		if (lpObj->Map == it->Map){
			if (it->MoveGate == 0){
				return 0;
			}
			result = gGate.GetGate(it->Gate, gate, map, x, y, dir, level);
			if (lpObj->Map == MAP_KANTURU3){
				gKanturuBattleUserMng.DelUserData(lpObj->Index);
			}
			if (lpObj->Map == MAP_RAKLION2){
				gRaklionBattleUserMng.DelUserData(lpObj->Index);
			}
		}
	}
	return result;
}