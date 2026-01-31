#include "stdafx.h"
#include "Protocol.h"
#include "Common.h"
#include "CustomEventTime.h"
#include "CustomRankUser.h"
#include "CustomRanking.h"
#include "HealthBar.h"
#include "Interface.h"
#include "ItemShopValue.h"
#include "Offset.h"
#include "OffTrade.h"
#include "PacketManager.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "Reconnect.h"
#include "Util.h"
#include "post_item.h"
#include "postInterface.h"
#include "PetProtocol.h"
#include "StatsAdvance.h"
#include "User.h"
#include "PartyBuffs.h"
#include "BuffIcon.h"
#include "Ruud.h"
#include "MiniMapInfo.h"
#include "Central.h"
#include "InterEx.h"
#include "NPCRuud.h"
#include "PartyBar.h"
#include "DanhHieu.h"
#include "TuLuyen.h"
#include "PartySearchSettings.h"
#include "PartySearch.h"
#include "HWID.h"
#include "CustomLuckySpin.h"
#include "ChangeClass.h"
#include "CustomJewelBank.h"
#include "QuickCommandWindow.h"
#include "HuyHieuCuongHoa.h"
#include "CustomCuongHoaWing.h"
#include "Ranking.h"
#include "LoginMainWin.h"
#include "MSGCommon.h"
#include "CustomOfflineMode.h"
#include "CustomVKR.h"
#include "Character.h"
#include "ThueFlag.h"

int  mDT_CapDo = 0;
int  mDT_TongPoint = 0;
int  mDT_PointNext = 0;
char mDT_Top1Name[11] = { 0 };
int  mDT_Top1Point = 0;
//==
int  mBT_CapDo = 0;
int  mBT_TongPoint = 0;
int  mBT_PointNext = 0;
char mBT_Top1Name[11] = { 0 };
int  mBT_Top1Point = 0;
int mLvCuongHoaHienTai = 0;
int mPointUsePhe = 0;

std::map<int, CONFIDATA_CUONGHOA> mDataConfigCuongHoa;

#if(MOCNAP == 1)
struct MOCNAP_UPDATE  // ok
{
	PBMSG_HEAD2 h;
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
	//--
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
};
void MocNapRecv(MOCNAP_UPDATE * aRecv)
{
	gObjUser.MocNapCheck1 = aRecv->MocNapCheck1;
	gObjUser.MocNapCheck2 = aRecv->MocNapCheck2;
	gObjUser.MocNapCheck3 = aRecv->MocNapCheck3;
	gObjUser.MocNapCheck4 = aRecv->MocNapCheck4;
	gObjUser.MocNapCheck5 = aRecv->MocNapCheck5;
	gObjUser.MocNapCheck6 = aRecv->MocNapCheck6;
	gObjUser.MocNapCheck7 = aRecv->MocNapCheck7;
	gObjUser.MocNapCheck8 = aRecv->MocNapCheck8;
	gObjUser.MocNapCheck9 = aRecv->MocNapCheck9;
	gObjUser.MocNapCheck10 = aRecv->MocNapCheck10;
	gObjUser.MocNapCheck11 = aRecv->MocNapCheck11;
	gObjUser.MocNapCheck12 = aRecv->MocNapCheck12;
	gObjUser.MocNapCheck13 = aRecv->MocNapCheck13;
	//--
	gObjUser.MOCNAPCOIN = aRecv->MOCNAPCOIN;
	gObjUser.MOCNAP1 = aRecv->MOCNAP1;
	gObjUser.MOCNAP2 = aRecv->MOCNAP2;
	gObjUser.MOCNAP3 = aRecv->MOCNAP3;
	gObjUser.MOCNAP4 = aRecv->MOCNAP4;
	gObjUser.MOCNAP5 = aRecv->MOCNAP5;
	gObjUser.MOCNAP6 = aRecv->MOCNAP6;
	gObjUser.MOCNAP7 = aRecv->MOCNAP7;
	gObjUser.MOCNAP8 = aRecv->MOCNAP8;
	gObjUser.MOCNAP9 = aRecv->MOCNAP9;
	gObjUser.MOCNAP10 = aRecv->MOCNAP10;
	gObjUser.MOCNAP11 = aRecv->MOCNAP11;
	gObjUser.MOCNAP12 = aRecv->MOCNAP12;
	gObjUser.MOCNAP13 = aRecv->MOCNAP13;
}
#endif

#if(BOSS_GUILD == 1)
struct BOSSGUILD_UPDATE
{
	PBMSG_HEAD2 h;
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
};

void BossGuildRecv(BOSSGUILD_UPDATE * aRecv)
{
	gObjUser.CheDo1 = aRecv->CheDo1;
	gObjUser.CheDo2 = aRecv->CheDo2;
	gObjUser.KillBoss = aRecv->KillBoss;
	gObjUser.Score = aRecv->Score;
	gObjUser.WCoinC = aRecv->WCoinC;
	gObjUser.PhuThuyWCoinC = aRecv->PhuThuyWCoinC;
	gObjUser.ChienBinhWCoinC = aRecv->ChienBinhWCoinC;
	gObjUser.TienNuWCoinC = aRecv->TienNuWCoinC;
	gObjUser.ThuatSiWCoinC = aRecv->ThuatSiWCoinC;
	gObjUser.ThietBinhWCoinC = aRecv->ThietBinhWCoinC;
	gObjUser.DauSiWCoinC = aRecv->DauSiWCoinC;
	gObjUser.ChuaTeWCoinC = aRecv->ChuaTeWCoinC;
}
#endif

#if(DANH_HIEU_NEW == 1)
struct DANHHIEU_UPDATE
{
	PBMSG_HEAD2 h;
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

};

void DanhHieuRecv(DANHHIEU_UPDATE* aRecv)
{
	gObjUser.rCoint = aRecv->rCoint;

	gObjUser.rCount = aRecv->rCount;
	gObjUser.rType = aRecv->rType;
	gObjUser.rIndex = aRecv->rIndex;

	gObjUser.SatThuong = aRecv->SatThuong;
	gObjUser.SatThuongX2 = aRecv->SatThuongX2;
	gObjUser.PhongThu = aRecv->PhongThu;
	gObjUser.HP = aRecv->HP;
	gObjUser.SD = aRecv->SD;
	gObjUser.GST = aRecv->GST;

	gObjUser.DANH_HIEU = aRecv->DANH_HIEU;
}
#endif

#if(TU_LUYEN_NEW == 1)
struct TULUYEN_UPDATE
{
	PBMSG_HEAD2 h;
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
};

