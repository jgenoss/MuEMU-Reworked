// MuMaker - INI Helper and Utilities
// Helper functions for INI file operations, encryption, and hardware identification

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using System;
using System.Drawing;
using System.IO;
using System.Management;
using System.Runtime.InteropServices;

namespace MuMaker.Core
{
    /// <summary>
    /// INI file helper and utility functions
    /// </summary>
    public static class IniHelper
    {
        #region P/Invoke Declarations
        [DllImport("kernel32", CharSet = CharSet.Ansi, SetLastError = true, ExactSpelling = true)]
        private static extern int GetPrivateProfileStringA(
            [MarshalAs(UnmanagedType.VBByRefStr)] ref string section,
            [MarshalAs(UnmanagedType.VBByRefStr)] ref string key,
            [MarshalAs(UnmanagedType.VBByRefStr)] ref string defaultValue,
            [MarshalAs(UnmanagedType.VBByRefStr)] ref string returnValue,
            int size,
            [MarshalAs(UnmanagedType.VBByRefStr)] ref string filePath);

        [DllImport("kernel32", CharSet = CharSet.Ansi, SetLastError = true, ExactSpelling = true)]
        private static extern int WritePrivateProfileStringA(
            [MarshalAs(UnmanagedType.VBByRefStr)] ref string section,
            [MarshalAs(UnmanagedType.VBByRefStr)] ref string key,
            [MarshalAs(UnmanagedType.VBByRefStr)] ref string value,
            [MarshalAs(UnmanagedType.VBByRefStr)] ref string filePath);
        #endregion

        #region INI File Operations
        /// <summary>
        /// Reads a value from an INI file
        /// </summary>
        /// <param name="filePath">Path to the INI file</param>
        /// <param name="section">Section name</param>
        /// <param name="key">Key name</param>
        /// <param name="defaultValue">Default value if not found</param>
        /// <returns>Value from INI file or default value</returns>
        public static string ReadValue(string filePath, string section, string key, string defaultValue = "")
        {
            string result = new string('\0', 255);
            int length = GetPrivateProfileStringA(ref section, ref key, ref defaultValue, ref result, Strings.Len(result), ref filePath);

            if (length == 0)
            {
                return defaultValue;
            }

            return Strings.Left(result, length);
        }

        /// <summary>
        /// Writes a value to an INI file
        /// </summary>
        /// <param name="filePath">Path to the INI file</param>
        /// <param name="section">Section name</param>
        /// <param name="key">Key name</param>
        /// <param name="value">Value to write</param>
        public static void WriteValue(string filePath, string section, string key, string value)
        {
            WritePrivateProfileStringA(ref section, ref key, ref value, ref filePath);
        }

        /// <summary>
        /// Reads a localized string from a language file
        /// </summary>
        /// <param name="language">Language name</param>
        /// <param name="key">String key</param>
        /// <returns>Localized string</returns>
        public static object ReadLanguageString(string language, string key)
        {
            using (StreamReader reader = new StreamReader("Lang/" + language + ".ini"))
            {
                string line = reader.ReadLine();
                while (line != null && Strings.Mid(line, 1, key.Length) != key)
                {
                    line = reader.ReadLine();
                }

                return Strings.Mid(line, key.Length + 2);
            }
        }
        #endregion

        #region Password Encryption/Decryption
        private const string EncryptionKey = "A$#@/&\x00fc%";

        /// <summary>
        /// Encrypts a password for storage
        /// </summary>
        /// <param name="password">Plain text password</param>
        /// <returns>Encrypted password in hex format</returns>
        public static string EncryptPassword(string password)
        {
            string result = "";
            int passwordLength = Strings.Len(password);

            for (int i = 1; i <= passwordLength; i++)
            {
                string passChar = Strings.Mid(password, i, 1);
                string keyChar = Strings.Mid(EncryptionKey, ((i - 1) % Strings.Len(EncryptionKey)) + 1, 1);
                result += Strings.Right("0" + Conversion.Hex(Strings.Asc(keyChar) ^ Strings.Asc(passChar)), 2);
            }

            return result;
        }

        /// <summary>
        /// Decrypts a password from storage
        /// </summary>
        /// <param name="encryptedPassword">Encrypted password in hex format</param>
        /// <returns>Decrypted plain text password</returns>
        public static string DecryptPassword(string encryptedPassword)
        {
            string result = "";
            int keyIndex = 1;
            int encryptedLength = Strings.Len(encryptedPassword);

            for (int i = 1; i <= encryptedLength; i += 2)
            {
                string hexPair = Strings.Mid(encryptedPassword, i, 2);
                string keyChar = Strings.Mid(EncryptionKey, ((keyIndex - 1) % Strings.Len(EncryptionKey)) + 1, 1);
                result += Conversions.ToString(Strings.Chr(Strings.Asc(keyChar) ^ (int)Math.Round(Conversion.Val("&h" + hexPair))));
                keyIndex++;
            }

            return result;
        }
        #endregion

