#include "stdafx.h"
#include "CustomCommands.h"
#include "MuClientAPI.h"
#include "MuConstants.h"
#include "UIBase.h"
#include "Protect.h"

CCustomCommands gCustomCommands;

// -------------------------------------------------------------------------------
// Constructor / Destructor
// -------------------------------------------------------------------------------

CCustomCommands::CCustomCommands()
{
	m_isOpen = false;
	m_initialized = false;
	m_wasMousePressed = false;
	m_lastClickTime = 0;
	m_scrollOffset = 0;

	// Posicion del panel
	m_panelWidth = 330.0f;
	m_panelHeight = 350.0f;
	m_panelX = 250.0f;
	m_panelY = 80.0f;
}

CCustomCommands::~CCustomCommands()
{
}

// -------------------------------------------------------------------------------
// Inicializacion - Cargar comandos predefinidos
// -------------------------------------------------------------------------------

void CCustomCommands::Load()
{
	if (m_initialized)
		return;

	m_commands.clear();

	// Comandos normales
	COMMAND_INFO cmd;

	// Comandos basicos
	strcpy_s(cmd.Command, "/move <Map>");
	strcpy_s(cmd.Description, "Move to a map");
	cmd.Type = CMD_TYPE_NORMAL;
	cmd.Available = true;
	m_commands.push_back(cmd);

	strcpy_s(cmd.Command, "/post <Msg>");
	strcpy_s(cmd.Description, "Post a message in global chat");
	cmd.Type = CMD_TYPE_NORMAL;
	m_commands.push_back(cmd);

	strcpy_s(cmd.Command, "/s <points>");
	strcpy_s(cmd.Description, "Add points in Str");
	cmd.Type = CMD_TYPE_NORMAL;
	m_commands.push_back(cmd);

	strcpy_s(cmd.Command, "/a <points>");
	strcpy_s(cmd.Description, "Add points in Agi");
	cmd.Type = CMD_TYPE_NORMAL;
	m_commands.push_back(cmd);

	strcpy_s(cmd.Command, "/v <points>");
	strcpy_s(cmd.Description, "Add points in Vit");
	cmd.Type = CMD_TYPE_NORMAL;
	m_commands.push_back(cmd);

	strcpy_s(cmd.Command, "/e <points>");
	strcpy_s(cmd.Description, "Add points in Ene");
	cmd.Type = CMD_TYPE_NORMAL;
	m_commands.push_back(cmd);

	strcpy_s(cmd.Command, "/c <points>");
	strcpy_s(cmd.Description, "Add points in Com");
	cmd.Type = CMD_TYPE_NORMAL;
	m_commands.push_back(cmd);

	strcpy_s(cmd.Command, "/pk");
	strcpy_s(cmd.Description, "Clear PK");
	cmd.Type = CMD_TYPE_NORMAL;
	m_commands.push_back(cmd);

	strcpy_s(cmd.Command, "/zen <value>");
	strcpy_s(cmd.Description, "Add zen");
	cmd.Type = CMD_TYPE_NORMAL;
	m_commands.push_back(cmd);

	strcpy_s(cmd.Command, "/evo");
	strcpy_s(cmd.Description, "Evolve char class");
	cmd.Type = CMD_TYPE_NORMAL;
	m_commands.push_back(cmd);

	strcpy_s(cmd.Command, "/bau <num>");
	strcpy_s(cmd.Description, "Change warehouse");
	cmd.Type = CMD_TYPE_NORMAL;
	m_commands.push_back(cmd);

	strcpy_s(cmd.Command, "/reset [auto]");
	strcpy_s(cmd.Description, "Reset character");
	cmd.Type = CMD_TYPE_NORMAL;
	m_commands.push_back(cmd);

	strcpy_s(cmd.Command, "/mreset");
	strcpy_s(cmd.Description, "Master reset");
	cmd.Type = CMD_TYPE_NORMAL;
	m_commands.push_back(cmd);

	// Comandos VIP1
	strcpy_s(cmd.Command, "/clearinv");
	strcpy_s(cmd.Description, "(VIP1)Clear inventory");
	cmd.Type = CMD_TYPE_VIP1;
	m_commands.push_back(cmd);

	strcpy_s(cmd.Command, "/marry to <player>");
	strcpy_s(cmd.Description, "(VIP1)Marry to a player");
	cmd.Type = CMD_TYPE_VIP1;
	m_commands.push_back(cmd);

	strcpy_s(cmd.Command, "/openware");
	strcpy_s(cmd.Description, "(VIP1)Open warehouse");
	cmd.Type = CMD_TYPE_VIP1;
	m_commands.push_back(cmd);

	strcpy_s(cmd.Command, "/readd");
	strcpy_s(cmd.Description, "(VIP1)ReAdd stats");
	cmd.Type = CMD_TYPE_VIP1;
	m_commands.push_back(cmd);

	// Comandos VIP2
	strcpy_s(cmd.Command, "/classe <type>");
	strcpy_s(cmd.Description, "(VIP2)Change character class");
	cmd.Type = CMD_TYPE_VIP2;
	m_commands.push_back(cmd);

	strcpy_s(cmd.Command, "/changename <NewName>");
	strcpy_s(cmd.Description, "(VIP2)Change character name");
	cmd.Type = CMD_TYPE_VIP2;
	m_commands.push_back(cmd);

	// Mas comandos normales
	strcpy_s(cmd.Command, "/pick <type>");
	strcpy_s(cmd.Description, "Auto get items");
	cmd.Type = CMD_TYPE_NORMAL;
	m_commands.push_back(cmd);

	strcpy_s(cmd.Command, "/help");
	strcpy_s(cmd.Description, "Summon help");
	cmd.Type = CMD_TYPE_NORMAL;
	m_commands.push_back(cmd);

	m_initialized = true;
}

