#include "stdafx.h"
#include "CustomNpcName.h"
#include "Offset.h"
#include "User.h"
#include "TMemory.h"
#include "Interface.h"
#include "Protocol.h"
#include "Object.h"
#include "Import.h"
#include "Defines.h"
#include "Util.h"
#include "User.h"
#include "PrintPlayer.h"
#include "Camera.h"
#include "Central.h"
#include "Controller.h"
#include "Config.h"
#include "HackCheck.h"
#include "HealthBar.h"
#include "Common.h"
#include "MSGCommon.h"
#include "CustomCuongHoaWing.h"
#include "CustomVKR.h"

User gObjUser;

DWORD LastTime = 0;
#if(CHONPHEDOILAP)
bool fakeCheckCTRLKeyPressed()
{
	return gObjUser.PkModePhe || HIBYTE(GetAsyncKeyState(VK_CONTROL)) == 128;
}
#endif
void User::Load()
{
	this->m_TargetUpdateTick	= 0;
	this->m_TargetType			= false;
	this->m_CursorX				= -1;
	this->m_CursorY				= -1;
	this->m_MapNumber			= -1;
	//Auto Move
	this->IsSendMove = 0;
	this->MoveToX = 0;
	this->MoveToY = 0;
	this->KhongDiDuoc = 0;
//#if(VANTHANH_FLAG == 1)
//	SetOp((LPVOID)0x00588511, (LPVOID)User::HoolCreateManyFlay, ASM::CALL);
//#endif
#if(CHONPHEDOILAP)
	this->PkModePhe = false;
	SetCompleteHook(0xE8, 0x0059A9B1, &fakeCheckCTRLKeyPressed);
	SetCompleteHook(0xE8, 0x0059AF48, &fakeCheckCTRLKeyPressed);
	SetCompleteHook(0xE8, 0x0059B20A, &fakeCheckCTRLKeyPressed);
	SetCompleteHook(0xE8, 0x0059B23D, &fakeCheckCTRLKeyPressed);
	SetCompleteHook(0xE8, 0x0059A420, &fakeCheckCTRLKeyPressed);
	SetCompleteHook(0xE8, 0x0059A844, &fakeCheckCTRLKeyPressed);
#endif

#if(FLAG_SKIN)
	SetOp((LPVOID)0x00588511, (LPVOID)User::HoolCreateManyFlay, ASM::CALL);//Flagrong
#endif
}



