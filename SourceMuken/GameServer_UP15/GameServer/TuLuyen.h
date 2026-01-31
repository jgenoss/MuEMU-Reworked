#include "user.h"
#include "Protocol.h"
#pragma once
#if(TULUYEN_NEW == 1)
// -------------------------------------------------------------------------------
struct BUY_TU_LUYEN_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
// -------------------------------------------------------------------------------

void TuLuyenDataSend(int aIndex);

class TuLuyen
{
public:
	// ----
	TuLuyen();
	virtual ~TuLuyen();
	// ----
	void		BUY_TU_LUYEN(LPOBJ lpObj, BUY_TU_LUYEN_REQ *aRecv);

	void		TU_LUYEN_OPTION(LPOBJ lpObj, bool flag);
	// ----
	void	    LOAD_TXT();
	// ----
	int        TU_LUYEN_WCOINC_01;
	int        TU_LUYEN_WCOINC_02;
	int        TU_LUYEN_WCOINC_03;
	int        TU_LUYEN_WCOINC_04;
	int        TU_LUYEN_WCOINC_05;
	int        TU_LUYEN_WCOINC_06;
	int        TU_LUYEN_WCOINC_07;
	int        TU_LUYEN_WCOINC_08;
	int        TU_LUYEN_WCOINC_09;
	int        TU_LUYEN_WCOINC_10;
	int        TU_LUYEN_WCOINC_11;
	int        TU_LUYEN_WCOINC_12;
	int        TU_LUYEN_WCOINC_13;
	int        TU_LUYEN_WCOINC_14;
	int        TU_LUYEN_WCOINC_15;
	int        TU_LUYEN_WCOINC_16;
	int        TU_LUYEN_WCOINC_17;
	int        TU_LUYEN_WCOINC_18;
	int        TU_LUYEN_WCOINC_19;
	int        TU_LUYEN_WCOINC_20;
	int        TU_LUYEN_WCOINC_21;
	int        TU_LUYEN_WCOINC_22;
	int        TU_LUYEN_WCOINC_23;
	int        TU_LUYEN_WCOINC_24;
	int        TU_LUYEN_WCOINC_25;
	int        TU_LUYEN_WCOINC_26;
	int        TU_LUYEN_WCOINC_27;
	int        TU_LUYEN_WCOINC_28;
	int        TU_LUYEN_WCOINC_29;
	int        TU_LUYEN_WCOINC_30;
	int        TU_LUYEN_WCOINC_31;
	int        TU_LUYEN_WCOINC_32;
	int        TU_LUYEN_WCOINC_33;
	int        TU_LUYEN_WCOINC_34;
	int        TU_LUYEN_WCOINC_35;
	int        TU_LUYEN_WCOINC_36;
	int        TU_LUYEN_WCOINC_37;
	int        TU_LUYEN_WCOINC_38;
	int        TU_LUYEN_WCOINC_39;
	int        TU_LUYEN_WCOINC_40;

	int         TU_LUYEN_SAT_THUONG_01;
	int         TU_LUYEN_SAT_THUONGX3_01;
	int         TU_LUYEN_HOAN_HAO_01;
	int         TU_LUYEN_THE_LUC_01;
	int         TU_LUYEN_SD_01;

	int         TU_LUYEN_SAT_THUONG_02;
	int         TU_LUYEN_SAT_THUONGX3_02;
	int         TU_LUYEN_HOAN_HAO_02;
	int         TU_LUYEN_THE_LUC_02;
	int         TU_LUYEN_SD_02;

	int         TU_LUYEN_SAT_THUONG_03;
	int         TU_LUYEN_SAT_THUONGX3_03;
	int         TU_LUYEN_HOAN_HAO_03;
	int         TU_LUYEN_THE_LUC_03;
	int         TU_LUYEN_SD_03;

	int         TU_LUYEN_SAT_THUONG_04;
	int         TU_LUYEN_SAT_THUONGX3_04;
	int         TU_LUYEN_HOAN_HAO_04;
	int         TU_LUYEN_THE_LUC_04;
	int         TU_LUYEN_SD_04;

	int         TU_LUYEN_SAT_THUONG_05;
	int         TU_LUYEN_SAT_THUONGX3_05;
	int         TU_LUYEN_HOAN_HAO_05;
	int         TU_LUYEN_THE_LUC_05;
	int         TU_LUYEN_SD_05;

	int         TU_LUYEN_SAT_THUONG_06;
	int         TU_LUYEN_SAT_THUONGX3_06;
	int         TU_LUYEN_HOAN_HAO_06;
	int         TU_LUYEN_THE_LUC_06;
	int         TU_LUYEN_SD_06;

	int         TU_LUYEN_SAT_THUONG_07;
	int         TU_LUYEN_SAT_THUONGX3_07;
	int         TU_LUYEN_HOAN_HAO_07;
	int         TU_LUYEN_THE_LUC_07;
	int         TU_LUYEN_SD_07;

