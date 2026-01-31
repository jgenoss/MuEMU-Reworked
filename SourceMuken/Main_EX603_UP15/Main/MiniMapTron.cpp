#include "stdafx.h"
#include "MiniMapTron.h"
#include "Import.h"
#include "Util.h"
#include "Offset.h"
#include "User.h"
#include "Interface.h"
#include "Defines.h"
#include "Common.h"
#include "MiniMapInfo.h"
#include "Central.h"
#include "WindowsStruct.h"
#include "InfoLog.h"
#include "PrintPlayer.h"

CMinimapTron gRenderMapTron;

CMinimapTron::CMinimapTron()
{
	this->DataMapTron.ModelID = -1;
	this->DataMapTron.XSW_Minimap_Frame = 0;  //-- Minimap_FrameX
	this->DataMapTron.YSW_Minimap_Frame = 0;  //-- Minimap_FrameY
	this->DataMapTron.XSW_Minimap = 535; //-- MiniMapX (Mover Minimapa Izquierda o Derecha)
	this->DataMapTron.YSW_Minimap = 306; //-- MiniMapY (Minimapa Abajo) (Mover Minimapa Arriba o Abajo)
	//this->DataMap.YSW_Minimap = 14; //-- MiniMapY (Minimapa Arriba) (Mover Minimapa Arriba o Abajo)
	this->DataMapTron.XSW_Time_Frame = 0; //-- Time_FrameX
	this->DataMapTron.YSW_Time_Frame = 0; //-- Time_FrameY
	this->DataMapTron.This_92 = 0;
	this->DataMapTron.This_96 = 0;
	this->DataMapTron.DropMoveUserX = 0; //-- DropMoveUserX
	this->DataMapTron.DropMoveUserY = 0; //-- DropMoveUserY
	this->DataMapTron.This_108;
	this->DataMapTron.This_112;
	this->DataMapTron.CurrentMoveX = 0; //-- CurrentMoveX
	this->DataMapTron.CurrentMoveY = 0; //-- CurrentMoveY
	this->DataMapTron.Scale = 1; //-- Scale
	this->DataMapTron.TimerEventVK = 0; //-- Scale
	this->DataMapTron.Alpha = 1.0f; //-- Alpha
}

CMinimapTron::~CMinimapTron()
{
}

