#include "stdafx.h"
#include "MuClientAPI.h"
#include "MuConstants.h"
#include "Offset.h"
#include "User.h"
#include "Protocol.h"
#include "Util.h"
#include "PrintPlayer.h"
#include "MemoryPatcher.h"

User	gObjUser;

DWORD LastTime = 0;

void User::Load()
{
	this->m_TargetUpdateTick = 0;
	this->m_TargetType = false;
	this->m_CursorX = -1;
	this->m_CursorY = -1;
	this->m_MapNumber = -1;
}

void User::Refresh()
{
	this->lpPlayer = &*(ObjectCharacter*)gMuClientApi.UserObjectStruct();
	this->lpViewPlayer = &*(ObjectPreview*)gMuClientApi.UserPreviewStruct();
	this->GetTarget();

	this->m_CursorX = gMuClientApi.CursorX();
	this->m_CursorY = gMuClientApi.CursorX();
	this->m_MapNumber = gMuClientApi.MapNumber();

	if (gObjUser.GetActiveSkill() == 261 || gObjUser.GetActiveSkill() == 552 || gObjUser.GetActiveSkill() == 555)
	{
		gMemory.SetDouble(&gMuClientApi.FrameSpeed1(), 0.0004000);
		gMemory.SetDouble(&gMuClientApi.FrameSpeed2(), 0.0002000);
	}
	else
	{
		gMemory.SetDouble(&gMuClientApi.FrameSpeed1(), 0.0040000);
		gMemory.SetDouble(&gMuClientApi.FrameSpeed2(), 0.0020000);
	}
}

bool User::GetTarget()
{
	if (gMuClientApi.ViewNPCTargetID() != -1)
	{
		this->lpViewTarget = &*(ObjectPreview*)gMuClientApi.GetPreviewStruct(gMuClientApi.PreviewThis(), gMuClientApi.ViewNPCTargetID());

		this->m_TargetType = 1;
		return true;
	}
	else if (gMuClientApi.ViewAttackTargetID() != -1)
	{
		this->lpViewTarget = &*(ObjectPreview*)gMuClientApi.GetPreviewStruct(gMuClientApi.PreviewThis(), gMuClientApi.ViewAttackTargetID());
		this->m_TargetType = 2;
		return true;
	}

	if (this->lpViewTarget != 0)
	{
		ZeroMemory(&this->lpViewTarget, sizeof(this->lpViewTarget));
	}

	this->m_TargetType = 0;
	return false;
}

int User::GetActiveSkill()
{
	lpCharObj lpPlayer = &*(ObjectCharacter*)*(int*)(MAIN_CHARACTER_STRUCT);
	lpViewObj lpViewPlayer = &*(ObjectPreview*)*(int*)(MAIN_VIEWPORT_STRUCT);
	return lpPlayer->pMagicList[lpViewPlayer->ActiveMagic];
}