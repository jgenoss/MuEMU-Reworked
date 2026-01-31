#include "StdAfx.h"
#include "PartyBar.h"
#include "Import.h"
#include "Util.h"
#include "Offset.h"
#include "Defines.h"
#include "PartyBuffs.h"

PartyBar10 QTPary;
int eventillo;

PartyBar10::PartyBar10()
{
	this->PartyMemberCount = 0;

	this->ClickTick = 0;
	this->OnClick = -1;
	this->OnClickD = -1;
	this->Page = 0;
	this->PartyShow = true;

	ZeroMemory(&this->JCPartyDB, sizeof(JCPartyDB));
	ZeroMemory(&this->LifePercent, sizeof(LifePercent));
	ZeroMemory(&this->ViewportID, sizeof(ViewportID));
}


PartyBar10::~PartyBar10()
{
}


void PartyBar10::JCGCPartyListAll(LPBYTE aRecv)
{
	signed int i; // [sp+8h] [bp-Ch]@1
	int datasize = 0; // [sp+10h] [bp-4h]@1
	char * v2; // ST10_4@3

	PMSG_PARTYLISTCOUNT pCount;
	memcpy(&pCount, &aRecv[datasize], sizeof(pCount));

	QTPary.PartyMemberCount = pCount.Count;

	datasize = 5;

	for (i = 0; i < QTPary.PartyMemberCount; ++i)
	{
		PMSG_PARTYLIST pList;
		memcpy(&pList, &aRecv[datasize], sizeof(pList));

		strncpy(QTPary.JCPartyDB[i].Name, pList.szId, 10);
		QTPary.JCPartyDB[i].Unknown10 = 0;
		QTPary.JCPartyDB[i].Unknown11 = pList.Number;
		QTPary.JCPartyDB[i].MapNumber = pList.MapNumber;
		QTPary.JCPartyDB[i].PosX = pList.X;
		QTPary.JCPartyDB[i].PosY = pList.Y;
		QTPary.JCPartyDB[i].Life = pList.Life;
		QTPary.JCPartyDB[i].MaxLife = pList.MaxLife;
		//--
		datasize += 24;
	}
}


int PartyBar10::PartyMemberLifeRecv(LPBYTE aRecv)
{
	int datasize = 0;
	char v2;
	char v3;
	signed int v4;
	char v5;
	PMSG_DEFAULT_COUNT pCount;
	memcpy(&pCount, &aRecv[datasize], sizeof(pCount));
	datasize = 4;
	int result = pCount.Count;

	for (int i = 0; i < result; ++i)
	{
		PMSG_PARTYLIFEALL pList;
		memcpy(&pList, &aRecv[datasize], sizeof(pList));

		v5 = pList.Number & 0xF;
		if (v5 >= 0)
			v4 = v5;
		else
			v4 = 0;
		if (v4 <= 10)
		{
			if (v5 >= 0)
				v2 = pList.Number & 0xF;
			else
				v2 = 0;
			v3 = v2;
		}
		else
		{
			v3 = 10;
		}

		QTPary.JCPartyDB[i].LifePercent = v3;
		datasize++;
	}
	return result;
}

