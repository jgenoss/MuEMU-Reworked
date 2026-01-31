#include "stdafx.h"
#include "..\..\Util\CCRC32.H"
#include "CustomBuyVip.h"
#include "CustomCommandInfo.h"
#include "CustomEventTimeText.h"
#include "CustomItem.h"
#include "CustomJewel.h"
#include "CustomMessage.h"
#include "CustomMonster.h"
#include "CustomNpcName.h"
#include "CustomWing.h"
#include "SmokeEffect.h"
#include "ThemidaSDK.h"
#include "CustomGloves.h"
#include "CustomCrossBow.h"
#include "CustomPet.h"
#include "CustomCloak.h"
#include "Fog.h"
#include "CustomItemPosition.h"
#include "CustomEffectRemake.h"
#include "ItemManager.h"
#include "ItemValue.h"
#include "ModelEffect.h"
#include "CustomEventBoss.h"

struct MAIN_FILE_INFO
{
	BYTE LauncherType; 
	char LauncherName[32];
	char CustomerName[32];
	char IpAddress[32];
	WORD IpAddressPort;
	char ClientVersion[8];
	char ClientSerial[17];
	char WindowName[32];
	char ScreenShotPath[50];
	char ClientName[32];
	char HackName[32];
	char PluginName5[32];
	char PluginName1[32];
	char PluginName2[32];
	char PluginName3[32];
	char PluginName4[32];
	char CameraName[32];
	char ServerName1[32];
	char ServerName2[32];
	char ServerName3[32];
	char ServerName4[32];
	DWORD ClientCRC32;
	DWORD HackCRC32;
	DWORD Plugin5CRC32;
	DWORD Plugin1CRC32;
	DWORD Plugin2CRC32;
	DWORD Plugin3CRC32;
	DWORD Plugin4CRC32;
	DWORD CameraCRC32;

	DWORD HelperActiveAlert;
	DWORD HelperActiveLevel;
	DWORD DWMaxAttackSpeed;
	DWORD DKMaxAttackSpeed;
	DWORD FEMaxAttackSpeed;
	DWORD MGMaxAttackSpeed;
	DWORD DLMaxAttackSpeed;
	DWORD SUMaxAttackSpeed;
	DWORD RFMaxAttackSpeed;
	DWORD ReconnectTime;
	DWORD ReconnectConnectAccountTime;
	DWORD ReconnectConnectCharacterTime;
	DWORD ReduceMemory;
	DWORD EnableMiniMapCircular;
	DWORD MaxGameInstances;
	DWORD AlwaysnameShowType;
	DWORD MinimapX;
	DWORD MinimapY;
	DWORD RemoveClass;
	DWORD CharsCount;
	DWORD RankUserType;
	DWORD DisableTree; 
	DWORD CsSkill; 
	DWORD DisableReflectEffect;
	DWORD EnableVipShop;
	DWORD VipTypes;
	DWORD PrintLogo;
	DWORD CustomMenuSwitch;
	DWORD CustomMenuType;
	DWORD MenuButtons[12];
	DWORD EnableCoinStatus;
	DWORD EnableShopValueSystem;
	DWORD CustomStoreEnableJoB;
	DWORD CustomStoreEnableJoS;
	DWORD CustomStoreEnableJoC;
	DWORD CustomStoreEnableCoin1;
	DWORD CustomStoreEnableCoin2;
	DWORD CustomStoreEnableCoin3;
	DWORD CustomOffStoreEnable;
	DWORD CustomMonsterEnable;
	DWORD DisablePartyHpBar;
	DWORD RankUserShowOverHead;
	DWORD RankUserOnlyOnSafeZone;
	DWORD RankUserShowReset;
	DWORD RankUserShowMasterReset;
	DWORD RankUserNeedAltKey;
	DWORD EnableRankVIP;
	DWORD EnableRankTuChan;
	DWORD EnableNutButton;
	DWORD EnableNutC;
	DWORD EnableHieuUng;
	//---
	DWORD ScanLoiClient;

	DWORD CustomInterfaceType;
	DWORD CustomRemoveCoord;
	DWORD TIME_GMT;
	DWORD MonitorFPS;
	DWORD MonitorMS;
	DWORD LimitFPS;
	DWORD EffectPlus15;
	DWORD DisableGens;
	DWORD DisableTabMap;
	DWORD DisableHelper;
	DWORD Disable380ButtonChaoBox;
	DWORD DisableAdvance;
	DWORD DisableEffectRemake;
	DWORD DisableCustomClaws;
	DWORD DisableCustomBow;
	DWORD DisableCustomCloack;
	DWORD DisableCustomPosition;
	DWORD DisableCustomPet;
	DWORD DisableSocketInvetori;
	DWORD DisableRepeirInInventory;
	DWORD DisableButtonOpenStore;
	DWORD DisableButtonInventoryExt;
	DWORD DisableButtonQuestInStats;
	DWORD DisableButtonPetsInStats;
	DWORD DisableButtonSkillMaster;
	DWORD SelectCharAnimate;
	DWORD SelectCharS13;
	DWORD EnableCameraZoom;
	DWORD Cam_ZoomMax;
	DWORD Cam_ZoomMin;
	DWORD InventoryUPGRADE;
	DWORD CameraZoom;
	//--
	//--Custom NPC
	//--ElfSoldier
	DWORD CustomElfSoldier;
	DWORD CustomElfSoldierWings;
	DWORD CustomElfSoldierHelm;
	DWORD CustomElfSoldierArmor;
	DWORD CustomElfSoldierPants;
	DWORD CustomElfSoldierGloves;
	DWORD CustomElfSoldierBoots;
	DWORD CustomTypeElfSoldierWeapon1;
	DWORD CustomElfSoldierWeapon1;
	DWORD CustomTypeElfSoldierWeapon2;
	DWORD CustomElfSoldierWeapon2;
	DWORD CustomElfSoldierHelmLevel;
	DWORD CustomElfSoldierArmorLevel;
	DWORD CustomElfSoldierPantsLevel;
	DWORD CustomElfSoldierGlovesLevel;
	DWORD CustomElfSoldierBootsLevel;
	DWORD CustomElfSoldierWeaponFirstLevel;
	DWORD CustomElfSoldierWeaponSecondLevel;
	DWORD CustomElfSoldierHelmExcellent;
	DWORD CustomElfSoldierArmorExcellent;
	DWORD CustomElfSoldierPantsExcellent;
	DWORD CustomElfSoldierGlovesExcellent;
	DWORD CustomElfSoldierBootsExcellent;
	DWORD CustomElfSoldierWeaponFirstExcellent;
	DWORD CustomElfSoldierWeaponSecondExcellent;

	//--Marlon
	DWORD CustomMarlon;
	DWORD CustomMarlonWings;
	DWORD CustomMarlonHelm;
	DWORD CustomMarlonArmor;
	DWORD CustomMarlonPants;
	DWORD CustomMarlonGloves;
	DWORD CustomMarlonBoots;
	DWORD CustomMarlonWeapon1;
	DWORD CustomTypeMarlonWeapon1;
	DWORD CustomMarlonWeapon2;
	DWORD CustomTypeMarlonWeapon2;
	DWORD CustomMarlonHelmLevel;
	DWORD CustomMarlonArmorLevel;
	DWORD CustomMarlonPantsLevel;
	DWORD CustomMarlonGlovesLevel;
	DWORD CustomMarlonBootsLevel;
	DWORD CustomMarlonWeaponFirstLevel;
	DWORD CustomMarlonWeaponSecondLevel;
	DWORD CustomMarlonHelmExcellent;
	DWORD CustomMarlonArmorExcellent;
	DWORD CustomMarlonPantsExcellent;
	DWORD CustomMarlonGlovesExcellent;
	DWORD CustomMarlonBootsExcellent;
	DWORD CustomMarlonWeaponFirstExcellent;
	DWORD CustomMarlonWeaponSecondExcellent;

