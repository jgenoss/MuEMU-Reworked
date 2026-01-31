#include "StdAfx.h"
#include "Config.h"
#include "Util.h"
#include <stdlib.h>
#include "windows.h"
#include "atlstr.h"
#include "Protect.h"

cConfig gConfig;

void cConfig::Load()
{	

#if(THANMA)
	char GetFotText[55] = { 0 };
	for (int st = 0; st < 50; st++)
	{
		wsprintf(GetFotText, "Text%d", st);
		GetPrivateProfileStringA("TextTM_EventThanMa", GetFotText, "Null", TextTM_ThanMaChien[st], sizeof(TextTM_ThanMaChien[st]), MENU_GAME_FILE);
		GetPrivateProfileStringA("Text_SachThuocTinh", GetFotText, "Null", TextVN_SachThuocTinh[st], sizeof(TextVN_SachThuocTinh[st]), MENU_GAME_FILE);
#if(CHONPHEDOILAP)
		GetPrivateProfileStringA("Text_DAOTACBAOTIEU", GetFotText, "Null", Text_DAOTACBAOTIEU[st], sizeof(Text_DAOTACBAOTIEU[st]), MENU_GAME_FILE);
#endif
	}
#endif

	//============================================================================================================
#if(TEXTVN_NEW)
	GetPrivateProfileStringA("MenuGame", "MenuGame0", "Null", MenuGame_TextVN[0], sizeof(MenuGame_TextVN[0]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame1", "Null", MenuGame_TextVN[1], sizeof(MenuGame_TextVN[1]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame2", "Null", MenuGame_TextVN[2], sizeof(MenuGame_TextVN[2]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame3", "Null", MenuGame_TextVN[3], sizeof(MenuGame_TextVN[3]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame4", "Null", MenuGame_TextVN[4], sizeof(MenuGame_TextVN[4]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame5", "Null", MenuGame_TextVN[5], sizeof(MenuGame_TextVN[5]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame6", "Null", MenuGame_TextVN[6], sizeof(MenuGame_TextVN[6]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame7", "Null", MenuGame_TextVN[7], sizeof(MenuGame_TextVN[7]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame8", "Null", MenuGame_TextVN[8], sizeof(MenuGame_TextVN[8]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame9", "Null", MenuGame_TextVN[9], sizeof(MenuGame_TextVN[9]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame10", "Null", MenuGame_TextVN[10], sizeof(MenuGame_TextVN[10]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame11", "Null", MenuGame_TextVN[11], sizeof(MenuGame_TextVN[11]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame12", "Null", MenuGame_TextVN[12], sizeof(MenuGame_TextVN[12]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame13", "Null", MenuGame_TextVN[13], sizeof(MenuGame_TextVN[13]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame14", "Null", MenuGame_TextVN[14], sizeof(MenuGame_TextVN[14]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame15", "Null", MenuGame_TextVN[15], sizeof(MenuGame_TextVN[15]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame16", "Null", MenuGame_TextVN[16], sizeof(MenuGame_TextVN[16]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame17", "Null", MenuGame_TextVN[17], sizeof(MenuGame_TextVN[17]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame18", "Null", MenuGame_TextVN[18], sizeof(MenuGame_TextVN[18]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame19", "Null", MenuGame_TextVN[19], sizeof(MenuGame_TextVN[19]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame20", "Null", MenuGame_TextVN[20], sizeof(MenuGame_TextVN[20]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame21", "Null", MenuGame_TextVN[21], sizeof(MenuGame_TextVN[21]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame22", "Null", MenuGame_TextVN[22], sizeof(MenuGame_TextVN[22]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame23", "Null", MenuGame_TextVN[23], sizeof(MenuGame_TextVN[23]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame24", "Null", MenuGame_TextVN[24], sizeof(MenuGame_TextVN[24]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame25", "Null", MenuGame_TextVN[25], sizeof(MenuGame_TextVN[25]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame26", "Null", MenuGame_TextVN[26], sizeof(MenuGame_TextVN[26]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame27", "Null", MenuGame_TextVN[27], sizeof(MenuGame_TextVN[27]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame28", "Null", MenuGame_TextVN[28], sizeof(MenuGame_TextVN[28]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame29", "Null", MenuGame_TextVN[29], sizeof(MenuGame_TextVN[29]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame30", "Null", MenuGame_TextVN[30], sizeof(MenuGame_TextVN[30]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame31", "Null", MenuGame_TextVN[31], sizeof(MenuGame_TextVN[31]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame32", "Null", MenuGame_TextVN[32], sizeof(MenuGame_TextVN[32]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame33", "Null", MenuGame_TextVN[33], sizeof(MenuGame_TextVN[33]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame34", "Null", MenuGame_TextVN[34], sizeof(MenuGame_TextVN[34]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame35", "Null", MenuGame_TextVN[35], sizeof(MenuGame_TextVN[35]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame36", "Null", MenuGame_TextVN[36], sizeof(MenuGame_TextVN[36]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame37", "Null", MenuGame_TextVN[37], sizeof(MenuGame_TextVN[37]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame38", "Null", MenuGame_TextVN[38], sizeof(MenuGame_TextVN[38]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame39", "Null", MenuGame_TextVN[39], sizeof(MenuGame_TextVN[39]), MENU_GAME_FILE);
	GetPrivateProfileStringA("MenuGame", "MenuGame40", "Null", MenuGame_TextVN[40], sizeof(MenuGame_TextVN[40]), MENU_GAME_FILE);

	GetPrivateProfileStringA("ToggleAuto", "ToggleAuto0", "Null",  ToggleAuto_TextVN[0],  sizeof(ToggleAuto_TextVN[0]), MENU_GAME_FILE);
	GetPrivateProfileStringA("ToggleAuto", "ToggleAuto1", "Null",  ToggleAuto_TextVN[1],  sizeof(ToggleAuto_TextVN[1]), MENU_GAME_FILE);
	GetPrivateProfileStringA("ToggleAuto", "ToggleAuto2", "Null",  ToggleAuto_TextVN[2],  sizeof(ToggleAuto_TextVN[2]), MENU_GAME_FILE);
	GetPrivateProfileStringA("ToggleAuto", "ToggleAuto3", "Null",  ToggleAuto_TextVN[3],  sizeof(ToggleAuto_TextVN[3]), MENU_GAME_FILE);
	GetPrivateProfileStringA("ToggleAuto", "ToggleAuto4", "Null",  ToggleAuto_TextVN[4],  sizeof(ToggleAuto_TextVN[4]), MENU_GAME_FILE);
	GetPrivateProfileStringA("ToggleAuto", "ToggleAuto5", "Null",  ToggleAuto_TextVN[5],  sizeof(ToggleAuto_TextVN[5]), MENU_GAME_FILE);
	GetPrivateProfileStringA("ToggleAuto", "ToggleAuto6", "Null",  ToggleAuto_TextVN[6],  sizeof(ToggleAuto_TextVN[6]), MENU_GAME_FILE);
	GetPrivateProfileStringA("ToggleAuto", "ToggleAuto7", "Null",  ToggleAuto_TextVN[7],  sizeof(ToggleAuto_TextVN[7]), MENU_GAME_FILE);
	GetPrivateProfileStringA("ToggleAuto", "ToggleAuto8", "Null",  ToggleAuto_TextVN[8],  sizeof(ToggleAuto_TextVN[8]), MENU_GAME_FILE);
	GetPrivateProfileStringA("ToggleAuto", "ToggleAuto9", "Null",  ToggleAuto_TextVN[9],  sizeof(ToggleAuto_TextVN[9]), MENU_GAME_FILE);

	GetPrivateProfileStringA("TextHDC", "TextHDC0", "Null", TextHDC[0], sizeof(TextHDC[0]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextHDC", "TextHDC1", "Null", TextHDC[1], sizeof(TextHDC[1]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextHDC", "TextHDC2", "Null", TextHDC[2], sizeof(TextHDC[2]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextHDC", "TextHDC3", "Null", TextHDC[3], sizeof(TextHDC[3]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextHDC", "TextHDC4", "Null", TextHDC[4], sizeof(TextHDC[4]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextHDC", "TextHDC5", "Null", TextHDC[5], sizeof(TextHDC[5]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextHDC", "TextHDC6", "Null", TextHDC[6], sizeof(TextHDC[6]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextHDC", "TextHDC7", "Null", TextHDC[7], sizeof(TextHDC[7]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextHDC", "TextHDC8", "Null", TextHDC[8], sizeof(TextHDC[8]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextHDC", "TextHDC9", "Null", TextHDC[9], sizeof(TextHDC[9]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextHDC", "TextHDC10", "Null", TextHDC[10], sizeof(TextHDC[10]), MENU_GAME_FILE);


//===>>>
#endif



	GetPrivateProfileStringA("GameOption", "GameOption0",  "Null", GameOption_TextVN[0],  sizeof(GameOption_TextVN[0]),  MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption1",  "Null", GameOption_TextVN[1],  sizeof(GameOption_TextVN[1]),  MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption2",  "Null", GameOption_TextVN[2],  sizeof(GameOption_TextVN[2]),  MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption3",  "Null", GameOption_TextVN[3],  sizeof(GameOption_TextVN[3]),  MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption4",  "Null", GameOption_TextVN[4],  sizeof(GameOption_TextVN[4]),  MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption5",  "Null", GameOption_TextVN[5],  sizeof(GameOption_TextVN[5]),  MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption6",  "Null", GameOption_TextVN[6],  sizeof(GameOption_TextVN[6]),  MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption7",  "Null", GameOption_TextVN[7],  sizeof(GameOption_TextVN[7]),  MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption8",  "Null", GameOption_TextVN[8],  sizeof(GameOption_TextVN[8]),  MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption9",  "Null", GameOption_TextVN[9],  sizeof(GameOption_TextVN[9]),  MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption10", "Null", GameOption_TextVN[10], sizeof(GameOption_TextVN[10]), MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption11", "Null", GameOption_TextVN[11], sizeof(GameOption_TextVN[11]), MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption12", "Null", GameOption_TextVN[12], sizeof(GameOption_TextVN[12]), MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption13", "Null", GameOption_TextVN[13], sizeof(GameOption_TextVN[13]), MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption14", "Null", GameOption_TextVN[14], sizeof(GameOption_TextVN[14]), MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption15", "Null", GameOption_TextVN[15], sizeof(GameOption_TextVN[15]), MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption16", "Null", GameOption_TextVN[16], sizeof(GameOption_TextVN[16]), MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption17", "Null", GameOption_TextVN[17], sizeof(GameOption_TextVN[17]), MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption18", "Null", GameOption_TextVN[18], sizeof(GameOption_TextVN[18]), MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption19", "Null", GameOption_TextVN[19], sizeof(GameOption_TextVN[19]), MENU_GAME_OPTION_FILE);
	GetPrivateProfileStringA("GameOption", "GameOption20", "Null", GameOption_TextVN[20], sizeof(GameOption_TextVN[20]), MENU_GAME_OPTION_FILE);




#if(DANH_HIEU_NEW)
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu0", "Null", TextVN_DanhHieu[0], sizeof(TextVN_DanhHieu[0]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu1", "Null", TextVN_DanhHieu[1], sizeof(TextVN_DanhHieu[1]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu2", "Null", TextVN_DanhHieu[2], sizeof(TextVN_DanhHieu[2]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu3", "Null", TextVN_DanhHieu[3], sizeof(TextVN_DanhHieu[3]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu4", "Null", TextVN_DanhHieu[4], sizeof(TextVN_DanhHieu[4]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu5", "Null", TextVN_DanhHieu[5], sizeof(TextVN_DanhHieu[5]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu6", "Null", TextVN_DanhHieu[6], sizeof(TextVN_DanhHieu[6]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu7", "Null", TextVN_DanhHieu[7], sizeof(TextVN_DanhHieu[7]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu8", "Null", TextVN_DanhHieu[8], sizeof(TextVN_DanhHieu[8]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu9", "Null", TextVN_DanhHieu[9], sizeof(TextVN_DanhHieu[9]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu10", "Null", TextVN_DanhHieu[10], sizeof(TextVN_DanhHieu[10]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu10", "Null", TextVN_DanhHieu[10], sizeof(TextVN_DanhHieu[10]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu11", "Null", TextVN_DanhHieu[11], sizeof(TextVN_DanhHieu[11]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu12", "Null", TextVN_DanhHieu[12], sizeof(TextVN_DanhHieu[12]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu13", "Null", TextVN_DanhHieu[13], sizeof(TextVN_DanhHieu[13]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu14", "Null", TextVN_DanhHieu[14], sizeof(TextVN_DanhHieu[14]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu15", "Null", TextVN_DanhHieu[15], sizeof(TextVN_DanhHieu[15]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu16", "Null", TextVN_DanhHieu[16], sizeof(TextVN_DanhHieu[16]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu17", "Null", TextVN_DanhHieu[17], sizeof(TextVN_DanhHieu[17]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu18", "Null", TextVN_DanhHieu[18], sizeof(TextVN_DanhHieu[18]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu19", "Null", TextVN_DanhHieu[19], sizeof(TextVN_DanhHieu[19]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu20", "Null", TextVN_DanhHieu[20], sizeof(TextVN_DanhHieu[20]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu21", "Null", TextVN_DanhHieu[21], sizeof(TextVN_DanhHieu[21]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu22", "Null", TextVN_DanhHieu[22], sizeof(TextVN_DanhHieu[22]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu23", "Null", TextVN_DanhHieu[23], sizeof(TextVN_DanhHieu[23]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu24", "Null", TextVN_DanhHieu[24], sizeof(TextVN_DanhHieu[24]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu25", "Null", TextVN_DanhHieu[25], sizeof(TextVN_DanhHieu[25]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu26", "Null", TextVN_DanhHieu[26], sizeof(TextVN_DanhHieu[26]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu27", "Null", TextVN_DanhHieu[27], sizeof(TextVN_DanhHieu[27]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu28", "Null", TextVN_DanhHieu[28], sizeof(TextVN_DanhHieu[28]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu29", "Null", TextVN_DanhHieu[29], sizeof(TextVN_DanhHieu[29]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu30", "Null", TextVN_DanhHieu[30], sizeof(TextVN_DanhHieu[30]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu31", "Null", TextVN_DanhHieu[31], sizeof(TextVN_DanhHieu[31]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu32", "Null", TextVN_DanhHieu[32], sizeof(TextVN_DanhHieu[32]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu33", "Null", TextVN_DanhHieu[33], sizeof(TextVN_DanhHieu[33]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu34", "Null", TextVN_DanhHieu[34], sizeof(TextVN_DanhHieu[34]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu35", "Null", TextVN_DanhHieu[35], sizeof(TextVN_DanhHieu[35]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu36", "Null", TextVN_DanhHieu[36], sizeof(TextVN_DanhHieu[36]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu37", "Null", TextVN_DanhHieu[37], sizeof(TextVN_DanhHieu[37]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu38", "Null", TextVN_DanhHieu[38], sizeof(TextVN_DanhHieu[38]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu39", "Null", TextVN_DanhHieu[39], sizeof(TextVN_DanhHieu[39]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu40", "Null", TextVN_DanhHieu[40], sizeof(TextVN_DanhHieu[40]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu41", "Null", TextVN_DanhHieu[41], sizeof(TextVN_DanhHieu[41]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu42", "Null", TextVN_DanhHieu[42], sizeof(TextVN_DanhHieu[42]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu43", "Null", TextVN_DanhHieu[43], sizeof(TextVN_DanhHieu[43]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu44", "Null", TextVN_DanhHieu[44], sizeof(TextVN_DanhHieu[44]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu45", "Null", TextVN_DanhHieu[45], sizeof(TextVN_DanhHieu[45]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu46", "Null", TextVN_DanhHieu[46], sizeof(TextVN_DanhHieu[46]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu47", "Null", TextVN_DanhHieu[47], sizeof(TextVN_DanhHieu[47]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu48", "Null", TextVN_DanhHieu[48], sizeof(TextVN_DanhHieu[48]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu49", "Null", TextVN_DanhHieu[49], sizeof(TextVN_DanhHieu[49]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu50", "Null", TextVN_DanhHieu[50], sizeof(TextVN_DanhHieu[50]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu51", "Null", TextVN_DanhHieu[51], sizeof(TextVN_DanhHieu[51]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu52", "Null", TextVN_DanhHieu[52], sizeof(TextVN_DanhHieu[52]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu53", "Null", TextVN_DanhHieu[53], sizeof(TextVN_DanhHieu[53]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu54", "Null", TextVN_DanhHieu[54], sizeof(TextVN_DanhHieu[54]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu55", "Null", TextVN_DanhHieu[55], sizeof(TextVN_DanhHieu[55]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu56", "Null", TextVN_DanhHieu[56], sizeof(TextVN_DanhHieu[56]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu57", "Null", TextVN_DanhHieu[57], sizeof(TextVN_DanhHieu[57]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu58", "Null", TextVN_DanhHieu[58], sizeof(TextVN_DanhHieu[58]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu59", "Null", TextVN_DanhHieu[59], sizeof(TextVN_DanhHieu[59]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu60", "Null", TextVN_DanhHieu[60], sizeof(TextVN_DanhHieu[60]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu61", "Null", TextVN_DanhHieu[61], sizeof(TextVN_DanhHieu[61]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu62", "Null", TextVN_DanhHieu[62], sizeof(TextVN_DanhHieu[62]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu63", "Null", TextVN_DanhHieu[63], sizeof(TextVN_DanhHieu[63]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu64", "Null", TextVN_DanhHieu[64], sizeof(TextVN_DanhHieu[64]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu65", "Null", TextVN_DanhHieu[65], sizeof(TextVN_DanhHieu[65]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu66", "Null", TextVN_DanhHieu[66], sizeof(TextVN_DanhHieu[66]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu67", "Null", TextVN_DanhHieu[67], sizeof(TextVN_DanhHieu[67]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu68", "Null", TextVN_DanhHieu[68], sizeof(TextVN_DanhHieu[68]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu69", "Null", TextVN_DanhHieu[69], sizeof(TextVN_DanhHieu[69]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu70", "Null", TextVN_DanhHieu[70], sizeof(TextVN_DanhHieu[70]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu71", "Null", TextVN_DanhHieu[71], sizeof(TextVN_DanhHieu[71]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu72", "Null", TextVN_DanhHieu[72], sizeof(TextVN_DanhHieu[72]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu73", "Null", TextVN_DanhHieu[73], sizeof(TextVN_DanhHieu[73]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu74", "Null", TextVN_DanhHieu[74], sizeof(TextVN_DanhHieu[74]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu75", "Null", TextVN_DanhHieu[75], sizeof(TextVN_DanhHieu[75]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu76", "Null", TextVN_DanhHieu[76], sizeof(TextVN_DanhHieu[76]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu77", "Null", TextVN_DanhHieu[77], sizeof(TextVN_DanhHieu[77]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu78", "Null", TextVN_DanhHieu[78], sizeof(TextVN_DanhHieu[78]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu79", "Null", TextVN_DanhHieu[79], sizeof(TextVN_DanhHieu[79]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu80", "Null", TextVN_DanhHieu[80], sizeof(TextVN_DanhHieu[80]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu81", "Null", TextVN_DanhHieu[81], sizeof(TextVN_DanhHieu[81]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu82", "Null", TextVN_DanhHieu[82], sizeof(TextVN_DanhHieu[82]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu83", "Null", TextVN_DanhHieu[83], sizeof(TextVN_DanhHieu[83]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu84", "Null", TextVN_DanhHieu[84], sizeof(TextVN_DanhHieu[84]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu85", "Null", TextVN_DanhHieu[85], sizeof(TextVN_DanhHieu[85]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu86", "Null", TextVN_DanhHieu[86], sizeof(TextVN_DanhHieu[86]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu87", "Null", TextVN_DanhHieu[87], sizeof(TextVN_DanhHieu[87]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu88", "Null", TextVN_DanhHieu[88], sizeof(TextVN_DanhHieu[88]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu89", "Null", TextVN_DanhHieu[89], sizeof(TextVN_DanhHieu[89]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu90", "Null", TextVN_DanhHieu[90], sizeof(TextVN_DanhHieu[90]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu91", "Null", TextVN_DanhHieu[91], sizeof(TextVN_DanhHieu[91]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu92", "Null", TextVN_DanhHieu[92], sizeof(TextVN_DanhHieu[92]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu93", "Null", TextVN_DanhHieu[93], sizeof(TextVN_DanhHieu[93]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu94", "Null", TextVN_DanhHieu[94], sizeof(TextVN_DanhHieu[94]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu95", "Null", TextVN_DanhHieu[95], sizeof(TextVN_DanhHieu[95]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu96", "Null", TextVN_DanhHieu[96], sizeof(TextVN_DanhHieu[96]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu97", "Null", TextVN_DanhHieu[97], sizeof(TextVN_DanhHieu[97]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu98", "Null", TextVN_DanhHieu[98], sizeof(TextVN_DanhHieu[98]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu99", "Null", TextVN_DanhHieu[99], sizeof(TextVN_DanhHieu[99]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu100", "Null", TextVN_DanhHieu[100], sizeof(TextVN_DanhHieu[100]), MENU_GAME_FILE);
#endif


#if(TU_LUYEN_NEW)
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen0", "Null", TextVN_TuLuyen[0], sizeof(TextVN_TuLuyen[0]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen1", "Null", TextVN_TuLuyen[1], sizeof(TextVN_TuLuyen[1]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen2", "Null", TextVN_TuLuyen[2], sizeof(TextVN_TuLuyen[2]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen3", "Null", TextVN_TuLuyen[3], sizeof(TextVN_TuLuyen[3]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen4", "Null", TextVN_TuLuyen[4], sizeof(TextVN_TuLuyen[4]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen5", "Null", TextVN_TuLuyen[5], sizeof(TextVN_TuLuyen[5]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen6", "Null", TextVN_TuLuyen[6], sizeof(TextVN_TuLuyen[6]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen7", "Null", TextVN_TuLuyen[7], sizeof(TextVN_TuLuyen[7]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen8", "Null", TextVN_TuLuyen[8], sizeof(TextVN_TuLuyen[8]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen9", "Null", TextVN_TuLuyen[9], sizeof(TextVN_TuLuyen[9]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen10", "Null", TextVN_TuLuyen[10], sizeof(TextVN_TuLuyen[10]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen11", "Null", TextVN_TuLuyen[11], sizeof(TextVN_TuLuyen[11]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen12", "Null", TextVN_TuLuyen[12], sizeof(TextVN_TuLuyen[12]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen13", "Null", TextVN_TuLuyen[13], sizeof(TextVN_TuLuyen[13]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen14", "Null", TextVN_TuLuyen[14], sizeof(TextVN_TuLuyen[14]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen15", "Null", TextVN_TuLuyen[15], sizeof(TextVN_TuLuyen[15]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen16", "Null", TextVN_TuLuyen[16], sizeof(TextVN_TuLuyen[16]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen17", "Null", TextVN_TuLuyen[17], sizeof(TextVN_TuLuyen[17]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen18", "Null", TextVN_TuLuyen[18], sizeof(TextVN_TuLuyen[18]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen19", "Null", TextVN_TuLuyen[19], sizeof(TextVN_TuLuyen[19]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen20", "Null", TextVN_TuLuyen[20], sizeof(TextVN_TuLuyen[20]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen21", "Null", TextVN_TuLuyen[21], sizeof(TextVN_TuLuyen[21]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen22", "Null", TextVN_TuLuyen[22], sizeof(TextVN_TuLuyen[22]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen23", "Null", TextVN_TuLuyen[23], sizeof(TextVN_TuLuyen[23]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen24", "Null", TextVN_TuLuyen[24], sizeof(TextVN_TuLuyen[24]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen25", "Null", TextVN_TuLuyen[25], sizeof(TextVN_TuLuyen[25]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen26", "Null", TextVN_TuLuyen[26], sizeof(TextVN_TuLuyen[26]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen27", "Null", TextVN_TuLuyen[27], sizeof(TextVN_TuLuyen[27]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen28", "Null", TextVN_TuLuyen[28], sizeof(TextVN_TuLuyen[28]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen29", "Null", TextVN_TuLuyen[29], sizeof(TextVN_TuLuyen[29]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen30", "Null", TextVN_TuLuyen[30], sizeof(TextVN_TuLuyen[30]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen31", "Null", TextVN_TuLuyen[31], sizeof(TextVN_TuLuyen[31]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen32", "Null", TextVN_TuLuyen[32], sizeof(TextVN_TuLuyen[32]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen33", "Null", TextVN_TuLuyen[33], sizeof(TextVN_TuLuyen[33]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen34", "Null", TextVN_TuLuyen[34], sizeof(TextVN_TuLuyen[34]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen35", "Null", TextVN_TuLuyen[35], sizeof(TextVN_TuLuyen[35]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen36", "Null", TextVN_TuLuyen[36], sizeof(TextVN_TuLuyen[36]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen37", "Null", TextVN_TuLuyen[37], sizeof(TextVN_TuLuyen[37]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen38", "Null", TextVN_TuLuyen[38], sizeof(TextVN_TuLuyen[38]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen39", "Null", TextVN_TuLuyen[39], sizeof(TextVN_TuLuyen[39]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen40", "Null", TextVN_TuLuyen[40], sizeof(TextVN_TuLuyen[40]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen41", "Null", TextVN_TuLuyen[41], sizeof(TextVN_TuLuyen[41]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen42", "Null", TextVN_TuLuyen[42], sizeof(TextVN_TuLuyen[42]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen43", "Null", TextVN_TuLuyen[43], sizeof(TextVN_TuLuyen[43]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen44", "Null", TextVN_TuLuyen[44], sizeof(TextVN_TuLuyen[44]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen45", "Null", TextVN_TuLuyen[45], sizeof(TextVN_TuLuyen[45]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen46", "Null", TextVN_TuLuyen[46], sizeof(TextVN_TuLuyen[46]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen47", "Null", TextVN_TuLuyen[47], sizeof(TextVN_TuLuyen[47]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen48", "Null", TextVN_TuLuyen[48], sizeof(TextVN_TuLuyen[48]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen49", "Null", TextVN_TuLuyen[49], sizeof(TextVN_TuLuyen[49]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen50", "Null", TextVN_TuLuyen[50], sizeof(TextVN_TuLuyen[50]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen51", "Null", TextVN_TuLuyen[51], sizeof(TextVN_TuLuyen[51]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen52", "Null", TextVN_TuLuyen[52], sizeof(TextVN_TuLuyen[52]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen53", "Null", TextVN_TuLuyen[53], sizeof(TextVN_TuLuyen[53]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen54", "Null", TextVN_TuLuyen[54], sizeof(TextVN_TuLuyen[54]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen55", "Null", TextVN_TuLuyen[55], sizeof(TextVN_TuLuyen[55]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen56", "Null", TextVN_TuLuyen[56], sizeof(TextVN_TuLuyen[56]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen57", "Null", TextVN_TuLuyen[57], sizeof(TextVN_TuLuyen[57]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen58", "Null", TextVN_TuLuyen[58], sizeof(TextVN_TuLuyen[58]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen59", "Null", TextVN_TuLuyen[59], sizeof(TextVN_TuLuyen[59]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen60", "Null", TextVN_TuLuyen[60], sizeof(TextVN_TuLuyen[60]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen61", "Null", TextVN_TuLuyen[61], sizeof(TextVN_TuLuyen[61]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen62", "Null", TextVN_TuLuyen[62], sizeof(TextVN_TuLuyen[62]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen63", "Null", TextVN_TuLuyen[63], sizeof(TextVN_TuLuyen[63]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen64", "Null", TextVN_TuLuyen[64], sizeof(TextVN_TuLuyen[64]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen65", "Null", TextVN_TuLuyen[65], sizeof(TextVN_TuLuyen[65]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen66", "Null", TextVN_TuLuyen[66], sizeof(TextVN_TuLuyen[66]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen67", "Null", TextVN_TuLuyen[67], sizeof(TextVN_TuLuyen[67]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen68", "Null", TextVN_TuLuyen[68], sizeof(TextVN_TuLuyen[68]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen69", "Null", TextVN_TuLuyen[69], sizeof(TextVN_TuLuyen[69]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen70", "Null", TextVN_TuLuyen[70], sizeof(TextVN_TuLuyen[70]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen71", "Null", TextVN_TuLuyen[71], sizeof(TextVN_TuLuyen[71]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen72", "Null", TextVN_TuLuyen[72], sizeof(TextVN_TuLuyen[72]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen73", "Null", TextVN_TuLuyen[73], sizeof(TextVN_TuLuyen[73]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen74", "Null", TextVN_TuLuyen[74], sizeof(TextVN_TuLuyen[74]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen75", "Null", TextVN_TuLuyen[75], sizeof(TextVN_TuLuyen[75]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen76", "Null", TextVN_TuLuyen[76], sizeof(TextVN_TuLuyen[76]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen77", "Null", TextVN_TuLuyen[77], sizeof(TextVN_TuLuyen[77]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen78", "Null", TextVN_TuLuyen[78], sizeof(TextVN_TuLuyen[78]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen79", "Null", TextVN_TuLuyen[79], sizeof(TextVN_TuLuyen[79]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen80", "Null", TextVN_TuLuyen[80], sizeof(TextVN_TuLuyen[80]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen81", "Null", TextVN_TuLuyen[81], sizeof(TextVN_TuLuyen[81]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen82", "Null", TextVN_TuLuyen[82], sizeof(TextVN_TuLuyen[82]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen83", "Null", TextVN_TuLuyen[83], sizeof(TextVN_TuLuyen[83]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen84", "Null", TextVN_TuLuyen[84], sizeof(TextVN_TuLuyen[84]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen85", "Null", TextVN_TuLuyen[85], sizeof(TextVN_TuLuyen[85]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen86", "Null", TextVN_TuLuyen[86], sizeof(TextVN_TuLuyen[86]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen87", "Null", TextVN_TuLuyen[87], sizeof(TextVN_TuLuyen[87]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen88", "Null", TextVN_TuLuyen[88], sizeof(TextVN_TuLuyen[88]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen89", "Null", TextVN_TuLuyen[89], sizeof(TextVN_TuLuyen[89]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen90", "Null", TextVN_TuLuyen[90], sizeof(TextVN_TuLuyen[90]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen91", "Null", TextVN_TuLuyen[91], sizeof(TextVN_TuLuyen[91]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen92", "Null", TextVN_TuLuyen[92], sizeof(TextVN_TuLuyen[92]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen93", "Null", TextVN_TuLuyen[93], sizeof(TextVN_TuLuyen[93]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen94", "Null", TextVN_TuLuyen[94], sizeof(TextVN_TuLuyen[94]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen95", "Null", TextVN_TuLuyen[95], sizeof(TextVN_TuLuyen[95]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen96", "Null", TextVN_TuLuyen[96], sizeof(TextVN_TuLuyen[96]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen97", "Null", TextVN_TuLuyen[97], sizeof(TextVN_TuLuyen[97]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen98", "Null", TextVN_TuLuyen[98], sizeof(TextVN_TuLuyen[98]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen99", "Null", TextVN_TuLuyen[99], sizeof(TextVN_TuLuyen[99]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen100", "Null", TextVN_TuLuyen[100], sizeof(TextVN_TuLuyen[100]), MENU_GAME_FILE);

	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen101", "Null", TextVN_TuLuyen[101], sizeof(TextVN_TuLuyen[101]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen102", "Null", TextVN_TuLuyen[102], sizeof(TextVN_TuLuyen[102]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen103", "Null", TextVN_TuLuyen[103], sizeof(TextVN_TuLuyen[103]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen104", "Null", TextVN_TuLuyen[104], sizeof(TextVN_TuLuyen[104]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen105", "Null", TextVN_TuLuyen[105], sizeof(TextVN_TuLuyen[105]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen106", "Null", TextVN_TuLuyen[106], sizeof(TextVN_TuLuyen[106]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen107", "Null", TextVN_TuLuyen[107], sizeof(TextVN_TuLuyen[107]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen108", "Null", TextVN_TuLuyen[108], sizeof(TextVN_TuLuyen[108]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen109", "Null", TextVN_TuLuyen[109], sizeof(TextVN_TuLuyen[109]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen110", "Null", TextVN_TuLuyen[110], sizeof(TextVN_TuLuyen[110]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen111", "Null", TextVN_TuLuyen[111], sizeof(TextVN_TuLuyen[111]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen112", "Null", TextVN_TuLuyen[112], sizeof(TextVN_TuLuyen[112]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen113", "Null", TextVN_TuLuyen[113], sizeof(TextVN_TuLuyen[113]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen114", "Null", TextVN_TuLuyen[114], sizeof(TextVN_TuLuyen[114]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen115", "Null", TextVN_TuLuyen[115], sizeof(TextVN_TuLuyen[115]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen116", "Null", TextVN_TuLuyen[116], sizeof(TextVN_TuLuyen[116]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen117", "Null", TextVN_TuLuyen[117], sizeof(TextVN_TuLuyen[117]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen118", "Null", TextVN_TuLuyen[118], sizeof(TextVN_TuLuyen[118]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen119", "Null", TextVN_TuLuyen[119], sizeof(TextVN_TuLuyen[119]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen120", "Null", TextVN_TuLuyen[120], sizeof(TextVN_TuLuyen[120]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen121", "Null", TextVN_TuLuyen[121], sizeof(TextVN_TuLuyen[121]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen122", "Null", TextVN_TuLuyen[122], sizeof(TextVN_TuLuyen[122]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen123", "Null", TextVN_TuLuyen[123], sizeof(TextVN_TuLuyen[123]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen124", "Null", TextVN_TuLuyen[124], sizeof(TextVN_TuLuyen[124]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen125", "Null", TextVN_TuLuyen[125], sizeof(TextVN_TuLuyen[125]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen126", "Null", TextVN_TuLuyen[126], sizeof(TextVN_TuLuyen[126]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen127", "Null", TextVN_TuLuyen[127], sizeof(TextVN_TuLuyen[127]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen128", "Null", TextVN_TuLuyen[128], sizeof(TextVN_TuLuyen[128]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen129", "Null", TextVN_TuLuyen[129], sizeof(TextVN_TuLuyen[129]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen130", "Null", TextVN_TuLuyen[130], sizeof(TextVN_TuLuyen[130]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen131", "Null", TextVN_TuLuyen[131], sizeof(TextVN_TuLuyen[131]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen132", "Null", TextVN_TuLuyen[132], sizeof(TextVN_TuLuyen[132]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen133", "Null", TextVN_TuLuyen[133], sizeof(TextVN_TuLuyen[133]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen134", "Null", TextVN_TuLuyen[134], sizeof(TextVN_TuLuyen[134]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen135", "Null", TextVN_TuLuyen[135], sizeof(TextVN_TuLuyen[135]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen136", "Null", TextVN_TuLuyen[136], sizeof(TextVN_TuLuyen[136]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen137", "Null", TextVN_TuLuyen[137], sizeof(TextVN_TuLuyen[137]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen138", "Null", TextVN_TuLuyen[138], sizeof(TextVN_TuLuyen[138]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen139", "Null", TextVN_TuLuyen[139], sizeof(TextVN_TuLuyen[139]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen140", "Null", TextVN_TuLuyen[140], sizeof(TextVN_TuLuyen[140]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen141", "Null", TextVN_TuLuyen[141], sizeof(TextVN_TuLuyen[141]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen142", "Null", TextVN_TuLuyen[142], sizeof(TextVN_TuLuyen[142]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen143", "Null", TextVN_TuLuyen[143], sizeof(TextVN_TuLuyen[143]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen144", "Null", TextVN_TuLuyen[144], sizeof(TextVN_TuLuyen[144]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen145", "Null", TextVN_TuLuyen[145], sizeof(TextVN_TuLuyen[145]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen146", "Null", TextVN_TuLuyen[146], sizeof(TextVN_TuLuyen[146]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen147", "Null", TextVN_TuLuyen[147], sizeof(TextVN_TuLuyen[147]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen148", "Null", TextVN_TuLuyen[148], sizeof(TextVN_TuLuyen[148]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen149", "Null", TextVN_TuLuyen[149], sizeof(TextVN_TuLuyen[149]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen150", "Null", TextVN_TuLuyen[150], sizeof(TextVN_TuLuyen[150]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen151", "Null", TextVN_TuLuyen[151], sizeof(TextVN_TuLuyen[151]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen152", "Null", TextVN_TuLuyen[152], sizeof(TextVN_TuLuyen[152]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen153", "Null", TextVN_TuLuyen[153], sizeof(TextVN_TuLuyen[153]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen154", "Null", TextVN_TuLuyen[154], sizeof(TextVN_TuLuyen[154]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen155", "Null", TextVN_TuLuyen[155], sizeof(TextVN_TuLuyen[155]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen156", "Null", TextVN_TuLuyen[156], sizeof(TextVN_TuLuyen[156]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen157", "Null", TextVN_TuLuyen[157], sizeof(TextVN_TuLuyen[157]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen158", "Null", TextVN_TuLuyen[158], sizeof(TextVN_TuLuyen[158]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen159", "Null", TextVN_TuLuyen[159], sizeof(TextVN_TuLuyen[159]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen160", "Null", TextVN_TuLuyen[160], sizeof(TextVN_TuLuyen[160]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen161", "Null", TextVN_TuLuyen[161], sizeof(TextVN_TuLuyen[161]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen162", "Null", TextVN_TuLuyen[162], sizeof(TextVN_TuLuyen[162]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen163", "Null", TextVN_TuLuyen[163], sizeof(TextVN_TuLuyen[163]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen164", "Null", TextVN_TuLuyen[164], sizeof(TextVN_TuLuyen[164]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen165", "Null", TextVN_TuLuyen[165], sizeof(TextVN_TuLuyen[165]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen166", "Null", TextVN_TuLuyen[166], sizeof(TextVN_TuLuyen[166]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen167", "Null", TextVN_TuLuyen[167], sizeof(TextVN_TuLuyen[167]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen168", "Null", TextVN_TuLuyen[168], sizeof(TextVN_TuLuyen[168]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen169", "Null", TextVN_TuLuyen[169], sizeof(TextVN_TuLuyen[169]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen170", "Null", TextVN_TuLuyen[170], sizeof(TextVN_TuLuyen[170]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen171", "Null", TextVN_TuLuyen[171], sizeof(TextVN_TuLuyen[171]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen172", "Null", TextVN_TuLuyen[172], sizeof(TextVN_TuLuyen[172]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen173", "Null", TextVN_TuLuyen[173], sizeof(TextVN_TuLuyen[173]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen174", "Null", TextVN_TuLuyen[174], sizeof(TextVN_TuLuyen[174]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen175", "Null", TextVN_TuLuyen[175], sizeof(TextVN_TuLuyen[175]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen176", "Null", TextVN_TuLuyen[176], sizeof(TextVN_TuLuyen[176]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen177", "Null", TextVN_TuLuyen[177], sizeof(TextVN_TuLuyen[177]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen178", "Null", TextVN_TuLuyen[178], sizeof(TextVN_TuLuyen[178]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen179", "Null", TextVN_TuLuyen[179], sizeof(TextVN_TuLuyen[179]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen180", "Null", TextVN_TuLuyen[180], sizeof(TextVN_TuLuyen[180]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen181", "Null", TextVN_TuLuyen[181], sizeof(TextVN_TuLuyen[181]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen182", "Null", TextVN_TuLuyen[182], sizeof(TextVN_TuLuyen[182]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen183", "Null", TextVN_TuLuyen[183], sizeof(TextVN_TuLuyen[183]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen184", "Null", TextVN_TuLuyen[184], sizeof(TextVN_TuLuyen[184]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen185", "Null", TextVN_TuLuyen[185], sizeof(TextVN_TuLuyen[185]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen186", "Null", TextVN_TuLuyen[186], sizeof(TextVN_TuLuyen[186]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen187", "Null", TextVN_TuLuyen[187], sizeof(TextVN_TuLuyen[187]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen188", "Null", TextVN_TuLuyen[188], sizeof(TextVN_TuLuyen[188]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen189", "Null", TextVN_TuLuyen[189], sizeof(TextVN_TuLuyen[189]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen190", "Null", TextVN_TuLuyen[190], sizeof(TextVN_TuLuyen[190]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen191", "Null", TextVN_TuLuyen[191], sizeof(TextVN_TuLuyen[191]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen192", "Null", TextVN_TuLuyen[192], sizeof(TextVN_TuLuyen[192]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen193", "Null", TextVN_TuLuyen[193], sizeof(TextVN_TuLuyen[193]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen194", "Null", TextVN_TuLuyen[194], sizeof(TextVN_TuLuyen[194]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen195", "Null", TextVN_TuLuyen[195], sizeof(TextVN_TuLuyen[195]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen196", "Null", TextVN_TuLuyen[196], sizeof(TextVN_TuLuyen[196]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen197", "Null", TextVN_TuLuyen[197], sizeof(TextVN_TuLuyen[197]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen198", "Null", TextVN_TuLuyen[198], sizeof(TextVN_TuLuyen[198]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen199", "Null", TextVN_TuLuyen[199], sizeof(TextVN_TuLuyen[199]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen200", "Null", TextVN_TuLuyen[200], sizeof(TextVN_TuLuyen[200]), MENU_GAME_FILE);

	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen201", "Null", TextVN_TuLuyen[201], sizeof(TextVN_TuLuyen[201]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen202", "Null", TextVN_TuLuyen[202], sizeof(TextVN_TuLuyen[202]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen203", "Null", TextVN_TuLuyen[203], sizeof(TextVN_TuLuyen[203]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen204", "Null", TextVN_TuLuyen[204], sizeof(TextVN_TuLuyen[204]), MENU_GAME_FILE);
	GetPrivateProfileStringA("TextVN_TuLuyen", "TextVN_TuLuyen205", "Null", TextVN_TuLuyen[205], sizeof(TextVN_TuLuyen[205]), MENU_GAME_FILE);
#endif

	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP0", "Null", HIEPMOCNAP[0], sizeof(HIEPMOCNAP[0]), MENU_GAME_FILE);

	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP1", "Null", HIEPMOCNAP[1], sizeof(HIEPMOCNAP[1]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP2", "Null", HIEPMOCNAP[2], sizeof(HIEPMOCNAP[2]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP3", "Null", HIEPMOCNAP[3], sizeof(HIEPMOCNAP[3]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP4", "Null", HIEPMOCNAP[4], sizeof(HIEPMOCNAP[4]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP5", "Null", HIEPMOCNAP[5], sizeof(HIEPMOCNAP[5]), MENU_GAME_FILE);

	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP6", "Null", HIEPMOCNAP[6], sizeof(HIEPMOCNAP[6]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP7", "Null", HIEPMOCNAP[7], sizeof(HIEPMOCNAP[7]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP8", "Null", HIEPMOCNAP[8], sizeof(HIEPMOCNAP[8]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP9", "Null", HIEPMOCNAP[9], sizeof(HIEPMOCNAP[9]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP10", "Null", HIEPMOCNAP[10], sizeof(HIEPMOCNAP[10]), MENU_GAME_FILE);

	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP11", "Null", HIEPMOCNAP[11], sizeof(HIEPMOCNAP[11]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP12", "Null", HIEPMOCNAP[12], sizeof(HIEPMOCNAP[12]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP13", "Null", HIEPMOCNAP[13], sizeof(HIEPMOCNAP[13]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP14", "Null", HIEPMOCNAP[14], sizeof(HIEPMOCNAP[14]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP15", "Null", HIEPMOCNAP[15], sizeof(HIEPMOCNAP[15]), MENU_GAME_FILE);

	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP16", "Null", HIEPMOCNAP[16], sizeof(HIEPMOCNAP[16]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP17", "Null", HIEPMOCNAP[17], sizeof(HIEPMOCNAP[17]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP18", "Null", HIEPMOCNAP[18], sizeof(HIEPMOCNAP[18]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP19", "Null", HIEPMOCNAP[19], sizeof(HIEPMOCNAP[19]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP20", "Null", HIEPMOCNAP[20], sizeof(HIEPMOCNAP[20]), MENU_GAME_FILE);

	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP21", "Null", HIEPMOCNAP[21], sizeof(HIEPMOCNAP[21]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP22", "Null", HIEPMOCNAP[22], sizeof(HIEPMOCNAP[22]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP23", "Null", HIEPMOCNAP[23], sizeof(HIEPMOCNAP[23]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP24", "Null", HIEPMOCNAP[24], sizeof(HIEPMOCNAP[24]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP25", "Null", HIEPMOCNAP[25], sizeof(HIEPMOCNAP[25]), MENU_GAME_FILE);

	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP26", "Null", HIEPMOCNAP[26], sizeof(HIEPMOCNAP[26]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP27", "Null", HIEPMOCNAP[27], sizeof(HIEPMOCNAP[27]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP28", "Null", HIEPMOCNAP[28], sizeof(HIEPMOCNAP[28]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP29", "Null", HIEPMOCNAP[29], sizeof(HIEPMOCNAP[29]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP30", "Null", HIEPMOCNAP[30], sizeof(HIEPMOCNAP[30]), MENU_GAME_FILE);

	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP31", "Null", HIEPMOCNAP[31], sizeof(HIEPMOCNAP[31]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP32", "Null", HIEPMOCNAP[32], sizeof(HIEPMOCNAP[32]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP33", "Null", HIEPMOCNAP[33], sizeof(HIEPMOCNAP[33]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP34", "Null", HIEPMOCNAP[34], sizeof(HIEPMOCNAP[34]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP35", "Null", HIEPMOCNAP[35], sizeof(HIEPMOCNAP[35]), MENU_GAME_FILE);

	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP36", "Null", HIEPMOCNAP[36], sizeof(HIEPMOCNAP[36]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP37", "Null", HIEPMOCNAP[37], sizeof(HIEPMOCNAP[37]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP38", "Null", HIEPMOCNAP[38], sizeof(HIEPMOCNAP[38]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP39", "Null", HIEPMOCNAP[39], sizeof(HIEPMOCNAP[39]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP40", "Null", HIEPMOCNAP[40], sizeof(HIEPMOCNAP[40]), MENU_GAME_FILE);

	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP41", "Null", HIEPMOCNAP[41], sizeof(HIEPMOCNAP[41]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP42", "Null", HIEPMOCNAP[42], sizeof(HIEPMOCNAP[42]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP43", "Null", HIEPMOCNAP[43], sizeof(HIEPMOCNAP[43]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP44", "Null", HIEPMOCNAP[44], sizeof(HIEPMOCNAP[44]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP45", "Null", HIEPMOCNAP[45], sizeof(HIEPMOCNAP[45]), MENU_GAME_FILE);

	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP46", "Null", HIEPMOCNAP[46], sizeof(HIEPMOCNAP[46]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP47", "Null", HIEPMOCNAP[47], sizeof(HIEPMOCNAP[47]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP48", "Null", HIEPMOCNAP[48], sizeof(HIEPMOCNAP[48]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP49", "Null", HIEPMOCNAP[49], sizeof(HIEPMOCNAP[49]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP50", "Null", HIEPMOCNAP[50], sizeof(HIEPMOCNAP[50]), MENU_GAME_FILE);

	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP51", "Null", HIEPMOCNAP[51], sizeof(HIEPMOCNAP[51]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP52", "Null", HIEPMOCNAP[52], sizeof(HIEPMOCNAP[52]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP53", "Null", HIEPMOCNAP[53], sizeof(HIEPMOCNAP[53]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP54", "Null", HIEPMOCNAP[54], sizeof(HIEPMOCNAP[54]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP55", "Null", HIEPMOCNAP[55], sizeof(HIEPMOCNAP[55]), MENU_GAME_FILE);

	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP56", "Null", HIEPMOCNAP[56], sizeof(HIEPMOCNAP[56]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP57", "Null", HIEPMOCNAP[57], sizeof(HIEPMOCNAP[57]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP58", "Null", HIEPMOCNAP[58], sizeof(HIEPMOCNAP[58]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP59", "Null", HIEPMOCNAP[59], sizeof(HIEPMOCNAP[59]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP60", "Null", HIEPMOCNAP[60], sizeof(HIEPMOCNAP[60]), MENU_GAME_FILE);

	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP61", "Null", HIEPMOCNAP[61], sizeof(HIEPMOCNAP[61]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP62", "Null", HIEPMOCNAP[62], sizeof(HIEPMOCNAP[62]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP63", "Null", HIEPMOCNAP[63], sizeof(HIEPMOCNAP[63]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP64", "Null", HIEPMOCNAP[64], sizeof(HIEPMOCNAP[64]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP65", "Null", HIEPMOCNAP[65], sizeof(HIEPMOCNAP[65]), MENU_GAME_FILE);

	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP66", "Null", HIEPMOCNAP[66], sizeof(HIEPMOCNAP[66]), MENU_GAME_FILE);
	GetPrivateProfileStringA("HIEPMOCNAP", "HIEPMOCNAP67", "Null", HIEPMOCNAP[67], sizeof(HIEPMOCNAP[67]), MENU_GAME_FILE);

}