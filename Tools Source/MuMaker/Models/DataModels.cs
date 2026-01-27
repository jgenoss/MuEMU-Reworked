// MuMaker - Data Models
// Contains all data structures for accounts, characters, guilds, and items

namespace MuMaker.Models
{
    #region Account Data
    /// <summary>
    /// Account information structure
    /// </summary>
    public struct AccountData
    {
        /// <summary>Account ID (username)</summary>
        public string AccountId;

        /// <summary>Account ID for display</summary>
        public string DisplayAccountId;

        /// <summary>Account password</summary>
        public string Password;

        /// <summary>Serial number</summary>
        public string SerialNumber;

        /// <summary>Email address</summary>
        public string Email;

        /// <summary>Block code (ban status)</summary>
        public string BlockCode;

        /// <summary>Account is loaded flag</summary>
        public bool IsLoaded;
    }

    /// <summary>
    /// Manages current account data
    /// </summary>
    public static class AccountManager
    {
        public static AccountData CurrentAccount;
    }
    #endregion

    #region Character Data
    /// <summary>
    /// Character information structure
    /// </summary>
    public struct CharacterData
    {
        /// <summary>Associated account ID</summary>
        public string AccountId;

        /// <summary>Character name</summary>
        public string Name;

        /// <summary>Character level</summary>
        public string Level;

        /// <summary>Level up points available</summary>
        public string LevelUpPoints;

        /// <summary>Experience points</summary>
        public string Experience;

        /// <summary>Strength stat</summary>
        public string Strength;

        /// <summary>Dexterity stat</summary>
        public string Dexterity;

        /// <summary>Vitality stat</summary>
        public string Vitality;

        /// <summary>Energy stat</summary>
        public string Energy;

        /// <summary>Leadership stat (for Dark Lord)</summary>
        public string Leadership;

        /// <summary>Fruit points</summary>
        public string FruitPoints;

        /// <summary>PK level</summary>
        public string PkLevel;

        /// <summary>PK count</summary>
        public string PkCount;

        /// <summary>PK time</summary>
        public string PkTime;

        /// <summary>Character class</summary>
        public string CharacterClass;

        /// <summary>Control code (GM level)</summary>
        public string ControlCode;

        /// <summary>Reset count</summary>
        public string ResetCount;

        /// <summary>Quest data (hex string)</summary>
        public string QuestData;

        /// <summary>Magic/Skill list (hex string)</summary>
        public string MagicList;

        /// <summary>Map number</summary>
        public int MapNumber;

        /// <summary>Map X position</summary>
        public int MapPosX;

        /// <summary>Map Y position</summary>
        public int MapPosY;
    }

    /// <summary>
    /// Default character class stats
    /// </summary>
    public struct DefaultClassStats
    {
        public string Strength;
        public string Dexterity;
        public string Vitality;
        public string Energy;
        public string Leadership;
        public string Level;
        public string LevelUpPoints;
    }

    /// <summary>
    /// Manages current character data
    /// </summary>
    public static class CharacterManager
    {
        public static CharacterData CurrentCharacter;
        public static CharacterData DefaultStats;
    }
    #endregion

    #region Warehouse Data
    /// <summary>
    /// Warehouse/Inventory data structure
    /// </summary>
    public struct WarehouseData
    {
        /// <summary>Warehouse items (hex string)</summary>
        public string WarehouseItems;

        /// <summary>Warehouse money</summary>
        public string WarehouseMoney;

        /// <summary>Inventory items (hex string)</summary>
        public string InventoryItems;

        /// <summary>Inventory money</summary>
        public string InventoryMoney;

        /// <summary>Extended warehouse number</summary>
        public int ExtendedWarehouseNumber;
    }

    /// <summary>
    /// Manages warehouse data
    /// </summary>
    public static class WarehouseManager
    {
        public static WarehouseData CurrentWarehouse;
    }
    #endregion

    #region Guild Data
    /// <summary>
    /// Guild information structure
    /// </summary>
    public struct GuildData
    {
        /// <summary>Guild master name</summary>
        public string MasterName;

        /// <summary>Guild name</summary>
        public string GuildName;

        /// <summary>Guild mark/emblem (hex string)</summary>
        public string GuildMark;

        /// <summary>Guild union number</summary>
        public string UnionNumber;

        /// <summary>Rival guild number</summary>
        public string RivalNumber;

