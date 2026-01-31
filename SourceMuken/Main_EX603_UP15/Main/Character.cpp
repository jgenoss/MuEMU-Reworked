#include "stdafx.h"
#include "Character.h"
#include "Util.h"
#include "Import.h"
#include "Interface.h"
#include "CustomFont.h"
#include "CustomMonster.h"
#include "SEASON3B.h"
cCharacter character;
cCharacter::cCharacter()
{
	this->Key = -1;
	this->SetZoom(0.45f, 0.8f, 0.01f, 0.6f);
}

cCharacter::~cCharacter()
{
}

void cCharacter::Init()
{
}

void cCharacter::Draw(int c, float x, float y, float w, float h, float rot, float zoom)
{
	if (c == 0) {
		return;
	}
	int o = c + 776;
	int worldBK = pMapNumber;
	pMapNumber = 0;
	pMapNumber = worldBK;

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glViewport2(x * g_fScreenRate_x, y * g_fScreenRate_y, w * g_fScreenRate_x, h * g_fScreenRate_y);
	gluPerspective2(1.f, (w * g_fScreenRate_x) / (h * g_fScreenRate_y), 2000, 20000);//CameraViewNear,CameraViewFar);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	((void(__cdecl*)(LPVOID a1)) 0x00635830)((LPVOID)0x87933A0);
	EnableDepthTest();
	EnableDepthMask();

	glRotatef(-90.0f, 1.f, 0.f, 0.f);
	glRotatef(-90.0f, 0.f, 0.f, 1.f);
	glTranslatef(-10000.0f, 0.0f, -75.f);
	if (*(WORD*)(c + 448) == 7831)
	{ // check 13 3, 4, 37... pet cuoi
		glTranslatef(-*(float*)(o + 252), -*(float*)(o + 256), -*(float*)(o + 260) + 50.0); // deo pet
	}
	else if (*(_WORD*)(c + 520) != 65535)
	{ //deo canh
		glTranslatef(-*(float*)(o + 252), -*(float*)(o + 256), -*(float*)(o + 260) + 50.0); // khi deo canh 
	}
	else
	{
		glTranslatef(-*(float*)(o + 252), -*(float*)(o + 256), -*(float*)(o + 260) + 50.0); // cao thap 
	}
	*(float*)(o + 264) = 0.0;
	*(float*)(o + 268) = 0.0;
	*(float*)(o + 272) = rot;

	glDisable(GL_ALPHA_TEST);
	glEnable(GL_TEXTURE_2D);
	EnableDepthTest();
	((void(*)()) 0x00635E80)();
	EnableDepthMask();
	TextureEnable = true;
	DepthTestEnable = true;
	CullFaceEnable = true;
	DepthMaskEnable = true;
	glDepthFunc(GL_LEQUAL);
	glAlphaFunc(GL_GREATER, 0.25f);
	glDisable(GL_FOG);
	glClear(GL_DEPTH_BUFFER_BIT);


	*(float*)(o + 96) = 0.7f * zoom;
	*(BYTE*)(c + 16) = 1;

	*(float*)(o + 156) = 1.0;
	*(float*)(o + 160) = 1.0;
	*(float*)(o + 164) = 1.0;

	((int(__cdecl*)(int c, int o, int Select)) 0x0056F210)(c, o, 0); //RenderCharacter

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glViewport2(0, 0, *(GLsizei*)0x0E61E58, *(GLsizei*)0x0E61E5C);

	EnableAlphaTest(true);
	glColor4f(1.f, 1.f, 1.f, 1.f);
}