void TuLuyenRecv(TULUYEN_UPDATE * aRecv)
{
	gObjUser.TU_LUYEN_WCOINC_01 = aRecv->TU_LUYEN_WCOINC_01;
	gObjUser.TU_LUYEN_WCOINC_02 = aRecv->TU_LUYEN_WCOINC_02;
	gObjUser.TU_LUYEN_WCOINC_03 = aRecv->TU_LUYEN_WCOINC_03;
	gObjUser.TU_LUYEN_WCOINC_04 = aRecv->TU_LUYEN_WCOINC_04;
	gObjUser.TU_LUYEN_WCOINC_05 = aRecv->TU_LUYEN_WCOINC_05;
	gObjUser.TU_LUYEN_WCOINC_06 = aRecv->TU_LUYEN_WCOINC_06;
	gObjUser.TU_LUYEN_WCOINC_07 = aRecv->TU_LUYEN_WCOINC_07;
	gObjUser.TU_LUYEN_WCOINC_08 = aRecv->TU_LUYEN_WCOINC_08;
	gObjUser.TU_LUYEN_WCOINC_09 = aRecv->TU_LUYEN_WCOINC_09;
	gObjUser.TU_LUYEN_WCOINC_10 = aRecv->TU_LUYEN_WCOINC_10;
	gObjUser.TU_LUYEN_WCOINC_11 = aRecv->TU_LUYEN_WCOINC_11;
	gObjUser.TU_LUYEN_WCOINC_12 = aRecv->TU_LUYEN_WCOINC_12;
	gObjUser.TU_LUYEN_WCOINC_13 = aRecv->TU_LUYEN_WCOINC_13;
	gObjUser.TU_LUYEN_WCOINC_14 = aRecv->TU_LUYEN_WCOINC_14;
	gObjUser.TU_LUYEN_WCOINC_15 = aRecv->TU_LUYEN_WCOINC_15;
	gObjUser.TU_LUYEN_WCOINC_16 = aRecv->TU_LUYEN_WCOINC_16;
	gObjUser.TU_LUYEN_WCOINC_17 = aRecv->TU_LUYEN_WCOINC_17;
	gObjUser.TU_LUYEN_WCOINC_18 = aRecv->TU_LUYEN_WCOINC_18;
	gObjUser.TU_LUYEN_WCOINC_19 = aRecv->TU_LUYEN_WCOINC_19;
	gObjUser.TU_LUYEN_WCOINC_20 = aRecv->TU_LUYEN_WCOINC_20;
	gObjUser.TU_LUYEN_WCOINC_21 = aRecv->TU_LUYEN_WCOINC_21;
	gObjUser.TU_LUYEN_WCOINC_22 = aRecv->TU_LUYEN_WCOINC_22;
	gObjUser.TU_LUYEN_WCOINC_23 = aRecv->TU_LUYEN_WCOINC_23;
	gObjUser.TU_LUYEN_WCOINC_24 = aRecv->TU_LUYEN_WCOINC_24;
	gObjUser.TU_LUYEN_WCOINC_25 = aRecv->TU_LUYEN_WCOINC_25;
	gObjUser.TU_LUYEN_WCOINC_26 = aRecv->TU_LUYEN_WCOINC_26;
	gObjUser.TU_LUYEN_WCOINC_27 = aRecv->TU_LUYEN_WCOINC_27;
	gObjUser.TU_LUYEN_WCOINC_28 = aRecv->TU_LUYEN_WCOINC_28;
	gObjUser.TU_LUYEN_WCOINC_29 = aRecv->TU_LUYEN_WCOINC_29;
	gObjUser.TU_LUYEN_WCOINC_30 = aRecv->TU_LUYEN_WCOINC_30;
	gObjUser.TU_LUYEN_WCOINC_31 = aRecv->TU_LUYEN_WCOINC_31;
	gObjUser.TU_LUYEN_WCOINC_32 = aRecv->TU_LUYEN_WCOINC_32;
	gObjUser.TU_LUYEN_WCOINC_33 = aRecv->TU_LUYEN_WCOINC_33;
	gObjUser.TU_LUYEN_WCOINC_34 = aRecv->TU_LUYEN_WCOINC_34;
	gObjUser.TU_LUYEN_WCOINC_35 = aRecv->TU_LUYEN_WCOINC_35;
	gObjUser.TU_LUYEN_WCOINC_36 = aRecv->TU_LUYEN_WCOINC_36;
	gObjUser.TU_LUYEN_WCOINC_37 = aRecv->TU_LUYEN_WCOINC_37;
	gObjUser.TU_LUYEN_WCOINC_38 = aRecv->TU_LUYEN_WCOINC_38;
	gObjUser.TU_LUYEN_WCOINC_39 = aRecv->TU_LUYEN_WCOINC_39;
	gObjUser.TU_LUYEN_WCOINC_40 = aRecv->TU_LUYEN_WCOINC_40;
}
#endif

#if(PKEVENT == 1) // OK
struct PKEVENT_UPDATE
{
	PBMSG_HEAD2 h;
	int SurvivorKill;
	int SurvivorDie;
	int SurvivorTotal;
};

void PKEventRecv(PKEVENT_UPDATE * aRecv)
{
	gObjUser.SurvivorKill = aRecv->SurvivorKill;
	gObjUser.SurvivorDie = aRecv->SurvivorDie;
	gObjUser.SurvivorTotal = aRecv->SurvivorTotal;
}
#endif





