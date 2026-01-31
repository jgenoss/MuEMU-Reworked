#pragma once
#include "Protocol.h"
#include "Interface.h"

struct PMSG_CUONGHOAWING_RECV
{
	PSBMSG_HEAD	header;
	int cuonghoawing;
	int dong1;
	int dong2;
	int dong3;
	int dong4;
	int dong5;
};

class CuongHoaWing
{
public:
	CuongHoaWing(void);
	~CuongHoaWing(void);
	void ImageLoad();
	void BinObeject();
	void DrawHuyHieu();
	void DrawChiSo();
	void GCData(PMSG_CUONGHOAWING_RECV* lpMsg);
	int cuonghoawing;
	int dong1;
	int dong2;
	int dong3;
	int dong4;
	int dong5;
private:
};
extern CuongHoaWing gCuongHoaWing;