//----- (0082ABA0)
char CMinimapTron::MapTronRender(int a1)
{
	float DIRPointer;
	lpViewObj ObjectPointer;

	char result; // al@2
	float blue; // ST30_4@3
	float green; // ST2C_4@3
	float v7; // ST78_4@3
	float v8; // ST74_4@3
	float v9; // ST20_4@12
	float v10; // ST1C_4@12
	float v11; // ST70_4@12
	float v12; // ST6C_4@12
	float v13; // ST10_4@12
	float v14; // ST0C_4@12
	float v15; // ST20_4@15
	float v16; // ST1C_4@15
	float v17; // ST68_4@15
	float v18; // ST64_4@15
	float v19; // ST10_4@15
	float v20; // ST0C_4@15
	int v21; // eax@17
	int v22; // eax@19
	float v23; // ST30_4@19
	float v24; // ST60_4@19
	int v25; // eax@19
	float v26; // ST5C_4@19
	float v27; // ST58_4@19
	float v28; // ST54_4@22
	float v29; // ST50_4@22
	float v30; // ST4C_4@22
	float v31; // ST48_4@22
	int v32; // eax@23
	int v33; // eax@23
	float v34; // ST2C_4@23
	float v35; // ST44_4@23
	int v36; // eax@23
	float v37; // ST30_4@23
	float v38; // ST40_4@23
	int v39; // eax@23
	float v40; // ST30_4@23
	float v41; // ST2C_4@23
	float v42; // ST3C_4@23
	float v43; // ST38_4@23
	int v44; // [sp+78h] [bp-3Ch]@1
	float v45; // [sp+7Ch] [bp-38h]@3
	float v46; // [sp+88h] [bp-2Ch]@6
	float v47; // [sp+8Ch] [bp-28h]@1
	float v48; // [sp+90h] [bp-24h]@3
	float v49; // [sp+94h] [bp-20h]@6
	float v50; // [sp+98h] [bp-1Ch]@6
	float v51; // [sp+9Ch] [bp-18h]@3
	float v52; // [sp+A4h] [bp-10h]@3
	float v53; // [sp+A8h] [bp-Ch]@3
	signed int i; // [sp+ACh] [bp-8h]@3
	int j; // [sp+ACh] [bp-8h]@17
	int k; // [sp+ACh] [bp-8h]@20
	float v57; // [sp+B0h] [bp-4h]@3

	v44 = a1;
	v47 = 45.0;

	ObjectPointer = &*(ObjectPreview*)(*(DWORD *)0x7BC4F04);
	DIRPointer = (double) 135.0f + ( 45 * abs((signed int)(ObjectPointer->m_Model.Angle.Z / 45.0)));

	if ( *(BYTE *)(a1 + 13500) )
	{
		pSetBlend(1);
		pDrawBarForm(0.0, 0.0, 640.0, 480.0, 0.45000002, 1);
		pGLSwitch();

		pSetBlend(1);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		
		v53 = (double)*(signed int *)(oUserPreviewStruct + 172) / 256.0 * (double)*(signed int *)(a1 + 8 * *(DWORD *)(a1 + 124) + 80);

		v48 = (double)*(signed int *)(oUserPreviewStruct + 176) / 256.0 * (double)*(signed int *)(a1 + 8 * *(DWORD *)(a1 + 124) + 76);

		v52 = 0.65156251;
		v45 = 1.0;
		v57 = 35.0;
		v51 = 6.0;
		blue = (double)*(signed int *)(a1 + 8 * *(DWORD *)(a1 + 124) + 80);
		green = (double)*(signed int *)(a1 + 8 * *(DWORD *)(a1 + 124) + 76);
		v7 = (double)*(signed int *)(a1 + 8 * *(DWORD *)(a1 + 124) + 80) - v53;
		v8 = (double)*(signed int *)(a1 + 8 * *(DWORD *)(a1 + 124) + 76) - v48;
		//-- PINTA el Mapa
		pDrawMapFull(32447, v8, v7, green, blue, v47);

		//-- CICLO PARA PINTAR LOS NPC
		for ( i = 0; i < 100 && (signed int)*(BYTE *)(v44 + 116 * i + 300) > 0; ++i )
		{
			v50 = (double)*(signed int *)(v44 + 116 * i + 304) / 256.0
				* (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 80);
			v46 = (double)*(signed int *)(v44 + 116 * i + 308) / 256.0
				* (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 76);
			v49 = (double)*(signed int *)(v44 + 116 * i + 312);

			if ( *(BYTE *)(v44 + 116 * i + 300) == 1 )
			{
				if ( pMapNumber != 34 || (signed int)(unsigned __int8)0x986746A <= 0 || *(DWORD *)(v44 + 116 * i + 304) == 228 && *(DWORD *)(v44 + 116 * i + 308) == 48 && pMapNumber == 34 )
				{
					//-- PINTAMOS LOS NPC
					v9 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 80);
					v10 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 76);
					v11 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 80) - v53;
					v12 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 76) - v48;
					v13 = (double)25;
					v14 = (double)25;

					pDrawMapObject(32452, v46, v50, v14, v13, v12, v11, v10, v9, v47, v49, 0.546875, 0.546875, i);
				}
			}
			else if ( *(BYTE *)(v44 + 116 * i + 300) == 2 )
			{
				//-- PINTAMOS PORTAL
				v15 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 80);
				v16 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 76);
				v17 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 80) - v53;
				v18 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 76) - v48;
				v19 = (double)30;
				v20 = (double)30;

				pDrawMapObject(32451, v46, v50, v20, v19, v18, v17, v16, v15, v47, v49, 0.546875, 0.546875, i + 100);
			}
		}
		//-- PINTAMOS AL PERSONAJE
		sub_637E80( 32450, 325.0, 230.0, 15.0, 15.0, DIRPointer, 0.0, 0.0, 0.546875, 0.546875);
		
		//v21 = pMakeColor(255, 255, 255, 255);
		//RenderBitMapColored(32450, 325.0, 230.0, 15.0, 15.0, 0.0, 0.0, 0.546875, 0.546875, v21);

		pGLSwitch();
		glColor3f(1.0, 1.0, 1.0);
		pSetBlend(false);
		result = 1;
	}
	else
	{
		result = *(BYTE *)(a1 + 13500);
	}

	return result;
}

