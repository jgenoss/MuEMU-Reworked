// Decompiled with JetBrains decompiler
// Type: Class19
// Assembly: MuMaker, Version=1.1.3.0, Culture=neutral, PublicKeyToken=null
// MVID: 7E43A6C6-04AF-4159-BD3A-BD25660D1460
// Assembly location: D:\MuServer\Tools\MuMaker 1.13\MuMaker-cleaned.exe

using Microsoft.VisualBasic.CompilerServices;
using System.IO;

[StandardModule]
internal sealed class Class19
{
  public static object smethod_0(object object_0)
  {
    string fileName = Conversions.ToString(Operators.ConcatenateObject(Operators.ConcatenateObject((object) "Img\\Skills\\", object_0), (object) ".MMK"));
    Class33.string_0 = !new FileInfo(fileName).Exists ? "Img\\Skills\\000000.MMK" : fileName;
    return (object) true;
  }

  public static object smethod_1()
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
      if (Operators.CompareString(Class24.struct4_2.string_33, "NO", false) != 0)
        str2 = Class24.struct4_2.string_33 + " ";
      if (Operators.CompareString(Class24.struct4_2.string_32, "NO", false) != 0)
        str2 = Class24.struct4_2.string_32 + " ";
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

  public static object smethod_2()
  {
    return (object) true;
  }
}
