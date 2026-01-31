// ---
#if (GHRS_TOP1_NEW)

#include "Protocol.h"
#include <WinDef.h>

//**********************************************//
//********** GameServer -> DataServer **********//
//**********************************************//
struct SDHP_CUSTOM_GHRS_SEND
{
	PBMSG_HEAD header;
	int time;
};

//**********************************************//
//********** DataServer -> GameServer **********//
//**********************************************//
struct SDHP_CUSTOM_GHRS_RECV
{
	PWMSG_HEAD header;
	int time;
	int resets;
	int Grand;
};

// ---
class CCustomGHRS
{
public:
	CCustomGHRS();
	~CCustomGHRS();
	void Load(char* path);
	// ---
	void GDCustomGHRSRecv(SDHP_CUSTOM_GHRS_RECV* lpMsg);
	void GDCustomGHRSReq();
	bool Compare(int H, int M, int S);
	int  maxResets;
	int	  GHRS_Relife;
	DWORD Day;
	bool serverStart;

	int  m_MocRelife1;
	int  m_PointRelife1;
	int GHRSTOP;
	int GHRSPLUS;
private:
	int m_count;
	DWORD GHRS_WEEK[7];
	DWORD Update_Hour;
	DWORD Update_Min;
	DWORD Update_Sec;

	// ---
};
extern CCustomGHRS gCustomGHRS;
// ---
#endif