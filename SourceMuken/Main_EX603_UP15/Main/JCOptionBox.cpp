#include "stdafx.h"
#include "JCEntryproy.h"
#include "JCOptionBox.h"
#include "Import.h"
#include "Util.h"
#include "Common.h"

JCOptionBox::JCOptionBox()
{
	this->JCRenderX = 0;
	this->JCRenderY = 0;
	this->JCWidth = 15.0;
	this->JCHeight = 15.0;
	ZeroMemory(this->JCtext, sizeof(this->JCtext));
	wsprintf(this->JCtext, "new JCOptionBox");
}

JCOptionBox::~JCOptionBox()
{

}

void JCOptionBox::SetText(char * Unknown)
{
	ZeroMemory(this->JCtext, sizeof(this->JCtext));
	wsprintf(this->JCtext, Unknown);
}

void JCOptionBox::LoadAction(int Pointer, int Action)
{
	this->JCActive = Pointer;
	this->JCAction = Action;

	switch (this->JCAction)
	{
	case JCDINAMIC_EFFECT:
	{
		this->JCActive = GetPrivateProfileIntA("AntiLag", "DisableDynamicEffect", 0, "./Settings.ini");
		SetByte((0x0074CD80 + 2), (this->JCActive == 0) ? 1 : 0);
	}
	break;
	case JCSTATIC_EFFECT:
	{
		this->JCActive = GetPrivateProfileIntA("AntiLag", "DisableStaticEffect", 0, "./Settings.ini");
		SetByte((0x00771359 + 3), (this->JCActive == 0) ? 1 : 0);
	}
	break;
	case JCSKILL_EFFECT:
	{
		this->JCActive = GetPrivateProfileIntA("AntiLag", "DisableSkillEffect", 0, "./Settings.ini");
		//SetByte((0x006D9113 + 3), ( DisableSkillEffect == 0 ) ? 1 : 0 );
		SetDword((0x0072D1BA + 3), (this->JCActive == 0) ? 0 : 500);
	}
	break;
	case JCITEMGLOW_EFFECT:
	{
		this->JCActive = GetPrivateProfileIntA("AntiLag", "DisableGlowEffect", 0, "./Settings.ini");
	}
	break;
	case JCOBJECTSHADOW:
	{
		this->JCActive = GetPrivateProfileIntA("AntiLag", "DisableShadow", 0, "./Settings.ini");
		DisableShadow = this->JCActive;
	}
	break;
	case JCOBJECTWORLDHIDE:
	{
		this->JCActive = GetPrivateProfileIntA("AntiLag", "DisableObject", 0, "./Settings.ini");
		//SetByte(0x005DE2B3 + 1, (this->JCActive == 0) ? 0x85 : 0x84); // Ocultamos objetos del mapa
	}
	break;
	case JTWINGSOBJECT:
	{
		this->JCActive = GetPrivateProfileIntA("AntiLag", "DisableWings", 0, "./Settings.ini");
		if (JCActive == 0)
		{
			SetCompleteHook(0xE8, 0x00588661, 0x005655C0);
		}
		else
		{
			MemorySet(0x00588661, 0x90, 0x05);
		}
	}
	break;
	case JTWEAPONOBJECT:
	{
		this->JCActive = GetPrivateProfileIntA("AntiLag", "DisableWeapons", 0, "./Settings.ini");
		if (JCActive == 0)
		{
			SetCompleteHook(0xE8, 0x00576DDB, 0x005655C0); //Enable Weapons
			SetCompleteHook(0xE8, 0x005883F4, 0x005655C0); //Enable Weapons
		}
		else
		{
			MemorySet(0x00576DDB, 0x90, 0x05); //Disable Weapons
			MemorySet(0x005883F4, 0x90, 0x05); //Disable Weapons
		}
	}
	break;
	case JTCLOACKOBJECT:
	{
		this->JCActive = GetPrivateProfileIntA("AntiLag", "DisableCloack", 0, "./Settings.ini");
		if (JCActive == 0)
		{
			SetByte(0x0051EE20, 0x55); //Enable Cloaks
		}
		else
		{
			SetByte(0x0051EE20, 0xC3); //Disable Cloaks
		}
	}
	break;
	case JCHIDEPLAYER:
	{
		this->JCActive = GetPrivateProfileIntA("AntiLag", "DisablePlayer", 0, "./Settings.ini");
		DisablePlayer = this->JCActive;
	}
	break;
	case NONE:
		break;
	case DEFAULT:
		break;
	}

}

void JCOptionBox::SetBounds(JCRECT Bound)
{
	this->JCRenderX = Bound.x;
	this->JCRenderY = Bound.y;
	this->JCWidth = Bound.w;
	this->JCHeight = Bound.h;
}

void JCOptionBox::SetBounds(float x, float y, float Width, float Height)
{
	this->JCRenderX = x;
	this->JCRenderY = y;
	this->JCWidth = Width;
	this->JCHeight = Height;
}

int JCOptionBox::SetVisible()
{
	if (this->JCActive != 0)
	{
		pSetTextColor(pTextThis(), 0x7Fu, 0xB2u, 0xFFu, 0xFFu); //-- eBlue
		//pSetTextColor(pTextThis(), 0x66u, 0x66u, 0x66u, 0xFFu); //-- eGray
	}
	else
	{

		pSetTextColor(pTextThis(), 1, 223, 119, 255); //-- eGreen
	}
	pDrawText(pTextThis(), this->JCRenderX + 18, this->JCRenderY + 3, this->JCtext, 0, 0, (LPINT)1, 0);
	pDrawButton(31593, this->JCRenderX, this->JCRenderY, this->JCWidth, this->JCHeight, 0.0, (this->JCActive != 0) ? 15.0 : 0.0);

	return this->JCActive;
}

