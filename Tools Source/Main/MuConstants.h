#pragma once
// MuConstantsAPI.h - Constantes y utilidades del cliente MU organizadas
// Convierte defines/enums en clases modernas con métodos type-safe.

#include <windows.h>

// --------------------------
// Type definitions
// --------------------------
#define _FC __fastcall
#define _CD __cdecl
#define Naked(Function) void __declspec(naked) Function()

// --------------------------
// Enumerations
// --------------------------

enum class ObjectType : int {
    Player = 1,
    Monster = 2,
    NPC = 4,
    None = 8
};

enum class ClassNumber : int {
    Wizard = 0,
    Knight = 1,
    Elf = 2,
    Magumsa = 3,
    DarkLord = 4,
    Summoner = 5,
    Monk = 6
};

enum class ClassCode : int {
    DarkWizard = 0,
    SoulMaster = 8,
    GrandMaster = 24,
    // ----
    DarkKnight = 1,
    BladeKnight = 9,
    BladeMaster = 25,
    // ----
    Elf = 2,
    MuseElf = 10,
    HighElf = 26,
    // ----
    MagicGladiator = 3,
    DuelMaster = 19,
    // ----
    DarkLord = 4,
    LordEmperor = 20,
    // ----
    Summoner = 5,
    BloodySummoner = 13,
    DimensionMaster = 29,
    // ----
    Monk = 6,
    FirstMaster = 16
};

enum class GameState : int {
    SelectServer = 2,
    SwitchCharacter = 4,
    GameProcess = 5
};

enum class WindowType : int {
    FriendList = 1,
    MoveList = 2,
    Party = 3,
    Quest = 4,
    NPC_Devin = 5,
    Guild = 6,
    Trade = 7,
    Warehouse = 8,
    ChaosBox = 9,
    CommandWindow = 10,
    PetInfo = 11,
    Shop = 12,
    Inventory = 13,
    Store = 14,
    OtherStore = 15,
    Character = 16,
    DevilSquare = 19,
    BloodCastle = 20,
    CreateGuild = 21,
    GuardNPC = 22,
    SeniorNPC = 23,
    GuardNPC2 = 24,
    CastleGateSwitch = 25,
    CatapultNPC = 26,
    CrywolfGate = 29,
    IllusionTemple = 30,
    HeroList = 32,
    ChatWindow = 33,
    FastMenu = 34,
    Options = 35,
    Help = 36,
    FastDial = 39,
    DuelScore = 49,
    SkillTree = 57,
    GoldenArcher1 = 58,
    GoldenArcher2 = 59,
    LuckyCoin1 = 60,
    LuckyCoin2 = 61,
    NPC_Duel = 62,
    NPC_Titus = 63,
    CashShop = 65,
    Lugard = 66,
    QuestList1 = 68,
    QuestList2 = 69,
    Jerint = 70,
    FullMap = 72,
    NPC_Dialog = 73,
    GensInfo = 74,
    NPC_Julia = 75,
    NPC_ChaosMix = 76,
    ExpandInventory = 77,
    ExpandWarehouse = 78,
    MuHelper = 79
};

enum class TextColor : BYTE {
    White = 0x00,
    Blue = 0x01,
    Red = 0x02,
    Gold = 0x03,
    Green = 0x04,
    WhiteRed = 0x05,
    Violet = 0x06,
    WhiteBlue = 0x07,
    WhiteBeige = 0x08,
    GreenBlue = 0x09,
    Gray = 0x0A,
    DarkViolet = 0x0B
};

enum class TextWeight : BYTE {
    Normal = 0x00,
    Bold = 0x01
};

