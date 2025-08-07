// ServerDisplayer.h: interface for the CServerDisplayer class.
// Enhanced Version with Modern UI
//////////////////////////////////////////////////////////////////////

#pragma once

#define MAX_LOG_TEXT_LINE 100
#define MAX_LOG_TEXT_SIZE 120

enum eLogColor
{
	LOG_WHITE = 0,
	LOG_RED = 1,
	LOG_GREEN = 2,
	LOG_BLUE = 3,
};

struct LOG_DISPLAY_INFO
{
	char text[MAX_LOG_TEXT_SIZE];
	eLogColor color;
};

class CServerDisplayer
{
public:
	CServerDisplayer();
	virtual ~CServerDisplayer();
	void Init(HWND hWnd);
	void Run();
	void SetWindowName();
	void PaintAllInfo();
	void PaintTitleBar();
	void PaintStatusSection();
	void PaintInfoBar();
	void LogTextPaint();
	void LogAddText(eLogColor color, char* text, int size);
	void DrawGradientRect(HDC hdc, RECT rect, COLORREF color1, COLORREF color2, bool vertical = true);
	DWORD GetUptime();
private:
	HWND m_hwnd;
	HFONT m_font;
	HFONT m_titleFont;
	HFONT m_infoFont;
	HBRUSH m_brush[6];  // Más brushes para diferentes colores
	HPEN m_pen[4];      // Pens para bordes
	LOG_DISPLAY_INFO m_log[MAX_LOG_TEXT_LINE];
	int m_count;
	char m_DisplayerText[2][64];
	DWORD m_startTime;
	int m_animationCounter;
};

extern CServerDisplayer gServerDisplayer;