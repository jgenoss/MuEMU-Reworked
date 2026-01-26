// Decompiled with JetBrains decompiler
// Type: MuMaker.MuMaker
// Assembly: MuMaker, Version=1.1.3.0, Culture=neutral, PublicKeyToken=null
// MVID: 7E43A6C6-04AF-4159-BD3A-BD25660D1460
// Assembly location: D:\MuServer\Tools\MuMaker 1.13\MuMaker-cleaned.exe

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Runtime.CompilerServices;
using System.Threading;
using System.Windows.Forms;

namespace MuMaker
{
  [DesignerGenerated]
  public class MuMaker : Form
  {
    private IContainer icontainer_0;
    [AccessedThroughProperty("ToolTips")]
    private ToolTip toolTip_0;
    [AccessedThroughProperty("TopOnOff")]
    private CheckBox _TopOnOff;
    [AccessedThroughProperty("BanderaID")]
    private PictureBox _BanderaID;
    [AccessedThroughProperty("InicialesIdioma")]
    private Label _InicialesIdioma;
    [AccessedThroughProperty("Reloj")]
    private System.Windows.Forms.Timer timer_0;
    [AccessedThroughProperty("Label1")]
    private Label _Label1;
    [AccessedThroughProperty("Boton2")]
    private Button _Boton2;
    [AccessedThroughProperty("Boton6")]
    private Button _Boton6;
    [AccessedThroughProperty("Boton5")]
    private Button _Boton5;
    [AccessedThroughProperty("Boton4")]
    private Button _Boton4;
    [AccessedThroughProperty("BotonFinderMaker")]
    private Button _BotonFinderMaker;
    [AccessedThroughProperty("UpDater")]
    private Label _UpDater;
    [AccessedThroughProperty("RealVersion")]
    private Label _RealVersion;
    [AccessedThroughProperty("MMKNM")]
    private Label _MMKNM;
    [AccessedThroughProperty("StatusMenu")]
    private ContextMenu contextMenu_0;
    [AccessedThroughProperty("MenuAccountMaker")]
    private MenuItem menuItem_0;
    [AccessedThroughProperty("MenuItemMaker")]
    private MenuItem menuItem_1;
    [AccessedThroughProperty("MenuSkillMaker")]
    private MenuItem menuItem_2;
    [AccessedThroughProperty("MenuMoveMaker")]
    private MenuItem menuItem_3;
    [AccessedThroughProperty("BotonSQLMaker")]
    private Button _BotonSQLMaker;
    [AccessedThroughProperty("Boton7")]
    private Button _Boton7;
    [AccessedThroughProperty("BUpDate")]
    private Button _BUpDate;
    [AccessedThroughProperty("BotonCreditos")]
    private LinkLabel _BotonCreditos;
    [AccessedThroughProperty("Minimizar")]
    private Button _Minimizar;
    [AccessedThroughProperty("Cerrar")]
    private Button _Cerrar;
    [AccessedThroughProperty("BotonConfig")]
    private Button _BotonConfig;
    [AccessedThroughProperty("PictureBox2")]
    private PictureBox _PictureBox2;
    [AccessedThroughProperty("BotonSkillMaker")]
    private Button _BotonSkillMaker;
    [AccessedThroughProperty("BotonItemMaker")]
    private Button _BotonItemMaker;
    [AccessedThroughProperty("BotonGuildMaker")]
    private Button _BotonGuildMaker;
    [AccessedThroughProperty("BotonMoveMaker")]
    private Button _BotonMoveMaker;
    [AccessedThroughProperty("SysTrayIcon")]
    private NotifyIcon notifyIcon_0;
    [AccessedThroughProperty("BotonAccountMaker")]
    private Button _BotonAccountMaker;
    [AccessedThroughProperty("MenuGuildMaker")]
    private MenuItem menuItem_4;
    [AccessedThroughProperty("MenuFinderMaker")]
    private MenuItem menuItem_5;
    [AccessedThroughProperty("MenuXxMaker4")]
    private MenuItem menuItem_6;
    [AccessedThroughProperty("MenuXxMaker5")]
    private MenuItem menuItem_7;
    [AccessedThroughProperty("MenuXxMaker6")]
    private MenuItem menuItem_8;
    [AccessedThroughProperty("MenuXxMaker7")]
    private MenuItem menuItem_9;
    [AccessedThroughProperty("MenuXxMaker2")]
    private MenuItem menuItem_10;
    [AccessedThroughProperty("MenuSQLMaker")]
    private MenuItem menuItem_11;
    [AccessedThroughProperty("MenuCerrar")]
    private MenuItem menuItem_12;
    [AccessedThroughProperty("PayPal1")]
    private PictureBox _PayPal1;
    [AccessedThroughProperty("UPDTimer")]
    private System.Windows.Forms.Timer timer_1;
    [AccessedThroughProperty("PayPal2")]
    private PictureBox _PayPal2;
    [AccessedThroughProperty("BotonConectarSQL")]
    private Button _BotonConectarSQL;
    [AccessedThroughProperty("BotonCerrarLoging")]
    private Button _BotonCerrarLoging;
    [AccessedThroughProperty("LogingSQL")]
    private PictureBox _LogingSQL;
    [AccessedThroughProperty("BotonLogingSQL")]
    private Button _BotonLogingSQL;
    [AccessedThroughProperty("UserSQL")]
    private TextBox _UserSQL;
    [AccessedThroughProperty("PswSQL")]
    private TextBox _PswSQL;
    [AccessedThroughProperty("MenuSeparador1")]
    private MenuItem menuItem_13;
    [AccessedThroughProperty("MenuReload")]
    private MenuItem menuItem_14;
    [AccessedThroughProperty("MenuSeparador2")]
    private MenuItem menuItem_15;
    [AccessedThroughProperty("CHVersion")]
    private System.Windows.Forms.Timer timer_2;
    [AccessedThroughProperty("ClientSuport")]
    private Label _ClientSuport;
    [AccessedThroughProperty("LabelInfo")]
    private Label _LabelInfo;
    [AccessedThroughProperty("Cuentas")]
    private ComboBox _Cuentas;
    [AccessedThroughProperty("CodigoOculto")]
    private GroupBox _CodigoOculto;
    [AccessedThroughProperty("Navegador")]
    private WebBrowser _Navegador;
    [AccessedThroughProperty("CKUPDT")]
    private CheckBox _CKUPDT;
    [AccessedThroughProperty("BotonReload")]
    private Button _BotonReload;
    [AccessedThroughProperty("CargaCuentasProgres")]
    private ProgressBar _CargaCuentasProgres;
    [AccessedThroughProperty("DeLoadAcc")]
    private System.Windows.Forms.Timer timer_3;
    [AccessedThroughProperty("BotonHelp")]
    private Button _BotonHelp;
    [AccessedThroughProperty("MenuHelpGuide")]
    private MenuItem menuItem_16;
    [AccessedThroughProperty("ClientKOR")]
    private Label _ClientKOR;
    [AccessedThroughProperty("ClientCHN")]
    private Label _ClientCHN;
    [AccessedThroughProperty("ClientJPN")]
    private Label _ClientJPN;
    private const int int_0 = 132;
    private const int int_1 = 1;
    private const int int_2 = 2;

    internal virtual ToolTip ToolTips
    {
      [DebuggerNonUserCode] get
      {
        return this.toolTip_0;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this.toolTip_0 = value;
      }
    }

    internal virtual CheckBox TopOnOff
    {
      [DebuggerNonUserCode] get
      {
        return this._TopOnOff;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.TopOnOff_CheckedChanged);
        if (this._TopOnOff != null)
          this._TopOnOff.CheckedChanged -= eventHandler;
        this._TopOnOff = value;
        if (this._TopOnOff == null)
          return;
        this._TopOnOff.CheckedChanged += eventHandler;
      }
    }

    internal virtual PictureBox BanderaID
    {
      [DebuggerNonUserCode] get
      {
        return this._BanderaID;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._BanderaID = value;
      }
    }

    internal virtual Label InicialesIdioma
    {
      [DebuggerNonUserCode] get
      {
        return this._InicialesIdioma;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._InicialesIdioma = value;
      }
    }

