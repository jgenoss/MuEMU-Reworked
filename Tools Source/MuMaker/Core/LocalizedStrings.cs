// MuMaker - Localized Strings
// Contains all UI strings loaded from language files

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using System.Runtime.CompilerServices;

namespace MuMaker.Core
{
    /// <summary>
    /// Localized UI strings loaded from language INI files
    /// </summary>
    public static class LocalizedStrings
    {
        #region Language Settings
        /// <summary>Current language name</summary>
        public static string CurrentLanguage;

        /// <summary>Language flag image path</summary>
        public static string LanguageFlagPath;

        /// <summary>Language code (first 3 characters)</summary>
        public static string LanguageCode;
        #endregion

        #region Common UI Strings
        /// <summary>Close button text</summary>
        public static object Close;

        /// <summary>Minimize button text</summary>
        public static object Minimize;

        /// <summary>Language selector text</summary>
        public static object Language;

        /// <summary>Search button text</summary>
        public static object Search;

        /// <summary>Account label text</summary>
        public static object Account;

        /// <summary>Character label text</summary>
        public static object Character;
        #endregion

        #region Selection Messages
        /// <summary>Select account message</summary>
        public static object SelectAccount;

        /// <summary>Select character message</summary>
        public static object SelectCharacter;

        /// <summary>Select guild message</summary>
        public static object SelectGuild;
        #endregion

        #region Labels
        /// <summary>Photo label</summary>
        public static object Photo;

        /// <summary>Level label</summary>
        public static object Level;

        /// <summary>Option label</summary>
        public static object Option;

        /// <summary>Equipment label</summary>
        public static object Equipment;

        /// <summary>Inventory label</summary>
        public static object Inventory;

        /// <summary>Vault/Warehouse label</summary>
        public static object Vault;

        /// <summary>Load button text</summary>
        public static object Load;
        #endregion

        #region Warehouse Messages
        /// <summary>No vault found message</summary>
        public static object NoVault;

        /// <summary>Create vault message</summary>
        public static object CreateVault;

        /// <summary>No inventory found message</summary>
        public static object NoInventory;

        /// <summary>Create inventory message</summary>
        public static object CreateInventory;
        #endregion

        #region Action Buttons
        /// <summary>Delete button text</summary>
        public static object Delete;

        /// <summary>Clear button text</summary>
        public static object Clear;

        /// <summary>All option text</summary>
        public static object All;

        /// <summary>Selected option text</summary>
        public static object Selected;

        /// <summary>Any serials text</summary>
        public static object AnySerials;
        #endregion

        #region Account Related
        /// <summary>Account infractions text</summary>
        public static object AccountInfractions;

        /// <summary>Related accounts text</summary>
        public static object RelatedAccounts;
        #endregion

        #region Navigation
        /// <summary>Characters menu text</summary>
        public static object Characters;

        /// <summary>Maps menu text</summary>
        public static object Maps;

        /// <summary>Apply coordinates text</summary>
        public static object ApplyCoordinates;
        #endregion

        #region Warning Messages
        /// <summary>Warning dialog title</summary>
        public static object Warning;

        /// <summary>Wrong item size warning</summary>
        public static object WrongItemSize;

        /// <summary>Error inserting item</summary>
        public static object ErrorInsertItem;

        /// <summary>Wrong delete item warning</summary>
        public static object WrongDeleteItem;

        /// <summary>Error deleting item</summary>
        public static object ErrorDeleteItem;
        #endregion

        #region Inventory/Warehouse Warnings
        /// <summary>Wrong inventory warning</summary>
        public static object WrongInventory;

        /// <summary>Wrong create inventory warning</summary>
        public static object WrongCreateInventory;

        /// <summary>Error creating inventory</summary>
        public static object CreateInventoryError;

        /// <summary>Wrong reset inventory warning</summary>
        public static object WrongResetInventory;

        /// <summary>Error resetting inventory</summary>
        public static object ResetInventoryError;

        /// <summary>Warehouse size warning</summary>
        public static object WarehouseSizeWarning;

        /// <summary>Wrong create vault warning</summary>
        public static object WrongCreateVault;

        /// <summary>Wrong create extra vault warning</summary>
        public static object WrongCreateExtraVault;

        /// <summary>Error creating vault</summary>
        public static object CreateWarehouseError;

