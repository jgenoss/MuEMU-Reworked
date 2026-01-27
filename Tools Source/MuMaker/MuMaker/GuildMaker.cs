// Decompiled with JetBrains decompiler
// Type: MuMaker.GuildMaker
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
using System.Windows.Forms;

namespace MuMaker
{
  [DesignerGenerated]
  public class GuildMaker : Form
  {
    private static GuildMaker guildMaker_0 = (GuildMaker) null;
    private IContainer icontainer_0;
    [AccessedThroughProperty("Personajes")]
    private ComboBox _Personajes;
    [AccessedThroughProperty("Guilds")]
    private ComboBox _Guilds;
    [AccessedThroughProperty("PersonajeSearch")]
    private TextBox _PersonajeSearch;
    [AccessedThroughProperty("GuildSearch")]
    private TextBox _GuildSearch;
    [AccessedThroughProperty("GuildsL")]
    private Label _GuildsL;
    [AccessedThroughProperty("Chart")]
    private Label _Chart;
    [AccessedThroughProperty("CreateGuild")]
    private Button _CreateGuild;
    [AccessedThroughProperty("BorrarGuild")]
    private Button _BorrarGuild;
    [AccessedThroughProperty("MK1")]
    private Label _MK1;
    [AccessedThroughProperty("MK2")]
    private Label _MK2;
    [AccessedThroughProperty("MK3")]
    private Label _MK3;
    [AccessedThroughProperty("MK4")]
    private Label _MK4;
    [AccessedThroughProperty("MK5")]
    private Label _MK5;
    [AccessedThroughProperty("MK6")]
    private Label _MK6;
    [AccessedThroughProperty("MK7")]
    private Label _MK7;
    [AccessedThroughProperty("MK15")]
    private Label _MK15;
    [AccessedThroughProperty("MK14")]
    private Label _MK14;
    [AccessedThroughProperty("MK13")]
    private Label _MK13;
    [AccessedThroughProperty("MK12")]
    private Label _MK12;
    [AccessedThroughProperty("MK11")]
    private Label _MK11;
    [AccessedThroughProperty("MK10")]
    private Label _MK10;
    [AccessedThroughProperty("MK9")]
    private Label _MK9;
    [AccessedThroughProperty("MK23")]
    private Label _MK23;
    [AccessedThroughProperty("MK22")]
    private Label _MK22;
    [AccessedThroughProperty("MK21")]
    private Label _MK21;
    [AccessedThroughProperty("MK20")]
    private Label _MK20;
    [AccessedThroughProperty("MK19")]
    private Label _MK19;
    [AccessedThroughProperty("MK18")]
    private Label _MK18;
    [AccessedThroughProperty("MK17")]
    private Label _MK17;
    [AccessedThroughProperty("MK31")]
    private Label _MK31;
    [AccessedThroughProperty("MK30")]
    private Label _MK30;
    [AccessedThroughProperty("MK29")]
    private Label _MK29;
    [AccessedThroughProperty("MK28")]
    private Label _MK28;
    [AccessedThroughProperty("MK27")]
    private Label _MK27;
    [AccessedThroughProperty("MK26")]
    private Label _MK26;
    [AccessedThroughProperty("MK25")]
    private Label _MK25;
    [AccessedThroughProperty("MK39")]
    private Label _MK39;
    [AccessedThroughProperty("MK38")]
    private Label _MK38;
    [AccessedThroughProperty("MK37")]
    private Label _MK37;
    [AccessedThroughProperty("MK36")]
    private Label _MK36;
    [AccessedThroughProperty("MK35")]
    private Label _MK35;
    [AccessedThroughProperty("MK34")]
    private Label _MK34;
    [AccessedThroughProperty("MK33")]
    private Label _MK33;
    [AccessedThroughProperty("MK47")]
    private Label _MK47;
    [AccessedThroughProperty("MK46")]
    private Label _MK46;
    [AccessedThroughProperty("MK45")]
    private Label _MK45;
    [AccessedThroughProperty("MK44")]
    private Label _MK44;
    [AccessedThroughProperty("MK43")]
    private Label _MK43;
    [AccessedThroughProperty("MK42")]
    private Label _MK42;
    [AccessedThroughProperty("MK41")]
    private Label _MK41;
    [AccessedThroughProperty("MK55")]
    private Label _MK55;
    [AccessedThroughProperty("MK54")]
    private Label _MK54;
    [AccessedThroughProperty("MK53")]
    private Label _MK53;
    [AccessedThroughProperty("MK52")]
    private Label _MK52;
    [AccessedThroughProperty("MK51")]
    private Label _MK51;
    [AccessedThroughProperty("MK50")]
    private Label _MK50;
    [AccessedThroughProperty("MK49")]
    private Label _MK49;
    [AccessedThroughProperty("MK63")]
    private Label _MK63;
    [AccessedThroughProperty("MK62")]
    private Label _MK62;
    [AccessedThroughProperty("MK61")]
    private Label _MK61;
    [AccessedThroughProperty("MK60")]
    private Label _MK60;
    [AccessedThroughProperty("MK59")]
    private Label _MK59;
    [AccessedThroughProperty("MK58")]
    private Label _MK58;
    [AccessedThroughProperty("MK57")]
    private Label _MK57;
    [AccessedThroughProperty("MK64")]
    private Label _MK64;
    [AccessedThroughProperty("MK56")]
    private Label _MK56;
    [AccessedThroughProperty("MK48")]
    private Label _MK48;
    [AccessedThroughProperty("MK40")]
    private Label _MK40;
    [AccessedThroughProperty("MK32")]
    private Label _MK32;
    [AccessedThroughProperty("MK24")]
    private Label _MK24;
    [AccessedThroughProperty("MK16")]
    private Label _MK16;
    [AccessedThroughProperty("MK8")]
    private Label _MK8;
    [AccessedThroughProperty("Integrantes")]
    private ListBox _Integrantes;
    [AccessedThroughProperty("Puntos")]
    private TextBox _Puntos;
    [AccessedThroughProperty("GuildName")]
    private TextBox _GuildName;
    [AccessedThroughProperty("Tipo")]
    private TextBox _Tipo;
    [AccessedThroughProperty("Noticia")]
    private TextBox _Noticia;
    [AccessedThroughProperty("GL1")]
    private RadioButton _GL1;
    [AccessedThroughProperty("GL4")]
    private RadioButton _GL4;
    [AccessedThroughProperty("GL3")]
    private RadioButton _GL3;
    [AccessedThroughProperty("GL2")]
    private RadioButton _GL2;
    [AccessedThroughProperty("Label1")]
    private Label _Label1;
    [AccessedThroughProperty("Label2")]
    private Label _Label2;
    [AccessedThroughProperty("CL1")]
    private Label _CL1;
    [AccessedThroughProperty("CL64")]
    private Label _CL64;
    [AccessedThroughProperty("CL2")]
    private Label _CL2;
    [AccessedThroughProperty("CL56")]
    private Label _CL56;
    [AccessedThroughProperty("CL3")]
    private Label _CL3;
    [AccessedThroughProperty("CL48")]
    private Label _CL48;
    [AccessedThroughProperty("CL4")]
    private Label _CL4;
    [AccessedThroughProperty("CL40")]
    private Label _CL40;
    [AccessedThroughProperty("CL5")]
    private Label _CL5;
    [AccessedThroughProperty("CL32")]
    private Label _CL32;
    [AccessedThroughProperty("CL6")]
    private Label _CL6;
    [AccessedThroughProperty("CL24")]
    private Label _CL24;
    [AccessedThroughProperty("CL7")]
    private Label _CL7;
    [AccessedThroughProperty("CL16")]
    private Label _CL16;
    [AccessedThroughProperty("CL9")]
    private Label _CL9;
    [AccessedThroughProperty("CL8")]
    private Label _CL8;
    [AccessedThroughProperty("CL10")]
    private Label _CL10;
    [AccessedThroughProperty("CL63")]
    private Label _CL63;
    [AccessedThroughProperty("CL11")]
    private Label _CL11;
    [AccessedThroughProperty("CL37")]
    private Label _CL37;
    [AccessedThroughProperty("CL62")]
    private Label _CL62;
    [AccessedThroughProperty("CL36")]
    private Label _CL36;
    [AccessedThroughProperty("CL12")]
    private Label _CL12;
    [AccessedThroughProperty("CL38")]
    private Label _CL38;
    [AccessedThroughProperty("CL61")]
    private Label _CL61;
    [AccessedThroughProperty("CL35")]
    private Label _CL35;
    [AccessedThroughProperty("CL13")]
    private Label _CL13;
    [AccessedThroughProperty("CL39")]
    private Label _CL39;
    [AccessedThroughProperty("CL60")]
    private Label _CL60;
    [AccessedThroughProperty("CL34")]
    private Label _CL34;
    [AccessedThroughProperty("CL14")]
    private Label _CL14;
    [AccessedThroughProperty("CL41")]
    private Label _CL41;
    [AccessedThroughProperty("CL59")]
    private Label _CL59;
    [AccessedThroughProperty("CL33")]
    private Label _CL33;
    [AccessedThroughProperty("CL15")]
    private Label _CL15;
    [AccessedThroughProperty("CL42")]
    private Label _CL42;
    [AccessedThroughProperty("CL58")]
    private Label _CL58;
    [AccessedThroughProperty("CL31")]
    private Label _CL31;
    [AccessedThroughProperty("CL17")]
    private Label _CL17;
    [AccessedThroughProperty("CL43")]
    private Label _CL43;
    [AccessedThroughProperty("CL57")]
    private Label _CL57;
    [AccessedThroughProperty("CL30")]
    private Label _CL30;
    [AccessedThroughProperty("CL18")]
    private Label _CL18;
    [AccessedThroughProperty("CL44")]
    private Label _CL44;
    [AccessedThroughProperty("CL55")]
    private Label _CL55;
    [AccessedThroughProperty("CL29")]
    private Label _CL29;
    [AccessedThroughProperty("CL19")]
    private Label _CL19;
    [AccessedThroughProperty("CL45")]
    private Label _CL45;
    [AccessedThroughProperty("CL54")]
    private Label _CL54;
    [AccessedThroughProperty("CL28")]
    private Label _CL28;
    [AccessedThroughProperty("CL20")]
    private Label _CL20;
    [AccessedThroughProperty("CL46")]
    private Label _CL46;
    [AccessedThroughProperty("CL53")]
    private Label _CL53;
    [AccessedThroughProperty("CL27")]
    private Label _CL27;
    [AccessedThroughProperty("CL21")]
    private Label _CL21;
    [AccessedThroughProperty("CL47")]
    private Label _CL47;
    [AccessedThroughProperty("CL52")]
    private Label _CL52;
    [AccessedThroughProperty("CL26")]
    private Label _CL26;
    [AccessedThroughProperty("CL22")]
    private Label _CL22;
    [AccessedThroughProperty("CL49")]
    private Label _CL49;
    [AccessedThroughProperty("CL51")]
    private Label _CL51;
    [AccessedThroughProperty("CL25")]
    private Label _CL25;
    [AccessedThroughProperty("CL23")]
    private Label _CL23;
    [AccessedThroughProperty("CL50")]
    private Label _CL50;
    [AccessedThroughProperty("MasterGuild")]
    private ComboBox _MasterGuild;
    [AccessedThroughProperty("Label67")]
    private Label _Label67;
    [AccessedThroughProperty("Label68")]
    private Label _Label68;
    [AccessedThroughProperty("GuildsEnemy")]
    private ListBox _GuildsEnemy;
    [AccessedThroughProperty("GuildsFriend")]
    private ListBox _GuildsFriend;
    [AccessedThroughProperty("Label69")]
    private Label _Label69;
    [AccessedThroughProperty("Label70")]
    private Label _Label70;
    [AccessedThroughProperty("C1")]
    private Label _C1;
    [AccessedThroughProperty("C2")]
    private Label _C2;
    [AccessedThroughProperty("C3")]
    private Label _C3;
    [AccessedThroughProperty("C4")]
    private Label _C4;
    [AccessedThroughProperty("C5")]
    private Label _C5;
    [AccessedThroughProperty("C6")]
    private Label _C6;
    [AccessedThroughProperty("C7")]
    private Label _C7;
    [AccessedThroughProperty("C16")]
    private Label _C16;
    [AccessedThroughProperty("C9")]
    private Label _C9;
    [AccessedThroughProperty("C8")]
    private Label _C8;
    [AccessedThroughProperty("C10")]
    private Label _C10;
    [AccessedThroughProperty("C11")]
    private Label _C11;
    [AccessedThroughProperty("C12")]
    private Label _C12;
    [AccessedThroughProperty("C13")]
    private Label _C13;
    [AccessedThroughProperty("C14")]
    private Label _C14;
    [AccessedThroughProperty("C15")]
    private Label _C15;
    [AccessedThroughProperty("CurrentColor")]
    private Label _CurrentColor;
    [AccessedThroughProperty("Label88")]
    private Label _Label88;
    [AccessedThroughProperty("NameGuild")]
    private Label _NameGuild;
    [AccessedThroughProperty("GuildMaster")]
    private Label _GuildMaster;
    [AccessedThroughProperty("Aplicar")]
    private Button _Aplicar;
    [AccessedThroughProperty("Reload")]
    private Button _Reload;
    [AccessedThroughProperty("Buscar")]
    private Button _Buscar;
    [AccessedThroughProperty("BorrarDatos")]
    private Button _BorrarDatos;
    [AccessedThroughProperty("Cerrar")]
    private Button _Cerrar;
    [AccessedThroughProperty("Minimizar")]
    private Button _Minimizar;
    [AccessedThroughProperty("Titulo")]
    private Label _Titulo;
    private const int int_0 = 132;
    private const int int_1 = 1;
    private const int int_2 = 2;

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

    internal virtual ComboBox Guilds
    {
      [DebuggerNonUserCode] get
      {
        return this._Guilds;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Guilds_SelectedIndexChanged);
        if (this._Guilds != null)
          this._Guilds.SelectedIndexChanged -= eventHandler;
        this._Guilds = value;
        if (this._Guilds == null)
          return;
        this._Guilds.SelectedIndexChanged += eventHandler;
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

    internal virtual TextBox GuildSearch
    {
      [DebuggerNonUserCode] get
      {
        return this._GuildSearch;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.GuildSearch_KeyPress);
        if (this._GuildSearch != null)
          this._GuildSearch.KeyPress -= pressEventHandler;
        this._GuildSearch = value;
        if (this._GuildSearch == null)
          return;
        this._GuildSearch.KeyPress += pressEventHandler;
      }
    }

    internal virtual Label GuildsL
    {
      [DebuggerNonUserCode] get
      {
        return this._GuildsL;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._GuildsL = value;
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

    internal virtual Button CreateGuild
    {
      [DebuggerNonUserCode] get
      {
        return this._CreateGuild;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_4);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_17);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_16);
        if (this._CreateGuild != null)
        {
          this._CreateGuild.Click -= eventHandler;
          this._CreateGuild.MouseDown -= mouseEventHandler1;
          this._CreateGuild.MouseUp -= mouseEventHandler2;
        }
        this._CreateGuild = value;
        if (this._CreateGuild == null)
          return;
        this._CreateGuild.Click += eventHandler;
        this._CreateGuild.MouseDown += mouseEventHandler1;
        this._CreateGuild.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual Button BorrarGuild
    {
      [DebuggerNonUserCode] get
      {
        return this._BorrarGuild;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_21);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_20);
        EventHandler eventHandler = new EventHandler(this.method_5);
        if (this._BorrarGuild != null)
        {
          this._BorrarGuild.MouseDown -= mouseEventHandler1;
          this._BorrarGuild.MouseUp -= mouseEventHandler2;
          this._BorrarGuild.Click -= eventHandler;
        }
        this._BorrarGuild = value;
        if (this._BorrarGuild == null)
          return;
        this._BorrarGuild.MouseDown += mouseEventHandler1;
        this._BorrarGuild.MouseUp += mouseEventHandler2;
        this._BorrarGuild.Click += eventHandler;
      }
    }

