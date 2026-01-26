// Decompiled with JetBrains decompiler
// Type: Class17
// Assembly: MuMaker, Version=1.1.3.0, Culture=neutral, PublicKeyToken=null
// MVID: 7E43A6C6-04AF-4159-BD3A-BD25660D1460
// Assembly location: D:\MuServer\Tools\MuMaker 1.13\MuMaker-cleaned.exe

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using System.IO;

[StandardModule]
internal sealed class Class17
{
  public static int int_0 = 10;
  public static int int_1 = 32;

  public static object smethod_0(object object_0)
  {
    string Expression = Strings.Replace(Conversions.ToString(object_0), " ", "", 1, -1, CompareMethod.Binary);
    int num = 0;
    do
    {
      Expression = Strings.Replace(Expression, Conversions.ToString(num), "", 1, -1, CompareMethod.Binary);
      checked { ++num; }
    }
    while (num <= 9);
    object obj = (object) ("Img/Maps/" + Expression + ".mmk");
    if (!new FileInfo(Conversions.ToString(obj)).Exists)
      obj = (object) "Img/Maps/SinFoto.mmk";
    return obj;
  }
}