void DataMapTronLoad()
{
	int v4; // [sp+Ch] [bp-Ch]@5
	int v5; // [sp+10h] [bp-8h]@2
	int Type;
	int Multiplicador;
	int Scalado;

	Type = gRenderMapTron.DataMapTron.Scale;
	Multiplicador = (( Type == 1 ) ? 1 : Type - 1 );
	Scalado = (( Type == 1 ) ? 512 : 128 );

	gRenderMapTron.DataMapTron.This_92 = *(DWORD *)(*(DWORD *)0x7BC4F04 + 172) / ((Type == 1) ? 0.5 : Type - 1 ); //-- X
	gRenderMapTron.DataMapTron.This_96 = (256 - *(DWORD *)(*(DWORD *)0x7BC4F04 + 176)) / ((Type == 1) ? 0.5 :  Type - 1  ); //-- Y

	//-- X
	if ( gRenderMapTron.DataMapTron.This_92 - ( Multiplicador << 6 ) <= 0 )
		v5 = 0;
	else
		v5 = gRenderMapTron.DataMapTron.This_92 - ( Multiplicador << 6 );

	gRenderMapTron.DataMapTron.This_108 = ( v5 >= Scalado ) ? Scalado : (v5 <= 0) ? 0: gRenderMapTron.DataMapTron.This_92 + 25 - ( Multiplicador << 6 );

	//-- Y
	if ( gRenderMapTron.DataMapTron.This_96 - ( Multiplicador << 6 ) <= 0 )
		v4 = 0;
	else
		v4 = gRenderMapTron.DataMapTron.This_96 - ( Multiplicador << 6 );

	gRenderMapTron.DataMapTron.This_112 = ( v4 >= Scalado ) ? Scalado : (v4 <= 0) ? 0: gRenderMapTron.DataMapTron.This_96 + 15 - ( Multiplicador << 6 );

	gRenderMapTron.DataMapTron.DropMoveUserX = gRenderMapTron.DataMapTron.XSW_Minimap + gRenderMapTron.DataMapTron.This_92 - gRenderMapTron.DataMapTron.This_108;
	gRenderMapTron.DataMapTron.DropMoveUserY = gRenderMapTron.DataMapTron.YSW_Minimap + gRenderMapTron.DataMapTron.This_96 - gRenderMapTron.DataMapTron.This_112;

	gRenderMapTron.DataMapTron.CurrentMoveX = (double)gRenderMapTron.DataMapTron.This_108 / ((double) ((Type == 1) ? 512 : 256 ) / (double)Multiplicador );
	gRenderMapTron.DataMapTron.CurrentMoveY = (double)gRenderMapTron.DataMapTron.This_112 / ((double) ((Type == 1) ? 512 : 256 ) / (double)Multiplicador );
}

void DataViewPortMapTronLoad()
{
	int Model;
	int Type;
	float XNPC, YNPC;

	Type = gRenderMapTron.DataMapTron.Scale;

	for (int i = 0; i < 400; ++i )
	{
		Model = pGetPreviewStruct(pPreviewThis(), i);
		if ( Model
			&& *(BYTE *)(Model + 780)
			&& Model != *(DWORD *)0x7BC4F04
			&& (*(BYTE *)(Model + 800) == 1 || *(BYTE *)(Model + 800) == 2 || *(BYTE *)(Model + 800) == 4) )
		{
			{
				XNPC = (double) gRenderMapTron.DataMapTron.XSW_Minimap + *(DWORD *)(Model + 172) / ((Type == 1) ? 0.5 : Type - 1 );
				YNPC = (double) gRenderMapTron.DataMapTron.YSW_Minimap + (256 - *(DWORD *)(Model + 176)) / ((Type == 1) ? 0.5 : Type - 1 );

				XNPC = XNPC - gRenderMapTron.DataMapTron.This_108 - 5;
				YNPC = YNPC - gRenderMapTron.DataMapTron.This_112 - 5;
				{
					RenderBitMapColored(31471, XNPC, YNPC, 7.0, 7.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255)); //Icono Monster
				}
			}
				//Aqui agregar ID de los Guard
				if( *(WORD *)(Model + 132) == 249
					|| *(WORD *)(Model + 132) == 247
					|| *(WORD *)(Model + 132) == 241) 
				{
					RenderBitMapColored(31472, XNPC, YNPC, 7.0, 7.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(0, 0, 255, 255)); //Icono Guard
				}

				else if ( *(BYTE *)(Model + 800) == 4  &&  *(WORD *)(Model + 132) != 249 )
			{

				if( *(WORD *)(Model + 132) == 251 )
				{
					RenderBitMapColored(31466, XNPC, YNPC, 7.0, 7.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255)); //Icono NPC
				}
				else if( *(WORD *)(Model + 132) == 255 || *(WORD *)(Model + 132) == 253 )
				{
					RenderBitMapColored(31467, XNPC, YNPC, 7.0, 7.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255)); //Icono NPC
				}
				else if( *(WORD *)(Model + 132) == 240 ) //-- Baul
				{
					RenderBitMapColored(31468, XNPC, YNPC, 7.0, 7.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255)); //Icono Baul
				}
				else if( *(WORD *)(Model + 132) == 229 || *(WORD *)(Model + 132) == 235 || *(WORD *)(Model + 132) == 233 || *(WORD *)(Model + 132) == 237 ) //-- Quest
				{
					RenderBitMapColored(31469, XNPC, YNPC, 7.0, 7.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255)); //Icono Quest
				}
				else
				{
					RenderBitMapColored(32452, XNPC, YNPC, 7.0, 7.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255)); //Icono Potion
				}

				//if( pCheckMouseOver((int) XNPC, (int) YNPC, (int) 10, (int) 10) )
				{
				//pDrawToolTip((int) XNPC, (int) YNPC - 10, (char *)(Model + 56));
				}
			}
		}
	}
}

