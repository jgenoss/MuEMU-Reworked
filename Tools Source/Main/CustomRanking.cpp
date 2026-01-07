#include "stdafx.h"
#include "CustomRanking.h"
#include "MuClientAPI.h"
#include "MuConstants.h"
#include "UIBase.h"
#include "Protect.h"

CCustomRanking gCustomRanking;

// -------------------------------------------------------------------------------
// Constructor / Destructor
// -------------------------------------------------------------------------------

CCustomRanking::CCustomRanking()
{
	m_isOpen = false;
	m_initialized = false;
	m_wasMousePressed = false;
	m_lastClickTime = 0;
	m_currentPage = 1;
	m_totalPages = 1;
	memset(m_welcomeMessage, 0, sizeof(m_welcomeMessage));

	// Posicion del panel (mas grande, centrado)
	m_panelWidth = 480.0f;
	m_panelHeight = 320.0f;
	m_panelX = 80.0f;
	m_panelY = 100.0f;
}

CCustomRanking::~CCustomRanking()
{
}

// -------------------------------------------------------------------------------
// Inicializacion
// -------------------------------------------------------------------------------

void CCustomRanking::Load()
{
	if (m_initialized)
		return;

	strcpy_s(m_welcomeMessage, "Bienvenido a MU ZXGAMES");
	m_initialized = true;
}

// -------------------------------------------------------------------------------
// Abrir/Cerrar Panel
// -------------------------------------------------------------------------------

void CCustomRanking::OpenPanel()
{
	m_isOpen = true;
	m_currentPage = 1;
	RequestRanking(1);
}

void CCustomRanking::ClosePanel()
{
	m_isOpen = false;
}

void CCustomRanking::TogglePanel()
{
	if (m_isOpen)
		ClosePanel();
	else
		OpenPanel();
}

// -------------------------------------------------------------------------------
// Solicitar ranking al servidor
// -------------------------------------------------------------------------------

void CCustomRanking::RequestRanking(int page)
{
	PMSG_CUSTOM_RANKING_SEND pMsg;
	pMsg.header.set(0xF3, 0xEB, sizeof(pMsg));
	pMsg.page = (BYTE)page;
	gMuClientApi.DataSend((BYTE*)&pMsg, sizeof(pMsg));
}

// -------------------------------------------------------------------------------
// Recibir ranking del servidor
// -------------------------------------------------------------------------------

void CCustomRanking::GCReqRanking(PMSG_CUSTOM_RANKING_RECV* lpMsg)
{
	m_entries.clear();
	m_currentPage = lpMsg->page;
	m_totalPages = lpMsg->totalPages;

	if (m_totalPages < 1) m_totalPages = 1;

	strncpy_s(m_welcomeMessage, lpMsg->WelcomeMessage, 63);

	CUSTOM_RANKING_DATA* pData = (CUSTOM_RANKING_DATA*)(((BYTE*)lpMsg) + sizeof(PMSG_CUSTOM_RANKING_RECV));

	for (int i = 0; i < lpMsg->count; i++)
	{
		RANKING_ENTRY entry;
		entry.Rank = pData[i].Rank;
		strncpy_s(entry.Name, pData[i].Name, 10);
		strncpy_s(entry.Class, GetClassName(pData[i].Class), 19);
		entry.Level = pData[i].Level;
		entry.Reset = pData[i].Reset;
		strncpy_s(entry.Map, GetMapName(pData[i].Map), 19);
		strncpy_s(entry.Guild, pData[i].Guild, 8);
		m_entries.push_back(entry);
	}
}

// -------------------------------------------------------------------------------
// Renderizado principal
// -------------------------------------------------------------------------------

void CCustomRanking::Render()
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