enum class MapNumber : int {
    Lorencia = 0,
    Dungeon = 1,
    Devias = 2,
    Noria = 3,
    LostTower = 4,
    Exile = 5,
    Stadium = 6,
    Atlans = 7,
    Tarkan = 8,
    DevilSquare = 9,
    Icarus = 10,
    BloodCastle1 = 11,
    BloodCastle2 = 12,
    BloodCastle3 = 13,
    BloodCastle4 = 14,
    BloodCastle5 = 15,
    BloodCastle6 = 16,
    BloodCastle7 = 17,
    ChaosCastle1 = 18,
    ChaosCastle2 = 19,
    ChaosCastle3 = 20,
    ChaosCastle4 = 21,
    ChaosCastle5 = 22,
    ChaosCastle6 = 23,
    Kalima1 = 24,
    Kalima2 = 25,
    Kalima3 = 26,
    Kalima4 = 27,
    Kalima5 = 28,
    Kalima6 = 29,
    Kalima7 = 36,
    Loren = 30,
    Trials = 31,
    DevilSquare6 = 32,
    Aida = 33,
    Crywolf = 34,
    Kanturu1 = 37,
    Kanturu3 = 38,
    Kanturu_Event = 39,
    Silent = 40,
    Barracks = 41,
    Refuge = 42,
    Illusion1 = 45,
    Illusion2 = 46,
    Illusion3 = 47,
    Illusion4 = 48,
    Illusion5 = 49,
    Illusion6 = 50,
    Elbeland = 51,
    BloodCastle8 = 52,
    ChaosCastle7 = 53,
    Calmness = 56,
    Raklion = 57,
    RaklionBoss = 58,
    SantaTown = 62,
    Vulcanus = 63,
    Colosseum = 64,
    Karutan1 = 80,
    Karutan2 = 81
};

namespace ItemOption {
    enum Type : int {
        Damage = 80,            // Additional Damage +<N>
        WizardryDamage = 81,
        CurseSpell = 82,
        Defense = 84,           // Additional Defense +<N>
        Luck = 85,              // Default: 0
        HPRecovery = 86,
        LifeIncrease = 87,      // Increase Max HP +4%
        ManaIncrease = 88,      // Increase Max Mana +4%
        DamageDecrease = 89,    // Damage Decrease +4%
        Reflect = 90,           // Reflect Damage +5%
        DefenseSuccess = 91,    // Defense success rate +10%
        IncreaseZen = 92,       // Increases acquisition rate of Zen +30%
        ExcellentDamage = 93,   // Excellent Damage rate +10%
        DamageByLevel = 94,     // Increase Damage +level/20
        IncreaseDamage = 95,    // Increase Damage +%d%
        IncreaseWizardry = 96,  // Increase Wizardry Dmg +level/20
        IncreaseWizardryDmg = 97, // Increase Wizardry Dmg +2%
        IncreaseSpeed = 98,     // Increase Attacking speed +%d
        LifePerMob = 99,        // Increases Life after hunting +life/8
        ManaPerMob = 100,       // Increases Mana after hunting +Mana/8
        IgnoreOpDefense = 103,
        ReturnAttack = 106,     // Return's enemy attack power in <N>%
        CompleteLife = 107,     // Complete recovery of life in <N>% rate
        CompleteMana = 108      // Complete recovery of Mana in <N>% rate
    };
}

namespace ASM {
    enum Opcode : BYTE {
        JMP = 0xE9,
        JE = 0x74,
        JNE = 0x75,
        JGE = 0x7D,
        NOP = 0x90,
        CALL = 0xE8,
        CALLD = 0xFF,
        PUSH = 0x68
    };
}

// --------------------------
// Main API Class
// --------------------------

class MuConstants {
public:
    // --------------------------
    // Constants
    // --------------------------
    static constexpr int ITEM_INTER = 1171;
    static constexpr DWORD MAX_ITEMOPT_BIT = 0x3F;

