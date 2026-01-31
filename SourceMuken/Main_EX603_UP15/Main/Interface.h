#pragma once

#include "stdafx.h"
#include "import.h"
#include "Protect.h"
#include "Camera.h"
#include "Central.h"
#include "CustomOfflineMode.h"
#define MAX_OBJECT 	1000
#define MAX_WIN_WIDTH 640
#define MAX_WIN_HEIGHT 480
#define MAX_WINDOW_EX 100
#define CS_GET_STRUCT(x, y)	   (1124 * x + *(int*) y)
#define pDrawInterfaceNumBer   ((double(__stdcall*)(float X, float Y, int num, float size)) 0x854FE0)
#define GMT (24 + (gProtect.m_MainInfo.TIME_GMT))


enum ObjectID
{
	eFlag01=1,
	eFlag02, 
	eFlag03,
	eFlag04,
	eFlag05,
	eFlag06,
	eFlag07,
	eFlag08,
	eFlag09,
	eFlag10,
	eFlag11,
	eFlag12,
	eFlag13,
	eFlag14,
	eFlag15,
	eFlag16,
	eFlag17,
	eFlag18,
	eFlag19,
	eFlag20,
	eFlag21,
	eFlag22,
	eTIME,
	eRankPANEL_MAIN,
	eRanking,
	eSAMPLEBUTTON,
	eSAMPLEBUTTON2,
	eVip_MAIN,
	eVip_TITLE,
	eVip_FRAME,
	eVip_FOOTER,
	eVip_DIV,
	eVip_CLOSE,
	eVip_BRONZE,
	eVip_SILVER,
	eVip_GOLD,
	eVip_PLATINUM,
	eVip_STATUS,
	 eChangePass_Main,
     eChangePass_OLD,
     eChangePass_OLD_HIDE,
     eChangePass_NEW_HIDE,
     eChangePass_NEW,
     eChangePass_BTOK,
     eChangePass_BTCLOSE,
	QUAN_LY_TK_MAIN,
	QUAN_LY_TK_CLOSE,
	eQUAN_LY1,
	eQUAN_LY2,
	eQUAN_LY3,
	eQUAN_LY4,
	eQUAN_LY5,
	eQUAN_LY6,
	eQUAN_LY7,
	eQUAN_LY8,
	eQUAN_LY9,
	eQUAN_LY10,
	eQUAN_LY11,
	eQUAN_LY12,
	eQUAN_LY13,
	eQUAN_LYTK1,
	eQUAN_LYTK2,
#if(RANKINGGOC == 1)
	eRanking_MAIN,
	eRanking_CLOSE,
	eRanking_TITLE,
	eRanking_FRAME,
	eRanking_FOOTER,
#endif

#if(RANKING_NEW == 1)
	eMAIN_RANKING,
	eRANKINGALL,
	eRANKINGDW,
	eRANKINGDK,
	eRANKINGEF,
	eRANKINGMG,
	eRANKINGDL,
	eRANKINGSM,
	eRANKINGRF,
	eRANKINGTOPNAP,
	eRANKINGBLOOD,
	eRANKINGDEVIL,
	eRANKINGCHAOS,
#endif


	eLogo,
	eEventTimePANEL_MAIN,
	eEventTime_MAIN,
	eEventTime_TITLE,
	eEventTime_CLOSE,
	eEventTime_FRAME,
	eEventTime_FOOTER,
	EXBEXO_MENU_BUTTON,

#if(OFFLINE_MODE_NEW)
	eOFFEXP_MAIN,
	eOFFEXP_TITLE,
	eOFFEXP_FRAME,
	eOFFEXP_FOOTER,
	eOFFEXP_DIV,
	eOFFEXP_CLOSE,
	eOFFEXP_POINT,
	eOFFEXP_CHECKBOX_BUFF,
	eOFFEXP_CHECKBOX_PICK_ZEN,
	eOFFEXP_CHECKBOX_PICK_JEWELS,
	eOFFEXP_CHECKBOX_PICK_EXC,
	eOFFEXP_CHECKBOX_PICK_ANC,
	eOFFEXP_CHECKBOX_SELECTED_HELPER,
	eOFFEXP_BTN_OK,