void cCharacter::Draw2(int c, float x, float y, float w, float h, float rot, float zoom)
{
	if (c == 0) {
		return;
	}
	int o = c + 776;
	int worldBK = pMapNumber;
	pMapNumber = 0;
	pMapNumber = worldBK;

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glViewport2(x * g_fScreenRate_x, y * g_fScreenRate_y, w * g_fScreenRate_x, h * g_fScreenRate_y);
	gluPerspective2(1.f, (w * g_fScreenRate_x) / (h * g_fScreenRate_y), 2000, 20000);//CameraViewNear,CameraViewFar);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	((void(__cdecl*)(LPVOID a1)) 0x00635830)((LPVOID)0x87933A0);
	EnableDepthTest();
	EnableDepthMask();

	glRotatef(-90.0f, 1.f, 0.f, 0.f);
	glRotatef(-90.0f, 0.f, 0.f, 1.f);
	glTranslatef(-10000.0f, 0.0f, -75.f);
	if (*(WORD*)(c + 448) == 7831)
	{ // check 13 3, 4, 37... pet cuoi
		glTranslatef(-*(float*)(o + 252), -*(float*)(o + 256), -*(float*)(o + 260)); // deo pet
	}
	else if (*(_WORD*)(c + 520) != 65535)
	{ //deo canh
		glTranslatef(-*(float*)(o + 252), -*(float*)(o + 256), -*(float*)(o + 260)); // khi deo canh 
	}
	else
	{
		glTranslatef(-*(float*)(o + 252), -*(float*)(o + 256), -*(float*)(o + 260)); // cao thap 
	}
	*(float*)(o + 264) = 0.0;
	*(float*)(o + 268) = 0.0;
	*(float*)(o + 272) = rot;

	glDisable(GL_ALPHA_TEST);
	glEnable(GL_TEXTURE_2D);
	EnableDepthTest();
	((void(*)()) 0x00635E80)();
	EnableDepthMask();
	TextureEnable = true;
	DepthTestEnable = true;
	CullFaceEnable = true;
	DepthMaskEnable = true;
	glDepthFunc(GL_LEQUAL);
	glAlphaFunc(GL_GREATER, 0.25f);
	glDisable(GL_FOG);
	glClear(GL_DEPTH_BUFFER_BIT);


	*(float*)(o + 96) = 0.7f * zoom;
	*(BYTE*)(c + 16) = 1;

	*(float*)(o + 156) = 1.0;
	*(float*)(o + 160) = 1.0;
	*(float*)(o + 164) = 1.0;

	((int(__cdecl*)(int c, int o, int Select)) 0x0056F210)(c, o, 0); //RenderCharacter

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glViewport2(0, 0, *(GLsizei*)0x0E61E58, *(GLsizei*)0x0E61E5C);

	EnableAlphaTest(true);
	glColor4f(1.f, 1.f, 1.f, 1.f);
}
void cCharacter::DrawClone(float x, float y, float w, float h)
{
	int c = *(int*)0x7BC4F04;
	if (c) {
		int o = c + 776;
		float Backup[10] = { 0, };
		Backup[0] = *(float*)(o + 264);
		Backup[1] = *(float*)(o + 268);
		Backup[2] = *(float*)(o + 272); //rot
		Backup[3] = *(float*)(o + 96);
		Backup[4] = *(float*)(o + 156);
		Backup[5] = *(float*)(o + 160);
		Backup[6] = *(float*)(o + 164);
		Backup[7] = *(float*)(o + 252);
		Backup[8] = *(float*)(o + 256);
		Backup[9] = *(float*)(o + 260);

		*(float*)(o + 252) = -300;
		*(float*)(o + 256) = -300;
		*(float*)(o + 260) = -300;

		character.Draw(c, x, y, w + 100, h + 100, 90.0f, 0.5f);

		*(BYTE*)(c + 16) = 0;

		*(float*)(o + 264) = Backup[0];
		*(float*)(o + 268) = Backup[1];
		*(float*)(o + 272) = Backup[2];
		*(float*)(o + 96) = Backup[3];
		*(float*)(o + 156) = Backup[4];
		*(float*)(o + 160) = Backup[5];
		*(float*)(o + 164) = Backup[6];
		*(float*)(o + 252) = Backup[7];
		*(float*)(o + 256) = Backup[8];
		*(float*)(o + 260) = Backup[9];
	}
}

bool cCharacter::Rotate(float x, float y, float w, float h, float* rot, float speed, float defaultRot)
{
	bool ret = false;
	if (this->Rotating && !MouseLButton) //release
	{
		this->Rotating = false;
	}
	if (pIsKeyPress(VK_RBUTTON)) //reset
	{
		this->Rotating = false;
		*rot = defaultRot;
	}
	if (this->Rotating) //rotate
	{
		if (this->rot[0] != pCursorX)
		{
			float diff = (float)(pCursorX - this->rot[0]) / speed;
			*rot += diff;
			this->rot[0] = pCursorX;
		}
		ret = true;
	}
	if (!gInterface.IsWorkZone(x, y, w, h)) {
		this->Zoomming = false;
		return ret;
	}
	this->Zoomming = true;
	if (!this->Rotating && pIsKeyPress(VK_LBUTTON)) {
		this->rot[0] = pCursorX;
		this->rot[1] = pCursorY;
		this->Rotating = true;
	}
	return ret;
}