    // HDK Constants
    static constexpr uintptr_t HDK_SET_ITEM_EFFECT = 0x0057AD82;
    static constexpr uintptr_t HDK_SET_COLOR_EFFECT = 0x0057AEFA;
    static constexpr uintptr_t HDK_ITEM_EFFECT_ALLOW = 0x0057AD8D;
    static constexpr uintptr_t HDK_ITEM_EFFECT_NOT_ALLOW = 0x0057B73B;
    static constexpr uintptr_t HDK_NEXT_ITEM_COLOR = 0x0057AF2E;
    static constexpr uintptr_t MAIN_LANGUAGE = 0x00E8C5C4;

    // Virtual Key Codes
    static constexpr int VK_N = 0x4E;
    static constexpr int VK_R = 0x52;
    static constexpr int VK_O = 0x4F;
    static constexpr int VK_W = 0x57;
    static constexpr int VK_J = 0x4A;
    static constexpr int VK_K = 0x4B;

    // --------------------------
    // Item System
    // --------------------------

    // Original: #define ITEM(x, y) ((x * 512) + y)
    /*inline static constexpr int ITEM(int x, int y) {
        return (x * 512) + y;
    }*/

    #define ITEM(x, y)					((x * 512) + y)

    // Original: #define ITEM2(x, y) ((x * 512) + y + ITEM_INTER)
    inline static constexpr int ITEM2(int x, int y) {
        return (x * 512) + y + ITEM_INTER;
    }

    // Original: #define IS_NEWWINGS(x) ((x < ITEM(12, 180)) ? FALSE : (x > ITEM(12, 215)) ? FALSE : TRUE)
    inline static constexpr bool IsNewWings(int x) {
        return (x >= ITEM(12, 180)) && (x <= ITEM(12, 215));
    }

    // --------------------------
    // Color System
    // --------------------------

    // Original: #define Color4f(r, b, g, o) ((o << 24) + (g << 16) + (b << 8) + r)
    // Esto debe ir fuera de cualquier clase
    #define Color4f(r, b, g, o)			((o << 24) + (g << 16) + (b << 8) + r)


    // Predefined colors
    struct Colors {


        static constexpr DWORD ShinyGreen = Color4f(172, 255, 56, 255);
        static constexpr DWORD ShinyGreen100 = Color4f(172, 255, 56, 100);
        static constexpr DWORD Gold = Color4f(255, 189, 25, 255);
        static constexpr DWORD Gold150 = Color4f(255, 189, 25, 150);
        static constexpr DWORD Gold180 = Color4f(255, 189, 25, 180);
        static constexpr DWORD White = Color4f(255, 255, 255, 255);
        static constexpr DWORD White150 = Color4f(255, 255, 255, 150);
        static constexpr DWORD White180 = Color4f(255, 255, 255, 180);
        static constexpr DWORD Orange = Color4f(255, 105, 25, 255);
        static constexpr DWORD Gray100 = Color4f(211, 211, 211, 100);
        static constexpr DWORD Gray150 = Color4f(50, 50, 50, 150);
        static constexpr DWORD Gray190 = Color4f(50, 50, 50, 190);
        static constexpr DWORD BlowPink = Color4f(220, 20, 60, 255);
        static constexpr DWORD Red = Color4f(225, 0, 0, 255);
        static constexpr DWORD Red2 = Color4f(225, 95, 45, 255);
        static constexpr DWORD Excellent = Color4f(0, 225, 139, 255);
        static constexpr DWORD Ancient = Color4f(1, 223, 119, 255);
        static constexpr DWORD Socket = Color4f(153, 102, 204, 255);
        static constexpr DWORD Blue = Color4f(36, 242, 252, 255);
        static constexpr DWORD Blue250 = Color4f(36, 242, 252, 250);
        static constexpr DWORD Yellow = Color4f(255, 255, 0, 255);
        static constexpr DWORD Yellow170 = Color4f(255, 255, 0, 170);
        static constexpr DWORD Brown = Color4f(69, 39, 18, 255);

    };

