// MuMaker - Database Operations
// Contains all database query operations for characters, accounts, warehouses, and guilds

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using MuMaker.Core;
using MuMaker.Models;
using System;
using System.Data;
using System.Data.SqlClient;
using System.Runtime.CompilerServices;

namespace MuMaker.Data
{
    /// <summary>
    /// Database operations for MuMaker
    /// </summary>
    public static class DatabaseOperations
    {
        #region Character Operations
        /// <summary>
        /// Loads character data from the database
        /// </summary>
        public static bool LoadCharacterData()
        {
            ConnectionManager.OpenCharacterConnection();

            try
            {
                string resetColumn = !Operators.ConditionalCompareObjectNotEqual(Configuration.ResetEnabled, 1, false)
                    ? Conversions.ToString(Operators.ConcatenateObject(", ", Configuration.ResetColumnName))
                    : "";

                SqlConnectionPool.CharacterConnection.Open();
                SqlConnectionPool.CharacterCommand.Connection = SqlConnectionPool.CharacterConnection;
                SqlConnectionPool.CharacterCommand.CommandText =
                    "SELECT cLevel, LevelUpPoint, Experience, Strength, Dexterity, Vitality, Energy, Leadership, FruitPoint, PkLevel, PkCount, PkTime, Class, CtlCode " +
                    resetColumn +
                    " FROM Character WHERE AccountID='" + AccountManager.CurrentAccount.DisplayAccountId +
                    "' AND NAME='" + CharacterManager.CurrentCharacter.Name + "'";

                SqlConnectionPool.CharacterReader = SqlConnectionPool.CharacterCommand.ExecuteReader();
                SqlConnectionPool.CharacterReader.Read();

                CharacterManager.CurrentCharacter.Level = SqlConnectionPool.CharacterReader[0].ToString();
                CharacterManager.CurrentCharacter.LevelUpPoints = SqlConnectionPool.CharacterReader[1].ToString();
                CharacterManager.CurrentCharacter.Experience = SqlConnectionPool.CharacterReader[2].ToString();
                CharacterManager.CurrentCharacter.Strength = SqlConnectionPool.CharacterReader[3].ToString();
                CharacterManager.CurrentCharacter.Dexterity = SqlConnectionPool.CharacterReader[4].ToString();
                CharacterManager.CurrentCharacter.Vitality = SqlConnectionPool.CharacterReader[5].ToString();
                CharacterManager.CurrentCharacter.Energy = SqlConnectionPool.CharacterReader[6].ToString();
                CharacterManager.CurrentCharacter.Leadership = SqlConnectionPool.CharacterReader[7].ToString();
                CharacterManager.CurrentCharacter.FruitPoints = SqlConnectionPool.CharacterReader[8].ToString();
                CharacterManager.CurrentCharacter.PkLevel = SqlConnectionPool.CharacterReader[9].ToString();
                CharacterManager.CurrentCharacter.PkCount = SqlConnectionPool.CharacterReader[10].ToString();
                CharacterManager.CurrentCharacter.PkTime = SqlConnectionPool.CharacterReader[11].ToString();
                CharacterManager.CurrentCharacter.CharacterClass = SqlConnectionPool.CharacterReader[12].ToString();
                CharacterManager.CurrentCharacter.ControlCode = SqlConnectionPool.CharacterReader[13].ToString();

                try
                {
                    CharacterManager.CurrentCharacter.ResetCount = NewLateBinding.LateGet(
                        SqlConnectionPool.CharacterReader, null, "Item",
                        new object[] { RuntimeHelpers.GetObjectValue(Configuration.ResetColumnName) },
                        null, null, null).ToString();
                }
                catch (Exception)
                {
                    CharacterManager.CurrentCharacter.ResetCount = "0";
                }

                SqlConnectionPool.CharacterReader.Close();
            }
            catch (Exception ex)
            {
                Interaction.MsgBox(ex.Message, MsgBoxStyle.OkOnly, null);
            }

            ConnectionManager.CloseCharacterConnection();

            // Load quest data
            ConnectionManager.OpenCharacterConnection();
            try
            {
                SqlConnectionPool.CharacterConnection.Open();
                SqlConnectionPool.CharacterCommand.Connection = SqlConnectionPool.CharacterConnection;
                SqlConnectionPool.CharacterCommand.CommandText =
                    "SELECT master.dbo.fn_varbintohexstr(CAST(Quest AS Image)) FROM Character WHERE AccountID='" +
                    AccountManager.CurrentAccount.DisplayAccountId + "' AND NAME='" +
                    CharacterManager.CurrentCharacter.Name + "'";

                SqlConnectionPool.CharacterReader = SqlConnectionPool.CharacterCommand.ExecuteReader();
                SqlConnectionPool.CharacterReader.Read();
                CharacterManager.CurrentCharacter.QuestData = Strings.Mid(
                    SqlConnectionPool.CharacterReader[0].ToString().ToUpper(), 3, 32);
                SqlConnectionPool.CharacterReader.Close();
            }
            catch (Exception ex)
            {
                Interaction.MsgBox(ex.Message, MsgBoxStyle.OkOnly, null);
                return false;
            }

            ConnectionManager.CloseCharacterConnection();
            return true;
        }

