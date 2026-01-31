#include "stdafx.h"
#include "Font.h"

CFont* gFont[100];

CFont::CFont(TCHAR* Name, int Size, int Weight, BOOL bItalic, BOOL bUnderline)
{
	this->m_Font = CreateFontA(Size, 0, 0, 0, Weight, bItalic, bUnderline, FALSE,
		0xFDE9, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS,
		NONANTIALIASED_QUALITY, FF_DONTCARE | DEFAULT_PITCH,
		Name);
}

CFont::~CFont()
{
	DeleteObject(this->m_Font);
}

void InitFonts()
{
	char FontName[] = "Arial";
	const int BaseFontSize = 0;
	gFont[ARIAL_8] = new CFont(FontName, BaseFontSize + 8, FW_NORMAL, FALSE, FALSE);
	gFont[ARIAL_12] = new CFont(FontName, BaseFontSize + 12, FW_NORMAL, FALSE, FALSE);
	gFont[ARIAL_14] = new CFont(FontName, BaseFontSize + 14, FW_NORMAL, FALSE, FALSE);
	gFont[ARIAL_15] = new CFont(FontName, BaseFontSize + 15, FW_NORMAL, FALSE, FALSE);
	gFont[ARIAL_16] = new CFont(FontName, BaseFontSize + 16, FW_NORMAL, FALSE, FALSE);
	gFont[ARIAL_20] = new CFont(FontName, BaseFontSize + 20, FW_NORMAL, FALSE, FALSE);
	gFont[ARIAL_22] = new CFont(FontName, BaseFontSize + 22, FW_NORMAL, FALSE, FALSE);
	gFont[ARIAL_24] = new CFont(FontName, BaseFontSize + 24, FW_NORMAL, FALSE, FALSE);

	gFont[ARIAL_BLACK_10] = new CFont(FontName, BaseFontSize + 10, FW_BOLD, FALSE, FALSE);
	gFont[ARIAL_BLACK_11] = new CFont(FontName, BaseFontSize + 11, FW_BOLD, FALSE, FALSE);
	gFont[ARIAL_BLACK_12] = new CFont(FontName, BaseFontSize + 12, FW_BOLD, FALSE, FALSE);
	gFont[ARIAL_BLACK_13] = new CFont(FontName, BaseFontSize + 13, FW_BOLD, FALSE, FALSE);
	gFont[ARIAL_BLACK_14] = new CFont(FontName, BaseFontSize + 14, FW_BOLD, FALSE, FALSE);
	gFont[ARIAL_BLACK_15] = new CFont(FontName, BaseFontSize + 15, FW_BOLD, FALSE, FALSE);
	gFont[ARIAL_BLACK_16] = new CFont(FontName, BaseFontSize + 16, FW_BOLD, FALSE, FALSE);
	gFont[ARIAL_BLACK_24] = new CFont(FontName, BaseFontSize + 24, FW_BOLD, FALSE, FALSE);

	gFont[ARIAL_UNDERLINE_10] = new CFont(FontName, BaseFontSize + 10, FW_NORMAL, FALSE, TRUE);
	gFont[ARIAL_UNDERLINE_12] = new CFont(FontName, BaseFontSize + 12, FW_NORMAL, FALSE, TRUE);
	gFont[ARIAL_UNDERLINE_14] = new CFont(FontName, BaseFontSize + 14, FW_NORMAL, FALSE, TRUE);
	gFont[ARIAL_UNDERLINE_15] = new CFont(FontName, BaseFontSize + 15, FW_NORMAL, FALSE, TRUE);
	gFont[ARIAL_UNDERLINE_16] = new CFont(FontName, BaseFontSize + 16, FW_NORMAL, FALSE, TRUE);

	gFont[ARIAL_ITALIC_10] = new CFont(FontName, BaseFontSize + 8, FW_NORMAL, TRUE, FALSE);
	gFont[ARIAL_ITALIC_12] = new CFont(FontName, BaseFontSize + 12, FW_NORMAL, TRUE, FALSE);
	gFont[ARIAL_ITALIC_14] = new CFont(FontName, BaseFontSize + 14, FW_NORMAL, TRUE, FALSE);
	gFont[ARIAL_ITALIC_15] = new CFont(FontName, BaseFontSize + 15, FW_NORMAL, TRUE, FALSE);
	gFont[ARIAL_ITALIC_16] = new CFont(FontName, BaseFontSize + 16, FW_NORMAL, TRUE, FALSE);
}