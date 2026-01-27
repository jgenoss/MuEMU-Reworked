// Decompiled with JetBrains decompiler
// Type: MuMaker.AccountMaker
// Assembly: MuMaker, Version=1.1.3.0, Culture=neutral, PublicKeyToken=null
// MVID: 7E43A6C6-04AF-4159-BD3A-BD25660D1460
// Assembly location: D:\MuServer\Tools\MuMaker 1.13\MuMaker-cleaned.exe

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using System;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Diagnostics;
using System.Drawing;
using System.Runtime.CompilerServices;
using System.Threading;
using System.Windows.Forms;

namespace MuMaker
{
  [DesignerGenerated]
  public class AccountMaker : Form
  {
    private static AccountMaker accountMaker_0 = (AccountMaker) null;
    private IContainer icontainer_0;
    [AccessedThroughProperty("Quests")]
    private ComboBox _Quests;
    [AccessedThroughProperty("CreateID")]
    private TextBox _CreateID;
    [AccessedThroughProperty("CreatePj")]
    private Button _CreatePj;
    [AccessedThroughProperty("ToolTips")]
    private ToolTip toolTip_0;
    [AccessedThroughProperty("AccountEdit")]
    private Button _AccountEdit;
    [AccessedThroughProperty("BorrarCuenta")]
    private Button _BorrarCuenta;
    [AccessedThroughProperty("ONLineInfo")]
    private Button _ONLineInfo;
    [AccessedThroughProperty("OnlineOFF")]
    private PictureBox _OnlineOFF;
    [AccessedThroughProperty("OnlineON")]
    private PictureBox _OnlineON;
    [AccessedThroughProperty("Label18")]
    private Label _Label18;
    [AccessedThroughProperty("Label27")]
    private Label _Label27;
    [AccessedThroughProperty("Label28")]
    private Label _Label28;
    [AccessedThroughProperty("Label26")]
    private Label _Label26;
    [AccessedThroughProperty("Label25")]
    private Label _Label25;
    [AccessedThroughProperty("EditDefault")]
    private Button _EditDefault;
    [AccessedThroughProperty("ResetDefault")]
    private Button _ResetDefault;
    [AccessedThroughProperty("Aplicar")]
    private Button _Aplicar;
    [AccessedThroughProperty("Reload")]
    private Button _Reload;
    [AccessedThroughProperty("Label24")]
    private Label _Label24;
    [AccessedThroughProperty("Clases")]
    private ComboBox _Clases;
    [AccessedThroughProperty("PersonalID")]
    private TextBox _PersonalID;
    [AccessedThroughProperty("PassWord")]
    private TextBox _PassWord;
    [AccessedThroughProperty("Email")]
    private TextBox _Email;
    [AccessedThroughProperty("CuentaID")]
    private TextBox _CuentaID;
    [AccessedThroughProperty("Frutas")]
    private TextBox _Frutas;
    [AccessedThroughProperty("EditChart")]
    private TextBox _EditChart;
    [AccessedThroughProperty("EditAccount")]
    private TextBox _EditAccount;
    [AccessedThroughProperty("PKTime")]
    private TextBox _PKTime;
    [AccessedThroughProperty("PKCount")]
    private TextBox _PKCount;
    [AccessedThroughProperty("Energia")]
    private TextBox _Energia;
    [AccessedThroughProperty("Fuerza")]
    private TextBox _Fuerza;
    [AccessedThroughProperty("Vitalidad")]
    private TextBox _Vitalidad;
    [AccessedThroughProperty("Agilidad")]
    private TextBox _Agilidad;
    [AccessedThroughProperty("Exp")]
    private TextBox _Exp;
    [AccessedThroughProperty("Level")]
    private TextBox _Level;
    [AccessedThroughProperty("Puntos")]
    private TextBox _Puntos;
    [AccessedThroughProperty("Comand")]
    private TextBox _Comand;
    [AccessedThroughProperty("PersonajeSearch")]
    private TextBox _PersonajeSearch;
    [AccessedThroughProperty("CuentaSearch")]
    private TextBox _CuentaSearch;
    [AccessedThroughProperty("CreatePassWord")]
    private TextBox _CreatePassWord;
    [AccessedThroughProperty("CreateEmail")]
    private TextBox _CreateEmail;
    [AccessedThroughProperty("CreateAccount")]
    private TextBox _CreateAccount;
    [AccessedThroughProperty("Label19")]
    private Label _Label19;
    [AccessedThroughProperty("Label20")]
    private Label _Label20;
    [AccessedThroughProperty("Label21")]
    private Label _Label21;
    [AccessedThroughProperty("CtrlCode")]
    private ComboBox _CtrlCode;
    [AccessedThroughProperty("BotonSkillMaker")]
    private Button _BotonSkillMaker;
    [AccessedThroughProperty("BotonItemMaker")]
    private Button _BotonItemMaker;
    [AccessedThroughProperty("BotonGuildMaker")]
    private Button _BotonGuildMaker;
    [AccessedThroughProperty("BotonMoveMaker")]
    private Button _BotonMoveMaker;
    [AccessedThroughProperty("PKLevel")]
    private ComboBox _PKLevel;
    [AccessedThroughProperty("Label17")]
    private Label _Label17;
    [AccessedThroughProperty("Label1")]
    private Label _Label1;
    [AccessedThroughProperty("Label16")]
    private Label _Label16;
    [AccessedThroughProperty("Label14")]
    private Label _Label14;
    [AccessedThroughProperty("Label13")]
    private Label _Label13;
    [AccessedThroughProperty("Label12")]
    private Label _Label12;
    [AccessedThroughProperty("Label10")]
    private Label _Label10;
    [AccessedThroughProperty("Label6")]
    private Label _Label6;
    [AccessedThroughProperty("Label7")]
    private Label _Label7;
    [AccessedThroughProperty("Label11")]
    private Label _Label11;
    [AccessedThroughProperty("Label8")]
    private Label _Label8;
    [AccessedThroughProperty("Label9")]
    private Label _Label9;
    [AccessedThroughProperty("Label5")]
    private Label _Label5;
    [AccessedThroughProperty("Label4")]
    private Label _Label4;
    [AccessedThroughProperty("BorrarDatos")]
    private Button _BorrarDatos;
    [AccessedThroughProperty("CrearAccount")]
    private Button _CrearAccount;
    [AccessedThroughProperty("Label2")]
    private Label _Label2;
    [AccessedThroughProperty("Account")]
    private Label _Account;
    [AccessedThroughProperty("Personajes")]
    private ComboBox _Personajes;
    [AccessedThroughProperty("Cuentas")]
    private ComboBox _Cuentas;
    [AccessedThroughProperty("Label22")]
    private Label _Label22;
    [AccessedThroughProperty("MD5OFF")]
    private Label _MD5OFF;
    [AccessedThroughProperty("MD5ON")]
    private Label _MD5ON;
    [AccessedThroughProperty("Label3")]
    private Label _Label3;
    [AccessedThroughProperty("Chart")]
    private Label _Chart;
    [AccessedThroughProperty("Resets")]
    private TextBox _Resets;
    [AccessedThroughProperty("Label23")]
    private Label _Label23;
    [AccessedThroughProperty("Label15")]
    private Label _Label15;
    [AccessedThroughProperty("Reloj")]
    private System.Windows.Forms.Timer timer_0;
    [AccessedThroughProperty("Buscar")]
    private Button _Buscar;
    [AccessedThroughProperty("Minimizar")]
    private Button _Minimizar;
    [AccessedThroughProperty("Cerrar")]
    private Button _Cerrar;
    [AccessedThroughProperty("Titulo")]
    private Label _Titulo;
    [AccessedThroughProperty("BlockACC")]
    private CheckBox _BlockACC;
    private const int int_0 = 132;
    private const int int_1 = 1;
    private const int int_2 = 2;

    internal virtual ComboBox Quests
    {
      [DebuggerNonUserCode] get
      {
        return this._Quests;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Quests = value;
      }
    }

    internal virtual TextBox CreateID
    {
      [DebuggerNonUserCode] get
      {
        return this._CreateID;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._CreateID = value;
      }
    }