int PartyBar10::JCPartStructID()
{
	int v49; // [sp+74h] [bp-10h]@18
	signed int v20; // [sp-4h] [bp-88h]@21
	signed int v24; // [sp+10h] [bp-74h]@75
	signed int v27; // [sp+1Ch] [bp-68h]@33
	int v6; // esi@59

	for (int i = 0; i<this->PartyMemberCount; i++)
	{
		this->LifePercent[32 * i] = this->JCPartyDB[i].LifePercent;
		this->ViewportID[8 * i] = this->JCPartyDB[i].ViewportID;
		this->JCPartyDB[i].ViewportID = -2;
	}

	for (int i = 0; i < 400; ++i)
	{
		int v12 = pGetPreviewStruct(pPreviewThis(), i);
		if (*(DWORD *)(v12 + 824) == 1163 && *(BYTE *)(v12 + 800) == 1
			&& *(BYTE *)(v12 + 780) && *(BYTE *)(v12 + 788)
			&& *(float *)(v12 + 928) > 0.0 && !*(BYTE *)(v12 + 36))
		{
			for (int j = 0; j < this->PartyMemberCount; j++)
			{
				int v10 = (int)&this->JCPartyDB[j];
				if (this->JCPartyDB[j].ViewportID == -2 && this->JCPartyDB[j].ViewportID <= -1)
				{
					unsigned int v7 = sub_9CF130(v12 + 56) >= 1 ? sub_9CF130(v12 + 56) : 1;
					if (sub_9CF130(v10) <= v7)
					{
						int v5 = sub_9CF130(v12 + 56) >= 1 ? sub_9CF130(v12 + 56) : 1;
						v6 = v5;
					}
					else
					{
						v6 = sub_9CF130(v10);
					}
					lpViewObj lpUser = &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), i);
					PartyUser* lpParty = &this->JCPartyDB[j];
					if (!this->FilterPartyNumberEx(lpParty, lpUser->Name, v6))
					{
						this->JCPartyDB[j].ViewportID = i;
						break;
					}
				}
			}
		}
		v49 = i + 1;
	}

	for (int k = 0; k < this->PartyMemberCount; k++)
	{
		int v8 = (int)&this->JCPartyDB[k];
		if (this->JCPartyDB[k].ViewportID < 0)
		{
			if (sub_9CF130(LODWORD(oUserPreviewStruct) + 56) >= 1)
				v27 = sub_9CF130(LODWORD(oUserPreviewStruct) + 56);
			else
				v27 = 1;
			if (sub_9CF130(v8) <= (unsigned int)v27)
			{
				if (sub_9CF130(LODWORD(oUserPreviewStruct) + 56) >= 1)
					v20 = sub_9CF130(LODWORD(oUserPreviewStruct) + 56);
				else
					v20 = 1;
				v24 = v20;
			}
			else
			{
				v24 = sub_9CF130(v8);
			}

			PartyUser* JCPartStruct = &this->JCPartyDB[k];

			v49 = this->FilterPartyNumberEx(JCPartStruct, (char *)(*(DWORD *)0x7BC4F04 + 56), v24);
			if (v49)
				this->JCPartyDB[k].ViewportID = -1;
			else
				this->JCPartyDB[k].ViewportID = -3;
		}
	}

	return v49;
}

void DeletObjParty(int member)
{
	PlayBuffer(25, 0, 0);
	PMSG_PARTYDELUSER pRequest;
	pRequest.h.set(0x43, sizeof(pRequest));
	pRequest.Number = QTPary.JCPartyDB[member].Unknown11;
	DataSend((LPBYTE)&pRequest, pRequest.h.size);
}

void PartyBar10::GetCoordPanelD(int a1, float a2, float a3, float a4, float a5)
{
	float y; // ST10_4@1
	float x; // ST0C_4@1
	int v58; // [sp+20h] [bp-18h]@1
	char v59; // [sp+2Bh] [bp-Dh]@4

	v58 = *(DWORD *)(GetInstance() + 100);

	pDrawGUI(a1, a2, a3, a4, a5);

	y = (double)*(signed int *)(v58 + 20) + 123;
	x = (double)*(signed int *)(v58 + 16) - 10;

	pDrawGUI(0x7BAA, x + 70, y + 275, 16, 20);

	if (pCheckMouseOver(x + 70, y + 275, 16, 20))
	{
		pDrawColorButton(0x7BAA, x + 70, y + 275, 16, 20, 0, 0, pMakeColor(255, 204, 20, 130));

		if (*(BYTE*)0x8793386 && GetTickCount() >= QTPary.OnClickD + 300)
		{
			QTPary.Page = 0;
			QTPary.OnClickD = GetTickCount();
		}
	}

	pDrawGUI(0x7BAB, x + 133, y + 275, 16, 20);

	if (pCheckMouseOver(x + 133, y + 275, 16, 20))
	{
		pDrawColorButton(0x7BAB, x + 133, y + 275, 16, 20, 0, 0, pMakeColor(255, 204, 20, 130));
		if (*(BYTE*)0x8793386 && GetTickCount() >= QTPary.OnClickD + 300)
		{
			QTPary.Page = (QTPary.PartyMemberCount > 5) ? 1 : 0;
			QTPary.OnClickD = GetTickCount();
		}
	}
}

