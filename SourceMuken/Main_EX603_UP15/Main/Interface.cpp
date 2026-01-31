#include "stdafx.h"
#include "Common.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "Interface.h"
#include "Import.h"
#include "Reconnect.h"
#include "TMemory.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protect.h"
#include "Protocol.h"
#include "PrintPlayer.h"
#include "User.h"
#include "Util.h"
#include "array.h"
#include "Offset.h"
#include "StatsAdvance.h"
#include "CustomCloak.h"
#include "ChatExpanded.h"
#include "Camera.h"
#include "TrayModeNew.h"
#include "Controller.h"
#include "postInterface.h"
#include "Ruud.h"
#include "Inter3.h"
#include "InterEx.h"
#include "Central.h"
#include "NPCRuud.h"
#include "CustomFont.h"
#include "CustomEventTime.h"
#include "CMacroUIEx.h"
#include "PartySearchSettings.h"
#include "PartySearch.h"
#include "Config.h"
#include "time.h"
#include "CustomLuckySpin.h"
#include "ChangeClass.h"
#include "SItemOption.h"
#include "CustomJewelBank.h"
#include "EmojiSystem.h"
#include "MiniMap.h"
#include "WindowsStruct.h"
#include "MocNap.h"
#include "DanhHieu.h"
#include "TuLuyen.h"
#include "HuyHieuCuongHoa.h"
#include "CustomCuongHoaWing.h"
#include "Ranking.h"
#include "MSGCommon.h"
#include "CustomOfflineMode.h"
#include "CustomVKR.h"
#include "QuanLyTaiKhoan.h"
#include "Character.h"
#include "CustomRankUser.h"
#include "CTimCheck.h"
#include "ThueFlag.h"

Interface gInterface;

Interface::Interface()
{
}

Interface::~Interface()
{
}



void Interface::RenderObjectSystem()
{
	if(gProtect.m_MainInfo.MonitorMS == 1){
		gInterface.lastReport = GetTickCount();
		gInterface.frameCount = 0;
	}
	if(gProtect.m_MainInfo.MonitorFPS == 1){
		gInterface.iniciador = 1;
	}

	#if(PARTYSEARCH==1)
		gPartySearch.loadBind();
	#endif
#if(EVENT_END_LESS)
		gInterface.mEndLessEvenInfoClear();
#endif

		gEmojis.AddTextures(); //> Agregar esto

		gHuyHieuCuongHoa.BinObeject();

		gCuongHoaWing.BinObeject();

		gVuKhiRong.BinObeject();
		 G_QUAN_LY_TK.BinObeject();

#if(FLAG_SKIN)
		 ThueFlag.Bind();
#endif

#if (NGAN_HANG_NGOC)
		//Jewel Bank
		this->BindObject(eJewelBank_MAIN, 0x7A5A, 222, 240, -1, -1);
		this->BindObject(eJewelBank_TITLE, 0x7A63, 230, 67, -1, -1);
		this->BindObject(eJewelBank_FRAME, 0x7A58, 230, 15, -1, -1);
		this->BindObject(eJewelBank_FOOTER, 0x7A59, 230, 50, -1, -1);
		this->BindObject(eJewelBank_DIV, 0x7A62, 223, 21, -1, -1);
		this->BindObject(eJewelBank_CLOSE, 0x7EC5, 36, 29, -1, -1);
		this->BindObject(eJewelBank_NEXT, 0x7903, 25, 40, -1, -1);
		this->BindObject(eJewelBank_PREV, 0x7904, 25, 40, -1, -1);

		for (int i = 0; i < 50; i++)
		{
			this->BindObject(eJewelBank_WITHDRAW + i, 31743, 16, 32, -1, -1);
		}
#endif




#if(EXBEXO_LOAD_SEND_TINH_NANG)
		this->BindObject(EXBEXO_AUTORESET_INTERFACE, 0x313A, 78, 22, -1, -1);
		this->BindObject(EXBEXO_QUESTCLASS_INTERFACE, 0x313A, 78, 22, -1, -1);
		this->BindObject(EXBEXO_OFFATTACK_INTERFACE, 0x313A, 78, 22, -1, -1);
		this->BindObject(EXBEXO_UYTHAC_INTERFACE, 0x313A, 78, 22, -1, -1);
		this->BindObject(EXBEXO_TAYDIEM_INTERFACE, 0x313A, 78, 22, -1, -1);
		this->BindObject(EXBEXO_TAYDIEMMASTER_INTERFACE, 0x313A, 78, 22, -1, -1);
#endif


#if(NUT_TINH_NANG)
		if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 4)
		{
			this->BindObject(eNAPTHE, 31461, 35, 14, -1, -1);  // 31461
			this->BindObject(eFACEBOOK, 31461, 35, 14, -1, -1);  // 31461
			//this->BindObject(eFANPAGE, 31461, 35, 14, -1, -1);  // 31461
			//this->BindObject(eGOUP, 31461, 35, 14, -1, -1);  // 31461
		}
#endif


	//51522
	//==============================================================>
#if(DANH_HIEU_NEW == 1)
	this->BindObject(EXBEXO_DANH_HIEU_MAIN, 0x0899, 560, 279, -1, -1);
	this->BindObject(EXBEXO_DANH_HIEU_CLOSE, 61529, 11, 11, -1, -1);
	this->BindObject(EXBEXO_DANH_HIEU_NANG_CAP, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eDANH_HIEU1, 32342, 20, 23, -1, -1);
	this->BindObject(eDANH_HIEU2, 32343, 20, 23, -1, -1);
#endif
#if(TU_LUYEN_NEW == 1)
		this->BindObject(EXBEXO_TU_LUYEN_MAIN, 0x0899, 560, 279, -1, -1);
		this->BindObject(EXBEXO_TU_LUYEN_CLOSE, 0x7EC5, 36, 29, -1, -1);
		this->BindObject(EXBEXO_TU_LUYEN_NANG_CAP, 0x7A5E, 108, 29, -1, -1);

		this->BindObject(eTU_LUYEN2, 0x7903, 25, 40, -1, -1);
		this->BindObject(eTU_LUYEN1, 0x7904, 25, 40, -1, -1);
#endif




	//----------------------------------------------------------------------------------------
#if(VONGQUAY_NEW)
	this->BindObject(eLuckySpin, 31461, 640, 419, -1, -1);  // 31461
	this->BindObject(eLuckySpinRoll, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eLuckySpinClose, 0x7EC5, 36, 29, -1, -1);
#endif

#if(OFFLINE_MODE_NEW)
	this->BindObject(eOFFEXP_MAIN, 31461, 900, 1000, -1, -1);  // 31461
	this->BindObject(eOFFEXP_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eOFFEXP_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eOFFEXP_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eOFFEXP_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eOFFEXP_POINT, 0x7B68, 10, 10, -1, -1);
	this->BindObject(eOFFEXP_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eOFFEXP_CHECKBOX_BUFF, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eOFFEXP_CHECKBOX_PICK_ZEN, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eOFFEXP_CHECKBOX_PICK_JEWELS, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eOFFEXP_CHECKBOX_PICK_EXC, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eOFFEXP_CHECKBOX_PICK_ANC, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eOFFEXP_CHECKBOX_SELECTED_HELPER, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eOFFEXP_BTN_OK, 0x7A5E, 106, 29, -1, -1);

	this->BindObject(eOFFEXP_SKILL1, 0x7A4C, 20, 28, -1, -1);
	this->BindObject(eOFFEXP_SKILL2, 0x7A4C, 20, 28, -1, -1);
	this->BindObject(eOFFEXP_SKILL3, 0x7A4C, 20, 28, -1, -1);
#endif


	//----------------------------------------------------------------------------------------
#if (DOI_GIOI_TINH)
	this->BindObject(eCHANGINGCLASS_MAIN, 31461, 640, 419, -1, -1);  // 31461
	//this->BindObject(eCHANGINGCLASS_TITLE, 0x7A63, 230, 67, -1, -1);
	//this->BindObject(eCHANGINGCLASS_FRAME, 0x7A58, 230, 15, -1, -1);
	//this->BindObject(eCHANGINGCLASS_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCHANGINGCLASS_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCHANGINGCLASS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_INFOBG, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eCHANGINGCLASS_MONEYBG, 0x7A89, 170, 26, -1, -1);
	this->BindObject(eCHANGINGCLASS_DW, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_DK, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_ELF, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_MG, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_DL, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_SUM, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_RF, 0x7A5E, 106, 29, -1, -1);
#endif


#if(OANTUTY)
	//
	this->BindObject(eRock, 0x9323, 36, 28, -1, -1);
	this->BindObject(ePaper, 0x9324, 36, 28, -1, -1);
	this->BindObject(eScissors, 0x9325, 36, 28, -1, -1);
#endif

	this->BindObject(eTVTHUD, 0x9912, 200, 27, -1, -1);



	//button event

	this->BindObject(eMenu_OPT21, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT22, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT23, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT24, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT25, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT26, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT27, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT28, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT29, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT30, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT31, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT32, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT33, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT34, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT35, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT36, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT37, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT38, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT39, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT40, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT41, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT42, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT43, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT44, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT45, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT46, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT47, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT48, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT49, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT50, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT51, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT52, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT53, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT54, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT55, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT56, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT57, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT58, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT59, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT60, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT61, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT62, 0x7906, 16, 12, -1, -1);









	//--
	if( gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4 )
	{
		this->BindObject(eMenu_MAIN, 0x7A5A, 222, 300, 205, -1);
		this->BindObject(eMenu_CLOSE, 71521, 59, 28, -1, -1);
		this->BindObject(eMenu_OPT1, 71522, 108, 30.5f, -1, -1);
		this->BindObject(eMenu_OPT2, 71522, 108, 30.5f, -1, -1);
		this->BindObject(eMenu_OPT3, 71522, 108, 30.5f, -1, -1);
		this->BindObject(eMenu_OPT4, 71522, 108, 30.5f, -1, -1);
		this->BindObject(eMenu_OPT5, 71522, 108, 30.5f, -1, -1);
		this->BindObject(eMenu_OPT6, 71522, 108, 30.5f, -1, -1);
		this->BindObject(eMenu_OPT7, 71522, 108, 30.5f, -1, -1);
		this->BindObject(eMenu_OPT8, 71522, 108, 30.5f, -1, -1);
		this->BindObject(eMenu_OPT9, 71522, 108, 30.5f, -1, -1);
		this->BindObject(eMenu_OPT10, 71522, 108, 30.5f, -1, -1);
		this->BindObject(eMenu_OPT11, 71522, 108, 30.5f, -1, -1);
		this->BindObject(eMenu_OPT12, 71522, 108, 30.5f, -1, -1);

		this->BindObject(eMenu_OPT20, 71522, 108, 30.5f, -1, -1);
	}
	else
	{

		this->BindObject(eMenu_MAIN, 0x7A5A, 222, 300, 205, -1);
		this->BindObject(eMenu_CLOSE, 71521, 59, 28, -1, -1);
		this->BindObject(eMenu_OPT1, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eMenu_OPT2, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eMenu_OPT3, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eMenu_OPT4, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eMenu_OPT5, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eMenu_OPT6, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eMenu_OPT7, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eMenu_OPT8, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eMenu_OPT9, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eMenu_OPT10, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eMenu_OPT11, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eMenu_OPT12, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eMenu_OPT20, 0x7A5E, 108, 29, -1, -1);
	}


	//button event

	//--
	this->BindObject(eTIME, 30847, 106, 22, -10, 359);
	this->BindObject(eFlag01, 0x7880, 78, 78, -1, -1);
	this->BindObject(eFlag02, 0x7881, 78, 78, -1, -1);
	this->BindObject(eFlag03, 0x7882, 78, 78, -1, -1);
	this->BindObject(eFlag04, 0x7883, 78, 78, -1, -1);
	this->BindObject(eFlag05, 0x7884, 78, 78, -1, -1);
	this->BindObject(eFlag06, 0x7885, 78, 78, -1, -1);
	this->BindObject(eFlag07, 0x7886, 78, 78, -1, -1);
	this->BindObject(eFlag08, 0x7887, 78, 78, -1, -1);
	this->BindObject(eFlag09, 0x7888, 78, 78, -1, -1);
	this->BindObject(eFlag10, 0x7889, 78, 78, -1, -1);
	this->BindObject(eFlag11, 0x7890, 78, 78, -1, -1);
	this->BindObject(eFlag12, 0x7891, 78, 78, -1, -1);
	this->BindObject(eFlag13, 0x7892, 78, 78, -1, -1);
	this->BindObject(eFlag14, 0x7893, 78, 78, -1, -1);
	this->BindObject(eFlag15, 0x7894, 78, 78, -1, -1);
	this->BindObject(eFlag16, 0x7895, 78, 78, -1, -1);
	this->BindObject(eFlag17, 0x7896, 78, 78, -1, -1);
	this->BindObject(eFlag18, 0x7897, 78, 78, -1, -1);
	this->BindObject(eFlag19, 0x7898, 78, 78, -1, -1);
	this->BindObject(eFlag20, 0x7899, 78, 78, -1, -1);
	this->BindObject(eFlag21, 0x7900, 78, 78, -1, -1);
	this->BindObject(eFlag22, 0x7901, 78, 78, -1, -1);
	//--
	this->BindObject(eRanking, 0x7902, 179, 27, -1, -1);
	this->BindObject(eSAMPLEBUTTON, 0x7903, 25, 40, -1, -1);
	this->BindObject(eSAMPLEBUTTON2, 0x7904, 25, 40, -1, -1);
	//--
	this->BindObject(eVip_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eVip_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eVip_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eVip_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eVip_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eVip_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eVip_BRONZE, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_SILVER, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_GOLD, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_PLATINUM, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_STATUS, 0x7A5E, 108, 29, -1, -1);
	
	//--
	this->BindObject(eCommand_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eCommand_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCommand_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCommand_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCommand_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCommand_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
#if(RANKINGGOC == 1)
	this->BindObject(eRanking_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eRanking_CLOSE, 0x7EC5, 36, 29, -1, -1);
#endif
	this->BindObject(eEventTime_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eEventTime_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
	this->BindObject(eCONFIRM_MAIN, 0x7A5A, 222, 120, 205, -1);
	this->BindObject(eCONFIRM_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCONFIRM_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCONFIRM_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCONFIRM_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCONFIRM_BTN_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eCONFIRM_BTN_CANCEL, 0x7A5C, 54, 30, -1, -1);
	this->BindObject(eLogo, 0x7905, 150, 114, -1, -1);
	//Custom Store
	if( gProtect.m_MainInfo.CustomInterfaceType == 3 )
	{
		this->BindObject(eOFFTRADE_JoB, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_JoS, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_JoC, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCC, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCP, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCG, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_OPEN, 51522, 108, 30, -1, -1);
	}
	else
	{
		this->BindObject(eOFFTRADE_JoB, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_JoS, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_JoC, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCC, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCP, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCG, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_OPEN, 0x7BFD, 108, 30, -1, -1);
	}
	//-- custom
	this->BindObject(eSTORE_CLOSE, 0x7BFD, 108, 30, -1, -1);
	//Minimap
	this->BindObject(ePLAYER_POINT, 31460, 3, 3, -1, -1);
	this->BindObject(eNULL_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eLORENCIA_MAP, 31462, 128, 128, -1, -1);
	this->BindObject(eDUNGEON_MAP, 31463, 128, 128, -1, -1);
	this->BindObject(eDEVIAS_MAP, 31464, 128, 128, -1, -1);
	this->BindObject(eNORIA_MAP, 31465, 128, 128, -1, -1);
	this->BindObject(eLOSTTOWER_MAP, 31466, 128, 128, -1, -1);
	this->BindObject(eSTADIUM_MAP, 61465, 128, 128, -1, -1);
	this->BindObject(eATLANS_MAP, 31467, 128, 128, -1, -1);
	this->BindObject(eTarkan_MAP, 31468, 128, 128, -1, -1);
	this->BindObject(eElbeland_MAP, 31469, 128, 128, -1, -1);
	this->BindObject(eICARUS_MAP, 31470, 128, 128, -1, -1);
	this->BindObject(eLANDOFTRIALS_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eAIDA_MAP, 31472, 128, 128, -1, -1);
	this->BindObject(eCRYWOLF_MAP, 31473, 128, 128, -1, -1);
	this->BindObject(eKANTRU_MAP, 31474, 128, 128, -1, -1);
	this->BindObject(eKANTRU3_MAP, 31475, 128, 128, -1, -1);
	this->BindObject(eBARRACKS_MAP, 31476, 128, 128, -1, -1);
	this->BindObject(eCALMNESS_MAP, 31477, 128, 128, -1, -1);
	this->BindObject(eRAKLION_MAP, 31478, 128, 128, -1, -1);
	this->BindObject(eVULCANUS_MAP, 31479, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN_MAP, 31480, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN2_MAP, 31481, 128, 128, -1, -1);
	this->BindObject(eNextCommand, 31659, 17, 18, -1, -1);
	this->BindObject(ePrevCommand, 31658, 17, 18, -1, -1);
	this->BindObject(eNextEvent, 31659, 17, 18, -1, -1);
	this->BindObject(ePrevEvent, 31658, 17, 18, -1, -1);
	this->BindObject(eCamera3DInit, 31659, 17, 18, -1, -1);
	this->BindObject(eCamera3DSwitch, 31659, 17, 18, -1, -1);
	this->Data[eTIME].OnShow = true;
	if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		this->BindObject(ButtonSettings, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStart, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStop, 51522, 19, 19, -1, -1);
	}
	else
	{
		this->BindObject(ButtonSettings, 31761, 18, 13.3, -1, -1);
		this->BindObject(ButtonStart, 31762, 18, 13.3, -1, -1);
		this->BindObject(ButtonStop, 31763, 18, 13.3, -1, -1);
	}
	this->BindObject(ButtonStartAttack, 31593, 15, 15, -15, -15);
	//--

	this->BindObject(eButtonOption1, 31593, 15, 15, -1, -1);
	this->BindObject(eButtonOption2, 31593, 15, 15, -1, -1);
	this->BindObject(eButtonOption3, 31593, 15, 15, -1, -1);
	this->BindObject(eButtonOption4, 31593, 15, 15, -1, -1);
	this->BindObject(eButtonOption5, 31593, 15, 15, -1, -1);
	this->BindObject(eButtonOption6, 31593, 15, 15, -1, -1);
	this->BindObject(eButtonOption7, 31593, 15, 15, -1, -1);
	this->BindObject(eButtonOption8, 31593, 15, 15, -1, -1);
	//this->BindObject(eCloseOption, 71521, 59, 28, -1, -1);

	#if(CAMERA)
	this->BindObject(eCAMERA_MAIN, 0x787A, 72, 18, 174, 0);
	// ----
	this->BindObject(eCAMERA_BUTTON1, 0x787B, 16, 12, 185.5, 1);
	this->BindObject(eCAMERA_BUTTON2, 0x787C, 16, 12, 202.5, 1);

	this->BindObject(eCAMERA_BUTTON_UP1, 51556, 16, 12, 185.5, 1);
	this->BindObject(eCAMERA_BUTTON_UP2, 51557, 16, 12, 202.5, 1);
	#endif
	this->BindObject(eConfigHelper, 31463, 17, 18, -1, -1);


	switch(gProtect.m_MainInfo.CustomInterfaceType)
	{
	case 1:
	case 2:
		//--
		if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
			this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{
			this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
			this->BindObject(eMenuBG, 0x7907, 36, 18, 174, 0);
		}
		//--
		//newminimap
		this->BindObject(MINIMAP_FRAME, 31608, 154, 162, -10, 359);

		this->BindObject(MINIMAP_TIME_FRAME, 31609, 134.0, 37.0, -10, 359);
		this->BindObject(MINIMAP_BUTTOM, 31617, 38.0f, 24.0f, -10, 569);
		//---
		this->BindObject(eDragonLeft, 2337, 108.0, 45.0, 0.0, 385);
		this->BindObject(eDragonRight, 2336, 108.0, 45.0, 532.0, 385);
		this->BindObject(eParty, iNewParty, 25, 25, 348, 449);
		this->BindObject(eCharacter, iNewCharacter, 25, 25, 379, 449);
		this->BindObject(eInventory, iNewInventory, 25, 25, 409, 449);
		this->BindObject(eFriend, iNewWinpush, 52, 18, 581, 432);

		if(gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			this->BindObject(eFastMenu, iNewFastMenu, 53, 19, 5, 432);
		}
		this->BindObject(eGuild, iNewGuild, 52, 18, 581, 454);
		break;
	case 3:
	case 4:
		this->BindObject(eButton1, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton2, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton3, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton4, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton5, 61525, 43.0f, 17.0f, -43.0f, -17.0f);

		if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
			this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{
			this->BindObject(eMenu, 51522, 19, 19, -1, -1);
			this->BindObject(eMenuBG, 51522, 36, 18, 174, 0);
		}
		//Ex700
		this->BindObject(chatbackground, 51545, 300.0f, 128.0f, -10, 569);
		this->BindObject(eShop, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eCharacter, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eInventory, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eQuest, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eCommunity, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eSystem, 51522, 19.5f, 19.5f, -1, -1);
		break;
	default:
		if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
			this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{
			this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
			this->BindObject(eMenuBG, 0x7907, 36, 18, 174, 0);
		}
		break;
	}
	if(gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		this->BindObject(eMoney1, 0x7909, 75, 13, -1, -1);
		this->BindObject(eMoney2, 0x7910, 75, 13, -1, -1);
	}
	if(gProtect.m_MainInfo.DisableAdvance == 0)
	{
		gInterface.BindObject(eADVANCE_STAT_INFO, ex_INFO_2, 22, 19, -1, -1);
	}

#if (MOCNAP == 1)
		G_BEXO_MOCNAP.BIND();
#endif

#if(SACHTHUOCTINH_NEW)
	this->BindObject(eSACHTHUOCTINH_INTERFACE, 31461, 35, 35, -1, -1);  // 31461
#endif



	//==Skin Model
	this->BindObject(eWindow_SkinModelNext, 0x7903, 25, 40, -1, -1);
	this->BindObject(eWindow_SkinModelPREV, 0x7904, 25, 40, -1, -1);
	SetCompleteHook(0xFF, 0x00633FFB, &this->LoadModels);	//===cái này nếu có rồi thì ko cần thêm

	SetRange((LPVOID)0x00842086, 5, ASM::NOP);
	SetRange((LPVOID)0x0084234F, 5, ASM::NOP);
	SetRange((LPVOID)0x008423C3, 5, ASM::NOP);
	SetOp((LPVOID)oLoadSomeForm_Call, this->LoadImages, ASM::CALL);
	SetOp((LPVOID)oDrawInterface_Call, this->Work, ASM::CALL);

	if(gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		SetRange((LPVOID)0x00835116, 5, ASM::NOP);
		SetOp((LPVOID)0x00835116, this->DrawZenAndRud, ASM::CALL);
	}




	//SetRange((LPVOID)0x00835116, 5, ASM::NOP);
	//SetOp((LPVOID)0x00835116, this->DrawZenAndRud, ASM::CALL);


	
}
void Interface::NewLoadInterface()
{

	gHuyHieuCuongHoa.DrawHuyHieu();

}
//#include "NewUIMyInventory.h"

void Interface::DrawZenAndRud(int a1, int a2, int a3, int a4)
{

	int v10;
	int v11;
	DWORD v23;
	v10 = *(DWORD*)(a1 + 40);
	v11 = *(DWORD*)(a1 + 36);
	v23 = *(DWORD*)(*(DWORD*)0x8128AC4 + 5956);
	*(float*)(0x00D24E88); //Width
	char Precio[50];



	char MoneyBuff1[50], MoneyBuff2[50], MoneyBuff3[50], MoneyBuff4[50], test[50];
	ZeroMemory(MoneyBuff1, sizeof(MoneyBuff1));
	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
	ZeroMemory(MoneyBuff3, sizeof(MoneyBuff3));
	ZeroMemory(MoneyBuff4, sizeof(MoneyBuff4));

	pGetMoneyFormat(v23, MoneyBuff1, 0);
	pGetMoneyFormat(Coin3, MoneyBuff2, 0);
	pGetMoneyFormat(Coin1, MoneyBuff3, 0);
	pGetMoneyFormat(Coin2, MoneyBuff4, 0);

	gInterface.DrawFormat(eWhite, v11, v10 + 12, 190, 3, pGetTextLine(pTextLineThis, 223));
	//--
	gInterface.DrawGUI(eMoney1, v11 + 18, v10 + 365);
	gInterface.DrawFormat(eWhite, v11 + 18, v10 + 367, 20, 1, "Zen");
	gInterface.DrawFormat(eRed, v11 + 40, v10 + 367, 50, 3, "%s", MoneyBuff1);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 102, v10 + 365);
	gInterface.DrawFormat(eWhite, v11 + 98, v10 + 367, 20, 1, "WCG");
	gInterface.DrawFormat(eWhite, v11 + 128, v10 + 367, 45, 4, "%s", MoneyBuff2);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 18, v10 + 378);
	gInterface.DrawFormat(eWhite, v11 + 17, v10 + 380, 20, 1, "WC");
	gInterface.DrawFormat(eGold, v11 + 38, v10 + 381, 50, 4, "%s", MoneyBuff3);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 102, v10 + 378);
	gInterface.DrawFormat(eWhite, v11 + 98, v10 + 380, 20, 1, "WCP");
	gInterface.DrawFormat(eBlue, v11 + 128, v10 + 381, 45, 4, "%s", MoneyBuff4);

	float Solarx;

	float MainWidth = 200.0;
	float MainHeight = 180.0;
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

	if (gProtect.m_MainInfo.CustomInterfaceType == 0)
	{
		if (gInterface.CheckWindow(Character))
		{
			Solarx = StartX - 190;
		}
		else
		{
			Solarx = StartX;
		}
	}
	else
	{
		Solarx = StartX;
	}

	if (gInterface.CheckWindow(Inventory))
	{
		if (gProtect.m_MainInfo.CustomInterfaceType == 0)
		{
			if (gHuyHieuCuongHoa.huyhieu >= 1)
			{
				pDrawGUI(59990, Solarx + 347, StartY - 37, 22, 22);
			}
			else
			{
				pDrawGUI(59999, Solarx + 347, StartY - 37, 22, 22);
			}
		}
		else if (gProtect.m_MainInfo.CustomInterfaceType == 0)
		{
			if (gHuyHieuCuongHoa.huyhieu >= 1)
			{
				pDrawGUI(59990, Solarx + 347, StartY - 37, 22, 22);
			}
			else
			{
				pDrawGUI(59999, Solarx + 347, StartY - 37, 22, 22);
			}
		}

	}
}


//void Interface::DrawZenAndRud(int a1, int a2, int a3, int a4)
//{
//	int v10;
//	int v11;
//	DWORD v23;
//	v10 = *(DWORD*)(a1 + 40);
//	v11 = *(DWORD*)(a1 + 36);
//	v23 = *(DWORD*)(*(DWORD*)0x8128AC4 + 5956);
//	*(float*)(0x00D24E88); //Width
//
//	char MoneyBuff1[50], MoneyBuff2[50], MoneyBuff3[50], MoneyBuff4[50], test[50];
//	ZeroMemory(MoneyBuff1, sizeof(MoneyBuff1));
//	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
//	ZeroMemory(MoneyBuff3, sizeof(MoneyBuff3));
//	ZeroMemory(MoneyBuff4, sizeof(MoneyBuff4));
//
//	pGetMoneyFormat(v23, MoneyBuff1, 0);
//	pGetMoneyFormat(Coin3, MoneyBuff2, 0);
//	pGetMoneyFormat(Coin1, MoneyBuff3, 0);
//	pGetMoneyFormat(Coin2, MoneyBuff4, 0);
//
//	gInterface.DrawFormat(eWhite, v11, v10 + 12, 190, 3, pGetTextLine(pTextLineThis, 223));
//	//--
//	gInterface.DrawGUI(eMoney1, v11 + 18, v10 + 365);
//	gInterface.DrawFormat(eBlack, v11 + 18, v10 + 367, 20, 1, "Zen");
//	gInterface.DrawFormat(eRed, v11 + 40, v10 + 367, 50, 3, "%s", MoneyBuff1);
//	//--
//	gInterface.DrawGUI(eMoney2, v11 + 102, v10 + 365);
//	gInterface.DrawFormat(eBlack, v11 + 102, v10 + 367, 20, 1, "GP");
//	gInterface.DrawFormat(eWhite, v11 + 128, v10 + 367, 45, 4, "%s", MoneyBuff2);
//	//--
//	gInterface.DrawGUI(eMoney2, v11 + 18, v10 + 378);
//	gInterface.DrawFormat(eBlack, v11 + 17, v10 + 380, 20, 1, "WC");
//	gInterface.DrawFormat(eGold, v11 + 38, v10 + 381, 50, 4, "%s", MoneyBuff3);
//	//--
//	gInterface.DrawGUI(eMoney2, v11 + 102, v10 + 378);
//	gInterface.DrawFormat(eBlack, v11 + 98, v10 + 380, 20, 1, "WCP");
//	gInterface.DrawFormat(eBlue, v11 + 128, v10 + 381, 45, 4, "%s", MoneyBuff4);
//}



