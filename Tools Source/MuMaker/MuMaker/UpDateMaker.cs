// Decompiled with JetBrains decompiler
// Type: MuMaker.UpDateMaker
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
  public class UpDateMaker : Form
  {
    private static UpDateMaker upDateMaker_0 = (UpDateMaker) null;
    private IContainer icontainer_0;
    [AccessedThroughProperty("Label3")]
    private Label _Label3;
    [AccessedThroughProperty("Label2")]
    private Label _Label2;
    [AccessedThroughProperty("LastVersion")]
    private Label _LastVersion;
    [AccessedThroughProperty("PictureBox3")]
    private PictureBox _PictureBox3;
    [AccessedThroughProperty("Label1")]
    private Label _Label1;
    [AccessedThroughProperty("Version")]
    private Label _Version;
    [AccessedThroughProperty("PictureBox2")]
    private PictureBox _PictureBox2;
    [AccessedThroughProperty("PictureBox1")]
    private PictureBox _PictureBox1;
    [AccessedThroughProperty("Reload")]
    private Button _Reload;
    [AccessedThroughProperty("PictureBox4")]
    private PictureBox _PictureBox4;
    [AccessedThroughProperty("Cerrar")]
    private Button _Cerrar;
    [AccessedThroughProperty("UPDT")]
    private Timer timer_0;
    [AccessedThroughProperty("InfoMakerWEB")]
    private WebBrowser _InfoMakerWEB;
    [AccessedThroughProperty("LinkMirror")]
    private PictureBox _LinkMirror;
    [AccessedThroughProperty("ToolTips")]
    private ToolTip toolTip_0;

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

    internal virtual Label LastVersion
    {
      [DebuggerNonUserCode] get
      {
        return this._LastVersion;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._LastVersion = value;
      }
    }

    internal virtual PictureBox PictureBox3
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox3;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox3 = value;
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

    internal virtual Label Version
    {
      [DebuggerNonUserCode] get
      {
        return this._Version;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Version = value;
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

    internal virtual PictureBox PictureBox1
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox1 = value;
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
        EventHandler eventHandler = new EventHandler(this.method_1);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_3);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_2);
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

    internal virtual PictureBox PictureBox4
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox4;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox4 = value;
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
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_5);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_4);
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

    internal virtual Timer UPDT
    {
      [DebuggerNonUserCode] get
      {
        return this.timer_0;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.UPDT_Tick);
        if (this.timer_0 != null)
          this.timer_0.Tick -= eventHandler;
        this.timer_0 = value;
        if (this.timer_0 == null)
          return;
        this.timer_0.Tick += eventHandler;
      }
    }

    internal virtual WebBrowser InfoMakerWEB
    {
      [DebuggerNonUserCode] get
      {
        return this._InfoMakerWEB;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._InfoMakerWEB = value;
      }
    }

    internal virtual PictureBox LinkMirror
    {
      [DebuggerNonUserCode] get
      {
        return this._LinkMirror;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.LinkMirror_Click);
        if (this._LinkMirror != null)
          this._LinkMirror.Click -= eventHandler;
        this._LinkMirror = value;
        if (this._LinkMirror == null)
          return;
        this._LinkMirror.Click += eventHandler;
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

    public static UpDateMaker DefInstance
    {
      get
      {
        if (UpDateMaker.upDateMaker_0 != null && !UpDateMaker.upDateMaker_0.IsDisposed)
          UpDateMaker.upDateMaker_0.BringToFront();
        else
          UpDateMaker.upDateMaker_0 = new UpDateMaker();
        return UpDateMaker.upDateMaker_0;
      }
      set
      {
        UpDateMaker.upDateMaker_0 = value;
      }
    }

    [DebuggerNonUserCode]
    public UpDateMaker()
    {
      this.Load += new EventHandler(this.UpDateMaker_Load);
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
      this.Label3 = new Label();
      this.Label2 = new Label();
      this.LastVersion = new Label();
      this.PictureBox3 = new PictureBox();
      this.Label1 = new Label();
      this.Version = new Label();
      this.PictureBox2 = new PictureBox();
      this.PictureBox1 = new PictureBox();
      this.Reload = new Button();
      this.PictureBox4 = new PictureBox();
      this.Cerrar = new Button();
      this.UPDT = new Timer(this.icontainer_0);
      this.InfoMakerWEB = new WebBrowser();
      this.LinkMirror = new PictureBox();
      this.ToolTips = new ToolTip(this.icontainer_0);
      ((ISupportInitialize) this.PictureBox3).BeginInit();
      ((ISupportInitialize) this.PictureBox2).BeginInit();
      ((ISupportInitialize) this.PictureBox1).BeginInit();
      ((ISupportInitialize) this.PictureBox4).BeginInit();
      ((ISupportInitialize) this.LinkMirror).BeginInit();
      this.SuspendLayout();
      this.Label3.BackColor = Color.Black;
      this.Label3.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label3.ForeColor = Color.DarkGoldenrod;
      Label label3_1 = this.Label3;
      Point point1 = new Point(8, 58);
      Point point2 = point1;
      label3_1.Location = point2;
      this.Label3.Name = "Label3";
      Label label3_2 = this.Label3;
      Size size1 = new Size(33, 12);
      Size size2 = size1;
      label3_2.Size = size2;
      this.Label3.TabIndex = 251;
      this.Label3.Text = "You:";
      this.Label3.TextAlign = ContentAlignment.MiddleCenter;
      this.Label2.BackColor = Color.Transparent;
      this.Label2.Font = new Font("Microsoft Sans Serif", 9.75f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label2.ForeColor = Color.DarkOrange;
      Label label2_1 = this.Label2;
      point1 = new Point(13, 37);
      Point point3 = point1;
      label2_1.Location = point3;
      this.Label2.Name = "Label2";
      Label label2_2 = this.Label2;
      size1 = new Size(61, 14);
      Size size3 = size1;
      label2_2.Size = size3;
      this.Label2.TabIndex = 250;
      this.Label2.Text = "Version";
      this.Label2.TextAlign = ContentAlignment.MiddleCenter;
      this.LastVersion.BackColor = Color.Black;
      this.LastVersion.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.LastVersion.ForeColor = Color.DarkGoldenrod;
      Label lastVersion1 = this.LastVersion;
      point1 = new Point(42, 79);
      Point point4 = point1;
      lastVersion1.Location = point4;
      this.LastVersion.Name = "LastVersion";
      Label lastVersion2 = this.LastVersion;
      size1 = new Size(34, 12);
      Size size4 = size1;
      lastVersion2.Size = size4;
      this.LastVersion.TabIndex = 249;
      this.LastVersion.TextAlign = ContentAlignment.MiddleCenter;
      this.PictureBox3.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.PictureBox3.Image = (Image) EmbeddedResources.smethod_80();
      PictureBox pictureBox3_1 = this.PictureBox3;
      point1 = new Point(60, 190);
      Point point5 = point1;
      pictureBox3_1.Location = point5;
      this.PictureBox3.Name = "PictureBox3";
      PictureBox pictureBox3_2 = this.PictureBox3;
      size1 = new Size(12, 19);
      Size size5 = size1;
      pictureBox3_2.Size = size5;
      this.PictureBox3.TabIndex = 244;
      this.PictureBox3.TabStop = false;
      this.Label1.BackColor = Color.Black;
      this.Label1.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label1.ForeColor = Color.DarkGoldenrod;
      Label label1_1 = this.Label1;
      point1 = new Point(6, 79);
      Point point6 = point1;
      label1_1.Location = point6;
      this.Label1.Name = "Label1";
      Label label1_2 = this.Label1;
      size1 = new Size(36, 12);
      Size size6 = size1;
      label1_2.Size = size6;
      this.Label1.TabIndex = 243;
      this.Label1.Text = "New:";
      this.Label1.TextAlign = ContentAlignment.MiddleCenter;
      this.Version.BackColor = Color.Black;
      this.Version.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Version.ForeColor = Color.DarkGoldenrod;
      Label version1 = this.Version;
      point1 = new Point(42, 58);
      Point point7 = point1;
      version1.Location = point7;
      this.Version.Name = "Version";
      Label version2 = this.Version;
      size1 = new Size(34, 12);
      Size size7 = size1;
      version2.Size = size7;
      this.Version.TabIndex = 242;
      this.Version.TextAlign = ContentAlignment.MiddleCenter;
      this.PictureBox2.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.PictureBox2.Image = (Image) EmbeddedResources.smethod_114();
      PictureBox pictureBox2_1 = this.PictureBox2;
      point1 = new Point(3, 53);
      Point point8 = point1;
      pictureBox2_1.Location = point8;
      this.PictureBox2.Name = "PictureBox2";
      PictureBox pictureBox2_2 = this.PictureBox2;
      size1 = new Size(79, 42);
      Size size8 = size1;
      pictureBox2_2.Size = size8;
      this.PictureBox2.TabIndex = 241;
      this.PictureBox2.TabStop = false;
      this.PictureBox1.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.PictureBox1.Image = (Image) EmbeddedResources.smethod_58();
      PictureBox pictureBox1_1 = this.PictureBox1;
      point1 = new Point(15, 126);
      Point point9 = point1;
      pictureBox1_1.Location = point9;
      this.PictureBox1.Name = "PictureBox1";
      PictureBox pictureBox1_2 = this.PictureBox1;
      size1 = new Size(60, 84);
      Size size9 = size1;
      pictureBox1_2.Size = size9;
      this.PictureBox1.TabIndex = 240;
      this.PictureBox1.TabStop = false;
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
      point1 = new Point(2, 95);
      Point point10 = point1;
      reload1.Location = point10;
      this.Reload.Name = "Reload";
      Button reload2 = this.Reload;
      size1 = new Size(40, 31);
      Size size10 = size1;
      reload2.Size = size10;
      this.Reload.TabIndex = 484;
      this.Reload.TabStop = false;
      this.ToolTips.SetToolTip((Control) this.Reload, "ReLoad");
      this.Reload.UseVisualStyleBackColor = false;
      this.PictureBox4.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.PictureBox4.Image = (Image) EmbeddedResources.smethod_80();
      PictureBox pictureBox4_1 = this.PictureBox4;
      point1 = new Point(9, 182);
      Point point11 = point1;
      pictureBox4_1.Location = point11;
      this.PictureBox4.Name = "PictureBox4";
      PictureBox pictureBox4_2 = this.PictureBox4;
      size1 = new Size(12, 19);
      Size size11 = size1;
      pictureBox4_2.Size = size11;
      this.PictureBox4.TabIndex = 485;
      this.PictureBox4.TabStop = false;
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
      point1 = new Point(249, 6);
      Point point12 = point1;
      cerrar1.Location = point12;
      this.Cerrar.Name = "Cerrar";
      Button cerrar2 = this.Cerrar;
      size1 = new Size(13, 13);
      Size size12 = size1;
      cerrar2.Size = size12;
      this.Cerrar.TabIndex = 486;
      this.Cerrar.TabStop = false;
      this.Cerrar.UseVisualStyleBackColor = false;
      this.UPDT.Enabled = true;
      this.UPDT.Interval = 10000;
      WebBrowser infoMakerWeb1 = this.InfoMakerWEB;
      point1 = new Point(83, 35);
      Point point13 = point1;
      infoMakerWeb1.Location = point13;
      WebBrowser infoMakerWeb2 = this.InfoMakerWEB;
      size1 = new Size(20, 20);
      Size size13 = size1;
      infoMakerWeb2.MinimumSize = size13;
      this.InfoMakerWEB.Name = "InfoMakerWEB";
      WebBrowser infoMakerWeb3 = this.InfoMakerWEB;
      size1 = new Size(184, 174);
      Size size14 = size1;
      infoMakerWeb3.Size = size14;
      this.InfoMakerWEB.TabIndex = 487;
      this.InfoMakerWEB.Url = new Uri("http://softwaretmt.sytes.net/mumaker/clientes/newsmmk.php", UriKind.Absolute);
      this.LinkMirror.BackColor = Color.Transparent;
      this.LinkMirror.Cursor = Cursors.Hand;
      // ISSUE: reference to a compiler-generated method
      this.LinkMirror.Image = (Image) EmbeddedResources.smethod_56();
      PictureBox linkMirror1 = this.LinkMirror;
      point1 = new Point(48, 96);
      Point point14 = point1;
      linkMirror1.Location = point14;
      this.LinkMirror.Name = "LinkMirror";
      PictureBox linkMirror2 = this.LinkMirror;
      size1 = new Size(32, 32);
      Size size15 = size1;
      linkMirror2.Size = size15;
      this.LinkMirror.SizeMode = PictureBoxSizeMode.StretchImage;
      this.LinkMirror.TabIndex = 488;
      this.LinkMirror.TabStop = false;
      this.ToolTips.SetToolTip((Control) this.LinkMirror, "DownLoad");
      this.AutoScaleMode = AutoScaleMode.Inherit;
      this.BackColor = Color.Black;
      // ISSUE: reference to a compiler-generated method
      this.BackgroundImage = (Image) EmbeddedResources.smethod_111();
      this.CancelButton = (IButtonControl) this.Cerrar;
      size1 = new Size(268, 211);
      this.ClientSize = size1;
      this.Controls.Add((Control) this.LinkMirror);
      this.Controls.Add((Control) this.Label1);
      this.Controls.Add((Control) this.PictureBox4);
      this.Controls.Add((Control) this.InfoMakerWEB);
      this.Controls.Add((Control) this.Reload);
      this.Controls.Add((Control) this.Cerrar);
      this.Controls.Add((Control) this.Label3);
      this.Controls.Add((Control) this.Label2);
      this.Controls.Add((Control) this.LastVersion);
      this.Controls.Add((Control) this.PictureBox3);
      this.Controls.Add((Control) this.Version);
      this.Controls.Add((Control) this.PictureBox2);
      this.Controls.Add((Control) this.PictureBox1);
      this.FormBorderStyle = FormBorderStyle.None;
      this.MaximizeBox = false;
      this.MinimizeBox = false;
      size1 = new Size(268, 211);
      this.MinimumSize = size1;
      this.Name = "UpDateMaker";
      this.ShowInTaskbar = false;
      this.StartPosition = FormStartPosition.CenterScreen;
      this.Text = "UpDateMaker";
      this.TransparencyKey = Color.Red;
      ((ISupportInitialize) this.PictureBox3).EndInit();
      ((ISupportInitialize) this.PictureBox2).EndInit();
      ((ISupportInitialize) this.PictureBox1).EndInit();
      ((ISupportInitialize) this.PictureBox4).EndInit();
      ((ISupportInitialize) this.LinkMirror).EndInit();
      this.ResumeLayout(false);
    }

    private void UpDateMaker_Load(object sender, EventArgs e)
    {
      this.Version.Text = Configuration.string_0;
      Configuration.object_0 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/UPDT.INI", "Info", "Version", Configuration.string_0);
      this.LastVersion.Text = Conversions.ToString(Configuration.object_0);
      this.LinkMirror.Focus();
    }

    private void method_0(object sender, EventArgs e)
    {
      this.Close();
      this.LinkMirror.Focus();
    }

    private void method_1(object sender, EventArgs e)
    {
      this.InfoMakerWEB.Navigate(new Uri("http://softwaretmt.sytes.net/mumaker/clientes/newsmmk.php"));
      IniHelper.smethod_21();
      Configuration.object_0 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/UPDT.INI", "Info", "Version", Configuration.string_0);
      this.LastVersion.Text = Conversions.ToString(Configuration.object_0);
      this.LinkMirror.Focus();
    }

    private void LinkMirror_Click(object sender, EventArgs e)
    {
      Process.Start("http://softwaretmt.sytes.net/mumaker/index.php?modulo=descargas");
    }

    private void method_2(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Reload.BackgroundImage = (Image) EmbeddedResources.smethod_100();
      this.LinkMirror.Focus();
    }

    private void method_3(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Reload.BackgroundImage = (Image) EmbeddedResources.smethod_101();
    }

    private void method_4(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) EmbeddedResources.smethod_39();
      this.LinkMirror.Focus();
    }

    private void method_5(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) EmbeddedResources.smethod_40();
    }

    private void UPDT_Tick(object sender, EventArgs e)
    {
      this.LastVersion.Text = Conversions.ToString(Configuration.object_0);
    }
  }
}
