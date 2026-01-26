// Decompiled with JetBrains decompiler
// Type: Class11
// Assembly: MuMaker, Version=1.1.3.0, Culture=neutral, PublicKeyToken=null
// MVID: 7E43A6C6-04AF-4159-BD3A-BD25660D1460
// Assembly location: D:\MuServer\Tools\MuMaker 1.13\MuMaker-cleaned.exe

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using System;

[StandardModule]
internal sealed class Class11
{
  public static object smethod_0(object object_0)
  {
    Class7.smethod_10();
    try
    {
      Class28.oleDbConnection_0.Open();
      Class28.oleDbCommand_0.Connection = Class28.oleDbConnection_0;
      Class28.oleDbCommand_0.CommandText = Conversions.ToString(Operators.ConcatenateObject(Operators.ConcatenateObject((object) "SELECT * FROM Skills WHERE NAME='", object_0), (object) "';"));
      Class28.oleDbCommand_0.ExecuteNonQuery();
      Class28.oleDbDataReader_0 = Class28.oleDbCommand_0.ExecuteReader();
      Class28.oleDbDataReader_0.Read();
      Class25.struct5_2.string_0 = Conversions.ToString(Class28.oleDbDataReader_0["Nº"]);
      Class25.struct5_2.string_1 = Conversions.ToString(Class28.oleDbDataReader_0["ID"]);
      Class25.struct5_2.string_3 = Conversions.ToString(Class28.oleDbDataReader_0["NAME"]);
      Class25.struct5_2.string_4 = Conversions.ToString(Class28.oleDbDataReader_0["TIPO"]);
      Class25.struct5_2.string_5 = Conversions.ToString(Class28.oleDbDataReader_0["Rango"]);
      Class25.struct5_2.string_6 = Conversions.ToString(Class28.oleDbDataReader_0["Mana"]);
      Class25.struct5_2.string_7 = Conversions.ToString(Class28.oleDbDataReader_0["Estamina"]);
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class28.oleDbDataReader_0.Close();
    Class7.smethod_11();
    return (object) true;
  }

  public static object smethod_1()
  {
    Class7.smethod_10();
    Class25.struct5_0.string_8 = "";
    try
    {
      Class28.oleDbConnection_0.Open();
      Class28.oleDbCommand_0.Connection = Class28.oleDbConnection_0;
      Class28.oleDbCommand_0.CommandText = "SELECT * FROM Skills WHERE ID=" + Conversions.ToString(Conversion.Val("&H" + Class25.struct5_0.string_1)) + ";";
      Class28.oleDbCommand_0.ExecuteNonQuery();
      Class28.oleDbDataReader_0 = Class28.oleDbCommand_0.ExecuteReader();
      if (Class28.oleDbDataReader_0.Read())
      {
        if (Operators.CompareString(Class25.struct5_0.string_2, "68", false) == 0)
          Class25.struct5_0.string_8 = " " + Conversions.ToString(Class28.oleDbDataReader_0["NAME"]) + " (Pet/Item)\n " + Conversions.ToString(Class28.oleDbDataReader_0["Tipo"]) + "\n Range : " + Conversions.ToString(Class28.oleDbDataReader_0["Rango"]) + "\n Mana : " + Conversions.ToString(Class28.oleDbDataReader_0["Mana"]) + "\n Stamina : " + Conversions.ToString(Class28.oleDbDataReader_0["Estamina"]);
        else
          Class25.struct5_0.string_8 = " " + Conversions.ToString(Class28.oleDbDataReader_0["NAME"]) + " (Aprendida/Learned)\n " + Conversions.ToString(Class28.oleDbDataReader_0["Tipo"]) + "\n Range : " + Conversions.ToString(Class28.oleDbDataReader_0["Rango"]) + "\n Mana : " + Conversions.ToString(Class28.oleDbDataReader_0["Mana"]) + "\n Stamina : " + Conversions.ToString(Class28.oleDbDataReader_0["Estamina"]);
        Class25.struct5_0.string_0 = Conversions.ToString(Class28.oleDbDataReader_0["Nº"]);
      }
      else
      {
        Class25.struct5_0.string_8 = "Unknown Skill\n UPDATE Items.mdb";
        Class25.struct5_0.string_0 = "000000";
      }
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class28.oleDbDataReader_0.Close();
    Class7.smethod_11();
    return (object) true;
  }
}