        /// <summary>
        /// Loads character by name
        /// </summary>
        public static bool LoadCharacterByName()
        {
            ConnectionManager.OpenCharacterConnection();

            if (Operators.CompareString(CharacterManager.CurrentCharacter.Name, "ALL", false) != 0)
            {
                SqlConnectionPool.CharacterConnection.Open();
                SqlConnectionPool.CharacterCommand.Connection = SqlConnectionPool.CharacterConnection;
                SqlConnectionPool.CharacterCommand.CommandText =
                    "SELECT * FROM Character WHERE Name='" + CharacterManager.CurrentCharacter.Name + "'";

                SqlConnectionPool.CharacterReader = SqlConnectionPool.CharacterCommand.ExecuteReader();
                SqlConnectionPool.CharacterReader.Read();

                CharacterManager.CurrentCharacter.AccountId = SqlConnectionPool.CharacterReader["AccountID"].ToString();
                CharacterManager.CurrentCharacter.Name = SqlConnectionPool.CharacterReader["Name"].ToString();
                CharacterManager.CurrentCharacter.Level = SqlConnectionPool.CharacterReader["cLevel"].ToString();
                CharacterManager.CurrentCharacter.MapNumber = Conversions.ToInteger(SqlConnectionPool.CharacterReader["MapNumber"]);
                CharacterManager.CurrentCharacter.MapPosX = Conversions.ToInteger(SqlConnectionPool.CharacterReader["MapPosX"]);
                CharacterManager.CurrentCharacter.MapPosY = Conversions.ToInteger(SqlConnectionPool.CharacterReader["MapPosY"]);
                CharacterManager.CurrentCharacter.ControlCode = Conversions.ToString(SqlConnectionPool.CharacterReader["CtlCode"]);

                AccountManager.CurrentAccount.DisplayAccountId = CharacterManager.CurrentCharacter.AccountId;
                SqlConnectionPool.CharacterReader.Close();
            }
            else
            {
                CharacterManager.CurrentCharacter.AccountId = "ALL";
                CharacterManager.CurrentCharacter.Name = "ALL";
                CharacterManager.CurrentCharacter.Level = "";
                CharacterManager.CurrentCharacter.MapNumber = 0;
                CharacterManager.CurrentCharacter.MapPosX = 0;
                CharacterManager.CurrentCharacter.MapPosY = 0;
                CharacterManager.CurrentCharacter.ControlCode = "0";
                AccountManager.CurrentAccount.DisplayAccountId = CharacterManager.CurrentCharacter.AccountId;
            }

            ConnectionManager.CloseCharacterConnection();
            return true;
        }
        #endregion

        #region Account Operations
        /// <summary>
        /// Loads account information from the database
        /// </summary>
        public static bool LoadAccountData()
        {
            ConnectionManager.OpenCharacterConnection();

            try
            {
                SqlConnectionPool.CharacterConnection.Open();
                SqlConnectionPool.CharacterCommand.Connection = SqlConnectionPool.CharacterConnection;
                SqlConnectionPool.CharacterCommand.CommandText =
                    "SELECT memb___id, memb__pwd, sno__numb, mail_addr, bloc_code FROM MEMB_INFO WHERE memb___id='" +
                    AccountManager.CurrentAccount.DisplayAccountId + "'";

                SqlConnectionPool.CharacterReader = SqlConnectionPool.CharacterCommand.ExecuteReader();
                SqlConnectionPool.CharacterReader.Read();

                AccountManager.CurrentAccount.AccountId = SqlConnectionPool.CharacterReader[0].ToString();
                AccountManager.CurrentAccount.Password = Operators.CompareString(
                    SqlConnectionPool.CharacterReader[1].ToString(), "System.Byte[]", false) != 0
                    ? SqlConnectionPool.CharacterReader[1].ToString()
                    : "MD5 ENCRYPT";
                AccountManager.CurrentAccount.SerialNumber = SqlConnectionPool.CharacterReader[2].ToString();
                AccountManager.CurrentAccount.Email = SqlConnectionPool.CharacterReader[3].ToString();
                AccountManager.CurrentAccount.BlockCode = SqlConnectionPool.CharacterReader[4].ToString();

                SqlConnectionPool.CharacterReader.Close();
            }
            catch (Exception ex)
            {
                Interaction.MsgBox(ex.Message, MsgBoxStyle.OkOnly, null);
                return false;
            }

            ConnectionManager.CloseCharacterConnection();
            return true;
        }
        #endregion