	eOFFEXP_SKILL1,
	eOFFEXP_SKILL2,
	eOFFEXP_SKILL3,
#endif
	eMenu,
	eMenuBG,
#if(FLAG_SKIN)
	eMAIN_ThueFlag,
#endif
	eMenu_MAIN,
	eMenu_CLOSE,
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

	eMenu_OPT20,
	//button event

	eMenu_OPT21,
	eMenu_OPT22,
	eMenu_OPT23,
	eMenu_OPT24,
	eMenu_OPT25,
	eMenu_OPT26,
	eMenu_OPT27,
	eMenu_OPT28,
	eMenu_OPT29,
	eMenu_OPT30,
	eMenu_OPT31,
	eMenu_OPT32,
	eMenu_OPT33,
	eMenu_OPT34,
	eMenu_OPT35,
	eMenu_OPT36,
	eMenu_OPT37,
	eMenu_OPT38,
	eMenu_OPT39,
	eMenu_OPT40,
	eMenu_OPT41,
	eMenu_OPT42,
	eMenu_OPT43,
	eMenu_OPT44,
	eMenu_OPT45,
	eMenu_OPT46,
	eMenu_OPT47,
	eMenu_OPT48,
	eMenu_OPT49,
	eMenu_OPT50,
	eMenu_OPT51,
	eMenu_OPT52,
	eMenu_OPT53,
	eMenu_OPT54,
	eMenu_OPT55,
	eMenu_OPT56,
	eMenu_OPT57,
	eMenu_OPT58,
	eMenu_OPT59,
	eMenu_OPT60,
	eMenu_OPT61,
	eMenu_OPT62,


	eCuaSoCTC,
	eTimeCTC,


	eCTCMiniWindow,
	eOTHERCHAR_POINT,
	eCHAR_POINT,

#if(BOSS_GUILD == 1)
	eBossGuildWindow,
#endif

#if(MOCNAP == 1)
	EXBEXO_MOCNAP_MAIN,
	EXBEXO_MOCNAP_CLOSE,
	MOCNAP1,
	MOCNAP2,
	MOCNAP3,
	MOCNAP4,
	MOCNAP5,
	MOCNAP6,
	MOCNAP7,
	MOCNAP8,
	MOCNAP9,
	MOCNAP10,
	MOCNAP11,
	MOCNAP12,
	MOCNAP13,
#endif
#if(THANMA)
	//===Than Ma Chien
	eWindowNPC_ThanMaChien,
	eWindowBXH_ThanMaChien,
#endif
	eDameGray,
	eDameColor,

	eRock,
	ePaper,
	eScissors,

	eCommand_MAIN,
	eCommand_TITLE,
	eCommand_FRAME,
	eCommand_FOOTER,
	eCommand_DIV,
	eCommand_CLOSE,
	eOFFTRADE_JoB,
	eOFFTRADE_JoS,
	eOFFTRADE_JoC,
	eOFFTRADE_WCC,
	eOFFTRADE_WCP,
	eOFFTRADE_WCG,
	eOFFTRADE_OPEN,
	//Minimap

