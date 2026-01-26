// Decompiled with JetBrains decompiler
// Type: Class13
// Assembly: MuMaker, Version=1.1.3.0, Culture=neutral, PublicKeyToken=null
// MVID: 7E43A6C6-04AF-4159-BD3A-BD25660D1460
// Assembly location: D:\MuServer\Tools\MuMaker 1.13\MuMaker-cleaned.exe

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using System;
using System.Data;

[StandardModule]
internal sealed class Class13
{
  public static object smethod_0(object object_0, object object_1, object object_2, object object_3, object object_4, object object_5, object object_6, object object_7, object object_8, object object_9, object object_10, object object_11, object object_12, object object_13, object object_14)
  {
    Class7.smethod_4();
    try
    {
      Class28.sqlConnection_5.Open();
      Class28.sqlCommand_5.Connection = Class28.sqlConnection_5;
      Class28.sqlCommand_5.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "INSERT INTO MuMakerFinderMaker (AC, PJ, Vault, Invent, ExtraW, NumExtraW, Pos, Item, Serial, FullEXE, ExeAnc, Full380, FullJoH, FullSck, CodeItems) VALUES ('", object_0), (object) "','"), object_1), (object) "','"), object_2), (object) "','"), object_3), (object) "','"), object_4), (object) "','"), object_5), (object) "','"), object_6), (object) "','"), object_7), (object) "','"), object_8), (object) "','"), object_9), (object) "','"), object_10), (object) "','"), object_11), (object) "','"), object_12), (object) "','"), object_13), (object) "','"), object_14), (object) "');"));
      Class28.sqlCommand_5.ExecuteReader();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_9();
    return (object) true;
  }

  public static object smethod_1()
  {
    try
    {
      Class7.smethod_0();
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "SELECT memb___id FROM MEMB_INFO ORDER BY memb___id ASC";
      Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
      Class29.int_1 = 0;
      while (Class28.sqlDataReader_1.Read())
        checked { ++Class29.int_1; }
      Class28.sqlDataReader_1.Close();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    if (Class28.sqlConnection_1.State == ConnectionState.Open)
      Class28.sqlConnection_1.Close();
    return (object) true;
  }

  public static object smethod_2(object object_0)
  {
    return !(Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(object_0), 15, 2), "3F", false) == 0 | Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(object_0), 15, 2), "7F", false) == 0) ? (object) "0" : (object) "1";
  }

  public static object smethod_3(object object_0)
  {
    return Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(object_0), 20, 1), "8", false) != 0 ? (object) "0" : (object) "1";
  }

  public static object smethod_4(object object_0)
  {
    return Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(object_0), 22, 1), "F", false) != 0 ? (object) "0" : (object) "1";
  }

  public static object smethod_5(object object_0)
  {
    string str1 = Conversions.ToString(0);
    string str2 = Conversions.ToString(Conversion.Val("&H" + Strings.Mid(Conversions.ToString(object_0), 15, 2)));
    if (Conversions.ToDouble(str2) >= 128.0)
      str2 = Conversions.ToString(Conversions.ToDouble(str2) - 128.0);
    if (Conversions.ToDouble(str2) >= 64.0)
      str2 = Conversions.ToString(Conversions.ToDouble(str2) - 64.0);
    if (Conversions.ToDouble(str2) >= 32.0)
    {
      str2 = Conversions.ToString(Conversions.ToDouble(str2) - 32.0);
      str1 = Conversions.ToString(1);
    }
    if (Conversions.ToDouble(str2) >= 16.0)
    {
      str2 = Conversions.ToString(Conversions.ToDouble(str2) - 16.0);
      str1 = Conversions.ToString(1);
    }
    if (Conversions.ToDouble(str2) >= 8.0)
    {
      str2 = Conversions.ToString(Conversions.ToDouble(str2) - 8.0);
      str1 = Conversions.ToString(1);
    }
    if (Conversions.ToDouble(str2) >= 4.0)
    {
      str2 = Conversions.ToString(Conversions.ToDouble(str2) - 4.0);
      str1 = Conversions.ToString(1);
    }
    if (Conversions.ToDouble(str2) >= 2.0)
    {
      str2 = Conversions.ToString(Conversions.ToDouble(str2) - 2.0);
      str1 = Conversions.ToString(1);
    }
    if (Conversions.ToDouble(str2) > 0.0)
      str1 = Conversions.ToString(1);
    return !(Conversions.ToDouble(str1) == 1.0 & (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(object_0), 18, 1), "5", false) == 0 | Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(object_0), 18, 1), "9", false) == 0)) ? (object) "0" : (object) "1";
  }

  public static object smethod_6(object object_0)
  {
    return Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(object_0), 23, 2), "00", false) == 0 ? (object) "0" : (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(object_0), 25, 2), "00", false) == 0 ? (object) "0" : (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(object_0), 27, 2), "00", false) == 0 ? (object) "0" : (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(object_0), 29, 2), "00", false) == 0 ? (object) "0" : (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(object_0), 31, 2), "00", false) == 0 ? (object) "0" : (object) "1"))));
  }
}
