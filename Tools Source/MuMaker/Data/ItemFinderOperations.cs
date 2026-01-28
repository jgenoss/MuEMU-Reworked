// MuMaker - Item Finder Operations
// Refactored from Class13

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using MuMaker.Core;
using System;
using System.Data;

namespace MuMaker.Data
{
    /// <summary>
    /// Operations for the Item Finder feature - searches and analyzes items across accounts
    /// </summary>
    [StandardModule]
    internal sealed class ItemFinderOperations
    {
        /// <summary>
        /// Insert a found item record into the MuMakerFinderMaker table
        /// </summary>
        public static object InsertFinderResult(
            object accountId,
            object characterName,
            object isVault,
            object isInventory,
            object isExtraWarehouse,
            object extraWarehouseNumber,
            object position,
            object itemHex,
            object serial,
            object hasFullExcellent,
            object hasExcellentAncient,
            object hasFull380,
            object hasFullJewelOfHarmony,
            object hasFullSocket,
            object itemCode)
        {
            ConnectionManager.OpenFinderDatabase();
            try
            {
                SqlConnectionPool.FinderDbConnection.Open();
                SqlConnectionPool.FinderDbCommand.Connection = SqlConnectionPool.FinderDbConnection;
                SqlConnectionPool.FinderDbCommand.CommandText = Conversions.ToString(
                    Operators.ConcatenateObject(
                        Operators.ConcatenateObject(
                            Operators.ConcatenateObject(
                                Operators.ConcatenateObject(
                                    Operators.ConcatenateObject(
                                        Operators.ConcatenateObject(
                                            Operators.ConcatenateObject(
                                                Operators.ConcatenateObject(
                                                    Operators.ConcatenateObject(
                                                        Operators.ConcatenateObject(
                                                            Operators.ConcatenateObject(
                                                                Operators.ConcatenateObject(
                                                                    Operators.ConcatenateObject(
                                                                        Operators.ConcatenateObject(
                                                                            Operators.ConcatenateObject(
                                                                                Operators.ConcatenateObject(
                                                                                    Operators.ConcatenateObject(
                                                                                        Operators.ConcatenateObject(
                                                                                            Operators.ConcatenateObject(
                                                                                                Operators.ConcatenateObject(
                                                                                                    Operators.ConcatenateObject(
                                                                                                        Operators.ConcatenateObject(
                                                                                                            Operators.ConcatenateObject(
                                                                                                                Operators.ConcatenateObject(
                                                                                                                    Operators.ConcatenateObject(
                                                                                                                        Operators.ConcatenateObject(
                                                                                                                            Operators.ConcatenateObject(
                                                                                                                                Operators.ConcatenateObject(
                                                                                                                                    Operators.ConcatenateObject(
                                                                                                                                        Operators.ConcatenateObject(
                                                                                                                                            (object)"INSERT INTO MuMakerFinderMaker (AC, PJ, Vault, Invent, ExtraW, NumExtraW, Pos, Item, Serial, FullEXE, ExeAnc, Full380, FullJoH, FullSck, CodeItems) VALUES ('",
                                                                                                                                            accountId),
                                                                                                                                        (object)"','"),
                                                                                                                                    characterName),
                                                                                                                                (object)"','"),
                                                                                                                            isVault),
                                                                                                                        (object)"','"),
                                                                                                                    isInventory),
                                                                                                                (object)"','"),
                                                                                                            isExtraWarehouse),
                                                                                                        (object)"','"),
                                                                                                    extraWarehouseNumber),
                                                                                                (object)"','"),
                                                                                            position),
                                                                                        (object)"','"),
                                                                                    itemHex),
                                                                                (object)"','"),
                                                                            serial),
                                                                        (object)"','"),
                                                                    hasFullExcellent),
                                                                (object)"','"),
                                                            hasExcellentAncient),
                                                        (object)"','"),
                                                    hasFull380),
                                                (object)"','"),
                                            hasFullJewelOfHarmony),
                                        (object)"','"),
                                    hasFullSocket),
                                (object)"','"),
                            itemCode),
                        (object)"');"));
                SqlConnectionPool.FinderDbCommand.ExecuteReader();
            }
            catch (Exception ex)
            {
                ProjectData.SetProjectError(ex);
                int num = (int)Interaction.MsgBox((object)ex.Message, MsgBoxStyle.OkOnly, (object)null);
                ProjectData.ClearProjectError();
            }
            ConnectionManager.CloseFinderDatabase();
            return (object)true;
        }

