// Decompiled with JetBrains decompiler
// Type: MuMaker.StatsMaker
// Assembly: MuMaker, Version=1.1.3.0, Culture=neutral, PublicKeyToken=null
// MVID: 7E43A6C6-04AF-4159-BD3A-BD25660D1460
// Assembly location: D:\MuServer\Tools\MuMaker 1.13\MuMaker-cleaned.exe

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

namespace MuMaker
{
  [DesignerGenerated]
  public class StatsMaker : Form
  {
    private static StatsMaker statsMaker_0 = (StatsMaker) null;
    private IContainer icontainer_0;
    [AccessedThroughProperty("Label1")]
    private Label _Label1;
    [AccessedThroughProperty("Personaje")]
    private PictureBox _Personaje;
    [AccessedThroughProperty("Aplicar")]
    private Button _Aplicar;
    [AccessedThroughProperty("Cerrar")]
    private Button _Cerrar;
    [AccessedThroughProperty("Label28")]
    private Label _Label28;
    [AccessedThroughProperty("Label27")]
    private Label _Label27;
    [AccessedThroughProperty("Label26")]
    private Label _Label26;
    [AccessedThroughProperty("Label25")]
    private Label _Label25;
    [AccessedThroughProperty("Energia")]
    private TextBox _Energia;
    [AccessedThroughProperty("Fuerza")]
    private TextBox _Fuerza;
    [AccessedThroughProperty("Vitalidad")]
    private TextBox _Vitalidad;
    [AccessedThroughProperty("Agilidad")]
    private TextBox _Agilidad;
    [AccessedThroughProperty("Level")]
    private TextBox _Level;
    [AccessedThroughProperty("Puntos")]
    private TextBox _Puntos;
    [AccessedThroughProperty("Comand")]
    private TextBox _Comand;
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
    [AccessedThroughProperty("Clases")]
    private ComboBox _Clases;
    [AccessedThroughProperty("Salir")]
    private Button _Salir;
    [AccessedThroughProperty("Titulo")]
    private Label _Titulo;

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