int TimerEventVK;

void Interface::DrawMiniMapTron()
{
	if(gRenderMapTron.DataMapTron.ModelID == -1)
	{
		return;
	}

	if (this->MiniMapCheck() || this->CheckMap() 
		|| !MiniMap || this->CheckWindow(FullMap) 
		|| this->CheckWindow(FriendList) || gInterface.CheckWindow(SkillTree) 
		|| gInterface.CheckWindow(CashShop) || gInterface.CheckWindow(FastMenu))
	{
		return;
	}

	float DIRPointer;
	lpViewObj ObjectPointer;
	char Cord[256];
	float v8; // ST34_4@1
	float v9; // ST30_4@1
	float v10; // ST08_4@1
	float v11; // ST04_4@1
	int Type;
	int Multiplicador;
	int Scalado;

	ObjectPointer = &*(ObjectPreview*)(*(DWORD *)0x7BC4F04);
	DIRPointer =  180 + ( 45 * abs((signed int)(ObjectPointer->m_Model.Angle.Z / 45.0)));

	Type = gRenderMapTron.DataMapTron.Scale;

	DataMapTronLoad();

	v8 = (double) (( Type == 1 ) ? 0.18f : (( Type == 2 ) ? 0.5f : 1.0));
	v9 = (double) (( Type == 1 ) ? 0.18f : (( Type == 2 ) ? 0.5f : 1.0));

	v10 = (double) gRenderMapTron.DataMapTron.YSW_Minimap + 10;
	v11 = (double) gRenderMapTron.DataMapTron.XSW_Minimap;
	//-- Fondo
	RenderBitmap(31464, v11 - 10, v10 - 10, 100, 100, 0.3699999452, 0.0625, 0.5779999495, 0.2889999151, 1, 1, 0.0); //Minimapa v2
	//-- Mapa
	RenderBitmap(31462, v11, v10, 80, 80, gRenderMapTron.DataMapTron.CurrentMoveX, gRenderMapTron.DataMapTron.CurrentMoveY, v9, v8, 1, 1, gRenderMapTron.DataMapTron.Alpha); //Minimapa v2
	//-- Cabezera
	RenderBitmap(31463, v11 + 25, v10 + 84, 30, 13, 0.3259999454, 0.00249999878, 0.6679999232, 0.04399995133, 1, 1, 0.0); //Minimapa v2
	/*RenderBitmap(31463, v11 + 11, v10 - 23, 60, 13, 0.3259999454, 0.00249999878, 0.6679999232, 0.04399995133, 1, 1, 0.0); //Minimapa v2
	//--Nombre Mapas Minimapa v2
	pSetFont(pTextThis(), (int)pFontBold);
	wsprintf(Cord, "%s", ((World >= 82 && World <= 100) ? pGetTextLine(pTextLineThis, (3810 + World - 82)) : pMapName(World)));
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 240, 240, 240, 255);
	pDrawText(pTextThis(), v11 + 25, v10 - 19, Cord, 148.0, 0, (LPINT)1, 0); //Minimapa v2*/
	//-- Coordenadas Minimapa v2
	pSetFont(pTextThis(), (int)pFontBold);
	wsprintf(Cord, "%d , %d", ObjectPointer->MapPosX, ObjectPointer->MapPosY);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 240, 240, 240, 255);
	pDrawText(pTextThis(), v11 + 30, v10 + 89, Cord, 148.0, 0, (LPINT)1, 0); //Minimapa v2


	//-- Usuario
	if ( gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 )
	{	/*//Puntero jugador clasico para 97/99 (Punto amarillo)
		pSetBlend(true);
		glColor4f(1.0, 1.0, 0.0, gRenderMapTron.DataMapTron.Alpha);
		pDrawBarForm((double)gRenderMapTron.DataMapTron.DropMoveUserX, (double)gRenderMapTron.DataMapTron.DropMoveUserY, 4.0, 4.0, 0.0, 0);
		pGLSwitch();*/

		//Puntero jugador ex700 para 97/99
		sub_637E80( 32450, (double)gRenderMapTron.DataMapTron.DropMoveUserX, (double)gRenderMapTron.DataMapTron.DropMoveUserY, 8.0, 8.0, DIRPointer, 0.0, 0.0, 0.546875, 0.546875); //Puntero personaje 97/99/s1/s2
	}
	else
	if ( gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4 )
	{
		sub_637E80( 32450, (double)gRenderMapTron.DataMapTron.DropMoveUserX, (double)gRenderMapTron.DataMapTron.DropMoveUserY, 8.0, 8.0, DIRPointer, 0.0, 0.0, 0.546875, 0.546875); //Puntero personaje s3/s6/ex700/legends
	}
	/*float JCPartyCoordOX;
	float JCPartyCoordOY;
	float JCPartyCoordX;
	float JCPartyCoordY;

	for(int i = 0; i < pPartyMemberCount ; i++)
	{
		if( !strcmp(pGetStrutParty( i ).Name, pGetUserName) )
		{
			continue;
		}

		JCPartyCoordOX = (double) gRenderMapTron.DataMapTron.XSW_Minimap + (gMiniMap.gPartyInfo[ i ].x) / ((Type == 1) ? 0.5 : Type - 1 );
		JCPartyCoordOY = (double) gRenderMapTron.DataMapTron.YSW_Minimap + (255 - (gMiniMap.gPartyInfo[ i ].y) ) / ((Type == 1) ? 0.5 : Type - 1 );

		JCPartyCoordX = JCPartyCoordOX - gRenderMapTron.DataMapTron.This_108 - 5;
		JCPartyCoordY = JCPartyCoordOY - gRenderMapTron.DataMapTron.This_112 - 5;

		sub_790DF0(61520, JCPartyCoordX, JCPartyCoordY, 10.0, 10.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, gRenderMapTron.DataMapTron.Alpha * 255));
	}*/

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, gRenderMapTron.DataMapTron.Alpha);

	DataViewPortMapTronLoad();
	int textAlpha;

	if ( gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 )
	{
		//Interface minimapa 97/99 original
		/*pSetBlend(true);
		glColor4f(1.0, 1.0, 1.0, gRenderMapTron.DataMapTron.Alpha);
		pDrawGUI(31608, gRenderMapTron.DataMapTron.XSW_Minimap_Frame, gRenderMapTron.DataMapTron.YSW_Minimap_Frame, 154.0, 162.0);
		pDrawGUI(31609, gRenderMapTron.DataMapTron.XSW_Time_Frame, gRenderMapTron.DataMapTron.YSW_Time_Frame, 134.0, 37.0);
		pGLSwitch();*/

		if(CheckButtonPressed( 618, 240, 15, 15 ))
		{
			PlayBuffer(25, 0, 0);
			
			if (GetTickCount() >= TimerEventVK + 200) 
			{
				if ( gRenderMapTron.DataMapTron.Scale == 1 ) 
				{
					gRenderMapTron.DataMapTron.Scale = 2;
				}
				else if ( gRenderMapTron.DataMapTron.Scale == 2 ) 
				{
					gRenderMapTron.DataMapTron.Scale = 3;
				}
				else if ( gRenderMapTron.DataMapTron.Scale == 3 ) 
				{ 
					gRenderMapTron.DataMapTron.Scale = 1; 
				}

				TimerEventVK = GetTickCount();
			}
		}

		if(CheckButtonPressed( 546, 239, 35, 20 ))
		{
			PlayBuffer(25, 0, 0);
			
			if (GetTickCount() >= TimerEventVK + 200) 
			{
				if ( gRenderMapTron.DataMapTron.Alpha == 1.0 ) 
				{
					gRenderMapTron.DataMapTron.Alpha = (double) 0.90f;
				}
				else if ( gRenderMapTron.DataMapTron.Alpha == 0.90f ) 
				{
					gRenderMapTron.DataMapTron.Alpha = (double)0.80;
				}
				else if ( gRenderMapTron.DataMapTron.Alpha == 0.80f ) 
				{ 
					gRenderMapTron.DataMapTron.Alpha = (double)0.70f;
				}
				else
				{
					gRenderMapTron.DataMapTron.Alpha = (double)1.0f;
				}

				TimerEventVK = GetTickCount();
			}
		}
		//Opacidad para Interface 97/99 original
		/*if ( gRenderMapTron.DataMapTron.Alpha == 1.0 ) 
		{
			textAlpha = 100;
		}
		else if ( gRenderMapTron.DataMapTron.Alpha == 0.90f ) 
		{
			textAlpha = 90;
		}
		else if ( gRenderMapTron.DataMapTron.Alpha == 0.80f ) 
		{ 
			textAlpha = 80;
		}
		else
		{
			textAlpha = 70;
		}*/

		
	}

	pGLSwitch();
	EnableAlphaTest(0);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	//Menu Opacidad Interface 97/99 original
	/*if ( gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 )
	{
		char Info[20];
		wsprintf(Info, "%d", textAlpha);
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pSetTextColor(pTextThis(), 240, 240, 240, 255);
		pDrawText(pTextThis(), 546, 245, Info, 35, 0, (LPINT)3, 0);
	}*/

	//-- Carcasa Mapa
	RenderBitmap(31465, v11 - 10, v10 - 10, 100, 100, 0.01299999747, 0.02999999747, 0.3105553985, 0.6109998822, 1, 1, 0.0); //Minimapa v2

	int x1, y1, w1, h1;

	//-- Boton Acercar
	x1 = v11 - 5; //Minimapa v2
	y1 = v10 + 67; //Minimapa v2
	w1 = 18;
	h1 = 18;
	//-- Carcaza Boton
	//RenderBitmap(31463, x1 - 4, y1 - 5, 26, 26, 0.8360000253, 0.4990000129, 0.1519999206, 0.073999919, 1, 1, 0.0); //Circulo

	if(pCheckMouseOver( x1, y1, w1, h1 ))
	{
		this->DrawToolTip(v11 + 26, v10 - 20, "Zoom (-)");
		if( *(BYTE*)0x8793386 )
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.43160009804, 0.1219998896, 0.06599189341, 1, 1, 0.0);
			PlayBuffer(25, 0, 0);
			if( GetTickCount() >= gRenderMapTron.DataMapTron.TimerEventVK + 200 )
			{
				if ( gRenderMapTron.DataMapTron.Scale == 3 ) 
				{ 
					gRenderMapTron.DataMapTron.Scale = 2; 
				}
				else if ( gRenderMapTron.DataMapTron.Scale == 2 ) 
				{ 
					gRenderMapTron.DataMapTron.Scale = 1; 
				}

				gRenderMapTron.DataMapTron.TimerEventVK = GetTickCount();
			}
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.43160009804, 0.1219998896, 0.06599189341, 1, 1, 0.0); //0,3689999878 + 0,06260011024
		}
		
	}
	else
	{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.43160009804, 0.1219998896, 0.06599189341, 1, 1, 0.0);
	}

	//-- Boton Alejar
	x1 = v11 - 13; //Minimapa v2
	y1 = v10 + 54; //Minimapa v2
	//-- Carcaza Boton
	//RenderBitmap(31463, x1 - 4, y1 - 5, 26, 26, 0.8360000253, 0.4990000129, 0.1519999206, 0.073999919, 1, 1, 0.0); //Circulo

	if(pCheckMouseOver( x1, y1, w1, h1 ))
	{
		this->DrawToolTip(v11 + 26, v10 - 20, "Zoom (+)");
		if( *(BYTE*)0x8793386 )
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.3689999878, 0.1219998896, 0.06599189341, 1, 1, 0.0);
			PlayBuffer(25, 0, 0);

			if( GetTickCount() >= gRenderMapTron.DataMapTron.TimerEventVK + 200 )
			{
				if ( gRenderMapTron.DataMapTron.Scale == 1 ) 
				{ 
					gRenderMapTron.DataMapTron.Scale = 2; 
				}
				else if ( gRenderMapTron.DataMapTron.Scale == 2 ) 
				{ 
					gRenderMapTron.DataMapTron.Scale = 3; 
				}

				gRenderMapTron.DataMapTron.TimerEventVK = GetTickCount();
			}
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.3689999878, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
		
	}
	else
	{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.3689999878, 0.1219998896, 0.06599189341, 1, 1, 0.0);
	}
	if(pCheckMouseOver( x1, y1, w1, h1 ))
	{
		if( *(BYTE*)0x8793386 )
		{
			PlayBuffer(25, 0, 0);
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, !*(BYTE*)(*(DWORD*)(0x00E8CB7C) + 0x08) ? 0.3689999878 : 0.5570000539, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, !*(BYTE*)(*(DWORD*)(0x00E8CB7C) + 0x08) ? 0.3689999878 : 0.5570000539, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
	}
	else
	{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, !*(BYTE*)(*(DWORD*)(0x00E8CB7C) + 0x08) ? 0.3689999878 : 0.5570000539, 0.1219998896, 0.06599189341, 1, 1, 0.0);
	}

	//-- Boton Config(Opciones Mu Helper)
	x1 = v11 + 66; //Minimapa v2
	y1 = v10 + 68; //Minimapa v2
	//-- Carcaza Boton
	//RenderBitmap(31463, x1 - 3, y1 - 5, 26, 26, 0.8360000253, 0.4990000129, 0.1519999206, 0.073999919, 1, 1, 0.0); //Circulo

	if(pCheckMouseOver( x1, y1, w1, h1 ))
	{
		this->DrawToolTip(v11 + 26, v10 - 20, "Config Helper");
		if( *(BYTE*)0x8793386 )
		{
			PlayBuffer(25, 0, 0);
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.682000539, 0.1219998896, 0.06599189341, 1, 1, 0.0); 
			if( GetTickCount() >= gRenderMapTron.DataMapTron.TimerEventVK + 200 )
			{
				gInterface.OpenConfig(0);
				gRenderMapTron.DataMapTron.TimerEventVK = GetTickCount();
			}		
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.682000539, 0.1219998896, 0.06599189341, 1, 1, 0.0); 
		}
	}
	else
	{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.682000539, 0.1219998896, 0.06599189341, 1, 1, 0.0); 
	}

	//-- Boton Menu Especial
	x1 = v11 + 66; //Minimapa v2
	y1 = v10 - 3; //Minimapa v2
	//-- Carcaza Boton
	//RenderBitmap(31463, x1 - 3, y1 - 5, 26, 26, 0.8360000253, 0.4990000129, 0.1519999206, 0.073999919, 1, 1, 0.0); //Circulo

	if(pCheckMouseOver( x1, y1, w1, h1 ))
	{
		this->DrawToolTip(v11 + 26, v10 - 20, "Especial Menu");
		if( *(BYTE*)0x8793386 )
		{
			PlayBuffer(25, 0, 0);
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.55680031852, 0.1219998896, 0.06599189341, 1, 1, 0.0);
			if( GetTickCount() >= gRenderMapTron.DataMapTron.TimerEventVK + 200 )
			{
				gInterface.OpenConfig(0);
				gRenderMapTron.DataMapTron.TimerEventVK = GetTickCount();
			}
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.55680031852, 0.1219998896, 0.06599189341, 1, 1, 0.0); 
		}
	}
	else
	{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.55680031852, 0.1219998896, 0.06599189341, 1, 1, 0.0); 
	}

	//-- Boton 3D
	x1 = v11 - 4; //Minimapa v2
	y1 = v10 - 3; //Minimapa v2
	//-- Carcaza Boton
	//RenderBitmap(31463, x1 - 4, y1 - 5, 26, 26, 0.8360000253, 0.4990000129, 0.1519999206, 0.073999919, 1, 1, 0.0); //Circulo

	if(pCheckMouseOver( x1, y1, w1, h1 ))
	{
		this->DrawToolTip(v11 + 26, v10 - 20, "Camera 3D");
		if( *(BYTE*)0x8793386 )
		{
			PlayBuffer(25, 0, 0);
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.61940042876, 0.1219998896, 0.06599189341, 1, 1, 0.0);
			if( GetTickCount() >= gRenderMapTron.DataMapTron.TimerEventVK + 200 )
			{
				gInterface.SwitchCamera();
				gRenderMapTron.DataMapTron.TimerEventVK = GetTickCount();
			}
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.61940042876, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
	}
	else
	{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.61940042876, 0.1219998896, 0.06599189341, 1, 1, 0.0);
	}

	//-- Boton Star
	x1 = v11 + 75; //Minimapa v2
	y1 = v10 + 54; //Minimapa v2
	//-- Carcaza Boton
	//RenderBitmap(31463, x1 - 3, y1 - 5, 26, 26, 0.8360000253, 0.4990000129, 0.1519999206, 0.073999919, 1, 1, 0.0); //Circulo

	if(pCheckMouseOver( x1, y1, w1, h1 ))
	{
		this->DrawToolTip(v11 + 26, v10 - 20, "Play Helper");
		if( *(BYTE*)0x8793386 )
		{
			PlayBuffer(25, 0, 0);
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.49420020828, 0.1219998896, 0.06599189341, 1, 1, 0.0);
			if( GetTickCount() >= gRenderMapTron.DataMapTron.TimerEventVK + 200 )
			{
				gInterface.OpenConfig(0);
				gRenderMapTron.DataMapTron.TimerEventVK = GetTickCount();
			}
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.49420020828, 0.1219998896, 0.06599189341, 1, 1, 0.0); 
		}
	}
	else
	{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.49420020828, 0.1219998896, 0.06599189341, 1, 1, 0.0); 
	}

	//-- Boton Armadura (Inventario)
	x1 = v11 + 79; //Minimapa v2
	y1 = v10 + 32; //Minimapa v2
	//-- Carcaza Boton
	//RenderBitmap(31463, x1 - 4, y1 - 5, 26, 26, 0.8360000253, 0.4990000129, 0.1519999206, 0.073999919, 1, 1, 0.0); //Circulo

	if(pCheckMouseOver( x1, y1, w1, h1 ))
	{
		this->DrawToolTip(v11 + 26, v10 - 20, "Inventory");
		if( *(BYTE*)0x8793386 )
		{
			PlayBuffer(25, 0, 0);
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.80420075948, 0.1219998896, 0.06599189341, 1, 1, 0.0);
			if( GetTickCount() >= gRenderMapTron.DataMapTron.TimerEventVK + 200 )
			{
			gInterface.OpenWindow(Inventory);
			}	
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.80420075948, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
	}
	else
	{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.80420075948, 0.1219998896, 0.06599189341, 1, 1, 0.0);
	}

	//-- Boton Config(Opciones del juego)
	x1 = v11 + 77; //Minimapa v2
	y1 = v10 + 17; //Minimapa v2
	//-- Carcaza Boton
	//RenderBitmap(31463, x1 - 4, y1 - 5, 26, 26, 0.8360000253, 0.4990000129, 0.1519999206, 0.073999919, 1, 1, 0.0); //Circulo

	if(pCheckMouseOver( x1, y1, w1, h1 ))
		
	{
		this->DrawToolTip(v11 + 26, v10 - 20, "System Option");
		if( *(BYTE*)0x8793386 )
		{
			PlayBuffer(25, 0, 0);
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.93240097996, 0.1219998896, 0.06599189341, 1, 1, 0.0);
			if( GetTickCount() >= gRenderMapTron.DataMapTron.TimerEventVK + 200 )
			{
				gInterface.OpenConfig(0);
				gRenderMapTron.DataMapTron.TimerEventVK = GetTickCount();
			}		
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.93240097996, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
	}
	else
	{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.93240097996, 0.1219998896, 0.06599189341, 1, 1, 0.0);
	}

	//-- Boton Camara
	x1 = v11 - 12; //Minimapa v2
	y1 = v10 + 9; //Minimapa v2
	//-- Carcaza Boton
	//RenderBitmap(31463, x1 - 4, y1 - 5, 26, 26, 0.8360000253, 0.4990000129, 0.1519999206, 0.073999919, 1, 1, 0.0); //Circulo

	if(pCheckMouseOver( x1, y1, w1, h1 ))
	{
		this->DrawToolTip(v11 + 26, v10 - 20, "Camera 3D Restore");
		if( *(BYTE*)0x8793386 )
		{
			PlayBuffer(25, 0, 0);
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.74460064924, 0.1219998896, 0.06599189341, 1, 1, 0.0);
			if( GetTickCount() >= gRenderMapTron.DataMapTron.TimerEventVK + 200 )
			{
			gInterface.CameraInit();
			}
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.74460064924, 0.1219998896, 0.06599189341, 1, 1, 0.0); 
		}
	}
	else
	{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.74460064924, 0.1219998896, 0.06599189341, 1, 1, 0.0); 
	}
}

