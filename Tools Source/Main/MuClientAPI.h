#pragma once
// MuClientAPIExtended.h - Wrapper completo para cliente MU
// Convierte todos los #define en métodos C++ organizados por categorías.

#include <windows.h>
#include <gl/GL.h>

// Forward declarations para tipos custom
struct VAngle
{
	float X;
	float Y;
	float Z;
};
struct PartyList;
struct ObjectItem;
struct ItemBmdStruct;
struct MU3Float;
struct ObjectCharacter;
struct ObjectPreview;

#define pDrawInterfaceS			((char(__cdecl*)()) 0x004D7970)
#define oDrawInterfaceS_Call	0x004DA2AC
#define pDrawInterface			((void(__cdecl*)()) 0x0080F8E0)
#define oDrawInterface_Call		0x0080F7FE

class MuClientAPIExtended {
public:
    // --------------------------
    // Interface / Drawing
    // --------------------------

    //inline static void DrawInterface() {
    //    ((void(__cdecl*)())(0x0080F8E0))();
    //}

    // Original: #define pDrawGUI ((void(__cdecl*)(DWORD, float, float, float, float)) 0x00790B50)
    inline static void DrawGUI(DWORD modelID, float x, float y, float w, float h) {
        using Fn = void(__cdecl*)(DWORD, float, float, float, float);
        reinterpret_cast<Fn>(0x00790B50)(modelID, x, y, w, h);
    }

    // Original: #define pDrawToolTip ((int(__cdecl*)(int X, int Y, LPCSTR Text)) 0x00597220)
    inline static int DrawToolTip(int x, int y, LPCSTR text) {
        using Fn = int(__cdecl*)(int, int, LPCSTR);
        return reinterpret_cast<Fn>(0x00597220)(x, y, text);
    }

    // Original: #define pDrawButton ((void(__cdecl*)(DWORD, float, float, float, float, float, float)) 0x00790E40)
    inline static void DrawButton(DWORD modelID, float x, float y, float w, float h, float sx = 0.0f, float sy = 0.0f) {
        using Fn = void(__cdecl*)(DWORD, float, float, float, float, float, float);
        reinterpret_cast<Fn>(0x00790E40)(modelID, x, y, w, h, sx, sy);
    }

    // Original: #define pDrawColorButton ((void(__cdecl*)(DWORD, float, float, float, float, float, float, DWORD)) 0x00790F20)
    inline static void DrawColorButton(DWORD modelID, float x, float y, float w, float h, float a = 0.0f, float b = 0.0f, DWORD color = 0) {
        using Fn = void(__cdecl*)(DWORD, float, float, float, float, float, float, DWORD);
        reinterpret_cast<Fn>(0x00790F20)(modelID, x, y, w, h, a, b, color);
    }

    // Original: #define pDrawExtraColor ((void(__cdecl*)(DWORD, float, float, float, float, float, float, float, float, DWORD)) 0x637A60)
    inline static void DrawExtraColor(DWORD modelID, float x, float y, float w, float h, float a = 0.0f, float b = 0.0f, float c = 0.0f, float d = 0.0f, DWORD color = 0) {
        using Fn = void(__cdecl*)(DWORD, float, float, float, float, float, float, float, float, DWORD);
        reinterpret_cast<Fn>(0x637A60)(modelID, x, y, w, h, a, b, c, d, color);
    }

    // Original: #define pDrawMapObject ((void(__cdecl*)(DWORD, float, float, float, float, float, float, float, float, float, float, float, float, DWORD)) 0x638400)
    inline static void DrawMapObject(DWORD model, float x, float y, float w, float h, float a6 = 0, float a7 = 0, float a8 = 0, float a9 = 0, float a10 = 0, float a11 = 0, float a12 = 0, float a13 = 0, DWORD color = 0) {
        using Fn = void(__cdecl*)(DWORD, float, float, float, float, float, float, float, float, float, float, float, float, DWORD);
        reinterpret_cast<Fn>(0x638400)(model, x, y, w, h, a6, a7, a8, a9, a10, a11, a12, a13, color);
    }

    // Original: #define pDrawInfoBox ((char(__cdecl*)(char Text, int Arg2)) 0x00738200)
    inline static char DrawInfoBox(char text, int arg2) {
        using Fn = char(__cdecl*)(char, int);
        return reinterpret_cast<Fn>(0x00738200)(text, arg2);
    }

    // Original: #define pDrawMessage ((int(__cdecl*)(LPCSTR Text, int Mode)) 0x00597630)
    inline static int DrawMessage(LPCSTR text, int mode) {
        using Fn = int(__cdecl*)(LPCSTR, int);
        return reinterpret_cast<Fn>(0x00597630)(text, mode);
    }

    // Original: #define pDrawBarForm ((void(__cdecl*)(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)) 0x6378A0)
    inline static void DrawBarForm(float x, float y, float w, float h, float arg5, int arg6) {
        using Fn = void(__cdecl*)(float, float, float, float, float, int);
        reinterpret_cast<Fn>(0x6378A0)(x, y, w, h, arg5, arg6);
    }

    // Original: #define pDrawImage ((void(__cdecl*)(int ImageID, float PosX, float PosY, float Width, float Height, float Arg6, float Arg7, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, bool ScaleAlpha)) 0x637C60)
    inline static void DrawImage(int imageID, float x, float y, float w, float h, float arg6 = 0.0f, float arg7 = 0.0f, float sx = 1.0f, float sy = 1.0f, bool sSize = true, bool sPos = true, bool sAlpha = true) {
        using Fn = void(__cdecl*)(int, float, float, float, float, float, float, float, float, bool, bool, bool);
        reinterpret_cast<Fn>(0x637C60)(imageID, x, y, w, h, arg6, arg7, sx, sy, sSize, sPos, sAlpha);
    }

    // Original: #define pDrawItemModel ((int(__cdecl*)(float PosX, float PosY, float Width, float Height, int ItemID, int a6, int a7, float a8, char a9)) 0x5CF310)
    inline static int DrawItemModel(float x, float y, float w, float h, int itemID, int a6, int a7, float a8, char a9) {
        using Fn = int(__cdecl*)(float, float, float, float, int, int, int, float, char);
        return reinterpret_cast<Fn>(0x5CF310)(x, y, w, h, itemID, a6, a7, a8, a9);
    }

    // --------------------------
    // Colors / Graphics
    // --------------------------

    // Original: #define pMakeColor ((DWORD(__cdecl*)(BYTE, BYTE, BYTE, BYTE)) 0x00412D20)
    inline static DWORD MakeColor(BYTE r, BYTE g, BYTE b, BYTE a) {
        using Fn = DWORD(__cdecl*)(BYTE, BYTE, BYTE, BYTE);
        return reinterpret_cast<Fn>(0x00412D20)(r, g, b, a);
    }

    // Original: #define pSetBlend ((void(__cdecl*)(BYTE Mode)) 0x635FD0)
    inline static void SetBlend(BYTE mode) {
        using Fn = void(__cdecl*)(BYTE);
        reinterpret_cast<Fn>(0x635FD0)(mode);
    }

    // Original: #define pGLSwitchBlend ((void(__cdecl*)()) 0x636070)
    inline static void GLSwitchBlend() {
        using Fn = void(__cdecl*)();
        reinterpret_cast<Fn>(0x636070)();
    }

