// MuMaker - Map Image Helper
// Refactored from Class17

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using System.IO;

namespace MuMaker.Helpers
{
    /// <summary>
    /// Helper for resolving map image paths
    /// </summary>
    [StandardModule]
    internal sealed class MapImageHelper
    {
        /// <summary>Default map cell width in pixels</summary>
        public static int MapCellWidth = 10;

        /// <summary>Default map cell height in pixels</summary>
        public static int MapCellHeight = 32;

        /// <summary>
        /// Get the image path for a map name
        /// </summary>
        /// <param name="mapName">Name of the map (may contain numbers and spaces)</param>
        /// <returns>Path to the map image file, or default "SinFoto.mmk" if not found</returns>
        public static object GetMapImagePath(object mapName)
        {
            // Remove spaces from map name
            string cleanName = Strings.Replace(Conversions.ToString(mapName), " ", "", 1, -1, CompareMethod.Binary);

            // Remove all numeric digits (0-9) from the name
            int digit = 0;
            do
            {
                cleanName = Strings.Replace(cleanName, Conversions.ToString(digit), "", 1, -1, CompareMethod.Binary);
                checked { ++digit; }
            }
            while (digit <= 9);

            // Build the image path
            object imagePath = (object)("Img/Maps/" + cleanName + ".mmk");

            // Check if the file exists, otherwise return default image
            if (!new FileInfo(Conversions.ToString(imagePath)).Exists)
            {
                imagePath = (object)"Img/Maps/SinFoto.mmk";
            }

            return imagePath;
        }
    }
}