	ePrevEventTC,
	eNextEventTC,	//
	eNextEventDanhHieu,
	ePrevEventDanhHieu,
	eDanhHieu,
	eDanhHieu_TITLE,
	eDanhHieu_FRAME,
	eDanhHieu_FOOTER,
	eDanhHieu_DIV,
	eDanhHieu_INFOBG,
	eDanhHieu_MONEYBG,
	eDanhHieu_CLOSE,
	eDanhHieuSend,
		//
	ePLAYER_POINT,
	eNULL_MAP,
	eLORENCIA_MAP,
	eDUNGEON_MAP,
	eDEVIAS_MAP,
	eNORIA_MAP,
	eLOSTTOWER_MAP,
	eSTADIUM_MAP,
	eATLANS_MAP,
	eTarkan_MAP,
	eElbeland_MAP,
	eICARUS_MAP,
	eLANDOFTRIALS_MAP,
	eAIDA_MAP,
	eCRYWOLF_MAP,
	eKANTRU_MAP,
	eKANTRU3_MAP,
	eBARRACKS_MAP,
	eCALMNESS_MAP,
	eRAKLION_MAP,
	eVULCANUS_MAP,
	eKALRUTAN_MAP,
	eKALRUTAN2_MAP,
	eCONFIRM_MAIN,
	eCONFIRM_BTN_OK,
	eCONFIRM_BTN_CANCEL,
	eCONFIRM_TITLE,
	eCONFIRM_FRAME,
	eCONFIRM_FOOTER,
	eCONFIRM_DIV,
	eNextCommand,
	ePrevCommand,
	eNextEvent,
	ePrevEvent,
//Ex700
	eMainEx700,
	eQuest,
	eCommunity,
	eSystem,
	//--custom
	eSTORE_CLOSE,
	ex_INFO_2,
	eADVANCE_STAT_INFO,
	//--
	//--s2
	eMainS2right,
	eMainS2middle,
	eMainS2left,
	eSkillBox,
	eDragonLeft,
	eDragonRight,
	eCharacter,
	eInventory,
	eParty,
	eFriend,
	eFastMenu,
	eShop,
	eGuild,
	//--custom money
	eMoney1,
	eMoney2,
	CharacterSelect,
	CharacterSelect_Button1,
	CharacterSelect_Button2,
	CharacterSelect_Button3,
	CharacterSelect_Button4,
	CharacterSelect_Button5,
	CharacterCreate_Button1,
	CharacterCreate_Button2,
	CharacterCreate_Button3,
	CharacterCreate_Button4,
	CharacterCreate_Button5,
	CharacterCreate_Button6,
	CharacterCreate_Button7,
	CharacterCreate_SEND,
	CharacterCreate_CANCEL,
	//chat
	chatbackground,
	MINIMAP_FRAME,
	MINIMAP_TIME_FRAME,
	MINIMAP_BUTTOM,
	ButtonSettings,
	ButtonStart,
	ButtonStop,
	ButtonStartAttack,
	eCamera3DInit,
	eCamera3DSwitch,
	strucMoveInv,
	eMainEx700Exp,
	RuudShopListIzq,
	RuudShopListDer,
	RuudShopWindow,
	RuudShopExit,
	eButton1,
	eButton2,
	eButton3,
	eButton4,
	eButton5,

	//-- Button Option New
	eButtonOption1,
	eButtonOption2,
	eButtonOption3,
	eButtonOption4,
	eButtonOption5,
	eButtonOption6,
	eButtonOption7,
	eButtonOption8,

	//--
#if(VONGQUAY_NEW)
	eLuckySpin,
	eLuckySpinRoll,
	eLuckySpinClose,
#endif

#if (DOI_GIOI_TINH)
	eCHANGINGCLASS_MAIN,
	eCHANGINGCLASS_TITLE,
	eCHANGINGCLASS_FRAME,
	eCHANGINGCLASS_FOOTER,
	eCHANGINGCLASS_DIV,
	eCHANGINGCLASS_INFOBG,
	eCHANGINGCLASS_MONEYBG,
	eCHANGINGCLASS_CLOSE,
	eCHANGINGCLASS_DW,
	eCHANGINGCLASS_DK,
	eCHANGINGCLASS_ELF,
	eCHANGINGCLASS_MG,
	eCHANGINGCLASS_DL,
	eCHANGINGCLASS_SUM,
	eCHANGINGCLASS_RF,
#endif




#if(DANH_HIEU_NEW)
	EXBEXO_DANH_HIEU_MAIN,
	EXBEXO_DANH_HIEU_CLOSE,
	EXBEXO_DANH_HIEU_NANG_CAP,

	eDANH_HIEU1,
	eDANH_HIEU2,
#endif

#if(TU_LUYEN_NEW)
	EXBEXO_TU_LUYEN_MAIN,
	EXBEXO_TU_LUYEN_CLOSE,
	EXBEXO_TU_LUYEN_NANG_CAP,

