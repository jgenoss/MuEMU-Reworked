// MuMaker - Skill Image Helper
// Refactored from Class19

using Microsoft.VisualBasic.CompilerServices;
using MuMaker.Models;
using System.IO;

namespace MuMaker.Helpers
{
    /// <summary>
    /// Helper for skill images and item name building
    /// </summary>
    [StandardModule]
    internal sealed class SkillImageHelper
    {
        /// <summary>
        /// Set the current skill image path based on skill number
        /// </summary>
        /// <param name="skillNumber">6-digit skill number (e.g., "000001")</param>
        /// <returns>True on success</returns>
        public static object SetSkillImagePath(object skillNumber)
        {
            string imagePath = Conversions.ToString(
                Operators.ConcatenateObject(
                    Operators.ConcatenateObject(
                        (object)"Img\\Skills\\", skillNumber),
                    (object)".MMK"));

            if (!new FileInfo(imagePath).Exists)
            {
                SkillImagePaths.CurrentSkillImagePath = "Img\\Skills\\000000.MMK";
            }
            else
            {
                SkillImagePaths.CurrentSkillImagePath = imagePath;
            }

            return (object)true;
        }

        /// <summary>
        /// Build a formatted item name with all options
        /// </summary>
        /// <returns>Full item name with excellent, ancient, level, skill, luck, and option info</returns>
        public static object BuildItemDisplayName()
        {
            string excellentPrefix = "";
            string ancientPrefix = "";
            string levelSuffix = "";
            string skillSuffix = "";
            string luckSuffix = "";
            string optionSuffix = "";

            // Add "Excelent" prefix if item has excellent options
            if (ItemData.CurrentItem.ExcellentOptionCount > 0)
            {
                excellentPrefix = "Excelent ";
            }

            // Add ancient set name prefix
            if (ItemData.CurrentItem.IsAncient)
            {
                if (Operators.CompareString(ItemData.ItemDatabaseInfo.AncientSetName2, "NO", false) != 0)
                {
                    ancientPrefix = ItemData.ItemDatabaseInfo.AncientSetName2 + " ";
                }
                if (Operators.CompareString(ItemData.ItemDatabaseInfo.AncientSetName1, "NO", false) != 0)
                {
                    ancientPrefix = ItemData.ItemDatabaseInfo.AncientSetName1 + " ";
                }
            }

            // Add level suffix (+X)
            if (Operators.CompareString(ItemData.CurrentItem.Level, "0", false) != 0 &
                Operators.CompareString(ItemData.CurrentItem.Level, "00", false) != 0)
            {
                if (Operators.CompareString(ItemData.ItemDatabaseInfo.LevelDisplay, "SN", false) != 0)
                {
                    levelSuffix = "";
                }
                if (Operators.CompareString(ItemData.ItemDatabaseInfo.LevelDisplay, "NO", false) == 0)
                {
                    levelSuffix = "+" + ItemData.CurrentItem.Level;
                }
            }

            // Add skill suffix
            if (ItemData.CurrentItem.HasSkill == Conversions.ToBoolean("1"))
            {
                skillSuffix = "+Skill";
            }

            // Add luck suffix
            if (ItemData.CurrentItem.HasLuck == Conversions.ToBoolean("1"))
            {
                luckSuffix = "+Luck";
            }

            // Add option suffix
            if (Operators.CompareString(ItemData.CurrentItem.AdditionalOption, "00", false) != 0)
            {
                optionSuffix = "+Opcion(" + ItemData.CurrentItem.AdditionalOption + ")";
            }

            return (object)(excellentPrefix + ancientPrefix + ItemData.ItemDatabaseInfo.ItemName +
                           levelSuffix + skillSuffix + luckSuffix + optionSuffix);
        }

        /// <summary>
        /// Placeholder method
        /// </summary>
        /// <returns>True</returns>
        public static object Placeholder()
        {
            return (object)true;
        }
    }
}
