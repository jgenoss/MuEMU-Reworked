#include "StdAfx.h"
#if(FLAG_SKIN)
#include "ThueFlag.h"
#include "Import.h"
#include "Interface.h"
#include "CustomFont.h"
#include "Character.h"
#include "Util.h"
#include "TMemory.h"
#include "Defines.h"

cThueFlag ThueFlag;

cThueFlag::cThueFlag()
{
	this->Init();
}


cThueFlag::~cThueFlag()
{
}
void cThueFlag::SetRect(float a1, float a2, float a3, float a4)
{
	this->x = a1;
	this->y = a2;
	this->w = a3;
	this->h = a4;
}
bool cThueFlag::CheckRect()
{
	return this->Drawing && gInterface.IsWorkZone4(x, y, w, h);
	return gInterface.Data[eMAIN_ThueFlag].OnShow=true && gInterface.IsWorkZone4(x, y, w, h);
}



void cThueFlag::Bind()
{
	gInterface.BindObject(eMAIN_ThueFlag, 0x7A5A, 445, 364, 205, -1);
}




void cThueFlag::Init()
{
	this->Drawing = false;
	this->SetRect(120, 70, 400, 255);

}

void cThueFlag::Draw()
{
	
	if (GetKeyState(VK_F3) & 0x4000 && this->TickCount + 350 < GetTickCount())
	{
		this->Drawing = !this->Drawing;
		this->TickCount = GetTickCount();
		if (!this->Drawing)
		{
			this->SendRequest(0x2, 0);
	
		}
		else
		{
			this->SendRequest(0x0, this->Selected);
		}
	}
	
	if (!this->Drawing)
	{
		return;
	}
	//if (!this->Show) return;

	//if (!gInterface.Data[eMAIN_ThueFlag].OnShow)
	//{
	//	return;
	//}
	//
	

	//pSetCursorFocus = true;
	//float MainWidth = 400.0;
	//int JCResto = pWinWidth / pWinHeightReal / 2 - 320;
	//x = (MAX_WIN_WIDTH / 2) - (MainWidth / 2)+JCResto;
	////==========
	glAlphaFunc(GL_GREATER, 0.0f);

	CustomFont.Draw(CustomFont.FontBold, x, y, 0x0, 0x373b45ff, w, h, 1, " ");

	RenderBitmap(31355, x, y + 63, 21.0, 159.2f, 0, 0, 21.f / 32.f, 320.f / 512.f, 1, 1, 0.0);
	RenderBitmap(31356, x + w - 21.f, y + 63, 21.0, 159.2f, 0, 0, 21.f / 32.f, 320.f / 512.f, 1, 1, 0.0);

	RenderBitmap(31353, x, y, 60.f, 63.f, 0.0, 0, 60.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 60, y, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 130, y, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 200, y, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 270, y, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 340, y, 60.f, 63.f, 130.f / 256.f, 0, 60.f / 256.f, 63.f / 64.f, 1, 1, 0.0);

	RenderBitmap(31357, x, y + 212, 60.f, 63.f, 0.0, 0, 60.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31357, x + 60, y + 212, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31357, x + 130, y + 212, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31357, x + 200, y + 212, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31357, x + 270, y + 212, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31357, x + 340, y + 212, 60.f, 63.f, 130.f / 256.f, 0, 60.f / 256.f, 63.f / 64.f, 1, 1, 0.0);


	if (pCheckMouseOver(x + w - 25, y + 5, 20, 18))
	{
	gInterface.DrawToolTip(x + w - 25, y + 25, "Đóng");
	}

	if (pIsKeyRelease(VK_LBUTTON) && gInterface.IsWorkZone4(x + w - 25, y + 5, 20, 18))
	{
		this->SendRequest(0x2, 0);
		this->Drawing = false;
		gInterface.Data[eMAIN_ThueFlag].OnShow = false;
	}

	glAlphaFunc(GL_GREATER, 0.25f);


	this->DrawButton(32331, x + 14 + 75 * 4, y + h - 70, 73, 27, 128.0, 128.0, ThueFlag.BuyAction);
	this->DrawButton(32331, x + 14 + 75 * 3, y + h - 40, 73, 27, 128.0, 128.0, ThueFlag.PrevAction);
	this->DrawButton(32331, x + 14 + 75 * 4, y + h - 40, 73, 27, 128.0, 128.0, ThueFlag.NextAction);


	CustomFont.Draw(CustomFont.FontNormal, x + 14 + 75 * 4, y + h - 32.5, 0xffffffff, 0x0, 73, 0, 3, ">>");
	CustomFont.Draw(CustomFont.FontNormal, x + 14 + 75 * 3, y + h - 32.5, 0xffffffff, 0x0, 73, 0, 3, "<<");

	CustomFont.Draw(CustomFont.FontBold, x, y + 12, 0xffffffff, 0x0, w, 0, 3, "Hệ Thống Cờ");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 50 + 25 * 1, 0x0, 0x87CEFA, 100, 15, 0, " ");
	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 50 + 25 * 2, 0x0, 0x00F5FF, 100, 15, 0, " ");
	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 50 + 25 * 3, 0x0, 0x00FA9A, 100, 15, 0, " ");
	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 50 + 25 * 4, 0x0, 0xCAFF70, 100, 15, 0, " ");
	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 50 + 25 * 5, 0x0, 0xFF6A6A, 100, 15, 0, " ");
	//CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 50 + 25 * 6, 0x0, 0xCBA0AE, 100, 15, 0, " ");

	THUE_FLAG_DATA* skin = this->FindId(this->Selected);

	if (skin != 0)
	{
		CustomFont.Draw(CustomFont.FontNormal, x, y + 80, 0xffffffff, 0x0, 150, 0, 3, "Giá Mua (Wcoin) : %d", skin->Price);

		CustomFont.Draw(CustomFont.FontNormal, x, y + 105, 0xffffffff, 0x0, 150, 0, 3, "Sát Thương: %d", skin->Value1);
		CustomFont.Draw(CustomFont.FontNormal, x, y + 130, 0xffffffff, 0x0, 150, 0, 3, "Phòng Thủ: %d", skin->Value2);
		CustomFont.Draw(CustomFont.FontNormal, x, y + 155, 0xffffffff, 0x0, 150, 0, 3, "Máu: %d", skin->Value3);
		CustomFont.Draw(CustomFont.FontNormal, x, y + 180, 0xffffffff, 0x0, 150, 0, 3, "Mana: %d", skin->Value4);
		//CustomFont.Draw(CustomFont.FontNormal, x, y + 205, 0xffffffff, 0x0, 150, 0, 3, "Bạn Cần : %d",skin->Value7);

		gInterface.DrawItem2(x + 10 + 25 * 4 + 100, y+105, 50, 60, ITEM(skin->Value5, skin->Value6), 11, 0, 0, 0); // de tam sau ong cho cai gi cung dc




		if (skin->Skin == abs(this->Skin))
		{
			CustomFont.Draw(CustomFont.FontNormal, x + 34 + 75 * 2, y + 35, 0x0, 0x00F5FF, 80, 10, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, x + 4 + 75 * 2, y + 35, 0xffffffff, 0x0, 150, 0, 3, "Kích Hoạt");

			CustomFont.Draw(CustomFont.FontNormal, x + 14 + 75 * 4, y + h - 62.5, 0xffffffff, 0x0, 73, 0, 3, this->Skin < 0 ? "Sử Dụng" : "Không Sử Dụng");
		}
		else
		{
			CustomFont.Draw(CustomFont.FontNormal, x + 34 + 75 * 2, y + 35, 0x0, 0x00F5FF, 80, 10, 0, " ");
			CustomFont.Draw(CustomFont.FontNormal, x + 4 + 75 * 2, y + 35, 0xffffffff, 0x0, 150, 0, 3, "Chưa Kích Hoạt");
			CustomFont.Draw(CustomFont.FontNormal, x + 14 + 75 * 4, y + h - 62.5, 0xffffffff, 0x0, 73, 0, 3, "Mua");
		}

		

	}
	else
	{
		char buf[25];
		int step = GetTickCount() / 1000 % 4;
		sprintf(buf, "Loading data%%.%ds", step);

		CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 50 + 13 * 1, 0xffffffff, 0x0, 150, 0, 0, buf, "...");
	}
}