	eTU_LUYEN1,
	eTU_LUYEN2,
#endif





#if(NUT_TINH_NANG)
	eNAPTHE,
	eFACEBOOK,
	eFANPAGE,
	eGOUP,
#endif


#if(EXBEXO_LOAD_SEND_TINH_NANG)
	EXBEXO_AUTORESET_INTERFACE,
	EXBEXO_QUESTCLASS_INTERFACE,
	EXBEXO_OFFATTACK_INTERFACE,
	EXBEXO_UYTHAC_INTERFACE,
	EXBEXO_TAYDIEM_INTERFACE,
	EXBEXO_TAYDIEMMASTER_INTERFACE,
#endif

#if(PARTYSEARCH==1)
	ePARTYSETTINGS_MAIN,
	ePARTYSETTINGS_TITLE,
	ePARTYSETTINGS_FRAME,
	ePARTYSETTINGS_FOOTER,
	ePARTYSETTINGS_DIV,
	ePARTYSETTINGS_CLOSE,
	ePARTYSETTINGS_SYSTEM_ACTIVE,
	ePARTYSETTINGS_ONLY_GUILD,
	ePARTYSETTINGS_ONE_CLASS,
	ePARTYSETTINGS_DARK_WIZARD,
	ePARTYSETTINGS_DARK_KNIGHT,
	ePARTYSETTINGS_ELF,
	ePARTYSETTINGS_MAGIC_GLADIATOR,
	ePARTYSETTINGS_DARK_LORD,
	ePARTYSETTINGS_SUMMONER,
	ePARTYSETTINGS_RAGE_FIGHTER,
	ePARTYSETTINGS_LEVEL_MINUS,
	ePARTYSETTINGS_LEVEL_PLUS,
	ePARTYSETTINGS_OK,
	ePARTYSEARCH_LEFT,
	ePARTYSEARCH_RIGHT,
	ePARTYSEARCH_MAIN,
	ePARTYSEARCH_TITLE,
	ePARTYSEARCH_FRAME,
	ePARTYSEARCH_FOOTER,
	ePARTYSEARCH_DIV,
	ePARTYSEARCH_CLOSE,
#endif


	eTVTHUD,


#if(CAMERA)
	eCAMERA_MAIN,
	eCAMERA_BUTTON1,
	eCAMERA_BUTTON2,

	eCAMERA_BUTTON_UP1,
	eCAMERA_BUTTON_UP2,
#endif

	eConfigHelper,




	eWindow_SkinModel, //= eJewelBank_WITHDRAW+51,
	eWindow_SkinModelNext,
	eWindow_SkinModelPREV,

	//---------------------------------------------------------------------
#if(SACHTHUOCTINH_NEW)
	eSACHTHUOCTINH_INTERFACE,
	eSACHTHUOCTINH_MAIN,
#endif
	//-------------------------------------------------------------------


#if(CHONPHEDOILAP)
		eWindow_ChonPhe,
#endif

#if(EVENT_MAPBAOTIEU)
		eWindow_NPCMoveMapBT,
#endif
#if(B_HON_HOAN)
		eWindow_NangCapHonHoan,
#endif
#if(B_BUFF_PHE)
		eWindow_QuanLyBuffPhe,

#endif
#if(CUSTOM_EVENTBOSS_BB)
		eWindow_CustomEventBoss,
#endif
#if(EVENT_END_LESS)
		eWindowNPCEndLessTower,
#endif
#if (NGAN_HANG_NGOC)
		CustomJewelBank,
		eJewelBank_MAIN,
		eJewelBank_TITLE,
		eJewelBank_FRAME,
		eJewelBank_FOOTER,
		eJewelBank_DIV,
		eJewelBank_CLOSE,
		eJewelBank_NEXT,
		eJewelBank_PREV,

		//Siempre tiene que ser el último de la lista.
		eJewelBank_WITHDRAW,
#endif
};
#if(B_HON_HOAN)
enum ImgHonHoan
{
	eImgHonHoan = 20000,
	eDemoHonHoan = eImgHonHoan + 15,
	eImgHonHoanEnd,
	eImgChuThanh,
#if(CUSTOM_EVENTBOSS_BB)
	eImgEventButton,
#endif
};
#endif
struct InterfaceElement
{
	DWORD	ModelID;
	float	Width;
	float	Height;
	float	X;
	float	Y;
	float	MaxX;
	float	MaxY;
	DWORD	EventTick;
	bool	OnClick;
	bool	OnShow;
	BYTE	Attribute;
	long	OpenedValue;
	BYTE	Speed;
	char	StatValue[20];
	bool	ByClose;
	bool	FirstLoad;
	//int		Type;

	void Open()
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->ByClose = false;
	};

	void Open(int Value, int Speed)
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
		this->FirstLoad = true;
	};

	void Close()
	{
		this->OnShow = false;
		pSetCursorFocus = false;
		this->ByClose = false;
	};

	void Close(int Value, int Speed)
	{
		this->OnShow = false; pSetCursorFocus = false;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
	}

	void CloseAnimated(int Speed)
	{
		pSetCursorFocus = false;
		//this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = true;
	}

	bool Check()
	{
		return this->OnShow;
	}
};