    // Original: #define pGLSwitch ((void(__cdecl*)()) 0x635F50)
    inline static void GLSwitch() {
        using Fn = void(__cdecl*)();
        reinterpret_cast<Fn>(0x635F50)();
    }

    // --------------------------
    // Text & Fonts
    // --------------------------

    // Original: #define pTextThis ((LPVOID(*)()) 0x0041FE10)
    inline static LPVOID TextThis() {
        using Fn = LPVOID(*)();
        return reinterpret_cast<Fn>(0x0041FE10)();
    }

    // Original: #define pTextFormat ((int(__cdecl*)(char * Buffer, int Arg2, int LineSize, LPCTSTR Text, int LineWidth, bool Arg6, BYTE Arg7)) 0x540880)
    inline static int TextFormat(char* buffer, int arg2, int lineSize, LPCSTR text, int lineWidth, bool arg6, BYTE arg7) {
        using Fn = int(__cdecl*)(char*, int, int, LPCSTR, int, bool, BYTE);
        return reinterpret_cast<Fn>(0x540880)(buffer, arg2, lineSize, text, lineWidth, arg6, arg7);
    }

    // Original: #define pDrawColorText ((int(__cdecl*)(LPCTSTR Text, int PosX, int PosY, int Width, int Arg5, int Color, int Arg7, int Align)) 0x7D04D0)
    inline static int DrawColorText(LPCSTR text, int x, int y, int width, int arg5, int color, int arg7, int align) {
        using Fn = int(__cdecl*)(LPCSTR, int, int, int, int, int, int, int);
        return reinterpret_cast<Fn>(0x007D04D0)(text, x, y, width, arg5, color, arg7, align);
    }

    // Original: #define pDrawText ((int(__thiscall*)(LPVOID This, int PosX, int PosY, LPCTSTR Text, int nCount, int nTabPositions, LPINT lpnTabStopPositions, int nTabOrigin)) 0x00420150)
    inline static int DrawText(LPVOID textThis, int x, int y, LPCSTR text, int nCount = 0, int nTabPos = 0, int* tabStops = nullptr, int tabOrigin = 0) {
        using Fn = int(__thiscall*)(LPVOID, int, int, LPCSTR, int, int, int*, int);
        return reinterpret_cast<Fn>(0x00420150)(textThis, x, y, text, nCount, nTabPos, tabStops, tabOrigin);
    }

    // Original: #define pSetTextColor ((void(__thiscall*)(LPVOID This, BYTE r, BYTE g, BYTE b, BYTE h)) 0x00420040)
    inline static void SetTextColor(LPVOID textThis, BYTE r, BYTE g, BYTE b, BYTE h) {
        using Fn = void(__thiscall*)(LPVOID, BYTE, BYTE, BYTE, BYTE);
        reinterpret_cast<Fn>(0x00420040)(textThis, r, g, b, h);
    }

    // Original: #define pTextLineThis ((LPVOID(*)()) 0x8128ADC)
    inline static LPVOID TextLineThis() {
        using Fn = LPVOID(*)();
        return reinterpret_cast<Fn>(0x8128ADC)();
    }

    // Original: #define pGetTextLine ((LPCSTR(__thiscall*)(LPVOID This, int LineNumber)) 0x402320)
    inline static LPCSTR GetTextLine(LPVOID textThis, int lineNumber) {
        using Fn = LPCSTR(__thiscall*)(LPVOID, int);
        return reinterpret_cast<Fn>(0x00402320)(textThis, lineNumber);
    }

    // --------------------------
    // Resources (Images/Models/Textures)
    // --------------------------

    // Original: #define pLoadImage ((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x00772330)
    inline static int LoadImage(char* folder, int code, int a3 = 0, int a4 = 0, int a5 = 0, int a6 = 0) {
        using Fn = int(__cdecl*)(char*, int, int, int, int, int);
        return reinterpret_cast<Fn>(0x00772330)(folder, code, a3, a4, a5, a6);
    }

    // Original: #define pLoadModel ((void(__cdecl*)(int ResourceID, char * Path, char * File, int Arg4)) 0x614D10)
    inline static void LoadModel(int resourceID, char* path, char* file, int a4 = -1) {
        using Fn = void(__cdecl*)(int, char*, char*, int);
        reinterpret_cast<Fn>(0x614D10)(resourceID, path, file, a4);
    }

    // Original: #define pLoadTexture ((void(__cdecl*)(int TextureID, char * Folder, int GLREPEAT, int GLNEAREST, int GLTRUE)) 0x614710)
    inline static void LoadTexture(int texID, char* folder, int glrepeat, int glnearest, int gltrue) {
        using Fn = void(__cdecl*)(int, char*, int, int, int);
        reinterpret_cast<Fn>(0x614710)(texID, folder, glrepeat, glnearest, gltrue);
    }

    // Original: #define pInitModelData ((void(__cdecl*)()) 0x00617D30)
    inline static void InitModelData() {
        using Fn = void(__cdecl*)();
        reinterpret_cast<Fn>(0x00617D30)();
    }

    // Original: #define pInitModelData2 ((void(__cdecl*)()) 0x00626190)
    inline static void InitModelData2() {
        using Fn = void(__cdecl*)();
        reinterpret_cast<Fn>(0x00626190)();
    }

    // Original: #define pInitTextureData ((void(__cdecl*)()) 0x0061AED0)
    inline static void InitTextureData() {
        using Fn = void(__cdecl*)();
        reinterpret_cast<Fn>(0x0061AED0)();
    }

    // Original: #define pLoadSomeForm ((void(__cdecl*)()) 0x007C2050)
    inline static void LoadSomeForm() {
        using Fn = void(__cdecl*)();
        reinterpret_cast<Fn>(0x007C2050)();
    }

    // --------------------------
    // Windows Management
    // --------------------------

    // Original: #define pWindowThis ((LPVOID(*)()) 0x861110)
    inline static LPVOID WindowThis() {
        using Fn = LPVOID(*)();
        return reinterpret_cast<Fn>(0x00861110)();
    }

    // Original: #define pCheckWindow ((bool(__thiscall*)(LPVOID This, int Code)) 0x0085EC20)
    inline static bool CheckWindow(int code) {
        using Fn = bool(__thiscall*)(LPVOID, int);
        return reinterpret_cast<Fn>(0x0085EC20)(WindowThis(), code);
    }

    // Original: #define pCloseWindow ((int(__thiscall*)(LPVOID This, int Code)) 0x0085F9A0)
    inline static int CloseWindow(int code) {
        using Fn = int(__thiscall*)(LPVOID, int);
        return reinterpret_cast<Fn>(0x0085F9A0)(WindowThis(), code);
    }

    // Original: #define pOpenWindow ((int(__thiscall*)(LPVOID This, int Code)) 0x0085EC50)
    inline static int OpenWindow(int code) {
        using Fn = int(__thiscall*)(LPVOID, int);
        return reinterpret_cast<Fn>(0x0085EC50)(WindowThis(), code);
    }

    // Original: #define pOpenInfoBox ((bool(__cdecl*)(LPVOID This, int Arg2, float Arg3)) 0x00790A10)
    inline static bool OpenInfoBox(LPVOID obj, int arg2, float arg3) {
        using Fn = bool(__cdecl*)(LPVOID, int, float);
        return reinterpret_cast<Fn>(0x00790A10)(obj, arg2, arg3);
    }