void PartyBar10::DrawPanelD()
{
	int v58; // [sp+20h] [bp-18h]@1
	char v59; // [sp+2Bh] [bp-Dh]@4

	v58 = *(DWORD *)(GetInstance() + 100);

	for (int i = 0; i < QTPary.PartyMemberCount; i++)
	{
		if (i < 5 && QTPary.Page == 0)
		{
			v59 = 0;
			if (!strcmp(QTPary.JCPartyDB[0].Name, (char *)(*(DWORD *)0x7BC4F04 + 56))
				|| !strcmp(QTPary.JCPartyDB[i].Name, (char *)(*(DWORD *)0x7BC4F04 + 56)))
			{
				v59 = 1;
			}

			sub_84AD10(v58, i, (int)&QTPary.JCPartyDB[i], v59);

			if (pCheckMouseOver(*(DWORD *)(v58 + 16) + 159, *(DWORD *)(v58 + 20) + 71 * i + 63, 11, 11))
			{
				if (*(BYTE*)0x8793386 && GetTickCount() >= eventillo + 300)
				{
					eventillo = GetTickCount();
					DeletObjParty(i);
				}
			}
		}
		else if (i >= 5 && QTPary.Page == 1)
		{
			v59 = 1;
			sub_84AD10(v58, i - 5, (int)&QTPary.JCPartyDB[i], v59);

			if (pCheckMouseOver(*(DWORD *)(v58 + 16) + 159, *(DWORD *)(v58 + 20) + 71 * (i - 5) + 63, 11, 11))
			{
				if (*(BYTE*)0x8793386 && GetTickCount() >= eventillo + 300)
				{
					eventillo = GetTickCount();
					DeletObjParty(i);
				}
			}
		}
	}
}


int PartyBar10::FilterPartyNumber(int a1, int a2, unsigned int a3)
{
	int result;
	int v4;
	int v5;
	char v6;
	char v7;
	char v8;
	char v9;
	int v10;
	int v11;
	unsigned int v12;

	char v13;
	char v14;
	char v15;
	char v16;
	char v17;

	v12 = 0;
	if (a3)
	{
		if (a3 < 9 || a3 == 9)
		{
			v4 = a2;
			v5 = a1;
			goto LABEL_24;
		}
		v4 = a2;
		v5 = a1;
		do
		{
			v13 = *(BYTE *)v5;
			v5 += 9;
			v4 += 9;
			//---
			int  mins = 9;
			if (!v13 || v13 != *(BYTE *)(v4 - mins))
			{
				v10 = *(BYTE *)(v5 - mins);
				v11 = *(BYTE *)(v4 - mins);
				goto LABEL_28;
			}
			v14 = *(BYTE *)(v5 - mins - 1);
			// ---
			mins = 8;
			if (!v14 || v14 != *(BYTE *)(v4 - mins))
			{
				v10 = *(BYTE *)(v5 - mins);
				v11 = *(BYTE *)(v4 - mins);
				goto LABEL_28;
			}
			v15 = *(BYTE *)(v5 - mins - 1);
			// ---
			mins = 7;
			if (!v15 || v15 != *(BYTE *)(v4 - mins))
			{
				v10 = *(BYTE *)(v5 - mins);
				v11 = *(BYTE *)(v4 - mins);
				goto LABEL_28;
			}
			v16 = *(BYTE *)(v5 - mins - 1);
			// ---
			mins = 6;
			if (!v16 || v16 != *(BYTE *)(v4 - mins))
			{
				v10 = *(BYTE *)(v5 - mins);
				v11 = *(BYTE *)(v4 - mins);
				goto LABEL_28;
			}
			v7 = *(BYTE *)(v5 - mins - 1);
			// ---
			mins = 5;
			if (!v13 || v13 != *(BYTE *)(v4 - mins))
			{
				v10 = *(BYTE *)(v5 - mins);
				v11 = *(BYTE *)(v4 - mins);
				goto LABEL_28;
			}
			v13 = *(BYTE *)(v5 - mins - 1);
			// ---
			if (!v6 || v6 != *(BYTE *)(v4 - 4))
			{
				v10 = *(BYTE *)(v5 - 4);
				v11 = *(BYTE *)(v4 - 4);
				goto LABEL_28;
			}
			v17 = *(BYTE *)(v5 - 3);
			if (!v17 || v17 != *(BYTE *)(v4 - 3))
			{
				v10 = *(BYTE *)(v5 - 3);
				v11 = *(BYTE *)(v4 - 3);
				goto LABEL_28;
			}
			v8 = *(BYTE *)(v5 - 2);
			if (!v8 || v8 != *(BYTE *)(v4 - 2))
			{
				v10 = *(BYTE *)(v5 - 2);
				v11 = *(BYTE *)(v4 - 2);
				goto LABEL_28;
			}
			v9 = *(BYTE *)(v5 - 1);
			if (!v9 || v9 != *(BYTE *)(v4 - 1))
			{
				v10 = *(BYTE *)(v5 - 1);
				v11 = *(BYTE *)(v4 - 1);
				goto LABEL_28;
			}
			v12 += 4;
		} while (v12 < a3 - 9);
		while (1)
		{
		LABEL_24:
			if (v12 >= a3)
				return 0;
			if (!*(BYTE *)v5 || *(BYTE *)v5 != *(BYTE *)v4)
				break;
			++v5;
			++v4;
			++v12;
		}
		v10 = *(BYTE *)v5;
		v11 = *(BYTE *)v4;
	LABEL_28:
		result = v10 - v11;
	}
	else
	{
		result = 0;
	}
	return result;
}