    internal virtual Label MK1
    {
      [DebuggerNonUserCode] get
      {
        return this._MK1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK1_Click);
        if (this._MK1 != null)
          this._MK1.Click -= eventHandler;
        this._MK1 = value;
        if (this._MK1 == null)
          return;
        this._MK1.Click += eventHandler;
      }
    }

    internal virtual Label MK2
    {
      [DebuggerNonUserCode] get
      {
        return this._MK2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK2_Click);
        if (this._MK2 != null)
          this._MK2.Click -= eventHandler;
        this._MK2 = value;
        if (this._MK2 == null)
          return;
        this._MK2.Click += eventHandler;
      }
    }

    internal virtual Label MK3
    {
      [DebuggerNonUserCode] get
      {
        return this._MK3;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK3_Click);
        if (this._MK3 != null)
          this._MK3.Click -= eventHandler;
        this._MK3 = value;
        if (this._MK3 == null)
          return;
        this._MK3.Click += eventHandler;
      }
    }

    internal virtual Label MK4
    {
      [DebuggerNonUserCode] get
      {
        return this._MK4;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK4_Click);
        if (this._MK4 != null)
          this._MK4.Click -= eventHandler;
        this._MK4 = value;
        if (this._MK4 == null)
          return;
        this._MK4.Click += eventHandler;
      }
    }

    internal virtual Label MK5
    {
      [DebuggerNonUserCode] get
      {
        return this._MK5;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK5_Click);
        if (this._MK5 != null)
          this._MK5.Click -= eventHandler;
        this._MK5 = value;
        if (this._MK5 == null)
          return;
        this._MK5.Click += eventHandler;
      }
    }

    internal virtual Label MK6
    {
      [DebuggerNonUserCode] get
      {
        return this._MK6;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK6_Click);
        if (this._MK6 != null)
          this._MK6.Click -= eventHandler;
        this._MK6 = value;
        if (this._MK6 == null)
          return;
        this._MK6.Click += eventHandler;
      }
    }

    internal virtual Label MK7
    {
      [DebuggerNonUserCode] get
      {
        return this._MK7;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK7_Click);
        if (this._MK7 != null)
          this._MK7.Click -= eventHandler;
        this._MK7 = value;
        if (this._MK7 == null)
          return;
        this._MK7.Click += eventHandler;
      }
    }

    internal virtual Label MK15
    {
      [DebuggerNonUserCode] get
      {
        return this._MK15;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK15_Click);
        if (this._MK15 != null)
          this._MK15.Click -= eventHandler;
        this._MK15 = value;
        if (this._MK15 == null)
          return;
        this._MK15.Click += eventHandler;
      }
    }

    internal virtual Label MK14
    {
      [DebuggerNonUserCode] get
      {
        return this._MK14;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK14_Click);
        if (this._MK14 != null)
          this._MK14.Click -= eventHandler;
        this._MK14 = value;
        if (this._MK14 == null)
          return;
        this._MK14.Click += eventHandler;
      }
    }

    internal virtual Label MK13
    {
      [DebuggerNonUserCode] get
      {
        return this._MK13;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK13_Click);
        if (this._MK13 != null)
          this._MK13.Click -= eventHandler;
        this._MK13 = value;
        if (this._MK13 == null)
          return;
        this._MK13.Click += eventHandler;
      }
    }

    internal virtual Label MK12
    {
      [DebuggerNonUserCode] get
      {
        return this._MK12;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK12_Click);
        if (this._MK12 != null)
          this._MK12.Click -= eventHandler;
        this._MK12 = value;
        if (this._MK12 == null)
          return;
        this._MK12.Click += eventHandler;
      }
    }

    internal virtual Label MK11
    {
      [DebuggerNonUserCode] get
      {
        return this._MK11;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK11_Click);
        if (this._MK11 != null)
          this._MK11.Click -= eventHandler;
        this._MK11 = value;
        if (this._MK11 == null)
          return;
        this._MK11.Click += eventHandler;
      }
    }

    internal virtual Label MK10
    {
      [DebuggerNonUserCode] get
      {
        return this._MK10;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK10_Click);
        if (this._MK10 != null)
          this._MK10.Click -= eventHandler;
        this._MK10 = value;
        if (this._MK10 == null)
          return;
        this._MK10.Click += eventHandler;
      }
    }

    internal virtual Label MK9
    {
      [DebuggerNonUserCode] get
      {
        return this._MK9;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK9_Click);
        if (this._MK9 != null)
          this._MK9.Click -= eventHandler;
        this._MK9 = value;
        if (this._MK9 == null)
          return;
        this._MK9.Click += eventHandler;
      }
    }

    internal virtual Label MK23
    {
      [DebuggerNonUserCode] get
      {
        return this._MK23;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK23_Click);
        if (this._MK23 != null)
          this._MK23.Click -= eventHandler;
        this._MK23 = value;
        if (this._MK23 == null)
          return;
        this._MK23.Click += eventHandler;
      }
    }

    internal virtual Label MK22
    {
      [DebuggerNonUserCode] get
      {
        return this._MK22;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK22_Click);
        if (this._MK22 != null)
          this._MK22.Click -= eventHandler;
        this._MK22 = value;
        if (this._MK22 == null)
          return;
        this._MK22.Click += eventHandler;
      }
    }

    internal virtual Label MK21
    {
      [DebuggerNonUserCode] get
      {
        return this._MK21;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK21_Click);
        if (this._MK21 != null)
          this._MK21.Click -= eventHandler;
        this._MK21 = value;
        if (this._MK21 == null)
          return;
        this._MK21.Click += eventHandler;
      }
    }

    internal virtual Label MK20
    {
      [DebuggerNonUserCode] get
      {
        return this._MK20;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK20_Click);
        if (this._MK20 != null)
          this._MK20.Click -= eventHandler;
        this._MK20 = value;
        if (this._MK20 == null)
          return;
        this._MK20.Click += eventHandler;
      }
    }

    internal virtual Label MK19
    {
      [DebuggerNonUserCode] get
      {
        return this._MK19;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK19_Click);
        if (this._MK19 != null)
          this._MK19.Click -= eventHandler;
        this._MK19 = value;
        if (this._MK19 == null)
          return;
        this._MK19.Click += eventHandler;
      }
    }

    internal virtual Label MK18
    {
      [DebuggerNonUserCode] get
      {
        return this._MK18;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK18_Click);
        if (this._MK18 != null)
          this._MK18.Click -= eventHandler;
        this._MK18 = value;
        if (this._MK18 == null)
          return;
        this._MK18.Click += eventHandler;
      }
    }

    internal virtual Label MK17
    {
      [DebuggerNonUserCode] get
      {
        return this._MK17;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK17_Click);
        if (this._MK17 != null)
          this._MK17.Click -= eventHandler;
        this._MK17 = value;
        if (this._MK17 == null)
          return;
        this._MK17.Click += eventHandler;
      }
    }

    internal virtual Label MK31
    {
      [DebuggerNonUserCode] get
      {
        return this._MK31;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK31_Click);
        if (this._MK31 != null)
          this._MK31.Click -= eventHandler;
        this._MK31 = value;
        if (this._MK31 == null)
          return;
        this._MK31.Click += eventHandler;
      }
    }

    internal virtual Label MK30
    {
      [DebuggerNonUserCode] get
      {
        return this._MK30;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK30_Click);
        if (this._MK30 != null)
          this._MK30.Click -= eventHandler;
        this._MK30 = value;
        if (this._MK30 == null)
          return;
        this._MK30.Click += eventHandler;
      }
    }

    internal virtual Label MK29
    {
      [DebuggerNonUserCode] get
      {
        return this._MK29;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK29_Click);
        if (this._MK29 != null)
          this._MK29.Click -= eventHandler;
        this._MK29 = value;
        if (this._MK29 == null)
          return;
        this._MK29.Click += eventHandler;
      }
    }

    internal virtual Label MK28
    {
      [DebuggerNonUserCode] get
      {
        return this._MK28;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK28_Click);
        if (this._MK28 != null)
          this._MK28.Click -= eventHandler;
        this._MK28 = value;
        if (this._MK28 == null)
          return;
        this._MK28.Click += eventHandler;
      }
    }

    internal virtual Label MK27
    {
      [DebuggerNonUserCode] get
      {
        return this._MK27;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK27_Click);
        if (this._MK27 != null)
          this._MK27.Click -= eventHandler;
        this._MK27 = value;
        if (this._MK27 == null)
          return;
        this._MK27.Click += eventHandler;
      }
    }

    internal virtual Label MK26
    {
      [DebuggerNonUserCode] get
      {
        return this._MK26;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK26_Click);
        if (this._MK26 != null)
          this._MK26.Click -= eventHandler;
        this._MK26 = value;
        if (this._MK26 == null)
          return;
        this._MK26.Click += eventHandler;
      }
    }

    internal virtual Label MK25
    {
      [DebuggerNonUserCode] get
      {
        return this._MK25;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK25_Click);
        if (this._MK25 != null)
          this._MK25.Click -= eventHandler;
        this._MK25 = value;
        if (this._MK25 == null)
          return;
        this._MK25.Click += eventHandler;
      }
    }

    internal virtual Label MK39
    {
      [DebuggerNonUserCode] get
      {
        return this._MK39;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK39_Click);
        if (this._MK39 != null)
          this._MK39.Click -= eventHandler;
        this._MK39 = value;
        if (this._MK39 == null)
          return;
        this._MK39.Click += eventHandler;
      }
    }

    internal virtual Label MK38
    {
      [DebuggerNonUserCode] get
      {
        return this._MK38;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK38_Click);
        if (this._MK38 != null)
          this._MK38.Click -= eventHandler;
        this._MK38 = value;
        if (this._MK38 == null)
          return;
        this._MK38.Click += eventHandler;
      }
    }

    internal virtual Label MK37
    {
      [DebuggerNonUserCode] get
      {
        return this._MK37;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK37_Click);
        if (this._MK37 != null)
          this._MK37.Click -= eventHandler;
        this._MK37 = value;
        if (this._MK37 == null)
          return;
        this._MK37.Click += eventHandler;
      }
    }

    internal virtual Label MK36
    {
      [DebuggerNonUserCode] get
      {
        return this._MK36;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK36_Click);
        if (this._MK36 != null)
          this._MK36.Click -= eventHandler;
        this._MK36 = value;
        if (this._MK36 == null)
          return;
        this._MK36.Click += eventHandler;
      }
    }

    internal virtual Label MK35
    {
      [DebuggerNonUserCode] get
      {
        return this._MK35;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK35_Click);
        if (this._MK35 != null)
          this._MK35.Click -= eventHandler;
        this._MK35 = value;
        if (this._MK35 == null)
          return;
        this._MK35.Click += eventHandler;
      }
    }

    internal virtual Label MK34
    {
      [DebuggerNonUserCode] get
      {
        return this._MK34;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK34_Click);
        if (this._MK34 != null)
          this._MK34.Click -= eventHandler;
        this._MK34 = value;
        if (this._MK34 == null)
          return;
        this._MK34.Click += eventHandler;
      }
    }

    internal virtual Label MK33
    {
      [DebuggerNonUserCode] get
      {
        return this._MK33;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK33_Click);
        if (this._MK33 != null)
          this._MK33.Click -= eventHandler;
        this._MK33 = value;
        if (this._MK33 == null)
          return;
        this._MK33.Click += eventHandler;
      }
    }

    internal virtual Label MK47
    {
      [DebuggerNonUserCode] get
      {
        return this._MK47;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK47_Click);
        if (this._MK47 != null)
          this._MK47.Click -= eventHandler;
        this._MK47 = value;
        if (this._MK47 == null)
          return;
        this._MK47.Click += eventHandler;
      }
    }

    internal virtual Label MK46
    {
      [DebuggerNonUserCode] get
      {
        return this._MK46;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK46_Click);
        if (this._MK46 != null)
          this._MK46.Click -= eventHandler;
        this._MK46 = value;
        if (this._MK46 == null)
          return;
        this._MK46.Click += eventHandler;
      }
    }

    internal virtual Label MK45
    {
      [DebuggerNonUserCode] get
      {
        return this._MK45;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK45_Click);
        if (this._MK45 != null)
          this._MK45.Click -= eventHandler;
        this._MK45 = value;
        if (this._MK45 == null)
          return;
        this._MK45.Click += eventHandler;
      }
    }

    internal virtual Label MK44
    {
      [DebuggerNonUserCode] get
      {
        return this._MK44;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK44_Click);
        if (this._MK44 != null)
          this._MK44.Click -= eventHandler;
        this._MK44 = value;
        if (this._MK44 == null)
          return;
        this._MK44.Click += eventHandler;
      }
    }

    internal virtual Label MK43
    {
      [DebuggerNonUserCode] get
      {
        return this._MK43;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK43_Click);
        if (this._MK43 != null)
          this._MK43.Click -= eventHandler;
        this._MK43 = value;
        if (this._MK43 == null)
          return;
        this._MK43.Click += eventHandler;
      }
    }

    internal virtual Label MK42
    {
      [DebuggerNonUserCode] get
      {
        return this._MK42;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK42_Click);
        if (this._MK42 != null)
          this._MK42.Click -= eventHandler;
        this._MK42 = value;
        if (this._MK42 == null)
          return;
        this._MK42.Click += eventHandler;
      }
    }

    internal virtual Label MK41
    {
      [DebuggerNonUserCode] get
      {
        return this._MK41;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK41_Click);
        if (this._MK41 != null)
          this._MK41.Click -= eventHandler;
        this._MK41 = value;
        if (this._MK41 == null)
          return;
        this._MK41.Click += eventHandler;
      }
    }

    internal virtual Label MK55
    {
      [DebuggerNonUserCode] get
      {
        return this._MK55;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK55_Click);
        if (this._MK55 != null)
          this._MK55.Click -= eventHandler;
        this._MK55 = value;
        if (this._MK55 == null)
          return;
        this._MK55.Click += eventHandler;
      }
    }

    internal virtual Label MK54
    {
      [DebuggerNonUserCode] get
      {
        return this._MK54;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK54_Click);
        if (this._MK54 != null)
          this._MK54.Click -= eventHandler;
        this._MK54 = value;
        if (this._MK54 == null)
          return;
        this._MK54.Click += eventHandler;
      }
    }

    internal virtual Label MK53
    {
      [DebuggerNonUserCode] get
      {
        return this._MK53;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK53_Click);
        if (this._MK53 != null)
          this._MK53.Click -= eventHandler;
        this._MK53 = value;
        if (this._MK53 == null)
          return;
        this._MK53.Click += eventHandler;
      }
    }

    internal virtual Label MK52
    {
      [DebuggerNonUserCode] get
      {
        return this._MK52;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK52_Click);
        if (this._MK52 != null)
          this._MK52.Click -= eventHandler;
        this._MK52 = value;
        if (this._MK52 == null)
          return;
        this._MK52.Click += eventHandler;
      }
    }

    internal virtual Label MK51
    {
      [DebuggerNonUserCode] get
      {
        return this._MK51;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK51_Click);
        if (this._MK51 != null)
          this._MK51.Click -= eventHandler;
        this._MK51 = value;
        if (this._MK51 == null)
          return;
        this._MK51.Click += eventHandler;
      }
    }

    internal virtual Label MK50
    {
      [DebuggerNonUserCode] get
      {
        return this._MK50;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK50_Click);
        if (this._MK50 != null)
          this._MK50.Click -= eventHandler;
        this._MK50 = value;
        if (this._MK50 == null)
          return;
        this._MK50.Click += eventHandler;
      }
    }

    internal virtual Label MK49
    {
      [DebuggerNonUserCode] get
      {
        return this._MK49;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK49_Click);
        if (this._MK49 != null)
          this._MK49.Click -= eventHandler;
        this._MK49 = value;
        if (this._MK49 == null)
          return;
        this._MK49.Click += eventHandler;
      }
    }

    internal virtual Label MK63
    {
      [DebuggerNonUserCode] get
      {
        return this._MK63;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK63_Click);
        if (this._MK63 != null)
          this._MK63.Click -= eventHandler;
        this._MK63 = value;
        if (this._MK63 == null)
          return;
        this._MK63.Click += eventHandler;
      }
    }

    internal virtual Label MK62
    {
      [DebuggerNonUserCode] get
      {
        return this._MK62;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK62_Click);
        if (this._MK62 != null)
          this._MK62.Click -= eventHandler;
        this._MK62 = value;
        if (this._MK62 == null)
          return;
        this._MK62.Click += eventHandler;
      }
    }

    internal virtual Label MK61
    {
      [DebuggerNonUserCode] get
      {
        return this._MK61;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK61_Click);
        if (this._MK61 != null)
          this._MK61.Click -= eventHandler;
        this._MK61 = value;
        if (this._MK61 == null)
          return;
        this._MK61.Click += eventHandler;
      }
    }

    internal virtual Label MK60
    {
      [DebuggerNonUserCode] get
      {
        return this._MK60;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK60_Click);
        if (this._MK60 != null)
          this._MK60.Click -= eventHandler;
        this._MK60 = value;
        if (this._MK60 == null)
          return;
        this._MK60.Click += eventHandler;
      }
    }

    internal virtual Label MK59
    {
      [DebuggerNonUserCode] get
      {
        return this._MK59;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK59_Click);
        if (this._MK59 != null)
          this._MK59.Click -= eventHandler;
        this._MK59 = value;
        if (this._MK59 == null)
          return;
        this._MK59.Click += eventHandler;
      }
    }

    internal virtual Label MK58
    {
      [DebuggerNonUserCode] get
      {
        return this._MK58;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK58_Click);
        if (this._MK58 != null)
          this._MK58.Click -= eventHandler;
        this._MK58 = value;
        if (this._MK58 == null)
          return;
        this._MK58.Click += eventHandler;
      }
    }

    internal virtual Label MK57
    {
      [DebuggerNonUserCode] get
      {
        return this._MK57;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK57_Click);
        if (this._MK57 != null)
          this._MK57.Click -= eventHandler;
        this._MK57 = value;
        if (this._MK57 == null)
          return;
        this._MK57.Click += eventHandler;
      }
    }

    internal virtual Label MK64
    {
      [DebuggerNonUserCode] get
      {
        return this._MK64;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK64_Click);
        if (this._MK64 != null)
          this._MK64.Click -= eventHandler;
        this._MK64 = value;
        if (this._MK64 == null)
          return;
        this._MK64.Click += eventHandler;
      }
    }

    internal virtual Label MK56
    {
      [DebuggerNonUserCode] get
      {
        return this._MK56;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK56_Click);
        if (this._MK56 != null)
          this._MK56.Click -= eventHandler;
        this._MK56 = value;
        if (this._MK56 == null)
          return;
        this._MK56.Click += eventHandler;
      }
    }

    internal virtual Label MK48
    {
      [DebuggerNonUserCode] get
      {
        return this._MK48;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK48_Click);
        if (this._MK48 != null)
          this._MK48.Click -= eventHandler;
        this._MK48 = value;
        if (this._MK48 == null)
          return;
        this._MK48.Click += eventHandler;
      }
    }

    internal virtual Label MK40
    {
      [DebuggerNonUserCode] get
      {
        return this._MK40;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK40_Click);
        if (this._MK40 != null)
          this._MK40.Click -= eventHandler;
        this._MK40 = value;
        if (this._MK40 == null)
          return;
        this._MK40.Click += eventHandler;
      }
    }

    internal virtual Label MK32
    {
      [DebuggerNonUserCode] get
      {
        return this._MK32;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK32_Click);
        if (this._MK32 != null)
          this._MK32.Click -= eventHandler;
        this._MK32 = value;
        if (this._MK32 == null)
          return;
        this._MK32.Click += eventHandler;
      }
    }

    internal virtual Label MK24
    {
      [DebuggerNonUserCode] get
      {
        return this._MK24;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK24_Click);
        if (this._MK24 != null)
          this._MK24.Click -= eventHandler;
        this._MK24 = value;
        if (this._MK24 == null)
          return;
        this._MK24.Click += eventHandler;
      }
    }

    internal virtual Label MK16
    {
      [DebuggerNonUserCode] get
      {
        return this._MK16;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK16_Click);
        if (this._MK16 != null)
          this._MK16.Click -= eventHandler;
        this._MK16 = value;
        if (this._MK16 == null)
          return;
        this._MK16.Click += eventHandler;
      }
    }

    internal virtual Label MK8
    {
      [DebuggerNonUserCode] get
      {
        return this._MK8;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MK8_Click);
        if (this._MK8 != null)
          this._MK8.Click -= eventHandler;
        this._MK8 = value;
        if (this._MK8 == null)
          return;
        this._MK8.Click += eventHandler;
      }
    }

    internal virtual ListBox Integrantes
    {
      [DebuggerNonUserCode] get
      {
        return this._Integrantes;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Integrantes_SelectedIndexChanged);
        if (this._Integrantes != null)
          this._Integrantes.SelectedIndexChanged -= eventHandler;
        this._Integrantes = value;
        if (this._Integrantes == null)
          return;
        this._Integrantes.SelectedIndexChanged += eventHandler;
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
        EventHandler eventHandler = new EventHandler(this.method_8);
        KeyPressEventHandler pressEventHandler = new KeyPressEventHandler(this.method_7);
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

    internal virtual TextBox GuildName
    {
      [DebuggerNonUserCode] get
      {
        return this._GuildName;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._GuildName = value;
      }
    }

    internal virtual TextBox Tipo
    {
      [DebuggerNonUserCode] get
      {
        return this._Tipo;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Tipo = value;
      }
    }

    internal virtual TextBox Noticia
    {
      [DebuggerNonUserCode] get
      {
        return this._Noticia;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Noticia_LostFocus);
        if (this._Noticia != null)
          this._Noticia.LostFocus -= eventHandler;
        this._Noticia = value;
        if (this._Noticia == null)
          return;
        this._Noticia.LostFocus += eventHandler;
      }
    }

    internal virtual RadioButton GL1
    {
      [DebuggerNonUserCode] get
      {
        return this._GL1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.GL1_CheckedChanged);
        if (this._GL1 != null)
          this._GL1.CheckedChanged -= eventHandler;
        this._GL1 = value;
        if (this._GL1 == null)
          return;
        this._GL1.CheckedChanged += eventHandler;
      }
    }

    internal virtual RadioButton GL4
    {
      [DebuggerNonUserCode] get
      {
        return this._GL4;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.GL4_CheckedChanged);
        if (this._GL4 != null)
          this._GL4.CheckedChanged -= eventHandler;
        this._GL4 = value;
        if (this._GL4 == null)
          return;
        this._GL4.CheckedChanged += eventHandler;
      }
    }

    internal virtual RadioButton GL3
    {
      [DebuggerNonUserCode] get
      {
        return this._GL3;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.GL3_CheckedChanged);
        if (this._GL3 != null)
          this._GL3.CheckedChanged -= eventHandler;
        this._GL3 = value;
        if (this._GL3 == null)
          return;
        this._GL3.CheckedChanged += eventHandler;
      }
    }

    internal virtual RadioButton GL2
    {
      [DebuggerNonUserCode] get
      {
        return this._GL2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.GL2_CheckedChanged);
        if (this._GL2 != null)
          this._GL2.CheckedChanged -= eventHandler;
        this._GL2 = value;
        if (this._GL2 == null)
          return;
        this._GL2.CheckedChanged += eventHandler;
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

    internal virtual Label CL1
    {
      [DebuggerNonUserCode] get
      {
        return this._CL1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL1_Click);
        if (this._CL1 != null)
          this._CL1.Click -= eventHandler;
        this._CL1 = value;
        if (this._CL1 == null)
          return;
        this._CL1.Click += eventHandler;
      }
    }

    internal virtual Label CL64
    {
      [DebuggerNonUserCode] get
      {
        return this._CL64;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL64_Click);
        if (this._CL64 != null)
          this._CL64.Click -= eventHandler;
        this._CL64 = value;
        if (this._CL64 == null)
          return;
        this._CL64.Click += eventHandler;
      }
    }

    internal virtual Label CL2
    {
      [DebuggerNonUserCode] get
      {
        return this._CL2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL2_Click);
        if (this._CL2 != null)
          this._CL2.Click -= eventHandler;
        this._CL2 = value;
        if (this._CL2 == null)
          return;
        this._CL2.Click += eventHandler;
      }
    }

    internal virtual Label CL56
    {
      [DebuggerNonUserCode] get
      {
        return this._CL56;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL56_Click);
        if (this._CL56 != null)
          this._CL56.Click -= eventHandler;
        this._CL56 = value;
        if (this._CL56 == null)
          return;
        this._CL56.Click += eventHandler;
      }
    }

    internal virtual Label CL3
    {
      [DebuggerNonUserCode] get
      {
        return this._CL3;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL3_Click);
        if (this._CL3 != null)
          this._CL3.Click -= eventHandler;
        this._CL3 = value;
        if (this._CL3 == null)
          return;
        this._CL3.Click += eventHandler;
      }
    }

    internal virtual Label CL48
    {
      [DebuggerNonUserCode] get
      {
        return this._CL48;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL48_Click);
        if (this._CL48 != null)
          this._CL48.Click -= eventHandler;
        this._CL48 = value;
        if (this._CL48 == null)
          return;
        this._CL48.Click += eventHandler;
      }
    }

    internal virtual Label CL4
    {
      [DebuggerNonUserCode] get
      {
        return this._CL4;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL4_Click);
        if (this._CL4 != null)
          this._CL4.Click -= eventHandler;
        this._CL4 = value;
        if (this._CL4 == null)
          return;
        this._CL4.Click += eventHandler;
      }
    }

    internal virtual Label CL40
    {
      [DebuggerNonUserCode] get
      {
        return this._CL40;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL40_Click);
        if (this._CL40 != null)
          this._CL40.Click -= eventHandler;
        this._CL40 = value;
        if (this._CL40 == null)
          return;
        this._CL40.Click += eventHandler;
      }
    }

    internal virtual Label CL5
    {
      [DebuggerNonUserCode] get
      {
        return this._CL5;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL5_Click);
        if (this._CL5 != null)
          this._CL5.Click -= eventHandler;
        this._CL5 = value;
        if (this._CL5 == null)
          return;
        this._CL5.Click += eventHandler;
      }
    }

    internal virtual Label CL32
    {
      [DebuggerNonUserCode] get
      {
        return this._CL32;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL32_Click);
        if (this._CL32 != null)
          this._CL32.Click -= eventHandler;
        this._CL32 = value;
        if (this._CL32 == null)
          return;
        this._CL32.Click += eventHandler;
      }
    }

    internal virtual Label CL6
    {
      [DebuggerNonUserCode] get
      {
        return this._CL6;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL6_Click);
        if (this._CL6 != null)
          this._CL6.Click -= eventHandler;
        this._CL6 = value;
        if (this._CL6 == null)
          return;
        this._CL6.Click += eventHandler;
      }
    }

    internal virtual Label CL24
    {
      [DebuggerNonUserCode] get
      {
        return this._CL24;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL24_Click);
        if (this._CL24 != null)
          this._CL24.Click -= eventHandler;
        this._CL24 = value;
        if (this._CL24 == null)
          return;
        this._CL24.Click += eventHandler;
      }
    }

    internal virtual Label CL7
    {
      [DebuggerNonUserCode] get
      {
        return this._CL7;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL7_Click);
        if (this._CL7 != null)
          this._CL7.Click -= eventHandler;
        this._CL7 = value;
        if (this._CL7 == null)
          return;
        this._CL7.Click += eventHandler;
      }
    }

    internal virtual Label CL16
    {
      [DebuggerNonUserCode] get
      {
        return this._CL16;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL16_Click);
        if (this._CL16 != null)
          this._CL16.Click -= eventHandler;
        this._CL16 = value;
        if (this._CL16 == null)
          return;
        this._CL16.Click += eventHandler;
      }
    }

    internal virtual Label CL9
    {
      [DebuggerNonUserCode] get
      {
        return this._CL9;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL9_Click);
        if (this._CL9 != null)
          this._CL9.Click -= eventHandler;
        this._CL9 = value;
        if (this._CL9 == null)
          return;
        this._CL9.Click += eventHandler;
      }
    }

    internal virtual Label CL8
    {
      [DebuggerNonUserCode] get
      {
        return this._CL8;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL8_Click);
        if (this._CL8 != null)
          this._CL8.Click -= eventHandler;
        this._CL8 = value;
        if (this._CL8 == null)
          return;
        this._CL8.Click += eventHandler;
      }
    }

    internal virtual Label CL10
    {
      [DebuggerNonUserCode] get
      {
        return this._CL10;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL10_Click);
        if (this._CL10 != null)
          this._CL10.Click -= eventHandler;
        this._CL10 = value;
        if (this._CL10 == null)
          return;
        this._CL10.Click += eventHandler;
      }
    }

    internal virtual Label CL63
    {
      [DebuggerNonUserCode] get
      {
        return this._CL63;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL63_Click);
        if (this._CL63 != null)
          this._CL63.Click -= eventHandler;
        this._CL63 = value;
        if (this._CL63 == null)
          return;
        this._CL63.Click += eventHandler;
      }
    }

    internal virtual Label CL11
    {
      [DebuggerNonUserCode] get
      {
        return this._CL11;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL11_Click);
        if (this._CL11 != null)
          this._CL11.Click -= eventHandler;
        this._CL11 = value;
        if (this._CL11 == null)
          return;
        this._CL11.Click += eventHandler;
      }
    }

    internal virtual Label CL37
    {
      [DebuggerNonUserCode] get
      {
        return this._CL37;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL37_Click);
        if (this._CL37 != null)
          this._CL37.Click -= eventHandler;
        this._CL37 = value;
        if (this._CL37 == null)
          return;
        this._CL37.Click += eventHandler;
      }
    }

    internal virtual Label CL62
    {
      [DebuggerNonUserCode] get
      {
        return this._CL62;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL62_Click);
        if (this._CL62 != null)
          this._CL62.Click -= eventHandler;
        this._CL62 = value;
        if (this._CL62 == null)
          return;
        this._CL62.Click += eventHandler;
      }
    }

    internal virtual Label CL36
    {
      [DebuggerNonUserCode] get
      {
        return this._CL36;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL36_Click);
        if (this._CL36 != null)
          this._CL36.Click -= eventHandler;
        this._CL36 = value;
        if (this._CL36 == null)
          return;
        this._CL36.Click += eventHandler;
      }
    }

    internal virtual Label CL12
    {
      [DebuggerNonUserCode] get
      {
        return this._CL12;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL12_Click);
        if (this._CL12 != null)
          this._CL12.Click -= eventHandler;
        this._CL12 = value;
        if (this._CL12 == null)
          return;
        this._CL12.Click += eventHandler;
      }
    }

    internal virtual Label CL38
    {
      [DebuggerNonUserCode] get
      {
        return this._CL38;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL38_Click);
        if (this._CL38 != null)
          this._CL38.Click -= eventHandler;
        this._CL38 = value;
        if (this._CL38 == null)
          return;
        this._CL38.Click += eventHandler;
      }
    }

    internal virtual Label CL61
    {
      [DebuggerNonUserCode] get
      {
        return this._CL61;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL61_Click);
        if (this._CL61 != null)
          this._CL61.Click -= eventHandler;
        this._CL61 = value;
        if (this._CL61 == null)
          return;
        this._CL61.Click += eventHandler;
      }
    }

    internal virtual Label CL35
    {
      [DebuggerNonUserCode] get
      {
        return this._CL35;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL35_Click);
        if (this._CL35 != null)
          this._CL35.Click -= eventHandler;
        this._CL35 = value;
        if (this._CL35 == null)
          return;
        this._CL35.Click += eventHandler;
      }
    }

    internal virtual Label CL13
    {
      [DebuggerNonUserCode] get
      {
        return this._CL13;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL13_Click);
        if (this._CL13 != null)
          this._CL13.Click -= eventHandler;
        this._CL13 = value;
        if (this._CL13 == null)
          return;
        this._CL13.Click += eventHandler;
      }
    }

    internal virtual Label CL39
    {
      [DebuggerNonUserCode] get
      {
        return this._CL39;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL39_Click);
        if (this._CL39 != null)
          this._CL39.Click -= eventHandler;
        this._CL39 = value;
        if (this._CL39 == null)
          return;
        this._CL39.Click += eventHandler;
      }
    }

    internal virtual Label CL60
    {
      [DebuggerNonUserCode] get
      {
        return this._CL60;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL60_Click);
        if (this._CL60 != null)
          this._CL60.Click -= eventHandler;
        this._CL60 = value;
        if (this._CL60 == null)
          return;
        this._CL60.Click += eventHandler;
      }
    }

    internal virtual Label CL34
    {
      [DebuggerNonUserCode] get
      {
        return this._CL34;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL34_Click);
        if (this._CL34 != null)
          this._CL34.Click -= eventHandler;
        this._CL34 = value;
        if (this._CL34 == null)
          return;
        this._CL34.Click += eventHandler;
      }
    }

    internal virtual Label CL14
    {
      [DebuggerNonUserCode] get
      {
        return this._CL14;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL14_Click);
        if (this._CL14 != null)
          this._CL14.Click -= eventHandler;
        this._CL14 = value;
        if (this._CL14 == null)
          return;
        this._CL14.Click += eventHandler;
      }
    }

    internal virtual Label CL41
    {
      [DebuggerNonUserCode] get
      {
        return this._CL41;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL41_Click);
        if (this._CL41 != null)
          this._CL41.Click -= eventHandler;
        this._CL41 = value;
        if (this._CL41 == null)
          return;
        this._CL41.Click += eventHandler;
      }
    }

    internal virtual Label CL59
    {
      [DebuggerNonUserCode] get
      {
        return this._CL59;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL59_Click);
        if (this._CL59 != null)
          this._CL59.Click -= eventHandler;
        this._CL59 = value;
        if (this._CL59 == null)
          return;
        this._CL59.Click += eventHandler;
      }
    }

    internal virtual Label CL33
    {
      [DebuggerNonUserCode] get
      {
        return this._CL33;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL33_Click);
        if (this._CL33 != null)
          this._CL33.Click -= eventHandler;
        this._CL33 = value;
        if (this._CL33 == null)
          return;
        this._CL33.Click += eventHandler;
      }
    }

    internal virtual Label CL15
    {
      [DebuggerNonUserCode] get
      {
        return this._CL15;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL15_Click);
        if (this._CL15 != null)
          this._CL15.Click -= eventHandler;
        this._CL15 = value;
        if (this._CL15 == null)
          return;
        this._CL15.Click += eventHandler;
      }
    }

    internal virtual Label CL42
    {
      [DebuggerNonUserCode] get
      {
        return this._CL42;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL42_Click);
        if (this._CL42 != null)
          this._CL42.Click -= eventHandler;
        this._CL42 = value;
        if (this._CL42 == null)
          return;
        this._CL42.Click += eventHandler;
      }
    }

    internal virtual Label CL58
    {
      [DebuggerNonUserCode] get
      {
        return this._CL58;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL58_Click);
        if (this._CL58 != null)
          this._CL58.Click -= eventHandler;
        this._CL58 = value;
        if (this._CL58 == null)
          return;
        this._CL58.Click += eventHandler;
      }
    }

    internal virtual Label CL31
    {
      [DebuggerNonUserCode] get
      {
        return this._CL31;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL31_Click);
        if (this._CL31 != null)
          this._CL31.Click -= eventHandler;
        this._CL31 = value;
        if (this._CL31 == null)
          return;
        this._CL31.Click += eventHandler;
      }
    }

    internal virtual Label CL17
    {
      [DebuggerNonUserCode] get
      {
        return this._CL17;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL17_Click);
        if (this._CL17 != null)
          this._CL17.Click -= eventHandler;
        this._CL17 = value;
        if (this._CL17 == null)
          return;
        this._CL17.Click += eventHandler;
      }
    }

    internal virtual Label CL43
    {
      [DebuggerNonUserCode] get
      {
        return this._CL43;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL43_Click);
        if (this._CL43 != null)
          this._CL43.Click -= eventHandler;
        this._CL43 = value;
        if (this._CL43 == null)
          return;
        this._CL43.Click += eventHandler;
      }
    }

    internal virtual Label CL57
    {
      [DebuggerNonUserCode] get
      {
        return this._CL57;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL57_Click);
        if (this._CL57 != null)
          this._CL57.Click -= eventHandler;
        this._CL57 = value;
        if (this._CL57 == null)
          return;
        this._CL57.Click += eventHandler;
      }
    }

    internal virtual Label CL30
    {
      [DebuggerNonUserCode] get
      {
        return this._CL30;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL30_Click);
        if (this._CL30 != null)
          this._CL30.Click -= eventHandler;
        this._CL30 = value;
        if (this._CL30 == null)
          return;
        this._CL30.Click += eventHandler;
      }
    }

    internal virtual Label CL18
    {
      [DebuggerNonUserCode] get
      {
        return this._CL18;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL18_Click);
        if (this._CL18 != null)
          this._CL18.Click -= eventHandler;
        this._CL18 = value;
        if (this._CL18 == null)
          return;
        this._CL18.Click += eventHandler;
      }
    }

    internal virtual Label CL44
    {
      [DebuggerNonUserCode] get
      {
        return this._CL44;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL44_Click);
        if (this._CL44 != null)
          this._CL44.Click -= eventHandler;
        this._CL44 = value;
        if (this._CL44 == null)
          return;
        this._CL44.Click += eventHandler;
      }
    }

    internal virtual Label CL55
    {
      [DebuggerNonUserCode] get
      {
        return this._CL55;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL55_Click);
        if (this._CL55 != null)
          this._CL55.Click -= eventHandler;
        this._CL55 = value;
        if (this._CL55 == null)
          return;
        this._CL55.Click += eventHandler;
      }
    }

    internal virtual Label CL29
    {
      [DebuggerNonUserCode] get
      {
        return this._CL29;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL29_Click);
        if (this._CL29 != null)
          this._CL29.Click -= eventHandler;
        this._CL29 = value;
        if (this._CL29 == null)
          return;
        this._CL29.Click += eventHandler;
      }
    }

    internal virtual Label CL19
    {
      [DebuggerNonUserCode] get
      {
        return this._CL19;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL19_Click);
        if (this._CL19 != null)
          this._CL19.Click -= eventHandler;
        this._CL19 = value;
        if (this._CL19 == null)
          return;
        this._CL19.Click += eventHandler;
      }
    }

    internal virtual Label CL45
    {
      [DebuggerNonUserCode] get
      {
        return this._CL45;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL45_Click);
        if (this._CL45 != null)
          this._CL45.Click -= eventHandler;
        this._CL45 = value;
        if (this._CL45 == null)
          return;
        this._CL45.Click += eventHandler;
      }
    }

    internal virtual Label CL54
    {
      [DebuggerNonUserCode] get
      {
        return this._CL54;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL54_Click);
        if (this._CL54 != null)
          this._CL54.Click -= eventHandler;
        this._CL54 = value;
        if (this._CL54 == null)
          return;
        this._CL54.Click += eventHandler;
      }
    }

    internal virtual Label CL28
    {
      [DebuggerNonUserCode] get
      {
        return this._CL28;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL28_Click);
        if (this._CL28 != null)
          this._CL28.Click -= eventHandler;
        this._CL28 = value;
        if (this._CL28 == null)
          return;
        this._CL28.Click += eventHandler;
      }
    }

    internal virtual Label CL20
    {
      [DebuggerNonUserCode] get
      {
        return this._CL20;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL20_Click);
        if (this._CL20 != null)
          this._CL20.Click -= eventHandler;
        this._CL20 = value;
        if (this._CL20 == null)
          return;
        this._CL20.Click += eventHandler;
      }
    }

    internal virtual Label CL46
    {
      [DebuggerNonUserCode] get
      {
        return this._CL46;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL46_Click);
        if (this._CL46 != null)
          this._CL46.Click -= eventHandler;
        this._CL46 = value;
        if (this._CL46 == null)
          return;
        this._CL46.Click += eventHandler;
      }
    }

    internal virtual Label CL53
    {
      [DebuggerNonUserCode] get
      {
        return this._CL53;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL53_Click);
        if (this._CL53 != null)
          this._CL53.Click -= eventHandler;
        this._CL53 = value;
        if (this._CL53 == null)
          return;
        this._CL53.Click += eventHandler;
      }
    }

    internal virtual Label CL27
    {
      [DebuggerNonUserCode] get
      {
        return this._CL27;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL27_Click);
        if (this._CL27 != null)
          this._CL27.Click -= eventHandler;
        this._CL27 = value;
        if (this._CL27 == null)
          return;
        this._CL27.Click += eventHandler;
      }
    }

    internal virtual Label CL21
    {
      [DebuggerNonUserCode] get
      {
        return this._CL21;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL21_Click);
        if (this._CL21 != null)
          this._CL21.Click -= eventHandler;
        this._CL21 = value;
        if (this._CL21 == null)
          return;
        this._CL21.Click += eventHandler;
      }
    }

    internal virtual Label CL47
    {
      [DebuggerNonUserCode] get
      {
        return this._CL47;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL47_Click);
        if (this._CL47 != null)
          this._CL47.Click -= eventHandler;
        this._CL47 = value;
        if (this._CL47 == null)
          return;
        this._CL47.Click += eventHandler;
      }
    }

    internal virtual Label CL52
    {
      [DebuggerNonUserCode] get
      {
        return this._CL52;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL52_Click);
        if (this._CL52 != null)
          this._CL52.Click -= eventHandler;
        this._CL52 = value;
        if (this._CL52 == null)
          return;
        this._CL52.Click += eventHandler;
      }
    }

    internal virtual Label CL26
    {
      [DebuggerNonUserCode] get
      {
        return this._CL26;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL26_Click);
        if (this._CL26 != null)
          this._CL26.Click -= eventHandler;
        this._CL26 = value;
        if (this._CL26 == null)
          return;
        this._CL26.Click += eventHandler;
      }
    }

    internal virtual Label CL22
    {
      [DebuggerNonUserCode] get
      {
        return this._CL22;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL22_Click);
        if (this._CL22 != null)
          this._CL22.Click -= eventHandler;
        this._CL22 = value;
        if (this._CL22 == null)
          return;
        this._CL22.Click += eventHandler;
      }
    }

    internal virtual Label CL49
    {
      [DebuggerNonUserCode] get
      {
        return this._CL49;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL49_Click);
        if (this._CL49 != null)
          this._CL49.Click -= eventHandler;
        this._CL49 = value;
        if (this._CL49 == null)
          return;
        this._CL49.Click += eventHandler;
      }
    }

    internal virtual Label CL51
    {
      [DebuggerNonUserCode] get
      {
        return this._CL51;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL51_Click);
        if (this._CL51 != null)
          this._CL51.Click -= eventHandler;
        this._CL51 = value;
        if (this._CL51 == null)
          return;
        this._CL51.Click += eventHandler;
      }
    }

    internal virtual Label CL25
    {
      [DebuggerNonUserCode] get
      {
        return this._CL25;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL25_Click);
        if (this._CL25 != null)
          this._CL25.Click -= eventHandler;
        this._CL25 = value;
        if (this._CL25 == null)
          return;
        this._CL25.Click += eventHandler;
      }
    }

    internal virtual Label CL23
    {
      [DebuggerNonUserCode] get
      {
        return this._CL23;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL23_Click);
        if (this._CL23 != null)
          this._CL23.Click -= eventHandler;
        this._CL23 = value;
        if (this._CL23 == null)
          return;
        this._CL23.Click += eventHandler;
      }
    }

    internal virtual Label CL50
    {
      [DebuggerNonUserCode] get
      {
        return this._CL50;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.CL50_Click);
        if (this._CL50 != null)
          this._CL50.Click -= eventHandler;
        this._CL50 = value;
        if (this._CL50 == null)
          return;
        this._CL50.Click += eventHandler;
      }
    }

    internal virtual ComboBox MasterGuild
    {
      [DebuggerNonUserCode] get
      {
        return this._MasterGuild;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MasterGuild_SelectedIndexChanged);
        if (this._MasterGuild != null)
          this._MasterGuild.SelectedIndexChanged -= eventHandler;
        this._MasterGuild = value;
        if (this._MasterGuild == null)
          return;
        this._MasterGuild.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual Label Label67
    {
      [DebuggerNonUserCode] get
      {
        return this._Label67;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label67 = value;
      }
    }

    internal virtual Label Label68
    {
      [DebuggerNonUserCode] get
      {
        return this._Label68;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label68 = value;
      }
    }

    internal virtual ListBox GuildsEnemy
    {
      [DebuggerNonUserCode] get
      {
        return this._GuildsEnemy;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.GuildsEnemy_SelectedIndexChanged);
        if (this._GuildsEnemy != null)
          this._GuildsEnemy.SelectedIndexChanged -= eventHandler;
        this._GuildsEnemy = value;
        if (this._GuildsEnemy == null)
          return;
        this._GuildsEnemy.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual ListBox GuildsFriend
    {
      [DebuggerNonUserCode] get
      {
        return this._GuildsFriend;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.GuildsFriend_SelectedIndexChanged);
        if (this._GuildsFriend != null)
          this._GuildsFriend.SelectedIndexChanged -= eventHandler;
        this._GuildsFriend = value;
        if (this._GuildsFriend == null)
          return;
        this._GuildsFriend.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual Label Label69
    {
      [DebuggerNonUserCode] get
      {
        return this._Label69;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label69 = value;
      }
    }

    internal virtual Label Label70
    {
      [DebuggerNonUserCode] get
      {
        return this._Label70;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label70 = value;
      }
    }

    internal virtual Label C1
    {
      [DebuggerNonUserCode] get
      {
        return this._C1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.C1_Click);
        if (this._C1 != null)
          this._C1.Click -= eventHandler;
        this._C1 = value;
        if (this._C1 == null)
          return;
        this._C1.Click += eventHandler;
      }
    }

    internal virtual Label C2
    {
      [DebuggerNonUserCode] get
      {
        return this._C2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.C2_Click);
        if (this._C2 != null)
          this._C2.Click -= eventHandler;
        this._C2 = value;
        if (this._C2 == null)
          return;
        this._C2.Click += eventHandler;
      }
    }

    internal virtual Label C3
    {
      [DebuggerNonUserCode] get
      {
        return this._C3;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.C3_Click);
        if (this._C3 != null)
          this._C3.Click -= eventHandler;
        this._C3 = value;
        if (this._C3 == null)
          return;
        this._C3.Click += eventHandler;
      }
    }

    internal virtual Label C4
    {
      [DebuggerNonUserCode] get
      {
        return this._C4;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.C4_Click);
        if (this._C4 != null)
          this._C4.Click -= eventHandler;
        this._C4 = value;
        if (this._C4 == null)
          return;
        this._C4.Click += eventHandler;
      }
    }

    internal virtual Label C5
    {
      [DebuggerNonUserCode] get
      {
        return this._C5;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.C5_Click);
        if (this._C5 != null)
          this._C5.Click -= eventHandler;
        this._C5 = value;
        if (this._C5 == null)
          return;
        this._C5.Click += eventHandler;
      }
    }

    internal virtual Label C6
    {
      [DebuggerNonUserCode] get
      {
        return this._C6;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.C6_Click);
        if (this._C6 != null)
          this._C6.Click -= eventHandler;
        this._C6 = value;
        if (this._C6 == null)
          return;
        this._C6.Click += eventHandler;
      }
    }

    internal virtual Label C7
    {
      [DebuggerNonUserCode] get
      {
        return this._C7;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.C7_Click);
        if (this._C7 != null)
          this._C7.Click -= eventHandler;
        this._C7 = value;
        if (this._C7 == null)
          return;
        this._C7.Click += eventHandler;
      }
    }

    internal virtual Label C16
    {
      [DebuggerNonUserCode] get
      {
        return this._C16;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.C16_Click);
        if (this._C16 != null)
          this._C16.Click -= eventHandler;
        this._C16 = value;
        if (this._C16 == null)
          return;
        this._C16.Click += eventHandler;
      }
    }

    internal virtual Label C9
    {
      [DebuggerNonUserCode] get
      {
        return this._C9;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.C9_Click);
        if (this._C9 != null)
          this._C9.Click -= eventHandler;
        this._C9 = value;
        if (this._C9 == null)
          return;
        this._C9.Click += eventHandler;
      }
    }

    internal virtual Label C8
    {
      [DebuggerNonUserCode] get
      {
        return this._C8;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.C8_Click);
        if (this._C8 != null)
          this._C8.Click -= eventHandler;
        this._C8 = value;
        if (this._C8 == null)
          return;
        this._C8.Click += eventHandler;
      }
    }

    internal virtual Label C10
    {
      [DebuggerNonUserCode] get
      {
        return this._C10;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.C10_Click);
        if (this._C10 != null)
          this._C10.Click -= eventHandler;
        this._C10 = value;
        if (this._C10 == null)
          return;
        this._C10.Click += eventHandler;
      }
    }

    internal virtual Label C11
    {
      [DebuggerNonUserCode] get
      {
        return this._C11;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.C11_Click);
        if (this._C11 != null)
          this._C11.Click -= eventHandler;
        this._C11 = value;
        if (this._C11 == null)
          return;
        this._C11.Click += eventHandler;
      }
    }

    internal virtual Label C12
    {
      [DebuggerNonUserCode] get
      {
        return this._C12;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.C12_Click);
        if (this._C12 != null)
          this._C12.Click -= eventHandler;
        this._C12 = value;
        if (this._C12 == null)
          return;
        this._C12.Click += eventHandler;
      }
    }

    internal virtual Label C13
    {
      [DebuggerNonUserCode] get
      {
        return this._C13;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.C13_Click);
        if (this._C13 != null)
          this._C13.Click -= eventHandler;
        this._C13 = value;
        if (this._C13 == null)
          return;
        this._C13.Click += eventHandler;
      }
    }

    internal virtual Label C14
    {
      [DebuggerNonUserCode] get
      {
        return this._C14;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.C14_Click);
        if (this._C14 != null)
          this._C14.Click -= eventHandler;
        this._C14 = value;
        if (this._C14 == null)
          return;
        this._C14.Click += eventHandler;
      }
    }

    internal virtual Label C15
    {
      [DebuggerNonUserCode] get
      {
        return this._C15;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.C15_Click);
        if (this._C15 != null)
          this._C15.Click -= eventHandler;
        this._C15 = value;
        if (this._C15 == null)
          return;
        this._C15.Click += eventHandler;
      }
    }

    internal virtual Label CurrentColor
    {
      [DebuggerNonUserCode] get
      {
        return this._CurrentColor;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._CurrentColor = value;
      }
    }

    internal virtual Label Label88
    {
      [DebuggerNonUserCode] get
      {
        return this._Label88;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label88 = value;
      }
    }

    internal virtual Label NameGuild
    {
      [DebuggerNonUserCode] get
      {
        return this._NameGuild;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._NameGuild = value;
      }
    }

    internal virtual Label GuildMaster
    {
      [DebuggerNonUserCode] get
      {
        return this._GuildMaster;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._GuildMaster = value;
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
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_19);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_18);
        EventHandler eventHandler = new EventHandler(this.method_3);
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
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_13);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_12);
        EventHandler eventHandler = new EventHandler(this.method_2);
        if (this._Reload != null)
        {
          this._Reload.MouseDown -= mouseEventHandler1;
          this._Reload.MouseUp -= mouseEventHandler2;
          this._Reload.Click -= eventHandler;
        }
        this._Reload = value;
        if (this._Reload == null)
          return;
        this._Reload.MouseDown += mouseEventHandler1;
        this._Reload.MouseUp += mouseEventHandler2;
        this._Reload.Click += eventHandler;
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
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_11);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_10);
        EventHandler eventHandler = new EventHandler(this.method_9);
        if (this._Buscar != null)
        {
          this._Buscar.MouseDown -= mouseEventHandler1;
          this._Buscar.MouseUp -= mouseEventHandler2;
          this._Buscar.Click -= eventHandler;
        }
        this._Buscar = value;
        if (this._Buscar == null)
          return;
        this._Buscar.MouseDown += mouseEventHandler1;
        this._Buscar.MouseUp += mouseEventHandler2;
        this._Buscar.Click += eventHandler;
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
        EventHandler eventHandler = new EventHandler(this.method_6);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_15);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_14);
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

    internal virtual Button Cerrar
    {
      [DebuggerNonUserCode] get
      {
        return this._Cerrar;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_25);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_24);
        EventHandler eventHandler = new EventHandler(this.method_1);
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

    internal virtual Button Minimizar
    {
      [DebuggerNonUserCode] get
      {
        return this._Minimizar;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_23);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_22);
        EventHandler eventHandler = new EventHandler(this.method_0);
        if (this._Minimizar != null)
        {
          this._Minimizar.MouseDown -= mouseEventHandler1;
          this._Minimizar.MouseUp -= mouseEventHandler2;
          this._Minimizar.Click -= eventHandler;
        }
        this._Minimizar = value;
        if (this._Minimizar == null)
          return;
        this._Minimizar.MouseDown += mouseEventHandler1;
        this._Minimizar.MouseUp += mouseEventHandler2;
        this._Minimizar.Click += eventHandler;
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

    public static GuildMaker DefInstance
    {
      get
      {
        if (GuildMaker.guildMaker_0 != null && !GuildMaker.guildMaker_0.IsDisposed)
          GuildMaker.guildMaker_0.BringToFront();
        else
          GuildMaker.guildMaker_0 = new GuildMaker();
        return GuildMaker.guildMaker_0;
      }
      set
      {
        GuildMaker.guildMaker_0 = value;
      }
    }

    [DebuggerNonUserCode]
    public GuildMaker()
    {
      this.Load += new EventHandler(this.GuildMaker_Load);
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
      ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof (GuildMaker));
      this.Personajes = new ComboBox();
      this.Guilds = new ComboBox();
      this.PersonajeSearch = new TextBox();
      this.GuildSearch = new TextBox();
      this.GuildsL = new Label();
      this.Chart = new Label();
      this.CreateGuild = new Button();
      this.BorrarGuild = new Button();
      this.MK1 = new Label();
      this.MK2 = new Label();
      this.MK3 = new Label();
      this.MK4 = new Label();
      this.MK5 = new Label();
      this.MK6 = new Label();
      this.MK7 = new Label();
      this.MK15 = new Label();
      this.MK14 = new Label();
      this.MK13 = new Label();
      this.MK12 = new Label();
      this.MK11 = new Label();
      this.MK10 = new Label();
      this.MK9 = new Label();
      this.MK23 = new Label();
      this.MK22 = new Label();
      this.MK21 = new Label();
      this.MK20 = new Label();
      this.MK19 = new Label();
      this.MK18 = new Label();
      this.MK17 = new Label();
      this.MK31 = new Label();
      this.MK30 = new Label();
      this.MK29 = new Label();
      this.MK28 = new Label();
      this.MK27 = new Label();
      this.MK26 = new Label();
      this.MK25 = new Label();
      this.MK39 = new Label();
      this.MK38 = new Label();
      this.MK37 = new Label();
      this.MK36 = new Label();
      this.MK35 = new Label();
      this.MK34 = new Label();
      this.MK33 = new Label();
      this.MK47 = new Label();
      this.MK46 = new Label();
      this.MK45 = new Label();
      this.MK44 = new Label();
      this.MK43 = new Label();
      this.MK42 = new Label();
      this.MK41 = new Label();
      this.MK55 = new Label();
      this.MK54 = new Label();
      this.MK53 = new Label();
      this.MK52 = new Label();
      this.MK51 = new Label();
      this.MK50 = new Label();
      this.MK49 = new Label();
      this.MK63 = new Label();
      this.MK62 = new Label();
      this.MK61 = new Label();
      this.MK60 = new Label();
      this.MK59 = new Label();
      this.MK58 = new Label();
      this.MK57 = new Label();
      this.MK64 = new Label();
      this.MK56 = new Label();
      this.MK48 = new Label();
      this.MK40 = new Label();
      this.MK32 = new Label();
      this.MK24 = new Label();
      this.MK16 = new Label();
      this.MK8 = new Label();
      this.Integrantes = new ListBox();
      this.Puntos = new TextBox();
      this.GuildName = new TextBox();
      this.Tipo = new TextBox();
      this.Noticia = new TextBox();
      this.GL1 = new RadioButton();
      this.GL4 = new RadioButton();
      this.GL3 = new RadioButton();
      this.GL2 = new RadioButton();
      this.Label1 = new Label();
      this.Label2 = new Label();
      this.CL1 = new Label();
      this.CL64 = new Label();
      this.CL2 = new Label();
      this.CL56 = new Label();
      this.CL3 = new Label();
      this.CL48 = new Label();
      this.CL4 = new Label();
      this.CL40 = new Label();
      this.CL5 = new Label();
      this.CL32 = new Label();
      this.CL6 = new Label();
      this.CL24 = new Label();
      this.CL7 = new Label();
      this.CL16 = new Label();
      this.CL9 = new Label();
      this.CL8 = new Label();
      this.CL10 = new Label();
      this.CL63 = new Label();
      this.CL11 = new Label();
      this.CL37 = new Label();
      this.CL62 = new Label();
      this.CL36 = new Label();
      this.CL12 = new Label();
      this.CL38 = new Label();
      this.CL61 = new Label();
      this.CL35 = new Label();
      this.CL13 = new Label();
      this.CL39 = new Label();
      this.CL60 = new Label();
      this.CL34 = new Label();
      this.CL14 = new Label();
      this.CL41 = new Label();
      this.CL59 = new Label();
      this.CL33 = new Label();
      this.CL15 = new Label();
      this.CL42 = new Label();
      this.CL58 = new Label();
      this.CL31 = new Label();
      this.CL17 = new Label();
      this.CL43 = new Label();
      this.CL57 = new Label();
      this.CL30 = new Label();
      this.CL18 = new Label();
      this.CL44 = new Label();
      this.CL55 = new Label();
      this.CL29 = new Label();
      this.CL19 = new Label();
      this.CL45 = new Label();
      this.CL54 = new Label();
      this.CL28 = new Label();
      this.CL20 = new Label();
      this.CL46 = new Label();
      this.CL53 = new Label();
      this.CL27 = new Label();
      this.CL21 = new Label();
      this.CL47 = new Label();
      this.CL52 = new Label();
      this.CL26 = new Label();
      this.CL22 = new Label();
      this.CL49 = new Label();
      this.CL51 = new Label();
      this.CL25 = new Label();
      this.CL23 = new Label();
      this.CL50 = new Label();
      this.MasterGuild = new ComboBox();
      this.Label67 = new Label();
      this.Label68 = new Label();
      this.GuildsEnemy = new ListBox();
      this.GuildsFriend = new ListBox();
      this.Label69 = new Label();
      this.Label70 = new Label();
      this.C1 = new Label();
      this.C2 = new Label();
      this.C3 = new Label();
      this.C4 = new Label();
      this.C5 = new Label();
      this.C6 = new Label();
      this.C7 = new Label();
      this.C16 = new Label();
      this.C9 = new Label();
      this.C8 = new Label();
      this.C10 = new Label();
      this.C11 = new Label();
      this.C12 = new Label();
      this.C13 = new Label();
      this.C14 = new Label();
      this.C15 = new Label();
      this.CurrentColor = new Label();
      this.Label88 = new Label();
      this.NameGuild = new Label();
      this.GuildMaster = new Label();
      this.Aplicar = new Button();
      this.Reload = new Button();
      this.Buscar = new Button();
      this.BorrarDatos = new Button();
      this.Cerrar = new Button();
      this.Minimizar = new Button();
      this.Titulo = new Label();
      this.SuspendLayout();
      this.Personajes.Cursor = Cursors.Hand;
      this.Personajes.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Personajes.ItemHeight = 13;
      ComboBox personajes1 = this.Personajes;
      Point point1 = new Point(187, 50);
      Point point2 = point1;
      personajes1.Location = point2;
      this.Personajes.Name = "Personajes";
      ComboBox personajes2 = this.Personajes;
      Size size1 = new Size(179, 21);
      Size size2 = size1;
      personajes2.Size = size2;
      this.Personajes.TabIndex = 445;
      this.Personajes.Text = " >> Seleccione Personaje << ";
      this.Guilds.Cursor = Cursors.Hand;
      this.Guilds.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.Guilds.ItemHeight = 13;
      ComboBox guilds1 = this.Guilds;
      point1 = new Point(9, 50);
      Point point3 = point1;
      guilds1.Location = point3;
      this.Guilds.Name = "Guilds";
      ComboBox guilds2 = this.Guilds;
      size1 = new Size(179, 21);
      Size size3 = size1;
      guilds2.Size = size3;
      this.Guilds.TabIndex = 444;
      this.Guilds.Text = " >> Seleccione Guild << ";
      this.PersonajeSearch.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox personajeSearch1 = this.PersonajeSearch;
      point1 = new Point(253, 30);
      Point point4 = point1;
      personajeSearch1.Location = point4;
      this.PersonajeSearch.MaxLength = 32;
      this.PersonajeSearch.Name = "PersonajeSearch";
      TextBox personajeSearch2 = this.PersonajeSearch;
      size1 = new Size(113, 20);
      Size size4 = size1;
      personajeSearch2.Size = size4;
      this.PersonajeSearch.TabIndex = 447;
      this.PersonajeSearch.TextAlign = HorizontalAlignment.Center;
      this.GuildSearch.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox guildSearch1 = this.GuildSearch;
      point1 = new Point(9, 30);
      Point point5 = point1;
      guildSearch1.Location = point5;
      this.GuildSearch.MaxLength = 32;
      this.GuildSearch.Name = "GuildSearch";
      TextBox guildSearch2 = this.GuildSearch;
      size1 = new Size(104, 20);
      Size size5 = size1;
      guildSearch2.Size = size5;
      this.GuildSearch.TabIndex = 446;
      this.GuildSearch.TextAlign = HorizontalAlignment.Center;
      this.GuildsL.BackColor = Color.Transparent;
      this.GuildsL.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.GuildsL.ForeColor = Color.DimGray;
      Label guildsL1 = this.GuildsL;
      point1 = new Point(115, 33);
      Point point6 = point1;
      guildsL1.Location = point6;
      this.GuildsL.Name = "GuildsL";
      Label guildsL2 = this.GuildsL;
      size1 = new Size(50, 14);
      Size size6 = size1;
      guildsL2.Size = size6;
      this.GuildsL.TabIndex = 449;
      this.GuildsL.Text = "Guild";
      this.GuildsL.TextAlign = ContentAlignment.MiddleCenter;
      this.Chart.BackColor = Color.Transparent;
      this.Chart.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Chart.ForeColor = Color.DimGray;
      Label chart1 = this.Chart;
      point1 = new Point(194, 33);
      Point point7 = point1;
      chart1.Location = point7;
      this.Chart.Name = "Chart";
      Label chart2 = this.Chart;
      size1 = new Size(64, 14);
      Size size7 = size1;
      chart2.Size = size7;
      this.Chart.TabIndex = 450;
      this.Chart.Text = "Master";
      this.Chart.TextAlign = ContentAlignment.MiddleCenter;
      this.CreateGuild.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.CreateGuild.BackgroundImage = (Image) EmbeddedResources.smethod_50();
      this.CreateGuild.BackgroundImageLayout = ImageLayout.Center;
      this.CreateGuild.Cursor = Cursors.Hand;
      this.CreateGuild.Enabled = false;
      this.CreateGuild.FlatAppearance.BorderSize = 0;
      this.CreateGuild.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.CreateGuild.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.CreateGuild.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.CreateGuild.FlatStyle = FlatStyle.Flat;
      this.CreateGuild.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.CreateGuild.ForeColor = Color.Transparent;
      Button createGuild1 = this.CreateGuild;
      point1 = new Point(316, 368);
      Point point8 = point1;
      createGuild1.Location = point8;
      this.CreateGuild.Name = "CreateGuild";
      Button createGuild2 = this.CreateGuild;
      size1 = new Size(52, 28);
      Size size8 = size1;
      createGuild2.Size = size8;
      this.CreateGuild.TabIndex = 501;
      this.CreateGuild.TabStop = false;
      this.CreateGuild.UseVisualStyleBackColor = false;
      this.BorrarGuild.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.BorrarGuild.BackgroundImage = (Image) EmbeddedResources.smethod_53();
      this.BorrarGuild.BackgroundImageLayout = ImageLayout.Center;
      this.BorrarGuild.Cursor = Cursors.Hand;
      this.BorrarGuild.Enabled = false;
      this.BorrarGuild.FlatAppearance.BorderSize = 0;
      this.BorrarGuild.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BorrarGuild.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BorrarGuild.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BorrarGuild.FlatStyle = FlatStyle.Flat;
      this.BorrarGuild.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BorrarGuild.ForeColor = Color.Transparent;
      Button borrarGuild1 = this.BorrarGuild;
      point1 = new Point(7, 284);
      Point point9 = point1;
      borrarGuild1.Location = point9;
      this.BorrarGuild.Name = "BorrarGuild";
      Button borrarGuild2 = this.BorrarGuild;
      size1 = new Size(52, 28);
      Size size9 = size1;
      borrarGuild2.Size = size9;
      this.BorrarGuild.TabIndex = 500;
      this.BorrarGuild.TabStop = false;
      this.BorrarGuild.UseVisualStyleBackColor = false;
      this.MK1.BackColor = Color.Transparent;
      this.MK1.BorderStyle = BorderStyle.Fixed3D;
      this.MK1.Cursor = Cursors.Hand;
      Label mk1_1 = this.MK1;
      point1 = new Point(300, 96);
      Point point10 = point1;
      mk1_1.Location = point10;
      Label mk1_2 = this.MK1;
      Padding padding1 = new Padding(0);
      Padding padding2 = padding1;
      mk1_2.Margin = padding2;
      this.MK1.Name = "MK1";
      Label mk1_3 = this.MK1;
      size1 = new Size(9, 9);
      Size size10 = size1;
      mk1_3.Size = size10;
      this.MK1.TabIndex = 509;
      this.MK1.Tag = (object) "0";
      this.MK2.BackColor = Color.Transparent;
      this.MK2.BorderStyle = BorderStyle.Fixed3D;
      this.MK2.Cursor = Cursors.Hand;
      Label mk2_1 = this.MK2;
      point1 = new Point(308, 96);
      Point point11 = point1;
      mk2_1.Location = point11;
      Label mk2_2 = this.MK2;
      padding1 = new Padding(0);
      Padding padding3 = padding1;
      mk2_2.Margin = padding3;
      this.MK2.Name = "MK2";
      Label mk2_3 = this.MK2;
      size1 = new Size(9, 9);
      Size size11 = size1;
      mk2_3.Size = size11;
      this.MK2.TabIndex = 510;
      this.MK2.Tag = (object) "0";
      this.MK3.BackColor = Color.Transparent;
      this.MK3.BorderStyle = BorderStyle.Fixed3D;
      this.MK3.Cursor = Cursors.Hand;
      Label mk3_1 = this.MK3;
      point1 = new Point(316, 96);
      Point point12 = point1;
      mk3_1.Location = point12;
      Label mk3_2 = this.MK3;
      padding1 = new Padding(0);
      Padding padding4 = padding1;
      mk3_2.Margin = padding4;
      this.MK3.Name = "MK3";
      Label mk3_3 = this.MK3;
      size1 = new Size(9, 9);
      Size size12 = size1;
      mk3_3.Size = size12;
      this.MK3.TabIndex = 511;
      this.MK3.Tag = (object) "0";
      this.MK4.BackColor = Color.Transparent;
      this.MK4.BorderStyle = BorderStyle.Fixed3D;
      this.MK4.Cursor = Cursors.Hand;
      Label mk4_1 = this.MK4;
      point1 = new Point(324, 96);
      Point point13 = point1;
      mk4_1.Location = point13;
      Label mk4_2 = this.MK4;
      padding1 = new Padding(0);
      Padding padding5 = padding1;
      mk4_2.Margin = padding5;
      this.MK4.Name = "MK4";
      Label mk4_3 = this.MK4;
      size1 = new Size(9, 9);
      Size size13 = size1;
      mk4_3.Size = size13;
      this.MK4.TabIndex = 512;
      this.MK4.Tag = (object) "0";
      this.MK5.BackColor = Color.Transparent;
      this.MK5.BorderStyle = BorderStyle.Fixed3D;
      this.MK5.Cursor = Cursors.Hand;
      Label mk5_1 = this.MK5;
      point1 = new Point(332, 96);
      Point point14 = point1;
      mk5_1.Location = point14;
      Label mk5_2 = this.MK5;
      padding1 = new Padding(0);
      Padding padding6 = padding1;
      mk5_2.Margin = padding6;
      this.MK5.Name = "MK5";
      Label mk5_3 = this.MK5;
      size1 = new Size(9, 9);
      Size size14 = size1;
      mk5_3.Size = size14;
      this.MK5.TabIndex = 513;
      this.MK5.Tag = (object) "0";
      this.MK6.BackColor = Color.Transparent;
      this.MK6.BorderStyle = BorderStyle.Fixed3D;
      this.MK6.Cursor = Cursors.Hand;
      Label mk6_1 = this.MK6;
      point1 = new Point(340, 96);
      Point point15 = point1;
      mk6_1.Location = point15;
      Label mk6_2 = this.MK6;
      padding1 = new Padding(0);
      Padding padding7 = padding1;
      mk6_2.Margin = padding7;
      this.MK6.Name = "MK6";
      Label mk6_3 = this.MK6;
      size1 = new Size(9, 9);
      Size size15 = size1;
      mk6_3.Size = size15;
      this.MK6.TabIndex = 514;
      this.MK6.Tag = (object) "0";
      this.MK7.BackColor = Color.Transparent;
      this.MK7.BorderStyle = BorderStyle.Fixed3D;
      this.MK7.Cursor = Cursors.Hand;
      Label mk7_1 = this.MK7;
      point1 = new Point(348, 96);
      Point point16 = point1;
      mk7_1.Location = point16;
      Label mk7_2 = this.MK7;
      padding1 = new Padding(0);
      Padding padding8 = padding1;
      mk7_2.Margin = padding8;
      this.MK7.Name = "MK7";
      Label mk7_3 = this.MK7;
      size1 = new Size(9, 9);
      Size size16 = size1;
      mk7_3.Size = size16;
      this.MK7.TabIndex = 515;
      this.MK7.Tag = (object) "0";
      this.MK15.BackColor = Color.Transparent;
      this.MK15.BorderStyle = BorderStyle.Fixed3D;
      this.MK15.Cursor = Cursors.Hand;
      Label mk15_1 = this.MK15;
      point1 = new Point(348, 104);
      Point point17 = point1;
      mk15_1.Location = point17;
      Label mk15_2 = this.MK15;
      padding1 = new Padding(0);
      Padding padding9 = padding1;
      mk15_2.Margin = padding9;
      this.MK15.Name = "MK15";
      Label mk15_3 = this.MK15;
      size1 = new Size(9, 9);
      Size size17 = size1;
      mk15_3.Size = size17;
      this.MK15.TabIndex = 522;
      this.MK15.Tag = (object) "0";
      this.MK14.BackColor = Color.Transparent;
      this.MK14.BorderStyle = BorderStyle.Fixed3D;
      this.MK14.Cursor = Cursors.Hand;
      Label mk14_1 = this.MK14;
      point1 = new Point(340, 104);
      Point point18 = point1;
      mk14_1.Location = point18;
      Label mk14_2 = this.MK14;
      padding1 = new Padding(0);
      Padding padding10 = padding1;
      mk14_2.Margin = padding10;
      this.MK14.Name = "MK14";
      Label mk14_3 = this.MK14;
      size1 = new Size(9, 9);
      Size size18 = size1;
      mk14_3.Size = size18;
      this.MK14.TabIndex = 521;
      this.MK14.Tag = (object) "0";
      this.MK13.BackColor = Color.Transparent;
      this.MK13.BorderStyle = BorderStyle.Fixed3D;
      this.MK13.Cursor = Cursors.Hand;
      Label mk13_1 = this.MK13;
      point1 = new Point(332, 104);
      Point point19 = point1;
      mk13_1.Location = point19;
      Label mk13_2 = this.MK13;
      padding1 = new Padding(0);
      Padding padding11 = padding1;
      mk13_2.Margin = padding11;
      this.MK13.Name = "MK13";
      Label mk13_3 = this.MK13;
      size1 = new Size(9, 9);
      Size size19 = size1;
      mk13_3.Size = size19;
      this.MK13.TabIndex = 520;
      this.MK13.Tag = (object) "0";
      this.MK12.BackColor = Color.Transparent;
      this.MK12.BorderStyle = BorderStyle.Fixed3D;
      this.MK12.Cursor = Cursors.Hand;
      Label mk12_1 = this.MK12;
      point1 = new Point(324, 104);
      Point point20 = point1;
      mk12_1.Location = point20;
      Label mk12_2 = this.MK12;
      padding1 = new Padding(0);
      Padding padding12 = padding1;
      mk12_2.Margin = padding12;
      this.MK12.Name = "MK12";
      Label mk12_3 = this.MK12;
      size1 = new Size(9, 9);
      Size size20 = size1;
      mk12_3.Size = size20;
      this.MK12.TabIndex = 519;
      this.MK12.Tag = (object) "0";
      this.MK11.BackColor = Color.Transparent;
      this.MK11.BorderStyle = BorderStyle.Fixed3D;
      this.MK11.Cursor = Cursors.Hand;
      Label mk11_1 = this.MK11;
      point1 = new Point(316, 104);
      Point point21 = point1;
      mk11_1.Location = point21;
      Label mk11_2 = this.MK11;
      padding1 = new Padding(0);
      Padding padding13 = padding1;
      mk11_2.Margin = padding13;
      this.MK11.Name = "MK11";
      Label mk11_3 = this.MK11;
      size1 = new Size(9, 9);
      Size size21 = size1;
      mk11_3.Size = size21;
      this.MK11.TabIndex = 518;
      this.MK11.Tag = (object) "0";
      this.MK10.BackColor = Color.Transparent;
      this.MK10.BorderStyle = BorderStyle.Fixed3D;
      this.MK10.Cursor = Cursors.Hand;
      Label mk10_1 = this.MK10;
      point1 = new Point(308, 104);
      Point point22 = point1;
      mk10_1.Location = point22;
      Label mk10_2 = this.MK10;
      padding1 = new Padding(0);
      Padding padding14 = padding1;
      mk10_2.Margin = padding14;
      this.MK10.Name = "MK10";
      Label mk10_3 = this.MK10;
      size1 = new Size(9, 9);
      Size size22 = size1;
      mk10_3.Size = size22;
      this.MK10.TabIndex = 517;
      this.MK10.Tag = (object) "0";
      this.MK9.BackColor = Color.Transparent;
      this.MK9.BorderStyle = BorderStyle.Fixed3D;
      this.MK9.Cursor = Cursors.Hand;
      Label mk9_1 = this.MK9;
      point1 = new Point(300, 104);
      Point point23 = point1;
      mk9_1.Location = point23;
      Label mk9_2 = this.MK9;
      padding1 = new Padding(0);
      Padding padding15 = padding1;
      mk9_2.Margin = padding15;
      this.MK9.Name = "MK9";
      Label mk9_3 = this.MK9;
      size1 = new Size(9, 9);
      Size size23 = size1;
      mk9_3.Size = size23;
      this.MK9.TabIndex = 516;
      this.MK9.Tag = (object) "0";
      this.MK23.BackColor = Color.Transparent;
      this.MK23.BorderStyle = BorderStyle.Fixed3D;
      this.MK23.Cursor = Cursors.Hand;
      Label mk23_1 = this.MK23;
      point1 = new Point(348, 112);
      Point point24 = point1;
      mk23_1.Location = point24;
      Label mk23_2 = this.MK23;
      padding1 = new Padding(0);
      Padding padding16 = padding1;
      mk23_2.Margin = padding16;
      this.MK23.Name = "MK23";
      Label mk23_3 = this.MK23;
      size1 = new Size(9, 9);
      Size size24 = size1;
      mk23_3.Size = size24;
      this.MK23.TabIndex = 529;
      this.MK23.Tag = (object) "0";
      this.MK22.BackColor = Color.Transparent;
      this.MK22.BorderStyle = BorderStyle.Fixed3D;
      this.MK22.Cursor = Cursors.Hand;
      Label mk22_1 = this.MK22;
      point1 = new Point(340, 112);
      Point point25 = point1;
      mk22_1.Location = point25;
      Label mk22_2 = this.MK22;
      padding1 = new Padding(0);
      Padding padding17 = padding1;
      mk22_2.Margin = padding17;
      this.MK22.Name = "MK22";
      Label mk22_3 = this.MK22;
      size1 = new Size(9, 9);
      Size size25 = size1;
      mk22_3.Size = size25;
      this.MK22.TabIndex = 528;
      this.MK22.Tag = (object) "0";
      this.MK21.BackColor = Color.Transparent;
      this.MK21.BorderStyle = BorderStyle.Fixed3D;
      this.MK21.Cursor = Cursors.Hand;
      Label mk21_1 = this.MK21;
      point1 = new Point(332, 112);
      Point point26 = point1;
      mk21_1.Location = point26;
      Label mk21_2 = this.MK21;
      padding1 = new Padding(0);
      Padding padding18 = padding1;
      mk21_2.Margin = padding18;
      this.MK21.Name = "MK21";
      Label mk21_3 = this.MK21;
      size1 = new Size(9, 9);
      Size size26 = size1;
      mk21_3.Size = size26;
      this.MK21.TabIndex = 527;
      this.MK21.Tag = (object) "0";
      this.MK20.BackColor = Color.Transparent;
      this.MK20.BorderStyle = BorderStyle.Fixed3D;
      this.MK20.Cursor = Cursors.Hand;
      Label mk20_1 = this.MK20;
      point1 = new Point(324, 112);
      Point point27 = point1;
      mk20_1.Location = point27;
      Label mk20_2 = this.MK20;
      padding1 = new Padding(0);
      Padding padding19 = padding1;
      mk20_2.Margin = padding19;
      this.MK20.Name = "MK20";
      Label mk20_3 = this.MK20;
      size1 = new Size(9, 9);
      Size size27 = size1;
      mk20_3.Size = size27;
      this.MK20.TabIndex = 526;
      this.MK20.Tag = (object) "0";
      this.MK19.BackColor = Color.Transparent;
      this.MK19.BorderStyle = BorderStyle.Fixed3D;
      this.MK19.Cursor = Cursors.Hand;
      Label mk19_1 = this.MK19;
      point1 = new Point(316, 112);
      Point point28 = point1;
      mk19_1.Location = point28;
      Label mk19_2 = this.MK19;
      padding1 = new Padding(0);
      Padding padding20 = padding1;
      mk19_2.Margin = padding20;
      this.MK19.Name = "MK19";
      Label mk19_3 = this.MK19;
      size1 = new Size(9, 9);
      Size size28 = size1;
      mk19_3.Size = size28;
      this.MK19.TabIndex = 525;
      this.MK19.Tag = (object) "0";
      this.MK18.BackColor = Color.Transparent;
      this.MK18.BorderStyle = BorderStyle.Fixed3D;
      this.MK18.Cursor = Cursors.Hand;
      Label mk18_1 = this.MK18;
      point1 = new Point(308, 112);
      Point point29 = point1;
      mk18_1.Location = point29;
      Label mk18_2 = this.MK18;
      padding1 = new Padding(0);
      Padding padding21 = padding1;
      mk18_2.Margin = padding21;
      this.MK18.Name = "MK18";
      Label mk18_3 = this.MK18;
      size1 = new Size(9, 9);
      Size size29 = size1;
      mk18_3.Size = size29;
      this.MK18.TabIndex = 524;
      this.MK18.Tag = (object) "0";
      this.MK17.BackColor = Color.Transparent;
      this.MK17.BorderStyle = BorderStyle.Fixed3D;
      this.MK17.Cursor = Cursors.Hand;
      Label mk17_1 = this.MK17;
      point1 = new Point(300, 112);
      Point point30 = point1;
      mk17_1.Location = point30;
      Label mk17_2 = this.MK17;
      padding1 = new Padding(0);
      Padding padding22 = padding1;
      mk17_2.Margin = padding22;
      this.MK17.Name = "MK17";
      Label mk17_3 = this.MK17;
      size1 = new Size(9, 9);
      Size size30 = size1;
      mk17_3.Size = size30;
      this.MK17.TabIndex = 523;
      this.MK17.Tag = (object) "0";
      this.MK31.BackColor = Color.Transparent;
      this.MK31.BorderStyle = BorderStyle.Fixed3D;
      this.MK31.Cursor = Cursors.Hand;
      Label mk31_1 = this.MK31;
      point1 = new Point(348, 120);
      Point point31 = point1;
      mk31_1.Location = point31;
      Label mk31_2 = this.MK31;
      padding1 = new Padding(0);
      Padding padding23 = padding1;
      mk31_2.Margin = padding23;
      this.MK31.Name = "MK31";
      Label mk31_3 = this.MK31;
      size1 = new Size(9, 9);
      Size size31 = size1;
      mk31_3.Size = size31;
      this.MK31.TabIndex = 536;
      this.MK31.Tag = (object) "0";
      this.MK30.BackColor = Color.Transparent;
      this.MK30.BorderStyle = BorderStyle.Fixed3D;
      this.MK30.Cursor = Cursors.Hand;
      Label mk30_1 = this.MK30;
      point1 = new Point(340, 120);
      Point point32 = point1;
      mk30_1.Location = point32;
      Label mk30_2 = this.MK30;
      padding1 = new Padding(0);
      Padding padding24 = padding1;
      mk30_2.Margin = padding24;
      this.MK30.Name = "MK30";
      Label mk30_3 = this.MK30;
      size1 = new Size(9, 9);
      Size size32 = size1;
      mk30_3.Size = size32;
      this.MK30.TabIndex = 535;
      this.MK30.Tag = (object) "0";
      this.MK29.BackColor = Color.Transparent;
      this.MK29.BorderStyle = BorderStyle.Fixed3D;
      this.MK29.Cursor = Cursors.Hand;
      Label mk29_1 = this.MK29;
      point1 = new Point(332, 120);
      Point point33 = point1;
      mk29_1.Location = point33;
      Label mk29_2 = this.MK29;
      padding1 = new Padding(0);
      Padding padding25 = padding1;
      mk29_2.Margin = padding25;
      this.MK29.Name = "MK29";
      Label mk29_3 = this.MK29;
      size1 = new Size(9, 9);
      Size size33 = size1;
      mk29_3.Size = size33;
      this.MK29.TabIndex = 534;
      this.MK29.Tag = (object) "0";
      this.MK28.BackColor = Color.Transparent;
      this.MK28.BorderStyle = BorderStyle.Fixed3D;
      this.MK28.Cursor = Cursors.Hand;
      Label mk28_1 = this.MK28;
      point1 = new Point(324, 120);
      Point point34 = point1;
      mk28_1.Location = point34;
      Label mk28_2 = this.MK28;
      padding1 = new Padding(0);
      Padding padding26 = padding1;
      mk28_2.Margin = padding26;
      this.MK28.Name = "MK28";
      Label mk28_3 = this.MK28;
      size1 = new Size(9, 9);
      Size size34 = size1;
      mk28_3.Size = size34;
      this.MK28.TabIndex = 533;
      this.MK28.Tag = (object) "0";
      this.MK27.BackColor = Color.Transparent;
      this.MK27.BorderStyle = BorderStyle.Fixed3D;
      this.MK27.Cursor = Cursors.Hand;
      Label mk27_1 = this.MK27;
      point1 = new Point(316, 120);
      Point point35 = point1;
      mk27_1.Location = point35;
      Label mk27_2 = this.MK27;
      padding1 = new Padding(0);
      Padding padding27 = padding1;
      mk27_2.Margin = padding27;
      this.MK27.Name = "MK27";
      Label mk27_3 = this.MK27;
      size1 = new Size(9, 9);
      Size size35 = size1;
      mk27_3.Size = size35;
      this.MK27.TabIndex = 532;
      this.MK27.Tag = (object) "0";
      this.MK26.BackColor = Color.Transparent;
      this.MK26.BorderStyle = BorderStyle.Fixed3D;
      this.MK26.Cursor = Cursors.Hand;
      Label mk26_1 = this.MK26;
      point1 = new Point(308, 120);
      Point point36 = point1;
      mk26_1.Location = point36;
      Label mk26_2 = this.MK26;
      padding1 = new Padding(0);
      Padding padding28 = padding1;
      mk26_2.Margin = padding28;
      this.MK26.Name = "MK26";
      Label mk26_3 = this.MK26;
      size1 = new Size(9, 9);
      Size size36 = size1;
      mk26_3.Size = size36;
      this.MK26.TabIndex = 531;
      this.MK26.Tag = (object) "0";
      this.MK25.BackColor = Color.Transparent;
      this.MK25.BorderStyle = BorderStyle.Fixed3D;
      this.MK25.Cursor = Cursors.Hand;
      Label mk25_1 = this.MK25;
      point1 = new Point(300, 120);
      Point point37 = point1;
      mk25_1.Location = point37;
      Label mk25_2 = this.MK25;
      padding1 = new Padding(0);
      Padding padding29 = padding1;
      mk25_2.Margin = padding29;
      this.MK25.Name = "MK25";
      Label mk25_3 = this.MK25;
      size1 = new Size(9, 9);
      Size size37 = size1;
      mk25_3.Size = size37;
      this.MK25.TabIndex = 530;
      this.MK25.Tag = (object) "0";
      this.MK39.BackColor = Color.Transparent;
      this.MK39.BorderStyle = BorderStyle.Fixed3D;
      this.MK39.Cursor = Cursors.Hand;
      Label mk39_1 = this.MK39;
      point1 = new Point(348, 128);
      Point point38 = point1;
      mk39_1.Location = point38;
      Label mk39_2 = this.MK39;
      padding1 = new Padding(0);
      Padding padding30 = padding1;
      mk39_2.Margin = padding30;
      this.MK39.Name = "MK39";
      Label mk39_3 = this.MK39;
      size1 = new Size(9, 9);
      Size size38 = size1;
      mk39_3.Size = size38;
      this.MK39.TabIndex = 543;
      this.MK39.Tag = (object) "0";
      this.MK38.BackColor = Color.Transparent;
      this.MK38.BorderStyle = BorderStyle.Fixed3D;
      this.MK38.Cursor = Cursors.Hand;
      Label mk38_1 = this.MK38;
      point1 = new Point(340, 128);
      Point point39 = point1;
      mk38_1.Location = point39;
      Label mk38_2 = this.MK38;
      padding1 = new Padding(0);
      Padding padding31 = padding1;
      mk38_2.Margin = padding31;
      this.MK38.Name = "MK38";
      Label mk38_3 = this.MK38;
      size1 = new Size(9, 9);
      Size size39 = size1;
      mk38_3.Size = size39;
      this.MK38.TabIndex = 542;
      this.MK38.Tag = (object) "0";
      this.MK37.BackColor = Color.Transparent;
      this.MK37.BorderStyle = BorderStyle.Fixed3D;
      this.MK37.Cursor = Cursors.Hand;
      Label mk37_1 = this.MK37;
      point1 = new Point(332, 128);
      Point point40 = point1;
      mk37_1.Location = point40;
      Label mk37_2 = this.MK37;
      padding1 = new Padding(0);
      Padding padding32 = padding1;
      mk37_2.Margin = padding32;
      this.MK37.Name = "MK37";
      Label mk37_3 = this.MK37;
      size1 = new Size(9, 9);
      Size size40 = size1;
      mk37_3.Size = size40;
      this.MK37.TabIndex = 541;
      this.MK37.Tag = (object) "0";
      this.MK36.BackColor = Color.Transparent;
      this.MK36.BorderStyle = BorderStyle.Fixed3D;
      this.MK36.Cursor = Cursors.Hand;
      Label mk36_1 = this.MK36;
      point1 = new Point(324, 128);
      Point point41 = point1;
      mk36_1.Location = point41;
      Label mk36_2 = this.MK36;
      padding1 = new Padding(0);
      Padding padding33 = padding1;
      mk36_2.Margin = padding33;
      this.MK36.Name = "MK36";
      Label mk36_3 = this.MK36;
      size1 = new Size(9, 9);
      Size size41 = size1;
      mk36_3.Size = size41;
      this.MK36.TabIndex = 540;
      this.MK36.Tag = (object) "0";
      this.MK35.BackColor = Color.Transparent;
      this.MK35.BorderStyle = BorderStyle.Fixed3D;
      this.MK35.Cursor = Cursors.Hand;
      Label mk35_1 = this.MK35;
      point1 = new Point(316, 128);
      Point point42 = point1;
      mk35_1.Location = point42;
      Label mk35_2 = this.MK35;
      padding1 = new Padding(0);
      Padding padding34 = padding1;
      mk35_2.Margin = padding34;
      this.MK35.Name = "MK35";
      Label mk35_3 = this.MK35;
      size1 = new Size(9, 9);
      Size size42 = size1;
      mk35_3.Size = size42;
      this.MK35.TabIndex = 539;
      this.MK35.Tag = (object) "0";
      this.MK34.BackColor = Color.Transparent;
      this.MK34.BorderStyle = BorderStyle.Fixed3D;
      this.MK34.Cursor = Cursors.Hand;
      Label mk34_1 = this.MK34;
      point1 = new Point(308, 128);
      Point point43 = point1;
      mk34_1.Location = point43;
      Label mk34_2 = this.MK34;
      padding1 = new Padding(0);
      Padding padding35 = padding1;
      mk34_2.Margin = padding35;
      this.MK34.Name = "MK34";
      Label mk34_3 = this.MK34;
      size1 = new Size(9, 9);
      Size size43 = size1;
      mk34_3.Size = size43;
      this.MK34.TabIndex = 538;
      this.MK34.Tag = (object) "0";
      this.MK33.BackColor = Color.Transparent;
      this.MK33.BorderStyle = BorderStyle.Fixed3D;
      this.MK33.Cursor = Cursors.Hand;
      Label mk33_1 = this.MK33;
      point1 = new Point(300, 128);
      Point point44 = point1;
      mk33_1.Location = point44;
      Label mk33_2 = this.MK33;
      padding1 = new Padding(0);
      Padding padding36 = padding1;
      mk33_2.Margin = padding36;
      this.MK33.Name = "MK33";
      Label mk33_3 = this.MK33;
      size1 = new Size(9, 9);
      Size size44 = size1;
      mk33_3.Size = size44;
      this.MK33.TabIndex = 537;
      this.MK33.Tag = (object) "0";
      this.MK47.BackColor = Color.Transparent;
      this.MK47.BorderStyle = BorderStyle.Fixed3D;
      this.MK47.Cursor = Cursors.Hand;
      Label mk47_1 = this.MK47;
      point1 = new Point(348, 136);
      Point point45 = point1;
      mk47_1.Location = point45;
      Label mk47_2 = this.MK47;
      padding1 = new Padding(0);
      Padding padding37 = padding1;
      mk47_2.Margin = padding37;
      this.MK47.Name = "MK47";
      Label mk47_3 = this.MK47;
      size1 = new Size(9, 9);
      Size size45 = size1;
      mk47_3.Size = size45;
      this.MK47.TabIndex = 550;
      this.MK47.Tag = (object) "0";
      this.MK46.BackColor = Color.Transparent;
      this.MK46.BorderStyle = BorderStyle.Fixed3D;
      this.MK46.Cursor = Cursors.Hand;
      Label mk46_1 = this.MK46;
      point1 = new Point(340, 136);
      Point point46 = point1;
      mk46_1.Location = point46;
      Label mk46_2 = this.MK46;
      padding1 = new Padding(0);
      Padding padding38 = padding1;
      mk46_2.Margin = padding38;
      this.MK46.Name = "MK46";
      Label mk46_3 = this.MK46;
      size1 = new Size(9, 9);
      Size size46 = size1;
      mk46_3.Size = size46;
      this.MK46.TabIndex = 549;
      this.MK46.Tag = (object) "0";
      this.MK45.BackColor = Color.Transparent;
      this.MK45.BorderStyle = BorderStyle.Fixed3D;
      this.MK45.Cursor = Cursors.Hand;
      Label mk45_1 = this.MK45;
      point1 = new Point(332, 136);
      Point point47 = point1;
      mk45_1.Location = point47;
      Label mk45_2 = this.MK45;
      padding1 = new Padding(0);
      Padding padding39 = padding1;
      mk45_2.Margin = padding39;
      this.MK45.Name = "MK45";
      Label mk45_3 = this.MK45;
      size1 = new Size(9, 9);
      Size size47 = size1;
      mk45_3.Size = size47;
      this.MK45.TabIndex = 548;
      this.MK45.Tag = (object) "0";
      this.MK44.BackColor = Color.Transparent;
      this.MK44.BorderStyle = BorderStyle.Fixed3D;
      this.MK44.Cursor = Cursors.Hand;
      Label mk44_1 = this.MK44;
      point1 = new Point(324, 136);
      Point point48 = point1;
      mk44_1.Location = point48;
      Label mk44_2 = this.MK44;
      padding1 = new Padding(0);
      Padding padding40 = padding1;
      mk44_2.Margin = padding40;
      this.MK44.Name = "MK44";
      Label mk44_3 = this.MK44;
      size1 = new Size(9, 9);
      Size size48 = size1;
      mk44_3.Size = size48;
      this.MK44.TabIndex = 547;
      this.MK44.Tag = (object) "0";
      this.MK43.BackColor = Color.Transparent;
      this.MK43.BorderStyle = BorderStyle.Fixed3D;
      this.MK43.Cursor = Cursors.Hand;
      Label mk43_1 = this.MK43;
      point1 = new Point(316, 136);
      Point point49 = point1;
      mk43_1.Location = point49;
      Label mk43_2 = this.MK43;
      padding1 = new Padding(0);
      Padding padding41 = padding1;
      mk43_2.Margin = padding41;
      this.MK43.Name = "MK43";
      Label mk43_3 = this.MK43;
      size1 = new Size(9, 9);
      Size size49 = size1;
      mk43_3.Size = size49;
      this.MK43.TabIndex = 546;
      this.MK43.Tag = (object) "0";
      this.MK42.BackColor = Color.Transparent;
      this.MK42.BorderStyle = BorderStyle.Fixed3D;
      this.MK42.Cursor = Cursors.Hand;
      Label mk42_1 = this.MK42;
      point1 = new Point(308, 136);
      Point point50 = point1;
      mk42_1.Location = point50;
      Label mk42_2 = this.MK42;
      padding1 = new Padding(0);
      Padding padding42 = padding1;
      mk42_2.Margin = padding42;
      this.MK42.Name = "MK42";
      Label mk42_3 = this.MK42;
      size1 = new Size(9, 9);
      Size size50 = size1;
      mk42_3.Size = size50;
      this.MK42.TabIndex = 545;
      this.MK42.Tag = (object) "0";
      this.MK41.BackColor = Color.Transparent;
      this.MK41.BorderStyle = BorderStyle.Fixed3D;
      this.MK41.Cursor = Cursors.Hand;
      Label mk41_1 = this.MK41;
      point1 = new Point(300, 136);
      Point point51 = point1;
      mk41_1.Location = point51;
      Label mk41_2 = this.MK41;
      padding1 = new Padding(0);
      Padding padding43 = padding1;
      mk41_2.Margin = padding43;
      this.MK41.Name = "MK41";
      Label mk41_3 = this.MK41;
      size1 = new Size(9, 9);
      Size size51 = size1;
      mk41_3.Size = size51;
      this.MK41.TabIndex = 544;
      this.MK41.Tag = (object) "0";
      this.MK55.BackColor = Color.Transparent;
      this.MK55.BorderStyle = BorderStyle.Fixed3D;
      this.MK55.Cursor = Cursors.Hand;
      Label mk55_1 = this.MK55;
      point1 = new Point(348, 144);
      Point point52 = point1;
      mk55_1.Location = point52;
      Label mk55_2 = this.MK55;
      padding1 = new Padding(0);
      Padding padding44 = padding1;
      mk55_2.Margin = padding44;
      this.MK55.Name = "MK55";
      Label mk55_3 = this.MK55;
      size1 = new Size(9, 9);
      Size size52 = size1;
      mk55_3.Size = size52;
      this.MK55.TabIndex = 557;
      this.MK55.Tag = (object) "0";
      this.MK54.BackColor = Color.Transparent;
      this.MK54.BorderStyle = BorderStyle.Fixed3D;
      this.MK54.Cursor = Cursors.Hand;
      Label mk54_1 = this.MK54;
      point1 = new Point(340, 144);
      Point point53 = point1;
      mk54_1.Location = point53;
      Label mk54_2 = this.MK54;
      padding1 = new Padding(0);
      Padding padding45 = padding1;
      mk54_2.Margin = padding45;
      this.MK54.Name = "MK54";
      Label mk54_3 = this.MK54;
      size1 = new Size(9, 9);
      Size size53 = size1;
      mk54_3.Size = size53;
      this.MK54.TabIndex = 556;
      this.MK54.Tag = (object) "0";
      this.MK53.BackColor = Color.Transparent;
      this.MK53.BorderStyle = BorderStyle.Fixed3D;
      this.MK53.Cursor = Cursors.Hand;
      Label mk53_1 = this.MK53;
      point1 = new Point(332, 144);
      Point point54 = point1;
      mk53_1.Location = point54;
      Label mk53_2 = this.MK53;
      padding1 = new Padding(0);
      Padding padding46 = padding1;
      mk53_2.Margin = padding46;
      this.MK53.Name = "MK53";
      Label mk53_3 = this.MK53;
      size1 = new Size(9, 9);
      Size size54 = size1;
      mk53_3.Size = size54;
      this.MK53.TabIndex = 555;
      this.MK53.Tag = (object) "0";
      this.MK52.BackColor = Color.Transparent;
      this.MK52.BorderStyle = BorderStyle.Fixed3D;
      this.MK52.Cursor = Cursors.Hand;
      Label mk52_1 = this.MK52;
      point1 = new Point(324, 144);
      Point point55 = point1;
      mk52_1.Location = point55;
      Label mk52_2 = this.MK52;
      padding1 = new Padding(0);
      Padding padding47 = padding1;
      mk52_2.Margin = padding47;
      this.MK52.Name = "MK52";
      Label mk52_3 = this.MK52;
      size1 = new Size(9, 9);
      Size size55 = size1;
      mk52_3.Size = size55;
      this.MK52.TabIndex = 554;
      this.MK52.Tag = (object) "0";
      this.MK51.BackColor = Color.Transparent;
      this.MK51.BorderStyle = BorderStyle.Fixed3D;
      this.MK51.Cursor = Cursors.Hand;
      Label mk51_1 = this.MK51;
      point1 = new Point(316, 144);
      Point point56 = point1;
      mk51_1.Location = point56;
      Label mk51_2 = this.MK51;
      padding1 = new Padding(0);
      Padding padding48 = padding1;
      mk51_2.Margin = padding48;
      this.MK51.Name = "MK51";
      Label mk51_3 = this.MK51;
      size1 = new Size(9, 9);
      Size size56 = size1;
      mk51_3.Size = size56;
      this.MK51.TabIndex = 553;
      this.MK51.Tag = (object) "0";
      this.MK50.BackColor = Color.Transparent;
      this.MK50.BorderStyle = BorderStyle.Fixed3D;
      this.MK50.Cursor = Cursors.Hand;
      Label mk50_1 = this.MK50;
      point1 = new Point(308, 144);
      Point point57 = point1;
      mk50_1.Location = point57;
      Label mk50_2 = this.MK50;
      padding1 = new Padding(0);
      Padding padding49 = padding1;
      mk50_2.Margin = padding49;
      this.MK50.Name = "MK50";
      Label mk50_3 = this.MK50;
      size1 = new Size(9, 9);
      Size size57 = size1;
      mk50_3.Size = size57;
      this.MK50.TabIndex = 552;
      this.MK50.Tag = (object) "0";
      this.MK49.BackColor = Color.Transparent;
      this.MK49.BorderStyle = BorderStyle.Fixed3D;
      this.MK49.Cursor = Cursors.Hand;
      Label mk49_1 = this.MK49;
      point1 = new Point(300, 144);
      Point point58 = point1;
      mk49_1.Location = point58;
      Label mk49_2 = this.MK49;
      padding1 = new Padding(0);
      Padding padding50 = padding1;
      mk49_2.Margin = padding50;
      this.MK49.Name = "MK49";
      Label mk49_3 = this.MK49;
      size1 = new Size(9, 9);
      Size size58 = size1;
      mk49_3.Size = size58;
      this.MK49.TabIndex = 551;
      this.MK49.Tag = (object) "0";
      this.MK63.BackColor = Color.Transparent;
      this.MK63.BorderStyle = BorderStyle.Fixed3D;
      this.MK63.Cursor = Cursors.Hand;
      Label mk63_1 = this.MK63;
      point1 = new Point(348, 152);
      Point point59 = point1;
      mk63_1.Location = point59;
      Label mk63_2 = this.MK63;
      padding1 = new Padding(0);
      Padding padding51 = padding1;
      mk63_2.Margin = padding51;
      this.MK63.Name = "MK63";
      Label mk63_3 = this.MK63;
      size1 = new Size(9, 9);
      Size size59 = size1;
      mk63_3.Size = size59;
      this.MK63.TabIndex = 564;
      this.MK63.Tag = (object) "0";
      this.MK62.BackColor = Color.Transparent;
      this.MK62.BorderStyle = BorderStyle.Fixed3D;
      this.MK62.Cursor = Cursors.Hand;
      Label mk62_1 = this.MK62;
      point1 = new Point(340, 152);
      Point point60 = point1;
      mk62_1.Location = point60;
      Label mk62_2 = this.MK62;
      padding1 = new Padding(0);
      Padding padding52 = padding1;
      mk62_2.Margin = padding52;
      this.MK62.Name = "MK62";
      Label mk62_3 = this.MK62;
      size1 = new Size(9, 9);
      Size size60 = size1;
      mk62_3.Size = size60;
      this.MK62.TabIndex = 563;
      this.MK62.Tag = (object) "0";
      this.MK61.BackColor = Color.Transparent;
      this.MK61.BorderStyle = BorderStyle.Fixed3D;
      this.MK61.Cursor = Cursors.Hand;
      Label mk61_1 = this.MK61;
      point1 = new Point(332, 152);
      Point point61 = point1;
      mk61_1.Location = point61;
      Label mk61_2 = this.MK61;
      padding1 = new Padding(0);
      Padding padding53 = padding1;
      mk61_2.Margin = padding53;
      this.MK61.Name = "MK61";
      Label mk61_3 = this.MK61;
      size1 = new Size(9, 9);
      Size size61 = size1;
      mk61_3.Size = size61;
      this.MK61.TabIndex = 562;
      this.MK61.Tag = (object) "0";
      this.MK60.BackColor = Color.Transparent;
      this.MK60.BorderStyle = BorderStyle.Fixed3D;
      this.MK60.Cursor = Cursors.Hand;
      Label mk60_1 = this.MK60;
      point1 = new Point(324, 152);
      Point point62 = point1;
      mk60_1.Location = point62;
      Label mk60_2 = this.MK60;
      padding1 = new Padding(0);
      Padding padding54 = padding1;
      mk60_2.Margin = padding54;
      this.MK60.Name = "MK60";
      Label mk60_3 = this.MK60;
      size1 = new Size(9, 9);
      Size size62 = size1;
      mk60_3.Size = size62;
      this.MK60.TabIndex = 561;
      this.MK60.Tag = (object) "0";
      this.MK59.BackColor = Color.Transparent;
      this.MK59.BorderStyle = BorderStyle.Fixed3D;
      this.MK59.Cursor = Cursors.Hand;
      Label mk59_1 = this.MK59;
      point1 = new Point(316, 152);
      Point point63 = point1;
      mk59_1.Location = point63;
      Label mk59_2 = this.MK59;
      padding1 = new Padding(0);
      Padding padding55 = padding1;
      mk59_2.Margin = padding55;
      this.MK59.Name = "MK59";
      Label mk59_3 = this.MK59;
      size1 = new Size(9, 9);
      Size size63 = size1;
      mk59_3.Size = size63;
      this.MK59.TabIndex = 560;
      this.MK59.Tag = (object) "0";
      this.MK58.BackColor = Color.Transparent;
      this.MK58.BorderStyle = BorderStyle.Fixed3D;
      this.MK58.Cursor = Cursors.Hand;
      Label mk58_1 = this.MK58;
      point1 = new Point(308, 152);
      Point point64 = point1;
      mk58_1.Location = point64;
      Label mk58_2 = this.MK58;
      padding1 = new Padding(0);
      Padding padding56 = padding1;
      mk58_2.Margin = padding56;
      this.MK58.Name = "MK58";
      Label mk58_3 = this.MK58;
      size1 = new Size(9, 9);
      Size size64 = size1;
      mk58_3.Size = size64;
      this.MK58.TabIndex = 559;
      this.MK58.Tag = (object) "0";
      this.MK57.BackColor = Color.Transparent;
      this.MK57.BorderStyle = BorderStyle.Fixed3D;
      this.MK57.Cursor = Cursors.Hand;
      Label mk57_1 = this.MK57;
      point1 = new Point(300, 152);
      Point point65 = point1;
      mk57_1.Location = point65;
      Label mk57_2 = this.MK57;
      padding1 = new Padding(0);
      Padding padding57 = padding1;
      mk57_2.Margin = padding57;
      this.MK57.Name = "MK57";
      Label mk57_3 = this.MK57;
      size1 = new Size(9, 9);
      Size size65 = size1;
      mk57_3.Size = size65;
      this.MK57.TabIndex = 558;
      this.MK57.Tag = (object) "0";
      this.MK64.BackColor = Color.Transparent;
      this.MK64.BorderStyle = BorderStyle.Fixed3D;
      this.MK64.Cursor = Cursors.Hand;
      Label mk64_1 = this.MK64;
      point1 = new Point(356, 152);
      Point point66 = point1;
      mk64_1.Location = point66;
      Label mk64_2 = this.MK64;
      padding1 = new Padding(0);
      Padding padding58 = padding1;
      mk64_2.Margin = padding58;
      this.MK64.Name = "MK64";
      Label mk64_3 = this.MK64;
      size1 = new Size(9, 9);
      Size size66 = size1;
      mk64_3.Size = size66;
      this.MK64.TabIndex = 572;
      this.MK64.Tag = (object) "0";
      this.MK56.BackColor = Color.Transparent;
      this.MK56.BorderStyle = BorderStyle.Fixed3D;
      this.MK56.Cursor = Cursors.Hand;
      Label mk56_1 = this.MK56;
      point1 = new Point(356, 144);
      Point point67 = point1;
      mk56_1.Location = point67;
      Label mk56_2 = this.MK56;
      padding1 = new Padding(0);
      Padding padding59 = padding1;
      mk56_2.Margin = padding59;
      this.MK56.Name = "MK56";
      Label mk56_3 = this.MK56;
      size1 = new Size(9, 9);
      Size size67 = size1;
      mk56_3.Size = size67;
      this.MK56.TabIndex = 571;
      this.MK56.Tag = (object) "0";
      this.MK48.BackColor = Color.Transparent;
      this.MK48.BorderStyle = BorderStyle.Fixed3D;
      this.MK48.Cursor = Cursors.Hand;
      Label mk48_1 = this.MK48;
      point1 = new Point(356, 136);
      Point point68 = point1;
      mk48_1.Location = point68;
      Label mk48_2 = this.MK48;
      padding1 = new Padding(0);
      Padding padding60 = padding1;
      mk48_2.Margin = padding60;
      this.MK48.Name = "MK48";
      Label mk48_3 = this.MK48;
      size1 = new Size(9, 9);
      Size size68 = size1;
      mk48_3.Size = size68;
      this.MK48.TabIndex = 570;
      this.MK48.Tag = (object) "0";
      this.MK40.BackColor = Color.Transparent;
      this.MK40.BorderStyle = BorderStyle.Fixed3D;
      this.MK40.Cursor = Cursors.Hand;
      Label mk40_1 = this.MK40;
      point1 = new Point(356, 128);
      Point point69 = point1;
      mk40_1.Location = point69;
      Label mk40_2 = this.MK40;
      padding1 = new Padding(0);
      Padding padding61 = padding1;
      mk40_2.Margin = padding61;
      this.MK40.Name = "MK40";
      Label mk40_3 = this.MK40;
      size1 = new Size(9, 9);
      Size size69 = size1;
      mk40_3.Size = size69;
      this.MK40.TabIndex = 569;
      this.MK40.Tag = (object) "0";
      this.MK32.BackColor = Color.Transparent;
      this.MK32.BorderStyle = BorderStyle.Fixed3D;
      this.MK32.Cursor = Cursors.Hand;
      Label mk32_1 = this.MK32;
      point1 = new Point(356, 120);
      Point point70 = point1;
      mk32_1.Location = point70;
      Label mk32_2 = this.MK32;
      padding1 = new Padding(0);
      Padding padding62 = padding1;
      mk32_2.Margin = padding62;
      this.MK32.Name = "MK32";
      Label mk32_3 = this.MK32;
      size1 = new Size(9, 9);
      Size size70 = size1;
      mk32_3.Size = size70;
      this.MK32.TabIndex = 568;
      this.MK32.Tag = (object) "0";
      this.MK24.BackColor = Color.Transparent;
      this.MK24.BorderStyle = BorderStyle.Fixed3D;
      this.MK24.Cursor = Cursors.Hand;
      Label mk24_1 = this.MK24;
      point1 = new Point(356, 112);
      Point point71 = point1;
      mk24_1.Location = point71;
      Label mk24_2 = this.MK24;
      padding1 = new Padding(0);
      Padding padding63 = padding1;
      mk24_2.Margin = padding63;
      this.MK24.Name = "MK24";
      Label mk24_3 = this.MK24;
      size1 = new Size(9, 9);
      Size size71 = size1;
      mk24_3.Size = size71;
      this.MK24.TabIndex = 567;
      this.MK24.Tag = (object) "0";
      this.MK16.BackColor = Color.Transparent;
      this.MK16.BorderStyle = BorderStyle.Fixed3D;
      this.MK16.Cursor = Cursors.Hand;
      Label mk16_1 = this.MK16;
      point1 = new Point(356, 104);
      Point point72 = point1;
      mk16_1.Location = point72;
      Label mk16_2 = this.MK16;
      padding1 = new Padding(0);
      Padding padding64 = padding1;
      mk16_2.Margin = padding64;
      this.MK16.Name = "MK16";
      Label mk16_3 = this.MK16;
      size1 = new Size(9, 9);
      Size size72 = size1;
      mk16_3.Size = size72;
      this.MK16.TabIndex = 566;
      this.MK16.Tag = (object) "0";
      this.MK8.BackColor = Color.Transparent;
      this.MK8.BorderStyle = BorderStyle.Fixed3D;
      this.MK8.Cursor = Cursors.Hand;
      Label mk8_1 = this.MK8;
      point1 = new Point(356, 96);
      Point point73 = point1;
      mk8_1.Location = point73;
      Label mk8_2 = this.MK8;
      padding1 = new Padding(0);
      Padding padding65 = padding1;
      mk8_2.Margin = padding65;
      this.MK8.Name = "MK8";
      Label mk8_3 = this.MK8;
      size1 = new Size(9, 9);
      Size size73 = size1;
      mk8_3.Size = size73;
      this.MK8.TabIndex = 565;
      this.MK8.Tag = (object) "0";
      this.Integrantes.Cursor = Cursors.Hand;
      this.Integrantes.Enabled = false;
      this.Integrantes.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      ListBox integrantes1 = this.Integrantes;
      point1 = new Point(10, 136);
      Point point74 = point1;
      integrantes1.Location = point74;
      this.Integrantes.Name = "Integrantes";
      ListBox integrantes2 = this.Integrantes;
      size1 = new Size(94, 147);
      Size size74 = size1;
      integrantes2.Size = size74;
      this.Integrantes.TabIndex = 573;
      this.Integrantes.TabStop = false;
      this.Puntos.Enabled = false;
      TextBox puntos1 = this.Puntos;
      point1 = new Point(106, 154);
      Point point75 = point1;
      puntos1.Location = point75;
      this.Puntos.Name = "Puntos";
      TextBox puntos2 = this.Puntos;
      size1 = new Size(64, 20);
      Size size75 = size1;
      puntos2.Size = size75;
      this.Puntos.TabIndex = 575;
      TextBox guildName1 = this.GuildName;
      point1 = new Point(10, 375);
      Point point76 = point1;
      guildName1.Location = point76;
      this.GuildName.Name = "GuildName";
      TextBox guildName2 = this.GuildName;
      size1 = new Size(142, 20);
      Size size76 = size1;
      guildName2.Size = size76;
      this.GuildName.TabIndex = 576;
      this.Tipo.Enabled = false;
      TextBox tipo1 = this.Tipo;
      point1 = new Point(106, 195);
      Point point77 = point1;
      tipo1.Location = point77;
      this.Tipo.Name = "Tipo";
      TextBox tipo2 = this.Tipo;
      size1 = new Size(64, 20);
      Size size77 = size1;
      tipo2.Size = size77;
      this.Tipo.TabIndex = 577;
      this.Tipo.Visible = false;
      this.Noticia.Enabled = false;
      TextBox noticia1 = this.Noticia;
      point1 = new Point(10, 116);
      Point point78 = point1;
      noticia1.Location = point78;
      this.Noticia.MaxLength = 60;
      this.Noticia.Name = "Noticia";
      TextBox noticia2 = this.Noticia;
      size1 = new Size(282, 20);
      Size size78 = size1;
      noticia2.Size = size78;
      this.Noticia.TabIndex = 582;
      this.GL1.AutoSize = true;
      this.GL1.BackColor = Color.Transparent;
      this.GL1.Cursor = Cursors.Hand;
      this.GL1.Enabled = false;
      this.GL1.ForeColor = Color.DarkOrange;
      RadioButton gl1_1 = this.GL1;
      point1 = new Point(106, 220);
      Point point79 = point1;
      gl1_1.Location = point79;
      this.GL1.Name = "GL1";
      RadioButton gl1_2 = this.GL1;
      size1 = new Size(96, 17);
      Size size79 = size1;
      gl1_2.Size = size79;
      this.GL1.TabIndex = 583;
      this.GL1.TabStop = true;
      this.GL1.Text = "Guild Master";
      this.GL1.UseVisualStyleBackColor = false;
      this.GL4.AutoSize = true;
      this.GL4.BackColor = Color.Transparent;
      this.GL4.Cursor = Cursors.Hand;
      this.GL4.Enabled = false;
      this.GL4.ForeColor = Color.DarkOrange;
      RadioButton gl4_1 = this.GL4;
      point1 = new Point(106, 268);
      Point point80 = point1;
      gl4_1.Location = point80;
      this.GL4.Name = "GL4";
      RadioButton gl4_2 = this.GL4;
      size1 = new Size(69, 17);
      Size size80 = size1;
      gl4_2.Size = size80;
      this.GL4.TabIndex = 584;
      this.GL4.TabStop = true;
      this.GL4.Text = "Member";
      this.GL4.UseVisualStyleBackColor = false;
      this.GL3.AutoSize = true;
      this.GL3.BackColor = Color.Transparent;
      this.GL3.Cursor = Cursors.Hand;
      this.GL3.Enabled = false;
      this.GL3.ForeColor = Color.DarkOrange;
      RadioButton gl3_1 = this.GL3;
      point1 = new Point(106, 252);
      Point point81 = point1;
      gl3_1.Location = point81;
      this.GL3.Name = "GL3";
      RadioButton gl3_2 = this.GL3;
      size1 = new Size(100, 17);
      Size size81 = size1;
      gl3_2.Size = size81;
      this.GL3.TabIndex = 585;
      this.GL3.TabStop = true;
      this.GL3.Text = "Battle Master";
      this.GL3.UseVisualStyleBackColor = false;
      this.GL2.AutoSize = true;
      this.GL2.BackColor = Color.Transparent;
      this.GL2.Cursor = Cursors.Hand;
      this.GL2.Enabled = false;
      this.GL2.ForeColor = Color.DarkOrange;
      RadioButton gl2_1 = this.GL2;
      point1 = new Point(106, 236);
      Point point82 = point1;
      gl2_1.Location = point82;
      this.GL2.Name = "GL2";
      RadioButton gl2_2 = this.GL2;
      size1 = new Size(76, 17);
      Size size82 = size1;
      gl2_2.Size = size82;
      this.GL2.TabIndex = 586;
      this.GL2.TabStop = true;
      this.GL2.Text = "Assistant";
      this.GL2.UseVisualStyleBackColor = false;
      this.Label1.AutoSize = true;
      this.Label1.BackColor = Color.Transparent;
      this.Label1.ForeColor = Color.DarkOrange;
      Label label1_1 = this.Label1;
      point1 = new Point(120, 140);
      Point point83 = point1;
      label1_1.Location = point83;
      this.Label1.Name = "Label1";
      Label label1_2 = this.Label1;
      size1 = new Size(40, 13);
      Size size83 = size1;
      label1_2.Size = size83;
      this.Label1.TabIndex = 587;
      this.Label1.Text = "Score";
      this.Label2.AutoSize = true;
      this.Label2.BackColor = Color.Transparent;
      this.Label2.ForeColor = Color.DarkOrange;
      Label label2_1 = this.Label2;
      point1 = new Point(105, 180);
      Point point84 = point1;
      label2_1.Location = point84;
      this.Label2.Name = "Label2";
      Label label2_2 = this.Label2;
      size1 = new Size(68, 13);
      Size size84 = size1;
      label2_2.Size = size84;
      this.Label2.TabIndex = 588;
      this.Label2.Text = "Guild Type";
      this.Label2.Visible = false;
      this.CL1.BackColor = Color.Transparent;
      this.CL1.BorderStyle = BorderStyle.Fixed3D;
      this.CL1.Cursor = Cursors.Hand;
      Label cl1_1 = this.CL1;
      point1 = new Point(245, 331);
      Point point85 = point1;
      cl1_1.Location = point85;
      Label cl1_2 = this.CL1;
      padding1 = new Padding(0);
      Padding padding66 = padding1;
      cl1_2.Margin = padding66;
      this.CL1.Name = "CL1";
      Label cl1_3 = this.CL1;
      size1 = new Size(9, 9);
      Size size85 = size1;
      cl1_3.Size = size85;
      this.CL1.TabIndex = 589;
      this.CL1.Tag = (object) "0";
      this.CL64.BackColor = Color.Transparent;
      this.CL64.BorderStyle = BorderStyle.Fixed3D;
      this.CL64.Cursor = Cursors.Hand;
      Label cl64_1 = this.CL64;
      point1 = new Point(301, 387);
      Point point86 = point1;
      cl64_1.Location = point86;
      Label cl64_2 = this.CL64;
      padding1 = new Padding(0);
      Padding padding67 = padding1;
      cl64_2.Margin = padding67;
      this.CL64.Name = "CL64";
      Label cl64_3 = this.CL64;
      size1 = new Size(9, 9);
      Size size86 = size1;
      cl64_3.Size = size86;
      this.CL64.TabIndex = 652;
      this.CL64.Tag = (object) "0";
      this.CL2.BackColor = Color.Transparent;
      this.CL2.BorderStyle = BorderStyle.Fixed3D;
      this.CL2.Cursor = Cursors.Hand;
      Label cl2_1 = this.CL2;
      point1 = new Point(253, 331);
      Point point87 = point1;
      cl2_1.Location = point87;
      Label cl2_2 = this.CL2;
      padding1 = new Padding(0);
      Padding padding68 = padding1;
      cl2_2.Margin = padding68;
      this.CL2.Name = "CL2";
      Label cl2_3 = this.CL2;
      size1 = new Size(9, 9);
      Size size87 = size1;
      cl2_3.Size = size87;
      this.CL2.TabIndex = 590;
      this.CL2.Tag = (object) "0";
      this.CL56.BackColor = Color.Transparent;
      this.CL56.BorderStyle = BorderStyle.Fixed3D;
      this.CL56.Cursor = Cursors.Hand;
      Label cl56_1 = this.CL56;
      point1 = new Point(301, 379);
      Point point88 = point1;
      cl56_1.Location = point88;
      Label cl56_2 = this.CL56;
      padding1 = new Padding(0);
      Padding padding69 = padding1;
      cl56_2.Margin = padding69;
      this.CL56.Name = "CL56";
      Label cl56_3 = this.CL56;
      size1 = new Size(9, 9);
      Size size88 = size1;
      cl56_3.Size = size88;
      this.CL56.TabIndex = 651;
      this.CL56.Tag = (object) "0";
      this.CL3.BackColor = Color.Transparent;
      this.CL3.BorderStyle = BorderStyle.Fixed3D;
      this.CL3.Cursor = Cursors.Hand;
      Label cl3_1 = this.CL3;
      point1 = new Point(261, 331);
      Point point89 = point1;
      cl3_1.Location = point89;
      Label cl3_2 = this.CL3;
      padding1 = new Padding(0);
      Padding padding70 = padding1;
      cl3_2.Margin = padding70;
      this.CL3.Name = "CL3";
      Label cl3_3 = this.CL3;
      size1 = new Size(9, 9);
      Size size89 = size1;
      cl3_3.Size = size89;
      this.CL3.TabIndex = 591;
      this.CL3.Tag = (object) "0";
      this.CL48.BackColor = Color.Transparent;
      this.CL48.BorderStyle = BorderStyle.Fixed3D;
      this.CL48.Cursor = Cursors.Hand;
      Label cl48_1 = this.CL48;
      point1 = new Point(301, 371);
      Point point90 = point1;
      cl48_1.Location = point90;
      Label cl48_2 = this.CL48;
      padding1 = new Padding(0);
      Padding padding71 = padding1;
      cl48_2.Margin = padding71;
      this.CL48.Name = "CL48";
      Label cl48_3 = this.CL48;
      size1 = new Size(9, 9);
      Size size90 = size1;
      cl48_3.Size = size90;
      this.CL48.TabIndex = 650;
      this.CL48.Tag = (object) "0";
      this.CL4.BackColor = Color.Transparent;
      this.CL4.BorderStyle = BorderStyle.Fixed3D;
      this.CL4.Cursor = Cursors.Hand;
      Label cl4_1 = this.CL4;
      point1 = new Point(269, 331);
      Point point91 = point1;
      cl4_1.Location = point91;
      Label cl4_2 = this.CL4;
      padding1 = new Padding(0);
      Padding padding72 = padding1;
      cl4_2.Margin = padding72;
      this.CL4.Name = "CL4";
      Label cl4_3 = this.CL4;
      size1 = new Size(9, 9);
      Size size91 = size1;
      cl4_3.Size = size91;
      this.CL4.TabIndex = 592;
      this.CL4.Tag = (object) "0";
      this.CL40.BackColor = Color.Transparent;
      this.CL40.BorderStyle = BorderStyle.Fixed3D;
      this.CL40.Cursor = Cursors.Hand;
      Label cl40_1 = this.CL40;
      point1 = new Point(301, 363);
      Point point92 = point1;
      cl40_1.Location = point92;
      Label cl40_2 = this.CL40;
      padding1 = new Padding(0);
      Padding padding73 = padding1;
      cl40_2.Margin = padding73;
      this.CL40.Name = "CL40";
      Label cl40_3 = this.CL40;
      size1 = new Size(9, 9);
      Size size92 = size1;
      cl40_3.Size = size92;
      this.CL40.TabIndex = 649;
      this.CL40.Tag = (object) "0";
      this.CL5.BackColor = Color.Transparent;
      this.CL5.BorderStyle = BorderStyle.Fixed3D;
      this.CL5.Cursor = Cursors.Hand;
      Label cl5_1 = this.CL5;
      point1 = new Point(277, 331);
      Point point93 = point1;
      cl5_1.Location = point93;
      Label cl5_2 = this.CL5;
      padding1 = new Padding(0);
      Padding padding74 = padding1;
      cl5_2.Margin = padding74;
      this.CL5.Name = "CL5";
      Label cl5_3 = this.CL5;
      size1 = new Size(9, 9);
      Size size93 = size1;
      cl5_3.Size = size93;
      this.CL5.TabIndex = 593;
      this.CL5.Tag = (object) "0";
      this.CL32.BackColor = Color.Transparent;
      this.CL32.BorderStyle = BorderStyle.Fixed3D;
      this.CL32.Cursor = Cursors.Hand;
      Label cl32_1 = this.CL32;
      point1 = new Point(301, 355);
      Point point94 = point1;
      cl32_1.Location = point94;
      Label cl32_2 = this.CL32;
      padding1 = new Padding(0);
      Padding padding75 = padding1;
      cl32_2.Margin = padding75;
      this.CL32.Name = "CL32";
      Label cl32_3 = this.CL32;
      size1 = new Size(9, 9);
      Size size94 = size1;
      cl32_3.Size = size94;
      this.CL32.TabIndex = 648;
      this.CL32.Tag = (object) "0";
      this.CL6.BackColor = Color.Transparent;
      this.CL6.BorderStyle = BorderStyle.Fixed3D;
      this.CL6.Cursor = Cursors.Hand;
      Label cl6_1 = this.CL6;
      point1 = new Point(285, 331);
      Point point95 = point1;
      cl6_1.Location = point95;
      Label cl6_2 = this.CL6;
      padding1 = new Padding(0);
      Padding padding76 = padding1;
      cl6_2.Margin = padding76;
      this.CL6.Name = "CL6";
      Label cl6_3 = this.CL6;
      size1 = new Size(9, 9);
      Size size95 = size1;
      cl6_3.Size = size95;
      this.CL6.TabIndex = 594;
      this.CL6.Tag = (object) "0";
      this.CL24.BackColor = Color.Transparent;
      this.CL24.BorderStyle = BorderStyle.Fixed3D;
      this.CL24.Cursor = Cursors.Hand;
      Label cl24_1 = this.CL24;
      point1 = new Point(301, 347);
      Point point96 = point1;
      cl24_1.Location = point96;
      Label cl24_2 = this.CL24;
      padding1 = new Padding(0);
      Padding padding77 = padding1;
      cl24_2.Margin = padding77;
      this.CL24.Name = "CL24";
      Label cl24_3 = this.CL24;
      size1 = new Size(9, 9);
      Size size96 = size1;
      cl24_3.Size = size96;
      this.CL24.TabIndex = 647;
      this.CL24.Tag = (object) "0";
      this.CL7.BackColor = Color.Transparent;
      this.CL7.BorderStyle = BorderStyle.Fixed3D;
      this.CL7.Cursor = Cursors.Hand;
      Label cl7_1 = this.CL7;
      point1 = new Point(293, 331);
      Point point97 = point1;
      cl7_1.Location = point97;
      Label cl7_2 = this.CL7;
      padding1 = new Padding(0);
      Padding padding78 = padding1;
      cl7_2.Margin = padding78;
      this.CL7.Name = "CL7";
      Label cl7_3 = this.CL7;
      size1 = new Size(9, 9);
      Size size97 = size1;
      cl7_3.Size = size97;
      this.CL7.TabIndex = 595;
      this.CL7.Tag = (object) "0";
      this.CL16.BackColor = Color.Transparent;
      this.CL16.BorderStyle = BorderStyle.Fixed3D;
      this.CL16.Cursor = Cursors.Hand;
      Label cl16_1 = this.CL16;
      point1 = new Point(301, 339);
      Point point98 = point1;
      cl16_1.Location = point98;
      Label cl16_2 = this.CL16;
      padding1 = new Padding(0);
      Padding padding79 = padding1;
      cl16_2.Margin = padding79;
      this.CL16.Name = "CL16";
      Label cl16_3 = this.CL16;
      size1 = new Size(9, 9);
      Size size98 = size1;
      cl16_3.Size = size98;
      this.CL16.TabIndex = 646;
      this.CL16.Tag = (object) "0";
      this.CL9.BackColor = Color.Transparent;
      this.CL9.BorderStyle = BorderStyle.Fixed3D;
      this.CL9.Cursor = Cursors.Hand;
      Label cl9_1 = this.CL9;
      point1 = new Point(245, 339);
      Point point99 = point1;
      cl9_1.Location = point99;
      Label cl9_2 = this.CL9;
      padding1 = new Padding(0);
      Padding padding80 = padding1;
      cl9_2.Margin = padding80;
      this.CL9.Name = "CL9";
      Label cl9_3 = this.CL9;
      size1 = new Size(9, 9);
      Size size99 = size1;
      cl9_3.Size = size99;
      this.CL9.TabIndex = 596;
      this.CL9.Tag = (object) "0";
      this.CL8.BackColor = Color.Transparent;
      this.CL8.BorderStyle = BorderStyle.Fixed3D;
      this.CL8.Cursor = Cursors.Hand;
      Label cl8_1 = this.CL8;
      point1 = new Point(301, 331);
      Point point100 = point1;
      cl8_1.Location = point100;
      Label cl8_2 = this.CL8;
      padding1 = new Padding(0);
      Padding padding81 = padding1;
      cl8_2.Margin = padding81;
      this.CL8.Name = "CL8";
      Label cl8_3 = this.CL8;
      size1 = new Size(9, 9);
      Size size100 = size1;
      cl8_3.Size = size100;
      this.CL8.TabIndex = 645;
      this.CL8.Tag = (object) "0";
      this.CL10.BackColor = Color.Transparent;
      this.CL10.BorderStyle = BorderStyle.Fixed3D;
      this.CL10.Cursor = Cursors.Hand;
      Label cl10_1 = this.CL10;
      point1 = new Point(253, 339);
      Point point101 = point1;
      cl10_1.Location = point101;
      Label cl10_2 = this.CL10;
      padding1 = new Padding(0);
      Padding padding82 = padding1;
      cl10_2.Margin = padding82;
      this.CL10.Name = "CL10";
      Label cl10_3 = this.CL10;
      size1 = new Size(9, 9);
      Size size101 = size1;
      cl10_3.Size = size101;
      this.CL10.TabIndex = 597;
      this.CL10.Tag = (object) "0";
      this.CL63.BackColor = Color.Transparent;
      this.CL63.BorderStyle = BorderStyle.Fixed3D;
      this.CL63.Cursor = Cursors.Hand;
      Label cl63_1 = this.CL63;
      point1 = new Point(293, 387);
      Point point102 = point1;
      cl63_1.Location = point102;
      Label cl63_2 = this.CL63;
      padding1 = new Padding(0);
      Padding padding83 = padding1;
      cl63_2.Margin = padding83;
      this.CL63.Name = "CL63";
      Label cl63_3 = this.CL63;
      size1 = new Size(9, 9);
      Size size102 = size1;
      cl63_3.Size = size102;
      this.CL63.TabIndex = 644;
      this.CL63.Tag = (object) "0";
      this.CL11.BackColor = Color.Transparent;
      this.CL11.BorderStyle = BorderStyle.Fixed3D;
      this.CL11.Cursor = Cursors.Hand;
      Label cl11_1 = this.CL11;
      point1 = new Point(261, 339);
      Point point103 = point1;
      cl11_1.Location = point103;
      Label cl11_2 = this.CL11;
      padding1 = new Padding(0);
      Padding padding84 = padding1;
      cl11_2.Margin = padding84;
      this.CL11.Name = "CL11";
      Label cl11_3 = this.CL11;
      size1 = new Size(9, 9);
      Size size103 = size1;
      cl11_3.Size = size103;
      this.CL11.TabIndex = 598;
      this.CL11.Tag = (object) "0";
      this.CL37.BackColor = Color.Transparent;
      this.CL37.BorderStyle = BorderStyle.Fixed3D;
      this.CL37.Cursor = Cursors.Hand;
      Label cl37_1 = this.CL37;
      point1 = new Point(277, 363);
      Point point104 = point1;
      cl37_1.Location = point104;
      Label cl37_2 = this.CL37;
      padding1 = new Padding(0);
      Padding padding85 = padding1;
      cl37_2.Margin = padding85;
      this.CL37.Name = "CL37";
      Label cl37_3 = this.CL37;
      size1 = new Size(9, 9);
      Size size104 = size1;
      cl37_3.Size = size104;
      this.CL37.TabIndex = 621;
      this.CL37.Tag = (object) "0";
      this.CL62.BackColor = Color.Transparent;
      this.CL62.BorderStyle = BorderStyle.Fixed3D;
      this.CL62.Cursor = Cursors.Hand;
      Label cl62_1 = this.CL62;
      point1 = new Point(285, 387);
      Point point105 = point1;
      cl62_1.Location = point105;
      Label cl62_2 = this.CL62;
      padding1 = new Padding(0);
      Padding padding86 = padding1;
      cl62_2.Margin = padding86;
      this.CL62.Name = "CL62";
      Label cl62_3 = this.CL62;
      size1 = new Size(9, 9);
      Size size105 = size1;
      cl62_3.Size = size105;
      this.CL62.TabIndex = 643;
      this.CL62.Tag = (object) "0";
      this.CL36.BackColor = Color.Transparent;
      this.CL36.BorderStyle = BorderStyle.Fixed3D;
      this.CL36.Cursor = Cursors.Hand;
      Label cl36_1 = this.CL36;
      point1 = new Point(269, 363);
      Point point106 = point1;
      cl36_1.Location = point106;
      Label cl36_2 = this.CL36;
      padding1 = new Padding(0);
      Padding padding87 = padding1;
      cl36_2.Margin = padding87;
      this.CL36.Name = "CL36";
      Label cl36_3 = this.CL36;
      size1 = new Size(9, 9);
      Size size106 = size1;
      cl36_3.Size = size106;
      this.CL36.TabIndex = 620;
      this.CL36.Tag = (object) "0";
      this.CL12.BackColor = Color.Transparent;
      this.CL12.BorderStyle = BorderStyle.Fixed3D;
      this.CL12.Cursor = Cursors.Hand;
      Label cl12_1 = this.CL12;
      point1 = new Point(269, 339);
      Point point107 = point1;
      cl12_1.Location = point107;
      Label cl12_2 = this.CL12;
      padding1 = new Padding(0);
      Padding padding88 = padding1;
      cl12_2.Margin = padding88;
      this.CL12.Name = "CL12";
      Label cl12_3 = this.CL12;
      size1 = new Size(9, 9);
      Size size107 = size1;
      cl12_3.Size = size107;
      this.CL12.TabIndex = 599;
      this.CL12.Tag = (object) "0";
      this.CL38.BackColor = Color.Transparent;
      this.CL38.BorderStyle = BorderStyle.Fixed3D;
      this.CL38.Cursor = Cursors.Hand;
      Label cl38_1 = this.CL38;
      point1 = new Point(285, 363);
      Point point108 = point1;
      cl38_1.Location = point108;
      Label cl38_2 = this.CL38;
      padding1 = new Padding(0);
      Padding padding89 = padding1;
      cl38_2.Margin = padding89;
      this.CL38.Name = "CL38";
      Label cl38_3 = this.CL38;
      size1 = new Size(9, 9);
      Size size108 = size1;
      cl38_3.Size = size108;
      this.CL38.TabIndex = 622;
      this.CL38.Tag = (object) "0";
      this.CL61.BackColor = Color.Transparent;
      this.CL61.BorderStyle = BorderStyle.Fixed3D;
      this.CL61.Cursor = Cursors.Hand;
      Label cl61_1 = this.CL61;
      point1 = new Point(277, 387);
      Point point109 = point1;
      cl61_1.Location = point109;
      Label cl61_2 = this.CL61;
      padding1 = new Padding(0);
      Padding padding90 = padding1;
      cl61_2.Margin = padding90;
      this.CL61.Name = "CL61";
      Label cl61_3 = this.CL61;
      size1 = new Size(9, 9);
      Size size109 = size1;
      cl61_3.Size = size109;
      this.CL61.TabIndex = 642;
      this.CL61.Tag = (object) "0";
      this.CL35.BackColor = Color.Transparent;
      this.CL35.BorderStyle = BorderStyle.Fixed3D;
      this.CL35.Cursor = Cursors.Hand;
      Label cl35_1 = this.CL35;
      point1 = new Point(261, 363);
      Point point110 = point1;
      cl35_1.Location = point110;
      Label cl35_2 = this.CL35;
      padding1 = new Padding(0);
      Padding padding91 = padding1;
      cl35_2.Margin = padding91;
      this.CL35.Name = "CL35";
      Label cl35_3 = this.CL35;
      size1 = new Size(9, 9);
      Size size110 = size1;
      cl35_3.Size = size110;
      this.CL35.TabIndex = 619;
      this.CL35.Tag = (object) "0";
      this.CL13.BackColor = Color.Transparent;
      this.CL13.BorderStyle = BorderStyle.Fixed3D;
      this.CL13.Cursor = Cursors.Hand;
      Label cl13_1 = this.CL13;
      point1 = new Point(277, 339);
      Point point111 = point1;
      cl13_1.Location = point111;
      Label cl13_2 = this.CL13;
      padding1 = new Padding(0);
      Padding padding92 = padding1;
      cl13_2.Margin = padding92;
      this.CL13.Name = "CL13";
      Label cl13_3 = this.CL13;
      size1 = new Size(9, 9);
      Size size111 = size1;
      cl13_3.Size = size111;
      this.CL13.TabIndex = 600;
      this.CL13.Tag = (object) "0";
      this.CL39.BackColor = Color.Transparent;
      this.CL39.BorderStyle = BorderStyle.Fixed3D;
      this.CL39.Cursor = Cursors.Hand;
      Label cl39_1 = this.CL39;
      point1 = new Point(293, 363);
      Point point112 = point1;
      cl39_1.Location = point112;
      Label cl39_2 = this.CL39;
      padding1 = new Padding(0);
      Padding padding93 = padding1;
      cl39_2.Margin = padding93;
      this.CL39.Name = "CL39";
      Label cl39_3 = this.CL39;
      size1 = new Size(9, 9);
      Size size112 = size1;
      cl39_3.Size = size112;
      this.CL39.TabIndex = 623;
      this.CL39.Tag = (object) "0";
      this.CL60.BackColor = Color.Transparent;
      this.CL60.BorderStyle = BorderStyle.Fixed3D;
      this.CL60.Cursor = Cursors.Hand;
      Label cl60_1 = this.CL60;
      point1 = new Point(269, 387);
      Point point113 = point1;
      cl60_1.Location = point113;
      Label cl60_2 = this.CL60;
      padding1 = new Padding(0);
      Padding padding94 = padding1;
      cl60_2.Margin = padding94;
      this.CL60.Name = "CL60";
      Label cl60_3 = this.CL60;
      size1 = new Size(9, 9);
      Size size113 = size1;
      cl60_3.Size = size113;
      this.CL60.TabIndex = 641;
      this.CL60.Tag = (object) "0";
      this.CL34.BackColor = Color.Transparent;
      this.CL34.BorderStyle = BorderStyle.Fixed3D;
      this.CL34.Cursor = Cursors.Hand;
      Label cl34_1 = this.CL34;
      point1 = new Point(253, 363);
      Point point114 = point1;
      cl34_1.Location = point114;
      Label cl34_2 = this.CL34;
      padding1 = new Padding(0);
      Padding padding95 = padding1;
      cl34_2.Margin = padding95;
      this.CL34.Name = "CL34";
      Label cl34_3 = this.CL34;
      size1 = new Size(9, 9);
      Size size114 = size1;
      cl34_3.Size = size114;
      this.CL34.TabIndex = 618;
      this.CL34.Tag = (object) "0";
      this.CL14.BackColor = Color.Transparent;
      this.CL14.BorderStyle = BorderStyle.Fixed3D;
      this.CL14.Cursor = Cursors.Hand;
      Label cl14_1 = this.CL14;
      point1 = new Point(285, 339);
      Point point115 = point1;
      cl14_1.Location = point115;
      Label cl14_2 = this.CL14;
      padding1 = new Padding(0);
      Padding padding96 = padding1;
      cl14_2.Margin = padding96;
      this.CL14.Name = "CL14";
      Label cl14_3 = this.CL14;
      size1 = new Size(9, 9);
      Size size115 = size1;
      cl14_3.Size = size115;
      this.CL14.TabIndex = 601;
      this.CL14.Tag = (object) "0";
      this.CL41.BackColor = Color.Transparent;
      this.CL41.BorderStyle = BorderStyle.Fixed3D;
      this.CL41.Cursor = Cursors.Hand;
      Label cl41_1 = this.CL41;
      point1 = new Point(245, 371);
      Point point116 = point1;
      cl41_1.Location = point116;
      Label cl41_2 = this.CL41;
      padding1 = new Padding(0);
      Padding padding97 = padding1;
      cl41_2.Margin = padding97;
      this.CL41.Name = "CL41";
      Label cl41_3 = this.CL41;
      size1 = new Size(9, 9);
      Size size116 = size1;
      cl41_3.Size = size116;
      this.CL41.TabIndex = 624;
      this.CL41.Tag = (object) "0";
      this.CL59.BackColor = Color.Transparent;
      this.CL59.BorderStyle = BorderStyle.Fixed3D;
      this.CL59.Cursor = Cursors.Hand;
      Label cl59_1 = this.CL59;
      point1 = new Point(261, 387);
      Point point117 = point1;
      cl59_1.Location = point117;
      Label cl59_2 = this.CL59;
      padding1 = new Padding(0);
      Padding padding98 = padding1;
      cl59_2.Margin = padding98;
      this.CL59.Name = "CL59";
      Label cl59_3 = this.CL59;
      size1 = new Size(9, 9);
      Size size117 = size1;
      cl59_3.Size = size117;
      this.CL59.TabIndex = 640;
      this.CL59.Tag = (object) "0";
      this.CL33.BackColor = Color.Transparent;
      this.CL33.BorderStyle = BorderStyle.Fixed3D;
      this.CL33.Cursor = Cursors.Hand;
      Label cl33_1 = this.CL33;
      point1 = new Point(245, 363);
      Point point118 = point1;
      cl33_1.Location = point118;
      Label cl33_2 = this.CL33;
      padding1 = new Padding(0);
      Padding padding99 = padding1;
      cl33_2.Margin = padding99;
      this.CL33.Name = "CL33";
      Label cl33_3 = this.CL33;
      size1 = new Size(9, 9);
      Size size118 = size1;
      cl33_3.Size = size118;
      this.CL33.TabIndex = 617;
      this.CL33.Tag = (object) "0";
      this.CL15.BackColor = Color.Transparent;
      this.CL15.BorderStyle = BorderStyle.Fixed3D;
      this.CL15.Cursor = Cursors.Hand;
      Label cl15_1 = this.CL15;
      point1 = new Point(293, 339);
      Point point119 = point1;
      cl15_1.Location = point119;
      Label cl15_2 = this.CL15;
      padding1 = new Padding(0);
      Padding padding100 = padding1;
      cl15_2.Margin = padding100;
      this.CL15.Name = "CL15";
      Label cl15_3 = this.CL15;
      size1 = new Size(9, 9);
      Size size119 = size1;
      cl15_3.Size = size119;
      this.CL15.TabIndex = 602;
      this.CL15.Tag = (object) "0";
      this.CL42.BackColor = Color.Transparent;
      this.CL42.BorderStyle = BorderStyle.Fixed3D;
      this.CL42.Cursor = Cursors.Hand;
      Label cl42_1 = this.CL42;
      point1 = new Point(253, 371);
      Point point120 = point1;
      cl42_1.Location = point120;
      Label cl42_2 = this.CL42;
      padding1 = new Padding(0);
      Padding padding101 = padding1;
      cl42_2.Margin = padding101;
      this.CL42.Name = "CL42";
      Label cl42_3 = this.CL42;
      size1 = new Size(9, 9);
      Size size120 = size1;
      cl42_3.Size = size120;
      this.CL42.TabIndex = 625;
      this.CL42.Tag = (object) "0";
      this.CL58.BackColor = Color.Transparent;
      this.CL58.BorderStyle = BorderStyle.Fixed3D;
      this.CL58.Cursor = Cursors.Hand;
      Label cl58_1 = this.CL58;
      point1 = new Point(253, 387);
      Point point121 = point1;
      cl58_1.Location = point121;
      Label cl58_2 = this.CL58;
      padding1 = new Padding(0);
      Padding padding102 = padding1;
      cl58_2.Margin = padding102;
      this.CL58.Name = "CL58";
      Label cl58_3 = this.CL58;
      size1 = new Size(9, 9);
      Size size121 = size1;
      cl58_3.Size = size121;
      this.CL58.TabIndex = 639;
      this.CL58.Tag = (object) "0";
      this.CL31.BackColor = Color.Transparent;
      this.CL31.BorderStyle = BorderStyle.Fixed3D;
      this.CL31.Cursor = Cursors.Hand;
      Label cl31_1 = this.CL31;
      point1 = new Point(293, 355);
      Point point122 = point1;
      cl31_1.Location = point122;
      Label cl31_2 = this.CL31;
      padding1 = new Padding(0);
      Padding padding103 = padding1;
      cl31_2.Margin = padding103;
      this.CL31.Name = "CL31";
      Label cl31_3 = this.CL31;
      size1 = new Size(9, 9);
      Size size122 = size1;
      cl31_3.Size = size122;
      this.CL31.TabIndex = 616;
      this.CL31.Tag = (object) "0";
      this.CL17.BackColor = Color.Transparent;
      this.CL17.BorderStyle = BorderStyle.Fixed3D;
      this.CL17.Cursor = Cursors.Hand;
      Label cl17_1 = this.CL17;
      point1 = new Point(245, 347);
      Point point123 = point1;
      cl17_1.Location = point123;
      Label cl17_2 = this.CL17;
      padding1 = new Padding(0);
      Padding padding104 = padding1;
      cl17_2.Margin = padding104;
      this.CL17.Name = "CL17";
      Label cl17_3 = this.CL17;
      size1 = new Size(9, 9);
      Size size123 = size1;
      cl17_3.Size = size123;
      this.CL17.TabIndex = 603;
      this.CL17.Tag = (object) "0";
      this.CL43.BackColor = Color.Transparent;
      this.CL43.BorderStyle = BorderStyle.Fixed3D;
      this.CL43.Cursor = Cursors.Hand;
      Label cl43_1 = this.CL43;
      point1 = new Point(261, 371);
      Point point124 = point1;
      cl43_1.Location = point124;
      Label cl43_2 = this.CL43;
      padding1 = new Padding(0);
      Padding padding105 = padding1;
      cl43_2.Margin = padding105;
      this.CL43.Name = "CL43";
      Label cl43_3 = this.CL43;
      size1 = new Size(9, 9);
      Size size124 = size1;
      cl43_3.Size = size124;
      this.CL43.TabIndex = 626;
      this.CL43.Tag = (object) "0";
      this.CL57.BackColor = Color.Transparent;
      this.CL57.BorderStyle = BorderStyle.Fixed3D;
      this.CL57.Cursor = Cursors.Hand;
      Label cl57_1 = this.CL57;
      point1 = new Point(245, 387);
      Point point125 = point1;
      cl57_1.Location = point125;
      Label cl57_2 = this.CL57;
      padding1 = new Padding(0);
      Padding padding106 = padding1;
      cl57_2.Margin = padding106;
      this.CL57.Name = "CL57";
      Label cl57_3 = this.CL57;
      size1 = new Size(9, 9);
      Size size125 = size1;
      cl57_3.Size = size125;
      this.CL57.TabIndex = 638;
      this.CL57.Tag = (object) "0";
      this.CL30.BackColor = Color.Transparent;
      this.CL30.BorderStyle = BorderStyle.Fixed3D;
      this.CL30.Cursor = Cursors.Hand;
      Label cl30_1 = this.CL30;
      point1 = new Point(285, 355);
      Point point126 = point1;
      cl30_1.Location = point126;
      Label cl30_2 = this.CL30;
      padding1 = new Padding(0);
      Padding padding107 = padding1;
      cl30_2.Margin = padding107;
      this.CL30.Name = "CL30";
      Label cl30_3 = this.CL30;
      size1 = new Size(9, 9);
      Size size126 = size1;
      cl30_3.Size = size126;
      this.CL30.TabIndex = 615;
      this.CL30.Tag = (object) "0";
      this.CL18.BackColor = Color.Transparent;
      this.CL18.BorderStyle = BorderStyle.Fixed3D;
      this.CL18.Cursor = Cursors.Hand;
      Label cl18_1 = this.CL18;
      point1 = new Point(253, 347);
      Point point127 = point1;
      cl18_1.Location = point127;
      Label cl18_2 = this.CL18;
      padding1 = new Padding(0);
      Padding padding108 = padding1;
      cl18_2.Margin = padding108;
      this.CL18.Name = "CL18";
      Label cl18_3 = this.CL18;
      size1 = new Size(9, 9);
      Size size127 = size1;
      cl18_3.Size = size127;
      this.CL18.TabIndex = 604;
      this.CL18.Tag = (object) "0";
      this.CL44.BackColor = Color.Transparent;
      this.CL44.BorderStyle = BorderStyle.Fixed3D;
      this.CL44.Cursor = Cursors.Hand;
      Label cl44_1 = this.CL44;
      point1 = new Point(269, 371);
      Point point128 = point1;
      cl44_1.Location = point128;
      Label cl44_2 = this.CL44;
      padding1 = new Padding(0);
      Padding padding109 = padding1;
      cl44_2.Margin = padding109;
      this.CL44.Name = "CL44";
      Label cl44_3 = this.CL44;
      size1 = new Size(9, 9);
      Size size128 = size1;
      cl44_3.Size = size128;
      this.CL44.TabIndex = 627;
      this.CL44.Tag = (object) "0";
      this.CL55.BackColor = Color.Transparent;
      this.CL55.BorderStyle = BorderStyle.Fixed3D;
      this.CL55.Cursor = Cursors.Hand;
      Label cl55_1 = this.CL55;
      point1 = new Point(293, 379);
      Point point129 = point1;
      cl55_1.Location = point129;
      Label cl55_2 = this.CL55;
      padding1 = new Padding(0);
      Padding padding110 = padding1;
      cl55_2.Margin = padding110;
      this.CL55.Name = "CL55";
      Label cl55_3 = this.CL55;
      size1 = new Size(9, 9);
      Size size129 = size1;
      cl55_3.Size = size129;
      this.CL55.TabIndex = 637;
      this.CL55.Tag = (object) "0";
      this.CL29.BackColor = Color.Transparent;
      this.CL29.BorderStyle = BorderStyle.Fixed3D;
      this.CL29.Cursor = Cursors.Hand;
      Label cl29_1 = this.CL29;
      point1 = new Point(277, 355);
      Point point130 = point1;
      cl29_1.Location = point130;
      Label cl29_2 = this.CL29;
      padding1 = new Padding(0);
      Padding padding111 = padding1;
      cl29_2.Margin = padding111;
      this.CL29.Name = "CL29";
      Label cl29_3 = this.CL29;
      size1 = new Size(9, 9);
      Size size130 = size1;
      cl29_3.Size = size130;
      this.CL29.TabIndex = 614;
      this.CL29.Tag = (object) "0";
      this.CL19.BackColor = Color.Transparent;
      this.CL19.BorderStyle = BorderStyle.Fixed3D;
      this.CL19.Cursor = Cursors.Hand;
      Label cl19_1 = this.CL19;
      point1 = new Point(261, 347);
      Point point131 = point1;
      cl19_1.Location = point131;
      Label cl19_2 = this.CL19;
      padding1 = new Padding(0);
      Padding padding112 = padding1;
      cl19_2.Margin = padding112;
      this.CL19.Name = "CL19";
      Label cl19_3 = this.CL19;
      size1 = new Size(9, 9);
      Size size131 = size1;
      cl19_3.Size = size131;
      this.CL19.TabIndex = 605;
      this.CL19.Tag = (object) "0";
      this.CL45.BackColor = Color.Transparent;
      this.CL45.BorderStyle = BorderStyle.Fixed3D;
      this.CL45.Cursor = Cursors.Hand;
      Label cl45_1 = this.CL45;
      point1 = new Point(277, 371);
      Point point132 = point1;
      cl45_1.Location = point132;
      Label cl45_2 = this.CL45;
      padding1 = new Padding(0);
      Padding padding113 = padding1;
      cl45_2.Margin = padding113;
      this.CL45.Name = "CL45";
      Label cl45_3 = this.CL45;
      size1 = new Size(9, 9);
      Size size132 = size1;
      cl45_3.Size = size132;
      this.CL45.TabIndex = 628;
      this.CL45.Tag = (object) "0";
      this.CL54.BackColor = Color.Transparent;
      this.CL54.BorderStyle = BorderStyle.Fixed3D;
      this.CL54.Cursor = Cursors.Hand;
      Label cl54_1 = this.CL54;
      point1 = new Point(285, 379);
      Point point133 = point1;
      cl54_1.Location = point133;
      Label cl54_2 = this.CL54;
      padding1 = new Padding(0);
      Padding padding114 = padding1;
      cl54_2.Margin = padding114;
      this.CL54.Name = "CL54";
      Label cl54_3 = this.CL54;
      size1 = new Size(9, 9);
      Size size133 = size1;
      cl54_3.Size = size133;
      this.CL54.TabIndex = 636;
      this.CL54.Tag = (object) "0";
      this.CL28.BackColor = Color.Transparent;
      this.CL28.BorderStyle = BorderStyle.Fixed3D;
      this.CL28.Cursor = Cursors.Hand;
      Label cl28_1 = this.CL28;
      point1 = new Point(269, 355);
      Point point134 = point1;
      cl28_1.Location = point134;
      Label cl28_2 = this.CL28;
      padding1 = new Padding(0);
      Padding padding115 = padding1;
      cl28_2.Margin = padding115;
      this.CL28.Name = "CL28";
      Label cl28_3 = this.CL28;
      size1 = new Size(9, 9);
      Size size134 = size1;
      cl28_3.Size = size134;
      this.CL28.TabIndex = 613;
      this.CL28.Tag = (object) "0";
      this.CL20.BackColor = Color.Transparent;
      this.CL20.BorderStyle = BorderStyle.Fixed3D;
      this.CL20.Cursor = Cursors.Hand;
      Label cl20_1 = this.CL20;
      point1 = new Point(269, 347);
      Point point135 = point1;
      cl20_1.Location = point135;
      Label cl20_2 = this.CL20;
      padding1 = new Padding(0);
      Padding padding116 = padding1;
      cl20_2.Margin = padding116;
      this.CL20.Name = "CL20";
      Label cl20_3 = this.CL20;
      size1 = new Size(9, 9);
      Size size135 = size1;
      cl20_3.Size = size135;
      this.CL20.TabIndex = 606;
      this.CL20.Tag = (object) "0";
      this.CL46.BackColor = Color.Transparent;
      this.CL46.BorderStyle = BorderStyle.Fixed3D;
      this.CL46.Cursor = Cursors.Hand;
      Label cl46_1 = this.CL46;
      point1 = new Point(285, 371);
      Point point136 = point1;
      cl46_1.Location = point136;
      Label cl46_2 = this.CL46;
      padding1 = new Padding(0);
      Padding padding117 = padding1;
      cl46_2.Margin = padding117;
      this.CL46.Name = "CL46";
      Label cl46_3 = this.CL46;
      size1 = new Size(9, 9);
      Size size136 = size1;
      cl46_3.Size = size136;
      this.CL46.TabIndex = 629;
      this.CL46.Tag = (object) "0";
      this.CL53.BackColor = Color.Transparent;
      this.CL53.BorderStyle = BorderStyle.Fixed3D;
      this.CL53.Cursor = Cursors.Hand;
      Label cl53_1 = this.CL53;
      point1 = new Point(277, 379);
      Point point137 = point1;
      cl53_1.Location = point137;
      Label cl53_2 = this.CL53;
      padding1 = new Padding(0);
      Padding padding118 = padding1;
      cl53_2.Margin = padding118;
      this.CL53.Name = "CL53";
      Label cl53_3 = this.CL53;
      size1 = new Size(9, 9);
      Size size137 = size1;
      cl53_3.Size = size137;
      this.CL53.TabIndex = 635;
      this.CL53.Tag = (object) "0";
      this.CL27.BackColor = Color.Transparent;
      this.CL27.BorderStyle = BorderStyle.Fixed3D;
      this.CL27.Cursor = Cursors.Hand;
      Label cl27_1 = this.CL27;
      point1 = new Point(261, 355);
      Point point138 = point1;
      cl27_1.Location = point138;
      Label cl27_2 = this.CL27;
      padding1 = new Padding(0);
      Padding padding119 = padding1;
      cl27_2.Margin = padding119;
      this.CL27.Name = "CL27";
      Label cl27_3 = this.CL27;
      size1 = new Size(9, 9);
      Size size138 = size1;
      cl27_3.Size = size138;
      this.CL27.TabIndex = 612;
      this.CL27.Tag = (object) "0";
      this.CL21.BackColor = Color.Transparent;
      this.CL21.BorderStyle = BorderStyle.Fixed3D;
      this.CL21.Cursor = Cursors.Hand;
      Label cl21_1 = this.CL21;
      point1 = new Point(277, 347);
      Point point139 = point1;
      cl21_1.Location = point139;
      Label cl21_2 = this.CL21;
      padding1 = new Padding(0);
      Padding padding120 = padding1;
      cl21_2.Margin = padding120;
      this.CL21.Name = "CL21";
      Label cl21_3 = this.CL21;
      size1 = new Size(9, 9);
      Size size139 = size1;
      cl21_3.Size = size139;
      this.CL21.TabIndex = 607;
      this.CL21.Tag = (object) "0";
      this.CL47.BackColor = Color.Transparent;
      this.CL47.BorderStyle = BorderStyle.Fixed3D;
      this.CL47.Cursor = Cursors.Hand;
      Label cl47_1 = this.CL47;
      point1 = new Point(293, 371);
      Point point140 = point1;
      cl47_1.Location = point140;
      Label cl47_2 = this.CL47;
      padding1 = new Padding(0);
      Padding padding121 = padding1;
      cl47_2.Margin = padding121;
      this.CL47.Name = "CL47";
      Label cl47_3 = this.CL47;
      size1 = new Size(9, 9);
      Size size140 = size1;
      cl47_3.Size = size140;
      this.CL47.TabIndex = 630;
      this.CL47.Tag = (object) "0";
      this.CL52.BackColor = Color.Transparent;
      this.CL52.BorderStyle = BorderStyle.Fixed3D;
      this.CL52.Cursor = Cursors.Hand;
      Label cl52_1 = this.CL52;
      point1 = new Point(269, 379);
      Point point141 = point1;
      cl52_1.Location = point141;
      Label cl52_2 = this.CL52;
      padding1 = new Padding(0);
      Padding padding122 = padding1;
      cl52_2.Margin = padding122;
      this.CL52.Name = "CL52";
      Label cl52_3 = this.CL52;
      size1 = new Size(9, 9);
      Size size141 = size1;
      cl52_3.Size = size141;
      this.CL52.TabIndex = 634;
      this.CL52.Tag = (object) "0";
      this.CL26.BackColor = Color.Transparent;
      this.CL26.BorderStyle = BorderStyle.Fixed3D;
      this.CL26.Cursor = Cursors.Hand;
      Label cl26_1 = this.CL26;
      point1 = new Point(253, 355);
      Point point142 = point1;
      cl26_1.Location = point142;
      Label cl26_2 = this.CL26;
      padding1 = new Padding(0);
      Padding padding123 = padding1;
      cl26_2.Margin = padding123;
      this.CL26.Name = "CL26";
      Label cl26_3 = this.CL26;
      size1 = new Size(9, 9);
      Size size142 = size1;
      cl26_3.Size = size142;
      this.CL26.TabIndex = 611;
      this.CL26.Tag = (object) "0";
      this.CL22.BackColor = Color.Transparent;
      this.CL22.BorderStyle = BorderStyle.Fixed3D;
      this.CL22.Cursor = Cursors.Hand;
      Label cl22_1 = this.CL22;
      point1 = new Point(285, 347);
      Point point143 = point1;
      cl22_1.Location = point143;
      Label cl22_2 = this.CL22;
      padding1 = new Padding(0);
      Padding padding124 = padding1;
      cl22_2.Margin = padding124;
      this.CL22.Name = "CL22";
      Label cl22_3 = this.CL22;
      size1 = new Size(9, 9);
      Size size143 = size1;
      cl22_3.Size = size143;
      this.CL22.TabIndex = 608;
      this.CL22.Tag = (object) "0";
      this.CL49.BackColor = Color.Transparent;
      this.CL49.BorderStyle = BorderStyle.Fixed3D;
      this.CL49.Cursor = Cursors.Hand;
      Label cl49_1 = this.CL49;
      point1 = new Point(245, 379);
      Point point144 = point1;
      cl49_1.Location = point144;
      Label cl49_2 = this.CL49;
      padding1 = new Padding(0);
      Padding padding125 = padding1;
      cl49_2.Margin = padding125;
      this.CL49.Name = "CL49";
      Label cl49_3 = this.CL49;
      size1 = new Size(9, 9);
      Size size144 = size1;
      cl49_3.Size = size144;
      this.CL49.TabIndex = 631;
      this.CL49.Tag = (object) "0";
      this.CL51.BackColor = Color.Transparent;
      this.CL51.BorderStyle = BorderStyle.Fixed3D;
      this.CL51.Cursor = Cursors.Hand;
      Label cl51_1 = this.CL51;
      point1 = new Point(261, 379);
      Point point145 = point1;
      cl51_1.Location = point145;
      Label cl51_2 = this.CL51;
      padding1 = new Padding(0);
      Padding padding126 = padding1;
      cl51_2.Margin = padding126;
      this.CL51.Name = "CL51";
      Label cl51_3 = this.CL51;
      size1 = new Size(9, 9);
      Size size145 = size1;
      cl51_3.Size = size145;
      this.CL51.TabIndex = 633;
      this.CL51.Tag = (object) "0";
      this.CL25.BackColor = Color.Transparent;
      this.CL25.BorderStyle = BorderStyle.Fixed3D;
      this.CL25.Cursor = Cursors.Hand;
      Label cl25_1 = this.CL25;
      point1 = new Point(245, 355);
      Point point146 = point1;
      cl25_1.Location = point146;
      Label cl25_2 = this.CL25;
      padding1 = new Padding(0);
      Padding padding127 = padding1;
      cl25_2.Margin = padding127;
      this.CL25.Name = "CL25";
      Label cl25_3 = this.CL25;
      size1 = new Size(9, 9);
      Size size146 = size1;
      cl25_3.Size = size146;
      this.CL25.TabIndex = 610;
      this.CL25.Tag = (object) "0";
      this.CL23.BackColor = Color.Transparent;
      this.CL23.BorderStyle = BorderStyle.Fixed3D;
      this.CL23.Cursor = Cursors.Hand;
      Label cl23_1 = this.CL23;
      point1 = new Point(293, 347);
      Point point147 = point1;
      cl23_1.Location = point147;
      Label cl23_2 = this.CL23;
      padding1 = new Padding(0);
      Padding padding128 = padding1;
      cl23_2.Margin = padding128;
      this.CL23.Name = "CL23";
      Label cl23_3 = this.CL23;
      size1 = new Size(9, 9);
      Size size147 = size1;
      cl23_3.Size = size147;
      this.CL23.TabIndex = 609;
      this.CL23.Tag = (object) "0";
      this.CL50.BackColor = Color.Transparent;
      this.CL50.BorderStyle = BorderStyle.Fixed3D;
      this.CL50.Cursor = Cursors.Hand;
      Label cl50_1 = this.CL50;
      point1 = new Point(253, 379);
      Point point148 = point1;
      cl50_1.Location = point148;
      Label cl50_2 = this.CL50;
      padding1 = new Padding(0);
      Padding padding129 = padding1;
      cl50_2.Margin = padding129;
      this.CL50.Name = "CL50";
      Label cl50_3 = this.CL50;
      size1 = new Size(9, 9);
      Size size148 = size1;
      cl50_3.Size = size148;
      this.CL50.TabIndex = 632;
      this.CL50.Tag = (object) "0";
      this.MasterGuild.Cursor = Cursors.Hand;
      this.MasterGuild.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      this.MasterGuild.ItemHeight = 13;
      ComboBox masterGuild1 = this.MasterGuild;
      point1 = new Point(10, 339);
      Point point149 = point1;
      masterGuild1.Location = point149;
      this.MasterGuild.Name = "MasterGuild";
      ComboBox masterGuild2 = this.MasterGuild;
      size1 = new Size(142, 21);
      Size size149 = size1;
      masterGuild2.Size = size149;
      this.MasterGuild.TabIndex = 653;
      this.MasterGuild.Text = " >> Guild Master << ";
      this.Label67.AutoSize = true;
      this.Label67.BackColor = Color.Transparent;
      this.Label67.ForeColor = Color.DarkOrange;
      Label label67_1 = this.Label67;
      point1 = new Point(50, 325);
      Point point150 = point1;
      label67_1.Location = point150;
      this.Label67.Name = "Label67";
      Label label67_2 = this.Label67;
      size1 = new Size(78, 13);
      Size size150 = size1;
      label67_2.Size = size150;
      this.Label67.TabIndex = 654;
      this.Label67.Text = "Guild Master";
      this.Label68.AutoSize = true;
      this.Label68.BackColor = Color.Transparent;
      this.Label68.ForeColor = Color.DarkOrange;
      Label label68_1 = this.Label68;
      point1 = new Point(42, 362);
      Point point151 = point1;
      label68_1.Location = point151;
      this.Label68.Name = "Label68";
      Label label68_2 = this.Label68;
      size1 = new Size(72, 13);
      Size size151 = size1;
      label68_2.Size = size151;
      this.Label68.TabIndex = 655;
      this.Label68.Text = "Guild Name";
      this.GuildsEnemy.Cursor = Cursors.Hand;
      this.GuildsEnemy.Enabled = false;
      this.GuildsEnemy.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      ListBox guildsEnemy1 = this.GuildsEnemy;
      point1 = new Point(287, 186);
      Point point152 = point1;
      guildsEnemy1.Location = point152;
      this.GuildsEnemy.Name = "GuildsEnemy";
      ListBox guildsEnemy2 = this.GuildsEnemy;
      size1 = new Size(84, 95);
      Size size152 = size1;
      guildsEnemy2.Size = size152;
      this.GuildsEnemy.TabIndex = 657;
      this.GuildsEnemy.TabStop = false;
      this.GuildsFriend.Cursor = Cursors.Hand;
      this.GuildsFriend.Enabled = false;
      this.GuildsFriend.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold);
      ListBox guildsFriend1 = this.GuildsFriend;
      point1 = new Point(203, 186);
      Point point153 = point1;
      guildsFriend1.Location = point153;
      this.GuildsFriend.Name = "GuildsFriend";
      ListBox guildsFriend2 = this.GuildsFriend;
      size1 = new Size(84, 95);
      Size size153 = size1;
      guildsFriend2.Size = size153;
      this.GuildsFriend.TabIndex = 658;
      this.GuildsFriend.TabStop = false;
      this.Label69.AutoSize = true;
      this.Label69.BackColor = Color.Transparent;
      this.Label69.ForeColor = Color.DarkOrange;
      Label label69_1 = this.Label69;
      point1 = new Point(207, 173);
      Point point154 = point1;
      label69_1.Location = point154;
      this.Label69.Name = "Label69";
      Label label69_2 = this.Label69;
      size1 = new Size(75, 13);
      Size size154 = size1;
      label69_2.Size = size154;
      this.Label69.TabIndex = 659;
      this.Label69.Text = "Guild Friend";
      this.Label70.AutoSize = true;
      this.Label70.BackColor = Color.Transparent;
      this.Label70.ForeColor = Color.DarkOrange;
      Label label70_1 = this.Label70;
      point1 = new Point(292, 173);
      Point point155 = point1;
      label70_1.Location = point155;
      this.Label70.Name = "Label70";
      Label label70_2 = this.Label70;
      size1 = new Size(77, 13);
      Size size155 = size1;
      label70_2.Size = size155;
      this.Label70.TabIndex = 660;
      this.Label70.Text = "Guild Enemy";
      this.C1.BackColor = Color.Transparent;
      this.C1.BorderStyle = BorderStyle.Fixed3D;
      this.C1.Cursor = Cursors.Hand;
      Label c1_1 = this.C1;
      point1 = new Point(157, 375);
      Point point156 = point1;
      c1_1.Location = point156;
      this.C1.Name = "C1";
      Label c1_2 = this.C1;
      size1 = new Size(11, 11);
      Size size156 = size1;
      c1_2.Size = size156;
      this.C1.TabIndex = 661;
      this.C1.Tag = (object) "0";
      this.C2.BackColor = Color.Black;
      this.C2.BorderStyle = BorderStyle.Fixed3D;
      this.C2.Cursor = Cursors.Hand;
      Label c2_1 = this.C2;
      point1 = new Point(167, 375);
      Point point157 = point1;
      c2_1.Location = point157;
      this.C2.Name = "C2";
      Label c2_2 = this.C2;
      size1 = new Size(11, 11);
      Size size157 = size1;
      c2_2.Size = size157;
      this.C2.TabIndex = 662;
      this.C2.Tag = (object) "1";
      this.C3.BackColor = Color.DarkGray;
      this.C3.BorderStyle = BorderStyle.Fixed3D;
      this.C3.Cursor = Cursors.Hand;
      Label c3_1 = this.C3;
      point1 = new Point(177, 375);
      Point point158 = point1;
      c3_1.Location = point158;
      this.C3.Name = "C3";
      Label c3_2 = this.C3;
      size1 = new Size(11, 11);
      Size size158 = size1;
      c3_2.Size = size158;
      this.C3.TabIndex = 663;
      this.C3.Tag = (object) "2";
      this.C4.BackColor = Color.White;
      this.C4.BorderStyle = BorderStyle.Fixed3D;
      this.C4.Cursor = Cursors.Hand;
      Label c4_1 = this.C4;
      point1 = new Point(187, 375);
      Point point159 = point1;
      c4_1.Location = point159;
      this.C4.Name = "C4";
      Label c4_2 = this.C4;
      size1 = new Size(11, 11);
      Size size159 = size1;
      c4_2.Size = size159;
      this.C4.TabIndex = 664;
      this.C4.Tag = (object) "3";
      this.C5.BackColor = Color.Red;
      this.C5.BorderStyle = BorderStyle.Fixed3D;
      this.C5.Cursor = Cursors.Hand;
      Label c5_1 = this.C5;
      point1 = new Point(197, 375);
      Point point160 = point1;
      c5_1.Location = point160;
      this.C5.Name = "C5";
      Label c5_2 = this.C5;
      size1 = new Size(11, 11);
      Size size160 = size1;
      c5_2.Size = size160;
      this.C5.TabIndex = 665;
      this.C5.Tag = (object) "4";
      this.C6.BackColor = Color.DarkOrange;
      this.C6.BorderStyle = BorderStyle.Fixed3D;
      this.C6.Cursor = Cursors.Hand;
      Label c6_1 = this.C6;
      point1 = new Point(207, 375);
      Point point161 = point1;
      c6_1.Location = point161;
      this.C6.Name = "C6";
      Label c6_2 = this.C6;
      size1 = new Size(11, 11);
      Size size161 = size1;
      c6_2.Size = size161;
      this.C6.TabIndex = 666;
      this.C6.Tag = (object) "5";
      this.C7.BackColor = Color.Yellow;
      this.C7.BorderStyle = BorderStyle.Fixed3D;
      this.C7.Cursor = Cursors.Hand;
      Label c7_1 = this.C7;
      point1 = new Point(217, 375);
      Point point162 = point1;
      c7_1.Location = point162;
      this.C7.Name = "C7";
      Label c7_2 = this.C7;
      size1 = new Size(11, 11);
      Size size162 = size1;
      c7_2.Size = size162;
      this.C7.TabIndex = 667;
      this.C7.Tag = (object) "6";
      this.C16.BackColor = Color.DeepPink;
      this.C16.BorderStyle = BorderStyle.Fixed3D;
      this.C16.Cursor = Cursors.Hand;
      Label c16_1 = this.C16;
      point1 = new Point(227, 385);
      Point point163 = point1;
      c16_1.Location = point163;
      this.C16.Name = "C16";
      Label c16_2 = this.C16;
      size1 = new Size(11, 11);
      Size size163 = size1;
      c16_2.Size = size163;
      this.C16.TabIndex = 676;
      this.C16.Tag = (object) "F";
      this.C9.BackColor = Color.Lime;
      this.C9.BorderStyle = BorderStyle.Fixed3D;
      this.C9.Cursor = Cursors.Hand;
      Label c9_1 = this.C9;
      point1 = new Point(157, 385);
      Point point164 = point1;
      c9_1.Location = point164;
      this.C9.Name = "C9";
      Label c9_2 = this.C9;
      size1 = new Size(11, 11);
      Size size164 = size1;
      c9_2.Size = size164;
      this.C9.TabIndex = 668;
      this.C9.Tag = (object) "8";
      this.C8.BackColor = Color.YellowGreen;
      this.C8.BorderStyle = BorderStyle.Fixed3D;
      this.C8.Cursor = Cursors.Hand;
      Label c8_1 = this.C8;
      point1 = new Point(227, 375);
      Point point165 = point1;
      c8_1.Location = point165;
      this.C8.Name = "C8";
      Label c8_2 = this.C8;
      size1 = new Size(11, 11);
      Size size165 = size1;
      c8_2.Size = size165;
      this.C8.TabIndex = 675;
      this.C8.Tag = (object) "7";
      this.C10.BackColor = Color.MediumSpringGreen;
      this.C10.BorderStyle = BorderStyle.Fixed3D;
      this.C10.Cursor = Cursors.Hand;
      Label c10_1 = this.C10;
      point1 = new Point(167, 385);
      Point point166 = point1;
      c10_1.Location = point166;
      this.C10.Name = "C10";
      Label c10_2 = this.C10;
      size1 = new Size(11, 11);
      Size size166 = size1;
      c10_2.Size = size166;
      this.C10.TabIndex = 669;
      this.C10.Tag = (object) "9";
      this.C11.BackColor = Color.Aqua;
      this.C11.BorderStyle = BorderStyle.Fixed3D;
      this.C11.Cursor = Cursors.Hand;
      Label c11_1 = this.C11;
      point1 = new Point(177, 385);
      Point point167 = point1;
      c11_1.Location = point167;
      this.C11.Name = "C11";
      Label c11_2 = this.C11;
      size1 = new Size(11, 11);
      Size size167 = size1;
      c11_2.Size = size167;
      this.C11.TabIndex = 670;
      this.C11.Tag = (object) "A";
      this.C12.BackColor = Color.DodgerBlue;
      this.C12.BorderStyle = BorderStyle.Fixed3D;
      this.C12.Cursor = Cursors.Hand;
      Label c12_1 = this.C12;
      point1 = new Point(187, 385);
      Point point168 = point1;
      c12_1.Location = point168;
      this.C12.Name = "C12";
      Label c12_2 = this.C12;
      size1 = new Size(11, 11);
      Size size168 = size1;
      c12_2.Size = size168;
      this.C12.TabIndex = 671;
      this.C12.Tag = (object) "B";
      this.C13.BackColor = Color.Blue;
      this.C13.BorderStyle = BorderStyle.Fixed3D;
      this.C13.Cursor = Cursors.Hand;
      Label c13_1 = this.C13;
      point1 = new Point(197, 385);
      Point point169 = point1;
      c13_1.Location = point169;
      this.C13.Name = "C13";
      Label c13_2 = this.C13;
      size1 = new Size(11, 11);
      Size size169 = size1;
      c13_2.Size = size169;
      this.C13.TabIndex = 672;
      this.C13.Tag = (object) "C";
      this.C14.BackColor = Color.BlueViolet;
      this.C14.BorderStyle = BorderStyle.Fixed3D;
      this.C14.Cursor = Cursors.Hand;
      Label c14_1 = this.C14;
      point1 = new Point(207, 385);
      Point point170 = point1;
      c14_1.Location = point170;
      this.C14.Name = "C14";
      Label c14_2 = this.C14;
      size1 = new Size(11, 11);
      Size size170 = size1;
      c14_2.Size = size170;
      this.C14.TabIndex = 673;
      this.C14.Tag = (object) "D";
      this.C15.BackColor = Color.Violet;
      this.C15.BorderStyle = BorderStyle.Fixed3D;
      this.C15.Cursor = Cursors.Hand;
      Label c15_1 = this.C15;
      point1 = new Point(217, 385);
      Point point171 = point1;
      c15_1.Location = point171;
      this.C15.Name = "C15";
      Label c15_2 = this.C15;
      size1 = new Size(11, 11);
      Size size171 = size1;
      c15_2.Size = size171;
      this.C15.TabIndex = 674;
      this.C15.Tag = (object) "E";
      this.CurrentColor.BackColor = Color.Transparent;
      this.CurrentColor.BorderStyle = BorderStyle.Fixed3D;
      Label currentColor1 = this.CurrentColor;
      point1 = new Point(190, 345);
      Point point172 = point1;
      currentColor1.Location = point172;
      this.CurrentColor.Name = "CurrentColor";
      this.CurrentColor.RightToLeft = RightToLeft.Yes;
      Label currentColor2 = this.CurrentColor;
      size1 = new Size(16, 16);
      Size size172 = size1;
      currentColor2.Size = size172;
      this.CurrentColor.TabIndex = 677;
      this.CurrentColor.Tag = (object) "0";
      this.Label88.AutoSize = true;
      this.Label88.BackColor = Color.Transparent;
      this.Label88.ForeColor = Color.DarkOrange;
      Label label88_1 = this.Label88;
      point1 = new Point(158, 328);
      Point point173 = point1;
      label88_1.Location = point173;
      this.Label88.Name = "Label88";
      Label label88_2 = this.Label88;
      size1 = new Size(81, 13);
      Size size173 = size1;
      label88_2.Size = size173;
      this.Label88.TabIndex = 678;
      this.Label88.Text = "Current Color";
      this.NameGuild.BackColor = Color.Transparent;
      this.NameGuild.Font = new Font("Microsoft Sans Serif", 12f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.NameGuild.ForeColor = Color.Red;
      Label nameGuild1 = this.NameGuild;
      point1 = new Point(10, 90);
      Point point174 = point1;
      nameGuild1.Location = point174;
      this.NameGuild.Name = "NameGuild";
      Label nameGuild2 = this.NameGuild;
      size1 = new Size(141, 22);
      Size size174 = size1;
      nameGuild2.Size = size174;
      this.NameGuild.TabIndex = 679;
      this.NameGuild.TextAlign = ContentAlignment.MiddleCenter;
      this.GuildMaster.BackColor = Color.Transparent;
      this.GuildMaster.Font = new Font("Microsoft Sans Serif", 12f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.GuildMaster.ForeColor = Color.Red;
      Label guildMaster1 = this.GuildMaster;
      point1 = new Point(151, 90);
      Point point175 = point1;
      guildMaster1.Location = point175;
      this.GuildMaster.Name = "GuildMaster";
      Label guildMaster2 = this.GuildMaster;
      size1 = new Size(143, 22);
      Size size175 = size1;
      guildMaster2.Size = size175;
      this.GuildMaster.TabIndex = 680;
      this.GuildMaster.TextAlign = ContentAlignment.MiddleCenter;
      this.Aplicar.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Aplicar.BackgroundImage = (Image) EmbeddedResources.smethod_90();
      this.Aplicar.BackgroundImageLayout = ImageLayout.Center;
      this.Aplicar.Cursor = Cursors.Hand;
      this.Aplicar.Enabled = false;
      this.Aplicar.FlatAppearance.BorderSize = 0;
      this.Aplicar.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.Aplicar.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.Aplicar.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.Aplicar.FlatStyle = FlatStyle.Flat;
      this.Aplicar.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Aplicar.ForeColor = Color.Transparent;
      Button aplicar1 = this.Aplicar;
      point1 = new Point(316, 282);
      Point point176 = point1;
      aplicar1.Location = point176;
      this.Aplicar.Name = "Aplicar";
      Button aplicar2 = this.Aplicar;
      size1 = new Size(54, 30);
      Size size176 = size1;
      aplicar2.Size = size176;
      this.Aplicar.TabIndex = 681;
      this.Aplicar.TabStop = false;
      this.Aplicar.UseVisualStyleBackColor = false;
      this.Reload.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Reload.BackgroundImage = (Image) EmbeddedResources.smethod_100();
      this.Reload.BackgroundImageLayout = ImageLayout.Center;
      this.Reload.Cursor = Cursors.Hand;
      this.Reload.Enabled = false;
      this.Reload.FlatAppearance.BorderSize = 0;
      this.Reload.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.Reload.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.Reload.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.Reload.FlatStyle = FlatStyle.Flat;
      this.Reload.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Reload.ForeColor = Color.Transparent;
      Button reload1 = this.Reload;
      point1 = new Point(250, 140);
      Point point177 = point1;
      reload1.Location = point177;
      this.Reload.Name = "Reload";
      Button reload2 = this.Reload;
      size1 = new Size(41, 31);
      Size size177 = size1;
      reload2.Size = size177;
      this.Reload.TabIndex = 682;
      this.Reload.TabStop = false;
      this.Reload.UseVisualStyleBackColor = false;
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
      point1 = new Point(165, 29);
      Point point178 = point1;
      buscar1.Location = point178;
      this.Buscar.Name = "Buscar";
      Button buscar2 = this.Buscar;
      size1 = new Size(32, 21);
      Size size178 = size1;
      buscar2.Size = size178;
      this.Buscar.TabIndex = 683;
      this.Buscar.TabStop = false;
      this.Buscar.UseVisualStyleBackColor = false;
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
      point1 = new Point(317, 328);
      Point point179 = point1;
      borrarDatos1.Location = point179;
      this.BorrarDatos.Name = "BorrarDatos";
      Button borrarDatos2 = this.BorrarDatos;
      size1 = new Size(52, 28);
      Size size179 = size1;
      borrarDatos2.Size = size179;
      this.BorrarDatos.TabIndex = 685;
      this.BorrarDatos.TabStop = false;
      this.BorrarDatos.UseVisualStyleBackColor = false;
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
      point1 = new Point(354, 6);
      Point point180 = point1;
      cerrar1.Location = point180;
      this.Cerrar.Name = "Cerrar";
      Button cerrar2 = this.Cerrar;
      size1 = new Size(13, 13);
      Size size180 = size1;
      cerrar2.Size = size180;
      this.Cerrar.TabIndex = 1897;
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
      Point point181 = point1;
      minimizar1.Location = point181;
      this.Minimizar.Name = "Minimizar";
      Button minimizar2 = this.Minimizar;
      size1 = new Size(13, 13);
      Size size181 = size1;
      minimizar2.Size = size181;
      this.Minimizar.TabIndex = 1896;
      this.Minimizar.TabStop = false;
      this.Minimizar.UseVisualStyleBackColor = false;
      this.Titulo.AutoSize = true;
      this.Titulo.BackColor = Color.Transparent;
      this.Titulo.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Titulo.ForeColor = Color.DarkOrange;
      Label titulo1 = this.Titulo;
      point1 = new Point(59, 6);
      Point point182 = point1;
      titulo1.Location = point182;
      this.Titulo.Name = "Titulo";
      Label titulo2 = this.Titulo;
      size1 = new Size(0, 13);
      Size size182 = size1;
      titulo2.Size = size182;
      this.Titulo.TabIndex = 1904;
      this.Titulo.TextAlign = ContentAlignment.MiddleLeft;
      this.AutoScaleMode = AutoScaleMode.Inherit;
      this.BackColor = Color.Black;
      // ISSUE: reference to a compiler-generated method
      this.BackgroundImage = (Image) EmbeddedResources.smethod_67();
      size1 = new Size(376, 405);
      this.ClientSize = size1;
      this.Controls.Add((Control) this.Titulo);
      this.Controls.Add((Control) this.Cerrar);
      this.Controls.Add((Control) this.Minimizar);
      this.Controls.Add((Control) this.BorrarDatos);
      this.Controls.Add((Control) this.Buscar);
      this.Controls.Add((Control) this.Reload);
      this.Controls.Add((Control) this.Label88);
      this.Controls.Add((Control) this.CurrentColor);
      this.Controls.Add((Control) this.C1);
      this.Controls.Add((Control) this.C2);
      this.Controls.Add((Control) this.C3);
      this.Controls.Add((Control) this.C4);
      this.Controls.Add((Control) this.C5);
      this.Controls.Add((Control) this.C6);
      this.Controls.Add((Control) this.C7);
      this.Controls.Add((Control) this.C9);
      this.Controls.Add((Control) this.C8);
      this.Controls.Add((Control) this.C10);
      this.Controls.Add((Control) this.C11);
      this.Controls.Add((Control) this.C12);
      this.Controls.Add((Control) this.C13);
      this.Controls.Add((Control) this.C14);
      this.Controls.Add((Control) this.C15);
      this.Controls.Add((Control) this.MasterGuild);
      this.Controls.Add((Control) this.Tipo);
      this.Controls.Add((Control) this.GuildName);
      this.Controls.Add((Control) this.Puntos);
      this.Controls.Add((Control) this.GuildsFriend);
      this.Controls.Add((Control) this.GuildsEnemy);
      this.Controls.Add((Control) this.Label68);
      this.Controls.Add((Control) this.Label67);
      this.Controls.Add((Control) this.Label2);
      this.Controls.Add((Control) this.Label1);
      this.Controls.Add((Control) this.Integrantes);
      this.Controls.Add((Control) this.GL2);
      this.Controls.Add((Control) this.GL3);
      this.Controls.Add((Control) this.GL4);
      this.Controls.Add((Control) this.GL1);
      this.Controls.Add((Control) this.Noticia);
      this.Controls.Add((Control) this.MK64);
      this.Controls.Add((Control) this.MK56);
      this.Controls.Add((Control) this.MK48);
      this.Controls.Add((Control) this.MK40);
      this.Controls.Add((Control) this.MK32);
      this.Controls.Add((Control) this.CreateGuild);
      this.Controls.Add((Control) this.BorrarGuild);
      this.Controls.Add((Control) this.MK24);
      this.Controls.Add((Control) this.Personajes);
      this.Controls.Add((Control) this.Guilds);
      this.Controls.Add((Control) this.MK16);
      this.Controls.Add((Control) this.PersonajeSearch);
      this.Controls.Add((Control) this.GuildSearch);
      this.Controls.Add((Control) this.MK8);
      this.Controls.Add((Control) this.GuildsL);
      this.Controls.Add((Control) this.MK63);
      this.Controls.Add((Control) this.Chart);
      this.Controls.Add((Control) this.MK62);
      this.Controls.Add((Control) this.MK61);
      this.Controls.Add((Control) this.MK60);
      this.Controls.Add((Control) this.MK59);
      this.Controls.Add((Control) this.MK58);
      this.Controls.Add((Control) this.MK57);
      this.Controls.Add((Control) this.MK55);
      this.Controls.Add((Control) this.MK54);
      this.Controls.Add((Control) this.MK53);
      this.Controls.Add((Control) this.MK52);
      this.Controls.Add((Control) this.MK51);
      this.Controls.Add((Control) this.MK50);
      this.Controls.Add((Control) this.Label69);
      this.Controls.Add((Control) this.Label70);
      this.Controls.Add((Control) this.NameGuild);
      this.Controls.Add((Control) this.GuildMaster);
      this.Controls.Add((Control) this.CL64);
      this.Controls.Add((Control) this.CL56);
      this.Controls.Add((Control) this.CL48);
      this.Controls.Add((Control) this.CL40);
      this.Controls.Add((Control) this.CL32);
      this.Controls.Add((Control) this.CL24);
      this.Controls.Add((Control) this.CL16);
      this.Controls.Add((Control) this.CL8);
      this.Controls.Add((Control) this.CL63);
      this.Controls.Add((Control) this.CL62);
      this.Controls.Add((Control) this.CL61);
      this.Controls.Add((Control) this.CL60);
      this.Controls.Add((Control) this.CL59);
      this.Controls.Add((Control) this.CL58);
      this.Controls.Add((Control) this.CL57);
      this.Controls.Add((Control) this.CL55);
      this.Controls.Add((Control) this.CL54);
      this.Controls.Add((Control) this.CL53);
      this.Controls.Add((Control) this.CL47);
      this.Controls.Add((Control) this.CL52);
      this.Controls.Add((Control) this.CL51);
      this.Controls.Add((Control) this.CL50);
      this.Controls.Add((Control) this.C16);
      this.Controls.Add((Control) this.CL49);
      this.Controls.Add((Control) this.CL46);
      this.Controls.Add((Control) this.CL45);
      this.Controls.Add((Control) this.CL44);
      this.Controls.Add((Control) this.CL43);
      this.Controls.Add((Control) this.CL42);
      this.Controls.Add((Control) this.CL41);
      this.Controls.Add((Control) this.CL39);
      this.Controls.Add((Control) this.CL38);
      this.Controls.Add((Control) this.CL37);
      this.Controls.Add((Control) this.CL36);
      this.Controls.Add((Control) this.CL35);
      this.Controls.Add((Control) this.CL34);
      this.Controls.Add((Control) this.CL33);
      this.Controls.Add((Control) this.CL31);
      this.Controls.Add((Control) this.CL30);
      this.Controls.Add((Control) this.CL29);
      this.Controls.Add((Control) this.CL28);
      this.Controls.Add((Control) this.CL27);
      this.Controls.Add((Control) this.CL26);
      this.Controls.Add((Control) this.CL25);
      this.Controls.Add((Control) this.CL23);
      this.Controls.Add((Control) this.CL22);
      this.Controls.Add((Control) this.CL21);
      this.Controls.Add((Control) this.CL20);
      this.Controls.Add((Control) this.CL19);
      this.Controls.Add((Control) this.CL18);
      this.Controls.Add((Control) this.CL17);
      this.Controls.Add((Control) this.CL15);
      this.Controls.Add((Control) this.CL14);
      this.Controls.Add((Control) this.CL13);
      this.Controls.Add((Control) this.CL12);
      this.Controls.Add((Control) this.CL11);
      this.Controls.Add((Control) this.CL10);
      this.Controls.Add((Control) this.CL9);
      this.Controls.Add((Control) this.CL7);
      this.Controls.Add((Control) this.CL6);
      this.Controls.Add((Control) this.CL5);
      this.Controls.Add((Control) this.CL4);
      this.Controls.Add((Control) this.CL3);
      this.Controls.Add((Control) this.CL2);
      this.Controls.Add((Control) this.CL1);
      this.Controls.Add((Control) this.MK49);
      this.Controls.Add((Control) this.MK47);
      this.Controls.Add((Control) this.MK46);
      this.Controls.Add((Control) this.MK45);
      this.Controls.Add((Control) this.MK44);
      this.Controls.Add((Control) this.MK43);
      this.Controls.Add((Control) this.MK42);
      this.Controls.Add((Control) this.MK41);
      this.Controls.Add((Control) this.MK39);
      this.Controls.Add((Control) this.MK38);
      this.Controls.Add((Control) this.MK37);
      this.Controls.Add((Control) this.MK36);
      this.Controls.Add((Control) this.MK35);
      this.Controls.Add((Control) this.MK34);
      this.Controls.Add((Control) this.MK33);
      this.Controls.Add((Control) this.MK31);
      this.Controls.Add((Control) this.MK30);
      this.Controls.Add((Control) this.MK29);
      this.Controls.Add((Control) this.MK28);
      this.Controls.Add((Control) this.MK27);
      this.Controls.Add((Control) this.MK26);
      this.Controls.Add((Control) this.MK25);
      this.Controls.Add((Control) this.MK23);
      this.Controls.Add((Control) this.MK22);
      this.Controls.Add((Control) this.MK21);
      this.Controls.Add((Control) this.MK20);
      this.Controls.Add((Control) this.MK19);
      this.Controls.Add((Control) this.MK18);
      this.Controls.Add((Control) this.MK17);
      this.Controls.Add((Control) this.MK15);
      this.Controls.Add((Control) this.MK14);
      this.Controls.Add((Control) this.MK13);
      this.Controls.Add((Control) this.MK12);
      this.Controls.Add((Control) this.MK11);
      this.Controls.Add((Control) this.MK10);
      this.Controls.Add((Control) this.MK9);
      this.Controls.Add((Control) this.MK7);
      this.Controls.Add((Control) this.MK6);
      this.Controls.Add((Control) this.MK5);
      this.Controls.Add((Control) this.MK4);
      this.Controls.Add((Control) this.MK3);
      this.Controls.Add((Control) this.MK2);
      this.Controls.Add((Control) this.MK1);
      this.Controls.Add((Control) this.Aplicar);
      this.DoubleBuffered = true;
      this.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.FormBorderStyle = FormBorderStyle.None;
      this.Icon = (Icon) componentResourceManager.GetObject("$this.Icon");
      this.MaximizeBox = false;
      size1 = new Size(376, 405);
      this.MaximumSize = size1;
      this.MinimizeBox = false;
      size1 = new Size(376, 405);
      this.MinimumSize = size1;
      this.Name = "GuildMaker";
      this.StartPosition = FormStartPosition.CenterScreen;
      this.Text = "GuildMaker";
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
      this.BorrarGuild.Enabled = true;
      this.Aplicar.Enabled = true;
      this.Reload.Enabled = true;
      this.Puntos.Enabled = true;
      this.Noticia.Enabled = true;
      this.Integrantes.Enabled = true;
      this.GuildsFriend.Enabled = true;
      this.GuildsEnemy.Enabled = true;
      this.Tipo.Enabled = true;
      this.GL1.Enabled = true;
      this.GL2.Enabled = true;
      this.GL3.Enabled = true;
      this.GL4.Enabled = true;
      return (object) true;
    }

    public object ExcepcionesOFF()
    {
      this.BorrarGuild.Enabled = false;
      this.Aplicar.Enabled = false;
      this.Reload.Enabled = false;
      this.Puntos.Enabled = false;
      this.Noticia.Enabled = false;
      this.Integrantes.Enabled = false;
      this.GuildsFriend.Enabled = false;
      this.GuildsEnemy.Enabled = false;
      this.Tipo.Enabled = false;
      this.GL1.Enabled = false;
      this.GL2.Enabled = false;
      this.GL3.Enabled = false;
      this.GL4.Enabled = false;
      return (object) true;
    }

    public object MARCKA(object object_0)
    {
      int Start = 1;
      do
      {
        string str = Strings.Mid(Conversions.ToString(object_0), Start, 1).ToUpper();
        Color color = Color.Transparent;
        string Left = str;
        if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(0), false) != 0)
        {
          if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(1), false) == 0)
            color = Color.Black;
          else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(2), false) == 0)
            color = Color.Gray;
          else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(3), false) == 0)
            color = Color.White;
          else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(4), false) == 0)
            color = Color.Red;
          else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(5), false) == 0)
            color = Color.DarkOrange;
          else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(6), false) == 0)
            color = Color.Yellow;
          else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(7), false) == 0)
            color = Color.YellowGreen;
          else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(8), false) == 0)
            color = Color.Lime;
          else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(9), false) == 0)
            color = Color.MediumSpringGreen;
          else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, "A", false) == 0)
            color = Color.Aqua;
          else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, "B", false) == 0)
            color = Color.DodgerBlue;
          else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, "C", false) == 0)
            color = Color.Blue;
          else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, "D", false) == 0)
            color = Color.BlueViolet;
          else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, "E", false) == 0)
            color = Color.Violet;
          else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, "F", false) == 0)
            color = Color.DeepPink;
        }
        else
          goto label_97;
