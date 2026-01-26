// Decompiled with JetBrains decompiler
// Type: Class12
// Assembly: MuMaker, Version=1.1.3.0, Culture=neutral, PublicKeyToken=null
// MVID: 7E43A6C6-04AF-4159-BD3A-BD25660D1460
// Assembly location: D:\MuServer\Tools\MuMaker 1.13\MuMaker-cleaned.exe

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using System;

[StandardModule]
internal sealed class Class12
{
  public static void smethod_0()
  {
    Class7.smethod_0();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "SELECT ConnectStat FROM MEMB_STAT WHERE memb___id='" + Class22.struct0_0.string_1 + "'";
      Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
      Class22.struct0_0.bool_0 = Class28.sqlDataReader_1.Read() && Conversions.ToDouble(Class28.sqlDataReader_1[0].ToString()) == 1.0;
      Class28.sqlDataReader_1.Close();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
  }

  public static object smethod_1()
  {
    Class7.smethod_0();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "UPDATE MEMB_STAT SET ConnectStat=0 WHERE memb___id='" + Class22.struct0_0.string_1 + "'";
      Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
      Class28.sqlDataReader_1.Close();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    return (object) true;
  }

  public static object smethod_2(object object_0, object object_1)
  {
    if (Operators.ConditionalCompareObjectEqual(object_0, (object) "Baned", false))
    {
      Class7.smethod_0();
      try
      {
        Class28.sqlConnection_1.Open();
        Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
        Class28.sqlCommand_1.CommandText = Conversions.ToString(Operators.ConcatenateObject(Operators.ConcatenateObject((object) "UPDATE Character SET CtlCode=0 WHERE AccountID='", object_1), (object) "'"));
        Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
        Class28.sqlDataReader_1.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      Class7.smethod_5();
    }
    else
    {
      try
      {
        Class28.sqlConnection_1.Open();
        Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
        Class28.sqlCommand_1.CommandText = Conversions.ToString(Operators.ConcatenateObject(Operators.ConcatenateObject((object) "UPDATE Character SET CtlCode=1 WHERE AccountID='", object_1), (object) "'"));
        Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
        Class28.sqlDataReader_1.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      Class7.smethod_5();
    }
    return (object) true;
  }
}
