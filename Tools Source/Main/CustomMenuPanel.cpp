#include "stdafx.h"
#include "CustomMenuPanel.h"
#include "MuClientAPI.h"
#include "MuConstants.h"
#include "UIBase.h"
#include "Protect.h"
#include "CustomEventTime.h"
#include "CustomCommands.h"
#include "CustomRanking.h"

CCustomMenuPanel gCustomMenuPanel;

// -------------------------------------------------------------------------------
// Constructor / Destructor
// -------------------------------------------------------------------------------

CCustomMenuPanel::CCustomMenuPanel()
{
	m_isOpen = false;
	m_initialized = false;
	m_wasMousePressed = false;
	m_lastClickTime = 0;

	// Posicion centrada del panel
	m_panelWidth = 200.0f;
	m_panelHeight = 310.0f;
	m_panelX = 30.0f;
	m_panelY = 100.0f;

	// Inicializar finanzas
	memset(&m_finances, 0, sizeof(m_finances));

	// Inicializar botones
	memset(m_buttons, 0, sizeof(m_buttons));
}

CCustomMenuPanel::~CCustomMenuPanel()
{
}

// -------------------------------------------------------------------------------
// Inicializacion
// -------------------------------------------------------------------------------

void CCustomMenuPanel::Load()
{
	if (m_initialized)
		return;

	// Configurar botones
	const char* buttonNames[MAX_MENU_BUTTONS] = {
		"Events",
		"Buy VIP",
		"Ranking",
		"Commands",
		"Jewel Bank",
		"Options"
	};

	float btnY = m_panelY + 85.0f;
	float btnHeight = 30.0f;
	float btnSpacing = 5.0f;
	float btnMargin = 15.0f;

	for (int i = 0; i < MAX_MENU_BUTTONS; i++)
	{
		m_buttons[i].Type = i;
		strncpy_s(m_buttons[i].Name, buttonNames[i], 31);
		m_buttons[i].X = m_panelX + btnMargin;
		m_buttons[i].Y = btnY + (i * (btnHeight + btnSpacing));
		m_buttons[i].Width = m_panelWidth - (btnMargin * 2);
		m_buttons[i].Height = btnHeight;
		m_buttons[i].Enabled = true;
		m_buttons[i].Hover = false;
	}

	m_initialized = true;
}

// -------------------------------------------------------------------------------
// Abrir/Cerrar Panel
// -------------------------------------------------------------------------------

void CCustomMenuPanel::OpenPanel()
{
	m_isOpen = true;
	RequestFinances();
}

void CCustomMenuPanel::ClosePanel()
{
	m_isOpen = false;
	// Resetear cursor focus al cerrar el panel
	gMuClientApi.SetCursorFocus() = 0;
}

void CCustomMenuPanel::TogglePanel()
{
	if (m_isOpen)
		ClosePanel();
	else
		OpenPanel();
}

// -------------------------------------------------------------------------------
// Solicitar finanzas al servidor
// -------------------------------------------------------------------------------

void CCustomMenuPanel::RequestFinances()
{
	PMSG_CUSTOM_FINANCES_SEND pMsg;
	pMsg.header.set(0xF3, 0xE9, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
}

// -------------------------------------------------------------------------------
// Recibir finanzas del servidor
// -------------------------------------------------------------------------------

void CCustomMenuPanel::GCReqFinances(PMSG_CUSTOM_FINANCES_RECV* lpMsg)
{
	m_finances.Cash = lpMsg->Cash;
	m_finances.Gold = lpMsg->Gold;
	m_finances.PcPoint = lpMsg->PcPoint;
}

// -------------------------------------------------------------------------------
// Renderizado principal
// -------------------------------------------------------------------------------

void CCustomMenuPanel::Render()
{
	if (!m_initialized)
		Load();

	if (!m_isOpen)
		return;

	// No renderizar si hay ventanas criticas abiertas
	if (gUIBase.CheckWindow(static_cast<int>(WindowType::CashShop)) ||
		gUIBase.CheckWindow(static_cast<int>(WindowType::FullMap)))
	{
		return;
	}

	ProcessInput();
	DrawPanel();
}

// -------------------------------------------------------------------------------
// Dibujar Panel Principal
// -------------------------------------------------------------------------------

void CCustomMenuPanel::DrawPanel()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	float x = m_panelX;
	float y = m_panelY;
	float w = m_panelWidth;
	float h = m_panelHeight;

	// Bloquear clicks hacia el fondo cuando el mouse esta sobre el panel
	int mouseX = gMuClientApi.CursorX();
	int mouseY = gMuClientApi.CursorY();
	if (mouseX >= x && mouseX <= x + w && mouseY >= y && mouseY <= y + h)
	{
		gMuClientApi.SetCursorFocus() = 1;
	}
	else
	{
		gMuClientApi.SetCursorFocus() = 0;
	}

	gMuClientApi.SetBlend(1);

	// Fondo del panel
	glColor4f(0.0f, 0.0f, 0.0f, 0.85f);
	gMuClientApi.DrawBarForm(x, y, w, h, 0.0f, 0);

	// Borde exterior dorado
	glColor4f(0.6f, 0.5f, 0.2f, 1.0f);
	gMuClientApi.DrawBarForm(x, y, w, 2, 0.0f, 0);                // Top
	gMuClientApi.DrawBarForm(x, y + h - 2, w, 2, 0.0f, 0);       // Bottom
	gMuClientApi.DrawBarForm(x, y, 2, h, 0.0f, 0);               // Left
	gMuClientApi.DrawBarForm(x + w - 2, y, 2, h, 0.0f, 0);       // Right

	// Borde interior
	glColor4f(0.3f, 0.25f, 0.1f, 1.0f);
	gMuClientApi.DrawBarForm(x + 3, y + 3, w - 6, 1, 0.0f, 0);
	gMuClientApi.DrawBarForm(x + 3, y + h - 4, w - 6, 1, 0.0f, 0);
	gMuClientApi.DrawBarForm(x + 3, y + 3, 1, h - 6, 0.0f, 0);
	gMuClientApi.DrawBarForm(x + w - 4, y + 3, 1, h - 6, 0.0f, 0);

	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();

	// Dibujar secciones
	DrawTitleBar();
	DrawFinancesSection();
	DrawButtons();

	glPopAttrib();
}

