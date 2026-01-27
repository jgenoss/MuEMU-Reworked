// MuMaker - Game Data Loader
// Loads game data from the local Access database (MuMaker.mdb)

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using MuMaker.Core;
using MuMaker.Models;
using System;

namespace MuMaker.Data
{
    /// <summary>
    /// Loads game data from the local Access database
    /// </summary>
    public static class GameDataLoader
    {
        #region Character Classes
        /// <summary>
        /// Loads character class data from the database
        /// </summary>
        public static bool LoadCharacterClasses()
        {
            ConnectionManager.OpenLocalDbConnection();

            try
            {
                SqlConnectionPool.LocalDbConnection.Open();
                SqlConnectionPool.LocalDbCommand.Connection = SqlConnectionPool.LocalDbConnection;
                SqlConnectionPool.LocalDbCommand.CommandText = "SELECT * FROM [Player - ClasesPJ] ORDER BY ID;";
                SqlConnectionPool.LocalDbCommand.ExecuteNonQuery();
                SqlConnectionPool.LocalDbReader = SqlConnectionPool.LocalDbCommand.ExecuteReader();

                int index = 0;
                while (SqlConnectionPool.LocalDbReader.Read())
                {
                    GameDataArrays.CharacterClassIds[index] = SqlConnectionPool.LocalDbReader["ID"].ToString();
                    GameDataArrays.CharacterClassCodes[index] = SqlConnectionPool.LocalDbReader["CD"].ToString();
                    GameDataArrays.CharacterClassNames[index] = SqlConnectionPool.LocalDbReader["Nombre"].ToString();
                    index++;
                }
                GameDataArrays.CharacterClassCount = index.ToString();
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

        #region Quests
        /// <summary>
        /// Loads quest data from the database
        /// </summary>
        public static bool LoadQuests()
        {
            ConnectionManager.OpenLocalDbConnection();

            try
            {
                SqlConnectionPool.LocalDbConnection.Open();
                SqlConnectionPool.LocalDbCommand.Connection = SqlConnectionPool.LocalDbConnection;
                SqlConnectionPool.LocalDbCommand.CommandText = "SELECT * FROM [Player - Quests] ORDER BY ID;";
                SqlConnectionPool.LocalDbCommand.ExecuteNonQuery();
                SqlConnectionPool.LocalDbReader = SqlConnectionPool.LocalDbCommand.ExecuteReader();

                int index = 0;
                while (SqlConnectionPool.LocalDbReader.Read())
                {
                    GameDataArrays.QuestIds[index] = SqlConnectionPool.LocalDbReader["ID"].ToString();
                    GameDataArrays.QuestCodes[index] = SqlConnectionPool.LocalDbReader["Code"].ToString();
                    GameDataArrays.QuestNames[index] = SqlConnectionPool.LocalDbReader["Nombre"].ToString();
                    index++;
                }
                GameDataArrays.QuestCount = index.ToString();
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

        #region Control Codes (GM Levels)
        /// <summary>
        /// Loads control code (GM level) data from the database
        /// </summary>
        public static bool LoadControlCodes()
        {
            ConnectionManager.OpenLocalDbConnection();

            try
            {
                SqlConnectionPool.LocalDbConnection.Open();
                SqlConnectionPool.LocalDbCommand.Connection = SqlConnectionPool.LocalDbConnection;
                SqlConnectionPool.LocalDbCommand.CommandText = "SELECT * FROM [Player - CtlCode] ORDER BY ID;";
                SqlConnectionPool.LocalDbCommand.ExecuteNonQuery();
                SqlConnectionPool.LocalDbReader = SqlConnectionPool.LocalDbCommand.ExecuteReader();

                int index = 0;
                while (SqlConnectionPool.LocalDbReader.Read())
                {
                    GameDataArrays.ControlCodeIds[index] = SqlConnectionPool.LocalDbReader["ID"].ToString();
                    GameDataArrays.ControlCodeNames[index] = SqlConnectionPool.LocalDbReader["Nombre"].ToString();
                    index++;
                }
                GameDataArrays.ControlCodeCount = index.ToString();
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

        #region Hero System (PK Status)
        /// <summary>
        /// Loads hero system (PK status) data from the database
        /// </summary>
        public static bool LoadHeroSystem()
        {
            ConnectionManager.OpenLocalDbConnection();

            try
            {
                SqlConnectionPool.LocalDbConnection.Open();
                SqlConnectionPool.LocalDbCommand.Connection = SqlConnectionPool.LocalDbConnection;
                SqlConnectionPool.LocalDbCommand.CommandText = "SELECT * FROM [Player - HeroSystem] ORDER BY ID;";
                SqlConnectionPool.LocalDbCommand.ExecuteNonQuery();
                SqlConnectionPool.LocalDbReader = SqlConnectionPool.LocalDbCommand.ExecuteReader();

                int index = 0;
                while (SqlConnectionPool.LocalDbReader.Read())
                {
                    GameDataArrays.HeroStatusIds[index] = SqlConnectionPool.LocalDbReader["ID"].ToString();
                    GameDataArrays.HeroStatusNames[index] = SqlConnectionPool.LocalDbReader["Nombre"].ToString();
                    index++;
                }
                GameDataArrays.HeroStatusCount = index.ToString();
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

        #region Maps
        /// <summary>
        /// Loads map data from the database
        /// </summary>
        public static bool LoadMaps()
        {
            ConnectionManager.OpenLocalDbConnection();

            try
            {
                SqlConnectionPool.LocalDbConnection.Open();
                SqlConnectionPool.LocalDbCommand.Connection = SqlConnectionPool.LocalDbConnection;
                SqlConnectionPool.LocalDbCommand.CommandText = "SELECT * FROM [Game - Mapas] ORDER BY ID;";
                SqlConnectionPool.LocalDbCommand.ExecuteNonQuery();
                SqlConnectionPool.LocalDbReader = SqlConnectionPool.LocalDbCommand.ExecuteReader();

                int index = 0;
                while (SqlConnectionPool.LocalDbReader.Read())
                {
                    GameDataArrays.MapIds[index] = SqlConnectionPool.LocalDbReader["ID"].ToString();
                    GameDataArrays.MapNames[index] = SqlConnectionPool.LocalDbReader["Nombre"].ToString();
                    index++;
                }
                GameDataArrays.MapCount = index.ToString();
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

        #region Excellent Options
        /// <summary>
        /// Loads excellent item options from the database
        /// </summary>
        public static bool LoadExcellentOptions()
        {
            ConnectionManager.OpenLocalDbConnection();

            try
            {
                SqlConnectionPool.LocalDbConnection.Open();
                SqlConnectionPool.LocalDbCommand.Connection = SqlConnectionPool.LocalDbConnection;
                SqlConnectionPool.LocalDbCommand.CommandText = "SELECT * FROM [Items - Excelent]";
                SqlConnectionPool.LocalDbCommand.ExecuteNonQuery();
                SqlConnectionPool.LocalDbReader = SqlConnectionPool.LocalDbCommand.ExecuteReader();

                int row = 0;
                while (SqlConnectionPool.LocalDbReader.Read())
                {
                    // Each row contains 6 excellent options for different item types
                    // Rows: 0=Weapons, 1=Armor, 2=Shields, 3=Helmets, 4=Boots/Gloves, 7=Wings
                    switch (row)
                    {
                        case 1: // Armor type
                            LocalizedStrings.NoEffect1 = SqlConnectionPool.LocalDbReader["1"].ToString();
                            LocalizedStrings.NoEffect2 = SqlConnectionPool.LocalDbReader["2"].ToString();
                            LocalizedStrings.NoEffect3 = SqlConnectionPool.LocalDbReader["3"].ToString();
                            LocalizedStrings.NoEffect4 = SqlConnectionPool.LocalDbReader["4"].ToString();
                            LocalizedStrings.NoEffect5 = SqlConnectionPool.LocalDbReader["5"].ToString();
                            LocalizedStrings.NoEffect6 = SqlConnectionPool.LocalDbReader["6"].ToString();
                            break;
                        case 2: // Shield type
                            LocalizedStrings.NoEffect7 = SqlConnectionPool.LocalDbReader["1"].ToString();
                            LocalizedStrings.NoEffect8 = SqlConnectionPool.LocalDbReader["2"].ToString();
                            LocalizedStrings.NoEffect9 = SqlConnectionPool.LocalDbReader["3"].ToString();
                            LocalizedStrings.NoEffect10 = SqlConnectionPool.LocalDbReader["4"].ToString();
                            LocalizedStrings.NoEffect11 = SqlConnectionPool.LocalDbReader["5"].ToString();
                            LocalizedStrings.NoEffect12 = SqlConnectionPool.LocalDbReader["6"].ToString();
                            break;
                        case 3: // Helmet type
                            LocalizedStrings.NoEffect13 = SqlConnectionPool.LocalDbReader["1"].ToString();
                            LocalizedStrings.NoEffect14 = SqlConnectionPool.LocalDbReader["2"].ToString();
                            LocalizedStrings.NoEffect15 = SqlConnectionPool.LocalDbReader["3"].ToString();
                            LocalizedStrings.NoEffect16 = SqlConnectionPool.LocalDbReader["4"].ToString();
                            LocalizedStrings.NoEffect17 = SqlConnectionPool.LocalDbReader["5"].ToString();
                            LocalizedStrings.NoEffect18 = SqlConnectionPool.LocalDbReader["6"].ToString();
                            break;
                        case 4: // Boots/Gloves type
                            LocalizedStrings.NoEffect19 = SqlConnectionPool.LocalDbReader["1"].ToString();
                            LocalizedStrings.NoEffect20 = SqlConnectionPool.LocalDbReader["2"].ToString();
                            LocalizedStrings.NoEffect21 = SqlConnectionPool.LocalDbReader["3"].ToString();
                            LocalizedStrings.NoEffect22 = SqlConnectionPool.LocalDbReader["4"].ToString();
                            LocalizedStrings.NoEffect23 = SqlConnectionPool.LocalDbReader["5"].ToString();
                            LocalizedStrings.NoEffect24 = SqlConnectionPool.LocalDbReader["6"].ToString();
                            break;
                    }
                    row++;
                }
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

        #region Refinery Options
        /// <summary>
        /// Loads refinery (Jewel of Harmony) options from the database
        /// </summary>
        public static bool LoadRefineryOptions()
        {
            ConnectionManager.OpenLocalDbConnection();

            try
            {
                SqlConnectionPool.LocalDbConnection.Open();
                SqlConnectionPool.LocalDbCommand.Connection = SqlConnectionPool.LocalDbConnection;
                SqlConnectionPool.LocalDbCommand.CommandText = "SELECT * FROM [Items - Refinery]";
                SqlConnectionPool.LocalDbCommand.ExecuteNonQuery();
                SqlConnectionPool.LocalDbReader = SqlConnectionPool.LocalDbCommand.ExecuteReader();

                int row = 0;
                while (SqlConnectionPool.LocalDbReader.Read())
                {
                    switch (row)
                    {
                        case 0:
                            LocalizedStrings.RefineryOption1_1 = SqlConnectionPool.LocalDbReader["1"].ToString();
                            LocalizedStrings.RefineryOption1_2 = SqlConnectionPool.LocalDbReader["2"].ToString();
                            break;
                        case 1:
                            LocalizedStrings.RefineryOption2_1 = SqlConnectionPool.LocalDbReader["1"].ToString();
                            LocalizedStrings.RefineryOption2_2 = SqlConnectionPool.LocalDbReader["2"].ToString();
                            break;
                        case 2:
                            LocalizedStrings.RefineryOption3_1 = SqlConnectionPool.LocalDbReader["1"].ToString();
                            LocalizedStrings.RefineryOption3_2 = SqlConnectionPool.LocalDbReader["2"].ToString();
                            break;
                        case 3:
                            LocalizedStrings.RefineryOption4_1 = SqlConnectionPool.LocalDbReader["1"].ToString();
                            LocalizedStrings.RefineryOption4_2 = SqlConnectionPool.LocalDbReader["2"].ToString();
                            break;
                        case 4:
                            LocalizedStrings.RefineryOption5_1 = SqlConnectionPool.LocalDbReader["1"].ToString();
                            LocalizedStrings.RefineryOption5_2 = SqlConnectionPool.LocalDbReader["2"].ToString();
                            break;
                        case 5:
                            LocalizedStrings.RefineryOption6_1 = SqlConnectionPool.LocalDbReader["1"].ToString();
                            LocalizedStrings.RefineryOption6_2 = SqlConnectionPool.LocalDbReader["2"].ToString();
                            break;
                        case 6:
                            LocalizedStrings.RefineryOption7_1 = SqlConnectionPool.LocalDbReader["1"].ToString();
                            LocalizedStrings.RefineryOption7_2 = SqlConnectionPool.LocalDbReader["2"].ToString();
                            break;
                    }
                    row++;
                }
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

        #region Jewel of Harmony
        /// <summary>
        /// Loads Jewel of Harmony options for a specific item type
        /// </summary>
        /// <param name="itemType">Item type code</param>
        public static bool LoadJewelOfHarmonyOptions(string itemType)
        {
            ConnectionManager.OpenLocalDbConnection();

            try
            {
                SqlConnectionPool.LocalDbConnection.Open();
                SqlConnectionPool.LocalDbCommand.Connection = SqlConnectionPool.LocalDbConnection;
                SqlConnectionPool.LocalDbCommand.CommandText = $"SELECT NM FROM [Items - JewelOfHarmony] WHERE TP='{itemType}' ORDER BY ID;";
                SqlConnectionPool.LocalDbCommand.ExecuteNonQuery();
                SqlConnectionPool.LocalDbReader = SqlConnectionPool.LocalDbCommand.ExecuteReader();

                int index = 0;
                while (SqlConnectionPool.LocalDbReader.Read())
                {
                    GameDataArrays.JewelOfHarmonyNames[index] = SqlConnectionPool.LocalDbReader["NM"].ToString();
                    index++;
                }
            }
            catch (Exception ex)
            {
                Interaction.MsgBox(ex.Message, MsgBoxStyle.OkOnly, null);
            }

            SqlConnectionPool.LocalDbReader?.Close();
            ConnectionManager.CloseLocalDbConnection();
            return true;
        }

        /// <summary>
        /// Loads Jewel of Harmony option values for a specific type and level
        /// </summary>
        public static bool LoadJewelOfHarmonyValues(string itemType, int optionIndex)
        {
            string hexIndex = Conversion.Hex(optionIndex + 1);

            ConnectionManager.OpenLocalDbConnection();

            try
            {
                SqlConnectionPool.LocalDbConnection.Open();
                SqlConnectionPool.LocalDbCommand.Connection = SqlConnectionPool.LocalDbConnection;
                SqlConnectionPool.LocalDbCommand.CommandText = $"SELECT * FROM [Items - JewelOfHarmony] WHERE ID='{hexIndex}' AND TP='{itemType}' ORDER BY ID;";
                SqlConnectionPool.LocalDbCommand.ExecuteNonQuery();
                SqlConnectionPool.LocalDbReader = SqlConnectionPool.LocalDbCommand.ExecuteReader();

                SqlConnectionPool.LocalDbReader.Read();

                // Load values 0-F (hex)
                string[] hexValues = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };
                for (int i = 0; i < 16; i++)
                {
                    GameDataArrays.JewelOfHarmonyValues[i] = SqlConnectionPool.LocalDbReader[hexValues[i]].ToString();
                }
            }
            catch (Exception)
            {
                // Ignore errors for missing JoH data
            }

            SqlConnectionPool.LocalDbReader?.Close();
            ConnectionManager.CloseLocalDbConnection();
            return true;
        }
        #endregion

        #region Socket Options
        /// <summary>
        /// Loads socket option data from the database
        /// </summary>
        public static bool LoadSocketOptions()
        {
            int index = 0;
            ConnectionManager.OpenLocalDbConnection();

            try
            {
                // First load universal sockets (TP=255)
                SqlConnectionPool.LocalDbConnection.Open();
                SqlConnectionPool.LocalDbCommand.Connection = SqlConnectionPool.LocalDbConnection;
                SqlConnectionPool.LocalDbCommand.CommandText = "SELECT * FROM [Items - Socket] WHERE TP=255 ORDER BY Nº;";
                SqlConnectionPool.LocalDbCommand.ExecuteNonQuery();
                SqlConnectionPool.LocalDbReader = SqlConnectionPool.LocalDbCommand.ExecuteReader();

                while (SqlConnectionPool.LocalDbReader.Read())
                {
                    GameDataArrays.SocketSlotIds[index] = (Conversions.ToDouble(SqlConnectionPool.LocalDbReader["ID"].ToString()) + 1).ToString();
                    GameDataArrays.SocketTypes[index] = SqlConnectionPool.LocalDbReader["TP"].ToString();
                    GameDataArrays.SocketSubtypes[index] = SqlConnectionPool.LocalDbReader["ST"].ToString();
                    GameDataArrays.SocketNames[index] = SqlConnectionPool.LocalDbReader["NM"].ToString();
                    GameDataArrays.SocketItemTypes[index] = SqlConnectionPool.LocalDbReader["IT"].ToString();
                    GameDataArrays.SocketOptionValues[index] = SqlConnectionPool.LocalDbReader["S1"].ToString();
                    index++;
                }
                GameDataArrays.SocketCount = index.ToString();
            }
            catch (Exception ex)
            {
                Interaction.MsgBox(ex.Message, MsgBoxStyle.OkOnly, null);
            }

            ConnectionManager.CloseLocalDbConnection();

            // Then load specific sockets with their 5 slot variations
            try
            {
                SqlConnectionPool.LocalDbConnection.Open();
                SqlConnectionPool.LocalDbCommand.Connection = SqlConnectionPool.LocalDbConnection;
                SqlConnectionPool.LocalDbCommand.CommandText = "SELECT * FROM [Items - Socket] WHERE (TP<>0 AND TP<>-1 AND TP<>255) ORDER BY Nº;";
                SqlConnectionPool.LocalDbCommand.ExecuteNonQuery();
                SqlConnectionPool.LocalDbReader = SqlConnectionPool.LocalDbCommand.ExecuteReader();

                int socketIndex = Conversions.ToInteger(GameDataArrays.SocketCount);
                while (SqlConnectionPool.LocalDbReader.Read())
                {
                    double baseId = Conversions.ToDouble(SqlConnectionPool.LocalDbReader["ID"].ToString());
                    string tp = SqlConnectionPool.LocalDbReader["TP"].ToString();
                    string st = SqlConnectionPool.LocalDbReader["ST"].ToString();
                    string nm = SqlConnectionPool.LocalDbReader["NM"].ToString();
                    string it = SqlConnectionPool.LocalDbReader["IT"].ToString();

                    // Create 5 entries for each socket (S1-S5)
                    int[] offsets = { 0, 50, 100, 150, 200 };
                    string[] slotColumns = { "S1", "S2", "S3", "S4", "S5" };

                    for (int slot = 0; slot < 5; slot++)
                    {
                        GameDataArrays.SocketSlotIds[socketIndex] = (baseId + 1 + offsets[slot]).ToString();
                        GameDataArrays.SocketTypes[socketIndex] = tp;
                        GameDataArrays.SocketSubtypes[socketIndex] = st;
                        GameDataArrays.SocketNames[socketIndex] = nm;
                        GameDataArrays.SocketItemTypes[socketIndex] = it;
                        GameDataArrays.SocketOptionValues[socketIndex] = SqlConnectionPool.LocalDbReader[slotColumns[slot]].ToString();
                        socketIndex++;
                    }
                }
                GameDataArrays.SocketCount = socketIndex.ToString();
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

        #region Load All
        /// <summary>
        /// Loads all game data from the database
        /// </summary>
        public static bool LoadAllGameData()
        {
            LoadCharacterClasses();
            LoadQuests();
            LoadControlCodes();
            LoadHeroSystem();
            LoadMaps();
            LoadExcellentOptions();
            LoadRefineryOptions();
            LoadSocketOptions();
            return true;
        }
        #endregion
    }
}