BOOL ProtocolCoreEx(BYTE head,BYTE* lpMsg,int size,int key) // OK
{
	//#if(ANTIHACK)	//Anti Solid
	//	BYTE ProtocolType = lpMsg[0];
	//	BYTE error = 0;
	//	if (ProtocolType == 0xC1)
	//	{
	//
	//		if (size == 74)					   //solid proxy mess
	//		{
	//			if (head == 0xD &&
	//				lpMsg[3] == 0x1 &&
	//				lpMsg[4] == 0x30 &&
	//				lpMsg[12] == 0x30 &&
	//				lpMsg[13] == 0x54 &&
	//				lpMsg[14] == 0x68 &&
	//				lpMsg[15] == 0x69 &&
	//				lpMsg[16] == 0x73)
	//				error++;
	//		}
	//		else if (size == 53)				  //solid proxy	mess
	//		{
	//			if (head == 0xD &&
	//				lpMsg[3] == 0x1 &&
	//				lpMsg[4] == 0x30 &&
	//				lpMsg[12] == 0x30 &&
	//				lpMsg[13] == 0x4F &&
	//				lpMsg[14] == 0x72 &&
	//				lpMsg[15] == 0x69 &&
	//				lpMsg[16] == 0x67)
	//				error++;
	//		}
	//		if (error)
	//		{
	//			//gCheatGuard.Report(error);
	//			//MessageBoxA(NULL, " Ban khong nen gian lan khi choi game! 100", "[HieuDaiCa]", ERROR);
	//			ExitProcess(0);
	//		}
	//	}
	//#endif
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

	switch(head)
	{
		case 0x11:
			GCDamageRecv((PMSG_DAMAGE_RECV*)lpMsg);
			break;
			//bug no bug
		//case 0x16:
			//GCMonsterDieRecv((PMSG_MONSTER_DIE_RECV*)lpMsg);
			//break;
		case 0x17:
			GCUserDieRecv((PMSG_USER_DIE_RECV*)lpMsg);
			break;
		case 0x26:
			GCLifeRecv((PMSG_LIFE_RECV*)lpMsg);
			break;
		case 0x27:
			GCManaRecv((PMSG_MANA_RECV*)lpMsg);
			break;
		case 0x2C:
			GCFruitResultRecv((PMSG_FRUIT_RESULT_RECV*)lpMsg);
			break;
			//no bug
		case 0x9C:
			GCRewardExperienceRecv((PMSG_REWARD_EXPERIENCE_RECV*)lpMsg);
			break;
		case 0xA3:
			GCQuestRewardRecv((PMSG_QUEST_REWARD_RECV*)lpMsg);
			break;
		case 0xB1:
			switch(((lpMsg[0]==0xC1)?lpMsg[3]:lpMsg[4]))
			{
				case 0x00:
					gIconBuff.DeleteAllBuff();
					jCRenderRuud.ClearRuudInfo();
					GCMapServerMoveRecv((PMSG_MAP_SERVER_MOVE_RECV*)lpMsg);
#if(FLAG_SKIN)
					ThueFlag.Clear();
#endif
					break;
				case 0x01:
					gIconBuff.DeleteAllBuff();
					jCRenderRuud.ClearRuudInfo();
					GCMapServerMoveAuthRecv((PMSG_MAP_SERVER_MOVE_AUTH_RECV*)lpMsg);
					break;

			}
			break;
		case 0xF1:
			switch(((lpMsg[0]==0xC1)?lpMsg[3]:lpMsg[4]))
			{
				case 0x00:
					GCConnectClientRecv((PMSG_CONNECT_CLIENT_RECV*)lpMsg);
					break;
				case 0x01:
					GCConnectAccountRecv((PMSG_CONNECT_ACCOUNT_RECV*)lpMsg);
					break;
				case 0x02:
					GCCloseClientRecv((PMSG_CLOSE_CLIENT_RECV*)lpMsg);
					break;

				case 0x12:
					g_pLoginMainWin.ReciveCreateAccount(((lpMsg[0] == 0xC1) ? lpMsg[4] : lpMsg[5]));
					break;

			}
			break;
		case 0xF3:
			switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
			{
			case 0xF5:
				gCustomJewelBank.GCCustomJewelBankInfoRecv((PSBMSG_JEWELBANK_RECV*)lpMsg);
				break;

				case 0x00:
					gIconBuff.DeleteAllBuff();
					jCRenderRuud.ClearRuudInfo();
					GCCharacterListRecv((PMSG_CHARACTER_LIST_RECV*)lpMsg);
					break;
				case 0x03:
					GCCharacterInfoRecv((PMSG_CHARACTER_INFO_RECV*)lpMsg);
					break;
				case 0x04:
					GCCharacterRegenRecv((PMSG_CHARACTER_REGEN_RECV*)lpMsg);
					break;
				case 0x05:
					GCLevelUpRecv((PMSG_LEVEL_UP_RECV*)lpMsg);
					break;
				case 0x06:
					GCLevelUpPointRecv((PMSG_LEVEL_UP_POINT_RECV*)lpMsg);
					break;
				case 0x07:
					GCMonsterDamageRecv((PMSG_MONSTER_DAMAGE_RECV*)lpMsg);
					break;

				case 0x32: //Show Window CTC Mini
					GCCTCMiniShowWindow((INFOCTCMINI_SENDCLIENT *)lpMsg);
					break;

				case 0x33: //Show Kill CTC Mini
					GCCTCMiniKill((CTCMINIKILL_SENDCLIENT *)lpMsg);
					break;

#if(BOSS_GUILD == 1)
				case 0x35: //Show Window Boss Guild
					GCBossGuildShowWindow((INFOBOSSGUILD_SENDCLIENT *)lpMsg); // ok
					break;
				case 0x36: //Show Window Boss Guild
					GCBossGuildTime((BOSSGUILDTIME_SENDCLIENT *)lpMsg); // ok
					break;
#endif



				case 0x38: //Info CTC
					GCInfoCTC((INFOCTC_SENDCLIENT *)lpMsg);
					break;

				case 0x39: //Show Kill Monter
					GCCTCKillMonter((CTCKILL_SENDCLIENT *)lpMsg);
					break;

				case 0x50:
					GCMasterInfoRecv((PMSG_MASTER_INFO_RECV*)lpMsg);
					break;
				case 0x51:
					GCMasterLevelUpRecv((PMSG_MASTER_LEVEL_UP_RECV*)lpMsg);
					break;
				case 0xE0:
					GCNewCharacterInfoRecv((PMSG_NEW_CHARACTER_INFO_RECV*)lpMsg);
					return 1;
				case 0xE1:
					GCNewCharacterCalcRecv((PMSG_NEW_CHARACTER_CALC_RECV*)lpMsg);
					return 1;
				case 0xE2:
					GCNewHealthBarRecv((PMSG_NEW_HEALTH_BAR_RECV*)lpMsg);
					return 1;
				case 0xE3:
					GCNewGensBattleInfoRecv((PMSG_NEW_GENS_BATTLE_INFO_RECV*)lpMsg);
					return 1;
				case 0xE4:
					GCNewMessageRecv((PMSG_NEW_MESSAGE_RECV*)lpMsg);
					return 1;
				case 0xE5:
					gCustomRankUser.GCReqRankLevelUser((PMSG_CUSTOM_RANKUSER*)lpMsg);
					return 1;

#if(RANKINGGOC == 1)
				case 0xE6:
					gCustomRanking.GCReqRanking((PMSG_CUSTOM_RANKING_RECV*)lpMsg);
					return 1;
				case 0xE7:
					gCustomRanking.GCReqRankingCount((PMSG_CUSTOM_RANKING_COUNT_RECV*)lpMsg);
					return 1;
#endif

				case 0xE8:
					gCustomEventTime.GCReqEventTime((PMSG_CUSTOM_EVENTTIME_RECV*)lpMsg);
					return 1;
				case 0xE9:
					gItemPrice.GCItemValueRecv((PMSG_ITEM_VALUE_RECV*)lpMsg);
					return 1;
				case 0xEA:
					GCRecvCoin((PMSG_COIN_RECV*)lpMsg);
					return 1;
				case 0xEB:
					gOffTrade.RecvPShop((PMSG_OFFTRADE_RECV*)lpMsg);
					return 1;
				case 0xEC:
					gOffTrade.PShopActiveRecv((PMSG_SHOPACTIVE_RECV*)lpMsg);
					return 1;
				case 0xED:
					GCBuyConfirmRecv((PMSG_ITEM_BUY_RECV*)lpMsg);
					break;
				case 0xEE:
					SetChaosBoxState((PMSG_SET_CHAOSBOX_STATE*)lpMsg);
				return 1;
				//--------------cosas de pet
				case 0xF1:
					GCPetCharSetRecv((PMSG_NEW_PET_CHARSET_RECV*)lpMsg);
					break;
				case 0xF2:
					GCPetCharSetSelectCharacterRecv((PMSG_NEW_SELECT_CHARACTER_CHARSET_RECV*)lpMsg);
					break;
				#if(PARTYSEARCH==1)
					case 0xF0:
						GCPartyListRecv((PMSG_RECV_PARTYLIST*)lpMsg);
						return 1;
					case 0xF8:
						gPartySearchSettings.GCPartySettingsRecv((PMSG_PARTYSETTINGS_RECV*)lpMsg);
						break;
                #endif
				// ADVANCE STATS
				case 0xF3:
					g_StatsAdvance.Recv((PMSG_STATS_ADVANCE*)lpMsg);
					return 1;
				// MasterSkill
				case 0xF4:
					gCRenderEx700.RecvMasterSkill((PMSG_MASTER_SKILL_LIST_SEND *)lpMsg);
					return 1;

				case 0x13:
					gIconBuff.GC_BuffInfo((PMSG_SEND_BUFF_ICON_EX*)lpMsg);
					break;
					break;
				case 0xF9:
					gMiniMap.RecvPartyInfo((MINIMAP_PARTY_INFO_RECV*)lpMsg);
				break;


#if(DANH_HIEU_NEW == 1)
				case 15:
					DanhHieuRecv((DANHHIEU_UPDATE*)lpMsg);

					break;
#endif

#if(TU_LUYEN_NEW == 1)
				case 100:
					TuLuyenRecv((TULUYEN_UPDATE*)lpMsg);
					break;
#endif


#if(PKEVENT == 1) // OK
				case 101:
					PKEventRecv((PKEVENT_UPDATE*)lpMsg);
					break;
				case 102:
					GCInfoPKEvent((INFOPKEVENT_SENDCLIENT *)lpMsg);
					break;
#endif
#if(TVTEVENT == 1) // OK
				case 103:
					GCInfoTvTEvent((INFOTVTEVENT_SENDCLIENT *)lpMsg);
					break;
#endif

#if(MOCNAP == 1) // OK
				case 104:
					MocNapRecv((MOCNAP_UPDATE*)lpMsg);
					break;
#endif

#if(BOSS_GUILD == 1)
				case 110:
					BossGuildRecv((BOSSGUILD_UPDATE*)lpMsg);
					break;
#endif

			}
			break;



					case 0xF4:
						switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
						{
						#if(CHIEN_TRUONG_CO)
						case 0x8: //Info chiến trường cổ
							GCInfoCTC((INFOCTC_SENDCLIENT *)lpMsg);
							break;
						case 0x9: //Show Kill Monter chiến trường cổ
							GCCTCKillMonter((CTCKILL_SENDCLIENT *)lpMsg);
							break;
						#endif
						}
						break;



					case 0xD3:
						switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
						{
#if(B_HON_HOAN)
						case 0x01:
							{
								gInterface.m_DataConfigHonHoan.clear();
								CSEV_COUNTLIST* mRecv = (CSEV_COUNTLIST*)lpMsg;
								for (int i = 0; i < mRecv->Count; i++)
								{
									CONFIDATA_HONHOAN lpInfo = *(CONFIDATA_HONHOAN*)(((BYTE*)lpMsg) + sizeof(CSEV_COUNTLIST) + (sizeof(CONFIDATA_HONHOAN) * i));

									gInterface.m_DataConfigHonHoan.insert(std::pair<int, CONFIDATA_HONHOAN>(lpInfo.LvHonHoan,lpInfo));
									
									//gInterface.m_DataConfigHonHoan.push_back(*lpInfo);

								}

								if ((GetTickCount() - gInterface.Data[eWindow_NangCapHonHoan].EventTick) > 300)
								{
									gInterface.Data[eWindow_NangCapHonHoan].OnShow ^= 1;
									gInterface.Data[eWindow_NangCapHonHoan].EventTick = GetTickCount();
								}
							}
							break;
#endif
#if(EVENT_END_LESS)
							//===OpenNPC Endless, show image
						case 0x30:
						{
							XULY_CGPACKET* mRecv = (XULY_CGPACKET*)lpMsg;
							if (!mRecv->ThaoTac) return 1;
							switch (mRecv->ThaoTac)
							{
							case 1: //Open NPC
							{
								if ((GetTickCount() - gInterface.Data[eWindowNPCEndLessTower].EventTick) > 300)
								{
									gInterface.Data[eWindowNPCEndLessTower].OnShow ^= 1;
									gInterface.Data[eWindowNPCEndLessTower].EventTick = GetTickCount();
								}
							}
							break;
							case 2: //Show Img End Wave
							{
								if ((GetTickCount() - gInterface.Data[eWindowNPCEndLessTower].EventTick) > 300)
								{
									gInterface.mEndLessEven_ShowImg = (BYTE)mRecv->ThaoTac;
									gInterface.Data[eWindowNPCEndLessTower].EventTick = GetTickCount();
								}
							}
							break;
							default:
								break;
							}

						}
						break;
						//===RecvInfo Event End Less
						case 0x31:
						{
							ENDLESSEVENT_INFO* mRecv = (ENDLESSEVENT_INFO*)lpMsg;
							gInterface.mEndLessEvenInfoClear();
							gInterface.mEndLessEven_Wave = mRecv->Wave;
							gInterface.mEndLessEven_LiveMob = mRecv->LiveMob;
							gInterface.mEndLessEven_Time = mRecv->Time;
							gInterface.mEndLessEven_State = mRecv->State;
						}
						break;
#endif
						case 0x05:
						{
							BUFFPHE_DATASEND* mRecv = (BUFFPHE_DATASEND*)lpMsg;
							
							//=========================================
							mDT_Top1Point = mRecv->mDT_Top1Point;
							mDT_TongPoint = mRecv->mDT_TongPoint;
							mDT_CapDo = mRecv->mDT_CapDo;
							mDT_PointNext = mRecv->mDT_PointNext;
							memcpy(&mDT_Top1Name, mRecv->mDT_Top1Name, sizeof(mDT_Top1Name));
							//===
							mBT_Top1Point = mRecv->mBT_Top1Point;
							mBT_TongPoint = mRecv->mBT_TongPoint;
							mBT_CapDo = mRecv->mBT_CapDo;
							mBT_PointNext = mRecv->mBT_PointNext;
							memcpy(&mBT_Top1Name, mRecv->mBT_Top1Name, sizeof(mBT_Top1Name));


							mLvCuongHoaHienTai  = mRecv->mLvCuongHoaHienTai;
							mPointUsePhe = mRecv->mPointUsePhe;
							gInterface.DrawMessage(1, "mPointUsePhe %d", mPointUsePhe);
							mDataConfigCuongHoa.clear();
							for (int i = 0; i < mRecv->Count; i++)
							{
								CONFIDATA_CUONGHOA lpInfo = *(CONFIDATA_CUONGHOA*)(((BYTE*)lpMsg) + sizeof(BUFFPHE_DATASEND) + (sizeof(CONFIDATA_CUONGHOA) * i));
							
								mDataConfigCuongHoa.insert(std::pair<int, CONFIDATA_CUONGHOA>(lpInfo.LvCuongHoa, lpInfo));
							
							
							}

							if ((GetTickCount() - gInterface.Data[eWindow_QuanLyBuffPhe].EventTick) > 300)
							{
								gInterface.Data[eWindow_QuanLyBuffPhe].OnShow = 1;
								gInterface.Data[eWindow_QuanLyBuffPhe].EventTick = GetTickCount();
							}
						}
						break;
						case 0x10:
							GCSetSkinModelList((BPMSG_CUSTOM_SKIN_SEND*)lpMsg);
							break;
						case 0x12:
							GCSetInfoSkinSelect((BPMSG_CUSTOM_SKIN_SEND*)lpMsg);
							break;
						//==Open Chon Phe
							case 0x20:
							{
								XULY_CGPACKET* mRecv = (XULY_CGPACKET*)lpMsg;
								if (!mRecv->ThaoTac) return 1;
								if ((GetTickCount() - gInterface.Data[eWindow_ChonPhe].EventTick) > 300)
								{
									gInterface.Data[eWindow_ChonPhe].OnShow ^= 1;
									gInterface.Data[eWindow_ChonPhe].EventTick = GetTickCount();
								}
							}
							break;
#if(EVENT_MAPBAOTIEU)
							//==Open NPC Move Map
							case 0x22:
							{
								XULY_CGPACKET* mRecv = (XULY_CGPACKET*)lpMsg;
								if (!mRecv->ThaoTac) return 1;
								if ((GetTickCount() - gInterface.Data[eWindow_NPCMoveMapBT].EventTick) > 300)
								{
									gInterface.Data[eWindow_NPCMoveMapBT].OnShow ^= 1;
									gInterface.Data[eWindow_NPCMoveMapBT].EventTick = GetTickCount();
									gInterface.Data[eWindow_NPCMoveMapBT].Attribute = mRecv->ThaoTac;
								}
							}
							break;
#endif
						}
						break;



					case 0x4E:
						switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
						{
#if(SOIITEM)
						case 0x0D:
							g_pQuickCommandWindow.ReceiveInventory(lpMsg);
							return 1;
#endif
#if(SOIITEM)
						case 0xD2: //soiitem
							switch (lpMsg[3])
							{
							case 0x05:
								g_pQuickCommandWindow.ReceivePeriodItemList(lpMsg);
								break;
							}
							break;
#endif
						}






		case 0xFB:
			switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
			{

#if(SACHTHUOCTINH_NEW == 1)
			case 0x56:
				gInterface.GetInfoThuocTinh((PMSG_THUOCTINH_UPD*)lpMsg);
				break;
			case 0x57:
				gInterface.GetInfoThuocTinhAtive((PMSG_THUOCTINH_ATIVE_UPD*)lpMsg);
				break;
#endif
#if(FLAG_SKIN)
			case 0x15:
				ThueFlag.RecvData(lpMsg);
				break;
#endif
				//============================================================================================================



#if(OFFLINE_MODE_NEW)
			case 0x00:
				gOfflineMode.GCOfflineModeRecv((PMSG_OFFLINEMODE_REQ*)lpMsg);
				break;
#endif
			case 0xE6:
				gVuKhiRong.GCData((PMSG_VUKHIRONG_RECV*)lpMsg);
				break;

			case 0xE7:
				gCuongHoaWing.GCData((PMSG_CUONGHOAWING_RECV*)lpMsg);
				break;

				case 0xE8:
					gHuyHieuCuongHoa.GCData((PMSG_HUYHIEU_RECV*)lpMsg);
					break;

				case 0x59:
					gInterface.TvTEventEx((PMSG_TVTEVENT_UPD*)lpMsg);
					break;

#if(THANMA)

					//==Than Ma Chien
				case 0x61:
				{
					if ((GetTickCount() - gInterface.Data[eWindowNPC_ThanMaChien].EventTick) > 300)
					{

						gInterface.Data[eWindowNPC_ThanMaChien].EventTick = GetTickCount();
						gInterface.Data[eWindowNPC_ThanMaChien].OnShow ^= 1;
					}
				}
				break;
				//===Set Tiem Than Ma
				case 0x62:
				{
					PMSG_TIMEEVENT_CUSTOM* mRecv = (PMSG_TIMEEVENT_CUSTOM*)lpMsg;
					gInterface.m_EventTMMap = mRecv->Map;
					gInterface.m_EventTMState = mRecv->State;
					gInterface.m_EventTMTimeCount = mRecv->TimeCount;
					gInterface.mCalcTimeEventTick = GetTickCount();
					//gInterface.DrawMessage(1,"TM State %d %d %d", gInterface.m_EventTMMap, gInterface.m_EventTMState, gInterface.m_EventTMTimeCount);

				}
				break;
				//===Set BXH
				case 0x63:
				{
					PMSG_COUNTLIST_TM* mRecv = (PMSG_COUNTLIST_TM*)lpMsg;
					gInterface.m_TMChienBXHC = 0;
					gInterface.m_TMScoreThienThan = mRecv->ScoreAcQuy;
					gInterface.m_TMScoreAcQuy = mRecv->ScoreThienThan;
					for (int n = 0; n < 10; n++)
					{
						memset(gInterface.m_ThanMaChienBXH[n].Name, 0, sizeof(gInterface.m_ThanMaChienBXH[n].Name));
						gInterface.m_ThanMaChienBXH[n].Kill = 0;
						gInterface.m_ThanMaChienBXH[n].Team = 0;
					}

					for (int n = 0; n < mRecv->Count; n++)
					{
						EVENTHANMA_BXH* lpInfo = (EVENTHANMA_BXH*)(((BYTE*)mRecv) + sizeof(PMSG_COUNTLIST_TM) + (sizeof(EVENTHANMA_BXH) * n));
						memcpy(gInterface.m_ThanMaChienBXH[n].Name, lpInfo->Name, sizeof(gInterface.m_ThanMaChienBXH[n].Name));
						gInterface.m_ThanMaChienBXH[n].Kill = lpInfo->Kill;
						gInterface.m_ThanMaChienBXH[n].Team = lpInfo->Team;
						gInterface.m_TMChienBXHC++;

						if (gInterface.m_TMChienBXHC > 10)
						{
							break;
						}
					}
					if (mRecv->OpenBXHWindow == 1)
					{
						gInterface.Data[eWindowBXH_ThanMaChien].OnShow = 1;
					}

				}
				break;
#endif


		#if(DOI_GIOI_TINH)
				case 0x08:
					gChangeClass.RecvData((PMSG_CHANGECLASS_DATA*)lpMsg);
					break;
		#endif


#if(VONGQUAY_NEW)
				case 0x31:
					gLuckySpin.LuckySpinData((GC_LuckySpinUpdateData*)lpMsg);
					break;
				case 0x32:
					LuckySpinRoll();
					break;
				case 0x33:
					gLuckySpin.GCItemSend((GC_LuckySpin_Data*)lpMsg);
					break;
				case 0x34:
					gLuckySpin.GCLuckySpinInit((GC_LuckySpinInit*)lpMsg);
					break;
#endif


				case 200:
					gInterface.GetInfoClient((PMSG_CLIENT_UPD*)lpMsg);
					break;




#if(OANTUTY)
				case 0x88:
					UpdateRPSMode();
					break;
#endif

			}
			break;









		case 0xFF:
			gInterface.DrawPing();
			break;
			//-- Open Ruud
		case 0xEA:
			jCRenderRuud.LoadRuudShop_Recv((PMSG_ITEMRUUD_LIST_RECV*)lpMsg);
			return 1;
		case 0xEE:
			jCRenderRuud.OpenRuudShop_Recv((PMSG_NPC_TALK_RECV*)lpMsg);
			return 1;
			//--post item

		case 0x78:
			RecvPostItem((PMSG_POSTITEM*)lpMsg);
			break;
		//-- Buff Icon
		case 0x2D:
			gIconBuff.Recv((PMSG_SEND_BUFF_ICON * )lpMsg);
			break;
			//-- Party Buff
		case 0x2E:
			gPartyBuffs.RecvPartyBuffs((PMSG_PARTY_EFFECT_LIST_SEND*)lpMsg);
			break;

#if(RANKING_NEW == 1)
		case 0xFE:
			gRanking.RecvInfo((DGCharTop*)lpMsg);
			break;
#endif



#if (takumi12 == 1)
		case 0x79:
			gCentral.CGPartyLifeRecv((PMSG_PARTY_LIFE_SEND *) lpMsg);
			break;
		case 0x7A:
			gCentral.CGPartyListRecv((PMSG_PARTY_LIST_SEND *) lpMsg);
				break;
#endif

	}

	return ProtocolCore(head,lpMsg,size,key);
}

