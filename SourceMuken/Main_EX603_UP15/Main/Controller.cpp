#include "stdafx.h"
#include "resource.h"
#include "Controller.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protocol.h"
#include "Import.h"
#include "Interface.h"
#include "Protect.h"
#include "TMemory.h"
#include "CSCharacterS13.h"
#include "CMacroUIEx.h"
#include "Camera.h"
#include "TrayModeNew.h"
#include "MiniMap.h"
#include "WindowsStruct.h"
#include "Ruud.h"
#include "Central.h"
#include "User.h"
#include "PartySearchSettings.h"
#include "MocNap.h"
#include "PartySearch.h"
#include "CustomLuckySpin.h"
#include "CustomJewelBank.h"
#include "MiniMap.h"
#include "TuLuyen.h"
#include "DanhHieu.h"
#include "Ranking.h"
#include "QuanLyTaiKhoan.h"
// ----------------------------------------------------------------------------------------------

Controller	gController;
// ----------------------------------------------------------------------------------------------
#if(NOTICE_MES==1)
char Notice_1[1024];
char Notice_2[1024];
char CameraNotAc[1024];
char CameraOn[1024];
char CameraOff[1024];
char CameraDefault[1024];
char GlowOn[1024];
char GlowOff[1024];
char AutoOn[1024];
char AutoOff[1024];

#endif

void __declspec(naked) iconHook()
{
	static DWORD dwIcon = (DWORD)LoadIcon(gController.Instance, MAKEINTRESOURCE(IDI_ICON1));
	static DWORD dwJmp = 0x004D0E3C;

	_asm
	{
		MOV EAX, dwIcon
		JMP dwJmp
	}
}

bool Controller::Load()
{
	if( !this->MouseHook )
	{
		this->MouseHook = SetWindowsHookEx(WH_MOUSE, this->Mouse, gController.Instance, GetCurrentThreadId());
		// ----
#if(NOTICE_MES==1)

				GetPrivateProfileString("Notice", "Notice_1", "", Notice_1, 1024, ".\\data\\Custom\\Notice.ini");
				GetPrivateProfileString("Notice", "Notice_2", "", Notice_2, 1024, ".\\data\\Custom\\Notice.ini");
				GetPrivateProfileString("Notice", "CameraNotAc", "", CameraNotAc, 1024, ".\\data\\Custom\\Notice.ini");
				GetPrivateProfileString("Message", "CameraOn", "", CameraOn, 1024, ".\\data\\Custom\\Notice.ini");
				GetPrivateProfileString("Message", "CameraOff", "", CameraOff, 1024, ".\\data\\Custom\\Notice.ini");
				GetPrivateProfileString("Message", "CameraDefault", "", CameraDefault, 1024, ".\\data\\Custom\\Notice.ini");
				GetPrivateProfileString("Message", "GlowOn", "", GlowOn, 1024, ".\\data\\Custom\\Notice.ini");
				GetPrivateProfileString("Message", "GlowOff", "", GlowOff, 1024, ".\\data\\Custom\\Notice.ini");
				GetPrivateProfileString("Message", "AutoOn", "", AutoOn, 1024, ".\\data\\Custom\\Notice.ini");
				GetPrivateProfileString("Message", "AutoOff", "", AutoOff, 1024, ".\\data\\Custom\\Notice.ini");

#endif
		if( !this->MouseHook )
		{
			return false;
		}
	}
	// ----
	if( !this->KeyboardHook )
	{
		this->KeyboardHook = SetWindowsHookExA(WH_KEYBOARD, this->Keyboard, gController.Instance, GetCurrentThreadId());
	}
	// ----
	SetOp((LPVOID)0x004D0E2F, iconHook, ASM::CALL);
	return true;
}