        #region Warehouse Operations
        /// <summary>
        /// Loads warehouse data for current account
        /// </summary>
        /// <param name="warehouseNumber">0 for main warehouse, 1+ for extended warehouses</param>
        public static bool LoadWarehouseData(int warehouseNumber)
        {
            ConnectionManager.OpenWarehouseConnection();

            try
            {
                SqlConnectionPool.WarehouseConnection.Open();
                SqlConnectionPool.WarehouseCommand.Connection = SqlConnectionPool.WarehouseConnection;

                if (warehouseNumber == 0)
                {
                    SqlConnectionPool.WarehouseCommand.CommandText =
                        "SELECT master.dbo.fn_varbintohexstr(CAST(Items AS Image)), Money FROM warehouse WHERE AccountID = '" +
                        AccountManager.CurrentAccount.DisplayAccountId + "'";
                }
                else
                {
                    SqlConnectionPool.WarehouseCommand.CommandText = Conversions.ToString(
                        Operators.ConcatenateObject(
                            Operators.ConcatenateObject(
                                Operators.ConcatenateObject(
                                    Operators.ConcatenateObject(
                                        Operators.ConcatenateObject(
                                            Operators.ConcatenateObject(
                                                "SELECT master.dbo.fn_varbintohexstr(CAST(Items AS Image)), Money FROM ",
                                                Configuration.ExtendedWarehouseTable),
                                            " WHERE AccountID = '"),
                                        AccountManager.CurrentAccount.DisplayAccountId),
                                    "' AND Number = '"),
                                warehouseNumber),
                            "'"));
                }

                SqlConnectionPool.WarehouseReader = SqlConnectionPool.WarehouseCommand.ExecuteReader();
                SqlConnectionPool.WarehouseReader.Read();

                WarehouseManager.CurrentWarehouse.WarehouseItems = Strings.Mid(
                    SqlConnectionPool.WarehouseReader[0].ToString().ToUpper(), 3,
                    SqlConnectionPool.WarehouseReader[0].ToString().Length);
                WarehouseManager.CurrentWarehouse.WarehouseMoney = SqlConnectionPool.WarehouseReader[1].ToString();

                SqlConnectionPool.WarehouseReader.Close();
            }
            catch (Exception)
            {
                ConnectionManager.CloseWarehouseConnection();
                return false;
            }

            ConnectionManager.CloseWarehouseConnection();

            // Validate warehouse length
            if (WarehouseManager.CurrentWarehouse.WarehouseItems.Length == Constants.WarehouseItemsLength)
            {
                return true;
            }

            Interaction.MsgBox(RuntimeHelpers.GetObjectValue(LocalizedStrings.WarehouseSizeWarning),
                MsgBoxStyle.OkOnly, RuntimeHelpers.GetObjectValue(LocalizedStrings.Warning));

            // Pad warehouse items if too short
            if (WarehouseManager.CurrentWarehouse.WarehouseItems.Length < Constants.WarehouseItemsLength)
            {
                int currentLength = WarehouseManager.CurrentWarehouse.WarehouseItems.Length + 1;
                int targetLength = Constants.WarehouseItemsLength;

                for (int i = currentLength; i <= targetLength; i++)
                {
                    WarehouseManager.CurrentWarehouse.WarehouseItems += "F";
                }
            }

            return false;
        }