int PartyBar10::FilterPartyNumberEx(PartyUser* lpUser, char* Name, unsigned int a3)
{
	if (!strcmp(lpUser->Name, Name))
	{
		return false;
	}

	return true;

}

int PartyBar10::MainPartyVieweID()
{
	return QTPary.JCPartStructID();
}

int PartyBar10::JCGetViewID(unsigned __int8 This)
{
	int v49; // [sp+74h] [bp-10h]@18

	v49 = sub_5B7900(This);

	QTPary.JCPartStructID();

	return v49;
}

char CheckStatusParty(int a1)
{
	char result; // al@2
	int v9; // [sp+0h] [bp-10h]@1
	int i; // [sp+4h] [bp-4h]@3

	v9 = *(DWORD *)(GetInstance() + 104);

	if (QTPary.PartyMemberCount > 0)
	{
		*(BYTE *)(v9 + 917) = 1;
		for (i = 0; i < QTPary.PartyMemberCount; ++i)
			QTPary.JCPartyDB[i].ViewportID = -2;
		result = 1;
	}
	else
	{
		*(BYTE *)(v9 + 917) = 0;
		result = 1;
	}
	return result;
}

char PrintfPartyBar(int a1)
{
	char result; // al@2
	float y; // ST08_4@5
	float x; // ST04_4@5
	signed int v13; // ST18_4@7
	float v39; // ST64_4@25
	signed int v42; // [sp+20h] [bp-50h]@23
	int v43; // [sp+54h] [bp-1Ch]@1
	int v44; // [sp+5Ch] [bp-14h]@7
	int v45; // [sp+68h] [bp-8h]@5
	int i; // [sp+6Ch] [bp-4h]@3

	v43 = *(DWORD *)(GetInstance() + 104);

	if (*(BYTE *)(v43 + 917))
	{
		EnableAlphaTest(1);
		glColor4f(1.0, 1.0, 1.0, 1.0);

		sub_420120(pTextThis(), (int)pFontNormal);
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);

		for (i = 0; i < QTPary.PartyMemberCount; ++i)
		{
			v45 = (30 + 2) * i;

			v13 = QTPary.JCPartyDB[i].ViewportID;

			y = (double)(*(DWORD *)(v43 + 28) + *(DWORD *)(v43 + 20) + v45);
			x = (double)(*(DWORD *)(v43 + 16) + *(DWORD *)(v43 + 24));

			glColor4f(0.0, 0.0, 0.0, 0.89999998);
			pDrawBarForm(x + 2, y + 2, 74.0, 17.0, 0.0, 0);

			EnableAlphaTest(1);
			if (QTPary.JCPartyDB[i].ViewportID == -1)
			{
				glColor4f(0.30000001, 0.0, 0.0, 0.5);
				pDrawBarForm(x, y, 74.0, 17.0, 0.0, 0);
				EnableAlphaTest(1);
			}
			else
			{
				v44 = pGetPreviewStruct(pPreviewThis(), v13);
				if (v44 && pCheckEffectPlayer((DWORD *)(v44 + 1260), 2) == 1)
				{
					glColor4f(0.2, 1.0, 0.2, 0.2);
					pDrawBarForm(x + 2, y + 2, 74.0, 17.0, 0.0, 0);
					EnableAlphaTest(1);
				}
				if (*(DWORD *)(v43 + 924) != -1 && *(DWORD *)(v43 + 924) == i)
				{
					glColor4f(0.40000001, 0.40000001, 0.40000001, 0.69999999);
					pDrawBarForm(x + 2, y + 2, 74.0, 17.0, 0.0, 0);
					EnableAlphaTest(1);
				}
			}
			pGLSupremo();

			pDrawGUI(31557, x, y, 77.0, 23.0);

			if (i)
			{
				if (v13 == -1)
				{
					sub_420080(pTextThis(), pMakeColor(0x80u, 0x80u, 0x80u, 0xFFu));
				}
				else
				{
					sub_420080(pTextThis(), pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
				}


				pDrawText(pTextThis(), (int)x + 4, (int)y + 4, QTPary.JCPartyDB[i].Name, *(DWORD *)(v43 + 932), 0, (LPINT)1, 0);
			}
			else
			{
				if (QTPary.JCPartyDB[0].ViewportID == -1)
				{
					sub_420080(pTextThis(), pMakeColor(0x80u, 0x4Bu, 0xBu, 0xFFu));
				}
				else
				{
					sub_420080(pTextThis(), pMakeColor(0xFFu, 0x94u, 0x16u, 0xFFu));
				}
				pDrawGUI(31553, x + 53, y + 3, 9.0, 10.0);

				pDrawText(pTextThis(), (int)x + 4, (int)y + 4, QTPary.JCPartyDB[0].Name, *(DWORD *)(v43 + 932), 0, (LPINT)1, 0);
			}

			if ((signed int)(unsigned __int8)QTPary.JCPartyDB[i].LifePercent <= 10)
				v42 = (unsigned __int8)QTPary.JCPartyDB[i].LifePercent;
			else
				v42 = 10;
			v39 = (double)v42 / 10.0 * 69.0;

			pDrawGUI(31558, x + 4, y + 16, v39, 3.0);

			if (!strcmp(QTPary.JCPartyDB[0].Name, (char *)(*(DWORD *)0x7BC4F04 + 56))
				|| !strcmp(QTPary.JCPartyDB[i].Name, (char *)(*(DWORD *)0x7BC4F04 + 56)))
			{
				if (pCheckMouseOver(x + 63, y + 3, 11, 11) && *(BYTE*)0x8793386)
				{
					pDrawButton(31554, x + 63, y + 3, 11.0, 11.0, 0.0, 11.0);
				}
				else
				{
					pDrawButton(31554, x + 63, y + 3, 11.0, 11.0, 0.0, 0.0);
				}
			}
			//Vẽ icon buff trên thanh bar
			gPartyBuffs.DrawPartyBuffs((double)x, (double)y + 21.0, QTPary.JCPartyDB[i].Name);
		}
		pGLSwitch();
		result = 1;
	}
	else
	{
		result = 1;
	}
	return result;
}