void GCDamageRecv(PMSG_DAMAGE_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]) & 0x7FFF;

	if(ViewIndex == aIndex)
	{
		ViewCurHP = lpMsg->ViewCurHP;
		ViewCurSD = lpMsg->ViewCurSD;
	}

	ViewDamageHP = lpMsg->ViewDamageHP;
	ViewDamageSD = lpMsg->ViewDamageSD;

	if((lpMsg->type & 0x10) != 0)
	{
		if(ViewDamageCount < 3)
		{
			ViewDamageTable[ViewDamageCount++] = lpMsg->ViewDamageHP;
			ViewDamageValue = ViewDamageCount;
		}
	}

	if((lpMsg->type & 0x20) != 0)
	{
		if(ViewDamageCount < 4)
		{
			ViewDamageTable[ViewDamageCount++] = lpMsg->ViewDamageHP;
			ViewDamageValue = ViewDamageCount;
		}
	}
}

void GCMonsterDieRecv(PMSG_MONSTER_DIE_RECV* lpMsg) // OK
{
	ViewDamageHP = lpMsg->ViewDamageHP;
}

void GCUserDieRecv(PMSG_USER_DIE_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]) & 0x7FFF;

	if(ViewIndex == aIndex)
	{
		ViewCurHP = 0;
	}
}