#if(TINHNANG_NEW == 1)
struct BUY_TINH_NANG_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
#endif

//======================================================
struct PMSG_TVTEVENT_UPD
{
	PSBMSG_HEAD	h;
	int ScoreRed;
	int ScoreBlue;
	int KillCount;
	int DieCount;
	int TotalPlayer;
};
//======================================================

struct PMSG_CLIENT_UPD
{
	PSBMSG_HEAD	h;
#if (SACHTHUOCTINH_NEW)
	int SachThuocTinh_01;
#endif
	int DanhHieu;
	int TuLuyen;

};
//--------------------------------------
#if(SACHTHUOCTINH_NEW)
struct SACHTHUOCTINH_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
#endif
//--------------------------------------
//======================================================
#if(SACHTHUOCTINH_NEW)
struct PMSG_THUOCTINH_UPD
{
	PSBMSG_HEAD	h;
	int SachThuocTinh_02;
	int SachThuocTinh_03;
	int SachThuocTinh_04;
	int SachThuocTinh_05;
	int SachThuocTinh_06;
	int SachThuocTinh_07;
};

struct PMSG_THUOCTINH_ATIVE_UPD
{
	PSBMSG_HEAD	h;
	int OPTION_LEVEL_01;
	int OPTION_LEVEL_02;
	int OPTION_LEVEL_03;
	int OPTION_LEVEL_04;
	int OPTION_LEVEL_05;
	int OPTION_LEVEL_06;
	int OPTION_LEVEL_07;
	int OPTION_LEVEL_08;
	int OPTION_LEVEL_09;
	int OPTION_LEVEL_10;
	int OPTION_LEVEL_11;
	int OPTION_LEVEL_12;
	int OPTION_ACTIVE_01;
	int OPTION_ACTIVE_02;
	int OPTION_ACTIVE_03;
	int OPTION_ACTIVE_04;
	int OPTION_ACTIVE_05;
	int OPTION_ACTIVE_06;
	int OPTION_ACTIVE_07;
	int OPTION_ACTIVE_08;
	int OPTION_ACTIVE_09;
	int OPTION_ACTIVE_10;
	int OPTION_ACTIVE_11;
	int OPTION_ACTIVE_12;
};
#endif




class Interface
{


public:
	void		Load();
	static void LoadImages();
	static int		LoadImg(char * Folder, DWORD ID);
	void		LoadImages2(char * Folder, int Code, int Arg3, int Arg4, int Arg5);
	static void LoadModels();
	static void Work();
	std::vector<BCUSTOM_SKINMODEL_DATA> m_SkinModelData;
	std::vector<SKIN_MODEL_DATA> m_SkinModelInfoSelect;
	bool SelectInfoSkin;
	int ConfirmSlot;
	float PetY;
	float PetX;
	int lastReport;
	int frameCount;
	int frameRate;
	char FPS_REAL[30];
	void UPDATE_FPS();
	void guiMonitore();
	int iniciador;
	int msPing;
	int lastSend;
	int validar;
	char ServerPing[50];
	char ultimoPing[50];
	int ultimo_Ping;
	char ServerRTT[50];
	char ultimoRTT[50];
	int ultimo_RTT;

	InterfaceElement Data[MAX_OBJECT];

public:
	Interface();
	virtual ~Interface();
	void RenderObjectSystem();

	//--------------------------------------
	void TvTEventEx(PMSG_TVTEVENT_UPD * aRecv);
	int m_ScoreRed;
	int m_ScoreBlue;
	int m_KillCount;
	int m_DieCount;
	int m_TotalPlayer;
	//--------------------------------------