        #region Hardware Identification
        /// <summary>
        /// Generates a unique hardware fingerprint for licensing
        /// </summary>
        /// <returns>8-character hardware fingerprint</returns>
        public static string GenerateHardwareFingerprint()
        {
            string cpuId = GetCpuId();
            string biosId = GetBiosId();
            string diskId = GetDiskId();
            string baseboardId = GetBaseboardId();
            string videoId = GetVideoId();
            string macAddress = GetMacAddress();

            return HashHardwareInfo(cpuId + biosId + diskId + baseboardId + videoId + macAddress);
        }

        private static string GetCpuId()
        {
            string result = GetWmiProperty("Win32_Processor", "UniqueId");
            if (!string.IsNullOrEmpty(result)) return result;

            result = GetWmiProperty("Win32_Processor", "ProcessorId");
            if (!string.IsNullOrEmpty(result)) return result;

            result = GetWmiProperty("Win32_Processor", "Name");
            if (string.IsNullOrEmpty(result))
            {
                result = GetWmiProperty("Win32_Processor", "Manufacturer");
            }

            return result + GetWmiProperty("Win32_Processor", "MaxClockSpeed");
        }

        private static string GetBiosId()
        {
            return GetWmiProperty("Win32_BIOS", "Manufacturer") +
                   GetWmiProperty("Win32_BIOS", "SMBIOSBIOSVersion") +
                   GetWmiProperty("Win32_BIOS", "IdentificationCode") +
                   GetWmiProperty("Win32_BIOS", "SerialNumber") +
                   GetWmiProperty("Win32_BIOS", "ReleaseDate") +
                   GetWmiProperty("Win32_BIOS", "Version");
        }

        private static string GetDiskId()
        {
            return GetWmiProperty("Win32_DiskDrive", "Model") +
                   GetWmiProperty("Win32_DiskDrive", "Manufacturer") +
                   GetWmiProperty("Win32_DiskDrive", "Signature") +
                   GetWmiProperty("Win32_DiskDrive", "TotalHeads");
        }

        private static string GetBaseboardId()
        {
            return GetWmiProperty("Win32_BaseBoard", "Model") +
                   GetWmiProperty("Win32_BaseBoard", "Manufacturer") +
                   GetWmiProperty("Win32_BaseBoard", "Name") +
                   GetWmiProperty("Win32_BaseBoard", "SerialNumber");
        }

        private static string GetVideoId()
        {
            return GetWmiProperty("Win32_VideoController", "DriverVersion") +
                   GetWmiProperty("Win32_VideoController", "Name");
        }

        private static string GetMacAddress()
        {
            return GetWmiPropertyWithCondition("Win32_NetworkAdapterConfiguration", "MACAddress", "IPEnabled");
        }

        private static string GetWmiProperty(string wmiClass, string property)
        {
            try
            {
                using (ManagementClass mc = new ManagementClass(wmiClass))
                {
                    foreach (ManagementObject mo in mc.GetInstances())
                    {
                        try
                        {
                            return mo[property]?.ToString() ?? "";
                        }
                        catch
                        {
                            continue;
                        }
                    }
                }
            }
            catch
            {
                // Ignore WMI errors
            }
            return "";
        }

        private static string GetWmiPropertyWithCondition(string wmiClass, string property, string conditionProperty)
        {
            try
            {
                using (ManagementClass mc = new ManagementClass(wmiClass))
                {
                    foreach (ManagementObject mo in mc.GetInstances())
                    {
                        try
                        {
                            if (mo[conditionProperty]?.ToString() == "True")
                            {
                                return mo[property]?.ToString() ?? "";
                            }
                        }
                        catch
                        {
                            continue;
                        }
                    }
                }
            }
            catch
            {
                // Ignore WMI errors
            }
            return "";
        }

        private static string HashHardwareInfo(string hardwareInfo)
        {
            int hash = 0;
            int position = 0;

            foreach (char c in hardwareInfo)
            {
                position++;
                hash = checked(hash + checked(Strings.Asc(c) * position));
            }

            return (hash.ToString() + "00000000").Substring(0, 8);
        }
        #endregion

