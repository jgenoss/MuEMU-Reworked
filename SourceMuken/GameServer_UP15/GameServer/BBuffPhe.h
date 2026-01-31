#pragma once
#include "DefaultClassInfo.h"
#include "User.h"
#include "Protocol.h"
#include "DSProtocol.h"

struct LISTMONTER_POINT
{
	int MonterClass;
	int Map;
	int Point;
};
struct CONFIDATA_CUONGHOA
{
	WORD LvCuongHoa;
	DWORD CongHienYC;
	DWORD TangMau;
	DWORD TangSD;
	DWORD TangST;
	DWORD TangPT;

};
struct CONFIDATA_BUFFPHE
{
	WORD CapDoPhe;
	DWORD TongPoint;

};
struct BUFFPHE_REQUESTDS
{
	PSBMSG_HEAD header;
	int aIndex;
	char Name[11];
};

struct BUFFPHE_REQUESTDS_SETINFO
{
	PSWMSG_HEAD header; // C2:04
	int  mDT_TongPoint;
	char mDT_Top1Name[11];
	int  mDT_Top1Point;
	//==
	int  mBT_TongPoint;
	char mBT_Top1Name[11];
	int  mBT_Top1Point;
};
struct INFOCHAR_BUFFPHE
{
	PSWMSG_HEAD header; // C2:04
	WORD index;
	BYTE result;
	char name[11];
	BYTE Class;
	WORD Level;
	BYTE Inventory[INVENTORY_SIZE][16];
	BYTE Skill[MAX_SKILL_LIST][3];
	BYTE Effect[MAX_EFFECT_LIST][13];
	BYTE ChonPheHanhTau;
	int PointUsePhe;
	// GUild
	char GuildName[9];
	int GuildNumber;
	int GuildStatus;
};
struct BUFFPHE_DATASEND
{
	PSWMSG_HEAD header;
	int  mDT_CapDo;
	int  mDT_TongPoint;
	int  mDT_PointNext;
	char mDT_Top1Name[11];
	int  mDT_Top1Point;
	//==
	int  mBT_CapDo;
	int  mBT_TongPoint;
	int  mBT_PointNext;
	char mBT_Top1Name[11];
	int  mBT_Top1Point;

	int mLvCuongHoaHienTai;
	int mPointUsePhe;
	int Count;

};

class CBBuffPhe
{
public:
	CBBuffPhe();
	virtual ~CBBuffPhe();
	//===
	int  DT_TongPoint;
	char DT_Top1Name[11];
	int  DT_Top1Point;
	WORD DT_CapDo;
	//==
	int  BT_TongPoint;
	char BT_Top1Name[11];
	int  BT_Top1Point;
	WORD BT_CapDo;
	//===
	int DelayGetTop;
	DWORD CacheTimeGetTop;
	DWORD m_TickCount;
	int CacheIndex[2];
	WORD TuongMap;
	WORD TuongX[2]; //0 Dao Tac, 1 Bao Tieu
	WORD TuongY[2];
	WORD TuongDir[2];

	std::vector<LISTMONTER_POINT> mDBMonterPoint;
	std::map<int, CONFIDATA_CUONGHOA> mDataConfigCuongHoa;
	std::map<int, CONFIDATA_BUFFPHE> mDataConfigBuffPhe;
	void LoadFileXML(char* FilePath);
	bool CheckMonterPoint(LPOBJ lpObj, LPOBJ Target);
	void CongTruRuud(LPOBJ lpObj, int Point, int TruCoin = 0);
	void InitData();

	int CBBuffPhe::GetCapDoPhe(int TongPoint);
	int CBBuffPhe::GetPointInCapDo(int CapDo);
	CONFIDATA_CUONGHOA* CBBuffPhe::GetInfoCuongHoaInCapDo(int CapDoCuongHoa);
	int CBBuffPhe::GetCapCHInPoint(int Point);
	void CBBuffPhe::CacheDataBuffPhe(BUFFPHE_REQUESTDS_SETINFO* lpMsg);
	void CBBuffPhe::MainProc();
	void CBBuffPhe::GetInfoCharTop(int Type);
	void CBBuffPhe::RecvCharInfoAddBot(INFOCHAR_BUFFPHE* lpMsg);
	void CBBuffPhe::SendInfoClient(int aIndex); // OK
	void CBBuffPhe::GetOptionCuongHoa(LPOBJ lpObj, bool flag);
	bool CBBuffPhe::CongHienBuffPhe(int aIndex, int Point);
};

extern CBBuffPhe gBBuffPhe;