	void GetInfoClient(PMSG_CLIENT_UPD * aRecv);
	int m_DanhHieu;
	int m_TuLuyen;
	int m_VuKhiRong;


//-- System Windows
	void OpenVipWindow(){ this->Data[eVip_MAIN].OnShow = true; };
	void CloseVipWindow() { this->Data[eVip_MAIN].OnShow = false; }
	bool CheckVipWindow() { return this->Data[eVip_MAIN].OnShow; };
	void DrawVipWindow();
	bool EventVipWindow_Main(DWORD Event);
	bool EventVipWindow_Close(DWORD Event);
	bool EventVipWindow_Bronze(DWORD Event);
	bool EventVipWindow_Silver(DWORD Event);
	bool EventVipWindow_Gold(DWORD Event);
	bool EventVipWindow_Platinum(DWORD Event);
	bool EventVipWindow_StatusVip(DWORD Event);
	//--
	void DrawMenu();
	bool EventDrawMenu_Open(DWORD Event);
	void OpenMenuWindow() { this->Data[eMenu_MAIN].OnShow = true; };
	void CloseMenuWindow() {this->Data[eMenu_MAIN].OnShow = false; };
	bool CheckMenuWindow() { return this->Data[eMenu_MAIN].OnShow; };
	void DrawMenuOpen();
	bool EventDrawMenu_Close(DWORD Event);
	bool EventDrawMenu_Op1(DWORD Event);
	bool EventDrawMenu_Op2(DWORD Event);
	bool EventDrawMenu_Op3(DWORD Event);
	bool EventDrawMenu_Op4(DWORD Event);
	bool EventDrawMenu_Op5(DWORD Event);
	bool EventDrawMenu_Op6(DWORD Event);
	bool EventDrawMenu_Op7(DWORD Event);
	bool EventDrawMenu_Op8(DWORD Event);
	bool EventDrawMenu_Op9(DWORD Event);
	bool EventDrawMenu_Op10(DWORD Event);
	bool EventDrawMenu_Op11(DWORD Event);
	bool EventDrawMenu_Op12(DWORD Event);

	bool EventDrawMenu_Op20(DWORD Event);
	//--
	void CloseEventTimeWindow() { this->Data[eEventTimePANEL_MAIN].OnShow = false; }
	void CloseERankWindow() { this->Data[eRankPANEL_MAIN].OnShow = false; }
	void CloseECommandWindow() { this->Data[eCommand_MAIN].OnShow = false; }
	void CloseJewelBankWindow() { this->Data[eJewelBank_MAIN].OnShow = false; };

	void DrawConfirmOpen();
	bool EventConfirm_OK(DWORD Event);
	bool EventConfirm_CANCEL(DWORD Event);
	void        WindowsKG();
//-- Funtions
	void BindObject(short ObjectID, DWORD ModelID, float Width, float Height, float X, float Y);
	void DrawGUI(short ObjectID, float PosX, float PosY);
	void DrawGUI2(short ObjectID, float PosX, float PosY);
	void WindowDraw(short ObjectID, float PosX, float PosY);


	void DrawGUI3(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawTimeUI();
	int DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	void DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void ResetDrawIMG(short ObjectID);
	int DrawMessage(int Mode, LPCSTR Text, ...);
	void DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	//void DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);

#if(VONGQUAY_NEW)
	static void DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
#endif


	void DrawWindow(int ObjMain, int ObjTitle, int ObjFrame, int ObjFooter, int Repeat, float X, float Y, char* Text);
	bool CheckWindow(int WindowID);
	int CloseWindow(int WindowID);
	int OpenWindow(int WindowID);
	bool IsWorkZone2(float X, float Y, float MaxX, float MaxY);
	bool IsWorkZone(short ObjectID);
	bool   IsWorkZone4(float, float, float, float);
	//-- Mover MiniMapa
	bool	IsWorkZone(float X, float Y, float MaxX, float MaxY, bool a5 = false);

	float GetResizeX(short ObjectID);
	int DrawToolTip(int X, int Y, LPCSTR Text, ...);
	float DrawRepeatGUI(short MonsterID, float X, float Y, int Count);
	float DrawRepeatGUIScale(short MonsterID, float X, float Y,float ScaleX, float ScaleY, int Count);
	void DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color);
	void DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawLogo(bool active);
	void CloseCustomWindow();

	//Mini Map
	void DrawMiniMap();
	bool MiniMapCheck();
	bool CombinedChecks();
	bool CheckMap();
	void SwitchMiniMap();

	void	MiniMapMini();

