// MuMaker - Stored Procedures Manager
// Manages creation and execution of SQL Server stored procedures

using Microsoft.VisualBasic.CompilerServices;
using MuMaker.Core;
using MuMaker.Models;
using System;
using System.Data;
using System.Data.SqlClient;

namespace MuMaker.Data
{
    /// <summary>
    /// Manages stored procedures for MuMaker operations
    /// </summary>
    public static class StoredProceduresManager
    {
        #region Initialize Stored Procedures
        /// <summary>
        /// Creates all required stored procedures if they don't exist
        /// </summary>
        public static bool InitializeStoredProcedures()
        {
            try
            {
                CreateWarehouseAndInventoryProcedures();
                CreateSkillProcedure();
                CreateQuestProcedure();
                CreateGuildProcedure();
                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }

        /// <summary>
        /// Creates warehouse and inventory stored procedures
        /// </summary>
        private static void CreateWarehouseAndInventoryProcedures()
        {
            string connectionString = BuildConnectionString();

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                // Check and create MMK_ItemMakerWareHous
                string checkProcSql = $"if object_id('{Configuration.MuOnlineDatabase}..MMK_ItemMakerWareHous') is not null " +
                    $"begin if objectproperty(object_id('{Configuration.MuOnlineDatabase}..MMK_ItemMakerWareHous'), 'IsProcedure')= 1 " +
                    $"select object_id('{Configuration.MuOnlineDatabase}..MMK_ItemMakerWareHous') else return end else return";

                using (SqlCommand cmd = new SqlCommand(checkProcSql, connection))
                {
                    cmd.CommandType = CommandType.Text;
                    connection.Open();

                    using (SqlDataReader reader = cmd.ExecuteReader())
                    {
                        if (!reader.Read())
                        {
                            reader.Close();
                            cmd.CommandText = @"CREATE PROCEDURE MMK_ItemMakerWareHous (@AccountID VARCHAR(10))
AS
UPDATE warehouse
SET Items=0x00000000000000000000
WHERE AccountID=@AccountID";
                            cmd.ExecuteNonQuery();
                        }
                    }
                }

                connection.Close();
                connection.Open();

                // Check and create MMK_ItemMakerInventory
                checkProcSql = $"if object_id('{Configuration.MuOnlineDatabase}..MMK_ItemMakerInventory') is not null " +
                    $"begin if objectproperty(object_id('{Configuration.MuOnlineDatabase}..MMK_ItemMakerInventory'), 'IsProcedure')= 1 " +
                    $"select object_id('{Configuration.MuOnlineDatabase}..MMK_ItemMakerInventory') else return end else return";

                using (SqlCommand cmd = new SqlCommand(checkProcSql, connection))
                {
                    cmd.CommandType = CommandType.Text;

                    using (SqlDataReader reader = cmd.ExecuteReader())
                    {
                        if (!reader.Read())
                        {
                            reader.Close();
                            cmd.CommandText = @"CREATE PROCEDURE MMK_ItemMakerInventory (@AccountID VARCHAR(10), @Name VARCHAR(10))
AS
UPDATE Character
SET Inventory=0x00000000000000000000
WHERE AccountID=@AccountID AND Name=@Name";
                            cmd.ExecuteNonQuery();
                        }
                    }
                }
            }
        }

        /// <summary>
        /// Creates skill stored procedure
        /// </summary>
        private static void CreateSkillProcedure()
        {
            string connectionString = BuildConnectionString();

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                string checkProcSql = $"if object_id('{Configuration.MuOnlineDatabase}..MMK_SkillMaker') is not null " +
                    $"begin if objectproperty(object_id('{Configuration.MuOnlineDatabase}..MMK_SkillMaker'), 'IsProcedure')= 1 " +
                    $"select object_id('{Configuration.MuOnlineDatabase}..MMK_SkillMaker') else return end else return";

                using (SqlCommand cmd = new SqlCommand(checkProcSql, connection))
                {
                    cmd.CommandType = CommandType.Text;
                    connection.Open();

                    using (SqlDataReader reader = cmd.ExecuteReader())
                    {
                        if (!reader.Read())
                        {
                            reader.Close();
                            cmd.CommandText = @"CREATE PROCEDURE MMK_SkillMaker (@AccountID VARCHAR(10), @Name VARCHAR(10))
AS
UPDATE Character
SET MagicList=0xFF0000
WHERE AccountID=@AccountID AND Name=@Name";
                            cmd.ExecuteNonQuery();
                        }
                    }
                }
            }
        }

