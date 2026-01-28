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
        #region Descriptive Method Names
        // Public descriptive methods for clean code usage
        public static string ReadIniValue(string filePath, string section, string key, string defaultValue = "") => ReadValue(filePath, section, key, defaultValue);
        public static void WriteIniValue(string filePath, string section, string key, string value) => WriteValue(filePath, section, key, value);
        public static string EncodeStringForWeb(string input) => smethod_5(input);
        public static void ReloadConfiguration() => smethod_21();
        public static object GetExtraWarehouseCount() => smethod_22();
        public static object ValidateRequiredFiles() => smethod_29();
        public static void LoadLocalizedStrings() => smethod_32();
        public static void LoadMapImages() => smethod_33();
        public static void PrepareShowConfigMaker() => smethod_35();
        public static void PrepareShowAccountMaker() => smethod_36();
        public static void PrepareShowItemMaker() => smethod_37();
        public static void PrepareShowSkillMaker() => smethod_38();
        public static void PrepareShowGuildMaker() => smethod_39();
        public static void PrepareShowMoveMaker() => smethod_40();
        public static void PrepareShowFinderMaker() => smethod_41();
        public static void PrepareShowSQLMaker() => smethod_42();
        public static void CompactLocalDatabase() => smethod_43();
        #endregion

        #region Original Method Aliases (smethod_X backward compatibility)
        // These aliases maintain compatibility with code calling original obfuscated method names

        /// <summary>
        /// smethod_0 - Read language string
        /// </summary>
        public static object smethod_0(string language, string key) => ReadLanguageString(language, key);

        /// <summary>
        /// smethod_1 - Read INI value
        /// </summary>
        public static string smethod_1(string filePath, string section, string key, string defaultValue = "")
            => ReadValue(filePath, section, key, defaultValue);

        /// <summary>
        /// smethod_2 - Write INI value
        /// </summary>
        public static void smethod_2(string filePath, string section, string key, string value)
            => WriteValue(filePath, section, key, value);

        /// <summary>
        /// smethod_3 - Decrypt password
        /// </summary>
        public static string smethod_3(string encryptedPassword) => DecryptPassword(encryptedPassword);

        /// <summary>
        /// smethod_5 - Encode string for web transmission
        /// </summary>
        public static string smethod_5(string input)
        {
            if (string.IsNullOrEmpty(input)) return "";
            string result = "";
            foreach (char c in input)
            {
                result += Strings.Chr(Strings.Asc(c) + 10);
            }
            return result;
        }

        /// <summary>
        /// smethod_7 - Encrypt password
        /// </summary>
        public static string smethod_7(string password) => EncryptPassword(password);

        /// <summary>
        /// smethod_8 - Decrypt password (alternate)
        /// </summary>
        public static string smethod_8(string encryptedPassword) => DecryptPassword(encryptedPassword);

        /// <summary>
        /// smethod_19 - Validate numeric input
        /// </summary>
        public static short smethod_19(short keyCode) => ValidateNumericInput(keyCode);

        /// <summary>
        /// smethod_20 - Generate hardware fingerprint
        /// </summary>
        public static string smethod_20() => GenerateHardwareFingerprint();

        /// <summary>
        /// smethod_21 - Reload configuration from INI files
        /// </summary>
        public static void smethod_21()
        {
            // Reload configuration
            Configuration.smethod_0(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath);
        }

        /// <summary>
        /// smethod_22 - Get extra warehouse count from config
        /// </summary>
        public static object smethod_22()
        {
            return Conversions.ToInteger(Configuration.object_13);
        }

        /// <summary>
        /// smethod_29 - Validate language files exist
        /// </summary>
        public static object smethod_29()
        {
            return ValidateLanguageFiles() && ValidateDatabaseFile() ? 0 : 1;
        }

        /// <summary>
        /// smethod_30 - Load image from byte array (convert MMK file to Image)
        /// </summary>
        public static Image smethod_30(byte[] imageBytes) => ByteArrayToImage(imageBytes);

        /// <summary>
        /// smethod_31 - Read MMK image file and return bytes
        /// </summary>
        public static byte[] smethod_31(object filePath) => ReadMmkImageFile(Conversions.ToString(filePath));

        /// <summary>
        /// smethod_32 - Load localized strings for current language
        /// </summary>
        public static void smethod_32()
        {
            LocalizedStrings.smethod_0(Conversions.ToString(Configuration.object_12));
        }

        /// <summary>
        /// smethod_33 - Load map images
        /// </summary>
        public static void smethod_33()
        {
            MapImageHelper.smethod_0();
        }

        /// <summary>
        /// smethod_34 - Load character images
        /// </summary>
        public static void smethod_34()
        {
            // Load character class images
        }

        /// <summary>
        /// smethod_35 - Show config maker
        /// </summary>
        public static void smethod_35()
        {
            // Placeholder - form navigation
        }

        /// <summary>
        /// smethod_36 - Show account maker
        /// </summary>
        public static void smethod_36()
        {
            // Placeholder - form navigation
        }

        /// <summary>
        /// smethod_37 - Show PJ maker
        /// </summary>
        public static void smethod_37()
        {
            // Placeholder - form navigation
        }

        /// <summary>
        /// smethod_38 - Show item maker
        /// </summary>
        public static void smethod_38()
        {
            // Placeholder - form navigation
        }

        /// <summary>
        /// smethod_39 - Show move maker
        /// </summary>
        public static void smethod_39()
        {
            // Placeholder - form navigation
        }

        /// <summary>
        /// smethod_40 - Show skill maker
        /// </summary>
        public static void smethod_40()
        {
            // Placeholder - form navigation
        }

        /// <summary>
        /// smethod_41 - Show guild maker
        /// </summary>
        public static void smethod_41()
        {
            // Placeholder - form navigation
        }

        /// <summary>
        /// smethod_42 - Show finder maker
        /// </summary>
        public static void smethod_42()
        {
            // Placeholder - form navigation
        }

        /// <summary>
        /// smethod_43 - Compact local database
        /// </summary>
        public static void smethod_43()
        {
            CompactDatabase();
        }

        /// <summary>
        /// smethod_44 - Load account data
        /// </summary>
        public static void smethod_44()
        {
            GameDataLoader.smethod_0();
        }

        /// <summary>
        /// smethod_45 - Load item data
        /// </summary>
        public static void smethod_45()
        {
            GameDataLoader.smethod_1();
        }

        /// <summary>
        /// smethod_46 - Load skill data
        /// </summary>
        public static void smethod_46()
        {
            GameDataLoader.smethod_2();
        }

        /// <summary>
        /// smethod_47 - Clear all form data
        /// </summary>
        public static void smethod_47()
        {
            GameDataLoader.smethod_3();
        }
        #endregion
    }
}
