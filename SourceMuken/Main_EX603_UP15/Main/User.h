#pragma once
#include "Object.h"
#include "Protocol.h"


#define CSParts2D				((float *(__thiscall*)(float * thisa, int a4, int a5, char a6, float a7, float a8, float a9, float a10, float a11, float a12)) 0x004EFFF0)
#define Operator_new			((float *(__cdecl*)(unsigned int a4)) 0x009D00C5)


#pragma pack(push, 1)
struct PMSG_TARGETDATA_REQ
{
	PSWMSG_HEAD header;
	int			aIndex;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_TARGETDATA_ANS
{
	PSWMSG_HEAD header;
	int aIndex;
    bool isMonster;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_TARGET_MONSTER_DATA : PMSG_TARGETDATA_ANS
{
    int Life;
    int MaxLife;
    short Level;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_TARGET_PLAYER_DATA : PMSG_TARGET_MONSTER_DATA
{
    int SD;
    int MaxSD;
    short Reset;
	short RankTitle;
	short Long;
};
#pragma pack(pop)

struct CUSTOM_LOGO
{
	int Active;
	int	X;
	int	Y;
};
struct TINH_NANG_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
class User
{
public:
	int CoordenadaX;
	int CoordenadaY;
	int getLevel;
	int getReset;
	char getName[11];
	//-- post item
	int				PostItemID;
	int				PostItemLV;
	int				PostItemExc;
	int				PostItemAcc;
	int				PostItemHarmony;
	int				PostItem380;
	char*			PostItemSocket;
	int				PostItemX;
	int				PostItemY;
	int				GetPet;
	//--
	void			Load();
	static void ChangeCharInfo(LPVOID This);
	void			Refresh();	
	bool			GetTarget();
	void			ToggleAuto();
	void			ToggleAutoTron();
	lpCharObj		lpPlayer;
	lpViewObj		lpViewPlayer;
	lpViewObj		lpViewTarget;
	BYTE			m_TargetType;	//1 - npc, 2 - attack
	int				m_MapNumber;
	int				m_CursorX;
	int				MagickAttack;
	int				m_CursorY;
	DWORD			m_TargetUpdateTick;
	int DanhHieu;
	int SurvivorKill;
	int SurvivorDie;
	int SurvivorTotal;

#if(MOCNAP == 1)
	int MocNapCheck1;
	int MocNapCheck2;
	int MocNapCheck3;
	int MocNapCheck4;
	int MocNapCheck5;
	int MocNapCheck6;
	int MocNapCheck7;
	int MocNapCheck8;
	int MocNapCheck9;
	int MocNapCheck10;
	int MocNapCheck11;
	int MocNapCheck12;
	int MocNapCheck13;
	int	MOCNAPCOIN;
	int	MOCNAP1;
	int	MOCNAP2;
	int	MOCNAP3;
	int	MOCNAP4;
	int	MOCNAP5;
	int	MOCNAP6;
	int	MOCNAP7;
	int	MOCNAP8;
	int	MOCNAP9;
	int	MOCNAP10;
	int	MOCNAP11;
	int	MOCNAP12;
	int	MOCNAP13;
#endif

#if(BOSS_GUILD == 1)
	int CheDo1;
	int CheDo2;
	int KillBoss;
	int Score;
	int WCoinC;
	int PhuThuyWCoinC;
	int ChienBinhWCoinC;
	int TienNuWCoinC;
	int ThuatSiWCoinC;
	int ThietBinhWCoinC;
	int DauSiWCoinC;
	int ChuaTeWCoinC;
#endif

#if(DANH_HIEU_NEW == 1)
	int rCoint;
	int rCount;
	int rType;
	int rIndex;
	int SatThuong;
	int SatThuongX2;
	int PhongThu;
	int HP;
	int SD;
	int GST;
	int DANH_HIEU;

#endif
#if(TU_LUYEN_NEW == 1)
	int TU_LUYEN_WCOINC_01;
	int TU_LUYEN_WCOINC_02;
	int TU_LUYEN_WCOINC_03;
	int TU_LUYEN_WCOINC_04;
	int TU_LUYEN_WCOINC_05;
	int TU_LUYEN_WCOINC_06;
	int TU_LUYEN_WCOINC_07;
	int TU_LUYEN_WCOINC_08;
	int TU_LUYEN_WCOINC_09;
	int TU_LUYEN_WCOINC_10;
	int TU_LUYEN_WCOINC_11;
	int TU_LUYEN_WCOINC_12;
	int TU_LUYEN_WCOINC_13;
	int TU_LUYEN_WCOINC_14;
	int TU_LUYEN_WCOINC_15;
	int TU_LUYEN_WCOINC_16;
	int TU_LUYEN_WCOINC_17;
	int TU_LUYEN_WCOINC_18;
	int TU_LUYEN_WCOINC_19;
	int TU_LUYEN_WCOINC_20;
	int TU_LUYEN_WCOINC_21;
	int TU_LUYEN_WCOINC_22;
	int TU_LUYEN_WCOINC_23;
	int TU_LUYEN_WCOINC_24;
	int TU_LUYEN_WCOINC_25;
	int TU_LUYEN_WCOINC_26;
	int TU_LUYEN_WCOINC_27;
	int TU_LUYEN_WCOINC_28;
	int TU_LUYEN_WCOINC_29;
	int TU_LUYEN_WCOINC_30;
	int TU_LUYEN_WCOINC_31;
	int TU_LUYEN_WCOINC_32;
	int TU_LUYEN_WCOINC_33;
	int TU_LUYEN_WCOINC_34;
	int TU_LUYEN_WCOINC_35;
	int TU_LUYEN_WCOINC_36;
	int TU_LUYEN_WCOINC_37;
	int TU_LUYEN_WCOINC_38;
	int TU_LUYEN_WCOINC_39;
	int TU_LUYEN_WCOINC_40;
#endif

	bool InSafeZone;
	static void	AllInOne();
	//--

	void DrawHP();
	void DrawRank();
	void SetTargetData(PMSG_TARGETDATA_ANS * lpMsg);
	int GetActiveSkill();
	static void	SetEventEffect(int PreviewStruct);
	BOOL        is_auto;
	BOOL        is_autotron;
	CUSTOM_LOGO m_Logo[400];

	void RenderRuneEffect(DWORD ObjectModel, int ID, int Type, float Z, float Size);
	static bool	ShowModelBMD(int a1, int a2, int a3);

	//Auto Sendmove
	DWORD		IsSendMove;
	DWORD			MoveToX;
	DWORD			MoveToY;
	BYTE		KhongDiDuoc;
//#if(VANTHANH_FLAG == 1)
//	static bool UseHasMagicRing();
//	static bool CreateManyFlag(ObjectPreview * pChar);
//	static void __cdecl HoolCreateManyFlay(ObjectPreview * pChar);
//#endif

#if(FLAG_SKIN)
	static bool TestFlag(ObjectPreview* pChar);
	static bool CreateManyFlag(ObjectPreview* pChar);
	static void __cdecl HoolCreateManyFlay(ObjectPreview* pChar);
#endif

#if(CHONPHEDOILAP)
	bool PkModePhe;
#endif

	void      CBRenderCharacter(DWORD ObjectPointer, int Effect, float SizeX, float SizeY, vec3_t Color, int Type = 0);
};
extern User gObjUser;