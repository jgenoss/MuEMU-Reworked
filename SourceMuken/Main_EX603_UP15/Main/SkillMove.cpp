#include "StdAfx.h"
#include "SkillMove.h"
#include "Util.h"

cSkillMove SkillMove;

cSkillMove::cSkillMove()
{
	this->Load();
}

cSkillMove::~cSkillMove()
{
}

void cSkillMove::Load()
{
	this->Method = false; //true = move that nhung dk van bi, fall = khong cho move

	SetCompleteHook(0xE8, 0x005AE556, &cSkillMove::CheckPathFinding); //skill 523					DL				Chaotic Diseier
	SetCompleteHook(0xE8, 0x005AFF37, &cSkillMove::CheckPathFinding); //skill 76					DK MG DL
	SetCompleteHook(0xE8, 0x005ACEF0, &cSkillMove::CheckPathFinding); //skill 76					ELF
	SetCompleteHook(0xE8, 0x005B1136, &cSkillMove::CheckPathFinding); //skill 76					DW MG SUM
	SetCompleteHook(0xE8, 0x005B2987, &cSkillMove::CheckPathFinding); //skill 217					DW MG SUM
	SetCompleteHook(0xE8, 0x005B2E51, &cSkillMove::CheckPathFinding); //skill 214,215,216,455,458	DW MG SUM
	SetCompleteHook(0xE8, 0x005B2E51, &cSkillMove::CheckPathFinding); //skill 219,220,454			DW MG SUM
	SetCompleteHook(0xE8, 0x005A0332, &cSkillMove::CheckPathFinding); //skill						RF

	//SetCompleteHook(0xE8, 0x005A1FCF, &cSkillMove::CheckPathFinding); //Action Other skills
	//SetCompleteHook(0xE8, 0x005A1EA1, &cSkillMove::CheckPathFinding); //Action Other skills
	//SetCompleteHook(0xE8, 0x005A1D6D, &cSkillMove::CheckPathFinding); //Action Other skills
	//SetCompleteHook(0xE8, 0x005A1C3C, &cSkillMove::CheckPathFinding); //Action Other skills
	//SetCompleteHook(0xE8, 0x005A1B0C, &cSkillMove::CheckPathFinding); //Action Other skills
	//SetCompleteHook(0xE8, 0x005A19DB, &cSkillMove::CheckPathFinding); //Action Other skills
	//SetCompleteHook(0xE8, 0x005A15AE, &cSkillMove::CheckPathFinding); //Action Other skills
	//SetCompleteHook(0xE8, 0x00565089, &cSkillMove::CheckPathFinding); //Unknow
}

bool cSkillMove::CheckPathFinding(int sx, int sy, int tx, int ty, PATH_t *a, float fDistance, int iDefaultWall)
{
	if (SkillMove.Method == false) {
		*(BYTE *)(*(DWORD*)0x007BC4F04 + 120) = 0;
		return false;
	}
	if (pPathFinding2(sx, sy, tx, ty, a, fDistance, iDefaultWall)) {
		pSendMove(*(DWORD*)0x007BC4F04, *(DWORD*)0x007BC4F04 + 776);
		return true;
	}
	*(BYTE *)(*(DWORD*)0x007BC4F04 + 120) = 0;
	return false;
}