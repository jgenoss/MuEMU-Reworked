#include "stdafx.h"
#include "Defines.h"
#include "Import.h"
#include "Interface.h"
#include "Offset.h"
#include "Protect.h"
#include "Util.h"
#include "HealthBar.h"
#include "Import.h"
#include "Object.h"
#include "PrintPlayer.h"
#include "WindowsStruct.h"
#include "CustomRankUser.h"
#include "DanhHieu.h"
#include "Config.h"
#include "User.h"
#if(CHONPHEDOILAP)
#include "CustomFont.h"
#include "Common.h"
#endif
CCustomRankUser::CCustomRankUser()
{
}

CCustomRankUser gCustomRankUser;

int ImgTagEx13 = 11300; //Rank Dynamic
int ImgTagEx14 = 11400; //Rank Dynamic
int ImgTagEx15 = 11500; //Rank Dynamic
int ImgTagEx16 = 11600; //Rank Dynamic

DWORD RunEffectTickTime[10] = { 0 };
void CCustomRankUser::RenderShowLogRank(DWORD ViewPortAddr, int index, int PosX, int PosY)
{
	if(*(BYTE*)(ViewPortAddr + 0xE) == 0 && gProtect.m_MainInfo.RankUserOnlyOnSafeZone != 0)
	{
		return; //continue;
	}

	ObjectPreview* Object = &*(ObjectPreview*)(ViewPortAddr);



	if (this->m_Data[index].m_rVipTaiKhoan != 0 && !pCheckEffectPlayer((DWORD *)(ViewPortAddr + 0x4EC), 28))
		//======================================
		if (!pCheckEffectPlayer((DWORD *)(ViewPortAddr + 0x4EC), 28))
		{
			if ((GetTickCount() - RunEffectTickTime[index]) > 500)
			{
				gObjUser.RenderRuneEffect((int)&Object->m_Model, 32378, 2, 10, 2.0);
				RunEffectTickTime[index] = GetTickCount();
			}
		}



	if((((pMapNumber)<18)?0:((pMapNumber)>23)?(((pMapNumber)==53)?1:0):1) == 1) //Disable in Chaos Castle
	{
		return; //continue;
	}
#if(CHONPHEDOILAP)
	if ((int)this->m_Data[index].m_PheDaChon > 0 && (int)this->m_Data[index].m_PheDaChon <= 2)
	{
		DWORD ColorTeam = 0;
		if ((int)this->m_Data[index].m_PheDaChon == 2)
		{
			ColorTeam = 0x007DFFB3;
		}
		else {
			ColorTeam = 0xFF0000B3;
		}
		HFONT FontTextTMB = CreateFontA(14, Main_Font_Width, 0, 0, 700, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, 0x1, 0, 0, Main_Font_Quality, 0, "Arial");
		if ((int)this->m_Data[index].m_CapDoCuongHoa > 0)
		{
			CustomFont.Draw(FontTextTMB, (float)PosX, (float)PosY - 35, 0xFFFFFFC8, ColorTeam, 80, 0, 3, "%s Cấp %d", gConfig.Text_DAOTACBAOTIEU[8 + (int)this->m_Data[index].m_PheDaChon], (int)this->m_Data[index].m_CapDoCuongHoa);
		}
		else
		{
			CustomFont.Draw(FontTextTMB, (float)PosX, (float)PosY - 35, 0xFFFFFFC8, ColorTeam, 80, 0, 3, gConfig.Text_DAOTACBAOTIEU[8 + (int)this->m_Data[index].m_PheDaChon]);
		}
		DeleteObject(FontTextTMB);
	}
#endif
	//=== Show Rank Chu Thanh
	if (this->m_Data[index].m_ShowRankChuPhe)
	{
		pSetBlend(true);
		glColor3f(1.0, 1.0, 1.0);
		//RenderBitmap(eImgChuThanh, (float)PosX + 24, (float)PosY - 90, Return2X(TransForX(60)), 60, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		RenderBitmap(eImgChuThanh, (float)PosX - 37.0f, (float)PosY - 118.0f, 270, 85, 0, 0, 1, 1, 1, 1, 0.0);
		pGLSwitchBlend();
		pGLSwitch();
		glColor3f(1.0, 1.0, 1.0);
		pSetBlend(false);
	}

	if (gProtect.m_MainInfo.RankUserShowOverHead != 0 || *(int*)0x0E609E8 == 4)
	{
		pSetBlend(true);
		glColor3f(1.0, 1.0, 1.0);
		RenderBitmap(gInterface.Data[this->m_Data[index].m_Rank + 1].ModelID, (float)PosX + 24, (float)PosY - 90, Return2X(TransForX(60)), 60, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		pGLSwitchBlend();
		pGLSwitch();
		glColor3f(1.0, 1.0, 1.0);
		pSetBlend(false);
	}
	if ( ViewPortAddr == *(DWORD *)0x7BC4F04 && (pCursorX >= PosX) && ((float)pCursorX <= (float)PosX + 50) && (pCursorY >= PosY + 20) && (pCursorY < PosY + 85))
	{
		this->LoadInfoUser(index, PosX, PosY, (char*)(ViewPortAddr + 0x38));
	}


#if(DANH_HIEU_NEW == 1)
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(true);
			if (MinimizarOfRank == 1)
			{
			}
			if (MinimizarOfRank == 0)
			{
				int v1 = this->m_Data[index].m_rDanhHieu % 10;
				int v2 = (this->m_Data[index].m_rDanhHieu - (v1)) / 10;

				switch (v2)
				{
				case 0:
					//gInterface.DrawToolTip((float)PosX - 130, (float)PosY + 200, "no info ...");
					break;
				case 1:
					RenderBitmap(90101, (float)PosX - 8.0f, (float)PosY - 68.0f, 80, 46, 0, 0, 26.f/40.f, 29.f / 40.f, 1, 1, 0.0);
					break;
				case 2:
					RenderBitmap(90102, (float)PosX - 6.0f, (float)PosY - 68.0f, 80, 46, 0, 0, 26.f / 40.f, 29.f / 40.f, 1, 1, 0.0);
					break;
				case 3:
					RenderBitmap(90103, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 4:
					RenderBitmap(90104, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 5:
					RenderBitmap(90105, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 6:
					RenderBitmap(90106, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 7:
					RenderBitmap(90107, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 8:
					RenderBitmap(90108, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 9:
					RenderBitmap(90109, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 10:
					RenderBitmap(90110, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 11:
					RenderBitmap(90111, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 12:
					RenderBitmap(90112, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 13:
					RenderBitmap(90113, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 14:
					RenderBitmap(90114, (float)PosX - 18.0f, (float)PosY - 95.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 15:
					RenderBitmap(90115, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 16:
					RenderBitmap(90116, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 17:
					RenderBitmap(90117, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 18:
					RenderBitmap(90118, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 19:
					RenderBitmap(90119, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 20:
					RenderBitmap(90120, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 21:
					RenderBitmap(90121, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 22:
					RenderBitmap(90122, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 23:
					RenderBitmap(90123, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 24:
					RenderBitmap(90124, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 25:
					RenderBitmap(90125, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 26:
					RenderBitmap(90126, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 27:
					RenderBitmap(90127, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 28:
					RenderBitmap(90128, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 29:
					RenderBitmap(90129, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 30:
					RenderBitmap(90130, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 31:
					RenderBitmap(90131, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 32:
					RenderBitmap(90132, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 33:
					RenderBitmap(90133, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 34:
					RenderBitmap(90134, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 35:
					RenderBitmap(90135, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 36:
					RenderBitmap(90136, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 37:
					RenderBitmap(90137, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 38:
					RenderBitmap(90138, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 39:
					RenderBitmap(90139, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 40:
					RenderBitmap(90140, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 41:
					RenderBitmap(90141, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 42:
					RenderBitmap(90142, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 43:
					RenderBitmap(90143, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 44:
					RenderBitmap(90144, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 45:
					RenderBitmap(90145, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 46:
					RenderBitmap(90146, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 47:
					RenderBitmap(90147, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 48:
					RenderBitmap(90148, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 49:
					RenderBitmap(90149, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 50:
					RenderBitmap(90150, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					pGLSwitchBlend();
			}


			//======================================
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(true);
			if (MinimizarOfRank == 1)
			{
			}
			if (MinimizarOfRank == 0)

			if (gProtect.m_MainInfo.EnableRankTuChan != 0)
			{

			{
				//switch (this->m_Data[index].m_rTuLuyen)
				{

				//case 0:
				//	break;
				//case 1:
				//	RenderBitmap(10128, (float)PosX + -45.0f, (float)PosY - 130.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 2:
				//	RenderBitmap(10129, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 3:
				//	RenderBitmap(10130, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 4:
				//	RenderBitmap(10131, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 5:
				//	RenderBitmap(10132, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 6:
				//	RenderBitmap(10133, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 7:
				//	RenderBitmap(10134, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 8:
				//	RenderBitmap(10135, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 9:
				//	RenderBitmap(10136, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 10:
				//	RenderBitmap(10137, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 11:
				//	RenderBitmap(10138, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 12:
				//	RenderBitmap(10139, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 13:
				//	RenderBitmap(10140, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 14:
				//	RenderBitmap(10141, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 15:
				//	RenderBitmap(10142, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 16:
				//	RenderBitmap(10143, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 17:
				//	RenderBitmap(10144, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 18:
				//	RenderBitmap(10145, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 19:
				//	RenderBitmap(10146, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 20:
				//	RenderBitmap(10147, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 21:
				//	RenderBitmap(10148, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 22:
				//	RenderBitmap(10149, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 23:
				//	RenderBitmap(10150, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 24:
				//	RenderBitmap(10151, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 25:
				//	RenderBitmap(10152, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 26:
				//	RenderBitmap(10153, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 27:
				//	RenderBitmap(10154, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 28:
				//	RenderBitmap(10155, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 29:
				//	RenderBitmap(10156, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 30:
				//	RenderBitmap(10157, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 31:
				//	RenderBitmap(10158, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 32:
				//	RenderBitmap(10159, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 33:
				//	RenderBitmap(10160, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 34:
				//	RenderBitmap(10161, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 35:
				//	RenderBitmap(10162, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 36:
				//	RenderBitmap(10163, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 37:
				//	RenderBitmap(10164, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 38:
				//	RenderBitmap(10165, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 39:
				//	RenderBitmap(10166, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 40:
				//	RenderBitmap(10167, (float)PosX + -45.0f, (float)PosY - 135.0f, 220, 100, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;

					pGLSwitchBlend();
				}
			}
		
}

}
#endif
	if (MinimizarOfRank == 1)
	{
	}
	if (MinimizarOfRank == 0)
	{


		if (gProtect.m_MainInfo.EnableRankVIP != 0)
		{
#if(DANH_HIEU_NEW == 1)
			//if (gProtect.m_MainInfo.EnableRankTuChan == 0 || TitleTuLuyen <= 0)
			{
				if (this->m_Data[index].m_rVipTaiKhoan == 1)
				{
					RenderBitmap(32891, (float)PosX + 26, (float)PosY - 86, 40, 30, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_rVipTaiKhoan == 2) {
					RenderBitmap(32892, (float)PosX + 26, (float)PosY - 86, 40, 30, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_rVipTaiKhoan == 3) {
					RenderBitmap(32893, (float)PosX + 26, (float)PosY - 86, 40, 30, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else {}
			}
			
#endif
			{
				if (this->m_Data[index].m_rVipTaiKhoan == 1)
				{
					RenderBitmap(32891, (float)PosX + 26, (float)PosY - 100, 40, 30, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_rVipTaiKhoan == 2) {
					RenderBitmap(32892, (float)PosX + 26, (float)PosY - 100, 40, 30, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_rVipTaiKhoan == 3) {
					RenderBitmap(32893, (float)PosX + 26, (float)PosY - 100, 40, 30, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}


				else {}
			}
		}
	}
}

void CCustomRankUser::DrawInfo()
{
	
	VAngle Angle;

	int PosX, PosY;

	DWORD ViewportAddress = ((DWORD(__thiscall*)(void*,DWORD))0x0096A4C0)(((void*(*)())0x00402BC0)(), pViewAttackTargetID);

	ObjectPreview* Object = &*(ObjectPreview*)(ViewportAddress);

	if(!ViewportAddress || *(BYTE*)(ViewportAddress+0x320) != 1)
	{
		return; //continue;
	}

	int index = *(WORD*)(ViewportAddress+0x7E);

	char* name = (char*)(ViewportAddress+0x38);


	//if (pCheckEffectPlayer((DWORD *)(ViewportAddress + 0x4EC), 28))
	//{
	//	if ((GetTickCount() - RunEffectTickTime[index]) > 500)
	//	{
	//		//32378 2.0 Type: 2 //VIP
	//		//441 Type 1
	//		//32404 Type 1 //Admin
	//		//32313
	//		gObjUser.RenderRuneEffect((int)&Object->m_Model, 32433, 2, 0.5, 0.0);
	//		RunEffectTickTime[index] = GetTickCount();
	//	}
	//}


	//if ((GetTickCount() - RunEffectTickTime[index]) > 500)
	//{
	//	//32378 2.0 Type: 2 //VIP
	//	//441 Type 1
	//	//32404 Type 1 //Admin
	//	gObjUser.RenderRuneEffect((int)&Object->m_Model, 32378, 2, 10, 2.0);
	//	RunEffectTickTime[index] = GetTickCount();
	//}



	if(this->m_Data[index].m_Enabled == false)
	{
		return; //continue;
	}

	if(*(BYTE*)(ViewportAddress+0xE) == 0 && gProtect.m_MainInfo.RankUserOnlyOnSafeZone != 0)
	{
		return; //continue;
	}

	if((((pMapNumber)<18)?0:((pMapNumber)>23)?(((pMapNumber)==53)?1:0):1) == 1) //Disable in Chaos Castle
	{
		return; //continue;
	}

	Angle.X = *(float*)(ViewportAddress+0x404);

	Angle.Y = *(float*)(ViewportAddress+0x408);

	Angle.Z = *(float*)(ViewportAddress+0x40C) + *(float*)(ViewportAddress+0x3E8) + 100.0f;

	pGetPosFromAngle(&Angle, &PosX, &PosY);

	PosX -= 42;







	this->LoadInfoUser(index, PosX, PosY, name);
}

void CCustomRankUser::LoadInfoUser(int index, int PosX, int PosY, char* name)
{
	if((!gInterface.Data[eMenu_MAIN].OnShow && 
	!gInterface.Data[eVip_MAIN].OnShow && 
	!gInterface.Data[eEventTimePANEL_MAIN].OnShow &&
	!gInterface.Data[eCommand_MAIN].OnShow &&
	!gInterface.Data[eRankPANEL_MAIN].OnShow)&&
	!gInterface.CheckWindow(35) )
	{
		if (gProtect.m_MainInfo.RankUserType != 4 && gProtect.m_MainInfo.RankUserShowOverHead != 0)
		{
			pSetBlend(true);
			glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
			pDrawBarForm((float)(PosX + 2), (float)(PosY - 76), 75, 10, 0.0f, 0);
			pGLSwitchBlend();
			pGLSwitch();
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(false);

			this->DrawFormat(eGold, PosX+7, PosY -75, 70, 3, "%s", this->m_Data[index].szTitleRank);
		}

		if( gProtect.m_MainInfo.RankUserNeedAltKey != 0 && !(GetKeyState(VK_MENU) & 0x8000) )
		{
			return; //continue;
		}

		if( gProtect.m_MainInfo.RankUserType == 0 )
		{
			return; //continue;
		}


		pSetBlend(true);

		char classename[20] = {0};

		switch(this->m_Data[index].m_Classe)
		{
			case 1:
				sprintf(classename, "Soul Master");
				break;
			case 2:
				sprintf(classename, "Grand Master");
				break;
			case 16:
				sprintf(classename, "Dark Knight");
				break;
			case 17:
				sprintf(classename, "Blade Knight");
				break;
			case 18:
				sprintf(classename, "Blade Master");
				break;
			case 32:
				sprintf(classename, "Fairy Elf");
				break;
			case 33:
				sprintf(classename, "Muse Elf");
				break;
			case 34:
				sprintf(classename, "High Elf");
				break;
			case 48:
				sprintf(classename, "Magic Gladiator");
				break;
			case 50:
				sprintf(classename, "Duel Master");
				break;
			case 64:
				sprintf(classename, "Dark Lord");
				break;
			case 66:
				sprintf(classename, "Lord Emperor");
				break;
			case 80:
				sprintf(classename, "Summoner");
				break;
			case 81:
				sprintf(classename, "Bloody Summoner");
				break;
			case 82:
				sprintf(classename, "Dimension Master");
				break;
			case 96:
				sprintf(classename, "Rage Fighter");
				break;
			case 98:
				sprintf(classename, "Fist Master");
				break;
			default:
				sprintf(classename, "Dark Wizard");
				break;
		}

		if (gProtect.m_MainInfo.RankUserType == 2)
		{
			glColor4f(0.0, 0.0, 0.0, 0.8);
			pDrawBarForm((float)(PosX+40), (float)(PosY - 8), 135, 80, 0.0f, 0);
			pGLSwitchBlend();

			this->DrawFormat(eRed2, PosX + 60, PosY - 4, 90, 3, "Rank: %s", this->m_Data[index].szTitleRank);
		
			this->DrawFormat(eWhite,  PosX + 60, PosY + 8, 15, 1, "Lvl:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 18, 15, 1, "Str:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 28, 15, 1, "Agi:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 38, 15, 1, "Vit:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 48, 15, 1, "Ene:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 58, 15, 1, "Com:");

			this->DrawFormat(eGold,  PosX + 80, PosY +  8, 45, 1, "%d ", this->m_Data[index].m_Level);
			this->DrawFormat(eGold,  PosX + 80, PosY + 18, 45, 1, "%d ", this->m_Data[index].m_For);
			this->DrawFormat(eGold,  PosX + 80, PosY + 28, 45, 1, "%d ", this->m_Data[index].m_Agi);
			this->DrawFormat(eGold,  PosX + 80, PosY + 38, 45, 1, "%d ", this->m_Data[index].m_Vit);
			this->DrawFormat(eGold,  PosX + 80, PosY + 48, 45, 1, "%d ", this->m_Data[index].m_Ene);
			this->DrawFormat(eGold,  PosX + 80, PosY + 58, 45, 1, "%d ", this->m_Data[index].m_Com);

			int posM = 0;

			if(gProtect.m_MainInfo.RankUserShowReset != 0)
			{
				this->DrawFormat(eWhite,  PosX + 120, PosY + 8, 25, 1,  "Resets:");
				this->DrawFormat(eGold,  PosX + 147, PosY + 8, 37, 1,  "%d", this->m_Data[index].m_Resets);
			}
			else
			{
				posM -= 10;
			}

			if(gProtect.m_MainInfo.RankUserShowMasterReset != 0)
			{
				this->DrawFormat(eWhite,  PosX + 120, PosY + 18 + posM, 25, 1, gCustomMessage.GetMessage(68));
				this->DrawFormat(eGold,  PosX + 147, PosY + 18 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
			}
			else
			{
				posM -= 10;
			}

			this->DrawFormat(eWhite,  PosX + 120, PosY + 28 + posM, 25, 1, "Kills:");
			this->DrawFormat(eWhite,  PosX + 120, PosY + 38 + posM, 25, 1, "Deaths:");
			this->DrawFormat(eGold,  PosX + 147, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
			this->DrawFormat(eGold,  PosX + 147, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

			this->DrawFormat(eAncient,  PosX + 120, PosY + 48 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
			this->DrawFormat(eOrange,  PosX + 120, PosY + 58 + posM, 60, 1, "%s", classename);

		}
		else if (gProtect.m_MainInfo.RankUserType == 1)
		{

			glColor4f(0.0, 0.0, 0.0, 0.8);
			pDrawBarForm((float)(PosX+40), (float)(PosY - 8), 120.0f, 80.0f, 0.0f, 0);
			pGLSwitchBlend();

			this->DrawFormat(eWhite,  PosX + 50, PosY - 2, 15, 1, "Lvl:");

			int posM = 0;

			if(gProtect.m_MainInfo.RankUserShowReset != 0)
			{
				this->DrawFormat(eWhite,  PosX + 50, PosY + 8, 25, 1,  "Resets:");
				this->DrawFormat(eGold,  PosX + 87, PosY + 8, 37, 1,  "%d", this->m_Data[index].m_Resets);
			}
			else
			{
				posM -= 10;
			}

			if(gProtect.m_MainInfo.RankUserShowMasterReset != 0)
			{
				this->DrawFormat(eWhite,  PosX + 50, PosY + 18 + posM, 25, 1, gCustomMessage.GetMessage(68));
				this->DrawFormat(eGold,  PosX + 87, PosY + 18 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
			}
			else
			{
				posM -= 10;
			}

			this->DrawFormat(eWhite,  PosX + 50, PosY + 28 + posM, 25, 1, "Kills:");
			this->DrawFormat(eWhite,  PosX + 50, PosY + 38 + posM, 25, 1, "Deaths:");

			this->DrawFormat(eGold,  PosX + 87, PosY - 2, 45, 1, "%d ", this->m_Data[index].m_Level);
			this->DrawFormat(eGold,  PosX + 87, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
			this->DrawFormat(eGold,  PosX + 87, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

			this->DrawFormat(eAncient,  PosX + 50, PosY + 48 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
			this->DrawFormat(eOrange,  PosX + 50, PosY + 58 + posM, 60, 1, "%s", classename);

			this->DrawFormat(eGold, PosX + 100, PosY -5, 70, 3, "%s", this->m_Data[index].szTitleRank);
			this->DrawFormat(eGold, PosX + 100, PosY + 59, 70, 3, "%s", name);
			pSetBlend(true);
			glColor3f(1.0, 1.0, 1.0);
			RenderBitmap(gInterface.Data[this->m_Data[index].m_Rank+1].ModelID, (float)PosX + 110, (float)PosY + 9, 78.0, 78.0,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			pGLSwitchBlend();
			pGLSwitch();
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(false);
		}
		else if (gProtect.m_MainInfo.RankUserType == 3)
		{

			glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
			pDrawBarForm((float)(PosX+40), (float)(PosY - 5), 80, 85, 0.0f, 0);
			pGLSwitchBlend();

			this->DrawFormat(eSocket, PosX + 40, PosY - 4, 80, 3, "INFO");

			this->DrawFormat(eWhite,  PosX + 50, PosY +8, 15, 1, "Lvl:");

			int posM = 0;

			if(gProtect.m_MainInfo.RankUserShowReset != 0)
			{
				this->DrawFormat(eWhite,  PosX + 50, PosY + 18, 25, 1, "Resets:");
				this->DrawFormat(eGold,  PosX + 87, PosY + 18, 37, 1, "%d", this->m_Data[index].m_Resets);
			}
			else
			{
				posM -= 10;
			}

			if(gProtect.m_MainInfo.RankUserShowMasterReset != 0)
			{
				this->DrawFormat(eWhite,  PosX + 50, PosY + 28 + posM, 25, 1, gCustomMessage.GetMessage(68));
				this->DrawFormat(eGold,  PosX + 87, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
			}
			else
			{
				posM -= 10;
			}

			this->DrawFormat(eWhite,  PosX + 50, PosY + 38 + posM, 25, 1, "Kills:");
			this->DrawFormat(eWhite,  PosX + 50, PosY + 48 + posM, 25, 1, "Deaths:");

			this->DrawFormat(eGold,  PosX + 87, PosY + 8, 45, 1, "%d ", this->m_Data[index].m_Level);
			this->DrawFormat(eGold,  PosX + 87, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
			this->DrawFormat(eGold,  PosX + 87, PosY + 48 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

			this->DrawFormat(eAncient,  PosX + 50, PosY + 58 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
			this->DrawFormat(eOrange,  PosX + 50, PosY + 68 + posM, 60, 1, "%s", classename);
		}
		else if (gProtect.m_MainInfo.RankUserType == 4)
		{

			glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
			pDrawBarForm((float)(PosX+2), (float)(PosY - 76), 75, 10, 0.0f, 0);
			pGLSwitchBlend();

			this->DrawFormat(eGold, PosX+7, PosY -75, 70, 3, "%s", this->m_Data[index].szTitleRank);
		}
		else 
		{
			glColor4f(0.0, 0.0, 0.0, 0.8);
			pDrawBarForm((float)(PosX+40), (float)(PosY - 8), 185, 80, 0.0f, 0);
			pGLSwitchBlend();

			this->DrawFormat(eRed2,		 PosX + 60, PosY - 6, 105, 3, "Character Status:");
		
			this->DrawFormat(eWhite,  PosX + 60, PosY + 8, 15, 1, "Lvl:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 18, 15, 1, "Str:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 28, 15, 1, "Agi:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 38, 15, 1, "Vit:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 48, 15, 1, "Ene:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 58, 15, 1, "Com:");

			this->DrawFormat(eGold,  PosX + 80, PosY +  8, 45, 1, "%d ", this->m_Data[index].m_Level);
			this->DrawFormat(eGold,  PosX + 80, PosY + 18, 45, 1, "%d ", this->m_Data[index].m_For);
			this->DrawFormat(eGold,  PosX + 80, PosY + 28, 45, 1, "%d ", this->m_Data[index].m_Agi);
			this->DrawFormat(eGold,  PosX + 80, PosY + 38, 45, 1, "%d ", this->m_Data[index].m_Vit);
			this->DrawFormat(eGold,  PosX + 80, PosY + 48, 45, 1, "%d ", this->m_Data[index].m_Ene);
			this->DrawFormat(eGold,  PosX + 80, PosY + 58, 45, 1, "%d ", this->m_Data[index].m_Com);

			int posM = 0;

			if(gProtect.m_MainInfo.RankUserShowReset != 0)
			{
				this->DrawFormat(eWhite,  PosX + 120, PosY + 8, 25, 1,  "Resets:");
				this->DrawFormat(eGold,  PosX + 147, PosY + 8, 37, 1,  "%d", this->m_Data[index].m_Resets);	
			}
			else
			{
				posM -= 10;
			}

			if(gProtect.m_MainInfo.RankUserShowMasterReset != 0)
			{
				this->DrawFormat(eWhite,  PosX + 120, PosY + 18 + posM, 25, 1, gCustomMessage.GetMessage(68));
				this->DrawFormat(eGold,  PosX + 147, PosY + 18 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
			}
			else
			{
				posM -= 10;
			}

			this->DrawFormat(eWhite,  PosX + 120, PosY + 28 + posM, 25, 1, "Kills:");
			this->DrawFormat(eWhite,  PosX + 120, PosY + 38 + posM, 25, 1, "Deaths:");
			this->DrawFormat(eGold,  PosX + 147, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
			this->DrawFormat(eGold,  PosX + 147, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

			this->DrawFormat(eAncient,  PosX + 120, PosY + 48 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
			this->DrawFormat(eOrange,  PosX + 120, PosY + 58 + posM, 60, 1, "%s", classename);

			this->DrawFormat(eGold, PosX + 133, PosY -5, 126, 3, "%s", this->m_Data[index].szTitleRank);
			this->DrawFormat(eGold, PosX + 133, PosY + 59, 126, 3, "%s", name);
			pSetBlend(true);
			glColor3f(1.0, 1.0, 1.0);
			RenderBitmap(gInterface.Data[this->m_Data[index].m_Rank+1].ModelID, (float)PosX + 170, (float)PosY + 5, Return2X(TransForX(78)), 78,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			pGLSwitchBlend();
			pGLSwitch();
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(false);
		}

	}

	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
}






int CCustomRankUser::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048] = {0};
	// ---
	int BuffLen = sizeof(Buff)-1;
	// ---
	ZeroMemory(Buff, BuffLen);
	// ---
	va_list args;
	// ---
	va_start(args, Text);
	// ---
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	// ---
	va_end(args);
	// ---
	int LineCount = 0;
	// ---
	char * Line = strtok(Buff, "\n");
	// ---
	while(Line != NULL)
	{
		pDrawColorText(Line, PosX, PosY, Width, 5, Color, 9, Align);
		// ---
		PosY += 10;
		// ---
		Line = strtok(NULL, "\n");
	}
	// ---
	return PosY;
}

void CCustomRankUser::GCReqRankLevelUser(PMSG_CUSTOM_RANKUSER * aRecv)
{
	if(aRecv == NULL)
	{
		return;
	}
	// --- 
	this->m_Data[aRecv->iIndex].m_Enabled = true;
	this->m_Data[aRecv->iIndex].m_Level = aRecv->iLevel;
	this->m_Data[aRecv->iIndex].m_Resets = aRecv->iReset;
	this->m_Data[aRecv->iIndex].m_MResets = aRecv->iMReset;
	this->m_Data[aRecv->iIndex].m_Kills = aRecv->iKills;
	this->m_Data[aRecv->iIndex].m_Deads = aRecv->iDeads;
	this->m_Data[aRecv->iIndex].m_For = aRecv->iFor;
	this->m_Data[aRecv->iIndex].m_Agi = aRecv->iAgi;	
	this->m_Data[aRecv->iIndex].m_Ene = aRecv->iEne;
	this->m_Data[aRecv->iIndex].m_Vit = aRecv->iVit;
	this->m_Data[aRecv->iIndex].m_Com = aRecv->iCom;
	this->m_Data[aRecv->iIndex].m_Classe = aRecv->iClasse;
	this->m_Data[aRecv->iIndex].m_Rank = aRecv->iRank;

#if(DANH_HIEU_NEW)
	this->m_Data[aRecv->iIndex].m_rDanhHieu = aRecv->irDanhHieu;
#endif
//	this->m_Data[aRecv->iIndex].m_rDanhHieu = aRecv->irDanhHieu;
//	this->m_Data[aRecv->iIndex].m_rTuLuyen = aRecv->irTuLuyen;
	this->m_Data[aRecv->iIndex].m_rVipTaiKhoan = aRecv->irVipTaiKhoan;
#if(CHONPHEDOILAP)
	this->m_Data[aRecv->iIndex].m_PheDaChon = aRecv->mPheDaChon;
#endif
#if(B_HON_HOAN)
	this->m_Data[aRecv->iIndex].m_CapDoHonHoan = aRecv->CapDoHonHoan;
#endif
	this->m_Data[aRecv->iIndex].m_CapDoCuongHoa = aRecv->CapDoCuongHoa;

	this->m_Data[aRecv->iIndex].m_ShowRankChuPhe = aRecv->ShowRankChuPhe;

#if(FLAG_SKIN)
	this->m_Data[aRecv->iIndex].m_Flag = aRecv->Flag;
#endif
	// ---
	//memcpy(this->m_Data[aRecv->iIndex].szTitleRank, aRecv->szName, sizeof(this->m_Data[aRecv->iIndex].szTitleRank));
	//memcpy(this->m_Data[aRecv->iIndex].m_Vip, aRecv->iVip, sizeof(this->m_Data[aRecv->iIndex].m_Vip));
}

bool CPreviewManager::ObjCheck(int index, int pThis)
{
	if(pThis == NULL)
	{
		return false;
	}
	// ---
	if(!CS_GET_STRUCT(index, pThis))
	{
		return false;
	}
	// ---
	return true;
}

bool CPreviewManager::ObjSelect(int index, int pThis)
{
	if(pThis == NULL)
	{
		return false;
	}
	// ---
	this->Index = *(WORD*)(CS_GET_STRUCT(index, pThis) + 86);
	this->Live = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 616);
	this->Type = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 634);
	this->IsSafeZone = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 14);
	// ---
	this->Angle.X = *(float*)(CS_GET_STRUCT(index, pThis) + 864);
	this->Angle.Y = *(float*)(CS_GET_STRUCT(index, pThis) + 868);
	this->Angle.Z = *(float*)(CS_GET_STRUCT(index, pThis) + 872) + *(float*)(CS_GET_STRUCT(index, pThis) + 836) + 100.0f;
	// ---
	return true;
}