// -------------------------------------------------------------------------------
// Dibujar Barra de Titulo
// -------------------------------------------------------------------------------

void CCustomMenuPanel::DrawTitleBar()
{
	float x = m_panelX;
	float y = m_panelY;
	float w = m_panelWidth;

	// Fondo de la barra de titulo
	gMuClientApi.SetBlend(1);
	glColor4f(0.15f, 0.12f, 0.08f, 0.95f);
	gMuClientApi.DrawBarForm(x + 5, y + 5, w - 10, 22, 0.0f, 0);

	// Linea decorativa inferior
	glColor4f(0.6f, 0.5f, 0.2f, 0.8f);
	gMuClientApi.DrawBarForm(x + 5, y + 26, w - 10, 1, 0.0f, 0);
	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();

	// Titulo "Menu"
	gUIBase.DrawFormat(g_muColors.Gold, (int)x, (int)y + 10, (int)w, 3, "Menu");

	// Boton X para cerrar
	float closeX = x + w - 25;
	float closeY = y + 7;
	float closeSize = 16;

	bool hoverClose = IsMouseOver(closeX, closeY, closeSize, closeSize);

	gMuClientApi.SetBlend(1);
	if (hoverClose)
	{
		glColor4f(0.5f, 0.2f, 0.2f, 0.9f);
		gMuClientApi.DrawBarForm(closeX, closeY, closeSize, closeSize, 0.0f, 0);
	}
	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();

	DWORD closeColor = hoverClose ? g_muColors.Red : g_muColors.White;
	gUIBase.DrawFormat(closeColor, (int)closeX, (int)closeY + 3, (int)closeSize, 3, "X");
}

// -------------------------------------------------------------------------------
// Dibujar Seccion de Finanzas
// -------------------------------------------------------------------------------

void CCustomMenuPanel::DrawFinancesSection()
{
	float x = m_panelX;
	float y = m_panelY + 32;
	float w = m_panelWidth;

	// Fondo de la seccion
	gMuClientApi.SetBlend(1);
	glColor4f(0.1f, 0.08f, 0.05f, 0.9f);
	gMuClientApi.DrawBarForm(x + 5, y, w - 10, 45, 0.0f, 0);

	// Linea decorativa
	glColor4f(0.6f, 0.5f, 0.2f, 0.5f);
	gMuClientApi.DrawBarForm(x + 10, y + 18, w - 20, 1, 0.0f, 0);
	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();

	// Titulo "My Finances:"
	gUIBase.DrawFormat(g_muColors.Gold, (int)x, (int)y + 3, (int)w, 3, "My Finances:");

	// Valores de finanzas
	char financeText[128];
	sprintf_s(financeText, "Cash:  %d    Gold:  %d    PcPoint:  %d",
		m_finances.Cash, m_finances.Gold, m_finances.PcPoint);

	// Dibujar cada valor con color diferente
	float valY = y + 25;

	// Cash
	gUIBase.DrawFormat(g_muColors.White, (int)x + 15, (int)valY, 40, 1, "Cash:");
	char cashStr[16];
	sprintf_s(cashStr, "%d", m_finances.Cash);
	gUIBase.DrawFormat(g_muColors.Gold, (int)x + 50, (int)valY, 35, 1, cashStr);

	// Gold
	gUIBase.DrawFormat(g_muColors.White, (int)x + 85, (int)valY, 35, 1, "Gold:");
	char goldStr[16];
	sprintf_s(goldStr, "%d", m_finances.Gold);
	gUIBase.DrawFormat(g_muColors.Gold, (int)x + 115, (int)valY, 30, 1, goldStr);

	// PcPoint
	gUIBase.DrawFormat(g_muColors.White, (int)x + 140, (int)valY, 50, 1, "PcPoint:");
	char pcpStr[16];
	sprintf_s(pcpStr, "%d", m_finances.PcPoint);
	gUIBase.DrawFormat(g_muColors.Gold, (int)x + 185, (int)valY, 30, 1, pcpStr);
}