        /// <summary>Guild notice/message</summary>
        public string Notice;

        /// <summary>Guild score</summary>
        public string Score;

        /// <summary>Reserved field 1</summary>
        public string Reserved1;

        /// <summary>Reserved field 2</summary>
        public string Reserved2;

        /// <summary>Guild type</summary>
        public string GuildType;

        /// <summary>Member count</summary>
        public string MemberCount;
    }

    /// <summary>
    /// Manages guild data
    /// </summary>
    public static class GuildManager
    {
        public static GuildData CurrentGuild;
    }
    #endregion

    #region Item Data
    /// <summary>
    /// Item information structure
    /// </summary>
    public struct ItemData
    {
        #region Basic Info
        /// <summary>Item number/index</summary>
        public string ItemNumber;

        /// <summary>Item type</summary>
        public string ItemType;

        /// <summary>Item ID</summary>
        public string ItemId;

        /// <summary>Item name</summary>
        public string Name;

        /// <summary>Width in inventory slots</summary>
        public string Width;

        /// <summary>Height in inventory slots</summary>
        public string Height;

        /// <summary>Z dimension</summary>
        public string Depth;

        /// <summary>Durability</summary>
        public string Durability;
        #endregion

        #region Enhancement
        /// <summary>Reserved field</summary>
        public string Reserved;

        /// <summary>Item level (+0 to +15)</summary>
        public string ItemLevel;

        /// <summary>Level display string</summary>
        public string LevelDisplay;

        /// <summary>Base level requirement</summary>
        public string BaseLevelRequirement;

        /// <summary>Item additional level</summary>
        public string AdditionalLevel;

        /// <summary>Luck option</summary>
        public string LuckOption;

        /// <summary>Skill option</summary>
        public string SkillOption;

        /// <summary>Option level (additional damage/defense)</summary>
        public string OptionLevel;
        #endregion

        #region Options Flags
        /// <summary>Has option flag</summary>
        public bool HasOption;

        /// <summary>Has luck flag</summary>
        public bool HasLuck;

        /// <summary>Has skill flag</summary>
        public bool HasSkill;

        /// <summary>Is ancient item flag</summary>
        public bool IsAncient;

        /// <summary>Has socket flag</summary>
        public bool HasSocket;
        #endregion

        #region Excellent Options
        /// <summary>Set item option description</summary>
        public string SetItemOption;

        /// <summary>Reserved option field</summary>
        public string ReservedOption;

        /// <summary>Reserved option field 2</summary>
        public string ReservedOption2;

        /// <summary>Excellent options bitfield</summary>
        public string ExcellentOptions;

        /// <summary>Excellent option display</summary>
        public string ExcellentDisplay;

        /// <summary>Ancient option</summary>
        public string AncientOption;

        /// <summary>Harmony/Refinery option</summary>
        public string HarmonyOption;

        /// <summary>Socket options</summary>
        public string SocketOptions;

        /// <summary>Set item options display</summary>
        public string SetOptionsDisplay;

        /// <summary>Additional options display</summary>
        public string AdditionalOptions;

        /// <summary>Serial number (hex)</summary>
        public string SerialNumber;
        #endregion

        #region Numeric Values
        /// <summary>Excellent option value</summary>
        public int ExcellentValue;

        /// <summary>Slot position</summary>
        public int SlotPosition;

        /// <summary>Refinery option value</summary>
        public int RefineryValue;

        /// <summary>Jewel of Harmony option</summary>
        public int JewelOfHarmonyValue;

        /// <summary>Reserved int field</summary>
        public int ReservedInt;

        /// <summary>Set item value</summary>
        public int SetItemValue;
        #endregion

        #region Set Item Info
        /// <summary>Set item name 1</summary>
        public string SetItemName1;

        /// <summary>Set item name 2</summary>
        public string SetItemName2;

        /// <summary>Additional display fields</summary>
        public string Display1;
        public string Display2;
        public string Display3;
        public string Display4;
        public string Display5;
        public string Display6;
        #endregion
    }

    /// <summary>
    /// Manages item data for different contexts
    /// </summary>
    public static class ItemManager
    {
        /// <summary>Currently selected item</summary>
        public static ItemData SelectedItem;

        /// <summary>Item being viewed/edited</summary>
        public static ItemData ViewedItem;

        /// <summary>Template item for creation</summary>
        public static ItemData TemplateItem;
    }
    #endregion
}
