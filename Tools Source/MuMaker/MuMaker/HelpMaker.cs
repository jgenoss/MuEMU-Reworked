// Decompiled with JetBrains decompiler
// Type: MuMaker.HelpMaker
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
  public class HelpMaker : Form
  {
    private static HelpMaker helpMaker_0 = (HelpMaker) null;
    private IContainer icontainer_0;
    [AccessedThroughProperty("WebHelpBrowser")]
    private WebBrowser _WebHelpBrowser;
    [AccessedThroughProperty("Cerrar")]
    private Button _Cerrar;
    [AccessedThroughProperty("Minimizar")]
    private Button _Minimizar;
    [AccessedThroughProperty("Titulo")]
    private Label _Titulo;
    private const int int_0 = 132;
    private const int int_1 = 1;
    private const int int_2 = 2;

    internal virtual WebBrowser WebHelpBrowser
    {
      [DebuggerNonUserCode] get
      {
        return this._WebHelpBrowser;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._WebHelpBrowser = value;
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
        EventHandler eventHandler = new EventHandler(this.method_1);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_4);
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

    internal virtual Button Minimizar
    {
      [DebuggerNonUserCode] get
      {
        return this._Minimizar;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_0);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_3);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_2);
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

    public static HelpMaker DefInstance
    {
      get
      {
        if (HelpMaker.helpMaker_0 != null && !HelpMaker.helpMaker_0.IsDisposed)
          HelpMaker.helpMaker_0.BringToFront();
        else
          HelpMaker.helpMaker_0 = new HelpMaker();
        return HelpMaker.helpMaker_0;
      }
      set
      {
        HelpMaker.helpMaker_0 = value;
      }
    }

    [DebuggerNonUserCode]
    public HelpMaker()
    {
      this.Load += new EventHandler(this.HelpMaker_Load);
      this.InitializeComponent();
    }

    [DebuggerNonUserCode]
    protected override void Dispose(bool disposing)
    {
      try
      {
        if (!disposing || this.icontainer_0 == null)
          return;
        this.icontainer_0.Dispose();
      }
      finally
      {
        base.Dispose(disposing);
      }
    }

    [DebuggerStepThrough]
    private void InitializeComponent()
    {
      ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof (HelpMaker));
      this.WebHelpBrowser = new WebBrowser();
      this.Cerrar = new Button();
      this.Minimizar = new Button();
      this.Titulo = new Label();
      this.SuspendLayout();
      WebBrowser webHelpBrowser1 = this.WebHelpBrowser;
      Point point1 = new Point(25, 27);
      Point point2 = point1;
      webHelpBrowser1.Location = point2;
      WebBrowser webHelpBrowser2 = this.WebHelpBrowser;
      Size size1 = new Size(850, 648);
      Size size2 = size1;
      webHelpBrowser2.MaximumSize = size2;
      WebBrowser webHelpBrowser3 = this.WebHelpBrowser;
      size1 = new Size(850, 648);
      Size size3 = size1;
      webHelpBrowser3.MinimumSize = size3;
      this.WebHelpBrowser.Name = "WebHelpBrowser";
      WebBrowser webHelpBrowser4 = this.WebHelpBrowser;
      size1 = new Size(850, 648);
      Size size4 = size1;
      webHelpBrowser4.Size = size4;
      this.WebHelpBrowser.TabIndex = 0;
      this.WebHelpBrowser.Url = new Uri("", UriKind.Relative);
      this.WebHelpBrowser.WebBrowserShortcutsEnabled = false;
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
      point1 = new Point(879, 6);
      Point point3 = point1;
      cerrar1.Location = point3;
      this.Cerrar.Name = "Cerrar";
      Button cerrar2 = this.Cerrar;
      size1 = new Size(13, 13);
      Size size5 = size1;
      cerrar2.Size = size5;
      this.Cerrar.TabIndex = 1894;
      this.Cerrar.TabStop = false;
      this.Cerrar.UseVisualStyleBackColor = false;
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
      point1 = new Point(8, 6);
      Point point4 = point1;
      minimizar1.Location = point4;
      this.Minimizar.Name = "Minimizar";
      Button minimizar2 = this.Minimizar;
      size1 = new Size(13, 13);
      Size size6 = size1;
      minimizar2.Size = size6;
      this.Minimizar.TabIndex = 1893;
      this.Minimizar.TabStop = false;
      this.Minimizar.UseVisualStyleBackColor = false;
      this.Titulo.AutoSize = true;
      this.Titulo.BackColor = Color.Transparent;
      this.Titulo.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Titulo.ForeColor = Color.DarkOrange;
      Label titulo1 = this.Titulo;
      point1 = new Point(60, 5);
      Point point5 = point1;
      titulo1.Location = point5;
      this.Titulo.Name = "Titulo";
      Label titulo2 = this.Titulo;
      size1 = new Size(0, 13);
      Size size7 = size1;
      titulo2.Size = size7;
      this.Titulo.TabIndex = 1895;
      this.Titulo.TextAlign = ContentAlignment.MiddleLeft;
      this.AutoScaleDimensions = new SizeF(7f, 13f);
      this.AutoScaleMode = AutoScaleMode.Font;
      // ISSUE: reference to a compiler-generated method
      this.BackgroundImage = (Image) EmbeddedResources.smethod_69();
      size1 = new Size(900, 700);
      this.ClientSize = size1;
      this.Controls.Add((Control) this.Titulo);
      this.Controls.Add((Control) this.Cerrar);
      this.Controls.Add((Control) this.Minimizar);
      this.Controls.Add((Control) this.WebHelpBrowser);
      this.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.FormBorderStyle = FormBorderStyle.None;
      this.Icon = (Icon) componentResourceManager.GetObject("$this.Icon");
      this.MaximizeBox = false;
      size1 = new Size(900, 700);
      this.MaximumSize = size1;
      this.MinimizeBox = false;
      size1 = new Size(900, 700);
      this.MinimumSize = size1;
      this.Name = "HelpMaker";
      this.StartPosition = FormStartPosition.CenterScreen;
      this.Text = "HelpMaker";
      this.TransparencyKey = Color.Fuchsia;
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

    public object Traducir()
    {
      this.Text = Conversions.ToString(Operators.ConcatenateObject((object) (this.Text + " - "), Configuration.object_18));
      this.Titulo.Text = this.Text;
      return (object) true;
    }

    private void HelpMaker_Load(object sender, EventArgs e)
    {
      this.Traducir();
      this.WebHelpBrowser.Navigate(new Uri(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "\\Help\\index.html"));
    }

    private void method_0(object sender, EventArgs e)
    {
      HelpMaker.DefInstance.WindowState = FormWindowState.Minimized;
    }

    private void method_1(object sender, EventArgs e)
    {
      this.Close();
    }

    private void method_2(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Minimizar.BackgroundImage = (Image) EmbeddedResources.smethod_86();
    }

    private void method_3(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Minimizar.BackgroundImage = (Image) EmbeddedResources.smethod_87();
    }

    private void method_4(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) EmbeddedResources.smethod_39();
    }

    private void method_5(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) EmbeddedResources.smethod_40();
    }
  }
}