	//--ChaosCardMaster
	DWORD CustomChaosCard;
	DWORD CustomChaosCardWings;
	DWORD CustomChaosCardHelm;
	DWORD CustomChaosCardArmor;
	DWORD CustomChaosCardPants;
	DWORD CustomChaosCardGloves;
	DWORD CustomChaosCardBoots;
	DWORD CustomChaosCardWeapon1;
	DWORD CustomTypeChaosCardWeapon1;
	DWORD CustomChaosCardWeapon2;
	DWORD CustomTypeChaosCardWeapon2;
	DWORD CustomChaosCardHelmLevel;
	DWORD CustomChaosCardArmorLevel;
	DWORD CustomChaosCardPantsLevel;
	DWORD CustomChaosCardGlovesLevel;
	DWORD CustomChaosCardBootsLevel;
	DWORD CustomChaosCardWeaponFirstLevel;
	DWORD CustomChaosCardWeaponSecondLevel;
	DWORD CustomChaosCardHelmExcellent;
	DWORD CustomChaosCardArmorExcellent;
	DWORD CustomChaosCardPantsExcellent;
	DWORD CustomChaosCardGlovesExcellent;
	DWORD CustomChaosCardBootsExcellent;
	DWORD CustomChaosCardWeaponFirstExcellent;
	DWORD CustomChaosCardWeaponSecondExcellent;

	//--Guard1
	DWORD CustomGuard1;
	DWORD CustomGuard1Wings;
	DWORD CustomGuard1Helm;
	DWORD CustomGuard1Armor;
	DWORD CustomGuard1Pants;
	DWORD CustomGuard1Gloves;
	DWORD CustomGuard1Boots;
	DWORD CustomGuard1Weapon1;
	DWORD CustomTypeGuard1Weapon1;
	DWORD CustomGuard1Weapon2;
	DWORD CustomTypeGuard1Weapon2;
	DWORD CustomGuard1HelmLevel;
	DWORD CustomGuard1ArmorLevel;
	DWORD CustomGuard1PantsLevel;
	DWORD CustomGuard1GlovesLevel;
	DWORD CustomGuard1BootsLevel;
	DWORD CustomGuard1WeaponFirstLevel;
	DWORD CustomGuard1WeaponSecondLevel;
	DWORD CustomGuard1HelmExcellent;
	DWORD CustomGuard1ArmorExcellent;
	DWORD CustomGuard1PantsExcellent;
	DWORD CustomGuard1GlovesExcellent;
	DWORD CustomGuard1BootsExcellent;
	DWORD CustomGuard1WeaponFirstExcellent;
	DWORD CustomGuard1WeaponSecondExcellent;

	//--Guard2
	DWORD CustomGuard2;
	DWORD CustomGuard2Wings;
	DWORD CustomGuard2Helm;
	DWORD CustomGuard2Armor;
	DWORD CustomGuard2Pants;
	DWORD CustomGuard2Gloves;
	DWORD CustomGuard2Boots;
	DWORD CustomGuard2Weapon1;
	DWORD CustomTypeGuard2Weapon1;
	DWORD CustomGuard2Weapon2;
	DWORD CustomTypeGuard2Weapon2;
	DWORD CustomGuard2HelmLevel;
	DWORD CustomGuard2ArmorLevel;
	DWORD CustomGuard2PantsLevel;
	DWORD CustomGuard2GlovesLevel;
	DWORD CustomGuard2BootsLevel;
	DWORD CustomGuard2WeaponFirstLevel;
	DWORD CustomGuard2WeaponSecondLevel;
	DWORD CustomGuard2HelmExcellent;
	DWORD CustomGuard2ArmorExcellent;
	DWORD CustomGuard2PantsExcellent;
	DWORD CustomGuard2GlovesExcellent;
	DWORD CustomGuard2BootsExcellent;
	DWORD CustomGuard2WeaponFirstExcellent;
	DWORD CustomGuard2WeaponSecondExcellent;

	//--CursedWizard
	DWORD CustomCursedWizard;
	DWORD CustomCursedWizardWings;
	DWORD CustomCursedWizardHelm;
	DWORD CustomCursedWizardArmor;
	DWORD CustomCursedWizardPants;
	DWORD CustomCursedWizardGloves;
	DWORD CustomCursedWizardBoots;
	DWORD CustomCursedWizardWeapon1;
	DWORD CustomTypeCursedWizardWeapon1;
	DWORD CustomCursedWizardWeapon2;
	DWORD CustomTypeCursedWizardWeapon2;
	DWORD CustomCursedWizardHelmLevel;
	DWORD CustomCursedWizardArmorLevel;
	DWORD CustomCursedWizardPantsLevel;
	DWORD CustomCursedWizardGlovesLevel;
	DWORD CustomCursedWizardBootsLevel;
	DWORD CustomCursedWizardWeaponFirstLevel;
	DWORD CustomCursedWizardWeaponSecondLevel;
	DWORD CustomCursedWizardHelmExcellent;
	DWORD CustomCursedWizardArmorExcellent;
	DWORD CustomCursedWizardPantsExcellent;
	DWORD CustomCursedWizardGlovesExcellent;
	DWORD CustomCursedWizardBootsExcellent;
	DWORD CustomCursedWizardWeaponFirstExcellent;
	DWORD CustomCursedWizardWeaponSecondExcellent;

	//--LeoHelper
	DWORD CustomLeoHelper;
	DWORD CustomLeoHelperWings;
	DWORD CustomLeoHelperHelm;
	DWORD CustomLeoHelperArmor;
	DWORD CustomLeoHelperPants;
	DWORD CustomLeoHelperGloves;
	DWORD CustomLeoHelperBoots;
	DWORD CustomLeoHelperHelmLevel;
	DWORD CustomLeoHelperArmorLevel;
	DWORD CustomLeoHelperPantsLevel;
	DWORD CustomLeoHelperGlovesLevel;
	DWORD CustomLeoHelperBootsLevel;
	DWORD CustomLeoHelperHelmExcellent;
	DWORD CustomLeoHelperArmorExcellent;
	DWORD CustomLeoHelperPantsExcellent;
	DWORD CustomLeoHelperGlovesExcellent;
	DWORD CustomLeoHelperBootsExcellent;


	CUSTOM_MESSAGE_INFO EngCustomMessageInfo[MAX_CUSTOM_MESSAGE];
	CUSTOM_MESSAGE_INFO PorCustomMessageInfo[MAX_CUSTOM_MESSAGE];
	CUSTOM_MESSAGE_INFO SpnCustomMessageInfo[MAX_CUSTOM_MESSAGE];
	CUSTOM_JEWEL_INFO CustomJewelInfo[MAX_CUSTOM_JEWEL];
	CUSTOM_WING_INFO CustomWingInfo[MAX_CUSTOM_WING];
	CUSTOM_ITEM_INFO CustomItemInfo[MAX_CUSTOM_ITEM];
	CUSTOM_BUYVIP_INFO CustomBuyVipInfo[MAX_CUSTOM_BUYVIP];
	CUSTOM_COMMAND_INFO CustomCommandInfo[MAX_CUSTOM_COMMAND];
	CUSTOM_EVENT_INFO CustomEventInfo[MAX_EVENTTIME];
	CUSTOM_SMOKEEFFECT CustomSmokeEffect[MAX_SMOKE_ITEMS];
	CUSTOM_FOG CustomFog[MAX_FOG];
	CUSTOMMONSTER_DATA CustomMonsters[MAX_CUSTOMMONSTER];
	BOSSCLASS_DATA	   CustomBossClass[MAX_BOSSCLASS]; //Boss Class