void Interface::LoadModels()
{
	pLoadModel(406, "Data\\Custom\\Bmd\\VIP1\\", "musign", -1);
	pLoadTexture(406, "Custom\\Bmd\\VIP1\\", 0x2901, 0x2600, 1);
	pLoadModel(407, "Data\\Custom\\Bmd\\VIP2\\", "musign", -1);
	pLoadTexture(407, "Custom\\Bmd\\VIP2\\", 0x2901, 0x2600, 1);
	pLoadModel(408, "Data\\Custom\\Bmd\\VIP3\\", "musign", -1);
	pLoadTexture(408, "Custom\\Bmd\\VIP3\\", 0x2901, 0x2600, 1);
	// ----
	//===Test Load SKin
	gInterface.SelectInfoSkin = false;

	pLoadModel(2000 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "bann", -1);
	pLoadTexture(2000 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);

	pLoadModel(2001 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Jack", -1);
	pLoadTexture(2001 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);

	pLoadModel(2002 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "trans_skeleton", -1);
	pLoadTexture(2002 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);

	pLoadModel(2003 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "santa", -1);
	pLoadTexture(2003 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);

	pLoadModel(2004 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Teste", -1);
	pLoadTexture(2004 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);

	//== Phần này load Model SKin bmd, thêm thì cứ đổi số 2005 thành 2006>> (số này trùng với config ở CustomModel.xml)
	pLoadModel(2005 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Luffy", -1);
	pLoadTexture(2005 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);

	//== Them SKin
	pLoadModel(2006 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith01", -1); //Ten File BMD SKin
	pLoadTexture(2006 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2007 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith02", -1); //Ten File BMD SKin
	pLoadTexture(2007 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2008 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith03", -1); //Ten File BMD SKin
	pLoadTexture(2008 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2009 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith04", -1); //Ten File BMD SKin
	pLoadTexture(2009 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2010 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith05", -1); //Ten File BMD SKin
	pLoadTexture(2010 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2011 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith06", -1); //Ten File BMD SKin
	pLoadTexture(2011 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2012 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith07", -1); //Ten File BMD SKin
	pLoadTexture(2012 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2013 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith08", -1); //Ten File BMD SKin
	pLoadTexture(2013 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2014 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith09", -1); //Ten File BMD SKin
	pLoadTexture(2014 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2015 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "yasou", -1); //Ten File BMD SKin
	pLoadTexture(2015 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2016 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "LeeSin", -1); //Ten File BMD SKin
	pLoadTexture(2016 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2017 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith12", -1); //Ten File BMD SKin
	pLoadTexture(2017 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2018 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith13", -1); //Ten File BMD SKin
	pLoadTexture(2018 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2019 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith14", -1); //Ten File BMD SKin
	pLoadTexture(2019 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2020 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith15", -1); //Ten File BMD SKin
	pLoadTexture(2020 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2021 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith16", -1); //Ten File BMD SKin
	pLoadTexture(2021 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	
	pLoadModel(2022 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith17", -1); //Ten File BMD SKin
	pLoadTexture(2022 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);


	pLoadModel(2023 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith18", -1); //Ten File BMD SKin
	pLoadTexture(2023 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);


	pLoadModel(2024 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith19", -1); //Ten File BMD SKin
	pLoadTexture(2024 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);


	pLoadModel(2025 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith20", -1); //Ten File BMD SKin
	pLoadTexture(2025 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2026 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith21", -1); //Ten File BMD SKin
	pLoadTexture(2026 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2027 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith22", -1); //Ten File BMD SKin
	pLoadTexture(2027 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2028 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith23", -1); //Ten File BMD SKin
	pLoadTexture(2028 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2029 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith24", -1); //Ten File BMD SKin
	pLoadTexture(2029 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2030 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith25", -1); //Ten File BMD SKin
	pLoadTexture(2030 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	pLoadModel(2031 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Smith26", -1); //Ten File BMD SKin
	pLoadTexture(2031 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
	

	//----
	pInitModelData2();
}

int Interface::LoadImg(char * Folder, DWORD ID){
	return pLoadImage(Folder, ID, GL_LINEAR, GL_CLAMP, 1, 0);
}


void Interface::LoadImages()
{

	if(gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		pLoadImage("Custom\\Interface\\Money\\item_money.tga", 0x7909, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\Money\\item_money2.tga", 0x7910, 0x2601, 0x2901, 1, 0);
	}


	
	//
	pLoadImage("Custom\\Interface\\Rank01.tga", 0x7880, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank02.tga", 0x7881, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank03.tga", 0x7882, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank04.tga", 0x7883, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank05.tga", 0x7884, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank06.tga", 0x7885, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank07.tga", 0x7886, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank08.tga", 0x7887, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank09.tga", 0x7888, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank10.tga", 0x7889, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank11.tga", 0x7890, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank12.tga", 0x7891, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank13.tga", 0x7892, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank14.tga", 0x7893, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank15.tga", 0x7894, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank16.tga", 0x7895, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank17.tga", 0x7896, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank18.tga", 0x7897, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank19.tga", 0x7898, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank20.tga", 0x7899, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank21.tga", 0x7900, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank22.tga", 0x7901, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Ranking.tga", 0x7902, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Next.tga", 0x7903, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Previous.tga", 0x7904, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\MU-logo.tga", 0x7905, 0x2601, 0x2901, 1, 0);
	
	

	//--
	pLoadImage("Custom\\VipTaiKhoan\\vip1.tga", 32891, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\VipTaiKhoan\\vip2.tga", 32893, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\VipTaiKhoan\\vip3.tga", 32895, 0x2601, 0x2900, 1, 0);



#if(NUT_TINH_NANG)
	LoadBitmapA("Custom\\Interface\\Nut.tga", 61535, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Nut_80_25.tga", 0x313A, 0x2601, 0x2900, 1, 0); // NÚT BUTTON
	pLoadImage("Custom\\Interface\\Khung.tga", 0x9331, 0x2601, 0x2900, 1, 0); // NÚT BUTTON
#endif

#if(PARTYSEARCH==1)
	gInterface.LoadImg("Custom\\Interface\\PartySearch_Title.tga", 0x7E98);
	gInterface.LoadImg("Custom\\Interface\\Info_Block.tga", 0x7E99);
#endif

	pLoadImage("Custom\\Interface\\BXH.tga", 0x9332, 0x2601, 0x2900, 1, 0); // NÚT BUTTON
	pLoadImage("Custom\\Interface\\bg500.tga", 0x9333, 0x2601, 0x2900, 1, 0); // NÚT BUTTON




	gInterface.ChoLoadImage = true;


	switch(gProtect.m_MainInfo.CustomInterfaceType) 
	{
	case 1:
	case 2:
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Item_Back01.tga", 61522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\DragonRight.tga", 2336, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\DragonLeft.tga", 2337, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		if(gProtect.m_MainInfo.CustomInterfaceType == 1)
		{
			LoadBitmapA("Custom\\InterfaceS2\\Menu_left97.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0); //replace
			LoadBitmapA("Custom\\Interface\\none.tga", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		}else
		{
			LoadBitmapA("Custom\\InterfaceS2\\Menu_left.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0); //replace
			LoadBitmapA("Custom\\InterfaceS2\\Menu_SD.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		}
		
		LoadBitmapA("Custom\\InterfaceS2\\Menu_right.jpg", 31294, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_middle.jpg", 31293, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Red.jpg", 0x7A42, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Green.jpg", 0x7A41, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Blue.jpg", 0x7A40, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_AG.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_fastmenu.jpg", iNewFastMenu, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Inventory.jpg", iNewInventory, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Character.jpg", iNewCharacter, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Party.jpg", iNewParty, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_friend.jpg", iNewWinpush, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_guild.jpg", iNewGuild, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\skillboxR.jpg", 0x700003, 0x2601, 0x2901, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill.jpg", 31308, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill2.jpg", 31309, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill3.jpg", 31311, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_command.jpg", 31310, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill.jpg", 31314, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill2.jpg", 31315, GL_LINEAR, GL_CLAMP, 1, 0); 
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill3.jpg", 31317, GL_LINEAR, GL_CLAMP, 1, 0); 
		//--
		LoadBitmapA("Custom\\InterfaceS2\\newui_skillbox.jpg", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skillbox2.jpg", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		//Interface Character
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Stats.jpg", 31352, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\StatsDL.jpg", 51291, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Stats2.jpg", 51292, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Level_box.jpg", 35353, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Level_button.jpg", 51290, GL_LINEAR, GL_CLAMP, 1, 0);
		//-- chat
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_vframe.jpg", 51551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe.tga", 51552, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_up.jpg", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_m.jpg", 51554, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_down.jpg", 51555, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_hframe.jpg", 31275, 9729, 10496, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue1.tga", 51530, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue2.tga", 51531, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue2_1.jpg", 51532, GL_LINEAR, GL_CLAMP, 1, 0);
		break;
	case 3:
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I1.tga", 61522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I2.tga", 61523, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I3.tga", 61524, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Frame_I3.tga", 61526, GL_LINEAR, GL_CLAMP, 1, 0); //-- All Window
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I4.tga", 61527, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Draw_money.tga", 61528, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\button_close.tga", 61529, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I1.tga", 61532, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_chainfo_btn_level.tga", 61533, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ButtonCharacterInfo.tga", 61535, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I2.tga", 61538, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I1.tga", 61539, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I2.tga", 61540, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I1.tga", 61541, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newSytemButton.tga", 61542, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I2.tga", 61543, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\StoreFrame_I1.tga", 61544, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\Main_IE.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_IE_Exp.tga", 59000, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I1.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I4.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I5.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_skillbox.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Interface\\GFx\\ex700\\guege_mp.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_mp_1.tga", 51501, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp_green.tga", 31297, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp_1.tga", 51502, GL_LINEAR, GL_CLAMP, 1, 0);
		goto LOAD_GFX;
	case 4:
		LoadBitmapA("Interface\\GFx\\Legends\\Main_IE.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_I3.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_mp.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_mp_1.tga", 51501, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp_green.tga", 31297, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp_1.tga", 51502, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Interface\\GFx\\Legends\\Main_I5.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_I4.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\Legends\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\newui_skillbox.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);
LOAD_GFX:
		LoadBitmapA("Interface\\GFx\\Buttom_empty_small.tga", 61525, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\newui_number1.tga", 6829, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg01.tga", 61550, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg02.tga", 61551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg03.tga", 61534, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Chat_I5.tga", 61548, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\newui_chat_back.tga", 61549, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Main_IE_Buttons.tga", 0x901, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\skill_render.tga", 61546, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\item_pbtnbg.tga", 61547, GL_LINEAR, GL_CLAMP, 1, 0);
		//-- Folder MacroUI
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Main.tga", 51550, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BSetup.tga", 51546, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BStart.tga", 51547, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Stop.tga", 51548, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Bar.jpg", 51549, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Menu.tga", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
		
#if(CAMERA)	
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BCamera.tga", 51556, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BReset.tga", 51557, GL_LINEAR, GL_CLAMP, 1, 0);
#endif
		//-- Botones del Main
		LoadBitmapA("Custom\\Interface\\none.tga", 31303, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31304, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31305, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31306, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31307, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\Interface\\none.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31294, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31292, GL_LINEAR, GL_CLAMP, 1, 0);
		break;
	}
	LoadBitmapA("Custom\\Interface\\TimeBar.tga", 0x787F, 0x2601, 0x2901, 1, 0);
	//LoadBitmapA("Custom\\Interface\\TimeBarS6.tga", 0x787E, 0x2601, 0x2901, 1, 0);
	LoadBitmapA("Custom\\Interface\\TimeBarS6.tga", 0x787F, GL_LINEAR, GL_CLAMP, 1, 0);

	if( gProtect.m_MainInfo.DisableEffectRemake == 0 )
	{
		pLoadImage("Effect\\flare01.jpg", 52002, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flareRed.jpg", 52230, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\JointLaser01.jpg", 52224, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\hikorora.jpg", 52379, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flareBlue.jpg", 52229, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\bostar3_R.jpg", 32614, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\line_of_big_R.jpg", 32772, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flare01.jpg", 42134, GL_LINEAR, GL_REPEAT, 1, 0);
	}

	//--
	#if(NOTICE_MES==1)
			pDrawMessage ( Notice_1, 1 );
			pDrawMessage ( Notice_2, 0 ); // chữ vàng
			//pDrawMessage ( Notice_2, 1 ); chữ xanh
	#endif

			

	pLoadSomeForm();
}




void Interface::WindowsKG(){
	if (gProtect.m_MainInfo.CustomInterfaceType >= 0){
		char interaltas[500];
		if (gInterface.validar == 0){
			if (gInterface.ultimo_Ping > 0){
				sprintf_s(interaltas, sizeof(interaltas), " %s || Player: %s || Level: %d || Reset: %d || WCoinnC: %d || || WCoinnP: %d || WCoinnG: %d", gProtect.m_MainInfo.WindowName, gObjUser.lpPlayer->Name, gObjUser.lpPlayer->Level, ViewReset, Coin1, Coin2, Coin3);
			}
			else{
				sprintf_s(interaltas, sizeof(interaltas), " %s || Player: %s || Level: %d || Reset: %d || WCoinnC: %d || WCoinnP: %d || WCoinnG: %d", gProtect.m_MainInfo.WindowName, gObjUser.lpPlayer->Name, gObjUser.lpPlayer->Level, ViewReset, Coin1, Coin2, Coin3);
			}
			SetWindowText(pGameWindow, interaltas);
		}
	}
}


void Interface::BindObject(short MonsterID, DWORD ModelID, float Width, float Height, float X, float Y)
{
	this->Data[MonsterID].EventTick	= 0;
	this->Data[MonsterID].OnClick	= false;
	this->Data[MonsterID].OnShow	= false;
	this->Data[MonsterID].ModelID	= ModelID;
	this->Data[MonsterID].Width		= Width;
	this->Data[MonsterID].Height	= Height;
	this->Data[MonsterID].X			= X;
	this->Data[MonsterID].Y			= Y;
	this->Data[MonsterID].MaxX		= X + Width;
	this->Data[MonsterID].MaxY		= Y + Height;
	this->Data[MonsterID].Attribute	= 0;
}

void Interface::DrawGUI(short ObjectID, float PosX, float PosY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawGUI2(short ObjectID, float PosX, float PosY)
{
	this->Data[ObjectID].X		= PosX;
	this->Data[ObjectID].Y		= PosY;
	this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawGUI3(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X		= PosX;
	this->Data[ObjectID].Y		= PosY;
	this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;

	RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1,0);
}

void Interface::DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1,0);
}






void Interface::ResetDrawIMG(short ObjectID)
{
	if( this->Data[ObjectID].X != -1 || this->Data[ObjectID].Y != -1 )
	{
		this->Data[ObjectID].X		= -1;
		this->Data[ObjectID].Y		= -1;
		this->Data[ObjectID].MaxX	= -1;
		this->Data[ObjectID].MaxY	= -1;
	}
}

bool CacheSkinSet = false;
int NumberSelect = -1;

void SkinModelGetInfo()
{
	XULY_CGPACKET pMsg;
	pMsg.header.set(0xD3, 0x11, sizeof(pMsg));
	pMsg.ThaoTac = gInterface.m_SkinModelData[NumberSelect].SkinIndex; //
	DataSend((LPBYTE)& pMsg, pMsg.header.size);
}

void SkinModelBuyAndReset(int SkinID)
{
	XULY_CGPACKET pMsg;
	pMsg.header.set(0xD3, 0x12, sizeof(pMsg));
	pMsg.ThaoTac = SkinID; //
	DataSend((LPBYTE)& pMsg, pMsg.header.size);
}

void DrawWindowSkinModel()
{
	if (!gInterface.Data[eWindow_SkinModel].OnShow)
	{
		if (CacheSkinSet)
		{
			NumberSelect = -1;
			character.SetChangeSkin(-1);
			CacheSkinSet = false;
		}
		return;
	}
	float CuaSoW = 350.0;
	float CuaSoH = 200.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;

	gCentral.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindow_SkinModel,FALSE, "Hệ Thống Thời Trang");
	character.DrawHero(StartX + (CuaSoW)-170, StartY + 10, 150, 150, oHero1);



	CustomFont.Draw(CustomFont.FontNormal, StartX + 25, StartY + 20 + (25 * 1), 0x0, 0x87CEFA, 100, 15, 0, " ");
	CustomFont.Draw(CustomFont.FontNormal, StartX + 25, StartY + 20 + (25 * 2), 0x0, 0x00F5FF, 100, 15, 0, " ");
	CustomFont.Draw(CustomFont.FontNormal, StartX + 25, StartY + 20 + (25 * 3), 0x0, 0x00FA9A, 100, 15, 0, " ");
	CustomFont.Draw(CustomFont.FontNormal, StartX + 25, StartY + 20 + (25 * 4), 0x0, 0xCAFF70, 100, 15, 0, " ");
	CustomFont.Draw(CustomFont.FontNormal, StartX + 25, StartY + 20 + (25 * 5), 0x0, 0xFF6A6A, 100, 15, 0, " ");
	CustomFont.Draw(CustomFont.FontNormal, StartX + 20, StartY + 20 + (25 * 6), 0x0, 0xed260cff, 130, 15, 0, " ");
	if (gInterface.SelectInfoSkin && NumberSelect != -1)
	{
		CustomFont.Draw(CustomFont.FontNormal, StartX + (CuaSoW)-170, StartY + 50, 0xffffffff, 0x000000C8, 150, 0, 3, "%s", gInterface.m_SkinModelInfoSelect[0].NameSkin);
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 50, 0xffffffff, 0x0, 150, 0, 3, "Giá Mua (WcoinP) : %d", gInterface.m_SkinModelInfoSelect[0].Coin);
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 75, 0xffffffff, 0x0, 150, 0, 3, "Sát Thương: %d", gInterface.m_SkinModelInfoSelect[0].ValueOp[0]);
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 100, 0xffffffff, 0x0, 150, 0, 3, "Phòng Thủ: %d", gInterface.m_SkinModelInfoSelect[0].ValueOp[1]);
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 125, 0xffffffff, 0x0, 150, 0, 3, "Máu: %d", gInterface.m_SkinModelInfoSelect[0].ValueOp[2]);
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 150, 0xffffffff, 0x0, 150, 0, 3, "Mana: %d", gInterface.m_SkinModelInfoSelect[0].ValueOp[3]);
		CustomFont.Draw(CustomFont.FontNormal, StartX + 10, StartY + 175, 0xffffffff, 0x0, 150, 0, 3, "Có thể mua nhiều Trang Phục để sử dụng !");
	}
	else {
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 50, 0xffffffff, 0x0, 150, 0, 3, "Giá Mua (WcoinP) : NULL");
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 75, 0xffffffff, 0x0, 150, 0, 3, "Sát Thương: NULL");
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 100, 0xffffffff, 0x0, 150, 0, 3, "Phòng Thủ: NULL");
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 125, 0xffffffff, 0x0, 150, 0, 3, "Máu: NULL");
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 150, 0xffffffff, 0x0, 150, 0, 3, "Mana: NULL");
		CustomFont.Draw(CustomFont.FontNormal, StartX + 10, StartY + 175, 0xffffffff, 0x0, 150, 0, 3, "Chọn trang phục để hiển thị thông tin !");

	}
	//==Next
	gInterface.DrawGUI(eWindow_SkinModelNext, StartX + (CuaSoW)-40, StartY + 80);
	if (gInterface.IsWorkZone(eWindow_SkinModelNext))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(eWindow_SkinModelNext, gInterface.Data[eWindow_SkinModelNext].X, gInterface.Data[eWindow_SkinModelNext].Y, Color);
		if (GetTickCount() - gInterface.Data[eTIME].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{
				gInterface.Data[eTIME].EventTick = GetTickCount();
				if (NumberSelect < (gInterface.m_SkinModelData.size() - 1) && NumberSelect != -1)
				{
					NumberSelect += 1;
					character.SetChangeSkin(gInterface.m_SkinModelData[NumberSelect].SkinIndex + MODELSKINFIX);
					CacheSkinSet = true;
					SkinModelGetInfo();
				}


			}
		}
	}

	gInterface.DrawGUI(eWindow_SkinModelPREV, StartX + (CuaSoW)-180, StartY + 80);

	if (gInterface.IsWorkZone(eWindow_SkinModelPREV))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(eWindow_SkinModelPREV, gInterface.Data[eWindow_SkinModelPREV].X, gInterface.Data[eWindow_SkinModelPREV].Y, Color);
		if (GetTickCount() - gInterface.Data[eTIME].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{
				//character.SetChangeSkin(-1); //<<<<<
				gInterface.Data[eTIME].EventTick = GetTickCount();
				if (NumberSelect > 0 && NumberSelect != -1)
				{
					NumberSelect -= 1;
					character.SetChangeSkin(gInterface.m_SkinModelData[NumberSelect].SkinIndex + MODELSKINFIX);
					CacheSkinSet = true;
					SkinModelGetInfo();

				}


			}
		}
	}
	CustomFont.Draw(CustomFont.FontNormal, StartX + (CuaSoW)-130, StartY + (CuaSoH - 45), 0xffffffff, 0x0, 75, 0, 3, "%d/%d", NumberSelect + 1, gInterface.m_SkinModelData.size());
	//===BUy
	if (gCentral.gDrawButton(StartX + (CuaSoW)-130, StartY + (CuaSoH - 37), 75, 14, "  ") && (GetTickCount() - gInterface.Data[eWindow_SkinModel].EventTick) > 300)
	{
		SkinModelBuyAndReset(gInterface.m_SkinModelData[NumberSelect].SkinIndex);
	}
	CustomFont.Draw(CustomFont.FontNormal, StartX + (CuaSoW)-130, StartY + (CuaSoH - 32), 0xffffffff, 0x0, 75, 0, 3, (CBGetStatusBuySkin(gInterface.m_SkinModelData[NumberSelect].SkinIndex)) ? "Kích Hoạt" : "Mua Trang Phục");

	//===Huy Kich Hoat
	if (gCentral.gDrawButton(StartX + (CuaSoW)-130, StartY + (CuaSoH - 19), 75, 14, "  ") && (GetTickCount() - gInterface.Data[eWindow_SkinModel].EventTick) > 300)
	{
		SkinModelBuyAndReset(-1);
	}
	CustomFont.Draw(CustomFont.FontNormal, StartX + (CuaSoW)-130, StartY + (CuaSoH - 14), 0xffffffff, 0x0, 75, 0, 3, "Huỷ Kích Hoạt");

	if (NumberSelect == -1 && ((int(__cdecl*)(int)) 0x57D9A0)(oHero1) != 400)
	{
		character.SetChangeSkin(gInterface.m_SkinModelData[0].SkinIndex + MODELSKINFIX);
		NumberSelect = 0;
		SkinModelGetInfo();

	}
}
#if(CHONPHEDOILAP)
void DrawChonPheDaoTacBaoTieu()
{
	if (!gInterface.Data[eWindow_ChonPhe].OnShow)
	{
		return;
	}
	float CuaSoW = 300.0;
	float CuaSoH = 230.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;
	gCentral.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindow_ChonPhe, TRUE, gConfig.Text_DAOTACBAOTIEU[0]);
	

	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);

	RenderBitmap(10004, StartX, StartY, CuaSoW, CuaSoH, 0.0, 0.0, 0.877744, 0.63888, 1, 1, 1.0);
	//RenderImage(31335, StartX+ (CuaSoW/2)-(148/2), StartY+(CuaSoH/2)-(138/2), 148.0, 138.0);
	pGLSwitch();
	EnableAlphaTest(0);

	gCentral.gInfoBox(StartX + 7, StartY +30, CuaSoW-23, 100, 0x00000096, 0, 0);

	HFONT FontTextTMB = CreateFontA(13, Main_Font_Width, 0, 0, 700, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, 0x1, 0, 0, Main_Font_Quality, 0, "Tahoma");
	HFONT FontTextTM = CreateFontA(13, Main_Font_Width, 0, 0, 400, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, 0x1, 0, 0, Main_Font_Quality, 0, "Tahoma");
	float TextStartY = StartY + 43;

	int ct = 0;
	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct++), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, gConfig.Text_DAOTACBAOTIEU[1]);// "❂ Chọn lựa con đường hành tẩu [Đạo Tặc] vs [Bảo Tiêu]"); //
	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct++), 0x00FBFFFF, 0x0, CuaSoW, 0, 1, gConfig.Text_DAOTACBAOTIEU[2]);//"❂ Lưu ý sau khi lựa chọn !!"); //
	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct++), 0xEBFFFBFF, 0x0, CuaSoW, 0, 1, gConfig.Text_DAOTACBAOTIEU[3]);//"• Mỗi nhân vật chỉ được chọn 1 lần "); //
	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct++), 0xEBFFFBFF, 0x0, CuaSoW, 0, 1, gConfig.Text_DAOTACBAOTIEU[4]);//"• Sau khi chọn sẽ hiển thị [Đạo Tặc] ~ [Bảo Tiêu] trên Nhân Vật"); //
	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct++), 0xEBFFFBFF, 0x0, CuaSoW, 0, 1, gConfig.Text_DAOTACBAOTIEU[5]);//"• Khác phe không thể Party"); //
	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct++), 0xEBFFFBFF, 0x0, CuaSoW, 0, 1, gConfig.Text_DAOTACBAOTIEU[6]);//"• Khác phe không thể vào cùng Guild"); //
	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct++), 0xEBFFFBFF, 0x0, CuaSoW, 0, 1, gConfig.Text_DAOTACBAOTIEU[7]);//"• Khác phe PK thoải mái không mang tội"); //

	CustomFont.Draw(FontTextTMB, StartX+10, TextStartY + (12 * ct++)+25, 0xFFFFFFFF, 0xFF950096, CuaSoW-20, 0, 3, gConfig.Text_DAOTACBAOTIEU[8]);//"❂ Chọn Con Đường ❂"); //


	DeleteObject(FontTextTMB);
	DeleteObject(FontTextTM);

	float ChiaRow = (CuaSoW / 2);

	if (gCentral.gDrawButton(StartX + (ChiaRow / 2) - (110 / 2), StartY + (CuaSoH - 55), 110, 14, gConfig.Text_DAOTACBAOTIEU[9]) && (GetTickCount() - gInterface.Data[eWindow_ChonPhe].EventTick) > 300)
	{
		//==Tham Gia Than Ma
		XULY_CGPACKET pMsg;
		pMsg.header.set(0xD3, 0x20, sizeof(pMsg));
		pMsg.ThaoTac = 1;
		DataSend((LPBYTE)& pMsg, pMsg.header.size);
		gInterface.Data[eWindow_ChonPhe].OnShow = false;
	}
	if (gCentral.gDrawButton((StartX + ChiaRow ) + (ChiaRow / 2) - (110 / 2), StartY + (CuaSoH - 55), 110, 14, gConfig.Text_DAOTACBAOTIEU[10]) && (GetTickCount() - gInterface.Data[eWindow_ChonPhe].EventTick) > 300)
	{
		//==Tham Gia Than Ma
		XULY_CGPACKET pMsg;
		pMsg.header.set(0xD3, 0x20, sizeof(pMsg));
		pMsg.ThaoTac = 2;
		DataSend((LPBYTE)& pMsg, pMsg.header.size);
		gInterface.Data[eWindow_ChonPhe].OnShow = false;
	}


	
}
#endif

#if(EVENT_MAPBAOTIEU)
void DrawWindowMoveMapBT()
{
	if (!gInterface.Data[eWindow_NPCMoveMapBT].OnShow)
	{
		if(gInterface.Data[eWindow_NPCMoveMapBT].Attribute != 0) gInterface.Data[eWindow_NPCMoveMapBT].Attribute = 0;
		return;
	}
	//gInterface.Data[eWindow_NPCMoveMapBT].Attribute
	int Select = gInterface.Data[eWindow_NPCMoveMapBT].Attribute;
	if (Select == 0)
	{
		Select = 1; //1 Dao Tac,2 Bao tieu , 3 Chung All
	}
	float CuaSoW = 220.0;
	float CuaSoH = 140.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;
	gCentral.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindow_NPCMoveMapBT, FALSE, "NPC Dịch Chuyển");
	gCentral.gInfoBox(StartX + 7, StartY + 30, CuaSoW - 23, 50, 0x00000096, 0, 0);

	HFONT FontTextTMB = CreateFontA(13, Main_Font_Width, 0, 0, 700, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, 0x1, 0, 0, Main_Font_Quality, 0, "Tahoma");
	HFONT FontTextTM = CreateFontA(13, Main_Font_Width, 0, 0, 400, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, 0x1, 0, 0, Main_Font_Quality, 0, "Tahoma");
	float TextStartY = StartY + 43;

	int ct = 0;
	if (Select < 3)
	{
		CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)), TextStartY + (12 * ct++), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "❂ NPC dịch chuyển đến bản đồ hành tẩu [%s]", gConfig.Text_DAOTACBAOTIEU[8 + Select]);
	}
	else {
		CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)), TextStartY + (12 * ct++), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "❂ NPC dịch chuyển đến bản đồ hành tẩu");
	}
	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)), TextStartY + (12 * ct++), 0x00FBFFFF, 0x0, CuaSoW, 0, 1, "❂ Lưu ý :");
	if (Select < 3)
	{
		CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)), TextStartY + (12 * ct++), 0xEBFFFBFF, 0x0, CuaSoW, 0, 1, "• Bản đồ chỉ dành cho [%s]", gConfig.Text_DAOTACBAOTIEU[8 + Select]);
	}
	else 
	{
		CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)), TextStartY + (12 * ct++), 0xEBFFFBFF, 0x0, CuaSoW, 0, 1, "• Bản đồ dành cho [%s] and [%s] ", gConfig.Text_DAOTACBAOTIEU[9], gConfig.Text_DAOTACBAOTIEU[10]);
	}

	if (gCentral.gDrawButton(StartX + (CuaSoW / 2) - (110 / 2), StartY + (CuaSoH - 40), 110, 14, "Di Chuyển") && (GetTickCount() - gInterface.Data[eWindow_NPCMoveMapBT].EventTick) > 300)
	{
		//==Move Map
		XULY_CGPACKET pMsg;
		pMsg.header.set(0xD3, 0x22, sizeof(pMsg));
		pMsg.ThaoTac = Select;
		DataSend((LPBYTE)& pMsg, pMsg.header.size);
		gInterface.Data[eWindow_NPCMoveMapBT].OnShow = false;

	}

	DeleteObject(FontTextTMB);
	DeleteObject(FontTextTM);
}
#endif

#if(B_HON_HOAN)

CONFIDATA_HONHOAN* GetConfigLvHonHoan(int LvHonHoan)
{
	std::map<int, CONFIDATA_HONHOAN>::iterator it = gInterface.m_DataConfigHonHoan.find(LvHonHoan);

	if (it == gInterface.m_DataConfigHonHoan.end())
	{
		return 0;
	}
	else
	{
		return &it->second;
	}

}
void DrawWindowNangCapHonHoan()
{
	if (!gInterface.Data[eWindow_NangCapHonHoan].OnShow)
	{
		return;
	}
	float CuaSoW = 350.0;
	float CuaSoH = 220.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;

	int LvHonHoan = gCustomRankUser.m_Data[gObjUser.lpViewPlayer->aIndex].m_CapDoHonHoan;

	CONFIDATA_HONHOAN * GetInfoLvHienTai = GetConfigLvHonHoan(LvHonHoan);
	CONFIDATA_HONHOAN * GetInfoLvTiepTheo = GetConfigLvHonHoan(LvHonHoan + 1);

	gCentral.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindow_NangCapHonHoan, FALSE, "Nâng Cấp Hồn Hoàn");
	//===Khung Trai
	gCentral.gInfoBox(StartX + 20, StartY + 30, 120, CuaSoH - 50, 0x00000096, 0, 0);
	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);

	RenderBitmap(eDemoHonHoan, StartX + 30, StartY + 35, 180, 180, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); //Anh Demo
	CustomFont.Draw(CustomFont.FontBold, StartX + 20, StartY + 35, 0xFFDE26FF, 0x0, 125, 0, 3, "❂ [Ảnh Minh Hoạ] khi nâng đủ 6 Cấp ❂");
	//===Info Bo Tro
	CustomFont.Draw(CustomFont.FontBold, StartX + 20, StartY + 35 + 110, 0xFFDE26FF, 0x0, 125, 0, 3, "[Chỉ Số Bổ Trợ Hiện Tại- Cấp %d]", LvHonHoan);
	float TextPlusY = StartY + 145 + 13;
	if (LvHonHoan < 6)
	{
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY, 0x00FF90FF, 0x0, 125, 0, 1, "• Tăng Máu : +%d (*%d)", (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangMau, GetInfoLvTiepTheo->TangMau);
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + 10, 0x00FF90FF, 0x0, 125, 0, 1, "• Tăng SD : +%d (*%d)", (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangSD, GetInfoLvTiepTheo->TangSD);
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + (10 * 2), 0x00FF90FF, 0x0, 125, 0, 1, "• Tăng Sát Thương : +%d (*%d)", (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangST, GetInfoLvTiepTheo->TangST);
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + (10 * 3), 0x00FF90FF, 0x0, 125, 0, 1, "• Tăng Phòng Thủ : +%d (*%d)", (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangPT, GetInfoLvTiepTheo->TangPT);

		CustomFont.Draw(CustomFont.FontBold, StartX + 20, TextPlusY + (10 * 4), 0xC8FF00FF, 0x0, 125, 0, 3, "[Chỉ số * là chỉ số cấp tiếp theo!]");
	}
	else
	{
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY, 0x00FF90FF, 0x0, 125, 0, 1, "• Tăng Máu : +%d", (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangMau);
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + 10, 0x00FF90FF, 0x0, 125, 0, 1, "• Tăng SD : +%d", (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangSD);
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + (10 * 2), 0x00FF90FF, 0x0, 125, 0, 1, "• Tăng Sát Thương : +%d", (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangST);
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + (10 * 3), 0x00FF90FF, 0x0, 125, 0, 1, "• Tăng Phòng Thủ : +%d", (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangPT);
	}

	pGLSwitch();
	EnableAlphaTest(0);
	//==================
	int ct = 0;
	CustomFont.Draw(CustomFont.FontBold, StartX + 160, StartY + 35 + (12 * ct++), 0xC8FF00FF, 0x0, CuaSoW - 170, 0, 1, "❂ Hồn Hoàn giúp gia tăng chỉ số cho Nhân Vật");
	CustomFont.Draw(CustomFont.FontBold, StartX + 160, StartY + 35 + (12 * ct++), 0xC8FF00FF, 0x0, CuaSoW - 170, 0, 1, "❂ Cấp Hồn Hoàn càng cao chỉ số càng cao");
	CustomFont.Draw(CustomFont.FontBold, StartX + 160, StartY + 35 + (12 * ct++), 0xC8FF00FF, 0x0, CuaSoW - 170, 0, 1, "❂ Nhân vật sẽ nhận dược Hiệu Ứng đặc trưng");

	float YUpCapHonHoan = StartY + 35 + (12 * ct) + 15;
	if (LvHonHoan < 6)
	{
		CustomFont.Draw(CustomFont.FontBold, StartX + 160, YUpCapHonHoan, 0xFFDE26FF, 0x0, CuaSoW - 170, 0, 1, "❂ Yêu Cầu Nâng Lên Cấp %d:", LvHonHoan + 1);
		CustomFont.Draw(CustomFont.FontBold, StartX + 160 + 30, YUpCapHonHoan + 13, 0x1FD2FFFF, 0x0, CuaSoW - 140, 0, 1, "• x%d %s", GetInfoLvTiepTheo->YCItemSL, GetItemName(GetInfoLvTiepTheo->YCItemID, GetInfoLvTiepTheo->YCItemLv));
		CustomFont.Draw(CustomFont.FontBold, StartX + 160 + 30, YUpCapHonHoan + 13 + (12 * 1), 0x1FD2FFFF, 0x0, CuaSoW - 140, 0, 1, "• x%d WC", GetInfoLvTiepTheo->YCWC);
		CustomFont.Draw(CustomFont.FontBold, StartX + 160 + 30, YUpCapHonHoan + 13 + (12 * 2), 0x1FD2FFFF, 0x0, CuaSoW - 140, 0, 1, "• x%d WP", GetInfoLvTiepTheo->YCWP);
		CustomFont.Draw(CustomFont.FontBold, StartX + 160 + 30, YUpCapHonHoan + 13 + (12 * 3), 0x1FD2FFFF, 0x0, CuaSoW - 140, 0, 1, "• x%d GP", GetInfoLvTiepTheo->YCGP);

		CustomFont.Draw(CustomFont.FontBold, StartX + 160, YUpCapHonHoan + 13 + (12 * 4) + 5, 0xFFDE26FF, 0x0, CuaSoW - 170, 0, 1, "❂ Lưu ý: kiểm tra kỹ các yêu cầu !!");

		if (gCentral.gDrawButton((StartX + 150) + ((CuaSoW - 160) / 2) - (110 / 2), StartY + (CuaSoH - 40), 110, 14, "Nâng Cấp") && (GetTickCount() - gInterface.Data[eWindow_NangCapHonHoan].EventTick) > 300)
		{
			//==Thang Cap
			XULY_CGPACKET pMsg;
			pMsg.header.set(0xD3, 0x02, sizeof(pMsg));
			pMsg.ThaoTac = 1;
			DataSend((LPBYTE)& pMsg, pMsg.header.size);

		}
	}
	else
	{
		CustomFont.Draw(CustomFont.FontBold, StartX + 160, YUpCapHonHoan, 0xFFDE26FF, 0x0, CuaSoW - 170, 0, 1, "❂ Hồn Hoàn của bạn đã đạt TỐi ĐA không thể nâng thêm !");
	}
}

#endif


#if(B_BUFF_PHE)

extern int  mDT_CapDo;
extern int  mDT_TongPoint;
extern int  mDT_PointNext;
extern char mDT_Top1Name[11];
extern int  mDT_Top1Point;
//==
extern int  mBT_CapDo;
extern int  mBT_TongPoint;
extern int  mBT_PointNext;
extern char mBT_Top1Name[11];
extern int  mBT_Top1Point;
extern int  mPointUsePhe;
extern int mLvCuongHoaHienTai;

extern std::map<int, CONFIDATA_CUONGHOA> mDataConfigCuongHoa;

CONFIDATA_CUONGHOA* GetConfigCuongHoa(int LvCuongHoa)
{
	std::map<int, CONFIDATA_CUONGHOA>::iterator it = mDataConfigCuongHoa.find(LvCuongHoa);

	if (it == mDataConfigCuongHoa.end())
	{
		return 0;
	}
	else
	{
		return &it->second;
	}

}
void DrawWindowQuanLyBuffPhe()
{
	if (!gInterface.Data[eWindow_QuanLyBuffPhe].OnShow)
	{
		return;
	}
	float CuaSoW = 450.0;
	float CuaSoH = 220.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;

	gCentral.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindow_QuanLyBuffPhe, FALSE, "Quản Lý - Thống Kê Phe");

	CONFIDATA_CUONGHOA* GetInfoCHHienTai = GetConfigCuongHoa(mLvCuongHoaHienTai);
	CONFIDATA_CUONGHOA* GetInfoCHTiepTheo = GetConfigCuongHoa(mLvCuongHoaHienTai + 1);
	float TextX = StartX + 25; //Dao Tac
	float TextX2 = (StartX+CuaSoW)-140; //Bao Tieu
	float TextX3 = StartX + 160; //Giua

	float TextY = StartY + 30;
	float InfoBuffY = TextY + 15 + (10 * 3);
	float InfoChuPheY = (InfoBuffY + (12 * 3)) + 3;

	int MaxCapCH = mDataConfigCuongHoa.size()-1;
	if (MaxCapCH < 0) return;

	//===Khung Trai Dao Tac
	gCentral.gInfoBox(TextX-5, StartY + 30, 120, CuaSoH - 50, 0x00000096, 0, 0);
	CustomFont.Draw(CustomFont.FontBold, TextX-5, StartY + 30, 0xFFFFFFC8, 0xFF0000B3, 127, 0, 3,"Phe [%s]", gConfig.Text_DAOTACBAOTIEU[9]);

	CustomFont.Draw(CustomFont.FontBold, TextX, TextY+12, 0xFFDE26FF, 0x0, 127, 0, 1, "Cấp Độ Phe : Cấp %d", mDT_CapDo);
	CustomFont.Draw(CustomFont.FontBold, TextX, TextY+12+(10*1), 0xFFDE26FF, 0x0, 127, 0, 1, "Tổng Điểm Phe : %s điểm", NumberFormat(mDT_TongPoint));
	if (mDT_PointNext > 0)
	{
		CustomFont.Draw(CustomFont.FontBold, TextX, TextY + 12 + (10 * 2), 0xC8FF00FF, 0x0, CuaSoW - 140, 0, 1, "❂ Đạt %s sẽ lên phe Cấp %d", NumberFormat(mDT_PointNext), mDT_CapDo + 1);
	}
	//CustomFont.Draw(CustomFont.FontBold, TextX-5, InfoBuffY, 0xFFFFFFC8, 0xB8B1AB78, 127, 0, 3, "Chỉ Số Hỗ Trợ Phe [Cấp 2]");
	//CustomFont.Draw(CustomFont.FontBold, TextX, InfoBuffY+(12*1), 0x1FD2FFFF, 0x0, CuaSoW - 140, 0, 1, "• Sát Thương +%d%% ", 40);
	//CustomFont.Draw(CustomFont.FontBold, TextX, InfoBuffY+(12*2), 0x1FD2FFFF, 0x0, CuaSoW - 140, 0, 1, "• Phòng Thủ +%d%% ", 45);

	CustomFont.Draw(CustomFont.FontBold, TextX - 5, InfoBuffY, 0xFFFFFFC8, 0xFF914778, 127, 0, 3, "*Chủ Phe");
	CustomFont.Draw(CustomFont.FontBold, TextX - 5, InfoBuffY+(12*1), 0x47FFF0FF, 0x0, 127, 0, 3, "%s (%s)", mDT_Top1Name, NumberFormat(mDT_Top1Point));
	CustomFont.Draw(CustomFont.FontBold, TextX - 5, InfoBuffY+(12*2), 0xC8FF00FF, 0x0, 127, 0, 3, "(Người cống hiến nhiều nhất Phe)");

	//===Khung Phai BaoTieu
	gCentral.gInfoBox(TextX2 - 5, StartY + 30, 120, CuaSoH - 50, 0x00000096, 0, 0);
	CustomFont.Draw(CustomFont.FontBold, TextX2 - 5, StartY + 30, 0xFFFFFFC8, 0x007DFFB3, 127, 0, 3, "Phe [%s]", gConfig.Text_DAOTACBAOTIEU[10]);

	CustomFont.Draw(CustomFont.FontBold, TextX2, TextY + 12, 0xFFDE26FF, 0x0, 127, 0, 1, "Cấp Độ Phe : Cấp %d", mBT_CapDo);
	CustomFont.Draw(CustomFont.FontBold, TextX2, TextY + 12 + (10 * 1), 0xFFDE26FF, 0x0, 127, 0, 1, "Tổng Điểm Phe : %s điểm", NumberFormat(mBT_TongPoint));
	if (mBT_PointNext > 0)
	{
		CustomFont.Draw(CustomFont.FontBold, TextX2, TextY + 12 + (10 * 2), 0xC8FF00FF, 0x0, CuaSoW - 140, 0, 1, "❂ Đạt %s sẽ lên phe Cấp %d", NumberFormat(mBT_PointNext), mBT_CapDo + 1);
	}
	//CustomFont.Draw(CustomFont.FontBold, TextX2 - 5, InfoBuffY, 0xFFFFFFC8, 0xB8B1AB78, 127, 0, 3, "Chỉ Số Hỗ Trợ Phe [Cấp 1]");
	//CustomFont.Draw(CustomFont.FontBold, TextX2, InfoBuffY + (12 * 1), 0x1FD2FFFF, 0x0, CuaSoW - 140, 0, 1, "• Sát Thương +%d%% ", 25);
	//CustomFont.Draw(CustomFont.FontBold, TextX2, InfoBuffY + (12 * 2), 0x1FD2FFFF, 0x0, CuaSoW - 140, 0, 1, "• Phòng Thủ +%d%% ", 30);

	CustomFont.Draw(CustomFont.FontBold, TextX2 - 5,InfoBuffY, 0xFFFFFFC8, 0xFF914778, 127, 0, 3, "*Chủ Phe");
	CustomFont.Draw(CustomFont.FontBold, TextX2 - 5,InfoBuffY + (12 * 1), 0x47FFF0FF, 0x0, 127, 0, 3, "%s (%s)", mBT_Top1Name, NumberFormat(mBT_Top1Point));
	CustomFont.Draw(CustomFont.FontBold, TextX2 - 5,InfoBuffY + (12 * 2), 0xC8FF00FF, 0x0, 127, 0, 3, "(Người cống hiến nhiều nhất Phe)");

	//===Cuong HOa Ban Than
	float TextY3 = StartY + 40;
	CustomFont.Draw(CustomFont.FontBold, TextX3 - 5, TextY3, 0x000000C8, 0x47FF78B3, 143, 0, 3, "Cường Hoá Bản Thân [%s] Cấp %d", gObjUser.lpViewPlayer->Name, mLvCuongHoaHienTai);
	CustomFont.Draw(CustomFont.FontBold, TextX3 - 5, TextY3 + (10 * 1), 0xC8FF00FF, 0x0, CuaSoW - 170, 0, 1, "❂ Cường Hoá chỉ số Nhân Vật");
	CustomFont.Draw(CustomFont.FontBold, TextX3 - 5, TextY3 + (10 * 2), 0xC8FF00FF, 0x0, CuaSoW - 170, 0, 1, "❂ Nhận được biệt hiệu đặt trưng");
	CustomFont.Draw(CustomFont.FontBold, TextX3 - 5, TextY3 + (10 * 3), 0xC8FF00FF, 0x0, CuaSoW - 170, 0, 1, "❂ Cống hiến thêm điểm cho Phe [%s]", gConfig.Text_DAOTACBAOTIEU[8+ gCustomRankUser.m_Data[gObjUser.lpViewPlayer->aIndex].m_PheDaChon]);
	if (GetInfoCHTiepTheo != 0)
	{
		CustomFont.Draw(CustomFont.FontBold, TextX3 - 5, TextY3 + (10 * 4), 0xC8FF00FF, 0x0, CuaSoW - 170, 0, 1, "❂ Cống hiến > %s sẽ lên Cường Hoá Cấp %d", NumberFormat(GetInfoCHTiepTheo->CongHienYC), GetInfoCHTiepTheo->LvCuongHoa);
	}
	CustomFont.Draw(CustomFont.FontBold, TextX3 - 5, TextY3 + 3 +(10 * 5), 0x000000C8, 0xDCFA1BB3, 143, 0, 3, "Đã Cống Hiến %s (Cấp %d/%d)", NumberFormat(mPointUsePhe), mLvCuongHoaHienTai, MaxCapCH);
	float InfoCHY = TextY3 + 3 + (10 * 5);
	CustomFont.Draw(CustomFont.FontBold, TextX3, InfoCHY+(10*1), 0x1FD2FFFF, 0x0, CuaSoW - 170, 0, 1, "• Tăng Máu +%d ", (GetInfoCHHienTai->TangMau >0 ? GetInfoCHHienTai->TangMau:0));
	CustomFont.Draw(CustomFont.FontBold, TextX3, InfoCHY + (10 * 2), 0x1FD2FFFF, 0x0, CuaSoW - 170, 0, 1, "• Tăng SD +%d ", (GetInfoCHHienTai->TangSD > 0 ? GetInfoCHHienTai->TangSD : 0));
	CustomFont.Draw(CustomFont.FontBold, TextX3, InfoCHY + (10 * 3), 0x1FD2FFFF, 0x0, CuaSoW - 170, 0, 1, "• Tăng Sát Thương +%d ", (GetInfoCHHienTai->TangST > 0 ? GetInfoCHHienTai->TangST : 0));
	CustomFont.Draw(CustomFont.FontBold, TextX3, InfoCHY + (10 * 4), 0x1FD2FFFF, 0x0, CuaSoW - 170, 0, 1, "• Tăng Phòng Thủ +%d ", (GetInfoCHHienTai->TangPT > 0 ? GetInfoCHHienTai->TangPT : 0));
	
	CustomFont.Draw(CustomFont.FontBold, TextX3 - 5, InfoCHY + (10 * 5), 0xFFFFFFC8, 0xB8B1AB78, 143, 0, 3, "• Bạn Đang Có %s Ruud •", NumberFormat(Ruud));

	CustomFont.Draw(CustomFont.FontBold, TextX3, InfoCHY + (10 * 6)+3, 0xFFFFFFC8, 0x0, (143/2), 0, 3, "Điểm Nộp :");
	gCentral.DrawInput(TextX3+ (143 / 2), InfoCHY + (10 * 6)+3, 45.5, 0, 0, gInterface.InputCHBuffPhe, 0x642b19ff, 0x481f12ff, 0xffffffff);
	CustomFont.Draw(CustomFont.FontBold, TextX3, InfoCHY + (10 * 7)+3, 0xFA8B1BFF, 0x0, CuaSoW - 170, 0, 1, "•Nhập số điểm bạn muốn Cống Hiến ");
	if (gInterface.InputCHBuffPhe->value > Ruud)
	{
		gInterface.InputCHBuffPhe->value = Ruud;
	}
	if (gCentral.gDrawButton(TextX3+12, InfoCHY + (10 * 8) + 3, 110, 14, "Nộp Cống Hiến") && (GetTickCount() - gInterface.Data[eWindow_QuanLyBuffPhe].EventTick) > 300)
	{

		XULY_CGPACKET pMsg;
		pMsg.header.set(0xD3, 0x06, sizeof(pMsg));
		pMsg.ThaoTac = (int)gInterface.InputCHBuffPhe->value;
		DataSend((LPBYTE)& pMsg, pMsg.header.size);
		gInterface.InputCHBuffPhe->value = 0; //clear()
	}

}
#endif
#if(CUSTOM_EVENTBOSS_BB)
#include "CustomEventBoss.h"
#include "Character.h"
void Interface::DrawItem3D(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int ExtOption, int Ancient, bool PickUp, float Scale, bool Center)
{
	float x = PosX;
	float y = PosY;

	if (ItemID >= ITEM(0, 0) && ItemID < ITEM(1, 0))
	{
		x = PosX - 10;
		if (ItemID == ITEM(0, 16) || ItemID == ITEM(0, 19)) {
			y = PosY + 30;
			//g_Console.AddMessage(1, "DrawItem3D %d", ItemID);
		}
		else if ((ItemID >= ITEM(0, 32) && ItemID <= ITEM(0, 35)) || gCustomBattleGloves.CheckGloves(ItemID) == true) { y = PosY + 15; }
		else if (ItemID >= ITEM(0, 15) && ItemID < ITEM(0, 32)) { y = PosY + 25; }
		else if (ItemID > ITEM(0, 35)) { y = PosY + 20; }
		else if (ItemID == ITEM(0, 0)) { y = PosY + 30; }
		else { y = PosY + 20; }
	}
	else if (ItemID >= ITEM(3, 0) && ItemID < ITEM(4, 0))
	{
		y = PosY + 30;
	}
	else if (ItemID >= ITEM(7, 0) && ItemID < ITEM(8, 0)) { y = PosY + 25; }
	else if (ItemID >= ITEM(8, 0) && ItemID < ITEM(9, 0))
	{
		if ((ItemID >= ITEM(8, 2) && ItemID <= ITEM(8, 4))
			|| ItemID == ITEM(8, 7) || ItemID == ITEM(8, 8)
			|| ItemID == ITEM(8, 15))
		{
			y = PosY + 20;
		}
		else if (ItemID == ITEM(8, 34) || ItemID == ITEM(8, 35)) { y = PosY + 25; }
		else if (ItemID <= ITEM(8, 73)) { y = PosY + 25; }
		else if (ItemID > ITEM(8, 73)) { y = PosY + 35; }
	}
	else if (ItemID >= ITEM(9, 0) && ItemID < ITEM(12, 0)) { y = PosY + 25; }
	else if (ItemID >= 2048)
	{
		y = PosY + 25;

		if (ItemID == ITEM(12, 40)) { y = PosY + 10; }
	}
	else { y = PosY + 20; }
	PosX = x;
	PosY = y - 25;
	pSetBlend(true);
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();
	sub_6363D0_Addr(0, 0, *(GLsizei*)0x00E61E58, *(GLsizei*)0x00E61E5C);
	float v2 = *(float*)0x00E61E58 / *(float*)0x00E61E5C;
	sub_6358A0_Addr(Scale, v2, *(float*)0xE61E38, *(float*)0xE61E3C);
	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();
	sub_635830_Addr((LPVOID)0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();
	glClear(0x100);
	//gInterface.DrawItem3DCenterImage = Center;

	pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, ExtOption, Ancient, PickUp);
	//gInterface.DrawItem3DCenterImage = false;
	sub_636720_Addr();
	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();
	glColor3f(1, 1, 1);
	pSetBlend(false);
	return;
}

