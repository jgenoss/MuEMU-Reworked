// Decompiled with JetBrains decompiler
// Type: Class15
// Assembly: MuMaker, Version=1.1.3.0, Culture=neutral, PublicKeyToken=null
// MVID: 7E43A6C6-04AF-4159-BD3A-BD25660D1460
// Assembly location: D:\MuServer\Tools\MuMaker 1.13\MuMaker-cleaned.exe

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using System;
using System.IO;
using System.Runtime.CompilerServices;

[StandardModule]
internal sealed class Class15
{
  public static object smethod_0(object object_0)
  {
    string fileName1 = Conversions.ToString(Operators.ConcatenateObject(Operators.ConcatenateObject((object) "Img\\Items\\", object_0), (object) ".MMK"));
    if (Class24.struct4_0.int_0 > 0)
      fileName1 = Conversions.ToString(Operators.ConcatenateObject(Operators.ConcatenateObject((object) "Img\\Items\\EXE\\", object_0), (object) ".MMK"));
    if (Class24.struct4_0.bool_3)
      fileName1 = Conversions.ToString(Operators.ConcatenateObject(Operators.ConcatenateObject((object) "Img\\Items\\ANC\\", object_0), (object) ".MMK"));
    string str;
    if (new FileInfo(fileName1).Exists)
    {
      str = fileName1;
    }
    else
    {
      string fileName2 = Conversions.ToString(Operators.ConcatenateObject(Operators.ConcatenateObject((object) "Img\\Items\\", object_0), (object) ".MMK"));
      str = !new FileInfo(fileName2).Exists ? "Img\\Items\\SinFoto.MMK" : fileName2;
    }
    Class31.string_1 = str;
    return (object) true;
  }

  public static object smethod_1()
  {
    string fileName1 = "Img\\Items\\" + Class24.struct4_1.string_0 + ".MMK";
    if (Class24.struct4_1.string_19.Length > 1)
      fileName1 = "Img\\Items\\EXE\\" + Class24.struct4_1.string_0 + ".MMK";
    if (Class24.struct4_1.string_16.Length > 1)
      fileName1 = "Img\\Items\\ANC\\" + Class24.struct4_1.string_0 + ".MMK";
    string str1;
    string str2;
    string str3;
    if (new FileInfo(fileName1).Exists)
    {
      str1 = fileName1;
      str2 = fileName1;
      str3 = fileName1;
      Class31.string_5 = fileName1;
    }
    else
    {
      string fileName2 = "Img\\Items\\" + Class24.struct4_1.string_0 + ".MMK";
      if (new FileInfo(fileName2).Exists)
      {
        str1 = fileName2;
        str2 = fileName2;
        str3 = fileName2;
        Class31.string_5 = fileName2;
      }
      else
      {
        str1 = "Img\\Items\\Fondo\\" + Conversions.ToString(Conversions.ToDouble(Class24.struct4_1.string_4) * 32.0) + "x" + Conversions.ToString(Conversions.ToDouble(Class24.struct4_1.string_5) * 32.0) + ".MMK";
        str2 = "Img\\Items\\Fondo\\SinFoto.MMK";
        str3 = "Img\\Items\\Fondo\\" + Conversions.ToString(Conversions.ToDouble(Class24.struct4_1.string_4) * 32.0) + "x" + Conversions.ToString(Conversions.ToDouble(Class24.struct4_1.string_5) * 32.0) + ".MMK";
        Class31.string_5 = "Img\\Items\\Fondo\\SinFoto.MMK";
      }
    }
    Class31.string_2 = str1;
    Class31.string_3 = str2;
    Class31.string_4 = str3;
    Class31.string_5 = Class31.string_5;
    return (object) true;
  }

  public static object smethod_2()
  {
    string str1 = "";
    string str2 = "";
    string str3 = "";
    string str4 = "";
    string str5 = "";
    string str6 = "";
    if (Class24.struct4_0.int_0 > 0)
      str1 = "Excelent ";
    if (Class24.struct4_0.bool_3)
    {
      if (Operators.CompareString(Class24.struct4_0.string_17, "1", false) == 0 && Operators.CompareString(Class24.struct4_2.string_32, "NO", false) != 0)
        str2 = Class24.struct4_2.string_32 + " ";
      if (Operators.CompareString(Class24.struct4_0.string_18, "1", false) == 0 && Operators.CompareString(Class24.struct4_2.string_33, "NO", false) != 0)
        str2 = Class24.struct4_2.string_33 + " ";
    }
    if (Operators.CompareString(Class24.struct4_0.string_9, "0", false) != 0 & Operators.CompareString(Class24.struct4_0.string_9, "00", false) != 0)
    {
      if (Operators.CompareString(Class24.struct4_2.string_9, "SN", false) != 0)
        str3 = "";
      if (Operators.CompareString(Class24.struct4_2.string_9, "NO", false) == 0)
        str3 = "+" + Class24.struct4_0.string_9;
    }
    if (Class24.struct4_0.bool_2 == Conversions.ToBoolean("1"))
      str4 = "+Skill";
    if (Class24.struct4_0.bool_1 == Conversions.ToBoolean("1"))
      str5 = "+Luck";
    if (Operators.CompareString(Class24.struct4_0.string_12, "00", false) != 0)
      str6 = "+Opcion(" + Class24.struct4_0.string_12 + ")";
    return (object) (str1 + str2 + Class24.struct4_2.string_3 + str3 + str4 + str5 + str6);
  }

