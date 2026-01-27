// MuMaker - Constants
// Contains all numeric constants used throughout the application

namespace MuMaker.Core
{
    /// <summary>
    /// Application-wide constants for item sizes, buffer lengths, and configuration values
    /// </summary>
    public static class Constants
    {
        #region Warehouse Constants
        /// <summary>
        /// Default warehouse items hex string length (7680 characters = 3840 bytes = 120 items * 32 bytes)
        /// </summary>
        public static int WarehouseItemsLength = 7680;

        /// <summary>
        /// Equipment hex string length (384 characters = 192 bytes = 12 slots * 16 bytes)
        /// </summary>
        public static int EquipmentLength = 384;

        /// <summary>
        /// Personal store hex string length
        /// </summary>
        public static int PersonalStoreLength = 3072;

        /// <summary>
        /// Inventory hex string length (3456 characters)
        /// </summary>
        public static int InventoryLength = 3456;
        #endregion

        #region Timeout Constants
        /// <summary>
        /// Default SQL command timeout in seconds
        /// </summary>
        public static int DefaultCommandTimeout = 360;

        /// <summary>
        /// Extended timeout for long operations
        /// </summary>
        public static int ExtendedTimeout = 120;
        #endregion

        #region Item Constants
        /// <summary>
        /// Number of item slots
        /// </summary>
        public static int ItemSlots = 12;

        /// <summary>
        /// Inventory grid size
        /// </summary>
        public static int InventoryGridSize = 96;

        /// <summary>
        /// Extended inventory size
        /// </summary>
        public static int ExtendedInventorySize = 108;

        /// <summary>
        /// Skill slots count
        /// </summary>
        public static int SkillSlots = 60;
        #endregion

        #region State Flags
        /// <summary>
        /// Flag for warehouse operation state
        /// </summary>
        public static int WarehouseState = 0;

        /// <summary>
        /// Flag for inventory operation state
        /// </summary>
        public static int InventoryState = 0;

        /// <summary>
        /// Flag for equipment operation state
        /// </summary>
        public static int EquipmentState = 0;

        /// <summary>
        /// General operation state flag
        /// </summary>
        public static int OperationState = 0;
        #endregion
    }
}
