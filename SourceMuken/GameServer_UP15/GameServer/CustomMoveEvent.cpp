
#include "StdAfx.h"
#include "CustomMoveEvent.h"
#include "GameMain.h"
#include "user.h"
#include "Path.h"
#include "Notice.h"

// -------------------------------------------------------------------------------
CCustomMoveEvent gCustomMoveEvent;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomMoveEvent::CCustomMoveEvent() // OK
{

}

CCustomMoveEvent::~CCustomMoveEvent() // OK
{

}


void CCustomMoveEvent::MOVE_EVENT(LPOBJ lpUser, MOVE_EVENT_REQ *lpMsg, int aIndex)
{
	//char sTmp[100] = { 0 };
	//char sTmpAll[1024] = { '\0' };
	//----------------------------------------------------------------------------
	/*for(int RevMove = 1; RevMove <= 41; RevMove++)
	{*/

	switch (lpMsg->MOVE_EVENT)
	{
	case  1:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case  2:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case  3:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case  4:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case  5:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case  6:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case  7:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case  8:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case  9:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 10:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 11:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 12:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 13:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 14:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 15:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 16:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 17:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 18:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 19:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 20:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 21:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 22:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 23:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 24:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 25:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 26:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 27:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 28:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 29:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 30:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 31:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 32:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 33:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 34:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 35:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 36:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 37:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 38:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 39:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 40:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	case 41:gObjMoveGate(aIndex, 799 + lpMsg->MOVE_EVENT);/*gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d | %d",aIndex, 799 +lpMsg->MOVE_EVENT);*/ break;
	}

	//	 if (lpMsg->MOVE_EVENT == 1) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799 +lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 2) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 3) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 4) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 5) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 6) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 7) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 8) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 9) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 10) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 11) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 12) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 13) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 14) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 15) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 16) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 17) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 18) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 19) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 20) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 21) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 22) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 23) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 24) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 25) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 26) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 27) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 28) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 29) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 30) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 31) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 32) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 33) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 34) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 35) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 36) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 37) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 38) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 39) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 40) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}
	//else if (lpMsg->MOVE_EVENT == 41) {/*gObjMoveGate(aIndex,799 + lpMsg->MOVE_EVENT);*/gNotice.GCNoticeSend(aIndex,1,0,0,0,0,0,"%d",799+lpMsg->MOVE_EVENT);}


	//}



	////----------------------------------------------------------------------------
	//else if (aRecv->EXBEXO_BUG_MOVE_EVENT == 2) //-> 
	//{
	//	gObjMoveGate(aIndex, 374);
	//	if (ElfCheat.THONG_BAO_MOVE_EVENT_02_SEND == 0)
	//	{
	//		return;
	//	}
	//	// Thong Bao All Server
	//	wsprintf(sTmpAll, &ElfCheat.THONG_BAO_MOVE_EVENT_02[0], lpUser->Name);
	//	AllSendServerMsg(sTmpAll);
	//}
	////----------------------------------------------------------------------------
	//else if (aRecv->EXBEXO_BUG_MOVE_EVENT == 3) //-> 
	//{
	//	gObjMoveGate(aIndex, 375);

	//	if (ElfCheat.THONG_BAO_MOVE_EVENT_03_SEND == 0)
	//	{
	//		return;
	//	}
	//	// Thong Bao All Server
	//	wsprintf(sTmpAll, &ElfCheat.THONG_BAO_MOVE_EVENT_03[0], lpUser->Name);
	//	AllSendServerMsg(sTmpAll);

	//}
	////----------------------------------------------------------------------------
	//else if (aRecv->EXBEXO_BUG_MOVE_EVENT == 4) //-> Rakion
	//{
	//	gObjMoveGate(aIndex, 376);

	//	if (ElfCheat.THONG_BAO_MOVE_EVENT_04_SEND == 0)
	//	{
	//		return;
	//	}
	//	// Thong Bao All Server
	//	wsprintf(sTmpAll, &ElfCheat.THONG_BAO_MOVE_EVENT_04[0], lpUser->Name);
	//	AllSendServerMsg(sTmpAll);

	//}
	////----------------------------------------------------------------------------
	//else if (aRecv->EXBEXO_BUG_MOVE_EVENT == 5) //->a
	//{
	//	gObjMoveGate(aIndex, 377);

	//	if (ElfCheat.THONG_BAO_MOVE_EVENT_05_SEND == 0)
	//	{
	//		return;
	//	}
	//	// Thong Bao All Server
	//	wsprintf(sTmpAll, &ElfCheat.THONG_BAO_MOVE_EVENT_05[0], lpUser->Name);
	//	AllSendServerMsg(sTmpAll);

	//}
	////----------------------------------------------------------------------------
	//else if (aRecv->EXBEXO_BUG_MOVE_EVENT == 6) //-> 
	//{
	//	gObjMoveGate(aIndex, 378);

	//	if (ElfCheat.THONG_BAO_MOVE_EVENT_06_SEND == 0)
	//	{
	//		return;
	//	}
	//	// Thong Bao All Server
	//	wsprintf(sTmpAll, &ElfCheat.THONG_BAO_MOVE_EVENT_06[0], lpUser->Name);
	//	AllSendServerMsg(sTmpAll);

	//}
	////----------------------------------------------------------------------------
	//else if (aRecv->EXBEXO_BUG_MOVE_EVENT == 7) //-> 
	//{
	//	gObjMoveGate(aIndex, 379);

	//	if (ElfCheat.THONG_BAO_MOVE_EVENT_07_SEND == 0)
	//	{
	//		return;
	//	}
	//	// Thong Bao All Server
	//	wsprintf(sTmpAll, &ElfCheat.THONG_BAO_MOVE_EVENT_07[0], lpUser->Name);
	//	AllSendServerMsg(sTmpAll);

	//}
	////----------------------------------------------------------------------------
	//else if (aRecv->EXBEXO_BUG_MOVE_EVENT == 10) //-> 
	//{
	//	gObjMoveGate(aIndex, 380);

	//	if (ElfCheat.THONG_BAO_MOVE_EVENT_08_SEND == 0)
	//	{
	//		return;
	//	}
	//	// Thong Bao All Server
	//	wsprintf(sTmpAll, &ElfCheat.THONG_BAO_MOVE_EVENT_08[0], lpUser->Name);
	//	AllSendServerMsg(sTmpAll);

	//}
	////----------------------------------------------------------------------------
	//else if (aRecv->EXBEXO_BUG_MOVE_EVENT == 11) //-> 
	//{
	//	gObjMoveGate(aIndex, 381);

	//	if (ElfCheat.THONG_BAO_MOVE_EVENT_09_SEND == 0)
	//	{
	//		return;
	//	}
	//	// Thong Bao All Server
	//	wsprintf(sTmpAll, &ElfCheat.THONG_BAO_MOVE_EVENT_09[0], lpUser->Name);
	//	AllSendServerMsg(sTmpAll);

	//}
	////----------------------------------------------------------------------------
	//else if (aRecv->EXBEXO_BUG_MOVE_EVENT == 12) //-> 
	//{
	//	gObjMoveGate(aIndex, 382);

	//	if (ElfCheat.THONG_BAO_MOVE_EVENT_10_SEND == 0)
	//	{
	//		return;
	//	}
	//	// Thong Bao All Server
	//	wsprintf(sTmpAll, &ElfCheat.THONG_BAO_MOVE_EVENT_10[0], lpUser->Name);
	//	AllSendServerMsg(sTmpAll);

	//}
	////----------------------------------------------------------------------------
	//else if (aRecv->EXBEXO_BUG_MOVE_EVENT == 13) //-> Boss BraveKnight
	//{
	//	gObjMoveGate(aIndex, 384);

	//	if (ElfCheat.THONG_BAO_MOVE_EVENT_11_SEND == 0)
	//	{
	//		return;
	//	}
	//	// Thong Bao All Server
	//	wsprintf(sTmpAll, &ElfCheat.THONG_BAO_MOVE_EVENT_11[0], lpUser->Name);
	//	AllSendServerMsg(sTmpAll);

	//}
	////----------------------------------------------------------------------------
	//else if (aRecv->EXBEXO_BUG_MOVE_EVENT == 14) //-> Boss BoxFly
	//{
	//	gObjMoveGate(aIndex, 385);

	//	if (ElfCheat.THONG_BAO_MOVE_EVENT_12_SEND == 0)
	//	{
	//		return;
	//	}
	//	// Thong Bao All Server
	//	wsprintf(sTmpAll, &ElfCheat.THONG_BAO_MOVE_EVENT_12[0], lpUser->Name);
	//	AllSendServerMsg(sTmpAll);

	//}
	////----------------------------------------------------------------------------
	//else if (aRecv->EXBEXO_BUG_MOVE_EVENT == 15) //-> 
	//{
	//	gObjMoveGate(aIndex, 386);
	//	if (ElfCheat.THONG_BAO_MOVE_EVENT_13_SEND == 0)
	//	{
	//		return;
	//	}
	//	// Thong Bao All Server
	//	wsprintf(sTmpAll, &ElfCheat.THONG_BAO_MOVE_EVENT_13[0], lpUser->Name);
	//	AllSendServerMsg(sTmpAll);

	//}
	////----------------------------------------------------------------------------
}
//==============================================================================================================================================