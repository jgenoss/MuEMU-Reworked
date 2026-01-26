// Decompiled with JetBrains decompiler
// Type: Class21
// Assembly: MuMaker, Version=1.1.3.0, Culture=neutral, PublicKeyToken=null
// MVID: 7E43A6C6-04AF-4159-BD3A-BD25660D1460
// Assembly location: D:\MuServer\Tools\MuMaker 1.13\MuMaker-cleaned.exe

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using System;

[StandardModule]
internal sealed class Class21
{
  public static object smethod_0()
  {
    if (Operators.ConditionalCompareObjectEqual((object) Interaction.MsgBox(Operators.ConcatenateObject(Operators.ConcatenateObject(Operators.ConcatenateObject(Operators.ConcatenateObject((object) "Create Colum '", Class26.object_11), (object) "', in Table 'Character' in Data Base "), Class26.object_7), (object) "?"), MsgBoxStyle.YesNo, (object) "!! Reset System !!"), (object) MsgBoxResult.Yes, false))
    {
      Class7.smethod_0();
      try
      {
        Class28.sqlConnection_1.Open();
        Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
        Class28.sqlCommand_1.CommandText = Conversions.ToString(Operators.ConcatenateObject(Operators.ConcatenateObject((object) "ALTER TABLE [dbo].[Character] ADD [", Class26.object_11), (object) "] [int] NOT NULL default 0"));
        Class28.sqlDataReader_1 = Class28.sqlCommand_1.ExecuteReader();
        Class28.sqlDataReader_1.Close();
        Class18.smethod_2(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "SQL", "Reset", Conversions.ToString(Class26.object_11));
        Class18.smethod_2(Class2.smethod_1().Info.DirectoryPath + "/Config.ini", "Config", "Reset", "1");
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      Class7.smethod_5();
    }
    return (object) true;
  }

  public static object smethod_1()
  {
    Class7.smethod_0();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1)\nTRUNCATE TABLE [dbo].[MuMakerFinderMaker]\nELSE\n CREATE TABLE [dbo].[MuMakerFinderMaker] ( [ID] [bigint] IDENTITY(1,1) NOT NULL,[AC] [varchar](10) COLLATE Chinese_PRC_CI_AS NOT NULL,[PJ] [varchar](10) COLLATE Chinese_PRC_CI_AS NOT NULL,[Vault] [smallint] NOT NULL,[Invent] [smallint] NOT NULL,[ExtraW] [smallint] NOT NULL,[NumExtraW] [smallint] NOT NULL,[Pos] [smallint] NOT NULL,[Item] [varchar](32) COLLATE Chinese_PRC_CI_AS NOT NULL,[Serial] [varchar](8) COLLATE Chinese_PRC_CI_AS NOT NULL,[FullEXE] [bit] NULL,[ExeAnc] [bit] NULL,[Full380] [bit] NULL,[FullJoH] [bit] NULL,[FullScK] [bit] NULL,[CodeItems] [varchar](4000) COLLATE Chinese_PRC_CI_AS NOT NULL) ON [PRIMARY]";
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

  public static object smethod_2()
  {
    Class7.smethod_0();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1) TRUNCATE TABLE [dbo].[MuMakerFinderMaker]";
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

  public static object smethod_3()
  {
    Class7.smethod_0();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1)\nDROP TABLE [dbo].[MuMakerFinderMaker]";
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

  public static object smethod_4()
  {
    Class7.smethod_0();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1) ALTER TABLE [dbo].[MuMakerFinderMaker] ALTER COLUMN [AC] [varchar](10) COLLATE Chinese_PRC_CI_AS NOT NULL";
      Class28.sqlCommand_1.ExecuteReader();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1) ALTER TABLE [dbo].[MuMakerFinderMaker] ALTER COLUMN [PJ] [varchar](10) COLLATE Chinese_PRC_CI_AS NOT NULL";
      Class28.sqlCommand_1.ExecuteReader();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1) ALTER TABLE [dbo].[MuMakerFinderMaker] ALTER COLUMN [Vault] [smallint] NOT NULL";
      Class28.sqlCommand_1.ExecuteReader();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1) ALTER TABLE [dbo].[MuMakerFinderMaker] ALTER COLUMN [Invent] [smallint] NOT NULL";
      Class28.sqlCommand_1.ExecuteReader();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1) ALTER TABLE [dbo].[MuMakerFinderMaker] ALTER COLUMN [ExtraW] [smallint] NOT NULL";
      Class28.sqlCommand_1.ExecuteReader();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1) ALTER TABLE [dbo].[MuMakerFinderMaker] ALTER COLUMN [NumExtraW] [smallint] NOT NULL";
      Class28.sqlCommand_1.ExecuteReader();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1) ALTER TABLE [dbo].[MuMakerFinderMaker] ALTER COLUMN [Pos] [smallint] NOT NULL";
      Class28.sqlCommand_1.ExecuteReader();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1) ALTER TABLE [dbo].[MuMakerFinderMaker] ALTER COLUMN [Item] [varchar](32) COLLATE Chinese_PRC_CI_AS NOT NULL";
      Class28.sqlCommand_1.ExecuteReader();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1) ALTER TABLE [dbo].[MuMakerFinderMaker] ALTER COLUMN [Serial] [varchar](8) COLLATE Chinese_PRC_CI_AS NOT NULL";
      Class28.sqlCommand_1.ExecuteReader();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1) ALTER TABLE [dbo].[MuMakerFinderMaker] ALTER COLUMN [FullEXE] [bit] NULL";
      Class28.sqlCommand_1.ExecuteReader();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1) ALTER TABLE [dbo].[MuMakerFinderMaker] ALTER COLUMN [ExeAnc] [bit] NULL";
      Class28.sqlCommand_1.ExecuteReader();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1) ALTER TABLE [dbo].[MuMakerFinderMaker] ALTER COLUMN [Full380] [bit] NULL";
      Class28.sqlCommand_1.ExecuteReader();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1) ALTER TABLE [dbo].[MuMakerFinderMaker] ALTER COLUMN [FullJoH] [bit] NULL";
      Class28.sqlCommand_1.ExecuteReader();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1) ALTER TABLE [dbo].[MuMakerFinderMaker] ALTER COLUMN [FullScK] [bit] NULL";
      Class28.sqlCommand_1.ExecuteReader();
    }
    catch (Exception ex)
    {
      ProjectData.SetProjectError(ex);
      int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
      ProjectData.ClearProjectError();
    }
    Class7.smethod_5();
    try
    {
      Class28.sqlConnection_1.Open();
      Class28.sqlCommand_1.Connection = Class28.sqlConnection_1;
      Class28.sqlCommand_1.CommandText = "IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[dbo].[MuMakerFinderMaker]') AND OBJECTPROPERTY(id, N'IsUserTable') = 1) ALTER TABLE [dbo].[MuMakerFinderMaker] ALTER COLUMN [CodeItems] [varchar](4000) COLLATE Chinese_PRC_CI_AS NOT NULL";
      Class28.sqlCommand_1.ExecuteReader();
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
}
