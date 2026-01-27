// MuMaker - Guild Alliance Manager
// Refactored from Class14

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using MuMaker.Core;
using MuMaker.Models;
using System;

namespace MuMaker.Data
{
    /// <summary>
    /// Manages guild unions (alliances) and rivals
    /// </summary>
    [StandardModule]
    internal sealed class GuildAllianceManager
    {
        /// <summary>
        /// Create a guild union (alliance) between two guilds
        /// </summary>
        /// <returns>True on success</returns>
        public static object CreateGuildUnion()
        {
            ConnectionManager.OpenMemberDatabase();
            int unionGuildNumber;

            // Get the guild number of the union target guild
            try
            {
                SqlConnectionPool.MemberDbConnection.Open();
                SqlConnectionPool.MemberDbCommand.Connection = SqlConnectionPool.MemberDbConnection;
                SqlConnectionPool.MemberDbCommand.CommandText = "SELECT Number FROM Guild WHERE G_Name='" +
                    GuildData.CurrentGuild.UnionGuildName + "'";
                SqlConnectionPool.MemberDbReader = SqlConnectionPool.MemberDbCommand.ExecuteReader();
                SqlConnectionPool.MemberDbReader.Read();
                unionGuildNumber = Conversions.ToInteger(SqlConnectionPool.MemberDbReader["Number"].ToString());
                SqlConnectionPool.MemberDbReader.Close();
            }
            catch (Exception ex)
            {
                ProjectData.SetProjectError(ex);
                unionGuildNumber = 0;
                ProjectData.ClearProjectError();
            }
            ConnectionManager.CloseMemberDatabase();

            // Set the union for the current guild
            try
            {
                SqlConnectionPool.MemberDbConnection.Open();
                SqlConnectionPool.MemberDbCommand.Connection = SqlConnectionPool.MemberDbConnection;
                SqlConnectionPool.MemberDbCommand.CommandText = "UPDATE Guild SET G_Union=" +
                    Conversions.ToString(unionGuildNumber) + " WHERE G_Name = '" +
                    GuildData.CurrentGuild.GuildName + "'";
                SqlConnectionPool.MemberDbCommand.ExecuteReader();
            }
            catch (Exception ex)
            {
                ProjectData.SetProjectError(ex);
                int num = (int)Interaction.MsgBox((object)ex.Message, MsgBoxStyle.OkOnly, (object)null);
                ProjectData.ClearProjectError();
            }
            ConnectionManager.CloseMemberDatabase();

            int currentGuildNumber;
            // Get the guild number of the current guild
            try
            {
                SqlConnectionPool.MemberDbConnection.Open();
                SqlConnectionPool.MemberDbCommand.Connection = SqlConnectionPool.MemberDbConnection;
                SqlConnectionPool.MemberDbCommand.CommandText = "SELECT Number FROM Guild WHERE G_Name='" +
                    GuildData.CurrentGuild.GuildName + "'";
                SqlConnectionPool.MemberDbReader = SqlConnectionPool.MemberDbCommand.ExecuteReader();
                SqlConnectionPool.MemberDbReader.Read();
                currentGuildNumber = Conversions.ToInteger(SqlConnectionPool.MemberDbReader["Number"].ToString());
                SqlConnectionPool.MemberDbReader.Close();
            }
            catch (Exception ex)
            {
                ProjectData.SetProjectError(ex);
                currentGuildNumber = 0;
                ProjectData.ClearProjectError();
            }
            ConnectionManager.CloseMemberDatabase();

