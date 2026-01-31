// MocNap.h: interface for the MocNap class.
//
//////////////////////////////////////////////////////////////////////
#include "Protocol.h"
#include "user.h"

#pragma once

#define MAX_CLASS 7

#if(MOCNAP == 1)

struct MOCNAP_GD_SAVE_DATA
{
	PSBMSG_HEAD header;
	// ----
	WORD	index;
	char	Name[11];
	// ----
	int		MOCNAP1;
	int		MOCNAP2;
	int		MOCNAP3;
	int		MOCNAP4;
	int		MOCNAP5;
	int		MOCNAP6;
	int		MOCNAP7;
	int		MOCNAP8;
	int		MOCNAP9;
	int		MOCNAP10;
	int		MOCNAP11;
	int		MOCNAP12;
	int		MOCNAP13;
	// ----
};

// -------------------------------------------------------------------------------
struct MOCNAP_GD_REQ_DATA
{
	PSBMSG_HEAD	header;
	WORD index;
	char name[11];
};
// -------------------------------------------------------------------------------

struct MOCNAP_DG_GET_DATA
{
	PSBMSG_HEAD	header;
	// ----
	WORD	index;
	// ----
	int		MOCNAP1;
	int		MOCNAP2;
	int		MOCNAP3;
	int		MOCNAP4;
	int		MOCNAP5;
	int		MOCNAP6;
	int		MOCNAP7;
	int		MOCNAP8;
	int		MOCNAP9;
	int		MOCNAP10;
	int		MOCNAP11;
	int		MOCNAP12;
	int		MOCNAP13;
	// ----
};

struct CUSTOM_MOC_NAP_INFO
{
	int ItemIndex;
	int ItemLevel;
	int ItemDurability;
	int ItemSkill;
	int ItemLuck;
	int ItemOption;
	int ItemExcellent;
	int ItemAncient;
	int ItemJOH;
	int ItemOpEx;
	int ItemSocket1;
	int ItemSocket2;
	int ItemSocket3;
	int ItemSocket4;
	int ItemSocket5;
};

struct MOCNAP_INFO
{
	int Class1;
	int Class2;
	int Class3;
	int Class4;
	int Class5;
	int Class6;
	int Class7;
	int Class8;
	int Class9;
	int Class10;
	int Class11;
	int Class12;
	int Class13;

	std::vector<CUSTOM_MOC_NAP_INFO> MOCNAP1; // ok
	std::vector<CUSTOM_MOC_NAP_INFO> MOCNAP2; // ok
	std::vector<CUSTOM_MOC_NAP_INFO> MOCNAP3; // ok
	std::vector<CUSTOM_MOC_NAP_INFO> MOCNAP4; // ok
	std::vector<CUSTOM_MOC_NAP_INFO> MOCNAP5;
	std::vector<CUSTOM_MOC_NAP_INFO> MOCNAP6;
	std::vector<CUSTOM_MOC_NAP_INFO> MOCNAP7;
	std::vector<CUSTOM_MOC_NAP_INFO> MOCNAP8;
	std::vector<CUSTOM_MOC_NAP_INFO> MOCNAP9;
	std::vector<CUSTOM_MOC_NAP_INFO> MOCNAP10;
	std::vector<CUSTOM_MOC_NAP_INFO> MOCNAP11;
	std::vector<CUSTOM_MOC_NAP_INFO> MOCNAP12;
	std::vector<CUSTOM_MOC_NAP_INFO> MOCNAP13;
};



void MocNapDataSend(int aIndex);

class CMocNap
{

public:
	CMocNap();
	virtual ~CMocNap();
	void Init();
	void Load();

	void Load(char* path);

	void SetInfo(MOCNAP_INFO info);

	void MocNap1(LPOBJ lpObj);
	void MocNap2(LPOBJ lpObj);
	void MocNap3(LPOBJ lpObj);
	void MocNap4(LPOBJ lpObj);
	void MocNap5(LPOBJ lpObj);
	void MocNap6(LPOBJ lpObj);
	void MocNap7(LPOBJ lpObj);
	void MocNap8(LPOBJ lpObj);
	void MocNap9(LPOBJ lpObj);
	void MocNap10(LPOBJ lpObj);
	void MocNap11(LPOBJ lpObj);
	void MocNap12(LPOBJ lpObj);
	void MocNap13(LPOBJ lpObj);

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

	void		GDSaveData(int aIndex);
	void		GDReqData(int aIndex);
	void		GDSaveUserInfo(int aIndex);
	void		GDReqUserInfo(int aIndex);
	void		DGGetData(MOCNAP_DG_GET_DATA * aRecv);

public:

	MOCNAP_INFO m_MocNapInfo[MAX_CLASS];
};

extern CMocNap gMocNap;

#endif