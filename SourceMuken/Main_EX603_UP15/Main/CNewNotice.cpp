#include "stdafx.h"
#include "CNewNotice.h"
#include "Defines.h"
#include "TMemory.h"
#include "Util.h"

#define pFontBold					*(HGDIOBJ*)0xE8C58C
#define EnableAlphaTest				((void(__cdecl*)(char a1)) 0x00635FD0)
#define pWindowThis                 ((LPVOID(*)()) 0x861110)
#define pCheckWindow		      	((bool(__thiscall*)(LPVOID This, int Code)) 0x0085EC20)
#define pSetTextSize				((int(__thiscall*)(LPVOID This, HFONT a2)) 0x420120)
#define pTextThis				    ((LPVOID(*)()) 0x0041FE10)
#define Notice                      *(int*)0x98671D4
#define NoticeInverse               *(int*)0x81C0418
#define NoticeCount                 *(int*)0x81C0414
#define pSetTextColor			    ((void(__thiscall*)(LPVOID This, BYTE r, BYTE g, BYTE b, BYTE h)) 0x00420040)
#define pSetBackgroundTextColor	    ((void(__thiscall*)(LPVOID This, int r, int g, int b, int h)) 0x004200B0)
#define pDrawText				    ((int(__thiscall*)(LPVOID This, int PosX, int PosY, LPCTSTR Text, int nCount, int nTabPositions, LPINT lpnTabStopPositions, int nTabOrigin)) 0x00420150)
#define pDrawMessage			    ((int(__cdecl*)(LPCSTR Text, int Mode)) 0x00597630)
#define sub_41FF80					((int(__thiscall*)(LPVOID This)) 0x0041FF80)
#define sub_401C10					((int(*)())0x401C10)
#define _GetTextExtentPoint			((int(__stdcall*)(HDC This, LPCSTR lpMultiByteStr, int, LPSIZE psizl)) 0x9593B0)
#define strlen                      ((int(__cdecl*)(const char* a1)) 0x009CF130)
#define CutText                     ((WORD(__thiscall*)(const CHAR *lpMultiByteStr, char *a4, char *a5, signed int a6)) 0x597980)
#define pWinWidthReal			    *(float*)0xE7C3D4
#define pWinHeightReal			    *(float*)0xE7C3D8
#define AlphaBlendType              *(int*)0x8793258
#define pDrawBarForm		    	((void(__cdecl*)(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)) 0x6378A0)
#define SetBgColor                  ((void*(__thiscall*)(int This, unsigned __int32 a2)) 0x4200F0)
#define pGLSwitchBlend			    ((void(__cdecl*)()) 0x636070)
#define pGLSwitch				    ((void(__cdecl*)()) 0x635F50)
#define oUserObjectStruct	    	*(int*)0x8128AC8
#define WhisperRegistID             *(int*)0x813DD60
int NoticeTime = 300;

CNewRenderNotice gRenderNotice;

CNewRenderNotice::CNewRenderNotice()
{

}

CNewRenderNotice::~CNewRenderNotice()
{
}