        /// <summary>
        /// Count total accounts in database for progress tracking
        /// </summary>
        /// <returns>True on success</returns>
        public static object CountTotalAccounts()
        {
            try
            {
                ConnectionManager.OpenMemberDatabase();
                SqlConnectionPool.MemberDbConnection.Open();
                SqlConnectionPool.MemberDbCommand.Connection = SqlConnectionPool.MemberDbConnection;
                SqlConnectionPool.MemberDbCommand.CommandText = "SELECT memb___id FROM MEMB_INFO ORDER BY memb___id ASC";
                SqlConnectionPool.MemberDbReader = SqlConnectionPool.MemberDbCommand.ExecuteReader();
                SearchState.TotalAccountCount = 0;
                while (SqlConnectionPool.MemberDbReader.Read())
                {
                    checked { ++SearchState.TotalAccountCount; }
                }
                SqlConnectionPool.MemberDbReader.Close();
            }
            catch (Exception ex)
            {
                ProjectData.SetProjectError(ex);
                int num = (int)Interaction.MsgBox((object)ex.Message, MsgBoxStyle.OkOnly, (object)null);
                ProjectData.ClearProjectError();
            }
            if (SqlConnectionPool.MemberDbConnection.State == ConnectionState.Open)
                SqlConnectionPool.MemberDbConnection.Close();
            return (object)true;
        }

        /// <summary>
        /// Check if item has full excellent options (3F or 7F at position 15-16)
        /// </summary>
        /// <param name="itemHex">32-character item hex string</param>
        /// <returns>"1" if full excellent, "0" otherwise</returns>
        public static object CheckFullExcellent(object itemHex)
        {
            string excellentByte = Strings.Mid(Conversions.ToString(itemHex), 15, 2);
            return (Operators.CompareString(excellentByte, "3F", false) == 0 |
                    Operators.CompareString(excellentByte, "7F", false) == 0)
                ? (object)"1"
                : (object)"0";
        }

        /// <summary>
        /// Check if item has 380 option (8 at position 20)
        /// </summary>
        /// <param name="itemHex">32-character item hex string</param>
        /// <returns>"1" if has 380, "0" otherwise</returns>
        public static object CheckHas380Option(object itemHex)
        {
            return Operators.CompareString(Strings.Mid(Conversions.ToString(itemHex), 20, 1), "8", false) != 0
                ? (object)"0"
                : (object)"1";
        }

        /// <summary>
        /// Check if item has full Jewel of Harmony (F at position 22)
        /// </summary>
        /// <param name="itemHex">32-character item hex string</param>
        /// <returns>"1" if full JoH, "0" otherwise</returns>
        public static object CheckFullJewelOfHarmony(object itemHex)
        {
            return Operators.CompareString(Strings.Mid(Conversions.ToString(itemHex), 22, 1), "F", false) != 0
                ? (object)"0"
                : (object)"1";
        }

        /// <summary>
        /// Check if item has excellent + ancient combination
        /// </summary>
        /// <param name="itemHex">32-character item hex string</param>
        /// <returns>"1" if excellent ancient, "0" otherwise</returns>
        public static object CheckExcellentAncient(object itemHex)
        {
            string hasExcellent = Conversions.ToString(0);
            string excellentValue = Conversions.ToString(Conversion.Val("&H" + Strings.Mid(Conversions.ToString(itemHex), 15, 2)));