int InfoTypeSelect = 0;
int BossListSelect = 0;
int PageListBoss = 0;
int PageListReward = 0;
void DrawCustomEventBoss()
{
	float ImgEventX = 0;
	float ImgEventY = 110;
	float ImgEventW = 60;
	float ImgEventH = 24;
	RenderBitmap(eImgEventButton, ImgEventX, ImgEventY, ImgEventW, ImgEventH, 0, 0, 0.92, 0.72, 1, 1, 0.0);

	if (pCheckMouseOver(ImgEventX, ImgEventY, ImgEventW, ImgEventH) == 1)
	{
		if (pIsKeyPress(VK_LBUTTON) && GetTickCount() - gInterface.Data[eWindow_CustomEventBoss].EventTick > 300)
		{
			
			PlayBuffer(25, 0, 0);
			gInterface.Data[eWindow_CustomEventBoss].OnShow ^= 1;
			gInterface.Data[eWindow_CustomEventBoss].EventTick = GetTickCount();


		}
		gCentral.LockMouseMoveClick = GetTickCount() + 500;
		pSetCursorFocus = true;
	}
	if (!gInterface.Data[eWindow_CustomEventBoss].OnShow)
	{
		BossListSelect = 0;
		if (PageListBoss > 0) PageListBoss = 0;
		if (PageListReward > 0) PageListReward = 0;
		return;
	}
	float CuaSoW = 350;
	float CuaSoH = 265;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;

	gCentral.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindow_CustomEventBoss, FALSE, "Event Info");
	//===Khung Trai Button Event
	gCentral.gInfoBox(StartX+15, StartY + 30, 60, CuaSoH - 50, 0x00000096, 0, 0);

	float mButtonX = (StartX + 15)+1;
	float mButtonY = (StartY + 30)+2;
	int ECount = 0;
	for (std::map<int, EventGroupData>::iterator it = gCustomEventBoss.m_EventData.begin(); it != gCustomEventBoss.m_EventData.end(); it++)
	{
		if (it->second.Index < 0 || ECount > 9) break;
		if (gCentral.gDrawButton(mButtonX, mButtonY+(ECount * 22), 65,20, 12, it->second.TextButton) && (GetTickCount() - gInterface.Data[eWindow_CustomEventBoss].EventTick) > 300)
		{
			PlayBuffer(25, 0, 0);
			InfoTypeSelect = it->second.Group; //Chon Nhom de Show Info
			BossListSelect = 0;
			if (PageListBoss > 0) PageListBoss = 0;
			if (PageListReward > 0) PageListReward = 0;
		}
		ECount++;
	}
	std::map<int, EventGroupData>::iterator it = gCustomEventBoss.m_EventData.find(InfoTypeSelect);

	if (it != gCustomEventBoss.m_EventData.end())
	{
		//====List Boss 1
		float ListBoss1X = StartX + 15 + 70;
		float ListBoss1Y = StartY + 30;
		gCentral.gInfoBox(ListBoss1X, ListBoss1Y, 80, 156, 0x00000096, 0, 0);
		character.DrawMonster(ListBoss1X + 2, ListBoss1Y + 3, 82, 160, oMonster1+ BossListSelect+(InfoTypeSelect*10), it->second.DataBoss[BossListSelect].IDBoss, it->second.DataBoss[BossListSelect].Size);
		//===Show InfoText
		float InfoTextX = ListBoss1X+90;
		float InfoTextY = ListBoss1Y;

		std::map<int, InfoTextData>::iterator rInfoText = gCustomEventBoss.m_InfoTextData.find(it->second.DataBoss[BossListSelect].TypeInfo);

		if (rInfoText != gCustomEventBoss.m_InfoTextData.end())
		{

			CustomFont.Draw(CustomFont.FontBold, InfoTextX, InfoTextY, 0xFFCC00C8, 0x6B3A1A78, 160, 0, 3, rInfoText->second.InfoTextList[0].Text);
			for (int nText = 1; nText < 6; nText++)
			{
				CustomFont.Draw(CustomFont.FontBold, InfoTextX+5, InfoTextY  +(12*nText), 0xD4BB63C8, 0x0, 0, 0, 1, rInfoText->second.InfoTextList[nText].Text);
			}

			std::map<int, InfoRewardData>::iterator rInfoReward = gCustomEventBoss.m_InfoRewardData.find(it->second.DataBoss[BossListSelect].TypeListItem);
			if (rInfoReward != gCustomEventBoss.m_InfoRewardData.end())
			{
				CustomFont.Draw(CustomFont.FontBold, InfoTextX, InfoTextY + (12 * 6), 0xFFCC00C8, 0x6B3A1A78, 160, 0, 3, "Vật Phẩm Rơi");
				float DrawItemX = InfoTextX + 25;
				float DrawItemY = InfoTextY + (12 * 7) + 15;
				float DrawItemW = 15;
				float DrawItemH = 15;
				int XCount = 0;
				pDrawButton(0x7E56, DrawItemX - 24, DrawItemY-6, 20, 23, 0, 0); //<<<
				if (pCheckMouseOver(DrawItemX - 24, DrawItemY - 6, 20, 23) == 1)
				{
					if (pIsKeyPress(VK_LBUTTON) && GetTickCount() - gInterface.Data[eWindow_CustomEventBoss].EventTick > 300)
					{

						PlayBuffer(25, 0, 0);
						if (PageListReward > 0) PageListReward--;


					}
					pDrawColorButton(0x7E56, DrawItemX - 24, DrawItemY - 6, 20, 23, 0, 0, eGold);
				}
				//===================

				pDrawButton(0x7E57, DrawItemX + (5 * 25)-6, DrawItemY-6, 20, 23, 0, 0); //>>>
				if (pCheckMouseOver(DrawItemX + (5 * 25) - 6, DrawItemY - 6, 20, 23) == 1)
				{
					if (pIsKeyPress(VK_LBUTTON) && GetTickCount() - gInterface.Data[eWindow_CustomEventBoss].EventTick > 300)
					{

						PlayBuffer(25, 0, 0);
						if (PageListReward < 1) PageListReward++;
					}
					pDrawColorButton(0x7E57, DrawItemX + (5 * 25) - 6, DrawItemY - 6, 20, 23, 0, 0, eGold);
				}
				//===================
				for (int nItem = 0; nItem < 5; nItem++)
				{
					if (rInfoReward->second.InfoRewardList[nItem].IndexItem > 0)
					{
						gCentral.gInfoBox((DrawItemX-3) + (XCount * 25), DrawItemY-5, 13, 15, 0xD4966396, 0, 0);
						gInterface.DrawItem3D(DrawItemX + (XCount * 25), DrawItemY, DrawItemW, DrawItemH, rInfoReward->second.InfoRewardList[nItem+(PageListReward*5)].IndexItem, rInfoReward->second.InfoRewardList[nItem+(PageListReward * 5)].Level, 0, 0, 0, rInfoReward->second.InfoRewardList[nItem + (PageListReward * 5)].Scale);
						XCount++;
					}
				}
			}
			//===Button Move
			if (it->second.DataBoss[BossListSelect].GateMove > 0)
			{
				if (gCentral.gDrawButton((InfoTextX + 45), (InfoTextY+130), 65, 20, 12, "Di Chuyển Đến Boss") && (GetTickCount() - gInterface.Data[eWindow_CustomEventBoss].EventTick) > 300)
				{
					PlayBuffer(25, 0, 0);
					//==Move Den Boss
					XULY_CGPACKET pMsg;
					pMsg.header.set(0xD3, 0x4A, sizeof(pMsg));
					pMsg.ThaoTac = it->second.DataBoss[BossListSelect].GateMove;
					DataSend((LPBYTE)& pMsg, pMsg.header.size);
					gInterface.Data[eWindow_CustomEventBoss].OnShow ^= 1;
	
				}
			}
		}

		//==List Bosss 2
		float ListBoss2X = StartX + 15 + 95;
		float ListBoss2Y = StartY + 30 + 170;
		float MouseHover = false;
		pDrawButton(0x7E56, ListBoss2X-22, ListBoss2Y+10, 20, 23, 0, 0); //<<<
		if (pCheckMouseOver(ListBoss2X - 22, ListBoss2Y + 10, 20, 23) == 1)
		{
			if (pIsKeyPress(VK_LBUTTON) && GetTickCount() - gInterface.Data[eWindow_CustomEventBoss].EventTick > 300)
			{

				PlayBuffer(25, 0, 0);
				if (PageListBoss > 0) PageListBoss--;


			}
			pDrawColorButton(0x7E56, ListBoss2X - 22, ListBoss2Y + 10, 20, 23, 0, 0, eGold);
		}
		//===================

		pDrawButton(0x7E57, ListBoss2X + (4 * 51), ListBoss2Y+10, 20, 23, 0, 0); //>>>
		if (pCheckMouseOver(ListBoss2X + (4 * 51), ListBoss2Y + 10, 20, 23) == 1)
		{
			if (pIsKeyPress(VK_LBUTTON) && GetTickCount() - gInterface.Data[eWindow_CustomEventBoss].EventTick > 300)
			{

				PlayBuffer(25, 0, 0);
				if (PageListBoss < 2) PageListBoss++;
			}
			pDrawColorButton(0x7E57, ListBoss2X + (4 * 51), ListBoss2Y + 10, 20, 23, 0, 0, eGold);
		}
		//===================
		for (int n = 0; n < 4; n++)
		{
			if (n + (PageListBoss * 4) > 12) break;
			if (it->second.DataBoss[n].IDBoss > 0)
			{
				if (pCheckMouseOver(ListBoss2X + (n * 51), ListBoss2Y, 40, 40) == 1)
				{
					if (pIsKeyPress(VK_LBUTTON) && GetTickCount() - gInterface.Data[eWindow_CustomEventBoss].EventTick > 300)
					{

						PlayBuffer(25, 0, 0);
						BossListSelect = n + (PageListBoss * 4);
						if (PageListReward > 0) PageListReward = 0;
						//gInterface.DrawMessage(1, "TT %d %d", BossListSelect, it->second.DataBoss[n].IDBoss);

					}
					MouseHover = true;
				}
				else
				{
					MouseHover = false;
				}
				gCentral.gInfoBox(ListBoss2X + (n * 51), ListBoss2Y, 40, 40, (!MouseHover)?0x00000096: 0x00FFB396, 0, 0);
				character.DrawMonster(ListBoss2X + (n * 51) + 2, ListBoss2Y + 3, 42, 40, oMonster1+(n+(PageListBoss*4))+(InfoTypeSelect * 10), it->second.DataBoss[n + (PageListBoss * 4)].IDBoss, it->second.DataBoss[n + (PageListBoss * 4)].Size);

			}
		}
	}

}

#endif

void Interface::Work()
{
#if(EVENT_END_LESS)
	gInterface.EndLessEventWindow();
#endif
#if(CUSTOM_EVENTBOSS_BB)
	DrawCustomEventBoss();
#endif

	//=== Draw WinDow Skin
	DrawWindowSkinModel();

#if(B_BUFF_PHE)
	DrawWindowQuanLyBuffPhe();
#endif

#if(CHONPHEDOILAP)
	DrawChonPheDaoTacBaoTieu();
#endif

#if(EVENT_MAPBAOTIEU)
	DrawWindowMoveMapBT();
#endif

#if(B_HON_HOAN)
	DrawWindowNangCapHonHoan();
#endif
#if(ANTIHACK)	
	//1.hack speed
	if (*(BYTE *)0x004DA3E0 != 40 || *(BYTE *)0x00D2360A != 64 || *(BYTE *)0x00D2360B != 65)
	{
		gMSGCommon.SendHack(1);
		MessageBoxA(NULL, "BQT khuyen ban khong gian lan khi choi game! 1", "[HieuDaiCa]", ERROR);	  //hack speed
		ExitProcess(0);
	}
	//2.HitHack
	if (*(BYTE*)(*(DWORD*)(0x7BC4F04) + 0x397) > 65)
	{
		gMSGCommon.SendHack(2);
		ExitProcess(0);
	}
	if (*(BYTE*)0x005DE171 != 137 || *(BYTE*)0x005DE172 != 138
		|| *(BYTE*)0x005DE173 != 160 || *(BYTE*)0x005DE174 != 0
		|| *(BYTE*)0x005DE175 != 0 || *(BYTE*)0x005DE176 != 0
		|| *(BYTE*)0x005B5FFF != 245 || *(BYTE*)0x005B6000 != 0
		|| *(BYTE*)0x005B6001 != 0 || *(BYTE*)0x005B6002 != 0)
	{
		gMSGCommon.SendHack(2);
		MessageBoxA(NULL, "BQT khuyen ban khong gian lan khi choi game! 2", "[HieuDaiCa]", ERROR);	 //delay hack
		ExitProcess(0);
	}
	//3.XDAME
	if (*(BYTE*)0x005A1797 != 141 || *(BYTE*)0x005A1798 != 212
		|| *(BYTE*)0x005A1799 != 247 || *(BYTE*)0x005A179A != 255
		|| *(BYTE*)0x005A179B != 255
		|| *(BYTE*)0x005AD824 != 141 || *(BYTE*)0x005AD825 != 172 || *(BYTE*)0x005AD826 != 239 || *(BYTE*)0x005AD827 != 255 || *(BYTE*)0x005AD828 != 255
		|| *(BYTE*)0x005AF96D != 141 || *(BYTE*)0x005AF96E != 28 || *(BYTE*)0x005AF96F != 142 || *(BYTE*)0x005AF970 != 255 || *(BYTE*)0x005AF971 != 255
		|| *(BYTE*)0x0059C79D != 141 || *(BYTE*)0x0059C79E != 212 || *(BYTE*)0x0059C79F != 247 || *(BYTE*)0x0059C7A0 != 255 || *(BYTE*)0x0059C7A1 != 255
		|| *(BYTE*)0x005AFBF1 != 141 || *(BYTE*)0x005AFBF2 != 4 || *(BYTE*)0x005AFBF3 != 134 || *(BYTE*)0x005AFBF4 != 255 || *(BYTE*)0x005AFBF5 != 255
		|| *(BYTE*)0x0059CEDC != 141 || *(BYTE*)0x0059CEDD != 228 || *(BYTE*)0x0059CEDE != 247 || *(BYTE*)0x0059CEDF != 255 || *(BYTE*)0x0059CEE0 != 255
		|| *(BYTE*)0x005B1CCB != 141 || *(BYTE*)0x005B1CCC != 4 || *(BYTE*)0x005B1CCD != 151 || *(BYTE*)0x005B1CCE != 255 || *(BYTE*)0x005B1CCF != 255
		|| *(BYTE*)0x005B170A != 141 || *(BYTE*)0x005B170B != 52 || *(BYTE*)0x005B170C != 175 || *(BYTE*)0x005B170D != 255 || *(BYTE*)0x005B170E != 255
		|| *(BYTE*)0x005B0C07 != 141 || *(BYTE*)0x005B0C08 != 124 || *(BYTE*)0x005B0C09 != 207 || *(BYTE*)0x005B0C0A != 255 || *(BYTE*)0x005B0C0B != 255
		|| *(BYTE*)0x005B187C != 141 || *(BYTE*)0x005B187D != 36 || *(BYTE*)0x005B187E != 167 || *(BYTE*)0x005B187F != 255 || *(BYTE*)0x005B1880 != 255
		|| *(BYTE*)0x0059D1E2 != 141 || *(BYTE*)0x0059D1E3 == 144 || *(BYTE*)0x0059D1E4 != 231 || *(BYTE*)0x0059D1E5 != 255 || *(BYTE*)0x0059D1E6 != 255
		|| *(BYTE*)0x005B1AA9 != 141 || *(BYTE*)0x005B1AAA != 20 || *(BYTE*)0x005B1AAB != 159 || *(BYTE*)0x005B1AAC != 255 || *(BYTE*)0x005B1AAD != 255
		|| *(BYTE*)0x005AC554 != 141 || *(BYTE*)0x005AC555 != 116 || *(BYTE*)0x005AC556 != 182 || *(BYTE*)0x005AC557 != 255 || *(BYTE*)0x005AC558 != 255
		|| *(BYTE*)0x0059D6AD != 141 || *(BYTE*)0x0059D6AE != 204 || *(BYTE*)0x0059D6AF != 239 || *(BYTE*)0x0059D6B0 != 255 || *(BYTE*)0x0059D6B1 != 255
		|| *(BYTE*)0x005AC22C != 141 || *(BYTE*)0x005AC22D != 252 || *(BYTE*)0x005AC22E != 190 || *(BYTE*)0x005AC22F != 255 || *(BYTE*)0x005AC230 != 255
		|| *(BYTE*)0x00534FD2 != 141 || *(BYTE*)0x00534FD3 == 144 || *(BYTE*)0x00534FD4 != 247 || *(BYTE*)0x00534FD5 != 255 || *(BYTE*)0x00534FD6 != 255
		|| *(BYTE*)0x0059DED9 != 141 || *(BYTE*)0x0059DEDA == 144 || *(BYTE*)0x0059DEDB != 239 || *(BYTE*)0x0059DEDC != 255 || *(BYTE*)0x0059DEDD != 255
		|| *(BYTE*)0x0059DC87 != 141 || *(BYTE*)0x0059DC88 == 144 || *(BYTE*)0x0059DC89 != 247 || *(BYTE*)0x0059DC8A != 255 || *(BYTE*)0x0059DC8B != 255
		//hetsum
		|| *(BYTE*)0x005B2C98 != 141 || *(BYTE*)0x005B2C99 != 108 || *(BYTE*)0x005B2C9A != 110 || *(BYTE*)0x005B2C9B != 255 || *(BYTE*)0x005B2C9C != 255
		//Rf damdat
		|| *(BYTE*)0x0059F471 != 141 || *(BYTE*)0x0059F472 != 36 || *(BYTE*)0x0059F473 != 191 || *(BYTE*)0x0059F474 != 255 || *(BYTE*)0x0059F475 != 255
		//vatnga
		|| *(BYTE*)0x005AF96D != 141 || *(BYTE*)0x005AF96E == 144 || *(BYTE*)0x005AF96F == 144 || *(BYTE*)0x005AF970 != 255 || *(BYTE*)0x005AF971 != 255
		//AALH1
		|| *(BYTE*)0x0059F211 != 141 || *(BYTE*)0x0059F212 != 68 || *(BYTE*)0x0059F213 != 199 || *(BYTE*)0x0059F214 != 255 || *(BYTE*)0x0059F215 != 255

		|| *(BYTE*)0x0050FB50 != 141 || *(BYTE*)0x0050FB51 == 90 || *(BYTE*)0x0050FB52 != 247 || *(BYTE*)0x0050FB53 != 255 || *(BYTE*)0x0050FB54 != 255
		//manhlong		
		|| *(BYTE*)0x0050F357 != 141 || *(BYTE*)0x0050F358 != 180 || *(BYTE*)0x0050F359 != 239 || *(BYTE*)0x0050F35A != 255 || *(BYTE*)0x0050F35B != 255

		//MG
		|| *(BYTE*)0x005ADE26 != 141 || *(BYTE*)0x005ADE27 != 116 || *(BYTE*)0x005ADE28 != 223 || *(BYTE*)0x005ADE29 != 255 || *(BYTE*)0x005ADE2A != 255
		|| *(BYTE*)0x005ADACC != 141 || *(BYTE*)0x005ADACD != 140 || *(BYTE*)0x005ADACE != 231 || *(BYTE*)0x005ADACF != 255 || *(BYTE*)0x005ADAD0 != 255
		|| *(BYTE*)0x005AE854 != 141 || *(BYTE*)0x005AE855 != 188 || *(BYTE*)0x005AE856 != 206 || *(BYTE*)0x005AE857 != 255 || *(BYTE*)0x005AE858 != 255
		//DL
		|| *(BYTE*)0x005AF1B1 != 141 || *(BYTE*)0x005AF1B2 != 92 || *(BYTE*)0x005AF1B3 != 166 || *(BYTE*)0x005AF1B4 != 255 || *(BYTE*)0x005AF1B5 != 255
		|| *(BYTE*)0x005AE1B5 != 141 || *(BYTE*)0x005AE1B6 != 236 || *(BYTE*)0x005AE1B7 != 214 || *(BYTE*)0x005AE1B8 != 255 || *(BYTE*)0x005AE1B9 != 255
		//saitama
		|| *(BYTE*)0x0064CF51 != 51 || *(BYTE*)0x0064CF52 != 1 || *(BYTE*)0x0064CF53 != 0 || *(BYTE*)0x0064CF54 != 0)

	{
		gMSGCommon.SendHack(3);
		MessageBoxA(NULL, "BQT khuyen ban khong gian lan khi choi game! 3", "[HieuDaiCa]", ERROR);	 //Xdame
		ExitProcess(0);
	}
	//4.Chay Nhanh
	if (*(BYTE*)0x00564D30 == 233)
	{
		gMSGCommon.SendHack(4);
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 4", "[HieuDaiCa]", ERROR);	 //cahy nhanh
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//5.Lenh Dance(Hack kill ko taget)
	if (*(BYTE*)(*(DWORD*)(0x7BC4F04) + 0x397) > 65)// loi khi su dung /Dance
	{
		gMSGCommon.SendHack(5);
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 5", "[HieuDaiCa]", ERROR);	 //hithack ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//6-7.Hack khang hieu ung
	if ((*(BYTE*)0x006407C0 == 195)		//khang day lui ok
		|| (*(BYTE*)0x005528A0 == 195)	//khang sat thuong ok
		|| (*(BYTE*)0x00749A30 == 195)		//khang sat thuong ok
		|| (*(BYTE*)0x004C8F00 == 195)	// khang hieu ung x?u ok
		|| (*(BYTE*)0x00596500 == 195)	// Xoa hoi chieu va noi luc
		|| (*(BYTE*)0x0057D760 == 195))	//khangtele dw ok
	{
		gMSGCommon.SendHack(6);
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 6", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0"); mo cai nay ra la xap nguon khi hack vao cai nay
		ExitProcess(0);
	}


	if ((*(BYTE*)0x006407C0 != 85)		//khang day lui ok
		|| (*(BYTE*)0x005528A0 != 85)	//khang sat thuong ok
		|| (*(BYTE*)0x00749A30 != 236)		//khang sat thuong ok
		|| (*(BYTE*)0x004C8F00 != 85)	// khang hieu ung x?u ok
		|| (*(BYTE*)0x00596500 != 85)	// Xoa hoi chieu va noi luc
		|| (*(BYTE*)0x0057D760 != 85))	//khangtele dw ok
	{
		gMSGCommon.SendHack(7);
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 7", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//8.Evil x Evil
	if (*(BYTE*)0x0073A641 != 91 || *(BYTE*)0x0055D515 == 100 || *(BYTE*)0x0055D515 != 4)
	{
		gMSGCommon.SendHack(8);
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 8", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//9.AALH

	if (*(DWORD*)0x0054539E == 1166749052 || *(DWORD*)0x00545248 == 1300967031
		|| *(BYTE*)0x0054539E == 118 || *(BYTE*)0x0054539E == 124
		|| *(BYTE*)0x00545248 == 117 || *(BYTE*)0x00545248 == 119
		|| *(BYTE*)0x00545248 == 123 || *(BYTE*)0x0054539E != 117
		|| *(BYTE*)0x00545248 != 122 || *(BYTE*)0x005B5FFA == 233)
	{
		gMSGCommon.SendHack(9);
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 9", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//10.Skill trong thanh
	if (*(BYTE*)0x00561746 == 0 || *(BYTE*)0x00561746 != 1)
	{
		gMSGCommon.SendHack(10);
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 10", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//11.GodMode
	if (*(BYTE*)0x0065FC76 == 235 || *(BYTE*)0x0065FC76 != 117)
	{
		gMSGCommon.SendHack(11);
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 11", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//12.Delay cuoi soi
	if (*(BYTE*)0x005DE16C != 102)
	{
		gMSGCommon.SendHack(12);
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 12", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//13.xdame skill
	if ((*(BYTE*)*(DWORD*)0x5B1705 == 10)			//quayrong
		|| (*(BYTE*)*(DWORD*)0x5A1792 == 10)		//danh thuong Dk
		|| (*(BYTE*)*(DWORD*)0x5AD81F == 10)		//xoay kiem
		|| (*(BYTE*)*(DWORD*)0x59C798 == 10)
		//----DW
		|| (*(BYTE*)*(DWORD*)0x59CED7 == 10)		//skill don
		|| (*(BYTE*)*(DWORD*)0x5B1CC6 == 10)		//muabangtuyet
		|| (*(BYTE*)*(DWORD*)0x5B0C02 == 10)		//Lua Dia Nguc
		|| (*(BYTE*)*(DWORD*)0x59D1DD == 10)		//muasaobang
		|| (*(BYTE*)*(DWORD*)0x5B1877 == 10)		//Kame
		|| (*(BYTE*)*(DWORD*)0x5B05C6 == 10)		//Nova
		|| (*(BYTE*)*(DWORD*)0x5B071D == 10)		//Nova1
		|| (*(BYTE*)*(DWORD*)0x5B1AA4 == 10)		//Cot lua
		//-------EFL
		|| (*(BYTE*)*(DWORD*)0x5AC54F == 10)		//Ngu Tien
		|| (*(BYTE*)*(DWORD*)0x59D6A8 == 10)		//Ban bang
		|| (*(BYTE*)*(DWORD*)0x5AC227 == 10)		//Buff mau
		//--------SUM
		|| (*(BYTE*)*(DWORD*)0x534FCD == 10)		//Skill sach
		|| (*(BYTE*)*(DWORD*)0x59DED4 == 10)		//Giat Set
		|| (*(BYTE*)*(DWORD*)0x59DC82 == 10)		//Hut Mau
		|| (*(BYTE*)*(DWORD*)0x5B2C93 == 10)		//Shok Dien
		//--------RF
		|| (*(BYTE*)*(DWORD*)0x59F46C == 10)		//D?m ??t
		|| (*(BYTE*)*(DWORD*)0x59F20C == 10)		//AALH
		//--------MG
		|| (*(BYTE*)*(DWORD*)0x5ADE21 == 10)		//Cú chém
		|| (*(BYTE*)*(DWORD*)0x5ADAC7 == 10)		//Chem Lua
		|| (*(BYTE*)*(DWORD*)0x5AE84F == 10)		//Hoa Diem
		//--------DL
		|| (*(BYTE*)*(DWORD*)0x59C798 == 10)		//Quat xich
		|| (*(BYTE*)*(DWORD*)0x5AF1AC == 10)		//Hoa Am
		|| (*(BYTE*)*(DWORD*)0x5AE1B0 == 10)		//Hon loan
		|| (*(BYTE*)0x00400354 != 0))				//So lan Xdame	
	{
		gMSGCommon.SendHack(13);
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 13", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//14.Hithack 2022
	if (*(BYTE*)(*(DWORD*)(0x0400000) + 0x00927C88) != 0)
	{
		gMSGCommon.SendHack(14);
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 14", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//15.Danh nhanh
	if (*(BYTE*)0x00400020 > 0)
	{
		gMSGCommon.SendHack(15);
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 15", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//16.Skill Trong Thành)
	if (*(DWORD *)0x005965C8 <= 0 || *(DWORD *)0x00895339 <= 10 /*|| *(DWORD *)0x08793738 < 10*/)
	{
		gMSGCommon.SendHack(16);
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 16", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}




	//17.XSDAME NEW

	if ((*(BYTE*)0x005B1705 != 106)			//quayrong
		|| (*(BYTE*)0x005A1792 != 106)		//danh thuong Dk
		|| (*(BYTE*)0x005AD81F != 106)		//xoay kiem
		|| (*(BYTE*)0x0059C798 != 106)
		//----DW
		|| (*(BYTE*)0x0059CED7 != 106)		//skill don
		|| (*(BYTE*)0x005B1CC6 != 106)		//muabangtuyet
		|| (*(BYTE*)0x005B0C02 != 106)		//Lua Dia Nguc
		|| (*(BYTE*)0x0059D1DD != 106)		//muasaobang
		|| (*(BYTE*)0x005B1877 != 106)		//Kame
		|| (*(BYTE*)0x005B05C6 != 106)		//Nova
		|| (*(BYTE*)0x005B071D != 106)		//Nova1
		|| (*(BYTE*)0x005B1AA4 != 106)		//Cot lua
		//-------EFL
		|| (*(BYTE*)0x005AC54F != 106)		//Ngu Tien
		|| (*(BYTE*)0x0059D6A8 != 106)		//Ban bang
		|| (*(BYTE*)0x005AC227 != 106)		//Buff mau
		//--------SUM
		|| (*(BYTE*)0x00534FCD != 106)		//Skill sach
		|| (*(BYTE*)0x0059DED4 != 106)		//Giat Set
		|| (*(BYTE*)0x0059DC82 != 106)		//Hut Mau
		|| (*(BYTE*)0x005B2C93 != 106)		//Shok Dien
		//--------RF
		|| (*(BYTE*)0x0059F46C != 106)		//D?m ??t
		|| (*(BYTE*)0x0059F20C != 106)		//AALH
		//--------MG
		|| (*(BYTE*)0x005ADE21 != 106)		//Cú chém
		|| (*(BYTE*)0x005ADAC7 != 106)		//Chem Lua
		|| (*(BYTE*)0x005AE84F != 106)		//Hoa Diem
		//--------DL
		|| (*(BYTE*)0x0059C798 != 106)		//Quat xich
		|| (*(BYTE*)0x005AF1AC != 106)		//Hoa Am
		|| (*(BYTE*)0x005AE1B0 != 106)		//Hon loan
		|| (*(BYTE*)0x00400354 != 0))		//So lan Xdame
	{
		gMSGCommon.SendHack(17);
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 17", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//18.Speed New
	if (*(BYTE*)0x004DA3E4 != 139 || *(BYTE*)0x004DA3E9 != 255)
	{
		gMSGCommon.SendHack(18);
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 18", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//19.Danh Ngoai tam
	if (*(BYTE*)0x00596343 == 233)
	{
		gMSGCommon.SendHack(19);
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 19", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//20.Nhan vat bất động
	if (*(BYTE*)0x0054539E != 117 || *(BYTE*)0x004DA3E9 == 124)
	{
		gMSGCommon.SendHack(20);
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 20", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}


	if (*(BYTE *)0x004DA3E0 != 40)
	{
		gMSGCommon.SendHack(21);
		MessageBoxA(NULL, "Speed-Hack Detected.", "[HieuDaiCa]", ERROR);
		ExitProcess(0);
	}


#endif





	//--Bar MiniMap
	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 || gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		if (gRenderMap.DataMap.ModelID != -1 && MiniMap)
		{
			gInterface.MiniMapMini();
		}
	}


	 G_QUAN_LY_TK.DRAW_QUAN_LY();

	gObjUser.Refresh();
	
	gHuyHieuCuongHoa.DrawHuyHieu();

	gHuyHieuCuongHoa.DrawChiSo();

	gCuongHoaWing.DrawHuyHieu();

	gCuongHoaWing.DrawChiSo();

	gVuKhiRong.DrawHuyHieu();

	gVuKhiRong.DrawChiSo();

#if(MOCNAP == 1)
		G_BEXO_MOCNAP.DRAW_MOCNAP();
#endif
#if(THANMA)
	gInterface.DrawTMAllWindows();
#endif
	jCRenderRuud.CheckOpen();
	
	if(gObjUser.lpViewPlayer->WeaponFirstSlot >= ITEM2(4,0) && gObjUser.lpViewPlayer->WeaponFirstSlot <= ITEM2(4,255)
		||gObjUser.lpViewPlayer->WeaponSecondSlot >= ITEM2(4,0) && gObjUser.lpViewPlayer->WeaponSecondSlot <= ITEM2(4,255))
	{
		gInterface.PetY = 38.0f;
		
	}
	else
	{
		gInterface.PetY = 26.0f;
	}

	if(gObjUser.lpViewPlayer->PetSlot!= -1)
	{
		gInterface.PetX = 61.0f;
	}else
	{
		gInterface.PetX = 0;
	}

	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{	gInterface.DrawInterfaceDragonLS3();
		gInterface.DrawInterfaceDragonRS3();
	}


#if(CHIEN_TRUONG_CO)
	gInterface.DrawChienTruongCo();
	gInterface.DrawTimeCTC();
#endif

#if(VONGQUAY_NEW)
	gLuckySpin.Draw();
#endif

#if(DANH_HIEU_NEW == 1)
	G_BEXO_DANH_HIEU.DRAW_DANH_HIEU();
#endif

#if(TU_LUYEN_NEW == 1)
	G_BEXO_TU_LUYEN.DRAW_TU_LUYEN();
#endif



	gCustomEventTime.Notice();


	gInterface.DrawMiniMap();

	gInterface.DrawTimeUI();

#if(RANKINGGOC == 1)
	gCustomRanking.DrawRankPanelWindow();
#endif

#if(RANKING_NEW == 1)
	gRanking.Draw();
#endif

#if(VANTHANH_CHUCHAY == 1)
	gInterface.DrawTextRun();
#endif

	gCustomEventTime.DrawEventTimePanelWindow();

#if(RECONNECT == 1)
	ReconnectMainProc();
#endif

	gInterface.DrawVipWindow();

	gInterface.DrawMenu();

	gInterface.DrawMenuOpen();

	gCustomCommandInfo.DrawCommandWindow();

	gInterface.DrawConfirmOpen();

	gInterface.WindowsKG();

	gRenderMap.AutoSendMove();

	gInterface.TvTEvent();

#if(BOSS_GUILD == 1)
	gInterface.DrawBossGuildWindow();
	gInterface.DrawBossGuildMap(); // Time
#endif


	gInterface.DrawCTCMiNiMap(); //LOad de draw
	gInterface.DrawCTCMiniWindow();//LOad de draw


#if(NUT_TINH_NANG)
	gInterface.DrawnNapThe();

	gInterface.DrawnFacebook();

	//gInterface.DrawFanpage();

	//gInterface.DrawGoup();
#endif



#if(EXBEXO_LOAD_SEND_TINH_NANG)
	gInterface.DRAW_TINHNANG_INTERFACE();
#endif

#if (NGAN_HANG_NGOC)
	gCustomJewelBank.DrawJewelBankWindow();
#endif

#if (DOI_GIOI_TINH)
	gInterface.DrawChangingClassWindow();
#endif

#if(PARTYSEARCH==1)
	gPartySearch.DrawPartySearchWindow();
	gPartySearch.DrawPartySettingsWindow();
#endif

#if(OANTUTY)
	gInterface.DrawRPS();
#endif

	gInterface.DrawMiniMap();



	if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		gInterface.DrawInterfaceCustom();
	}

	pDrawInterface();

	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		
		if(gProtect.m_MainInfo.CustomInterfaceType == 1)
		{
			gInterface.DrawInterface97Menu();
		}
		if(gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			gInterface.DrawInterfaceS2Menu();
		}
	}

	if( GetForegroundWindow() == pGameWindow )
	{
		if (GetKeyState(VK_SNAPSHOT) < 0) 
		{
			gInterface.DrawLogo(1); 
		}

		if (GetKeyState('H') & 0x4000) 
		{
			gCustomEventTime.OpenWindow();
		}
		if (GetKeyState('O') & 0x4000) 
		{
			gInterface.OpenConfig(0);
		}

		if (GetKeyState('J') & 0x4000)
		{
			gCustomJewelBank.OpenWindow();
		}

		if (GetKeyState(VK_UP) & 0x4000) 
		{
			gInterface.OpenConfig(1);
		}
		else if (GetKeyState(VK_DOWN) & 0x4000) 
		{
			gInterface.OpenConfig(1);
		}

		if (GetKeyState(VK_F5) & 0x4000)
		{
			gInterface.SwitchHideDanhHieu();
		}

		if (GetKeyState(VK_F6) & 0x4000) 
		{
			G_QUAN_LY_TK.OPEN_WINDOW_CHANGEPASS();
		}

		if (GetKeyState(VK_F7) & 0x4000) 
		{
			gInterface.SwitchAntiLag2();
			gInterface.SwitchAntiLag1();
		}


		if (GetKeyState(VK_F9) & 0x4000)
		{
			gInterface.SwitchHidePlayer();
		}

		if (GetKeyState(VK_F4) & 0x4000) //Test open skin
		{
			if((GetTickCount()-gInterface.Data[eWindow_SkinModel].EventTick) > 300)
			{
				gInterface.Data[eWindow_SkinModel].OnShow ^= 1;
				gInterface.Data[eWindow_SkinModel].EventTick = GetTickCount();
			}
		}
		//==========Test Window
		//if (GetKeyState(VK_F3) & 0x4000) //Test NPC Move Map Bao Tieu
		//{
		//	if ((GetTickCount() - gInterface.Data[eWindow_QuanLyBuffPhe].EventTick) > 300)
		//	{
		//		gInterface.Data[eWindow_QuanLyBuffPhe].OnShow ^= 1;
		//		gInterface.Data[eWindow_QuanLyBuffPhe].EventTick = GetTickCount();
		//	}
		//}

		if (GetKeyState(VK_F8) & 0x4000) 
		{
			//gInterface.OpenMenuWindow();
			if((GetTickCount()-gInterface.Data[eMenu_MAIN].EventTick) > 300)
			{
				if (gInterface.CheckMenuWindow())
				{
					gInterface.Data[eMenu_MAIN].EventTick = GetTickCount();
					gInterface.CloseMenuWindow();
				}
				else
				{
					gInterface.Data[eMenu_MAIN].EventTick = GetTickCount();

					//close all to open menu
					gInterface.CloseMenuWindow();
					gInterface.CloseEventTimeWindow(); //event time
					//gJewelBank.CloseJewelBankWindow(); //jewelbank
					gInterface.Data[ePARTYSEARCH_MAIN].OnShow == false;//setting searchparty
					gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == false;//searchpeary
					gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == false;//searchpeary
					gInterface.Data[eCHANGINGCLASS_MAIN].OnShow == false;//setting searchparty
				
					gInterface.CloseVipWindow(); //close Vip
					//gInterface.CloseERankWindow(); //close Rank
					//gInterface.CloseECommandWindow(); //close Ranking
					//open-menu
					gInterface.OpenMenuWindow();
					//gTuChanInterface.SwitchTuChan();
				}
			}
		}



		
		if (GetKeyState(VK_END) <0 ) 
		{
			{		
				gObjUser.ToggleAuto();
			}

		}

		if (GetKeyState(VK_INSERT) <0 ) 
		{
			{		
				gObjUser.ToggleAutoTron();
			}

		}

		
		//if (GetKeyState(VK_F8) & 0x4000) 
		//{
		//	gCustomRanking.OpenWindow();
		//}
		
		if (GetKeyState(VK_F10) & 0x4000) 
		{
			gInterface.SwitchCamera();
		}
		if (GetKeyState(VK_F11) & 0x4000) 
		{
			gInterface.CameraInit();
		}
		if (GetKeyState(VK_F12) & 0x4000) 
		{
			if( gTrayMode.TempWindowProc == NULL )
			{
				gTrayMode.TempWindowProc = SetWindowLong(pGameWindow, GWL_WNDPROC, (long)gController.Window);
			}
			// ----
			gTrayMode.SwitchState();
		}
		if (GetKeyState(VK_ESCAPE) < 0) 
		{

			if (gInterface.Data[ePARTYSEARCH_MAIN].OnShow == true)
			{
				gInterface.Data[ePARTYSEARCH_MAIN].OnShow = false;
				
				if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

#if(RANKING_NEW == 1)
			if (gRanking.Show == true)
			{
				gRanking.Show = false;
				pSetCursorFocus = false;
			}
#endif


			if (gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == true)
			{
					gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == false;
				
				if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

			if (gInterface.Data[eJewelBank_MAIN].OnShow == true)
			{
				gInterface.Data[eJewelBank_MAIN].OnShow == false;

				if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}


			if (gInterface.Data[eCHANGINGCLASS_MAIN].OnShow == true)
			{
				gInterface.Data[eCHANGINGCLASS_MAIN].OnShow == false;

				if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}


			if (gInterface.Data[eCommand_MAIN].OnShow == true)
			{
				gInterface.Data[eCommand_MAIN].OnShow = false;
				
				if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

			if (gInterface.Data[eRankPANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eRankPANEL_MAIN].OnShow = false;
				
				if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

			if (gInterface.CheckVipWindow())
			{
				gInterface.CloseVipWindow();
			}


			if (gInterface.CheckMenuWindow())
			{
				gInterface.CloseMenuWindow();
			}
			if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
				
			if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}


		}
	}

//	gCRuudShop.RuudShop();
	gInterface.DrawLogo(0);
	////-----------------------------------------------------------------------------------------------------------------------
	//char Text1[1024];
	//char Text2[1024];
	//char Text3[1024];
	//char Text4[1024];
	//sprintf(Text1, "X: %d", gObjUser.m_CursorX);
	//sprintf(Text2, "Y: %d", gObjUser.m_CursorY);
	//
	//gInterface.DrawFormat(eYellow, 615, 10, 200, 1, Text1);
	//gInterface.DrawFormat(eYellow, 615, 20, 200, 1, Text2);
	////gInterface.DrawFormat(eYellow, 300, 10, 200, 1, "X: %d", gObjUser.m_CursorX);
	////gInterface.DrawFormat(eYellow, 300, 20, 200, 1, "Y: %d", gObjUser.m_CursorY);

	//int ToaDoX = gObjUser.CoordenadaX;
	//int ToaDoY = gObjUser.CoordenadaY;
	//if ( gObjUser.CoordenadaX != 0 || gObjUser.CoordenadaY != 0 )
	//{
	//	
	//	

	//	if((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) >= 10000)
	//	{
	//		if ( (ToaDoX - gObjUser.CoordenadaX) > 5 || (ToaDoX - gObjUser.CoordenadaX) < 5  )
	//	{
	//		//ExitProcess(0);
	//		gInterface.DrawFormat(eYellow, 300, 10, 200, 1, "ToaDoX: %d", ToaDoX);
	//		gInterface.DrawFormat(eYellow, 300, 20, 200, 1, "ToaDoY: %d", ToaDoY);
	//	}
	//		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();
	//	}
	//	
	//	//if ( (ToaDoY - gObjUser.CoordenadaY) > 5 || (ToaDoY - gObjUser.CoordenadaY) < 5  )
	//	//{
	//	//	ExitProcess(0);
	//	//}

	//	
	//	
	//}

#if(FLAG_SKIN)
	ThueFlag.Draw();
#endif


	//-----------------------------------------------------------------------------------------------------------------------
}

void Interface::SwitchMiniMap()
{
	if((GetTickCount() - gInterface.Data[eNULL_MAP].EventTick) < 1000 ||this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[eNULL_MAP].EventTick = GetTickCount();

	if (MiniMap != 0)
	{
		gInterface.DrawMessage(1, "MiniMap Window [OFF]");
		MiniMap = 0;
		WritePrivateProfileStringA("Graphics","MiniMap","0","./Settings.ini");
	}
	else 
	{
		gInterface.DrawMessage(1, "MiniMap Window [ON]");
		MiniMap = 1;
		WritePrivateProfileStringA("Graphics","MiniMap","1","./Settings.ini");
	}
	
}

int Thongbao = 100;
int a = 10;
void Interface::DrawTimeUI()
{
	if(gProtect.m_MainInfo.CustomInterfaceType >= 0)
	{
		if (TimerBar == 0
			|| (this->CheckWindow(ObjWindow::CashShop)
			//|| this->CheckWindow(ObjWindow::FriendList)
			|| this->CheckWindow(ObjWindow::MoveList)
			//|| this->CheckWindow(ObjWindow::Party)
			//|| this->CheckWindow(ObjWindow::Quest)
			//|| this->CheckWindow(ObjWindow::NPC_Devin)
			//|| this->CheckWindow(ObjWindow::Guild)	
			|| this->CheckWindow(ObjWindow::Trade)
			|| this->CheckWindow(ObjWindow::Warehouse)
			//|| this->CheckWindow(ObjWindow::ChaosBox)
			//|| this->CheckWindow(ObjWindow::CommandWindow)
			//|| this->CheckWindow(ObjWindow::PetInfo)
			|| this->CheckWindow(ObjWindow::Shop)
			|| this->CheckWindow(ObjWindow::Inventory)
			//|| this->CheckWindow(ObjWindow::Store)
			//|| this->CheckWindow(ObjWindow::OtherStore)
			|| this->CheckWindow(ObjWindow::Character)
			//|| this->CheckWindow(ObjWindow::DevilSquare)
			//|| this->CheckWindow(ObjWindow::BloodCastle)
			//|| this->CheckWindow(ObjWindow::CreateGuild)
			//|| this->CheckWindow(ObjWindow::GuardNPC)
			//|| this->CheckWindow(ObjWindow::SeniorNPC)
			//|| this->CheckWindow(ObjWindow::GuardNPC2)
			//|| this->CheckWindow(ObjWindow::CastleGateSwitch)
			//|| this->CheckWindow(ObjWindow::CatapultNPC)
			//|| this->CheckWindow(ObjWindow::CrywolfGate)
			//|| this->CheckWindow(ObjWindow::IllusionTemple)
			//|| this->CheckWindow(ObjWindow::HeroList)
			|| this->CheckWindow(ObjWindow::ChatWindow)
			//|| this->CheckWindow(ObjWindow::FastMenu)
			|| this->CheckWindow(ObjWindow::Options)	
			|| this->CheckWindow(ObjWindow::Help)
			//|| this->CheckWindow(ObjWindow::FastDial)
			|| this->CheckWindow(ObjWindow::SkillTree)
			//|| this->CheckWindow(ObjWindow::GoldenArcher1)
			//|| this->CheckWindow(ObjWindow::GoldenArcher2)
			//|| this->CheckWindow(ObjWindow::LuckyCoin1)
			//|| this->CheckWindow(ObjWindow::LuckyCoin2)
			//|| this->CheckWindow(ObjWindow::NPC_Duel)
			//|| this->CheckWindow(ObjWindow::NPC_Titus)
			|| this->CheckWindow(ObjWindow::CashShop)
			|| this->CheckWindow(ObjWindow::Lugard)
			//|| this->CheckWindow(ObjWindow::QuestList1)
			//|| this->CheckWindow(ObjWindow::QuestList2)
			|| this->CheckWindow(ObjWindow::Jerint)
			|| this->CheckWindow(ObjWindow::FullMap)
			|| this->CheckWindow(ObjWindow::NPC_Dialog)
			//|| this->CheckWindow(ObjWindow::GensInfo)
			|| this->CheckWindow(ObjWindow::NPC_Julia)
			|| this->CheckWindow(ObjWindow::NPC_ChaosMix)
			|| this->CheckWindow(ObjWindow::ExpandInventory)
			|| this->CheckWindow(ObjWindow::ExpandWarehouse)
			//|| this->CheckWindow(ObjWindow::MuHelper)
			|| pMapNumber == 34
			|| pMapNumber == 30))
		{
			return;
		}
			//--
			time_t TimeServer;
			struct tm * ServerT;
			time(&TimeServer);
			
			ServerT = gmtime(&TimeServer);
			// ----
			char ServerTimeName[25] = "Giờ :";
			char ServerTime[30];

			sprintf(ServerTime, "%2d:%02d:%02d", (ServerT->tm_hour + GMT)%24, ServerT->tm_min, ServerT->tm_sec);
			// -----
			this->DrawGUI(eTIME, this->Data[eTIME].X - 30, this->Data[eTIME].Y + 52);

			this->DrawFormat(eGold, 5, 416, 50, 1, ServerTimeName);
			this->DrawFormat(eWhite, 25, 416, 100, 1, ServerTime);

			//this->DrawFormat(eWhite, 300, 300, 70, 1, ServerTime); //ss2/3



			//this->DrawFormat(eOrange, 5, 370, 300, 1, gCustomMessage.GetMessage(97));
			//this->DrawFormat(eExcellent, 5, 380, 300, 1, gCustomMessage.GetMessage(98));
			//this->DrawFormat(eBlue250 , 5, 391, 300, 1, gCustomMessage.GetMessage(99));
			//this->DrawFormat(eYellow, 70, 415, 300, 1, gCustomMessage.GetMessage(100));

	}
	//gCustomEventTime.DrawEventTimePanelWindow();

}

int Interface::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	int LineCount = 0;
	
	char * Line = strtok(Buff, "\n");
	
	while( Line != NULL )
	{
		pDrawColorText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
	
	return PosY;
}

bool Interface::IsWorkZone4(float x, float y, float x2, float y2)
{
	bool result = GetForegroundWindow() == pGameWindow && pCursorX >= x && pCursorX <= x + x2 && pCursorY >= y && pCursorY <= y + y2;
	return result;
}

bool Interface::CheckWindow(int WindowID)
{
	return pCheckWindow(pWindowThis(), WindowID);
}
int Interface::CloseWindow(int WindowID)
{
	return pCloseWindow(pWindowThis(), WindowID);
}
int Interface::OpenWindow(int WindowID)
{
	return pOpenWindow(pWindowThis(), WindowID);
}

bool Interface::IsWorkZone2(float X, float Y, float MaxX, float MaxY)
{
	if ((gObjUser.m_CursorX < X || gObjUser.m_CursorX > MaxX)
		|| (gObjUser.m_CursorY < Y || gObjUser.m_CursorY > MaxY))
	{
		return false;
	}
	// ----
	return true;
}
bool Interface::IsWorkZone(float X, float Y, float MaxX, float MaxY, bool a5)
{
	if (a5)
	{
		if ((pCursorX < X || pCursorX > X + MaxX) || (pCursorY < Y || pCursorY > Y + MaxY))
			return false;
		return true;
	}
	if ((pCursorX < X || pCursorX > MaxX) || (pCursorY < Y || pCursorY > MaxY))
		return false;
	return true;
}

bool Interface::IsWorkZone(short ObjectID)
{
	if( (pCursorX < this->Data[ObjectID].X || pCursorX > this->Data[ObjectID].MaxX) 
		|| (pCursorY < this->Data[ObjectID].Y || pCursorY > this->Data[ObjectID].MaxY) )
		return false;

	return true;
}

float Interface::GetResizeX(short ObjectID)
{
	if( pWinWidth == 800 )
	{
		return this->Data[ObjectID].X + 16.0;
	}
	else if( pWinWidth != 1024 )
	{
		return this->Data[ObjectID].X - 16.0;
	}
	
	return this->Data[ObjectID].X;
}

int Interface::DrawToolTip(int X, int Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	return pDrawToolTip(X, Y, Buff);
}

int Interface::DrawMessage(int Mode, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----
	return pDrawMessage(Buff, Mode);
}

void Interface::DrawVipWindow()
{

	if (!this->Data[eVip_MAIN].OnShow)
	{
		return;
	}

	if (gProtect.m_MainInfo.EnableVipShop != 1)
	{
		this->CloseVipWindow();
		return;
	}

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store))
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)))
	{
		CloseVipWindow();
		return;
	}

	// ----
	float MainWidth = 230.0;
	float MainHeight = 320.0;
	float StartBody = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	// ----
	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	//pDrawGUFULL(0x9333, StartX - 10, StartY - 10, 250, 300, 0, 0, 1, 1, 1, 1, 0.0); // MENU


	// ----
	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(5));
	int LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 35, 210, 1, gCustomMessage.GetMessage(6), gObjUser.lpPlayer->Name);
	LineY = this->DrawFormat(eGold, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(14));
	LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(7));
	LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(8));
	//--
	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 85, 200, 1); //-- Divisor
	//--
	this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 95 - 2, 210, 1, "Loại");
	this->DrawFormat(eGold, (int)StartX + 80, (int)StartBody + 95 - 2, 210, 1, "Exp");
	this->DrawFormat(eGold, (int)StartX + 130, (int)StartBody + 95 - 2, 210, 1, "Drop");
	this->DrawFormat(eGold, (int)StartX + 170, (int)StartBody + 95 - 2, 210, 1, "Thời Gian");
	// ----

	if (gProtect.m_MainInfo.VipTypes < 1 || gProtect.m_MainInfo.VipTypes > 3)
	{
		gProtect.m_MainInfo.VipTypes = 3;
	}

	for (int i = 0; i < (int)gProtect.m_MainInfo.VipTypes; i++)
	{
		this->DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 110 + (12 * i) - 5, 210, 1, gCustomBuyVip.m_CustomBuyVipInfo[i].VipName);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 80, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Exp);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 130, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Drop);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 170, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "%d day(s)", gCustomBuyVip.m_CustomBuyVipInfo[i].Days);

		pDrawGUI(0x7B5E, StartX + 30, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
		pDrawGUI(0x7B5E, StartX + 30 + 82, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
	}

	if (gProtect.m_MainInfo.VipTypes > 0)
	{
		// ---- bronze start 
		if (IsWorkZone(eVip_BRONZE))
		{
			if (this->Data[eVip_BRONZE].OnClick)
				this->DrawButton(eVip_BRONZE, StartX + 64, 220, 0, 58);
			else
				this->DrawButton(eVip_BRONZE, StartX + 64, 220, 0, 29);
			// ----
			this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
			this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin1);
			this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin2);
			this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin3);
		}
		else
			this->DrawButton(eVip_BRONZE, StartX + 64, 220, 0, 0);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 90, 220 + 9, 160, 1, gCustomMessage.GetMessage(9), gCustomBuyVip.m_CustomBuyVipInfo[0].VipName);
		// ---- bronze end ------------------------------------
	}

	if (gProtect.m_MainInfo.VipTypes > 1)
	{
		// ---- Silver start ------------------------------------
		if (IsWorkZone(eVip_SILVER))
		{
			if (this->Data[eVip_SILVER].OnClick)
				this->DrawButton(eVip_SILVER, StartX + 64, 250, 0, 58);
			else
				this->DrawButton(eVip_SILVER, StartX + 64, 250, 0, 29);
			// ----
			this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
			this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin1);
			this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin2);
			this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin3);
		}
		else
			this->DrawButton(eVip_SILVER, StartX + 64, 250, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 90, 250 + 9, 160, 1, gCustomMessage.GetMessage(9), gCustomBuyVip.m_CustomBuyVipInfo[1].VipName);
		// ---- silver end ------------------------------------
	}

	if (gProtect.m_MainInfo.VipTypes > 2)
	{
		// ---- gold start ------------------------------------
		if (IsWorkZone(eVip_GOLD))
		{
			if (this->Data[eVip_GOLD].OnClick)
				this->DrawButton(eVip_GOLD, StartX + 64, 280, 0, 58);
			else
				this->DrawButton(eVip_GOLD, StartX + 64, 280, 0, 29);
			// ----
			this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
			this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin1);
			this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin2);
			this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin3);
		}
		else
			this->DrawButton(eVip_GOLD, StartX + 64, 280, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 90, 280 + 9, 160, 1, gCustomMessage.GetMessage(9), gCustomBuyVip.m_CustomBuyVipInfo[2].VipName);
		// ---- gold end ------------------------------------
	}

	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), 280 + 55, 200, 1); //-- Divisor
}