    // --------------------------
    // Chat System
    // --------------------------

    // Original: #define pShowChatMessage ((bool(__thiscall*)(LPVOID This)) 0x00788A80)
    inline static bool ShowChatMessage(LPVOID chatThis) {
        using Fn = bool(__thiscall*)(LPVOID);
        return reinterpret_cast<Fn>(0x00788A80)(chatThis);
    }

    // Original: #define pSetChatMessageType ((int(__thiscall*)(LPVOID This, int Type)) 0x0078B870)
    inline static int SetChatMessageType(LPVOID chatThis, int type) {
        using Fn = int(__thiscall*)(LPVOID, int);
        return reinterpret_cast<Fn>(0x0078B870)(chatThis, type);
    }

    // Original: #define pChatThis ((LPVOID(__thiscall*)(LPVOID This)) 0x861220)
    inline static LPVOID ChatThis(LPVOID obj) {
        using Fn = LPVOID(__thiscall*)(LPVOID);
        return reinterpret_cast<Fn>(0x861220)(obj);
    }

    // Original: #define pChatIsClosed ((bool(__thiscall*)(LPVOID This)) 0x786110)
    inline static bool ChatIsClosed(LPVOID chatThis) {
        using Fn = bool(__thiscall*)(LPVOID);
        return reinterpret_cast<Fn>(0x786110)(chatThis);
    }

    // Original: #define pChatCheckLevel ((bool(__cdecl*)(int MinLevel, char * Name)) 0x597E10)
    inline static bool ChatCheckLevel(int minLevel, char* name) {
        using Fn = bool(__cdecl*)(int, char*);
        return reinterpret_cast<Fn>(0x597E10)(minLevel, name);
    }

    // Original: #define pChatWhisperThis ((LPVOID(__thiscall*)(LPVOID This)) 0x861620)
    inline static LPVOID ChatWhisperThis(LPVOID obj) {
        using Fn = LPVOID(__thiscall*)(LPVOID);
        return reinterpret_cast<Fn>(0x861620)(obj);
    }

    // Original: #define pChatWhisperActive ((bool(__thiscall*)(LPVOID This)) 0x849E00)
    inline static bool ChatWhisperActive(LPVOID chatThis) {
        using Fn = bool(__thiscall*)(LPVOID);
        return reinterpret_cast<Fn>(0x849E00)(chatThis);
    }

    // Original: #define pChatReserveLine ((DWORD(__cdecl*)(DWORD Arg1, DWORD Arg2, DWORD Arg3)) 0x6D6C20)
    inline static DWORD ChatReserveLine(DWORD arg1, DWORD arg2, DWORD arg3) {
        using Fn = DWORD(__cdecl*)(DWORD, DWORD, DWORD);
        return reinterpret_cast<Fn>(0x6D6C20)(arg1, arg2, arg3);
    }

    // Original: #define pChatBoxThis ((DWORD(__thiscall*)(LPVOID This)) 0x861180)
    inline static DWORD ChatBoxThis(LPVOID obj) {
        using Fn = DWORD(__thiscall*)(LPVOID);
        return reinterpret_cast<Fn>(0x861180)(obj);
    }

    // Original: #define pChatOutput ((void(__thiscall*)(DWORD This, char * Name, char * Message, DWORD Type, DWORD Arg4)) 0x007894E0)
    inline static void ChatOutput(DWORD chatObj, char* name, char* message, DWORD type, DWORD arg4) {
        using Fn = void(__thiscall*)(DWORD, char*, char*, DWORD, DWORD);
        reinterpret_cast<Fn>(0x007894E0)(chatObj, name, message, type, arg4);
    }

    // Original: #define pSendChatSay ((int(__cdecl*)(char * Name, char * Text, lpViewObj lpObject, int a4, int a5)) 0x5996A0)
    /*inline static int SendChatSay(char* name, char* text, lpViewObj lpObject = nullptr, int a4 = 0, int a5 = 0) {
        using Fn = int(__cdecl*)(char*, char*, lpViewObj, int, int);
        return reinterpret_cast<Fn>(0x005996A0)(name, text, lpObject, a4, a5);
    }*/

    // --------------------------
    // Player / Character System
    // --------------------------

    // Original: #define pGetPosFromAngle ((void(__cdecl*)(VAngle * Angle, int * PosX, int * PosY)) 0x635B00)
    inline static void GetPosFromAngle(VAngle* angle, int* posX, int* posY) {
        using Fn = void(__cdecl*)(VAngle*, int*, int*);
        reinterpret_cast<Fn>(0x635B00)(angle, posX, posY);
    }

    // Original: #define pIsMaster ((bool(__cdecl*)(BYTE Class)) 0x5878E0)
    inline static bool IsMaster(BYTE charClass) {
        using Fn = bool(__cdecl*)(BYTE);
        return reinterpret_cast<Fn>(0x5878E0)(charClass);
    }

    // Original: #define pIsMaster2 ((bool(__cdecl*)(BYTE Class)) 0x5875A0)
    inline static bool IsMaster2(BYTE charClass) {
        using Fn = bool(__cdecl*)(BYTE);
        return reinterpret_cast<Fn>(0x5875A0)(charClass);
    }

    // Original: #define pGetCharClass ((BYTE(__cdecl*)(BYTE Class)) 0x405230)
    inline static BYTE GetCharClass(BYTE charClass) {
        using Fn = BYTE(__cdecl*)(BYTE);
        return reinterpret_cast<Fn>(0x405230)(charClass);
    }

    // Original: #define pGetAttackSpeed ((void(__thiscall*)()) 0x593B20)
    inline static void GetAttackSpeed() {
        using Fn = void(__thiscall*)();
        reinterpret_cast<Fn>(0x593B20)();
    }

    // --------------------------
    // Items System
    // --------------------------

    // Original: #define pGetItemColor ((void(__cdecl*)(int ModelID, float Arg2, float Arg3, VAngle * Color, bool BalrogMode)) 0x5F8C50)
    inline static void GetItemColor(int modelID, float arg2, float arg3, VAngle* color, bool balrogMode) {
        using Fn = void(__cdecl*)(int, float, float, VAngle*, bool);
        reinterpret_cast<Fn>(0x5F8C50)(modelID, arg2, arg3, color, balrogMode);
    }

    // Original: #define pGetItemColor2 ((void(__cdecl*)(int ModelID, float Arg2, float Arg3, VAngle * Color, bool BalrogMode)) 0x5FA4A0)
    inline static void GetItemColor2(int modelID, float arg2, float arg3, VAngle* color, bool balrogMode) {
        using Fn = void(__cdecl*)(int, float, float, VAngle*, bool);
        reinterpret_cast<Fn>(0x5FA4A0)(modelID, arg2, arg3, color, balrogMode);
    }

    // Original: #define pSetItemPrice ((__int64(__cdecl*)(ObjectItem * lpItem, int Mode)) 0x58E3B0)
    inline static __int64 SetItemPrice(ObjectItem* lpItem, int mode) {
        using Fn = __int64(__cdecl*)(ObjectItem*, int);
        return reinterpret_cast<Fn>(0x58E3B0)(lpItem, mode);
    }

