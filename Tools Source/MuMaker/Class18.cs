using JRO;
using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using MuMaker;
using System;
using System.Drawing;
using System.IO;
using System.Management;
using System.Runtime.InteropServices;

[StandardModule]
internal sealed class Class18
{
    [DllImport("kernel32", CharSet = CharSet.Ansi, SetLastError = true, ExactSpelling = true)]
    private static extern int GetPrivateProfileStringA([MarshalAs(UnmanagedType.VBByRefStr)] ref string string_0, [MarshalAs(UnmanagedType.VBByRefStr)] ref string string_1, [MarshalAs(UnmanagedType.VBByRefStr)] ref string string_2, [MarshalAs(UnmanagedType.VBByRefStr)] ref string string_3, int int_0, [MarshalAs(UnmanagedType.VBByRefStr)] ref string string_4);
    public static object smethod_0(string string_0, string string_1)
    {
        StreamReader reader = new StreamReader("Lang/" + string_0 + ".ini");
        string str = reader.ReadLine();
        while ((str != null) & (Strings.Mid(str, 1, string_1.Length) != string_1))
        {
            str = reader.ReadLine();
        }
        reader.Close();
        return Strings.Mid(str, string_1.Length + 2);
    }

    public static string smethod_1(string string_0, string string_1, string string_2, string string_3 = "")
    {
        string str = new string('\0', 0xff);
        int length = GetPrivateProfileStringA(ref string_1, ref string_2, ref string_3, ref str, Strings.Len(str), ref string_0);
        if (length == 0)
        {
            return string_3;
        }
        return Strings.Left(str, length);
    }

    private static string smethod_10(string string_0, string string_1, string string_2)
    {
        string str = "";
        ManagementObjectCollection instances = new ManagementClass(string_0).GetInstances();
        foreach (ManagementObject obj2 in instances)
        {
            if ((obj2[string_2].ToString() == "True") && (str == ""))
            {
                try
                {
                    return obj2[string_1].ToString();
                }
                catch (Exception exception1)
                {
                    ProjectData.SetProjectError(exception1);
                    ProjectData.ClearProjectError();
                }
            }
        }
        return str;
    }

    private static string smethod_11(string string_0, string string_1)
    {
        string str = "";
        ManagementObjectCollection instances = new ManagementClass(string_0).GetInstances();
        foreach (ManagementObject obj2 in instances)
        {
            if (str == "")
            {
                try
                {
                    return obj2[string_1].ToString();
                }
                catch (Exception exception1)
                {
                    ProjectData.SetProjectError(exception1);
                    ProjectData.ClearProjectError();
                }
            }
        }
        return str;
    }

    private static string smethod_12()
    {
        string str = smethod_11("Win32_Processor", "UniqueId");
        if (str != "")
        {
            return str;
        }
        str = smethod_11("Win32_Processor", "ProcessorId");
        if (str != "")
        {
            return str;
        }
        str = smethod_11("Win32_Processor", "Name");
        if (str == "")
        {
            str = smethod_11("Win32_Processor", "Manufacturer");
        }
        return (str + smethod_11("Win32_Processor", "MaxClockSpeed"));
    }

    private static string smethod_13()
    {
        return (smethod_11("Win32_BIOS", "Manufacturer") + smethod_11("Win32_BIOS", "SMBIOSBIOSVersion") + smethod_11("Win32_BIOS", "IdentificationCode") + smethod_11("Win32_BIOS", "SerialNumber") + smethod_11("Win32_BIOS", "ReleaseDate") + smethod_11("Win32_BIOS", "Version"));
    }

    private static string smethod_14()
    {
        return (smethod_11("Win32_DiskDrive", "Model") + smethod_11("Win32_DiskDrive", "Manufacturer") + smethod_11("Win32_DiskDrive", "Signature") + smethod_11("Win32_DiskDrive", "TotalHeads"));
    }

    private static string smethod_15()
    {
        return (smethod_11("Win32_BaseBoard", "Model") + smethod_11("Win32_BaseBoard", "Manufacturer") + smethod_11("Win32_BaseBoard", "Name") + smethod_11("Win32_BaseBoard", "SerialNumber"));
    }

    private static string smethod_16()
    {
        return (smethod_11("Win32_VideoController", "DriverVersion") + smethod_11("Win32_VideoController", "Name"));
    }