bool Interface::EventVipWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_CLOSE].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_CLOSE].EventTick = GetTickCount();
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Bronze(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_BRONZE].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_BRONZE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_BRONZE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_BRONZE].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_BRONZE].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(1);
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Silver(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_SILVER].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_SILVER))
	{
		return false;
	}
	if (gProtect.m_MainInfo.VipTypes < 2)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_SILVER].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_SILVER].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_SILVER].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(2);
	this->CloseVipWindow();
	// ----
	return false;
}

// ----------------------------------------------------------------------------------------------
bool Interface::EventVipWindow_Gold(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_GOLD].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_GOLD))
	{
		return false;
	}
	if (gProtect.m_MainInfo.VipTypes < 3)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_GOLD].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_GOLD].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_GOLD].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(3);
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Main(DWORD Event)
{
	this->EventVipWindow_Close(Event);
	this->EventVipWindow_Bronze(Event);
	this->EventVipWindow_Silver(Event);
	this->EventVipWindow_Gold(Event);
	// ----
	return true;
}

float Interface::DrawRepeatGUI(short MonsterID, float X, float Y, int Count)
{
	float StartY = Y;
	// ----
	for( int i = 0; i < Count; i++ )
	{
		pDrawGUI(this->Data[MonsterID].ModelID, X, StartY,
			this->Data[MonsterID].Width, this->Data[MonsterID].Height);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

float Interface::DrawRepeatGUIScale(short MonsterID, float X, float Y,float ScaleX, float ScaleY, int Count)
{
	float StartY = Y;
	// ----
	for( int i = 0; i < Count; i++ )
	{
		this->DrawIMG(this->Data[MonsterID].ModelID, X, StartY,ScaleX,ScaleY);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

void Interface::DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= X;
		this->Data[ObjectID].Y		= Y;
		this->Data[ObjectID].MaxX	= X + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= Y + this->Data[ObjectID].Height;
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, X, Y, 
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

void Interface::DrawLogo(bool active)
{
	if (gProtect.m_MainInfo.PrintLogo != 0)
	{

		if (active == 1)
		{
			this->Data[eLogo].EventTick = GetTickCount()+1500;
		}

		if (gInterface.Data[eLogo].EventTick > GetTickCount())
		{
			if (gProtect.m_MainInfo.PrintLogo == 1)
			{
				this->DrawGUI(eLogo, 10, 10);
			}

			if (gProtect.m_MainInfo.PrintLogo == 2)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, 10);

			}

			if (gProtect.m_MainInfo.PrintLogo == 3)
			{
				this->DrawGUI(eLogo, 10, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 4)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 5)
			{
				this->DrawGUI(eLogo, (MAX_WIN_WIDTH/2)-(150/2), (MAX_WIN_HEIGHT/2)-(114/2));
			}
		}
	}
}

void Interface::DrawMenu()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (this->Data[eMenu].OnShow)
	{
		this->Data[eMenu].OnShow = false;
	}

	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		CloseMenuWindow();
		return;
	}
	
	this->Data[eMenu].OnShow = true;
}

bool Interface::EventDrawMenu_Open(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu].EventTick);
	// ----
	if (!this->Data[eMenu].OnShow || !IsWorkZone(eMenu))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
		this->Data[eMenu].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	
	// ----
	this->Data[eMenu].EventTick = GetTickCount();
	
	if (CheckMenuWindow())
	{
		CloseMenuWindow();
	}
	else
	{
		CloseCustomWindow();
		OpenMenuWindow();
	}
	// ----
	return false;
}

void Interface::DrawMenuOpen()
{
	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}
	//--
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1 || !this->Data[eMenu_MAIN].OnShow || pCheckWindow(pWindowThis(), 35))
	{
		return;
	}

	float MainWidth = 250.0;
	float MainHeight = 310.0;
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	//--
	//---------------------------------------------------------------------------------------//
	if (gInterface.IsWorkZone(eMenu_MAIN)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//---------------------------------------------------------------------------------------//
	pDrawMessage("", 0); // Không Cho Hiện Thông Báo Trên Màn Hình
	//---------------------------------------------------------------------------------------//



	this->Data[eMenu_MAIN].MaxX = StartX + MainWidth;
	this->Data[eMenu_MAIN].MaxY = StartY + MainHeight;

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	//this->DrawFormat(eGold, (int)StartX + 10, (int)StartY + 10, 210, 3, "Menu - F5");
		
	CustomFont.DrawMultipleColor(CustomFont.FontSize18, (int)StartX + 100, (int)StartY + 10, 0x0, 0, 0, 0, "Menu - F8");

	if(gProtect.m_MainInfo.EnableCoinStatus == 1)
	{
		this->DrawFormat(eGold, (int)StartX + 10, (int)StartY + 35, 210, 3, gCustomMessage.GetMessage(50));

		this->DrawFormat(eWhite, (int)StartX + 25, (int)StartY + 55, 40, 1, gCustomMessage.GetMessage(51));
		this->DrawFormat(eGold, (int)StartX + 50, (int)StartY + 55, 40, 1, "%d",Coin1);

		this->DrawFormat(eWhite, (int)StartX + 90, (int)StartY + 55, 40, 1, gCustomMessage.GetMessage(52));
		this->DrawFormat(eGold, (int)StartX + 115, (int)StartY + 55, 40, 1, "%d",Coin2);

		this->DrawFormat(eWhite, (int)StartX + 153, (int)StartY + 55, 40, 1, gCustomMessage.GetMessage(53));
		this->DrawFormat(eGold, (int)StartX + 176, (int)StartY + 55, 40, 1, "%d",Coin3);
	}
	else
	{
		this->DrawFormat(eGold, (int)StartX + 10, (int)StartY + 45, 210, 3, gCustomMessage.GetMessage(54));
	}

	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + 75, 200, 1); //-- Divisor

	float CurrentMove;
	int BtCount = -1;
	int BtStart = StartY + 88;
	int BtDistance = 28;

	int ObjectIDs[13] = 
	{ 
		eMenu_OPT1,
		eMenu_OPT2,
		eMenu_OPT3,
		eMenu_OPT4,
		eMenu_OPT5,
		eMenu_OPT6,
		eMenu_OPT7,
		eMenu_OPT8,
		eMenu_OPT9,
		eMenu_OPT10,
		eMenu_OPT11,
		eMenu_OPT12,

	};
	
	for(int n = 0; n < 12; n++)
	{
		if(gProtect.m_MainInfo.MenuButtons[n] == 1)
		{
			BtCount++;
		}
		else
		{
			continue;
		}

		CurrentMove = 0.0;
		if (IsWorkZone(ObjectIDs[n]))
		{
			if (this->Data[ObjectIDs[n]].OnClick)
			{
				if( gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4 )
				{	
					PlayBuffer(25, 0, 0);
					CurrentMove = 30.5f;
				}
				else
				{
					CurrentMove = 29;
				}
			}
		}

		/*float MainWidth = 280.0;
		float MainHeight = 370.0;
		float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
		float MainCenter = StartX + (MainWidth / 3);
		float ButtonX = MainCenter - (float)(29.0 / 2);*/
		
		int SoButton = 12;
		if( gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4 )
		{	
		if (BtCount %2 == 0)
				{
					this->DrawButton(ObjectIDs[n], StartX + 10, BtStart + (30.0f * (BtCount/2)), 0, CurrentMove);
					//this->DrawFormat(eWhite, StartX  + 10, BtStart + (30.0f * (BtCount/2)) + 9, 108, 3,gCustomMessage.GetMessage(( n == 8) ? 44 : 25 + n));
					this->DrawFormat(eWhite, StartX  + 10, BtStart + (30.0f * (BtCount/2)) + 9, 108, 3,gConfig.MenuGame_TextVN[(( n == SoButton) ? 40 : 1 + n)]);
				}
			else 
				{
					this->DrawButton(ObjectIDs[n], StartX + (MainWidth) - (108 ) - 10, BtStart + (30.0f * (BtCount/2)), 0, CurrentMove);
					this->DrawFormat(eWhite, StartX + (MainWidth) - (108 ) - 10, BtStart + (30.0f * (BtCount/2)) + 9, 108, 3,gConfig.MenuGame_TextVN[(( n == SoButton) ? 40 : 1 + n)]);
				}

		}
		else
		{
		if (BtCount %2 == 0)
				{
					this->DrawButton(ObjectIDs[n], StartX + 10, BtStart + (29 * (BtCount/2)), 0, CurrentMove);
					//this->DrawFormat(eWhite, StartX  + 10, BtStart + (30.0f * (BtCount/2)) + 9, 108, 3,gCustomMessage.GetMessage(( n == 8) ? 44 : 25 + n));
					this->DrawFormat(eWhite, StartX  + 10, BtStart + (29 * (BtCount/2)) + 9, 108, 3,gConfig.MenuGame_TextVN[(( n == SoButton) ? 40 : 1 + n)]);
				}
			else 
				{
					this->DrawButton(ObjectIDs[n], StartX + (MainWidth) - (108 ) - 10, BtStart + (29 * (BtCount/2)), 0, CurrentMove);
					this->DrawFormat(eWhite, StartX + (MainWidth) - (108 ) - 10, BtStart + (29 * (BtCount/2)) + 9, 108, 3,gConfig.MenuGame_TextVN[(( n == SoButton) ? 40 : 1 + n)]);
				}
		}


		//this->DrawButton(ObjectIDs[n], StartX + (MainWidth / 5) - (108 / 5), BtStart + (33.0f * BtCount), 0, CurrentMove);
		//this->DrawFormat(eWhite, StartX + (MainWidth / 5) - (108 / 5), BtStart + (33.0f * BtCount) + 9, 108, 3,gCustomMessage.GetMessage(( n == 8) ? 44 : 25 + n));

			
	}


	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2),  StartY + MainHeight - 40, 200, 1); //-- Divisor


	//--
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_CLOSE))
	{
		if (this->Data[eMenu_CLOSE].OnClick)
		{
			PlayBuffer(25, 0, 0);
			gInterface.DrawButtonRender(eMenu_CLOSE, StartX + (MainWidth / 2) - (59 / 2), StartY + MainHeight  - 32, 0 , 28);
		}
		else
		{
			gInterface.DrawButtonRender(eMenu_CLOSE, StartX + (MainWidth / 2) - (59 / 2), StartY + MainHeight  - 32, 0 , 0);
		}
	}
	else
	{
		gInterface.DrawButtonRender(eMenu_CLOSE, StartX + (MainWidth / 2) - (59 / 2), StartY + MainHeight - 32, 0 , 0);
	}
	gInterface.DrawFormat(eWhite, StartX + (MainWidth / 2) - (59 / 2), StartY + MainHeight - 25 , 59, 3, "Đóng");
}

bool Interface::EventDrawMenu_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_CLOSE].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_CLOSE].EventTick = GetTickCount();
	this->CloseMenuWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventDrawMenu_Op1(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT1].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
	|| gInterface.CheckWindow(Warehouse)
	|| gInterface.CheckWindow(ChaosBox)
	|| gInterface.CheckWindow(Store)
	|| gInterface.CheckWindow(OtherStore)
	|| gInterface.CheckWindow(ExpandInventory)
	|| gInterface.CheckWindow(Shop)
	|| gInterface.CheckWindow(Trade)
	|| gInterface.CheckWindow(LuckyCoin1)
	|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	//--
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT1))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT1].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT1].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT1].EventTick = GetTickCount();

	this->CloseMenuWindow();

#if(MOCNAP == 1)
	G_BEXO_MOCNAP.OPEN_WINDOW_MOCNAP();
	//G_BEXO_MOCNAP.BUY_MOCNAP(2);
	//PlayBuffer(25, 0, 0);
#endif
	// ----
	return false;

}

bool Interface::EventDrawMenu_Op2(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT2].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
	|| gInterface.CheckWindow(Warehouse)
	|| gInterface.CheckWindow(ChaosBox)
	|| gInterface.CheckWindow(Store)
	|| gInterface.CheckWindow(OtherStore)
	|| gInterface.CheckWindow(ExpandInventory)
	|| gInterface.CheckWindow(Shop)
	|| gInterface.CheckWindow(Trade)
	|| gInterface.CheckWindow(LuckyCoin1)
	|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	//--
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT2))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT2].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT2].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT2].EventTick = GetTickCount();

	this->CloseCustomWindow();

	this->OpenVipWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op3(DWORD Event)
{
	
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT3].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
	|| gInterface.CheckWindow(Warehouse)
	|| gInterface.CheckWindow(ChaosBox)
	|| gInterface.CheckWindow(Store)
	|| gInterface.CheckWindow(OtherStore)
	|| gInterface.CheckWindow(ExpandInventory)
	|| gInterface.CheckWindow(Shop)
	|| gInterface.CheckWindow(Trade)
	|| gInterface.CheckWindow(LuckyCoin1)
	|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT3))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT3].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT3].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT3].EventTick = GetTickCount();

	this->CloseMenuWindow();

	SEND_GS_REQ pRequest;
	pRequest.h.set(0xFD, 0x21, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
	gRanking.Show = true;

	
	// ----
	return false;
	
}

bool Interface::EventDrawMenu_Op4(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT4].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
	|| gInterface.CheckWindow(Warehouse)
	|| gInterface.CheckWindow(ChaosBox)
	|| gInterface.CheckWindow(Store)
	|| gInterface.CheckWindow(OtherStore)
	|| gInterface.CheckWindow(ExpandInventory)
	|| gInterface.CheckWindow(Shop)
	|| gInterface.CheckWindow(Trade)
	|| gInterface.CheckWindow(LuckyCoin1)
	|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT4))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT4].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT4].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT4].EventTick = GetTickCount();

	this->CloseMenuWindow();

#if(DANH_HIEU_NEW == 1)
	G_BEXO_DANH_HIEU.OPEN_WINDOW_DANH_HIEU();
	G_BEXO_DANH_HIEU.BUY_DANH_HIEU(2);
	PlayBuffer(25, 0, 0);
#endif
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op5(DWORD Event)
{

	//if(gProtect.m_MainInfo.MenuButtons[n] == 1)
		
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT5].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
	|| gInterface.CheckWindow(Warehouse)
	|| gInterface.CheckWindow(ChaosBox)
	|| gInterface.CheckWindow(Store)
	|| gInterface.CheckWindow(OtherStore)
	|| gInterface.CheckWindow(ExpandInventory)
	|| gInterface.CheckWindow(Shop)
	|| gInterface.CheckWindow(Trade)
	|| gInterface.CheckWindow(LuckyCoin1)
	|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT5))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT5].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT5].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT5].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gCustomJewelBank.OpenWindow();
	// ----

	return false;

}


bool Interface::EventDrawMenu_Op6(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT6].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
	|| gInterface.CheckWindow(Warehouse)
	|| gInterface.CheckWindow(ChaosBox)
	|| gInterface.CheckWindow(Store)
	|| gInterface.CheckWindow(OtherStore)
	|| gInterface.CheckWindow(ExpandInventory)
	|| gInterface.CheckWindow(Shop)
	|| gInterface.CheckWindow(Trade)
	|| gInterface.CheckWindow(LuckyCoin1)
	|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT6))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT6].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT6].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT6].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gInterface.Data[eCHANGINGCLASS_MAIN].Open();

	
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op7(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT7].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
	|| gInterface.CheckWindow(Warehouse)
	|| gInterface.CheckWindow(ChaosBox)
	|| gInterface.CheckWindow(Store)
	|| gInterface.CheckWindow(OtherStore)
	|| gInterface.CheckWindow(ExpandInventory)
	|| gInterface.CheckWindow(Shop)
	|| gInterface.CheckWindow(Trade)
	|| gInterface.CheckWindow(LuckyCoin1)
	|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT7))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT7].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT7].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT7].EventTick = GetTickCount();

	this->CloseMenuWindow();

	if (GetForegroundWindow() == pGameWindow)
	{
		gPartySearch.SwitchPartySettingsWindowState();
	}
	// ----
	return false;
}
bool Interface::EventDrawMenu_Op8(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT8].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
	|| gInterface.CheckWindow(Warehouse)
	|| gInterface.CheckWindow(ChaosBox)
	|| gInterface.CheckWindow(Store)
	|| gInterface.CheckWindow(OtherStore)
	|| gInterface.CheckWindow(ExpandInventory)
	|| gInterface.CheckWindow(Shop)
	|| gInterface.CheckWindow(Trade)
	|| gInterface.CheckWindow(LuckyCoin1)
	|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT8))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT8].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT8].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT8].EventTick = GetTickCount();

	this->CloseMenuWindow();



	//gPartySearch.SwitchPartySearchWindowState();
	if (GetForegroundWindow() == pGameWindow)
	{
		UP_PARTYSEARCH_REQ pMsg;
		pMsg.h.set(0xF3, 0x25, sizeof(pMsg));
		DataSend((BYTE*)&pMsg, pMsg.h.size);
		pSetCursorFocus = false;
	}

	return false;
}

