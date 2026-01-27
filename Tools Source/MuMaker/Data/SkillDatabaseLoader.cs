// MuMaker - Skill Database Loader
// Refactored from Class11

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using MuMaker.Core;
using MuMaker.Models;
using System;

namespace MuMaker.Data
{
    /// <summary>
    /// Loads skill data from the local MuMaker database
    /// </summary>
    [StandardModule]
    internal sealed class SkillDatabaseLoader
    {
        /// <summary>
        /// Load skill data by skill name
        /// </summary>
        /// <param name="skillName">Name of the skill to load</param>
        /// <returns>True on success</returns>
        public static object smethod_0(object skillName)
        {
            ConnectionManager.smethod_10();
            try
            {
                SqlConnectionPool.oleDbConnection_0.Open();
                SqlConnectionPool.oleDbCommand_0.Connection = SqlConnectionPool.oleDbConnection_0;
                SqlConnectionPool.oleDbCommand_0.CommandText = Conversions.ToString(
                    Operators.ConcatenateObject(
                        Operators.ConcatenateObject(
                            (object)"SELECT * FROM Skills WHERE NAME='", skillName),
                        (object)"';"));
                SqlConnectionPool.oleDbCommand_0.ExecuteNonQuery();
                SqlConnectionPool.oleDbDataReader_0 = SqlConnectionPool.oleDbCommand_0.ExecuteReader();
                SqlConnectionPool.oleDbDataReader_0.Read();

                SkillData.struct5_2.string_0 = Conversions.ToString(SqlConnectionPool.oleDbDataReader_0["Nº"]);
                SkillData.struct5_2.string_1 = Conversions.ToString(SqlConnectionPool.oleDbDataReader_0["ID"]);
                SkillData.struct5_2.string_3 = Conversions.ToString(SqlConnectionPool.oleDbDataReader_0["NAME"]);
                SkillData.struct5_2.string_4 = Conversions.ToString(SqlConnectionPool.oleDbDataReader_0["TIPO"]);
                SkillData.struct5_2.string_5 = Conversions.ToString(SqlConnectionPool.oleDbDataReader_0["Rango"]);
                SkillData.struct5_2.string_6 = Conversions.ToString(SqlConnectionPool.oleDbDataReader_0["Mana"]);
                SkillData.struct5_2.string_7 = Conversions.ToString(SqlConnectionPool.oleDbDataReader_0["Estamina"]);
            }
            catch (Exception ex)
            {
                ProjectData.SetProjectError(ex);
                int num = (int)Interaction.MsgBox((object)ex.Message, MsgBoxStyle.OkOnly, (object)null);
                ProjectData.ClearProjectError();
            }
            SqlConnectionPool.oleDbDataReader_0.Close();
            ConnectionManager.smethod_11();
            return (object)true;
        }

        /// <summary>
        /// Load skill data by skill ID and build tooltip text
        /// </summary>
        /// <returns>True on success</returns>
        public static object smethod_1()
        {
            ConnectionManager.smethod_10();
            SkillData.struct5_0.string_8 = "";
            try
            {
                SqlConnectionPool.oleDbConnection_0.Open();
                SqlConnectionPool.oleDbCommand_0.Connection = SqlConnectionPool.oleDbConnection_0;
                SqlConnectionPool.oleDbCommand_0.CommandText = "SELECT * FROM Skills WHERE ID=" +
                    Conversions.ToString(Conversion.Val("&H" + SkillData.struct5_0.string_1)) + ";";
                SqlConnectionPool.oleDbCommand_0.ExecuteNonQuery();
                SqlConnectionPool.oleDbDataReader_0 = SqlConnectionPool.oleDbCommand_0.ExecuteReader();

                if (SqlConnectionPool.oleDbDataReader_0.Read())
                {
                    if (Operators.CompareString(SkillData.struct5_0.string_2, "68", false) == 0)
                    {
                        SkillData.struct5_0.string_8 = " " +
                            Conversions.ToString(SqlConnectionPool.oleDbDataReader_0["NAME"]) + " (Pet/Item)\n " +
                            Conversions.ToString(SqlConnectionPool.oleDbDataReader_0["Tipo"]) + "\n Range : " +
                            Conversions.ToString(SqlConnectionPool.oleDbDataReader_0["Rango"]) + "\n Mana : " +
                            Conversions.ToString(SqlConnectionPool.oleDbDataReader_0["Mana"]) + "\n Stamina : " +
                            Conversions.ToString(SqlConnectionPool.oleDbDataReader_0["Estamina"]);
                    }
                    else
                    {
                        SkillData.struct5_0.string_8 = " " +
                            Conversions.ToString(SqlConnectionPool.oleDbDataReader_0["NAME"]) + " (Aprendida/Learned)\n " +
                            Conversions.ToString(SqlConnectionPool.oleDbDataReader_0["Tipo"]) + "\n Range : " +
                            Conversions.ToString(SqlConnectionPool.oleDbDataReader_0["Rango"]) + "\n Mana : " +
                            Conversions.ToString(SqlConnectionPool.oleDbDataReader_0["Mana"]) + "\n Stamina : " +
                            Conversions.ToString(SqlConnectionPool.oleDbDataReader_0["Estamina"]);
                    }
                    SkillData.struct5_0.string_0 = Conversions.ToString(SqlConnectionPool.oleDbDataReader_0["Nº"]);
                }
                else
                {
                    SkillData.struct5_0.string_8 = "Unknown Skill\n UPDATE Items.mdb";
                    SkillData.struct5_0.string_0 = "000000";
                }
            }
            catch (Exception ex)
            {
                ProjectData.SetProjectError(ex);
                int num = (int)Interaction.MsgBox((object)ex.Message, MsgBoxStyle.OkOnly, (object)null);
                ProjectData.ClearProjectError();
            }
            SqlConnectionPool.oleDbDataReader_0.Close();
            ConnectionManager.smethod_11();
            return (object)true;
        }
    }
}