        #region Input Validation
        /// <summary>
        /// Validates numeric input (0-9 only)
        /// </summary>
        public static short ValidateNumericInput(short keyCode)
        {
            if (Strings.InStr("1234567890", Conversions.ToString(Strings.Chr(keyCode)), CompareMethod.Binary) == 0)
            {
                keyCode = 0;
            }

            // Allow special keys
            switch (keyCode)
            {
                case 8:  // Backspace
                case 13: // Enter
                    return keyCode;
                default:
                    return keyCode;
            }
        }

        /// <summary>
        /// Validates hexadecimal input (0-9, A-F)
        /// </summary>
        public static short ValidateHexInput(short keyCode)
        {
            if (Strings.InStr("1234567890abcdefABCDEF", Conversions.ToString(Strings.Chr(keyCode)), CompareMethod.Binary) == 0)
            {
                keyCode = 0;
            }

            // Allow special keys
            switch (keyCode)
            {
                case 8:  // Backspace
                case 13: // Enter
                    return keyCode;
                default:
                    return keyCode;
            }
        }
        #endregion

        #region Image Utilities
        /// <summary>
        /// Converts byte array to Image
        /// </summary>
        public static Image ByteArrayToImage(byte[] imageBytes)
        {
            if (imageBytes == null) return null;

            using (MemoryStream ms = new MemoryStream(imageBytes))
            {
                return Image.FromStream(ms);
            }
        }

        /// <summary>
        /// Reads and decodes MMK image file (custom format)
        /// </summary>
        public static byte[] ReadMmkImageFile(string filePath)
        {
            const string mmkHeader = "MMKTMT";
            const string gifHeader = "GIF89a";

            byte[] fileBytes = File.ReadAllBytes(filePath);

            // Verify and convert MMK header to GIF header
            for (int i = 0; i < gifHeader.Length; i++)
            {
                if (fileBytes[i] != Strings.Asc(Strings.Mid(mmkHeader, i + 1, 1)))
                {
                    // Invalid MMK file, return placeholder
                    fileBytes = File.ReadAllBytes(@"Img\Items\Fondo\Clean.MMK");

                    for (int j = 0; j < gifHeader.Length; j++)
                    {
                        fileBytes[j] = (byte)Strings.Asc(Strings.Mid(gifHeader, j + 1, 1));
                    }

                    Interaction.MsgBox("Invalid/Corrupted MMK File: " + filePath, MsgBoxStyle.ApplicationModal, null);
                    return fileBytes;
                }

                fileBytes[i] = (byte)Strings.Asc(Strings.Mid(gifHeader, i + 1, 1));
            }

            return fileBytes;
        }
        #endregion

        #region Database Maintenance
        /// <summary>
        /// Compacts the local Access database
        /// </summary>
        public static bool CompactDatabase()
        {
            if (!File.Exists("MuMaker.mdb"))
            {
                Interaction.MsgBox("MuMaker.mdb Not Found!", MsgBoxStyle.ApplicationModal, null);
                return false;
            }

            try
            {
                if (File.Exists("NewMuMaker.mdb"))
                {
                    File.Delete("NewMuMaker.mdb");
                }

                // Use JRO to compact database
                var jetEngine = new JRO.JetEngineClass();
                jetEngine.CompactDatabase(
                    "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=MuMaker.mdb;",
                    "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=NewMuMaker.mdb;Jet OLEDB:Engine Type=5");

                // Replace old database with compacted one
                File.Delete("MuMaker.mdb");
                File.Move("NewMuMaker.mdb", "MuMaker.mdb");

                return true;
            }
            catch (Exception ex)
            {
                Interaction.MsgBox(ex.Message, MsgBoxStyle.ApplicationModal, null);
                return false;
            }
        }
        #endregion

        #region File Existence Checks
        /// <summary>
        /// Validates all required language files exist
        /// </summary>
        public static bool ValidateLanguageFiles()
        {
            string[] languages = { "Arabe", "Chino", "Coreano", "Deutsch", "English", "Espanol", "French", "Italiano", "Latviski", "Polish", "PortBra", "Ruso" };

            foreach (string lang in languages)
            {
                if (!File.Exists($@"Lang\{lang}.ini") || !File.Exists($@"Lang\{lang}.gif"))
                {
                    Interaction.MsgBox($"File:\nLang\\{lang}.ini or .gif\nNot Found!", MsgBoxStyle.Critical, "Error!");
                    return false;
                }
            }

            return true;
        }

        /// <summary>
        /// Validates the local database file exists
        /// </summary>
        public static bool ValidateDatabaseFile()
        {
            if (!File.Exists("MuMaker.mdb"))
            {
                Interaction.MsgBox("File:\nMuMaker.mdb\nNot Found!", MsgBoxStyle.Critical, "Error!");
                return false;
            }
            return true;
        }
        #endregion
    }
}