	// ex700
	void DrawInterfaceCustom();
	// s2
	void DrawInterfaceS2Menu();
	void DrawInterface97Menu();
	void EventNewInterface_All(DWORD Event);
	void EventNewInterface97_All(DWORD Event);
	void DrawCoord();
	void DrawInterfaceDragonLS3();
	void DrawInterfaceDragonRS3();
	// Advanced Stats
	bool WindowEx[MAX_WINDOW_EX];
	bool CheckWindowEx(int WindowID);
	void DrawBarForm(float PosX,float PosY,float Width,float Height,GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	//--
	void OpenConfig(int type);
	void SwitchCamera();
	void SwitchChatExpand();
	void SwitchHideDanhHieu();
	void CameraInit();

	void SwitchAntiLag1();
	void SwitchAntiLag2();
	void SwitchHidePlayer();

	int  AntiLag1;
	int  AntiLag2;

	int  AntiLagPlayer;




	bool Button(DWORD Event, int WinID, int ButtonID, bool Type);
	bool		ButtonEx(DWORD Event, int ButtonID, bool Type);
	int			DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...);
	void		DrawText(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);

	void DrawPing();
	void SendPingRecv();
	void NewLoadInterface();
	static void DrawZenAndRud(int a1, int a2, int a3, int a4);

	BOOL        is_auto;
	BOOL        is_autotron;

	void	    TvTEvent();

#if(CHIEN_TRUONG_CO)
	void		DrawChienTruongCo();
	void		DrawTimeCTC();
#endif

#if(BOSS_GUILD == 1)
	void		DrawBossGuildWindow();
	void		DrawBossGuildMap();
#endif
	//////CTCmini//////////
	void		DrawCTCMiNiMap();
	void		DrawCTCMiniWindow();
#if(VANTHANH_CHUCHAY == 1)
	void DrawTextRun();
	bool QuayLai;
#endif
#if (DOI_GIOI_TINH)
	void		DrawChangingClassWindow();
	bool		EventChangingClassWindow_Main(DWORD Event);
	bool		EventChangingClassWindow_Close(DWORD Event);
	bool		EventChangingClassWindow_DW(DWORD Event);
	bool		EventChangingClassWindow_DK(DWORD Event);
	bool		EventChangingClassWindow_ELF(DWORD Event);
	bool		EventChangingClassWindow_MG(DWORD Event);
	bool		EventChangingClassWindow_DL(DWORD Event);
	bool		EventChangingClassWindow_SUM(DWORD Event);
	bool		EventChangingClassWindow_RF(DWORD Event);
#endif

#if(OANTUTY)
	void		DrawRPS();
	void		EventRPS_Main(DWORD Event);
#endif

#if(OFFLINE_MODE_NEW)
	void		DrawOffExpWindow();
	bool		EventOffExpWindow_Main(DWORD Event);
	void		SwitchOffExpWindoState() { (Data[eOFFEXP_MAIN].OnShow == true) ? Data[eOFFEXP_MAIN].Close() : gOfflineMode.CGOfflineModeSend(); };
#endif


#if(EXBEXO_LOAD_SEND_TINH_NANG)
	void		DRAW_TINHNANG_INTERFACE();
	bool		EVENT_TINHNANG_INTERFACE(DWORD Event);
	bool		EVENT_AUTORESET_INTERFACE(DWORD Event);
	bool		EVENT_LAMNHIEMVU_INTERFACE(DWORD Event);
	bool		EVENT_OFFATTACK_INTERFACE(DWORD Event);
	bool		EVENT_UYTHAC_INTERFACE(DWORD Event);
	bool		EVENT_TAYDIEM_INTERFACE(DWORD Event);
	bool		EVENT_TAYDIEM_MASTER_INTERFACE(DWORD Event);
#endif
	//---------------------------------------------------------------------------------------------------------------------------------

#if(NUT_TINH_NANG)
	void DrawnNapThe();
	void DrawnFacebook();
	//void DrawFanpage();
	//void DrawGoup();