label_31:
        switch (Start)
        {
          case 1:
            this.MK1.BackColor = color;
            this.MK1.Tag = (object) str;
            break;
          case 2:
            this.MK2.BackColor = color;
            this.MK2.Tag = (object) str;
            break;
          case 3:
            this.MK3.BackColor = color;
            this.MK3.Tag = (object) str;
            break;
          case 4:
            this.MK4.BackColor = color;
            this.MK4.Tag = (object) str;
            break;
          case 5:
            this.MK5.BackColor = color;
            this.MK5.Tag = (object) str;
            break;
          case 6:
            this.MK6.BackColor = color;
            this.MK6.Tag = (object) str;
            break;
          case 7:
            this.MK7.BackColor = color;
            this.MK7.Tag = (object) str;
            break;
          case 8:
            this.MK8.BackColor = color;
            this.MK8.Tag = (object) str;
            break;
          case 9:
            this.MK9.BackColor = color;
            this.MK9.Tag = (object) str;
            break;
          case 10:
            this.MK10.BackColor = color;
            this.MK10.Tag = (object) str;
            break;
          case 11:
            this.MK11.BackColor = color;
            this.MK11.Tag = (object) str;
            break;
          case 12:
            this.MK12.BackColor = color;
            this.MK12.Tag = (object) str;
            break;
          case 13:
            this.MK13.BackColor = color;
            this.MK13.Tag = (object) str;
            break;
          case 14:
            this.MK14.BackColor = color;
            this.MK14.Tag = (object) str;
            break;
          case 15:
            this.MK15.BackColor = color;
            this.MK15.Tag = (object) str;
            break;
          case 16:
            this.MK16.BackColor = color;
            this.MK16.Tag = (object) str;
            break;
          case 17:
            this.MK17.BackColor = color;
            this.MK17.Tag = (object) str;
            break;
          case 18:
            this.MK18.BackColor = color;
            this.MK18.Tag = (object) str;
            break;
          case 19:
            this.MK19.BackColor = color;
            this.MK19.Tag = (object) str;
            break;
          case 20:
            this.MK20.BackColor = color;
            this.MK20.Tag = (object) str;
            break;
          case 21:
            this.MK21.BackColor = color;
            this.MK21.Tag = (object) str;
            break;
          case 22:
            this.MK22.BackColor = color;
            this.MK22.Tag = (object) str;
            break;
          case 23:
            this.MK23.BackColor = color;
            this.MK23.Tag = (object) str;
            break;
          case 24:
            this.MK24.BackColor = color;
            this.MK24.Tag = (object) str;
            break;
          case 25:
            this.MK25.BackColor = color;
            this.MK25.Tag = (object) str;
            break;
          case 26:
            this.MK26.BackColor = color;
            this.MK26.Tag = (object) str;
            break;
          case 27:
            this.MK27.BackColor = color;
            this.MK27.Tag = (object) str;
            break;
          case 28:
            this.MK28.BackColor = color;
            this.MK28.Tag = (object) str;
            break;
          case 29:
            this.MK29.BackColor = color;
            this.MK29.Tag = (object) str;
            break;
          case 30:
            this.MK30.BackColor = color;
            this.MK30.Tag = (object) str;
            break;
          case 31:
            this.MK31.BackColor = color;
            this.MK31.Tag = (object) str;
            break;
          case 32:
            this.MK32.BackColor = color;
            this.MK32.Tag = (object) str;
            break;
          case 33:
            this.MK33.BackColor = color;
            this.MK33.Tag = (object) str;
            break;
          case 34:
            this.MK34.BackColor = color;
            this.MK34.Tag = (object) str;
            break;
          case 35:
            this.MK35.BackColor = color;
            this.MK35.Tag = (object) str;
            break;
          case 36:
            this.MK36.BackColor = color;
            this.MK36.Tag = (object) str;
            break;
          case 37:
            this.MK37.BackColor = color;
            this.MK37.Tag = (object) str;
            break;
          case 38:
            this.MK38.BackColor = color;
            this.MK38.Tag = (object) str;
            break;
          case 39:
            this.MK39.BackColor = color;
            this.MK39.Tag = (object) str;
            break;
          case 40:
            this.MK40.BackColor = color;
            this.MK40.Tag = (object) str;
            break;
          case 41:
            this.MK41.BackColor = color;
            this.MK41.Tag = (object) str;
            break;
          case 42:
            this.MK42.BackColor = color;
            this.MK42.Tag = (object) str;
            break;
          case 43:
            this.MK43.BackColor = color;
            this.MK43.Tag = (object) str;
            break;
          case 44:
            this.MK44.BackColor = color;
            this.MK44.Tag = (object) str;
            break;
          case 45:
            this.MK45.BackColor = color;
            this.MK45.Tag = (object) str;
            break;
          case 46:
            this.MK46.BackColor = color;
            this.MK46.Tag = (object) str;
            break;
          case 47:
            this.MK47.BackColor = color;
            this.MK47.Tag = (object) str;
            break;
          case 48:
            this.MK48.BackColor = color;
            this.MK48.Tag = (object) str;
            break;
          case 49:
            this.MK49.BackColor = color;
            this.MK49.Tag = (object) str;
            break;
          case 50:
            this.MK50.BackColor = color;
            this.MK50.Tag = (object) str;
            break;
          case 51:
            this.MK51.BackColor = color;
            this.MK51.Tag = (object) str;
            break;
          case 52:
            this.MK52.BackColor = color;
            this.MK52.Tag = (object) str;
            break;
          case 53:
            this.MK53.BackColor = color;
            this.MK53.Tag = (object) str;
            break;
          case 54:
            this.MK54.BackColor = color;
            this.MK54.Tag = (object) str;
            break;
          case 55:
            this.MK55.BackColor = color;
            this.MK55.Tag = (object) str;
            break;
          case 56:
            this.MK56.BackColor = color;
            this.MK56.Tag = (object) str;
            break;
          case 57:
            this.MK57.BackColor = color;
            this.MK57.Tag = (object) str;
            break;
          case 58:
            this.MK58.BackColor = color;
            this.MK58.Tag = (object) str;
            break;
          case 59:
            this.MK59.BackColor = color;
            this.MK59.Tag = (object) str;
            break;
          case 60:
            this.MK60.BackColor = color;
            this.MK60.Tag = (object) str;
            break;
          case 61:
            this.MK61.BackColor = color;
            this.MK61.Tag = (object) str;
            break;
          case 62:
            this.MK62.BackColor = color;
            this.MK62.Tag = (object) str;
            break;
          case 63:
            this.MK63.BackColor = color;
            this.MK63.Tag = (object) str;
            break;
          case 64:
            this.MK64.BackColor = color;
            this.MK64.Tag = (object) str;
            break;
        }
        checked { ++Start; }
        continue;
