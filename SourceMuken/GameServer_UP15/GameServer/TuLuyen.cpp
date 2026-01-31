#include "StdAfx.h"
#include "user.h"
#include "TuLuyen.h"
#include "DSProtocol.h"
#include "GameMain.h"
#include "Path.h"
#include "MemScript.h"
#include "Util.h"
#include "CashShop.h"
#include "Message.h"
#include "Notice.h"
#include "CustomRankUser.h"
#include "ObjectManager.h"

#if(TULUYEN_NEW)

TuLuyen gTuLuyen;
// -------------------------------------------------------------------------------
TuLuyen::TuLuyen() // OK
{

}
// -------------------------------------------------------------------------------
TuLuyen::~TuLuyen() // OK
{
}
// -------------------------------------------------------------------------------
void TuLuyen::TU_LUYEN_OPTION(LPOBJ lpObj, bool flag)
{
	if (flag != 0)
	{
		return;
	}
	if (lpObj->CB_Status1 != 0)
	{
		return; //
	}

	if (lpObj->rTuLuyen == 0)
	{

	}

	if (lpObj->rTuLuyen == 1)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_01;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_01;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_01;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_01;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_01;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_01;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_01;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_01;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_01;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_01;
	}
	//-----
	if (lpObj->rTuLuyen == 2)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_02;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_02;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_02;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_02;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_02;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_02;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_02;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_02;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_02;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_02;
	}
	//-----
	if (lpObj->rTuLuyen == 3)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_03;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_03;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_03;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_03;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_03;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_03;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_03;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_03;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_03;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_03;
	}
	//-----
	if (lpObj->rTuLuyen == 4)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_04;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_04;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_04;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_04;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_04;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_04;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_04;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_04;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_04;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_04;
	}
	//-----
	if (lpObj->rTuLuyen == 5)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_05;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_05;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_05;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_05;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_05;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_05;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_05;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_05;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_05;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_05;
	}
	//-----
	if (lpObj->rTuLuyen == 6)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_06;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_06;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_06;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_06;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_06;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_06;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_06;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_06;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_06;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_06;
	}
	//-----
	if (lpObj->rTuLuyen == 7)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_07;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_07;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_07;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_07;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_07;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_07;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_07;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_07;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_07;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_07;
	}
	//-----
	if (lpObj->rTuLuyen == 8)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_08;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_08;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_08;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_08;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_08;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_08;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_08;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_08;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_08;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_08;
	}
	//-----
	if (lpObj->rTuLuyen == 9)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_09;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_09;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_09;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_09;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_09;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_09;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_09;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_09;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_09;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_09;
	}
	if (lpObj->rTuLuyen == 10)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_10;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_10;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_10;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_10;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_10;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_10;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_10;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_10;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_10;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_10;
	}
	//-----
	if (lpObj->rTuLuyen == 11)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_11;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_11;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_11;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_11;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_11;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_11;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_11;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_11;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_11;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_11;
	}
	//-----
	if (lpObj->rTuLuyen == 12)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_12;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_12;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_12;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_12;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_12;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_12;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_12;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_12;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_12;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_12;
	}
	//-----
	if (lpObj->rTuLuyen == 13)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_13;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_13;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_13;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_13;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_13;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_13;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_13;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_13;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_13;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_13;
	}
	//-----
	if (lpObj->rTuLuyen == 14)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_14;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_14;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_14;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_14;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_14;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_14;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_14;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_14;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_14;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_14;
	}
	//-----
	if (lpObj->rTuLuyen == 15)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_15;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_15;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_15;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_15;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_15;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_15;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_15;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_15;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_15;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_15;
	}
	//-----
	if (lpObj->rTuLuyen == 16)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_16;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_16;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_16;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_16;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_16;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_16;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_16;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_16;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_16;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_16;
	}
	if (lpObj->rTuLuyen == 17)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_17;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_17;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_17;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_17;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_17;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_17;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_17;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_17;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_17;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_17;
	}
	if (lpObj->rTuLuyen == 18)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_18;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_18;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_18;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_18;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_18;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_18;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_18;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_18;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_18;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_18;
	}
	if (lpObj->rTuLuyen == 19)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_19;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_19;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_19;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_19;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_19;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_19;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_19;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_19;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_19;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_19;
	}
	if (lpObj->rTuLuyen == 20)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_20;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_20;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_20;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_20;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_20;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_20;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_20;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_20;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_20;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_20;
	}
	if (lpObj->rTuLuyen == 21)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_21;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_21;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_21;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_21;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_21;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_21;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_21;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_21;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_21;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_21;
	}
	if (lpObj->rTuLuyen == 22)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_22;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_22;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_22;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_22;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_22;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_22;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_22;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_22;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_22;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_22;
	}
	if (lpObj->rTuLuyen == 23)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_23;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_23;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_23;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_23;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_23;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_23;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_23;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_23;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_23;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_23;
	}
	if (lpObj->rTuLuyen == 24)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_24;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_24;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_24;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_24;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_24;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_24;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_24;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_24;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_24;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_24;
	}
	if (lpObj->rTuLuyen == 25)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_25;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_25;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_25;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_25;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_25;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_25;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_25;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_25;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_25;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_25;
	}
	if (lpObj->rTuLuyen == 26)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_26;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_26;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_26;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_26;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_26;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_26;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_26;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_26;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_26;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_26;
	}
	if (lpObj->rTuLuyen == 27)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_27;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_27;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_27;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_27;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_27;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_27;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_27;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_27;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_27;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_27;
	}
	if (lpObj->rTuLuyen == 28)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_28;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_28;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_28;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_28;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_28;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_28;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_28;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_28;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_28;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_28;
	}
	if (lpObj->rTuLuyen == 29)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_29;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_29;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_29;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_29;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_29;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_29;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_29;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_29;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_29;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_29;
	}
	if (lpObj->rTuLuyen == 30)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_30;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_30;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_30;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_30;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_30;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_30;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_30;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_30;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_30;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_30;
	}
	if (lpObj->rTuLuyen == 31)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_31;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_31;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_31;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_31;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_31;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_31;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_31;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_31;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_31;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_31;
	}
	if (lpObj->rTuLuyen == 32)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_32;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_32;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_32;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_32;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_32;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_32;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_32;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_32;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_32;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_32;
	}
	if (lpObj->rTuLuyen == 33)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_33;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_33;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_33;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_33;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_33;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_33;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_33;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_33;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_33;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_33;
	}
	if (lpObj->rTuLuyen == 34)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_34;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_34;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_34;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_34;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_34;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_34;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_34;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_34;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_34;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_34;
	}
	if (lpObj->rTuLuyen == 35)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_35;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_35;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_35;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_35;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_35;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_35;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_35;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_35;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_35;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_35;
	}
	if (lpObj->rTuLuyen == 36)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_36;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_36;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_36;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_36;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_36;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_36;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_36;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_36;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_36;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_36;
	}
	if (lpObj->rTuLuyen == 37)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_37;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_37;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_37;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_37;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_37;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_37;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_37;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_37;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_37;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_37;
	}
	if (lpObj->rTuLuyen == 38)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_38;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_38;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_38;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_38;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_38;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_38;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_38;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_38;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_38;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_38;
	}
	if (lpObj->rTuLuyen == 39)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_39;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_39;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_39;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_39;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_39;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_39;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_39;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_39;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_39;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_39;
	}
	if (lpObj->rTuLuyen == 40)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_40;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_40;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_40;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_40;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_40;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_40;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_40;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_40;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_40;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_40;
	}
}
// -------------------------------------------------------------------------------
void TuLuyen::LOAD_TXT()
{
	this->TU_LUYEN_WCOINC_01 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_01", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_02 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_02", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_03 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_03", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_04 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_04", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_05 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_05", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_06 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_06", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_07 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_07", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_08 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_08", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_09 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_09", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_10 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_10", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_11 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_11", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_12 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_12", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_13 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_13", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_14 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_14", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_15 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_15", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_16 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_16", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_17 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_17", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_18 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_18", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_19 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_19", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_20 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_20", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_21 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_21", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_22 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_22", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_23 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_23", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_24 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_24", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_25 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_25", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_26 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_26", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_27 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_27", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_28 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_28", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_29 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_29", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_30 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_30", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_31 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_31", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_32 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_32", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_33 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_33", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_34 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_34", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_35 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_35", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_36 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_36", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_37 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_37", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_38 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_38", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_39 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_39", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC_40 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_40", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));

	this->TU_LUYEN_SAT_THUONG_01 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_01", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_02 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_02", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_03 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_03", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_04 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_04", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_05 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_05", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_06 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_06", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_07 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_07", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_08 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_08", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_09 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_09", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_10 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_10", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_11 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_11", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_12 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_12", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_13 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_13", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_14 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_14", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_15 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_15", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_16 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_16", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_17 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_17", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_18 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_18", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_19 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_19", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_20 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_20", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_21 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_21", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_22 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_22", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_23 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_23", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_24 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_24", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_25 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_25", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_26 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_26", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_27 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_27", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_28 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_28", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_29 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_29", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_30 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_30", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_31 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_31", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_32 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_32", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_33 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_33", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_34 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_34", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_35 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_35", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_36 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_36", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_37 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_37", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_38 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_38", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_39 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_39", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_40 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_40", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));

	this->TU_LUYEN_SAT_THUONGX3_01 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_01", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_02 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_02", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_03 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_03", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_04 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_04", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_05 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_05", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_06 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_06", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_07 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_07", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_08 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_08", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_09 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_09", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_10 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_10", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_11 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_11", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_12 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_12", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_13 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_13", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_14 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_14", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_15 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_15", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_16 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_16", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_17 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_17", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_18 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_18", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_19 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_19", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_20 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_20", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_21 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_21", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_22 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_22", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_23 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_23", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_24 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_24", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_25 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_25", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_26 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_26", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_27 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_27", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_28 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_28", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_29 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_29", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_30 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_30", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_31 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_31", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_32 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_32", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_33 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_33", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_34 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_34", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_35 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_35", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_36 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_36", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_37 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_37", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_38 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_38", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_39 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_39", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_40 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_40", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));

	this->TU_LUYEN_HOAN_HAO_01 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_01", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_02 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_02", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_03 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_03", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_04 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_04", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_05 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_05", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_06 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_06", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_07 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_07", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_08 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_08", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_09 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_09", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_10 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_10", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_11 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_11", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_12 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_12", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_13 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_13", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_14 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_14", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_15 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_15", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_16 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_16", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_17 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_17", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_18 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_18", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_19 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_19", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_20 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_20", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_21 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_21", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_22 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_22", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_23 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_23", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_24 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_24", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_25 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_25", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_26 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_26", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_27 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_27", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_28 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_28", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_29 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_29", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_30 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_30", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_31 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_31", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_32 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_32", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_33 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_33", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_34 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_34", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_35 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_35", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_36 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_36", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_37 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_37", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_38 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_38", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_39 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_39", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_40 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_40", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));

	this->TU_LUYEN_THE_LUC_01 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_01", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_02 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_02", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_03 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_03", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_04 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_04", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_05 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_05", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_06 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_06", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_07 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_07", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_08 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_08", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_09 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_09", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_10 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_10", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_11 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_11", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_12 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_12", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_13 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_13", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_14 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_14", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_15 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_15", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_16 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_16", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_17 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_17", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_18 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_18", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_19 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_19", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_20 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_20", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_21 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_21", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_22 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_22", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_23 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_23", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_24 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_24", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_25 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_25", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_26 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_26", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_27 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_27", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_28 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_28", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_29 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_29", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_30 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_30", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_31 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_31", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_32 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_32", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_33 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_33", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_34 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_34", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_35 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_35", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_36 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_36", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_37 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_37", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_38 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_38", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_39 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_39", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_40 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_40", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));

	this->TU_LUYEN_SD_01 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_01", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_02 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_02", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_03 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_03", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_04 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_04", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_05 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_05", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_06 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_06", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_07 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_07", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_08 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_08", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_09 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_09", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_10 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_10", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_11 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_11", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_12 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_12", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_13 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_13", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_14 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_14", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_15 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_15", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_16 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_16", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_17 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_17", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_18 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_18", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_19 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_19", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_20 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_20", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_21 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_21", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_22 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_22", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_23 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_23", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_24 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_24", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_25 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_25", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_26 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_26", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_27 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_27", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_28 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_28", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_29 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_29", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_30 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_30", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_31 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_31", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_32 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_32", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_33 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_33", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_34 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_34", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_35 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_35", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_36 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_36", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_37 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_37", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_38 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_38", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_39 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_39", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_40 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_40", 0, gPath.GetFullPath("Custom\\TuLuyen\\CustomTuLuyen.ini"));


}
// -------------------------------------------------------------------------------
void TuLuyen::BUY_TU_LUYEN(LPOBJ lpObj, BUY_TU_LUYEN_REQ *aRecv)
{
	if (aRecv->Number == 1)
	{
		////27-03-2022
		//if (gVanThanhProtect.TuLuyen == 0)
		//{
		//	gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Chức năng bảo trì!");
		//	return;
		//}
#if(CHECK_USER == 1)
		if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
			|| lpObj->Interface.type == INTERFACE_TRADE
			|| lpObj->Interface.type == INTERFACE_PARTY
			|| lpObj->Interface.type == INTERFACE_WAREHOUSE
			|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
			|| lpObj->Interface.type == INTERFACE_CASH_SHOP
			|| lpObj->Interface.type == INTERFACE_TRAINER
			|| lpObj->Interface.use != 0
			|| lpObj->State == OBJECT_DELCMD
			|| lpObj->DieRegen != 0
			|| lpObj->Teleport != 0
			|| lpObj->PShopOpen != 0
			|| lpObj->ChaosLock != 0
			|| lpObj->SkillSummonPartyTime != 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
			return;
		}
		// Delay Khi Click
		if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(42));
			return;
		}
