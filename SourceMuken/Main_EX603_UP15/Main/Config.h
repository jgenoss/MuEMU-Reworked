#ifndef _Config_H
#define _Config_H

class cConfig
{
public:
	void Load();
	//===================================================
#if(TEXTVN_NEW)
	char MenuGame_TextVN[40][120];
	char ToggleAuto_TextVN[120][120];
	char GameOption_TextVN[40][120];
#if(DANH_HIEU_NEW)
	char TextVN_DanhHieu[120][120];
#endif
#if(TU_LUYEN_NEW)
	char TextVN_TuLuyen[210][210];
#endif
	char TextTM_ThanMaChien[50][120];
#endif
	char TextVN_SachThuocTinh[50][120];
	char TextVN[500][500];

	char TextHDC[500][500];
#if(CHONPHEDOILAP)
	char Text_DAOTACBAOTIEU[50][120];
#endif
	char HIEPMOCNAP[500][500];

};
//===================================================
#define MENU_GAME_FILE "./Data/Custom/Messenger.ini"
#define MENU_GAME_OPTION_FILE "./Data/Custom/GameOption.ini"
#if(DANHHIEU)
#define DANHHIEU_FILE "./Data/Custom/DanhHieu.cfg"
#endif
extern cConfig gConfig;

#endif