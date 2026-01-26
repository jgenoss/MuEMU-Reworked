using Microsoft.VisualBasic;
using Microsoft.VisualBasic.ApplicationServices;
using Microsoft.VisualBasic.CompilerServices;
using MuMaker;
using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Windows.Forms;

[GeneratedCode("MyTemplate", "8.0.0.0")]
[HideModuleName]
[StandardModule]
internal sealed class Class2
{
    private readonly static Class2.Class5<Class1> class5_0;

    private readonly static Class2.Class5<Class0> class5_1;

    private readonly static Class2.Class5<User> class5_2;

    private static Class2.Class5<Class2.Class3> class5_3;

    private readonly static Class2.Class5<Class2.Class4> class5_4;

    [DebuggerNonUserCode]
    static Class2()
    {
        Class2.class5_0 = new Class2.Class5<Class1>();
        Class2.class5_1 = new Class2.Class5<Class0>();
        Class2.class5_2 = new Class2.Class5<User>();
        Class2.class5_3 = new Class2.Class5<Class2.Class3>();
        Class2.class5_4 = new Class2.Class5<Class2.Class4>();
    }

    [DebuggerHidden]
    internal static Class1 smethod_0()
    {
        return Class2.class5_0.method_0();
    }

    [DebuggerHidden]
    internal static Class0 smethod_1()
    {
        return Class2.class5_1.method_0();
    }

    [DebuggerHidden]
    internal static User smethod_2()
    {
        return Class2.class5_2.method_0();
    }

    [DebuggerHidden]
    internal static Class2.Class3 smethod_3()
    {
        return Class2.class5_3.method_0();
    }

    [DebuggerHidden]
    internal static Class2.Class4 smethod_4()
    {
        return Class2.class5_4.method_0();
    }

    [EditorBrowsable(EditorBrowsableState.Never)]
    [MyGroupCollection("System.Windows.Forms.Form", "Create__Instance__", "Dispose__Instance__", "My.MyProject.Forms")]
    internal sealed class Class3
    {
        public AccountMaker accountMaker_0;

        public ConfigMaker configMaker_0;

        public Creditos creditos_0;

        public FinderMaker finderMaker_0;

        public GuildMaker guildMaker_0;

        public HelpMaker helpMaker_0;

        public ItemMaker itemMaker_0;

        public MoveMaker moveMaker_0;

        public MuMaker.MuMaker muMaker_0;

        public PJMaker pjmaker_0;

        public SkillMaker skillMaker_0;

        public SQLMaker sqlmaker_0;

        public StatsMaker statsMaker_0;

        public UpDateMaker upDateMaker_0;

        public VentanaBarraLoad ventanaBarraLoad_0;

        [ThreadStatic]
        private static Hashtable hashtable_0;

        [DebuggerHidden]
        [EditorBrowsable(EditorBrowsableState.Never)]
        public Class3()
        {
        }

        [DebuggerNonUserCode]
        public AccountMaker method_0()
        {
            this.accountMaker_0 = Class2.Class3.smethod_0<AccountMaker>(this.accountMaker_0);
            return this.accountMaker_0;
        }

        [DebuggerNonUserCode]
        public ConfigMaker method_1()
        {
            this.configMaker_0 = Class2.Class3.smethod_0<ConfigMaker>(this.configMaker_0);
            return this.configMaker_0;
        }

        [DebuggerNonUserCode]
        public SkillMaker method_10()
        {
            this.skillMaker_0 = Class2.Class3.smethod_0<SkillMaker>(this.skillMaker_0);
            return this.skillMaker_0;
        }

        [DebuggerNonUserCode]
        public SQLMaker method_11()
        {
            this.sqlmaker_0 = Class2.Class3.smethod_0<SQLMaker>(this.sqlmaker_0);
            return this.sqlmaker_0;
        }

        [DebuggerNonUserCode]
        public StatsMaker method_12()
        {
            this.statsMaker_0 = Class2.Class3.smethod_0<StatsMaker>(this.statsMaker_0);
            return this.statsMaker_0;
        }