    internal virtual Button CreatePj
    {
      [DebuggerNonUserCode] get
      {
        return this._CreatePj;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_49);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_48);
        EventHandler eventHandler = new EventHandler(this.method_37);
        if (this._CreatePj != null)
        {
          this._CreatePj.MouseDown -= mouseEventHandler1;
          this._CreatePj.MouseUp -= mouseEventHandler2;
          this._CreatePj.Click -= eventHandler;
        }
        this._CreatePj = value;
        if (this._CreatePj == null)
          return;
        this._CreatePj.MouseDown += mouseEventHandler1;
        this._CreatePj.MouseUp += mouseEventHandler2;
        this._CreatePj.Click += eventHandler;
      }
    }

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

    internal virtual Button AccountEdit
    {
      [DebuggerNonUserCode] get
      {
        return this._AccountEdit;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_57);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_56);
        EventHandler eventHandler = new EventHandler(this.method_39);
        if (this._AccountEdit != null)
        {
          this._AccountEdit.MouseDown -= mouseEventHandler1;
          this._AccountEdit.MouseUp -= mouseEventHandler2;
          this._AccountEdit.Click -= eventHandler;
        }
        this._AccountEdit = value;
        if (this._AccountEdit == null)
          return;
        this._AccountEdit.MouseDown += mouseEventHandler1;
        this._AccountEdit.MouseUp += mouseEventHandler2;
        this._AccountEdit.Click += eventHandler;
      }
    }

    internal virtual Button BorrarCuenta
    {
      [DebuggerNonUserCode] get
      {
        return this._BorrarCuenta;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_59);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_58);
        EventHandler eventHandler = new EventHandler(this.method_38);
        if (this._BorrarCuenta != null)
        {
          this._BorrarCuenta.MouseDown -= mouseEventHandler1;
          this._BorrarCuenta.MouseUp -= mouseEventHandler2;
          this._BorrarCuenta.Click -= eventHandler;
        }
        this._BorrarCuenta = value;
        if (this._BorrarCuenta == null)
          return;
        this._BorrarCuenta.MouseDown += mouseEventHandler1;
        this._BorrarCuenta.MouseUp += mouseEventHandler2;
        this._BorrarCuenta.Click += eventHandler;
      }
    }

    internal virtual Button ONLineInfo
    {
      [DebuggerNonUserCode] get
      {
        return this._ONLineInfo;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.ONLineInfo_Click);
        if (this._ONLineInfo != null)
          this._ONLineInfo.Click -= eventHandler;
        this._ONLineInfo = value;
        if (this._ONLineInfo == null)
          return;
        this._ONLineInfo.Click += eventHandler;
      }
    }

    internal virtual PictureBox OnlineOFF
    {
      [DebuggerNonUserCode] get
      {
        return this._OnlineOFF;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._OnlineOFF = value;
      }
    }

    internal virtual PictureBox OnlineON
    {
      [DebuggerNonUserCode] get
      {
        return this._OnlineON;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._OnlineON = value;
      }
    }

    internal virtual Label Label18
    {
      [DebuggerNonUserCode] get
      {
        return this._Label18;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label18 = value;
      }
    }

    internal virtual Label Label27
    {
      [DebuggerNonUserCode] get
      {
        return this._Label27;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label27 = value;
      }
    }

    internal virtual Label Label28
    {
      [DebuggerNonUserCode] get
      {
        return this._Label28;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label28 = value;
      }
    }

    internal virtual Label Label26
    {
      [DebuggerNonUserCode] get
      {
        return this._Label26;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label26 = value;
      }
    }

    internal virtual Label Label25
    {
      [DebuggerNonUserCode] get
      {
        return this._Label25;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label25 = value;
      }
    }

    internal virtual Button EditDefault
    {
      [DebuggerNonUserCode] get
      {
        return this._EditDefault;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_55);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_54);
        EventHandler eventHandler = new EventHandler(this.method_36);
        if (this._EditDefault != null)
        {
          this._EditDefault.MouseDown -= mouseEventHandler1;
          this._EditDefault.MouseUp -= mouseEventHandler2;
          this._EditDefault.Click -= eventHandler;
        }
        this._EditDefault = value;
        if (this._EditDefault == null)
          return;
        this._EditDefault.MouseDown += mouseEventHandler1;
        this._EditDefault.MouseUp += mouseEventHandler2;
        this._EditDefault.Click += eventHandler;
      }
    }

    internal virtual Button ResetDefault
    {
      [DebuggerNonUserCode] get
      {
        return this._ResetDefault;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_53);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_52);
        EventHandler eventHandler = new EventHandler(this.method_32);
        if (this._ResetDefault != null)
        {
          this._ResetDefault.MouseDown -= mouseEventHandler1;
          this._ResetDefault.MouseUp -= mouseEventHandler2;
          this._ResetDefault.Click -= eventHandler;
        }
        this._ResetDefault = value;
        if (this._ResetDefault == null)
          return;
        this._ResetDefault.MouseDown += mouseEventHandler1;
        this._ResetDefault.MouseUp += mouseEventHandler2;
        this._ResetDefault.Click += eventHandler;
      }
    }

    internal virtual Button Aplicar
    {
      [DebuggerNonUserCode] get
      {
        return this._Aplicar;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_51);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_50);
        EventHandler eventHandler = new EventHandler(this.method_31);
        if (this._Aplicar != null)
        {
          this._Aplicar.MouseDown -= mouseEventHandler1;
          this._Aplicar.MouseUp -= mouseEventHandler2;
          this._Aplicar.Click -= eventHandler;
        }
        this._Aplicar = value;
        if (this._Aplicar == null)
          return;
        this._Aplicar.MouseDown += mouseEventHandler1;
        this._Aplicar.MouseUp += mouseEventHandler2;
        this._Aplicar.Click += eventHandler;
      }
    }

    internal virtual Button Reload
    {
      [DebuggerNonUserCode] get
      {
        return this._Reload;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_33);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_43);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_42);
        if (this._Reload != null)
        {
          this._Reload.Click -= eventHandler;
          this._Reload.MouseDown -= mouseEventHandler1;
          this._Reload.MouseUp -= mouseEventHandler2;
        }
        this._Reload = value;
        if (this._Reload == null)
          return;
        this._Reload.Click += eventHandler;
        this._Reload.MouseDown += mouseEventHandler1;
        this._Reload.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual Label Label24
    {
      [DebuggerNonUserCode] get
      {
        return this._Label24;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label24 = value;
      }
    }

    internal virtual ComboBox Clases
    {
      [DebuggerNonUserCode] get
      {
        return this._Clases;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Clases_SelectedIndexChanged);
        if (this._Clases != null)
          this._Clases.SelectedIndexChanged -= eventHandler;
        this._Clases = value;
        if (this._Clases == null)
          return;
        this._Clases.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual TextBox PersonalID
    {
      [DebuggerNonUserCode] get
      {
        return this._PersonalID;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PersonalID = value;
      }
    }

    internal virtual TextBox PassWord
    {
      [DebuggerNonUserCode] get
      {
        return this._PassWord;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PassWord = value;
      }
    }

    internal virtual TextBox Email
    {
      [DebuggerNonUserCode] get
      {
        return this._Email;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Email = value;
      }
    }

    internal virtual TextBox CuentaID
    {
      [DebuggerNonUserCode] get
      {
        return this._CuentaID;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._CuentaID = value;
      }
    }

    internal virtual TextBox Frutas
    {
      [DebuggerNonUserCode] get
      {
        return this._Frutas;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_20);
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.method_8);
        if (this._Frutas != null)
        {
          this._Frutas.LostFocus -= eventHandler;
          this._Frutas.KeyPress -= pressEventHandler;
        }
        this._Frutas = value;
        if (this._Frutas == null)
          return;
        this._Frutas.LostFocus += eventHandler;
        this._Frutas.KeyPress += pressEventHandler;
      }
    }

    internal virtual TextBox EditChart
    {
      [DebuggerNonUserCode] get
      {
        return this._EditChart;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._EditChart = value;
      }
    }

    internal virtual TextBox EditAccount
    {
      [DebuggerNonUserCode] get
      {
        return this._EditAccount;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._EditAccount = value;
      }
    }

    internal virtual TextBox PKTime
    {
      [DebuggerNonUserCode] get
      {
        return this._PKTime;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_22);
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.method_10);
        if (this._PKTime != null)
        {
          this._PKTime.LostFocus -= eventHandler;
          this._PKTime.KeyPress -= pressEventHandler;
        }
        this._PKTime = value;
        if (this._PKTime == null)
          return;
        this._PKTime.LostFocus += eventHandler;
        this._PKTime.KeyPress += pressEventHandler;
      }
    }

    internal virtual TextBox PKCount
    {
      [DebuggerNonUserCode] get
      {
        return this._PKCount;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_21);
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.method_9);
        if (this._PKCount != null)
        {
          this._PKCount.LostFocus -= eventHandler;
          this._PKCount.KeyPress -= pressEventHandler;
        }
        this._PKCount = value;
        if (this._PKCount == null)
          return;
        this._PKCount.LostFocus += eventHandler;
        this._PKCount.KeyPress += pressEventHandler;
      }
    }

    internal virtual TextBox Energia
    {
      [DebuggerNonUserCode] get
      {
        return this._Energia;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_18);
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.method_6);
        if (this._Energia != null)
        {
          this._Energia.LostFocus -= eventHandler;
          this._Energia.KeyPress -= pressEventHandler;
        }
        this._Energia = value;
        if (this._Energia == null)
          return;
        this._Energia.LostFocus += eventHandler;
        this._Energia.KeyPress += pressEventHandler;
      }
    }

    internal virtual TextBox Fuerza
    {
      [DebuggerNonUserCode] get
      {
        return this._Fuerza;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_15);
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.method_3);
        if (this._Fuerza != null)
        {
          this._Fuerza.LostFocus -= eventHandler;
          this._Fuerza.KeyPress -= pressEventHandler;
        }
        this._Fuerza = value;
        if (this._Fuerza == null)
          return;
        this._Fuerza.LostFocus += eventHandler;
        this._Fuerza.KeyPress += pressEventHandler;
      }
    }

    internal virtual TextBox Vitalidad
    {
      [DebuggerNonUserCode] get
      {
        return this._Vitalidad;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_17);
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.method_5);
        if (this._Vitalidad != null)
        {
          this._Vitalidad.LostFocus -= eventHandler;
          this._Vitalidad.KeyPress -= pressEventHandler;
        }
        this._Vitalidad = value;
        if (this._Vitalidad == null)
          return;
        this._Vitalidad.LostFocus += eventHandler;
        this._Vitalidad.KeyPress += pressEventHandler;
      }
    }

    internal virtual TextBox Agilidad
    {
      [DebuggerNonUserCode] get
      {
        return this._Agilidad;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_16);
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.method_4);
        if (this._Agilidad != null)
        {
          this._Agilidad.LostFocus -= eventHandler;
          this._Agilidad.KeyPress -= pressEventHandler;
        }
        this._Agilidad = value;
        if (this._Agilidad == null)
          return;
        this._Agilidad.LostFocus += eventHandler;
        this._Agilidad.KeyPress += pressEventHandler;
      }
    }

    internal virtual TextBox Exp
    {
      [DebuggerNonUserCode] get
      {
        return this._Exp;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_14);
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.method_2);
        if (this._Exp != null)
        {
          this._Exp.LostFocus -= eventHandler;
          this._Exp.KeyPress -= pressEventHandler;
        }
        this._Exp = value;
        if (this._Exp == null)
          return;
        this._Exp.LostFocus += eventHandler;
        this._Exp.KeyPress += pressEventHandler;
      }
    }

    internal virtual TextBox Level
    {
      [DebuggerNonUserCode] get
      {
        return this._Level;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_12);
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.method_0);
        if (this._Level != null)
        {
          this._Level.LostFocus -= eventHandler;
          this._Level.KeyPress -= pressEventHandler;
        }
        this._Level = value;
        if (this._Level == null)
          return;
        this._Level.LostFocus += eventHandler;
        this._Level.KeyPress += pressEventHandler;
      }
    }

    internal virtual TextBox Puntos
    {
      [DebuggerNonUserCode] get
      {
        return this._Puntos;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_13);
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.method_1);
        if (this._Puntos != null)
        {
          this._Puntos.LostFocus -= eventHandler;
          this._Puntos.KeyPress -= pressEventHandler;
        }
        this._Puntos = value;
        if (this._Puntos == null)
          return;
        this._Puntos.LostFocus += eventHandler;
        this._Puntos.KeyPress += pressEventHandler;
      }
    }

    internal virtual TextBox Comand
    {
      [DebuggerNonUserCode] get
      {
        return this._Comand;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_19);
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.method_7);
        if (this._Comand != null)
        {
          this._Comand.LostFocus -= eventHandler;
          this._Comand.KeyPress -= pressEventHandler;
        }
        this._Comand = value;
        if (this._Comand == null)
          return;
        this._Comand.LostFocus += eventHandler;
        this._Comand.KeyPress += pressEventHandler;
      }
    }

    internal virtual TextBox PersonajeSearch
    {
      [DebuggerNonUserCode] get
      {
        return this._PersonajeSearch;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.PersonajeSearch_KeyPress);
        if (this._PersonajeSearch != null)
          this._PersonajeSearch.KeyPress -= pressEventHandler;
        this._PersonajeSearch = value;
        if (this._PersonajeSearch == null)
          return;
        this._PersonajeSearch.KeyPress += pressEventHandler;
      }
    }

    internal virtual TextBox CuentaSearch
    {
      [DebuggerNonUserCode] get
      {
        return this._CuentaSearch;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.CuentaSearch_KeyPress);
        if (this._CuentaSearch != null)
          this._CuentaSearch.KeyPress -= pressEventHandler;
        this._CuentaSearch = value;
        if (this._CuentaSearch == null)
          return;
        this._CuentaSearch.KeyPress += pressEventHandler;
      }
    }

    internal virtual TextBox CreatePassWord
    {
      [DebuggerNonUserCode] get
      {
        return this._CreatePassWord;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._CreatePassWord = value;
      }
    }

    internal virtual TextBox CreateEmail
    {
      [DebuggerNonUserCode] get
      {
        return this._CreateEmail;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._CreateEmail = value;
      }
    }

    internal virtual TextBox CreateAccount
    {
      [DebuggerNonUserCode] get
      {
        return this._CreateAccount;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._CreateAccount = value;
      }
    }

    internal virtual Label Label19
    {
      [DebuggerNonUserCode] get
      {
        return this._Label19;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label19 = value;
      }
    }

    internal virtual Label Label20
    {
      [DebuggerNonUserCode] get
      {
        return this._Label20;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label20 = value;
      }
    }

    internal virtual Label Label21
    {
      [DebuggerNonUserCode] get
      {
        return this._Label21;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label21 = value;
      }
    }

    internal virtual ComboBox CtrlCode
    {
      [DebuggerNonUserCode] get
      {
        return this._CtrlCode;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._CtrlCode = value;
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
        EventHandler eventHandler = new EventHandler(this.method_28);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_63);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_62);
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
        EventHandler eventHandler = new EventHandler(this.method_27);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_61);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_60);
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
        EventHandler eventHandler = new EventHandler(this.method_30);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_65);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_64);
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
        EventHandler eventHandler = new EventHandler(this.method_29);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_67);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_66);
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

    internal virtual ComboBox PKLevel
    {
      [DebuggerNonUserCode] get
      {
        return this._PKLevel;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PKLevel = value;
      }
    }

    internal virtual Label Label17
    {
      [DebuggerNonUserCode] get
      {
        return this._Label17;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label17 = value;
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

    internal virtual Label Label16
    {
      [DebuggerNonUserCode] get
      {
        return this._Label16;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label16 = value;
      }
    }

    internal virtual Label Label14
    {
      [DebuggerNonUserCode] get
      {
        return this._Label14;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label14 = value;
      }
    }

    internal virtual Label Label13
    {
      [DebuggerNonUserCode] get
      {
        return this._Label13;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label13 = value;
      }
    }

    internal virtual Label Label12
    {
      [DebuggerNonUserCode] get
      {
        return this._Label12;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label12 = value;
      }
    }

    internal virtual Label Label10
    {
      [DebuggerNonUserCode] get
      {
        return this._Label10;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label10 = value;
      }
    }

    internal virtual Label Label6
    {
      [DebuggerNonUserCode] get
      {
        return this._Label6;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label6 = value;
      }
    }

    internal virtual Label Label7
    {
      [DebuggerNonUserCode] get
      {
        return this._Label7;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label7 = value;
      }
    }

    internal virtual Label Label11
    {
      [DebuggerNonUserCode] get
      {
        return this._Label11;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label11 = value;
      }
    }

    internal virtual Label Label8
    {
      [DebuggerNonUserCode] get
      {
        return this._Label8;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label8 = value;
      }
    }

    internal virtual Label Label9
    {
      [DebuggerNonUserCode] get
      {
        return this._Label9;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label9 = value;
      }
    }

    internal virtual Label Label5
    {
      [DebuggerNonUserCode] get
      {
        return this._Label5;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label5 = value;
      }
    }

    internal virtual Label Label4
    {
      [DebuggerNonUserCode] get
      {
        return this._Label4;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label4 = value;
      }
    }

    internal virtual Button BorrarDatos
    {
      [DebuggerNonUserCode] get
      {
        return this._BorrarDatos;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_24);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_45);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_44);
        if (this._BorrarDatos != null)
        {
          this._BorrarDatos.Click -= eventHandler;
          this._BorrarDatos.MouseDown -= mouseEventHandler1;
          this._BorrarDatos.MouseUp -= mouseEventHandler2;
        }
        this._BorrarDatos = value;
        if (this._BorrarDatos == null)
          return;
        this._BorrarDatos.Click += eventHandler;
        this._BorrarDatos.MouseDown += mouseEventHandler1;
        this._BorrarDatos.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual Button CrearAccount
    {
      [DebuggerNonUserCode] get
      {
        return this._CrearAccount;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_25);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_47);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_46);
        if (this._CrearAccount != null)
        {
          this._CrearAccount.Click -= eventHandler;
          this._CrearAccount.MouseDown -= mouseEventHandler1;
          this._CrearAccount.MouseUp -= mouseEventHandler2;
        }
        this._CrearAccount = value;
        if (this._CrearAccount == null)
          return;
        this._CrearAccount.Click += eventHandler;
        this._CrearAccount.MouseDown += mouseEventHandler1;
        this._CrearAccount.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual Label Label2
    {
      [DebuggerNonUserCode] get
      {
        return this._Label2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label2 = value;
      }
    }

    internal virtual Label Account
    {
      [DebuggerNonUserCode] get
      {
        return this._Account;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Account = value;
      }
    }

    internal virtual ComboBox Personajes
    {
      [DebuggerNonUserCode] get
      {
        return this._Personajes;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Personajes_SelectedIndexChanged);
        if (this._Personajes != null)
          this._Personajes.SelectedIndexChanged -= eventHandler;
        this._Personajes = value;
        if (this._Personajes == null)
          return;
        this._Personajes.SelectedIndexChanged += eventHandler;
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
        EventHandler eventHandler = new EventHandler(this.Cuentas_SelectedIndexChanged);
        if (this._Cuentas != null)
          this._Cuentas.SelectedIndexChanged -= eventHandler;
        this._Cuentas = value;
        if (this._Cuentas == null)
          return;
        this._Cuentas.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual Label Label22
    {
      [DebuggerNonUserCode] get
      {
        return this._Label22;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label22 = value;
      }
    }

    internal virtual Label MD5OFF
    {
      [DebuggerNonUserCode] get
      {
        return this._MD5OFF;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._MD5OFF = value;
      }
    }

    internal virtual Label MD5ON
    {
      [DebuggerNonUserCode] get
      {
        return this._MD5ON;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._MD5ON = value;
      }
    }

    internal virtual Label Label3
    {
      [DebuggerNonUserCode] get
      {
        return this._Label3;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label3 = value;
      }
    }

    internal virtual Label Chart
    {
      [DebuggerNonUserCode] get
      {
        return this._Chart;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Chart = value;
      }
    }

    internal virtual TextBox Resets
    {
      [DebuggerNonUserCode] get
      {
        return this._Resets;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_23);
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.method_11);
        if (this._Resets != null)
        {
          this._Resets.LostFocus -= eventHandler;
          this._Resets.KeyPress -= pressEventHandler;
        }
        this._Resets = value;
        if (this._Resets == null)
          return;
        this._Resets.LostFocus += eventHandler;
        this._Resets.KeyPress += pressEventHandler;
      }
    }

    internal virtual Label Label23
    {
      [DebuggerNonUserCode] get
      {
        return this._Label23;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label23 = value;
      }
    }

    internal virtual Label Label15
    {
      [DebuggerNonUserCode] get
      {
        return this._Label15;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label15 = value;
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

    internal virtual Button Buscar
    {
      [DebuggerNonUserCode] get
      {
        return this._Buscar;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_26);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_41);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_40);
        if (this._Buscar != null)
        {
          this._Buscar.Click -= eventHandler;
          this._Buscar.MouseDown -= mouseEventHandler1;
          this._Buscar.MouseUp -= mouseEventHandler2;
        }
        this._Buscar = value;
        if (this._Buscar == null)
          return;
        this._Buscar.Click += eventHandler;
        this._Buscar.MouseDown += mouseEventHandler1;
        this._Buscar.MouseUp += mouseEventHandler2;
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
        EventHandler eventHandler = new EventHandler(this.method_34);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_69);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_68);
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
        EventHandler eventHandler = new EventHandler(this.method_35);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_71);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_70);
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

    internal virtual Label Titulo
    {
      [DebuggerNonUserCode] get
      {
        return this._Titulo;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Titulo = value;
      }
    }

    internal virtual CheckBox BlockACC
    {
      [DebuggerNonUserCode] get
      {
        return this._BlockACC;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._BlockACC = value;
      }
    }

    public static AccountMaker DefInstance
    {
      get
      {
        if (AccountMaker.accountMaker_0 != null && !AccountMaker.accountMaker_0.IsDisposed)
          AccountMaker.accountMaker_0.BringToFront();
        else
          AccountMaker.accountMaker_0 = new AccountMaker();
        return AccountMaker.accountMaker_0;
      }
      set
      {
        AccountMaker.accountMaker_0 = value;
      }
    }

    [DebuggerNonUserCode]
    public AccountMaker()
    {
      this.Move += new EventHandler(this.AccountMaker_Move);
      this.Closing += new CancelEventHandler(this.AccountMaker_Closing);
      this.Load += new EventHandler(this.AccountMaker_Load);
      this.InitializeComponent();
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
      ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof (AccountMaker));
      this.Quests = new ComboBox();
      this.CreateID = new TextBox();
      this.CreatePj = new Button();
      this.AccountEdit = new Button();
      this.BorrarCuenta = new Button();
      this.ONLineInfo = new Button();
      this.OnlineOFF = new PictureBox();
      this.OnlineON = new PictureBox();
      this.Label18 = new Label();
      this.Label27 = new Label();
      this.Label28 = new Label();
      this.Label26 = new Label();
      this.Label25 = new Label();
      this.EditDefault = new Button();
      this.ResetDefault = new Button();
      this.Aplicar = new Button();
      this.Reload = new Button();
      this.Label24 = new Label();
      this.Clases = new ComboBox();
      this.PersonalID = new TextBox();
      this.PassWord = new TextBox();
      this.Email = new TextBox();
      this.CuentaID = new TextBox();
      this.Frutas = new TextBox();
      this.EditChart = new TextBox();
      this.EditAccount = new TextBox();
      this.PKTime = new TextBox();
      this.ToolTips = new ToolTip(this.icontainer_0);
      this.PKCount = new TextBox();
      this.Energia = new TextBox();
      this.Fuerza = new TextBox();
      this.Vitalidad = new TextBox();
      this.Agilidad = new TextBox();
      this.Exp = new TextBox();
      this.Level = new TextBox();
      this.Puntos = new TextBox();
      this.Comand = new TextBox();
      this.PersonajeSearch = new TextBox();
      this.CuentaSearch = new TextBox();
      this.CreatePassWord = new TextBox();
      this.CreateEmail = new TextBox();
      this.CreateAccount = new TextBox();
      this.Label19 = new Label();
      this.Label20 = new Label();
      this.Label21 = new Label();
      this.CtrlCode = new ComboBox();
      this.BotonSkillMaker = new Button();
      this.BotonItemMaker = new Button();
      this.BotonGuildMaker = new Button();
      this.BotonMoveMaker = new Button();
      this.PKLevel = new ComboBox();
      this.Label17 = new Label();
      this.Label1 = new Label();
      this.Label16 = new Label();
      this.Label14 = new Label();
      this.Label13 = new Label();
      this.Label12 = new Label();
      this.Label10 = new Label();
      this.Label6 = new Label();
      this.Label7 = new Label();
      this.Label11 = new Label();
      this.Label8 = new Label();
      this.Label9 = new Label();
      this.Label5 = new Label();
      this.Label4 = new Label();
      this.BorrarDatos = new Button();
      this.CrearAccount = new Button();
      this.Label2 = new Label();
      this.Account = new Label();
      this.Personajes = new ComboBox();
      this.Cuentas = new ComboBox();
      this.Label22 = new Label();
      this.MD5OFF = new Label();
      this.MD5ON = new Label();
      this.Label3 = new Label();
      this.Chart = new Label();
      this.Resets = new TextBox();
      this.Label23 = new Label();
      this.Label15 = new Label();
      this.Reloj = new System.Windows.Forms.Timer(this.icontainer_0);
      this.Buscar = new Button();
      this.Minimizar = new Button();
      this.Cerrar = new Button();
      this.Titulo = new Label();
      this.BlockACC = new CheckBox();
      ((ISupportInitialize) this.OnlineOFF).BeginInit();
      ((ISupportInitialize) this.OnlineON).BeginInit();
      this.SuspendLayout();
      this.Quests.Cursor = Cursors.Hand;
      this.Quests.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Quests.ImeMode = ImeMode.NoControl;
      this.Quests.ItemHeight = 13;
      ComboBox quests1 = this.Quests;
      Point point1 = new Point(12, 469);
      Point point2 = point1;
      quests1.Location = point2;
      this.Quests.MaxDropDownItems = 10;
      this.Quests.Name = "Quests";
      ComboBox quests2 = this.Quests;
      Size size1 = new Size(210, 21);
      Size size2 = size1;
      quests2.Size = size2;
      this.Quests.TabIndex = 500;
      this.CreateID.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox createId1 = this.CreateID;
      point1 = new Point(174, 78);
      Point point3 = point1;
      createId1.Location = point3;
      this.CreateID.MaxLength = 18;
      this.CreateID.Name = "CreateID";
      TextBox createId2 = this.CreateID;
      size1 = new Size(136, 20);
      Size size3 = size1;
      createId2.Size = size3;
      this.CreateID.TabIndex = 423;
      this.CreateID.Text = "123456789012345678";
      this.CreateID.TextAlign = HorizontalAlignment.Center;
      this.CreatePj.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.CreatePj.BackgroundImage = (Image) EmbeddedResources.smethod_50();
      this.CreatePj.BackgroundImageLayout = ImageLayout.Center;
      this.CreatePj.Cursor = Cursors.Hand;
      this.CreatePj.FlatAppearance.BorderSize = 0;
      this.CreatePj.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.CreatePj.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.CreatePj.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.CreatePj.FlatStyle = FlatStyle.Flat;
      this.CreatePj.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.CreatePj.ForeColor = Color.Transparent;
      Button createPj1 = this.CreatePj;
      point1 = new Point(321, 293);
      Point point4 = point1;
      createPj1.Location = point4;
      this.CreatePj.Name = "CreatePj";
      Button createPj2 = this.CreatePj;
      size1 = new Size(52, 28);
      Size size4 = size1;
      createPj2.Size = size4;
      this.CreatePj.TabIndex = 499;
      this.CreatePj.TabStop = false;
      this.ToolTips.SetToolTip((Control) this.CreatePj, "Aply");
      this.CreatePj.UseVisualStyleBackColor = false;
      this.AccountEdit.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.AccountEdit.BackgroundImage = (Image) EmbeddedResources.smethod_90();
      this.AccountEdit.BackgroundImageLayout = ImageLayout.Center;
      this.AccountEdit.Cursor = Cursors.Hand;
      this.AccountEdit.FlatAppearance.BorderSize = 0;
      this.AccountEdit.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.AccountEdit.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.AccountEdit.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.AccountEdit.FlatStyle = FlatStyle.Flat;
      this.AccountEdit.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.AccountEdit.ForeColor = Color.Transparent;
      Button accountEdit1 = this.AccountEdit;
      point1 = new Point(316, 509);
      Point point5 = point1;
      accountEdit1.Location = point5;
      this.AccountEdit.Name = "AccountEdit";
      Button accountEdit2 = this.AccountEdit;
      size1 = new Size(54, 30);
      Size size5 = size1;
      accountEdit2.Size = size5;
      this.AccountEdit.TabIndex = 498;
      this.AccountEdit.TabStop = false;
      this.ToolTips.SetToolTip((Control) this.AccountEdit, "Aply");
      this.AccountEdit.UseVisualStyleBackColor = false;
      this.BorrarCuenta.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BorrarCuenta.BackgroundImage = (Image) EmbeddedResources.smethod_53();
      this.BorrarCuenta.BackgroundImageLayout = ImageLayout.Center;
      this.BorrarCuenta.Cursor = Cursors.Hand;
      this.BorrarCuenta.FlatAppearance.BorderSize = 0;
      this.BorrarCuenta.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BorrarCuenta.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BorrarCuenta.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BorrarCuenta.FlatStyle = FlatStyle.Flat;
      this.BorrarCuenta.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BorrarCuenta.ForeColor = Color.Transparent;
      Button borrarCuenta1 = this.BorrarCuenta;
      point1 = new Point(317, 553);
      Point point6 = point1;
      borrarCuenta1.Location = point6;
      this.BorrarCuenta.Name = "BorrarCuenta";
      Button borrarCuenta2 = this.BorrarCuenta;
      size1 = new Size(52, 28);
      Size size6 = size1;
      borrarCuenta2.Size = size6;
      this.BorrarCuenta.TabIndex = 497;
      this.BorrarCuenta.TabStop = false;
      this.BorrarCuenta.UseVisualStyleBackColor = false;
      this.ONLineInfo.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.ONLineInfo.BackgroundImage = (Image) EmbeddedResources.smethod_70();
      this.ONLineInfo.BackgroundImageLayout = ImageLayout.Center;
      this.ONLineInfo.Cursor = Cursors.Hand;
      this.ONLineInfo.FlatAppearance.BorderSize = 0;
      this.ONLineInfo.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.ONLineInfo.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.ONLineInfo.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.ONLineInfo.FlatStyle = FlatStyle.Flat;
      this.ONLineInfo.Font = new Font("Verdana", 7f, FontStyle.Bold);
      this.ONLineInfo.ForeColor = Color.Transparent;
      this.ONLineInfo.ImeMode = ImeMode.NoControl;
      Button onLineInfo1 = this.ONLineInfo;
      point1 = new Point(233, 294);
      Point point7 = point1;
      onLineInfo1.Location = point7;
      this.ONLineInfo.Name = "ONLineInfo";
      Button onLineInfo2 = this.ONLineInfo;
      size1 = new Size(16, 16);
      Size size7 = size1;
      onLineInfo2.Size = size7;
      this.ONLineInfo.TabIndex = 493;
      this.ONLineInfo.TabStop = false;
      this.ONLineInfo.TextAlign = ContentAlignment.TopLeft;
      this.ONLineInfo.UseVisualStyleBackColor = false;
      this.OnlineOFF.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.OnlineOFF.Image = (Image) EmbeddedResources.smethod_89();
      PictureBox onlineOff1 = this.OnlineOFF;
      point1 = new Point(294, 295);
      Point point8 = point1;
      onlineOff1.Location = point8;
      this.OnlineOFF.Name = "OnlineOFF";
      PictureBox onlineOff2 = this.OnlineOFF;
      size1 = new Size(14, 14);
      Size size8 = size1;
      onlineOff2.Size = size8;
      this.OnlineOFF.TabIndex = 492;
      this.OnlineOFF.TabStop = false;
      this.OnlineON.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.OnlineON.Image = (Image) EmbeddedResources.smethod_92();
      PictureBox onlineOn1 = this.OnlineON;
      point1 = new Point(294, 295);
      Point point9 = point1;
      onlineOn1.Location = point9;
      this.OnlineON.Name = "OnlineON";
      PictureBox onlineOn2 = this.OnlineON;
      size1 = new Size(14, 14);
      Size size9 = size1;
      onlineOn2.Size = size9;
      this.OnlineON.TabIndex = 491;
      this.OnlineON.TabStop = false;
      this.OnlineON.Visible = false;
      this.Label18.AutoSize = true;
      this.Label18.BackColor = Color.Transparent;
      this.Label18.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label18.ForeColor = Color.DimGray;
      Label label18_1 = this.Label18;
      point1 = new Point(250, 295);
      Point point10 = point1;
      label18_1.Location = point10;
      this.Label18.Name = "Label18";
      Label label18_2 = this.Label18;
      size1 = new Size(43, 13);
      Size size10 = size1;
      label18_2.Size = size10;
      this.Label18.TabIndex = 490;
      this.Label18.Text = "Online";
      Label label27_1 = this.Label27;
      point1 = new Point(115, 186);
      Point point11 = point1;
      label27_1.Location = point11;
      this.Label27.Name = "Label27";
      Label label27_2 = this.Label27;
      size1 = new Size(2, 68);
      Size size11 = size1;
      label27_2.Size = size11;
      this.Label27.TabIndex = 487;
      this.Label27.Text = "Label27";
      Label label28_1 = this.Label28;
      point1 = new Point(261, 186);
      Point point12 = point1;
      label28_1.Location = point12;
      this.Label28.Name = "Label28";
      Label label28_2 = this.Label28;
      size1 = new Size(4, 68);
      Size size12 = size1;
      label28_2.Size = size12;
      this.Label28.TabIndex = 488;
      this.Label28.Text = "Label28";
      Label label26_1 = this.Label26;
      point1 = new Point(117, 230);
      Point point13 = point1;
      label26_1.Location = point13;
      this.Label26.Name = "Label26";
      Label label26_2 = this.Label26;
      size1 = new Size(146, 2);
      Size size13 = size1;
      label26_2.Size = size13;
      this.Label26.TabIndex = 486;
      this.Label26.Text = "Label26";
      Label label25_1 = this.Label25;
      point1 = new Point(117, 252);
      Point point14 = point1;
      label25_1.Location = point14;
      this.Label25.Name = "Label25";
      Label label25_2 = this.Label25;
      size1 = new Size(146, 2);
      Size size14 = size1;
      label25_2.Size = size14;
      this.Label25.TabIndex = 485;
      this.Label25.Text = "Label25";
      this.EditDefault.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.EditDefault.BackgroundImage = (Image) EmbeddedResources.smethod_14();
      this.EditDefault.BackgroundImageLayout = ImageLayout.Center;
      this.EditDefault.Cursor = Cursors.Hand;
      this.EditDefault.FlatAppearance.BorderSize = 0;
      this.EditDefault.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.EditDefault.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.EditDefault.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.EditDefault.FlatStyle = FlatStyle.Flat;
      this.EditDefault.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.EditDefault.ForeColor = Color.Transparent;
      Button editDefault1 = this.EditDefault;
      point1 = new Point(273, 262);
      Point point15 = point1;
      editDefault1.Location = point15;
      this.EditDefault.Name = "EditDefault";
      Button editDefault2 = this.EditDefault;
      size1 = new Size(34, 27);
      Size size15 = size1;
      editDefault2.Size = size15;
      this.EditDefault.TabIndex = 484;
      this.EditDefault.TabStop = false;
      this.ToolTips.SetToolTip((Control) this.EditDefault, "Edit Default");
      this.EditDefault.UseVisualStyleBackColor = false;
      this.ResetDefault.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.ResetDefault.BackgroundImage = (Image) EmbeddedResources.smethod_117();
      this.ResetDefault.BackgroundImageLayout = ImageLayout.Center;
      this.ResetDefault.Cursor = Cursors.Hand;
      this.ResetDefault.FlatAppearance.BorderSize = 0;
      this.ResetDefault.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.ResetDefault.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.ResetDefault.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.ResetDefault.FlatStyle = FlatStyle.Flat;
      this.ResetDefault.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.ResetDefault.ForeColor = Color.Transparent;
      Button resetDefault1 = this.ResetDefault;
      point1 = new Point(233, 263);
      Point point16 = point1;
      resetDefault1.Location = point16;
      this.ResetDefault.Name = "ResetDefault";
      Button resetDefault2 = this.ResetDefault;
      size1 = new Size(32, 25);
      Size size16 = size1;
      resetDefault2.Size = size16;
      this.ResetDefault.TabIndex = 470;
      this.ResetDefault.TabStop = false;
      this.ToolTips.SetToolTip((Control) this.ResetDefault, "Reset / Default");
      this.ResetDefault.UseVisualStyleBackColor = false;
      this.Aplicar.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Aplicar.BackgroundImage = (Image) EmbeddedResources.smethod_90();
      this.Aplicar.BackgroundImageLayout = ImageLayout.Center;
      this.Aplicar.Cursor = Cursors.Hand;
      this.Aplicar.FlatAppearance.BorderSize = 0;
      this.Aplicar.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.Aplicar.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.Aplicar.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.Aplicar.FlatStyle = FlatStyle.Flat;
      this.Aplicar.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Aplicar.ForeColor = Color.Transparent;
      Button aplicar1 = this.Aplicar;
      point1 = new Point(317, 263);
      Point point17 = point1;
      aplicar1.Location = point17;
      this.Aplicar.Name = "Aplicar";
      Button aplicar2 = this.Aplicar;
      size1 = new Size(54, 30);
      Size size17 = size1;
      aplicar2.Size = size17;
      this.Aplicar.TabIndex = 463;
      this.Aplicar.TabStop = false;
      this.ToolTips.SetToolTip((Control) this.Aplicar, "Aply");
      this.Aplicar.UseVisualStyleBackColor = false;
      this.Reload.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Reload.BackgroundImage = (Image) EmbeddedResources.smethod_100();
      this.Reload.BackgroundImageLayout = ImageLayout.Center;
      this.Reload.Cursor = Cursors.Hand;
      this.Reload.FlatAppearance.BorderSize = 0;
      this.Reload.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.Reload.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.Reload.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.Reload.FlatStyle = FlatStyle.Flat;
      this.Reload.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Reload.ForeColor = Color.Transparent;
      Button reload1 = this.Reload;
      point1 = new Point(331, 327);
      Point point18 = point1;
      reload1.Location = point18;
      this.Reload.Name = "Reload";
      Button reload2 = this.Reload;
      size1 = new Size(40, 31);
      Size size18 = size1;
      reload2.Size = size18;
      this.Reload.TabIndex = 483;
      this.Reload.TabStop = false;
      this.ToolTips.SetToolTip((Control) this.Reload, "Reload Info");
      this.Reload.UseVisualStyleBackColor = false;
      this.Label24.BackColor = Color.Transparent;
      this.Label24.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label24.ForeColor = Color.DimGray;
      Label label24_1 = this.Label24;
      point1 = new Point(180, 64);
      Point point19 = point1;
      label24_1.Location = point19;
      this.Label24.Name = "Label24";
      Label label24_2 = this.Label24;
      size1 = new Size(66, 16);
      Size size19 = size1;
      label24_2.Size = size19;
      this.Label24.TabIndex = 482;
      this.Label24.Text = "Personal ID";
      this.Label24.TextAlign = ContentAlignment.MiddleCenter;
      this.Clases.BackColor = Color.Black;
      this.Clases.Cursor = Cursors.Hand;
      this.Clases.DropDownWidth = 8;
      this.Clases.Font = new Font("Microsoft Sans Serif", 10f, FontStyle.Bold);
      this.Clases.ForeColor = Color.DarkGoldenrod;
      this.Clases.ItemHeight = 16;
      ComboBox clases1 = this.Clases;
      point1 = new Point(115, 230);
      Point point20 = point1;
      clases1.Location = point20;
      this.Clases.MaxDropDownItems = 10;
      this.Clases.Name = "Clases";
      ComboBox clases2 = this.Clases;
      size1 = new Size(148, 24);
      Size size20 = size1;
      clases2.Size = size20;
      this.Clases.TabIndex = 480;
      this.PersonalID.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox personalId1 = this.PersonalID;
      point1 = new Point(163, 559);
      Point point21 = point1;
      personalId1.Location = point21;
      this.PersonalID.MaxLength = 18;
      this.PersonalID.Name = "PersonalID";
      TextBox personalId2 = this.PersonalID;
      size1 = new Size(142, 20);
      Size size21 = size1;
      personalId2.Size = size21;
      this.PersonalID.TabIndex = 475;
      this.PersonalID.TabStop = false;
      this.PersonalID.TextAlign = HorizontalAlignment.Center;
      this.PassWord.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox passWord1 = this.PassWord;
      point1 = new Point(163, 520);
      Point point22 = point1;
      passWord1.Location = point22;
      this.PassWord.MaxLength = 10;
      this.PassWord.Name = "PassWord";
      TextBox passWord2 = this.PassWord;
      size1 = new Size(142, 20);
      Size size22 = size1;
      passWord2.Size = size22;
      this.PassWord.TabIndex = 474;
      this.PassWord.TabStop = false;
      this.PassWord.TextAlign = HorizontalAlignment.Center;
      this.Email.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox email1 = this.Email;
      point1 = new Point(12, 559);
      Point point23 = point1;
      email1.Location = point23;
      this.Email.MaxLength = 50;
      this.Email.Name = "Email";
      TextBox email2 = this.Email;
      size1 = new Size(142, 20);
      Size size23 = size1;
      email2.Size = size23;
      this.Email.TabIndex = 473;
      this.Email.TabStop = false;
      this.Email.TextAlign = HorizontalAlignment.Center;
      this.CuentaID.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox cuentaId1 = this.CuentaID;
      point1 = new Point(12, 520);
      Point point24 = point1;
      cuentaId1.Location = point24;
      this.CuentaID.MaxLength = 10;
      this.CuentaID.Name = "CuentaID";
      TextBox cuentaId2 = this.CuentaID;
      size1 = new Size(142, 20);
      Size size24 = size1;
      cuentaId2.Size = size24;
      this.CuentaID.TabIndex = 472;
      this.CuentaID.TabStop = false;
      this.CuentaID.TextAlign = HorizontalAlignment.Center;
      this.Frutas.BackColor = Color.White;
      this.Frutas.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Frutas.ForeColor = Color.Black;
      TextBox frutas1 = this.Frutas;
      point1 = new Point(82, 443);
      Point point25 = point1;
      frutas1.Location = point25;
      this.Frutas.MaxLength = 4;
      this.Frutas.Name = "Frutas";
      TextBox frutas2 = this.Frutas;
      size1 = new Size(140, 20);
      Size size25 = size1;
      frutas2.Size = size25;
      this.Frutas.TabIndex = 432;
      this.EditChart.BackColor = Color.Black;
      this.EditChart.BorderStyle = BorderStyle.None;
      this.EditChart.Cursor = Cursors.Default;
      this.EditChart.Font = new Font("Microsoft Sans Serif", 14f, FontStyle.Regular, GraphicsUnit.Point, (byte) 0);
      this.EditChart.ForeColor = Color.Red;
      TextBox editChart1 = this.EditChart;
      point1 = new Point(116, 208);
      Point point26 = point1;
      editChart1.Location = point26;
      this.EditChart.Name = "EditChart";
      this.EditChart.ReadOnly = true;
      TextBox editChart2 = this.EditChart;
      size1 = new Size(145, 22);
      Size size26 = size1;
      editChart2.Size = size26;
      this.EditChart.TabIndex = 469;
      this.EditChart.TabStop = false;
      this.EditChart.TextAlign = HorizontalAlignment.Center;
      this.EditAccount.BackColor = Color.Black;
      this.EditAccount.BorderStyle = BorderStyle.None;
      this.EditAccount.Cursor = Cursors.Default;
      this.EditAccount.Font = new Font("Microsoft Sans Serif", 14f, FontStyle.Regular, GraphicsUnit.Point, (byte) 0);
      this.EditAccount.ForeColor = Color.Red;
      TextBox editAccount1 = this.EditAccount;
      point1 = new Point(116, 186);
      Point point27 = point1;
      editAccount1.Location = point27;
      this.EditAccount.Name = "EditAccount";
      this.EditAccount.ReadOnly = true;
      TextBox editAccount2 = this.EditAccount;
      size1 = new Size(145, 22);
      Size size27 = size1;
      editAccount2.Size = size27;
      this.EditAccount.TabIndex = 468;
      this.EditAccount.TabStop = false;
      this.EditAccount.TextAlign = HorizontalAlignment.Center;
      this.PKTime.BackColor = Color.White;
      this.PKTime.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.PKTime.ForeColor = Color.Black;
      TextBox pkTime1 = this.PKTime;
      point1 = new Point(286, 443);
      Point point28 = point1;
      pkTime1.Location = point28;
      this.PKTime.MaxLength = 6;
      this.PKTime.Name = "PKTime";
      TextBox pkTime2 = this.PKTime;
      size1 = new Size(86, 20);
      Size size28 = size1;
      pkTime2.Size = size28;
      this.PKTime.TabIndex = 436;
      this.PKCount.BackColor = Color.White;
      this.PKCount.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.PKCount.ForeColor = Color.Black;
      TextBox pkCount1 = this.PKCount;
      point1 = new Point(286, 421);
      Point point29 = point1;
      pkCount1.Location = point29;
      this.PKCount.MaxLength = 4;
      this.PKCount.Name = "PKCount";
      TextBox pkCount2 = this.PKCount;
      size1 = new Size(86, 20);
      Size size29 = size1;
      pkCount2.Size = size29;
      this.PKCount.TabIndex = 435;
      this.Energia.BackColor = Color.White;
      this.Energia.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Energia.ForeColor = Color.Black;
      TextBox energia1 = this.Energia;
      point1 = new Point(82, 399);
      Point point30 = point1;
      energia1.Location = point30;
      this.Energia.MaxLength = 6;
      this.Energia.Name = "Energia";
      TextBox energia2 = this.Energia;
      size1 = new Size(140, 20);
      Size size30 = size1;
      energia2.Size = size30;
      this.Energia.TabIndex = 430;
      this.Fuerza.BackColor = Color.White;
      this.Fuerza.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Fuerza.ForeColor = Color.Black;
      TextBox fuerza1 = this.Fuerza;
      point1 = new Point(82, 333);
      Point point31 = point1;
      fuerza1.Location = point31;
      this.Fuerza.MaxLength = 6;
      this.Fuerza.Name = "Fuerza";
      TextBox fuerza2 = this.Fuerza;
      size1 = new Size(140, 20);
      Size size31 = size1;
      fuerza2.Size = size31;
      this.Fuerza.TabIndex = 427;
      this.Vitalidad.BackColor = Color.White;
      this.Vitalidad.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Vitalidad.ForeColor = Color.Black;
      TextBox vitalidad1 = this.Vitalidad;
      point1 = new Point(82, 377);
      Point point32 = point1;
      vitalidad1.Location = point32;
      this.Vitalidad.MaxLength = 6;
      this.Vitalidad.Name = "Vitalidad";
      TextBox vitalidad2 = this.Vitalidad;
      size1 = new Size(140, 20);
      Size size32 = size1;
      vitalidad2.Size = size32;
      this.Vitalidad.TabIndex = 429;
      this.Agilidad.BackColor = Color.White;
      this.Agilidad.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Agilidad.ForeColor = Color.Black;
      TextBox agilidad1 = this.Agilidad;
      point1 = new Point(82, 355);
      Point point33 = point1;
      agilidad1.Location = point33;
      this.Agilidad.MaxLength = 6;
      this.Agilidad.Name = "Agilidad";
      TextBox agilidad2 = this.Agilidad;
      size1 = new Size(140, 20);
      Size size33 = size1;
      agilidad2.Size = size33;
      this.Agilidad.TabIndex = 428;
      this.Exp.BackColor = Color.White;
      this.Exp.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Exp.ForeColor = Color.Black;
      TextBox exp1 = this.Exp;
      point1 = new Point(82, 311);
      Point point34 = point1;
      exp1.Location = point34;
      this.Exp.MaxLength = 16;
      this.Exp.Name = "Exp";
      TextBox exp2 = this.Exp;
      size1 = new Size(140, 20);
      Size size34 = size1;
      exp2.Size = size34;
      this.Exp.TabIndex = 426;
      this.Level.BackColor = Color.White;
      this.Level.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Level.ForeColor = Color.Black;
      TextBox level1 = this.Level;
      point1 = new Point(82, 267);
      Point point35 = point1;
      level1.Location = point35;
      this.Level.MaxLength = 5;
      this.Level.Name = "Level";
      TextBox level2 = this.Level;
      size1 = new Size(140, 20);
      Size size35 = size1;
      level2.Size = size35;
      this.Level.TabIndex = 424;
      this.Puntos.BackColor = Color.White;
      this.Puntos.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Puntos.ForeColor = Color.Black;
      TextBox puntos1 = this.Puntos;
      point1 = new Point(82, 289);
      Point point36 = point1;
      puntos1.Location = point36;
      this.Puntos.MaxLength = 4;
      this.Puntos.Name = "Puntos";
      TextBox puntos2 = this.Puntos;
      size1 = new Size(140, 20);
      Size size36 = size1;
      puntos2.Size = size36;
      this.Puntos.TabIndex = 425;
      this.Comand.BackColor = Color.White;
      this.Comand.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Comand.ForeColor = Color.Black;
      TextBox comand1 = this.Comand;
      point1 = new Point(82, 421);
      Point point37 = point1;
      comand1.Location = point37;
      this.Comand.MaxLength = 6;
      this.Comand.Name = "Comand";
      TextBox comand2 = this.Comand;
      size1 = new Size(140, 20);
      Size size37 = size1;
      comand2.Size = size37;
      this.Comand.TabIndex = 431;
      this.PersonajeSearch.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox personajeSearch1 = this.PersonajeSearch;
      point1 = new Point(208, 130);
      Point point38 = point1;
      personajeSearch1.Location = point38;
      this.PersonajeSearch.MaxLength = 32;
      this.PersonajeSearch.Name = "PersonajeSearch";
      TextBox personajeSearch2 = this.PersonajeSearch;
      size1 = new Size(160, 20);
      Size size38 = size1;
      personajeSearch2.Size = size38;
      this.PersonajeSearch.TabIndex = 440;
      this.PersonajeSearch.TextAlign = HorizontalAlignment.Center;
      this.CuentaSearch.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox cuentaSearch1 = this.CuentaSearch;
      point1 = new Point(8, 130);
      Point point39 = point1;
      cuentaSearch1.Location = point39;
      this.CuentaSearch.MaxLength = 32;
      this.CuentaSearch.Name = "CuentaSearch";
      TextBox cuentaSearch2 = this.CuentaSearch;
      size1 = new Size(160, 20);
      Size size39 = size1;
      cuentaSearch2.Size = size39;
      this.CuentaSearch.TabIndex = 439;
      this.CuentaSearch.TextAlign = HorizontalAlignment.Center;
      this.CreatePassWord.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox createPassWord1 = this.CreatePassWord;
      point1 = new Point(174, 42);
      Point point40 = point1;
      createPassWord1.Location = point40;
      this.CreatePassWord.MaxLength = 10;
      this.CreatePassWord.Name = "CreatePassWord";
      TextBox createPassWord2 = this.CreatePassWord;
      size1 = new Size(136, 20);
      Size size40 = size1;
      createPassWord2.Size = size40;
      this.CreatePassWord.TabIndex = 421;
      this.CreatePassWord.TextAlign = HorizontalAlignment.Center;
      this.CreateEmail.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox createEmail1 = this.CreateEmail;
      point1 = new Point(12, 78);
      Point point41 = point1;
      createEmail1.Location = point41;
      this.CreateEmail.MaxLength = 50;
      this.CreateEmail.Name = "CreateEmail";
      TextBox createEmail2 = this.CreateEmail;
      size1 = new Size(160, 20);
      Size size41 = size1;
      createEmail2.Size = size41;
      this.CreateEmail.TabIndex = 422;
      this.CreateEmail.TextAlign = HorizontalAlignment.Center;
      this.CreateAccount.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox createAccount1 = this.CreateAccount;
      point1 = new Point(52, 42);
      Point point42 = point1;
      createAccount1.Location = point42;
      this.CreateAccount.MaxLength = 10;
      this.CreateAccount.Name = "CreateAccount";
      TextBox createAccount2 = this.CreateAccount;
      size1 = new Size(120, 20);
      Size size42 = size1;
      createAccount2.Size = size42;
      this.CreateAccount.TabIndex = 420;
      this.CreateAccount.TextAlign = HorizontalAlignment.Center;
      this.Label19.BackColor = Color.Transparent;
      this.Label19.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label19.ForeColor = Color.DimGray;
      Label label19_1 = this.Label19;
      point1 = new Point(196, 502);
      Point point43 = point1;
      label19_1.Location = point43;
      this.Label19.Name = "Label19";
      Label label19_2 = this.Label19;
      size1 = new Size(112, 16);
      Size size43 = size1;
      label19_2.Size = size43;
      this.Label19.TabIndex = 479;
      this.Label19.Text = "PassWord";
      this.Label19.TextAlign = ContentAlignment.MiddleCenter;
      this.Label20.BackColor = Color.Transparent;
      this.Label20.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label20.ForeColor = Color.DimGray;
      Label label20_1 = this.Label20;
      point1 = new Point(155, 542);
      Point point44 = point1;
      label20_1.Location = point44;
      this.Label20.Name = "Label20";
      Label label20_2 = this.Label20;
      size1 = new Size(110, 16);
      Size size44 = size1;
      label20_2.Size = size44;
      this.Label20.TabIndex = 478;
      this.Label20.Text = "Personal ID";
      this.Label20.TextAlign = ContentAlignment.MiddleCenter;
      this.Label21.BackColor = Color.Transparent;
      this.Label21.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label21.ForeColor = Color.DimGray;
      Label label21_1 = this.Label21;
      point1 = new Point(28, 542);
      Point point45 = point1;
      label21_1.Location = point45;
      this.Label21.Name = "Label21";
      Label label21_2 = this.Label21;
      size1 = new Size(112, 16);
      Size size45 = size1;
      label21_2.Size = size45;
      this.Label21.TabIndex = 477;
      this.Label21.Text = "E-Mail";
      this.Label21.TextAlign = ContentAlignment.MiddleCenter;
      this.CtrlCode.Cursor = Cursors.Hand;
      this.CtrlCode.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.CtrlCode.ItemHeight = 13;
      ComboBox ctrlCode1 = this.CtrlCode;
      point1 = new Point(226, 469);
      Point point46 = point1;
      ctrlCode1.Location = point46;
      this.CtrlCode.MaxDropDownItems = 10;
      this.CtrlCode.Name = "CtrlCode";
      ComboBox ctrlCode2 = this.CtrlCode;
      size1 = new Size(140, 21);
      Size size46 = size1;
      ctrlCode2.Size = size46;
      this.CtrlCode.TabIndex = 433;
      this.BotonSkillMaker.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonSkillMaker.BackgroundImage = (Image) EmbeddedResources.smethod_29();
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
      point1 = new Point(7, 223);
      Point point47 = point1;
      botonSkillMaker1.Location = point47;
      this.BotonSkillMaker.Name = "BotonSkillMaker";
      Button botonSkillMaker2 = this.BotonSkillMaker;
      size1 = new Size(106, 24);
      Size size47 = size1;
      botonSkillMaker2.Size = size47;
      this.BotonSkillMaker.TabIndex = 467;
      this.BotonSkillMaker.TabStop = false;
      this.BotonSkillMaker.UseVisualStyleBackColor = false;
      this.BotonItemMaker.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonItemMaker.BackgroundImage = (Image) EmbeddedResources.smethod_20();
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
      point1 = new Point(7, 192);
      Point point48 = point1;
      botonItemMaker1.Location = point48;
      this.BotonItemMaker.Name = "BotonItemMaker";
      Button botonItemMaker2 = this.BotonItemMaker;
      size1 = new Size(106, 24);
      Size size48 = size1;
      botonItemMaker2.Size = size48;
      this.BotonItemMaker.TabIndex = 466;
      this.BotonItemMaker.TabStop = false;
      this.BotonItemMaker.UseVisualStyleBackColor = false;
      this.BotonGuildMaker.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonGuildMaker.BackgroundImage = (Image) EmbeddedResources.smethod_18();
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
      point1 = new Point(264, 193);
      Point point49 = point1;
      botonGuildMaker1.Location = point49;
      this.BotonGuildMaker.Name = "BotonGuildMaker";
      Button botonGuildMaker2 = this.BotonGuildMaker;
      size1 = new Size(106, 24);
      Size size49 = size1;
      botonGuildMaker2.Size = size49;
      this.BotonGuildMaker.TabIndex = 465;
      this.BotonGuildMaker.TabStop = false;
      this.BotonGuildMaker.UseVisualStyleBackColor = false;
      this.BotonMoveMaker.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonMoveMaker.BackgroundImage = (Image) EmbeddedResources.smethod_24();
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
      point1 = new Point(264, 223);
      Point point50 = point1;
      botonMoveMaker1.Location = point50;
      this.BotonMoveMaker.Name = "BotonMoveMaker";
      Button botonMoveMaker2 = this.BotonMoveMaker;
      size1 = new Size(106, 24);
      Size size50 = size1;
      botonMoveMaker2.Size = size50;
      this.BotonMoveMaker.TabIndex = 464;
      this.BotonMoveMaker.TabStop = false;
      this.BotonMoveMaker.UseVisualStyleBackColor = false;
      this.PKLevel.Cursor = Cursors.Hand;
      this.PKLevel.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.PKLevel.ItemHeight = 13;
      ComboBox pkLevel1 = this.PKLevel;
      point1 = new Point(268, 398);
      Point point51 = point1;
      pkLevel1.Location = point51;
      this.PKLevel.MaxDropDownItems = 10;
      this.PKLevel.Name = "PKLevel";
      ComboBox pkLevel2 = this.PKLevel;
      size1 = new Size(104, 21);
      Size size51 = size1;
      pkLevel2.Size = size51;
      this.PKLevel.TabIndex = 434;
      this.Label17.AutoSize = true;
      this.Label17.BackColor = Color.Transparent;
      this.Label17.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label17.ForeColor = Color.DimGray;
      Label label17_1 = this.Label17;
      point1 = new Point(223, 403);
      Point point52 = point1;
      label17_1.Location = point52;
      this.Label17.Name = "Label17";
      Label label17_2 = this.Label17;
      size1 = new Size(48, 13);
      Size size52 = size1;
      label17_2.Size = size52;
      this.Label17.TabIndex = 462;
      this.Label17.Text = "PK lvl :";
      this.Label17.TextAlign = ContentAlignment.MiddleLeft;
      this.Label1.AutoSize = true;
      this.Label1.BackColor = Color.Transparent;
      this.Label1.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label1.ForeColor = Color.DimGray;
      Label label1_1 = this.Label1;
      point1 = new Point(224, 425);
      Point point53 = point1;
      label1_1.Location = point53;
      this.Label1.Name = "Label1";
      Label label1_2 = this.Label1;
      size1 = new Size(54, 13);
      Size size53 = size1;
      label1_2.Size = size53;
      this.Label1.TabIndex = 461;
      this.Label1.Text = "PK Cnt :";
      this.Label1.TextAlign = ContentAlignment.MiddleLeft;
      this.Label16.AutoSize = true;
      this.Label16.BackColor = Color.Transparent;
      this.Label16.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label16.ForeColor = Color.DimGray;
      Label label16_1 = this.Label16;
      point1 = new Point(224, 447);
      Point point54 = point1;
      label16_1.Location = point54;
      this.Label16.Name = "Label16";
      Label label16_2 = this.Label16;
      size1 = new Size(62, 13);
      Size size54 = size1;
      label16_2.Size = size54;
      this.Label16.TabIndex = 460;
      this.Label16.Text = "PK Time :";
      this.Label16.TextAlign = ContentAlignment.MiddleLeft;
      this.Label14.BackColor = Color.Transparent;
      this.Label14.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label14.ForeColor = Color.DimGray;
      Label label14_1 = this.Label14;
      point1 = new Point(12, 445);
      Point point55 = point1;
      label14_1.Location = point55;
      this.Label14.Name = "Label14";
      Label label14_2 = this.Label14;
      size1 = new Size(70, 16);
      Size size55 = size1;
      label14_2.Size = size55;
      this.Label14.TabIndex = 458;
      this.Label14.Text = "Fruit Point :";
      this.Label14.TextAlign = ContentAlignment.MiddleLeft;
      this.Label13.BackColor = Color.Transparent;
      this.Label13.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label13.ForeColor = Color.DimGray;
      Label label13_1 = this.Label13;
      point1 = new Point(12, 423);
      Point point56 = point1;
      label13_1.Location = point56;
      this.Label13.Name = "Label13";
      Label label13_2 = this.Label13;
      size1 = new Size(70, 16);
      Size size56 = size1;
      label13_2.Size = size56;
      this.Label13.TabIndex = 457;
      this.Label13.Text = "Command :";
      this.Label13.TextAlign = ContentAlignment.MiddleLeft;
      this.Label12.BackColor = Color.Transparent;
      this.Label12.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label12.ForeColor = Color.DimGray;
      Label label12_1 = this.Label12;
      point1 = new Point(12, 401);
      Point point57 = point1;
      label12_1.Location = point57;
      this.Label12.Name = "Label12";
      Label label12_2 = this.Label12;
      size1 = new Size(70, 16);
      Size size57 = size1;
      label12_2.Size = size57;
      this.Label12.TabIndex = 456;
      this.Label12.Text = "Energy :";
      this.Label12.TextAlign = ContentAlignment.MiddleLeft;
      this.Label10.BackColor = Color.Transparent;
      this.Label10.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label10.ForeColor = Color.DimGray;
      Label label10_1 = this.Label10;
      point1 = new Point(12, 291);
      Point point58 = point1;
      label10_1.Location = point58;
      this.Label10.Name = "Label10";
      Label label10_2 = this.Label10;
      size1 = new Size(70, 16);
      Size size58 = size1;
      label10_2.Size = size58;
      this.Label10.TabIndex = 454;
      this.Label10.Text = "Points :";
      this.Label10.TextAlign = ContentAlignment.MiddleLeft;
      this.Label6.BackColor = Color.Transparent;
      this.Label6.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label6.ForeColor = Color.DimGray;
      Label label6_1 = this.Label6;
      point1 = new Point(12, 269);
      Point point59 = point1;
      label6_1.Location = point59;
      this.Label6.Name = "Label6";
      Label label6_2 = this.Label6;
      size1 = new Size(70, 16);
      Size size59 = size1;
      label6_2.Size = size59;
      this.Label6.TabIndex = 450;
      this.Label6.Text = "Level :";
      this.Label6.TextAlign = ContentAlignment.MiddleLeft;
      this.Label7.BackColor = Color.Transparent;
      this.Label7.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label7.ForeColor = Color.DimGray;
      Label label7_1 = this.Label7;
      point1 = new Point(12, 357);
      Point point60 = point1;
      label7_1.Location = point60;
      this.Label7.Name = "Label7";
      Label label7_2 = this.Label7;
      size1 = new Size(70, 16);
      Size size60 = size1;
      label7_2.Size = size60;
      this.Label7.TabIndex = 451;
      this.Label7.Text = "Agility :";
      this.Label7.TextAlign = ContentAlignment.MiddleLeft;
      this.Label11.BackColor = Color.Transparent;
      this.Label11.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label11.ForeColor = Color.DimGray;
      Label label11_1 = this.Label11;
      point1 = new Point(12, 379);
      Point point61 = point1;
      label11_1.Location = point61;
      this.Label11.Name = "Label11";
      Label label11_2 = this.Label11;
      size1 = new Size(70, 16);
      Size size61 = size1;
      label11_2.Size = size61;
      this.Label11.TabIndex = 455;
      this.Label11.Text = "Vitality :";
      this.Label11.TextAlign = ContentAlignment.MiddleLeft;
      this.Label8.BackColor = Color.Transparent;
      this.Label8.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label8.ForeColor = Color.DimGray;
      Label label8_1 = this.Label8;
      point1 = new Point(12, 335);
      Point point62 = point1;
      label8_1.Location = point62;
      this.Label8.Name = "Label8";
      Label label8_2 = this.Label8;
      size1 = new Size(70, 16);
      Size size62 = size1;
      label8_2.Size = size62;
      this.Label8.TabIndex = 452;
      this.Label8.Text = "Strength :";
      this.Label8.TextAlign = ContentAlignment.MiddleLeft;
      this.Label9.BackColor = Color.Transparent;
      this.Label9.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label9.ForeColor = Color.DimGray;
      Label label9_1 = this.Label9;
      point1 = new Point(12, 313);
      Point point63 = point1;
      label9_1.Location = point63;
      this.Label9.Name = "Label9";
      Label label9_2 = this.Label9;
      size1 = new Size(70, 16);
      Size size63 = size1;
      label9_2.Size = size63;
      this.Label9.TabIndex = 453;
      this.Label9.Text = "XP :";
      this.Label9.TextAlign = ContentAlignment.MiddleLeft;
      this.Label5.BackColor = Color.Transparent;
      this.Label5.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label5.ForeColor = Color.DimGray;
      Label label5_1 = this.Label5;
      point1 = new Point(176, 26);
      Point point64 = point1;
      label5_1.Location = point64;
      this.Label5.Name = "Label5";
      Label label5_2 = this.Label5;
      size1 = new Size(130, 16);
      Size size64 = size1;
      label5_2.Size = size64;
      this.Label5.TabIndex = 449;
      this.Label5.Text = "PassWord";
      this.Label5.TextAlign = ContentAlignment.MiddleCenter;
      this.Label4.BackColor = Color.Transparent;
      this.Label4.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label4.ForeColor = Color.Red;
      Label label4_1 = this.Label4;
      point1 = new Point((int) byte.MaxValue, 65);
      Point point65 = point1;
      label4_1.Location = point65;
      this.Label4.Name = "Label4";
      Label label4_2 = this.Label4;
      size1 = new Size(59, 13);
      Size size65 = size1;
      label4_2.Size = size65;
      this.Label4.TabIndex = 448;
      this.Label4.Text = "18 CHAR";
      this.Label4.TextAlign = ContentAlignment.MiddleRight;
      this.BorrarDatos.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BorrarDatos.BackgroundImage = (Image) EmbeddedResources.smethod_36();
      this.BorrarDatos.BackgroundImageLayout = ImageLayout.Center;
      this.BorrarDatos.Cursor = Cursors.Hand;
      this.BorrarDatos.FlatAppearance.BorderSize = 0;
      this.BorrarDatos.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BorrarDatos.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BorrarDatos.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BorrarDatos.FlatStyle = FlatStyle.Flat;
      this.BorrarDatos.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BorrarDatos.ForeColor = Color.Transparent;
      Button borrarDatos1 = this.BorrarDatos;
      point1 = new Point(317, 27);
      Point point66 = point1;
      borrarDatos1.Location = point66;
      this.BorrarDatos.Name = "BorrarDatos";
      Button borrarDatos2 = this.BorrarDatos;
      size1 = new Size(52, 28);
      Size size66 = size1;
      borrarDatos2.Size = size66;
      this.BorrarDatos.TabIndex = 447;
      this.BorrarDatos.TabStop = false;
      this.BorrarDatos.UseVisualStyleBackColor = false;
      this.CrearAccount.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.CrearAccount.BackgroundImage = (Image) EmbeddedResources.smethod_50();
      this.CrearAccount.BackgroundImageLayout = ImageLayout.Center;
      this.CrearAccount.Cursor = Cursors.Hand;
      this.CrearAccount.FlatAppearance.BorderSize = 0;
      this.CrearAccount.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.CrearAccount.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.CrearAccount.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.CrearAccount.FlatStyle = FlatStyle.Flat;
      this.CrearAccount.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.CrearAccount.ForeColor = Color.Transparent;
      Button crearAccount1 = this.CrearAccount;
      point1 = new Point(318, 76);
      Point point67 = point1;
      crearAccount1.Location = point67;
      this.CrearAccount.Name = "CrearAccount";
      Button crearAccount2 = this.CrearAccount;
      size1 = new Size(52, 28);
      Size size67 = size1;
      crearAccount2.Size = size67;
      this.CrearAccount.TabIndex = 446;
      this.CrearAccount.TabStop = false;
      this.CrearAccount.UseVisualStyleBackColor = false;
      this.Label2.BackColor = Color.Transparent;
      this.Label2.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label2.ForeColor = Color.DimGray;
      Label label2_1 = this.Label2;
      point1 = new Point(58, 26);
      Point point68 = point1;
      label2_1.Location = point68;
      this.Label2.Name = "Label2";
      Label label2_2 = this.Label2;
      size1 = new Size(110, 16);
      Size size68 = size1;
      label2_2.Size = size68;
      this.Label2.TabIndex = 444;
      this.Label2.Text = "Account ID";
      this.Label2.TextAlign = ContentAlignment.MiddleCenter;
      this.Account.BackColor = Color.Transparent;
      this.Account.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Account.ForeColor = Color.DimGray;
      Label account1 = this.Account;
      point1 = new Point(68, 114);
      Point point69 = point1;
      account1.Location = point69;
      this.Account.Name = "Account";
      Label account2 = this.Account;
      size1 = new Size(50, 14);
      Size size69 = size1;
      account2.Size = size69;
      this.Account.TabIndex = 442;
      this.Account.Text = "Cuenta";
      this.Account.TextAlign = ContentAlignment.MiddleCenter;
      this.Personajes.Cursor = Cursors.Hand;
      this.Personajes.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Personajes.ItemHeight = 13;
      ComboBox personajes1 = this.Personajes;
      point1 = new Point(188, 150);
      Point point70 = point1;
      personajes1.Location = point70;
      this.Personajes.Name = "Personajes";
      ComboBox personajes2 = this.Personajes;
      size1 = new Size(180, 21);
      Size size70 = size1;
      personajes2.Size = size70;
      this.Personajes.TabIndex = 438;
      this.Personajes.Text = " >> Seleccione Personaje << ";
      this.Cuentas.Cursor = Cursors.Hand;
      this.Cuentas.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Cuentas.ItemHeight = 13;
      ComboBox cuentas1 = this.Cuentas;
      point1 = new Point(8, 150);
      Point point71 = point1;
      cuentas1.Location = point71;
      this.Cuentas.Name = "Cuentas";
      ComboBox cuentas2 = this.Cuentas;
      size1 = new Size(180, 21);
      Size size71 = size1;
      cuentas2.Size = size71;
      this.Cuentas.TabIndex = 437;
      this.Cuentas.Text = " >> Seleccione Cuenta << ";
      this.Label22.BackColor = Color.Transparent;
      this.Label22.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label22.ForeColor = Color.DimGray;
      Label label22_1 = this.Label22;
      point1 = new Point(34, 504);
      Point point72 = point1;
      label22_1.Location = point72;
      this.Label22.Name = "Label22";
      Label label22_2 = this.Label22;
      size1 = new Size(62, 16);
      Size size72 = size1;
      label22_2.Size = size72;
      this.Label22.TabIndex = 476;
      this.Label22.Text = "Account ID";
      this.Label22.TextAlign = ContentAlignment.MiddleCenter;
      this.MD5OFF.BackColor = Color.Transparent;
      this.MD5OFF.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.MD5OFF.ForeColor = Color.Red;
      Label md5Off1 = this.MD5OFF;
      point1 = new Point(12, 36);
      Point point73 = point1;
      md5Off1.Location = point73;
      this.MD5OFF.Name = "MD5OFF";
      Label md5Off2 = this.MD5OFF;
      size1 = new Size(33, 26);
      Size size73 = size1;
      md5Off2.Size = size73;
      this.MD5OFF.TabIndex = 481;
      this.MD5OFF.Text = "MD5 OFF";
      this.MD5OFF.TextAlign = ContentAlignment.MiddleCenter;
      this.MD5ON.BackColor = Color.Transparent;
      this.MD5ON.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.MD5ON.ForeColor = Color.Lime;
      Label md5On1 = this.MD5ON;
      point1 = new Point(16, 44);
      Point point74 = point1;
      md5On1.Location = point74;
      this.MD5ON.Name = "MD5ON";
      Label md5On2 = this.MD5ON;
      size1 = new Size(30, 24);
      Size size74 = size1;
      md5On2.Size = size74;
      this.MD5ON.TabIndex = 489;
      this.MD5ON.Text = "MD5 ON";
      this.MD5ON.TextAlign = ContentAlignment.MiddleCenter;
      this.MD5ON.Visible = false;
      this.Label3.BackColor = Color.Transparent;
      this.Label3.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label3.ForeColor = Color.DimGray;
      Label label3_1 = this.Label3;
      point1 = new Point(16, 62);
      Point point75 = point1;
      label3_1.Location = point75;
      this.Label3.Name = "Label3";
      Label label3_2 = this.Label3;
      size1 = new Size(154, 16);
      Size size75 = size1;
      label3_2.Size = size75;
      this.Label3.TabIndex = 445;
      this.Label3.Text = "E-Mail";
      this.Label3.TextAlign = ContentAlignment.MiddleCenter;
      this.Chart.BackColor = Color.Transparent;
      this.Chart.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Chart.ForeColor = Color.DimGray;
      Label chart1 = this.Chart;
      point1 = new Point(250, 113);
      Point point76 = point1;
      chart1.Location = point76;
      this.Chart.Name = "Chart";
      Label chart2 = this.Chart;
      size1 = new Size(64, 14);
      Size size76 = size1;
      chart2.Size = size76;
      this.Chart.TabIndex = 443;
      this.Chart.Text = "Personaje";
      this.Chart.TextAlign = ContentAlignment.MiddleCenter;
      this.Resets.BackColor = Color.White;
      this.Resets.Enabled = false;
      this.Resets.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Resets.ForeColor = Color.Black;
      TextBox resets1 = this.Resets;
      point1 = new Point(314, 376);
      Point point77 = point1;
      resets1.Location = point77;
      this.Resets.MaxLength = 7;
      this.Resets.Name = "Resets";
      TextBox resets2 = this.Resets;
      size1 = new Size(58, 20);
      Size size77 = size1;
      resets2.Size = size77;
      this.Resets.TabIndex = 501;
      this.Resets.Text = "0";
      this.Label23.AutoSize = true;
      this.Label23.BackColor = Color.Transparent;
      this.Label23.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label23.ForeColor = Color.DimGray;
      Label label23_1 = this.Label23;
      point1 = new Point(223, 380);
      Point point78 = point1;
      label23_1.Location = point78;
      this.Label23.Name = "Label23";
      Label label23_2 = this.Label23;
      size1 = new Size(87, 13);
      Size size78 = size1;
      label23_2.Size = size78;
      this.Label23.TabIndex = 502;
      this.Label23.Text = "Nº of Resets :";
      this.Label23.TextAlign = ContentAlignment.MiddleLeft;
      this.Label15.BackColor = Color.Transparent;
      this.Label15.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label15.ForeColor = Color.Red;
      Label label15_1 = this.Label15;
      point1 = new Point(250, 545);
      Point point79 = point1;
      label15_1.Location = point79;
      this.Label15.Name = "Label15";
      Label label15_2 = this.Label15;
      size1 = new Size(59, 13);
      Size size79 = size1;
      label15_2.Size = size79;
      this.Label15.TabIndex = 504;
      this.Label15.Text = "18 CHAR";
      this.Label15.TextAlign = ContentAlignment.MiddleRight;
      this.Reloj.Enabled = true;
      this.Reloj.Interval = 10000;
      this.Buscar.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Buscar.BackgroundImage = (Image) EmbeddedResources.smethod_12();
      this.Buscar.BackgroundImageLayout = ImageLayout.Center;
      this.Buscar.Cursor = Cursors.Hand;
      this.Buscar.FlatAppearance.BorderSize = 0;
      this.Buscar.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.Buscar.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.Buscar.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.Buscar.FlatStyle = FlatStyle.Flat;
      this.Buscar.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Buscar.ForeColor = Color.Transparent;
      Button buscar1 = this.Buscar;
      point1 = new Point(172, 118);
      Point point80 = point1;
      buscar1.Location = point80;
      this.Buscar.Name = "Buscar";
      Button buscar2 = this.Buscar;
      size1 = new Size(32, 21);
      Size size80 = size1;
      buscar2.Size = size80;
      this.Buscar.TabIndex = 505;
      this.Buscar.TabStop = false;
      this.Buscar.UseVisualStyleBackColor = false;
      this.Minimizar.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Minimizar.BackgroundImage = (Image) EmbeddedResources.smethod_86();
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
      point1 = new Point(8, 7);
      Point point81 = point1;
      minimizar1.Location = point81;
      this.Minimizar.Name = "Minimizar";
      Button minimizar2 = this.Minimizar;
      size1 = new Size(13, 13);
      Size size81 = size1;
      minimizar2.Size = size81;
      this.Minimizar.TabIndex = 1892;
      this.Minimizar.TabStop = false;
      this.Minimizar.UseVisualStyleBackColor = false;
      this.Cerrar.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) EmbeddedResources.smethod_39();
      this.Cerrar.BackgroundImageLayout = ImageLayout.Center;
      this.Cerrar.Cursor = Cursors.Hand;
      this.Cerrar.DialogResult = DialogResult.Cancel;
      this.Cerrar.FlatAppearance.BorderSize = 0;
      this.Cerrar.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.Cerrar.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.Cerrar.FlatStyle = FlatStyle.Flat;
      this.Cerrar.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Cerrar.ForeColor = Color.Transparent;
      Button cerrar1 = this.Cerrar;
      point1 = new Point(355, 7);
      Point point82 = point1;
      cerrar1.Location = point82;
      this.Cerrar.Name = "Cerrar";
      Button cerrar2 = this.Cerrar;
      size1 = new Size(13, 13);
      Size size82 = size1;
      cerrar2.Size = size82;
      this.Cerrar.TabIndex = 1893;
      this.Cerrar.TabStop = false;
      this.Cerrar.UseVisualStyleBackColor = false;
      this.Titulo.AutoSize = true;
      this.Titulo.BackColor = Color.Transparent;
      this.Titulo.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Titulo.ForeColor = Color.DarkOrange;
      Label titulo1 = this.Titulo;
      point1 = new Point(59, 7);
      Point point83 = point1;
      titulo1.Location = point83;
      this.Titulo.Name = "Titulo";
      Label titulo2 = this.Titulo;
      size1 = new Size(0, 13);
      Size size83 = size1;
      titulo2.Size = size83;
      this.Titulo.TabIndex = 1894;
      this.Titulo.TextAlign = ContentAlignment.MiddleLeft;
      this.BlockACC.AutoSize = true;
      this.BlockACC.BackColor = Color.Transparent;
      this.BlockACC.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BlockACC.ForeColor = Color.Red;
      CheckBox blockAcc1 = this.BlockACC;
      point1 = new Point(118, 503);
      Point point84 = point1;
      blockAcc1.Location = point84;
      this.BlockACC.Name = "BlockACC";
      CheckBox blockAcc2 = this.BlockACC;
      size1 = new Size(86, 17);
      Size size84 = size1;
      blockAcc2.Size = size84;
      this.BlockACC.TabIndex = 1895;
      this.BlockACC.Text = "Block ACC";
      this.BlockACC.UseVisualStyleBackColor = false;
      this.AutoScaleMode = AutoScaleMode.Inherit;
      this.BackColor = Color.Black;
      // ISSUE: reference to a compiler-generated method
      this.BackgroundImage = (Image) EmbeddedResources.smethod_3();
      this.CancelButton = (IButtonControl) this.Minimizar;
      size1 = new Size(376, 590);
      this.ClientSize = size1;
      this.Controls.Add((Control) this.BotonGuildMaker);
      this.Controls.Add((Control) this.Titulo);
      this.Controls.Add((Control) this.Cerrar);
      this.Controls.Add((Control) this.Minimizar);
      this.Controls.Add((Control) this.Buscar);
      this.Controls.Add((Control) this.BotonMoveMaker);
      this.Controls.Add((Control) this.Personajes);
      this.Controls.Add((Control) this.Cuentas);
      this.Controls.Add((Control) this.Label23);
      this.Controls.Add((Control) this.Resets);
      this.Controls.Add((Control) this.Quests);
      this.Controls.Add((Control) this.CreateID);
      this.Controls.Add((Control) this.CreatePj);
      this.Controls.Add((Control) this.AccountEdit);
      this.Controls.Add((Control) this.BorrarCuenta);
      this.Controls.Add((Control) this.ONLineInfo);
      this.Controls.Add((Control) this.Label27);
      this.Controls.Add((Control) this.Label28);
      this.Controls.Add((Control) this.Label26);
      this.Controls.Add((Control) this.Label25);
      this.Controls.Add((Control) this.EditDefault);
      this.Controls.Add((Control) this.ResetDefault);
      this.Controls.Add((Control) this.Aplicar);
      this.Controls.Add((Control) this.Reload);
      this.Controls.Add((Control) this.Label24);
      this.Controls.Add((Control) this.PersonalID);
      this.Controls.Add((Control) this.PassWord);
      this.Controls.Add((Control) this.Email);
      this.Controls.Add((Control) this.CuentaID);
      this.Controls.Add((Control) this.Frutas);
      this.Controls.Add((Control) this.EditChart);
      this.Controls.Add((Control) this.EditAccount);
      this.Controls.Add((Control) this.PKTime);
      this.Controls.Add((Control) this.PKCount);
      this.Controls.Add((Control) this.Energia);
      this.Controls.Add((Control) this.Fuerza);
      this.Controls.Add((Control) this.Vitalidad);
      this.Controls.Add((Control) this.Agilidad);
      this.Controls.Add((Control) this.Exp);
      this.Controls.Add((Control) this.Level);
      this.Controls.Add((Control) this.Puntos);
      this.Controls.Add((Control) this.Comand);
      this.Controls.Add((Control) this.PersonajeSearch);
      this.Controls.Add((Control) this.CuentaSearch);
      this.Controls.Add((Control) this.CreatePassWord);
      this.Controls.Add((Control) this.CreateEmail);
      this.Controls.Add((Control) this.CreateAccount);
      this.Controls.Add((Control) this.Label21);
      this.Controls.Add((Control) this.CtrlCode);
      this.Controls.Add((Control) this.BotonSkillMaker);
      this.Controls.Add((Control) this.BotonItemMaker);
      this.Controls.Add((Control) this.PKLevel);
      this.Controls.Add((Control) this.Label17);
      this.Controls.Add((Control) this.Label1);
      this.Controls.Add((Control) this.Label16);
      this.Controls.Add((Control) this.Label14);
      this.Controls.Add((Control) this.Label13);
      this.Controls.Add((Control) this.Label12);
      this.Controls.Add((Control) this.Label10);
      this.Controls.Add((Control) this.Label6);
      this.Controls.Add((Control) this.Label7);
      this.Controls.Add((Control) this.Label11);
      this.Controls.Add((Control) this.Label8);
      this.Controls.Add((Control) this.Label9);
      this.Controls.Add((Control) this.Label5);
      this.Controls.Add((Control) this.Label4);
      this.Controls.Add((Control) this.BorrarDatos);
      this.Controls.Add((Control) this.CrearAccount);
      this.Controls.Add((Control) this.Label2);
      this.Controls.Add((Control) this.Account);
      this.Controls.Add((Control) this.MD5OFF);
      this.Controls.Add((Control) this.MD5ON);
      this.Controls.Add((Control) this.Label3);
      this.Controls.Add((Control) this.Chart);
      this.Controls.Add((Control) this.OnlineOFF);
      this.Controls.Add((Control) this.OnlineON);
      this.Controls.Add((Control) this.Label15);
      this.Controls.Add((Control) this.Label20);
      this.Controls.Add((Control) this.Label18);
      this.Controls.Add((Control) this.Clases);
      this.Controls.Add((Control) this.BlockACC);
      this.Controls.Add((Control) this.Label19);
      this.Controls.Add((Control) this.Label22);
      this.FormBorderStyle = FormBorderStyle.None;
      this.Icon = (Icon) componentResourceManager.GetObject("$this.Icon");
      this.MaximizeBox = false;
      this.MinimizeBox = false;
      this.Name = "AccountMaker";
      this.StartPosition = FormStartPosition.CenterScreen;
      this.Text = "AccountMaker";
      ((ISupportInitialize) this.OnlineOFF).EndInit();
      ((ISupportInitialize) this.OnlineON).EndInit();
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

    public object CargarClasesPJ()
    {
      this.Clases.Items.Clear();
      int num1 = 1;
      int num2 = Conversions.ToInteger(GameDataArrays.string_9);
      int num3 = num1;
      while (num3 <= num2)
      {
        this.Clases.Items.Add((object) GameDataArrays.string_8[checked (num3 - 1)]);
        checked { ++num3; }
      }
      return (object) true;
    }

    public object CargarQuests()
    {
      this.Quests.Items.Clear();
      int num1 = 1;
      int num2 = Conversions.ToInteger(GameDataArrays.string_13);
      int num3 = num1;
      while (num3 <= num2)
      {
        this.Quests.Items.Add((object) GameDataArrays.string_12[checked (num3 - 1)]);
        checked { ++num3; }
      }
      return (object) true;
    }

    public object CargarCtlCode()
    {
      this.CtrlCode.Items.Clear();
      int num1 = 1;
      int num2 = Conversions.ToInteger(GameDataArrays.string_5);
      int num3 = num1;
      while (num3 <= num2)
      {
        this.CtrlCode.Items.Add((object) GameDataArrays.string_4[checked (num3 - 1)]);
        checked { ++num3; }
      }
      return (object) true;
    }

    public object CargarHeroSystem()
    {
      this.PKLevel.Items.Clear();
      int num1 = 1;
      int num2 = Conversions.ToInteger(GameDataArrays.string_16);
      int num3 = num1;
      while (num3 <= num2)
      {
        this.PKLevel.Items.Add((object) GameDataArrays.string_15[checked (num3 - 1)]);
        checked { ++num3; }
      }
      return (object) true;
    }

    public object CargarCuenta()
    {
      this.CuentaID.Text = AccountData.CurrentAccount.string_0;
      this.PassWord.Text = AccountData.CurrentAccount.string_2;
      this.PersonalID.Text = AccountData.CurrentAccount.string_3;
      this.Email.Text = AccountData.CurrentAccount.string_4;
      this.BlockACC.Checked = Conversions.ToDouble(AccountData.CurrentAccount.string_5) != 0.0;
      this.ResetDatosPJ();
      this.RestriccionesOFF();
      this.CuentaID.Enabled = true;
      this.PassWord.Enabled = true;
      this.Email.Enabled = true;
      this.PersonalID.Enabled = true;
      this.CreatePj.Enabled = true;
      this.AccountEdit.Enabled = true;
      this.BorrarCuenta.Enabled = true;
      this.BlockACC.Enabled = true;
      this.Buscar.Focus();
      this.Buscar.Select();
      StatsMaker.DefInstance.Close();
      PJMaker.DefInstance.Close();
      return (object) true;
    }

    public object CargarPersonaje()
    {
      this.EditAccount.Text = Conversions.ToString(this.Cuentas.SelectedItem);
      this.EditChart.Text = Conversions.ToString(this.Personajes.SelectedItem);
      DatabaseOperations.smethod_0();
      this.Level.Text = AccountData.CurrentCharacter.string_2;
      this.Puntos.Text = AccountData.CurrentCharacter.string_3;
      this.Exp.Text = AccountData.CurrentCharacter.string_4;
      this.Fuerza.Text = AccountData.CurrentCharacter.string_5;
      this.Agilidad.Text = AccountData.CurrentCharacter.string_6;
      this.Vitalidad.Text = AccountData.CurrentCharacter.string_7;
      this.Energia.Text = AccountData.CurrentCharacter.string_8;
      this.Comand.Text = AccountData.CurrentCharacter.string_9;
      this.Frutas.Text = AccountData.CurrentCharacter.string_10;
      this.PKLevel.SelectedIndex = Conversions.ToInteger(AccountData.CurrentCharacter.string_11);
      this.PKCount.Text = AccountData.CurrentCharacter.string_12;
      this.PKTime.Text = AccountData.CurrentCharacter.string_13;
      try
      {
        int num1 = 1;
        int num2 = Conversions.ToInteger(GameDataArrays.string_9);
        int num3 = num1;
        while (num3 <= num2)
        {
          if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(AccountData.CurrentCharacter.string_14, GameDataArrays.string_6[checked (num3 - 1)], false) != 0)
          {
            this.Clases.SelectedIndex = checked ((int) Math.Round(unchecked (Conversions.ToDouble(GameDataArrays.string_9) - 1.0)));
            checked { ++num3; }
          }
          else
          {
            this.Clases.SelectedIndex = checked (num3 - 1);
            break;
          }
        }
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      try
      {
        int num1 = 1;
        int num2 = Conversions.ToInteger(GameDataArrays.string_13);
        int num3 = num1;
        while (num3 <= num2)
        {
          if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(AccountData.CurrentCharacter.string_17, GameDataArrays.string_11[checked (num3 - 1)], false) != 0)
          {
            this.Quests.SelectedIndex = checked ((int) Math.Round(unchecked (Conversions.ToDouble(GameDataArrays.string_13) - 1.0)));
            checked { ++num3; }
          }
          else
          {
            this.Quests.SelectedIndex = checked (num3 - 1);
            break;
          }
        }
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      try
      {
        int num1 = 1;
        int num2 = Conversions.ToInteger(GameDataArrays.string_5);
        int num3 = num1;
        while (num3 <= num2)
        {
          if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(AccountData.CurrentCharacter.string_15, GameDataArrays.string_3[checked (num3 - 1)], false) != 0)
          {
            this.CtrlCode.SelectedIndex = checked ((int) Math.Round(unchecked (Conversions.ToDouble(GameDataArrays.string_5) - 1.0)));
            checked { ++num3; }
          }
          else
          {
            this.CtrlCode.SelectedIndex = checked (num3 - 1);
            break;
          }
        }
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      try
      {
        int num1 = 1;
        int num2 = Conversions.ToInteger(GameDataArrays.string_16);
        int num3 = num1;
        while (num3 <= num2)
        {
          if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(AccountData.CurrentCharacter.string_11, GameDataArrays.string_14[checked (num3 - 1)], false) != 0)
          {
            this.PKLevel.SelectedIndex = checked ((int) Math.Round(unchecked (Conversions.ToDouble(GameDataArrays.string_16) - 1.0)));
            if (Conversions.ToDouble(AccountData.CurrentCharacter.string_11) > 6.0)
              this.PKLevel.SelectedIndex = checked ((int) Math.Round(unchecked (Conversions.ToDouble(GameDataArrays.string_16) - 2.0)));
            if (Conversions.ToDouble(AccountData.CurrentCharacter.string_11) < 0.0)
              this.PKLevel.SelectedIndex = 0;
            checked { ++num3; }
          }
          else
          {
            this.PKLevel.SelectedIndex = checked (num3 - 1);
            break;
          }
        }
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Configuration.object_14, (object) 1, false))
      {
        this.Resets.Enabled = true;
        try
        {
          this.Resets.Text = AccountData.CurrentCharacter.string_16;
        }
        catch (Exception ex)
        {
          ProjectData.SetProjectError(ex);
          this.Resets.Enabled = false;
          this.Resets.Text = Conversions.ToString(0);
          ProjectData.ClearProjectError();
        }
      }
      else
      {
        this.Resets.Enabled = false;
        this.Resets.Text = Conversions.ToString(0);
      }
      this.RestriccionesON();
      this.Buscar.Focus();
      this.Buscar.Select();
      StatsMaker.DefInstance.Close();
      PJMaker.DefInstance.Close();
      return (object) true;
    }

    public object CargarCuentas()
    {
      if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Configuration.object_16, (object) 1, false))
      {
        try
        {
          this.Cuentas.Text = Conversions.ToString(LocalizedStrings.object_7);
          this.Cuentas.Items.Clear();
          int num1 = 0;
          int num2 = checked (ApplicationServices.MuMakerApplication.smethod_3().method_8().Cuentas.Items.Count - 1);
          int index = num1;
          while (index <= num2)
          {
            this.Cuentas.Items.Add(RuntimeHelpers.GetObjectValue(ApplicationServices.MuMakerApplication.smethod_3().method_8().Cuentas.Items[index]));
            checked { ++index; }
          }
        }
        catch (Exception ex)
        {
          ProjectData.SetProjectError(ex);
          ProjectData.ClearProjectError();
        }
      }
      else
      {
        ConnectionManager.smethod_0();
        try
        {
          SqlConnectionPool.sqlConnection_1.Open();
          SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
          SqlConnectionPool.sqlCommand_1.CommandText = "SELECT memb___id FROM MEMB_INFO ORDER BY memb___id ASC";
          SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
          this.Cuentas.Text = Conversions.ToString(LocalizedStrings.object_7);
          this.Cuentas.Items.Clear();
          while (SqlConnectionPool.sqlDataReader_1.Read())
            this.Cuentas.Items.Add((object) SqlConnectionPool.sqlDataReader_1[0].ToString());
          SqlConnectionPool.sqlDataReader_1.Close();
        }
        catch (Exception ex)
        {
          ProjectData.SetProjectError(ex);
          int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
          ProjectData.ClearProjectError();
        }
        ConnectionManager.smethod_5();
      }
      return (object) true;
    }

    public object CargarPersonajes()
    {
      ConnectionManager.smethod_0();
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = "SELECT Name FROM Character WHERE AccountID='" + AccountData.CurrentAccount.string_1 + "'";
        SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
        this.Personajes.Text = Conversions.ToString(LocalizedStrings.object_8);
        this.Personajes.Items.Clear();
        while (SqlConnectionPool.sqlDataReader_1.Read())
          this.Personajes.Items.Add((object) SqlConnectionPool.sqlDataReader_1[0].ToString());
        SqlConnectionPool.sqlDataReader_1.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
      return (object) true;
    }

    public object CheckOnLine()
    {
      AccountStatusManager.smethod_0();
      if (AccountData.CurrentAccount.bool_0)
      {
        this.OnlineOFF.Hide();
        this.OnlineON.Show();
      }
      else
      {
        this.OnlineOFF.Show();
        this.OnlineON.Hide();
      }
      return (object) true;
    }

    public object ResetDatosCuenta()
    {
      this.CuentaID.Text = "";
      this.PassWord.Text = "";
      this.Email.Text = "";
      this.PersonalID.Text = "";
      return (object) true;
    }

    public object ResetDatosPJ()
    {
      this.EditAccount.Text = "";
      this.EditChart.Text = "";
      this.Clases.SelectedIndex = 0;
      this.Level.Text = "";
      this.Puntos.Text = "";
      this.Exp.Text = "";
      this.Fuerza.Text = "";
      this.Agilidad.Text = "";
      this.Vitalidad.Text = "";
      this.Energia.Text = "";
      this.Comand.Text = "";
      this.PKLevel.SelectedIndex = 0;
      this.PKCount.Text = "";
      this.PKTime.Text = "";
      this.CtrlCode.SelectedIndex = 0;
      this.Frutas.Text = "";
      return (object) true;
    }

    public object RestriccionesON()
    {
      this.Clases.Enabled = true;
      this.Level.Enabled = true;
      this.Puntos.Enabled = true;
      this.Exp.Enabled = true;
      this.Fuerza.Enabled = true;
      this.Agilidad.Enabled = true;
      this.Vitalidad.Enabled = true;
      this.Energia.Enabled = true;
      this.Comand.Enabled = true;
      this.PKLevel.Enabled = true;
      this.PKCount.Enabled = true;
      this.PKTime.Enabled = true;
      this.CtrlCode.Enabled = true;
      this.Frutas.Enabled = true;
      this.Aplicar.Enabled = true;
      this.Reload.Enabled = true;
      this.Quests.Enabled = true;
      this.CreatePj.Enabled = true;
      this.ResetDefault.Enabled = true;
      this.AccountEdit.Enabled = true;
      this.BorrarCuenta.Enabled = true;
      this.BlockACC.Enabled = true;
      this.CuentaID.Enabled = true;
      this.PassWord.Enabled = true;
      this.Email.Enabled = true;
      this.PersonalID.Enabled = true;
      return (object) true;
    }

    public object RestriccionesOFF()
    {
      this.Clases.Enabled = false;
      this.Level.Enabled = false;
      this.Puntos.Enabled = false;
      this.Exp.Enabled = false;
      this.Fuerza.Enabled = false;
      this.Agilidad.Enabled = false;
      this.Vitalidad.Enabled = false;
      this.Energia.Enabled = false;
      this.Comand.Enabled = false;
      this.PKLevel.Enabled = false;
      this.PKCount.Enabled = false;
      this.PKTime.Enabled = false;
      this.CtrlCode.Enabled = false;
      this.Frutas.Enabled = false;
      this.Aplicar.Enabled = false;
      this.Reload.Enabled = false;
      this.Quests.SelectedIndex = 0;
      this.Quests.Enabled = false;
      this.CreatePj.Enabled = false;
      this.ResetDefault.Enabled = false;
      this.AccountEdit.Enabled = false;
      this.BorrarCuenta.Enabled = false;
      this.BlockACC.Enabled = false;
      this.CuentaID.Enabled = false;
      this.PassWord.Enabled = false;
      this.Email.Enabled = false;
      this.PersonalID.Enabled = false;
      return (object) true;
    }

    public object Traducir()
    {
      if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Configuration.object_15, (object) 1, false))
      {
        this.MD5ON.Visible = true;
        this.MD5OFF.Visible = false;
      }
      else
      {
        this.MD5ON.Visible = false;
        this.MD5OFF.Visible = true;
      }
      this.Account.Text = Conversions.ToString(LocalizedStrings.object_5);
      this.Chart.Text = Conversions.ToString(LocalizedStrings.object_6);
      this.Cuentas.Text = Conversions.ToString(LocalizedStrings.object_7);
      this.Personajes.Text = Conversions.ToString(LocalizedStrings.object_8);
      this.Text = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) (this.Text + " - "), Configuration.object_18));
      this.Titulo.Text = this.Text;
      return (object) true;
    }

    private void AccountMaker_Load(object sender, EventArgs e)
    {
      VentanaBarraLoad.DefInstance.Show();
      IniHelper.smethod_44();
      VentanaBarraLoad.DefInstance.Carga.Value = 10;
      this.CargarClasesPJ();
      VentanaBarraLoad.DefInstance.Carga.Value = 20;
      this.CargarQuests();
      VentanaBarraLoad.DefInstance.Carga.Value = 30;
      this.CargarCtlCode();
      VentanaBarraLoad.DefInstance.Carga.Value = 40;
      this.CargarHeroSystem();
      VentanaBarraLoad.DefInstance.Carga.Value = 50;
      this.RestriccionesOFF();
      VentanaBarraLoad.DefInstance.Carga.Value = 60;
      this.ResetDatosPJ();
      VentanaBarraLoad.DefInstance.Carga.Value = 70;
      this.CargarCuentas();
      VentanaBarraLoad.DefInstance.Carga.Value = 80;
      StoredProceduresManager.smethod_2();
      VentanaBarraLoad.DefInstance.Carga.Value = 90;
      this.ResetDatosCuenta();
      this.Traducir();
      VentanaBarraLoad.DefInstance.Carga.Value = 100;
      VentanaBarraLoad.DefInstance.Hide();
      this.Buscar.Focus();
      this.Buscar.Select();
    }

    private void Cuentas_SelectedIndexChanged(object sender, EventArgs e)
    {
      AccountData.CurrentAccount.string_1 = Conversions.ToString(this.Cuentas.SelectedItem);
      DatabaseOperations.smethod_1();
      this.CargarCuenta();
      this.CargarPersonajes();
      this.CheckOnLine();
    }

    private void Personajes_SelectedIndexChanged(object sender, EventArgs e)
    {
      AccountData.CurrentCharacter.string_1 = Conversions.ToString(this.Personajes.SelectedItem);
      this.CargarPersonaje();
    }

    private void method_0(object sender, KeyPressEventArgs e)
    {
      if ((int) IniHelper.smethod_19(checked ((short) Strings.Asc(e.KeyChar))) != 0)
        return;
      e.Handled = true;
    }

    private void method_1(object sender, KeyPressEventArgs e)
    {
      if ((int) IniHelper.smethod_19(checked ((short) Strings.Asc(e.KeyChar))) != 0)
        return;
      e.Handled = true;
    }

    private void method_2(object sender, KeyPressEventArgs e)
    {
      if ((int) IniHelper.smethod_19(checked ((short) Strings.Asc(e.KeyChar))) != 0)
        return;
      e.Handled = true;
    }

    private void method_3(object sender, KeyPressEventArgs e)
    {
      if ((int) IniHelper.smethod_19(checked ((short) Strings.Asc(e.KeyChar))) != 0)
        return;
      e.Handled = true;
    }

    private void method_4(object sender, KeyPressEventArgs e)
    {
      if ((int) IniHelper.smethod_19(checked ((short) Strings.Asc(e.KeyChar))) != 0)
        return;
      e.Handled = true;
    }

    private void method_5(object sender, KeyPressEventArgs e)
    {
      if ((int) IniHelper.smethod_19(checked ((short) Strings.Asc(e.KeyChar))) != 0)
        return;
      e.Handled = true;
    }

    private void method_6(object sender, KeyPressEventArgs e)
    {
      if ((int) IniHelper.smethod_19(checked ((short) Strings.Asc(e.KeyChar))) != 0)
        return;
      e.Handled = true;
    }

    private void method_7(object sender, KeyPressEventArgs e)
    {
      if ((int) IniHelper.smethod_19(checked ((short) Strings.Asc(e.KeyChar))) != 0)
        return;
      e.Handled = true;
    }

    private void method_8(object sender, KeyPressEventArgs e)
    {
      if ((int) IniHelper.smethod_19(checked ((short) Strings.Asc(e.KeyChar))) != 0)
        return;
      e.Handled = true;
    }

    private void method_9(object sender, KeyPressEventArgs e)
    {
      if ((int) IniHelper.smethod_19(checked ((short) Strings.Asc(e.KeyChar))) != 0)
        return;
      e.Handled = true;
    }

    private void method_10(object sender, KeyPressEventArgs e)
    {
      if ((int) IniHelper.smethod_19(checked ((short) Strings.Asc(e.KeyChar))) != 0)
        return;
      e.Handled = true;
    }

    private void method_11(object sender, KeyPressEventArgs e)
    {
      if ((int) IniHelper.smethod_19(checked ((short) Strings.Asc(e.KeyChar))) != 0)
        return;
      e.Handled = true;
    }

    private void PersonajeSearch_KeyPress(object sender, KeyPressEventArgs e)
    {
      if ((int) checked ((short) Strings.Asc(e.KeyChar)) != 13)
        return;
      this.method_26(RuntimeHelpers.GetObjectValue(sender), (EventArgs) e);
    }

    private void CuentaSearch_KeyPress(object sender, KeyPressEventArgs e)
    {
      if ((int) checked ((short) Strings.Asc(e.KeyChar)) != 13)
        return;
      this.method_26(RuntimeHelpers.GetObjectValue(sender), (EventArgs) e);
    }

    private void method_12(object sender, EventArgs e)
    {
      if (this.Level.Text.Length > 0)
        return;
      this.Level.Text = Conversions.ToString(0);
    }

    private void method_13(object sender, EventArgs e)
    {
      if (this.Puntos.Text.Length > 0)
        return;
      this.Puntos.Text = Conversions.ToString(0);
    }

    private void method_14(object sender, EventArgs e)
    {
      if (this.Exp.Text.Length > 0)
        return;
      this.Exp.Text = Conversions.ToString(0);
    }

    private void method_15(object sender, EventArgs e)
    {
      if (this.Fuerza.Text.Length > 0)
        return;
      this.Fuerza.Text = Conversions.ToString(0);
    }

    private void method_16(object sender, EventArgs e)
    {
      if (this.Agilidad.Text.Length > 0)
        return;
      this.Agilidad.Text = Conversions.ToString(0);
    }

    private void method_17(object sender, EventArgs e)
    {
      if (this.Vitalidad.Text.Length > 0)
        return;
      this.Vitalidad.Text = Conversions.ToString(0);
    }

    private void method_18(object sender, EventArgs e)
    {
      if (this.Energia.Text.Length > 0)
        return;
      this.Energia.Text = Conversions.ToString(0);
    }

    private void method_19(object sender, EventArgs e)
    {
      if (this.Comand.Text.Length > 0)
        return;
      this.Comand.Text = Conversions.ToString(0);
    }

    private void method_20(object sender, EventArgs e)
    {
      if (this.Frutas.Text.Length > 0)
        return;
      this.Frutas.Text = Conversions.ToString(0);
    }

    private void method_21(object sender, EventArgs e)
    {
      if (this.PKCount.Text.Length > 0)
        return;
      this.PKCount.Text = Conversions.ToString(0);
    }

    private void method_22(object sender, EventArgs e)
    {
      if (this.PKTime.Text.Length > 0)
        return;
      this.PKTime.Text = Conversions.ToString(0);
    }

    private void method_23(object sender, EventArgs e)
    {
      if (this.Resets.Text.Length > 0)
        return;
      this.Resets.Text = Conversions.ToString(0);
    }

    private void method_24(object sender, EventArgs e)
    {
      this.CreateAccount.Text = "";
      this.CreatePassWord.Text = "";
      this.CreateEmail.Text = "";
      this.CreateID.Text = "123456789012345678";
    }

    private void method_25(object sender, EventArgs e)
    {
      if (this.CreateAccount.Text.Length >= 1 & this.CreatePassWord.Text.Length >= 1 & this.CreateEmail.Text.Length >= 1 & this.CreateID.Text.Length >= 1)
      {
        if (this.CreateID.Text.Length == 18)
        {
          ConnectionManager.smethod_0();
          object Left = (object) 0;
          try
          {
            SqlConnectionPool.sqlConnection_1.Open();
            SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
            SqlConnectionPool.sqlCommand_1.CommandText = "SELECT * FROM MEMB_INFO WHERE memb___id='" + this.CreateAccount.Text + "'";
            SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
            while (SqlConnectionPool.sqlDataReader_1.Read())
              Left = Microsoft.VisualBasic.CompilerServices.Operators.AddObject(Left, (object) 1);
            SqlConnectionPool.sqlDataReader_1.Close();
            if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectNotEqual(Left, (object) 0, false))
            {
              int num = (int) Interaction.MsgBox((object) "Account Already Existing!!", MsgBoxStyle.OkOnly, (object) null);
              this.CreateAccount.SelectAll();
            }
            else
            {
              ConnectionManager.smethod_5();
              if (this.MD5ON.Visible)
              {
                SqlConnectionPool.sqlConnection_1.Open();
                SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
                try
                {
                  SqlConnectionPool.sqlCommand_1.CommandText = "INSERT INTO MEMB_INFO (memb___id, memb_name, sno__numb, mail_addr, bloc_code, ctl1_code) VALUES ('" + this.CreateAccount.Text + "', 'TMT', '" + this.CreateID.Text + "', '" + this.CreateEmail.Text + "', '0', '1')";
                }
                catch (Exception ex1)
                {
                  ProjectData.SetProjectError(ex1);
                  Exception exception1 = ex1;
                  try
                  {
                    SqlConnectionPool.sqlCommand_1.CommandText = "INSERT INTO MEMB_INFO (memb___id, memb_name, sno__numb, mail_addr, bloc_code, ctl1_code) VALUES ('" + this.CreateAccount.Text + "', 'TMT', '" + Strings.Mid(this.CreateID.Text, 1, 13) + "', '" + this.CreateEmail.Text + "', '0', '1')";
                  }
                  catch (Exception ex2)
                  {
                    ProjectData.SetProjectError(ex2);
                    Exception exception2 = ex2;
                    int num = (int) Interaction.MsgBox((object) (exception1.Message + "\n" + exception2.Message), MsgBoxStyle.OkOnly, (object) null);
                    ProjectData.ClearProjectError();
                  }
                  ProjectData.ClearProjectError();
                }
                SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
                SqlConnectionPool.sqlDataReader_1.Close();
                ConnectionManager.smethod_5();
                SqlConnectionPool.sqlConnection_1.Open();
                try
                {
                  SqlCommand sqlCommand1 = new SqlCommand();
                  SqlCommand sqlCommand2 = new SqlCommand("SP_MD5_ENCODE_VALUE", SqlConnectionPool.sqlConnection_1);
                  sqlCommand2.CommandType = CommandType.StoredProcedure;
                  sqlCommand2.Parameters.Add(new SqlParameter("@btInStr", SqlDbType.VarChar, 10)
                  {
                    Direction = ParameterDirection.Input
                  });
                  sqlCommand2.Parameters.Add(new SqlParameter("@btInStrIndex", SqlDbType.VarChar, 10)
                  {
                    Direction = ParameterDirection.Input
                  });
                  sqlCommand2.Parameters["@btInStr"].Value = (object) this.CreatePassWord.Text;
                  sqlCommand2.Parameters["@btInStrIndex"].Value = (object) this.CreateAccount.Text;
                  sqlCommand2.ExecuteNonQuery();
                  sqlCommand2.Dispose();
                  sqlCommand1.Dispose();
                }
                catch (Exception ex)
                {
                  ProjectData.SetProjectError(ex);
                  int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
                  ProjectData.ClearProjectError();
                }
                ConnectionManager.smethod_5();
              }
              else
              {
                SqlConnectionPool.sqlConnection_1.Open();
                SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
                try
                {
                  SqlConnectionPool.sqlCommand_1.CommandText = "INSERT INTO MEMB_INFO (memb___id, memb__pwd, memb_name, sno__numb, mail_addr, bloc_code, ctl1_code) VALUES ('" + this.CreateAccount.Text + "', '" + this.CreatePassWord.Text + "', 'TMT', '" + this.CreateID.Text + "', '" + this.CreateEmail.Text + "', '0', '1')";
                }
                catch (Exception ex1)
                {
                  ProjectData.SetProjectError(ex1);
                  Exception exception1 = ex1;
                  try
                  {
                    SqlConnectionPool.sqlCommand_1.CommandText = "INSERT INTO MEMB_INFO (memb___id, memb__pwd, memb_name, sno__numb, mail_addr, bloc_code, ctl1_code) VALUES ('" + this.CreateAccount.Text + "', '" + this.CreatePassWord.Text + "', 'TMT', '" + Strings.Mid(this.CreateID.Text, 1, 13) + "', '" + this.CreateEmail.Text + "', '0', '1')";
                  }
                  catch (Exception ex2)
                  {
                    ProjectData.SetProjectError(ex2);
                    Exception exception2 = ex2;
                    int num = (int) Interaction.MsgBox((object) (exception1.Message + "\n" + exception2.Message), MsgBoxStyle.OkOnly, (object) null);
                    ProjectData.ClearProjectError();
                  }
                  ProjectData.ClearProjectError();
                }
                SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
                SqlConnectionPool.sqlDataReader_1.Close();
                ConnectionManager.smethod_5();
              }
              if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Configuration.object_17, (object) 1, false))
              {
                ApplicationServices.MuMakerApplication.smethod_3().method_8().CargarCuentas();
                this.CargarCuentas();
              }
              else
              {
                ApplicationServices.MuMakerApplication.smethod_3().method_8().Cuentas.Items.Add((object) this.CreateAccount.Text);
                this.Cuentas.Items.Add((object) this.CreateAccount.Text);
              }
              int num1 = (int) Interaction.MsgBox((object) "Account Create!!", MsgBoxStyle.OkOnly, (object) null);
              this.CreateAccount.Text = "";
              this.CreatePassWord.Text = "";
              this.CreateEmail.Text = "";
              this.CreateID.Text = "";
              this.CuentaID.Text = "";
              this.PassWord.Text = "";
              this.Email.Text = "";
              this.PersonalID.Text = "";
              this.CreateID.Text = "123456789012345678";
              ConnectionManager.smethod_5();
              this.ResetDatosPJ();
            }
          }
          catch (Exception ex)
          {
            ProjectData.SetProjectError(ex);
            int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
            ProjectData.ClearProjectError();
          }
          ConnectionManager.smethod_5();
        }
        else
        {
          int num = (int) Interaction.MsgBox((object) "Personal ID NEED 18 CHR!!", MsgBoxStyle.OkOnly, (object) null);
          this.CreateID.SelectAll();
        }
      }
      else
      {
        if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(LocalizedStrings.string_0, "Espanol", false) == 0)
        {
          int num1 = (int) Interaction.MsgBox((object) "Rellene Todos Los Campos!!", MsgBoxStyle.OkOnly, (object) null);
        }
        if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(LocalizedStrings.string_0, "English", false) == 0)
        {
          int num2 = (int) Interaction.MsgBox((object) "Fill up everything!!", MsgBoxStyle.OkOnly, (object) null);
        }
        if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(LocalizedStrings.string_0, "PortBra", false) == 0)
        {
          int num3 = (int) Interaction.MsgBox((object) "Rellene Todos Os Campos!!", MsgBoxStyle.OkOnly, (object) null);
        }
        if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(LocalizedStrings.string_0, "Espanol", false) != 0 & Microsoft.VisualBasic.CompilerServices.Operators.CompareString(LocalizedStrings.string_0, "English", false) != 0 & Microsoft.VisualBasic.CompilerServices.Operators.CompareString(LocalizedStrings.string_0, "PortBra", false) != 0)
        {
          int num4 = (int) Interaction.MsgBox((object) "Fill up everything!!", MsgBoxStyle.OkOnly, (object) null);
        }
      }
      PJMaker.DefInstance.Hide();
    }

    private void method_26(object sender, EventArgs e)
    {
      if (this.CuentaSearch.Text.Length > 0)
        this.Cuentas.SelectedItem = (object) this.CuentaSearch.Text;
      if (this.PersonajeSearch.Text.Length <= 0)
        return;
      ConnectionManager.smethod_0();
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = "SELECT AccountID FROM Character WHERE Name='" + this.PersonajeSearch.Text + "'";
        SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
        while (SqlConnectionPool.sqlDataReader_1.Read())
          this.CuentaSearch.Text = SqlConnectionPool.sqlDataReader_1[0].ToString();
        SqlConnectionPool.sqlDataReader_1.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
      this.Cuentas.SelectedItem = (object) this.CuentaSearch.Text;
      this.Personajes.SelectedItem = (object) this.PersonajeSearch.Text;
    }

    private void method_27(object sender, EventArgs e)
    {
      AccountMaker.DefInstance.WindowState = FormWindowState.Minimized;
      VentanaBarraLoad.DefInstance.Show();
      ItemMaker.DefInstance.Show();
      ItemMaker.DefInstance.Cuentas.SelectedItem = RuntimeHelpers.GetObjectValue(AccountMaker.DefInstance.Cuentas.SelectedItem);
      ItemMaker.DefInstance.Personajes.SelectedItem = RuntimeHelpers.GetObjectValue(AccountMaker.DefInstance.Personajes.SelectedItem);
      VentanaBarraLoad.DefInstance.Hide();
      ItemMaker.DefInstance.Activate();
      AccountMaker.DefInstance.Close();
    }

    private void method_28(object sender, EventArgs e)
    {
      AccountMaker.DefInstance.WindowState = FormWindowState.Minimized;
      VentanaBarraLoad.DefInstance.Show();
      SkillMaker.DefInstance.Show();
      SkillMaker.DefInstance.Cuentas.SelectedItem = RuntimeHelpers.GetObjectValue(AccountMaker.DefInstance.Cuentas.SelectedItem);
      SkillMaker.DefInstance.Personajes.SelectedItem = RuntimeHelpers.GetObjectValue(AccountMaker.DefInstance.Personajes.SelectedItem);
      VentanaBarraLoad.DefInstance.Hide();
      SkillMaker.DefInstance.Activate();
      AccountMaker.DefInstance.Close();
    }

    private void method_29(object sender, EventArgs e)
    {
      AccountMaker.DefInstance.WindowState = FormWindowState.Minimized;
      VentanaBarraLoad.DefInstance.Show();
      MoveMaker.DefInstance.Show();
      VentanaBarraLoad.DefInstance.Hide();
      MoveMaker.DefInstance.Activate();
      AccountMaker.DefInstance.Close();
    }

    private void method_30(object sender, EventArgs e)
    {
      AccountMaker.DefInstance.WindowState = FormWindowState.Minimized;
      VentanaBarraLoad.DefInstance.Show();
      GuildMaker.DefInstance.Show();
      VentanaBarraLoad.DefInstance.Hide();
      GuildMaker.DefInstance.Activate();
      AccountMaker.DefInstance.Close();
    }

    private void method_31(object sender, EventArgs e)
    {
      StatsMaker.DefInstance.Close();
      PJMaker.DefInstance.Close();
      ConnectionManager.smethod_0();
      int num1 = Conversions.ToInteger(GameDataArrays.string_6[this.Clases.SelectedIndex]);
      int num2 = Conversions.ToInteger(GameDataArrays.string_3[this.CtrlCode.SelectedIndex]);
      string str1 = IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "Reset", "0");
      string str2 = IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "Reset", "Resets");
      int num3;
      if (Conversions.ToDouble(str1) == 1.0 & this.Resets.Enabled)
      {
        try
        {
          SqlConnectionPool.sqlConnection_1.Open();
          SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
          if (num1 == 999 & num2 == 999)
            SqlConnectionPool.sqlCommand_1.CommandText = "UPDATE Character SET cLevel='" + this.Level.Text + "', LevelUpPoint='" + this.Puntos.Text + "', Experience='" + this.Exp.Text + "', Strength='" + this.Fuerza.Text + "', Dexterity='" + this.Agilidad.Text + "', Vitality='" + this.Vitalidad.Text + "', Energy='" + this.Energia.Text + "', PkCount='" + this.PKCount.Text + "', PkLevel='" + Conversions.ToString(this.PKLevel.SelectedIndex) + "', PkTime='" + this.PKTime.Text + "', Leadership='" + this.Comand.Text + "', FruitPoint='" + this.Frutas.Text + "', " + str2 + "=" + this.Resets.Text + " WHERE AccountID='" + this.EditAccount.Text + "' AND Name='" + this.EditChart.Text + "'";
          if (num1 == 999 & num2 != 999)
            SqlConnectionPool.sqlCommand_1.CommandText = "UPDATE Character SET cLevel='" + this.Level.Text + "', LevelUpPoint='" + this.Puntos.Text + "', Experience='" + this.Exp.Text + "', Strength='" + this.Fuerza.Text + "', Dexterity='" + this.Agilidad.Text + "', Vitality='" + this.Vitalidad.Text + "', Energy='" + this.Energia.Text + "', PkCount='" + this.PKCount.Text + "', PkLevel='" + Conversions.ToString(this.PKLevel.SelectedIndex) + "', PkTime='" + this.PKTime.Text + "', CtlCode='" + Conversions.ToString(num2) + "', Leadership='" + this.Comand.Text + "', FruitPoint='" + this.Frutas.Text + "', " + str2 + "=" + this.Resets.Text + " WHERE AccountID='" + this.EditAccount.Text + "' AND Name='" + this.EditChart.Text + "'";
          if (num1 != 999 & num2 == 999)
            SqlConnectionPool.sqlCommand_1.CommandText = "UPDATE Character SET cLevel='" + this.Level.Text + "', LevelUpPoint='" + this.Puntos.Text + "' Class='" + Conversions.ToString(num1) + "', Experience='" + this.Exp.Text + "', Strength='" + this.Fuerza.Text + "', Dexterity='" + this.Agilidad.Text + "', Vitality='" + this.Vitalidad.Text + "', Energy='" + this.Energia.Text + "', PkCount='" + this.PKCount.Text + "', PkLevel='" + Conversions.ToString(this.PKLevel.SelectedIndex) + "', PkTime='" + this.PKTime.Text + "', Leadership='" + this.Comand.Text + "', FruitPoint='" + this.Frutas.Text + "', " + str2 + "=" + this.Resets.Text + " WHERE AccountID='" + this.EditAccount.Text + "' AND Name='" + this.EditChart.Text + "'";
          if (num1 != 999 & num2 != 999)
            SqlConnectionPool.sqlCommand_1.CommandText = "UPDATE Character SET cLevel='" + this.Level.Text + "', LevelUpPoint='" + this.Puntos.Text + "', Class='" + Conversions.ToString(num1) + "', Experience='" + this.Exp.Text + "', Strength='" + this.Fuerza.Text + "', Dexterity='" + this.Agilidad.Text + "', Vitality='" + this.Vitalidad.Text + "', Energy='" + this.Energia.Text + "', PkCount='" + this.PKCount.Text + "', PkLevel='" + Conversions.ToString(this.PKLevel.SelectedIndex) + "', PkTime='" + this.PKTime.Text + "',  CtlCode='" + Conversions.ToString(num2) + "', Leadership='" + this.Comand.Text + "', FruitPoint='" + this.Frutas.Text + "', " + str2 + "=" + this.Resets.Text + " WHERE AccountID='" + this.EditAccount.Text + "' AND Name='" + this.EditChart.Text + "'";
          SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
          SqlConnectionPool.sqlDataReader_1.Close();
          num3 = 1;
        }
        catch (Exception ex)
        {
          ProjectData.SetProjectError(ex);
          int num4 = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
          ConnectionManager.smethod_5();
          ProjectData.ClearProjectError();
          return;
        }
      }
      else
      {
        try
        {
          SqlConnectionPool.sqlConnection_1.Open();
          SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
          if (num1 == 999 & num2 == 999)
            SqlConnectionPool.sqlCommand_1.CommandText = "UPDATE Character SET cLevel='" + this.Level.Text + "', LevelUpPoint='" + this.Puntos.Text + "', Experience='" + this.Exp.Text + "', Strength='" + this.Fuerza.Text + "', Dexterity='" + this.Agilidad.Text + "', Vitality='" + this.Vitalidad.Text + "', Energy='" + this.Energia.Text + "', PkCount='" + this.PKCount.Text + "', PkLevel='" + Conversions.ToString(this.PKLevel.SelectedIndex) + "', PkTime='" + this.PKTime.Text + "', Leadership='" + this.Comand.Text + "', FruitPoint='" + this.Frutas.Text + "' WHERE AccountID='" + this.EditAccount.Text + "' AND Name='" + this.EditChart.Text + "'";
          if (num1 == 999 & num2 != 999)
            SqlConnectionPool.sqlCommand_1.CommandText = "UPDATE Character SET cLevel='" + this.Level.Text + "', LevelUpPoint='" + this.Puntos.Text + "', Experience='" + this.Exp.Text + "', Strength='" + this.Fuerza.Text + "', Dexterity='" + this.Agilidad.Text + "', Vitality='" + this.Vitalidad.Text + "', Energy='" + this.Energia.Text + "', PkCount='" + this.PKCount.Text + "', PkLevel='" + Conversions.ToString(this.PKLevel.SelectedIndex) + "', PkTime='" + this.PKTime.Text + "', CtlCode='" + Conversions.ToString(num2) + "', Leadership='" + this.Comand.Text + "', FruitPoint='" + this.Frutas.Text + "' WHERE AccountID='" + this.EditAccount.Text + "' AND Name='" + this.EditChart.Text + "'";
          if (num1 != 999 & num2 == 999)
            SqlConnectionPool.sqlCommand_1.CommandText = "UPDATE Character SET cLevel='" + this.Level.Text + "', LevelUpPoint='" + this.Puntos.Text + "'  Class='" + Conversions.ToString(num1) + "', Experience='" + this.Exp.Text + "', Strength='" + this.Fuerza.Text + "', Dexterity='" + this.Agilidad.Text + "', Vitality='" + this.Vitalidad.Text + "', Energy='" + this.Energia.Text + "', PkCount='" + this.PKCount.Text + "', PkLevel='" + Conversions.ToString(this.PKLevel.SelectedIndex) + "', PkTime='" + this.PKTime.Text + "', Leadership='" + this.Comand.Text + "', FruitPoint='" + this.Frutas.Text + "' WHERE AccountID='" + this.EditAccount.Text + "' AND Name='" + this.EditChart.Text + "'";
          if (num1 != 999 & num2 != 999)
            SqlConnectionPool.sqlCommand_1.CommandText = "UPDATE Character SET cLevel='" + this.Level.Text + "', LevelUpPoint='" + this.Puntos.Text + "', Class='" + Conversions.ToString(num1) + "', Experience='" + this.Exp.Text + "', Strength='" + this.Fuerza.Text + "', Dexterity='" + this.Agilidad.Text + "', Vitality='" + this.Vitalidad.Text + "', Energy='" + this.Energia.Text + "', PkCount='" + this.PKCount.Text + "', PkLevel='" + Conversions.ToString(this.PKLevel.SelectedIndex) + "', PkTime='" + this.PKTime.Text + "',  CtlCode='" + Conversions.ToString(num2) + "', Leadership='" + this.Comand.Text + "', FruitPoint='" + this.Frutas.Text + "' WHERE AccountID='" + this.EditAccount.Text + "' AND Name='" + this.EditChart.Text + "'";
          SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
          SqlConnectionPool.sqlDataReader_1.Close();
          num3 = 1;
        }
        catch (Exception ex)
        {
          ProjectData.SetProjectError(ex);
          int num4 = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
          ConnectionManager.smethod_5();
          ProjectData.ClearProjectError();
          return;
        }
      }
      ConnectionManager.smethod_5();
      StoredProceduresManager.smethod_11((object) ("0x" + GameDataArrays.string_11[this.Quests.SelectedIndex]));
      int num5 = 0;
      if (Conversions.ToDouble(GameDataArrays.string_10[this.Quests.SelectedIndex]) == 999.0)
        num5 = 1;
      int num6;
      if (num5 == 1)
      {
        num6 = 1;
      }
      else
      {
        ConnectionManager.smethod_1();
        SqlConnectionPool.sqlConnection_2.Open();
        try
        {
          SqlCommand sqlCommand1 = new SqlCommand();
          SqlCommand sqlCommand2 = new SqlCommand("MMK_QuestMaker", SqlConnectionPool.sqlConnection_2);
          sqlCommand2.CommandType = CommandType.StoredProcedure;
          sqlCommand2.Parameters.Add(new SqlParameter("@AccountID", SqlDbType.VarChar, 10)
          {
            Direction = ParameterDirection.Input
          });
          sqlCommand2.Parameters.Add(new SqlParameter("@Name", SqlDbType.VarChar, 10)
          {
            Direction = ParameterDirection.Input
          });
          sqlCommand2.Parameters["@AccountID"].Value = (object) this.EditAccount.Text;
          sqlCommand2.Parameters["@Name"].Value = (object) this.EditChart.Text;
          sqlCommand2.ExecuteNonQuery();
          sqlCommand2.Dispose();
          sqlCommand1.Dispose();
          num6 = checked (num3 + 1);
        }
        catch (Exception ex)
        {
          ProjectData.SetProjectError(ex);
          Exception exception = ex;
          num6 = checked (num3 - 1);
          int num4 = (int) Interaction.MsgBox((object) exception.Message, MsgBoxStyle.OkOnly, (object) null);
          ProjectData.ClearProjectError();
        }
        ConnectionManager.smethod_6();
      }
      if (num6 == 1)
      {
        int num7 = (int) Interaction.MsgBox((object) "!! QUEST UNKNOWN .:. NOT SAVE!!", MsgBoxStyle.OkOnly, (object) null);
      }
      if (num6 != 2)
        return;
      int num8 = (int) Interaction.MsgBox((object) "!! ALL OK !!", MsgBoxStyle.OkOnly, (object) null);
    }

    private void method_32(object sender, EventArgs e)
    {
      int num1 = Conversions.ToInteger(GameDataArrays.string_7[this.Clases.SelectedIndex]);
      if (num1 == 9999)
        num1 = 0;
      ConnectionManager.smethod_0();
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = "SELECT * FROM DefaultClassType WHERE Class='" + Conversions.ToString(num1) + "'";
        SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
        SqlConnectionPool.sqlDataReader_1.Read();
        this.Level.Text = SqlConnectionPool.sqlDataReader_1[17].ToString();
        this.Puntos.Text = SqlConnectionPool.sqlDataReader_1[18].ToString();
        this.Exp.Text = "0";
        this.Fuerza.Text = SqlConnectionPool.sqlDataReader_1[1].ToString();
        this.Agilidad.Text = SqlConnectionPool.sqlDataReader_1[2].ToString();
        this.Vitalidad.Text = SqlConnectionPool.sqlDataReader_1[3].ToString();
        this.Energia.Text = SqlConnectionPool.sqlDataReader_1[4].ToString();
        this.Comand.Text = SqlConnectionPool.sqlDataReader_1[16].ToString();
        this.PKLevel.SelectedIndex = 3;
        this.PKCount.Text = "0";
        this.PKTime.Text = "0";
        this.CtrlCode.SelectedIndex = 0;
        this.Quests.SelectedIndex = 0;
        try
        {
          int num2 = 1;
          int num3 = Conversions.ToInteger(GameDataArrays.string_9);
          int num4 = num2;
          while (num4 <= num3)
          {
            if ((double) num1 != Conversions.ToDouble(GameDataArrays.string_6[checked (num4 - 1)]))
            {
              this.Clases.SelectedIndex = checked ((int) Math.Round(unchecked (Conversions.ToDouble(GameDataArrays.string_9) - 1.0)));
              checked { ++num4; }
            }
            else
            {
              this.Clases.SelectedIndex = checked (num4 - 1);
              break;
            }
          }
        }
        catch (Exception ex)
        {
          ProjectData.SetProjectError(ex);
          int num2 = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
          ProjectData.ClearProjectError();
        }
        this.Frutas.Text = "0";
        this.Resets.Text = "0";
        SqlConnectionPool.sqlDataReader_1.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num2 = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
    }

    private void method_33(object sender, EventArgs e)
    {
      this.CargarPersonaje();
      PJMaker.DefInstance.Close();
    }

    private void ONLineInfo_Click(object sender, EventArgs e)
    {
      this.CheckOnLine();
    }

    private void method_34(object sender, EventArgs e)
    {
      AccountMaker.DefInstance.WindowState = FormWindowState.Minimized;
    }

    private void method_35(object sender, EventArgs e)
    {
      this.Close();
    }

    private void method_36(object sender, EventArgs e)
    {
      PJMaker.DefInstance.Close();
      StatsMaker.DefInstance.Show();
      StatsMaker.DefInstance.Location = new Point(checked (AccountMaker.DefInstance.Location.X + 376), checked (AccountMaker.DefInstance.Location.Y + 223));
    }

    private void AccountMaker_Move(object sender, EventArgs e)
    {
        Point location = DefInstance.Location;
        Point point3 = new Point(location.X + 0x178, DefInstance.Location.Y + 0xdf);
        StatsMaker.DefInstance.Location = point3;
        location = new Point(DefInstance.Location.X + 0x178, DefInstance.Location.Y);
        PJMaker.DefInstance.Location = location;
    }

    private void method_37(object sender, EventArgs e)
    {
      StatsMaker.DefInstance.Close();
      PJMaker.DefInstance.Close();
      PJMaker.DefInstance.Show();
      PJMaker.DefInstance.Location = new Point(checked (AccountMaker.DefInstance.Location.X + 376), AccountMaker.DefInstance.Location.Y);
    }

    private void method_38(object sender, EventArgs e)
    {
      StatsMaker.DefInstance.Close();
      PJMaker.DefInstance.Close();
      if (!Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual((object) Interaction.MsgBox((object) "!!!!! Delete This Account !!!!!", MsgBoxStyle.YesNo, RuntimeHelpers.GetObjectValue(LocalizedStrings.object_76)), (object) MsgBoxResult.Yes, false))
        return;
      ConnectionManager.smethod_0();
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = "DELETE FROM MEMB_INFO WHERE memb___id='" + this.CuentaID.Text + "'";
        SqlConnectionPool.sqlCommand_1.ExecuteReader();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = "DELETE FROM AccountCharacter WHERE Id='" + this.CuentaID.Text + "'";
        SqlConnectionPool.sqlCommand_1.ExecuteReader();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = "DELETE FROM Character WHERE AccountID='" + this.CuentaID.Text + "'";
        SqlConnectionPool.sqlCommand_1.ExecuteReader();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = "DELETE FROM warehouse WHERE AccountID='" + this.CuentaID.Text + "'";
        SqlConnectionPool.sqlCommand_1.ExecuteReader();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = "DELETE FROM ExtWareHouse WHERE AccountID='" + this.CuentaID.Text + "'";
        SqlConnectionPool.sqlCommand_1.ExecuteReader();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
      PJMaker.DefInstance.Close();
      if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(Configuration.object_17, (object) 1, false))
      {
        ApplicationServices.MuMakerApplication.smethod_3().method_8().CargarCuentas();
        this.CargarCuentas();
      }
      else
      {
        ApplicationServices.MuMakerApplication.smethod_3().method_8().Cuentas.Items.Remove((object) this.CuentaID.Text);
        this.Cuentas.Items.Remove((object) this.CuentaID.Text);
        this.CargarCuentas();
      }
      ConnectionManager.smethod_5();
      this.CuentaID.Text = "";
      this.PassWord.Text = "";
      this.Email.Text = "";
      this.PersonalID.Text = "";
      this.ResetDatosPJ();
      this.RestriccionesOFF();
      this.Buscar.Focus();
      this.Buscar.Select();
    }

    private void method_39(object sender, EventArgs e)
    {
      if (this.CuentaID.Text.Length >= 1 & this.PassWord.Text.Length >= 1 & this.Email.Text.Length >= 1 & this.PersonalID.Text.Length >= 1)
      {
        if (this.PersonalID.Text.Length == 18)
        {
          ConnectionManager.smethod_0();
          object Left = (object) 0;
          try
          {
            SqlConnectionPool.sqlConnection_1.Open();
            SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
            SqlConnectionPool.sqlCommand_1.CommandText = "SELECT * FROM MEMB_INFO WHERE memb___id='" + this.CuentaID.Text + "'";
            SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
            while (SqlConnectionPool.sqlDataReader_1.Read())
              Left = Microsoft.VisualBasic.CompilerServices.Operators.AddObject(Left, (object) 1);
            if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(this.CuentaID.Text, this.Cuentas.Text, false) == 0)
              Left = (object) 0;
            SqlConnectionPool.sqlDataReader_1.Close();
            if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectNotEqual(Left, (object) 0, false))
            {
              int num = (int) Interaction.MsgBox((object) "Account Already Existing!!", MsgBoxStyle.OkOnly, (object) null);
              this.CreateAccount.SelectAll();
            }
            else
            {
              ConnectionManager.smethod_5();
              if (this.MD5ON.Visible)
              {
                SqlConnectionPool.sqlConnection_1.Open();
                SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
                try
                {
                  SqlConnectionPool.sqlCommand_1.CommandText = "UPDATE MEMB_INFO SET memb___id = '" + this.CuentaID.Text + "', sno__numb = '" + this.PersonalID.Text + "', mail_addr = '" + this.Email.Text + "' WHERE memb___id = '" + this.Cuentas.Text + "';";
                }
                catch (Exception ex1)
                {
                  ProjectData.SetProjectError(ex1);
                  Exception exception1 = ex1;
                  try
                  {
                    SqlConnectionPool.sqlCommand_1.CommandText = "UPDATE MEMB_INFO SET memb___id = '" + this.CuentaID.Text + "', sno__numb = '" + Strings.Mid(this.PersonalID.Text, 1, 13) + "', mail_addr = '" + this.Email.Text + "' WHERE memb___id = '" + this.Cuentas.Text + "';";
                  }
                  catch (Exception ex2)
                  {
                    ProjectData.SetProjectError(ex2);
                    Exception exception2 = ex2;
                    int num = (int) Interaction.MsgBox((object) (exception1.Message + "\n" + exception2.Message), MsgBoxStyle.OkOnly, (object) null);
                    ProjectData.ClearProjectError();
                  }
                  ProjectData.ClearProjectError();
                }
                SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
                SqlConnectionPool.sqlDataReader_1.Close();
                ConnectionManager.smethod_5();
                SqlConnectionPool.sqlConnection_1.Open();
                try
                {
                  SqlCommand sqlCommand1 = new SqlCommand();
                  SqlCommand sqlCommand2 = new SqlCommand("SP_MD5_ENCODE_VALUE", SqlConnectionPool.sqlConnection_1);
                  sqlCommand2.CommandType = CommandType.StoredProcedure;
                  sqlCommand2.Parameters.Add(new SqlParameter("@btInStr", SqlDbType.VarChar, 10)
                  {
                    Direction = ParameterDirection.Input
                  });
                  sqlCommand2.Parameters.Add(new SqlParameter("@btInStrIndex", SqlDbType.VarChar, 10)
                  {
                    Direction = ParameterDirection.Input
                  });
                  sqlCommand2.Parameters["@btInStr"].Value = (object) this.PassWord.Text;
                  sqlCommand2.Parameters["@btInStrIndex"].Value = (object) this.CuentaID.Text;
                  sqlCommand2.ExecuteNonQuery();
                  sqlCommand2.Dispose();
                  sqlCommand1.Dispose();
                }
                catch (Exception ex)
                {
                  ProjectData.SetProjectError(ex);
                  int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
                  ProjectData.ClearProjectError();
                }
                ConnectionManager.smethod_5();
              }
              else
              {
                SqlConnectionPool.sqlConnection_1.Open();
                SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
                try
                {
                  SqlConnectionPool.sqlCommand_1.CommandText = "UPDATE MEMB_INFO SET memb___id = '" + this.CuentaID.Text + "', memb__pwd = '" + this.PassWord.Text + "', sno__numb = '" + this.PersonalID.Text + "', mail_addr = '" + this.Email.Text + "' WHERE memb___id = '" + this.Cuentas.Text + "';";
                }
                catch (Exception ex1)
                {
                  ProjectData.SetProjectError(ex1);
                  Exception exception1 = ex1;
                  try
                  {
                    SqlConnectionPool.sqlCommand_1.CommandText = "UPDATE MEMB_INFO SET memb___id = '" + this.CuentaID.Text + "', memb__pwd = '" + this.PassWord.Text + "', sno__numb = '" + Strings.Mid(this.PersonalID.Text, 1, 13) + "', mail_addr = '" + this.Email.Text + "' WHERE memb___id = '" + this.Cuentas.Text + "';";
                  }
                  catch (Exception ex2)
                  {
                    ProjectData.SetProjectError(ex2);
                    Exception exception2 = ex2;
                    int num = (int) Interaction.MsgBox((object) (exception1.Message + "\n" + exception2.Message), MsgBoxStyle.OkOnly, (object) null);
                    ProjectData.ClearProjectError();
                  }
                  ProjectData.ClearProjectError();
                }
                SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
                SqlConnectionPool.sqlDataReader_1.Close();
                ConnectionManager.smethod_5();
              }
              SqlConnectionPool.sqlConnection_1.Open();
              SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
              SqlConnectionPool.sqlCommand_1.CommandText = "UPDATE character SET AccountID = '" + this.CuentaID.Text + "' WHERE AccountID = '" + this.Cuentas.Text + "';";
              SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
              SqlConnectionPool.sqlDataReader_1.Close();
              ConnectionManager.smethod_5();
              SqlConnectionPool.sqlConnection_1.Open();
              SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
              SqlConnectionPool.sqlCommand_1.CommandText = "UPDATE AccountCharacter SET Id = '" + this.CuentaID.Text + "'WHERE Id = '" + this.Cuentas.Text + "';";
              SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
              SqlConnectionPool.sqlDataReader_1.Close();
              int num1 = (int) Interaction.MsgBox((object) "Account Edited!!", MsgBoxStyle.OkOnly, (object) null);
              ConnectionManager.smethod_5();
              this.ResetDatosPJ();
              try
              {
                SqlConnectionPool.sqlConnection_1.Open();
                SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
                SqlConnectionPool.sqlCommand_1.CommandText = "SELECT memb___id FROM MEMB_INFO ORDER BY memb___id ASC";
                SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
                string string_0 = IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "Languaje", "Espanol");
                this.Personajes.Text = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) " ", IniHelper.smethod_0(string_0, "SelecPerson")), (object) " "));
                this.Personajes.Items.Clear();
                this.Cuentas.Text = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) " ", IniHelper.smethod_0(string_0, "SelecAcount")), (object) " "));
                this.Cuentas.Items.Clear();
                while (SqlConnectionPool.sqlDataReader_1.Read())
                  this.Cuentas.Items.Add((object) SqlConnectionPool.sqlDataReader_1[0].ToString());
                this.Cuentas.SelectedItem = (object) this.CuentaID.Text;
                SqlConnectionPool.sqlDataReader_1.Close();
              }
              catch (Exception ex)
              {
                ProjectData.SetProjectError(ex);
                int num2 = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
                ProjectData.ClearProjectError();
              }
              ConnectionManager.smethod_5();
            }
          }
          catch (Exception ex)
          {
            ProjectData.SetProjectError(ex);
            int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
            ProjectData.ClearProjectError();
          }
          ConnectionManager.smethod_5();
          this.RestriccionesOFF();
          this.CuentaID.Enabled = true;
          this.PassWord.Enabled = true;
          this.Email.Enabled = true;
          this.PersonalID.Enabled = true;
          this.CreatePj.Enabled = true;
          this.AccountEdit.Enabled = true;
          this.BorrarCuenta.Enabled = true;
        }
        else
        {
          int num = (int) Interaction.MsgBox((object) "Personal ID NEED 18 CHR!!", MsgBoxStyle.OkOnly, (object) null);
          this.CreateID.SelectAll();
        }
      }
      else
      {
        if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(LocalizedStrings.string_0, "Espanol", false) == 0)
        {
          int num1 = (int) Interaction.MsgBox((object) "Rellene Todos Los Campos!!", MsgBoxStyle.OkOnly, (object) null);
        }
        if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(LocalizedStrings.string_0, "English", false) == 0)
        {
          int num2 = (int) Interaction.MsgBox((object) "Fill up everything!!", MsgBoxStyle.OkOnly, (object) null);
        }
        if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(LocalizedStrings.string_0, "PortBra", false) == 0)
        {
          int num3 = (int) Interaction.MsgBox((object) "Rellene Todos Os Campos!!", MsgBoxStyle.OkOnly, (object) null);
        }
        if (!(Microsoft.VisualBasic.CompilerServices.Operators.CompareString(LocalizedStrings.string_0, "Espanol", false) != 0 & Microsoft.VisualBasic.CompilerServices.Operators.CompareString(LocalizedStrings.string_0, "English", false) != 0 & Microsoft.VisualBasic.CompilerServices.Operators.CompareString(LocalizedStrings.string_0, "PortBra", false) != 0))
          return;
        int num4 = (int) Interaction.MsgBox((object) "Fill up everything!!", MsgBoxStyle.OkOnly, (object) null);
      }
    }

    private void AccountMaker_Closing(object sender, CancelEventArgs e)
    {
      IniHelper.smethod_47();
      PJMaker.DefInstance.Close();
      StatsMaker.DefInstance.Close();
    }

    private void Clases_SelectedIndexChanged(object sender, EventArgs e)
    {
      this.Buscar.Focus();
      this.Buscar.Select();
    }

    private void Reloj_Tick(object sender, EventArgs e)
    {
      new Thread(new ThreadStart(AccountStatusManager.smethod_0))
      {
        IsBackground = true
      }.Start();
      if (AccountData.CurrentAccount.bool_0)
      {
        this.OnlineOFF.Hide();
        this.OnlineON.Show();
      }
      else
      {
        this.OnlineOFF.Show();
        this.OnlineON.Hide();
      }
    }

    private void method_40(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Buscar.BackgroundImage = (Image) EmbeddedResources.smethod_12();
    }

    private void method_41(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Buscar.BackgroundImage = (Image) EmbeddedResources.smethod_13();
    }

    private void method_42(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Reload.BackgroundImage = (Image) EmbeddedResources.smethod_100();
    }

    private void method_43(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Reload.BackgroundImage = (Image) EmbeddedResources.smethod_101();
    }

    private void method_44(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BorrarDatos.BackgroundImage = (Image) EmbeddedResources.smethod_36();
    }

    private void method_45(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BorrarDatos.BackgroundImage = (Image) EmbeddedResources.smethod_37();
    }

    private void method_46(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.CrearAccount.BackgroundImage = (Image) EmbeddedResources.smethod_50();
    }

    private void method_47(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.CrearAccount.BackgroundImage = (Image) EmbeddedResources.smethod_51();
    }

    private void method_48(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.CreatePj.BackgroundImage = (Image) EmbeddedResources.smethod_50();
    }

    private void method_49(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.CreatePj.BackgroundImage = (Image) EmbeddedResources.smethod_51();
    }

    private void method_50(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Aplicar.BackgroundImage = (Image) EmbeddedResources.smethod_90();
    }

    private void method_51(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Aplicar.BackgroundImage = (Image) EmbeddedResources.smethod_91();
    }

    private void method_52(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.ResetDefault.BackgroundImage = (Image) EmbeddedResources.smethod_117();
    }

    private void method_53(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.ResetDefault.BackgroundImage = (Image) EmbeddedResources.smethod_118();
    }

    private void method_54(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.EditDefault.BackgroundImage = (Image) EmbeddedResources.smethod_14();
    }

    private void method_55(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.EditDefault.BackgroundImage = (Image) EmbeddedResources.smethod_15();
    }

    private void method_56(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.AccountEdit.BackgroundImage = (Image) EmbeddedResources.smethod_90();
    }

    private void method_57(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.AccountEdit.BackgroundImage = (Image) EmbeddedResources.smethod_91();
    }

    private void method_58(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BorrarCuenta.BackgroundImage = (Image) EmbeddedResources.smethod_53();
    }

    private void method_59(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BorrarCuenta.BackgroundImage = (Image) EmbeddedResources.smethod_54();
    }

    private void method_60(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonItemMaker.BackgroundImage = (Image) EmbeddedResources.smethod_20();
    }

    private void method_61(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonItemMaker.BackgroundImage = (Image) EmbeddedResources.smethod_21();
    }

    private void method_62(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonSkillMaker.BackgroundImage = (Image) EmbeddedResources.smethod_29();
    }

    private void method_63(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonSkillMaker.BackgroundImage = (Image) EmbeddedResources.smethod_30();
    }

    private void method_64(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonGuildMaker.BackgroundImage = (Image) EmbeddedResources.smethod_18();
    }

    private void method_65(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonGuildMaker.BackgroundImage = (Image) EmbeddedResources.smethod_19();
    }

    private void method_66(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonMoveMaker.BackgroundImage = (Image) EmbeddedResources.smethod_24();
    }

    private void method_67(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonMoveMaker.BackgroundImage = (Image) EmbeddedResources.smethod_25();
    }

    private void method_68(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Minimizar.BackgroundImage = (Image) EmbeddedResources.smethod_86();
    }

    private void method_69(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Minimizar.BackgroundImage = (Image) EmbeddedResources.smethod_87();
    }

    private void method_70(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) EmbeddedResources.smethod_39();
    }

    private void method_71(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) EmbeddedResources.smethod_40();
    }
  }
}