label_97:
        color = Color.Transparent;
        goto label_31;
      }
      while (Start <= 64);
      return (object) true;
    }

    public object MARCK(object object_0)
    {
      string str = "0x0000000000000000000000000000000000000000000000000000000000000000";
      if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(object_0, (object) 0, false))
        str = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "0x", this.MK1.Tag), this.MK2.Tag), this.MK3.Tag), this.MK4.Tag), this.MK5.Tag), this.MK6.Tag), this.MK7.Tag), this.MK8.Tag), this.MK9.Tag), this.MK10.Tag)), this.MK11.Tag), this.MK12.Tag), this.MK13.Tag), this.MK14.Tag), this.MK15.Tag), this.MK16.Tag), this.MK17.Tag), this.MK18.Tag), this.MK19.Tag), this.MK20.Tag)), this.MK21.Tag), this.MK22.Tag), this.MK23.Tag), this.MK24.Tag), this.MK25.Tag), this.MK26.Tag), this.MK27.Tag), this.MK28.Tag), this.MK29.Tag), this.MK30.Tag)), this.MK31.Tag), this.MK32.Tag), this.MK33.Tag), this.MK34.Tag), this.MK35.Tag), this.MK36.Tag), this.MK37.Tag), this.MK38.Tag), this.MK39.Tag), this.MK40.Tag)), this.MK41.Tag), this.MK42.Tag), this.MK43.Tag), this.MK44.Tag), this.MK45.Tag), this.MK46.Tag), this.MK47.Tag), this.MK48.Tag), this.MK49.Tag), this.MK50.Tag)), this.MK51.Tag), this.MK52.Tag), this.MK53.Tag), this.MK54.Tag), this.MK55.Tag), this.MK56.Tag), this.MK57.Tag), this.MK58.Tag), this.MK59.Tag), this.MK60.Tag)), this.MK61.Tag), this.MK62.Tag), this.MK63.Tag), this.MK64.Tag));
      if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(object_0, (object) 1, false))
        str = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "0x", this.CL1.Tag), this.CL2.Tag), this.CL3.Tag), this.CL4.Tag), this.CL5.Tag), this.CL6.Tag), this.CL7.Tag), this.CL8.Tag), this.CL9.Tag), this.CL10.Tag)), this.CL11.Tag), this.CL12.Tag), this.CL13.Tag), this.CL14.Tag), this.CL15.Tag), this.CL16.Tag), this.CL17.Tag), this.CL18.Tag), this.CL19.Tag), this.CL20.Tag)), this.CL21.Tag), this.CL22.Tag), this.CL23.Tag), this.CL24.Tag), this.CL25.Tag), this.CL26.Tag), this.CL27.Tag), this.CL28.Tag), this.CL29.Tag), this.CL30.Tag)), this.CL31.Tag), this.CL32.Tag), this.CL33.Tag), this.CL34.Tag), this.CL35.Tag), this.CL36.Tag), this.CL37.Tag), this.CL38.Tag), this.CL39.Tag), this.CL40.Tag)), this.CL41.Tag), this.CL42.Tag), this.CL43.Tag), this.CL44.Tag), this.CL45.Tag), this.CL46.Tag), this.CL47.Tag), this.CL48.Tag), this.CL49.Tag), this.CL50.Tag)), this.CL51.Tag), this.CL52.Tag), this.CL53.Tag), this.CL54.Tag), this.CL55.Tag), this.CL56.Tag), this.CL57.Tag), this.CL58.Tag), this.CL59.Tag), this.CL60.Tag)), this.CL61.Tag), this.CL62.Tag), this.CL63.Tag), this.CL64.Tag));
      return (object) str;
    }

    public object CargarGuilds()
    {
      this.ExcepcionesOFF();
      ConnectionManager.smethod_0();
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = "SELECT G_Name, G_Master, G_Score, G_Notice FROM Guild ORDER BY Number ASC";
        SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
        this.Guilds.Text = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) " ", LocalizedStrings.object_72), (object) " "));
        this.Personajes.Text = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) " ", LocalizedStrings.object_8), (object) " "));
        this.Noticia.Text = "";
        this.Puntos.Text = "";
        this.Tipo.Text = "";
        this.GL1.Checked = false;
        this.GL2.Checked = false;
        this.GL3.Checked = false;
        this.GL4.Checked = false;
        this.NameGuild.Text = "";
        this.GuildMaster.Text = "";
        this.Integrantes.Items.Clear();
        this.GuildsFriend.Items.Clear();
        this.GuildsEnemy.Items.Clear();
        this.Personajes.Items.Clear();
        this.Guilds.Items.Clear();
        this.GuildsFriend.Items.Add((object) "[ NONE ]");
        this.GuildsEnemy.Items.Add((object) "[ NONE ]");
        while (SqlConnectionPool.sqlDataReader_1.Read())
        {
          this.Guilds.Items.Add((object) SqlConnectionPool.sqlDataReader_1["G_Name"].ToString());
          this.Personajes.Items.Add((object) SqlConnectionPool.sqlDataReader_1["G_Master"].ToString());
          this.GuildsFriend.Items.Add((object) SqlConnectionPool.sqlDataReader_1["G_Name"].ToString());
          this.GuildsEnemy.Items.Add((object) SqlConnectionPool.sqlDataReader_1["G_Name"].ToString());
        }
        SqlConnectionPool.sqlDataReader_1.Close();
        this.GuildsFriend.SelectedIndex = 0;
        this.GuildsEnemy.SelectedIndex = 0;
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
        SqlConnectionPool.sqlCommand_1.CommandText = "SELECT Name FROM Character ORDER BY Name ASC";
        SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
        this.MasterGuild.Items.Clear();
        this.MasterGuild.Items.Add((object) " >> Guild Master << ");
        while (SqlConnectionPool.sqlDataReader_1.Read())
          this.MasterGuild.Items.Add((object) SqlConnectionPool.sqlDataReader_1["Name"].ToString());
        this.MasterGuild.SelectedIndex = 0;
        this.GuildName.Text = "";
        this.CreateGuild.Enabled = false;
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

    public object CargarDatosGuild()
    {
      ConnectionManager.smethod_0();
      SqlConnectionPool.sqlConnection_1.Open();
      SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
      SqlConnectionPool.sqlCommand_1.CommandText = "SELECT G_Name FROM Guild WHERE Number=" + GuildData.CurrentGuild.string_3 + ";";
      SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
      try
      {
        SqlConnectionPool.sqlDataReader_1.Read();
        if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(SqlConnectionPool.sqlDataReader_1["G_Name"].ToString(), "", false) != 0)
          this.GuildsFriend.SelectedItem = (object) SqlConnectionPool.sqlDataReader_1["G_Name"].ToString();
        else
          this.GuildsFriend.SelectedIndex = 0;
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        this.GuildsFriend.SelectedIndex = 0;
        ProjectData.ClearProjectError();
      }
      SqlConnectionPool.sqlDataReader_1.Close();
      ConnectionManager.smethod_5();
      SqlConnectionPool.sqlConnection_1.Open();
      SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
      SqlConnectionPool.sqlCommand_1.CommandText = "SELECT G_Name FROM Guild WHERE Number=" + GuildData.CurrentGuild.string_4 + ";";
      SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
      try
      {
        SqlConnectionPool.sqlDataReader_1.Read();
        if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(SqlConnectionPool.sqlDataReader_1["G_Name"].ToString(), "", false) != 0)
          this.GuildsEnemy.SelectedItem = (object) SqlConnectionPool.sqlDataReader_1["G_Name"].ToString();
        else
          this.GuildsEnemy.SelectedIndex = 0;
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        this.GuildsEnemy.SelectedIndex = 0;
        ProjectData.ClearProjectError();
      }
      SqlConnectionPool.sqlDataReader_1.Close();
      ConnectionManager.smethod_5();
      SqlConnectionPool.sqlConnection_1.Open();
      SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
      SqlConnectionPool.sqlCommand_1.CommandText = "SELECT Name, G_Status FROM GuildMember WHERE G_Name='" + GuildData.CurrentGuild.string_1 + "' ORDER BY G_Status DESC";
      SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
      this.Integrantes.Items.Clear();
      while (SqlConnectionPool.sqlDataReader_1.Read())
        this.Integrantes.Items.Add((object) SqlConnectionPool.sqlDataReader_1["Name"].ToString());
      SqlConnectionPool.sqlDataReader_1.Close();
      ConnectionManager.smethod_5();
      return (object) true;
    }

    public object ResetMK()
    {
      this.MK1.BackColor = Color.Transparent;
      this.MK1.Tag = (object) 0;
      this.MK2.BackColor = Color.Transparent;
      this.MK2.Tag = (object) 0;
      this.MK3.BackColor = Color.Transparent;
      this.MK3.Tag = (object) 0;
      this.MK4.BackColor = Color.Transparent;
      this.MK4.Tag = (object) 0;
      this.MK5.BackColor = Color.Transparent;
      this.MK5.Tag = (object) 0;
      this.MK6.BackColor = Color.Transparent;
      this.MK6.Tag = (object) 0;
      this.MK7.BackColor = Color.Transparent;
      this.MK7.Tag = (object) 0;
      this.MK8.BackColor = Color.Transparent;
      this.MK8.Tag = (object) 0;
      this.MK9.BackColor = Color.Transparent;
      this.MK9.Tag = (object) 0;
      this.MK10.BackColor = Color.Transparent;
      this.MK10.Tag = (object) 0;
      this.MK11.BackColor = Color.Transparent;
      this.MK11.Tag = (object) 0;
      this.MK12.BackColor = Color.Transparent;
      this.MK12.Tag = (object) 0;
      this.MK13.BackColor = Color.Transparent;
      this.MK13.Tag = (object) 0;
      this.MK14.BackColor = Color.Transparent;
      this.MK14.Tag = (object) 0;
      this.MK15.BackColor = Color.Transparent;
      this.MK15.Tag = (object) 0;
      this.MK16.BackColor = Color.Transparent;
      this.MK16.Tag = (object) 0;
      this.MK17.BackColor = Color.Transparent;
      this.MK17.Tag = (object) 0;
      this.MK18.BackColor = Color.Transparent;
      this.MK18.Tag = (object) 0;
      this.MK19.BackColor = Color.Transparent;
      this.MK19.Tag = (object) 0;
      this.MK20.BackColor = Color.Transparent;
      this.MK20.Tag = (object) 0;
      this.MK21.BackColor = Color.Transparent;
      this.MK21.Tag = (object) 0;
      this.MK22.BackColor = Color.Transparent;
      this.MK22.Tag = (object) 0;
      this.MK23.BackColor = Color.Transparent;
      this.MK23.Tag = (object) 0;
      this.MK24.BackColor = Color.Transparent;
      this.MK24.Tag = (object) 0;
      this.MK25.BackColor = Color.Transparent;
      this.MK25.Tag = (object) 0;
      this.MK26.BackColor = Color.Transparent;
      this.MK26.Tag = (object) 0;
      this.MK27.BackColor = Color.Transparent;
      this.MK27.Tag = (object) 0;
      this.MK28.BackColor = Color.Transparent;
      this.MK28.Tag = (object) 0;
      this.MK29.BackColor = Color.Transparent;
      this.MK29.Tag = (object) 0;
      this.MK30.BackColor = Color.Transparent;
      this.MK30.Tag = (object) 0;
      this.MK31.BackColor = Color.Transparent;
      this.MK31.Tag = (object) 0;
      this.MK32.BackColor = Color.Transparent;
      this.MK32.Tag = (object) 0;
      this.MK33.BackColor = Color.Transparent;
      this.MK33.Tag = (object) 0;
      this.MK34.BackColor = Color.Transparent;
      this.MK34.Tag = (object) 0;
      this.MK35.BackColor = Color.Transparent;
      this.MK35.Tag = (object) 0;
      this.MK36.BackColor = Color.Transparent;
      this.MK36.Tag = (object) 0;
      this.MK37.BackColor = Color.Transparent;
      this.MK37.Tag = (object) 0;
      this.MK38.BackColor = Color.Transparent;
      this.MK38.Tag = (object) 0;
      this.MK39.BackColor = Color.Transparent;
      this.MK39.Tag = (object) 0;
      this.MK40.BackColor = Color.Transparent;
      this.MK40.Tag = (object) 0;
      this.MK41.BackColor = Color.Transparent;
      this.MK41.Tag = (object) 0;
      this.MK42.BackColor = Color.Transparent;
      this.MK42.Tag = (object) 0;
      this.MK43.BackColor = Color.Transparent;
      this.MK43.Tag = (object) 0;
      this.MK44.BackColor = Color.Transparent;
      this.MK44.Tag = (object) 0;
      this.MK45.BackColor = Color.Transparent;
      this.MK45.Tag = (object) 0;
      this.MK46.BackColor = Color.Transparent;
      this.MK46.Tag = (object) 0;
      this.MK47.BackColor = Color.Transparent;
      this.MK47.Tag = (object) 0;
      this.MK48.BackColor = Color.Transparent;
      this.MK48.Tag = (object) 0;
      this.MK49.BackColor = Color.Transparent;
      this.MK49.Tag = (object) 0;
      this.MK50.BackColor = Color.Transparent;
      this.MK50.Tag = (object) 0;
      this.MK51.BackColor = Color.Transparent;
      this.MK51.Tag = (object) 0;
      this.MK52.BackColor = Color.Transparent;
      this.MK52.Tag = (object) 0;
      this.MK53.BackColor = Color.Transparent;
      this.MK53.Tag = (object) 0;
      this.MK54.BackColor = Color.Transparent;
      this.MK54.Tag = (object) 0;
      this.MK55.BackColor = Color.Transparent;
      this.MK55.Tag = (object) 0;
      this.MK56.BackColor = Color.Transparent;
      this.MK56.Tag = (object) 0;
      this.MK57.BackColor = Color.Transparent;
      this.MK57.Tag = (object) 0;
      this.MK58.BackColor = Color.Transparent;
      this.MK58.Tag = (object) 0;
      this.MK59.BackColor = Color.Transparent;
      this.MK59.Tag = (object) 0;
      this.MK60.BackColor = Color.Transparent;
      this.MK60.Tag = (object) 0;
      this.MK61.BackColor = Color.Transparent;
      this.MK61.Tag = (object) 0;
      this.MK62.BackColor = Color.Transparent;
      this.MK62.Tag = (object) 0;
      this.MK63.BackColor = Color.Transparent;
      this.MK63.Tag = (object) 0;
      this.MK64.BackColor = Color.Transparent;
      this.MK64.Tag = (object) 0;
      this.CL1.BackColor = Color.Transparent;
      this.CL1.Tag = (object) 0;
      this.CL2.BackColor = Color.Transparent;
      this.CL2.Tag = (object) 0;
      this.CL3.BackColor = Color.Transparent;
      this.CL3.Tag = (object) 0;
      this.CL4.BackColor = Color.Transparent;
      this.CL4.Tag = (object) 0;
      this.CL5.BackColor = Color.Transparent;
      this.CL5.Tag = (object) 0;
      this.CL6.BackColor = Color.Transparent;
      this.CL6.Tag = (object) 0;
      this.CL7.BackColor = Color.Transparent;
      this.CL7.Tag = (object) 0;
      this.CL8.BackColor = Color.Transparent;
      this.CL8.Tag = (object) 0;
      this.CL9.BackColor = Color.Transparent;
      this.CL9.Tag = (object) 0;
      this.CL10.BackColor = Color.Transparent;
      this.CL10.Tag = (object) 0;
      this.CL11.BackColor = Color.Transparent;
      this.CL11.Tag = (object) 0;
      this.CL12.BackColor = Color.Transparent;
      this.CL12.Tag = (object) 0;
      this.CL13.BackColor = Color.Transparent;
      this.CL13.Tag = (object) 0;
      this.CL14.BackColor = Color.Transparent;
      this.CL14.Tag = (object) 0;
      this.CL15.BackColor = Color.Transparent;
      this.CL15.Tag = (object) 0;
      this.CL16.BackColor = Color.Transparent;
      this.CL16.Tag = (object) 0;
      this.CL17.BackColor = Color.Transparent;
      this.CL17.Tag = (object) 0;
      this.CL18.BackColor = Color.Transparent;
      this.CL18.Tag = (object) 0;
      this.CL19.BackColor = Color.Transparent;
      this.CL19.Tag = (object) 0;
      this.CL20.BackColor = Color.Transparent;
      this.CL20.Tag = (object) 0;
      this.CL21.BackColor = Color.Transparent;
      this.CL21.Tag = (object) 0;
      this.CL22.BackColor = Color.Transparent;
      this.CL22.Tag = (object) 0;
      this.CL23.BackColor = Color.Transparent;
      this.CL23.Tag = (object) 0;
      this.CL24.BackColor = Color.Transparent;
      this.CL24.Tag = (object) 0;
      this.CL25.BackColor = Color.Transparent;
      this.CL25.Tag = (object) 0;
      this.CL26.BackColor = Color.Transparent;
      this.CL26.Tag = (object) 0;
      this.CL27.BackColor = Color.Transparent;
      this.CL27.Tag = (object) 0;
      this.CL28.BackColor = Color.Transparent;
      this.CL28.Tag = (object) 0;
      this.CL29.BackColor = Color.Transparent;
      this.CL29.Tag = (object) 0;
      this.CL30.BackColor = Color.Transparent;
      this.CL30.Tag = (object) 0;
      this.CL31.BackColor = Color.Transparent;
      this.CL31.Tag = (object) 0;
      this.CL32.BackColor = Color.Transparent;
      this.CL32.Tag = (object) 0;
      this.CL33.BackColor = Color.Transparent;
      this.CL33.Tag = (object) 0;
      this.CL34.BackColor = Color.Transparent;
      this.CL34.Tag = (object) 0;
      this.CL35.BackColor = Color.Transparent;
      this.CL35.Tag = (object) 0;
      this.CL36.BackColor = Color.Transparent;
      this.CL36.Tag = (object) 0;
      this.CL37.BackColor = Color.Transparent;
      this.CL37.Tag = (object) 0;
      this.CL38.BackColor = Color.Transparent;
      this.CL38.Tag = (object) 0;
      this.CL39.BackColor = Color.Transparent;
      this.CL39.Tag = (object) 0;
      this.CL40.BackColor = Color.Transparent;
      this.CL40.Tag = (object) 0;
      this.CL41.BackColor = Color.Transparent;
      this.CL41.Tag = (object) 0;
      this.CL42.BackColor = Color.Transparent;
      this.CL42.Tag = (object) 0;
      this.CL43.BackColor = Color.Transparent;
      this.CL43.Tag = (object) 0;
      this.CL44.BackColor = Color.Transparent;
      this.CL44.Tag = (object) 0;
      this.CL45.BackColor = Color.Transparent;
      this.CL45.Tag = (object) 0;
      this.CL46.BackColor = Color.Transparent;
      this.CL46.Tag = (object) 0;
      this.CL47.BackColor = Color.Transparent;
      this.CL47.Tag = (object) 0;
      this.CL48.BackColor = Color.Transparent;
      this.CL48.Tag = (object) 0;
      this.CL49.BackColor = Color.Transparent;
      this.CL49.Tag = (object) 0;
      this.CL50.BackColor = Color.Transparent;
      this.CL50.Tag = (object) 0;
      this.CL51.BackColor = Color.Transparent;
      this.CL51.Tag = (object) 0;
      this.CL52.BackColor = Color.Transparent;
      this.CL52.Tag = (object) 0;
      this.CL53.BackColor = Color.Transparent;
      this.CL53.Tag = (object) 0;
      this.CL54.BackColor = Color.Transparent;
      this.CL54.Tag = (object) 0;
      this.CL55.BackColor = Color.Transparent;
      this.CL55.Tag = (object) 0;
      this.CL56.BackColor = Color.Transparent;
      this.CL56.Tag = (object) 0;
      this.CL57.BackColor = Color.Transparent;
      this.CL57.Tag = (object) 0;
      this.CL58.BackColor = Color.Transparent;
      this.CL58.Tag = (object) 0;
      this.CL59.BackColor = Color.Transparent;
      this.CL59.Tag = (object) 0;
      this.CL60.BackColor = Color.Transparent;
      this.CL60.Tag = (object) 0;
      this.CL61.BackColor = Color.Transparent;
      this.CL61.Tag = (object) 0;
      this.CL62.BackColor = Color.Transparent;
      this.CL62.Tag = (object) 0;
      this.CL63.BackColor = Color.Transparent;
      this.CL63.Tag = (object) 0;
      this.CL64.BackColor = Color.Transparent;
      this.CL64.Tag = (object) 0;
      return (object) true;
    }

    public object Traducir()
    {
      this.Guilds.Text = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) " ", LocalizedStrings.object_72), (object) " "));
      this.Personajes.Text = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) " ", LocalizedStrings.object_8), (object) " "));
      this.Text = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) (this.Text + " - "), Configuration.object_18));
      this.Titulo.Text = this.Text;
      return (object) true;
    }

    private void GuildMaker_Load(object sender, EventArgs e)
    {
      VentanaBarraLoad.DefInstance.Show();
      IniHelper.smethod_47();
      VentanaBarraLoad.DefInstance.Carga.Value = 10;
      VentanaBarraLoad.DefInstance.Carga.Value = 40;
      this.CargarGuilds();
      VentanaBarraLoad.DefInstance.Carga.Value = 60;
      this.Traducir();
      VentanaBarraLoad.DefInstance.Carga.Value = 80;
      StoredProceduresManager.smethod_3();
      VentanaBarraLoad.DefInstance.Carga.Value = 100;
      VentanaBarraLoad.DefInstance.Hide();
      this.Buscar.Focus();
      this.Buscar.Select();
    }

    private void Guilds_SelectedIndexChanged(object sender, EventArgs e)
    {
      this.Personajes.SelectedIndex = this.Guilds.SelectedIndex;
      this.ExcepcionesON();
    }

    private void Personajes_SelectedIndexChanged(object sender, EventArgs e)
    {
      this.Guilds.SelectedIndex = this.Personajes.SelectedIndex;
      this.NameGuild.Text = Conversions.ToString(this.Guilds.SelectedItem);
      this.GuildMaster.Text = Conversions.ToString(this.Personajes.SelectedItem);
      GuildData.CurrentGuild.string_1 = Conversions.ToString(this.Guilds.SelectedItem);
      GuildData.CurrentGuild.string_0 = Conversions.ToString(this.Personajes.SelectedItem);
      DatabaseOperations.smethod_10();
      if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(GuildData.CurrentGuild.string_1, "No Guild", false) == 0)
        this.ExcepcionesOFF();
      this.NameGuild.Text = GuildData.CurrentGuild.string_1;
      this.MARCKA((object) GuildData.CurrentGuild.string_2);
      this.Noticia.Text = GuildData.CurrentGuild.string_5;
      this.Puntos.Text = GuildData.CurrentGuild.string_6;
      this.CargarDatosGuild();
      this.Buscar.Focus();
      this.Buscar.Select();
    }

    private void Integrantes_SelectedIndexChanged(object sender, EventArgs e)
    {
      ConnectionManager.smethod_0();
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "SELECT G_Status FROM GuildMember WHERE Name='", this.Integrantes.SelectedItem), (object) "'"));
        SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
        while (SqlConnectionPool.sqlDataReader_1.Read())
        {
          if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(SqlConnectionPool.sqlDataReader_1["G_Status"], (object) 128, false))
            this.GL1.Select();
          if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(SqlConnectionPool.sqlDataReader_1["G_Status"], (object) 64, false))
            this.GL2.Select();
          if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(SqlConnectionPool.sqlDataReader_1["G_Status"], (object) 32, false))
            this.GL3.Select();
          if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(SqlConnectionPool.sqlDataReader_1["G_Status"], (object) 0, false))
            this.GL4.Select();
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
    }

    private void MasterGuild_SelectedIndexChanged(object sender, EventArgs e)
    {
      this.CreateGuild.Enabled = true;
    }

    private void method_0(object sender, EventArgs e)
    {
      GuildMaker.DefInstance.WindowState = FormWindowState.Minimized;
    }

    private void method_1(object sender, EventArgs e)
    {
      this.Close();
    }

    private void method_2(object sender, EventArgs e)
    {
      this.Guilds.SelectedIndex = this.Personajes.SelectedIndex;
      this.NameGuild.Text = Conversions.ToString(this.Guilds.SelectedItem);
      this.GuildMaster.Text = Conversions.ToString(this.Personajes.SelectedItem);
      GuildData.CurrentGuild.string_1 = Conversions.ToString(this.Guilds.SelectedItem);
      GuildData.CurrentGuild.string_0 = Conversions.ToString(this.Personajes.SelectedItem);
      DatabaseOperations.smethod_10();
      if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(GuildData.CurrentGuild.string_1, "No Guild", false) == 0)
        this.ExcepcionesOFF();
      this.NameGuild.Text = GuildData.CurrentGuild.string_1;
      this.MARCKA((object) GuildData.CurrentGuild.string_2);
      this.Noticia.Text = GuildData.CurrentGuild.string_5;
      this.Puntos.Text = GuildData.CurrentGuild.string_6;
      this.CargarDatosGuild();
      this.Buscar.Focus();
      this.Buscar.Select();
    }

    private void method_3(object sender, EventArgs e)
    {
      int num1 = 0;
      ConnectionManager.smethod_0();
      int num2;
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = "UPDATE Guild SET G_Notice='" + this.Noticia.Text + "', G_Score='" + this.Puntos.Text + "' WHERE G_Name = '" + this.NameGuild.Text + "'";
        SqlConnectionPool.sqlCommand_1.ExecuteReader();
        num2 = checked (num1 + 1);
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        Exception exception = ex;
        int num3 = checked (num1 - 1);
        int num4 = (int) Interaction.MsgBox((object) exception.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
        return;
      }
      int num5;
      try
      {
        GuildAllianceManager.smethod_0();
        GuildAllianceManager.smethod_1();
        num5 = checked (num2 + 1);
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        Exception exception = ex;
        num5 = checked (num2 - 1);
        int num3 = (int) Interaction.MsgBox((object) exception.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      string str = Conversions.ToString(this.MARCK((object) 0));
      ConnectionManager.smethod_5();
      SqlConnectionPool.sqlConnection_1.Open();
      StoredProceduresManager.smethod_13((object) str);
      int num6;
      try
      {
        SqlCommand sqlCommand1 = new SqlCommand();
        SqlCommand sqlCommand2 = new SqlCommand("MMK_GuildMaker", SqlConnectionPool.sqlConnection_1);
        sqlCommand2.CommandType = CommandType.StoredProcedure;
        sqlCommand2.Parameters.Add(new SqlParameter("@Name", SqlDbType.VarChar, 10)
        {
          Direction = ParameterDirection.Input
        });
        sqlCommand2.Parameters["@Name"].Value = (object) this.NameGuild.Text;
        sqlCommand2.ExecuteNonQuery();
        sqlCommand2.Dispose();
        sqlCommand1.Dispose();
        num6 = checked (num5 + 1);
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        Exception exception = ex;
        num6 = checked (num5 - 1);
        int num3 = (int) Interaction.MsgBox((object) exception.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
      if (num6 == 1)
      {
        int num7 = (int) Interaction.MsgBox((object) "!! MARK ERROR !!", MsgBoxStyle.OkOnly, (object) null);
      }
      if (num6 != 2)
        return;
      int num8 = (int) Interaction.MsgBox((object) "!! ALL OK !!", MsgBoxStyle.OkOnly, (object) null);
      this.ResetMK();
      this.CargarGuilds();
    }

    private void method_4(object sender, EventArgs e)
    {
      int num1 = 0;
      int num2 = 0;
      if (this.GuildName.Text.Length <= 0)
      {
        int num3 = (int) Interaction.MsgBox((object) "!!NEED ONE GUILD NAME!!", MsgBoxStyle.OkOnly, (object) "!!GuildMaker!!");
      }
      else
      {
        this.MARCK((object) 1);
        ConnectionManager.smethod_0();
        try
        {
          SqlConnectionPool.sqlConnection_1.Open();
          SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
          SqlConnectionPool.sqlCommand_1.CommandText = "SELECT G_Name FROM Guild;";
          SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
          while (SqlConnectionPool.sqlDataReader_1.Read())
          {
            if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(SqlConnectionPool.sqlDataReader_1["G_Name"].ToString().ToUpper(), this.GuildName.Text.ToUpper(), false) == 0)
              num1 = 1;
          }
          SqlConnectionPool.sqlDataReader_1.Close();
        }
        catch (Exception ex)
        {
          ProjectData.SetProjectError(ex);
          int num4 = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
          num1 = 1;
          ProjectData.ClearProjectError();
        }
        ConnectionManager.smethod_5();
        if (num1 != 1)
        {
          ConnectionManager.smethod_0();
          SqlConnectionPool.sqlConnection_1.Open();
          int num4;
          try
          {
            SqlCommand sqlCommand1 = new SqlCommand();
            SqlCommand sqlCommand2 = new SqlCommand("WZ_GuildCreate", SqlConnectionPool.sqlConnection_1);
            sqlCommand2.CommandType = CommandType.StoredProcedure;
            sqlCommand2.Parameters.Add(new SqlParameter("@GuildName", SqlDbType.VarChar, 8)
            {
              Direction = ParameterDirection.Input
            });
            sqlCommand2.Parameters.Add(new SqlParameter("@MasterName", SqlDbType.VarChar, 10)
            {
              Direction = ParameterDirection.Input
            });
            sqlCommand2.Parameters["@GuildName"].Value = (object) this.GuildName.Text;
            sqlCommand2.Parameters["@MasterName"].Value = (object) this.MasterGuild.Text;
            sqlCommand2.ExecuteNonQuery();
            sqlCommand2.Dispose();
            sqlCommand1.Dispose();
            SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
            SqlConnectionPool.sqlCommand_1.CommandText = "UPDATE GuildMember SET G_Status=128 WHERE Name = '" + this.MasterGuild.Text + "'";
            SqlConnectionPool.sqlCommand_1.ExecuteReader();
            num4 = checked (num2 + 1);
          }
          catch (Exception ex)
          {
            ProjectData.SetProjectError(ex);
            int num5 = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
            ProjectData.ClearProjectError();
            return;
          }
          ConnectionManager.smethod_5();
          if (num1 != 1)
          {
            ConnectionManager.smethod_0();
            SqlConnectionPool.sqlConnection_1.Open();
            StoredProceduresManager.smethod_13((object) Conversions.ToString(this.MARCK((object) 1)));
            try
            {
              SqlCommand sqlCommand1 = new SqlCommand();
              SqlCommand sqlCommand2 = new SqlCommand("MMK_GuildMaker", SqlConnectionPool.sqlConnection_1);
              sqlCommand2.CommandType = CommandType.StoredProcedure;
              sqlCommand2.Parameters.Add(new SqlParameter("@Name", SqlDbType.VarChar, 10)
              {
                Direction = ParameterDirection.Input
              });
              sqlCommand2.Parameters["@Name"].Value = (object) this.GuildName.Text;
              sqlCommand2.ExecuteNonQuery();
              sqlCommand2.Dispose();
              sqlCommand1.Dispose();
              checked { ++num4; }
            }
            catch (Exception ex)
            {
              ProjectData.SetProjectError(ex);
              Exception exception = ex;
              checked { --num4; }
              int num5 = (int) Interaction.MsgBox((object) exception.Message, MsgBoxStyle.OkOnly, (object) null);
              ProjectData.ClearProjectError();
            }
            ConnectionManager.smethod_5();
          }
          if (num4 == 1)
          {
            int num6 = (int) Interaction.MsgBox((object) "!! MARK ERROR !!", MsgBoxStyle.OkOnly, (object) null);
          }
          if (num4 != 2)
            return;
          int num7 = (int) Interaction.MsgBox((object) "!! ALL OK !!", MsgBoxStyle.OkOnly, (object) null);
          this.ResetMK();
          this.CargarGuilds();
        }
        else
        {
          int num8 = (int) Interaction.MsgBox((object) "Guild Name Already Exist\nUse Other Guild Name", MsgBoxStyle.OkOnly, (object) null);
        }
      }
    }

    private void method_5(object sender, EventArgs e)
    {
      if (!Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual((object) Interaction.MsgBox((object) "!!!!! Delete This Guild !!!!!", MsgBoxStyle.YesNo, (object) "!!DELETE GUILD!!"), (object) MsgBoxResult.Yes, false))
        return;
      ConnectionManager.smethod_0();
      SqlConnectionPool.sqlConnection_1.Open();
      try
      {
        SqlCommand sqlCommand1 = new SqlCommand();
        SqlCommand sqlCommand2 = new SqlCommand("WZ_SetGuildDelete", SqlConnectionPool.sqlConnection_1);
        sqlCommand2.CommandType = CommandType.StoredProcedure;
        sqlCommand2.Parameters.Add(new SqlParameter("@GuildName", SqlDbType.VarChar, 10)
        {
          Direction = ParameterDirection.Input
        });
        sqlCommand2.Parameters["@GuildName"].Value = (object) GuildData.CurrentGuild.string_1;
        sqlCommand2.ExecuteNonQuery();
        sqlCommand2.Dispose();
        sqlCommand1.Dispose();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
        return;
      }
      ConnectionManager.smethod_5();
      this.ResetMK();
      this.CargarGuilds();
    }

    private void method_6(object sender, EventArgs e)
    {
    }

    private void method_7(object sender, KeyPressEventArgs e)
    {
      if ((int) IniHelper.smethod_19(checked ((short) Strings.Asc(e.KeyChar))) != 0)
        return;
      e.Handled = true;
    }

    private void method_8(object sender, EventArgs e)
    {
      if (this.Puntos.Text.Length > 0)
        return;
      this.Puntos.Text = Conversions.ToString(0);
    }

    private void Noticia_LostFocus(object sender, EventArgs e)
    {
      if (this.Noticia.Text.Length > 0)
        return;
      this.Noticia.Text = " ";
    }

    private void GL1_CheckedChanged(object sender, EventArgs e)
    {
      try
      {
        ConnectionManager.smethod_0();
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "UPDATE GuildMember SET G_Status=128 WHERE Name = '", this.Integrantes.SelectedItem), (object) "'"));
        SqlConnectionPool.sqlCommand_1.ExecuteReader();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
    }

    private void GL2_CheckedChanged(object sender, EventArgs e)
    {
      try
      {
        ConnectionManager.smethod_0();
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "UPDATE GuildMember SET G_Status=64 WHERE Name = '", this.Integrantes.SelectedItem), (object) "'"));
        SqlConnectionPool.sqlCommand_1.ExecuteReader();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
    }

    private void GL3_CheckedChanged(object sender, EventArgs e)
    {
      try
      {
        ConnectionManager.smethod_0();
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "UPDATE GuildMember SET G_Status=32 WHERE Name = '", this.Integrantes.SelectedItem), (object) "'"));
        SqlConnectionPool.sqlCommand_1.ExecuteReader();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
    }

    private void GL4_CheckedChanged(object sender, EventArgs e)
    {
      try
      {
        ConnectionManager.smethod_0();
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "UPDATE GuildMember SET G_Status=0 WHERE Name = '", this.Integrantes.SelectedItem), (object) "'"));
        SqlConnectionPool.sqlCommand_1.ExecuteReader();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
    }

    private void GuildsEnemy_SelectedIndexChanged(object sender, EventArgs e)
    {
      GuildData.CurrentGuild.string_8 = Conversions.ToString(this.GuildsEnemy.SelectedItem);
    }

    private void GuildsFriend_SelectedIndexChanged(object sender, EventArgs e)
    {
      GuildData.CurrentGuild.string_7 = Conversions.ToString(this.GuildsFriend.SelectedItem);
    }

    private void method_9(object sender, EventArgs e)
    {
      if (this.GuildSearch.Text.Length > 0)
        this.Guilds.SelectedItem = (object) this.GuildSearch.Text;
      if (this.PersonajeSearch.Text.Length <= 0)
        return;
      ConnectionManager.smethod_0();
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = "SELECT G_Name FROM Guild WHERE G_Master='" + this.PersonajeSearch.Text + "'";
        SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
        while (SqlConnectionPool.sqlDataReader_1.Read())
          this.GuildSearch.Text = SqlConnectionPool.sqlDataReader_1[0].ToString();
        SqlConnectionPool.sqlDataReader_1.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
      this.Guilds.SelectedItem = (object) this.GuildSearch.Text;
      this.Personajes.SelectedItem = (object) this.PersonajeSearch.Text;
    }

    private void C16_Click(object sender, EventArgs e)
    {
      this.CurrentColor.BackColor = this.C16.BackColor;
      this.CurrentColor.Tag = RuntimeHelpers.GetObjectValue(this.C16.Tag);
    }

    private void C15_Click(object sender, EventArgs e)
    {
      this.CurrentColor.BackColor = this.C15.BackColor;
      this.CurrentColor.Tag = RuntimeHelpers.GetObjectValue(this.C15.Tag);
    }

    private void C14_Click(object sender, EventArgs e)
    {
      this.CurrentColor.BackColor = this.C14.BackColor;
      this.CurrentColor.Tag = RuntimeHelpers.GetObjectValue(this.C14.Tag);
    }

    private void C13_Click(object sender, EventArgs e)
    {
      this.CurrentColor.BackColor = this.C13.BackColor;
      this.CurrentColor.Tag = RuntimeHelpers.GetObjectValue(this.C13.Tag);
    }

    private void C12_Click(object sender, EventArgs e)
    {
      this.CurrentColor.BackColor = this.C12.BackColor;
      this.CurrentColor.Tag = RuntimeHelpers.GetObjectValue(this.C12.Tag);
    }

    private void C11_Click(object sender, EventArgs e)
    {
      this.CurrentColor.BackColor = this.C11.BackColor;
      this.CurrentColor.Tag = RuntimeHelpers.GetObjectValue(this.C11.Tag);
    }

    private void C10_Click(object sender, EventArgs e)
    {
      this.CurrentColor.BackColor = this.C10.BackColor;
      this.CurrentColor.Tag = RuntimeHelpers.GetObjectValue(this.C10.Tag);
    }

    private void C9_Click(object sender, EventArgs e)
    {
      this.CurrentColor.BackColor = this.C9.BackColor;
      this.CurrentColor.Tag = RuntimeHelpers.GetObjectValue(this.C9.Tag);
    }

    private void C8_Click(object sender, EventArgs e)
    {
      this.CurrentColor.BackColor = this.C8.BackColor;
      this.CurrentColor.Tag = RuntimeHelpers.GetObjectValue(this.C8.Tag);
    }

    private void C7_Click(object sender, EventArgs e)
    {
      this.CurrentColor.BackColor = this.C7.BackColor;
      this.CurrentColor.Tag = RuntimeHelpers.GetObjectValue(this.C7.Tag);
    }

    private void C6_Click(object sender, EventArgs e)
    {
      this.CurrentColor.BackColor = this.C6.BackColor;
      this.CurrentColor.Tag = RuntimeHelpers.GetObjectValue(this.C6.Tag);
    }

    private void C5_Click(object sender, EventArgs e)
    {
      this.CurrentColor.BackColor = this.C5.BackColor;
      this.CurrentColor.Tag = RuntimeHelpers.GetObjectValue(this.C5.Tag);
    }

    private void C4_Click(object sender, EventArgs e)
    {
      this.CurrentColor.BackColor = this.C4.BackColor;
      this.CurrentColor.Tag = RuntimeHelpers.GetObjectValue(this.C4.Tag);
    }

    private void C3_Click(object sender, EventArgs e)
    {
      this.CurrentColor.BackColor = this.C3.BackColor;
      this.CurrentColor.Tag = RuntimeHelpers.GetObjectValue(this.C3.Tag);
    }

    private void C2_Click(object sender, EventArgs e)
    {
      this.CurrentColor.BackColor = this.C2.BackColor;
      this.CurrentColor.Tag = RuntimeHelpers.GetObjectValue(this.C2.Tag);
    }

    private void C1_Click(object sender, EventArgs e)
    {
      this.CurrentColor.BackColor = this.C1.BackColor;
      this.CurrentColor.Tag = RuntimeHelpers.GetObjectValue(this.C1.Tag);
    }

    private void MK1_Click(object sender, EventArgs e)
    {
      this.MK1.BackColor = this.CurrentColor.BackColor;
      this.MK1.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK2_Click(object sender, EventArgs e)
    {
      this.MK2.BackColor = this.CurrentColor.BackColor;
      this.MK2.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK3_Click(object sender, EventArgs e)
    {
      this.MK3.BackColor = this.CurrentColor.BackColor;
      this.MK3.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK4_Click(object sender, EventArgs e)
    {
      this.MK4.BackColor = this.CurrentColor.BackColor;
      this.MK4.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK5_Click(object sender, EventArgs e)
    {
      this.MK5.BackColor = this.CurrentColor.BackColor;
      this.MK5.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK6_Click(object sender, EventArgs e)
    {
      this.MK6.BackColor = this.CurrentColor.BackColor;
      this.MK6.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK7_Click(object sender, EventArgs e)
    {
      this.MK7.BackColor = this.CurrentColor.BackColor;
      this.MK7.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK9_Click(object sender, EventArgs e)
    {
      this.MK9.BackColor = this.CurrentColor.BackColor;
      this.MK9.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK10_Click(object sender, EventArgs e)
    {
      this.MK10.BackColor = this.CurrentColor.BackColor;
      this.MK10.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK11_Click(object sender, EventArgs e)
    {
      this.MK11.BackColor = this.CurrentColor.BackColor;
      this.MK11.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK12_Click(object sender, EventArgs e)
    {
      this.MK12.BackColor = this.CurrentColor.BackColor;
      this.MK12.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK13_Click(object sender, EventArgs e)
    {
      this.MK13.BackColor = this.CurrentColor.BackColor;
      this.MK13.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK14_Click(object sender, EventArgs e)
    {
      this.MK14.BackColor = this.CurrentColor.BackColor;
      this.MK14.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK15_Click(object sender, EventArgs e)
    {
      this.MK15.BackColor = this.CurrentColor.BackColor;
      this.MK15.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK17_Click(object sender, EventArgs e)
    {
      this.MK17.BackColor = this.CurrentColor.BackColor;
      this.MK17.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK18_Click(object sender, EventArgs e)
    {
      this.MK18.BackColor = this.CurrentColor.BackColor;
      this.MK18.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK19_Click(object sender, EventArgs e)
    {
      this.MK19.BackColor = this.CurrentColor.BackColor;
      this.MK19.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK20_Click(object sender, EventArgs e)
    {
      this.MK20.BackColor = this.CurrentColor.BackColor;
      this.MK20.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK21_Click(object sender, EventArgs e)
    {
      this.MK21.BackColor = this.CurrentColor.BackColor;
      this.MK21.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK22_Click(object sender, EventArgs e)
    {
      this.MK22.BackColor = this.CurrentColor.BackColor;
      this.MK22.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK23_Click(object sender, EventArgs e)
    {
      this.MK23.BackColor = this.CurrentColor.BackColor;
      this.MK23.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK25_Click(object sender, EventArgs e)
    {
      this.MK25.BackColor = this.CurrentColor.BackColor;
      this.MK25.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK26_Click(object sender, EventArgs e)
    {
      this.MK26.BackColor = this.CurrentColor.BackColor;
      this.MK26.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK27_Click(object sender, EventArgs e)
    {
      this.MK27.BackColor = this.CurrentColor.BackColor;
      this.MK27.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK28_Click(object sender, EventArgs e)
    {
      this.MK28.BackColor = this.CurrentColor.BackColor;
      this.MK28.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK29_Click(object sender, EventArgs e)
    {
      this.MK29.BackColor = this.CurrentColor.BackColor;
      this.MK29.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK30_Click(object sender, EventArgs e)
    {
      this.MK30.BackColor = this.CurrentColor.BackColor;
      this.MK30.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK31_Click(object sender, EventArgs e)
    {
      this.MK31.BackColor = this.CurrentColor.BackColor;
      this.MK31.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK33_Click(object sender, EventArgs e)
    {
      this.MK33.BackColor = this.CurrentColor.BackColor;
      this.MK33.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK34_Click(object sender, EventArgs e)
    {
      this.MK34.BackColor = this.CurrentColor.BackColor;
      this.MK34.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK35_Click(object sender, EventArgs e)
    {
      this.MK35.BackColor = this.CurrentColor.BackColor;
      this.MK35.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK36_Click(object sender, EventArgs e)
    {
      this.MK36.BackColor = this.CurrentColor.BackColor;
      this.MK36.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK37_Click(object sender, EventArgs e)
    {
      this.MK37.BackColor = this.CurrentColor.BackColor;
      this.MK37.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK38_Click(object sender, EventArgs e)
    {
      this.MK38.BackColor = this.CurrentColor.BackColor;
      this.MK38.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK39_Click(object sender, EventArgs e)
    {
      this.MK39.BackColor = this.CurrentColor.BackColor;
      this.MK39.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK41_Click(object sender, EventArgs e)
    {
      this.MK41.BackColor = this.CurrentColor.BackColor;
      this.MK41.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK42_Click(object sender, EventArgs e)
    {
      this.MK42.BackColor = this.CurrentColor.BackColor;
      this.MK42.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK43_Click(object sender, EventArgs e)
    {
      this.MK43.BackColor = this.CurrentColor.BackColor;
      this.MK43.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK44_Click(object sender, EventArgs e)
    {
      this.MK44.BackColor = this.CurrentColor.BackColor;
      this.MK44.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK45_Click(object sender, EventArgs e)
    {
      this.MK45.BackColor = this.CurrentColor.BackColor;
      this.MK45.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK46_Click(object sender, EventArgs e)
    {
      this.MK46.BackColor = this.CurrentColor.BackColor;
      this.MK46.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK47_Click(object sender, EventArgs e)
    {
      this.MK47.BackColor = this.CurrentColor.BackColor;
      this.MK47.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK49_Click(object sender, EventArgs e)
    {
      this.MK49.BackColor = this.CurrentColor.BackColor;
      this.MK49.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK50_Click(object sender, EventArgs e)
    {
      this.MK50.BackColor = this.CurrentColor.BackColor;
      this.MK50.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK51_Click(object sender, EventArgs e)
    {
      this.MK51.BackColor = this.CurrentColor.BackColor;
      this.MK51.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK52_Click(object sender, EventArgs e)
    {
      this.MK52.BackColor = this.CurrentColor.BackColor;
      this.MK52.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK53_Click(object sender, EventArgs e)
    {
      this.MK53.BackColor = this.CurrentColor.BackColor;
      this.MK53.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK54_Click(object sender, EventArgs e)
    {
      this.MK54.BackColor = this.CurrentColor.BackColor;
      this.MK54.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK55_Click(object sender, EventArgs e)
    {
      this.MK55.BackColor = this.CurrentColor.BackColor;
      this.MK55.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK57_Click(object sender, EventArgs e)
    {
      this.MK57.BackColor = this.CurrentColor.BackColor;
      this.MK57.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK58_Click(object sender, EventArgs e)
    {
      this.MK58.BackColor = this.CurrentColor.BackColor;
      this.MK58.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK59_Click(object sender, EventArgs e)
    {
      this.MK59.BackColor = this.CurrentColor.BackColor;
      this.MK59.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK60_Click(object sender, EventArgs e)
    {
      this.MK60.BackColor = this.CurrentColor.BackColor;
      this.MK60.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK61_Click(object sender, EventArgs e)
    {
      this.MK61.BackColor = this.CurrentColor.BackColor;
      this.MK61.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK62_Click(object sender, EventArgs e)
    {
      this.MK62.BackColor = this.CurrentColor.BackColor;
      this.MK62.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK63_Click(object sender, EventArgs e)
    {
      this.MK63.BackColor = this.CurrentColor.BackColor;
      this.MK63.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK8_Click(object sender, EventArgs e)
    {
      this.MK8.BackColor = this.CurrentColor.BackColor;
      this.MK8.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK16_Click(object sender, EventArgs e)
    {
      this.MK16.BackColor = this.CurrentColor.BackColor;
      this.MK16.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK24_Click(object sender, EventArgs e)
    {
      this.MK24.BackColor = this.CurrentColor.BackColor;
      this.MK24.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK32_Click(object sender, EventArgs e)
    {
      this.MK32.BackColor = this.CurrentColor.BackColor;
      this.MK32.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK40_Click(object sender, EventArgs e)
    {
      this.MK40.BackColor = this.CurrentColor.BackColor;
      this.MK40.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK48_Click(object sender, EventArgs e)
    {
      this.MK48.BackColor = this.CurrentColor.BackColor;
      this.MK48.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK56_Click(object sender, EventArgs e)
    {
      this.MK56.BackColor = this.CurrentColor.BackColor;
      this.MK56.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void MK64_Click(object sender, EventArgs e)
    {
      this.MK64.BackColor = this.CurrentColor.BackColor;
      this.MK64.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL1_Click(object sender, EventArgs e)
    {
      this.CL1.BackColor = this.CurrentColor.BackColor;
      this.CL1.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL2_Click(object sender, EventArgs e)
    {
      this.CL2.BackColor = this.CurrentColor.BackColor;
      this.CL2.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL3_Click(object sender, EventArgs e)
    {
      this.CL3.BackColor = this.CurrentColor.BackColor;
      this.CL3.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL4_Click(object sender, EventArgs e)
    {
      this.CL4.BackColor = this.CurrentColor.BackColor;
      this.CL4.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL5_Click(object sender, EventArgs e)
    {
      this.CL5.BackColor = this.CurrentColor.BackColor;
      this.CL5.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL6_Click(object sender, EventArgs e)
    {
      this.CL6.BackColor = this.CurrentColor.BackColor;
      this.CL6.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL7_Click(object sender, EventArgs e)
    {
      this.CL7.BackColor = this.CurrentColor.BackColor;
      this.CL7.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL9_Click(object sender, EventArgs e)
    {
      this.CL9.BackColor = this.CurrentColor.BackColor;
      this.CL9.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL10_Click(object sender, EventArgs e)
    {
      this.CL10.BackColor = this.CurrentColor.BackColor;
      this.CL10.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL11_Click(object sender, EventArgs e)
    {
      this.CL11.BackColor = this.CurrentColor.BackColor;
      this.CL11.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL12_Click(object sender, EventArgs e)
    {
      this.CL12.BackColor = this.CurrentColor.BackColor;
      this.CL12.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL13_Click(object sender, EventArgs e)
    {
      this.CL13.BackColor = this.CurrentColor.BackColor;
      this.CL13.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL14_Click(object sender, EventArgs e)
    {
      this.CL14.BackColor = this.CurrentColor.BackColor;
      this.CL14.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL15_Click(object sender, EventArgs e)
    {
      this.CL15.BackColor = this.CurrentColor.BackColor;
      this.CL15.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL17_Click(object sender, EventArgs e)
    {
      this.CL17.BackColor = this.CurrentColor.BackColor;
      this.CL17.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL18_Click(object sender, EventArgs e)
    {
      this.CL18.BackColor = this.CurrentColor.BackColor;
      this.CL18.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL19_Click(object sender, EventArgs e)
    {
      this.CL19.BackColor = this.CurrentColor.BackColor;
      this.CL19.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL20_Click(object sender, EventArgs e)
    {
      this.CL20.BackColor = this.CurrentColor.BackColor;
      this.CL20.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL21_Click(object sender, EventArgs e)
    {
      this.CL21.BackColor = this.CurrentColor.BackColor;
      this.CL21.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL22_Click(object sender, EventArgs e)
    {
      this.CL22.BackColor = this.CurrentColor.BackColor;
      this.CL22.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL23_Click(object sender, EventArgs e)
    {
      this.CL23.BackColor = this.CurrentColor.BackColor;
      this.CL23.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL25_Click(object sender, EventArgs e)
    {
      this.CL25.BackColor = this.CurrentColor.BackColor;
      this.CL25.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL26_Click(object sender, EventArgs e)
    {
      this.CL26.BackColor = this.CurrentColor.BackColor;
      this.CL26.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL27_Click(object sender, EventArgs e)
    {
      this.CL27.BackColor = this.CurrentColor.BackColor;
      this.CL27.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL28_Click(object sender, EventArgs e)
    {
      this.CL28.BackColor = this.CurrentColor.BackColor;
      this.CL28.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL29_Click(object sender, EventArgs e)
    {
      this.CL29.BackColor = this.CurrentColor.BackColor;
      this.CL29.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL30_Click(object sender, EventArgs e)
    {
      this.CL30.BackColor = this.CurrentColor.BackColor;
      this.CL30.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL31_Click(object sender, EventArgs e)
    {
      this.CL31.BackColor = this.CurrentColor.BackColor;
      this.CL31.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL33_Click(object sender, EventArgs e)
    {
      this.CL33.BackColor = this.CurrentColor.BackColor;
      this.CL33.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL34_Click(object sender, EventArgs e)
    {
      this.CL34.BackColor = this.CurrentColor.BackColor;
      this.CL34.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL35_Click(object sender, EventArgs e)
    {
      this.CL35.BackColor = this.CurrentColor.BackColor;
      this.CL35.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL36_Click(object sender, EventArgs e)
    {
      this.CL36.BackColor = this.CurrentColor.BackColor;
      this.CL36.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL37_Click(object sender, EventArgs e)
    {
      this.CL37.BackColor = this.CurrentColor.BackColor;
      this.CL37.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL38_Click(object sender, EventArgs e)
    {
      this.CL38.BackColor = this.CurrentColor.BackColor;
      this.CL38.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL39_Click(object sender, EventArgs e)
    {
      this.CL39.BackColor = this.CurrentColor.BackColor;
      this.CL39.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL41_Click(object sender, EventArgs e)
    {
      this.CL41.BackColor = this.CurrentColor.BackColor;
      this.CL41.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL42_Click(object sender, EventArgs e)
    {
      this.CL42.BackColor = this.CurrentColor.BackColor;
      this.CL42.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL43_Click(object sender, EventArgs e)
    {
      this.CL43.BackColor = this.CurrentColor.BackColor;
      this.CL43.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL44_Click(object sender, EventArgs e)
    {
      this.CL44.BackColor = this.CurrentColor.BackColor;
      this.CL44.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL45_Click(object sender, EventArgs e)
    {
      this.CL45.BackColor = this.CurrentColor.BackColor;
      this.CL45.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL46_Click(object sender, EventArgs e)
    {
      this.CL46.BackColor = this.CurrentColor.BackColor;
      this.CL46.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL49_Click(object sender, EventArgs e)
    {
      this.CL49.BackColor = this.CurrentColor.BackColor;
      this.CL49.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL50_Click(object sender, EventArgs e)
    {
      this.CL50.BackColor = this.CurrentColor.BackColor;
      this.CL50.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL51_Click(object sender, EventArgs e)
    {
      this.CL51.BackColor = this.CurrentColor.BackColor;
      this.CL51.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL52_Click(object sender, EventArgs e)
    {
      this.CL52.BackColor = this.CurrentColor.BackColor;
      this.CL52.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL47_Click(object sender, EventArgs e)
    {
      this.CL47.BackColor = this.CurrentColor.BackColor;
      this.CL47.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL53_Click(object sender, EventArgs e)
    {
      this.CL53.BackColor = this.CurrentColor.BackColor;
      this.CL53.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL54_Click(object sender, EventArgs e)
    {
      this.CL54.BackColor = this.CurrentColor.BackColor;
      this.CL54.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL55_Click(object sender, EventArgs e)
    {
      this.CL55.BackColor = this.CurrentColor.BackColor;
      this.CL55.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL57_Click(object sender, EventArgs e)
    {
      this.CL57.BackColor = this.CurrentColor.BackColor;
      this.CL57.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL58_Click(object sender, EventArgs e)
    {
      this.CL58.BackColor = this.CurrentColor.BackColor;
      this.CL58.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL59_Click(object sender, EventArgs e)
    {
      this.CL59.BackColor = this.CurrentColor.BackColor;
      this.CL59.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL60_Click(object sender, EventArgs e)
    {
      this.CL60.BackColor = this.CurrentColor.BackColor;
      this.CL60.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL61_Click(object sender, EventArgs e)
    {
      this.CL61.BackColor = this.CurrentColor.BackColor;
      this.CL61.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL62_Click(object sender, EventArgs e)
    {
      this.CL62.BackColor = this.CurrentColor.BackColor;
      this.CL62.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL63_Click(object sender, EventArgs e)
    {
      this.CL63.BackColor = this.CurrentColor.BackColor;
      this.CL63.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL8_Click(object sender, EventArgs e)
    {
      this.CL8.BackColor = this.CurrentColor.BackColor;
      this.CL8.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL16_Click(object sender, EventArgs e)
    {
      this.CL16.BackColor = this.CurrentColor.BackColor;
      this.CL16.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL24_Click(object sender, EventArgs e)
    {
      this.CL24.BackColor = this.CurrentColor.BackColor;
      this.CL24.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL32_Click(object sender, EventArgs e)
    {
      this.CL32.BackColor = this.CurrentColor.BackColor;
      this.CL32.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL40_Click(object sender, EventArgs e)
    {
      this.CL40.BackColor = this.CurrentColor.BackColor;
      this.CL40.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL48_Click(object sender, EventArgs e)
    {
      this.CL48.BackColor = this.CurrentColor.BackColor;
      this.CL48.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL56_Click(object sender, EventArgs e)
    {
      this.CL56.BackColor = this.CurrentColor.BackColor;
      this.CL56.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
    }

    private void CL64_Click(object sender, EventArgs e)
    {
      this.CL64.BackColor = this.CurrentColor.BackColor;
      this.CL64.Tag = RuntimeHelpers.GetObjectValue(this.CurrentColor.Tag);
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

    private void method_12(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Reload.BackgroundImage = (Image) EmbeddedResources.smethod_100();
    }

    private void method_13(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Reload.BackgroundImage = (Image) EmbeddedResources.smethod_101();
    }

    private void method_14(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BorrarDatos.BackgroundImage = (Image) EmbeddedResources.smethod_36();
    }

    private void method_15(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BorrarDatos.BackgroundImage = (Image) EmbeddedResources.smethod_37();
    }

    private void method_16(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.CreateGuild.BackgroundImage = (Image) EmbeddedResources.smethod_50();
    }

    private void method_17(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.CreateGuild.BackgroundImage = (Image) EmbeddedResources.smethod_51();
    }

    private void method_18(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Aplicar.BackgroundImage = (Image) EmbeddedResources.smethod_90();
    }

    private void method_19(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Aplicar.BackgroundImage = (Image) EmbeddedResources.smethod_91();
    }

    private void method_20(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BorrarGuild.BackgroundImage = (Image) EmbeddedResources.smethod_53();
    }

    private void method_21(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BorrarGuild.BackgroundImage = (Image) EmbeddedResources.smethod_54();
    }

    private void method_22(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Minimizar.BackgroundImage = (Image) EmbeddedResources.smethod_86();
    }

    private void method_23(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Minimizar.BackgroundImage = (Image) EmbeddedResources.smethod_87();
    }

    private void method_24(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) EmbeddedResources.smethod_39();
    }

    private void method_25(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) EmbeddedResources.smethod_40();
    }

    private void PersonajeSearch_KeyPress(object sender, KeyPressEventArgs e)
    {
      if ((int) checked ((short) Strings.Asc(e.KeyChar)) != 13)
        return;
      this.method_9(RuntimeHelpers.GetObjectValue(sender), (EventArgs) e);
    }

    private void GuildSearch_KeyPress(object sender, KeyPressEventArgs e)
    {
      if ((int) checked ((short) Strings.Asc(e.KeyChar)) != 13)
        return;
      this.method_9(RuntimeHelpers.GetObjectValue(sender), (EventArgs) e);
    }
  }
}
