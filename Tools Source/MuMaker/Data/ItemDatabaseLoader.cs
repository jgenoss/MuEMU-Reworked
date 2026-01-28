// MuMaker - Item Database Loader
// Loads and parses item data from the local Access database

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using MuMaker.Core;
using MuMaker.Models;
using System;
using System.Runtime.CompilerServices;

namespace MuMaker.Data
{
    /// <summary>
    /// Loads item data from the local Access database (MuMaker.mdb)
    /// </summary>
    public static class ItemDatabaseLoader
    {
        #region Reset Item Selection
        /// <summary>
        /// Resets the current item selection
        /// </summary>
        public static bool ResetItemSelection()
        {
            ItemManager.SelectedItem.SlotPosition = 0;
            return true;
        }
        #endregion

        #region Load Item by Name
        /// <summary>
        /// Loads item data by item name
        /// </summary>
        /// <param name="itemName">Name of the item to load</param>
        public static bool LoadItemByName(string itemName)
        {
            ConnectionManager.OpenLocalDbConnection();

            try
            {
                SqlConnectionPool.LocalDbConnection.Open();
                SqlConnectionPool.LocalDbCommand.Connection = SqlConnectionPool.LocalDbConnection;
                SqlConnectionPool.LocalDbCommand.CommandText = $"SELECT * FROM Items WHERE NAME='{itemName}';";
                SqlConnectionPool.LocalDbCommand.ExecuteNonQuery();
                SqlConnectionPool.LocalDbReader = SqlConnectionPool.LocalDbCommand.ExecuteReader();
                SqlConnectionPool.LocalDbReader.Read();

                // Load basic item info
                ItemManager.TemplateItem.ItemNumber = SqlConnectionPool.LocalDbReader["Nº"].ToString();
                ItemManager.TemplateItem.ItemId = SqlConnectionPool.LocalDbReader["ID"].ToString();
                ItemManager.TemplateItem.ItemType = SqlConnectionPool.LocalDbReader["TP"].ToString();
                ItemManager.TemplateItem.Name = SqlConnectionPool.LocalDbReader["NAME"].ToString();
                ItemManager.TemplateItem.Width = SqlConnectionPool.LocalDbReader["X"].ToString();
                ItemManager.TemplateItem.Height = SqlConnectionPool.LocalDbReader["Y"].ToString();
                ItemManager.TemplateItem.Depth = SqlConnectionPool.LocalDbReader["Z"].ToString();
                ItemManager.TemplateItem.Durability = SqlConnectionPool.LocalDbReader["DUR"].ToString();
                ItemManager.TemplateItem.ItemLevel = SqlConnectionPool.LocalDbReader["LVL"].ToString();

                // Load options
                ItemManager.TemplateItem.HasOption = Conversions.ToBoolean(SqlConnectionPool.LocalDbReader["OP"].ToString());
                ItemManager.TemplateItem.HasLuck = Conversions.ToBoolean(SqlConnectionPool.LocalDbReader["LK"].ToString());
                ItemManager.TemplateItem.HasSkill = Conversions.ToBoolean(SqlConnectionPool.LocalDbReader["SK"].ToString());
                ItemManager.TemplateItem.IsAncient = Conversions.ToBoolean(SqlConnectionPool.LocalDbReader["ANC"].ToString());
                ItemManager.TemplateItem.ExcellentValue = Conversions.ToInteger(SqlConnectionPool.LocalDbReader["EXE"].ToString());
                ItemManager.TemplateItem.RefineryValue = Conversions.ToInteger(SqlConnectionPool.LocalDbReader["RF"].ToString());
                ItemManager.TemplateItem.JewelOfHarmonyValue = Conversions.ToInteger(SqlConnectionPool.LocalDbReader["JH"].ToString());
                ItemManager.TemplateItem.HasSocket = Conversions.ToBoolean(SqlConnectionPool.LocalDbReader["Socket"].ToString());
                ItemManager.TemplateItem.SetItemValue = Conversions.ToInteger(SqlConnectionPool.LocalDbReader["SET"].ToString());
                ItemManager.TemplateItem.SetItemName1 = SqlConnectionPool.LocalDbReader["SETItem1"].ToString();
                ItemManager.TemplateItem.SetItemName2 = SqlConnectionPool.LocalDbReader["SETItem2"].ToString();
            }
            catch (Exception ex)
            {
                Interaction.MsgBox(ex.Message, MsgBoxStyle.OkOnly, null);
            }

            SqlConnectionPool.LocalDbReader?.Close();
            ConnectionManager.CloseLocalDbConnection();
            return true;
        }
        #endregion