LRESULT Controller::Mouse(int Code, WPARAM wParam, LPARAM lParam)
{
	if( GetForegroundWindow() != pGameWindow )
	{
		return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
	}
	// ----
	MOUSEHOOKSTRUCTEX * Mouse	= (MOUSEHOOKSTRUCTEX*)lParam;
	gController.wMouse = wParam;

	switch(wParam)
	{
	case WM_LBUTTONUP:
	case WM_LBUTTONDOWN:
		{
#if(RANKINGGOC == 1)
			gCustomRanking.EventRankingNext(wParam);
			gCustomRanking.EventRankingBack(wParam);
			gCustomRanking.EventRankingWindow_Close(wParam);
#endif
			G_QUAN_LY_TK.EVENT_CLICK_CHANGEPASS(wParam);
			gInterface.EventVipWindow_Main(wParam);
			gCustomCommandInfo.EventCommandWindow_Close(wParam);
			gCustomCommandInfo.CommandNext(wParam);
			gCustomCommandInfo.CommandPrev(wParam);
			gCustomEventTime.EventEventTimeWindow_Close(wParam);
			gCustomEventTime.EventNext(wParam);
			gCustomEventTime.EventPrev(wParam);
			gInterface.EventDrawMenu_Open(wParam);
			gInterface.EventDrawMenu_Close(wParam);
			gInterface.EventDrawMenu_Op1(wParam);
			gInterface.EventDrawMenu_Op2(wParam);
			gInterface.EventDrawMenu_Op3(wParam);
			gInterface.EventDrawMenu_Op4(wParam);
			gInterface.EventDrawMenu_Op5(wParam);
			gInterface.EventDrawMenu_Op6(wParam);
			gInterface.EventDrawMenu_Op7(wParam);
			gInterface.EventDrawMenu_Op8(wParam);
			gInterface.EventDrawMenu_Op9(wParam);
			gInterface.EventDrawMenu_Op10(wParam);
			gInterface.EventDrawMenu_Op11(wParam);
			gInterface.EventDrawMenu_Op12(wParam);
			gInterface.EventDrawMenu_Op20(wParam);

#if(MOCNAP == 1)
				G_BEXO_MOCNAP.MAIN_MOCNAP(wParam);
#endif

#if (SACHTHUOCTINH_NEW)

			gInterface.EventSachThuocTinhInterface(wParam);
	
#endif




			//btn move event
			gCustomEventTime.EventDrawMenu_Op21(wParam);
			gCustomEventTime.EventDrawMenu_Op22(wParam);
			gCustomEventTime.EventDrawMenu_Op23(wParam);
			gCustomEventTime.EventDrawMenu_Op24(wParam);
			gCustomEventTime.EventDrawMenu_Op25(wParam);
			gCustomEventTime.EventDrawMenu_Op26(wParam);
			gCustomEventTime.EventDrawMenu_Op27(wParam);
			gCustomEventTime.EventDrawMenu_Op28(wParam);
			gCustomEventTime.EventDrawMenu_Op29(wParam);
			gCustomEventTime.EventDrawMenu_Op30(wParam);
			gCustomEventTime.EventDrawMenu_Op31(wParam);
			gCustomEventTime.EventDrawMenu_Op32(wParam);
			gCustomEventTime.EventDrawMenu_Op33(wParam);
			gCustomEventTime.EventDrawMenu_Op34(wParam);
			gCustomEventTime.EventDrawMenu_Op35(wParam);
			gCustomEventTime.EventDrawMenu_Op36(wParam);
			gCustomEventTime.EventDrawMenu_Op37(wParam);
			gCustomEventTime.EventDrawMenu_Op38(wParam);
			gCustomEventTime.EventDrawMenu_Op39(wParam);
			gCustomEventTime.EventDrawMenu_Op40(wParam);
			gCustomEventTime.EventDrawMenu_Op41(wParam);
			gCustomEventTime.EventDrawMenu_Op42(wParam);
			gCustomEventTime.EventDrawMenu_Op43(wParam);
			gCustomEventTime.EventDrawMenu_Op44(wParam);
			gCustomEventTime.EventDrawMenu_Op45(wParam);
			gCustomEventTime.EventDrawMenu_Op46(wParam);
			gCustomEventTime.EventDrawMenu_Op47(wParam);
			gCustomEventTime.EventDrawMenu_Op48(wParam);
			gCustomEventTime.EventDrawMenu_Op49(wParam);
			gCustomEventTime.EventDrawMenu_Op50(wParam);
			gCustomEventTime.EventDrawMenu_Op51(wParam);
			gCustomEventTime.EventDrawMenu_Op52(wParam);
			gCustomEventTime.EventDrawMenu_Op53(wParam);
			gCustomEventTime.EventDrawMenu_Op54(wParam);
			gCustomEventTime.EventDrawMenu_Op55(wParam);
			gCustomEventTime.EventDrawMenu_Op56(wParam);
			gCustomEventTime.EventDrawMenu_Op57(wParam);
			gCustomEventTime.EventDrawMenu_Op58(wParam);
			gCustomEventTime.EventDrawMenu_Op59(wParam);
			gCustomEventTime.EventDrawMenu_Op60(wParam);
			gCustomEventTime.EventDrawMenu_Op61(wParam);

#if(NUT_TINH_NANG)
			gInterface.EventDrawnNapThe_Open(wParam);
			gInterface.EventDrawnFacebook_Open(wParam);
			//gInterface.EventDrawFanpage_Open(wParam);
			//gInterface.EventDrawGoup_Open(wParam);
#endif

#if(OFFLINE_MODE_NEW)
			gInterface.EventOffExpWindow_Main(wParam);
#endif

#if(EXBEXO_LOAD_SEND_TINH_NANG)
			gInterface.EVENT_TINHNANG_INTERFACE(wParam);
#endif
			//-----------------------------------------------------------------------------------------------------



            #if(PARTYSEARCH==1)
			    gPartySearch.EventPartySearchWindow_All(wParam);
			    gPartySearch.EventPartySettingsWindow_Main(wParam);
            #endif

#if (NGAN_HANG_NGOC)
			gCustomJewelBank.CommandNext(wParam);
			gCustomJewelBank.CommandPrev(wParam);
			gCustomJewelBank.EventJewelBankWindow_Close(wParam);
			gCustomJewelBank.EventJewelBankWithDraw(wParam);
#endif

#if(DANH_HIEU_NEW == 1)
			G_BEXO_DANH_HIEU.BEXO_CLICK_TRANG_DANH_HIEU(wParam);
			G_BEXO_DANH_HIEU.MAIN_DANH_HIEU(wParam);
#endif
#if(OANTUTY)
			gInterface.EventRPS_Main(wParam);
#endif

#if(DOI_GIOI_TINH)
			gLuckySpin.EventWindow_Main(wParam);
#endif
#if(VONGQUAY_NEW)
			gInterface.EventChangingClassWindow_Main(wParam);
#endif
			gInterface.EventConfirm_CANCEL(wParam);
			gInterface.EventConfirm_OK(wParam);
			gCRuudShop.RuudShopEventButton(wParam);
			gCSCharacterS13.SelectCharButton(wParam);
			EventMuOffhelper(wParam);



#if(TU_LUYEN_NEW == 1)
			G_BEXO_TU_LUYEN.BEXO_CLICK_TRANG_TU_LUYEN(wParam);
			G_BEXO_TU_LUYEN.MAIN_TU_LUYEN(wParam);
#endif



			if(gCRuudShop.RuudRender.Open)
			{
				if ( pCheckMouseOver(gCRuudShop.RuudRender.x, gCRuudShop.RuudRender.y + 10, gCRuudShop.RuudRender.w, 40.0f) == 1 )
				{
					gCRuudShop.RuudRender.Cursor.x = (double)*(DWORD*)0x879340C - gCRuudShop.RuudRender.x;
					gCRuudShop.RuudRender.Cursor.y = (double)*(DWORD*)0x8793410 - gCRuudShop.RuudRender.y;
					if(wParam == WM_LBUTTONDOWN)
					{
						gCRuudShop.RuudRender.Move = 1;
					}
					else
					{
						gCRuudShop.RuudRender.Move = 0;
					}
				}
				else
				{
					gCRuudShop.RuudRender.Move = 0;
				}
			}
			else if(gProtect.m_MainInfo.CustomInterfaceType == 1)
			{
				gInterface.EventNewInterface97_All(wParam);
			}
			else if(gProtect.m_MainInfo.CustomInterfaceType == 2)
			{
				gInterface.EventNewInterface_All(wParam);
			}
			gCMacroUIEx.Button(wParam);
			gOffTrade.EventOffTradeWindow_Main(wParam);
			gOffTrade.EventCloseTradeWindow_Main(wParam);
		}
		
		break;
		case WM_MOUSEMOVE:

			gCRuudShop.MoveWindows(&gCRuudShop.RuudRender,
				((double)*(DWORD*)0x879340C) - gCRuudShop.RuudRender.Cursor.x,
				((double)*(DWORD*)0x8793410) - gCRuudShop.RuudRender.Cursor.y);

			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.Move(Mouse);
			}
			break;
		case WM_MBUTTONDOWN:
			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.SetIsMove(1);
				gCamera.SetCursorX(Mouse->pt.x);
				gCamera.SetCursorY(Mouse->pt.y);
			}
			break;
		case WM_MBUTTONUP:
			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.SetIsMove(0);
			}
			break;
		case WM_MOUSEWHEEL:
			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.Zoom(Mouse);
			}
			break;
	}
	// ----
	return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
}
// ----------------------------------------------------------------------------------------------

