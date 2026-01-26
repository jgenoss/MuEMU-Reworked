// Decompiled with JetBrains decompiler
// Type: MuMaker.SQLMaker
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
  public class SQLMaker : Form
  {
    private static SQLMaker sqlmaker_0 = (SQLMaker) null;
    private IContainer icontainer_0;
    [AccessedThroughProperty("StatusBar")]
    private StatusBar _StatusBar;
    [AccessedThroughProperty("NombreProyecto")]
    private StatusBarPanel _NombreProyecto;
    [AccessedThroughProperty("Cuentas")]
    private StatusBarPanel _Cuentas;
    [AccessedThroughProperty("TextLoad")]
    private StatusBarPanel _TextLoad;
    [AccessedThroughProperty("ProgresBar")]
    private ProgressBar _ProgresBar;
    [AccessedThroughProperty("Tab1")]
    private TabPage _Tab1;
    [AccessedThroughProperty("CuentasOFF")]
    private GroupBox _CuentasOFF;
    [AccessedThroughProperty("InactiveAFF")]
    private TextBox _InactiveAFF;
    [AccessedThroughProperty("Label7")]
    private Label _Label7;
    [AccessedThroughProperty("Inactive")]
    private TextBox _Inactive;
    [AccessedThroughProperty("Label4")]
    private Label _Label4;
    [AccessedThroughProperty("Label2")]
    private Label _Label2;
    [AccessedThroughProperty("InacAccAply")]
    private Button _InacAccAply;
    [AccessedThroughProperty("GroupBox2")]
    private GroupBox _GroupBox2;
    [AccessedThroughProperty("BannedAFF")]
    private TextBox _BannedAFF;
    [AccessedThroughProperty("Label8")]
    private Label _Label8;
    [AccessedThroughProperty("NumPJ")]
    private TextBox _NumPJ;
    [AccessedThroughProperty("Label10")]
    private Label _Label10;
    [AccessedThroughProperty("Label3")]
    private Label _Label3;
    [AccessedThroughProperty("BanAccAply")]
    private Button _BanAccAply;
    [AccessedThroughProperty("CuentasVacias")]
    private GroupBox _CuentasVacias;
    [AccessedThroughProperty("EmpyAFF")]
    private TextBox _EmpyAFF;
    [AccessedThroughProperty("Label6")]
    private Label _Label6;
    [AccessedThroughProperty("Label1")]
    private Label _Label1;
    [AccessedThroughProperty("EmpAccAply")]
    private Button _EmpAccAply;
    [AccessedThroughProperty("Pestañas")]
    private TabControl tabControl_0;
    [AccessedThroughProperty("Reload")]
    private Button _Reload;

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

    internal virtual StatusBarPanel NombreProyecto
    {
      [DebuggerNonUserCode] get
      {
        return this._NombreProyecto;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._NombreProyecto = value;
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

    internal virtual StatusBarPanel TextLoad
    {
      [DebuggerNonUserCode] get
      {
        return this._TextLoad;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._TextLoad = value;
      }
    }

    internal virtual ProgressBar ProgresBar
    {
      [DebuggerNonUserCode] get
      {
        return this._ProgresBar;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._ProgresBar = value;
      }
    }

    internal virtual TabPage Tab1
    {
      [DebuggerNonUserCode] get
      {
        return this._Tab1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Tab1 = value;
      }
    }

    internal virtual GroupBox CuentasOFF
    {
      [DebuggerNonUserCode] get
      {
        return this._CuentasOFF;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._CuentasOFF = value;
      }
    }

    internal virtual TextBox InactiveAFF
    {
      [DebuggerNonUserCode] get
      {
        return this._InactiveAFF;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._InactiveAFF = value;
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

    internal virtual TextBox Inactive
    {
      [DebuggerNonUserCode] get
      {
        return this._Inactive;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler1 = new EventHandler(this.method_7);
        EventHandler eventHandler2 = new EventHandler(this.method_5);
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.method_3);
        if (this._Inactive != null)
        {
          this._Inactive.TextChanged -= eventHandler1;
          this._Inactive.LostFocus -= eventHandler2;
          this._Inactive.KeyPress -= pressEventHandler;
        }
        this._Inactive = value;
        if (this._Inactive == null)
          return;
        this._Inactive.TextChanged += eventHandler1;
        this._Inactive.LostFocus += eventHandler2;
        this._Inactive.KeyPress += pressEventHandler;
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

    internal virtual Button InacAccAply
    {
      [DebuggerNonUserCode] get
      {
        return this._InacAccAply;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.InacAccAply_Click);
        if (this._InacAccAply != null)
          this._InacAccAply.Click -= eventHandler;
        this._InacAccAply = value;
        if (this._InacAccAply == null)
          return;
        this._InacAccAply.Click += eventHandler;
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

    internal virtual TextBox BannedAFF
    {
      [DebuggerNonUserCode] get
      {
        return this._BannedAFF;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._BannedAFF = value;
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

    internal virtual TextBox NumPJ
    {
      [DebuggerNonUserCode] get
      {
        return this._NumPJ;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler1 = new EventHandler(this.method_8);
        EventHandler eventHandler2 = new EventHandler(this.method_6);
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.method_4);
        if (this._NumPJ != null)
        {
          this._NumPJ.TextChanged -= eventHandler1;
          this._NumPJ.LostFocus -= eventHandler2;
          this._NumPJ.KeyPress -= pressEventHandler;
        }
        this._NumPJ = value;
        if (this._NumPJ == null)
          return;
        this._NumPJ.TextChanged += eventHandler1;
        this._NumPJ.LostFocus += eventHandler2;
        this._NumPJ.KeyPress += pressEventHandler;
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

    internal virtual Button BanAccAply
    {
      [DebuggerNonUserCode] get
      {
        return this._BanAccAply;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.BanAccAply_Click);
        if (this._BanAccAply != null)
          this._BanAccAply.Click -= eventHandler;
        this._BanAccAply = value;
        if (this._BanAccAply == null)
          return;
        this._BanAccAply.Click += eventHandler;
      }
    }

    internal virtual GroupBox CuentasVacias
    {
      [DebuggerNonUserCode] get
      {
        return this._CuentasVacias;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._CuentasVacias = value;
      }
    }

    internal virtual TextBox EmpyAFF
    {
      [DebuggerNonUserCode] get
      {
        return this._EmpyAFF;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._EmpyAFF = value;
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

    internal virtual Button EmpAccAply
    {
      [DebuggerNonUserCode] get
      {
        return this._EmpAccAply;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.EmpAccAply_Click);
        if (this._EmpAccAply != null)
          this._EmpAccAply.Click -= eventHandler;
        this._EmpAccAply = value;
        if (this._EmpAccAply == null)
          return;
        this._EmpAccAply.Click += eventHandler;
      }
    }

    internal virtual TabControl TabControl_0
    {
      [DebuggerNonUserCode] get
      {
        return this.tabControl_0;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this.tabControl_0 = value;
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
        EventHandler eventHandler = new EventHandler(this.Reload_Click);
        if (this._Reload != null)
          this._Reload.Click -= eventHandler;
        this._Reload = value;
        if (this._Reload == null)
          return;
        this._Reload.Click += eventHandler;
      }
    }

    public static SQLMaker DefInstance
    {
      get
      {
        if (SQLMaker.sqlmaker_0 != null && !SQLMaker.sqlmaker_0.IsDisposed)
          SQLMaker.sqlmaker_0.BringToFront();
        else
          SQLMaker.sqlmaker_0 = new SQLMaker();
        return SQLMaker.sqlmaker_0;
      }
      set
      {
        SQLMaker.sqlmaker_0 = value;
      }
    }

    [DebuggerNonUserCode]
    public SQLMaker()
    {
      this.Load += new EventHandler(this.SQLMaker_Load);
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
      ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof (SQLMaker));
      this.StatusBar = new StatusBar();
      this.NombreProyecto = new StatusBarPanel();
      this.Cuentas = new StatusBarPanel();
      this.TextLoad = new StatusBarPanel();
      this.ProgresBar = new ProgressBar();
      this.Tab1 = new TabPage();
      this.Reload = new Button();
      this.CuentasOFF = new GroupBox();
      this.InactiveAFF = new TextBox();
      this.Label7 = new Label();
      this.Inactive = new TextBox();
      this.Label4 = new Label();
      this.Label2 = new Label();
      this.InacAccAply = new Button();
      this.GroupBox2 = new GroupBox();
      this.BannedAFF = new TextBox();
      this.Label8 = new Label();
      this.NumPJ = new TextBox();
      this.Label10 = new Label();
      this.Label3 = new Label();
      this.BanAccAply = new Button();
      this.CuentasVacias = new GroupBox();
      this.EmpyAFF = new TextBox();
      this.Label6 = new Label();
      this.Label1 = new Label();
      this.EmpAccAply = new Button();
      this.TabControl_0 = new TabControl();
      this.NombreProyecto.BeginInit();
      this.Cuentas.BeginInit();
      this.TextLoad.BeginInit();
      this.Tab1.SuspendLayout();
      this.CuentasOFF.SuspendLayout();
      this.GroupBox2.SuspendLayout();
      this.CuentasVacias.SuspendLayout();
      this.TabControl_0.SuspendLayout();
      this.SuspendLayout();
      this.StatusBar.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.StatusBar.ImeMode = ImeMode.NoControl;
      StatusBar statusBar1 = this.StatusBar;
      Point point1 = new Point(0, 245);
      Point point2 = point1;
      statusBar1.Location = point2;
      this.StatusBar.Name = "StatusBar";
      this.StatusBar.Panels.AddRange(new StatusBarPanel[3]
      {
        this.NombreProyecto,
        this.Cuentas,
        this.TextLoad
      });
      this.StatusBar.ShowPanels = true;
      StatusBar statusBar2 = this.StatusBar;
      Size size1 = new Size(630, 16);
      Size size2 = size1;
      statusBar2.Size = size2;
      this.StatusBar.TabIndex = 225;
      this.NombreProyecto.Icon = (Icon) componentResourceManager.GetObject("NombreProyecto.Icon");
      this.NombreProyecto.Name = "NombreProyecto";
      this.NombreProyecto.Text = "SQLMaker";
      this.NombreProyecto.Width = 110;
      this.Cuentas.Alignment = HorizontalAlignment.Right;
      this.Cuentas.Name = "Cuentas";
      this.Cuentas.Width = 450;
      this.TextLoad.Alignment = HorizontalAlignment.Center;
      this.TextLoad.Name = "TextLoad";
      this.TextLoad.Text = "100%";
      this.TextLoad.Width = 80;
      this.ProgresBar.BackColor = SystemColors.Control;
      ProgressBar progresBar1 = this.ProgresBar;
      point1 = new Point(0, 234);
      Point point3 = point1;
      progresBar1.Location = point3;
      this.ProgresBar.Name = "ProgresBar";
      ProgressBar progresBar2 = this.ProgresBar;
      size1 = new Size(630, 12);
      Size size3 = size1;
      progresBar2.Size = size3;
      this.ProgresBar.TabIndex = 226;
      this.Tab1.Controls.Add((Control) this.Reload);
      this.Tab1.Controls.Add((Control) this.CuentasOFF);
      this.Tab1.Controls.Add((Control) this.GroupBox2);
      this.Tab1.Controls.Add((Control) this.CuentasVacias);
      this.Tab1.ForeColor = Color.Black;
      TabPage tab1_1 = this.Tab1;
      point1 = new Point(4, 22);
      Point point4 = point1;
      tab1_1.Location = point4;
      this.Tab1.Name = "Tab1";
      this.Tab1.Padding = new Padding(3);
      TabPage tab1_2 = this.Tab1;
      size1 = new Size(625, 212);
      Size size4 = size1;
      tab1_2.Size = size4;
      this.Tab1.TabIndex = 0;
      this.Tab1.Text = "Maintenance";
      this.Tab1.UseVisualStyleBackColor = true;
      this.Reload.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Reload.BackgroundImage = (Image) Class34.smethod_100();
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
      point1 = new Point(575, 177);
      Point point5 = point1;
      reload1.Location = point5;
      this.Reload.Name = "Reload";
      Button reload2 = this.Reload;
      size1 = new Size(41, 30);
      Size size5 = size1;
      reload2.Size = size5;
      this.Reload.TabIndex = 484;
      this.Reload.TabStop = false;
      this.Reload.UseVisualStyleBackColor = false;
      this.CuentasOFF.Controls.Add((Control) this.InactiveAFF);
      this.CuentasOFF.Controls.Add((Control) this.Label7);
      this.CuentasOFF.Controls.Add((Control) this.Inactive);
      this.CuentasOFF.Controls.Add((Control) this.Label4);
      this.CuentasOFF.Controls.Add((Control) this.Label2);
      this.CuentasOFF.Controls.Add((Control) this.InacAccAply);
      this.CuentasOFF.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      GroupBox cuentasOff1 = this.CuentasOFF;
      point1 = new Point(6, 59);
      Point point6 = point1;
      cuentasOff1.Location = point6;
      this.CuentasOFF.Name = "CuentasOFF";
      GroupBox cuentasOff2 = this.CuentasOFF;
      size1 = new Size(613, 56);
      Size size6 = size1;
      cuentasOff2.Size = size6;
      this.CuentasOFF.TabIndex = 235;
      this.CuentasOFF.TabStop = false;
      this.CuentasOFF.Text = "Inactive Account";
      TextBox inactiveAff1 = this.InactiveAFF;
      point1 = new Point(326, 32);
      Point point7 = point1;
      inactiveAff1.Location = point7;
      this.InactiveAFF.Name = "InactiveAFF";
      this.InactiveAFF.ReadOnly = true;
      TextBox inactiveAff2 = this.InactiveAFF;
      size1 = new Size(62, 20);
      Size size7 = size1;
      inactiveAff2.Size = size7;
      this.InactiveAFF.TabIndex = 238;
      this.InactiveAFF.Text = "0";
      this.InactiveAFF.TextAlign = HorizontalAlignment.Center;
      Label label7_1 = this.Label7;
      point1 = new Point(326, 8);
      Point point8 = point1;
      label7_1.Location = point8;
      this.Label7.Name = "Label7";
      Label label7_2 = this.Label7;
      size1 = new Size(62, 26);
      Size size8 = size1;
      label7_2.Size = size8;
      this.Label7.TabIndex = 239;
      this.Label7.Text = "Affect Account";
      this.Label7.TextAlign = ContentAlignment.MiddleCenter;
      TextBox inactive1 = this.Inactive;
      point1 = new Point(401, 32);
      Point point9 = point1;
      inactive1.Location = point9;
      this.Inactive.MaxLength = 3;
      this.Inactive.Name = "Inactive";
      TextBox inactive2 = this.Inactive;
      size1 = new Size(30, 20);
      Size size9 = size1;
      inactive2.Size = size9;
      this.Inactive.TabIndex = 235;
      this.Inactive.Text = "90";
      this.Inactive.TextAlign = HorizontalAlignment.Center;
      this.Label4.AutoSize = true;
      Label label4_1 = this.Label4;
      point1 = new Point(429, 35);
      Point point10 = point1;
      label4_1.Location = point10;
      this.Label4.Name = "Label4";
      Label label4_2 = this.Label4;
      size1 = new Size(85, 13);
      Size size10 = size1;
      label4_2.Size = size10;
      this.Label4.TabIndex = 236;
      this.Label4.Text = "Days Inactive";
      Label label2_1 = this.Label2;
      point1 = new Point(5, 13);
      Point point11 = point1;
      label2_1.Location = point11;
      this.Label2.Name = "Label2";
      Label label2_2 = this.Label2;
      size1 = new Size(313, 40);
      Size size11 = size1;
      label2_2.Size = size11;
      this.Label2.TabIndex = 234;
      this.Label2.Text = "Borra Cuentas Inactivas durante los dias indicados!!\r\nWill delete accounts within the certain amount of days it was innactive for.";
      this.InacAccAply.BackColor = Color.Transparent;
      this.InacAccAply.BackgroundImageLayout = ImageLayout.Center;
      this.InacAccAply.Cursor = Cursors.Hand;
      this.InacAccAply.FlatAppearance.BorderSize = 0;
      this.InacAccAply.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.InacAccAply.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.InacAccAply.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.InacAccAply.FlatStyle = FlatStyle.System;
      this.InacAccAply.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.InacAccAply.ForeColor = Color.Transparent;
      Button inacAccAply1 = this.InacAccAply;
      point1 = new Point(523, 25);
      Point point12 = point1;
      inacAccAply1.Location = point12;
      this.InacAccAply.Name = "InacAccAply";
      Button inacAccAply2 = this.InacAccAply;
      size1 = new Size(86, 28);
      Size size12 = size1;
      inacAccAply2.Size = size12;
      this.InacAccAply.TabIndex = 233;
      this.InacAccAply.TabStop = false;
      this.InacAccAply.Text = "Aplicar";
      this.InacAccAply.UseVisualStyleBackColor = false;
      this.GroupBox2.Controls.Add((Control) this.BannedAFF);
      this.GroupBox2.Controls.Add((Control) this.Label8);
      this.GroupBox2.Controls.Add((Control) this.NumPJ);
      this.GroupBox2.Controls.Add((Control) this.Label10);
      this.GroupBox2.Controls.Add((Control) this.Label3);
      this.GroupBox2.Controls.Add((Control) this.BanAccAply);
      this.GroupBox2.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      GroupBox groupBox2_1 = this.GroupBox2;
      point1 = new Point(6, 116);
      Point point13 = point1;
      groupBox2_1.Location = point13;
      this.GroupBox2.Name = "GroupBox2";
      GroupBox groupBox2_2 = this.GroupBox2;
      size1 = new Size(613, 56);
      Size size13 = size1;
      groupBox2_2.Size = size13;
      this.GroupBox2.TabIndex = 235;
      this.GroupBox2.TabStop = false;
      this.GroupBox2.Text = "Banned Account";
      TextBox bannedAff1 = this.BannedAFF;
      point1 = new Point(326, 32);
      Point point14 = point1;
      bannedAff1.Location = point14;
      this.BannedAFF.Name = "BannedAFF";
      this.BannedAFF.ReadOnly = true;
      TextBox bannedAff2 = this.BannedAFF;
      size1 = new Size(62, 20);
      Size size14 = size1;
      bannedAff2.Size = size14;
      this.BannedAFF.TabIndex = 243;
      this.BannedAFF.Text = "0";
      this.BannedAFF.TextAlign = HorizontalAlignment.Center;
      Label label8_1 = this.Label8;
      point1 = new Point(326, 8);
      Point point15 = point1;
      label8_1.Location = point15;
      this.Label8.Name = "Label8";
      Label label8_2 = this.Label8;
      size1 = new Size(62, 26);
      Size size15 = size1;
      label8_2.Size = size15;
      this.Label8.TabIndex = 244;
      this.Label8.Text = "Affect Account";
      this.Label8.TextAlign = ContentAlignment.MiddleCenter;
      TextBox numPj1 = this.NumPJ;
      point1 = new Point(401, 32);
      Point point16 = point1;
      numPj1.Location = point16;
      this.NumPJ.MaxLength = 1;
      this.NumPJ.Name = "NumPJ";
      TextBox numPj2 = this.NumPJ;
      size1 = new Size(30, 20);
      Size size16 = size1;
      numPj2.Size = size16;
      this.NumPJ.TabIndex = 241;
      this.NumPJ.Text = "1";
      this.NumPJ.TextAlign = HorizontalAlignment.Center;
      this.Label10.AutoSize = true;
      Label label10_1 = this.Label10;
      point1 = new Point(433, 35);
      Point point17 = point1;
      label10_1.Location = point17;
      this.Label10.Name = "Label10";
      Label label10_2 = this.Label10;
      size1 = new Size(68, 13);
      Size size17 = size1;
      label10_2.Size = size17;
      this.Label10.TabIndex = 242;
      this.Label10.Text = "Characters";
      Label label3_1 = this.Label3;
      point1 = new Point(5, 13);
      Point point18 = point1;
      label3_1.Location = point18;
      this.Label3.Name = "Label3";
      Label label3_2 = this.Label3;
      size1 = new Size(313, 40);
      Size size18 = size1;
      label3_2.Size = size18;
      this.Label3.TabIndex = 234;
      this.Label3.Text = "Borra las Cuentas que tengan PJ Baneados!!\r\nWill delete all banned accounts!!";
      this.BanAccAply.BackColor = Color.Transparent;
      this.BanAccAply.BackgroundImageLayout = ImageLayout.Center;
      this.BanAccAply.Cursor = Cursors.Hand;
      this.BanAccAply.FlatAppearance.BorderSize = 0;
      this.BanAccAply.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BanAccAply.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BanAccAply.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BanAccAply.FlatStyle = FlatStyle.System;
      this.BanAccAply.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BanAccAply.ForeColor = Color.Transparent;
      Button banAccAply1 = this.BanAccAply;
      point1 = new Point(523, 25);
      Point point19 = point1;
      banAccAply1.Location = point19;
      this.BanAccAply.Name = "BanAccAply";
      Button banAccAply2 = this.BanAccAply;
      size1 = new Size(86, 28);
      Size size19 = size1;
      banAccAply2.Size = size19;
      this.BanAccAply.TabIndex = 233;
      this.BanAccAply.TabStop = false;
      this.BanAccAply.Text = "Aplicar";
      this.BanAccAply.UseVisualStyleBackColor = false;
      this.CuentasVacias.Controls.Add((Control) this.EmpyAFF);
      this.CuentasVacias.Controls.Add((Control) this.Label6);
      this.CuentasVacias.Controls.Add((Control) this.Label1);
      this.CuentasVacias.Controls.Add((Control) this.EmpAccAply);
      this.CuentasVacias.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      GroupBox cuentasVacias1 = this.CuentasVacias;
      point1 = new Point(6, 2);
      Point point20 = point1;
      cuentasVacias1.Location = point20;
      this.CuentasVacias.Name = "CuentasVacias";
      GroupBox cuentasVacias2 = this.CuentasVacias;
      size1 = new Size(613, 56);
      Size size20 = size1;
      cuentasVacias2.Size = size20;
      this.CuentasVacias.TabIndex = 234;
      this.CuentasVacias.TabStop = false;
      this.CuentasVacias.Text = "Empy Account";
      TextBox empyAff1 = this.EmpyAFF;
      point1 = new Point(326, 32);
      Point point21 = point1;
      empyAff1.Location = point21;
      this.EmpyAFF.Name = "EmpyAFF";
      this.EmpyAFF.ReadOnly = true;
      TextBox empyAff2 = this.EmpyAFF;
      size1 = new Size(62, 20);
      Size size21 = size1;
      empyAff2.Size = size21;
      this.EmpyAFF.TabIndex = 236;
      this.EmpyAFF.Text = "0";
      this.EmpyAFF.TextAlign = HorizontalAlignment.Center;
      Label label6_1 = this.Label6;
      point1 = new Point(326, 8);
      Point point22 = point1;
      label6_1.Location = point22;
      this.Label6.Name = "Label6";
      Label label6_2 = this.Label6;
      size1 = new Size(62, 26);
      Size size22 = size1;
      label6_2.Size = size22;
      this.Label6.TabIndex = 237;
      this.Label6.Text = "Affect Account";
      this.Label6.TextAlign = ContentAlignment.MiddleCenter;
      Label label1_1 = this.Label1;
      point1 = new Point(5, 13);
      Point point23 = point1;
      label1_1.Location = point23;
      this.Label1.Name = "Label1";
      Label label1_2 = this.Label1;
      size1 = new Size(313, 40);
      Size size23 = size1;
      label1_2.Size = size23;
      this.Label1.TabIndex = 234;
      this.Label1.Text = "Borra las Cuentas que esten Vacias!!\r\nWill delete all accounts that are empty!!";
      this.EmpAccAply.BackColor = Color.Transparent;
      this.EmpAccAply.BackgroundImageLayout = ImageLayout.Center;
      this.EmpAccAply.Cursor = Cursors.Hand;
      this.EmpAccAply.FlatAppearance.BorderSize = 0;
      this.EmpAccAply.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.EmpAccAply.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.EmpAccAply.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.EmpAccAply.FlatStyle = FlatStyle.System;
      this.EmpAccAply.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.EmpAccAply.ForeColor = Color.Transparent;
      Button empAccAply1 = this.EmpAccAply;
      point1 = new Point(523, 25);
      Point point24 = point1;
      empAccAply1.Location = point24;
      this.EmpAccAply.Name = "EmpAccAply";
      Button empAccAply2 = this.EmpAccAply;
      size1 = new Size(86, 28);
      Size size24 = size1;
      empAccAply2.Size = size24;
      this.EmpAccAply.TabIndex = 233;
      this.EmpAccAply.TabStop = false;
      this.EmpAccAply.Text = "Aplicar";
      this.EmpAccAply.UseVisualStyleBackColor = false;
      this.TabControl_0.Controls.Add((Control) this.Tab1);
      TabControl tabControl0_1 = this.TabControl_0;
      point1 = new Point(-1, 0);
      Point point25 = point1;
      tabControl0_1.Location = point25;
      this.TabControl_0.Name = "Pestañas";
      this.TabControl_0.SelectedIndex = 0;
      TabControl tabControl0_2 = this.TabControl_0;
      size1 = new Size(633, 238);
      Size size25 = size1;
      tabControl0_2.Size = size25;
      this.TabControl_0.TabIndex = 0;
      this.AutoScaleDimensions = new SizeF(6f, 13f);
      this.AutoScaleMode = AutoScaleMode.Font;
      this.BackColor = Color.Black;
      size1 = new Size(630, 261);
      this.ClientSize = size1;
      this.Controls.Add((Control) this.ProgresBar);
      this.Controls.Add((Control) this.StatusBar);
      this.Controls.Add((Control) this.TabControl_0);
      this.Icon = (Icon) componentResourceManager.GetObject("$this.Icon");
      this.MaximizeBox = false;
      size1 = new Size(638, 288);
      this.MaximumSize = size1;
      size1 = new Size(638, 288);
      this.MinimumSize = size1;
      this.Name = "SQLMaker";
      this.StartPosition = FormStartPosition.CenterScreen;
      this.Text = "SQLMaker - BETA - TEST - SUGERENCES";
      this.NombreProyecto.EndInit();
      this.Cuentas.EndInit();
      this.TextLoad.EndInit();
      this.Tab1.ResumeLayout(false);
      this.CuentasOFF.ResumeLayout(false);
      this.CuentasOFF.PerformLayout();
      this.GroupBox2.ResumeLayout(false);
      this.GroupBox2.PerformLayout();
      this.CuentasVacias.ResumeLayout(false);
      this.CuentasVacias.PerformLayout();
      this.TabControl_0.ResumeLayout(false);
      this.ResumeLayout(false);
    }

    public object EmpyAccount()
    {
      Class7.smethod_0();
      Class7.smethod_1();
      string str = Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "ExtWareHouse", "ExtWareHouse");
      try
      {
        Class28.sqlConnection_2.Open();
        Class28.sqlCommand_2 = new SqlCommand();
        Class28.sqlCommand_2.Connection = Class28.sqlConnection_2;
        Class28.sqlCommand_2.CommandText = "SELECT Id FROM AccountCharacter WHERE GameID1 IS NULL AND GameID2 IS NULL AND GameID3 IS NULL AND GameID4 IS NULL AND GameID5 IS NULL";
        Class28.sqlDataReader_2 = Class28.sqlCommand_2.ExecuteReader();
        int num = 0;
        SQLMaker.DefInstance.ProgresBar.Maximum = checked ((int) Math.Round(unchecked (Conversions.ToDouble(this.EmpyAFF.Text) + 1.0)));
        while (Class28.sqlDataReader_2.Read())
        {
          Class28.sqlCommand_1 = new SqlCommand();
          try
          {
            Class28.sqlConnection_1.Open();
            Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
            Class28.sqlCommand_1.CommandText = "DELETE FROM MEMB_STAT WHERE memb___id='" + Class28.sqlDataReader_2[0].ToString() + "'";
            Class28.sqlCommand_1.ExecuteReader();
          }
          catch (Exception ex)
          {
            ProjectData.SetProjectError(ex);
            ProjectData.ClearProjectError();
          }
          if (Class28.sqlConnection_1.State == ConnectionState.Open)
            Class28.sqlConnection_1.Close();
          try
          {
            Class28.sqlConnection_1.Open();
            Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
            Class28.sqlCommand_1.CommandText = "DELETE FROM MEMB_INFO WHERE memb___id='" + Class28.sqlDataReader_2[0].ToString() + "'";
            Class28.sqlCommand_1.ExecuteReader();
          }
          catch (Exception ex)
          {
            ProjectData.SetProjectError(ex);
            ProjectData.ClearProjectError();
          }
          if (Class28.sqlConnection_1.State == ConnectionState.Open)
            Class28.sqlConnection_1.Close();
          try
          {
            Class28.sqlConnection_1.Open();
            Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
            Class28.sqlCommand_1.CommandText = "DELETE FROM AccountCharacter WHERE Id='" + Class28.sqlDataReader_2[0].ToString() + "'";
            Class28.sqlCommand_1.ExecuteReader();
          }
          catch (Exception ex)
          {
            ProjectData.SetProjectError(ex);
            ProjectData.ClearProjectError();
          }
          if (Class28.sqlConnection_1.State == ConnectionState.Open)
            Class28.sqlConnection_1.Close();
          try
          {
            Class28.sqlConnection_1.Open();
            Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
            Class28.sqlCommand_1.CommandText = "DELETE FROM Character WHERE AccountID='" + Class28.sqlDataReader_2[0].ToString() + "'";
            Class28.sqlCommand_1.ExecuteReader();
          }
          catch (Exception ex)
          {
            ProjectData.SetProjectError(ex);
            ProjectData.ClearProjectError();
          }
          if (Class28.sqlConnection_1.State == ConnectionState.Open)
            Class28.sqlConnection_1.Close();
          try
          {
            Class28.sqlConnection_1.Open();
            Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
            Class28.sqlCommand_1.CommandText = "DELETE FROM warehouse WHERE AccountID='" + Class28.sqlDataReader_2[0].ToString() + "'";
            Class28.sqlCommand_1.ExecuteReader();
          }
          catch (Exception ex)
          {
            ProjectData.SetProjectError(ex);
            ProjectData.ClearProjectError();
          }
          if (Class28.sqlConnection_1.State == ConnectionState.Open)
            Class28.sqlConnection_1.Close();
          try
          {
            Class28.sqlConnection_1.Open();
            Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
            Class28.sqlCommand_1.CommandText = "DELETE FROM " + str + " WHERE AccountID='" + Class28.sqlDataReader_2[0].ToString() + "'";
            Class28.sqlCommand_1.ExecuteReader();
          }
          catch (Exception ex)
          {
            ProjectData.SetProjectError(ex);
            ProjectData.ClearProjectError();
          }
          if (Class28.sqlConnection_1.State == ConnectionState.Open)
            Class28.sqlConnection_1.Close();
          try
          {
            SQLMaker.DefInstance.ProgresBar.Value = num;
          }
          catch (Exception ex)
          {
            ProjectData.SetProjectError(ex);
            SQLMaker.DefInstance.ProgresBar.Value = checked ((int) Math.Round(unchecked (Conversions.ToDouble(this.EmpyAFF.Text) + 1.0)));
            this.TextLoad.Text = Conversions.ToString(Math.Round((double) this.ProgresBar.Value / (double) this.ProgresBar.Maximum * 100.0)) + "%";
            ProjectData.ClearProjectError();
          }
          checked { ++num; }
        }
        Class28.sqlDataReader_2.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      SQLMaker.DefInstance.ProgresBar.Value = checked ((int) Math.Round(unchecked (Conversions.ToDouble(this.EmpyAFF.Text) + 1.0)));
      this.TextLoad.Text = "100%";
      if (Class28.sqlConnection_1.State == ConnectionState.Open)
        Class28.sqlConnection_1.Close();
      if (Class28.sqlConnection_2.State == ConnectionState.Open)
        Class28.sqlConnection_2.Close();
      return (object) true;
    }

    public object InactiveAccount()
    {
      Class7.smethod_0();
      Class7.smethod_1();
      string str = Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "ExtWareHouse", "ExtWareHouse");
      try
      {
        Class28.sqlConnection_2.Open();
        Class28.sqlCommand_2 = new SqlCommand();
        Class28.sqlCommand_2.Connection = Class28.sqlConnection_2;
        Class28.sqlCommand_2.CommandText = "SELECT memb___id, DisConnectTM FROM MEMB_STAT";
        Class28.sqlDataReader_2 = Class28.sqlCommand_2.ExecuteReader();
        int num = 0;
        SQLMaker.DefInstance.ProgresBar.Maximum = checked ((int) Math.Round(unchecked (Conversions.ToDouble(this.InactiveAFF.Text) + 1.0)));
        while (Class28.sqlDataReader_2.Read())
        {
          object Left = (object) Decimal.Subtract(Conversions.ToDecimal(Strings.Mid(Conversions.ToString(DateAndTime.Now), 1, 2)), Conversions.ToDecimal(Strings.Mid(Class28.sqlDataReader_2[1].ToString(), 1, 2)));
          object Right1 = (object) Decimal.Multiply(Decimal.Subtract(Conversions.ToDecimal(Strings.Mid(Conversions.ToString(DateAndTime.Now), 4, 2)), Conversions.ToDecimal(Strings.Mid(Class28.sqlDataReader_2[1].ToString(), 4, 2))), new Decimal(30L));
          object Right2 = (object) Decimal.Multiply(Decimal.Subtract(Conversions.ToDecimal(Strings.Mid(Conversions.ToString(DateAndTime.Now), 7, 4)), Conversions.ToDecimal(Strings.Mid(Class28.sqlDataReader_2[1].ToString(), 7, 4))), new Decimal(365L));
          if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectLess(Left, (object) 0, false))
            Left = Microsoft.VisualBasic.CompilerServices.Operators.MultiplyObject(Left, (object) -1);
          if (Decimal.Compare(new Decimal(Conversions.ToInteger(Microsoft.VisualBasic.CompilerServices.Operators.AddObject(Microsoft.VisualBasic.CompilerServices.Operators.AddObject(Left, Right1), Right2))), Conversions.ToDecimal(this.Inactive.Text)) > 0)
          {
            Class28.sqlCommand_1 = new SqlCommand();
            try
            {
              Class28.sqlConnection_1.Open();
              Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
              Class28.sqlCommand_1.CommandText = "DELETE FROM MEMB_STAT WHERE memb___id='" + Class28.sqlDataReader_2[0].ToString() + "'";
              Class28.sqlCommand_1.ExecuteReader();
            }
            catch (Exception ex)
            {
              ProjectData.SetProjectError(ex);
              ProjectData.ClearProjectError();
            }
            if (Class28.sqlConnection_1.State == ConnectionState.Open)
              Class28.sqlConnection_1.Close();
            try
            {
              Class28.sqlConnection_1.Open();
              Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
              Class28.sqlCommand_1.CommandText = "DELETE FROM MEMB_INFO WHERE memb___id='" + Class28.sqlDataReader_2[0].ToString() + "'";
              Class28.sqlCommand_1.ExecuteReader();
            }
            catch (Exception ex)
            {
              ProjectData.SetProjectError(ex);
              ProjectData.ClearProjectError();
            }
            if (Class28.sqlConnection_1.State == ConnectionState.Open)
              Class28.sqlConnection_1.Close();
            try
            {
              Class28.sqlConnection_1.Open();
              Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
              Class28.sqlCommand_1.CommandText = "DELETE FROM AccountCharacter WHERE Id='" + Class28.sqlDataReader_2[0].ToString() + "'";
              Class28.sqlCommand_1.ExecuteReader();
            }
            catch (Exception ex)
            {
              ProjectData.SetProjectError(ex);
              ProjectData.ClearProjectError();
            }
            if (Class28.sqlConnection_1.State == ConnectionState.Open)
              Class28.sqlConnection_1.Close();
            try
            {
              Class28.sqlConnection_1.Open();
              Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
              Class28.sqlCommand_1.CommandText = "DELETE FROM Character WHERE AccountID='" + Class28.sqlDataReader_2[0].ToString() + "'";
              Class28.sqlCommand_1.ExecuteReader();
            }
            catch (Exception ex)
            {
              ProjectData.SetProjectError(ex);
              ProjectData.ClearProjectError();
            }
            if (Class28.sqlConnection_1.State == ConnectionState.Open)
              Class28.sqlConnection_1.Close();
            try
            {
              Class28.sqlConnection_1.Open();
              Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
              Class28.sqlCommand_1.CommandText = "DELETE FROM warehouse WHERE AccountID='" + Class28.sqlDataReader_2[0].ToString() + "'";
              Class28.sqlCommand_1.ExecuteReader();
            }
            catch (Exception ex)
            {
              ProjectData.SetProjectError(ex);
              ProjectData.ClearProjectError();
            }
            if (Class28.sqlConnection_1.State == ConnectionState.Open)
              Class28.sqlConnection_1.Close();
            try
            {
              Class28.sqlConnection_1.Open();
              Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
              Class28.sqlCommand_1.CommandText = "DELETE FROM " + str + " WHERE AccountID='" + Class28.sqlDataReader_2[0].ToString() + "'";
              Class28.sqlCommand_1.ExecuteReader();
            }
            catch (Exception ex)
            {
              ProjectData.SetProjectError(ex);
              ProjectData.ClearProjectError();
            }
            if (Class28.sqlConnection_1.State == ConnectionState.Open)
              Class28.sqlConnection_1.Close();
          }
          try
          {
            SQLMaker.DefInstance.ProgresBar.Value = num;
          }
          catch (Exception ex)
          {
            ProjectData.SetProjectError(ex);
            SQLMaker.DefInstance.ProgresBar.Value = checked ((int) Math.Round(unchecked (Conversions.ToDouble(this.InactiveAFF.Text) + 1.0)));
            this.TextLoad.Text = Conversions.ToString(Math.Round((double) this.ProgresBar.Value / (double) this.ProgresBar.Maximum * 100.0)) + "%";
            ProjectData.ClearProjectError();
          }
          checked { ++num; }
        }
        Class28.sqlDataReader_2.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      SQLMaker.DefInstance.ProgresBar.Value = checked ((int) Math.Round(unchecked (Conversions.ToDouble(this.InactiveAFF.Text) + 1.0)));
      this.TextLoad.Text = "100%";
      if (Class28.sqlConnection_1.State == ConnectionState.Open)
        Class28.sqlConnection_1.Close();
      if (Class28.sqlConnection_2.State == ConnectionState.Open)
        Class28.sqlConnection_2.Close();
      return (object) true;
    }

    public object BannedAccount()
    {
      Class7.smethod_0();
      Class7.smethod_1();
      string str = Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "ExtWareHouse", "ExtWareHouse");
      try
      {
        Class28.sqlConnection_2.Open();
        Class28.sqlCommand_2 = new SqlCommand();
        Class28.sqlCommand_2.Connection = Class28.sqlConnection_2;
        Class28.sqlCommand_2.CommandText = "SELECT AccountID, COUNT(AccountID) FROM Character WHERE CtlCode = 1 GROUP BY AccountID";
        Class28.sqlDataReader_2 = Class28.sqlCommand_2.ExecuteReader();
        int num1 = 0;
        SQLMaker.DefInstance.ProgresBar.Maximum = checked ((int) Math.Round(unchecked (Conversions.ToDouble(this.BannedAFF.Text) + 1.0)));
        while (Class28.sqlDataReader_2.Read())
        {
          int num2 = (int) Interaction.MsgBox((object) (Class28.sqlDataReader_2[0].ToString() + " - " + Class28.sqlDataReader_2[1].ToString()), MsgBoxStyle.OkOnly, (object) null);
          if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Class28.sqlDataReader_2[1].ToString(), this.NumPJ.Text, false) >= 0)
          {
            Class28.sqlCommand_1 = new SqlCommand();
            try
            {
              Class28.sqlConnection_1.Open();
              Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
              Class28.sqlCommand_1.CommandText = "DELETE FROM MEMB_STAT WHERE memb___id='" + Class28.sqlDataReader_2[0].ToString() + "'";
              Class28.sqlCommand_1.ExecuteReader();
            }
            catch (Exception ex)
            {
              ProjectData.SetProjectError(ex);
              ProjectData.ClearProjectError();
            }
            if (Class28.sqlConnection_1.State == ConnectionState.Open)
              Class28.sqlConnection_1.Close();
            try
            {
              Class28.sqlConnection_1.Open();
              Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
              Class28.sqlCommand_1.CommandText = "DELETE FROM MEMB_INFO WHERE memb___id='" + Class28.sqlDataReader_2[0].ToString() + "'";
              Class28.sqlCommand_1.ExecuteReader();
            }
            catch (Exception ex)
            {
              ProjectData.SetProjectError(ex);
              ProjectData.ClearProjectError();
            }
            if (Class28.sqlConnection_1.State == ConnectionState.Open)
              Class28.sqlConnection_1.Close();
            try
            {
              Class28.sqlConnection_1.Open();
              Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
              Class28.sqlCommand_1.CommandText = "DELETE FROM AccountCharacter WHERE Id='" + Class28.sqlDataReader_2[0].ToString() + "'";
              Class28.sqlCommand_1.ExecuteReader();
            }
            catch (Exception ex)
            {
              ProjectData.SetProjectError(ex);
              ProjectData.ClearProjectError();
            }
            if (Class28.sqlConnection_1.State == ConnectionState.Open)
              Class28.sqlConnection_1.Close();
            try
            {
              Class28.sqlConnection_1.Open();
              Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
              Class28.sqlCommand_1.CommandText = "DELETE FROM Character WHERE AccountID='" + Class28.sqlDataReader_2[0].ToString() + "'";
              Class28.sqlCommand_1.ExecuteReader();
            }
            catch (Exception ex)
            {
              ProjectData.SetProjectError(ex);
              ProjectData.ClearProjectError();
            }
            if (Class28.sqlConnection_1.State == ConnectionState.Open)
              Class28.sqlConnection_1.Close();
            try
            {
              Class28.sqlConnection_1.Open();
              Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
              Class28.sqlCommand_1.CommandText = "DELETE FROM warehouse WHERE AccountID='" + Class28.sqlDataReader_2[0].ToString() + "'";
              Class28.sqlCommand_1.ExecuteReader();
            }
            catch (Exception ex)
            {
              ProjectData.SetProjectError(ex);
              ProjectData.ClearProjectError();
            }
            if (Class28.sqlConnection_1.State == ConnectionState.Open)
              Class28.sqlConnection_1.Close();
            try
            {
              Class28.sqlConnection_1.Open();
              Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
              Class28.sqlCommand_1.CommandText = "DELETE FROM " + str + " WHERE AccountID='" + Class28.sqlDataReader_2[0].ToString() + "'";
              Class28.sqlCommand_1.ExecuteReader();
            }
            catch (Exception ex)
            {
              ProjectData.SetProjectError(ex);
              ProjectData.ClearProjectError();
            }
            if (Class28.sqlConnection_1.State == ConnectionState.Open)
              Class28.sqlConnection_1.Close();
          }
          try
          {
            SQLMaker.DefInstance.ProgresBar.Value = num1;
          }
          catch (Exception ex)
          {
            ProjectData.SetProjectError(ex);
            SQLMaker.DefInstance.ProgresBar.Value = checked ((int) Math.Round(unchecked (Conversions.ToDouble(this.BannedAFF.Text) + 1.0)));
            this.TextLoad.Text = Conversions.ToString(Math.Round((double) this.ProgresBar.Value / (double) this.ProgresBar.Maximum * 100.0)) + "%";
            ProjectData.ClearProjectError();
          }
          checked { ++num1; }
        }
        Class28.sqlDataReader_2.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      SQLMaker.DefInstance.ProgresBar.Value = checked ((int) Math.Round(unchecked (Conversions.ToDouble(this.BannedAFF.Text) + 1.0)));
      this.TextLoad.Text = "100%";
      if (Class28.sqlConnection_1.State == ConnectionState.Open)
        Class28.sqlConnection_1.Close();
      if (Class28.sqlConnection_2.State == ConnectionState.Open)
        Class28.sqlConnection_2.Close();
      return (object) true;
    }

    private void method_0()
    {
      Class7.smethod_0();
      Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "ExtWareHouse", "ExtWareHouse");
      try
      {
        Class28.sqlConnection_1.Open();
        Class28.sqlCommand_1 = new SqlCommand();
        Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
        Class28.sqlCommand_1.CommandText = "SELECT COUNT(Id) FROM AccountCharacter WHERE GameID1 IS NULL AND GameID2 IS NULL AND GameID3 IS NULL AND GameID4 IS NULL AND GameID5 IS NULL";
        Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
        Class28.sqlDataReader_1.Read();
        this.EmpyAFF.Text = Class28.sqlDataReader_1[0].ToString();
        Class28.sqlDataReader_1.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      if (Class28.sqlConnection_1.State != ConnectionState.Open)
        return;
      Class28.sqlConnection_1.Close();
    }

    private void method_1()
    {
      Class7.smethod_1();
      Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "ExtWareHouse", "ExtWareHouse");
      try
      {
        Class28.sqlConnection_2.Open();
        Class28.sqlCommand_2 = new SqlCommand();
        Class28.sqlCommand_2.Connection = Class28.sqlConnection_2;
        Class28.sqlCommand_2.CommandText = "SELECT memb___id, DisConnectTM FROM MEMB_STAT";
        Class28.sqlDataReader_2 = Class28.sqlCommand_2.ExecuteReader();
        int num1 = 0;
        while (Class28.sqlDataReader_2.Read())
        {
          int num2 = Convert.ToInt32(Decimal.Subtract(Conversions.ToDecimal(Strings.Mid(Conversions.ToString(DateAndTime.Now), 1, 2)), Conversions.ToDecimal(Strings.Mid(Class28.sqlDataReader_2[1].ToString(), 1, 2))));
          int num3 = Convert.ToInt32(Decimal.Multiply(Decimal.Subtract(Conversions.ToDecimal(Strings.Mid(Conversions.ToString(DateAndTime.Now), 4, 2)), Conversions.ToDecimal(Strings.Mid(Class28.sqlDataReader_2[1].ToString(), 4, 2))), new Decimal(30L)));
          int num4 = Convert.ToInt32(Decimal.Multiply(Decimal.Subtract(Conversions.ToDecimal(Strings.Mid(Conversions.ToString(DateAndTime.Now), 7, 4)), Conversions.ToDecimal(Strings.Mid(Class28.sqlDataReader_2[1].ToString(), 7, 4))), new Decimal(365L)));
          if (num2 < 0)
            checked { num2 *= -1; }
          if (Decimal.Compare(new Decimal(checked (num2 + num3 + num4)), Conversions.ToDecimal(this.Inactive.Text)) > 0)
          {
            checked { ++num1; }
            this.InactiveAFF.Text = Conversions.ToString(num1);
            this.InactiveAFF.Update();
          }
        }
        this.InactiveAFF.Text = Conversions.ToString(num1);
        Class28.sqlDataReader_2.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      if (Class28.sqlConnection_2.State != ConnectionState.Open)
        return;
      Class28.sqlConnection_2.Close();
    }

    private void method_2()
    {
      Class7.smethod_0();
      Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "ExtWareHouse", "ExtWareHouse");
      try
      {
        Class28.sqlConnection_1.Open();
        Class28.sqlCommand_1 = new SqlCommand();
        Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
        Class28.sqlCommand_1.CommandText = "SELECT AccountID, COUNT(AccountID) FROM Character WHERE CtlCode = 1 GROUP BY AccountID";
        Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
        int num = 0;
        while (Class28.sqlDataReader_1.Read())
        {
          if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Class28.sqlDataReader_1[1].ToString(), this.NumPJ.Text, false) >= 0)
          {
            checked { ++num; }
            this.BannedAFF.Text = Conversions.ToString(num);
            this.BannedAFF.Update();
          }
        }
        this.BannedAFF.Text = Conversions.ToString(num);
        Class28.sqlDataReader_1.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      if (Class28.sqlConnection_1.State != ConnectionState.Open)
        return;
      Class28.sqlConnection_1.Close();
    }

    public object RellenarDatos()
    {
      string str1 = Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "Personal", "DIAS", "90");
      string str2 = Class18.smethod_1(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "Personal", "PJ", "1");
      this.Inactive.Text = str1;
      this.NumPJ.Text = str2;
      return (object) true;
    }

    private void SQLMaker_Load(object sender, EventArgs e)
    {
      Class18.smethod_47();
      this.RellenarDatos();
      SQLMaker.DefInstance.ProgresBar.Value = 10;
      new Thread(new ThreadStart(this.method_0))
      {
        IsBackground = true
      }.Start();
      SQLMaker.DefInstance.ProgresBar.Value = 40;
      new Thread(new ThreadStart(this.method_1))
      {
        IsBackground = true
      }.Start();
      SQLMaker.DefInstance.ProgresBar.Value = 70;
      new Thread(new ThreadStart(this.method_2))
      {
        IsBackground = true
      }.Start();
      SQLMaker.DefInstance.ProgresBar.Value = 100;
    }

    private void EmpAccAply_Click(object sender, EventArgs e)
    {
      if (!Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual((object) Interaction.MsgBox((object) ("DELETE [" + this.EmpyAFF.Text + "] ACCOUNTS!!"), MsgBoxStyle.YesNo, (object) "!! DELETE !!"), (object) MsgBoxResult.Yes, false))
        return;
      this.EmpyAccount();
    }

    private void InacAccAply_Click(object sender, EventArgs e)
    {
      if (!Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual((object) Interaction.MsgBox((object) ("DELETE [" + this.InactiveAFF.Text + "] ACCOUNTS!!"), MsgBoxStyle.YesNo, (object) "!! DELETE !!"), (object) MsgBoxResult.Yes, false))
        return;
      this.InactiveAccount();
    }

    private void BanAccAply_Click(object sender, EventArgs e)
    {
      if (!Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual((object) Interaction.MsgBox((object) ("DELETE [" + this.BannedAFF.Text + "] ACCOUNTS!!"), MsgBoxStyle.YesNo, (object) "!! DELETE !!"), (object) MsgBoxResult.Yes, false))
        return;
      this.BannedAccount();
    }

    private void method_3(object sender, KeyPressEventArgs e)
    {
      if ((int) Class18.smethod_19(checked ((short) Strings.Asc(e.KeyChar))) == 0)
        e.Handled = true;
      if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(this.Inactive.Text, "", false) == 0)
        this.Inactive.Text = Conversions.ToString(1);
      if (Conversions.ToDouble(this.Inactive.Text) != 0.0)
        return;
      this.Inactive.Text = Conversions.ToString(1);
    }

    private void method_4(object sender, KeyPressEventArgs e)
    {
      if ((int) Class18.smethod_19(checked ((short) Strings.Asc(e.KeyChar))) == 0)
        e.Handled = true;
      if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(this.NumPJ.Text, "", false) == 0)
        this.NumPJ.Text = Conversions.ToString(1);
      if (Conversions.ToDouble(this.NumPJ.Text) != 0.0)
        return;
      this.NumPJ.Text = Conversions.ToString(1);
    }

    private void method_5(object sender, EventArgs e)
    {
      Class18.smethod_2(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "Personal", "DIAS", this.Inactive.Text);
    }

    private void method_6(object sender, EventArgs e)
    {
      Class18.smethod_2(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "Personal", "PJ", this.NumPJ.Text);
    }

    private void method_7(object sender, EventArgs e)
    {
      if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(this.Inactive.Text, "", false) == 0)
      {
        this.Inactive.Text = Conversions.ToString(1);
        this.Inactive.SelectAll();
      }
      if (Conversions.ToDouble(this.Inactive.Text) != 0.0)
        return;
      this.Inactive.Text = Conversions.ToString(1);
      this.Inactive.SelectAll();
    }

    private void method_8(object sender, EventArgs e)
    {
      if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(this.NumPJ.Text, "", false) == 0)
      {
        this.NumPJ.Text = Conversions.ToString(1);
        this.NumPJ.SelectAll();
      }
      if (Conversions.ToDouble(this.NumPJ.Text) == 0.0)
      {
        this.NumPJ.Text = Conversions.ToString(1);
        this.NumPJ.SelectAll();
      }
      if (Conversions.ToDouble(this.NumPJ.Text) <= 5.0)
        return;
      this.NumPJ.Text = Conversions.ToString(5);
      this.NumPJ.SelectAll();
    }

    private void Reload_Click(object sender, EventArgs e)
    {
      SQLMaker.DefInstance.ProgresBar.Value = 10;
      new Thread(new ThreadStart(this.method_0))
      {
        IsBackground = true
      }.Start();
      SQLMaker.DefInstance.ProgresBar.Value = 40;
      new Thread(new ThreadStart(this.method_1))
      {
        IsBackground = true
      }.Start();
      SQLMaker.DefInstance.ProgresBar.Value = 70;
      new Thread(new ThreadStart(this.method_2))
      {
        IsBackground = true
      }.Start();
      SQLMaker.DefInstance.ProgresBar.Value = 100;
    }
  }
}
