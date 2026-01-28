// MuMaker - Finder Table Manager
// Refactored from Class21

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using MuMaker.Core;
using System;

namespace MuMaker.Data
{
    /// <summary>
    /// Manages the MuMakerFinderMaker database table for item search results
    /// </summary>
    [StandardModule]
    internal sealed class FinderTableManager
    {
        /// <summary>
        /// Add reset column to Character table
        /// </summary>
        /// <returns>True on success</returns>
        public static object AddResetColumn()
        {
            if (Operators.ConditionalCompareObjectEqual(
                (object)Interaction.MsgBox(
                    Operators.ConcatenateObject(
                        Operators.ConcatenateObject(
                            Operators.ConcatenateObject(
                                Operators.ConcatenateObject(
                                    (object)"Create Colum '", Configuration.ResetColumnName),
                                (object)"', in Table 'Character' in Data Base "),
                            Configuration.MuOnlineDatabase),
                        (object)"?"),
                    MsgBoxStyle.YesNo, (object)"!! Reset System !!"),
                (object)MsgBoxResult.Yes, false))
            {
                ConnectionManager.OpenMemberDatabase();
                try
                {
                    SqlConnectionPool.MemberDbConnection.Open();
                    SqlConnectionPool.MemberDbCommand.Connection = SqlConnectionPool.MemberDbConnection;
                    SqlConnectionPool.MemberDbCommand.CommandText = Conversions.ToString(
                        Operators.ConcatenateObject(
                            Operators.ConcatenateObject(
                                (object)"ALTER TABLE [dbo].[Character] ADD [", Configuration.ResetColumnName),
                            (object)"] [int] NOT NULL default 0"));
                    SqlConnectionPool.MemberDbReader = SqlConnectionPool.MemberDbCommand.ExecuteReader();
                    SqlConnectionPool.MemberDbReader.Close();

                    IniHelper.WriteIniValue(
                        ApplicationServices.MuMakerApplication.GetApplicationInstance().Info.DirectoryPath + "/Config.ini",
                        "SQL", "Reset",
                        Conversions.ToString(Configuration.ResetColumnName));
                    IniHelper.WriteIniValue(
                        ApplicationServices.MuMakerApplication.GetApplicationInstance().Info.DirectoryPath + "/Config.ini",
                        "Config", "Reset", "1");
                }
                catch (Exception ex)
                {
                    ProjectData.SetProjectError(ex);
                    int num = (int)Interaction.MsgBox((object)ex.Message, MsgBoxStyle.OkOnly, (object)null);
                    ProjectData.ClearProjectError();
                }
                ConnectionManager.CloseMemberDatabase();
            }
            return (object)true;
        }

        /// <summary>
        /// Create or truncate the MuMakerFinderMaker table
        /// </summary>
        /// <returns>True on success</returns>
        public static object CreateOrTruncateFinderTable()
        {
            ConnectionManager.OpenMemberDatabase();
            try
            {
                SqlConnectionPool.MemberDbConnection.Open();
                SqlConnectionPool.MemberDbCommand.Connection = SqlConnectionPool.MemberDbConnection;
                SqlConnectionPool.MemberDbCommand.CommandText =
                    @"IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1)
TRUNCATE TABLE [dbo].[MuMakerFinderMaker]
ELSE
 CREATE TABLE [dbo].[MuMakerFinderMaker] ( [ID] [bigint] IDENTITY(1,1) NOT NULL,[AC] [varchar](10) COLLATE Chinese_PRC_CI_AS NOT NULL,[PJ] [varchar](10) COLLATE Chinese_PRC_CI_AS NOT NULL,[Vault] [smallint] NOT NULL,[Invent] [smallint] NOT NULL,[ExtraW] [smallint] NOT NULL,[NumExtraW] [smallint] NOT NULL,[Pos] [smallint] NOT NULL,[Item] [varchar](32) COLLATE Chinese_PRC_CI_AS NOT NULL,[Serial] [varchar](8) COLLATE Chinese_PRC_CI_AS NOT NULL,[FullEXE] [bit] NULL,[ExeAnc] [bit] NULL,[Full380] [bit] NULL,[FullJoH] [bit] NULL,[FullScK] [bit] NULL,[CodeItems] [varchar](4000) COLLATE Chinese_PRC_CI_AS NOT NULL) ON [PRIMARY]";
                SqlConnectionPool.MemberDbReader = SqlConnectionPool.MemberDbCommand.ExecuteReader();
                SqlConnectionPool.MemberDbReader.Close();
            }
            catch (Exception ex)
            {
                ProjectData.SetProjectError(ex);
                int num = (int)Interaction.MsgBox((object)ex.Message, MsgBoxStyle.OkOnly, (object)null);
                ProjectData.ClearProjectError();
            }
            ConnectionManager.CloseMemberDatabase();
            return (object)true;
        }