    private static string smethod_17()
    {
        return smethod_10("Win32_NetworkAdapterConfiguration", "MACAddress", "IPEnabled");
    }

    private static string smethod_18(string string_0)
    {
        int num = 0;
        int num1 = 0;
        string string0 = string_0;
        int num2 = 0;
        int length = string0.Length;
        while (num2 < length)
        {
            char chr = string0[num2];
            num1++;
            num = checked(num + checked(Strings.Asc(chr) * num1));
            num2++;
        }
        string str = string.Concat(num.ToString(), "00000000");
        return str.Substring(0, 8);
    }

    public static short smethod_19(short short_0)
    {
        short num;
        if (Strings.InStr("1234567890", Conversions.ToString(Strings.Chr(short_0)), CompareMethod.Binary) == 0)
        {
            num = 0;
        }
        else
        {
            num = short_0;
        }
        switch (short_0)
        {
            case 8:
                return short_0;

            case 9:
            case 10:
            case 11:
            case 12:
                return num;

            case 13:
                return short_0;
        }
        return num;
    }

    public static void smethod_2(string string_0, string string_1, string string_2, string string_3)
    {
        WritePrivateProfileStringA(ref string_1, ref string_2, ref string_3, ref string_0);
    }

    public static short smethod_20(short short_0)
    {
        short num;
        if (Strings.InStr("1234567890abcdefABCDEF", Conversions.ToString(Strings.Chr(short_0)), CompareMethod.Binary) == 0)
        {
            num = 0;
        }
        else
        {
            num = short_0;
        }
        switch (short_0)
        {
            case 8:
                return short_0;

            case 9:
            case 10:
            case 11:
            case 12:
                return num;

            case 13:
                return short_0;
        }
        return num;
    }

    public static void smethod_21()
    {
        try
        {
            FileInfo info = new FileInfo("UPDT.INI");
            if (info.Exists)
            {
                FileSystem.Kill("UPDT.INI");
            }
            Class2.smethod_0().Network.DownloadFile("http://mumaker.sytes.net/mumaker/clientes/UPDT.INI", Class2.smethod_1().Info.DirectoryPath + "/UPDT.INI");
        }
        catch (Exception exception1)
        {
            ProjectData.SetProjectError(exception1);
            ProjectData.ClearProjectError();
        }
    }

    public static object smethod_22()
    {
        return Operators.AddObject(Operators.AddObject(Operators.AddObject(Operators.AddObject(Operators.AddObject(smethod_23(), smethod_24()), smethod_25()), smethod_26()), smethod_27()), smethod_28());
    }

    public static object smethod_23()
    {
        string fileName = @"Lang\Arabe.ini";
        FileInfo info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\Arabe.gif";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\Chino.ini";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\Chino.gif";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\Coreano.ini";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\Coreano.gif";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\Deutsch.ini";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\Deutsch.gif";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\English.ini";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\English.gif";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\Espanol.ini";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\Espanol.gif";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\French.ini";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\French.gif";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\Italiano.ini";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\Italiano.gif";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\Latviski.ini";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\Latviski.gif";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\Polish.ini";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\Polish.gif";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\PortBra.ini";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\PortBra.gif";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\Ruso.ini";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = @"Lang\Ruso.gif";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        return 0;
    }

    public static object smethod_24()
    {
        string fileName = "Interop.JRO.dll";
        FileInfo info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        return 0;
    }

    public static object smethod_25()
    {
        string fileName = "Img/Items/Fondo/128x128.MMK";
        FileInfo info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Items/Fondo/128x64.MMK";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Items/Fondo/128x96.MMK";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Items/Fondo/160x64.MMK";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Items/Fondo/160x96.MMK";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Items/Fondo/32x128.MMK";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Items/Fondo/0x0.MMK";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Items/Fondo/32x32.MMK";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Items/Fondo/32x64.MMK";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Items/Fondo/32x96.MMK";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Items/Fondo/64x128.MMK";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Items/Fondo/64x64.MMK";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Items/Fondo/64x96.MMK";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Items/Fondo/96x128.MMK";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Items/Fondo/96x64.MMK";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Items/Fondo/96x96.MMK";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Items/Fondo/casilla.MMK";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Items/Fondo/clean.MMK";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Items/Fondo/sinfoto.MMK";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        return 0;
    }