        /// <summary>
        /// Creates quest stored procedure
        /// </summary>
        private static void CreateQuestProcedure()
        {
            string connectionString = BuildConnectionString();

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                string checkProcSql = $"if object_id('{Configuration.MuOnlineDatabase}..MMK_QuestMaker') is not null " +
                    $"begin if objectproperty(object_id('{Configuration.MuOnlineDatabase}..MMK_QuestMaker'), 'IsProcedure')= 1 " +
                    $"select object_id('{Configuration.MuOnlineDatabase}..MMK_QuestMaker') else return end else return";

                using (SqlCommand cmd = new SqlCommand(checkProcSql, connection))
                {
                    cmd.CommandType = CommandType.Text;
                    connection.Open();

                    using (SqlDataReader reader = cmd.ExecuteReader())
                    {
                        if (!reader.Read())
                        {
                            reader.Close();
                            cmd.CommandText = @"CREATE PROCEDURE MMK_QuestMaker (@AccountID VARCHAR(10), @Name VARCHAR(10))
AS
UPDATE Character
SET Quest=0xFFFFFF
WHERE AccountID=@AccountID AND Name=@Name";
                            cmd.ExecuteNonQuery();
                        }
                    }
                }
            }
        }

        /// <summary>
        /// Creates guild stored procedure
        /// </summary>
        private static void CreateGuildProcedure()
        {
            string connectionString = BuildConnectionString();

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                string checkProcSql = $"if object_id('{Configuration.MuOnlineDatabase}..MMK_GuildMaker') is not null " +
                    $"begin if objectproperty(object_id('{Configuration.MuOnlineDatabase}..MMK_GuildMaker'), 'IsProcedure')= 1 " +
                    $"select object_id('{Configuration.MuOnlineDatabase}..MMK_GuildMaker') else return end else return";

                using (SqlCommand cmd = new SqlCommand(checkProcSql, connection))
                {
                    cmd.CommandType = CommandType.Text;
                    connection.Open();

                    using (SqlDataReader reader = cmd.ExecuteReader())
                    {
                        if (!reader.Read())
                        {
                            reader.Close();
                            cmd.CommandText = @"CREATE PROCEDURE MMK_GuildMaker (@Name VARCHAR(8))
AS
UPDATE Guild
SET G_Mark=0x0000000000000000000000000000000000000000000000000000000000000000
WHERE G_Name=@Name";
                            cmd.ExecuteNonQuery();
                        }
                    }
                }
            }
        }
        #endregion

        #region Prepare Stored Procedures for Operations
        /// <summary>
        /// Prepares warehouse insert stored procedure with dynamic item size
        /// </summary>
        public static void PrepareWarehouseInsert()
        {
            string connectionString = BuildConnectionString();

            // Build hex string filled with F's
            string emptyItems = "0x";
            for (int i = 1; i <= Constants.WarehouseItemsLength; i++)
            {
                emptyItems += "F";
            }

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                string checkProcSql = $"if object_id('{Configuration.MuOnlineDatabase}..MMK_ItemMakerWareHous') is not null " +
                    $"begin if objectproperty(object_id('{Configuration.MuOnlineDatabase}..MMK_ItemMakerWareHous'), 'IsProcedure')= 1 " +
                    $"select object_id('{Configuration.MuOnlineDatabase}..MMK_ItemMakerWareHous') else return end else return";

                using (SqlCommand cmd = new SqlCommand(checkProcSql, connection))
                {
                    cmd.CommandType = CommandType.Text;
                    connection.Open();

                    using (SqlDataReader reader = cmd.ExecuteReader())
                    {
                        if (reader.Read())
                        {
                            reader.Close();

                            string alterSql;
                            if (WarehouseManager.CurrentWarehouse.ExtendedWarehouseNumber != 0)
                            {
                                alterSql = $@"ALTER PROCEDURE MMK_ItemMakerWareHous (@AccountID VARCHAR(10))
AS
INSERT INTO {Configuration.ExtendedWarehouseTable} (AccountID, Number, Items, Money, pw)
VALUES (@AccountID, {WarehouseManager.CurrentWarehouse.ExtendedWarehouseNumber}, {emptyItems}, 0, 0)";
                            }
                            else
                            {
                                alterSql = $@"ALTER PROCEDURE MMK_ItemMakerWareHous (@AccountID VARCHAR(10))
AS
INSERT INTO warehouse (AccountID, Items, Money)
VALUES (@AccountID, {emptyItems}, 0)";
                            }

                            cmd.CommandText = alterSql;
                            cmd.ExecuteNonQuery();
                        }
                    }
                }
            }
        }

        /// <summary>
        /// Prepares warehouse reset stored procedure
        /// </summary>
        public static void PrepareWarehouseReset()
        {
            string connectionString = BuildConnectionString();

            // Build hex string filled with F's
            string emptyItems = "0x";
            for (int i = 1; i <= Constants.WarehouseItemsLength; i++)
            {
                emptyItems += "F";
            }

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                string checkProcSql = $"if object_id('{Configuration.MuOnlineDatabase}..MMK_ItemMakerWareHous') is not null " +
                    $"begin if objectproperty(object_id('{Configuration.MuOnlineDatabase}..MMK_ItemMakerWareHous'), 'IsProcedure')= 1 " +
                    $"select object_id('{Configuration.MuOnlineDatabase}..MMK_ItemMakerWareHous') else return end else return";

                using (SqlCommand cmd = new SqlCommand(checkProcSql, connection))
                {
                    cmd.CommandType = CommandType.Text;
                    connection.Open();

                    using (SqlDataReader reader = cmd.ExecuteReader())
                    {
                        if (reader.Read())
                        {
                            reader.Close();

                            string alterSql;
                            if (WarehouseManager.CurrentWarehouse.ExtendedWarehouseNumber != 0)
                            {
                                alterSql = $@"ALTER PROCEDURE MMK_ItemMakerWareHous (@AccountID VARCHAR(10))
AS
UPDATE {Configuration.ExtendedWarehouseTable}
SET Items={emptyItems}, Money=0
WHERE AccountID=@AccountID AND Number={WarehouseManager.CurrentWarehouse.ExtendedWarehouseNumber}";
                            }
                            else
                            {
                                alterSql = $@"ALTER PROCEDURE MMK_ItemMakerWareHous (@AccountID VARCHAR(10))
AS
UPDATE warehouse
SET Items={emptyItems}, Money=0
WHERE AccountID=@AccountID";
                            }

                            cmd.CommandText = alterSql;
                            cmd.ExecuteNonQuery();
                        }
                    }
                }
            }
        }

        /// <summary>
        /// Prepares inventory insert stored procedure
        /// </summary>
        public static void PrepareInventoryInsert()
        {
            string connectionString = BuildConnectionString();

            // Build hex string filled with F's for inventory
            string emptyItems = "0x";
            for (int i = 1; i <= Constants.InventoryLength; i++)
            {
                emptyItems += "F";
            }

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                string checkProcSql = $"if object_id('{Configuration.MuOnlineDatabase}..MMK_ItemMakerInventory') is not null " +
                    $"begin if objectproperty(object_id('{Configuration.MuOnlineDatabase}..MMK_ItemMakerInventory'), 'IsProcedure')= 1 " +
                    $"select object_id('{Configuration.MuOnlineDatabase}..MMK_ItemMakerInventory') else return end else return";

                using (SqlCommand cmd = new SqlCommand(checkProcSql, connection))
                {
                    cmd.CommandType = CommandType.Text;
                    connection.Open();

                    using (SqlDataReader reader = cmd.ExecuteReader())
                    {
                        if (reader.Read())
                        {
                            reader.Close();
                            cmd.CommandText = $@"ALTER PROCEDURE MMK_ItemMakerInventory (@AccountID VARCHAR(10), @Name VARCHAR(10))
AS
UPDATE Character
SET Inventory={emptyItems}, Money=0
WHERE AccountID=@AccountID AND Name=@Name";
                            cmd.ExecuteNonQuery();
                        }
                    }
                }
            }
        }

        /// <summary>
        /// Prepares inventory reset stored procedure
        /// </summary>
        public static void PrepareInventoryReset()
        {
            // Same as PrepareInventoryInsert since it updates the same fields
            PrepareInventoryInsert();
        }
        #endregion

        #region Helper Methods
        /// <summary>
        /// Builds connection string based on configuration
        /// </summary>
        private static string BuildConnectionString()
        {
            if (Operators.ConditionalCompareObjectEqual(Configuration.ConnectionType, "Local", false))
            {
                return $"Data Source=localhost; uid={Configuration.SqlUsername};pwd={Configuration.SqlPassword};database={Configuration.MuOnlineDatabase};";
            }
            else
            {
                return $"Network Library=dbmssocn; Data Source={Configuration.ServerIpAddress},{Configuration.ServerPort}; uid={Configuration.SqlUsername};pwd={Configuration.SqlPassword};database={Configuration.MuOnlineDatabase};";
            }
        }
        #endregion

        #region Original Method Aliases (smethod_X backward compatibility)
        /// <summary>smethod_0 - Create warehouse procedure</summary>
        public static void smethod_0() => CreateWarehouseAndInventoryProcedures();

        /// <summary>smethod_1 - Create skill procedure</summary>
        public static void smethod_1() => CreateSkillProcedure();

        /// <summary>smethod_2 - Create quest procedure</summary>
        public static void smethod_2() => CreateQuestProcedure();

        /// <summary>smethod_3 - Create guild procedure</summary>
        public static void smethod_3() => CreateGuildProcedure();

        /// <summary>smethod_9 - Execute finder search (warehouse)</summary>
        public static void smethod_9(object searchQuery)
        {
            // Execute finder search query on warehouse
            ConnectionManager.OpenWarehouseConnection();
            try
            {
                SqlConnectionPool.WarehouseConnection.Open();
                SqlConnectionPool.WarehouseCommand.Connection = SqlConnectionPool.WarehouseConnection;
                SqlConnectionPool.WarehouseCommand.CommandText = Conversions.ToString(searchQuery);
                SqlConnectionPool.WarehouseCommand.ExecuteNonQuery();
            }
            catch (Exception) { }
            ConnectionManager.CloseWarehouseConnection();
        }

        /// <summary>smethod_10 - Execute finder search (inventory)</summary>
        public static void smethod_10(object searchQuery)
        {
            // Execute finder search query on inventory
            ConnectionManager.OpenInventoryConnection();
            try
            {
                SqlConnectionPool.InventoryConnection.Open();
                SqlConnectionPool.InventoryCommand.Connection = SqlConnectionPool.InventoryConnection;
                SqlConnectionPool.InventoryCommand.CommandText = Conversions.ToString(searchQuery);
                SqlConnectionPool.InventoryCommand.ExecuteNonQuery();
            }
            catch (Exception) { }
            ConnectionManager.CloseInventoryConnection();
        }

        /// <summary>smethod_11 - Update quest data</summary>
        public static void smethod_11(object questHex)
        {
            ConnectionManager.OpenCharacterConnection();
            try
            {
                SqlConnectionPool.CharacterConnection.Open();
                SqlConnectionPool.CharacterCommand.Connection = SqlConnectionPool.CharacterConnection;
                SqlConnectionPool.CharacterCommand.CommandText =
                    $"UPDATE Character SET Quest={questHex} WHERE AccountID='{AccountManager.CurrentAccount.DisplayAccountId}' AND Name='{CharacterManager.CurrentCharacter.Name}'";
                SqlConnectionPool.CharacterCommand.ExecuteNonQuery();
            }
            catch (Exception) { }
            ConnectionManager.CloseCharacterConnection();
        }

        /// <summary>smethod_14 - Initialize all stored procedures</summary>
        public static void smethod_14() => InitializeStoredProcedures();
        #endregion
    }
}