bool MiniMapTronFileCheck1(int Map) // OK
{
	if(Map - 1 == 30){return 0;}
	
	char Path[64];

	wsprintf(Path, "Data\\Custom\\Maps\\World%d.ozj", Map);

	int File = rFileOpen(Path, "rb");

	if ( File )
	{
		rFileClose(File);
		return 1;
	}
	else
	{
		return 0;
	}
}

void MiniMapTronLoad() // OK
{
	if (pMapNumber < MAX_MINI_MAP_TRON && pMapNumber != 30)
	{
		char buff[32];

		wsprintf(buff, "Custom\\Maps\\World%d.jpg", ( pMapNumber + 1 ));
		
		if (MiniMapTronFileCheck1( pMapNumber + 1 ) != 0)
		{
			gRenderMapTron.DataMapTron.ModelID = 31462;
			pLoadImage(buff, 31462, 0x2601, 0x2900, 1, 0);
		}
		else
		{
			gRenderMapTron.DataMapTron.ModelID = -1;
		}
	}
}

__declspec(naked) void LoadTextureMapTron()
{
	static DWORD Addr2_JMP = 0x0062F8A6;
	static DWORD Addr1_JMP = 0x0062F87C;
	static DWORD Map = 0x007AA331;

	_asm
	{
		MOV EAX, DWORD PTR SS:[EBP-0x78]
		MOV Map, EAX
	}
	if ( Map == 74 || Map == 75 )
	{
		_asm
		{
			JMP[Addr2_JMP]
		}
	}
	else
	{
		MiniMapTronLoad();
		_asm
		{
			JMP[Addr1_JMP]
		}
	}
}

bool pDisabledMouseMAPTron(int x, int y, int w, int h)
{
	return 0;
}

void CMinimapTron::MiniMapTronload()
{
	SetCompleteHook(0xE8, 0x0082B772, &pDisabledMouseMAPTron); //ok

	SetCompleteHook(0xE9, 0x0062F870, &LoadTextureMapTron); //ok
	SetCompleteHook(0xE9, 0x0082ABA0, &CMinimapTron::MapTronRender);
}