	int         TU_LUYEN_SAT_THUONG_08;
	int         TU_LUYEN_SAT_THUONGX3_08;
	int         TU_LUYEN_HOAN_HAO_08;
	int         TU_LUYEN_THE_LUC_08;
	int         TU_LUYEN_SD_08;

	int         TU_LUYEN_SAT_THUONG_09;
	int         TU_LUYEN_SAT_THUONGX3_09;
	int         TU_LUYEN_HOAN_HAO_09;
	int         TU_LUYEN_THE_LUC_09;
	int         TU_LUYEN_SD_09;

	int         TU_LUYEN_SAT_THUONG_10;
	int         TU_LUYEN_SAT_THUONGX3_10;
	int         TU_LUYEN_HOAN_HAO_10;
	int         TU_LUYEN_THE_LUC_10;
	int         TU_LUYEN_SD_10;

	int         TU_LUYEN_SAT_THUONG_11;
	int         TU_LUYEN_SAT_THUONGX3_11;
	int         TU_LUYEN_HOAN_HAO_11;
	int         TU_LUYEN_THE_LUC_11;
	int         TU_LUYEN_SD_11;

	int         TU_LUYEN_SAT_THUONG_12;
	int         TU_LUYEN_SAT_THUONGX3_12;
	int         TU_LUYEN_HOAN_HAO_12;
	int         TU_LUYEN_THE_LUC_12;
	int         TU_LUYEN_SD_12;

	int         TU_LUYEN_SAT_THUONG_13;
	int         TU_LUYEN_SAT_THUONGX3_13;
	int         TU_LUYEN_HOAN_HAO_13;
	int         TU_LUYEN_THE_LUC_13;
	int         TU_LUYEN_SD_13;

	int         TU_LUYEN_SAT_THUONG_14;
	int         TU_LUYEN_SAT_THUONGX3_14;
	int         TU_LUYEN_HOAN_HAO_14;
	int         TU_LUYEN_THE_LUC_14;
	int         TU_LUYEN_SD_14;

	int         TU_LUYEN_SAT_THUONG_15;
	int         TU_LUYEN_SAT_THUONGX3_15;
	int         TU_LUYEN_HOAN_HAO_15;
	int         TU_LUYEN_THE_LUC_15;
	int         TU_LUYEN_SD_15;

	int         TU_LUYEN_SAT_THUONG_16;
	int         TU_LUYEN_SAT_THUONGX3_16;
	int         TU_LUYEN_HOAN_HAO_16;
	int         TU_LUYEN_THE_LUC_16;
	int         TU_LUYEN_SD_16;

	int         TU_LUYEN_SAT_THUONG_17;
	int         TU_LUYEN_SAT_THUONGX3_17;
	int         TU_LUYEN_HOAN_HAO_17;
	int         TU_LUYEN_THE_LUC_17;
	int         TU_LUYEN_SD_17;

	int         TU_LUYEN_SAT_THUONG_18;
	int         TU_LUYEN_SAT_THUONGX3_18;
	int         TU_LUYEN_HOAN_HAO_18;
	int         TU_LUYEN_THE_LUC_18;
	int         TU_LUYEN_SD_18;

	int         TU_LUYEN_SAT_THUONG_19;
	int         TU_LUYEN_SAT_THUONGX3_19;
	int         TU_LUYEN_HOAN_HAO_19;
	int         TU_LUYEN_THE_LUC_19;
	int         TU_LUYEN_SD_19;

	int         TU_LUYEN_SAT_THUONG_20;
	int         TU_LUYEN_SAT_THUONGX3_20;
	int         TU_LUYEN_HOAN_HAO_20;
	int         TU_LUYEN_THE_LUC_20;
	int         TU_LUYEN_SD_20;

	int         TU_LUYEN_SAT_THUONG_21;
	int         TU_LUYEN_SAT_THUONGX3_21;
	int         TU_LUYEN_HOAN_HAO_21;
	int         TU_LUYEN_THE_LUC_21;
	int         TU_LUYEN_SD_21;

	int         TU_LUYEN_SAT_THUONG_22;
	int         TU_LUYEN_SAT_THUONGX3_22;
	int         TU_LUYEN_HOAN_HAO_22;
	int         TU_LUYEN_THE_LUC_22;
	int         TU_LUYEN_SD_22;

	int         TU_LUYEN_SAT_THUONG_23;
	int         TU_LUYEN_SAT_THUONGX3_23;
	int         TU_LUYEN_HOAN_HAO_23;
	int         TU_LUYEN_THE_LUC_23;
	int         TU_LUYEN_SD_23;