        /// <summary>
        /// Loads inventory data for current character
        /// </summary>
        public static bool LoadInventoryData()
        {
            ConnectionManager.OpenInventoryConnection();

            try
            {
                SqlConnectionPool.InventoryConnection.Open();
                SqlConnectionPool.InventoryCommand.Connection = SqlConnectionPool.InventoryConnection;
                SqlConnectionPool.InventoryCommand.CommandText =
                    "SELECT master.dbo.fn_varbintohexstr(CAST(Inventory AS Image)), Money FROM Character WHERE AccountID = '" +
                    AccountManager.CurrentAccount.DisplayAccountId + "' AND Name='" +
                    CharacterManager.CurrentCharacter.Name + "'";

                SqlConnectionPool.InventoryReader = SqlConnectionPool.InventoryCommand.ExecuteReader();
                SqlConnectionPool.InventoryReader.Read();

                WarehouseManager.CurrentWarehouse.InventoryItems = Strings.Mid(
                    SqlConnectionPool.InventoryReader[0].ToString().ToUpper(), 3,
                    SqlConnectionPool.InventoryReader[0].ToString().Length);
                WarehouseManager.CurrentWarehouse.InventoryMoney = SqlConnectionPool.InventoryReader[1].ToString();

                SqlConnectionPool.InventoryReader.Close();
            }
            catch (Exception)
            {
                ConnectionManager.CloseInventoryConnection();
                return false;
            }

            ConnectionManager.CloseInventoryConnection();
            return true;
        }
        #endregion

        #region Guild Operations
        /// <summary>
        /// Loads guild data for current character
        /// </summary>
        public static bool LoadGuildData()
        {
            ConnectionManager.OpenCharacterConnection();

            try
            {
                SqlConnectionPool.CharacterConnection.Open();
                SqlConnectionPool.CharacterCommand.Connection = SqlConnectionPool.CharacterConnection;
                SqlConnectionPool.CharacterCommand.CommandText =
                    "SELECT G_Name, G_Union, G_Rival, G_Notice, G_Score, G_Type, MemberCount, " +
                    "master.dbo.fn_varbintohexstr(CAST(G_Mark AS Image)) AS MARCK FROM Guild WHERE G_Master='" +
                    GuildManager.CurrentGuild.MasterName + "'";

                SqlConnectionPool.CharacterReader = SqlConnectionPool.CharacterCommand.ExecuteReader();

                try
                {
                    SqlConnectionPool.CharacterReader.Read();

                    if (Operators.CompareString(SqlConnectionPool.CharacterReader["G_Name"].ToString(), "", false) != 0)
                    {
                        GuildManager.CurrentGuild.GuildName = SqlConnectionPool.CharacterReader["G_Name"].ToString();
                        GuildManager.CurrentGuild.GuildMark = Strings.Mid(SqlConnectionPool.CharacterReader["MARCK"].ToString(), 3);
                        GuildManager.CurrentGuild.UnionNumber = SqlConnectionPool.CharacterReader["G_Union"].ToString();
                        GuildManager.CurrentGuild.RivalNumber = SqlConnectionPool.CharacterReader["G_Rival"].ToString();
                        GuildManager.CurrentGuild.Notice = SqlConnectionPool.CharacterReader["G_Notice"].ToString();
                        GuildManager.CurrentGuild.Score = SqlConnectionPool.CharacterReader["G_Score"].ToString();
                        GuildManager.CurrentGuild.GuildType = SqlConnectionPool.CharacterReader["G_Type"].ToString();
                        GuildManager.CurrentGuild.MemberCount = SqlConnectionPool.CharacterReader["MemberCount"].ToString();
                    }
                    else
                    {
                        SetNoGuildDefaults();
                    }
                }
                catch (Exception)
                {
                    SetNoGuildDefaults();
                }

                SqlConnectionPool.CharacterReader.Close();
            }
            catch (Exception ex)
            {
                Interaction.MsgBox(ex.Message, MsgBoxStyle.OkOnly, null);
            }

            ConnectionManager.CloseCharacterConnection();
            return true;
        }

        /// <summary>
        /// Sets default values when no guild is found
        /// </summary>
        private static void SetNoGuildDefaults()
        {
            GuildManager.CurrentGuild.GuildName = ">No Guild<";
            GuildManager.CurrentGuild.UnionNumber = "0";
            GuildManager.CurrentGuild.RivalNumber = "0";
            GuildManager.CurrentGuild.GuildMark = "0x0000000000000000000000000000000000000000000000000000000000000000";
            GuildManager.CurrentGuild.Notice = "";
            GuildManager.CurrentGuild.Score = "";
            GuildManager.CurrentGuild.GuildType = "";
            GuildManager.CurrentGuild.MemberCount = "";
        }
        #endregion

