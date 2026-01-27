// MuMaker - Item Hex Parser
// Parses and builds item hex strings for MU Online items

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using MuMaker.Models;
using System;
using System.IO;

namespace MuMaker.Data
{
    /// <summary>
    /// Parses and builds item hex strings
    /// </summary>
    public static class ItemHexParser
    {
        #region Image Path Resolution
        /// <summary>
        /// Gets the image path for an item based on its properties
        /// </summary>
        public static string GetItemImagePath(string itemNumber)
        {
            string imagePath = $"Img\\Items\\{itemNumber}.MMK";

            // Check for excellent version
            if (ItemManager.SelectedItem.ExcellentValue > 0)
                imagePath = $"Img\\Items\\EXE\\{itemNumber}.MMK";

            // Check for ancient version
            if (ItemManager.SelectedItem.IsAncient)
                imagePath = $"Img\\Items\\ANC\\{itemNumber}.MMK";

            // Verify file exists
            if (new FileInfo(imagePath).Exists)
            {
                return imagePath;
            }

            // Fall back to standard image
            string standardPath = $"Img\\Items\\{itemNumber}.MMK";
            if (new FileInfo(standardPath).Exists)
            {
                return standardPath;
            }

            // Fall back to placeholder
            return "Img\\Items\\SinFoto.MMK";
        }

        /// <summary>
        /// Gets the image path for a viewed item
        /// </summary>
        public static bool ResolveViewedItemImages()
        {
            string basePath = $"Img\\Items\\{ItemManager.ViewedItem.ItemNumber}.MMK";

            // Check for excellent version
            if (ItemManager.ViewedItem.ExcellentOptions.Length > 1)
                basePath = $"Img\\Items\\EXE\\{ItemManager.ViewedItem.ItemNumber}.MMK";

            // Check for ancient version
            if (ItemManager.ViewedItem.AncientOption.Length > 1)
                basePath = $"Img\\Items\\ANC\\{ItemManager.ViewedItem.ItemNumber}.MMK";

            string resolvedPath;
            if (new FileInfo(basePath).Exists)
            {
                resolvedPath = basePath;
            }
            else
            {
                string standardPath = $"Img\\Items\\{ItemManager.ViewedItem.ItemNumber}.MMK";
                if (new FileInfo(standardPath).Exists)
                {
                    resolvedPath = standardPath;
                }
                else
                {
                    // Use size-based placeholder
                    string width = Conversions.ToString(Conversions.ToDouble(ItemManager.ViewedItem.Width) * 32.0);
                    string height = Conversions.ToString(Conversions.ToDouble(ItemManager.ViewedItem.Height) * 32.0);
                    resolvedPath = $"Img\\Items\\Fondo\\{width}x{height}.MMK";
                }
            }

            // Store paths for different UI elements
            ItemPaths.PrimaryImage = resolvedPath;
            ItemPaths.SecondaryImage = resolvedPath;
            ItemPaths.TertiaryImage = resolvedPath;
            ItemPaths.DisplayImage = resolvedPath;

            return true;
        }
        #endregion

        #region Item Name Building
        /// <summary>
        /// Builds the full item name with all options
        /// </summary>
        public static string BuildFullItemName()
        {
            string prefix = "";
            string setName = "";
            string levelSuffix = "";
            string skillSuffix = "";
            string luckSuffix = "";
            string optionSuffix = "";

            // Excellent prefix
            if (ItemManager.SelectedItem.ExcellentValue > 0)
                prefix = "Excelent ";

            // Ancient/Set prefix
            if (ItemManager.SelectedItem.IsAncient)
            {
                if (Operators.CompareString(ItemManager.SelectedItem.SetItemOption, "1", false) == 0 &&
                    Operators.CompareString(ItemManager.TemplateItem.SetItemName1, "NO", false) != 0)
                {
                    setName = ItemManager.TemplateItem.SetItemName1 + " ";
                }
                if (Operators.CompareString(ItemManager.SelectedItem.ReservedOption, "1", false) == 0 &&
                    Operators.CompareString(ItemManager.TemplateItem.SetItemName2, "NO", false) != 0)
                {
                    setName = ItemManager.TemplateItem.SetItemName2 + " ";
                }
            }

            // Level suffix
            if (Operators.CompareString(ItemManager.SelectedItem.ItemLevel, "0", false) != 0 &&
                Operators.CompareString(ItemManager.SelectedItem.ItemLevel, "00", false) != 0)
            {
                if (Operators.CompareString(ItemManager.TemplateItem.ItemLevel, "NO", false) == 0)
                {
                    levelSuffix = "+" + ItemManager.SelectedItem.ItemLevel;
                }
            }

            // Skill suffix
            if (ItemManager.SelectedItem.HasSkill)
                skillSuffix = "+Skill";

            // Luck suffix
            if (ItemManager.SelectedItem.HasLuck)
                luckSuffix = "+Luck";

            // Option suffix
            if (Operators.CompareString(ItemManager.SelectedItem.AdditionalLevel, "00", false) != 0)
                optionSuffix = $"+Opcion({ItemManager.SelectedItem.AdditionalLevel})";

            return prefix + setName + ItemManager.TemplateItem.Name + levelSuffix + skillSuffix + luckSuffix + optionSuffix;
        }
        #endregion