        [DebuggerNonUserCode]
        public UpDateMaker method_13()
        {
            this.upDateMaker_0 = Class2.Class3.smethod_0<UpDateMaker>(this.upDateMaker_0);
            return this.upDateMaker_0;
        }

        [DebuggerNonUserCode]
        public VentanaBarraLoad method_14()
        {
            this.ventanaBarraLoad_0 = Class2.Class3.smethod_0<VentanaBarraLoad>(this.ventanaBarraLoad_0);
            return this.ventanaBarraLoad_0;
        }

        [DebuggerNonUserCode]
        public void method_15(AccountMaker accountMaker_1)
        {
            if (accountMaker_1 == this.accountMaker_0)
            {
                return;
            }
            if (accountMaker_1 != null)
            {
                throw new ArgumentException("Property can only be set to Nothing");
            }
            this.method_30<AccountMaker>(ref this.accountMaker_0);
        }

        [DebuggerNonUserCode]
        public void method_16(ConfigMaker configMaker_1)
        {
            if (configMaker_1 == this.configMaker_0)
            {
                return;
            }
            if (configMaker_1 != null)
            {
                throw new ArgumentException("Property can only be set to Nothing");
            }
            this.method_30<ConfigMaker>(ref this.configMaker_0);
        }

        [DebuggerNonUserCode]
        public void method_17(Creditos creditos_1)
        {
            if (creditos_1 == this.creditos_0)
            {
                return;
            }
            if (creditos_1 != null)
            {
                throw new ArgumentException("Property can only be set to Nothing");
            }
            this.method_30<Creditos>(ref this.creditos_0);
        }

        [DebuggerNonUserCode]
        public void method_18(FinderMaker finderMaker_1)
        {
            if (finderMaker_1 == this.finderMaker_0)
            {
                return;
            }
            if (finderMaker_1 != null)
            {
                throw new ArgumentException("Property can only be set to Nothing");
            }
            this.method_30<FinderMaker>(ref this.finderMaker_0);
        }

        [DebuggerNonUserCode]
        public void method_19(GuildMaker guildMaker_1)
        {
            if (guildMaker_1 == this.guildMaker_0)
            {
                return;
            }
            if (guildMaker_1 != null)
            {
                throw new ArgumentException("Property can only be set to Nothing");
            }
            this.method_30<GuildMaker>(ref this.guildMaker_0);
        }

        [DebuggerNonUserCode]
        public Creditos method_2()
        {
            this.creditos_0 = Class2.Class3.smethod_0<Creditos>(this.creditos_0);
            return this.creditos_0;
        }

        [DebuggerNonUserCode]
        public void method_20(HelpMaker helpMaker_1)
        {
            if (helpMaker_1 == this.helpMaker_0)
            {
                return;
            }
            if (helpMaker_1 != null)
            {
                throw new ArgumentException("Property can only be set to Nothing");
            }
            this.method_30<HelpMaker>(ref this.helpMaker_0);
        }

        [DebuggerNonUserCode]
        public void method_21(ItemMaker itemMaker_1)
        {
            if (itemMaker_1 == this.itemMaker_0)
            {
                return;
            }
            if (itemMaker_1 != null)
            {
                throw new ArgumentException("Property can only be set to Nothing");
            }
            this.method_30<ItemMaker>(ref this.itemMaker_0);
        }

        [DebuggerNonUserCode]
        public void method_22(MoveMaker moveMaker_1)
        {
            if (moveMaker_1 == this.moveMaker_0)
            {
                return;
            }
            if (moveMaker_1 != null)
            {
                throw new ArgumentException("Property can only be set to Nothing");
            }
            this.method_30<MoveMaker>(ref this.moveMaker_0);
        }

        [DebuggerNonUserCode]
        public void method_23(MuMaker.MuMaker muMaker_1)
        {
            if (muMaker_1 == this.muMaker_0)
            {
                return;
            }
            if (muMaker_1 != null)
            {
                throw new ArgumentException("Property can only be set to Nothing");
            }
            this.method_30<MuMaker.MuMaker>(ref this.muMaker_0);
        }