void cCharacter::Zoom(MOUSEHOOKSTRUCTEX * Mouse, WPARAM wParam)
{
	if (!this->Zoomming)
	{
		return;
	}
	switch (wParam) {

	case WM_RBUTTONDOWN:
		this->rot[2] = this->LimitZoom[3]; //reset
		break;
	case WM_MOUSEWHEEL: {
		if ((int)Mouse->mouseData > 0) {
			this->rot[2] = min(this->LimitZoom[1], this->rot[2] + this->LimitZoom[2]);
		}
		else if ((int)Mouse->mouseData < 0) {
			this->rot[2] = max(this->LimitZoom[0], this->rot[2] - this->LimitZoom[2]);
		}
	}
						break;

	}
}

int cCharacter::CreateHero(int Index, short Class, bool clearItems)
{
	int key = ((int(__cdecl*)(int)) 0x57D9A0)(Index);
	if (key != 400)
	{
		int c = ((int(__thiscall*)(int, int)) 0x0096A4C0)(((int(*)()) 0x402BC0)(), key);
		if (c)
		{
			if (clearItems || *(_BYTE*)(c + 19) != Class)
			{
				int o = c + 776;
				*(float*)(o + 156) = 0.3f;
				*(float*)(o + 160) = 0.3f;
				*(float*)(o + 164) = 0.3f;
				*(_BYTE*)(c + 19) = Class;

				*(_WORD*)(c + 268) = ((int(__cdecl*)(BYTE userclass)) 0x00405230)(Class) + 9389;
				*(_WORD*)(c + 304) = ((int(__cdecl*)(BYTE userclass)) 0x00405230)(Class) + 9413;
				*(_WORD*)(c + 340) = ((int(__cdecl*)(BYTE userclass)) 0x00405230)(Class) + 9437;
				*(_WORD*)(c + 376) = ((int(__cdecl*)(BYTE userclass)) 0x00405230)(Class) + 9461;
				*(_WORD*)(c + 412) = ((int(__cdecl*)(BYTE userclass)) 0x00405230)(Class) + 9485;
				*(_WORD*)(c + 448) = -1;
				*(_WORD*)(c + 484) = -1;
				*(_WORD*)(c + 520) = -1;
				*(_WORD*)(c + 556) = -1;
				*(_BYTE*)(c + 21) = 0;
				((void(__cdecl*)(int)) 0x57F020)(c);
				((void(__cdecl*)(int)) 0x54EA80)(c);
				this->SetZoom();
			}
			return key;
		}
		return -1;
	}
	int c = ((int(__cdecl*)(int, int, char, char, float)) 0x0057EEC0)(Index, 1163, 0, 0, 90);
	if (c) {
		int o = c + 776;
		*(float*)(o + 156) = 0.3f;
		*(float*)(o + 160) = 0.3f;
		*(float*)(o + 164) = 0.3f;
		*(_BYTE*)(c + 19) = Class;

		*(_WORD*)(c + 268) = ((int(__cdecl*)(BYTE userclass)) 0x00405230)(Class) + 9389;
		*(_WORD*)(c + 304) = ((int(__cdecl*)(BYTE userclass)) 0x00405230)(Class) + 9413;
		*(_WORD*)(c + 340) = ((int(__cdecl*)(BYTE userclass)) 0x00405230)(Class) + 9437;
		*(_WORD*)(c + 376) = ((int(__cdecl*)(BYTE userclass)) 0x00405230)(Class) + 9461;
		*(_WORD*)(c + 412) = ((int(__cdecl*)(BYTE userclass)) 0x00405230)(Class) + 9485;
		*(_WORD*)(c + 448) = -1;
		*(_WORD*)(c + 484) = -1;
		*(_WORD*)(c + 520) = -1;
		*(_WORD*)(c + 556) = -1;
		*(_BYTE*)(c + 21) = 0;
		((void(__cdecl*)(int)) 0x57F020)(c);
		((void(__cdecl*)(int)) 0x54EA80)(c);
		this->SetZoom();
		return *(_WORD*)(c + 126);
	}
	return -1;
}