    public static object smethod_26()
    {
        string fileName = "Img/Maps/SinFoto.mmk";
        FileInfo info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        return 0;
    }

    public static object smethod_27()
    {
        string fileName = "Img/Pj/999999.mmk";
        FileInfo info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/000.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/000000.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/000001.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/000002.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/016.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/016016.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/016017.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/016018.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/032.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/032032.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/032033.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/032034.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/048.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/048048.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/048049.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/048050.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/064.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/064064.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/064065.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/064066.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/080.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/080080.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/080081.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Pj/080082.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        return 0;
    }

    public static object smethod_28()
    {
        string fileName = "Img/Items/SinFoto.mmk";
        FileInfo info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        fileName = "Img/Skills/000000.mmk";
        info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        return 0;
    }

    public static object smethod_29()
    {
        string fileName = "MuMaker.mdb";
        FileInfo info = new FileInfo(fileName);
        if (!info.Exists)
        {
            Interaction.MsgBox("File :\n" + fileName + "\nNo Found!!", MsgBoxStyle.Critical, "Error!!");
            return 1;
        }
        return 0;
    }

    public static object smethod_3()
    {
        JetEngine engine = new JetEngineClass();
        FileInfo info = new FileInfo("MuMaker.mdb");
        if (!info.Exists)
        {
            Interaction.MsgBox("MuMaker.mdb !! Not Found !!", MsgBoxStyle.ApplicationModal, null);
        }
        else
        {
            FileInfo info2 = new FileInfo("NewMuMaker.mdb");
            if (info2.Exists)
            {
                FileSystem.Kill("NewMuMaker.mdb");
            }
            try
            {
                engine.CompactDatabase("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=MuMaker.mdb;", "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=NewMuMaker.mdb;Jet OLEDB:Engine Type=5");
                smethod_4();
            }
            catch (Exception exception1)
            {
                ProjectData.SetProjectError(exception1);
                ProjectData.ClearProjectError();
            }
        }
        return true;
    }

    public static Image smethod_30(byte[] byte_0)
    {
        if (byte_0 != null)
        {
            MemoryStream stream = new MemoryStream(byte_0);
            return Image.FromStream(stream);
        }
        return null;
    }

    public static byte[] smethod_31(object object_0)
    {
        string str = "MMKTMT";
        string expression = "GIF89a";
        byte[] buffer = Class2.smethod_0().FileSystem.ReadAllBytes(Conversions.ToString(object_0));
        int num2 = Strings.Len(expression);
        for (int i = 1; i <= num2; i++)
        {
            if (buffer[i - 1] != Strings.Asc(Strings.Mid(str, i, 1)))
            {
                buffer = Class2.smethod_0().FileSystem.ReadAllBytes(@"Img\Items\Fondo\Clean.MMK");
                int num5 = Strings.Len(expression);
                for (int j = 1; j <= num5; j++)
                {
                    buffer[j - 1] = (byte)Strings.Asc(Strings.Mid(expression, j, 1));
                }
                Interaction.MsgBox(Operators.ConcatenateObject("Invalid/Corrupted MMK File : ", object_0), MsgBoxStyle.ApplicationModal, null);
                return buffer;
            }
            buffer[i - 1] = (byte)Strings.Asc(Strings.Mid(expression, i, 1));
        }
        return buffer;
    }

    public static object smethod_32()
    {
        Class24.struct4_2.string_0 = "000000";
        Class24.struct4_2.string_2 = "00";
        Class24.struct4_2.string_1 = "00";
        Class24.struct4_2.string_3 = "NOMBRE";
        Class24.struct4_2.string_4 = "0";
        Class24.struct4_2.string_5 = "0";
        Class24.struct4_2.string_6 = "0";
        Class24.struct4_2.string_7 = "000";
        Class24.struct4_2.string_9 = "NO";
        Class24.struct4_2.bool_0 = false;
        Class24.struct4_2.bool_1 = false;
        Class24.struct4_2.bool_2 = false;
        Class24.struct4_2.bool_3 = false;
        Class24.struct4_2.int_0 = Conversions.ToInteger("0");
        Class24.struct4_2.int_2 = Conversions.ToInteger("0");
        Class24.struct4_2.int_3 = Conversions.ToInteger("0");
        Class24.struct4_2.int_5 = Conversions.ToInteger("0");
        Class24.struct4_2.string_32 = "NO";
        Class24.struct4_2.string_33 = "NO";
        return true;
    }