void CCustomRanking::DrawPanel()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	float x = m_panelX;
	float y = m_panelY;
	float w = m_panelWidth;
	float h = m_panelHeight;

	// Bloquear clicks hacia el fondo
	int mouseX = gMuClientApi.CursorX();
	int mouseY = gMuClientApi.CursorY();
	if (mouseX >= x && mouseX <= x + w && mouseY >= y && mouseY <= y + h)
	{
		gMuClientApi.SetCursorFocus() = 1;
	}

	gMuClientApi.SetBlend(1);

	// Fondo del panel (semi-transparente)
	glColor4f(0.0f, 0.0f, 0.0f, 0.75f);
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
	DrawTableHeader();
	DrawRankingList();
	DrawWelcomeMessage();
	DrawPagination();

	glPopAttrib();
}

// -------------------------------------------------------------------------------
// Dibujar Barra de Titulo
// -------------------------------------------------------------------------------

void CCustomRanking::DrawTitleBar()
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

	gUIBase.DrawFormat(g_muColors.Gold, (int)x, (int)y + 10, (int)w, 3, "Ranking User");

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
// Dibujar Encabezado de Tabla
// -------------------------------------------------------------------------------

void CCustomRanking::DrawTableHeader()
{
	float x = m_panelX + 10;
	float y = m_panelY + 35;

	// Fondo del encabezado
	gMuClientApi.SetBlend(1);
	glColor4f(0.1f, 0.08f, 0.05f, 0.9f);
	gMuClientApi.DrawBarForm(x - 5, y - 2, m_panelWidth - 10, 18, 0.0f, 0);
	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();

	// Columnas: (N) Name Class Level Reset Map Guild
	gUIBase.DrawFormat(g_muColors.Gold, (int)x, (int)y, 25, 1, "(N)");
	gUIBase.DrawFormat(g_muColors.Gold, (int)x + 25, (int)y, 70, 1, "Name");
	gUIBase.DrawFormat(g_muColors.Gold, (int)x + 100, (int)y, 80, 1, "Class");
	gUIBase.DrawFormat(g_muColors.Gold, (int)x + 185, (int)y, 40, 1, "Level");
	gUIBase.DrawFormat(g_muColors.Gold, (int)x + 235, (int)y, 45, 1, "Reset");
	gUIBase.DrawFormat(g_muColors.Gold, (int)x + 290, (int)y, 70, 1, "Map");
	gUIBase.DrawFormat(g_muColors.Gold, (int)x + 365, (int)y, 60, 1, "Guild");
}

// -------------------------------------------------------------------------------
// Dibujar Lista de Ranking
// -------------------------------------------------------------------------------

void CCustomRanking::DrawRankingList()
{
	float x = m_panelX + 10;
	float y = m_panelY + 58;
	float lineHeight = 22.0f;

	for (size_t i = 0; i < m_entries.size() && i < RANKING_PER_PAGE; i++)
	{
		RANKING_ENTRY& entry = m_entries[i];
		float lineY = y + (i * lineHeight);

		// Color segun ranking
		DWORD rankColor = GetRankColor(entry.Rank);
		DWORD textColor = g_muColors.White;

		// Numero de ranking
		char rankStr[8];
		sprintf_s(rankStr, "%d", entry.Rank);
		gUIBase.DrawFormat(rankColor, (int)x, (int)lineY, 20, 1, rankStr);

		// Nombre
		gUIBase.DrawFormat(textColor, (int)x + 25, (int)lineY, 70, 1, entry.Name);

		// Clase
		gUIBase.DrawFormat(textColor, (int)x + 100, (int)lineY, 80, 1, entry.Class);

		// Nivel
		char levelStr[8];
		sprintf_s(levelStr, "%d", entry.Level);
		gUIBase.DrawFormat(textColor, (int)x + 185, (int)lineY, 40, 1, levelStr);

		// Resets
		char resetStr[16];
		sprintf_s(resetStr, "%d", entry.Reset);
		gUIBase.DrawFormat(textColor, (int)x + 235, (int)lineY, 45, 1, resetStr);

		// Mapa
		gUIBase.DrawFormat(g_muColors.Gold, (int)x + 290, (int)lineY, 70, 1, entry.Map);

		// Guild
		gUIBase.DrawFormat(textColor, (int)x + 365, (int)lineY, 60, 1, entry.Guild);
	}
}

