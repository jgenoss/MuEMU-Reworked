#if(CHIEN_TRUONG_CO)
#include "user.h"
#include "Protocol.h"

struct INFOCTC_SENDCLIENT
{
	PSBMSG_HEAD header; // C3:F3:03
	DWORD TimeConLai;
	DWORD PointKillQuai;
	DWORD PartyKillPoint;
	DWORD MonterYeuCau;
	DWORD TYPE;

};


struct CTCKILL_SENDCLIENT
{
	PSBMSG_HEAD header; // C3:F3:03
	DWORD QuaiKill;

};
struct CAPNHAT_CTC_0H
{
	PWMSG_HEAD header;
	WORD	index;
	int		TimeCTC;
};


class cChienTruongCo
{
public:
	cChienTruongCo();
	virtual ~cChienTruongCo();
	void LoadData(char * FilePath);
	int Enabled;
	int TimeBuyMin;
	int WCoinBuy;
	int MaxBuyDay;

	int Class;
	int Map;
	int X;
	int Y;

	int LoaiTien;
	int PointKillMonter;
	int PartyKillPoint;
	char MsgTPoint[256];

	int SLQuaiYeuCau;
	int IndexType;
	char MsgTKill[256];

	void SendInfoCTC(int aIndex, int Type);
	void CGPacketCTC(XULY_CGPACKET* aRecv, int aIndex);
	void CapNhatTimeCTC(CAPNHAT_CTC_0H* lpMsg);
	bool Dialog(int aIndex, int aNpcIndex);
	void MonsterDie(LPOBJ Player);
	void SendKillCTC(int aIndex);
	void CheckTimeInCTC(int aIndex);

};
extern cChienTruongCo	gChienTruongCo;
#endif