    enum ColorMacro
    {
        eShinyGreen = Color4f(172, 255, 56, 255),
        eShinyGreen100 = Color4f(172, 255, 56, 100),
        eGold = Color4f(255, 189, 25, 255),
        eGold150 = Color4f(255, 189, 25, 150),
        eGold180 = Color4f(255, 189, 25, 180),
        eWhite = Color4f(255, 255, 255, 255),
        eWhite150 = Color4f(255, 255, 255, 150),
        eWhite180 = Color4f(255, 255, 255, 180),
        eOrange = Color4f(255, 105, 25, 255),
        eGray100 = Color4f(211, 211, 211, 100),
        eGray150 = Color4f(50, 50, 50, 150),
        eGray190 = Color4f(50, 50, 50, 190),
        eBlowPink = Color4f(220, 20, 60, 255),
        eRed = Color4f(225, 0, 0, 255),
        eRed2 = Color4f(225, 95, 45, 255),
        eExcellent = Color4f(0, 225, 139, 255),
        eAncient = Color4f(1, 223, 119, 255),
        eSocket = Color4f(153, 102, 204, 255),
        eBlue = Color4f(36, 242, 252, 255),
        eBlue250 = Color4f(36, 242, 252, 250),
        eYellow = Color4f(255, 255, 0, 255),
        eYellow170 = Color4f(255, 255, 0, 170),
        eBrown = Color4f(69, 39, 18, 255),
    };

    // --------------------------
    // Character Set Utilities
    // --------------------------

    // Original: #define CS_GET_WEAPON(x, y) ( y | (16 * (x & 0xF0)) )
    inline static constexpr int GetWeaponCS(int x, int y) {
        return y | (16 * (x & 0xF0));
    }

    // Original: #define CS_GET_HELM(x, y, z) ( (32 * (z & 0xF)) + 16 * ((x >> 7) & 1) + (y >> 4) )
    inline static constexpr int GetHelmCS(int x, int y, int z) {
        return (32 * (z & 0xF)) + 16 * ((x >> 7) & 1) + (y >> 4);
    }

    // Original: #define CS_GET_ARMOR(x, y, z) ( (32 * ((z >> 4) & 0xF)) + 16 * ((x >> 6) & 1) + (y & 0xF) )
    inline static constexpr int GetArmorCS(int x, int y, int z) {
        return (32 * ((z >> 4) & 0xF)) + 16 * ((x >> 6) & 1) + (y & 0xF);
    }

    // Original: #define CS_GET_PANTS(x, y, z) ( (32 * (z & 0xF)) + 16 * ((x >> 5) & 1) + (y >> 4) )
    inline static constexpr int GetPantsCS(int x, int y, int z) {
        return (32 * (z & 0xF)) + 16 * ((x >> 5) & 1) + (y >> 4);
    }

    // Original: #define CS_GET_GLOVES(x, y, z) ( (32 * ((z >> 4) & 0xF)) + 16 * ((x >> 4) & 1) + (y & 0xF) )
    inline static constexpr int GetGlovesCS(int x, int y, int z) {
        return (32 * ((z >> 4) & 0xF)) + 16 * ((x >> 4) & 1) + (y & 0xF);
    }

    // Original: #define CS_GET_BOOTS(x, y, z) ( (32 * (z & 0xF)) + 16 * ((x >> 3) & 1) + (y >> 4) )
    inline static constexpr int GetBootsCS(int x, int y, int z) {
        return (32 * (z & 0xF)) + 16 * ((x >> 3) & 1) + (y >> 4);
    }

    // --------------------------
    // Item Options Utilities
    // --------------------------

    // Original: #define GET_ITEMOPT_LEVEL(x) ((x >> 3) & 0xF)
    inline static constexpr int GetItemOptLevel(int x) {
        return (x >> 3) & 0xF;
    }

    // Original: #define SET_ITEMOPT_LEVEL(x) (x << 3)
    inline static constexpr int SetItemOptLevel(int x) {
        return x << 3;
    }