            // Remove high bits to check for excellent options
            if (Conversions.ToDouble(excellentValue) >= 128.0)
                excellentValue = Conversions.ToString(Conversions.ToDouble(excellentValue) - 128.0);
            if (Conversions.ToDouble(excellentValue) >= 64.0)
                excellentValue = Conversions.ToString(Conversions.ToDouble(excellentValue) - 64.0);
            if (Conversions.ToDouble(excellentValue) >= 32.0)
            {
                excellentValue = Conversions.ToString(Conversions.ToDouble(excellentValue) - 32.0);
                hasExcellent = Conversions.ToString(1);
            }
            if (Conversions.ToDouble(excellentValue) >= 16.0)
            {
                excellentValue = Conversions.ToString(Conversions.ToDouble(excellentValue) - 16.0);
                hasExcellent = Conversions.ToString(1);
            }
            if (Conversions.ToDouble(excellentValue) >= 8.0)
            {
                excellentValue = Conversions.ToString(Conversions.ToDouble(excellentValue) - 8.0);
                hasExcellent = Conversions.ToString(1);
            }
            if (Conversions.ToDouble(excellentValue) >= 4.0)
            {
                excellentValue = Conversions.ToString(Conversions.ToDouble(excellentValue) - 4.0);
                hasExcellent = Conversions.ToString(1);
            }
            if (Conversions.ToDouble(excellentValue) >= 2.0)
            {
                excellentValue = Conversions.ToString(Conversions.ToDouble(excellentValue) - 2.0);
                hasExcellent = Conversions.ToString(1);
            }
            if (Conversions.ToDouble(excellentValue) > 0.0)
                hasExcellent = Conversions.ToString(1);

            // Check if excellent AND ancient (5 or 9 at position 18)
            string ancientByte = Strings.Mid(Conversions.ToString(itemHex), 18, 1);
            return (Conversions.ToDouble(hasExcellent) == 1.0 &
                    (Operators.CompareString(ancientByte, "5", false) == 0 |
                     Operators.CompareString(ancientByte, "9", false) == 0))
                ? (object)"1"
                : (object)"0";
        }

        /// <summary>
        /// Check if item has socket options (non-00 values at positions 23-32)
        /// </summary>
        /// <param name="itemHex">32-character item hex string</param>
        /// <returns>"1" if has sockets, "0" otherwise</returns>
        public static object CheckHasSocket(object itemHex)
        {
            // Check all 5 socket slots (positions 23-24, 25-26, 27-28, 29-30, 31-32)
            if (Operators.CompareString(Strings.Mid(Conversions.ToString(itemHex), 23, 2), "00", false) == 0)
                return (object)"0";
            if (Operators.CompareString(Strings.Mid(Conversions.ToString(itemHex), 25, 2), "00", false) == 0)
                return (object)"0";
            if (Operators.CompareString(Strings.Mid(Conversions.ToString(itemHex), 27, 2), "00", false) == 0)
                return (object)"0";
            if (Operators.CompareString(Strings.Mid(Conversions.ToString(itemHex), 29, 2), "00", false) == 0)
                return (object)"0";
            if (Operators.CompareString(Strings.Mid(Conversions.ToString(itemHex), 31, 2), "00", false) == 0)
                return (object)"0";
            return (object)"1";
        }

        #region Original Method Aliases (smethod_X backward compatibility)
        /// <summary>smethod_0 - Insert finder result</summary>
        public static object smethod_0(
            object accountId, object characterName, object isVault, object isInventory,
            object isExtraWarehouse, object extraWarehouseNumber, object position, object itemHex,
            object serial, object hasFullExcellent, object hasExcellentAncient, object hasFull380,
            object hasFullJewelOfHarmony, object hasFullSocket, object itemCode)
            => InsertFinderResult(accountId, characterName, isVault, isInventory, isExtraWarehouse,
                extraWarehouseNumber, position, itemHex, serial, hasFullExcellent, hasExcellentAncient,
                hasFull380, hasFullJewelOfHarmony, hasFullSocket, itemCode);

        /// <summary>smethod_1 - Count total accounts</summary>
        public static object smethod_1() => CountTotalAccounts();

        /// <summary>smethod_2 - Check full excellent</summary>
        public static object smethod_2(object itemHex) => CheckFullExcellent(itemHex);

        /// <summary>smethod_3 - Check has 380 option</summary>
        public static object smethod_3(object itemHex) => CheckHas380Option(itemHex);

        /// <summary>smethod_4 - Check full jewel of harmony</summary>
        public static object smethod_4(object itemHex) => CheckFullJewelOfHarmony(itemHex);

        /// <summary>smethod_5 - Check excellent ancient</summary>
        public static object smethod_5(object itemHex) => CheckExcellentAncient(itemHex);

        /// <summary>smethod_6 - Check has socket</summary>
        public static object smethod_6(object itemHex) => CheckHasSocket(itemHex);
        #endregion
    }
}
