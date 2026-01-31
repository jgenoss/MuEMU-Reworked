#pragma once


class Font {
public:
	Font() {};
	~Font() {};
	void Load();
	HFONT LoadNewFont();
	HFONT LoadNewFont2();
	HFONT LoadNewFont3();
	HFONT LoadNewFont4();
	//HFONT LoadNewFontBold();
	HFONT FontBSize[30];
	HFONT FontSize[30];
	void FontSizeLoad(int a1);
};

extern Font gFont;
