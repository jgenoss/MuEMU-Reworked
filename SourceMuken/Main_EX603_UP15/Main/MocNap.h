#pragma once
#include "Import.h"
#include "Interface.h"
#include "Protocol.h"

#if(MOCNAP == 1)
#define add1 1
#define gcolor eWhite
//-----------------------------------------------------------------------------------------------------------------------------------------------------
class BEXO_MOCNAP
{
public:
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	BEXO_MOCNAP();
	void DRAW_MOCNAP();
	void BIND();
	bool HIENTHIMOCNAP;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainWidth;
	float MainHeight;
	float StartY;
	float StartX;
	DWORD ClickTick;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	void		OPEN_WINDOW_MOCNAP() { gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_WINDOW_MOCNAP() { gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_WINDOW_MOCNAP() { return gInterface.Data[EXBEXO_MOCNAP_MAIN].OnShow; };

	void		DRAW_WINDOW_MOCNAP();

	bool		MAIN_MOCNAP(DWORD Event);
	bool		CLOSE_MOCNAP(DWORD Event);

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}; extern BEXO_MOCNAP G_BEXO_MOCNAP;
//===================================================================================================================================================================

#endif