  public static object smethod_3()
  {
    string str1 = "0";
    string str2 = "0";
    string str3 = "0";
    string str4 = "0";
    string str5 = "00000000";
    string str6 = "0";
    string str7 = "0";
    string str8 = "00";
    string str9 = "00";
    string str10 = "00";
    string str11 = "00";
    string str12 = "00";
    string str13 = Conversion.Hex((object) Class24.struct4_2.string_2);
    if (str13.Length == 1)
      str13 = "0" + str13;
    if (Class24.struct4_0.bool_1 == Conversions.ToBoolean("1"))
      str1 = "4";
    if (Class24.struct4_0.bool_2 == Conversions.ToBoolean("1"))
      str2 = "128";
    if (Operators.CompareString(Class24.struct4_0.string_12, "", false) == 0)
      Class24.struct4_0.bool_0 = false;
    if (Conversions.ToDouble(Class24.struct4_0.string_12) <= 12.0)
    {
      str3 = Conversions.ToString(Conversions.ToDouble(Class24.struct4_0.string_12) / 4.0);
      str4 = "00";
    }
    if (Conversions.ToDouble(Class24.struct4_0.string_12) >= 16.0)
    {
      str3 = Conversions.ToString(Conversions.ToDouble(Class24.struct4_0.string_12) / 4.0 - 4.0);
      str4 = "64";
    }
    string Expression1 = Conversion.Hex((object) Conversions.ToString(Decimal.Add(Decimal.Add(Decimal.Add(new Decimal(Conversions.ToDouble(Class24.struct4_0.string_9) * 8.0), Conversions.ToDecimal(str3)), Conversions.ToDecimal(str1)), Conversions.ToDecimal(str2))));
    if (Strings.Len(Expression1) == 1)
      Expression1 = "0" + Expression1;
    string Expression2 = Conversion.Hex((object) Class24.struct4_0.string_7);
    if (Strings.Len(Expression2) == 1)
      Expression2 = "0" + Expression2;
    if (Class24.struct4_0.string_31.Length == 0)
      str5 = "00000000";
    if (Class24.struct4_0.string_31.Length == 1)
      str5 = "0000000" + Class24.struct4_0.string_31;
    if (Class24.struct4_0.string_31.Length == 2)
      str5 = "000000" + Class24.struct4_0.string_31;
    if (Class24.struct4_0.string_31.Length == 3)
      str5 = "00000" + Class24.struct4_0.string_31;
    if (Class24.struct4_0.string_31.Length == 4)
      str5 = "0000" + Class24.struct4_0.string_31;
    if (Class24.struct4_0.string_31.Length == 5)
      str5 = "000" + Class24.struct4_0.string_31;
    if (Class24.struct4_0.string_31.Length == 6)
      str5 = "00" + Class24.struct4_0.string_31;
    if (Class24.struct4_0.string_31.Length == 7)
      str5 = "0" + Class24.struct4_0.string_31;
    if (Class24.struct4_0.string_31.Length == 8)
      str5 = Class24.struct4_0.string_31;
    string Expression3 = Conversion.Hex((object) Conversions.ToString(Decimal.Add(new Decimal(Class24.struct4_0.int_1), Conversions.ToDecimal(str4))));
    if (Strings.Len(Expression3) == 1)
      Expression3 = "0" + Expression3;
    if (Operators.CompareString(Class24.struct4_0.string_17, "1", false) == 0)
      str7 = "5";
    if (Operators.CompareString(Class24.struct4_0.string_18, "1", false) == 0)
      str7 = "A";
    string str14 = Conversion.Hex((object) Class24.struct4_2.string_1);
    string str15 = Conversions.ToString(Class24.struct4_0.int_2);
    string str16 = Class24.struct4_2.string_23 + Class24.struct4_2.string_24;
    try
    {
      str8 = Class24.struct4_2.string_25;
      if (str8.Length == 0)
        str8 = "00";
      if (str8.Length < 2)
        str8 = "0" + str8;
      str9 = Class24.struct4_2.string_26;
      if (str9.Length == 0)
        str9 = "00";
      if (str9.Length < 2)
        str9 = "0" + str9;
      str10 = Class24.struct4_2.string_27;
      if (str10.Length == 0)
        str10 = "00";
      if (str10.Length < 2)
        str10 = "0" + str10;
      str11 = Class24.struct4_2.string_28;
      if (str11.Length == 0)
        str11 = "00";
      if (str11.Length < 2)
        str11 = "0" + str11;
      str12 = Class24.struct4_2.string_29;
      if (str12.Length == 0)
        str12 = "00";
      if (str12.Length < 2)
        str12 = "0" + str12;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      ProjectData.ClearProjectError();
    }
    return (object) (str13 + Expression1 + Expression2 + str5 + Expression3 + str6 + str7 + str14 + str15 + str16 + str8 + str9 + str10 + str11 + str12);
  }

