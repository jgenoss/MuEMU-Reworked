#include "user.h"
#include "Protocol.h"


#if (SACHTHUOCTINH_NEW == 1)

struct SACHTHUOCTINH_GD_SAVE_DATA
{
	PSBMSG_HEAD header;
	// ----
	WORD	index;
	char	Name[11];
	int SACHTHUOCTINH_01;
	int SACHTHUOCTINH_02;
	int SACHTHUOCTINH_03;
	int SACHTHUOCTINH_04;
	int SACHTHUOCTINH_05;
	int SACHTHUOCTINH_06;
	int SACHTHUOCTINH_07;
};

// -------------------------------------------------------------------------------
struct SACHTHUOCTINH_GD_REQ_DATA
{
	PSBMSG_HEAD	header;
	WORD index;
	char name[11];
};
// -------------------------------------------------------------------------------


struct SACHTHUOCTINH_DG_GET_DATA
{
	PSBMSG_HEAD	header;
	// ----
	WORD	index;
	int SACHTHUOCTINH_01;
	int SACHTHUOCTINH_02;
	int SACHTHUOCTINH_03;
	int SACHTHUOCTINH_04;
	int SACHTHUOCTINH_05;
	int SACHTHUOCTINH_06;
	int SACHTHUOCTINH_07;
};

// -------------------------------------------------------------------------------
struct SACHTHUOCTINH_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};

//  ------------------------------------------------------------------------------


struct STATS_SACHTHUOCTINH_DATA
{
	char MSG_10[1024];
};

struct PMSG_STATS_SACHTHUOCTINH
{
	PSBMSG_HEAD h;
	BYTE Result;
	STATS_SACHTHUOCTINH_DATA StatInfo;
};


class SachThuocTinh
{
public:
	// ----
	SachThuocTinh();
	virtual ~SachThuocTinh();

	void	    Load();

	void		GDSaveData(int aIndex);
	void		GDReqData(int aIndex);
	void		GDSaveUserInfo(int aIndex);
	void		GDReqUserInfo(int aIndex);
	void		DGGetData(SACHTHUOCTINH_DG_GET_DATA * aRecv);

	void		Option(LPOBJ lpObj, bool flag);
	void		BUG_SACHTHUOCTINH(LPOBJ lpObj, SACHTHUOCTINH_REQ *aRecv);
	// ----
	int MAX_THUOC_TINH_02;
	int MAX_THUOC_TINH_03;
	int MAX_THUOC_TINH_04;
	int MAX_THUOC_TINH_05;
	int MAX_THUOC_TINH_06;
	int MAX_THUOC_TINH_07;

	int OPTION_LEVEL_01;
	int OPTION_LEVEL_02;
	int OPTION_LEVEL_03;
	int OPTION_LEVEL_04;
	int OPTION_LEVEL_05;
	int OPTION_LEVEL_06;
	int OPTION_LEVEL_07;
	int OPTION_LEVEL_08;
	int OPTION_LEVEL_09;
	int OPTION_LEVEL_10;
	int OPTION_LEVEL_11;
	int OPTION_LEVEL_12;

	int OPTION_ACTIVE_01;
	int OPTION_ACTIVE_02;
	int OPTION_ACTIVE_03;
	int OPTION_ACTIVE_04;
	int OPTION_ACTIVE_05;
	int OPTION_ACTIVE_06;
	int OPTION_ACTIVE_07;
	int OPTION_ACTIVE_08;
	int OPTION_ACTIVE_09;
	int OPTION_ACTIVE_10;
	int OPTION_ACTIVE_11;
	int OPTION_ACTIVE_12;


	char MSG_01[1024];
	char MSG_02[1024];

	char MSG_10[1024];
	// ----
	SACHTHUOCTINH_GD_REQ_DATA SACHTHUOCTINH;
	// ----

private:

}; extern SachThuocTinh gSachThuocTinh;

#endif
// -------------------------------------------------------------------------------


