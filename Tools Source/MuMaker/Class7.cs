// Decompiled with JetBrains decompiler
// Type: Class7
// Assembly: MuMaker, Version=1.1.3.0, Culture=neutral, PublicKeyToken=null
// MVID: 7E43A6C6-04AF-4159-BD3A-BD25660D1460
// Assembly location: D:\MuServer\Tools\MuMaker 1.13\MuMaker-cleaned.exe

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using System.Data;
using System.Data.OleDb;
using System.Data.SqlClient;

[StandardModule]
internal sealed class Class7
{
  public static object smethod_0()
  {
    object Left = Class26.object_4;
    if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Left, (object) "Local", false))
      Class28.sqlConnection_1 = new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    else if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Left, (object) "Remote", false))
    {
      Class28.sqlConnection_1 = new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    }
    else
    {
      int num = (int) Interaction.MsgBox((object) "BAD Type Connection: Using Local Connection", MsgBoxStyle.OkOnly, (object) null);
      Class28.sqlConnection_1 = new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    }
    Class28.sqlCommand_1 = new SqlCommand();
    Class28.sqlCommand_1.CommandTimeout = Class26.int_0;
    return (object) true;
  }

  public static object smethod_1()
  {
    object Left = Class26.object_4;
    if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Left, (object) "Local", false))
      Class28.sqlConnection_2 = new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    else if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Left, (object) "Remote", false))
    {
      Class28.sqlConnection_2 = new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    }
    else
    {
      int num = (int) Interaction.MsgBox((object) "BAD Type Connection: Using Local Connection", MsgBoxStyle.OkOnly, (object) null);
      Class28.sqlConnection_2 = new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    }
    Class28.sqlCommand_2 = new SqlCommand();
    Class28.sqlCommand_2.CommandTimeout = Class26.int_0;
    return (object) true;
  }

  public static object smethod_2()
  {
    object Left = Class26.object_4;
    if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Left, (object) "Local", false))
      Class28.sqlConnection_3 = new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    else if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Left, (object) "Remote", false))
    {
      Class28.sqlConnection_3 = new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    }
    else
    {
      int num = (int) Interaction.MsgBox((object) "BAD Type Connection: Using Local Connection", MsgBoxStyle.OkOnly, (object) null);
      Class28.sqlConnection_3 = new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    }
    Class28.sqlCommand_3 = new SqlCommand();
    Class28.sqlCommand_3.CommandTimeout = Class26.int_0;
    return (object) true;
  }

  public static object smethod_3()
  {
    object Left = Class26.object_4;
    if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Left, (object) "Local", false))
      Class28.sqlConnection_4 = new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    else if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Left, (object) "Remote", false))
    {
      Class28.sqlConnection_4 = new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    }
    else
    {
      int num = (int) Interaction.MsgBox((object) "BAD Type Connection: Using Local Connection", MsgBoxStyle.OkOnly, (object) null);
      Class28.sqlConnection_4 = new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    }
    Class28.sqlCommand_4 = new SqlCommand();
    Class28.sqlCommand_4.CommandTimeout = Class26.int_0;
    return (object) true;
  }

  public static object smethod_4()
  {
    object Left = Class26.object_4;
    if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Left, (object) "Local", false))
      Class28.sqlConnection_5 = new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    else if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Left, (object) "Remote", false))
    {
      Class28.sqlConnection_5 = new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    }
    else
    {
      int num = (int) Interaction.MsgBox((object) "BAD Type Connection: Using Local Connection", MsgBoxStyle.OkOnly, (object) null);
      Class28.sqlConnection_5 = new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    }
    Class28.sqlCommand_5 = new SqlCommand();
    Class28.sqlCommand_5.CommandTimeout = Class26.int_0;
    return (object) true;
  }

  public static object smethod_5()
  {
    if (Class28.sqlConnection_1.State == ConnectionState.Open)
      Class28.sqlConnection_1.Close();
    return (object) true;
  }

  public static object smethod_6()
  {
    if (Class28.sqlConnection_2.State == ConnectionState.Open)
      Class28.sqlConnection_2.Close();
    return (object) true;
  }

  public static object smethod_7()
  {
    if (Class28.sqlConnection_3.State == ConnectionState.Open)
      Class28.sqlConnection_3.Close();
    return (object) true;
  }

  public static object smethod_8()
  {
    if (Class28.sqlConnection_4.State == ConnectionState.Open)
      Class28.sqlConnection_4.Close();
    return (object) true;
  }

  public static object smethod_9()
  {
    if (Class28.sqlConnection_5.State == ConnectionState.Open)
      Class28.sqlConnection_5.Close();
    return (object) true;
  }

  public static object smethod_10()
  {
    Class28.oleDbConnection_0 = new OleDbConnection();
    Class28.oleDbConnection_0.ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=MuMaker.mdb;";
    Class28.oleDbCommand_0 = new OleDbCommand();
    Class28.oleDbCommand_0.CommandTimeout = Class28.int_1;
    return (object) true;
  }

  public static object smethod_11()
  {
    if (Class28.oleDbConnection_0.State == ConnectionState.Open)
      Class28.oleDbConnection_0.Close();
    return (object) true;
  }
}