LRESULT Controller::Keyboard(int Code, WPARAM wParam, LPARAM lParam)
{
	if( ((lParam >> 31) & 1) && (Code == HC_ACTION) )
	{
		if(GetForegroundWindow() != pGameWindow || pPlayerState != GameProcess)
		{
			return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
		}

		gController.wKeyBord = wParam;

	}

	//if(GetForegroundWindow() == pGameWindow && pPlayerState == GameProcess)
	//{
	//	if(Code == HC_ACTION)
	//	{
	//		if(((lParam >> 31) & 1))
	//		{
	//			#if(DEV_PLAYERSHOP)
	//			g_ItemMarket.Keyboard(wParam);
	//			#endif
	//		}
	//	}
	//}

	if(GetForegroundWindow() == pGameWindow && pPlayerState == GameProcess) // 
		if(Code == HC_ACTION)
		{
			if(((DWORD)lParam & (1 << 30)) != 0 && ((DWORD)lParam & (1 << 31)) != 0)
			{
				if( GetForegroundWindow() == *(HWND*)(MAIN_WINDOW) )
				{
					

					G_QUAN_LY_TK.CHANGEPASS_TEXTBOX(wParam);
					gCentral.keyPressed(wParam);


				}
			}
		}
	

	return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
}
// ----------------------------------------------------------------------------------------------


LRESULT Controller::Window(HWND Window, DWORD Message, WPARAM wParam, LPARAM lParam)
{
	switch(Message)
	{

	case TRAYMODE_ICON_MESSAGE:
		{
			switch(lParam)
			{
			case WM_LBUTTONDBLCLK:
				{
					gTrayMode.SwitchState();
				}
				break;
			}
		}
		break;
	}
	// ----
	return CallWindowProc((WNDPROC)gTrayMode.TempWindowProc, Window, Message, wParam, lParam);
}