    public static object smethod_33()
    {
        Class24.struct4_0.string_0 = "000000";
        Class24.struct4_0.string_2 = "00";
        Class24.struct4_0.string_1 = "00";
        Class24.struct4_0.string_3 = "NOMBRE";
        Class24.struct4_0.string_4 = "0";
        Class24.struct4_0.string_5 = "0";
        Class24.struct4_0.string_6 = "0";
        Class24.struct4_0.string_7 = "000";
        Class24.struct4_0.string_9 = "00";
        Class24.struct4_0.bool_0 = false;
        Class24.struct4_0.bool_1 = false;
        Class24.struct4_0.bool_2 = false;
        Class24.struct4_0.bool_3 = false;
        Class24.struct4_0.int_0 = Conversions.ToInteger("0");
        Class24.struct4_0.int_2 = Conversions.ToInteger("0");
        Class24.struct4_0.int_3 = Conversions.ToInteger("0");
        Class24.struct4_0.int_5 = Conversions.ToInteger("0");
        Class24.struct4_0.string_32 = "NO";
        Class24.struct4_0.string_33 = "NO";
        return true;
    }

    public static object smethod_34()
    {
        Class22.struct0_0.string_1 = "";
        Class22.struct1_0.string_0 = "";
        Class22.struct1_0.string_1 = "";
        return true;
    }

    public static object smethod_35()
    {
        return true;
    }

    public static object smethod_36()
    {
        ConfigMaker.DefInstance.Close();
        smethod_34();
        ItemMaker.DefInstance.Close();
        SkillMaker.DefInstance.Close();
        GuildMaker.DefInstance.Close();
        MoveMaker.DefInstance.Close();
        FinderMaker.DefInstance.Close();
        SQLMaker.DefInstance.Close();
        smethod_34();
        return true;
    }

    public static object smethod_37()
    {
        ConfigMaker.DefInstance.Close();
        AccountMaker.DefInstance.Close();
        SkillMaker.DefInstance.Close();
        GuildMaker.DefInstance.Close();
        MoveMaker.DefInstance.Close();
        FinderMaker.DefInstance.Close();
        SQLMaker.DefInstance.Close();
        smethod_34();
        smethod_32();
        smethod_33();
        return true;
    }

    public static object smethod_38()
    {
        ConfigMaker.DefInstance.Close();
        AccountMaker.DefInstance.Close();
        smethod_34();
        ItemMaker.DefInstance.Close();
        GuildMaker.DefInstance.Close();
        FinderMaker.DefInstance.Close();
        MoveMaker.DefInstance.Close();
        SQLMaker.DefInstance.Close();
        smethod_34();
        return true;
    }

    public static object smethod_39()
    {
        ConfigMaker.DefInstance.Close();
        AccountMaker.DefInstance.Close();
        smethod_34();
        ItemMaker.DefInstance.Close();
        SkillMaker.DefInstance.Close();
        MoveMaker.DefInstance.Close();
        FinderMaker.DefInstance.Close();
        SQLMaker.DefInstance.Close();
        smethod_34();
        return true;
    }

    public static object smethod_4()
    {
        try
        {
            FileSystem.Kill("MuMaker.mdb");
            FileSystem.Rename("NewMuMaker.mdb", "MuMaker.mdb");
        }
        catch (Exception exception1)
        {
            ProjectData.SetProjectError(exception1);
            Exception exception = exception1;
            Interaction.MsgBox(exception.Message, MsgBoxStyle.ApplicationModal, null);
            ProjectData.ClearProjectError();
        }
        return true;
    }

    public static object smethod_40()
    {
        ConfigMaker.DefInstance.Close();
        AccountMaker.DefInstance.Close();
        smethod_34();
        ItemMaker.DefInstance.Close();
        SkillMaker.DefInstance.Close();
        GuildMaker.DefInstance.Close();
        FinderMaker.DefInstance.Close();
        SQLMaker.DefInstance.Close();
        smethod_34();
        return true;
    }

    public static object smethod_41()
    {
        ConfigMaker.DefInstance.Close();
        AccountMaker.DefInstance.Close();
        smethod_34();
        ItemMaker.DefInstance.Close();
        SkillMaker.DefInstance.Close();
        GuildMaker.DefInstance.Close();
        MoveMaker.DefInstance.Close();
        SQLMaker.DefInstance.Close();
        smethod_34();
        return true;
    }