// -------------------------------------------------------------------------------
// Dibujar Botones
// -------------------------------------------------------------------------------

void CCustomMenuPanel::DrawButtons()
{
	for (int i = 0; i < MAX_MENU_BUTTONS; i++)
	{
		if (m_buttons[i].Enabled)
		{
			DrawButton(&m_buttons[i]);
		}
	}
}

void CCustomMenuPanel::DrawButton(MENU_PANEL_BUTTON* pBtn)
{
	if (!pBtn)
		return;

	float x = pBtn->X;
	float y = pBtn->Y;
	float w = pBtn->Width;
	float h = pBtn->Height;

	bool hover = IsMouseOver(x, y, w, h);
	pBtn->Hover = hover;

	gMuClientApi.SetBlend(1);

	// Fondo del boton
	if (hover)
		glColor4f(0.2f, 0.18f, 0.12f, 0.95f);
	else
		glColor4f(0.1f, 0.08f, 0.05f, 0.9f);

	gMuClientApi.DrawBarForm(x, y, w, h, 0.0f, 0);

	// Borde del boton
	glColor4f(0.4f, 0.35f, 0.2f, 0.9f);
	gMuClientApi.DrawBarForm(x, y, w, 1, 0.0f, 0);           // Top
	gMuClientApi.DrawBarForm(x, y + h - 1, w, 1, 0.0f, 0);   // Bottom
	gMuClientApi.DrawBarForm(x, y, 1, h, 0.0f, 0);           // Left
	gMuClientApi.DrawBarForm(x + w - 1, y, 1, h, 0.0f, 0);   // Right

	// Efecto de brillo superior
	if (hover)
	{
		glColor4f(1.0f, 0.9f, 0.7f, 0.15f);
		gMuClientApi.DrawBarForm(x + 1, y + 1, w - 2, h / 3, 0.0f, 0);
	}

	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();

	// Texto del boton
	DWORD textColor = hover ? g_muColors.White : g_muColors.LightGray;
	gUIBase.DrawFormat(textColor, (int)x, (int)y + 10, (int)w, 3, pBtn->Name);
}

// -------------------------------------------------------------------------------
// Procesamiento de Input
// -------------------------------------------------------------------------------

void CCustomMenuPanel::ProcessInput()
{
	if (!IsMouseClicked())
		return;

	float x = m_panelX;
	float y = m_panelY;
	float w = m_panelWidth;

	// Verificar click en boton X
	float closeX = x + w - 25;
	float closeY = y + 7;
	if (IsMouseOver(closeX, closeY, 16, 16))
	{
		ClosePanel();
		return;
	}

	// Verificar click en botones
	for (int i = 0; i < MAX_MENU_BUTTONS; i++)
	{
		if (m_buttons[i].Enabled && m_buttons[i].Hover)
		{
			ExecuteButtonAction(m_buttons[i].Type);
			return;
		}
	}
}

bool CCustomMenuPanel::IsMouseOver(float x, float y, float w, float h)
{
	int mouseX = gMuClientApi.CursorX();
	int mouseY = gMuClientApi.CursorY();
	return (mouseX >= x && mouseX <= x + w && mouseY >= y && mouseY <= y + h);
}

bool CCustomMenuPanel::IsMouseClicked()
{
	bool isPressed = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;
	bool clicked = isPressed && !m_wasMousePressed;
	m_wasMousePressed = isPressed;

	if (clicked)
	{
		DWORD currentTime = GetTickCount();
		if (currentTime - m_lastClickTime < 200)
			return false;
		m_lastClickTime = currentTime;
	}
	return clicked;
}

// -------------------------------------------------------------------------------
// Ejecutar Accion del Boton
// -------------------------------------------------------------------------------

void CCustomMenuPanel::ExecuteButtonAction(int btnType)
{
	switch (btnType)
	{
		case MENU_BTN_EVENTS:
			gCustomEventTime.OpenWindow();
			break;

		case MENU_BTN_BUYVIP:
			// TODO: Abrir ventana de compra VIP o ejecutar comando
			break;

		case MENU_BTN_RANKING:
			gCustomRanking.OpenPanel();
			break;

		case MENU_BTN_COMMANDS:
			gCustomCommands.OpenPanel();
			break;

		case MENU_BTN_JEWELBANK:
			// TODO: Abrir Jewel Bank
			break;

		case MENU_BTN_OPTIONS:
			// TODO: Abrir opciones
			break;

		default:
			break;
	}
}