void User::ToggleAuto() {


	if((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000)
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	this->is_auto = !this->is_auto;
}

void User::ToggleAutoTron() {


	if((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000)
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	this->is_autotron = !this->is_autotron;
}

#define preturnModel						((bool(__cdecl*)(int a1, int a2, int a3)) 0x0056F210)

bool User::ShowModelBMD(int a1, int a2, int a3) //An Nguoi Choi OK
{
	int result; // eax

	if (DisablePlayer == 1 && pPlayerState == 5 && oUserPreviewStruct != a1 && (*(BYTE *)(a2 + 24) == 1))
		result = 0;
	else
		result = preturnModel(a1, a2, a3);
	return result;
}


void User::Refresh()
{

	//if (GetModuleHandle(gProtect.m_MainInfo.HackName) == 0 )
	//{
	//	ExitProcess(1);
	//}
	//while (GetModuleHandle(gProtect.m_MainInfo.HackName) == 0)
	//{
	//	ExitProcess(1);
	//}




	float MainWidth = 230.0;
	float MainHeight = 70.0;
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);


	this->lpPlayer			= &*(ObjectCharacter*)oUserObjectStruct;
	this->lpViewPlayer		= &*(ObjectPreview*)oUserPreviewStruct;
	this->GetTarget();

	this->m_CursorX			= pCursorX;
	this->m_CursorY			= pCursorY;
	this->m_MapNumber		= pMapNumber;

	if (pMapNumber == 62)
	{
		//gInterface.DrawMessage(1, "Camera Restore [DEFAULT]");
		gCamera.Restore();
	}

	



	this->CoordenadaX = this->lpViewPlayer->MapPosX;
	this->CoordenadaY = this->lpViewPlayer->MapPosY;
	this->getLevel = gObjUser.lpPlayer->Level;
	this->GetPet = this->lpViewPlayer->PetSlot;
	this->InSafeZone = this->lpViewPlayer->InSafeZone;

	sprintf(this->getName,"%s",gObjUser.lpPlayer->Name);

	if ( gObjUser.GetActiveSkill() == 261 || 
		gObjUser.GetActiveSkill() == 552 || 
		gObjUser.GetActiveSkill() == 555 )
	{
		SetDouble(&pFrameSpeed1, 0.0004000);
		SetDouble(&pFrameSpeed2, 0.0002000);
	}
	else
	{
		SetDouble(&pFrameSpeed1, 0.0040000);
		SetDouble(&pFrameSpeed2, 0.0020000);
	}

	if (this->is_autotron != 1 && this->is_auto == 1) {
		SetByte((PVOID)0x08793383, 1);

		//gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

		//gInterface.DrawFormat(eGold,  StartX + (MainWidth / 3),StartY + 10, 200, 1,gCustomMessage.GetMessage(85));
		//
		//gInterface.DrawFormat(eGold,  StartX + (MainWidth / 5),StartY + 25, 100, 1,"END: Táº¯t Auto");
		//
		//gInterface.DrawFormat(eRed,  StartX + (MainWidth / 5),StartY + 45, 100, 1,"INSERT: Tá»± xoay [OFF]");

		//==

		gInterface.DrawFormat(eGold, 120,25, 200, 1,gConfig.ToggleAuto_TextVN[0]);
			
		gInterface.DrawFormat(eGold,  120,40, 100, 1,gConfig.ToggleAuto_TextVN[1]);
		
		gInterface.DrawFormat(eRed,  120,55, 200, 1,gConfig.ToggleAuto_TextVN[2]);



		//gInterface.DrawFormat(eGold, pCursorX+20,pCursorY, 200, 1,gCustomMessage.GetMessage(85));
		//	
		//gInterface.DrawFormat(eGold,  pCursorX+20,pCursorY+15, 100, 1,"END: Táº¯t Auto");
		//
		//gInterface.DrawFormat(eRed,  pCursorX+20,pCursorY+30, 200, 1,"INSERT: Tá»± xoay [OFF]");


		

	}

	





//=================================================================================================
		if (this->is_autotron == 1 && this->is_auto == 1) {
			SetByte((PVOID)0x08793383, 1);
	
		 //gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);
		 //
		 //gInterface.DrawFormat(eGold,  StartX + (MainWidth / 3),StartY + 10, 200, 1,gCustomMessage.GetMessage(85));
		 //
		 //gInterface.DrawFormat(eGold,  StartX + (MainWidth / 5),StartY + 25, 100, 1,"END: Táº¯t Auto");
		 //
		 //gInterface.DrawFormat(eExcellent,  StartX + (MainWidth / 5),StartY + 45, 200, 1,"INSERT: Tá»± xoay [ON]");

			gInterface.DrawFormat(eGold, 120,25, 200, 1,gConfig.ToggleAuto_TextVN[0]);
			
			gInterface.DrawFormat(eGold,  120,40, 100, 1,gConfig.ToggleAuto_TextVN[1]);
			
			gInterface.DrawFormat(eExcellent,  120,55, 200, 1,gConfig.ToggleAuto_TextVN[3]);


          pCursorX = (int)pWinWidth / pWinWidthReal / 2;
          pCursorY = (int)pWinHeight / pWinHeightReal / 2.1;

          int radius;
         
          (*(float*)gCamera.m_Address.Zoom <= 50)?radius = 120 -(*(float*)gCamera.m_Address.Zoom): (*(float*)gCamera.m_Address.Zoom >= 56)?radius = 120 -(*(float*)gCamera.m_Address.Zoom):radius = 110;

          int alpha = 100;
          static double angle = 0;
          angle += 0.1;  // or some other value.  Higher numbers = circles faster
         
          int Rand = rand() % 100;
          double x;
          double y;
          //(Rand % 2 == 0)?
          ////ve hinh tron
          x = cos(angle) * radius;
          y = sin(angle) * radius;
          ////:(Rand % 3 == 0)?
          //// //ve bong hoa
          //// x = (radius - alpha) * (2+sin(radius*angle)) * cos(angle),
          //// y = (radius - alpha) * (2+sin(radius*angle)) * sin(angle)
          //:
          //ve so 8
          /* x = (cos(angle) * sin(angle)  * radius) * (cos(angle) * cos(angle));
          y = (sin(angle) * cos(angle)  * radius) * (sin(angle) * sin(angle));*/
          pCursorX -= x;
          pCursorY -= y;

			// gInterface.DrawFormat(eGold, pCursorX+20,pCursorY, 200, 1,gCustomMessage.GetMessage(85));
			//
			//gInterface.DrawFormat(eGold,  pCursorX+20,pCursorY+15, 100, 1,"END: Táº¯t Auto");
			//
			//gInterface.DrawFormat(eExcellent,  pCursorX+20,pCursorY+30, 200, 1,"INSERT: Tá»± xoay [ON]");
	}
};
#if(CHONPHEDOILAP)
#include "CustomRankUser.h"
#endif
bool User::GetTarget()
{
#if(CHONPHEDOILAP)
	if (this->lpViewTarget)
	{

		if (gCustomRankUser.m_Data[this->lpViewTarget->aIndex].m_PheDaChon > 0 && gCustomRankUser.m_Data[this->lpViewTarget->aIndex].m_PheDaChon != gCustomRankUser.m_Data[this->lpViewPlayer->aIndex].m_PheDaChon)
		{
			this->PkModePhe = true;
		} 
		else {
			this->PkModePhe = false;
		}
		//gInterface.DrawMessage(1, "%d Target %d", gCustomRankUser.m_Data[this->lpViewPlayer->aIndex].m_PheDaChon,gCustomRankUser.m_Data[this->lpViewTarget->aIndex].m_PheDaChon);
	}
#endif
	if( pViewNPCTargetID != -1 )
	{
		this->lpViewTarget	= &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), pViewNPCTargetID);

		this->m_TargetType	= 1;
		return true;
	}
	else if( pViewAttackTargetID != -1 )
	{
		this->lpViewTarget	= &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), pViewAttackTargetID);
		this->m_TargetType	= 2;
		return true;
	}
	
	if( this->lpViewTarget != 0 )
	{
		ZeroMemory(&this->lpViewTarget, sizeof(this->lpViewTarget));
	}
	
	this->m_TargetType = 0;
	return false;
}