void cCharacter::CharSetSlotItem(int c, int Slot, int Id, int Level, int Ex, int Ancient)
{
	if (c) {
		switch (Slot)
		{
		case 16: //head
			break;
		case 2: //helm
			*(_WORD*)(c + 268) = Id;
			*(BYTE*)(c + 268 + 2) = Level; //((Level>>3)&15);
			*(BYTE*)(c + 268 + 3) = Ancient;
			*(BYTE*)(c + 268 + 4) = Ex;
			break;
		case 3: //armor
			*(_WORD*)(c + 304) = Id;
			*(BYTE*)(c + 304 + 2) = Level;
			*(BYTE*)(c + 304 + 3) = Ancient;
			*(BYTE*)(c + 304 + 4) = Ex;
			break;
		case 4: //pants
			*(_WORD*)(c + 340) = Id;
			*(BYTE*)(c + 340 + 2) = Level;
			*(BYTE*)(c + 340 + 3) = Ancient;
			*(BYTE*)(c + 340 + 4) = Ex;
			break;
		case 5: //gloves
			*(_WORD*)(c + 376) = Id;
			*(BYTE*)(c + 376 + 2) = Level;
			*(BYTE*)(c + 376 + 3) = Ancient;
			*(BYTE*)(c + 376 + 4) = Ex;
			break;
		case 6: //boots
			*(_WORD*)(c + 412) = Id;
			*(BYTE*)(c + 412 + 2) = Level;
			*(BYTE*)(c + 412 + 3) = Ancient;
			*(BYTE*)(c + 412 + 4) = Ex;
			break;
		case 0: //weapon 0
			*(_WORD*)(c + 448) = Id;
			*(BYTE*)(c + 448 + 2) = Level;
			*(BYTE*)(c + 448 + 3) = Ancient;
			*(BYTE*)(c + 448 + 4) = Ex;
			break;
		case 1: //weapon 1
			*(_WORD*)(c + 484) = Id;
			*(BYTE*)(c + 484 + 2) = Level;
			*(BYTE*)(c + 484 + 3) = Ancient;
			*(BYTE*)(c + 484 + 4) = Ex;
			break;
		case 7: //wings
			*(_WORD*)(c + 520) = Id;
			*(BYTE*)(c + 520 + 2) = Level;
			*(BYTE*)(c + 520 + 3) = Ancient;
			*(BYTE*)(c + 520 + 4) = Ex;
			break;
		case 8: //pets
			*(_WORD*)(c + 556) = Id;
			*(BYTE*)(c + 556 + 2) = Level;
			*(BYTE*)(c + 556 + 3) = Ancient;
			*(BYTE*)(c + 556 + 4) = Ex;
			break;
		default:
			break;
		}
	}
}
void cCharacter::SetChangeSkin(int Skin)
{
	int key = ((int(__cdecl*)(int)) 0x57D9A0)(oHero1);
	if (key == 400) //chua co object
	{
		return;
	}
	int c = ((int(__thiscall*)(int a1, int a2)) 0x0096A4C0)(((int(*)()) 0x402BC0)(), key);
	if (!c) return;
	int o = c + 776;
	*(DWORD*)(o + 52) = (Skin == -1 ? *((DWORD*)oUserPreviewStruct + 207) : Skin);
}
void cCharacter::DrawHero(float x, float y, float w, float h, int Id)
{
	int key = ((int(__cdecl*)(int)) 0x57D9A0)(Id);
	if (key == 400) //chua co object
	{
		//khoi tao
		this->CreateHero(Id, 1, true);
		//this->SetChangeSkin(-1);
		key = ((int(__cdecl*)(int)) 0x57D9A0)(Id);
		int c = ((int(__thiscall*)(int a1, int a2)) 0x0096A4C0)(((int(*)()) 0x402BC0)(), key);
		if (c) {
			this->CharSetSlotItem(c, 0, 1171 + 0 * 512 + 19, 15, 1, 1); //vu khi
			this->CharSetSlotItem(c, 1, 1171 + 6 * 512 + 10, 15, 1, 1); //vu khi
			this->CharSetSlotItem(c, 2, 1171 + 7 * 512 + 1, 15, 1, 1); //mu
			this->CharSetSlotItem(c, 3, 1171 + 8 * 512 + 1, 15, 1, 1); //ao
			this->CharSetSlotItem(c, 4, 1171 + 9 * 512 + 1, 15, 1, 1); //quan
			this->CharSetSlotItem(c, 5, 1171 + 10 * 512 + 1, 15, 1, 1); //quan
			this->CharSetSlotItem(c, 6, 1171 + 11 * 512 + 1, 15, 1, 1); //quan
			this->CharSetSlotItem(c, 7, 1171 + 12 * 512 + 36, 15, 1, 1); //wing
		}
	}
	else //da co, ve thoi
	{
		int c = ((int(__thiscall*)(int a1, int a2)) 0x0096A4C0)(((int(*)()) 0x402BC0)(), key);
		if (c) {
			int hero = *(int*)0x7BC4F04;
			
			if (*(_BYTE*)(c + 19) != *(_BYTE*)(hero + 19))
			{
				this->CreateHero(Id, *(_BYTE*)(hero + 19), true);
				//this->SetChangeSkin(-1);
				//clone item

				for (int i = 0; i < 9; i++)
				{
					*(_WORD*)(c + 268 + 36 * i) = *(_WORD*)(hero + 268 + 36 * i);
					*(BYTE*)(c + 268 + 2 + 36 * i) = *(BYTE*)(hero + 268 + 2 + 36 * i);
					*(BYTE*)(c + 268 + 3 + 36 * i) = *(BYTE*)(hero + 268 + 3 + 36 * i);
					*(BYTE*)(c + 268 + 4 + 36 * i) = *(BYTE*)(hero + 268 + 4 + 36 * i);
				}

			}
			else {
				for (int i = 0; i < 9; i++)
				{
					//update items
					if (*(_WORD*)(c + 268 + 36 * i) != *(_WORD*)(hero + 268 + 36 * i)) {
						*(_WORD*)(c + 268 + 36 * i) = *(_WORD*)(hero + 268 + 36 * i);
						*(BYTE*)(c + 268 + 2 + 36 * i) = *(BYTE*)(hero + 268 + 2 + 36 * i);
						*(BYTE*)(c + 268 + 3 + 36 * i) = *(BYTE*)(hero + 268 + 3 + 36 * i);
						*(BYTE*)(c + 268 + 4 + 36 * i) = *(BYTE*)(hero + 268 + 4 + 36 * i);
					}
				}
				int o = c + 776;
				int oh = hero + 776;
				//this->Draw2(c, x, y, w, h, 90.0f, 0.5f);
				//*(DWORD*)(o + 52) = *(DWORD*)(oh + 52);
				this->Rotate(x, y, 150, 150, &*(float*)(o + 272), 0.5f, 90.f);
				this->Draw2(c, x, y, h, w, *(float*)(o + 272), this->rot[2] - 0.3f);
			}
		}
	}
}
int cCharacter::CreateMonster(int Index, short Class)
{
	int key = ((int(__cdecl*)(int)) 0x57D9A0)(Index);
	if (key != 400)
	{
		int c = ((int(__thiscall*)(int a1, int a2)) 0x0096A4C0)(((int(*)()) 0x402BC0)(), key);
		return key;
	}
	int c = gCustomMonster.CreateMonster(Class, 0, 0, Index);
	this->SetZoom();
	return *(_WORD*)(c + 126);
}

void cCharacter::DrawMonster(float x, float y, float w, float h,int IndexModel, int Class, float Size)
{
	
	int key = ((int(__cdecl*)(int)) 0x57D9A0)(IndexModel);
	if (key == 400) //chua co object
	{
		//khoi tao
		this->CreateMonster(IndexModel, Class);
	}
	else //da co, ve thoi
	{
		int c = ((int(__thiscall*)(int a1, int a2)) 0x0096A4C0)(((int(*)()) 0x402BC0)(), key);
		if (c)
		{
			int o = c + 776;
			this->Draw2(c, x, y, w, h, 90.f, Size);
		}
	}
}
