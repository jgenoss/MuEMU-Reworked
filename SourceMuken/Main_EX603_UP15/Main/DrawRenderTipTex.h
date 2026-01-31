#pragma once
#define pRenderItemInfo								((void(__thiscall*)(int thisa, int sx,int sy, int ip, bool Sell, int Inventype, bool bItemTextListBoxUse)) 0x007E3E30)
#define pGetSpecialOptionText						((void(__cdecl*)(int Type, char* Text, WORD Option, char Value, int iMana)) 0x005C2F70)

#define ForSocket_Item									((int (__thiscall*)(LPVOID thisa, int ip, int num)) 0x00968880)

class CDrawRenderTipTex
{
public:
	CDrawRenderTipTex(void);
	virtual ~CDrawRenderTipTex(void);

	void Init();
	static int __thiscall AttachToolTipForSocketItem(LPVOID thisa, int ip, int TextNum);
	static void __thiscall pCRenderItemInfo(int thisa, int sx, int sy, int ip, bool Sell, int Inventype, bool bItemTextListBoxUse);
};

extern CDrawRenderTipTex g_pTipTextList;