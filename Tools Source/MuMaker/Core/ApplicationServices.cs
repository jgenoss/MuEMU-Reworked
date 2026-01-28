// MuMaker - Application Services
// VB.NET Application infrastructure classes

using Microsoft.VisualBasic.ApplicationServices;
using Microsoft.VisualBasic.Devices;
using MuMaker;
using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace MuMaker.Core
{
    #region Application Base
    /// <summary>
    /// Console application base class for VB.NET compatibility
    /// </summary>
    [GeneratedCode("MyTemplate", "8.0.0.0")]
    [EditorBrowsable(EditorBrowsableState.Never)]
    public class MuMakerApplication : ConsoleApplicationBase
    {
        private static MuMakerApplication _instance;

        [DebuggerNonUserCode]
        public MuMakerApplication() { }

        #region Original Method Aliases (smethod_X backward compatibility)
        /// <summary>
        /// smethod_1 - Get application instance (singleton)
        /// </summary>
        public static MuMakerApplication smethod_1()
        {
            if (_instance == null)
                _instance = new MuMakerApplication();
            return _instance;
        }

        /// <summary>
        /// smethod_3 - Get application instance for startup (used in Main())
        /// </summary>
        public static MuMakerApplication smethod_3()
        {
            return smethod_1();
        }

        /// <summary>
        /// method_8 - Get the main startup form instance
        /// </summary>
        public Form method_8()
        {
            return MuMaker.MuMaker.DefInstance;
        }
        #endregion

        #region Descriptive Method Names
        /// <summary>Get application instance (singleton)</summary>
        public static MuMakerApplication GetInstance() => smethod_1();

        /// <summary>Get application instance for startup</summary>
        public static MuMakerApplication GetApplicationForStartup() => smethod_3();

        /// <summary>Get the main startup form instance</summary>
        public Form GetStartupForm() => method_8();
        #endregion
    }
    #endregion

    #region Computer Services
    /// <summary>
    /// Computer services class for VB.NET compatibility
    /// </summary>
    [EditorBrowsable(EditorBrowsableState.Never)]
    [GeneratedCode("MyTemplate", "8.0.0.0")]
    public class MuMakerComputer : Computer
    {
        [DebuggerHidden]
        [EditorBrowsable(EditorBrowsableState.Never)]
        public MuMakerComputer() { }
    }
    #endregion

    #region Application Project
    /// <summary>
    /// Main application project class - manages form instances and services
    /// </summary>
    [GeneratedCode("MyTemplate", "8.0.0.0")]
    public static class ApplicationProject
    {
        private static readonly ThreadSafeObjectProvider<MuMakerComputer> _computer = new ThreadSafeObjectProvider<MuMakerComputer>();
        private static readonly ThreadSafeObjectProvider<MuMakerApplication> _application = new ThreadSafeObjectProvider<MuMakerApplication>();
        private static readonly ThreadSafeObjectProvider<User> _user = new ThreadSafeObjectProvider<User>();
        private static ThreadSafeObjectProvider<FormManager> _forms = new ThreadSafeObjectProvider<FormManager>();

        /// <summary>Gets the Computer instance</summary>
        [DebuggerHidden]
        public static MuMakerComputer Computer => _computer.GetInstance();

        /// <summary>Gets the Application instance</summary>
        [DebuggerHidden]
        public static MuMakerApplication Application => _application.GetInstance();

        /// <summary>Gets the User instance</summary>
        [DebuggerHidden]
        public static User User => _user.GetInstance();

        /// <summary>Gets the Forms manager</summary>
        [DebuggerHidden]
        public static FormManager Forms => _forms.GetInstance();
    }
    #endregion

    #region Form Manager
    /// <summary>
    /// Manages form instances for the application
    /// </summary>
    [EditorBrowsable(EditorBrowsableState.Never)]
    public sealed class FormManager
    {
        #region Form Instance Fields
        private AccountMaker _accountMaker;
        private ConfigMaker _configMaker;
        private Creditos _creditos;
        private FinderMaker _finderMaker;
        private GuildMaker _guildMaker;
        private HelpMaker _helpMaker;
        private ItemMaker _itemMaker;
        private MoveMaker _moveMaker;
        private MuMaker.MuMaker _muMaker;
        private PJMaker _pjMaker;
        private SkillMaker _skillMaker;
        private SQLMaker _sqlMaker;
        private StatsMaker _statsMaker;
        private UpDateMaker _updateMaker;
        private VentanaBarraLoad _loadingWindow;

        [ThreadStatic]
        private static Hashtable _formCreationFlags;
        #endregion

        #region Form Accessors
        /// <summary>Gets or creates the AccountMaker form</summary>
        [DebuggerNonUserCode]
        public AccountMaker AccountMaker
        {
            get { _accountMaker = CreateFormInstance(_accountMaker); return _accountMaker; }
            set { if (value != _accountMaker && value != null) throw new ArgumentException("Property can only be set to Nothing"); DisposeForm(ref _accountMaker); }
        }

        /// <summary>Gets or creates the ConfigMaker form</summary>
        [DebuggerNonUserCode]
        public ConfigMaker ConfigMaker
        {
            get { _configMaker = CreateFormInstance(_configMaker); return _configMaker; }
            set { if (value != _configMaker && value != null) throw new ArgumentException("Property can only be set to Nothing"); DisposeForm(ref _configMaker); }
        }

        /// <summary>Gets or creates the Creditos form</summary>
        [DebuggerNonUserCode]
        public Creditos Creditos
        {
            get { _creditos = CreateFormInstance(_creditos); return _creditos; }
            set { if (value != _creditos && value != null) throw new ArgumentException("Property can only be set to Nothing"); DisposeForm(ref _creditos); }
        }

        /// <summary>Gets or creates the FinderMaker form</summary>
        [DebuggerNonUserCode]
        public FinderMaker FinderMaker
        {
            get { _finderMaker = CreateFormInstance(_finderMaker); return _finderMaker; }
            set { if (value != _finderMaker && value != null) throw new ArgumentException("Property can only be set to Nothing"); DisposeForm(ref _finderMaker); }
        }

        /// <summary>Gets or creates the GuildMaker form</summary>
        [DebuggerNonUserCode]
        public GuildMaker GuildMaker
        {
            get { _guildMaker = CreateFormInstance(_guildMaker); return _guildMaker; }
            set { if (value != _guildMaker && value != null) throw new ArgumentException("Property can only be set to Nothing"); DisposeForm(ref _guildMaker); }
        }

        /// <summary>Gets or creates the HelpMaker form</summary>
        [DebuggerNonUserCode]
        public HelpMaker HelpMaker
        {
            get { _helpMaker = CreateFormInstance(_helpMaker); return _helpMaker; }
            set { if (value != _helpMaker && value != null) throw new ArgumentException("Property can only be set to Nothing"); DisposeForm(ref _helpMaker); }
        }

        /// <summary>Gets or creates the ItemMaker form</summary>
        [DebuggerNonUserCode]
        public ItemMaker ItemMaker
        {
            get { _itemMaker = CreateFormInstance(_itemMaker); return _itemMaker; }
            set { if (value != _itemMaker && value != null) throw new ArgumentException("Property can only be set to Nothing"); DisposeForm(ref _itemMaker); }
        }

        /// <summary>Gets or creates the MoveMaker form</summary>
        [DebuggerNonUserCode]
        public MoveMaker MoveMaker
        {
            get { _moveMaker = CreateFormInstance(_moveMaker); return _moveMaker; }
            set { if (value != _moveMaker && value != null) throw new ArgumentException("Property can only be set to Nothing"); DisposeForm(ref _moveMaker); }
        }

        /// <summary>Gets or creates the main MuMaker form</summary>
        [DebuggerNonUserCode]
        public MuMaker.MuMaker MuMaker
        {
            get { _muMaker = CreateFormInstance(_muMaker); return _muMaker; }
            set { if (value != _muMaker && value != null) throw new ArgumentException("Property can only be set to Nothing"); DisposeForm(ref _muMaker); }
        }

        /// <summary>Gets or creates the PJMaker form</summary>
        [DebuggerNonUserCode]
        public PJMaker PJMaker
        {
            get { _pjMaker = CreateFormInstance(_pjMaker); return _pjMaker; }
            set { if (value != _pjMaker && value != null) throw new ArgumentException("Property can only be set to Nothing"); DisposeForm(ref _pjMaker); }
        }

        /// <summary>Gets or creates the SkillMaker form</summary>
        [DebuggerNonUserCode]
        public SkillMaker SkillMaker
        {
            get { _skillMaker = CreateFormInstance(_skillMaker); return _skillMaker; }
            set { if (value != _skillMaker && value != null) throw new ArgumentException("Property can only be set to Nothing"); DisposeForm(ref _skillMaker); }
        }

        /// <summary>Gets or creates the SQLMaker form</summary>
        [DebuggerNonUserCode]
        public SQLMaker SQLMaker
        {
            get { _sqlMaker = CreateFormInstance(_sqlMaker); return _sqlMaker; }
            set { if (value != _sqlMaker && value != null) throw new ArgumentException("Property can only be set to Nothing"); DisposeForm(ref _sqlMaker); }
        }

        /// <summary>Gets or creates the StatsMaker form</summary>
        [DebuggerNonUserCode]
        public StatsMaker StatsMaker
        {
            get { _statsMaker = CreateFormInstance(_statsMaker); return _statsMaker; }
            set { if (value != _statsMaker && value != null) throw new ArgumentException("Property can only be set to Nothing"); DisposeForm(ref _statsMaker); }
        }

        /// <summary>Gets or creates the UpDateMaker form</summary>
        [DebuggerNonUserCode]
        public UpDateMaker UpDateMaker
        {
            get { _updateMaker = CreateFormInstance(_updateMaker); return _updateMaker; }
            set { if (value != _updateMaker && value != null) throw new ArgumentException("Property can only be set to Nothing"); DisposeForm(ref _updateMaker); }
        }

        /// <summary>Gets or creates the Loading Window form</summary>
        [DebuggerNonUserCode]
        public VentanaBarraLoad LoadingWindow
        {
            get { _loadingWindow = CreateFormInstance(_loadingWindow); return _loadingWindow; }
            set { if (value != _loadingWindow && value != null) throw new ArgumentException("Property can only be set to Nothing"); DisposeForm(ref _loadingWindow); }
        }
        #endregion

        #region Helper Methods
        [DebuggerHidden]
        private static T CreateFormInstance<T>(T existingForm) where T : Form, new()
        {
            if (existingForm != null && !existingForm.IsDisposed)
                return existingForm;

            if (_formCreationFlags == null)
                _formCreationFlags = new Hashtable();
            else if (_formCreationFlags.ContainsKey(typeof(T)))
                throw new InvalidOperationException("Recursive form creation detected");

            _formCreationFlags.Add(typeof(T), null);
            try
            {
                return Activator.CreateInstance<T>();
            }
            catch (TargetInvocationException ex) when (ex.InnerException != null)
            {
                throw new InvalidOperationException("Form creation failed: " + ex.InnerException.Message, ex.InnerException);
            }
            finally
            {
                _formCreationFlags.Remove(typeof(T));
            }
        }

        [DebuggerHidden]
        private void DisposeForm<T>(ref T form) where T : Form
        {
            form?.Dispose();
            form = default;
        }
        #endregion
    }
    #endregion

    #region Thread-Safe Object Provider
    /// <summary>
    /// Thread-safe lazy initialization provider
    /// </summary>
    [ComVisible(false)]
    [EditorBrowsable(EditorBrowsableState.Never)]
    public sealed class ThreadSafeObjectProvider<T> where T : new()
    {
        private static T _instance;

        [DebuggerHidden]
        [EditorBrowsable(EditorBrowsableState.Never)]
        public ThreadSafeObjectProvider() { }

        [DebuggerHidden]
        public T GetInstance()
        {
            if (_instance == null)
                _instance = Activator.CreateInstance<T>();
            return _instance;
        }
    }
    #endregion
}