        #region Hex String Building
        /// <summary>
        /// Builds a complete 32-character hex string for an item
        /// </summary>
        public static string BuildItemHexString()
        {
            // Initialize option values
            string luckValue = "0";
            string skillValue = "0";
            string optionLow = "0";
            string optionHigh = "00";
            string serialNumber = "00000000";
            string socketFlag = "0";
            string excellentFlag = "0";
            string ancientValue = "00";
            string harmonyValue = "00";
            string socket1 = "00";
            string socket2 = "00";
            string socket3 = "00";
            string socket4 = "00";
            string socket5 = "00";

            // Item ID (2 hex digits)
            string itemId = Conversion.Hex(ItemManager.TemplateItem.ItemId);
            if (itemId.Length == 1)
                itemId = "0" + itemId;

            // Luck option (bit 2)
            if (ItemManager.SelectedItem.HasLuck)
                luckValue = "4";

            // Skill option (bit 7)
            if (ItemManager.SelectedItem.HasSkill)
                skillValue = "128";

            // Option level (0-28 mapped to bytes)
            if (string.IsNullOrEmpty(ItemManager.SelectedItem.AdditionalLevel))
                ItemManager.SelectedItem.HasOption = false;

            double optionValue = Conversions.ToDouble(ItemManager.SelectedItem.AdditionalLevel);
            if (optionValue <= 12.0)
            {
                optionLow = Conversions.ToString(optionValue / 4.0);
                optionHigh = "00";
            }
            else if (optionValue >= 16.0)
            {
                optionLow = Conversions.ToString(optionValue / 4.0 - 4.0);
                optionHigh = "64";
            }

            // Combined level/option byte
            decimal combinedValue = Convert.ToDecimal(
                Conversions.ToDouble(ItemManager.SelectedItem.ItemLevel) * 8.0 +
                Conversions.ToDouble(optionLow) +
                Conversions.ToDouble(luckValue) +
                Conversions.ToDouble(skillValue));
            string levelOptionByte = Conversion.Hex(combinedValue.ToString());
            if (levelOptionByte.Length == 1)
                levelOptionByte = "0" + levelOptionByte;

            // Durability
            string durability = Conversion.Hex(ItemManager.SelectedItem.Durability);
            if (durability.Length == 1)
                durability = "0" + durability;

            // Item type nibble (high nibble of byte 9)
            string itemTypeNibble = Conversion.Hex(ItemManager.TemplateItem.ItemType);

            // Excellent options
            if (ItemManager.SelectedItem.ExcellentValue > 0)
            {
                string excellentHex = Conversion.Hex(ItemManager.SelectedItem.ExcellentValue);
                if (excellentHex.Length == 1)
                    excellentHex = "0" + excellentHex;
                excellentFlag = excellentHex;
            }

            // Ancient options
            if (ItemManager.SelectedItem.IsAncient)
            {
                int ancientCode = 0;
                if (Operators.CompareString(ItemManager.SelectedItem.SetItemOption, "1", false) == 0)
                    ancientCode = 5;
                if (Operators.CompareString(ItemManager.SelectedItem.ReservedOption, "1", false) == 0)
                    ancientCode = 10;

                ancientValue = Conversion.Hex(ancientCode);
                if (ancientValue.Length == 1)
                    ancientValue = "0" + ancientValue;
            }

            // Build the 32-character hex string
            // Format: ID(2) + LevelOpt(2) + Dur(2) + Serial(8) + 00 + Type(1)OptionHigh(1) + Excellent(2) + Ancient(2) + Harmony(2) + Sockets(10)
            string hexString = itemId +
                              levelOptionByte +
                              durability +
                              serialNumber +
                              "00" +
                              itemTypeNibble + Strings.Mid(optionHigh, 1, 1) +
                              excellentFlag +
                              ancientValue +
                              harmonyValue +
                              socket1 + socket2 + socket3 + socket4 + socket5;

            return hexString.ToUpper();
        }
        #endregion

        #region Hex String Parsing
        /// <summary>
        /// Parses item level from hex string
        /// </summary>
        public static string ParseItemLevel(string hexString)
        {
            // Level is in byte 1 (characters 3-4), bits 3-6
            double byte1Value = Conversion.Val("&H" + Strings.Mid(hexString, 3, 2));
            int level = (int)(byte1Value / 8.0) % 16;
            return "+" + level.ToString("00");
        }

