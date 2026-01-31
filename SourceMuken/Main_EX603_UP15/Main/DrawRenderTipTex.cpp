#include "StdAfx.h"
#include "Util.h"
#include "Defines.h"
#include "SEASON3B.h"

#include "DrawRenderTipTex.h"
#include "CustomCuongHoaWing.h"

CDrawRenderTipTex g_pTipTextList;

CDrawRenderTipTex::CDrawRenderTipTex(void)
{
}

CDrawRenderTipTex::~CDrawRenderTipTex(void)
{
}

bool sell_tooltip = false;
int Invent = 0;

void CDrawRenderTipTex::pCRenderItemInfo(int thisa, int sx, int sy, int ip, bool Sell, int Inventype, bool bItemTextListBoxUse)
{
	sell_tooltip = Sell;
	Invent = Inventype;
	pRenderItemInfo(thisa, sx, sy, ip, Sell, Inventype, bItemTextListBoxUse);
}

using std::copy; using std::string;  //cong dong c++ viet nam

int CDrawRenderTipTex::AttachToolTipForSocketItem(LPVOID thisa, int ip, int TextNum)
{
	int Level = (*(DWORD *)(ip + 2) >> 3) & 0xF; //-- item +0 -> +5
	string TextItem;

	int ItemScritp = *(DWORD*)0x8128AC0 + 84 * *(WORD *)ip;

	int wLevel = *(WORD *)(ItemScritp + 32); //-- level cua ITEM

	TextItem.clear();

	int LevelItemStar = wLevel / 15;

	WORD itemindex = *(WORD *)ip;

	if ((IsVisible(g_pNewUISystem(), 12) || sell_tooltip) || (Invent == 4 || Invent == 5))
	{



		if (itemindex == 6320)
		{
			TextItem.append("Cường Hoá Siêu Wing");
			AddOAttachptionLine(TEXT_COLOR_GREEN_BLUE, 1, 3, 0, TextItem.c_str());
		}
		else
		{
			TextItem.append("Cường Hoá Set Item");
			AddOAttachptionLine(TEXT_COLOR_REDPURPLE, 1, 3, 0, TextItem.c_str());
		}


		//AddOAttachptionLine(TEXT_COLOR_RED, 1, 3, 0, TextItem.c_str());

	}

	else
	{


		if (itemindex == 6320)
		{
			TextItem.append("Cường Hoá Siêu Wing");
			AddOAttachptionLine(TEXT_COLOR_GREEN_BLUE, 1, 1, 0, TextItem.c_str());

		}
		else
		{
			TextItem.append("Cường Hoá Set Item");
			AddOAttachptionLine(TEXT_COLOR_REDPURPLE, 1, 1, 0, TextItem.c_str());
		}


		//AddOAttachptionLine(TEXT_COLOR_RED, 1, 1, 0, TextItem.c_str());

	}
	return ForSocket_Item(thisa, ip, TextNum);
}

void CDrawRenderTipTex::Init()
{
	SetCompleteHook(0xE8, 0x0042AE6F, pCRenderItemInfo);
	SetCompleteHook(0xE8, 0x007DCFCB, pCRenderItemInfo);
	SetCompleteHook(0xE8, 0x007DD028, pCRenderItemInfo);
	SetCompleteHook(0xE8, 0x007DD060, pCRenderItemInfo);
	SetCompleteHook(0xE8, 0x007DD098, pCRenderItemInfo);
	SetCompleteHook(0xE8, 0x0083B917, pCRenderItemInfo);
	SetCompleteHook(0xE8, 0x007E5B70, &CDrawRenderTipTex::AttachToolTipForSocketItem);

}