    // Original: #define GET_ITEMOPT0(x) (x & 3)
    inline static constexpr int GetItemOpt0(int x) {
        return x & 3;
    }

    // Original: #define GET_ITEMOPT16(x) (x & 0x40)
    inline static constexpr int GetItemOpt16(int x) {
        return x & 0x40;
    }

    // Original: #define GET_ITEMOPT_SKILL(x) (x >> 7)
    inline static constexpr int GetItemOptSkill(int x) {
        return x >> 7;
    }

    // Original: #define GET_ITEMOPT_LUCK(x) ((x >> 2) & 1)
    inline static constexpr bool GetItemOptLuck(int x) {
        return ((x >> 2) & 1) != 0;
    }

    // Individual option getters
    // Original: #define GET_ITEMOPT_0(x) (x & 1)
    inline static constexpr bool GetItemOpt_0(int x) {
        return (x & 1) != 0;
    }

    // Original: #define GET_ITEMOPT_1(x) (((x & MAX_ITEMOPT_BIT) >> 1) & 1)
    inline static constexpr bool GetItemOpt_1(int x) {
        return (((x & MAX_ITEMOPT_BIT) >> 1) & 1) != 0;
    }

    // Original: #define GET_ITEMOPT_2(x) (((x & MAX_ITEMOPT_BIT) >> 2) & 1)
    inline static constexpr bool GetItemOpt_2(int x) {
        return (((x & MAX_ITEMOPT_BIT) >> 2) & 1) != 0;
    }

    // Original: #define GET_ITEMOPT_3(x) (((x & MAX_ITEMOPT_BIT) >> 3) & 1)
    inline static constexpr bool GetItemOpt_3(int x) {
        return (((x & MAX_ITEMOPT_BIT) >> 3) & 1) != 0;
    }

    // Original: #define GET_ITEMOPT_4(x) (((x & MAX_ITEMOPT_BIT) >> 4) & 1)
    inline static constexpr bool GetItemOpt_4(int x) {
        return (((x & MAX_ITEMOPT_BIT) >> 4) & 1) != 0;
    }

    // Original: #define GET_ITEMOPT_5(x) (((x & MAX_ITEMOPT_BIT) >> 5) & 1)
    inline static constexpr bool GetItemOpt_5(int x) {
        return (((x & MAX_ITEMOPT_BIT) >> 5) & 1) != 0;
    }

    // --------------------------
    // Map Range Checkers
    // --------------------------

    // Original: #define DG_MAP_RANGE(x) (((x)<65)?0:((x)>68)?0:1)
    inline static constexpr bool IsDevilGroundMapRange(int x) {
        return (x >= 65) && (x <= 68);
    }

    // Original: #define CC_MAP_RANGE(x) (((x)<18)?0:((x)>23)?(((x)==53)?1:0):1)
    inline static constexpr bool IsChaosCastleMapRange(int x) {
        if (x < 18) return false;
        if (x > 23) return (x == 53);
        return true;
    }

    // --------------------------
    // Utility Functions
    // --------------------------

    // Original: #define LODWORD(h) ((DWORD)(__int64(h) & __int64(0xffffffff)))
    inline static constexpr DWORD LowDWord(__int64 h) {
        return static_cast<DWORD>(h & 0xffffffff);
    }

    // Enhanced map checking utilities
    inline static bool IsBloodCastle(MapNumber map) {
        int mapVal = static_cast<int>(map);
        return (mapVal >= static_cast<int>(MapNumber::BloodCastle1) &&
            mapVal <= static_cast<int>(MapNumber::BloodCastle7)) ||
            mapVal == static_cast<int>(MapNumber::BloodCastle8);
    }

    inline static bool IsChaosCastle(MapNumber map) {
        int mapVal = static_cast<int>(map);
        return (mapVal >= static_cast<int>(MapNumber::ChaosCastle1) &&
            mapVal <= static_cast<int>(MapNumber::ChaosCastle6)) ||
            mapVal == static_cast<int>(MapNumber::ChaosCastle7);
    }

