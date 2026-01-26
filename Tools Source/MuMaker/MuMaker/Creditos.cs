// Decompiled with JetBrains decompiler
// Type: MuMaker.Creditos
// Assembly: MuMaker, Version=1.1.3.0, Culture=neutral, PublicKeyToken=null
// MVID: 7E43A6C6-04AF-4159-BD3A-BD25660D1460
// Assembly location: D:\MuServer\Tools\MuMaker 1.13\MuMaker-cleaned.exe

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
  public class Creditos : Form
  {
    private static Creditos creditos_0 = (Creditos) null;
    private IContainer icontainer_0;
    [AccessedThroughProperty("Messenger")]
    private TextBox _Messenger;
    [AccessedThroughProperty("Email")]
    private LinkLabel _Email;
    [AccessedThroughProperty("Cerrar")]
    private Button _Cerrar;
    [AccessedThroughProperty("Nombre")]
    private Label _Nombre;
    [AccessedThroughProperty("Label6")]
    private Label _Label6;
    [AccessedThroughProperty("Label5")]
    private Label _Label5;
    [AccessedThroughProperty("Titulo")]
    private Label _Titulo;
    [AccessedThroughProperty("Label4")]
    private Label _Label4;
    [AccessedThroughProperty("LinkWEB")]
    private LinkLabel _LinkWEB;
    [AccessedThroughProperty("LinkFORO")]
    private LinkLabel _LinkFORO;
    [AccessedThroughProperty("PayPal")]
    private PictureBox _PayPal;

    internal virtual TextBox Messenger
    {
      [DebuggerNonUserCode] get
      {
        return this._Messenger;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Messenger_Click);
        if (this._Messenger != null)
          this._Messenger.Click -= eventHandler;
        this._Messenger = value;
        if (this._Messenger == null)
          return;
        this._Messenger.Click += eventHandler;
      }
    }

    internal virtual LinkLabel Email
    {
      [DebuggerNonUserCode] get
      {
        return this._Email;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        LinkLabelLinkClickedEventHandler clickedEventHandler = new LinkLabelLinkClickedEventHandler(this.Email_LinkClicked);
        if (this._Email != null)
          this._Email.LinkClicked -= clickedEventHandler;
        this._Email = value;
        if (this._Email == null)
          return;
        this._Email.LinkClicked += clickedEventHandler;
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
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_2);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_1);
        EventHandler eventHandler = new EventHandler(this.method_0);
        if (this._Cerrar != null)
        {
          this._Cerrar.MouseDown -= mouseEventHandler1;
          this._Cerrar.MouseUp -= mouseEventHandler2;
          this._Cerrar.Click -= eventHandler;
        }
        this._Cerrar = value;
        if (this._Cerrar == null)
          return;
        this._Cerrar.MouseDown += mouseEventHandler1;
        this._Cerrar.MouseUp += mouseEventHandler2;
        this._Cerrar.Click += eventHandler;
      }
    }

    internal virtual Label Nombre
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

    internal virtual LinkLabel LinkWEB
    {
      [DebuggerNonUserCode] get
      {
        return this._LinkWEB;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        LinkLabelLinkClickedEventHandler clickedEventHandler = new LinkLabelLinkClickedEventHandler(this.LinkWEB_LinkClicked);
        if (this._LinkWEB != null)
          this._LinkWEB.LinkClicked -= clickedEventHandler;
        this._LinkWEB = value;
        if (this._LinkWEB == null)
          return;
        this._LinkWEB.LinkClicked += clickedEventHandler;
      }
    }

    internal virtual LinkLabel LinkFORO
    {
      [DebuggerNonUserCode] get
      {
        return this._LinkFORO;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        LinkLabelLinkClickedEventHandler clickedEventHandler = new LinkLabelLinkClickedEventHandler(this.LinkFORO_LinkClicked);
        if (this._LinkFORO != null)
          this._LinkFORO.LinkClicked -= clickedEventHandler;
        this._LinkFORO = value;
        if (this._LinkFORO == null)
          return;
        this._LinkFORO.LinkClicked += clickedEventHandler;
      }
    }

    internal virtual PictureBox PayPal
    {
      [DebuggerNonUserCode] get
      {
        return this._PayPal;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.PayPal_Click);
        if (this._PayPal != null)
          this._PayPal.Click -= eventHandler;
        this._PayPal = value;
        if (this._PayPal == null)
          return;
        this._PayPal.Click += eventHandler;
      }
    }

    public static Creditos DefInstance
    {
      get
      {
        if (Creditos.creditos_0 != null && !Creditos.creditos_0.IsDisposed)
          Creditos.creditos_0.BringToFront();
        else
          Creditos.creditos_0 = new Creditos();
        return Creditos.creditos_0;
      }
      set
      {
        Creditos.creditos_0 = value;
      }
    }

    [DebuggerNonUserCode]
    public Creditos()
    {
      this.Load += new EventHandler(this.Creditos_Load);
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
      this.Messenger = new TextBox();
      this.Email = new LinkLabel();
      this.Cerrar = new Button();
      this.Nombre = new Label();
      this.Label6 = new Label();
      this.Label5 = new Label();
      this.Titulo = new Label();
      this.Label4 = new Label();
      this.LinkWEB = new LinkLabel();
      this.LinkFORO = new LinkLabel();
      this.PayPal = new PictureBox();
      ((ISupportInitialize) this.PayPal).BeginInit();
      this.SuspendLayout();
      this.Messenger.BackColor = Color.Black;
      this.Messenger.BorderStyle = BorderStyle.None;
      this.Messenger.Cursor = Cursors.IBeam;
      this.Messenger.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Messenger.ForeColor = Color.DarkGoldenrod;
      TextBox messenger1 = this.Messenger;
      Point point1 = new Point(61, 86);
      Point point2 = point1;
      messenger1.Location = point2;
      this.Messenger.Name = "Messenger";
      this.Messenger.ReadOnly = true;
      TextBox messenger2 = this.Messenger;
      Size size1 = new Size(143, 13);
      Size size2 = size1;
      messenger2.Size = size2;
      this.Messenger.TabIndex = 244;
      this.Messenger.Text = "TimTrucho@Hotmail.com";
      this.Email.ActiveLinkColor = Color.Chocolate;
      this.Email.BackColor = Color.Transparent;
      this.Email.Cursor = Cursors.Hand;
      this.Email.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Email.ForeColor = Color.Transparent;
      this.Email.LinkColor = Color.DarkOrange;
      LinkLabel email1 = this.Email;
      point1 = new Point(58, 62);
      Point point3 = point1;
      email1.Location = point3;
      this.Email.Name = "Email";
      LinkLabel email2 = this.Email;
      size1 = new Size(188, 14);
      Size size3 = size1;
      email2.Size = size3;
      this.Email.TabIndex = 243;
      this.Email.TabStop = true;
      this.Email.Text = "timtrucho@yahoo.es";
      this.Email.VisitedLinkColor = Color.DarkOrange;
      this.Cerrar.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) Class34.smethod_43();
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
      point1 = new Point(440, 74);
      Point point4 = point1;
      cerrar1.Location = point4;
      this.Cerrar.Name = "Cerrar";
      Button cerrar2 = this.Cerrar;
      size1 = new Size(52, 28);
      Size size4 = size1;
      cerrar2.Size = size4;
      this.Cerrar.TabIndex = 242;
      this.Cerrar.TabStop = false;
      this.Cerrar.UseVisualStyleBackColor = false;
      this.Nombre.BackColor = Color.Transparent;
      this.Nombre.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Nombre.ForeColor = Color.DarkOrange;
      Label nombre1 = this.Nombre;
      point1 = new Point(58, 39);
      Point point5 = point1;
      nombre1.Location = point5;
      this.Nombre.Name = "Nombre";
      Label nombre2 = this.Nombre;
      size1 = new Size(278, 12);
      Size size5 = size1;
      nombre2.Size = size5;
      this.Nombre.TabIndex = 241;
      this.Nombre.Text = "Manuel Fernandez Gundin - TimTrucho - TMT";
      this.Label6.BackColor = Color.Transparent;
      this.Label6.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label6.ForeColor = Color.DarkGray;
      Label label6_1 = this.Label6;
      point1 = new Point(14, 37);
      Point point6 = point1;
      label6_1.Location = point6;
      this.Label6.Name = "Label6";
      Label label6_2 = this.Label6;
      size1 = new Size(46, 12);
      Size size6 = size1;
      label6_2.Size = size6;
      this.Label6.TabIndex = 239;
      this.Label6.Text = "Autor :";
      this.Label5.BackColor = Color.Transparent;
      this.Label5.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label5.ForeColor = Color.DarkGray;
      Label label5_1 = this.Label5;
      point1 = new Point(13, 62);
      Point point7 = point1;
      label5_1.Location = point7;
      this.Label5.Name = "Label5";
      Label label5_2 = this.Label5;
      size1 = new Size(46, 12);
      Size size7 = size1;
      label5_2.Size = size7;
      this.Label5.TabIndex = 238;
      this.Label5.Text = "E-Mail:";
      this.Titulo.AutoSize = true;
      this.Titulo.BackColor = Color.Transparent;
      this.Titulo.Font = new Font("Microsoft Sans Serif", 14f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Titulo.ForeColor = Color.DarkGray;
      Label titulo1 = this.Titulo;
      point1 = new Point(71, 9);
      Point point8 = point1;
      titulo1.Location = point8;
      this.Titulo.Name = "Titulo";
      Label titulo2 = this.Titulo;
      size1 = new Size(358, 24);
      Size size8 = size1;
      titulo2.Size = size8;
      this.Titulo.TabIndex = 236;
      this.Titulo.Text = "MuMaker - SoftWare TMT - MuOnline";
      this.Label4.BackColor = Color.Transparent;
      this.Label4.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label4.ForeColor = Color.DarkGray;
      Label label4_1 = this.Label4;
      point1 = new Point(14, 87);
      Point point9 = point1;
      label4_1.Location = point9;
      this.Label4.Name = "Label4";
      Label label4_2 = this.Label4;
      size1 = new Size(38, 12);
      Size size9 = size1;
      label4_2.Size = size9;
      this.Label4.TabIndex = 237;
      this.Label4.Text = "MSN:";
      this.LinkWEB.ActiveLinkColor = Color.Chocolate;
      this.LinkWEB.AutoSize = true;
      this.LinkWEB.BackColor = Color.Transparent;
      this.LinkWEB.Cursor = Cursors.Hand;
      this.LinkWEB.Font = new Font("Microsoft Sans Serif", 15.75f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.LinkWEB.ForeColor = Color.Transparent;
      this.LinkWEB.LinkColor = Color.DarkOrange;
      LinkLabel linkWeb1 = this.LinkWEB;
      point1 = new Point(252, 66);
      Point point10 = point1;
      linkWeb1.Location = point10;
      this.LinkWEB.Name = "LinkWEB";
      LinkLabel linkWeb2 = this.LinkWEB;
      size1 = new Size(63, 25);
      Size size10 = size1;
      linkWeb2.Size = size10;
      this.LinkWEB.TabIndex = 246;
      this.LinkWEB.TabStop = true;
      this.LinkWEB.Text = "WEB";
      this.LinkWEB.VisitedLinkColor = Color.DarkOrange;
      this.LinkFORO.ActiveLinkColor = Color.Chocolate;
      this.LinkFORO.AutoSize = true;
      this.LinkFORO.BackColor = Color.Transparent;
      this.LinkFORO.Cursor = Cursors.Hand;
      this.LinkFORO.Font = new Font("Microsoft Sans Serif", 15.75f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.LinkFORO.ForeColor = Color.Transparent;
      this.LinkFORO.LinkColor = Color.DarkOrange;
      LinkLabel linkForo1 = this.LinkFORO;
      point1 = new Point(341, 66);
      Point point11 = point1;
      linkForo1.Location = point11;
      this.LinkFORO.Name = "LinkFORO";
      LinkLabel linkForo2 = this.LinkFORO;
      size1 = new Size(76, 25);
      Size size11 = size1;
      linkForo2.Size = size11;
      this.LinkFORO.TabIndex = 248;
      this.LinkFORO.TabStop = true;
      this.LinkFORO.Text = "FORO";
      this.LinkFORO.VisitedLinkColor = Color.DarkOrange;
      this.PayPal.BackgroundImageLayout = ImageLayout.Center;
      this.PayPal.Cursor = Cursors.Hand;
      // ISSUE: reference to a compiler-generated method
      this.PayPal.Image = (Image) Class34.smethod_94();
      PictureBox payPal1 = this.PayPal;
      point1 = new Point(429, 25);
      Point point12 = point1;
      payPal1.Location = point12;
      this.PayPal.Name = "PayPal";
      PictureBox payPal2 = this.PayPal;
      size1 = new Size(62, 31);
      Size size12 = size1;
      payPal2.Size = size12;
      this.PayPal.TabIndex = 316;
      this.PayPal.TabStop = false;
      this.AutoScaleMode = AutoScaleMode.Inherit;
      this.BackColor = Color.Black;
      // ISSUE: reference to a compiler-generated method
      this.BackgroundImage = (Image) Class34.smethod_52();
      this.CancelButton = (IButtonControl) this.Cerrar;
      size1 = new Size(500, 111);
      this.ClientSize = size1;
      this.Controls.Add((Control) this.PayPal);
      this.Controls.Add((Control) this.LinkFORO);
      this.Controls.Add((Control) this.LinkWEB);
      this.Controls.Add((Control) this.Messenger);
      this.Controls.Add((Control) this.Email);
      this.Controls.Add((Control) this.Cerrar);
      this.Controls.Add((Control) this.Nombre);
      this.Controls.Add((Control) this.Label6);
      this.Controls.Add((Control) this.Label5);
      this.Controls.Add((Control) this.Titulo);
      this.Controls.Add((Control) this.Label4);
      this.FormBorderStyle = FormBorderStyle.None;
      this.MaximizeBox = false;
      size1 = new Size(500, 111);
      this.MaximumSize = size1;
      this.MinimizeBox = false;
      size1 = new Size(500, 111);
      this.MinimumSize = size1;
      this.Name = "Creditos";
      this.ShowInTaskbar = false;
      this.StartPosition = FormStartPosition.CenterScreen;
      this.Text = "Creditos";
      this.TransparencyKey = Color.Red;
      ((ISupportInitialize) this.PayPal).EndInit();
      this.ResumeLayout(false);
      this.PerformLayout();
    }

    private void Creditos_Load(object sender, EventArgs e)
    {
      this.Messenger.Focus();
    }

    private void Email_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
    {
      Process.Start("mailto:timtrucho@yahoo.es?subject=MuMaker " + Class2.smethod_3().method_8().RealVersion.Text + "!!");
    }

    private void LinkWEB_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
    {
      Process.Start("http://softwaretmt.sytes.net/mumaker");
    }

    private void LinkFORO_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
    {
      Process.Start("http://softwaretmt.sytes.net/mumaker/foro");
    }

    private void Messenger_Click(object sender, EventArgs e)
    {
      this.Messenger.SelectAll();
    }

    private void method_0(object sender, EventArgs e)
    {
      this.Messenger.Focus();
      this.Close();
    }

    private void PayPal_Click(object sender, EventArgs e)
    {
      Process.Start("http://softwaretmt.sytes.net/mumaker/index.php?modulo=paypal");
    }

    private void method_1(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) Class34.smethod_43();
      this.Messenger.Focus();
    }

    private void method_2(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) Class34.smethod_46();
    }
  }
}