#endif
		//---------------------------------------------------------
		if (lpObj->rTuLuyen < 1)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_01)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_01);
				return;
			}
			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_01), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Tân Tú]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 2)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_02)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_02);
				return;
			}
			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_02), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Hành Giả]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 3)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_03)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_03);
				return;
			}
			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_03), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Du Hiệp]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 4)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_04)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_04);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_04), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Cư Sĩ]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 5)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_05)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_05);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_05), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Khắc Tinh", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 6)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_06)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_06);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_06), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Tân Nhập]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 7)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_07)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_07);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_07), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Thiên Sứ]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 8)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_08)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_08);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_08), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Trưởng Lão]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 9)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_09)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_09);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_09), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Chân Nhân]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 10)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_10)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_10);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_10), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Tôn Giả]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 11)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_11)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_11);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_11), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Tân Tiên]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 12)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_12)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_12);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_12), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Địa Tiên]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 13)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_13)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_13);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_13), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Thiên Tiên]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 14)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_14)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_14);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_14), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Chân Tiên]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 15)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_15)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_15);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_15), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Linh Tiên]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 16)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_16)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_16);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_16), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Thượng Tiên[", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 17)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_17)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_17);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_17), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Kim Tiên]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 18)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_18)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_18);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_18), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Tiên Quân]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 19)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_19)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_19);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_19), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Tiên Tôn]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 20)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_20)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_20);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_20), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Tiên Đế]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 21)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_21)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_21);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_21), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Trì Thiên]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 22)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_22)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_22);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_22), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Huyền Thiên]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 23)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_23)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_23);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_23), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Hồng Thiên]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 24)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_24)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_24);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_24), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Trân Thiên]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 25)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_25)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_25);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_25), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Thông Thiên]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 26)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_26)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_26);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_26), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Lăng Thiên]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 27)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_27)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_27);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_27), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Hỗn Thiên]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 28)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_28)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_28);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_28), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Tề Thiên]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 29)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_29)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_29);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_29), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Ngạo Thiên]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 30)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_30)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_30);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_30), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Chúng Thần]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 31)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_31)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_31);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_31), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Độ Ách]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 32)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_32)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_32);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_32), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Luân Chuyển]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 33)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_33)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_33);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_33), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Ngự Long]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 34)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_34)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_34);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_34), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Thần Võ]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 35)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_35)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_35);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_35), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Đấu Thế]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 36)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_36)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_36);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_36), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Vô Lượng]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 37)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_37)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_37);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_37), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Hỗn Nguyên]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 38)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_38)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_38);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_38), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Thái Thanh]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 39)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_39)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_39);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_39), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Vô Đối]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//---------------------------------------------------------
		else if (lpObj->rTuLuyen < 40)
		{
			if (lpObj->rTuLuyen > 40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn Đã Đạt Cấp Độ Tối Đa!");
				return;
			}

			if (lpObj->Coin1 < this->TU_LUYEN_WCOINC_40)
			{
				gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Tài Khoản Không Đủ %d WCoinC", this->TU_LUYEN_WCOINC_40);
				return;
			}

			GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC_40), 0, 0, "Tu Luyện");
			//gCashShop.CGCashShopPointRecv(lpObj->Index);
			lpObj->rTuLuyen += 1; // Thay Đổi
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "Nhân Vật [%s] Đã Tu Luyện Lên [Thần Thánh]", lpObj->Name);
			gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
			//GDCharacterInfoSaveSend(lpObj->Index);
			gObjectManager.CharacterCalcAttribute(lpObj->Index);
		}
		//Set Delay
		lpObj->ClickClientSend = GetTickCount();
	}
}

