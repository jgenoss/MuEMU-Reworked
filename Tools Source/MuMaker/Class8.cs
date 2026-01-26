// Decompiled with JetBrains decompiler
// Type: Class8
// Assembly: MuMaker, Version=1.1.3.0, Culture=neutral, PublicKeyToken=null
// MVID: 7E43A6C6-04AF-4159-BD3A-BD25660D1460
// Assembly location: D:\MuServer\Tools\MuMaker 1.13\MuMaker-cleaned.exe

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using System;
using System.Data;
using System.Data.SqlClient;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

[StandardModule]
internal sealed class Class8
{
  public static object smethod_0()
  {
    Class7.smethod_0();
    try
    {
      string str = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectNotEqual(Class26.object_14, (object) 1, false) ? Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) ", ", Class26.object_11)) : "";
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "SELECT cLevel, LevelUpPoint, Experience, Strength, Dexterity, Vitality, Energy, Leadership, FruitPoint, PkLevel, PkCount, PkTime, Class, CtlCode " + str + " FROM Character WHERE AccountID='" + Class22.struct0_0.string_1 + "' AND NAME='" + Class22.struct1_0.string_1 + "'";
      Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
      Class28.sqlDataReader_1.Read();
      Class22.struct1_0.string_2 = Class28.sqlDataReader_1[0].ToString();
      Class22.struct1_0.string_3 = Class28.sqlDataReader_1[1].ToString();
      Class22.struct1_0.string_4 = Class28.sqlDataReader_1[2].ToString();
      Class22.struct1_0.string_5 = Class28.sqlDataReader_1[3].ToString();
      Class22.struct1_0.string_6 = Class28.sqlDataReader_1[4].ToString();
      Class22.struct1_0.string_7 = Class28.sqlDataReader_1[5].ToString();
      Class22.struct1_0.string_8 = Class28.sqlDataReader_1[6].ToString();
      Class22.struct1_0.string_9 = Class28.sqlDataReader_1[7].ToString();
      Class22.struct1_0.string_10 = Class28.sqlDataReader_1[8].ToString();
      Class22.struct1_0.string_11 = Class28.sqlDataReader_1[9].ToString();
      Class22.struct1_0.string_12 = Class28.sqlDataReader_1[10].ToString();
      Class22.struct1_0.string_13 = Class28.sqlDataReader_1[11].ToString();
      Class22.struct1_0.string_14 = Class28.sqlDataReader_1[12].ToString();
      Class22.struct1_0.string_15 = Class28.sqlDataReader_1[13].ToString();
      try
      {
        Class22.struct1_0.string_16 = NewLateBinding.LateGet((object) Class28.sqlDataReader_1, (Type) null, "Item", new object[1]
        {
          RuntimeHelpers.GetObjectValue(Class26.object_11)
        }, (string[]) null, (Type[]) null, (bool[]) null).ToString();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        Class22.struct1_0.string_16 = "0";
        ProjectData.ClearProjectError();
      }
      Class28.sqlDataReader_1.Close();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    Class7.smethod_0();
    object obj;
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "SELECT master.dbo.fn_varbintohexstr(CAST(Quest AS Image)) FROM Character WHERE AccountID='" + Class22.struct0_0.string_1 + "' AND NAME='" + Class22.struct1_0.string_1 + "'";
      Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
      Class28.sqlDataReader_1.Read();
      Class22.struct1_0.string_17 = Strings.Mid(Class28.sqlDataReader_1[0].ToString().ToUpper(), 3, 32);
      Class28.sqlDataReader_1.Close();
      goto label_10;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_10:
    Class7.smethod_5();
    return (object) true;
  }

  public static object smethod_1()
  {
    Class7.smethod_0();
    object obj;
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "SELECT memb___id, memb__pwd, sno__numb, mail_addr, bloc_code FROM MEMB_INFO WHERE memb___id='" + Class22.struct0_0.string_1 + "'";
      Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
      Class28.sqlDataReader_1.Read();
      Class22.struct0_0.string_0 = Class28.sqlDataReader_1[0].ToString();
      Class22.struct0_0.string_2 = Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Class28.sqlDataReader_1[1].ToString(), "System.Byte[]", false) != 0 ? Class28.sqlDataReader_1[1].ToString() : "MD5 ENCRYPT";
      Class22.struct0_0.string_3 = Class28.sqlDataReader_1[2].ToString();
      Class22.struct0_0.string_4 = Class28.sqlDataReader_1[3].ToString();
      Class22.struct0_0.string_5 = Class28.sqlDataReader_1[4].ToString();
      Class28.sqlDataReader_1.Close();
      goto label_4;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_4:
    Class7.smethod_5();
    return (object) true;
  }

  public static object smethod_2(object object_0)
  {
    Class7.smethod_0();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "SELECT * FROM DefaultClassType WHERE Class='", object_0), (object) "'"));
      Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
      Class28.sqlDataReader_1.Read();
      Class22.struct1_1.string_5 = Class28.sqlDataReader_1[1].ToString();
      Class22.struct1_1.string_6 = Class28.sqlDataReader_1[2].ToString();
      Class22.struct1_1.string_7 = Class28.sqlDataReader_1[3].ToString();
      Class22.struct1_1.string_8 = Class28.sqlDataReader_1[4].ToString();
      Class22.struct1_1.string_9 = Class28.sqlDataReader_1[16].ToString();
      Class22.struct1_1.string_2 = Class28.sqlDataReader_1[17].ToString();
      Class22.struct1_1.string_3 = Class28.sqlDataReader_1[18].ToString();
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

  public static object smethod_3(object object_0)
  {
    Class7.smethod_2();
    object obj;
    if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(object_0, (object) 0, false))
    {
      try
      {
        Class28.sqlConnection_3.Open();
        Class28.sqlCommand_3.Connection = Class28.sqlConnection_3;
        Class28.sqlCommand_3.CommandText = "SELECT master.dbo.fn_varbintohexstr(CAST(Items AS Image)), Money FROM warehouse WHERE AccountID = '" + Class22.struct0_0.string_1 + "'";
        Class28.sqlDataReader_3 = Class28.sqlCommand_3.ExecuteReader();
        Class28.sqlDataReader_3.Read();
        Class22.struct2_0.string_0 = Strings.Mid(Class28.sqlDataReader_3[0].ToString().ToUpper(), 3, Class28.sqlDataReader_3[0].ToString().Length);
        Class22.struct2_0.string_1 = Class28.sqlDataReader_3[1].ToString();
        Class28.sqlDataReader_3.Close();
        goto label_6;
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        Class7.smethod_7();
        obj = (object) false;
        ProjectData.ClearProjectError();
      }
    }
    else
    {
      try
      {
        Class28.sqlConnection_3.Open();
        Class28.sqlCommand_3.Connection = Class28.sqlConnection_3;
        Class28.sqlCommand_3.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "SELECT master.dbo.fn_varbintohexstr(CAST(Items AS Image)), Money FROM ", Class26.object_10), (object) " WHERE AccountID = '"), (object) Class22.struct0_0.string_1), (object) "' AND Number = '"), object_0), (object) "'"));
        Class28.sqlDataReader_3 = Class28.sqlCommand_3.ExecuteReader();
        Class28.sqlDataReader_3.Read();
        Class22.struct2_0.string_0 = Strings.Mid(Class28.sqlDataReader_3[0].ToString().ToUpper(), 3, Class28.sqlDataReader_3[0].ToString().Length);
        Class22.struct2_0.string_1 = Class28.sqlDataReader_3[1].ToString();
        Class28.sqlDataReader_3.Close();
        goto label_6;
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        Class7.smethod_7();
        obj = (object) false;
        ProjectData.ClearProjectError();
      }
    }
    return obj;
