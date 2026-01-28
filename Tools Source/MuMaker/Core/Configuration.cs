// MuMaker - Configuration
// Refactored from Class26
// Application configuration loaded from INI files

using Microsoft.VisualBasic.CompilerServices;
using System;

namespace MuMaker.Core
{
    /// <summary>
    /// Application configuration settings loaded from Config.ini and UPDT.INI
    /// </summary>
    [StandardModule]
    internal sealed class Configuration
    {
        #region Version Information
        public static string string_0 = "1.13";   // Current version
        public static string string_1 = "1.07K";  // Database version K
        public static string string_2 = "1.03H";  // Database version H
        public static string string_3 = "1.03K";  // Database version K2
        public static object object_18;           // Loaded version from UPDT.INI
        public static string string_4;            // Update info
        public static string string_5 = "";       // Hardware ID
        #endregion

        #region SQL Connection Settings (object_0 - object_11)
        public static object object_0;   // Server IP address
        public static object object_1;   // Server port
        public static object object_2;   // Connection type (Local/Remote)
        public static object object_3;   // SQL username
        public static object object_4;   // SQL password (encrypted)
        public static object object_5;   // Remember password
        public static object object_6;   // (unused)
        public static object object_7;   // MuOnline database name
        public static object object_8;   // MuRanking database name
        public static object object_9;   // MuEvent database name
        public static object object_10;  // Extended warehouse table name
        public static object object_11;  // Reset column name
        public static int int_0;         // Command timeout
        #endregion

        #region Application Settings (object_12 - object_17)
        public static object object_12;  // Language
        public static object object_13;  // Extra warehouse count
        public static object object_14;  // Reset enabled
        public static object object_15;  // MD5 enabled
        public static object object_16;  // First load
        public static object object_17;  // Auto reload
        #endregion

        #region Personal Settings (object_19 - object_22)
        public static object object_19;  // User name
        public static object object_20;  // Days config
        public static object object_21;  // Character selection
        public static object object_22;  // Effects top position
        #endregion

        #region Descriptive Aliases
        public static string CurrentVersion { get => string_0; set => string_0 = value; }
        public static string HardwareId { get => string_5; set => string_5 = value; }
        public static object ServerIpAddress { get => object_0; set => object_0 = value; }
        public static object ServerPort { get => object_1; set => object_1 = value; }
        public static object ConnectionType { get => object_2; set => object_2 = value; }
        public static object SqlUsername { get => object_3; set => object_3 = value; }
        public static object SqlPassword { get => object_4; set => object_4 = value; }
        public static object MuOnlineDatabase { get => object_7; set => object_7 = value; }
        public static object MuRankingDatabase { get => object_8; set => object_8 = value; }
        public static object MuEventDatabase { get => object_9; set => object_9 = value; }
        public static object ExtendedWarehouseTable { get => object_10; set => object_10 = value; }
        public static object ResetColumnName { get => object_11; set => object_11 = value; }
        public static int CommandTimeout { get => int_0; set => int_0 = value; }
        public static object Language { get => object_12; set => object_12 = value; }
        #endregion

        #region Initialization Methods
        /// <summary>
        /// Load configuration (smethod_0)
        /// </summary>
        public static void smethod_0(string appPath)
        {
            // Load from UPDT.INI
            object_18 = IniHelper.smethod_1(appPath + "/UPDT.INI", "Info", "Version", string_0);
            string_4 = IniHelper.smethod_1(appPath + "/UPDT.INI", "Info", "Info", "!! No Info !!");

            // Load SQL settings from Config.ini
            object_5 = IniHelper.smethod_1(appPath + "/Config.ini", "SQL", "RPW", "0");
            object_3 = IniHelper.smethod_1(appPath + "/Config.ini", "SQL", "Usuario", "sa");
            object_4 = IniHelper.smethod_3(IniHelper.smethod_1(appPath + "/Config.ini", "SQL", "PassWord", ""));
            object_2 = IniHelper.smethod_1(appPath + "/Config.ini", "SQL", "Connection", "Local");
            object_0 = IniHelper.smethod_1(appPath + "/Config.ini", "SQL", "IPServer", "127.0.0.1");
            object_1 = IniHelper.smethod_1(appPath + "/Config.ini", "SQL", "PORTServer", "1433");
            object_7 = IniHelper.smethod_1(appPath + "/Config.ini", "SQL", "MuOnline", "MuOnline");
            object_8 = IniHelper.smethod_1(appPath + "/Config.ini", "SQL", "MuRanking", "MuRanking");
            object_9 = IniHelper.smethod_1(appPath + "/Config.ini", "SQL", "MuEvent", "MuEvent");
            object_10 = IniHelper.smethod_1(appPath + "/Config.ini", "SQL", "ExtWareHouse", "ExtWareHouse");
            object_11 = IniHelper.smethod_1(appPath + "/Config.ini", "SQL", "Reset", "Resets");
            int_0 = Conversions.ToInteger(IniHelper.smethod_1(appPath + "/Config.ini", "SQL", "TimeLimit", "360"));

            // Load application settings
            object_12 = IniHelper.smethod_1(appPath + "/Config.ini", "Config", "Languaje", "Espanol");
            object_13 = IniHelper.smethod_1(appPath + "/Config.ini", "Config", "NuExtraWareHouses", "0");
            object_14 = IniHelper.smethod_1(appPath + "/Config.ini", "Config", "Reset", "0");
            object_15 = IniHelper.smethod_1(appPath + "/Config.ini", "Config", "MD5", "0");
            object_16 = IniHelper.smethod_1(appPath + "/Config.ini", "Config", "FirstLoad", "0");
            object_17 = IniHelper.smethod_1(appPath + "/Config.ini", "Config", "AutoReLoad", "0");

            // Load personal settings
            object_19 = IniHelper.smethod_1(appPath + "/Config.ini", "Personal", "Name", "N00B");
            object_20 = IniHelper.smethod_1(appPath + "/Config.ini", "Personal", "DIAS", "30");
            object_21 = IniHelper.smethod_1(appPath + "/Config.ini", "Personal", "PJ", "1");
            object_22 = IniHelper.smethod_1(appPath + "/Config.ini", "FX", "Top", "0");
        }

        /// <summary>
        /// Generate hardware ID (smethod_1)
        /// </summary>
        public static bool smethod_1()
        {
            try
            {
                if (string.Equals(string_5, "00000000") || string.Equals(string_5, ""))
                {
                    string_5 = IniHelper.smethod_20();
                }
                return true;
            }
            catch (Exception)
            {
                string_5 = "00000000";
                return false;
            }
        }
        #endregion

        #region Descriptive Method Names
        /// <summary>Load configuration from INI files</summary>
        public static void LoadConfiguration(string appPath) => smethod_0(appPath);

        /// <summary>Load configuration from default path</summary>
        public static void LoadConfiguration() => smethod_0(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath);

        /// <summary>Generate hardware ID</summary>
        public static bool GenerateHardwareId() => smethod_1();
        #endregion
    }
}