void cThueFlag::SendRequest(BYTE type, int value)
{
	PMSG_THUE_FLAG_SEND pRequest;
	pRequest.h.set((LPBYTE)&pRequest, 0xFB, 0x03, sizeof(pRequest));
	pRequest.Type = type;
	pRequest.Value = value;
	DataSend((LPBYTE)&pRequest, pRequest.h.size);
}


void cThueFlag::RecvData(BYTE* a)
{
	PMSG_THUE_FLAG_RECV* Packet = (PMSG_THUE_FLAG_RECV*)a;

	this->Skin = Packet->Skin;

	if (Packet->Data.Id == -1)
	{
		return;
	}

	this->Selected = Packet->Data.Id;

	THUE_FLAG_DATA* skin = this->FindId(Packet->Data.Id);

	if (skin != 0)
	{
		skin->Id = Packet->Data.Id;
		skin->Skin = Packet->Data.Skin;
		skin->Price = Packet->Data.Price;
		skin->Value1 = Packet->Data.Value1;
		skin->Value2 = Packet->Data.Value2;
		skin->Value3 = Packet->Data.Value3;
		skin->Value4 = Packet->Data.Value4;
		skin->Value5 = Packet->Data.Value5;
		skin->Value6 = Packet->Data.Value6;
		skin->Value7 = Packet->Data.Value7;
	}
	else
	{
		THUE_FLAG_DATA new_skin;
		new_skin.Id = Packet->Data.Id;
		new_skin.Skin = Packet->Data.Skin;
		new_skin.Price = Packet->Data.Price;
		new_skin.Value1 = Packet->Data.Value1;
		new_skin.Value2 = Packet->Data.Value2;
		new_skin.Value3 = Packet->Data.Value3;
		new_skin.Value4 = Packet->Data.Value4;
		new_skin.Value5 = Packet->Data.Value5;
		new_skin.Value6 = Packet->Data.Value6;
		new_skin.Value7 = Packet->Data.Value7;


		this->m_Data.push_back(new_skin);
		return;
	}
}