void JCOptionBox::SetSize(float Width, float Height)
{
	this->JCWidth = Width;
	this->JCHeight = Height;
}

void JCOptionBox::SetLocation(float x, float y)
{
	this->JCRenderX = x;
	this->JCRenderY = y;
}

void JCOptionBox::SetLocationX(float x)
{
	this->JCRenderX = x;
}

void JCOptionBox::SetLocationY(float y)
{
	this->JCRenderY = y;
}

char * JCOptionBox::GetText()
{
	return this->JCtext;
}

JCRECT JCOptionBox::GetBounds()
{
	JCRECT Bounds;
	Bounds.x = this->JCRenderX;
	Bounds.y = this->JCRenderY;
	Bounds.w = this->JCWidth;
	Bounds.h = this->JCHeight;

	return Bounds;
}

void JCOptionBox::mouseClicked()
{
	if (pCheckMouseOver(this->JCRenderX, this->JCRenderY, this->JCWidth, this->JCHeight) && *(BYTE*)0x8793386)
	{
		if (GetTickCount() >= this->JCTimerEvent + 300)
		{
			if (this->JCActive)
			{
				this->JCActive = 0;
			}
			else
			{
				this->JCActive = 1;
			}
			this->ActionListener();
			this->JCTimerEvent = GetTickCount();
		}
		PlayBuffer(25, 0, 0);
	}
}

void JCOptionBox::mouseEntered()
{
}

void JCOptionBox::ActionListener()
{
	switch (this->JCAction)
	{
	case JCDINAMIC_EFFECT:
	{
		WritePrivateProfileStringA("AntiLag", "DisableDynamicEffect", (this->JCActive != 0) ? "1" : "0", "./Settings.ini");
		SetByte((0x0074CD80 + 2), (this->JCActive == 0) ? 1 : 0);
	}
	break;
	case JCSTATIC_EFFECT:
	{
		WritePrivateProfileStringA("AntiLag", "DisableStaticEffect", (this->JCActive != 0) ? "1" : "0", "./Settings.ini");
		SetByte((0x00771359 + 3), (this->JCActive == 0) ? 1 : 0);
	}
	break;
	case JCSKILL_EFFECT:
	{
		WritePrivateProfileStringA("AntiLag", "DisableSkillEffect", (this->JCActive != 0) ? "1" : "0", "./Settings.ini");
		SetDword((0x0072D1BA + 3), (this->JCActive == 0) ? 0 : 500); //SetByte((0x006D9113 + 3), ( DisableSkillEffect == 0 ) ? 1 : 0 );
	}
	break;
	case JCITEMGLOW_EFFECT:
	{
		WritePrivateProfileStringA("AntiLag", "DisableGlowEffect", (this->JCActive != 0) ? "1" : "0", "./Settings.ini");
	}
	break;
	case JCOBJECTSHADOW:
	{
		WritePrivateProfileStringA("AntiLag", "DisableShadow", (this->JCActive != 0) ? "1" : "0", "./Settings.ini");
		DisableShadow = this->JCActive;
	}
	break;
	case JCOBJECTWORLDHIDE:
	{
		WritePrivateProfileStringA("AntiLag", "DisableObject", (this->JCActive != 0) ? "1" : "0", "./Settings.ini");
		//SetByte(0x0057D4F5 + 1, ( this->JCActive == 0 ) ? 0 : 1 ); // Mostramos los monster
		//SetByte(0x005DE2B3 + 1, (this->JCActive == 0) ? 0x85 : 0x84); // Ocultamos objetos del mapa
	}
	break;
	case JTWINGSOBJECT:
	{
		WritePrivateProfileStringA("AntiLag", "DisableWings", (this->JCActive != 0) ? "1" : "0", "./Settings.ini");
		if (JCActive == 0)
		{
			SetCompleteHook(0xE8, 0x00588661, 0x005655C0);
		}
		else
		{
			MemorySet(0x00588661, 0x90, 0x05);
		}
	}
	break;
	case JTWEAPONOBJECT:
	{
		WritePrivateProfileStringA("AntiLag", "DisableWeapons", (this->JCActive != 0) ? "1" : "0", "./Settings.ini");
		if (JCActive == 0)
		{
			SetCompleteHook(0xE8, 0x00576DDB, 0x005655C0); //Enable Weapons
			SetCompleteHook(0xE8, 0x005883F4, 0x005655C0); //Enable Weapons
		}
		else
		{
			MemorySet(0x00576DDB, 0x90, 0x05); //Disable Weapons
			MemorySet(0x005883F4, 0x90, 0x05); //Disable Weapons
		}
	}
	break;
	case JTCLOACKOBJECT:
	{
		WritePrivateProfileStringA("AntiLag", "DisableCloack", (this->JCActive != 0) ? "1" : "0", "./Settings.ini");
		if (JCActive == 0)
		{
			SetByte(0x0051EE20, 0x55); //Enable Cloaks
		}
		else
		{
			SetByte(0x0051EE20, 0xC3); //Disable Cloaks
		}
	}
	break;
	case JCHIDEPLAYER:
	{
		WritePrivateProfileStringA("AntiLag", "DisablePlayer", (this->JCActive != 0) ? "1" : "0", "./Settings.ini");
		DisablePlayer = this->JCActive;
	}
	break;
	case NONE:
		break;
	case DEFAULT:
		break;
	}
}