        [DebuggerNonUserCode]
        public void method_24(PJMaker pjmaker_1)
        {
            if (pjmaker_1 == this.pjmaker_0)
            {
                return;
            }
            if (pjmaker_1 != null)
            {
                throw new ArgumentException("Property can only be set to Nothing");
            }
            this.method_30<PJMaker>(ref this.pjmaker_0);
        }

        [DebuggerNonUserCode]
        public void method_25(SkillMaker skillMaker_1)
        {
            if (skillMaker_1 == this.skillMaker_0)
            {
                return;
            }
            if (skillMaker_1 != null)
            {
                throw new ArgumentException("Property can only be set to Nothing");
            }
            this.method_30<SkillMaker>(ref this.skillMaker_0);
        }

        [DebuggerNonUserCode]
        public void method_26(SQLMaker sqlmaker_1)
        {
            if (sqlmaker_1 == this.sqlmaker_0)
            {
                return;
            }
            if (sqlmaker_1 != null)
            {
                throw new ArgumentException("Property can only be set to Nothing");
            }
            this.method_30<SQLMaker>(ref this.sqlmaker_0);
        }

        [DebuggerNonUserCode]
        public void method_27(StatsMaker statsMaker_1)
        {
            if (statsMaker_1 == this.statsMaker_0)
            {
                return;
            }
            if (statsMaker_1 != null)
            {
                throw new ArgumentException("Property can only be set to Nothing");
            }
            this.method_30<StatsMaker>(ref this.statsMaker_0);
        }

        [DebuggerNonUserCode]
        public void method_28(UpDateMaker upDateMaker_1)
        {
            if (upDateMaker_1 == this.upDateMaker_0)
            {
                return;
            }
            if (upDateMaker_1 != null)
            {
                throw new ArgumentException("Property can only be set to Nothing");
            }
            this.method_30<UpDateMaker>(ref this.upDateMaker_0);
        }

        [DebuggerNonUserCode]
        public void method_29(VentanaBarraLoad ventanaBarraLoad_1)
        {
            if (ventanaBarraLoad_1 == this.ventanaBarraLoad_0)
            {
                return;
            }
            if (ventanaBarraLoad_1 != null)
            {
                throw new ArgumentException("Property can only be set to Nothing");
            }
            this.method_30<VentanaBarraLoad>(ref this.ventanaBarraLoad_0);
        }

        [DebuggerNonUserCode]
        public FinderMaker method_3()
        {
            this.finderMaker_0 = Class2.Class3.smethod_0<FinderMaker>(this.finderMaker_0);
            return this.finderMaker_0;
        }

        [DebuggerHidden]
        private void method_30<T>(ref T gparam_0)
        where T : Form
        {
            gparam_0.Dispose();
            gparam_0 = default(T);
        }

        [EditorBrowsable(EditorBrowsableState.Never)]
        internal Type method_31()
        {
            return typeof(Class2.Class3);
        }

        [DebuggerNonUserCode]
        public GuildMaker method_4()
        {
            this.guildMaker_0 = Class2.Class3.smethod_0<GuildMaker>(this.guildMaker_0);
            return this.guildMaker_0;
        }

        [DebuggerNonUserCode]
        public HelpMaker method_5()
        {
            this.helpMaker_0 = Class2.Class3.smethod_0<HelpMaker>(this.helpMaker_0);
            return this.helpMaker_0;
        }

        [DebuggerNonUserCode]
        public ItemMaker method_6()
        {
            this.itemMaker_0 = Class2.Class3.smethod_0<ItemMaker>(this.itemMaker_0);
            return this.itemMaker_0;
        }

        [DebuggerNonUserCode]
        public MoveMaker method_7()
        {
            this.moveMaker_0 = Class2.Class3.smethod_0<MoveMaker>(this.moveMaker_0);
            return this.moveMaker_0;
        }

        [DebuggerNonUserCode]
        public MuMaker.MuMaker method_8()
        {
            this.muMaker_0 = Class2.Class3.smethod_0<MuMaker.MuMaker>(this.muMaker_0);
            return this.muMaker_0;
        }