    internal virtual PictureBox Personaje
    {
      [DebuggerNonUserCode] get
      {
        return this._Personaje;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Personaje = value;
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
        EventHandler eventHandler = new EventHandler(this.method_0);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_8);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_7);
        if (this._Aplicar != null)
        {
          this._Aplicar.Click -= eventHandler;
          this._Aplicar.MouseDown -= mouseEventHandler1;
          this._Aplicar.MouseUp -= mouseEventHandler2;
        }
        this._Aplicar = value;
        if (this._Aplicar == null)
          return;
        this._Aplicar.Click += eventHandler;
        this._Aplicar.MouseDown += mouseEventHandler1;
        this._Aplicar.MouseUp += mouseEventHandler2;
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
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_6);
        EventHandler eventHandler = new EventHandler(this.method_1);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_5);
        if (this._Cerrar != null)
        {
          this._Cerrar.MouseDown -= mouseEventHandler1;
          this._Cerrar.Click -= eventHandler;
          this._Cerrar.MouseUp -= mouseEventHandler2;
        }
        this._Cerrar = value;
        if (this._Cerrar == null)
          return;
        this._Cerrar.MouseDown += mouseEventHandler1;
        this._Cerrar.Click += eventHandler;
        this._Cerrar.MouseUp += mouseEventHandler2;
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

    internal virtual TextBox Energia
    {
      [DebuggerNonUserCode] get
      {
        return this._Energia;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Energia = value;
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
        this._Fuerza = value;
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
        this._Vitalidad = value;
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
        this._Agilidad = value;
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
        this._Level = value;
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
        this._Puntos = value;
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
        this._Comand = value;
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

    internal virtual Button Salir
    {
      [DebuggerNonUserCode] get
      {
        return this._Salir;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_4);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_3);
        EventHandler eventHandler = new EventHandler(this.method_2);
        if (this._Salir != null)
        {
          this._Salir.MouseDown -= mouseEventHandler1;
          this._Salir.MouseUp -= mouseEventHandler2;
          this._Salir.Click -= eventHandler;
        }
        this._Salir = value;
        if (this._Salir == null)
          return;
        this._Salir.MouseDown += mouseEventHandler1;
        this._Salir.MouseUp += mouseEventHandler2;
        this._Salir.Click += eventHandler;
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

    public static StatsMaker DefInstance
    {
      get
      {
        if (StatsMaker.statsMaker_0 != null && !StatsMaker.statsMaker_0.IsDisposed)
          StatsMaker.statsMaker_0.BringToFront();
        else
          StatsMaker.statsMaker_0 = new StatsMaker();
        return StatsMaker.statsMaker_0;
      }
      set
      {
        StatsMaker.statsMaker_0 = value;
      }
    }

    [DebuggerNonUserCode]
    public StatsMaker()
    {
      this.Load += new EventHandler(this.StatsMaker_Load);
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
      this.Label1 = new Label();
      this.Personaje = new PictureBox();
      this.Aplicar = new Button();
      this.Cerrar = new Button();
      this.Label28 = new Label();
      this.Label27 = new Label();
      this.Label26 = new Label();
      this.Label25 = new Label();
      this.Energia = new TextBox();
      this.Fuerza = new TextBox();
      this.Vitalidad = new TextBox();
      this.Agilidad = new TextBox();
      this.Level = new TextBox();
      this.Puntos = new TextBox();
      this.Comand = new TextBox();
      this.Label13 = new Label();
      this.Label12 = new Label();
      this.Label10 = new Label();
      this.Label6 = new Label();
      this.Label7 = new Label();
      this.Label11 = new Label();
      this.Label8 = new Label();
      this.Clases = new ComboBox();
      this.Salir = new Button();
      this.Titulo = new Label();
      ((ISupportInitialize) this.Personaje).BeginInit();
      this.SuspendLayout();
      this.Label1.BackColor = Color.Transparent;
      this.Label1.Font = new Font("Microsoft Sans Serif", 12f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label1.ForeColor = Color.DarkOrange;
      Label label1_1 = this.Label1;
      Point point1 = new Point(57, 28);
      Point point2 = point1;
      label1_1.Location = point2;
      this.Label1.Name = "Label1";
      Label label1_2 = this.Label1;
      Size size1 = new Size(262, 18);
      Size size2 = size1;
      label1_2.Size = size2;
      this.Label1.TabIndex = 440;
      this.Label1.Text = "Start Stats To Characters";
      this.Label1.TextAlign = ContentAlignment.MiddleCenter;
      this.Personaje.BackColor = Color.Transparent;
      PictureBox personaje1 = this.Personaje;
      point1 = new Point(172, 92);
      Point point3 = point1;
      personaje1.Location = point3;
      this.Personaje.Name = "Personaje";
      PictureBox personaje2 = this.Personaje;
      size1 = new Size(128, 128);
      Size size3 = size1;
      personaje2.Size = size3;
      this.Personaje.TabIndex = 439;
      this.Personaje.TabStop = false;
      this.Aplicar.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Aplicar.BackgroundImage = (Image) Class34.smethod_90();
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
      point1 = new Point(6, 223);
      Point point4 = point1;
      aplicar1.Location = point4;
      this.Aplicar.Name = "Aplicar";
      Button aplicar2 = this.Aplicar;
      size1 = new Size(54, 30);
      Size size4 = size1;
      aplicar2.Size = size4;
      this.Aplicar.TabIndex = 438;
      this.Aplicar.TabStop = false;
      this.Aplicar.UseVisualStyleBackColor = false;
      this.Cerrar.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) Class34.smethod_43();
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
      point1 = new Point(251, 225);
      Point point5 = point1;
      cerrar1.Location = point5;
      this.Cerrar.Name = "Cerrar";
      Button cerrar2 = this.Cerrar;
      size1 = new Size(52, 28);
      Size size5 = size1;
      cerrar2.Size = size5;
      this.Cerrar.TabIndex = 437;
      this.Cerrar.TabStop = false;
      this.Cerrar.UseVisualStyleBackColor = false;
      this.Label28.BackColor = Color.Black;
      Label label28_1 = this.Label28;
      point1 = new Point(304, 65);
      Point point6 = point1;
      label28_1.Location = point6;
      this.Label28.Name = "Label28";
      Label label28_2 = this.Label28;
      size1 = new Size(2, 20);
      Size size6 = size1;
      label28_2.Size = size6;
      this.Label28.TabIndex = 436;
      this.Label28.Text = "Label28";
      this.Label27.BackColor = Color.Black;
      Label label27_1 = this.Label27;
      point1 = new Point(168, 65);
      Point point7 = point1;
      label27_1.Location = point7;
      this.Label27.Name = "Label27";
      Label label27_2 = this.Label27;
      size1 = new Size(2, 20);
      Size size7 = size1;
      label27_2.Size = size7;
      this.Label27.TabIndex = 435;
      this.Label27.Text = "Label27";
      this.Label26.BackColor = Color.Black;
      Label label26_1 = this.Label26;
      point1 = new Point(168, 63);
      Point point8 = point1;
      label26_1.Location = point8;
      this.Label26.Name = "Label26";
      Label label26_2 = this.Label26;
      size1 = new Size(138, 2);
      Size size8 = size1;
      label26_2.Size = size8;
      this.Label26.TabIndex = 434;
      this.Label26.Text = "Label26";
      this.Label25.BackColor = Color.Black;
      Label label25_1 = this.Label25;
      point1 = new Point(168, 85);
      Point point9 = point1;
      label25_1.Location = point9;
      this.Label25.Name = "Label25";
      Label label25_2 = this.Label25;
      size1 = new Size(138, 2);
      Size size9 = size1;
      label25_2.Size = size9;
      this.Label25.TabIndex = 433;
      this.Label25.Text = "Label25";
      this.Energia.BackColor = Color.White;
      this.Energia.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Energia.ForeColor = Color.Black;
      TextBox energia1 = this.Energia;
      point1 = new Point(77, 175);
      Point point10 = point1;
      energia1.Location = point10;
      this.Energia.MaxLength = 5;
      this.Energia.Name = "Energia";
      TextBox energia2 = this.Energia;
      size1 = new Size(87, 20);
      Size size10 = size1;
      energia2.Size = size10;
      this.Energia.TabIndex = 423;
      this.Fuerza.BackColor = Color.White;
      this.Fuerza.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Fuerza.ForeColor = Color.Black;
      TextBox fuerza1 = this.Fuerza;
      point1 = new Point(77, 101);
      Point point11 = point1;
      fuerza1.Location = point11;
      this.Fuerza.MaxLength = 5;
      this.Fuerza.Name = "Fuerza";
      TextBox fuerza2 = this.Fuerza;
      size1 = new Size(87, 20);
      Size size11 = size1;
      fuerza2.Size = size11;
      this.Fuerza.TabIndex = 420;
      this.Vitalidad.BackColor = Color.White;
      this.Vitalidad.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Vitalidad.ForeColor = Color.Black;
      TextBox vitalidad1 = this.Vitalidad;
      point1 = new Point(77, 151);
      Point point12 = point1;
      vitalidad1.Location = point12;
      this.Vitalidad.MaxLength = 5;
      this.Vitalidad.Name = "Vitalidad";
      TextBox vitalidad2 = this.Vitalidad;
      size1 = new Size(87, 20);
      Size size12 = size1;
      vitalidad2.Size = size12;
      this.Vitalidad.TabIndex = 422;
      this.Agilidad.BackColor = Color.White;
      this.Agilidad.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Agilidad.ForeColor = Color.Black;
      TextBox agilidad1 = this.Agilidad;
      point1 = new Point(77, (int) sbyte.MaxValue);
      Point point13 = point1;
      agilidad1.Location = point13;
      this.Agilidad.MaxLength = 5;
      this.Agilidad.Name = "Agilidad";
      TextBox agilidad2 = this.Agilidad;
      size1 = new Size(87, 20);
      Size size13 = size1;
      agilidad2.Size = size13;
      this.Agilidad.TabIndex = 421;
      this.Level.BackColor = Color.White;
      this.Level.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Level.ForeColor = Color.Black;
      TextBox level1 = this.Level;
      point1 = new Point(77, 53);
      Point point14 = point1;
      level1.Location = point14;
      this.Level.MaxLength = 3;
      this.Level.Name = "Level";
      TextBox level2 = this.Level;
      size1 = new Size(87, 20);
      Size size14 = size1;
      level2.Size = size14;
      this.Level.TabIndex = 418;
      this.Puntos.BackColor = Color.White;
      this.Puntos.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Puntos.ForeColor = Color.Black;
      TextBox puntos1 = this.Puntos;
      point1 = new Point(77, 77);
      Point point15 = point1;
      puntos1.Location = point15;
      this.Puntos.MaxLength = 4;
      this.Puntos.Name = "Puntos";
      TextBox puntos2 = this.Puntos;
      size1 = new Size(87, 20);
      Size size15 = size1;
      puntos2.Size = size15;
      this.Puntos.TabIndex = 419;
      this.Comand.BackColor = Color.White;
      this.Comand.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Comand.ForeColor = Color.Black;
      TextBox comand1 = this.Comand;
      point1 = new Point(77, 199);
      Point point16 = point1;
      comand1.Location = point16;
      this.Comand.MaxLength = 5;
      this.Comand.Name = "Comand";
      TextBox comand2 = this.Comand;
      size1 = new Size(87, 20);
      Size size16 = size1;
      comand2.Size = size16;
      this.Comand.TabIndex = 424;
      this.Label13.BackColor = Color.Transparent;
      this.Label13.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label13.ForeColor = Color.DimGray;
      Label label13_1 = this.Label13;
      point1 = new Point(7, 201);
      Point point17 = point1;
      label13_1.Location = point17;
      this.Label13.Name = "Label13";
      Label label13_2 = this.Label13;
      size1 = new Size(70, 16);
      Size size17 = size1;
      label13_2.Size = size17;
      this.Label13.TabIndex = 432;
      this.Label13.Text = "Command :";
      this.Label13.TextAlign = ContentAlignment.MiddleLeft;
      this.Label12.BackColor = Color.Transparent;
      this.Label12.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label12.ForeColor = Color.DimGray;
      Label label12_1 = this.Label12;
      point1 = new Point(7, 177);
      Point point18 = point1;
      label12_1.Location = point18;
      this.Label12.Name = "Label12";
      Label label12_2 = this.Label12;
      size1 = new Size(70, 16);
      Size size18 = size1;
      label12_2.Size = size18;
      this.Label12.TabIndex = 431;
      this.Label12.Text = "Energy :";
      this.Label12.TextAlign = ContentAlignment.MiddleLeft;
      this.Label10.BackColor = Color.Transparent;
      this.Label10.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label10.ForeColor = Color.DimGray;
      Label label10_1 = this.Label10;
      point1 = new Point(7, 79);
      Point point19 = point1;
      label10_1.Location = point19;
      this.Label10.Name = "Label10";
      Label label10_2 = this.Label10;
      size1 = new Size(70, 16);
      Size size19 = size1;
      label10_2.Size = size19;
      this.Label10.TabIndex = 429;
      this.Label10.Text = "Points :";
      this.Label10.TextAlign = ContentAlignment.MiddleLeft;
      this.Label6.BackColor = Color.Transparent;
      this.Label6.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label6.ForeColor = Color.DimGray;
      Label label6_1 = this.Label6;
      point1 = new Point(7, 55);
      Point point20 = point1;
      label6_1.Location = point20;
      this.Label6.Name = "Label6";
      Label label6_2 = this.Label6;
      size1 = new Size(70, 16);
      Size size20 = size1;
      label6_2.Size = size20;
      this.Label6.TabIndex = 426;
      this.Label6.Text = "Level :";
      this.Label6.TextAlign = ContentAlignment.MiddleLeft;
      this.Label7.BackColor = Color.Transparent;
      this.Label7.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label7.ForeColor = Color.DimGray;
      Label label7_1 = this.Label7;
      point1 = new Point(7, 129);
      Point point21 = point1;
      label7_1.Location = point21;
      this.Label7.Name = "Label7";
      Label label7_2 = this.Label7;
      size1 = new Size(70, 16);
      Size size21 = size1;
      label7_2.Size = size21;
      this.Label7.TabIndex = 427;
      this.Label7.Text = "Agility :";
      this.Label7.TextAlign = ContentAlignment.MiddleLeft;
      this.Label11.BackColor = Color.Transparent;
      this.Label11.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label11.ForeColor = Color.DimGray;
      Label label11_1 = this.Label11;
      point1 = new Point(7, 153);
      Point point22 = point1;
      label11_1.Location = point22;
      this.Label11.Name = "Label11";
      Label label11_2 = this.Label11;
      size1 = new Size(70, 16);
      Size size22 = size1;
      label11_2.Size = size22;
      this.Label11.TabIndex = 430;
      this.Label11.Text = "Vitality :";
      this.Label11.TextAlign = ContentAlignment.MiddleLeft;
      this.Label8.BackColor = Color.Transparent;
      this.Label8.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label8.ForeColor = Color.DimGray;
      Label label8_1 = this.Label8;
      point1 = new Point(7, 103);
      Point point23 = point1;
      label8_1.Location = point23;
      this.Label8.Name = "Label8";
      Label label8_2 = this.Label8;
      size1 = new Size(70, 16);
      Size size23 = size1;
      label8_2.Size = size23;
      this.Label8.TabIndex = 428;
      this.Label8.Text = "Strength :";
      this.Label8.TextAlign = ContentAlignment.MiddleLeft;
      this.Clases.BackColor = Color.Black;
      this.Clases.Cursor = Cursors.Hand;
      this.Clases.DropDownWidth = 8;
      this.Clases.Font = new Font("Microsoft Sans Serif", 10f, FontStyle.Bold);
      this.Clases.ForeColor = Color.DarkGoldenrod;
      this.Clases.ItemHeight = 16;
      this.Clases.Items.AddRange(new object[6]
      {
        (object) "Dark Wizard",
        (object) "Dark Knight",
        (object) "Fairy Elf",
        (object) "Magic Gladiator",
        (object) "Dark Lord",
        (object) "Summoner"
      });
      ComboBox clases1 = this.Clases;
      point1 = new Point(168, 63);
      Point point24 = point1;
      clases1.Location = point24;
      this.Clases.Name = "Clases";
      ComboBox clases2 = this.Clases;
      size1 = new Size(138, 24);
      Size size24 = size1;
      clases2.Size = size24;
      this.Clases.TabIndex = 425;
      this.Salir.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Salir.BackgroundImage = (Image) Class34.smethod_39();
      this.Salir.BackgroundImageLayout = ImageLayout.Center;
      this.Salir.Cursor = Cursors.Hand;
      this.Salir.DialogResult = DialogResult.Cancel;
      this.Salir.FlatAppearance.BorderSize = 0;
      this.Salir.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.Salir.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.Salir.FlatStyle = FlatStyle.Flat;
      this.Salir.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Salir.ForeColor = Color.Transparent;
      Button salir1 = this.Salir;
      point1 = new Point(290, 7);
      Point point25 = point1;
      salir1.Location = point25;
      this.Salir.Name = "Salir";
      Button salir2 = this.Salir;
      size1 = new Size(13, 13);
      Size size25 = size1;
      salir2.Size = size25;
      this.Salir.TabIndex = 487;
      this.Salir.TabStop = false;
      this.Salir.UseVisualStyleBackColor = false;
      this.Titulo.AutoSize = true;
      this.Titulo.BackColor = Color.Transparent;
      this.Titulo.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Titulo.ForeColor = Color.DarkOrange;
      Label titulo1 = this.Titulo;
      point1 = new Point(57, 7);
      Point point26 = point1;
      titulo1.Location = point26;
      this.Titulo.Name = "Titulo";
      Label titulo2 = this.Titulo;
      size1 = new Size(0, 13);
      Size size26 = size1;
      titulo2.Size = size26;
      this.Titulo.TabIndex = 488;
      this.AutoScaleMode = AutoScaleMode.Inherit;
      this.BackColor = Color.Black;
      // ISSUE: reference to a compiler-generated method
      this.BackgroundImage = (Image) Class34.smethod_107();
      this.CancelButton = (IButtonControl) this.Cerrar;
      size1 = new Size(310, 260);
      this.ClientSize = size1;
      this.Controls.Add((Control) this.Titulo);
      this.Controls.Add((Control) this.Salir);
      this.Controls.Add((Control) this.Label1);
      this.Controls.Add((Control) this.Personaje);
      this.Controls.Add((Control) this.Aplicar);
      this.Controls.Add((Control) this.Cerrar);
      this.Controls.Add((Control) this.Label28);
      this.Controls.Add((Control) this.Label27);
      this.Controls.Add((Control) this.Label26);
      this.Controls.Add((Control) this.Label25);
      this.Controls.Add((Control) this.Energia);
      this.Controls.Add((Control) this.Fuerza);
      this.Controls.Add((Control) this.Vitalidad);
      this.Controls.Add((Control) this.Agilidad);
      this.Controls.Add((Control) this.Level);
      this.Controls.Add((Control) this.Puntos);
      this.Controls.Add((Control) this.Comand);
      this.Controls.Add((Control) this.Label13);
      this.Controls.Add((Control) this.Label12);
      this.Controls.Add((Control) this.Label10);
      this.Controls.Add((Control) this.Label6);
      this.Controls.Add((Control) this.Label7);
      this.Controls.Add((Control) this.Label11);
      this.Controls.Add((Control) this.Label8);
      this.Controls.Add((Control) this.Clases);
      this.FormBorderStyle = FormBorderStyle.None;
      this.MaximizeBox = false;
      this.MinimizeBox = false;
      this.Name = "StatsMaker";
      this.ShowInTaskbar = false;
      this.StartPosition = FormStartPosition.CenterScreen;
      this.Text = "StatsMaker";
      ((ISupportInitialize) this.Personaje).EndInit();
      this.ResumeLayout(false);
      this.PerformLayout();
    }

    public object ModificarStats()
    {
      object Right = (object) checked (this.Clases.SelectedIndex * 16);
      Class7.smethod_0();
      try
      {
        Class28.sqlConnection_1.Open();
        Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
        Class28.sqlCommand_1.CommandText = Conversions.ToString(Operators.ConcatenateObject(Operators.ConcatenateObject((object) ("UPDATE DefaultClassType SET Level='" + this.Level.Text + "', LevelUpPoint='" + this.Puntos.Text + "', Strength='" + this.Fuerza.Text + "', Dexterity='" + this.Agilidad.Text + "', Vitality='" + this.Vitalidad.Text + "', Energy='" + this.Energia.Text + "', Leadership='" + this.Comand.Text + "' WHERE Class='"), Right), (object) "'"));
        Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
        Class28.sqlDataReader_1.Close();
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

    private void StatsMaker_Load(object sender, EventArgs e)
    {
      this.Text = Conversions.ToString(Operators.ConcatenateObject((object) (this.Text + " - "), Class26.object_18));
      this.Titulo.Text = this.Text;
      this.Clases.SelectedIndex = 0;
      Class8.smethod_2((object) this.Clases.SelectedIndex);
    }

    private void Clases_SelectedIndexChanged(object sender, EventArgs e)
    {
      if (this.Clases.SelectedIndex == 0)
        this.Personaje.BackgroundImage = (Image) new Bitmap(Class18.smethod_30(Class18.smethod_31((object) Class27.string_1)));
      if (this.Clases.SelectedIndex == 1)
        this.Personaje.BackgroundImage = (Image) new Bitmap(Class18.smethod_30(Class18.smethod_31((object) Class27.string_6)));
      if (this.Clases.SelectedIndex == 2)
        this.Personaje.BackgroundImage = (Image) new Bitmap(Class18.smethod_30(Class18.smethod_31((object) Class27.string_11)));
      if (this.Clases.SelectedIndex == 3)
        this.Personaje.BackgroundImage = (Image) new Bitmap(Class18.smethod_30(Class18.smethod_31((object) Class27.string_16)));
      if (this.Clases.SelectedIndex == 4)
        this.Personaje.BackgroundImage = (Image) new Bitmap(Class18.smethod_30(Class18.smethod_31((object) Class27.string_20)));
      if (this.Clases.SelectedIndex == 5)
        this.Personaje.BackgroundImage = (Image) new Bitmap(Class18.smethod_30(Class18.smethod_31((object) Class27.string_24)));
      Class8.smethod_2((object) checked (this.Clases.SelectedIndex * 16));
      this.Fuerza.Text = Class22.struct1_1.string_5;
      this.Agilidad.Text = Class22.struct1_1.string_6;
      this.Vitalidad.Text = Class22.struct1_1.string_7;
      this.Energia.Text = Class22.struct1_1.string_8;
      this.Comand.Text = Class22.struct1_1.string_9;
      this.Level.Text = Class22.struct1_1.string_2;
      this.Puntos.Text = Class22.struct1_1.string_3;
    }

    private void method_0(object sender, EventArgs e)
    {
      this.ModificarStats();
    }

    private void method_1(object sender, EventArgs e)
    {
      this.Close();
    }

    private void method_2(object sender, EventArgs e)
    {
      this.Close();
    }

    private void method_3(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Salir.BackgroundImage = (Image) Class34.smethod_39();
    }

    private void method_4(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Salir.BackgroundImage = (Image) Class34.smethod_40();
    }

    private void method_5(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) Class34.smethod_43();
    }

    private void method_6(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) Class34.smethod_46();
    }

    private void method_7(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Aplicar.BackgroundImage = (Image) Class34.smethod_90();
    }

    private void method_8(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Aplicar.BackgroundImage = (Image) Class34.smethod_91();
    }
  }
}