    // Original: #define pIsExpensiveItem ((bool(__cdecl*)(ObjectItem * lpItem)) 0x5C81F0)
    inline static bool IsExpensiveItem(ObjectItem* lpItem) {
        using Fn = bool(__cdecl*)(ObjectItem*);
        return reinterpret_cast<Fn>(0x5C81F0)(lpItem);
    }

    // Original: #define pIsUpgradeItem ((bool(__thiscall*)(LPVOID This, ObjectItem * lpSource, ObjectItem * lpTarget)) 0x7DDAC0)
    inline static bool IsUpgradeItem(LPVOID obj, ObjectItem* lpSource, ObjectItem* lpTarget) {
        using Fn = bool(__thiscall*)(LPVOID, ObjectItem*, ObjectItem*);
        return reinterpret_cast<Fn>(0x7DDAC0)(obj, lpSource, lpTarget);
    }

    // Original: #define pAllowRepairWings ((bool(__cdecl*)(ObjectItem * lpItem)) 0x5C9DA0)
    inline static bool AllowRepairWings(ObjectItem* lpItem) {
        using Fn = bool(__cdecl*)(ObjectItem*);
        return reinterpret_cast<Fn>(0x5C9DA0)(lpItem);
    }

    // Original: #define pSetItemOption ((void(__cdecl*)(ObjectItem * lpItem, BYTE Option, BYTE Special, BYTE Value)) 0x58B910)
    inline static void SetItemOption(ObjectItem* lpItem, BYTE option, BYTE special, BYTE value) {
        using Fn = void(__cdecl*)(ObjectItem*, BYTE, BYTE, BYTE);
        reinterpret_cast<Fn>(0x58B910)(lpItem, option, special, value);
    }

    // Original: #define pSetItemOptionText ((void(__cdecl*)(int ItemID, int Line, WORD OptionID, bool Arg4, int Arg5)) 0x5C2F70)
    inline static void SetItemOptionText(int itemID, int line, WORD optionID, bool arg4, int arg5) {
        using Fn = void(__cdecl*)(int, int, WORD, bool, int);
        reinterpret_cast<Fn>(0x5C2F70)(itemID, line, optionID, arg4, arg5);
    }

    // Original: #define pSetItemTextLine ((void(__cdecl*)(int Line, LPSTR Text, ...)) 0x9CF6AA)
    inline static void SetItemTextLine(int line, LPCSTR text, ...) {
        using Fn = void(__cdecl*)(int, LPCSTR, ...);
        va_list args;
        va_start(args, text);
        reinterpret_cast<Fn>(0x9CF6AA)(line, text, args);
        va_end(args);
    }

    // Original: #define pIsWings ((int(__thiscall*)(LPVOID This, DWORD ItemID)) 0x7E7870)
    inline static int IsWings(LPVOID obj, DWORD itemID) {
        using Fn = int(__thiscall*)(LPVOID, DWORD);
        return reinterpret_cast<Fn>(0x7E7870)(obj, itemID);
    }

    // Original: #define pGetMaxDurability ((short(__cdecl*)(ObjectItem * lpItem, int ScriptStruct, int Level)) 0x5C2170)
    inline static short GetMaxDurability(ObjectItem* lpItem, int scriptStruct, int level) {
        using Fn = short(__cdecl*)(ObjectItem*, int, int);
        return reinterpret_cast<Fn>(0x5C2170)(lpItem, scriptStruct, level);
    }

    // --------------------------
    // Effects System
    // --------------------------

    #define pSetItemEffect ((void(__cdecl*)(int Arg1, int ModelID, VAngle Angle, int Arg4, int ItemLevel, char Arg6, int Arg7, int Arg8, int Arg9)) 0x609E70)
    //inline static void SetItemEffect(int a1, int modelID, VAngle angle, int a4, int itemLevel, char a6, int a7, int a8, int a9) {
    //    using Fn = void(__cdecl*)(int, int, VAngle, int, int, char, int, int, int);
    //    reinterpret_cast<Fn>(0x00609E70)(a1, modelID, angle, a4, itemLevel, a6, a7, a8, a9);
    //}

    #define pSetItemEffect2 ((void(__cdecl*)(float a4, float a5, float a6, lpViewObj Object, float a8, DWORD ModelID, int a10, char a11, char a12, char a13, signed int a14, char a15)) 0x5655C0)
    //inline static void SetItemEffect2(float a4, float a5, float a6, lpViewObj object, float a8, DWORD modelID, int a10, char a11, char a12, char a13, int a14, char a15) {
    //    using Fn = void(__cdecl*)(float, float, float, lpViewObj, float, DWORD, int, char, char, char, int, char);
    //    reinterpret_cast<Fn>(0x5655C0)(a4, a5, a6, object, a8, modelID, a10, a11, a12, a13, a14, a15);
    //}

    // Original: #define pPlayEffectAnimation ((int(__cdecl*)(int EffectIndex, int PreviewStruct)) 0x667130)
    inline static int PlayEffectAnimation(int effectIndex, int previewStruct) {
        using Fn = int(__cdecl*)(int, int);
        return reinterpret_cast<Fn>(0x667130)(effectIndex, previewStruct);
    }

    // Original: #define pAllowStaticEffect ((void(__thiscall*)(LPVOID This, DWORD * Arg1, DWORD Arg2, int Arg3, int Arg4)) 0x544E60)
    inline static void AllowStaticEffect(LPVOID obj, DWORD* arg1, DWORD arg2, int arg3, int arg4) {
        using Fn = void(__thiscall*)(LPVOID, DWORD*, DWORD, int, int);
        reinterpret_cast<Fn>(0x544E60)(obj, arg1, arg2, arg3, arg4);
    }

    // Original: #define pPlayStaticEffect ((int(__cdecl*)(DWORD ModelID, DWORD Arg1, float Scale, float * Color, int Model, float a6, int a7)) 0x771310)
    inline static int PlayStaticEffect(DWORD modelID, DWORD arg1, float scale, float* color, int model, float a6, int a7) {
        using Fn = int(__cdecl*)(DWORD, DWORD, float, float*, int, float, int);
        return reinterpret_cast<Fn>(0x00771310)(modelID, arg1, scale, color, model, a6, a7);
    }

    // Original: #define pPlayDynamicEffect ((int(__cdecl*)(DWORD ModelID, DWORD * Arg1, int Arg2, float * Color, int Arg4, float Arg5, int Arg6)) 0x74CD30)
    inline static int PlayDynamicEffect(DWORD modelID, DWORD* arg1, int arg2, float* color, int arg4, float arg5, int arg6) {
        using Fn = int(__cdecl*)(DWORD, DWORD*, int, float*, int, float, int);
        return reinterpret_cast<Fn>(0x0074CD30)(modelID, arg1, arg2, color, arg4, arg5, arg6);
    }

    // Original: #define pTexEffect ((int(__thiscall*)(int This, signed int a2, int a3, float a4, signed int a5, float a6, float a7, float a8, int a9)) 0x005468A0)
    inline static int TexEffect(int obj, int a2, int a3, float a4, int a5, float a6, float a7, float a8, int a9) {
        using Fn = int(__thiscall*)(int, int, int, float, int, float, float, float, int);
        return reinterpret_cast<Fn>(0x005468A0)(obj, a2, a3, a4, a5, a6, a7, a8, a9);
    }

