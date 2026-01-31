#include "StdAfx.h"
#include "HuyHieuCuongHoa.h"
#include "Util.h"
#include "Object.h"
#include "Import.h"
#include "Central.h"
#include "User.h"
#include "CustomMessage.h"
#include "Defines.h"
#include "Protect.h"
#include "CustomFont.h"
#include "GLFont.h"

HuyHieuCuongHoa gHuyHieuCuongHoa;

HuyHieuCuongHoa::HuyHieuCuongHoa(void)
{
}

HuyHieuCuongHoa::~HuyHieuCuongHoa(void)
{
}

void HuyHieuCuongHoa::ImageLoad()
{
	pLoadImage("Custom\\Interface\\Gray.tga", 59999, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\Color.tga", 59990, 0x2601, 0x2900, 1, 0);

}

void HuyHieuCuongHoa::BinObeject()
{
	gInterface.BindObject(eDameGray, 0x7901, 23, 23, -1, -1);
	gInterface.BindObject(eDameColor, 0x7902, 23, 23, -1, -1);
}

void HuyHieuCuongHoa::DrawHuyHieu()
{

}
void HuyHieuCuongHoa::DrawChiSo()
{
	if (gProtect.m_MainInfo.CustomInterfaceType == 0)
	{

		float Solarx;
		float Solary;
		float MainWidth = 200.0;
		float MainHeight = 180.0;
		float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
		float CurrentMove;
		int TxtCount = -1;
		Solary = StartY - 70;
		int TxtStart = Solary + 100;
		int SetLV = 0;
		Solarx = StartX - 200;

		if (gInterface.CheckWindow(Inventory) && pCheckMouseOver(StartX + 347, StartY - 47, 22, 22))
		{
			gCentral.PrintDropBox(Solarx + 220, Solary, MainWidth, MainHeight, 0, 0);

			CustomFont.Draw(CustomFont.FontBold, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) - 60, 0xFFBF00FF, 0x0, 210, 0, 3, "Huy Hiệu Cường Hóa");
			gInterface.DrawFormat(eYellow, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) - 45, 210, 3, "Thông Tin Set Item Cường Hóa");
			gInterface.DrawFormat(eYellow, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) - 35, 210, 3, "Áp Dụng Khi Mặc Đủ 5 Món");
			gInterface.DrawFormat(eYellow, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) - 25, 210, 3, "Đồ Cấp 7 Trở Lên");
			gInterface.DrawFormat(eYellow, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) - 15, 210, 3, "Đủ Set Trang Bị Hoàn Hảo + 11 Kích Hoạt 1 Dòng");
			gInterface.DrawFormat(eYellow, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) - 5, 210, 3, "Đủ Set Trang Bị Hoàn Hảo + 12 Kích Hoạt 2 Dòng");
			gInterface.DrawFormat(eYellow, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 5, 210, 3, "Đủ Set Trang Bị Hoàn Hảo + 13 Kích Hoạt 3 Dòng");
			gInterface.DrawFormat(eYellow, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 15, 210, 3, "Đủ Set Trang Bị Hoàn Hảo + 14 Kích Hoạt 4 Dòng");
			gInterface.DrawFormat(eYellow, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 25, 210, 3, "Đủ Set Trang Bị Hoàn Hảo + 15 Kích Hoạt 5 Dòng");

			pSetBackgroundTextColor(pTextThis(), 255, 0, 0, 255);
			pSetTextColor(pTextThis(), 255, 255, 255, 0xFFu); //-- ewhite
			pDrawText(pTextThis(), Solarx + (MainWidth / 2) - (137 / 2) + 190, TxtStart + (33.0f * TxtCount) + 40, "Chỉ Số Khi Mặc Đủ Set", 200, 0, (LPINT)3, 0);


			if (this->huyhieu >= 1)
			{
				gInterface.DrawFormat(eExcellent, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 50, 210, 3, "(Đủ Set + 11)Gia Tăng Lượng HP %d", this->dong1);
			}
			else
			{
				gInterface.DrawFormat(eGray100, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 50, 210, 3, "(Đủ Set + 11)Gia Tăng Lượng HP %d", this->dong1);
			}
			if (this->huyhieu >= 2)
			{
				gInterface.DrawFormat(eExcellent, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 60, 210, 3, "(Đủ Set + 12)Gia Tăng Phòng Thủ %d", this->dong2);
			}
			else
			{
				gInterface.DrawFormat(eGray100, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 60, 210, 3, "(Đủ Set + 12)Gia Tăng Phòng Thủ %d", this->dong2);
			}

			if (this->huyhieu >= 3)
			{
				gInterface.DrawFormat(eExcellent, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 70, 210, 3, "(Đủ Set + 13)Gia Tăng Tấn Công %d", this->dong3);
			}
			else
			{
				gInterface.DrawFormat(eGray100, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 70, 210, 3, "(Đủ Set + 13)Gia Tăng Tấn Công %d", this->dong3);
			}
			if (this->huyhieu >= 4)
			{
				gInterface.DrawFormat(eExcellent, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 80, 210, 3, "(Đủ Set + 14)Tỷ Lệ X2 Sát Thương + %d%%", this->dong4);
			}
			else
			{
				gInterface.DrawFormat(eGray100, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 80, 210, 3, "(Đủ Set + 14)Tỷ Lệ X2 Sát Thương + %d%%", this->dong4);
			}
			if (this->huyhieu >= 5)
			{
				gInterface.DrawFormat(eExcellent, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 90, 210, 3, "(Đủ Set + 15)Bỏ Qua Phòng Thủ + %d%%", this->dong5);
			}
			else
			{
				gInterface.DrawFormat(eGray100, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 90, 210, 3, "(Đủ Set + 15)Bỏ Qua Phòng Thủ + %d%%", this->dong5);
			}
		}
	}
	else
	{
		float Solarx;
		float MainWidth = 200.0;
		float MainHeight = 180.0;
		float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
		float CurrentMove;
		int TxtCount = -1;
		int TxtStart = StartY + 100;
		int SetLV = 0;

		if (gInterface.CheckWindow(Character))
		{
			Solarx = StartX - 190;
		}
		else
		{
			Solarx = StartX;
		}

		if (gInterface.CheckWindow(Inventory) && pCheckMouseOver(Solarx + 347, StartY - 47, 22, 22))
		{
			gCentral.PrintDropBox(Solarx + 220, StartY, MainWidth, MainHeight, 0, 0);

			CustomFont.Draw(CustomFont.FontBold, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) - 60, 0xFFBF00FF, 0x0, 210, 0, 3, "Huy Hiệu Cường Hóa");
			gInterface.DrawFormat(eYellow, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) - 45, 210, 3, "Thông Tin Set Item Cường Hóa");
			gInterface.DrawFormat(eYellow, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) - 35, 210, 3, "Áp Dụng Cho Set Item");
			gInterface.DrawFormat(eYellow, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) - 25, 210, 3, "Đồ Cấp7 - 380 - 400");
			gInterface.DrawFormat(eYellow, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) - 15, 210, 3, "Đủ Set Trang Bị Hoàn Hảo + 11 Kích Hoạt 1 Dòng");
			gInterface.DrawFormat(eYellow, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) - 5, 210, 3, "Đủ Set Trang Bị Hoàn Hảo + 12 Kích Hoạt 2 Dòng");
			gInterface.DrawFormat(eYellow, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 5, 210, 3, "Đủ Set Trang Bị Hoàn Hảo + 13 Kích Hoạt 3 Dòng");
			gInterface.DrawFormat(eYellow, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 15, 210, 3, "Đủ Set Trang Bị Hoàn Hảo + 14 Kích Hoạt 4 Dòng");
			gInterface.DrawFormat(eYellow, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 25, 210, 3, "Đủ Set Trang Bị Hoàn Hảo + 15 Kích Hoạt 5 Dòng");


			pSetBackgroundTextColor(pTextThis(), 255, 0, 0, 255);

			pSetTextColor(pTextThis(), 255, 255, 255, 0xFFu); //-- ewhite
			pDrawText(pTextThis(), Solarx + (MainWidth / 2) - (137 / 2) + 190, TxtStart + (33.0f * TxtCount) + 40, "Chỉ Số Khi Mặc Đủ Set", 200, 0, (LPINT)3, 0);

			if (this->huyhieu >= 1)
			{
				gInterface.DrawFormat(eExcellent, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 50, 210, 3, "(Đủ Set + 11)Gia Tăng Lượng HP %d", this->dong1);
			}
			else
			{
				gInterface.DrawFormat(eGray100, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 50, 210, 3, "(Đủ Set + 11)Gia Tăng Lượng HP %d", this->dong1);
			}
			if (this->huyhieu >= 2)
			{
				gInterface.DrawFormat(eExcellent, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 60, 210, 3, "(Đủ Set + 12)Gia Tăng Phòng Thủ %d", this->dong2);
			}
			else
			{
				gInterface.DrawFormat(eGray100, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 60, 210, 3, "(Đủ Set + 12)Gia Tăng Phòng Thủ %d", this->dong2);
			}

			if (this->huyhieu >= 3)
			{
				gInterface.DrawFormat(eExcellent, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 70, 210, 3, "(Đủ Set + 13)Gia Tăng Tấn Công %d", this->dong3);
			}
			else
			{
				gInterface.DrawFormat(eGray100, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 70, 210, 3, "(Đủ Set + 13)Gia Tăng Tấn Công %d", this->dong3);
			}
			if (this->huyhieu >= 4)
			{
				gInterface.DrawFormat(eExcellent, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 80, 210, 3, "(Đủ Set + 14)Tỷ Lệ X2 Sát Thương + %d%%", this->dong4);
			}
			else
			{
				gInterface.DrawFormat(eGray100, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 80, 210, 3, "(Đủ Set + 14)Tỷ Lệ X2 Sát Thương + %d%%", this->dong4);
			}
			if (this->huyhieu >= 5)
			{
				gInterface.DrawFormat(eExcellent, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 90, 210, 3, "(Đủ Set + 15)Bỏ Qua Phòng Thủ + %d%%", this->dong5);
			}
			else
			{
				gInterface.DrawFormat(eGray100, Solarx + (MainWidth / 2) - (137 / 2) + 180, TxtStart + (33.0f * TxtCount) + 90, 210, 3, "(Đủ Set + 15)Bỏ Qua Phòng Thủ + %d%%", this->dong5);
			}
		}
	}
}

void HuyHieuCuongHoa::GCData(PMSG_HUYHIEU_RECV* lpMsg)
{
	this->huyhieu = lpMsg->huyhieu;
	this->dong1 = lpMsg->dong1;
	this->dong2 = lpMsg->dong2;
	this->dong3 = lpMsg->dong3;
	this->dong4 = lpMsg->dong4;
	this->dong5 = lpMsg->dong5;
}