// Decompiled with JetBrains decompiler
// Type: Class20
// Assembly: MuMaker, Version=1.1.3.0, Culture=neutral, PublicKeyToken=null
// MVID: 7E43A6C6-04AF-4159-BD3A-BD25660D1460
// Assembly location: D:\MuServer\Tools\MuMaker 1.13\MuMaker-cleaned.exe

using Microsoft.VisualBasic.CompilerServices;
using System;
using System.Data;
using System.Data.SqlClient;

[StandardModule]
internal sealed class Class20
{
  public static object smethod_0()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_ItemMakerWareHous') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_ItemMakerWareHous'), 'IsProcedure')= 1 select object_id('"), Class26.object_7), (object) "..MMK_ItemMakerWareHous') else return end else return")), Class28.sqlConnection_0);
    try
    {
      SqlCommand sqlCommand1 = Class28.sqlCommand_0;
      sqlCommand1.CommandType = CommandType.Text;
      sqlCommand1.Connection.Open();
      Class28.sqlDataReader_0 = sqlCommand1.ExecuteReader();
      if (!Class28.sqlDataReader_0.Read())
      {
        sqlCommand1.CommandText = "CREATE PROCEDURE MMK_ItemMakerWareHous (@AccountID VARCHAR(10))\nAS\nUPDATE warehouse\nSET Items=0x00000000000000000000\nWHERE AccountID=@AccountID";
        Class28.sqlDataReader_0.Close();
        sqlCommand1.ExecuteNonQuery();
      }
      else
        Class28.sqlDataReader_0.Close();
      sqlCommand1.Dispose();
      Class28.sqlConnection_0.Close();
      Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_ItemMakerInventory') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_ItemMakerInventory'), 'IsProcedure')= 1 select object_id('"), Class26.object_7), (object) "..MMK_ItemMakerInventory') else return end else return")), Class28.sqlConnection_0);
      SqlCommand sqlCommand2 = Class28.sqlCommand_0;
      sqlCommand2.CommandType = CommandType.Text;
      sqlCommand2.Connection.Open();
      Class28.sqlDataReader_0 = sqlCommand2.ExecuteReader();
      if (!Class28.sqlDataReader_0.Read())
      {
        sqlCommand2.CommandText = "CREATE PROCEDURE MMK_ItemMakerInventory (@AccountID VARCHAR(10), @Name VARCHAR(10))\nAS\nUPDATE Character\nSET Inventory=0x00000000000000000000\nWHERE AccountID=@AccountID AND Name=@Name";
        Class28.sqlDataReader_0.Close();
        sqlCommand2.ExecuteNonQuery();
      }
      else
        Class28.sqlDataReader_0.Close();
      sqlCommand2.Dispose();
      Class28.sqlConnection_0.Close();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      ProjectData.ClearProjectError();
    }
    return (object) true;
  }

  public static object smethod_1()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_SkillMaker') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_SkillMaker'), 'IsProcedure')= 1 select object_id('"), Class26.object_7), (object) "..MMK_SkillMaker') else return end else return")), Class28.sqlConnection_0);
    try
    {
      SqlCommand sqlCommand = Class28.sqlCommand_0;
      sqlCommand.CommandType = CommandType.Text;
      sqlCommand.Connection.Open();
      Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
      if (!Class28.sqlDataReader_0.Read())
      {
        sqlCommand.CommandText = "CREATE PROCEDURE MMK_SkillMaker (@AccountID VARCHAR(10), @Name VARCHAR(10))\nAS\nUPDATE Character\nSET MagicList=0xFF0000\nWHERE AccountID=@AccountID AND Name=@Name";
        Class28.sqlDataReader_0.Close();
        sqlCommand.ExecuteNonQuery();
      }
      else
        Class28.sqlDataReader_0.Close();
      sqlCommand.Dispose();
      Class28.sqlConnection_0.Close();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      ProjectData.ClearProjectError();
    }
    return (object) true;
  }

  public static object smethod_2()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_QuestMaker') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_QuestMaker'), 'IsProcedure')= 1 select object_id('"), Class26.object_7), (object) "..MMK_QuestMaker') else return end else return")), Class28.sqlConnection_0);
    object obj;
    try
    {
      SqlCommand sqlCommand = Class28.sqlCommand_0;
      sqlCommand.CommandType = CommandType.Text;
      sqlCommand.Connection.Open();
      Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
      if (!Class28.sqlDataReader_0.Read())
      {
        sqlCommand.CommandText = "CREATE PROCEDURE MMK_QuestMaker (@AccountID VARCHAR(10), @Name VARCHAR(10))\nAS\nUPDATE Character\nSET Quest=0xFFFFFF\nWHERE AccountID=@AccountID AND Name=@Name";
        Class28.sqlDataReader_0.Close();
        sqlCommand.ExecuteNonQuery();
      }
      else
        Class28.sqlDataReader_0.Close();
      sqlCommand.Dispose();
      Class28.sqlConnection_0.Close();
      goto label_7;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_7:
    return (object) true;
  }

  public static object smethod_3()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_GuildMaker') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_GuildMaker'), 'IsProcedure')= 1 select object_id('"), Class26.object_7), (object) "..MMK_GuildMaker') else return end else return")), Class28.sqlConnection_0);
    object obj;
    try
    {
      SqlCommand sqlCommand = Class28.sqlCommand_0;
      sqlCommand.CommandType = CommandType.Text;
      sqlCommand.Connection.Open();
      Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
      if (!Class28.sqlDataReader_0.Read())
      {
        sqlCommand.CommandText = "CREATE PROCEDURE MMK_GuildMaker (@Name VARCHAR(8))\nAS\nUPDATE Guild\nSET G_Mark=0x0000000000000000000000000000000000000000000000000000000000000000\nWHERE G_Name=@Name";
        Class28.sqlDataReader_0.Close();
        sqlCommand.ExecuteNonQuery();
      }
      else
        Class28.sqlDataReader_0.Close();
      sqlCommand.Dispose();
      Class28.sqlConnection_0.Close();
      goto label_7;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_7:
    return (object) true;
  }

  public static object smethod_4()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_ItemMakerWareHous') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_ItemMakerWareHous'), 'IsProcedure')= 1 select object_id('"), Class26.object_7), (object) "..MMK_ItemMakerWareHous') else return end else return")), Class28.sqlConnection_0);
    object obj = (object) "0x";
    int num1 = 1;
    int num2 = Class32.int_0;
    int num3 = num1;
    while (num3 <= num2)
    {
      obj = Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(obj, (object) "F");
      checked { ++num3; }
    }
    SqlCommand sqlCommand = Class28.sqlCommand_0;
    sqlCommand.CommandType = CommandType.Text;
    sqlCommand.Connection.Open();
    Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
    if (Class28.sqlDataReader_0.Read())
    {
      sqlCommand.CommandText = Class22.struct2_0.int_0 != 0 ? Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "ALTER PROCEDURE MMK_ItemMakerWareHous (@AccountID VARCHAR(10))\nAS\nINSERT INTO ", Class26.object_10), (object) " (AccountID, Number, Items, Money, pw) VALUES (@AccountID, "), (object) Class22.struct2_0.int_0), (object) ", "), obj), (object) ", 0, 0)")) : Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "ALTER PROCEDURE MMK_ItemMakerWareHous (@AccountID VARCHAR(10))\nAS\nINSERT INTO warehouse (AccountID, Items, Money) VALUES (@AccountID, ", obj), (object) ", 0)"));
      Class28.sqlDataReader_0.Close();
      sqlCommand.ExecuteNonQuery();
    }
    else
      Class28.sqlDataReader_0.Close();
    sqlCommand.Dispose();
    Class28.sqlConnection_0.Close();
    return (object) true;
  }

  public static object smethod_5()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_ItemMakerInventory') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_ItemMakerInventory'), 'IsProcedure')= 1 select object_id('"), Class26.object_7), (object) "..MMK_ItemMakerInventory') else return end else return")), Class28.sqlConnection_0);
    object obj = (object) "0x";
    int num1 = 1;
    int num2 = Class32.int_3;
    int num3 = num1;
    while (num3 <= num2)
    {
      obj = Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(obj, (object) "F");
      checked { ++num3; }
    }
    SqlCommand sqlCommand = Class28.sqlCommand_0;
    sqlCommand.CommandType = CommandType.Text;
    sqlCommand.Connection.Open();
    Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
    if (Class28.sqlDataReader_0.Read())
    {
      sqlCommand.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "ALTER PROCEDURE MMK_ItemMakerInventory (@AccountID VARCHAR(10), @Name VARCHAR(10))\nAS\nUPDATE Character\nSET Inventory=", obj), (object) '\n'), (object) "WHERE AccountID=@AccountID AND Name=@Name"));
      Class28.sqlDataReader_0.Close();
      sqlCommand.ExecuteNonQuery();
    }
    else
      Class28.sqlDataReader_0.Close();
    sqlCommand.Dispose();
    Class28.sqlConnection_0.Close();
    return (object) true;
  }

  public static object smethod_6()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_ItemMakerWareHous') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_ItemMakerWareHous'), 'IsProcedure')= 1 select object_id('"), Class26.object_7), (object) "..MMK_ItemMakerWareHous') else return end else return")), Class28.sqlConnection_0);
    object obj = (object) "0x";
    int num1 = 1;
    int num2 = Class32.int_0;
    int num3 = num1;
    while (num3 <= num2)
    {
      obj = Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(obj, (object) "F");
      checked { ++num3; }
    }
    SqlCommand sqlCommand = Class28.sqlCommand_0;
    sqlCommand.CommandType = CommandType.Text;
    sqlCommand.Connection.Open();
    Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
    if (Class28.sqlDataReader_0.Read())
    {
      sqlCommand.CommandText = Class22.struct2_0.int_0 != 0 ? Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "ALTER PROCEDURE MMK_ItemMakerWareHous (@AccountID VARCHAR(10))\nAS\nUPDATE ", Class26.object_10), (object) '\n'), (object) "SET Items="), obj), (object) '\n'), (object) "WHERE AccountID=@AccountID AND Number='"), (object) Class22.struct2_0.int_0), (object) "'")) : Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "ALTER PROCEDURE MMK_ItemMakerWareHous (@AccountID VARCHAR(10))\nAS\nUPDATE warehouse\nSET Items=", obj), (object) '\n'), (object) "WHERE AccountID=@AccountID"));
      Class28.sqlDataReader_0.Close();
      sqlCommand.ExecuteNonQuery();
    }
    else
      Class28.sqlDataReader_0.Close();
    sqlCommand.Dispose();
    Class28.sqlConnection_0.Close();
    return (object) true;
  }

  public static object smethod_7()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_ItemMakerInventory') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_ItemMakerInventory'), 'IsProcedure')= 1 select object_id('"), Class26.object_7), (object) "..MMK_ItemMakerInventory') else return end else return")), Class28.sqlConnection_0);
    object obj = (object) "0x";
    int num1 = 1;
    int num2 = Class32.int_3;
    int num3 = num1;
    while (num3 <= num2)
    {
      obj = Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(obj, (object) "F");
      checked { ++num3; }
    }
    SqlCommand sqlCommand = Class28.sqlCommand_0;
    sqlCommand.CommandType = CommandType.Text;
    sqlCommand.Connection.Open();
    Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
    if (Class28.sqlDataReader_0.Read())
    {
      sqlCommand.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "ALTER PROCEDURE MMK_ItemMakerInventory (@AccountID VARCHAR(10), @Name VARCHAR(10))\nAS\nUPDATE Character\nSET Inventory=", obj), (object) '\n'), (object) "WHERE AccountID=@AccountID AND Name=@Name"));
      Class28.sqlDataReader_0.Close();
      sqlCommand.ExecuteNonQuery();
    }
    else
      Class28.sqlDataReader_0.Close();
    sqlCommand.Dispose();
    Class28.sqlConnection_0.Close();
    return (object) true;
  }

  public static object smethod_8()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_SkillMaker') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_SkillMaker'), 'IsProcedure')= 1 select object_id('"), Class26.object_7), (object) "..MMK_SkillMaker') else return end else return")), Class28.sqlConnection_0);
    object obj = (object) "0x";
    int num1 = 1;
    int num2 = checked ((int) Math.Round(unchecked ((double) Class32.int_4 / 6.0)));
    int num3 = num1;
    while (num3 <= num2)
    {
      obj = Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(obj, (object) "FF0000");
      checked { ++num3; }
    }
    SqlCommand sqlCommand = Class28.sqlCommand_0;
    sqlCommand.CommandType = CommandType.Text;
    sqlCommand.Connection.Open();
    Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
    if (Class28.sqlDataReader_0.Read())
    {
      sqlCommand.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "ALTER PROCEDURE MMK_SkillMaker (@AccountID VARCHAR(10), @Name VARCHAR(10))\nAS\nUPDATE Character\nSET MagicList=", obj), (object) '\n'), (object) "WHERE AccountID=@AccountID AND Name=@Name"));
      Class28.sqlDataReader_0.Close();
      sqlCommand.ExecuteNonQuery();
    }
    else
      Class28.sqlDataReader_0.Close();
    sqlCommand.Dispose();
    Class28.sqlConnection_0.Close();
    return (object) true;
  }

  public static object smethod_9(object object_0)
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_ItemMakerWareHous') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_ItemMakerWareHous'), 'IsProcedure')= 1 select object_id('"), Class26.object_7), (object) "..MMK_ItemMakerWareHous') else return end else return")), Class28.sqlConnection_0);
    SqlCommand sqlCommand = Class28.sqlCommand_0;
    sqlCommand.CommandType = CommandType.Text;
    sqlCommand.Connection.Open();
    Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
    if (Class28.sqlDataReader_0.Read())
    {
      sqlCommand.CommandText = Class22.struct2_0.int_0 != 0 ? Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "ALTER PROCEDURE MMK_ItemMakerWareHous (@AccountID VARCHAR(10))\nAS\nUPDATE ", Class26.object_10), (object) '\n'), (object) "SET Items="), object_0), (object) '\n'), (object) "WHERE AccountID=@AccountID AND Number='"), (object) Class22.struct2_0.int_0), (object) "'")) : Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "ALTER PROCEDURE MMK_ItemMakerWareHous (@AccountID VARCHAR(10))\nAS\nUPDATE warehouse\nSET Items=", object_0), (object) '\n'), (object) "WHERE AccountID=@AccountID"));
      Class28.sqlDataReader_0.Close();
      sqlCommand.ExecuteNonQuery();
    }
    else
      Class28.sqlDataReader_0.Close();
    sqlCommand.Dispose();
    Class28.sqlConnection_0.Close();
    return (object) true;
  }

  public static object smethod_10(object object_0)
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_ItemMakerInventory') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_ItemMakerInventory'), 'IsProcedure')= 1 select object_id('"), Class26.object_7), (object) "..MMK_ItemMakerInventory') else return end else return")), Class28.sqlConnection_0);
    SqlCommand sqlCommand = Class28.sqlCommand_0;
    sqlCommand.CommandType = CommandType.Text;
    sqlCommand.Connection.Open();
    Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
    if (Class28.sqlDataReader_0.Read())
    {
      sqlCommand.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "ALTER PROCEDURE MMK_ItemMakerInventory (@AccountID VARCHAR(10), @Name VARCHAR(10))\nAS\nUPDATE Character\nSET Inventory=", object_0), (object) '\n'), (object) "WHERE AccountID=@AccountID AND Name=@Name"));
      Class28.sqlDataReader_0.Close();
      sqlCommand.ExecuteNonQuery();
    }
    else
      Class28.sqlDataReader_0.Close();
    sqlCommand.Dispose();
    Class28.sqlConnection_0.Close();
    return (object) true;
  }

  public static object smethod_11(object object_0)
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_QuestMaker') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_QuestMaker'), 'IsProcedure')= 1 select object_id('"), Class26.object_7), (object) "..MMK_QuestMaker') else return end else return")), Class28.sqlConnection_0);
    object obj;
    try
    {
      SqlCommand sqlCommand = Class28.sqlCommand_0;
      sqlCommand.CommandType = CommandType.Text;
      sqlCommand.Connection.Open();
      Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
      if (Class28.sqlDataReader_0.Read())
      {
        sqlCommand.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "ALTER PROCEDURE MMK_QuestMaker (@AccountID VARCHAR(10), @Name VARCHAR(10))\nAS\nUPDATE Character\nSET Quest=", object_0), (object) '\n'), (object) "WHERE AccountID=@AccountID AND Name=@Name"));
        Class28.sqlDataReader_0.Close();
        sqlCommand.ExecuteNonQuery();
      }
      else
        Class28.sqlDataReader_0.Close();
      sqlCommand.Dispose();
      Class28.sqlConnection_0.Close();
      goto label_7;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_7:
    return (object) true;
  }

  public static object smethod_12(object object_0)
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_SkillMaker') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_SkillMaker'), 'IsProcedure')= 1 select object_id('"), Class26.object_7), (object) "..MMK_SkillMaker') else return end else return")), Class28.sqlConnection_0);
    SqlCommand sqlCommand = Class28.sqlCommand_0;
    sqlCommand.CommandType = CommandType.Text;
    sqlCommand.Connection.Open();
    Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
    if (Class28.sqlDataReader_0.Read())
    {
      sqlCommand.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "ALTER PROCEDURE MMK_SkillMaker (@AccountID VARCHAR(10), @Name VARCHAR(10))\nAS\nUPDATE Character\nSET MagicList=", object_0), (object) '\n'), (object) "WHERE AccountID=@AccountID AND Name=@Name"));
      Class28.sqlDataReader_0.Close();
      sqlCommand.ExecuteNonQuery();
    }
    else
      Class28.sqlDataReader_0.Close();
    sqlCommand.Dispose();
    Class28.sqlConnection_0.Close();
    return (object) true;
  }

  public static object smethod_13(object object_0)
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_GuildMaker') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_GuildMaker'), 'IsProcedure')= 1 select object_id('"), Class26.object_7), (object) "..MMK_GuildMaker') else return end else return")), Class28.sqlConnection_0);
    object obj;
    try
    {
      SqlCommand sqlCommand = Class28.sqlCommand_0;
      sqlCommand.CommandType = CommandType.Text;
      sqlCommand.Connection.Open();
      Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
      if (Class28.sqlDataReader_0.Read())
      {
        sqlCommand.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "ALTER PROCEDURE MMK_GuildMaker (@Name VARCHAR(8))\nAS\nUPDATE Guild\nSET G_Mark=", object_0), (object) '\n'), (object) "WHERE G_Name=@Name"));
        Class28.sqlDataReader_0.Close();
        sqlCommand.ExecuteNonQuery();
      }
      else
        Class28.sqlDataReader_0.Close();
      sqlCommand.Dispose();
      Class28.sqlConnection_0.Close();
      goto label_7;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_7:
    return (object) true;
  }

  public static object smethod_14()
  {
    Class20.smethod_15();
    Class20.smethod_16();
    Class20.smethod_17();
    Class20.smethod_18();
    Class20.smethod_19();
    Class20.smethod_20();
    Class20.smethod_21();
    Class20.smethod_22();
    Class20.smethod_23();
    Class20.smethod_24();
    Class20.smethod_25();
    Class20.smethod_26();
    Class21.smethod_3();
    return (object) true;
  }

  public static object smethod_15()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..ItemMakerWareHous') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..ItemMakerWareHous'), 'IsProcedure')= 0 select object_id('"), Class26.object_7), (object) "..ItemMakerWareHous') else return end else return")), Class28.sqlConnection_0);
    object obj;
    try
    {
      SqlCommand sqlCommand = Class28.sqlCommand_0;
      sqlCommand.CommandType = CommandType.Text;
      sqlCommand.Connection.Open();
      Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
      if (!Class28.sqlDataReader_0.Read())
      {
        sqlCommand.CommandText = "DROP PROCEDURE ItemMakerWareHous";
        Class28.sqlDataReader_0.Close();
        sqlCommand.ExecuteNonQuery();
      }
      else
        Class28.sqlDataReader_0.Close();
      sqlCommand.Dispose();
      Class28.sqlConnection_0.Close();
      goto label_7;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_7:
    return (object) true;
  }

  public static object smethod_16()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..ItemMakerInventary') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..ItemMakerInventary'), 'IsProcedure')= 0 select object_id('"), Class26.object_7), (object) "..ItemMakerInventary') else return end else return")), Class28.sqlConnection_0);
    object obj;
    try
    {
      SqlCommand sqlCommand = Class28.sqlCommand_0;
      sqlCommand.CommandType = CommandType.Text;
      sqlCommand.Connection.Open();
      Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
      if (!Class28.sqlDataReader_0.Read())
      {
        sqlCommand.CommandText = "DROP PROCEDURE ItemMakerInventary";
        Class28.sqlDataReader_0.Close();
        sqlCommand.ExecuteNonQuery();
      }
      else
        Class28.sqlDataReader_0.Close();
      sqlCommand.Dispose();
      Class28.sqlConnection_0.Close();
      goto label_7;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_7:
    return (object) true;
  }

  public static object smethod_17()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..SkillMaker') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..SkillMaker'), 'IsProcedure')= 0 select object_id('"), Class26.object_7), (object) "..SkillMaker') else return end else return")), Class28.sqlConnection_0);
    object obj;
    try
    {
      SqlCommand sqlCommand = Class28.sqlCommand_0;
      sqlCommand.CommandType = CommandType.Text;
      sqlCommand.Connection.Open();
      Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
      if (!Class28.sqlDataReader_0.Read())
      {
        sqlCommand.CommandText = "DROP PROCEDURE SkillMaker";
        Class28.sqlDataReader_0.Close();
        sqlCommand.ExecuteNonQuery();
      }
      else
        Class28.sqlDataReader_0.Close();
      sqlCommand.Dispose();
      Class28.sqlConnection_0.Close();
      goto label_7;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_7:
    return (object) true;
  }

  public static object smethod_18()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..QuestMaker') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..QuestMaker'), 'IsProcedure')= 0 select object_id('"), Class26.object_7), (object) "..QuestMaker') else return end else return")), Class28.sqlConnection_0);
    object obj;
    try
    {
      SqlCommand sqlCommand = Class28.sqlCommand_0;
      sqlCommand.CommandType = CommandType.Text;
      sqlCommand.Connection.Open();
      Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
      if (!Class28.sqlDataReader_0.Read())
      {
        sqlCommand.CommandText = "DROP PROCEDURE QuestMaker";
        Class28.sqlDataReader_0.Close();
        sqlCommand.ExecuteNonQuery();
      }
      else
        Class28.sqlDataReader_0.Close();
      sqlCommand.Dispose();
      Class28.sqlConnection_0.Close();
      goto label_7;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_7:
    return (object) true;
  }

  public static object smethod_19()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..GuildMaker') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..GuildMaker'), 'IsProcedure')= 0 select object_id('"), Class26.object_7), (object) "..GuildMaker') else return end else return")), Class28.sqlConnection_0);
    object obj;
    try
    {
      SqlCommand sqlCommand = Class28.sqlCommand_0;
      sqlCommand.CommandType = CommandType.Text;
      sqlCommand.Connection.Open();
      Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
      if (!Class28.sqlDataReader_0.Read())
      {
        sqlCommand.CommandText = "DROP PROCEDURE GuildMaker";
        Class28.sqlDataReader_0.Close();
        sqlCommand.ExecuteNonQuery();
      }
      else
        Class28.sqlDataReader_0.Close();
      sqlCommand.Dispose();
      Class28.sqlConnection_0.Close();
      goto label_7;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_7:
    return (object) true;
  }

  public static object smethod_20()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..DupeFinder') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..DupeFinder'), 'IsProcedure')= 0 select object_id('"), Class26.object_7), (object) "..DupeFinder') else return end else return")), Class28.sqlConnection_0);
    object obj;
    try
    {
      SqlCommand sqlCommand = Class28.sqlCommand_0;
      sqlCommand.CommandType = CommandType.Text;
      sqlCommand.Connection.Open();
      Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
      if (!Class28.sqlDataReader_0.Read())
      {
        sqlCommand.CommandText = "DROP PROCEDURE DupeFinder";
        Class28.sqlDataReader_0.Close();
        sqlCommand.ExecuteNonQuery();
      }
      else
        Class28.sqlDataReader_0.Close();
      sqlCommand.Dispose();
      Class28.sqlConnection_0.Close();
      goto label_7;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_7:
    return (object) true;
  }

  public static object smethod_21()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_ItemMakerWareHous') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_ItemMakerWareHous'), 'IsProcedure')= 0 select object_id('"), Class26.object_7), (object) "..MMK_ItemMakerWareHous') else return end else return")), Class28.sqlConnection_0);
    object obj;
    try
    {
      SqlCommand sqlCommand = Class28.sqlCommand_0;
      sqlCommand.CommandType = CommandType.Text;
      sqlCommand.Connection.Open();
      Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
      if (!Class28.sqlDataReader_0.Read())
      {
        sqlCommand.CommandText = "DROP PROCEDURE MMK_ItemMakerWareHous";
        Class28.sqlDataReader_0.Close();
        sqlCommand.ExecuteNonQuery();
      }
      else
        Class28.sqlDataReader_0.Close();
      sqlCommand.Dispose();
      Class28.sqlConnection_0.Close();
      goto label_7;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_7:
    return (object) true;
  }

  public static object smethod_22()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_ItemMakerInventory') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_ItemMakerInventory'), 'IsProcedure')= 0 select object_id('"), Class26.object_7), (object) "..MMK_ItemMakerInventory') else return end else return")), Class28.sqlConnection_0);
    object obj;
    try
    {
      SqlCommand sqlCommand = Class28.sqlCommand_0;
      sqlCommand.CommandType = CommandType.Text;
      sqlCommand.Connection.Open();
      Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
      if (!Class28.sqlDataReader_0.Read())
      {
        sqlCommand.CommandText = "DROP PROCEDURE MMK_ItemMakerInventory";
        Class28.sqlDataReader_0.Close();
        sqlCommand.ExecuteNonQuery();
      }
      else
        Class28.sqlDataReader_0.Close();
      sqlCommand.Dispose();
      Class28.sqlConnection_0.Close();
      goto label_7;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_7:
    return (object) true;
  }

  public static object smethod_23()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_SkillMaker') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_SkillMaker'), 'IsProcedure')= 0 select object_id('"), Class26.object_7), (object) "..MMK_SkillMaker') else return end else return")), Class28.sqlConnection_0);
    object obj;
    try
    {
      SqlCommand sqlCommand = Class28.sqlCommand_0;
      sqlCommand.CommandType = CommandType.Text;
      sqlCommand.Connection.Open();
      Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
      if (!Class28.sqlDataReader_0.Read())
      {
        sqlCommand.CommandText = "DROP PROCEDURE MMK_SkillMaker";
        Class28.sqlDataReader_0.Close();
        sqlCommand.ExecuteNonQuery();
      }
      else
        Class28.sqlDataReader_0.Close();
      sqlCommand.Dispose();
      Class28.sqlConnection_0.Close();
      goto label_7;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_7:
    return (object) true;
  }

  public static object smethod_24()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_QuestMaker') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_QuestMaker'), 'IsProcedure')= 0 select object_id('"), Class26.object_7), (object) "..MMK_QuestMaker') else return end else return")), Class28.sqlConnection_0);
    object obj;
    try
    {
      SqlCommand sqlCommand = Class28.sqlCommand_0;
      sqlCommand.CommandType = CommandType.Text;
      sqlCommand.Connection.Open();
      Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
      if (!Class28.sqlDataReader_0.Read())
      {
        sqlCommand.CommandText = "DROP PROCEDURE MMK_QuestMaker";
        Class28.sqlDataReader_0.Close();
        sqlCommand.ExecuteNonQuery();
      }
      else
        Class28.sqlDataReader_0.Close();
      sqlCommand.Dispose();
      Class28.sqlConnection_0.Close();
      goto label_7;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_7:
    return (object) true;
  }

  public static object smethod_25()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_GuildMaker') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_GuildMaker'), 'IsProcedure')= 0 select object_id('"), Class26.object_7), (object) "..MMK_GuildMaker') else return end else return")), Class28.sqlConnection_0);
    object obj;
    try
    {
      SqlCommand sqlCommand = Class28.sqlCommand_0;
      sqlCommand.CommandType = CommandType.Text;
      sqlCommand.Connection.Open();
      Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
      if (!Class28.sqlDataReader_0.Read())
      {
        sqlCommand.CommandText = "DROP PROCEDURE MMK_GuildMaker";
        Class28.sqlDataReader_0.Close();
        sqlCommand.ExecuteNonQuery();
      }
      else
        Class28.sqlDataReader_0.Close();
      sqlCommand.Dispose();
      Class28.sqlConnection_0.Close();
      goto label_7;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_7:
    return (object) true;
  }

  public static object smethod_26()
  {
    Class28.sqlConnection_0 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Class26.object_4, (object) "Local", false) ? new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Network Library=dbmssocn; Data Source=", Class26.object_5), (object) ","), Class26.object_6), (object) "; uid="), Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";"))) : new SqlConnection(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "Data Source=localhost; uid=", Class26.object_2), (object) ";pwd="), Class26.object_3), (object) ";database="), Class26.object_7), (object) ";")));
    Class28.sqlCommand_0 = new SqlCommand(Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "if object_id('", Class26.object_7), (object) "..MMK_FinderMaker') is not null begin if objectproperty(object_id('"), Class26.object_7), (object) "..MMK_FinderMaker'), 'IsProcedure')= 0 select object_id('"), Class26.object_7), (object) "..MMK_FinderMaker') else return end else return")), Class28.sqlConnection_0);
    object obj;
    try
    {
      SqlCommand sqlCommand = Class28.sqlCommand_0;
      sqlCommand.CommandType = CommandType.Text;
      sqlCommand.Connection.Open();
      Class28.sqlDataReader_0 = sqlCommand.ExecuteReader();
      if (!Class28.sqlDataReader_0.Read())
      {
        sqlCommand.CommandText = "DROP PROCEDURE MMK_FinderMaker";
        Class28.sqlDataReader_0.Close();
        sqlCommand.ExecuteNonQuery();
      }
      else
        Class28.sqlDataReader_0.Close();
      sqlCommand.Dispose();
      Class28.sqlConnection_0.Close();
      goto label_7;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_7:
    return (object) true;
  }
}