            // Set the union for the target guild (bidirectional)
            try
            {
                SqlConnectionPool.MemberDbConnection.Open();
                SqlConnectionPool.MemberDbCommand.Connection = SqlConnectionPool.MemberDbConnection;
                SqlConnectionPool.MemberDbCommand.CommandText = "UPDATE Guild SET G_Union=" +
                    Conversions.ToString(currentGuildNumber) + " WHERE G_Name = '" +
                    GuildData.CurrentGuild.UnionGuildName + "'";
                SqlConnectionPool.MemberDbCommand.ExecuteReader();
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
        /// Create a guild rivalry between two guilds
        /// </summary>
        /// <returns>True on success</returns>
        public static object CreateGuildRivalry()
        {
            ConnectionManager.OpenMemberDatabase();
            int rivalGuildNumber;

            // Get the guild number of the rival target guild
            try
            {
                SqlConnectionPool.MemberDbConnection.Open();
                SqlConnectionPool.MemberDbCommand.Connection = SqlConnectionPool.MemberDbConnection;
                SqlConnectionPool.MemberDbCommand.CommandText = "SELECT Number FROM Guild WHERE G_Name='" +
                    GuildData.CurrentGuild.RivalGuildName + "'";
                SqlConnectionPool.MemberDbReader = SqlConnectionPool.MemberDbCommand.ExecuteReader();
                SqlConnectionPool.MemberDbReader.Read();
                rivalGuildNumber = Conversions.ToInteger(SqlConnectionPool.MemberDbReader["Number"].ToString());
                SqlConnectionPool.MemberDbReader.Close();
            }
            catch (Exception ex)
            {
                ProjectData.SetProjectError(ex);
                rivalGuildNumber = 0;
                ProjectData.ClearProjectError();
            }
            ConnectionManager.CloseMemberDatabase();

            // Set the rival for the current guild
            try
            {
                SqlConnectionPool.MemberDbConnection.Open();
                SqlConnectionPool.MemberDbCommand.Connection = SqlConnectionPool.MemberDbConnection;
                SqlConnectionPool.MemberDbCommand.CommandText = "UPDATE Guild SET G_Rival=" +
                    Conversions.ToString(rivalGuildNumber) + " WHERE G_Name = '" +
                    GuildData.CurrentGuild.GuildName + "'";
                SqlConnectionPool.MemberDbCommand.ExecuteReader();
            }
            catch (Exception ex)
            {
                ProjectData.SetProjectError(ex);
                int num = (int)Interaction.MsgBox((object)ex.Message, MsgBoxStyle.OkOnly, (object)null);
                ProjectData.ClearProjectError();
            }
            ConnectionManager.CloseMemberDatabase();

            int currentGuildNumber;
            // Get the guild number of the current guild
            try
            {
                SqlConnectionPool.MemberDbConnection.Open();
                SqlConnectionPool.MemberDbCommand.Connection = SqlConnectionPool.MemberDbConnection;
                SqlConnectionPool.MemberDbCommand.CommandText = "SELECT Number FROM Guild WHERE G_Name='" +
                    GuildData.CurrentGuild.GuildName + "'";
                SqlConnectionPool.MemberDbReader = SqlConnectionPool.MemberDbCommand.ExecuteReader();
                SqlConnectionPool.MemberDbReader.Read();
                currentGuildNumber = Conversions.ToInteger(SqlConnectionPool.MemberDbReader["Number"].ToString());
                SqlConnectionPool.MemberDbReader.Close();
            }
            catch (Exception ex)
            {
                ProjectData.SetProjectError(ex);
                currentGuildNumber = 0;
                ProjectData.ClearProjectError();
            }
            ConnectionManager.CloseMemberDatabase();

            // Set the rival for the target guild (bidirectional)
            try
            {
                SqlConnectionPool.MemberDbConnection.Open();
                SqlConnectionPool.MemberDbCommand.Connection = SqlConnectionPool.MemberDbConnection;
                SqlConnectionPool.MemberDbCommand.CommandText = "UPDATE Guild SET G_Rival=" +
                    Conversions.ToString(currentGuildNumber) + " WHERE G_Name = '" +
                    GuildData.CurrentGuild.RivalGuildName + "'";
                SqlConnectionPool.MemberDbCommand.ExecuteReader();
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
    }
}