void GCLifeRecv(PMSG_LIFE_RECV* lpMsg) // OK
{
	if(lpMsg->type == 0xFE)
	{
		ViewMaxHP = lpMsg->ViewHP;
		ViewMaxSD = lpMsg->ViewSD;
	}

	if(lpMsg->type == 0xFF)
	{
		ViewCurHP = ((ViewCurHP==0)?ViewCurHP:lpMsg->ViewHP);
		ViewCurSD = lpMsg->ViewSD;
	}
}

void GCManaRecv(PMSG_MANA_RECV* lpMsg) // OK
{
	if(lpMsg->type == 0xFE)
	{
		ViewMaxMP = lpMsg->ViewMP;
		ViewMaxBP = lpMsg->ViewBP;
	}

	if(lpMsg->type == 0xFF)
	{
		ViewCurMP = lpMsg->ViewMP;
		ViewCurBP = lpMsg->ViewBP;
	}
}

void GCFruitResultRecv(PMSG_FRUIT_RESULT_RECV* lpMsg) // OK
{
	if(lpMsg->result == 0 || lpMsg->result == 3 || lpMsg->result == 6 || lpMsg->result == 17)
	{
		ViewValue = lpMsg->ViewValue;
		ViewPoint = lpMsg->ViewPoint;
		ViewStrength = lpMsg->ViewStrength;
		ViewDexterity = lpMsg->ViewDexterity;
		ViewVitality = lpMsg->ViewVitality;
		ViewEnergy = lpMsg->ViewEnergy;
		ViewLeadership = lpMsg->ViewLeadership;
	}
}

void GCRewardExperienceRecv(PMSG_REWARD_EXPERIENCE_RECV* lpMsg) // OK
{
	gObjUser.Refresh();
	ViewDamageHP = lpMsg->ViewDamageHP;
}

void GCQuestRewardRecv(PMSG_QUEST_REWARD_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]) & 0x7FFF;

	if(ViewIndex == aIndex)
	{
		ViewPoint = lpMsg->ViewPoint;
	}
}

void GCMapServerMoveRecv(PMSG_MAP_SERVER_MOVE_RECV* lpMsg) // OK
{
	ReconnectOnMapServerMove(lpMsg->IpAddress,lpMsg->ServerPort);
}

void GCMapServerMoveAuthRecv(PMSG_MAP_SERVER_MOVE_AUTH_RECV* lpMsg) // OK
{
	ReconnectOnMapServerMoveAuth(lpMsg->result);
}

void GCConnectClientRecv(PMSG_CONNECT_CLIENT_RECV* lpMsg) // OK
{
	gHwid.SendHwid();
	ViewIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]);
}

void GCConnectAccountRecv(PMSG_CONNECT_ACCOUNT_RECV* lpMsg) // OK
{
	ReconnectOnConnectAccount(lpMsg->result);
}

void GCCloseClientRecv(PMSG_CLOSE_CLIENT_RECV* lpMsg) // OK
{
	ReconnectOnCloseClient(lpMsg->result);
}

void GCCharacterListRecv(PMSG_CHARACTER_LIST_RECV* lpMsg) // OK
{
	ReconnectOnCharacterList();
}

void GCCharacterInfoRecv(PMSG_CHARACTER_INFO_RECV* lpMsg) // OK
{
	ReconnectOnCharacterInfo();

	ObjectDir = lpMsg->Dir;
	ViewReset = lpMsg->ViewReset;
	ViewPoint = lpMsg->ViewPoint;
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewStrength = lpMsg->ViewStrength;
	ViewDexterity = lpMsg->ViewDexterity;
	ViewVitality = lpMsg->ViewVitality;
	ViewEnergy = lpMsg->ViewEnergy;
	ViewLeadership = lpMsg->ViewLeadership;

	*(WORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+0x07E) = 0;

	*(BYTE*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+0x30C) = 0;

	switch(((*(BYTE*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x0B)) & 7))
	{
	//	case 0:
	//		SetByte(0x00556C38,((gProtect.m_MainInfo.DWMaxAttackSpeed>=0xFFFF)?0x02:0x0F));
	//		break;
	//	case 1:
	//		SetByte(0x00556C38,((gProtect.m_MainInfo.DKMaxAttackSpeed>=0xFFFF)?0x0F:0x0F));
	//		break;
	//	case 2:
	//		SetByte(0x00556C38,((gProtect.m_MainInfo.FEMaxAttackSpeed>=0xFFFF)?0x02:0x0F));
	//		break;
	//	case 3:
	//		SetByte(0x00556C38,((gProtect.m_MainInfo.MGMaxAttackSpeed>=0xFFFF)?0x02:0x0F));
	//		break;
	//	case 4:
	//		SetByte(0x00556C38,((gProtect.m_MainInfo.DLMaxAttackSpeed>=0xFFFF)?0x02:0x0F));
	//		break;
	//	case 5:
	//		SetByte(0x00556C38,((gProtect.m_MainInfo.SUMaxAttackSpeed>=0xFFFF)?0x02:0x0F)); 
	//		break;
	//	case 6:
	//		SetByte(0x00556C38,((gProtect.m_MainInfo.RFMaxAttackSpeed>=0xFFFF)?0x0F:0x0F));
	//		break;

	//}


	case 0:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.DWMaxAttackSpeed >= 0xFFFF) ? 0x03 : 0x0F));
		break;
	case 1:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.DKMaxAttackSpeed >= 0xFFFF) ? 0x04 : 0x0F));
		break;
	case 2:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.FEMaxAttackSpeed >= 0xFFFF) ? 0x03 : 0x0F));
		break;
	case 3:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.MGMaxAttackSpeed >= 0xFFFF) ? 0x03 : 0x0F));
		break;
	case 4:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.DLMaxAttackSpeed >= 0xFFFF) ? 0x03 : 0x0F));
		break;
	case 5:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.SUMaxAttackSpeed >= 0xFFFF) ? 0x03 : 0x0F));
		break;
	case 6:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.RFMaxAttackSpeed >= 0xFFFF) ? 0x0F : 0x0F));
		break;
	}
}

