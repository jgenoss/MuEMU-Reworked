#pragma once
#include "Import.h"
#include "Interface.h"
#include "Protocol.h"

#if(TU_LUYEN_NEW == 1)

struct BUY_TU_LUYEN_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------
class BEXO_TU_LUYEN
{
public:
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	BEXO_TU_LUYEN();
	void DRAW_TU_LUYEN();
	bool HIENTHITU_LUYEN;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	int TRANG_TU_LUYEN;
	void BEXO_CLICK_TRANG_TU_LUYEN(DWORD ClickMouse);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainWidth;
	float MainHeight;
	float StartY;
	float StartX;
	DWORD ClickTick;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	void		OPEN_WINDOW_TU_LUYEN() { gInterface.Data[EXBEXO_TU_LUYEN_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_WINDOW_TU_LUYEN() { gInterface.Data[EXBEXO_TU_LUYEN_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_WINDOW_TU_LUYEN() { return gInterface.Data[EXBEXO_TU_LUYEN_MAIN].OnShow; };

	void		DRAW_WINDOW_TU_LUYEN();

	bool		MAIN_TU_LUYEN(DWORD Event);
	bool		CLOSE_TU_LUYEN(DWORD Event);

	void BUY_TU_LUYEN(int Number);

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}; extern BEXO_TU_LUYEN G_BEXO_TU_LUYEN;
//===================================================================================================================================================================

#endif