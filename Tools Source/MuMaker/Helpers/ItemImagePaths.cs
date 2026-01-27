// MuMaker - Item Image Paths
// Refactored from Class31

using Microsoft.VisualBasic.CompilerServices;

namespace MuMaker.Helpers
{
    /// <summary>
    /// Image paths for item backgrounds and grid cells
    /// Maintains backward compatibility with original field names
    /// </summary>
    [StandardModule]
    internal sealed class ItemImagePaths
    {
        // Original field names for backward compatibility
        public static string string_6 = "Img\\Items\\fondo\\casilla.mmk";  // Grid cell
        public static string string_7 = "Img\\Items\\fondo\\32x32.mmk";    // 32x32 background
        public static string string_8 = "Img\\Items\\fondo\\clean.mmk";    // Clean background
        public static string string_0;  // Current item image path
        public static string string_1;  // Secondary item image path
        public static string string_2;  // Tertiary item image path
        public static string string_3;  // Item display text 1
        public static string string_4;  // Item display text 2
        public static string string_5;  // Item display text 3
        public static int int_0;        // Current X position
        public static int int_1;        // Current Y position
    }
}
