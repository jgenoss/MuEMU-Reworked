#pragma once
#include "Protocol.h"
#include "Interface.h"

struct PMSG_VUKHIRONG_RECV
{
	PSBMSG_HEAD	header;
	int vukhirong;
	int dong1;
	int dong2;
	int dong3;
};

class VuKhiRong
{
public:
	VuKhiRong(void);
	~VuKhiRong(void);
	void ImageLoad();
	void BinObeject();
	void DrawHuyHieu();
	void DrawChiSo();
	void GCData(PMSG_VUKHIRONG_RECV* lpMsg);
	int vukhirong;
	int dong1;
	int dong2;
	int dong3;
private:
};
extern VuKhiRong gVuKhiRong;