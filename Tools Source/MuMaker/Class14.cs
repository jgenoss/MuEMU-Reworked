// Decompiled with JetBrains decompiler
// Type: Class14
// Assembly: MuMaker, Version=1.1.3.0, Culture=neutral, PublicKeyToken=null
// MVID: 7E43A6C6-04AF-4159-BD3A-BD25660D1460
// Assembly location: D:\MuServer\Tools\MuMaker 1.13\MuMaker-cleaned.exe

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using System;

[StandardModule]
internal sealed class Class14
{
  public static object smethod_0()
  {
    Class7.smethod_0();
    int num1;
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "SELECT Number FROM Guild WHERE G_Name='" + Class23.struct3_0.string_7 + "'";
      Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
      Class28.sqlDataReader_1.Read();
      num1 = Conversions.ToInteger(Class28.sqlDataReader_1["Number"].ToString());
      Class28.sqlDataReader_1.Close();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      num1 = 0;
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "UPDATE Guild SET G_Union=" + Conversions.ToString(num1) + " WHERE G_Name = '" + Class23.struct3_0.string_1 + "'";
      Class28.sqlCommand_1.ExecuteReader();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num2 = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    int num3;
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "SELECT Number FROM Guild WHERE G_Name='" + Class23.struct3_0.string_1 + "'";
      Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
      Class28.sqlDataReader_1.Read();
      num3 = Conversions.ToInteger(Class28.sqlDataReader_1["Number"].ToString());
      Class28.sqlDataReader_1.Close();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      num3 = 0;
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "UPDATE Guild SET G_Union=" + Conversions.ToString(num3) + " WHERE G_Name = '" + Class23.struct3_0.string_7 + "'";
      Class28.sqlCommand_1.ExecuteReader();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num2 = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    return (object) true;
  }

  public static object smethod_1()
  {
    Class7.smethod_0();
    int num1;
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "SELECT Number FROM Guild WHERE G_Name='" + Class23.struct3_0.string_8 + "'";
      Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
      Class28.sqlDataReader_1.Read();
      num1 = Conversions.ToInteger(Class28.sqlDataReader_1["Number"].ToString());
      Class28.sqlDataReader_1.Close();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      num1 = 0;
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "UPDATE Guild SET G_Rival=" + Conversions.ToString(num1) + " WHERE G_Name = '" + Class23.struct3_0.string_1 + "'";
      Class28.sqlCommand_1.ExecuteReader();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num2 = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    int num3;
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "SELECT Number FROM Guild WHERE G_Name='" + Class23.struct3_0.string_1 + "'";
      Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
      Class28.sqlDataReader_1.Read();
      num3 = Conversions.ToInteger(Class28.sqlDataReader_1["Number"].ToString());
      Class28.sqlDataReader_1.Close();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      num3 = 0;
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "UPDATE Guild SET G_Rival=" + Conversions.ToString(num3) + " WHERE G_Name = '" + Class23.struct3_0.string_8 + "'";
      Class28.sqlCommand_1.ExecuteReader();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num2 = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    return (object) true;
  }
}
