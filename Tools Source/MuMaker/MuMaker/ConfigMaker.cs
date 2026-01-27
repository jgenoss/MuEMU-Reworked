// Decompiled with JetBrains decompiler
// Type: MuMaker.ConfigMaker
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
  public class ConfigMaker : Form
  {
    private static ConfigMaker configMaker_0 = (ConfigMaker) null;
    private IContainer icontainer_0;
    [AccessedThroughProperty("PictureBox8")]
    private PictureBox _PictureBox8;
    [AccessedThroughProperty("MuEvent")]
    private TextBox _MuEvent;
    [AccessedThroughProperty("Label16")]
    private Label _Label16;
    [AccessedThroughProperty("MuRanking")]
    private TextBox _MuRanking;
    [AccessedThroughProperty("PassWord")]
    private TextBox _PassWord;
    [AccessedThroughProperty("Usuario")]
    private TextBox _Usuario;
    [AccessedThroughProperty("LocalRemote")]
    private RadioButton _LocalRemote;
    [AccessedThroughProperty("LocalHost")]
    private RadioButton _LocalHost;
    [AccessedThroughProperty("Label12")]
    private Label _Label12;
    [AccessedThroughProperty("Puerto")]
    private TextBox _Puerto;
    [AccessedThroughProperty("MuOnline")]
    private TextBox _MuOnline;
    [AccessedThroughProperty("Label4")]
    private Label _Label4;
    [AccessedThroughProperty("IPServer")]
    private TextBox _IPServer;
    [AccessedThroughProperty("ExtWareHouse")]
    private TextBox _ExtWareHouse;
    [AccessedThroughProperty("Label1")]
    private Label _Label1;
    [AccessedThroughProperty("NuExtraWareHouses")]
    private TextBox _NuExtraWareHouses;
    [AccessedThroughProperty("Label10")]
    private Label _Label10;
    [AccessedThroughProperty("Label7")]
    private Label _Label7;
    [AccessedThroughProperty("ExtraWareHouse")]
    private CheckBox _ExtraWareHouse;
    [AccessedThroughProperty("Label5")]
    private Label _Label5;
    [AccessedThroughProperty("Label14")]
    private Label _Label14;
    [AccessedThroughProperty("Label15")]
    private Label _Label15;
    [AccessedThroughProperty("PictureBox7")]
    private PictureBox _PictureBox7;
    [AccessedThroughProperty("PictureBox10")]
    private PictureBox _PictureBox10;
    [AccessedThroughProperty("PictureBox9")]
    private PictureBox _PictureBox9;
    [AccessedThroughProperty("PictureBox6")]
    private PictureBox _PictureBox6;
    [AccessedThroughProperty("PictureBox4")]
    private PictureBox _PictureBox4;
    [AccessedThroughProperty("PictureBox3")]
    private PictureBox _PictureBox3;
    [AccessedThroughProperty("Idiomas")]
    private ComboBox _Idiomas;
    [AccessedThroughProperty("PictureBox2")]
    private PictureBox _PictureBox2;
    [AccessedThroughProperty("PictureBox1")]
    private PictureBox _PictureBox1;
    [AccessedThroughProperty("PictureBox5")]
    private PictureBox _PictureBox5;
    [AccessedThroughProperty("Cancelar")]
    private Button _Cancelar;
    [AccessedThroughProperty("ToolTips")]
    private ToolTip toolTip_0;
    [AccessedThroughProperty("Aceptar")]
    private Button _Aceptar;
    [AccessedThroughProperty("MMKNM")]
    private TextBox _MMKNM;
    [AccessedThroughProperty("ColumReset")]
    private TextBox _ColumReset;
    [AccessedThroughProperty("ResetSystem")]
    private CheckBox _ResetSystem;
    [AccessedThroughProperty("CHMD5")]
    private CheckBox _CHMD5;
    [AccessedThroughProperty("PictureBox12")]
    private PictureBox _PictureBox12;
    [AccessedThroughProperty("PictureBox11")]
    private PictureBox _PictureBox11;
    [AccessedThroughProperty("CreateReset")]
    private Button _CreateReset;
    [AccessedThroughProperty("Label2")]
    private Label _Label2;
    [AccessedThroughProperty("Label3")]
    private Label _Label3;
    [AccessedThroughProperty("ReUsPw")]
    private CheckBox _ReUsPw;
    [AccessedThroughProperty("Cerrar")]
    private Button _Cerrar;
    [AccessedThroughProperty("TimeLimit")]
    private TextBox _TimeLimit;
    [AccessedThroughProperty("Label8")]
    private Label _Label8;
    [AccessedThroughProperty("CleanProcedures")]
    private Button _CleanProcedures;
    [AccessedThroughProperty("Label6")]
    private Label _Label6;
    [AccessedThroughProperty("AutoLoad")]
    private CheckBox _AutoLoad;
    [AccessedThroughProperty("AutoReLoad")]
    private CheckBox _AutoReLoad;
    private const int int_0 = 132;
    private const int int_1 = 1;
    private const int int_2 = 2;

    internal virtual PictureBox PictureBox8
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox8;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.PictureBox8_Click);
        if (this._PictureBox8 != null)
          this._PictureBox8.Click -= eventHandler;
        this._PictureBox8 = value;
        if (this._PictureBox8 == null)
          return;
        this._PictureBox8.Click += eventHandler;
      }
    }

    internal virtual TextBox MuEvent
    {
      [DebuggerNonUserCode] get
      {
        return this._MuEvent;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MuEvent_LostFocus);
        if (this._MuEvent != null)
          this._MuEvent.LostFocus -= eventHandler;
        this._MuEvent = value;
        if (this._MuEvent == null)
          return;
        this._MuEvent.LostFocus += eventHandler;
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

    internal virtual TextBox MuRanking
    {
      [DebuggerNonUserCode] get
      {
        return this._MuRanking;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MuRanking_LostFocus);
        if (this._MuRanking != null)
          this._MuRanking.LostFocus -= eventHandler;
        this._MuRanking = value;
        if (this._MuRanking == null)
          return;
        this._MuRanking.LostFocus += eventHandler;
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

    internal virtual TextBox Usuario
    {
      [DebuggerNonUserCode] get
      {
        return this._Usuario;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Usuario_LostFocus);
        if (this._Usuario != null)
          this._Usuario.LostFocus -= eventHandler;
        this._Usuario = value;
        if (this._Usuario == null)
          return;
        this._Usuario.LostFocus += eventHandler;
      }
    }

    internal virtual RadioButton LocalRemote
    {
      [DebuggerNonUserCode] get
      {
        return this._LocalRemote;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.LocalRemote_CheckedChanged);
        if (this._LocalRemote != null)
          this._LocalRemote.CheckedChanged -= eventHandler;
        this._LocalRemote = value;
        if (this._LocalRemote == null)
          return;
        this._LocalRemote.CheckedChanged += eventHandler;
      }
    }

    internal virtual RadioButton LocalHost
    {
      [DebuggerNonUserCode] get
      {
        return this._LocalHost;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.LocalHost_CheckedChanged);
        if (this._LocalHost != null)
          this._LocalHost.CheckedChanged -= eventHandler;
        this._LocalHost = value;
        if (this._LocalHost == null)
          return;
        this._LocalHost.CheckedChanged += eventHandler;
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

    internal virtual TextBox Puerto
    {
      [DebuggerNonUserCode] get
      {
        return this._Puerto;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Puerto_LostFocus);
        if (this._Puerto != null)
          this._Puerto.LostFocus -= eventHandler;
        this._Puerto = value;
        if (this._Puerto == null)
          return;
        this._Puerto.LostFocus += eventHandler;
      }
    }

    internal virtual TextBox MuOnline
    {
      [DebuggerNonUserCode] get
      {
        return this._MuOnline;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MuOnline_LostFocus);
        if (this._MuOnline != null)
          this._MuOnline.LostFocus -= eventHandler;
        this._MuOnline = value;
        if (this._MuOnline == null)
          return;
        this._MuOnline.LostFocus += eventHandler;
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

    internal virtual TextBox IPServer
    {
      [DebuggerNonUserCode] get
      {
        return this._IPServer;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.IPServer_LostFocus);
        if (this._IPServer != null)
          this._IPServer.LostFocus -= eventHandler;
        this._IPServer = value;
        if (this._IPServer == null)
          return;
        this._IPServer.LostFocus += eventHandler;
      }
    }

    internal virtual TextBox ExtWareHouse
    {
      [DebuggerNonUserCode] get
      {
        return this._ExtWareHouse;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.ExtWareHouse_LostFocus);
        if (this._ExtWareHouse != null)
          this._ExtWareHouse.LostFocus -= eventHandler;
        this._ExtWareHouse = value;
        if (this._ExtWareHouse == null)
          return;
        this._ExtWareHouse.LostFocus += eventHandler;
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

    internal virtual TextBox NuExtraWareHouses
    {
      [DebuggerNonUserCode] get
      {
        return this._NuExtraWareHouses;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_6);
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.method_3);
        if (this._NuExtraWareHouses != null)
        {
          this._NuExtraWareHouses.LostFocus -= eventHandler;
          this._NuExtraWareHouses.KeyPress -= pressEventHandler;
        }
        this._NuExtraWareHouses = value;
        if (this._NuExtraWareHouses == null)
          return;
        this._NuExtraWareHouses.LostFocus += eventHandler;
        this._NuExtraWareHouses.KeyPress += pressEventHandler;
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

    internal virtual CheckBox ExtraWareHouse
    {
      [DebuggerNonUserCode] get
      {
        return this._ExtraWareHouse;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.ExtraWareHouse_CheckedChanged);
        if (this._ExtraWareHouse != null)
          this._ExtraWareHouse.CheckedChanged -= eventHandler;
        this._ExtraWareHouse = value;
        if (this._ExtraWareHouse == null)
          return;
        this._ExtraWareHouse.CheckedChanged += eventHandler;
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

    internal virtual PictureBox PictureBox7
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox7;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.PictureBox7_Click);
        if (this._PictureBox7 != null)
          this._PictureBox7.Click -= eventHandler;
        this._PictureBox7 = value;
        if (this._PictureBox7 == null)
          return;
        this._PictureBox7.Click += eventHandler;
      }
    }

    internal virtual PictureBox PictureBox10
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox10;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.PictureBox10_Click);
        if (this._PictureBox10 != null)
          this._PictureBox10.Click -= eventHandler;
        this._PictureBox10 = value;
        if (this._PictureBox10 == null)
          return;
        this._PictureBox10.Click += eventHandler;
      }
    }

    internal virtual PictureBox PictureBox9
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox9;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.PictureBox9_Click);
        if (this._PictureBox9 != null)
          this._PictureBox9.Click -= eventHandler;
        this._PictureBox9 = value;
        if (this._PictureBox9 == null)
          return;
        this._PictureBox9.Click += eventHandler;
      }
    }

    internal virtual PictureBox PictureBox6
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox6;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.PictureBox6_Click);
        if (this._PictureBox6 != null)
          this._PictureBox6.Click -= eventHandler;
        this._PictureBox6 = value;
        if (this._PictureBox6 == null)
          return;
        this._PictureBox6.Click += eventHandler;
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
        EventHandler eventHandler = new EventHandler(this.PictureBox4_Click);
        if (this._PictureBox4 != null)
          this._PictureBox4.Click -= eventHandler;
        this._PictureBox4 = value;
        if (this._PictureBox4 == null)
          return;
        this._PictureBox4.Click += eventHandler;
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
        EventHandler eventHandler = new EventHandler(this.PictureBox3_Click);
        if (this._PictureBox3 != null)
          this._PictureBox3.Click -= eventHandler;
        this._PictureBox3 = value;
        if (this._PictureBox3 == null)
          return;
        this._PictureBox3.Click += eventHandler;
      }
    }

    internal virtual ComboBox Idiomas
    {
      [DebuggerNonUserCode] get
      {
        return this._Idiomas;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Idiomas = value;
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
        EventHandler eventHandler = new EventHandler(this.PictureBox2_Click);
        if (this._PictureBox2 != null)
          this._PictureBox2.Click -= eventHandler;
        this._PictureBox2 = value;
        if (this._PictureBox2 == null)
          return;
        this._PictureBox2.Click += eventHandler;
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
        EventHandler eventHandler = new EventHandler(this.PictureBox1_Click);
        if (this._PictureBox1 != null)
          this._PictureBox1.Click -= eventHandler;
        this._PictureBox1 = value;
        if (this._PictureBox1 == null)
          return;
        this._PictureBox1.Click += eventHandler;
      }
    }

    internal virtual PictureBox PictureBox5
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox5;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.PictureBox5_Click);
        if (this._PictureBox5 != null)
          this._PictureBox5.Click -= eventHandler;
        this._PictureBox5 = value;
        if (this._PictureBox5 == null)
          return;
        this._PictureBox5.Click += eventHandler;
      }
    }

    internal virtual Button Cancelar
    {
      [DebuggerNonUserCode] get
      {
        return this._Cancelar;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_1);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_12);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_11);
        if (this._Cancelar != null)
        {
          this._Cancelar.Click -= eventHandler;
          this._Cancelar.MouseDown -= mouseEventHandler1;
          this._Cancelar.MouseUp -= mouseEventHandler2;
        }
        this._Cancelar = value;
        if (this._Cancelar == null)
          return;
        this._Cancelar.Click += eventHandler;
        this._Cancelar.MouseDown += mouseEventHandler1;
        this._Cancelar.MouseUp += mouseEventHandler2;
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

    internal virtual Button Aceptar
    {
      [DebuggerNonUserCode] get
      {
        return this._Aceptar;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_0);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_10);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_9);
        if (this._Aceptar != null)
        {
          this._Aceptar.Click -= eventHandler;
          this._Aceptar.MouseDown -= mouseEventHandler1;
          this._Aceptar.MouseUp -= mouseEventHandler2;
        }
        this._Aceptar = value;
        if (this._Aceptar == null)
          return;
        this._Aceptar.Click += eventHandler;
        this._Aceptar.MouseDown += mouseEventHandler1;
        this._Aceptar.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual TextBox MMKNM
    {
      [DebuggerNonUserCode] get
      {
        return this._MMKNM;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MMKNM_LostFocus);
        if (this._MMKNM != null)
          this._MMKNM.LostFocus -= eventHandler;
        this._MMKNM = value;
        if (this._MMKNM == null)
          return;
        this._MMKNM.LostFocus += eventHandler;
      }
    }

    internal virtual TextBox ColumReset
    {
      [DebuggerNonUserCode] get
      {
        return this._ColumReset;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.ColumReset_LostFocus);
        if (this._ColumReset != null)
          this._ColumReset.LostFocus -= eventHandler;
        this._ColumReset = value;
        if (this._ColumReset == null)
          return;
        this._ColumReset.LostFocus += eventHandler;
      }
    }

    internal virtual CheckBox ResetSystem
    {
      [DebuggerNonUserCode] get
      {
        return this._ResetSystem;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.ResetSystem_CheckedChanged);
        if (this._ResetSystem != null)
          this._ResetSystem.CheckedChanged -= eventHandler;
        this._ResetSystem = value;
        if (this._ResetSystem == null)
          return;
        this._ResetSystem.CheckedChanged += eventHandler;
      }
    }

    internal virtual CheckBox CHMD5
    {
      [DebuggerNonUserCode] get
      {
        return this._CHMD5;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._CHMD5 = value;
      }
    }

    internal virtual PictureBox PictureBox12
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox12;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.PictureBox12_Click);
        if (this._PictureBox12 != null)
          this._PictureBox12.Click -= eventHandler;
        this._PictureBox12 = value;
        if (this._PictureBox12 == null)
          return;
        this._PictureBox12.Click += eventHandler;
      }
    }

    internal virtual PictureBox PictureBox11
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox11;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.PictureBox11_Click);
        if (this._PictureBox11 != null)
          this._PictureBox11.Click -= eventHandler;
        this._PictureBox11 = value;
        if (this._PictureBox11 == null)
          return;
        this._PictureBox11.Click += eventHandler;
      }
    }

    internal virtual Button CreateReset
    {
      [DebuggerNonUserCode] get
      {
        return this._CreateReset;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_4);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_14);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_13);
        if (this._CreateReset != null)
        {
          this._CreateReset.Click -= eventHandler;
          this._CreateReset.MouseDown -= mouseEventHandler1;
          this._CreateReset.MouseUp -= mouseEventHandler2;
        }
        this._CreateReset = value;
        if (this._CreateReset == null)
          return;
        this._CreateReset.Click += eventHandler;
        this._CreateReset.MouseDown += mouseEventHandler1;
        this._CreateReset.MouseUp += mouseEventHandler2;
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

    internal virtual CheckBox ReUsPw
    {
      [DebuggerNonUserCode] get
      {
        return this._ReUsPw;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.ReUsPw_CheckedChanged);
        if (this._ReUsPw != null)
          this._ReUsPw.CheckedChanged -= eventHandler;
        this._ReUsPw = value;
        if (this._ReUsPw == null)
          return;
        this._ReUsPw.CheckedChanged += eventHandler;
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
        EventHandler eventHandler = new EventHandler(this.method_2);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_18);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_17);
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

    internal virtual TextBox TimeLimit
    {
      [DebuggerNonUserCode] get
      {
        return this._TimeLimit;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.method_8);
        EventHandler eventHandler = new EventHandler(this.method_7);
        if (this._TimeLimit != null)
        {
          this._TimeLimit.KeyPress -= pressEventHandler;
          this._TimeLimit.LostFocus -= eventHandler;
        }
        this._TimeLimit = value;
        if (this._TimeLimit == null)
          return;
        this._TimeLimit.KeyPress += pressEventHandler;
        this._TimeLimit.LostFocus += eventHandler;
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

    internal virtual Button CleanProcedures
    {
      [DebuggerNonUserCode] get
      {
        return this._CleanProcedures;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_5);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_16);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_15);
        if (this._CleanProcedures != null)
        {
          this._CleanProcedures.Click -= eventHandler;
          this._CleanProcedures.MouseDown -= mouseEventHandler1;
          this._CleanProcedures.MouseUp -= mouseEventHandler2;
        }
        this._CleanProcedures = value;
        if (this._CleanProcedures == null)
          return;
        this._CleanProcedures.Click += eventHandler;
        this._CleanProcedures.MouseDown += mouseEventHandler1;
        this._CleanProcedures.MouseUp += mouseEventHandler2;
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

    internal virtual CheckBox AutoLoad
    {
      [DebuggerNonUserCode] get
      {
        return this._AutoLoad;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.AutoLoad_CheckedChanged);
        if (this._AutoLoad != null)
          this._AutoLoad.CheckedChanged -= eventHandler;
        this._AutoLoad = value;
        if (this._AutoLoad == null)
          return;
        this._AutoLoad.CheckedChanged += eventHandler;
      }
    }

    internal virtual CheckBox AutoReLoad
    {
      [DebuggerNonUserCode] get
      {
        return this._AutoReLoad;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.AutoReLoad_CheckedChanged);
        if (this._AutoReLoad != null)
          this._AutoReLoad.CheckedChanged -= eventHandler;
        this._AutoReLoad = value;
        if (this._AutoReLoad == null)
          return;
        this._AutoReLoad.CheckedChanged += eventHandler;
      }
    }

    public static ConfigMaker DefInstance
    {
      get
      {
        if (ConfigMaker.configMaker_0 != null && !ConfigMaker.configMaker_0.IsDisposed)
          ConfigMaker.configMaker_0.BringToFront();
        else
          ConfigMaker.configMaker_0 = new ConfigMaker();
        return ConfigMaker.configMaker_0;
      }
      set
      {
        ConfigMaker.configMaker_0 = value;
      }
    }

    [DebuggerNonUserCode]
    public ConfigMaker()
    {
      this.Load += new EventHandler(this.ConfigMaker_Load);
      this.Closing += new CancelEventHandler(this.ConfigMaker_Closing);
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
      ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof (ConfigMaker));
      this.PassWord = new TextBox();
      this.Usuario = new TextBox();
      this.LocalRemote = new RadioButton();
      this.LocalHost = new RadioButton();
      this.Label12 = new Label();
      this.Puerto = new TextBox();
      this.Label4 = new Label();
      this.IPServer = new TextBox();
      this.Label1 = new Label();
      this.Label10 = new Label();
      this.Label5 = new Label();
      this.CHMD5 = new CheckBox();
      this.ColumReset = new TextBox();
      this.ResetSystem = new CheckBox();
      this.MuEvent = new TextBox();
      this.Label16 = new Label();
      this.MuRanking = new TextBox();
      this.MuOnline = new TextBox();
      this.ExtWareHouse = new TextBox();
      this.NuExtraWareHouses = new TextBox();
      this.Label7 = new Label();
      this.ExtraWareHouse = new CheckBox();
      this.Label14 = new Label();
      this.Label15 = new Label();
      this.Idiomas = new ComboBox();
      this.ToolTips = new ToolTip(this.icontainer_0);
      this.CreateReset = new Button();
      this.Aceptar = new Button();
      this.AutoLoad = new CheckBox();
      this.AutoReLoad = new CheckBox();
      this.MMKNM = new TextBox();
      this.PictureBox12 = new PictureBox();
      this.PictureBox11 = new PictureBox();
      this.PictureBox8 = new PictureBox();
      this.PictureBox7 = new PictureBox();
      this.PictureBox10 = new PictureBox();
      this.PictureBox9 = new PictureBox();
      this.PictureBox6 = new PictureBox();
      this.PictureBox4 = new PictureBox();
      this.PictureBox3 = new PictureBox();
      this.PictureBox2 = new PictureBox();
      this.PictureBox1 = new PictureBox();
      this.PictureBox5 = new PictureBox();
      this.Cancelar = new Button();
      this.Label2 = new Label();
      this.Label3 = new Label();
      this.ReUsPw = new CheckBox();
      this.Cerrar = new Button();
      this.TimeLimit = new TextBox();
      this.Label8 = new Label();
      this.CleanProcedures = new Button();
      this.Label6 = new Label();
      ((ISupportInitialize) this.PictureBox12).BeginInit();
      ((ISupportInitialize) this.PictureBox11).BeginInit();
      ((ISupportInitialize) this.PictureBox8).BeginInit();
      ((ISupportInitialize) this.PictureBox7).BeginInit();
      ((ISupportInitialize) this.PictureBox10).BeginInit();
      ((ISupportInitialize) this.PictureBox9).BeginInit();
      ((ISupportInitialize) this.PictureBox6).BeginInit();
      ((ISupportInitialize) this.PictureBox4).BeginInit();
      ((ISupportInitialize) this.PictureBox3).BeginInit();
      ((ISupportInitialize) this.PictureBox2).BeginInit();
      ((ISupportInitialize) this.PictureBox1).BeginInit();
      ((ISupportInitialize) this.PictureBox5).BeginInit();
      this.SuspendLayout();
      this.PassWord.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox passWord1 = this.PassWord;
      Point point1 = new Point(73, 193);
      Point point2 = point1;
      passWord1.Location = point2;
      this.PassWord.Name = "PassWord";
      this.PassWord.PasswordChar = '*';
      TextBox passWord2 = this.PassWord;
      Size size1 = new Size(184, 20);
      Size size2 = size1;
      passWord2.Size = size2;
      this.PassWord.TabIndex = 8;
      this.Usuario.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox usuario1 = this.Usuario;
      point1 = new Point(73, 169);
      Point point3 = point1;
      usuario1.Location = point3;
      this.Usuario.MaxLength = 20;
      this.Usuario.Name = "Usuario";
      TextBox usuario2 = this.Usuario;
      size1 = new Size(184, 20);
      Size size3 = size1;
      usuario2.Size = size3;
      this.Usuario.TabIndex = 7;
      this.LocalRemote.AutoSize = true;
      this.LocalRemote.BackColor = Color.Transparent;
      this.LocalRemote.Cursor = Cursors.Hand;
      this.LocalRemote.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      RadioButton localRemote1 = this.LocalRemote;
      point1 = new Point(193, 76);
      Point point4 = point1;
      localRemote1.Location = point4;
      this.LocalRemote.Name = "LocalRemote";
      RadioButton localRemote2 = this.LocalRemote;
      size1 = new Size(68, 17);
      Size size4 = size1;
      localRemote2.Size = size4;
      this.LocalRemote.TabIndex = 3;
      this.LocalRemote.Text = "Remote";
      this.ToolTips.SetToolTip((Control) this.LocalRemote, "SQL are in ROMOTE PC");
      this.LocalRemote.UseVisualStyleBackColor = false;
      this.LocalHost.AutoSize = true;
      this.LocalHost.BackColor = Color.Transparent;
      this.LocalHost.Checked = true;
      this.LocalHost.Cursor = Cursors.Hand;
      this.LocalHost.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      RadioButton localHost1 = this.LocalHost;
      point1 = new Point(126, 77);
      Point point5 = point1;
      localHost1.Location = point5;
      this.LocalHost.Name = "LocalHost";
      RadioButton localHost2 = this.LocalHost;
      size1 = new Size(56, 17);
      Size size5 = size1;
      localHost2.Size = size5;
      this.LocalHost.TabIndex = 2;
      this.LocalHost.TabStop = true;
      this.LocalHost.Text = "Local";
      this.ToolTips.SetToolTip((Control) this.LocalHost, "SQL are in LOCAL PC");
      this.LocalHost.UseVisualStyleBackColor = false;
      this.Label12.BackColor = Color.Transparent;
      this.Label12.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label12_1 = this.Label12;
      point1 = new Point(3, 71);
      Point point6 = point1;
      label12_1.Location = point6;
      this.Label12.Name = "Label12";
      Label label12_2 = this.Label12;
      size1 = new Size(114, 26);
      Size size6 = size1;
      label12_2.Size = size6;
      this.Label12.TabIndex = 24;
      this.Label12.Text = "Type Connection :\r\nMuMaker <-> SQL:";
      this.Label12.TextAlign = ContentAlignment.TopRight;
      this.Puerto.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox puerto1 = this.Puerto;
      point1 = new Point(218, 104);
      Point point7 = point1;
      puerto1.Location = point7;
      this.Puerto.MaxLength = 4;
      this.Puerto.Name = "Puerto";
      TextBox puerto2 = this.Puerto;
      size1 = new Size(40, 20);
      Size size7 = size1;
      puerto2.Size = size7;
      this.Puerto.TabIndex = 5;
      this.Label4.AutoSize = true;
      this.Label4.BackColor = Color.Transparent;
      this.Label4.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label4_1 = this.Label4;
      point1 = new Point(5, 196);
      Point point8 = point1;
      label4_1.Location = point8;
      this.Label4.Name = "Label4";
      Label label4_2 = this.Label4;
      size1 = new Size(64, 13);
      Size size8 = size1;
      label4_2.Size = size8;
      this.Label4.TabIndex = 11;
      this.Label4.Text = "PassWord";
      this.Label4.TextAlign = ContentAlignment.MiddleLeft;
      this.IPServer.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox ipServer1 = this.IPServer;
      point1 = new Point(104, 104);
      Point point9 = point1;
      ipServer1.Location = point9;
      this.IPServer.MaxLength = 30;
      this.IPServer.Name = "IPServer";
      TextBox ipServer2 = this.IPServer;
      size1 = new Size(102, 20);
      Size size9 = size1;
      ipServer2.Size = size9;
      this.IPServer.TabIndex = 4;
      this.Label1.AutoSize = true;
      this.Label1.BackColor = Color.Transparent;
      this.Label1.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label1_1 = this.Label1;
      point1 = new Point(3, 108);
      Point point10 = point1;
      label1_1.Location = point10;
      this.Label1.Name = "Label1";
      Label label1_2 = this.Label1;
      size1 = new Size(90, 13);
      Size size10 = size1;
      label1_2.Size = size10;
      this.Label1.TabIndex = 7;
      this.Label1.Text = "SQL - IP : Port";
      this.Label1.TextAlign = ContentAlignment.MiddleLeft;
      this.Label10.BackColor = Color.Transparent;
      this.Label10.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label10_1 = this.Label10;
      point1 = new Point(208, 101);
      Point point11 = point1;
      label10_1.Location = point11;
      this.Label10.Name = "Label10";
      Label label10_2 = this.Label10;
      size1 = new Size(9, 24);
      Size size11 = size1;
      label10_2.Size = size11;
      this.Label10.TabIndex = 21;
      this.Label10.Text = ":";
      this.Label10.TextAlign = ContentAlignment.MiddleLeft;
      this.Label5.AutoSize = true;
      this.Label5.BackColor = Color.Transparent;
      this.Label5.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label5_1 = this.Label5;
      point1 = new Point(5, 175);
      Point point12 = point1;
      label5_1.Location = point12;
      this.Label5.Name = "Label5";
      Label label5_2 = this.Label5;
      size1 = new Size(61, 13);
      Size size12 = size1;
      label5_2.Size = size12;
      this.Label5.TabIndex = 13;
      this.Label5.Text = "SQL User";
      this.Label5.TextAlign = ContentAlignment.MiddleLeft;
      this.CHMD5.AutoSize = true;
      this.CHMD5.BackColor = Color.Transparent;
      this.CHMD5.Cursor = Cursors.Hand;
      this.CHMD5.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      CheckBox chmD5_1 = this.CHMD5;
      point1 = new Point(9, 230);
      Point point13 = point1;
      chmD5_1.Location = point13;
      this.CHMD5.Name = "CHMD5";
      CheckBox chmD5_2 = this.CHMD5;
      size1 = new Size(250, 17);
      Size size13 = size1;
      chmD5_2.Size = size13;
      this.CHMD5.TabIndex = 9;
      this.CHMD5.Text = "MD5 -> If  DB  have  MD5  Encriptation";
      this.CHMD5.UseVisualStyleBackColor = false;
      this.ColumReset.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox columReset1 = this.ColumReset;
      point1 = new Point(358, 252);
      Point point14 = point1;
      columReset1.Location = point14;
      this.ColumReset.MaxLength = 10;
      this.ColumReset.Name = "ColumReset";
      TextBox columReset2 = this.ColumReset;
      size1 = new Size(75, 20);
      Size size14 = size1;
      columReset2.Size = size14;
      this.ColumReset.TabIndex = 15;
      this.ResetSystem.AutoSize = true;
      this.ResetSystem.BackColor = Color.Transparent;
      this.ResetSystem.Cursor = Cursors.Hand;
      this.ResetSystem.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      CheckBox resetSystem1 = this.ResetSystem;
      point1 = new Point(269, 254);
      Point point15 = point1;
      resetSystem1.Location = point15;
      this.ResetSystem.Name = "ResetSystem";
      CheckBox resetSystem2 = this.ResetSystem;
      size1 = new Size(91, 17);
      Size size15 = size1;
      resetSystem2.Size = size15;
      this.ResetSystem.TabIndex = 14;
      this.ResetSystem.Text = "Syst. Reset";
      this.ResetSystem.UseVisualStyleBackColor = false;
      this.MuEvent.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox muEvent1 = this.MuEvent;
      point1 = new Point(93, 305);
      Point point16 = point1;
      muEvent1.Location = point16;
      this.MuEvent.MaxLength = 40;
      this.MuEvent.Name = "MuEvent";
      TextBox muEvent2 = this.MuEvent;
      size1 = new Size(164, 20);
      Size size16 = size1;
      muEvent2.Size = size16;
      this.MuEvent.TabIndex = 12;
      this.Label16.AutoSize = true;
      this.Label16.BackColor = Color.Transparent;
      this.Label16.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label16_1 = this.Label16;
      point1 = new Point(5, 310);
      Point point17 = point1;
      label16_1.Location = point17;
      this.Label16.Name = "Label16";
      Label label16_2 = this.Label16;
      size1 = new Size(69, 13);
      Size size17 = size1;
      label16_2.Size = size17;
      this.Label16.TabIndex = 31;
      this.Label16.Text = "DB - Event";
      this.Label16.TextAlign = ContentAlignment.MiddleCenter;
      this.MuRanking.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox muRanking1 = this.MuRanking;
      point1 = new Point(93, 280);
      Point point18 = point1;
      muRanking1.Location = point18;
      this.MuRanking.MaxLength = 40;
      this.MuRanking.Name = "MuRanking";
      TextBox muRanking2 = this.MuRanking;
      size1 = new Size(164, 20);
      Size size18 = size1;
      muRanking2.Size = size18;
      this.MuRanking.TabIndex = 11;
      this.MuOnline.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox muOnline1 = this.MuOnline;
      point1 = new Point(93, (int) byte.MaxValue);
      Point point19 = point1;
      muOnline1.Location = point19;
      this.MuOnline.MaxLength = 40;
      this.MuOnline.Name = "MuOnline";
      TextBox muOnline2 = this.MuOnline;
      size1 = new Size(164, 20);
      Size size19 = size1;
      muOnline2.Size = size19;
      this.MuOnline.TabIndex = 10;
      this.ExtWareHouse.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox extWareHouse1 = this.ExtWareHouse;
      point1 = new Point(268, 305);
      Point point20 = point1;
      extWareHouse1.Location = point20;
      this.ExtWareHouse.MaxLength = 30;
      this.ExtWareHouse.Name = "ExtWareHouse";
      TextBox extWareHouse2 = this.ExtWareHouse;
      size1 = new Size(182, 20);
      Size size20 = size1;
      extWareHouse2.Size = size20;
      this.ExtWareHouse.TabIndex = 17;
      this.NuExtraWareHouses.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox nuExtraWareHouses1 = this.NuExtraWareHouses;
      point1 = new Point(455, 305);
      Point point21 = point1;
      nuExtraWareHouses1.Location = point21;
      this.NuExtraWareHouses.MaxLength = 2;
      this.NuExtraWareHouses.Name = "NuExtraWareHouses";
      TextBox nuExtraWareHouses2 = this.NuExtraWareHouses;
      size1 = new Size(22, 20);
      Size size21 = size1;
      nuExtraWareHouses2.Size = size21;
      this.NuExtraWareHouses.TabIndex = 18;
      this.NuExtraWareHouses.TextAlign = HorizontalAlignment.Center;
      this.Label7.AutoSize = true;
      this.Label7.BackColor = Color.Transparent;
      this.Label7.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label7_1 = this.Label7;
      point1 = new Point(457, 287);
      Point point22 = point1;
      label7_1.Location = point22;
      this.Label7.Name = "Label7";
      Label label7_2 = this.Label7;
      size1 = new Size(21, 13);
      Size size22 = size1;
      label7_2.Size = size22;
      this.Label7.TabIndex = 18;
      this.Label7.Text = "Nº";
      this.Label7.TextAlign = ContentAlignment.MiddleLeft;
      this.ExtraWareHouse.AutoSize = true;
      this.ExtraWareHouse.BackColor = Color.Transparent;
      this.ExtraWareHouse.Cursor = Cursors.Hand;
      this.ExtraWareHouse.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      CheckBox extraWareHouse1 = this.ExtraWareHouse;
      point1 = new Point(269, 285);
      Point point23 = point1;
      extraWareHouse1.Location = point23;
      this.ExtraWareHouse.Name = "ExtraWareHouse";
      CheckBox extraWareHouse2 = this.ExtraWareHouse;
      size1 = new Size(125, 17);
      Size size23 = size1;
      extraWareHouse2.Size = size23;
      this.ExtraWareHouse.TabIndex = 16;
      this.ExtraWareHouse.Text = "Extra WareHouse";
      this.ExtraWareHouse.UseVisualStyleBackColor = false;
      this.Label14.AutoSize = true;
      this.Label14.BackColor = Color.Transparent;
      this.Label14.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label14_1 = this.Label14;
      point1 = new Point(5, 257);
      Point point24 = point1;
      label14_1.Location = point24;
      this.Label14.Name = "Label14";
      Label label14_2 = this.Label14;
      size1 = new Size(89, 13);
      Size size24 = size1;
      label14_2.Size = size24;
      this.Label14.TabIndex = 28;
      this.Label14.Text = "DB - MuOnline";
      this.Label14.TextAlign = ContentAlignment.MiddleCenter;
      this.Label15.AutoSize = true;
      this.Label15.BackColor = Color.Transparent;
      this.Label15.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label15_1 = this.Label15;
      point1 = new Point(5, 284);
      Point point25 = point1;
      label15_1.Location = point25;
      this.Label15.Name = "Label15";
      Label label15_2 = this.Label15;
      size1 = new Size(83, 13);
      Size size25 = size1;
      label15_2.Size = size25;
      this.Label15.TabIndex = 29;
      this.Label15.Text = "DB - Ranking";
      this.Label15.TextAlign = ContentAlignment.MiddleCenter;
      this.Idiomas.Cursor = Cursors.Hand;
      this.Idiomas.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Idiomas.ItemHeight = 13;
      this.Idiomas.Items.AddRange(new object[12]
      {
        (object) "Español",
        (object) "English",
        (object) "Deutsch",
        (object) "French",
        (object) "PortBra",
        (object) "Italiano",
        (object) "Polish",
        (object) "Latviski",
        (object) "Ruso",
        (object) "Arabe",
        (object) "Chino",
        (object) "Coreano"
      });
      ComboBox idiomas1 = this.Idiomas;
      point1 = new Point(268, 39);
      Point point26 = point1;
      idiomas1.Location = point26;
      this.Idiomas.MaxDropDownItems = 13;
      this.Idiomas.Name = "Idiomas";
      ComboBox idiomas2 = this.Idiomas;
      size1 = new Size(105, 21);
      Size size26 = size1;
      idiomas2.Size = size26;
      this.Idiomas.TabIndex = 15;
      this.CreateReset.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.CreateReset.BackgroundImage = (Image) EmbeddedResources.smethod_50();
      this.CreateReset.BackgroundImageLayout = ImageLayout.Center;
      this.CreateReset.Cursor = Cursors.Hand;
      this.CreateReset.FlatAppearance.BorderSize = 0;
      this.CreateReset.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.CreateReset.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.CreateReset.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.CreateReset.FlatStyle = FlatStyle.Flat;
      this.CreateReset.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.CreateReset.ForeColor = Color.Transparent;
      Button createReset1 = this.CreateReset;
      point1 = new Point(437, 248);
      Point point27 = point1;
      createReset1.Location = point27;
      this.CreateReset.Name = "CreateReset";
      Button createReset2 = this.CreateReset;
      size1 = new Size(52, 28);
      Size size27 = size1;
      createReset2.Size = size27;
      this.CreateReset.TabIndex = 504;
      this.CreateReset.TabStop = false;
      this.ToolTips.SetToolTip((Control) this.CreateReset, "Create Colum Resets in SQL");
      this.CreateReset.UseVisualStyleBackColor = false;
      this.Aceptar.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Aceptar.BackgroundImage = (Image) EmbeddedResources.smethod_90();
      this.Aceptar.BackgroundImageLayout = ImageLayout.Center;
      this.Aceptar.Cursor = Cursors.Hand;
      this.Aceptar.DialogResult = DialogResult.OK;
      this.Aceptar.FlatAppearance.BorderSize = 0;
      this.Aceptar.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.Aceptar.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.Aceptar.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.Aceptar.FlatStyle = FlatStyle.Flat;
      this.Aceptar.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Aceptar.ForeColor = Color.Transparent;
      Button aceptar1 = this.Aceptar;
      point1 = new Point(101, 336);
      Point point28 = point1;
      aceptar1.Location = point28;
      this.Aceptar.Name = "Aceptar";
      Button aceptar2 = this.Aceptar;
      size1 = new Size(52, 28);
      Size size28 = size1;
      aceptar2.Size = size28;
      this.Aceptar.TabIndex = 19;
      this.Aceptar.TabStop = false;
      this.ToolTips.SetToolTip((Control) this.Aceptar, "Save");
      this.Aceptar.UseVisualStyleBackColor = false;
      this.AutoLoad.AutoSize = true;
      this.AutoLoad.BackColor = Color.Transparent;
      this.AutoLoad.Checked = true;
      this.AutoLoad.CheckState = CheckState.Checked;
      this.AutoLoad.Cursor = Cursors.Hand;
      this.AutoLoad.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      CheckBox autoLoad1 = this.AutoLoad;
      point1 = new Point(269, 167);
      Point point29 = point1;
      autoLoad1.Location = point29;
      this.AutoLoad.Name = "AutoLoad";
      CheckBox autoLoad2 = this.AutoLoad;
      size1 = new Size(129, 17);
      Size size29 = size1;
      autoLoad2.Size = size29;
      this.AutoLoad.TabIndex = 6;
      this.AutoLoad.Text = "Load All Accounts\r";
      this.ToolTips.SetToolTip((Control) this.AutoLoad, "When MuMaker Open Load all Accounts ON/OFF");
      this.AutoLoad.UseVisualStyleBackColor = false;
      this.AutoReLoad.AutoSize = true;
      this.AutoReLoad.BackColor = Color.Transparent;
      this.AutoReLoad.Cursor = Cursors.Hand;
      this.AutoReLoad.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      CheckBox autoReLoad1 = this.AutoReLoad;
      point1 = new Point(269, 190);
      Point point30 = point1;
      autoReLoad1.Location = point30;
      this.AutoReLoad.Name = "AutoReLoad";
      CheckBox autoReLoad2 = this.AutoReLoad;
      size1 = new Size(175, 17);
      Size size30 = size1;
      autoReLoad2.Size = size30;
      this.AutoReLoad.TabIndex = 6;
      this.AutoReLoad.Text = "Auto ReLoad All Accounts";
      this.ToolTips.SetToolTip((Control) this.AutoReLoad, "When Create/Delete Accounts AutoReload all Accounts ON/OFF");
      this.AutoReLoad.UseVisualStyleBackColor = false;
      this.MMKNM.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox mmknm1 = this.MMKNM;
      point1 = new Point(12, 42);
      Point point31 = point1;
      mmknm1.Location = point31;
      this.MMKNM.MaxLength = 34;
      this.MMKNM.Name = "MMKNM";
      TextBox mmknm2 = this.MMKNM;
      size1 = new Size(245, 20);
      Size size31 = size1;
      mmknm2.Size = size31;
      this.MMKNM.TabIndex = 1;
      this.MMKNM.TextAlign = HorizontalAlignment.Center;
      this.PictureBox12.BackColor = Color.Transparent;
      this.PictureBox12.BorderStyle = BorderStyle.Fixed3D;
      this.PictureBox12.Cursor = Cursors.Hand;
      // ISSUE: reference to a compiler-generated method
      this.PictureBox12.Image = (Image) EmbeddedResources.smethod_42();
      PictureBox pictureBox12_1 = this.PictureBox12;
      point1 = new Point(448, 90);
      Point point32 = point1;
      pictureBox12_1.Location = point32;
      this.PictureBox12.Name = "PictureBox12";
      PictureBox pictureBox12_2 = this.PictureBox12;
      size1 = new Size(33, 23);
      Size size32 = size1;
      pictureBox12_2.Size = size32;
      this.PictureBox12.TabIndex = 24;
      this.PictureBox12.TabStop = false;
      this.PictureBox11.BackColor = Color.Transparent;
      this.PictureBox11.BorderStyle = BorderStyle.Fixed3D;
      this.PictureBox11.Cursor = Cursors.Hand;
      // ISSUE: reference to a compiler-generated method
      this.PictureBox11.Image = (Image) EmbeddedResources.smethod_78();
      PictureBox pictureBox11_1 = this.PictureBox11;
      point1 = new Point(412, 90);
      Point point33 = point1;
      pictureBox11_1.Location = point33;
      this.PictureBox11.Name = "PictureBox11";
      PictureBox pictureBox11_2 = this.PictureBox11;
      size1 = new Size(33, 23);
      Size size33 = size1;
      pictureBox11_2.Size = size33;
      this.PictureBox11.TabIndex = 23;
      this.PictureBox11.TabStop = false;
      this.PictureBox8.BackColor = Color.Transparent;
      this.PictureBox8.BorderStyle = BorderStyle.Fixed3D;
      this.PictureBox8.Cursor = Cursors.Hand;
      // ISSUE: reference to a compiler-generated method
      this.PictureBox8.Image = (Image) EmbeddedResources.smethod_79();
      PictureBox pictureBox8_1 = this.PictureBox8;
      point1 = new Point(412, 65);
      Point point34 = point1;
      pictureBox8_1.Location = point34;
      this.PictureBox8.Name = "PictureBox8";
      PictureBox pictureBox8_2 = this.PictureBox8;
      size1 = new Size(33, 23);
      Size size34 = size1;
      pictureBox8_2.Size = size34;
      this.PictureBox8.TabIndex = 22;
      this.PictureBox8.TabStop = false;
      this.PictureBox7.BackColor = Color.Transparent;
      this.PictureBox7.BorderStyle = BorderStyle.Fixed3D;
      this.PictureBox7.Cursor = Cursors.Hand;
      // ISSUE: reference to a compiler-generated method
      this.PictureBox7.Image = (Image) EmbeddedResources.smethod_98();
      PictureBox pictureBox7_1 = this.PictureBox7;
      point1 = new Point(376, 65);
      Point point35 = point1;
      pictureBox7_1.Location = point35;
      this.PictureBox7.Name = "PictureBox7";
      PictureBox pictureBox7_2 = this.PictureBox7;
      size1 = new Size(33, 23);
      Size size35 = size1;
      pictureBox7_2.Size = size35;
      this.PictureBox7.TabIndex = 21;
      this.PictureBox7.TabStop = false;
      this.PictureBox10.BackColor = Color.Transparent;
      this.PictureBox10.BorderStyle = BorderStyle.Fixed3D;
      this.PictureBox10.Cursor = Cursors.Hand;
      // ISSUE: reference to a compiler-generated method
      this.PictureBox10.Image = (Image) EmbeddedResources.smethod_6();
      PictureBox pictureBox10_1 = this.PictureBox10;
      point1 = new Point(376, 90);
      Point point36 = point1;
      pictureBox10_1.Location = point36;
      this.PictureBox10.Name = "PictureBox10";
      PictureBox pictureBox10_2 = this.PictureBox10;
      size1 = new Size(33, 23);
      Size size36 = size1;
      pictureBox10_2.Size = size36;
      this.PictureBox10.TabIndex = 20;
      this.PictureBox10.TabStop = false;
      this.PictureBox9.BackColor = Color.Transparent;
      this.PictureBox9.BorderStyle = BorderStyle.Fixed3D;
      this.PictureBox9.Cursor = Cursors.Hand;
      // ISSUE: reference to a compiler-generated method
      this.PictureBox9.Image = (Image) EmbeddedResources.smethod_103();
      PictureBox pictureBox9_1 = this.PictureBox9;
      point1 = new Point(448, 65);
      Point point37 = point1;
      pictureBox9_1.Location = point37;
      this.PictureBox9.Name = "PictureBox9";
      PictureBox pictureBox9_2 = this.PictureBox9;
      size1 = new Size(33, 23);
      Size size37 = size1;
      pictureBox9_2.Size = size37;
      this.PictureBox9.TabIndex = 19;
      this.PictureBox9.TabStop = false;
      this.PictureBox6.BackColor = Color.Transparent;
      this.PictureBox6.BorderStyle = BorderStyle.Fixed3D;
      this.PictureBox6.Cursor = Cursors.Hand;
      // ISSUE: reference to a compiler-generated method
      this.PictureBox6.Image = (Image) EmbeddedResources.smethod_76();
      PictureBox pictureBox6_1 = this.PictureBox6;
      point1 = new Point(340, 65);
      Point point38 = point1;
      pictureBox6_1.Location = point38;
      this.PictureBox6.Name = "PictureBox6";
      PictureBox pictureBox6_2 = this.PictureBox6;
      size1 = new Size(33, 23);
      Size size38 = size1;
      pictureBox6_2.Size = size38;
      this.PictureBox6.TabIndex = 18;
      this.PictureBox6.TabStop = false;
      this.PictureBox4.BackColor = Color.Transparent;
      this.PictureBox4.BorderStyle = BorderStyle.Fixed3D;
      this.PictureBox4.Cursor = Cursors.Hand;
      // ISSUE: reference to a compiler-generated method
      this.PictureBox4.Image = (Image) EmbeddedResources.smethod_63();
      PictureBox pictureBox4_1 = this.PictureBox4;
      point1 = new Point(268, 65);
      Point point39 = point1;
      pictureBox4_1.Location = point39;
      this.PictureBox4.Name = "PictureBox4";
      PictureBox pictureBox4_2 = this.PictureBox4;
      size1 = new Size(33, 23);
      Size size39 = size1;
      pictureBox4_2.Size = size39;
      this.PictureBox4.TabIndex = 17;
      this.PictureBox4.TabStop = false;
      this.PictureBox3.BackColor = Color.Transparent;
      this.PictureBox3.BorderStyle = BorderStyle.Fixed3D;
      this.PictureBox3.Cursor = Cursors.Hand;
      // ISSUE: reference to a compiler-generated method
      this.PictureBox3.Image = (Image) EmbeddedResources.smethod_55();
      PictureBox pictureBox3_1 = this.PictureBox3;
      point1 = new Point(448, 39);
      Point point40 = point1;
      pictureBox3_1.Location = point40;
      this.PictureBox3.Name = "PictureBox3";
      PictureBox pictureBox3_2 = this.PictureBox3;
      size1 = new Size(33, 23);
      Size size40 = size1;
      pictureBox3_2.Size = size40;
      this.PictureBox3.TabIndex = 16;
      this.PictureBox3.TabStop = false;
      this.PictureBox2.BackColor = Color.Transparent;
      this.PictureBox2.BorderStyle = BorderStyle.Fixed3D;
      this.PictureBox2.Cursor = Cursors.Hand;
      // ISSUE: reference to a compiler-generated method
      this.PictureBox2.Image = (Image) EmbeddedResources.smethod_59();
      PictureBox pictureBox2_1 = this.PictureBox2;
      point1 = new Point(412, 39);
      Point point41 = point1;
      pictureBox2_1.Location = point41;
      this.PictureBox2.Name = "PictureBox2";
      PictureBox pictureBox2_2 = this.PictureBox2;
      size1 = new Size(33, 23);
      Size size41 = size1;
      pictureBox2_2.Size = size41;
      this.PictureBox2.TabIndex = 8;
      this.PictureBox2.TabStop = false;
      this.PictureBox1.BackColor = Color.Transparent;
      this.PictureBox1.BorderStyle = BorderStyle.Fixed3D;
      this.PictureBox1.Cursor = Cursors.Hand;
      // ISSUE: reference to a compiler-generated method
      this.PictureBox1.Image = (Image) EmbeddedResources.smethod_60();
      PictureBox pictureBox1_1 = this.PictureBox1;
      point1 = new Point(376, 39);
      Point point42 = point1;
      pictureBox1_1.Location = point42;
      this.PictureBox1.Name = "PictureBox1";
      PictureBox pictureBox1_2 = this.PictureBox1;
      size1 = new Size(33, 23);
      Size size42 = size1;
      pictureBox1_2.Size = size42;
      this.PictureBox1.TabIndex = 7;
      this.PictureBox1.TabStop = false;
      this.PictureBox5.BackColor = Color.Transparent;
      this.PictureBox5.BorderStyle = BorderStyle.Fixed3D;
      this.PictureBox5.Cursor = Cursors.Hand;
      // ISSUE: reference to a compiler-generated method
      this.PictureBox5.Image = (Image) EmbeddedResources.smethod_99();
      PictureBox pictureBox5_1 = this.PictureBox5;
      point1 = new Point(304, 65);
      Point point43 = point1;
      pictureBox5_1.Location = point43;
      this.PictureBox5.Name = "PictureBox5";
      PictureBox pictureBox5_2 = this.PictureBox5;
      size1 = new Size(33, 23);
      Size size43 = size1;
      pictureBox5_2.Size = size43;
      this.PictureBox5.TabIndex = 9;
      this.PictureBox5.TabStop = false;
      this.Cancelar.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Cancelar.BackgroundImage = (Image) EmbeddedResources.smethod_36();
      this.Cancelar.BackgroundImageLayout = ImageLayout.Center;
      this.Cancelar.Cursor = Cursors.Hand;
      this.Cancelar.DialogResult = DialogResult.Cancel;
      this.Cancelar.FlatAppearance.BorderSize = 0;
      this.Cancelar.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.Cancelar.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.Cancelar.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.Cancelar.FlatStyle = FlatStyle.Flat;
      this.Cancelar.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Cancelar.ForeColor = Color.Transparent;
      Button cancelar1 = this.Cancelar;
      point1 = new Point(359, 336);
      Point point44 = point1;
      cancelar1.Location = point44;
      this.Cancelar.Name = "Cancelar";
      Button cancelar2 = this.Cancelar;
      size1 = new Size(52, 28);
      Size size44 = size1;
      cancelar2.Size = size44;
      this.Cancelar.TabIndex = 20;
      this.Cancelar.TabStop = false;
      this.Cancelar.UseVisualStyleBackColor = false;
      this.Label2.AutoSize = true;
      this.Label2.BackColor = Color.Transparent;
      this.Label2.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label2_1 = this.Label2;
      point1 = new Point(11, 27);
      Point point45 = point1;
      label2_1.Location = point45;
      this.Label2.Name = "Label2";
      Label label2_2 = this.Label2;
      size1 = new Size(250, 13);
      Size size45 = size1;
      label2_2.Size = size45;
      this.Label2.TabIndex = 0;
      this.Label2.Text = "Your Name / Server Name / Your Nick . . .";
      this.Label3.AutoSize = true;
      this.Label3.BackColor = Color.Transparent;
      this.Label3.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label3_1 = this.Label3;
      point1 = new Point(316, 25);
      Point point46 = point1;
      label3_1.Location = point46;
      this.Label3.Name = "Label3";
      Label label3_2 = this.Label3;
      size1 = new Size(124, 13);
      Size size46 = size1;
      label3_2.Size = size46;
      this.Label3.TabIndex = 507;
      this.Label3.Text = "Suported Languages";
      this.ReUsPw.AutoSize = true;
      this.ReUsPw.BackColor = Color.Transparent;
      this.ReUsPw.Checked = true;
      this.ReUsPw.CheckState = CheckState.Checked;
      this.ReUsPw.Cursor = Cursors.Hand;
      this.ReUsPw.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      CheckBox reUsPw1 = this.ReUsPw;
      point1 = new Point(9, 139);
      Point point47 = point1;
      reUsPw1.Location = point47;
      this.ReUsPw.Name = "ReUsPw";
      CheckBox reUsPw2 = this.ReUsPw;
      size1 = new Size(247, 17);
      Size size47 = size1;
      reUsPw2.Size = size47;
      this.ReUsPw.TabIndex = 6;
      this.ReUsPw.Text = "Store  Your  SQL  User  <->  PassWord";
      this.ReUsPw.UseVisualStyleBackColor = false;
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
      point1 = new Point(472, 5);
      Point point48 = point1;
      cerrar1.Location = point48;
      this.Cerrar.Name = "Cerrar";
      Button cerrar2 = this.Cerrar;
      size1 = new Size(13, 13);
      Size size48 = size1;
      cerrar2.Size = size48;
      this.Cerrar.TabIndex = 21;
      this.Cerrar.TabStop = false;
      this.Cerrar.UseVisualStyleBackColor = false;
      this.TimeLimit.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox timeLimit1 = this.TimeLimit;
      point1 = new Point(267, 216);
      Point point49 = point1;
      timeLimit1.Location = point49;
      this.TimeLimit.MaxLength = 4;
      this.TimeLimit.Name = "TimeLimit";
      TextBox timeLimit2 = this.TimeLimit;
      size1 = new Size(35, 20);
      Size size49 = size1;
      timeLimit2.Size = size49;
      this.TimeLimit.TabIndex = 508;
      this.TimeLimit.TextAlign = HorizontalAlignment.Right;
      this.Label8.AutoSize = true;
      this.Label8.BackColor = Color.Transparent;
      this.Label8.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label8_1 = this.Label8;
      point1 = new Point(302, 220);
      Point point50 = point1;
      label8_1.Location = point50;
      this.Label8.Name = "Label8";
      Label label8_2 = this.Label8;
      size1 = new Size(190, 13);
      Size size50 = size1;
      label8_2.Size = size50;
      this.Label8.TabIndex = 510;
      this.Label8.Text = "TimeLimit SQL Connection (Seg)";
      this.Label8.TextAlign = ContentAlignment.MiddleLeft;
      this.CleanProcedures.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.CleanProcedures.BackgroundImage = (Image) EmbeddedResources.smethod_4();
      this.CleanProcedures.BackgroundImageLayout = ImageLayout.Center;
      this.CleanProcedures.Cursor = Cursors.Hand;
      this.CleanProcedures.FlatAppearance.BorderSize = 0;
      this.CleanProcedures.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.CleanProcedures.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.CleanProcedures.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.CleanProcedures.FlatStyle = FlatStyle.Flat;
      this.CleanProcedures.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.CleanProcedures.ForeColor = Color.Transparent;
      Button cleanProcedures1 = this.CleanProcedures;
      point1 = new Point(267, (int) sbyte.MaxValue);
      Point point51 = point1;
      cleanProcedures1.Location = point51;
      this.CleanProcedures.Name = "CleanProcedures";
      Button cleanProcedures2 = this.CleanProcedures;
      size1 = new Size(32, 25);
      Size size51 = size1;
      cleanProcedures2.Size = size51;
      this.CleanProcedures.TabIndex = 504;
      this.CleanProcedures.TabStop = false;
      this.CleanProcedures.UseVisualStyleBackColor = false;
      this.Label6.AutoSize = true;
      this.Label6.BackColor = Color.Transparent;
      this.Label6.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label6_1 = this.Label6;
      point1 = new Point(300, (int) sbyte.MaxValue);
      Point point52 = point1;
      label6_1.Location = point52;
      this.Label6.Name = "Label6";
      Label label6_2 = this.Label6;
      size1 = new Size(148, 26);
      Size size52 = size1;
      label6_2.Size = size52;
      this.Label6.TabIndex = 510;
      this.Label6.Text = "Clean and Regenerate\r\nMMK_Procedures in SQL";
      this.Label6.TextAlign = ContentAlignment.MiddleLeft;
      this.AutoScaleMode = AutoScaleMode.Inherit;
      this.BackColor = Color.Black;
      // ISSUE: reference to a compiler-generated method
      this.BackgroundImage = (Image) EmbeddedResources.smethod_47();
      this.CancelButton = (IButtonControl) this.Cerrar;
      size1 = new Size(492, 368);
      this.ClientSize = size1;
      this.Controls.Add((Control) this.Label6);
      this.Controls.Add((Control) this.Label8);
      this.Controls.Add((Control) this.TimeLimit);
      this.Controls.Add((Control) this.Cerrar);
      this.Controls.Add((Control) this.AutoReLoad);
      this.Controls.Add((Control) this.AutoLoad);
      this.Controls.Add((Control) this.ReUsPw);
      this.Controls.Add((Control) this.CleanProcedures);
      this.Controls.Add((Control) this.CreateReset);
      this.Controls.Add((Control) this.PictureBox12);
      this.Controls.Add((Control) this.CHMD5);
      this.Controls.Add((Control) this.ColumReset);
      this.Controls.Add((Control) this.MuEvent);
      this.Controls.Add((Control) this.ResetSystem);
      this.Controls.Add((Control) this.PictureBox11);
      this.Controls.Add((Control) this.ExtraWareHouse);
      this.Controls.Add((Control) this.PassWord);
      this.Controls.Add((Control) this.ExtWareHouse);
      this.Controls.Add((Control) this.PictureBox10);
      this.Controls.Add((Control) this.Label7);
      this.Controls.Add((Control) this.PictureBox8);
      this.Controls.Add((Control) this.NuExtraWareHouses);
      this.Controls.Add((Control) this.PictureBox9);
      this.Controls.Add((Control) this.MuOnline);
      this.Controls.Add((Control) this.PictureBox7);
      this.Controls.Add((Control) this.MuRanking);
      this.Controls.Add((Control) this.Usuario);
      this.Controls.Add((Control) this.PictureBox6);
      this.Controls.Add((Control) this.Label14);
      this.Controls.Add((Control) this.PictureBox4);
      this.Controls.Add((Control) this.PictureBox5);
      this.Controls.Add((Control) this.Label15);
      this.Controls.Add((Control) this.PictureBox3);
      this.Controls.Add((Control) this.PictureBox2);
      this.Controls.Add((Control) this.Idiomas);
      this.Controls.Add((Control) this.PictureBox1);
      this.Controls.Add((Control) this.Label16);
      this.Controls.Add((Control) this.Label4);
      this.Controls.Add((Control) this.MMKNM);
      this.Controls.Add((Control) this.Label5);
      this.Controls.Add((Control) this.LocalRemote);
      this.Controls.Add((Control) this.LocalHost);
      this.Controls.Add((Control) this.Cancelar);
      this.Controls.Add((Control) this.Label12);
      this.Controls.Add((Control) this.Puerto);
      this.Controls.Add((Control) this.Aceptar);
      this.Controls.Add((Control) this.IPServer);
      this.Controls.Add((Control) this.Label1);
      this.Controls.Add((Control) this.Label10);
      this.Controls.Add((Control) this.Label3);
      this.Controls.Add((Control) this.Label2);
      this.ForeColor = Color.DarkGoldenrod;
      this.FormBorderStyle = FormBorderStyle.None;
      this.Icon = (Icon) componentResourceManager.GetObject("$this.Icon");
      this.MaximizeBox = false;
      this.MinimizeBox = false;
      this.Name = "ConfigMaker";
      this.StartPosition = FormStartPosition.CenterScreen;
      this.Text = "ConfigMaker";
      this.TopMost = true;
      this.TransparencyKey = Color.Red;
      ((ISupportInitialize) this.PictureBox12).EndInit();
      ((ISupportInitialize) this.PictureBox11).EndInit();
      ((ISupportInitialize) this.PictureBox8).EndInit();
      ((ISupportInitialize) this.PictureBox7).EndInit();
      ((ISupportInitialize) this.PictureBox10).EndInit();
      ((ISupportInitialize) this.PictureBox9).EndInit();
      ((ISupportInitialize) this.PictureBox6).EndInit();
      ((ISupportInitialize) this.PictureBox4).EndInit();
      ((ISupportInitialize) this.PictureBox3).EndInit();
      ((ISupportInitialize) this.PictureBox2).EndInit();
      ((ISupportInitialize) this.PictureBox1).EndInit();
      ((ISupportInitialize) this.PictureBox5).EndInit();
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

    public object ReiniciarMuMaker()
    {
      IniHelper.smethod_43();
      try
      {
        object Left = (object) FileSystem.CurDir();
        Process process = new Process();
        Process.GetProcessesByName("MuMaker")[0].CloseMainWindow();
        NewLateBinding.LateCall((object) process, (System.Type) null, "Start", new object[1]
        {
          Operators.ConcatenateObject(Left, (object) "/MuMaker.exe")
        }, (string[]) null, (System.Type[]) null, (bool[]) null, 1 != 0);
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) "!! RESTART MuMaker RESTART !!", MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      return (object) true;
    }

    public object ComprobarExtraWareHouse()
    {
      if (this.ExtraWareHouse.Checked)
      {
        object obj1 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "ExtWareHouse", "ExtWareHouse");
        object obj2 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "NuExtraWareHouse", "0");
        this.ExtWareHouse.Enabled = true;
        this.NuExtraWareHouses.Enabled = true;
        this.ExtWareHouse.Text = Conversions.ToString(obj1);
        this.NuExtraWareHouses.Text = Conversions.ToString(obj2);
      }
      else
      {
        object obj1 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "ExtWareHouse", "ExtWareHouse");
        object obj2 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "NuExtraWareHouse", "0");
        this.ExtWareHouse.Enabled = false;
        this.NuExtraWareHouses.Enabled = false;
        this.ExtWareHouse.Text = Conversions.ToString(obj1);
        this.NuExtraWareHouses.Text = Conversions.ToString(obj2);
      }
      return (object) true;
    }

    public object ComprobarReset()
    {
      if (this.ResetSystem.Checked)
      {
        object obj = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "Reset", "Resets");
        this.ColumReset.Enabled = true;
        this.ColumReset.Text = Conversions.ToString(obj);
      }
      else
      {
        object obj = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "Reset", "Resets");
        this.ColumReset.Enabled = false;
        this.ColumReset.Text = Conversions.ToString(obj);
      }
      return (object) true;
    }

    private void ConfigMaker_Load(object sender, EventArgs e)
    {
      ApplicationServices.MuMakerApplication.smethod_3().method_8().WindowState = FormWindowState.Minimized;
      object Left1 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "RPW", "0");
      object Left2 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "Connection", "Local");
      object obj1 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "Usuario", "sa");
      object obj2 = (object) IniHelper.smethod_8(IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "PassWord", ""));
      object obj3 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "IPServer", "127.0.0.1");
      object obj4 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "PORTServer", "1433");
      object obj5 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "MuOnline", "MuOnline");
      object obj6 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "MuEvent", "MuEvent");
      object obj7 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "MuRanking", "Ranking");
      object obj8 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "Reset", "Resets");
      object obj9 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "ExtWareHouse", "ExtWareHouse");
      int num = Conversions.ToInteger(IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "TimeLimit", Conversions.ToString(360)));
      object Left3 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "ExtraWareHouse", "0");
      object obj10 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "NuExtraWareHouses", "0");
      object Left4 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "Reset", "0");
      object Left5 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "MD5", "0");
      object Left6 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "FirstLoad", "1");
      object Left7 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "AutoReLoad", "0");
      object obj11 = (object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "Languaje", "Espanol");
      this.MMKNM.Text = Conversions.ToString((object) IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Personal", "Name", "N00B"));
      this.Usuario.Text = Conversions.ToString(obj1);
      this.PassWord.Text = Conversions.ToString(obj2);
      if (Operators.ConditionalCompareObjectEqual(Left2, (object) "Local", false))
        this.LocalHost.Checked = true;
      if (Operators.ConditionalCompareObjectEqual(Left2, (object) "Remote", false))
        this.LocalRemote.Checked = true;
      this.IPServer.Text = Conversions.ToString(obj3);
      this.Puerto.Text = Conversions.ToString(obj4);
      this.MuOnline.Text = Conversions.ToString(obj5);
      this.MuRanking.Text = Conversions.ToString(obj7);
      this.MuEvent.Text = Conversions.ToString(obj6);
      this.Idiomas.SelectedIndex = 0;
      try
      {
        this.Idiomas.SelectedItem = RuntimeHelpers.GetObjectValue(obj11);
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        this.Idiomas.SelectedIndex = 0;
        ProjectData.ClearProjectError();
      }
      if (Operators.ConditionalCompareObjectEqual(Left3, (object) 1, false))
        this.ExtraWareHouse.Checked = true;
      if (Operators.ConditionalCompareObjectEqual(Left4, (object) 1, false))
        this.ResetSystem.Checked = true;
      if (this.ExtraWareHouse.Checked)
      {
        this.ExtWareHouse.Text = Conversions.ToString(obj9);
        this.NuExtraWareHouses.Text = Conversions.ToString(obj10);
      }
      else
      {
        this.ExtWareHouse.Enabled = false;
        this.NuExtraWareHouses.Enabled = false;
        this.ExtWareHouse.Text = Conversions.ToString(obj9);
        this.NuExtraWareHouses.Text = Conversions.ToString(obj10);
      }
      if (this.ResetSystem.Checked)
      {
        this.ColumReset.Text = Conversions.ToString(obj8);
      }
      else
      {
        this.ColumReset.Enabled = false;
        this.ColumReset.Text = Conversions.ToString(obj8);
      }
      this.CHMD5.Checked = Operators.ConditionalCompareObjectEqual(Left5, (object) 1, false);
      if (Operators.ConditionalCompareObjectEqual(Left1, (object) 1, false))
      {
        this.ReUsPw.Checked = true;
        this.Label4.Visible = true;
        this.Label5.Visible = true;
        this.Usuario.Visible = true;
        this.PassWord.Visible = true;
      }
      else
      {
        this.ReUsPw.Checked = false;
        this.Label4.Visible = false;
        this.Label5.Visible = false;
        this.Usuario.Visible = false;
        this.PassWord.Visible = false;
      }
      if (Operators.ConditionalCompareObjectEqual(Left6, (object) 1, false))
      {
        this.AutoLoad.Checked = true;
        this.AutoReLoad.Checked = Operators.ConditionalCompareObjectEqual(Left7, (object) 1, false);
      }
      else
      {
        this.AutoLoad.Checked = false;
        this.AutoReLoad.Visible = false;
        this.AutoReLoad.Checked = false;
      }
      this.TimeLimit.Text = Conversions.ToString(num);
    }

    private void method_0(object sender, EventArgs e)
    {
      if (this.ReUsPw.Checked)
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "RPW", "1");
      else
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "RPW", "0");
      IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "Usuario", this.Usuario.Text);
      IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "PassWord", IniHelper.smethod_7(this.PassWord.Text));
      if (this.LocalHost.Checked)
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "Connection", "Local");
      if (this.LocalRemote.Checked)
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "Connection", "Remote");
      IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "IPServer", this.IPServer.Text);
      IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "PORTServer", this.Puerto.Text);
      IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "MuOnline", this.MuOnline.Text);
      IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "MuEvent", this.MuEvent.Text);
      IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "MuRanking", this.MuRanking.Text);
      IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "TimeLimit", this.TimeLimit.Text);
      if (Operators.CompareString(this.Idiomas.Text, "Español", false) == 0)
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "Languaje", "Espanol");
      else
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "Languaje", this.Idiomas.Text);
      if (this.ExtraWareHouse.Checked)
      {
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "ExtWareHouse", this.ExtWareHouse.Text);
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "NuExtraWareHouses", this.NuExtraWareHouses.Text);
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "ExtraWareHouse", "1");
      }
      else
      {
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "ExtWareHouse", this.ExtWareHouse.Text);
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "NuExtraWareHouses", "0");
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "ExtraWareHouse", "0");
      }
      if (this.ResetSystem.Checked)
      {
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "Reset", this.ColumReset.Text);
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "Reset", "1");
      }
      else
      {
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "Reset", this.ColumReset.Text);
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "Reset", "0");
      }
      if (this.CHMD5.Checked)
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "MD5", "1");
      else
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "MD5", "0");
      if (this.AutoLoad.Checked)
      {
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "FirstLoad", "1");
        if (-(this.AutoReLoad.Checked ? 1 : 0) == 1)
          IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "AutoReLoad", "1");
        else
          IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "AutoReLoad", "0");
      }
      else
      {
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "FirstLoad", "0");
        IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "AutoReLoad", "0");
      }
      IniHelper.smethod_2(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "Personal", "Name", this.MMKNM.Text);
      Form.ActiveForm.Hide();
      ApplicationServices.MuMakerApplication.smethod_3().method_8().WindowState = FormWindowState.Normal;
      this.ReiniciarMuMaker();
    }

    private void method_1(object sender, EventArgs e)
    {
      Form.ActiveForm.Close();
      ApplicationServices.MuMakerApplication.smethod_3().method_8().WindowState = FormWindowState.Normal;
      ApplicationServices.MuMakerApplication.smethod_3().method_8().BotonCreditos.Focus();
    }

    private void method_2(object sender, EventArgs e)
    {
      Form.ActiveForm.Close();
      ApplicationServices.MuMakerApplication.smethod_3().method_8().WindowState = FormWindowState.Normal;
      ApplicationServices.MuMakerApplication.smethod_3().method_8().BotonCreditos.Focus();
    }

    private void ExtraWareHouse_CheckedChanged(object sender, EventArgs e)
    {
      this.ComprobarExtraWareHouse();
    }

    private void ResetSystem_CheckedChanged(object sender, EventArgs e)
    {
      this.ComprobarReset();
    }

    private void method_3(object sender, KeyPressEventArgs e)
    {
      if ((int) IniHelper.smethod_19(checked ((short) Strings.Asc(e.KeyChar))) != 0)
        return;
      e.Handled = true;
    }

    private void LocalHost_CheckedChanged(object sender, EventArgs e)
    {
      if (this.LocalHost.Checked)
      {
        this.IPServer.Enabled = false;
        this.Puerto.Enabled = false;
        this.IPServer.Text = "127.0.0.1";
        this.Puerto.Text = "1433";
      }
      if (!this.LocalRemote.Checked)
        return;
      this.IPServer.Enabled = true;
      this.Puerto.Enabled = true;
    }

    private void LocalRemote_CheckedChanged(object sender, EventArgs e)
    {
      if (this.LocalHost.Checked)
      {
        this.IPServer.Enabled = false;
        this.Puerto.Enabled = false;
        this.IPServer.Text = "127.0.0.1";
        this.Puerto.Text = "1433";
      }
      if (!this.LocalRemote.Checked)
        return;
      this.IPServer.Enabled = true;
      this.Puerto.Enabled = true;
      this.IPServer.Text = IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "IPServer", "127.0.0.1");
      this.Puerto.Text = IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "PORTServer", "1433");
    }

    private void method_4(object sender, EventArgs e)
    {
      FinderTableManager.smethod_0();
    }

    private void ReUsPw_CheckedChanged(object sender, EventArgs e)
    {
      if (this.ReUsPw.Checked)
      {
        this.Label4.Visible = true;
        this.Label5.Visible = true;
        this.Usuario.Visible = true;
        this.PassWord.Visible = true;
      }
      else
      {
        this.Label4.Visible = false;
        this.Label5.Visible = false;
        this.Usuario.Visible = false;
        this.PassWord.Visible = false;
      }
    }

    private void AutoLoad_CheckedChanged(object sender, EventArgs e)
    {
      if (this.AutoLoad.Checked)
      {
        this.AutoReLoad.Visible = true;
      }
      else
      {
        this.AutoReLoad.Visible = false;
        this.AutoReLoad.Checked = false;
      }
    }

    private void AutoReLoad_CheckedChanged(object sender, EventArgs e)
    {
    }

    private void method_5(object sender, EventArgs e)
    {
      StoredProceduresManager.smethod_14();
      StoredProceduresManager.smethod_0();
      StoredProceduresManager.smethod_1();
      StoredProceduresManager.smethod_2();
      StoredProceduresManager.smethod_3();
    }

    private void MMKNM_LostFocus(object sender, EventArgs e)
    {
      if (Operators.CompareString(this.MMKNM.Text, "", false) != 0)
        return;
      this.MMKNM.Text = "N00B";
    }

    private void Usuario_LostFocus(object sender, EventArgs e)
    {
      if (Operators.CompareString(this.Usuario.Text, "", false) != 0)
        return;
      this.Usuario.Text = "sa";
    }

    private void IPServer_LostFocus(object sender, EventArgs e)
    {
      if (Operators.CompareString(this.IPServer.Text, "", false) != 0)
        return;
      this.IPServer.Text = "127.0.0.1";
    }

    private void Puerto_LostFocus(object sender, EventArgs e)
    {
      if (Operators.CompareString(this.Puerto.Text, "", false) != 0)
        return;
      this.Puerto.Text = "1433";
    }

    private void MuOnline_LostFocus(object sender, EventArgs e)
    {
      if (Operators.CompareString(this.MuOnline.Text, "", false) != 0)
        return;
      this.MuOnline.Text = "MuOnline";
    }

    private void MuRanking_LostFocus(object sender, EventArgs e)
    {
      if (Operators.CompareString(this.MuRanking.Text, "", false) != 0)
        return;
      this.MuRanking.Text = "Ranking";
    }

    private void MuEvent_LostFocus(object sender, EventArgs e)
    {
      if (Operators.CompareString(this.MuEvent.Text, "", false) != 0)
        return;
      this.MuEvent.Text = "MuEvent";
    }

    private void method_6(object sender, EventArgs e)
    {
      if (Operators.CompareString(this.NuExtraWareHouses.Text, "", false) != 0)
        return;
      this.NuExtraWareHouses.Text = "ExtWareHouse";
    }

    private void ExtWareHouse_LostFocus(object sender, EventArgs e)
    {
      if (Operators.CompareString(this.ExtWareHouse.Text, "", false) != 0)
        return;
      this.ExtWareHouse.Text = "0";
    }

    private void ColumReset_LostFocus(object sender, EventArgs e)
    {
      if (Operators.CompareString(this.ColumReset.Text, "", false) != 0)
        return;
      this.ColumReset.Text = "Resets";
    }

    private void method_7(object sender, EventArgs e)
    {
      if (Operators.CompareString(this.TimeLimit.Text, "", false) == 0)
        this.TimeLimit.Text = Conversions.ToString(360);
      if (Operators.CompareString(Strings.Mid(this.TimeLimit.Text, 1, 4), "0000", false) == 0)
        this.TimeLimit.Text = Conversions.ToString(360);
      if (Operators.CompareString(Strings.Mid(this.TimeLimit.Text, 1, 3), "000", false) == 0)
        this.TimeLimit.Text = Strings.Mid(this.TimeLimit.Text, 4, 1);
      if (Operators.CompareString(Strings.Mid(this.TimeLimit.Text, 1, 2), "00", false) == 0)
        this.TimeLimit.Text = Strings.Mid(this.TimeLimit.Text, 3, 2);
      if (Operators.CompareString(Strings.Mid(this.TimeLimit.Text, 1, 1), "0", false) != 0)
        return;
      this.TimeLimit.Text = Strings.Mid(this.TimeLimit.Text, 2, 3);
    }

    private void method_8(object sender, KeyPressEventArgs e)
    {
      if ((int) IniHelper.smethod_19(checked ((short) Strings.Asc(e.KeyChar))) != 0)
        return;
      e.Handled = true;
    }

    private void PictureBox1_Click(object sender, EventArgs e)
    {
      this.Idiomas.SelectedIndex = 0;
    }

    private void PictureBox2_Click(object sender, EventArgs e)
    {
      this.Idiomas.SelectedIndex = 1;
    }

    private void PictureBox3_Click(object sender, EventArgs e)
    {
      this.Idiomas.SelectedIndex = 2;
    }

    private void PictureBox4_Click(object sender, EventArgs e)
    {
      this.Idiomas.SelectedIndex = 3;
    }

    private void PictureBox5_Click(object sender, EventArgs e)
    {
      this.Idiomas.SelectedIndex = 4;
    }

    private void PictureBox6_Click(object sender, EventArgs e)
    {
      this.Idiomas.SelectedIndex = 5;
    }

    private void PictureBox7_Click(object sender, EventArgs e)
    {
      this.Idiomas.SelectedIndex = 6;
    }

    private void PictureBox8_Click(object sender, EventArgs e)
    {
      this.Idiomas.SelectedIndex = 7;
    }

    private void PictureBox9_Click(object sender, EventArgs e)
    {
      this.Idiomas.SelectedIndex = 8;
    }

    private void PictureBox10_Click(object sender, EventArgs e)
    {
      this.Idiomas.SelectedIndex = 9;
    }

    private void PictureBox12_Click(object sender, EventArgs e)
    {
      this.Idiomas.SelectedIndex = 10;
    }

    private void PictureBox11_Click(object sender, EventArgs e)
    {
      this.Idiomas.SelectedIndex = 11;
    }

    private void method_9(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Aceptar.BackgroundImage = (Image) EmbeddedResources.smethod_90();
      this.MMKNM.Focus();
    }

    private void method_10(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Aceptar.BackgroundImage = (Image) EmbeddedResources.smethod_91();
    }

    private void method_11(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cancelar.BackgroundImage = (Image) EmbeddedResources.smethod_36();
      this.MMKNM.Focus();
    }

    private void method_12(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cancelar.BackgroundImage = (Image) EmbeddedResources.smethod_37();
    }

    private void method_13(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.CreateReset.BackgroundImage = (Image) EmbeddedResources.smethod_50();
      this.MMKNM.Focus();
    }

    private void method_14(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.CreateReset.BackgroundImage = (Image) EmbeddedResources.smethod_51();
    }

    private void method_15(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.CleanProcedures.BackgroundImage = (Image) EmbeddedResources.smethod_4();
      this.MMKNM.Focus();
    }

    private void method_16(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.CleanProcedures.BackgroundImage = (Image) EmbeddedResources.smethod_5();
    }

    private void method_17(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) EmbeddedResources.smethod_39();
      this.MMKNM.Focus();
    }

    private void method_18(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) EmbeddedResources.smethod_40();
    }

    private void ConfigMaker_Closing(object sender, CancelEventArgs e)
    {
      ApplicationServices.MuMakerApplication.smethod_3().method_8().WindowState = FormWindowState.Normal;
    }
  }
}
