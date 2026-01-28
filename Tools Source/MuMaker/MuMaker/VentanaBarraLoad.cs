// Decompiled with JetBrains decompiler
// Type: MuMaker.VentanaBarraLoad
// Assembly: MuMaker, Version=1.1.3.0, Culture=neutral, PublicKeyToken=null
// MVID: 7E43A6C6-04AF-4159-BD3A-BD25660D1460
// Assembly location: D:\MuServer\Tools\MuMaker 1.13\MuMaker-cleaned.exe

using Microsoft.VisualBasic.CompilerServices;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

namespace MuMaker
{
  [DesignerGenerated]
  public class VentanaBarraLoad : Form
  {
    private static VentanaBarraLoad ventanaBarraLoad_0 = (VentanaBarraLoad) null;
    private IContainer icontainer_0;
    [AccessedThroughProperty("Carga")]
    private ProgressBar _Carga;

    internal virtual ProgressBar Carga
    {
      [DebuggerNonUserCode] get
      {
        return this._Carga;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Carga = value;
      }
    }

    public static VentanaBarraLoad DefInstance
    {
      get
      {
        if (VentanaBarraLoad.ventanaBarraLoad_0 != null && !VentanaBarraLoad.ventanaBarraLoad_0.IsDisposed)
          VentanaBarraLoad.ventanaBarraLoad_0.BringToFront();
        else
          VentanaBarraLoad.ventanaBarraLoad_0 = new VentanaBarraLoad();
        return VentanaBarraLoad.ventanaBarraLoad_0;
      }
      set
      {
        VentanaBarraLoad.ventanaBarraLoad_0 = value;
      }
    }

    [DebuggerNonUserCode]
    public VentanaBarraLoad()
    {
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
      ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof (VentanaBarraLoad));
      this.Carga = new ProgressBar();
      this.SuspendLayout();
      this.Carga.BackColor = SystemColors.ControlDarkDark;
      this.Carga.ForeColor = Color.DarkOrange;
      this.Carga.Location = new Point(37, 52);
      this.Carga.Margin = new Padding(0);
      this.Carga.Name = "Carga";
      ProgressBar carga = this.Carga;
      Size size1 = new Size(335, 10);
      Size size2 = size1;
      carga.Size = size2;
      this.Carga.Step = 1;
      this.Carga.Style = ProgressBarStyle.Marquee;
      this.Carga.TabIndex = 2;
      this.AutoScaleMode = AutoScaleMode.Inherit;
      // ISSUE: reference to a compiler-generated method
      this.BackgroundImage = (Image) EmbeddedResources.smethod_8();
      size1 = new Size(409, 86);
      this.ClientSize = size1;
      this.Controls.Add((Control) this.Carga);
      this.Cursor = Cursors.Hand;
      this.FormBorderStyle = FormBorderStyle.None;
      this.Icon = (Icon) componentResourceManager.GetObject("$this.Icon");
      this.MaximizeBox = false;
      size1 = new Size(409, 86);
      this.MaximumSize = size1;
      this.MinimizeBox = false;
      size1 = new Size(409, 86);
      this.MinimumSize = size1;
      this.Name = "VentanaBarraLoad";
      this.ShowInTaskbar = false;
      this.StartPosition = FormStartPosition.CenterScreen;
      this.Text = "VentanaBarraLoad";
      this.TopMost = true;
      this.TransparencyKey = Color.Red;
      this.ResumeLayout(false);
    }
  }
}
