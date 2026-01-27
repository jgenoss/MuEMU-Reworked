// MuMaker - SQL Connection Pool
// Refactored from Class28
// Manages SQL Server connections and commands

using Microsoft.VisualBasic.CompilerServices;
using System.Data.OleDb;
using System.Data.SqlClient;

namespace MuMaker.Core
{
    /// <summary>
    /// Centralized SQL connection and command management
    /// </summary>
    [StandardModule]
    internal sealed class SqlConnectionPool
    {
        #region SQL Server Connections (original naming)
        // Primary connection (sqlConnection_0 not used in original)
        public static SqlConnection sqlConnection_0;
        public static SqlCommand sqlCommand_0;
        public static SqlDataReader sqlDataReader_0;
        public static int int_1;  // Operation result
        public static SqlParameter sqlParameter_0;

        // Member database connection
        public static SqlConnection sqlConnection_1;
        public static SqlCommand sqlCommand_1;
        public static SqlDataReader sqlDataReader_1;

        // Character database connection
        public static SqlConnection sqlConnection_2;
        public static SqlCommand sqlCommand_2;
        public static SqlDataReader sqlDataReader_2;

        // Warehouse database connection
        public static SqlConnection sqlConnection_3;
        public static SqlCommand sqlCommand_3;
        public static SqlDataReader sqlDataReader_3;

        // Inventory database connection
        public static SqlConnection sqlConnection_4;
        public static SqlCommand sqlCommand_4;
        public static SqlDataReader sqlDataReader_4;

        // Finder database connection
        public static SqlConnection sqlConnection_5;
        public static SqlCommand sqlCommand_5;
        public static SqlDataReader sqlDataReader_5;
        #endregion

        #region OleDb Connections (for local MDB database)
        // OleDb timeout
        public static int int_0 = 360;

        // Primary OleDb connection
        public static OleDbConnection oleDbConnection_0;
        public static OleDbCommand oleDbCommand_0;
        public static OleDbDataReader oleDbDataReader_0;

        // Secondary OleDb connection
        public static OleDbConnection oleDbConnection_1;
        public static OleDbCommand oleDbCommand_1;
        public static OleDbDataReader oleDbDataReader_1;
        #endregion

        #region Descriptive Aliases (for new code)
        // Primary
        public static SqlConnection PrimaryConnection { get => sqlConnection_0; set => sqlConnection_0 = value; }
        public static SqlCommand PrimaryCommand { get => sqlCommand_0; set => sqlCommand_0 = value; }
        public static SqlDataReader PrimaryReader { get => sqlDataReader_0; set => sqlDataReader_0 = value; }

        // Member
        public static SqlConnection MemberDbConnection { get => sqlConnection_1; set => sqlConnection_1 = value; }
        public static SqlCommand MemberDbCommand { get => sqlCommand_1; set => sqlCommand_1 = value; }
        public static SqlDataReader MemberDbReader { get => sqlDataReader_1; set => sqlDataReader_1 = value; }

        // Character
        public static SqlConnection CharacterDbConnection { get => sqlConnection_2; set => sqlConnection_2 = value; }
        public static SqlCommand CharacterDbCommand { get => sqlCommand_2; set => sqlCommand_2 = value; }
        public static SqlDataReader CharacterDbReader { get => sqlDataReader_2; set => sqlDataReader_2 = value; }

        // Warehouse
        public static SqlConnection WarehouseDbConnection { get => sqlConnection_3; set => sqlConnection_3 = value; }
        public static SqlCommand WarehouseDbCommand { get => sqlCommand_3; set => sqlCommand_3 = value; }
        public static SqlDataReader WarehouseDbReader { get => sqlDataReader_3; set => sqlDataReader_3 = value; }

        // Inventory
        public static SqlConnection InventoryDbConnection { get => sqlConnection_4; set => sqlConnection_4 = value; }
        public static SqlCommand InventoryDbCommand { get => sqlCommand_4; set => sqlCommand_4 = value; }
        public static SqlDataReader InventoryDbReader { get => sqlDataReader_4; set => sqlDataReader_4 = value; }

        // Finder
        public static SqlConnection FinderDbConnection { get => sqlConnection_5; set => sqlConnection_5 = value; }
        public static SqlCommand FinderDbCommand { get => sqlCommand_5; set => sqlCommand_5 = value; }
        public static SqlDataReader FinderDbReader { get => sqlDataReader_5; set => sqlDataReader_5 = value; }

        // Local DB
        public static OleDbConnection LocalDbConnection { get => oleDbConnection_0; set => oleDbConnection_0 = value; }
        public static OleDbCommand LocalDbCommand { get => oleDbCommand_0; set => oleDbCommand_0 = value; }
        public static OleDbDataReader LocalDbReader { get => oleDbDataReader_0; set => oleDbDataReader_0 = value; }
        #endregion
    }
}