void cThueFlag::Clear()
{

	this->TickCount = 0;
	this->Skin = 0;
	this->Selected = 0;
	this->m_Data.clear();

}

THUE_FLAG_DATA* cThueFlag::FindSkin(int id)
{
	for (int i = 0; i < this->m_Data.size(); i++)
	{
		if (this->m_Data[i].Skin == id)
		{
			return &this->m_Data[i];
		}
	}
	return 0;
}
THUE_FLAG_DATA* cThueFlag::FindId(int id)
{
	for (int i = 0; i < this->m_Data.size(); i++)
	{
		if (this->m_Data[i].Id == id)
		{
			return &this->m_Data[i];
		}
	}
	return 0;
}


void cThueFlag::DrawButton(int IMGcode, float x, float y, float w, float h, float a6, float a7, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc)
{
	if (gInterface.IsWorkZone4(x, y, w, h)) {
		if (GetKeyState(VK_LBUTTON) & 0x8000) {
			RenderBitmap(IMGcode, x, y, w, h, 0.0, h / a7 * 2.0, w / a6, h / a7, 1, 1, 0.0);
		}
		else {
			RenderBitmap(IMGcode, x, y, w, h, 0.0, h / a7, w / a6, h / a7, 1, 1, 0.0);
		}
		if (pIsKeyRelease(VK_LBUTTON))
		{
			pCallbackFunc(this);
			return;
		}
		return;
	}
	else {
		RenderBitmap(IMGcode, x, y, w, h, 0.0, 0.0, w / a6, h / a7, 1, 1, 0.0);
	}
	return;
}


void cThueFlag::BuyAction(LPVOID pClass)
{
	cThueFlag* This = (cThueFlag*)pClass;


	THUE_FLAG_DATA* skin = This->FindId(This->Selected);

	if (skin != 0)
	{
		if (skin->Skin == abs(This->Skin))
		{
			This->SendRequest(0x3, abs(This->Skin) >= 0);
		}
		else
		{
			This->SendRequest(0x1, This->Selected);
		}
	}
}

void cThueFlag::NextAction(LPVOID pClass)
{
	cThueFlag* This = (cThueFlag*)pClass;

	This->SendRequest(0x0, This->Selected + 1);
}

void cThueFlag::PrevAction(LPVOID pClass)
{
	cThueFlag* This = (cThueFlag*)pClass;
	if (This->Selected > 0)
	{
		This->SendRequest(0x0, This->Selected - 1);
	}
}
#endif