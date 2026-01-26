using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using System;
using System.Data.OleDb;
using System.Runtime.CompilerServices;

[StandardModule]
internal sealed class Class9
{
    public static object smethod_0()
    {
        Class24.struct4_0.int_1 = 0;
        return true;
    }

    public static object smethod_1(object object_0)
    {
        Class7.smethod_10();
        try
        {
            Class28.oleDbConnection_0.Open();
            Class28.oleDbCommand_0.Connection = Class28.oleDbConnection_0;
            Class28.oleDbCommand_0.CommandText = Conversions.ToString(Operators.ConcatenateObject(Operators.ConcatenateObject("SELECT * FROM Items WHERE NAME='", object_0), "';"));
            Class28.oleDbCommand_0.ExecuteNonQuery();
            Class28.oleDbDataReader_0 = Class28.oleDbCommand_0.ExecuteReader();
            Class28.oleDbDataReader_0.Read();
            Class24.struct4_2.string_0 = Conversions.ToString(Class28.oleDbDataReader_0["Nº"]);
            Class24.struct4_2.string_2 = Conversions.ToString(Class28.oleDbDataReader_0["ID"]);
            Class24.struct4_2.string_1 = Conversions.ToString(Class28.oleDbDataReader_0["TP"]);
            Class24.struct4_2.string_3 = Conversions.ToString(Class28.oleDbDataReader_0["NAME"]);
            Class24.struct4_2.string_4 = Conversions.ToString(Class28.oleDbDataReader_0["X"]);
            Class24.struct4_2.string_5 = Conversions.ToString(Class28.oleDbDataReader_0["Y"]);
            Class24.struct4_2.string_6 = Conversions.ToString(Class28.oleDbDataReader_0["Z"]);
            Class24.struct4_2.string_7 = Conversions.ToString(Class28.oleDbDataReader_0["DUR"]);
            Class24.struct4_2.string_9 = Conversions.ToString(Class28.oleDbDataReader_0["LVL"]);
            Class24.struct4_2.bool_0 = Conversions.ToBoolean(Conversions.ToString(Class28.oleDbDataReader_0["OP"]));
            Class24.struct4_2.bool_1 = Conversions.ToBoolean(Conversions.ToString(Class28.oleDbDataReader_0["LK"]));
            Class24.struct4_2.bool_2 = Conversions.ToBoolean(Conversions.ToString(Class28.oleDbDataReader_0["SK"]));
            Class24.struct4_2.bool_3 = Conversions.ToBoolean(Conversions.ToString(Class28.oleDbDataReader_0["ANC"]));
            Class24.struct4_2.int_0 = Conversions.ToInteger(Conversions.ToString(Class28.oleDbDataReader_0["EXE"]));
            Class24.struct4_2.int_2 = Conversions.ToInteger(Conversions.ToString(Class28.oleDbDataReader_0["RF"]));
            Class24.struct4_2.int_3 = Conversions.ToInteger(Conversions.ToString(Class28.oleDbDataReader_0["JH"]));
            Class24.struct4_2.bool_4 = Conversions.ToBoolean(Conversions.ToString(Class28.oleDbDataReader_0["Socket"]));
            Class24.struct4_2.int_5 = Conversions.ToInteger(Conversions.ToString(Class28.oleDbDataReader_0["SET"]));
            Class24.struct4_2.string_32 = Conversions.ToString(Class28.oleDbDataReader_0["SETItem1"]);
            Class24.struct4_2.string_33 = Conversions.ToString(Class28.oleDbDataReader_0["SETItem2"]);
        }
        catch (Exception exception)
        {
            ProjectData.SetProjectError(exception);
            Interaction.MsgBox(exception.Message, MsgBoxStyle.OkOnly, null);
            ProjectData.ClearProjectError();
        }
        Class28.oleDbDataReader_0.Close();
        Class7.smethod_11();
        return true;
    }

