// MuMaker - Data Models
// Contains all data structures for accounts, characters, guilds, items, and warehouses
// Maintains backward compatibility with original field names (string_0, string_1, etc.)

using Microsoft.VisualBasic.CompilerServices;

namespace MuMaker.Models
{
    #region Account Data (Class22)

    /// <summary>
    /// Account information structure (Struct0)
    /// </summary>
    public struct Struct0
    {
        public string string_0;  // Account number/index
        public string string_1;  // Account ID (username)
        public string string_2;  // Password
        public string string_3;  // Personal ID / Serial
        public string string_4;  // Email
        public string string_5;  // Block code (ban status)
        public bool bool_0;      // Is online/loaded
    }

    /// <summary>
    /// Character information structure (Struct1)
    /// </summary>
    public struct Struct1
    {
        public string string_0;  // Account ID
        public string string_1;  // Character name
        public string string_2;  // Level
        public string string_3;  // Level up points
        public string string_4;  // Experience
        public string string_5;  // Strength
        public string string_6;  // Dexterity (Agility)
        public string string_7;  // Vitality
        public string string_8;  // Energy
        public string string_9;  // Leadership (Command)
        public string string_10; // Fruit points
        public string string_11; // PK level
        public string string_12; // PK count
        public string string_13; // PK time
        public string string_14; // Character class
        public string string_15; // Control code (GM)
        public string string_16; // Reset count
        public string string_17; // Quest data
        public string string_18; // Magic/Skill list
        public int int_0;        // Map number
        public int int_1;        // Map X position
        public int int_2;        // Map Y position
    }

    /// <summary>
    /// Warehouse information structure (Struct2)
    /// </summary>
    public struct Struct2
    {
        public string string_0;  // Warehouse items (hex)
        public string string_1;  // Warehouse money
        public string string_2;  // Inventory items (hex)
        public string string_3;  // Inventory money
        public int int_0;        // Extended warehouse number
    }

    /// <summary>
    /// Account data manager - replaces Class22
    /// </summary>
    [StandardModule]
    internal sealed class AccountData
    {
        public static Struct0 struct0_0;  // Current account
        public static Struct1 struct1_0;  // Current character
        public static Struct1 struct1_1;  // Secondary character (for stats comparison)
        public static Struct2 struct2_0;  // Current warehouse

        // Descriptive aliases
        public static Struct0 CurrentAccount { get => struct0_0; set => struct0_0 = value; }
        public static Struct1 CurrentCharacter { get => struct1_0; set => struct1_0 = value; }
        public static Struct1 SecondaryCharacter { get => struct1_1; set => struct1_1 = value; }
        public static Struct2 CurrentWarehouse { get => struct2_0; set => struct2_0 = value; }
    }

    #endregion

    #region Guild Data (Class23)

    /// <summary>
    /// Guild information structure (Struct3)
    /// </summary>
    public struct Struct3
    {
        public string string_0;  // Guild master name
        public string string_1;  // Guild name
        public string string_2;  // Guild mark/emblem (hex)
        public string string_3;  // Union number
        public string string_4;  // Rival number
        public string string_5;  // Notice/message
        public string string_6;  // Score
        public string string_7;  // Union guild name
        public string string_8;  // Rival guild name
        public string string_9;  // Guild type
        public string string_10; // Member count
    }

    /// <summary>
    /// Guild data manager - replaces Class23
    /// </summary>
    [StandardModule]
    internal sealed class GuildData
    {
        public static Struct3 struct3_0;  // Current guild

        // Descriptive alias
        public static Struct3 CurrentGuild { get => struct3_0; set => struct3_0 = value; }
    }

    #endregion

    #region Item Data (Class24)

    /// <summary>
    /// Item information structure (Struct4)
    /// Contains parsed item data from hex string
    /// </summary>
    public struct Struct4
    {
        // Basic item info
        public string string_0;  // Item number/index
        public string string_1;  // Item type
        public string string_2;  // Item ID
        public string string_3;  // Item name
        public string string_4;  // Width
        public string string_5;  // Height
        public string string_6;  // Depth
        public string string_7;  // Durability
        public string string_8;  // Reserved

        // Enhancement info
        public string string_9;  // Item level (+0 to +15)
        public string string_10; // Level display
        public string string_11; // Base level requirement
        public string string_12; // Additional option level
        public string string_13; // Luck option display
        public string string_14; // Skill option display
        public string string_15; // Ancient type indicator
        public string string_16; // Excellent options
        public string string_17; // Harmony option
        public string string_18; // Socket options
        public string string_19; // Excellent prefix

        // Serial and display
        public string string_20; // Serial number
        public string string_21; // Set item options
        public string string_22; // Additional display 1
        public string string_23; // Additional display 2
        public string string_24; // Additional display 3
        public string string_25; // Additional display 4
        public string string_26; // Additional display 5
        public string string_27; // Additional display 6
        public string string_28; // Additional display 7
        public string string_29; // Additional display 8
        public string string_30; // Additional display 9
        public string string_31; // Additional display 10
        public string string_32; // Set item name 1 (Ancient set)
        public string string_33; // Set item name 2 (Ancient set)

        // Flags
        public bool bool_0;  // Has option
        public bool bool_1;  // Has luck
        public bool bool_2;  // Has skill
        public bool bool_3;  // Is ancient
        public bool bool_4;  // Has socket

        // Numeric values
        public int int_0;   // Excellent value count
        public int int_1;   // Slot position
        public int int_2;   // Refinery value
        public int int_3;   // Item database index
        public int int_4;   // Jewel of Harmony value
        public int int_5;   // Set item value
    }

    /// <summary>
    /// Item data manager - replaces Class24
    /// </summary>
    [StandardModule]
    internal sealed class ItemData
    {
        public static Struct4 struct4_0;  // Current item (being edited)
        public static Struct4 struct4_1;  // Temp item (for display/parsing)
        public static Struct4 struct4_2;  // Item database info (loaded from DB)

        // Descriptive aliases
        public static Struct4 CurrentItem { get => struct4_0; set => struct4_0 = value; }
        public static Struct4 TempItem { get => struct4_1; set => struct4_1 = value; }
        public static Struct4 ItemDatabaseInfo { get => struct4_2; set => struct4_2 = value; }
    }

    #endregion
}