bool Interface::EventDrawMenu_Op9(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT9].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
	|| gInterface.CheckWindow(Warehouse)
	|| gInterface.CheckWindow(ChaosBox)
	|| gInterface.CheckWindow(Store)
	|| gInterface.CheckWindow(OtherStore)
	|| gInterface.CheckWindow(ExpandInventory)
	|| gInterface.CheckWindow(Shop)
	|| gInterface.CheckWindow(Trade)
	|| gInterface.CheckWindow(LuckyCoin1)
	|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT9))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT9].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT9].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT9].EventTick = GetTickCount();

	this->CloseMenuWindow();

	if (GetForegroundWindow() == pGameWindow)
	{
		gInterface.Data[eWindow_SkinModel].OnShow ^= 1;
		gInterface.Data[eWindow_SkinModel].EventTick = GetTickCount();
	}
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op10(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT10].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
	|| gInterface.CheckWindow(Warehouse)
	|| gInterface.CheckWindow(ChaosBox)
	|| gInterface.CheckWindow(Store)
	|| gInterface.CheckWindow(OtherStore)
	|| gInterface.CheckWindow(ExpandInventory)
	|| gInterface.CheckWindow(Shop)
	|| gInterface.CheckWindow(Trade)
	|| gInterface.CheckWindow(LuckyCoin1)
	|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT10))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT10].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT10].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT10].EventTick = GetTickCount();

	this->CloseMenuWindow();
#if(B_HON_HOAN)
	if (GetForegroundWindow() == pGameWindow)
	{
		//==Open Window hon Hoan
		XULY_CGPACKET pMsg;
		pMsg.header.set(0xD3, 0x01, sizeof(pMsg));
		pMsg.ThaoTac = 1;
		DataSend((LPBYTE)& pMsg, pMsg.header.size);
	}
#endif
	// ----
	return false;
}



bool Interface::EventDrawMenu_Op11(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT11].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT11))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT11].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT11].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT11].EventTick = GetTickCount();

	this->CloseMenuWindow();

	if (GetForegroundWindow() == pGameWindow)
	{
		gInterface.SwitchOffExpWindoState();

		//G_BEXO_VIPNHANVAT.OPEN_WINDOW_VIPNHANVAT();

	}
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op12(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT12].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT12))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT12].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT12].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT12].EventTick = GetTickCount();

	this->CloseMenuWindow();

	if (GetForegroundWindow() == pGameWindow && gInterface.Data[eWindow_QuanLyBuffPhe].OnShow == 0)
	{
		//==Open Window Buff Phe
		XULY_CGPACKET pMsg;
		pMsg.header.set(0xD3, 0x05, sizeof(pMsg));
		pMsg.ThaoTac = 1;
		DataSend((LPBYTE)& pMsg, pMsg.header.size);
	}
	// ----
	return false;
}


bool Interface::EventDrawMenu_Op20(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT20].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT20))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT20].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT20].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT20].EventTick = GetTickCount();

	this->CloseMenuWindow();

	this->OpenWindow(ObjWindow::Options);
	// ----
	return false;
}



bool Interface::MiniMapCheck()
{
	bool visual = false;

	if ( gInterface.CheckWindow(13) && gInterface.CheckWindow(Character)
    || gInterface.CheckWindow(8)
    || gInterface.CheckWindow(12)
    || gInterface.CheckWindow(9)
    || gInterface.CheckWindow(7)
    || gInterface.CheckWindow(14)
    || gInterface.CheckWindow(15)
    || gInterface.CheckWindow(60)
    || gInterface.CheckWindow(76) )
	{
		visual = true;
	}
	else
	{
		if ( gInterface.CheckWindow(16) && (gInterface.CheckWindow(4)||gInterface.CheckWindow(69)) )
		{
			visual = true;
		}
		else
		{
			if ( gInterface.CheckWindow(16) && gInterface.CheckWindow(11) )
			{
				visual = true;
			}
			else
			{
				if ( gInterface.CheckWindow(27) )
				{
					visual = true;
				}
				else
				{
					if ( gInterface.CheckWindow(13)
					|| gInterface.CheckWindow(16)
					|| gInterface.CheckWindow(3)
					|| gInterface.CheckWindow(21)
					|| gInterface.CheckWindow(6)
					|| gInterface.CheckWindow(22)
					|| gInterface.CheckWindow(23)
					|| gInterface.CheckWindow(24)
					|| gInterface.CheckWindow(4)
					|| gInterface.CheckWindow(18)
					|| gInterface.CheckWindow(10)
					|| gInterface.CheckWindow(5)
					|| gInterface.CheckWindow(25)
					|| gInterface.CheckWindow(26)
					|| gInterface.CheckWindow(19)
					|| gInterface.CheckWindow(20)
					|| gInterface.CheckWindow(58)
					|| gInterface.CheckWindow(59)
					|| gInterface.CheckWindow(62)
					|| gInterface.CheckWindow(73)
					|| gInterface.CheckWindow(68)
					|| gInterface.CheckWindow(69)
					|| gInterface.CheckWindow(70)
					|| gInterface.CheckWindow(66)
					|| gInterface.CheckWindow(75)
					|| gInterface.CheckWindow(74) )
					{
						visual = true;
					}
					else
					{
						if ( gInterface.CheckWindow(79) )
						{
							if ( gInterface.CheckWindow(80) )
							{
								visual = true;
							}
							else
							{
								visual = true;
							}	
						}
					}
				}
			}
		}
	}
  
	if ( gInterface.CheckWindow(77) )
	{
		if ( gInterface.CheckWindow(Warehouse) ||
			gInterface.CheckWindow(ChaosBox) ||
			gInterface.CheckWindow(Store) ||
			gInterface.CheckWindow(OtherStore) ||
			gInterface.CheckWindow(Character))
		{
			visual = true;
		}
		else
		{
			visual = true;
		}
	}
	else if ( gInterface.CheckWindow(78) )
	{
			visual = true;
	}
	return visual;
}

bool Interface::CombinedChecks()
{
	if ((this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Character)
		&& this->CheckWindow(Store)))
		return true;
	return false;
}

//bool Interface::CheckMap()
//{
//	switch(gObjUser.m_MapNumber)
//	{
//		case eMapNumber::Lorencia:
//			return false;
//			break;
//		case eMapNumber::Dungeon:
//			return false;
//			break;
//		case eMapNumber::Devias:
//			return false;
//			break;
//		case eMapNumber::Noria:
//			return false;
//			break;
//		case eMapNumber::LostTower:
//			return false;
//			break;
//		case eMapNumber::Stadium:
//			return false;
//		case eMapNumber::Atlans:
//			return false;
//			break;
//		case eMapNumber::Tarkan:
//			return false;
//			break;
//		case eMapNumber::Elbeland:
//			return false;
//			break;
//		case eMapNumber::Icarus:
//			return false;
//			break;
//		case eMapNumber::Trials:
//			return false;
//			break;
//		case eMapNumber::Aida:
//			return false;
//			break;
//		case eMapNumber::Crywolf:
//			return false;
//			break;
//		case eMapNumber::Kanturu1:
//			return false;
//			break;
//		case eMapNumber::Kanturu3:
//			return false;
//			break;
//		case eMapNumber::Barracks:
//			return false;
//			break;
//		case eMapNumber::Calmness:
//			return false;
//			break;
//		case eMapNumber::Raklion:
//			return false;
//			break;
//		case eMapNumber::Vulcanus:
//			return false;
//			break;
//		case eMapNumber::Karutan1:
//			return false;
//			break;
//		case eMapNumber::Karutan2:
//			return false;
//			break;
//		default:
//			return true;
//			break;
//	}
//}

void Interface::CloseCustomWindow()
{
	this->CloseMenuWindow();
	this->CloseVipWindow();
	this->Data[eRankPANEL_MAIN].OnShow		= false;
	this->Data[eEventTimePANEL_MAIN].OnShow = false;
	this->Data[eCommand_MAIN].OnShow		= false;
	//this->Data[eJewelsBank].OnShow			= false;




	
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
}

void Interface::DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store)) 
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		return;
	}

	pSetBlend(true);
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);

	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;

	if (ItemID == 406)
	{
		sub_6358A0_Addr(0.4, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else if (ItemID == 407)
	{
		sub_6358A0_Addr(0.5, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else
	{
		sub_6358A0_Addr(0.7, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0); 
	sub_635DE0_Addr();
	sub_635E40_Addr();

	glClear(0x100);

	VAngle v45;

	unsigned __int8 v44 = 1; //0 = parado / 1 = girando

	sub_6359B0_Addr(PosX, PosY, (int)&v45, 0); //vi tri bmd
	sub_5CA0D0_Addr(ItemID, Level, Excl, Anc, (int)&v45, v44, 0); //chức năng hiển thị BMD
	
	sub_636720_Addr();

	glMatrixMode(0x1700);
	glPopMatrix();
	glMatrixMode(0x1701);
	glPopMatrix();

	sub_637770_Addr();

	glColor3f(1,1,1);
	pSetBlend(false);
}

void Interface::DrawConfirmOpen()
{
	if(!this->CheckWindow(Shop) && this->Data[eCONFIRM_MAIN].OnShow == true)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_OK].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_CANCEL].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if( !this->Data[eCONFIRM_MAIN].OnShow )
	{
		return;
	}

	float StartX;
	if( gProtect.m_MainInfo.CustomInterfaceType == 3 )
	{
		StartX = 205.0f;
	}
	else
	{
		StartX = 25.0f;
	}

	float MainWidth			= 230.0;
	float MainHeight		= 130.0;
	float StartBody			= 90.0;
	float StartY			= 90.0;
	
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(66));

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 40, 210, 3, gCustomMessage.GetMessage(67));

	this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, 0);

	if( this->IsWorkZone(eCONFIRM_BTN_OK) )
	{
		int ScaleY = 30;
		// ----
		if( this->Data[eCONFIRM_BTN_OK].OnClick )
		{
			ScaleY = 60;
		}
		// ----
		this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, ScaleY);
	}

	this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, 0);

	if( this->IsWorkZone(eCONFIRM_BTN_CANCEL) )
	{
		int ScaleY = 30;
		// ----
		if( this->Data[eCONFIRM_BTN_CANCEL].OnClick )
		{
			ScaleY = 60;
		}
		// ----
		this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, ScaleY);
	}

}


bool Interface::EventConfirm_OK(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_OK].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_OK))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_OK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].EventTick = GetTickCount();

	PMSG_ITEM_BUY_RECV pMsg;

	pMsg.header.set(0xF3, 0xED,sizeof(pMsg));

	pMsg.slot = this->ConfirmSlot;

	DataSend((BYTE*)&pMsg,pMsg.header.size);

	this->Data[eCONFIRM_MAIN].OnShow = false;
	
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

bool Interface::EventConfirm_CANCEL(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_CANCEL].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_CANCEL))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_CANCEL].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].EventTick = GetTickCount();

	this->Data[eCONFIRM_MAIN].OnShow = false;

	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

//-- advance
void Interface::DrawBarForm(float PosX, float PosY, float Width, float Height, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(PosX, PosY, Width, Height, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}
// ----------------------------------------------------------------------------------------------
bool Interface::CheckWindowEx(int WindowID)
{
	if (WindowID < 0 || WindowID > MAX_WINDOW_EX)
	{
		return 0;
	}
	return this->WindowEx[WindowID];
}

//---- cosas peladas

void Interface::UPDATE_FPS(){
	gInterface.frameCount++;
	if (GetTickCount() - gInterface.lastReport >= 1000)
	{
		gInterface.frameRate = gInterface.frameCount / ((GetTickCount() - gInterface.lastReport) / 1000);
		sprintf(gInterface.FPS_REAL, "FPS: %d", gInterface.frameRate);
		gInterface.lastReport = GetTickCount();
		gInterface.frameCount = 0;
	}

	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop) )
	{
		return;
	}

	this->DrawFormat(eGold, 600, 5, 80, 1, gInterface.FPS_REAL);
}

void Interface::guiMonitore(){
	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(460.0, 0.0, 180.0, 20.0, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}

void Interface::DrawPing()
{
	gInterface.msPing = GetTickCount() - gInterface.lastSend;
	gInterface.iniciador = 3;
}

struct PMSG_PING
{
	PBMSG_HEAD h;
};

void Interface::SendPingRecv()
{
	if(gInterface.iniciador == 1)
	{
		PMSG_PING pMsgPing;
		pMsgPing.h.set(0xFF,sizeof(pMsgPing));
		gInterface.lastSend = GetTickCount();
		DataSend((BYTE*)&pMsgPing,sizeof(pMsgPing));
		gInterface.iniciador=2;
	}
	else if(gInterface.iniciador == 3)
	{
		if (GetTickCount() >= gInterface.lastSend + 1000){
			PMSG_PING pMsgPing;
			pMsgPing.h.set(0xFF,sizeof(pMsgPing));
			gInterface.lastSend = GetTickCount();
			DataSend((BYTE*)&pMsgPing,sizeof(pMsgPing));
			gInterface.iniciador=2;
		}
	}

	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}
	sprintf(gInterface.ServerRTT, "RTT: %d ms", gInterface.msPing);
	sprintf(gInterface.ServerPing, "PING: %d ms", (gInterface.msPing/2));
	// ----
	gInterface.validar=0;

	if(gInterface.msPing > 0){
		//----
		this->DrawFormat(eGold, 470, 5, 120, 1, gInterface.ServerRTT);
		this->DrawFormat(eGold, 530, 5, 120, 1, gInterface.ServerPing);
		//--
		sprintf(gInterface.ultimoRTT, gInterface.ServerRTT);
		sprintf(gInterface.ultimoPing, gInterface.ServerPing);
		//--
		gInterface.ultimo_RTT = gInterface.msPing;
		gInterface.validar=1;
	}

	if(gInterface.validar==0)
	{
		if(gInterface.ultimo_RTT > 0)
		{
			this->DrawFormat(eGold, 470, 5, 80, 1, gInterface.ultimoRTT);
			this->DrawFormat(eGold, 530, 5, 120, 1, gInterface.ultimoPing);
		}
		else
		{
			this->DrawFormat(eGold, 470, 5, 120, 1, gInterface.ServerRTT);
			this->DrawFormat(eGold, 530, 5, 120, 1, gInterface.ServerPing);
		}
	}
}

void Interface::SwitchChatExpand()
{

	if((GetTickCount() - gInterface.Data[chatbackground].EventTick) < 1000 ||this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[chatbackground].EventTick = GetTickCount();

	if (SeparateChat != 0)
	{
		gInterface.DrawMessage(1, "Chat Window Separate [OFF]");
		SeparateChat = 0;
		WritePrivateProfileStringA("Setting","SeparateChat","0","./Settings.ini");
	}
	else 
	{
		gInterface.DrawMessage(1, "Chat Window Separate [ON]");
		SeparateChat = 1;
		WritePrivateProfileStringA("Setting","SeparateChat","1","./Settings.ini");
	}
		gChatExpanded.Switch();
}

void Interface::SwitchHideDanhHieu()
{
	if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	if (MinimizarOfRank == 0)
	{
		MinimizarOfRank = 1;
		pDrawMessage("Ẩn Danh Hiệu: [Tắt]", 1);
	}
	else
	{
		MinimizarOfRank = 0;
		pDrawMessage("Ẩn Danh Hiệu: [Bật]", 1);
	}
}

void Interface::OpenConfig(int type)
{
	if(type == 0)
	{
		if( (GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400 
			|| this->CheckWindow(ChatWindow) 
			|| this->CheckWindow(MuHelper) 
			|| this->CheckWindow(Inventory) 
			|| this->CheckWindow(Store) 
			|| this->CheckWindow(Character) 
			|| this->CheckWindow(CreateGuild) )
		{
			return;
		}

		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (pCheckWindow(pWindowThis(), 35))
		{
			pCloseWindow(pWindowThis(), 35);
		}
		else 
		{
			pOpenWindow(pWindowThis(), 35);
		}
	}
	else if(type == 1 )
	{
		if( (GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400 || OpenSwicthSkill == 0)
		{
			return;
		}

		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (SkillPage == 1)
		{
			SkillPage = 2;
		}
		else
		{
			SkillPage = 1;
		}
	}

	PlayBuffer(25, 0, 0);
}
//-- SwitchCamera
void Interface::SwitchCamera()
{

	if(gProtect.m_MainInfo.DisableHelper == 0)
	{
		if( (GetTickCount() - gInterface.Data[eCamera3DSwitch].EventTick) < 1000 )
		{
			return;
		}

		if( pMapNumber == 62 )
		{
			gInterface.DrawMessage(1, CameraNotAc);
			gCamera.Restore();
		}

		gInterface.Data[eCamera3DSwitch].EventTick = GetTickCount();

		gCamera.Toggle();

		if (gCamera.getEnabled())
		{
			gInterface.DrawMessage(1, CameraOn);
		}
		else
		{
			gInterface.DrawMessage(1, CameraOff);
		}
	}
}

//gym chuot
//-- CameraInit
void Interface::CameraInit(){

	if((GetTickCount() - gInterface.Data[eCamera3DInit].EventTick) < 1000 )
	{
		return;
	}

	gInterface.Data[eCamera3DInit].EventTick = GetTickCount();

	if (gCamera.getEnabled())
	{
		gInterface.DrawMessage(1, CameraDefault);
		gCamera.Restore();
	}
}

bool Interface::Button(DWORD Event, int WinID, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if (Event == WM_LBUTTONDOWN  && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
	}

	if (Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

void Interface::DrawInterfaceS2Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 433, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 457, 0.0, 0.0);
	}
	if (IsWorkZone(eFastMenu))
	{
		this->DrawToolTip(13, 420, "System");
	}
	if (this->CheckWindow(FastMenu))
	{
		gInterface.DrawButton(eFastMenu, 6, 433, 0.0, 0.0);
	}
}
//--------------------------------------
void Interface::DrawInterface97Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 433, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 457, 0.0, 0.0);
	}
}
//--------------------------------------
void Interface::EventNewInterface_All(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}
	
	if (IsWorkZone(eFastMenu))
	{
		DWORD Delay = (CurrentTick - this->Data[eFastMenu].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFastMenu].OnClick = true;
			return;
		}
		this->Data[eFastMenu].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFastMenu].EventTick = GetTickCount();
		if (this->CheckWindow(FastMenu)) {
				this->CloseWindow(FastMenu);
		}
		else {
			this->OpenWindow(FastMenu);
		}
	}
	else if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}
	
	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory)) {
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList)) {
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild)) {
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}
void Interface::EventNewInterface97_All(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}
	
	if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}
	
	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory))
		{
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList))
		{
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild))
		{
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}

void Interface::DrawInterfaceDragonLS3()
{
	if(this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::FullMap)
		|| this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::MoveList)
		)
	{
		return;
	}
	this->DrawGUI(eDragonLeft, this->Data[eDragonLeft].X, this->Data[eDragonLeft].Y);
}

void Interface::DrawInterfaceDragonRS3()
{	
	if (this->MiniMapCheck()||(this->CheckWindow(SkillTree)|| this->CheckWindow(CashShop) || this->CheckWindow(FullMap)
		||this->CheckWindow(FastMenu)||this->CheckWindow(FriendList))
		|| pMapNumber == 39 //Kanturu
		|| pMapNumber == 58 //Selupam
		|| pMapNumber == 64 //Duel Arena
		|| pMapNumber == 65 //Doppelganger
		|| pMapNumber == 66 //Doppelganger
		|| pMapNumber == 67 //Doppelganger
		|| pMapNumber == 68 //Doppelganger
		|| pMapNumber == 69 //Imperial Guardian
		|| pMapNumber == 70 //Imperial Guardian
		|| pMapNumber == 71 //Imperial Guardian
		|| pMapNumber == 72 //Imperial Guardian
		|| pMapNumber == 11	//Blood Castle
		|| pMapNumber == 12	//Blood Castle
		|| pMapNumber == 13	//Blood Castle
		|| pMapNumber == 14	//Blood Castle
		|| pMapNumber == 15	//Blood Castle
		|| pMapNumber == 16	//Blood Castle
		|| pMapNumber == 17	//Blood Castle
		|| pMapNumber == 52	//Blood Castle
		|| pMapNumber == 9	//Devil Square
		|| pMapNumber == 32	//Devil Square
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 45	//Illusion Temple
		|| pMapNumber == 46	//Illusion Temple
		|| pMapNumber == 47	//Illusion Temple
		|| pMapNumber == 48	//Illusion Temple
		|| pMapNumber == 49	//Illusion Temple
		|| pMapNumber == 50	//Illusion Temple
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 34 //Crywolf
		|| pMapNumber == 30 //Valley/CastleSiege
		|| pMapNumber == 65 /*DuelArena*/)
	{
		return;
	}
	this->DrawGUI(eDragonRight, this->Data[eDragonRight].X, this->Data[eDragonRight].Y);
}

void Interface::DrawCoord()
{
	gObjUser.Refresh();

	if (*(DWORD*)MAIN_SCREEN_STATE == 5)
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		pDrawInterfaceNumBer(22, 461, gObjUser.lpViewPlayer->MapPosX, 1);
		pDrawInterfaceNumBer(46, 461, gObjUser.lpViewPlayer->MapPosY, 1);

	}
}



int Interface::DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	char Buff2[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----

	int LineCount = 0;

	strcpy(Buff2, Buff);

	char* Line = strtok(Buff2, "\n");
	// ----
	while (Line != NULL)
	{
		LineCount++;
		Line = strtok(NULL, "\n");
	}

	pSetBlend(true);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	pDrawBarForm(PosX, PosY, Width, LineCount * 10, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();

	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);

	this->DrawText(eWhite, PosX, PosY, Width, Align, Buff);
	return 0;
}
void Interface::DrawText(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...) // OK
{
	char Buff[2048];
	const int BuffLen = sizeof(Buff) - 1;
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	char* Line = strtok(Buff, "\n");

	while (Line != nullptr)
	{
		DrawInterfaceText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
}



bool Interface::ButtonEx(DWORD Event, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if (Event == WM_LBUTTONDOWN && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
		//return false;
	}

	if (Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

#if(VONGQUAY_NEW)

void testfunc()
{
	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();
}

void Interface::DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{

	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	//float X = ull_to_float2(*(QWORD*)0xE61E58);
	//float Y = ull_to_float2(*(QWORD*)0xE61E58+1);

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);
	//float v2 = (X / (Y / 100.0f)) / 100.0f;//(*(float*)MAIN_RESOLUTION_X / (*(float*)MAIN_RESOLUTION_Y / 100.0f)) / 100.0f;
	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;
	sub_6358A0_Addr(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C);

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();


	pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);

	testfunc();
	//sub_637770_Addr();

	glColor3f(1, 1, 1);
	pSetBlend(false);
}
#endif
//void Interface::DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
//{
//    glMatrixMode(0x1701);
//    glPushMatrix();
//    glLoadIdentity();
//
//    sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);
//
//    float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;
//    sub_6358A0_Addr(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C);
// 
//    glMatrixMode(0x1700);
//    glPushMatrix();
//    glLoadIdentity();
// 
//    sub_635830_Addr((LPVOID)0x87933A0);
//    sub_635DE0_Addr();
//    sub_635E40_Addr();
// 
//    pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);
//   
//	glMatrixMode(0x1700u);
//    glPopMatrix();
//    glMatrixMode(0x1701u);
//    glPopMatrix();
//
//    glColor3f(1,1,1);
//    pSetBlend(false);
//}

void Interface::LoadImages2(char * Folder, int Code, int Arg3, int Arg4, int Arg5)
{
	pLoadImage(Folder, Code, Arg3, Arg4, Arg5,0);
}
void Interface::DrawWindow(int ObjMain, int ObjTitle, int ObjFrame, int ObjFooter, int Repeat, float X, float Y, char* Text)
{
	float StartY = Y;
	float StartX = X;

	gInterface.DrawGUI(ObjMain, StartX, StartY + 2);
	gInterface.DrawGUI(ObjTitle, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(ObjFrame, StartX, StartY + 67.0, Repeat);
	gInterface.DrawGUI(ObjFooter, StartX, StartY);

	gInterface.DrawFormat(eGold, StartX + 10, Y + 10, 210, 3, Text);
}

#if (DOI_GIOI_TINH)
void Interface::DrawChangingClassWindow()
{
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;
	// ----
	DWORD ItemNameColor = eWhite;
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	this->DrawGUI(eCHANGINGCLASS_MAIN, StartX, this->Data[eCHANGINGCLASS_MAIN].Y + 100);

	//pDrawGUFULL(0x9333, StartX - 34, StartY - 10, 300, 250, 0, 0, 1, 1, 1, 1, 0.0); // MENU

	gCItemSetOption.ItemTooltipS15(StartX + 0, gInterface.Data[eCHANGINGCLASS_MAIN].Y + 1, 225, 260, 0.0, 0);
	gCItemSetOption.ItemTooltipS15(StartX + 0, gInterface.Data[eCHANGINGCLASS_MAIN].Y + 1, 225, 260, 0.0, 0);

	this->DrawGUI(eCHANGINGCLASS_CLOSE, StartX + 205, this->Data[eCHANGINGCLASS_MAIN].Y + 0);
	// ----
	if (this->IsWorkZone(eCHANGINGCLASS_CLOSE))
	{
		DWORD Color = eGray150;
		this->DrawColoredGUI(eCHANGINGCLASS_CLOSE, this->Data[eCHANGINGCLASS_CLOSE].X, this->Data[eCHANGINGCLASS_CLOSE].Y, Color);
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, 105, 210, 3, "Đổi Giới Tính");
	// ----

	this->DrawGUI(eCHANGINGCLASS_MONEYBG, StartX + 30, this->Data[eCHANGINGCLASS_MAIN].Y + 190);
	this->DrawFormat(eWhite, StartX + 10, this->Data[eCHANGINGCLASS_MAIN].Y + 195, 210, 3, "WCoinC = %d", gChangeClass.m_WCoinC);
	// ----

	// ----
	this->DrawGUI(eCHANGINGCLASS_DW, ButtonX - 57, this->Data[eCHANGINGCLASS_MAIN].Y + 30);

	this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 40, 210, 3, "%s", pGetTextLine(pTextLineThis, 20));
	//pGetTextLine
	// ----
	this->DrawGUI(eCHANGINGCLASS_DK, ButtonX + 52, this->Data[eCHANGINGCLASS_MAIN].Y + 30);
	this->DrawFormat(eWhite, StartX + 62, this->Data[eCHANGINGCLASS_MAIN].Y + 40, 210, 3, "%s", pGetTextLine(pTextLineThis, 21));
	// ----
	this->DrawGUI(eCHANGINGCLASS_ELF, ButtonX - 57, this->Data[eCHANGINGCLASS_MAIN].Y + 60);
	this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 70, 210, 3, "%s", pGetTextLine(pTextLineThis, 22));
	// ----
	this->DrawGUI(eCHANGINGCLASS_MG, ButtonX + 52, this->Data[eCHANGINGCLASS_MAIN].Y + 60);
	this->DrawFormat(eWhite, StartX + 62, this->Data[eCHANGINGCLASS_MAIN].Y + 70, 210, 3, "%s", pGetTextLine(pTextLineThis, 23));
	// ----
	this->DrawGUI(eCHANGINGCLASS_DL, ButtonX - 57, this->Data[eCHANGINGCLASS_MAIN].Y + 90);
	this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 100, 210, 3, "%s", pGetTextLine(pTextLineThis, 24));
	// ----
	if (gProtect.m_MainInfo.CharsCount >= 6)
	{
		this->DrawGUI(eCHANGINGCLASS_SUM, ButtonX + 52, this->Data[eCHANGINGCLASS_MAIN].Y + 90);
		this->DrawFormat(eWhite, StartX + 62, this->Data[eCHANGINGCLASS_MAIN].Y + 100, 210, 3, "%s", pGetTextLine(pTextLineThis, 1687));
	}
	// ----
	if (gProtect.m_MainInfo.CharsCount >= 7)
	{
		this->DrawGUI(eCHANGINGCLASS_RF, ButtonX, this->Data[eCHANGINGCLASS_MAIN].Y + 120);
		this->DrawFormat(eWhite, StartX + 8, this->Data[eCHANGINGCLASS_MAIN].Y + 130, 210, 3, "%s", pGetTextLine(pTextLineThis, 3150));
	}
	// ----
	this->DrawGUI(eCHANGINGCLASS_DIV, StartX, this->Data[eCHANGINGCLASS_MAIN].Y + 150);
	// ----
	this->Data[eCHANGINGCLASS_DW].Attribute = true;
	this->Data[eCHANGINGCLASS_DK].Attribute = true;
	this->Data[eCHANGINGCLASS_ELF].Attribute = true;
	this->Data[eCHANGINGCLASS_MG].Attribute = true;
	this->Data[eCHANGINGCLASS_DL].Attribute = true;
	this->Data[eCHANGINGCLASS_SUM].Attribute = true;
	this->Data[eCHANGINGCLASS_RF].Attribute = true;
	// ----
	if (IsWorkZone(eCHANGINGCLASS_DW))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_DW].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_DW, this->Data[eCHANGINGCLASS_DW].X, this->Data[eCHANGINGCLASS_DW].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_DK))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_DK].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_DK, this->Data[eCHANGINGCLASS_DK].X, this->Data[eCHANGINGCLASS_DK].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_ELF))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_ELF].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_ELF, this->Data[eCHANGINGCLASS_ELF].X, this->Data[eCHANGINGCLASS_ELF].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_MG))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_MG].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_MG, this->Data[eCHANGINGCLASS_MG].X, this->Data[eCHANGINGCLASS_MG].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_DL))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_DL].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_DL, this->Data[eCHANGINGCLASS_DL].X, this->Data[eCHANGINGCLASS_DL].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_SUM))
	{
		if (gProtect.m_MainInfo.CharsCount >= 6)
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eCHANGINGCLASS_SUM].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eCHANGINGCLASS_SUM, this->Data[eCHANGINGCLASS_SUM].X, this->Data[eCHANGINGCLASS_SUM].Y, Color);
		}
	}
	if (IsWorkZone(eCHANGINGCLASS_RF))
	{
		if (gProtect.m_MainInfo.CharsCount >= 7)
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eCHANGINGCLASS_RF].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eCHANGINGCLASS_RF, this->Data[eCHANGINGCLASS_RF].X, this->Data[eCHANGINGCLASS_RF].Y, Color);
		}
	}

}
// ----------------------------------------------------------------------------------------------

bool Interface::EventChangingClassWindow_Main(DWORD Event)
{
	this->EventChangingClassWindow_Close(Event);
	this->EventChangingClassWindow_DW(Event);
	this->EventChangingClassWindow_DK(Event);
	this->EventChangingClassWindow_ELF(Event);
	this->EventChangingClassWindow_MG(Event);
	this->EventChangingClassWindow_DL(Event);
	this->EventChangingClassWindow_SUM(Event);
	this->EventChangingClassWindow_RF(Event);
	return true;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventChangingClassWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_CLOSE].EventTick);
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_CLOSE].EventTick = GetTickCount();
	this->Data[eCHANGINGCLASS_MAIN].Close();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventChangingClassWindow_DW(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_DW].EventTick);
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_DW)
		|| !this->Data[eCHANGINGCLASS_DW].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_DW].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_DW].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_DW].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(0);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_DK(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_DK].EventTick);
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_DK)
		|| !this->Data[eCHANGINGCLASS_DK].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_DK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_DK].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_DK].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(16);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_ELF(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_ELF].EventTick);

	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_ELF)
		|| !this->Data[eCHANGINGCLASS_ELF].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_ELF].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_ELF].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_ELF].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(32);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_MG(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_MG].EventTick);
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_MG)
		|| !this->Data[eCHANGINGCLASS_MG].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_MG].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_MG].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_MG].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(48);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_DL(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_DL].EventTick);
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_DL)
		|| !this->Data[eCHANGINGCLASS_DL].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_DL].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_DL].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_DL].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(64);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_SUM(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_SUM].EventTick);
	// ----
	if (gProtect.m_MainInfo.CharsCount<6)
	{
		return false;
	}
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_SUM)
		|| !this->Data[eCHANGINGCLASS_SUM].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_SUM].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_SUM].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_SUM].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(80);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_RF(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_RF].EventTick);
	// ----
	if (gProtect.m_MainInfo.CharsCount<7)
	{
		return false;
	}
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_RF)
		|| !this->Data[eCHANGINGCLASS_RF].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_RF].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_RF].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_RF].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(96);
	// ----
	return false;
}
#endif

#if(OANTUTY)
void Interface::DrawRPS()
{
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

	if (this->CheckWindow(ObjWindow::Trade))
	{
		this->DrawGUI(eRock, StartX + 80, StartY + 85);
		this->DrawGUI(ePaper, StartX + 120, StartY + 85);
		this->DrawGUI(eScissors, StartX + 160, StartY + 85);

		if (this->IsWorkZone(eRock))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eRock].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eRock, this->Data[eRock].X, this->Data[eRock].Y, Color);
		}
		if (this->IsWorkZone(ePaper))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[ePaper].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(ePaper, this->Data[ePaper].X, this->Data[ePaper].Y, Color);
		}
		if (this->IsWorkZone(eScissors))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eScissors].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eScissors, this->Data[eScissors].X, this->Data[eScissors].Y, Color);
		}
		if (this->Data[eRock].Attribute == 1)
		{
			DWORD Color = eYellow;
			gInterface.DrawColoredGUI(eRock, gInterface.Data[eRock].X, gInterface.Data[eRock].Y, Color);
		}
		if (this->Data[ePaper].Attribute == 1)
		{
			DWORD Color = eYellow;
			gInterface.DrawColoredGUI(ePaper, gInterface.Data[ePaper].X, gInterface.Data[ePaper].Y, Color);
		}
		if (this->Data[eScissors].Attribute == 1)
		{
			DWORD Color = eYellow;
			gInterface.DrawColoredGUI(eScissors, gInterface.Data[eScissors].X, gInterface.Data[eScissors].Y, Color);
		}
	}
}

void Interface::EventRPS_Main(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if (!this->CheckWindow(ObjWindow::Trade))
	{
		return;
	}

	if (this->IsWorkZone(eRock))
	{
		DWORD Delay = (CurrentTick - this->Data[eRock].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eRock].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eRock].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eRock].EventTick = GetTickCount();
		//Func
		RPSMode(1);
		//pDrawMessage("Ban chon bua",1);
		this->Data[eRock].Attribute = 1;
		this->Data[ePaper].Attribute = 0;
		this->Data[eScissors].Attribute = 0;
	}
	//
	else if (this->IsWorkZone(ePaper))
	{
		DWORD Delay = (CurrentTick - this->Data[ePaper].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePaper].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[ePaper].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[ePaper].EventTick = GetTickCount();
		//Func
		RPSMode(2);
		//pDrawMessage("Ban chon bao",1);
		this->Data[eRock].Attribute = 0;
		this->Data[ePaper].Attribute = 1;
		this->Data[eScissors].Attribute = 0;
	}
	//
	else if (this->IsWorkZone(eScissors))
	{
		DWORD Delay = (CurrentTick - this->Data[eScissors].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eScissors].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eScissors].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eScissors].EventTick = GetTickCount();
		//Func
		this->Data[eRock].Attribute = 0;
		this->Data[ePaper].Attribute = 0;
		this->Data[eScissors].Attribute = 1;
		RPSMode(3);
		//pDrawMessage("Ban chon keo",1);
	}
}
#endif


#if(EXBEXO_LOAD_SEND_TINH_NANG)
void Interface::DRAW_TINHNANG_INTERFACE()
{

	if (gProtect.m_MainInfo.EnableNutC != 0)
	{

	float MainWidth = 30.0;
	float MainHeight = 20.0;
	float StartY = 20.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	if (this->CheckWindow(ObjWindow::Character))
	{
		// AutoReset
		this->DrawGUI(EXBEXO_AUTORESET_INTERFACE, StartX + 160, StartY + 52);
		//--------------------------------------------------------------------------------------------
		HFONT TextFontBold_Autoreset = CreateFontA(15, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
		pSetTextFont(pTextThis(), TextFontBold_Autoreset); //set font
		pSetTextColor(pTextThis(), 255, 255, 0, 255); // MÀU
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pDrawText(pTextThis(), 473, 77, gCustomMessage.GetMessage(160), 150, 0, (LPINT)0, 0); // "Tự động Reset"
		//Giải phóng
		DeleteObject(TextFontBold_Autoreset);
		//--------------------------------------------------------------------------------------------
		// QuestClass
		this->DrawGUI(EXBEXO_QUESTCLASS_INTERFACE, StartX + 239, StartY + 52);
		//--------------------------------------------------------------------------------------------
		HFONT TextFontBold_NhiemVu = CreateFontA(15, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
		pSetTextFont(pTextThis(), TextFontBold_NhiemVu); //set font
		pSetTextColor(pTextThis(), 0, 255, 255, 255); // MÀU
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pDrawText(pTextThis(), 558, 77, gCustomMessage.GetMessage(161), 150, 0, (LPINT)0, 0); // "Làm Nhiệm Vụ"
		//Giải phóng
		DeleteObject(TextFontBold_NhiemVu);
		//--------------------------------------------------------------------------------------------
		// OffAttack
		this->DrawGUI(EXBEXO_OFFATTACK_INTERFACE, StartX + 160, StartY + 74);
		//--------------------------------------------------------------------------------------------
		HFONT TextFontBold_OffAttack = CreateFontA(15, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
		pSetTextFont(pTextThis(), TextFontBold_OffAttack); //set font
		pSetTextColor(pTextThis(), 255, 0, 0, 255); // MÀU
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pDrawText(pTextThis(), 473, 100, gCustomMessage.GetMessage(162), 150, 0, (LPINT)0, 0); // "ATTACK"
		//Giải phóng
		DeleteObject(TextFontBold_OffAttack);
		//--------------------------------------------------------------------------------------------
		// UyThac
		this->DrawGUI(EXBEXO_UYTHAC_INTERFACE, StartX + 239, StartY + 74);
		//--------------------------------------------------------------------------------------------
		HFONT TextFontBold_UyThac = CreateFontA(15, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
		pSetTextFont(pTextThis(), TextFontBold_UyThac); //set font
		pSetTextColor(pTextThis(), 0, 255, 0, 255); // MÀU
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pDrawText(pTextThis(), 558, 100, gCustomMessage.GetMessage(163), 150, 0, (LPINT)0, 0); // "OFF ATTACK"
		//Giải phóng
		DeleteObject(TextFontBold_UyThac);
		//--------------------------------------------------------------------------------------------
		// TayDiem
		this->DrawGUI(EXBEXO_TAYDIEM_INTERFACE, StartX + 159, StartY + 351);
		//--------------------------------------------------------------------------------------------
		HFONT TextFontBold_TayDiem = CreateFontA(15, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
		pSetTextFont(pTextThis(), TextFontBold_TayDiem); //set font
		pSetTextColor(pTextThis(), 0, 255, 255, 255); // MÀU
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pDrawText(pTextThis(), 488, 377, gCustomMessage.GetMessage(164), 150, 0, (LPINT)0, 0); // "Tẩy Điểm"
		//Giải phóng
		DeleteObject(TextFontBold_TayDiem);
		//--------------------------------------------------------------------------------------------
		// TayDiemMaster
		this->DrawGUI(EXBEXO_TAYDIEMMASTER_INTERFACE, StartX + 239, StartY + 351);
		//--------------------------------------------------------------------------------------------
		HFONT TextFontBold_TayDiemMaster = CreateFontA(15, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
		pSetTextFont(pTextThis(), TextFontBold_TayDiemMaster); //set font
		pSetTextColor(pTextThis(), 0, 255, 255, 255); // MÀU
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pDrawText(pTextThis(), 565, 377, gCustomMessage.GetMessage(165), 150, 0, (LPINT)0, 0); // "Tẩy Điểm Master"
		//Giải phóng
		DeleteObject(TextFontBold_TayDiemMaster);
		//--------------------------------------------------------------------------------------------
	}
	//----------------------------------------------------------------------------------------------------------------------
	if (this->CheckWindow(ObjWindow::Character))
		if (gInterface.IsWorkZone(EXBEXO_AUTORESET_INTERFACE))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(EXBEXO_AUTORESET_INTERFACE, gInterface.Data[EXBEXO_AUTORESET_INTERFACE].X, gInterface.Data[EXBEXO_AUTORESET_INTERFACE].Y, Color);
		}
	//----------------------------------------------------------------------------------------------------------------------
	if (this->CheckWindow(ObjWindow::Character))
		if (gInterface.IsWorkZone(EXBEXO_QUESTCLASS_INTERFACE))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(EXBEXO_QUESTCLASS_INTERFACE, gInterface.Data[EXBEXO_QUESTCLASS_INTERFACE].X, gInterface.Data[EXBEXO_QUESTCLASS_INTERFACE].Y, Color);
		}
	//----------------------------------------------------------------------------------------------------------------------
	if (this->CheckWindow(ObjWindow::Character))
		if (gInterface.IsWorkZone(EXBEXO_OFFATTACK_INTERFACE))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(EXBEXO_OFFATTACK_INTERFACE, gInterface.Data[EXBEXO_OFFATTACK_INTERFACE].X, gInterface.Data[EXBEXO_OFFATTACK_INTERFACE].Y, Color);
		}
	//----------------------------------------------------------------------------------------------------------------------
	if (this->CheckWindow(ObjWindow::Character))
		if (gInterface.IsWorkZone(EXBEXO_UYTHAC_INTERFACE))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(EXBEXO_UYTHAC_INTERFACE, gInterface.Data[EXBEXO_UYTHAC_INTERFACE].X, gInterface.Data[EXBEXO_UYTHAC_INTERFACE].Y, Color);
		}
	//----------------------------------------------------------------------------------------------------------------------
	if (this->CheckWindow(ObjWindow::Character))
		if (gInterface.IsWorkZone(EXBEXO_TAYDIEM_INTERFACE))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(EXBEXO_TAYDIEM_INTERFACE, gInterface.Data[EXBEXO_TAYDIEM_INTERFACE].X, gInterface.Data[EXBEXO_TAYDIEM_INTERFACE].Y, Color);
		}
	//----------------------------------------------------------------------------------------------------------------------
	if (this->CheckWindow(ObjWindow::Character))
		if (gInterface.IsWorkZone(EXBEXO_TAYDIEMMASTER_INTERFACE))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(EXBEXO_TAYDIEMMASTER_INTERFACE, gInterface.Data[EXBEXO_TAYDIEMMASTER_INTERFACE].X, gInterface.Data[EXBEXO_TAYDIEMMASTER_INTERFACE].Y, Color);
		}
}
}