    inline static bool IsKalima(MapNumber map) {
        int mapVal = static_cast<int>(map);
        return (mapVal >= static_cast<int>(MapNumber::Kalima1) &&
            mapVal <= static_cast<int>(MapNumber::Kalima6)) ||
            mapVal == static_cast<int>(MapNumber::Kalima7);
    }

    inline static bool IsIllusion(MapNumber map) {
        int mapVal = static_cast<int>(map);
        return mapVal >= static_cast<int>(MapNumber::Illusion1) &&
            mapVal <= static_cast<int>(MapNumber::Illusion6);
    }

    inline static bool IsKarutan(MapNumber map) {
        int mapVal = static_cast<int>(map);
        return mapVal == static_cast<int>(MapNumber::Karutan1) ||
            mapVal == static_cast<int>(MapNumber::Karutan2);
    }

    // Class utilities
    inline static bool IsMasterClass(ClassCode classCode) {
        int code = static_cast<int>(classCode);
        return code >= 8; // All master classes are >= 8
    }

    inline static ClassNumber GetBaseClass(ClassCode classCode) {
        int code = static_cast<int>(classCode);
        switch (code) {
        case 0: case 8: case 24: return ClassNumber::Wizard;
        case 1: case 9: case 25: return ClassNumber::Knight;
        case 2: case 10: case 26: return ClassNumber::Elf;
        case 3: case 19: return ClassNumber::Magumsa;
        case 4: case 20: return ClassNumber::DarkLord;
        case 5: case 13: case 29: return ClassNumber::Summoner;
        case 6: case 16: return ClassNumber::Monk;
        default: return ClassNumber::Wizard;
        }
    }

    // Item option helpers
    inline static bool HasExcellentOption(int options, int optionIndex) {
        if (optionIndex < 0 || optionIndex > 5) return false;
        return (((options & MAX_ITEMOPT_BIT) >> optionIndex) & 1) != 0;
    }

    inline static int SetExcellentOption(int options, int optionIndex, bool enabled) {
        if (optionIndex < 0 || optionIndex > 5) return options;
        if (enabled) {
            return options | (1 << optionIndex);
        }
        else {
            return options & ~(1 << optionIndex);
        }
    }

    // Color helpers
    inline static DWORD MakeColorWithAlpha(DWORD baseColor, BYTE alpha) {
        return (baseColor & 0x00FFFFFF) | (static_cast<DWORD>(alpha) << 24);
    }

    inline static BYTE GetColorRed(DWORD color) {
        return static_cast<BYTE>(color & 0xFF);
    }

    inline static BYTE GetColorGreen(DWORD color) {
        return static_cast<BYTE>((color >> 8) & 0xFF);
    }

    inline static BYTE GetColorBlue(DWORD color) {
        return static_cast<BYTE>((color >> 16) & 0xFF);
    }

    inline static BYTE GetColorAlpha(DWORD color) {
        return static_cast<BYTE>((color >> 24) & 0xFF);
    }

    // --------------------------
    // Item Categories
    // --------------------------

    struct ItemCategories {
        // Weapons
        static constexpr int WEAPON_START = ITEM(0, 0);
        static constexpr int WEAPON_END = ITEM(5, 255);

        // Armor sets
        static constexpr int ARMOR_START = ITEM(6, 0);
        static constexpr int ARMOR_END = ITEM(11, 255);

        // Wings
        static constexpr int WINGS_START = ITEM(12, 0);
        static constexpr int WINGS_END = ITEM(12, 255);
        static constexpr int NEW_WINGS_START = ITEM(12, 180);
        static constexpr int NEW_WINGS_END = ITEM(12, 215);

        // Jewels
        static constexpr int JEWEL_START = ITEM(14, 0);
        static constexpr int JEWEL_END = ITEM(14, 255);

