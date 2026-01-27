// MuMaker - Item Image Paths
// Refactored from Class31

using Microsoft.VisualBasic.CompilerServices;

namespace MuMaker.Helpers
{
    /// <summary>
    /// Image paths for item backgrounds and grid cells
    /// </summary>
    [StandardModule]
    internal sealed class ItemImagePaths
    {
        /// <summary>Grid cell background image</summary>
        public static string GridCellBackground = "Img\\Items\\fondo\\casilla.mmk";

        /// <summary>32x32 pixel item background</summary>
        public static string ItemBackground32x32 = "Img\\Items\\fondo\\32x32.mmk";

        /// <summary>Clean/empty background image</summary>
        public static string CleanBackground = "Img\\Items\\fondo\\clean.mmk";

        /// <summary>Current item image path (dynamic)</summary>
        public static string CurrentItemImagePath;

        /// <summary>Secondary item image path</summary>
        public static string SecondaryItemImagePath;

        /// <summary>Tertiary item image path</summary>
        public static string TertiaryItemImagePath;

        /// <summary>Item display text 1</summary>
        public static string ItemDisplayText1;

        /// <summary>Item display text 2</summary>
        public static string ItemDisplayText2;

        /// <summary>Item display text 3</summary>
        public static string ItemDisplayText3;

        /// <summary>Current X position</summary>
        public static int CurrentX;

        /// <summary>Current Y position</summary>
        public static int CurrentY;
    }
}