    // Original: #define pCustomEffGet ((int(__thiscall*)(int This, int a2, int *a3, MU3Float *a4, char a5)) 0x00545030)
    inline static int CustomEffGet(int obj, int a2, int* a3, MU3Float* a4, char a5) {
        using Fn = int(__thiscall*)(int, int, int*, MU3Float*, char);
        return reinterpret_cast<Fn>(0x00545030)(obj, a2, a3, a4, a5);
    }

    // Original: #define pCustomEffect ((int(__cdecl*)(int a1, MU3Float *a2, float a3,int *Color, int a5, int a6, int a7)) 0x771310)
    inline static int CustomEffect(int a1, MU3Float* a2, float a3, int* color, int a5, int a6, int a7) {
        using Fn = int(__cdecl*)(int, MU3Float*, float, int*, int, int, int);
        return reinterpret_cast<Fn>(0x771310)(a1, a2, a3, color, a5, a6, a7);
    }

    // Original: #define pCustomEffGet2 ((int(__thiscall*)(int This, int a2, float a3,int a4,float a5,float a6, float a7, int a8,int a9)) 0x005494C0)
    inline static int CustomEffGet2(int obj, int a2, float a3, int a4, float a5, float a6, float a7, int a8, int a9) {
        using Fn = int(__thiscall*)(int, int, float, int, float, float, float, int, int);
        return reinterpret_cast<Fn>(0x005494C0)(obj, a2, a3, a4, a5, a6, a7, a8, a9);
    }

    // --------------------------
    // Monsters / NPCs
    // --------------------------

    // Original: #define pShowMonster ((lpViewObj(__cdecl*)(int MonsterID, int a2, int a3, int a4)) 0x580FC0)
    /*inline static lpViewObj ShowMonster(int monsterID, int a2, int a3, int a4) {
        using Fn = lpViewObj(__cdecl*)(int, int, int, int);
        return reinterpret_cast<Fn>(0x00580FC0)(monsterID, a2, a3, a4);
    }*/

    // Original: #define pCheckEffect ((char(__thiscall*)(LPVOID This, char a2)) 0x004C8640)
    inline static char CheckEffect(LPVOID obj, char a2) {
        using Fn = char(__thiscall*)(LPVOID, char);
        return reinterpret_cast<Fn>(0x004C8640)(obj, a2);
    }

    // --------------------------
    // Event System
    // --------------------------

    // Original: #define pInitEventStatus ((void(__cdecl*)(int PreviewStruct)) 0x4EFF70)
    inline static void InitEventStatus(int previewStruct) {
        using Fn = void(__cdecl*)(int);
        reinterpret_cast<Fn>(0x4EFF70)(previewStruct);
    }

    // Original: #define pEventEffectThis ((LPVOID(__cdecl*)(int Arg1)) 0x9D00C5)
    inline static LPVOID EventEffectThis(int arg1) {
        using Fn = LPVOID(__cdecl*)(int);
        return reinterpret_cast<Fn>(0x9D00C5)(arg1);
    }

    // Original: #define pAddEventEffect ((LPVOID(__thiscall*)(LPVOID This, int ModelID, int a3, bool bFixRotation, float a5, float a6, float a7, float a8, float a9, float a10)) 0x4EFFF0)
    inline static LPVOID AddEventEffect(LPVOID obj, int modelID, int a3, bool fixRotation, float a5, float a6, float a7, float a8, float a9, float a10) {
        using Fn = LPVOID(__thiscall*)(LPVOID, int, int, bool, float, float, float, float, float, float);
        return reinterpret_cast<Fn>(0x4EFFF0)(obj, modelID, a3, fixRotation, a5, a6, a7, a8, a9, a10);
    }

    // Original: #define pAddEventEffect2 ((LPVOID(__thiscall*)(LPVOID This, int ModelID, int a3, int a4, float a5, float a6, float a7)) 0x4F0730)
    inline static LPVOID AddEventEffect2(LPVOID obj, int modelID, int a3, int a4, float a5, float a6, float a7) {
        using Fn = LPVOID(__thiscall*)(LPVOID, int, int, int, float, float, float);
        return reinterpret_cast<Fn>(0x4F0730)(obj, modelID, a3, a4, a5, a6, a7);
    }

    // --------------------------
    // Shop Systems
    // --------------------------

    // Original: #define pPShopThis1 ((LPVOID(__cdecl*)()) 0x861110)
    inline static LPVOID PShopThis1() {
        using Fn = LPVOID(__cdecl*)();
        return reinterpret_cast<Fn>(0x861110)();
    }

    // Original: #define pPShopThis2 ((LPVOID(__thiscall*)(LPVOID This)) 0x861400)
    inline static LPVOID PShopThis2(LPVOID obj) {
        using Fn = LPVOID(__thiscall*)(LPVOID);
        return reinterpret_cast<Fn>(0x861400)(obj);
    }

    // Original: #define pPShopSet ((void(__thiscall*)(LPVOID This, BYTE Mode)) 0x840F70)
    inline static void PShopSet(LPVOID obj, BYTE mode) {
        using Fn = void(__thiscall*)(LPVOID, BYTE);
        reinterpret_cast<Fn>(0x840F70)(obj, mode);
    }

    // Original: #define pPShopRefresh ((void(__cdecl*)(int Preview)) 0x6685B0)
    inline static void PShopRefresh(int preview) {
        using Fn = void(__cdecl*)(int);
        reinterpret_cast<Fn>(0x6685B0)(preview);
    }

    // Original: #define pGameShopThis ((LPVOID(*)()) 0x93F370)
    inline static LPVOID GameShopThis() {
        using Fn = LPVOID(*)();
        return reinterpret_cast<Fn>(0x93F370)();
    }

    // Original: #define pGameShopGetGP ((double(__thiscall*)(LPVOID This)) 0x9405B0)
    inline static double GameShopGetGP(LPVOID obj) {
        using Fn = double(__thiscall*)(LPVOID);
        return reinterpret_cast<Fn>(0x9405B0)(obj);
    }

    // --------------------------
    // Helper Systems
    // --------------------------

    // Original: #define pMUHelperThis ((LPVOID(__cdecl*)()) 0x4DB240)
    inline static LPVOID MUHelperThis() {
        using Fn = LPVOID(__cdecl*)();
        return reinterpret_cast<Fn>(0x4DB240)();
    }

    // Original: #define pMUHelperClose ((void(__thiscall*)(LPVOID This)) 0x95D450)
    inline static void MUHelperClose(LPVOID obj) {
        using Fn = void(__thiscall*)(LPVOID);
        reinterpret_cast<Fn>(0x95D450)(obj);
    }

    // Original: #define pMUHelperStart ((void(__thiscall*)(LPVOID This)) 0x95D190)
    inline static void MUHelperStart(LPVOID obj) {
        using Fn = void(__thiscall*)(LPVOID);
        reinterpret_cast<Fn>(0x95D190)(obj);
    }

    // Original: #define pMUHelperDataSet ((bool(__thiscall*)(LPVOID This, LPBYTE Data)) 0x960C10)
    inline static bool MUHelperDataSet(LPVOID obj, LPBYTE data) {
        using Fn = bool(__thiscall*)(LPVOID, LPBYTE);
        return reinterpret_cast<Fn>(0x960C10)(obj, data);
    }

    // --------------------------
    // Warehouse System
    // --------------------------