        [DebuggerNonUserCode]
        public PJMaker method_9()
        {
            this.pjmaker_0 = Class2.Class3.smethod_0<PJMaker>(this.pjmaker_0);
            return this.pjmaker_0;
        }

        [DebuggerHidden]
        private static T smethod_0<T>(T gparam_0)
        where T : Form, new()
        {
            T t;
            if (gparam_0 != null && !gparam_0.IsDisposed)
            {
                return gparam_0;
            }
            if (Class2.Class3.hashtable_0 == null)
            {
                Class2.Class3.hashtable_0 = new Hashtable();
            }
            else if (Class2.Class3.hashtable_0.ContainsKey(typeof(T)))
            {
                throw new InvalidOperationException(Utils.GetResourceString("WinForms_RecursiveFormCreate", new string[0]));
            }
            Class2.Class3.hashtable_0.Add(typeof(T), null);
            try
            {
                try
                {
                    t = Activator.CreateInstance<T>();
                }
                catch (TargetInvocationException targetInvocationException) when (targetInvocationException.InnerException != null)
                {
                    string[] message = new string[] { targetInvocationException.InnerException.Message };
                    string resourceString = Utils.GetResourceString("WinForms_SeeInnerException", message);
                    throw new InvalidOperationException(resourceString, targetInvocationException.InnerException);
                }
            }
            finally
            {
                Class2.Class3.hashtable_0.Remove(typeof(T));
            }
            return t;
        }

        /* [EditorBrowsable(EditorBrowsableState.Never)]
         public override bool System.Object.Equals(object object_0)
         {
             return this.Equals(RuntimeHelpers.GetObjectValue(object_0));
         }

         [EditorBrowsable(EditorBrowsableState.Never)]
         public override int System.Object.GetHashCode()
         {
             return this.GetHashCode();
         }

         [EditorBrowsable(EditorBrowsableState.Never)]
         public override string System.Object.ToString()
         {
             return this.ToString();
         }*/
    }

    [EditorBrowsable(EditorBrowsableState.Never)]
    [MyGroupCollection("System.Web.Services.Protocols.SoapHttpClientProtocol", "Create__Instance__", "Dispose__Instance__", "")]
    internal sealed class Class4
    {
        [DebuggerHidden]
        [EditorBrowsable(EditorBrowsableState.Never)]
        public Class4()
        {
        }

        [DebuggerHidden]
        [EditorBrowsable(EditorBrowsableState.Never)]
        internal Type method_0()
        {
            return typeof(Class2.Class4);
        }

        [DebuggerHidden]
        private void method_1<T>(ref T gparam_0)
        {
            gparam_0 = default(T);
        }

        [DebuggerHidden]
        private static T smethod_0<T>(T gparam_0)
        where T : new()
        {
            if (gparam_0 == null)
            {
                return Activator.CreateInstance<T>();
            }
            return gparam_0;
        }

        /* [DebuggerHidden]
         [EditorBrowsable(EditorBrowsableState.Never)]
         public override bool System.Object.Equals(object object_0)
         {
             return this.Equals(RuntimeHelpers.GetObjectValue(object_0));
         }

         [DebuggerHidden]
         [EditorBrowsable(EditorBrowsableState.Never)]
         public override int System.Object.GetHashCode()
         {
             return this.GetHashCode();
         }

         [DebuggerHidden]
         [EditorBrowsable(EditorBrowsableState.Never)]
         public override string System.Object.ToString()
         {
             return this.ToString();
         }*/
    }

    [ComVisible(false)]
    [EditorBrowsable(EditorBrowsableState.Never)]
    internal sealed class Class5<T>
    where T : new()
    {
        private static T gparam_0;

        [DebuggerHidden]
        [EditorBrowsable(EditorBrowsableState.Never)]
        public Class5()
        {
        }

        [DebuggerHidden]
        internal T method_0()
        {
            if (Class2.Class5<T>.gparam_0 == null)
            {
                Class2.Class5<T>.gparam_0 = Activator.CreateInstance<T>();
            }
            return Class2.Class5<T>.gparam_0;
        }
    }
}