void ObjPartyDelect(int member)
{

	PlayBuffer(25, 0, 0);
	PMSG_PARTYDELUSER pRequest;
	pRequest.h.set(0x43, sizeof(pRequest));
	pRequest.Number = QTPary.JCPartyDB[member].Unknown11;
	DataSend((LPBYTE)&pRequest, pRequest.h.size);
	QTPary.Page = 0;

}

char sub_84BB30(int a1)
{
	void *v4;
	int v5;
	int v9;
	int v10;
	int v11;
	int i;

	v9 = a1;

	*(DWORD *)(a1 + 924) = -1;

	for (i = 0; i < QTPary.PartyMemberCount; ++i)
	{
		v11 = (30 + 2) * i;//*(DWORD *)(v9 + 920) * i;
		if (!strcmp(QTPary.JCPartyDB[0].Name, (char *)(*(DWORD *)0x7BC4F04 + 56))
			|| !strcmp(QTPary.JCPartyDB[i].Name, (char *)(*(DWORD *)0x7BC4F04 + 56)))
		{
			if (pCheckMouseOver(*(DWORD *)(v9 + 24) + *(DWORD *)(v9 + 16) + 63,
				v11 + *(DWORD *)(v9 + 28) + *(DWORD *)(v9 + 20) + 3,
				11, 11) && *(BYTE*)0x8793386)
			{
				ObjPartyDelect(i);
				return 1;
			}
		}
		if (pCheckMouseOver(
			*(DWORD *)(v9 + 24) + *(DWORD *)(v9 + 16),
			v11 + *(DWORD *)(v9 + 28) + *(DWORD *)(v9 + 20),
			77,
			23))
		{
			*(DWORD *)(v9 + 924) = i;
			if (*(DWORD *)0xE61730 == -1)
			{
				v10 = pGetPreviewStruct(pPreviewThis(), QTPary.JCPartyDB[i].ViewportID);
				if (v10)
				{
					if (v10 != *(DWORD*)0x7BC4F04)
						sub_5996A0(v10 + 56, (const CHAR *)&*(LPVOID*)0xD47C9C, v10, 0, -1);
				}
			}
			if (sub_84C8B0((int)&QTPary.JCPartyDB[i]))
				return 1;
		}
	}
	return 0;
}

