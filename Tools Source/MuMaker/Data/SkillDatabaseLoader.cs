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
        public static object LoadSkillByName(object skillName)
        {
            ConnectionManager.OpenLocalDatabase();
            try
            {
                SqlConnectionPool.LocalDbConnection.Open();
                SqlConnectionPool.LocalDbCommand.Connection = SqlConnectionPool.LocalDbConnection;
                SqlConnectionPool.LocalDbCommand.CommandText = Conversions.ToString(
                    Operators.ConcatenateObject(
                        Operators.ConcatenateObject(
                            (object)"SELECT * FROM Skills WHERE NAME='", skillName),
                        (object)"';"));
                SqlConnectionPool.LocalDbCommand.ExecuteNonQuery();
                SqlConnectionPool.LocalDbReader = SqlConnectionPool.LocalDbCommand.ExecuteReader();
                SqlConnectionPool.LocalDbReader.Read();

                SkillData.SelectedSkill.SkillNumber = Conversions.ToString(SqlConnectionPool.LocalDbReader["Nº"]);
                SkillData.SelectedSkill.SkillId = Conversions.ToString(SqlConnectionPool.LocalDbReader["ID"]);
                SkillData.SelectedSkill.Name = Conversions.ToString(SqlConnectionPool.LocalDbReader["NAME"]);
                SkillData.SelectedSkill.Type = Conversions.ToString(SqlConnectionPool.LocalDbReader["TIPO"]);
                SkillData.SelectedSkill.Range = Conversions.ToString(SqlConnectionPool.LocalDbReader["Rango"]);
                SkillData.SelectedSkill.ManaCost = Conversions.ToString(SqlConnectionPool.LocalDbReader["Mana"]);
                SkillData.SelectedSkill.StaminaCost = Conversions.ToString(SqlConnectionPool.LocalDbReader["Estamina"]);
            }
            catch (Exception ex)
            {
                ProjectData.SetProjectError(ex);
                int num = (int)Interaction.MsgBox((object)ex.Message, MsgBoxStyle.OkOnly, (object)null);
                ProjectData.ClearProjectError();
            }
            SqlConnectionPool.LocalDbReader.Close();
            ConnectionManager.CloseLocalDatabase();
            return (object)true;
        }

        /// <summary>
        /// Load skill data by skill ID and build tooltip text
        /// </summary>
        /// <returns>True on success</returns>
        public static object LoadSkillById()
        {
            ConnectionManager.OpenLocalDatabase();
            SkillData.CurrentSkill.TooltipText = "";
            try
            {
                SqlConnectionPool.LocalDbConnection.Open();
                SqlConnectionPool.LocalDbCommand.Connection = SqlConnectionPool.LocalDbConnection;
                SqlConnectionPool.LocalDbCommand.CommandText = "SELECT * FROM Skills WHERE ID=" +
                    Conversions.ToString(Conversion.Val("&H" + SkillData.CurrentSkill.SkillId)) + ";";
                SqlConnectionPool.LocalDbCommand.ExecuteNonQuery();
                SqlConnectionPool.LocalDbReader = SqlConnectionPool.LocalDbCommand.ExecuteReader();

                if (SqlConnectionPool.LocalDbReader.Read())
                {
                    string skillSource;
                    if (Operators.CompareString(SkillData.CurrentSkill.SkillTypeCode, "68", false) == 0)
                    {
                        skillSource = "(Pet/Item)";
                    }
                    else
                    {
                        skillSource = "(Aprendida/Learned)";
                    }

                    SkillData.CurrentSkill.TooltipText = " " +
                        Conversions.ToString(SqlConnectionPool.LocalDbReader["NAME"]) + " " + skillSource + "\n " +
                        Conversions.ToString(SqlConnectionPool.LocalDbReader["Tipo"]) + "\n Range : " +
                        Conversions.ToString(SqlConnectionPool.LocalDbReader["Rango"]) + "\n Mana : " +
                        Conversions.ToString(SqlConnectionPool.LocalDbReader["Mana"]) + "\n Stamina : " +
                        Conversions.ToString(SqlConnectionPool.LocalDbReader["Estamina"]);

                    SkillData.CurrentSkill.SkillNumber = Conversions.ToString(SqlConnectionPool.LocalDbReader["Nº"]);
                }
                else
                {
                    SkillData.CurrentSkill.TooltipText = "Unknown Skill\n UPDATE Items.mdb";
                    SkillData.CurrentSkill.SkillNumber = "000000";
                }
            }
            catch (Exception ex)
            {
                ProjectData.SetProjectError(ex);
                int num = (int)Interaction.MsgBox((object)ex.Message, MsgBoxStyle.OkOnly, (object)null);
                ProjectData.ClearProjectError();
            }
            SqlConnectionPool.LocalDbReader.Close();
            ConnectionManager.CloseLocalDatabase();
            return (object)true;
        }
    }
}