bool Interface::EVENT_TINHNANG_INTERFACE(DWORD Event)
{
	this->EVENT_AUTORESET_INTERFACE(Event);
	this->EVENT_LAMNHIEMVU_INTERFACE(Event);
	this->EVENT_OFFATTACK_INTERFACE(Event);
	this->EVENT_UYTHAC_INTERFACE(Event);
	this->EVENT_TAYDIEM_INTERFACE(Event);
	this->EVENT_TAYDIEM_MASTER_INTERFACE(Event);
	return true;
}
bool Interface::EVENT_AUTORESET_INTERFACE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[EXBEXO_AUTORESET_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Character) || !IsWorkZone(EXBEXO_AUTORESET_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EXBEXO_AUTORESET_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[EXBEXO_AUTORESET_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EXBEXO_AUTORESET_INTERFACE].EventTick = GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 0x23, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	//gInterface.CloseWindow(Character);

	return true;

}
// ----------------------------------------------------------------------------------------------
bool Interface::EVENT_LAMNHIEMVU_INTERFACE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[EXBEXO_QUESTCLASS_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Character) || !IsWorkZone(EXBEXO_QUESTCLASS_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EXBEXO_QUESTCLASS_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[EXBEXO_QUESTCLASS_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EXBEXO_QUESTCLASS_INTERFACE].EventTick = GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 0x24, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	//gInterface.CloseWindow(Character);
	return true;
}
// ----------------------------------------------------------------------------------------------
bool Interface::EVENT_OFFATTACK_INTERFACE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[EXBEXO_OFFATTACK_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Character) || !IsWorkZone(EXBEXO_OFFATTACK_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EXBEXO_OFFATTACK_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[EXBEXO_OFFATTACK_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EXBEXO_OFFATTACK_INTERFACE].EventTick = GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 0x25, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	//gInterface.CloseWindow(Character);
	return true;
}
// ----------------------------------------------------------------------------------------------
bool Interface::EVENT_UYTHAC_INTERFACE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[EXBEXO_UYTHAC_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Character) || !IsWorkZone(EXBEXO_UYTHAC_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EXBEXO_UYTHAC_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[EXBEXO_UYTHAC_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EXBEXO_UYTHAC_INTERFACE].EventTick = GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 0x26, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	//gInterface.CloseWindow(Character);
	return true;
}
// ----------------------------------------------------------------------------------------------
bool Interface::EVENT_TAYDIEM_INTERFACE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[EXBEXO_TAYDIEM_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Character) || !IsWorkZone(EXBEXO_TAYDIEM_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EXBEXO_TAYDIEM_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[EXBEXO_TAYDIEM_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EXBEXO_TAYDIEM_INTERFACE].EventTick = GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 0x27, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	//gInterface.CloseWindow(Character);
	return true;
}
// ----------------------------------------------------------------------------------------------
bool Interface::EVENT_TAYDIEM_MASTER_INTERFACE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[EXBEXO_TAYDIEMMASTER_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Character) || !IsWorkZone(EXBEXO_TAYDIEMMASTER_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EXBEXO_TAYDIEMMASTER_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[EXBEXO_TAYDIEMMASTER_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EXBEXO_TAYDIEMMASTER_INTERFACE].EventTick = GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 0x28, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	//gInterface.CloseWindow(Character);
	return true;
}
// ----------------------------------------------------------------------------------------------
#endif
DWORD	SetInvisibleEffect_PointerYYYYY;
DWORD	SetInvisibleEffect_BuffYYYYY;
DWORD	SetInvisibleEffect_PointerYYYY;
DWORD	SetInvisibleEffect_BuffYYYY;

__declspec(naked) void ItemInvisible11(){
	static DWORD m_aaaaab = 0x0060B37A;
	_asm{
		mov SetInvisibleEffect_BuffYYYYY, esi
			mov ecx, dword ptr ss : [ebp + 8]
			mov esi, dword ptr ds : [ecx + 0x30]
			mov SetInvisibleEffect_PointerYYYYY, esi
			mov esi, SetInvisibleEffect_BuffYYYYY
	}
	if (SetInvisibleEffect_PointerYYYYY != 0x1EA5
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 15)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 30)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 31)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 136)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 137)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 138)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 139)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 140)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 141)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 142)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 143)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 13)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 14)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 16)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 31)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 42)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 13)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 41)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 43)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 44))
	{
		_asm{
			jmp[m_aaaaab]
		}
	}
}
__declspec(naked) void ItemInvisible22(){
	static DWORD m_aaaaaa = 0x0060B41D;
	_asm{
		mov SetInvisibleEffect_BuffYYYY, esi
			mov ecx, dword ptr ss : [ebp + 8]
			mov esi, dword ptr ds : [ecx + 0x30]
			jmp[m_aaaaaa]
	}
}
DWORD	SetInvisibleEffect_PointerXXX;
DWORD	SetInvisibleEffect_BuffXXX;

Naked(InvisibleEffectXX){
	_asm{
		mov SetInvisibleEffect_BuffXXX, esi
			mov ecx, dword ptr ss : [ebp + 8]
			mov esi, dword ptr ds : [ecx + 0x30]
			mov SetInvisibleEffect_PointerXXX, esi
			mov esi, SetInvisibleEffect_BuffXXX
	}
	if (SetInvisibleEffect_PointerXXX == 0x1EA5 || SetInvisibleEffect_PointerXXX == ITEM2(13, 18)){
		_asm{
			mov SetInvisibleEffect_BuffXXX, 0x0060B37A
				jmp SetInvisibleEffect_BuffXXX
		}
	}
	else{
		_asm{
			mov SetInvisibleEffect_BuffXXX, 0x0060B41D
				jmp SetInvisibleEffect_BuffXXX
		}
	}
}

void InvisibleItem11(){
	SetCompleteHook(0xE9, 0x0060B36A, &ItemInvisible11);
}
void InvisibleItem22(){
	SetCompleteHook(0xE9, 0x0060B36A, &ItemInvisible22);
}
void InvisibleItemXX(){
	SetRange((LPVOID)0x0060B36A, 10, ASM::NOP); //12
	SetCompleteHook(0xE9, 0x0060B36A, &InvisibleEffectXX);
}


void Interface::SwitchAntiLag1()
{
	if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
	{
		if (AntiLag1 != 0)
		{
			gInterface.DrawMessage(1, "AntiLag 1 [OFF]");

			AntiLag1 = 0;
			SetByte(0x0074CD30, 0x55); //Enable Dynamic Effects
			SetByte(0x00771310, 0x55); //Enable Static Effects
			SetByte(0x00608200, 0x55); //Enable Glow Effects
			SetByte(0x00608FB0, 0x55); //Enable Skills Effects
			SetByte(0x005EDFE0, 0x55); //Enable Objects
			SetByte(0x0054A270, 0x55); //Shadows

		}
		else
		{
			gInterface.DrawMessage(1, "AntiLag 1 [ON]");
			AntiLag1 = 1;
			SetByte(0x0074CD30, 0xC3); //Disable Dynamic Effects
			SetByte(0x00771310, 0xC3); //Disable Static Effects
			SetByte(0x00608200, 0xC3); //Disable Glow Effects
			SetByte(0x00608FB0, 0xC3); //Disable Skills Effects
			SetByte(0x0054A270, 0xC3); //Disable Shadows
			
		}
	}
}

void Interface::SwitchAntiLag2()
{
	if (pPlayerState < GameProcess)
	{
		return;
	}
	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}
	if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
	{
		if (AntiLag2 != 0)
		{
			gInterface.DrawMessage(1, "AntiLag 2 [OFF]");

			AntiLag2 = 0;
			InvisibleItem22();
			InvisibleItemXX();
			//SetByte(0x005DE2B3 + 1, (this->AntiLag2 == 0) ? 0x85 : 0x84); // Ocultamos objetos del mapa
			SetByte((0x0074CD80 + 2), (this->AntiLag2 == 0) ? 1 : 0); // DisableDynamicEffect
			SetByte((0x00771359 + 3), (this->AntiLag2 == 0) ? 1 : 0); // DisableStaticEffect
			DisableGlowEffect == this->AntiLag2 == 1;
			DisableShadow = this->AntiLag2 == 1;
			SetCompleteHook(0xE8, 0x00588661, 0x005655C0); // Dis Wings
			SetCompleteHook(0xE8, 0x00576DDB, 0x005655C0); //Enable Weapons
			SetCompleteHook(0xE8, 0x005883F4, 0x005655C0); //Enable Weapons
			SetByte(0x0051EE20, 0x55); //Enable Cloaks
		}
		else
		{
			gInterface.DrawMessage(1, "AntiLag 2 [ON]");

			InvisibleItem11();
			//SetByte(0x005DE2B3 + 1, (this->AntiLag2 == 1) ? 0x85 : 0x84); // Ocultamos objetos del mapa
			SetByte((0x0074CD80 + 2), (this->AntiLag2 == 1) ? 1 : 0); // DisableDynamicEffect
			SetByte((0x00771359 + 3), (this->AntiLag2 == 1) ? 1 : 0); // DisableStaticEffect

			DisableGlowEffect == this->AntiLag2 == 0;
			DisableShadow = this->AntiLag2 == 0;

			MemorySet(0x00588661, 0x90, 0x05); // On Wing
			MemorySet(0x00576DDB, 0x90, 0x05); //Disable Weapons
			MemorySet(0x005883F4, 0x90, 0x05); //Disable Weapons
			SetByte(0x0051EE20, 0xC3); //Disable Cloaks

			AntiLag2 = 1;
		}
	}
}

void Interface::SwitchHidePlayer()
{
	if (pPlayerState < GameProcess)
	{
		return;
	}
	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}
	if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
	{
		if (AntiLagPlayer != 0)
		{
			gInterface.DrawMessage(1, "Ẩn nhân vật [OFF]");

			AntiLagPlayer = 0;
			DisablePlayer = this->AntiLagPlayer == 1;
		}
		else
		{
			gInterface.DrawMessage(1, "Ẩn nhân vật [ON]");

			DisablePlayer = this->AntiLagPlayer == 0;

			AntiLagPlayer = 1;
		}
	}
}
#if(NUT_TINH_NANG)

void Interface::DrawnNapThe()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (this->Data[eNAPTHE].OnShow)
	{
		this->Data[eNAPTHE].OnShow = false;
	}

	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))

	{
		return;
	}

	this->Data[eNAPTHE].OnShow = true;
}

bool Interface::EventDrawnNapThe_Open(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eNAPTHE].EventTick);
	// ----
	if (!this->Data[eNAPTHE].OnShow || !IsWorkZone(eNAPTHE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{

		//if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
		//{
		//	pSetCursorFocus = false;
		//}
		this->Data[eNAPTHE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eNAPTHE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}

	// ----
	this->Data[eNAPTHE].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow)
	{
		//ShellExecute(NULL, "open", "https://www.facebook.com/hieudaica2020/", NULL, NULL, SW_MAXIMIZE);
		ShellExecute(NULL, "open", gCustomMessage.GetMessage(85), NULL, NULL, SW_MAXIMIZE);

	}
	return false;
}

void Interface::DrawnFacebook()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (this->Data[eFACEBOOK].OnShow)
	{
		this->Data[eFACEBOOK].OnShow = false;
	}

	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}

	this->Data[eFACEBOOK].OnShow = true;
}

bool Interface::EventDrawnFacebook_Open(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eFACEBOOK].EventTick);
	// ----
	if (!this->Data[eFACEBOOK].OnShow || !IsWorkZone(eFACEBOOK))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{

		//if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
		//{
		//	pSetCursorFocus = false;
		//}
		this->Data[eFACEBOOK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eFACEBOOK].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}

	// ----
	this->Data[eFACEBOOK].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow)
	{
		//ShellExecute(NULL, "open", "https://www.facebook.com/hieudaica2020/", NULL, NULL, SW_MAXIMIZE);
		ShellExecute(NULL, "open", gCustomMessage.GetMessage(86), NULL, NULL, SW_MAXIMIZE);

	}

	return false;
}


//void Interface::DrawFanpage()
//{
//	//if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
//	//{
//	//	return;
//	//}
//
//	if (this->Data[eFANPAGE].OnShow)
//	{
//		this->Data[eFANPAGE].OnShow = false;
//	}
//
//	if (gInterface.CheckWindow(ObjWindow::CashShop)
//		|| gInterface.CheckWindow(ObjWindow::FriendList)
//		|| gInterface.CheckWindow(ObjWindow::MoveList)
//		|| gInterface.CheckWindow(ObjWindow::Party)
//		|| gInterface.CheckWindow(ObjWindow::Quest)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
//		|| gInterface.CheckWindow(ObjWindow::Guild)
//		|| gInterface.CheckWindow(ObjWindow::Trade)
//		|| gInterface.CheckWindow(ObjWindow::Warehouse)
//		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
//		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
//		|| gInterface.CheckWindow(ObjWindow::PetInfo)
//		|| gInterface.CheckWindow(ObjWindow::Shop)
//		|| gInterface.CheckWindow(ObjWindow::Inventory)
//		|| gInterface.CheckWindow(ObjWindow::Store)
//		|| gInterface.CheckWindow(ObjWindow::OtherStore)
//		|| gInterface.CheckWindow(ObjWindow::Character)
//		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
//		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
//		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
//		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
//		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
//		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
//		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
//		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
//		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
//		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
//		|| gInterface.CheckWindow(ObjWindow::HeroList)
//		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
//		|| gInterface.CheckWindow(ObjWindow::FastMenu)
//		|| gInterface.CheckWindow(ObjWindow::Options)
//		|| gInterface.CheckWindow(ObjWindow::Help)
//		|| gInterface.CheckWindow(ObjWindow::FastDial)
//		|| gInterface.CheckWindow(ObjWindow::SkillTree)
//		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
//		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
//		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
//		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
//		|| gInterface.CheckWindow(ObjWindow::CashShop)
//		|| gInterface.CheckWindow(ObjWindow::Lugard)
//		|| gInterface.CheckWindow(ObjWindow::QuestList1)
//		|| gInterface.CheckWindow(ObjWindow::QuestList2)
//		|| gInterface.CheckWindow(ObjWindow::Jerint)
//		|| gInterface.CheckWindow(ObjWindow::FullMap)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
//		|| gInterface.CheckWindow(ObjWindow::GensInfo)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
//		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
//		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
//		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
//		|| gInterface.CheckWindow(ObjWindow::MuHelper))
//	{
//		return;
//	}
//
//	this->Data[eFANPAGE].OnShow = true;
//}
//
//bool Interface::EventDrawFanpage_Open(DWORD Event)
//{
//	DWORD CurrentTick = GetTickCount();
//	DWORD Delay = (CurrentTick - this->Data[eFANPAGE].EventTick);
//	// ----
//	if (!this->Data[eFANPAGE].OnShow || !IsWorkZone(eFANPAGE))
//	{
//		return false;
//	}
//	// ----
//	if (Event == WM_LBUTTONDOWN)
//	{
//
//		//if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
//		//{
//		//	pSetCursorFocus = false;
//		//}
//		this->Data[eFANPAGE].OnClick = true;
//		return true;
//	}
//	// ----
//	this->Data[eFANPAGE].OnClick = false;
//	// ----
//	if (Delay < 500)
//	{
//		return false;
//	}
//
//	// ----
//	this->Data[eFANPAGE].EventTick = GetTickCount();
//
//	if (GetForegroundWindow() == pGameWindow)
//	{
//		//ShellExecute(NULL, "open", "https://www.facebook.com/MuOlnine2022", NULL, NULL, SW_MAXIMIZE);
//		ShellExecute(NULL, "open", gCustomMessage.GetMessage(87), NULL, NULL, SW_MAXIMIZE);
//	}
//
//	return false;
//}
//
//void Interface::DrawGoup()
//{
//	//if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
//	//{
//	//	return;
//	//}
//
//	if (this->Data[eGOUP].OnShow)
//	{
//		this->Data[eGOUP].OnShow = false;
//	}
//
//	if (gInterface.CheckWindow(ObjWindow::CashShop)
//		|| gInterface.CheckWindow(ObjWindow::FriendList)
//		|| gInterface.CheckWindow(ObjWindow::MoveList)
//		|| gInterface.CheckWindow(ObjWindow::Party)
//		|| gInterface.CheckWindow(ObjWindow::Quest)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
//		|| gInterface.CheckWindow(ObjWindow::Guild)
//		|| gInterface.CheckWindow(ObjWindow::Trade)
//		|| gInterface.CheckWindow(ObjWindow::Warehouse)
//		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
//		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
//		|| gInterface.CheckWindow(ObjWindow::PetInfo)
//		|| gInterface.CheckWindow(ObjWindow::Shop)
//		|| gInterface.CheckWindow(ObjWindow::Inventory)
//		|| gInterface.CheckWindow(ObjWindow::Store)
//		|| gInterface.CheckWindow(ObjWindow::OtherStore)
//		|| gInterface.CheckWindow(ObjWindow::Character)
//		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
//		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
//		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
//		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
//		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
//		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
//		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
//		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
//		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
//		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
//		|| gInterface.CheckWindow(ObjWindow::HeroList)
//		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
//		|| gInterface.CheckWindow(ObjWindow::FastMenu)
//		|| gInterface.CheckWindow(ObjWindow::Options)
//		|| gInterface.CheckWindow(ObjWindow::Help)
//		|| gInterface.CheckWindow(ObjWindow::FastDial)
//		|| gInterface.CheckWindow(ObjWindow::SkillTree)
//		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
//		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
//		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
//		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
//		|| gInterface.CheckWindow(ObjWindow::CashShop)
//		|| gInterface.CheckWindow(ObjWindow::Lugard)
//		|| gInterface.CheckWindow(ObjWindow::QuestList1)
//		|| gInterface.CheckWindow(ObjWindow::QuestList2)
//		|| gInterface.CheckWindow(ObjWindow::Jerint)
//		|| gInterface.CheckWindow(ObjWindow::FullMap)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
//		|| gInterface.CheckWindow(ObjWindow::GensInfo)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
//		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
//		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
//		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
//		|| gInterface.CheckWindow(ObjWindow::MuHelper))
//	{
//		return;
//	}
//
//	this->Data[eGOUP].OnShow = true;
//}
//
//bool Interface::EventDrawGoup_Open(DWORD Event)
//{
//	DWORD CurrentTick = GetTickCount();
//	DWORD Delay = (CurrentTick - this->Data[eGOUP].EventTick);
//	// ----
//	if (!this->Data[eGOUP].OnShow || !IsWorkZone(eGOUP))
//	{
//		return false;
//	}
//	// ----
//	if (Event == WM_LBUTTONDOWN)
//	{
//
//		//if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
//		//{
//		//	pSetCursorFocus = false;
//		//}
//		this->Data[eGOUP].OnClick = true;
//		return true;
//	}
//	// ----
//	this->Data[eGOUP].OnClick = false;
//	// ----
//	if (Delay < 500)
//	{
//		return false;
//	}
//
//	// ----
//	this->Data[eGOUP].EventTick = GetTickCount();
//
//	if (GetForegroundWindow() == pGameWindow)
//	{
//
//		ShellExecute(NULL, "open", gCustomMessage.GetMessage(88), NULL, NULL, SW_MAXIMIZE);
//		//ShellExecute(NULL, "open", "https://www.facebook.com/groups/843355849734618", NULL, NULL, SW_MAXIMIZE);
//
//	}
//
//	return false;
//}
#endif


DWORD ClickTickCount = 0;
#if(CHIEN_TRUONG_CO)
void Interface::DrawChienTruongCo()
{
	if (!this->Data[eCuaSoCTC].OnShow)
	{
		return;
	}

	float CuaSoW = 230.0;
	float CuaSoH = 200.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;

	gCentral.PrintDropBox(StartX, StartY, CuaSoW, CuaSoH, 0, 0);

	if (gInterface.IsWorkZone(StartX, StartY, CuaSoW, CuaSoH)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;

	//======Close
	int CloseX = StartX + CuaSoW - 40;
	int CloseY = StartY;
	pDrawGUI(0x7EC5, CloseX, CloseY, 36.0f, 29.0f);
	if (pCheckMouseOver(CloseX, CloseY, 36, 36) == 1)
	{
		if (GetTickCount() - ClickTickCount > 300)
		{
			if (GetKeyState(1) & 0x8000)
			{
				glColor3f(1.0f, 0.0f, 0.0f);
				gInterface.Data[eCuaSoCTC].OnShow ^= 1;
				ClickTickCount = GetTickCount();
			}
		}
		pDrawColorButton(0x7EC5, CloseX, CloseY, 36, 29, 0, 0, pMakeColor(255, 204, 20, 130));
		gInterface.DrawFormat(eGold, CloseX + 15, CloseY + 30, 0, 1, "Đóng");
	}
	//================================================
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 5, 0xB8E600FF, 0x0, CuaSoW, 0, 3, "Chiến Trường Cổ"); //
	pDrawGUI(71520, StartX + (CuaSoW / 2) - (200 / 2), StartY + 30, 200, 1); //-- Divisor
	StartX = StartX + (CuaSoW / 8);
	StartY = StartY + 45;
	//====================================
	int hours = CTC_TimeConLai / 3600;
	int minutes = (CTC_TimeConLai / 60) % 60;
	int seconds = CTC_TimeConLai % 60;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xE6FCF7FF, 0x0, CuaSoW, 0, 1, "Thời gian còn lại:"); //
	CustomFont.Draw(CustomFont.FontBold, StartX + 70, StartY, 0x16FAC1FF, 0x0, CuaSoW, 0, 1, "%02d:%02d:%02d", hours, minutes, seconds); //
	//===================================
	StartY = StartY + 15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Tiêu Diệt Đủ %d Quái Nhận 1 Ngọc Ngẫu Nhiên", CTC_MonterYeuCau); //
	StartY = StartY + 15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Mỗi Ngày Miễn Phí 40 Phút", CTC_PartyKillPoint); //
	StartY = StartY + 15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Mua Thêm 60 Phút Mất 50k Wcoin", CTC_PointKillQuai); //
	StartY = StartY + 15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0x26FFD0FF, 0x0, CuaSoW, 0, 1, "- Có Khả Năng Rớt Lông Vũ, HHHT"); //
	StartY = StartY + 15;
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY, 0xFF7226FF, 0x0, CuaSoW, 0, 1, "Lưu Ý : Khu vực PK Tự Do, Hãy Cẩn Thận"); //


	//============Button
	float SizeButtonW = 95.0;
	float SizeButtonH = 19.0;
	StartX = StartX - 10;
	//=====================Button 1
	if (pCheckMouseOver(StartX, StartY + 40, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eCuaSoCTC].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				XULY_CGPACKET pMsg;
				pMsg.header.set(0xF3, 0x38, sizeof(pMsg));
				pMsg.ThaoTac = 1;
				DataSend((LPBYTE)&pMsg, pMsg.header.size);
				this->Data[eCuaSoCTC].OnShow = 0;
				gInterface.Data[eCuaSoCTC].EventTick = GetTickCount();
				//pDrawMessage ( "Button 2", 0 );
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX, StartY + 40, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 40 + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Bước Vào"); //Buoc Vao

	//=====================================
	//=====================Button 2
	if (pCheckMouseOver(StartX + SizeButtonW + 5, StartY + 40, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eCuaSoCTC].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{
				glColor3f(0.72f, 0.438f, 0.0432f);

				XULY_CGPACKET pMsg;
				pMsg.header.set(0xF3, 0x38, sizeof(pMsg));
				pMsg.ThaoTac = 2;
				DataSend((LPBYTE)&pMsg, pMsg.header.size);
				//pDrawMessage ( "Button 2", 0 );		  
				gInterface.Data[eCuaSoCTC].EventTick = GetTickCount();
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX + SizeButtonW + 5, StartY + 40, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX + SizeButtonW + 5, StartY + 40 + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Thêm Thời Gian"); //
	//=====================================
	glColor3f(1.0f, 1.0f, 1.0f); //Xoa mau

}



void Interface::DrawTimeCTC()
{

	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}
	if (pMapNumber != 97) {
		return;
	}
	float CuaSoW = 130.0;
	float CuaSoH = 81.0;

	float StartX = 516.0;
	float StartY = 348.0;
	//RenderBitmap(31566, StartX, StartY, CuaSoW, CuaSoH, 0.0, 0.0, 1.0, 1.0, 1, 1, 0);
	pDrawGUI(31650, 412.0f, 342.0f, 227.0f, 87.0f);
	int PhanTramKill;
	if (CTC_MonterYeuCau > 0) {
		PhanTramKill = (CTC_QuaiVatDaKill * 100) / CTC_MonterYeuCau;
		if (PhanTramKill > 100) { PhanTramKill = 100; }
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 5, 0xFF7226FF, 0x0, CuaSoW, 0, 3, "Đã Tiêu Diệt: %d/%d Quái", CTC_QuaiVatDaKill, CTC_MonterYeuCau); //
	}
	//================ Tinh Toan Time
	if ((GetTickCount() - gInterface.Data[eTimeCTC].EventTick) > 1000)
	{
		if (CTC_TimeConLai > 0)
		{
			CTC_TimeConLai = CTC_TimeConLai - 1;
		}
		gInterface.Data[eTimeCTC].EventTick = GetTickCount();
	}

	int hours = CTC_TimeConLai / 3600;
	int minutes = (CTC_TimeConLai / 60) % 60;
	int seconds = CTC_TimeConLai % 60;
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 35, 0x16FAC1FF, 0x0, CuaSoW, 0, 3, "Thời Gian Còn Lại : %02d:%02d:%02d", hours, minutes, seconds); //
	//=================================
	float TyLeTGA = (166.0 * PhanTramKill) / 100;
	if (TyLeTGA > 166.0) { TyLeTGA = 166.0; }
	pDrawGUI(31653, 471.5f, 421.0f, TyLeTGA, 7.0f);


}
#endif