  public static object smethod_4(object object_0)
  {
    object obj;
    try
    {
      string Left = Strings.Mid(Conversions.ToString(object_0), 18, 1);
      obj = !(Operators.CompareString(Left, "5", false) == 0 | Operators.CompareString(Left, "9", false) == 0 | Operators.CompareString(Left, "A", false) == 0) ? (object) "" : (object) "Ancient ";
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) "(ERROR) Ancient ";
      ProjectData.ClearProjectError();
    }
    return obj;
  }

  public static object smethod_5(object object_0)
  {
    object obj;
    try
    {
      string str = Conversions.ToString(Conversion.Val("&H" + Strings.Mid(Conversions.ToString(object_0), 15, 2)));
      obj = (object) "";
      if (Conversions.ToDouble(str) >= 128.0)
        str = Conversions.ToString(Conversions.ToDouble(str) - 128.0);
      if (Conversions.ToDouble(str) >= 64.0)
        str = Conversions.ToString(Conversions.ToDouble(str) - 64.0);
      if (Conversions.ToDouble(str) >= 32.0)
      {
        str = Conversions.ToString(Conversions.ToDouble(str) - 32.0);
        obj = (object) "Excelent ";
      }
      if (Conversions.ToDouble(str) >= 16.0)
      {
        str = Conversions.ToString(Conversions.ToDouble(str) - 16.0);
        obj = (object) "Excelent ";
      }
      if (Conversions.ToDouble(str) >= 8.0)
      {
        str = Conversions.ToString(Conversions.ToDouble(str) - 8.0);
        obj = (object) "Excelent ";
      }
      if (Conversions.ToDouble(str) >= 4.0)
      {
        str = Conversions.ToString(Conversions.ToDouble(str) - 4.0);
        obj = (object) "Excelent ";
      }
      if (Conversions.ToDouble(str) >= 2.0)
      {
        str = Conversions.ToString(Conversions.ToDouble(str) - 2.0);
        obj = (object) "Excelent ";
      }
      if (Conversions.ToDouble(str) > 0.0)
        obj = (object) "Excelent ";
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) "(ERROR) Excelent ";
      ProjectData.ClearProjectError();
    }
    return obj;
  }

  public static object smethod_6(object object_0)
  {
    string str1 = "";
    string str2 = "";
    string str3 = "";
    string str4 = "";
    string str5 = "";
    string str6 = "";
    string str7 = "";
    string str8 = "";
    string str9 = "";
    string str10 = "";
    string str11 = "";
    string str12 = "";
    string str13 = "";
    string str14 = "";
    string str15 = "";
    string str16 = "";
    string str17 = "";
    string str18 = "";
    string str19 = "";
    string str20 = "";
    string str21 = "";
    string str22 = "";
    string str23 = "";
    string str24 = "";
    string str25 = "";
    string str26 = "";
    string str27 = "";
    string str28 = "";
    string str29 = "";
    string str30 = "";
    string str31 = "";
    string str32 = "";
    string str33 = "";
    string str34 = "";
    string str35 = "";
    string str36 = "";
    object obj;
    try
    {
      string str37 = Conversions.ToString(Conversion.Val("&H" + Strings.Mid(Conversions.ToString(object_0), 15, 2)));
      if (Conversions.ToDouble(str37) >= 128.0)
        str37 = Conversions.ToString(Conversions.ToDouble(str37) - 128.0);
      if (Conversions.ToDouble(str37) >= 64.0)
        str37 = Conversions.ToString(Conversions.ToDouble(str37) - 64.0);
      if (Conversions.ToDouble(str37) >= 32.0)
      {
        str37 = Conversions.ToString(Conversions.ToDouble(str37) - 32.0);
        string str38 = Conversions.ToString(Class30.object_33);
        string str39 = Conversions.ToString(Class30.object_39);
        string str40 = Conversions.ToString(Class30.object_45);
        string str41 = Conversions.ToString(Class30.object_51);
        string str42 = Conversions.ToString(Class30.object_34);
        string str43 = Conversions.ToString(Class30.object_28);
        str31 = str31 + "\n * " + str38;
        str32 = str32 + "\n * " + str39;
        str33 = str33 + "\n * " + str40;
        str34 = str34 + "\n * " + str41;
        str35 = str35 + "\n * " + str42;
        str36 = str36 + "\n * " + str43;
      }
      if (Conversions.ToDouble(str37) >= 16.0)
      {
        str37 = Conversions.ToString(Conversions.ToDouble(str37) - 16.0);
        string str38 = Conversions.ToString(Class30.object_32);
        string str39 = Conversions.ToString(Class30.object_38);
        string str40 = Conversions.ToString(Class30.object_44);
        string str41 = Conversions.ToString(Class30.object_50);
        string str42 = Conversions.ToString(Class30.object_35);
        string str43 = Conversions.ToString(Class30.object_29);
        str25 = str25 + "\n * " + str38;
        str26 = str26 + "\n * " + str39;
        str27 = str27 + "\n * " + str40;
        str28 = str28 + "\n * " + str41;
        str29 = str29 + "\n * " + str42;
        str30 = str30 + "\n * " + str43;
      }
      if (Conversions.ToDouble(str37) >= 8.0)
      {
        str37 = Conversions.ToString(Conversions.ToDouble(str37) - 8.0);
        string str38 = Conversions.ToString(Class30.object_31);
        string str39 = Conversions.ToString(Class30.object_37);
        string str40 = Conversions.ToString(Class30.object_43);
        string str41 = Conversions.ToString(Class30.object_49);
        string str42 = Conversions.ToString(Class30.object_36);
        string str43 = Conversions.ToString(Class30.object_30);
        str19 = str19 + "\n * " + str38;
        str20 = str20 + "\n * " + str39;
        str21 = str21 + "\n * " + str40;
        str22 = str22 + "\n * " + str41;
        str23 = str23 + "\n * " + str42;
        str24 = str24 + "\n * " + str43;
      }
      if (Conversions.ToDouble(str37) >= 4.0)
      {
        str37 = Conversions.ToString(Conversions.ToDouble(str37) - 4.0);
        string str38 = Conversions.ToString(Class30.object_30);
        string str39 = Conversions.ToString(Class30.object_36);
        string str40 = Conversions.ToString(Class30.object_42);
        string str41 = Conversions.ToString(Class30.object_48);
        string str42 = Conversions.ToString(Class30.object_37);
        string str43 = Conversions.ToString(Class30.object_31);
        str13 = str13 + "\n * " + str38;
        str14 = str14 + "\n * " + str39;
        str15 = str15 + "\n * " + str40;
        str16 = str16 + "\n * " + str41;
        str17 = str17 + "\n * " + str42;
        str18 = str18 + "\n * " + str43;
      }
      if (Conversions.ToDouble(str37) >= 2.0)
      {
        str37 = Conversions.ToString(Conversions.ToDouble(str37) - 2.0);
        string str38 = Conversions.ToString(Class30.object_29);
        string str39 = Conversions.ToString(Class30.object_35);
        string str40 = Conversions.ToString(Class30.object_41);
        string str41 = Conversions.ToString(Class30.object_47);
        string str42 = Conversions.ToString(Class30.object_38);
        string str43 = Conversions.ToString(Class30.object_32);
        str7 = str7 + "\n * " + str38;
        str8 = str8 + "\n * " + str39;
        str9 = str9 + "\n * " + str40;
        str10 = str10 + "\n * " + str41;
        str11 = str11 + "\n * " + str42;
        str12 = str12 + "\n * " + str43;
      }
      if (Conversions.ToDouble(str37) > 0.0)
      {
        string str38 = Conversions.ToString(Class30.object_28);
        string str39 = Conversions.ToString(Class30.object_34);
        string str40 = Conversions.ToString(Class30.object_40);
        string str41 = Conversions.ToString(Class30.object_46);
        string str42 = Conversions.ToString(Class30.object_39);
        string str43 = Conversions.ToString(Class30.object_33);
        str1 = str1 + "\n * " + str38;
        str2 = str2 + "\n * " + str39;
        str3 = str3 + "\n * " + str40;
        str4 = str4 + "\n * " + str41;
        str5 = str5 + "\n * " + str42;
        str6 = str6 + "\n * " + str43;
      }
      obj = (object) "\n [EXE] \n--------------------\n";
      if (Class24.struct4_1.int_0 == 0)
        obj = (object) "\n [EXE] \n--------------------\n";
      if (Class24.struct4_1.int_0 == 1)
        obj = (object) ("\n [EXE] " + str1 + str7 + str13 + str19 + str25 + str31 + "\n");
      if (Class24.struct4_1.int_0 == 2)
        obj = (object) ("\n [EXE] " + str2 + str8 + str14 + str20 + str26 + str32 + "\n");
      if (Class24.struct4_1.int_0 == 3)
        obj = (object) ("\n [EXE] " + str3 + str9 + str15 + str21 + str27 + str33 + "\n");
      if (Class24.struct4_1.int_0 == 4)
        obj = (object) ("\n [EXE] " + str4 + str10 + str16 + str22 + str28 + str34 + "\n");
      if (Class24.struct4_1.int_0 == 5)
        obj = (object) ("\n [EXE] " + str5 + str11 + str17 + str23 + str29 + str35 + "\n");
      if (Class24.struct4_1.int_0 == 6)
        obj = (object) ("\n [EXE] " + str6 + str12 + str18 + str24 + str30 + str36 + "\n");
      if (obj.ToString().Length == 9)
        obj = (object) "\n [EXE] \n--------------------\n";
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) "\n [EXE] \n---E--R--R--O--R---\n";
      ProjectData.ClearProjectError();
    }
    return obj;
  }

  public static object smethod_7(object object_0)
  {
    object obj;
    try
    {
      string str = Conversions.ToString(Conversion.Val("&H" + Strings.Mid(Conversions.ToString(object_0), 3, 2)));
      obj = (object) "+00";
      if (Conversions.ToDouble(str) >= 128.0)
        str = Conversions.ToString(Conversions.ToDouble(str) - 128.0);
      if (Conversions.ToDouble(str) >= 120.0)
      {
        str = Conversions.ToString(0);
        obj = (object) "+15";
      }
      if (Conversions.ToDouble(str) >= 112.0)
      {
        str = Conversions.ToString(0);
        obj = (object) "+14";
      }
      if (Conversions.ToDouble(str) >= 104.0)
      {
        str = Conversions.ToString(0);
        obj = (object) "+13";
      }
      if (Conversions.ToDouble(str) >= 96.0)
      {
        str = Conversions.ToString(0);
        obj = (object) "+12";
      }
      if (Conversions.ToDouble(str) >= 88.0)
      {
        str = Conversions.ToString(0);
        obj = (object) "+11";
      }
      if (Conversions.ToDouble(str) >= 80.0)
      {
        str = Conversions.ToString(0);
        obj = (object) "+10";
      }
      if (Conversions.ToDouble(str) >= 72.0)
      {
        str = Conversions.ToString(0);
        obj = (object) "+09";
      }
      if (Conversions.ToDouble(str) >= 64.0)
      {
        str = Conversions.ToString(0);
        obj = (object) "+08";
      }
      if (Conversions.ToDouble(str) >= 56.0)
      {
        str = Conversions.ToString(0);
        obj = (object) "+07";
      }
      if (Conversions.ToDouble(str) >= 48.0)
      {
        str = Conversions.ToString(0);
        obj = (object) "+06";
      }
      if (Conversions.ToDouble(str) >= 40.0)
      {
        str = Conversions.ToString(0);
        obj = (object) "+05";
      }
      if (Conversions.ToDouble(str) >= 32.0)
      {
        str = Conversions.ToString(0);
        obj = (object) "+04";
      }
      if (Conversions.ToDouble(str) >= 24.0)
      {
        str = Conversions.ToString(0);
        obj = (object) "+03";
      }
      if (Conversions.ToDouble(str) >= 16.0)
      {
        str = Conversions.ToString(0);
        obj = (object) "+02";
      }
      if (Conversions.ToDouble(str) >= 8.0)
      {
        str = Conversions.ToString(0);
        obj = (object) "+01";
      }
      if (Conversions.ToDouble(str) > 0.0)
      {
        Conversions.ToString(0);
        obj = (object) "+00";
      }
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) "+00";
      ProjectData.ClearProjectError();
    }
    return obj;
  }

  public static object smethod_8(object object_0)
  {
    string str1 = "";
    object obj;
    try
    {
      string str2 = Conversions.ToString(Conversion.Val("&H" + Strings.Mid(Conversions.ToString(object_0), 4, 1)));
      string str3 = Conversions.ToString(Conversion.Val("&H" + Strings.Mid(Conversions.ToString(object_0), 15, 1)));
      obj = (object) "";
      if (Conversions.ToDouble(str2) >= 12.0)
        str2 = Conversions.ToString(Conversions.ToDouble(str2) - 12.0);
      if (Conversions.ToDouble(str2) >= 8.0)
        str2 = Conversions.ToString(Conversions.ToDouble(str2) - 8.0);
      if (Conversions.ToDouble(str2) >= 4.0)
        str2 = Conversions.ToString(Conversions.ToDouble(str2) - 4.0);
      if (Conversions.ToDouble(str3) >= 12.0 & Conversions.ToDouble(str3) <= 15.0)
        str3 = Conversions.ToString(1);
      if (Conversions.ToDouble(str3) >= 4.0 & Conversions.ToDouble(str3) <= 7.0)
        str3 = Conversions.ToString(1);
      if (Conversions.ToDouble(str2) == 0.0)
        str1 = "";
      if (Conversions.ToDouble(str2) == 1.0)
        str1 = "+4";
      if (Conversions.ToDouble(str2) == 2.0)
        str1 = "+8";
      if (Conversions.ToDouble(str2) == 3.0)
        str1 = "+12";
      if (Conversions.ToDouble(str2) == 0.0 & Conversions.ToDouble(str3) == 1.0)
        str1 = "+16";
      if (Conversions.ToDouble(str2) == 1.0 & Conversions.ToDouble(str3) == 1.0)
        str1 = "+20";
      if (Conversions.ToDouble(str2) == 2.0 & Conversions.ToDouble(str3) == 1.0)
        str1 = "+24";
      if (Conversions.ToDouble(str2) == 3.0 & Conversions.ToDouble(str3) == 1.0)
        str1 = "+28";
      if (Conversions.ToDouble(str2) > 0.0 & Conversions.ToDouble(str2) <= 3.0 | Conversions.ToDouble(str2) >= 0.0 & Conversions.ToDouble(str2) <= 3.0 & Conversions.ToDouble(str3) == 1.0 | Conversions.ToDouble(str3) == 1.0)
        obj = (object) ("+Option(" + str1 + ")");
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) "+Option(ERROR)";
      ProjectData.ClearProjectError();
    }
    return obj;
  }

  public static object smethod_9(object object_0)
  {
    object obj = (object) "";
    try
    {
      string str = Conversions.ToString(Conversion.Val("&H" + Strings.Mid(Conversions.ToString(object_0), 3, 1)));
      if (Conversions.ToDouble(str) >= 8.0 & Conversions.ToDouble(str) <= 9.0 | Conversions.ToDouble(str) >= 10.0 & Conversions.ToDouble(str) <= 15.0)
        obj = (object) "+Skill";
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) "+Skill (ERROR)";
      ProjectData.ClearProjectError();
    }
    return obj;
  }

  public static object smethod_10(object object_0)
  {
    object obj = (object) "";
    try
    {
      string str = Conversions.ToString(Conversion.Val("&H" + Strings.Mid(Conversions.ToString(object_0), 4, 1)));
      if (Conversions.ToDouble(str) >= 4.0 & Conversions.ToDouble(str) <= 7.0 | Conversions.ToDouble(str) >= 12.0 & Conversions.ToDouble(str) <= 15.0)
        obj = (object) "+Luck";
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) "+Luck (ERROR)";
      ProjectData.ClearProjectError();
    }
    return obj;
  }

  public static object smethod_11(object object_0)
  {
    string str1 = "";
    string str2 = "";
    Class24.struct4_1.string_21 = "\n [RF lvl 380] \n";
    object obj;
    try
    {
      if (Conversions.ToDouble(Strings.Mid(Conversions.ToString(object_0), 20, 1)) == 8.0)
      {
        if (Class24.struct4_1.int_2 == 0)
        {
          str1 = Conversions.ToString(Class30.object_58);
          str2 = Conversions.ToString(Class30.object_59);
        }
        if (Class24.struct4_1.int_2 == 1)
        {
          str1 = Conversions.ToString(Class30.object_60);
          str2 = Conversions.ToString(Class30.object_61);
        }
        if (Class24.struct4_1.int_2 == 2)
        {
          str1 = Conversions.ToString(Class30.object_62);
          str2 = Conversions.ToString(Class30.object_63);
        }
        if (Class24.struct4_1.int_2 == 3)
        {
          str1 = Conversions.ToString(Class30.object_64);
          str2 = Conversions.ToString(Class30.object_65);
        }
        if (Class24.struct4_1.int_2 == 4)
        {
          str1 = Conversions.ToString(Class30.object_66);
          str2 = Conversions.ToString(Class30.object_67);
        }
        if (Class24.struct4_1.int_2 == 5)
        {
          str1 = Conversions.ToString(Class30.object_68);
          str2 = Conversions.ToString(Class30.object_69);
        }
        if (Class24.struct4_1.int_2 == 6)
        {
          str1 = Conversions.ToString(Class30.object_70);
          str2 = Conversions.ToString(Class30.object_71);
        }
        Class24.struct4_1.string_21 = Class24.struct4_1.string_21 + str1 + "\n" + str2;
        goto label_20;
      }
      else
      {
        Class24.struct4_1.string_21 = Class24.struct4_1.string_21 + "--------------------";
        goto label_20;
      }
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      Class24.struct4_1.string_21 = "\n [RF lvl 380] \n";
      Class24.struct4_1.string_21 = Class24.struct4_1.string_21 + "--------------------";
      obj = (object) Class24.struct4_1.string_21;
      ProjectData.ClearProjectError();
    }
    return obj;
label_20:
    return (object) Class24.struct4_1.string_21;
  }

  public static object smethod_12(object object_0)
  {
    Class24.struct4_1.string_22 = "\n [JoH] \n";
    if (((double) Class24.struct4_1.int_3 == Conversions.ToDouble("1") | (double) Class24.struct4_1.int_3 == Conversions.ToDouble("2") | (double) Class24.struct4_1.int_3 == Conversions.ToDouble("3")) & Operators.CompareString(Strings.Mid(Conversions.ToString(object_0), 21, 2), "00", false) != 0)
    {
      Class7.smethod_10();
      try
      {
        Class28.oleDbConnection_0.Open();
        Class28.oleDbCommand_0.Connection = Class28.oleDbConnection_0;
        Class28.oleDbCommand_0.CommandText = "SELECT * FROM [Items - JewelOfHarmony] WHERE TP='" + Conversions.ToString(Class24.struct4_1.int_3) + "' AND ID='" + Strings.Mid(Conversions.ToString(object_0), 21, 1) + "';";
        Class28.oleDbCommand_0.ExecuteNonQuery();
        Class28.oleDbDataReader_0 = Class28.oleDbCommand_0.ExecuteReader();
        Class28.oleDbDataReader_0.Read();
        Class24.struct4_1.string_22 = Class24.struct4_1.string_22 + Conversions.ToString(Class28.oleDbDataReader_0["NM"]);
        Class24.struct4_1.string_22 = Class24.struct4_1.string_22 + " " + Conversions.ToString(Class28.oleDbDataReader_0[Strings.Mid(Conversions.ToString(object_0), 22, 1)]);
        Class28.oleDbDataReader_0.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      Class7.smethod_11();
    }
    else
      Class24.struct4_1.string_22 = Class24.struct4_1.string_22 + "--------------------";
    return (object) Class24.struct4_1.string_22;
  }

  public static object smethod_13(object object_0)
  {
    string Left1 = "";
    string Left2 = "";
    string Left3 = "";
    string Left4 = "";
    string Left5 = "";
    long num1 = checked ((long) Math.Round(Conversion.Val("&H" + Strings.Mid(Conversions.ToString(object_0), 23, 10))));
    int num2 = checked ((int) Math.Round(Conversion.Val("&H" + Strings.Mid(Conversions.ToString(object_0), 23, 2))));
    int num3 = checked ((int) Math.Round(Conversion.Val("&H" + Strings.Mid(Conversions.ToString(object_0), 25, 2))));
    int num4 = checked ((int) Math.Round(Conversion.Val("&H" + Strings.Mid(Conversions.ToString(object_0), 27, 2))));
    int num5 = checked ((int) Math.Round(Conversion.Val("&H" + Strings.Mid(Conversions.ToString(object_0), 29, 2))));
    int num6 = checked ((int) Math.Round(Conversion.Val("&H" + Strings.Mid(Conversions.ToString(object_0), 31, 2))));
    object obj;
    if (num1 > 0L)
    {
      int num7 = 1;
      int num8 = Conversions.ToInteger(Class6.string_30);
      int num9 = num7;
      while (num9 <= num8)
      {
        if (Conversions.ToDouble(Class6.string_19[checked (num9 - 1)]) == (double) num2)
          Left1 = "Socket 1 : " + Class6.string_21[checked (num9 - 1)] + " (" + Class6.string_22[checked (num9 - 1)] + ") + " + Class6.string_24[checked (num9 - 1)] + "\n";
        if (Conversions.ToDouble(Class6.string_19[checked (num9 - 1)]) == (double) num3)
          Left2 = "Socket 2 : " + Class6.string_21[checked (num9 - 1)] + " (" + Class6.string_22[checked (num9 - 1)] + ") + " + Class6.string_24[checked (num9 - 1)] + "\n";
        if (Conversions.ToDouble(Class6.string_19[checked (num9 - 1)]) == (double) num4)
          Left3 = "Socket 3 : " + Class6.string_21[checked (num9 - 1)] + " (" + Class6.string_22[checked (num9 - 1)] + ") + " + Class6.string_24[checked (num9 - 1)] + "\n";
        if (Conversions.ToDouble(Class6.string_19[checked (num9 - 1)]) == (double) num5)
          Left4 = "Socket 4 : " + Class6.string_21[checked (num9 - 1)] + " (" + Class6.string_22[checked (num9 - 1)] + ") + " + Class6.string_24[checked (num9 - 1)] + "\n";
        if (Conversions.ToDouble(Class6.string_19[checked (num9 - 1)]) == (double) num6)
          Left5 = "Socket 5 : " + Class6.string_21[checked (num9 - 1)] + " (" + Class6.string_22[checked (num9 - 1)] + ") + " + Class6.string_24[checked (num9 - 1)] + "\n";
        if (num2 == 0 | num2 == (int) byte.MaxValue)
          Left1 = "";
        if (num3 == 0 | num3 == (int) byte.MaxValue)
          Left2 = "";
        if (num4 == 0 | num4 == (int) byte.MaxValue)
          Left3 = "";
        if (num5 == 0 | num5 == (int) byte.MaxValue)
          Left4 = "";
        if (num6 == 0 | num6 == (int) byte.MaxValue)
          Left5 = "";
        checked { ++num9; }
      }
      obj = (object) ("\n [Socket System] \n" + Left1 + Left2 + Left3 + Left4 + Left5 + "\n");
      if (Operators.CompareString(Left1, "", false) == 0 & Operators.CompareString(Left2, "", false) == 0 & Operators.CompareString(Left3, "", false) == 0 & Operators.CompareString(Left4, "", false) == 0 & Operators.CompareString(Left5, "", false) == 0)
        obj = (object) "\n [Socket System] \n--------------------\n";
    }
    else
      obj = (object) "\n [Socket System] \n--------------------\n";
    return obj;
  }

  public static object smethod_14()
  {
    object obj;
    try
    {
      if (Operators.CompareString(Class24.struct4_2.string_7, "000", false) != 0 & Operators.CompareString(Class24.struct4_2.string_7, "255", false) != 0 & Operators.CompareString(Class24.struct4_2.string_7, "001", false) != 0)
      {
        if (Operators.CompareString(Class24.struct4_0.string_7, "", false) == 0)
          Class24.struct4_0.string_7 = Conversions.ToString(0);
        Class24.struct4_0.string_7 = Class24.struct4_2.string_7;
        if (Conversions.ToDouble(Class24.struct4_0.string_9) == 15.0)
          Class24.struct4_0.string_7 = Conversions.ToString(Decimal.Add(Conversions.ToDecimal(Class24.struct4_0.string_7), new Decimal(44L)));
        if (Conversions.ToDouble(Class24.struct4_0.string_9) == 14.0)
          Class24.struct4_0.string_7 = Conversions.ToString(Decimal.Add(Conversions.ToDecimal(Class24.struct4_0.string_7), new Decimal(38L)));
        if (Conversions.ToDouble(Class24.struct4_0.string_9) == 13.0)
          Class24.struct4_0.string_7 = Conversions.ToString(Decimal.Add(Conversions.ToDecimal(Class24.struct4_0.string_7), new Decimal(32L)));
        if (Conversions.ToDouble(Class24.struct4_0.string_9) == 12.0)
          Class24.struct4_0.string_7 = Conversions.ToString(Decimal.Add(Conversions.ToDecimal(Class24.struct4_0.string_7), new Decimal(26L)));
        if (Conversions.ToDouble(Class24.struct4_0.string_9) == 11.0)
          Class24.struct4_0.string_7 = Conversions.ToString(Decimal.Add(Conversions.ToDecimal(Class24.struct4_0.string_7), new Decimal(20L)));
        if (Conversions.ToDouble(Class24.struct4_0.string_9) == 10.0)
          Class24.struct4_0.string_7 = Conversions.ToString(Decimal.Add(Conversions.ToDecimal(Class24.struct4_0.string_7), new Decimal(17L)));
        if (Conversions.ToDouble(Class24.struct4_0.string_9) == 9.0)
          Class24.struct4_0.string_7 = Conversions.ToString(Decimal.Add(Conversions.ToDecimal(Class24.struct4_0.string_7), new Decimal(14L)));
        if (Conversions.ToDouble(Class24.struct4_0.string_9) == 8.0)
          Class24.struct4_0.string_7 = Conversions.ToString(Decimal.Add(Conversions.ToDecimal(Class24.struct4_0.string_7), new Decimal(12L)));
        if (Conversions.ToDouble(Class24.struct4_0.string_9) == 7.0)
          Class24.struct4_0.string_7 = Conversions.ToString(Decimal.Add(Conversions.ToDecimal(Class24.struct4_0.string_7), new Decimal(10L)));
        if (Conversions.ToDouble(Class24.struct4_0.string_9) == 6.0)
          Class24.struct4_0.string_7 = Conversions.ToString(Decimal.Add(Conversions.ToDecimal(Class24.struct4_0.string_7), new Decimal(8L)));
        if (Conversions.ToDouble(Class24.struct4_0.string_9) == 5.0)
          Class24.struct4_0.string_7 = Conversions.ToString(Decimal.Add(Conversions.ToDecimal(Class24.struct4_0.string_7), new Decimal(6L)));
        if (Conversions.ToDouble(Class24.struct4_0.string_9) == 4.0)
          Class24.struct4_0.string_7 = Conversions.ToString(Decimal.Add(Conversions.ToDecimal(Class24.struct4_0.string_7), new Decimal(4L)));
        if (Conversions.ToDouble(Class24.struct4_0.string_9) == 3.0)
          Class24.struct4_0.string_7 = Conversions.ToString(Decimal.Add(Conversions.ToDecimal(Class24.struct4_0.string_7), new Decimal(3L)));
        if (Conversions.ToDouble(Class24.struct4_0.string_9) == 2.0)
          Class24.struct4_0.string_7 = Conversions.ToString(Decimal.Add(Conversions.ToDecimal(Class24.struct4_0.string_7), new Decimal(2L)));
        if (Conversions.ToDouble(Class24.struct4_0.string_9) == 1.0)
          Class24.struct4_0.string_7 = Conversions.ToString(Decimal.Add(Conversions.ToDecimal(Class24.struct4_0.string_7), Decimal.One));
        if (Conversions.ToDouble(Class24.struct4_0.string_9) == 0.0)
          Class24.struct4_0.string_7 = Conversions.ToString(Decimal.Add(Conversions.ToDecimal(Class24.struct4_0.string_7), Decimal.Zero));
        if (Class24.struct4_0.int_0 > 0)
          Class24.struct4_0.string_7 = Conversions.ToString(Conversions.ToDouble(Class24.struct4_0.string_7) + 15.0);
        if (Class24.struct4_0.bool_3)
          Class24.struct4_0.string_7 = Conversions.ToString(Conversions.ToDouble(Class24.struct4_0.string_7) + 20.0);
        if (Conversions.ToDouble(Class24.struct4_0.string_7) > (double) byte.MaxValue)
          Class24.struct4_0.string_7 = Conversions.ToString((int) byte.MaxValue);
        if (Class24.struct4_0.string_7.Length < 3)
          Class24.struct4_0.string_7 = "0" + Class24.struct4_0.string_7;
      }
      else if (Operators.CompareString(Class24.struct4_2.string_7, "001", false) == 0)
      {
        Class24.struct4_0.string_7 = Class24.struct4_2.string_8;
      }
      else
      {
        Class24.struct4_0.string_7 = Class24.struct4_2.string_7;
        Class24.struct4_2.string_8 = "001";
      }
      if (Operators.CompareString(Class24.struct4_0.string_7, "", false) == 0)
        Class24.struct4_0.string_7 = Conversions.ToString(0);
      obj = (object) true;
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      obj = (object) false;
      ProjectData.ClearProjectError();
    }
    return obj;
  }

  public static object smethod_15()
  {
    VBMath.Randomize();
    object Right = (object) Conversion.Hex(RuntimeHelpers.GetObjectValue((object) Conversion.Int((float) uint.MaxValue * VBMath.Rnd())));
    if (Right.ToString().Length == 0)
      Right = (object) "00000000";
    if (Right.ToString().Length == 1)
      Right = Operators.ConcatenateObject((object) "0000000", Right);
    if (Right.ToString().Length == 2)
      Right = Operators.ConcatenateObject((object) "000000", Right);
    if (Right.ToString().Length == 3)
      Right = Operators.ConcatenateObject((object) "00000", Right);
    if (Right.ToString().Length == 4)
      Right = Operators.ConcatenateObject((object) "0000", Right);
    if (Right.ToString().Length == 5)
      Right = Operators.ConcatenateObject((object) "000", Right);
    if (Right.ToString().Length == 6)
      Right = Operators.ConcatenateObject((object) "00", Right);
    if (Right.ToString().Length == 7)
      Right = Operators.ConcatenateObject((object) "0", Right);
    if (Right.ToString().Length == 8)
      Right = RuntimeHelpers.GetObjectValue(Right);
    return Right;
  }
}
