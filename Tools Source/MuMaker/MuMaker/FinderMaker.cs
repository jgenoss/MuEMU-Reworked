// Decompiled with JetBrains decompiler
// Type: MuMaker.FinderMaker
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
  public class FinderMaker : Form
  {
    private static FinderMaker finderMaker_0 = (FinderMaker) null;
    private IContainer icontainer_0;
    [AccessedThroughProperty("Tipo2")]
    private ListBox _Tipo2;
    [AccessedThroughProperty("Tipo1")]
    private ListBox _Tipo1;
    [AccessedThroughProperty("Foto")]
    private Label _Foto;
    [AccessedThroughProperty("Label17")]
    private Label _Label17;
    [AccessedThroughProperty("JoHOPs")]
    private ComboBox _JoHOPs;
    [AccessedThroughProperty("JoHOP")]
    private ComboBox _JoHOP;
    [AccessedThroughProperty("JHOP")]
    private CheckBox _JHOP;
    [AccessedThroughProperty("RF1")]
    private Label _RF1;
    [AccessedThroughProperty("RF2")]
    private Label _RF2;
    [AccessedThroughProperty("Reloj")]
    private System.Windows.Forms.Timer timer_0;
    [AccessedThroughProperty("Label6")]
    private Label _Label6;
    [AccessedThroughProperty("EXE6")]
    private CheckBox _EXE6;
    [AccessedThroughProperty("EXE4")]
    private CheckBox _EXE4;
    [AccessedThroughProperty("EXE5")]
    private CheckBox _EXE5;
    [AccessedThroughProperty("EXE3")]
    private CheckBox _EXE3;
    [AccessedThroughProperty("EXE2")]
    private CheckBox _EXE2;
    [AccessedThroughProperty("EXE1")]
    private CheckBox _EXE1;
    [AccessedThroughProperty("Emergente")]
    private ToolTip toolTip_0;
    [AccessedThroughProperty("Label18")]
    private Label _Label18;
    [AccessedThroughProperty("Codigo")]
    private TextBox _Codigo;
    [AccessedThroughProperty("Serial")]
    private TextBox _Serial;
    [AccessedThroughProperty("Dur")]
    private TextBox _Dur;
    [AccessedThroughProperty("Siz")]
    private TextBox _Siz;
    [AccessedThroughProperty("Label13")]
    private Label _Label13;
    [AccessedThroughProperty("Label12")]
    private Label _Label12;
    [AccessedThroughProperty("Label8")]
    private Label _Label8;
    [AccessedThroughProperty("Label3")]
    private Label _Label3;
    [AccessedThroughProperty("Nombre")]
    private TextBox _Nombre;
    [AccessedThroughProperty("Label10")]
    private Label _Label10;
    [AccessedThroughProperty("Label9")]
    private Label _Label9;
    [AccessedThroughProperty("Imagen")]
    private PictureBox _Imagen;
    [AccessedThroughProperty("Opcion")]
    private ListBox _Opcion;
    [AccessedThroughProperty("Level")]
    private ListBox _Level;
    [AccessedThroughProperty("Numero")]
    private ComboBox _Numero;
    [AccessedThroughProperty("Label23")]
    private Label _Label23;
    [AccessedThroughProperty("Ancient1")]
    private RadioButton _Ancient1;
    [AccessedThroughProperty("NoAncient")]
    private RadioButton _NoAncient;
    [AccessedThroughProperty("Level2")]
    private Label _Level2;
    [AccessedThroughProperty("Opcion2")]
    private Label _Opcion2;
    [AccessedThroughProperty("Items")]
    private ListBox _Items;
    [AccessedThroughProperty("Label7")]
    private Label _Label7;
    [AccessedThroughProperty("Luck")]
    private CheckBox _Luck;
    [AccessedThroughProperty("Skill")]
    private CheckBox _Skill;
    [AccessedThroughProperty("Label5")]
    private Label _Label5;
    [AccessedThroughProperty("Ancient2")]
    private RadioButton _Ancient2;
    [AccessedThroughProperty("Label4")]
    private Label _Label4;
    [AccessedThroughProperty("SetAncient")]
    private Label _SetAncient;
    [AccessedThroughProperty("Siz2")]
    private Label _Siz2;
    [AccessedThroughProperty("Dur2")]
    private Label _Dur2;
    [AccessedThroughProperty("RF")]
    private CheckBox _RF;
    [AccessedThroughProperty("Label19")]
    private Label _Label19;
    [AccessedThroughProperty("Minimizar")]
    private Button _Minimizar;
    [AccessedThroughProperty("Cerrar")]
    private Button _Cerrar;
    [AccessedThroughProperty("Titulo")]
    private Label _Titulo;
    [AccessedThroughProperty("Label1")]
    private Label _Label1;
    [AccessedThroughProperty("Label2")]
    private Label _Label2;
    [AccessedThroughProperty("Label14")]
    private Label _Label14;
    [AccessedThroughProperty("BoxItemFinder")]
    private GroupBox _BoxItemFinder;
    [AccessedThroughProperty("StopSearch")]
    private Button _StopSearch;
    [AccessedThroughProperty("StatusBar")]
    private StatusBar _StatusBar;
    [AccessedThroughProperty("Cuentas")]
    private StatusBarPanel _Cuentas;
    [AccessedThroughProperty("TextLoad1")]
    private StatusBarPanel _TextLoad1;
    [AccessedThroughProperty("TextLoad2")]
    private StatusBarPanel _TextLoad2;
    [AccessedThroughProperty("Label11")]
    private Label _Label11;
    [AccessedThroughProperty("SerialSearch")]
    private TextBox _SerialSearch;
    [AccessedThroughProperty("BuscarSerial")]
    private Button _BuscarSerial;
    [AccessedThroughProperty("Label15")]
    private Label _Label15;
    [AccessedThroughProperty("ItemCodeSearch")]
    private TextBox _ItemCodeSearch;
    [AccessedThroughProperty("ItemCode")]
    private TextBox _ItemCode;
    [AccessedThroughProperty("ItemSerial")]
    private TextBox _ItemSerial;
    [AccessedThroughProperty("ItemName")]
    private TextBox _ItemName;
    [AccessedThroughProperty("Cuenta1")]
    private TextBox _Cuenta1;
    [AccessedThroughProperty("Personaje1")]
    private TextBox _Personaje1;
    [AccessedThroughProperty("Label24")]
    private Label _Label24;
    [AccessedThroughProperty("RadioExtra")]
    private RadioButton _RadioExtra;
    [AccessedThroughProperty("Label27")]
    private Label _Label27;
    [AccessedThroughProperty("RadioVault")]
    private RadioButton _RadioVault;
    [AccessedThroughProperty("Label29")]
    private Label _Label29;
    [AccessedThroughProperty("Label28")]
    private Label _Label28;
    [AccessedThroughProperty("RadioInvent")]
    private RadioButton _RadioInvent;
    [AccessedThroughProperty("Label16")]
    private Label _Label16;
    [AccessedThroughProperty("N3")]
    private CheckBox _N3;
    [AccessedThroughProperty("S3")]
    private CheckBox _S3;
    [AccessedThroughProperty("Label20")]
    private Label _Label20;
    [AccessedThroughProperty("N2")]
    private CheckBox _N2;
    [AccessedThroughProperty("S2")]
    private CheckBox _S2;
    [AccessedThroughProperty("Extra")]
    private CheckBox _Extra;
    [AccessedThroughProperty("BuscarCode")]
    private Button _BuscarCode;
    [AccessedThroughProperty("Label31")]
    private Label _Label31;
    [AccessedThroughProperty("Label32")]
    private Label _Label32;
    [AccessedThroughProperty("AllSerials")]
    private CheckBox _AllSerials;
    [AccessedThroughProperty("S5")]
    private CheckBox _S5;
    [AccessedThroughProperty("Account1")]
    private Label _Account1;
    [AccessedThroughProperty("Chart1")]
    private Label _Chart1;
    [AccessedThroughProperty("Invent")]
    private CheckBox _Invent;
    [AccessedThroughProperty("Vault")]
    private CheckBox _Vault;
    [AccessedThroughProperty("Label36")]
    private Label _Label36;
    [AccessedThroughProperty("CuentasDupe")]
    private ListBox _CuentasDupe;
    [AccessedThroughProperty("InfracAccount")]
    private Label _InfracAccount;
    [AccessedThroughProperty("RelatedAccount")]
    private Label _RelatedAccount;
    [AccessedThroughProperty("N5")]
    private CheckBox _N5;
    [AccessedThroughProperty("N1")]
    private CheckBox _N1;
    [AccessedThroughProperty("S1")]
    private CheckBox _S1;
    [AccessedThroughProperty("Label38")]
    private Label _Label38;
    [AccessedThroughProperty("Label39")]
    private Label _Label39;
    [AccessedThroughProperty("Label40")]
    private Label _Label40;
    [AccessedThroughProperty("CargaParcial")]
    private ProgressBar _CargaParcial;
    [AccessedThroughProperty("CargaTotal")]
    private ProgressBar _CargaTotal;
    [AccessedThroughProperty("ImagenItemFound")]
    private PictureBox _ImagenItemFound;
    [AccessedThroughProperty("TIPS")]
    private Label _TIPS;
    [AccessedThroughProperty("BotonFullEXE")]
    private Button _BotonFullEXE;
    [AccessedThroughProperty("GroupBox1")]
    private GroupBox _GroupBox1;
    [AccessedThroughProperty("GroupBox2")]
    private GroupBox _GroupBox2;
    [AccessedThroughProperty("BotonFull380")]
    private Button _BotonFull380;
    [AccessedThroughProperty("GroupBox3")]
    private GroupBox _GroupBox3;
    [AccessedThroughProperty("BotonFullJoH")]
    private Button _BotonFullJoH;
    [AccessedThroughProperty("GroupBox4")]
    private GroupBox _GroupBox4;
    [AccessedThroughProperty("BotonFullSK")]
    private Button _BotonFullSK;
    [AccessedThroughProperty("GroupBox5")]
    private GroupBox _GroupBox5;
    [AccessedThroughProperty("BotonEXEANC")]
    private Button _BotonEXEANC;
    [AccessedThroughProperty("Label25")]
    private Label _Label25;
    [AccessedThroughProperty("Label43")]
    private Label _Label43;
    [AccessedThroughProperty("Clean")]
    private Button _Clean;
    [AccessedThroughProperty("Seleccionado")]
    private Button _Seleccionado;
    [AccessedThroughProperty("Todos")]
    private Button _Todos;
    [AccessedThroughProperty("Label21")]
    private Label _Label21;
    [AccessedThroughProperty("Label22")]
    private Label _Label22;
    [AccessedThroughProperty("Label30")]
    private Label _Label30;
    [AccessedThroughProperty("CapaCodeOculto")]
    private GroupBox _CapaCodeOculto;
    [AccessedThroughProperty("PJDupe")]
    private ListBox _PJDupe;
    [AccessedThroughProperty("Pos")]
    private ListBox _Pos;
    [AccessedThroughProperty("CodeItems")]
    private ListBox _CodeItems;
    [AccessedThroughProperty("Status")]
    private StatusBarPanel _Status;
    [AccessedThroughProperty("S4")]
    private CheckBox _S4;
    [AccessedThroughProperty("N4")]
    private CheckBox _N4;
    [AccessedThroughProperty("Label26")]
    private Label _Label26;
    [AccessedThroughProperty("Socket3")]
    private ComboBox _Socket3;
    [AccessedThroughProperty("Socket5")]
    private ComboBox _Socket5;
    [AccessedThroughProperty("Socket2")]
    private ComboBox _Socket2;
    [AccessedThroughProperty("Socket4")]
    private ComboBox _Socket4;
    [AccessedThroughProperty("Socket1")]
    private ComboBox _Socket1;
    [AccessedThroughProperty("SocketSystem")]
    private CheckBox _SocketSystem;
    private const int int_0 = 132;
    private const int int_1 = 1;
    private const int int_2 = 2;

    internal virtual ListBox Tipo2
    {
      [DebuggerNonUserCode] get
      {
        return this._Tipo2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Tipo2_SelectedIndexChanged);
        if (this._Tipo2 != null)
          this._Tipo2.SelectedIndexChanged -= eventHandler;
        this._Tipo2 = value;
        if (this._Tipo2 == null)
          return;
        this._Tipo2.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual ListBox Tipo1
    {
      [DebuggerNonUserCode] get
      {
        return this._Tipo1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Tipo1_SelectedIndexChanged);
        if (this._Tipo1 != null)
          this._Tipo1.SelectedIndexChanged -= eventHandler;
        this._Tipo1 = value;
        if (this._Tipo1 == null)
          return;
        this._Tipo1.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual Label Foto
    {
      [DebuggerNonUserCode] get
      {
        return this._Foto;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Foto = value;
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

    internal virtual ComboBox JoHOPs
    {
      [DebuggerNonUserCode] get
      {
        return this._JoHOPs;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.JoHOPs_SelectedIndexChanged);
        if (this._JoHOPs != null)
          this._JoHOPs.SelectedIndexChanged -= eventHandler;
        this._JoHOPs = value;
        if (this._JoHOPs == null)
          return;
        this._JoHOPs.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual ComboBox JoHOP
    {
      [DebuggerNonUserCode] get
      {
        return this._JoHOP;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.JoHOP_SelectedIndexChanged);
        if (this._JoHOP != null)
          this._JoHOP.SelectedIndexChanged -= eventHandler;
        this._JoHOP = value;
        if (this._JoHOP == null)
          return;
        this._JoHOP.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual CheckBox JHOP
    {
      [DebuggerNonUserCode] get
      {
        return this._JHOP;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.JHOP_CheckedChanged);
        if (this._JHOP != null)
          this._JHOP.CheckedChanged -= eventHandler;
        this._JHOP = value;
        if (this._JHOP == null)
          return;
        this._JHOP.CheckedChanged += eventHandler;
      }
    }

    internal virtual Label RF1
    {
      [DebuggerNonUserCode] get
      {
        return this._RF1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._RF1 = value;
      }
    }

    internal virtual Label RF2
    {
      [DebuggerNonUserCode] get
      {
        return this._RF2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._RF2 = value;
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
        this.timer_0 = value;
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

    internal virtual CheckBox EXE6
    {
      [DebuggerNonUserCode] get
      {
        return this._EXE6;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.EXE6_CheckedChanged);
        if (this._EXE6 != null)
          this._EXE6.CheckedChanged -= eventHandler;
        this._EXE6 = value;
        if (this._EXE6 == null)
          return;
        this._EXE6.CheckedChanged += eventHandler;
      }
    }

    internal virtual CheckBox EXE4
    {
      [DebuggerNonUserCode] get
      {
        return this._EXE4;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.EXE4_CheckedChanged);
        if (this._EXE4 != null)
          this._EXE4.CheckedChanged -= eventHandler;
        this._EXE4 = value;
        if (this._EXE4 == null)
          return;
        this._EXE4.CheckedChanged += eventHandler;
      }
    }

    internal virtual CheckBox EXE5
    {
      [DebuggerNonUserCode] get
      {
        return this._EXE5;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.EXE5_CheckedChanged);
        if (this._EXE5 != null)
          this._EXE5.CheckedChanged -= eventHandler;
        this._EXE5 = value;
        if (this._EXE5 == null)
          return;
        this._EXE5.CheckedChanged += eventHandler;
      }
    }

    internal virtual CheckBox EXE3
    {
      [DebuggerNonUserCode] get
      {
        return this._EXE3;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.EXE3_CheckedChanged);
        if (this._EXE3 != null)
          this._EXE3.CheckedChanged -= eventHandler;
        this._EXE3 = value;
        if (this._EXE3 == null)
          return;
        this._EXE3.CheckedChanged += eventHandler;
      }
    }

    internal virtual CheckBox EXE2
    {
      [DebuggerNonUserCode] get
      {
        return this._EXE2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.EXE2_CheckedChanged);
        if (this._EXE2 != null)
          this._EXE2.CheckedChanged -= eventHandler;
        this._EXE2 = value;
        if (this._EXE2 == null)
          return;
        this._EXE2.CheckedChanged += eventHandler;
      }
    }

    internal virtual CheckBox EXE1
    {
      [DebuggerNonUserCode] get
      {
        return this._EXE1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.EXE1_CheckedChanged);
        if (this._EXE1 != null)
          this._EXE1.CheckedChanged -= eventHandler;
        this._EXE1 = value;
        if (this._EXE1 == null)
          return;
        this._EXE1.CheckedChanged += eventHandler;
      }
    }

    internal virtual ToolTip Emergente
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

    internal virtual TextBox Codigo
    {
      [DebuggerNonUserCode] get
      {
        return this._Codigo;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Codigo_TextChanged);
        if (this._Codigo != null)
          this._Codigo.TextChanged -= eventHandler;
        this._Codigo = value;
        if (this._Codigo == null)
          return;
        this._Codigo.TextChanged += eventHandler;
      }
    }

    internal virtual TextBox Serial
    {
      [DebuggerNonUserCode] get
      {
        return this._Serial;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.method_4);
        EventHandler eventHandler1 = new EventHandler(this.method_3);
        EventHandler eventHandler2 = new EventHandler(this.method_2);
        EventHandler eventHandler3 = new EventHandler(this.method_1);
        if (this._Serial != null)
        {
          this._Serial.KeyPress -= pressEventHandler;
          this._Serial.LostFocus -= eventHandler1;
          this._Serial.Click -= eventHandler2;
          this._Serial.TextChanged -= eventHandler3;
        }
        this._Serial = value;
        if (this._Serial == null)
          return;
        this._Serial.KeyPress += pressEventHandler;
        this._Serial.LostFocus += eventHandler1;
        this._Serial.Click += eventHandler2;
        this._Serial.TextChanged += eventHandler3;
      }
    }

    internal virtual TextBox Dur
    {
      [DebuggerNonUserCode] get
      {
        return this._Dur;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Dur = value;
      }
    }

    internal virtual TextBox Siz
    {
      [DebuggerNonUserCode] get
      {
        return this._Siz;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Siz = value;
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

    internal virtual TextBox Nombre
    {
      [DebuggerNonUserCode] get
      {
        return this._Nombre;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Nombre = value;
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

    internal virtual PictureBox Imagen
    {
      [DebuggerNonUserCode] get
      {
        return this._Imagen;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Imagen = value;
      }
    }

    internal virtual ListBox Opcion
    {
      [DebuggerNonUserCode] get
      {
        return this._Opcion;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Opcion_SelectedIndexChanged);
        if (this._Opcion != null)
          this._Opcion.SelectedIndexChanged -= eventHandler;
        this._Opcion = value;
        if (this._Opcion == null)
          return;
        this._Opcion.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual ListBox Level
    {
      [DebuggerNonUserCode] get
      {
        return this._Level;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Level_SelectedIndexChanged);
        if (this._Level != null)
          this._Level.SelectedIndexChanged -= eventHandler;
        this._Level = value;
        if (this._Level == null)
          return;
        this._Level.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual ComboBox Numero
    {
      [DebuggerNonUserCode] get
      {
        return this._Numero;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Numero_SelectedIndexChanged);
        if (this._Numero != null)
          this._Numero.SelectedIndexChanged -= eventHandler;
        this._Numero = value;
        if (this._Numero == null)
          return;
        this._Numero.SelectedIndexChanged += eventHandler;
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

    internal virtual RadioButton Ancient1
    {
      [DebuggerNonUserCode] get
      {
        return this._Ancient1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Ancient1_CheckedChanged);
        if (this._Ancient1 != null)
          this._Ancient1.CheckedChanged -= eventHandler;
        this._Ancient1 = value;
        if (this._Ancient1 == null)
          return;
        this._Ancient1.CheckedChanged += eventHandler;
      }
    }

    internal virtual RadioButton NoAncient
    {
      [DebuggerNonUserCode] get
      {
        return this._NoAncient;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.NoAncient_CheckedChanged);
        if (this._NoAncient != null)
          this._NoAncient.CheckedChanged -= eventHandler;
        this._NoAncient = value;
        if (this._NoAncient == null)
          return;
        this._NoAncient.CheckedChanged += eventHandler;
      }
    }

    internal virtual Label Level2
    {
      [DebuggerNonUserCode] get
      {
        return this._Level2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Level2 = value;
      }
    }

    internal virtual Label Opcion2
    {
      [DebuggerNonUserCode] get
      {
        return this._Opcion2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Opcion2 = value;
      }
    }

    internal virtual ListBox Items
    {
      [DebuggerNonUserCode] get
      {
        return this._Items;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Items_SelectedIndexChanged);
        if (this._Items != null)
          this._Items.SelectedIndexChanged -= eventHandler;
        this._Items = value;
        if (this._Items == null)
          return;
        this._Items.SelectedIndexChanged += eventHandler;
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

    internal virtual CheckBox Luck
    {
      [DebuggerNonUserCode] get
      {
        return this._Luck;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Luck_CheckedChanged);
        if (this._Luck != null)
          this._Luck.CheckedChanged -= eventHandler;
        this._Luck = value;
        if (this._Luck == null)
          return;
        this._Luck.CheckedChanged += eventHandler;
      }
    }

    internal virtual CheckBox Skill
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill_CheckedChanged);
        if (this._Skill != null)
          this._Skill.CheckedChanged -= eventHandler;
        this._Skill = value;
        if (this._Skill == null)
          return;
        this._Skill.CheckedChanged += eventHandler;
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

    internal virtual RadioButton Ancient2
    {
      [DebuggerNonUserCode] get
      {
        return this._Ancient2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Ancient2_CheckedChanged);
        if (this._Ancient2 != null)
          this._Ancient2.CheckedChanged -= eventHandler;
        this._Ancient2 = value;
        if (this._Ancient2 == null)
          return;
        this._Ancient2.CheckedChanged += eventHandler;
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

    internal virtual Label SetAncient
    {
      [DebuggerNonUserCode] get
      {
        return this._SetAncient;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._SetAncient = value;
      }
    }

    internal virtual Label Siz2
    {
      [DebuggerNonUserCode] get
      {
        return this._Siz2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Siz2 = value;
      }
    }

    internal virtual Label Dur2
    {
      [DebuggerNonUserCode] get
      {
        return this._Dur2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Dur2 = value;
      }
    }

    internal virtual CheckBox RF
    {
      [DebuggerNonUserCode] get
      {
        return this._RF;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.RF_CheckedChanged);
        if (this._RF != null)
          this._RF.CheckedChanged -= eventHandler;
        this._RF = value;
        if (this._RF == null)
          return;
        this._RF.CheckedChanged += eventHandler;
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

    internal virtual Button Minimizar
    {
      [DebuggerNonUserCode] get
      {
        return this._Minimizar;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_16);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_19);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_18);
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
        EventHandler eventHandler = new EventHandler(this.method_17);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_21);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_20);
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

    internal virtual GroupBox BoxItemFinder
    {
      [DebuggerNonUserCode] get
      {
        return this._BoxItemFinder;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._BoxItemFinder = value;
      }
    }

    internal virtual Button StopSearch
    {
      [DebuggerNonUserCode] get
      {
        return this._StopSearch;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.StopSearch_Click);
        if (this._StopSearch != null)
          this._StopSearch.Click -= eventHandler;
        this._StopSearch = value;
        if (this._StopSearch == null)
          return;
        this._StopSearch.Click += eventHandler;
      }
    }

    internal virtual StatusBar StatusBar
    {
      [DebuggerNonUserCode] get
      {
        return this._StatusBar;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._StatusBar = value;
      }
    }

    internal virtual StatusBarPanel Cuentas
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

    internal virtual StatusBarPanel TextLoad1
    {
      [DebuggerNonUserCode] get
      {
        return this._TextLoad1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._TextLoad1 = value;
      }
    }

    internal virtual StatusBarPanel TextLoad2
    {
      [DebuggerNonUserCode] get
      {
        return this._TextLoad2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._TextLoad2 = value;
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

    internal virtual TextBox SerialSearch
    {
      [DebuggerNonUserCode] get
      {
        return this._SerialSearch;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._SerialSearch = value;
      }
    }

    internal virtual Button BuscarSerial
    {
      [DebuggerNonUserCode] get
      {
        return this._BuscarSerial;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_47);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_46);
        EventHandler eventHandler = new EventHandler(this.method_14);
        if (this._BuscarSerial != null)
        {
          this._BuscarSerial.MouseDown -= mouseEventHandler1;
          this._BuscarSerial.MouseUp -= mouseEventHandler2;
          this._BuscarSerial.Click -= eventHandler;
        }
        this._BuscarSerial = value;
        if (this._BuscarSerial == null)
          return;
        this._BuscarSerial.MouseDown += mouseEventHandler1;
        this._BuscarSerial.MouseUp += mouseEventHandler2;
        this._BuscarSerial.Click += eventHandler;
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

    internal virtual TextBox ItemCodeSearch
    {
      [DebuggerNonUserCode] get
      {
        return this._ItemCodeSearch;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._ItemCodeSearch = value;
      }
    }

    internal virtual TextBox ItemCode
    {
      [DebuggerNonUserCode] get
      {
        return this._ItemCode;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._ItemCode = value;
      }
    }

    internal virtual TextBox ItemSerial
    {
      [DebuggerNonUserCode] get
      {
        return this._ItemSerial;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._ItemSerial = value;
      }
    }

    internal virtual TextBox ItemName
    {
      [DebuggerNonUserCode] get
      {
        return this._ItemName;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._ItemName = value;
      }
    }

    internal virtual TextBox Cuenta1
    {
      [DebuggerNonUserCode] get
      {
        return this._Cuenta1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Cuenta1 = value;
      }
    }

    internal virtual TextBox Personaje1
    {
      [DebuggerNonUserCode] get
      {
        return this._Personaje1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Personaje1 = value;
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

    internal virtual RadioButton RadioExtra
    {
      [DebuggerNonUserCode] get
      {
        return this._RadioExtra;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._RadioExtra = value;
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

    internal virtual RadioButton RadioVault
    {
      [DebuggerNonUserCode] get
      {
        return this._RadioVault;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._RadioVault = value;
      }
    }

    internal virtual Label Label29
    {
      [DebuggerNonUserCode] get
      {
        return this._Label29;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label29 = value;
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

    internal virtual RadioButton RadioInvent
    {
      [DebuggerNonUserCode] get
      {
        return this._RadioInvent;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._RadioInvent = value;
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

    internal virtual CheckBox N3
    {
      [DebuggerNonUserCode] get
      {
        return this._N3;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._N3 = value;
      }
    }

    internal virtual CheckBox S3
    {
      [DebuggerNonUserCode] get
      {
        return this._S3;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._S3 = value;
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

    internal virtual CheckBox N2
    {
      [DebuggerNonUserCode] get
      {
        return this._N2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._N2 = value;
      }
    }

    internal virtual CheckBox S2
    {
      [DebuggerNonUserCode] get
      {
        return this._S2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._S2 = value;
      }
    }

    internal virtual CheckBox Extra
    {
      [DebuggerNonUserCode] get
      {
        return this._Extra;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_43);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_42);
        if (this._Extra != null)
        {
          this._Extra.MouseDown -= mouseEventHandler1;
          this._Extra.MouseUp -= mouseEventHandler2;
        }
        this._Extra = value;
        if (this._Extra == null)
          return;
        this._Extra.MouseDown += mouseEventHandler1;
        this._Extra.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual Button BuscarCode
    {
      [DebuggerNonUserCode] get
      {
        return this._BuscarCode;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_45);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_44);
        EventHandler eventHandler = new EventHandler(this.method_15);
        if (this._BuscarCode != null)
        {
          this._BuscarCode.MouseDown -= mouseEventHandler1;
          this._BuscarCode.MouseUp -= mouseEventHandler2;
          this._BuscarCode.Click -= eventHandler;
        }
        this._BuscarCode = value;
        if (this._BuscarCode == null)
          return;
        this._BuscarCode.MouseDown += mouseEventHandler1;
        this._BuscarCode.MouseUp += mouseEventHandler2;
        this._BuscarCode.Click += eventHandler;
      }
    }

    internal virtual Label Label31
    {
      [DebuggerNonUserCode] get
      {
        return this._Label31;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label31 = value;
      }
    }

    internal virtual Label Label32
    {
      [DebuggerNonUserCode] get
      {
        return this._Label32;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label32 = value;
      }
    }

    internal virtual CheckBox AllSerials
    {
      [DebuggerNonUserCode] get
      {
        return this._AllSerials;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.AllSerials_CheckedChanged);
        if (this._AllSerials != null)
          this._AllSerials.CheckedChanged -= eventHandler;
        this._AllSerials = value;
        if (this._AllSerials == null)
          return;
        this._AllSerials.CheckedChanged += eventHandler;
      }
    }

    internal virtual CheckBox S5
    {
      [DebuggerNonUserCode] get
      {
        return this._S5;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._S5 = value;
      }
    }

    internal virtual Label Account1
    {
      [DebuggerNonUserCode] get
      {
        return this._Account1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Account1 = value;
      }
    }

    internal virtual Label Chart1
    {
      [DebuggerNonUserCode] get
      {
        return this._Chart1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Chart1 = value;
      }
    }

    internal virtual CheckBox Invent
    {
      [DebuggerNonUserCode] get
      {
        return this._Invent;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_39);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_38);
        if (this._Invent != null)
        {
          this._Invent.MouseDown -= mouseEventHandler1;
          this._Invent.MouseUp -= mouseEventHandler2;
        }
        this._Invent = value;
        if (this._Invent == null)
          return;
        this._Invent.MouseDown += mouseEventHandler1;
        this._Invent.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual CheckBox Vault
    {
      [DebuggerNonUserCode] get
      {
        return this._Vault;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_41);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_40);
        if (this._Vault != null)
        {
          this._Vault.MouseDown -= mouseEventHandler1;
          this._Vault.MouseUp -= mouseEventHandler2;
        }
        this._Vault = value;
        if (this._Vault == null)
          return;
        this._Vault.MouseDown += mouseEventHandler1;
        this._Vault.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual Label Label36
    {
      [DebuggerNonUserCode] get
      {
        return this._Label36;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label36 = value;
      }
    }

    internal virtual ListBox CuentasDupe
    {
      [DebuggerNonUserCode] get
      {
        return this._CuentasDupe;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CuentasDupe_SelectedIndexChanged);
        if (this._CuentasDupe != null)
          this._CuentasDupe.SelectedIndexChanged -= eventHandler;
        this._CuentasDupe = value;
        if (this._CuentasDupe == null)
          return;
        this._CuentasDupe.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual Label InfracAccount
    {
      [DebuggerNonUserCode] get
      {
        return this._InfracAccount;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._InfracAccount = value;
      }
    }

    internal virtual Label RelatedAccount
    {
      [DebuggerNonUserCode] get
      {
        return this._RelatedAccount;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._RelatedAccount = value;
      }
    }

    internal virtual CheckBox N5
    {
      [DebuggerNonUserCode] get
      {
        return this._N5;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._N5 = value;
      }
    }

    internal virtual CheckBox N1
    {
      [DebuggerNonUserCode] get
      {
        return this._N1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._N1 = value;
      }
    }

    internal virtual CheckBox S1
    {
      [DebuggerNonUserCode] get
      {
        return this._S1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._S1 = value;
      }
    }

    internal virtual Label Label38
    {
      [DebuggerNonUserCode] get
      {
        return this._Label38;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label38 = value;
      }
    }

    internal virtual Label Label39
    {
      [DebuggerNonUserCode] get
      {
        return this._Label39;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label39 = value;
      }
    }

    internal virtual Label Label40
    {
      [DebuggerNonUserCode] get
      {
        return this._Label40;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label40 = value;
      }
    }

    internal virtual ProgressBar CargaParcial
    {
      [DebuggerNonUserCode] get
      {
        return this._CargaParcial;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._CargaParcial = value;
      }
    }

    internal virtual ProgressBar CargaTotal
    {
      [DebuggerNonUserCode] get
      {
        return this._CargaTotal;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._CargaTotal = value;
      }
    }

    internal virtual PictureBox ImagenItemFound
    {
      [DebuggerNonUserCode] get
      {
        return this._ImagenItemFound;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._ImagenItemFound = value;
      }
    }

    internal virtual Label TIPS
    {
      [DebuggerNonUserCode] get
      {
        return this._TIPS;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._TIPS = value;
      }
    }

    internal virtual Button BotonFullEXE
    {
      [DebuggerNonUserCode] get
      {
        return this._BotonFullEXE;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_23);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_22);
        EventHandler eventHandler = new EventHandler(this.method_9);
        if (this._BotonFullEXE != null)
        {
          this._BotonFullEXE.MouseDown -= mouseEventHandler1;
          this._BotonFullEXE.MouseUp -= mouseEventHandler2;
          this._BotonFullEXE.Click -= eventHandler;
        }
        this._BotonFullEXE = value;
        if (this._BotonFullEXE == null)
          return;
        this._BotonFullEXE.MouseDown += mouseEventHandler1;
        this._BotonFullEXE.MouseUp += mouseEventHandler2;
        this._BotonFullEXE.Click += eventHandler;
      }
    }

    internal virtual GroupBox GroupBox1
    {
      [DebuggerNonUserCode] get
      {
        return this._GroupBox1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._GroupBox1 = value;
      }
    }

    internal virtual GroupBox GroupBox2
    {
      [DebuggerNonUserCode] get
      {
        return this._GroupBox2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._GroupBox2 = value;
      }
    }

    internal virtual Button BotonFull380
    {
      [DebuggerNonUserCode] get
      {
        return this._BotonFull380;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_25);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_24);
        EventHandler eventHandler = new EventHandler(this.method_10);
        if (this._BotonFull380 != null)
        {
          this._BotonFull380.MouseDown -= mouseEventHandler1;
          this._BotonFull380.MouseUp -= mouseEventHandler2;
          this._BotonFull380.Click -= eventHandler;
        }
        this._BotonFull380 = value;
        if (this._BotonFull380 == null)
          return;
        this._BotonFull380.MouseDown += mouseEventHandler1;
        this._BotonFull380.MouseUp += mouseEventHandler2;
        this._BotonFull380.Click += eventHandler;
      }
    }

    internal virtual GroupBox GroupBox3
    {
      [DebuggerNonUserCode] get
      {
        return this._GroupBox3;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._GroupBox3 = value;
      }
    }

    internal virtual Button BotonFullJoH
    {
      [DebuggerNonUserCode] get
      {
        return this._BotonFullJoH;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_27);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_26);
        EventHandler eventHandler = new EventHandler(this.method_11);
        if (this._BotonFullJoH != null)
        {
          this._BotonFullJoH.MouseDown -= mouseEventHandler1;
          this._BotonFullJoH.MouseUp -= mouseEventHandler2;
          this._BotonFullJoH.Click -= eventHandler;
        }
        this._BotonFullJoH = value;
        if (this._BotonFullJoH == null)
          return;
        this._BotonFullJoH.MouseDown += mouseEventHandler1;
        this._BotonFullJoH.MouseUp += mouseEventHandler2;
        this._BotonFullJoH.Click += eventHandler;
      }
    }

    internal virtual GroupBox GroupBox4
    {
      [DebuggerNonUserCode] get
      {
        return this._GroupBox4;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._GroupBox4 = value;
      }
    }

    internal virtual Button BotonFullSK
    {
      [DebuggerNonUserCode] get
      {
        return this._BotonFullSK;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_29);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_28);
        EventHandler eventHandler = new EventHandler(this.method_12);
        if (this._BotonFullSK != null)
        {
          this._BotonFullSK.MouseDown -= mouseEventHandler1;
          this._BotonFullSK.MouseUp -= mouseEventHandler2;
          this._BotonFullSK.Click -= eventHandler;
        }
        this._BotonFullSK = value;
        if (this._BotonFullSK == null)
          return;
        this._BotonFullSK.MouseDown += mouseEventHandler1;
        this._BotonFullSK.MouseUp += mouseEventHandler2;
        this._BotonFullSK.Click += eventHandler;
      }
    }

    internal virtual GroupBox GroupBox5
    {
      [DebuggerNonUserCode] get
      {
        return this._GroupBox5;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._GroupBox5 = value;
      }
    }

    internal virtual Button BotonEXEANC
    {
      [DebuggerNonUserCode] get
      {
        return this._BotonEXEANC;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_31);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_30);
        EventHandler eventHandler = new EventHandler(this.method_13);
        if (this._BotonEXEANC != null)
        {
          this._BotonEXEANC.MouseDown -= mouseEventHandler1;
          this._BotonEXEANC.MouseUp -= mouseEventHandler2;
          this._BotonEXEANC.Click -= eventHandler;
        }
        this._BotonEXEANC = value;
        if (this._BotonEXEANC == null)
          return;
        this._BotonEXEANC.MouseDown += mouseEventHandler1;
        this._BotonEXEANC.MouseUp += mouseEventHandler2;
        this._BotonEXEANC.Click += eventHandler;
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

    internal virtual Label Label43
    {
      [DebuggerNonUserCode] get
      {
        return this._Label43;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label43 = value;
      }
    }

    internal virtual Button Clean
    {
      [DebuggerNonUserCode] get
      {
        return this._Clean;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_33);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_32);
        EventHandler eventHandler = new EventHandler(this.method_6);
        if (this._Clean != null)
        {
          this._Clean.MouseDown -= mouseEventHandler1;
          this._Clean.MouseUp -= mouseEventHandler2;
          this._Clean.Click -= eventHandler;
        }
        this._Clean = value;
        if (this._Clean == null)
          return;
        this._Clean.MouseDown += mouseEventHandler1;
        this._Clean.MouseUp += mouseEventHandler2;
        this._Clean.Click += eventHandler;
      }
    }

    internal virtual Button Seleccionado
    {
      [DebuggerNonUserCode] get
      {
        return this._Seleccionado;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_35);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_34);
        EventHandler eventHandler = new EventHandler(this.method_7);
        if (this._Seleccionado != null)
        {
          this._Seleccionado.MouseDown -= mouseEventHandler1;
          this._Seleccionado.MouseUp -= mouseEventHandler2;
          this._Seleccionado.Click -= eventHandler;
        }
        this._Seleccionado = value;
        if (this._Seleccionado == null)
          return;
        this._Seleccionado.MouseDown += mouseEventHandler1;
        this._Seleccionado.MouseUp += mouseEventHandler2;
        this._Seleccionado.Click += eventHandler;
      }
    }

    internal virtual Button Todos
    {
      [DebuggerNonUserCode] get
      {
        return this._Todos;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_37);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_36);
        EventHandler eventHandler = new EventHandler(this.method_8);
        if (this._Todos != null)
        {
          this._Todos.MouseDown -= mouseEventHandler1;
          this._Todos.MouseUp -= mouseEventHandler2;
          this._Todos.Click -= eventHandler;
        }
        this._Todos = value;
        if (this._Todos == null)
          return;
        this._Todos.MouseDown += mouseEventHandler1;
        this._Todos.MouseUp += mouseEventHandler2;
        this._Todos.Click += eventHandler;
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

    internal virtual Label Label30
    {
      [DebuggerNonUserCode] get
      {
        return this._Label30;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label30 = value;
      }
    }

    internal virtual GroupBox CapaCodeOculto
    {
      [DebuggerNonUserCode] get
      {
        return this._CapaCodeOculto;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._CapaCodeOculto = value;
      }
    }

    internal virtual ListBox PJDupe
    {
      [DebuggerNonUserCode] get
      {
        return this._PJDupe;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.PJDupe_SelectedIndexChanged);
        if (this._PJDupe != null)
          this._PJDupe.SelectedIndexChanged -= eventHandler;
        this._PJDupe = value;
        if (this._PJDupe == null)
          return;
        this._PJDupe.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual ListBox Pos
    {
      [DebuggerNonUserCode] get
      {
        return this._Pos;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Pos = value;
      }
    }

    internal virtual ListBox CodeItems
    {
      [DebuggerNonUserCode] get
      {
        return this._CodeItems;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._CodeItems = value;
      }
    }

    internal virtual StatusBarPanel Status
    {
      [DebuggerNonUserCode] get
      {
        return this._Status;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Status = value;
      }
    }

    internal virtual CheckBox S4
    {
      [DebuggerNonUserCode] get
      {
        return this._S4;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._S4 = value;
      }
    }

    internal virtual CheckBox N4
    {
      [DebuggerNonUserCode] get
      {
        return this._N4;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._N4 = value;
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

    internal virtual ComboBox Socket3
    {
      [DebuggerNonUserCode] get
      {
        return this._Socket3;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Socket3_SelectedIndexChanged);
        if (this._Socket3 != null)
          this._Socket3.SelectedIndexChanged -= eventHandler;
        this._Socket3 = value;
        if (this._Socket3 == null)
          return;
        this._Socket3.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual ComboBox Socket5
    {
      [DebuggerNonUserCode] get
      {
        return this._Socket5;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Socket5_SelectedIndexChanged);
        if (this._Socket5 != null)
          this._Socket5.SelectedIndexChanged -= eventHandler;
        this._Socket5 = value;
        if (this._Socket5 == null)
          return;
        this._Socket5.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual ComboBox Socket2
    {
      [DebuggerNonUserCode] get
      {
        return this._Socket2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Socket2_SelectedIndexChanged);
        if (this._Socket2 != null)
          this._Socket2.SelectedIndexChanged -= eventHandler;
        this._Socket2 = value;
        if (this._Socket2 == null)
          return;
        this._Socket2.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual ComboBox Socket4
    {
      [DebuggerNonUserCode] get
      {
        return this._Socket4;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Socket4_SelectedIndexChanged);
        if (this._Socket4 != null)
          this._Socket4.SelectedIndexChanged -= eventHandler;
        this._Socket4 = value;
        if (this._Socket4 == null)
          return;
        this._Socket4.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual ComboBox Socket1
    {
      [DebuggerNonUserCode] get
      {
        return this._Socket1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Socket1_SelectedIndexChanged);
        if (this._Socket1 != null)
          this._Socket1.SelectedIndexChanged -= eventHandler;
        this._Socket1 = value;
        if (this._Socket1 == null)
          return;
        this._Socket1.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual CheckBox SocketSystem
    {
      [DebuggerNonUserCode] get
      {
        return this._SocketSystem;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.SocketSystem_CheckedChanged);
        if (this._SocketSystem != null)
          this._SocketSystem.CheckedChanged -= eventHandler;
        this._SocketSystem = value;
        if (this._SocketSystem == null)
          return;
        this._SocketSystem.CheckedChanged += eventHandler;
      }
    }

    public static FinderMaker DefInstance
    {
      get
      {
        if (FinderMaker.finderMaker_0 != null && !FinderMaker.finderMaker_0.IsDisposed)
          FinderMaker.finderMaker_0.BringToFront();
        else
          FinderMaker.finderMaker_0 = new FinderMaker();
        return FinderMaker.finderMaker_0;
      }
      set
      {
        FinderMaker.finderMaker_0 = value;
      }
    }

    [DebuggerNonUserCode]
    public FinderMaker()
    {
      this.Closing += new CancelEventHandler(this.FinderMaker_Closing);
      this.Closed += new EventHandler(this.FinderMaker_Closed);
      this.Load += new EventHandler(this.FinderMaker_Load);
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
      ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof (FinderMaker));
      this.Tipo2 = new ListBox();
      this.Tipo1 = new ListBox();
      this.Foto = new Label();
      this.Label17 = new Label();
      this.JoHOPs = new ComboBox();
      this.JoHOP = new ComboBox();
      this.JHOP = new CheckBox();
      this.RF1 = new Label();
      this.RF2 = new Label();
      this.Reloj = new System.Windows.Forms.Timer(this.icontainer_0);
      this.Label6 = new Label();
      this.EXE6 = new CheckBox();
      this.EXE4 = new CheckBox();
      this.EXE5 = new CheckBox();
      this.EXE3 = new CheckBox();
      this.EXE2 = new CheckBox();
      this.EXE1 = new CheckBox();
      this.Label18 = new Label();
      this.Codigo = new TextBox();
      this.Serial = new TextBox();
      this.Dur = new TextBox();
      this.Siz = new TextBox();
      this.Label13 = new Label();
      this.Label12 = new Label();
      this.Label8 = new Label();
      this.Label3 = new Label();
      this.Nombre = new TextBox();
      this.Label10 = new Label();
      this.Label9 = new Label();
      this.Opcion = new ListBox();
      this.Level = new ListBox();
      this.Numero = new ComboBox();
      this.Label23 = new Label();
      this.Ancient1 = new RadioButton();
      this.NoAncient = new RadioButton();
      this.Level2 = new Label();
      this.Opcion2 = new Label();
      this.Items = new ListBox();
      this.Label7 = new Label();
      this.Luck = new CheckBox();
      this.Skill = new CheckBox();
      this.Label5 = new Label();
      this.Ancient2 = new RadioButton();
      this.Label4 = new Label();
      this.SetAncient = new Label();
      this.Siz2 = new Label();
      this.Dur2 = new Label();
      this.RF = new CheckBox();
      this.Emergente = new ToolTip(this.icontainer_0);
      this.Imagen = new PictureBox();
      this.Label19 = new Label();
      this.Minimizar = new Button();
      this.Cerrar = new Button();
      this.Titulo = new Label();
      this.Label1 = new Label();
      this.Label2 = new Label();
      this.Label14 = new Label();
      this.BoxItemFinder = new GroupBox();
      this.S4 = new CheckBox();
      this.N4 = new CheckBox();
      this.Label26 = new Label();
      this.StopSearch = new Button();
      this.StatusBar = new StatusBar();
      this.Cuentas = new StatusBarPanel();
      this.Status = new StatusBarPanel();
      this.TextLoad1 = new StatusBarPanel();
      this.TextLoad2 = new StatusBarPanel();
      this.PJDupe = new ListBox();
      this.Label11 = new Label();
      this.SerialSearch = new TextBox();
      this.BuscarSerial = new Button();
      this.Label15 = new Label();
      this.ItemCodeSearch = new TextBox();
      this.ItemCode = new TextBox();
      this.ItemSerial = new TextBox();
      this.ItemName = new TextBox();
      this.Cuenta1 = new TextBox();
      this.Personaje1 = new TextBox();
      this.Label24 = new Label();
      this.RadioExtra = new RadioButton();
      this.Label27 = new Label();
      this.RadioVault = new RadioButton();
      this.Label29 = new Label();
      this.Label28 = new Label();
      this.RadioInvent = new RadioButton();
      this.Label16 = new Label();
      this.N3 = new CheckBox();
      this.S3 = new CheckBox();
      this.Label20 = new Label();
      this.N2 = new CheckBox();
      this.S2 = new CheckBox();
      this.BuscarCode = new Button();
      this.Label31 = new Label();
      this.Label32 = new Label();
      this.S5 = new CheckBox();
      this.Account1 = new Label();
      this.Chart1 = new Label();
      this.Label36 = new Label();
      this.CuentasDupe = new ListBox();
      this.InfracAccount = new Label();
      this.RelatedAccount = new Label();
      this.N5 = new CheckBox();
      this.N1 = new CheckBox();
      this.S1 = new CheckBox();
      this.Label38 = new Label();
      this.Label39 = new Label();
      this.Label40 = new Label();
      this.CargaParcial = new ProgressBar();
      this.CargaTotal = new ProgressBar();
      this.ImagenItemFound = new PictureBox();
      this.TIPS = new Label();
      this.AllSerials = new CheckBox();
      this.Extra = new CheckBox();
      this.Invent = new CheckBox();
      this.Vault = new CheckBox();
      this.BotonFullEXE = new Button();
      this.GroupBox1 = new GroupBox();
      this.GroupBox2 = new GroupBox();
      this.BotonFull380 = new Button();
      this.GroupBox3 = new GroupBox();
      this.BotonFullJoH = new Button();
      this.GroupBox4 = new GroupBox();
      this.BotonFullSK = new Button();
      this.GroupBox5 = new GroupBox();
      this.BotonEXEANC = new Button();
      this.Label25 = new Label();
      this.Label43 = new Label();
      this.Clean = new Button();
      this.Seleccionado = new Button();
      this.Todos = new Button();
      this.Label21 = new Label();
      this.Label22 = new Label();
      this.Label30 = new Label();
      this.CapaCodeOculto = new GroupBox();
      this.Pos = new ListBox();
      this.CodeItems = new ListBox();
      this.Socket3 = new ComboBox();
      this.Socket5 = new ComboBox();
      this.Socket2 = new ComboBox();
      this.Socket4 = new ComboBox();
      this.Socket1 = new ComboBox();
      this.SocketSystem = new CheckBox();
      ((ISupportInitialize) this.Imagen).BeginInit();
      this.BoxItemFinder.SuspendLayout();
      this.Cuentas.BeginInit();
      this.Status.BeginInit();
      this.TextLoad1.BeginInit();
      this.TextLoad2.BeginInit();
      ((ISupportInitialize) this.ImagenItemFound).BeginInit();
      this.GroupBox1.SuspendLayout();
      this.GroupBox2.SuspendLayout();
      this.GroupBox3.SuspendLayout();
      this.GroupBox4.SuspendLayout();
      this.GroupBox5.SuspendLayout();
      this.CapaCodeOculto.SuspendLayout();
      this.SuspendLayout();
      this.Tipo2.Cursor = Cursors.Hand;
      this.Tipo2.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Tipo2.Items.AddRange(new object[15]
      {
        (object) "Orbs",
        (object) "Scrolls",
        (object) "Jewels",
        (object) "Potions",
        (object) "Amulets",
        (object) "Events",
        (object) "Events Mix",
        (object) "Quests",
        (object) "Gifts/Boxs",
        (object) "Mix Pets",
        (object) "Mix Items",
        (object) "Castel Siege",
        (object) "Other Items",
        (object) "+ ADD OP",
        (object) "New/Test"
      });
      ListBox tipo2_1 = this.Tipo2;
      Point point1 = new Point(94, 27);
      Point point2 = point1;
      tipo2_1.Location = point2;
      this.Tipo2.Name = "Tipo2";
      ListBox tipo2_2 = this.Tipo2;
      Size size1 = new Size(92, 238);
      Size size2 = size1;
      tipo2_2.Size = size2;
      this.Tipo2.TabIndex = 269;
      this.Tipo2.TabStop = false;
      this.Tipo1.Cursor = Cursors.Hand;
      this.Tipo1.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Tipo1.Items.AddRange(new object[18]
      {
        (object) "Swords",
        (object) "Axes",
        (object) "Maces",
        (object) "Scepters",
        (object) "Spears",
        (object) "Bows",
        (object) "CrossBows",
        (object) "Staffs",
        (object) "Shields",
        (object) "Helms",
        (object) "Armors",
        (object) "Pants",
        (object) "Gloves",
        (object) "Boots",
        (object) "Wings",
        (object) "Guards/Pets",
        (object) "Rings",
        (object) "Pendants"
      });
      ListBox tipo1_1 = this.Tipo1;
      point1 = new Point(2, 27);
      Point point3 = point1;
      tipo1_1.Location = point3;
      this.Tipo1.Name = "Tipo1";
      ListBox tipo1_2 = this.Tipo1;
      size1 = new Size(92, 238);
      Size size3 = size1;
      tipo1_2.Size = size3;
      this.Tipo1.TabIndex = 268;
      this.Tipo1.TabStop = false;
      this.Foto.BackColor = Color.Transparent;
      this.Foto.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Foto.ForeColor = SystemColors.GrayText;
      this.Foto.ImeMode = ImeMode.NoControl;
      Label foto1 = this.Foto;
      point1 = new Point(8, 265);
      Point point4 = point1;
      foto1.Location = point4;
      this.Foto.Name = "Foto";
      Label foto2 = this.Foto;
      size1 = new Size(172, 16);
      Size size4 = size1;
      foto2.Size = size4;
      this.Foto.TabIndex = 278;
      this.Foto.Text = "Foto";
      this.Foto.TextAlign = ContentAlignment.MiddleCenter;
      this.Label17.BackColor = SystemColors.Menu;
      this.Label17.ImeMode = ImeMode.NoControl;
      Label label17_1 = this.Label17;
      point1 = new Point(378, 26);
      Point point5 = point1;
      label17_1.Location = point5;
      this.Label17.Name = "Label17";
      Label label17_2 = this.Label17;
      size1 = new Size(2, 534);
      Size size5 = size1;
      label17_2.Size = size5;
      this.Label17.TabIndex = 301;
      this.JoHOPs.BackColor = Color.Black;
      this.JoHOPs.Cursor = Cursors.Hand;
      this.JoHOPs.Enabled = false;
      this.JoHOPs.ForeColor = Color.Gold;
      ComboBox joHoPs1 = this.JoHOPs;
      point1 = new Point(190, 541);
      Point point6 = point1;
      joHoPs1.Location = point6;
      this.JoHOPs.Name = "JoHOPs";
      ComboBox joHoPs2 = this.JoHOPs;
      size1 = new Size(190, 21);
      Size size6 = size1;
      joHoPs2.Size = size6;
      this.JoHOPs.TabIndex = 343;
      this.JoHOP.BackColor = Color.Black;
      this.JoHOP.Cursor = Cursors.Hand;
      this.JoHOP.Enabled = false;
      this.JoHOP.ForeColor = Color.Gold;
      ComboBox joHop1 = this.JoHOP;
      point1 = new Point(190, 521);
      Point point7 = point1;
      joHop1.Location = point7;
      this.JoHOP.Name = "JoHOP";
      ComboBox joHop2 = this.JoHOP;
      size1 = new Size(190, 21);
      Size size7 = size1;
      joHop2.Size = size7;
      this.JoHOP.TabIndex = 342;
      this.JHOP.BackColor = Color.Transparent;
      this.JHOP.Cursor = Cursors.Hand;
      this.JHOP.Enabled = false;
      this.JHOP.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.JHOP.ForeColor = Color.Gold;
      this.JHOP.ImeMode = ImeMode.NoControl;
      CheckBox jhop1 = this.JHOP;
      point1 = new Point(194, 503);
      Point point8 = point1;
      jhop1.Location = point8;
      this.JHOP.Name = "JHOP";
      CheckBox jhop2 = this.JHOP;
      size1 = new Size(178, 16);
      Size size8 = size1;
      jhop2.Size = size8;
      this.JHOP.TabIndex = 341;
      this.JHOP.TabStop = false;
      this.JHOP.Text = "Jewel Of Harmony";
      this.JHOP.UseVisualStyleBackColor = false;
      this.RF1.BackColor = Color.Transparent;
      this.RF1.Enabled = false;
      this.RF1.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.RF1.ForeColor = Color.DeepPink;
      Label rf1_1 = this.RF1;
      point1 = new Point(194, 469);
      Point point9 = point1;
      rf1_1.Location = point9;
      this.RF1.Name = "RF1";
      Label rf1_2 = this.RF1;
      size1 = new Size(180, 12);
      Size size9 = size1;
      rf1_2.Size = size9;
      this.RF1.TabIndex = 339;
      this.RF2.BackColor = Color.Transparent;
      this.RF2.Enabled = false;
      this.RF2.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.RF2.ForeColor = Color.DeepPink;
      Label rf2_1 = this.RF2;
      point1 = new Point(194, 483);
      Point point10 = point1;
      rf2_1.Location = point10;
      this.RF2.Name = "RF2";
      Label rf2_2 = this.RF2;
      size1 = new Size(180, 12);
      Size size10 = size1;
      rf2_2.Size = size10;
      this.RF2.TabIndex = 338;
      this.Reloj.Enabled = true;
      this.Reloj.Interval = 10000;
      this.Label6.BackColor = SystemColors.Menu;
      this.Label6.ImeMode = ImeMode.NoControl;
      Label label6_1 = this.Label6;
      point1 = new Point(190, 499);
      Point point11 = point1;
      label6_1.Location = point11;
      this.Label6.Name = "Label6";
      Label label6_2 = this.Label6;
      size1 = new Size(190, 2);
      Size size11 = size1;
      label6_2.Size = size11;
      this.Label6.TabIndex = 337;
      this.EXE6.BackColor = Color.Transparent;
      this.EXE6.Cursor = Cursors.Hand;
      this.EXE6.Enabled = false;
      this.EXE6.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.EXE6.ForeColor = Color.Green;
      this.EXE6.ImeMode = ImeMode.NoControl;
      CheckBox exE6_1 = this.EXE6;
      point1 = new Point(4, 545);
      Point point12 = point1;
      exE6_1.Location = point12;
      this.EXE6.Name = "EXE6";
      CheckBox exE6_2 = this.EXE6;
      size1 = new Size(186, 16);
      Size size12 = size1;
      exE6_2.Size = size12;
      this.EXE6.TabIndex = 288;
      this.EXE6.TabStop = false;
      this.EXE6.Text = "No Efect";
      this.EXE6.UseVisualStyleBackColor = false;
      this.EXE4.BackColor = Color.Transparent;
      this.EXE4.Cursor = Cursors.Hand;
      this.EXE4.Enabled = false;
      this.EXE4.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.EXE4.ForeColor = Color.Green;
      this.EXE4.ImeMode = ImeMode.NoControl;
      CheckBox exE4_1 = this.EXE4;
      point1 = new Point(4, 509);
      Point point13 = point1;
      exE4_1.Location = point13;
      this.EXE4.Name = "EXE4";
      CheckBox exE4_2 = this.EXE4;
      size1 = new Size(186, 16);
      Size size13 = size1;
      exE4_2.Size = size13;
      this.EXE4.TabIndex = 284;
      this.EXE4.TabStop = false;
      this.EXE4.Text = "No Efect";
      this.EXE4.UseVisualStyleBackColor = false;
      this.EXE5.BackColor = Color.Transparent;
      this.EXE5.Cursor = Cursors.Hand;
      this.EXE5.Enabled = false;
      this.EXE5.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.EXE5.ForeColor = Color.Green;
      this.EXE5.ImeMode = ImeMode.NoControl;
      CheckBox exE5_1 = this.EXE5;
      point1 = new Point(4, 527);
      Point point14 = point1;
      exE5_1.Location = point14;
      this.EXE5.Name = "EXE5";
      CheckBox exE5_2 = this.EXE5;
      size1 = new Size(186, 16);
      Size size14 = size1;
      exE5_2.Size = size14;
      this.EXE5.TabIndex = 286;
      this.EXE5.TabStop = false;
      this.EXE5.Text = "No Efect";
      this.EXE5.UseVisualStyleBackColor = false;
      this.EXE3.BackColor = Color.Transparent;
      this.EXE3.Cursor = Cursors.Hand;
      this.EXE3.Enabled = false;
      this.EXE3.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.EXE3.ForeColor = Color.Green;
      this.EXE3.ImeMode = ImeMode.NoControl;
      CheckBox exE3_1 = this.EXE3;
      point1 = new Point(4, 491);
      Point point15 = point1;
      exE3_1.Location = point15;
      this.EXE3.Name = "EXE3";
      CheckBox exE3_2 = this.EXE3;
      size1 = new Size(186, 16);
      Size size15 = size1;
      exE3_2.Size = size15;
      this.EXE3.TabIndex = 282;
      this.EXE3.TabStop = false;
      this.EXE3.Text = "No Efect";
      this.EXE3.UseVisualStyleBackColor = false;
      this.EXE2.BackColor = Color.Transparent;
      this.EXE2.Cursor = Cursors.Hand;
      this.EXE2.Enabled = false;
      this.EXE2.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.EXE2.ForeColor = Color.Green;
      this.EXE2.ImeMode = ImeMode.NoControl;
      CheckBox exE2_1 = this.EXE2;
      point1 = new Point(4, 473);
      Point point16 = point1;
      exE2_1.Location = point16;
      this.EXE2.Name = "EXE2";
      CheckBox exE2_2 = this.EXE2;
      size1 = new Size(186, 16);
      Size size16 = size1;
      exE2_2.Size = size16;
      this.EXE2.TabIndex = 280;
      this.EXE2.TabStop = false;
      this.EXE2.Text = "No Efect";
      this.EXE2.UseVisualStyleBackColor = false;
      this.EXE1.BackColor = Color.Transparent;
      this.EXE1.Cursor = Cursors.Hand;
      this.EXE1.Enabled = false;
      this.EXE1.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.EXE1.ForeColor = Color.Green;
      this.EXE1.ImeMode = ImeMode.NoControl;
      CheckBox exE1_1 = this.EXE1;
      point1 = new Point(4, 455);
      Point point17 = point1;
      exE1_1.Location = point17;
      this.EXE1.Name = "EXE1";
      CheckBox exE1_2 = this.EXE1;
      size1 = new Size(186, 16);
      Size size17 = size1;
      exE1_2.Size = size17;
      this.EXE1.TabIndex = 277;
      this.EXE1.TabStop = false;
      this.EXE1.Text = "No Efect";
      this.EXE1.UseVisualStyleBackColor = false;
      this.Label18.BackColor = SystemColors.Menu;
      this.Label18.ImeMode = ImeMode.NoControl;
      Label label18_1 = this.Label18;
      point1 = new Point(188, 451);
      Point point18 = point1;
      label18_1.Location = point18;
      this.Label18.Name = "Label18";
      Label label18_2 = this.Label18;
      size1 = new Size(2, 112);
      Size size18 = size1;
      label18_2.Size = size18;
      this.Label18.TabIndex = 302;
      this.Codigo.Cursor = Cursors.Default;
      this.Codigo.Font = new Font("Courier New", 8.25f, FontStyle.Bold);
      TextBox codigo1 = this.Codigo;
      point1 = new Point(486, 626);
      Point point19 = point1;
      codigo1.Location = point19;
      this.Codigo.MaxLength = 32;
      this.Codigo.Name = "Codigo";
      this.Codigo.ReadOnly = true;
      TextBox codigo2 = this.Codigo;
      size1 = new Size(230, 20);
      Size size19 = size1;
      codigo2.Size = size19;
      this.Codigo.TabIndex = 300;
      this.Codigo.TabStop = false;
      this.Codigo.Text = "00000000000000000000000000000000";
      this.Codigo.TextAlign = HorizontalAlignment.Right;
      this.Serial.CharacterCasing = CharacterCasing.Upper;
      this.Serial.Cursor = Cursors.Default;
      this.Serial.Font = new Font("Courier New", 8.25f, FontStyle.Bold);
      TextBox serial1 = this.Serial;
      point1 = new Point(292, 427);
      Point point20 = point1;
      serial1.Location = point20;
      this.Serial.MaxLength = 8;
      this.Serial.Name = "Serial";
      TextBox serial2 = this.Serial;
      size1 = new Size(76, 20);
      Size size20 = size1;
      serial2.Size = size20;
      this.Serial.TabIndex = 291;
      this.Serial.TabStop = false;
      this.Serial.Text = "00000000";
      this.Serial.TextAlign = HorizontalAlignment.Right;
      this.Dur.Cursor = Cursors.Default;
      this.Dur.Enabled = false;
      this.Dur.Font = new Font("Courier New", 8.25f, FontStyle.Bold);
      TextBox dur1 = this.Dur;
      point1 = new Point(344, 385);
      Point point21 = point1;
      dur1.Location = point21;
      this.Dur.Name = "Dur";
      this.Dur.ReadOnly = true;
      TextBox dur2 = this.Dur;
      size1 = new Size(26, 20);
      Size size21 = size1;
      dur2.Size = size21;
      this.Dur.TabIndex = 297;
      this.Dur.TabStop = false;
      this.Dur.Text = "000";
      this.Dur.TextAlign = HorizontalAlignment.Right;
      this.Siz.Cursor = Cursors.Default;
      this.Siz.Enabled = false;
      this.Siz.Font = new Font("Courier New", 8.25f, FontStyle.Bold);
      TextBox siz1 = this.Siz;
      point1 = new Point(240, 425);
      Point point22 = point1;
      siz1.Location = point22;
      this.Siz.Name = "Siz";
      this.Siz.ReadOnly = true;
      TextBox siz2 = this.Siz;
      size1 = new Size(26, 20);
      Size size22 = size1;
      siz2.Size = size22;
      this.Siz.TabIndex = 295;
      this.Siz.TabStop = false;
      this.Siz.Text = "0x0";
      this.Label13.BackColor = SystemColors.Menu;
      this.Label13.ImeMode = ImeMode.NoControl;
      Label label13_1 = this.Label13;
      point1 = new Point(276, 411);
      Point point23 = point1;
      label13_1.Location = point23;
      this.Label13.Name = "Label13";
      Label label13_2 = this.Label13;
      size1 = new Size(2, 38);
      Size size23 = size1;
      label13_2.Size = size23;
      this.Label13.TabIndex = 329;
      this.Label12.BackColor = SystemColors.Menu;
      this.Label12.ImeMode = ImeMode.NoControl;
      Label label12_1 = this.Label12;
      point1 = new Point(276, 264);
      Point point24 = point1;
      label12_1.Location = point24;
      this.Label12.Name = "Label12";
      Label label12_2 = this.Label12;
      size1 = new Size(2, 13);
      Size size24 = size1;
      label12_2.Size = size24;
      this.Label12.TabIndex = 328;
      this.Label8.BackColor = SystemColors.Menu;
      this.Label8.ImeMode = ImeMode.NoControl;
      Label label8_1 = this.Label8;
      point1 = new Point(230, 264);
      Point point25 = point1;
      label8_1.Location = point25;
      this.Label8.Name = "Label8";
      Label label8_2 = this.Label8;
      size1 = new Size(2, 13);
      Size size25 = size1;
      label8_2.Size = size25;
      this.Label8.TabIndex = 327;
      this.Label3.BackColor = SystemColors.Menu;
      this.Label3.ImeMode = ImeMode.NoControl;
      Label label3_1 = this.Label3;
      point1 = new Point(186, 263);
      Point point26 = point1;
      label3_1.Location = point26;
      this.Label3.Name = "Label3";
      Label label3_2 = this.Label3;
      size1 = new Size(2, 186);
      Size size26 = size1;
      label3_2.Size = size26;
      this.Label3.TabIndex = 326;
      this.Nombre.Cursor = Cursors.Default;
      this.Nombre.Font = new Font("Courier New", 8.25f, FontStyle.Bold);
      TextBox nombre1 = this.Nombre;
      point1 = new Point(2, 626);
      Point point27 = point1;
      nombre1.Location = point27;
      this.Nombre.Name = "Nombre";
      this.Nombre.ReadOnly = true;
      TextBox nombre2 = this.Nombre;
      size1 = new Size(484, 20);
      Size size27 = size1;
      nombre2.Size = size27;
      this.Nombre.TabIndex = 273;
      this.Nombre.TabStop = false;
      this.Nombre.Text = " Seleccione un Item";
      this.Label10.BackColor = SystemColors.Menu;
      this.Label10.ImeMode = ImeMode.NoControl;
      Label label10_1 = this.Label10;
      point1 = new Point(232, 409);
      Point point28 = point1;
      label10_1.Location = point28;
      this.Label10.Name = "Label10";
      Label label10_2 = this.Label10;
      size1 = new Size(146, 2);
      Size size28 = size1;
      label10_2.Size = size28;
      this.Label10.TabIndex = 314;
      this.Label9.BackColor = SystemColors.Menu;
      this.Label9.ImeMode = ImeMode.NoControl;
      Label label9_1 = this.Label9;
      point1 = new Point(278, 367);
      Point point29 = point1;
      label9_1.Location = point29;
      this.Label9.Name = "Label9";
      Label label9_2 = this.Label9;
      size1 = new Size(100, 2);
      Size size29 = size1;
      label9_2.Size = size29;
      this.Label9.TabIndex = 313;
      this.Opcion.BackColor = SystemColors.MenuText;
      this.Opcion.Cursor = Cursors.Hand;
      this.Opcion.Enabled = false;
      this.Opcion.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Opcion.ForeColor = Color.Blue;
      this.Opcion.Items.AddRange(new object[8]
      {
        (object) "00",
        (object) "04",
        (object) "08",
        (object) "12",
        (object) "16",
        (object) "20",
        (object) "24",
        (object) "28"
      });
      ListBox opcion1 = this.Opcion;
      point1 = new Point(232, 277);
      Point point30 = point1;
      opcion1.Location = point30;
      this.Opcion.Name = "Opcion";
      this.Opcion.RightToLeft = RightToLeft.Yes;
      ListBox opcion2 = this.Opcion;
      size1 = new Size(46, 134);
      Size size30 = size1;
      opcion2.Size = size30;
      this.Opcion.TabIndex = 274;
      this.Opcion.TabStop = false;
      this.Level.BackColor = Color.Black;
      this.Level.Cursor = Cursors.Hand;
      this.Level.Enabled = false;
      this.Level.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Level.ForeColor = Color.Gold;
      this.Level.Items.AddRange(new object[16]
      {
        (object) "00",
        (object) "01",
        (object) "02",
        (object) "03",
        (object) "04",
        (object) "05",
        (object) "06",
        (object) "07",
        (object) "08",
        (object) "09",
        (object) "10",
        (object) "11",
        (object) "12",
        (object) "13",
        (object) "14",
        (object) "15"
      });
      ListBox level1 = this.Level;
      point1 = new Point(186, 277);
      Point point31 = point1;
      level1.Location = point31;
      this.Level.Name = "Level";
      ListBox level2 = this.Level;
      size1 = new Size(46, 173);
      Size size31 = size1;
      level2.Size = size31;
      this.Level.TabIndex = 272;
      this.Level.TabStop = false;
      this.Numero.Cursor = Cursors.Hand;
      this.Numero.Enabled = false;
      this.Numero.Font = new Font("Courier New", 8.25f, FontStyle.Bold);
      this.Numero.ItemHeight = 14;
      this.Numero.Items.AddRange(new object[9]
      {
        (object) "001",
        (object) "005",
        (object) "010",
        (object) "020",
        (object) "050",
        (object) "100",
        (object) "150",
        (object) "200",
        (object) "255"
      });
      ComboBox numero1 = this.Numero;
      point1 = new Point(286, 383);
      Point point32 = point1;
      numero1.Location = point32;
      this.Numero.Name = "Numero";
      ComboBox numero2 = this.Numero;
      size1 = new Size(48, 22);
      Size size32 = size1;
      numero2.Size = size32;
      this.Numero.TabIndex = 289;
      this.Numero.TabStop = false;
      this.Numero.Text = "001";
      this.Label23.BackColor = Color.Transparent;
      this.Label23.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Label23.ForeColor = SystemColors.GrayText;
      this.Label23.ImeMode = ImeMode.NoControl;
      Label label23_1 = this.Label23;
      point1 = new Point(284, 369);
      Point point33 = point1;
      label23_1.Location = point33;
      this.Label23.Name = "Label23";
      Label label23_2 = this.Label23;
      size1 = new Size(50, 16);
      Size size33 = size1;
      label23_2.Size = size33;
      this.Label23.TabIndex = 304;
      this.Label23.Text = "Nº Items";
      this.Label23.TextAlign = ContentAlignment.MiddleCenter;
      this.Ancient1.BackColor = Color.Transparent;
      this.Ancient1.Cursor = Cursors.Hand;
      this.Ancient1.Enabled = false;
      this.Ancient1.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Ancient1.ForeColor = Color.Lime;
      this.Ancient1.ImeMode = ImeMode.NoControl;
      RadioButton ancient1_1 = this.Ancient1;
      point1 = new Point(280, 301);
      Point point34 = point1;
      ancient1_1.Location = point34;
      this.Ancient1.Name = "Ancient1";
      RadioButton ancient1_2 = this.Ancient1;
      size1 = new Size(96, 17);
      Size size34 = size1;
      ancient1_2.Size = size34;
      this.Ancient1.TabIndex = 285;
      this.Ancient1.Text = "Set ANC 1º";
      this.Ancient1.UseVisualStyleBackColor = false;
      this.NoAncient.AutoSize = true;
      this.NoAncient.BackColor = Color.Transparent;
      this.NoAncient.Cursor = Cursors.Hand;
      this.NoAncient.Enabled = false;
      this.NoAncient.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.NoAncient.ForeColor = Color.Gray;
      this.NoAncient.ImeMode = ImeMode.NoControl;
      RadioButton noAncient1 = this.NoAncient;
      point1 = new Point(280, 280);
      Point point35 = point1;
      noAncient1.Location = point35;
      this.NoAncient.Name = "NoAncient";
      RadioButton noAncient2 = this.NoAncient;
      size1 = new Size(90, 17);
      Size size35 = size1;
      noAncient2.Size = size35;
      this.NoAncient.TabIndex = 283;
      this.NoAncient.Text = "NO Ancient";
      this.NoAncient.UseVisualStyleBackColor = false;
      this.Level2.BackColor = Color.Gold;
      this.Level2.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Level2.ForeColor = Color.Black;
      this.Level2.ImeMode = ImeMode.NoControl;
      Label level2_1 = this.Level2;
      point1 = new Point(187, 264);
      Point point36 = point1;
      level2_1.Location = point36;
      this.Level2.Name = "Level2";
      Label level2_2 = this.Level2;
      size1 = new Size(46, 13);
      Size size36 = size1;
      level2_2.Size = size36;
      this.Level2.TabIndex = 281;
      this.Level2.Text = "Level";
      this.Level2.TextAlign = ContentAlignment.MiddleCenter;
      this.Opcion2.BackColor = Color.Blue;
      this.Opcion2.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Opcion2.ForeColor = Color.Black;
      this.Opcion2.ImeMode = ImeMode.NoControl;
      Label opcion2_1 = this.Opcion2;
      point1 = new Point(230, 264);
      Point point37 = point1;
      opcion2_1.Location = point37;
      this.Opcion2.Name = "Opcion2";
      Label opcion2_2 = this.Opcion2;
      size1 = new Size(49, 13);
      Size size37 = size1;
      opcion2_2.Size = size37;
      this.Opcion2.TabIndex = 279;
      this.Opcion2.Text = "Opcion";
      this.Opcion2.TextAlign = ContentAlignment.MiddleCenter;
      this.Items.Cursor = Cursors.Hand;
      this.Items.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      ListBox items1 = this.Items;
      point1 = new Point(186, 27);
      Point point38 = point1;
      items1.Location = point38;
      this.Items.Name = "Items";
      ListBox items2 = this.Items;
      size1 = new Size(192, 238);
      Size size38 = size1;
      items2.Size = size38;
      this.Items.TabIndex = 270;
      this.Items.TabStop = false;
      this.Label7.BackColor = SystemColors.Menu;
      this.Label7.ImeMode = ImeMode.NoControl;
      Label label7_1 = this.Label7;
      point1 = new Point(186, 275);
      Point point39 = point1;
      label7_1.Location = point39;
      this.Label7.Name = "Label7";
      Label label7_2 = this.Label7;
      size1 = new Size(194, 2);
      Size size39 = size1;
      label7_2.Size = size39;
      this.Label7.TabIndex = 294;
      this.Luck.BackColor = Color.Transparent;
      this.Luck.Cursor = Cursors.Hand;
      this.Luck.Enabled = false;
      this.Luck.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Luck.ForeColor = Color.Blue;
      this.Luck.ImeMode = ImeMode.NoControl;
      CheckBox luck1 = this.Luck;
      point1 = new Point(284, 349);
      Point point40 = point1;
      luck1.Location = point40;
      this.Luck.Name = "Luck";
      CheckBox luck2 = this.Luck;
      size1 = new Size(48, 16);
      Size size40 = size1;
      luck2.Size = size40;
      this.Luck.TabIndex = 275;
      this.Luck.TabStop = false;
      this.Luck.Text = "Luck";
      this.Luck.UseVisualStyleBackColor = false;
      this.Skill.BackColor = Color.Transparent;
      this.Skill.Cursor = Cursors.Hand;
      this.Skill.Enabled = false;
      this.Skill.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Skill.ForeColor = Color.Blue;
      this.Skill.ImeMode = ImeMode.NoControl;
      CheckBox skill1 = this.Skill;
      point1 = new Point(334, 349);
      Point point41 = point1;
      skill1.Location = point41;
      this.Skill.Name = "Skill";
      CheckBox skill2 = this.Skill;
      size1 = new Size(48, 16);
      Size size41 = size1;
      skill2.Size = size41;
      this.Skill.TabIndex = 276;
      this.Skill.TabStop = false;
      this.Skill.Text = "Skill";
      this.Skill.UseVisualStyleBackColor = false;
      this.Label5.BackColor = SystemColors.Menu;
      this.Label5.ImeMode = ImeMode.NoControl;
      Label label5_1 = this.Label5;
      point1 = new Point(2, 449);
      Point point42 = point1;
      label5_1.Location = point42;
      this.Label5.Name = "Label5";
      Label label5_2 = this.Label5;
      size1 = new Size(376, 2);
      Size size42 = size1;
      label5_2.Size = size42;
      this.Label5.TabIndex = 292;
      this.Ancient2.BackColor = Color.Transparent;
      this.Ancient2.Cursor = Cursors.Hand;
      this.Ancient2.Enabled = false;
      this.Ancient2.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Ancient2.ForeColor = Color.Lime;
      this.Ancient2.ImeMode = ImeMode.NoControl;
      RadioButton ancient2_1 = this.Ancient2;
      point1 = new Point(280, 322);
      Point point43 = point1;
      ancient2_1.Location = point43;
      this.Ancient2.Name = "Ancient2";
      RadioButton ancient2_2 = this.Ancient2;
      size1 = new Size(96, 17);
      Size size43 = size1;
      ancient2_2.Size = size43;
      this.Ancient2.TabIndex = 287;
      this.Ancient2.Text = "Set ANC 2º";
      this.Ancient2.UseVisualStyleBackColor = false;
      this.Label4.BackColor = SystemColors.Menu;
      this.Label4.ImeMode = ImeMode.NoControl;
      Label label4_1 = this.Label4;
      point1 = new Point(278, 343);
      Point point44 = point1;
      label4_1.Location = point44;
      this.Label4.Name = "Label4";
      Label label4_2 = this.Label4;
      size1 = new Size(100, 2);
      Size size44 = size1;
      label4_2.Size = size44;
      this.Label4.TabIndex = 290;
      this.SetAncient.BackColor = Color.Blue;
      this.SetAncient.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.SetAncient.ForeColor = Color.Lime;
      this.SetAncient.ImeMode = ImeMode.NoControl;
      Label setAncient1 = this.SetAncient;
      point1 = new Point(278, 264);
      Point point45 = point1;
      setAncient1.Location = point45;
      this.SetAncient.Name = "SetAncient";
      Label setAncient2 = this.SetAncient;
      size1 = new Size(100, 13);
      Size size45 = size1;
      setAncient2.Size = size45;
      this.SetAncient.TabIndex = 293;
      this.SetAncient.Text = "Ancient";
      this.SetAncient.TextAlign = ContentAlignment.MiddleCenter;
      this.Siz2.BackColor = Color.Transparent;
      this.Siz2.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Siz2.ForeColor = SystemColors.GrayText;
      this.Siz2.ImeMode = ImeMode.NoControl;
      Label siz2_1 = this.Siz2;
      point1 = new Point(232, 410);
      Point point46 = point1;
      siz2_1.Location = point46;
      this.Siz2.Name = "Siz2";
      Label siz2_2 = this.Siz2;
      size1 = new Size(41, 16);
      Size size46 = size1;
      siz2_2.Size = size46;
      this.Siz2.TabIndex = 296;
      this.Siz2.Text = "Size";
      this.Siz2.TextAlign = ContentAlignment.MiddleCenter;
      this.Dur2.BackColor = Color.Transparent;
      this.Dur2.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Dur2.ForeColor = SystemColors.GrayText;
      this.Dur2.ImeMode = ImeMode.NoControl;
      Label dur2_1 = this.Dur2;
      point1 = new Point(344, 369);
      Point point47 = point1;
      dur2_1.Location = point47;
      this.Dur2.Name = "Dur2";
      Label dur2_2 = this.Dur2;
      size1 = new Size(24, 16);
      Size size47 = size1;
      dur2_2.Size = size47;
      this.Dur2.TabIndex = 298;
      this.Dur2.Text = "Dur";
      this.Dur2.TextAlign = ContentAlignment.MiddleCenter;
      this.RF.BackColor = Color.Transparent;
      this.RF.Cursor = Cursors.Hand;
      this.RF.Enabled = false;
      this.RF.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.RF.ForeColor = Color.DeepPink;
      this.RF.ImeMode = ImeMode.NoControl;
      CheckBox rf1 = this.RF;
      point1 = new Point(192, 451);
      Point point48 = point1;
      rf1.Location = point48;
      this.RF.Name = "RF";
      CheckBox rf2 = this.RF;
      size1 = new Size(122, 16);
      Size size48 = size1;
      rf2.Size = size48;
      this.RF.TabIndex = 340;
      this.RF.TabStop = false;
      this.RF.Text = "Refinery lvl 380";
      this.RF.UseVisualStyleBackColor = false;
      this.Emergente.AutomaticDelay = 5000;
      this.Emergente.AutoPopDelay = 500000;
      this.Emergente.InitialDelay = 5;
      this.Emergente.ReshowDelay = 1;
      this.Imagen.BackColor = Color.Transparent;
      this.Imagen.ImeMode = ImeMode.NoControl;
      PictureBox imagen1 = this.Imagen;
      point1 = new Point(12, 277);
      Point point49 = point1;
      imagen1.Location = point49;
      this.Imagen.Name = "Imagen";
      PictureBox imagen2 = this.Imagen;
      size1 = new Size(165, 165);
      Size size49 = size1;
      imagen2.Size = size49;
      this.Imagen.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Imagen.TabIndex = 271;
      this.Imagen.TabStop = false;
      this.Label19.BackColor = SystemColors.Menu;
      this.Label19.ImeMode = ImeMode.NoControl;
      Label label19_1 = this.Label19;
      point1 = new Point(0, 562);
      Point point50 = point1;
      label19_1.Location = point50;
      this.Label19.Name = "Label19";
      Label label19_2 = this.Label19;
      size1 = new Size(718, 1);
      Size size50 = size1;
      label19_2.Size = size50;
      this.Label19.TabIndex = 303;
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
      point1 = new Point(8, 7);
      Point point51 = point1;
      minimizar1.Location = point51;
      this.Minimizar.Name = "Minimizar";
      Button minimizar2 = this.Minimizar;
      size1 = new Size(13, 13);
      Size size51 = size1;
      minimizar2.Size = size51;
      this.Minimizar.TabIndex = 1892;
      this.Minimizar.TabStop = false;
      this.Minimizar.UseVisualStyleBackColor = false;
      this.Cerrar.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) Class34.smethod_39();
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
      point1 = new Point(697, 7);
      Point point52 = point1;
      cerrar1.Location = point52;
      this.Cerrar.Name = "Cerrar";
      Button cerrar2 = this.Cerrar;
      size1 = new Size(13, 13);
      Size size52 = size1;
      cerrar2.Size = size52;
      this.Cerrar.TabIndex = 1893;
      this.Cerrar.TabStop = false;
      this.Cerrar.UseVisualStyleBackColor = false;
      this.Titulo.AutoSize = true;
      this.Titulo.BackColor = Color.Transparent;
      this.Titulo.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Titulo.ForeColor = Color.DarkOrange;
      Label titulo1 = this.Titulo;
      point1 = new Point(61, 8);
      Point point53 = point1;
      titulo1.Location = point53;
      this.Titulo.Name = "Titulo";
      Label titulo2 = this.Titulo;
      size1 = new Size(0, 13);
      Size size53 = size1;
      titulo2.Size = size53;
      this.Titulo.TabIndex = 1894;
      this.Label1.BackColor = Color.Gray;
      this.Label1.ImeMode = ImeMode.NoControl;
      Label label1_1 = this.Label1;
      point1 = new Point(0, 27);
      Point point54 = point1;
      label1_1.Location = point54;
      this.Label1.Name = "Label1";
      Label label1_2 = this.Label1;
      size1 = new Size(2, 620);
      Size size54 = size1;
      label1_2.Size = size54;
      this.Label1.TabIndex = 1897;
      this.Label2.BackColor = Color.Gray;
      this.Label2.ImeMode = ImeMode.NoControl;
      Label label2_1 = this.Label2;
      point1 = new Point(716, 59);
      Point point55 = point1;
      label2_1.Location = point55;
      this.Label2.Name = "Label2";
      Label label2_2 = this.Label2;
      size1 = new Size(2, 588);
      Size size55 = size1;
      label2_2.Size = size55;
      this.Label2.TabIndex = 1898;
      this.Label14.BackColor = Color.Gray;
      this.Label14.ImeMode = ImeMode.NoControl;
      Label label14_1 = this.Label14;
      point1 = new Point(0, 646);
      Point point56 = point1;
      label14_1.Location = point56;
      this.Label14.Name = "Label14";
      Label label14_2 = this.Label14;
      size1 = new Size(718, 2);
      Size size56 = size1;
      label14_2.Size = size56;
      this.Label14.TabIndex = 1900;
      this.BoxItemFinder.Controls.Add((Control) this.S4);
      this.BoxItemFinder.Controls.Add((Control) this.N4);
      this.BoxItemFinder.Controls.Add((Control) this.Label26);
      this.BoxItemFinder.Controls.Add((Control) this.StopSearch);
      this.BoxItemFinder.Controls.Add((Control) this.StatusBar);
      this.BoxItemFinder.Controls.Add((Control) this.PJDupe);
      this.BoxItemFinder.Controls.Add((Control) this.Label11);
      this.BoxItemFinder.Controls.Add((Control) this.SerialSearch);
      this.BoxItemFinder.Controls.Add((Control) this.BuscarSerial);
      this.BoxItemFinder.Controls.Add((Control) this.Label15);
      this.BoxItemFinder.Controls.Add((Control) this.ItemCodeSearch);
      this.BoxItemFinder.Controls.Add((Control) this.ItemCode);
      this.BoxItemFinder.Controls.Add((Control) this.ItemSerial);
      this.BoxItemFinder.Controls.Add((Control) this.ItemName);
      this.BoxItemFinder.Controls.Add((Control) this.Cuenta1);
      this.BoxItemFinder.Controls.Add((Control) this.Personaje1);
      this.BoxItemFinder.Controls.Add((Control) this.Label24);
      this.BoxItemFinder.Controls.Add((Control) this.RadioExtra);
      this.BoxItemFinder.Controls.Add((Control) this.Label27);
      this.BoxItemFinder.Controls.Add((Control) this.RadioVault);
      this.BoxItemFinder.Controls.Add((Control) this.Label29);
      this.BoxItemFinder.Controls.Add((Control) this.Label28);
      this.BoxItemFinder.Controls.Add((Control) this.RadioInvent);
      this.BoxItemFinder.Controls.Add((Control) this.Label16);
      this.BoxItemFinder.Controls.Add((Control) this.N3);
      this.BoxItemFinder.Controls.Add((Control) this.S3);
      this.BoxItemFinder.Controls.Add((Control) this.Label20);
      this.BoxItemFinder.Controls.Add((Control) this.N2);
      this.BoxItemFinder.Controls.Add((Control) this.S2);
      this.BoxItemFinder.Controls.Add((Control) this.BuscarCode);
      this.BoxItemFinder.Controls.Add((Control) this.Label31);
      this.BoxItemFinder.Controls.Add((Control) this.Label32);
      this.BoxItemFinder.Controls.Add((Control) this.S5);
      this.BoxItemFinder.Controls.Add((Control) this.Account1);
      this.BoxItemFinder.Controls.Add((Control) this.Chart1);
      this.BoxItemFinder.Controls.Add((Control) this.Label36);
      this.BoxItemFinder.Controls.Add((Control) this.CuentasDupe);
      this.BoxItemFinder.Controls.Add((Control) this.InfracAccount);
      this.BoxItemFinder.Controls.Add((Control) this.RelatedAccount);
      this.BoxItemFinder.Controls.Add((Control) this.N5);
      this.BoxItemFinder.Controls.Add((Control) this.N1);
      this.BoxItemFinder.Controls.Add((Control) this.S1);
      this.BoxItemFinder.Controls.Add((Control) this.Label38);
      this.BoxItemFinder.Controls.Add((Control) this.Label39);
      this.BoxItemFinder.Controls.Add((Control) this.Label40);
      this.BoxItemFinder.Controls.Add((Control) this.CargaParcial);
      this.BoxItemFinder.Controls.Add((Control) this.CargaTotal);
      this.BoxItemFinder.Controls.Add((Control) this.ImagenItemFound);
      this.BoxItemFinder.Controls.Add((Control) this.TIPS);
      this.BoxItemFinder.Font = new Font("Microsoft Sans Serif", 9.75f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      GroupBox boxItemFinder1 = this.BoxItemFinder;
      point1 = new Point(379, 119);
      Point point57 = point1;
      boxItemFinder1.Location = point57;
      this.BoxItemFinder.Name = "BoxItemFinder";
      GroupBox boxItemFinder2 = this.BoxItemFinder;
      size1 = new Size(339, 443);
      Size size57 = size1;
      boxItemFinder2.Size = size57;
      this.BoxItemFinder.TabIndex = 1901;
      this.BoxItemFinder.TabStop = false;
      this.S4.AutoCheck = false;
      CheckBox s4_1 = this.S4;
      point1 = new Point(266, 275);
      Point point58 = point1;
      s4_1.Location = point58;
      this.S4.Name = "S4";
      CheckBox s4_2 = this.S4;
      size1 = new Size(16, 14);
      Size size58 = size1;
      s4_2.Size = size58;
      this.S4.TabIndex = 471;
      this.S4.TabStop = false;
      this.S4.TextAlign = ContentAlignment.TopLeft;
      this.N4.AutoCheck = false;
      CheckBox n4_1 = this.N4;
      point1 = new Point(310, 275);
      Point point59 = point1;
      n4_1.Location = point59;
      this.N4.Name = "N4";
      CheckBox n4_2 = this.N4;
      size1 = new Size(16, 14);
      Size size59 = size1;
      n4_2.Size = size59;
      this.N4.TabIndex = 472;
      this.N4.TabStop = false;
      this.N4.TextAlign = ContentAlignment.TopLeft;
      this.Label26.AutoSize = true;
      this.Label26.BackColor = Color.Black;
      this.Label26.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label26.ForeColor = Color.DimGray;
      Label label26_1 = this.Label26;
      point1 = new Point(186, 275);
      Point point60 = point1;
      label26_1.Location = point60;
      this.Label26.Name = "Label26";
      Label label26_2 = this.Label26;
      size1 = new Size(77, 13);
      Size size60 = size1;
      label26_2.Size = size60;
      this.Label26.TabIndex = 470;
      this.Label26.Text = "Full Sockets";
      this.Label26.TextAlign = ContentAlignment.MiddleRight;
      this.StopSearch.BackColor = Color.DimGray;
      this.StopSearch.Cursor = Cursors.Hand;
      this.StopSearch.Font = new Font("Microsoft Sans Serif", 7f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.StopSearch.ForeColor = Color.DarkRed;
      Button stopSearch1 = this.StopSearch;
      point1 = new Point(174, 330);
      Point point61 = point1;
      stopSearch1.Location = point61;
      this.StopSearch.Name = "StopSearch";
      Button stopSearch2 = this.StopSearch;
      size1 = new Size(163, 20);
      Size size61 = size1;
      stopSearch2.Size = size61;
      this.StopSearch.TabIndex = 461;
      this.StopSearch.TabStop = false;
      this.StopSearch.Text = "CANCEL SEARCH";
      this.StopSearch.UseVisualStyleBackColor = false;
      this.StatusBar.Anchor = AnchorStyles.None;
      this.StatusBar.Dock = DockStyle.None;
      this.StatusBar.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.StatusBar.ImeMode = ImeMode.NoControl;
      StatusBar statusBar1 = this.StatusBar;
      point1 = new Point(1, 423);
      Point point62 = point1;
      statusBar1.Location = point62;
      this.StatusBar.Margin = new Padding(0);
      this.StatusBar.Name = "StatusBar";
      this.StatusBar.Panels.AddRange(new StatusBarPanel[4]
      {
        this.Cuentas,
        this.Status,
        this.TextLoad1,
        this.TextLoad2
      });
      this.StatusBar.ShowPanels = true;
      StatusBar statusBar2 = this.StatusBar;
      size1 = new Size(339, 20);
      Size size62 = size1;
      statusBar2.Size = size62;
      this.StatusBar.TabIndex = 398;
      this.Cuentas.Alignment = HorizontalAlignment.Right;
      this.Cuentas.Name = "Cuentas";
      this.Cuentas.Width = 120;
      this.Status.Alignment = HorizontalAlignment.Center;
      this.Status.Name = "Status";
      this.Status.Width = 128;
      this.TextLoad1.Alignment = HorizontalAlignment.Right;
      this.TextLoad1.Name = "TextLoad1";
      this.TextLoad1.Text = "100%";
      this.TextLoad1.Width = 40;
      this.TextLoad2.Name = "TextLoad2";
      this.TextLoad2.Text = "100%";
      this.TextLoad2.Width = 50;
      this.PJDupe.Cursor = Cursors.Hand;
      this.PJDupe.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      ListBox pjDupe1 = this.PJDupe;
      point1 = new Point(169, 28);
      Point point63 = point1;
      pjDupe1.Location = point63;
      this.PJDupe.Name = "PJDupe";
      ListBox pjDupe2 = this.PJDupe;
      size1 = new Size(168, 95);
      Size size63 = size1;
      pjDupe2.Size = size63;
      this.PJDupe.TabIndex = 389;
      this.PJDupe.TabStop = false;
      this.Label11.BackColor = SystemColors.AppWorkspace;
      Label label11_1 = this.Label11;
      point1 = new Point(2, 383);
      Point point64 = point1;
      label11_1.Location = point64;
      this.Label11.Name = "Label11";
      Label label11_2 = this.Label11;
      size1 = new Size(332, 1);
      Size size64 = size1;
      label11_2.Size = size64;
      this.Label11.TabIndex = 460;
      this.SerialSearch.Font = new Font("Courier New", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox serialSearch1 = this.SerialSearch;
      point1 = new Point(108, 383);
      Point point65 = point1;
      serialSearch1.Location = point65;
      this.SerialSearch.MaxLength = 8;
      this.SerialSearch.Name = "SerialSearch";
      this.SerialSearch.ReadOnly = true;
      TextBox serialSearch2 = this.SerialSearch;
      size1 = new Size(230, 20);
      Size size65 = size1;
      serialSearch2.Size = size65;
      this.SerialSearch.TabIndex = 457;
      this.SerialSearch.TabStop = false;
      this.SerialSearch.TextAlign = HorizontalAlignment.Center;
      this.BuscarSerial.BackColor = Color.DimGray;
      this.BuscarSerial.Cursor = Cursors.Hand;
      this.BuscarSerial.FlatStyle = FlatStyle.System;
      this.BuscarSerial.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BuscarSerial.ForeColor = Color.Black;
      this.BuscarSerial.ImageAlign = ContentAlignment.TopCenter;
      Button buscarSerial1 = this.BuscarSerial;
      point1 = new Point(2, 384);
      Point point66 = point1;
      buscarSerial1.Location = point66;
      this.BuscarSerial.Name = "BuscarSerial";
      Button buscarSerial2 = this.BuscarSerial;
      size1 = new Size(60, 19);
      Size size66 = size1;
      buscarSerial2.Size = size66;
      this.BuscarSerial.TabIndex = 459;
      this.BuscarSerial.TabStop = false;
      this.BuscarSerial.Text = "Search";
      this.BuscarSerial.UseVisualStyleBackColor = false;
      this.Label15.BackColor = Color.Black;
      this.Label15.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label15.ForeColor = Color.DimGray;
      Label label15_1 = this.Label15;
      point1 = new Point(62, 387);
      Point point67 = point1;
      label15_1.Location = point67;
      this.Label15.Name = "Label15";
      Label label15_2 = this.Label15;
      size1 = new Size(42, 12);
      Size size67 = size1;
      label15_2.Size = size67;
      this.Label15.TabIndex = 458;
      this.Label15.Text = "Serial :";
      this.ItemCodeSearch.Font = new Font("Courier New", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox itemCodeSearch1 = this.ItemCodeSearch;
      point1 = new Point(108, 364);
      Point point68 = point1;
      itemCodeSearch1.Location = point68;
      this.ItemCodeSearch.MaxLength = 30;
      this.ItemCodeSearch.Name = "ItemCodeSearch";
      this.ItemCodeSearch.ReadOnly = true;
      TextBox itemCodeSearch2 = this.ItemCodeSearch;
      size1 = new Size(230, 20);
      Size size68 = size1;
      itemCodeSearch2.Size = size68;
      this.ItemCodeSearch.TabIndex = 453;
      this.ItemCodeSearch.TabStop = false;
      this.ItemCodeSearch.TextAlign = HorizontalAlignment.Center;
      this.ItemCode.Enabled = false;
      this.ItemCode.Font = new Font("Courier New", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox itemCode1 = this.ItemCode;
      point1 = new Point(2, 163);
      Point point69 = point1;
      itemCode1.Location = point69;
      this.ItemCode.MaxLength = 30;
      this.ItemCode.Name = "ItemCode";
      this.ItemCode.ReadOnly = true;
      TextBox itemCode2 = this.ItemCode;
      size1 = new Size(230, 20);
      Size size69 = size1;
      itemCode2.Size = size69;
      this.ItemCode.TabIndex = 441;
      this.ItemCode.TabStop = false;
      this.ItemCode.TextAlign = HorizontalAlignment.Center;
      this.ItemSerial.Enabled = false;
      this.ItemSerial.Font = new Font("Courier New", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox itemSerial1 = this.ItemSerial;
      point1 = new Point(276, 163);
      Point point70 = point1;
      itemSerial1.Location = point70;
      this.ItemSerial.MaxLength = 8;
      this.ItemSerial.Name = "ItemSerial";
      this.ItemSerial.ReadOnly = true;
      TextBox itemSerial2 = this.ItemSerial;
      size1 = new Size(62, 20);
      Size size70 = size1;
      itemSerial2.Size = size70;
      this.ItemSerial.TabIndex = 411;
      this.ItemSerial.TabStop = false;
      this.ItemSerial.TextAlign = HorizontalAlignment.Center;
      this.ItemName.Enabled = false;
      this.ItemName.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox itemName1 = this.ItemName;
      point1 = new Point(2, 143);
      Point point71 = point1;
      itemName1.Location = point71;
      this.ItemName.MaxLength = 30;
      this.ItemName.Name = "ItemName";
      this.ItemName.ReadOnly = true;
      TextBox itemName2 = this.ItemName;
      size1 = new Size(336, 20);
      Size size71 = size1;
      itemName2.Size = size71;
      this.ItemName.TabIndex = 410;
      this.ItemName.TabStop = false;
      this.Cuenta1.Enabled = false;
      this.Cuenta1.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox cuenta1_1 = this.Cuenta1;
      point1 = new Point(76, 123);
      Point point72 = point1;
      cuenta1_1.Location = point72;
      this.Cuenta1.Name = "Cuenta1";
      this.Cuenta1.ReadOnly = true;
      TextBox cuenta1_2 = this.Cuenta1;
      size1 = new Size(94, 20);
      Size size72 = size1;
      cuenta1_2.Size = size72;
      this.Cuenta1.TabIndex = 402;
      this.Cuenta1.TabStop = false;
      this.Personaje1.Enabled = false;
      this.Personaje1.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox personaje1_1 = this.Personaje1;
      point1 = new Point(250, 123);
      Point point73 = point1;
      personaje1_1.Location = point73;
      this.Personaje1.Name = "Personaje1";
      this.Personaje1.ReadOnly = true;
      TextBox personaje1_2 = this.Personaje1;
      size1 = new Size(88, 20);
      Size size73 = size1;
      personaje1_2.Size = size73;
      this.Personaje1.TabIndex = 403;
      this.Personaje1.TabStop = false;
      this.Label24.BackColor = SystemColors.AppWorkspace;
      Label label24_1 = this.Label24;
      point1 = new Point(2, 183);
      Point point74 = point1;
      label24_1.Location = point74;
      this.Label24.Name = "Label24";
      Label label24_2 = this.Label24;
      size1 = new Size(336, 2);
      Size size74 = size1;
      label24_2.Size = size74;
      this.Label24.TabIndex = 442;
      this.RadioExtra.Cursor = Cursors.Hand;
      this.RadioExtra.Enabled = false;
      this.RadioExtra.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.RadioExtra.ForeColor = Color.Blue;
      RadioButton radioExtra1 = this.RadioExtra;
      point1 = new Point(288, 187);
      Point point75 = point1;
      radioExtra1.Location = point75;
      this.RadioExtra.Name = "RadioExtra";
      RadioButton radioExtra2 = this.RadioExtra;
      size1 = new Size(50, 20);
      Size size75 = size1;
      radioExtra2.Size = size75;
      this.RadioExtra.TabIndex = 448;
      this.RadioExtra.Text = "Extra";
      this.Label27.BackColor = SystemColors.AppWorkspace;
      Label label27_1 = this.Label27;
      point1 = new Point(2, 350);
      Point point76 = point1;
      label27_1.Location = point76;
      this.Label27.Name = "Label27";
      Label label27_2 = this.Label27;
      size1 = new Size(336, 2);
      Size size76 = size1;
      label27_2.Size = size76;
      this.Label27.TabIndex = 444;
      this.RadioVault.Cursor = Cursors.Hand;
      this.RadioVault.Enabled = false;
      this.RadioVault.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.RadioVault.ForeColor = Color.Blue;
      RadioButton radioVault1 = this.RadioVault;
      point1 = new Point(236, 187);
      Point point77 = point1;
      radioVault1.Location = point77;
      this.RadioVault.Name = "RadioVault";
      RadioButton radioVault2 = this.RadioVault;
      size1 = new Size(50, 20);
      Size size77 = size1;
      radioVault2.Size = size77;
      this.RadioVault.TabIndex = 447;
      this.RadioVault.Text = "Vault";
      this.Label29.BackColor = SystemColors.AppWorkspace;
      Label label29_1 = this.Label29;
      point1 = new Point(174, 209);
      Point point78 = point1;
      label29_1.Location = point78;
      this.Label29.Name = "Label29";
      Label label29_2 = this.Label29;
      size1 = new Size(164, 2);
      Size size78 = size1;
      label29_2.Size = size78;
      this.Label29.TabIndex = 446;
      this.Label28.BackColor = SystemColors.AppWorkspace;
      Label label28_1 = this.Label28;
      point1 = new Point(172, 180);
      Point point79 = point1;
      label28_1.Location = point79;
      this.Label28.Name = "Label28";
      Label label28_2 = this.Label28;
      size1 = new Size(2, 172);
      Size size79 = size1;
      label28_2.Size = size79;
      this.Label28.TabIndex = 445;
      this.RadioInvent.Cursor = Cursors.Hand;
      this.RadioInvent.Enabled = false;
      this.RadioInvent.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.RadioInvent.ForeColor = Color.Blue;
      RadioButton radioInvent1 = this.RadioInvent;
      point1 = new Point(178, 187);
      Point point80 = point1;
      radioInvent1.Location = point80;
      this.RadioInvent.Name = "RadioInvent";
      RadioButton radioInvent2 = this.RadioInvent;
      size1 = new Size(54, 20);
      Size size80 = size1;
      radioInvent2.Size = size80;
      this.RadioInvent.TabIndex = 449;
      this.RadioInvent.Text = "Invent";
      this.Label16.BackColor = Color.Black;
      this.Label16.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label16.ForeColor = Color.DimGray;
      Label label16_1 = this.Label16;
      point1 = new Point(232, 167);
      Point point81 = point1;
      label16_1.Location = point81;
      this.Label16.Name = "Label16";
      Label label16_2 = this.Label16;
      size1 = new Size(42, 12);
      Size size81 = size1;
      label16_2.Size = size81;
      this.Label16.TabIndex = 434;
      this.Label16.Text = "Serial :";
      this.N3.AutoCheck = false;
      CheckBox n3_1 = this.N3;
      point1 = new Point(310, 260);
      Point point82 = point1;
      n3_1.Location = point82;
      this.N3.Name = "N3";
      CheckBox n3_2 = this.N3;
      size1 = new Size(16, 14);
      Size size82 = size1;
      n3_2.Size = size82;
      this.N3.TabIndex = 437;
      this.N3.TabStop = false;
      this.N3.TextAlign = ContentAlignment.TopLeft;
      this.S3.AutoCheck = false;
      CheckBox s3_1 = this.S3;
      point1 = new Point(266, 260);
      Point point83 = point1;
      s3_1.Location = point83;
      this.S3.Name = "S3";
      CheckBox s3_2 = this.S3;
      size1 = new Size(16, 14);
      Size size83 = size1;
      s3_2.Size = size83;
      this.S3.TabIndex = 436;
      this.S3.TabStop = false;
      this.S3.TextAlign = ContentAlignment.TopLeft;
      this.Label20.AutoSize = true;
      this.Label20.BackColor = Color.Black;
      this.Label20.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label20.ForeColor = Color.DimGray;
      Label label20_1 = this.Label20;
      point1 = new Point(210, 260);
      Point point84 = point1;
      label20_1.Location = point84;
      this.Label20.Name = "Label20";
      Label label20_2 = this.Label20;
      size1 = new Size(53, 13);
      Size size84 = size1;
      label20_2.Size = size84;
      this.Label20.TabIndex = 435;
      this.Label20.Text = "Full JoH";
      this.Label20.TextAlign = ContentAlignment.MiddleRight;
      this.N2.AutoCheck = false;
      CheckBox n2_1 = this.N2;
      point1 = new Point(310, 244);
      Point point85 = point1;
      n2_1.Location = point85;
      this.N2.Name = "N2";
      CheckBox n2_2 = this.N2;
      size1 = new Size(16, 14);
      Size size85 = size1;
      n2_2.Size = size85;
      this.N2.TabIndex = 433;
      this.N2.TabStop = false;
      this.N2.TextAlign = ContentAlignment.TopLeft;
      this.S2.AutoCheck = false;
      CheckBox s2_1 = this.S2;
      point1 = new Point(266, 244);
      Point point86 = point1;
      s2_1.Location = point86;
      this.S2.Name = "S2";
      CheckBox s2_2 = this.S2;
      size1 = new Size(16, 14);
      Size size86 = size1;
      s2_2.Size = size86;
      this.S2.TabIndex = 432;
      this.S2.TabStop = false;
      this.S2.TextAlign = ContentAlignment.TopLeft;
      this.BuscarCode.BackColor = Color.DimGray;
      this.BuscarCode.Cursor = Cursors.Hand;
      this.BuscarCode.FlatStyle = FlatStyle.System;
      this.BuscarCode.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BuscarCode.ForeColor = Color.Black;
      this.BuscarCode.ImageAlign = ContentAlignment.TopCenter;
      Button buscarCode1 = this.BuscarCode;
      point1 = new Point(2, 365);
      Point point87 = point1;
      buscarCode1.Location = point87;
      this.BuscarCode.Name = "BuscarCode";
      Button buscarCode2 = this.BuscarCode;
      size1 = new Size(60, 19);
      Size size87 = size1;
      buscarCode2.Size = size87;
      this.BuscarCode.TabIndex = 455;
      this.BuscarCode.TabStop = false;
      this.BuscarCode.Text = "Search";
      this.BuscarCode.UseVisualStyleBackColor = false;
      this.Label31.BackColor = Color.Black;
      this.Label31.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label31.ForeColor = Color.DimGray;
      Label label31_1 = this.Label31;
      point1 = new Point(64, 367);
      Point point88 = point1;
      label31_1.Location = point88;
      this.Label31.Name = "Label31";
      Label label31_2 = this.Label31;
      size1 = new Size(40, 12);
      Size size88 = size1;
      label31_2.Size = size88;
      this.Label31.TabIndex = 454;
      this.Label31.Text = "Code : ";
      this.Label32.AutoSize = true;
      this.Label32.BackColor = Color.Black;
      this.Label32.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label32.ForeColor = Color.DimGray;
      Label label32_1 = this.Label32;
      point1 = new Point(256, 212);
      Point point89 = point1;
      label32_1.Location = point89;
      this.Label32.Name = "Label32";
      Label label32_2 = this.Label32;
      size1 = new Size(76, 13);
      Size size89 = size1;
      label32_2.Size = size89;
      this.Label32.TabIndex = 452;
      this.Label32.Text = "Yes   -    No";
      this.S5.AutoCheck = false;
      CheckBox s5_1 = this.S5;
      point1 = new Point(266, 290);
      Point point90 = point1;
      s5_1.Location = point90;
      this.S5.Name = "S5";
      CheckBox s5_2 = this.S5;
      size1 = new Size(16, 14);
      Size size90 = size1;
      s5_2.Size = size90;
      this.S5.TabIndex = 430;
      this.S5.TabStop = false;
      this.S5.TextAlign = ContentAlignment.TopLeft;
      this.Account1.BackColor = Color.Black;
      this.Account1.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Account1.ForeColor = Color.DimGray;
      Label account1_1 = this.Account1;
      point1 = new Point(6, (int) sbyte.MaxValue);
      Point point91 = point1;
      account1_1.Location = point91;
      this.Account1.Name = "Account1";
      Label account1_2 = this.Account1;
      size1 = new Size(68, 12);
      Size size91 = size1;
      account1_2.Size = size91;
      this.Account1.TabIndex = 415;
      this.Account1.Text = "Account : ";
      this.Chart1.BackColor = Color.Black;
      this.Chart1.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Chart1.ForeColor = Color.DimGray;
      Label chart1_1 = this.Chart1;
      point1 = new Point(172, (int) sbyte.MaxValue);
      Point point92 = point1;
      chart1_1.Location = point92;
      this.Chart1.Name = "Chart1";
      Label chart1_2 = this.Chart1;
      size1 = new Size(78, 16);
      Size size92 = size1;
      chart1_2.Size = size92;
      this.Chart1.TabIndex = 417;
      this.Chart1.Text = "Character : ";
      this.Label36.BackColor = SystemColors.AppWorkspace;
      Label label36_1 = this.Label36;
      point1 = new Point(168, 8);
      Point point93 = point1;
      label36_1.Location = point93;
      this.Label36.Name = "Label36";
      Label label36_2 = this.Label36;
      size1 = new Size(3, 20);
      Size size93 = size1;
      label36_2.Size = size93;
      this.Label36.TabIndex = 392;
      this.CuentasDupe.Cursor = Cursors.Hand;
      this.CuentasDupe.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      ListBox cuentasDupe1 = this.CuentasDupe;
      point1 = new Point(2, 28);
      Point point94 = point1;
      cuentasDupe1.Location = point94;
      this.CuentasDupe.Name = "CuentasDupe";
      ListBox cuentasDupe2 = this.CuentasDupe;
      size1 = new Size(168, 95);
      Size size94 = size1;
      cuentasDupe2.Size = size94;
      this.CuentasDupe.TabIndex = 390;
      this.CuentasDupe.TabStop = false;
      this.InfracAccount.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.InfracAccount.ForeColor = Color.DimGray;
      Label infracAccount1 = this.InfracAccount;
      point1 = new Point(3, 12);
      Point point95 = point1;
      infracAccount1.Location = point95;
      this.InfracAccount.Name = "InfracAccount";
      Label infracAccount2 = this.InfracAccount;
      size1 = new Size(163, 18);
      Size size95 = size1;
      infracAccount2.Size = size95;
      this.InfracAccount.TabIndex = 391;
      this.InfracAccount.Text = "Cuenta Infractora";
      this.InfracAccount.TextAlign = ContentAlignment.TopCenter;
      this.RelatedAccount.BackColor = Color.Black;
      this.RelatedAccount.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.RelatedAccount.ForeColor = Color.DimGray;
      Label relatedAccount1 = this.RelatedAccount;
      point1 = new Point(169, 12);
      Point point96 = point1;
      relatedAccount1.Location = point96;
      this.RelatedAccount.Name = "RelatedAccount";
      Label relatedAccount2 = this.RelatedAccount;
      size1 = new Size(168, 18);
      Size size96 = size1;
      relatedAccount2.Size = size96;
      this.RelatedAccount.TabIndex = 395;
      this.RelatedAccount.Text = "Relacion";
      this.RelatedAccount.TextAlign = ContentAlignment.TopCenter;
      this.N5.AutoCheck = false;
      CheckBox n5_1 = this.N5;
      point1 = new Point(310, 290);
      Point point97 = point1;
      n5_1.Location = point97;
      this.N5.Name = "N5";
      CheckBox n5_2 = this.N5;
      size1 = new Size(16, 14);
      Size size97 = size1;
      n5_2.Size = size97;
      this.N5.TabIndex = 431;
      this.N5.TabStop = false;
      this.N5.TextAlign = ContentAlignment.TopLeft;
      this.N1.AutoCheck = false;
      CheckBox n1_1 = this.N1;
      point1 = new Point(310, 228);
      Point point98 = point1;
      n1_1.Location = point98;
      this.N1.Name = "N1";
      CheckBox n1_2 = this.N1;
      size1 = new Size(16, 14);
      Size size98 = size1;
      n1_2.Size = size98;
      this.N1.TabIndex = 429;
      this.N1.TabStop = false;
      this.N1.TextAlign = ContentAlignment.TopLeft;
      this.S1.AutoCheck = false;
      CheckBox s1_1 = this.S1;
      point1 = new Point(266, 228);
      Point point99 = point1;
      s1_1.Location = point99;
      this.S1.Name = "S1";
      CheckBox s1_2 = this.S1;
      size1 = new Size(16, 14);
      Size size99 = size1;
      s1_2.Size = size99;
      this.S1.TabIndex = 428;
      this.S1.TabStop = false;
      this.S1.TextAlign = ContentAlignment.TopLeft;
      this.Label38.AutoSize = true;
      this.Label38.BackColor = Color.Black;
      this.Label38.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label38.ForeColor = Color.DimGray;
      Label label38_1 = this.Label38;
      point1 = new Point(211, 244);
      Point point100 = point1;
      label38_1.Location = point100;
      this.Label38.Name = "Label38";
      Label label38_2 = this.Label38;
      size1 = new Size(52, 13);
      Size size100 = size1;
      label38_2.Size = size100;
      this.Label38.TabIndex = 423;
      this.Label38.Text = "Full 380";
      this.Label38.TextAlign = ContentAlignment.MiddleRight;
      this.Label39.AutoSize = true;
      this.Label39.BackColor = Color.Black;
      this.Label39.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label39.ForeColor = Color.DimGray;
      Label label39_1 = this.Label39;
      point1 = new Point(192, 290);
      Point point101 = point1;
      label39_1.Location = point101;
      this.Label39.Name = "Label39";
      Label label39_2 = this.Label39;
      size1 = new Size(71, 13);
      Size size101 = size1;
      label39_2.Size = size101;
      this.Label39.TabIndex = 422;
      this.Label39.Text = "ExeAncient";
      this.Label39.TextAlign = ContentAlignment.MiddleRight;
      this.Label40.AutoSize = true;
      this.Label40.BackColor = Color.Black;
      this.Label40.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label40.ForeColor = Color.DimGray;
      Label label40_1 = this.Label40;
      point1 = new Point(208, 228);
      Point point102 = point1;
      label40_1.Location = point102;
      this.Label40.Name = "Label40";
      Label label40_2 = this.Label40;
      size1 = new Size(55, 13);
      Size size102 = size1;
      label40_2.Size = size102;
      this.Label40.TabIndex = 421;
      this.Label40.Text = "Full EXE";
      this.Label40.TextAlign = ContentAlignment.MiddleRight;
      this.CargaParcial.BackColor = SystemColors.Control;
      ProgressBar cargaParcial1 = this.CargaParcial;
      point1 = new Point(2, 403);
      Point point103 = point1;
      cargaParcial1.Location = point103;
      this.CargaParcial.Name = "CargaParcial";
      ProgressBar cargaParcial2 = this.CargaParcial;
      size1 = new Size(338, 10);
      Size size103 = size1;
      cargaParcial2.Size = size103;
      this.CargaParcial.TabIndex = 397;
      this.CargaTotal.BackColor = SystemColors.Control;
      ProgressBar cargaTotal1 = this.CargaTotal;
      point1 = new Point(2, 413);
      Point point104 = point1;
      cargaTotal1.Location = point104;
      this.CargaTotal.Name = "CargaTotal";
      ProgressBar cargaTotal2 = this.CargaTotal;
      size1 = new Size(338, 10);
      Size size104 = size1;
      cargaTotal2.Size = size104;
      this.CargaTotal.TabIndex = 396;
      this.ImagenItemFound.BackColor = Color.Black;
      this.ImagenItemFound.Cursor = Cursors.Default;
      this.ImagenItemFound.ImeMode = ImeMode.NoControl;
      PictureBox imagenItemFound1 = this.ImagenItemFound;
      point1 = new Point(4, 185);
      Point point105 = point1;
      imagenItemFound1.Location = point105;
      this.ImagenItemFound.Name = "ImagenItemFound";
      PictureBox imagenItemFound2 = this.ImagenItemFound;
      size1 = new Size(165, 165);
      Size size105 = size1;
      imagenItemFound2.Size = size105;
      this.ImagenItemFound.SizeMode = PictureBoxSizeMode.CenterImage;
      this.ImagenItemFound.TabIndex = 412;
      this.ImagenItemFound.TabStop = false;
      this.TIPS.BackColor = SystemColors.AppWorkspace;
      this.TIPS.Cursor = Cursors.Default;
      this.TIPS.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.TIPS.ForeColor = Color.DarkRed;
      Label tips1 = this.TIPS;
      point1 = new Point(1, 352);
      Point point106 = point1;
      tips1.Location = point106;
      this.TIPS.Name = "TIPS";
      Label tips2 = this.TIPS;
      size1 = new Size(338, 13);
      Size size106 = size1;
      tips2.Size = size106;
      this.TIPS.TabIndex = 469;
      this.TIPS.Text = "USE WITH SERVER OFF / NEED MANY TIME TO SCAN ALL";
      this.TIPS.TextAlign = ContentAlignment.MiddleCenter;
      this.AllSerials.BackColor = Color.Black;
      this.AllSerials.Cursor = Cursors.Hand;
      this.AllSerials.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.AllSerials.ForeColor = Color.Gray;
      CheckBox allSerials1 = this.AllSerials;
      point1 = new Point(293, 410);
      Point point107 = point1;
      allSerials1.Location = point107;
      this.AllSerials.Name = "AllSerials";
      CheckBox allSerials2 = this.AllSerials;
      size1 = new Size(81, 20);
      Size size107 = size1;
      allSerials2.Size = size107;
      this.AllSerials.TabIndex = 456;
      this.AllSerials.TabStop = false;
      this.AllSerials.Text = "All S/N !!";
      this.AllSerials.UseVisualStyleBackColor = false;
      this.Extra.BackColor = Color.Transparent;
      this.Extra.Checked = true;
      this.Extra.CheckState = CheckState.Checked;
      this.Extra.Cursor = Cursors.Hand;
      this.Extra.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Extra.ForeColor = Color.DimGray;
      // ISSUE: reference to a compiler-generated method
      this.Extra.Image = (Image) Class34.smethod_73();
      this.Extra.ImageAlign = ContentAlignment.MiddleRight;
      CheckBox extra1 = this.Extra;
      point1 = new Point(616, 67);
      Point point108 = point1;
      extra1.Location = point108;
      this.Extra.Name = "Extra";
      this.Extra.RightToLeft = RightToLeft.Yes;
      CheckBox extra2 = this.Extra;
      size1 = new Size(90, 26);
      Size size108 = size1;
      extra2.Size = size108;
      this.Extra.TabIndex = 450;
      this.Extra.TabStop = false;
      this.Extra.Text = "Extra";
      this.Extra.UseVisualStyleBackColor = false;
      this.Invent.BackColor = Color.Transparent;
      this.Invent.Checked = true;
      this.Invent.CheckState = CheckState.Checked;
      this.Invent.Cursor = Cursors.Hand;
      this.Invent.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Invent.ForeColor = Color.DimGray;
      // ISSUE: reference to a compiler-generated method
      this.Invent.Image = (Image) Class34.smethod_71();
      this.Invent.ImageAlign = ContentAlignment.MiddleRight;
      CheckBox invent1 = this.Invent;
      point1 = new Point(382, 67);
      Point point109 = point1;
      invent1.Location = point109;
      this.Invent.Name = "Invent";
      this.Invent.RightToLeft = RightToLeft.Yes;
      CheckBox invent2 = this.Invent;
      size1 = new Size(114, 26);
      Size size109 = size1;
      invent2.Size = size109;
      this.Invent.TabIndex = 400;
      this.Invent.TabStop = false;
      this.Invent.Text = "Inventary";
      this.Invent.UseVisualStyleBackColor = false;
      this.Vault.BackColor = Color.Transparent;
      this.Vault.Checked = true;
      this.Vault.CheckState = CheckState.Checked;
      this.Vault.Cursor = Cursors.Hand;
      this.Vault.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Vault.ForeColor = Color.DimGray;
      // ISSUE: reference to a compiler-generated method
      this.Vault.Image = (Image) Class34.smethod_112();
      this.Vault.ImageAlign = ContentAlignment.MiddleRight;
      CheckBox vault1 = this.Vault;
      point1 = new Point(510, 67);
      Point point110 = point1;
      vault1.Location = point110;
      this.Vault.Name = "Vault";
      this.Vault.RightToLeft = RightToLeft.Yes;
      CheckBox vault2 = this.Vault;
      size1 = new Size(90, 26);
      Size size110 = size1;
      vault2.Size = size110;
      this.Vault.TabIndex = 399;
      this.Vault.TabStop = false;
      this.Vault.Text = "Vault";
      this.Vault.UseVisualStyleBackColor = false;
      this.BotonFullEXE.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonFullEXE.BackgroundImage = (Image) Class34.smethod_12();
      this.BotonFullEXE.BackgroundImageLayout = ImageLayout.Center;
      this.BotonFullEXE.Cursor = Cursors.Hand;
      this.BotonFullEXE.FlatAppearance.BorderSize = 0;
      this.BotonFullEXE.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BotonFullEXE.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BotonFullEXE.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BotonFullEXE.FlatStyle = FlatStyle.Flat;
      this.BotonFullEXE.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BotonFullEXE.ForeColor = Color.Transparent;
      Button botonFullExe1 = this.BotonFullEXE;
      point1 = new Point(16, 14);
      Point point111 = point1;
      botonFullExe1.Location = point111;
      this.BotonFullEXE.Name = "BotonFullEXE";
      Button botonFullExe2 = this.BotonFullEXE;
      size1 = new Size(32, 21);
      Size size111 = size1;
      botonFullExe2.Size = size111;
      this.BotonFullEXE.TabIndex = 1903;
      this.BotonFullEXE.TabStop = false;
      this.BotonFullEXE.UseVisualStyleBackColor = false;
      this.GroupBox1.BackColor = Color.Transparent;
      this.GroupBox1.Controls.Add((Control) this.BotonFullEXE);
      this.GroupBox1.Font = new Font("Microsoft Sans Serif", 6.75f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.GroupBox1.ForeColor = Color.DarkOrange;
      GroupBox groupBox1_1 = this.GroupBox1;
      point1 = new Point(381, 26);
      Point point112 = point1;
      groupBox1_1.Location = point112;
      this.GroupBox1.Name = "GroupBox1";
      GroupBox groupBox1_2 = this.GroupBox1;
      size1 = new Size(64, 40);
      Size size112 = size1;
      groupBox1_2.Size = size112;
      this.GroupBox1.TabIndex = 1904;
      this.GroupBox1.TabStop = false;
      this.GroupBox1.Text = "Full EXE";
      this.GroupBox2.BackColor = Color.Transparent;
      this.GroupBox2.Controls.Add((Control) this.BotonFull380);
      this.GroupBox2.Font = new Font("Microsoft Sans Serif", 6.75f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.GroupBox2.ForeColor = Color.DarkOrange;
      GroupBox groupBox2_1 = this.GroupBox2;
      point1 = new Point(447, 26);
      Point point113 = point1;
      groupBox2_1.Location = point113;
      this.GroupBox2.Name = "GroupBox2";
      GroupBox groupBox2_2 = this.GroupBox2;
      size1 = new Size(64, 40);
      Size size113 = size1;
      groupBox2_2.Size = size113;
      this.GroupBox2.TabIndex = 1905;
      this.GroupBox2.TabStop = false;
      this.GroupBox2.Text = "Full 380";
      this.BotonFull380.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonFull380.BackgroundImage = (Image) Class34.smethod_12();
      this.BotonFull380.BackgroundImageLayout = ImageLayout.Center;
      this.BotonFull380.Cursor = Cursors.Hand;
      this.BotonFull380.FlatAppearance.BorderSize = 0;
      this.BotonFull380.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BotonFull380.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BotonFull380.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BotonFull380.FlatStyle = FlatStyle.Flat;
      this.BotonFull380.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BotonFull380.ForeColor = Color.Transparent;
      Button botonFull380_1 = this.BotonFull380;
      point1 = new Point(16, 14);
      Point point114 = point1;
      botonFull380_1.Location = point114;
      this.BotonFull380.Name = "BotonFull380";
      Button botonFull380_2 = this.BotonFull380;
      size1 = new Size(32, 21);
      Size size114 = size1;
      botonFull380_2.Size = size114;
      this.BotonFull380.TabIndex = 1903;
      this.BotonFull380.TabStop = false;
      this.BotonFull380.UseVisualStyleBackColor = false;
      this.GroupBox3.BackColor = Color.Transparent;
      this.GroupBox3.Controls.Add((Control) this.BotonFullJoH);
      this.GroupBox3.Font = new Font("Microsoft Sans Serif", 6.75f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.GroupBox3.ForeColor = Color.DarkOrange;
      GroupBox groupBox3_1 = this.GroupBox3;
      point1 = new Point(513, 26);
      Point point115 = point1;
      groupBox3_1.Location = point115;
      this.GroupBox3.Name = "GroupBox3";
      GroupBox groupBox3_2 = this.GroupBox3;
      size1 = new Size(64, 40);
      Size size115 = size1;
      groupBox3_2.Size = size115;
      this.GroupBox3.TabIndex = 1905;
      this.GroupBox3.TabStop = false;
      this.GroupBox3.Text = "Full JoH";
      this.BotonFullJoH.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonFullJoH.BackgroundImage = (Image) Class34.smethod_12();
      this.BotonFullJoH.BackgroundImageLayout = ImageLayout.Center;
      this.BotonFullJoH.Cursor = Cursors.Hand;
      this.BotonFullJoH.FlatAppearance.BorderSize = 0;
      this.BotonFullJoH.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BotonFullJoH.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BotonFullJoH.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BotonFullJoH.FlatStyle = FlatStyle.Flat;
      this.BotonFullJoH.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BotonFullJoH.ForeColor = Color.Transparent;
      Button botonFullJoH1 = this.BotonFullJoH;
      point1 = new Point(16, 14);
      Point point116 = point1;
      botonFullJoH1.Location = point116;
      this.BotonFullJoH.Name = "BotonFullJoH";
      Button botonFullJoH2 = this.BotonFullJoH;
      size1 = new Size(32, 21);
      Size size116 = size1;
      botonFullJoH2.Size = size116;
      this.BotonFullJoH.TabIndex = 1903;
      this.BotonFullJoH.TabStop = false;
      this.BotonFullJoH.UseVisualStyleBackColor = false;
      this.GroupBox4.BackColor = Color.Transparent;
      this.GroupBox4.Controls.Add((Control) this.BotonFullSK);
      this.GroupBox4.Font = new Font("Microsoft Sans Serif", 6.75f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.GroupBox4.ForeColor = Color.DarkOrange;
      GroupBox groupBox4_1 = this.GroupBox4;
      point1 = new Point(579, 26);
      Point point117 = point1;
      groupBox4_1.Location = point117;
      this.GroupBox4.Name = "GroupBox4";
      GroupBox groupBox4_2 = this.GroupBox4;
      size1 = new Size(64, 40);
      Size size117 = size1;
      groupBox4_2.Size = size117;
      this.GroupBox4.TabIndex = 1906;
      this.GroupBox4.TabStop = false;
      this.GroupBox4.Text = "Full SK";
      this.BotonFullSK.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonFullSK.BackgroundImage = (Image) Class34.smethod_12();
      this.BotonFullSK.BackgroundImageLayout = ImageLayout.Center;
      this.BotonFullSK.Cursor = Cursors.Hand;
      this.BotonFullSK.FlatAppearance.BorderSize = 0;
      this.BotonFullSK.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BotonFullSK.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BotonFullSK.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BotonFullSK.FlatStyle = FlatStyle.Flat;
      this.BotonFullSK.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BotonFullSK.ForeColor = Color.Transparent;
      Button botonFullSk1 = this.BotonFullSK;
      point1 = new Point(16, 14);
      Point point118 = point1;
      botonFullSk1.Location = point118;
      this.BotonFullSK.Name = "BotonFullSK";
      Button botonFullSk2 = this.BotonFullSK;
      size1 = new Size(32, 21);
      Size size118 = size1;
      botonFullSk2.Size = size118;
      this.BotonFullSK.TabIndex = 1903;
      this.BotonFullSK.TabStop = false;
      this.BotonFullSK.UseVisualStyleBackColor = false;
      this.GroupBox5.BackColor = Color.Transparent;
      this.GroupBox5.Controls.Add((Control) this.BotonEXEANC);
      this.GroupBox5.Font = new Font("Microsoft Sans Serif", 6.75f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.GroupBox5.ForeColor = Color.DarkOrange;
      GroupBox groupBox5_1 = this.GroupBox5;
      point1 = new Point(645, 26);
      Point point119 = point1;
      groupBox5_1.Location = point119;
      this.GroupBox5.Name = "GroupBox5";
      GroupBox groupBox5_2 = this.GroupBox5;
      size1 = new Size(64, 40);
      Size size119 = size1;
      groupBox5_2.Size = size119;
      this.GroupBox5.TabIndex = 1907;
      this.GroupBox5.TabStop = false;
      this.GroupBox5.Text = "Exe Anc";
      this.BotonEXEANC.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BotonEXEANC.BackgroundImage = (Image) Class34.smethod_12();
      this.BotonEXEANC.BackgroundImageLayout = ImageLayout.Center;
      this.BotonEXEANC.Cursor = Cursors.Hand;
      this.BotonEXEANC.FlatAppearance.BorderSize = 0;
      this.BotonEXEANC.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BotonEXEANC.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BotonEXEANC.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BotonEXEANC.FlatStyle = FlatStyle.Flat;
      this.BotonEXEANC.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BotonEXEANC.ForeColor = Color.Transparent;
      Button botonExeanc1 = this.BotonEXEANC;
      point1 = new Point(16, 14);
      Point point120 = point1;
      botonExeanc1.Location = point120;
      this.BotonEXEANC.Name = "BotonEXEANC";
      Button botonExeanc2 = this.BotonEXEANC;
      size1 = new Size(32, 21);
      Size size120 = size1;
      botonExeanc2.Size = size120;
      this.BotonEXEANC.TabIndex = 1903;
      this.BotonEXEANC.TabStop = false;
      this.BotonEXEANC.UseVisualStyleBackColor = false;
      this.Label25.BackColor = Color.Gray;
      this.Label25.ImeMode = ImeMode.NoControl;
      Label label25_1 = this.Label25;
      point1 = new Point(380, 64);
      Point point121 = point1;
      label25_1.Location = point121;
      this.Label25.Name = "Label25";
      Label label25_2 = this.Label25;
      size1 = new Size(336, 2);
      Size size121 = size1;
      label25_2.Size = size121;
      this.Label25.TabIndex = 1908;
      this.Label43.BackColor = Color.Gray;
      this.Label43.ImeMode = ImeMode.NoControl;
      Label label43_1 = this.Label43;
      point1 = new Point(380, 95);
      Point point122 = point1;
      label43_1.Location = point122;
      this.Label43.Name = "Label43";
      Label label43_2 = this.Label43;
      size1 = new Size(336, 2);
      Size size122 = size1;
      label43_2.Size = size122;
      this.Label43.TabIndex = 1909;
      this.Clean.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Clean.BackgroundImage = (Image) Class34.smethod_4();
      this.Clean.BackgroundImageLayout = ImageLayout.Center;
      this.Clean.Cursor = Cursors.Hand;
      this.Clean.FlatAppearance.BorderSize = 0;
      this.Clean.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.Clean.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.Clean.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.Clean.FlatStyle = FlatStyle.Flat;
      this.Clean.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Clean.ForeColor = Color.Transparent;
      Button clean1 = this.Clean;
      point1 = new Point(385, 99);
      Point point123 = point1;
      clean1.Location = point123;
      this.Clean.Name = "Clean";
      Button clean2 = this.Clean;
      size1 = new Size(32, 25);
      Size size123 = size1;
      clean2.Size = size123;
      this.Clean.TabIndex = 1904;
      this.Clean.TabStop = false;
      this.Clean.UseVisualStyleBackColor = false;
      this.Seleccionado.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Seleccionado.BackgroundImage = (Image) Class34.smethod_117();
      this.Seleccionado.BackgroundImageLayout = ImageLayout.Center;
      this.Seleccionado.Cursor = Cursors.Hand;
      this.Seleccionado.FlatAppearance.BorderSize = 0;
      this.Seleccionado.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.Seleccionado.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.Seleccionado.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.Seleccionado.FlatStyle = FlatStyle.Flat;
      this.Seleccionado.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Seleccionado.ForeColor = Color.Transparent;
      Button seleccionado1 = this.Seleccionado;
      point1 = new Point(513, 99);
      Point point124 = point1;
      seleccionado1.Location = point124;
      this.Seleccionado.Name = "Seleccionado";
      Button seleccionado2 = this.Seleccionado;
      size1 = new Size(32, 25);
      Size size124 = size1;
      seleccionado2.Size = size124;
      this.Seleccionado.TabIndex = 1910;
      this.Seleccionado.TabStop = false;
      this.Seleccionado.UseVisualStyleBackColor = false;
      this.Todos.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Todos.BackgroundImage = (Image) Class34.smethod_53();
      this.Todos.BackgroundImageLayout = ImageLayout.Center;
      this.Todos.Cursor = Cursors.Hand;
      this.Todos.FlatAppearance.BorderSize = 0;
      this.Todos.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.Todos.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.Todos.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.Todos.FlatStyle = FlatStyle.Flat;
      this.Todos.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Todos.ForeColor = Color.Transparent;
      Button todos1 = this.Todos;
      point1 = new Point(616, 97);
      Point point125 = point1;
      todos1.Location = point125;
      this.Todos.Name = "Todos";
      Button todos2 = this.Todos;
      size1 = new Size(52, 28);
      Size size125 = size1;
      todos2.Size = size125;
      this.Todos.TabIndex = 1911;
      this.Todos.TabStop = false;
      this.Todos.UseVisualStyleBackColor = false;
      this.Label21.BackColor = Color.Black;
      this.Label21.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label21.ForeColor = Color.DimGray;
      Label label21_1 = this.Label21;
      point1 = new Point(419, 97);
      Point point126 = point1;
      label21_1.Location = point126;
      this.Label21.Name = "Label21";
      Label label21_2 = this.Label21;
      size1 = new Size(64, 29);
      Size size126 = size1;
      label21_2.Size = size126;
      this.Label21.TabIndex = 470;
      this.Label21.Text = "Clean Results";
      this.Label21.TextAlign = ContentAlignment.MiddleLeft;
      this.Label22.BackColor = Color.Black;
      this.Label22.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label22.ForeColor = Color.DimGray;
      Label label22_1 = this.Label22;
      point1 = new Point(545, 97);
      Point point127 = point1;
      label22_1.Location = point127;
      this.Label22.Name = "Label22";
      Label label22_2 = this.Label22;
      size1 = new Size(63, 29);
      Size size127 = size1;
      label22_2.Size = size127;
      this.Label22.TabIndex = 1912;
      this.Label22.Text = "Delete Selected";
      this.Label22.TextAlign = ContentAlignment.MiddleLeft;
      this.Label30.BackColor = Color.Black;
      this.Label30.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label30.ForeColor = Color.DimGray;
      Label label30_1 = this.Label30;
      point1 = new Point(668, 97);
      Point point128 = point1;
      label30_1.Location = point128;
      this.Label30.Name = "Label30";
      Label label30_2 = this.Label30;
      size1 = new Size(54, 29);
      Size size128 = size1;
      label30_2.Size = size128;
      this.Label30.TabIndex = 1913;
      this.Label30.Text = "All Results";
      this.Label30.TextAlign = ContentAlignment.MiddleLeft;
      this.CapaCodeOculto.Controls.Add((Control) this.Pos);
      this.CapaCodeOculto.Controls.Add((Control) this.CodeItems);
      this.CapaCodeOculto.Font = new Font("Microsoft Sans Serif", 12f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.CapaCodeOculto.ForeColor = Color.Red;
      GroupBox capaCodeOculto1 = this.CapaCodeOculto;
      point1 = new Point(193, 174);
      Point point129 = point1;
      capaCodeOculto1.Location = point129;
      this.CapaCodeOculto.Name = "CapaCodeOculto";
      GroupBox capaCodeOculto2 = this.CapaCodeOculto;
      size1 = new Size(172, 84);
      Size size129 = size1;
      capaCodeOculto2.Size = size129;
      this.CapaCodeOculto.TabIndex = 470;
      this.CapaCodeOculto.TabStop = false;
      this.CapaCodeOculto.Text = "CapaCodeOculto";
      this.CapaCodeOculto.Visible = false;
      this.Pos.Enabled = false;
      this.Pos.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      ListBox pos1 = this.Pos;
      point1 = new Point(85, 24);
      Point point130 = point1;
      pos1.Location = point130;
      this.Pos.Name = "Pos";
      ListBox pos2 = this.Pos;
      size1 = new Size(81, 56);
      Size size130 = size1;
      pos2.Size = size130;
      this.Pos.TabIndex = 391;
      this.Pos.TabStop = false;
      this.CodeItems.Enabled = false;
      this.CodeItems.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      ListBox codeItems1 = this.CodeItems;
      point1 = new Point(6, 24);
      Point point131 = point1;
      codeItems1.Location = point131;
      this.CodeItems.Name = "CodeItems";
      ListBox codeItems2 = this.CodeItems;
      size1 = new Size(76, 56);
      Size size131 = size1;
      codeItems2.Size = size131;
      this.CodeItems.TabIndex = 390;
      this.CodeItems.TabStop = false;
      this.Socket3.BackColor = Color.Black;
      this.Socket3.Cursor = Cursors.Hand;
      this.Socket3.Enabled = false;
      this.Socket3.ForeColor = Color.DarkViolet;
      ComboBox socket3_1 = this.Socket3;
      point1 = new Point(359, 563);
      Point point132 = point1;
      socket3_1.Location = point132;
      this.Socket3.Name = "Socket3";
      ComboBox socket3_2 = this.Socket3;
      size1 = new Size(357, 21);
      Size size132 = size1;
      socket3_2.Size = size132;
      this.Socket3.TabIndex = 1917;
      this.Socket5.BackColor = Color.Black;
      this.Socket5.Cursor = Cursors.Hand;
      this.Socket5.Enabled = false;
      this.Socket5.ForeColor = Color.DarkViolet;
      ComboBox socket5_1 = this.Socket5;
      point1 = new Point(359, 605);
      Point point133 = point1;
      socket5_1.Location = point133;
      this.Socket5.Name = "Socket5";
      ComboBox socket5_2 = this.Socket5;
      size1 = new Size(357, 21);
      Size size133 = size1;
      socket5_2.Size = size133;
      this.Socket5.TabIndex = 1918;
      this.Socket2.BackColor = Color.Black;
      this.Socket2.Cursor = Cursors.Hand;
      this.Socket2.Enabled = false;
      this.Socket2.ForeColor = Color.DarkViolet;
      ComboBox socket2_1 = this.Socket2;
      point1 = new Point(2, 605);
      Point point134 = point1;
      socket2_1.Location = point134;
      this.Socket2.Name = "Socket2";
      ComboBox socket2_2 = this.Socket2;
      size1 = new Size(357, 21);
      Size size134 = size1;
      socket2_2.Size = size134;
      this.Socket2.TabIndex = 1916;
      this.Socket4.BackColor = Color.Black;
      this.Socket4.Cursor = Cursors.Hand;
      this.Socket4.Enabled = false;
      this.Socket4.ForeColor = Color.DarkViolet;
      ComboBox socket4_1 = this.Socket4;
      point1 = new Point(359, 584);
      Point point135 = point1;
      socket4_1.Location = point135;
      this.Socket4.Name = "Socket4";
      ComboBox socket4_2 = this.Socket4;
      size1 = new Size(357, 21);
      Size size135 = size1;
      socket4_2.Size = size135;
      this.Socket4.TabIndex = 1914;
      this.Socket1.BackColor = Color.Black;
      this.Socket1.Cursor = Cursors.Hand;
      this.Socket1.Enabled = false;
      this.Socket1.ForeColor = Color.DarkViolet;
      ComboBox socket1_1 = this.Socket1;
      point1 = new Point(2, 584);
      Point point136 = point1;
      socket1_1.Location = point136;
      this.Socket1.Name = "Socket1";
      ComboBox socket1_2 = this.Socket1;
      size1 = new Size(357, 21);
      Size size136 = size1;
      socket1_2.Size = size136;
      this.Socket1.TabIndex = 1915;
      this.SocketSystem.AutoSize = true;
      this.SocketSystem.Enabled = false;
      this.SocketSystem.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.SocketSystem.ForeColor = Color.DarkViolet;
      CheckBox socketSystem1 = this.SocketSystem;
      point1 = new Point(6, 565);
      Point point137 = point1;
      socketSystem1.Location = point137;
      this.SocketSystem.Name = "SocketSystem";
      CheckBox socketSystem2 = this.SocketSystem;
      size1 = new Size(110, 17);
      Size size137 = size1;
      socketSystem2.Size = size137;
      this.SocketSystem.TabIndex = 1919;
      this.SocketSystem.Text = "Socket System";
      this.SocketSystem.UseVisualStyleBackColor = true;
      this.AutoScaleMode = AutoScaleMode.Inherit;
      this.BackColor = Color.Black;
      // ISSUE: reference to a compiler-generated method
      this.BackgroundImage = (Image) Class34.smethod_61();
      this.BackgroundImageLayout = ImageLayout.None;
      size1 = new Size(718, 648);
      this.ClientSize = size1;
      this.Controls.Add((Control) this.Socket3);
      this.Controls.Add((Control) this.Socket5);
      this.Controls.Add((Control) this.Socket2);
      this.Controls.Add((Control) this.Socket4);
      this.Controls.Add((Control) this.Socket1);
      this.Controls.Add((Control) this.SocketSystem);
      this.Controls.Add((Control) this.Label2);
      this.Controls.Add((Control) this.Label43);
      this.Controls.Add((Control) this.Label30);
      this.Controls.Add((Control) this.Label22);
      this.Controls.Add((Control) this.Label21);
      this.Controls.Add((Control) this.Todos);
      this.Controls.Add((Control) this.Seleccionado);
      this.Controls.Add((Control) this.Clean);
      this.Controls.Add((Control) this.Label25);
      this.Controls.Add((Control) this.GroupBox5);
      this.Controls.Add((Control) this.GroupBox4);
      this.Controls.Add((Control) this.GroupBox3);
      this.Controls.Add((Control) this.GroupBox2);
      this.Controls.Add((Control) this.Label14);
      this.Controls.Add((Control) this.Label1);
      this.Controls.Add((Control) this.Titulo);
      this.Controls.Add((Control) this.Cerrar);
      this.Controls.Add((Control) this.Minimizar);
      this.Controls.Add((Control) this.Label12);
      this.Controls.Add((Control) this.Label8);
      this.Controls.Add((Control) this.Opcion2);
      this.Controls.Add((Control) this.SetAncient);
      this.Controls.Add((Control) this.Level2);
      this.Controls.Add((Control) this.Tipo2);
      this.Controls.Add((Control) this.Tipo1);
      this.Controls.Add((Control) this.Foto);
      this.Controls.Add((Control) this.Label17);
      this.Controls.Add((Control) this.JoHOPs);
      this.Controls.Add((Control) this.JoHOP);
      this.Controls.Add((Control) this.JHOP);
      this.Controls.Add((Control) this.RF1);
      this.Controls.Add((Control) this.RF2);
      this.Controls.Add((Control) this.Label6);
      this.Controls.Add((Control) this.Label18);
      this.Controls.Add((Control) this.Codigo);
      this.Controls.Add((Control) this.Serial);
      this.Controls.Add((Control) this.Dur);
      this.Controls.Add((Control) this.Siz);
      this.Controls.Add((Control) this.Label13);
      this.Controls.Add((Control) this.Label3);
      this.Controls.Add((Control) this.Extra);
      this.Controls.Add((Control) this.Nombre);
      this.Controls.Add((Control) this.Label19);
      this.Controls.Add((Control) this.Label10);
      this.Controls.Add((Control) this.Label9);
      this.Controls.Add((Control) this.Imagen);
      this.Controls.Add((Control) this.Opcion);
      this.Controls.Add((Control) this.Level);
      this.Controls.Add((Control) this.Numero);
      this.Controls.Add((Control) this.Label23);
      this.Controls.Add((Control) this.Items);
      this.Controls.Add((Control) this.Label7);
      this.Controls.Add((Control) this.Luck);
      this.Controls.Add((Control) this.Invent);
      this.Controls.Add((Control) this.Vault);
      this.Controls.Add((Control) this.Label5);
      this.Controls.Add((Control) this.Label4);
      this.Controls.Add((Control) this.Siz2);
      this.Controls.Add((Control) this.Dur2);
      this.Controls.Add((Control) this.RF);
      this.Controls.Add((Control) this.EXE6);
      this.Controls.Add((Control) this.EXE4);
      this.Controls.Add((Control) this.EXE5);
      this.Controls.Add((Control) this.EXE3);
      this.Controls.Add((Control) this.EXE2);
      this.Controls.Add((Control) this.EXE1);
      this.Controls.Add((Control) this.Ancient1);
      this.Controls.Add((Control) this.NoAncient);
      this.Controls.Add((Control) this.Ancient2);
      this.Controls.Add((Control) this.GroupBox1);
      this.Controls.Add((Control) this.BoxItemFinder);
      this.Controls.Add((Control) this.AllSerials);
      this.Controls.Add((Control) this.Skill);
      this.Controls.Add((Control) this.CapaCodeOculto);
      this.FormBorderStyle = FormBorderStyle.None;
      this.Icon = (Icon) componentResourceManager.GetObject("$this.Icon");
      this.MaximizeBox = false;
      size1 = new Size(718, 648);
      this.MaximumSize = size1;
      this.MinimizeBox = false;
      size1 = new Size(718, 648);
      this.MinimumSize = size1;
      this.Name = "FinderMaker";
      this.StartPosition = FormStartPosition.CenterScreen;
      this.Text = "FinderMaker";
      ((ISupportInitialize) this.Imagen).EndInit();
      this.BoxItemFinder.ResumeLayout(false);
      this.BoxItemFinder.PerformLayout();
      this.Cuentas.EndInit();
      this.Status.EndInit();
      this.TextLoad1.EndInit();
      this.TextLoad2.EndInit();
      ((ISupportInitialize) this.ImagenItemFound).EndInit();
      this.GroupBox1.ResumeLayout(false);
      this.GroupBox2.ResumeLayout(false);
      this.GroupBox3.ResumeLayout(false);
      this.GroupBox4.ResumeLayout(false);
      this.GroupBox5.ResumeLayout(false);
      this.CapaCodeOculto.ResumeLayout(false);
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

    public object CargarJoH()
    {
      if (Class24.struct4_2.int_3 == 0)
      {
        this.JHOP.Checked = false;
        this.JHOP.Enabled = false;
      }
      else
        this.JHOP.Enabled = true;
      this.JoHOP.Items.Clear();
      int num1 = 1;
      int num2 = Class6.int_1;
      int num3 = num1;
      while (num3 <= num2)
      {
        this.JoHOP.Items.Add((object) Class6.string_17[checked (num3 - 1)]);
        checked { ++num3; }
      }
      try
      {
        this.JoHOP.SelectedIndex = 0;
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        ProjectData.ClearProjectError();
      }
      return (object) true;
    }

    public object CargarJoHOP()
    {
      this.JoHOPs.Items.Clear();
      int num1 = 1;
      int num2 = Class6.int_2;
      int num3 = num1;
      while (num3 <= num2)
      {
        this.JoHOPs.Items.Add(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(this.JoHOP.SelectedItem, (object) " "), (object) Class6.string_18[checked (num3 - 1)]));
        checked { ++num3; }
      }
      try
      {
        this.JoHOPs.SelectedIndex = 0;
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        ProjectData.ClearProjectError();
      }
      return (object) true;
    }

    public object CargarSocketSystem()
    {
      this.Socket1.Items.Clear();
      this.Socket2.Items.Clear();
      this.Socket3.Items.Clear();
      this.Socket4.Items.Clear();
      this.Socket5.Items.Clear();
      int num1 = 1;
      do
      {
        this.Socket1.Items.Add((object) ("Socket 1 : " + Class6.string_21[checked (num1 - 1)] + " (" + Class6.string_22[checked (num1 - 1)] + ")"));
        this.Socket2.Items.Add((object) ("Socket 2 : " + Class6.string_21[checked (num1 - 1)] + " (" + Class6.string_22[checked (num1 - 1)] + ")"));
        this.Socket3.Items.Add((object) ("Socket 3 : " + Class6.string_21[checked (num1 - 1)] + " (" + Class6.string_22[checked (num1 - 1)] + ")"));
        this.Socket4.Items.Add((object) ("Socket 4 : " + Class6.string_21[checked (num1 - 1)] + " (" + Class6.string_22[checked (num1 - 1)] + ")"));
        this.Socket5.Items.Add((object) ("Socket 5 : " + Class6.string_21[checked (num1 - 1)] + " (" + Class6.string_22[checked (num1 - 1)] + ")"));
        checked { ++num1; }
      }
      while (num1 <= 2);
      int num2 = 3;
      int num3 = Conversions.ToInteger(Class6.string_30);
      int num4 = num2;
      while (num4 <= num3)
      {
        this.Socket1.Items.Add((object) ("Socket 1 : " + Class6.string_21[checked (num4 - 1)] + " (" + Class6.string_22[checked (num4 - 1)] + ") + " + Class6.string_24[checked (num4 - 1)]));
        this.Socket2.Items.Add((object) ("Socket 2 : " + Class6.string_21[checked (num4 - 1)] + " (" + Class6.string_22[checked (num4 - 1)] + ") + " + Class6.string_24[checked (num4 - 1)]));
        this.Socket3.Items.Add((object) ("Socket 3 : " + Class6.string_21[checked (num4 - 1)] + " (" + Class6.string_22[checked (num4 - 1)] + ") + " + Class6.string_24[checked (num4 - 1)]));
        this.Socket4.Items.Add((object) ("Socket 4 : " + Class6.string_21[checked (num4 - 1)] + " (" + Class6.string_22[checked (num4 - 1)] + ") + " + Class6.string_24[checked (num4 - 1)]));
        this.Socket5.Items.Add((object) ("Socket 5 : " + Class6.string_21[checked (num4 - 1)] + " (" + Class6.string_22[checked (num4 - 1)] + ") + " + Class6.string_24[checked (num4 - 1)]));
        checked { ++num4; }
      }
      try
      {
        this.Socket1.SelectedIndex = 0;
        this.Socket2.SelectedIndex = 0;
        this.Socket3.SelectedIndex = 0;
        this.Socket4.SelectedIndex = 0;
        this.Socket5.SelectedIndex = 0;
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        ProjectData.ClearProjectError();
      }
      return (object) true;
    }

    public object MostrarInfoItemFound()
    {
      string str = "";
      Class7.smethod_0();
      try
      {
        Class28.sqlConnection_1.Open();
        Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
        Class28.sqlCommand_1.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "SELECT * FROM MuMakerFinderMaker WHERE AC='", this.CuentasDupe.SelectedItem), (object) "' AND PJ='"), this.PJDupe.SelectedItem), (object) "' AND Item='"), this.CodeItems.SelectedItem), (object) "' AND Pos='"), this.Pos.SelectedItem), (object) "';"));
        Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
        while (Class28.sqlDataReader_1.Read())
        {
          this.Cuenta1.Text = Conversions.ToString(Class28.sqlDataReader_1["AC"]);
          this.Personaje1.Text = Conversions.ToString(Class28.sqlDataReader_1["PJ"]);
          if (Conversions.ToBoolean(Conversions.ToString(Class28.sqlDataReader_1["Invent"])))
          {
            this.RadioInvent.Checked = true;
            this.RadioInvent.Enabled = true;
          }
          else
            this.RadioInvent.Enabled = false;
          if (Conversions.ToBoolean(Conversions.ToString(Class28.sqlDataReader_1["Vault"])))
          {
            this.RadioVault.Checked = true;
            this.RadioVault.Enabled = true;
          }
          else
            this.RadioVault.Enabled = false;
          if (Conversions.ToBoolean(Conversions.ToString(Class28.sqlDataReader_1["ExtraW"])))
          {
            this.RadioExtra.Checked = true;
            this.RadioExtra.Enabled = true;
          }
          else
            this.RadioExtra.Enabled = false;
          Class22.struct2_0.int_0 = Conversions.ToInteger(Conversions.ToString(Class28.sqlDataReader_1["NumExtraW"]));
          Class9.smethod_2((object) Conversions.ToString(Class28.sqlDataReader_1["Item"]));
          if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Class24.struct4_1.string_15, "5", false) != 0 & Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Class24.struct4_1.string_15, "9", false) != 0 & Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Class24.struct4_1.string_15, "A", false) != 0)
          {
            str = "";
          }
          else
          {
            if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Class24.struct4_1.string_15, "5", false) == 0 | Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Class24.struct4_1.string_15, "9", false) == 0)
              str = Class24.struct4_1.string_32;
            if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Class24.struct4_1.string_15, "A", false) == 0)
              str = Class24.struct4_1.string_33;
          }
          this.ItemName.Text = " " + str + Class24.struct4_1.string_19 + Class24.struct4_1.string_3 + Class24.struct4_1.string_9 + Class24.struct4_1.string_14 + Class24.struct4_1.string_13 + Class24.struct4_1.string_12;
          this.ItemCode.Text = Conversions.ToString(Class28.sqlDataReader_1["Item"]);
          this.ItemSerial.Text = Conversions.ToString(Class28.sqlDataReader_1["Serial"]);
          if (Conversions.ToBoolean(Conversions.ToString(Class28.sqlDataReader_1["FullEXE"])))
          {
            this.S1.Checked = true;
            this.N1.Checked = false;
          }
          else
          {
            this.S1.Checked = false;
            this.N1.Checked = true;
          }
          if (Conversions.ToBoolean(Conversions.ToString(Class28.sqlDataReader_1["Full380"])))
          {
            this.S2.Checked = true;
            this.N2.Checked = false;
          }
          else
          {
            this.S2.Checked = false;
            this.N2.Checked = true;
          }
          if (Conversions.ToBoolean(Conversions.ToString(Class28.sqlDataReader_1["FullJoH"])))
          {
            this.S3.Checked = true;
            this.N3.Checked = false;
          }
          else
          {
            this.S3.Checked = false;
            this.N3.Checked = true;
          }
          if (Conversions.ToBoolean(Conversions.ToString(Class28.sqlDataReader_1["FullSck"])))
          {
            this.S4.Checked = true;
            this.N4.Checked = false;
          }
          else
          {
            this.S4.Checked = false;
            this.N4.Checked = true;
          }
          if (Conversions.ToBoolean(Conversions.ToString(Class28.sqlDataReader_1["ExeAnc"])))
          {
            this.S5.Checked = true;
            this.N5.Checked = false;
          }
          else
          {
            this.S5.Checked = false;
            this.N5.Checked = true;
          }
          Class15.smethod_1();
          this.ImagenItemFound.Image = Class18.smethod_30(Class18.smethod_31((object) Class31.string_5));
          Class29.string_0 = Conversions.ToString(Class28.sqlDataReader_1["CodeItems"]);
        }
        Class28.sqlDataReader_1.Close();
        Class20.smethod_0();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      Class7.smethod_5();
      return (object) true;
    }

    public object AnalizarDatos()
    {
      if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Class24.struct4_2.string_9, "NO", false) == 0)
      {
        this.Level.Enabled = true;
        Class24.struct4_0.string_9 = Conversions.ToString(this.Level.SelectedItem);
      }
      else
      {
        this.Level.Enabled = false;
        if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Class24.struct4_2.string_9, "SN", false) == 0)
          this.Level.SelectedIndex = 0;
        else
          this.Level.SelectedItem = (object) Class24.struct4_2.string_9;
      }
      if (Class24.struct4_2.bool_0)
      {
        this.Opcion.Enabled = true;
      }
      else
      {
        this.Opcion.Enabled = false;
        this.Opcion.SelectedIndex = 0;
      }
      if (Class24.struct4_2.bool_1)
      {
        this.Luck.Enabled = true;
      }
      else
      {
        this.Luck.Checked = false;
        this.Luck.Enabled = false;
      }
      if (Class24.struct4_2.bool_2)
      {
        this.Skill.Enabled = true;
      }
      else
      {
        this.Skill.Checked = false;
        this.Skill.Enabled = false;
      }
      if (Class24.struct4_2.bool_3)
      {
        this.NoAncient.Enabled = true;
        this.Ancient1.Enabled = true;
        this.Ancient2.Enabled = true;
      }
      else
      {
        this.NoAncient.Select();
        this.NoAncient.Enabled = false;
        this.Ancient1.Enabled = false;
        this.Ancient2.Enabled = false;
      }
      if ((double) Class24.struct4_2.int_0 != Conversions.ToDouble("0"))
      {
        this.EXE1.Enabled = true;
        this.EXE2.Enabled = true;
        this.EXE3.Enabled = true;
        this.EXE4.Enabled = true;
        this.EXE5.Enabled = true;
        this.EXE6.Enabled = true;
      }
      else
      {
        this.EXE1.Enabled = false;
        this.EXE2.Enabled = false;
        this.EXE3.Enabled = false;
        this.EXE4.Enabled = false;
        this.EXE5.Enabled = false;
        this.EXE6.Enabled = false;
        this.EXE1.Checked = false;
        this.EXE2.Checked = false;
        this.EXE3.Checked = false;
        this.EXE4.Checked = false;
        this.EXE5.Checked = false;
        this.EXE6.Checked = false;
      }
      if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Class24.struct4_2.string_32, "NO", false) != 0)
      {
        this.Ancient1.Text = "Set " + Class24.struct4_2.string_32;
        this.Ancient1.Enabled = true;
      }
      else
      {
        this.Ancient1.Text = "No 1º Set";
        this.Ancient1.Enabled = false;
        if (!this.Ancient2.Checked)
          this.NoAncient.Checked = true;
      }
      if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Class24.struct4_2.string_33, "NO", false) != 0)
      {
        this.Ancient2.Text = "Set " + Class24.struct4_2.string_33;
        this.Ancient2.Enabled = true;
      }
      else
      {
        this.Ancient2.Text = "No 2º Set";
        this.Ancient2.Enabled = false;
        if (!this.Ancient1.Checked)
          this.NoAncient.Checked = true;
      }
      this.Items.Focus();
      return (object) true;
    }

    public object Excepciones()
    {
      if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Class24.struct4_2.string_7, "001", false) == 0)
      {
        this.Numero.Enabled = true;
        this.Dur.Text = Conversions.ToString(this.Numero.SelectedItem);
      }
      else
      {
        this.Numero.Enabled = false;
        this.Numero.SelectedItem = (object) "001";
      }
      if ((double) Class24.struct4_2.int_0 == Conversions.ToDouble("0"))
      {
        this.EXE1.Text = Conversions.ToString(Class30.object_27);
        this.EXE2.Text = Conversions.ToString(Class30.object_27);
        this.EXE3.Text = Conversions.ToString(Class30.object_27);
        this.EXE4.Text = Conversions.ToString(Class30.object_27);
        this.EXE5.Text = Conversions.ToString(Class30.object_27);
        this.EXE6.Text = Conversions.ToString(Class30.object_27);
      }
      if ((double) Class24.struct4_2.int_0 == Conversions.ToDouble("1"))
      {
        this.EXE1.Text = Conversions.ToString(Class30.object_28);
        this.EXE2.Text = Conversions.ToString(Class30.object_29);
        this.EXE3.Text = Conversions.ToString(Class30.object_30);
        this.EXE4.Text = Conversions.ToString(Class30.object_31);
        this.EXE5.Text = Conversions.ToString(Class30.object_32);
        this.EXE6.Text = Conversions.ToString(Class30.object_33);
      }
      if ((double) Class24.struct4_2.int_0 == Conversions.ToDouble("2"))
      {
        this.EXE1.Text = Conversions.ToString(Class30.object_34);
        this.EXE2.Text = Conversions.ToString(Class30.object_35);
        this.EXE3.Text = Conversions.ToString(Class30.object_36);
        this.EXE4.Text = Conversions.ToString(Class30.object_37);
        this.EXE5.Text = Conversions.ToString(Class30.object_38);
        this.EXE6.Text = Conversions.ToString(Class30.object_39);
      }
      if ((double) Class24.struct4_2.int_0 == Conversions.ToDouble("3"))
      {
        this.EXE1.Text = Conversions.ToString(Class30.object_40);
        this.EXE2.Text = Conversions.ToString(Class30.object_41);
        this.EXE3.Text = Conversions.ToString(Class30.object_42);
        this.EXE4.Text = Conversions.ToString(Class30.object_43);
        this.EXE5.Text = Conversions.ToString(Class30.object_44);
        this.EXE6.Text = Conversions.ToString(Class30.object_45);
      }
      if ((double) Class24.struct4_2.int_0 == Conversions.ToDouble("4"))
      {
        this.EXE1.Text = Conversions.ToString(Class30.object_46);
        this.EXE2.Text = Conversions.ToString(Class30.object_47);
        this.EXE3.Text = Conversions.ToString(Class30.object_48);
        this.EXE4.Text = Conversions.ToString(Class30.object_49);
        this.EXE5.Text = Conversions.ToString(Class30.object_50);
        this.EXE6.Text = Conversions.ToString(Class30.object_51);
        this.EXE4.Enabled = false;
        this.EXE5.Enabled = false;
        this.EXE6.Enabled = false;
      }
      if ((double) Class24.struct4_2.int_0 == Conversions.ToDouble("5"))
      {
        this.EXE1.Text = Conversions.ToString(Class30.object_39);
        this.EXE2.Text = Conversions.ToString(Class30.object_38);
        this.EXE3.Text = Conversions.ToString(Class30.object_37);
        this.EXE4.Text = Conversions.ToString(Class30.object_36);
        this.EXE5.Text = Conversions.ToString(Class30.object_35);
        this.EXE6.Text = Conversions.ToString(Class30.object_34);
      }
      if ((double) Class24.struct4_2.int_0 == Conversions.ToDouble("6"))
      {
        this.EXE1.Text = Conversions.ToString(Class30.object_33);
        this.EXE2.Text = Conversions.ToString(Class30.object_32);
        this.EXE3.Text = Conversions.ToString(Class30.object_31);
        this.EXE4.Text = Conversions.ToString(Class30.object_30);
        this.EXE5.Text = Conversions.ToString(Class30.object_29);
        this.EXE6.Text = Conversions.ToString(Class30.object_28);
      }
      if ((double) Class24.struct4_2.int_2 == Conversions.ToDouble("0"))
      {
        this.RF1.Text = "Refinery Option 1";
        this.RF2.Text = "Refinery Option 2";
        this.RF.Enabled = false;
        this.RF.Checked = false;
      }
      if ((double) Class24.struct4_2.int_2 == Conversions.ToDouble("1"))
      {
        this.RF1.Text = Conversions.ToString(Class30.object_60);
        this.RF2.Text = Conversions.ToString(Class30.object_61);
        this.RF.Enabled = true;
      }
      if ((double) Class24.struct4_2.int_2 == Conversions.ToDouble("2"))
      {
        this.RF1.Text = Conversions.ToString(Class30.object_62);
        this.RF2.Text = Conversions.ToString(Class30.object_63);
        this.RF.Enabled = true;
      }
      if ((double) Class24.struct4_2.int_2 == Conversions.ToDouble("3"))
      {
        this.RF1.Text = Conversions.ToString(Class30.object_64);
        this.RF2.Text = Conversions.ToString(Class30.object_65);
        this.RF.Enabled = true;
      }
      if ((double) Class24.struct4_2.int_2 == Conversions.ToDouble("4"))
      {
        this.RF1.Text = Conversions.ToString(Class30.object_64);
        this.RF2.Text = Conversions.ToString(Class30.object_65);
        this.RF.Enabled = true;
      }
      if ((double) Class24.struct4_2.int_2 == Conversions.ToDouble("5"))
      {
        this.RF1.Text = Conversions.ToString(Class30.object_66);
        this.RF2.Text = Conversions.ToString(Class30.object_67);
        this.RF.Enabled = true;
      }
      if ((double) Class24.struct4_2.int_2 == Conversions.ToDouble("6"))
      {
        this.RF1.Text = Conversions.ToString(Class30.object_70);
        this.RF2.Text = Conversions.ToString(Class30.object_71);
        this.RF.Enabled = true;
      }
      if (!this.RF.Enabled)
      {
        this.RF1.Enabled = false;
        this.RF2.Enabled = false;
      }
      else
      {
        this.RF1.Enabled = true;
        this.RF2.Enabled = true;
      }
      if (this.JHOP.Checked)
      {
        this.JoHOP.Enabled = true;
        this.JoHOPs.Enabled = true;
      }
      else
      {
        this.JoHOP.Enabled = false;
        this.JoHOPs.Enabled = false;
      }
      if (!Class24.struct4_2.bool_4)
      {
        this.SocketSystem.Checked = false;
        this.SocketSystem.Enabled = false;
      }
      else
        this.SocketSystem.Enabled = true;
      return (object) true;
    }

    public object ExepcionFenrir()
    {
      if ((double) Class24.struct4_2.int_0 == Conversions.ToDouble("4"))
      {
        if (this.EXE1.Checked)
        {
          this.EXE2.Checked = false;
          this.EXE3.Checked = false;
        }
        if (this.EXE2.Checked)
        {
          this.EXE1.Checked = false;
          this.EXE3.Checked = false;
        }
        if (this.EXE3.Checked)
        {
          this.EXE1.Checked = false;
          this.EXE2.Checked = false;
        }
      }
      return (object) true;
    }

    public object ExepcionFenrir1()
    {
      if ((double) Class24.struct4_2.int_0 == Conversions.ToDouble("4") && this.EXE1.Checked)
      {
        this.EXE2.Checked = false;
        this.EXE3.Checked = false;
      }
      return (object) true;
    }

    public object ExepcionFenrir2()
    {
      if ((double) Class24.struct4_2.int_0 == Conversions.ToDouble("4") && this.EXE2.Checked)
      {
        this.EXE1.Checked = false;
        this.EXE3.Checked = false;
      }
      return (object) true;
    }

    public object ExepcionFenrir3()
    {
      if ((double) Class24.struct4_2.int_0 == Conversions.ToDouble("4") && this.EXE3.Checked)
      {
        this.EXE1.Checked = false;
        this.EXE2.Checked = false;
      }
      return (object) true;
    }

    public object BorrarVault(object CS)
    {
      int num1 = Conversions.ToInteger(Microsoft.VisualBasic.CompilerServices.Operators.MultiplyObject(CS, (object) 32));
      int Start = checked (num1 + 1);
      Strings.Mid(Class29.string_0, Conversions.ToInteger(Microsoft.VisualBasic.CompilerServices.Operators.SubtractObject(Microsoft.VisualBasic.CompilerServices.Operators.MultiplyObject(CS, (object) 32), (object) 31)), 32);
      string str = "0x" + (!Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(CS, (object) 1, false) ? Strings.Mid(Class29.string_0, 1, checked (num1 - 32)) + "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF" + Strings.Mid(Class29.string_0, Start) : "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF" + Strings.Mid(Class29.string_0, 33));
      Class7.smethod_0();
      Class28.sqlConnection_1.Open();
      Class20.smethod_9((object) str);
      try
      {
        SqlCommand sqlCommand1 = new SqlCommand();
        SqlCommand sqlCommand2 = new SqlCommand("MMK_ItemMakerWareHous", Class28.sqlConnection_1);
        sqlCommand2.CommandType = CommandType.StoredProcedure;
        sqlCommand2.Parameters.Add(new SqlParameter("@AccountID", SqlDbType.VarChar, 10)
        {
          Direction = ParameterDirection.Input
        });
        sqlCommand2.Parameters["@AccountID"].Value = (object) this.Cuenta1.Text;
        sqlCommand2.ExecuteNonQuery();
        sqlCommand2.Dispose();
        sqlCommand1.Dispose();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num2 = (int) Interaction.MsgBox(RuntimeHelpers.GetObjectValue(Class30.object_80), MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      Class7.smethod_5();
      this.ActualizarDB((object) Class29.string_0, (object) Strings.Mid(str, 3), RuntimeHelpers.GetObjectValue(CS));
      return (object) true;
    }

    public object BorrarInvent(object CS)
    {
      int num1 = Conversions.ToInteger(Microsoft.VisualBasic.CompilerServices.Operators.MultiplyObject(CS, (object) 32));
      int Start = checked (num1 + 1);
      Strings.Mid(Class29.string_0, Conversions.ToInteger(Microsoft.VisualBasic.CompilerServices.Operators.SubtractObject(Microsoft.VisualBasic.CompilerServices.Operators.MultiplyObject(CS, (object) 32), (object) 31)), 32);
      string str = "0x" + (!Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(CS, (object) 1, false) ? Strings.Mid(Class29.string_0, 1, checked (num1 - 32)) + "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF" + Strings.Mid(Class29.string_0, Start) : "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF" + Strings.Mid(Class29.string_0, 33));
      Class7.smethod_0();
      Class28.sqlConnection_1.Open();
      Class20.smethod_10((object) str);
      try
      {
        SqlCommand sqlCommand1 = new SqlCommand();
        SqlCommand sqlCommand2 = new SqlCommand("MMK_ItemMakerInventory", Class28.sqlConnection_1);
        sqlCommand2.CommandType = CommandType.StoredProcedure;
        sqlCommand2.Parameters.Add(new SqlParameter("@AccountID", SqlDbType.VarChar, 10)
        {
          Direction = ParameterDirection.Input
        });
        sqlCommand2.Parameters.Add(new SqlParameter("@Name", SqlDbType.VarChar, 10)
        {
          Direction = ParameterDirection.Input
        });
        sqlCommand2.Parameters["@AccountID"].Value = (object) this.Cuenta1.Text;
        sqlCommand2.Parameters["@Name"].Value = (object) this.Personaje1.Text;
        sqlCommand2.ExecuteNonQuery();
        sqlCommand2.Dispose();
        sqlCommand1.Dispose();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num2 = (int) Interaction.MsgBox(RuntimeHelpers.GetObjectValue(Class30.object_80), MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      Class7.smethod_5();
      this.ActualizarDB((object) Class29.string_0, (object) Strings.Mid(str, 3), RuntimeHelpers.GetObjectValue(CS));
      return (object) true;
    }

    public object BorrarExtra(object CS)
    {
      int num1 = Conversions.ToInteger(Microsoft.VisualBasic.CompilerServices.Operators.MultiplyObject(CS, (object) 32));
      int Start = checked (num1 + 1);
      Strings.Mid(Class29.string_0, Conversions.ToInteger(Microsoft.VisualBasic.CompilerServices.Operators.SubtractObject(Microsoft.VisualBasic.CompilerServices.Operators.MultiplyObject(CS, (object) 32), (object) 31)), 32);
      string str = "0x" + (!Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(CS, (object) 1, false) ? Strings.Mid(Class29.string_0, 1, checked (num1 - 32)) + "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF" + Strings.Mid(Class29.string_0, Start) : "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF" + Strings.Mid(Class29.string_0, 33));
      Class7.smethod_0();
      Class28.sqlConnection_1.Open();
      Class20.smethod_9((object) str);
      try
      {
        SqlCommand sqlCommand1 = new SqlCommand();
        SqlCommand sqlCommand2 = new SqlCommand("MMK_ItemMakerWareHous", Class28.sqlConnection_1);
        sqlCommand2.CommandType = CommandType.StoredProcedure;
        sqlCommand2.Parameters.Add(new SqlParameter("@AccountID", SqlDbType.VarChar, 10)
        {
          Direction = ParameterDirection.Input
        });
        sqlCommand2.Parameters["@AccountID"].Value = (object) this.Cuenta1.Text;
        sqlCommand2.ExecuteNonQuery();
        sqlCommand2.Dispose();
        sqlCommand1.Dispose();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num2 = (int) Interaction.MsgBox(RuntimeHelpers.GetObjectValue(Class30.object_80), MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      Class7.smethod_5();
      this.ActualizarDB((object) Class29.string_0, (object) Strings.Mid(str, 3), RuntimeHelpers.GetObjectValue(CS));
      return (object) true;
    }

    private void method_0()
    {
      this.CuentasDupe.Focus();
      string str = Conversions.ToString(this.CuentasDupe.Items.Count);
      this.CargaTotal.Maximum = Conversions.ToInteger(str);
      this.CargaParcial.Maximum = Conversions.ToInteger(str);
      if (Conversions.ToDouble(str) >= 1.0)
        this.CuentasDupe.SelectedIndex = 0;
      if (this.CuentasDupe.SelectedIndex != -1)
      {
        this.OcultarBotones();
        int num = 1;
        while (Conversions.ToDouble(str) >= 1.0)
        {
          if (Class29.bool_0)
            return;
          if (this.RadioInvent.Checked)
          {
            Class12.smethod_1();
            this.BorrarInvent(RuntimeHelpers.GetObjectValue(this.Pos.SelectedItem));
          }
          if (Class29.bool_0)
            return;
          if (this.RadioVault.Checked)
          {
            Class12.smethod_1();
            this.BorrarVault(RuntimeHelpers.GetObjectValue(this.Pos.SelectedItem));
          }
          if (Class29.bool_0)
            return;
          if (this.RadioExtra.Checked)
          {
            this.BorrarExtra(RuntimeHelpers.GetObjectValue(this.Pos.SelectedItem));
            Class12.smethod_1();
          }
          Class29.string_1 = Conversions.ToString(this.CuentasDupe.SelectedIndex);
          this.PJDupe.Items.RemoveAt(Conversions.ToInteger(Class29.string_1));
          this.Pos.Items.RemoveAt(Conversions.ToInteger(Class29.string_1));
          this.CodeItems.Items.RemoveAt(Conversions.ToInteger(Class29.string_1));
          this.CuentasDupe.Items.RemoveAt(Conversions.ToInteger(Class29.string_1));
          this.CuentasDupe.Focus();
          if (Conversions.ToDouble(Class29.string_1) > 1.0)
            this.CuentasDupe.SelectedIndex = checked ((int) Math.Round(unchecked (Conversions.ToDouble(Class29.string_1) - 1.0)));
          if ((Conversions.ToDouble(Class29.string_1) == 0.0 | Conversions.ToDouble(Class29.string_1) == 1.0) & Conversions.ToDouble(str) > 1.0)
            this.CuentasDupe.SelectedIndex = 0;
          str = Conversions.ToString(this.CuentasDupe.Items.Count);
          this.CargaParcial.Value = num;
          this.CargaTotal.Value = num;
          this.TextLoad1.Text = Conversions.ToString(Math.Round((double) this.CargaParcial.Value / (double) this.CargaParcial.Maximum * 100.0)) + "%";
          this.TextLoad2.Text = Conversions.ToString(Math.Round((double) this.CargaTotal.Value / (double) this.CargaTotal.Maximum * 100.0)) + "%";
          checked { ++num; }
        }
      }
      this.CargaParcial.Maximum = 100;
      this.CargaParcial.Value = 100;
      this.TextLoad1.Text = " 100%";
      this.CargaTotal.Maximum = 100;
      this.CargaTotal.Value = 100;
      this.TextLoad2.Text = "100%";
      this.Resetear();
      this.MostrarBotones();
    }

    public object Traducir()
    {
      this.Foto.Text = Conversions.ToString(Class30.object_9);
      this.Level2.Text = Conversions.ToString(Class30.object_10);
      this.Opcion2.Text = Conversions.ToString(Class30.object_11);
      this.Account1.Text = Conversions.ToString(Class30.object_5);
      this.Chart1.Text = Conversions.ToString(Class30.object_6);
      this.InfracAccount.Text = Conversions.ToString(Class30.object_22);
      this.RelatedAccount.Text = Conversions.ToString(Class30.object_23);
      this.Text = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) (this.Text + " - "), Class26.object_18));
      this.Titulo.Text = this.Text;
      return (object) true;
    }

    private void FinderMaker_Load(object sender, EventArgs e)
    {
      VentanaBarraLoad.DefInstance.Show();
      Class18.smethod_45();
      VentanaBarraLoad.DefInstance.Carga.Value = 1;
      Class21.smethod_1();
      VentanaBarraLoad.DefInstance.Carga.Value = 5;
      Class13.smethod_1();
      VentanaBarraLoad.DefInstance.Carga.Value = 10;
      Class10.smethod_6();
      Class10.smethod_9();
      VentanaBarraLoad.DefInstance.Carga.Value = 20;
      this.Cuentas.Text = Conversions.ToString(Class29.int_1) + " Accounts";
      VentanaBarraLoad.DefInstance.Carga.Value = 40;
      Class9.smethod_0();
      VentanaBarraLoad.DefInstance.Carga.Value = 45;
      Class10.smethod_5();
      VentanaBarraLoad.DefInstance.Carga.Value = 55;
      Class21.smethod_4();
      this.NoAncient.Select();
      VentanaBarraLoad.DefInstance.Carga.Value = 60;
      this.Level.SelectedIndex = 0;
      VentanaBarraLoad.DefInstance.Carga.Value = 65;
      this.Opcion.SelectedIndex = 0;
      VentanaBarraLoad.DefInstance.Carga.Value = 70;
      this.Tipo1.SelectedIndex = 0;
      this.Numero.SelectedIndex = 0;
      this.CargarSocketSystem();
      VentanaBarraLoad.DefInstance.Carga.Value = 80;
      this.Traducir();
      VentanaBarraLoad.DefInstance.Carga.Value = 90;
      Class21.smethod_2();
      VentanaBarraLoad.DefInstance.Carga.Value = 100;
      this.CuentasDupe.Focus();
      VentanaBarraLoad.DefInstance.Hide();
    }

    private void Tipo1_SelectedIndexChanged(object sender, EventArgs e)
    {
      Class7.smethod_10();
      int num1 = 0;
      try
      {
        Class28.oleDbConnection_0.Open();
        Class28.oleDbCommand_0.Connection = Class28.oleDbConnection_0;
        Class28.oleDbCommand_0.CommandText = "SELECT NAME FROM Items WHERE CATEGORIA='" + this.Tipo1.Text + "' ORDER BY Nº ASC;";
        Class28.oleDbCommand_0.ExecuteNonQuery();
        Class28.oleDbDataReader_0 = Class28.oleDbCommand_0.ExecuteReader();
        this.Items.Items.Clear();
        num1 = 0;
        while (Class28.oleDbDataReader_0.Read())
        {
          this.Items.Items.Add((object) Conversions.ToString(Class28.oleDbDataReader_0["NAME"]));
          checked { ++num1; }
        }
        Class28.oleDbDataReader_0.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num2 = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      Class7.smethod_11();
      if (num1 > 0)
        this.Items.SelectedIndex = !(this.Tipo1.SelectedIndex == 9 | this.Tipo1.SelectedIndex == 10 | this.Tipo1.SelectedIndex == 11 | this.Tipo1.SelectedIndex == 12 | this.Tipo1.SelectedIndex == 13) ? 0 : Class24.struct4_2.int_5;
      this.Items.Focus();
    }

    private void Tipo2_SelectedIndexChanged(object sender, EventArgs e)
    {
      Class7.smethod_10();
      int num1 = 0;
      try
      {
        Class28.oleDbConnection_0.Open();
        Class28.oleDbCommand_0.Connection = Class28.oleDbConnection_0;
        Class28.oleDbCommand_0.CommandText = "SELECT NAME FROM Items WHERE CATEGORIA='" + this.Tipo2.Text + "' ORDER BY Nº ASC;";
        Class28.oleDbCommand_0.ExecuteNonQuery();
        Class28.oleDbDataReader_0 = Class28.oleDbCommand_0.ExecuteReader();
        this.Items.Items.Clear();
        num1 = 0;
        while (Class28.oleDbDataReader_0.Read())
        {
          this.Items.Items.Add((object) Conversions.ToString(Class28.oleDbDataReader_0["NAME"]));
          checked { ++num1; }
        }
        Class28.oleDbDataReader_0.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num2 = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      Class7.smethod_11();
      if (num1 > 0)
        this.Items.SelectedIndex = 0;
      this.Items.Focus();
    }

    private void Items_SelectedIndexChanged(object sender, EventArgs e)
    {
      Class9.smethod_1((object) this.Items.Text);
      this.AnalizarDatos();
      this.Excepciones();
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      Class15.smethod_14();
      this.Dur.Text = Class24.struct4_0.string_7;
      Class10.smethod_7((object) Class24.struct4_2.int_3);
      this.CargarJoH();
      Class10.smethod_8((object) Class24.struct4_2.int_3, (object) checked (this.JoHOP.SelectedIndex - 1));
      this.CargarJoHOP();
      Class15.smethod_0((object) Class24.struct4_2.string_0);
      this.Imagen.Image = Class18.smethod_30(Class18.smethod_31((object) Class31.string_1));
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
      this.SerialSearch.Text = this.Serial.Text;
      this.ItemCodeSearch.Text = this.Codigo.Text;
      this.Siz.Text = Class24.struct4_2.string_4 + "x" + Class24.struct4_2.string_5;
    }

    private void Level_SelectedIndexChanged(object sender, EventArgs e)
    {
      Class24.struct4_0.string_9 = Conversions.ToString(this.Level.SelectedIndex);
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      Class15.smethod_14();
      this.Dur.Text = Class24.struct4_0.string_7;
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void Opcion_SelectedIndexChanged(object sender, EventArgs e)
    {
      Class24.struct4_0.string_12 = Conversions.ToString(this.Opcion.SelectedItem);
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      Class15.smethod_14();
      this.Dur.Text = Class24.struct4_0.string_7;
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void EXE1_CheckedChanged(object sender, EventArgs e)
    {
      this.ExepcionFenrir1();
      Class24.struct4_0.int_1 = !this.EXE1.Checked ? checked (Class24.struct4_0.int_1 - 1) : checked (Class24.struct4_0.int_1 + 1);
      Class24.struct4_0.int_0 = Class24.struct4_0.int_1 <= 0 ? 0 : 1;
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      Class15.smethod_14();
      this.Dur.Text = Class24.struct4_0.string_7;
      Class15.smethod_0((object) Class24.struct4_2.string_0);
      this.Imagen.Image = Class18.smethod_30(Class18.smethod_31((object) Class31.string_1));
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void EXE2_CheckedChanged(object sender, EventArgs e)
    {
      this.ExepcionFenrir2();
      Class24.struct4_0.int_1 = !this.EXE2.Checked ? checked (Class24.struct4_0.int_1 - 2) : checked (Class24.struct4_0.int_1 + 2);
      Class24.struct4_0.int_0 = Class24.struct4_0.int_1 <= 0 ? 0 : 1;
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      Class15.smethod_14();
      this.Dur.Text = Class24.struct4_0.string_7;
      Class15.smethod_0((object) Class24.struct4_2.string_0);
      this.Imagen.Image = Class18.smethod_30(Class18.smethod_31((object) Class31.string_1));
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void EXE3_CheckedChanged(object sender, EventArgs e)
    {
      this.ExepcionFenrir3();
      Class24.struct4_0.int_1 = !this.EXE3.Checked ? checked (Class24.struct4_0.int_1 - 4) : checked (Class24.struct4_0.int_1 + 4);
      Class24.struct4_0.int_0 = Class24.struct4_0.int_1 <= 0 ? 0 : 1;
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      Class15.smethod_14();
      this.Dur.Text = Class24.struct4_0.string_7;
      Class15.smethod_0((object) Class24.struct4_2.string_0);
      this.Imagen.Image = Class18.smethod_30(Class18.smethod_31((object) Class31.string_1));
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void EXE4_CheckedChanged(object sender, EventArgs e)
    {
      this.ExepcionFenrir();
      Class24.struct4_0.int_1 = !this.EXE4.Checked ? checked (Class24.struct4_0.int_1 - 8) : checked (Class24.struct4_0.int_1 + 8);
      Class24.struct4_0.int_0 = Class24.struct4_0.int_1 <= 0 ? 0 : 1;
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      Class15.smethod_14();
      this.Dur.Text = Class24.struct4_0.string_7;
      Class15.smethod_0((object) Class24.struct4_2.string_0);
      this.Imagen.Image = Class18.smethod_30(Class18.smethod_31((object) Class31.string_1));
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void EXE5_CheckedChanged(object sender, EventArgs e)
    {
      this.ExepcionFenrir();
      Class24.struct4_0.int_1 = !this.EXE5.Checked ? checked (Class24.struct4_0.int_1 - 16) : checked (Class24.struct4_0.int_1 + 16);
      Class24.struct4_0.int_0 = Class24.struct4_0.int_1 <= 0 ? 0 : 1;
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      Class15.smethod_14();
      this.Dur.Text = Class24.struct4_0.string_7;
      Class15.smethod_0((object) Class24.struct4_2.string_0);
      this.Imagen.Image = Class18.smethod_30(Class18.smethod_31((object) Class31.string_1));
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void EXE6_CheckedChanged(object sender, EventArgs e)
    {
      this.ExepcionFenrir();
      Class24.struct4_0.int_1 = !this.EXE6.Checked ? checked (Class24.struct4_0.int_1 - 32) : checked (Class24.struct4_0.int_1 + 32);
      Class24.struct4_0.int_0 = Class24.struct4_0.int_1 <= 0 ? 0 : 1;
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      Class15.smethod_14();
      this.Dur.Text = Class24.struct4_0.string_7;
      Class15.smethod_0((object) Class24.struct4_2.string_0);
      this.Imagen.Image = Class18.smethod_30(Class18.smethod_31((object) Class31.string_1));
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void NoAncient_CheckedChanged(object sender, EventArgs e)
    {
      if (this.NoAncient.Checked)
      {
        Class24.struct4_0.bool_3 = false;
        Class24.struct4_0.string_17 = "0";
        Class24.struct4_0.string_18 = "0";
      }
      else
        Class24.struct4_0.bool_3 = true;
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      Class15.smethod_14();
      this.Dur.Text = Class24.struct4_0.string_7;
      Class15.smethod_0((object) Class24.struct4_2.string_0);
      this.Imagen.Image = Class18.smethod_30(Class18.smethod_31((object) Class31.string_1));
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void Ancient1_CheckedChanged(object sender, EventArgs e)
    {
      if (this.Ancient1.Checked)
      {
        Class24.struct4_0.bool_3 = true;
        Class24.struct4_0.string_17 = "1";
        Class24.struct4_0.string_18 = "0";
      }
      else
      {
        Class24.struct4_0.bool_3 = false;
        Class24.struct4_0.string_17 = "0";
        Class24.struct4_0.string_18 = "1";
      }
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      Class15.smethod_14();
      this.Dur.Text = Class24.struct4_0.string_7;
      Class15.smethod_0((object) Class24.struct4_2.string_0);
      this.Imagen.Image = Class18.smethod_30(Class18.smethod_31((object) Class31.string_1));
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void Ancient2_CheckedChanged(object sender, EventArgs e)
    {
      if (this.Ancient2.Checked)
      {
        Class24.struct4_0.bool_3 = true;
        Class24.struct4_0.string_17 = "0";
        Class24.struct4_0.string_18 = "1";
      }
      else
      {
        Class24.struct4_0.bool_3 = false;
        Class24.struct4_0.string_17 = "1";
        Class24.struct4_0.string_18 = "0";
      }
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      Class15.smethod_14();
      this.Dur.Text = Class24.struct4_0.string_7;
      Class15.smethod_0((object) Class24.struct4_2.string_0);
      this.Imagen.Image = Class18.smethod_30(Class18.smethod_31((object) Class31.string_1));
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void Luck_CheckedChanged(object sender, EventArgs e)
    {
      Class24.struct4_0.bool_1 = this.Luck.Checked;
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      Class15.smethod_14();
      this.Dur.Text = Class24.struct4_0.string_7;
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void Skill_CheckedChanged(object sender, EventArgs e)
    {
      Class24.struct4_0.bool_2 = this.Skill.Checked;
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      Class15.smethod_14();
      this.Dur.Text = Class24.struct4_0.string_7;
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void Numero_SelectedIndexChanged(object sender, EventArgs e)
    {
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      Class24.struct4_2.string_8 = Conversions.ToString(this.Numero.SelectedItem);
      Class15.smethod_14();
      this.Dur.Text = Class24.struct4_0.string_7;
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void RF_CheckedChanged(object sender, EventArgs e)
    {
      Class24.struct4_0.int_2 = !this.RF.Checked ? Conversions.ToInteger("0") : Conversions.ToInteger("8");
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      Class15.smethod_14();
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void JHOP_CheckedChanged(object sender, EventArgs e)
    {
      Class10.smethod_7((object) Class24.struct4_2.int_3);
      this.CargarJoH();
      Class10.smethod_8((object) Class24.struct4_2.int_3, (object) checked (this.JoHOP.SelectedIndex - 1));
      this.CargarJoHOP();
      if (this.JHOP.Checked)
      {
        this.JoHOP.Enabled = true;
        this.JoHOPs.Enabled = true;
        this.JoHOP.SelectedItem = (object) 0;
        this.JoHOPs.SelectedItem = (object) 0;
      }
      else
      {
        this.JoHOP.SelectedItem = (object) 0;
        this.JoHOPs.SelectedItem = (object) 0;
        this.JoHOP.Enabled = false;
        this.JoHOPs.Enabled = false;
      }
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void JoHOP_SelectedIndexChanged(object sender, EventArgs e)
    {
      Class10.smethod_8((object) Class24.struct4_2.int_3, (object) checked (this.JoHOP.SelectedIndex - 1));
      this.CargarJoHOP();
      this.JoHOP.SelectedItem = (object) 0;
      this.JoHOPs.SelectedItem = (object) 0;
    }

    private void JoHOPs_SelectedIndexChanged(object sender, EventArgs e)
    {
      Class24.struct4_2.string_23 = Conversion.Hex(this.JoHOP.SelectedIndex);
      Class24.struct4_2.string_24 = Conversion.Hex(this.JoHOPs.SelectedIndex);
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void SocketSystem_CheckedChanged(object sender, EventArgs e)
    {
      if (this.SocketSystem.Checked)
      {
        this.Socket1.Enabled = true;
        this.Socket2.Enabled = true;
        this.Socket3.Enabled = true;
        this.Socket4.Enabled = true;
        this.Socket5.Enabled = true;
        this.Socket1.SelectedIndex = 0;
        this.Socket2.SelectedIndex = 0;
        this.Socket3.SelectedIndex = 0;
        this.Socket4.SelectedIndex = 0;
        this.Socket5.SelectedIndex = 0;
      }
      else
      {
        this.Socket1.Enabled = false;
        this.Socket2.Enabled = false;
        this.Socket3.Enabled = false;
        this.Socket4.Enabled = false;
        this.Socket5.Enabled = false;
        this.Socket1.SelectedIndex = 0;
        this.Socket2.SelectedIndex = 0;
        this.Socket3.SelectedIndex = 0;
        this.Socket4.SelectedIndex = 0;
        this.Socket5.SelectedIndex = 0;
      }
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void Socket1_SelectedIndexChanged(object sender, EventArgs e)
    {
      Class24.struct4_2.string_25 = Conversion.Hex((object) Class6.string_19[this.Socket1.SelectedIndex]);
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void Socket2_SelectedIndexChanged(object sender, EventArgs e)
    {
      Class24.struct4_2.string_26 = Conversion.Hex((object) Class6.string_19[this.Socket2.SelectedIndex]);
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void Socket3_SelectedIndexChanged(object sender, EventArgs e)
    {
      Class24.struct4_2.string_27 = Conversion.Hex((object) Class6.string_19[this.Socket3.SelectedIndex]);
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void Socket4_SelectedIndexChanged(object sender, EventArgs e)
    {
      Class24.struct4_2.string_28 = Conversion.Hex((object) Class6.string_19[this.Socket4.SelectedIndex]);
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void Socket5_SelectedIndexChanged(object sender, EventArgs e)
    {
      Class24.struct4_2.string_29 = Conversion.Hex((object) Class6.string_19[this.Socket5.SelectedIndex]);
      this.Nombre.Text = Conversions.ToString(Class15.smethod_2());
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
    }

    private void method_1(object sender, EventArgs e)
    {
      Class24.struct4_0.string_31 = this.Serial.Text;
      Class15.smethod_14();
      this.Dur.Text = Class24.struct4_0.string_7;
      this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
      this.SerialSearch.Text = this.Serial.Text;
    }

    private void method_2(object sender, EventArgs e)
    {
      this.Serial.SelectAll();
      this.SerialSearch.Text = this.Serial.Text;
    }

    private void method_3(object sender, EventArgs e)
    {
      if (this.Serial.Text.Length == 0)
        this.Serial.Text = "00000000";
      if (this.Serial.Text.Length == 1)
        this.Serial.Text = "0000000" + this.Serial.Text;
      if (this.Serial.Text.Length == 2)
        this.Serial.Text = "000000" + this.Serial.Text;
      if (this.Serial.Text.Length == 3)
        this.Serial.Text = "00000" + this.Serial.Text;
      if (this.Serial.Text.Length == 4)
        this.Serial.Text = "0000" + this.Serial.Text;
      if (this.Serial.Text.Length == 5)
        this.Serial.Text = "000" + this.Serial.Text;
      if (this.Serial.Text.Length == 6)
        this.Serial.Text = "00" + this.Serial.Text;
      if (this.Serial.Text.Length == 7)
        this.Serial.Text = "0" + this.Serial.Text;
      if (this.Serial.Text.Length == 8)
        this.Serial.Text = this.Serial.Text;
      this.Items.Focus();
    }

    private void AllSerials_CheckedChanged(object sender, EventArgs e)
    {
      if (this.AllSerials.Checked)
      {
        this.Serial.ReadOnly = true;
        this.Serial.Text = "XXXXXXXX";
        Class24.struct4_0.string_31 = this.Serial.Text;
        this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
        this.BuscarSerial.Enabled = false;
      }
      else
      {
        this.Serial.ReadOnly = false;
        this.Serial.Text = "00000000";
        Class24.struct4_0.string_31 = this.Serial.Text;
        this.Codigo.Text = Conversions.ToString(Class15.smethod_3());
        this.BuscarSerial.Enabled = true;
      }
    }

    private void Codigo_TextChanged(object sender, EventArgs e)
    {
      this.SerialSearch.Text = this.Serial.Text;
      this.ItemCodeSearch.Text = this.Codigo.Text;
    }

    public object Resetear()
    {
      this.CuentasDupe.Items.Clear();
      this.PJDupe.Items.Clear();
      this.CodeItems.Items.Clear();
      this.Pos.Items.Clear();
      this.CargaParcial.Value = 0;
      this.CargaTotal.Value = 0;
      this.Cuenta1.Text = "";
      this.Personaje1.Text = "";
      this.ItemName.Text = "";
      this.ItemCode.Text = "";
      this.ItemSerial.Text = "";
      Class29.string_0 = "";
      this.RadioInvent.Checked = false;
      this.RadioVault.Checked = false;
      this.RadioExtra.Checked = false;
      this.RadioInvent.Enabled = false;
      this.RadioVault.Enabled = false;
      this.RadioExtra.Enabled = false;
      this.S1.Checked = false;
      this.S5.Checked = false;
      this.S2.Checked = false;
      this.S3.Checked = false;
      this.N1.Checked = false;
      this.N2.Checked = false;
      this.N3.Checked = false;
      this.N4.Checked = false;
      this.N5.Checked = false;
      this.ImagenItemFound.Image = (Image) new Bitmap(Class18.smethod_30(Class18.smethod_31((object) "img\\items\\fondo\\clean.mmk")));
      this.TextLoad1.Text = "0%";
      this.TextLoad2.Text = "0%";
      Class21.smethod_2();
      this.CuentasDupe.Focus();
      return (object) true;
    }

    public object ActualizarDB(object X, object Y, object Z)
    {
      Class7.smethod_0();
      try
      {
        Class28.sqlConnection_1.Open();
        Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
        Class28.sqlCommand_1.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) ("DELETE FROM MuMakerFinderMaker WHERE AC='" + this.Cuenta1.Text + "' AND PJ='" + this.Personaje1.Text + "' AND CodeItems = '"), X), (object) "' AND Pos = '"), Z), (object) "'"));
        Class28.sqlCommand_1.ExecuteReader();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      Class7.smethod_5();
      try
      {
        Class28.sqlConnection_1.Open();
        Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
        Class28.sqlCommand_1.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "UPDATE MuMakerFinderMaker SET CodeItems = '", Y), (object) "' WHERE CodeItems = '"), X), (object) "'"));
        Class28.sqlCommand_1.ExecuteReader();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      Class7.smethod_5();
      return (object) true;
    }

    private void method_4(object sender, KeyPressEventArgs e)
    {
      if ((int) Class18.smethod_20(checked ((short) Strings.Asc(e.KeyChar))) != 0)
        return;
      e.Handled = true;
    }

    private void CuentasDupe_SelectedIndexChanged(object sender, EventArgs e)
    {
      try
      {
        this.PJDupe.SelectedIndex = this.CuentasDupe.SelectedIndex;
        this.CodeItems.SelectedIndex = this.CuentasDupe.SelectedIndex;
        this.Pos.SelectedIndex = this.CuentasDupe.SelectedIndex;
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        ProjectData.ClearProjectError();
      }
      this.MostrarInfoItemFound();
    }

    private void PJDupe_SelectedIndexChanged(object sender, EventArgs e)
    {
      try
      {
        this.CuentasDupe.SelectedIndex = this.PJDupe.SelectedIndex;
        this.CodeItems.SelectedIndex = this.CuentasDupe.SelectedIndex;
        this.Pos.SelectedIndex = this.CuentasDupe.SelectedIndex;
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        ProjectData.ClearProjectError();
      }
    }

    public object OcultarBotones()
    {
      Class29.bool_0 = false;
      this.BotonFullEXE.Enabled = false;
      this.BotonEXEANC.Enabled = false;
      this.BotonFull380.Enabled = false;
      this.BotonFullJoH.Enabled = false;
      this.BotonFullSK.Enabled = false;
      this.Invent.Enabled = false;
      this.Vault.Enabled = false;
      this.Extra.Enabled = false;
      this.Clean.Enabled = false;
      this.Seleccionado.Enabled = false;
      this.Todos.Enabled = false;
      this.BuscarCode.Enabled = false;
      this.BuscarSerial.Enabled = false;
      this.CuentasDupe.Enabled = false;
      this.PJDupe.Enabled = false;
      return (object) true;
    }

    public object MostrarBotones()
    {
      this.BotonFullEXE.Enabled = true;
      this.BotonEXEANC.Enabled = true;
      this.BotonFull380.Enabled = true;
      this.BotonFullJoH.Enabled = true;
      this.BotonFullSK.Enabled = true;
      this.Invent.Enabled = true;
      this.Vault.Enabled = true;
      this.Extra.Enabled = true;
      this.Clean.Enabled = true;
      this.Seleccionado.Enabled = true;
      this.Todos.Enabled = true;
      this.BuscarCode.Enabled = true;
      if (this.AllSerials.Checked)
        this.BuscarSerial.Enabled = false;
      else
        this.BuscarSerial.Enabled = true;
      Class29.bool_0 = true;
      this.CuentasDupe.Enabled = true;
      this.PJDupe.Enabled = true;
      return (object) true;
    }

    public object Full(object vAccount, object vPersonaje, object vVault, object vInvent, object vExtraW, object vNumExtraW, object vPos, object vItem, object vItems)
    {
      switch (Class29.int_0)
      {
        case 1:
          if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(vItem), 15, 2), "3F", false) == 0 | Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(vItem), 15, 2), "7F", false) == 0)
          {
            this.CuentasDupe.Items.Add(RuntimeHelpers.GetObjectValue(vAccount));
            this.PJDupe.Items.Add(RuntimeHelpers.GetObjectValue(vPersonaje));
            this.CodeItems.Items.Add(RuntimeHelpers.GetObjectValue(vItem));
            this.Pos.Items.Add(RuntimeHelpers.GetObjectValue(vPos));
            Class13.smethod_0(RuntimeHelpers.GetObjectValue(vAccount), RuntimeHelpers.GetObjectValue(vPersonaje), RuntimeHelpers.GetObjectValue(vVault), RuntimeHelpers.GetObjectValue(vInvent), RuntimeHelpers.GetObjectValue(vExtraW), RuntimeHelpers.GetObjectValue(vNumExtraW), RuntimeHelpers.GetObjectValue(vPos), RuntimeHelpers.GetObjectValue(vItem), (object) Strings.Mid(Conversions.ToString(vItem), 7, 8), (object) "1", RuntimeHelpers.GetObjectValue(Class13.smethod_5(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_3(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_4(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_6(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(vItems));
            break;
          }
          break;
        case 2:
          if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(vItem), 20, 1), "8", false) == 0)
          {
            this.CuentasDupe.Items.Add(RuntimeHelpers.GetObjectValue(vAccount));
            this.PJDupe.Items.Add(RuntimeHelpers.GetObjectValue(vPersonaje));
            this.CodeItems.Items.Add(RuntimeHelpers.GetObjectValue(vItem));
            this.Pos.Items.Add(RuntimeHelpers.GetObjectValue(vPos));
            Class13.smethod_0(RuntimeHelpers.GetObjectValue(vAccount), RuntimeHelpers.GetObjectValue(vPersonaje), RuntimeHelpers.GetObjectValue(vVault), RuntimeHelpers.GetObjectValue(vInvent), RuntimeHelpers.GetObjectValue(vExtraW), RuntimeHelpers.GetObjectValue(vNumExtraW), RuntimeHelpers.GetObjectValue(vPos), RuntimeHelpers.GetObjectValue(vItem), (object) Strings.Mid(Conversions.ToString(vItem), 7, 8), RuntimeHelpers.GetObjectValue(Class13.smethod_2(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_5(RuntimeHelpers.GetObjectValue(vItem))), (object) "1", RuntimeHelpers.GetObjectValue(Class13.smethod_4(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_6(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(vItems));
            break;
          }
          break;
        case 3:
          if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(vItem), 22, 1), "F", false) == 0)
          {
            this.CuentasDupe.Items.Add(RuntimeHelpers.GetObjectValue(vAccount));
            this.PJDupe.Items.Add(RuntimeHelpers.GetObjectValue(vPersonaje));
            this.CodeItems.Items.Add(RuntimeHelpers.GetObjectValue(vItem));
            this.Pos.Items.Add(RuntimeHelpers.GetObjectValue(vPos));
            Class13.smethod_0(RuntimeHelpers.GetObjectValue(vAccount), RuntimeHelpers.GetObjectValue(vPersonaje), RuntimeHelpers.GetObjectValue(vVault), RuntimeHelpers.GetObjectValue(vInvent), RuntimeHelpers.GetObjectValue(vExtraW), RuntimeHelpers.GetObjectValue(vNumExtraW), RuntimeHelpers.GetObjectValue(vPos), RuntimeHelpers.GetObjectValue(vItem), (object) Strings.Mid(Conversions.ToString(vItem), 7, 8), RuntimeHelpers.GetObjectValue(Class13.smethod_2(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_5(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_3(RuntimeHelpers.GetObjectValue(vItem))), (object) "1", RuntimeHelpers.GetObjectValue(Class13.smethod_6(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(vItems));
            break;
          }
          break;
        case 4:
          if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(vItem), 23, 2), "00", false) != 0 && Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(vItem), 25, 2), "00", false) != 0 && (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(vItem), 27, 2), "00", false) != 0 && Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(vItem), 29, 2), "00", false) != 0) && Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(vItem), 31, 2), "00", false) != 0)
          {
            this.CuentasDupe.Items.Add(RuntimeHelpers.GetObjectValue(vAccount));
            this.PJDupe.Items.Add(RuntimeHelpers.GetObjectValue(vPersonaje));
            this.CodeItems.Items.Add(RuntimeHelpers.GetObjectValue(vItem));
            this.Pos.Items.Add(RuntimeHelpers.GetObjectValue(vPos));
            Class13.smethod_0(RuntimeHelpers.GetObjectValue(vAccount), RuntimeHelpers.GetObjectValue(vPersonaje), RuntimeHelpers.GetObjectValue(vVault), RuntimeHelpers.GetObjectValue(vInvent), RuntimeHelpers.GetObjectValue(vExtraW), RuntimeHelpers.GetObjectValue(vNumExtraW), RuntimeHelpers.GetObjectValue(vPos), RuntimeHelpers.GetObjectValue(vItem), (object) Strings.Mid(Conversions.ToString(vItem), 7, 8), RuntimeHelpers.GetObjectValue(Class13.smethod_2(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_5(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_3(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_4(RuntimeHelpers.GetObjectValue(vItem))), (object) "1", RuntimeHelpers.GetObjectValue(vItems));
            break;
          }
          break;
        case 5:
          if (Conversions.ToBoolean(Microsoft.VisualBasic.CompilerServices.Operators.AndObject(Microsoft.VisualBasic.CompilerServices.Operators.CompareObjectEqual(Class15.smethod_5(RuntimeHelpers.GetObjectValue(vItem)), (object) "Excelent ", false), Microsoft.VisualBasic.CompilerServices.Operators.CompareObjectEqual(Class15.smethod_4(RuntimeHelpers.GetObjectValue(vItem)), (object) "Ancient ", false))))
          {
            this.CuentasDupe.Items.Add(RuntimeHelpers.GetObjectValue(vAccount));
            this.PJDupe.Items.Add(RuntimeHelpers.GetObjectValue(vPersonaje));
            this.CodeItems.Items.Add(RuntimeHelpers.GetObjectValue(vItem));
            this.Pos.Items.Add(RuntimeHelpers.GetObjectValue(vPos));
            Class13.smethod_0(RuntimeHelpers.GetObjectValue(vAccount), RuntimeHelpers.GetObjectValue(vPersonaje), RuntimeHelpers.GetObjectValue(vVault), RuntimeHelpers.GetObjectValue(vInvent), RuntimeHelpers.GetObjectValue(vExtraW), RuntimeHelpers.GetObjectValue(vNumExtraW), RuntimeHelpers.GetObjectValue(vPos), RuntimeHelpers.GetObjectValue(vItem), (object) Strings.Mid(Conversions.ToString(vItem), 7, 8), RuntimeHelpers.GetObjectValue(Class13.smethod_2(RuntimeHelpers.GetObjectValue(vItem))), (object) "1", RuntimeHelpers.GetObjectValue(Class13.smethod_3(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_4(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_6(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(vItems));
            break;
          }
          break;
        case 6:
          if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(vItem), 7, 8), this.SerialSearch.Text, false) == 0)
          {
            this.CuentasDupe.Items.Add(RuntimeHelpers.GetObjectValue(vAccount));
            this.PJDupe.Items.Add(RuntimeHelpers.GetObjectValue(vPersonaje));
            this.CodeItems.Items.Add(RuntimeHelpers.GetObjectValue(vItem));
            this.Pos.Items.Add(RuntimeHelpers.GetObjectValue(vPos));
            Class13.smethod_0(RuntimeHelpers.GetObjectValue(vAccount), RuntimeHelpers.GetObjectValue(vPersonaje), RuntimeHelpers.GetObjectValue(vVault), RuntimeHelpers.GetObjectValue(vInvent), RuntimeHelpers.GetObjectValue(vExtraW), RuntimeHelpers.GetObjectValue(vNumExtraW), RuntimeHelpers.GetObjectValue(vPos), RuntimeHelpers.GetObjectValue(vItem), (object) Strings.Mid(Conversions.ToString(vItem), 7, 8), RuntimeHelpers.GetObjectValue(Class13.smethod_2(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_5(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_3(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_4(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_6(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(vItems));
            break;
          }
          break;
        case 7:
          if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual((object) this.ItemCodeSearch.Text, vItem, false))
          {
            this.CuentasDupe.Items.Add(RuntimeHelpers.GetObjectValue(vAccount));
            this.PJDupe.Items.Add(RuntimeHelpers.GetObjectValue(vPersonaje));
            this.CodeItems.Items.Add(RuntimeHelpers.GetObjectValue(vItem));
            this.Pos.Items.Add(RuntimeHelpers.GetObjectValue(vPos));
            Class13.smethod_0(RuntimeHelpers.GetObjectValue(vAccount), RuntimeHelpers.GetObjectValue(vPersonaje), RuntimeHelpers.GetObjectValue(vVault), RuntimeHelpers.GetObjectValue(vInvent), RuntimeHelpers.GetObjectValue(vExtraW), RuntimeHelpers.GetObjectValue(vNumExtraW), RuntimeHelpers.GetObjectValue(vPos), RuntimeHelpers.GetObjectValue(vItem), (object) Strings.Mid(Conversions.ToString(vItem), 7, 8), RuntimeHelpers.GetObjectValue(Class13.smethod_2(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_5(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_3(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_4(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_6(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(vItems));
            break;
          }
          break;
        case 8:
          if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(vItem), 1, 6), Strings.Mid(this.ItemCodeSearch.Text, 1, 6), false) == 0 & Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(Conversions.ToString(vItem), 15, 18), Strings.Mid(this.ItemCodeSearch.Text, 15, 18), false) == 0)
          {
            this.CuentasDupe.Items.Add(RuntimeHelpers.GetObjectValue(vAccount));
            this.PJDupe.Items.Add(RuntimeHelpers.GetObjectValue(vPersonaje));
            this.CodeItems.Items.Add(RuntimeHelpers.GetObjectValue(vItem));
            this.Pos.Items.Add(RuntimeHelpers.GetObjectValue(vPos));
            Class13.smethod_0(RuntimeHelpers.GetObjectValue(vAccount), RuntimeHelpers.GetObjectValue(vPersonaje), RuntimeHelpers.GetObjectValue(vVault), RuntimeHelpers.GetObjectValue(vInvent), RuntimeHelpers.GetObjectValue(vExtraW), RuntimeHelpers.GetObjectValue(vNumExtraW), RuntimeHelpers.GetObjectValue(vPos), RuntimeHelpers.GetObjectValue(vItem), (object) Strings.Mid(Conversions.ToString(vItem), 7, 8), RuntimeHelpers.GetObjectValue(Class13.smethod_2(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_5(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_3(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_4(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(Class13.smethod_6(RuntimeHelpers.GetObjectValue(vItem))), RuntimeHelpers.GetObjectValue(vItems));
            break;
          }
          break;
      }
      return (object) true;
    }

    private void method_5()
    {
      this.OcultarBotones();
      this.Resetear();
      this.CargaTotal.Maximum = Class29.int_1;
      this.CargaParcial.Maximum = 120;
      try
      {
        Class7.smethod_0();
        Class28.sqlConnection_1.Open();
        Class7.smethod_1();
        Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
        Class28.sqlCommand_1.CommandText = "SELECT memb___id FROM MEMB_INFO ORDER BY memb___id ASC";
        Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
        int num1 = 0;
        while (Class28.sqlDataReader_1.Read())
        {
          try
          {
            this.CargaParcial.Maximum = 120;
            if (this.Vault.Checked)
            {
              try
              {
                Class28.sqlConnection_2.Open();
                Class28.sqlCommand_2.Connection = Class28.sqlConnection_2;
                Class28.sqlCommand_2.CommandText = "SELECT master.dbo.fn_varbintohexstr(CAST(Items AS Image)) FROM warehouse WHERE AccountID = '" + Class28.sqlDataReader_1[0].ToString() + "'";
                Class28.sqlDataReader_2 = Class28.sqlCommand_2.ExecuteReader();
                while (Class28.sqlDataReader_2.Read())
                {
                  if (Class29.bool_0)
                    return;
                  string str = Strings.Mid(Class28.sqlDataReader_2[0].ToString().ToUpper(), 3, Class28.sqlDataReader_2[0].ToString().Length);
                  int num2 = 0;
                  int num3 = 1;
label_10:
                  if (Class29.bool_0)
                    return;
                  string Left = Strings.Mid(str, checked (num3 + num2), 32);
                  checked { num2 += 31; }
                  if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF", false) != 0 & Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, "", false) != 0)
                    this.Full((object) Class28.sqlDataReader_1[0].ToString(), (object) "-", (object) "1", (object) "0", (object) "0", (object) "0", (object) num3, (object) Left, (object) str);
                  this.CargaParcial.Value = num3;
                  this.TextLoad1.Text = Conversions.ToString(Math.Round((double) this.CargaParcial.Value / (double) this.CargaParcial.Maximum * 100.0)) + "%";
                  checked { ++num3; }
                  if (num3 <= 120)
                    goto label_10;
                }
              }
              catch (Exception ex)
              {
                ProjectData.SetProjectError(ex);
                ProjectData.ClearProjectError();
              }
              Class28.sqlDataReader_2.Close();
              Class7.smethod_6();
            }
            this.CargaParcial.Maximum = 120;
            if (this.Extra.Checked)
            {
              try
              {
                Class28.sqlConnection_2.Open();
                Class28.sqlCommand_2.Connection = Class28.sqlConnection_2;
                Class28.sqlCommand_2.CommandText = "SELECT master.dbo.fn_varbintohexstr(CAST(Items AS Image)), Number FROM ExtWareHouse WHERE AccountID = '" + Class28.sqlDataReader_1[0].ToString() + "'";
                Class28.sqlDataReader_2 = Class28.sqlCommand_2.ExecuteReader();
                while (Class28.sqlDataReader_2.Read())
                {
                  if (Class29.bool_0)
                    return;
                  string str = Strings.Mid(Class28.sqlDataReader_2[0].ToString().ToUpper(), 3, Class28.sqlDataReader_2[0].ToString().Length);
                  int num2 = 0;
                  int num3 = 1;
label_21:
                  if (Class29.bool_0)
                    return;
                  string Left = Strings.Mid(str, checked (num3 + num2), 32);
                  checked { num2 += 31; }
                  if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF", false) != 0 & Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, "", false) != 0)
                    this.Full((object) Class28.sqlDataReader_1[0].ToString(), (object) "-", (object) "0", (object) "0", (object) "1", (object) Class28.sqlDataReader_2[1].ToString(), (object) num3, (object) Left, (object) str);
                  this.CargaParcial.Value = num3;
                  this.TextLoad1.Text = Conversions.ToString(Math.Round((double) this.CargaParcial.Value / (double) this.CargaParcial.Maximum * 100.0)) + "%";
                  checked { ++num3; }
                  if (num3 <= 120)
                    goto label_21;
                }
              }
              catch (Exception ex)
              {
                ProjectData.SetProjectError(ex);
                ProjectData.ClearProjectError();
              }
              Class28.sqlDataReader_2.Close();
              Class7.smethod_6();
            }
            this.CargaParcial.Maximum = 108;
            if (this.Invent.Checked)
            {
              try
              {
                Class28.sqlConnection_2.Open();
                Class28.sqlCommand_2.Connection = Class28.sqlConnection_2;
                Class28.sqlCommand_2.CommandText = "SELECT master.dbo.fn_varbintohexstr(CAST(Inventory AS Image)), Name FROM Character WHERE AccountID = '" + Class28.sqlDataReader_1[0].ToString() + "'";
                Class28.sqlDataReader_2 = Class28.sqlCommand_2.ExecuteReader();
                while (Class28.sqlDataReader_2.Read())
                {
                  if (Class29.bool_0)
                    return;
                  string str = Strings.Mid(Class28.sqlDataReader_2[0].ToString().ToUpper(), 3, Class28.sqlDataReader_2[0].ToString().Length);
                  int num2 = 0;
                  int num3 = 1;
label_34:
                  if (Class29.bool_0)
                    return;
                  string Left = Strings.Mid(str, checked (num3 + num2), 32);
                  checked { num2 += 31; }
                  if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF", false) != 0 & Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, "", false) != 0)
                    this.Full((object) Class28.sqlDataReader_1[0].ToString(), (object) Class28.sqlDataReader_2[1].ToString(), (object) "0", (object) "1", (object) "0", (object) "0", (object) num3, (object) Left, (object) str);
                  this.CargaParcial.Value = num3;
                  this.TextLoad1.Text = Conversions.ToString(Math.Round((double) this.CargaParcial.Value / (double) this.CargaParcial.Maximum * 100.0)) + "%";
                  checked { ++num3; }
                  if (num3 <= 108)
                    goto label_34;
                }
              }
              catch (Exception ex)
              {
                ProjectData.SetProjectError(ex);
                ProjectData.ClearProjectError();
              }
              Class28.sqlDataReader_2.Close();
              Class7.smethod_6();
            }
          }
          catch (Exception ex)
          {
            ProjectData.SetProjectError(ex);
            ProjectData.ClearProjectError();
          }
          checked { ++num1; }
          try
          {
            this.CargaTotal.Value = num1;
          }
          catch (Exception ex)
          {
            ProjectData.SetProjectError(ex);
            int num2 = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
            ProjectData.ClearProjectError();
          }
          this.TextLoad2.Text = Conversions.ToString(Math.Round((double) this.CargaTotal.Value / (double) this.CargaTotal.Maximum * 100.0)) + "%";
          Class7.smethod_6();
        }
        Class28.sqlDataReader_1.Close();
        this.Status.Text = "!! FINISH ALL OK !!";
        Class7.smethod_5();
        Class7.smethod_6();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        this.Status.Text = "FINISH W/ERRORS";
        Class7.smethod_5();
        Class7.smethod_6();
        ProjectData.ClearProjectError();
      }
      Class7.smethod_5();
      Class7.smethod_6();
      this.MostrarBotones();
      Class29.int_0 = 0;
    }

    private void StopSearch_Click(object sender, EventArgs e)
    {
      Class29.bool_0 = true;
      this.MostrarBotones();
      this.CuentasDupe.Focus();
    }

    private void method_6(object sender, EventArgs e)
    {
      this.Resetear();
    }

    private void method_7(object sender, EventArgs e)
    {
      this.CuentasDupe.Focus();
      string str = Conversions.ToString(this.CuentasDupe.Items.Count);
      if (Conversions.ToDouble(str) >= 1.0 & this.CuentasDupe.SelectedIndex != -1)
      {
        this.OcultarBotones();
        if (this.RadioInvent.Checked)
        {
          Class12.smethod_1();
          this.BorrarInvent(RuntimeHelpers.GetObjectValue(this.Pos.SelectedItem));
        }
        if (this.RadioVault.Checked)
        {
          Class12.smethod_1();
          this.BorrarVault(RuntimeHelpers.GetObjectValue(this.Pos.SelectedItem));
        }
        if (this.RadioExtra.Checked)
        {
          this.BorrarExtra(RuntimeHelpers.GetObjectValue(this.Pos.SelectedItem));
          Class12.smethod_1();
        }
        Class29.string_1 = Conversions.ToString(this.CuentasDupe.SelectedIndex);
        this.PJDupe.Items.RemoveAt(Conversions.ToInteger(Class29.string_1));
        this.Pos.Items.RemoveAt(Conversions.ToInteger(Class29.string_1));
        this.CodeItems.Items.RemoveAt(Conversions.ToInteger(Class29.string_1));
        this.CuentasDupe.Items.RemoveAt(Conversions.ToInteger(Class29.string_1));
        this.CuentasDupe.Focus();
        if (Conversions.ToDouble(Class29.string_1) > 1.0)
          this.CuentasDupe.SelectedIndex = checked ((int) Math.Round(unchecked (Conversions.ToDouble(Class29.string_1) - 1.0)));
        if (!((Conversions.ToDouble(Class29.string_1) == 0.0 | Conversions.ToDouble(Class29.string_1) == 1.0) & Conversions.ToDouble(str) > 1.0))
          return;
        this.CuentasDupe.SelectedIndex = 0;
      }
      else
        this.Resetear();
    }

    private void method_8(object sender, EventArgs e)
    {
      new Thread(new ThreadStart(this.method_0))
      {
        IsBackground = true
      }.Start();
    }

    private void FinderMaker_Closing(object sender, CancelEventArgs e)
    {
      Class18.smethod_47();
      Class21.smethod_2();
    }

    private void FinderMaker_Closed(object sender, EventArgs e)
    {
      Class18.smethod_47();
      Class21.smethod_2();
    }

    private void method_9(object sender, EventArgs e)
    {
      Class29.int_0 = 1;
      this.Status.Text = "!! SEARCHING !!";
      new Thread(new ThreadStart(this.method_5))
      {
        IsBackground = true,
        Priority = ThreadPriority.Highest
      }.Start();
    }

    private void method_10(object sender, EventArgs e)
    {
      Class29.int_0 = 2;
      this.Status.Text = "!! SEARCHING !!";
      new Thread(new ThreadStart(this.method_5))
      {
        IsBackground = true,
        Priority = ThreadPriority.Highest
      }.Start();
    }

    private void method_11(object sender, EventArgs e)
    {
      Class29.int_0 = 3;
      this.Status.Text = "!! SEARCHING !!";
      new Thread(new ThreadStart(this.method_5))
      {
        IsBackground = true,
        Priority = ThreadPriority.Highest
      }.Start();
    }

    private void method_12(object sender, EventArgs e)
    {
      Class29.int_0 = 4;
      this.Status.Text = "!! SEARCHING !!";
      new Thread(new ThreadStart(this.method_5))
      {
        IsBackground = true,
        Priority = ThreadPriority.Highest
      }.Start();
    }

    private void method_13(object sender, EventArgs e)
    {
      Class29.int_0 = 5;
      this.Status.Text = "!! SEARCHING !!";
      new Thread(new ThreadStart(this.method_5))
      {
        IsBackground = true,
        Priority = ThreadPriority.Highest
      }.Start();
    }

    private void method_14(object sender, EventArgs e)
    {
      Class29.int_0 = 6;
      this.Status.Text = "!! SEARCHING !!";
      new Thread(new ThreadStart(this.method_5))
      {
        IsBackground = true,
        Priority = ThreadPriority.Highest
      }.Start();
    }

    private void method_15(object sender, EventArgs e)
    {
      Class29.int_0 = Microsoft.VisualBasic.CompilerServices.Operators.CompareString(this.SerialSearch.Text, "XXXXXXXX", false) == 0 ? 8 : 7;
      this.Status.Text = "!! SEARCHING !!";
      new Thread(new ThreadStart(this.method_5))
      {
        IsBackground = true,
        Priority = ThreadPriority.Highest
      }.Start();
    }

    private void method_16(object sender, EventArgs e)
    {
      FinderMaker.DefInstance.WindowState = FormWindowState.Minimized;
    }

    private void method_17(object sender, EventArgs e)
    {
      this.Close();
    }

    private void method_18(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Minimizar.BackgroundImage = (Image) Class34.smethod_86();
    }

    private void method_19(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Minimizar.BackgroundImage = (Image) Class34.smethod_87();
    }

    private void method_20(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) Class34.smethod_39();
    }

    private void method_21(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) Class34.smethod_40();
    }

    private void method_22(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonFullEXE.BackgroundImage = (Image) Class34.smethod_12();
    }

    private void method_23(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonFullEXE.BackgroundImage = (Image) Class34.smethod_13();
    }

    private void method_24(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonFull380.BackgroundImage = (Image) Class34.smethod_12();
    }

    private void method_25(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonFull380.BackgroundImage = (Image) Class34.smethod_13();
    }

    private void method_26(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonFullJoH.BackgroundImage = (Image) Class34.smethod_12();
    }

    private void method_27(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonFullJoH.BackgroundImage = (Image) Class34.smethod_13();
    }

    private void method_28(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonFullSK.BackgroundImage = (Image) Class34.smethod_12();
    }

    private void method_29(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonFullSK.BackgroundImage = (Image) Class34.smethod_13();
    }

    private void method_30(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonEXEANC.BackgroundImage = (Image) Class34.smethod_12();
    }

    private void method_31(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BotonEXEANC.BackgroundImage = (Image) Class34.smethod_13();
    }

    private void method_32(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Clean.BackgroundImage = (Image) Class34.smethod_4();
    }

    private void method_33(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Clean.BackgroundImage = (Image) Class34.smethod_5();
    }

    private void method_34(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Seleccionado.BackgroundImage = (Image) Class34.smethod_117();
    }

    private void method_35(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Seleccionado.BackgroundImage = (Image) Class34.smethod_118();
    }

    private void method_36(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Todos.BackgroundImage = (Image) Class34.smethod_53();
    }

    private void method_37(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Todos.BackgroundImage = (Image) Class34.smethod_54();
    }

    private void method_38(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Invent.Image = (Image) Class34.smethod_71();
    }

    private void method_39(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Invent.Image = (Image) Class34.smethod_72();
    }

    private void method_40(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Vault.Image = (Image) Class34.smethod_112();
    }

    private void method_41(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Vault.Image = (Image) Class34.smethod_113();
    }

    private void method_42(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Extra.Image = (Image) Class34.smethod_73();
    }

    private void method_43(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Extra.Image = (Image) Class34.smethod_74();
    }

    private void method_44(object sender, MouseEventArgs e)
    {
    }

    private void method_45(object sender, MouseEventArgs e)
    {
    }

    private void method_46(object sender, MouseEventArgs e)
    {
    }

    private void method_47(object sender, MouseEventArgs e)
    {
    }
  }
}