#if(TINHNANG_NEW == 1)
void Interface::BUY_TINH_NANG_GAME(int Number)
{
	BUY_TINH_NANG_REQ pMsg;
	pMsg.h.set(0xFC, 0x01, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
#endif


#if(BOSS_GUILD == 1)
void CGMoveBossGuild(int Type)
{
	if (Type > 0)
	{
		BOSSGUILD_CGPACKET pMsg;
		pMsg.header.set(0xF3, 0x40, sizeof(pMsg));
		pMsg.CongVao = Type - 1;
		DataSend((LPBYTE)&pMsg, pMsg.header.size);
	}
}
void Interface::DrawBossGuildWindow()
{

	if (!this->Data[eBossGuildWindow].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;

	float CuaSoW = 250.0;
	float CuaSoH = 250.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 95.0;

	gCentral.PrintDropBox(StartX, StartY, CuaSoW, CuaSoH, 0, 0);

	//======Close
	int CloseX = StartX + CuaSoW - 40;
	int CloseY = StartY;
	pDrawGUI(0x7EC5, CloseX, CloseY, 36.0f, 29.0f);
	if (pCheckMouseOver(CloseX, CloseY, 36, 36) == 1)
	{
		if (GetTickCount() - ClickTickCount > 300)
		{
			if (GetKeyState(1) & 0x8000)
			{
				glColor3f(1.0f, 0.0f, 0.0f);
				gInterface.Data[eBossGuildWindow].OnShow ^= 1;
				ClickTickCount = GetTickCount();
			}
		}
		pDrawColorButton(0x7EC5, CloseX, CloseY, 36, 29, 0, 0, pMakeColor(255, 204, 20, 130));
		gInterface.DrawFormat(eGold, CloseX + 15, CloseY + 30, 0, 1, "Close");
	}
	//================================================
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 5, 0xB8E600FF, 0x0, CuaSoW, 0, 3, "Boss Guild"); // cái đó em sửa sau 
	pDrawGUI(71520, StartX + (CuaSoW / 2) - (200 / 2), StartY + 30, 200, 1); //-- Divisor
	//====================================

	if (gObjUser.CheDo1 == 1)
	{
		StartY = StartY + 35;
		CustomFont.Draw(CustomFont.FontSize18, StartX + (CuaSoW / 10) - 20, StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "Tiêu diệt các Boss Phù Thủy, Chiến Binh, Tiên Nữ"); //
		StartY = StartY + 20;
		CustomFont.Draw(CustomFont.FontSize18, StartX + (CuaSoW / 10) - 20, StartY, 0xCC0033FF, 0x0, CuaSoW, 0, 1, "Mỗi thành viên sẽ đem lại %d điểm Guild chiến thắng", gObjUser.Score); //
		StartY = StartY + 20;
		CustomFont.Draw(CustomFont.FontSize18, StartX + (CuaSoW / 10) - 20, StartY, 0xB8E600FF, 0x0, CuaSoW, 0, 1, "Mỗi thành viên sẽ nhận được %d WCoinC khi Guild chiến thắng", gObjUser.WCoinC); //
		//---
		StartY = StartY + 23;
		CustomFont.Draw(CustomFont.FontBold, StartX + (CuaSoW / 10) - 20, StartY, 0x6699FFFF, 0x0, CuaSoW, 0, 1, "Nhân vật tiêu diệt Boss Phù Thủy sẽ nhận được %d WCoinC", gObjUser.PhuThuyWCoinC); //
		StartY = StartY + 20;
		CustomFont.Draw(CustomFont.FontBold, StartX + (CuaSoW / 10) - 20, StartY, 0xFFFF66FF, 0x0, CuaSoW, 0, 1, "Nhân vật tiêu diệt Boss Chiến Binh sẽ nhận được %d WCoinC", gObjUser.ChienBinhWCoinC); //
		StartY = StartY + 20;
		CustomFont.Draw(CustomFont.FontBold, StartX + (CuaSoW / 10) - 20, StartY, 0x99FFFFFF, 0x0, CuaSoW, 0, 1, "Nhân vật tiêu diệt Boss Tiên Nữ sẽ nhận được %d WCoinC", gObjUser.TienNuWCoinC); //
	}

	if (gObjUser.CheDo2 == 1)
	{
		StartY = StartY + 35;
		CustomFont.Draw(CustomFont.FontSize18, StartX + (CuaSoW / 10) - 20, StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "Tiêu diệt các Boss Thuật Sĩ, Thiết Binh, Đấu Sĩ, Chúa Tể"); //
		StartY = StartY + 20;
		CustomFont.Draw(CustomFont.FontSize18, StartX + (CuaSoW / 10) - 20, StartY, 0xCC0033FF, 0x0, CuaSoW, 0, 1, "Mỗi thành viên sẽ đem lại %d điểm Guild chiến thắng", gObjUser.Score); //
		StartY = StartY + 20;
		CustomFont.Draw(CustomFont.FontSize18, StartX + (CuaSoW / 10) - 20, StartY, 0xB8E600FF, 0x0, CuaSoW, 0, 1, "Mỗi thành viên sẽ nhận được %d WCoinC khi Guild chiến thắng", gObjUser.WCoinC); //
		//---
		StartY = StartY + 23;
		CustomFont.Draw(CustomFont.FontBold, StartX + (CuaSoW / 10) - 20, StartY, 0x6699FFFF, 0x0, CuaSoW, 0, 1, "Nhân vật tiêu diệt Boss Thuật Sĩ sẽ nhận được %d WCoinC", gObjUser.ThuatSiWCoinC); //
		StartY = StartY + 20;
		CustomFont.Draw(CustomFont.FontBold, StartX + (CuaSoW / 10) - 20, StartY, 0xFFFF66FF, 0x0, CuaSoW, 0, 1, "Nhân vật tiêu diệt Boss Thiết Binh sẽ nhận được %d WCoinC", gObjUser.ThietBinhWCoinC); //
		StartY = StartY + 20;
		CustomFont.Draw(CustomFont.FontBold, StartX + (CuaSoW / 10) - 20, StartY, 0x99FFFFFF, 0x0, CuaSoW, 0, 1, "Nhân vật tiêu diệt Boss Đấu Sĩ sẽ nhận được %d WCoinC", gObjUser.DauSiWCoinC); //
		StartY = StartY + 20;
		CustomFont.Draw(CustomFont.FontBold, StartX + (CuaSoW / 10) - 20, StartY, 0xFFCC33FF, 0x0, CuaSoW, 0, 1, "Nhân vật tiêu diệt Boss Chúa Tể sẽ nhận được %d WCoinC", gObjUser.ChuaTeWCoinC); //
	}

	//============Button
	StartY = StartY + 10;
	float SizeButtonW = 95.0;
	float SizeButtonH = 19.0;
	StartX = StartX + (CuaSoW / 2);
	int StartX1 = 50;
	int StartY1 = 10;
	//=====================Button 1
	if (pCheckMouseOver(StartX - StartX1, StartY + StartY1 + 20, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eBossGuildWindow].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{
				glColor3f(0.72f, 0.438f, 0.0432f);
				CGMoveBossGuild(1);
				this->Data[eBossGuildWindow].OnShow = 0;
				gInterface.Data[eBossGuildWindow].EventTick = GetTickCount();
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	RenderBitmap(31563, StartX - StartX1, StartY + StartY1 + 20, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX - StartX1, StartY + (SizeButtonH / 4) + StartY1 + 20, 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Tham gia"); //Buoc Vao
	//-------
	glColor3f(1.0f, 1.0f, 1.0f); //Xoa mau
}
void Interface::DrawBossGuildMap()
{
	if (pPlayerState < GameProcess)
	{
		return;
	}
	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}
	float MainWidth = 138.0;
	float MainHeight = 265.0;
	float StartY = 264.0;
	float StartX = 512.0; //512

	if (pMapNumber == 83)
	{
		pDrawGUI(31650, 412.0f, 362.0f, 227.0f, 87.0f);
		//================ Tinh Toan Time
		if ((GetTickCount() - gInterface.Data[eTimeCTC].EventTick) > 1000)
		{
			if (BossGuild_TimeConLai > 0)
			{
				BossGuild_TimeConLai = BossGuild_TimeConLai - 1;
			}
			gInterface.Data[eTimeCTC].EventTick = GetTickCount();
		}

		int hours = BossGuild_TimeConLai / 3600;
		int minutes = (BossGuild_TimeConLai / 60) % 60;
		int seconds = BossGuild_TimeConLai % 60;

		CustomFont.Draw(CustomFont.FontBold, StartX + 20, StartY + 110, eWhite, 0x0, 100, 0, 3, " Boss Guild"); //
		CustomFont.Draw(CustomFont.FontBold, StartX + 23, StartY + 135, eYellow, 0x0, 100, 0, 3, " Thời gian còn lại"); //
		CustomFont.Draw(CustomFont.FontBold, StartX + 20, StartY + 150, eWhite, 0x0, 100, 0, 3, " %02d:%02d:%02d", hours, minutes, seconds); //
		//=================================

		SetByte(0x0059AF53 + 2, 0);		 // Pk Không Cần Ctrl
		SetByte(0x0059B248 + 2, 0);		 // Pk Không Cần Ctrl
	}
}
#endif

//===========
void CGMoveCTCMini(int Type)
{
	if (Type > 0)
	{
		CTCMINI_CGPACKET pMsg;
		pMsg.header.set(0xF3, 0x39, sizeof(pMsg));
		pMsg.CongVao = Type - 1;
		DataSend((LPBYTE)&pMsg, pMsg.header.size);
	}
}


void Interface::DrawCTCMiniWindow()
{

	if (!this->Data[eCTCMiniWindow].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;

	float CuaSoW = 250.0;
	float CuaSoH = 250.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 95.0;

	gCentral.PrintDropBox(StartX, StartY, CuaSoW, CuaSoH, 0, 0);

	//======Close
	int CloseX = StartX + CuaSoW - 40;
	int CloseY = StartY;
	pDrawGUI(0x7EC5, CloseX, CloseY, 36.0f, 29.0f);
	if (pCheckMouseOver(CloseX, CloseY, 36, 36) == 1)
	{
		if (GetTickCount() - ClickTickCount > 300)
		{
			if (GetKeyState(1) & 0x8000)
			{
				glColor3f(1.0f, 0.0f, 0.0f);
				gInterface.Data[eCTCMiniWindow].OnShow ^= 1;
				ClickTickCount = GetTickCount();
			}
		}
		pDrawColorButton(0x7EC5, CloseX, CloseY, 36, 29, 0, 0, pMakeColor(255, 204, 20, 130));
		gInterface.DrawFormat(eGold, CloseX + 15, CloseY + 30, 0, 1, "Close");
	}
	//================================================
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 5, 0xB8E600FF, 0x0, CuaSoW, 0, 3, "CTC - Chiến Phe"); // cái đó em sửa sau 
	pDrawGUI(71520, StartX + (CuaSoW / 2) - (200 / 2), StartY + 30, 200, 1); //-- Divisor
	//====================================
	StartY = StartY + 45;
	CustomFont.Draw(CustomFont.FontNormal, StartX + (CuaSoW / 10), StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Cả Phe: +25000 cống hiến khi Phá Cổng"); //
	StartY = StartY + 12;
	CustomFont.Draw(CustomFont.FontNormal, StartX + (CuaSoW / 10), StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Cả Phe: +30000 cống hiến khi Chiếm Trụ"); //
	StartY = StartY + 12;
	CustomFont.Draw(CustomFont.FontNormal, StartX + (CuaSoW / 10), StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Cả Phe: +10000 cống hiến khi Thắng Sự Kiện"); //
	StartY = StartY + 12;
	CustomFont.Draw(CustomFont.FontBold, StartX + (CuaSoW / 10), StartY, 0x00FFCCFF, 0x0, CuaSoW, 0, 1, "Lưu ý: Phe Chiếm 2 trụ trở lên sẽ thắng."); //
	StartY = StartY + 12;
	CustomFont.Draw(CustomFont.FontBold, StartX + (CuaSoW / 10), StartY, 0x00FF90FF, 0x0, CuaSoW, 0, 1, "Phé Chiến Thắng Sự Kiện Trước Sẽ Được Vào 'Lãnh Địa'"); //
	StartY = StartY + 25;
	pDrawGUI(32583, StartX, StartY, 128.0f, 128.0f); //Huong Dan CTC

	//============Button
	StartY = StartY + 10;
	float SizeButtonW = 95.0;
	float SizeButtonH = 19.0;
	StartX = StartX + (CuaSoW / 2);
	//=====================Button 1
	if (pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1 && !CheckVaoLanhDia)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);
				CGMoveCTCMini(1);
				this->Data[eCTCMiniWindow].OnShow = 0;
				gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
				//pDrawMessage ( "Button 2", 0 );
			}
		}
	}
	else if (CheckVaoLanhDia)
	{
		glColor3f(0.42f, 0.42f, 0.42f);
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Tiến Công"); //Buoc Vao
	//=====================================
	/*StartY = StartY + 22;
	//=====================Button 2
	if (pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				CGMoveCTCMini(2);
				this->Data[eCTCMiniWindow].OnShow = 0;
				gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Cổng 2"); //Buoc Vao
	//=====================================
	StartY = StartY + 22;
	//=====================Button 3
	if (pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				CGMoveCTCMini(3);
				this->Data[eCTCMiniWindow].OnShow = 0;
				gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Cổng 3"); //Buoc Vao
	//=====================================
	StartY = StartY + 22;
	//=====================Button 4
	if (pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				CGMoveCTCMini(4);
				this->Data[eCTCMiniWindow].OnShow = 0;
				gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
				//pDrawMessage ( "Button 2", 0 );
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Cổng 4"); //Buoc Vao
	//=====================================
	*/
	StartY = StartY + 22;
	//=====================Button Lanh Dia
	if (pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1 && CheckVaoLanhDia)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				CGMoveCTCMini(5);
				this->Data[eCTCMiniWindow].OnShow = 0;
				gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
			}
		}
	}
	else if (!CheckVaoLanhDia) 
	{
		glColor3f(0.42f, 0.42f, 0.42f);
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Lãnh Địa"); //Buoc Vao
	//=====================================
	//=====================================
	glColor3f(1.0f, 1.0f, 1.0f); //Xoa mau
}

void Interface::DrawCTCMiNiMap()
{
	if (pPlayerState < GameProcess)
	{
		return;
	}
	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}
	if (gObjUser.m_MapNumber != 98)
	{
		return;
	}
	float MainWidth = 138.0;
	float MainHeight = 265.0;
	float StartY = 264.0;
	float StartX = 512.0; //512

	pDrawGUI(32584, StartX, StartY, 128.0f, 157.0f); //UI
	pDrawGUI(32583, StartX, StartY + 28.0, 128.0f, 128.0f); //MAP

	//================ Tinh Toan Time
	if ((GetTickCount() - gInterface.Data[eTimeCTC].EventTick) > 1000)
	{
		if (CTCMINI_TimeCTCMini > 0)
		{
			CTCMINI_TimeCTCMini = CTCMINI_TimeCTCMini - 1;
		}
		gInterface.Data[eTimeCTC].EventTick = GetTickCount();
	}

	int hours = CTCMINI_TimeCTCMini / 3600;
	int minutes = (CTCMINI_TimeCTCMini / 60) % 60;
	int seconds = CTCMINI_TimeCTCMini % 60;
	CustomFont.Draw(CustomFont.FontBold, StartX + 10, StartY + 10, 0x16FAC1FF, 0x0, 100, 0, 3, " %02d:%02d:%02d", hours, minutes, seconds); //
	//=================================

	//== Cong Vao 1
	if (CTCMINI_Cong[0] == 0) {
		RenderBitmap(31681, (float)(StartX - 3 + 96 / 2), (float)(294 - 5 + (255 - 130) / 2), 7.0, 7.0, 0.0, 0.0, 0.875, 0.875, 1, 1, 0.0);
	}
	//== Cong Vao 2
	if (CTCMINI_Cong[1] == 0) {
		RenderBitmap(31681, (float)(StartX - 3 + 128 / 2), (float)(294 - 5 + (255 - 130) / 2), 7.0, 7.0, 0.0, 0.0, 0.875, 0.875, 1, 1, 0.0);
	}
	//== Cong Vao 3
	if (CTCMINI_Cong[2] == 0) {
		RenderBitmap(31681, (float)(StartX - 2.5 + 161 / 2), (float)(294 - 5 + (255 - 130) / 2), 7.0, 7.0, 0.0, 0.0, 0.875, 0.875, 1, 1, 0.0);
	}

	//Tru Chua Cong 1 //31683 Thuoc Ve Guild
	if (CTCMINI_Tru[0] == 0) {
		RenderBitmap(31680, (float)(StartX - 4.5 + 96 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
	}
	else  {
		RenderBitmap(31683, (float)(StartX - 4.5 + 96 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
	}
	//Tru Chua Cong 2
	if (CTCMINI_Tru[1] == 0) {
		RenderBitmap(31680, (float)(StartX - 4.5 + 128 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
	}
	else  {
		RenderBitmap(31683, (float)(StartX - 4.5 + 128 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
	}
	//Tru Chua Cong 3
	if (CTCMINI_Tru[2] == 0) {
		RenderBitmap(31680, (float)(StartX - 4.5 + 161 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
	}
	else  {
		RenderBitmap(31683, (float)(StartX - 4.5 + 161 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
	}

	//pDrawGUI(32585, 640/2-(210/2), 480/2-(94/2),210,94);

	int Model;

	for (int i = 0; i < 400; i++)
	{
		Model = pGetPreviewStruct(pPreviewThis(), i);
		if (!Model) {
			continue;
		}
		if (Model
			&& *(BYTE *)(Model + 780)
			&& *(BYTE *)(Model + 800) == emPlayer
			)
		{
			if (Model != *(DWORD *)0x7BC4F04)
			{
				this->DrawGUI(ePLAYER_POINT, (float)(StartX - 1 + *(DWORD *)(Model + 172) / 2), (float)(294 - 1 + (255 - *(DWORD *)(Model + 176)) / 2));
			}
			else {
				this->DrawGUI(ePLAYER_POINT, (float)(StartX - 1 + *(DWORD *)(Model + 172) / 2), (float)(294 - 1 + (255 - *(DWORD *)(Model + 176)) / 2));
			}

		}
	}
}

//=========================================================================================================================================
//=========================================================================================================================================
void Interface::TvTEventEx(PMSG_TVTEVENT_UPD * aRecv)
{
	this->m_ScoreBlue = 0;
	this->m_ScoreBlue = aRecv->ScoreBlue;
	this->m_ScoreRed = 0;
	this->m_ScoreRed = aRecv->ScoreRed;
	this->m_KillCount = 0;
	this->m_KillCount = aRecv->KillCount;
	this->m_DieCount = 0;
	this->m_DieCount = aRecv->DieCount;
	this->m_TotalPlayer = 0;
	this->m_TotalPlayer = aRecv->TotalPlayer;
}



//=========================================================================================================================================
//=========================================================================================================================================
void Interface::TvTEvent()
{

	if (this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::ChatWindow)
		|| this->CheckWindow(ObjWindow::Store)
		|| this->CheckWindow(ObjWindow::Character)
		|| this->CheckWindow(ObjWindow::Inventory)
		|| this->CheckWindow(ObjWindow::Quest)
		|| this->CheckWindow(ObjWindow::MoveList))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	//===================================================================================================
	if (pMapNumber == 82)
	{
		this->DrawGUI(eTVTHUD, MAX_WIN_WIDTH - 210, 0);
		this->DrawGUI(eTVTHUD, MAX_WIN_WIDTH - 162, 0);
		gCItemSetOption.ItemTooltipS15(MAX_WIN_WIDTH - 197, 3, 40, 13, 0.0, 0);
		//================ Tinh Toan Time
		if ((GetTickCount() - gInterface.Data[eTVTHUD].EventTick) > 1000)
		{
			if (TvTEvent_TimeConLai > 0)
			{
				TvTEvent_TimeConLai = TvTEvent_TimeConLai - 1;
			}
			gInterface.Data[eTVTHUD].EventTick = GetTickCount();
		}
		int minutes = (TvTEvent_TimeConLai / 60) % 60;
		int seconds = TvTEvent_TimeConLai % 60;
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 210, 4, 70, 3, "%02d:%02d", minutes, seconds);
		//=================================

		this->DrawFormat(eRed, MAX_WIN_WIDTH - 176, 3, 70, 3, "%d", this->m_ScoreRed);
		this->DrawFormat(eBlue, MAX_WIN_WIDTH - 150, 3, 70, 3, "%d", this->m_ScoreBlue);
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 112, 3, 70, 3, "%d", this->m_KillCount);
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 82, 3, 70, 3, "%d", this->m_DieCount);
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 52, 3, 70, 3, "%d", this->m_TotalPlayer);

		SetByte(0x0059AF53 + 2, 0);
		SetByte(0x0059B248 + 2, 0);

	}
	//===================================================================================================
	if (pMapNumber == 88)
	{
		this->DrawGUI(eTVTHUD, MAX_WIN_WIDTH - 162, 0);

		//================ Tinh Toan Time
		if ((GetTickCount() - gInterface.Data[eTVTHUD].EventTick) > 1000)
		{
			if (PKEvent_TimeConLai > 0)
			{
				PKEvent_TimeConLai = PKEvent_TimeConLai - 1;
			}
			gInterface.Data[eTVTHUD].EventTick = GetTickCount();
		}

		gCItemSetOption.ItemTooltipS15(MAX_WIN_WIDTH - 152, 3, 47, 13, 0.0, 0);
		int minutes = (PKEvent_TimeConLai / 60) % 60;
		int seconds = PKEvent_TimeConLai % 60;
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 165, 4, 70, 3, "%02d:%02d", minutes, seconds);
		//=================================

		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 112, 3, 70, 3, "%d", gObjUser.SurvivorKill);
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 82, 3, 70, 3, "%d", gObjUser.SurvivorDie);
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 52, 3, 70, 3, "%d", gObjUser.SurvivorTotal);

		SetByte(0x0059AF53 + 2, 0);
		SetByte(0x0059B248 + 2, 0);
	}
}
//===========


void Interface::GetInfoClient(PMSG_CLIENT_UPD * aRecv)
{
#if (SACHTHUOCTINH_NEW)
	//-----------------------------
	this->m_SachThuocTinh_01 = aRecv->SachThuocTinh_01;
#endif
	//-----------------------------
	this->m_DanhHieu = aRecv->DanhHieu;
	this->m_TuLuyen = aRecv->TuLuyen;

}
#if(OFFLINE_MODE_NEW)
void Interface::DrawOffExpWindow()
{
	if (!this->Data[eOFFEXP_MAIN].OnShow)
	{
		return;
	}
	// ----
	DWORD ItemNameColor = eWhite;
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 50.0; // 100.0
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	//---------------------------------------------------------------------------------------//
	if (this->IsWorkZone(eOFFEXP_MAIN)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//---------------------------------------------------------------------------------------//
	//pDrawMessage("", 0); // Không Cho Hiện Thông Báo Trên Màn Hình
	//---------------------------------------------------------------------------------------//
	this->DrawGUI(eOFFEXP_MAIN, StartX, StartY + 20);

	gCItemSetOption.ItemTooltipS15(StartX - 15, gInterface.Data[eOFFEXP_MAIN].Y + 20, 260, 280, 0.0, 150);
	//gCItemSetOption.ItemTooltipS15(StartX - 15, gInterface.Data[eOFFEXP_MAIN].Y + 30, 260, 260, 0.0, 150);

	//this->DrawGUI(eOFFEXP_TITLE, StartX, StartY);
	//StartY = this->DrawRepeatGUI(eOFFEXP_FRAME, StartX, StartY + 67.0, 13);
	//this->DrawGUI(eOFFEXP_FOOTER, StartX, StartY);

	this->DrawGUI(eOFFEXP_CLOSE, StartX + 216, this->Data[eOFFEXP_MAIN].Y + 28);
	// ----
	if (this->IsWorkZone(eOFFEXP_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eOFFEXP_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eOFFEXP_CLOSE, this->Data[eOFFEXP_CLOSE].X, this->Data[eOFFEXP_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eOFFEXP_CLOSE].X + 5, this->Data[eOFFEXP_CLOSE].Y + 25, "Close");
	}
	// ----

	this->DrawFormat(eGold, StartX + 10, this->Data[eOFFEXP_MAIN].Y + 5, 210, 3, "Treo Máy Offline"); // Treo Máy Offline

	this->DrawFormat(eWhite, StartX + 10, this->Data[eOFFEXP_MAIN].Y + 35, 210, 3, "Chào[%s]!Bạn đang bận việc và muốn treo máy ?", gObjUser.lpPlayer->Name); // "Chào [%s]! Bạn đang bận việc và muốn treo máy?"

	this->DrawFormat(eWhite, StartX + 10, this->Data[eOFFEXP_MAIN].Y + 55, 210, 3, "Ở chế độ này, bạn có thể cày level khi máy tính của bạn đã tắt."); // "Ở chế độ này, bạn có thể cày level khi máy tính của bạn đã tắt."

	pDrawGUI(0x7B5E, StartX + 30, this->Data[eOFFEXP_MAIN].Y + 78, 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
	pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[eOFFEXP_MAIN].Y + 78, 82.0, 2.0); // Äåëèòåëü ìåëêèé 2


	int ObjectIDs[7] =
	{
		eOFFEXP_CHECKBOX_BUFF,
		0,
		eOFFEXP_CHECKBOX_PICK_ZEN,
		eOFFEXP_CHECKBOX_PICK_JEWELS,
		eOFFEXP_CHECKBOX_PICK_EXC,
		eOFFEXP_CHECKBOX_PICK_ANC,
		eOFFEXP_CHECKBOX_SELECTED_HELPER
	};

	char szText[7][64] =
	{
		"Tự động Buff",
		"NULL",
		"Nhặt Zen",
		"Nhặt Ngọc",
		"Nhặt Item Hoàn hảo",
		"Nhặt Items Thần",
		"Nhặt Items có trong danh sách Auto train"
	};

	for (int i = 0; i<8; i++)
	{
		pDrawGUI(0x7B5E, StartX + 30, this->Data[eOFFEXP_MAIN].Y + 114 + (20 * i), 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
		pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[eOFFEXP_MAIN].Y + 114 + (20 * i), 82.0, 2.0); // Äåëèòåëü ìåëêèé 2

		if (i != 1 && i != 7)
		{
			int btn = 1;
			if (i == 0 && gOfflineMode.DrawBuff == 0)
			{
				btn = 0;
			}

			if ((i >= 2 && i <= 6) && gOfflineMode.DrawPick == 0)
			{
				btn = 0;
			}

			this->DrawGUI(eOFFEXP_POINT, StartX + 30, this->Data[eOFFEXP_MAIN].Y + 120 + (20 * i)); //
			this->DrawFormat(eWhite, StartX + 45, this->Data[eOFFEXP_MAIN].Y + 121 + (20 * i), 200, 1, szText[i]);
			if (btn == 1)
			{
				this->DrawButton(ObjectIDs[i], ButtonX + 117, this->Data[eOFFEXP_MAIN].Y + 117 + (20 * i), 0, 15 * gOfflineMode.GetCheckBox(i));
			}
			else
			{
				//				this->DrawColoredButton(ObjectIDs[i], ButtonX + 117, this->Data[eOFFEXP_MAIN].Y + 117 + (20 * i), 0, 15 * gOfflineMode.GetCheckBox(i), eGray150);
			}

		}
	}

	this->DrawFormat(eGold, StartX + 10, this->Data[eOFFEXP_MAIN].Y + 141, 210, 3, "Tùy chọn nhặt Item chỉ sử dụng cho tài khoản Vip."); // "Tùy chọn nhặt Item chỉ sử dụng cho tài khoản Vip."

	this->DrawGUI(eOFFEXP_BTN_OK, ButtonX - 3, this->Data[eOFFEXP_MAIN].Y + 260);
	this->DrawFormat(eWhite, StartX + 5, this->Data[eOFFEXP_MAIN].Y + 270, 210, 3, "Bắt Đầu"); // "Bắt Đầu"

	if (IsWorkZone(eOFFEXP_BTN_OK))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eOFFEXP_BTN_OK].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eOFFEXP_BTN_OK, this->Data[eOFFEXP_BTN_OK].X, this->Data[eOFFEXP_BTN_OK].Y, Color);
	}

	gOfflineMode.DrawSkill(0, StartX);
	gOfflineMode.DrawSkill(1, StartX);
	gOfflineMode.DrawSkill(2, StartX);

	for (int i = 0; i <= 2; i++)
	{
		if (gOfflineMode.SkillsIndex[i] == 0)
		{
			continue;
		}

		if (this->IsWorkZone(StartX + (50 * (i + 1)), this->Data[eOFFEXP_MAIN].Y + 83, StartX + (50 * (i + 1)) + 20, this->Data[eOFFEXP_MAIN].Y + 83 + 28))
		{
			this->DrawToolTipEx(eWhite, StartX + (50 * (i + 1)) - 14, this->Data[eOFFEXP_MAIN].Y + 123, 50, 30, 3, gOfflineMode.SkillsName[i]);
		}
	}

	//if ((gObjUser.lpPlayer->Class & 7) == DarkWizard)
	//{
	//	pDrawGUI(0x1000, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1001, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1002, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == DarkKnight)
	//{
	//	pDrawGUI(0x1003, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1004, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1005, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == Elf)
	//{
	//	pDrawGUI(0x1006, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1007, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1008, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == MagicGladiator)
	//{
	//	pDrawGUI(0x1009, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1010, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1011, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == DarkLord)
	//{
	//	pDrawGUI(0x1012, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1013, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1014, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == Summoner)
	//{
	//	pDrawGUI(0x1015, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1016, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1017, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == Monk)
	//{
	//	pDrawGUI(0x1018, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1019, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}

}
// ----------------------------------------------------------------------------------------------
bool Interface::EventOffExpWindow_Main(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if (!this->Data[eOFFEXP_MAIN].OnShow)
	{
		return false;
	}

	if (IsWorkZone(eOFFEXP_CLOSE))
	{
		DWORD Delay = (CurrentTick - this->Data[eOFFEXP_CLOSE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eOFFEXP_CLOSE].OnClick = true;
			return true;
		}
		// ----
		this->Data[eOFFEXP_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		// ----
		this->Data[eOFFEXP_CLOSE].EventTick = GetTickCount();

		this->SwitchOffExpWindoState();
		// ----
		return false;
	}

	if (IsWorkZone(eOFFEXP_BTN_OK))
	{
		DWORD Delay = (CurrentTick - this->Data[eOFFEXP_BTN_OK].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eOFFEXP_BTN_OK].OnClick = true;
			return true;
		}
		// ----
		this->Data[eOFFEXP_BTN_OK].OnClick = false;;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		// ----
		this->Data[eOFFEXP_BTN_OK].EventTick = GetTickCount();
		gOfflineMode.SendOffExpData();
		this->SwitchOffExpWindoState();
	}

	int ObjectIDs[7] =
	{
		eOFFEXP_CHECKBOX_BUFF,
		0,
		eOFFEXP_CHECKBOX_PICK_ZEN,
		eOFFEXP_CHECKBOX_PICK_JEWELS,
		eOFFEXP_CHECKBOX_PICK_EXC,
		eOFFEXP_CHECKBOX_PICK_ANC,
		eOFFEXP_CHECKBOX_SELECTED_HELPER
	};

	for (int i = 0; i<7; i++)
	{
		if (i == 1) continue;

		if (i == 0 && gOfflineMode.DrawBuff == 0)
		{
			continue;
		}

		if ((i >= 2 && i <= 6) && gOfflineMode.DrawPick == 0)
		{
			continue;
		}

		if (this->IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);
			// ----
			if (!this->Data[eOFFEXP_MAIN].OnShow)
			{
				return false;
			}
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return false;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;
			// ----
			if (Delay < 200)
			{
				return false;
			}
			// ----
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();
			gOfflineMode.ChangeCheckBox(i);
		}
	}

	for (int i = 0; i <= 2; i++)
	{
		if (gOfflineMode.SkillsIndex[i] == 0)
		{
			continue;
		}

		float X = gOfflineMode.GetSkillX(i);
		float Y = gOfflineMode.GetSkillY(i);

		if (this->IsWorkZone(X, Y, X + 20, Y + 28))
		{
			DWORD Delay = (CurrentTick - gOfflineMode.m_SkillCoord[i].EventTick);

			if (Event == WM_LBUTTONDOWN)
			{
				continue;
			}
			// ----
			if (Delay < 500)
			{
				continue;
			}

			gOfflineMode.m_SkillCoord[i].EventTick = GetTickCount();

			if (gOfflineMode.SkillsData[i] == 0)
			{
				return false;
			}

			gOfflineMode.ClearSelectedSkill();
			gOfflineMode.SelectedSkill[i] = true;
		}
	}
	return false;
}
#endif
#if(VANTHANH_CHUCHAY == 1)
float VitriX = 150.0;
float VitriY = 380.0;
bool QuayLai = false;
int res = 0;
int begin_time = 0;
void Interface::DrawTextRun()
{
	if (gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(Character) //-- 13 & 16
		|| gInterface.CheckWindow(Warehouse) //-- 8
		|| gInterface.CheckWindow(Shop) //-- 12
		|| gInterface.CheckWindow(ChaosBox) //-- 9
		|| gInterface.CheckWindow(Trade) //-- 7
		|| gInterface.CheckWindow(Store) //-- 14
		|| gInterface.CheckWindow(OtherStore) //-- 15
		|| gInterface.CheckWindow(LuckyCoin1) //-- 60
		|| gInterface.CheckWindow(NPC_ChaosMix)) //-- 76
	{
		return;
	}

	if (!QuayLai && VitriX < 300)
	{

		VitriX++;
	}
	else
	{
		VitriX = 70.0;
		res++;
	}
	//9-04-2022
	if (res > 8)
	{
		res = 0;
	}
	//9-04-2022
	gCItemSetOption.ItemTooltipS15(VitriX + 165, VitriY - 378, 105, 10, 0.0, 0);
	CustomFont.Draw(CustomFont.FontBold, VitriX + 170, VitriY - 378, 0xB8E600FF, 0x00, ePLAYER_POINT, 0, 1000, gConfig.TextHDC[res]); //#00ffff	
}
#endif
#if(THANMA)
void DrawTMPoint() //<<< Draw Bang POint PK
{
	if (pMapNumber != gInterface.m_EventTMMap || gInterface.m_EventTMTimeCount == 0)
	{
		return;
	}
	//Test
	float ChieuRong = 150.0f;
	float ChieuDai = 10.0f;
	float ViTriX = ((int)pWinWidth / pWinHeightReal / 2) - (ChieuRong / 2);
	float ViTriY = 5;

	int DiemA = gInterface.m_TMScoreAcQuy;
	int DiemB = gInterface.m_TMScoreThienThan;
	float TyLeTGA = 0;

	if (gCentral.gDrawButton(ViTriX + ChieuRong + 5, 2, 75, 12, gConfig.TextTM_ThanMaChien[18]) && (GetTickCount() - gInterface.Data[eWindowNPC_ThanMaChien].EventTick) > 300)
	{
		////===BXH
		gInterface.Data[eWindowBXH_ThanMaChien].OnShow ^= 1;
	}

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	glColor4f(0.79, 0.5467, 0.1264, 0.3);
	pDrawBarForm(ViTriX - 2, ViTriY - 2, ChieuRong + 4, ChieuDai + 4, 0.0, 0); //Nen Goc
	EnableAlphaTest(1);

	glColor4f(1.0, 0.0, 0.0, 0.7);
	pDrawBarForm(ViTriX, ViTriY, ChieuRong, ChieuDai, 0.0, 0); //Ac Quy
	EnableAlphaTest(1);

	if (DiemA == 0 && DiemB == 0)
	{
		TyLeTGA = ChieuRong / 2;
	}
	else
	{
		TyLeTGA = (ChieuRong * ((DiemA * 100) / (DiemA + DiemB))) / 100;
	}

	glColor4f(0.0, 0.5, 1.0, 0.7);
	pDrawBarForm(ViTriX, ViTriY, TyLeTGA, ChieuDai, 0.0, 0); //Thien Than
	EnableAlphaTest(1);
	pGLSupremo();

	//=== TInh Time Event
	if ((GetTickCount() - gInterface.mCalcTimeEventTick) > 1000)
	{
		if (gInterface.m_EventTMTimeCount > 0)
		{
			gInterface.m_EventTMTimeCount = gInterface.m_EventTMTimeCount - 1;
		}
		gInterface.mCalcTimeEventTick = GetTickCount();
	}
	char text1[120];
	int totalseconds;
	int hours;
	int minutes;
	int seconds;
	int days;

	totalseconds = gInterface.m_EventTMTimeCount;
	hours = totalseconds / 3600;
	minutes = (totalseconds / 60) % 60;
	seconds = totalseconds % 60;

	if (hours > 23)
	{
		days = hours / 24;
		wsprintf(text1, "%d day(s)+", days);
	}
	else
	{
		wsprintf(text1, "%02d:%02d", minutes, seconds);
	}
	//==Text
	HFONT FontTextTMPoint = CreateFontA(12.5, Main_Font_Width, 0, 0, 400, 0, 0, 0, 1u, 0, 0, 3u, 0, "Arial");

	CustomFont.Draw(FontTextTMPoint, ViTriX, ViTriY + (ChieuDai / 2) - 4, 0xFFFFFFFF, 0x0, ChieuRong, 0, 3, "Time: %s", text1);
	//==Ben Trai
	CustomFont.Draw(FontTextTMPoint, ViTriX, ViTriY + (ChieuDai / 2) - 4, 0xFFFFFFFF, 0x0, (ChieuRong / 2), 0, 3, "[%s] : %d", gConfig.TextTM_ThanMaChien[16], DiemA);
	//==Ben Phai
	CustomFont.Draw(FontTextTMPoint, ViTriX + (ChieuRong / 2), ViTriY + (ChieuDai / 2) - 4, 0xFFFFFFFF, 0x0, (ChieuRong / 2), 0, 3, "[%s] : %d", gConfig.TextTM_ThanMaChien[17], DiemB);
	DeleteObject(FontTextTMPoint);
	return;
}
void DrawWindowNPCTM()
{
	if (!gInterface.Data[eWindowNPC_ThanMaChien].OnShow)
	{
		return;
	}
	float CuaSoW = 300.0;
	float CuaSoH = 250.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;
	gCentral.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindowNPC_ThanMaChien, FALSE, gConfig.TextTM_ThanMaChien[0]);
	if (gInterface.IsWorkZone(StartX, StartY, CuaSoW, CuaSoH)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;

	if (gCentral.gDrawButton(StartX + (CuaSoW / 2) - (115 / 2), StartY + (CuaSoH - 45), 115, 14, gConfig.TextTM_ThanMaChien[1]) && (GetTickCount() - gInterface.Data[eWindowNPC_ThanMaChien].EventTick) > 300)
	{
		//==Tham Gia Than Ma
		XULY_CGPACKET pMsg;
		pMsg.header.set(0xFF, 0x92, sizeof(pMsg));
		pMsg.ThaoTac = 1;
		DataSend((LPBYTE)& pMsg, pMsg.header.size);
		gInterface.Data[eWindowNPC_ThanMaChien].OnShow ^= 1;
		////===BXH
		//gInterface.Data[eWindowBXH_ThanMaChien].OnShow ^= 1;
	}
	HFONT FontTextTMB = CreateFontA(13, Main_Font_Width, 0, 0, 700, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, 0x1, 0, 0, Main_Font_Quality, 0, "Tahoma");
	HFONT FontTextTM = CreateFontA(13, Main_Font_Width, 0, 0, 400, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, 0x1, 0, 0, Main_Font_Quality, 0, "Tahoma");
	float TextStartY = StartY + 33;
	for (int ct = 0; ct < 14; ct++)
	{
		if (ct == 0 || ct == 1 || ct == 5 || ct == 11)
		{
			CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, gConfig.TextTM_ThanMaChien[2 + ct]); //
		}
		else if (ct == 10)
		{
			CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct), 0x00FBFFFF, 0x0, CuaSoW, 0, 1, gConfig.TextTM_ThanMaChien[2 + ct]); //
		}
		else {
			CustomFont.Draw(FontTextTM, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct), 0xEBFFFBFF, 0x0, CuaSoW, 0, 1, gConfig.TextTM_ThanMaChien[2 + ct]); //
		}

	}
	DeleteObject(FontTextTMB);
	DeleteObject(FontTextTM);
}
void DrawWindowBXHTM()
{
	if (!gInterface.Data[eWindowBXH_ThanMaChien].OnShow)
	{
		return;
	}
	float CuaSoW = 250.0;
	float CuaSoH = 200.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;

	gCentral.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindowBXH_ThanMaChien, FALSE, gConfig.TextTM_ThanMaChien[18]);



	//====================================
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 40, 0xFABB00FF, 0x0, CuaSoW / 4, 0, 3, "Top"); //
	CustomFont.Draw(CustomFont.FontBold, StartX + CuaSoW / 4, StartY + 40, 0xFABB00FF, 0x0, CuaSoW / 4, 0, 3, "Name"); //
	CustomFont.Draw(CustomFont.FontBold, StartX + ((CuaSoW / 4) * 2), StartY + 40, 0xFABB00FF, 0x0, CuaSoW / 4, 0, 3, "Kill"); //
	CustomFont.Draw(CustomFont.FontBold, StartX + ((CuaSoW / 4) * 3), StartY + 40, 0xFABB00FF, 0x0, CuaSoW / 4, 0, 3, "Team"); //
	DWORD ColorTextRank = 0xE0DFDCFF;

	for (int i = 0; i < gInterface.m_TMChienBXHC; i++)
	{
		if (i % 2)
		{
			ColorTextRank = 0xA3A3A3FF;
		}
		else {
			ColorTextRank = 0xE0DFDCFF;
		}
		if (i < 3) { ColorTextRank = 0xFFE240FF; }
		CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, CuaSoW / 4, 0, 3, "%d", i + 1); //
		CustomFont.Draw(CustomFont.FontBold, StartX + CuaSoW / 4, StartY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, CuaSoW / 4, 0, 3, "%s", gInterface.m_ThanMaChienBXH[i].Name); //
		CustomFont.Draw(CustomFont.FontBold, StartX + ((CuaSoW / 4) * 2), StartY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, CuaSoW / 4, 0, 3, "%d", gInterface.m_ThanMaChienBXH[i].Kill); //
		CustomFont.Draw(CustomFont.FontBold, StartX + ((CuaSoW / 4) * 3), StartY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, CuaSoW / 4, 0, 3, "%s", (gInterface.m_ThanMaChienBXH[i].Team > 0) ? gConfig.TextTM_ThanMaChien[15 + gInterface.m_ThanMaChienBXH[i].Team] : "NULL"); //

	}
}
void Interface::DrawTMAllWindows()
{
	DrawTMPoint();
	DrawWindowNPCTM();
	DrawWindowBXHTM();
}
#endif

//=========================================================================================================================================

#if(SACHTHUOCTINH_NEW == 1)
void Interface::DrawSachThuocTinhInterface()
{
	if (CheckWindow(ObjWindow::SkillTree) - CheckWindow(ObjWindow::CashShop))
	{
		Data[eSACHTHUOCTINH_INTERFACE].OnShow = false;
		return;
	}

	float MainWidth = 30.0;
	float MainHeight = 20.0;
	float StartY = 20.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float StartXRing = 40.0;

	if (this->CheckWindow(ObjWindow::Inventory))
	{
		if (gProtect.m_MainInfo.CustomInterfaceType == 3)
		{
			//if (gObjUser.SachThuocTinh == 1)
			{
				
				//gInterface.DrawMessage(1,"Debug Slot %d",this->Data[eSACHTHUOCTINH_INTERFACE].OnShow);
				gInterface.DrawGUI(eSACHTHUOCTINH_INTERFACE, StartX + 285, StartY + 180);
				pDrawGUI(10000, StartX + 285, StartY + 177, 35, 35);
				if (this->m_SachThuocTinh_01 >= 1)
				{
					gInterface.DrawItem2(StartX + 302, StartY + 205, 0, 0, ITEM(14, 450), 0, 0, 5, 0);
					//gInterface.DrawItem2(StartX + 302, StartY + 205, 0, 0, ITEM(12, 15), 0, 0, 5, 0);
				}

				if (gInterface.IsWorkZone(eSACHTHUOCTINH_INTERFACE))
				{
					DWORD Color = eGray150;
					gInterface.DrawColoredGUI(eSACHTHUOCTINH_INTERFACE, gInterface.Data[eSACHTHUOCTINH_INTERFACE].X, gInterface.Data[eSACHTHUOCTINH_INTERFACE].Y, Color);
				}
			}

		}
	}
}
bool Interface::EventSachThuocTinhInterface(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eSACHTHUOCTINH_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Inventory) || !IsWorkZone(eSACHTHUOCTINH_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eSACHTHUOCTINH_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eSACHTHUOCTINH_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eSACHTHUOCTINH_INTERFACE].EventTick = GetTickCount();

	//if (gObjUser.SachThuocTinh == 1)
	{
		if (this->m_SachThuocTinh_01 >= 1)
		{
			if (GetForegroundWindow() == pGameWindow)
			{
				if (this->CheckSachThuocTinhWindow())
				{
					this->CloseSachThuocTinhWindow();
				}
				else
				{
					this->OpenSachThuocTinhWindow();
				}
			}
		}
		this->BUG_SACHTHUOCTINH(8);
	}
	//if (gObjUser.SachThuocTinh == 0)
	//{
	//	gInterface.DrawMessage(1, "Chức năng [Sách Thuộc Tính] đang bảo trì !");
	//}

	return true;
}


