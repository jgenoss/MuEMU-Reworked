// Decompiled with JetBrains decompiler
// Type: MuMaker.SkillMaker
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
  public class SkillMaker : Form
  {
    private static SkillMaker skillMaker_0 = (SkillMaker) null;
    private IContainer icontainer_0;
    [AccessedThroughProperty("Emergente")]
    private ToolTip toolTip_0;
    [AccessedThroughProperty("Skill31")]
    private PictureBox _Skill31;
    [AccessedThroughProperty("Skill32")]
    private PictureBox _Skill32;
    [AccessedThroughProperty("Skill33")]
    private PictureBox _Skill33;
    [AccessedThroughProperty("Skill34")]
    private PictureBox _Skill34;
    [AccessedThroughProperty("Skill35")]
    private PictureBox _Skill35;
    [AccessedThroughProperty("Skill36")]
    private PictureBox _Skill36;
    [AccessedThroughProperty("Skill37")]
    private PictureBox _Skill37;
    [AccessedThroughProperty("Skill38")]
    private PictureBox _Skill38;
    [AccessedThroughProperty("Skill39")]
    private PictureBox _Skill39;
    [AccessedThroughProperty("Skill40")]
    private PictureBox _Skill40;
    [AccessedThroughProperty("Skill41")]
    private PictureBox _Skill41;
    [AccessedThroughProperty("Skill42")]
    private PictureBox _Skill42;
    [AccessedThroughProperty("Skill43")]
    private PictureBox _Skill43;
    [AccessedThroughProperty("Skill44")]
    private PictureBox _Skill44;
    [AccessedThroughProperty("Skill45")]
    private PictureBox _Skill45;
    [AccessedThroughProperty("Skill46")]
    private PictureBox _Skill46;
    [AccessedThroughProperty("Skill47")]
    private PictureBox _Skill47;
    [AccessedThroughProperty("Skill48")]
    private PictureBox _Skill48;
    [AccessedThroughProperty("Skill21")]
    private PictureBox _Skill21;
    [AccessedThroughProperty("Skill22")]
    private PictureBox _Skill22;
    [AccessedThroughProperty("Skill23")]
    private PictureBox _Skill23;
    [AccessedThroughProperty("Skill24")]
    private PictureBox _Skill24;
    [AccessedThroughProperty("Skill25")]
    private PictureBox _Skill25;
    [AccessedThroughProperty("Skill26")]
    private PictureBox _Skill26;
    [AccessedThroughProperty("Skill27")]
    private PictureBox _Skill27;
    [AccessedThroughProperty("Skill28")]
    private PictureBox _Skill28;
    [AccessedThroughProperty("Skill29")]
    private PictureBox _Skill29;
    [AccessedThroughProperty("Skill49")]
    private PictureBox _Skill49;
    [AccessedThroughProperty("Label6")]
    private Label _Label6;
    [AccessedThroughProperty("OnlineOFF")]
    private PictureBox _OnlineOFF;
    [AccessedThroughProperty("OnlineON")]
    private PictureBox _OnlineON;
    [AccessedThroughProperty("ClearSkills")]
    private Button _ClearSkills;
    [AccessedThroughProperty("ONLineInfo")]
    private Button _ONLineInfo;
    [AccessedThroughProperty("Skill50")]
    private PictureBox _Skill50;
    [AccessedThroughProperty("Skill51")]
    private PictureBox _Skill51;
    [AccessedThroughProperty("Skill52")]
    private PictureBox _Skill52;
    [AccessedThroughProperty("Skill53")]
    private PictureBox _Skill53;
    [AccessedThroughProperty("Skill54")]
    private PictureBox _Skill54;
    [AccessedThroughProperty("Skill55")]
    private PictureBox _Skill55;
    [AccessedThroughProperty("Skill56")]
    private PictureBox _Skill56;
    [AccessedThroughProperty("Skill57")]
    private PictureBox _Skill57;
    [AccessedThroughProperty("Skill58")]
    private PictureBox _Skill58;
    [AccessedThroughProperty("Skill59")]
    private PictureBox _Skill59;
    [AccessedThroughProperty("Skill60")]
    private PictureBox _Skill60;
    [AccessedThroughProperty("Skill30")]
    private PictureBox _Skill30;
    [AccessedThroughProperty("Skill11")]
    private PictureBox _Skill11;
    [AccessedThroughProperty("Skill12")]
    private PictureBox _Skill12;
    [AccessedThroughProperty("Skill13")]
    private PictureBox _Skill13;
    [AccessedThroughProperty("Skill14")]
    private PictureBox _Skill14;
    [AccessedThroughProperty("Skill15")]
    private PictureBox _Skill15;
    [AccessedThroughProperty("Skill16")]
    private PictureBox _Skill16;
    [AccessedThroughProperty("Skill17")]
    private PictureBox _Skill17;
    [AccessedThroughProperty("Skill18")]
    private PictureBox _Skill18;
    [AccessedThroughProperty("Skill20")]
    private PictureBox _Skill20;
    [AccessedThroughProperty("Skill19")]
    private PictureBox _Skill19;
    [AccessedThroughProperty("Skill10")]
    private PictureBox _Skill10;
    [AccessedThroughProperty("Skill9")]
    private PictureBox _Skill9;
    [AccessedThroughProperty("Skill8")]
    private PictureBox _Skill8;
    [AccessedThroughProperty("Skill7")]
    private PictureBox _Skill7;
    [AccessedThroughProperty("Skill6")]
    private PictureBox _Skill6;
    [AccessedThroughProperty("Skill5")]
    private PictureBox _Skill5;
    [AccessedThroughProperty("Skill4")]
    private PictureBox _Skill4;
    [AccessedThroughProperty("Skill3")]
    private PictureBox _Skill3;
    [AccessedThroughProperty("Skill1")]
    private PictureBox _Skill1;
    [AccessedThroughProperty("Skill2")]
    private PictureBox _Skill2;
    [AccessedThroughProperty("PersonajeSearch")]
    private TextBox _PersonajeSearch;
    [AccessedThroughProperty("CuentaSearch")]
    private TextBox _CuentaSearch;
    [AccessedThroughProperty("Foto")]
    private Label _Foto;
    [AccessedThroughProperty("Imagen")]
    private PictureBox _Imagen;
    [AccessedThroughProperty("Items")]
    private ListBox _Items;
    [AccessedThroughProperty("Tipo")]
    private ListBox _Tipo;
    [AccessedThroughProperty("Account")]
    private Label _Account;
    [AccessedThroughProperty("Personajes")]
    private ComboBox _Personajes;
    [AccessedThroughProperty("Cuentas")]
    private ComboBox _Cuentas;
    [AccessedThroughProperty("Chart")]
    private Label _Chart;
    [AccessedThroughProperty("Reloj")]
    private System.Windows.Forms.Timer timer_0;
    [AccessedThroughProperty("Buscar")]
    private Button _Buscar;
    [AccessedThroughProperty("Cerrar")]
    private Button _Cerrar;
    [AccessedThroughProperty("Minimizar")]
    private Button _Minimizar;
    [AccessedThroughProperty("SkillTipo")]
    private Label _SkillTipo;
    [AccessedThroughProperty("SkillRango")]
    private Label _SkillRango;
    [AccessedThroughProperty("Mana")]
    private Label _Mana;
    [AccessedThroughProperty("Estamina")]
    private Label _Estamina;
    [AccessedThroughProperty("CuentaSkill")]
    private Label _CuentaSkill;
    [AccessedThroughProperty("ChartSkill")]
    private Label _ChartSkill;
    [AccessedThroughProperty("NombreClase")]
    private Label _NombreClase;
    [AccessedThroughProperty("Titulo")]
    private Label _Titulo;
    private const int int_0 = 132;
    private const int int_1 = 1;
    private const int int_2 = 2;

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

    internal virtual PictureBox Skill31
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill31;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill31_Click);
        if (this._Skill31 != null)
          this._Skill31.Click -= eventHandler;
        this._Skill31 = value;
        if (this._Skill31 == null)
          return;
        this._Skill31.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill32
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill32;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill32_Click);
        if (this._Skill32 != null)
          this._Skill32.Click -= eventHandler;
        this._Skill32 = value;
        if (this._Skill32 == null)
          return;
        this._Skill32.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill33
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill33;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill33_Click);
        if (this._Skill33 != null)
          this._Skill33.Click -= eventHandler;
        this._Skill33 = value;
        if (this._Skill33 == null)
          return;
        this._Skill33.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill34
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill34;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill34_Click);
        if (this._Skill34 != null)
          this._Skill34.Click -= eventHandler;
        this._Skill34 = value;
        if (this._Skill34 == null)
          return;
        this._Skill34.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill35
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill35;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill35_Click);
        if (this._Skill35 != null)
          this._Skill35.Click -= eventHandler;
        this._Skill35 = value;
        if (this._Skill35 == null)
          return;
        this._Skill35.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill36
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill36;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill36_Click);
        if (this._Skill36 != null)
          this._Skill36.Click -= eventHandler;
        this._Skill36 = value;
        if (this._Skill36 == null)
          return;
        this._Skill36.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill37
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill37;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill37_Click);
        if (this._Skill37 != null)
          this._Skill37.Click -= eventHandler;
        this._Skill37 = value;
        if (this._Skill37 == null)
          return;
        this._Skill37.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill38
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill38;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill38_Click);
        if (this._Skill38 != null)
          this._Skill38.Click -= eventHandler;
        this._Skill38 = value;
        if (this._Skill38 == null)
          return;
        this._Skill38.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill39
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill39;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill39_Click);
        if (this._Skill39 != null)
          this._Skill39.Click -= eventHandler;
        this._Skill39 = value;
        if (this._Skill39 == null)
          return;
        this._Skill39.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill40
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill40;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill40_Click);
        if (this._Skill40 != null)
          this._Skill40.Click -= eventHandler;
        this._Skill40 = value;
        if (this._Skill40 == null)
          return;
        this._Skill40.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill41
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill41;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill41_Click);
        if (this._Skill41 != null)
          this._Skill41.Click -= eventHandler;
        this._Skill41 = value;
        if (this._Skill41 == null)
          return;
        this._Skill41.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill42
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill42;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill42_Click);
        if (this._Skill42 != null)
          this._Skill42.Click -= eventHandler;
        this._Skill42 = value;
        if (this._Skill42 == null)
          return;
        this._Skill42.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill43
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill43;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill43_Click);
        if (this._Skill43 != null)
          this._Skill43.Click -= eventHandler;
        this._Skill43 = value;
        if (this._Skill43 == null)
          return;
        this._Skill43.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill44
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill44;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill44_Click);
        if (this._Skill44 != null)
          this._Skill44.Click -= eventHandler;
        this._Skill44 = value;
        if (this._Skill44 == null)
          return;
        this._Skill44.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill45
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill45;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill45_Click);
        if (this._Skill45 != null)
          this._Skill45.Click -= eventHandler;
        this._Skill45 = value;
        if (this._Skill45 == null)
          return;
        this._Skill45.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill46
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill46;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill46_Click);
        if (this._Skill46 != null)
          this._Skill46.Click -= eventHandler;
        this._Skill46 = value;
        if (this._Skill46 == null)
          return;
        this._Skill46.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill47
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill47;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill47_Click);
        if (this._Skill47 != null)
          this._Skill47.Click -= eventHandler;
        this._Skill47 = value;
        if (this._Skill47 == null)
          return;
        this._Skill47.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill48
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill48;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill48_Click);
        if (this._Skill48 != null)
          this._Skill48.Click -= eventHandler;
        this._Skill48 = value;
        if (this._Skill48 == null)
          return;
        this._Skill48.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill21
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill21;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill21_Click);
        if (this._Skill21 != null)
          this._Skill21.Click -= eventHandler;
        this._Skill21 = value;
        if (this._Skill21 == null)
          return;
        this._Skill21.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill22
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill22;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill22_Click);
        if (this._Skill22 != null)
          this._Skill22.Click -= eventHandler;
        this._Skill22 = value;
        if (this._Skill22 == null)
          return;
        this._Skill22.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill23
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill23;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill23_Click);
        if (this._Skill23 != null)
          this._Skill23.Click -= eventHandler;
        this._Skill23 = value;
        if (this._Skill23 == null)
          return;
        this._Skill23.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill24
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill24;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill24_Click);
        if (this._Skill24 != null)
          this._Skill24.Click -= eventHandler;
        this._Skill24 = value;
        if (this._Skill24 == null)
          return;
        this._Skill24.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill25
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill25;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill25_Click);
        if (this._Skill25 != null)
          this._Skill25.Click -= eventHandler;
        this._Skill25 = value;
        if (this._Skill25 == null)
          return;
        this._Skill25.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill26
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill26;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill26_Click);
        if (this._Skill26 != null)
          this._Skill26.Click -= eventHandler;
        this._Skill26 = value;
        if (this._Skill26 == null)
          return;
        this._Skill26.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill27
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill27;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill27_Click);
        if (this._Skill27 != null)
          this._Skill27.Click -= eventHandler;
        this._Skill27 = value;
        if (this._Skill27 == null)
          return;
        this._Skill27.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill28
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill28;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill28_Click);
        if (this._Skill28 != null)
          this._Skill28.Click -= eventHandler;
        this._Skill28 = value;
        if (this._Skill28 == null)
          return;
        this._Skill28.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill29
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill29;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill29_Click);
        if (this._Skill29 != null)
          this._Skill29.Click -= eventHandler;
        this._Skill29 = value;
        if (this._Skill29 == null)
          return;
        this._Skill29.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill49
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill49;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill49_Click);
        if (this._Skill49 != null)
          this._Skill49.Click -= eventHandler;
        this._Skill49 = value;
        if (this._Skill49 == null)
          return;
        this._Skill49.Click += eventHandler;
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

    internal virtual Button ClearSkills
    {
      [DebuggerNonUserCode] get
      {
        return this._ClearSkills;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_5);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_4);
        EventHandler eventHandler = new EventHandler(this.method_1);
        if (this._ClearSkills != null)
        {
          this._ClearSkills.MouseDown -= mouseEventHandler1;
          this._ClearSkills.MouseUp -= mouseEventHandler2;
          this._ClearSkills.Click -= eventHandler;
        }
        this._ClearSkills = value;
        if (this._ClearSkills == null)
          return;
        this._ClearSkills.MouseDown += mouseEventHandler1;
        this._ClearSkills.MouseUp += mouseEventHandler2;
        this._ClearSkills.Click += eventHandler;
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

    internal virtual PictureBox Skill50
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill50;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill50_Click);
        if (this._Skill50 != null)
          this._Skill50.Click -= eventHandler;
        this._Skill50 = value;
        if (this._Skill50 == null)
          return;
        this._Skill50.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill51
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill51;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill51_Click);
        if (this._Skill51 != null)
          this._Skill51.Click -= eventHandler;
        this._Skill51 = value;
        if (this._Skill51 == null)
          return;
        this._Skill51.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill52
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill52;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill52_Click);
        if (this._Skill52 != null)
          this._Skill52.Click -= eventHandler;
        this._Skill52 = value;
        if (this._Skill52 == null)
          return;
        this._Skill52.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill53
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill53;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill53_Click);
        if (this._Skill53 != null)
          this._Skill53.Click -= eventHandler;
        this._Skill53 = value;
        if (this._Skill53 == null)
          return;
        this._Skill53.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill54
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill54;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill54_Click);
        if (this._Skill54 != null)
          this._Skill54.Click -= eventHandler;
        this._Skill54 = value;
        if (this._Skill54 == null)
          return;
        this._Skill54.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill55
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill55;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill55_Click);
        if (this._Skill55 != null)
          this._Skill55.Click -= eventHandler;
        this._Skill55 = value;
        if (this._Skill55 == null)
          return;
        this._Skill55.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill56
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill56;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill56_Click);
        if (this._Skill56 != null)
          this._Skill56.Click -= eventHandler;
        this._Skill56 = value;
        if (this._Skill56 == null)
          return;
        this._Skill56.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill57
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill57;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill57_Click);
        if (this._Skill57 != null)
          this._Skill57.Click -= eventHandler;
        this._Skill57 = value;
        if (this._Skill57 == null)
          return;
        this._Skill57.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill58
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill58;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill58_Click);
        if (this._Skill58 != null)
          this._Skill58.Click -= eventHandler;
        this._Skill58 = value;
        if (this._Skill58 == null)
          return;
        this._Skill58.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill59
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill59;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill59_Click);
        if (this._Skill59 != null)
          this._Skill59.Click -= eventHandler;
        this._Skill59 = value;
        if (this._Skill59 == null)
          return;
        this._Skill59.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill60
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill60;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill60_Click);
        if (this._Skill60 != null)
          this._Skill60.Click -= eventHandler;
        this._Skill60 = value;
        if (this._Skill60 == null)
          return;
        this._Skill60.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill30
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill30;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill30_Click);
        if (this._Skill30 != null)
          this._Skill30.Click -= eventHandler;
        this._Skill30 = value;
        if (this._Skill30 == null)
          return;
        this._Skill30.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill11
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill11;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill11_Click);
        if (this._Skill11 != null)
          this._Skill11.Click -= eventHandler;
        this._Skill11 = value;
        if (this._Skill11 == null)
          return;
        this._Skill11.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill12
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill12;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill12_Click);
        if (this._Skill12 != null)
          this._Skill12.Click -= eventHandler;
        this._Skill12 = value;
        if (this._Skill12 == null)
          return;
        this._Skill12.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill13
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill13;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill13_Click);
        if (this._Skill13 != null)
          this._Skill13.Click -= eventHandler;
        this._Skill13 = value;
        if (this._Skill13 == null)
          return;
        this._Skill13.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill14
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill14;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill14_Click);
        if (this._Skill14 != null)
          this._Skill14.Click -= eventHandler;
        this._Skill14 = value;
        if (this._Skill14 == null)
          return;
        this._Skill14.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill15
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill15;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill15_Click);
        if (this._Skill15 != null)
          this._Skill15.Click -= eventHandler;
        this._Skill15 = value;
        if (this._Skill15 == null)
          return;
        this._Skill15.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill16
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill16;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill16_Click);
        if (this._Skill16 != null)
          this._Skill16.Click -= eventHandler;
        this._Skill16 = value;
        if (this._Skill16 == null)
          return;
        this._Skill16.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill17
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill17;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill17_Click);
        if (this._Skill17 != null)
          this._Skill17.Click -= eventHandler;
        this._Skill17 = value;
        if (this._Skill17 == null)
          return;
        this._Skill17.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill18
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill18;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill18_Click);
        if (this._Skill18 != null)
          this._Skill18.Click -= eventHandler;
        this._Skill18 = value;
        if (this._Skill18 == null)
          return;
        this._Skill18.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill20
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill20;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill20_Click);
        if (this._Skill20 != null)
          this._Skill20.Click -= eventHandler;
        this._Skill20 = value;
        if (this._Skill20 == null)
          return;
        this._Skill20.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill19
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill19;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill19_Click);
        if (this._Skill19 != null)
          this._Skill19.Click -= eventHandler;
        this._Skill19 = value;
        if (this._Skill19 == null)
          return;
        this._Skill19.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill10
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill10;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill10_Click);
        if (this._Skill10 != null)
          this._Skill10.Click -= eventHandler;
        this._Skill10 = value;
        if (this._Skill10 == null)
          return;
        this._Skill10.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill9
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill9;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill9_Click);
        if (this._Skill9 != null)
          this._Skill9.Click -= eventHandler;
        this._Skill9 = value;
        if (this._Skill9 == null)
          return;
        this._Skill9.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill8
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill8;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill8_Click);
        if (this._Skill8 != null)
          this._Skill8.Click -= eventHandler;
        this._Skill8 = value;
        if (this._Skill8 == null)
          return;
        this._Skill8.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill7
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill7;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill7_Click);
        if (this._Skill7 != null)
          this._Skill7.Click -= eventHandler;
        this._Skill7 = value;
        if (this._Skill7 == null)
          return;
        this._Skill7.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill6
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill6;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill6_Click);
        if (this._Skill6 != null)
          this._Skill6.Click -= eventHandler;
        this._Skill6 = value;
        if (this._Skill6 == null)
          return;
        this._Skill6.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill5
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill5;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill5_Click);
        if (this._Skill5 != null)
          this._Skill5.Click -= eventHandler;
        this._Skill5 = value;
        if (this._Skill5 == null)
          return;
        this._Skill5.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill4
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill4;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill4_Click);
        if (this._Skill4 != null)
          this._Skill4.Click -= eventHandler;
        this._Skill4 = value;
        if (this._Skill4 == null)
          return;
        this._Skill4.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill3
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill3;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill3_Click);
        if (this._Skill3 != null)
          this._Skill3.Click -= eventHandler;
        this._Skill3 = value;
        if (this._Skill3 == null)
          return;
        this._Skill3.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill1
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill1_Click);
        if (this._Skill1 != null)
          this._Skill1.Click -= eventHandler;
        this._Skill1 = value;
        if (this._Skill1 == null)
          return;
        this._Skill1.Click += eventHandler;
      }
    }

    internal virtual PictureBox Skill2
    {
      [DebuggerNonUserCode] get
      {
        return this._Skill2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Skill2_Click);
        if (this._Skill2 != null)
          this._Skill2.Click -= eventHandler;
        this._Skill2 = value;
        if (this._Skill2 == null)
          return;
        this._Skill2.Click += eventHandler;
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

    internal virtual ListBox Tipo
    {
      [DebuggerNonUserCode] get
      {
        return this._Tipo;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Tipo_SelectedIndexChanged);
        if (this._Tipo != null)
          this._Tipo.SelectedIndexChanged -= eventHandler;
        this._Tipo = value;
        if (this._Tipo == null)
          return;
        this._Tipo.SelectedIndexChanged += eventHandler;
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
        EventHandler eventHandler = new EventHandler(this.method_0);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_11);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_10);
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

    internal virtual Button Cerrar
    {
      [DebuggerNonUserCode] get
      {
        return this._Cerrar;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_3);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_9);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_8);
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

    internal virtual Button Minimizar
    {
      [DebuggerNonUserCode] get
      {
        return this._Minimizar;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_2);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_7);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_6);
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

    internal virtual Label SkillTipo
    {
      [DebuggerNonUserCode] get
      {
        return this._SkillTipo;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._SkillTipo = value;
      }
    }

    internal virtual Label SkillRango
    {
      [DebuggerNonUserCode] get
      {
        return this._SkillRango;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._SkillRango = value;
      }
    }

    internal virtual Label Mana
    {
      [DebuggerNonUserCode] get
      {
        return this._Mana;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Mana = value;
      }
    }

    internal virtual Label Estamina
    {
      [DebuggerNonUserCode] get
      {
        return this._Estamina;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Estamina = value;
      }
    }

    internal virtual Label CuentaSkill
    {
      [DebuggerNonUserCode] get
      {
        return this._CuentaSkill;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._CuentaSkill = value;
      }
    }

    internal virtual Label ChartSkill
    {
      [DebuggerNonUserCode] get
      {
        return this._ChartSkill;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._ChartSkill = value;
      }
    }

    internal virtual Label NombreClase
    {
      [DebuggerNonUserCode] get
      {
        return this._NombreClase;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._NombreClase = value;
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

    public static SkillMaker DefInstance
    {
      get
      {
        if (SkillMaker.skillMaker_0 != null && !SkillMaker.skillMaker_0.IsDisposed)
          SkillMaker.skillMaker_0.BringToFront();
        else
          SkillMaker.skillMaker_0 = new SkillMaker();
        return SkillMaker.skillMaker_0;
      }
      set
      {
        SkillMaker.skillMaker_0 = value;
      }
    }

    [DebuggerNonUserCode]
    public SkillMaker()
    {
      this.Closing += new CancelEventHandler(this.SkillMaker_Closing);
      this.Load += new EventHandler(this.SkillMaker_Load);
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
      ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof (SkillMaker));
      this.Emergente = new ToolTip(this.icontainer_0);
      this.Skill31 = new PictureBox();
      this.Skill32 = new PictureBox();
      this.Skill33 = new PictureBox();
      this.Skill34 = new PictureBox();
      this.Skill35 = new PictureBox();
      this.Skill36 = new PictureBox();
      this.Skill37 = new PictureBox();
      this.Skill38 = new PictureBox();
      this.Skill39 = new PictureBox();
      this.Skill40 = new PictureBox();
      this.Skill41 = new PictureBox();
      this.Skill42 = new PictureBox();
      this.Skill43 = new PictureBox();
      this.Skill44 = new PictureBox();
      this.Skill45 = new PictureBox();
      this.Skill46 = new PictureBox();
      this.Skill47 = new PictureBox();
      this.Skill48 = new PictureBox();
      this.Skill21 = new PictureBox();
      this.Skill22 = new PictureBox();
      this.Skill23 = new PictureBox();
      this.Skill24 = new PictureBox();
      this.Skill25 = new PictureBox();
      this.Skill26 = new PictureBox();
      this.Skill27 = new PictureBox();
      this.Skill28 = new PictureBox();
      this.Skill29 = new PictureBox();
      this.Skill49 = new PictureBox();
      this.Label6 = new Label();
      this.OnlineOFF = new PictureBox();
      this.OnlineON = new PictureBox();
      this.ClearSkills = new Button();
      this.ONLineInfo = new Button();
      this.Skill50 = new PictureBox();
      this.Skill51 = new PictureBox();
      this.Skill52 = new PictureBox();
      this.Skill53 = new PictureBox();
      this.Skill54 = new PictureBox();
      this.Skill55 = new PictureBox();
      this.Skill56 = new PictureBox();
      this.Skill57 = new PictureBox();
      this.Skill58 = new PictureBox();
      this.Skill59 = new PictureBox();
      this.Skill60 = new PictureBox();
      this.Skill30 = new PictureBox();
      this.Skill11 = new PictureBox();
      this.Skill12 = new PictureBox();
      this.Skill13 = new PictureBox();
      this.Skill14 = new PictureBox();
      this.Skill15 = new PictureBox();
      this.Skill16 = new PictureBox();
      this.Skill17 = new PictureBox();
      this.Skill18 = new PictureBox();
      this.Skill20 = new PictureBox();
      this.Skill19 = new PictureBox();
      this.Skill10 = new PictureBox();
      this.Skill9 = new PictureBox();
      this.Skill8 = new PictureBox();
      this.Skill7 = new PictureBox();
      this.Skill6 = new PictureBox();
      this.Skill5 = new PictureBox();
      this.Skill4 = new PictureBox();
      this.Skill3 = new PictureBox();
      this.Skill1 = new PictureBox();
      this.Skill2 = new PictureBox();
      this.PersonajeSearch = new TextBox();
      this.CuentaSearch = new TextBox();
      this.Foto = new Label();
      this.Imagen = new PictureBox();
      this.Items = new ListBox();
      this.Tipo = new ListBox();
      this.Account = new Label();
      this.Personajes = new ComboBox();
      this.Cuentas = new ComboBox();
      this.Chart = new Label();
      this.Reloj = new System.Windows.Forms.Timer(this.icontainer_0);
      this.Buscar = new Button();
      this.Cerrar = new Button();
      this.Minimizar = new Button();
      this.SkillTipo = new Label();
      this.SkillRango = new Label();
      this.Mana = new Label();
      this.Estamina = new Label();
      this.CuentaSkill = new Label();
      this.ChartSkill = new Label();
      this.NombreClase = new Label();
      this.Titulo = new Label();
      ((ISupportInitialize) this.Skill31).BeginInit();
      ((ISupportInitialize) this.Skill32).BeginInit();
      ((ISupportInitialize) this.Skill33).BeginInit();
      ((ISupportInitialize) this.Skill34).BeginInit();
      ((ISupportInitialize) this.Skill35).BeginInit();
      ((ISupportInitialize) this.Skill36).BeginInit();
      ((ISupportInitialize) this.Skill37).BeginInit();
      ((ISupportInitialize) this.Skill38).BeginInit();
      ((ISupportInitialize) this.Skill39).BeginInit();
      ((ISupportInitialize) this.Skill40).BeginInit();
      ((ISupportInitialize) this.Skill41).BeginInit();
      ((ISupportInitialize) this.Skill42).BeginInit();
      ((ISupportInitialize) this.Skill43).BeginInit();
      ((ISupportInitialize) this.Skill44).BeginInit();
      ((ISupportInitialize) this.Skill45).BeginInit();
      ((ISupportInitialize) this.Skill46).BeginInit();
      ((ISupportInitialize) this.Skill47).BeginInit();
      ((ISupportInitialize) this.Skill48).BeginInit();
      ((ISupportInitialize) this.Skill21).BeginInit();
      ((ISupportInitialize) this.Skill22).BeginInit();
      ((ISupportInitialize) this.Skill23).BeginInit();
      ((ISupportInitialize) this.Skill24).BeginInit();
      ((ISupportInitialize) this.Skill25).BeginInit();
      ((ISupportInitialize) this.Skill26).BeginInit();
      ((ISupportInitialize) this.Skill27).BeginInit();
      ((ISupportInitialize) this.Skill28).BeginInit();
      ((ISupportInitialize) this.Skill29).BeginInit();
      ((ISupportInitialize) this.Skill49).BeginInit();
      ((ISupportInitialize) this.OnlineOFF).BeginInit();
      ((ISupportInitialize) this.OnlineON).BeginInit();
      ((ISupportInitialize) this.Skill50).BeginInit();
      ((ISupportInitialize) this.Skill51).BeginInit();
      ((ISupportInitialize) this.Skill52).BeginInit();
      ((ISupportInitialize) this.Skill53).BeginInit();
      ((ISupportInitialize) this.Skill54).BeginInit();
      ((ISupportInitialize) this.Skill55).BeginInit();
      ((ISupportInitialize) this.Skill56).BeginInit();
      ((ISupportInitialize) this.Skill57).BeginInit();
      ((ISupportInitialize) this.Skill58).BeginInit();
      ((ISupportInitialize) this.Skill59).BeginInit();
      ((ISupportInitialize) this.Skill60).BeginInit();
      ((ISupportInitialize) this.Skill30).BeginInit();
      ((ISupportInitialize) this.Skill11).BeginInit();
      ((ISupportInitialize) this.Skill12).BeginInit();
      ((ISupportInitialize) this.Skill13).BeginInit();
      ((ISupportInitialize) this.Skill14).BeginInit();
      ((ISupportInitialize) this.Skill15).BeginInit();
      ((ISupportInitialize) this.Skill16).BeginInit();
      ((ISupportInitialize) this.Skill17).BeginInit();
      ((ISupportInitialize) this.Skill18).BeginInit();
      ((ISupportInitialize) this.Skill20).BeginInit();
      ((ISupportInitialize) this.Skill19).BeginInit();
      ((ISupportInitialize) this.Skill10).BeginInit();
      ((ISupportInitialize) this.Skill9).BeginInit();
      ((ISupportInitialize) this.Skill8).BeginInit();
      ((ISupportInitialize) this.Skill7).BeginInit();
      ((ISupportInitialize) this.Skill6).BeginInit();
      ((ISupportInitialize) this.Skill5).BeginInit();
      ((ISupportInitialize) this.Skill4).BeginInit();
      ((ISupportInitialize) this.Skill3).BeginInit();
      ((ISupportInitialize) this.Skill1).BeginInit();
      ((ISupportInitialize) this.Skill2).BeginInit();
      ((ISupportInitialize) this.Imagen).BeginInit();
      this.SuspendLayout();
      this.Emergente.AutomaticDelay = 5000;
      this.Emergente.AutoPopDelay = 500000;
      this.Emergente.InitialDelay = 5;
      this.Emergente.ReshowDelay = 1;
      this.Skill31.BackColor = Color.DimGray;
      this.Skill31.BackgroundImage = (Image) componentResourceManager.GetObject("Skill31.BackgroundImage");
      this.Skill31.Cursor = Cursors.Hand;
      this.Skill31.ImeMode = ImeMode.NoControl;
      PictureBox skill31_1 = this.Skill31;
      Point point1 = new Point(18, 432);
      Point point2 = point1;
      skill31_1.Location = point2;
      this.Skill31.Name = "Skill31";
      PictureBox skill31_2 = this.Skill31;
      Size size1 = new Size(34, 35);
      Size size2 = size1;
      skill31_2.Size = size2;
      this.Skill31.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill31.TabIndex = 422;
      this.Skill31.TabStop = false;
      this.Skill32.BackColor = Color.DimGray;
      this.Skill32.BackgroundImage = (Image) componentResourceManager.GetObject("Skill32.BackgroundImage");
      this.Skill32.Cursor = Cursors.Hand;
      this.Skill32.ImeMode = ImeMode.NoControl;
      PictureBox skill32_1 = this.Skill32;
      point1 = new Point(52, 432);
      Point point3 = point1;
      skill32_1.Location = point3;
      this.Skill32.Name = "Skill32";
      PictureBox skill32_2 = this.Skill32;
      size1 = new Size(34, 35);
      Size size3 = size1;
      skill32_2.Size = size3;
      this.Skill32.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill32.TabIndex = 421;
      this.Skill32.TabStop = false;
      this.Skill33.BackColor = Color.DimGray;
      this.Skill33.BackgroundImage = (Image) componentResourceManager.GetObject("Skill33.BackgroundImage");
      this.Skill33.Cursor = Cursors.Hand;
      this.Skill33.ImeMode = ImeMode.NoControl;
      PictureBox skill33_1 = this.Skill33;
      point1 = new Point(86, 432);
      Point point4 = point1;
      skill33_1.Location = point4;
      this.Skill33.Name = "Skill33";
      PictureBox skill33_2 = this.Skill33;
      size1 = new Size(34, 35);
      Size size4 = size1;
      skill33_2.Size = size4;
      this.Skill33.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill33.TabIndex = 420;
      this.Skill33.TabStop = false;
      this.Skill34.BackColor = Color.DimGray;
      this.Skill34.BackgroundImage = (Image) componentResourceManager.GetObject("Skill34.BackgroundImage");
      this.Skill34.Cursor = Cursors.Hand;
      this.Skill34.ImeMode = ImeMode.NoControl;
      PictureBox skill34_1 = this.Skill34;
      point1 = new Point(120, 432);
      Point point5 = point1;
      skill34_1.Location = point5;
      this.Skill34.Name = "Skill34";
      PictureBox skill34_2 = this.Skill34;
      size1 = new Size(34, 35);
      Size size5 = size1;
      skill34_2.Size = size5;
      this.Skill34.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill34.TabIndex = 419;
      this.Skill34.TabStop = false;
      this.Skill35.BackColor = Color.DimGray;
      this.Skill35.BackgroundImage = (Image) componentResourceManager.GetObject("Skill35.BackgroundImage");
      this.Skill35.Cursor = Cursors.Hand;
      this.Skill35.ImeMode = ImeMode.NoControl;
      PictureBox skill35_1 = this.Skill35;
      point1 = new Point(154, 432);
      Point point6 = point1;
      skill35_1.Location = point6;
      this.Skill35.Name = "Skill35";
      PictureBox skill35_2 = this.Skill35;
      size1 = new Size(34, 35);
      Size size6 = size1;
      skill35_2.Size = size6;
      this.Skill35.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill35.TabIndex = 418;
      this.Skill35.TabStop = false;
      this.Skill36.BackColor = Color.DimGray;
      this.Skill36.BackgroundImage = (Image) componentResourceManager.GetObject("Skill36.BackgroundImage");
      this.Skill36.Cursor = Cursors.Hand;
      this.Skill36.ImeMode = ImeMode.NoControl;
      PictureBox skill36_1 = this.Skill36;
      point1 = new Point(188, 432);
      Point point7 = point1;
      skill36_1.Location = point7;
      this.Skill36.Name = "Skill36";
      PictureBox skill36_2 = this.Skill36;
      size1 = new Size(34, 35);
      Size size7 = size1;
      skill36_2.Size = size7;
      this.Skill36.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill36.TabIndex = 417;
      this.Skill36.TabStop = false;
      this.Skill37.BackColor = Color.DimGray;
      this.Skill37.BackgroundImage = (Image) componentResourceManager.GetObject("Skill37.BackgroundImage");
      this.Skill37.Cursor = Cursors.Hand;
      this.Skill37.ImeMode = ImeMode.NoControl;
      PictureBox skill37_1 = this.Skill37;
      point1 = new Point(222, 432);
      Point point8 = point1;
      skill37_1.Location = point8;
      this.Skill37.Name = "Skill37";
      PictureBox skill37_2 = this.Skill37;
      size1 = new Size(34, 35);
      Size size8 = size1;
      skill37_2.Size = size8;
      this.Skill37.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill37.TabIndex = 416;
      this.Skill37.TabStop = false;
      this.Skill38.BackColor = Color.DimGray;
      this.Skill38.BackgroundImage = (Image) componentResourceManager.GetObject("Skill38.BackgroundImage");
      this.Skill38.Cursor = Cursors.Hand;
      this.Skill38.ImeMode = ImeMode.NoControl;
      PictureBox skill38_1 = this.Skill38;
      point1 = new Point(256, 432);
      Point point9 = point1;
      skill38_1.Location = point9;
      this.Skill38.Name = "Skill38";
      PictureBox skill38_2 = this.Skill38;
      size1 = new Size(34, 35);
      Size size9 = size1;
      skill38_2.Size = size9;
      this.Skill38.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill38.TabIndex = 415;
      this.Skill38.TabStop = false;
      this.Skill39.BackColor = Color.DimGray;
      this.Skill39.BackgroundImage = (Image) componentResourceManager.GetObject("Skill39.BackgroundImage");
      this.Skill39.Cursor = Cursors.Hand;
      this.Skill39.ImeMode = ImeMode.NoControl;
      PictureBox skill39_1 = this.Skill39;
      point1 = new Point(290, 432);
      Point point10 = point1;
      skill39_1.Location = point10;
      this.Skill39.Name = "Skill39";
      PictureBox skill39_2 = this.Skill39;
      size1 = new Size(34, 35);
      Size size10 = size1;
      skill39_2.Size = size10;
      this.Skill39.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill39.TabIndex = 414;
      this.Skill39.TabStop = false;
      this.Skill40.BackColor = Color.DimGray;
      this.Skill40.BackgroundImage = (Image) componentResourceManager.GetObject("Skill40.BackgroundImage");
      this.Skill40.Cursor = Cursors.Hand;
      this.Skill40.ImeMode = ImeMode.NoControl;
      PictureBox skill40_1 = this.Skill40;
      point1 = new Point(324, 432);
      Point point11 = point1;
      skill40_1.Location = point11;
      this.Skill40.Name = "Skill40";
      PictureBox skill40_2 = this.Skill40;
      size1 = new Size(34, 35);
      Size size11 = size1;
      skill40_2.Size = size11;
      this.Skill40.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill40.TabIndex = 413;
      this.Skill40.TabStop = false;
      this.Skill41.BackColor = Color.DimGray;
      this.Skill41.BackgroundImage = (Image) componentResourceManager.GetObject("Skill41.BackgroundImage");
      this.Skill41.Cursor = Cursors.Hand;
      this.Skill41.ImeMode = ImeMode.NoControl;
      PictureBox skill41_1 = this.Skill41;
      point1 = new Point(18, 468);
      Point point12 = point1;
      skill41_1.Location = point12;
      this.Skill41.Name = "Skill41";
      PictureBox skill41_2 = this.Skill41;
      size1 = new Size(34, 35);
      Size size12 = size1;
      skill41_2.Size = size12;
      this.Skill41.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill41.TabIndex = 412;
      this.Skill41.TabStop = false;
      this.Skill42.BackColor = Color.DimGray;
      this.Skill42.BackgroundImage = (Image) componentResourceManager.GetObject("Skill42.BackgroundImage");
      this.Skill42.Cursor = Cursors.Hand;
      this.Skill42.ImeMode = ImeMode.NoControl;
      PictureBox skill42_1 = this.Skill42;
      point1 = new Point(52, 468);
      Point point13 = point1;
      skill42_1.Location = point13;
      this.Skill42.Name = "Skill42";
      PictureBox skill42_2 = this.Skill42;
      size1 = new Size(34, 35);
      Size size13 = size1;
      skill42_2.Size = size13;
      this.Skill42.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill42.TabIndex = 411;
      this.Skill42.TabStop = false;
      this.Skill43.BackColor = Color.DimGray;
      this.Skill43.BackgroundImage = (Image) componentResourceManager.GetObject("Skill43.BackgroundImage");
      this.Skill43.Cursor = Cursors.Hand;
      this.Skill43.ImeMode = ImeMode.NoControl;
      PictureBox skill43_1 = this.Skill43;
      point1 = new Point(86, 468);
      Point point14 = point1;
      skill43_1.Location = point14;
      this.Skill43.Name = "Skill43";
      PictureBox skill43_2 = this.Skill43;
      size1 = new Size(34, 35);
      Size size14 = size1;
      skill43_2.Size = size14;
      this.Skill43.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill43.TabIndex = 410;
      this.Skill43.TabStop = false;
      this.Skill44.BackColor = Color.DimGray;
      this.Skill44.BackgroundImage = (Image) componentResourceManager.GetObject("Skill44.BackgroundImage");
      this.Skill44.Cursor = Cursors.Hand;
      this.Skill44.ImeMode = ImeMode.NoControl;
      PictureBox skill44_1 = this.Skill44;
      point1 = new Point(120, 468);
      Point point15 = point1;
      skill44_1.Location = point15;
      this.Skill44.Name = "Skill44";
      PictureBox skill44_2 = this.Skill44;
      size1 = new Size(34, 35);
      Size size15 = size1;
      skill44_2.Size = size15;
      this.Skill44.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill44.TabIndex = 409;
      this.Skill44.TabStop = false;
      this.Skill45.BackColor = Color.DimGray;
      this.Skill45.BackgroundImage = (Image) componentResourceManager.GetObject("Skill45.BackgroundImage");
      this.Skill45.Cursor = Cursors.Hand;
      this.Skill45.ImeMode = ImeMode.NoControl;
      PictureBox skill45_1 = this.Skill45;
      point1 = new Point(154, 468);
      Point point16 = point1;
      skill45_1.Location = point16;
      this.Skill45.Name = "Skill45";
      PictureBox skill45_2 = this.Skill45;
      size1 = new Size(34, 35);
      Size size16 = size1;
      skill45_2.Size = size16;
      this.Skill45.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill45.TabIndex = 408;
      this.Skill45.TabStop = false;
      this.Skill46.BackColor = Color.DimGray;
      this.Skill46.BackgroundImage = (Image) componentResourceManager.GetObject("Skill46.BackgroundImage");
      this.Skill46.Cursor = Cursors.Hand;
      this.Skill46.ImeMode = ImeMode.NoControl;
      PictureBox skill46_1 = this.Skill46;
      point1 = new Point(188, 468);
      Point point17 = point1;
      skill46_1.Location = point17;
      this.Skill46.Name = "Skill46";
      PictureBox skill46_2 = this.Skill46;
      size1 = new Size(34, 35);
      Size size17 = size1;
      skill46_2.Size = size17;
      this.Skill46.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill46.TabIndex = 407;
      this.Skill46.TabStop = false;
      this.Skill47.BackColor = Color.DimGray;
      this.Skill47.BackgroundImage = (Image) componentResourceManager.GetObject("Skill47.BackgroundImage");
      this.Skill47.Cursor = Cursors.Hand;
      this.Skill47.ImeMode = ImeMode.NoControl;
      PictureBox skill47_1 = this.Skill47;
      point1 = new Point(222, 468);
      Point point18 = point1;
      skill47_1.Location = point18;
      this.Skill47.Name = "Skill47";
      PictureBox skill47_2 = this.Skill47;
      size1 = new Size(34, 35);
      Size size18 = size1;
      skill47_2.Size = size18;
      this.Skill47.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill47.TabIndex = 406;
      this.Skill47.TabStop = false;
      this.Skill48.BackColor = Color.DimGray;
      this.Skill48.BackgroundImage = (Image) componentResourceManager.GetObject("Skill48.BackgroundImage");
      this.Skill48.Cursor = Cursors.Hand;
      this.Skill48.ImeMode = ImeMode.NoControl;
      PictureBox skill48_1 = this.Skill48;
      point1 = new Point(256, 468);
      Point point19 = point1;
      skill48_1.Location = point19;
      this.Skill48.Name = "Skill48";
      PictureBox skill48_2 = this.Skill48;
      size1 = new Size(34, 35);
      Size size19 = size1;
      skill48_2.Size = size19;
      this.Skill48.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill48.TabIndex = 405;
      this.Skill48.TabStop = false;
      this.Skill21.BackColor = Color.DimGray;
      this.Skill21.BackgroundImage = (Image) componentResourceManager.GetObject("Skill21.BackgroundImage");
      this.Skill21.Cursor = Cursors.Hand;
      this.Skill21.ImeMode = ImeMode.NoControl;
      PictureBox skill21_1 = this.Skill21;
      point1 = new Point(18, 396);
      Point point20 = point1;
      skill21_1.Location = point20;
      this.Skill21.Name = "Skill21";
      PictureBox skill21_2 = this.Skill21;
      size1 = new Size(34, 35);
      Size size20 = size1;
      skill21_2.Size = size20;
      this.Skill21.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill21.TabIndex = 392;
      this.Skill21.TabStop = false;
      this.Skill22.BackColor = Color.DimGray;
      this.Skill22.BackgroundImage = (Image) componentResourceManager.GetObject("Skill22.BackgroundImage");
      this.Skill22.Cursor = Cursors.Hand;
      this.Skill22.ImeMode = ImeMode.NoControl;
      PictureBox skill22_1 = this.Skill22;
      point1 = new Point(52, 396);
      Point point21 = point1;
      skill22_1.Location = point21;
      this.Skill22.Name = "Skill22";
      PictureBox skill22_2 = this.Skill22;
      size1 = new Size(34, 35);
      Size size21 = size1;
      skill22_2.Size = size21;
      this.Skill22.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill22.TabIndex = 391;
      this.Skill22.TabStop = false;
      this.Skill23.BackColor = Color.DimGray;
      this.Skill23.BackgroundImage = (Image) componentResourceManager.GetObject("Skill23.BackgroundImage");
      this.Skill23.Cursor = Cursors.Hand;
      this.Skill23.ImeMode = ImeMode.NoControl;
      PictureBox skill23_1 = this.Skill23;
      point1 = new Point(86, 396);
      Point point22 = point1;
      skill23_1.Location = point22;
      this.Skill23.Name = "Skill23";
      PictureBox skill23_2 = this.Skill23;
      size1 = new Size(34, 35);
      Size size22 = size1;
      skill23_2.Size = size22;
      this.Skill23.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill23.TabIndex = 390;
      this.Skill23.TabStop = false;
      this.Skill24.BackColor = Color.DimGray;
      this.Skill24.BackgroundImage = (Image) componentResourceManager.GetObject("Skill24.BackgroundImage");
      this.Skill24.Cursor = Cursors.Hand;
      this.Skill24.ImeMode = ImeMode.NoControl;
      PictureBox skill24_1 = this.Skill24;
      point1 = new Point(120, 396);
      Point point23 = point1;
      skill24_1.Location = point23;
      this.Skill24.Name = "Skill24";
      PictureBox skill24_2 = this.Skill24;
      size1 = new Size(34, 35);
      Size size23 = size1;
      skill24_2.Size = size23;
      this.Skill24.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill24.TabIndex = 389;
      this.Skill24.TabStop = false;
      this.Skill25.BackColor = Color.DimGray;
      this.Skill25.BackgroundImage = (Image) componentResourceManager.GetObject("Skill25.BackgroundImage");
      this.Skill25.Cursor = Cursors.Hand;
      this.Skill25.ImeMode = ImeMode.NoControl;
      PictureBox skill25_1 = this.Skill25;
      point1 = new Point(154, 396);
      Point point24 = point1;
      skill25_1.Location = point24;
      this.Skill25.Name = "Skill25";
      PictureBox skill25_2 = this.Skill25;
      size1 = new Size(34, 35);
      Size size24 = size1;
      skill25_2.Size = size24;
      this.Skill25.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill25.TabIndex = 388;
      this.Skill25.TabStop = false;
      this.Skill26.BackColor = Color.DimGray;
      this.Skill26.BackgroundImage = (Image) componentResourceManager.GetObject("Skill26.BackgroundImage");
      this.Skill26.Cursor = Cursors.Hand;
      this.Skill26.ImeMode = ImeMode.NoControl;
      PictureBox skill26_1 = this.Skill26;
      point1 = new Point(188, 396);
      Point point25 = point1;
      skill26_1.Location = point25;
      this.Skill26.Name = "Skill26";
      PictureBox skill26_2 = this.Skill26;
      size1 = new Size(34, 35);
      Size size25 = size1;
      skill26_2.Size = size25;
      this.Skill26.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill26.TabIndex = 387;
      this.Skill26.TabStop = false;
      this.Skill27.BackColor = Color.DimGray;
      this.Skill27.BackgroundImage = (Image) componentResourceManager.GetObject("Skill27.BackgroundImage");
      this.Skill27.Cursor = Cursors.Hand;
      this.Skill27.ImeMode = ImeMode.NoControl;
      PictureBox skill27_1 = this.Skill27;
      point1 = new Point(222, 396);
      Point point26 = point1;
      skill27_1.Location = point26;
      this.Skill27.Name = "Skill27";
      PictureBox skill27_2 = this.Skill27;
      size1 = new Size(34, 35);
      Size size26 = size1;
      skill27_2.Size = size26;
      this.Skill27.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill27.TabIndex = 386;
      this.Skill27.TabStop = false;
      this.Skill28.BackColor = Color.DimGray;
      this.Skill28.BackgroundImage = (Image) componentResourceManager.GetObject("Skill28.BackgroundImage");
      this.Skill28.Cursor = Cursors.Hand;
      this.Skill28.ImeMode = ImeMode.NoControl;
      PictureBox skill28_1 = this.Skill28;
      point1 = new Point(256, 396);
      Point point27 = point1;
      skill28_1.Location = point27;
      this.Skill28.Name = "Skill28";
      PictureBox skill28_2 = this.Skill28;
      size1 = new Size(34, 35);
      Size size27 = size1;
      skill28_2.Size = size27;
      this.Skill28.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill28.TabIndex = 385;
      this.Skill28.TabStop = false;
      this.Skill29.BackColor = Color.DimGray;
      this.Skill29.BackgroundImage = (Image) componentResourceManager.GetObject("Skill29.BackgroundImage");
      this.Skill29.Cursor = Cursors.Hand;
      this.Skill29.ImeMode = ImeMode.NoControl;
      PictureBox skill29_1 = this.Skill29;
      point1 = new Point(290, 396);
      Point point28 = point1;
      skill29_1.Location = point28;
      this.Skill29.Name = "Skill29";
      PictureBox skill29_2 = this.Skill29;
      size1 = new Size(34, 35);
      Size size28 = size1;
      skill29_2.Size = size28;
      this.Skill29.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill29.TabIndex = 384;
      this.Skill29.TabStop = false;
      this.Skill49.BackColor = Color.DimGray;
      this.Skill49.BackgroundImage = (Image) componentResourceManager.GetObject("Skill49.BackgroundImage");
      this.Skill49.Cursor = Cursors.Hand;
      this.Skill49.ImeMode = ImeMode.NoControl;
      PictureBox skill49_1 = this.Skill49;
      point1 = new Point(290, 468);
      Point point29 = point1;
      skill49_1.Location = point29;
      this.Skill49.Name = "Skill49";
      PictureBox skill49_2 = this.Skill49;
      size1 = new Size(34, 35);
      Size size29 = size1;
      skill49_2.Size = size29;
      this.Skill49.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill49.TabIndex = 404;
      this.Skill49.TabStop = false;
      this.Label6.BackColor = Color.Transparent;
      this.Label6.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label6.ForeColor = Color.DimGray;
      Label label6_1 = this.Label6;
      point1 = new Point(309, 253);
      Point point30 = point1;
      label6_1.Location = point30;
      this.Label6.Name = "Label6";
      Label label6_2 = this.Label6;
      size1 = new Size(46, 12);
      Size size30 = size1;
      label6_2.Size = size30;
      this.Label6.TabIndex = 426;
      this.Label6.Text = "Online";
      this.Label6.TextAlign = ContentAlignment.MiddleRight;
      this.OnlineOFF.BackColor = Color.Transparent;
      this.OnlineOFF.Image = (Image) componentResourceManager.GetObject("OnlineOFF.Image");
      PictureBox onlineOff1 = this.OnlineOFF;
      point1 = new Point(354, 253);
      Point point31 = point1;
      onlineOff1.Location = point31;
      this.OnlineOFF.Name = "OnlineOFF";
      PictureBox onlineOff2 = this.OnlineOFF;
      size1 = new Size(14, 14);
      Size size31 = size1;
      onlineOff2.Size = size31;
      this.OnlineOFF.TabIndex = 428;
      this.OnlineOFF.TabStop = false;
      this.OnlineON.BackColor = Color.Transparent;
      this.OnlineON.Image = (Image) componentResourceManager.GetObject("OnlineON.Image");
      PictureBox onlineOn1 = this.OnlineON;
      point1 = new Point(354, 253);
      Point point32 = point1;
      onlineOn1.Location = point32;
      this.OnlineON.Name = "OnlineON";
      PictureBox onlineOn2 = this.OnlineON;
      size1 = new Size(14, 14);
      Size size32 = size1;
      onlineOn2.Size = size32;
      this.OnlineON.TabIndex = 427;
      this.OnlineON.TabStop = false;
      this.OnlineON.Visible = false;
      this.ClearSkills.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.ClearSkills.BackgroundImage = (Image) EmbeddedResources.smethod_53();
      this.ClearSkills.BackgroundImageLayout = ImageLayout.Center;
      this.ClearSkills.Cursor = Cursors.Hand;
      this.ClearSkills.DialogResult = DialogResult.Cancel;
      this.ClearSkills.FlatAppearance.BorderSize = 0;
      this.ClearSkills.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.ClearSkills.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.ClearSkills.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.ClearSkills.FlatStyle = FlatStyle.Flat;
      this.ClearSkills.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.ClearSkills.ForeColor = Color.Transparent;
      Button clearSkills1 = this.ClearSkills;
      point1 = new Point(319, 275);
      Point point33 = point1;
      clearSkills1.Location = point33;
      this.ClearSkills.Name = "ClearSkills";
      Button clearSkills2 = this.ClearSkills;
      size1 = new Size(52, 28);
      Size size33 = size1;
      clearSkills2.Size = size33;
      this.ClearSkills.TabIndex = 425;
      this.ClearSkills.TabStop = false;
      this.ClearSkills.UseVisualStyleBackColor = false;
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
      point1 = new Point(297, 252);
      Point point34 = point1;
      onLineInfo1.Location = point34;
      this.ONLineInfo.Name = "ONLineInfo";
      Button onLineInfo2 = this.ONLineInfo;
      size1 = new Size(16, 16);
      Size size34 = size1;
      onLineInfo2.Size = size34;
      this.ONLineInfo.TabIndex = 432;
      this.ONLineInfo.TabStop = false;
      this.ONLineInfo.TextAlign = ContentAlignment.TopLeft;
      this.ONLineInfo.UseVisualStyleBackColor = false;
      this.Skill50.BackColor = Color.DimGray;
      this.Skill50.BackgroundImage = (Image) componentResourceManager.GetObject("Skill50.BackgroundImage");
      this.Skill50.Cursor = Cursors.Hand;
      this.Skill50.ImeMode = ImeMode.NoControl;
      PictureBox skill50_1 = this.Skill50;
      point1 = new Point(324, 468);
      Point point35 = point1;
      skill50_1.Location = point35;
      this.Skill50.Name = "Skill50";
      PictureBox skill50_2 = this.Skill50;
      size1 = new Size(34, 35);
      Size size35 = size1;
      skill50_2.Size = size35;
      this.Skill50.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill50.TabIndex = 403;
      this.Skill50.TabStop = false;
      this.Skill51.BackColor = Color.DimGray;
      this.Skill51.BackgroundImage = (Image) componentResourceManager.GetObject("Skill51.BackgroundImage");
      this.Skill51.Cursor = Cursors.Hand;
      this.Skill51.ImeMode = ImeMode.NoControl;
      PictureBox skill51_1 = this.Skill51;
      point1 = new Point(18, 504);
      Point point36 = point1;
      skill51_1.Location = point36;
      this.Skill51.Name = "Skill51";
      PictureBox skill51_2 = this.Skill51;
      size1 = new Size(34, 35);
      Size size36 = size1;
      skill51_2.Size = size36;
      this.Skill51.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill51.TabIndex = 402;
      this.Skill51.TabStop = false;
      this.Skill52.BackColor = Color.DimGray;
      this.Skill52.BackgroundImage = (Image) componentResourceManager.GetObject("Skill52.BackgroundImage");
      this.Skill52.Cursor = Cursors.Hand;
      this.Skill52.ImeMode = ImeMode.NoControl;
      PictureBox skill52_1 = this.Skill52;
      point1 = new Point(52, 504);
      Point point37 = point1;
      skill52_1.Location = point37;
      this.Skill52.Name = "Skill52";
      PictureBox skill52_2 = this.Skill52;
      size1 = new Size(34, 35);
      Size size37 = size1;
      skill52_2.Size = size37;
      this.Skill52.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill52.TabIndex = 401;
      this.Skill52.TabStop = false;
      this.Skill53.BackColor = Color.DimGray;
      this.Skill53.BackgroundImage = (Image) componentResourceManager.GetObject("Skill53.BackgroundImage");
      this.Skill53.Cursor = Cursors.Hand;
      this.Skill53.ImeMode = ImeMode.NoControl;
      PictureBox skill53_1 = this.Skill53;
      point1 = new Point(86, 504);
      Point point38 = point1;
      skill53_1.Location = point38;
      this.Skill53.Name = "Skill53";
      PictureBox skill53_2 = this.Skill53;
      size1 = new Size(34, 35);
      Size size38 = size1;
      skill53_2.Size = size38;
      this.Skill53.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill53.TabIndex = 400;
      this.Skill53.TabStop = false;
      this.Skill54.BackColor = Color.DimGray;
      this.Skill54.BackgroundImage = (Image) componentResourceManager.GetObject("Skill54.BackgroundImage");
      this.Skill54.Cursor = Cursors.Hand;
      this.Skill54.ImeMode = ImeMode.NoControl;
      PictureBox skill54_1 = this.Skill54;
      point1 = new Point(120, 504);
      Point point39 = point1;
      skill54_1.Location = point39;
      this.Skill54.Name = "Skill54";
      PictureBox skill54_2 = this.Skill54;
      size1 = new Size(34, 35);
      Size size39 = size1;
      skill54_2.Size = size39;
      this.Skill54.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill54.TabIndex = 399;
      this.Skill54.TabStop = false;
      this.Skill55.BackColor = Color.DimGray;
      this.Skill55.BackgroundImage = (Image) componentResourceManager.GetObject("Skill55.BackgroundImage");
      this.Skill55.Cursor = Cursors.Hand;
      this.Skill55.ImeMode = ImeMode.NoControl;
      PictureBox skill55_1 = this.Skill55;
      point1 = new Point(154, 504);
      Point point40 = point1;
      skill55_1.Location = point40;
      this.Skill55.Name = "Skill55";
      PictureBox skill55_2 = this.Skill55;
      size1 = new Size(34, 35);
      Size size40 = size1;
      skill55_2.Size = size40;
      this.Skill55.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill55.TabIndex = 398;
      this.Skill55.TabStop = false;
      this.Skill56.BackColor = Color.DimGray;
      this.Skill56.BackgroundImage = (Image) componentResourceManager.GetObject("Skill56.BackgroundImage");
      this.Skill56.Cursor = Cursors.Hand;
      this.Skill56.ImeMode = ImeMode.NoControl;
      PictureBox skill56_1 = this.Skill56;
      point1 = new Point(188, 504);
      Point point41 = point1;
      skill56_1.Location = point41;
      this.Skill56.Name = "Skill56";
      PictureBox skill56_2 = this.Skill56;
      size1 = new Size(34, 35);
      Size size41 = size1;
      skill56_2.Size = size41;
      this.Skill56.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill56.TabIndex = 397;
      this.Skill56.TabStop = false;
      this.Skill57.BackColor = Color.DimGray;
      this.Skill57.BackgroundImage = (Image) componentResourceManager.GetObject("Skill57.BackgroundImage");
      this.Skill57.Cursor = Cursors.Hand;
      this.Skill57.ImeMode = ImeMode.NoControl;
      PictureBox skill57_1 = this.Skill57;
      point1 = new Point(222, 504);
      Point point42 = point1;
      skill57_1.Location = point42;
      this.Skill57.Name = "Skill57";
      PictureBox skill57_2 = this.Skill57;
      size1 = new Size(34, 35);
      Size size42 = size1;
      skill57_2.Size = size42;
      this.Skill57.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill57.TabIndex = 396;
      this.Skill57.TabStop = false;
      this.Skill58.BackColor = Color.DimGray;
      this.Skill58.BackgroundImage = (Image) componentResourceManager.GetObject("Skill58.BackgroundImage");
      this.Skill58.Cursor = Cursors.Hand;
      this.Skill58.ImeMode = ImeMode.NoControl;
      PictureBox skill58_1 = this.Skill58;
      point1 = new Point(256, 504);
      Point point43 = point1;
      skill58_1.Location = point43;
      this.Skill58.Name = "Skill58";
      PictureBox skill58_2 = this.Skill58;
      size1 = new Size(34, 35);
      Size size43 = size1;
      skill58_2.Size = size43;
      this.Skill58.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill58.TabIndex = 395;
      this.Skill58.TabStop = false;
      this.Skill59.BackColor = Color.DimGray;
      this.Skill59.BackgroundImage = (Image) componentResourceManager.GetObject("Skill59.BackgroundImage");
      this.Skill59.Cursor = Cursors.Hand;
      this.Skill59.ImeMode = ImeMode.NoControl;
      PictureBox skill59_1 = this.Skill59;
      point1 = new Point(290, 504);
      Point point44 = point1;
      skill59_1.Location = point44;
      this.Skill59.Name = "Skill59";
      PictureBox skill59_2 = this.Skill59;
      size1 = new Size(34, 35);
      Size size44 = size1;
      skill59_2.Size = size44;
      this.Skill59.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill59.TabIndex = 394;
      this.Skill59.TabStop = false;
      this.Skill60.BackColor = Color.DimGray;
      this.Skill60.BackgroundImage = (Image) componentResourceManager.GetObject("Skill60.BackgroundImage");
      this.Skill60.Cursor = Cursors.Hand;
      this.Skill60.ImeMode = ImeMode.NoControl;
      PictureBox skill60_1 = this.Skill60;
      point1 = new Point(324, 504);
      Point point45 = point1;
      skill60_1.Location = point45;
      this.Skill60.Name = "Skill60";
      PictureBox skill60_2 = this.Skill60;
      size1 = new Size(34, 35);
      Size size45 = size1;
      skill60_2.Size = size45;
      this.Skill60.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill60.TabIndex = 393;
      this.Skill60.TabStop = false;
      this.Skill30.BackColor = Color.DimGray;
      this.Skill30.BackgroundImage = (Image) componentResourceManager.GetObject("Skill30.BackgroundImage");
      this.Skill30.Cursor = Cursors.Hand;
      this.Skill30.ImeMode = ImeMode.NoControl;
      PictureBox skill30_1 = this.Skill30;
      point1 = new Point(324, 396);
      Point point46 = point1;
      skill30_1.Location = point46;
      this.Skill30.Name = "Skill30";
      PictureBox skill30_2 = this.Skill30;
      size1 = new Size(34, 35);
      Size size46 = size1;
      skill30_2.Size = size46;
      this.Skill30.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill30.TabIndex = 383;
      this.Skill30.TabStop = false;
      this.Skill11.BackColor = Color.DimGray;
      this.Skill11.BackgroundImage = (Image) componentResourceManager.GetObject("Skill11.BackgroundImage");
      this.Skill11.Cursor = Cursors.Hand;
      this.Skill11.ImeMode = ImeMode.NoControl;
      PictureBox skill11_1 = this.Skill11;
      point1 = new Point(18, 360);
      Point point47 = point1;
      skill11_1.Location = point47;
      this.Skill11.Name = "Skill11";
      PictureBox skill11_2 = this.Skill11;
      size1 = new Size(34, 35);
      Size size47 = size1;
      skill11_2.Size = size47;
      this.Skill11.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill11.TabIndex = 382;
      this.Skill11.TabStop = false;
      this.Skill12.BackColor = Color.DimGray;
      this.Skill12.BackgroundImage = (Image) componentResourceManager.GetObject("Skill12.BackgroundImage");
      this.Skill12.Cursor = Cursors.Hand;
      this.Skill12.ImeMode = ImeMode.NoControl;
      PictureBox skill12_1 = this.Skill12;
      point1 = new Point(52, 360);
      Point point48 = point1;
      skill12_1.Location = point48;
      this.Skill12.Name = "Skill12";
      PictureBox skill12_2 = this.Skill12;
      size1 = new Size(34, 35);
      Size size48 = size1;
      skill12_2.Size = size48;
      this.Skill12.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill12.TabIndex = 381;
      this.Skill12.TabStop = false;
      this.Skill13.BackColor = Color.DimGray;
      this.Skill13.BackgroundImage = (Image) componentResourceManager.GetObject("Skill13.BackgroundImage");
      this.Skill13.Cursor = Cursors.Hand;
      this.Skill13.ImeMode = ImeMode.NoControl;
      PictureBox skill13_1 = this.Skill13;
      point1 = new Point(86, 360);
      Point point49 = point1;
      skill13_1.Location = point49;
      this.Skill13.Name = "Skill13";
      PictureBox skill13_2 = this.Skill13;
      size1 = new Size(34, 35);
      Size size49 = size1;
      skill13_2.Size = size49;
      this.Skill13.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill13.TabIndex = 380;
      this.Skill13.TabStop = false;
      this.Skill14.BackColor = Color.DimGray;
      this.Skill14.BackgroundImage = (Image) componentResourceManager.GetObject("Skill14.BackgroundImage");
      this.Skill14.Cursor = Cursors.Hand;
      this.Skill14.ImeMode = ImeMode.NoControl;
      PictureBox skill14_1 = this.Skill14;
      point1 = new Point(120, 360);
      Point point50 = point1;
      skill14_1.Location = point50;
      this.Skill14.Name = "Skill14";
      PictureBox skill14_2 = this.Skill14;
      size1 = new Size(34, 35);
      Size size50 = size1;
      skill14_2.Size = size50;
      this.Skill14.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill14.TabIndex = 379;
      this.Skill14.TabStop = false;
      this.Skill15.BackColor = Color.DimGray;
      this.Skill15.BackgroundImage = (Image) componentResourceManager.GetObject("Skill15.BackgroundImage");
      this.Skill15.Cursor = Cursors.Hand;
      this.Skill15.ImeMode = ImeMode.NoControl;
      PictureBox skill15_1 = this.Skill15;
      point1 = new Point(154, 360);
      Point point51 = point1;
      skill15_1.Location = point51;
      this.Skill15.Name = "Skill15";
      PictureBox skill15_2 = this.Skill15;
      size1 = new Size(34, 35);
      Size size51 = size1;
      skill15_2.Size = size51;
      this.Skill15.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill15.TabIndex = 378;
      this.Skill15.TabStop = false;
      this.Skill16.BackColor = Color.DimGray;
      this.Skill16.BackgroundImage = (Image) componentResourceManager.GetObject("Skill16.BackgroundImage");
      this.Skill16.Cursor = Cursors.Hand;
      this.Skill16.ImeMode = ImeMode.NoControl;
      PictureBox skill16_1 = this.Skill16;
      point1 = new Point(188, 360);
      Point point52 = point1;
      skill16_1.Location = point52;
      this.Skill16.Name = "Skill16";
      PictureBox skill16_2 = this.Skill16;
      size1 = new Size(34, 35);
      Size size52 = size1;
      skill16_2.Size = size52;
      this.Skill16.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill16.TabIndex = 377;
      this.Skill16.TabStop = false;
      this.Skill17.BackColor = Color.DimGray;
      this.Skill17.BackgroundImage = (Image) componentResourceManager.GetObject("Skill17.BackgroundImage");
      this.Skill17.Cursor = Cursors.Hand;
      this.Skill17.ImeMode = ImeMode.NoControl;
      PictureBox skill17_1 = this.Skill17;
      point1 = new Point(222, 360);
      Point point53 = point1;
      skill17_1.Location = point53;
      this.Skill17.Name = "Skill17";
      PictureBox skill17_2 = this.Skill17;
      size1 = new Size(34, 35);
      Size size53 = size1;
      skill17_2.Size = size53;
      this.Skill17.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill17.TabIndex = 376;
      this.Skill17.TabStop = false;
      this.Skill18.BackColor = Color.DimGray;
      this.Skill18.BackgroundImage = (Image) componentResourceManager.GetObject("Skill18.BackgroundImage");
      this.Skill18.Cursor = Cursors.Hand;
      this.Skill18.ImeMode = ImeMode.NoControl;
      PictureBox skill18_1 = this.Skill18;
      point1 = new Point(256, 360);
      Point point54 = point1;
      skill18_1.Location = point54;
      this.Skill18.Name = "Skill18";
      PictureBox skill18_2 = this.Skill18;
      size1 = new Size(34, 35);
      Size size54 = size1;
      skill18_2.Size = size54;
      this.Skill18.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill18.TabIndex = 375;
      this.Skill18.TabStop = false;
      this.Skill20.BackColor = Color.DimGray;
      this.Skill20.BackgroundImage = (Image) componentResourceManager.GetObject("Skill20.BackgroundImage");
      this.Skill20.Cursor = Cursors.Hand;
      this.Skill20.ImeMode = ImeMode.NoControl;
      PictureBox skill20_1 = this.Skill20;
      point1 = new Point(324, 360);
      Point point55 = point1;
      skill20_1.Location = point55;
      this.Skill20.Name = "Skill20";
      PictureBox skill20_2 = this.Skill20;
      size1 = new Size(34, 35);
      Size size55 = size1;
      skill20_2.Size = size55;
      this.Skill20.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill20.TabIndex = 374;
      this.Skill20.TabStop = false;
      this.Skill19.BackColor = Color.DimGray;
      this.Skill19.BackgroundImage = (Image) componentResourceManager.GetObject("Skill19.BackgroundImage");
      this.Skill19.Cursor = Cursors.Hand;
      this.Skill19.ImeMode = ImeMode.NoControl;
      PictureBox skill19_1 = this.Skill19;
      point1 = new Point(290, 360);
      Point point56 = point1;
      skill19_1.Location = point56;
      this.Skill19.Name = "Skill19";
      PictureBox skill19_2 = this.Skill19;
      size1 = new Size(34, 35);
      Size size56 = size1;
      skill19_2.Size = size56;
      this.Skill19.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill19.TabIndex = 373;
      this.Skill19.TabStop = false;
      this.Skill10.BackColor = Color.DimGray;
      this.Skill10.BackgroundImage = (Image) componentResourceManager.GetObject("Skill10.BackgroundImage");
      this.Skill10.Cursor = Cursors.Hand;
      this.Skill10.ImeMode = ImeMode.NoControl;
      PictureBox skill10_1 = this.Skill10;
      point1 = new Point(324, 324);
      Point point57 = point1;
      skill10_1.Location = point57;
      this.Skill10.Name = "Skill10";
      PictureBox skill10_2 = this.Skill10;
      size1 = new Size(34, 35);
      Size size57 = size1;
      skill10_2.Size = size57;
      this.Skill10.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill10.TabIndex = 372;
      this.Skill10.TabStop = false;
      this.Skill9.BackColor = Color.DimGray;
      this.Skill9.BackgroundImage = (Image) componentResourceManager.GetObject("Skill9.BackgroundImage");
      this.Skill9.Cursor = Cursors.Hand;
      this.Skill9.ImeMode = ImeMode.NoControl;
      PictureBox skill9_1 = this.Skill9;
      point1 = new Point(290, 324);
      Point point58 = point1;
      skill9_1.Location = point58;
      this.Skill9.Name = "Skill9";
      PictureBox skill9_2 = this.Skill9;
      size1 = new Size(34, 35);
      Size size58 = size1;
      skill9_2.Size = size58;
      this.Skill9.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill9.TabIndex = 371;
      this.Skill9.TabStop = false;
      this.Skill8.BackColor = Color.DimGray;
      this.Skill8.BackgroundImage = (Image) componentResourceManager.GetObject("Skill8.BackgroundImage");
      this.Skill8.Cursor = Cursors.Hand;
      this.Skill8.ImeMode = ImeMode.NoControl;
      PictureBox skill8_1 = this.Skill8;
      point1 = new Point(256, 324);
      Point point59 = point1;
      skill8_1.Location = point59;
      this.Skill8.Name = "Skill8";
      PictureBox skill8_2 = this.Skill8;
      size1 = new Size(34, 35);
      Size size59 = size1;
      skill8_2.Size = size59;
      this.Skill8.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill8.TabIndex = 370;
      this.Skill8.TabStop = false;
      this.Skill7.BackColor = Color.DimGray;
      this.Skill7.BackgroundImage = (Image) componentResourceManager.GetObject("Skill7.BackgroundImage");
      this.Skill7.Cursor = Cursors.Hand;
      this.Skill7.ImeMode = ImeMode.NoControl;
      PictureBox skill7_1 = this.Skill7;
      point1 = new Point(222, 324);
      Point point60 = point1;
      skill7_1.Location = point60;
      this.Skill7.Name = "Skill7";
      PictureBox skill7_2 = this.Skill7;
      size1 = new Size(34, 35);
      Size size60 = size1;
      skill7_2.Size = size60;
      this.Skill7.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill7.TabIndex = 369;
      this.Skill7.TabStop = false;
      this.Skill6.BackColor = Color.DimGray;
      this.Skill6.BackgroundImage = (Image) componentResourceManager.GetObject("Skill6.BackgroundImage");
      this.Skill6.Cursor = Cursors.Hand;
      this.Skill6.ImeMode = ImeMode.NoControl;
      PictureBox skill6_1 = this.Skill6;
      point1 = new Point(188, 324);
      Point point61 = point1;
      skill6_1.Location = point61;
      this.Skill6.Name = "Skill6";
      PictureBox skill6_2 = this.Skill6;
      size1 = new Size(34, 35);
      Size size61 = size1;
      skill6_2.Size = size61;
      this.Skill6.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill6.TabIndex = 368;
      this.Skill6.TabStop = false;
      this.Skill5.BackColor = Color.DimGray;
      this.Skill5.BackgroundImage = (Image) componentResourceManager.GetObject("Skill5.BackgroundImage");
      this.Skill5.Cursor = Cursors.Hand;
      this.Skill5.ImeMode = ImeMode.NoControl;
      PictureBox skill5_1 = this.Skill5;
      point1 = new Point(154, 324);
      Point point62 = point1;
      skill5_1.Location = point62;
      this.Skill5.Name = "Skill5";
      PictureBox skill5_2 = this.Skill5;
      size1 = new Size(34, 35);
      Size size62 = size1;
      skill5_2.Size = size62;
      this.Skill5.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill5.TabIndex = 367;
      this.Skill5.TabStop = false;
      this.Skill4.BackColor = Color.DimGray;
      this.Skill4.BackgroundImage = (Image) componentResourceManager.GetObject("Skill4.BackgroundImage");
      this.Skill4.Cursor = Cursors.Hand;
      this.Skill4.ImeMode = ImeMode.NoControl;
      PictureBox skill4_1 = this.Skill4;
      point1 = new Point(120, 324);
      Point point63 = point1;
      skill4_1.Location = point63;
      this.Skill4.Name = "Skill4";
      PictureBox skill4_2 = this.Skill4;
      size1 = new Size(34, 35);
      Size size63 = size1;
      skill4_2.Size = size63;
      this.Skill4.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill4.TabIndex = 366;
      this.Skill4.TabStop = false;
      this.Skill3.BackColor = Color.DimGray;
      this.Skill3.BackgroundImage = (Image) componentResourceManager.GetObject("Skill3.BackgroundImage");
      this.Skill3.Cursor = Cursors.Hand;
      this.Skill3.ImeMode = ImeMode.NoControl;
      PictureBox skill3_1 = this.Skill3;
      point1 = new Point(86, 324);
      Point point64 = point1;
      skill3_1.Location = point64;
      this.Skill3.Name = "Skill3";
      PictureBox skill3_2 = this.Skill3;
      size1 = new Size(34, 35);
      Size size64 = size1;
      skill3_2.Size = size64;
      this.Skill3.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill3.TabIndex = 365;
      this.Skill3.TabStop = false;
      this.Skill1.BackColor = Color.DimGray;
      this.Skill1.BackgroundImage = (Image) componentResourceManager.GetObject("Skill1.BackgroundImage");
      this.Skill1.Cursor = Cursors.Hand;
      this.Skill1.ImeMode = ImeMode.NoControl;
      PictureBox skill1_1 = this.Skill1;
      point1 = new Point(18, 324);
      Point point65 = point1;
      skill1_1.Location = point65;
      this.Skill1.Name = "Skill1";
      PictureBox skill1_2 = this.Skill1;
      size1 = new Size(34, 35);
      Size size65 = size1;
      skill1_2.Size = size65;
      this.Skill1.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill1.TabIndex = 364;
      this.Skill1.TabStop = false;
      this.Skill2.BackColor = Color.DimGray;
      this.Skill2.BackgroundImage = (Image) componentResourceManager.GetObject("Skill2.BackgroundImage");
      this.Skill2.Cursor = Cursors.Hand;
      this.Skill2.ImeMode = ImeMode.NoControl;
      PictureBox skill2_1 = this.Skill2;
      point1 = new Point(52, 324);
      Point point66 = point1;
      skill2_1.Location = point66;
      this.Skill2.Name = "Skill2";
      PictureBox skill2_2 = this.Skill2;
      size1 = new Size(34, 35);
      Size size66 = size1;
      skill2_2.Size = size66;
      this.Skill2.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Skill2.TabIndex = 363;
      this.Skill2.TabStop = false;
      this.PersonajeSearch.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox personajeSearch1 = this.PersonajeSearch;
      point1 = new Point(207, 31);
      Point point67 = point1;
      personajeSearch1.Location = point67;
      this.PersonajeSearch.Name = "PersonajeSearch";
      TextBox personajeSearch2 = this.PersonajeSearch;
      size1 = new Size(89, 20);
      Size size67 = size1;
      personajeSearch2.Size = size67;
      this.PersonajeSearch.TabIndex = 352;
      this.PersonajeSearch.TabStop = false;
      this.PersonajeSearch.TextAlign = HorizontalAlignment.Center;
      this.CuentaSearch.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox cuentaSearch1 = this.CuentaSearch;
      point1 = new Point(64, 31);
      Point point68 = point1;
      cuentaSearch1.Location = point68;
      this.CuentaSearch.Name = "CuentaSearch";
      TextBox cuentaSearch2 = this.CuentaSearch;
      size1 = new Size(106, 20);
      Size size68 = size1;
      cuentaSearch2.Size = size68;
      this.CuentaSearch.TabIndex = 351;
      this.CuentaSearch.TabStop = false;
      this.CuentaSearch.TextAlign = HorizontalAlignment.Center;
      this.Foto.BackColor = Color.Transparent;
      this.Foto.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Foto.ForeColor = SystemColors.GrayText;
      this.Foto.ImeMode = ImeMode.NoControl;
      Label foto1 = this.Foto;
      point1 = new Point(274, 88);
      Point point69 = point1;
      foto1.Location = point69;
      this.Foto.Name = "Foto";
      Label foto2 = this.Foto;
      size1 = new Size(96, 16);
      Size size69 = size1;
      foto2.Size = size69;
      this.Foto.TabIndex = 357;
      this.Foto.Text = "Foto";
      this.Foto.TextAlign = ContentAlignment.MiddleCenter;
      this.Imagen.BackColor = Color.Black;
      this.Imagen.ImeMode = ImeMode.NoControl;
      PictureBox imagen1 = this.Imagen;
      point1 = new Point(305, 108);
      Point point70 = point1;
      imagen1.Location = point70;
      this.Imagen.Name = "Imagen";
      PictureBox imagen2 = this.Imagen;
      size1 = new Size(34, 35);
      Size size70 = size1;
      imagen2.Size = size70;
      this.Imagen.SizeMode = PictureBoxSizeMode.CenterImage;
      this.Imagen.TabIndex = 356;
      this.Imagen.TabStop = false;
      this.Items.Cursor = Cursors.Hand;
      this.Items.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      ListBox items1 = this.Items;
      point1 = new Point(130, 95);
      Point point71 = point1;
      items1.Location = point71;
      this.Items.Name = "Items";
      ListBox items2 = this.Items;
      size1 = new Size(134, 134);
      Size size71 = size1;
      items2.Size = size71;
      this.Items.TabIndex = 348;
      this.Items.TabStop = false;
      this.Tipo.Cursor = Cursors.Hand;
      this.Tipo.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Tipo.Items.AddRange(new object[19]
      {
        (object) "Dark Wizard",
        (object) "Soul Master",
        (object) "Gran Master",
        (object) "Dark Knight",
        (object) "Blade Knight",
        (object) "Blade Master",
        (object) "Fairy Elf",
        (object) "Muse Elf",
        (object) "High Elf",
        (object) "Magic Gladiator",
        (object) "Duel Master",
        (object) "Dark Lord",
        (object) "Lord Emperor",
        (object) "Summoner",
        (object) "Bloody Summoner",
        (object) "Dimension Master",
        (object) "Pets",
        (object) "Others",
        (object) "New/Test"
      });
      ListBox tipo1 = this.Tipo;
      point1 = new Point(10, 95);
      Point point72 = point1;
      tipo1.Location = point72;
      this.Tipo.Name = "Tipo";
      ListBox tipo2 = this.Tipo;
      size1 = new Size(120, 134);
      Size size72 = size1;
      tipo2.Size = size72;
      this.Tipo.TabIndex = 355;
      this.Tipo.TabStop = false;
      this.Account.BackColor = Color.Transparent;
      this.Account.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Account.ForeColor = Color.DimGray;
      Label account1 = this.Account;
      point1 = new Point(8, 33);
      Point point73 = point1;
      account1.Location = point73;
      this.Account.Name = "Account";
      Label account2 = this.Account;
      size1 = new Size(50, 14);
      Size size73 = size1;
      account2.Size = size73;
      this.Account.TabIndex = 353;
      this.Account.Text = "Cuenta";
      this.Account.TextAlign = ContentAlignment.MiddleCenter;
      this.Personajes.Cursor = Cursors.Hand;
      this.Personajes.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Personajes.ItemHeight = 13;
      ComboBox personajes1 = this.Personajes;
      point1 = new Point(189, 51);
      Point point74 = point1;
      personajes1.Location = point74;
      this.Personajes.Name = "Personajes";
      ComboBox personajes2 = this.Personajes;
      size1 = new Size(178, 21);
      Size size74 = size1;
      personajes2.Size = size74;
      this.Personajes.TabIndex = 350;
      this.Personajes.TabStop = false;
      this.Personajes.Text = " >> Seleccione Personaje << ";
      this.Cuentas.Cursor = Cursors.Hand;
      this.Cuentas.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Cuentas.ItemHeight = 13;
      ComboBox cuentas1 = this.Cuentas;
      point1 = new Point(10, 51);
      Point point75 = point1;
      cuentas1.Location = point75;
      this.Cuentas.Name = "Cuentas";
      ComboBox cuentas2 = this.Cuentas;
      size1 = new Size(178, 21);
      Size size75 = size1;
      cuentas2.Size = size75;
      this.Cuentas.TabIndex = 349;
      this.Cuentas.TabStop = false;
      this.Cuentas.Text = " >> Seleccione Cuenta << ";
      this.Chart.BackColor = Color.Transparent;
      this.Chart.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Chart.ForeColor = Color.DimGray;
      Label chart1 = this.Chart;
      point1 = new Point(302, 32);
      Point point76 = point1;
      chart1.Location = point76;
      this.Chart.Name = "Chart";
      Label chart2 = this.Chart;
      size1 = new Size(64, 14);
      Size size76 = size1;
      chart2.Size = size76;
      this.Chart.TabIndex = 354;
      this.Chart.Text = "Personaje";
      this.Chart.TextAlign = ContentAlignment.MiddleCenter;
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
      point1 = new Point(173, 29);
      Point point77 = point1;
      buscar1.Location = point77;
      this.Buscar.Name = "Buscar";
      Button buscar2 = this.Buscar;
      size1 = new Size(32, 21);
      Size size77 = size1;
      buscar2.Size = size77;
      this.Buscar.TabIndex = 506;
      this.Buscar.TabStop = false;
      this.Buscar.UseVisualStyleBackColor = false;
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
      Point point78 = point1;
      cerrar1.Location = point78;
      this.Cerrar.Name = "Cerrar";
      Button cerrar2 = this.Cerrar;
      size1 = new Size(13, 13);
      Size size78 = size1;
      cerrar2.Size = size78;
      this.Cerrar.TabIndex = 1895;
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
      point1 = new Point(8, 7);
      Point point79 = point1;
      minimizar1.Location = point79;
      this.Minimizar.Name = "Minimizar";
      Button minimizar2 = this.Minimizar;
      size1 = new Size(13, 13);
      Size size79 = size1;
      minimizar2.Size = size79;
      this.Minimizar.TabIndex = 1894;
      this.Minimizar.TabStop = false;
      this.Minimizar.UseVisualStyleBackColor = false;
      this.SkillTipo.BackColor = Color.Transparent;
      this.SkillTipo.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.SkillTipo.ForeColor = Color.Red;
      Label skillTipo1 = this.SkillTipo;
      point1 = new Point(269, 148);
      Point point80 = point1;
      skillTipo1.Location = point80;
      this.SkillTipo.Name = "SkillTipo";
      Label skillTipo2 = this.SkillTipo;
      size1 = new Size(100, 13);
      Size size80 = size1;
      skillTipo2.Size = size80;
      this.SkillTipo.TabIndex = 1896;
      this.SkillTipo.TextAlign = ContentAlignment.MiddleCenter;
      this.SkillRango.BackColor = Color.Transparent;
      this.SkillRango.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.SkillRango.ForeColor = Color.DarkOrange;
      Label skillRango1 = this.SkillRango;
      point1 = new Point(269, 169);
      Point point81 = point1;
      skillRango1.Location = point81;
      this.SkillRango.Name = "SkillRango";
      Label skillRango2 = this.SkillRango;
      size1 = new Size(100, 13);
      Size size81 = size1;
      skillRango2.Size = size81;
      this.SkillRango.TabIndex = 1897;
      this.SkillRango.TextAlign = ContentAlignment.MiddleCenter;
      this.Mana.BackColor = Color.Transparent;
      this.Mana.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Mana.ForeColor = Color.MediumBlue;
      Label mana1 = this.Mana;
      point1 = new Point(269, 190);
      Point point82 = point1;
      mana1.Location = point82;
      this.Mana.Name = "Mana";
      Label mana2 = this.Mana;
      size1 = new Size(100, 13);
      Size size82 = size1;
      mana2.Size = size82;
      this.Mana.TabIndex = 1898;
      this.Mana.TextAlign = ContentAlignment.MiddleCenter;
      this.Estamina.BackColor = Color.Transparent;
      this.Estamina.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Estamina.ForeColor = Color.Purple;
      Label estamina1 = this.Estamina;
      point1 = new Point(269, 211);
      Point point83 = point1;
      estamina1.Location = point83;
      this.Estamina.Name = "Estamina";
      Label estamina2 = this.Estamina;
      size1 = new Size(100, 13);
      Size size83 = size1;
      estamina2.Size = size83;
      this.Estamina.TabIndex = 1899;
      this.Estamina.TextAlign = ContentAlignment.MiddleCenter;
      this.CuentaSkill.BackColor = Color.Transparent;
      this.CuentaSkill.Font = new Font("Microsoft Sans Serif", 14.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.CuentaSkill.ForeColor = Color.Red;
      Label cuentaSkill1 = this.CuentaSkill;
      point1 = new Point(36, 243);
      Point point84 = point1;
      cuentaSkill1.Location = point84;
      this.CuentaSkill.Name = "CuentaSkill";
      Label cuentaSkill2 = this.CuentaSkill;
      size1 = new Size(245, 22);
      Size size84 = size1;
      cuentaSkill2.Size = size84;
      this.CuentaSkill.TabIndex = 1900;
      this.CuentaSkill.TextAlign = ContentAlignment.MiddleCenter;
      this.ChartSkill.BackColor = Color.Transparent;
      this.ChartSkill.Font = new Font("Microsoft Sans Serif", 14.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.ChartSkill.ForeColor = Color.Red;
      Label chartSkill1 = this.ChartSkill;
      point1 = new Point(36, 265);
      Point point85 = point1;
      chartSkill1.Location = point85;
      this.ChartSkill.Name = "ChartSkill";
      Label chartSkill2 = this.ChartSkill;
      size1 = new Size(245, 22);
      Size size85 = size1;
      chartSkill2.Size = size85;
      this.ChartSkill.TabIndex = 1901;
      this.ChartSkill.TextAlign = ContentAlignment.MiddleCenter;
      this.NombreClase.BackColor = Color.Transparent;
      this.NombreClase.Font = new Font("Microsoft Sans Serif", 12f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.NombreClase.ForeColor = Color.Goldenrod;
      Label nombreClase1 = this.NombreClase;
      point1 = new Point(36, 287);
      Point point86 = point1;
      nombreClase1.Location = point86;
      this.NombreClase.Name = "NombreClase";
      Label nombreClase2 = this.NombreClase;
      size1 = new Size(245, 20);
      Size size86 = size1;
      nombreClase2.Size = size86;
      this.NombreClase.TabIndex = 1902;
      this.NombreClase.TextAlign = ContentAlignment.MiddleCenter;
      this.Titulo.AutoSize = true;
      this.Titulo.BackColor = Color.Transparent;
      this.Titulo.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Titulo.ForeColor = Color.DarkOrange;
      Label titulo1 = this.Titulo;
      point1 = new Point(59, 7);
      Point point87 = point1;
      titulo1.Location = point87;
      this.Titulo.Name = "Titulo";
      Label titulo2 = this.Titulo;
      size1 = new Size(0, 13);
      Size size87 = size1;
      titulo2.Size = size87;
      this.Titulo.TabIndex = 1903;
      this.Titulo.TextAlign = ContentAlignment.MiddleLeft;
      this.AutoScaleMode = AutoScaleMode.Inherit;
      this.BackColor = Color.Black;
      this.BackgroundImage = (Image) componentResourceManager.GetObject("$this.BackgroundImage");
      this.CancelButton = (IButtonControl) this.Minimizar;
      size1 = new Size(376, 553);
      this.ClientSize = size1;
      this.Controls.Add((Control) this.Titulo);
      this.Controls.Add((Control) this.NombreClase);
      this.Controls.Add((Control) this.ChartSkill);
      this.Controls.Add((Control) this.CuentaSkill);
      this.Controls.Add((Control) this.Estamina);
      this.Controls.Add((Control) this.Mana);
      this.Controls.Add((Control) this.SkillRango);
      this.Controls.Add((Control) this.SkillTipo);
      this.Controls.Add((Control) this.Cerrar);
      this.Controls.Add((Control) this.Minimizar);
      this.Controls.Add((Control) this.Buscar);
      this.Controls.Add((Control) this.OnlineOFF);
      this.Controls.Add((Control) this.OnlineON);
      this.Controls.Add((Control) this.ONLineInfo);
      this.Controls.Add((Control) this.Skill31);
      this.Controls.Add((Control) this.Skill32);
      this.Controls.Add((Control) this.Skill33);
      this.Controls.Add((Control) this.Skill34);
      this.Controls.Add((Control) this.Skill35);
      this.Controls.Add((Control) this.Skill36);
      this.Controls.Add((Control) this.Skill37);
      this.Controls.Add((Control) this.Skill38);
      this.Controls.Add((Control) this.Skill39);
      this.Controls.Add((Control) this.Skill40);
      this.Controls.Add((Control) this.Skill41);
      this.Controls.Add((Control) this.Skill42);
      this.Controls.Add((Control) this.Skill43);
      this.Controls.Add((Control) this.Skill44);
      this.Controls.Add((Control) this.Skill45);
      this.Controls.Add((Control) this.Skill46);
      this.Controls.Add((Control) this.Skill47);
      this.Controls.Add((Control) this.Skill48);
      this.Controls.Add((Control) this.Skill21);
      this.Controls.Add((Control) this.Skill22);
      this.Controls.Add((Control) this.Skill23);
      this.Controls.Add((Control) this.Skill24);
      this.Controls.Add((Control) this.Skill25);
      this.Controls.Add((Control) this.Skill26);
      this.Controls.Add((Control) this.Skill27);
      this.Controls.Add((Control) this.Skill28);
      this.Controls.Add((Control) this.Skill29);
      this.Controls.Add((Control) this.Skill49);
      this.Controls.Add((Control) this.Label6);
      this.Controls.Add((Control) this.ClearSkills);
      this.Controls.Add((Control) this.Skill50);
      this.Controls.Add((Control) this.Skill51);
      this.Controls.Add((Control) this.Skill52);
      this.Controls.Add((Control) this.Skill53);
      this.Controls.Add((Control) this.Skill54);
      this.Controls.Add((Control) this.Skill55);
      this.Controls.Add((Control) this.Skill56);
      this.Controls.Add((Control) this.Skill57);
      this.Controls.Add((Control) this.Skill58);
      this.Controls.Add((Control) this.Skill59);
      this.Controls.Add((Control) this.Skill60);
      this.Controls.Add((Control) this.Skill30);
      this.Controls.Add((Control) this.Skill11);
      this.Controls.Add((Control) this.Skill12);
      this.Controls.Add((Control) this.Skill13);
      this.Controls.Add((Control) this.Skill14);
      this.Controls.Add((Control) this.Skill15);
      this.Controls.Add((Control) this.Skill16);
      this.Controls.Add((Control) this.Skill17);
      this.Controls.Add((Control) this.Skill18);
      this.Controls.Add((Control) this.Skill20);
      this.Controls.Add((Control) this.Skill19);
      this.Controls.Add((Control) this.Skill10);
      this.Controls.Add((Control) this.Skill9);
      this.Controls.Add((Control) this.Skill8);
      this.Controls.Add((Control) this.Skill7);
      this.Controls.Add((Control) this.Skill6);
      this.Controls.Add((Control) this.Skill5);
      this.Controls.Add((Control) this.Skill4);
      this.Controls.Add((Control) this.Skill3);
      this.Controls.Add((Control) this.Skill1);
      this.Controls.Add((Control) this.Skill2);
      this.Controls.Add((Control) this.PersonajeSearch);
      this.Controls.Add((Control) this.CuentaSearch);
      this.Controls.Add((Control) this.Foto);
      this.Controls.Add((Control) this.Imagen);
      this.Controls.Add((Control) this.Items);
      this.Controls.Add((Control) this.Tipo);
      this.Controls.Add((Control) this.Account);
      this.Controls.Add((Control) this.Personajes);
      this.Controls.Add((Control) this.Cuentas);
      this.Controls.Add((Control) this.Chart);
      this.FormBorderStyle = FormBorderStyle.None;
      this.Icon = (Icon) componentResourceManager.GetObject("$this.Icon");
      this.MaximizeBox = false;
      size1 = new Size(376, 553);
      this.MaximumSize = size1;
      this.MinimizeBox = false;
      size1 = new Size(376, 553);
      this.MinimumSize = size1;
      this.Name = "SkillMaker";
      this.StartPosition = FormStartPosition.CenterScreen;
      this.Text = "SkillMaker";
      ((ISupportInitialize) this.Skill31).EndInit();
      ((ISupportInitialize) this.Skill32).EndInit();
      ((ISupportInitialize) this.Skill33).EndInit();
      ((ISupportInitialize) this.Skill34).EndInit();
      ((ISupportInitialize) this.Skill35).EndInit();
      ((ISupportInitialize) this.Skill36).EndInit();
      ((ISupportInitialize) this.Skill37).EndInit();
      ((ISupportInitialize) this.Skill38).EndInit();
      ((ISupportInitialize) this.Skill39).EndInit();
      ((ISupportInitialize) this.Skill40).EndInit();
      ((ISupportInitialize) this.Skill41).EndInit();
      ((ISupportInitialize) this.Skill42).EndInit();
      ((ISupportInitialize) this.Skill43).EndInit();
      ((ISupportInitialize) this.Skill44).EndInit();
      ((ISupportInitialize) this.Skill45).EndInit();
      ((ISupportInitialize) this.Skill46).EndInit();
      ((ISupportInitialize) this.Skill47).EndInit();
      ((ISupportInitialize) this.Skill48).EndInit();
      ((ISupportInitialize) this.Skill21).EndInit();
      ((ISupportInitialize) this.Skill22).EndInit();
      ((ISupportInitialize) this.Skill23).EndInit();
      ((ISupportInitialize) this.Skill24).EndInit();
      ((ISupportInitialize) this.Skill25).EndInit();
      ((ISupportInitialize) this.Skill26).EndInit();
      ((ISupportInitialize) this.Skill27).EndInit();
      ((ISupportInitialize) this.Skill28).EndInit();
      ((ISupportInitialize) this.Skill29).EndInit();
      ((ISupportInitialize) this.Skill49).EndInit();
      ((ISupportInitialize) this.OnlineOFF).EndInit();
      ((ISupportInitialize) this.OnlineON).EndInit();
      ((ISupportInitialize) this.Skill50).EndInit();
      ((ISupportInitialize) this.Skill51).EndInit();
      ((ISupportInitialize) this.Skill52).EndInit();
      ((ISupportInitialize) this.Skill53).EndInit();
      ((ISupportInitialize) this.Skill54).EndInit();
      ((ISupportInitialize) this.Skill55).EndInit();
      ((ISupportInitialize) this.Skill56).EndInit();
      ((ISupportInitialize) this.Skill57).EndInit();
      ((ISupportInitialize) this.Skill58).EndInit();
      ((ISupportInitialize) this.Skill59).EndInit();
      ((ISupportInitialize) this.Skill60).EndInit();
      ((ISupportInitialize) this.Skill30).EndInit();
      ((ISupportInitialize) this.Skill11).EndInit();
      ((ISupportInitialize) this.Skill12).EndInit();
      ((ISupportInitialize) this.Skill13).EndInit();
      ((ISupportInitialize) this.Skill14).EndInit();
      ((ISupportInitialize) this.Skill15).EndInit();
      ((ISupportInitialize) this.Skill16).EndInit();
      ((ISupportInitialize) this.Skill17).EndInit();
      ((ISupportInitialize) this.Skill18).EndInit();
      ((ISupportInitialize) this.Skill20).EndInit();
      ((ISupportInitialize) this.Skill19).EndInit();
      ((ISupportInitialize) this.Skill10).EndInit();
      ((ISupportInitialize) this.Skill9).EndInit();
      ((ISupportInitialize) this.Skill8).EndInit();
      ((ISupportInitialize) this.Skill7).EndInit();
      ((ISupportInitialize) this.Skill6).EndInit();
      ((ISupportInitialize) this.Skill5).EndInit();
      ((ISupportInitialize) this.Skill4).EndInit();
      ((ISupportInitialize) this.Skill3).EndInit();
      ((ISupportInitialize) this.Skill1).EndInit();
      ((ISupportInitialize) this.Skill2).EndInit();
      ((ISupportInitialize) this.Imagen).EndInit();
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

    public object ExcepcionesON()
    {
      this.ClearSkills.Enabled = true;
      this.Skill1.Enabled = true;
      this.Skill2.Enabled = true;
      this.Skill3.Enabled = true;
      this.Skill4.Enabled = true;
      this.Skill5.Enabled = true;
      this.Skill6.Enabled = true;
      this.Skill7.Enabled = true;
      this.Skill8.Enabled = true;
      this.Skill9.Enabled = true;
      this.Skill10.Enabled = true;
      this.Skill11.Enabled = true;
      this.Skill12.Enabled = true;
      this.Skill13.Enabled = true;
      this.Skill14.Enabled = true;
      this.Skill15.Enabled = true;
      this.Skill16.Enabled = true;
      this.Skill17.Enabled = true;
      this.Skill18.Enabled = true;
      this.Skill19.Enabled = true;
      this.Skill20.Enabled = true;
      this.Skill21.Enabled = true;
      this.Skill22.Enabled = true;
      this.Skill23.Enabled = true;
      this.Skill24.Enabled = true;
      this.Skill25.Enabled = true;
      this.Skill26.Enabled = true;
      this.Skill27.Enabled = true;
      this.Skill28.Enabled = true;
      this.Skill29.Enabled = true;
      this.Skill30.Enabled = true;
      this.Skill31.Enabled = true;
      this.Skill32.Enabled = true;
      this.Skill33.Enabled = true;
      this.Skill34.Enabled = true;
      this.Skill35.Enabled = true;
      this.Skill36.Enabled = true;
      this.Skill37.Enabled = true;
      this.Skill38.Enabled = true;
      this.Skill39.Enabled = true;
      this.Skill40.Enabled = true;
      this.Skill41.Enabled = true;
      this.Skill42.Enabled = true;
      this.Skill43.Enabled = true;
      this.Skill44.Enabled = true;
      this.Skill45.Enabled = true;
      this.Skill46.Enabled = true;
      this.Skill47.Enabled = true;
      this.Skill48.Enabled = true;
      this.Skill49.Enabled = true;
      this.Skill50.Enabled = true;
      this.Skill51.Enabled = true;
      this.Skill52.Enabled = true;
      this.Skill53.Enabled = true;
      this.Skill54.Enabled = true;
      this.Skill55.Enabled = true;
      this.Skill56.Enabled = true;
      this.Skill57.Enabled = true;
      this.Skill58.Enabled = true;
      this.Skill59.Enabled = true;
      this.Skill60.Enabled = true;
      return (object) true;
    }

    public object ExcepcionesOFF()
    {
      this.ClearSkills.Enabled = false;
      this.Skill1.Enabled = false;
      this.Skill2.Enabled = false;
      this.Skill3.Enabled = false;
      this.Skill4.Enabled = false;
      this.Skill5.Enabled = false;
      this.Skill6.Enabled = false;
      this.Skill7.Enabled = false;
      this.Skill8.Enabled = false;
      this.Skill9.Enabled = false;
      this.Skill10.Enabled = false;
      this.Skill11.Enabled = false;
      this.Skill12.Enabled = false;
      this.Skill13.Enabled = false;
      this.Skill14.Enabled = false;
      this.Skill15.Enabled = false;
      this.Skill16.Enabled = false;
      this.Skill17.Enabled = false;
      this.Skill18.Enabled = false;
      this.Skill19.Enabled = false;
      this.Skill20.Enabled = false;
      this.Skill21.Enabled = false;
      this.Skill22.Enabled = false;
      this.Skill23.Enabled = false;
      this.Skill24.Enabled = false;
      this.Skill25.Enabled = false;
      this.Skill26.Enabled = false;
      this.Skill27.Enabled = false;
      this.Skill28.Enabled = false;
      this.Skill29.Enabled = false;
      this.Skill30.Enabled = false;
      this.Skill31.Enabled = false;
      this.Skill32.Enabled = false;
      this.Skill33.Enabled = false;
      this.Skill34.Enabled = false;
      this.Skill35.Enabled = false;
      this.Skill36.Enabled = false;
      this.Skill37.Enabled = false;
      this.Skill38.Enabled = false;
      this.Skill39.Enabled = false;
      this.Skill40.Enabled = false;
      this.Skill41.Enabled = false;
      this.Skill42.Enabled = false;
      this.Skill43.Enabled = false;
      this.Skill44.Enabled = false;
      this.Skill45.Enabled = false;
      this.Skill46.Enabled = false;
      this.Skill47.Enabled = false;
      this.Skill48.Enabled = false;
      this.Skill49.Enabled = false;
      this.Skill50.Enabled = false;
      this.Skill51.Enabled = false;
      this.Skill52.Enabled = false;
      this.Skill53.Enabled = false;
      this.Skill54.Enabled = false;
      this.Skill55.Enabled = false;
      this.Skill56.Enabled = false;
      this.Skill57.Enabled = false;
      this.Skill58.Enabled = false;
      this.Skill59.Enabled = false;
      this.Skill60.Enabled = false;
      return (object) true;
    }

    public object ResetearSkills()
    {
      this.Skill1.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill2.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill3.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill4.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill5.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill6.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill7.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill8.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill9.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill10.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill11.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill12.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill13.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill14.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill15.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill16.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill17.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill18.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill19.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill20.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill21.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill22.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill23.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill24.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill25.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill26.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill27.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill28.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill29.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill30.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill31.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill32.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill33.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill34.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill35.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill36.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill37.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill38.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill39.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill40.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill41.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill42.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill43.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill44.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill45.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill46.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill47.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill48.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill49.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill50.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill51.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill52.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill53.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill54.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill55.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill56.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill57.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill58.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill59.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Skill60.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_1)));
      this.Emergente.SetToolTip((Control) this.Skill1, "");
      this.Emergente.SetToolTip((Control) this.Skill2, "");
      this.Emergente.SetToolTip((Control) this.Skill3, "");
      this.Emergente.SetToolTip((Control) this.Skill4, "");
      this.Emergente.SetToolTip((Control) this.Skill5, "");
      this.Emergente.SetToolTip((Control) this.Skill6, "");
      this.Emergente.SetToolTip((Control) this.Skill7, "");
      this.Emergente.SetToolTip((Control) this.Skill8, "");
      this.Emergente.SetToolTip((Control) this.Skill9, "");
      this.Emergente.SetToolTip((Control) this.Skill10, "");
      this.Emergente.SetToolTip((Control) this.Skill11, "");
      this.Emergente.SetToolTip((Control) this.Skill12, "");
      this.Emergente.SetToolTip((Control) this.Skill13, "");
      this.Emergente.SetToolTip((Control) this.Skill14, "");
      this.Emergente.SetToolTip((Control) this.Skill15, "");
      this.Emergente.SetToolTip((Control) this.Skill16, "");
      this.Emergente.SetToolTip((Control) this.Skill17, "");
      this.Emergente.SetToolTip((Control) this.Skill18, "");
      this.Emergente.SetToolTip((Control) this.Skill19, "");
      this.Emergente.SetToolTip((Control) this.Skill20, "");
      this.Emergente.SetToolTip((Control) this.Skill21, "");
      this.Emergente.SetToolTip((Control) this.Skill22, "");
      this.Emergente.SetToolTip((Control) this.Skill23, "");
      this.Emergente.SetToolTip((Control) this.Skill24, "");
      this.Emergente.SetToolTip((Control) this.Skill25, "");
      this.Emergente.SetToolTip((Control) this.Skill26, "");
      this.Emergente.SetToolTip((Control) this.Skill27, "");
      this.Emergente.SetToolTip((Control) this.Skill28, "");
      this.Emergente.SetToolTip((Control) this.Skill29, "");
      this.Emergente.SetToolTip((Control) this.Skill30, "");
      this.Emergente.SetToolTip((Control) this.Skill31, "");
      this.Emergente.SetToolTip((Control) this.Skill32, "");
      this.Emergente.SetToolTip((Control) this.Skill33, "");
      this.Emergente.SetToolTip((Control) this.Skill34, "");
      this.Emergente.SetToolTip((Control) this.Skill35, "");
      this.Emergente.SetToolTip((Control) this.Skill36, "");
      this.Emergente.SetToolTip((Control) this.Skill37, "");
      this.Emergente.SetToolTip((Control) this.Skill38, "");
      this.Emergente.SetToolTip((Control) this.Skill39, "");
      this.Emergente.SetToolTip((Control) this.Skill40, "");
      this.Emergente.SetToolTip((Control) this.Skill41, "");
      this.Emergente.SetToolTip((Control) this.Skill42, "");
      this.Emergente.SetToolTip((Control) this.Skill43, "");
      this.Emergente.SetToolTip((Control) this.Skill44, "");
      this.Emergente.SetToolTip((Control) this.Skill45, "");
      this.Emergente.SetToolTip((Control) this.Skill46, "");
      this.Emergente.SetToolTip((Control) this.Skill47, "");
      this.Emergente.SetToolTip((Control) this.Skill48, "");
      this.Emergente.SetToolTip((Control) this.Skill49, "");
      this.Emergente.SetToolTip((Control) this.Skill50, "");
      this.Emergente.SetToolTip((Control) this.Skill51, "");
      this.Emergente.SetToolTip((Control) this.Skill52, "");
      this.Emergente.SetToolTip((Control) this.Skill53, "");
      this.Emergente.SetToolTip((Control) this.Skill54, "");
      this.Emergente.SetToolTip((Control) this.Skill55, "");
      this.Emergente.SetToolTip((Control) this.Skill56, "");
      this.Emergente.SetToolTip((Control) this.Skill57, "");
      this.Emergente.SetToolTip((Control) this.Skill58, "");
      this.Emergente.SetToolTip((Control) this.Skill60, "");
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

    public object ClasePersonaje()
    {
      ConnectionManager.smethod_0();
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = "SELECT Class FROM Character WHERE AccountID='" + AccountData.CurrentAccount.string_1 + "' AND Name='" + AccountData.CurrentCharacter.string_1 + "'";
        SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
        this.NombreClase.Text = " [ UNKNOWN ] ";
        while (SqlConnectionPool.sqlDataReader_1.Read())
        {
          int num1 = 1;
          int num2 = Conversions.ToInteger(GameDataArrays.string_9);
          int num3 = num1;
          while (num3 <= num2)
          {
            if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(SqlConnectionPool.sqlDataReader_1[0].ToString(), GameDataArrays.string_6[checked (num3 - 1)], false) == 0)
              this.NombreClase.Text = GameDataArrays.string_8[checked (num3 - 1)];
            checked { ++num3; }
          }
        }
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

    public object Skills()
    {
      this.ResetearSkills();
      DatabaseOperations.smethod_9();
      this.CuentaSkill.Text = this.Cuentas.Text;
      this.ChartSkill.Text = this.Personajes.Text;
      int num1 = 0;
      int num2 = 1;
      int num3 = Constants.int_9;
      int num4 = num2;
      while (num4 <= num3)
      {
        SkillData.CurrentSkill.string_1 = Strings.Mid(AccountData.CurrentCharacter.string_18, checked (num4 + num1), 2);
        SkillData.CurrentSkill.string_2 = Strings.Mid(AccountData.CurrentCharacter.string_18, checked (num4 + num1 + 2), 2);
        checked { num1 += 5; }
        if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(SkillData.CurrentSkill.string_1, "FF", false) != 0 & Microsoft.VisualBasic.CompilerServices.Operators.CompareString(SkillData.CurrentSkill.string_1, "", false) != 0)
        {
          SkillDatabaseLoader.smethod_1();
          SkillImageHelper.smethod_0((object) SkillData.CurrentSkill.string_0);
          switch (num4)
          {
            case 1:
              this.Skill1.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill1, SkillData.CurrentSkill.string_8);
              break;
            case 2:
              this.Skill2.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill2, SkillData.CurrentSkill.string_8);
              break;
            case 3:
              this.Skill3.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill3, SkillData.CurrentSkill.string_8);
              break;
            case 4:
              this.Skill4.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill4, SkillData.CurrentSkill.string_8);
              break;
            case 5:
              this.Skill5.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill5, SkillData.CurrentSkill.string_8);
              break;
            case 6:
              this.Skill6.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill6, SkillData.CurrentSkill.string_8);
              break;
            case 7:
              this.Skill7.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill7, SkillData.CurrentSkill.string_8);
              break;
            case 8:
              this.Skill8.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill8, SkillData.CurrentSkill.string_8);
              break;
            case 9:
              this.Skill9.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill9, SkillData.CurrentSkill.string_8);
              break;
            case 10:
              this.Skill10.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill10, SkillData.CurrentSkill.string_8);
              break;
            case 11:
              this.Skill11.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill11, SkillData.CurrentSkill.string_8);
              break;
            case 12:
              this.Skill12.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill12, SkillData.CurrentSkill.string_8);
              break;
            case 13:
              this.Skill13.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill13, SkillData.CurrentSkill.string_8);
              break;
            case 14:
              this.Skill14.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill14, SkillData.CurrentSkill.string_8);
              break;
            case 15:
              this.Skill15.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill15, SkillData.CurrentSkill.string_8);
              break;
            case 16:
              this.Skill16.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill16, SkillData.CurrentSkill.string_8);
              break;
            case 17:
              this.Skill17.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill17, SkillData.CurrentSkill.string_8);
              break;
            case 18:
              this.Skill18.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill18, SkillData.CurrentSkill.string_8);
              break;
            case 19:
              this.Skill19.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill19, SkillData.CurrentSkill.string_8);
              break;
            case 20:
              this.Skill20.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill20, SkillData.CurrentSkill.string_8);
              break;
            case 21:
              this.Skill21.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill21, SkillData.CurrentSkill.string_8);
              break;
            case 22:
              this.Skill22.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill22, SkillData.CurrentSkill.string_8);
              break;
            case 23:
              this.Skill23.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill23, SkillData.CurrentSkill.string_8);
              break;
            case 24:
              this.Skill24.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill24, SkillData.CurrentSkill.string_8);
              break;
            case 25:
              this.Skill25.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill25, SkillData.CurrentSkill.string_8);
              break;
            case 26:
              this.Skill26.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill26, SkillData.CurrentSkill.string_8);
              break;
            case 27:
              this.Skill27.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill27, SkillData.CurrentSkill.string_8);
              break;
            case 28:
              this.Skill28.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill28, SkillData.CurrentSkill.string_8);
              break;
            case 29:
              this.Skill29.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill29, SkillData.CurrentSkill.string_8);
              break;
            case 30:
              this.Skill30.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill30, SkillData.CurrentSkill.string_8);
              break;
            case 31:
              this.Skill31.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill31, SkillData.CurrentSkill.string_8);
              break;
            case 32:
              this.Skill32.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill32, SkillData.CurrentSkill.string_8);
              break;
            case 33:
              this.Skill33.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill33, SkillData.CurrentSkill.string_8);
              break;
            case 34:
              this.Skill34.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill34, SkillData.CurrentSkill.string_8);
              break;
            case 35:
              this.Skill35.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill35, SkillData.CurrentSkill.string_8);
              break;
            case 36:
              this.Skill36.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill36, SkillData.CurrentSkill.string_8);
              break;
            case 37:
              this.Skill37.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill37, SkillData.CurrentSkill.string_8);
              break;
            case 38:
              this.Skill38.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill38, SkillData.CurrentSkill.string_8);
              break;
            case 39:
              this.Skill39.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill39, SkillData.CurrentSkill.string_8);
              break;
            case 40:
              this.Skill40.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill40, SkillData.CurrentSkill.string_8);
              break;
            case 41:
              this.Skill41.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill41, SkillData.CurrentSkill.string_8);
              break;
            case 42:
              this.Skill42.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill42, SkillData.CurrentSkill.string_8);
              break;
            case 43:
              this.Skill43.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill43, SkillData.CurrentSkill.string_8);
              break;
            case 44:
              this.Skill44.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill44, SkillData.CurrentSkill.string_8);
              break;
            case 45:
              this.Skill45.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill45, SkillData.CurrentSkill.string_8);
              break;
            case 46:
              this.Skill46.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill46, SkillData.CurrentSkill.string_8);
              break;
            case 47:
              this.Skill47.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill47, SkillData.CurrentSkill.string_8);
              break;
            case 48:
              this.Skill48.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill48, SkillData.CurrentSkill.string_8);
              break;
            case 49:
              this.Skill49.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill49, SkillData.CurrentSkill.string_8);
              break;
            case 50:
              this.Skill50.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill50, SkillData.CurrentSkill.string_8);
              break;
            case 51:
              this.Skill51.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill51, SkillData.CurrentSkill.string_8);
              break;
            case 52:
              this.Skill52.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill52, SkillData.CurrentSkill.string_8);
              break;
            case 53:
              this.Skill53.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill53, SkillData.CurrentSkill.string_8);
              break;
            case 54:
              this.Skill54.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill54, SkillData.CurrentSkill.string_8);
              break;
            case 55:
              this.Skill55.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill55, SkillData.CurrentSkill.string_8);
              break;
            case 56:
              this.Skill56.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill56, SkillData.CurrentSkill.string_8);
              break;
            case 57:
              this.Skill57.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill57, SkillData.CurrentSkill.string_8);
              break;
            case 58:
              this.Skill58.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill58, SkillData.CurrentSkill.string_8);
              break;
            case 59:
              this.Skill59.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill59, SkillData.CurrentSkill.string_8);
              break;
            case 60:
              this.Skill60.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
              this.Emergente.SetToolTip((Control) this.Skill60, SkillData.CurrentSkill.string_8);
              break;
          }
        }
        checked { ++num4; }
      }
      return (object) true;
    }

    public object EditSkills(object CS)
    {
      string str1 = (SkillData.SelectedSkill.string_1.Length != 1 ? Conversion.Hex((object) SkillData.SelectedSkill.string_1) : "0" + Conversion.Hex((object) SkillData.SelectedSkill.string_1)) + "0000";
      int Start1 = !Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(CS, (object) 1, false) ? Conversions.ToInteger(Microsoft.VisualBasic.CompilerServices.Operators.AddObject(Microsoft.VisualBasic.CompilerServices.Operators.MultiplyObject(Microsoft.VisualBasic.CompilerServices.Operators.SubtractObject(CS, (object) 1), (object) 6), (object) 1)) : Conversions.ToInteger(CS);
      int num1;
      if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Strings.Mid(AccountData.CurrentCharacter.string_18, Start1, 6), "FF0000", false) != 0)
      {
        if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual((object) Interaction.MsgBox(RuntimeHelpers.GetObjectValue(LocalizedStrings.object_93), MsgBoxStyle.YesNo, RuntimeHelpers.GetObjectValue(LocalizedStrings.object_76)), (object) MsgBoxResult.Yes, false))
        {
          this.BorrarSkill(RuntimeHelpers.GetObjectValue(CS));
          this.Skills();
        }
        num1 = 0;
      }
      else
        num1 = 1;
      if (num1 == 1)
      {
        int num2 = Conversions.ToInteger(Microsoft.VisualBasic.CompilerServices.Operators.MultiplyObject(CS, (object) 6));
        int Start2 = checked (num2 + 1);
        string str2 = "0x" + (!Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(CS, (object) 1, false) ? Strings.Mid(AccountData.CurrentCharacter.string_18, 1, checked (num2 - 6)) + str1 + Strings.Mid(AccountData.CurrentCharacter.string_18, Start2) : str1 + Strings.Mid(AccountData.CurrentCharacter.string_18, 7));
        ConnectionManager.smethod_0();
        SqlConnectionPool.sqlConnection_1.Open();
        StoredProceduresManager.smethod_12((object) str2);
        try
        {
          SqlCommand sqlCommand1 = new SqlCommand();
          SqlCommand sqlCommand2 = new SqlCommand("MMK_SkillMaker", SqlConnectionPool.sqlConnection_1);
          sqlCommand2.CommandType = CommandType.StoredProcedure;
          sqlCommand2.Parameters.Add(new SqlParameter("@AccountID", SqlDbType.VarChar, 10)
          {
            Direction = ParameterDirection.Input
          });
          sqlCommand2.Parameters.Add(new SqlParameter("@Name", SqlDbType.VarChar, 10)
          {
            Direction = ParameterDirection.Input
          });
          sqlCommand2.Parameters["@AccountID"].Value = (object) AccountData.CurrentAccount.string_1;
          sqlCommand2.Parameters["@Name"].Value = (object) AccountData.CurrentCharacter.string_1;
          sqlCommand2.ExecuteNonQuery();
          sqlCommand2.Dispose();
          sqlCommand1.Dispose();
        }
        catch (Exception ex)
        {
          ProjectData.SetProjectError(ex);
          int num3 = (int) Interaction.MsgBox((object) "ERROR al Insertat el Skill!!", MsgBoxStyle.OkOnly, (object) null);
          ProjectData.ClearProjectError();
        }
        ConnectionManager.smethod_5();
        this.Skills();
      }
      return (object) true;
    }

    public object BorrarSkill(object CS)
    {
      int num1 = Conversions.ToInteger(Microsoft.VisualBasic.CompilerServices.Operators.MultiplyObject(CS, (object) 6));
      int Start = checked (num1 + 1);
      string str = "0x" + (!Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(CS, (object) 1, false) ? Strings.Mid(AccountData.CurrentCharacter.string_18, 1, checked (num1 - 6)) + "FF0000" + Strings.Mid(AccountData.CurrentCharacter.string_18, Start) : "FF0000" + Strings.Mid(AccountData.CurrentCharacter.string_18, 7));
      ConnectionManager.smethod_0();
      SqlConnectionPool.sqlConnection_1.Open();
      StoredProceduresManager.smethod_12((object) str);
      try
      {
        SqlCommand sqlCommand1 = new SqlCommand();
        SqlCommand sqlCommand2 = new SqlCommand("MMK_SkillMaker", SqlConnectionPool.sqlConnection_1);
        sqlCommand2.CommandType = CommandType.StoredProcedure;
        sqlCommand2.Parameters.Add(new SqlParameter("@AccountID", SqlDbType.VarChar, 10)
        {
          Direction = ParameterDirection.Input
        });
        sqlCommand2.Parameters.Add(new SqlParameter("@Name", SqlDbType.VarChar, 10)
        {
          Direction = ParameterDirection.Input
        });
        sqlCommand2.Parameters["@AccountID"].Value = (object) AccountData.CurrentAccount.string_1;
        sqlCommand2.Parameters["@Name"].Value = (object) AccountData.CurrentCharacter.string_1;
        sqlCommand2.ExecuteNonQuery();
        sqlCommand2.Dispose();
        sqlCommand1.Dispose();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num2 = (int) Interaction.MsgBox(RuntimeHelpers.GetObjectValue(LocalizedStrings.object_94), MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
      return (object) true;
    }

    public object ResetSkills()
    {
      StoredProceduresManager.smethod_8();
      ConnectionManager.smethod_0();
      SqlConnectionPool.sqlConnection_1.Open();
      try
      {
        SqlCommand sqlCommand1 = new SqlCommand();
        SqlCommand sqlCommand2 = new SqlCommand("MMK_SkillMaker", SqlConnectionPool.sqlConnection_1);
        sqlCommand2.CommandType = CommandType.StoredProcedure;
        sqlCommand2.Parameters.Add(new SqlParameter("@AccountID", SqlDbType.VarChar, 10)
        {
          Direction = ParameterDirection.Input
        });
        sqlCommand2.Parameters.Add(new SqlParameter("@Name", SqlDbType.VarChar, 10)
        {
          Direction = ParameterDirection.Input
        });
        sqlCommand2.Parameters["@AccountID"].Value = (object) AccountData.CurrentAccount.string_1;
        sqlCommand2.Parameters["@Name"].Value = (object) AccountData.CurrentCharacter.string_1;
        sqlCommand2.ExecuteNonQuery();
        sqlCommand2.Dispose();
        sqlCommand1.Dispose();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox(RuntimeHelpers.GetObjectValue(LocalizedStrings.object_98), MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
      return (object) true;
    }

    public object Traducir()
    {
      this.Foto.Text = Conversions.ToString(LocalizedStrings.object_9);
      this.Account.Text = Conversions.ToString(LocalizedStrings.object_5);
      this.Chart.Text = Conversions.ToString(LocalizedStrings.object_6);
      this.Text = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) (this.Text + " - "), Configuration.object_18));
      this.Titulo.Text = this.Text;
      return (object) true;
    }

    private void SkillMaker_Load(object sender, EventArgs e)
    {
      VentanaBarraLoad.DefInstance.Show();
      IniHelper.smethod_46();
      VentanaBarraLoad.DefInstance.Carga.Value = 10;
      VentanaBarraLoad.DefInstance.Carga.Value = 20;
      this.CargarCuentas();
      VentanaBarraLoad.DefInstance.Carga.Value = 60;
      VentanaBarraLoad.DefInstance.Carga.Value = 70;
      this.Tipo.SelectedIndex = 0;
      VentanaBarraLoad.DefInstance.Carga.Value = 80;
      StoredProceduresManager.smethod_1();
      VentanaBarraLoad.DefInstance.Carga.Value = 90;
      this.ExcepcionesOFF();
      this.Traducir();
      VentanaBarraLoad.DefInstance.Carga.Value = 100;
      VentanaBarraLoad.DefInstance.Hide();
    }

    private void Cuentas_SelectedIndexChanged(object sender, EventArgs e)
    {
      AccountData.CurrentAccount.string_1 = Conversions.ToString(this.Cuentas.SelectedItem);
      this.CargarPersonajes();
      this.ExcepcionesOFF();
      this.ResetearSkills();
      this.CuentaSkill.Text = "";
      this.ChartSkill.Text = "";
      this.NombreClase.Text = "";
    }

    private void Personajes_SelectedIndexChanged(object sender, EventArgs e)
    {
      AccountData.CurrentCharacter.string_1 = Conversions.ToString(this.Personajes.SelectedItem);
      this.CuentaSkill.Text = AccountData.CurrentAccount.string_1;
      this.ChartSkill.Text = AccountData.CurrentCharacter.string_1;
      this.ClasePersonaje();
      this.Skills();
      AccountStatusManager.smethod_0();
      this.ExcepcionesON();
    }

    private void Tipo_SelectedIndexChanged(object sender, EventArgs e)
    {
      ConnectionManager.smethod_10();
      int num1 = 0;
      try
      {
        SqlConnectionPool.oleDbConnection_0.Open();
        SqlConnectionPool.oleDbCommand_0.Connection = SqlConnectionPool.oleDbConnection_0;
        SqlConnectionPool.oleDbCommand_0.CommandText = "SELECT NAME FROM Skills WHERE CLASE='" + this.Tipo.Text + "' ORDER BY Nº ASC;";
        SqlConnectionPool.oleDbCommand_0.ExecuteNonQuery();
        SqlConnectionPool.oleDbDataReader_0 = SqlConnectionPool.oleDbCommand_0.ExecuteReader();
        this.Items.Items.Clear();
        num1 = 0;
        while (SqlConnectionPool.oleDbDataReader_0.Read())
        {
          this.Items.Items.Add((object) Conversions.ToString(SqlConnectionPool.oleDbDataReader_0["NAME"]));
          checked { ++num1; }
        }
        SqlConnectionPool.oleDbDataReader_0.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num2 = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_11();
      if (num1 <= 0)
        return;
      this.Items.SelectedIndex = 0;
      this.Items.Focus();
    }

    private void Items_SelectedIndexChanged(object sender, EventArgs e)
    {
      SkillDatabaseLoader.smethod_0((object) this.Items.Text);
      SkillImageHelper.smethod_0((object) SkillData.SelectedSkill.string_0);
      this.Imagen.Image = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) SkillImagePaths.string_0)));
      this.SkillTipo.Text = SkillData.SelectedSkill.string_4;
      this.SkillRango.Text = "Range : " + SkillData.SelectedSkill.string_5;
      this.Mana.Text = "Mana : " + SkillData.SelectedSkill.string_6;
      this.Estamina.Text = "Stamina : " + SkillData.SelectedSkill.string_7;
      this.Items.Focus();
    }

    private void Skill1_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 1);
      AccountStatusManager.smethod_0();
    }

    private void Skill2_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 2);
      AccountStatusManager.smethod_0();
    }

    private void Skill3_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 3);
      AccountStatusManager.smethod_0();
    }

    private void Skill4_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 4);
      AccountStatusManager.smethod_0();
    }

    private void Skill5_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 5);
      AccountStatusManager.smethod_0();
    }

    private void Skill6_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 6);
      AccountStatusManager.smethod_0();
    }

    private void Skill7_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 7);
      AccountStatusManager.smethod_0();
    }

    private void Skill8_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 8);
      AccountStatusManager.smethod_0();
    }

    private void Skill9_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 9);
      AccountStatusManager.smethod_0();
    }

    private void Skill10_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 10);
      AccountStatusManager.smethod_0();
    }

    private void Skill11_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 11);
      AccountStatusManager.smethod_0();
    }

    private void Skill12_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 12);
      AccountStatusManager.smethod_0();
    }

    private void Skill13_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 13);
      AccountStatusManager.smethod_0();
    }

    private void Skill14_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 14);
      AccountStatusManager.smethod_0();
    }

    private void Skill15_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 15);
      AccountStatusManager.smethod_0();
    }

    private void Skill16_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 16);
      AccountStatusManager.smethod_0();
    }

    private void Skill17_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 17);
      AccountStatusManager.smethod_0();
    }

    private void Skill18_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 18);
      AccountStatusManager.smethod_0();
    }

    private void Skill19_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 19);
      AccountStatusManager.smethod_0();
    }

    private void Skill20_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 20);
      AccountStatusManager.smethod_0();
    }

    private void Skill21_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 21);
      AccountStatusManager.smethod_0();
    }

    private void Skill22_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 22);
      AccountStatusManager.smethod_0();
    }

    private void Skill23_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 23);
      AccountStatusManager.smethod_0();
    }

    private void Skill24_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 24);
      AccountStatusManager.smethod_0();
    }

    private void Skill25_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 25);
      AccountStatusManager.smethod_0();
    }

    private void Skill26_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 26);
      AccountStatusManager.smethod_0();
    }

    private void Skill27_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 27);
      AccountStatusManager.smethod_0();
    }

    private void Skill28_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 28);
      AccountStatusManager.smethod_0();
    }

    private void Skill29_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 29);
      AccountStatusManager.smethod_0();
    }

    private void Skill30_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 30);
      AccountStatusManager.smethod_0();
    }

    private void Skill31_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 31);
      AccountStatusManager.smethod_0();
    }

    private void Skill32_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 32);
      AccountStatusManager.smethod_0();
    }

    private void Skill33_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 33);
      AccountStatusManager.smethod_0();
    }

    private void Skill34_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 34);
      AccountStatusManager.smethod_0();
    }

    private void Skill35_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 35);
      AccountStatusManager.smethod_0();
    }

    private void Skill36_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 36);
      AccountStatusManager.smethod_0();
    }

    private void Skill37_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 37);
      AccountStatusManager.smethod_0();
    }

    private void Skill38_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 38);
      AccountStatusManager.smethod_0();
    }

    private void Skill39_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 39);
      AccountStatusManager.smethod_0();
    }

    private void Skill40_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 40);
      AccountStatusManager.smethod_0();
    }

    private void Skill41_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 41);
      AccountStatusManager.smethod_0();
    }

    private void Skill42_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 42);
      AccountStatusManager.smethod_0();
    }

    private void Skill43_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 43);
      AccountStatusManager.smethod_0();
    }

    private void Skill44_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 44);
      AccountStatusManager.smethod_0();
    }

    private void Skill45_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 45);
      AccountStatusManager.smethod_0();
    }

    private void Skill46_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 46);
      AccountStatusManager.smethod_0();
    }

    private void Skill47_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 47);
      AccountStatusManager.smethod_0();
    }

    private void Skill48_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 48);
      AccountStatusManager.smethod_0();
    }

    private void Skill49_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 49);
      AccountStatusManager.smethod_0();
    }

    private void Skill50_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 50);
      AccountStatusManager.smethod_0();
    }

    private void Skill51_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 51);
      AccountStatusManager.smethod_0();
    }

    private void Skill52_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 52);
      AccountStatusManager.smethod_0();
    }

    private void Skill53_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 53);
      AccountStatusManager.smethod_0();
    }

    private void Skill54_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 54);
      AccountStatusManager.smethod_0();
    }

    private void Skill55_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 55);
      AccountStatusManager.smethod_0();
    }

    private void Skill56_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 56);
      AccountStatusManager.smethod_0();
    }

    private void Skill57_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 57);
      AccountStatusManager.smethod_0();
    }

    private void Skill58_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 58);
      AccountStatusManager.smethod_0();
    }

    private void Skill59_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 59);
      AccountStatusManager.smethod_0();
    }

    private void Skill60_Click(object sender, EventArgs e)
    {
      this.EditSkills((object) 60);
      AccountStatusManager.smethod_0();
    }

    private void method_0(object sender, EventArgs e)
    {
      if (this.CuentaSearch.Text.Length > 0)
        this.Cuentas.SelectedItem = (object) this.CuentaSearch.Text;
      if (this.PersonajeSearch.Text.Length > 0)
      {
        ConnectionManager.smethod_0();
        try
        {
          SqlConnectionPool.sqlConnection_1.Open();
          SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
          SqlConnectionPool.sqlCommand_1.CommandText = "SELECT AccountID FROM Character WHere Name='" + this.PersonajeSearch.Text + "'";
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
      this.Items.Focus();
    }

    private void ONLineInfo_Click(object sender, EventArgs e)
    {
      this.CheckOnLine();
      this.Items.Focus();
    }

    private void method_1(object sender, EventArgs e)
    {
      this.Items.Focus();
      if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual((object) Interaction.MsgBox(RuntimeHelpers.GetObjectValue(LocalizedStrings.object_97), MsgBoxStyle.YesNo, RuntimeHelpers.GetObjectValue(LocalizedStrings.object_76)), (object) MsgBoxResult.Yes, false))
        this.ResetSkills();
      this.Skills();
    }

    private void method_2(object sender, EventArgs e)
    {
      SkillMaker.DefInstance.WindowState = FormWindowState.Minimized;
    }

    private void method_3(object sender, EventArgs e)
    {
      this.Close();
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

    private void SkillMaker_Closing(object sender, CancelEventArgs e)
    {
      IniHelper.smethod_47();
      IniHelper.smethod_3();
    }

    private void method_4(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.ClearSkills.BackgroundImage = (Image) EmbeddedResources.smethod_53();
    }

    private void method_5(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.ClearSkills.BackgroundImage = (Image) EmbeddedResources.smethod_54();
    }

    private void method_6(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Minimizar.BackgroundImage = (Image) EmbeddedResources.smethod_86();
    }

    private void method_7(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Minimizar.BackgroundImage = (Image) EmbeddedResources.smethod_87();
    }

    private void method_8(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) EmbeddedResources.smethod_39();
    }

    private void method_9(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) EmbeddedResources.smethod_40();
    }

    private void method_10(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Buscar.BackgroundImage = (Image) EmbeddedResources.smethod_12();
    }

    private void method_11(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Buscar.BackgroundImage = (Image) EmbeddedResources.smethod_13();
    }

    private void PersonajeSearch_KeyPress(object sender, KeyPressEventArgs e)
    {
      if ((int) checked ((short) Strings.Asc(e.KeyChar)) != 13)
        return;
      this.method_0(RuntimeHelpers.GetObjectValue(sender), (EventArgs) e);
    }

    private void CuentaSearch_KeyPress(object sender, KeyPressEventArgs e)
    {
      if ((int) checked ((short) Strings.Asc(e.KeyChar)) != 13)
        return;
      this.method_0(RuntimeHelpers.GetObjectValue(sender), (EventArgs) e);
    }
  }
}