int User::GetActiveSkill()
{
 lpCharObj lpPlayer  = &*(ObjectCharacter*)*(int*)(MAIN_CHARACTER_STRUCT);
 lpViewObj lpViewPlayer  = &*(ObjectPreview*)*(int*)(MAIN_VIEWPORT_STRUCT);
 return lpPlayer->pMagicList[lpViewPlayer->ActiveMagic];
}

void User::SetEventEffect(int PreviewStruct)
{

	lpViewObj lpPreview = &*(ObjectPreview*)PreviewStruct;

	if(lpPreview)
	{
		if(*(DWORD*)(MAIN_SCREEN_STATE) == GameProcess)
		{
			if (lpPreview->m_Model.ObjectType == emPlayer)
			{
					VAngle Angle;
					int PosX;
					int PosY;

					Angle.X = *(float*)(PreviewStruct+0x404);

					Angle.Y = *(float*)(PreviewStruct+0x408);

					Angle.Z = *(float*)(PreviewStruct+0x40C) + *(float*)(PreviewStruct+0x3E8) + 100.0f;

					pGetPosFromAngle(&Angle, &PosX, &PosY);
			}
		}
	}

	// ----
	if( lpPreview->CtlCode == 32 )
	{
		if( *(DWORD*)(PreviewStruct + 672) && lpPreview->Unknown23 != 5 )
		{
			pInitEventStatus(PreviewStruct);
		}
		// ----
		lpPreview->Unknown23 = 5;
	}
	// ----
	if( *(DWORD*)(PreviewStruct + 672) != 0 || !lpPreview->Unknown23 )
	{
		return;
	}
	// ----
	switch(lpPreview->Unknown23)
	{
	case 5:	//-> GM
		{
			if( pEventEffectThis(668) )
			{
				DWORD ModelID = 349;
				// ----
				if( !strncmp(lpPreview->Name, "[GM]", 4) )
				{
					ModelID = 406;
				}
				else if( !strncmp(lpPreview->Name, "[EM]", 4) )
				{
					ModelID = 407;
				}
				else if( !strcmp(lpPreview->Name, "Admin") )
				{
					ModelID = 408;
				}

				// ----
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect(pEventEffectThis(668), 408, 20, 1, 70.0, -5.0, 0.0, 0.0, 0.0, 45.0);
			}
		}
		break;
		// --
	case 6:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 0, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 7:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 1, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 8:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 2, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 9:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 3, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 10:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 4, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 11:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 5, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 12:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 6, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 13:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 7, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
	default:
		{
			lpPreview->Unknown23 = 0;
		}
		break;
	}
}

