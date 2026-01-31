#pragma once
#include "Protocol.h"
#include "Interface.h"

struct PMSG_HUYHIEU_RECV
{
	PSBMSG_HEAD	header;
	int huyhieu;
	int dong1;
	int dong2;
	int dong3;
	int dong4;
	int dong5;
};

class HuyHieuCuongHoa
{
public:
	HuyHieuCuongHoa(void);
	~HuyHieuCuongHoa(void);
	void ImageLoad();
	void BinObeject();
	void DrawHuyHieu();
	void DrawChiSo();
	void GCData(PMSG_HUYHIEU_RECV* lpMsg);
	int huyhieu;
	int dong1;
	int dong2;
	int dong3;
	int dong4;
	int dong5;
private:
	//int huyhieu;
	//int dong1;
	//int dong2;
	//int dong3;
	//int dong4;
	//int dong5;
};
extern HuyHieuCuongHoa gHuyHieuCuongHoa;