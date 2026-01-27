// MuMaker - Account Status Manager
// Refactored from Class12

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using MuMaker.Core;
using MuMaker.Models;
using System;

namespace MuMaker.Data
{
    /// <summary>
    /// Manages account connection status and ban state
    /// </summary>
    [StandardModule]
    internal sealed class AccountStatusManager
    {
        /// <summary>
        /// Check if the current account is connected (online)
        /// </summary>
        public static void CheckConnectionStatus()
        {
            ConnectionManager.OpenMemberDatabase();
            try
            {
                SqlConnectionPool.MemberDbConnection.Open();
                SqlConnectionPool.MemberDbCommand.Connection = SqlConnectionPool.MemberDbConnection;
                SqlConnectionPool.MemberDbCommand.CommandText = "SELECT ConnectStat FROM MEMB_STAT WHERE memb___id='" +
                    AccountData.CurrentAccount.AccountId + "'";
                SqlConnectionPool.MemberDbReader = SqlConnectionPool.MemberDbCommand.ExecuteReader();
                AccountData.CurrentAccount.IsOnline = SqlConnectionPool.MemberDbReader.Read() &&
                    Conversions.ToDouble(SqlConnectionPool.MemberDbReader[0].ToString()) == 1.0;
                SqlConnectionPool.MemberDbReader.Close();
            }
            catch (Exception ex)
            {
                ProjectData.SetProjectError(ex);
                ProjectData.ClearProjectError();
            }
            ConnectionManager.CloseMemberDatabase();
        }

        /// <summary>
        /// Disconnect the current account (set ConnectStat to 0)
        /// </summary>
        /// <returns>True on success</returns>
        public static object DisconnectAccount()
        {
            ConnectionManager.OpenMemberDatabase();
            try
            {
                SqlConnectionPool.MemberDbConnection.Open();
                SqlConnectionPool.MemberDbCommand.Connection = SqlConnectionPool.MemberDbConnection;
                SqlConnectionPool.MemberDbCommand.CommandText = "UPDATE MEMB_STAT SET ConnectStat=0 WHERE memb___id='" +
                    AccountData.CurrentAccount.AccountId + "'";
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
        /// Update account ban status (CtlCode)
        /// </summary>
        /// <param name="currentStatus">Current status ("Baned" to unban, otherwise ban)</param>
        /// <param name="accountId">Account ID to update</param>
        /// <returns>True on success</returns>
        public static object UpdateBanStatus(object currentStatus, object accountId)
        {
            if (Operators.ConditionalCompareObjectEqual(currentStatus, (object)"Baned", false))
            {
                // Unban account - set CtlCode to 0
                ConnectionManager.OpenMemberDatabase();
                try
                {
                    SqlConnectionPool.MemberDbConnection.Open();
                    SqlConnectionPool.MemberDbCommand.Connection = SqlConnectionPool.MemberDbConnection;
                    SqlConnectionPool.MemberDbCommand.CommandText = Conversions.ToString(
                        Operators.ConcatenateObject(
                            Operators.ConcatenateObject(
                                (object)"UPDATE Character SET CtlCode=0 WHERE AccountID='", accountId),
                            (object)"'"));
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
            }
            else
            {
                // Ban account - set CtlCode to 1
                try
                {
                    SqlConnectionPool.MemberDbConnection.Open();
                    SqlConnectionPool.MemberDbCommand.Connection = SqlConnectionPool.MemberDbConnection;
                    SqlConnectionPool.MemberDbCommand.CommandText = Conversions.ToString(
                        Operators.ConcatenateObject(
                            Operators.ConcatenateObject(
                                (object)"UPDATE Character SET CtlCode=1 WHERE AccountID='", accountId),
                            (object)"'"));
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
            }
            return (object)true;
        }
    }
}