        #region Parse Item from Hex String
        /// <summary>
        /// Parses item data from a hex string
        /// </summary>
        /// <param name="hexString">32-character hex string representing the item</param>
        public static bool ParseItemFromHex(string hexString)
        {
            // Parse basic info from hex positions
            // Byte 0-1: Item ID
            ItemManager.ViewedItem.ItemId = Conversions.ToString(Conversion.Val("&H" + Strings.Mid(hexString, 1, 2)));

            // Byte 9 (position 19): Item Type nibble
            ItemManager.ViewedItem.ItemType = Conversions.ToString(Conversion.Val("&H" + Strings.Mid(hexString, 19, 1)));

            // Parse level and options
            ItemManager.ViewedItem.ItemLevel = ItemHexParser.ParseItemLevel(hexString);
            ItemManager.ViewedItem.LevelDisplay = Strings.Mid(ItemHexParser.ParseItemLevel(hexString), 2, 2);

            // Serial number (bytes 4-7)
            ItemManager.ViewedItem.SerialNumber = Strings.Mid(hexString, 7, 8);

            // Parse additional level
            ItemManager.ViewedItem.AdditionalLevel = ItemHexParser.ParseAdditionalLevel(hexString);

            // Parse option level
            ItemManager.ViewedItem.OptionLevel = ItemHexParser.ParseOptionLevel(hexString);

            // Parse luck/skill
            ItemManager.ViewedItem.LuckOption = ItemHexParser.ParseLuckOption(hexString);

            // Parse ancient options
            ItemManager.ViewedItem.AncientOption = ItemHexParser.ParseAncientOption(hexString);

            // Parse excellent options
            ItemManager.ViewedItem.ExcellentOptions = ItemHexParser.ParseExcellentOptions(hexString);

            // Socket flag (byte 17-18)
            ItemManager.ViewedItem.Reserved = Strings.Mid(hexString, 18, 1);

            // Clean up level display
            if (Operators.CompareString(ItemManager.ViewedItem.ItemLevel, "+00", false) == 0)
            {
                ItemManager.ViewedItem.ItemLevel = "";
            }

            // Look up item in database
            ConnectionManager.OpenLocalDbConnection();

            int matchCount = 0;
            try
            {
                SqlConnectionPool.LocalDbConnection.Open();
                SqlConnectionPool.LocalDbCommand.Connection = SqlConnectionPool.LocalDbConnection;
                SqlConnectionPool.LocalDbCommand.CommandText = $"SELECT Nº, NAME, LVL, X, Y, Z, EXE, RF, JH, SET, SetItem1, SetItem2 FROM Items WHERE ID={ItemManager.ViewedItem.ItemId} AND TP={ItemManager.ViewedItem.ItemType};";
                SqlConnectionPool.LocalDbCommand.ExecuteNonQuery();
                SqlConnectionPool.LocalDbReader = SqlConnectionPool.LocalDbCommand.ExecuteReader();

                while (SqlConnectionPool.LocalDbReader.Read())
                {
                    matchCount++;
                    ItemManager.ViewedItem.ItemNumber = SqlConnectionPool.LocalDbReader["Nº"].ToString();
                    ItemManager.ViewedItem.Name = SqlConnectionPool.LocalDbReader["NAME"].ToString();
                    ItemManager.ViewedItem.BaseLevelRequirement = SqlConnectionPool.LocalDbReader["LVL"].ToString();
                    ItemManager.ViewedItem.Width = SqlConnectionPool.LocalDbReader["X"].ToString();
                    ItemManager.ViewedItem.Height = SqlConnectionPool.LocalDbReader["Y"].ToString();
                    ItemManager.ViewedItem.Depth = SqlConnectionPool.LocalDbReader["Z"].ToString();
                    ItemManager.ViewedItem.ExcellentValue = Conversions.ToInteger(SqlConnectionPool.LocalDbReader["EXE"].ToString());
                    ItemManager.ViewedItem.RefineryValue = Conversions.ToInteger(SqlConnectionPool.LocalDbReader["RF"].ToString());
                    ItemManager.ViewedItem.JewelOfHarmonyValue = Conversions.ToInteger(SqlConnectionPool.LocalDbReader["JH"].ToString());
                    ItemManager.ViewedItem.SetItemValue = Conversions.ToInteger(SqlConnectionPool.LocalDbReader["SET"].ToString());

                    // Load set item names
                    if (ItemManager.ViewedItem.AncientOption.Length <= 1)
                    {
                        ItemManager.ViewedItem.SetItemName1 = "";
                        ItemManager.ViewedItem.SetItemName2 = "";
                    }
                    else
                    {
                        ItemManager.ViewedItem.SetItemName1 = SqlConnectionPool.LocalDbReader["SetItem1"].ToString() == "NO"
                            ? ""
                            : SqlConnectionPool.LocalDbReader["SetItem1"].ToString() + " ";

                        ItemManager.ViewedItem.SetItemName2 = SqlConnectionPool.LocalDbReader["SetItem2"].ToString() == "NO"
                            ? ""
                            : SqlConnectionPool.LocalDbReader["SetItem2"].ToString() + " ";
                    }
                }
                SqlConnectionPool.LocalDbReader.Close();
            }
            catch (Exception ex)
            {
                Interaction.MsgBox(ex.Message, MsgBoxStyle.OkOnly, null);
            }

            ConnectionManager.CloseLocalDbConnection();

            // If multiple matches found (e.g., same ID/TP but different base levels), refine search
            if (matchCount > 1)
            {
                ConnectionManager.OpenLocalDbConnection();
                try
                {
                    SqlConnectionPool.LocalDbConnection.Open();
                    SqlConnectionPool.LocalDbCommand.Connection = SqlConnectionPool.LocalDbConnection;
                    SqlConnectionPool.LocalDbCommand.CommandText = $"SELECT Nº, NAME, LVL FROM Items WHERE ID={ItemManager.ViewedItem.ItemId} AND TP={ItemManager.ViewedItem.ItemType} AND LVL='{ItemManager.ViewedItem.LevelDisplay}';";
                    SqlConnectionPool.LocalDbCommand.ExecuteNonQuery();
                    SqlConnectionPool.LocalDbReader = SqlConnectionPool.LocalDbCommand.ExecuteReader();
                    SqlConnectionPool.LocalDbReader.Read();

                    ItemManager.ViewedItem.ItemNumber = SqlConnectionPool.LocalDbReader["Nº"].ToString();
                    ItemManager.ViewedItem.Name = SqlConnectionPool.LocalDbReader["NAME"].ToString();
                    ItemManager.ViewedItem.BaseLevelRequirement = SqlConnectionPool.LocalDbReader["LVL"].ToString();
                    SqlConnectionPool.LocalDbReader.Close();
                }
                catch (Exception)
                {
                    ItemManager.ViewedItem.Name = "Unknown Item\n UPDATE Items.mdb";
                }
                ConnectionManager.CloseLocalDbConnection();
            }

            // Clear level display if item has no level variations
            if (Operators.CompareString(ItemManager.ViewedItem.BaseLevelRequirement, "NO", false) != 0)
            {
                ItemManager.ViewedItem.ItemLevel = "";
            }

            // Parse remaining options
            ItemManager.ViewedItem.HarmonyOption = ItemHexParser.ParseHarmonyOption(hexString);
            ItemManager.ViewedItem.SetOptionsDisplay = ItemHexParser.ParseSetOptions(hexString);
            ItemManager.ViewedItem.SocketOptions = ItemHexParser.ParseSocketOptions(hexString);
            ItemManager.ViewedItem.AdditionalOptions = ItemHexParser.ParseAdditionalOptions(hexString);

            return true;
        }
        #endregion

        #region Original Method Aliases (smethod_X backward compatibility)
        /// <summary>smethod_0 - Reset item selection</summary>
        public static bool smethod_0() => ResetItemSelection();

        /// <summary>smethod_1 - Load item by name</summary>
        public static bool smethod_1(string itemName) => LoadItemByName(itemName);

        /// <summary>smethod_2 - Parse item from hex</summary>
        public static bool smethod_2(string hexString) => ParseItemFromHex(hexString);
        #endregion
    }
}