	int         TU_LUYEN_SAT_THUONG_24;
	int         TU_LUYEN_SAT_THUONGX3_24;
	int         TU_LUYEN_HOAN_HAO_24;
	int         TU_LUYEN_THE_LUC_24;
	int         TU_LUYEN_SD_24;

	int         TU_LUYEN_SAT_THUONG_25;
	int         TU_LUYEN_SAT_THUONGX3_25;
	int         TU_LUYEN_HOAN_HAO_25;
	int         TU_LUYEN_THE_LUC_25;
	int         TU_LUYEN_SD_25;

	int         TU_LUYEN_SAT_THUONG_26;
	int         TU_LUYEN_SAT_THUONGX3_26;
	int         TU_LUYEN_HOAN_HAO_26;
	int         TU_LUYEN_THE_LUC_26;
	int         TU_LUYEN_SD_26;

	int         TU_LUYEN_SAT_THUONG_27;
	int         TU_LUYEN_SAT_THUONGX3_27;
	int         TU_LUYEN_HOAN_HAO_27;
	int         TU_LUYEN_THE_LUC_27;
	int         TU_LUYEN_SD_27;

	int         TU_LUYEN_SAT_THUONG_28;
	int         TU_LUYEN_SAT_THUONGX3_28;
	int         TU_LUYEN_HOAN_HAO_28;
	int         TU_LUYEN_THE_LUC_28;
	int         TU_LUYEN_SD_28;

	int         TU_LUYEN_SAT_THUONG_29;
	int         TU_LUYEN_SAT_THUONGX3_29;
	int         TU_LUYEN_HOAN_HAO_29;
	int         TU_LUYEN_THE_LUC_29;
	int         TU_LUYEN_SD_29;

	int         TU_LUYEN_SAT_THUONG_30;
	int         TU_LUYEN_SAT_THUONGX3_30;
	int         TU_LUYEN_HOAN_HAO_30;
	int         TU_LUYEN_THE_LUC_30;
	int         TU_LUYEN_SD_30;

	int         TU_LUYEN_SAT_THUONG_31;
	int         TU_LUYEN_SAT_THUONGX3_31;
	int         TU_LUYEN_HOAN_HAO_31;
	int         TU_LUYEN_THE_LUC_31;
	int         TU_LUYEN_SD_31;

	int         TU_LUYEN_SAT_THUONG_32;
	int         TU_LUYEN_SAT_THUONGX3_32;
	int         TU_LUYEN_HOAN_HAO_32;
	int         TU_LUYEN_THE_LUC_32;
	int         TU_LUYEN_SD_32;

	int         TU_LUYEN_SAT_THUONG_33;
	int         TU_LUYEN_SAT_THUONGX3_33;
	int         TU_LUYEN_HOAN_HAO_33;
	int         TU_LUYEN_THE_LUC_33;
	int         TU_LUYEN_SD_33;

	int         TU_LUYEN_SAT_THUONG_34;
	int         TU_LUYEN_SAT_THUONGX3_34;
	int         TU_LUYEN_HOAN_HAO_34;
	int         TU_LUYEN_THE_LUC_34;
	int         TU_LUYEN_SD_34;

	int         TU_LUYEN_SAT_THUONG_35;
	int         TU_LUYEN_SAT_THUONGX3_35;
	int         TU_LUYEN_HOAN_HAO_35;
	int         TU_LUYEN_THE_LUC_35;
	int         TU_LUYEN_SD_35;

	int         TU_LUYEN_SAT_THUONG_36;
	int         TU_LUYEN_SAT_THUONGX3_36;
	int         TU_LUYEN_HOAN_HAO_36;
	int         TU_LUYEN_THE_LUC_36;
	int         TU_LUYEN_SD_36;

	int         TU_LUYEN_SAT_THUONG_37;
	int         TU_LUYEN_SAT_THUONGX3_37;
	int         TU_LUYEN_HOAN_HAO_37;
	int         TU_LUYEN_THE_LUC_37;
	int         TU_LUYEN_SD_37;

	int         TU_LUYEN_SAT_THUONG_38;
	int         TU_LUYEN_SAT_THUONGX3_38;
	int         TU_LUYEN_HOAN_HAO_38;
	int         TU_LUYEN_THE_LUC_38;
	int         TU_LUYEN_SD_38;

	int         TU_LUYEN_SAT_THUONG_39;
	int         TU_LUYEN_SAT_THUONGX3_39;
	int         TU_LUYEN_HOAN_HAO_39;
	int         TU_LUYEN_THE_LUC_39;
	int         TU_LUYEN_SD_39;

	int         TU_LUYEN_SAT_THUONG_40;
	int         TU_LUYEN_SAT_THUONGX3_40;
	int         TU_LUYEN_HOAN_HAO_40;
	int         TU_LUYEN_THE_LUC_40;
	int         TU_LUYEN_SD_40;


}; extern TuLuyen gTuLuyen;

#endif
// -------------------------------------------------------------------------------