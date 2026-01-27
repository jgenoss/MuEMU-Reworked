// MuMaker - SQL Connection Pool
// Manages SQL Server connections and commands

using System.Data.OleDb;
using System.Data.SqlClient;

namespace MuMaker.Core
{
    /// <summary>
    /// Centralized SQL connection and command management
    /// </summary>
    public static class SqlConnectionPool
    {
        #region SQL Server Connections
        /// <summary>
        /// Primary SQL connection for general operations
        /// </summary>
        public static SqlConnection PrimaryConnection;

        /// <summary>
        /// SQL command for primary connection
        /// </summary>
        public static SqlCommand PrimaryCommand;

        /// <summary>
        /// Data reader for primary connection
        /// </summary>
        public static SqlDataReader PrimaryReader;

        /// <summary>
        /// Operation result code
        /// </summary>
        public static int OperationResult;

        /// <summary>
        /// SQL parameter for stored procedures
        /// </summary>
        public static SqlParameter StoredProcParameter;
        #endregion

        #region Character Database Connections
        /// <summary>
        /// Connection for character database operations
        /// </summary>
        public static SqlConnection CharacterConnection;

        /// <summary>
        /// Command for character database operations
        /// </summary>
        public static SqlCommand CharacterCommand;

        /// <summary>
        /// Reader for character database operations
        /// </summary>
        public static SqlDataReader CharacterReader;
        #endregion

        #region Account Database Connections
        /// <summary>
        /// Connection for account database operations
        /// </summary>
        public static SqlConnection AccountConnection;

        /// <summary>
        /// Command for account database operations
        /// </summary>
        public static SqlCommand AccountCommand;

        /// <summary>
        /// Reader for account database operations
        /// </summary>
        public static SqlDataReader AccountReader;
        #endregion

        #region Warehouse Database Connections
        /// <summary>
        /// Connection for warehouse database operations
        /// </summary>
        public static SqlConnection WarehouseConnection;

        /// <summary>
        /// Command for warehouse database operations
        /// </summary>
        public static SqlCommand WarehouseCommand;

        /// <summary>
        /// Reader for warehouse database operations
        /// </summary>
        public static SqlDataReader WarehouseReader;
        #endregion

        #region Inventory Database Connections
        /// <summary>
        /// Connection for inventory database operations
        /// </summary>
        public static SqlConnection InventoryConnection;

        /// <summary>
        /// Command for inventory database operations
        /// </summary>
        public static SqlCommand InventoryCommand;

        /// <summary>
        /// Reader for inventory database operations
        /// </summary>
        public static SqlDataReader InventoryReader;
        #endregion

        #region Guild Database Connections
        /// <summary>
        /// Connection for guild database operations
        /// </summary>
        public static SqlConnection GuildConnection;

        /// <summary>
        /// Command for guild database operations
        /// </summary>
        public static SqlCommand GuildCommand;

        /// <summary>
        /// Reader for guild database operations
        /// </summary>
        public static SqlDataReader GuildReader;
        #endregion

        #region OleDb Connections (for local MDB database)
        /// <summary>
        /// Default OleDb command timeout
        /// </summary>
        public static int OleDbTimeout = 360;

        /// <summary>
        /// Primary OleDb connection for local database
        /// </summary>
        public static OleDbConnection LocalDbConnection;

        /// <summary>
        /// Primary OleDb command for local database
        /// </summary>
        public static OleDbCommand LocalDbCommand;

        /// <summary>
        /// Primary OleDb reader for local database
        /// </summary>
        public static OleDbDataReader LocalDbReader;

        /// <summary>
        /// Secondary OleDb connection for local database
        /// </summary>
        public static OleDbConnection SecondaryLocalDbConnection;

        /// <summary>
        /// Secondary OleDb command for local database
        /// </summary>
        public static OleDbCommand SecondaryLocalDbCommand;

        /// <summary>
        /// Secondary OleDb reader for local database
        /// </summary>
        public static OleDbDataReader SecondaryLocalDbReader;
        #endregion
    }
}
