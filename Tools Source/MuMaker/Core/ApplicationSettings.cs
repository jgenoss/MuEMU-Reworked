// MuMaker - Application Settings
// Refactored from Class35

using System.CodeDom.Compiler;
using System.ComponentModel;
using System.Configuration;
using System.Diagnostics;
using System.Runtime.CompilerServices;

namespace MuMaker.Core
{
    /// <summary>
    /// Application settings provider using .NET ApplicationSettingsBase
    /// </summary>
    [CompilerGenerated]
    [EditorBrowsable(EditorBrowsableState.Advanced)]
    [GeneratedCode("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "9.0.0.0")]
    internal sealed class ApplicationSettings : ApplicationSettingsBase
    {
        private static ApplicationSettings _defaultInstance =
            (ApplicationSettings)SettingsBase.Synchronized((SettingsBase)new ApplicationSettings());

        /// <summary>
        /// Default constructor
        /// </summary>
        [DebuggerNonUserCode]
        public ApplicationSettings()
        {
        }

        /// <summary>
        /// Gets the singleton instance of application settings
        /// </summary>
        [SpecialName]
        public static ApplicationSettings GetDefault()
        {
            return _defaultInstance;
        }
    }
}