	NPCNAME_DATA CustomNPCName[MAX_CUSTOM_NPCNAME];
	//--
	CUSTOM_BOW_INFO CustomBowInfo[MAX_CUSTOM_BOW];
	CUSTOM_RF_GLOVES CustomGloves[MAX_CUSTOM_GLOVES];
	CUSTOM_PET_INFO CustomPetInfo[MAX_PET_ITEM];
	CUSTOMCLOAK_DATA m_CustomCloak[MAX_CUSTOMCLOAK];
	CUSTOM_POSITION_INFO CustomPosition[MAX_POSITION_ITEM];
	REMAKE_EFFECT CustomRemake[MAX_REMAKE_EFFECT];
	//--
	ITEM_INFO m_ItemInfoEx[MAX_ITEM2];
	CUSTOM_MODEL_EFFECT_INFO m_CustomModelInfo[MAX_MODEL_EFFECT];

#if(CUSTOM_EVENTBOSS_BB)	
	EventGroupData	m_BEventData[MAX_CUSTOM_EVENTBOSS];
	InfoTextData	m_BInfoTextData[MAX_DATA_INFOTEXT];
	InfoRewardData	m_BInfoRewardData[MAX_DATA_INFOREWARD];
#endif
};

int _tmain(int argc,_TCHAR* argv[]) // OK
{
	CLEAR_START

	ENCODE_START

	MAIN_FILE_INFO info;

	memset(&info,0,sizeof(info));
	
	GetPrivateProfileString("MainInfo","CustomerName","",info.CustomerName,sizeof(info.CustomerName),".\\MainInfo.ini");

	info.LauncherType = GetPrivateProfileInt("MainInfo","LauncherType",0,".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","LauncherName","XTLauncherExecutable",info.LauncherName,sizeof(info.LauncherName),".\\MainInfo.ini");
	
	GetPrivateProfileString("MainInfo","IpAddress","",info.IpAddress,sizeof(info.IpAddress),".\\MainInfo.ini");

	info.IpAddressPort = GetPrivateProfileInt("MainInfo","IpAddressPort",44405,".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","ClientVersion","",info.ClientVersion,sizeof(info.ClientVersion),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","ClientSerial","",info.ClientSerial,sizeof(info.ClientSerial),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","WindowName","[MU]",info.WindowName,sizeof(info.WindowName),".\\MainInfo.ini");
	
	GetPrivateProfileString("MainInfo","ScreenShotPath","",info.ScreenShotPath,sizeof(info.ScreenShotPath),".\\MainInfo.ini");
	
	GetPrivateProfileString("MainInfo","ClientName","",info.ClientName,sizeof(info.ClientName),".\\MainInfo.ini");
	
	//-------------------

	GetPrivateProfileString("MainInfo","AntiHackName","",info.HackName,sizeof(info.HackName),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","PluginName1","",info.PluginName1,sizeof(info.PluginName1),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","PluginName2","",info.PluginName2,sizeof(info.PluginName2),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","PluginName3","",info.PluginName3,sizeof(info.PluginName3),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","PluginName4","",info.PluginName4,sizeof(info.PluginName4),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","PluginName5","",info.PluginName5,sizeof(info.PluginName5),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","CameraName","",info.CameraName,sizeof(info.CameraName),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","ServerName1","",info.ServerName1,sizeof(info.ServerName1),".\\MainInfo.ini");
	
	GetPrivateProfileString("MainInfo","ServerName2","",info.ServerName2,sizeof(info.ServerName2),".\\MainInfo.ini");
	
	GetPrivateProfileString("MainInfo","ServerName3","",info.ServerName3,sizeof(info.ServerName3),".\\MainInfo.ini");
	
	GetPrivateProfileString("MainInfo","ServerName4","",info.ServerName4,sizeof(info.ServerName4),".\\MainInfo.ini");

	//--

	info.HelperActiveAlert = GetPrivateProfileInt("HelperInfo","HelperActiveAlert",0,".\\MainInfo.ini");

	info.HelperActiveLevel = GetPrivateProfileInt("HelperInfo","HelperActiveLevel",80,".\\MainInfo.ini");

	info.DWMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","DWMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.DKMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","DKMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.FEMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","FEMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.MGMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","MGMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.DLMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","DLMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.SUMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","SUMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.RFMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","RFMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.ReconnectTime = GetPrivateProfileInt("ReconnectInfo", "ReconnectTime", 0, ".\\MainInfo.ini");
	info.ReconnectConnectAccountTime = GetPrivateProfileInt("ReconnectInfo", "ReconnectConnectAccountTime", 0, ".\\MainInfo.ini");
	info.ReconnectConnectCharacterTime = GetPrivateProfileInt("ReconnectInfo", "ReconnectConnectCharacterTime", 0, ".\\MainInfo.ini");

	info.ReduceMemory = GetPrivateProfileInt("Custom","DelectCharacter",300,".\\MainInfo.ini");
	
	info.EnableMiniMapCircular = GetPrivateProfileInt("Custom","EnableMiniMapCircular",0,".\\MainInfo.ini");
	

	










	info.MaxGameInstances = GetPrivateProfileInt("Custom","MaxGameInstances",0,".\\MainInfo.ini");
	
	info.AlwaysnameShowType = GetPrivateProfileInt("Custom","AlwaysnameShowType",0,".\\MainInfo.ini");

	info.MinimapX = GetPrivateProfileInt("Custom","MinimapX",0,".\\MainInfo.ini");
	
	info.MinimapY = GetPrivateProfileInt("Custom","MinimapY",0,".\\MainInfo.ini");

	info.RemoveClass = GetPrivateProfileInt("Custom","RemoveClass",0,".\\MainInfo.ini");

	info.CharsCount = GetPrivateProfileInt("Custom", "CharsCount", 7, ".\\MainInfo.ini");


	info.RankUserType = GetPrivateProfileInt("Custom","RankUserType",0,".\\MainInfo.ini");

	info.DisableTree = GetPrivateProfileInt("Custom","DisableMasterSkillTree",0,".\\MainInfo.ini");

	info.CsSkill = GetPrivateProfileInt("Custom","EnableCsSkillsAllMaps",0,".\\MainInfo.ini");

	info.DisableReflectEffect = GetPrivateProfileInt("Custom","DisableReflectEffect",0,".\\MainInfo.ini");

	info.RankUserShowOverHead = GetPrivateProfileInt("Custom","RankUserShowOverHead",0,".\\MainInfo.ini");

	info.RankUserOnlyOnSafeZone = GetPrivateProfileInt("Custom","RankUserOnlyOnSafeZone",1,".\\MainInfo.ini");

	info.RankUserShowReset = GetPrivateProfileInt("Custom","RankUserShowReset",1,".\\MainInfo.ini");

	info.RankUserShowMasterReset = GetPrivateProfileInt("Custom","RankUserShowMasterReset",1,".\\MainInfo.ini");

	info.RankUserNeedAltKey = GetPrivateProfileInt("Custom","RankUserNeedAltKey",0,".\\MainInfo.ini");

	info.EnableRankVIP = GetPrivateProfileInt("Custom","EnableRankVIP",0,".\\MainInfo.ini");

	info.EnableRankTuChan = GetPrivateProfileInt("Custom","EnableRankTuChan",0,".\\MainInfo.ini");

	info.EnableNutButton = GetPrivateProfileInt("Custom", "EnableNutButton", 0, ".\\MainInfo.ini");

	info.EnableNutC = GetPrivateProfileInt("Custom", "EnableNutC", 0, ".\\MainInfo.ini");

	info.EnableHieuUng = GetPrivateProfileInt("Custom", "EnableHieuUng", 0, ".\\MainInfo.ini");

	info.EnableVipShop = GetPrivateProfileInt("Custom","EnableVipShop",0,".\\MainInfo.ini");

	info.VipTypes = GetPrivateProfileInt("Custom","VipTypes",3,".\\MainInfo.ini");

	info.PrintLogo = GetPrivateProfileInt("Custom","PrintLogo",0,".\\MainInfo.ini");

	info.CustomMenuSwitch = GetPrivateProfileInt("Custom","CustomMenuSwitch",0,".\\MainInfo.ini");

	info.CustomMenuType = GetPrivateProfileInt("Custom","CustomMenuType",0,".\\MainInfo.ini");


	info.MenuButtons[0] = GetPrivateProfileInt("Custom","Bat_GioEventButton",0,".\\MainInfo.ini");

	info.MenuButtons[1] = GetPrivateProfileInt("Custom","Bat_MuaVipButton",0,".\\MainInfo.ini");

	info.MenuButtons[2] = GetPrivateProfileInt("Custom","Bat_BXHButton",0,".\\MainInfo.ini");

	info.MenuButtons[3] = GetPrivateProfileInt("Custom","Bat_LenhGameButton",0,".\\MainInfo.ini");

	info.MenuButtons[4] = GetPrivateProfileInt("Custom","Bat_NganHangButton",0,".\\MainInfo.ini");

	info.MenuButtons[5] = GetPrivateProfileInt("Custom","Bat_DoiGioiTinh",0,".\\MainInfo.ini");

	info.MenuButtons[6] = GetPrivateProfileInt("Custom","Bat_TaoNhomButton",0,".\\MainInfo.ini");

	info.MenuButtons[7] = GetPrivateProfileInt("Custom","Bat_TimNhomButton",0,".\\MainInfo.ini");

	info.MenuButtons[8] = GetPrivateProfileInt("Custom","Bat_VongQuayMMButton",0,".\\MainInfo.ini");

	info.MenuButtons[9] = GetPrivateProfileInt("Custom","Bat_DanhHieu",0,".\\MainInfo.ini");

	info.MenuButtons[10] = GetPrivateProfileInt("Custom", "Bat_VipNhanVat", 0, ".\\MainInfo.ini");

	info.MenuButtons[11] = GetPrivateProfileInt("Custom", "Bat_TuLuyen", 0, ".\\MainInfo.ini");



	//info.MenuButtons[8] = GetPrivateProfileInt("Custom","EnableOptionButton",0,".\\MainInfo.ini");

	info.EnableCoinStatus = GetPrivateProfileInt("Custom","EnableCoinStatus",0,".\\MainInfo.ini");

	info.EnableShopValueSystem  = GetPrivateProfileInt("Custom","EnableShopValueSystem",0,".\\MainInfo.ini");

	info.CustomStoreEnableJoB  = GetPrivateProfileInt("Custom","EnableStoreBlessButtom",0,".\\MainInfo.ini");

	info.CustomStoreEnableJoS  = GetPrivateProfileInt("Custom","EnableStoreSoulButtom",0,".\\MainInfo.ini");

	info.CustomStoreEnableJoC  = GetPrivateProfileInt("Custom","EnableStoreChaosButtom",0,".\\MainInfo.ini");

	info.CustomStoreEnableCoin1  = GetPrivateProfileInt("Custom","EnableStoreCoin1Buttom",0,".\\MainInfo.ini");

	info.CustomStoreEnableCoin2  = GetPrivateProfileInt("Custom","EnableStoreCoin2Buttom",0,".\\MainInfo.ini");

	info.CustomStoreEnableCoin3  = GetPrivateProfileInt("Custom","EnableStoreCoin3Buttom",0,".\\MainInfo.ini");

	info.CustomOffStoreEnable  = GetPrivateProfileInt("Custom","EnableOffStoreButtom",0,".\\MainInfo.ini");

	info.CustomMonsterEnable  = GetPrivateProfileInt("Custom","CustomMonsterEnable",0,".\\MainInfo.ini");
	
	info.CustomInterfaceType  = GetPrivateProfileInt("Custom","CustomInterfaceType",0,".\\MainInfo.ini");


	// Scan Fix Client
	info.ScanLoiClient = GetPrivateProfileInt("Custom", "ScanLoiClient", 0, ".\\MainInfo.ini");

	//----------------------------------------------------------------------------------------
	info.TIME_GMT  = GetPrivateProfileInt("TimeZone","TIME_GMT",0,".\\MainInfo.ini");
	
	info.MonitorFPS  = GetPrivateProfileInt("Custom","MonitorFPS",0,".\\MainInfo.ini");

	info.MonitorMS  = GetPrivateProfileInt("Custom","MonitorMS",0,".\\MainInfo.ini");

	info.LimitFPS  = GetPrivateProfileInt("Custom","LimitFPS ",0,".\\MainInfo.ini");
	
	info.EffectPlus15  = GetPrivateProfileInt("Effect","EffectPlus15",0,".\\MainInfo.ini");

	info.DisablePartyHpBar  = GetPrivateProfileInt("Disable","DisablePartyHpBar",0,".\\MainInfo.ini");
	
	info.DisableGens  = GetPrivateProfileInt("Disable","DisableGens ",0,".\\MainInfo.ini");

	info.DisableTabMap  = GetPrivateProfileInt("Disable","DisableTabMap ",0,".\\MainInfo.ini");

	info.DisableHelper  = GetPrivateProfileInt("Disable","DisableHelper ",0,".\\MainInfo.ini");

	info.Disable380ButtonChaoBox  = GetPrivateProfileInt("Disable","Disable380ButtonChaoBox ",0,".\\MainInfo.ini");

	info.DisableAdvance  = GetPrivateProfileInt("Disable","DisableAdvance",0,".\\MainInfo.ini");
	
	info.DisableCustomClaws  = GetPrivateProfileInt("Disable","DisableCustomClaws ",0,".\\MainInfo.ini");

	info.DisableCustomBow  = GetPrivateProfileInt("Disable","DisableCustomBow ",0,".\\MainInfo.ini");

	info.DisableCustomCloack  = GetPrivateProfileInt("Disable","DisableCustomCloack ",0,".\\MainInfo.ini");

	info.DisableCustomPosition  = GetPrivateProfileInt("Disable","DisableCustomPosition ",0,".\\MainInfo.ini");

	info.DisableCustomPet  = GetPrivateProfileInt("Disable","DisableCustomPet ",0,".\\MainInfo.ini");

	info.DisableEffectRemake  = GetPrivateProfileInt("Disable","DisableEffectRemake ",0,".\\MainInfo.ini");

	info.DisableSocketInvetori  = GetPrivateProfileInt("Disable","DisableSocketInvetori ",0,".\\MainInfo.ini");

	info.DisableRepeirInInventory  = GetPrivateProfileInt("Disable","DisableRepeirInInventory ",0,".\\MainInfo.ini");

	info.DisableButtonOpenStore  = GetPrivateProfileInt("Disable","DisableButtonOpenStore ",0,".\\MainInfo.ini");

	info.DisableButtonInventoryExt  = GetPrivateProfileInt("Disable","DisableButtonInventoryExt ",0,".\\MainInfo.ini");

	info.DisableButtonQuestInStats  = GetPrivateProfileInt("Disable","DisableButtonQuestInStats ",0,".\\MainInfo.ini");

	info.DisableButtonPetsInStats  = GetPrivateProfileInt("Disable","DisableButtonPetsInStats ",0,".\\MainInfo.ini");

	info.DisableButtonSkillMaster  = GetPrivateProfileInt("Disable","DisableButtonSkillMaster ",0,".\\MainInfo.ini");

	info.SelectCharAnimate  = GetPrivateProfileInt("UPGRADE","SelectCharAnimate ",0,".\\MainInfo.ini");

	info.SelectCharS13  = GetPrivateProfileInt("UPGRADE","SelectCharS13 ",0,".\\MainInfo.ini");

	info.EnableCameraZoom  = GetPrivateProfileInt("CameraConfig","EnableCameraZoom ",0,".\\MainInfo.ini");

	info.Cam_ZoomMax  = GetPrivateProfileInt("CameraConfig","Cam_ZoomMax ",0,".\\MainInfo.ini");

	info.Cam_ZoomMin  = GetPrivateProfileInt("CameraConfig","Cam_ZoomMin ",0,".\\MainInfo.ini");

	info.InventoryUPGRADE  = GetPrivateProfileInt("UPGRADE","InventoryUPGRADE ",0,".\\MainInfo.ini");

	info.CameraZoom  = GetPrivateProfileInt("UPGRADE","CameraZoom ",0,".\\MainInfo.ini");




	//-- Custom NPC
	//---ElfSoldier
	info.CustomElfSoldier = GetPrivateProfileInt("SoldierELF", "CustomElfSoldier", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierWings = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierWings", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierHelm = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierHelm", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierArmor = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierArmor", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierPants = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierPants", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierGloves = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierGloves", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierBoots = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierBoots", 0, "Common\\NPCItems.ini");
	info.CustomTypeElfSoldierWeapon1 = GetPrivateProfileInt("SoldierELF", "CustomType1", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierWeapon1 = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierWeapon1", 0, "Common\\NPCItems.ini");
	info.CustomTypeElfSoldierWeapon2 = GetPrivateProfileInt("SoldierELF", "CustomType2", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierWeapon2 = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierWeapon2", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierHelmLevel = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierHelmLevel", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierArmorLevel = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierArmorLevel", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierPantsLevel = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierPantsLevel", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierGlovesLevel = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierGlovesLevel", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierBootsLevel = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierBootsLevel", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierWeaponFirstLevel = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierWeaponFirstLevel", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierWeaponSecondLevel = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierWeaponSecondLevel", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierHelmExcellent = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierHelmExcellent", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierArmorExcellent = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierArmorExcellent", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierPantsExcellent = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierPantsExcellent", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierGlovesExcellent = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierGlovesExcellent", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierBootsExcellent = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierBootsExcellent", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierWeaponFirstExcellent = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierWeaponFirstExcellent", 0, "Common\\NPCItems.ini");
	info.CustomElfSoldierWeaponSecondExcellent = GetPrivateProfileInt("SoldierELF", "CustomElfSoldierWeaponSecondExcellent", 0, "Common\\NPCItems.ini");

	//---Marlon
	info.CustomMarlon = GetPrivateProfileInt("Marlon", "CustomMarlon", 0, "Common\\NPCItems.ini");
	info.CustomMarlonWings = GetPrivateProfileInt("Marlon", "CustomMarlonWings", 0, "Common\\NPCItems.ini");
	info.CustomMarlonHelm = GetPrivateProfileInt("Marlon", "CustomMarlonHelm", 0, "Common\\NPCItems.ini");
	info.CustomMarlonArmor = GetPrivateProfileInt("Marlon", "CustomMarlonArmor", 0, "Common\\NPCItems.ini");
	info.CustomMarlonPants = GetPrivateProfileInt("Marlon", "CustomMarlonPants", 0, "Common\\NPCItems.ini");
	info.CustomMarlonGloves = GetPrivateProfileInt("Marlon", "CustomMarlonGloves", 0, "Common\\NPCItems.ini");
	info.CustomMarlonBoots = GetPrivateProfileInt("Marlon", "CustomMarlonBoots", 0, "Common\\NPCItems.ini");
	info.CustomTypeMarlonWeapon1 = GetPrivateProfileInt("Marlon", "CustomType1", 0, "Common\\NPCItems.ini");
	info.CustomMarlonWeapon1 = GetPrivateProfileInt("Marlon", "CustomMarlonWeapon1", 0, "Common\\NPCItems.ini");
	info.CustomTypeMarlonWeapon2 = GetPrivateProfileInt("Marlon", "CustomType2", 0, "Common\\NPCItems.ini");
	info.CustomMarlonWeapon2 = GetPrivateProfileInt("Marlon", "CustomMarlonWeapon2", 0, "Common\\NPCItems.ini");
	info.CustomMarlonHelmLevel = GetPrivateProfileInt("Marlon", "CustomMarlonHelmLevel", 0, "Common\\NPCItems.ini");
	info.CustomMarlonArmorLevel = GetPrivateProfileInt("Marlon", "CustomMarlonArmorLevel", 0, "Common\\NPCItems.ini");
	info.CustomMarlonPantsLevel = GetPrivateProfileInt("Marlon", "CustomMarlonPantsLevel", 0, "Common\\NPCItems.ini");
	info.CustomMarlonGlovesLevel = GetPrivateProfileInt("Marlon", "CustomMarlonGlovesLevel", 0, "Common\\NPCItems.ini");
	info.CustomMarlonBootsLevel = GetPrivateProfileInt("Marlon", "CustomMarlonBootsLevel", 0, "Common\\NPCItems.ini");
	info.CustomMarlonWeaponFirstLevel = GetPrivateProfileInt("Marlon", "CustomMarlonWeaponFirstLevel", 0, "Common\\NPCItems.ini");
	info.CustomMarlonWeaponSecondLevel = GetPrivateProfileInt("Marlon", "CustomMarlonWeaponSecondLevel", 0, "Common\\NPCItems.ini");
	info.CustomMarlonHelmExcellent = GetPrivateProfileInt("Marlon", "CustomMarlonHelmExcellent", 0, "Common\\NPCItems.ini");
	info.CustomMarlonArmorExcellent = GetPrivateProfileInt("Marlon", "CustomMarlonArmorExcellent", 0, "Common\\NPCItems.ini");
	info.CustomMarlonPantsExcellent = GetPrivateProfileInt("Marlon", "CustomMarlonPantsExcellent", 0, "Common\\NPCItems.ini");
	info.CustomMarlonGlovesExcellent = GetPrivateProfileInt("Marlon", "CustomMarlonGlovesExcellent", 0, "Common\\NPCItems.ini");
	info.CustomMarlonBootsExcellent = GetPrivateProfileInt("Marlon", "CustomMarlonBootsExcellent", 0, "Common\\NPCItems.ini");
	info.CustomMarlonWeaponFirstExcellent = GetPrivateProfileInt("Marlon", "CustomMarlonWeaponFirstExcellent", 0, "Common\\NPCItems.ini");
	info.CustomMarlonWeaponSecondExcellent = GetPrivateProfileInt("Marlon", "CustomMarlonWeaponSecondExcellent", 0, "Common\\NPCItems.ini");
	//---ChaosCard
	info.CustomChaosCard = GetPrivateProfileInt("ChaosCard", "CustomChaosCard", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardWings = GetPrivateProfileInt("ChaosCard", "CustomChaosCardWings", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardHelm = GetPrivateProfileInt("ChaosCard", "CustomChaosCardHelm", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardArmor = GetPrivateProfileInt("ChaosCard", "CustomChaosCardArmor", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardPants = GetPrivateProfileInt("ChaosCard", "CustomChaosCardPants", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardGloves = GetPrivateProfileInt("ChaosCard", "CustomChaosCardGloves", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardBoots = GetPrivateProfileInt("ChaosCard", "CustomChaosCardBoots", 0, "Common\\NPCItems.ini");
	info.CustomTypeChaosCardWeapon1 = GetPrivateProfileInt("ChaosCard", "CustomType1", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardWeapon1 = GetPrivateProfileInt("ChaosCard", "CustomChaosCardWeapon1", 0, "Common\\NPCItems.ini");
	info.CustomTypeChaosCardWeapon2 = GetPrivateProfileInt("ChaosCard", "CustomType2", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardWeapon2 = GetPrivateProfileInt("ChaosCard", "CustomChaosCardWeapon2", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardHelmLevel = GetPrivateProfileInt("ChaosCard", "CustomChaosCardHelmLevel", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardArmorLevel = GetPrivateProfileInt("ChaosCard", "CustomChaosCardArmorLevel", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardPantsLevel = GetPrivateProfileInt("ChaosCard", "CustomChaosCardPantsLevel", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardGlovesLevel = GetPrivateProfileInt("ChaosCard", "CustomChaosCardGlovesLevel", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardBootsLevel = GetPrivateProfileInt("ChaosCard", "CustomChaosCardBootsLevel", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardWeaponFirstLevel = GetPrivateProfileInt("ChaosCard", "CustomChaosCardWeaponFirstLevel", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardWeaponSecondLevel = GetPrivateProfileInt("ChaosCard", "CustomChaosCardWeaponSecondLevel", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardHelmExcellent = GetPrivateProfileInt("ChaosCard", "CustomChaosCardHelmExcellent", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardArmorExcellent = GetPrivateProfileInt("ChaosCard", "CustomChaosCardArmorExcellent", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardPantsExcellent = GetPrivateProfileInt("ChaosCard", "CustomChaosCardPantsExcellent", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardGlovesExcellent = GetPrivateProfileInt("ChaosCard", "CustomChaosCardGlovesExcellent", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardBootsExcellent = GetPrivateProfileInt("ChaosCard", "CustomChaosCardBootsExcellent", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardWeaponFirstExcellent = GetPrivateProfileInt("ChaosCard", "CustomChaosCardWeaponFirstExcellent", 0, "Common\\NPCItems.ini");
	info.CustomChaosCardWeaponSecondExcellent = GetPrivateProfileInt("ChaosCard", "CustomChaosCardWeaponSecondExcellent", 0, "Common\\NPCItems.ini");
	//---Guard1
	info.CustomGuard1 = GetPrivateProfileInt("Guard1", "CustomGuard1", 0, "Common\\NPCItems.ini");
	info.CustomGuard1Wings = GetPrivateProfileInt("Guard1", "CustomGuard1Wings", 0, "Common\\NPCItems.ini");
	info.CustomGuard1Helm = GetPrivateProfileInt("Guard1", "CustomGuard1Helm", 0, "Common\\NPCItems.ini");
	info.CustomGuard1Armor = GetPrivateProfileInt("Guard1", "CustomGuard1Armor", 0, "Common\\NPCItems.ini");
	info.CustomGuard1Pants = GetPrivateProfileInt("Guard1", "CustomGuard1Pants", 0, "Common\\NPCItems.ini");
	info.CustomGuard1Gloves = GetPrivateProfileInt("Guard1", "CustomGuard1Gloves", 0, "Common\\NPCItems.ini");
	info.CustomGuard1Boots = GetPrivateProfileInt("Guard1", "CustomGuard1Boots", 0, "Common\\NPCItems.ini");
	info.CustomTypeGuard1Weapon1 = GetPrivateProfileInt("Guard1", "CustomType1", 0, "Common\\NPCItems.ini");
	info.CustomGuard1Weapon1 = GetPrivateProfileInt("Guard1", "CustomGuard1Weapon1", 0, "Common\\NPCItems.ini");
	info.CustomTypeGuard1Weapon2 = GetPrivateProfileInt("Guard1", "CustomType2", 0, "Common\\NPCItems.ini");
	info.CustomGuard1Weapon2 = GetPrivateProfileInt("Guard1", "CustomGuard1Weapon2", 0, "Common\\NPCItems.ini");
	info.CustomGuard1HelmLevel = GetPrivateProfileInt("Guard1", "CustomGuard1HelmLevel", 0, "Common\\NPCItems.ini");
	info.CustomGuard1ArmorLevel = GetPrivateProfileInt("Guard1", "CustomGuard1ArmorLevel", 0, "Common\\NPCItems.ini");
	info.CustomGuard1PantsLevel = GetPrivateProfileInt("Guard1", "CustomGuard1PantsLevel", 0, "Common\\NPCItems.ini");
	info.CustomGuard1GlovesLevel = GetPrivateProfileInt("Guard1", "CustomGuard1GlovesLevel", 0, "Common\\NPCItems.ini");
	info.CustomGuard1BootsLevel = GetPrivateProfileInt("Guard1", "CustomGuard1BootsLevel", 0, "Common\\NPCItems.ini");
	info.CustomGuard1WeaponFirstLevel = GetPrivateProfileInt("Guard1", "CustomGuard1WeaponFirstLevel", 0, "Common\\NPCItems.ini");
	info.CustomGuard1WeaponSecondLevel = GetPrivateProfileInt("Guard1", "CustomGuard1WeaponSecondLevel", 0, "Common\\NPCItems.ini");
	info.CustomGuard1HelmExcellent = GetPrivateProfileInt("Guard1", "CustomGuard1HelmExcellent", 0, "Common\\NPCItems.ini");
	info.CustomGuard1ArmorExcellent = GetPrivateProfileInt("Guard1", "CustomGuard1ArmorExcellent", 0, "Common\\NPCItems.ini");
	info.CustomGuard1PantsExcellent = GetPrivateProfileInt("Guard1", "CustomGuard1PantsExcellent", 0, "Common\\NPCItems.ini");
	info.CustomGuard1GlovesExcellent = GetPrivateProfileInt("Guard1", "CustomGuard1GlovesExcellent", 0, "Common\\NPCItems.ini");
	info.CustomGuard1BootsExcellent = GetPrivateProfileInt("Guard1", "CustomGuard1BootsExcellent", 0, "Common\\NPCItems.ini");
	info.CustomGuard1WeaponFirstExcellent = GetPrivateProfileInt("Guard1", "CustomGuard1WeaponFirstExcellent", 0, "Common\\NPCItems.ini");
	info.CustomGuard1WeaponSecondExcellent = GetPrivateProfileInt("Guard1", "CustomGuard1WeaponSecondExcellent", 0, "Common\\NPCItems.ini");
	//---Guard2
	info.CustomGuard2 = GetPrivateProfileInt("Guard2", "CustomGuard2", 0, "Common\\NPCItems.ini");
	info.CustomGuard2Wings = GetPrivateProfileInt("Guard2", "CustomGuard2Wings", 0, "Common\\NPCItems.ini");
	info.CustomGuard2Helm = GetPrivateProfileInt("Guard2", "CustomGuard2Helm", 0, "Common\\NPCItems.ini");
	info.CustomGuard2Armor = GetPrivateProfileInt("Guard2", "CustomGuard2Armor", 0, "Common\\NPCItems.ini");
	info.CustomGuard2Pants = GetPrivateProfileInt("Guard2", "CustomGuard2Pants", 0, "Common\\NPCItems.ini");
	info.CustomGuard2Gloves = GetPrivateProfileInt("Guard2", "CustomGuard2Gloves", 0, "Common\\NPCItems.ini");
	info.CustomGuard2Boots = GetPrivateProfileInt("Guard2", "CustomGuard2Boots", 0, "Common\\NPCItems.ini");
	info.CustomTypeGuard2Weapon1 = GetPrivateProfileInt("Guard2", "CustomType1", 0, "Common\\NPCItems.ini");
	info.CustomGuard2Weapon1 = GetPrivateProfileInt("Guard2", "CustomGuard2Weapon1", 0, "Common\\NPCItems.ini");
	info.CustomTypeGuard2Weapon2 = GetPrivateProfileInt("Guard2", "CustomType2", 0, "Common\\NPCItems.ini");
	info.CustomGuard2Weapon2 = GetPrivateProfileInt("Guard2", "CustomGuard2Weapon2", 0, "Common\\NPCItems.ini");
	info.CustomGuard2HelmLevel = GetPrivateProfileInt("Guard2", "CustomGuard2HelmLevel", 0, "Common\\NPCItems.ini");
	info.CustomGuard2ArmorLevel = GetPrivateProfileInt("Guard2", "CustomGuard2ArmorLevel", 0, "Common\\NPCItems.ini");
	info.CustomGuard2PantsLevel = GetPrivateProfileInt("Guard2", "CustomGuard2PantsLevel", 0, "Common\\NPCItems.ini");
	info.CustomGuard2GlovesLevel = GetPrivateProfileInt("Guard2", "CustomGuard2GlovesLevel", 0, "Common\\NPCItems.ini");
	info.CustomGuard2BootsLevel = GetPrivateProfileInt("Guard2", "CustomGuard2BootsLevel", 0, "Common\\NPCItems.ini");
	info.CustomGuard2WeaponFirstLevel = GetPrivateProfileInt("Guard2", "CustomGuard2WeaponFirstLevel", 0, "Common\\NPCItems.ini");
	info.CustomGuard2WeaponSecondLevel = GetPrivateProfileInt("Guard2", "CustomGuard2WeaponSecondLevel", 0, "Common\\NPCItems.ini");
	info.CustomGuard2HelmExcellent = GetPrivateProfileInt("Guard2", "CustomGuard2HelmExcellent", 0, "Common\\NPCItems.ini");
	info.CustomGuard2ArmorExcellent = GetPrivateProfileInt("Guard2", "CustomGuard2ArmorExcellent", 0, "Common\\NPCItems.ini");
	info.CustomGuard2PantsExcellent = GetPrivateProfileInt("Guard2", "CustomGuard2PantsExcellent", 0, "Common\\NPCItems.ini");
	info.CustomGuard2GlovesExcellent = GetPrivateProfileInt("Guard2", "CustomGuard2GlovesExcellent", 0, "Common\\NPCItems.ini");
	info.CustomGuard2BootsExcellent = GetPrivateProfileInt("Guard2", "CustomGuard2BootsExcellent", 0, "Common\\NPCItems.ini");
	info.CustomGuard2WeaponFirstExcellent = GetPrivateProfileInt("Guard2", "CustomGuard2WeaponFirstExcellent", 0, "Common\\NPCItems.ini");
	info.CustomGuard2WeaponSecondExcellent = GetPrivateProfileInt("Guard2", "CustomGuard2WeaponSecondExcellent", 0, "Common\\NPCItems.ini");
	//---CursedWizard
	info.CustomCursedWizard = GetPrivateProfileInt("CursedWizard", "CustomCursedWizard", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardWings = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardWings", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardHelm = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardHelm", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardArmor = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardArmor", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardPants = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardPants", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardGloves = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardGloves", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardBoots = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardBoots", 0, "Common\\NPCItems.ini");
	info.CustomTypeCursedWizardWeapon1 = GetPrivateProfileInt("CursedWizard", "CustomType1", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardWeapon1 = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardWeapon1", 0, "Common\\NPCItems.ini");
	info.CustomTypeCursedWizardWeapon2 = GetPrivateProfileInt("CursedWizard", "CustomType2", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardWeapon2 = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardWeapon2", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardHelmLevel = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardHelmLevel", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardArmorLevel = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardArmorLevel", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardPantsLevel = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardPantsLevel", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardGlovesLevel = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardGlovesLevel", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardBootsLevel = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardBootsLevel", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardWeaponFirstLevel = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardWeaponFirstLevel", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardWeaponSecondLevel = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardWeaponSecondLevel", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardHelmExcellent = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardHelmExcellent", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardArmorExcellent = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardArmorExcellent", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardPantsExcellent = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardPantsExcellent", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardGlovesExcellent = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardGlovesExcellent", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardBootsExcellent = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardBootsExcellent", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardWeaponFirstExcellent = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardWeaponFirstExcellent", 0, "Common\\NPCItems.ini");
	info.CustomCursedWizardWeaponSecondExcellent = GetPrivateProfileInt("CursedWizard", "CustomCursedWizardWeaponSecondExcellent", 0, "Common\\NPCItems.ini");
	//--LeoHelper
	info.CustomLeoHelper = GetPrivateProfileInt("LeoHelper", "CustomLeoHelper", 0, "Common\\NPCItems.ini");
	info.CustomLeoHelperWings = GetPrivateProfileInt("LeoHelper", "CustomLeoHelperWings", 0, "Common\\NPCItems.ini");
	info.CustomLeoHelperHelm = GetPrivateProfileInt("LeoHelper", "CustomLeoHelperHelm", 0, "Common\\NPCItems.ini");
	info.CustomLeoHelperArmor = GetPrivateProfileInt("LeoHelper", "CustomLeoHelperArmor", 0, "Common\\NPCItems.ini");
	info.CustomLeoHelperPants = GetPrivateProfileInt("LeoHelper", "CustomLeoHelperPants", 0, "Common\\NPCItems.ini");
	info.CustomLeoHelperGloves = GetPrivateProfileInt("LeoHelper", "CustomLeoHelperGloves", 0, "Common\\NPCItems.ini");
	info.CustomLeoHelperBoots = GetPrivateProfileInt("LeoHelper", "CustomLeoHelperBoots", 0, "Common\\NPCItems.ini");
	info.CustomLeoHelperHelmLevel = GetPrivateProfileInt("LeoHelper", "CustomLeoHelperHelmLevel", 0, "Common\\NPCItems.ini");
	info.CustomLeoHelperArmorLevel = GetPrivateProfileInt("LeoHelper", "CustomLeoHelperArmorLevel", 0, "Common\\NPCItems.ini");
	info.CustomLeoHelperPantsLevel = GetPrivateProfileInt("LeoHelper", "CustomLeoHelperPantsLevel", 0, "Common\\NPCItems.ini");
	info.CustomLeoHelperGlovesLevel = GetPrivateProfileInt("LeoHelper", "CustomLeoHelperGlovesLevel", 0, "Common\\NPCItems.ini");
	info.CustomLeoHelperBootsLevel = GetPrivateProfileInt("LeoHelper", "CustomLeoHelperBootsLevel", 0, "Common\\NPCItems.ini");
	info.CustomLeoHelperHelmExcellent = GetPrivateProfileInt("LeoHelper", "CustomLeoHelperHelmExcellent", 0, "Common\\NPCItems.ini");
	info.CustomLeoHelperArmorExcellent = GetPrivateProfileInt("LeoHelper", "CustomLeoHelperArmorExcellent", 0, "Common\\NPCItems.ini");
	info.CustomLeoHelperPantsExcellent = GetPrivateProfileInt("LeoHelper", "CustomLeoHelperPantsExcellent", 0, "Common\\NPCItems.ini");
	info.CustomLeoHelperGlovesExcellent = GetPrivateProfileInt("LeoHelper", "CustomLeoHelperGlovesExcellent", 0, "Common\\NPCItems.ini");
	info.CustomLeoHelperBootsExcellent = GetPrivateProfileInt("LeoHelper", "CustomLeoHelperBootsExcellent", 0, "Common\\NPCItems.ini");




	gCustomMessage.Load("Common\\CustomMessage.txt");

	gCustomJewel.Load("CustomItem\\CustomJewel.txt");

	gCustomWing.Load("CustomItem\\CustomWing.txt");

	gCustomItem.Load("CustomItem\\CustomItem.txt");

	gCustomBuyVip.Load("Common\\CustomBuyVip.txt");

	gCustomCommandInfo.Load("Common\\CustomCommandInfo.txt");

	gCustomEventTimeText.Load("Common\\CustomEventTimeText.txt");

	gSmokeEffect.Load("CustomItem\\CustomSmokeEffect.txt");

	gFog.Load("Common\\CustomFog.txt");

	gMonsters.Load("CustomMonster\\CustomMonster.txt");

	gNPCName.Load("CustomMonster\\CustomNPCName.txt");
	//--
	gCustomGloves.Load("CustomItem\\CustomGloves.txt");

	gCustomCrossBow.Load("CustomItem\\CustomCrossbow.txt");

	gCustomPet2.Load("CustomPet\\CustomPet.txt");

	gCloak.Load("CustomItem\\CustomCloak.txt");

	gCustomPosition.Load("CustomItem\\CustomItemPosition.txt");

	gCustomRemake.Load("CustomItem\\CustomEffectRemake.txt");

	gItemManager.Load("CustomItem\\Item.txt");

	gCustomModelEffect.Load("CustomItem\\ModelEffect.txt");

#if(CUSTOM_EVENTBOSS_BB)
	gCustomEventBoss.Load("Common\\CustomEventBoss.xml");

	memcpy(info.m_BEventData, gCustomEventBoss.m_EventData, sizeof(info.m_BEventData));
	memcpy(info.m_BInfoTextData, gCustomEventBoss.m_InfoTextData, sizeof(info.m_BInfoTextData));
	memcpy(info.m_BInfoRewardData, gCustomEventBoss.m_InfoRewardData, sizeof(info.m_BInfoRewardData));
#endif

	memcpy(info.EngCustomMessageInfo,gCustomMessage.m_EngCustomMessageInfo,sizeof(info.EngCustomMessageInfo));

	memcpy(info.PorCustomMessageInfo,gCustomMessage.m_PorCustomMessageInfo,sizeof(info.PorCustomMessageInfo));

	memcpy(info.SpnCustomMessageInfo,gCustomMessage.m_SpnCustomMessageInfo,sizeof(info.SpnCustomMessageInfo));

	memcpy(info.CustomJewelInfo,gCustomJewel.m_CustomJewelInfo,sizeof(info.CustomJewelInfo));

	memcpy(info.CustomWingInfo,gCustomWing.m_CustomWingInfo,sizeof(info.CustomWingInfo));

	memcpy(info.CustomItemInfo,gCustomItem.m_CustomItemInfo,sizeof(info.CustomItemInfo));

	memcpy(info.CustomBuyVipInfo,gCustomBuyVip.m_CustomBuyVipInfo,sizeof(info.CustomBuyVipInfo));

	memcpy(info.CustomCommandInfo,gCustomCommandInfo.m_CustomCommandInfo,sizeof(info.CustomCommandInfo));

	memcpy(info.CustomEventInfo,gCustomEventTimeText.m_CustomEventInfo,sizeof(info.CustomEventInfo));

	memcpy(info.CustomSmokeEffect, gSmokeEffect.m_CustomSmokeEffect, sizeof(info.CustomSmokeEffect));

	memcpy(info.CustomFog, gFog.m_CustomFog, sizeof(info.CustomFog));

	memcpy(info.CustomMonsters, gMonsters.m_Monsters, sizeof(info.CustomMonsters));

	memcpy(info.CustomBossClass, gMonsters.m_BossClass, sizeof(info.CustomBossClass)); //Custom Boss Class


	memcpy(info.CustomNPCName, gNPCName.m_CustomNpcName, sizeof(info.CustomNPCName));
//-----
	memcpy(info.CustomGloves, gCustomGloves.m_CustomGlovesInfo, sizeof(info.CustomGloves));

	memcpy(info.CustomBowInfo, gCustomCrossBow.m_CustomBowInfo, sizeof(info.CustomBowInfo));

	memcpy(info.CustomPetInfo, gCustomPet2.m_CustomPetInfo, sizeof(info.CustomPetInfo));

	memcpy(info.m_CustomCloak, gCloak.m_Cloak, sizeof(info.m_CustomCloak));

	memcpy(info.CustomPosition, gCustomPosition.m_CustomPositionInfo, sizeof(info.CustomPosition));

	memcpy(info.CustomRemake, gCustomRemake.m_CustomRemake, sizeof(info.CustomRemake));

	memcpy(info.m_ItemInfoEx, gItemManager.m_ItemInfo, sizeof(info.m_ItemInfoEx));

	memcpy(info.m_CustomModelInfo, gCustomModelEffect.m_CustomModelEffectInfo, sizeof(info.m_CustomModelInfo));


	CCRC32 CRC32;

	if(CRC32.FileCRC(info.ClientName,&info.ClientCRC32,1024) == 0)
	{
		info.ClientCRC32 = 0;
	}

	if(CRC32.FileCRC(info.HackName,&info.HackCRC32,1024) == 0)
	{
		info.HackCRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName1,&info.Plugin1CRC32,1024) == 0)
	{
		info.Plugin1CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName2,&info.Plugin2CRC32,1024) == 0)
	{
		info.Plugin2CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName3,&info.Plugin3CRC32,1024) == 0)
	{
		info.Plugin3CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName4,&info.Plugin4CRC32,1024) == 0)
	{
		info.Plugin4CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName5,&info.Plugin5CRC32,1024) == 0)
	{
		info.Plugin5CRC32 = 0;
	}

	if(CRC32.FileCRC(info.CameraName,&info.CameraCRC32,1024) == 0)
	{
		info.CameraCRC32 = 0;
	}

	DWORD MainDLLCRC32;
	DWORD VerifyCRC32;

	if (CRC32.FileCRC("Main.dll", &MainDLLCRC32, 1024) == 0)
	{
		MainDLLCRC32 = 0;
	}

	if (CRC32.FileCRC("Verify.dll", &VerifyCRC32, 1024) == 0)
	{
		MainDLLCRC32 = 0;
	}
	std::ofstream fout(".\\CRCInfo.txt", std::ios_base::out | std::ios_base::trunc); //открываем файл для записи, предварительно очищая его

	fout << "GameGuardCRC = 0x" << std::hex << (DWORD)info.HackCRC32 << std::endl;
	fout << "VerifyCRC = 0x" << std::hex << (DWORD)VerifyCRC32 << std::endl;
	fout << "MainDLLCRC = 0x" << std::hex << (DWORD)MainDLLCRC32 << std::endl;
	fout << "MainEXECRC = 0x" << std::hex << (DWORD)info.ClientCRC32 << std::endl;

	fout.close(); //закрываем файл

	for(int n=0;n < sizeof(MAIN_FILE_INFO);n++)
	{
		((BYTE*)&info)[n] ^= (BYTE)(0xDA^LOBYTE(n));
		((BYTE*)&info)[n] -= (BYTE)(0x95^HIBYTE(n));
	}

#if(PREMIUN==1)
	HANDLE file = CreateFile("Premium/wzClient.dll",GENERIC_WRITE,FILE_SHARE_READ,0,CREATE_ALWAYS,FILE_ATTRIBUTE_ARCHIVE,0);
#else
	HANDLE file = CreateFile("Free/Licencia",GENERIC_WRITE,FILE_SHARE_READ,0,CREATE_ALWAYS,FILE_ATTRIBUTE_ARCHIVE,0);
#endif

	if(file == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	DWORD OutSize = 0;

	if(WriteFile(file,&info,sizeof(MAIN_FILE_INFO),&OutSize,0) == 0)
	{
		CloseHandle(file);
		return 0;
	}

	CloseHandle(file);
	
	//system("pause");

	ENCODE_END

	CLEAR_END

	return 0;
}
