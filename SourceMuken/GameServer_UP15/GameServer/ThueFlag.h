#include "stdafx.h"
#if(FLAG_SKIN)
#include "Protocol.h"

struct THUE_FLAG_DATA
{
	int		Id;
	int		Skin;
	int		Price;
	int		Value1;
	int		Value2;
	int		Value3;
	int		Value4;
	int		Value5;
	int		Value6;
	int		Value7;
};

struct PMSG_THUE_FLAG_RECV
{
	PBMSG_HEAD2_Origin h;
	BYTE Type;
	int  Value;
};

struct PMSG_THUE_FLAG_SEND
{
	PBMSG_HEAD2_Origin h;
	int				Skin;
	THUE_FLAG_DATA	Data;
};

class cThueFlag
{
public:
	cThueFlag();
	~cThueFlag();
	void Read(char* path);
	void CGRequestRecv(BYTE* a, int aIndex);
	void GCInfoSend(int a, int aIndex, bool changeskin = true);
	void BuyProc(int a, int aIndex);
	void SkinState(bool state, int aIndex);
	void OnLogin(int aIndex);
	void CharacterCalc(int aIndex, bool flag);
	THUE_FLAG_DATA* FindSkin(int id);
	std::vector<THUE_FLAG_DATA> m_Data;
private:
	
};

extern cThueFlag ThueFlag;
#endif