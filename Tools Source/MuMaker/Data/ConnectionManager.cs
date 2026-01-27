// MuMaker - Connection Manager
// Handles SQL Server connection creation and management

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using MuMaker.Core;
using System.Data;
using System.Data.OleDb;
using System.Data.SqlClient;

namespace MuMaker.Data
{
    /// <summary>
    /// Manages database connections for all operations
    /// </summary>
    public static class ConnectionManager
    {
        #region Connection String Building
        /// <summary>
        /// Builds a SQL Server connection string based on configuration
        /// </summary>
        private static string BuildConnectionString(string database)
        {
            if (Operators.ConditionalCompareObjectEqual(Configuration.ConnectionType, "Local", false))
            {
                return $"Data Source=localhost; uid={Configuration.SqlUsername};pwd={Configuration.SqlPassword};database={database};";
            }
            else
            {
                return $"Network Library=dbmssocn; Data Source={Configuration.ServerIpAddress},{Configuration.ServerPort}; uid={Configuration.SqlUsername};pwd={Configuration.SqlPassword};database={database};";
            }
        }
        #endregion

        #region Character Connection
        /// <summary>
        /// Opens a connection for character database operations
        /// </summary>
        public static bool OpenCharacterConnection()
        {
            string connectionString = BuildConnectionString(Conversions.ToString(Configuration.MuOnlineDatabase));

            SqlConnectionPool.CharacterConnection = new SqlConnection(connectionString);
            SqlConnectionPool.CharacterCommand = new SqlCommand();
            SqlConnectionPool.CharacterCommand.CommandTimeout = Configuration.CommandTimeout;

            return true;
        }

        /// <summary>
        /// Closes the character database connection
        /// </summary>
        public static bool CloseCharacterConnection()
        {
            if (SqlConnectionPool.CharacterConnection?.State == ConnectionState.Open)
            {
                SqlConnectionPool.CharacterConnection.Close();
            }
            return true;
        }
        #endregion

        #region Account Connection
        /// <summary>
        /// Opens a connection for account database operations
        /// </summary>
        public static bool OpenAccountConnection()
        {
            string connectionString = BuildConnectionString(Conversions.ToString(Configuration.MuOnlineDatabase));

            SqlConnectionPool.AccountConnection = new SqlConnection(connectionString);
            SqlConnectionPool.AccountCommand = new SqlCommand();
            SqlConnectionPool.AccountCommand.CommandTimeout = Configuration.CommandTimeout;

            return true;
        }

        /// <summary>
        /// Closes the account database connection
        /// </summary>
        public static bool CloseAccountConnection()
        {
            if (SqlConnectionPool.AccountConnection?.State == ConnectionState.Open)
            {
                SqlConnectionPool.AccountConnection.Close();
            }
            return true;
        }
        #endregion

        #region Warehouse Connection
        /// <summary>
        /// Opens a connection for warehouse database operations
        /// </summary>
        public static bool OpenWarehouseConnection()
        {
            string connectionString = BuildConnectionString(Conversions.ToString(Configuration.MuOnlineDatabase));

            SqlConnectionPool.WarehouseConnection = new SqlConnection(connectionString);
            SqlConnectionPool.WarehouseCommand = new SqlCommand();
            SqlConnectionPool.WarehouseCommand.CommandTimeout = Configuration.CommandTimeout;

            return true;
        }

        /// <summary>
        /// Closes the warehouse database connection
        /// </summary>
        public static bool CloseWarehouseConnection()
        {
            if (SqlConnectionPool.WarehouseConnection?.State == ConnectionState.Open)
            {
                SqlConnectionPool.WarehouseConnection.Close();
            }
            return true;
        }
        #endregion

        #region Inventory Connection
        /// <summary>
        /// Opens a connection for inventory database operations
        /// </summary>
        public static bool OpenInventoryConnection()
        {
            string connectionString = BuildConnectionString(Conversions.ToString(Configuration.MuOnlineDatabase));

            SqlConnectionPool.InventoryConnection = new SqlConnection(connectionString);
            SqlConnectionPool.InventoryCommand = new SqlCommand();
            SqlConnectionPool.InventoryCommand.CommandTimeout = Configuration.CommandTimeout;

            return true;
        }

        /// <summary>
        /// Closes the inventory database connection
        /// </summary>
        public static bool CloseInventoryConnection()
        {
            if (SqlConnectionPool.InventoryConnection?.State == ConnectionState.Open)
            {
                SqlConnectionPool.InventoryConnection.Close();
            }
            return true;
        }
        #endregion

        #region Guild Connection
        /// <summary>
        /// Opens a connection for guild database operations
        /// </summary>
        public static bool OpenGuildConnection()
        {
            string connectionString = BuildConnectionString(Conversions.ToString(Configuration.MuOnlineDatabase));

            SqlConnectionPool.GuildConnection = new SqlConnection(connectionString);
            SqlConnectionPool.GuildCommand = new SqlCommand();
            SqlConnectionPool.GuildCommand.CommandTimeout = Configuration.CommandTimeout;

            return true;
        }

        /// <summary>
        /// Closes the guild database connection
        /// </summary>
        public static bool CloseGuildConnection()
        {
            if (SqlConnectionPool.GuildConnection?.State == ConnectionState.Open)
            {
                SqlConnectionPool.GuildConnection.Close();
            }
            return true;
        }
        #endregion

        #region Local Database Connection (OleDb for MuMaker.mdb)
        /// <summary>
        /// Opens a connection to the local Access database
        /// </summary>
        public static bool OpenLocalDbConnection()
        {
            SqlConnectionPool.LocalDbConnection = new OleDbConnection();
            SqlConnectionPool.LocalDbConnection.ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=MuMaker.mdb;";
            SqlConnectionPool.LocalDbCommand = new OleDbCommand();
            SqlConnectionPool.LocalDbCommand.CommandTimeout = SqlConnectionPool.OleDbTimeout;

            return true;
        }

        /// <summary>
        /// Closes the local Access database connection
        /// </summary>
        public static bool CloseLocalDbConnection()
        {
            if (SqlConnectionPool.LocalDbConnection?.State == ConnectionState.Open)
            {
                SqlConnectionPool.LocalDbConnection.Close();
            }
            return true;
        }
        #endregion
    }
}