        /// <summary>
        /// Truncate the MuMakerFinderMaker table (clear all data)
        /// </summary>
        /// <returns>True on success</returns>
        public static object TruncateFinderTable()
        {
            ConnectionManager.OpenMemberDatabase();
            try
            {
                SqlConnectionPool.MemberDbConnection.Open();
                SqlConnectionPool.MemberDbCommand.Connection = SqlConnectionPool.MemberDbConnection;
                SqlConnectionPool.MemberDbCommand.CommandText =
                    "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1) TRUNCATE TABLE [dbo].[MuMakerFinderMaker]";
                SqlConnectionPool.MemberDbReader = SqlConnectionPool.MemberDbCommand.ExecuteReader();
                SqlConnectionPool.MemberDbReader.Close();
            }
            catch (Exception ex)
            {
                ProjectData.SetProjectError(ex);
                int num = (int)Interaction.MsgBox((object)ex.Message, MsgBoxStyle.OkOnly, (object)null);
                ProjectData.ClearProjectError();
            }
            ConnectionManager.CloseMemberDatabase();
            return (object)true;
        }

        /// <summary>
        /// Drop the MuMakerFinderMaker table
        /// </summary>
        /// <returns>True on success</returns>
        public static object DropFinderTable()
        {
            ConnectionManager.OpenMemberDatabase();
            try
            {
                SqlConnectionPool.MemberDbConnection.Open();
                SqlConnectionPool.MemberDbCommand.Connection = SqlConnectionPool.MemberDbConnection;
                SqlConnectionPool.MemberDbCommand.CommandText =
                    @"IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1)
DROP TABLE [dbo].[MuMakerFinderMaker]";
                SqlConnectionPool.MemberDbReader = SqlConnectionPool.MemberDbCommand.ExecuteReader();
                SqlConnectionPool.MemberDbReader.Close();
            }
            catch (Exception ex)
            {
                ProjectData.SetProjectError(ex);
                int num = (int)Interaction.MsgBox((object)ex.Message, MsgBoxStyle.OkOnly, (object)null);
                ProjectData.ClearProjectError();
            }
            ConnectionManager.CloseMemberDatabase();
            return (object)true;
        }

        /// <summary>
        /// Update/repair all columns in the MuMakerFinderMaker table
        /// </summary>
        /// <returns>True on success</returns>
        public static object RepairFinderTableColumns()
        {
            // Update AC column
            ExecuteAlterColumn("[AC] [varchar](10) COLLATE Chinese_PRC_CI_AS NOT NULL");
            // Update PJ column
            ExecuteAlterColumn("[PJ] [varchar](10) COLLATE Chinese_PRC_CI_AS NOT NULL");
            // Update Vault column
            ExecuteAlterColumn("[Vault] [smallint] NOT NULL");
            // Update Invent column
            ExecuteAlterColumn("[Invent] [smallint] NOT NULL");
            // Update ExtraW column
            ExecuteAlterColumn("[ExtraW] [smallint] NOT NULL");
            // Update NumExtraW column
            ExecuteAlterColumn("[NumExtraW] [smallint] NOT NULL");
            // Update Pos column
            ExecuteAlterColumn("[Pos] [smallint] NOT NULL");
            // Update Item column
            ExecuteAlterColumn("[Item] [varchar](32) COLLATE Chinese_PRC_CI_AS NOT NULL");
            // Update Serial column
            ExecuteAlterColumn("[Serial] [varchar](8) COLLATE Chinese_PRC_CI_AS NOT NULL");
            // Update FullEXE column
            ExecuteAlterColumn("[FullEXE] [bit] NULL");
            // Update ExeAnc column
            ExecuteAlterColumn("[ExeAnc] [bit] NULL");
            // Update Full380 column
            ExecuteAlterColumn("[Full380] [bit] NULL");
            // Update FullJoH column
            ExecuteAlterColumn("[FullJoH] [bit] NULL");
            // Update FullScK column
            ExecuteAlterColumn("[FullScK] [bit] NULL");
            // Update CodeItems column
            ExecuteAlterColumn("[CodeItems] [varchar](4000) COLLATE Chinese_PRC_CI_AS NOT NULL");

            return (object)true;
        }

        /// <summary>
        /// Execute an ALTER COLUMN command on the MuMakerFinderMaker table
        /// </summary>
        private static void ExecuteAlterColumn(string columnDefinition)
        {
            ConnectionManager.OpenMemberDatabase();
            try
            {
                SqlConnectionPool.MemberDbConnection.Open();
                SqlConnectionPool.MemberDbCommand.Connection = SqlConnectionPool.MemberDbConnection;
                SqlConnectionPool.MemberDbCommand.CommandText =
                    "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1) " +
                    "ALTER TABLE [dbo].[MuMakerFinderMaker] ALTER COLUMN " + columnDefinition;
                SqlConnectionPool.MemberDbCommand.ExecuteReader();
            }
            catch (Exception ex)
            {
                ProjectData.SetProjectError(ex);
                int num = (int)Interaction.MsgBox((object)ex.Message, MsgBoxStyle.OkOnly, (object)null);
                ProjectData.ClearProjectError();
            }
            ConnectionManager.CloseMemberDatabase();
        }

        #region Original Method Aliases (smethod_X backward compatibility)
        /// <summary>smethod_0 - Add reset column</summary>
        public static object smethod_0() => AddResetColumn();

        /// <summary>smethod_1 - Create or truncate finder table</summary>
        public static object smethod_1() => CreateOrTruncateFinderTable();

        /// <summary>smethod_2 - Truncate finder table</summary>
        public static object smethod_2() => TruncateFinderTable();

        /// <summary>smethod_3 - Drop finder table</summary>
        public static object smethod_3() => DropFinderTable();

        /// <summary>smethod_4 - Repair finder table columns</summary>
        public static object smethod_4() => RepairFinderTableColumns();
        #endregion
    }
}