	bool		EventDrawnNapThe_Open(DWORD Event);
	bool		EventDrawnFacebook_Open(DWORD Event);
	//bool		EventDrawFanpage_Open(DWORD Event);
	//bool		EventDrawGoup_Open(DWORD Event);
#endif
#if (THANMA)
	//=== Event Chien Truong Than Ma
	void DrawTMAllWindows();
	int	m_EventTMTimeCount;
	int m_EventTMState;
	int m_EventTMMap;
	int mCalcTimeEventTick;
	int m_TMScoreThienThan;
	int m_TMScoreAcQuy;
	int m_TMChienBXHC;
	EVENTHANMA_BXH m_ThanMaChienBXH[10];
	void TMReset() // OK
	{
		this->m_TMChienBXHC = 0;
		this->m_TMScoreThienThan = 0;
		this->m_TMScoreAcQuy = 0;
		this->mCalcTimeEventTick = 0;
		this->m_EventTMTimeCount = 0;
	}
#endif


#if(TINHNANG_NEW == 1)
	void BUY_TINH_NANG_GAME(int Number);
#endif

	//Bat tat 
	BYTE m_ChangeClassButton;

	//---------------------------------------------------------------------------------------

//======================================================
#if(SACHTHUOCTINH_NEW)
	void BUG_SACHTHUOCTINH(int Number);
#endif
#if(SACHTHUOCTINH_NEW)
	void GetInfoThuocTinh(PMSG_THUOCTINH_UPD * aRecv);
	int m_SachThuocTinh_01;
	int m_SachThuocTinh_02;
	int m_SachThuocTinh_03;
	int m_SachThuocTinh_04;
	int m_SachThuocTinh_05;
	int m_SachThuocTinh_06;
	int m_SachThuocTinh_07;

	void GetInfoThuocTinhAtive(PMSG_THUOCTINH_ATIVE_UPD * aRecv);
	int m_OPTION_LEVEL_01;
	int m_OPTION_LEVEL_02;
	int m_OPTION_LEVEL_03;
	int m_OPTION_LEVEL_04;
	int m_OPTION_LEVEL_05;
	int m_OPTION_LEVEL_06;
	int m_OPTION_LEVEL_07;
	int m_OPTION_LEVEL_08;
	int m_OPTION_LEVEL_09;
	int m_OPTION_LEVEL_10;
	int m_OPTION_LEVEL_11;
	int m_OPTION_LEVEL_12;
	int m_OPTION_ACTIVE_01;
	int m_OPTION_ACTIVE_02;
	int m_OPTION_ACTIVE_03;
	int m_OPTION_ACTIVE_04;
	int m_OPTION_ACTIVE_05;
	int m_OPTION_ACTIVE_06;
	int m_OPTION_ACTIVE_07;
	int m_OPTION_ACTIVE_08;
	int m_OPTION_ACTIVE_09;
	int m_OPTION_ACTIVE_10;
	int m_OPTION_ACTIVE_11;
	int m_OPTION_ACTIVE_12;

#endif
	void		ImageLoad(char* Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6);
#if(SACHTHUOCTINH_NEW)
	void		DrawSachThuocTinhInterface();
	bool		EventSachThuocTinhInterface(DWORD Event);

	void		DrawSachThuocTinh();
	void	    OpenSachThuocTinhWindow() { this->Data[eSACHTHUOCTINH_MAIN].OnShow = true; };
	void	    CloseSachThuocTinhWindow() { this->Data[eSACHTHUOCTINH_MAIN].OnShow = false; };
	bool	    CheckSachThuocTinhWindow() { return this->Data[eSACHTHUOCTINH_MAIN].OnShow; };
#endif
	//---------------------------------------------------------------------------------------
	bool ChoLoadImage;
	void LoadImageSauKhiVaoGame();

#if(B_HON_HOAN)
	std::map<int, CONFIDATA_HONHOAN> m_DataConfigHonHoan;
#endif

#if(B_BUFF_PHE)
	uintInput* InputCHBuffPhe;
#endif
#if(CUSTOM_EVENTBOSS_BB)
	void      DrawItem3D(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int ExtOption, int Ancient, bool PickUp, float Scale = 1.0f, bool Center = true);
#endif
#if(EVENT_END_LESS)
	WORD		mEndLessEven_Wave;
	WORD		mEndLessEven_LiveMob;
	DWORD		mEndLessEven_Time;
	BYTE		mEndLessEven_State;
	BYTE		mEndLessEven_ShowImg;
	void mEndLessEvenInfoClear()
	{
		mEndLessEven_Wave = 0;
		mEndLessEven_LiveMob = 0;
		mEndLessEven_Time = 0;
		mEndLessEven_State = 0;
	}
	void EndLessEventWindow();
#endif
private:

};
extern Interface gInterface;