struct TULUYEN_UPDATE
{
	PBMSG_HEAD3 h;
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

void TuLuyenDataSend(int aIndex)
{
	TULUYEN_UPDATE rSend;
	LPOBJ lpObj = &gObj[aIndex];
	rSend.h.set((LPBYTE)&rSend, 0xF3, 100, sizeof(rSend));

	rSend.TU_LUYEN_WCOINC_01 = gTuLuyen.TU_LUYEN_WCOINC_01;
	rSend.TU_LUYEN_WCOINC_02 = gTuLuyen.TU_LUYEN_WCOINC_02;
	rSend.TU_LUYEN_WCOINC_03 = gTuLuyen.TU_LUYEN_WCOINC_03;
	rSend.TU_LUYEN_WCOINC_04 = gTuLuyen.TU_LUYEN_WCOINC_04;
	rSend.TU_LUYEN_WCOINC_05 = gTuLuyen.TU_LUYEN_WCOINC_05;
	rSend.TU_LUYEN_WCOINC_06 = gTuLuyen.TU_LUYEN_WCOINC_06;
	rSend.TU_LUYEN_WCOINC_07 = gTuLuyen.TU_LUYEN_WCOINC_07;
	rSend.TU_LUYEN_WCOINC_08 = gTuLuyen.TU_LUYEN_WCOINC_08;
	rSend.TU_LUYEN_WCOINC_09 = gTuLuyen.TU_LUYEN_WCOINC_09;
	rSend.TU_LUYEN_WCOINC_10 = gTuLuyen.TU_LUYEN_WCOINC_10;
	rSend.TU_LUYEN_WCOINC_11 = gTuLuyen.TU_LUYEN_WCOINC_11;
	rSend.TU_LUYEN_WCOINC_12 = gTuLuyen.TU_LUYEN_WCOINC_12;
	rSend.TU_LUYEN_WCOINC_13 = gTuLuyen.TU_LUYEN_WCOINC_13;
	rSend.TU_LUYEN_WCOINC_14 = gTuLuyen.TU_LUYEN_WCOINC_14;
	rSend.TU_LUYEN_WCOINC_15 = gTuLuyen.TU_LUYEN_WCOINC_15;
	rSend.TU_LUYEN_WCOINC_16 = gTuLuyen.TU_LUYEN_WCOINC_16;
	rSend.TU_LUYEN_WCOINC_17 = gTuLuyen.TU_LUYEN_WCOINC_17;
	rSend.TU_LUYEN_WCOINC_18 = gTuLuyen.TU_LUYEN_WCOINC_18;
	rSend.TU_LUYEN_WCOINC_19 = gTuLuyen.TU_LUYEN_WCOINC_19;
	rSend.TU_LUYEN_WCOINC_20 = gTuLuyen.TU_LUYEN_WCOINC_20;
	rSend.TU_LUYEN_WCOINC_21 = gTuLuyen.TU_LUYEN_WCOINC_21;
	rSend.TU_LUYEN_WCOINC_22 = gTuLuyen.TU_LUYEN_WCOINC_22;
	rSend.TU_LUYEN_WCOINC_23 = gTuLuyen.TU_LUYEN_WCOINC_23;
	rSend.TU_LUYEN_WCOINC_24 = gTuLuyen.TU_LUYEN_WCOINC_24;
	rSend.TU_LUYEN_WCOINC_25 = gTuLuyen.TU_LUYEN_WCOINC_25;
	rSend.TU_LUYEN_WCOINC_26 = gTuLuyen.TU_LUYEN_WCOINC_26;
	rSend.TU_LUYEN_WCOINC_27 = gTuLuyen.TU_LUYEN_WCOINC_27;
	rSend.TU_LUYEN_WCOINC_28 = gTuLuyen.TU_LUYEN_WCOINC_28;
	rSend.TU_LUYEN_WCOINC_29 = gTuLuyen.TU_LUYEN_WCOINC_29;
	rSend.TU_LUYEN_WCOINC_30 = gTuLuyen.TU_LUYEN_WCOINC_30;
	rSend.TU_LUYEN_WCOINC_31 = gTuLuyen.TU_LUYEN_WCOINC_31;
	rSend.TU_LUYEN_WCOINC_32 = gTuLuyen.TU_LUYEN_WCOINC_32;
	rSend.TU_LUYEN_WCOINC_33 = gTuLuyen.TU_LUYEN_WCOINC_33;
	rSend.TU_LUYEN_WCOINC_34 = gTuLuyen.TU_LUYEN_WCOINC_34;
	rSend.TU_LUYEN_WCOINC_35 = gTuLuyen.TU_LUYEN_WCOINC_35;
	rSend.TU_LUYEN_WCOINC_36 = gTuLuyen.TU_LUYEN_WCOINC_36;
	rSend.TU_LUYEN_WCOINC_37 = gTuLuyen.TU_LUYEN_WCOINC_37;
	rSend.TU_LUYEN_WCOINC_38 = gTuLuyen.TU_LUYEN_WCOINC_38;
	rSend.TU_LUYEN_WCOINC_39 = gTuLuyen.TU_LUYEN_WCOINC_39;
	rSend.TU_LUYEN_WCOINC_40 = gTuLuyen.TU_LUYEN_WCOINC_40;

	DataSend(aIndex, (LPBYTE)&rSend, sizeof(rSend));
}

#endif