        /// <summary>Wrong reset vault warning</summary>
        public static object WrongResetVault;

        /// <summary>Error resetting vault</summary>
        public static object ResetWarehouseError;
        #endregion

        #region Skill Messages
        /// <summary>Wrong skills warning</summary>
        public static object WrongSkills;

        /// <summary>Wrong delete skills warning</summary>
        public static object WrongDeleteSkills;

        /// <summary>Error deleting skills</summary>
        public static object ErrorDeleteSkills;

        /// <summary>Wrong create skills warning</summary>
        public static object WrongCreateSkills;

        /// <summary>Error creating skills</summary>
        public static object ErrorCreateSkills;

        /// <summary>Wrong reset skills warning</summary>
        public static object WrongResetSkills;

        /// <summary>Error resetting skills</summary>
        public static object ErrorResetSkills;

        /// <summary>Wrong maps warning</summary>
        public static object WrongMaps;
        #endregion

        #region Refinery Options (Placeholders)
        public static object RefineryOption1_1 = "No Refinery 1st Options";
        public static object RefineryOption1_2 = "No Refinery 2nd Options";
        public static object RefineryOption2_1 = "No Refinery 1st Options";
        public static object RefineryOption2_2 = "No Refinery 2nd Options";
        public static object RefineryOption3_1 = "No Refinery 1st Options";
        public static object RefineryOption3_2 = "No Refinery 2nd Options";
        public static object RefineryOption4_1 = "No Refinery 1st Options";
        public static object RefineryOption4_2 = "No Refinery 2nd Options";
        public static object RefineryOption5_1 = "No Refinery 1st Options";
        public static object RefineryOption5_2 = "No Refinery 2nd Options";
        public static object RefineryOption6_1 = "No Refinery 1st Options";
        public static object RefineryOption6_2 = "No Refinery 2nd Options";
        public static object RefineryOption7_1 = "No Refinery 1st Options";
        public static object RefineryOption7_2 = "No Refinery 2nd Options";
        #endregion

        #region Effect Placeholders
        public static object NoEffect1 = "NO EFFECT";
        public static object NoEffect2 = "NO EFFECT";
        public static object NoEffect3 = "NO EFFECT";
        public static object NoEffect4 = "NO EFFECT";
        public static object NoEffect5 = "NO EFFECT";
        public static object NoEffect6 = "NO EFFECT";
        public static object NoEffect7 = "NO EFFECT";
        public static object NoEffect8 = "NO EFFECT";
        public static object NoEffect9 = "NO EFFECT";
        public static object NoEffect10 = "NO EFFECT";
        public static object NoEffect11 = "NO EFFECT";
        public static object NoEffect12 = "NO EFFECT";
        public static object NoEffect13 = "NO EFFECT";
        public static object NoEffect14 = "NO EFFECT";
        public static object NoEffect15 = "NO EFFECT";
        public static object NoEffect16 = "NO EFFECT";
        public static object NoEffect17 = "NO EFFECT";
        public static object NoEffect18 = "NO EFFECT";
        public static object NoEffect19 = "NO EFFECT";
        public static object NoEffect20 = "NO EFFECT";
        public static object NoEffect21 = "NO EFFECT";
        public static object NoEffect22 = "NO EFFECT";
        public static object NoEffect23 = "NO EFFECT";
        public static object NoEffect24 = "NO EFFECT";
        #endregion

        #region Initialization
        /// <summary>
        /// smethod_0 - Loads all localized strings from the language file (original method name)
        /// </summary>
        public static void smethod_0(string language) => Initialize(language);