        /// <summary>
        /// Parses additional level/option from hex string
        /// </summary>
        public static string ParseAdditionalLevel(string hexString)
        {
            // Option is encoded in byte 1 (bits 0-1) and byte 9 (bit 6)
            double byte1Value = Conversion.Val("&H" + Strings.Mid(hexString, 3, 2));
            double byte9Value = Conversion.Val("&H" + Strings.Mid(hexString, 17, 2));

            int optionLow = (int)(byte1Value % 4);
            int optionHigh = ((int)byte9Value & 64) > 0 ? 4 : 0;

            return ((optionLow + optionHigh) * 4).ToString("00");
        }

        /// <summary>
        /// Parses option level
        /// </summary>
        public static string ParseOptionLevel(string hexString)
        {
            double byte1Value = Conversion.Val("&H" + Strings.Mid(hexString, 3, 2));
            int option = (int)(byte1Value % 4);
            return option.ToString();
        }

        /// <summary>
        /// Parses luck option
        /// </summary>
        public static string ParseLuckOption(string hexString)
        {
            double byte1Value = Conversion.Val("&H" + Strings.Mid(hexString, 3, 2));
            return ((int)byte1Value & 4) > 0 ? "1" : "0";
        }

        /// <summary>
        /// Parses skill option
        /// </summary>
        public static string ParseSkillOption(string hexString)
        {
            double byte1Value = Conversion.Val("&H" + Strings.Mid(hexString, 3, 2));
            return ((int)byte1Value & 128) > 0 ? "1" : "0";
        }

        /// <summary>
        /// Parses ancient/set option
        /// </summary>
        public static string ParseAncientOption(string hexString)
        {
            // Ancient option is in byte 11 (characters 21-22)
            string ancientByte = Strings.Mid(hexString, 21, 2);
            int ancientValue = (int)Conversion.Val("&H" + ancientByte);

            if (ancientValue == 0)
                return "";

            // Decode ancient set type
            if (ancientValue >= 5 && ancientValue < 10)
                return "Set1";
            if (ancientValue >= 10)
                return "Set2";

            return ancientValue.ToString();
        }

        /// <summary>
        /// Parses excellent options
        /// </summary>
        public static string ParseExcellentOptions(string hexString)
        {
            // Excellent options are in byte 10 (characters 19-20)
            string excellentByte = Strings.Mid(hexString, 19, 2);
            int excellentValue = (int)Conversion.Val("&H" + excellentByte);

            if (excellentValue == 0)
                return "";

            return excellentValue.ToString();
        }

        /// <summary>
        /// Parses harmony option
        /// </summary>
        public static string ParseHarmonyOption(string hexString)
        {
            // Harmony option is in byte 12 (characters 23-24)
            string harmonyByte = Strings.Mid(hexString, 23, 2);
            int harmonyValue = (int)Conversion.Val("&H" + harmonyByte);

            if (harmonyValue == 0)
                return "";

            return harmonyValue.ToString();
        }

        /// <summary>
        /// Parses set options
        /// </summary>
        public static string ParseSetOptions(string hexString)
        {
            string ancientByte = Strings.Mid(hexString, 21, 2);
            int ancientValue = (int)Conversion.Val("&H" + ancientByte);

            if (ancientValue == 0)
                return "";

            return ancientValue.ToString("00");
        }

        /// <summary>
        /// Parses socket options
        /// </summary>
        public static string ParseSocketOptions(string hexString)
        {
            // Sockets are in bytes 13-17 (characters 25-34)
            if (hexString.Length < 32)
                return "";

            string sockets = Strings.Mid(hexString, 25, 10);
            if (sockets == "0000000000" || sockets == "FFFFFFFFFF")
                return "";

            return sockets;
        }

        /// <summary>
        /// Parses additional options display
        /// </summary>
        public static string ParseAdditionalOptions(string hexString)
        {
            // Parse and format additional display info
            string options = "";

            string luck = ParseLuckOption(hexString);
            string skill = ParseSkillOption(hexString);
            string optionLevel = ParseAdditionalLevel(hexString);

            if (luck == "1")
                options += "+Luck ";
            if (skill == "1")
                options += "+Skill ";
            if (Operators.CompareString(optionLevel, "00", false) != 0)
                options += $"+{optionLevel}% ";

            return options.Trim();
        }
        #endregion
    }

    /// <summary>
    /// Stores resolved item image paths
    /// </summary>
    public static class ItemPaths
    {
        public static string PrimaryImage;
        public static string SecondaryImage;
        public static string TertiaryImage;
        public static string DisplayImage;
        public static string SelectedImage;
    }
}
