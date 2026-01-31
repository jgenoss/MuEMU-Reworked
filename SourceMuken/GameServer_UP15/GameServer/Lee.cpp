#include "StdAfx.h"
#include "Lee.h"
#include "Notice.h"
#include "CommandManager.h"
#include "Util.h"
#include "Log.h"
#include "DSProtocol.h"
#include "GameMain.h"
#include "ServerInfo.h"

Lee gLee;


Lee::Lee()
{
}

Lee::~Lee()
{
}
void Lee::ReqHackRequest(LPOBJ lpObj, REQUEST_HACK_REQ* aRecv)
{
	if (gObjIsConnectedGP(lpObj->Index) == 0)
	{
		return;
	}
	int SoLanSuDung = 0;
	//DU LIEU GUI VE NEU SO DUOC GUI > 0
	if (aRecv->Number > 0)
	{
		//THONG BAO TREN GS
		LogAdd(LOG_RED, "[HDC-Antihack] Phát hiện nghi vấn hack Tài Khoản %s-%s | %d |Hack Type : %d", lpObj->Account, lpObj->Name, aRecv->Number);
		//GHI LOG RA FILE TEXT
		gLog.Output(LOG_HACK, "[HDC-Antihack] [%s][%s] - Hack Type : %d | So lan hack == %d", lpObj->Account, lpObj->Name, aRecv->Number, SoLanSuDung);
		//SO LAN SU DUNG DC CONG DON LEN
		SoLanSuDung++;
		//NEU SO LAN NO HACK VUOT QUA 2(CO THE TAO CONFIG O DAY - CÓ THỂ TÙY CHỈNH CHO NÓ BẬT HACK 2 3 LẦN LÀ XỬ LÝ - 1 LẦN HƠI NGHIÊM)
		if (SoLanSuDung > 2)
		{
			//KHOA NHAN VAT DUOI LENH BLOCK
			SDHP_COMMAND_BLOC_SEND pMsg;
			pMsg.header.set(0x0F, 0x06, sizeof(pMsg));
			pMsg.index = lpObj->Index;
			//SO NGAY BI KHOA
			pMsg.days = 999;
			memcpy(pMsg.namebloc, lpObj->Name, sizeof(pMsg.namebloc));
			gDataServerConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
			//NEW SU DUNG HACK MA CLIENT KO XU LY
			//GS XU LY (KILL NHAN VAT RA KHOI SERVER)
			gObjUserKill(lpObj->Index);
			//LUU LOG  XU LY NHAN VAT VAO FILE TEXT
			gLog.Output(LOG_HACK, "[HDC-Antihack] [%s][%s] - Hack Type : %d | So lan hack == %d", lpObj->Account, lpObj->Name, aRecv->Number, SoLanSuDung);
		}
	}



}