//----- (0084BCB0) --------------------------------------------------------
bool GetTargetMember(int a1)
{
	bool result; // al@2
	int v5; // [sp+0h] [bp-8h]@1

	v5 = *(DWORD *)(GetInstance() + 104);

	if (*(BYTE *)(v5 + 917))
	{
		if (sub_84BB30(v5) == 1)
		{
			result = 0;
		}
		else
		{
			result = QTPary.PartyMemberCount <= 0 || !pCheckMouseOver(
				*(DWORD *)(v5 + 24) + *(DWORD *)(v5 + 16),
				*(DWORD *)(v5 + 28) + *(DWORD *)(v5 + 20),
				77, 30 * QTPary.PartyMemberCount);
		}
	}
	else
	{
		result = 1;
	}
	return result;
}

void DeleteButton(int v58, int num, int lpObj)
{
	if (pCheckMouseOver(*(DWORD *)(v58 + 16) + 159, *(DWORD *)(v58 + 20) + 71 * num + 63, 11, 11)
		&& *(BYTE*)0x8793386)
	{
		pDrawButton(31554, *(DWORD *)(v58 + 16) + 159, *(DWORD *)(v58 + 20) + 71 * num + 63, 11.0, 11.0, 0.0, 11.0);
		ObjPartyDelect(lpObj);
		return;
	}
	else
	{
		pDrawButton(31554, *(DWORD *)(v58 + 16) + 159, *(DWORD *)(v58 + 20) + 71 * num + 63, 11.0, 11.0, 0.0, 0.0);
	}
}
void sub_84A4A0()
{
	int v58;
	int num;
	int i;

	v58 = *(DWORD*)(GetInstance() + 100);

	for (i = 0; i < QTPary.PartyMemberCount; i++)
	{
		if (i < 5 && QTPary.Page == 0)
		{
			num = i;
			sub_84AD10(v58, num, (int)&QTPary.JCPartyDB[num], 0);

			if (!strcmp(QTPary.JCPartyDB[0].Name, (char *)(*(DWORD *)0x7BC4F04 + 56))
				|| !strcmp(QTPary.JCPartyDB[i].Name, (char *)(*(DWORD *)0x7BC4F04 + 56)))
			{
				DeleteButton(v58, num, i);
			}
		}
		else if (i > 4 && QTPary.Page == 1)
		{
			num = i - 5;
			sub_84AD10(v58, num, (int)&QTPary.JCPartyDB[i], 0);

			if (!strcmp(QTPary.JCPartyDB[0].Name, (char *)(*(DWORD *)0x7BC4F04 + 56))
				|| !strcmp(QTPary.JCPartyDB[i].Name, (char *)(*(DWORD *)0x7BC4F04 + 56)))
			{
				DeleteButton(v58, num, i);
			}
		}
	}
}

__declspec(naked) void PartyWindows()
{
	static DWORD Addr_JMP = 0x0084A90A;

	sub_84A4A0();

	_asm
	{
		JMP[Addr_JMP]
	}
}

void GetButtonMembers()
{
	float y;
	float x;
	int v58;
	char v59;

	v58 = *(DWORD *)(GetInstance() + 100);
	if (*(BYTE *)(v58 + 1060))
	{
		y = (double)*(signed int *)(v58 + 20) + 123;
		x = (double)*(signed int *)(v58 + 16) - 10;

		pDrawGUI(0x7BAA, x + 70, y + 275, 16, 20);

		if (pCheckMouseOver(x + 70, y + 275, 16, 20))
		{
			pDrawColorButton(0x7BAA, x + 70, y + 275, 16, 20, 0, 0, pMakeColor(255, 204, 20, 130));

			if (*(BYTE*)0x8793386 && GetTickCount() >= QTPary.OnClickD + 300)
			{
				QTPary.Page = 0;
				QTPary.OnClickD = GetTickCount();
			}
		}
		pDrawGUI(0x7BAB, x + 133, y + 275, 16, 20);

		if (pCheckMouseOver(x + 133, y + 275, 16, 20))
		{
			pDrawColorButton(0x7BAB, x + 133, y + 275, 16, 20, 0, 0, pMakeColor(255, 204, 20, 130));
			if (*(BYTE*)0x8793386 && GetTickCount() >= QTPary.OnClickD + 300)
			{
				QTPary.Page = (QTPary.PartyMemberCount > 5) ? 1 : 0;
				QTPary.OnClickD = GetTickCount();
			}
		}
	}
	pGLSwitch();
}