        // Potions
        static constexpr int POTION_START = ITEM(14, 0);
        static constexpr int POTION_END = ITEM(14, 50);

        static bool IsWeapon(int itemID) {
            return itemID >= WEAPON_START && itemID <= WEAPON_END;
        }

        static bool IsArmor(int itemID) {
            return itemID >= ARMOR_START && itemID <= ARMOR_END;
        }

        static bool IsWings(int itemID) {
            return itemID >= WINGS_START && itemID <= WINGS_END;
        }

        static bool IsNewWings(int itemID) {
            return itemID >= NEW_WINGS_START && itemID <= NEW_WINGS_END;
        }

        static bool IsJewel(int itemID) {
            return itemID >= JEWEL_START && itemID <= JEWEL_END;
        }

        static bool IsPotion(int itemID) {
            return itemID >= POTION_START && itemID <= POTION_END;
        }
    };

    // --------------------------
    // Text Utilities
    // --------------------------

    struct TextUtils {
        static DWORD GetColorFromTextColor(TextColor color) {
            switch (color) {
            case TextColor::White: return Colors::White;
            case TextColor::Blue: return Colors::Blue;
            case TextColor::Red: return Colors::Red;
            case TextColor::Gold: return Colors::Gold;
            case TextColor::Green: return Colors::ShinyGreen;
            default: return Colors::White;
            }
        }

        static const char* GetClassName(ClassCode classCode) {
            switch (classCode) {
            case ClassCode::DarkWizard: return "Dark Wizard";
            case ClassCode::SoulMaster: return "Soul Master";
            case ClassCode::GrandMaster: return "Grand Master";
            case ClassCode::DarkKnight: return "Dark Knight";
            case ClassCode::BladeKnight: return "Blade Knight";
            case ClassCode::BladeMaster: return "Blade Master";
            case ClassCode::Elf: return "Elf";
            case ClassCode::MuseElf: return "Muse Elf";
            case ClassCode::HighElf: return "High Elf";
            case ClassCode::MagicGladiator: return "Magic Gladiator";
            case ClassCode::DuelMaster: return "Duel Master";
            case ClassCode::DarkLord: return "Dark Lord";
            case ClassCode::LordEmperor: return "Lord Emperor";
            case ClassCode::Summoner: return "Summoner";
            case ClassCode::BloodySummoner: return "Bloody Summoner";
            case ClassCode::DimensionMaster: return "Dimension Master";
            case ClassCode::Monk: return "Monk";
            case ClassCode::FirstMaster: return "First Master";
            default: return "Unknown";
            }
        }