// -------------------------------------------------------------------------------
// Abrir/Cerrar Panel
// -------------------------------------------------------------------------------

void CCustomCommands::OpenPanel()
{
	m_isOpen = true;
	m_scrollOffset = 0;
}

void CCustomCommands::ClosePanel()
{
	m_isOpen = false;
	// Resetear cursor focus al cerrar el panel
	gMuClientApi.SetCursorFocus() = 0;
}

void CCustomCommands::TogglePanel()
{
	if (m_isOpen)
		ClosePanel();
	else
		OpenPanel();
}

// -------------------------------------------------------------------------------
// Solicitar comandos al servidor (opcional - para comandos dinamicos)
// -------------------------------------------------------------------------------

void CCustomCommands::RequestCommands()
{
	PMSG_CUSTOM_COMMANDS_SEND pMsg;
	pMsg.header.set(0xF3, 0xEA, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
}

// -------------------------------------------------------------------------------
// Recibir comandos del servidor (opcional)
// -------------------------------------------------------------------------------

void CCustomCommands::GCReqCommands(PMSG_CUSTOM_COMMANDS_RECV* lpMsg)
{
	m_commands.clear();

	CUSTOM_COMMAND_DATA* pData = (CUSTOM_COMMAND_DATA*)(((BYTE*)lpMsg) + sizeof(PMSG_CUSTOM_COMMANDS_RECV));

	for (int i = 0; i < lpMsg->count; i++)
	{
		COMMAND_INFO cmd;
		strncpy_s(cmd.Command, pData[i].Command, 31);
		strncpy_s(cmd.Description, pData[i].Description, 63);
		cmd.Type = pData[i].Type;
		cmd.Available = true;
		m_commands.push_back(cmd);
	}
}

// -------------------------------------------------------------------------------
// Renderizado principal
// -------------------------------------------------------------------------------

void CCustomCommands::Render()
{
	if (!m_initialized)
		Load();

	if (!m_isOpen)
		return;

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

void CCustomCommands::DrawPanel()
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
	glColor4f(0.0f, 0.0f, 0.0f, 0.9f);
	gMuClientApi.DrawBarForm(x, y, w, h, 0.0f, 0);

	// Borde exterior dorado
	glColor4f(0.6f, 0.5f, 0.2f, 1.0f);
	gMuClientApi.DrawBarForm(x, y, w, 2, 0.0f, 0);
	gMuClientApi.DrawBarForm(x, y + h - 2, w, 2, 0.0f, 0);
	gMuClientApi.DrawBarForm(x, y, 2, h, 0.0f, 0);
	gMuClientApi.DrawBarForm(x + w - 2, y, 2, h, 0.0f, 0);

	// Borde interior
	glColor4f(0.3f, 0.25f, 0.1f, 1.0f);
	gMuClientApi.DrawBarForm(x + 3, y + 3, w - 6, 1, 0.0f, 0);
	gMuClientApi.DrawBarForm(x + 3, y + h - 4, w - 6, 1, 0.0f, 0);
	gMuClientApi.DrawBarForm(x + 3, y + 3, 1, h - 6, 0.0f, 0);
	gMuClientApi.DrawBarForm(x + w - 4, y + 3, 1, h - 6, 0.0f, 0);

	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();

	DrawTitleBar();
	DrawCommandList();
	DrawScrollBar();

	glPopAttrib();
}

// -------------------------------------------------------------------------------
// Dibujar Barra de Titulo
// -------------------------------------------------------------------------------

void CCustomCommands::DrawTitleBar()
{
	float x = m_panelX;
	float y = m_panelY;
	float w = m_panelWidth;

	gMuClientApi.SetBlend(1);
	glColor4f(0.15f, 0.12f, 0.08f, 0.95f);
	gMuClientApi.DrawBarForm(x + 5, y + 5, w - 10, 22, 0.0f, 0);

	glColor4f(0.6f, 0.5f, 0.2f, 0.8f);
	gMuClientApi.DrawBarForm(x + 5, y + 26, w - 10, 1, 0.0f, 0);
	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();

	gUIBase.DrawFormat(g_muColors.Gold, (int)x, (int)y + 10, (int)w, 3, "Commands");

	// Boton X
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
// Dibujar Lista de Comandos
// -------------------------------------------------------------------------------

void CCustomCommands::DrawCommandList()
{
	float x = m_panelX + 10;
	float y = m_panelY + 35;
	float w = m_panelWidth - 30;
	float lineHeight = 16.0f;

	int visibleCount = 0;
	int startIdx = m_scrollOffset;

	for (size_t i = startIdx; i < m_commands.size() && visibleCount < MAX_VISIBLE_COMMANDS; i++)
	{
		COMMAND_INFO& cmd = m_commands[i];

		float lineY = y + (visibleCount * lineHeight);

		// Determinar color segun tipo
		DWORD cmdColor;
		switch (cmd.Type)
		{
			case CMD_TYPE_VIP1:
			case CMD_TYPE_VIP2:
				cmdColor = g_muColors.Green;
				break;
			case CMD_TYPE_ADMIN:
				cmdColor = g_muColors.Red;
				break;
			default:
				cmdColor = g_muColors.Gold;
				break;
		}

		// Dibujar comando
		gUIBase.DrawFormat(cmdColor, (int)x, (int)lineY, 120, 1, cmd.Command);

		// Dibujar descripcion
		DWORD descColor = (cmd.Type == CMD_TYPE_VIP1 || cmd.Type == CMD_TYPE_VIP2) ? g_muColors.Green : g_muColors.LightGray;
		gUIBase.DrawFormat(descColor, (int)x + 125, (int)lineY, 180, 1, cmd.Description);

		visibleCount++;
	}
}

// -------------------------------------------------------------------------------
// Dibujar Barra de Scroll
// -------------------------------------------------------------------------------

void CCustomCommands::DrawScrollBar()
{
	if (m_commands.size() <= MAX_VISIBLE_COMMANDS)
		return;

	float x = m_panelX + m_panelWidth - 18;
	float y = m_panelY + 35;
	float w = 10;
	float h = m_panelHeight - 50;

	gMuClientApi.SetBlend(1);

	// Fondo del scroll
	glColor4f(0.1f, 0.1f, 0.1f, 0.8f);
	gMuClientApi.DrawBarForm(x, y, w, h, 0.0f, 0);

	// Calcular posicion del thumb
	int maxScroll = (int)m_commands.size() - MAX_VISIBLE_COMMANDS;
	float thumbHeight = h * ((float)MAX_VISIBLE_COMMANDS / (float)m_commands.size());
	float thumbY = y + ((float)m_scrollOffset / (float)maxScroll) * (h - thumbHeight);

	// Thumb del scroll
	glColor4f(0.5f, 0.45f, 0.3f, 0.9f);
	gMuClientApi.DrawBarForm(x, thumbY, w, thumbHeight, 0.0f, 0);

	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();
}

// -------------------------------------------------------------------------------
// Procesamiento de Input
// -------------------------------------------------------------------------------

void CCustomCommands::ProcessInput()
{
	// Scroll con rueda del mouse
	int mouseX = gMuClientApi.CursorX();
	int mouseY = gMuClientApi.CursorY();

	if (mouseX >= m_panelX && mouseX <= m_panelX + m_panelWidth &&
		mouseY >= m_panelY && mouseY <= m_panelY + m_panelHeight)
	{
		// Detectar scroll wheel (esto depende de la implementacion del cliente)
		// Por ahora usamos teclas de flecha o clicks
	}

	if (!IsMouseClicked())
		return;

	float x = m_panelX;
	float y = m_panelY;
	float w = m_panelWidth;

	// Click en boton X
	float closeX = x + w - 25;
	float closeY = y + 7;
	if (IsMouseOver(closeX, closeY, 16, 16))
	{
		ClosePanel();
		return;
	}

	// Click en area de scroll para subir/bajar
	float scrollX = m_panelX + m_panelWidth - 18;
	float scrollY = m_panelY + 35;
	float scrollH = m_panelHeight - 50;

	if (IsMouseOver(scrollX, scrollY, 10, scrollH / 2))
	{
		ScrollUp();
	}
	else if (IsMouseOver(scrollX, scrollY + scrollH / 2, 10, scrollH / 2))
	{
		ScrollDown();
	}
}

void CCustomCommands::ScrollUp()
{
	if (m_scrollOffset > 0)
		m_scrollOffset--;
}

void CCustomCommands::ScrollDown()
{
	int maxScroll = (int)m_commands.size() - MAX_VISIBLE_COMMANDS;
	if (m_scrollOffset < maxScroll)
		m_scrollOffset++;
}

bool CCustomCommands::IsMouseOver(float x, float y, float w, float h)
{
	int mouseX = gMuClientApi.CursorX();
	int mouseY = gMuClientApi.CursorY();
	return (mouseX >= x && mouseX <= x + w && mouseY >= y && mouseY <= y + h);
}

bool CCustomCommands::IsMouseClicked()
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