//=========================================================================================================================================
void Interface::DrawSachThuocTinh()
{
	{
		if (this->CheckWindow(CashShop) ||
		this->CheckWindow(ChaosBox) ||
		this->CheckWindow(FullMap) ||
		this->CheckWindow(SkillTree) ||
		this->CheckWindow(Warehouse) ||
		this->CheckWindow(Shop) ||
		this->CheckWindow(Trade) ||
		this->CheckWindow(Party) ||
		this->CheckWindow(ExpandInventory) ||
		this->CheckWindow(ExpandWarehouse))
		return;
		//--------------------------------------------------------------
		if (!this->Data[eSACHTHUOCTINH_MAIN].OnShow)
		{
			return;
		}
		//--------------------------------------------------------------
		float MainWidth = 30.0;
		float MainHeight = 20.0;
		float StartY = 40.0;
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

		if (this->CheckWindow(ObjWindow::Inventory))
		{
			//--------------------------------------------------------------
			pDrawGUFULL(61526, StartX - 70, StartY - 25, 340, 620, 0, 0, 1, 1, 1, 1, 0.0);  // IMAGE MENU
			//--------------------------------------------------------------
			pSetCursorFocus = true;
			//--------------------------------------------------------------
			pDrawGUFULL(0x502A, StartX - 18, StartY + 25, 2, 330, 0, 0, 1, 1, 1, 1, 0.0); // Dọc
			pDrawGUFULL(0x502A, StartX + 38, StartY + 25, 2, 330, 0, 0, 1, 1, 1, 1, 0.0); // Dọc
			//--------------------------------------------------------------
			pDrawGUFULL(0x501A, StartX - 60, StartY + 50, 200, 2, 0, 0, 1, 1, 1, 1, 0.0); // Ngang
			pDrawGUFULL(0x501A, StartX - 60, StartY + 100, 200, 2, 0, 0, 1, 1, 1, 1, 0.0); // Ngang
			pDrawGUFULL(0x501A, StartX - 60, StartY + 150, 200, 2, 0, 0, 1, 1, 1, 1, 0.0); // Ngang
			pDrawGUFULL(0x501A, StartX - 60, StartY + 200, 200, 2, 0, 0, 1, 1, 1, 1, 0.0); // Ngang
			pDrawGUFULL(0x501A, StartX - 60, StartY + 250, 200, 2, 0, 0, 1, 1, 1, 1, 0.0); // Ngang
			pDrawGUFULL(0x501A, StartX - 60, StartY + 300, 200, 2, 0, 0, 1, 1, 1, 1, 0.0); // Ngang
			//--------------------------------------------------------------
			gInterface.DrawItem2(StartX - 40, StartY + 81, 0, 0, ITEM(14, 451), 15, 63, 0, 0);
			gInterface.DrawItem2(StartX - 40, StartY + 131, 0, 0, ITEM(14, 452), 15, 63, 0, 0);
			gInterface.DrawItem2(StartX - 40, StartY + 181, 0, 0, ITEM(14, 453), 15, 63, 0, 0);
			gInterface.DrawItem2(StartX - 40, StartY + 231, 0, 0, ITEM(14, 454), 15, 63, 0, 0);
			gInterface.DrawItem2(StartX - 40, StartY + 281, 0, 0, ITEM(14, 455), 15, 63, 0, 0);
			gInterface.DrawItem2(StartX - 40, StartY + 331, 0, 0, ITEM(14, 456), 15, 63, 0, 0);
			//--------------------------------------------------------------
			gInterface.DrawFormat(eWhite, StartX + 10, StartY - 1, 1000, 1, gConfig.TextVN_SachThuocTinh[0]);
			//--------------------------------------------------------------
			gInterface.DrawFormat(eAncient, StartX - 60, StartY + 25, 1000, 1, gConfig.TextVN_SachThuocTinh[15]);
			gInterface.DrawFormat(eAncient, StartX - 5, StartY + 25, 1000, 1, gConfig.TextVN_SachThuocTinh[16]);
			gInterface.DrawFormat(eAncient, StartX + 65, StartY + 25, 1000, 1, gConfig.TextVN_SachThuocTinh[17]);
			//--------------------------------------------------------------
			// Slot 2
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 55, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_02, this->m_OPTION_LEVEL_01);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 55, 1000, 1, gConfig.TextVN_SachThuocTinh[2], this->m_OPTION_ACTIVE_01);

			if (this->m_SachThuocTinh_02 >= this->m_OPTION_LEVEL_01)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 55, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_02, this->m_OPTION_LEVEL_01);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 55, 1000, 1, gConfig.TextVN_SachThuocTinh[2], this->m_OPTION_ACTIVE_01);
			}

			// Slot 3
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 75, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_02, this->m_OPTION_LEVEL_02);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 75, 1000, 1, gConfig.TextVN_SachThuocTinh[3], this->m_OPTION_ACTIVE_02);

			if (this->m_SachThuocTinh_02 >= this->m_OPTION_LEVEL_02)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 75, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_02, this->m_OPTION_LEVEL_02);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 75, 1000, 1, gConfig.TextVN_SachThuocTinh[3], this->m_OPTION_ACTIVE_02);
			}

			// Slot 4
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 105, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_03, this->m_OPTION_LEVEL_03);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 105, 1000, 1, gConfig.TextVN_SachThuocTinh[4], this->m_OPTION_ACTIVE_03);

			if (this->m_SachThuocTinh_03 >= this->m_OPTION_LEVEL_03)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 105, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_03, this->m_OPTION_LEVEL_03);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 105, 1000, 1, gConfig.TextVN_SachThuocTinh[4], this->m_OPTION_ACTIVE_03);
			}

			// Slot 5
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 125, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_03, this->m_OPTION_LEVEL_04);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 125, 1000, 1, gConfig.TextVN_SachThuocTinh[5], this->m_OPTION_ACTIVE_04);

			if (this->m_SachThuocTinh_03 >= this->m_OPTION_LEVEL_04)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 125, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_03, this->m_OPTION_LEVEL_04);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 125, 1000, 1, gConfig.TextVN_SachThuocTinh[5], this->m_OPTION_ACTIVE_04);
			}

			// Slot 6
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 155, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_04, this->m_OPTION_LEVEL_05);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 155, 1000, 1, gConfig.TextVN_SachThuocTinh[6], this->m_OPTION_ACTIVE_05);

			if (this->m_SachThuocTinh_04 >= this->m_OPTION_LEVEL_05)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 155, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_04, this->m_OPTION_LEVEL_05);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 155, 1000, 1, gConfig.TextVN_SachThuocTinh[6], this->m_OPTION_ACTIVE_05);
			}

			// Slot 7
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 175, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_04, this->m_OPTION_LEVEL_06);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 175, 1000, 1, gConfig.TextVN_SachThuocTinh[7], this->m_OPTION_ACTIVE_06);

			if (this->m_SachThuocTinh_04 >= this->m_OPTION_LEVEL_06)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 175, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_04, this->m_OPTION_LEVEL_06);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 175, 1000, 1, gConfig.TextVN_SachThuocTinh[7], this->m_OPTION_ACTIVE_06);
			}

			// Slot 8
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 205, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_05, this->m_OPTION_LEVEL_07);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 205, 1000, 1, gConfig.TextVN_SachThuocTinh[8], this->m_OPTION_ACTIVE_07);

			if (this->m_SachThuocTinh_05 >= this->m_OPTION_LEVEL_07)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 205, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_05, this->m_OPTION_LEVEL_07);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 205, 1000, 1, gConfig.TextVN_SachThuocTinh[8], this->m_OPTION_ACTIVE_07);
			}

			// Slot 9
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 225, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_05, this->m_OPTION_LEVEL_08);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 225, 1000, 1, gConfig.TextVN_SachThuocTinh[9], this->m_OPTION_ACTIVE_08);

			if (this->m_SachThuocTinh_05 >= this->m_OPTION_LEVEL_08)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 225, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_05, this->m_OPTION_LEVEL_08);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 225, 1000, 1, gConfig.TextVN_SachThuocTinh[9], this->m_OPTION_ACTIVE_08);
			}

			// Slot 10
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 255, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_06, this->m_OPTION_LEVEL_09);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 255, 1000, 1, gConfig.TextVN_SachThuocTinh[10], this->m_OPTION_ACTIVE_09);

			if (this->m_SachThuocTinh_06 >= this->m_OPTION_LEVEL_09)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 255, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_06, this->m_OPTION_LEVEL_09);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 255, 1000, 1, gConfig.TextVN_SachThuocTinh[10], this->m_OPTION_ACTIVE_09);
			}

			// Slot 11
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 275, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_06, this->m_OPTION_LEVEL_10);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 275, 1000, 1, gConfig.TextVN_SachThuocTinh[11], this->m_OPTION_ACTIVE_10);

			if (this->m_SachThuocTinh_06 >= this->m_OPTION_LEVEL_10)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 275, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_06, this->m_OPTION_LEVEL_10);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 275, 1000, 1, gConfig.TextVN_SachThuocTinh[11], this->m_OPTION_ACTIVE_10);
			}

			// Slot 12
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 305, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_07, this->m_OPTION_LEVEL_11);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 305, 1000, 1, gConfig.TextVN_SachThuocTinh[12], this->m_OPTION_ACTIVE_11);

			if (this->m_SachThuocTinh_07 >= this->m_OPTION_LEVEL_11)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 305, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_07, this->m_OPTION_LEVEL_11);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 305, 1000, 1, gConfig.TextVN_SachThuocTinh[12], this->m_OPTION_ACTIVE_11);
			}

			// Slot 13
			gInterface.DrawFormat(eWhite, StartX - 10, StartY + 325, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_07, this->m_OPTION_LEVEL_12);

			gInterface.DrawFormat(eWhite, StartX + 50, StartY + 325, 1000, 1, gConfig.TextVN_SachThuocTinh[13], this->m_OPTION_ACTIVE_12);

			if (this->m_SachThuocTinh_07 >= this->m_OPTION_LEVEL_12)
			{
				gInterface.DrawFormat(eYellow, StartX - 10, StartY + 325, 1000, 1, gConfig.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_07, this->m_OPTION_LEVEL_12);

				gInterface.DrawFormat(eYellow, StartX + 50, StartY + 325, 1000, 1, gConfig.TextVN_SachThuocTinh[13], this->m_OPTION_ACTIVE_12);
			}
		}
		//--------------------------------------------------------------
	}
}
#endif



#if(SACHTHUOCTINH_NEW)
void Interface::GetInfoThuocTinh(PMSG_THUOCTINH_UPD * aRecv)
{
	//-----------------------------
	this->m_SachThuocTinh_02 = aRecv->SachThuocTinh_02;
	this->m_SachThuocTinh_03 = aRecv->SachThuocTinh_03;
	this->m_SachThuocTinh_04 = aRecv->SachThuocTinh_04;
	this->m_SachThuocTinh_05 = aRecv->SachThuocTinh_05;
	this->m_SachThuocTinh_06 = aRecv->SachThuocTinh_06;
	this->m_SachThuocTinh_07 = aRecv->SachThuocTinh_07;
}
void Interface::GetInfoThuocTinhAtive(PMSG_THUOCTINH_ATIVE_UPD * aRecv)
{
	//-----------------------------
	this->m_OPTION_LEVEL_01 = aRecv->OPTION_LEVEL_01;
	this->m_OPTION_LEVEL_02 = aRecv->OPTION_LEVEL_02;
	this->m_OPTION_LEVEL_03 = aRecv->OPTION_LEVEL_03;
	this->m_OPTION_LEVEL_04 = aRecv->OPTION_LEVEL_04;
	this->m_OPTION_LEVEL_05 = aRecv->OPTION_LEVEL_05;
	this->m_OPTION_LEVEL_06 = aRecv->OPTION_LEVEL_06;
	this->m_OPTION_LEVEL_07 = aRecv->OPTION_LEVEL_07;
	this->m_OPTION_LEVEL_08 = aRecv->OPTION_LEVEL_08;
	this->m_OPTION_LEVEL_09 = aRecv->OPTION_LEVEL_09;
	this->m_OPTION_LEVEL_10 = aRecv->OPTION_LEVEL_10;
	this->m_OPTION_LEVEL_11 = aRecv->OPTION_LEVEL_11;
	this->m_OPTION_LEVEL_12 = aRecv->OPTION_LEVEL_12;
	this->m_OPTION_ACTIVE_01 = aRecv->OPTION_ACTIVE_01;
	this->m_OPTION_ACTIVE_02 = aRecv->OPTION_ACTIVE_02;
	this->m_OPTION_ACTIVE_03 = aRecv->OPTION_ACTIVE_03;
	this->m_OPTION_ACTIVE_04 = aRecv->OPTION_ACTIVE_04;
	this->m_OPTION_ACTIVE_05 = aRecv->OPTION_ACTIVE_05;
	this->m_OPTION_ACTIVE_06 = aRecv->OPTION_ACTIVE_06;
	this->m_OPTION_ACTIVE_07 = aRecv->OPTION_ACTIVE_07;
	this->m_OPTION_ACTIVE_08 = aRecv->OPTION_ACTIVE_08;
	this->m_OPTION_ACTIVE_09 = aRecv->OPTION_ACTIVE_09;
	this->m_OPTION_ACTIVE_10 = aRecv->OPTION_ACTIVE_10;
	this->m_OPTION_ACTIVE_11 = aRecv->OPTION_ACTIVE_11;
	this->m_OPTION_ACTIVE_12 = aRecv->OPTION_ACTIVE_12;
}
#endif
//---------------------------------------------------------
#if(SACHTHUOCTINH_NEW)
void Interface::BUG_SACHTHUOCTINH(int Number)
{
	SACHTHUOCTINH_REQ pMsg;
	pMsg.h.set(0xFC, 0x09, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
#endif
//---------------------------------------------------------

void Interface::ImageLoad(char* Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)
{
	char path[255];
	strcpy(path, ".\\Data\\");

	strcat(path, Folder);

	std::string Buffer = path;

	size_t pos = Buffer.find("jpg");

	if (pos != std::string::npos)
	{
		Buffer.replace(pos, 3, "ozj");
	}
	else
	{
		pos = Buffer.find("tga");

		if (pos != std::string::npos)
		{
			Buffer.replace(pos, 3, "ozt");
		}
		else
		{
			ErrorMessageBox("[%s] Load error! Pos = %d", Buffer, pos);
		}
	}

	if (FileExist(Buffer.c_str()) == false)
	{
		ErrorMessageBox("[%s] - NOT FOUND", Buffer.c_str());
	}

	pLoadImage(Folder, Code, Arg3, Arg4, Arg5, Arg6);
}



void Interface::LoadImageSauKhiVaoGame()
{
	if (!gInterface.ChoLoadImage) return;

	gEmojis.LoadImages(); //> Agregar esto

#if(DANH_HIEU_NEW == 1)
	pLoadImage("Custom\\DanhHieu\\Main.tga", 0x0899, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\DanhHieu\\Successful.tga", 0x0898, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\DanhHieu\\Progress.tga", 0x0897, 0x2601, 0x2901, 1, 0);
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		pLoadImage("Custom\\DanhHieu\\SuccessNo.tga", 0x0896, 0x2601, 0x2901, 1, 0);
	}
	LoadBitmapA("Interface\\GFx\\ex700\\button_close.tga", 61529, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\DanhHieu\\thanhcong.tga", 531145, GL_NEAREST, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\DanhHieu\\popup_bg_big01.tga", 37899999, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Custom\\DanhHieu\\1.tga", 90101, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\2.tga", 90102, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\3.tga", 90103, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\4.tga", 90104, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\5.tga", 90105, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\6.tga", 90106, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\7.tga", 90107, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\8.tga", 90108, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\9.tga", 90109, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\10.tga", 90110, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\11.tga", 90111, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\12.tga", 90112, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\13.tga", 90113, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\14.tga", 90114, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\15.tga", 90115, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\16.tga", 90116, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\17.tga", 90117, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\18.tga", 90118, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\19.tga", 90119, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\20.tga", 90120, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\21.tga", 90121, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\22.tga", 90122, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\23.tga", 90123, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\24.tga", 90124, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\25.tga", 90125, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\26.tga", 90126, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\27.tga", 90127, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\28.tga", 90128, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\29.tga", 90129, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\30.tga", 90130, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\31.tga", 90131, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\32.tga", 90132, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\33.tga", 90133, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\34.tga", 90134, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\35.tga", 90135, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\36.tga", 90136, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\37.tga", 90137, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\38.tga", 90138, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\39.tga", 90139, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\40.tga", 90140, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\41.tga", 90141, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\42.tga", 90142, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\43.tga", 90143, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\44.tga", 90144, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\45.tga", 90145, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\46.tga", 90146, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\47.tga", 90147, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\48.tga", 90148, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\49.tga", 90149, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\50.tga", 90150, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\01.tga", 91101, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\02.tga", 91102, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\03.tga", 91103, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\04.tga", 91104, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\05.tga", 91105, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\06.tga", 91106, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\07.tga", 91107, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\08.tga", 91108, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\09.tga", 91109, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\10.tga", 91110, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\11.tga", 91111, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\12.tga", 91112, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\13.tga", 91113, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\14.tga", 91114, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\15.tga", 91115, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\16.tga", 91116, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\17.tga", 91117, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\18.tga", 91118, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\19.tga", 91119, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\20.tga", 91120, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\21.tga", 91121, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\22.tga", 91122, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\23.tga", 91123, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\24.tga", 91124, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\25.tga", 91125, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\26.tga", 91126, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\27.tga", 91127, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\28.tga", 91128, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\29.tga", 91129, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\30.tga", 91130, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\31.tga", 91131, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\32.tga", 91132, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\33.tga", 91133, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\34.tga", 91134, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\35.tga", 91135, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\36.tga", 91136, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\37.tga", 91137, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\38.tga", 91138, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\39.tga", 91139, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\40.tga", 91140, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\41.tga", 91141, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\42.tga", 91142, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\43.tga", 91143, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\44.tga", 91144, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\45.tga", 91145, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\46.tga", 91146, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\47.tga", 91147, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\48.tga", 91148, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\49.tga", 91149, 0x2601, 0x2900, 1, 0);
	pLoadImage("Item\\partCharge1\\Obj\\50.tga", 91150, 0x2601, 0x2900, 1, 0);
#endif
#if(DANH_HIEU_NEW == 1)
	Interface::ImageLoad("Custom\\TuLuyen\\1.tga", 10128, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\2.tga", 10129, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\3.tga", 10130, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\4.tga", 10131, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\5.tga", 10132, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\6.tga", 10133, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\7.tga", 10134, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\8.tga", 10135, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\9.tga", 10136, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\10.tga", 10137, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\11.tga", 10138, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\12.tga", 10139, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\13.tga", 10140, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\14.tga", 10141, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\15.tga", 10142, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\16.tga", 10143, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\17.tga", 10144, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\18.tga", 10145, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\19.tga", 10146, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\20.tga", 10147, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\21.tga", 10148, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\22.tga", 10149, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\23.tga", 10150, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\24.tga", 10151, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\25.tga", 10152, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\26.tga", 10153, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\27.tga", 10154, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\28.tga", 10155, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\29.tga", 10156, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\30.tga", 10157, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\31.tga", 10158, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\32.tga", 10159, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\33.tga", 10160, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\34.tga", 10161, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\35.tga", 10162, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\36.tga", 10163, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\37.tga", 10164, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\38.tga", 10165, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\39.tga", 10166, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\TuLuyen\\40.tga", 10167, 0x2601, 0x2900, 1, 0);
#endif


	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		Interface::ImageLoad("Custom\\Interface\\Menu1.tga", 0x7906, 0x2601, 0x2901, 1, 0);
	}
	else
	{
		Interface::ImageLoad("Custom\\Interface\\Menu2.tga", 0x7906, 0x2601, 0x2901, 1, 0);
		Interface::ImageLoad("Custom\\Interface\\Menu_BG.tga", 0x7907, 0x2601, 0x2901, 1, 0);
	}


	Interface::ImageLoad("Custom\\Interface\\Button.tga", 0x7908, 0x2601, 0x2900, 1, 0);
	//MiniMap
	Interface::ImageLoad("Custom\\Maps\\PlayerPoint.jpg", 31460, 0x2600, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\Interface\\none.tga", 31461, 0x2601, 0x2900, 1, 0);
	//--
	//--Interface MiniMap 97/99/S2/S6
	if (MiniMapType == 0)
	{
		Interface::ImageLoad("Custom\\Maps\\edBtUcx_old.tga", 31463, 0x2601, 0x2900, 1, 0); //-- Dungeon
		Interface::ImageLoad("Custom\\Maps\\timeold.tga", 31458, 0x2601, 0x2900, 1, 0); //-- Dungeon
	}
	//--Interface MiniMap ex700/Legends
	if (MiniMapType == 1)
	{
		Interface::ImageLoad("Custom\\Maps\\edBtUcx.tga", 31463, 0x2601, 0x2900, 1, 0); //-- Dungeon
		Interface::ImageLoad("Custom\\Maps\\time700.tga", 31458, 0x2601, 0x2900, 1, 0); //-- Dungeon
	}
	//--
	Interface::ImageLoad("Custom\\Maps\\edBtUcx_2.tga", 31464, 0x2601, 0x2900, 1, 0); //-- Dungeon
	Interface::ImageLoad("Custom\\Maps\\edBtUcx_1.tga", 31459, 0x2601, 0x2900, 1, 0); //-- Dungeon
	Interface::ImageLoad("Custom\\Maps\\YYB6BUk.tga", 31465, 0x2601, 0x2900, 1, 0); //-- Dungeon
	Interface::ImageLoad("Custom\\Maps\\mini_map_ui_blacksmith.tga", 31466, 0x2601, 0x2900, 1, 0); //-- Dungeon
	Interface::ImageLoad("Custom\\Maps\\mini_map_ui_Potion.tga", 31467, 0x2601, 0x2900, 1, 0); //-- Dungeon
	Interface::ImageLoad("Custom\\Maps\\mini_map_ui_baul.tga", 31468, 0x2601, 0x2900, 1, 0); //-- Dungeon
	Interface::ImageLoad("Custom\\Maps\\mini_map_ui_Que.tga", 31469, 0x2601, 0x2900, 1, 0); //-- Dungeon
	Interface::ImageLoad("Custom\\Maps\\mini_map_ui_monsterred.tga", 31471, 0x2601, 0x2900, 1, 0); //-- Dungeon Red
	Interface::ImageLoad("Custom\\Maps\\mini_map_ui_monsterblue.tga", 31472, 0x2601, 0x2900, 1, 0); //-- Dungeon Blue
	Interface::ImageLoad("Custom\\Maps\\mini_map_ui_monstergold.tga", 31473, 0x2601, 0x2900, 1, 0); //-- Dungeon Gold

#if(MOCNAP == 1)
		pLoadImage("Custom\\Interface\\Progress.tga", 0x0897, 0x2601, 0x2901, 1, 0);
#endif

#if(CAMERA)	
	Interface::ImageLoad("Custom\\Interface\\CameraUI_BG.tga", 0x787A, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\Interface\\CameraUI_Switch.tga", 0x787B, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\Interface\\CameraUI_Reset.tga", 0x787C, 0x2601, 0x2900, 1, 0);

#endif

	//=== CTC Mini UI ==//
	Interface::ImageLoad("Custom\\CTCMini\\UiCtc.tga", 32584, 9729, 10496, 1, 0);
	Interface::ImageLoad("Custom\\CTCMini\\CTCMiniMap.tga", 32583, 9729, 10496, 1, 0);
	Interface::ImageLoad("Custom\\CTCMini\\StartCTC.tga", 32585, 9729, 10496, 1, 0);
	Interface::ImageLoad("Custom\\CTCMini\\WinCTC.tga", 32586, 9729, 10496, 1, 0);
	Interface::ImageLoad("Custom\\CTCMini\\LoseCTC.tga", 32589, 9729, 10496, 1, 0); //Trung voi ID effect 32587
	Interface::ImageLoad("Custom\\CTCMini\\DialogCTC.tga", 32588, 9729, 10496, 1, 0);
	Interface::ImageLoad("Custom\\CTCMini\\CharPoint.tga", 32506, 9729, 10496, 1, 0);
	Interface::ImageLoad("Custom\\CTCMini\\OtherCharPoint.tga", 32507, 9729, 10496, 1, 0);
	//==============================//

	Interface::ImageLoad("Custom\\Interface\\tvt_hud.tga", 0x9912, 0x2601, 0x2900, 1, 0);

	Interface::ImageLoad("Custom\\Desig\\khung1.tga", 500001, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\Interface\\Button-30-20.tga", 10099, 0x2601, 0x2900, 1, 0);



	Interface::ImageLoad("Interface\\mini_map_ui_party.tga", 61520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha

	if (gProtect.m_MakeViewTRSData.TooltipS15 == 1)
	{
		//-- itemtooltip
		Interface::ImageLoad("Interface\\GFx\\tooltip_bg01.tga", 61511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
		Interface::ImageLoad("Interface\\GFx\\tooltip_bg02.tga", 61512, 0x2601, 0x2901, 1, 0);
		Interface::ImageLoad("Interface\\GFx\\tooltip_bg03.tga", 61513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
		Interface::ImageLoad("Interface\\GFx\\tooltip_bg04.tga", 61514, 0x2601, 0x2901, 1, 0);
		Interface::ImageLoad("Interface\\GFx\\tooltip_bg06.tga", 61515, 0x2601, 0x2901, 1, 0);
		Interface::ImageLoad("Interface\\GFx\\tooltip_bg07.tga", 61516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
		Interface::ImageLoad("Interface\\GFx\\tooltip_bg08.tga", 61517, 0x2601, 0x2901, 1, 0);
		Interface::ImageLoad("Interface\\GFx\\tooltip_bg09.tga", 61518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	}
	//-- itemtooltip
	Interface::ImageLoad("Interface\\GFx\\popupbg01.tga", 71511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
	Interface::ImageLoad("Interface\\GFx\\popupbg02.tga", 71512, 0x2601, 0x2901, 1, 0);
	Interface::ImageLoad("Interface\\GFx\\popupbg03.tga", 71513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
	Interface::ImageLoad("Interface\\GFx\\popupbg04.tga", 71514, 0x2601, 0x2901, 1, 0);
	Interface::ImageLoad("Interface\\GFx\\popupbg06.tga", 71515, 0x2601, 0x2901, 1, 0);
	Interface::ImageLoad("Interface\\GFx\\popupbg07.tga", 71516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
	Interface::ImageLoad("Interface\\GFx\\popupbg08.tga", 71517, 0x2601, 0x2901, 1, 0);
	Interface::ImageLoad("Interface\\GFx\\popupbg09.tga", 71518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	Interface::ImageLoad("Interface\\GFx\\popup_line_m.tga", 71519, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	Interface::ImageLoad("Interface\\GFx\\popup_line_s.tga", 71520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	Interface::ImageLoad("Interface\\GFx\\Render_buttom_1.tga", 71521, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	Interface::ImageLoad("Interface\\GFx\\Render_buttom_2.tga", 71522, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	Interface::ImageLoad("Interface\\GFx\\Render_buttom_3.tga", 71524, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	Interface::ImageLoad("Interface\\GFx\\RenderBits_Sound.tga", 71523, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	Interface::ImageLoad("Interface\\GFx\\newui_option_volume01.tga", 31596, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	Interface::ImageLoad("Interface\\GFx\\newui_option_volume02.tga", 31597, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	//Party Bar 97/99/S2/S6
	if (MiniMapType == 0)
	{
		Interface::ImageLoad("Custom\\Party\\PartyBar.tga", 81525, GL_LINEAR, GL_CLAMP, 1, 0);
		Interface::ImageLoad("Custom\\Party\\newui_Party_Back.tga", 81520, 0x2601, 0x2901, 1, 0);
		Interface::ImageLoad("Custom\\Party\\newui_Party_flag.tga", 81521, 0x2601, 0x2901, 1, 0);
		Interface::ImageLoad("Custom\\Party\\newui_Party_HpBar.jpg", 81522, 0x2601, 0x2901, 1, 0);
		Interface::ImageLoad("Custom\\Party\\newui_Party_ManaBar.jpg", 81523, 0x2601, 0x2901, 1, 0);
		Interface::ImageLoad("Custom\\Party\\newui_Party_X.tga", 81524, 0x2601, 0x2901, 1, 0);
	}
	//--
	//--Party Bar ex700/Legends
	if (MiniMapType == 1)
	{
		Interface::ImageLoad("Custom\\Party\\Ex700\\PartyBar.tga", 81525, GL_LINEAR, GL_CLAMP, 1, 0);
		Interface::ImageLoad("Custom\\Party\\Ex700\\newui_Party_Back.tga", 81520, 0x2601, 0x2901, 1, 0);
		Interface::ImageLoad("Custom\\Party\\Ex700\\newui_Party_flag.tga", 81521, 0x2601, 0x2901, 1, 0);
		Interface::ImageLoad("Custom\\Party\\Ex700\\newui_Party_HpBar.jpg", 81522, 0x2601, 0x2901, 1, 0);
		Interface::ImageLoad("Custom\\Party\\Ex700\\newui_Party_ManaBar.jpg", 81523, 0x2601, 0x2901, 1, 0);
		Interface::ImageLoad("Custom\\Party\\Ex700\\newui_Party_X.tga", 81524, 0x2601, 0x2901, 1, 0);
	}
	//--
	Interface::ImageLoad("Interface\\newui_number1.tga", 31337, 9729, 10496, 1, 0);

	//newminimap
	Interface::ImageLoad("Interface\\newui_SW_Minimap_Frame.tga", 31608, GL_LINEAR, GL_CLAMP, 1, 0);

	Interface::ImageLoad("Interface\\newui_SW_Time_Frame.tga", 31609, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Interface\\newui_SW_MiniMap_Bt_clearness.jpg", 31617, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Interface\\GFx\\InventoryFrame_RuudShop.tga", 61560, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Interface\\GFx\\Menu_RuudShopFrame.tga", 61561, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Interface\\GFx\\Menu_Button03.tga", 61562, GL_LINEAR, GL_CLAMP, 1, 0);
	//

#if(OANTUTY)
	Interface::ImageLoad("Custom\\RPSMode\\rock.tga", 0x9323, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\RPSMode\\paper.tga", 0x9324, 0x2601, 0x2900, 1, 0);
	Interface::ImageLoad("Custom\\RPSMode\\scissors.tga", 0x9325, 0x2601, 0x2900, 1, 0);
#endif
	//Interface Minimapa 97/99
	//LoadBitmapA("Interface\\newui_SW_Minimap_Frame.tga", 31608, GL_LINEAR, GL_CLAMP, 1, 0);
	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 || gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		Interface::ImageLoad("Interface\\newui_SW_Time_Frame.tga", 31609, GL_LINEAR, GL_CLAMP, 1, 0);
		Interface::ImageLoad("Interface\\newui_SW_MiniMap_Bt_clearness.jpg", 31617, GL_LINEAR, GL_CLAMP, 1, 0);
		Interface::ImageLoad("Interface\\GFx\\InventoryFrame_RuudShop.tga", 61560, GL_LINEAR, GL_CLAMP, 1, 0);
		Interface::ImageLoad("Interface\\GFx\\Menu_RuudShopFrame.tga", 61561, GL_LINEAR, GL_CLAMP, 1, 0);
		Interface::ImageLoad("Interface\\GFx\\Menu_Button03.tga", 61562, GL_LINEAR, GL_CLAMP, 1, 0);
		Interface::ImageLoad("Interface\\GFx\\ex700\\newSytemButton.tga", 61542, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//-- Pet Bar ex700/Legends
	if (MiniMapType == 1)
	{
		Interface::ImageLoad("Interface\\GFx\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//-- Pet Bar 97/99/S2/S6
	if (MiniMapType == 0)
	{
		Interface::ImageLoad("Custom\\Party\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
	}
#if(SACHTHUOCTINH_NEW)
	Interface::ImageLoad("Interface\\GFx\\ex700\\Interface\\SachThuocTinh_UI.tga", 10000, 0x2601, 0x2901, 1, 0);
	Interface::ImageLoad("Interface\\GFx\\ex700\\Interface\\Button-ThuocTinh.tga", 10003, 0x2601, 0x2900, 1, 0); // NÚT XÓA HÒM ĐỒ
#endif
#if(CHONPHEDOILAP)
	Interface::ImageLoad("Custom\\newui-chonphe.jpg", 10004, 0x2601, 0x2901, 1, 0);
#endif
	//--
	if (gProtect.m_MainInfo.DisableCustomCloack == 0)
	{
		gCloak.LoadTexture();
	}


	Interface::ImageLoad("Custom\\Desig\\Login.tga", 71621, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Custom\\Desig\\1.tga", 71622, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Custom\\Desig\\2.tga", 71623, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Custom\\Desig\\3.tga", 71624, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Custom\\Desig\\4.tga", 71625, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Custom\\Desig\\5.tga", 71626, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Custom\\Desig\\6.tga", 71627, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Custom\\Desig\\8.tga", 71629, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Custom\\Desig\\9.tga", 71630, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Custom\\Desig\\10.tga", 71630, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Custom\\Desig\\login_back.tga", 71631, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Custom\\Desig\\reloadcap.jpg", 71632, GL_LINEAR, GL_CLAMP, 1, 0);

#if(B_HON_HOAN)
	//=== Hon Hoan
	Interface::ImageLoad("Custom\\HonHoan\\1.jpg", eImgHonHoan, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Custom\\HonHoan\\2.jpg", eImgHonHoan + 1, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Custom\\HonHoan\\3.jpg", eImgHonHoan + 2, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Custom\\HonHoan\\4.jpg", eImgHonHoan + 3, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Custom\\HonHoan\\5.jpg", eImgHonHoan + 4, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Custom\\HonHoan\\6.jpg", eImgHonHoan + 5, GL_LINEAR, GL_CLAMP, 1, 0);
	Interface::ImageLoad("Custom\\HonHoan\\DemoHonHoan.tga", eDemoHonHoan, GL_LINEAR, GL_CLAMP, 1, 0);
	
#endif
	Interface::ImageLoad("Custom\\ChuThanh.tga", eImgChuThanh, GL_LINEAR, GL_CLAMP, 1, 0);
#if(CUSTOM_EVENTBOSS_BB)
	Interface::ImageLoad("Custom\\EventButton.tga", eImgEventButton, GL_LINEAR, GL_CLAMP, 1, 0);
#endif
	gInterface.m_DataConfigHonHoan.clear();
	gHuyHieuCuongHoa.ImageLoad();
	gCuongHoaWing.ImageLoad();
	gVuKhiRong.ImageLoad();
#if(B_BUFF_PHE)
	this->InputCHBuffPhe = new uintInput(0, 500000, 0);
#endif

	gInterface.ChoLoadImage = false;

}


#if(EVENT_END_LESS)
#include "SEASON3B.h"
float fAlpha = 0.1f;
void BRenderTimeCountDown(float x, float y, float w, int MatchTime)
{
	char lpszStr[256];
	char lpszStrS[10];
	int iMinute = MatchTime / 60;
	DWORD ColorText = 0xE6FCF7FF;
	wsprintf(lpszStr, " %.2d :", iMinute);

	int iSecondTime = MatchTime - (iMinute * 60);
	if (iSecondTime >= 0)
	{
		wsprintf(lpszStrS, " %.2d", iSecondTime);
		strcat(lpszStr, lpszStrS);
	}

	if (iMinute < 5)
	{
		ColorText = 0xFF2121FF;
	}
	if (iMinute < 15)
	{
		wsprintf(lpszStrS, ": %.2d", ((int)WorldTime % 60));
		strcat(lpszStr, lpszStrS);
	}
	HFONT FontTextTime = CreateFontA(14, Main_Font_Width, 0, 0, 700, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, 0x1, 0, 0, Main_Font_Quality, 0, "Tahoma");
	CustomFont.Draw(FontTextTime, x, y, 0xE6FCF7FF, 0x0, w, 0, 3, lpszStr); //Buoc Vao
	DeleteObject(FontTextTime);

}
void BDrawImgSlow()
{
	float fPosX, fPosY, fWidth, fHeight, tu, tv;

	fWidth = 372.0f;
	fHeight = 99.0f;
	fPosX = (MAX_WIN_WIDTH - fWidth) / 2.0f;
	fPosY = (480.0f / 2) - 99.0f;
	tu = fWidth / 512.f;
	tv = fHeight / 128.f;

	if (fAlpha <= 1.0f)
		fAlpha += 0.01f;
	else if (fAlpha >= 0.99f && g_Time.GetTimeCheck(3, 5000))
	{
		fAlpha = 0.1f;
		gInterface.mEndLessEven_ShowImg = 0;
	}
	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	RenderBitmap(32360, fPosX, fPosY, fWidth, fHeight, 0.f, 0.f, tu, tv, true, true, fAlpha);
	pGLSwitch();
	EnableAlphaTest(0);
}
void Interface::EndLessEventWindow()
{
	//==Show Khung Info
	if (gInterface.mEndLessEven_Time > 0 && gInterface.mEndLessEven_State != 0)
	{
		//BRenderTimeCountDown(150, 150, gInterface.mEndLessEven_Time);

		float InfoW = 100;
		float InfoH = 40;
		float InfoX = MAX_WIN_WIDTH - (InfoW + 20);
		float InfoY = MAX_WIN_HEIGHT - (InfoH + 60);
		gCentral.gInfoBox(InfoX, InfoY, InfoW, InfoH, 0x00000096, 0, 0);

		CustomFont.Draw(CustomFont.FontBold, InfoX, InfoY + 3, 0xE6FCF7FF, 0x0, InfoW + 7, 0, 3, "[Vòng %d]", gInterface.mEndLessEven_Wave);
		CustomFont.Draw(CustomFont.FontBold, InfoX, InfoY + 13, 0xE6FCF7FF, 0x00FFE564, InfoW + 7, 0, 3, "Còn (x%d) Quái Vật", gInterface.mEndLessEven_LiveMob);
		CustomFont.Draw(CustomFont.FontBold, InfoX, (InfoY + InfoH) - 17, 0xE6FCF7FF, 0xFFBB0064, InfoW + 7, 0, 3, "Thời Gian Còn Lại");
		BRenderTimeCountDown(InfoX, (InfoY + InfoH) - 7, InfoW + 10, gInterface.mEndLessEven_Time);
	}

	//==Show Img Clear Wave
	if (gInterface.mEndLessEven_ShowImg != 0)
	{
		BDrawImgSlow();
	}
	if (!gInterface.Data[eWindowNPCEndLessTower].OnShow)
	{
		return;
	}
	float CuaSoW = 300;
	float CuaSoH = 200;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;
	gCentral.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindowNPCEndLessTower,FALSE, "Sự Kiện EndLessTower");

	gCentral.gInfoBox(StartX + 7, StartY + 30, CuaSoW - 23, 110, 0x00000096, 0, 0);

	HFONT FontTextTMB = CreateFontA(13, Main_Font_Width, 0, 0, 700, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, 0x1, 0, 0, Main_Font_Quality, 0, "Tahoma");
	HFONT FontTextTM = CreateFontA(13, Main_Font_Width, 0, 0, 400, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, 0x1, 0, 0, Main_Font_Quality, 0, "Tahoma");
	float TextStartY = StartY + 43;

	int ct = 0;
	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct++), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "❂ Sự Kiện EndLessTower"); //
	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct++), 0x00FBFFFF, 0x0, CuaSoW, 0, 1, "❂ Lưu ý "); //
	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct++), 0xEBFFFBFF, 0x0, CuaSoW, 0, 1, "• Tham gia cùng nhóm hoặc 1 mình vào sự kiện (cần Item yêu cầu) "); //
	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct++), 0xEBFFFBFF, 0x0, CuaSoW, 0, 1, "• Xoá toàn bộ Buff, Point, Thùng đồ cá nhân (Giữ nguyên Item đang mặc)"); //
	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct++), 0xEBFFFBFF, 0x0, CuaSoW, 0, 1, "• Point sẽ được tặng bằng nhau !"); //
	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct++), 0xEBFFFBFF, 0x0, CuaSoW, 0, 1, "• Kết thúc Event sẽ khôi phục Point và Đồ như trước khi tham gia"); //
	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct++), 0xEBFFFBFF, 0x0, CuaSoW, 0, 1, "• Nhận thưởng theo số Wave đã đi được"); //
	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct++), 0xEBFFFBFF, 0x0, CuaSoW, 0, 1, "• Mỗi NV Có 2 lượt đi mỗi ngày (Reset sau 12h)"); //

	if (gCentral.gDrawButton(StartX + (CuaSoW / 2) - (110 / 2), StartY + (CuaSoH - 35), 110, 14, "Vào Sự Kiện") && (GetTickCount() - gInterface.Data[eWindowNPCEndLessTower].EventTick) > 300)
	{
		//==Tham Gia
		XULY_CGPACKET pMsg;
		pMsg.header.set(0xD3, 0x30, sizeof(pMsg));
		pMsg.ThaoTac = 1;
		DataSend((LPBYTE)& pMsg, pMsg.header.size);
		gInterface.Data[eWindowNPCEndLessTower].OnShow = false;
	}

	DeleteObject(FontTextTMB);
	DeleteObject(FontTextTM);
}
#endif