void GCCharacterRegenRecv(PMSG_CHARACTER_REGEN_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewCurSD = lpMsg->ViewCurSD;
}

void GCLevelUpRecv(PMSG_LEVEL_UP_RECV* lpMsg) // OK
{
	ViewPoint = lpMsg->ViewPoint;

	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewExperience = lpMsg->ViewExperience;
	ViewNextExperience = lpMsg->ViewNextExperience;

	ViewCurMP = ViewMaxMP;
	ViewCurBP = ViewMaxBP;
	*(WORD *)(*(DWORD *)0x8128AC8 + 36) = *(WORD *)(*(DWORD *)0x8128AC8 + 40); //-- Mana
	*(WORD *)(*(DWORD *)0x8128AC8 + 64) = *(WORD *)(*(DWORD *)0x8128AC8 + 66); //-- BP
}

void GCLevelUpPointRecv(PMSG_LEVEL_UP_POINT_RECV* lpMsg) // OK
{
	if(lpMsg->result >= 16 && lpMsg->result <= 20)
	{
		ViewPoint = lpMsg->ViewPoint;
		ViewMaxHP = lpMsg->ViewMaxHP;
		ViewMaxMP = lpMsg->ViewMaxMP;
		ViewMaxBP = lpMsg->ViewMaxBP;
		ViewMaxSD = lpMsg->ViewMaxSD;
		ViewStrength = lpMsg->ViewStrength;
		ViewDexterity = lpMsg->ViewDexterity;
		ViewVitality = lpMsg->ViewVitality;
		ViewEnergy = lpMsg->ViewEnergy;
		ViewLeadership = lpMsg->ViewLeadership;
	}
}

void GCMonsterDamageRecv(PMSG_MONSTER_DAMAGE_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewDamageHP = lpMsg->ViewDamageHP;
	ViewDamageSD = lpMsg->ViewDamageSD;
}

void GCMasterInfoRecv(PMSG_MASTER_INFO_RECV* lpMsg) // OK
{
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewMaxSD = lpMsg->ViewMaxSD;
}

void GCMasterLevelUpRecv(PMSG_MASTER_LEVEL_UP_RECV* lpMsg) // OK
{
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewMasterExperience = lpMsg->ViewMasterExperience;
	ViewMasterNextExperience = lpMsg->ViewMasterNextExperience;
	ViewCurMP = ViewMaxMP;
	ViewCurBP = ViewMaxBP;

	*(WORD *)(*(DWORD *)0x8128AC8 + 64) = *(WORD *)(*(DWORD *)0x8128AC8 + 66);
}

void GCNewCharacterInfoRecv(PMSG_NEW_CHARACTER_INFO_RECV* lpMsg) // OK
{
	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x0E) = lpMsg->Level;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x74) = lpMsg->LevelUpPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x18) = lpMsg->Strength;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x1A) = lpMsg->Dexterity;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x1C) = lpMsg->Vitality;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x1E) = lpMsg->Energy;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x20) = lpMsg->Leadership;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x22) = lpMsg->Life;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x26) = lpMsg->MaxLife;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x24) = lpMsg->Mana;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x28) = lpMsg->MaxMana;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x40) = lpMsg->BP;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x42) = lpMsg->MaxBP;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x2A) = lpMsg->Shield;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x2C) = lpMsg->MaxShield;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x4C) = lpMsg->FruitAddPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x4E) = lpMsg->MaxFruitAddPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x50) = lpMsg->FruitSubPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x52) = lpMsg->MaxFruitSubPoint;

	*(DWORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x10) = lpMsg->Experience;

	*(DWORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x14) = lpMsg->NextExperience;

	//EXTRA
	ViewReset = lpMsg->ViewReset;
	ViewPoint = lpMsg->ViewPoint;
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewStrength = lpMsg->ViewStrength;
	ViewDexterity = lpMsg->ViewDexterity;
	ViewVitality = lpMsg->ViewVitality;
	ViewEnergy = lpMsg->ViewEnergy;
	ViewLeadership = lpMsg->ViewLeadership;
}

void GCNewCharacterCalcRecv(PMSG_NEW_CHARACTER_CALC_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewAddStrength = lpMsg->ViewAddStrength;
	ViewAddDexterity = lpMsg->ViewAddDexterity;
	ViewAddVitality = lpMsg->ViewAddVitality;
	ViewAddEnergy = lpMsg->ViewAddEnergy;
	ViewAddLeadership = lpMsg->ViewAddLeadership;
	ViewPhysiDamageMin = lpMsg->ViewPhysiDamageMin;
	ViewPhysiDamageMax = lpMsg->ViewPhysiDamageMax;
	ViewMagicDamageMin = lpMsg->ViewMagicDamageMin;
	ViewMagicDamageMax = lpMsg->ViewMagicDamageMax;
	ViewCurseDamageMin = lpMsg->ViewCurseDamageMin;
	ViewCurseDamageMax = lpMsg->ViewCurseDamageMax;
	ViewMulPhysiDamage = lpMsg->ViewMulPhysiDamage;
	ViewDivPhysiDamage = lpMsg->ViewDivPhysiDamage;
	ViewMulMagicDamage = lpMsg->ViewMulMagicDamage;
	ViewDivMagicDamage = lpMsg->ViewDivMagicDamage;
	ViewMulCurseDamage = lpMsg->ViewMulCurseDamage;
	ViewDivCurseDamage = lpMsg->ViewDivCurseDamage;
	ViewMagicDamageRate = lpMsg->ViewMagicDamageRate;
	ViewCurseDamageRate = lpMsg->ViewCurseDamageRate;
	ViewPhysiSpeed = lpMsg->ViewPhysiSpeed;
	ViewMagicSpeed = lpMsg->ViewMagicSpeed;
	ViewAttackSuccessRate = lpMsg->ViewAttackSuccessRate;
	ViewAttackSuccessRatePvP = lpMsg->ViewAttackSuccessRatePvP;
	ViewDefense = lpMsg->ViewDefense;
	ViewDefenseSuccessRate = lpMsg->ViewDefenseSuccessRate;
	ViewDefenseSuccessRatePvP = lpMsg->ViewDefenseSuccessRatePvP;
	ViewDamageMultiplier = lpMsg->ViewDamageMultiplier;
	ViewRFDamageMultiplierA = lpMsg->ViewRFDamageMultiplierA;
	ViewRFDamageMultiplierB = lpMsg->ViewRFDamageMultiplierB;
	ViewRFDamageMultiplierC = lpMsg->ViewRFDamageMultiplierC;
	ViewDarkSpiritAttackDamageMin = lpMsg->ViewDarkSpiritAttackDamageMin;
	ViewDarkSpiritAttackDamageMax = lpMsg->ViewDarkSpiritAttackDamageMax;
	ViewDarkSpiritAttackSpeed = lpMsg->ViewDarkSpiritAttackSpeed;
	ViewDarkSpiritAttackSuccessRate = lpMsg->ViewDarkSpiritAttackSuccessRate;
}

void GCNewHealthBarRecv(PMSG_NEW_HEALTH_BAR_RECV* lpMsg) // OK
{
	ClearNewHealthBar();

	for(int n=0;n < lpMsg->count;n++)
	{
		PMSG_NEW_HEALTH_RECV* lpInfo = (PMSG_NEW_HEALTH_RECV*)(((BYTE*)lpMsg)+sizeof(PMSG_NEW_HEALTH_BAR_RECV)+(sizeof(PMSG_NEW_HEALTH_RECV)*n));

		InsertNewHealthBar(lpInfo->index, lpInfo->type, lpInfo->rate, lpInfo->rate2, lpInfo->bHasManyFlag);
	}
}