// -------------------------------------------------------------------------------
// Dibujar Mensaje de Bienvenida
// -------------------------------------------------------------------------------

void CCustomRanking::DrawWelcomeMessage()
{
	float x = m_panelX;
	float y = m_panelY + m_panelHeight - 70;
	float w = m_panelWidth;

	// Fondo del mensaje
	gMuClientApi.SetBlend(1);
	glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
	gMuClientApi.DrawBarForm(x + 10, y, w - 20, 35, 0.0f, 0);
	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();

	// Mensaje
	gUIBase.DrawFormat(g_muColors.Gold, (int)x, (int)y + 5, (int)w, 3, m_welcomeMessage);

	// Segunda linea de ejemplo
	gUIBase.DrawFormat(g_muColors.Blue, (int)x, (int)y + 18, (int)w, 3, "MaxVoll foi o vencedor do sorteio. Parabens!");
}

// -------------------------------------------------------------------------------
// Dibujar Paginacion
// -------------------------------------------------------------------------------

void CCustomRanking::DrawPagination()
{
	float x = m_panelX;
	float y = m_panelY + m_panelHeight - 28;
	float w = m_panelWidth;

	// Fondo de paginacion
	gMuClientApi.SetBlend(1);
	glColor4f(0.15f, 0.12f, 0.08f, 0.95f);
	gMuClientApi.DrawBarForm(x + 5, y, w - 10, 22, 0.0f, 0);
	gMuClientApi.GLSwitchBlend();
	gMuClientApi.GLSwitch();

	// Boton Prev (<)
	float prevX = x + (w / 2) - 70;
	float btnY = y + 3;
	float btnW = 20;
	float btnH = 16;

	bool hoverPrev = IsMouseOver(prevX, btnY, btnW, btnH);
	DWORD prevColor = hoverPrev ? g_muColors.White : g_muColors.Gold;
	gUIBase.DrawFormat(prevColor, (int)prevX, (int)btnY + 2, (int)btnW, 3, "<");

	// Texto de pagina
	char pageText[32];
	sprintf_s(pageText, "Page: %d/%d", m_currentPage, m_totalPages);
	gUIBase.DrawFormat(g_muColors.Green, (int)x, (int)y + 5, (int)w, 3, pageText);

	// Boton Next (>)
	float nextX = x + (w / 2) + 50;
	bool hoverNext = IsMouseOver(nextX, btnY, btnW, btnH);
	DWORD nextColor = hoverNext ? g_muColors.White : g_muColors.Gold;
	gUIBase.DrawFormat(nextColor, (int)nextX, (int)btnY + 2, (int)btnW, 3, ">");
}

// -------------------------------------------------------------------------------
// Procesamiento de Input
// -------------------------------------------------------------------------------

void CCustomRanking::ProcessInput()
{
	if (!IsMouseClicked())
		return;

	float x = m_panelX;
	float y = m_panelY;
	float w = m_panelWidth;
	float h = m_panelHeight;

	// Click en boton X
	float closeX = x + w - 25;
	float closeY = y + 7;
	if (IsMouseOver(closeX, closeY, 16, 16))
	{
		ClosePanel();
		return;
	}

	// Click en paginacion
	float pagY = y + h - 28 + 3;
	float prevX = x + (w / 2) - 70;
	float nextX = x + (w / 2) + 50;

	if (IsMouseOver(prevX, pagY, 20, 16))
	{
		PrevPage();
		return;
	}

	if (IsMouseOver(nextX, pagY, 20, 16))
	{
		NextPage();
		return;
	}
}

void CCustomRanking::PrevPage()
{
	if (m_currentPage > 1)
	{
		m_currentPage--;
		RequestRanking(m_currentPage);
	}
}

