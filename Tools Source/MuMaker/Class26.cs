// Decompiled with JetBrains decompiler
// Type: Class26
// Assembly: MuMaker, Version=1.1.3.0, Culture=neutral, PublicKeyToken=null
// MVID: 7E43A6C6-04AF-4159-BD3A-BD25660D1460
// Assembly location: D:\MuServer\Tools\MuMaker 1.13\MuMaker-cleaned.exe

using Microsoft.VisualBasic.CompilerServices;
using System;

[StandardModule]
internal sealed class Class26
{
  public static string string_0 = "1.13";
  public static string string_1 = "1.07K";
  public static string string_2 = "1.03H";
  public static string string_3 = "1.03K";
  public static object object_0 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/UPDT.INI", "Info", "Version", Class26.string_0);
  public static string string_4 = Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/UPDT.INI", "Info", "Info", "!! No Info !!");
  public static string string_5 = "";
  public static object object_1 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "RPW", "0");
  public static object object_2 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "Usuario", "sa");
  public static object object_3 = (object) Class18.smethod_8(Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "PassWord", ""));
  public static object object_4 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "Connection", "Local");
  public static object object_5 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "IPServer", "127.0.0.1");
  public static object object_6 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "PORTServer", "1433");
  public static object object_7 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "MuOnline", "MuOnline");
  public static object object_8 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "MuRanking", "MuRanking");
  public static object object_9 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "MuEvent", "MuEvent");
  public static object object_10 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "ExtWareHouse", "ExtWareHouse");
  public static object object_11 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "Reset", "Resets");
  public static int int_0 = Conversions.ToInteger(Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "TimeLimit", Conversions.ToString(360)));
  public static object object_12 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "Languaje", "Espanol");
  public static object object_13 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "NuExtraWareHouses", "0");
  public static object object_14 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "Reset", "0");
  public static object object_15 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "MD5", "0");
  public static object object_16 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "FirstLoad", "0");
  public static object object_17 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "AutoReLoad", "0");
  public static object object_18 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "Personal", "Name", "N00B");
  public static object object_19 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "Personal", "DIAS", "30");
  public static object object_20 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "Personal", "PJ", "1");
  public static object object_21 = (object) Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "FX", "Top", "0");

  public static object smethod_0()
  {
    try
    {
      if (Operators.CompareString(Class26.string_5, "00000000", false) == 0 | Operators.CompareString(Class26.string_5, "", false) == 0)
        Class26.string_5 = Class18.smethod_9();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      Class26.string_5 = "00000000";
      ProjectData.ClearProjectError();
    }
    return (object) true;
  }
}