        #region Skill Operations
        /// <summary>
        /// Loads skill/magic list for current character
        /// </summary>
        public static bool LoadSkillData()
        {
            ConnectionManager.OpenCharacterConnection();

            try
            {
                SqlConnectionPool.CharacterConnection.Open();
                SqlConnectionPool.CharacterCommand.Connection = SqlConnectionPool.CharacterConnection;
                SqlConnectionPool.CharacterCommand.CommandText =
                    "SELECT master.dbo.fn_varbintohexstr(CAST(MagicList AS Image)) FROM Character WHERE AccountID='" +
                    AccountManager.CurrentAccount.DisplayAccountId + "' AND NAME='" +
                    CharacterManager.CurrentCharacter.Name + "'";

                SqlConnectionPool.CharacterReader = SqlConnectionPool.CharacterCommand.ExecuteReader();
                SqlConnectionPool.CharacterReader.Read();

                CharacterManager.CurrentCharacter.MagicList = Strings.Mid(
                    SqlConnectionPool.CharacterReader[0].ToString().ToUpper(), 3,
                    SqlConnectionPool.CharacterReader[0].ToString().Length);

                SqlConnectionPool.CharacterReader.Close();
            }
            catch (Exception ex)
            {
                Interaction.MsgBox(ex.Message, MsgBoxStyle.OkOnly, null);
                return false;
            }

            ConnectionManager.CloseCharacterConnection();
            return true;
        }
        #endregion

        #region Default Class Stats
        /// <summary>
        /// Loads default stats for a character class
        /// </summary>
        public static bool LoadDefaultClassStats(int characterClass)
        {
            ConnectionManager.OpenCharacterConnection();

            try
            {
                SqlConnectionPool.CharacterConnection.Open();
                SqlConnectionPool.CharacterCommand.Connection = SqlConnectionPool.CharacterConnection;
                SqlConnectionPool.CharacterCommand.CommandText =
                    "SELECT * FROM DefaultClassType WHERE Class='" + characterClass + "'";

                SqlConnectionPool.CharacterReader = SqlConnectionPool.CharacterCommand.ExecuteReader();
                SqlConnectionPool.CharacterReader.Read();

                CharacterManager.DefaultStats.Strength = SqlConnectionPool.CharacterReader[1].ToString();
                CharacterManager.DefaultStats.Dexterity = SqlConnectionPool.CharacterReader[2].ToString();
                CharacterManager.DefaultStats.Vitality = SqlConnectionPool.CharacterReader[3].ToString();
                CharacterManager.DefaultStats.Energy = SqlConnectionPool.CharacterReader[4].ToString();
                CharacterManager.DefaultStats.Leadership = SqlConnectionPool.CharacterReader[16].ToString();
                CharacterManager.DefaultStats.Level = SqlConnectionPool.CharacterReader[17].ToString();
                CharacterManager.DefaultStats.LevelUpPoints = SqlConnectionPool.CharacterReader[18].ToString();

                SqlConnectionPool.CharacterReader.Close();
            }
            catch (Exception ex)
            {
                Interaction.MsgBox(ex.Message, MsgBoxStyle.OkOnly, null);
            }

            ConnectionManager.CloseCharacterConnection();
            return true;
        }
        #endregion

        #region Original Method Aliases (smethod_X backward compatibility)
        /// <summary>smethod_0 - Load character data</summary>
        public static bool smethod_0() => LoadCharacterData();

        /// <summary>smethod_1 - Load account data</summary>
        public static bool smethod_1() => LoadAccountData();
        #endregion

        #region Warehouse Create/Reset
        /// <summary>
        /// Creates warehouse backup (stored procedure)
        /// </summary>
        public static bool CreateWarehouseBackup()
        {
            ConnectionManager.OpenCharacterConnection();
            SqlConnectionPool.CharacterConnection.Open();
            StoredProceduresManager.PrepareWarehouseInsert();

            try
            {
                using (SqlCommand cmd = new SqlCommand("MMK_ItemMakerWareHous", SqlConnectionPool.CharacterConnection))
                {
                    cmd.CommandType = CommandType.StoredProcedure;
                    cmd.Parameters.Add(new SqlParameter("@AccountID", SqlDbType.VarChar, 10)
                    {
                        Direction = ParameterDirection.Input,
                        Value = AccountManager.CurrentAccount.DisplayAccountId
                    });
                    cmd.ExecuteNonQuery();
                }

                SqlConnectionPool.OperationResult = 0;
            }
            catch (Exception)
            {
                Interaction.MsgBox(RuntimeHelpers.GetObjectValue(LocalizedStrings.CreateWarehouseError),
                    MsgBoxStyle.OkOnly, RuntimeHelpers.GetObjectValue(LocalizedStrings.Warning));
                return false;
            }

            ConnectionManager.CloseCharacterConnection();
            return true;
        }