void CCustomRanking::NextPage()
{
	if (m_currentPage < m_totalPages)
	{
		m_currentPage++;
		RequestRanking(m_currentPage);
	}
}

bool CCustomRanking::IsMouseOver(float x, float y, float w, float h)
{
	int mouseX = gMuClientApi.CursorX();
	int mouseY = gMuClientApi.CursorY();
	return (mouseX >= x && mouseX <= x + w && mouseY >= y && mouseY <= y + h);
}

bool CCustomRanking::IsMouseClicked()
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
// Utilidades
// -------------------------------------------------------------------------------

DWORD CCustomRanking::GetRankColor(int rank)
{
	switch (rank)
	{
		case 1: return g_muColors.Gold;      // #1 Dorado
		case 2: return g_muColors.Blue;      // #2 Azul
		case 3: return g_muColors.Red;       // #3 Rojo
		case 4: return g_muColors.Green;     // #4 Verde
		case 5: return g_muColors.Purple;    // #5 Purpura
		default: return g_muColors.White;
	}
}

const char* CCustomRanking::GetClassName(int classId)
{
	switch (classId)
	{
		case 0: return "Dark Wizard";
		case 1: return "Soul Master";
		case 2: return "Grand Master";
		case 3: return "Soul Wizard";
		case 16: return "Dark Knight";
		case 17: return "Blade Knight";
		case 18: return "Blade Master";
		case 19: return "Dragon Knight";
		case 32: return "Elf";
		case 33: return "Muse Elf";
		case 34: return "High Elf";
		case 35: return "Noble Elf";
		case 48: return "Magic Gladiator";
		case 49: return "Duel Master";
		case 50: return "Dual Master";
		case 64: return "Dark Lord";
		case 65: return "Lord Emperor";
		case 66: return "Empire Lord";
		case 80: return "Summoner";
		case 81: return "Bloody Summoner";
		case 82: return "Dimension Master";
		case 83: return "Dimension Summoner";
		case 96: return "Rage Fighter";
		case 97: return "Fist Master";
		case 98: return "Fist Blazer";
		case 112: return "Grow Lancer";
		case 113: return "Mirage Lancer";
		case 114: return "Shining Lancer";
		case 128: return "Rune Wizard";
		case 129: return "Rune Spell Master";
		case 130: return "Grand Rune Master";
		case 144: return "Slayer";
		case 145: return "Royal Slayer";
		case 146: return "Master Slayer";
		case 160: return "Gun Crusher";
		case 161: return "Gun Breaker";
		case 162: return "Master Gun Breaker";
		default: return "Unknown";
	}
}

const char* CCustomRanking::GetMapName(int mapId)
{
	switch (mapId)
	{
		case 0: return "Lorencia";
		case 1: return "Dungeon";
		case 2: return "Devias";
		case 3: return "Noria";
		case 4: return "Lost Tower";
		case 6: return "Arena";
		case 7: return "Atlans";
		case 8: return "Tarkan";
		case 10: return "Icarus";
		case 30: return "Valley of Loren";
		case 31: return "Land of Trials";
		case 33: return "Aida";
		case 34: return "Crywolf";
		case 36: return "Kanturu1";
		case 37: return "Kanturu2";
		case 38: return "Kanturu3";
		case 39: return "Silent";
		case 41: return "Barracks";
		case 42: return "Refuge";
		case 51: return "Elbeland";
		case 56: return "Swamp";
		case 57: return "Raklion";
		case 63: return "Santa Town";
		case 69: return "Vulcanus";
		case 80: return "Lorencia";
		case 81: return "Karutan1";
		case 82: return "Karutan2";
		case 91: return "Acheron";
		case 95: return "Debenter";
		case 96: return "Debenter";
		case 100: return "Uruk Mountain";
		case 101: return "Nars";
		case 102: return "Ferea";
		case 110: return "Nixies Lake";
		case 112: return "Deep Dungeon 1";
		case 116: return "Swamp of Darkness";
		case 122: return "Cubera";
		default: return "Unknown";
	}
}
