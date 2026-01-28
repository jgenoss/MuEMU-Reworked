// MuMaker - Connection Manager
// Refactored from Class7
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
    [StandardModule]
    internal sealed class ConnectionManager
    {
        #region Connection String Building
        private static string BuildConnectionString(string database)
        {
            if (Operators.ConditionalCompareObjectEqual(Configuration.object_2, "Local", false))
            {
                return "Data Source=localhost; uid=" + Conversions.ToString(Configuration.object_3) +
                       ";pwd=" + Conversions.ToString(Configuration.object_4) +
                       ";database=" + database + ";";
            }
            else
            {
                return "Network Library=dbmssocn; Data Source=" + Conversions.ToString(Configuration.object_0) + "," +
                       Conversions.ToString(Configuration.object_1) + "; uid=" + Conversions.ToString(Configuration.object_3) +
                       ";pwd=" + Conversions.ToString(Configuration.object_4) + ";database=" + database + ";";
            }
        }
        #endregion

        #region Member/Account Connection (smethod_0, smethod_5)
        /// <summary>
        /// Opens connection for member database operations
        /// </summary>
        public static bool smethod_0()
        {
            string connectionString = BuildConnectionString(Conversions.ToString(Configuration.object_7));
            SqlConnectionPool.sqlConnection_1 = new SqlConnection(connectionString);
            SqlConnectionPool.sqlCommand_1 = new SqlCommand();
            SqlConnectionPool.sqlCommand_1.CommandTimeout = Configuration.int_0;
            return true;
        }

        /// <summary>
        /// Closes the member database connection
        /// </summary>
        public static bool smethod_5()
        {
            if (SqlConnectionPool.sqlConnection_1 != null && SqlConnectionPool.sqlConnection_1.State == ConnectionState.Open)
            {
                SqlConnectionPool.sqlConnection_1.Close();
            }
            return true;
        }
        #endregion

        #region Character Connection (smethod_1, smethod_6)
        /// <summary>
        /// Opens connection for character database operations
        /// </summary>
        public static bool smethod_1()
        {
            string connectionString = BuildConnectionString(Conversions.ToString(Configuration.object_7));
            SqlConnectionPool.sqlConnection_2 = new SqlConnection(connectionString);
            SqlConnectionPool.sqlCommand_2 = new SqlCommand();
            SqlConnectionPool.sqlCommand_2.CommandTimeout = Configuration.int_0;
            return true;
        }

        /// <summary>
        /// Closes the character database connection
        /// </summary>
        public static bool smethod_6()
        {
            if (SqlConnectionPool.sqlConnection_2 != null && SqlConnectionPool.sqlConnection_2.State == ConnectionState.Open)
            {
                SqlConnectionPool.sqlConnection_2.Close();
            }
            return true;
        }
        #endregion

        #region Warehouse Connection (smethod_2, smethod_7)
        /// <summary>
        /// Opens connection for warehouse database operations
        /// </summary>
        public static bool smethod_2()
        {
            string connectionString = BuildConnectionString(Conversions.ToString(Configuration.object_7));
            SqlConnectionPool.sqlConnection_3 = new SqlConnection(connectionString);
            SqlConnectionPool.sqlCommand_3 = new SqlCommand();
            SqlConnectionPool.sqlCommand_3.CommandTimeout = Configuration.int_0;
            return true;
        }

        /// <summary>
        /// Closes the warehouse database connection
        /// </summary>
        public static bool smethod_7()
        {
            if (SqlConnectionPool.sqlConnection_3 != null && SqlConnectionPool.sqlConnection_3.State == ConnectionState.Open)
            {
                SqlConnectionPool.sqlConnection_3.Close();
            }
            return true;
        }
        #endregion

        #region Inventory Connection (smethod_3, smethod_8)
        /// <summary>
        /// Opens connection for inventory database operations
        /// </summary>
        public static bool smethod_3()
        {
            string connectionString = BuildConnectionString(Conversions.ToString(Configuration.object_7));
            SqlConnectionPool.sqlConnection_4 = new SqlConnection(connectionString);
            SqlConnectionPool.sqlCommand_4 = new SqlCommand();
            SqlConnectionPool.sqlCommand_4.CommandTimeout = Configuration.int_0;
            return true;
        }

        /// <summary>
        /// Closes the inventory database connection
        /// </summary>
        public static bool smethod_8()
        {
            if (SqlConnectionPool.sqlConnection_4 != null && SqlConnectionPool.sqlConnection_4.State == ConnectionState.Open)
            {
                SqlConnectionPool.sqlConnection_4.Close();
            }
            return true;
        }
        #endregion

        #region Finder Connection (smethod_4, smethod_9)
        /// <summary>
        /// Opens connection for finder database operations
        /// </summary>
        public static bool smethod_4()
        {
            string connectionString = BuildConnectionString(Conversions.ToString(Configuration.object_7));
            SqlConnectionPool.sqlConnection_5 = new SqlConnection(connectionString);
            SqlConnectionPool.sqlCommand_5 = new SqlCommand();
            SqlConnectionPool.sqlCommand_5.CommandTimeout = Configuration.int_0;
            return true;
        }

        /// <summary>
        /// Closes the finder database connection
        /// </summary>
        public static bool smethod_9()
        {
            if (SqlConnectionPool.sqlConnection_5 != null && SqlConnectionPool.sqlConnection_5.State == ConnectionState.Open)
            {
                SqlConnectionPool.sqlConnection_5.Close();
            }
            return true;
        }
        #endregion

        #region Local Database Connection (smethod_10, smethod_11)
        /// <summary>
        /// Opens connection to local Access database (MuMaker.mdb)
        /// </summary>
        public static bool smethod_10()
        {
            SqlConnectionPool.oleDbConnection_0 = new OleDbConnection();
            SqlConnectionPool.oleDbConnection_0.ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=MuMaker.mdb;";
            SqlConnectionPool.oleDbCommand_0 = new OleDbCommand();
            SqlConnectionPool.oleDbCommand_0.CommandTimeout = SqlConnectionPool.int_0;
            return true;
        }

        /// <summary>
        /// Closes the local Access database connection
        /// </summary>
        public static bool smethod_11()
        {
            if (SqlConnectionPool.oleDbConnection_0 != null && SqlConnectionPool.oleDbConnection_0.State == ConnectionState.Open)
            {
                SqlConnectionPool.oleDbConnection_0.Close();
            }
            return true;
        }
        #endregion

        #region Descriptive Aliases (for new code)
        public static bool OpenMemberDatabase() => smethod_0();
        public static bool CloseMemberDatabase() => smethod_5();
        public static bool OpenCharacterDatabase() => smethod_1();
        public static bool CloseCharacterDatabase() => smethod_6();
        public static bool OpenWarehouseDatabase() => smethod_2();
        public static bool CloseWarehouseDatabase() => smethod_7();
        public static bool OpenInventoryDatabase() => smethod_3();
        public static bool CloseInventoryDatabase() => smethod_8();
        public static bool OpenFinderDatabase() => smethod_4();
        public static bool CloseFinderDatabase() => smethod_9();
        public static bool OpenLocalDatabase() => smethod_10();
        public static bool CloseLocalDatabase() => smethod_11();
        #endregion
    }
}