    // Original: #define pWarehouseExThis ((int(__thiscall*)(LPVOID This)) 0x861A80)
    inline static int WarehouseExThis(LPVOID obj) {
        using Fn = int(__thiscall*)(LPVOID);
        return reinterpret_cast<Fn>(0x861A80)(obj);
    }

    // Original: #define pWarehouseExSet ((void(__thiscall*)(int Pointer, BYTE Status)) 0x856BD0)
    inline static void WarehouseExSet(int pointer, BYTE status) {
        using Fn = void(__thiscall*)(int, BYTE);
        reinterpret_cast<Fn>(0x856BD0)(pointer, status);
    }

    // --------------------------
    // Preview System
    // --------------------------

    // Original: #define pPreviewThis ((LPVOID(*)()) 0x402BC0)
    inline static LPVOID PreviewThis() {
        using Fn = LPVOID(*)();
        return reinterpret_cast<Fn>(0x402BC0)();
    }

    // Original: #define pClearPreviewThis ((LPVOID(*)()) 0x82C5C80)
    inline static LPVOID ClearPreviewThis() {
        using Fn = LPVOID(*)();
        return reinterpret_cast<Fn>(0x82C5C80)();
    }

    // Original: #define pClearPreview ((void(__thiscall*)(LPVOID This)) 0x4CC780)
    inline static void ClearPreview(LPVOID obj) {
        using Fn = void(__thiscall*)(LPVOID);
        reinterpret_cast<Fn>(0x4CC780)(obj);
    }

    // Original: #define pGetPreviewStruct ((DWORD(__thiscall*)(LPVOID This, int ViewportID)) 0x0096A4C0)
    inline static DWORD GetPreviewStruct(LPVOID obj, int viewportID) {
        using Fn = DWORD(__thiscall*)(LPVOID, int);
        return reinterpret_cast<Fn>(0x0096A4C0)(obj, viewportID);
    }

    // Original: #define pPreviewCharSet ((void(__cdecl*)(int ObjectIndex, BYTE * CharSet, lpViewObj Object, int Mode)) 0x57FD90)
    /*inline static void PreviewCharSet(int objectIndex, BYTE* charSet, lpViewObj object, int mode) {
        using Fn = void(__cdecl*)(int, BYTE*, lpViewObj, int);
        reinterpret_cast<Fn>(0x57FD90)(objectIndex, charSet, object, mode);
    }*/

    // --------------------------
    // Game System
    // --------------------------

    // Original: #define pGetCommandLine ((LPSTR(WINAPI*)()) 0x00D221C8)
    inline static LPSTR GetCommandLine() {
        using Fn = LPSTR(WINAPI*)();
        return reinterpret_cast<Fn>(0x00D221C8)();
    }

    // Original: #define pCreateConnect ((int(__cdecl*)(char * IP, WORD Port)) 0x0063C960)
    inline static int CreateConnect(char* ip, WORD port) {
        using Fn = int(__cdecl*)(char*, WORD);
        return reinterpret_cast<Fn>(0x0063C960)(ip, port);
    }

    // Original: #define pMenuExitEvent ((DWORD(__cdecl*)(int Arg1)) 0x7A89D0)
    inline static DWORD MenuExitEvent(int arg1) {
        using Fn = DWORD(__cdecl*)(int);
        return reinterpret_cast<Fn>(0x7A89D0)(arg1);
    }

    // Original: #define pGameLoad ((int(__cdecl*)()) 0x004D0FC0)
    inline static int GameLoad() {
        using Fn = int(__cdecl*)();
        return reinterpret_cast<Fn>(0x004D0FC0)();
    }

    // Original: #define pGetMapName ((char*(__cdecl*)(int MapNumber)) 0x5D2C10)
    inline static const char* GetMapName(int mapNumber) {
        using Fn = const char* (__cdecl*)(int);
        return reinterpret_cast<Fn>(0x5D2C10)(mapNumber);
    }

    // Original: #define pMapName ((char*(__cdecl*)(signed int mapNumber)) 0x5D2C10)
    inline static const char* MapName(int mapNumber) {
        using Fn = const char* (__cdecl*)(int);
        return reinterpret_cast<Fn>(0x5D2C10)(mapNumber);
    }

    // Original: #define pMoveListInit ((void(__thiscall*)(LPVOID This, int Arg1, int Arg2)) 0x830C10)
    inline static void MoveListInit(LPVOID obj, int arg1, int arg2) {
        using Fn = void(__thiscall*)(LPVOID, int, int);
        reinterpret_cast<Fn>(0x830C10)(obj, arg1, arg2);
    }

    // Original: #define pRefreshViewport ((void(__cdecl*)(DWORD a1, DWORD a2, int a3)) 0x558630)
    inline static void RefreshViewport(DWORD a1, DWORD a2, int a3) {
        using Fn = void(__cdecl*)(DWORD, DWORD, int);
        reinterpret_cast<Fn>(0x558630)(a1, a2, a3);
    }

    // Original: #define pSetPetMount ((int(__cdecl*)(int MauntCode, int Arg2, int Arg3, int Arg4, int Arg5)) 0x004A8271)
    inline static int SetPetMount(int mountCode, int arg2, int arg3, int arg4, int arg5) {
        using Fn = int(__cdecl*)(int, int, int, int, int);
        return reinterpret_cast<Fn>(0x004A8271)(mountCode, arg2, arg3, arg4, arg5);
    }

    // Original: #define pUserStat ((LPVOID(*)()) 0x588D70)
    inline static LPVOID UserStat() {
        using Fn = LPVOID(*)();
        return reinterpret_cast<Fn>(0x588D70)();
    }

    // Original: #define pUpdateUserStat ((void(__thiscall*)(LPVOID This, int * Value, int Code)) 0x4EA460)
    inline static void UpdateUserStat(LPVOID obj, int* value, int code) {
        using Fn = void(__thiscall*)(LPVOID, int*, int);
        reinterpret_cast<Fn>(0x4EA460)(obj, value, code);
    }

    // Original: #define pIsButtonPressed ((int(__thiscall*)(int ButtonNumber)) 0x791070)
    inline static int IsButtonPressed(int buttonNumber) {
        using Fn = int(__thiscall*)(int);
        return reinterpret_cast<Fn>(0x791070)(buttonNumber);
    }

    // Original: #define pAllowGUI ((bool(__cdecl*)()) 0x007D4250)
    inline static bool AllowGUI() {
        using Fn = bool(__cdecl*)();
        return reinterpret_cast<Fn>(0x007D4250)();
    }

    // Original: #define pCharacterBuf ((int(__thiscall*)(void *This, int a2)) 0x0040FCA0)
    inline static int CharacterBuf(void* obj, int a2) {
        using Fn = int(__thiscall*)(void*, int);
        return reinterpret_cast<Fn>(0x0040FCA0)(obj, a2);
    }

    // Original: #define pGetMoneyFormat ((int(__cdecl*)(double Value, char * Buff, int Arg3)) 0x5C1170)
    inline static int GetMoneyFormat(double value, char* buff, int arg3) {
        using Fn = int(__cdecl*)(double, char*, int);
        return reinterpret_cast<Fn>(0x5C1170)(value, buff, arg3);
    }

    // Original: #define pIsFlyingMauntToMove ((bool(__thiscall*)(LPVOID This, WORD ItemID1, WORD ItemID2)) 0x831B09)
    inline static bool IsFlyingMountToMove(LPVOID obj, WORD itemID1, WORD itemID2) {
        using Fn = bool(__thiscall*)(LPVOID, WORD, WORD);
        return reinterpret_cast<Fn>(0x831B09)(obj, itemID1, itemID2);
    }