        /// <summary>
        /// Loads all localized strings from the language file
        /// </summary>
        /// <param name="language">Language name (e.g., "English", "Espanol")</param>
        public static void Initialize(string language)
        {
            CurrentLanguage = language;
            LanguageFlagPath = "Lang/" + language + ".gif";
            LanguageCode = Strings.Mid(language, 1, 3);

            // Load all strings from language file
            Close = IniHelper.ReadLanguageString(language, "Close");
            Minimize = IniHelper.ReadLanguageString(language, "Minimize");
            Language = IniHelper.ReadLanguageString(language, "Idioma");
            Search = IniHelper.ReadLanguageString(language, "Search");
            Account = IniHelper.ReadLanguageString(language, "Account");
            Character = IniHelper.ReadLanguageString(language, "Chart");

            SelectAccount = Operators.ConcatenateObject(
                Operators.ConcatenateObject(" ", IniHelper.ReadLanguageString(language, "SelecAcount")), " ");
            SelectCharacter = Operators.ConcatenateObject(
                Operators.ConcatenateObject(" ", IniHelper.ReadLanguageString(language, "SelecPerson")), " ");
            SelectGuild = IniHelper.ReadLanguageString(language, "SelecGuild");

            Photo = IniHelper.ReadLanguageString(language, "Foto");
            Level = IniHelper.ReadLanguageString(language, "Level");
            Option = IniHelper.ReadLanguageString(language, "Opcion");
            Equipment = IniHelper.ReadLanguageString(language, "Equipment");
            Inventory = IniHelper.ReadLanguageString(language, "Invent");
            Vault = IniHelper.ReadLanguageString(language, "Vault");
            Load = IniHelper.ReadLanguageString(language, "Load");

            NoVault = IniHelper.ReadLanguageString(language, "NoVault");
            CreateVault = IniHelper.ReadLanguageString(language, "CreateVault");
            NoInventory = IniHelper.ReadLanguageString(language, "NoInvent");
            CreateInventory = IniHelper.ReadLanguageString(language, "CreateInvent");

            Delete = IniHelper.ReadLanguageString(language, "Delete");
            Clear = IniHelper.ReadLanguageString(language, "Clear");
            All = IniHelper.ReadLanguageString(language, "All");
            Selected = IniHelper.ReadLanguageString(language, "Selected");
            AnySerials = IniHelper.ReadLanguageString(language, "AnySerials");

            AccountInfractions = IniHelper.ReadLanguageString(language, "InfracAccount");
            RelatedAccounts = IniHelper.ReadLanguageString(language, "RelatedAccount");

            Characters = IniHelper.ReadLanguageString(language, "Charts");
            Maps = IniHelper.ReadLanguageString(language, "Maps");
            ApplyCoordinates = IniHelper.ReadLanguageString(language, "AplyCoord");

            Warning = IniHelper.ReadLanguageString(language, "Warning");
            WrongItemSize = IniHelper.ReadLanguageString(language, "WrSizeIT");
            ErrorInsertItem = IniHelper.ReadLanguageString(language, "ErInsertIT");
            WrongDeleteItem = IniHelper.ReadLanguageString(language, "WrDeleteIT");
            ErrorDeleteItem = IniHelper.ReadLanguageString(language, "ErDeleteIT");

            WrongInventory = IniHelper.ReadLanguageString(language, "WrInvent");
            WrongCreateInventory = IniHelper.ReadLanguageString(language, "WrCreateINV");
            CreateInventoryError = IniHelper.ReadLanguageString(language, "ErCreateINV");
            WrongResetInventory = IniHelper.ReadLanguageString(language, "WrResetINV");
            ResetInventoryError = IniHelper.ReadLanguageString(language, "ErResetINV");

            WarehouseSizeWarning = IniHelper.ReadLanguageString(language, "WrVault");
            WrongCreateVault = IniHelper.ReadLanguageString(language, "WrCreateVault");
            WrongCreateExtraVault = IniHelper.ReadLanguageString(language, "WrCreateExtraVault");
            CreateWarehouseError = IniHelper.ReadLanguageString(language, "ErCreateVault");
            WrongResetVault = IniHelper.ReadLanguageString(language, "WrResetVault");
            ResetWarehouseError = IniHelper.ReadLanguageString(language, "ErResetVault");

            WrongSkills = IniHelper.ReadLanguageString(language, "WrSkills");
            WrongDeleteSkills = IniHelper.ReadLanguageString(language, "WrDeleteSkills");
            ErrorDeleteSkills = IniHelper.ReadLanguageString(language, "ErDeleteSkills");
            WrongCreateSkills = IniHelper.ReadLanguageString(language, "WrCreateSkills");
            ErrorCreateSkills = IniHelper.ReadLanguageString(language, "ErCreateSkills");
            WrongResetSkills = IniHelper.ReadLanguageString(language, "WrResetSkills");
            ErrorResetSkills = IniHelper.ReadLanguageString(language, "ErResetSkills");
            WrongMaps = IniHelper.ReadLanguageString(language, "WrMaps");
        }
        #endregion
    }
}
