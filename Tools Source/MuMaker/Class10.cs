// Decompiled with JetBrains decompiler
// Type: Class10
// Assembly: MuMaker, Version=1.1.3.0, Culture=neutral, PublicKeyToken=null
// MVID: 7E43A6C6-04AF-4159-BD3A-BD25660D1460
// Assembly location: D:\MuServer\Tools\MuMaker 1.13\MuMaker-cleaned.exe

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using System;

[StandardModule]
internal sealed class Class10
{
  public static object smethod_0()
  {
    Class7.smethod_10();
    try
    {
      Class28.oleDbConnection_0.Open();
      Class28.oleDbCommand_0.Connection = Class28.oleDbConnection_0;
      Class28.oleDbCommand_0.CommandText = "SELECT * FROM [Player - ClasesPJ] ORDER BY ID;";
      Class28.oleDbCommand_0.ExecuteNonQuery();
      Class28.oleDbDataReader_0 = Class28.oleDbCommand_0.ExecuteReader();
      int index = 0;
      while (Class28.oleDbDataReader_0.Read())
      {
        Class6.string_6[index] = Conversions.ToString(Class28.oleDbDataReader_0["ID"]).ToString();
        Class6.string_7[index] = Conversions.ToString(Class28.oleDbDataReader_0["CD"]).ToString();
        Class6.string_8[index] = Conversions.ToString(Class28.oleDbDataReader_0["Nombre"]).ToString();
        checked { ++index; }
      }
      Class6.string_9 = Conversions.ToString(index);
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
    try
    {
      Class28.oleDbConnection_0.Open();
      Class28.oleDbCommand_0.Connection = Class28.oleDbConnection_0;
      Class28.oleDbCommand_0.CommandText = "SELECT * FROM [Player - Quests] ORDER BY ID;";
      Class28.oleDbCommand_0.ExecuteNonQuery();
      Class28.oleDbDataReader_0 = Class28.oleDbCommand_0.ExecuteReader();
      int index = 0;
      while (Class28.oleDbDataReader_0.Read())
      {
        Class6.string_10[index] = Conversions.ToString(Class28.oleDbDataReader_0["ID"]).ToString();
        Class6.string_11[index] = Conversions.ToString(Class28.oleDbDataReader_0["Code"]).ToString();
        Class6.string_12[index] = Conversions.ToString(Class28.oleDbDataReader_0["Nombre"]).ToString();
        checked { ++index; }
      }
      Class6.string_13 = Conversions.ToString(index);
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

  public static object smethod_2()
  {
    Class7.smethod_10();
    try
    {
      Class28.oleDbConnection_0.Open();
      Class28.oleDbCommand_0.Connection = Class28.oleDbConnection_0;
      Class28.oleDbCommand_0.CommandText = "SELECT * FROM [Player - CtlCode] ORDER BY ID;";
      Class28.oleDbCommand_0.ExecuteNonQuery();
      Class28.oleDbDataReader_0 = Class28.oleDbCommand_0.ExecuteReader();
      int index = 0;
      while (Class28.oleDbDataReader_0.Read())
      {
        Class6.string_3[index] = Conversions.ToString(Class28.oleDbDataReader_0["ID"]).ToString();
        Class6.string_4[index] = Conversions.ToString(Class28.oleDbDataReader_0["Nombre"]).ToString();
        checked { ++index; }
      }
      Class6.string_5 = Conversions.ToString(index);
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

  public static object smethod_3()
  {
    Class7.smethod_10();
    try
    {
      Class28.oleDbConnection_0.Open();
      Class28.oleDbCommand_0.Connection = Class28.oleDbConnection_0;
      Class28.oleDbCommand_0.CommandText = "SELECT * FROM [Player - HeroSystem] ORDER BY ID;";
      Class28.oleDbCommand_0.ExecuteNonQuery();
      Class28.oleDbDataReader_0 = Class28.oleDbCommand_0.ExecuteReader();
      int index = 0;
      while (Class28.oleDbDataReader_0.Read())
      {
        Class6.string_14[index] = Conversions.ToString(Class28.oleDbDataReader_0["ID"]).ToString();
        Class6.string_15[index] = Conversions.ToString(Class28.oleDbDataReader_0["Nombre"]).ToString();
        checked { ++index; }
      }
      Class6.string_16 = Conversions.ToString(index);
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

  public static object smethod_4()
  {
    Class7.smethod_10();
    try
    {
      Class28.oleDbConnection_0.Open();
      Class28.oleDbCommand_0.Connection = Class28.oleDbConnection_0;
      Class28.oleDbCommand_0.CommandText = "SELECT * FROM [Game - Mapas] ORDER BY ID;";
      Class28.oleDbCommand_0.ExecuteNonQuery();
      Class28.oleDbDataReader_0 = Class28.oleDbCommand_0.ExecuteReader();
      int index = 0;
      while (Class28.oleDbDataReader_0.Read())
      {
        Class6.string_0[index] = Conversions.ToString(Class28.oleDbDataReader_0["ID"]).ToString();
        Class6.string_1[index] = Conversions.ToString(Class28.oleDbDataReader_0["Nombre"]).ToString();
        checked { ++index; }
      }
      Class6.string_2 = Conversions.ToString(index);
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

  public static object smethod_5()
  {
    Class7.smethod_10();
    try
    {
      Class28.oleDbConnection_0.Open();
      Class28.oleDbCommand_0.Connection = Class28.oleDbConnection_0;
      Class28.oleDbCommand_0.CommandText = "SELECT * FROM [Items - Excelent]";
      Class28.oleDbCommand_0.ExecuteNonQuery();
      Class28.oleDbDataReader_0 = Class28.oleDbCommand_0.ExecuteReader();
      int num = 0;
      while (Class28.oleDbDataReader_0.Read())
      {
        if (num == 0)
        {
          Class30.object_27 = (object) Conversions.ToString(Class28.oleDbDataReader_0["1"]);
          Class30.object_27 = (object) Conversions.ToString(Class28.oleDbDataReader_0["2"]);
          Class30.object_27 = (object) Conversions.ToString(Class28.oleDbDataReader_0["3"]);
          Class30.object_27 = (object) Conversions.ToString(Class28.oleDbDataReader_0["4"]);
          Class30.object_27 = (object) Conversions.ToString(Class28.oleDbDataReader_0["5"]);
          Class30.object_27 = (object) Conversions.ToString(Class28.oleDbDataReader_0["6"]);
        }
        if (num == 1)
        {
          Class30.object_28 = (object) Conversions.ToString(Class28.oleDbDataReader_0["1"]);
          Class30.object_29 = (object) Conversions.ToString(Class28.oleDbDataReader_0["2"]);
          Class30.object_30 = (object) Conversions.ToString(Class28.oleDbDataReader_0["3"]);
          Class30.object_31 = (object) Conversions.ToString(Class28.oleDbDataReader_0["4"]);
          Class30.object_32 = (object) Conversions.ToString(Class28.oleDbDataReader_0["5"]);
          Class30.object_33 = (object) Conversions.ToString(Class28.oleDbDataReader_0["6"]);
        }
        if (num == 2)
        {
          Class30.object_34 = (object) Conversions.ToString(Class28.oleDbDataReader_0["1"]);
          Class30.object_35 = (object) Conversions.ToString(Class28.oleDbDataReader_0["2"]);
          Class30.object_36 = (object) Conversions.ToString(Class28.oleDbDataReader_0["3"]);
          Class30.object_37 = (object) Conversions.ToString(Class28.oleDbDataReader_0["4"]);
          Class30.object_38 = (object) Conversions.ToString(Class28.oleDbDataReader_0["5"]);
          Class30.object_39 = (object) Conversions.ToString(Class28.oleDbDataReader_0["6"]);
        }
        if (num == 3)
        {
          Class30.object_40 = (object) Conversions.ToString(Class28.oleDbDataReader_0["1"]);
          Class30.object_41 = (object) Conversions.ToString(Class28.oleDbDataReader_0["2"]);
          Class30.object_42 = (object) Conversions.ToString(Class28.oleDbDataReader_0["3"]);
          Class30.object_43 = (object) Conversions.ToString(Class28.oleDbDataReader_0["4"]);
          Class30.object_44 = (object) Conversions.ToString(Class28.oleDbDataReader_0["5"]);
          Class30.object_45 = (object) Conversions.ToString(Class28.oleDbDataReader_0["6"]);
        }
        if (num == 4)
        {
          Class30.object_46 = (object) Conversions.ToString(Class28.oleDbDataReader_0["1"]);
          Class30.object_47 = (object) Conversions.ToString(Class28.oleDbDataReader_0["2"]);
          Class30.object_48 = (object) Conversions.ToString(Class28.oleDbDataReader_0["3"]);
          Class30.object_49 = (object) Conversions.ToString(Class28.oleDbDataReader_0["4"]);
          Class30.object_50 = (object) Conversions.ToString(Class28.oleDbDataReader_0["5"]);
          Class30.object_51 = (object) Conversions.ToString(Class28.oleDbDataReader_0["6"]);
        }
        if (num != 5)
          ;
        if (num != 6)
          ;
        if (num == 7)
        {
          Class30.object_52 = (object) Conversions.ToString(Class28.oleDbDataReader_0["1"]);
          Class30.object_53 = (object) Conversions.ToString(Class28.oleDbDataReader_0["2"]);
          Class30.object_54 = (object) Conversions.ToString(Class28.oleDbDataReader_0["3"]);
          Class30.object_55 = (object) Conversions.ToString(Class28.oleDbDataReader_0["4"]);
          Class30.object_56 = (object) Conversions.ToString(Class28.oleDbDataReader_0["5"]);
          Class30.object_57 = (object) Conversions.ToString(Class28.oleDbDataReader_0["6"]);
        }
        checked { ++num; }
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

  public static object smethod_6()
  {
    Class7.smethod_10();
    try
    {
      Class28.oleDbConnection_0.Open();
      Class28.oleDbCommand_0.Connection = Class28.oleDbConnection_0;
      Class28.oleDbCommand_0.CommandText = "SELECT * FROM [Items - Refinery]";
      Class28.oleDbCommand_0.ExecuteNonQuery();
      Class28.oleDbDataReader_0 = Class28.oleDbCommand_0.ExecuteReader();
      int num = 0;
      while (Class28.oleDbDataReader_0.Read())
      {
        if (num == 0)
        {
          Class30.object_58 = (object) Conversions.ToString(Class28.oleDbDataReader_0["1"]);
          Class30.object_59 = (object) Conversions.ToString(Class28.oleDbDataReader_0["2"]);
        }
        if (num == 1)
        {
          Class30.object_60 = (object) Conversions.ToString(Class28.oleDbDataReader_0["1"]);
          Class30.object_61 = (object) Conversions.ToString(Class28.oleDbDataReader_0["2"]);
        }
        if (num == 2)
        {
          Class30.object_62 = (object) Conversions.ToString(Class28.oleDbDataReader_0["1"]);
          Class30.object_63 = (object) Conversions.ToString(Class28.oleDbDataReader_0["2"]);
        }
        if (num == 3)
        {
          Class30.object_64 = (object) Conversions.ToString(Class28.oleDbDataReader_0["1"]);
          Class30.object_65 = (object) Conversions.ToString(Class28.oleDbDataReader_0["2"]);
        }
        if (num == 4)
        {
          Class30.object_66 = (object) Conversions.ToString(Class28.oleDbDataReader_0["1"]);
          Class30.object_67 = (object) Conversions.ToString(Class28.oleDbDataReader_0["2"]);
        }
        if (num == 5)
        {
          Class30.object_68 = (object) Conversions.ToString(Class28.oleDbDataReader_0["1"]);
          Class30.object_69 = (object) Conversions.ToString(Class28.oleDbDataReader_0["2"]);
        }
        if (num == 6)
        {
          Class30.object_70 = (object) Conversions.ToString(Class28.oleDbDataReader_0["1"]);
          Class30.object_71 = (object) Conversions.ToString(Class28.oleDbDataReader_0["2"]);
        }
        checked { ++num; }
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

  public static object smethod_7(object object_0)
  {
    Class7.smethod_10();
    try
    {
      Class28.oleDbConnection_0.Open();
      Class28.oleDbCommand_0.Connection = Class28.oleDbConnection_0;
      Class28.oleDbCommand_0.CommandText = Conversions.ToString(Operators.ConcatenateObject(Operators.ConcatenateObject((object) "SELECT NM FROM [Items - JewelOfHarmony] WHERE TP='", object_0), (object) "' ORDER BY ID;"));
      Class28.oleDbCommand_0.ExecuteNonQuery();
      Class28.oleDbDataReader_0 = Class28.oleDbCommand_0.ExecuteReader();
      object Left = (object) 0;
      while (Class28.oleDbDataReader_0.Read())
      {
        Class6.string_17[Conversions.ToInteger(Left)] = Class28.oleDbDataReader_0["NM"].ToString();
        Left = Operators.AddObject(Left, (object) 1);
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

  public static object smethod_8(object object_0, object object_1)
  {
    object_1 = (object) Conversion.Hex(Operators.AddObject(object_1, (object) 1));
    Class7.smethod_10();
    try
    {
      Class28.oleDbConnection_0.Open();
      Class28.oleDbCommand_0.Connection = Class28.oleDbConnection_0;
      Class28.oleDbCommand_0.CommandText = Conversions.ToString(Operators.ConcatenateObject(Operators.ConcatenateObject(Operators.ConcatenateObject(Operators.ConcatenateObject((object) "SELECT * FROM [Items - JewelOfHarmony] WHERE ID='", object_1), (object) "' AND TP='"), object_0), (object) "' ORDER BY ID;"));
      Class28.oleDbCommand_0.ExecuteNonQuery();
      Class28.oleDbDataReader_0 = Class28.oleDbCommand_0.ExecuteReader();
      object Left1 = (object) 0;
      Class28.oleDbDataReader_0.Read();
      Class6.string_18[Conversions.ToInteger(Left1)] = Conversions.ToString(Class28.oleDbDataReader_0["0"]);
      object Left2 = Operators.AddObject(Left1, (object) 1);
      Class6.string_18[Conversions.ToInteger(Left2)] = Conversions.ToString(Class28.oleDbDataReader_0["1"]);
      object Left3 = Operators.AddObject(Left2, (object) 1);
      Class6.string_18[Conversions.ToInteger(Left3)] = Conversions.ToString(Class28.oleDbDataReader_0["2"]);
      object Left4 = Operators.AddObject(Left3, (object) 1);
      Class6.string_18[Conversions.ToInteger(Left4)] = Conversions.ToString(Class28.oleDbDataReader_0["3"]);
      object Left5 = Operators.AddObject(Left4, (object) 1);
      Class6.string_18[Conversions.ToInteger(Left5)] = Conversions.ToString(Class28.oleDbDataReader_0["4"]);
      object Left6 = Operators.AddObject(Left5, (object) 1);
      Class6.string_18[Conversions.ToInteger(Left6)] = Conversions.ToString(Class28.oleDbDataReader_0["5"]);
      object Left7 = Operators.AddObject(Left6, (object) 1);
      Class6.string_18[Conversions.ToInteger(Left7)] = Conversions.ToString(Class28.oleDbDataReader_0["6"]);
      object Left8 = Operators.AddObject(Left7, (object) 1);
      Class6.string_18[Conversions.ToInteger(Left8)] = Conversions.ToString(Class28.oleDbDataReader_0["7"]);
      object Left9 = Operators.AddObject(Left8, (object) 1);
      Class6.string_18[Conversions.ToInteger(Left9)] = Conversions.ToString(Class28.oleDbDataReader_0["8"]);
      object Left10 = Operators.AddObject(Left9, (object) 1);
      Class6.string_18[Conversions.ToInteger(Left10)] = Conversions.ToString(Class28.oleDbDataReader_0["9"]);
      object Left11 = Operators.AddObject(Left10, (object) 1);
      Class6.string_18[Conversions.ToInteger(Left11)] = Conversions.ToString(Class28.oleDbDataReader_0["A"]);
      object Left12 = Operators.AddObject(Left11, (object) 1);
      Class6.string_18[Conversions.ToInteger(Left12)] = Conversions.ToString(Class28.oleDbDataReader_0["B"]);
      object Left13 = Operators.AddObject(Left12, (object) 1);
      Class6.string_18[Conversions.ToInteger(Left13)] = Conversions.ToString(Class28.oleDbDataReader_0["C"]);
      object Left14 = Operators.AddObject(Left13, (object) 1);
      Class6.string_18[Conversions.ToInteger(Left14)] = Conversions.ToString(Class28.oleDbDataReader_0["D"]);
      object Left15 = Operators.AddObject(Left14, (object) 1);
      Class6.string_18[Conversions.ToInteger(Left15)] = Conversions.ToString(Class28.oleDbDataReader_0["E"]);
      object obj = Operators.AddObject(Left15, (object) 1);
      Class6.string_18[Conversions.ToInteger(obj)] = Conversions.ToString(Class28.oleDbDataReader_0["F"]);
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      ProjectData.ClearProjectError();
    }
    Class28.oleDbDataReader_0.Close();
    Class7.smethod_11();
    return (object) true;
  }

  public static object smethod_9()
  {
    int index1 = 0;
    Class7.smethod_10();
    try
    {
      Class28.oleDbConnection_0.Open();
      Class28.oleDbCommand_0.Connection = Class28.oleDbConnection_0;
      Class28.oleDbCommand_0.CommandText = "SELECT * FROM [Items - Socket] WHERE TP=255 ORDER BY Nº;";
      Class28.oleDbCommand_0.ExecuteNonQuery();
      Class28.oleDbDataReader_0 = Class28.oleDbCommand_0.ExecuteReader();
      while (Class28.oleDbDataReader_0.Read())
      {
        Class6.string_19[index1] = Conversions.ToString(Conversions.ToDouble(Conversions.ToString(Class28.oleDbDataReader_0["ID"]).ToString()) + 1.0);
        Class6.string_20[index1] = Conversions.ToString(Class28.oleDbDataReader_0["TP"]).ToString();
        Class6.string_21[index1] = Conversions.ToString(Class28.oleDbDataReader_0["ST"]).ToString();
        Class6.string_22[index1] = Conversions.ToString(Class28.oleDbDataReader_0["NM"]).ToString();
        Class6.string_23[index1] = Conversions.ToString(Class28.oleDbDataReader_0["IT"]).ToString();
        Class6.string_24[index1] = Conversions.ToString(Class28.oleDbDataReader_0["S1"]).ToString();
        checked { ++index1; }
      }
      Class6.string_30 = Conversions.ToString(index1);
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_11();
    try
    {
      Class28.oleDbConnection_0.Open();
      Class28.oleDbCommand_0.Connection = Class28.oleDbConnection_0;
      Class28.oleDbCommand_0.CommandText = "SELECT * FROM [Items - Socket] WHERE (TP<>0 AND TP<>-1 AND TP<>255) ORDER BY Nº;";
      Class28.oleDbCommand_0.ExecuteNonQuery();
      Class28.oleDbDataReader_0 = Class28.oleDbCommand_0.ExecuteReader();
      int index2 = Conversions.ToInteger(Class6.string_30);
      while (Class28.oleDbDataReader_0.Read())
      {
        Class6.string_19[index2] = Conversions.ToString(Conversions.ToDouble(Conversions.ToString(Class28.oleDbDataReader_0["ID"]).ToString()) + 1.0);
        Class6.string_20[index2] = Conversions.ToString(Class28.oleDbDataReader_0["TP"]).ToString();
        Class6.string_21[index2] = Conversions.ToString(Class28.oleDbDataReader_0["ST"]).ToString();
        Class6.string_22[index2] = Conversions.ToString(Class28.oleDbDataReader_0["NM"]).ToString();
        Class6.string_23[index2] = Conversions.ToString(Class28.oleDbDataReader_0["IT"]).ToString();
        Class6.string_24[index2] = Conversions.ToString(Class28.oleDbDataReader_0["S1"]).ToString();
        int index3 = checked (index2 + 1);
        Class6.string_19[index3] = Conversions.ToString(Conversions.ToDouble(Conversions.ToString(Class28.oleDbDataReader_0["ID"]).ToString()) + 51.0);
        Class6.string_20[index3] = Conversions.ToString(Class28.oleDbDataReader_0["TP"]).ToString();
        Class6.string_21[index3] = Conversions.ToString(Class28.oleDbDataReader_0["ST"]).ToString();
        Class6.string_22[index3] = Conversions.ToString(Class28.oleDbDataReader_0["NM"]).ToString();
        Class6.string_23[index3] = Conversions.ToString(Class28.oleDbDataReader_0["IT"]).ToString();
        Class6.string_24[index3] = Conversions.ToString(Class28.oleDbDataReader_0["S2"]).ToString();
        int index4 = checked (index3 + 1);
        Class6.string_19[index4] = Conversions.ToString(Conversions.ToDouble(Conversions.ToString(Class28.oleDbDataReader_0["ID"]).ToString()) + 101.0);
        Class6.string_20[index4] = Conversions.ToString(Class28.oleDbDataReader_0["TP"]).ToString();
        Class6.string_21[index4] = Conversions.ToString(Class28.oleDbDataReader_0["ST"]).ToString();
        Class6.string_22[index4] = Conversions.ToString(Class28.oleDbDataReader_0["NM"]).ToString();
        Class6.string_23[index4] = Conversions.ToString(Class28.oleDbDataReader_0["IT"]).ToString();
        Class6.string_24[index4] = Conversions.ToString(Class28.oleDbDataReader_0["S3"]).ToString();
        int index5 = checked (index4 + 1);
        Class6.string_19[index5] = Conversions.ToString(Conversions.ToDouble(Conversions.ToString(Class28.oleDbDataReader_0["ID"]).ToString()) + 151.0);
        Class6.string_20[index5] = Conversions.ToString(Class28.oleDbDataReader_0["TP"]).ToString();
        Class6.string_21[index5] = Conversions.ToString(Class28.oleDbDataReader_0["ST"]).ToString();
        Class6.string_22[index5] = Conversions.ToString(Class28.oleDbDataReader_0["NM"]).ToString();
        Class6.string_23[index5] = Conversions.ToString(Class28.oleDbDataReader_0["IT"]).ToString();
        Class6.string_24[index5] = Conversions.ToString(Class28.oleDbDataReader_0["S4"]).ToString();
        int index6 = checked (index5 + 1);
        Class6.string_19[index6] = Conversions.ToString(Conversions.ToDouble(Conversions.ToString(Class28.oleDbDataReader_0["ID"]).ToString()) + 201.0);
        Class6.string_20[index6] = Conversions.ToString(Class28.oleDbDataReader_0["TP"]).ToString();
        Class6.string_21[index6] = Conversions.ToString(Class28.oleDbDataReader_0["ST"]).ToString();
        Class6.string_22[index6] = Conversions.ToString(Class28.oleDbDataReader_0["NM"]).ToString();
        Class6.string_23[index6] = Conversions.ToString(Class28.oleDbDataReader_0["IT"]).ToString();
        Class6.string_24[index6] = Conversions.ToString(Class28.oleDbDataReader_0["S5"]).ToString();
        index2 = checked (index6 + 1);
      }
      Class6.string_30 = Conversions.ToString(index2);
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