void User::RenderRuneEffect(DWORD ObjectModel, int ID, int Type, float Z, float Size)
{
	MU3Float lBone;

	MU3Float lBone2;

	vec3_t Color;

	vec3_t ColorRandom;

	Vector(0.0, 0.8, 0.0, Color);

	Vector(((float)(rand() % 100) / 100), ((float)(rand() % 100) / 100), ((float)(rand() % 100) / 100), ColorRandom);

	lBone.X = *(float*)(ObjectModel + 252);

	lBone.Y = *(float*)(ObjectModel + 256);

	lBone.Z = *(float*)(ObjectModel + 260);

	lBone2.X = *(float*)(ObjectModel + 264);

	lBone2.Y = *(float*)(ObjectModel + 268);

	lBone2.Z = *(float*)(ObjectModel + 272);

	lBone.Z = lBone.Z + (float)(Z);

	lBone2.Z = lBone2.Z + (float)(Z);
	//32404 : Vong Xoay
	//32378 : AAA
	pSkillEffect(ID, (int)&lBone, (int)&lBone2, ColorRandom, Type, 0, -1, 0, 0, 0, Size, -1);

	//pCreateEffec(32378, (int)&lBone, (int)&lBone2, ColorRandom, 0, 0, -1, 0, 0, 0, 2.0, -1);
	//pCreateEffec(32378, (int)&lBone, (int)&lBone2, ColorRandom, 2, 0, -1, 0, 0, 0, 1.0, -1);
	//pCreateEffec(32378, (int)&lBone, (int)&lBone2, ColorRandom, 2, 0, -1, 0, 0, 0, 0.2, -1);
	//pCreateEffec(32378, (int)&lBone, (int)&lBone2, ColorRandom, 2, 0, -1, 0, 0, 0, 0.1, -1);
	//pCreateEffec(439, (int)&lBone, (int)&lBone2, ColorRandom, 1, 0, -1, 0, 0, 0, 0.60000002, -1);
	//pCreateEffec(440, (int)&lBone, (int)&lBone2, ColorRandom, 1, 0, -1, 0, 0, 0, 0.60000002, -1);
	//pCreateEffec(441, (int)&lBone, (int)&lBone2, ColorRandom, 1, 0, -1, 0, 0, 0, 0.60000002, -1);
	//pCreateEffec(32119, (int)&lBone, (int)&lBone2, ColorRandom, 0, 0, -1, 0, 0, 0, 0.5, -1);
	//pCreateEffec(32376, (int)&lBone, (int)&lBone2, ColorRandom, 0, 0, -1, 0, 0, 0, 1.0, -1);
}



//#if(VANTHANH_FLAG == 1)
//bool User::UseHasMagicRing()
//{
//	DWORD  pCharData = *(DWORD*)MAIN_CHARACTER_STRUCT;
//	if (pCharData)
//	{
//		for (size_t i = 0; i < 2; i++)
//		{
//			ObjectItem2* VuKhiRong = (ObjectItem2*)GetCharacterItem(i);
//			//if (VKRONG->ItemID == ITEM(13, 20) && VKRONG->Opt.opt_level == 3)
//			if (VuKhiRong->ItemID == ITEM(0, 50)
//				|| VuKhiRong->ItemID == ITEM(0, 51)
//				|| VuKhiRong->ItemID == ITEM(0, 61)
//				|| VuKhiRong->ItemID == ITEM(2, 25)
//				|| VuKhiRong->ItemID == ITEM(3, 27)
//				|| VuKhiRong->ItemID == ITEM(4, 30)
//				|| VuKhiRong->ItemID == ITEM(5, 49)
//				|| VuKhiRong->ItemID == ITEM(5, 50))
//			{
//				return true;
//			}
//		}
//	}
//	return false;
//}
//bool User::CreateManyFlag(ObjectPreview * pChar)
//{
//
//
//	if (!pChar->Unknown764 && (pChar == (ObjectPreview *)*(DWORD*)MAIN_VIEWPORT_STRUCT && UseHasMagicRing() || PlayerHasManyFlag(pChar->aIndex)))
//	{
//		void* pMem = ((void*(__cdecl*)(int))(0x9D00C5))(668);
//		pChar->Unknown764 = (DWORD)((void*(__thiscall*)(void *this1, int modeType, int ParentBoneIndex, bool bFllowParentRotate, float ox, float oy, float oz, float rx, float ry, float rz))(0x4EFFF0))
//			(
//			pMem, 348, 20, 0, -45.0, -5.0, -0.0, 0.0, 0.0, 1);
//
//		return true;
//	}
//
//	return false;
//}
//void User::HoolCreateManyFlay(ObjectPreview*  pChar)
//{
//	User::CreateManyFlag(pChar);
//	((void(__cdecl*)(ObjectPreview*))(0x4EF9A0))(pChar);
//}
//
//#endif


#if(FLAG_SKIN)

bool User::TestFlag(ObjectPreview* pChar)
{
	if (pPlayerState == 4) //Select Character
	{
		return false;
	}
	//if (pChar == (ObjectPreview*)*(DWORD*)MAIN_VIEWPORT_STRUCT)
	//{
	//	lpViewObj lpObj = gObjUser.lpViewPlayer;p
	//	if (gCustomRankUser.m_Data[lpObj->aIndex].m_Flag >=1)
	//	{
	//	return true;
	//	}
	//}
	if (gCustomRankUser.m_Data[pChar->aIndex].m_Flag >= 1)
	{
		return true;
	}

	return false;
}



