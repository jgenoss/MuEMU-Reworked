#pragma once
// ----------------------------------------------------------------------------------------------

class Controller
{
public:
	bool	Load();
	// ----
	static	LRESULT WINAPI Mouse(int Code, WPARAM wParam, LPARAM lParam);
	static	LRESULT WINAPI Keyboard(int Code, WPARAM wParam, LPARAM lParam);
	static	LRESULT WINAPI Window(HWND Window, DWORD Message, WPARAM wParam, LPARAM lParam);
	// ----
	HINSTANCE	Instance;
	WPARAM	wMouse;
	WPARAM wKeyBord;
private:
	HHOOK		MouseHook;
	HHOOK		KeyboardHook;

	// ----
}; extern Controller gController;
#if(NOTICE_MES==1)
extern char Notice_1[1024];
extern char Notice_2[1024];
extern char CameraOn[1024];
extern char CameraOff[1024];
extern char CameraNotAc[1024];
extern char CameraDefault[1024];
extern char GlowOn[1024];
extern char GlowOff[1024];
extern char AutoOn[1024];
extern char AutoOff[1024];

#endif
// ----------------------------------------------------------------------------------------------