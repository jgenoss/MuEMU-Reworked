// MuMaker - Game Data Arrays
// Static arrays for storing game data loaded from the local database

namespace MuMaker.Models
{
    /// <summary>
    /// Static arrays for storing game data (maps, classes, quests, items, etc.)
    /// </summary>
    public static class GameDataArrays
    {
        #region Array Size Constants
        /// <summary>Maximum number of items in arrays</summary>
        public static int MaxArraySize = 512;

        /// <summary>Maximum item types</summary>
        public static int MaxItemTypes = 16;

        /// <summary>Maximum item categories</summary>
        public static int MaxItemCategories = 16;
        #endregion

        #region Map Data
        /// <summary>Map IDs</summary>
        public static string[] MapIds = new string[MaxArraySize + 1];

        /// <summary>Map names</summary>
        public static string[] MapNames = new string[MaxArraySize + 1];

        /// <summary>Total number of maps loaded</summary>
        public static string MapCount;
        #endregion

        #region Control Code Data (GM Levels)
        /// <summary>Control code IDs</summary>
        public static string[] ControlCodeIds = new string[MaxArraySize + 1];

        /// <summary>Control code names (Admin, GM, etc.)</summary>
        public static string[] ControlCodeNames = new string[MaxArraySize + 1];

        /// <summary>Total number of control codes loaded</summary>
        public static string ControlCodeCount;
        #endregion

        #region Character Class Data
        /// <summary>Character class IDs</summary>
        public static string[] CharacterClassIds = new string[MaxArraySize + 1];

        /// <summary>Character class codes</summary>
        public static string[] CharacterClassCodes = new string[MaxArraySize + 1];

        /// <summary>Character class names</summary>
        public static string[] CharacterClassNames = new string[MaxArraySize + 1];

        /// <summary>Total number of character classes loaded</summary>
        public static string CharacterClassCount;
        #endregion

        #region Quest Data
        /// <summary>Quest IDs</summary>
        public static string[] QuestIds = new string[MaxArraySize + 1];

        /// <summary>Quest codes</summary>
        public static string[] QuestCodes = new string[MaxArraySize + 1];

        /// <summary>Quest names</summary>
        public static string[] QuestNames = new string[MaxArraySize + 1];

        /// <summary>Total number of quests loaded</summary>
        public static string QuestCount;
        #endregion

        #region Hero System Data (PK Status)
        /// <summary>Hero system status IDs</summary>
        public static string[] HeroStatusIds = new string[MaxArraySize + 1];

        /// <summary>Hero system status names</summary>
        public static string[] HeroStatusNames = new string[MaxArraySize + 1];

        /// <summary>Total number of hero statuses loaded</summary>
        public static string HeroStatusCount;
        #endregion

        #region Jewel of Harmony Data
        /// <summary>Jewel of Harmony option names</summary>
        public static string[] JewelOfHarmonyNames = new string[MaxArraySize + 1];

        /// <summary>Jewel of Harmony option values (0-F)</summary>
        public static string[] JewelOfHarmonyValues = new string[MaxArraySize + 1];
        #endregion

        #region Socket Data
        /// <summary>Socket slot IDs</summary>
        public static string[] SocketSlotIds = new string[MaxArraySize + 1];

        /// <summary>Socket types</summary>
        public static string[] SocketTypes = new string[MaxArraySize + 1];

        /// <summary>Socket subtypes</summary>
        public static string[] SocketSubtypes = new string[MaxArraySize + 1];

        /// <summary>Socket names</summary>
        public static string[] SocketNames = new string[MaxArraySize + 1];

        /// <summary>Socket item types</summary>
        public static string[] SocketItemTypes = new string[MaxArraySize + 1];

        /// <summary>Socket option values</summary>
        public static string[] SocketOptionValues = new string[MaxArraySize + 1];

        /// <summary>Socket bonus 1</summary>
        public static string[] SocketBonus1 = new string[MaxArraySize + 1];

        /// <summary>Socket bonus 2</summary>
        public static string[] SocketBonus2 = new string[MaxArraySize + 1];

        /// <summary>Socket bonus 3</summary>
        public static string[] SocketBonus3 = new string[MaxArraySize + 1];

        /// <summary>Socket bonus 4</summary>
        public static string[] SocketBonus4 = new string[MaxArraySize + 1];

        /// <summary>Socket bonus 5</summary>
        public static string[] SocketBonus5 = new string[MaxArraySize + 1];

        /// <summary>Total number of sockets loaded</summary>
        public static string SocketCount;
        #endregion

        #region Initialization
        /// <summary>
        /// Clears all arrays
        /// </summary>
        public static void ClearAll()
        {
            MapIds = new string[MaxArraySize + 1];
            MapNames = new string[MaxArraySize + 1];
            ControlCodeIds = new string[MaxArraySize + 1];
            ControlCodeNames = new string[MaxArraySize + 1];
            CharacterClassIds = new string[MaxArraySize + 1];
            CharacterClassCodes = new string[MaxArraySize + 1];
            CharacterClassNames = new string[MaxArraySize + 1];
            QuestIds = new string[MaxArraySize + 1];
            QuestCodes = new string[MaxArraySize + 1];
            QuestNames = new string[MaxArraySize + 1];
            HeroStatusIds = new string[MaxArraySize + 1];
            HeroStatusNames = new string[MaxArraySize + 1];
            JewelOfHarmonyNames = new string[MaxArraySize + 1];
            JewelOfHarmonyValues = new string[MaxArraySize + 1];
            SocketSlotIds = new string[MaxArraySize + 1];
            SocketTypes = new string[MaxArraySize + 1];
            SocketSubtypes = new string[MaxArraySize + 1];
            SocketNames = new string[MaxArraySize + 1];
            SocketItemTypes = new string[MaxArraySize + 1];
            SocketOptionValues = new string[MaxArraySize + 1];
            SocketBonus1 = new string[MaxArraySize + 1];
            SocketBonus2 = new string[MaxArraySize + 1];
            SocketBonus3 = new string[MaxArraySize + 1];
            SocketBonus4 = new string[MaxArraySize + 1];
            SocketBonus5 = new string[MaxArraySize + 1];
        }
        #endregion
    }
}
