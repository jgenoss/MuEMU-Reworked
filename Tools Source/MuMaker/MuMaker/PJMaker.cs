// Decompiled with JetBrains decompiler
// Type: MuMaker.PJMaker
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
  public class PJMaker : Form
  {
    private static PJMaker pjmaker_0 = (PJMaker) null;
    private IContainer icontainer_0;
    [AccessedThroughProperty("Classe3")]
    private Label _Classe3;
    [AccessedThroughProperty("PJ1Name")]
    private Label _PJ1Name;
    [AccessedThroughProperty("PJ3lvl")]
    private Label _PJ3lvl;
    [AccessedThroughProperty("CreatePJ")]
    private Panel _CreatePJ;
    [AccessedThroughProperty("Label1")]
    private Label _Label1;
    [AccessedThroughProperty("MG")]
    private RadioButton _MG;
    [AccessedThroughProperty("DL")]
    private RadioButton _DL;
    [AccessedThroughProperty("DW")]
    private RadioButton _DW;
    [AccessedThroughProperty("DK")]
    private RadioButton _DK;
    [AccessedThroughProperty("FE")]
    private RadioButton _FE;
    [AccessedThroughProperty("Cerrar")]
    private Button _Cerrar;
    [AccessedThroughProperty("Aplicar")]
    private Button _Aplicar;
    [AccessedThroughProperty("NamePJ")]
    private TextBox _NamePJ;
    [AccessedThroughProperty("Personaje")]
    private PictureBox _Personaje;
    [AccessedThroughProperty("PJ1lvl")]
    private Label _PJ1lvl;
    [AccessedThroughProperty("PJ2lvl")]
    private Label _PJ2lvl;
    [AccessedThroughProperty("BClosed")]
    private Button _BClosed;
    [AccessedThroughProperty("Classe1")]
    private Label _Classe1;
    [AccessedThroughProperty("Classe2")]
    private Label _Classe2;
    [AccessedThroughProperty("PJ3Name")]
    private Label _PJ3Name;
    [AccessedThroughProperty("PJ5lvl")]
    private Label _PJ5lvl;
    [AccessedThroughProperty("PJ5Name")]
    private Label _PJ5Name;
    [AccessedThroughProperty("PJ2Name")]
    private Label _PJ2Name;
    [AccessedThroughProperty("Classe5")]
    private Label _Classe5;
    [AccessedThroughProperty("Classe4")]
    private Label _Classe4;
    [AccessedThroughProperty("PJ4lvl")]
    private Label _PJ4lvl;
    [AccessedThroughProperty("PJ4Name")]
    private Label _PJ4Name;
    [AccessedThroughProperty("CrearAccount")]
    private Button _CrearAccount;
    [AccessedThroughProperty("BorrarPJ5")]
    private Button _BorrarPJ5;
    [AccessedThroughProperty("BorrarPJ4")]
    private Button _BorrarPJ4;
    [AccessedThroughProperty("BorrarPJ2")]
    private Button _BorrarPJ2;
    [AccessedThroughProperty("BorrarPJ3")]
    private Button _BorrarPJ3;
    [AccessedThroughProperty("PJE2")]
    private Panel _PJE2;
    [AccessedThroughProperty("PJ4")]
    private PictureBox _PJ4;
    [AccessedThroughProperty("PJ2")]
    private PictureBox _PJ2;
    [AccessedThroughProperty("PJ3")]
    private PictureBox _PJ3;
    [AccessedThroughProperty("PJ1")]
    private PictureBox _PJ1;
    [AccessedThroughProperty("BorrarPJ1")]
    private Button _BorrarPJ1;
    [AccessedThroughProperty("PJE4")]
    private Panel _PJE4;
    [AccessedThroughProperty("PJE1")]
    private Panel _PJE1;
    [AccessedThroughProperty("PictureBox1")]
    private PictureBox _PictureBox1;
    [AccessedThroughProperty("PJE5")]
    private Panel _PJE5;
    [AccessedThroughProperty("PJ5")]
    private PictureBox _PJ5;
    [AccessedThroughProperty("PJE3")]
    private Panel _PJE3;
    [AccessedThroughProperty("SM")]
    private RadioButton _SM;
    [AccessedThroughProperty("Titulo")]
    private Label _Titulo;
    [AccessedThroughProperty("Salir")]
    private Button _Salir;

    internal virtual Label Classe3
    {
      [DebuggerNonUserCode] get
      {
        return this._Classe3;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Classe3 = value;
      }
    }

    internal virtual Label PJ1Name
    {
      [DebuggerNonUserCode] get
      {
        return this._PJ1Name;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJ1Name = value;
      }
    }

    internal virtual Label PJ3lvl
    {
      [DebuggerNonUserCode] get
      {
        return this._PJ3lvl;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJ3lvl = value;
      }
    }

    internal virtual Panel CreatePJ
    {
      [DebuggerNonUserCode] get
      {
        return this._CreatePJ;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._CreatePJ = value;
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

    internal virtual RadioButton MG
    {
      [DebuggerNonUserCode] get
      {
        return this._MG;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.MG_CheckedChanged);
        if (this._MG != null)
          this._MG.CheckedChanged -= eventHandler;
        this._MG = value;
        if (this._MG == null)
          return;
        this._MG.CheckedChanged += eventHandler;
      }
    }

    internal virtual RadioButton DL
    {
      [DebuggerNonUserCode] get
      {
        return this._DL;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.DL_CheckedChanged);
        if (this._DL != null)
          this._DL.CheckedChanged -= eventHandler;
        this._DL = value;
        if (this._DL == null)
          return;
        this._DL.CheckedChanged += eventHandler;
      }
    }

    internal virtual RadioButton DW
    {
      [DebuggerNonUserCode] get
      {
        return this._DW;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.DW_CheckedChanged);
        if (this._DW != null)
          this._DW.CheckedChanged -= eventHandler;
        this._DW = value;
        if (this._DW == null)
          return;
        this._DW.CheckedChanged += eventHandler;
      }
    }

    internal virtual RadioButton DK
    {
      [DebuggerNonUserCode] get
      {
        return this._DK;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.DK_CheckedChanged);
        if (this._DK != null)
          this._DK.CheckedChanged -= eventHandler;
        this._DK = value;
        if (this._DK == null)
          return;
        this._DK.CheckedChanged += eventHandler;
      }
    }

    internal virtual RadioButton FE
    {
      [DebuggerNonUserCode] get
      {
        return this._FE;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.FE_CheckedChanged);
        if (this._FE != null)
          this._FE.CheckedChanged -= eventHandler;
        this._FE = value;
        if (this._FE == null)
          return;
        this._FE.CheckedChanged += eventHandler;
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
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_27);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_26);
        EventHandler eventHandler = new EventHandler(this.method_2);
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

    internal virtual Button Aplicar
    {
      [DebuggerNonUserCode] get
      {
        return this._Aplicar;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_1);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_23);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_22);
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

    internal virtual TextBox NamePJ
    {
      [DebuggerNonUserCode] get
      {
        return this._NamePJ;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.NamePJ_TextChanged);
        if (this._NamePJ != null)
          this._NamePJ.TextChanged -= eventHandler;
        this._NamePJ = value;
        if (this._NamePJ == null)
          return;
        this._NamePJ.TextChanged += eventHandler;
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

    internal virtual Label PJ1lvl
    {
      [DebuggerNonUserCode] get
      {
        return this._PJ1lvl;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJ1lvl = value;
      }
    }

    internal virtual Label PJ2lvl
    {
      [DebuggerNonUserCode] get
      {
        return this._PJ2lvl;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJ2lvl = value;
      }
    }

    internal virtual Button BClosed
    {
      [DebuggerNonUserCode] get
      {
        return this._BClosed;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_25);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_24);
        EventHandler eventHandler = new EventHandler(this.method_3);
        if (this._BClosed != null)
        {
          this._BClosed.MouseDown -= mouseEventHandler1;
          this._BClosed.MouseUp -= mouseEventHandler2;
          this._BClosed.Click -= eventHandler;
        }
        this._BClosed = value;
        if (this._BClosed == null)
          return;
        this._BClosed.MouseDown += mouseEventHandler1;
        this._BClosed.MouseUp += mouseEventHandler2;
        this._BClosed.Click += eventHandler;
      }
    }

    internal virtual Label Classe1
    {
      [DebuggerNonUserCode] get
      {
        return this._Classe1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Classe1 = value;
      }
    }

    internal virtual Label Classe2
    {
      [DebuggerNonUserCode] get
      {
        return this._Classe2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Classe2 = value;
      }
    }

    internal virtual Label PJ3Name
    {
      [DebuggerNonUserCode] get
      {
        return this._PJ3Name;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJ3Name = value;
      }
    }

    internal virtual Label PJ5lvl
    {
      [DebuggerNonUserCode] get
      {
        return this._PJ5lvl;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJ5lvl = value;
      }
    }

    internal virtual Label PJ5Name
    {
      [DebuggerNonUserCode] get
      {
        return this._PJ5Name;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJ5Name = value;
      }
    }

    internal virtual Label PJ2Name
    {
      [DebuggerNonUserCode] get
      {
        return this._PJ2Name;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJ2Name = value;
      }
    }

    internal virtual Label Classe5
    {
      [DebuggerNonUserCode] get
      {
        return this._Classe5;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Classe5 = value;
      }
    }

    internal virtual Label Classe4
    {
      [DebuggerNonUserCode] get
      {
        return this._Classe4;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Classe4 = value;
      }
    }

    internal virtual Label PJ4lvl
    {
      [DebuggerNonUserCode] get
      {
        return this._PJ4lvl;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJ4lvl = value;
      }
    }

    internal virtual Label PJ4Name
    {
      [DebuggerNonUserCode] get
      {
        return this._PJ4Name;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJ4Name = value;
      }
    }

    internal virtual Button CrearAccount
    {
      [DebuggerNonUserCode] get
      {
        return this._CrearAccount;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_0);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_21);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_20);
        if (this._CrearAccount != null)
        {
          this._CrearAccount.Click -= eventHandler;
          this._CrearAccount.MouseDown -= mouseEventHandler1;
          this._CrearAccount.MouseUp -= mouseEventHandler2;
        }
        this._CrearAccount = value;
        if (this._CrearAccount == null)
          return;
        this._CrearAccount.Click += eventHandler;
        this._CrearAccount.MouseDown += mouseEventHandler1;
        this._CrearAccount.MouseUp += mouseEventHandler2;
      }
    }

    internal virtual Button BorrarPJ5
    {
      [DebuggerNonUserCode] get
      {
        return this._BorrarPJ5;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_19);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_18);
        EventHandler eventHandler = new EventHandler(this.method_9);
        if (this._BorrarPJ5 != null)
        {
          this._BorrarPJ5.MouseDown -= mouseEventHandler1;
          this._BorrarPJ5.MouseUp -= mouseEventHandler2;
          this._BorrarPJ5.Click -= eventHandler;
        }
        this._BorrarPJ5 = value;
        if (this._BorrarPJ5 == null)
          return;
        this._BorrarPJ5.MouseDown += mouseEventHandler1;
        this._BorrarPJ5.MouseUp += mouseEventHandler2;
        this._BorrarPJ5.Click += eventHandler;
      }
    }

    internal virtual Button BorrarPJ4
    {
      [DebuggerNonUserCode] get
      {
        return this._BorrarPJ4;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_17);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_16);
        EventHandler eventHandler = new EventHandler(this.method_8);
        if (this._BorrarPJ4 != null)
        {
          this._BorrarPJ4.MouseDown -= mouseEventHandler1;
          this._BorrarPJ4.MouseUp -= mouseEventHandler2;
          this._BorrarPJ4.Click -= eventHandler;
        }
        this._BorrarPJ4 = value;
        if (this._BorrarPJ4 == null)
          return;
        this._BorrarPJ4.MouseDown += mouseEventHandler1;
        this._BorrarPJ4.MouseUp += mouseEventHandler2;
        this._BorrarPJ4.Click += eventHandler;
      }
    }

    internal virtual Button BorrarPJ2
    {
      [DebuggerNonUserCode] get
      {
        return this._BorrarPJ2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_13);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_12);
        EventHandler eventHandler = new EventHandler(this.method_6);
        if (this._BorrarPJ2 != null)
        {
          this._BorrarPJ2.MouseDown -= mouseEventHandler1;
          this._BorrarPJ2.MouseUp -= mouseEventHandler2;
          this._BorrarPJ2.Click -= eventHandler;
        }
        this._BorrarPJ2 = value;
        if (this._BorrarPJ2 == null)
          return;
        this._BorrarPJ2.MouseDown += mouseEventHandler1;
        this._BorrarPJ2.MouseUp += mouseEventHandler2;
        this._BorrarPJ2.Click += eventHandler;
      }
    }

    internal virtual Button BorrarPJ3
    {
      [DebuggerNonUserCode] get
      {
        return this._BorrarPJ3;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_15);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_14);
        EventHandler eventHandler = new EventHandler(this.method_7);
        if (this._BorrarPJ3 != null)
        {
          this._BorrarPJ3.MouseDown -= mouseEventHandler1;
          this._BorrarPJ3.MouseUp -= mouseEventHandler2;
          this._BorrarPJ3.Click -= eventHandler;
        }
        this._BorrarPJ3 = value;
        if (this._BorrarPJ3 == null)
          return;
        this._BorrarPJ3.MouseDown += mouseEventHandler1;
        this._BorrarPJ3.MouseUp += mouseEventHandler2;
        this._BorrarPJ3.Click += eventHandler;
      }
    }

    internal virtual Panel PJE2
    {
      [DebuggerNonUserCode] get
      {
        return this._PJE2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJE2 = value;
      }
    }

    internal virtual PictureBox PJ4
    {
      [DebuggerNonUserCode] get
      {
        return this._PJ4;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJ4 = value;
      }
    }

    internal virtual PictureBox PJ2
    {
      [DebuggerNonUserCode] get
      {
        return this._PJ2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJ2 = value;
      }
    }

    internal virtual PictureBox PJ3
    {
      [DebuggerNonUserCode] get
      {
        return this._PJ3;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJ3 = value;
      }
    }

    internal virtual PictureBox PJ1
    {
      [DebuggerNonUserCode] get
      {
        return this._PJ1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJ1 = value;
      }
    }

    internal virtual Button BorrarPJ1
    {
      [DebuggerNonUserCode] get
      {
        return this._BorrarPJ1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_11);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_10);
        EventHandler eventHandler = new EventHandler(this.method_5);
        if (this._BorrarPJ1 != null)
        {
          this._BorrarPJ1.MouseDown -= mouseEventHandler1;
          this._BorrarPJ1.MouseUp -= mouseEventHandler2;
          this._BorrarPJ1.Click -= eventHandler;
        }
        this._BorrarPJ1 = value;
        if (this._BorrarPJ1 == null)
          return;
        this._BorrarPJ1.MouseDown += mouseEventHandler1;
        this._BorrarPJ1.MouseUp += mouseEventHandler2;
        this._BorrarPJ1.Click += eventHandler;
      }
    }

    internal virtual Panel PJE4
    {
      [DebuggerNonUserCode] get
      {
        return this._PJE4;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJE4 = value;
      }
    }

    internal virtual Panel PJE1
    {
      [DebuggerNonUserCode] get
      {
        return this._PJE1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJE1 = value;
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

    internal virtual Panel PJE5
    {
      [DebuggerNonUserCode] get
      {
        return this._PJE5;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJE5 = value;
      }
    }

    internal virtual PictureBox PJ5
    {
      [DebuggerNonUserCode] get
      {
        return this._PJ5;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJ5 = value;
      }
    }

    internal virtual Panel PJE3
    {
      [DebuggerNonUserCode] get
      {
        return this._PJE3;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PJE3 = value;
      }
    }

    internal virtual RadioButton SM
    {
      [DebuggerNonUserCode] get
      {
        return this._SM;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.SM_CheckedChanged);
        if (this._SM != null)
          this._SM.CheckedChanged -= eventHandler;
        this._SM = value;
        if (this._SM == null)
          return;
        this._SM.CheckedChanged += eventHandler;
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

    internal virtual Button Salir
    {
      [DebuggerNonUserCode] get
      {
        return this._Salir;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_29);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_28);
        EventHandler eventHandler = new EventHandler(this.method_4);
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

    public static PJMaker DefInstance
    {
      get
      {
        if (PJMaker.pjmaker_0 != null && !PJMaker.pjmaker_0.IsDisposed)
          PJMaker.pjmaker_0.BringToFront();
        else
          PJMaker.pjmaker_0 = new PJMaker();
        return PJMaker.pjmaker_0;
      }
      set
      {
        PJMaker.pjmaker_0 = value;
      }
    }

    [DebuggerNonUserCode]
    public PJMaker()
    {
      this.Load += new EventHandler(this.PJMaker_Load);
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
      ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof (PJMaker));
      this.Classe3 = new Label();
      this.PJ1Name = new Label();
      this.PJ3lvl = new Label();
      this.CreatePJ = new Panel();
      this.SM = new RadioButton();
      this.DL = new RadioButton();
      this.MG = new RadioButton();
      this.DW = new RadioButton();
      this.DK = new RadioButton();
      this.FE = new RadioButton();
      this.Cerrar = new Button();
      this.Aplicar = new Button();
      this.NamePJ = new TextBox();
      this.Personaje = new PictureBox();
      this.Label1 = new Label();
      this.PJ1lvl = new Label();
      this.PJ2lvl = new Label();
      this.BClosed = new Button();
      this.Classe1 = new Label();
      this.Classe2 = new Label();
      this.PJ3Name = new Label();
      this.PJ5lvl = new Label();
      this.PJ5Name = new Label();
      this.PJ2Name = new Label();
      this.Classe5 = new Label();
      this.Classe4 = new Label();
      this.PJ4lvl = new Label();
      this.PJ4Name = new Label();
      this.CrearAccount = new Button();
      this.BorrarPJ5 = new Button();
      this.BorrarPJ4 = new Button();
      this.BorrarPJ2 = new Button();
      this.BorrarPJ3 = new Button();
      this.PJE2 = new Panel();
      this.PJ4 = new PictureBox();
      this.PJ2 = new PictureBox();
      this.PJ3 = new PictureBox();
      this.PJ1 = new PictureBox();
      this.BorrarPJ1 = new Button();
      this.PJE4 = new Panel();
      this.PJE1 = new Panel();
      this.PictureBox1 = new PictureBox();
      this.PJE5 = new Panel();
      this.PJ5 = new PictureBox();
      this.PJE3 = new Panel();
      this.Titulo = new Label();
      this.Salir = new Button();
      this.CreatePJ.SuspendLayout();
      ((ISupportInitialize) this.Personaje).BeginInit();
      this.PJE2.SuspendLayout();
      ((ISupportInitialize) this.PJ4).BeginInit();
      ((ISupportInitialize) this.PJ2).BeginInit();
      ((ISupportInitialize) this.PJ3).BeginInit();
      ((ISupportInitialize) this.PJ1).BeginInit();
      this.PJE4.SuspendLayout();
      this.PJE1.SuspendLayout();
      ((ISupportInitialize) this.PictureBox1).BeginInit();
      this.PJE5.SuspendLayout();
      ((ISupportInitialize) this.PJ5).BeginInit();
      this.PJE3.SuspendLayout();
      this.SuspendLayout();
      this.Classe3.BackColor = Color.Transparent;
      this.Classe3.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Classe3.ForeColor = Color.GreenYellow;
      Label classe3_1 = this.Classe3;
      Point point1 = new Point(0, 20);
      Point point2 = point1;
      classe3_1.Location = point2;
      this.Classe3.Name = "Classe3";
      Label classe3_2 = this.Classe3;
      Size size1 = new Size(116, 12);
      Size size2 = size1;
      classe3_2.Size = size2;
      this.Classe3.TabIndex = 440;
      this.Classe3.TextAlign = ContentAlignment.MiddleCenter;
      this.PJ1Name.BackColor = Color.Transparent;
      this.PJ1Name.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.PJ1Name.ForeColor = Color.DarkOrange;
      Label pj1Name1 = this.PJ1Name;
      point1 = new Point(-1, 3);
      Point point3 = point1;
      pj1Name1.Location = point3;
      this.PJ1Name.Name = "PJ1Name";
      Label pj1Name2 = this.PJ1Name;
      size1 = new Size(116, 12);
      Size size3 = size1;
      pj1Name2.Size = size3;
      this.PJ1Name.TabIndex = 436;
      this.PJ1Name.TextAlign = ContentAlignment.MiddleCenter;
      this.PJ3lvl.BackColor = Color.Transparent;
      this.PJ3lvl.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.PJ3lvl.ForeColor = Color.Red;
      Label pj3lvl1 = this.PJ3lvl;
      point1 = new Point(0, 37);
      Point point4 = point1;
      pj3lvl1.Location = point4;
      this.PJ3lvl.Name = "PJ3lvl";
      Label pj3lvl2 = this.PJ3lvl;
      size1 = new Size(116, 12);
      Size size4 = size1;
      pj3lvl2.Size = size4;
      this.PJ3lvl.TabIndex = 439;
      this.PJ3lvl.TextAlign = ContentAlignment.MiddleCenter;
      this.CreatePJ.BackColor = Color.DimGray;
      // ISSUE: reference to a compiler-generated method
      this.CreatePJ.BackgroundImage = (Image) EmbeddedResources.smethod_96();
      this.CreatePJ.Controls.Add((Control) this.SM);
      this.CreatePJ.Controls.Add((Control) this.DL);
      this.CreatePJ.Controls.Add((Control) this.MG);
      this.CreatePJ.Controls.Add((Control) this.DW);
      this.CreatePJ.Controls.Add((Control) this.DK);
      this.CreatePJ.Controls.Add((Control) this.FE);
      this.CreatePJ.Controls.Add((Control) this.Cerrar);
      this.CreatePJ.Controls.Add((Control) this.Aplicar);
      this.CreatePJ.Controls.Add((Control) this.NamePJ);
      this.CreatePJ.Controls.Add((Control) this.Personaje);
      this.CreatePJ.Controls.Add((Control) this.Label1);
      Panel createPj1 = this.CreatePJ;
      point1 = new Point(110, 25);
      Point point5 = point1;
      createPj1.Location = point5;
      this.CreatePJ.Name = "CreatePJ";
      Panel createPj2 = this.CreatePJ;
      size1 = new Size(310, 150);
      Size size5 = size1;
      createPj2.Size = size5;
      this.CreatePJ.TabIndex = 448;
      this.CreatePJ.TabStop = true;
      this.CreatePJ.Visible = false;
      this.SM.AutoSize = true;
      this.SM.BackColor = Color.Transparent;
      this.SM.Cursor = Cursors.Hand;
      this.SM.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.SM.ForeColor = Color.Gray;
      RadioButton sm1 = this.SM;
      point1 = new Point(101, 31);
      Point point6 = point1;
      sm1.Location = point6;
      this.SM.Name = "SM";
      RadioButton sm2 = this.SM;
      size1 = new Size(83, 17);
      Size size6 = size1;
      sm2.Size = size6;
      this.SM.TabIndex = 441;
      this.SM.Text = "Sommoner";
      this.SM.UseVisualStyleBackColor = false;
      this.DL.AutoSize = true;
      this.DL.BackColor = Color.Transparent;
      this.DL.Cursor = Cursors.Hand;
      this.DL.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.DL.ForeColor = Color.Gray;
      RadioButton dl1 = this.DL;
      point1 = new Point(101, 13);
      Point point7 = point1;
      dl1.Location = point7;
      this.DL.Name = "DL";
      RadioButton dl2 = this.DL;
      size1 = new Size(81, 17);
      Size size7 = size1;
      dl2.Size = size7;
      this.DL.TabIndex = 436;
      this.DL.Text = "Dark Lord";
      this.DL.UseVisualStyleBackColor = false;
      this.MG.BackColor = Color.Transparent;
      this.MG.Cursor = Cursors.Hand;
      this.MG.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.MG.ForeColor = Color.Gray;
      RadioButton mg1 = this.MG;
      point1 = new Point(10, 66);
      Point point8 = point1;
      mg1.Location = point8;
      this.MG.Name = "MG";
      RadioButton mg2 = this.MG;
      size1 = new Size(70, 26);
      Size size8 = size1;
      mg2.Size = size8;
      this.MG.TabIndex = 437;
      this.MG.Text = "Magic Gladiator";
      this.MG.UseVisualStyleBackColor = false;
      this.DW.AutoSize = true;
      this.DW.BackColor = Color.Transparent;
      this.DW.Cursor = Cursors.Hand;
      this.DW.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.DW.ForeColor = Color.Gray;
      RadioButton dw1 = this.DW;
      point1 = new Point(10, 13);
      Point point9 = point1;
      dw1.Location = point9;
      this.DW.Name = "DW";
      RadioButton dw2 = this.DW;
      size1 = new Size(95, 17);
      Size size9 = size1;
      dw2.Size = size9;
      this.DW.TabIndex = 434;
      this.DW.Text = "Dark Wizard";
      this.DW.UseVisualStyleBackColor = false;
      this.DK.AutoSize = true;
      this.DK.BackColor = Color.Transparent;
      this.DK.Checked = true;
      this.DK.Cursor = Cursors.Hand;
      this.DK.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.DK.ForeColor = Color.Gray;
      RadioButton dk1 = this.DK;
      point1 = new Point(10, 31);
      Point point10 = point1;
      dk1.Location = point10;
      this.DK.Name = "DK";
      RadioButton dk2 = this.DK;
      size1 = new Size(92, 17);
      Size size10 = size1;
      dk2.Size = size10;
      this.DK.TabIndex = 439;
      this.DK.TabStop = true;
      this.DK.Text = "Dark Knight";
      this.DK.UseVisualStyleBackColor = false;
      this.FE.AutoSize = true;
      this.FE.BackColor = Color.Transparent;
      this.FE.Cursor = Cursors.Hand;
      this.FE.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.FE.ForeColor = Color.Gray;
      RadioButton fe1 = this.FE;
      point1 = new Point(10, 49);
      Point point11 = point1;
      fe1.Location = point11;
      this.FE.Name = "FE";
      RadioButton fe2 = this.FE;
      size1 = new Size(71, 17);
      Size size11 = size1;
      fe2.Size = size11;
      this.FE.TabIndex = 438;
      this.FE.Text = "Fairy Elf";
      this.FE.UseVisualStyleBackColor = false;
      this.Cerrar.BackColor = Color.Transparent;
      this.Cerrar.BackgroundImage = (Image) componentResourceManager.GetObject("Cerrar.BackgroundImage");
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
      point1 = new Point(113, 94);
      Point point12 = point1;
      cerrar1.Location = point12;
      this.Cerrar.Name = "Cerrar";
      Button cerrar2 = this.Cerrar;
      size1 = new Size(52, 28);
      Size size12 = size1;
      cerrar2.Size = size12;
      this.Cerrar.TabIndex = 433;
      this.Cerrar.UseVisualStyleBackColor = false;
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
      point1 = new Point(2, 93);
      Point point13 = point1;
      aplicar1.Location = point13;
      this.Aplicar.Name = "Aplicar";
      Button aplicar2 = this.Aplicar;
      size1 = new Size(54, 30);
      Size size13 = size1;
      aplicar2.Size = size13;
      this.Aplicar.TabIndex = 432;
      this.Aplicar.UseVisualStyleBackColor = false;
      TextBox namePj1 = this.NamePJ;
      point1 = new Point(9, 123);
      Point point14 = point1;
      namePj1.Location = point14;
      this.NamePJ.MaxLength = 10;
      this.NamePJ.Name = "NamePJ";
      TextBox namePj2 = this.NamePJ;
      size1 = new Size(156, 20);
      Size size14 = size1;
      namePj2.Size = size14;
      this.NamePJ.TabIndex = 429;
      this.Personaje.BackColor = Color.Transparent;
      PictureBox personaje1 = this.Personaje;
      point1 = new Point(175, 16);
      Point point15 = point1;
      personaje1.Location = point15;
      this.Personaje.Name = "Personaje";
      PictureBox personaje2 = this.Personaje;
      size1 = new Size(128, 128);
      Size size15 = size1;
      personaje2.Size = size15;
      this.Personaje.TabIndex = 431;
      this.Personaje.TabStop = false;
      this.Label1.BackColor = Color.Transparent;
      this.Label1.Font = new Font("Microsoft Sans Serif", 12f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Label1.ForeColor = Color.DarkOrange;
      Label label1_1 = this.Label1;
      point1 = new Point(54, 99);
      Point point16 = point1;
      label1_1.Location = point16;
      this.Label1.Name = "Label1";
      Label label1_2 = this.Label1;
      size1 = new Size(60, 16);
      Size size16 = size1;
      label1_2.Size = size16;
      this.Label1.TabIndex = 440;
      this.Label1.Text = "Name";
      this.Label1.TextAlign = ContentAlignment.MiddleCenter;
      this.PJ1lvl.BackColor = Color.Transparent;
      this.PJ1lvl.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.PJ1lvl.ForeColor = Color.Red;
      Label pj1lvl1 = this.PJ1lvl;
      point1 = new Point(-1, 36);
      Point point17 = point1;
      pj1lvl1.Location = point17;
      this.PJ1lvl.Name = "PJ1lvl";
      Label pj1lvl2 = this.PJ1lvl;
      size1 = new Size(116, 12);
      Size size17 = size1;
      pj1lvl2.Size = size17;
      this.PJ1lvl.TabIndex = 437;
      this.PJ1lvl.TextAlign = ContentAlignment.MiddleCenter;
      this.PJ2lvl.BackColor = Color.Transparent;
      this.PJ2lvl.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.PJ2lvl.ForeColor = Color.Red;
      Label pj2lvl1 = this.PJ2lvl;
      point1 = new Point(0, 37);
      Point point18 = point1;
      pj2lvl1.Location = point18;
      this.PJ2lvl.Name = "PJ2lvl";
      Label pj2lvl2 = this.PJ2lvl;
      size1 = new Size(116, 12);
      Size size18 = size1;
      pj2lvl2.Size = size18;
      this.PJ2lvl.TabIndex = 439;
      this.PJ2lvl.TextAlign = ContentAlignment.MiddleCenter;
      this.BClosed.BackColor = Color.Transparent;
      this.BClosed.BackgroundImage = (Image) componentResourceManager.GetObject("BClosed.BackgroundImage");
      this.BClosed.BackgroundImageLayout = ImageLayout.Center;
      this.BClosed.Cursor = Cursors.Hand;
      this.BClosed.FlatAppearance.BorderSize = 0;
      this.BClosed.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BClosed.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BClosed.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BClosed.FlatStyle = FlatStyle.Flat;
      this.BClosed.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BClosed.ForeColor = Color.Transparent;
      Button bclosed1 = this.BClosed;
      point1 = new Point(473, 27);
      Point point19 = point1;
      bclosed1.Location = point19;
      this.BClosed.Name = "BClosed";
      Button bclosed2 = this.BClosed;
      size1 = new Size(52, 28);
      Size size19 = size1;
      bclosed2.Size = size19;
      this.BClosed.TabIndex = 449;
      this.BClosed.TabStop = false;
      this.BClosed.UseVisualStyleBackColor = false;
      this.Classe1.BackColor = Color.Transparent;
      this.Classe1.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Classe1.ForeColor = Color.GreenYellow;
      Label classe1_1 = this.Classe1;
      point1 = new Point(-1, 20);
      Point point20 = point1;
      classe1_1.Location = point20;
      this.Classe1.Name = "Classe1";
      Label classe1_2 = this.Classe1;
      size1 = new Size(116, 12);
      Size size20 = size1;
      classe1_2.Size = size20;
      this.Classe1.TabIndex = 438;
      this.Classe1.TextAlign = ContentAlignment.MiddleCenter;
      this.Classe2.BackColor = Color.Transparent;
      this.Classe2.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Classe2.ForeColor = Color.GreenYellow;
      Label classe2_1 = this.Classe2;
      point1 = new Point(0, 20);
      Point point21 = point1;
      classe2_1.Location = point21;
      this.Classe2.Name = "Classe2";
      Label classe2_2 = this.Classe2;
      size1 = new Size(116, 12);
      Size size21 = size1;
      classe2_2.Size = size21;
      this.Classe2.TabIndex = 440;
      this.Classe2.TextAlign = ContentAlignment.MiddleCenter;
      this.PJ3Name.BackColor = Color.Transparent;
      this.PJ3Name.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.PJ3Name.ForeColor = Color.DarkOrange;
      Label pj3Name1 = this.PJ3Name;
      point1 = new Point(0, 2);
      Point point22 = point1;
      pj3Name1.Location = point22;
      this.PJ3Name.Name = "PJ3Name";
      Label pj3Name2 = this.PJ3Name;
      size1 = new Size(116, 12);
      Size size22 = size1;
      pj3Name2.Size = size22;
      this.PJ3Name.TabIndex = 438;
      this.PJ3Name.TextAlign = ContentAlignment.MiddleCenter;
      this.PJ5lvl.BackColor = Color.Transparent;
      this.PJ5lvl.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.PJ5lvl.ForeColor = Color.Red;
      Label pj5lvl1 = this.PJ5lvl;
      point1 = new Point(0, 37);
      Point point23 = point1;
      pj5lvl1.Location = point23;
      this.PJ5lvl.Name = "PJ5lvl";
      Label pj5lvl2 = this.PJ5lvl;
      size1 = new Size(116, 12);
      Size size23 = size1;
      pj5lvl2.Size = size23;
      this.PJ5lvl.TabIndex = 439;
      this.PJ5lvl.TextAlign = ContentAlignment.MiddleCenter;
      this.PJ5Name.BackColor = Color.Transparent;
      this.PJ5Name.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.PJ5Name.ForeColor = Color.DarkOrange;
      Label pj5Name1 = this.PJ5Name;
      point1 = new Point(0, 3);
      Point point24 = point1;
      pj5Name1.Location = point24;
      this.PJ5Name.Name = "PJ5Name";
      Label pj5Name2 = this.PJ5Name;
      size1 = new Size(116, 12);
      Size size24 = size1;
      pj5Name2.Size = size24;
      this.PJ5Name.TabIndex = 438;
      this.PJ5Name.TextAlign = ContentAlignment.MiddleCenter;
      this.PJ2Name.BackColor = Color.Transparent;
      this.PJ2Name.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.PJ2Name.ForeColor = Color.DarkOrange;
      Label pj2Name1 = this.PJ2Name;
      point1 = new Point(0, 3);
      Point point25 = point1;
      pj2Name1.Location = point25;
      this.PJ2Name.Name = "PJ2Name";
      Label pj2Name2 = this.PJ2Name;
      size1 = new Size(116, 12);
      Size size25 = size1;
      pj2Name2.Size = size25;
      this.PJ2Name.TabIndex = 438;
      this.PJ2Name.TextAlign = ContentAlignment.MiddleCenter;
      this.Classe5.BackColor = Color.Transparent;
      this.Classe5.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Classe5.ForeColor = Color.GreenYellow;
      Label classe5_1 = this.Classe5;
      point1 = new Point(0, 20);
      Point point26 = point1;
      classe5_1.Location = point26;
      this.Classe5.Name = "Classe5";
      Label classe5_2 = this.Classe5;
      size1 = new Size(116, 12);
      Size size26 = size1;
      classe5_2.Size = size26;
      this.Classe5.TabIndex = 440;
      this.Classe5.TextAlign = ContentAlignment.MiddleCenter;
      this.Classe4.BackColor = Color.Transparent;
      this.Classe4.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Classe4.ForeColor = Color.GreenYellow;
      Label classe4_1 = this.Classe4;
      point1 = new Point(0, 20);
      Point point27 = point1;
      classe4_1.Location = point27;
      this.Classe4.Name = "Classe4";
      Label classe4_2 = this.Classe4;
      size1 = new Size(116, 12);
      Size size27 = size1;
      classe4_2.Size = size27;
      this.Classe4.TabIndex = 440;
      this.Classe4.TextAlign = ContentAlignment.MiddleCenter;
      this.PJ4lvl.BackColor = Color.Transparent;
      this.PJ4lvl.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.PJ4lvl.ForeColor = Color.Red;
      Label pj4lvl1 = this.PJ4lvl;
      point1 = new Point(0, 37);
      Point point28 = point1;
      pj4lvl1.Location = point28;
      this.PJ4lvl.Name = "PJ4lvl";
      Label pj4lvl2 = this.PJ4lvl;
      size1 = new Size(116, 12);
      Size size28 = size1;
      pj4lvl2.Size = size28;
      this.PJ4lvl.TabIndex = 439;
      this.PJ4lvl.TextAlign = ContentAlignment.MiddleCenter;
      this.PJ4Name.BackColor = Color.Transparent;
      this.PJ4Name.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.PJ4Name.ForeColor = Color.DarkOrange;
      Label pj4Name1 = this.PJ4Name;
      point1 = new Point(0, 2);
      Point point29 = point1;
      pj4Name1.Location = point29;
      this.PJ4Name.Name = "PJ4Name";
      Label pj4Name2 = this.PJ4Name;
      size1 = new Size(116, 12);
      Size size29 = size1;
      pj4Name2.Size = size29;
      this.PJ4Name.TabIndex = 438;
      this.PJ4Name.TextAlign = ContentAlignment.MiddleCenter;
      this.CrearAccount.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.CrearAccount.BackgroundImage = (Image) EmbeddedResources.smethod_50();
      this.CrearAccount.BackgroundImageLayout = ImageLayout.Center;
      this.CrearAccount.Cursor = Cursors.Hand;
      this.CrearAccount.FlatAppearance.BorderSize = 0;
      this.CrearAccount.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.CrearAccount.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.CrearAccount.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.CrearAccount.FlatStyle = FlatStyle.Flat;
      this.CrearAccount.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.CrearAccount.ForeColor = Color.Transparent;
      Button crearAccount1 = this.CrearAccount;
      point1 = new Point(5, 27);
      Point point30 = point1;
      crearAccount1.Location = point30;
      this.CrearAccount.Name = "CrearAccount";
      Button crearAccount2 = this.CrearAccount;
      size1 = new Size(52, 28);
      Size size30 = size1;
      crearAccount2.Size = size30;
      this.CrearAccount.TabIndex = 441;
      this.CrearAccount.TabStop = false;
      this.CrearAccount.UseVisualStyleBackColor = false;
      this.BorrarPJ5.BackColor = Color.Transparent;
      this.BorrarPJ5.BackgroundImage = (Image) componentResourceManager.GetObject("BorrarPJ5.BackgroundImage");
      this.BorrarPJ5.BackgroundImageLayout = ImageLayout.Center;
      this.BorrarPJ5.Cursor = Cursors.Hand;
      this.BorrarPJ5.FlatAppearance.BorderSize = 0;
      this.BorrarPJ5.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BorrarPJ5.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BorrarPJ5.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BorrarPJ5.FlatStyle = FlatStyle.Flat;
      this.BorrarPJ5.Font = new Font("Verdana", 7f, FontStyle.Bold);
      this.BorrarPJ5.ForeColor = Color.Transparent;
      this.BorrarPJ5.ImeMode = ImeMode.NoControl;
      Button borrarPj5_1 = this.BorrarPJ5;
      point1 = new Point(429, 210);
      Point point31 = point1;
      borrarPj5_1.Location = point31;
      this.BorrarPJ5.Name = "BorrarPJ5";
      Button borrarPj5_2 = this.BorrarPJ5;
      size1 = new Size(52, 28);
      Size size31 = size1;
      borrarPj5_2.Size = size31;
      this.BorrarPJ5.TabIndex = 459;
      this.BorrarPJ5.TabStop = false;
      this.BorrarPJ5.TextAlign = ContentAlignment.TopLeft;
      this.BorrarPJ5.UseVisualStyleBackColor = false;
      this.BorrarPJ5.Visible = false;
      this.BorrarPJ4.BackColor = Color.Transparent;
      this.BorrarPJ4.BackgroundImage = (Image) componentResourceManager.GetObject("BorrarPJ4.BackgroundImage");
      this.BorrarPJ4.BackgroundImageLayout = ImageLayout.Center;
      this.BorrarPJ4.Cursor = Cursors.Hand;
      this.BorrarPJ4.FlatAppearance.BorderSize = 0;
      this.BorrarPJ4.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BorrarPJ4.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BorrarPJ4.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BorrarPJ4.FlatStyle = FlatStyle.Flat;
      this.BorrarPJ4.Font = new Font("Verdana", 7f, FontStyle.Bold);
      this.BorrarPJ4.ForeColor = Color.Transparent;
      this.BorrarPJ4.ImeMode = ImeMode.NoControl;
      Button borrarPj4_1 = this.BorrarPJ4;
      point1 = new Point(333, 156);
      Point point32 = point1;
      borrarPj4_1.Location = point32;
      this.BorrarPJ4.Name = "BorrarPJ4";
      Button borrarPj4_2 = this.BorrarPJ4;
      size1 = new Size(52, 28);
      Size size32 = size1;
      borrarPj4_2.Size = size32;
      this.BorrarPJ4.TabIndex = 458;
      this.BorrarPJ4.TabStop = false;
      this.BorrarPJ4.TextAlign = ContentAlignment.TopLeft;
      this.BorrarPJ4.UseVisualStyleBackColor = false;
      this.BorrarPJ4.Visible = false;
      this.BorrarPJ2.BackColor = Color.Transparent;
      this.BorrarPJ2.BackgroundImage = (Image) componentResourceManager.GetObject("BorrarPJ2.BackgroundImage");
      this.BorrarPJ2.BackgroundImageLayout = ImageLayout.Center;
      this.BorrarPJ2.Cursor = Cursors.Hand;
      this.BorrarPJ2.FlatAppearance.BorderSize = 0;
      this.BorrarPJ2.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BorrarPJ2.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BorrarPJ2.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BorrarPJ2.FlatStyle = FlatStyle.Flat;
      this.BorrarPJ2.Font = new Font("Verdana", 7f, FontStyle.Bold);
      this.BorrarPJ2.ForeColor = Color.Transparent;
      this.BorrarPJ2.ImeMode = ImeMode.NoControl;
      Button borrarPj2_1 = this.BorrarPJ2;
      point1 = new Point(141, 156);
      Point point33 = point1;
      borrarPj2_1.Location = point33;
      this.BorrarPJ2.Name = "BorrarPJ2";
      Button borrarPj2_2 = this.BorrarPJ2;
      size1 = new Size(52, 28);
      Size size33 = size1;
      borrarPj2_2.Size = size33;
      this.BorrarPJ2.TabIndex = 457;
      this.BorrarPJ2.TabStop = false;
      this.BorrarPJ2.TextAlign = ContentAlignment.TopLeft;
      this.BorrarPJ2.UseVisualStyleBackColor = false;
      this.BorrarPJ2.Visible = false;
      this.BorrarPJ3.BackColor = Color.Transparent;
      this.BorrarPJ3.BackgroundImage = (Image) componentResourceManager.GetObject("BorrarPJ3.BackgroundImage");
      this.BorrarPJ3.BackgroundImageLayout = ImageLayout.Center;
      this.BorrarPJ3.Cursor = Cursors.Hand;
      this.BorrarPJ3.FlatAppearance.BorderSize = 0;
      this.BorrarPJ3.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BorrarPJ3.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BorrarPJ3.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BorrarPJ3.FlatStyle = FlatStyle.Flat;
      this.BorrarPJ3.Font = new Font("Verdana", 7f, FontStyle.Bold);
      this.BorrarPJ3.ForeColor = Color.Transparent;
      this.BorrarPJ3.ImeMode = ImeMode.NoControl;
      Button borrarPj3_1 = this.BorrarPJ3;
      point1 = new Point(239, 102);
      Point point34 = point1;
      borrarPj3_1.Location = point34;
      this.BorrarPJ3.Name = "BorrarPJ3";
      Button borrarPj3_2 = this.BorrarPJ3;
      size1 = new Size(52, 28);
      Size size34 = size1;
      borrarPj3_2.Size = size34;
      this.BorrarPJ3.TabIndex = 456;
      this.BorrarPJ3.TabStop = false;
      this.BorrarPJ3.TextAlign = ContentAlignment.TopLeft;
      this.BorrarPJ3.UseVisualStyleBackColor = false;
      this.BorrarPJ3.Visible = false;
      this.PJE2.BackColor = Color.Transparent;
      this.PJE2.BackgroundImage = (Image) componentResourceManager.GetObject("PJE2.BackgroundImage");
      this.PJE2.Controls.Add((Control) this.Classe2);
      this.PJE2.Controls.Add((Control) this.PJ2lvl);
      this.PJE2.Controls.Add((Control) this.PJ2Name);
      Panel pjE2_1 = this.PJE2;
      point1 = new Point(109, 184);
      Point point35 = point1;
      pjE2_1.Location = point35;
      this.PJE2.Name = "PJE2";
      Panel pjE2_2 = this.PJE2;
      size1 = new Size(116, 52);
      Size size35 = size1;
      pjE2_2.Size = size35;
      this.PJE2.TabIndex = 454;
      this.PJE2.Visible = false;
      this.PJ4.BackColor = Color.Transparent;
      PictureBox pj4_1 = this.PJ4;
      point1 = new Point(329, 248);
      Point point36 = point1;
      pj4_1.Location = point36;
      this.PJ4.Name = "PJ4";
      PictureBox pj4_2 = this.PJ4;
      size1 = new Size(60, 150);
      Size size36 = size1;
      pj4_2.Size = size36;
      this.PJ4.TabIndex = 445;
      this.PJ4.TabStop = false;
      this.PJ2.BackColor = Color.Transparent;
      PictureBox pj2_1 = this.PJ2;
      point1 = new Point(137, 248);
      Point point37 = point1;
      pj2_1.Location = point37;
      this.PJ2.Name = "PJ2";
      PictureBox pj2_2 = this.PJ2;
      size1 = new Size(60, 150);
      Size size37 = size1;
      pj2_2.Size = size37;
      this.PJ2.TabIndex = 444;
      this.PJ2.TabStop = false;
      this.PJ3.BackColor = Color.Transparent;
      PictureBox pj3_1 = this.PJ3;
      point1 = new Point(233, 210);
      Point point38 = point1;
      pj3_1.Location = point38;
      this.PJ3.Name = "PJ3";
      PictureBox pj3_2 = this.PJ3;
      size1 = new Size(60, 150);
      Size size38 = size1;
      pj3_2.Size = size38;
      this.PJ3.TabIndex = 443;
      this.PJ3.TabStop = false;
      this.PJ1.BackColor = Color.Transparent;
      PictureBox pj1_1 = this.PJ1;
      point1 = new Point(41, 292);
      Point point39 = point1;
      pj1_1.Location = point39;
      this.PJ1.Name = "PJ1";
      PictureBox pj1_2 = this.PJ1;
      size1 = new Size(60, 150);
      Size size39 = size1;
      pj1_2.Size = size39;
      this.PJ1.TabIndex = 442;
      this.PJ1.TabStop = false;
      this.BorrarPJ1.BackColor = Color.Transparent;
      this.BorrarPJ1.BackgroundImage = (Image) componentResourceManager.GetObject("BorrarPJ1.BackgroundImage");
      this.BorrarPJ1.BackgroundImageLayout = ImageLayout.Center;
      this.BorrarPJ1.Cursor = Cursors.Hand;
      this.BorrarPJ1.FlatAppearance.BorderSize = 0;
      this.BorrarPJ1.FlatAppearance.CheckedBackColor = Color.Transparent;
      this.BorrarPJ1.FlatAppearance.MouseDownBackColor = Color.Transparent;
      this.BorrarPJ1.FlatAppearance.MouseOverBackColor = Color.Transparent;
      this.BorrarPJ1.FlatStyle = FlatStyle.Flat;
      this.BorrarPJ1.Font = new Font("Verdana", 7f, FontStyle.Bold);
      this.BorrarPJ1.ForeColor = Color.Transparent;
      this.BorrarPJ1.ImeMode = ImeMode.NoControl;
      Button borrarPj1_1 = this.BorrarPJ1;
      point1 = new Point(45, 210);
      Point point40 = point1;
      borrarPj1_1.Location = point40;
      this.BorrarPJ1.Name = "BorrarPJ1";
      Button borrarPj1_2 = this.BorrarPJ1;
      size1 = new Size(52, 28);
      Size size40 = size1;
      borrarPj1_2.Size = size40;
      this.BorrarPJ1.TabIndex = 455;
      this.BorrarPJ1.TabStop = false;
      this.BorrarPJ1.TextAlign = ContentAlignment.TopLeft;
      this.BorrarPJ1.UseVisualStyleBackColor = false;
      this.BorrarPJ1.Visible = false;
      this.PJE4.BackColor = Color.Transparent;
      this.PJE4.BackgroundImage = (Image) componentResourceManager.GetObject("PJE4.BackgroundImage");
      this.PJE4.Controls.Add((Control) this.Classe4);
      this.PJE4.Controls.Add((Control) this.PJ4lvl);
      this.PJE4.Controls.Add((Control) this.PJ4Name);
      Panel pjE4_1 = this.PJE4;
      point1 = new Point(301, 184);
      Point point41 = point1;
      pjE4_1.Location = point41;
      this.PJE4.Name = "PJE4";
      Panel pjE4_2 = this.PJE4;
      size1 = new Size(116, 52);
      Size size41 = size1;
      pjE4_2.Size = size41;
      this.PJE4.TabIndex = 452;
      this.PJE4.Visible = false;
      this.PJE1.BackColor = Color.Transparent;
      this.PJE1.BackgroundImage = (Image) componentResourceManager.GetObject("PJE1.BackgroundImage");
      this.PJE1.Controls.Add((Control) this.Classe1);
      this.PJE1.Controls.Add((Control) this.PJ1lvl);
      this.PJE1.Controls.Add((Control) this.PJ1Name);
      Panel pjE1_1 = this.PJE1;
      point1 = new Point(13, 238);
      Point point42 = point1;
      pjE1_1.Location = point42;
      this.PJE1.Name = "PJE1";
      Panel pjE1_2 = this.PJE1;
      size1 = new Size(116, 52);
      Size size42 = size1;
      pjE1_2.Size = size42;
      this.PJE1.TabIndex = 450;
      this.PJE1.Visible = false;
      this.PictureBox1.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.PictureBox1.Image = (Image) EmbeddedResources.smethod_64();
      PictureBox pictureBox1_1 = this.PictureBox1;
      point1 = new Point(451, 54);
      Point point43 = point1;
      pictureBox1_1.Location = point43;
      this.PictureBox1.Name = "PictureBox1";
      PictureBox pictureBox1_2 = this.PictureBox1;
      size1 = new Size(54, 108);
      Size size43 = size1;
      pictureBox1_2.Size = size43;
      this.PictureBox1.TabIndex = 447;
      this.PictureBox1.TabStop = false;
      this.PJE5.BackColor = Color.Transparent;
      this.PJE5.BackgroundImage = (Image) componentResourceManager.GetObject("PJE5.BackgroundImage");
      this.PJE5.Controls.Add((Control) this.Classe5);
      this.PJE5.Controls.Add((Control) this.PJ5lvl);
      this.PJE5.Controls.Add((Control) this.PJ5Name);
      Panel pjE5_1 = this.PJE5;
      point1 = new Point(397, 238);
      Point point44 = point1;
      pjE5_1.Location = point44;
      this.PJE5.Name = "PJE5";
      Panel pjE5_2 = this.PJE5;
      size1 = new Size(116, 52);
      Size size44 = size1;
      pjE5_2.Size = size44;
      this.PJE5.TabIndex = 453;
      this.PJE5.Visible = false;
      this.PJ5.BackColor = Color.Transparent;
      PictureBox pj5_1 = this.PJ5;
      point1 = new Point(425, 292);
      Point point45 = point1;
      pj5_1.Location = point45;
      this.PJ5.Name = "PJ5";
      PictureBox pj5_2 = this.PJ5;
      size1 = new Size(60, 150);
      Size size45 = size1;
      pj5_2.Size = size45;
      this.PJ5.TabIndex = 446;
      this.PJ5.TabStop = false;
      this.PJE3.BackColor = Color.Transparent;
      this.PJE3.BackgroundImage = (Image) componentResourceManager.GetObject("PJE3.BackgroundImage");
      this.PJE3.Controls.Add((Control) this.Classe3);
      this.PJE3.Controls.Add((Control) this.PJ3lvl);
      this.PJE3.Controls.Add((Control) this.PJ3Name);
      Panel pjE3_1 = this.PJE3;
      point1 = new Point(207, 130);
      Point point46 = point1;
      pjE3_1.Location = point46;
      this.PJE3.Name = "PJE3";
      Panel pjE3_2 = this.PJE3;
      size1 = new Size(116, 52);
      Size size46 = size1;
      pjE3_2.Size = size46;
      this.PJE3.TabIndex = 451;
      this.PJE3.Visible = false;
      this.Titulo.AutoSize = true;
      this.Titulo.BackColor = Color.Transparent;
      this.Titulo.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Titulo.ForeColor = Color.DarkOrange;
      Label titulo1 = this.Titulo;
      point1 = new Point(61, 6);
      Point point47 = point1;
      titulo1.Location = point47;
      this.Titulo.Name = "Titulo";
      Label titulo2 = this.Titulo;
      size1 = new Size(0, 13);
      Size size47 = size1;
      titulo2.Size = size47;
      this.Titulo.TabIndex = 490;
      this.Salir.BackColor = Color.Transparent;
      // ISSUE: reference to a compiler-generated method
      this.Salir.BackgroundImage = (Image) EmbeddedResources.smethod_39();
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
      point1 = new Point(513, 6);
      Point point48 = point1;
      salir1.Location = point48;
      this.Salir.Name = "Salir";
      Button salir2 = this.Salir;
      size1 = new Size(13, 13);
      Size size48 = size1;
      salir2.Size = size48;
      this.Salir.TabIndex = 489;
      this.Salir.TabStop = false;
      this.Salir.UseVisualStyleBackColor = false;
      this.AutoScaleMode = AutoScaleMode.Inherit;
      this.BackColor = Color.Black;
      // ISSUE: reference to a compiler-generated method
      this.BackgroundImage = (Image) EmbeddedResources.smethod_97();
      this.CancelButton = (IButtonControl) this.Cerrar;
      size1 = new Size(534, 442);
      this.ClientSize = size1;
      this.Controls.Add((Control) this.Titulo);
      this.Controls.Add((Control) this.Salir);
      this.Controls.Add((Control) this.CreatePJ);
      this.Controls.Add((Control) this.BClosed);
      this.Controls.Add((Control) this.CrearAccount);
      this.Controls.Add((Control) this.BorrarPJ5);
      this.Controls.Add((Control) this.BorrarPJ4);
      this.Controls.Add((Control) this.BorrarPJ2);
      this.Controls.Add((Control) this.BorrarPJ3);
      this.Controls.Add((Control) this.PJE2);
      this.Controls.Add((Control) this.PJ4);
      this.Controls.Add((Control) this.PJ2);
      this.Controls.Add((Control) this.PJ3);
      this.Controls.Add((Control) this.PJ1);
      this.Controls.Add((Control) this.BorrarPJ1);
      this.Controls.Add((Control) this.PJE4);
      this.Controls.Add((Control) this.PJE1);
      this.Controls.Add((Control) this.PictureBox1);
      this.Controls.Add((Control) this.PJE5);
      this.Controls.Add((Control) this.PJ5);
      this.Controls.Add((Control) this.PJE3);
      this.FormBorderStyle = FormBorderStyle.None;
      this.MaximizeBox = false;
      size1 = new Size(534, 442);
      this.MaximumSize = size1;
      this.MinimizeBox = false;
      size1 = new Size(534, 442);
      this.MinimumSize = size1;
      this.Name = "PJMaker";
      this.ShowInTaskbar = false;
      this.StartPosition = FormStartPosition.CenterScreen;
      this.Text = "PJMaker";
      this.CreatePJ.ResumeLayout(false);
      this.CreatePJ.PerformLayout();
      ((ISupportInitialize) this.Personaje).EndInit();
      this.PJE2.ResumeLayout(false);
      ((ISupportInitialize) this.PJ4).EndInit();
      ((ISupportInitialize) this.PJ2).EndInit();
      ((ISupportInitialize) this.PJ3).EndInit();
      ((ISupportInitialize) this.PJ1).EndInit();
      this.PJE4.ResumeLayout(false);
      this.PJE1.ResumeLayout(false);
      ((ISupportInitialize) this.PictureBox1).EndInit();
      this.PJE5.ResumeLayout(false);
      ((ISupportInitialize) this.PJ5).EndInit();
      this.PJE3.ResumeLayout(false);
      this.ResumeLayout(false);
      this.PerformLayout();
    }

    public object CheckPJ()
    {
      if (this.DW.Checked)
        this.Personaje.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) CharacterImagePaths.string_1)));
      if (this.DK.Checked)
        this.Personaje.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) CharacterImagePaths.string_6)));
      if (this.FE.Checked)
        this.Personaje.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) CharacterImagePaths.string_11)));
      if (this.MG.Checked)
        this.Personaje.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) CharacterImagePaths.string_16)));
      if (this.DL.Checked)
        this.Personaje.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) CharacterImagePaths.string_20)));
      if (this.SM.Checked)
        this.Personaje.BackgroundImage = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) CharacterImagePaths.string_24)));
      return (object) true;
    }

    public object Personajes()
    {
      ConnectionManager.smethod_0();
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = "SELECT GameID1,GameID2,GameID3,GameID4,GameID5,GameIDC FROM AccountCharacter WHERE Id='" + AccountMaker.DefInstance.Cuentas.Text + "';";
        SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
label_2:
        if (SqlConnectionPool.sqlDataReader_1.Read())
        {
          this.PJE1.Visible = false;
          this.PJE2.Visible = false;
          this.PJE3.Visible = false;
          this.PJE4.Visible = false;
          this.PJE5.Visible = false;
          this.BorrarPJ1.Visible = false;
          this.BorrarPJ2.Visible = false;
          this.BorrarPJ3.Visible = false;
          this.BorrarPJ4.Visible = false;
          this.BorrarPJ5.Visible = false;
          int num1 = 1;
          do
          {
            ConnectionManager.smethod_1();
            try
            {
              SqlConnectionPool.sqlConnection_2.Open();
              SqlConnectionPool.sqlCommand_2.Connection = SqlConnectionPool.sqlConnection_2;
              SqlConnectionPool.sqlCommand_2.CommandText = "SELECT Class, cLevel FROM Character WHERE AccountId='" + AccountMaker.DefInstance.Cuentas.Text + "' AND Name='" + SqlConnectionPool.sqlDataReader_1[checked (num1 - 1)].ToString() + "';";
              SqlConnectionPool.sqlDataReader_2 = SqlConnectionPool.sqlCommand_2.ExecuteReader();
              switch (num1)
              {
                case 1:
                  if (SqlConnectionPool.sqlDataReader_2.Read())
                  {
                    this.PJE1.Visible = true;
                    this.BorrarPJ1.Visible = true;
                    this.PJ1Name.Text = SqlConnectionPool.sqlDataReader_1[checked (num1 - 1)].ToString();
                    this.PJ1lvl.Text = SqlConnectionPool.sqlDataReader_2[1].ToString();
                    string str1 = SqlConnectionPool.sqlDataReader_2[0].ToString();
                    string str2 = CharacterImagePaths.string_0;
                    try
                    {
                      this.Classe1.Text = GameDataArrays.string_8[Conversions.ToInteger(Array.IndexOf<string>(GameDataArrays.string_6, str1).ToString())];
                    }
                    catch (Exception ex)
                    {
                      ProjectData.SetProjectError(ex);
                      this.Classe1.Text = GameDataArrays.string_8[Conversions.ToInteger(GameDataArrays.string_9)];
                      ProjectData.ClearProjectError();
                    }
                    string Left = str1;
                    if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(0), false) == 0)
                      str2 = CharacterImagePaths.string_2;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(1), false) == 0)
                      str2 = CharacterImagePaths.string_3;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(2), false) == 0)
                      str2 = CharacterImagePaths.string_4;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(3), false) == 0)
                      str2 = CharacterImagePaths.string_5;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(16), false) == 0)
                      str2 = CharacterImagePaths.string_7;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(17), false) == 0)
                      str2 = CharacterImagePaths.string_8;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(18), false) == 0)
                      str2 = CharacterImagePaths.string_9;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(19), false) == 0)
                      str2 = CharacterImagePaths.string_10;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(32), false) == 0)
                      str2 = CharacterImagePaths.string_12;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(33), false) == 0)
                      str2 = CharacterImagePaths.string_13;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(34), false) == 0)
                      str2 = CharacterImagePaths.string_14;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(35), false) == 0)
                      str2 = CharacterImagePaths.string_15;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(48), false) == 0)
                      str2 = CharacterImagePaths.string_17;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(49), false) == 0)
                      str2 = CharacterImagePaths.string_18;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(50), false) == 0)
                      str2 = CharacterImagePaths.string_18;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(64), false) == 0)
                      str2 = CharacterImagePaths.string_21;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(65), false) == 0)
                      str2 = CharacterImagePaths.string_22;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(66), false) == 0)
                      str2 = CharacterImagePaths.string_22;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(80), false) == 0)
                      str2 = CharacterImagePaths.string_25;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(81), false) == 0)
                      str2 = CharacterImagePaths.string_26;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(82), false) == 0)
                      str2 = CharacterImagePaths.string_27;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(83), false) == 0)
                      str2 = CharacterImagePaths.string_28;
                    this.PJ1.Image = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) str2)));
                    break;
                  }
                  break;
                case 2:
                  if (SqlConnectionPool.sqlDataReader_2.Read())
                  {
                    this.PJE2.Visible = true;
                    this.BorrarPJ2.Visible = true;
                    this.PJ2Name.Text = SqlConnectionPool.sqlDataReader_1[checked (num1 - 1)].ToString();
                    this.PJ2lvl.Text = SqlConnectionPool.sqlDataReader_2[1].ToString();
                    string str1 = SqlConnectionPool.sqlDataReader_2[0].ToString();
                    string str2 = CharacterImagePaths.string_0;
                    try
                    {
                      this.Classe2.Text = GameDataArrays.string_8[Conversions.ToInteger(Array.IndexOf<string>(GameDataArrays.string_6, str1).ToString())];
                    }
                    catch (Exception ex)
                    {
                      ProjectData.SetProjectError(ex);
                      this.Classe2.Text = GameDataArrays.string_8[Conversions.ToInteger(GameDataArrays.string_9)];
                      ProjectData.ClearProjectError();
                    }
                    string Left = str1;
                    if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(0), false) == 0)
                      str2 = CharacterImagePaths.string_2;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(1), false) == 0)
                      str2 = CharacterImagePaths.string_3;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(2), false) == 0)
                      str2 = CharacterImagePaths.string_4;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(3), false) == 0)
                      str2 = CharacterImagePaths.string_5;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(16), false) == 0)
                      str2 = CharacterImagePaths.string_7;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(17), false) == 0)
                      str2 = CharacterImagePaths.string_8;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(18), false) == 0)
                      str2 = CharacterImagePaths.string_9;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(19), false) == 0)
                      str2 = CharacterImagePaths.string_10;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(32), false) == 0)
                      str2 = CharacterImagePaths.string_12;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(33), false) == 0)
                      str2 = CharacterImagePaths.string_13;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(34), false) == 0)
                      str2 = CharacterImagePaths.string_14;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(35), false) == 0)
                      str2 = CharacterImagePaths.string_15;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(48), false) == 0)
                      str2 = CharacterImagePaths.string_17;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(49), false) == 0)
                      str2 = CharacterImagePaths.string_18;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(50), false) == 0)
                      str2 = CharacterImagePaths.string_18;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(64), false) == 0)
                      str2 = CharacterImagePaths.string_21;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(65), false) == 0)
                      str2 = CharacterImagePaths.string_22;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(66), false) == 0)
                      str2 = CharacterImagePaths.string_22;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(80), false) == 0)
                      str2 = CharacterImagePaths.string_25;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(81), false) == 0)
                      str2 = CharacterImagePaths.string_26;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(82), false) == 0)
                      str2 = CharacterImagePaths.string_27;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(83), false) == 0)
                      str2 = CharacterImagePaths.string_28;
                    this.PJ2.Image = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) str2)));
                    break;
                  }
                  break;
                case 3:
                  if (SqlConnectionPool.sqlDataReader_2.Read())
                  {
                    this.PJE3.Visible = true;
                    this.BorrarPJ3.Visible = true;
                    this.PJ3Name.Text = SqlConnectionPool.sqlDataReader_1[checked (num1 - 1)].ToString();
                    this.PJ3lvl.Text = SqlConnectionPool.sqlDataReader_2[1].ToString();
                    string str1 = SqlConnectionPool.sqlDataReader_2[0].ToString();
                    string str2 = CharacterImagePaths.string_0;
                    try
                    {
                      this.Classe3.Text = GameDataArrays.string_8[Conversions.ToInteger(Array.IndexOf<string>(GameDataArrays.string_6, str1).ToString())];
                    }
                    catch (Exception ex)
                    {
                      ProjectData.SetProjectError(ex);
                      this.Classe3.Text = GameDataArrays.string_8[Conversions.ToInteger(GameDataArrays.string_9)];
                      ProjectData.ClearProjectError();
                    }
                    string Left = str1;
                    if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(0), false) == 0)
                      str2 = CharacterImagePaths.string_2;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(1), false) == 0)
                      str2 = CharacterImagePaths.string_3;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(2), false) == 0)
                      str2 = CharacterImagePaths.string_4;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(3), false) == 0)
                      str2 = CharacterImagePaths.string_5;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(16), false) == 0)
                      str2 = CharacterImagePaths.string_7;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(17), false) == 0)
                      str2 = CharacterImagePaths.string_8;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(18), false) == 0)
                      str2 = CharacterImagePaths.string_9;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(19), false) == 0)
                      str2 = CharacterImagePaths.string_10;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(32), false) == 0)
                      str2 = CharacterImagePaths.string_12;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(33), false) == 0)
                      str2 = CharacterImagePaths.string_13;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(34), false) == 0)
                      str2 = CharacterImagePaths.string_14;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(35), false) == 0)
                      str2 = CharacterImagePaths.string_15;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(48), false) == 0)
                      str2 = CharacterImagePaths.string_17;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(49), false) == 0)
                      str2 = CharacterImagePaths.string_18;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(50), false) == 0)
                      str2 = CharacterImagePaths.string_18;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(64), false) == 0)
                      str2 = CharacterImagePaths.string_21;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(65), false) == 0)
                      str2 = CharacterImagePaths.string_22;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(66), false) == 0)
                      str2 = CharacterImagePaths.string_22;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(80), false) == 0)
                      str2 = CharacterImagePaths.string_25;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(81), false) == 0)
                      str2 = CharacterImagePaths.string_26;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(82), false) == 0)
                      str2 = CharacterImagePaths.string_27;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(83), false) == 0)
                      str2 = CharacterImagePaths.string_28;
                    this.PJ3.Image = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) str2)));
                    break;
                  }
                  break;
                case 4:
                  if (SqlConnectionPool.sqlDataReader_2.Read())
                  {
                    this.PJE4.Visible = true;
                    this.BorrarPJ4.Visible = true;
                    this.PJ4Name.Text = SqlConnectionPool.sqlDataReader_1[checked (num1 - 1)].ToString();
                    this.PJ4lvl.Text = SqlConnectionPool.sqlDataReader_2[1].ToString();
                    string str1 = SqlConnectionPool.sqlDataReader_2[0].ToString();
                    string str2 = CharacterImagePaths.string_0;
                    try
                    {
                      this.Classe4.Text = GameDataArrays.string_8[Conversions.ToInteger(Array.IndexOf<string>(GameDataArrays.string_6, str1).ToString())];
                    }
                    catch (Exception ex)
                    {
                      ProjectData.SetProjectError(ex);
                      this.Classe4.Text = GameDataArrays.string_8[Conversions.ToInteger(GameDataArrays.string_9)];
                      ProjectData.ClearProjectError();
                    }
                    string Left = str1;
                    if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(0), false) == 0)
                      str2 = CharacterImagePaths.string_2;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(1), false) == 0)
                      str2 = CharacterImagePaths.string_3;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(2), false) == 0)
                      str2 = CharacterImagePaths.string_4;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(3), false) == 0)
                      str2 = CharacterImagePaths.string_5;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(16), false) == 0)
                      str2 = CharacterImagePaths.string_7;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(17), false) == 0)
                      str2 = CharacterImagePaths.string_8;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(18), false) == 0)
                      str2 = CharacterImagePaths.string_9;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(19), false) == 0)
                      str2 = CharacterImagePaths.string_10;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(32), false) == 0)
                      str2 = CharacterImagePaths.string_12;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(33), false) == 0)
                      str2 = CharacterImagePaths.string_13;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(34), false) == 0)
                      str2 = CharacterImagePaths.string_14;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(35), false) == 0)
                      str2 = CharacterImagePaths.string_15;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(48), false) == 0)
                      str2 = CharacterImagePaths.string_17;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(49), false) == 0)
                      str2 = CharacterImagePaths.string_18;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(50), false) == 0)
                      str2 = CharacterImagePaths.string_18;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(64), false) == 0)
                      str2 = CharacterImagePaths.string_21;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(65), false) == 0)
                      str2 = CharacterImagePaths.string_22;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(66), false) == 0)
                      str2 = CharacterImagePaths.string_22;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(80), false) == 0)
                      str2 = CharacterImagePaths.string_25;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(81), false) == 0)
                      str2 = CharacterImagePaths.string_26;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(82), false) == 0)
                      str2 = CharacterImagePaths.string_27;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(83), false) == 0)
                      str2 = CharacterImagePaths.string_28;
                    this.PJ4.Image = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) str2)));
                    break;
                  }
                  break;
                case 5:
                  if (SqlConnectionPool.sqlDataReader_2.Read())
                  {
                    this.PJE5.Visible = true;
                    this.BorrarPJ5.Visible = true;
                    this.PJ5Name.Text = SqlConnectionPool.sqlDataReader_1[checked (num1 - 1)].ToString();
                    this.PJ5lvl.Text = SqlConnectionPool.sqlDataReader_2[1].ToString();
                    string str1 = SqlConnectionPool.sqlDataReader_2[0].ToString();
                    string str2 = CharacterImagePaths.string_0;
                    try
                    {
                      this.Classe5.Text = GameDataArrays.string_8[Conversions.ToInteger(Array.IndexOf<string>(GameDataArrays.string_6, str1).ToString())];
                    }
                    catch (Exception ex)
                    {
                      ProjectData.SetProjectError(ex);
                      this.Classe5.Text = GameDataArrays.string_8[Conversions.ToInteger(GameDataArrays.string_9)];
                      ProjectData.ClearProjectError();
                    }
                    string Left = str1;
                    if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(0), false) == 0)
                      str2 = CharacterImagePaths.string_2;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(1), false) == 0)
                      str2 = CharacterImagePaths.string_3;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(2), false) == 0)
                      str2 = CharacterImagePaths.string_4;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(3), false) == 0)
                      str2 = CharacterImagePaths.string_5;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(16), false) == 0)
                      str2 = CharacterImagePaths.string_7;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(17), false) == 0)
                      str2 = CharacterImagePaths.string_8;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(18), false) == 0)
                      str2 = CharacterImagePaths.string_9;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(19), false) == 0)
                      str2 = CharacterImagePaths.string_10;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(32), false) == 0)
                      str2 = CharacterImagePaths.string_12;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(33), false) == 0)
                      str2 = CharacterImagePaths.string_13;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(34), false) == 0)
                      str2 = CharacterImagePaths.string_14;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(35), false) == 0)
                      str2 = CharacterImagePaths.string_15;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(48), false) == 0)
                      str2 = CharacterImagePaths.string_17;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(49), false) == 0)
                      str2 = CharacterImagePaths.string_18;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(50), false) == 0)
                      str2 = CharacterImagePaths.string_18;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(64), false) == 0)
                      str2 = CharacterImagePaths.string_21;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(65), false) == 0)
                      str2 = CharacterImagePaths.string_22;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(66), false) == 0)
                      str2 = CharacterImagePaths.string_22;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(80), false) == 0)
                      str2 = CharacterImagePaths.string_25;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(81), false) == 0)
                      str2 = CharacterImagePaths.string_26;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(82), false) == 0)
                      str2 = CharacterImagePaths.string_27;
                    else if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(Left, Conversions.ToString(83), false) == 0)
                      str2 = CharacterImagePaths.string_28;
                    this.PJ5.Image = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) str2)));
                    break;
                  }
                  break;
              }
              SqlConnectionPool.sqlDataReader_2.Close();
            }
            catch (Exception ex)
            {
              ProjectData.SetProjectError(ex);
              int num2 = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
              ProjectData.ClearProjectError();
            }
            ConnectionManager.smethod_6();
            checked { ++num1; }
          }
          while (num1 <= 5);
          goto label_2;
        }
        else
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

    public object ComprovarName()
    {
      object obj = (object) 0;
      ConnectionManager.smethod_0();
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = "SELECT Name FROM Character;";
        SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
        while (SqlConnectionPool.sqlDataReader_1.Read())
        {
          if (Microsoft.VisualBasic.CompilerServices.Operators.CompareString(this.NamePJ.Text.ToUpper(), SqlConnectionPool.sqlDataReader_1[0].ToString().ToUpper(), false) != 0)
          {
            obj = (object) 0;
          }
          else
          {
            obj = (object) 1;
            SqlConnectionPool.sqlDataReader_1.Close();
            ConnectionManager.smethod_5();
            goto label_9;
          }
        }
        SqlConnectionPool.sqlDataReader_1.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        obj = (object) 1;
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
label_9:
      return obj;
    }

        //public object MakePJ()
        //{
        //  if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(this.ComprovarName(), (object) 0, false))
        //  {
        //    ConnectionManager.smethod_0();
        //    SqlConnectionPool.sqlConnection_1.Open();
        //    int num1;
        //    if (this.DW.Checked)
        //      num1 = 0;
        //    if (this.DK.Checked)
        //      num1 = 16;
        //    if (this.FE.Checked)
        //      num1 = 32;
        //    if (this.MG.Checked)
        //      num1 = 48;
        //    if (this.DL.Checked)
        //      num1 = 64;
        //    if (this.SM.Checked)
        //      num1 = 80;
        //    try
        //    {
        //      SqlCommand sqlCommand1 = new SqlCommand();
        //      SqlCommand sqlCommand2 = new SqlCommand("WZ_CreateCharacter", SqlConnectionPool.sqlConnection_1);
        //      sqlCommand2.CommandType = CommandType.StoredProcedure;
        //      SqlConnectionPool.sqlParameter_0 = new SqlParameter("@AccountID", SqlDbType.VarChar, 10);
        //      SqlConnectionPool.sqlParameter_0.Direction = ParameterDirection.Input;
        //      sqlCommand2.Parameters.Add(SqlConnectionPool.sqlParameter_0);
        //      SqlConnectionPool.sqlParameter_0 = new SqlParameter("@Name", SqlDbType.VarChar, 10);
        //      SqlConnectionPool.sqlParameter_0.Direction = ParameterDirection.Input;
        //      sqlCommand2.Parameters.Add(SqlConnectionPool.sqlParameter_0);
        //      SqlConnectionPool.sqlParameter_0 = new SqlParameter("@Class", SqlDbType.TinyInt);
        //      SqlConnectionPool.sqlParameter_0.Direction = ParameterDirection.Input;
        //      sqlCommand2.Parameters.Add(SqlConnectionPool.sqlParameter_0);
        //      sqlCommand2.Parameters["@AccountID"].Value = (object) AccountMaker.DefInstance.Cuentas.Text;
        //      sqlCommand2.Parameters["@Name"].Value = (object) this.NamePJ.Text;
        //      sqlCommand2.Parameters["@Class"].Value = (object) num1;
        //      sqlCommand2.ExecuteNonQuery();
        //      sqlCommand2.Dispose();
        //      SqlConnectionPool.int_0 = 0;
        //      sqlCommand1.Dispose();
        //    }
        //    catch (Exception ex)
        //    {
        //      ProjectData.SetProjectError(ex);
        //      int num2 = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        //      ProjectData.ClearProjectError();
        //    }
        //    ConnectionManager.smethod_5();
        //  }
        //  else
        //  {
        //    int num = (int) Interaction.MsgBox((object) "Name Already Exist\nUse Other Name", MsgBoxStyle.OkOnly, (object) null);
        //  }
        //  return (object) true;
        //}
        public object MakePJ()
        {
            if (Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual(this.ComprovarName(), 0, false))
            {
                int num2 = 0;
                ConnectionManager.smethod_0();
                SqlConnectionPool.sqlConnection_1.Open();
                if (this.DW.Checked)
                {
                    num2 = 0;
                }
                if (this.DK.Checked)
                {
                    num2 = 0x10;
                }
                if (this.FE.Checked)
                {
                    num2 = 0x20;
                }
                if (this.MG.Checked)
                {
                    num2 = 0x30;
                }
                if (this.DL.Checked)
                {
                    num2 = 0x40;
                }
                if (this.SM.Checked)
                {
                    num2 = 80;
                }
                try
                {
                    SqlCommand command = new SqlCommand();
                    SqlCommand command2 = new SqlCommand("WZ_CreateCharacter", SqlConnectionPool.sqlConnection_1)
                    {
                        CommandType = CommandType.StoredProcedure
                    };
                    SqlConnectionPool.sqlParameter_0 = new SqlParameter("@AccountID", SqlDbType.VarChar, 10);
                    SqlConnectionPool.sqlParameter_0.Direction = ParameterDirection.Input;
                    command2.Parameters.Add(SqlConnectionPool.sqlParameter_0);
                    SqlConnectionPool.sqlParameter_0 = new SqlParameter("@Name", SqlDbType.VarChar, 10);
                    SqlConnectionPool.sqlParameter_0.Direction = ParameterDirection.Input;
                    command2.Parameters.Add(SqlConnectionPool.sqlParameter_0);
                    SqlConnectionPool.sqlParameter_0 = new SqlParameter("@Class", SqlDbType.TinyInt);
                    SqlConnectionPool.sqlParameter_0.Direction = ParameterDirection.Input;
                    command2.Parameters.Add(SqlConnectionPool.sqlParameter_0);
                    command2.Parameters["@AccountID"].Value = AccountMaker.DefInstance.Cuentas.Text;
                    command2.Parameters["@Name"].Value = this.NamePJ.Text;
                    command2.Parameters["@Class"].Value = num2;
                    command2.ExecuteNonQuery();
                    command2.Dispose();
                    SqlConnectionPool.int_0 = 0;
                    command.Dispose();
                    command = null;
                }
                catch (Exception exception1)
                {
                    ProjectData.SetProjectError(exception1);
                    Exception exception = exception1;
                    Interaction.MsgBox(exception.Message, MsgBoxStyle.ApplicationModal, null);
                    ProjectData.ClearProjectError();
                }
                ConnectionManager.smethod_5();
            }
            else
            {
                Interaction.MsgBox("Name Already Exist\nUse Other Name", MsgBoxStyle.ApplicationModal, null);
            }
            return true;
        }

        public object DeletePJ(object Name, object NPJ)
    {
      ConnectionManager.smethod_0();
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) ("DELETE FROM Character WHERE AccountID='" + AccountMaker.DefInstance.Cuentas.Text + "' AND Name='"), Name), (object) "';"));
        SqlConnectionPool.sqlCommand_1.ExecuteReader();
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
        SqlConnectionPool.sqlCommand_1.CommandText = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) "UPDATE AccountCharacter SET GameID", NPJ), (object) " = NULL WHERE ID = '"), (object) AccountMaker.DefInstance.Cuentas.Text), (object) "';"));
        SqlConnectionPool.sqlCommand_1.ExecuteReader();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
      StatsMaker.DefInstance.Close();
      PJMaker.DefInstance.Close();
      PJMaker.DefInstance.Show();
      PJMaker.DefInstance.Location = new Point(checked (AccountMaker.DefInstance.Location.X + 376), AccountMaker.DefInstance.Location.Y);
      ConnectionManager.smethod_0();
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = "SELECT Name FROM Character WHERE AccountID='" + AccountMaker.DefInstance.Cuentas.Text + "'";
        SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
        AccountMaker.DefInstance.Personajes.Text = " " + IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Lang/" + LocalizedStrings.string_0 + ".ini", "Lang", "SelecPerson", ">> Seleccionar Personaje <<") + " ";
        AccountMaker.DefInstance.Personajes.Items.Clear();
        while (SqlConnectionPool.sqlDataReader_1.Read())
          AccountMaker.DefInstance.Personajes.Items.Add((object) SqlConnectionPool.sqlDataReader_1[0].ToString());
        SqlConnectionPool.sqlDataReader_1.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
      DatabaseOperations.smethod_1();
      AccountMaker.DefInstance.ResetDatosPJ();
      AccountMaker.DefInstance.RestriccionesOFF();
      AccountMaker.DefInstance.CreatePj.Enabled = true;
      AccountMaker.DefInstance.Buscar.Focus();
      AccountMaker.DefInstance.Buscar.Select();
      AccountMaker.DefInstance.CuentaID.Enabled = true;
      AccountMaker.DefInstance.PassWord.Enabled = true;
      AccountMaker.DefInstance.Email.Enabled = true;
      AccountMaker.DefInstance.PersonalID.Enabled = true;
      AccountMaker.DefInstance.BorrarCuenta.Enabled = true;
      AccountMaker.DefInstance.AccountEdit.Enabled = true;
      return (object) true;
    }

    private void PJMaker_Load(object sender, EventArgs e)
    {
      this.Text = Conversions.ToString(Microsoft.VisualBasic.CompilerServices.Operators.ConcatenateObject((object) (this.Text + " - "), Configuration.object_18));
      this.Titulo.Text = this.Text;
      this.Personajes();
    }

    private void NamePJ_TextChanged(object sender, EventArgs e)
    {
      if (this.NamePJ.Text.Length > 0)
        this.Aplicar.Enabled = true;
      else
        this.Aplicar.Enabled = false;
    }

    private void FE_CheckedChanged(object sender, EventArgs e)
    {
      this.CheckPJ();
    }

    private void DK_CheckedChanged(object sender, EventArgs e)
    {
      this.CheckPJ();
    }

    private void DW_CheckedChanged(object sender, EventArgs e)
    {
      this.CheckPJ();
    }

    private void DL_CheckedChanged(object sender, EventArgs e)
    {
      this.CheckPJ();
    }

    private void MG_CheckedChanged(object sender, EventArgs e)
    {
      this.CheckPJ();
    }

    private void SM_CheckedChanged(object sender, EventArgs e)
    {
      this.CheckPJ();
    }

    private void method_0(object sender, EventArgs e)
    {
      this.CreatePJ.Visible = true;
      this.DK.Checked = true;
    }

    private void method_1(object sender, EventArgs e)
    {
      this.CreatePJ.Visible = false;
      this.MakePJ();
      StatsMaker.DefInstance.Close();
      PJMaker.DefInstance.Close();
      PJMaker.DefInstance.Show();
      PJMaker.DefInstance.Location = new Point(checked (AccountMaker.DefInstance.Location.X + 376), AccountMaker.DefInstance.Location.Y);
      ConnectionManager.smethod_0();
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = "SELECT Name FROM Character WHERE AccountID='" + AccountMaker.DefInstance.Cuentas.Text + "'";
        SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
        AccountMaker.DefInstance.Personajes.Text = " " + IniHelper.smethod_1(ApplicationServices.MuMakerApplication.smethod_1().Info.DirectoryPath + "/Lang/" + LocalizedStrings.string_0 + ".ini", "Lang", "SelecPerson", ">> Seleccionar Personaje <<") + " ";
        AccountMaker.DefInstance.Personajes.Items.Clear();
        while (SqlConnectionPool.sqlDataReader_1.Read())
          AccountMaker.DefInstance.Personajes.Items.Add((object) SqlConnectionPool.sqlDataReader_1[0].ToString());
        SqlConnectionPool.sqlDataReader_1.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
      DatabaseOperations.smethod_1();
      AccountMaker.DefInstance.ResetDatosPJ();
      AccountMaker.DefInstance.RestriccionesOFF();
      AccountMaker.DefInstance.CreatePj.Enabled = true;
      AccountMaker.DefInstance.Buscar.Focus();
      AccountMaker.DefInstance.Buscar.Select();
      AccountMaker.DefInstance.CuentaID.Enabled = true;
      AccountMaker.DefInstance.PassWord.Enabled = true;
      AccountMaker.DefInstance.Email.Enabled = true;
      AccountMaker.DefInstance.PersonalID.Enabled = true;
      AccountMaker.DefInstance.BorrarCuenta.Enabled = true;
      AccountMaker.DefInstance.AccountEdit.Enabled = true;
    }

    private void method_2(object sender, EventArgs e)
    {
      this.CreatePJ.Visible = false;
    }

    private void method_3(object sender, EventArgs e)
    {
      PJMaker.DefInstance.Close();
    }

    private void method_4(object sender, EventArgs e)
    {
      PJMaker.DefInstance.Close();
    }

    private void method_5(object sender, EventArgs e)
    {
      if (!Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual((object) Interaction.MsgBox((object) "Delete PJ!!", MsgBoxStyle.YesNo, (object) "Delete"), (object) MsgBoxResult.Yes, false))
        return;
      this.DeletePJ((object) this.PJ1Name.Text, (object) 1);
    }

    private void method_6(object sender, EventArgs e)
    {
      if (!Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual((object) Interaction.MsgBox((object) "Delete PJ!!", MsgBoxStyle.YesNo, (object) "Delete"), (object) MsgBoxResult.Yes, false))
        return;
      this.DeletePJ((object) this.PJ2Name.Text, (object) 2);
    }

    private void method_7(object sender, EventArgs e)
    {
      if (!Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual((object) Interaction.MsgBox((object) "Delete PJ!!", MsgBoxStyle.YesNo, (object) "Delete"), (object) MsgBoxResult.Yes, false))
        return;
      this.DeletePJ((object) this.PJ3Name.Text, (object) 3);
    }

    private void method_8(object sender, EventArgs e)
    {
      if (!Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual((object) Interaction.MsgBox((object) "Delete PJ!!", MsgBoxStyle.YesNo, (object) "Delete"), (object) MsgBoxResult.Yes, false))
        return;
      this.DeletePJ((object) this.PJ4Name.Text, (object) 4);
    }

    private void method_9(object sender, EventArgs e)
    {
      if (!Microsoft.VisualBasic.CompilerServices.Operators.ConditionalCompareObjectEqual((object) Interaction.MsgBox((object) "Delete PJ!!", MsgBoxStyle.YesNo, (object) "Delete"), (object) MsgBoxResult.Yes, false))
        return;
      this.DeletePJ((object) this.PJ5Name.Text, (object) 5);
    }

    private void method_10(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BorrarPJ1.BackgroundImage = (Image) EmbeddedResources.smethod_53();
    }

    private void method_11(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BorrarPJ1.BackgroundImage = (Image) EmbeddedResources.smethod_54();
    }

    private void method_12(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BorrarPJ2.BackgroundImage = (Image) EmbeddedResources.smethod_53();
    }

    private void method_13(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BorrarPJ2.BackgroundImage = (Image) EmbeddedResources.smethod_54();
    }

    private void method_14(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BorrarPJ3.BackgroundImage = (Image) EmbeddedResources.smethod_53();
    }

    private void method_15(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BorrarPJ3.BackgroundImage = (Image) EmbeddedResources.smethod_54();
    }

    private void method_16(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BorrarPJ4.BackgroundImage = (Image) EmbeddedResources.smethod_53();
    }

    private void method_17(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BorrarPJ4.BackgroundImage = (Image) EmbeddedResources.smethod_54();
    }

    private void method_18(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BorrarPJ5.BackgroundImage = (Image) EmbeddedResources.smethod_53();
    }

    private void method_19(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BorrarPJ5.BackgroundImage = (Image) EmbeddedResources.smethod_54();
    }

    private void method_20(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.CrearAccount.BackgroundImage = (Image) EmbeddedResources.smethod_50();
    }

    private void method_21(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.CrearAccount.BackgroundImage = (Image) EmbeddedResources.smethod_51();
    }

    private void method_22(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Aplicar.BackgroundImage = (Image) EmbeddedResources.smethod_90();
    }

    private void method_23(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Aplicar.BackgroundImage = (Image) EmbeddedResources.smethod_91();
    }

    private void method_24(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BClosed.BackgroundImage = (Image) EmbeddedResources.smethod_43();
    }

    private void method_25(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.BClosed.BackgroundImage = (Image) EmbeddedResources.smethod_46();
    }

    private void method_26(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) EmbeddedResources.smethod_43();
    }

    private void method_27(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) EmbeddedResources.smethod_46();
    }

    private void method_28(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Salir.BackgroundImage = (Image) EmbeddedResources.smethod_39();
    }

    private void method_29(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Salir.BackgroundImage = (Image) EmbeddedResources.smethod_40();
    }
  }
}