    public static object smethod_2(object object_0)
    {
        int num = 0;
        string[] string2;
        Class24.struct4_1.string_2 = Conversions.ToString(Conversion.Val(string.Concat("&H", Strings.Mid(Conversions.ToString(object_0), 1, 2))));
        Class24.struct4_1.string_1 = Conversions.ToString(Conversion.Val(string.Concat("&H", Strings.Mid(Conversions.ToString(object_0), 19, 1))));
        Class24.struct4_1.string_9 = Conversions.ToString(Class15.smethod_7(RuntimeHelpers.GetObjectValue(object_0)));
        Class24.struct4_1.string_10 = Strings.Mid(Conversions.ToString(Class15.smethod_7(RuntimeHelpers.GetObjectValue(object_0))), 2, 2);
        Class24.struct4_1.string_31 = Strings.Mid(Conversions.ToString(object_0), 7, 8);
        Class24.struct4_1.string_12 = Conversions.ToString(Class15.smethod_8(RuntimeHelpers.GetObjectValue(object_0)));
        Class24.struct4_1.string_13 = Conversions.ToString(Class15.smethod_10(RuntimeHelpers.GetObjectValue(object_0)));
        Class24.struct4_1.string_14 = Conversions.ToString(Class15.smethod_9(RuntimeHelpers.GetObjectValue(object_0)));
        Class24.struct4_1.string_16 = Conversions.ToString(Class15.smethod_4(RuntimeHelpers.GetObjectValue(object_0)));
        Class24.struct4_1.string_19 = Conversions.ToString(Class15.smethod_5(RuntimeHelpers.GetObjectValue(object_0)));
        Class24.struct4_1.string_15 = Strings.Mid(Conversions.ToString(object_0), 18, 1);
        if (Operators.CompareString(Class24.struct4_1.string_9, "+00", false) == 0)
        {
            Class24.struct4_1.string_9 = "";
        }
        Class7.smethod_10();
        try
        {
            Class28.oleDbConnection_0.Open();
            Class28.oleDbCommand_0.Connection = Class28.oleDbConnection_0;
            OleDbCommand oleDbCommand0 = Class28.oleDbCommand_0;
            string2 = new string[] { "SELECT Nº, NAME, LVL, X, Y, Z, EXE, RF, JH, SET, SetItem1, SetItem2 FROM Items WHERE ID=", Class24.struct4_1.string_2, " AND TP=", Class24.struct4_1.string_1, ";" };
            oleDbCommand0.CommandText = string.Concat(string2);
            Class28.oleDbCommand_0.ExecuteNonQuery();
            Class28.oleDbDataReader_0 = Class28.oleDbCommand_0.ExecuteReader();
            num = 0;
            while (Class28.oleDbDataReader_0.Read())
            {
                num++;
                Class24.struct4_1.string_0 = Conversions.ToString(Class28.oleDbDataReader_0["Nº"]);
                Class24.struct4_1.string_3 = Conversions.ToString(Class28.oleDbDataReader_0["NAME"]);
                Class24.struct4_1.string_11 = Conversions.ToString(Class28.oleDbDataReader_0["LVL"]);
                Class24.struct4_1.string_4 = Conversions.ToString(Class28.oleDbDataReader_0["X"]);
                Class24.struct4_1.string_5 = Conversions.ToString(Class28.oleDbDataReader_0["Y"]);
                Class24.struct4_1.string_6 = Conversions.ToString(Class28.oleDbDataReader_0["Z"]);
                Class24.struct4_1.int_0 = Conversions.ToInteger(Conversions.ToString(Class28.oleDbDataReader_0["EXE"]));
                Class24.struct4_1.int_2 = Conversions.ToInteger(Conversions.ToString(Class28.oleDbDataReader_0["RF"]));
                Class24.struct4_1.int_3 = Conversions.ToInteger(Conversions.ToString(Class28.oleDbDataReader_0["JH"]));
                Class24.struct4_1.int_5 = Conversions.ToInteger(Conversions.ToString(Class28.oleDbDataReader_0["SET"]));
                if (Class24.struct4_1.string_16.Length <= 1)
                {
                    Class24.struct4_1.string_32 = "";
                    Class24.struct4_1.string_33 = "";
                }
                else
                {
                    if (Operators.CompareString(Conversions.ToString(Class28.oleDbDataReader_0["SetItem1"]), "NO", false) == 0)
                    {
                        Class24.struct4_1.string_32 = "";
                    }
                    else
                    {
                        Class24.struct4_1.string_32 = string.Concat(Conversions.ToString(Class28.oleDbDataReader_0["SetItem1"]), " ");
                    }
                    if (Operators.CompareString(Conversions.ToString(Class28.oleDbDataReader_0["SetItem2"]), "NO", false) == 0)
                    {
                        Class24.struct4_1.string_33 = "";
                    }
                    else
                    {
                        Class24.struct4_1.string_33 = string.Concat(Conversions.ToString(Class28.oleDbDataReader_0["SetItem2"]), " ");
                    }
                }
            }
            Class28.oleDbDataReader_0.Close();
        }
        catch (Exception exception)
        {
            ProjectData.SetProjectError(exception);
            Interaction.MsgBox(exception.Message, MsgBoxStyle.OkOnly, null);
            ProjectData.ClearProjectError();
        }
        Class7.smethod_11();
        if (num > 1)
        {
            Class7.smethod_10();
            try
            {
                Class28.oleDbConnection_0.Open();
                Class28.oleDbCommand_0.Connection = Class28.oleDbConnection_0;
                OleDbCommand oleDbCommand = Class28.oleDbCommand_0;
                string2 = new string[] { "SELECT Nº, NAME, LVL FROM Items WHERE ID=", Class24.struct4_1.string_2, " AND TP=", Class24.struct4_1.string_1, " AND LVL='", Class24.struct4_1.string_10, "';" };
                oleDbCommand.CommandText = string.Concat(string2);
                Class28.oleDbCommand_0.ExecuteNonQuery();
                Class28.oleDbDataReader_0 = Class28.oleDbCommand_0.ExecuteReader();
                Class28.oleDbDataReader_0.Read();
                Class24.struct4_1.string_0 = Conversions.ToString(Class28.oleDbDataReader_0["Nº"]);
                Class24.struct4_1.string_3 = Conversions.ToString(Class28.oleDbDataReader_0["NAME"]);
                Class24.struct4_1.string_11 = Conversions.ToString(Class28.oleDbDataReader_0["LVL"]);
                Class28.oleDbDataReader_0.Close();
            }
            catch (Exception exception1)
            {
                ProjectData.SetProjectError(exception1);
                Class24.struct4_1.string_3 = "Unknown Item\n UPDATE Items.mdb";
                ProjectData.ClearProjectError();
            }
            Class7.smethod_11();
        }
        if (Operators.CompareString(Class24.struct4_1.string_11, "NO", false) != 0)
        {
            Class24.struct4_1.string_9 = "";
        }
        Class24.struct4_1.string_20 = Conversions.ToString(Class15.smethod_6(RuntimeHelpers.GetObjectValue(object_0)));
        Class24.struct4_1.string_22 = Conversions.ToString(Class15.smethod_12(RuntimeHelpers.GetObjectValue(object_0)));
        Class24.struct4_1.string_21 = Conversions.ToString(Class15.smethod_11(RuntimeHelpers.GetObjectValue(object_0)));
        Class24.struct4_1.string_30 = Conversions.ToString(Class15.smethod_13(RuntimeHelpers.GetObjectValue(object_0)));
        return true;
    }
}