void PartyBar10::Load()
{
	SetCompleteHook(0xE8, 0x0084A91A, &GetButtonMembers);
	SetCompleteHook(0xE9, 0x0084A6D7, &PartyWindows);
	//--
	SetCompleteHook(0xE9, 0x0084BCB0, &GetTargetMember);
	SetCompleteHook(0xE9, 0x0084BDB0, &PrintfPartyBar);
	SetCompleteHook(0xE9, 0x0084BD50, &CheckStatusParty);
	//--
	SetCompleteHook(0xE8, 0x00664568, this->JCGCPartyListAll);
	SetOp(0x0066458A, this->PartyMemberLifeRecv, ASM::CALL);
	//--
	DWORD PartyMemberDB = (DWORD)&this->JCPartyDB;
	SendPacked((LPVOID)0x0051C629, &PartyMemberDB, 0x81, 0xC2);
	SendPacked((LPVOID)0x0078F28A, &PartyMemberDB, 0x68);
	//--
	DWORD AddressLifePercent = (DWORD)&this->LifePercent;
	SendPacked((LPVOID)0x0095FED9, &AddressLifePercent, 0x0F, 0xB6, 0x89);
	//--
	DWORD AddressViewportID = (DWORD)&this->ViewportID;
	SendPacked((LPVOID)0x0095FF91, &AddressViewportID, 0x8B, 0x91); 
	//--
	DWORD AddressPartyMemberCount = (DWORD)&this->PartyMemberCount;
	SendPacked((LPVOID)0x0095E6B7, &AddressPartyMemberCount, 0x83, 0x3D); 
	SendPacked((LPVOID)0x0095E70D, &AddressPartyMemberCount, 0x83, 0x05); 
	SendPacked((LPVOID)0x0095FE98, &AddressPartyMemberCount, 0x3B, 0x05); 
	SendPacked((LPVOID)0x0095FF7F, &AddressPartyMemberCount, 0x3B, 0x05); 
	//--
	SendPacked((LPVOID)0x0051C61B, &AddressPartyMemberCount, 0x3B, 0x0D); 
	SendPacked((LPVOID)0x0064E2CC, &AddressPartyMemberCount, 0xC7, 0x05); 
	SendPacked((LPVOID)0x005C60CB, &AddressPartyMemberCount, 0x83, 0x3D); 
	SendPacked((LPVOID)0x00814033, &AddressPartyMemberCount, 0x83, 0x3D); 
	SendPacked((LPVOID)0x005AD1B2, &AddressPartyMemberCount, 0x83, 0x3D); 
	SendPacked((LPVOID)0x0078F274, &AddressPartyMemberCount, 0x83, 0x3D); 
	SendPacked((LPVOID)0x0084BA51, &AddressPartyMemberCount, 0x0F, 0xAF, 0x0D);
	SendPacked((LPVOID)0x0084A47B, &AddressPartyMemberCount, 0x83, 0x3D);
	//--
	SetCompleteHook(0xE8, 0x005B8395, this->JCGetViewID);
	SetCompleteHook(0xE8, 0x005B83AD, this->JCGetViewID);
	SetCompleteHook(0xE8, 0x005B83C5, this->JCGetViewID);
	SetCompleteHook(0xE8, 0x005B84EB, this->JCGetViewID);
	SetCompleteHook(0xE8, 0x005B8506, this->JCGetViewID);
	SetCompleteHook(0xE8, 0x005B851E, this->JCGetViewID);
	//--
	SetCompleteHook(0xE8, 0x005B83EE, this->MainPartyVieweID);
	SetCompleteHook(0xE8, 0x005B84D3, this->MainPartyVieweID);
	SetCompleteHook(0xE8, 0x005B856C, this->MainPartyVieweID);
	SetCompleteHook(0xE8, 0x005B857A, this->MainPartyVieweID);
}