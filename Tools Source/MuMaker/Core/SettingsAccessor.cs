// MuMaker - Settings Accessor
// Refactored from Class36

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using System.Diagnostics;
using System.Runtime.CompilerServices;

namespace MuMaker.Core
{
    /// <summary>
    /// Helper module to access application settings
    /// </summary>
    [StandardModule]
    [CompilerGenerated]
    [HideModuleName]
    [DebuggerNonUserCode]
    internal sealed class SettingsAccessor
    {
        /// <summary>
        /// Gets the default application settings instance
        /// </summary>
        [SpecialName]
        internal static ApplicationSettings GetSettings()
        {
            return ApplicationSettings.GetDefault();
        }
    }
}