    // Original: #define pTest ((float(__cdecl*)(double))0x009CEBF0)
    inline static float Test(double value) {
        using Fn = float(__cdecl*)(double);
        return reinterpret_cast<Fn>(0x009CEBF0)(value);
    }

    // --------------------------
    // Sub Functions (Direct addresses)
    // --------------------------

    // Original: #define sub_636720_Addr ((int(*)())0x636720)
    inline static int Sub636720() {
        using Fn = int(*)();
        return reinterpret_cast<Fn>(0x636720)();
    }

    // Original: #define sub_6363D0_Addr ((void(__cdecl*)(GLint x, int a2, GLsizei width, GLsizei height)) 0x6363D0)
    inline static void Sub6363D0(GLint x, int a2, GLsizei width, GLsizei height) {
        using Fn = void(__cdecl*)(GLint, int, GLsizei, GLsizei);
        reinterpret_cast<Fn>(0x6363D0)(x, a2, width, height);
    }

    // Original: #define sub_6358A0_Addr ((int(__cdecl*)(float a1, float a2, float a3, float a4)) 0x6358A0)
    inline static int Sub6358A0(float a1, float a2, float a3, float a4) {
        using Fn = int(__cdecl*)(float, float, float, float);
        return reinterpret_cast<Fn>(0x6358A0)(a1, a2, a3, a4);
    }

    // Original: #define sub_635830_Addr ((void(__cdecl*)(LPVOID a1)) 0x635830)
    inline static void Sub635830(LPVOID a1) {
        using Fn = void(__cdecl*)(LPVOID);
        reinterpret_cast<Fn>(0x635830)(a1);
    }

    // Original: #define sub_635DE0_Addr ((void(*)()) 0x635DE0)
    inline static void Sub635DE0() {
        using Fn = void(*)();
        reinterpret_cast<Fn>(0x635DE0)();
    }

    // Original: #define sub_635E40_Addr ((void(*)()) 0x635E40)
    inline static void Sub635E40() {
        using Fn = void(*)();
        reinterpret_cast<Fn>(0x635E40)();
    }

    // Original: #define sub_637770_Addr ((void(*)()) 0x637770)
    inline static void Sub637770() {
        using Fn = void(*)();
        reinterpret_cast<Fn>(0x637770)();
    }

    // Original: #define sub_6359B0_Addr ((int(__cdecl*)(int a1, int a2, int a3, char a4)) 0x006359B0)
    inline static int Sub6359B0(int a1, int a2, int a3, char a4) {
        using Fn = int(__cdecl*)(int, int, int, char);
        return reinterpret_cast<Fn>(0x006359B0)(a1, a2, a3, a4);
    }

    // Original: #define sub_5CA0D0_Addr ((void(__cdecl*)(signed int a1, signed int a2, int a3, int a4, int a5, int a6, char a7)) 0x5CA0D0)
    inline static void Sub5CA0D0(int a1, int a2, int a3, int a4, int a5, int a6, char a7) {
        using Fn = void(__cdecl*)(int, int, int, int, int, int, char);
        reinterpret_cast<Fn>(0x5CA0D0)(a1, a2, a3, a4, a5, a6, a7);
    }

    // --------------------------
    // Pet System
    // --------------------------

    // Original: #define pPetCall1 ((LPVOID(__cdecl*)(int ID, int PetStruct, int PetObjectView, int Mode, int arg5)) 0x5013B0)
    inline static LPVOID PetCall1(int id, int petStruct, int petObjectView, int mode, int arg5) {
        using Fn = LPVOID(__cdecl*)(int, int, int, int, int);
        return reinterpret_cast<Fn>(0x5013B0)(id, petStruct, petObjectView, mode, arg5);
    }

    // Original: #define pPetCall2 ((LPVOID(__cdecl*)(int ID, int PetStruct, int PetObjectView, int Mode, int arg5)) 0x501700)
    inline static LPVOID PetCall2(int id, int petStruct, int petObjectView, int mode, int arg5) {
        using Fn = LPVOID(__cdecl*)(int, int, int, int, int);
        return reinterpret_cast<Fn>(0x501700)(id, petStruct, petObjectView, mode, arg5);
    }

    // --------------------------
    // Memory Offsets / Global Variables
    // --------------------------

    // Party system
    inline static PartyList& PartyListStruct() {
        return *reinterpret_cast<PartyList*>(0x81CB4E8);
    }

    /*inline static char* GetPartyStruct(int slot) {
        return (char*)((slot * sizeof(PartyList)) + (*reinterpret_cast<char**>(0x81CB4E8)));
    }*/

    inline static DWORD& PartyMemberCount() {
        return *reinterpret_cast<DWORD*>(0x81F6B6C);
    }

    // Player data
    inline static short& MasterLevel() {
        return *reinterpret_cast<short*>(0x87935D8);
    }

    inline static short& MasterPoint() {
        return *reinterpret_cast<short*>(0x87935F2);
    }

    inline static __int64& MasterExp() {
        return *reinterpret_cast<__int64*>(0x87935E0);
    }

    inline static __int64& MasterNextExp() {
        return *reinterpret_cast<__int64*>(0x87935E8);
    }

    inline static int& PlayerState() {
        return *reinterpret_cast<int*>(0x0E609E8);
    }

    // Map data
    inline static int& MapNumber() {
        return *reinterpret_cast<int*>(0x0E61E18);
    }

    // Window data
    inline static int& CursorX() {
        return *reinterpret_cast<int*>(0x879340C);
    }

    inline static int& CursorY() {
        return *reinterpret_cast<int*>(0x8793410);
    }

    inline static int& WinWidth() {
        return *reinterpret_cast<int*>(0x0E61E58);
    }

    inline static int& WinHeight() {
        return *reinterpret_cast<int*>(0x0E61E5C);
    }

    inline static float& WinWidthReal() {
        return *reinterpret_cast<float*>(0xE7C3D4);
    }

    inline static float& WinHeightReal() {
        return *reinterpret_cast<float*>(0xE7C3D8);
    }

    inline static int& WinFontHeight() {
        return *reinterpret_cast<int*>(0x81C0380);
    }

    inline static HWND& GameWindow() {
        return *reinterpret_cast<HWND*>(0x0E8C578);
    }

    inline static int& GameResolutionMode() {
        return *reinterpret_cast<int*>(0x0E8C240);
    }

    // Game state
    inline static DWORD& LastSkillIndex() {
        return *reinterpret_cast<DWORD*>(0x81C039C);
    }

    inline static int& ViewUnknownTargetID() {
        return *reinterpret_cast<int*>(0xE61728);
    }

    inline static int& ViewNPCTargetID() {
        return *reinterpret_cast<int*>(0xE6172C);
    }

    inline static int& ViewAttackTargetID() {
        return *reinterpret_cast<int*>(0xE61730);
    }

    inline static DWORD& SetCursorFocus() {
        return *reinterpret_cast<DWORD*>(0xE8CB3C);
    }

    inline static int& IsDisconnect() {
        return *reinterpret_cast<int*>(0xE82C24);
    }

    inline static DWORD& OnLine() {
        return *reinterpret_cast<DWORD*>(0x8793704);
    }

