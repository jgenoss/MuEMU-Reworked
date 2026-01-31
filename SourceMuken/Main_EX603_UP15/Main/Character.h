#pragma once

//#define SetPlayerStop						((void(__cdecl*)(int c)) 0x54EA80)
//#define SetCharacterScale					((void(__cdecl*)(int c)) 0x57F020)
//#define MoveCharacter						((int(__cdecl*)(int c, int o)) 0x0055AF20)
//#define MoveCharacterVisual					((int(__cdecl*)(int c, int o)) 0x00561560)
//#define RenderCharacter						((int(__cdecl*)(int c, int o, int Select)) 0x0056F210)
#define TextureEnable						*(BYTE*)0x08793260
#define DepthTestEnable						*(BYTE*)0x0879325F
#define CullFaceEnable						*(BYTE*)0x0879325E
#define DepthMaskEnable						*(BYTE*)0x0879325D
#define pIsButtonPressed		((int(__cdecl*)(int ButtonNumber)) 0x791070)
#define pIsKeyNone				((bool(__cdecl*)(int)) 0x791030)
#define pIsKeyRelease			((bool(__cdecl*)(int)) 0x791050)
#define pIsKeyPress				((bool(__cdecl*)(int)) 0x791070)
#define pIsKeyRepeat			((bool(__cdecl*)(int)) 0x791090)
#define MouseLButton			*(bool*)0x8793386
#define _BYTE		BYTE
#define _WORD		WORD
#define _DWORD		DWORD

enum CustomObjectID //0-99
{
	oViewCharItems = 9968,
	oHero1 = 9969,
	oMonster1=14000,	
};

class cCharacter
{
public:
	cCharacter();
	~cCharacter();
	void Init();
	void DrawHero(float x, float y, float w, float h, int Id);
	void DrawClone(float x, float y, float w, float h);
	int  CreateHero(int Index, short Class, bool clearItems = false);
	void CharSetSlotItem(int C, int Slot, int Id, int Level, int Ex, int Ancient);
	void SetZoom(float zoom = 1.f) { this->rot[2] = zoom; }
	void Zoom(MOUSEHOOKSTRUCTEX* Mouse, WPARAM wParam);
	void SetZoom(float min, float max, float speed, float defaultZoom) { this->LimitZoom[0] = min; this->LimitZoom[1] = max; this->LimitZoom[2] = speed; this->LimitZoom[3] = defaultZoom; this->rot[2] = defaultZoom; }
	bool Rotate(float x, float y, float w, float h, float* rot, float speed, float defaultRot = 90.f);
	void Draw(int c, float x, float y, float w, float h, float rot = 90.f, float zoom = 1.f);
	void Draw2(int c, float x, float y, float w, float h, float rot = 90.f, float zoom = 1.f);
	void SetChangeSkin(int Skin);
	void cCharacter::DrawMonster(float x, float y, float w, float h, int IndexModel, int Class, float Size =1.f);
	int cCharacter::CreateMonster(int Index, short Class);
	int Key;
	float Rot;
private:
	bool Rotating;
	bool Zoomming;
	float LimitZoom[4];
	float rot[3];
};

extern cCharacter character;