void GCNewGensBattleInfoRecv(PMSG_NEW_GENS_BATTLE_INFO_RECV* lpMsg) // OK
{
	GensBattleMapCount = lpMsg->GensBattleMapCount;

	GensMoveIndexCount = lpMsg->GensMoveIndexCount;

	memcpy(GensBattleMap,lpMsg->GensBattleMap,sizeof(GensBattleMap));

	memcpy(GensMoveIndex,lpMsg->GensMoveIndex,sizeof(GensMoveIndex));
}

void GCNewMessageRecv(PMSG_NEW_MESSAGE_RECV* lpMsg) // OK
{
	PMSG_NEW_MESSAGE_RECV pMsg;
	pMsg.header.set(0xF3,0xE4,sizeof(pMsg));
	DataSend((BYTE*)&pMsg,sizeof(pMsg));
}


//Cashshop Fix
void OpenCashShopSend(BYTE type)
{
	PMSG_CASH_SHOP_OPEN_RECV pMsg;
	pMsg.OpenType = type;
	pMsg.header.set(0xD2,0x02,sizeof(pMsg));
	DataSend((BYTE*)&pMsg,sizeof(pMsg));
}




bool CashShopSwitchState()
{
	sub_861900_Addr((int)pWindowThis());

	if ( !sub_944E50_Addr() )
		return 0;

	void* v48 = sub_93F370_Addr();

	if ( sub_93FCA0_Addr((int)v48) == 1 )
	{
		if ( !sub_93F600_Addr((CHAR *)sub_93F370_Addr()) )
			return 0;
	}

	if ( sub_93FD10_Addr((int)sub_93F370_Addr()) == 1 )
	{
		if ( sub_93F950_Addr((CHAR *)sub_93F370_Addr()) == 1 )
		{
			BYTE* v53 = (BYTE *)sub_941030_Addr((BYTE*)sub_93F370_Addr());
			int v55 = sub_941000_Addr((BYTE*)sub_93F370_Addr());
			BYTE* v57 = (BYTE *)sub_861900_Addr((int)pWindowThis());
			sub_944FE0_Addr(v57, v55, v53);
		}
	}

	if ( pCheckWindow(pWindowThis(), 65) )
	{
		OpenCashShopSend(1);
		pCloseWindow(pWindowThis(), 65);
	}
	else
	{
		if ( !sub_9406C0_Addr((BYTE*)sub_93F370_Addr()) )
		{
			OpenCashShopSend(0);
			sub_9406A0_Addr((BYTE*)sub_93F370_Addr(), 1);
			char* v62 = (char *)sub_8611E0_Addr((DWORD*)pWindowThis());
			sub_815130_Addr(v62, 0, 1);
		}
	}
}

#if(OANTUTY)
void RPSMode(int Number)
{
	RPSMODE_REQ pMsg;
	pMsg.h.set(0xFC, 0x21, sizeof(pMsg));
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}

void UpdateRPSMode()
{
	gInterface.Data[eRock].Attribute = 0;
	gInterface.Data[ePaper].Attribute = 0;
	gInterface.Data[eScissors].Attribute = 0;
}
#endif

void DataSend(BYTE* lpMsg,DWORD size) // OK
{
	BYTE EncBuff[2048];

	if(gPacketManager.AddData(lpMsg,size) != 0 && gPacketManager.ExtractPacket(EncBuff) != 0)
	{
		BYTE send[2048];

		memcpy(send,EncBuff,size);

		if(EncBuff[0] == 0xC3 || EncBuff[0] == 0xC4)
		{
			if(EncBuff[0] == 0xC3)
			{
				BYTE save = EncBuff[1];

				EncBuff[1] = (*(BYTE*)(MAIN_PACKET_SERIAL))++;

				size = gPacketManager.Encrypt(&send[2],&EncBuff[1],(size-1))+2;

				EncBuff[1] = save;

				send[0] = 0xC3;
				send[1] = LOBYTE(size);
			}
			else
			{
				BYTE save = EncBuff[2];

				EncBuff[2] = (*(BYTE*)(MAIN_PACKET_SERIAL))++;

				size = gPacketManager.Encrypt(&send[3],&EncBuff[2],(size-2))+3;

				EncBuff[2] = save;

				send[0] = 0xC4;
				send[1] = HIBYTE(size);
				send[2] = LOBYTE(size);
			}
		}

		((void(__thiscall*)(void*,BYTE*,DWORD))0x00405110)((void*)0x08793750,send,size);
	}
}

void GCRecvCoin(PMSG_COIN_RECV* lpMsg) // OK
{
	Coin1 = lpMsg->Coin1;
	Coin2 = lpMsg->Coin2;
	Coin3 = lpMsg->Coin3;
	Ruud = lpMsg->Ruud;
}

void GCBuyConfirmRecv(PMSG_ITEM_BUY_RECV* lpMsg) // OK
{
	gInterface.Data[eCONFIRM_MAIN].OnShow = true;
	pSetCursorFocus = true;
	gInterface.ConfirmSlot = lpMsg->slot;
}




//======================================= lo nuevo
//--post item
bool RecvPostItem(PMSG_POSTITEM * lpMsg) {

	void * item_post = PostItem::AddItem ( &lpMsg->item_data[0] );

	if ( item_post == nullptr ) { return false; }

	char Name[11] = { '\0' };
	char Messase[61] = { '\0' };
	char Messase_API[70] = { '\0' };
	memcpy_s ( &Name[0], 10, &lpMsg->chatid[0], 10 );
	memcpy_s ( &Messase[0], 60, &lpMsg->chatmsg[0], 60 );
	int len = strlen ( Messase );

	
	// ----
	// Cat text Excillent
	if ( ( BYTE ) Messase[0] == 0xC4 &&
			( BYTE ) Messase[1] == 0x90 &&
			( BYTE ) Messase[2] == 0xE1 &&
			( BYTE ) Messase[3] == 0xBB &&
			( BYTE ) Messase[4] == 0x93 &&
			( BYTE ) Messase[5] == 0x20 &&
			( BYTE ) Messase[6] == 0x68 &&
			( BYTE ) Messase[7] == 0x6F &&
			( BYTE ) Messase[8] == 0xC3 &&
			( BYTE ) Messase[9] == 0xA0 &&
			( BYTE ) Messase[10] == 0x6E &&
			( BYTE ) Messase[11] == 0x20 &&
			( BYTE ) Messase[12] == 0x68 &&
			( BYTE ) Messase[13] == 0xE1 &&
			( BYTE ) Messase[14] == 0xBA &&
			( BYTE ) Messase[15] == 0xA3 &&
			( BYTE ) Messase[16] == 0x6F &&
			( BYTE ) Messase[17] == 0x20 ) {
		strcpy_s ( &Messase[0], 61, &Messase[18] );
	}
	// Cat bot ten neu qua dai
	if ( len > 25 ) 
	{
		for ( int i = 20; i < len; ++i ) 
		{
			if ( isalpha ( Messase[i] ) || Messase[i] == ' ' ) 
			{
				Messase[i] = '.';
				Messase[i + 1] = '.';
				Messase[i + 2] = '.';
				Messase[i + 3] = '\0';
			}
		}
	}
	//push this node to eItemNode
	for (int i = 0; i < 19; i++)
	{
		gPostItem.eItemNode[i] = gPostItem.eItemNode[i + 1];
	}
	gPostItem.eItemNode[19] = (DWORD)item_post;
	//end eItemNode
	sprintf_s( Messase_API, "[Bán] %s_[%08X]", Messase, (DWORD)item_post);
	gPostItem.draw_character_head_chat_text_ = true;
	newInterface::DrawChat ( gPostItem.PostItemColor, &Name[0], &Messase_API[0] );
	// ----

	if ( !gPostItem.draw_character_head_chat_text_ ) 
	{ // da lay duoc base_address
		// xu ly doan chat tren dau nhan vat
		char message[256] = { 0 };
		char * chat_text_first = CharacterHeadChatTextFirst ( gPostItem.draw_character_head_chat_text_base_address_ );
		char * chat_text_last = CharacterHeadChatTextLast ( gPostItem.draw_character_head_chat_text_base_address_ );
		unsigned long msgfirst_len = strlen ( chat_text_first );
		unsigned long msglast_len = strlen ( chat_text_last );
		strcpy_s ( message, sizeof ( message ), chat_text_first );
		strcat_s ( message, chat_text_last );
		unsigned long message_len = strlen ( message );

		if ( message[message_len - 1 - 8 - 2] != '_' ||
				message[message_len - 1 - 8 - 1] != '[' ||
				message[message_len - 1] != ']' ) 
		{
		}
		else 
		{
			message[message_len - 1 - 8 - 2] = '\0';  // cat bo doan duoi

			// copy lai
			if ( msgfirst_len ) 
			{
				memcpy_s ( chat_text_first, 0x50, message, msgfirst_len );
				chat_text_first[msgfirst_len] = '\0';
			}

			if ( msglast_len ) 
			{
				memcpy_s ( chat_text_last, 0x50, &message[msgfirst_len], msglast_len );
				chat_text_last[msglast_len] = '\0';
			}
		}
	}
	return true;
}