bool User::CreateManyFlag(ObjectPreview* pChar)
{
	if (DisableShadow == 1)
	{
		return false;
	}
	int Model = gCustomRankUser.m_Data[pChar->aIndex].m_Flag;
	if (gCustomRankUser.m_Data[pChar->aIndex].m_Flag >= 1 && !pCheckEffectPlayer((DWORD*)((int)pChar + 0x4EC), 28))
	{

		//gCustomModelFlag.RenderEffectJPG(pChar, 200000 + Model); //OK

	}
	else
	{
		//gCustomRankUser.m_Data[pChar->aIndex].CacheBMD1 = 0;
	}
	float* v15; // [sp+38h] [bp-5Ch]@13
	float* v24; // [sp+80h] [bp-14h]@12
	int thisa;

	int Flag = gCustomRankUser.m_Data[pChar->aIndex].m_Flag;
	if (TestFlag(pChar))
	{
		if (!pChar->Unknown764)
		{

			v24 = (float*)Operator_new(0x29Cu);
			if (v24)
				v15 = CSParts2D(v24, 6443 + 1171 + Flag, 20, 0, -45.0, -5.0, -0.0, 0.0, 0.0, 1);
			else
				v15 = 0;

			*(DWORD*)(thisa + 764) = (DWORD)v15;

		}
		return true;

	}


	pChar->Unknown764 = 0;
	return false;
}


void User::HoolCreateManyFlay(ObjectPreview* pChar)
{
	User::CreateManyFlag(pChar);
	((void(__cdecl*)(ObjectPreview*))(0x4EF9A0))(pChar);

}

#endif

#define WorldTime				*(float*)0x005EF5A1C
#define EnableAlphaBlend					((void(__cdecl*)()) 0x636070)
#define DisableAlphaBlend				((void(__cdecl*)()) 0x00635F50)
#define RenderTerrainAlphaBitmap             			((void(__cdecl*)(int Texture,float xf,float yf,float SizeX,float SizeY,vec3_t Light,float Xoay,float Alpha,float Height, int DoCao)) 0x005DAD80)

void User::CBRenderCharacter(DWORD ObjectPointer, int Effect, float SizeX, float SizeY, vec3_t Color, int Type)
{

	lpViewObj a4 = &*(ObjectPreview*)(ObjectPointer);
	vec3_t vLight;
	float fLumi = sinf(WorldTime * 0.0015f) * 0.3f + 0.5f;
	Vector(fLumi * Color[0], fLumi * Color[1], fLumi * Color[2], vLight); //7 Mau
	EnableAlphaBlend();
	//RenderTerrainAlphaBitmap(Effect, a4->m_Model.VecPos.X, a4->m_Model.VecPos.Y, SizeX, SizeY, Color, WorldTime * 0.11f, 1.0, 5, 1);
	if (Type == 0)
	{
		RenderTerrainAlphaBitmap(Effect, a4->m_Model.VecPos.X, a4->m_Model.VecPos.Y, SizeX, SizeY, Color, WorldTime * 0.11f, 1.0, 5, 1);
	}
	else {
		RenderTerrainAlphaBitmap(Effect, a4->m_Model.VecPos.X, a4->m_Model.VecPos.Y, SizeX, SizeY, Color, -WorldTime * 0.01f, 1.0, 5, 1);
	}
	
	DisableAlphaBlend();

	//lpViewObj a4 = &*(ObjectPreview*)(ObjectPointer);
	//vec3_t vLight;
	//Vector(1.0f, 1.0f, 1.f, vLight);
	//float fLumi = sinf(WorldTime * 0.0015f) * 0.3f + 0.5f;
	//Vector(fLumi * vLight[0], fLumi * vLight[1], fLumi * vLight[2], vLight);
	//EnableAlphaBlend();
	//RenderTerrainAlphaBitmap(32280, a4->m_Model.VecPos.X, a4->m_Model.VecPos.Y, 5.8f, 5.8f, vLight, WorldTime * 0.11f, 1.0, 5, 1);
	//RenderTerrainAlphaBitmap(32280, a4->m_Model.VecPos.X, a4->m_Model.VecPos.Y, 3.8f, 3.8f, vLight, -WorldTime * 0.01f, 1.0, 5, 1);
	//DisableAlphaBlend();

	//pDrawMessage("11111111111111111111", 1);
}