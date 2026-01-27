// MuMaker - Configuration
// Application configuration loaded from INI files

using Microsoft.VisualBasic.CompilerServices;
using System;

namespace MuMaker.Core
{
    /// <summary>
    /// Application configuration settings loaded from Config.ini and UPDT.INI
    /// </summary>
    public static class Configuration
    {
        #region Version Information
        /// <summary>
        /// Current application version
        /// </summary>
        public static string CurrentVersion = "1.13";

        /// <summary>
        /// Compatible database version (Korean)
        /// </summary>
        public static string DatabaseVersionK = "1.07K";

        /// <summary>
        /// Compatible database version (H)
        /// </summary>
        public static string DatabaseVersionH = "1.03H";

        /// <summary>
        /// Compatible database version (K2)
        /// </summary>
        public static string DatabaseVersionK2 = "1.03K";

        /// <summary>
        /// Loaded version from UPDT.INI
        /// </summary>
        public static object LoadedVersion;

        /// <summary>
        /// Update information
        /// </summary>
        public static string UpdateInfo;

        /// <summary>
        /// Hardware ID for licensing
        /// </summary>
        public static string HardwareId = "";
        #endregion

        #region SQL Connection Settings
        /// <summary>
        /// Remember password flag
        /// </summary>
        public static object RememberPassword;

        /// <summary>
        /// SQL Server username
        /// </summary>
        public static object SqlUsername;

        /// <summary>
        /// SQL Server password (encrypted)
        /// </summary>
        public static object SqlPassword;

        /// <summary>
        /// Connection type: "Local" or "Remote"
        /// </summary>
        public static object ConnectionType;

        /// <summary>
        /// Remote server IP address
        /// </summary>
        public static object ServerIpAddress;

        /// <summary>
        /// Remote server port
        /// </summary>
        public static object ServerPort;

        /// <summary>
        /// Main MuOnline database name
        /// </summary>
        public static object MuOnlineDatabase;

        /// <summary>
        /// Ranking database name
        /// </summary>
        public static object MuRankingDatabase;

        /// <summary>
        /// Event database name
        /// </summary>
        public static object MuEventDatabase;

        /// <summary>
        /// Extended warehouse table name
        /// </summary>
        public static object ExtendedWarehouseTable;

        /// <summary>
        /// Reset column name
        /// </summary>
        public static object ResetColumnName;

        /// <summary>
        /// SQL command timeout in seconds
        /// </summary>
        public static int CommandTimeout;
        #endregion

        #region Application Settings
        /// <summary>
        /// Selected language
        /// </summary>
        public static object Language;

        /// <summary>
        /// Number of extra warehouses
        /// </summary>
        public static object ExtraWarehouseCount;

        /// <summary>
        /// Reset system enabled flag
        /// </summary>
        public static object ResetEnabled;

        /// <summary>
        /// MD5 password encryption flag
        /// </summary>
        public static object Md5Enabled;

        /// <summary>
        /// First load flag
        /// </summary>
        public static object FirstLoad;

        /// <summary>
        /// Auto reload data flag
        /// </summary>
        public static object AutoReload;
        #endregion

        #region Personal Settings
        /// <summary>
        /// User display name
        /// </summary>
        public static object UserName;

        /// <summary>
        /// Days configuration
        /// </summary>
        public static object DaysConfig;

        /// <summary>
        /// Character selection
        /// </summary>
        public static object CharacterSelection;

        /// <summary>
        /// Top position for effects
        /// </summary>
        public static object EffectsTopPosition;
        #endregion

        #region Initialization
        /// <summary>
        /// Initialize configuration from INI files
        /// </summary>
        /// <param name="appPath">Application directory path</param>
        public static void Initialize(string appPath)
        {
            // Load from UPDT.INI
            LoadedVersion = IniHelper.ReadValue(appPath + "/UPDT.INI", "Info", "Version", CurrentVersion);
            UpdateInfo = IniHelper.ReadValue(appPath + "/UPDT.INI", "Info", "Info", "!! No Info !!");

            // Load SQL settings from Config.ini
            RememberPassword = IniHelper.ReadValue(appPath + "/Config.ini", "SQL", "RPW", "0");
            SqlUsername = IniHelper.ReadValue(appPath + "/Config.ini", "SQL", "Usuario", "sa");
            SqlPassword = IniHelper.DecryptPassword(IniHelper.ReadValue(appPath + "/Config.ini", "SQL", "PassWord", ""));
            ConnectionType = IniHelper.ReadValue(appPath + "/Config.ini", "SQL", "Connection", "Local");
            ServerIpAddress = IniHelper.ReadValue(appPath + "/Config.ini", "SQL", "IPServer", "127.0.0.1");
            ServerPort = IniHelper.ReadValue(appPath + "/Config.ini", "SQL", "PORTServer", "1433");
            MuOnlineDatabase = IniHelper.ReadValue(appPath + "/Config.ini", "SQL", "MuOnline", "MuOnline");
            MuRankingDatabase = IniHelper.ReadValue(appPath + "/Config.ini", "SQL", "MuRanking", "MuRanking");
            MuEventDatabase = IniHelper.ReadValue(appPath + "/Config.ini", "SQL", "MuEvent", "MuEvent");
            ExtendedWarehouseTable = IniHelper.ReadValue(appPath + "/Config.ini", "SQL", "ExtWareHouse", "ExtWareHouse");
            ResetColumnName = IniHelper.ReadValue(appPath + "/Config.ini", "SQL", "Reset", "Resets");
            CommandTimeout = Conversions.ToInteger(IniHelper.ReadValue(appPath + "/Config.ini", "SQL", "TimeLimit", "360"));

            // Load application settings
            Language = IniHelper.ReadValue(appPath + "/Config.ini", "Config", "Languaje", "Espanol");
            ExtraWarehouseCount = IniHelper.ReadValue(appPath + "/Config.ini", "Config", "NuExtraWareHouses", "0");
            ResetEnabled = IniHelper.ReadValue(appPath + "/Config.ini", "Config", "Reset", "0");
            Md5Enabled = IniHelper.ReadValue(appPath + "/Config.ini", "Config", "MD5", "0");
            FirstLoad = IniHelper.ReadValue(appPath + "/Config.ini", "Config", "FirstLoad", "0");
            AutoReload = IniHelper.ReadValue(appPath + "/Config.ini", "Config", "AutoReLoad", "0");

            // Load personal settings
            UserName = IniHelper.ReadValue(appPath + "/Config.ini", "Personal", "Name", "N00B");
            DaysConfig = IniHelper.ReadValue(appPath + "/Config.ini", "Personal", "DIAS", "30");
            CharacterSelection = IniHelper.ReadValue(appPath + "/Config.ini", "Personal", "PJ", "1");
            EffectsTopPosition = IniHelper.ReadValue(appPath + "/Config.ini", "FX", "Top", "0");
        }

        /// <summary>
        /// Generate hardware ID for licensing
        /// </summary>
        public static bool GenerateHardwareId()
        {
            try
            {
                if (string.Equals(HardwareId, "00000000") || string.Equals(HardwareId, ""))
                {
                    HardwareId = IniHelper.GenerateHardwareFingerprint();
                }
                return true;
            }
            catch (Exception)
            {
                HardwareId = "00000000";
                return false;
            }
        }
        #endregion
    }
}