    inline static DWORD& MUIsLoaded() {
        return *reinterpret_cast<DWORD*>(0xE60974);
    }

    inline static int& MUHelperClass() {
        return *reinterpret_cast<int*>(0xE8CB7C);
    }

    inline static char* MUCommandLine() {
        return reinterpret_cast<char*>(0x0E8C274);
    }

    // Frame system
    inline static BYTE& FrameValue1() {
        return *reinterpret_cast<BYTE*>(0x004D9F02 + 2);
    }

    inline static DWORD& FrameValue2() {
        return *reinterpret_cast<DWORD*>(0x004DA3B2 + 1);
    }

    inline static DWORD& FrameValue3() {
        return *reinterpret_cast<DWORD*>(0x004DA3DD + 3);
    }

    inline static BYTE& FrameValue4() {
        return *reinterpret_cast<BYTE*>(0x004DA3AC + 3);
    }

    inline static double& FrameSpeed1() {
        return *reinterpret_cast<double*>(0x0D27C88);
    }

    inline static double& FrameSpeed2() {
        return *reinterpret_cast<double*>(0x0D281C0);
    }

    inline static DWORD& FpsTime() {
        return *reinterpret_cast<DWORD*>(0x0E8CB30);
    }

    // Camera system
    inline static float& CamZoom() {
        return *reinterpret_cast<float*>(0x0D27BFC);
    }

    inline static float& CamPosZDef() {
        return *reinterpret_cast<float*>(0x0D255AC);
    }

    inline static float& CamPosZ() {
        return *reinterpret_cast<float*>(0x0D255A0);
    }

    inline static float& CamRotZ() {
        return *reinterpret_cast<float*>(0x87933D8);
    }

    inline static float& CamRotZDef() {
        return *reinterpret_cast<float*>(0x0D27B78);
    }

    inline static float& CamRotY() {
        return *reinterpret_cast<float*>(0x0D27B88);
    }

    // Camera clip data
    inline static float& CamClipX() {
        return *reinterpret_cast<float*>(0x0D2C848);
    }

    inline static float& CamClipY() {
        return *reinterpret_cast<float*>(0x0D2C894);
    }

    inline static float& CamClipZ() {
        return *reinterpret_cast<float*>(0x0D2C8B8);
    }

    inline static float& CamClipXCS() {
        return *reinterpret_cast<float*>(0x0D2C898);
    }

    inline static float& CamClipYCS() {
        return *reinterpret_cast<float*>(0x0D2C8A8);
    }

    inline static float& CamClipX2() {
        return *reinterpret_cast<float*>(0x0D2C878);
    }

    inline static float& CamClipY2() {
        return *reinterpret_cast<float*>(0x0D2C880);
    }

    inline static float& CamClipZ2() {
        return *reinterpret_cast<float*>(0x0D2B94C);
    }

    inline static float& CamClipGL() {
        return *reinterpret_cast<float*>(0x0D2570C);
    }

    // Item text system
    inline static DWORD& ItemTextColor() {
        return *reinterpret_cast<DWORD*>(0x81C0A68);
    }

    inline static DWORD& ItemTextWeight() {
        return *reinterpret_cast<DWORD*>(0x81C09F0);
    }

    inline static DWORD& ItemTextLine() {
        return *reinterpret_cast<DWORD*>(0x81C0AE0);
    }

    inline static DWORD& ItemTextIndex() {
        return *reinterpret_cast<DWORD*>(0x81F6BF0);
    }

    // NPC/Monster system
    inline static char* NpcName() {
        return reinterpret_cast<char*>(0x8119F68);
    }

    inline static DWORD& ChatStructure() {
        return *reinterpret_cast<DWORD*>(0x8129540);
    }

    // Battle system
    inline static BYTE& MaxBattleZoneCount() {
        return *reinterpret_cast<BYTE*>(0x005D3078 + 3);
    }

    // Item BMD system
    inline static ItemBmdStruct& ItemBmdStruct() {
        return *reinterpret_cast<::ItemBmdStruct*>(0x8128AC0);
    }

    /*inline static ItemBmdStruct* GetItemBmdStruct(int itemId) {
        return reinterpret_cast<::ItemBmdStruct*>(*reinterpret_cast<DWORD*>(0x8128AC0) + sizeof(::ItemBmdStruct) * itemId);
    }*/

    // Object structures
    inline static int& UserPreviewStruct() {
        return *reinterpret_cast<int*>(0x7BC4F04);
    }

    inline static int& UserObjectStruct() {
        return *reinterpret_cast<int*>(0x8128AC8);
    }

    inline static int& UserObjectStruct_() {
        return *reinterpret_cast<int*>(0x8128AC4);
    }

    // --------------------------
    // Constants / Offsets (for reference)
    // --------------------------

    // Battle offsets
    static constexpr uintptr_t BattleMapStart = 0x0083165E;
    static constexpr uintptr_t BattleZoneStart = 0x005D3043;
    static constexpr uintptr_t IsBattleServer_Call1 = 0x005D303A;
    static constexpr uintptr_t IsBattleServer_Call2 = 0x00831651;

    // Load form offsets
    static constexpr uintptr_t LoadSomeForm_Call = 0x007C1D7E;

    // AllowGUI calls
    static constexpr uintptr_t AllowGUI_Call1 = 0x007D378E;
    static constexpr uintptr_t AllowGUI_Call2 = 0x00811C42;

    // Vulcanus move
    static constexpr uintptr_t VulcanusMove = 0x00831BAC + 2;

    // Chat message call
    static constexpr uintptr_t ShowChatMessage_Call = 0x0078B0BC;

    // Character colors
    static constexpr uintptr_t CharColorLoot = 0x0064B6AB + 1;
    static constexpr uintptr_t CharColorExp = 0x0064C9A0 + 1;

    // Item text add
    static constexpr uintptr_t ItemTextAdd = 0x9CF6AA;

    // Item title color
    static constexpr uintptr_t ItemTitleColor = 0x005C8261;
    static constexpr uintptr_t ItemTitleColorNext = 0x005C8261 + 8;
    static constexpr uintptr_t ItemTitleColorSet = 0x005A9C00;

    // Item description
    static constexpr uintptr_t ItemDescriptionText = 0x005AE921;
    static constexpr uintptr_t ItemDescriptionTextNext = 0x005AE96C;

    // Print global
    static constexpr uintptr_t MainPrintGlobal = 0x00597630;

    // --------------------------
    // Utility Functions
    // --------------------------

    inline static int SafeReadInt(uintptr_t addr) {
        return *reinterpret_cast<int*>(addr);
    }

    inline static void SafeWriteInt(uintptr_t addr, int val) {
        *reinterpret_cast<int*>(addr) = val;
    }

    inline static float SafeReadFloat(uintptr_t addr) {
        return *reinterpret_cast<float*>(addr);
    }

    inline static void SafeWriteFloat(uintptr_t addr, float val) {
        *reinterpret_cast<float*>(addr) = val;
    }

    inline static BYTE SafeReadByte(uintptr_t addr) {
        return *reinterpret_cast<BYTE*>(addr);
    }

    inline static void SafeWriteByte(uintptr_t addr, BYTE val) {
        *reinterpret_cast<BYTE*>(addr) = val;
    }
};

extern MuClientAPIExtended gMuClientApi;