        /// <summary>
        /// Resets warehouse (stored procedure)
        /// </summary>
        public static bool ResetWarehouse()
        {
            ConnectionManager.OpenCharacterConnection();
            SqlConnectionPool.CharacterConnection.Open();
            StoredProceduresManager.PrepareWarehouseReset();

            try
            {
                using (SqlCommand cmd = new SqlCommand("MMK_ItemMakerWareHous", SqlConnectionPool.CharacterConnection))
                {
                    cmd.CommandType = CommandType.StoredProcedure;
                    cmd.Parameters.Add(new SqlParameter("@AccountID", SqlDbType.VarChar, 10)
                    {
                        Direction = ParameterDirection.Input,
                        Value = AccountManager.CurrentAccount.DisplayAccountId
                    });
                    cmd.ExecuteNonQuery();
                }

                SqlConnectionPool.OperationResult = 0;
            }
            catch (Exception)
            {
                Interaction.MsgBox(RuntimeHelpers.GetObjectValue(LocalizedStrings.ResetWarehouseError),
                    MsgBoxStyle.OkOnly, RuntimeHelpers.GetObjectValue(LocalizedStrings.Warning));
            }

            ConnectionManager.CloseCharacterConnection();
            return true;
        }

        /// <summary>
        /// Creates inventory backup (stored procedure)
        /// </summary>
        public static bool CreateInventoryBackup()
        {
            ConnectionManager.OpenCharacterConnection();
            SqlConnectionPool.CharacterConnection.Open();
            StoredProceduresManager.PrepareInventoryInsert();

            try
            {
                using (SqlCommand cmd = new SqlCommand("MMK_ItemMakerInventory", SqlConnectionPool.CharacterConnection))
                {
                    cmd.CommandType = CommandType.StoredProcedure;
                    cmd.Parameters.Add(new SqlParameter("@AccountID", SqlDbType.VarChar, 10)
                    {
                        Direction = ParameterDirection.Input,
                        Value = AccountManager.CurrentAccount.DisplayAccountId
                    });
                    cmd.Parameters.Add(new SqlParameter("@Name", SqlDbType.VarChar, 10)
                    {
                        Direction = ParameterDirection.Input,
                        Value = CharacterManager.CurrentCharacter.Name
                    });
                    cmd.ExecuteNonQuery();
                }

                SqlConnectionPool.OperationResult = 0;
            }
            catch (Exception)
            {
                Interaction.MsgBox(RuntimeHelpers.GetObjectValue(LocalizedStrings.CreateInventoryError),
                    MsgBoxStyle.OkOnly, RuntimeHelpers.GetObjectValue(LocalizedStrings.Warning));
                return false;
            }

            ConnectionManager.CloseCharacterConnection();
            return true;
        }

        /// <summary>
        /// Resets inventory (stored procedure)
        /// </summary>
        public static bool ResetInventory()
        {
            ConnectionManager.OpenCharacterConnection();
            SqlConnectionPool.CharacterConnection.Open();
            StoredProceduresManager.PrepareInventoryReset();

            try
            {
                using (SqlCommand cmd = new SqlCommand("MMK_ItemMakerInventory", SqlConnectionPool.CharacterConnection))
                {
                    cmd.CommandType = CommandType.StoredProcedure;
                    cmd.Parameters.Add(new SqlParameter("@AccountID", SqlDbType.VarChar, 10)
                    {
                        Direction = ParameterDirection.Input,
                        Value = AccountManager.CurrentAccount.DisplayAccountId
                    });
                    cmd.Parameters.Add(new SqlParameter("@Name", SqlDbType.VarChar, 10)
                    {
                        Direction = ParameterDirection.Input,
                        Value = CharacterManager.CurrentCharacter.Name
                    });
                    cmd.ExecuteNonQuery();
                }

                SqlConnectionPool.OperationResult = 0;
            }
            catch (Exception)
            {
                Interaction.MsgBox(RuntimeHelpers.GetObjectValue(LocalizedStrings.ResetInventoryError),
                    MsgBoxStyle.OkOnly, RuntimeHelpers.GetObjectValue(LocalizedStrings.Warning));
            }

            ConnectionManager.CloseCharacterConnection();
            return true;
        }
        #endregion
    }
}
