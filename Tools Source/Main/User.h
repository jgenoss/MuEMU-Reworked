#pragma once
#include "Object.h"
#include "Protocol.h"

class User
{
public:
	void		Load();
	void		Refresh();
	bool		GetTarget();
	lpCharObj	lpPlayer;
	lpViewObj	lpViewPlayer;
	lpViewObj	lpViewTarget;
	BYTE		m_TargetType;	//1 - npc, 2 - attack
	int			m_MapNumber;
	int			m_CursorX;
	int			MagickAttack;
	int			m_CursorY;
	DWORD		m_TargetUpdateTick;
	int GetActiveSkill();
};
extern User gObjUser;