    internal virtual System.Windows.Forms.Timer Reloj
    {
      [DebuggerNonUserCode] get
      {
        return this.timer_0;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Reloj_Tick);
        if (this.timer_0 != null)
          this.timer_0.Tick -= eventHandler;
        this.timer_0 = value;
        if (this.timer_0 == null)
          return;
        this.timer_0.Tick += eventHandler;
      }
    }

    internal virtual Label Label1
    {
      [DebuggerNonUserCode] get
      {
        return this._Label1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label1 = value;
      }
    }

    internal virtual Button Boton2
    {
      [DebuggerNonUserCode] get
      {
        return this._Boton2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Boton2 = value;
      }
    }

    internal virtual Button Boton6
    {
      [DebuggerNonUserCode] get
      {
        return this._Boton6;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Boton6 = value;
      }
    }

    internal virtual Button Boton5
    {
      [DebuggerNonUserCode] get
      {
        return this._Boton5;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Boton5 = value;
      }
    }

    internal virtual Button Boton4
    {
      [DebuggerNonUserCode] get
      {
        return this._Boton4;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Boton4 = value;
      }
    }

    internal virtual Button BotonFinderMaker
    {
      [DebuggerNonUserCode] get
      {
        return this._BotonFinderMaker;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_7);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_32);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_31);
        if (this._BotonFinderMaker != null)
        {
          this._BotonFinderMaker.Click -= eventHandler;
          this._BotonFinderMaker.MouseDown -= mouseEventHandler1;
          this._BotonFinderMaker.MouseUp -= mouseEventHandler2;
        }
        this._BotonFinderMaker = value;
        if (this._BotonFinderMaker == null)
          return;
        this._BotonFinderMaker.Click += eventHandler;
        this._BotonFinderMaker.MouseDown += mouseEventHandler1;
        this._BotonFinderMaker.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual Label UpDater
    {
      [DebuggerNonUserCode] get
      {
        return this._UpDater;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._UpDater = value;
      }
    }

    internal virtual Label RealVersion
    {
      [DebuggerNonUserCode] get
      {
        return this._RealVersion;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._RealVersion = value;
      }
    }

    internal virtual Label MMKNM
    {
      [DebuggerNonUserCode] get
      {
        return this._MMKNM;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._MMKNM = value;
      }
    }

    internal virtual ContextMenu StatusMenu
    {
      [DebuggerNonUserCode] get
      {
        return this.contextMenu_0;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this.contextMenu_0 = value;
      }
    }

    internal virtual MenuItem MenuAccountMaker
    {
      [DebuggerNonUserCode] get
      {
        return this.menuItem_0;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MenuAccountMaker_Click);
        if (this.menuItem_0 != null)
          this.menuItem_0.Click -= eventHandler;
        this.menuItem_0 = value;
        if (this.menuItem_0 == null)
          return;
        this.menuItem_0.Click += eventHandler;
      }
    }

    internal virtual MenuItem MenuItemMaker
    {
      [DebuggerNonUserCode] get
      {
        return this.menuItem_1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MenuItemMaker_Click);
        if (this.menuItem_1 != null)
          this.menuItem_1.Click -= eventHandler;
        this.menuItem_1 = value;
        if (this.menuItem_1 == null)
          return;
        this.menuItem_1.Click += eventHandler;
      }
    }

    internal virtual MenuItem MenuSkillMaker
    {
      [DebuggerNonUserCode] get
      {
        return this.menuItem_2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MenuSkillMaker_Click);
        if (this.menuItem_2 != null)
          this.menuItem_2.Click -= eventHandler;
        this.menuItem_2 = value;
        if (this.menuItem_2 == null)
          return;
        this.menuItem_2.Click += eventHandler;
      }
    }

    internal virtual MenuItem MenuMoveMaker
    {
      [DebuggerNonUserCode] get
      {
        return this.menuItem_3;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MenuMoveMaker_Click);
        if (this.menuItem_3 != null)
          this.menuItem_3.Click -= eventHandler;
        this.menuItem_3 = value;
        if (this.menuItem_3 == null)
          return;
        this.menuItem_3.Click += eventHandler;
      }
    }

    internal virtual Button BotonSQLMaker
    {
      [DebuggerNonUserCode] get
      {
        return this._BotonSQLMaker;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_8);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_34);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_33);
        if (this._BotonSQLMaker != null)
        {
          this._BotonSQLMaker.Click -= eventHandler;
          this._BotonSQLMaker.MouseDown -= mouseEventHandler1;
          this._BotonSQLMaker.MouseUp -= mouseEventHandler2;
        }
        this._BotonSQLMaker = value;
        if (this._BotonSQLMaker == null)
          return;
        this._BotonSQLMaker.Click += eventHandler;
        this._BotonSQLMaker.MouseDown += mouseEventHandler1;
        this._BotonSQLMaker.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual Button Boton7
    {
      [DebuggerNonUserCode] get
      {
        return this._Boton7;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Boton7 = value;
      }
    }

    internal virtual Button BUpDate
    {
      [DebuggerNonUserCode] get
      {
        return this._BUpDate;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.BUpDate_Click);
        if (this._BUpDate != null)
          this._BUpDate.Click -= eventHandler;
        this._BUpDate = value;
        if (this._BUpDate == null)
          return;
        this._BUpDate.Click += eventHandler;
      }
    }

    internal virtual LinkLabel BotonCreditos
    {
      [DebuggerNonUserCode] get
      {
        return this._BotonCreditos;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        LinkLabelLinkClickedEventHandler clickedEventHandler = new LinkLabelLinkClickedEventHandler(this.BotonCreditos_LinkClicked);
        if (this._BotonCreditos != null)
          this._BotonCreditos.LinkClicked -= clickedEventHandler;
        this._BotonCreditos = value;
        if (this._BotonCreditos == null)
          return;
        this._BotonCreditos.LinkClicked += clickedEventHandler;
      }
    }

    internal virtual Button Minimizar
    {
      [DebuggerNonUserCode] get
      {
        return this._Minimizar;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_14);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_18);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_17);
        if (this._Minimizar != null)
        {
          this._Minimizar.Click -= eventHandler;
          this._Minimizar.MouseDown -= mouseEventHandler1;
          this._Minimizar.MouseUp -= mouseEventHandler2;
        }
        this._Minimizar = value;
        if (this._Minimizar == null)
          return;
        this._Minimizar.Click += eventHandler;
        this._Minimizar.MouseDown += mouseEventHandler1;
        this._Minimizar.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual Button Cerrar
    {
      [DebuggerNonUserCode] get
      {
        return this._Cerrar;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_13);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_20);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_19);
        if (this._Cerrar != null)
        {
          this._Cerrar.Click -= eventHandler;
          this._Cerrar.MouseDown -= mouseEventHandler1;
          this._Cerrar.MouseUp -= mouseEventHandler2;
        }
        this._Cerrar = value;
        if (this._Cerrar == null)
          return;
        this._Cerrar.Click += eventHandler;
        this._Cerrar.MouseDown += mouseEventHandler1;
        this._Cerrar.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual Button BotonConfig
    {
      [DebuggerNonUserCode] get
      {
        return this._BotonConfig;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_9);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_16);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_15);
        if (this._BotonConfig != null)
        {
          this._BotonConfig.Click -= eventHandler;
          this._BotonConfig.MouseDown -= mouseEventHandler1;
          this._BotonConfig.MouseUp -= mouseEventHandler2;
        }
        this._BotonConfig = value;
        if (this._BotonConfig == null)
          return;
        this._BotonConfig.Click += eventHandler;
        this._BotonConfig.MouseDown += mouseEventHandler1;
        this._BotonConfig.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual PictureBox PictureBox2
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox2 = value;
      }
    }

    internal virtual Button BotonSkillMaker
    {
      [DebuggerNonUserCode] get
      {
        return this._BotonSkillMaker;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_4);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_26);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_25);
        if (this._BotonSkillMaker != null)
        {
          this._BotonSkillMaker.Click -= eventHandler;
          this._BotonSkillMaker.MouseDown -= mouseEventHandler1;
          this._BotonSkillMaker.MouseUp -= mouseEventHandler2;
        }
        this._BotonSkillMaker = value;
        if (this._BotonSkillMaker == null)
          return;
        this._BotonSkillMaker.Click += eventHandler;
        this._BotonSkillMaker.MouseDown += mouseEventHandler1;
        this._BotonSkillMaker.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual Button BotonItemMaker
    {
      [DebuggerNonUserCode] get
      {
        return this._BotonItemMaker;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_3);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_24);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_23);
        if (this._BotonItemMaker != null)
        {
          this._BotonItemMaker.Click -= eventHandler;
          this._BotonItemMaker.MouseDown -= mouseEventHandler1;
          this._BotonItemMaker.MouseUp -= mouseEventHandler2;
        }
        this._BotonItemMaker = value;
        if (this._BotonItemMaker == null)
          return;
        this._BotonItemMaker.Click += eventHandler;
        this._BotonItemMaker.MouseDown += mouseEventHandler1;
        this._BotonItemMaker.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual Button BotonGuildMaker
    {
      [DebuggerNonUserCode] get
      {
        return this._BotonGuildMaker;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_5);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_28);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_27);
        if (this._BotonGuildMaker != null)
        {
          this._BotonGuildMaker.Click -= eventHandler;
          this._BotonGuildMaker.MouseDown -= mouseEventHandler1;
          this._BotonGuildMaker.MouseUp -= mouseEventHandler2;
        }
        this._BotonGuildMaker = value;
        if (this._BotonGuildMaker == null)
          return;
        this._BotonGuildMaker.Click += eventHandler;
        this._BotonGuildMaker.MouseDown += mouseEventHandler1;
        this._BotonGuildMaker.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual Button BotonMoveMaker
    {
      [DebuggerNonUserCode] get
      {
        return this._BotonMoveMaker;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_6);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_30);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_29);
        if (this._BotonMoveMaker != null)
        {
          this._BotonMoveMaker.Click -= eventHandler;
          this._BotonMoveMaker.MouseDown -= mouseEventHandler1;
          this._BotonMoveMaker.MouseUp -= mouseEventHandler2;
        }
        this._BotonMoveMaker = value;
        if (this._BotonMoveMaker == null)
          return;
        this._BotonMoveMaker.Click += eventHandler;
        this._BotonMoveMaker.MouseDown += mouseEventHandler1;
        this._BotonMoveMaker.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual NotifyIcon SysTrayIcon
    {
      [DebuggerNonUserCode] get
      {
        return this.notifyIcon_0;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.SysTrayIcon_DoubleClick);
        if (this.notifyIcon_0 != null)
          this.notifyIcon_0.DoubleClick -= eventHandler;
        this.notifyIcon_0 = value;
        if (this.notifyIcon_0 == null)
          return;
        this.notifyIcon_0.DoubleClick += eventHandler;
      }
    }

    internal virtual Button BotonAccountMaker
    {
      [DebuggerNonUserCode] get
      {
        return this._BotonAccountMaker;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_2);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_22);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_21);
        if (this._BotonAccountMaker != null)
        {
          this._BotonAccountMaker.Click -= eventHandler;
          this._BotonAccountMaker.MouseDown -= mouseEventHandler1;
          this._BotonAccountMaker.MouseUp -= mouseEventHandler2;
        }
        this._BotonAccountMaker = value;
        if (this._BotonAccountMaker == null)
          return;
        this._BotonAccountMaker.Click += eventHandler;
        this._BotonAccountMaker.MouseDown += mouseEventHandler1;
        this._BotonAccountMaker.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual MenuItem MenuGuildMaker
    {
      [DebuggerNonUserCode] get
      {
        return this.menuItem_4;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MenuGuildMaker_Click);
        if (this.menuItem_4 != null)
          this.menuItem_4.Click -= eventHandler;
        this.menuItem_4 = value;
        if (this.menuItem_4 == null)
          return;
        this.menuItem_4.Click += eventHandler;
      }
    }

    internal virtual MenuItem MenuFinderMaker
    {
      [DebuggerNonUserCode] get
      {
        return this.menuItem_5;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MenuFinderMaker_Click);
        if (this.menuItem_5 != null)
          this.menuItem_5.Click -= eventHandler;
        this.menuItem_5 = value;
        if (this.menuItem_5 == null)
          return;
        this.menuItem_5.Click += eventHandler;
      }
    }

    internal virtual MenuItem MenuXxMaker4
    {
      [DebuggerNonUserCode] get
      {
        return this.menuItem_6;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this.menuItem_6 = value;
      }
    }

    internal virtual MenuItem MenuXxMaker5
    {
      [DebuggerNonUserCode] get
      {
        return this.menuItem_7;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this.menuItem_7 = value;
      }
    }

    internal virtual MenuItem MenuXxMaker6
    {
      [DebuggerNonUserCode] get
      {
        return this.menuItem_8;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this.menuItem_8 = value;
      }
    }

    internal virtual MenuItem MenuXxMaker7
    {
      [DebuggerNonUserCode] get
      {
        return this.menuItem_9;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this.menuItem_9 = value;
      }
    }

    internal virtual MenuItem MenuXxMaker2
    {
      [DebuggerNonUserCode] get
      {
        return this.menuItem_10;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this.menuItem_10 = value;
      }
    }

    internal virtual MenuItem MenuSQLMaker
    {
      [DebuggerNonUserCode] get
      {
        return this.menuItem_11;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MenuSQLMaker_Click);
        if (this.menuItem_11 != null)
          this.menuItem_11.Click -= eventHandler;
        this.menuItem_11 = value;
        if (this.menuItem_11 == null)
          return;
        this.menuItem_11.Click += eventHandler;
      }
    }

    internal virtual MenuItem MenuCerrar
    {
      [DebuggerNonUserCode] get
      {
        return this.menuItem_12;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MenuCerrar_Click);
        if (this.menuItem_12 != null)
          this.menuItem_12.Click -= eventHandler;
        this.menuItem_12 = value;
        if (this.menuItem_12 == null)
          return;
        this.menuItem_12.Click += eventHandler;
      }
    }

    internal virtual PictureBox PayPal1
    {
      [DebuggerNonUserCode] get
      {
        return this._PayPal1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.PayPal1_Click);
        if (this._PayPal1 != null)
          this._PayPal1.Click -= eventHandler;
        this._PayPal1 = value;
        if (this._PayPal1 == null)
          return;
        this._PayPal1.Click += eventHandler;
      }
    }

    internal virtual System.Windows.Forms.Timer UPDTimer
    {
      [DebuggerNonUserCode] get
      {
        return this.timer_1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.UPDTimer_Tick);
        if (this.timer_1 != null)
          this.timer_1.Tick -= eventHandler;
        this.timer_1 = value;
        if (this.timer_1 == null)
          return;
        this.timer_1.Tick += eventHandler;
      }
    }

    internal virtual PictureBox PayPal2
    {
      [DebuggerNonUserCode] get
      {
        return this._PayPal2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.PayPal2_Click);
        if (this._PayPal2 != null)
          this._PayPal2.Click -= eventHandler;
        this._PayPal2 = value;
        if (this._PayPal2 == null)
          return;
        this._PayPal2.Click += eventHandler;
      }
    }

    internal virtual Button BotonConectarSQL
    {
      [DebuggerNonUserCode] get
      {
        return this._BotonConectarSQL;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_1);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_36);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_35);
        if (this._BotonConectarSQL != null)
        {
          this._BotonConectarSQL.Click -= eventHandler;
          this._BotonConectarSQL.MouseDown -= mouseEventHandler1;
          this._BotonConectarSQL.MouseUp -= mouseEventHandler2;
        }
        this._BotonConectarSQL = value;
        if (this._BotonConectarSQL == null)
          return;
        this._BotonConectarSQL.Click += eventHandler;
        this._BotonConectarSQL.MouseDown += mouseEventHandler1;
        this._BotonConectarSQL.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual Button BotonCerrarLoging
    {
      [DebuggerNonUserCode] get
      {
        return this._BotonCerrarLoging;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_0);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_38);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_37);
        if (this._BotonCerrarLoging != null)
        {
          this._BotonCerrarLoging.Click -= eventHandler;
          this._BotonCerrarLoging.MouseDown -= mouseEventHandler1;
          this._BotonCerrarLoging.MouseUp -= mouseEventHandler2;
        }
        this._BotonCerrarLoging = value;
        if (this._BotonCerrarLoging == null)
          return;
        this._BotonCerrarLoging.Click += eventHandler;
        this._BotonCerrarLoging.MouseDown += mouseEventHandler1;
        this._BotonCerrarLoging.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual PictureBox LogingSQL
    {
      [DebuggerNonUserCode] get
      {
        return this._LogingSQL;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._LogingSQL = value;
      }
    }

    internal virtual Button BotonLogingSQL
    {
      [DebuggerNonUserCode] get
      {
        return this._BotonLogingSQL;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_10);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_40);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_39);
        if (this._BotonLogingSQL != null)
        {
          this._BotonLogingSQL.Click -= eventHandler;
          this._BotonLogingSQL.MouseDown -= mouseEventHandler1;
          this._BotonLogingSQL.MouseUp -= mouseEventHandler2;
        }
        this._BotonLogingSQL = value;
        if (this._BotonLogingSQL == null)
          return;
        this._BotonLogingSQL.Click += eventHandler;
        this._BotonLogingSQL.MouseDown += mouseEventHandler1;
        this._BotonLogingSQL.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual TextBox UserSQL
    {
      [DebuggerNonUserCode] get
      {
        return this._UserSQL;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._UserSQL = value;
      }
    }

    internal virtual TextBox PswSQL
    {
      [DebuggerNonUserCode] get
      {
        return this._PswSQL;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PswSQL = value;
      }
    }

    internal virtual MenuItem MenuSeparador1
    {
      [DebuggerNonUserCode] get
      {
        return this.menuItem_13;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this.menuItem_13 = value;
      }
    }

    internal virtual MenuItem MenuReload
    {
      [DebuggerNonUserCode] get
      {
        return this.menuItem_14;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MenuReload_Click);
        if (this.menuItem_14 != null)
          this.menuItem_14.Click -= eventHandler;
        this.menuItem_14 = value;
        if (this.menuItem_14 == null)
          return;
        this.menuItem_14.Click += eventHandler;
      }
    }

    internal virtual MenuItem MenuSeparador2
    {
      [DebuggerNonUserCode] get
      {
        return this.menuItem_15;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this.menuItem_15 = value;
      }
    }

    internal virtual System.Windows.Forms.Timer CHVersion
    {
      [DebuggerNonUserCode] get
      {
        return this.timer_2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CHVersion_Tick);
        if (this.timer_2 != null)
          this.timer_2.Tick -= eventHandler;
        this.timer_2 = value;
        if (this.timer_2 == null)
          return;
        this.timer_2.Tick += eventHandler;
      }
    }

    internal virtual Label ClientSuport
    {
      [DebuggerNonUserCode] get
      {
        return this._ClientSuport;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._ClientSuport = value;
      }
    }

    internal virtual Label LabelInfo
    {
      [DebuggerNonUserCode] get
      {
        return this._LabelInfo;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._LabelInfo = value;
      }
    }

    internal virtual ComboBox Cuentas
    {
      [DebuggerNonUserCode] get
      {
        return this._Cuentas;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Cuentas = value;
      }
    }

    internal virtual GroupBox CodigoOculto
    {
      [DebuggerNonUserCode] get
      {
        return this._CodigoOculto;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._CodigoOculto = value;
      }
    }

    internal virtual WebBrowser Navegador
    {
      [DebuggerNonUserCode] get
      {
        return this._Navegador;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Navegador = value;
      }
    }

    internal virtual CheckBox CKUPDT
    {
      [DebuggerNonUserCode] get
      {
        return this._CKUPDT;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._CKUPDT = value;
      }
    }

    internal virtual Button BotonReload
    {
      [DebuggerNonUserCode] get
      {
        return this._BotonReload;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_11);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_42);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_41);
        if (this._BotonReload != null)
        {
          this._BotonReload.Click -= eventHandler;
          this._BotonReload.MouseDown -= mouseEventHandler1;
          this._BotonReload.MouseUp -= mouseEventHandler2;
        }
        this._BotonReload = value;
        if (this._BotonReload == null)
          return;
        this._BotonReload.Click += eventHandler;
        this._BotonReload.MouseDown += mouseEventHandler1;
        this._BotonReload.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual ProgressBar CargaCuentasProgres
    {
      [DebuggerNonUserCode] get
      {
        return this._CargaCuentasProgres;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._CargaCuentasProgres = value;
      }
    }

    internal virtual System.Windows.Forms.Timer DeLoadAcc
    {
      [DebuggerNonUserCode] get
      {
        return this.timer_3;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.DeLoadAcc_Tick);
        if (this.timer_3 != null)
          this.timer_3.Tick -= eventHandler;
        this.timer_3 = value;
        if (this.timer_3 == null)
          return;
        this.timer_3.Tick += eventHandler;
      }
    }

    internal virtual Button BotonHelp
    {
      [DebuggerNonUserCode] get
      {
        return this._BotonHelp;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_44);
        EventHandler eventHandler = new EventHandler(this.method_12);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_43);
        if (this._BotonHelp != null)
        {
          this._BotonHelp.MouseDown -= mouseEventHandler1;
          this._BotonHelp.Click -= eventHandler;
          this._BotonHelp.MouseUp -= mouseEventHandler2;
        }
        this._BotonHelp = value;
        if (this._BotonHelp == null)
          return;
        this._BotonHelp.MouseDown += mouseEventHandler1;
        this._BotonHelp.Click += eventHandler;
        this._BotonHelp.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual MenuItem MenuHelpGuide
    {
      [DebuggerNonUserCode] get
      {
        return this.menuItem_16;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MenuHelpGuide_Click);
        if (this.menuItem_16 != null)
          this.menuItem_16.Click -= eventHandler;
        this.menuItem_16 = value;
        if (this.menuItem_16 == null)
          return;
        this.menuItem_16.Click += eventHandler;
      }
    }

    internal virtual Label ClientKOR
    {
      [DebuggerNonUserCode] get
      {
        return this._ClientKOR;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._ClientKOR = value;
      }
    }

    internal virtual Label ClientCHN
    {
      [DebuggerNonUserCode] get
      {
        return this._ClientCHN;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._ClientCHN = value;
      }
    }

    internal virtual Label ClientJPN
    {
      [DebuggerNonUserCode] get
      {
        return this._ClientJPN;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._ClientJPN = value;
      }
    }

    [DebuggerNonUserCode]
    public MuMaker()
    {
      this.Load += new EventHandler(this.MuMaker_Load);
      this.Closing += new CancelEventHandler(this.MuMaker_Closing);
      this.Move += new EventHandler(this.MuMaker_Move);
      this.LocationChanged += new EventHandler(this.MuMaker_LocationChanged);
      this.InitializeComponent();
    }

    [STAThread]
    public static void Main()
    {
      Application.Run((Form) Class2.smethod_3().method_8());
    }

    [DebuggerNonUserCode]
    protected override void Dispose(bool disposing)
    {
      if (disposing && this.icontainer_0 != null)
        this.icontainer_0.Dispose();
      base.Dispose(disposing);
    }

    [DebuggerStepThrough]
    private void InitializeComponent()
    {
      this.icontainer_0 = (IContainer) new System.ComponentModel.Container();
      ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof (MuMaker));
      this.TopOnOff = new CheckBox();
      this.BanderaID = new PictureBox();
      this.InicialesIdioma = new Label();
      this.Reloj = new System.Windows.Forms.Timer(this.icontainer_0);
      this.Label1 = new Label();
      this.Boton2 = new Button();
      this.Boton6 = new Button();
      this.Boton5 = new Button();
      this.Boton4 = new Button();
      this.BotonFinderMaker = new Button();
      this.UpDater = new Label();
      this.RealVersion = new Label();
      this.MMKNM = new Label();
      this.StatusMenu = new ContextMenu();
      this.MenuAccountMaker = new MenuItem();
      this.MenuItemMaker = new MenuItem();
      this.MenuSkillMaker = new MenuItem();
      this.MenuGuildMaker = new MenuItem();
      this.MenuXxMaker2 = new MenuItem();
      this.MenuMoveMaker = new MenuItem();
      this.MenuFinderMaker = new MenuItem();
      this.MenuXxMaker4 = new MenuItem();
      this.MenuXxMaker5 = new MenuItem();
      this.MenuXxMaker6 = new MenuItem();
      this.MenuXxMaker7 = new MenuItem();
      this.MenuSQLMaker = new MenuItem();
      this.MenuSeparador1 = new MenuItem();
      this.MenuReload = new MenuItem();
      this.MenuHelpGuide = new MenuItem();
      this.MenuSeparador2 = new MenuItem();
      this.MenuCerrar = new MenuItem();
      this.BotonSQLMaker = new Button();
      this.Boton7 = new Button();
      this.BUpDate = new Button();
      this.BotonCreditos = new LinkLabel();
      this.Minimizar = new Button();
      this.Cerrar = new Button();
      this.BotonConfig = new Button();
      this.PictureBox2 = new PictureBox();
      this.BotonSkillMaker = new Button();
      this.BotonItemMaker = new Button();
      this.BotonGuildMaker = new Button();
      this.BotonMoveMaker = new Button();
      this.SysTrayIcon = new NotifyIcon(this.icontainer_0);
      this.BotonAccountMaker = new Button();
      this.ToolTips = new ToolTip(this.icontainer_0);
      this.PayPal1 = new PictureBox();
      this.PayPal2 = new PictureBox();
      this.BotonReload = new Button();
      this.CargaCuentasProgres = new ProgressBar();
      this.ClientSuport = new Label();
      this.ClientKOR = new Label();
      this.ClientCHN = new Label();
      this.ClientJPN = new Label();
      this.UPDTimer = new System.Windows.Forms.Timer(this.icontainer_0);
      this.BotonConectarSQL = new Button();
      this.BotonCerrarLoging = new Button();
      this.LogingSQL = new PictureBox();
      this.BotonLogingSQL = new Button();
      this.UserSQL = new TextBox();
      this.PswSQL = new TextBox();
      this.CHVersion = new System.Windows.Forms.Timer(this.icontainer_0);
      this.LabelInfo = new Label();
      this.Cuentas = new ComboBox();
      this.CodigoOculto = new GroupBox();
      this.Navegador = new WebBrowser();
      this.CKUPDT = new CheckBox();
      this.DeLoadAcc = new System.Windows.Forms.Timer(this.icontainer_0);
      this.BotonHelp = new Button();
      ((ISupportInitialize) this.BanderaID).BeginInit();
      ((ISupportInitialize) this.PictureBox2).BeginInit();
      ((ISupportInitialize) this.PayPal1).BeginInit();
      ((ISupportInitialize) this.PayPal2).BeginInit();
      ((ISupportInitialize) this.LogingSQL).BeginInit();
      this.CodigoOculto.SuspendLayout();
      this.SuspendLayout();
      this.TopOnOff.AutoSize = true;
      this.TopOnOff.BackColor = Color.Transparent;
      this.TopOnOff.Cursor = Cursors.Hand;
      this.TopOnOff.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.TopOnOff.ForeColor = Color.Goldenrod;
      CheckBox topOnOff1 = this.TopOnOff;
      Point point1 = new Point(382, 28);
      Point point2 = point1;
      topOnOff1.Location = point2;
      this.TopOnOff.Name = "TopOnOff";
      CheckBox topOnOff2 = this.TopOnOff;
      Size size1 = new Size(15, 14);
      Size size2 = size1;
      topOnOff2.Size = size2;
      this.TopOnOff.TabIndex = 293;
      this.TopOnOff.TabStop = false;
      this.ToolTips.SetToolTip((Control) this.TopOnOff, "ALWAYS On TOP - On/Off");
      this.TopOnOff.UseVisualStyleBackColor = false;
      this.BanderaID.BackColor = Color.Transparent;
      this.BanderaID.ImeMode = ImeMode.NoControl;
      PictureBox banderaId1 = this.BanderaID;
      point1 = new Point(361, 4);
      Point point3 = point1;
      banderaId1.Location = point3;
      this.BanderaID.Name = "BanderaID";
      PictureBox banderaId2 = this.BanderaID;
      size1 = new Size(29, 19);
      Size size3 = size1;
      banderaId2.Size = size3;
      this.BanderaID.TabIndex = 290;
      this.BanderaID.TabStop = false;
      this.InicialesIdioma.BackColor = Color.Transparent;
      this.InicialesIdioma.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.InicialesIdioma.ForeColor = Color.Orange;
      Label inicialesIdioma1 = this.InicialesIdioma;
      point1 = new Point(393, 7);
      Point point4 = point1;
      inicialesIdioma1.Location = point4;
      this.InicialesIdioma.Name = "InicialesIdioma";
      Label inicialesIdioma2 = this.InicialesIdioma;
      size1 = new Size(28, 13);
      Size size4 = size1;
      inicialesIdioma2.Size = size4;
      this.InicialesIdioma.TabIndex = 291;
      this.Reloj.Interval = 30000;
      this.Label1.AutoSize = true;
      this.Label1.BackColor = Color.Transparent;
      this.Label1.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label1.ForeColor = Color.Orange;
      Label label1_1 = this.Label1;
      point1 = new Point(57, 29);
      Point point5 = point1;
      label1_1.Location = point5;
      this.Label1.Name = "Label1";
      Label label1_2 = this.Label1;
      size1 = new Size(14, 13);
      Size size5 = size1;
      label1_2.Size = size5;
      this.Label1.TabIndex = 297;
      this.Label1.Text = "v";
      this.Boton2.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Boton2.BackgroundImage = (Image) Class34.smethod_26();
      this.Boton2.BackgroundImageLayout = ImageLayout.Center;
      this.Boton2.Cursor = Cursors.Hand;
      this.Boton2.Enabled = false;
      this.Boton2.FlatAppearance.BorderSize = 0;
      this.Boton2.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.Boton2.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.Boton2.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.Boton2.FlatStyle = FlatStyle.Flat;
      this.Boton2.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Boton2.ForeColor = Color.Transparent;
      Button boton2_1 = this.Boton2;
      point1 = new Point(102, 160);
      Point point6 = point1;
      boton2_1.Location = point6;
      this.Boton2.Name = "Boton2";
      Button boton2_2 = this.Boton2;
      size1 = new Size(106, 24);
      Size size6 = size1;
      boton2_2.Size = size6;
      this.Boton2.TabIndex = 295;
      this.Boton2.TabStop = false;
      this.Boton2.UseVisualStyleBackColor = false;
      this.Boton6.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Boton6.BackgroundImage = (Image) Class34.smethod_26();
      this.Boton6.BackgroundImageLayout = ImageLayout.Center;
      this.Boton6.Cursor = Cursors.Hand;
      this.Boton6.Enabled = false;
      this.Boton6.FlatAppearance.BorderSize = 0;
      this.Boton6.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.Boton6.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.Boton6.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.Boton6.FlatStyle = FlatStyle.Flat;
      this.Boton6.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Boton6.ForeColor = Color.Transparent;
      Button boton6_1 = this.Boton6;
      point1 = new Point(215, 136);
      Point point7 = point1;
      boton6_1.Location = point7;
      this.Boton6.Name = "Boton6";
      Button boton6_2 = this.Boton6;
      size1 = new Size(106, 24);
      Size size7 = size1;
      boton6_2.Size = size7;
      this.Boton6.TabIndex = 306;
      this.Boton6.TabStop = false;
      this.Boton6.UseVisualStyleBackColor = false;
      this.Boton5.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Boton5.BackgroundImage = (Image) Class34.smethod_26();
      this.Boton5.BackgroundImageLayout = ImageLayout.Center;
      this.Boton5.Cursor = Cursors.Hand;
      this.Boton5.Enabled = false;
      this.Boton5.FlatAppearance.BorderSize = 0;
      this.Boton5.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.Boton5.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.Boton5.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.Boton5.FlatStyle = FlatStyle.Flat;
      this.Boton5.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Boton5.ForeColor = Color.Transparent;
      Button boton5_1 = this.Boton5;
      point1 = new Point(215, 112);
      Point point8 = point1;
      boton5_1.Location = point8;
      this.Boton5.Name = "Boton5";
      Button boton5_2 = this.Boton5;
      size1 = new Size(106, 24);
      Size size8 = size1;
      boton5_2.Size = size8;
      this.Boton5.TabIndex = 304;
      this.Boton5.TabStop = false;
      this.Boton5.UseVisualStyleBackColor = false;
      this.Boton4.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Boton4.BackgroundImage = (Image) Class34.smethod_26();
      this.Boton4.BackgroundImageLayout = ImageLayout.Center;
      this.Boton4.Cursor = Cursors.Hand;
      this.Boton4.Enabled = false;
      this.Boton4.FlatAppearance.BorderSize = 0;
      this.Boton4.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.Boton4.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.Boton4.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.Boton4.FlatStyle = FlatStyle.Flat;
      this.Boton4.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Boton4.ForeColor = Color.Transparent;
      Button boton4_1 = this.Boton4;
      point1 = new Point(214, 88);
      Point point9 = point1;
      boton4_1.Location = point9;
      this.Boton4.Name = "Boton4";
      Button boton4_2 = this.Boton4;
      size1 = new Size(106, 24);
      Size size9 = size1;
      boton4_2.Size = size9;
      this.Boton4.TabIndex = 302;
      this.Boton4.TabStop = false;
      this.Boton4.UseVisualStyleBackColor = false;
      this.BotonFinderMaker.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonFinderMaker.BackgroundImage = (Image) Class34.smethod_16();
      this.BotonFinderMaker.BackgroundImageLayout = ImageLayout.Center;
      this.BotonFinderMaker.Cursor = Cursors.Hand;
      this.BotonFinderMaker.Enabled = false;
      this.BotonFinderMaker.FlatAppearance.BorderSize = 0;
      this.BotonFinderMaker.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BotonFinderMaker.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BotonFinderMaker.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BotonFinderMaker.FlatStyle = FlatStyle.Flat;
      this.BotonFinderMaker.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BotonFinderMaker.ForeColor = Color.Transparent;
      Button botonFinderMaker1 = this.BotonFinderMaker;
      point1 = new Point(214, 64);
      Point point10 = point1;
      botonFinderMaker1.Location = point10;
      this.BotonFinderMaker.Name = "BotonFinderMaker";
      Button botonFinderMaker2 = this.BotonFinderMaker;
      size1 = new Size(106, 24);
      Size size10 = size1;
      botonFinderMaker2.Size = size10;
      this.BotonFinderMaker.TabIndex = 300;
      this.BotonFinderMaker.TabStop = false;
      this.BotonFinderMaker.UseVisualStyleBackColor = false;
      this.UpDater.AutoSize = true;
      this.UpDater.BackColor = Color.Transparent;
      this.UpDater.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.UpDater.ForeColor = Color.LightSeaGreen;
      Label upDater1 = this.UpDater;
      point1 = new Point(32, 168);
      Point point11 = point1;
      upDater1.Location = point11;
      this.UpDater.Name = "UpDater";
      Label upDater2 = this.UpDater;
      size1 = new Size(50, 13);
      Size size11 = size1;
      upDater2.Size = size11;
      this.UpDater.TabIndex = 299;
      this.UpDater.Text = "UpDate";
      this.UpDater.Visible = false;
      this.RealVersion.AutoSize = true;
      this.RealVersion.BackColor = Color.Transparent;
      this.RealVersion.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.RealVersion.ForeColor = Color.Orange;
      Label realVersion1 = this.RealVersion;
      point1 = new Point(72, 29);
      Point point12 = point1;
      realVersion1.Location = point12;
      this.RealVersion.Name = "RealVersion";
      Label realVersion2 = this.RealVersion;
      size1 = new Size(32, 13);
      Size size12 = size1;
      realVersion2.Size = size12;
      this.RealVersion.TabIndex = 313;
      this.RealVersion.Text = "0.00";
      this.MMKNM.BackColor = Color.Transparent;
      this.MMKNM.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.MMKNM.ForeColor = Color.Orange;
      Label mmknm1 = this.MMKNM;
      point1 = new Point(170, 7);
      Point point13 = point1;
      mmknm1.Location = point13;
      this.MMKNM.Name = "MMKNM";
      Label mmknm2 = this.MMKNM;
      size1 = new Size(138, 14);
      Size size13 = size1;
      mmknm2.Size = size13;
      this.MMKNM.TabIndex = 312;
      this.MMKNM.TextAlign = ContentAlignment.MiddleCenter;
      this.StatusMenu.MenuItems.AddRange(new MenuItem[17]
      {
        this.MenuAccountMaker,
        this.MenuItemMaker,
        this.MenuSkillMaker,
        this.MenuGuildMaker,
        this.MenuXxMaker2,
        this.MenuMoveMaker,
        this.MenuFinderMaker,
        this.MenuXxMaker4,
        this.MenuXxMaker5,
        this.MenuXxMaker6,
        this.MenuXxMaker7,
        this.MenuSQLMaker,
        this.MenuSeparador1,
        this.MenuReload,
        this.MenuHelpGuide,
        this.MenuSeparador2,
        this.MenuCerrar
      });
      this.MenuAccountMaker.Index = 0;
      this.MenuAccountMaker.Text = "AccountMaker";
      this.MenuItemMaker.Index = 1;
      this.MenuItemMaker.Text = "ItemMaker";
      this.MenuSkillMaker.Index = 2;
      this.MenuSkillMaker.Text = "SkillMaker";
      this.MenuGuildMaker.Index = 3;
      this.MenuGuildMaker.Text = "GuildMaker";
      this.MenuXxMaker2.Enabled = false;
      this.MenuXxMaker2.Index = 4;
      this.MenuXxMaker2.Text = ">RESERVED<";
      this.MenuXxMaker2.Visible = false;
      this.MenuMoveMaker.Index = 5;
      this.MenuMoveMaker.Text = "MoveMaker";
      this.MenuFinderMaker.Index = 6;
      this.MenuFinderMaker.Text = "FinderMaker";
      this.MenuXxMaker4.Enabled = false;
      this.MenuXxMaker4.Index = 7;
      this.MenuXxMaker4.Text = ">RESERVED<";
      this.MenuXxMaker4.Visible = false;
      this.MenuXxMaker5.Enabled = false;
      this.MenuXxMaker5.Index = 8;
      this.MenuXxMaker5.Text = ">RESERVED<";
      this.MenuXxMaker5.Visible = false;
      this.MenuXxMaker6.Enabled = false;
      this.MenuXxMaker6.Index = 9;
      this.MenuXxMaker6.Text = ">RESERVED<";
      this.MenuXxMaker6.Visible = false;
      this.MenuXxMaker7.Enabled = false;
      this.MenuXxMaker7.Index = 10;
      this.MenuXxMaker7.Text = ">RESERVED<";
      this.MenuXxMaker7.Visible = false;
      this.MenuSQLMaker.Index = 11;
      this.MenuSQLMaker.Text = "SQLMaker";
      this.MenuSeparador1.Index = 12;
      this.MenuSeparador1.Text = "-";
      this.MenuSeparador1.Visible = false;
      this.MenuReload.Index = 13;
      this.MenuReload.Text = "Reload Acc.";
      this.MenuReload.Visible = false;
      this.MenuHelpGuide.Index = 14;
      this.MenuHelpGuide.Text = "Help/Guide";
      this.MenuSeparador2.Index = 15;
      this.MenuSeparador2.Text = "-";
      this.MenuCerrar.Index = 16;
      this.MenuCerrar.Text = "Close";
      this.BotonSQLMaker.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonSQLMaker.BackgroundImage = (Image) Class34.smethod_31();
      this.BotonSQLMaker.BackgroundImageLayout = ImageLayout.Center;
      this.BotonSQLMaker.Cursor = Cursors.Hand;
      this.BotonSQLMaker.FlatAppearance.BorderSize = 0;
      this.BotonSQLMaker.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BotonSQLMaker.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BotonSQLMaker.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BotonSQLMaker.FlatStyle = FlatStyle.Flat;
      this.BotonSQLMaker.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BotonSQLMaker.ForeColor = Color.Transparent;
      Button botonSqlMaker1 = this.BotonSQLMaker;
      point1 = new Point(215, 184);
      Point point14 = point1;
      botonSqlMaker1.Location = point14;
      this.BotonSQLMaker.Name = "BotonSQLMaker";
      Button botonSqlMaker2 = this.BotonSQLMaker;
      size1 = new Size(106, 24);
      Size size14 = size1;
      botonSqlMaker2.Size = size14;
      this.BotonSQLMaker.TabIndex = 310;
      this.BotonSQLMaker.TabStop = false;
      this.BotonSQLMaker.UseVisualStyleBackColor = false;
      this.Boton7.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Boton7.BackgroundImage = (Image) Class34.smethod_26();
      this.Boton7.BackgroundImageLayout = ImageLayout.Center;
      this.Boton7.Cursor = Cursors.Hand;
      this.Boton7.Enabled = false;
      this.Boton7.FlatAppearance.BorderSize = 0;
      this.Boton7.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.Boton7.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.Boton7.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.Boton7.FlatStyle = FlatStyle.Flat;
      this.Boton7.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Boton7.ForeColor = Color.Transparent;
      Button boton7_1 = this.Boton7;
      point1 = new Point(215, 160);
      Point point15 = point1;
      boton7_1.Location = point15;
      this.Boton7.Name = "Boton7";
      Button boton7_2 = this.Boton7;
      size1 = new Size(106, 24);
      Size size15 = size1;
      boton7_2.Size = size15;
      this.Boton7.TabIndex = 308;
      this.Boton7.TabStop = false;
      this.Boton7.UseVisualStyleBackColor = false;
      this.BUpDate.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BUpDate.BackgroundImage = (Image) Class34.smethod_109();
      this.BUpDate.BackgroundImageLayout = ImageLayout.Center;
      this.BUpDate.Cursor = Cursors.Hand;
      this.BUpDate.FlatAppearance.BorderSize = 0;
      this.BUpDate.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BUpDate.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BUpDate.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BUpDate.FlatStyle = FlatStyle.Flat;
      this.BUpDate.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BUpDate.ForeColor = Color.Transparent;
      Button bupDate1 = this.BUpDate;
      point1 = new Point(26, 105);
      Point point16 = point1;
      bupDate1.Location = point16;
      this.BUpDate.Name = "BUpDate";
      Button bupDate2 = this.BUpDate;
      size1 = new Size(61, 64);
      Size size16 = size1;
      bupDate2.Size = size16;
      this.BUpDate.TabIndex = 298;
      this.BUpDate.TabStop = false;
      this.BUpDate.TextAlign = ContentAlignment.BottomCenter;
      this.BUpDate.UseVisualStyleBackColor = false;
      this.BotonCreditos.ActiveLinkColor = Color.DarkGoldenrod;
      this.BotonCreditos.BackColor = Color.Transparent;
      this.BotonCreditos.Cursor = Cursors.Hand;
      this.BotonCreditos.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BotonCreditos.ForeColor = Color.Orange;
      this.BotonCreditos.LinkBehavior = LinkBehavior.NeverUnderline;
      this.BotonCreditos.LinkColor = Color.Orange;
      LinkLabel botonCreditos1 = this.BotonCreditos;
      point1 = new Point(161, 215);
      Point point17 = point1;
      botonCreditos1.Location = point17;
      this.BotonCreditos.Name = "BotonCreditos";
      LinkLabel botonCreditos2 = this.BotonCreditos;
      size1 = new Size(114, 16);
      Size size17 = size1;
      botonCreditos2.Size = size17;
      this.BotonCreditos.TabIndex = 282;
      this.BotonCreditos.TabStop = true;
      this.BotonCreditos.Text = "Credits - Contact";
      this.BotonCreditos.TextAlign = ContentAlignment.MiddleCenter;
      this.BotonCreditos.VisitedLinkColor = Color.Goldenrod;
      this.Minimizar.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Minimizar.BackgroundImage = (Image) Class34.smethod_86();
      this.Minimizar.BackgroundImageLayout = ImageLayout.Center;
      this.Minimizar.Cursor = Cursors.Hand;
      this.Minimizar.DialogResult = DialogResult.Cancel;
      this.Minimizar.FlatAppearance.BorderSize = 0;
      this.Minimizar.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.Minimizar.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.Minimizar.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.Minimizar.FlatStyle = FlatStyle.Flat;
      this.Minimizar.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Minimizar.ForeColor = Color.Transparent;
      Button minimizar1 = this.Minimizar;
      point1 = new Point(26, 32);
      Point point18 = point1;
      minimizar1.Location = point18;
      this.Minimizar.Name = "Minimizar";
      Button minimizar2 = this.Minimizar;
      size1 = new Size(13, 13);
      Size size18 = size1;
      minimizar2.Size = size18;
      this.Minimizar.TabIndex = 280;
      this.Minimizar.TabStop = false;
      this.Minimizar.UseVisualStyleBackColor = false;
      this.Cerrar.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) Class34.smethod_44();
      this.Cerrar.BackgroundImageLayout = ImageLayout.Center;
      this.Cerrar.Cursor = Cursors.Hand;
      this.Cerrar.DialogResult = DialogResult.Cancel;
      this.Cerrar.FlatAppearance.BorderSize = 0;
      this.Cerrar.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.Cerrar.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.Cerrar.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.Cerrar.FlatStyle = FlatStyle.Flat;
      this.Cerrar.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Cerrar.ForeColor = Color.Transparent;
      Button cerrar1 = this.Cerrar;
      point1 = new Point(429, 189);
      Point point19 = point1;
      cerrar1.Location = point19;
      this.Cerrar.Name = "Cerrar";
      Button cerrar2 = this.Cerrar;
      size1 = new Size(36, 36);
      Size size19 = size1;
      cerrar2.Size = size19;
      this.Cerrar.TabIndex = 281;
      this.Cerrar.TabStop = false;
      this.Cerrar.UseVisualStyleBackColor = false;
      this.BotonConfig.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonConfig.BackgroundImage = (Image) Class34.smethod_14();
      this.BotonConfig.BackgroundImageLayout = ImageLayout.Center;
      this.BotonConfig.Cursor = Cursors.Hand;
      this.BotonConfig.FlatAppearance.BorderSize = 0;
      this.BotonConfig.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BotonConfig.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BotonConfig.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BotonConfig.FlatStyle = FlatStyle.Flat;
      this.BotonConfig.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BotonConfig.ForeColor = Color.Transparent;
      Button botonConfig1 = this.BotonConfig;
      point1 = new Point(434, 118);
      Point point20 = point1;
      botonConfig1.Location = point20;
      this.BotonConfig.Name = "BotonConfig";
      Button botonConfig2 = this.BotonConfig;
      size1 = new Size(34, 27);
      Size size20 = size1;
      botonConfig2.Size = size20;
      this.BotonConfig.TabIndex = 279;
      this.BotonConfig.TabStop = false;
      this.ToolTips.SetToolTip((Control) this.BotonConfig, "ConfigMaker");
      this.BotonConfig.UseVisualStyleBackColor = false;
      this.PictureBox2.BackColor = Color.Transparent;
      this.PictureBox2.Enabled = false;
      // ISSUE: reference to a compiler-generated method
      this.PictureBox2.Image = (Image) Class34.smethod_110();
      PictureBox pictureBox2_1 = this.PictureBox2;
      point1 = new Point(342, 94);
      Point point21 = point1;
      pictureBox2_1.Location = point21;
      this.PictureBox2.Name = "PictureBox2";
      PictureBox pictureBox2_2 = this.PictureBox2;
      size1 = new Size(78, 137);
      Size size21 = size1;
      pictureBox2_2.Size = size21;
      this.PictureBox2.TabIndex = 283;
      this.PictureBox2.TabStop = false;
      this.BotonSkillMaker.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonSkillMaker.BackgroundImage = (Image) Class34.smethod_29();
      this.BotonSkillMaker.BackgroundImageLayout = ImageLayout.Center;
      this.BotonSkillMaker.Cursor = Cursors.Hand;
      this.BotonSkillMaker.FlatAppearance.BorderSize = 0;
      this.BotonSkillMaker.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BotonSkillMaker.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BotonSkillMaker.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BotonSkillMaker.FlatStyle = FlatStyle.Flat;
      this.BotonSkillMaker.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BotonSkillMaker.ForeColor = Color.Transparent;
      Button botonSkillMaker1 = this.BotonSkillMaker;
      point1 = new Point(102, 112);
      Point point22 = point1;
      botonSkillMaker1.Location = point22;
      this.BotonSkillMaker.Name = "BotonSkillMaker";
      Button botonSkillMaker2 = this.BotonSkillMaker;
      size1 = new Size(106, 24);
      Size size22 = size1;
      botonSkillMaker2.Size = size22;
      this.BotonSkillMaker.TabIndex = 278;
      this.BotonSkillMaker.TabStop = false;
      this.BotonSkillMaker.UseVisualStyleBackColor = false;
      this.BotonItemMaker.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonItemMaker.BackgroundImage = (Image) Class34.smethod_20();
      this.BotonItemMaker.BackgroundImageLayout = ImageLayout.Center;
      this.BotonItemMaker.Cursor = Cursors.Hand;
      this.BotonItemMaker.FlatAppearance.BorderSize = 0;
      this.BotonItemMaker.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BotonItemMaker.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BotonItemMaker.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BotonItemMaker.FlatStyle = FlatStyle.Flat;
      this.BotonItemMaker.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BotonItemMaker.ForeColor = Color.Transparent;
      Button botonItemMaker1 = this.BotonItemMaker;
      point1 = new Point(102, 88);
      Point point23 = point1;
      botonItemMaker1.Location = point23;
      this.BotonItemMaker.Name = "BotonItemMaker";
      Button botonItemMaker2 = this.BotonItemMaker;
      size1 = new Size(106, 24);
      Size size23 = size1;
      botonItemMaker2.Size = size23;
      this.BotonItemMaker.TabIndex = 277;
      this.BotonItemMaker.TabStop = false;
      this.BotonItemMaker.UseVisualStyleBackColor = false;
      this.BotonGuildMaker.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonGuildMaker.BackgroundImage = (Image) Class34.smethod_18();
      this.BotonGuildMaker.BackgroundImageLayout = ImageLayout.Center;
      this.BotonGuildMaker.Cursor = Cursors.Hand;
      this.BotonGuildMaker.FlatAppearance.BorderSize = 0;
      this.BotonGuildMaker.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BotonGuildMaker.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BotonGuildMaker.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BotonGuildMaker.FlatStyle = FlatStyle.Flat;
      this.BotonGuildMaker.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BotonGuildMaker.ForeColor = Color.Transparent;
      Button botonGuildMaker1 = this.BotonGuildMaker;
      point1 = new Point(102, 136);
      Point point24 = point1;
      botonGuildMaker1.Location = point24;
      this.BotonGuildMaker.Name = "BotonGuildMaker";
      Button botonGuildMaker2 = this.BotonGuildMaker;
      size1 = new Size(106, 24);
      Size size24 = size1;
      botonGuildMaker2.Size = size24;
      this.BotonGuildMaker.TabIndex = 276;
      this.BotonGuildMaker.TabStop = false;
      this.BotonGuildMaker.UseVisualStyleBackColor = false;
      this.BotonMoveMaker.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonMoveMaker.BackgroundImage = (Image) Class34.smethod_24();
      this.BotonMoveMaker.BackgroundImageLayout = ImageLayout.Center;
      this.BotonMoveMaker.Cursor = Cursors.Hand;
      this.BotonMoveMaker.FlatAppearance.BorderSize = 0;
      this.BotonMoveMaker.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BotonMoveMaker.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BotonMoveMaker.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BotonMoveMaker.FlatStyle = FlatStyle.Flat;
      this.BotonMoveMaker.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BotonMoveMaker.ForeColor = Color.Transparent;
      Button botonMoveMaker1 = this.BotonMoveMaker;
      point1 = new Point(102, 184);
      Point point25 = point1;
      botonMoveMaker1.Location = point25;
      this.BotonMoveMaker.Name = "BotonMoveMaker";
      Button botonMoveMaker2 = this.BotonMoveMaker;
      size1 = new Size(106, 24);
      Size size25 = size1;
      botonMoveMaker2.Size = size25;
      this.BotonMoveMaker.TabIndex = 275;
      this.BotonMoveMaker.TabStop = false;
      this.BotonMoveMaker.UseVisualStyleBackColor = false;
      this.SysTrayIcon.ContextMenu = this.StatusMenu;
      this.SysTrayIcon.Icon = (Icon) componentResourceManager.GetObject("SysTrayIcon.Icon");
      this.SysTrayIcon.Text = "MuMaker";
      this.SysTrayIcon.Visible = true;
      this.BotonAccountMaker.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonAccountMaker.BackgroundImage = (Image) Class34.smethod_10();
      this.BotonAccountMaker.BackgroundImageLayout = ImageLayout.Center;
      this.BotonAccountMaker.Cursor = Cursors.Hand;
      this.BotonAccountMaker.FlatAppearance.BorderSize = 0;
      this.BotonAccountMaker.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BotonAccountMaker.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BotonAccountMaker.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BotonAccountMaker.FlatStyle = FlatStyle.Flat;
      this.BotonAccountMaker.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BotonAccountMaker.ForeColor = Color.Transparent;
      Button botonAccountMaker1 = this.BotonAccountMaker;
      point1 = new Point(102, 64);
      Point point26 = point1;
      botonAccountMaker1.Location = point26;
      this.BotonAccountMaker.Name = "BotonAccountMaker";
      Button botonAccountMaker2 = this.BotonAccountMaker;
      size1 = new Size(106, 24);
      Size size26 = size1;
      botonAccountMaker2.Size = size26;
      this.BotonAccountMaker.TabIndex = 274;
      this.BotonAccountMaker.TabStop = false;
      this.BotonAccountMaker.UseVisualStyleBackColor = false;
      this.PayPal1.BackgroundImageLayout = ImageLayout.Center;
      this.PayPal1.Cursor = Cursors.Hand;
      // ISSUE: reference to a compiler-generated method
      this.PayPal1.Image = (Image) Class34.smethod_94();
      PictureBox payPal1_1 = this.PayPal1;
      point1 = new Point(117, 26);
      Point point27 = point1;
      payPal1_1.Location = point27;
      this.PayPal1.Name = "PayPal1";
      PictureBox payPal1_2 = this.PayPal1;
      size1 = new Size(62, 21);
      Size size27 = size1;
      payPal1_2.Size = size27;
      this.PayPal1.TabIndex = 315;
      this.PayPal1.TabStop = false;
      this.ToolTips.SetToolTip((Control) this.PayPal1, "Donate To Project");
      this.PayPal2.BackgroundImageLayout = ImageLayout.Center;
      this.PayPal2.Cursor = Cursors.Hand;
      // ISSUE: reference to a compiler-generated method
      this.PayPal2.Image = (Image) Class34.smethod_94();
      PictureBox payPal2_1 = this.PayPal2;
      point1 = new Point(300, 26);
      Point point28 = point1;
      payPal2_1.Location = point28;
      this.PayPal2.Name = "PayPal2";
      PictureBox payPal2_2 = this.PayPal2;
      size1 = new Size(62, 21);
      Size size28 = size1;
      payPal2_2.Size = size28;
      this.PayPal2.TabIndex = 318;
      this.PayPal2.TabStop = false;
      this.ToolTips.SetToolTip((Control) this.PayPal2, "Donate To Project");
      this.BotonReload.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonReload.BackgroundImage = (Image) Class34.smethod_100();
      this.BotonReload.BackgroundImageLayout = ImageLayout.Center;
      this.BotonReload.Cursor = Cursors.Hand;
      this.BotonReload.FlatAppearance.BorderSize = 0;
      this.BotonReload.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BotonReload.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BotonReload.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BotonReload.FlatStyle = FlatStyle.Flat;
      this.BotonReload.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BotonReload.ForeColor = Color.Transparent;
      Button botonReload1 = this.BotonReload;
      point1 = new Point(427, 145);
      Point point29 = point1;
      botonReload1.Location = point29;
      this.BotonReload.Name = "BotonReload";
      Button botonReload2 = this.BotonReload;
      size1 = new Size(40, 31);
      Size size29 = size1;
      botonReload2.Size = size29;
      this.BotonReload.TabIndex = 484;
      this.BotonReload.TabStop = false;
      this.ToolTips.SetToolTip((Control) this.BotonReload, "Reload All Acounts");
      this.BotonReload.UseVisualStyleBackColor = false;
      this.BotonReload.Visible = false;
      this.CargaCuentasProgres.ForeColor = Color.DarkOrange;
      ProgressBar cargaCuentasProgres1 = this.CargaCuentasProgres;
      point1 = new Point(90, 117);
      Point point30 = point1;
      cargaCuentasProgres1.Location = point30;
      this.CargaCuentasProgres.MarqueeAnimationSpeed = 1;
      this.CargaCuentasProgres.Maximum = 1000;
      this.CargaCuentasProgres.Name = "CargaCuentasProgres";
      ProgressBar cargaCuentasProgres2 = this.CargaCuentasProgres;
      size1 = new Size(247, 36);
      Size size30 = size1;
      cargaCuentasProgres2.Size = size30;
      this.CargaCuentasProgres.Step = 1;
      this.CargaCuentasProgres.Style = ProgressBarStyle.Continuous;
      this.CargaCuentasProgres.TabIndex = 485;
      this.ToolTips.SetToolTip((Control) this.CargaCuentasProgres, "!! ReLoading Accounts !!");
      this.CargaCuentasProgres.Visible = false;
      this.ClientSuport.BackColor = Color.Transparent;
      this.ClientSuport.Font = new Font("Microsoft Sans Serif", 6.75f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.ClientSuport.ForeColor = Color.Orange;
      Label clientSuport1 = this.ClientSuport;
      point1 = new Point(328, 64);
      Point point31 = point1;
      clientSuport1.Location = point31;
      Label clientSuport2 = this.ClientSuport;
      Padding padding1 = new Padding(0);
      Padding padding2 = padding1;
      clientSuport2.Margin = padding2;
      this.ClientSuport.Name = "ClientSuport";
      Label clientSuport3 = this.ClientSuport;
      size1 = new Size(122, 12);
      Size size31 = size1;
      clientSuport3.Size = size31;
      this.ClientSuport.TabIndex = 327;
      this.ClientSuport.Text = "KOR        CHN       JPN\r\n";
      this.ClientSuport.TextAlign = ContentAlignment.MiddleCenter;
      this.ToolTips.SetToolTip((Control) this.ClientSuport, "Mu Clients Suported");
      this.ClientKOR.BackColor = Color.Transparent;
      this.ClientKOR.Font = new Font("Microsoft Sans Serif", 6.75f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.ClientKOR.ForeColor = Color.Orange;
      Label clientKor1 = this.ClientKOR;
      point1 = new Point(331, 76);
      Point point32 = point1;
      clientKor1.Location = point32;
      Label clientKor2 = this.ClientKOR;
      padding1 = new Padding(0);
      Padding padding3 = padding1;
      clientKor2.Margin = padding3;
      this.ClientKOR.Name = "ClientKOR";
      Label clientKor3 = this.ClientKOR;
      size1 = new Size(40, 12);
      Size size32 = size1;
      clientKor3.Size = size32;
      this.ClientKOR.TabIndex = 486;
      this.ClientKOR.Text = "X.XXX";
      this.ClientKOR.TextAlign = ContentAlignment.MiddleCenter;
      this.ToolTips.SetToolTip((Control) this.ClientKOR, "Mu Clients Suported");
      this.ClientCHN.BackColor = Color.Transparent;
      this.ClientCHN.Font = new Font("Microsoft Sans Serif", 6.75f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.ClientCHN.ForeColor = Color.Orange;
      Label clientChn1 = this.ClientCHN;
      point1 = new Point(369, 76);
      Point point33 = point1;
      clientChn1.Location = point33;
      Label clientChn2 = this.ClientCHN;
      padding1 = new Padding(0);
      Padding padding4 = padding1;
      clientChn2.Margin = padding4;
      this.ClientCHN.Name = "ClientCHN";
      Label clientChn3 = this.ClientCHN;
      size1 = new Size(40, 12);
      Size size33 = size1;
      clientChn3.Size = size33;
      this.ClientCHN.TabIndex = 487;
      this.ClientCHN.Text = "X.XXX";
      this.ClientCHN.TextAlign = ContentAlignment.MiddleCenter;
      this.ToolTips.SetToolTip((Control) this.ClientCHN, "Mu Clients Suported");
      this.ClientJPN.BackColor = Color.Transparent;
      this.ClientJPN.Font = new Font("Microsoft Sans Serif", 6.75f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.ClientJPN.ForeColor = Color.Orange;
      Label clientJpn1 = this.ClientJPN;
      point1 = new Point(407, 76);
      Point point34 = point1;
      clientJpn1.Location = point34;
      Label clientJpn2 = this.ClientJPN;
      padding1 = new Padding(0);
      Padding padding5 = padding1;
      clientJpn2.Margin = padding5;
      this.ClientJPN.Name = "ClientJPN";
      Label clientJpn3 = this.ClientJPN;
      size1 = new Size(40, 12);
      Size size34 = size1;
      clientJpn3.Size = size34;
      this.ClientJPN.TabIndex = 488;
      this.ClientJPN.Text = "X.XXX";
      this.ClientJPN.TextAlign = ContentAlignment.MiddleCenter;
      this.ToolTips.SetToolTip((Control) this.ClientJPN, "Mu Clients Suported");
      this.UPDTimer.Interval = 1000;
      this.BotonConectarSQL.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonConectarSQL.BackgroundImage = (Image) Class34.smethod_48();
      this.BotonConectarSQL.BackgroundImageLayout = ImageLayout.Center;
      this.BotonConectarSQL.Cursor = Cursors.Hand;
      this.BotonConectarSQL.FlatAppearance.BorderSize = 0;
      this.BotonConectarSQL.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BotonConectarSQL.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BotonConectarSQL.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BotonConectarSQL.FlatStyle = FlatStyle.Flat;
      this.BotonConectarSQL.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BotonConectarSQL.ForeColor = Color.Transparent;
      Button botonConectarSql1 = this.BotonConectarSQL;
      point1 = new Point(188, 169);
      Point point35 = point1;
      botonConectarSql1.Location = point35;
      this.BotonConectarSQL.Name = "BotonConectarSQL";
      Button botonConectarSql2 = this.BotonConectarSQL;
      size1 = new Size(52, 28);
      Size size35 = size1;
      botonConectarSql2.Size = size35;
      this.BotonConectarSQL.TabIndex = 321;
      this.BotonConectarSQL.TabStop = false;
      this.BotonConectarSQL.UseVisualStyleBackColor = false;
      this.BotonConectarSQL.Visible = false;
      this.BotonCerrarLoging.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonCerrarLoging.BackgroundImage = (Image) Class34.smethod_39();
      this.BotonCerrarLoging.BackgroundImageLayout = ImageLayout.Center;
      this.BotonCerrarLoging.Cursor = Cursors.Hand;
      this.BotonCerrarLoging.DialogResult = DialogResult.Cancel;
      this.BotonCerrarLoging.FlatAppearance.BorderSize = 0;
      this.BotonCerrarLoging.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BotonCerrarLoging.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BotonCerrarLoging.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BotonCerrarLoging.FlatStyle = FlatStyle.Flat;
      this.BotonCerrarLoging.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BotonCerrarLoging.ForeColor = Color.Transparent;
      Button botonCerrarLoging1 = this.BotonCerrarLoging;
      point1 = new Point(287, 78);
      Point point36 = point1;
      botonCerrarLoging1.Location = point36;
      this.BotonCerrarLoging.Name = "BotonCerrarLoging";
      Button botonCerrarLoging2 = this.BotonCerrarLoging;
      size1 = new Size(13, 13);
      Size size36 = size1;
      botonCerrarLoging2.Size = size36;
      this.BotonCerrarLoging.TabIndex = 320;
      this.BotonCerrarLoging.TabStop = false;
      this.BotonCerrarLoging.UseVisualStyleBackColor = false;
      this.BotonCerrarLoging.Visible = false;
      // ISSUE: reference to a compiler-generated method
      this.LogingSQL.BackgroundImage = (Image) Class34.smethod_81();
      PictureBox logingSql1 = this.LogingSQL;
      point1 = new Point(120, 71);
      Point point37 = point1;
      logingSql1.Location = point37;
      this.LogingSQL.Name = "LogingSQL";
      PictureBox logingSql2 = this.LogingSQL;
      size1 = new Size(188, 128);
      Size size37 = size1;
      logingSql2.Size = size37;
      this.LogingSQL.TabIndex = 319;
      this.LogingSQL.TabStop = false;
      this.LogingSQL.Visible = false;
      this.BotonLogingSQL.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonLogingSQL.BackgroundImage = (Image) Class34.smethod_48();
      this.BotonLogingSQL.BackgroundImageLayout = ImageLayout.Center;
      this.BotonLogingSQL.Cursor = Cursors.Hand;
      this.BotonLogingSQL.FlatAppearance.BorderSize = 0;
      this.BotonLogingSQL.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BotonLogingSQL.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BotonLogingSQL.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BotonLogingSQL.FlatStyle = FlatStyle.Flat;
      this.BotonLogingSQL.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BotonLogingSQL.ForeColor = Color.Transparent;
      Button botonLogingSql1 = this.BotonLogingSQL;
      point1 = new Point(213, 106);
      Point point38 = point1;
      botonLogingSql1.Location = point38;
      this.BotonLogingSQL.Name = "BotonLogingSQL";
      Button botonLogingSql2 = this.BotonLogingSQL;
      size1 = new Size(52, 28);
      Size size38 = size1;
      botonLogingSql2.Size = size38;
      this.BotonLogingSQL.TabIndex = 322;
      this.BotonLogingSQL.TabStop = false;
      this.BotonLogingSQL.UseVisualStyleBackColor = false;
      this.BotonLogingSQL.Visible = false;
      TextBox userSql1 = this.UserSQL;
      point1 = new Point(163, 110);
      Point point39 = point1;
      userSql1.Location = point39;
      this.UserSQL.Name = "UserSQL";
      TextBox userSql2 = this.UserSQL;
      size1 = new Size(132, 20);
      Size size39 = size1;
      userSql2.Size = size39;
      this.UserSQL.TabIndex = 323;
      this.UserSQL.Visible = false;
      TextBox pswSql1 = this.PswSQL;
      point1 = new Point(163, 144);
      Point point40 = point1;
      pswSql1.Location = point40;
      this.PswSQL.Name = "PswSQL";
      this.PswSQL.PasswordChar = '*';
      TextBox pswSql2 = this.PswSQL;
      size1 = new Size(132, 20);
      Size size40 = size1;
      pswSql2.Size = size40;
      this.PswSQL.TabIndex = 324;
      this.PswSQL.Visible = false;
      this.CHVersion.Enabled = true;
      this.CHVersion.Interval = 3600000;
      this.LabelInfo.AutoSize = true;
      this.LabelInfo.BackColor = Color.Transparent;
      this.LabelInfo.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.LabelInfo.ForeColor = Color.Orange;
      Label labelInfo1 = this.LabelInfo;
      point1 = new Point(25, 95);
      Point point41 = point1;
      labelInfo1.Location = point41;
      this.LabelInfo.Name = "LabelInfo";
      Label labelInfo2 = this.LabelInfo;
      size1 = new Size(62, 13);
      Size size41 = size1;
      labelInfo2.Size = size41;
      this.LabelInfo.TabIndex = 328;
      this.LabelInfo.Text = "InfoNewS";
      this.Cuentas.Cursor = Cursors.Hand;
      this.Cuentas.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Cuentas.ItemHeight = 13;
      ComboBox cuentas1 = this.Cuentas;
      point1 = new Point(6, 15);
      Point point42 = point1;
      cuentas1.Location = point42;
      this.Cuentas.Name = "Cuentas";
      ComboBox cuentas2 = this.Cuentas;
      size1 = new Size(191, 21);
      Size size42 = size1;
      cuentas2.Size = size42;
      this.Cuentas.TabIndex = 329;
      this.Cuentas.TabStop = false;
      this.Cuentas.Text = " >> Seleccione Cuenta << ";
      this.Cuentas.Visible = false;
      this.CodigoOculto.Controls.Add((Control) this.Navegador);
      this.CodigoOculto.Controls.Add((Control) this.CKUPDT);
      this.CodigoOculto.Controls.Add((Control) this.Cuentas);
      GroupBox codigoOculto1 = this.CodigoOculto;
      point1 = new Point(5, 30);
      Point point43 = point1;
      codigoOculto1.Location = point43;
      this.CodigoOculto.Name = "CodigoOculto";
      GroupBox codigoOculto2 = this.CodigoOculto;
      size1 = new Size(15, 17);
      Size size43 = size1;
      codigoOculto2.Size = size43;
      this.CodigoOculto.TabIndex = 331;
      this.CodigoOculto.TabStop = false;
      this.CodigoOculto.Visible = false;
      WebBrowser navegador1 = this.Navegador;
      point1 = new Point(6, 37);
      Point point44 = point1;
      navegador1.Location = point44;
      WebBrowser navegador2 = this.Navegador;
      size1 = new Size(20, 20);
      Size size44 = size1;
      navegador2.MinimumSize = size44;
      this.Navegador.Name = "Navegador";
      this.Navegador.ScrollBarsEnabled = false;
      WebBrowser navegador3 = this.Navegador;
      size1 = new Size(20, 20);
      Size size45 = size1;
      navegador3.Size = size45;
      this.Navegador.TabIndex = 316;
      this.Navegador.Url = new Uri("", UriKind.Relative);
      this.Navegador.Visible = false;
      this.CKUPDT.AutoSize = true;
      CheckBox ckupdt1 = this.CKUPDT;
      point1 = new Point(27, 39);
      Point point45 = point1;
      ckupdt1.Location = point45;
      this.CKUPDT.Name = "CKUPDT";
      CheckBox ckupdt2 = this.CKUPDT;
      size1 = new Size(15, 14);
      Size size46 = size1;
      ckupdt2.Size = size46;
      this.CKUPDT.TabIndex = 317;
      this.CKUPDT.UseVisualStyleBackColor = true;
      this.CKUPDT.Visible = false;
      this.DeLoadAcc.Interval = 1;
      this.BotonHelp.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonHelp.BackgroundImage = (Image) Class34.smethod_83();
      this.BotonHelp.BackgroundImageLayout = ImageLayout.Center;
      this.BotonHelp.Cursor = Cursors.Hand;
      this.BotonHelp.FlatAppearance.BorderSize = 0;
      this.BotonHelp.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BotonHelp.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BotonHelp.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BotonHelp.FlatStyle = FlatStyle.Flat;
      this.BotonHelp.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BotonHelp.ForeColor = Color.Transparent;
      Button botonHelp1 = this.BotonHelp;
      point1 = new Point(430, 93);
      Point point46 = point1;
      botonHelp1.Location = point46;
      this.BotonHelp.Name = "BotonHelp";
      Button botonHelp2 = this.BotonHelp;
      size1 = new Size(32, 25);
      Size size47 = size1;
      botonHelp2.Size = size47;
      this.BotonHelp.TabIndex = 279;
      this.BotonHelp.TabStop = false;
      this.BotonHelp.UseVisualStyleBackColor = false;
      this.AutoScaleDimensions = new SizeF(6f, 13f);
      this.AutoScaleMode = AutoScaleMode.Font;
      this.BackColor = Color.Black;
      // ISSUE: reference to a compiler-generated method
      this.BackgroundImage = (Image) Class34.smethod_82();
      this.BackgroundImageLayout = ImageLayout.Center;
      this.CancelButton = (IButtonControl) this.Minimizar;
      size1 = new Size(478, 240);
      this.ClientSize = size1;
      this.Controls.Add((Control) this.ClientJPN);
      this.Controls.Add((Control) this.ClientCHN);
      this.Controls.Add((Control) this.ClientKOR);
      this.Controls.Add((Control) this.BotonReload);
      this.Controls.Add((Control) this.CodigoOculto);
      this.Controls.Add((Control) this.LabelInfo);
      this.Controls.Add((Control) this.ClientSuport);
      this.Controls.Add((Control) this.Boton2);
      this.Controls.Add((Control) this.Boton6);
      this.Controls.Add((Control) this.Boton5);
      this.Controls.Add((Control) this.Boton4);
      this.Controls.Add((Control) this.BotonFinderMaker);
      this.Controls.Add((Control) this.BotonSQLMaker);
      this.Controls.Add((Control) this.Boton7);
      this.Controls.Add((Control) this.BotonSkillMaker);
      this.Controls.Add((Control) this.BotonItemMaker);
      this.Controls.Add((Control) this.BotonGuildMaker);
      this.Controls.Add((Control) this.BotonMoveMaker);
      this.Controls.Add((Control) this.BotonAccountMaker);
      this.Controls.Add((Control) this.PswSQL);
      this.Controls.Add((Control) this.UserSQL);
      this.Controls.Add((Control) this.BotonConectarSQL);
      this.Controls.Add((Control) this.BotonCerrarLoging);
      this.Controls.Add((Control) this.LogingSQL);
      this.Controls.Add((Control) this.BotonLogingSQL);
      this.Controls.Add((Control) this.PayPal2);
      this.Controls.Add((Control) this.PayPal1);
      this.Controls.Add((Control) this.TopOnOff);
      this.Controls.Add((Control) this.BanderaID);
      this.Controls.Add((Control) this.InicialesIdioma);
      this.Controls.Add((Control) this.Label1);
      this.Controls.Add((Control) this.UpDater);
      this.Controls.Add((Control) this.RealVersion);
      this.Controls.Add((Control) this.MMKNM);
      this.Controls.Add((Control) this.BUpDate);
      this.Controls.Add((Control) this.BotonCreditos);
      this.Controls.Add((Control) this.Minimizar);
      this.Controls.Add((Control) this.Cerrar);
      this.Controls.Add((Control) this.BotonHelp);
      this.Controls.Add((Control) this.BotonConfig);
      this.Controls.Add((Control) this.PictureBox2);
      this.Controls.Add((Control) this.CargaCuentasProgres);
      this.DoubleBuffered = true;
      this.FormBorderStyle = FormBorderStyle.None;
      this.Icon = (Icon) componentResourceManager.GetObject("$this.Icon");
      this.MaximizeBox = false;
      size1 = new Size(478, 240);
      this.MaximumSize = size1;
      this.MinimizeBox = false;
      size1 = new Size(478, 240);
      this.MinimumSize = size1;
      this.Name = "MuMaker";
      this.StartPosition = FormStartPosition.CenterScreen;
      this.Text = "MuMaker";
      this.TransparencyKey = Color.Red;
      ((ISupportInitialize) this.BanderaID).EndInit();
      ((ISupportInitialize) this.PictureBox2).EndInit();
      ((ISupportInitialize) this.PayPal1).EndInit();
      ((ISupportInitialize) this.PayPal2).EndInit();
      ((ISupportInitialize) this.LogingSQL).EndInit();
      this.CodigoOculto.ResumeLayout(false);
      this.CodigoOculto.PerformLayout();
      this.ResumeLayout(false);
      this.PerformLayout();
    }

    protected override void WndProc(ref Message message_0)
    {
      if (this.WindowState == FormWindowState.Maximized)
        this.WindowState = FormWindowState.Normal;
      if (message_0.Msg == 132)
      {
        base.WndProc(ref message_0);
        if (message_0.Result.ToInt32() != 1)
          return;
        message_0.Result = (IntPtr) 2;
      }
      else
        base.WndProc(ref message_0);
    }

    public object RevisarNombre()
    {
      this.MMKNM.Text = !Operators.ConditionalCompareObjectEqual(Class26.object_18, (object) "", false) ? Conversions.ToString(Class26.object_18) : "N00B";
      return (object) true;
    }

    public object RevisarVersion()
    {
      this.UpDater.Hide();
      if (Operators.ConditionalCompareObjectNotEqual(Class26.object_0, (object) "0", false))
      {
        if (Operators.CompareString(Strings.Replace(this.RealVersion.Text, ".", "", 1, -1, CompareMethod.Binary), Strings.Replace(Conversions.ToString(Class26.object_0), ".", "", 1, -1, CompareMethod.Binary), false) < 0)
        {
          this.UPDTimer.Enabled = true;
          this.UpDater.Show();
        }
        else
        {
          this.UPDTimer.Enabled = false;
          this.UpDater.Hide();
        }
      }
      return (object) true;
    }

    public object Excepciones()
    {
      if (Operators.ConditionalCompareObjectEqual(Class26.object_16, (object) 1, false))
      {
        this.BotonReload.Enabled = true;
        this.MenuReload.Enabled = true;
        this.BotonReload.Visible = true;
        this.MenuSeparador1.Visible = true;
        this.MenuReload.Visible = true;
      }
      else
      {
        this.BotonReload.Enabled = false;
        this.MenuReload.Enabled = false;
        this.BotonReload.Visible = false;
        this.MenuReload.Visible = false;
        this.MenuSeparador1.Visible = false;
      }
      return (object) true;
    }

    public void ClientCnMMK()
    {
      string str1 = Class18.smethod_5("CN");
      string str2 = Class18.smethod_5(Class26.string_5);
      string str3 = Class18.smethod_5(Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "Personal", "Name", "N00B"));
      string str4 = Class18.smethod_5(Class26.string_0);
      string str5 = Class18.smethod_5(Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "IPServer", "127.0.0.1"));
      string str6 = Class18.smethod_5(Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "Connection", "Local"));
      string str7 = Class18.smethod_5(Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "Languaje", "Espanol"));
      string str8 = Class18.smethod_5("ON");
      try
      {
        this.Navegador.Navigate(new Uri("http://mumaker.sytes.net/mumaker/clientes/mumaker.php?V0=" + str1 + "&V1=" + str2 + "&V2=" + str3 + "&V3=" + str4 + "&V4=" + str5 + "&V5=" + str6 + "&V6=" + str7 + "&V7=" + str8));
        this.Navegador.Refresh();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        ProjectData.ClearProjectError();
      }
    }

    public void ClientOnMMK()
    {
      string str1 = Class18.smethod_5("ON");
      string str2 = Class18.smethod_5(Class26.string_5);
      string str3 = Class18.smethod_5(Class26.string_0);
      try
      {
        this.Navegador.Navigate(new Uri("http://mumaker.sytes.net/mumaker/clientes/mumaker.php?V0=" + str1 + "&V1=" + str2 + "&V3=" + str3));
        this.Navegador.Refresh();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        ProjectData.ClearProjectError();
      }
    }

    public object CargarCuentas()
    {
      if (Operators.ConditionalCompareObjectEqual(Class26.object_16, (object) 1, false))
      {
        Class7.smethod_0();
        try
        {
          Class28.sqlConnection_1.Open();
          Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
          Class28.sqlCommand_1.CommandText = "SELECT memb___id FROM MEMB_INFO ORDER BY memb___id ASC";
          Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
          this.Cuentas.Text = Conversions.ToString(Class30.object_7);
          this.Cuentas.Items.Clear();
          while (Class28.sqlDataReader_1.Read())
            this.Cuentas.Items.Add((object) Class28.sqlDataReader_1[0].ToString());
          Class28.sqlDataReader_1.Close();
        }
        catch (Exception ex)
        {
          ProjectData.SetProjectError(ex);
          int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
          ProjectData.ClearProjectError();
        }
        Class7.smethod_5();
      }
      return (object) true;
    }

    public void ReLoadCuentas()
    {
      this.OcultarBotones();
      this.DisableMenus();
      this.OcultarLoginSQL();
      this.DeLoadAcc.Start();
      this.CargaCuentasProgres.Visible = true;
      if (Operators.ConditionalCompareObjectEqual(Class26.object_16, (object) 1, false))
      {
        Class7.smethod_0();
        try
        {
          Class28.sqlConnection_1.Open();
          Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
          Class28.sqlCommand_1.CommandText = "SELECT memb___id FROM MEMB_INFO ORDER BY memb___id ASC";
          Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
          this.Cuentas.Text = Conversions.ToString(Class30.object_7);
          this.Cuentas.Items.Clear();
          while (Class28.sqlDataReader_1.Read())
            this.Cuentas.Items.Add((object) Class28.sqlDataReader_1[0].ToString());
          Class28.sqlDataReader_1.Close();
        }
        catch (Exception ex)
        {
          ProjectData.SetProjectError(ex);
          int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
          ProjectData.ClearProjectError();
        }
        Class7.smethod_5();
      }
      this.CargaCuentasProgres.Visible = false;
      this.DeLoadAcc.Stop();
      this.MostrarBotones();
      this.EnableMenus();
    }

    public object OcultarBotones()
    {
      this.BotonReload.Visible = false;
      this.BotonAccountMaker.Visible = false;
      this.BotonItemMaker.Visible = false;
      this.BotonSkillMaker.Visible = false;
      this.BotonMoveMaker.Visible = false;
      this.BotonGuildMaker.Visible = false;
      this.BotonSQLMaker.Visible = false;
      this.Boton2.Visible = false;
      this.BotonFinderMaker.Visible = false;
      this.Boton4.Visible = false;
      this.Boton5.Visible = false;
      this.Boton6.Visible = false;
      this.Boton7.Visible = false;
      return (object) true;
    }

    public object OcultarMenus()
    {
      this.MenuAccountMaker.Visible = false;
      this.MenuItemMaker.Visible = false;
      this.MenuSkillMaker.Visible = false;
      this.MenuGuildMaker.Visible = false;
      this.MenuXxMaker2.Visible = false;
      this.MenuMoveMaker.Visible = false;
      this.MenuFinderMaker.Visible = false;
      this.MenuXxMaker4.Visible = false;
      this.MenuXxMaker5.Visible = false;
      this.MenuXxMaker6.Visible = false;
      this.MenuXxMaker7.Visible = false;
      this.MenuSQLMaker.Visible = false;
      this.MenuSeparador1.Visible = false;
      this.MenuReload.Visible = false;
      this.MenuSeparador2.Visible = false;
      return (object) true;
    }

    public object OcultarLoginSQL()
    {
      this.BotonCerrarLoging.Visible = false;
      this.BotonConectarSQL.Visible = false;
      this.UserSQL.Visible = false;
      this.PswSQL.Visible = false;
      this.LogingSQL.Visible = false;
      return (object) true;
    }

    public object MostrarBotones()
    {
      if (Operators.ConditionalCompareObjectEqual(Class26.object_16, (object) 1, false))
        this.BotonReload.Visible = true;
      this.BotonAccountMaker.Visible = true;
      this.BotonItemMaker.Visible = true;
      this.BotonSkillMaker.Visible = true;
      this.BotonMoveMaker.Visible = true;
      this.BotonGuildMaker.Visible = true;
      this.BotonSQLMaker.Visible = true;
      this.Boton2.Visible = true;
      this.BotonFinderMaker.Visible = true;
      this.Boton4.Visible = true;
      this.Boton5.Visible = true;
      this.Boton6.Visible = true;
      this.Boton7.Visible = true;
      return (object) true;
    }

    public object MostrarMenus()
    {
      if (Operators.ConditionalCompareObjectEqual(Class26.object_16, (object) 1, false))
      {
        this.MenuSeparador1.Visible = true;
        this.MenuReload.Visible = true;
      }
      this.MenuAccountMaker.Visible = true;
      this.MenuItemMaker.Visible = true;
      this.MenuSkillMaker.Visible = true;
      this.MenuGuildMaker.Visible = true;
      this.MenuMoveMaker.Visible = true;
      this.MenuFinderMaker.Visible = true;
      this.MenuSQLMaker.Visible = true;
      this.MenuSeparador2.Visible = true;
      return (object) true;
    }

    public object MostrarLoginSQL()
    {
      this.BotonCerrarLoging.Visible = true;
      this.BotonConectarSQL.Visible = true;
      this.UserSQL.Visible = true;
      this.PswSQL.Visible = true;
      this.LogingSQL.Visible = true;
      return (object) true;
    }

    public object DisableBotones()
    {
      this.BotonReload.Enabled = false;
      this.BotonAccountMaker.Enabled = false;
      this.BotonItemMaker.Enabled = false;
      this.BotonSkillMaker.Enabled = false;
      this.BotonMoveMaker.Enabled = false;
      this.BotonGuildMaker.Enabled = false;
      this.BotonSQLMaker.Enabled = false;
      this.Boton2.Enabled = false;
      this.BotonFinderMaker.Enabled = false;
      this.Boton4.Enabled = false;
      this.Boton5.Enabled = false;
      this.Boton6.Enabled = false;
      this.Boton7.Enabled = false;
      this.BotonConfig.Enabled = false;
      return (object) true;
    }

    public object DisableMenus()
    {
      this.MenuAccountMaker.Enabled = false;
      this.MenuItemMaker.Enabled = false;
      this.MenuSkillMaker.Enabled = false;
      this.MenuGuildMaker.Enabled = false;
      this.MenuXxMaker2.Enabled = false;
      this.MenuMoveMaker.Enabled = false;
      this.MenuFinderMaker.Enabled = false;
      this.MenuXxMaker4.Enabled = false;
      this.MenuXxMaker5.Enabled = false;
      this.MenuXxMaker6.Enabled = false;
      this.MenuXxMaker7.Enabled = false;
      this.MenuSQLMaker.Enabled = false;
      this.MenuReload.Enabled = false;
      return (object) true;
    }

    public object DisableLoginSQL()
    {
      this.BotonCerrarLoging.Enabled = false;
      this.BotonConectarSQL.Enabled = false;
      this.UserSQL.Enabled = false;
      this.PswSQL.Enabled = false;
      this.LogingSQL.Enabled = false;
      return (object) true;
    }

    public object EnableBotones()
    {
      if (Operators.ConditionalCompareObjectEqual(Class26.object_16, (object) 1, false))
        this.BotonReload.Enabled = true;
      this.BotonAccountMaker.Enabled = true;
      this.BotonItemMaker.Enabled = true;
      this.BotonSkillMaker.Enabled = true;
      this.BotonMoveMaker.Enabled = true;
      this.BotonGuildMaker.Enabled = true;
      this.BotonSQLMaker.Enabled = true;
      this.Boton2.Enabled = false;
      this.BotonFinderMaker.Enabled = true;
      this.Boton4.Enabled = false;
      this.Boton5.Enabled = false;
      this.Boton6.Enabled = false;
      this.Boton7.Enabled = false;
      return (object) true;
    }

    public object EnableMenus()
    {
      if (Operators.ConditionalCompareObjectEqual(Class26.object_16, (object) 1, false))
        this.MenuReload.Enabled = true;
      this.MenuAccountMaker.Enabled = true;
      this.MenuItemMaker.Enabled = true;
      this.MenuSkillMaker.Enabled = true;
      this.MenuGuildMaker.Enabled = true;
      this.MenuXxMaker2.Enabled = false;
      this.MenuMoveMaker.Enabled = true;
      this.MenuFinderMaker.Enabled = true;
      this.MenuXxMaker4.Enabled = false;
      this.MenuXxMaker5.Enabled = false;
      this.MenuXxMaker6.Enabled = false;
      this.MenuXxMaker7.Enabled = false;
      this.MenuSQLMaker.Enabled = true;
      this.MenuReload.Enabled = true;
      return (object) true;
    }

    public object EnableLoginSQL()
    {
      this.BotonCerrarLoging.Enabled = true;
      this.BotonConectarSQL.Enabled = true;
      this.UserSQL.Enabled = true;
      this.PswSQL.Enabled = true;
      this.LogingSQL.Enabled = true;
      return (object) true;
    }

    public object Traducir()
    {
      this.ToolTips.SetToolTip((Control) this.Cerrar, Conversions.ToString(Class30.object_0));
      this.ToolTips.SetToolTip((Control) this.Minimizar, Conversions.ToString(Class30.object_1));
      this.ToolTips.SetToolTip((Control) this.BanderaID, Conversions.ToString(Class30.object_3));
      this.ToolTips.SetToolTip((Control) this.InicialesIdioma, Conversions.ToString(Class30.object_2));
      this.BanderaID.BackgroundImage = (Image) new Bitmap(Class30.string_1);
      this.ClientKOR.Text = Class26.string_1;
      this.ClientCHN.Text = Class26.string_2;
      this.ClientJPN.Text = Class26.string_3;
      this.InicialesIdioma.Text = Class30.string_2;
      this.TopOnOff.Checked = Operators.ConditionalCompareObjectEqual(Class26.object_21, (object) 1, false);
      this.Text = Conversions.ToString(Operators.ConcatenateObject((object) (this.Text + " - "), Class26.object_18));
      return (object) true;
    }

    private void method_0(object sender, EventArgs e)
    {
      this.UserSQL.Text = "";
      this.PswSQL.Text = "";
      this.OcultarLoginSQL();
      this.BotonLogingSQL.Visible = true;
    }

    private void method_1(object sender, EventArgs e)
    {
      Class26.object_2 = (object) this.UserSQL.Text;
      Class26.object_3 = (object) this.PswSQL.Text;
      Class7.smethod_0();
      try
      {
        Class28.sqlConnection_1.Open();
        this.EnableBotones();
        this.EnableMenus();
        Class7.smethod_5();
        this.OcultarLoginSQL();
        this.MostrarBotones();
        this.MostrarMenus();
        this.CargarCuentas();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        this.DisableBotones();
        this.DisableMenus();
        Class7.smethod_5();
        this.MostrarLoginSQL();
        this.UserSQL.Text = "";
        this.PswSQL.Text = "";
        this.BotonConfig.Enabled = true;
        ProjectData.ClearProjectError();
      }
      this.BotonCreditos.Focus();
    }

    private void MuMaker_Load(object sender, EventArgs e)
    {
      if (Operators.ConditionalCompareObjectEqual(Class18.smethod_29(), (object) 1, false))
        this.Close();
      this.RealVersion.Text = Class26.string_0;
      if (new FileInfo("MuMaker.exe").Exists)
      {
        VentanaBarraLoad.DefInstance.Show();
        this.Excepciones();
        VentanaBarraLoad.DefInstance.Carga.Value = 5;
        Class18.smethod_32();
        Class18.smethod_33();
        VentanaBarraLoad.DefInstance.Carga.Value = 10;
        Class10.smethod_0();
        VentanaBarraLoad.DefInstance.Carga.Value = 15;
        Class10.smethod_1();
        VentanaBarraLoad.DefInstance.Carga.Value = 20;
        Class10.smethod_2();
        VentanaBarraLoad.DefInstance.Carga.Value = 25;
        Class10.smethod_3();
        VentanaBarraLoad.DefInstance.Carga.Value = 30;
        FileInfo fileInfo = new FileInfo("Config.ini");
        VentanaBarraLoad.DefInstance.Carga.Value = 40;
        if (!fileInfo.Exists)
        {
          ConfigMaker.DefInstance.Show();
          this.DisableBotones();
          this.DisableMenus();
          this.DisableLoginSQL();
        }
        else
        {
          this.Reloj.Enabled = true;
          if (Operators.ConditionalCompareObjectEqual(Class26.object_1, (object) 1, false))
          {
            Class7.smethod_0();
            try
            {
              this.EnableBotones();
              this.EnableMenus();
              VentanaBarraLoad.DefInstance.Carga.Value = 60;
              this.CargarCuentas();
            }
            catch (Exception ex)
            {
              ProjectData.SetProjectError(ex);
              int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
              this.DisableBotones();
              this.DisableMenus();
              Class7.smethod_5();
              this.BotonConfig.Enabled = true;
              ProjectData.ClearProjectError();
            }
          }
          else
          {
            this.MostrarLoginSQL();
            this.OcultarBotones();
            this.DisableMenus();
          }
        }
        VentanaBarraLoad.DefInstance.Carga.Value = 50;
        if (Operators.ConditionalCompareObjectGreater(Class18.smethod_22(), (object) 0, false))
        {
          this.DisableBotones();
          this.DisableMenus();
          this.DisableLoginSQL();
        }
        else
          this.Traducir();
        VentanaBarraLoad.DefInstance.Carga.Value = 70;
        Class26.smethod_0();
        VentanaBarraLoad.DefInstance.Carga.Value = 80;
        this.RevisarNombre();
        VentanaBarraLoad.DefInstance.Carga.Value = 90;
        if (this.Reloj.Enabled)
        {
          new Thread(new ThreadStart(this.ClientCnMMK))
          {
            IsBackground = true
          }.Start();
          new Thread(new ThreadStart(Class18.smethod_21))
          {
            IsBackground = true
          }.Start();
        }
        this.RevisarVersion();
        VentanaBarraLoad.DefInstance.Carga.Value = 100;
        VentanaBarraLoad.DefInstance.Hide();
      }
      else
      {
        int num = (int) Interaction.MsgBox((object) "Rename <=> MuMaker.exe", MsgBoxStyle.OkOnly, (object) null);
        this.DisableBotones();
        this.DisableMenus();
        this.DisableLoginSQL();
      }
      this.BotonCreditos.Focus();
    }

    private void MuMaker_Move(object sender, EventArgs e)
    {
      int x1 = checked (this.Location.X - 268);
      Point point1 = this.Location;
      int y1 = checked (point1.Y + 22);
      UpDateMaker defInstance1 = UpDateMaker.DefInstance;
      point1 = new Point(x1, y1);
      Point point2 = point1;
      defInstance1.Location = point2;
      UpDateMaker.DefInstance.TopMost = true;
      int x2 = checked (this.Location.X - 15);
      Point point3 = this.Location;
      int y2 = checked (point3.Y + 233);
      Creditos defInstance2 = Creditos.DefInstance;
      point3 = new Point(x2, y2);
      Point point4 = point3;
      defInstance2.Location = point4;
      Creditos.DefInstance.TopMost = true;
      this.TopMost = true;
    }

    private void MuMaker_LocationChanged(object sender, EventArgs e)
    {
      if (ConfigMaker.DefInstance.Visible)
        return;
      if (this.WindowState == FormWindowState.Minimized)
      {
        this.TopMost = false;
        this.Hide();
      }
      if (this.WindowState != FormWindowState.Maximized)
        return;
      this.TopMost = true;
    }

    private void method_2(object sender, EventArgs e)
    {
      Class18.smethod_36();
      if (!this.TopOnOff.Checked)
        this.WindowState = FormWindowState.Minimized;
      AccountMaker.DefInstance.Show();
      AccountMaker.DefInstance.Activate();
      this.BotonCreditos.Focus();
    }

    private void method_3(object sender, EventArgs e)
    {
      Class18.smethod_37();
      if (!this.TopOnOff.Checked)
        this.WindowState = FormWindowState.Minimized;
      ItemMaker.DefInstance.Show();
      ItemMaker.DefInstance.Activate();
      this.BotonCreditos.Focus();
    }

    private void method_4(object sender, EventArgs e)
    {
      Class18.smethod_38();
      if (!this.TopOnOff.Checked)
        this.WindowState = FormWindowState.Minimized;
      SkillMaker.DefInstance.Show();
      SkillMaker.DefInstance.Activate();
      this.BotonCreditos.Focus();
    }

    private void method_5(object sender, EventArgs e)
    {
      Class18.smethod_39();
      if (!this.TopOnOff.Checked)
        this.WindowState = FormWindowState.Minimized;
      GuildMaker.DefInstance.Show();
      GuildMaker.DefInstance.Activate();
      this.BotonCreditos.Focus();
    }

    private void method_6(object sender, EventArgs e)
    {
      Class18.smethod_40();
      if (!this.TopOnOff.Checked)
        this.WindowState = FormWindowState.Minimized;
      MoveMaker.DefInstance.Show();
      MoveMaker.DefInstance.Activate();
      this.BotonCreditos.Focus();
    }

    private void method_7(object sender, EventArgs e)
    {
      Class18.smethod_41();
      if (!this.TopOnOff.Checked)
        this.WindowState = FormWindowState.Minimized;
      FinderMaker.DefInstance.Show();
      FinderMaker.DefInstance.Activate();
      this.BotonCreditos.Focus();
    }

    private void method_8(object sender, EventArgs e)
    {
      Class18.smethod_42();
      if (!this.TopOnOff.Checked)
        this.WindowState = FormWindowState.Minimized;
      SQLMaker.DefInstance.Show();
      SQLMaker.DefInstance.Activate();
      this.BotonCreditos.Focus();
    }

    private void method_9(object sender, EventArgs e)
    {
      Class18.smethod_35();
      ConfigMaker.DefInstance.Show();
      ConfigMaker.DefInstance.Select();
      ConfigMaker.DefInstance.TopLevel = true;
      this.BotonCreditos.Focus();
    }

    private void method_10(object sender, EventArgs e)
    {
      this.BotonLogingSQL.Visible = false;
      this.BotonCerrarLoging.Visible = true;
      this.BotonConectarSQL.Visible = true;
      this.UserSQL.Visible = true;
      this.PswSQL.Visible = true;
      this.LogingSQL.Visible = true;
      this.BotonCreditos.Focus();
    }

    private void method_11(object sender, EventArgs e)
    {
      this.CargaCuentasProgres.Value = 0;
      new Thread(new ThreadStart(this.ReLoadCuentas))
      {
        IsBackground = true
      }.Start();
      this.BotonCreditos.Focus();
    }

    private void method_12(object sender, EventArgs e)
    {
      if (!this.TopOnOff.Checked)
        this.WindowState = FormWindowState.Minimized;
      HelpMaker.DefInstance.Show();
      HelpMaker.DefInstance.Activate();
      this.BotonCreditos.Focus();
    }

    private void SysTrayIcon_DoubleClick(object sender, EventArgs e)
    {
      if (this.WindowState == FormWindowState.Normal)
      {
        this.WindowState = FormWindowState.Minimized;
      }
      else
      {
        this.Show();
        this.WindowState = FormWindowState.Normal;
      }
    }

    private void MenuAccountMaker_Click(object sender, EventArgs e)
    {
      Class18.smethod_36();
      if (!this.TopOnOff.Checked)
        this.WindowState = FormWindowState.Minimized;
      VentanaBarraLoad.DefInstance.Show();
      AccountMaker.DefInstance.Show();
      VentanaBarraLoad.DefInstance.Hide();
      AccountMaker.DefInstance.Activate();
    }

    private void MenuItemMaker_Click(object sender, EventArgs e)
    {
      Class18.smethod_37();
      if (!this.TopOnOff.Checked)
        this.WindowState = FormWindowState.Minimized;
      VentanaBarraLoad.DefInstance.Show();
      ItemMaker.DefInstance.Show();
      VentanaBarraLoad.DefInstance.Hide();
      ItemMaker.DefInstance.Activate();
    }

    private void MenuSkillMaker_Click(object sender, EventArgs e)
    {
      Class18.smethod_38();
      if (!this.TopOnOff.Checked)
        this.WindowState = FormWindowState.Minimized;
      VentanaBarraLoad.DefInstance.Show();
      SkillMaker.DefInstance.Show();
      VentanaBarraLoad.DefInstance.Hide();
      SkillMaker.DefInstance.Activate();
    }

    private void MenuGuildMaker_Click(object sender, EventArgs e)
    {
      Class18.smethod_39();
      if (!this.TopOnOff.Checked)
        this.WindowState = FormWindowState.Minimized;
      VentanaBarraLoad.DefInstance.Show();
      GuildMaker.DefInstance.Show();
      VentanaBarraLoad.DefInstance.Hide();
      GuildMaker.DefInstance.Activate();
    }

    private void MenuMoveMaker_Click(object sender, EventArgs e)
    {
      Class18.smethod_40();
      if (!this.TopOnOff.Checked)
        this.WindowState = FormWindowState.Minimized;
      VentanaBarraLoad.DefInstance.Show();
      MoveMaker.DefInstance.Show();
      VentanaBarraLoad.DefInstance.Hide();
      MoveMaker.DefInstance.Activate();
    }

    private void MenuFinderMaker_Click(object sender, EventArgs e)
    {
      Class18.smethod_41();
      if (!this.TopOnOff.Checked)
        this.WindowState = FormWindowState.Minimized;
      VentanaBarraLoad.DefInstance.Show();
      FinderMaker.DefInstance.Show();
      VentanaBarraLoad.DefInstance.Hide();
      FinderMaker.DefInstance.Activate();
    }

    private void MenuSQLMaker_Click(object sender, EventArgs e)
    {
      Class18.smethod_42();
      if (!this.TopOnOff.Checked)
        this.WindowState = FormWindowState.Minimized;
      VentanaBarraLoad.DefInstance.Show();
      SQLMaker.DefInstance.Show();
      VentanaBarraLoad.DefInstance.Hide();
      SQLMaker.DefInstance.Activate();
    }

    private void MenuReload_Click(object sender, EventArgs e)
    {
      new Thread(new ThreadStart(this.ReLoadCuentas))
      {
        IsBackground = true
      }.Start();
      this.BotonCreditos.Focus();
    }

    private void MenuHelpGuide_Click(object sender, EventArgs e)
    {
      if (!this.TopOnOff.Checked)
        this.WindowState = FormWindowState.Minimized;
      HelpMaker.DefInstance.Show();
      HelpMaker.DefInstance.Activate();
      this.BotonCreditos.Focus();
    }

    private void MenuCerrar_Click(object sender, EventArgs e)
    {
      Class18.smethod_43();
      this.Visible = false;
      this.SysTrayIcon.Dispose();
      this.Close();
    }

    private void BUpDate_Click(object sender, EventArgs e)
    {
      UpDateMaker.DefInstance.Show();
      int x = checked (this.Location.X - 268);
      Point point1 = this.Location;
      int y = checked (point1.Y + 22);
      UpDateMaker defInstance = UpDateMaker.DefInstance;
      point1 = new Point(x, y);
      Point point2 = point1;
      defInstance.Location = point2;
      UpDateMaker.DefInstance.TopMost = true;
      this.TopOnOff.Focus();
    }

    private void BotonCreditos_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
    {
      int x = checked (this.Location.X - 15);
      Point point1 = this.Location;
      int y = checked (point1.Y + 233);
      Creditos.DefInstance.Show();
      Creditos defInstance = Creditos.DefInstance;
      point1 = new Point(x, y);
      Point point2 = point1;
      defInstance.Location = point2;
      Creditos.DefInstance.TopMost = true;
      this.TopMost = true;
    }

    private void TopOnOff_CheckedChanged(object sender, EventArgs e)
    {
      this.BotonCreditos.Focus();
      if (this.TopOnOff.Checked)
        Class18.smethod_2(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "FX", "Top", "1");
      else
        Class18.smethod_2(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "FX", "Top", "0");
    }

    private void method_13(object sender, EventArgs e)
    {
      Class18.smethod_43();
      this.BotonCreditos.Focus();
      this.Visible = false;
      this.SysTrayIcon.Dispose();
      this.Close();
    }

    private void method_14(object sender, EventArgs e)
    {
      this.WindowState = FormWindowState.Minimized;
    }

    private void Reloj_Tick(object sender, EventArgs e)
    {
      new Thread(new ThreadStart(this.ClientOnMMK))
      {
        IsBackground = true
      }.Start();
      this.UpDater.Hide();
      if (!new FileInfo("UPDT.INI").Exists)
        new Thread(new ThreadStart(Class18.smethod_21))
        {
          IsBackground = true
        }.Start();
      this.RevisarVersion();
      if (Operators.ConditionalCompareObjectNotEqual(Class26.object_0, (object) "0", false) && Operators.CompareString(Strings.Replace(Class26.string_0, ".", "", 1, -1, CompareMethod.Binary), Strings.Replace(Conversions.ToString(Class26.object_0), ".", "", 1, -1, CompareMethod.Binary), false) < 0)
      {
        this.UpDater.Show();
        this.UPDTimer.Enabled = true;
      }
      VBMath.Randomize();
      object Left = (object) (float) ((double) Conversion.Int(9f * VBMath.Rnd()) + 20.0);
      object Right1 = (object) Conversion.Int(9f * VBMath.Rnd());
      object Right2 = (object) Conversion.Int(9f * VBMath.Rnd());
      object Right3 = (object) Conversion.Int(9f * VBMath.Rnd());
      object Right4 = (object) Conversion.Int(9f * VBMath.Rnd());
      if (Operators.ConditionalCompareObjectEqual(Operators.ConcatenateObject(Operators.ConcatenateObject(Operators.ConcatenateObject(Operators.ConcatenateObject(Left, Right1), Right2), Right3), Right4), (object) 0, false))
        this.Reloj.Interval = 30000;
      else
        this.Reloj.Interval = Conversions.ToInteger(Operators.ConcatenateObject(Operators.ConcatenateObject(Operators.ConcatenateObject(Operators.ConcatenateObject(Left, Right1), Right2), Right3), Right4));
    }

    private void UPDTimer_Tick(object sender, EventArgs e)
    {
      if (this.CKUPDT.Checked)
      {
        this.UpDater.Hide();
        this.CKUPDT.Checked = false;
      }
      else
      {
        this.UpDater.Show();
        this.CKUPDT.Checked = true;
      }
    }

    private void CHVersion_Tick(object sender, EventArgs e)
    {
      new Thread(new ThreadStart(Class18.smethod_21))
      {
        IsBackground = true
      }.Start();
    }

    private void DeLoadAcc_Tick(object sender, EventArgs e)
    {
      if (this.CargaCuentasProgres.Value >= 0 & this.CargaCuentasProgres.Value <= 999)
        this.CargaCuentasProgres.Value = checked (this.CargaCuentasProgres.Value + 1);
      else
        this.CargaCuentasProgres.Value = 0;
    }

    private void PayPal1_Click(object sender, EventArgs e)
    {
      Process.Start("http://softwaretmt.sytes.net/mumaker/index.php?modulo=paypal");
    }

    private void PayPal2_Click(object sender, EventArgs e)
    {
      Process.Start("http://softwaretmt.sytes.net/mumaker/index.php?modulo=paypal");
    }

    private void MuMaker_Closing(object sender, CancelEventArgs e)
    {
      this.BotonCreditos.Focus();
      this.Visible = false;
      this.SysTrayIcon.Dispose();
      ProjectData.EndApp();
    }

    private void method_15(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonConfig.BackgroundImage = (Image) Class34.smethod_14();
      this.BotonCreditos.Focus();
    }

    private void method_16(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonConfig.BackgroundImage = (Image) Class34.smethod_15();
    }

    private void method_17(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Minimizar.BackgroundImage = (Image) Class34.smethod_86();
      this.BotonCreditos.Focus();
    }

    private void method_18(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Minimizar.BackgroundImage = (Image) Class34.smethod_87();
    }

    private void method_19(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) Class34.smethod_44();
      this.BotonCreditos.Focus();
    }

    private void method_20(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) Class34.smethod_45();
    }

    private void method_21(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonAccountMaker.BackgroundImage = (Image) Class34.smethod_10();
      this.BotonCreditos.Focus();
    }

    private void method_22(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonAccountMaker.BackgroundImage = (Image) Class34.smethod_11();
    }

    private void method_23(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonItemMaker.BackgroundImage = (Image) Class34.smethod_20();
      this.BotonCreditos.Focus();
    }

    private void method_24(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonItemMaker.BackgroundImage = (Image) Class34.smethod_21();
    }

    private void method_25(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonSkillMaker.BackgroundImage = (Image) Class34.smethod_29();
      this.BotonCreditos.Focus();
    }

    private void method_26(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonSkillMaker.BackgroundImage = (Image) Class34.smethod_30();
    }

    private void method_27(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonGuildMaker.BackgroundImage = (Image) Class34.smethod_18();
      this.BotonCreditos.Focus();
    }

    private void method_28(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonGuildMaker.BackgroundImage = (Image) Class34.smethod_19();
    }

    private void method_29(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonMoveMaker.BackgroundImage = (Image) Class34.smethod_24();
      this.BotonCreditos.Focus();
    }

    private void method_30(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonMoveMaker.BackgroundImage = (Image) Class34.smethod_25();
    }

    private void method_31(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonFinderMaker.BackgroundImage = (Image) Class34.smethod_16();
      this.BotonCreditos.Focus();
    }

    private void method_32(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonFinderMaker.BackgroundImage = (Image) Class34.smethod_17();
    }

    private void method_33(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonSQLMaker.BackgroundImage = (Image) Class34.smethod_31();
      this.BotonCreditos.Focus();
    }

    private void method_34(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonSQLMaker.BackgroundImage = (Image) Class34.smethod_32();
    }

    private void method_35(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonConectarSQL.BackgroundImage = (Image) Class34.smethod_48();
      this.BotonCreditos.Focus();
    }

    private void method_36(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonConectarSQL.BackgroundImage = (Image) Class34.smethod_49();
    }

    private void method_37(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonCerrarLoging.BackgroundImage = (Image) Class34.smethod_39();
      this.BotonCreditos.Focus();
    }

    private void method_38(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonCerrarLoging.BackgroundImage = (Image) Class34.smethod_40();
    }

    private void method_39(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonLogingSQL.BackgroundImage = (Image) Class34.smethod_48();
      this.BotonCreditos.Focus();
    }

    private void method_40(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonLogingSQL.BackgroundImage = (Image) Class34.smethod_49();
    }

    private void method_41(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonReload.BackgroundImage = (Image) Class34.smethod_100();
    }

    private void method_42(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonReload.BackgroundImage = (Image) Class34.smethod_101();
    }

    private void method_43(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonHelp.BackgroundImage = (Image) Class34.smethod_83();
    }

    private void method_44(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonHelp.BackgroundImage = (Image) Class34.smethod_84();
    }
  }
}