    public static object smethod_42()
    {
        ConfigMaker.DefInstance.Close();
        AccountMaker.DefInstance.Close();
        smethod_34();
        ItemMaker.DefInstance.Close();
        SkillMaker.DefInstance.Close();
        GuildMaker.DefInstance.Close();
        MoveMaker.DefInstance.Close();
        FinderMaker.DefInstance.Close();
        smethod_34();
        return true;
    }

    public static object smethod_43()
    {
        smethod_34();
        ConfigMaker.DefInstance.Close();
        UpDateMaker.DefInstance.Close();
        Creditos.DefInstance.Close();
        return true;
    }

    public static object smethod_44()
    {
        Class32.int_10 = 1;
        Class32.int_11 = 0;
        Class32.int_12 = 0;
        return true;
    }

    public static object smethod_45()
    {
        Class32.int_10 = 0;
        Class32.int_11 = 1;
        Class32.int_12 = 0;
        return true;
    }

    public static object smethod_46()
    {
        Class32.int_10 = 0;
        Class32.int_11 = 0;
        Class32.int_12 = 1;
        return true;
    }

    public static object smethod_47()
    {
        Class32.int_10 = 0;
        Class32.int_11 = 0;
        Class32.int_12 = 0;
        return true;
    }

    public static string smethod_5(string string_0)
    {
        string str = "\x00b7";
        string str2 = "";
        int num = Strings.Len(string_0);
        for (int i = 1; i <= num; i++)
        {
            string str4 = Strings.Mid(string_0, i, 1);
            string str5 = Strings.Mid(str, ((i - 1) % Strings.Len(str)) + 1, 1);
            str2 = str2 + Conversions.ToString(Strings.Chr(Strings.Asc(str5) ^ Strings.Asc(str4)));
        }
        return str2;
    }

    public static string smethod_6(string string_0)
    {
        string str = "\x00b7";
        string str2 = "";
        int num = Strings.Len(string_0);
        for (int i = 1; i <= num; i++)
        {
            string str4 = Strings.Mid(string_0, i, 2);
            string str5 = Strings.Mid(str, ((i - 1) % Strings.Len(str)) + 1, 1);
            str2 = str2 + Conversions.ToString(Strings.Chr(Strings.Asc(str4) ^ Strings.Asc(str5)));
        }
        return str2;
    }

    public static string smethod_7(string string_0)
    {
        string str = "A$#@/&\x00fc%";
        string str2 = "";
        int num2 = Strings.Len(string_0);
        for (int i = 1; i <= num2; i++)
        {
            string str3 = Strings.Mid(string_0, i, 1);
            string str4 = Strings.Mid(str, ((i - 1) % Strings.Len(str)) + 1, 1);
            str2 = str2 + Strings.Right("0" + Conversion.Hex((int)(Strings.Asc(str4) ^ Strings.Asc(str3))), 2);
        }
        return str2;
    }

    public static string smethod_8(string string_0)
    {
        string str = "A$#@/&\x00fc%";
        string str2 = "";
        int num2 = 1;
        int num3 = Strings.Len(string_0);
        for (int i = 1; i <= num3; i += 2)
        {
            string str3 = Strings.Mid(string_0, i, 2);
            string str4 = Strings.Mid(str, ((num2 - 1) % Strings.Len(str)) + 1, 1);
            str2 = str2 + Conversions.ToString(Strings.Chr(Strings.Asc(str4) ^ ((int)((long)Math.Round(Conversion.Val("&h" + str3))))));
            num2++;
        }
        return str2;
    }

    public static string smethod_9()
    {
        return smethod_18(smethod_12() + smethod_13() + smethod_14() + smethod_15() + smethod_16() + smethod_17());
    }

    [DllImport("kernel32", CharSet = CharSet.Ansi, SetLastError = true, ExactSpelling = true)]
    private static extern int WritePrivateProfileStringA([MarshalAs(UnmanagedType.VBByRefStr)] ref string string_0, [MarshalAs(UnmanagedType.VBByRefStr)] ref string string_1, [MarshalAs(UnmanagedType.VBByRefStr)] ref string string_2, [MarshalAs(UnmanagedType.VBByRefStr)] ref string string_3);
}