//----- (00597220) --------------------------------------------------------
void RenderTipText(int a3, int a4, LPCSTR lpString){
	HGDIOBJ alpha; // ST18_4@1
	void *v6; // eax@1
	int blue; // ST14_4@1
	void *v8; // eax@1
	HDC red; // ST0C_4@1
	int v10; // eax@1
	int v11; // ST60_4@1
	float v12; // ST5C_4@1
	float v13; // ST58_4@1
	float v14; // ST54_4@1
	float v15; // ST50_4@1
	float v16; // ST4C_4@1
	float v17; // ST48_4@1
	float v18; // ST44_4@1
	float v19; // ST40_4@1
	float v20; // ST3C_4@1
	float v21; // ST38_4@1
	float v22; // ST34_4@1
	float v23; // ST30_4@1
	float v24; // ST2C_4@1
	float v25; // ST28_4@1
	float v26; // ST24_4@1
	float v27; // ST20_4@1
	void *v28; // eax@1
	void *v29; // eax@1
	void *v30; // eax@1
	struct tagSIZE psizl; // [sp+60h] [bp-8h]@1
	HGDIOBJ ho;

	psizl.cx = 0;
	psizl.cy = 0;
	alpha = ho;
	v6 = pTextThis();
	pSetTextSize((LPVOID)v6, (HFONT)alpha);
	blue = lstrlenA(lpString);
	v8 = pTextThis();
	red = (HDC)sub_41FF80((LPVOID)v8);
	v10 = sub_401C10();
	_GetTextExtentPoint((HDC)v10,/*red,*/ lpString, blue, &psizl);
	v11 = AlphaBlendType;
	EnableAlphaTest(1);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	v12 = (double)(signed int)psizl.cx / pWinWidthReal + 4.0;
	v13 = (double)a4 - 3.0;
	v14 = (double)a3 - 2.0;
	pDrawBarForm(v14, v13, v12, 1.0, 0.0, 0);
	v15 = (double)(signed int)psizl.cy / pWinHeightReal + 4.0;
	v16 = (double)a4 - 3.0;
	v17 = (double)a3 - 2.0;
	pDrawBarForm(v17, v16, 1.0, v15, 0.0, 0);
	v18 = (double)(signed int)psizl.cy / pWinHeightReal + 4.0;
	v19 = (double)a4 - 3.0;
	v20 = (double)a3 - 2.0 + (double)(signed int)psizl.cx / pWinWidthReal + 3.0;
	pDrawBarForm(v20, v19, 1.0, v18, 0.0, 0);
	v21 = (double)(signed int)psizl.cx / pWinWidthReal + 4.0;
	v22 = (double)a4 - 3.0 + (double)(signed int)psizl.cy / pWinHeightReal + 3.0;
	v23 = (double)a3 - 2.0;
	pDrawBarForm(v23, v22, v21, 1.0, 0.0, 0);
	glColor4f(0.0, 0.0, 0.0, 0.80000001);
	v24 = (double)(signed int)psizl.cy / pWinHeightReal + 2.0;
	v25 = (double)(signed int)psizl.cx / pWinWidthReal + 2.0;
	v26 = (double)a4 - 2.0;
	v27 = (double)a3 - 1.0;
	pDrawBarForm(v27, v26, v25, v24, 0.0, 0);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glEnable(0xDE1u);
	v28 = pTextThis();
	pSetTextColor((LPVOID)v28, 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	v29 = pTextThis();
	SetBgColor((int)v29, 0);
	v30 = pTextThis();
	pDrawText((LPVOID)v30, a3, a4, (LPCSTR)lpString, 0, 0, (LPINT)1, 0);
	switch (v11)
	{
	case 0:
		pGLSwitch();
		break;
	case 1:
		//EnableLightMap();
		break;
	case 2:
		EnableAlphaTest(1);
		break;
	case 3:
		pGLSwitchBlend();
		break;
	case 4:
		//EnableAlphaBlendMinus();
		break;
	case 5:
		//EnableAlphaBlend2();
		break;
	default:
		pGLSwitch();
		break;
	}
}

//----- (00597580) --------------------------------------------------------
int ScrollNotice(){
	int result; // eax@4
	signed int i; // [sp+0h] [bp-4h]@2
	if (NoticeCount > 5){
		NoticeCount = 5;
		for (i = 1; i < 6; ++i){
			//byte_813DED4[264 * (i - 1)] = byte_813DED4[264 * i];
			strcpy((char*)&Notice + 264 * (i - 1), 0);
			result = i + 1;
		}
	}
	return result;
}

//----- (00597610) --------------------------------------------------------
void *ClearNotice(){//char
	return memset((char *)&Notice, 0, 1584);
}

//----- (00597630) --------------------------------------------------------
void CreateNotice(LPCSTR lpString, char a4){
	HGDIOBJ v4; // ST0C_4@1
	void *v5; // eax@1
	int v6; // ST08_4@1
	void *v7; // eax@1
	HDC v8; // ST00_4@1
	int v9; // eax@1
	char *v10; // ST18_4@2
	int v11; // eax@3
	char *v12; // ST14_4@3
	char *v13; // ST10_4@3
	char v14; // [sp+Ch] [bp-208h]@3
	char v15; // [sp+10Ch] [bp-108h]@3
	struct tagSIZE psizl; // [sp+20Ch] [bp-8h]@1

	v4 = pFontBold;
	v5 = pTextThis();
	pSetTextSize((LPVOID)v5, (HFONT)v4);
	v6 = lstrlenA(lpString);
	v7 = pTextThis();
	v8 = (HDC)sub_41FF80((LPVOID)v7);
	v9 = sub_401C10();
	_GetTextExtentPoint((HDC)v9, (LPCSTR)v8, (int)lpString, (LPSIZE)v6);
	ScrollNotice();
	//byte_813DED4[264 * NoticeCount] = a4;
	if (psizl.cx >= 256)
	{
		v11 = strlen((const char *)lpString);
		CutText(lpString, &v14, &v15, v11);
		v12 = (char *)&Notice + 264 * NoticeCount + 1;//++
		strcpy((char*)v12, 0);
		ScrollNotice();
		//byte_813DED4[264 * NoticeCount] = a4;
		v13 = (char *)&Notice + 264 * NoticeCount + 1;//++
		strcpy((char*)v13, 0);
	}
	else
	{
		v10 = (char *)&Notice + 264 * NoticeCount + 1;//++
		strcpy((char*)v10, 0);
	}
	NoticeTime = 300;
}

//----- (005977A0) --------------------------------------------------------
void MoveNotices(LPCSTR This){
	int v2; // eax@1
	v2 = NoticeTime--;
	if (v2 <= 0){
		NoticeTime = 300;
		pDrawMessage(This, 0);
	}
}
// E6178C: using guessed type int NoticeTime;

//----- (005977E0) --------------------------------------------------------
int RenderNotices(){
	int result; // eax@1
	HGDIOBJ blue; // ST18_4@2
	void *v6; // eax@2
	void *v7; // eax@5
	void *v8; // eax@6
	void *v9; // eax@7
	void *v10; // eax@9
	void *v11; // eax@9
	void *v12; // eax@10
	signed int i; // [sp+10h] [bp-4h]@2

	result = (unsigned __int8)pCheckWindow(pWindowThis, 65);
	if ((unsigned __int8)result != 1){
		EnableAlphaTest(1);
		blue = pFontBold;
		v6 = pTextThis();
		pSetTextSize((LPVOID)v6, (HFONT)blue);
		glColor3f(1.0, 1.0, 1.0);
		for (i = 0; i < 6; ++i){
			if (*((BYTE *)&Notice + 264 * i + 260)){
				v10 = pTextThis();
				pSetTextColor((LPVOID)v10, 0x64u, 0xFFu, 0xC8u, 0xFFu);
				v11 = pTextThis();
				pSetBackgroundTextColor((LPVOID)v11, 0, 0, 0, 0x80u);
			}
			else{
				v7 = pTextThis();
				pSetBackgroundTextColor((LPVOID)v7, 0, 0, 0, 0x80u);
				if (NoticeInverse % 10 >= 5)
				{
					v9 = pTextThis();
					pSetTextColor((LPVOID)v9, 0xFFu, 0xC8u, 0x50u, 0xFFu);
				}
				else
				{
					v8 = pTextThis();
					pSetTextColor((LPVOID)v8, 0xFFu, 0xC8u, 0x50u, 0x80u);
				}
			}
			v12 = pTextThis();
			pDrawText((LPVOID)v12, 320, 13 * i + 300, (LPCSTR)&Notice + 264 * i, 0, 0, (LPINT)8, 0);
		}
		result = NoticeInverse + 1;// (NoticeInverse++ + 1)
	}
	return result;
}

//----- (00597E10) --------------------------------------------------------
int _cdecl pChatCheckLevel(signed int a1, BYTE *a2){
	int result; // eax@1
	signed int i; // [sp+0h] [bp-Ch]@2
	char v4; // [sp+7h] [bp-5h]@2
	result = oUserObjectStruct;
	if (*(WORD *)(oUserObjectStruct + 14) < a1){
		v4 = 1;
		for (i = 0; i < 10; ++i){
			//if (!sub_9D09B0(a2, &byte_813DD60[10 * i])){
			//	v4 = 0;
			//	break;
			//}
		}
		result = (unsigned __int8)v4;
		if (v4){
			//strcpy((int)&byte_813DD60[10 * dword_81C041C]);
			//result = dword_81C041C++ + 1;
			//if (dword_81C041C >= 10)
			//	dword_81C041C = 0;
		}
	}
	return result;
}

//----- (00597EC0) --------------------------------------------------------
void *ClearWhisperID(){//char
	return memset((char *)&WhisperRegistID, 0, 110);
}

#define g_iChatInputType *(DWORD*)0xE60960
char *InputTextHide;
char *InputText;
#define InputTextWidth   *(DWORD*)0xE6174C
#define InputIndex       *(DWORD*)0x81C0400
int InputFrame;
#define pDrawText2				    ((int(__thiscall*)(LPVOID This, int PosX, int PosY, int aa, int nCount, int nTabPositions, LPINT lpnTabStopPositions, int nTabOrigin)) 0x00420150)
//#define SetPositionIME_Wnd          ((void(__cdecl*)(float a1, float 2)) 0x596B80)
//----- (00596EF0) --------------------------------------------------------
void RenderInputText(int a3, int a4, int a5)
{
	void *v5; // eax@3
	void *v6; // eax@3
	int v7; // ST0C_4@17
	void *v8; // eax@17
	float v9; // ST18_4@18
	float v10; // ST14_4@18
	int v11; // ecx@20
	int v12; // ST00_4@23
	void *v13; // eax@23
	int v14; // ST00_4@24
	void *v15; // eax@24
	int v16; // ST00_4@26
	void *v17; // eax@26
	unsigned int k; // [sp+Ch] [bp-124h]@12
	unsigned int j; // [sp+10h] [bp-120h]@9
	unsigned int v20; // [sp+14h] [bp-11Ch]@9
	unsigned int i; // [sp+18h] [bp-118h]@4
	unsigned int v22; // [sp+1Ch] [bp-114h]@4
	char v23[260]; // [sp+20h] [bp-110h]@6
	char v24; // [sp+124h] [bp-Ch]@17
	char *v25; // [sp+12Ch] [bp-4h]@17

	if (g_iChatInputType != 1 && !g_iChatInputType)
	{
		v5 = pTextThis();
		//pSetTextColor((LPVOID)v5, 0xFFu, 0xE6u, 0xD2u, 0xFFu);
		v6 = pTextThis();
		SetBgColor((int)v6, 0);
		if (InputTextHide[a5] == 1)
		{
			v22 = 0;
			for (i = 0; i < /*sub_9CF130*/strlen(&InputText[256 * a5]); ++i)
			{
				v23[i] = 42;
				v22 = i;
			}
			v23[v22 + 1] = 0;
		}
		else if (InputTextHide[a5] == 2)
		{
			v20 = 0;
			for (j = 0; j < 7; ++j)
			{
				v23[j] = *(&InputText[256 * a5] + j);
				v20 = j;
			}
			for (k = 7; k < strlen(&InputText[256 * a5]); ++k)
			{
				v23[k] = 42;
				v20 = k;
			}
			v23[v20 + 1] = 0;
		}
		else
		{
			strcpy((char*)v23, 0);
		}
		v7 = InputTextWidth;
		v8 = pTextThis();
		pDrawText((LPVOID)v8, a3, a4, (LPCSTR)v23, v7, 0, (LPINT)1, (int)&v24);
		v25 = &v24;
		if (a5 == InputIndex)
		{
			v9 = (double)a4;
			v10 = (double)(*(_DWORD *)v25 + a3);
			//SetPositionIME_Wnd(v10, v9);
		}
		if (a5 == InputIndex)
		{
			v11 = InputFrame++ % 2;
			if (!v11){
				EnableAlphaTest(1);
				if (strlen((char *)(4 * a5 + 135525180))){
					if (InputTextHide[a5] == 1){
						v12 = *(_DWORD *)v25 + a3;
						v13 = pTextThis();
						pDrawText((LPVOID)v13, v12, a4, (LPCTSTR)"**", 0, 0, (LPINT)1, 0);
					}
					else{
						v14 = *(_DWORD *)v25 + a3;
						v15 = pTextThis();
						pDrawText2((LPVOID)v15, v14, a4, (int)4 * a5 + 135525180, 0, 0, (LPINT)1, 0);
					}
				}
				else
				{
					v16 = *(_DWORD *)v25 + a3;
					v17 = pTextThis();
					pDrawText((LPVOID)v17, v16, a4, (LPCTSTR)"_", 0, 0, (LPINT)1, 0);
				}
			}
		}
	}
}

void CNewRenderNotice::Load(){
}
