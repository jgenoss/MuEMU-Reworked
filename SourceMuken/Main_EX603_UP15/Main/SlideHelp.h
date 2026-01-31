#pragma once

#define pSlideSetPosition ((int(__thiscall*)(DWORD This,int X,int Y)) 0x00417EC0) 

class CSlide
{
public:
	void Load();

	static int __fastcall SetPosition(DWORD This, int X, int Y);
};

extern CSlide gSlide;