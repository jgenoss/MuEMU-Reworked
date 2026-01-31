#include "stdafx.h"
#include "GuildLogo.h"
#include "Util.h"
#include "CustomRankUser.h"

#define CreateGuildMark ((void(__cdecl*)(int nMarkIndex, bool blend)) 0x005D30F0)
#define RenderBitmap ((void(__cdecl*)(int Texture, float x, float y, float Width, float Height, float u, float v, float uWidth, float vHeight, bool Scale, bool StartScale, float Alpha)) 0x00637C60)
#define RenderBoolean ((void(__cdecl*)(int x, int y, DWORD c)) 0x005985F0)

void InitGuildIcon()
{
	SetCompleteHook(0xE8, 0x005BAFAB, &DrawLogo);
}

void DrawLogo(int x, int y, DWORD c)
{
	DWORD character = *(DWORD*)(c + 668); //Get Character Struct
	float W = *(DWORD*)(c + 680);
	if (*(BYTE*)(character + 800) == 1) //Check Character Type
	{
		if (*(short*)(character + 124) != -1) //Check Character Guild
		{
			float posX = (float)x - 21.0f;

			if (*(BYTE*)(character + 31) != 0) //Check Character Gens
			{
				posX += 93.0f;
			}

			CreateGuildMark(*(WORD*)(character + 124), true); //CreateGuildMark

			RenderBitmap(31740, posX, (float)y, 18.0f, 18.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1, 1, 0); //RenderBitmap
		}
	}
	//===Fix VI Tri Rank
	DWORD ViewportAddress = *(DWORD*)(c + 668);

	if (*(BYTE*)(ViewportAddress + 0x320) == 1) //Check User Type
	{
		float PosX = x;
		float PosY = y;
		//gObjUser.m_Logo[n].Active = 1;
		//gObjUser.m_Logo[n].X = PosX;
		//gObjUser.m_Logo[n].Y = PosY;

		gCustomRankUser.RenderShowLogRank(ViewportAddress, *(WORD*)(ViewportAddress + 0x7E), (PosX + (W/2))-40, PosY+25);
		//gCustomRankUser.RenderShowLogRank(ViewportAddress, *(WORD*)(ViewportAddress + 0x7E), PosX - 42, PosY);

	}
	RenderBoolean(x, y, c); //RenderBoolean
}