        static const char* GetMapName(MapNumber map) {
            switch (map) {
            case MapNumber::Lorencia: return "Lorencia";
            case MapNumber::Dungeon: return "Dungeon";
            case MapNumber::Devias: return "Devias";
            case MapNumber::Noria: return "Noria";
            case MapNumber::LostTower: return "Lost Tower";
            case MapNumber::Exile: return "Exile";
            case MapNumber::Stadium: return "Stadium";
            case MapNumber::Atlans: return "Atlans";
            case MapNumber::Tarkan: return "Tarkan";
            case MapNumber::DevilSquare: return "Devil Square";
            case MapNumber::Icarus: return "Icarus";
            case MapNumber::BloodCastle1: return "Blood Castle 1";
            case MapNumber::BloodCastle2: return "Blood Castle 2";
            case MapNumber::BloodCastle3: return "Blood Castle 3";
            case MapNumber::BloodCastle4: return "Blood Castle 4";
            case MapNumber::BloodCastle5: return "Blood Castle 5";
            case MapNumber::BloodCastle6: return "Blood Castle 6";
            case MapNumber::BloodCastle7: return "Blood Castle 7";
            case MapNumber::BloodCastle8: return "Blood Castle 8";
            case MapNumber::ChaosCastle1: return "Chaos Castle 1";
            case MapNumber::ChaosCastle2: return "Chaos Castle 2";
            case MapNumber::ChaosCastle3: return "Chaos Castle 3";
            case MapNumber::ChaosCastle4: return "Chaos Castle 4";
            case MapNumber::ChaosCastle5: return "Chaos Castle 5";
            case MapNumber::ChaosCastle6: return "Chaos Castle 6";
            case MapNumber::ChaosCastle7: return "Chaos Castle 7";
            case MapNumber::Kalima1: return "Kalima 1";
            case MapNumber::Kalima2: return "Kalima 2";
            case MapNumber::Kalima3: return "Kalima 3";
            case MapNumber::Kalima4: return "Kalima 4";
            case MapNumber::Kalima5: return "Kalima 5";
            case MapNumber::Kalima6: return "Kalima 6";
            case MapNumber::Kalima7: return "Kalima 7";
            case MapNumber::Loren: return "Loren Market";
            case MapNumber::Trials: return "Trials";
            case MapNumber::DevilSquare6: return "Devil Square 6";
            case MapNumber::Aida: return "Aida";
            case MapNumber::Crywolf: return "Crywolf";
            case MapNumber::Kanturu1: return "Kanturu 1";
            case MapNumber::Kanturu3: return "Kanturu 3";
            case MapNumber::Kanturu_Event: return "Kanturu Event";
            case MapNumber::Silent: return "Silent Map";
            case MapNumber::Barracks: return "Barracks";
            case MapNumber::Refuge: return "Refuge";
            case MapNumber::Illusion1: return "Illusion Temple 1";
            case MapNumber::Illusion2: return "Illusion Temple 2";
            case MapNumber::Illusion3: return "Illusion Temple 3";
            case MapNumber::Illusion4: return "Illusion Temple 4";
            case MapNumber::Illusion5: return "Illusion Temple 5";
            case MapNumber::Illusion6: return "Illusion Temple 6";
            case MapNumber::Elbeland: return "Elbeland";
            case MapNumber::Calmness: return "Calmness";
            case MapNumber::Raklion: return "Raklion";
            case MapNumber::RaklionBoss: return "Raklion Boss";
            case MapNumber::SantaTown: return "Santa Town";
            case MapNumber::Vulcanus: return "Vulcanus";
            case MapNumber::Colosseum: return "Colosseum";
            case MapNumber::Karutan1: return "Karutan 1";
            case MapNumber::Karutan2: return "Karutan 2";
            default: return "Unknown Map";
            }
        }
    };

    // --------------------------
    // Memory Addresses
    // --------------------------

    struct MemoryAddresses {
        static constexpr uintptr_t MAIN_LANGUAGE = 0x00E8C5C4;

        // HDK addresses
        static constexpr uintptr_t HDK_SET_ITEM_EFFECT = 0x0057AD82;
        static constexpr uintptr_t HDK_SET_COLOR_EFFECT = 0x0057AEFA;
        static constexpr uintptr_t HDK_ITEM_EFFECT_ALLOW = 0x0057AD8D;
        static constexpr uintptr_t HDK_ITEM_EFFECT_NOT_ALLOW = 0x0057B73B;
        static constexpr uintptr_t HDK_NEXT_ITEM_COLOR = 0x0057AF2E;
    };

    // --------------------------
    // Easy access to main language
    // --------------------------
    inline static DWORD& MainLanguage() {
        return *reinterpret_cast<DWORD*>(MemoryAddresses::MAIN_LANGUAGE);
    }
};

// --------------------------
// Convenience typedefs
// --------------------------
using MuConst = MuConstants;
using MuColors = MuConstants::Colors;
using MuItems = MuConstants::ItemCategories;
using MuText = MuConstants::TextUtils;

extern MuConst  g_muConstants;
extern MuColors g_muColors;
extern MuItems  g_muItems;
extern MuText   g_muText;

// End of MuConstantsAPI.h