label_6:
    Class7.smethod_7();
    MessageBox.Show("Length = " + Class22.struct2_0.string_0.Length.ToString() + " Default = " +
                    Class32.int_0.ToString());
    if (Class22.struct2_0.string_0.Length == Class32.int_0)
      return (object) true;
    int num1 = (int) Interaction.MsgBox(RuntimeHelpers.GetObjectValue(Class30.object_86), MsgBoxStyle.OkOnly, RuntimeHelpers.GetObjectValue(Class30.object_76));
    if (Class22.struct2_0.string_0.Length < Class32.int_0)
    {
      int num2 = checked (Class22.struct2_0.string_0.Length + 1);
      int num3 = Class32.int_0;
      int num4 = num2;
      while (num4 <= num3)
      {
        Class22.struct2_0.string_0 = Class22.struct2_0.string_0 + "F";
        checked { ++num4; }
      }
    }
    return (object) false;
  }

  public static object smethod_4()
  {
    Class7.smethod_0();
    Class28.sqlConnection_1.Open();
    Class20.smethod_4();
    object obj;
    try
    {
      SqlCommand sqlCommand1 = new SqlCommand();
      SqlCommand sqlCommand2 = new SqlCommand("MMK_ItemMakerWareHous", Class28.sqlConnection_1);
      sqlCommand2.CommandType = CommandType.StoredProcedure;
      Class28.sqlParameter_0 = new SqlParameter("@AccountID", SqlDbType.VarChar, 10);
      Class28.sqlParameter_0.Direction = ParameterDirection.Input;
      sqlCommand2.Parameters.Add(Class28.sqlParameter_0);
      sqlCommand2.Parameters["@AccountID"].Value = (object) Class22.struct0_0.string_1;
      sqlCommand2.ExecuteNonQuery();
      sqlCommand2.Dispose();
      Class28.int_0 = 0;
      sqlCommand1.Dispose();
      goto label_4;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox(RuntimeHelpers.GetObjectValue(Class30.object_89), MsgBoxStyle.OkOnly, RuntimeHelpers.GetObjectValue(Class30.object_76));
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_4:
    Class7.smethod_5();
    return (object) true;
  }

  public static object smethod_5()
  {
    Class7.smethod_0();
    Class28.sqlConnection_1.Open();
    Class20.smethod_6();
    try
    {
      SqlCommand sqlCommand1 = new SqlCommand();
      SqlCommand sqlCommand2 = new SqlCommand("MMK_ItemMakerWareHous", Class28.sqlConnection_1);
      sqlCommand2.CommandType = CommandType.StoredProcedure;
      Class28.sqlParameter_0 = new SqlParameter("@AccountID", SqlDbType.VarChar, 10);
      Class28.sqlParameter_0.Direction = ParameterDirection.Input;
      sqlCommand2.Parameters.Add(Class28.sqlParameter_0);
      sqlCommand2.Parameters["@AccountID"].Value = (object) Class22.struct0_0.string_1;
      sqlCommand2.ExecuteNonQuery();
      sqlCommand2.Dispose();
      Class28.int_0 = 0;
      sqlCommand1.Dispose();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox(RuntimeHelpers.GetObjectValue(Class30.object_91), MsgBoxStyle.OkOnly, RuntimeHelpers.GetObjectValue(Class30.object_76));
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    return (object) true;
  }

  public static object smethod_6()
  {
    Class7.smethod_3();
    object obj;
    try
    {
      Class28.sqlConnection_4.Open();
      Class28.sqlCommand_4.Connection = Class28.sqlConnection_4;
      Class28.sqlCommand_4.CommandText = "SELECT master.dbo.fn_varbintohexstr(CAST(Inventory AS Image)), Money FROM Character WHERE AccountID = '" + Class22.struct0_0.string_1 + "' AND Name='" + Class22.struct1_0.string_1 + "'";
      Class28.sqlDataReader_4 = Class28.sqlCommand_4.ExecuteReader();
      Class28.sqlDataReader_4.Read();
      Class22.struct2_0.string_2 = Strings.Mid(Class28.sqlDataReader_4[0].ToString().ToUpper(), 3, Class28.sqlDataReader_4[0].ToString().Length);
      Class22.struct2_0.string_3 = Class28.sqlDataReader_4[1].ToString();
      Class28.sqlDataReader_4.Close();
      goto label_4;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      Class7.smethod_8();
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_4:
    Class7.smethod_8();
    return (object) true;
  }

  public static object smethod_7()
  {
    Class7.smethod_0();
    Class28.sqlConnection_1.Open();
    Class20.smethod_5();
    object obj;
    try
    {
      SqlCommand sqlCommand1 = new SqlCommand();
      SqlCommand sqlCommand2 = new SqlCommand("MMK_ItemMakerInventory", Class28.sqlConnection_1);
      sqlCommand2.CommandType = CommandType.StoredProcedure;
      Class28.sqlParameter_0 = new SqlParameter("@AccountID", SqlDbType.VarChar, 10);
      Class28.sqlParameter_0.Direction = ParameterDirection.Input;
      sqlCommand2.Parameters.Add(Class28.sqlParameter_0);
      Class28.sqlParameter_0 = new SqlParameter("@Name", SqlDbType.VarChar, 10);
      Class28.sqlParameter_0.Direction = ParameterDirection.Input;
      sqlCommand2.Parameters.Add(Class28.sqlParameter_0);
      sqlCommand2.Parameters["@AccountID"].Value = (object) Class22.struct0_0.string_1;
      sqlCommand2.Parameters["@Name"].Value = (object) Class22.struct1_0.string_1;
      sqlCommand2.ExecuteNonQuery();
      sqlCommand2.Dispose();
      Class28.int_0 = 0;
      sqlCommand1.Dispose();
      goto label_4;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox(RuntimeHelpers.GetObjectValue(Class30.object_83), MsgBoxStyle.OkOnly, RuntimeHelpers.GetObjectValue(Class30.object_76));
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_4:
    Class7.smethod_5();
    return (object) true;
  }

  public static object smethod_8()
  {
    Class7.smethod_0();
    Class28.sqlConnection_1.Open();
    Class20.smethod_7();
    try
    {
      SqlCommand sqlCommand1 = new SqlCommand();
      SqlCommand sqlCommand2 = new SqlCommand("MMK_ItemMakerInventory", Class28.sqlConnection_1);
      sqlCommand2.CommandType = CommandType.StoredProcedure;
      Class28.sqlParameter_0 = new SqlParameter("@AccountID", SqlDbType.VarChar, 10);
      Class28.sqlParameter_0.Direction = ParameterDirection.Input;
      sqlCommand2.Parameters.Add(Class28.sqlParameter_0);
      Class28.sqlParameter_0 = new SqlParameter("@Name", SqlDbType.VarChar, 10);
      Class28.sqlParameter_0.Direction = ParameterDirection.Input;
      sqlCommand2.Parameters.Add(Class28.sqlParameter_0);
      sqlCommand2.Parameters["@AccountID"].Value = (object) Class22.struct0_0.string_1;
      sqlCommand2.Parameters["@Name"].Value = (object) Class22.struct1_0.string_1;
      sqlCommand2.ExecuteNonQuery();
      sqlCommand2.Dispose();
      Class28.int_0 = 0;
      sqlCommand1.Dispose();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox(RuntimeHelpers.GetObjectValue(Class30.object_85), MsgBoxStyle.OkOnly, RuntimeHelpers.GetObjectValue(Class30.object_76));
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    return (object) true;
  }

  public static object smethod_9()
  {
    Class7.smethod_0();
    object obj;
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "SELECT master.dbo.fn_varbintohexstr(CAST(MagicList AS Image)) FROM Character WHERE AccountID='" + Class22.struct0_0.string_1 + "' AND NAME='" + Class22.struct1_0.string_1 + "'";
      Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
      Class28.sqlDataReader_1.Read();
      Class22.struct1_0.string_18 = Strings.Mid(Class28.sqlDataReader_1[0].ToString().ToUpper(), 3, Class28.sqlDataReader_1[0].ToString().Length);
      Class28.sqlDataReader_1.Close();
      goto label_4;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
label_4:
    Class7.smethod_5();
    return (object) true;
  }

  public static object smethod_10()
  {
    Class7.smethod_0();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "SELECT G_Name, G_Union,G_Rival,G_Notice, G_Score, G_Type, MemberCount, master.dbo.fn_varbintohexstr(CAST(G_Mark AS Image)) AS MARCK FROM Guild WHERE G_Master='" + Class23.struct3_0.string_0 + "'";
      Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
      try
      {
        Class28.sqlDataReader_1.Read();
        if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Class28.sqlDataReader_1["G_Name"].ToString(), "", false) != 0)
        {
          Class23.struct3_0.string_1 = Class28.sqlDataReader_1["G_Name"].ToString();
          Class23.struct3_0.string_2 = Strings.Mid(Class28.sqlDataReader_1["MARCK"].ToString(), 3);
          Class23.struct3_0.string_3 = Class28.sqlDataReader_1["G_Union"].ToString();
          Class23.struct3_0.string_4 = Class28.sqlDataReader_1["G_Rival"].ToString();
          Class23.struct3_0.string_5 = Class28.sqlDataReader_1["G_Notice"].ToString();
          Class23.struct3_0.string_6 = Class28.sqlDataReader_1["G_Score"].ToString();
          Class23.struct3_0.string_9 = Class28.sqlDataReader_1["G_Type"].ToString();
          Class23.struct3_0.string_10 = Class28.sqlDataReader_1["MemberCount"].ToString();
        }
        else
        {
          Class23.struct3_0.string_1 = ">No Guild<";
          Class23.struct3_0.string_3 = Conversions.ToString(0);
          Class23.struct3_0.string_4 = Conversions.ToString(0);
          Class23.struct3_0.string_2 = "0x0000000000000000000000000000000000000000000000000000000000000000";
          Class23.struct3_0.string_5 = "";
          Class23.struct3_0.string_6 = "";
          Class23.struct3_0.string_9 = "";
          Class23.struct3_0.string_10 = "";
        }
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        Class23.struct3_0.string_1 = ">No Guild<";
        Class23.struct3_0.string_3 = Conversions.ToString(0);
        Class23.struct3_0.string_4 = Conversions.ToString(0);
        Class23.struct3_0.string_2 = "0x0000000000000000000000000000000000000000000000000000000000000000";
        Class23.struct3_0.string_5 = "";
        Class23.struct3_0.string_6 = "";
        Class23.struct3_0.string_9 = "";
        Class23.struct3_0.string_10 = "";
        ProjectData.ClearProjectError();
      }
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

  public static object smethod_11()
  {
    Class7.smethod_0();
    if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Class22.struct1_0.string_1, "ALL", false) != 0)
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "SELECT * FROM Character WHERE  Name='" + Class22.struct1_0.string_1 + "'";
      Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
      Class28.sqlDataReader_1.Read();
      Class22.struct1_0.string_0 = Class28.sqlDataReader_1["AccountID"].ToString();
      Class22.struct1_0.string_1 = Class28.sqlDataReader_1["Name"].ToString();
      Class22.struct1_0.string_2 = Class28.sqlDataReader_1["cLevel"].ToString();
      Class22.struct1_0.int_0 = Conversions.ToInteger(Class28.sqlDataReader_1["MapNumber"]);
      Class22.struct1_0.int_1 = Conversions.ToInteger(Class28.sqlDataReader_1["MapPosX"]);
      Class22.struct1_0.int_2 = Conversions.ToInteger(Class28.sqlDataReader_1["MapPosY"]);
      Class22.struct1_0.string_15 = Conversions.ToString(Class28.sqlDataReader_1["CtlCode"]);
      Class22.struct0_0.string_1 = Class22.struct1_0.string_0;
      Class28.sqlDataReader_1.Close();
    }
    else
    {
      Class22.struct1_0.string_0 = "ALL";
      Class22.struct1_0.string_1 = "ALL";
      Class22.struct1_0.string_2 = "";
      Class22.struct1_0.int_0 = 0;
      Class22.struct1_0.int_1 = 0;
      Class22.struct1_0.int_2 = 0;
      Class22.struct1_0.string_15 = Conversions.ToString(0);
      Class22.struct0_0.string_1 = Class22.struct1_0.string_0;
    }
    Class7.smethod_5();
    return (object) true;
  }
}
