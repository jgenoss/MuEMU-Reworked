#pragma once
#include "StdAfx.h"
#include "DSProtocol.h"
#include "User.h"


struct CUSTOM_SKIN_CONFIG
{
	int     Enable;
	int		Firework;
	int			Notice;
	char		Msg[90];

};

struct SKIN_MODEL_DATA
{
	int Index;
	int SkinIndex;
	int Coin;
	int ValueOp[4];
	char NameSkin[90];
};

struct CUSTOM_SKIN_MESSAGE
{
	int Index;
	char Message[256];
};

//===Send List Cho Client
struct BPMSG_CUSTOM_SKIN_SEND
{
	PSWMSG_HEAD header;
	int count;
};
struct BCUSTOM_SKINMODEL_DATA
{
	int SkinIndex;
	int StatusBuy;
};
struct GSSENDDS_GETLISTISBUYSKIN
{
	PSBMSG_HEAD header;
	char AccountID[11];
	int aIndex;
};

struct CUSTOM_MENU_HOATDONG
{
	int IDIndex;
	char ButtonName[90];
};
class BCustomSkinModel
{
public:
	void Load(char* FilePath);
	CUSTOM_SKIN_CONFIG* m_Config;
	std::vector<CUSTOM_MENU_HOATDONG> m_MenuHoatDong;
	std::vector<SKIN_MODEL_DATA> m_SkinModelData;
	SKIN_MODEL_DATA* GetInfoSkinModel(int SkinIndex);
	bool UpdateListSkinBuy(int aIndex, int SkinIndex);

	void GDGetListBuy(int Index);
	void CGListSkinModelSend(int Index);
	void CGGetInfoSelectSkin(int Index, int SkinIndex);
	bool CheckSkinIsBuy(int Index, int SkinIndex);
	void RecvGDGetListBuy(CBCUSTOM_LOAD_COUNT* lpMsg);
	void GDSaveSkinBuy(int aIndex, int SkinIndex);
	void RecvActionSkin(int aIndex, int SkinIndexAction);
	void ActiveBonusSkin(LPOBJ lpObj, bool flag);
	int  GetCBSkinChange(int aIndex);
private:
	//===Mess
	std::map<int, CUSTOM_SKIN_MESSAGE> m_MessageInfoBP;
	char* GetMessage(int index);

};

extern BCustomSkinModel gBCustomSkinModel;