//--- pet
void GCPetCharSetRecv(PMSG_NEW_PET_CHARSET_RECV* lpMsg)
{
	ClearNewPetCharSet();

	for (int n = 0; n < lpMsg->count; n++)
	{
		NEW_PET_STRUCT* lpInfo = (NEW_PET_STRUCT*)(((BYTE*)lpMsg) + sizeof(PMSG_NEW_PET_CHARSET_RECV)+(sizeof(NEW_PET_STRUCT)*n));

		InsertNewPetCharSet(lpInfo->index, lpInfo->PetCharSet);
	}
}

void GCPetCharSetSelectCharacterRecv(PMSG_NEW_SELECT_CHARACTER_CHARSET_RECV* lpMsg)
{
	ClearNewPetCharSetSelectCharacter();

	for (int n = 0; n < lpMsg->count; n++)
	{
		PMSG_NEW_CHARACTER_CHARSET_RECV* lpInfo = (PMSG_NEW_CHARACTER_CHARSET_RECV*)(((BYTE*)lpMsg) + sizeof(PMSG_NEW_SELECT_CHARACTER_CHARSET_RECV)+(sizeof(PMSG_NEW_CHARACTER_CHARSET_RECV)*n));

		InsertNewPetCharSetSelectCharacter(lpInfo->Name, lpInfo->PetCharSet);
	}
}

void SetChaosBoxState(PMSG_SET_CHAOSBOX_STATE* Data){
	pChaosBoxState = Data->state;
	return;
}


#if(PARTYSEARCH==1)
void GCPartyListRecv(PMSG_RECV_PARTYLIST* lpMsg){
	gPartySearch.ClearPartyList();
	for (int n = 0; n<lpMsg->Count; n++){
		PMSG_PARTYSEARCH_PARTYLIST* lpInfo = (PMSG_PARTYSEARCH_PARTYLIST*)(((BYTE*)lpMsg) + sizeof(PMSG_RECV_PARTYLIST)+(sizeof(PMSG_PARTYSEARCH_PARTYLIST)*n));
		gPartySearch.InsertPartyList(lpInfo);
	}
	gPartySearch.SwitchPartySearchWindowState();
}
#endif
//=======================
//-- RUUD
//=======================
#if(VONGQUAY_NEW)
void LuckySpinRoll()
{
	gLuckySpin.StartRoll = 1;
}
#endif

#if(CHIEN_TRUONG_CO)
void GCInfoCTC(INFOCTC_SENDCLIENT* lpMsg) // OK
{
	//if((GetTickCount()-gInterface.Data[eCuaSoCTC].EventTick) > 1000)
	{
		CTC_TimeConLai = lpMsg->TimeConLai;
		CTC_PointKillQuai = lpMsg->PointKillQuai;
		CTC_PartyKillPoint = lpMsg->PartyKillPoint;
		CTC_MonterYeuCau = lpMsg->MonterYeuCau;
		gInterface.Data[eCuaSoCTC].OnShow = lpMsg->TYPE;
		gInterface.Data[eCuaSoCTC].EventTick = GetTickCount();
	}
}

void GCCTCKillMonter(CTCKILL_SENDCLIENT* lpMsg) // OK
{
	CTC_QuaiVatDaKill = lpMsg->QuaiKill;
}
#endif


#if(BOSS_GUILD == 1) // ok
void GCBossGuildShowWindow(INFOBOSSGUILD_SENDCLIENT* lpMsg) // OK
{
	if ((GetTickCount() - gInterface.Data[eBossGuildWindow].EventTick) > 300)
	{
		gInterface.Data[eBossGuildWindow].EventTick = GetTickCount();
		gInterface.Data[eBossGuildWindow].OnShow ^= 1;
		gInterface.BUY_TINH_NANG_GAME(7);
	}
}

void GCBossGuildTime(BOSSGUILDTIME_SENDCLIENT* lpMsg) // OK
{
	BossGuild_TimeConLai = lpMsg->TimeBossGuild;
}
#endif



// Protocol.cpp
// =========== CTC Mini
void GCCTCMiniShowWindow(INFOCTCMINI_SENDCLIENT* lpMsg) // OK
{
	if ((GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick) > 300)
	{
		gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
		gInterface.Data[eCTCMiniWindow].OnShow ^= 1;
	}
	CheckVaoLanhDia = lpMsg->GuildWinOld;
}


void GCCTCMiniKill(CTCMINIKILL_SENDCLIENT* lpMsg) // OK
{
	CTCMINI_TimeCTCMini = lpMsg->TimeCTCMini;
	for (int n = 0; n < 3; n++) //Them Cong
	{
		CTCMINI_Cong[n] = lpMsg->Cong[n];
		CTCMINI_Tru[n] = lpMsg->Tru[n];
	}
}


#if(PKEVENT == 1)
void GCInfoPKEvent(INFOPKEVENT_SENDCLIENT* lpMsg) // OK
{
	PKEvent_TimeConLai = lpMsg->TimeConLaiPKEvent;
}
#endif

#if(TVTEVENT == 1)
void GCInfoTvTEvent(INFOTVTEVENT_SENDCLIENT* lpMsg) // OK
{
	TvTEvent_TimeConLai = lpMsg->TimeConLaiTvTEvent;
}
#endif


//=== Set List Skin Model
void GCSetSkinModelList(BPMSG_CUSTOM_SKIN_SEND* lpMsg)
{
	gInterface.m_SkinModelData.clear();

	for (int i = 0; i < lpMsg->count; i++)
	{
		BCUSTOM_SKINMODEL_DATA* lpInfo = (BCUSTOM_SKINMODEL_DATA*)(((BYTE*)lpMsg) + sizeof(BPMSG_CUSTOM_SKIN_SEND) + (sizeof(BCUSTOM_SKINMODEL_DATA) * i));

		gInterface.m_SkinModelData.push_back(*lpInfo);
		//g_Console.AddMessage(3, "GCSetSkinModelList [%d] %d", lpInfo->SkinIndex, lpInfo->StatusBuy);
	}

	//if (gInterface.m_SkinModelData.size())
	//{
	//	if ((GetTickCount() - gInterface.WindowSkin->lastActionTime) >= 1000 && !gInterface.WindowSkin->onShow)
	//	{
	//		gInterface.WindowSkin->onShow ^= 1;
	//		gInterface.WindowSkin->lastActionTime = GetTickCount();
	//	}
	//}
}
void GCSetInfoSkinSelect(BPMSG_CUSTOM_SKIN_SEND* lpMsg)
{
	//SAFE_DELETE(gInterface.m_SkinModelInfoSelect);
	gInterface.m_SkinModelInfoSelect.clear();
	gInterface.SelectInfoSkin = false;
	for (int i = 0; i < lpMsg->count; i++)
	{
		SKIN_MODEL_DATA* lpInfo = (SKIN_MODEL_DATA*)(((BYTE*)lpMsg) + sizeof(BPMSG_CUSTOM_SKIN_SEND) + (sizeof(SKIN_MODEL_DATA) * i));

		gInterface.m_SkinModelInfoSelect.push_back(*lpInfo);
		//SkinSelect = lpInfo->SkinIndex + MODELSKINFIX;

		//gInterface.DrawMessage(3, "GCSetInfoSkinSelect %d [%d] %d",i, gInterface.m_SkinModelInfoSelect[i].Coin, gInterface.m_SkinModelInfoSelect[i].ValueOp[0]);
		gInterface.SelectInfoSkin = true;
	}
	//pDrawMessage("OK INFO", 1);

}
bool CBGetStatusBuySkin(int SkinIndex)
{
	for (int i = 0; i < gInterface.m_SkinModelData.size(); i++)
	{
		if (gInterface.m_SkinModelData[i].SkinIndex == SkinIndex && gInterface.m_SkinModelData[i].StatusBuy)
		{
			return 1;
		}
	}
	return 0;
}
