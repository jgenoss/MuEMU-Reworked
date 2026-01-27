// Decompiled with JetBrains decompiler
// Type: MuMaker.MoveMaker
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
using System.Threading;
using System.Windows.Forms;

namespace MuMaker
{
  [DesignerGenerated]
  public class MoveMaker : Form
  {
    private static MoveMaker moveMaker_0 = (MoveMaker) null;
    private IContainer icontainer_0;
    [AccessedThroughProperty("Label2")]
    private Label _Label2;
    [AccessedThroughProperty("GameMaster")]
    private RadioButton _GameMaster;
    [AccessedThroughProperty("Reload")]
    private Button _Reload;
    [AccessedThroughProperty("Emergente")]
    private ToolTip toolTip_0;
    [AccessedThroughProperty("PJOnline")]
    private ListBox _PJOnline;
    [AccessedThroughProperty("PictureBox500")]
    private PictureBox _PictureBox500;
    [AccessedThroughProperty("PictureBox499")]
    private PictureBox _PictureBox499;
    [AccessedThroughProperty("PictureBox498")]
    private PictureBox _PictureBox498;
    [AccessedThroughProperty("PictureBox497")]
    private PictureBox _PictureBox497;
    [AccessedThroughProperty("PictureBox496")]
    private PictureBox _PictureBox496;
    [AccessedThroughProperty("PictureBox495")]
    private PictureBox _PictureBox495;
    [AccessedThroughProperty("PictureBox494")]
    private PictureBox _PictureBox494;
    [AccessedThroughProperty("PictureBox493")]
    private PictureBox _PictureBox493;
    [AccessedThroughProperty("PictureBox492")]
    private PictureBox _PictureBox492;
    [AccessedThroughProperty("PictureBox491")]
    private PictureBox _PictureBox491;
    [AccessedThroughProperty("PictureBox490")]
    private PictureBox _PictureBox490;
    [AccessedThroughProperty("PictureBox489")]
    private PictureBox _PictureBox489;
    [AccessedThroughProperty("PictureBox488")]
    private PictureBox _PictureBox488;
    [AccessedThroughProperty("PictureBox487")]
    private PictureBox _PictureBox487;
    [AccessedThroughProperty("PictureBox486")]
    private PictureBox _PictureBox486;
    [AccessedThroughProperty("PictureBox485")]
    private PictureBox _PictureBox485;
    [AccessedThroughProperty("PictureBox484")]
    private PictureBox _PictureBox484;
    [AccessedThroughProperty("PictureBox483")]
    private PictureBox _PictureBox483;
    [AccessedThroughProperty("PictureBox482")]
    private PictureBox _PictureBox482;
    [AccessedThroughProperty("PictureBox481")]
    private PictureBox _PictureBox481;
    [AccessedThroughProperty("PictureBox480")]
    private PictureBox _PictureBox480;
    [AccessedThroughProperty("PictureBox479")]
    private PictureBox _PictureBox479;
    [AccessedThroughProperty("PictureBox478")]
    private PictureBox _PictureBox478;
    [AccessedThroughProperty("PictureBox477")]
    private PictureBox _PictureBox477;
    [AccessedThroughProperty("PictureBox476")]
    private PictureBox _PictureBox476;
    [AccessedThroughProperty("PictureBox475")]
    private PictureBox _PictureBox475;
    [AccessedThroughProperty("PictureBox474")]
    private PictureBox _PictureBox474;
    [AccessedThroughProperty("PictureBox473")]
    private PictureBox _PictureBox473;
    [AccessedThroughProperty("PictureBox472")]
    private PictureBox _PictureBox472;
    [AccessedThroughProperty("PictureBox471")]
    private PictureBox _PictureBox471;
    [AccessedThroughProperty("PictureBox470")]
    private PictureBox _PictureBox470;
    [AccessedThroughProperty("PictureBox469")]
    private PictureBox _PictureBox469;
    [AccessedThroughProperty("PictureBox468")]
    private PictureBox _PictureBox468;
    [AccessedThroughProperty("PictureBox467")]
    private PictureBox _PictureBox467;
    [AccessedThroughProperty("PictureBox466")]
    private PictureBox _PictureBox466;
    [AccessedThroughProperty("PictureBox465")]
    private PictureBox _PictureBox465;
    [AccessedThroughProperty("PictureBox464")]
    private PictureBox _PictureBox464;
    [AccessedThroughProperty("PictureBox463")]
    private PictureBox _PictureBox463;
    [AccessedThroughProperty("PictureBox462")]
    private PictureBox _PictureBox462;
    [AccessedThroughProperty("PictureBox461")]
    private PictureBox _PictureBox461;
    [AccessedThroughProperty("PictureBox460")]
    private PictureBox _PictureBox460;
    [AccessedThroughProperty("PictureBox459")]
    private PictureBox _PictureBox459;
    [AccessedThroughProperty("PictureBox458")]
    private PictureBox _PictureBox458;
    [AccessedThroughProperty("PictureBox457")]
    private PictureBox _PictureBox457;
    [AccessedThroughProperty("PictureBox456")]
    private PictureBox _PictureBox456;
    [AccessedThroughProperty("PictureBox455")]
    private PictureBox _PictureBox455;
    [AccessedThroughProperty("PictureBox454")]
    private PictureBox _PictureBox454;
    [AccessedThroughProperty("PictureBox453")]
    private PictureBox _PictureBox453;
    [AccessedThroughProperty("PictureBox452")]
    private PictureBox _PictureBox452;
    [AccessedThroughProperty("PictureBox451")]
    private PictureBox _PictureBox451;
    [AccessedThroughProperty("Label23")]
    private Label _Label23;
    [AccessedThroughProperty("PictureBox450")]
    private PictureBox _PictureBox450;
    [AccessedThroughProperty("PictureBox449")]
    private PictureBox _PictureBox449;
    [AccessedThroughProperty("PictureBox225")]
    private PictureBox _PictureBox225;
    [AccessedThroughProperty("PictureBox226")]
    private PictureBox _PictureBox226;
    [AccessedThroughProperty("PictureBox227")]
    private PictureBox _PictureBox227;
    [AccessedThroughProperty("PictureBox228")]
    private PictureBox _PictureBox228;
    [AccessedThroughProperty("PictureBox229")]
    private PictureBox _PictureBox229;
    [AccessedThroughProperty("PictureBox230")]
    private PictureBox _PictureBox230;
    [AccessedThroughProperty("PictureBox231")]
    private PictureBox _PictureBox231;
    [AccessedThroughProperty("PictureBox232")]
    private PictureBox _PictureBox232;
    [AccessedThroughProperty("PictureBox233")]
    private PictureBox _PictureBox233;
    [AccessedThroughProperty("PictureBox234")]
    private PictureBox _PictureBox234;
    [AccessedThroughProperty("PictureBox235")]
    private PictureBox _PictureBox235;
    [AccessedThroughProperty("PictureBox236")]
    private PictureBox _PictureBox236;
    [AccessedThroughProperty("PictureBox237")]
    private PictureBox _PictureBox237;
    [AccessedThroughProperty("PictureBox238")]
    private PictureBox _PictureBox238;
    [AccessedThroughProperty("PictureBox239")]
    private PictureBox _PictureBox239;
    [AccessedThroughProperty("PictureBox240")]
    private PictureBox _PictureBox240;
    [AccessedThroughProperty("PictureBox241")]
    private PictureBox _PictureBox241;
    [AccessedThroughProperty("PictureBox242")]
    private PictureBox _PictureBox242;
    [AccessedThroughProperty("PictureBox243")]
    private PictureBox _PictureBox243;
    [AccessedThroughProperty("PictureBox244")]
    private PictureBox _PictureBox244;
    [AccessedThroughProperty("PictureBox245")]
    private PictureBox _PictureBox245;
    [AccessedThroughProperty("PictureBox246")]
    private PictureBox _PictureBox246;
    [AccessedThroughProperty("PictureBox247")]
    private PictureBox _PictureBox247;
    [AccessedThroughProperty("PictureBox248")]
    private PictureBox _PictureBox248;
    [AccessedThroughProperty("PictureBox249")]
    private PictureBox _PictureBox249;
    [AccessedThroughProperty("PictureBox250")]
    private PictureBox _PictureBox250;
    [AccessedThroughProperty("PictureBox251")]
    private PictureBox _PictureBox251;
    [AccessedThroughProperty("PictureBox252")]
    private PictureBox _PictureBox252;
    [AccessedThroughProperty("PictureBox253")]
    private PictureBox _PictureBox253;
    [AccessedThroughProperty("PictureBox254")]
    private PictureBox _PictureBox254;
    [AccessedThroughProperty("PictureBox255")]
    private PictureBox _PictureBox255;
    [AccessedThroughProperty("PictureBox256")]
    private PictureBox _PictureBox256;
    [AccessedThroughProperty("PictureBox257")]
    private PictureBox _PictureBox257;
    [AccessedThroughProperty("PictureBox258")]
    private PictureBox _PictureBox258;
    [AccessedThroughProperty("PictureBox259")]
    private PictureBox _PictureBox259;
    [AccessedThroughProperty("PictureBox260")]
    private PictureBox _PictureBox260;
    [AccessedThroughProperty("PictureBox261")]
    private PictureBox _PictureBox261;
    [AccessedThroughProperty("PictureBox262")]
    private PictureBox _PictureBox262;
    [AccessedThroughProperty("PictureBox263")]
    private PictureBox _PictureBox263;
    [AccessedThroughProperty("PictureBox264")]
    private PictureBox _PictureBox264;
    [AccessedThroughProperty("PictureBox265")]
    private PictureBox _PictureBox265;
    [AccessedThroughProperty("PictureBox266")]
    private PictureBox _PictureBox266;
    [AccessedThroughProperty("PictureBox267")]
    private PictureBox _PictureBox267;
    [AccessedThroughProperty("PictureBox268")]
    private PictureBox _PictureBox268;
    [AccessedThroughProperty("PictureBox269")]
    private PictureBox _PictureBox269;
    [AccessedThroughProperty("PictureBox270")]
    private PictureBox _PictureBox270;
    [AccessedThroughProperty("PictureBox271")]
    private PictureBox _PictureBox271;
    [AccessedThroughProperty("PictureBox272")]
    private PictureBox _PictureBox272;
    [AccessedThroughProperty("PictureBox273")]
    private PictureBox _PictureBox273;
    [AccessedThroughProperty("PictureBox274")]
    private PictureBox _PictureBox274;
    [AccessedThroughProperty("PictureBox275")]
    private PictureBox _PictureBox275;
    [AccessedThroughProperty("PictureBox276")]
    private PictureBox _PictureBox276;
    [AccessedThroughProperty("PictureBox277")]
    private PictureBox _PictureBox277;
    [AccessedThroughProperty("PictureBox278")]
    private PictureBox _PictureBox278;
    [AccessedThroughProperty("PictureBox279")]
    private PictureBox _PictureBox279;
    [AccessedThroughProperty("PictureBox280")]
    private PictureBox _PictureBox280;
    [AccessedThroughProperty("PictureBox281")]
    private PictureBox _PictureBox281;
    [AccessedThroughProperty("PictureBox282")]
    private PictureBox _PictureBox282;
    [AccessedThroughProperty("PictureBox283")]
    private PictureBox _PictureBox283;
    [AccessedThroughProperty("PictureBox284")]
    private PictureBox _PictureBox284;
    [AccessedThroughProperty("PictureBox285")]
    private PictureBox _PictureBox285;
    [AccessedThroughProperty("PictureBox286")]
    private PictureBox _PictureBox286;
    [AccessedThroughProperty("PictureBox287")]
    private PictureBox _PictureBox287;
    [AccessedThroughProperty("PictureBox288")]
    private PictureBox _PictureBox288;
    [AccessedThroughProperty("PictureBox289")]
    private PictureBox _PictureBox289;
    [AccessedThroughProperty("PictureBox290")]
    private PictureBox _PictureBox290;
    [AccessedThroughProperty("PictureBox291")]
    private PictureBox _PictureBox291;
    [AccessedThroughProperty("PictureBox292")]
    private PictureBox _PictureBox292;
    [AccessedThroughProperty("PictureBox293")]
    private PictureBox _PictureBox293;
    [AccessedThroughProperty("PictureBox294")]
    private PictureBox _PictureBox294;
    [AccessedThroughProperty("PictureBox295")]
    private PictureBox _PictureBox295;
    [AccessedThroughProperty("PictureBox296")]
    private PictureBox _PictureBox296;
    [AccessedThroughProperty("PictureBox297")]
    private PictureBox _PictureBox297;
    [AccessedThroughProperty("PictureBox298")]
    private PictureBox _PictureBox298;
    [AccessedThroughProperty("PictureBox299")]
    private PictureBox _PictureBox299;
    [AccessedThroughProperty("PictureBox300")]
    private PictureBox _PictureBox300;
    [AccessedThroughProperty("PictureBox301")]
    private PictureBox _PictureBox301;
    [AccessedThroughProperty("PictureBox302")]
    private PictureBox _PictureBox302;
    [AccessedThroughProperty("PictureBox303")]
    private PictureBox _PictureBox303;
    [AccessedThroughProperty("PictureBox304")]
    private PictureBox _PictureBox304;
    [AccessedThroughProperty("PictureBox305")]
    private PictureBox _PictureBox305;
    [AccessedThroughProperty("PictureBox306")]
    private PictureBox _PictureBox306;
    [AccessedThroughProperty("PictureBox307")]
    private PictureBox _PictureBox307;
    [AccessedThroughProperty("PictureBox308")]
    private PictureBox _PictureBox308;
    [AccessedThroughProperty("PictureBox309")]
    private PictureBox _PictureBox309;
    [AccessedThroughProperty("PictureBox310")]
    private PictureBox _PictureBox310;
    [AccessedThroughProperty("PictureBox311")]
    private PictureBox _PictureBox311;
    [AccessedThroughProperty("PictureBox312")]
    private PictureBox _PictureBox312;
    [AccessedThroughProperty("PictureBox313")]
    private PictureBox _PictureBox313;
    [AccessedThroughProperty("PictureBox314")]
    private PictureBox _PictureBox314;
    [AccessedThroughProperty("PictureBox315")]
    private PictureBox _PictureBox315;
    [AccessedThroughProperty("PictureBox316")]
    private PictureBox _PictureBox316;
    [AccessedThroughProperty("PictureBox317")]
    private PictureBox _PictureBox317;
    [AccessedThroughProperty("PictureBox318")]
    private PictureBox _PictureBox318;
    [AccessedThroughProperty("PictureBox319")]
    private PictureBox _PictureBox319;
    [AccessedThroughProperty("PictureBox320")]
    private PictureBox _PictureBox320;
    [AccessedThroughProperty("PictureBox321")]
    private PictureBox _PictureBox321;
    [AccessedThroughProperty("PictureBox322")]
    private PictureBox _PictureBox322;
    [AccessedThroughProperty("PictureBox323")]
    private PictureBox _PictureBox323;
    [AccessedThroughProperty("PictureBox324")]
    private PictureBox _PictureBox324;
    [AccessedThroughProperty("PictureBox325")]
    private PictureBox _PictureBox325;
    [AccessedThroughProperty("PictureBox326")]
    private PictureBox _PictureBox326;
    [AccessedThroughProperty("PictureBox327")]
    private PictureBox _PictureBox327;
    [AccessedThroughProperty("PictureBox328")]
    private PictureBox _PictureBox328;
    [AccessedThroughProperty("PictureBox329")]
    private PictureBox _PictureBox329;
    [AccessedThroughProperty("PictureBox330")]
    private PictureBox _PictureBox330;
    [AccessedThroughProperty("PictureBox331")]
    private PictureBox _PictureBox331;
    [AccessedThroughProperty("PictureBox332")]
    private PictureBox _PictureBox332;
    [AccessedThroughProperty("PictureBox333")]
    private PictureBox _PictureBox333;
    [AccessedThroughProperty("PictureBox334")]
    private PictureBox _PictureBox334;
    [AccessedThroughProperty("PictureBox335")]
    private PictureBox _PictureBox335;
    [AccessedThroughProperty("PictureBox336")]
    private PictureBox _PictureBox336;
    [AccessedThroughProperty("PictureBox337")]
    private PictureBox _PictureBox337;
    [AccessedThroughProperty("PictureBox338")]
    private PictureBox _PictureBox338;
    [AccessedThroughProperty("PictureBox339")]
    private PictureBox _PictureBox339;
    [AccessedThroughProperty("PictureBox340")]
    private PictureBox _PictureBox340;
    [AccessedThroughProperty("PictureBox341")]
    private PictureBox _PictureBox341;
    [AccessedThroughProperty("PictureBox342")]
    private PictureBox _PictureBox342;
    [AccessedThroughProperty("PictureBox343")]
    private PictureBox _PictureBox343;
    [AccessedThroughProperty("PictureBox344")]
    private PictureBox _PictureBox344;
    [AccessedThroughProperty("PictureBox345")]
    private PictureBox _PictureBox345;
    [AccessedThroughProperty("PictureBox346")]
    private PictureBox _PictureBox346;
    [AccessedThroughProperty("PictureBox347")]
    private PictureBox _PictureBox347;
    [AccessedThroughProperty("PictureBox348")]
    private PictureBox _PictureBox348;
    [AccessedThroughProperty("PictureBox349")]
    private PictureBox _PictureBox349;
    [AccessedThroughProperty("PictureBox350")]
    private PictureBox _PictureBox350;
    [AccessedThroughProperty("PictureBox351")]
    private PictureBox _PictureBox351;
    [AccessedThroughProperty("PictureBox352")]
    private PictureBox _PictureBox352;
    [AccessedThroughProperty("PictureBox353")]
    private PictureBox _PictureBox353;
    [AccessedThroughProperty("PictureBox354")]
    private PictureBox _PictureBox354;
    [AccessedThroughProperty("PictureBox355")]
    private PictureBox _PictureBox355;
    [AccessedThroughProperty("PictureBox356")]
    private PictureBox _PictureBox356;
    [AccessedThroughProperty("PictureBox357")]
    private PictureBox _PictureBox357;
    [AccessedThroughProperty("PictureBox358")]
    private PictureBox _PictureBox358;
    [AccessedThroughProperty("PictureBox359")]
    private PictureBox _PictureBox359;
    [AccessedThroughProperty("PictureBox360")]
    private PictureBox _PictureBox360;
    [AccessedThroughProperty("PictureBox361")]
    private PictureBox _PictureBox361;
    [AccessedThroughProperty("PictureBox362")]
    private PictureBox _PictureBox362;
    [AccessedThroughProperty("PictureBox363")]
    private PictureBox _PictureBox363;
    [AccessedThroughProperty("PictureBox364")]
    private PictureBox _PictureBox364;
    [AccessedThroughProperty("PictureBox365")]
    private PictureBox _PictureBox365;
    [AccessedThroughProperty("PictureBox366")]
    private PictureBox _PictureBox366;
    [AccessedThroughProperty("PictureBox367")]
    private PictureBox _PictureBox367;
    [AccessedThroughProperty("PictureBox368")]
    private PictureBox _PictureBox368;
    [AccessedThroughProperty("PictureBox369")]
    private PictureBox _PictureBox369;
    [AccessedThroughProperty("PictureBox370")]
    private PictureBox _PictureBox370;
    [AccessedThroughProperty("PictureBox371")]
    private PictureBox _PictureBox371;
    [AccessedThroughProperty("PictureBox372")]
    private PictureBox _PictureBox372;
    [AccessedThroughProperty("PictureBox373")]
    private PictureBox _PictureBox373;
    [AccessedThroughProperty("PictureBox374")]
    private PictureBox _PictureBox374;
    [AccessedThroughProperty("PictureBox375")]
    private PictureBox _PictureBox375;
    [AccessedThroughProperty("PictureBox376")]
    private PictureBox _PictureBox376;
    [AccessedThroughProperty("PictureBox377")]
    private PictureBox _PictureBox377;
    [AccessedThroughProperty("PictureBox378")]
    private PictureBox _PictureBox378;
    [AccessedThroughProperty("PictureBox379")]
    private PictureBox _PictureBox379;
    [AccessedThroughProperty("PictureBox380")]
    private PictureBox _PictureBox380;
    [AccessedThroughProperty("PictureBox381")]
    private PictureBox _PictureBox381;
    [AccessedThroughProperty("PictureBox382")]
    private PictureBox _PictureBox382;
    [AccessedThroughProperty("PictureBox383")]
    private PictureBox _PictureBox383;
    [AccessedThroughProperty("PictureBox384")]
    private PictureBox _PictureBox384;
    [AccessedThroughProperty("PictureBox385")]
    private PictureBox _PictureBox385;
    [AccessedThroughProperty("PictureBox386")]
    private PictureBox _PictureBox386;
    [AccessedThroughProperty("PictureBox387")]
    private PictureBox _PictureBox387;
    [AccessedThroughProperty("PictureBox388")]
    private PictureBox _PictureBox388;
    [AccessedThroughProperty("PictureBox389")]
    private PictureBox _PictureBox389;
    [AccessedThroughProperty("PictureBox390")]
    private PictureBox _PictureBox390;
    [AccessedThroughProperty("PictureBox391")]
    private PictureBox _PictureBox391;
    [AccessedThroughProperty("PictureBox392")]
    private PictureBox _PictureBox392;
    [AccessedThroughProperty("PictureBox393")]
    private PictureBox _PictureBox393;
    [AccessedThroughProperty("PictureBox394")]
    private PictureBox _PictureBox394;
    [AccessedThroughProperty("PictureBox395")]
    private PictureBox _PictureBox395;
    [AccessedThroughProperty("PictureBox396")]
    private PictureBox _PictureBox396;
    [AccessedThroughProperty("PictureBox397")]
    private PictureBox _PictureBox397;
    [AccessedThroughProperty("PictureBox398")]
    private PictureBox _PictureBox398;
    [AccessedThroughProperty("PictureBox399")]
    private PictureBox _PictureBox399;
    [AccessedThroughProperty("PictureBox400")]
    private PictureBox _PictureBox400;
    [AccessedThroughProperty("PictureBox401")]
    private PictureBox _PictureBox401;
    [AccessedThroughProperty("PictureBox402")]
    private PictureBox _PictureBox402;
    [AccessedThroughProperty("PictureBox403")]
    private PictureBox _PictureBox403;
    [AccessedThroughProperty("PictureBox404")]
    private PictureBox _PictureBox404;
    [AccessedThroughProperty("PictureBox405")]
    private PictureBox _PictureBox405;
    [AccessedThroughProperty("PictureBox406")]
    private PictureBox _PictureBox406;
    [AccessedThroughProperty("PictureBox407")]
    private PictureBox _PictureBox407;
    [AccessedThroughProperty("PictureBox408")]
    private PictureBox _PictureBox408;
    [AccessedThroughProperty("PictureBox409")]
    private PictureBox _PictureBox409;
    [AccessedThroughProperty("PictureBox410")]
    private PictureBox _PictureBox410;
    [AccessedThroughProperty("PictureBox411")]
    private PictureBox _PictureBox411;
    [AccessedThroughProperty("PictureBox412")]
    private PictureBox _PictureBox412;
    [AccessedThroughProperty("PictureBox413")]
    private PictureBox _PictureBox413;
    [AccessedThroughProperty("PictureBox414")]
    private PictureBox _PictureBox414;
    [AccessedThroughProperty("PictureBox415")]
    private PictureBox _PictureBox415;
    [AccessedThroughProperty("PictureBox416")]
    private PictureBox _PictureBox416;
    [AccessedThroughProperty("PictureBox417")]
    private PictureBox _PictureBox417;
    [AccessedThroughProperty("PictureBox418")]
    private PictureBox _PictureBox418;
    [AccessedThroughProperty("PictureBox419")]
    private PictureBox _PictureBox419;
    [AccessedThroughProperty("PictureBox420")]
    private PictureBox _PictureBox420;
    [AccessedThroughProperty("PictureBox421")]
    private PictureBox _PictureBox421;
    [AccessedThroughProperty("PictureBox422")]
    private PictureBox _PictureBox422;
    [AccessedThroughProperty("PictureBox423")]
    private PictureBox _PictureBox423;
    [AccessedThroughProperty("PictureBox424")]
    private PictureBox _PictureBox424;
    [AccessedThroughProperty("PictureBox425")]
    private PictureBox _PictureBox425;
    [AccessedThroughProperty("PictureBox426")]
    private PictureBox _PictureBox426;
    [AccessedThroughProperty("PictureBox427")]
    private PictureBox _PictureBox427;
    [AccessedThroughProperty("PictureBox428")]
    private PictureBox _PictureBox428;
    [AccessedThroughProperty("PictureBox429")]
    private PictureBox _PictureBox429;
    [AccessedThroughProperty("PictureBox430")]
    private PictureBox _PictureBox430;
    [AccessedThroughProperty("PictureBox431")]
    private PictureBox _PictureBox431;
    [AccessedThroughProperty("PictureBox432")]
    private PictureBox _PictureBox432;
    [AccessedThroughProperty("PictureBox433")]
    private PictureBox _PictureBox433;
    [AccessedThroughProperty("PictureBox434")]
    private PictureBox _PictureBox434;
    [AccessedThroughProperty("PictureBox435")]
    private PictureBox _PictureBox435;
    [AccessedThroughProperty("PictureBox436")]
    private PictureBox _PictureBox436;
    [AccessedThroughProperty("PictureBox437")]
    private PictureBox _PictureBox437;
    [AccessedThroughProperty("PictureBox438")]
    private PictureBox _PictureBox438;
    [AccessedThroughProperty("PictureBox439")]
    private PictureBox _PictureBox439;
    [AccessedThroughProperty("PictureBox440")]
    private PictureBox _PictureBox440;
    [AccessedThroughProperty("PictureBox441")]
    private PictureBox _PictureBox441;
    [AccessedThroughProperty("PictureBox442")]
    private PictureBox _PictureBox442;
    [AccessedThroughProperty("PictureBox443")]
    private PictureBox _PictureBox443;
    [AccessedThroughProperty("PictureBox444")]
    private PictureBox _PictureBox444;
    [AccessedThroughProperty("PictureBox445")]
    private PictureBox _PictureBox445;
    [AccessedThroughProperty("PictureBox446")]
    private PictureBox _PictureBox446;
    [AccessedThroughProperty("PictureBox447")]
    private PictureBox _PictureBox447;
    [AccessedThroughProperty("PictureBox448")]
    private PictureBox _PictureBox448;
    [AccessedThroughProperty("PictureBox113")]
    private PictureBox _PictureBox113;
    [AccessedThroughProperty("PictureBox114")]
    private PictureBox _PictureBox114;
    [AccessedThroughProperty("PictureBox115")]
    private PictureBox _PictureBox115;
    [AccessedThroughProperty("PictureBox116")]
    private PictureBox _PictureBox116;
    [AccessedThroughProperty("PictureBox117")]
    private PictureBox _PictureBox117;
    [AccessedThroughProperty("PictureBox118")]
    private PictureBox _PictureBox118;
    [AccessedThroughProperty("PictureBox119")]
    private PictureBox _PictureBox119;
    [AccessedThroughProperty("PictureBox120")]
    private PictureBox _PictureBox120;
    [AccessedThroughProperty("PictureBox121")]
    private PictureBox _PictureBox121;
    [AccessedThroughProperty("PictureBox122")]
    private PictureBox _PictureBox122;
    [AccessedThroughProperty("PictureBox123")]
    private PictureBox _PictureBox123;
    [AccessedThroughProperty("PictureBox124")]
    private PictureBox _PictureBox124;
    [AccessedThroughProperty("PictureBox125")]
    private PictureBox _PictureBox125;
    [AccessedThroughProperty("PictureBox126")]
    private PictureBox _PictureBox126;
    [AccessedThroughProperty("PictureBox127")]
    private PictureBox _PictureBox127;
    [AccessedThroughProperty("PictureBox128")]
    private PictureBox _PictureBox128;
    [AccessedThroughProperty("PictureBox129")]
    private PictureBox _PictureBox129;
    [AccessedThroughProperty("PictureBox130")]
    private PictureBox _PictureBox130;
    [AccessedThroughProperty("PictureBox131")]
    private PictureBox _PictureBox131;
    [AccessedThroughProperty("PictureBox132")]
    private PictureBox _PictureBox132;
    [AccessedThroughProperty("PictureBox133")]
    private PictureBox _PictureBox133;
    [AccessedThroughProperty("PictureBox134")]
    private PictureBox _PictureBox134;
    [AccessedThroughProperty("PictureBox135")]
    private PictureBox _PictureBox135;
    [AccessedThroughProperty("PictureBox136")]
    private PictureBox _PictureBox136;
    [AccessedThroughProperty("PictureBox137")]
    private PictureBox _PictureBox137;
    [AccessedThroughProperty("PictureBox138")]
    private PictureBox _PictureBox138;
    [AccessedThroughProperty("PictureBox139")]
    private PictureBox _PictureBox139;
    [AccessedThroughProperty("PictureBox140")]
    private PictureBox _PictureBox140;
    [AccessedThroughProperty("PictureBox141")]
    private PictureBox _PictureBox141;
    [AccessedThroughProperty("PictureBox142")]
    private PictureBox _PictureBox142;
    [AccessedThroughProperty("PictureBox143")]
    private PictureBox _PictureBox143;
    [AccessedThroughProperty("PictureBox144")]
    private PictureBox _PictureBox144;
    [AccessedThroughProperty("PictureBox145")]
    private PictureBox _PictureBox145;
    [AccessedThroughProperty("PictureBox146")]
    private PictureBox _PictureBox146;
    [AccessedThroughProperty("PictureBox147")]
    private PictureBox _PictureBox147;
    [AccessedThroughProperty("PictureBox148")]
    private PictureBox _PictureBox148;
    [AccessedThroughProperty("PictureBox149")]
    private PictureBox _PictureBox149;
    [AccessedThroughProperty("PictureBox150")]
    private PictureBox _PictureBox150;
    [AccessedThroughProperty("PictureBox151")]
    private PictureBox _PictureBox151;
    [AccessedThroughProperty("PictureBox152")]
    private PictureBox _PictureBox152;
    [AccessedThroughProperty("PictureBox153")]
    private PictureBox _PictureBox153;
    [AccessedThroughProperty("PictureBox154")]
    private PictureBox _PictureBox154;
    [AccessedThroughProperty("PictureBox155")]
    private PictureBox _PictureBox155;
    [AccessedThroughProperty("PictureBox156")]
    private PictureBox _PictureBox156;
    [AccessedThroughProperty("PictureBox157")]
    private PictureBox _PictureBox157;
    [AccessedThroughProperty("PictureBox158")]
    private PictureBox _PictureBox158;
    [AccessedThroughProperty("PictureBox159")]
    private PictureBox _PictureBox159;
    [AccessedThroughProperty("PictureBox160")]
    private PictureBox _PictureBox160;
    [AccessedThroughProperty("PictureBox161")]
    private PictureBox _PictureBox161;
    [AccessedThroughProperty("PictureBox162")]
    private PictureBox _PictureBox162;
    [AccessedThroughProperty("PictureBox163")]
    private PictureBox _PictureBox163;
    [AccessedThroughProperty("PictureBox164")]
    private PictureBox _PictureBox164;
    [AccessedThroughProperty("PictureBox165")]
    private PictureBox _PictureBox165;
    [AccessedThroughProperty("PictureBox166")]
    private PictureBox _PictureBox166;
    [AccessedThroughProperty("PictureBox167")]
    private PictureBox _PictureBox167;
    [AccessedThroughProperty("PictureBox168")]
    private PictureBox _PictureBox168;
    [AccessedThroughProperty("PictureBox169")]
    private PictureBox _PictureBox169;
    [AccessedThroughProperty("PictureBox170")]
    private PictureBox _PictureBox170;
    [AccessedThroughProperty("PictureBox171")]
    private PictureBox _PictureBox171;
    [AccessedThroughProperty("PictureBox172")]
    private PictureBox _PictureBox172;
    [AccessedThroughProperty("PictureBox173")]
    private PictureBox _PictureBox173;
    [AccessedThroughProperty("PictureBox174")]
    private PictureBox _PictureBox174;
    [AccessedThroughProperty("PictureBox175")]
    private PictureBox _PictureBox175;
    [AccessedThroughProperty("PictureBox176")]
    private PictureBox _PictureBox176;
    [AccessedThroughProperty("PictureBox177")]
    private PictureBox _PictureBox177;
    [AccessedThroughProperty("PictureBox178")]
    private PictureBox _PictureBox178;
    [AccessedThroughProperty("PictureBox179")]
    private PictureBox _PictureBox179;
    [AccessedThroughProperty("PictureBox180")]
    private PictureBox _PictureBox180;
    [AccessedThroughProperty("PictureBox181")]
    private PictureBox _PictureBox181;
    [AccessedThroughProperty("PictureBox182")]
    private PictureBox _PictureBox182;
    [AccessedThroughProperty("PictureBox183")]
    private PictureBox _PictureBox183;
    [AccessedThroughProperty("PictureBox184")]
    private PictureBox _PictureBox184;
    [AccessedThroughProperty("PictureBox185")]
    private PictureBox _PictureBox185;
    [AccessedThroughProperty("PictureBox186")]
    private PictureBox _PictureBox186;
    [AccessedThroughProperty("PictureBox187")]
    private PictureBox _PictureBox187;
    [AccessedThroughProperty("PictureBox188")]
    private PictureBox _PictureBox188;
    [AccessedThroughProperty("PictureBox189")]
    private PictureBox _PictureBox189;
    [AccessedThroughProperty("PictureBox190")]
    private PictureBox _PictureBox190;
    [AccessedThroughProperty("PictureBox191")]
    private PictureBox _PictureBox191;
    [AccessedThroughProperty("PictureBox192")]
    private PictureBox _PictureBox192;
    [AccessedThroughProperty("PictureBox193")]
    private PictureBox _PictureBox193;
    [AccessedThroughProperty("PictureBox194")]
    private PictureBox _PictureBox194;
    [AccessedThroughProperty("PictureBox195")]
    private PictureBox _PictureBox195;
    [AccessedThroughProperty("PictureBox196")]
    private PictureBox _PictureBox196;
    [AccessedThroughProperty("PictureBox197")]
    private PictureBox _PictureBox197;
    [AccessedThroughProperty("PictureBox198")]
    private PictureBox _PictureBox198;
    [AccessedThroughProperty("PictureBox199")]
    private PictureBox _PictureBox199;
    [AccessedThroughProperty("PictureBox200")]
    private PictureBox _PictureBox200;
    [AccessedThroughProperty("PictureBox201")]
    private PictureBox _PictureBox201;
    [AccessedThroughProperty("PictureBox202")]
    private PictureBox _PictureBox202;
    [AccessedThroughProperty("PictureBox203")]
    private PictureBox _PictureBox203;
    [AccessedThroughProperty("PictureBox204")]
    private PictureBox _PictureBox204;
    [AccessedThroughProperty("PictureBox205")]
    private PictureBox _PictureBox205;
    [AccessedThroughProperty("PictureBox206")]
    private PictureBox _PictureBox206;
    [AccessedThroughProperty("PictureBox207")]
    private PictureBox _PictureBox207;
    [AccessedThroughProperty("PictureBox208")]
    private PictureBox _PictureBox208;
    [AccessedThroughProperty("PictureBox209")]
    private PictureBox _PictureBox209;
    [AccessedThroughProperty("PictureBox210")]
    private PictureBox _PictureBox210;
    [AccessedThroughProperty("PictureBox211")]
    private PictureBox _PictureBox211;
    [AccessedThroughProperty("PictureBox212")]
    private PictureBox _PictureBox212;
    [AccessedThroughProperty("PictureBox213")]
    private PictureBox _PictureBox213;
    [AccessedThroughProperty("PictureBox214")]
    private PictureBox _PictureBox214;
    [AccessedThroughProperty("PictureBox215")]
    private PictureBox _PictureBox215;
    [AccessedThroughProperty("PictureBox216")]
    private PictureBox _PictureBox216;
    [AccessedThroughProperty("PictureBox217")]
    private PictureBox _PictureBox217;
    [AccessedThroughProperty("PictureBox218")]
    private PictureBox _PictureBox218;
    [AccessedThroughProperty("PictureBox219")]
    private PictureBox _PictureBox219;
    [AccessedThroughProperty("PictureBox220")]
    private PictureBox _PictureBox220;
    [AccessedThroughProperty("PictureBox221")]
    private PictureBox _PictureBox221;
    [AccessedThroughProperty("Chart")]
    private Label _Chart;
    [AccessedThroughProperty("Acount")]
    private TextBox _Acount;
    [AccessedThroughProperty("Baneado")]
    private TextBox _Baneado;
    [AccessedThroughProperty("BanUnBan")]
    private Button _BanUnBan;
    [AccessedThroughProperty("level")]
    private TextBox _level;
    [AccessedThroughProperty("PN")]
    private CheckBox _PN;
    [AccessedThroughProperty("Account")]
    private Label _Account;
    [AccessedThroughProperty("Label6")]
    private Label _Label6;
    [AccessedThroughProperty("Label4")]
    private Label _Label4;
    [AccessedThroughProperty("Label5")]
    private Label _Label5;
    [AccessedThroughProperty("Personajes")]
    private TextBox _Personajes;
    [AccessedThroughProperty("OnlineOFF")]
    private PictureBox _OnlineOFF;
    [AccessedThroughProperty("OnlineON")]
    private PictureBox _OnlineON;
    [AccessedThroughProperty("Desconectador")]
    private Button _Desconectador;
    [AccessedThroughProperty("Label10")]
    private Label _Label10;
    [AccessedThroughProperty("Label11")]
    private Label _Label11;
    [AccessedThroughProperty("PictureBox223")]
    private PictureBox _PictureBox223;
    [AccessedThroughProperty("PictureBox222")]
    private PictureBox _PictureBox222;
    [AccessedThroughProperty("Label9")]
    private Label _Label9;
    [AccessedThroughProperty("Label8")]
    private Label _Label8;
    [AccessedThroughProperty("Aplicar")]
    private Button _Aplicar;
    [AccessedThroughProperty("Label16")]
    private Label _Label16;
    [AccessedThroughProperty("Label15")]
    private Label _Label15;
    [AccessedThroughProperty("Label14")]
    private Label _Label14;
    [AccessedThroughProperty("PH")]
    private CheckBox _PH;
    [AccessedThroughProperty("Label12")]
    private Label _Label12;
    [AccessedThroughProperty("PK")]
    private CheckBox _PK;
    [AccessedThroughProperty("Label13")]
    private Label _Label13;
    [AccessedThroughProperty("PictureBox224")]
    private PictureBox _PictureBox224;
    [AccessedThroughProperty("PictureBox57")]
    private PictureBox _PictureBox57;
    [AccessedThroughProperty("PictureBox58")]
    private PictureBox _PictureBox58;
    [AccessedThroughProperty("PictureBox59")]
    private PictureBox _PictureBox59;
    [AccessedThroughProperty("PictureBox60")]
    private PictureBox _PictureBox60;
    [AccessedThroughProperty("PictureBox61")]
    private PictureBox _PictureBox61;
    [AccessedThroughProperty("PictureBox62")]
    private PictureBox _PictureBox62;
    [AccessedThroughProperty("PictureBox63")]
    private PictureBox _PictureBox63;
    [AccessedThroughProperty("PictureBox64")]
    private PictureBox _PictureBox64;
    [AccessedThroughProperty("PictureBox65")]
    private PictureBox _PictureBox65;
    [AccessedThroughProperty("PictureBox66")]
    private PictureBox _PictureBox66;
    [AccessedThroughProperty("PictureBox67")]
    private PictureBox _PictureBox67;
    [AccessedThroughProperty("PictureBox68")]
    private PictureBox _PictureBox68;
    [AccessedThroughProperty("PictureBox69")]
    private PictureBox _PictureBox69;
    [AccessedThroughProperty("PictureBox70")]
    private PictureBox _PictureBox70;
    [AccessedThroughProperty("PictureBox71")]
    private PictureBox _PictureBox71;
    [AccessedThroughProperty("PictureBox72")]
    private PictureBox _PictureBox72;
    [AccessedThroughProperty("PictureBox73")]
    private PictureBox _PictureBox73;
    [AccessedThroughProperty("PictureBox74")]
    private PictureBox _PictureBox74;
    [AccessedThroughProperty("PictureBox75")]
    private PictureBox _PictureBox75;
    [AccessedThroughProperty("PictureBox76")]
    private PictureBox _PictureBox76;
    [AccessedThroughProperty("PictureBox77")]
    private PictureBox _PictureBox77;
    [AccessedThroughProperty("PictureBox78")]
    private PictureBox _PictureBox78;
    [AccessedThroughProperty("PictureBox79")]
    private PictureBox _PictureBox79;
    [AccessedThroughProperty("PictureBox80")]
    private PictureBox _PictureBox80;
    [AccessedThroughProperty("PictureBox81")]
    private PictureBox _PictureBox81;
    [AccessedThroughProperty("PictureBox82")]
    private PictureBox _PictureBox82;
    [AccessedThroughProperty("PictureBox83")]
    private PictureBox _PictureBox83;
    [AccessedThroughProperty("PictureBox84")]
    private PictureBox _PictureBox84;
    [AccessedThroughProperty("PictureBox85")]
    private PictureBox _PictureBox85;
    [AccessedThroughProperty("PictureBox86")]
    private PictureBox _PictureBox86;
    [AccessedThroughProperty("PictureBox87")]
    private PictureBox _PictureBox87;
    [AccessedThroughProperty("PictureBox88")]
    private PictureBox _PictureBox88;
    [AccessedThroughProperty("PictureBox89")]
    private PictureBox _PictureBox89;
    [AccessedThroughProperty("PictureBox90")]
    private PictureBox _PictureBox90;
    [AccessedThroughProperty("PictureBox91")]
    private PictureBox _PictureBox91;
    [AccessedThroughProperty("PictureBox92")]
    private PictureBox _PictureBox92;
    [AccessedThroughProperty("PictureBox93")]
    private PictureBox _PictureBox93;
    [AccessedThroughProperty("PictureBox94")]
    private PictureBox _PictureBox94;
    [AccessedThroughProperty("PictureBox95")]
    private PictureBox _PictureBox95;
    [AccessedThroughProperty("PictureBox96")]
    private PictureBox _PictureBox96;
    [AccessedThroughProperty("PictureBox97")]
    private PictureBox _PictureBox97;
    [AccessedThroughProperty("PictureBox98")]
    private PictureBox _PictureBox98;
    [AccessedThroughProperty("PictureBox99")]
    private PictureBox _PictureBox99;
    [AccessedThroughProperty("PictureBox100")]
    private PictureBox _PictureBox100;
    [AccessedThroughProperty("PictureBox101")]
    private PictureBox _PictureBox101;
    [AccessedThroughProperty("PictureBox102")]
    private PictureBox _PictureBox102;
    [AccessedThroughProperty("PictureBox103")]
    private PictureBox _PictureBox103;
    [AccessedThroughProperty("PictureBox104")]
    private PictureBox _PictureBox104;
    [AccessedThroughProperty("PictureBox105")]
    private PictureBox _PictureBox105;
    [AccessedThroughProperty("PictureBox106")]
    private PictureBox _PictureBox106;
    [AccessedThroughProperty("PictureBox107")]
    private PictureBox _PictureBox107;
    [AccessedThroughProperty("PictureBox108")]
    private PictureBox _PictureBox108;
    [AccessedThroughProperty("PictureBox109")]
    private PictureBox _PictureBox109;
    [AccessedThroughProperty("PictureBox110")]
    private PictureBox _PictureBox110;
    [AccessedThroughProperty("PictureBox111")]
    private PictureBox _PictureBox111;
    [AccessedThroughProperty("PictureBox112")]
    private PictureBox _PictureBox112;
    [AccessedThroughProperty("PictureBox29")]
    private PictureBox _PictureBox29;
    [AccessedThroughProperty("PictureBox30")]
    private PictureBox _PictureBox30;
    [AccessedThroughProperty("PictureBox31")]
    private PictureBox _PictureBox31;
    [AccessedThroughProperty("PictureBox32")]
    private PictureBox _PictureBox32;
    [AccessedThroughProperty("PictureBox33")]
    private PictureBox _PictureBox33;
    [AccessedThroughProperty("PictureBox34")]
    private PictureBox _PictureBox34;
    [AccessedThroughProperty("PictureBox35")]
    private PictureBox _PictureBox35;
    [AccessedThroughProperty("PictureBox36")]
    private PictureBox _PictureBox36;
    [AccessedThroughProperty("PictureBox37")]
    private PictureBox _PictureBox37;
    [AccessedThroughProperty("PictureBox38")]
    private PictureBox _PictureBox38;
    [AccessedThroughProperty("PictureBox39")]
    private PictureBox _PictureBox39;
    [AccessedThroughProperty("PictureBox40")]
    private PictureBox _PictureBox40;
    [AccessedThroughProperty("PictureBox41")]
    private PictureBox _PictureBox41;
    [AccessedThroughProperty("PictureBox42")]
    private PictureBox _PictureBox42;
    [AccessedThroughProperty("PictureBox43")]
    private PictureBox _PictureBox43;
    [AccessedThroughProperty("PictureBox44")]
    private PictureBox _PictureBox44;
    [AccessedThroughProperty("PictureBox45")]
    private PictureBox _PictureBox45;
    [AccessedThroughProperty("PictureBox46")]
    private PictureBox _PictureBox46;
    [AccessedThroughProperty("PictureBox47")]
    private PictureBox _PictureBox47;
    [AccessedThroughProperty("PictureBox48")]
    private PictureBox _PictureBox48;
    [AccessedThroughProperty("PictureBox49")]
    private PictureBox _PictureBox49;
    [AccessedThroughProperty("PictureBox50")]
    private PictureBox _PictureBox50;
    [AccessedThroughProperty("PictureBox51")]
    private PictureBox _PictureBox51;
    [AccessedThroughProperty("PictureBox52")]
    private PictureBox _PictureBox52;
    [AccessedThroughProperty("PictureBox53")]
    private PictureBox _PictureBox53;
    [AccessedThroughProperty("PictureBox54")]
    private PictureBox _PictureBox54;
    [AccessedThroughProperty("PictureBox55")]
    private PictureBox _PictureBox55;
    [AccessedThroughProperty("PictureBox56")]
    private PictureBox _PictureBox56;
    [AccessedThroughProperty("PictureBox15")]
    private PictureBox _PictureBox15;
    [AccessedThroughProperty("PictureBox16")]
    private PictureBox _PictureBox16;
    [AccessedThroughProperty("PictureBox17")]
    private PictureBox _PictureBox17;
    [AccessedThroughProperty("PictureBox18")]
    private PictureBox _PictureBox18;
    [AccessedThroughProperty("PictureBox19")]
    private PictureBox _PictureBox19;
    [AccessedThroughProperty("PictureBox20")]
    private PictureBox _PictureBox20;
    [AccessedThroughProperty("PictureBox21")]
    private PictureBox _PictureBox21;
    [AccessedThroughProperty("PictureBox22")]
    private PictureBox _PictureBox22;
    [AccessedThroughProperty("PictureBox23")]
    private PictureBox _PictureBox23;
    [AccessedThroughProperty("PictureBox24")]
    private PictureBox _PictureBox24;
    [AccessedThroughProperty("PictureBox25")]
    private PictureBox _PictureBox25;
    [AccessedThroughProperty("PictureBox26")]
    private PictureBox _PictureBox26;
    [AccessedThroughProperty("PictureBox27")]
    private PictureBox _PictureBox27;
    [AccessedThroughProperty("PictureBox28")]
    private PictureBox _PictureBox28;
    [AccessedThroughProperty("PictureBox14")]
    private PictureBox _PictureBox14;
    [AccessedThroughProperty("PictureBox13")]
    private PictureBox _PictureBox13;
    [AccessedThroughProperty("PictureBox12")]
    private PictureBox _PictureBox12;
    [AccessedThroughProperty("PictureBox11")]
    private PictureBox _PictureBox11;
    [AccessedThroughProperty("PictureBox10")]
    private PictureBox _PictureBox10;
    [AccessedThroughProperty("PictureBox9")]
    private PictureBox _PictureBox9;
    [AccessedThroughProperty("PictureBox8")]
    private PictureBox _PictureBox8;
    [AccessedThroughProperty("PictureBox7")]
    private PictureBox _PictureBox7;
    [AccessedThroughProperty("PictureBox6")]
    private PictureBox _PictureBox6;
    [AccessedThroughProperty("PictureBox5")]
    private PictureBox _PictureBox5;
    [AccessedThroughProperty("PictureBox4")]
    private PictureBox _PictureBox4;
    [AccessedThroughProperty("PictureBox3")]
    private PictureBox _PictureBox3;
    [AccessedThroughProperty("PictureBox2")]
    private PictureBox _PictureBox2;
    [AccessedThroughProperty("PictureBox1")]
    private PictureBox _PictureBox1;
    [AccessedThroughProperty("Label7")]
    private Label _Label7;
    [AccessedThroughProperty("PersonajeSearch")]
    private TextBox _PersonajeSearch;
    [AccessedThroughProperty("Todos")]
    private RadioButton _Todos;
    [AccessedThroughProperty("Charts")]
    private Label _Charts;
    [AccessedThroughProperty("PJ1")]
    private PictureBox _PJ1;
    [AccessedThroughProperty("Maps")]
    private Label _Maps;
    [AccessedThroughProperty("FotoMapa")]
    private PictureBox _FotoMapa;
    [AccessedThroughProperty("Label1")]
    private Label _Label1;
    [AccessedThroughProperty("Baneados")]
    private RadioButton _Baneados;
    [AccessedThroughProperty("ListaMapas")]
    private ListBox _ListaMapas;
    [AccessedThroughProperty("GroupBox1")]
    private GroupBox _GroupBox1;
    [AccessedThroughProperty("GroupBox2")]
    private GroupBox _GroupBox2;
    [AccessedThroughProperty("XXYY")]
    private GroupBox _XXYY;
    [AccessedThroughProperty("Label19")]
    private Label _Label19;
    [AccessedThroughProperty("Reloj")]
    private System.Windows.Forms.Timer timer_0;
    [AccessedThroughProperty("VerTodosPJ")]
    private ListBox _VerTodosPJ;
    [AccessedThroughProperty("Minimizar")]
    private Button _Minimizar;
    [AccessedThroughProperty("Cerrar")]
    private Button _Cerrar;
    [AccessedThroughProperty("Titulo")]
    private Label _Titulo;
    [AccessedThroughProperty("Buscar")]
    private Button _Buscar;
    [AccessedThroughProperty("Label3")]
    private Label _Label3;
    [AccessedThroughProperty("Search")]
    private Label _Search;
    [AccessedThroughProperty("X")]
    private Label _X;
    [AccessedThroughProperty("YYY")]
    private Label _YYY;
    [AccessedThroughProperty("XXX")]
    private Label _XXX;
    [AccessedThroughProperty("YY")]
    private Label _YY;
    [AccessedThroughProperty("XX")]
    private Label _XX;
    [AccessedThroughProperty("Y")]
    private Label _Y;
    private const int int_0 = 132;
    private const int int_1 = 1;
    private const int int_2 = 2;

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

    internal virtual RadioButton GameMaster
    {
      [DebuggerNonUserCode] get
      {
        return this._GameMaster;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.GameMaster_CheckedChanged);
        if (this._GameMaster != null)
          this._GameMaster.CheckedChanged -= eventHandler;
        this._GameMaster = value;
        if (this._GameMaster == null)
          return;
        this._GameMaster.CheckedChanged += eventHandler;
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
        EventHandler eventHandler = new EventHandler(this.method_5);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_15);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_14);
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

    internal virtual ListBox PJOnline
    {
      [DebuggerNonUserCode] get
      {
        return this._PJOnline;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.PJOnline_SelectedIndexChanged);
        if (this._PJOnline != null)
          this._PJOnline.SelectedIndexChanged -= eventHandler;
        this._PJOnline = value;
        if (this._PJOnline == null)
          return;
        this._PJOnline.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual PictureBox PictureBox500
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox500;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox500 = value;
      }
    }

    internal virtual PictureBox PictureBox499
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox499;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox499 = value;
      }
    }

    internal virtual PictureBox PictureBox498
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox498;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox498 = value;
      }
    }

    internal virtual PictureBox PictureBox497
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox497;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox497 = value;
      }
    }

    internal virtual PictureBox PictureBox496
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox496;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox496 = value;
      }
    }

    internal virtual PictureBox PictureBox495
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox495;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox495 = value;
      }
    }

    internal virtual PictureBox PictureBox494
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox494;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox494 = value;
      }
    }

    internal virtual PictureBox PictureBox493
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox493;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox493 = value;
      }
    }

    internal virtual PictureBox PictureBox492
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox492;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox492 = value;
      }
    }

    internal virtual PictureBox PictureBox491
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox491;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox491 = value;
      }
    }

    internal virtual PictureBox PictureBox490
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox490;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox490 = value;
      }
    }

    internal virtual PictureBox PictureBox489
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox489;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox489 = value;
      }
    }

    internal virtual PictureBox PictureBox488
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox488;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox488 = value;
      }
    }

    internal virtual PictureBox PictureBox487
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox487;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox487 = value;
      }
    }

    internal virtual PictureBox PictureBox486
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox486;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox486 = value;
      }
    }

    internal virtual PictureBox PictureBox485
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox485;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox485 = value;
      }
    }

    internal virtual PictureBox PictureBox484
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox484;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox484 = value;
      }
    }

    internal virtual PictureBox PictureBox483
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox483;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox483 = value;
      }
    }

    internal virtual PictureBox PictureBox482
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox482;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox482 = value;
      }
    }

    internal virtual PictureBox PictureBox481
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox481;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox481 = value;
      }
    }

    internal virtual PictureBox PictureBox480
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox480;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox480 = value;
      }
    }

    internal virtual PictureBox PictureBox479
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox479;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox479 = value;
      }
    }

    internal virtual PictureBox PictureBox478
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox478;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox478 = value;
      }
    }

    internal virtual PictureBox PictureBox477
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox477;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox477 = value;
      }
    }

    internal virtual PictureBox PictureBox476
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox476;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox476 = value;
      }
    }

    internal virtual PictureBox PictureBox475
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox475;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox475 = value;
      }
    }

    internal virtual PictureBox PictureBox474
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox474;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox474 = value;
      }
    }

    internal virtual PictureBox PictureBox473
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox473;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox473 = value;
      }
    }

    internal virtual PictureBox PictureBox472
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox472;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox472 = value;
      }
    }

    internal virtual PictureBox PictureBox471
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox471;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox471 = value;
      }
    }

    internal virtual PictureBox PictureBox470
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox470;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox470 = value;
      }
    }

    internal virtual PictureBox PictureBox469
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox469;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox469 = value;
      }
    }

    internal virtual PictureBox PictureBox468
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox468;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox468 = value;
      }
    }

    internal virtual PictureBox PictureBox467
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox467;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox467 = value;
      }
    }

    internal virtual PictureBox PictureBox466
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox466;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox466 = value;
      }
    }

    internal virtual PictureBox PictureBox465
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox465;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox465 = value;
      }
    }

    internal virtual PictureBox PictureBox464
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox464;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox464 = value;
      }
    }

    internal virtual PictureBox PictureBox463
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox463;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox463 = value;
      }
    }

    internal virtual PictureBox PictureBox462
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox462;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox462 = value;
      }
    }

    internal virtual PictureBox PictureBox461
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox461;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox461 = value;
      }
    }

    internal virtual PictureBox PictureBox460
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox460;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox460 = value;
      }
    }

    internal virtual PictureBox PictureBox459
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox459;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox459 = value;
      }
    }

    internal virtual PictureBox PictureBox458
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox458;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox458 = value;
      }
    }

    internal virtual PictureBox PictureBox457
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox457;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox457 = value;
      }
    }

    internal virtual PictureBox PictureBox456
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox456;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox456 = value;
      }
    }

    internal virtual PictureBox PictureBox455
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox455;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox455 = value;
      }
    }

    internal virtual PictureBox PictureBox454
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox454;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox454 = value;
      }
    }

    internal virtual PictureBox PictureBox453
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox453;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox453 = value;
      }
    }

    internal virtual PictureBox PictureBox452
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox452;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox452 = value;
      }
    }

    internal virtual PictureBox PictureBox451
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox451;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox451 = value;
      }
    }

    internal virtual Label Label23
    {
      [DebuggerNonUserCode] get
      {
        return this._Label23;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label23 = value;
      }
    }

    internal virtual PictureBox PictureBox450
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox450;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox450 = value;
      }
    }

    internal virtual PictureBox PictureBox449
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox449;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox449 = value;
      }
    }

    internal virtual PictureBox PictureBox225
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox225;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox225 = value;
      }
    }

    internal virtual PictureBox PictureBox226
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox226;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox226 = value;
      }
    }

    internal virtual PictureBox PictureBox227
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox227;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox227 = value;
      }
    }

    internal virtual PictureBox PictureBox228
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox228;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox228 = value;
      }
    }

    internal virtual PictureBox PictureBox229
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox229;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox229 = value;
      }
    }

    internal virtual PictureBox PictureBox230
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox230;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox230 = value;
      }
    }

    internal virtual PictureBox PictureBox231
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox231;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox231 = value;
      }
    }

    internal virtual PictureBox PictureBox232
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox232;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox232 = value;
      }
    }

    internal virtual PictureBox PictureBox233
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox233;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox233 = value;
      }
    }

    internal virtual PictureBox PictureBox234
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox234;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox234 = value;
      }
    }

    internal virtual PictureBox PictureBox235
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox235;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox235 = value;
      }
    }

    internal virtual PictureBox PictureBox236
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox236;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox236 = value;
      }
    }

    internal virtual PictureBox PictureBox237
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox237;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox237 = value;
      }
    }

    internal virtual PictureBox PictureBox238
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox238;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox238 = value;
      }
    }

    internal virtual PictureBox PictureBox239
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox239;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox239 = value;
      }
    }

    internal virtual PictureBox PictureBox240
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox240;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox240 = value;
      }
    }

    internal virtual PictureBox PictureBox241
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox241;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox241 = value;
      }
    }

    internal virtual PictureBox PictureBox242
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox242;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox242 = value;
      }
    }

    internal virtual PictureBox PictureBox243
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox243;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox243 = value;
      }
    }

    internal virtual PictureBox PictureBox244
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox244;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox244 = value;
      }
    }

    internal virtual PictureBox PictureBox245
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox245;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox245 = value;
      }
    }

    internal virtual PictureBox PictureBox246
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox246;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox246 = value;
      }
    }

    internal virtual PictureBox PictureBox247
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox247;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox247 = value;
      }
    }

    internal virtual PictureBox PictureBox248
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox248;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox248 = value;
      }
    }

    internal virtual PictureBox PictureBox249
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox249;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox249 = value;
      }
    }

    internal virtual PictureBox PictureBox250
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox250;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox250 = value;
      }
    }

    internal virtual PictureBox PictureBox251
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox251;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox251 = value;
      }
    }

    internal virtual PictureBox PictureBox252
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox252;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox252 = value;
      }
    }

    internal virtual PictureBox PictureBox253
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox253;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox253 = value;
      }
    }

    internal virtual PictureBox PictureBox254
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox254;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox254 = value;
      }
    }

    internal virtual PictureBox PictureBox255
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox255;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox255 = value;
      }
    }

    internal virtual PictureBox PictureBox256
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox256;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox256 = value;
      }
    }

    internal virtual PictureBox PictureBox257
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox257;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox257 = value;
      }
    }

    internal virtual PictureBox PictureBox258
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox258;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox258 = value;
      }
    }

    internal virtual PictureBox PictureBox259
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox259;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox259 = value;
      }
    }

    internal virtual PictureBox PictureBox260
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox260;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox260 = value;
      }
    }

    internal virtual PictureBox PictureBox261
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox261;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox261 = value;
      }
    }

    internal virtual PictureBox PictureBox262
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox262;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox262 = value;
      }
    }

    internal virtual PictureBox PictureBox263
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox263;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox263 = value;
      }
    }

    internal virtual PictureBox PictureBox264
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox264;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox264 = value;
      }
    }

    internal virtual PictureBox PictureBox265
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox265;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox265 = value;
      }
    }

    internal virtual PictureBox PictureBox266
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox266;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox266 = value;
      }
    }

    internal virtual PictureBox PictureBox267
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox267;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox267 = value;
      }
    }

    internal virtual PictureBox PictureBox268
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox268;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox268 = value;
      }
    }

    internal virtual PictureBox PictureBox269
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox269;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox269 = value;
      }
    }

    internal virtual PictureBox PictureBox270
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox270;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox270 = value;
      }
    }

    internal virtual PictureBox PictureBox271
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox271;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox271 = value;
      }
    }

    internal virtual PictureBox PictureBox272
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox272;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox272 = value;
      }
    }

    internal virtual PictureBox PictureBox273
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox273;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox273 = value;
      }
    }

    internal virtual PictureBox PictureBox274
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox274;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox274 = value;
      }
    }

    internal virtual PictureBox PictureBox275
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox275;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox275 = value;
      }
    }

    internal virtual PictureBox PictureBox276
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox276;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox276 = value;
      }
    }

    internal virtual PictureBox PictureBox277
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox277;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox277 = value;
      }
    }

    internal virtual PictureBox PictureBox278
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox278;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox278 = value;
      }
    }

    internal virtual PictureBox PictureBox279
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox279;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox279 = value;
      }
    }

    internal virtual PictureBox PictureBox280
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox280;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox280 = value;
      }
    }

    internal virtual PictureBox PictureBox281
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox281;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox281 = value;
      }
    }

    internal virtual PictureBox PictureBox282
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox282;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox282 = value;
      }
    }

    internal virtual PictureBox PictureBox283
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox283;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox283 = value;
      }
    }

    internal virtual PictureBox PictureBox284
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox284;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox284 = value;
      }
    }

    internal virtual PictureBox PictureBox285
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox285;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox285 = value;
      }
    }

    internal virtual PictureBox PictureBox286
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox286;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox286 = value;
      }
    }

    internal virtual PictureBox PictureBox287
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox287;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox287 = value;
      }
    }

    internal virtual PictureBox PictureBox288
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox288;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox288 = value;
      }
    }

    internal virtual PictureBox PictureBox289
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox289;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox289 = value;
      }
    }

    internal virtual PictureBox PictureBox290
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox290;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox290 = value;
      }
    }

    internal virtual PictureBox PictureBox291
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox291;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox291 = value;
      }
    }

    internal virtual PictureBox PictureBox292
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox292;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox292 = value;
      }
    }

    internal virtual PictureBox PictureBox293
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox293;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox293 = value;
      }
    }

    internal virtual PictureBox PictureBox294
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox294;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox294 = value;
      }
    }

    internal virtual PictureBox PictureBox295
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox295;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox295 = value;
      }
    }

    internal virtual PictureBox PictureBox296
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox296;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox296 = value;
      }
    }

    internal virtual PictureBox PictureBox297
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox297;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox297 = value;
      }
    }

    internal virtual PictureBox PictureBox298
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox298;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox298 = value;
      }
    }

    internal virtual PictureBox PictureBox299
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox299;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox299 = value;
      }
    }

    internal virtual PictureBox PictureBox300
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox300;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox300 = value;
      }
    }

    internal virtual PictureBox PictureBox301
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox301;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox301 = value;
      }
    }

    internal virtual PictureBox PictureBox302
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox302;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox302 = value;
      }
    }

    internal virtual PictureBox PictureBox303
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox303;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox303 = value;
      }
    }

    internal virtual PictureBox PictureBox304
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox304;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox304 = value;
      }
    }

    internal virtual PictureBox PictureBox305
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox305;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox305 = value;
      }
    }

    internal virtual PictureBox PictureBox306
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox306;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox306 = value;
      }
    }

    internal virtual PictureBox PictureBox307
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox307;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox307 = value;
      }
    }

    internal virtual PictureBox PictureBox308
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox308;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox308 = value;
      }
    }

    internal virtual PictureBox PictureBox309
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox309;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox309 = value;
      }
    }

    internal virtual PictureBox PictureBox310
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox310;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox310 = value;
      }
    }

    internal virtual PictureBox PictureBox311
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox311;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox311 = value;
      }
    }

    internal virtual PictureBox PictureBox312
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox312;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox312 = value;
      }
    }

    internal virtual PictureBox PictureBox313
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox313;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox313 = value;
      }
    }

    internal virtual PictureBox PictureBox314
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox314;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox314 = value;
      }
    }

    internal virtual PictureBox PictureBox315
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox315;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox315 = value;
      }
    }

    internal virtual PictureBox PictureBox316
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox316;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox316 = value;
      }
    }

    internal virtual PictureBox PictureBox317
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox317;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox317 = value;
      }
    }

    internal virtual PictureBox PictureBox318
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox318;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox318 = value;
      }
    }

    internal virtual PictureBox PictureBox319
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox319;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox319 = value;
      }
    }

    internal virtual PictureBox PictureBox320
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox320;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox320 = value;
      }
    }

    internal virtual PictureBox PictureBox321
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox321;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox321 = value;
      }
    }

    internal virtual PictureBox PictureBox322
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox322;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox322 = value;
      }
    }

    internal virtual PictureBox PictureBox323
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox323;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox323 = value;
      }
    }

    internal virtual PictureBox PictureBox324
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox324;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox324 = value;
      }
    }

    internal virtual PictureBox PictureBox325
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox325;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox325 = value;
      }
    }

    internal virtual PictureBox PictureBox326
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox326;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox326 = value;
      }
    }

    internal virtual PictureBox PictureBox327
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox327;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox327 = value;
      }
    }

    internal virtual PictureBox PictureBox328
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox328;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox328 = value;
      }
    }

    internal virtual PictureBox PictureBox329
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox329;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox329 = value;
      }
    }

    internal virtual PictureBox PictureBox330
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox330;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox330 = value;
      }
    }

    internal virtual PictureBox PictureBox331
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox331;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox331 = value;
      }
    }

    internal virtual PictureBox PictureBox332
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox332;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox332 = value;
      }
    }

    internal virtual PictureBox PictureBox333
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox333;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox333 = value;
      }
    }

    internal virtual PictureBox PictureBox334
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox334;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox334 = value;
      }
    }

    internal virtual PictureBox PictureBox335
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox335;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox335 = value;
      }
    }

    internal virtual PictureBox PictureBox336
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox336;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox336 = value;
      }
    }

    internal virtual PictureBox PictureBox337
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox337;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox337 = value;
      }
    }

    internal virtual PictureBox PictureBox338
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox338;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox338 = value;
      }
    }

    internal virtual PictureBox PictureBox339
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox339;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox339 = value;
      }
    }

    internal virtual PictureBox PictureBox340
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox340;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox340 = value;
      }
    }

    internal virtual PictureBox PictureBox341
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox341;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox341 = value;
      }
    }

    internal virtual PictureBox PictureBox342
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox342;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox342 = value;
      }
    }

    internal virtual PictureBox PictureBox343
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox343;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox343 = value;
      }
    }

    internal virtual PictureBox PictureBox344
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox344;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox344 = value;
      }
    }

    internal virtual PictureBox PictureBox345
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox345;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox345 = value;
      }
    }

    internal virtual PictureBox PictureBox346
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox346;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox346 = value;
      }
    }

    internal virtual PictureBox PictureBox347
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox347;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox347 = value;
      }
    }

    internal virtual PictureBox PictureBox348
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox348;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox348 = value;
      }
    }

    internal virtual PictureBox PictureBox349
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox349;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox349 = value;
      }
    }

    internal virtual PictureBox PictureBox350
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox350;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox350 = value;
      }
    }

    internal virtual PictureBox PictureBox351
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox351;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox351 = value;
      }
    }

    internal virtual PictureBox PictureBox352
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox352;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox352 = value;
      }
    }

    internal virtual PictureBox PictureBox353
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox353;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox353 = value;
      }
    }

    internal virtual PictureBox PictureBox354
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox354;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox354 = value;
      }
    }

    internal virtual PictureBox PictureBox355
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox355;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox355 = value;
      }
    }

    internal virtual PictureBox PictureBox356
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox356;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox356 = value;
      }
    }

    internal virtual PictureBox PictureBox357
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox357;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox357 = value;
      }
    }

    internal virtual PictureBox PictureBox358
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox358;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox358 = value;
      }
    }

    internal virtual PictureBox PictureBox359
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox359;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox359 = value;
      }
    }

    internal virtual PictureBox PictureBox360
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox360;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox360 = value;
      }
    }

    internal virtual PictureBox PictureBox361
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox361;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox361 = value;
      }
    }

    internal virtual PictureBox PictureBox362
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox362;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox362 = value;
      }
    }

    internal virtual PictureBox PictureBox363
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox363;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox363 = value;
      }
    }

    internal virtual PictureBox PictureBox364
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox364;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox364 = value;
      }
    }

    internal virtual PictureBox PictureBox365
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox365;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox365 = value;
      }
    }

    internal virtual PictureBox PictureBox366
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox366;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox366 = value;
      }
    }

    internal virtual PictureBox PictureBox367
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox367;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox367 = value;
      }
    }

    internal virtual PictureBox PictureBox368
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox368;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox368 = value;
      }
    }

    internal virtual PictureBox PictureBox369
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox369;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox369 = value;
      }
    }

    internal virtual PictureBox PictureBox370
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox370;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox370 = value;
      }
    }

    internal virtual PictureBox PictureBox371
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox371;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox371 = value;
      }
    }

    internal virtual PictureBox PictureBox372
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox372;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox372 = value;
      }
    }

    internal virtual PictureBox PictureBox373
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox373;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox373 = value;
      }
    }

    internal virtual PictureBox PictureBox374
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox374;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox374 = value;
      }
    }

    internal virtual PictureBox PictureBox375
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox375;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox375 = value;
      }
    }

    internal virtual PictureBox PictureBox376
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox376;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox376 = value;
      }
    }

    internal virtual PictureBox PictureBox377
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox377;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox377 = value;
      }
    }

    internal virtual PictureBox PictureBox378
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox378;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox378 = value;
      }
    }

    internal virtual PictureBox PictureBox379
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox379;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox379 = value;
      }
    }

    internal virtual PictureBox PictureBox380
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox380;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox380 = value;
      }
    }

    internal virtual PictureBox PictureBox381
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox381;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox381 = value;
      }
    }

    internal virtual PictureBox PictureBox382
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox382;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox382 = value;
      }
    }

    internal virtual PictureBox PictureBox383
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox383;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox383 = value;
      }
    }

    internal virtual PictureBox PictureBox384
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox384;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox384 = value;
      }
    }

    internal virtual PictureBox PictureBox385
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox385;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox385 = value;
      }
    }

    internal virtual PictureBox PictureBox386
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox386;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox386 = value;
      }
    }

    internal virtual PictureBox PictureBox387
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox387;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox387 = value;
      }
    }

    internal virtual PictureBox PictureBox388
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox388;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox388 = value;
      }
    }

    internal virtual PictureBox PictureBox389
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox389;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox389 = value;
      }
    }

    internal virtual PictureBox PictureBox390
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox390;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox390 = value;
      }
    }

    internal virtual PictureBox PictureBox391
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox391;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox391 = value;
      }
    }

    internal virtual PictureBox PictureBox392
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox392;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox392 = value;
      }
    }

    internal virtual PictureBox PictureBox393
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox393;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox393 = value;
      }
    }

    internal virtual PictureBox PictureBox394
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox394;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox394 = value;
      }
    }

    internal virtual PictureBox PictureBox395
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox395;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox395 = value;
      }
    }

    internal virtual PictureBox PictureBox396
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox396;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox396 = value;
      }
    }

    internal virtual PictureBox PictureBox397
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox397;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox397 = value;
      }
    }

    internal virtual PictureBox PictureBox398
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox398;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox398 = value;
      }
    }

    internal virtual PictureBox PictureBox399
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox399;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox399 = value;
      }
    }

    internal virtual PictureBox PictureBox400
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox400;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox400 = value;
      }
    }

    internal virtual PictureBox PictureBox401
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox401;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox401 = value;
      }
    }

    internal virtual PictureBox PictureBox402
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox402;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox402 = value;
      }
    }

    internal virtual PictureBox PictureBox403
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox403;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox403 = value;
      }
    }

    internal virtual PictureBox PictureBox404
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox404;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox404 = value;
      }
    }

    internal virtual PictureBox PictureBox405
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox405;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox405 = value;
      }
    }

    internal virtual PictureBox PictureBox406
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox406;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox406 = value;
      }
    }

    internal virtual PictureBox PictureBox407
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox407;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox407 = value;
      }
    }

    internal virtual PictureBox PictureBox408
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox408;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox408 = value;
      }
    }

    internal virtual PictureBox PictureBox409
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox409;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox409 = value;
      }
    }

    internal virtual PictureBox PictureBox410
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox410;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox410 = value;
      }
    }

    internal virtual PictureBox PictureBox411
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox411;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox411 = value;
      }
    }

    internal virtual PictureBox PictureBox412
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox412;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox412 = value;
      }
    }

    internal virtual PictureBox PictureBox413
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox413;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox413 = value;
      }
    }

    internal virtual PictureBox PictureBox414
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox414;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox414 = value;
      }
    }

    internal virtual PictureBox PictureBox415
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox415;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox415 = value;
      }
    }

    internal virtual PictureBox PictureBox416
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox416;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox416 = value;
      }
    }

    internal virtual PictureBox PictureBox417
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox417;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox417 = value;
      }
    }

    internal virtual PictureBox PictureBox418
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox418;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox418 = value;
      }
    }

    internal virtual PictureBox PictureBox419
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox419;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox419 = value;
      }
    }

    internal virtual PictureBox PictureBox420
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox420;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox420 = value;
      }
    }

    internal virtual PictureBox PictureBox421
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox421;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox421 = value;
      }
    }

    internal virtual PictureBox PictureBox422
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox422;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox422 = value;
      }
    }

    internal virtual PictureBox PictureBox423
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox423;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox423 = value;
      }
    }

    internal virtual PictureBox PictureBox424
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox424;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox424 = value;
      }
    }

    internal virtual PictureBox PictureBox425
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox425;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox425 = value;
      }
    }

    internal virtual PictureBox PictureBox426
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox426;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox426 = value;
      }
    }

    internal virtual PictureBox PictureBox427
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox427;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox427 = value;
      }
    }

    internal virtual PictureBox PictureBox428
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox428;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox428 = value;
      }
    }

    internal virtual PictureBox PictureBox429
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox429;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox429 = value;
      }
    }

    internal virtual PictureBox PictureBox430
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox430;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox430 = value;
      }
    }

    internal virtual PictureBox PictureBox431
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox431;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox431 = value;
      }
    }

    internal virtual PictureBox PictureBox432
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox432;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox432 = value;
      }
    }

    internal virtual PictureBox PictureBox433
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox433;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox433 = value;
      }
    }

    internal virtual PictureBox PictureBox434
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox434;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox434 = value;
      }
    }

    internal virtual PictureBox PictureBox435
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox435;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox435 = value;
      }
    }

    internal virtual PictureBox PictureBox436
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox436;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox436 = value;
      }
    }

    internal virtual PictureBox PictureBox437
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox437;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox437 = value;
      }
    }

    internal virtual PictureBox PictureBox438
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox438;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox438 = value;
      }
    }

    internal virtual PictureBox PictureBox439
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox439;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox439 = value;
      }
    }

    internal virtual PictureBox PictureBox440
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox440;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox440 = value;
      }
    }

    internal virtual PictureBox PictureBox441
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox441;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox441 = value;
      }
    }

    internal virtual PictureBox PictureBox442
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox442;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox442 = value;
      }
    }

    internal virtual PictureBox PictureBox443
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox443;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox443 = value;
      }
    }

    internal virtual PictureBox PictureBox444
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox444;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox444 = value;
      }
    }

    internal virtual PictureBox PictureBox445
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox445;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox445 = value;
      }
    }

    internal virtual PictureBox PictureBox446
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox446;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox446 = value;
      }
    }

    internal virtual PictureBox PictureBox447
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox447;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox447 = value;
      }
    }

    internal virtual PictureBox PictureBox448
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox448;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox448 = value;
      }
    }

    internal virtual PictureBox PictureBox113
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox113;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox113 = value;
      }
    }

    internal virtual PictureBox PictureBox114
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox114;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox114 = value;
      }
    }

    internal virtual PictureBox PictureBox115
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox115;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox115 = value;
      }
    }

    internal virtual PictureBox PictureBox116
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox116;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox116 = value;
      }
    }

    internal virtual PictureBox PictureBox117
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox117;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox117 = value;
      }
    }

    internal virtual PictureBox PictureBox118
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox118;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox118 = value;
      }
    }

    internal virtual PictureBox PictureBox119
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox119;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox119 = value;
      }
    }

    internal virtual PictureBox PictureBox120
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox120;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox120 = value;
      }
    }

    internal virtual PictureBox PictureBox121
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox121;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox121 = value;
      }
    }

    internal virtual PictureBox PictureBox122
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox122;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox122 = value;
      }
    }

    internal virtual PictureBox PictureBox123
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox123;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox123 = value;
      }
    }

    internal virtual PictureBox PictureBox124
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox124;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox124 = value;
      }
    }

    internal virtual PictureBox PictureBox125
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox125;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox125 = value;
      }
    }

    internal virtual PictureBox PictureBox126
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox126;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox126 = value;
      }
    }

    internal virtual PictureBox PictureBox127
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox127;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox127 = value;
      }
    }

    internal virtual PictureBox PictureBox128
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox128;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox128 = value;
      }
    }

    internal virtual PictureBox PictureBox129
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox129;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox129 = value;
      }
    }

    internal virtual PictureBox PictureBox130
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox130;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox130 = value;
      }
    }

    internal virtual PictureBox PictureBox131
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox131;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox131 = value;
      }
    }

    internal virtual PictureBox PictureBox132
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox132;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox132 = value;
      }
    }

    internal virtual PictureBox PictureBox133
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox133;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox133 = value;
      }
    }

    internal virtual PictureBox PictureBox134
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox134;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox134 = value;
      }
    }

    internal virtual PictureBox PictureBox135
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox135;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox135 = value;
      }
    }

    internal virtual PictureBox PictureBox136
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox136;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox136 = value;
      }
    }

    internal virtual PictureBox PictureBox137
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox137;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox137 = value;
      }
    }

    internal virtual PictureBox PictureBox138
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox138;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox138 = value;
      }
    }

    internal virtual PictureBox PictureBox139
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox139;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox139 = value;
      }
    }

    internal virtual PictureBox PictureBox140
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox140;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox140 = value;
      }
    }

    internal virtual PictureBox PictureBox141
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox141;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox141 = value;
      }
    }

    internal virtual PictureBox PictureBox142
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox142;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox142 = value;
      }
    }

    internal virtual PictureBox PictureBox143
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox143;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox143 = value;
      }
    }

    internal virtual PictureBox PictureBox144
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox144;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox144 = value;
      }
    }

    internal virtual PictureBox PictureBox145
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox145;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox145 = value;
      }
    }

    internal virtual PictureBox PictureBox146
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox146;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox146 = value;
      }
    }

    internal virtual PictureBox PictureBox147
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox147;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox147 = value;
      }
    }

    internal virtual PictureBox PictureBox148
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox148;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox148 = value;
      }
    }

    internal virtual PictureBox PictureBox149
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox149;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox149 = value;
      }
    }

    internal virtual PictureBox PictureBox150
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox150;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox150 = value;
      }
    }

    internal virtual PictureBox PictureBox151
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox151;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox151 = value;
      }
    }

    internal virtual PictureBox PictureBox152
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox152;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox152 = value;
      }
    }

    internal virtual PictureBox PictureBox153
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox153;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox153 = value;
      }
    }

    internal virtual PictureBox PictureBox154
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox154;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox154 = value;
      }
    }

    internal virtual PictureBox PictureBox155
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox155;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox155 = value;
      }
    }

    internal virtual PictureBox PictureBox156
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox156;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox156 = value;
      }
    }

    internal virtual PictureBox PictureBox157
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox157;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox157 = value;
      }
    }

    internal virtual PictureBox PictureBox158
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox158;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox158 = value;
      }
    }

    internal virtual PictureBox PictureBox159
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox159;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox159 = value;
      }
    }

    internal virtual PictureBox PictureBox160
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox160;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox160 = value;
      }
    }

    internal virtual PictureBox PictureBox161
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox161;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox161 = value;
      }
    }

    internal virtual PictureBox PictureBox162
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox162;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox162 = value;
      }
    }

    internal virtual PictureBox PictureBox163
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox163;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox163 = value;
      }
    }

    internal virtual PictureBox PictureBox164
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox164;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox164 = value;
      }
    }

    internal virtual PictureBox PictureBox165
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox165;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox165 = value;
      }
    }

    internal virtual PictureBox PictureBox166
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox166;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox166 = value;
      }
    }

    internal virtual PictureBox PictureBox167
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox167;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox167 = value;
      }
    }

    internal virtual PictureBox PictureBox168
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox168;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox168 = value;
      }
    }

    internal virtual PictureBox PictureBox169
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox169;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox169 = value;
      }
    }

    internal virtual PictureBox PictureBox170
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox170;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox170 = value;
      }
    }

    internal virtual PictureBox PictureBox171
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox171;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox171 = value;
      }
    }

    internal virtual PictureBox PictureBox172
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox172;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox172 = value;
      }
    }

    internal virtual PictureBox PictureBox173
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox173;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox173 = value;
      }
    }

    internal virtual PictureBox PictureBox174
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox174;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox174 = value;
      }
    }

    internal virtual PictureBox PictureBox175
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox175;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox175 = value;
      }
    }

    internal virtual PictureBox PictureBox176
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox176;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox176 = value;
      }
    }

    internal virtual PictureBox PictureBox177
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox177;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox177 = value;
      }
    }

    internal virtual PictureBox PictureBox178
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox178;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox178 = value;
      }
    }

    internal virtual PictureBox PictureBox179
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox179;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox179 = value;
      }
    }

    internal virtual PictureBox PictureBox180
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox180;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox180 = value;
      }
    }

    internal virtual PictureBox PictureBox181
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox181;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox181 = value;
      }
    }

    internal virtual PictureBox PictureBox182
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox182;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox182 = value;
      }
    }

    internal virtual PictureBox PictureBox183
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox183;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox183 = value;
      }
    }

    internal virtual PictureBox PictureBox184
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox184;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox184 = value;
      }
    }

    internal virtual PictureBox PictureBox185
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox185;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox185 = value;
      }
    }

    internal virtual PictureBox PictureBox186
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox186;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox186 = value;
      }
    }

    internal virtual PictureBox PictureBox187
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox187;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox187 = value;
      }
    }

    internal virtual PictureBox PictureBox188
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox188;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox188 = value;
      }
    }

    internal virtual PictureBox PictureBox189
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox189;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox189 = value;
      }
    }

    internal virtual PictureBox PictureBox190
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox190;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox190 = value;
      }
    }

    internal virtual PictureBox PictureBox191
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox191;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox191 = value;
      }
    }

    internal virtual PictureBox PictureBox192
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox192;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox192 = value;
      }
    }

    internal virtual PictureBox PictureBox193
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox193;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox193 = value;
      }
    }

    internal virtual PictureBox PictureBox194
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox194;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox194 = value;
      }
    }

    internal virtual PictureBox PictureBox195
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox195;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox195 = value;
      }
    }

    internal virtual PictureBox PictureBox196
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox196;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox196 = value;
      }
    }

    internal virtual PictureBox PictureBox197
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox197;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox197 = value;
      }
    }

    internal virtual PictureBox PictureBox198
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox198;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox198 = value;
      }
    }

    internal virtual PictureBox PictureBox199
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox199;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox199 = value;
      }
    }

    internal virtual PictureBox PictureBox200
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox200;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox200 = value;
      }
    }

    internal virtual PictureBox PictureBox201
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox201;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox201 = value;
      }
    }

    internal virtual PictureBox PictureBox202
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox202;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox202 = value;
      }
    }

    internal virtual PictureBox PictureBox203
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox203;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox203 = value;
      }
    }

    internal virtual PictureBox PictureBox204
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox204;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox204 = value;
      }
    }

    internal virtual PictureBox PictureBox205
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox205;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox205 = value;
      }
    }

    internal virtual PictureBox PictureBox206
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox206;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox206 = value;
      }
    }

    internal virtual PictureBox PictureBox207
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox207;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox207 = value;
      }
    }

    internal virtual PictureBox PictureBox208
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox208;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox208 = value;
      }
    }

    internal virtual PictureBox PictureBox209
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox209;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox209 = value;
      }
    }

    internal virtual PictureBox PictureBox210
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox210;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox210 = value;
      }
    }

    internal virtual PictureBox PictureBox211
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox211;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox211 = value;
      }
    }

    internal virtual PictureBox PictureBox212
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox212;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox212 = value;
      }
    }

    internal virtual PictureBox PictureBox213
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox213;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox213 = value;
      }
    }

    internal virtual PictureBox PictureBox214
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox214;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox214 = value;
      }
    }

    internal virtual PictureBox PictureBox215
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox215;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox215 = value;
      }
    }

    internal virtual PictureBox PictureBox216
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox216;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox216 = value;
      }
    }

    internal virtual PictureBox PictureBox217
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox217;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox217 = value;
      }
    }

    internal virtual PictureBox PictureBox218
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox218;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox218 = value;
      }
    }

    internal virtual PictureBox PictureBox219
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox219;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox219 = value;
      }
    }

    internal virtual PictureBox PictureBox220
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox220;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox220 = value;
      }
    }

    internal virtual PictureBox PictureBox221
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox221;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox221 = value;
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

    internal virtual TextBox Acount
    {
      [DebuggerNonUserCode] get
      {
        return this._Acount;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Acount = value;
      }
    }

    internal virtual TextBox Baneado
    {
      [DebuggerNonUserCode] get
      {
        return this._Baneado;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Baneado = value;
      }
    }

    internal virtual Button BanUnBan
    {
      [DebuggerNonUserCode] get
      {
        return this._BanUnBan;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.BanUnBan_Click);
        if (this._BanUnBan != null)
          this._BanUnBan.Click -= eventHandler;
        this._BanUnBan = value;
        if (this._BanUnBan == null)
          return;
        this._BanUnBan.Click += eventHandler;
      }
    }

    internal virtual TextBox level
    {
      [DebuggerNonUserCode] get
      {
        return this._level;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._level = value;
      }
    }

    internal virtual CheckBox PN
    {
      [DebuggerNonUserCode] get
      {
        return this._PN;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.PN_CheckedChanged);
        if (this._PN != null)
          this._PN.CheckedChanged -= eventHandler;
        this._PN = value;
        if (this._PN == null)
          return;
        this._PN.CheckedChanged += eventHandler;
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

    internal virtual TextBox Personajes
    {
      [DebuggerNonUserCode] get
      {
        return this._Personajes;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Personajes = value;
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

    internal virtual Button Desconectador
    {
      [DebuggerNonUserCode] get
      {
        return this._Desconectador;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Desconectador_Click);
        if (this._Desconectador != null)
          this._Desconectador.Click -= eventHandler;
        this._Desconectador = value;
        if (this._Desconectador == null)
          return;
        this._Desconectador.Click += eventHandler;
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

    internal virtual PictureBox PictureBox223
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox223;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox223 = value;
      }
    }

    internal virtual PictureBox PictureBox222
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox222;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox222 = value;
      }
    }

    internal virtual Label Label9
    {
      [DebuggerNonUserCode] get
      {
        return this._Label9;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label9 = value;
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

    internal virtual Button Aplicar
    {
      [DebuggerNonUserCode] get
      {
        return this._Aplicar;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Aplicar_Click);
        if (this._Aplicar != null)
          this._Aplicar.Click -= eventHandler;
        this._Aplicar = value;
        if (this._Aplicar == null)
          return;
        this._Aplicar.Click += eventHandler;
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

    internal virtual CheckBox PH
    {
      [DebuggerNonUserCode] get
      {
        return this._PH;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.PH_CheckedChanged);
        if (this._PH != null)
          this._PH.CheckedChanged -= eventHandler;
        this._PH = value;
        if (this._PH == null)
          return;
        this._PH.CheckedChanged += eventHandler;
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

    internal virtual CheckBox PK
    {
      [DebuggerNonUserCode] get
      {
        return this._PK;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.PK_CheckedChanged);
        if (this._PK != null)
          this._PK.CheckedChanged -= eventHandler;
        this._PK = value;
        if (this._PK == null)
          return;
        this._PK.CheckedChanged += eventHandler;
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

    internal virtual PictureBox PictureBox224
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox224;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox224 = value;
      }
    }

    internal virtual PictureBox PictureBox57
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox57;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox57 = value;
      }
    }

    internal virtual PictureBox PictureBox58
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox58;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox58 = value;
      }
    }

    internal virtual PictureBox PictureBox59
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox59;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox59 = value;
      }
    }

    internal virtual PictureBox PictureBox60
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox60;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox60 = value;
      }
    }

    internal virtual PictureBox PictureBox61
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox61;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox61 = value;
      }
    }

    internal virtual PictureBox PictureBox62
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox62;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox62 = value;
      }
    }

    internal virtual PictureBox PictureBox63
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox63;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox63 = value;
      }
    }

    internal virtual PictureBox PictureBox64
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox64;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox64 = value;
      }
    }

    internal virtual PictureBox PictureBox65
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox65;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox65 = value;
      }
    }

    internal virtual PictureBox PictureBox66
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox66;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox66 = value;
      }
    }

    internal virtual PictureBox PictureBox67
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox67;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox67 = value;
      }
    }

    internal virtual PictureBox PictureBox68
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox68;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox68 = value;
      }
    }

    internal virtual PictureBox PictureBox69
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox69;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox69 = value;
      }
    }

    internal virtual PictureBox PictureBox70
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox70;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox70 = value;
      }
    }

    internal virtual PictureBox PictureBox71
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox71;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox71 = value;
      }
    }

    internal virtual PictureBox PictureBox72
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox72;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox72 = value;
      }
    }

    internal virtual PictureBox PictureBox73
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox73;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox73 = value;
      }
    }

    internal virtual PictureBox PictureBox74
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox74;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox74 = value;
      }
    }

    internal virtual PictureBox PictureBox75
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox75;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox75 = value;
      }
    }

    internal virtual PictureBox PictureBox76
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox76;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox76 = value;
      }
    }

    internal virtual PictureBox PictureBox77
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox77;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox77 = value;
      }
    }

    internal virtual PictureBox PictureBox78
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox78;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox78 = value;
      }
    }

    internal virtual PictureBox PictureBox79
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox79;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox79 = value;
      }
    }

    internal virtual PictureBox PictureBox80
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox80;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox80 = value;
      }
    }

    internal virtual PictureBox PictureBox81
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox81;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox81 = value;
      }
    }

    internal virtual PictureBox PictureBox82
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox82;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox82 = value;
      }
    }

    internal virtual PictureBox PictureBox83
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox83;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox83 = value;
      }
    }

    internal virtual PictureBox PictureBox84
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox84;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox84 = value;
      }
    }

    internal virtual PictureBox PictureBox85
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox85;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox85 = value;
      }
    }

    internal virtual PictureBox PictureBox86
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox86;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox86 = value;
      }
    }

    internal virtual PictureBox PictureBox87
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox87;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox87 = value;
      }
    }

    internal virtual PictureBox PictureBox88
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox88;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox88 = value;
      }
    }

    internal virtual PictureBox PictureBox89
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox89;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox89 = value;
      }
    }

    internal virtual PictureBox PictureBox90
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox90;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox90 = value;
      }
    }

    internal virtual PictureBox PictureBox91
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox91;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox91 = value;
      }
    }

    internal virtual PictureBox PictureBox92
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox92;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox92 = value;
      }
    }

    internal virtual PictureBox PictureBox93
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox93;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox93 = value;
      }
    }

    internal virtual PictureBox PictureBox94
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox94;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox94 = value;
      }
    }

    internal virtual PictureBox PictureBox95
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox95;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox95 = value;
      }
    }

    internal virtual PictureBox PictureBox96
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox96;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox96 = value;
      }
    }

    internal virtual PictureBox PictureBox97
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox97;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox97 = value;
      }
    }

    internal virtual PictureBox PictureBox98
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox98;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox98 = value;
      }
    }

    internal virtual PictureBox PictureBox99
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox99;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox99 = value;
      }
    }

    internal virtual PictureBox PictureBox100
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox100;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox100 = value;
      }
    }

    internal virtual PictureBox PictureBox101
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox101;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox101 = value;
      }
    }

    internal virtual PictureBox PictureBox102
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox102;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox102 = value;
      }
    }

    internal virtual PictureBox PictureBox103
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox103;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox103 = value;
      }
    }

    internal virtual PictureBox PictureBox104
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox104;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox104 = value;
      }
    }

    internal virtual PictureBox PictureBox105
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox105;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox105 = value;
      }
    }

    internal virtual PictureBox PictureBox106
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox106;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox106 = value;
      }
    }

    internal virtual PictureBox PictureBox107
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox107;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox107 = value;
      }
    }

    internal virtual PictureBox PictureBox108
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox108;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox108 = value;
      }
    }

    internal virtual PictureBox PictureBox109
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox109;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox109 = value;
      }
    }

    internal virtual PictureBox PictureBox110
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox110;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox110 = value;
      }
    }

    internal virtual PictureBox PictureBox111
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox111;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox111 = value;
      }
    }

    internal virtual PictureBox PictureBox112
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox112;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox112 = value;
      }
    }

    internal virtual PictureBox PictureBox29
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox29;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox29 = value;
      }
    }

    internal virtual PictureBox PictureBox30
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox30;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox30 = value;
      }
    }

    internal virtual PictureBox PictureBox31
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox31;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox31 = value;
      }
    }

    internal virtual PictureBox PictureBox32
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox32;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox32 = value;
      }
    }

    internal virtual PictureBox PictureBox33
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox33;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox33 = value;
      }
    }

    internal virtual PictureBox PictureBox34
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox34;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox34 = value;
      }
    }

    internal virtual PictureBox PictureBox35
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox35;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox35 = value;
      }
    }

    internal virtual PictureBox PictureBox36
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox36;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox36 = value;
      }
    }

    internal virtual PictureBox PictureBox37
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox37;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox37 = value;
      }
    }

    internal virtual PictureBox PictureBox38
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox38;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox38 = value;
      }
    }

    internal virtual PictureBox PictureBox39
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox39;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox39 = value;
      }
    }

    internal virtual PictureBox PictureBox40
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox40;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox40 = value;
      }
    }

    internal virtual PictureBox PictureBox41
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox41;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox41 = value;
      }
    }

    internal virtual PictureBox PictureBox42
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox42;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox42 = value;
      }
    }

    internal virtual PictureBox PictureBox43
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox43;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox43 = value;
      }
    }

    internal virtual PictureBox PictureBox44
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox44;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox44 = value;
      }
    }

    internal virtual PictureBox PictureBox45
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox45;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox45 = value;
      }
    }

    internal virtual PictureBox PictureBox46
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox46;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox46 = value;
      }
    }

    internal virtual PictureBox PictureBox47
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox47;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox47 = value;
      }
    }

    internal virtual PictureBox PictureBox48
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox48;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox48 = value;
      }
    }

    internal virtual PictureBox PictureBox49
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox49;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox49 = value;
      }
    }

    internal virtual PictureBox PictureBox50
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox50;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox50 = value;
      }
    }

    internal virtual PictureBox PictureBox51
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox51;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox51 = value;
      }
    }

    internal virtual PictureBox PictureBox52
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox52;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox52 = value;
      }
    }

    internal virtual PictureBox PictureBox53
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox53;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox53 = value;
      }
    }

    internal virtual PictureBox PictureBox54
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox54;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox54 = value;
      }
    }

    internal virtual PictureBox PictureBox55
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox55;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox55 = value;
      }
    }

    internal virtual PictureBox PictureBox56
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox56;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox56 = value;
      }
    }

    internal virtual PictureBox PictureBox15
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox15;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox15 = value;
      }
    }

    internal virtual PictureBox PictureBox16
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox16;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox16 = value;
      }
    }

    internal virtual PictureBox PictureBox17
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox17;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox17 = value;
      }
    }

    internal virtual PictureBox PictureBox18
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox18;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox18 = value;
      }
    }

    internal virtual PictureBox PictureBox19
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox19;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox19 = value;
      }
    }

    internal virtual PictureBox PictureBox20
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox20;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox20 = value;
      }
    }

    internal virtual PictureBox PictureBox21
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox21;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox21 = value;
      }
    }

    internal virtual PictureBox PictureBox22
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox22;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox22 = value;
      }
    }

    internal virtual PictureBox PictureBox23
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox23;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox23 = value;
      }
    }

    internal virtual PictureBox PictureBox24
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox24;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox24 = value;
      }
    }

    internal virtual PictureBox PictureBox25
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox25;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox25 = value;
      }
    }

    internal virtual PictureBox PictureBox26
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox26;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox26 = value;
      }
    }

    internal virtual PictureBox PictureBox27
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox27;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox27 = value;
      }
    }

    internal virtual PictureBox PictureBox28
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox28;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox28 = value;
      }
    }

    internal virtual PictureBox PictureBox14
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox14;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox14 = value;
      }
    }

    internal virtual PictureBox PictureBox13
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox13;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox13 = value;
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
        this._PictureBox12 = value;
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
        this._PictureBox11 = value;
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
        this._PictureBox10 = value;
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
        this._PictureBox9 = value;
      }
    }

    internal virtual PictureBox PictureBox8
    {
      [DebuggerNonUserCode] get
      {
        return this._PictureBox8;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._PictureBox8 = value;
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
        this._PictureBox7 = value;
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
        this._PictureBox6 = value;
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
        this._PictureBox5 = value;
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

    internal virtual RadioButton Todos
    {
      [DebuggerNonUserCode] get
      {
        return this._Todos;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Todos_CheckedChanged);
        if (this._Todos != null)
          this._Todos.CheckedChanged -= eventHandler;
        this._Todos = value;
        if (this._Todos == null)
          return;
        this._Todos.CheckedChanged += eventHandler;
      }
    }

    internal virtual Label Charts
    {
      [DebuggerNonUserCode] get
      {
        return this._Charts;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Charts = value;
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

    internal virtual Label Maps
    {
      [DebuggerNonUserCode] get
      {
        return this._Maps;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Maps = value;
      }
    }

    internal virtual PictureBox FotoMapa
    {
      [DebuggerNonUserCode] get
      {
        return this._FotoMapa;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_11);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_10);
        MouseEventHandler mouseEventHandler3 = new MouseEventHandler(this.method_9);
        if (this._FotoMapa != null)
        {
          this._FotoMapa.MouseMove -= mouseEventHandler1;
          this._FotoMapa.MouseUp -= mouseEventHandler2;
          this._FotoMapa.MouseDown -= mouseEventHandler3;
        }
        this._FotoMapa = value;
        if (this._FotoMapa == null)
          return;
        this._FotoMapa.MouseMove += mouseEventHandler1;
        this._FotoMapa.MouseUp += mouseEventHandler2;
        this._FotoMapa.MouseDown += mouseEventHandler3;
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

    internal virtual RadioButton Baneados
    {
      [DebuggerNonUserCode] get
      {
        return this._Baneados;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.Baneados_CheckedChanged);
        if (this._Baneados != null)
          this._Baneados.CheckedChanged -= eventHandler;
        this._Baneados = value;
        if (this._Baneados == null)
          return;
        this._Baneados.CheckedChanged += eventHandler;
      }
    }

    internal virtual ListBox ListaMapas
    {
      [DebuggerNonUserCode] get
      {
        return this._ListaMapas;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.ListaMapas_SelectedIndexChanged);
        if (this._ListaMapas != null)
          this._ListaMapas.SelectedIndexChanged -= eventHandler;
        this._ListaMapas = value;
        if (this._ListaMapas == null)
          return;
        this._ListaMapas.SelectedIndexChanged += eventHandler;
      }
    }

    internal virtual GroupBox GroupBox1
    {
      [DebuggerNonUserCode] get
      {
        return this._GroupBox1;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._GroupBox1 = value;
      }
    }

    internal virtual GroupBox GroupBox2
    {
      [DebuggerNonUserCode] get
      {
        return this._GroupBox2;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._GroupBox2 = value;
      }
    }

    internal virtual GroupBox XXYY
    {
      [DebuggerNonUserCode] get
      {
        return this._XXYY;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._XXYY = value;
      }
    }

    internal virtual Label Label19
    {
      [DebuggerNonUserCode] get
      {
        return this._Label19;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Label19 = value;
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

    internal virtual ListBox VerTodosPJ
    {
      [DebuggerNonUserCode] get
      {
        return this._VerTodosPJ;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.VerTodosPJ_SelectedIndexChanged);
        if (this._VerTodosPJ != null)
          this._VerTodosPJ.SelectedIndexChanged -= eventHandler;
        this._VerTodosPJ = value;
        if (this._VerTodosPJ == null)
          return;
        this._VerTodosPJ.SelectedIndexChanged += eventHandler;
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
        EventHandler eventHandler = new EventHandler(this.method_7);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_17);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_16);
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

    internal virtual Button Cerrar
    {
      [DebuggerNonUserCode] get
      {
        return this._Cerrar;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        EventHandler eventHandler = new EventHandler(this.method_8);
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_19);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_18);
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

    internal virtual Button Buscar
    {
      [DebuggerNonUserCode] get
      {
        return this._Buscar;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        MouseEventHandler mouseEventHandler1 = new MouseEventHandler(this.method_13);
        MouseEventHandler mouseEventHandler2 = new MouseEventHandler(this.method_12);
        EventHandler eventHandler = new EventHandler(this.method_6);
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

    internal virtual Label Search
    {
      [DebuggerNonUserCode] get
      {
        return this._Search;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Search = value;
      }
    }

    internal virtual Label X
    {
      [DebuggerNonUserCode] get
      {
        return this._X;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._X = value;
      }
    }

    internal virtual Label YYY
    {
      [DebuggerNonUserCode] get
      {
        return this._YYY;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._YYY = value;
      }
    }

    internal virtual Label XXX
    {
      [DebuggerNonUserCode] get
      {
        return this._XXX;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._XXX = value;
      }
    }

    internal virtual Label YY
    {
      [DebuggerNonUserCode] get
      {
        return this._YY;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._YY = value;
      }
    }

    internal virtual Label XX
    {
      [DebuggerNonUserCode] get
      {
        return this._XX;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._XX = value;
      }
    }

    internal virtual Label Y
    {
      [DebuggerNonUserCode] get
      {
        return this._Y;
      }
      [DebuggerNonUserCode, MethodImpl(MethodImplOptions.Synchronized)] set
      {
        this._Y = value;
      }
    }

    public static MoveMaker DefInstance
    {
      get
      {
        if (MoveMaker.moveMaker_0 != null && !MoveMaker.moveMaker_0.IsDisposed)
          MoveMaker.moveMaker_0.BringToFront();
        else
          MoveMaker.moveMaker_0 = new MoveMaker();
        return MoveMaker.moveMaker_0;
      }
      set
      {
        MoveMaker.moveMaker_0 = value;
      }
    }

    [DebuggerNonUserCode]
    public MoveMaker()
    {
      this.Load += new EventHandler(this.MoveMaker_Load);
      this.Closing += new CancelEventHandler(this.MoveMaker_Closing);
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
      ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof (MoveMaker));
      this.Label2 = new Label();
      this.GameMaster = new RadioButton();
      this.PJOnline = new ListBox();
      this.Label23 = new Label();
      this.Chart = new Label();
      this.Acount = new TextBox();
      this.Baneado = new TextBox();
      this.BanUnBan = new Button();
      this.level = new TextBox();
      this.PN = new CheckBox();
      this.Account = new Label();
      this.Label6 = new Label();
      this.Label4 = new Label();
      this.Label5 = new Label();
      this.Personajes = new TextBox();
      this.Desconectador = new Button();
      this.Emergente = new ToolTip(this.icontainer_0);
      this.Reload = new Button();
      this.Label10 = new Label();
      this.Label11 = new Label();
      this.Label9 = new Label();
      this.Label8 = new Label();
      this.Aplicar = new Button();
      this.Label16 = new Label();
      this.Label15 = new Label();
      this.Label14 = new Label();
      this.PH = new CheckBox();
      this.Label12 = new Label();
      this.PK = new CheckBox();
      this.Label13 = new Label();
      this.Label7 = new Label();
      this.PersonajeSearch = new TextBox();
      this.Todos = new RadioButton();
      this.Charts = new Label();
      this.Maps = new Label();
      this.Label1 = new Label();
      this.Baneados = new RadioButton();
      this.ListaMapas = new ListBox();
      this.GroupBox1 = new GroupBox();
      this.GroupBox2 = new GroupBox();
      this.OnlineOFF = new PictureBox();
      this.OnlineON = new PictureBox();
      this.XXYY = new GroupBox();
      this.YYY = new Label();
      this.XXX = new Label();
      this.YY = new Label();
      this.XX = new Label();
      this.Y = new Label();
      this.X = new Label();
      this.Label19 = new Label();
      this.PictureBox500 = new PictureBox();
      this.PictureBox499 = new PictureBox();
      this.PictureBox498 = new PictureBox();
      this.PictureBox497 = new PictureBox();
      this.PictureBox496 = new PictureBox();
      this.PictureBox495 = new PictureBox();
      this.PictureBox494 = new PictureBox();
      this.PictureBox493 = new PictureBox();
      this.PictureBox492 = new PictureBox();
      this.PictureBox491 = new PictureBox();
      this.PictureBox490 = new PictureBox();
      this.PictureBox489 = new PictureBox();
      this.PictureBox488 = new PictureBox();
      this.PictureBox487 = new PictureBox();
      this.PictureBox486 = new PictureBox();
      this.PictureBox485 = new PictureBox();
      this.PictureBox484 = new PictureBox();
      this.PictureBox483 = new PictureBox();
      this.PictureBox482 = new PictureBox();
      this.PictureBox481 = new PictureBox();
      this.PictureBox480 = new PictureBox();
      this.PictureBox479 = new PictureBox();
      this.PictureBox478 = new PictureBox();
      this.PictureBox477 = new PictureBox();
      this.PictureBox476 = new PictureBox();
      this.PictureBox475 = new PictureBox();
      this.PictureBox474 = new PictureBox();
      this.PictureBox473 = new PictureBox();
      this.PictureBox472 = new PictureBox();
      this.PictureBox471 = new PictureBox();
      this.PictureBox470 = new PictureBox();
      this.PictureBox469 = new PictureBox();
      this.PictureBox468 = new PictureBox();
      this.PictureBox467 = new PictureBox();
      this.PictureBox466 = new PictureBox();
      this.PictureBox465 = new PictureBox();
      this.PictureBox464 = new PictureBox();
      this.PictureBox463 = new PictureBox();
      this.PictureBox462 = new PictureBox();
      this.PictureBox461 = new PictureBox();
      this.PictureBox460 = new PictureBox();
      this.PictureBox459 = new PictureBox();
      this.PictureBox458 = new PictureBox();
      this.PictureBox457 = new PictureBox();
      this.PictureBox456 = new PictureBox();
      this.PictureBox455 = new PictureBox();
      this.PictureBox454 = new PictureBox();
      this.PictureBox453 = new PictureBox();
      this.PictureBox452 = new PictureBox();
      this.PictureBox451 = new PictureBox();
      this.PictureBox450 = new PictureBox();
      this.PictureBox449 = new PictureBox();
      this.PictureBox225 = new PictureBox();
      this.PictureBox226 = new PictureBox();
      this.PictureBox227 = new PictureBox();
      this.PictureBox228 = new PictureBox();
      this.PictureBox229 = new PictureBox();
      this.PictureBox230 = new PictureBox();
      this.PictureBox231 = new PictureBox();
      this.PictureBox232 = new PictureBox();
      this.PictureBox233 = new PictureBox();
      this.PictureBox234 = new PictureBox();
      this.PictureBox235 = new PictureBox();
      this.PictureBox236 = new PictureBox();
      this.PictureBox237 = new PictureBox();
      this.PictureBox238 = new PictureBox();
      this.PictureBox239 = new PictureBox();
      this.PictureBox240 = new PictureBox();
      this.PictureBox241 = new PictureBox();
      this.PictureBox242 = new PictureBox();
      this.PictureBox243 = new PictureBox();
      this.PictureBox244 = new PictureBox();
      this.PictureBox245 = new PictureBox();
      this.PictureBox246 = new PictureBox();
      this.PictureBox247 = new PictureBox();
      this.PictureBox248 = new PictureBox();
      this.PictureBox249 = new PictureBox();
      this.PictureBox250 = new PictureBox();
      this.PictureBox251 = new PictureBox();
      this.PictureBox252 = new PictureBox();
      this.PictureBox253 = new PictureBox();
      this.PictureBox254 = new PictureBox();
      this.PictureBox255 = new PictureBox();
      this.PictureBox256 = new PictureBox();
      this.PictureBox257 = new PictureBox();
      this.PictureBox258 = new PictureBox();
      this.PictureBox259 = new PictureBox();
      this.PictureBox260 = new PictureBox();
      this.PictureBox261 = new PictureBox();
      this.PictureBox262 = new PictureBox();
      this.PictureBox263 = new PictureBox();
      this.PictureBox264 = new PictureBox();
      this.PictureBox265 = new PictureBox();
      this.PictureBox266 = new PictureBox();
      this.PictureBox267 = new PictureBox();
      this.PictureBox268 = new PictureBox();
      this.PictureBox269 = new PictureBox();
      this.PictureBox270 = new PictureBox();
      this.PictureBox271 = new PictureBox();
      this.PictureBox272 = new PictureBox();
      this.PictureBox273 = new PictureBox();
      this.PictureBox274 = new PictureBox();
      this.PictureBox275 = new PictureBox();
      this.PictureBox276 = new PictureBox();
      this.PictureBox277 = new PictureBox();
      this.PictureBox278 = new PictureBox();
      this.PictureBox279 = new PictureBox();
      this.PictureBox280 = new PictureBox();
      this.PictureBox281 = new PictureBox();
      this.PictureBox282 = new PictureBox();
      this.PictureBox283 = new PictureBox();
      this.PictureBox284 = new PictureBox();
      this.PictureBox285 = new PictureBox();
      this.PictureBox286 = new PictureBox();
      this.PictureBox287 = new PictureBox();
      this.PictureBox288 = new PictureBox();
      this.PictureBox289 = new PictureBox();
      this.PictureBox290 = new PictureBox();
      this.PictureBox291 = new PictureBox();
      this.PictureBox292 = new PictureBox();
      this.PictureBox293 = new PictureBox();
      this.PictureBox294 = new PictureBox();
      this.PictureBox295 = new PictureBox();
      this.PictureBox296 = new PictureBox();
      this.PictureBox297 = new PictureBox();
      this.PictureBox298 = new PictureBox();
      this.PictureBox299 = new PictureBox();
      this.PictureBox300 = new PictureBox();
      this.PictureBox301 = new PictureBox();
      this.PictureBox302 = new PictureBox();
      this.PictureBox303 = new PictureBox();
      this.PictureBox304 = new PictureBox();
      this.PictureBox305 = new PictureBox();
      this.PictureBox306 = new PictureBox();
      this.PictureBox307 = new PictureBox();
      this.PictureBox308 = new PictureBox();
      this.PictureBox309 = new PictureBox();
      this.PictureBox310 = new PictureBox();
      this.PictureBox311 = new PictureBox();
      this.PictureBox312 = new PictureBox();
      this.PictureBox313 = new PictureBox();
      this.PictureBox314 = new PictureBox();
      this.PictureBox315 = new PictureBox();
      this.PictureBox316 = new PictureBox();
      this.PictureBox317 = new PictureBox();
      this.PictureBox318 = new PictureBox();
      this.PictureBox319 = new PictureBox();
      this.PictureBox320 = new PictureBox();
      this.PictureBox321 = new PictureBox();
      this.PictureBox322 = new PictureBox();
      this.PictureBox323 = new PictureBox();
      this.PictureBox324 = new PictureBox();
      this.PictureBox325 = new PictureBox();
      this.PictureBox326 = new PictureBox();
      this.PictureBox327 = new PictureBox();
      this.PictureBox328 = new PictureBox();
      this.PictureBox329 = new PictureBox();
      this.PictureBox330 = new PictureBox();
      this.PictureBox331 = new PictureBox();
      this.PictureBox332 = new PictureBox();
      this.PictureBox333 = new PictureBox();
      this.PictureBox334 = new PictureBox();
      this.PictureBox335 = new PictureBox();
      this.PictureBox336 = new PictureBox();
      this.PictureBox337 = new PictureBox();
      this.PictureBox338 = new PictureBox();
      this.PictureBox339 = new PictureBox();
      this.PictureBox340 = new PictureBox();
      this.PictureBox341 = new PictureBox();
      this.PictureBox342 = new PictureBox();
      this.PictureBox343 = new PictureBox();
      this.PictureBox344 = new PictureBox();
      this.PictureBox345 = new PictureBox();
      this.PictureBox346 = new PictureBox();
      this.PictureBox347 = new PictureBox();
      this.PictureBox348 = new PictureBox();
      this.PictureBox349 = new PictureBox();
      this.PictureBox350 = new PictureBox();
      this.PictureBox351 = new PictureBox();
      this.PictureBox352 = new PictureBox();
      this.PictureBox353 = new PictureBox();
      this.PictureBox354 = new PictureBox();
      this.PictureBox355 = new PictureBox();
      this.PictureBox356 = new PictureBox();
      this.PictureBox357 = new PictureBox();
      this.PictureBox358 = new PictureBox();
      this.PictureBox359 = new PictureBox();
      this.PictureBox360 = new PictureBox();
      this.PictureBox361 = new PictureBox();
      this.PictureBox362 = new PictureBox();
      this.PictureBox363 = new PictureBox();
      this.PictureBox364 = new PictureBox();
      this.PictureBox365 = new PictureBox();
      this.PictureBox366 = new PictureBox();
      this.PictureBox367 = new PictureBox();
      this.PictureBox368 = new PictureBox();
      this.PictureBox369 = new PictureBox();
      this.PictureBox370 = new PictureBox();
      this.PictureBox371 = new PictureBox();
      this.PictureBox372 = new PictureBox();
      this.PictureBox373 = new PictureBox();
      this.PictureBox374 = new PictureBox();
      this.PictureBox375 = new PictureBox();
      this.PictureBox376 = new PictureBox();
      this.PictureBox377 = new PictureBox();
      this.PictureBox378 = new PictureBox();
      this.PictureBox379 = new PictureBox();
      this.PictureBox380 = new PictureBox();
      this.PictureBox381 = new PictureBox();
      this.PictureBox382 = new PictureBox();
      this.PictureBox383 = new PictureBox();
      this.PictureBox384 = new PictureBox();
      this.PictureBox385 = new PictureBox();
      this.PictureBox386 = new PictureBox();
      this.PictureBox387 = new PictureBox();
      this.PictureBox388 = new PictureBox();
      this.PictureBox389 = new PictureBox();
      this.PictureBox390 = new PictureBox();
      this.PictureBox391 = new PictureBox();
      this.PictureBox392 = new PictureBox();
      this.PictureBox393 = new PictureBox();
      this.PictureBox394 = new PictureBox();
      this.PictureBox395 = new PictureBox();
      this.PictureBox396 = new PictureBox();
      this.PictureBox397 = new PictureBox();
      this.PictureBox398 = new PictureBox();
      this.PictureBox399 = new PictureBox();
      this.PictureBox400 = new PictureBox();
      this.PictureBox401 = new PictureBox();
      this.PictureBox402 = new PictureBox();
      this.PictureBox403 = new PictureBox();
      this.PictureBox404 = new PictureBox();
      this.PictureBox405 = new PictureBox();
      this.PictureBox406 = new PictureBox();
      this.PictureBox407 = new PictureBox();
      this.PictureBox408 = new PictureBox();
      this.PictureBox409 = new PictureBox();
      this.PictureBox410 = new PictureBox();
      this.PictureBox411 = new PictureBox();
      this.PictureBox412 = new PictureBox();
      this.PictureBox413 = new PictureBox();
      this.PictureBox414 = new PictureBox();
      this.PictureBox415 = new PictureBox();
      this.PictureBox416 = new PictureBox();
      this.PictureBox417 = new PictureBox();
      this.PictureBox418 = new PictureBox();
      this.PictureBox419 = new PictureBox();
      this.PictureBox420 = new PictureBox();
      this.PictureBox421 = new PictureBox();
      this.PictureBox422 = new PictureBox();
      this.PictureBox423 = new PictureBox();
      this.PictureBox424 = new PictureBox();
      this.PictureBox425 = new PictureBox();
      this.PictureBox426 = new PictureBox();
      this.PictureBox427 = new PictureBox();
      this.PictureBox428 = new PictureBox();
      this.PictureBox429 = new PictureBox();
      this.PictureBox430 = new PictureBox();
      this.PictureBox431 = new PictureBox();
      this.PictureBox432 = new PictureBox();
      this.PictureBox433 = new PictureBox();
      this.PictureBox434 = new PictureBox();
      this.PictureBox435 = new PictureBox();
      this.PictureBox436 = new PictureBox();
      this.PictureBox437 = new PictureBox();
      this.PictureBox438 = new PictureBox();
      this.PictureBox439 = new PictureBox();
      this.PictureBox440 = new PictureBox();
      this.PictureBox441 = new PictureBox();
      this.PictureBox442 = new PictureBox();
      this.PictureBox443 = new PictureBox();
      this.PictureBox444 = new PictureBox();
      this.PictureBox445 = new PictureBox();
      this.PictureBox446 = new PictureBox();
      this.PictureBox447 = new PictureBox();
      this.PictureBox448 = new PictureBox();
      this.PictureBox113 = new PictureBox();
      this.PictureBox114 = new PictureBox();
      this.PictureBox115 = new PictureBox();
      this.PictureBox116 = new PictureBox();
      this.PictureBox117 = new PictureBox();
      this.PictureBox118 = new PictureBox();
      this.PictureBox119 = new PictureBox();
      this.PictureBox120 = new PictureBox();
      this.PictureBox121 = new PictureBox();
      this.PictureBox122 = new PictureBox();
      this.PictureBox123 = new PictureBox();
      this.PictureBox124 = new PictureBox();
      this.PictureBox125 = new PictureBox();
      this.PictureBox126 = new PictureBox();
      this.PictureBox127 = new PictureBox();
      this.PictureBox128 = new PictureBox();
      this.PictureBox129 = new PictureBox();
      this.PictureBox130 = new PictureBox();
      this.PictureBox131 = new PictureBox();
      this.PictureBox132 = new PictureBox();
      this.PictureBox133 = new PictureBox();
      this.PictureBox134 = new PictureBox();
      this.PictureBox135 = new PictureBox();
      this.PictureBox136 = new PictureBox();
      this.PictureBox137 = new PictureBox();
      this.PictureBox138 = new PictureBox();
      this.PictureBox139 = new PictureBox();
      this.PictureBox140 = new PictureBox();
      this.PictureBox141 = new PictureBox();
      this.PictureBox142 = new PictureBox();
      this.PictureBox143 = new PictureBox();
      this.PictureBox144 = new PictureBox();
      this.PictureBox145 = new PictureBox();
      this.PictureBox146 = new PictureBox();
      this.PictureBox147 = new PictureBox();
      this.PictureBox148 = new PictureBox();
      this.PictureBox149 = new PictureBox();
      this.PictureBox150 = new PictureBox();
      this.PictureBox151 = new PictureBox();
      this.PictureBox152 = new PictureBox();
      this.PictureBox153 = new PictureBox();
      this.PictureBox154 = new PictureBox();
      this.PictureBox155 = new PictureBox();
      this.PictureBox156 = new PictureBox();
      this.PictureBox157 = new PictureBox();
      this.PictureBox158 = new PictureBox();
      this.PictureBox159 = new PictureBox();
      this.PictureBox160 = new PictureBox();
      this.PictureBox161 = new PictureBox();
      this.PictureBox162 = new PictureBox();
      this.PictureBox163 = new PictureBox();
      this.PictureBox164 = new PictureBox();
      this.PictureBox165 = new PictureBox();
      this.PictureBox166 = new PictureBox();
      this.PictureBox167 = new PictureBox();
      this.PictureBox168 = new PictureBox();
      this.PictureBox169 = new PictureBox();
      this.PictureBox170 = new PictureBox();
      this.PictureBox171 = new PictureBox();
      this.PictureBox172 = new PictureBox();
      this.PictureBox173 = new PictureBox();
      this.PictureBox174 = new PictureBox();
      this.PictureBox175 = new PictureBox();
      this.PictureBox176 = new PictureBox();
      this.PictureBox177 = new PictureBox();
      this.PictureBox178 = new PictureBox();
      this.PictureBox179 = new PictureBox();
      this.PictureBox180 = new PictureBox();
      this.PictureBox181 = new PictureBox();
      this.PictureBox182 = new PictureBox();
      this.PictureBox183 = new PictureBox();
      this.PictureBox184 = new PictureBox();
      this.PictureBox185 = new PictureBox();
      this.PictureBox186 = new PictureBox();
      this.PictureBox187 = new PictureBox();
      this.PictureBox188 = new PictureBox();
      this.PictureBox189 = new PictureBox();
      this.PictureBox190 = new PictureBox();
      this.PictureBox191 = new PictureBox();
      this.PictureBox192 = new PictureBox();
      this.PictureBox193 = new PictureBox();
      this.PictureBox194 = new PictureBox();
      this.PictureBox195 = new PictureBox();
      this.PictureBox196 = new PictureBox();
      this.PictureBox197 = new PictureBox();
      this.PictureBox198 = new PictureBox();
      this.PictureBox199 = new PictureBox();
      this.PictureBox200 = new PictureBox();
      this.PictureBox201 = new PictureBox();
      this.PictureBox202 = new PictureBox();
      this.PictureBox203 = new PictureBox();
      this.PictureBox204 = new PictureBox();
      this.PictureBox205 = new PictureBox();
      this.PictureBox206 = new PictureBox();
      this.PictureBox207 = new PictureBox();
      this.PictureBox208 = new PictureBox();
      this.PictureBox209 = new PictureBox();
      this.PictureBox210 = new PictureBox();
      this.PictureBox211 = new PictureBox();
      this.PictureBox212 = new PictureBox();
      this.PictureBox213 = new PictureBox();
      this.PictureBox214 = new PictureBox();
      this.PictureBox215 = new PictureBox();
      this.PictureBox216 = new PictureBox();
      this.PictureBox217 = new PictureBox();
      this.PictureBox218 = new PictureBox();
      this.PictureBox219 = new PictureBox();
      this.PictureBox220 = new PictureBox();
      this.PictureBox221 = new PictureBox();
      this.PictureBox223 = new PictureBox();
      this.PictureBox222 = new PictureBox();
      this.PictureBox224 = new PictureBox();
      this.PictureBox57 = new PictureBox();
      this.PictureBox58 = new PictureBox();
      this.PictureBox59 = new PictureBox();
      this.PictureBox60 = new PictureBox();
      this.PictureBox61 = new PictureBox();
      this.PictureBox62 = new PictureBox();
      this.PictureBox63 = new PictureBox();
      this.PictureBox64 = new PictureBox();
      this.PictureBox65 = new PictureBox();
      this.PictureBox66 = new PictureBox();
      this.PictureBox67 = new PictureBox();
      this.PictureBox68 = new PictureBox();
      this.PictureBox69 = new PictureBox();
      this.PictureBox70 = new PictureBox();
      this.PictureBox71 = new PictureBox();
      this.PictureBox72 = new PictureBox();
      this.PictureBox73 = new PictureBox();
      this.PictureBox74 = new PictureBox();
      this.PictureBox75 = new PictureBox();
      this.PictureBox76 = new PictureBox();
      this.PictureBox77 = new PictureBox();
      this.PictureBox78 = new PictureBox();
      this.PictureBox79 = new PictureBox();
      this.PictureBox80 = new PictureBox();
      this.PictureBox81 = new PictureBox();
      this.PictureBox82 = new PictureBox();
      this.PictureBox83 = new PictureBox();
      this.PictureBox84 = new PictureBox();
      this.PictureBox85 = new PictureBox();
      this.PictureBox86 = new PictureBox();
      this.PictureBox87 = new PictureBox();
      this.PictureBox88 = new PictureBox();
      this.PictureBox89 = new PictureBox();
      this.PictureBox90 = new PictureBox();
      this.PictureBox91 = new PictureBox();
      this.PictureBox92 = new PictureBox();
      this.PictureBox93 = new PictureBox();
      this.PictureBox94 = new PictureBox();
      this.PictureBox95 = new PictureBox();
      this.PictureBox96 = new PictureBox();
      this.PictureBox97 = new PictureBox();
      this.PictureBox98 = new PictureBox();
      this.PictureBox99 = new PictureBox();
      this.PictureBox100 = new PictureBox();
      this.PictureBox101 = new PictureBox();
      this.PictureBox102 = new PictureBox();
      this.PictureBox103 = new PictureBox();
      this.PictureBox104 = new PictureBox();
      this.PictureBox105 = new PictureBox();
      this.PictureBox106 = new PictureBox();
      this.PictureBox107 = new PictureBox();
      this.PictureBox108 = new PictureBox();
      this.PictureBox109 = new PictureBox();
      this.PictureBox110 = new PictureBox();
      this.PictureBox111 = new PictureBox();
      this.PictureBox112 = new PictureBox();
      this.PictureBox29 = new PictureBox();
      this.PictureBox30 = new PictureBox();
      this.PictureBox31 = new PictureBox();
      this.PictureBox32 = new PictureBox();
      this.PictureBox33 = new PictureBox();
      this.PictureBox34 = new PictureBox();
      this.PictureBox35 = new PictureBox();
      this.PictureBox36 = new PictureBox();
      this.PictureBox37 = new PictureBox();
      this.PictureBox38 = new PictureBox();
      this.PictureBox39 = new PictureBox();
      this.PictureBox40 = new PictureBox();
      this.PictureBox41 = new PictureBox();
      this.PictureBox42 = new PictureBox();
      this.PictureBox43 = new PictureBox();
      this.PictureBox44 = new PictureBox();
      this.PictureBox45 = new PictureBox();
      this.PictureBox46 = new PictureBox();
      this.PictureBox47 = new PictureBox();
      this.PictureBox48 = new PictureBox();
      this.PictureBox49 = new PictureBox();
      this.PictureBox50 = new PictureBox();
      this.PictureBox51 = new PictureBox();
      this.PictureBox52 = new PictureBox();
      this.PictureBox53 = new PictureBox();
      this.PictureBox54 = new PictureBox();
      this.PictureBox55 = new PictureBox();
      this.PictureBox56 = new PictureBox();
      this.PictureBox15 = new PictureBox();
      this.PictureBox16 = new PictureBox();
      this.PictureBox17 = new PictureBox();
      this.PictureBox18 = new PictureBox();
      this.PictureBox19 = new PictureBox();
      this.PictureBox20 = new PictureBox();
      this.PictureBox21 = new PictureBox();
      this.PictureBox22 = new PictureBox();
      this.PictureBox23 = new PictureBox();
      this.PictureBox24 = new PictureBox();
      this.PictureBox25 = new PictureBox();
      this.PictureBox26 = new PictureBox();
      this.PictureBox27 = new PictureBox();
      this.PictureBox28 = new PictureBox();
      this.PictureBox14 = new PictureBox();
      this.PictureBox13 = new PictureBox();
      this.PictureBox12 = new PictureBox();
      this.PictureBox11 = new PictureBox();
      this.PictureBox10 = new PictureBox();
      this.PictureBox9 = new PictureBox();
      this.PictureBox8 = new PictureBox();
      this.PictureBox7 = new PictureBox();
      this.PictureBox6 = new PictureBox();
      this.PictureBox5 = new PictureBox();
      this.PictureBox4 = new PictureBox();
      this.PictureBox3 = new PictureBox();
      this.PictureBox2 = new PictureBox();
      this.PictureBox1 = new PictureBox();
      this.PJ1 = new PictureBox();
      this.FotoMapa = new PictureBox();
      this.Reloj = new System.Windows.Forms.Timer(this.icontainer_0);
      this.VerTodosPJ = new ListBox();
      this.Minimizar = new Button();
      this.Cerrar = new Button();
      this.Titulo = new Label();
      this.Buscar = new Button();
      this.Label3 = new Label();
      this.Search = new Label();
      this.GroupBox1.SuspendLayout();
      this.GroupBox2.SuspendLayout();
      ((ISupportInitialize) this.OnlineOFF).BeginInit();
      ((ISupportInitialize) this.OnlineON).BeginInit();
      this.XXYY.SuspendLayout();
      ((ISupportInitialize) this.PictureBox500).BeginInit();
      ((ISupportInitialize) this.PictureBox499).BeginInit();
      ((ISupportInitialize) this.PictureBox498).BeginInit();
      ((ISupportInitialize) this.PictureBox497).BeginInit();
      ((ISupportInitialize) this.PictureBox496).BeginInit();
      ((ISupportInitialize) this.PictureBox495).BeginInit();
      ((ISupportInitialize) this.PictureBox494).BeginInit();
      ((ISupportInitialize) this.PictureBox493).BeginInit();
      ((ISupportInitialize) this.PictureBox492).BeginInit();
      ((ISupportInitialize) this.PictureBox491).BeginInit();
      ((ISupportInitialize) this.PictureBox490).BeginInit();
      ((ISupportInitialize) this.PictureBox489).BeginInit();
      ((ISupportInitialize) this.PictureBox488).BeginInit();
      ((ISupportInitialize) this.PictureBox487).BeginInit();
      ((ISupportInitialize) this.PictureBox486).BeginInit();
      ((ISupportInitialize) this.PictureBox485).BeginInit();
      ((ISupportInitialize) this.PictureBox484).BeginInit();
      ((ISupportInitialize) this.PictureBox483).BeginInit();
      ((ISupportInitialize) this.PictureBox482).BeginInit();
      ((ISupportInitialize) this.PictureBox481).BeginInit();
      ((ISupportInitialize) this.PictureBox480).BeginInit();
      ((ISupportInitialize) this.PictureBox479).BeginInit();
      ((ISupportInitialize) this.PictureBox478).BeginInit();
      ((ISupportInitialize) this.PictureBox477).BeginInit();
      ((ISupportInitialize) this.PictureBox476).BeginInit();
      ((ISupportInitialize) this.PictureBox475).BeginInit();
      ((ISupportInitialize) this.PictureBox474).BeginInit();
      ((ISupportInitialize) this.PictureBox473).BeginInit();
      ((ISupportInitialize) this.PictureBox472).BeginInit();
      ((ISupportInitialize) this.PictureBox471).BeginInit();
      ((ISupportInitialize) this.PictureBox470).BeginInit();
      ((ISupportInitialize) this.PictureBox469).BeginInit();
      ((ISupportInitialize) this.PictureBox468).BeginInit();
      ((ISupportInitialize) this.PictureBox467).BeginInit();
      ((ISupportInitialize) this.PictureBox466).BeginInit();
      ((ISupportInitialize) this.PictureBox465).BeginInit();
      ((ISupportInitialize) this.PictureBox464).BeginInit();
      ((ISupportInitialize) this.PictureBox463).BeginInit();
      ((ISupportInitialize) this.PictureBox462).BeginInit();
      ((ISupportInitialize) this.PictureBox461).BeginInit();
      ((ISupportInitialize) this.PictureBox460).BeginInit();
      ((ISupportInitialize) this.PictureBox459).BeginInit();
      ((ISupportInitialize) this.PictureBox458).BeginInit();
      ((ISupportInitialize) this.PictureBox457).BeginInit();
      ((ISupportInitialize) this.PictureBox456).BeginInit();
      ((ISupportInitialize) this.PictureBox455).BeginInit();
      ((ISupportInitialize) this.PictureBox454).BeginInit();
      ((ISupportInitialize) this.PictureBox453).BeginInit();
      ((ISupportInitialize) this.PictureBox452).BeginInit();
      ((ISupportInitialize) this.PictureBox451).BeginInit();
      ((ISupportInitialize) this.PictureBox450).BeginInit();
      ((ISupportInitialize) this.PictureBox449).BeginInit();
      ((ISupportInitialize) this.PictureBox225).BeginInit();
      ((ISupportInitialize) this.PictureBox226).BeginInit();
      ((ISupportInitialize) this.PictureBox227).BeginInit();
      ((ISupportInitialize) this.PictureBox228).BeginInit();
      ((ISupportInitialize) this.PictureBox229).BeginInit();
      ((ISupportInitialize) this.PictureBox230).BeginInit();
      ((ISupportInitialize) this.PictureBox231).BeginInit();
      ((ISupportInitialize) this.PictureBox232).BeginInit();
      ((ISupportInitialize) this.PictureBox233).BeginInit();
      ((ISupportInitialize) this.PictureBox234).BeginInit();
      ((ISupportInitialize) this.PictureBox235).BeginInit();
      ((ISupportInitialize) this.PictureBox236).BeginInit();
      ((ISupportInitialize) this.PictureBox237).BeginInit();
      ((ISupportInitialize) this.PictureBox238).BeginInit();
      ((ISupportInitialize) this.PictureBox239).BeginInit();
      ((ISupportInitialize) this.PictureBox240).BeginInit();
      ((ISupportInitialize) this.PictureBox241).BeginInit();
      ((ISupportInitialize) this.PictureBox242).BeginInit();
      ((ISupportInitialize) this.PictureBox243).BeginInit();
      ((ISupportInitialize) this.PictureBox244).BeginInit();
      ((ISupportInitialize) this.PictureBox245).BeginInit();
      ((ISupportInitialize) this.PictureBox246).BeginInit();
      ((ISupportInitialize) this.PictureBox247).BeginInit();
      ((ISupportInitialize) this.PictureBox248).BeginInit();
      ((ISupportInitialize) this.PictureBox249).BeginInit();
      ((ISupportInitialize) this.PictureBox250).BeginInit();
      ((ISupportInitialize) this.PictureBox251).BeginInit();
      ((ISupportInitialize) this.PictureBox252).BeginInit();
      ((ISupportInitialize) this.PictureBox253).BeginInit();
      ((ISupportInitialize) this.PictureBox254).BeginInit();
      ((ISupportInitialize) this.PictureBox255).BeginInit();
      ((ISupportInitialize) this.PictureBox256).BeginInit();
      ((ISupportInitialize) this.PictureBox257).BeginInit();
      ((ISupportInitialize) this.PictureBox258).BeginInit();
      ((ISupportInitialize) this.PictureBox259).BeginInit();
      ((ISupportInitialize) this.PictureBox260).BeginInit();
      ((ISupportInitialize) this.PictureBox261).BeginInit();
      ((ISupportInitialize) this.PictureBox262).BeginInit();
      ((ISupportInitialize) this.PictureBox263).BeginInit();
      ((ISupportInitialize) this.PictureBox264).BeginInit();
      ((ISupportInitialize) this.PictureBox265).BeginInit();
      ((ISupportInitialize) this.PictureBox266).BeginInit();
      ((ISupportInitialize) this.PictureBox267).BeginInit();
      ((ISupportInitialize) this.PictureBox268).BeginInit();
      ((ISupportInitialize) this.PictureBox269).BeginInit();
      ((ISupportInitialize) this.PictureBox270).BeginInit();
      ((ISupportInitialize) this.PictureBox271).BeginInit();
      ((ISupportInitialize) this.PictureBox272).BeginInit();
      ((ISupportInitialize) this.PictureBox273).BeginInit();
      ((ISupportInitialize) this.PictureBox274).BeginInit();
      ((ISupportInitialize) this.PictureBox275).BeginInit();
      ((ISupportInitialize) this.PictureBox276).BeginInit();
      ((ISupportInitialize) this.PictureBox277).BeginInit();
      ((ISupportInitialize) this.PictureBox278).BeginInit();
      ((ISupportInitialize) this.PictureBox279).BeginInit();
      ((ISupportInitialize) this.PictureBox280).BeginInit();
      ((ISupportInitialize) this.PictureBox281).BeginInit();
      ((ISupportInitialize) this.PictureBox282).BeginInit();
      ((ISupportInitialize) this.PictureBox283).BeginInit();
      ((ISupportInitialize) this.PictureBox284).BeginInit();
      ((ISupportInitialize) this.PictureBox285).BeginInit();
      ((ISupportInitialize) this.PictureBox286).BeginInit();
      ((ISupportInitialize) this.PictureBox287).BeginInit();
      ((ISupportInitialize) this.PictureBox288).BeginInit();
      ((ISupportInitialize) this.PictureBox289).BeginInit();
      ((ISupportInitialize) this.PictureBox290).BeginInit();
      ((ISupportInitialize) this.PictureBox291).BeginInit();
      ((ISupportInitialize) this.PictureBox292).BeginInit();
      ((ISupportInitialize) this.PictureBox293).BeginInit();
      ((ISupportInitialize) this.PictureBox294).BeginInit();
      ((ISupportInitialize) this.PictureBox295).BeginInit();
      ((ISupportInitialize) this.PictureBox296).BeginInit();
      ((ISupportInitialize) this.PictureBox297).BeginInit();
      ((ISupportInitialize) this.PictureBox298).BeginInit();
      ((ISupportInitialize) this.PictureBox299).BeginInit();
      ((ISupportInitialize) this.PictureBox300).BeginInit();
      ((ISupportInitialize) this.PictureBox301).BeginInit();
      ((ISupportInitialize) this.PictureBox302).BeginInit();
      ((ISupportInitialize) this.PictureBox303).BeginInit();
      ((ISupportInitialize) this.PictureBox304).BeginInit();
      ((ISupportInitialize) this.PictureBox305).BeginInit();
      ((ISupportInitialize) this.PictureBox306).BeginInit();
      ((ISupportInitialize) this.PictureBox307).BeginInit();
      ((ISupportInitialize) this.PictureBox308).BeginInit();
      ((ISupportInitialize) this.PictureBox309).BeginInit();
      ((ISupportInitialize) this.PictureBox310).BeginInit();
      ((ISupportInitialize) this.PictureBox311).BeginInit();
      ((ISupportInitialize) this.PictureBox312).BeginInit();
      ((ISupportInitialize) this.PictureBox313).BeginInit();
      ((ISupportInitialize) this.PictureBox314).BeginInit();
      ((ISupportInitialize) this.PictureBox315).BeginInit();
      ((ISupportInitialize) this.PictureBox316).BeginInit();
      ((ISupportInitialize) this.PictureBox317).BeginInit();
      ((ISupportInitialize) this.PictureBox318).BeginInit();
      ((ISupportInitialize) this.PictureBox319).BeginInit();
      ((ISupportInitialize) this.PictureBox320).BeginInit();
      ((ISupportInitialize) this.PictureBox321).BeginInit();
      ((ISupportInitialize) this.PictureBox322).BeginInit();
      ((ISupportInitialize) this.PictureBox323).BeginInit();
      ((ISupportInitialize) this.PictureBox324).BeginInit();
      ((ISupportInitialize) this.PictureBox325).BeginInit();
      ((ISupportInitialize) this.PictureBox326).BeginInit();
      ((ISupportInitialize) this.PictureBox327).BeginInit();
      ((ISupportInitialize) this.PictureBox328).BeginInit();
      ((ISupportInitialize) this.PictureBox329).BeginInit();
      ((ISupportInitialize) this.PictureBox330).BeginInit();
      ((ISupportInitialize) this.PictureBox331).BeginInit();
      ((ISupportInitialize) this.PictureBox332).BeginInit();
      ((ISupportInitialize) this.PictureBox333).BeginInit();
      ((ISupportInitialize) this.PictureBox334).BeginInit();
      ((ISupportInitialize) this.PictureBox335).BeginInit();
      ((ISupportInitialize) this.PictureBox336).BeginInit();
      ((ISupportInitialize) this.PictureBox337).BeginInit();
      ((ISupportInitialize) this.PictureBox338).BeginInit();
      ((ISupportInitialize) this.PictureBox339).BeginInit();
      ((ISupportInitialize) this.PictureBox340).BeginInit();
      ((ISupportInitialize) this.PictureBox341).BeginInit();
      ((ISupportInitialize) this.PictureBox342).BeginInit();
      ((ISupportInitialize) this.PictureBox343).BeginInit();
      ((ISupportInitialize) this.PictureBox344).BeginInit();
      ((ISupportInitialize) this.PictureBox345).BeginInit();
      ((ISupportInitialize) this.PictureBox346).BeginInit();
      ((ISupportInitialize) this.PictureBox347).BeginInit();
      ((ISupportInitialize) this.PictureBox348).BeginInit();
      ((ISupportInitialize) this.PictureBox349).BeginInit();
      ((ISupportInitialize) this.PictureBox350).BeginInit();
      ((ISupportInitialize) this.PictureBox351).BeginInit();
      ((ISupportInitialize) this.PictureBox352).BeginInit();
      ((ISupportInitialize) this.PictureBox353).BeginInit();
      ((ISupportInitialize) this.PictureBox354).BeginInit();
      ((ISupportInitialize) this.PictureBox355).BeginInit();
      ((ISupportInitialize) this.PictureBox356).BeginInit();
      ((ISupportInitialize) this.PictureBox357).BeginInit();
      ((ISupportInitialize) this.PictureBox358).BeginInit();
      ((ISupportInitialize) this.PictureBox359).BeginInit();
      ((ISupportInitialize) this.PictureBox360).BeginInit();
      ((ISupportInitialize) this.PictureBox361).BeginInit();
      ((ISupportInitialize) this.PictureBox362).BeginInit();
      ((ISupportInitialize) this.PictureBox363).BeginInit();
      ((ISupportInitialize) this.PictureBox364).BeginInit();
      ((ISupportInitialize) this.PictureBox365).BeginInit();
      ((ISupportInitialize) this.PictureBox366).BeginInit();
      ((ISupportInitialize) this.PictureBox367).BeginInit();
      ((ISupportInitialize) this.PictureBox368).BeginInit();
      ((ISupportInitialize) this.PictureBox369).BeginInit();
      ((ISupportInitialize) this.PictureBox370).BeginInit();
      ((ISupportInitialize) this.PictureBox371).BeginInit();
      ((ISupportInitialize) this.PictureBox372).BeginInit();
      ((ISupportInitialize) this.PictureBox373).BeginInit();
      ((ISupportInitialize) this.PictureBox374).BeginInit();
      ((ISupportInitialize) this.PictureBox375).BeginInit();
      ((ISupportInitialize) this.PictureBox376).BeginInit();
      ((ISupportInitialize) this.PictureBox377).BeginInit();
      ((ISupportInitialize) this.PictureBox378).BeginInit();
      ((ISupportInitialize) this.PictureBox379).BeginInit();
      ((ISupportInitialize) this.PictureBox380).BeginInit();
      ((ISupportInitialize) this.PictureBox381).BeginInit();
      ((ISupportInitialize) this.PictureBox382).BeginInit();
      ((ISupportInitialize) this.PictureBox383).BeginInit();
      ((ISupportInitialize) this.PictureBox384).BeginInit();
      ((ISupportInitialize) this.PictureBox385).BeginInit();
      ((ISupportInitialize) this.PictureBox386).BeginInit();
      ((ISupportInitialize) this.PictureBox387).BeginInit();
      ((ISupportInitialize) this.PictureBox388).BeginInit();
      ((ISupportInitialize) this.PictureBox389).BeginInit();
      ((ISupportInitialize) this.PictureBox390).BeginInit();
      ((ISupportInitialize) this.PictureBox391).BeginInit();
      ((ISupportInitialize) this.PictureBox392).BeginInit();
      ((ISupportInitialize) this.PictureBox393).BeginInit();
      ((ISupportInitialize) this.PictureBox394).BeginInit();
      ((ISupportInitialize) this.PictureBox395).BeginInit();
      ((ISupportInitialize) this.PictureBox396).BeginInit();
      ((ISupportInitialize) this.PictureBox397).BeginInit();
      ((ISupportInitialize) this.PictureBox398).BeginInit();
      ((ISupportInitialize) this.PictureBox399).BeginInit();
      ((ISupportInitialize) this.PictureBox400).BeginInit();
      ((ISupportInitialize) this.PictureBox401).BeginInit();
      ((ISupportInitialize) this.PictureBox402).BeginInit();
      ((ISupportInitialize) this.PictureBox403).BeginInit();
      ((ISupportInitialize) this.PictureBox404).BeginInit();
      ((ISupportInitialize) this.PictureBox405).BeginInit();
      ((ISupportInitialize) this.PictureBox406).BeginInit();
      ((ISupportInitialize) this.PictureBox407).BeginInit();
      ((ISupportInitialize) this.PictureBox408).BeginInit();
      ((ISupportInitialize) this.PictureBox409).BeginInit();
      ((ISupportInitialize) this.PictureBox410).BeginInit();
      ((ISupportInitialize) this.PictureBox411).BeginInit();
      ((ISupportInitialize) this.PictureBox412).BeginInit();
      ((ISupportInitialize) this.PictureBox413).BeginInit();
      ((ISupportInitialize) this.PictureBox414).BeginInit();
      ((ISupportInitialize) this.PictureBox415).BeginInit();
      ((ISupportInitialize) this.PictureBox416).BeginInit();
      ((ISupportInitialize) this.PictureBox417).BeginInit();
      ((ISupportInitialize) this.PictureBox418).BeginInit();
      ((ISupportInitialize) this.PictureBox419).BeginInit();
      ((ISupportInitialize) this.PictureBox420).BeginInit();
      ((ISupportInitialize) this.PictureBox421).BeginInit();
      ((ISupportInitialize) this.PictureBox422).BeginInit();
      ((ISupportInitialize) this.PictureBox423).BeginInit();
      ((ISupportInitialize) this.PictureBox424).BeginInit();
      ((ISupportInitialize) this.PictureBox425).BeginInit();
      ((ISupportInitialize) this.PictureBox426).BeginInit();
      ((ISupportInitialize) this.PictureBox427).BeginInit();
      ((ISupportInitialize) this.PictureBox428).BeginInit();
      ((ISupportInitialize) this.PictureBox429).BeginInit();
      ((ISupportInitialize) this.PictureBox430).BeginInit();
      ((ISupportInitialize) this.PictureBox431).BeginInit();
      ((ISupportInitialize) this.PictureBox432).BeginInit();
      ((ISupportInitialize) this.PictureBox433).BeginInit();
      ((ISupportInitialize) this.PictureBox434).BeginInit();
      ((ISupportInitialize) this.PictureBox435).BeginInit();
      ((ISupportInitialize) this.PictureBox436).BeginInit();
      ((ISupportInitialize) this.PictureBox437).BeginInit();
      ((ISupportInitialize) this.PictureBox438).BeginInit();
      ((ISupportInitialize) this.PictureBox439).BeginInit();
      ((ISupportInitialize) this.PictureBox440).BeginInit();
      ((ISupportInitialize) this.PictureBox441).BeginInit();
      ((ISupportInitialize) this.PictureBox442).BeginInit();
      ((ISupportInitialize) this.PictureBox443).BeginInit();
      ((ISupportInitialize) this.PictureBox444).BeginInit();
      ((ISupportInitialize) this.PictureBox445).BeginInit();
      ((ISupportInitialize) this.PictureBox446).BeginInit();
      ((ISupportInitialize) this.PictureBox447).BeginInit();
      ((ISupportInitialize) this.PictureBox448).BeginInit();
      ((ISupportInitialize) this.PictureBox113).BeginInit();
      ((ISupportInitialize) this.PictureBox114).BeginInit();
      ((ISupportInitialize) this.PictureBox115).BeginInit();
      ((ISupportInitialize) this.PictureBox116).BeginInit();
      ((ISupportInitialize) this.PictureBox117).BeginInit();
      ((ISupportInitialize) this.PictureBox118).BeginInit();
      ((ISupportInitialize) this.PictureBox119).BeginInit();
      ((ISupportInitialize) this.PictureBox120).BeginInit();
      ((ISupportInitialize) this.PictureBox121).BeginInit();
      ((ISupportInitialize) this.PictureBox122).BeginInit();
      ((ISupportInitialize) this.PictureBox123).BeginInit();
      ((ISupportInitialize) this.PictureBox124).BeginInit();
      ((ISupportInitialize) this.PictureBox125).BeginInit();
      ((ISupportInitialize) this.PictureBox126).BeginInit();
      ((ISupportInitialize) this.PictureBox127).BeginInit();
      ((ISupportInitialize) this.PictureBox128).BeginInit();
      ((ISupportInitialize) this.PictureBox129).BeginInit();
      ((ISupportInitialize) this.PictureBox130).BeginInit();
      ((ISupportInitialize) this.PictureBox131).BeginInit();
      ((ISupportInitialize) this.PictureBox132).BeginInit();
      ((ISupportInitialize) this.PictureBox133).BeginInit();
      ((ISupportInitialize) this.PictureBox134).BeginInit();
      ((ISupportInitialize) this.PictureBox135).BeginInit();
      ((ISupportInitialize) this.PictureBox136).BeginInit();
      ((ISupportInitialize) this.PictureBox137).BeginInit();
      ((ISupportInitialize) this.PictureBox138).BeginInit();
      ((ISupportInitialize) this.PictureBox139).BeginInit();
      ((ISupportInitialize) this.PictureBox140).BeginInit();
      ((ISupportInitialize) this.PictureBox141).BeginInit();
      ((ISupportInitialize) this.PictureBox142).BeginInit();
      ((ISupportInitialize) this.PictureBox143).BeginInit();
      ((ISupportInitialize) this.PictureBox144).BeginInit();
      ((ISupportInitialize) this.PictureBox145).BeginInit();
      ((ISupportInitialize) this.PictureBox146).BeginInit();
      ((ISupportInitialize) this.PictureBox147).BeginInit();
      ((ISupportInitialize) this.PictureBox148).BeginInit();
      ((ISupportInitialize) this.PictureBox149).BeginInit();
      ((ISupportInitialize) this.PictureBox150).BeginInit();
      ((ISupportInitialize) this.PictureBox151).BeginInit();
      ((ISupportInitialize) this.PictureBox152).BeginInit();
      ((ISupportInitialize) this.PictureBox153).BeginInit();
      ((ISupportInitialize) this.PictureBox154).BeginInit();
      ((ISupportInitialize) this.PictureBox155).BeginInit();
      ((ISupportInitialize) this.PictureBox156).BeginInit();
      ((ISupportInitialize) this.PictureBox157).BeginInit();
      ((ISupportInitialize) this.PictureBox158).BeginInit();
      ((ISupportInitialize) this.PictureBox159).BeginInit();
      ((ISupportInitialize) this.PictureBox160).BeginInit();
      ((ISupportInitialize) this.PictureBox161).BeginInit();
      ((ISupportInitialize) this.PictureBox162).BeginInit();
      ((ISupportInitialize) this.PictureBox163).BeginInit();
      ((ISupportInitialize) this.PictureBox164).BeginInit();
      ((ISupportInitialize) this.PictureBox165).BeginInit();
      ((ISupportInitialize) this.PictureBox166).BeginInit();
      ((ISupportInitialize) this.PictureBox167).BeginInit();
      ((ISupportInitialize) this.PictureBox168).BeginInit();
      ((ISupportInitialize) this.PictureBox169).BeginInit();
      ((ISupportInitialize) this.PictureBox170).BeginInit();
      ((ISupportInitialize) this.PictureBox171).BeginInit();
      ((ISupportInitialize) this.PictureBox172).BeginInit();
      ((ISupportInitialize) this.PictureBox173).BeginInit();
      ((ISupportInitialize) this.PictureBox174).BeginInit();
      ((ISupportInitialize) this.PictureBox175).BeginInit();
      ((ISupportInitialize) this.PictureBox176).BeginInit();
      ((ISupportInitialize) this.PictureBox177).BeginInit();
      ((ISupportInitialize) this.PictureBox178).BeginInit();
      ((ISupportInitialize) this.PictureBox179).BeginInit();
      ((ISupportInitialize) this.PictureBox180).BeginInit();
      ((ISupportInitialize) this.PictureBox181).BeginInit();
      ((ISupportInitialize) this.PictureBox182).BeginInit();
      ((ISupportInitialize) this.PictureBox183).BeginInit();
      ((ISupportInitialize) this.PictureBox184).BeginInit();
      ((ISupportInitialize) this.PictureBox185).BeginInit();
      ((ISupportInitialize) this.PictureBox186).BeginInit();
      ((ISupportInitialize) this.PictureBox187).BeginInit();
      ((ISupportInitialize) this.PictureBox188).BeginInit();
      ((ISupportInitialize) this.PictureBox189).BeginInit();
      ((ISupportInitialize) this.PictureBox190).BeginInit();
      ((ISupportInitialize) this.PictureBox191).BeginInit();
      ((ISupportInitialize) this.PictureBox192).BeginInit();
      ((ISupportInitialize) this.PictureBox193).BeginInit();
      ((ISupportInitialize) this.PictureBox194).BeginInit();
      ((ISupportInitialize) this.PictureBox195).BeginInit();
      ((ISupportInitialize) this.PictureBox196).BeginInit();
      ((ISupportInitialize) this.PictureBox197).BeginInit();
      ((ISupportInitialize) this.PictureBox198).BeginInit();
      ((ISupportInitialize) this.PictureBox199).BeginInit();
      ((ISupportInitialize) this.PictureBox200).BeginInit();
      ((ISupportInitialize) this.PictureBox201).BeginInit();
      ((ISupportInitialize) this.PictureBox202).BeginInit();
      ((ISupportInitialize) this.PictureBox203).BeginInit();
      ((ISupportInitialize) this.PictureBox204).BeginInit();
      ((ISupportInitialize) this.PictureBox205).BeginInit();
      ((ISupportInitialize) this.PictureBox206).BeginInit();
      ((ISupportInitialize) this.PictureBox207).BeginInit();
      ((ISupportInitialize) this.PictureBox208).BeginInit();
      ((ISupportInitialize) this.PictureBox209).BeginInit();
      ((ISupportInitialize) this.PictureBox210).BeginInit();
      ((ISupportInitialize) this.PictureBox211).BeginInit();
      ((ISupportInitialize) this.PictureBox212).BeginInit();
      ((ISupportInitialize) this.PictureBox213).BeginInit();
      ((ISupportInitialize) this.PictureBox214).BeginInit();
      ((ISupportInitialize) this.PictureBox215).BeginInit();
      ((ISupportInitialize) this.PictureBox216).BeginInit();
      ((ISupportInitialize) this.PictureBox217).BeginInit();
      ((ISupportInitialize) this.PictureBox218).BeginInit();
      ((ISupportInitialize) this.PictureBox219).BeginInit();
      ((ISupportInitialize) this.PictureBox220).BeginInit();
      ((ISupportInitialize) this.PictureBox221).BeginInit();
      ((ISupportInitialize) this.PictureBox223).BeginInit();
      ((ISupportInitialize) this.PictureBox222).BeginInit();
      ((ISupportInitialize) this.PictureBox224).BeginInit();
      ((ISupportInitialize) this.PictureBox57).BeginInit();
      ((ISupportInitialize) this.PictureBox58).BeginInit();
      ((ISupportInitialize) this.PictureBox59).BeginInit();
      ((ISupportInitialize) this.PictureBox60).BeginInit();
      ((ISupportInitialize) this.PictureBox61).BeginInit();
      ((ISupportInitialize) this.PictureBox62).BeginInit();
      ((ISupportInitialize) this.PictureBox63).BeginInit();
      ((ISupportInitialize) this.PictureBox64).BeginInit();
      ((ISupportInitialize) this.PictureBox65).BeginInit();
      ((ISupportInitialize) this.PictureBox66).BeginInit();
      ((ISupportInitialize) this.PictureBox67).BeginInit();
      ((ISupportInitialize) this.PictureBox68).BeginInit();
      ((ISupportInitialize) this.PictureBox69).BeginInit();
      ((ISupportInitialize) this.PictureBox70).BeginInit();
      ((ISupportInitialize) this.PictureBox71).BeginInit();
      ((ISupportInitialize) this.PictureBox72).BeginInit();
      ((ISupportInitialize) this.PictureBox73).BeginInit();
      ((ISupportInitialize) this.PictureBox74).BeginInit();
      ((ISupportInitialize) this.PictureBox75).BeginInit();
      ((ISupportInitialize) this.PictureBox76).BeginInit();
      ((ISupportInitialize) this.PictureBox77).BeginInit();
      ((ISupportInitialize) this.PictureBox78).BeginInit();
      ((ISupportInitialize) this.PictureBox79).BeginInit();
      ((ISupportInitialize) this.PictureBox80).BeginInit();
      ((ISupportInitialize) this.PictureBox81).BeginInit();
      ((ISupportInitialize) this.PictureBox82).BeginInit();
      ((ISupportInitialize) this.PictureBox83).BeginInit();
      ((ISupportInitialize) this.PictureBox84).BeginInit();
      ((ISupportInitialize) this.PictureBox85).BeginInit();
      ((ISupportInitialize) this.PictureBox86).BeginInit();
      ((ISupportInitialize) this.PictureBox87).BeginInit();
      ((ISupportInitialize) this.PictureBox88).BeginInit();
      ((ISupportInitialize) this.PictureBox89).BeginInit();
      ((ISupportInitialize) this.PictureBox90).BeginInit();
      ((ISupportInitialize) this.PictureBox91).BeginInit();
      ((ISupportInitialize) this.PictureBox92).BeginInit();
      ((ISupportInitialize) this.PictureBox93).BeginInit();
      ((ISupportInitialize) this.PictureBox94).BeginInit();
      ((ISupportInitialize) this.PictureBox95).BeginInit();
      ((ISupportInitialize) this.PictureBox96).BeginInit();
      ((ISupportInitialize) this.PictureBox97).BeginInit();
      ((ISupportInitialize) this.PictureBox98).BeginInit();
      ((ISupportInitialize) this.PictureBox99).BeginInit();
      ((ISupportInitialize) this.PictureBox100).BeginInit();
      ((ISupportInitialize) this.PictureBox101).BeginInit();
      ((ISupportInitialize) this.PictureBox102).BeginInit();
      ((ISupportInitialize) this.PictureBox103).BeginInit();
      ((ISupportInitialize) this.PictureBox104).BeginInit();
      ((ISupportInitialize) this.PictureBox105).BeginInit();
      ((ISupportInitialize) this.PictureBox106).BeginInit();
      ((ISupportInitialize) this.PictureBox107).BeginInit();
      ((ISupportInitialize) this.PictureBox108).BeginInit();
      ((ISupportInitialize) this.PictureBox109).BeginInit();
      ((ISupportInitialize) this.PictureBox110).BeginInit();
      ((ISupportInitialize) this.PictureBox111).BeginInit();
      ((ISupportInitialize) this.PictureBox112).BeginInit();
      ((ISupportInitialize) this.PictureBox29).BeginInit();
      ((ISupportInitialize) this.PictureBox30).BeginInit();
      ((ISupportInitialize) this.PictureBox31).BeginInit();
      ((ISupportInitialize) this.PictureBox32).BeginInit();
      ((ISupportInitialize) this.PictureBox33).BeginInit();
      ((ISupportInitialize) this.PictureBox34).BeginInit();
      ((ISupportInitialize) this.PictureBox35).BeginInit();
      ((ISupportInitialize) this.PictureBox36).BeginInit();
      ((ISupportInitialize) this.PictureBox37).BeginInit();
      ((ISupportInitialize) this.PictureBox38).BeginInit();
      ((ISupportInitialize) this.PictureBox39).BeginInit();
      ((ISupportInitialize) this.PictureBox40).BeginInit();
      ((ISupportInitialize) this.PictureBox41).BeginInit();
      ((ISupportInitialize) this.PictureBox42).BeginInit();
      ((ISupportInitialize) this.PictureBox43).BeginInit();
      ((ISupportInitialize) this.PictureBox44).BeginInit();
      ((ISupportInitialize) this.PictureBox45).BeginInit();
      ((ISupportInitialize) this.PictureBox46).BeginInit();
      ((ISupportInitialize) this.PictureBox47).BeginInit();
      ((ISupportInitialize) this.PictureBox48).BeginInit();
      ((ISupportInitialize) this.PictureBox49).BeginInit();
      ((ISupportInitialize) this.PictureBox50).BeginInit();
      ((ISupportInitialize) this.PictureBox51).BeginInit();
      ((ISupportInitialize) this.PictureBox52).BeginInit();
      ((ISupportInitialize) this.PictureBox53).BeginInit();
      ((ISupportInitialize) this.PictureBox54).BeginInit();
      ((ISupportInitialize) this.PictureBox55).BeginInit();
      ((ISupportInitialize) this.PictureBox56).BeginInit();
      ((ISupportInitialize) this.PictureBox15).BeginInit();
      ((ISupportInitialize) this.PictureBox16).BeginInit();
      ((ISupportInitialize) this.PictureBox17).BeginInit();
      ((ISupportInitialize) this.PictureBox18).BeginInit();
      ((ISupportInitialize) this.PictureBox19).BeginInit();
      ((ISupportInitialize) this.PictureBox20).BeginInit();
      ((ISupportInitialize) this.PictureBox21).BeginInit();
      ((ISupportInitialize) this.PictureBox22).BeginInit();
      ((ISupportInitialize) this.PictureBox23).BeginInit();
      ((ISupportInitialize) this.PictureBox24).BeginInit();
      ((ISupportInitialize) this.PictureBox25).BeginInit();
      ((ISupportInitialize) this.PictureBox26).BeginInit();
      ((ISupportInitialize) this.PictureBox27).BeginInit();
      ((ISupportInitialize) this.PictureBox28).BeginInit();
      ((ISupportInitialize) this.PictureBox14).BeginInit();
      ((ISupportInitialize) this.PictureBox13).BeginInit();
      ((ISupportInitialize) this.PictureBox12).BeginInit();
      ((ISupportInitialize) this.PictureBox11).BeginInit();
      ((ISupportInitialize) this.PictureBox10).BeginInit();
      ((ISupportInitialize) this.PictureBox9).BeginInit();
      ((ISupportInitialize) this.PictureBox8).BeginInit();
      ((ISupportInitialize) this.PictureBox7).BeginInit();
      ((ISupportInitialize) this.PictureBox6).BeginInit();
      ((ISupportInitialize) this.PictureBox5).BeginInit();
      ((ISupportInitialize) this.PictureBox4).BeginInit();
      ((ISupportInitialize) this.PictureBox3).BeginInit();
      ((ISupportInitialize) this.PictureBox2).BeginInit();
      ((ISupportInitialize) this.PictureBox1).BeginInit();
      ((ISupportInitialize) this.PJ1).BeginInit();
      ((ISupportInitialize) this.FotoMapa).BeginInit();
      this.SuspendLayout();
      this.Label2.BorderStyle = BorderStyle.Fixed3D;
      Label label2_1 = this.Label2;
      Point point1 = new Point(560, 269);
      Point point2 = point1;
      label2_1.Location = point2;
      this.Label2.Name = "Label2";
      Label label2_2 = this.Label2;
      Size size1 = new Size(2, 40);
      Size size2 = size1;
      label2_2.Size = size2;
      this.Label2.TabIndex = 1889;
      this.GameMaster.AutoSize = true;
      this.GameMaster.BackColor = Color.Transparent;
      this.GameMaster.Cursor = Cursors.Hand;
      this.GameMaster.Font = new Font("Microsoft Sans Serif", 8f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.GameMaster.ForeColor = Color.Lime;
      RadioButton gameMaster1 = this.GameMaster;
      point1 = new Point(571, 290);
      Point point3 = point1;
      gameMaster1.Location = point3;
      this.GameMaster.Name = "GameMaster";
      RadioButton gameMaster2 = this.GameMaster;
      size1 = new Size(66, 17);
      Size size3 = size1;
      gameMaster2.Size = size3;
      this.GameMaster.TabIndex = 1888;
      this.GameMaster.Text = "> GM <";
      this.GameMaster.UseVisualStyleBackColor = false;
      this.PJOnline.Cursor = Cursors.Hand;
      this.PJOnline.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      ListBox pjOnline1 = this.PJOnline;
      point1 = new Point(690, 84);
      Point point4 = point1;
      pjOnline1.Location = point4;
      this.PJOnline.Name = "PJOnline";
      ListBox pjOnline2 = this.PJOnline;
      size1 = new Size(96, 420);
      Size size4 = size1;
      pjOnline2.Size = size4;
      this.PJOnline.TabIndex = 1371;
      this.PJOnline.TabStop = false;
      this.Label23.BorderStyle = BorderStyle.Fixed3D;
      Label label23_1 = this.Label23;
      point1 = new Point(690, 486);
      Point point5 = point1;
      label23_1.Location = point5;
      this.Label23.Name = "Label23";
      Label label23_2 = this.Label23;
      size1 = new Size(2, 60);
      Size size5 = size1;
      label23_2.Size = size5;
      this.Label23.TabIndex = 1836;
      this.Label23.Text = "Label23";
      Label chart1 = this.Chart;
      point1 = new Point(84, 7);
      Point point6 = point1;
      chart1.Location = point6;
      this.Chart.Name = "Chart";
      Label chart2 = this.Chart;
      size1 = new Size(74, 16);
      Size size6 = size1;
      chart2.Size = size6;
      this.Chart.TabIndex = 3;
      this.Chart.Text = "Personaje";
      this.Chart.TextAlign = ContentAlignment.TopCenter;
      this.Acount.Enabled = false;
      TextBox acount1 = this.Acount;
      point1 = new Point(2, 21);
      Point point7 = point1;
      acount1.Location = point7;
      this.Acount.Name = "Acount";
      this.Acount.ReadOnly = true;
      TextBox acount2 = this.Acount;
      size1 = new Size(82, 20);
      Size size7 = size1;
      acount2.Size = size7;
      this.Acount.TabIndex = 0;
      this.Acount.TabStop = false;
      this.Baneado.Enabled = false;
      this.Baneado.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox baneado1 = this.Baneado;
      point1 = new Point(82, 63);
      Point point8 = point1;
      baneado1.Location = point8;
      this.Baneado.Name = "Baneado";
      this.Baneado.ReadOnly = true;
      TextBox baneado2 = this.Baneado;
      size1 = new Size(68, 20);
      Size size8 = size1;
      baneado2.Size = size8;
      this.Baneado.TabIndex = 11;
      this.Baneado.TabStop = false;
      this.Baneado.TextAlign = HorizontalAlignment.Center;
      this.BanUnBan.BackColor = Color.DimGray;
      this.BanUnBan.Cursor = Cursors.Hand;
      this.BanUnBan.FlatStyle = FlatStyle.System;
      this.BanUnBan.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.BanUnBan.ForeColor = Color.Green;
      Button banUnBan1 = this.BanUnBan;
      point1 = new Point(55, 87);
      Point point9 = point1;
      banUnBan1.Location = point9;
      this.BanUnBan.Name = "BanUnBan";
      Button banUnBan2 = this.BanUnBan;
      size1 = new Size(88, 24);
      Size size9 = size1;
      banUnBan2.Size = size9;
      this.BanUnBan.TabIndex = 10;
      this.BanUnBan.TabStop = false;
      this.BanUnBan.Text = "Ban/UnBan";
      this.BanUnBan.UseVisualStyleBackColor = false;
      this.level.Enabled = false;
      this.level.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox level1 = this.level;
      point1 = new Point(46, 63);
      Point point10 = point1;
      level1.Location = point10;
      this.level.Name = "level";
      this.level.ReadOnly = true;
      TextBox level2 = this.level;
      size1 = new Size(28, 20);
      Size size10 = size1;
      level2.Size = size10;
      this.level.TabIndex = 7;
      this.level.TabStop = false;
      this.level.TextAlign = HorizontalAlignment.Center;
      this.PN.AutoSize = true;
      this.PN.BackColor = Color.Transparent;
      this.PN.Checked = true;
      this.PN.CheckState = CheckState.Checked;
      this.PN.Cursor = Cursors.Hand;
      this.PN.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.PN.ForeColor = Color.Silver;
      CheckBox pn1 = this.PN;
      point1 = new Point(60, 11);
      Point point11 = point1;
      pn1.Location = point11;
      this.PN.Name = "PN";
      CheckBox pn2 = this.PN;
      size1 = new Size(65, 17);
      Size size11 = size1;
      pn2.Size = size11;
      this.PN.TabIndex = 214;
      this.PN.TabStop = false;
      this.PN.Text = "Normal";
      this.PN.UseVisualStyleBackColor = false;
      Label account1 = this.Account;
      point1 = new Point(4, 7);
      Point point12 = point1;
      account1.Location = point12;
      this.Account.Name = "Account";
      Label account2 = this.Account;
      size1 = new Size(72, 16);
      Size size12 = size1;
      account2.Size = size12;
      this.Account.TabIndex = 2;
      this.Account.Text = "Cuenta";
      this.Account.TextAlign = ContentAlignment.TopCenter;
      this.Label6.AutoSize = true;
      Label label6_1 = this.Label6;
      point1 = new Point(4, 47);
      Point point13 = point1;
      label6_1.Location = point13;
      this.Label6.Name = "Label6";
      Label label6_2 = this.Label6;
      size1 = new Size(43, 13);
      Size size13 = size1;
      label6_2.Size = size13;
      this.Label6.TabIndex = 251;
      this.Label6.Text = "Online";
      this.Label4.AutoSize = true;
      Label label4_1 = this.Label4;
      point1 = new Point(50, 47);
      Point point14 = point1;
      label4_1.Location = point14;
      this.Label4.Name = "Label4";
      Label label4_2 = this.Label4;
      size1 = new Size(20, 13);
      Size size14 = size1;
      label4_2.Size = size14;
      this.Label4.TabIndex = 8;
      this.Label4.Text = "lvl";
      this.Label5.AutoSize = true;
      Label label5_1 = this.Label5;
      point1 = new Point(82, 47);
      Point point15 = point1;
      label5_1.Location = point15;
      this.Label5.Name = "Label5";
      Label label5_2 = this.Label5;
      size1 = new Size(73, 13);
      Size size15 = size1;
      label5_2.Size = size15;
      this.Label5.TabIndex = 12;
      this.Label5.Text = "Ban/UnBan";
      this.Personajes.Enabled = false;
      TextBox personajes1 = this.Personajes;
      point1 = new Point(84, 21);
      Point point16 = point1;
      personajes1.Location = point16;
      this.Personajes.Name = "Personajes";
      this.Personajes.ReadOnly = true;
      TextBox personajes2 = this.Personajes;
      size1 = new Size(80, 20);
      Size size16 = size1;
      personajes2.Size = size16;
      this.Personajes.TabIndex = 1;
      this.Personajes.TabStop = false;
      this.Desconectador.BackColor = Color.DimGray;
      this.Desconectador.Cursor = Cursors.Hand;
      this.Desconectador.FlatStyle = FlatStyle.System;
      this.Desconectador.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Desconectador.ForeColor = Color.Red;
      Button desconectador1 = this.Desconectador;
      point1 = new Point(10, 87);
      Point point17 = point1;
      desconectador1.Location = point17;
      this.Desconectador.Name = "Desconectador";
      Button desconectador2 = this.Desconectador;
      size1 = new Size(28, 24);
      Size size17 = size1;
      desconectador2.Size = size17;
      this.Desconectador.TabIndex = 13;
      this.Desconectador.TabStop = false;
      this.Desconectador.Text = "Off";
      this.Desconectador.UseVisualStyleBackColor = false;
      this.Emergente.AutomaticDelay = 5000;
      this.Emergente.AutoPopDelay = 5000000;
      this.Emergente.InitialDelay = 5;
      this.Emergente.ReshowDelay = 1;
      this.Emergente.ShowAlways = true;
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
      point1 = new Point(645, 274);
      Point point18 = point1;
      reload1.Location = point18;
      this.Reload.Name = "Reload";
      Button reload2 = this.Reload;
      size1 = new Size(40, 31);
      Size size18 = size1;
      reload2.Size = size18;
      this.Reload.TabIndex = 1887;
      this.Reload.TabStop = false;
      this.Emergente.SetToolTip((Control) this.Reload, "Refresh / ReLoad");
      this.Reload.UseVisualStyleBackColor = false;
      this.Label10.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label10_1 = this.Label10;
      point1 = new Point(64, 55);
      Point point19 = point1;
      label10_1.Location = point19;
      this.Label10.Name = "Label10";
      Label label10_2 = this.Label10;
      size1 = new Size(22, 14);
      Size size19 = size1;
      label10_2.Size = size19;
      this.Label10.TabIndex = 851;
      this.Label10.Text = "Y : ";
      this.Label11.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label11_1 = this.Label11;
      point1 = new Point(10, 55);
      Point point20 = point1;
      label11_1.Location = point20;
      this.Label11.Name = "Label11";
      Label label11_2 = this.Label11;
      size1 = new Size(22, 14);
      Size size20 = size1;
      label11_2.Size = size20;
      this.Label11.TabIndex = 850;
      this.Label11.Text = "X : ";
      this.Label9.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label9_1 = this.Label9;
      point1 = new Point(64, 11);
      Point point21 = point1;
      label9_1.Location = point21;
      this.Label9.Name = "Label9";
      Label label9_2 = this.Label9;
      size1 = new Size(22, 14);
      Size size21 = size1;
      label9_2.Size = size21;
      this.Label9.TabIndex = 847;
      this.Label9.Text = "Y : ";
      this.Label8.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label8_1 = this.Label8;
      point1 = new Point(10, 11);
      Point point22 = point1;
      label8_1.Location = point22;
      this.Label8.Name = "Label8";
      Label label8_2 = this.Label8;
      size1 = new Size(22, 14);
      Size size22 = size1;
      label8_2.Size = size22;
      this.Label8.TabIndex = 846;
      this.Label8.Text = "X : ";
      this.Aplicar.BackColor = Color.DimGray;
      this.Aplicar.Cursor = Cursors.Hand;
      this.Aplicar.FlatStyle = FlatStyle.System;
      this.Aplicar.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Aplicar.ForeColor = Color.Black;
      Button aplicar1 = this.Aplicar;
      point1 = new Point(8, 75);
      Point point23 = point1;
      aplicar1.Location = point23;
      this.Aplicar.Name = "Aplicar";
      Button aplicar2 = this.Aplicar;
      size1 = new Size(152, 24);
      Size size23 = size1;
      aplicar2.Size = size23;
      this.Aplicar.TabIndex = 860;
      this.Aplicar.TabStop = false;
      this.Aplicar.Text = "Aplicar Coordenadas";
      this.Aplicar.UseVisualStyleBackColor = false;
      this.Label16.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label16_1 = this.Label16;
      point1 = new Point(122, 55);
      Point point24 = point1;
      label16_1.Location = point24;
      this.Label16.Name = "Label16";
      Label label16_2 = this.Label16;
      size1 = new Size(40, 14);
      Size size24 = size1;
      label16_2.Size = size24;
      this.Label16.TabIndex = 859;
      this.Label16.Text = "Mouse";
      this.Label15.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label15_1 = this.Label15;
      point1 = new Point(122, 33);
      Point point25 = point1;
      label15_1.Location = point25;
      this.Label15.Name = "Label15";
      Label label15_2 = this.Label15;
      size1 = new Size(40, 14);
      Size size25 = size1;
      label15_2.Size = size25;
      this.Label15.TabIndex = 858;
      this.Label15.Text = "Move";
      this.Label14.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label14_1 = this.Label14;
      point1 = new Point(122, 11);
      Point point26 = point1;
      label14_1.Location = point26;
      this.Label14.Name = "Label14";
      Label label14_2 = this.Label14;
      size1 = new Size(40, 14);
      Size size26 = size1;
      label14_2.Size = size26;
      this.Label14.TabIndex = 857;
      this.Label14.Text = "Char";
      this.PH.AutoSize = true;
      this.PH.BackColor = Color.Transparent;
      this.PH.Checked = true;
      this.PH.CheckState = CheckState.Checked;
      this.PH.Cursor = Cursors.Hand;
      this.PH.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.PH.ForeColor = Color.DeepSkyBlue;
      CheckBox ph1 = this.PH;
      point1 = new Point(8, 11);
      Point point27 = point1;
      ph1.Location = point27;
      this.PH.Name = "PH";
      CheckBox ph2 = this.PH;
      size1 = new Size(53, 17);
      Size size27 = size1;
      ph2.Size = size27;
      this.PH.TabIndex = 212;
      this.PH.TabStop = false;
      this.PH.Text = "Hero";
      this.PH.UseVisualStyleBackColor = false;
      this.Label12.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label12_1 = this.Label12;
      point1 = new Point(64, 33);
      Point point28 = point1;
      label12_1.Location = point28;
      this.Label12.Name = "Label12";
      Label label12_2 = this.Label12;
      size1 = new Size(22, 14);
      Size size28 = size1;
      label12_2.Size = size28;
      this.Label12.TabIndex = 855;
      this.Label12.Text = "Y : ";
      this.PK.AutoSize = true;
      this.PK.BackColor = Color.Transparent;
      this.PK.Checked = true;
      this.PK.CheckState = CheckState.Checked;
      this.PK.Cursor = Cursors.Hand;
      this.PK.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.PK.ForeColor = Color.Red;
      CheckBox pk1 = this.PK;
      point1 = new Point(124, 11);
      Point point29 = point1;
      pk1.Location = point29;
      this.PK.Name = "PK";
      CheckBox pk2 = this.PK;
      size1 = new Size(42, 17);
      Size size29 = size1;
      pk2.Size = size29;
      this.PK.TabIndex = 213;
      this.PK.TabStop = false;
      this.PK.Text = "PK";
      this.PK.UseVisualStyleBackColor = false;
      this.Label13.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label label13_1 = this.Label13;
      point1 = new Point(10, 33);
      Point point30 = point1;
      label13_1.Location = point30;
      this.Label13.Name = "Label13";
      Label label13_2 = this.Label13;
      size1 = new Size(22, 14);
      Size size30 = size1;
      label13_2.Size = size30;
      this.Label13.TabIndex = 854;
      this.Label13.Text = "X : ";
      this.Label7.BorderStyle = BorderStyle.Fixed3D;
      Label label7_1 = this.Label7;
      point1 = new Point(638, 269);
      Point point31 = point1;
      label7_1.Location = point31;
      this.Label7.Name = "Label7";
      Label label7_2 = this.Label7;
      size1 = new Size(2, 40);
      Size size31 = size1;
      label7_2.Size = size31;
      this.Label7.TabIndex = 1374;
      this.PersonajeSearch.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      TextBox personajeSearch1 = this.PersonajeSearch;
      point1 = new Point(690, 527);
      Point point32 = point1;
      personajeSearch1.Location = point32;
      this.PersonajeSearch.Name = "PersonajeSearch";
      TextBox personajeSearch2 = this.PersonajeSearch;
      size1 = new Size(96, 20);
      Size size32 = size1;
      personajeSearch2.Size = size32;
      this.PersonajeSearch.TabIndex = 1383;
      this.PersonajeSearch.TabStop = false;
      this.PersonajeSearch.TextAlign = HorizontalAlignment.Center;
      this.Todos.BackColor = Color.Transparent;
      this.Todos.CheckAlign = ContentAlignment.TopCenter;
      this.Todos.Checked = true;
      this.Todos.Cursor = Cursors.Hand;
      this.Todos.Font = new Font("Microsoft Sans Serif", 8f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Todos.ForeColor = Color.Blue;
      RadioButton todos1 = this.Todos;
      point1 = new Point(531, 273);
      Point point33 = point1;
      todos1.Location = point33;
      this.Todos.Name = "Todos";
      RadioButton todos2 = this.Todos;
      size1 = new Size(28, 33);
      Size size33 = size1;
      todos2.Size = size33;
      this.Todos.TabIndex = 1369;
      this.Todos.TabStop = true;
      this.Todos.Text = "All";
      this.Todos.TextAlign = ContentAlignment.BottomCenter;
      this.Todos.UseVisualStyleBackColor = false;
      this.Charts.BackColor = Color.Transparent;
      this.Charts.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Charts.ForeColor = Color.DimGray;
      Label charts1 = this.Charts;
      point1 = new Point(696, 37);
      Point point34 = point1;
      charts1.Location = point34;
      this.Charts.Name = "Charts";
      Label charts2 = this.Charts;
      size1 = new Size(86, 14);
      Size size34 = size1;
      charts2.Size = size34;
      this.Charts.TabIndex = 1382;
      this.Charts.Text = "Personajes";
      this.Charts.TextAlign = ContentAlignment.TopCenter;
      this.Maps.BackColor = Color.Transparent;
      this.Maps.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Maps.ForeColor = Color.DimGray;
      Label maps1 = this.Maps;
      point1 = new Point(564, 37);
      Point point35 = point1;
      maps1.Location = point35;
      this.Maps.Name = "Maps";
      Label maps2 = this.Maps;
      size1 = new Size(86, 14);
      Size size35 = size1;
      maps2.Size = size35;
      this.Maps.TabIndex = 1379;
      this.Maps.Text = "Mapas";
      this.Maps.TextAlign = ContentAlignment.TopCenter;
      this.Label1.BorderStyle = BorderStyle.Fixed3D;
      Label label1_1 = this.Label1;
      point1 = new Point(527, 25);
      Point point36 = point1;
      label1_1.Location = point36;
      this.Label1.Name = "Label1";
      Label label1_2 = this.Label1;
      size1 = new Size(2, 522);
      Size size36 = size1;
      label1_2.Size = size36;
      this.Label1.TabIndex = 1368;
      this.Label1.Text = "Label1";
      this.Baneados.AutoSize = true;
      this.Baneados.BackColor = Color.Transparent;
      this.Baneados.Cursor = Cursors.Hand;
      this.Baneados.Font = new Font("Microsoft Sans Serif", 8f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Baneados.ForeColor = Color.Red;
      RadioButton baneados1 = this.Baneados;
      point1 = new Point(571, 272);
      Point point37 = point1;
      baneados1.Location = point37;
      this.Baneados.Name = "Baneados";
      RadioButton baneados2 = this.Baneados;
      size1 = new Size(61, 17);
      Size size37 = size1;
      baneados2.Size = size37;
      this.Baneados.TabIndex = 1370;
      this.Baneados.Text = "Baned";
      this.Baneados.UseVisualStyleBackColor = false;
      this.ListaMapas.Cursor = Cursors.Hand;
      this.ListaMapas.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      ListBox listaMapas1 = this.ListaMapas;
      point1 = new Point(528, 58);
      Point point38 = point1;
      listaMapas1.Location = point38;
      this.ListaMapas.Name = "ListaMapas";
      ListBox listaMapas2 = this.ListaMapas;
      size1 = new Size(162, 212);
      Size size38 = size1;
      listaMapas2.Size = size38;
      this.ListaMapas.TabIndex = 1366;
      this.ListaMapas.TabStop = false;
      this.GroupBox1.BackColor = Color.Transparent;
      this.GroupBox1.Controls.Add((Control) this.PN);
      this.GroupBox1.Controls.Add((Control) this.PH);
      this.GroupBox1.Controls.Add((Control) this.PK);
      this.GroupBox1.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.GroupBox1.ForeColor = Color.DimGray;
      GroupBox groupBox1_1 = this.GroupBox1;
      point1 = new Point(527, 302);
      Point point39 = point1;
      groupBox1_1.Location = point39;
      this.GroupBox1.Name = "GroupBox1";
      GroupBox groupBox1_2 = this.GroupBox1;
      size1 = new Size(166, 32);
      Size size39 = size1;
      groupBox1_2.Size = size39;
      this.GroupBox1.TabIndex = 1372;
      this.GroupBox1.TabStop = false;
      this.GroupBox2.BackColor = Color.Transparent;
      this.GroupBox2.Controls.Add((Control) this.Desconectador);
      this.GroupBox2.Controls.Add((Control) this.Personajes);
      this.GroupBox2.Controls.Add((Control) this.Chart);
      this.GroupBox2.Controls.Add((Control) this.Acount);
      this.GroupBox2.Controls.Add((Control) this.Baneado);
      this.GroupBox2.Controls.Add((Control) this.BanUnBan);
      this.GroupBox2.Controls.Add((Control) this.level);
      this.GroupBox2.Controls.Add((Control) this.Account);
      this.GroupBox2.Controls.Add((Control) this.Label6);
      this.GroupBox2.Controls.Add((Control) this.Label4);
      this.GroupBox2.Controls.Add((Control) this.Label5);
      this.GroupBox2.Controls.Add((Control) this.OnlineOFF);
      this.GroupBox2.Controls.Add((Control) this.OnlineON);
      this.GroupBox2.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.GroupBox2.ForeColor = Color.DimGray;
      GroupBox groupBox2_1 = this.GroupBox2;
      point1 = new Point(527, 328);
      Point point40 = point1;
      groupBox2_1.Location = point40;
      this.GroupBox2.Name = "GroupBox2";
      GroupBox groupBox2_2 = this.GroupBox2;
      size1 = new Size(165, 122);
      Size size40 = size1;
      groupBox2_2.Size = size40;
      this.GroupBox2.TabIndex = 1373;
      this.GroupBox2.TabStop = false;
      // ISSUE: reference to a compiler-generated method
      this.OnlineOFF.Image = (Image) EmbeddedResources.smethod_89();
      PictureBox onlineOff1 = this.OnlineOFF;
      point1 = new Point(18, 67);
      Point point41 = point1;
      onlineOff1.Location = point41;
      this.OnlineOFF.Name = "OnlineOFF";
      PictureBox onlineOff2 = this.OnlineOFF;
      size1 = new Size(14, 14);
      Size size41 = size1;
      onlineOff2.Size = size41;
      this.OnlineOFF.TabIndex = 253;
      this.OnlineOFF.TabStop = false;
      // ISSUE: reference to a compiler-generated method
      this.OnlineON.Image = (Image) EmbeddedResources.smethod_92();
      PictureBox onlineOn1 = this.OnlineON;
      point1 = new Point(18, 67);
      Point point42 = point1;
      onlineOn1.Location = point42;
      this.OnlineON.Name = "OnlineON";
      PictureBox onlineOn2 = this.OnlineON;
      size1 = new Size(14, 14);
      Size size42 = size1;
      onlineOn2.Size = size42;
      this.OnlineON.TabIndex = 252;
      this.OnlineON.TabStop = false;
      this.OnlineON.Visible = false;
      this.XXYY.BackColor = Color.Transparent;
      this.XXYY.Controls.Add((Control) this.YYY);
      this.XXYY.Controls.Add((Control) this.XXX);
      this.XXYY.Controls.Add((Control) this.YY);
      this.XXYY.Controls.Add((Control) this.XX);
      this.XXYY.Controls.Add((Control) this.Y);
      this.XXYY.Controls.Add((Control) this.X);
      this.XXYY.Controls.Add((Control) this.Aplicar);
      this.XXYY.Controls.Add((Control) this.Label16);
      this.XXYY.Controls.Add((Control) this.Label15);
      this.XXYY.Controls.Add((Control) this.Label14);
      this.XXYY.Controls.Add((Control) this.Label12);
      this.XXYY.Controls.Add((Control) this.Label13);
      this.XXYY.Controls.Add((Control) this.Label10);
      this.XXYY.Controls.Add((Control) this.Label11);
      this.XXYY.Controls.Add((Control) this.Label9);
      this.XXYY.Controls.Add((Control) this.Label8);
      GroupBox xxyy1 = this.XXYY;
      point1 = new Point(527, 444);
      Point point43 = point1;
      xxyy1.Location = point43;
      this.XXYY.Name = "XXYY";
      GroupBox xxyy2 = this.XXYY;
      size1 = new Size(166, 103);
      Size size43 = size1;
      xxyy2.Size = size43;
      this.XXYY.TabIndex = 1375;
      this.XXYY.TabStop = false;
      this.YYY.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label yyy1 = this.YYY;
      point1 = new Point(84, 55);
      Point point44 = point1;
      yyy1.Location = point44;
      this.YYY.Name = "YYY";
      Label yyy2 = this.YYY;
      size1 = new Size(26, 13);
      Size size44 = size1;
      yyy2.Size = size44;
      this.YYY.TabIndex = 865;
      this.YYY.TextAlign = ContentAlignment.MiddleRight;
      this.XXX.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label xxx1 = this.XXX;
      point1 = new Point(30, 55);
      Point point45 = point1;
      xxx1.Location = point45;
      this.XXX.Name = "XXX";
      Label xxx2 = this.XXX;
      size1 = new Size(26, 13);
      Size size45 = size1;
      xxx2.Size = size45;
      this.XXX.TabIndex = 864;
      this.XXX.TextAlign = ContentAlignment.MiddleRight;
      this.YY.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label yy1 = this.YY;
      point1 = new Point(84, 33);
      Point point46 = point1;
      yy1.Location = point46;
      this.YY.Name = "YY";
      Label yy2 = this.YY;
      size1 = new Size(26, 13);
      Size size46 = size1;
      yy2.Size = size46;
      this.YY.TabIndex = 863;
      this.YY.Text = "0";
      this.YY.TextAlign = ContentAlignment.MiddleRight;
      this.XX.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label xx1 = this.XX;
      point1 = new Point(30, 33);
      Point point47 = point1;
      xx1.Location = point47;
      this.XX.Name = "XX";
      Label xx2 = this.XX;
      size1 = new Size(26, 13);
      Size size47 = size1;
      xx2.Size = size47;
      this.XX.TabIndex = 862;
      this.XX.Text = "0";
      this.XX.TextAlign = ContentAlignment.MiddleRight;
      this.Y.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label y1 = this.Y;
      point1 = new Point(84, 11);
      Point point48 = point1;
      y1.Location = point48;
      this.Y.Name = "Y";
      Label y2 = this.Y;
      size1 = new Size(26, 13);
      Size size48 = size1;
      y2.Size = size48;
      this.Y.TabIndex = 861;
      this.Y.TextAlign = ContentAlignment.MiddleRight;
      this.X.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      Label x1 = this.X;
      point1 = new Point(30, 11);
      Point point49 = point1;
      x1.Location = point49;
      this.X.Name = "X";
      Label x2 = this.X;
      size1 = new Size(26, 13);
      Size size49 = size1;
      x2.Size = size49;
      this.X.TabIndex = 254;
      this.X.TextAlign = ContentAlignment.MiddleRight;
      this.Label19.BorderStyle = BorderStyle.Fixed3D;
      Label label19_1 = this.Label19;
      point1 = new Point(688, 25);
      Point point50 = point1;
      label19_1.Location = point50;
      this.Label19.Name = "Label19";
      Label label19_2 = this.Label19;
      size1 = new Size(2, 34);
      Size size50 = size1;
      label19_2.Size = size50;
      this.Label19.TabIndex = 1381;
      this.Label19.Text = "Label19";
      this.PictureBox500.BackColor = Color.White;
      this.PictureBox500.Cursor = Cursors.Help;
      PictureBox pictureBox500_1 = this.PictureBox500;
      point1 = new Point(460, 578);
      Point point51 = point1;
      pictureBox500_1.Location = point51;
      this.PictureBox500.Name = "PictureBox500";
      PictureBox pictureBox500_2 = this.PictureBox500;
      size1 = new Size(3, 3);
      Size size51 = size1;
      pictureBox500_2.Size = size51;
      this.PictureBox500.TabIndex = 1886;
      this.PictureBox500.TabStop = false;
      this.PictureBox499.BackColor = Color.White;
      this.PictureBox499.Cursor = Cursors.Help;
      PictureBox pictureBox499_1 = this.PictureBox499;
      point1 = new Point(460, 578);
      Point point52 = point1;
      pictureBox499_1.Location = point52;
      this.PictureBox499.Name = "PictureBox499";
      PictureBox pictureBox499_2 = this.PictureBox499;
      size1 = new Size(3, 3);
      Size size52 = size1;
      pictureBox499_2.Size = size52;
      this.PictureBox499.TabIndex = 1885;
      this.PictureBox499.TabStop = false;
      this.PictureBox498.BackColor = Color.White;
      this.PictureBox498.Cursor = Cursors.Help;
      PictureBox pictureBox498_1 = this.PictureBox498;
      point1 = new Point(460, 578);
      Point point53 = point1;
      pictureBox498_1.Location = point53;
      this.PictureBox498.Name = "PictureBox498";
      PictureBox pictureBox498_2 = this.PictureBox498;
      size1 = new Size(3, 3);
      Size size53 = size1;
      pictureBox498_2.Size = size53;
      this.PictureBox498.TabIndex = 1884;
      this.PictureBox498.TabStop = false;
      this.PictureBox497.BackColor = Color.White;
      this.PictureBox497.Cursor = Cursors.Help;
      PictureBox pictureBox497_1 = this.PictureBox497;
      point1 = new Point(460, 578);
      Point point54 = point1;
      pictureBox497_1.Location = point54;
      this.PictureBox497.Name = "PictureBox497";
      PictureBox pictureBox497_2 = this.PictureBox497;
      size1 = new Size(3, 3);
      Size size54 = size1;
      pictureBox497_2.Size = size54;
      this.PictureBox497.TabIndex = 1883;
      this.PictureBox497.TabStop = false;
      this.PictureBox496.BackColor = Color.White;
      this.PictureBox496.Cursor = Cursors.Help;
      PictureBox pictureBox496_1 = this.PictureBox496;
      point1 = new Point(460, 578);
      Point point55 = point1;
      pictureBox496_1.Location = point55;
      this.PictureBox496.Name = "PictureBox496";
      PictureBox pictureBox496_2 = this.PictureBox496;
      size1 = new Size(3, 3);
      Size size55 = size1;
      pictureBox496_2.Size = size55;
      this.PictureBox496.TabIndex = 1882;
      this.PictureBox496.TabStop = false;
      this.PictureBox495.BackColor = Color.White;
      this.PictureBox495.Cursor = Cursors.Help;
      PictureBox pictureBox495_1 = this.PictureBox495;
      point1 = new Point(460, 578);
      Point point56 = point1;
      pictureBox495_1.Location = point56;
      this.PictureBox495.Name = "PictureBox495";
      PictureBox pictureBox495_2 = this.PictureBox495;
      size1 = new Size(3, 3);
      Size size56 = size1;
      pictureBox495_2.Size = size56;
      this.PictureBox495.TabIndex = 1881;
      this.PictureBox495.TabStop = false;
      this.PictureBox494.BackColor = Color.White;
      this.PictureBox494.Cursor = Cursors.Help;
      PictureBox pictureBox494_1 = this.PictureBox494;
      point1 = new Point(460, 578);
      Point point57 = point1;
      pictureBox494_1.Location = point57;
      this.PictureBox494.Name = "PictureBox494";
      PictureBox pictureBox494_2 = this.PictureBox494;
      size1 = new Size(3, 3);
      Size size57 = size1;
      pictureBox494_2.Size = size57;
      this.PictureBox494.TabIndex = 1880;
      this.PictureBox494.TabStop = false;
      this.PictureBox493.BackColor = Color.White;
      this.PictureBox493.Cursor = Cursors.Help;
      PictureBox pictureBox493_1 = this.PictureBox493;
      point1 = new Point(460, 578);
      Point point58 = point1;
      pictureBox493_1.Location = point58;
      this.PictureBox493.Name = "PictureBox493";
      PictureBox pictureBox493_2 = this.PictureBox493;
      size1 = new Size(3, 3);
      Size size58 = size1;
      pictureBox493_2.Size = size58;
      this.PictureBox493.TabIndex = 1879;
      this.PictureBox493.TabStop = false;
      this.PictureBox492.BackColor = Color.White;
      this.PictureBox492.Cursor = Cursors.Help;
      PictureBox pictureBox492_1 = this.PictureBox492;
      point1 = new Point(460, 578);
      Point point59 = point1;
      pictureBox492_1.Location = point59;
      this.PictureBox492.Name = "PictureBox492";
      PictureBox pictureBox492_2 = this.PictureBox492;
      size1 = new Size(3, 3);
      Size size59 = size1;
      pictureBox492_2.Size = size59;
      this.PictureBox492.TabIndex = 1878;
      this.PictureBox492.TabStop = false;
      this.PictureBox491.BackColor = Color.White;
      this.PictureBox491.Cursor = Cursors.Help;
      PictureBox pictureBox491_1 = this.PictureBox491;
      point1 = new Point(460, 578);
      Point point60 = point1;
      pictureBox491_1.Location = point60;
      this.PictureBox491.Name = "PictureBox491";
      PictureBox pictureBox491_2 = this.PictureBox491;
      size1 = new Size(3, 3);
      Size size60 = size1;
      pictureBox491_2.Size = size60;
      this.PictureBox491.TabIndex = 1877;
      this.PictureBox491.TabStop = false;
      this.PictureBox490.BackColor = Color.White;
      this.PictureBox490.Cursor = Cursors.Help;
      PictureBox pictureBox490_1 = this.PictureBox490;
      point1 = new Point(460, 578);
      Point point61 = point1;
      pictureBox490_1.Location = point61;
      this.PictureBox490.Name = "PictureBox490";
      PictureBox pictureBox490_2 = this.PictureBox490;
      size1 = new Size(3, 3);
      Size size61 = size1;
      pictureBox490_2.Size = size61;
      this.PictureBox490.TabIndex = 1876;
      this.PictureBox490.TabStop = false;
      this.PictureBox489.BackColor = Color.White;
      this.PictureBox489.Cursor = Cursors.Help;
      PictureBox pictureBox489_1 = this.PictureBox489;
      point1 = new Point(460, 578);
      Point point62 = point1;
      pictureBox489_1.Location = point62;
      this.PictureBox489.Name = "PictureBox489";
      PictureBox pictureBox489_2 = this.PictureBox489;
      size1 = new Size(3, 3);
      Size size62 = size1;
      pictureBox489_2.Size = size62;
      this.PictureBox489.TabIndex = 1875;
      this.PictureBox489.TabStop = false;
      this.PictureBox488.BackColor = Color.White;
      this.PictureBox488.Cursor = Cursors.Help;
      PictureBox pictureBox488_1 = this.PictureBox488;
      point1 = new Point(460, 578);
      Point point63 = point1;
      pictureBox488_1.Location = point63;
      this.PictureBox488.Name = "PictureBox488";
      PictureBox pictureBox488_2 = this.PictureBox488;
      size1 = new Size(3, 3);
      Size size63 = size1;
      pictureBox488_2.Size = size63;
      this.PictureBox488.TabIndex = 1874;
      this.PictureBox488.TabStop = false;
      this.PictureBox487.BackColor = Color.White;
      this.PictureBox487.Cursor = Cursors.Help;
      PictureBox pictureBox487_1 = this.PictureBox487;
      point1 = new Point(460, 578);
      Point point64 = point1;
      pictureBox487_1.Location = point64;
      this.PictureBox487.Name = "PictureBox487";
      PictureBox pictureBox487_2 = this.PictureBox487;
      size1 = new Size(3, 3);
      Size size64 = size1;
      pictureBox487_2.Size = size64;
      this.PictureBox487.TabIndex = 1873;
      this.PictureBox487.TabStop = false;
      this.PictureBox486.BackColor = Color.White;
      this.PictureBox486.Cursor = Cursors.Help;
      PictureBox pictureBox486_1 = this.PictureBox486;
      point1 = new Point(460, 578);
      Point point65 = point1;
      pictureBox486_1.Location = point65;
      this.PictureBox486.Name = "PictureBox486";
      PictureBox pictureBox486_2 = this.PictureBox486;
      size1 = new Size(3, 3);
      Size size65 = size1;
      pictureBox486_2.Size = size65;
      this.PictureBox486.TabIndex = 1872;
      this.PictureBox486.TabStop = false;
      this.PictureBox485.BackColor = Color.White;
      this.PictureBox485.Cursor = Cursors.Help;
      PictureBox pictureBox485_1 = this.PictureBox485;
      point1 = new Point(460, 578);
      Point point66 = point1;
      pictureBox485_1.Location = point66;
      this.PictureBox485.Name = "PictureBox485";
      PictureBox pictureBox485_2 = this.PictureBox485;
      size1 = new Size(3, 3);
      Size size66 = size1;
      pictureBox485_2.Size = size66;
      this.PictureBox485.TabIndex = 1871;
      this.PictureBox485.TabStop = false;
      this.PictureBox484.BackColor = Color.White;
      this.PictureBox484.Cursor = Cursors.Help;
      PictureBox pictureBox484_1 = this.PictureBox484;
      point1 = new Point(460, 578);
      Point point67 = point1;
      pictureBox484_1.Location = point67;
      this.PictureBox484.Name = "PictureBox484";
      PictureBox pictureBox484_2 = this.PictureBox484;
      size1 = new Size(3, 3);
      Size size67 = size1;
      pictureBox484_2.Size = size67;
      this.PictureBox484.TabIndex = 1870;
      this.PictureBox484.TabStop = false;
      this.PictureBox483.BackColor = Color.White;
      this.PictureBox483.Cursor = Cursors.Help;
      PictureBox pictureBox483_1 = this.PictureBox483;
      point1 = new Point(460, 578);
      Point point68 = point1;
      pictureBox483_1.Location = point68;
      this.PictureBox483.Name = "PictureBox483";
      PictureBox pictureBox483_2 = this.PictureBox483;
      size1 = new Size(3, 3);
      Size size68 = size1;
      pictureBox483_2.Size = size68;
      this.PictureBox483.TabIndex = 1869;
      this.PictureBox483.TabStop = false;
      this.PictureBox482.BackColor = Color.White;
      this.PictureBox482.Cursor = Cursors.Help;
      PictureBox pictureBox482_1 = this.PictureBox482;
      point1 = new Point(460, 578);
      Point point69 = point1;
      pictureBox482_1.Location = point69;
      this.PictureBox482.Name = "PictureBox482";
      PictureBox pictureBox482_2 = this.PictureBox482;
      size1 = new Size(3, 3);
      Size size69 = size1;
      pictureBox482_2.Size = size69;
      this.PictureBox482.TabIndex = 1868;
      this.PictureBox482.TabStop = false;
      this.PictureBox481.BackColor = Color.White;
      this.PictureBox481.Cursor = Cursors.Help;
      PictureBox pictureBox481_1 = this.PictureBox481;
      point1 = new Point(460, 578);
      Point point70 = point1;
      pictureBox481_1.Location = point70;
      this.PictureBox481.Name = "PictureBox481";
      PictureBox pictureBox481_2 = this.PictureBox481;
      size1 = new Size(3, 3);
      Size size70 = size1;
      pictureBox481_2.Size = size70;
      this.PictureBox481.TabIndex = 1867;
      this.PictureBox481.TabStop = false;
      this.PictureBox480.BackColor = Color.White;
      this.PictureBox480.Cursor = Cursors.Help;
      PictureBox pictureBox480_1 = this.PictureBox480;
      point1 = new Point(460, 578);
      Point point71 = point1;
      pictureBox480_1.Location = point71;
      this.PictureBox480.Name = "PictureBox480";
      PictureBox pictureBox480_2 = this.PictureBox480;
      size1 = new Size(3, 3);
      Size size71 = size1;
      pictureBox480_2.Size = size71;
      this.PictureBox480.TabIndex = 1866;
      this.PictureBox480.TabStop = false;
      this.PictureBox479.BackColor = Color.White;
      this.PictureBox479.Cursor = Cursors.Help;
      PictureBox pictureBox479_1 = this.PictureBox479;
      point1 = new Point(460, 578);
      Point point72 = point1;
      pictureBox479_1.Location = point72;
      this.PictureBox479.Name = "PictureBox479";
      PictureBox pictureBox479_2 = this.PictureBox479;
      size1 = new Size(3, 3);
      Size size72 = size1;
      pictureBox479_2.Size = size72;
      this.PictureBox479.TabIndex = 1865;
      this.PictureBox479.TabStop = false;
      this.PictureBox478.BackColor = Color.White;
      this.PictureBox478.Cursor = Cursors.Help;
      PictureBox pictureBox478_1 = this.PictureBox478;
      point1 = new Point(460, 578);
      Point point73 = point1;
      pictureBox478_1.Location = point73;
      this.PictureBox478.Name = "PictureBox478";
      PictureBox pictureBox478_2 = this.PictureBox478;
      size1 = new Size(3, 3);
      Size size73 = size1;
      pictureBox478_2.Size = size73;
      this.PictureBox478.TabIndex = 1864;
      this.PictureBox478.TabStop = false;
      this.PictureBox477.BackColor = Color.White;
      this.PictureBox477.Cursor = Cursors.Help;
      PictureBox pictureBox477_1 = this.PictureBox477;
      point1 = new Point(460, 578);
      Point point74 = point1;
      pictureBox477_1.Location = point74;
      this.PictureBox477.Name = "PictureBox477";
      PictureBox pictureBox477_2 = this.PictureBox477;
      size1 = new Size(3, 3);
      Size size74 = size1;
      pictureBox477_2.Size = size74;
      this.PictureBox477.TabIndex = 1863;
      this.PictureBox477.TabStop = false;
      this.PictureBox476.BackColor = Color.White;
      this.PictureBox476.Cursor = Cursors.Help;
      PictureBox pictureBox476_1 = this.PictureBox476;
      point1 = new Point(460, 578);
      Point point75 = point1;
      pictureBox476_1.Location = point75;
      this.PictureBox476.Name = "PictureBox476";
      PictureBox pictureBox476_2 = this.PictureBox476;
      size1 = new Size(3, 3);
      Size size75 = size1;
      pictureBox476_2.Size = size75;
      this.PictureBox476.TabIndex = 1862;
      this.PictureBox476.TabStop = false;
      this.PictureBox475.BackColor = Color.White;
      this.PictureBox475.Cursor = Cursors.Help;
      PictureBox pictureBox475_1 = this.PictureBox475;
      point1 = new Point(460, 578);
      Point point76 = point1;
      pictureBox475_1.Location = point76;
      this.PictureBox475.Name = "PictureBox475";
      PictureBox pictureBox475_2 = this.PictureBox475;
      size1 = new Size(3, 3);
      Size size76 = size1;
      pictureBox475_2.Size = size76;
      this.PictureBox475.TabIndex = 1861;
      this.PictureBox475.TabStop = false;
      this.PictureBox474.BackColor = Color.White;
      this.PictureBox474.Cursor = Cursors.Help;
      PictureBox pictureBox474_1 = this.PictureBox474;
      point1 = new Point(460, 578);
      Point point77 = point1;
      pictureBox474_1.Location = point77;
      this.PictureBox474.Name = "PictureBox474";
      PictureBox pictureBox474_2 = this.PictureBox474;
      size1 = new Size(3, 3);
      Size size77 = size1;
      pictureBox474_2.Size = size77;
      this.PictureBox474.TabIndex = 1860;
      this.PictureBox474.TabStop = false;
      this.PictureBox473.BackColor = Color.White;
      this.PictureBox473.Cursor = Cursors.Help;
      PictureBox pictureBox473_1 = this.PictureBox473;
      point1 = new Point(460, 578);
      Point point78 = point1;
      pictureBox473_1.Location = point78;
      this.PictureBox473.Name = "PictureBox473";
      PictureBox pictureBox473_2 = this.PictureBox473;
      size1 = new Size(3, 3);
      Size size78 = size1;
      pictureBox473_2.Size = size78;
      this.PictureBox473.TabIndex = 1859;
      this.PictureBox473.TabStop = false;
      this.PictureBox472.BackColor = Color.White;
      this.PictureBox472.Cursor = Cursors.Help;
      PictureBox pictureBox472_1 = this.PictureBox472;
      point1 = new Point(460, 578);
      Point point79 = point1;
      pictureBox472_1.Location = point79;
      this.PictureBox472.Name = "PictureBox472";
      PictureBox pictureBox472_2 = this.PictureBox472;
      size1 = new Size(3, 3);
      Size size79 = size1;
      pictureBox472_2.Size = size79;
      this.PictureBox472.TabIndex = 1858;
      this.PictureBox472.TabStop = false;
      this.PictureBox471.BackColor = Color.White;
      this.PictureBox471.Cursor = Cursors.Help;
      PictureBox pictureBox471_1 = this.PictureBox471;
      point1 = new Point(460, 578);
      Point point80 = point1;
      pictureBox471_1.Location = point80;
      this.PictureBox471.Name = "PictureBox471";
      PictureBox pictureBox471_2 = this.PictureBox471;
      size1 = new Size(3, 3);
      Size size80 = size1;
      pictureBox471_2.Size = size80;
      this.PictureBox471.TabIndex = 1857;
      this.PictureBox471.TabStop = false;
      this.PictureBox470.BackColor = Color.White;
      this.PictureBox470.Cursor = Cursors.Help;
      PictureBox pictureBox470_1 = this.PictureBox470;
      point1 = new Point(460, 578);
      Point point81 = point1;
      pictureBox470_1.Location = point81;
      this.PictureBox470.Name = "PictureBox470";
      PictureBox pictureBox470_2 = this.PictureBox470;
      size1 = new Size(3, 3);
      Size size81 = size1;
      pictureBox470_2.Size = size81;
      this.PictureBox470.TabIndex = 1856;
      this.PictureBox470.TabStop = false;
      this.PictureBox469.BackColor = Color.White;
      this.PictureBox469.Cursor = Cursors.Help;
      PictureBox pictureBox469_1 = this.PictureBox469;
      point1 = new Point(460, 578);
      Point point82 = point1;
      pictureBox469_1.Location = point82;
      this.PictureBox469.Name = "PictureBox469";
      PictureBox pictureBox469_2 = this.PictureBox469;
      size1 = new Size(3, 3);
      Size size82 = size1;
      pictureBox469_2.Size = size82;
      this.PictureBox469.TabIndex = 1855;
      this.PictureBox469.TabStop = false;
      this.PictureBox468.BackColor = Color.White;
      this.PictureBox468.Cursor = Cursors.Help;
      PictureBox pictureBox468_1 = this.PictureBox468;
      point1 = new Point(460, 578);
      Point point83 = point1;
      pictureBox468_1.Location = point83;
      this.PictureBox468.Name = "PictureBox468";
      PictureBox pictureBox468_2 = this.PictureBox468;
      size1 = new Size(3, 3);
      Size size83 = size1;
      pictureBox468_2.Size = size83;
      this.PictureBox468.TabIndex = 1854;
      this.PictureBox468.TabStop = false;
      this.PictureBox467.BackColor = Color.White;
      this.PictureBox467.Cursor = Cursors.Help;
      PictureBox pictureBox467_1 = this.PictureBox467;
      point1 = new Point(460, 578);
      Point point84 = point1;
      pictureBox467_1.Location = point84;
      this.PictureBox467.Name = "PictureBox467";
      PictureBox pictureBox467_2 = this.PictureBox467;
      size1 = new Size(3, 3);
      Size size84 = size1;
      pictureBox467_2.Size = size84;
      this.PictureBox467.TabIndex = 1853;
      this.PictureBox467.TabStop = false;
      this.PictureBox466.BackColor = Color.White;
      this.PictureBox466.Cursor = Cursors.Help;
      PictureBox pictureBox466_1 = this.PictureBox466;
      point1 = new Point(460, 578);
      Point point85 = point1;
      pictureBox466_1.Location = point85;
      this.PictureBox466.Name = "PictureBox466";
      PictureBox pictureBox466_2 = this.PictureBox466;
      size1 = new Size(3, 3);
      Size size85 = size1;
      pictureBox466_2.Size = size85;
      this.PictureBox466.TabIndex = 1852;
      this.PictureBox466.TabStop = false;
      this.PictureBox465.BackColor = Color.White;
      this.PictureBox465.Cursor = Cursors.Help;
      PictureBox pictureBox465_1 = this.PictureBox465;
      point1 = new Point(460, 578);
      Point point86 = point1;
      pictureBox465_1.Location = point86;
      this.PictureBox465.Name = "PictureBox465";
      PictureBox pictureBox465_2 = this.PictureBox465;
      size1 = new Size(3, 3);
      Size size86 = size1;
      pictureBox465_2.Size = size86;
      this.PictureBox465.TabIndex = 1851;
      this.PictureBox465.TabStop = false;
      this.PictureBox464.BackColor = Color.White;
      this.PictureBox464.Cursor = Cursors.Help;
      PictureBox pictureBox464_1 = this.PictureBox464;
      point1 = new Point(460, 578);
      Point point87 = point1;
      pictureBox464_1.Location = point87;
      this.PictureBox464.Name = "PictureBox464";
      PictureBox pictureBox464_2 = this.PictureBox464;
      size1 = new Size(3, 3);
      Size size87 = size1;
      pictureBox464_2.Size = size87;
      this.PictureBox464.TabIndex = 1850;
      this.PictureBox464.TabStop = false;
      this.PictureBox463.BackColor = Color.White;
      this.PictureBox463.Cursor = Cursors.Help;
      PictureBox pictureBox463_1 = this.PictureBox463;
      point1 = new Point(460, 578);
      Point point88 = point1;
      pictureBox463_1.Location = point88;
      this.PictureBox463.Name = "PictureBox463";
      PictureBox pictureBox463_2 = this.PictureBox463;
      size1 = new Size(3, 3);
      Size size88 = size1;
      pictureBox463_2.Size = size88;
      this.PictureBox463.TabIndex = 1849;
      this.PictureBox463.TabStop = false;
      this.PictureBox462.BackColor = Color.White;
      this.PictureBox462.Cursor = Cursors.Help;
      PictureBox pictureBox462_1 = this.PictureBox462;
      point1 = new Point(460, 578);
      Point point89 = point1;
      pictureBox462_1.Location = point89;
      this.PictureBox462.Name = "PictureBox462";
      PictureBox pictureBox462_2 = this.PictureBox462;
      size1 = new Size(3, 3);
      Size size89 = size1;
      pictureBox462_2.Size = size89;
      this.PictureBox462.TabIndex = 1848;
      this.PictureBox462.TabStop = false;
      this.PictureBox461.BackColor = Color.White;
      this.PictureBox461.Cursor = Cursors.Help;
      PictureBox pictureBox461_1 = this.PictureBox461;
      point1 = new Point(460, 578);
      Point point90 = point1;
      pictureBox461_1.Location = point90;
      this.PictureBox461.Name = "PictureBox461";
      PictureBox pictureBox461_2 = this.PictureBox461;
      size1 = new Size(3, 3);
      Size size90 = size1;
      pictureBox461_2.Size = size90;
      this.PictureBox461.TabIndex = 1847;
      this.PictureBox461.TabStop = false;
      this.PictureBox460.BackColor = Color.White;
      this.PictureBox460.Cursor = Cursors.Help;
      PictureBox pictureBox460_1 = this.PictureBox460;
      point1 = new Point(460, 578);
      Point point91 = point1;
      pictureBox460_1.Location = point91;
      this.PictureBox460.Name = "PictureBox460";
      PictureBox pictureBox460_2 = this.PictureBox460;
      size1 = new Size(3, 3);
      Size size91 = size1;
      pictureBox460_2.Size = size91;
      this.PictureBox460.TabIndex = 1846;
      this.PictureBox460.TabStop = false;
      this.PictureBox459.BackColor = Color.White;
      this.PictureBox459.Cursor = Cursors.Help;
      PictureBox pictureBox459_1 = this.PictureBox459;
      point1 = new Point(460, 578);
      Point point92 = point1;
      pictureBox459_1.Location = point92;
      this.PictureBox459.Name = "PictureBox459";
      PictureBox pictureBox459_2 = this.PictureBox459;
      size1 = new Size(3, 3);
      Size size92 = size1;
      pictureBox459_2.Size = size92;
      this.PictureBox459.TabIndex = 1845;
      this.PictureBox459.TabStop = false;
      this.PictureBox458.BackColor = Color.White;
      this.PictureBox458.Cursor = Cursors.Help;
      PictureBox pictureBox458_1 = this.PictureBox458;
      point1 = new Point(460, 578);
      Point point93 = point1;
      pictureBox458_1.Location = point93;
      this.PictureBox458.Name = "PictureBox458";
      PictureBox pictureBox458_2 = this.PictureBox458;
      size1 = new Size(3, 3);
      Size size93 = size1;
      pictureBox458_2.Size = size93;
      this.PictureBox458.TabIndex = 1844;
      this.PictureBox458.TabStop = false;
      this.PictureBox457.BackColor = Color.White;
      this.PictureBox457.Cursor = Cursors.Help;
      PictureBox pictureBox457_1 = this.PictureBox457;
      point1 = new Point(460, 578);
      Point point94 = point1;
      pictureBox457_1.Location = point94;
      this.PictureBox457.Name = "PictureBox457";
      PictureBox pictureBox457_2 = this.PictureBox457;
      size1 = new Size(3, 3);
      Size size94 = size1;
      pictureBox457_2.Size = size94;
      this.PictureBox457.TabIndex = 1843;
      this.PictureBox457.TabStop = false;
      this.PictureBox456.BackColor = Color.White;
      this.PictureBox456.Cursor = Cursors.Help;
      PictureBox pictureBox456_1 = this.PictureBox456;
      point1 = new Point(460, 578);
      Point point95 = point1;
      pictureBox456_1.Location = point95;
      this.PictureBox456.Name = "PictureBox456";
      PictureBox pictureBox456_2 = this.PictureBox456;
      size1 = new Size(3, 3);
      Size size95 = size1;
      pictureBox456_2.Size = size95;
      this.PictureBox456.TabIndex = 1842;
      this.PictureBox456.TabStop = false;
      this.PictureBox455.BackColor = Color.White;
      this.PictureBox455.Cursor = Cursors.Help;
      PictureBox pictureBox455_1 = this.PictureBox455;
      point1 = new Point(460, 578);
      Point point96 = point1;
      pictureBox455_1.Location = point96;
      this.PictureBox455.Name = "PictureBox455";
      PictureBox pictureBox455_2 = this.PictureBox455;
      size1 = new Size(3, 3);
      Size size96 = size1;
      pictureBox455_2.Size = size96;
      this.PictureBox455.TabIndex = 1841;
      this.PictureBox455.TabStop = false;
      this.PictureBox454.BackColor = Color.White;
      this.PictureBox454.Cursor = Cursors.Help;
      PictureBox pictureBox454_1 = this.PictureBox454;
      point1 = new Point(460, 578);
      Point point97 = point1;
      pictureBox454_1.Location = point97;
      this.PictureBox454.Name = "PictureBox454";
      PictureBox pictureBox454_2 = this.PictureBox454;
      size1 = new Size(3, 3);
      Size size97 = size1;
      pictureBox454_2.Size = size97;
      this.PictureBox454.TabIndex = 1840;
      this.PictureBox454.TabStop = false;
      this.PictureBox453.BackColor = Color.White;
      this.PictureBox453.Cursor = Cursors.Help;
      PictureBox pictureBox453_1 = this.PictureBox453;
      point1 = new Point(460, 578);
      Point point98 = point1;
      pictureBox453_1.Location = point98;
      this.PictureBox453.Name = "PictureBox453";
      PictureBox pictureBox453_2 = this.PictureBox453;
      size1 = new Size(3, 3);
      Size size98 = size1;
      pictureBox453_2.Size = size98;
      this.PictureBox453.TabIndex = 1839;
      this.PictureBox453.TabStop = false;
      this.PictureBox452.BackColor = Color.White;
      this.PictureBox452.Cursor = Cursors.Help;
      PictureBox pictureBox452_1 = this.PictureBox452;
      point1 = new Point(460, 578);
      Point point99 = point1;
      pictureBox452_1.Location = point99;
      this.PictureBox452.Name = "PictureBox452";
      PictureBox pictureBox452_2 = this.PictureBox452;
      size1 = new Size(3, 3);
      Size size99 = size1;
      pictureBox452_2.Size = size99;
      this.PictureBox452.TabIndex = 1838;
      this.PictureBox452.TabStop = false;
      this.PictureBox451.BackColor = Color.White;
      this.PictureBox451.Cursor = Cursors.Help;
      PictureBox pictureBox451_1 = this.PictureBox451;
      point1 = new Point(460, 578);
      Point point100 = point1;
      pictureBox451_1.Location = point100;
      this.PictureBox451.Name = "PictureBox451";
      PictureBox pictureBox451_2 = this.PictureBox451;
      size1 = new Size(3, 3);
      Size size100 = size1;
      pictureBox451_2.Size = size100;
      this.PictureBox451.TabIndex = 1837;
      this.PictureBox451.TabStop = false;
      this.PictureBox450.BackColor = Color.White;
      this.PictureBox450.Cursor = Cursors.Help;
      PictureBox pictureBox450_1 = this.PictureBox450;
      point1 = new Point(460, 578);
      Point point101 = point1;
      pictureBox450_1.Location = point101;
      this.PictureBox450.Name = "PictureBox450";
      PictureBox pictureBox450_2 = this.PictureBox450;
      size1 = new Size(3, 3);
      Size size101 = size1;
      pictureBox450_2.Size = size101;
      this.PictureBox450.TabIndex = 1834;
      this.PictureBox450.TabStop = false;
      this.PictureBox449.BackColor = Color.White;
      this.PictureBox449.Cursor = Cursors.Help;
      PictureBox pictureBox449_1 = this.PictureBox449;
      point1 = new Point(460, 578);
      Point point102 = point1;
      pictureBox449_1.Location = point102;
      this.PictureBox449.Name = "PictureBox449";
      PictureBox pictureBox449_2 = this.PictureBox449;
      size1 = new Size(3, 3);
      Size size102 = size1;
      pictureBox449_2.Size = size102;
      this.PictureBox449.TabIndex = 1833;
      this.PictureBox449.TabStop = false;
      this.PictureBox225.BackColor = Color.White;
      this.PictureBox225.Cursor = Cursors.Help;
      PictureBox pictureBox225_1 = this.PictureBox225;
      point1 = new Point(460, 578);
      Point point103 = point1;
      pictureBox225_1.Location = point103;
      this.PictureBox225.Name = "PictureBox225";
      PictureBox pictureBox225_2 = this.PictureBox225;
      size1 = new Size(3, 3);
      Size size103 = size1;
      pictureBox225_2.Size = size103;
      this.PictureBox225.TabIndex = 1832;
      this.PictureBox225.TabStop = false;
      this.PictureBox226.BackColor = Color.White;
      this.PictureBox226.Cursor = Cursors.Help;
      PictureBox pictureBox226_1 = this.PictureBox226;
      point1 = new Point(460, 578);
      Point point104 = point1;
      pictureBox226_1.Location = point104;
      this.PictureBox226.Name = "PictureBox226";
      PictureBox pictureBox226_2 = this.PictureBox226;
      size1 = new Size(3, 3);
      Size size104 = size1;
      pictureBox226_2.Size = size104;
      this.PictureBox226.TabIndex = 1831;
      this.PictureBox226.TabStop = false;
      this.PictureBox227.BackColor = Color.White;
      this.PictureBox227.Cursor = Cursors.Help;
      PictureBox pictureBox227_1 = this.PictureBox227;
      point1 = new Point(460, 578);
      Point point105 = point1;
      pictureBox227_1.Location = point105;
      this.PictureBox227.Name = "PictureBox227";
      PictureBox pictureBox227_2 = this.PictureBox227;
      size1 = new Size(3, 3);
      Size size105 = size1;
      pictureBox227_2.Size = size105;
      this.PictureBox227.TabIndex = 1830;
      this.PictureBox227.TabStop = false;
      this.PictureBox228.BackColor = Color.White;
      this.PictureBox228.Cursor = Cursors.Help;
      PictureBox pictureBox228_1 = this.PictureBox228;
      point1 = new Point(460, 578);
      Point point106 = point1;
      pictureBox228_1.Location = point106;
      this.PictureBox228.Name = "PictureBox228";
      PictureBox pictureBox228_2 = this.PictureBox228;
      size1 = new Size(3, 3);
      Size size106 = size1;
      pictureBox228_2.Size = size106;
      this.PictureBox228.TabIndex = 1829;
      this.PictureBox228.TabStop = false;
      this.PictureBox229.BackColor = Color.White;
      this.PictureBox229.Cursor = Cursors.Help;
      PictureBox pictureBox229_1 = this.PictureBox229;
      point1 = new Point(460, 578);
      Point point107 = point1;
      pictureBox229_1.Location = point107;
      this.PictureBox229.Name = "PictureBox229";
      PictureBox pictureBox229_2 = this.PictureBox229;
      size1 = new Size(3, 3);
      Size size107 = size1;
      pictureBox229_2.Size = size107;
      this.PictureBox229.TabIndex = 1828;
      this.PictureBox229.TabStop = false;
      this.PictureBox230.BackColor = Color.White;
      this.PictureBox230.Cursor = Cursors.Help;
      PictureBox pictureBox230_1 = this.PictureBox230;
      point1 = new Point(460, 578);
      Point point108 = point1;
      pictureBox230_1.Location = point108;
      this.PictureBox230.Name = "PictureBox230";
      PictureBox pictureBox230_2 = this.PictureBox230;
      size1 = new Size(3, 3);
      Size size108 = size1;
      pictureBox230_2.Size = size108;
      this.PictureBox230.TabIndex = 1827;
      this.PictureBox230.TabStop = false;
      this.PictureBox231.BackColor = Color.White;
      this.PictureBox231.Cursor = Cursors.Help;
      PictureBox pictureBox231_1 = this.PictureBox231;
      point1 = new Point(460, 578);
      Point point109 = point1;
      pictureBox231_1.Location = point109;
      this.PictureBox231.Name = "PictureBox231";
      PictureBox pictureBox231_2 = this.PictureBox231;
      size1 = new Size(3, 3);
      Size size109 = size1;
      pictureBox231_2.Size = size109;
      this.PictureBox231.TabIndex = 1826;
      this.PictureBox231.TabStop = false;
      this.PictureBox232.BackColor = Color.White;
      this.PictureBox232.Cursor = Cursors.Help;
      PictureBox pictureBox232_1 = this.PictureBox232;
      point1 = new Point(460, 578);
      Point point110 = point1;
      pictureBox232_1.Location = point110;
      this.PictureBox232.Name = "PictureBox232";
      PictureBox pictureBox232_2 = this.PictureBox232;
      size1 = new Size(3, 3);
      Size size110 = size1;
      pictureBox232_2.Size = size110;
      this.PictureBox232.TabIndex = 1825;
      this.PictureBox232.TabStop = false;
      this.PictureBox233.BackColor = Color.White;
      this.PictureBox233.Cursor = Cursors.Help;
      PictureBox pictureBox233_1 = this.PictureBox233;
      point1 = new Point(460, 578);
      Point point111 = point1;
      pictureBox233_1.Location = point111;
      this.PictureBox233.Name = "PictureBox233";
      PictureBox pictureBox233_2 = this.PictureBox233;
      size1 = new Size(3, 3);
      Size size111 = size1;
      pictureBox233_2.Size = size111;
      this.PictureBox233.TabIndex = 1824;
      this.PictureBox233.TabStop = false;
      this.PictureBox234.BackColor = Color.White;
      this.PictureBox234.Cursor = Cursors.Help;
      PictureBox pictureBox234_1 = this.PictureBox234;
      point1 = new Point(460, 578);
      Point point112 = point1;
      pictureBox234_1.Location = point112;
      this.PictureBox234.Name = "PictureBox234";
      PictureBox pictureBox234_2 = this.PictureBox234;
      size1 = new Size(3, 3);
      Size size112 = size1;
      pictureBox234_2.Size = size112;
      this.PictureBox234.TabIndex = 1823;
      this.PictureBox234.TabStop = false;
      this.PictureBox235.BackColor = Color.White;
      this.PictureBox235.Cursor = Cursors.Help;
      PictureBox pictureBox235_1 = this.PictureBox235;
      point1 = new Point(460, 578);
      Point point113 = point1;
      pictureBox235_1.Location = point113;
      this.PictureBox235.Name = "PictureBox235";
      PictureBox pictureBox235_2 = this.PictureBox235;
      size1 = new Size(3, 3);
      Size size113 = size1;
      pictureBox235_2.Size = size113;
      this.PictureBox235.TabIndex = 1822;
      this.PictureBox235.TabStop = false;
      this.PictureBox236.BackColor = Color.White;
      this.PictureBox236.Cursor = Cursors.Help;
      PictureBox pictureBox236_1 = this.PictureBox236;
      point1 = new Point(460, 578);
      Point point114 = point1;
      pictureBox236_1.Location = point114;
      this.PictureBox236.Name = "PictureBox236";
      PictureBox pictureBox236_2 = this.PictureBox236;
      size1 = new Size(3, 3);
      Size size114 = size1;
      pictureBox236_2.Size = size114;
      this.PictureBox236.TabIndex = 1821;
      this.PictureBox236.TabStop = false;
      this.PictureBox237.BackColor = Color.White;
      this.PictureBox237.Cursor = Cursors.Help;
      PictureBox pictureBox237_1 = this.PictureBox237;
      point1 = new Point(460, 578);
      Point point115 = point1;
      pictureBox237_1.Location = point115;
      this.PictureBox237.Name = "PictureBox237";
      PictureBox pictureBox237_2 = this.PictureBox237;
      size1 = new Size(3, 3);
      Size size115 = size1;
      pictureBox237_2.Size = size115;
      this.PictureBox237.TabIndex = 1820;
      this.PictureBox237.TabStop = false;
      this.PictureBox238.BackColor = Color.White;
      this.PictureBox238.Cursor = Cursors.Help;
      PictureBox pictureBox238_1 = this.PictureBox238;
      point1 = new Point(460, 578);
      Point point116 = point1;
      pictureBox238_1.Location = point116;
      this.PictureBox238.Name = "PictureBox238";
      PictureBox pictureBox238_2 = this.PictureBox238;
      size1 = new Size(3, 3);
      Size size116 = size1;
      pictureBox238_2.Size = size116;
      this.PictureBox238.TabIndex = 1819;
      this.PictureBox238.TabStop = false;
      this.PictureBox239.BackColor = Color.White;
      this.PictureBox239.Cursor = Cursors.Help;
      PictureBox pictureBox239_1 = this.PictureBox239;
      point1 = new Point(460, 578);
      Point point117 = point1;
      pictureBox239_1.Location = point117;
      this.PictureBox239.Name = "PictureBox239";
      PictureBox pictureBox239_2 = this.PictureBox239;
      size1 = new Size(3, 3);
      Size size117 = size1;
      pictureBox239_2.Size = size117;
      this.PictureBox239.TabIndex = 1818;
      this.PictureBox239.TabStop = false;
      this.PictureBox240.BackColor = Color.White;
      this.PictureBox240.Cursor = Cursors.Help;
      PictureBox pictureBox240_1 = this.PictureBox240;
      point1 = new Point(460, 578);
      Point point118 = point1;
      pictureBox240_1.Location = point118;
      this.PictureBox240.Name = "PictureBox240";
      PictureBox pictureBox240_2 = this.PictureBox240;
      size1 = new Size(3, 3);
      Size size118 = size1;
      pictureBox240_2.Size = size118;
      this.PictureBox240.TabIndex = 1817;
      this.PictureBox240.TabStop = false;
      this.PictureBox241.BackColor = Color.White;
      this.PictureBox241.Cursor = Cursors.Help;
      PictureBox pictureBox241_1 = this.PictureBox241;
      point1 = new Point(460, 578);
      Point point119 = point1;
      pictureBox241_1.Location = point119;
      this.PictureBox241.Name = "PictureBox241";
      PictureBox pictureBox241_2 = this.PictureBox241;
      size1 = new Size(3, 3);
      Size size119 = size1;
      pictureBox241_2.Size = size119;
      this.PictureBox241.TabIndex = 1816;
      this.PictureBox241.TabStop = false;
      this.PictureBox242.BackColor = Color.White;
      this.PictureBox242.Cursor = Cursors.Help;
      PictureBox pictureBox242_1 = this.PictureBox242;
      point1 = new Point(460, 578);
      Point point120 = point1;
      pictureBox242_1.Location = point120;
      this.PictureBox242.Name = "PictureBox242";
      PictureBox pictureBox242_2 = this.PictureBox242;
      size1 = new Size(3, 3);
      Size size120 = size1;
      pictureBox242_2.Size = size120;
      this.PictureBox242.TabIndex = 1815;
      this.PictureBox242.TabStop = false;
      this.PictureBox243.BackColor = Color.White;
      this.PictureBox243.Cursor = Cursors.Help;
      PictureBox pictureBox243_1 = this.PictureBox243;
      point1 = new Point(460, 578);
      Point point121 = point1;
      pictureBox243_1.Location = point121;
      this.PictureBox243.Name = "PictureBox243";
      PictureBox pictureBox243_2 = this.PictureBox243;
      size1 = new Size(3, 3);
      Size size121 = size1;
      pictureBox243_2.Size = size121;
      this.PictureBox243.TabIndex = 1814;
      this.PictureBox243.TabStop = false;
      this.PictureBox244.BackColor = Color.White;
      this.PictureBox244.Cursor = Cursors.Help;
      PictureBox pictureBox244_1 = this.PictureBox244;
      point1 = new Point(460, 578);
      Point point122 = point1;
      pictureBox244_1.Location = point122;
      this.PictureBox244.Name = "PictureBox244";
      PictureBox pictureBox244_2 = this.PictureBox244;
      size1 = new Size(3, 3);
      Size size122 = size1;
      pictureBox244_2.Size = size122;
      this.PictureBox244.TabIndex = 1813;
      this.PictureBox244.TabStop = false;
      this.PictureBox245.BackColor = Color.White;
      this.PictureBox245.Cursor = Cursors.Help;
      PictureBox pictureBox245_1 = this.PictureBox245;
      point1 = new Point(460, 578);
      Point point123 = point1;
      pictureBox245_1.Location = point123;
      this.PictureBox245.Name = "PictureBox245";
      PictureBox pictureBox245_2 = this.PictureBox245;
      size1 = new Size(3, 3);
      Size size123 = size1;
      pictureBox245_2.Size = size123;
      this.PictureBox245.TabIndex = 1812;
      this.PictureBox245.TabStop = false;
      this.PictureBox246.BackColor = Color.White;
      this.PictureBox246.Cursor = Cursors.Help;
      PictureBox pictureBox246_1 = this.PictureBox246;
      point1 = new Point(460, 578);
      Point point124 = point1;
      pictureBox246_1.Location = point124;
      this.PictureBox246.Name = "PictureBox246";
      PictureBox pictureBox246_2 = this.PictureBox246;
      size1 = new Size(3, 3);
      Size size124 = size1;
      pictureBox246_2.Size = size124;
      this.PictureBox246.TabIndex = 1811;
      this.PictureBox246.TabStop = false;
      this.PictureBox247.BackColor = Color.White;
      this.PictureBox247.Cursor = Cursors.Help;
      PictureBox pictureBox247_1 = this.PictureBox247;
      point1 = new Point(460, 578);
      Point point125 = point1;
      pictureBox247_1.Location = point125;
      this.PictureBox247.Name = "PictureBox247";
      PictureBox pictureBox247_2 = this.PictureBox247;
      size1 = new Size(3, 3);
      Size size125 = size1;
      pictureBox247_2.Size = size125;
      this.PictureBox247.TabIndex = 1810;
      this.PictureBox247.TabStop = false;
      this.PictureBox248.BackColor = Color.White;
      this.PictureBox248.Cursor = Cursors.Help;
      PictureBox pictureBox248_1 = this.PictureBox248;
      point1 = new Point(460, 578);
      Point point126 = point1;
      pictureBox248_1.Location = point126;
      this.PictureBox248.Name = "PictureBox248";
      PictureBox pictureBox248_2 = this.PictureBox248;
      size1 = new Size(3, 3);
      Size size126 = size1;
      pictureBox248_2.Size = size126;
      this.PictureBox248.TabIndex = 1809;
      this.PictureBox248.TabStop = false;
      this.PictureBox249.BackColor = Color.White;
      this.PictureBox249.Cursor = Cursors.Help;
      PictureBox pictureBox249_1 = this.PictureBox249;
      point1 = new Point(460, 578);
      Point point127 = point1;
      pictureBox249_1.Location = point127;
      this.PictureBox249.Name = "PictureBox249";
      PictureBox pictureBox249_2 = this.PictureBox249;
      size1 = new Size(3, 3);
      Size size127 = size1;
      pictureBox249_2.Size = size127;
      this.PictureBox249.TabIndex = 1808;
      this.PictureBox249.TabStop = false;
      this.PictureBox250.BackColor = Color.White;
      this.PictureBox250.Cursor = Cursors.Help;
      PictureBox pictureBox250_1 = this.PictureBox250;
      point1 = new Point(460, 578);
      Point point128 = point1;
      pictureBox250_1.Location = point128;
      this.PictureBox250.Name = "PictureBox250";
      PictureBox pictureBox250_2 = this.PictureBox250;
      size1 = new Size(3, 3);
      Size size128 = size1;
      pictureBox250_2.Size = size128;
      this.PictureBox250.TabIndex = 1807;
      this.PictureBox250.TabStop = false;
      this.PictureBox251.BackColor = Color.White;
      this.PictureBox251.Cursor = Cursors.Help;
      PictureBox pictureBox251_1 = this.PictureBox251;
      point1 = new Point(460, 578);
      Point point129 = point1;
      pictureBox251_1.Location = point129;
      this.PictureBox251.Name = "PictureBox251";
      PictureBox pictureBox251_2 = this.PictureBox251;
      size1 = new Size(3, 3);
      Size size129 = size1;
      pictureBox251_2.Size = size129;
      this.PictureBox251.TabIndex = 1806;
      this.PictureBox251.TabStop = false;
      this.PictureBox252.BackColor = Color.White;
      this.PictureBox252.Cursor = Cursors.Help;
      PictureBox pictureBox252_1 = this.PictureBox252;
      point1 = new Point(460, 578);
      Point point130 = point1;
      pictureBox252_1.Location = point130;
      this.PictureBox252.Name = "PictureBox252";
      PictureBox pictureBox252_2 = this.PictureBox252;
      size1 = new Size(3, 3);
      Size size130 = size1;
      pictureBox252_2.Size = size130;
      this.PictureBox252.TabIndex = 1805;
      this.PictureBox252.TabStop = false;
      this.PictureBox253.BackColor = Color.White;
      this.PictureBox253.Cursor = Cursors.Help;
      PictureBox pictureBox253_1 = this.PictureBox253;
      point1 = new Point(460, 578);
      Point point131 = point1;
      pictureBox253_1.Location = point131;
      this.PictureBox253.Name = "PictureBox253";
      PictureBox pictureBox253_2 = this.PictureBox253;
      size1 = new Size(3, 3);
      Size size131 = size1;
      pictureBox253_2.Size = size131;
      this.PictureBox253.TabIndex = 1804;
      this.PictureBox253.TabStop = false;
      this.PictureBox254.BackColor = Color.White;
      this.PictureBox254.Cursor = Cursors.Help;
      PictureBox pictureBox254_1 = this.PictureBox254;
      point1 = new Point(460, 578);
      Point point132 = point1;
      pictureBox254_1.Location = point132;
      this.PictureBox254.Name = "PictureBox254";
      PictureBox pictureBox254_2 = this.PictureBox254;
      size1 = new Size(3, 3);
      Size size132 = size1;
      pictureBox254_2.Size = size132;
      this.PictureBox254.TabIndex = 1803;
      this.PictureBox254.TabStop = false;
      this.PictureBox255.BackColor = Color.White;
      this.PictureBox255.Cursor = Cursors.Help;
      PictureBox pictureBox255_1 = this.PictureBox255;
      point1 = new Point(460, 578);
      Point point133 = point1;
      pictureBox255_1.Location = point133;
      this.PictureBox255.Name = "PictureBox255";
      PictureBox pictureBox255_2 = this.PictureBox255;
      size1 = new Size(3, 3);
      Size size133 = size1;
      pictureBox255_2.Size = size133;
      this.PictureBox255.TabIndex = 1802;
      this.PictureBox255.TabStop = false;
      this.PictureBox256.BackColor = Color.White;
      this.PictureBox256.Cursor = Cursors.Help;
      PictureBox pictureBox256_1 = this.PictureBox256;
      point1 = new Point(460, 578);
      Point point134 = point1;
      pictureBox256_1.Location = point134;
      this.PictureBox256.Name = "PictureBox256";
      PictureBox pictureBox256_2 = this.PictureBox256;
      size1 = new Size(3, 3);
      Size size134 = size1;
      pictureBox256_2.Size = size134;
      this.PictureBox256.TabIndex = 1801;
      this.PictureBox256.TabStop = false;
      this.PictureBox257.BackColor = Color.White;
      this.PictureBox257.Cursor = Cursors.Help;
      PictureBox pictureBox257_1 = this.PictureBox257;
      point1 = new Point(460, 578);
      Point point135 = point1;
      pictureBox257_1.Location = point135;
      this.PictureBox257.Name = "PictureBox257";
      PictureBox pictureBox257_2 = this.PictureBox257;
      size1 = new Size(3, 3);
      Size size135 = size1;
      pictureBox257_2.Size = size135;
      this.PictureBox257.TabIndex = 1800;
      this.PictureBox257.TabStop = false;
      this.PictureBox258.BackColor = Color.White;
      this.PictureBox258.Cursor = Cursors.Help;
      PictureBox pictureBox258_1 = this.PictureBox258;
      point1 = new Point(460, 578);
      Point point136 = point1;
      pictureBox258_1.Location = point136;
      this.PictureBox258.Name = "PictureBox258";
      PictureBox pictureBox258_2 = this.PictureBox258;
      size1 = new Size(3, 3);
      Size size136 = size1;
      pictureBox258_2.Size = size136;
      this.PictureBox258.TabIndex = 1799;
      this.PictureBox258.TabStop = false;
      this.PictureBox259.BackColor = Color.White;
      this.PictureBox259.Cursor = Cursors.Help;
      PictureBox pictureBox259_1 = this.PictureBox259;
      point1 = new Point(460, 578);
      Point point137 = point1;
      pictureBox259_1.Location = point137;
      this.PictureBox259.Name = "PictureBox259";
      PictureBox pictureBox259_2 = this.PictureBox259;
      size1 = new Size(3, 3);
      Size size137 = size1;
      pictureBox259_2.Size = size137;
      this.PictureBox259.TabIndex = 1798;
      this.PictureBox259.TabStop = false;
      this.PictureBox260.BackColor = Color.White;
      this.PictureBox260.Cursor = Cursors.Help;
      PictureBox pictureBox260_1 = this.PictureBox260;
      point1 = new Point(460, 578);
      Point point138 = point1;
      pictureBox260_1.Location = point138;
      this.PictureBox260.Name = "PictureBox260";
      PictureBox pictureBox260_2 = this.PictureBox260;
      size1 = new Size(3, 3);
      Size size138 = size1;
      pictureBox260_2.Size = size138;
      this.PictureBox260.TabIndex = 1797;
      this.PictureBox260.TabStop = false;
      this.PictureBox261.BackColor = Color.White;
      this.PictureBox261.Cursor = Cursors.Help;
      PictureBox pictureBox261_1 = this.PictureBox261;
      point1 = new Point(460, 578);
      Point point139 = point1;
      pictureBox261_1.Location = point139;
      this.PictureBox261.Name = "PictureBox261";
      PictureBox pictureBox261_2 = this.PictureBox261;
      size1 = new Size(3, 3);
      Size size139 = size1;
      pictureBox261_2.Size = size139;
      this.PictureBox261.TabIndex = 1796;
      this.PictureBox261.TabStop = false;
      this.PictureBox262.BackColor = Color.White;
      this.PictureBox262.Cursor = Cursors.Help;
      PictureBox pictureBox262_1 = this.PictureBox262;
      point1 = new Point(460, 578);
      Point point140 = point1;
      pictureBox262_1.Location = point140;
      this.PictureBox262.Name = "PictureBox262";
      PictureBox pictureBox262_2 = this.PictureBox262;
      size1 = new Size(3, 3);
      Size size140 = size1;
      pictureBox262_2.Size = size140;
      this.PictureBox262.TabIndex = 1795;
      this.PictureBox262.TabStop = false;
      this.PictureBox263.BackColor = Color.White;
      this.PictureBox263.Cursor = Cursors.Help;
      PictureBox pictureBox263_1 = this.PictureBox263;
      point1 = new Point(460, 578);
      Point point141 = point1;
      pictureBox263_1.Location = point141;
      this.PictureBox263.Name = "PictureBox263";
      PictureBox pictureBox263_2 = this.PictureBox263;
      size1 = new Size(3, 3);
      Size size141 = size1;
      pictureBox263_2.Size = size141;
      this.PictureBox263.TabIndex = 1794;
      this.PictureBox263.TabStop = false;
      this.PictureBox264.BackColor = Color.White;
      this.PictureBox264.Cursor = Cursors.Help;
      PictureBox pictureBox264_1 = this.PictureBox264;
      point1 = new Point(460, 578);
      Point point142 = point1;
      pictureBox264_1.Location = point142;
      this.PictureBox264.Name = "PictureBox264";
      PictureBox pictureBox264_2 = this.PictureBox264;
      size1 = new Size(3, 3);
      Size size142 = size1;
      pictureBox264_2.Size = size142;
      this.PictureBox264.TabIndex = 1793;
      this.PictureBox264.TabStop = false;
      this.PictureBox265.BackColor = Color.White;
      this.PictureBox265.Cursor = Cursors.Help;
      PictureBox pictureBox265_1 = this.PictureBox265;
      point1 = new Point(460, 578);
      Point point143 = point1;
      pictureBox265_1.Location = point143;
      this.PictureBox265.Name = "PictureBox265";
      PictureBox pictureBox265_2 = this.PictureBox265;
      size1 = new Size(3, 3);
      Size size143 = size1;
      pictureBox265_2.Size = size143;
      this.PictureBox265.TabIndex = 1792;
      this.PictureBox265.TabStop = false;
      this.PictureBox266.BackColor = Color.White;
      this.PictureBox266.Cursor = Cursors.Help;
      PictureBox pictureBox266_1 = this.PictureBox266;
      point1 = new Point(460, 578);
      Point point144 = point1;
      pictureBox266_1.Location = point144;
      this.PictureBox266.Name = "PictureBox266";
      PictureBox pictureBox266_2 = this.PictureBox266;
      size1 = new Size(3, 3);
      Size size144 = size1;
      pictureBox266_2.Size = size144;
      this.PictureBox266.TabIndex = 1791;
      this.PictureBox266.TabStop = false;
      this.PictureBox267.BackColor = Color.White;
      this.PictureBox267.Cursor = Cursors.Help;
      PictureBox pictureBox267_1 = this.PictureBox267;
      point1 = new Point(460, 578);
      Point point145 = point1;
      pictureBox267_1.Location = point145;
      this.PictureBox267.Name = "PictureBox267";
      PictureBox pictureBox267_2 = this.PictureBox267;
      size1 = new Size(3, 3);
      Size size145 = size1;
      pictureBox267_2.Size = size145;
      this.PictureBox267.TabIndex = 1790;
      this.PictureBox267.TabStop = false;
      this.PictureBox268.BackColor = Color.White;
      this.PictureBox268.Cursor = Cursors.Help;
      PictureBox pictureBox268_1 = this.PictureBox268;
      point1 = new Point(460, 578);
      Point point146 = point1;
      pictureBox268_1.Location = point146;
      this.PictureBox268.Name = "PictureBox268";
      PictureBox pictureBox268_2 = this.PictureBox268;
      size1 = new Size(3, 3);
      Size size146 = size1;
      pictureBox268_2.Size = size146;
      this.PictureBox268.TabIndex = 1789;
      this.PictureBox268.TabStop = false;
      this.PictureBox269.BackColor = Color.White;
      this.PictureBox269.Cursor = Cursors.Help;
      PictureBox pictureBox269_1 = this.PictureBox269;
      point1 = new Point(460, 578);
      Point point147 = point1;
      pictureBox269_1.Location = point147;
      this.PictureBox269.Name = "PictureBox269";
      PictureBox pictureBox269_2 = this.PictureBox269;
      size1 = new Size(3, 3);
      Size size147 = size1;
      pictureBox269_2.Size = size147;
      this.PictureBox269.TabIndex = 1788;
      this.PictureBox269.TabStop = false;
      this.PictureBox270.BackColor = Color.White;
      this.PictureBox270.Cursor = Cursors.Help;
      PictureBox pictureBox270_1 = this.PictureBox270;
      point1 = new Point(460, 578);
      Point point148 = point1;
      pictureBox270_1.Location = point148;
      this.PictureBox270.Name = "PictureBox270";
      PictureBox pictureBox270_2 = this.PictureBox270;
      size1 = new Size(3, 3);
      Size size148 = size1;
      pictureBox270_2.Size = size148;
      this.PictureBox270.TabIndex = 1787;
      this.PictureBox270.TabStop = false;
      this.PictureBox271.BackColor = Color.White;
      this.PictureBox271.Cursor = Cursors.Help;
      PictureBox pictureBox271_1 = this.PictureBox271;
      point1 = new Point(460, 578);
      Point point149 = point1;
      pictureBox271_1.Location = point149;
      this.PictureBox271.Name = "PictureBox271";
      PictureBox pictureBox271_2 = this.PictureBox271;
      size1 = new Size(3, 3);
      Size size149 = size1;
      pictureBox271_2.Size = size149;
      this.PictureBox271.TabIndex = 1786;
      this.PictureBox271.TabStop = false;
      this.PictureBox272.BackColor = Color.White;
      this.PictureBox272.Cursor = Cursors.Help;
      PictureBox pictureBox272_1 = this.PictureBox272;
      point1 = new Point(460, 578);
      Point point150 = point1;
      pictureBox272_1.Location = point150;
      this.PictureBox272.Name = "PictureBox272";
      PictureBox pictureBox272_2 = this.PictureBox272;
      size1 = new Size(3, 3);
      Size size150 = size1;
      pictureBox272_2.Size = size150;
      this.PictureBox272.TabIndex = 1785;
      this.PictureBox272.TabStop = false;
      this.PictureBox273.BackColor = Color.White;
      this.PictureBox273.Cursor = Cursors.Help;
      PictureBox pictureBox273_1 = this.PictureBox273;
      point1 = new Point(460, 578);
      Point point151 = point1;
      pictureBox273_1.Location = point151;
      this.PictureBox273.Name = "PictureBox273";
      PictureBox pictureBox273_2 = this.PictureBox273;
      size1 = new Size(3, 3);
      Size size151 = size1;
      pictureBox273_2.Size = size151;
      this.PictureBox273.TabIndex = 1784;
      this.PictureBox273.TabStop = false;
      this.PictureBox274.BackColor = Color.White;
      this.PictureBox274.Cursor = Cursors.Help;
      PictureBox pictureBox274_1 = this.PictureBox274;
      point1 = new Point(460, 578);
      Point point152 = point1;
      pictureBox274_1.Location = point152;
      this.PictureBox274.Name = "PictureBox274";
      PictureBox pictureBox274_2 = this.PictureBox274;
      size1 = new Size(3, 3);
      Size size152 = size1;
      pictureBox274_2.Size = size152;
      this.PictureBox274.TabIndex = 1783;
      this.PictureBox274.TabStop = false;
      this.PictureBox275.BackColor = Color.White;
      this.PictureBox275.Cursor = Cursors.Help;
      PictureBox pictureBox275_1 = this.PictureBox275;
      point1 = new Point(460, 578);
      Point point153 = point1;
      pictureBox275_1.Location = point153;
      this.PictureBox275.Name = "PictureBox275";
      PictureBox pictureBox275_2 = this.PictureBox275;
      size1 = new Size(3, 3);
      Size size153 = size1;
      pictureBox275_2.Size = size153;
      this.PictureBox275.TabIndex = 1782;
      this.PictureBox275.TabStop = false;
      this.PictureBox276.BackColor = Color.White;
      this.PictureBox276.Cursor = Cursors.Help;
      PictureBox pictureBox276_1 = this.PictureBox276;
      point1 = new Point(460, 578);
      Point point154 = point1;
      pictureBox276_1.Location = point154;
      this.PictureBox276.Name = "PictureBox276";
      PictureBox pictureBox276_2 = this.PictureBox276;
      size1 = new Size(3, 3);
      Size size154 = size1;
      pictureBox276_2.Size = size154;
      this.PictureBox276.TabIndex = 1781;
      this.PictureBox276.TabStop = false;
      this.PictureBox277.BackColor = Color.White;
      this.PictureBox277.Cursor = Cursors.Help;
      PictureBox pictureBox277_1 = this.PictureBox277;
      point1 = new Point(460, 578);
      Point point155 = point1;
      pictureBox277_1.Location = point155;
      this.PictureBox277.Name = "PictureBox277";
      PictureBox pictureBox277_2 = this.PictureBox277;
      size1 = new Size(3, 3);
      Size size155 = size1;
      pictureBox277_2.Size = size155;
      this.PictureBox277.TabIndex = 1780;
      this.PictureBox277.TabStop = false;
      this.PictureBox278.BackColor = Color.White;
      this.PictureBox278.Cursor = Cursors.Help;
      PictureBox pictureBox278_1 = this.PictureBox278;
      point1 = new Point(460, 578);
      Point point156 = point1;
      pictureBox278_1.Location = point156;
      this.PictureBox278.Name = "PictureBox278";
      PictureBox pictureBox278_2 = this.PictureBox278;
      size1 = new Size(3, 3);
      Size size156 = size1;
      pictureBox278_2.Size = size156;
      this.PictureBox278.TabIndex = 1779;
      this.PictureBox278.TabStop = false;
      this.PictureBox279.BackColor = Color.White;
      this.PictureBox279.Cursor = Cursors.Help;
      PictureBox pictureBox279_1 = this.PictureBox279;
      point1 = new Point(460, 578);
      Point point157 = point1;
      pictureBox279_1.Location = point157;
      this.PictureBox279.Name = "PictureBox279";
      PictureBox pictureBox279_2 = this.PictureBox279;
      size1 = new Size(3, 3);
      Size size157 = size1;
      pictureBox279_2.Size = size157;
      this.PictureBox279.TabIndex = 1778;
      this.PictureBox279.TabStop = false;
      this.PictureBox280.BackColor = Color.White;
      this.PictureBox280.Cursor = Cursors.Help;
      PictureBox pictureBox280_1 = this.PictureBox280;
      point1 = new Point(460, 578);
      Point point158 = point1;
      pictureBox280_1.Location = point158;
      this.PictureBox280.Name = "PictureBox280";
      PictureBox pictureBox280_2 = this.PictureBox280;
      size1 = new Size(3, 3);
      Size size158 = size1;
      pictureBox280_2.Size = size158;
      this.PictureBox280.TabIndex = 1777;
      this.PictureBox280.TabStop = false;
      this.PictureBox281.BackColor = Color.White;
      this.PictureBox281.Cursor = Cursors.Help;
      PictureBox pictureBox281_1 = this.PictureBox281;
      point1 = new Point(460, 578);
      Point point159 = point1;
      pictureBox281_1.Location = point159;
      this.PictureBox281.Name = "PictureBox281";
      PictureBox pictureBox281_2 = this.PictureBox281;
      size1 = new Size(3, 3);
      Size size159 = size1;
      pictureBox281_2.Size = size159;
      this.PictureBox281.TabIndex = 1776;
      this.PictureBox281.TabStop = false;
      this.PictureBox282.BackColor = Color.White;
      this.PictureBox282.Cursor = Cursors.Help;
      PictureBox pictureBox282_1 = this.PictureBox282;
      point1 = new Point(460, 578);
      Point point160 = point1;
      pictureBox282_1.Location = point160;
      this.PictureBox282.Name = "PictureBox282";
      PictureBox pictureBox282_2 = this.PictureBox282;
      size1 = new Size(3, 3);
      Size size160 = size1;
      pictureBox282_2.Size = size160;
      this.PictureBox282.TabIndex = 1775;
      this.PictureBox282.TabStop = false;
      this.PictureBox283.BackColor = Color.White;
      this.PictureBox283.Cursor = Cursors.Help;
      PictureBox pictureBox283_1 = this.PictureBox283;
      point1 = new Point(460, 578);
      Point point161 = point1;
      pictureBox283_1.Location = point161;
      this.PictureBox283.Name = "PictureBox283";
      PictureBox pictureBox283_2 = this.PictureBox283;
      size1 = new Size(3, 3);
      Size size161 = size1;
      pictureBox283_2.Size = size161;
      this.PictureBox283.TabIndex = 1774;
      this.PictureBox283.TabStop = false;
      this.PictureBox284.BackColor = Color.White;
      this.PictureBox284.Cursor = Cursors.Help;
      PictureBox pictureBox284_1 = this.PictureBox284;
      point1 = new Point(460, 578);
      Point point162 = point1;
      pictureBox284_1.Location = point162;
      this.PictureBox284.Name = "PictureBox284";
      PictureBox pictureBox284_2 = this.PictureBox284;
      size1 = new Size(3, 3);
      Size size162 = size1;
      pictureBox284_2.Size = size162;
      this.PictureBox284.TabIndex = 1773;
      this.PictureBox284.TabStop = false;
      this.PictureBox285.BackColor = Color.White;
      this.PictureBox285.Cursor = Cursors.Help;
      PictureBox pictureBox285_1 = this.PictureBox285;
      point1 = new Point(460, 578);
      Point point163 = point1;
      pictureBox285_1.Location = point163;
      this.PictureBox285.Name = "PictureBox285";
      PictureBox pictureBox285_2 = this.PictureBox285;
      size1 = new Size(3, 3);
      Size size163 = size1;
      pictureBox285_2.Size = size163;
      this.PictureBox285.TabIndex = 1772;
      this.PictureBox285.TabStop = false;
      this.PictureBox286.BackColor = Color.White;
      this.PictureBox286.Cursor = Cursors.Help;
      PictureBox pictureBox286_1 = this.PictureBox286;
      point1 = new Point(460, 578);
      Point point164 = point1;
      pictureBox286_1.Location = point164;
      this.PictureBox286.Name = "PictureBox286";
      PictureBox pictureBox286_2 = this.PictureBox286;
      size1 = new Size(3, 3);
      Size size164 = size1;
      pictureBox286_2.Size = size164;
      this.PictureBox286.TabIndex = 1771;
      this.PictureBox286.TabStop = false;
      this.PictureBox287.BackColor = Color.White;
      this.PictureBox287.Cursor = Cursors.Help;
      PictureBox pictureBox287_1 = this.PictureBox287;
      point1 = new Point(460, 578);
      Point point165 = point1;
      pictureBox287_1.Location = point165;
      this.PictureBox287.Name = "PictureBox287";
      PictureBox pictureBox287_2 = this.PictureBox287;
      size1 = new Size(3, 3);
      Size size165 = size1;
      pictureBox287_2.Size = size165;
      this.PictureBox287.TabIndex = 1770;
      this.PictureBox287.TabStop = false;
      this.PictureBox288.BackColor = Color.White;
      this.PictureBox288.Cursor = Cursors.Help;
      PictureBox pictureBox288_1 = this.PictureBox288;
      point1 = new Point(460, 578);
      Point point166 = point1;
      pictureBox288_1.Location = point166;
      this.PictureBox288.Name = "PictureBox288";
      PictureBox pictureBox288_2 = this.PictureBox288;
      size1 = new Size(3, 3);
      Size size166 = size1;
      pictureBox288_2.Size = size166;
      this.PictureBox288.TabIndex = 1769;
      this.PictureBox288.TabStop = false;
      this.PictureBox289.BackColor = Color.White;
      this.PictureBox289.Cursor = Cursors.Help;
      PictureBox pictureBox289_1 = this.PictureBox289;
      point1 = new Point(460, 578);
      Point point167 = point1;
      pictureBox289_1.Location = point167;
      this.PictureBox289.Name = "PictureBox289";
      PictureBox pictureBox289_2 = this.PictureBox289;
      size1 = new Size(3, 3);
      Size size167 = size1;
      pictureBox289_2.Size = size167;
      this.PictureBox289.TabIndex = 1768;
      this.PictureBox289.TabStop = false;
      this.PictureBox290.BackColor = Color.White;
      this.PictureBox290.Cursor = Cursors.Help;
      PictureBox pictureBox290_1 = this.PictureBox290;
      point1 = new Point(460, 578);
      Point point168 = point1;
      pictureBox290_1.Location = point168;
      this.PictureBox290.Name = "PictureBox290";
      PictureBox pictureBox290_2 = this.PictureBox290;
      size1 = new Size(3, 3);
      Size size168 = size1;
      pictureBox290_2.Size = size168;
      this.PictureBox290.TabIndex = 1767;
      this.PictureBox290.TabStop = false;
      this.PictureBox291.BackColor = Color.White;
      this.PictureBox291.Cursor = Cursors.Help;
      PictureBox pictureBox291_1 = this.PictureBox291;
      point1 = new Point(460, 578);
      Point point169 = point1;
      pictureBox291_1.Location = point169;
      this.PictureBox291.Name = "PictureBox291";
      PictureBox pictureBox291_2 = this.PictureBox291;
      size1 = new Size(3, 3);
      Size size169 = size1;
      pictureBox291_2.Size = size169;
      this.PictureBox291.TabIndex = 1766;
      this.PictureBox291.TabStop = false;
      this.PictureBox292.BackColor = Color.White;
      this.PictureBox292.Cursor = Cursors.Help;
      PictureBox pictureBox292_1 = this.PictureBox292;
      point1 = new Point(460, 578);
      Point point170 = point1;
      pictureBox292_1.Location = point170;
      this.PictureBox292.Name = "PictureBox292";
      PictureBox pictureBox292_2 = this.PictureBox292;
      size1 = new Size(3, 3);
      Size size170 = size1;
      pictureBox292_2.Size = size170;
      this.PictureBox292.TabIndex = 1765;
      this.PictureBox292.TabStop = false;
      this.PictureBox293.BackColor = Color.White;
      this.PictureBox293.Cursor = Cursors.Help;
      PictureBox pictureBox293_1 = this.PictureBox293;
      point1 = new Point(460, 578);
      Point point171 = point1;
      pictureBox293_1.Location = point171;
      this.PictureBox293.Name = "PictureBox293";
      PictureBox pictureBox293_2 = this.PictureBox293;
      size1 = new Size(3, 3);
      Size size171 = size1;
      pictureBox293_2.Size = size171;
      this.PictureBox293.TabIndex = 1764;
      this.PictureBox293.TabStop = false;
      this.PictureBox294.BackColor = Color.White;
      this.PictureBox294.Cursor = Cursors.Help;
      PictureBox pictureBox294_1 = this.PictureBox294;
      point1 = new Point(460, 578);
      Point point172 = point1;
      pictureBox294_1.Location = point172;
      this.PictureBox294.Name = "PictureBox294";
      PictureBox pictureBox294_2 = this.PictureBox294;
      size1 = new Size(3, 3);
      Size size172 = size1;
      pictureBox294_2.Size = size172;
      this.PictureBox294.TabIndex = 1763;
      this.PictureBox294.TabStop = false;
      this.PictureBox295.BackColor = Color.White;
      this.PictureBox295.Cursor = Cursors.Help;
      PictureBox pictureBox295_1 = this.PictureBox295;
      point1 = new Point(460, 578);
      Point point173 = point1;
      pictureBox295_1.Location = point173;
      this.PictureBox295.Name = "PictureBox295";
      PictureBox pictureBox295_2 = this.PictureBox295;
      size1 = new Size(3, 3);
      Size size173 = size1;
      pictureBox295_2.Size = size173;
      this.PictureBox295.TabIndex = 1762;
      this.PictureBox295.TabStop = false;
      this.PictureBox296.BackColor = Color.White;
      this.PictureBox296.Cursor = Cursors.Help;
      PictureBox pictureBox296_1 = this.PictureBox296;
      point1 = new Point(460, 578);
      Point point174 = point1;
      pictureBox296_1.Location = point174;
      this.PictureBox296.Name = "PictureBox296";
      PictureBox pictureBox296_2 = this.PictureBox296;
      size1 = new Size(3, 3);
      Size size174 = size1;
      pictureBox296_2.Size = size174;
      this.PictureBox296.TabIndex = 1761;
      this.PictureBox296.TabStop = false;
      this.PictureBox297.BackColor = Color.White;
      this.PictureBox297.Cursor = Cursors.Help;
      PictureBox pictureBox297_1 = this.PictureBox297;
      point1 = new Point(460, 578);
      Point point175 = point1;
      pictureBox297_1.Location = point175;
      this.PictureBox297.Name = "PictureBox297";
      PictureBox pictureBox297_2 = this.PictureBox297;
      size1 = new Size(3, 3);
      Size size175 = size1;
      pictureBox297_2.Size = size175;
      this.PictureBox297.TabIndex = 1760;
      this.PictureBox297.TabStop = false;
      this.PictureBox298.BackColor = Color.White;
      this.PictureBox298.Cursor = Cursors.Help;
      PictureBox pictureBox298_1 = this.PictureBox298;
      point1 = new Point(460, 578);
      Point point176 = point1;
      pictureBox298_1.Location = point176;
      this.PictureBox298.Name = "PictureBox298";
      PictureBox pictureBox298_2 = this.PictureBox298;
      size1 = new Size(3, 3);
      Size size176 = size1;
      pictureBox298_2.Size = size176;
      this.PictureBox298.TabIndex = 1759;
      this.PictureBox298.TabStop = false;
      this.PictureBox299.BackColor = Color.White;
      this.PictureBox299.Cursor = Cursors.Help;
      PictureBox pictureBox299_1 = this.PictureBox299;
      point1 = new Point(460, 578);
      Point point177 = point1;
      pictureBox299_1.Location = point177;
      this.PictureBox299.Name = "PictureBox299";
      PictureBox pictureBox299_2 = this.PictureBox299;
      size1 = new Size(3, 3);
      Size size177 = size1;
      pictureBox299_2.Size = size177;
      this.PictureBox299.TabIndex = 1758;
      this.PictureBox299.TabStop = false;
      this.PictureBox300.BackColor = Color.White;
      this.PictureBox300.Cursor = Cursors.Help;
      PictureBox pictureBox300_1 = this.PictureBox300;
      point1 = new Point(460, 578);
      Point point178 = point1;
      pictureBox300_1.Location = point178;
      this.PictureBox300.Name = "PictureBox300";
      PictureBox pictureBox300_2 = this.PictureBox300;
      size1 = new Size(3, 3);
      Size size178 = size1;
      pictureBox300_2.Size = size178;
      this.PictureBox300.TabIndex = 1757;
      this.PictureBox300.TabStop = false;
      this.PictureBox301.BackColor = Color.White;
      this.PictureBox301.Cursor = Cursors.Help;
      PictureBox pictureBox301_1 = this.PictureBox301;
      point1 = new Point(460, 578);
      Point point179 = point1;
      pictureBox301_1.Location = point179;
      this.PictureBox301.Name = "PictureBox301";
      PictureBox pictureBox301_2 = this.PictureBox301;
      size1 = new Size(3, 3);
      Size size179 = size1;
      pictureBox301_2.Size = size179;
      this.PictureBox301.TabIndex = 1756;
      this.PictureBox301.TabStop = false;
      this.PictureBox302.BackColor = Color.White;
      this.PictureBox302.Cursor = Cursors.Help;
      PictureBox pictureBox302_1 = this.PictureBox302;
      point1 = new Point(460, 578);
      Point point180 = point1;
      pictureBox302_1.Location = point180;
      this.PictureBox302.Name = "PictureBox302";
      PictureBox pictureBox302_2 = this.PictureBox302;
      size1 = new Size(3, 3);
      Size size180 = size1;
      pictureBox302_2.Size = size180;
      this.PictureBox302.TabIndex = 1755;
      this.PictureBox302.TabStop = false;
      this.PictureBox303.BackColor = Color.White;
      this.PictureBox303.Cursor = Cursors.Help;
      PictureBox pictureBox303_1 = this.PictureBox303;
      point1 = new Point(460, 578);
      Point point181 = point1;
      pictureBox303_1.Location = point181;
      this.PictureBox303.Name = "PictureBox303";
      PictureBox pictureBox303_2 = this.PictureBox303;
      size1 = new Size(3, 3);
      Size size181 = size1;
      pictureBox303_2.Size = size181;
      this.PictureBox303.TabIndex = 1754;
      this.PictureBox303.TabStop = false;
      this.PictureBox304.BackColor = Color.White;
      this.PictureBox304.Cursor = Cursors.Help;
      PictureBox pictureBox304_1 = this.PictureBox304;
      point1 = new Point(460, 578);
      Point point182 = point1;
      pictureBox304_1.Location = point182;
      this.PictureBox304.Name = "PictureBox304";
      PictureBox pictureBox304_2 = this.PictureBox304;
      size1 = new Size(3, 3);
      Size size182 = size1;
      pictureBox304_2.Size = size182;
      this.PictureBox304.TabIndex = 1753;
      this.PictureBox304.TabStop = false;
      this.PictureBox305.BackColor = Color.White;
      this.PictureBox305.Cursor = Cursors.Help;
      PictureBox pictureBox305_1 = this.PictureBox305;
      point1 = new Point(460, 578);
      Point point183 = point1;
      pictureBox305_1.Location = point183;
      this.PictureBox305.Name = "PictureBox305";
      PictureBox pictureBox305_2 = this.PictureBox305;
      size1 = new Size(3, 3);
      Size size183 = size1;
      pictureBox305_2.Size = size183;
      this.PictureBox305.TabIndex = 1752;
      this.PictureBox305.TabStop = false;
      this.PictureBox306.BackColor = Color.White;
      this.PictureBox306.Cursor = Cursors.Help;
      PictureBox pictureBox306_1 = this.PictureBox306;
      point1 = new Point(460, 578);
      Point point184 = point1;
      pictureBox306_1.Location = point184;
      this.PictureBox306.Name = "PictureBox306";
      PictureBox pictureBox306_2 = this.PictureBox306;
      size1 = new Size(3, 3);
      Size size184 = size1;
      pictureBox306_2.Size = size184;
      this.PictureBox306.TabIndex = 1751;
      this.PictureBox306.TabStop = false;
      this.PictureBox307.BackColor = Color.White;
      this.PictureBox307.Cursor = Cursors.Help;
      PictureBox pictureBox307_1 = this.PictureBox307;
      point1 = new Point(460, 578);
      Point point185 = point1;
      pictureBox307_1.Location = point185;
      this.PictureBox307.Name = "PictureBox307";
      PictureBox pictureBox307_2 = this.PictureBox307;
      size1 = new Size(3, 3);
      Size size185 = size1;
      pictureBox307_2.Size = size185;
      this.PictureBox307.TabIndex = 1750;
      this.PictureBox307.TabStop = false;
      this.PictureBox308.BackColor = Color.White;
      this.PictureBox308.Cursor = Cursors.Help;
      PictureBox pictureBox308_1 = this.PictureBox308;
      point1 = new Point(460, 578);
      Point point186 = point1;
      pictureBox308_1.Location = point186;
      this.PictureBox308.Name = "PictureBox308";
      PictureBox pictureBox308_2 = this.PictureBox308;
      size1 = new Size(3, 3);
      Size size186 = size1;
      pictureBox308_2.Size = size186;
      this.PictureBox308.TabIndex = 1749;
      this.PictureBox308.TabStop = false;
      this.PictureBox309.BackColor = Color.White;
      this.PictureBox309.Cursor = Cursors.Help;
      PictureBox pictureBox309_1 = this.PictureBox309;
      point1 = new Point(460, 578);
      Point point187 = point1;
      pictureBox309_1.Location = point187;
      this.PictureBox309.Name = "PictureBox309";
      PictureBox pictureBox309_2 = this.PictureBox309;
      size1 = new Size(3, 3);
      Size size187 = size1;
      pictureBox309_2.Size = size187;
      this.PictureBox309.TabIndex = 1748;
      this.PictureBox309.TabStop = false;
      this.PictureBox310.BackColor = Color.White;
      this.PictureBox310.Cursor = Cursors.Help;
      PictureBox pictureBox310_1 = this.PictureBox310;
      point1 = new Point(460, 578);
      Point point188 = point1;
      pictureBox310_1.Location = point188;
      this.PictureBox310.Name = "PictureBox310";
      PictureBox pictureBox310_2 = this.PictureBox310;
      size1 = new Size(3, 3);
      Size size188 = size1;
      pictureBox310_2.Size = size188;
      this.PictureBox310.TabIndex = 1747;
      this.PictureBox310.TabStop = false;
      this.PictureBox311.BackColor = Color.White;
      this.PictureBox311.Cursor = Cursors.Help;
      PictureBox pictureBox311_1 = this.PictureBox311;
      point1 = new Point(460, 578);
      Point point189 = point1;
      pictureBox311_1.Location = point189;
      this.PictureBox311.Name = "PictureBox311";
      PictureBox pictureBox311_2 = this.PictureBox311;
      size1 = new Size(3, 3);
      Size size189 = size1;
      pictureBox311_2.Size = size189;
      this.PictureBox311.TabIndex = 1746;
      this.PictureBox311.TabStop = false;
      this.PictureBox312.BackColor = Color.White;
      this.PictureBox312.Cursor = Cursors.Help;
      PictureBox pictureBox312_1 = this.PictureBox312;
      point1 = new Point(460, 578);
      Point point190 = point1;
      pictureBox312_1.Location = point190;
      this.PictureBox312.Name = "PictureBox312";
      PictureBox pictureBox312_2 = this.PictureBox312;
      size1 = new Size(3, 3);
      Size size190 = size1;
      pictureBox312_2.Size = size190;
      this.PictureBox312.TabIndex = 1745;
      this.PictureBox312.TabStop = false;
      this.PictureBox313.BackColor = Color.White;
      this.PictureBox313.Cursor = Cursors.Help;
      PictureBox pictureBox313_1 = this.PictureBox313;
      point1 = new Point(460, 578);
      Point point191 = point1;
      pictureBox313_1.Location = point191;
      this.PictureBox313.Name = "PictureBox313";
      PictureBox pictureBox313_2 = this.PictureBox313;
      size1 = new Size(3, 3);
      Size size191 = size1;
      pictureBox313_2.Size = size191;
      this.PictureBox313.TabIndex = 1744;
      this.PictureBox313.TabStop = false;
      this.PictureBox314.BackColor = Color.White;
      this.PictureBox314.Cursor = Cursors.Help;
      PictureBox pictureBox314_1 = this.PictureBox314;
      point1 = new Point(460, 578);
      Point point192 = point1;
      pictureBox314_1.Location = point192;
      this.PictureBox314.Name = "PictureBox314";
      PictureBox pictureBox314_2 = this.PictureBox314;
      size1 = new Size(3, 3);
      Size size192 = size1;
      pictureBox314_2.Size = size192;
      this.PictureBox314.TabIndex = 1743;
      this.PictureBox314.TabStop = false;
      this.PictureBox315.BackColor = Color.White;
      this.PictureBox315.Cursor = Cursors.Help;
      PictureBox pictureBox315_1 = this.PictureBox315;
      point1 = new Point(460, 578);
      Point point193 = point1;
      pictureBox315_1.Location = point193;
      this.PictureBox315.Name = "PictureBox315";
      PictureBox pictureBox315_2 = this.PictureBox315;
      size1 = new Size(3, 3);
      Size size193 = size1;
      pictureBox315_2.Size = size193;
      this.PictureBox315.TabIndex = 1742;
      this.PictureBox315.TabStop = false;
      this.PictureBox316.BackColor = Color.White;
      this.PictureBox316.Cursor = Cursors.Help;
      PictureBox pictureBox316_1 = this.PictureBox316;
      point1 = new Point(460, 578);
      Point point194 = point1;
      pictureBox316_1.Location = point194;
      this.PictureBox316.Name = "PictureBox316";
      PictureBox pictureBox316_2 = this.PictureBox316;
      size1 = new Size(3, 3);
      Size size194 = size1;
      pictureBox316_2.Size = size194;
      this.PictureBox316.TabIndex = 1741;
      this.PictureBox316.TabStop = false;
      this.PictureBox317.BackColor = Color.White;
      this.PictureBox317.Cursor = Cursors.Help;
      PictureBox pictureBox317_1 = this.PictureBox317;
      point1 = new Point(460, 578);
      Point point195 = point1;
      pictureBox317_1.Location = point195;
      this.PictureBox317.Name = "PictureBox317";
      PictureBox pictureBox317_2 = this.PictureBox317;
      size1 = new Size(3, 3);
      Size size195 = size1;
      pictureBox317_2.Size = size195;
      this.PictureBox317.TabIndex = 1740;
      this.PictureBox317.TabStop = false;
      this.PictureBox318.BackColor = Color.White;
      this.PictureBox318.Cursor = Cursors.Help;
      PictureBox pictureBox318_1 = this.PictureBox318;
      point1 = new Point(460, 578);
      Point point196 = point1;
      pictureBox318_1.Location = point196;
      this.PictureBox318.Name = "PictureBox318";
      PictureBox pictureBox318_2 = this.PictureBox318;
      size1 = new Size(3, 3);
      Size size196 = size1;
      pictureBox318_2.Size = size196;
      this.PictureBox318.TabIndex = 1739;
      this.PictureBox318.TabStop = false;
      this.PictureBox319.BackColor = Color.White;
      this.PictureBox319.Cursor = Cursors.Help;
      PictureBox pictureBox319_1 = this.PictureBox319;
      point1 = new Point(460, 578);
      Point point197 = point1;
      pictureBox319_1.Location = point197;
      this.PictureBox319.Name = "PictureBox319";
      PictureBox pictureBox319_2 = this.PictureBox319;
      size1 = new Size(3, 3);
      Size size197 = size1;
      pictureBox319_2.Size = size197;
      this.PictureBox319.TabIndex = 1738;
      this.PictureBox319.TabStop = false;
      this.PictureBox320.BackColor = Color.White;
      this.PictureBox320.Cursor = Cursors.Help;
      PictureBox pictureBox320_1 = this.PictureBox320;
      point1 = new Point(460, 578);
      Point point198 = point1;
      pictureBox320_1.Location = point198;
      this.PictureBox320.Name = "PictureBox320";
      PictureBox pictureBox320_2 = this.PictureBox320;
      size1 = new Size(3, 3);
      Size size198 = size1;
      pictureBox320_2.Size = size198;
      this.PictureBox320.TabIndex = 1737;
      this.PictureBox320.TabStop = false;
      this.PictureBox321.BackColor = Color.White;
      this.PictureBox321.Cursor = Cursors.Help;
      PictureBox pictureBox321_1 = this.PictureBox321;
      point1 = new Point(460, 578);
      Point point199 = point1;
      pictureBox321_1.Location = point199;
      this.PictureBox321.Name = "PictureBox321";
      PictureBox pictureBox321_2 = this.PictureBox321;
      size1 = new Size(3, 3);
      Size size199 = size1;
      pictureBox321_2.Size = size199;
      this.PictureBox321.TabIndex = 1736;
      this.PictureBox321.TabStop = false;
      this.PictureBox322.BackColor = Color.White;
      this.PictureBox322.Cursor = Cursors.Help;
      PictureBox pictureBox322_1 = this.PictureBox322;
      point1 = new Point(460, 578);
      Point point200 = point1;
      pictureBox322_1.Location = point200;
      this.PictureBox322.Name = "PictureBox322";
      PictureBox pictureBox322_2 = this.PictureBox322;
      size1 = new Size(3, 3);
      Size size200 = size1;
      pictureBox322_2.Size = size200;
      this.PictureBox322.TabIndex = 1735;
      this.PictureBox322.TabStop = false;
      this.PictureBox323.BackColor = Color.White;
      this.PictureBox323.Cursor = Cursors.Help;
      PictureBox pictureBox323_1 = this.PictureBox323;
      point1 = new Point(460, 578);
      Point point201 = point1;
      pictureBox323_1.Location = point201;
      this.PictureBox323.Name = "PictureBox323";
      PictureBox pictureBox323_2 = this.PictureBox323;
      size1 = new Size(3, 3);
      Size size201 = size1;
      pictureBox323_2.Size = size201;
      this.PictureBox323.TabIndex = 1734;
      this.PictureBox323.TabStop = false;
      this.PictureBox324.BackColor = Color.White;
      this.PictureBox324.Cursor = Cursors.Help;
      PictureBox pictureBox324_1 = this.PictureBox324;
      point1 = new Point(460, 578);
      Point point202 = point1;
      pictureBox324_1.Location = point202;
      this.PictureBox324.Name = "PictureBox324";
      PictureBox pictureBox324_2 = this.PictureBox324;
      size1 = new Size(3, 3);
      Size size202 = size1;
      pictureBox324_2.Size = size202;
      this.PictureBox324.TabIndex = 1733;
      this.PictureBox324.TabStop = false;
      this.PictureBox325.BackColor = Color.White;
      this.PictureBox325.Cursor = Cursors.Help;
      PictureBox pictureBox325_1 = this.PictureBox325;
      point1 = new Point(460, 578);
      Point point203 = point1;
      pictureBox325_1.Location = point203;
      this.PictureBox325.Name = "PictureBox325";
      PictureBox pictureBox325_2 = this.PictureBox325;
      size1 = new Size(3, 3);
      Size size203 = size1;
      pictureBox325_2.Size = size203;
      this.PictureBox325.TabIndex = 1732;
      this.PictureBox325.TabStop = false;
      this.PictureBox326.BackColor = Color.White;
      this.PictureBox326.Cursor = Cursors.Help;
      PictureBox pictureBox326_1 = this.PictureBox326;
      point1 = new Point(460, 578);
      Point point204 = point1;
      pictureBox326_1.Location = point204;
      this.PictureBox326.Name = "PictureBox326";
      PictureBox pictureBox326_2 = this.PictureBox326;
      size1 = new Size(3, 3);
      Size size204 = size1;
      pictureBox326_2.Size = size204;
      this.PictureBox326.TabIndex = 1731;
      this.PictureBox326.TabStop = false;
      this.PictureBox327.BackColor = Color.White;
      this.PictureBox327.Cursor = Cursors.Help;
      PictureBox pictureBox327_1 = this.PictureBox327;
      point1 = new Point(460, 578);
      Point point205 = point1;
      pictureBox327_1.Location = point205;
      this.PictureBox327.Name = "PictureBox327";
      PictureBox pictureBox327_2 = this.PictureBox327;
      size1 = new Size(3, 3);
      Size size205 = size1;
      pictureBox327_2.Size = size205;
      this.PictureBox327.TabIndex = 1730;
      this.PictureBox327.TabStop = false;
      this.PictureBox328.BackColor = Color.White;
      this.PictureBox328.Cursor = Cursors.Help;
      PictureBox pictureBox328_1 = this.PictureBox328;
      point1 = new Point(460, 578);
      Point point206 = point1;
      pictureBox328_1.Location = point206;
      this.PictureBox328.Name = "PictureBox328";
      PictureBox pictureBox328_2 = this.PictureBox328;
      size1 = new Size(3, 3);
      Size size206 = size1;
      pictureBox328_2.Size = size206;
      this.PictureBox328.TabIndex = 1729;
      this.PictureBox328.TabStop = false;
      this.PictureBox329.BackColor = Color.White;
      this.PictureBox329.Cursor = Cursors.Help;
      PictureBox pictureBox329_1 = this.PictureBox329;
      point1 = new Point(460, 578);
      Point point207 = point1;
      pictureBox329_1.Location = point207;
      this.PictureBox329.Name = "PictureBox329";
      PictureBox pictureBox329_2 = this.PictureBox329;
      size1 = new Size(3, 3);
      Size size207 = size1;
      pictureBox329_2.Size = size207;
      this.PictureBox329.TabIndex = 1728;
      this.PictureBox329.TabStop = false;
      this.PictureBox330.BackColor = Color.White;
      this.PictureBox330.Cursor = Cursors.Help;
      PictureBox pictureBox330_1 = this.PictureBox330;
      point1 = new Point(460, 578);
      Point point208 = point1;
      pictureBox330_1.Location = point208;
      this.PictureBox330.Name = "PictureBox330";
      PictureBox pictureBox330_2 = this.PictureBox330;
      size1 = new Size(3, 3);
      Size size208 = size1;
      pictureBox330_2.Size = size208;
      this.PictureBox330.TabIndex = 1727;
      this.PictureBox330.TabStop = false;
      this.PictureBox331.BackColor = Color.White;
      this.PictureBox331.Cursor = Cursors.Help;
      PictureBox pictureBox331_1 = this.PictureBox331;
      point1 = new Point(460, 578);
      Point point209 = point1;
      pictureBox331_1.Location = point209;
      this.PictureBox331.Name = "PictureBox331";
      PictureBox pictureBox331_2 = this.PictureBox331;
      size1 = new Size(3, 3);
      Size size209 = size1;
      pictureBox331_2.Size = size209;
      this.PictureBox331.TabIndex = 1726;
      this.PictureBox331.TabStop = false;
      this.PictureBox332.BackColor = Color.White;
      this.PictureBox332.Cursor = Cursors.Help;
      PictureBox pictureBox332_1 = this.PictureBox332;
      point1 = new Point(460, 578);
      Point point210 = point1;
      pictureBox332_1.Location = point210;
      this.PictureBox332.Name = "PictureBox332";
      PictureBox pictureBox332_2 = this.PictureBox332;
      size1 = new Size(3, 3);
      Size size210 = size1;
      pictureBox332_2.Size = size210;
      this.PictureBox332.TabIndex = 1725;
      this.PictureBox332.TabStop = false;
      this.PictureBox333.BackColor = Color.White;
      this.PictureBox333.Cursor = Cursors.Help;
      PictureBox pictureBox333_1 = this.PictureBox333;
      point1 = new Point(460, 578);
      Point point211 = point1;
      pictureBox333_1.Location = point211;
      this.PictureBox333.Name = "PictureBox333";
      PictureBox pictureBox333_2 = this.PictureBox333;
      size1 = new Size(3, 3);
      Size size211 = size1;
      pictureBox333_2.Size = size211;
      this.PictureBox333.TabIndex = 1724;
      this.PictureBox333.TabStop = false;
      this.PictureBox334.BackColor = Color.White;
      this.PictureBox334.Cursor = Cursors.Help;
      PictureBox pictureBox334_1 = this.PictureBox334;
      point1 = new Point(460, 578);
      Point point212 = point1;
      pictureBox334_1.Location = point212;
      this.PictureBox334.Name = "PictureBox334";
      PictureBox pictureBox334_2 = this.PictureBox334;
      size1 = new Size(3, 3);
      Size size212 = size1;
      pictureBox334_2.Size = size212;
      this.PictureBox334.TabIndex = 1723;
      this.PictureBox334.TabStop = false;
      this.PictureBox335.BackColor = Color.White;
      this.PictureBox335.Cursor = Cursors.Help;
      PictureBox pictureBox335_1 = this.PictureBox335;
      point1 = new Point(460, 578);
      Point point213 = point1;
      pictureBox335_1.Location = point213;
      this.PictureBox335.Name = "PictureBox335";
      PictureBox pictureBox335_2 = this.PictureBox335;
      size1 = new Size(3, 3);
      Size size213 = size1;
      pictureBox335_2.Size = size213;
      this.PictureBox335.TabIndex = 1722;
      this.PictureBox335.TabStop = false;
      this.PictureBox336.BackColor = Color.White;
      this.PictureBox336.Cursor = Cursors.Help;
      PictureBox pictureBox336_1 = this.PictureBox336;
      point1 = new Point(460, 578);
      Point point214 = point1;
      pictureBox336_1.Location = point214;
      this.PictureBox336.Name = "PictureBox336";
      PictureBox pictureBox336_2 = this.PictureBox336;
      size1 = new Size(3, 3);
      Size size214 = size1;
      pictureBox336_2.Size = size214;
      this.PictureBox336.TabIndex = 1721;
      this.PictureBox336.TabStop = false;
      this.PictureBox337.BackColor = Color.White;
      this.PictureBox337.Cursor = Cursors.Help;
      PictureBox pictureBox337_1 = this.PictureBox337;
      point1 = new Point(460, 578);
      Point point215 = point1;
      pictureBox337_1.Location = point215;
      this.PictureBox337.Name = "PictureBox337";
      PictureBox pictureBox337_2 = this.PictureBox337;
      size1 = new Size(3, 3);
      Size size215 = size1;
      pictureBox337_2.Size = size215;
      this.PictureBox337.TabIndex = 1720;
      this.PictureBox337.TabStop = false;
      this.PictureBox338.BackColor = Color.White;
      this.PictureBox338.Cursor = Cursors.Help;
      PictureBox pictureBox338_1 = this.PictureBox338;
      point1 = new Point(460, 578);
      Point point216 = point1;
      pictureBox338_1.Location = point216;
      this.PictureBox338.Name = "PictureBox338";
      PictureBox pictureBox338_2 = this.PictureBox338;
      size1 = new Size(3, 3);
      Size size216 = size1;
      pictureBox338_2.Size = size216;
      this.PictureBox338.TabIndex = 1719;
      this.PictureBox338.TabStop = false;
      this.PictureBox339.BackColor = Color.White;
      this.PictureBox339.Cursor = Cursors.Help;
      PictureBox pictureBox339_1 = this.PictureBox339;
      point1 = new Point(460, 578);
      Point point217 = point1;
      pictureBox339_1.Location = point217;
      this.PictureBox339.Name = "PictureBox339";
      PictureBox pictureBox339_2 = this.PictureBox339;
      size1 = new Size(3, 3);
      Size size217 = size1;
      pictureBox339_2.Size = size217;
      this.PictureBox339.TabIndex = 1718;
      this.PictureBox339.TabStop = false;
      this.PictureBox340.BackColor = Color.White;
      this.PictureBox340.Cursor = Cursors.Help;
      PictureBox pictureBox340_1 = this.PictureBox340;
      point1 = new Point(460, 578);
      Point point218 = point1;
      pictureBox340_1.Location = point218;
      this.PictureBox340.Name = "PictureBox340";
      PictureBox pictureBox340_2 = this.PictureBox340;
      size1 = new Size(3, 3);
      Size size218 = size1;
      pictureBox340_2.Size = size218;
      this.PictureBox340.TabIndex = 1717;
      this.PictureBox340.TabStop = false;
      this.PictureBox341.BackColor = Color.White;
      this.PictureBox341.Cursor = Cursors.Help;
      PictureBox pictureBox341_1 = this.PictureBox341;
      point1 = new Point(460, 578);
      Point point219 = point1;
      pictureBox341_1.Location = point219;
      this.PictureBox341.Name = "PictureBox341";
      PictureBox pictureBox341_2 = this.PictureBox341;
      size1 = new Size(3, 3);
      Size size219 = size1;
      pictureBox341_2.Size = size219;
      this.PictureBox341.TabIndex = 1716;
      this.PictureBox341.TabStop = false;
      this.PictureBox342.BackColor = Color.White;
      this.PictureBox342.Cursor = Cursors.Help;
      PictureBox pictureBox342_1 = this.PictureBox342;
      point1 = new Point(460, 578);
      Point point220 = point1;
      pictureBox342_1.Location = point220;
      this.PictureBox342.Name = "PictureBox342";
      PictureBox pictureBox342_2 = this.PictureBox342;
      size1 = new Size(3, 3);
      Size size220 = size1;
      pictureBox342_2.Size = size220;
      this.PictureBox342.TabIndex = 1715;
      this.PictureBox342.TabStop = false;
      this.PictureBox343.BackColor = Color.White;
      this.PictureBox343.Cursor = Cursors.Help;
      PictureBox pictureBox343_1 = this.PictureBox343;
      point1 = new Point(460, 578);
      Point point221 = point1;
      pictureBox343_1.Location = point221;
      this.PictureBox343.Name = "PictureBox343";
      PictureBox pictureBox343_2 = this.PictureBox343;
      size1 = new Size(3, 3);
      Size size221 = size1;
      pictureBox343_2.Size = size221;
      this.PictureBox343.TabIndex = 1714;
      this.PictureBox343.TabStop = false;
      this.PictureBox344.BackColor = Color.White;
      this.PictureBox344.Cursor = Cursors.Help;
      PictureBox pictureBox344_1 = this.PictureBox344;
      point1 = new Point(460, 578);
      Point point222 = point1;
      pictureBox344_1.Location = point222;
      this.PictureBox344.Name = "PictureBox344";
      PictureBox pictureBox344_2 = this.PictureBox344;
      size1 = new Size(3, 3);
      Size size222 = size1;
      pictureBox344_2.Size = size222;
      this.PictureBox344.TabIndex = 1713;
      this.PictureBox344.TabStop = false;
      this.PictureBox345.BackColor = Color.White;
      this.PictureBox345.Cursor = Cursors.Help;
      PictureBox pictureBox345_1 = this.PictureBox345;
      point1 = new Point(460, 578);
      Point point223 = point1;
      pictureBox345_1.Location = point223;
      this.PictureBox345.Name = "PictureBox345";
      PictureBox pictureBox345_2 = this.PictureBox345;
      size1 = new Size(3, 3);
      Size size223 = size1;
      pictureBox345_2.Size = size223;
      this.PictureBox345.TabIndex = 1712;
      this.PictureBox345.TabStop = false;
      this.PictureBox346.BackColor = Color.White;
      this.PictureBox346.Cursor = Cursors.Help;
      PictureBox pictureBox346_1 = this.PictureBox346;
      point1 = new Point(460, 578);
      Point point224 = point1;
      pictureBox346_1.Location = point224;
      this.PictureBox346.Name = "PictureBox346";
      PictureBox pictureBox346_2 = this.PictureBox346;
      size1 = new Size(3, 3);
      Size size224 = size1;
      pictureBox346_2.Size = size224;
      this.PictureBox346.TabIndex = 1711;
      this.PictureBox346.TabStop = false;
      this.PictureBox347.BackColor = Color.White;
      this.PictureBox347.Cursor = Cursors.Help;
      PictureBox pictureBox347_1 = this.PictureBox347;
      point1 = new Point(460, 578);
      Point point225 = point1;
      pictureBox347_1.Location = point225;
      this.PictureBox347.Name = "PictureBox347";
      PictureBox pictureBox347_2 = this.PictureBox347;
      size1 = new Size(3, 3);
      Size size225 = size1;
      pictureBox347_2.Size = size225;
      this.PictureBox347.TabIndex = 1710;
      this.PictureBox347.TabStop = false;
      this.PictureBox348.BackColor = Color.White;
      this.PictureBox348.Cursor = Cursors.Help;
      PictureBox pictureBox348_1 = this.PictureBox348;
      point1 = new Point(460, 578);
      Point point226 = point1;
      pictureBox348_1.Location = point226;
      this.PictureBox348.Name = "PictureBox348";
      PictureBox pictureBox348_2 = this.PictureBox348;
      size1 = new Size(3, 3);
      Size size226 = size1;
      pictureBox348_2.Size = size226;
      this.PictureBox348.TabIndex = 1709;
      this.PictureBox348.TabStop = false;
      this.PictureBox349.BackColor = Color.White;
      this.PictureBox349.Cursor = Cursors.Help;
      PictureBox pictureBox349_1 = this.PictureBox349;
      point1 = new Point(460, 578);
      Point point227 = point1;
      pictureBox349_1.Location = point227;
      this.PictureBox349.Name = "PictureBox349";
      PictureBox pictureBox349_2 = this.PictureBox349;
      size1 = new Size(3, 3);
      Size size227 = size1;
      pictureBox349_2.Size = size227;
      this.PictureBox349.TabIndex = 1708;
      this.PictureBox349.TabStop = false;
      this.PictureBox350.BackColor = Color.White;
      this.PictureBox350.Cursor = Cursors.Help;
      PictureBox pictureBox350_1 = this.PictureBox350;
      point1 = new Point(460, 578);
      Point point228 = point1;
      pictureBox350_1.Location = point228;
      this.PictureBox350.Name = "PictureBox350";
      PictureBox pictureBox350_2 = this.PictureBox350;
      size1 = new Size(3, 3);
      Size size228 = size1;
      pictureBox350_2.Size = size228;
      this.PictureBox350.TabIndex = 1707;
      this.PictureBox350.TabStop = false;
      this.PictureBox351.BackColor = Color.White;
      this.PictureBox351.Cursor = Cursors.Help;
      PictureBox pictureBox351_1 = this.PictureBox351;
      point1 = new Point(460, 578);
      Point point229 = point1;
      pictureBox351_1.Location = point229;
      this.PictureBox351.Name = "PictureBox351";
      PictureBox pictureBox351_2 = this.PictureBox351;
      size1 = new Size(3, 3);
      Size size229 = size1;
      pictureBox351_2.Size = size229;
      this.PictureBox351.TabIndex = 1706;
      this.PictureBox351.TabStop = false;
      this.PictureBox352.BackColor = Color.White;
      this.PictureBox352.Cursor = Cursors.Help;
      PictureBox pictureBox352_1 = this.PictureBox352;
      point1 = new Point(460, 578);
      Point point230 = point1;
      pictureBox352_1.Location = point230;
      this.PictureBox352.Name = "PictureBox352";
      PictureBox pictureBox352_2 = this.PictureBox352;
      size1 = new Size(3, 3);
      Size size230 = size1;
      pictureBox352_2.Size = size230;
      this.PictureBox352.TabIndex = 1705;
      this.PictureBox352.TabStop = false;
      this.PictureBox353.BackColor = Color.White;
      this.PictureBox353.Cursor = Cursors.Help;
      PictureBox pictureBox353_1 = this.PictureBox353;
      point1 = new Point(460, 578);
      Point point231 = point1;
      pictureBox353_1.Location = point231;
      this.PictureBox353.Name = "PictureBox353";
      PictureBox pictureBox353_2 = this.PictureBox353;
      size1 = new Size(3, 3);
      Size size231 = size1;
      pictureBox353_2.Size = size231;
      this.PictureBox353.TabIndex = 1704;
      this.PictureBox353.TabStop = false;
      this.PictureBox354.BackColor = Color.White;
      this.PictureBox354.Cursor = Cursors.Help;
      PictureBox pictureBox354_1 = this.PictureBox354;
      point1 = new Point(460, 578);
      Point point232 = point1;
      pictureBox354_1.Location = point232;
      this.PictureBox354.Name = "PictureBox354";
      PictureBox pictureBox354_2 = this.PictureBox354;
      size1 = new Size(3, 3);
      Size size232 = size1;
      pictureBox354_2.Size = size232;
      this.PictureBox354.TabIndex = 1703;
      this.PictureBox354.TabStop = false;
      this.PictureBox355.BackColor = Color.White;
      this.PictureBox355.Cursor = Cursors.Help;
      PictureBox pictureBox355_1 = this.PictureBox355;
      point1 = new Point(460, 578);
      Point point233 = point1;
      pictureBox355_1.Location = point233;
      this.PictureBox355.Name = "PictureBox355";
      PictureBox pictureBox355_2 = this.PictureBox355;
      size1 = new Size(3, 3);
      Size size233 = size1;
      pictureBox355_2.Size = size233;
      this.PictureBox355.TabIndex = 1702;
      this.PictureBox355.TabStop = false;
      this.PictureBox356.BackColor = Color.White;
      this.PictureBox356.Cursor = Cursors.Help;
      PictureBox pictureBox356_1 = this.PictureBox356;
      point1 = new Point(460, 578);
      Point point234 = point1;
      pictureBox356_1.Location = point234;
      this.PictureBox356.Name = "PictureBox356";
      PictureBox pictureBox356_2 = this.PictureBox356;
      size1 = new Size(3, 3);
      Size size234 = size1;
      pictureBox356_2.Size = size234;
      this.PictureBox356.TabIndex = 1701;
      this.PictureBox356.TabStop = false;
      this.PictureBox357.BackColor = Color.White;
      this.PictureBox357.Cursor = Cursors.Help;
      PictureBox pictureBox357_1 = this.PictureBox357;
      point1 = new Point(460, 578);
      Point point235 = point1;
      pictureBox357_1.Location = point235;
      this.PictureBox357.Name = "PictureBox357";
      PictureBox pictureBox357_2 = this.PictureBox357;
      size1 = new Size(3, 3);
      Size size235 = size1;
      pictureBox357_2.Size = size235;
      this.PictureBox357.TabIndex = 1700;
      this.PictureBox357.TabStop = false;
      this.PictureBox358.BackColor = Color.White;
      this.PictureBox358.Cursor = Cursors.Help;
      PictureBox pictureBox358_1 = this.PictureBox358;
      point1 = new Point(460, 578);
      Point point236 = point1;
      pictureBox358_1.Location = point236;
      this.PictureBox358.Name = "PictureBox358";
      PictureBox pictureBox358_2 = this.PictureBox358;
      size1 = new Size(3, 3);
      Size size236 = size1;
      pictureBox358_2.Size = size236;
      this.PictureBox358.TabIndex = 1699;
      this.PictureBox358.TabStop = false;
      this.PictureBox359.BackColor = Color.White;
      this.PictureBox359.Cursor = Cursors.Help;
      PictureBox pictureBox359_1 = this.PictureBox359;
      point1 = new Point(460, 578);
      Point point237 = point1;
      pictureBox359_1.Location = point237;
      this.PictureBox359.Name = "PictureBox359";
      PictureBox pictureBox359_2 = this.PictureBox359;
      size1 = new Size(3, 3);
      Size size237 = size1;
      pictureBox359_2.Size = size237;
      this.PictureBox359.TabIndex = 1698;
      this.PictureBox359.TabStop = false;
      this.PictureBox360.BackColor = Color.White;
      this.PictureBox360.Cursor = Cursors.Help;
      PictureBox pictureBox360_1 = this.PictureBox360;
      point1 = new Point(460, 578);
      Point point238 = point1;
      pictureBox360_1.Location = point238;
      this.PictureBox360.Name = "PictureBox360";
      PictureBox pictureBox360_2 = this.PictureBox360;
      size1 = new Size(3, 3);
      Size size238 = size1;
      pictureBox360_2.Size = size238;
      this.PictureBox360.TabIndex = 1697;
      this.PictureBox360.TabStop = false;
      this.PictureBox361.BackColor = Color.White;
      this.PictureBox361.Cursor = Cursors.Help;
      PictureBox pictureBox361_1 = this.PictureBox361;
      point1 = new Point(460, 578);
      Point point239 = point1;
      pictureBox361_1.Location = point239;
      this.PictureBox361.Name = "PictureBox361";
      PictureBox pictureBox361_2 = this.PictureBox361;
      size1 = new Size(3, 3);
      Size size239 = size1;
      pictureBox361_2.Size = size239;
      this.PictureBox361.TabIndex = 1696;
      this.PictureBox361.TabStop = false;
      this.PictureBox362.BackColor = Color.White;
      this.PictureBox362.Cursor = Cursors.Help;
      PictureBox pictureBox362_1 = this.PictureBox362;
      point1 = new Point(460, 578);
      Point point240 = point1;
      pictureBox362_1.Location = point240;
      this.PictureBox362.Name = "PictureBox362";
      PictureBox pictureBox362_2 = this.PictureBox362;
      size1 = new Size(3, 3);
      Size size240 = size1;
      pictureBox362_2.Size = size240;
      this.PictureBox362.TabIndex = 1695;
      this.PictureBox362.TabStop = false;
      this.PictureBox363.BackColor = Color.White;
      this.PictureBox363.Cursor = Cursors.Help;
      PictureBox pictureBox363_1 = this.PictureBox363;
      point1 = new Point(460, 578);
      Point point241 = point1;
      pictureBox363_1.Location = point241;
      this.PictureBox363.Name = "PictureBox363";
      PictureBox pictureBox363_2 = this.PictureBox363;
      size1 = new Size(3, 3);
      Size size241 = size1;
      pictureBox363_2.Size = size241;
      this.PictureBox363.TabIndex = 1694;
      this.PictureBox363.TabStop = false;
      this.PictureBox364.BackColor = Color.White;
      this.PictureBox364.Cursor = Cursors.Help;
      PictureBox pictureBox364_1 = this.PictureBox364;
      point1 = new Point(460, 578);
      Point point242 = point1;
      pictureBox364_1.Location = point242;
      this.PictureBox364.Name = "PictureBox364";
      PictureBox pictureBox364_2 = this.PictureBox364;
      size1 = new Size(3, 3);
      Size size242 = size1;
      pictureBox364_2.Size = size242;
      this.PictureBox364.TabIndex = 1693;
      this.PictureBox364.TabStop = false;
      this.PictureBox365.BackColor = Color.White;
      this.PictureBox365.Cursor = Cursors.Help;
      PictureBox pictureBox365_1 = this.PictureBox365;
      point1 = new Point(460, 578);
      Point point243 = point1;
      pictureBox365_1.Location = point243;
      this.PictureBox365.Name = "PictureBox365";
      PictureBox pictureBox365_2 = this.PictureBox365;
      size1 = new Size(3, 3);
      Size size243 = size1;
      pictureBox365_2.Size = size243;
      this.PictureBox365.TabIndex = 1692;
      this.PictureBox365.TabStop = false;
      this.PictureBox366.BackColor = Color.White;
      this.PictureBox366.Cursor = Cursors.Help;
      PictureBox pictureBox366_1 = this.PictureBox366;
      point1 = new Point(460, 578);
      Point point244 = point1;
      pictureBox366_1.Location = point244;
      this.PictureBox366.Name = "PictureBox366";
      PictureBox pictureBox366_2 = this.PictureBox366;
      size1 = new Size(3, 3);
      Size size244 = size1;
      pictureBox366_2.Size = size244;
      this.PictureBox366.TabIndex = 1691;
      this.PictureBox366.TabStop = false;
      this.PictureBox367.BackColor = Color.White;
      this.PictureBox367.Cursor = Cursors.Help;
      PictureBox pictureBox367_1 = this.PictureBox367;
      point1 = new Point(460, 578);
      Point point245 = point1;
      pictureBox367_1.Location = point245;
      this.PictureBox367.Name = "PictureBox367";
      PictureBox pictureBox367_2 = this.PictureBox367;
      size1 = new Size(3, 3);
      Size size245 = size1;
      pictureBox367_2.Size = size245;
      this.PictureBox367.TabIndex = 1690;
      this.PictureBox367.TabStop = false;
      this.PictureBox368.BackColor = Color.White;
      this.PictureBox368.Cursor = Cursors.Help;
      PictureBox pictureBox368_1 = this.PictureBox368;
      point1 = new Point(460, 578);
      Point point246 = point1;
      pictureBox368_1.Location = point246;
      this.PictureBox368.Name = "PictureBox368";
      PictureBox pictureBox368_2 = this.PictureBox368;
      size1 = new Size(3, 3);
      Size size246 = size1;
      pictureBox368_2.Size = size246;
      this.PictureBox368.TabIndex = 1689;
      this.PictureBox368.TabStop = false;
      this.PictureBox369.BackColor = Color.White;
      this.PictureBox369.Cursor = Cursors.Help;
      PictureBox pictureBox369_1 = this.PictureBox369;
      point1 = new Point(460, 578);
      Point point247 = point1;
      pictureBox369_1.Location = point247;
      this.PictureBox369.Name = "PictureBox369";
      PictureBox pictureBox369_2 = this.PictureBox369;
      size1 = new Size(3, 3);
      Size size247 = size1;
      pictureBox369_2.Size = size247;
      this.PictureBox369.TabIndex = 1688;
      this.PictureBox369.TabStop = false;
      this.PictureBox370.BackColor = Color.White;
      this.PictureBox370.Cursor = Cursors.Help;
      PictureBox pictureBox370_1 = this.PictureBox370;
      point1 = new Point(460, 578);
      Point point248 = point1;
      pictureBox370_1.Location = point248;
      this.PictureBox370.Name = "PictureBox370";
      PictureBox pictureBox370_2 = this.PictureBox370;
      size1 = new Size(3, 3);
      Size size248 = size1;
      pictureBox370_2.Size = size248;
      this.PictureBox370.TabIndex = 1687;
      this.PictureBox370.TabStop = false;
      this.PictureBox371.BackColor = Color.White;
      this.PictureBox371.Cursor = Cursors.Help;
      PictureBox pictureBox371_1 = this.PictureBox371;
      point1 = new Point(460, 578);
      Point point249 = point1;
      pictureBox371_1.Location = point249;
      this.PictureBox371.Name = "PictureBox371";
      PictureBox pictureBox371_2 = this.PictureBox371;
      size1 = new Size(3, 3);
      Size size249 = size1;
      pictureBox371_2.Size = size249;
      this.PictureBox371.TabIndex = 1686;
      this.PictureBox371.TabStop = false;
      this.PictureBox372.BackColor = Color.White;
      this.PictureBox372.Cursor = Cursors.Help;
      PictureBox pictureBox372_1 = this.PictureBox372;
      point1 = new Point(460, 578);
      Point point250 = point1;
      pictureBox372_1.Location = point250;
      this.PictureBox372.Name = "PictureBox372";
      PictureBox pictureBox372_2 = this.PictureBox372;
      size1 = new Size(3, 3);
      Size size250 = size1;
      pictureBox372_2.Size = size250;
      this.PictureBox372.TabIndex = 1685;
      this.PictureBox372.TabStop = false;
      this.PictureBox373.BackColor = Color.White;
      this.PictureBox373.Cursor = Cursors.Help;
      PictureBox pictureBox373_1 = this.PictureBox373;
      point1 = new Point(460, 578);
      Point point251 = point1;
      pictureBox373_1.Location = point251;
      this.PictureBox373.Name = "PictureBox373";
      PictureBox pictureBox373_2 = this.PictureBox373;
      size1 = new Size(3, 3);
      Size size251 = size1;
      pictureBox373_2.Size = size251;
      this.PictureBox373.TabIndex = 1684;
      this.PictureBox373.TabStop = false;
      this.PictureBox374.BackColor = Color.White;
      this.PictureBox374.Cursor = Cursors.Help;
      PictureBox pictureBox374_1 = this.PictureBox374;
      point1 = new Point(460, 578);
      Point point252 = point1;
      pictureBox374_1.Location = point252;
      this.PictureBox374.Name = "PictureBox374";
      PictureBox pictureBox374_2 = this.PictureBox374;
      size1 = new Size(3, 3);
      Size size252 = size1;
      pictureBox374_2.Size = size252;
      this.PictureBox374.TabIndex = 1683;
      this.PictureBox374.TabStop = false;
      this.PictureBox375.BackColor = Color.White;
      this.PictureBox375.Cursor = Cursors.Help;
      PictureBox pictureBox375_1 = this.PictureBox375;
      point1 = new Point(460, 578);
      Point point253 = point1;
      pictureBox375_1.Location = point253;
      this.PictureBox375.Name = "PictureBox375";
      PictureBox pictureBox375_2 = this.PictureBox375;
      size1 = new Size(3, 3);
      Size size253 = size1;
      pictureBox375_2.Size = size253;
      this.PictureBox375.TabIndex = 1682;
      this.PictureBox375.TabStop = false;
      this.PictureBox376.BackColor = Color.White;
      this.PictureBox376.Cursor = Cursors.Help;
      PictureBox pictureBox376_1 = this.PictureBox376;
      point1 = new Point(460, 578);
      Point point254 = point1;
      pictureBox376_1.Location = point254;
      this.PictureBox376.Name = "PictureBox376";
      PictureBox pictureBox376_2 = this.PictureBox376;
      size1 = new Size(3, 3);
      Size size254 = size1;
      pictureBox376_2.Size = size254;
      this.PictureBox376.TabIndex = 1681;
      this.PictureBox376.TabStop = false;
      this.PictureBox377.BackColor = Color.White;
      this.PictureBox377.Cursor = Cursors.Help;
      PictureBox pictureBox377_1 = this.PictureBox377;
      point1 = new Point(460, 578);
      Point point255 = point1;
      pictureBox377_1.Location = point255;
      this.PictureBox377.Name = "PictureBox377";
      PictureBox pictureBox377_2 = this.PictureBox377;
      size1 = new Size(3, 3);
      Size size255 = size1;
      pictureBox377_2.Size = size255;
      this.PictureBox377.TabIndex = 1680;
      this.PictureBox377.TabStop = false;
      this.PictureBox378.BackColor = Color.White;
      this.PictureBox378.Cursor = Cursors.Help;
      PictureBox pictureBox378_1 = this.PictureBox378;
      point1 = new Point(460, 578);
      Point point256 = point1;
      pictureBox378_1.Location = point256;
      this.PictureBox378.Name = "PictureBox378";
      PictureBox pictureBox378_2 = this.PictureBox378;
      size1 = new Size(3, 3);
      Size size256 = size1;
      pictureBox378_2.Size = size256;
      this.PictureBox378.TabIndex = 1679;
      this.PictureBox378.TabStop = false;
      this.PictureBox379.BackColor = Color.White;
      this.PictureBox379.Cursor = Cursors.Help;
      PictureBox pictureBox379_1 = this.PictureBox379;
      point1 = new Point(460, 578);
      Point point257 = point1;
      pictureBox379_1.Location = point257;
      this.PictureBox379.Name = "PictureBox379";
      PictureBox pictureBox379_2 = this.PictureBox379;
      size1 = new Size(3, 3);
      Size size257 = size1;
      pictureBox379_2.Size = size257;
      this.PictureBox379.TabIndex = 1678;
      this.PictureBox379.TabStop = false;
      this.PictureBox380.BackColor = Color.White;
      this.PictureBox380.Cursor = Cursors.Help;
      PictureBox pictureBox380_1 = this.PictureBox380;
      point1 = new Point(460, 578);
      Point point258 = point1;
      pictureBox380_1.Location = point258;
      this.PictureBox380.Name = "PictureBox380";
      PictureBox pictureBox380_2 = this.PictureBox380;
      size1 = new Size(3, 3);
      Size size258 = size1;
      pictureBox380_2.Size = size258;
      this.PictureBox380.TabIndex = 1677;
      this.PictureBox380.TabStop = false;
      this.PictureBox381.BackColor = Color.White;
      this.PictureBox381.Cursor = Cursors.Help;
      PictureBox pictureBox381_1 = this.PictureBox381;
      point1 = new Point(460, 578);
      Point point259 = point1;
      pictureBox381_1.Location = point259;
      this.PictureBox381.Name = "PictureBox381";
      PictureBox pictureBox381_2 = this.PictureBox381;
      size1 = new Size(3, 3);
      Size size259 = size1;
      pictureBox381_2.Size = size259;
      this.PictureBox381.TabIndex = 1676;
      this.PictureBox381.TabStop = false;
      this.PictureBox382.BackColor = Color.White;
      this.PictureBox382.Cursor = Cursors.Help;
      PictureBox pictureBox382_1 = this.PictureBox382;
      point1 = new Point(460, 578);
      Point point260 = point1;
      pictureBox382_1.Location = point260;
      this.PictureBox382.Name = "PictureBox382";
      PictureBox pictureBox382_2 = this.PictureBox382;
      size1 = new Size(3, 3);
      Size size260 = size1;
      pictureBox382_2.Size = size260;
      this.PictureBox382.TabIndex = 1675;
      this.PictureBox382.TabStop = false;
      this.PictureBox383.BackColor = Color.White;
      this.PictureBox383.Cursor = Cursors.Help;
      PictureBox pictureBox383_1 = this.PictureBox383;
      point1 = new Point(460, 578);
      Point point261 = point1;
      pictureBox383_1.Location = point261;
      this.PictureBox383.Name = "PictureBox383";
      PictureBox pictureBox383_2 = this.PictureBox383;
      size1 = new Size(3, 3);
      Size size261 = size1;
      pictureBox383_2.Size = size261;
      this.PictureBox383.TabIndex = 1674;
      this.PictureBox383.TabStop = false;
      this.PictureBox384.BackColor = Color.White;
      this.PictureBox384.Cursor = Cursors.Help;
      PictureBox pictureBox384_1 = this.PictureBox384;
      point1 = new Point(460, 578);
      Point point262 = point1;
      pictureBox384_1.Location = point262;
      this.PictureBox384.Name = "PictureBox384";
      PictureBox pictureBox384_2 = this.PictureBox384;
      size1 = new Size(3, 3);
      Size size262 = size1;
      pictureBox384_2.Size = size262;
      this.PictureBox384.TabIndex = 1673;
      this.PictureBox384.TabStop = false;
      this.PictureBox385.BackColor = Color.White;
      this.PictureBox385.Cursor = Cursors.Help;
      PictureBox pictureBox385_1 = this.PictureBox385;
      point1 = new Point(460, 578);
      Point point263 = point1;
      pictureBox385_1.Location = point263;
      this.PictureBox385.Name = "PictureBox385";
      PictureBox pictureBox385_2 = this.PictureBox385;
      size1 = new Size(3, 3);
      Size size263 = size1;
      pictureBox385_2.Size = size263;
      this.PictureBox385.TabIndex = 1672;
      this.PictureBox385.TabStop = false;
      this.PictureBox386.BackColor = Color.White;
      this.PictureBox386.Cursor = Cursors.Help;
      PictureBox pictureBox386_1 = this.PictureBox386;
      point1 = new Point(460, 578);
      Point point264 = point1;
      pictureBox386_1.Location = point264;
      this.PictureBox386.Name = "PictureBox386";
      PictureBox pictureBox386_2 = this.PictureBox386;
      size1 = new Size(3, 3);
      Size size264 = size1;
      pictureBox386_2.Size = size264;
      this.PictureBox386.TabIndex = 1671;
      this.PictureBox386.TabStop = false;
      this.PictureBox387.BackColor = Color.White;
      this.PictureBox387.Cursor = Cursors.Help;
      PictureBox pictureBox387_1 = this.PictureBox387;
      point1 = new Point(460, 578);
      Point point265 = point1;
      pictureBox387_1.Location = point265;
      this.PictureBox387.Name = "PictureBox387";
      PictureBox pictureBox387_2 = this.PictureBox387;
      size1 = new Size(3, 3);
      Size size265 = size1;
      pictureBox387_2.Size = size265;
      this.PictureBox387.TabIndex = 1670;
      this.PictureBox387.TabStop = false;
      this.PictureBox388.BackColor = Color.White;
      this.PictureBox388.Cursor = Cursors.Help;
      PictureBox pictureBox388_1 = this.PictureBox388;
      point1 = new Point(460, 578);
      Point point266 = point1;
      pictureBox388_1.Location = point266;
      this.PictureBox388.Name = "PictureBox388";
      PictureBox pictureBox388_2 = this.PictureBox388;
      size1 = new Size(3, 3);
      Size size266 = size1;
      pictureBox388_2.Size = size266;
      this.PictureBox388.TabIndex = 1669;
      this.PictureBox388.TabStop = false;
      this.PictureBox389.BackColor = Color.White;
      this.PictureBox389.Cursor = Cursors.Help;
      PictureBox pictureBox389_1 = this.PictureBox389;
      point1 = new Point(460, 578);
      Point point267 = point1;
      pictureBox389_1.Location = point267;
      this.PictureBox389.Name = "PictureBox389";
      PictureBox pictureBox389_2 = this.PictureBox389;
      size1 = new Size(3, 3);
      Size size267 = size1;
      pictureBox389_2.Size = size267;
      this.PictureBox389.TabIndex = 1668;
      this.PictureBox389.TabStop = false;
      this.PictureBox390.BackColor = Color.White;
      this.PictureBox390.Cursor = Cursors.Help;
      PictureBox pictureBox390_1 = this.PictureBox390;
      point1 = new Point(460, 578);
      Point point268 = point1;
      pictureBox390_1.Location = point268;
      this.PictureBox390.Name = "PictureBox390";
      PictureBox pictureBox390_2 = this.PictureBox390;
      size1 = new Size(3, 3);
      Size size268 = size1;
      pictureBox390_2.Size = size268;
      this.PictureBox390.TabIndex = 1667;
      this.PictureBox390.TabStop = false;
      this.PictureBox391.BackColor = Color.White;
      this.PictureBox391.Cursor = Cursors.Help;
      PictureBox pictureBox391_1 = this.PictureBox391;
      point1 = new Point(460, 578);
      Point point269 = point1;
      pictureBox391_1.Location = point269;
      this.PictureBox391.Name = "PictureBox391";
      PictureBox pictureBox391_2 = this.PictureBox391;
      size1 = new Size(3, 3);
      Size size269 = size1;
      pictureBox391_2.Size = size269;
      this.PictureBox391.TabIndex = 1666;
      this.PictureBox391.TabStop = false;
      this.PictureBox392.BackColor = Color.White;
      this.PictureBox392.Cursor = Cursors.Help;
      PictureBox pictureBox392_1 = this.PictureBox392;
      point1 = new Point(460, 578);
      Point point270 = point1;
      pictureBox392_1.Location = point270;
      this.PictureBox392.Name = "PictureBox392";
      PictureBox pictureBox392_2 = this.PictureBox392;
      size1 = new Size(3, 3);
      Size size270 = size1;
      pictureBox392_2.Size = size270;
      this.PictureBox392.TabIndex = 1665;
      this.PictureBox392.TabStop = false;
      this.PictureBox393.BackColor = Color.White;
      this.PictureBox393.Cursor = Cursors.Help;
      PictureBox pictureBox393_1 = this.PictureBox393;
      point1 = new Point(460, 578);
      Point point271 = point1;
      pictureBox393_1.Location = point271;
      this.PictureBox393.Name = "PictureBox393";
      PictureBox pictureBox393_2 = this.PictureBox393;
      size1 = new Size(3, 3);
      Size size271 = size1;
      pictureBox393_2.Size = size271;
      this.PictureBox393.TabIndex = 1664;
      this.PictureBox393.TabStop = false;
      this.PictureBox394.BackColor = Color.White;
      this.PictureBox394.Cursor = Cursors.Help;
      PictureBox pictureBox394_1 = this.PictureBox394;
      point1 = new Point(460, 578);
      Point point272 = point1;
      pictureBox394_1.Location = point272;
      this.PictureBox394.Name = "PictureBox394";
      PictureBox pictureBox394_2 = this.PictureBox394;
      size1 = new Size(3, 3);
      Size size272 = size1;
      pictureBox394_2.Size = size272;
      this.PictureBox394.TabIndex = 1663;
      this.PictureBox394.TabStop = false;
      this.PictureBox395.BackColor = Color.White;
      this.PictureBox395.Cursor = Cursors.Help;
      PictureBox pictureBox395_1 = this.PictureBox395;
      point1 = new Point(460, 578);
      Point point273 = point1;
      pictureBox395_1.Location = point273;
      this.PictureBox395.Name = "PictureBox395";
      PictureBox pictureBox395_2 = this.PictureBox395;
      size1 = new Size(3, 3);
      Size size273 = size1;
      pictureBox395_2.Size = size273;
      this.PictureBox395.TabIndex = 1662;
      this.PictureBox395.TabStop = false;
      this.PictureBox396.BackColor = Color.White;
      this.PictureBox396.Cursor = Cursors.Help;
      PictureBox pictureBox396_1 = this.PictureBox396;
      point1 = new Point(460, 578);
      Point point274 = point1;
      pictureBox396_1.Location = point274;
      this.PictureBox396.Name = "PictureBox396";
      PictureBox pictureBox396_2 = this.PictureBox396;
      size1 = new Size(3, 3);
      Size size274 = size1;
      pictureBox396_2.Size = size274;
      this.PictureBox396.TabIndex = 1661;
      this.PictureBox396.TabStop = false;
      this.PictureBox397.BackColor = Color.White;
      this.PictureBox397.Cursor = Cursors.Help;
      PictureBox pictureBox397_1 = this.PictureBox397;
      point1 = new Point(460, 578);
      Point point275 = point1;
      pictureBox397_1.Location = point275;
      this.PictureBox397.Name = "PictureBox397";
      PictureBox pictureBox397_2 = this.PictureBox397;
      size1 = new Size(3, 3);
      Size size275 = size1;
      pictureBox397_2.Size = size275;
      this.PictureBox397.TabIndex = 1660;
      this.PictureBox397.TabStop = false;
      this.PictureBox398.BackColor = Color.White;
      this.PictureBox398.Cursor = Cursors.Help;
      PictureBox pictureBox398_1 = this.PictureBox398;
      point1 = new Point(460, 578);
      Point point276 = point1;
      pictureBox398_1.Location = point276;
      this.PictureBox398.Name = "PictureBox398";
      PictureBox pictureBox398_2 = this.PictureBox398;
      size1 = new Size(3, 3);
      Size size276 = size1;
      pictureBox398_2.Size = size276;
      this.PictureBox398.TabIndex = 1659;
      this.PictureBox398.TabStop = false;
      this.PictureBox399.BackColor = Color.White;
      this.PictureBox399.Cursor = Cursors.Help;
      PictureBox pictureBox399_1 = this.PictureBox399;
      point1 = new Point(460, 578);
      Point point277 = point1;
      pictureBox399_1.Location = point277;
      this.PictureBox399.Name = "PictureBox399";
      PictureBox pictureBox399_2 = this.PictureBox399;
      size1 = new Size(3, 3);
      Size size277 = size1;
      pictureBox399_2.Size = size277;
      this.PictureBox399.TabIndex = 1658;
      this.PictureBox399.TabStop = false;
      this.PictureBox400.BackColor = Color.White;
      this.PictureBox400.Cursor = Cursors.Help;
      PictureBox pictureBox400_1 = this.PictureBox400;
      point1 = new Point(460, 578);
      Point point278 = point1;
      pictureBox400_1.Location = point278;
      this.PictureBox400.Name = "PictureBox400";
      PictureBox pictureBox400_2 = this.PictureBox400;
      size1 = new Size(3, 3);
      Size size278 = size1;
      pictureBox400_2.Size = size278;
      this.PictureBox400.TabIndex = 1657;
      this.PictureBox400.TabStop = false;
      this.PictureBox401.BackColor = Color.White;
      this.PictureBox401.Cursor = Cursors.Help;
      PictureBox pictureBox401_1 = this.PictureBox401;
      point1 = new Point(460, 578);
      Point point279 = point1;
      pictureBox401_1.Location = point279;
      this.PictureBox401.Name = "PictureBox401";
      PictureBox pictureBox401_2 = this.PictureBox401;
      size1 = new Size(3, 3);
      Size size279 = size1;
      pictureBox401_2.Size = size279;
      this.PictureBox401.TabIndex = 1656;
      this.PictureBox401.TabStop = false;
      this.PictureBox402.BackColor = Color.White;
      this.PictureBox402.Cursor = Cursors.Help;
      PictureBox pictureBox402_1 = this.PictureBox402;
      point1 = new Point(460, 578);
      Point point280 = point1;
      pictureBox402_1.Location = point280;
      this.PictureBox402.Name = "PictureBox402";
      PictureBox pictureBox402_2 = this.PictureBox402;
      size1 = new Size(3, 3);
      Size size280 = size1;
      pictureBox402_2.Size = size280;
      this.PictureBox402.TabIndex = 1655;
      this.PictureBox402.TabStop = false;
      this.PictureBox403.BackColor = Color.White;
      this.PictureBox403.Cursor = Cursors.Help;
      PictureBox pictureBox403_1 = this.PictureBox403;
      point1 = new Point(460, 578);
      Point point281 = point1;
      pictureBox403_1.Location = point281;
      this.PictureBox403.Name = "PictureBox403";
      PictureBox pictureBox403_2 = this.PictureBox403;
      size1 = new Size(3, 3);
      Size size281 = size1;
      pictureBox403_2.Size = size281;
      this.PictureBox403.TabIndex = 1654;
      this.PictureBox403.TabStop = false;
      this.PictureBox404.BackColor = Color.White;
      this.PictureBox404.Cursor = Cursors.Help;
      PictureBox pictureBox404_1 = this.PictureBox404;
      point1 = new Point(460, 578);
      Point point282 = point1;
      pictureBox404_1.Location = point282;
      this.PictureBox404.Name = "PictureBox404";
      PictureBox pictureBox404_2 = this.PictureBox404;
      size1 = new Size(3, 3);
      Size size282 = size1;
      pictureBox404_2.Size = size282;
      this.PictureBox404.TabIndex = 1653;
      this.PictureBox404.TabStop = false;
      this.PictureBox405.BackColor = Color.White;
      this.PictureBox405.Cursor = Cursors.Help;
      PictureBox pictureBox405_1 = this.PictureBox405;
      point1 = new Point(460, 578);
      Point point283 = point1;
      pictureBox405_1.Location = point283;
      this.PictureBox405.Name = "PictureBox405";
      PictureBox pictureBox405_2 = this.PictureBox405;
      size1 = new Size(3, 3);
      Size size283 = size1;
      pictureBox405_2.Size = size283;
      this.PictureBox405.TabIndex = 1652;
      this.PictureBox405.TabStop = false;
      this.PictureBox406.BackColor = Color.White;
      this.PictureBox406.Cursor = Cursors.Help;
      PictureBox pictureBox406_1 = this.PictureBox406;
      point1 = new Point(460, 578);
      Point point284 = point1;
      pictureBox406_1.Location = point284;
      this.PictureBox406.Name = "PictureBox406";
      PictureBox pictureBox406_2 = this.PictureBox406;
      size1 = new Size(3, 3);
      Size size284 = size1;
      pictureBox406_2.Size = size284;
      this.PictureBox406.TabIndex = 1651;
      this.PictureBox406.TabStop = false;
      this.PictureBox407.BackColor = Color.White;
      this.PictureBox407.Cursor = Cursors.Help;
      PictureBox pictureBox407_1 = this.PictureBox407;
      point1 = new Point(460, 578);
      Point point285 = point1;
      pictureBox407_1.Location = point285;
      this.PictureBox407.Name = "PictureBox407";
      PictureBox pictureBox407_2 = this.PictureBox407;
      size1 = new Size(3, 3);
      Size size285 = size1;
      pictureBox407_2.Size = size285;
      this.PictureBox407.TabIndex = 1650;
      this.PictureBox407.TabStop = false;
      this.PictureBox408.BackColor = Color.White;
      this.PictureBox408.Cursor = Cursors.Help;
      PictureBox pictureBox408_1 = this.PictureBox408;
      point1 = new Point(460, 578);
      Point point286 = point1;
      pictureBox408_1.Location = point286;
      this.PictureBox408.Name = "PictureBox408";
      PictureBox pictureBox408_2 = this.PictureBox408;
      size1 = new Size(3, 3);
      Size size286 = size1;
      pictureBox408_2.Size = size286;
      this.PictureBox408.TabIndex = 1649;
      this.PictureBox408.TabStop = false;
      this.PictureBox409.BackColor = Color.White;
      this.PictureBox409.Cursor = Cursors.Help;
      PictureBox pictureBox409_1 = this.PictureBox409;
      point1 = new Point(460, 578);
      Point point287 = point1;
      pictureBox409_1.Location = point287;
      this.PictureBox409.Name = "PictureBox409";
      PictureBox pictureBox409_2 = this.PictureBox409;
      size1 = new Size(3, 3);
      Size size287 = size1;
      pictureBox409_2.Size = size287;
      this.PictureBox409.TabIndex = 1648;
      this.PictureBox409.TabStop = false;
      this.PictureBox410.BackColor = Color.White;
      this.PictureBox410.Cursor = Cursors.Help;
      PictureBox pictureBox410_1 = this.PictureBox410;
      point1 = new Point(460, 578);
      Point point288 = point1;
      pictureBox410_1.Location = point288;
      this.PictureBox410.Name = "PictureBox410";
      PictureBox pictureBox410_2 = this.PictureBox410;
      size1 = new Size(3, 3);
      Size size288 = size1;
      pictureBox410_2.Size = size288;
      this.PictureBox410.TabIndex = 1647;
      this.PictureBox410.TabStop = false;
      this.PictureBox411.BackColor = Color.White;
      this.PictureBox411.Cursor = Cursors.Help;
      PictureBox pictureBox411_1 = this.PictureBox411;
      point1 = new Point(460, 578);
      Point point289 = point1;
      pictureBox411_1.Location = point289;
      this.PictureBox411.Name = "PictureBox411";
      PictureBox pictureBox411_2 = this.PictureBox411;
      size1 = new Size(3, 3);
      Size size289 = size1;
      pictureBox411_2.Size = size289;
      this.PictureBox411.TabIndex = 1646;
      this.PictureBox411.TabStop = false;
      this.PictureBox412.BackColor = Color.White;
      this.PictureBox412.Cursor = Cursors.Help;
      PictureBox pictureBox412_1 = this.PictureBox412;
      point1 = new Point(460, 578);
      Point point290 = point1;
      pictureBox412_1.Location = point290;
      this.PictureBox412.Name = "PictureBox412";
      PictureBox pictureBox412_2 = this.PictureBox412;
      size1 = new Size(3, 3);
      Size size290 = size1;
      pictureBox412_2.Size = size290;
      this.PictureBox412.TabIndex = 1645;
      this.PictureBox412.TabStop = false;
      this.PictureBox413.BackColor = Color.White;
      this.PictureBox413.Cursor = Cursors.Help;
      PictureBox pictureBox413_1 = this.PictureBox413;
      point1 = new Point(460, 578);
      Point point291 = point1;
      pictureBox413_1.Location = point291;
      this.PictureBox413.Name = "PictureBox413";
      PictureBox pictureBox413_2 = this.PictureBox413;
      size1 = new Size(3, 3);
      Size size291 = size1;
      pictureBox413_2.Size = size291;
      this.PictureBox413.TabIndex = 1644;
      this.PictureBox413.TabStop = false;
      this.PictureBox414.BackColor = Color.White;
      this.PictureBox414.Cursor = Cursors.Help;
      PictureBox pictureBox414_1 = this.PictureBox414;
      point1 = new Point(460, 578);
      Point point292 = point1;
      pictureBox414_1.Location = point292;
      this.PictureBox414.Name = "PictureBox414";
      PictureBox pictureBox414_2 = this.PictureBox414;
      size1 = new Size(3, 3);
      Size size292 = size1;
      pictureBox414_2.Size = size292;
      this.PictureBox414.TabIndex = 1643;
      this.PictureBox414.TabStop = false;
      this.PictureBox415.BackColor = Color.White;
      this.PictureBox415.Cursor = Cursors.Help;
      PictureBox pictureBox415_1 = this.PictureBox415;
      point1 = new Point(460, 578);
      Point point293 = point1;
      pictureBox415_1.Location = point293;
      this.PictureBox415.Name = "PictureBox415";
      PictureBox pictureBox415_2 = this.PictureBox415;
      size1 = new Size(3, 3);
      Size size293 = size1;
      pictureBox415_2.Size = size293;
      this.PictureBox415.TabIndex = 1642;
      this.PictureBox415.TabStop = false;
      this.PictureBox416.BackColor = Color.White;
      this.PictureBox416.Cursor = Cursors.Help;
      PictureBox pictureBox416_1 = this.PictureBox416;
      point1 = new Point(460, 578);
      Point point294 = point1;
      pictureBox416_1.Location = point294;
      this.PictureBox416.Name = "PictureBox416";
      PictureBox pictureBox416_2 = this.PictureBox416;
      size1 = new Size(3, 3);
      Size size294 = size1;
      pictureBox416_2.Size = size294;
      this.PictureBox416.TabIndex = 1641;
      this.PictureBox416.TabStop = false;
      this.PictureBox417.BackColor = Color.White;
      this.PictureBox417.Cursor = Cursors.Help;
      PictureBox pictureBox417_1 = this.PictureBox417;
      point1 = new Point(460, 578);
      Point point295 = point1;
      pictureBox417_1.Location = point295;
      this.PictureBox417.Name = "PictureBox417";
      PictureBox pictureBox417_2 = this.PictureBox417;
      size1 = new Size(3, 3);
      Size size295 = size1;
      pictureBox417_2.Size = size295;
      this.PictureBox417.TabIndex = 1640;
      this.PictureBox417.TabStop = false;
      this.PictureBox418.BackColor = Color.White;
      this.PictureBox418.Cursor = Cursors.Help;
      PictureBox pictureBox418_1 = this.PictureBox418;
      point1 = new Point(460, 578);
      Point point296 = point1;
      pictureBox418_1.Location = point296;
      this.PictureBox418.Name = "PictureBox418";
      PictureBox pictureBox418_2 = this.PictureBox418;
      size1 = new Size(3, 3);
      Size size296 = size1;
      pictureBox418_2.Size = size296;
      this.PictureBox418.TabIndex = 1639;
      this.PictureBox418.TabStop = false;
      this.PictureBox419.BackColor = Color.White;
      this.PictureBox419.Cursor = Cursors.Help;
      PictureBox pictureBox419_1 = this.PictureBox419;
      point1 = new Point(460, 578);
      Point point297 = point1;
      pictureBox419_1.Location = point297;
      this.PictureBox419.Name = "PictureBox419";
      PictureBox pictureBox419_2 = this.PictureBox419;
      size1 = new Size(3, 3);
      Size size297 = size1;
      pictureBox419_2.Size = size297;
      this.PictureBox419.TabIndex = 1638;
      this.PictureBox419.TabStop = false;
      this.PictureBox420.BackColor = Color.White;
      this.PictureBox420.Cursor = Cursors.Help;
      PictureBox pictureBox420_1 = this.PictureBox420;
      point1 = new Point(460, 578);
      Point point298 = point1;
      pictureBox420_1.Location = point298;
      this.PictureBox420.Name = "PictureBox420";
      PictureBox pictureBox420_2 = this.PictureBox420;
      size1 = new Size(3, 3);
      Size size298 = size1;
      pictureBox420_2.Size = size298;
      this.PictureBox420.TabIndex = 1637;
      this.PictureBox420.TabStop = false;
      this.PictureBox421.BackColor = Color.White;
      this.PictureBox421.Cursor = Cursors.Help;
      PictureBox pictureBox421_1 = this.PictureBox421;
      point1 = new Point(460, 578);
      Point point299 = point1;
      pictureBox421_1.Location = point299;
      this.PictureBox421.Name = "PictureBox421";
      PictureBox pictureBox421_2 = this.PictureBox421;
      size1 = new Size(3, 3);
      Size size299 = size1;
      pictureBox421_2.Size = size299;
      this.PictureBox421.TabIndex = 1636;
      this.PictureBox421.TabStop = false;
      this.PictureBox422.BackColor = Color.White;
      this.PictureBox422.Cursor = Cursors.Help;
      PictureBox pictureBox422_1 = this.PictureBox422;
      point1 = new Point(460, 578);
      Point point300 = point1;
      pictureBox422_1.Location = point300;
      this.PictureBox422.Name = "PictureBox422";
      PictureBox pictureBox422_2 = this.PictureBox422;
      size1 = new Size(3, 3);
      Size size300 = size1;
      pictureBox422_2.Size = size300;
      this.PictureBox422.TabIndex = 1635;
      this.PictureBox422.TabStop = false;
      this.PictureBox423.BackColor = Color.White;
      this.PictureBox423.Cursor = Cursors.Help;
      PictureBox pictureBox423_1 = this.PictureBox423;
      point1 = new Point(460, 578);
      Point point301 = point1;
      pictureBox423_1.Location = point301;
      this.PictureBox423.Name = "PictureBox423";
      PictureBox pictureBox423_2 = this.PictureBox423;
      size1 = new Size(3, 3);
      Size size301 = size1;
      pictureBox423_2.Size = size301;
      this.PictureBox423.TabIndex = 1634;
      this.PictureBox423.TabStop = false;
      this.PictureBox424.BackColor = Color.White;
      this.PictureBox424.Cursor = Cursors.Help;
      PictureBox pictureBox424_1 = this.PictureBox424;
      point1 = new Point(460, 578);
      Point point302 = point1;
      pictureBox424_1.Location = point302;
      this.PictureBox424.Name = "PictureBox424";
      PictureBox pictureBox424_2 = this.PictureBox424;
      size1 = new Size(3, 3);
      Size size302 = size1;
      pictureBox424_2.Size = size302;
      this.PictureBox424.TabIndex = 1633;
      this.PictureBox424.TabStop = false;
      this.PictureBox425.BackColor = Color.White;
      this.PictureBox425.Cursor = Cursors.Help;
      PictureBox pictureBox425_1 = this.PictureBox425;
      point1 = new Point(460, 578);
      Point point303 = point1;
      pictureBox425_1.Location = point303;
      this.PictureBox425.Name = "PictureBox425";
      PictureBox pictureBox425_2 = this.PictureBox425;
      size1 = new Size(3, 3);
      Size size303 = size1;
      pictureBox425_2.Size = size303;
      this.PictureBox425.TabIndex = 1632;
      this.PictureBox425.TabStop = false;
      this.PictureBox426.BackColor = Color.White;
      this.PictureBox426.Cursor = Cursors.Help;
      PictureBox pictureBox426_1 = this.PictureBox426;
      point1 = new Point(460, 578);
      Point point304 = point1;
      pictureBox426_1.Location = point304;
      this.PictureBox426.Name = "PictureBox426";
      PictureBox pictureBox426_2 = this.PictureBox426;
      size1 = new Size(3, 3);
      Size size304 = size1;
      pictureBox426_2.Size = size304;
      this.PictureBox426.TabIndex = 1631;
      this.PictureBox426.TabStop = false;
      this.PictureBox427.BackColor = Color.White;
      this.PictureBox427.Cursor = Cursors.Help;
      PictureBox pictureBox427_1 = this.PictureBox427;
      point1 = new Point(460, 578);
      Point point305 = point1;
      pictureBox427_1.Location = point305;
      this.PictureBox427.Name = "PictureBox427";
      PictureBox pictureBox427_2 = this.PictureBox427;
      size1 = new Size(3, 3);
      Size size305 = size1;
      pictureBox427_2.Size = size305;
      this.PictureBox427.TabIndex = 1630;
      this.PictureBox427.TabStop = false;
      this.PictureBox428.BackColor = Color.White;
      this.PictureBox428.Cursor = Cursors.Help;
      PictureBox pictureBox428_1 = this.PictureBox428;
      point1 = new Point(460, 578);
      Point point306 = point1;
      pictureBox428_1.Location = point306;
      this.PictureBox428.Name = "PictureBox428";
      PictureBox pictureBox428_2 = this.PictureBox428;
      size1 = new Size(3, 3);
      Size size306 = size1;
      pictureBox428_2.Size = size306;
      this.PictureBox428.TabIndex = 1629;
      this.PictureBox428.TabStop = false;
      this.PictureBox429.BackColor = Color.White;
      this.PictureBox429.Cursor = Cursors.Help;
      PictureBox pictureBox429_1 = this.PictureBox429;
      point1 = new Point(460, 578);
      Point point307 = point1;
      pictureBox429_1.Location = point307;
      this.PictureBox429.Name = "PictureBox429";
      PictureBox pictureBox429_2 = this.PictureBox429;
      size1 = new Size(3, 3);
      Size size307 = size1;
      pictureBox429_2.Size = size307;
      this.PictureBox429.TabIndex = 1628;
      this.PictureBox429.TabStop = false;
      this.PictureBox430.BackColor = Color.White;
      this.PictureBox430.Cursor = Cursors.Help;
      PictureBox pictureBox430_1 = this.PictureBox430;
      point1 = new Point(460, 578);
      Point point308 = point1;
      pictureBox430_1.Location = point308;
      this.PictureBox430.Name = "PictureBox430";
      PictureBox pictureBox430_2 = this.PictureBox430;
      size1 = new Size(3, 3);
      Size size308 = size1;
      pictureBox430_2.Size = size308;
      this.PictureBox430.TabIndex = 1627;
      this.PictureBox430.TabStop = false;
      this.PictureBox431.BackColor = Color.White;
      this.PictureBox431.Cursor = Cursors.Help;
      PictureBox pictureBox431_1 = this.PictureBox431;
      point1 = new Point(460, 578);
      Point point309 = point1;
      pictureBox431_1.Location = point309;
      this.PictureBox431.Name = "PictureBox431";
      PictureBox pictureBox431_2 = this.PictureBox431;
      size1 = new Size(3, 3);
      Size size309 = size1;
      pictureBox431_2.Size = size309;
      this.PictureBox431.TabIndex = 1626;
      this.PictureBox431.TabStop = false;
      this.PictureBox432.BackColor = Color.White;
      this.PictureBox432.Cursor = Cursors.Help;
      PictureBox pictureBox432_1 = this.PictureBox432;
      point1 = new Point(460, 578);
      Point point310 = point1;
      pictureBox432_1.Location = point310;
      this.PictureBox432.Name = "PictureBox432";
      PictureBox pictureBox432_2 = this.PictureBox432;
      size1 = new Size(3, 3);
      Size size310 = size1;
      pictureBox432_2.Size = size310;
      this.PictureBox432.TabIndex = 1625;
      this.PictureBox432.TabStop = false;
      this.PictureBox433.BackColor = Color.White;
      this.PictureBox433.Cursor = Cursors.Help;
      PictureBox pictureBox433_1 = this.PictureBox433;
      point1 = new Point(460, 578);
      Point point311 = point1;
      pictureBox433_1.Location = point311;
      this.PictureBox433.Name = "PictureBox433";
      PictureBox pictureBox433_2 = this.PictureBox433;
      size1 = new Size(3, 3);
      Size size311 = size1;
      pictureBox433_2.Size = size311;
      this.PictureBox433.TabIndex = 1624;
      this.PictureBox433.TabStop = false;
      this.PictureBox434.BackColor = Color.White;
      this.PictureBox434.Cursor = Cursors.Help;
      PictureBox pictureBox434_1 = this.PictureBox434;
      point1 = new Point(460, 578);
      Point point312 = point1;
      pictureBox434_1.Location = point312;
      this.PictureBox434.Name = "PictureBox434";
      PictureBox pictureBox434_2 = this.PictureBox434;
      size1 = new Size(3, 3);
      Size size312 = size1;
      pictureBox434_2.Size = size312;
      this.PictureBox434.TabIndex = 1623;
      this.PictureBox434.TabStop = false;
      this.PictureBox435.BackColor = Color.White;
      this.PictureBox435.Cursor = Cursors.Help;
      PictureBox pictureBox435_1 = this.PictureBox435;
      point1 = new Point(460, 578);
      Point point313 = point1;
      pictureBox435_1.Location = point313;
      this.PictureBox435.Name = "PictureBox435";
      PictureBox pictureBox435_2 = this.PictureBox435;
      size1 = new Size(3, 3);
      Size size313 = size1;
      pictureBox435_2.Size = size313;
      this.PictureBox435.TabIndex = 1622;
      this.PictureBox435.TabStop = false;
      this.PictureBox436.BackColor = Color.White;
      this.PictureBox436.Cursor = Cursors.Help;
      PictureBox pictureBox436_1 = this.PictureBox436;
      point1 = new Point(460, 578);
      Point point314 = point1;
      pictureBox436_1.Location = point314;
      this.PictureBox436.Name = "PictureBox436";
      PictureBox pictureBox436_2 = this.PictureBox436;
      size1 = new Size(3, 3);
      Size size314 = size1;
      pictureBox436_2.Size = size314;
      this.PictureBox436.TabIndex = 1621;
      this.PictureBox436.TabStop = false;
      this.PictureBox437.BackColor = Color.White;
      this.PictureBox437.Cursor = Cursors.Help;
      PictureBox pictureBox437_1 = this.PictureBox437;
      point1 = new Point(460, 578);
      Point point315 = point1;
      pictureBox437_1.Location = point315;
      this.PictureBox437.Name = "PictureBox437";
      PictureBox pictureBox437_2 = this.PictureBox437;
      size1 = new Size(3, 3);
      Size size315 = size1;
      pictureBox437_2.Size = size315;
      this.PictureBox437.TabIndex = 1620;
      this.PictureBox437.TabStop = false;
      this.PictureBox438.BackColor = Color.White;
      this.PictureBox438.Cursor = Cursors.Help;
      PictureBox pictureBox438_1 = this.PictureBox438;
      point1 = new Point(460, 578);
      Point point316 = point1;
      pictureBox438_1.Location = point316;
      this.PictureBox438.Name = "PictureBox438";
      PictureBox pictureBox438_2 = this.PictureBox438;
      size1 = new Size(3, 3);
      Size size316 = size1;
      pictureBox438_2.Size = size316;
      this.PictureBox438.TabIndex = 1619;
      this.PictureBox438.TabStop = false;
      this.PictureBox439.BackColor = Color.White;
      this.PictureBox439.Cursor = Cursors.Help;
      PictureBox pictureBox439_1 = this.PictureBox439;
      point1 = new Point(460, 578);
      Point point317 = point1;
      pictureBox439_1.Location = point317;
      this.PictureBox439.Name = "PictureBox439";
      PictureBox pictureBox439_2 = this.PictureBox439;
      size1 = new Size(3, 3);
      Size size317 = size1;
      pictureBox439_2.Size = size317;
      this.PictureBox439.TabIndex = 1618;
      this.PictureBox439.TabStop = false;
      this.PictureBox440.BackColor = Color.White;
      this.PictureBox440.Cursor = Cursors.Help;
      PictureBox pictureBox440_1 = this.PictureBox440;
      point1 = new Point(460, 578);
      Point point318 = point1;
      pictureBox440_1.Location = point318;
      this.PictureBox440.Name = "PictureBox440";
      PictureBox pictureBox440_2 = this.PictureBox440;
      size1 = new Size(3, 3);
      Size size318 = size1;
      pictureBox440_2.Size = size318;
      this.PictureBox440.TabIndex = 1617;
      this.PictureBox440.TabStop = false;
      this.PictureBox441.BackColor = Color.White;
      this.PictureBox441.Cursor = Cursors.Help;
      PictureBox pictureBox441_1 = this.PictureBox441;
      point1 = new Point(460, 578);
      Point point319 = point1;
      pictureBox441_1.Location = point319;
      this.PictureBox441.Name = "PictureBox441";
      PictureBox pictureBox441_2 = this.PictureBox441;
      size1 = new Size(3, 3);
      Size size319 = size1;
      pictureBox441_2.Size = size319;
      this.PictureBox441.TabIndex = 1616;
      this.PictureBox441.TabStop = false;
      this.PictureBox442.BackColor = Color.White;
      this.PictureBox442.Cursor = Cursors.Help;
      PictureBox pictureBox442_1 = this.PictureBox442;
      point1 = new Point(460, 578);
      Point point320 = point1;
      pictureBox442_1.Location = point320;
      this.PictureBox442.Name = "PictureBox442";
      PictureBox pictureBox442_2 = this.PictureBox442;
      size1 = new Size(3, 3);
      Size size320 = size1;
      pictureBox442_2.Size = size320;
      this.PictureBox442.TabIndex = 1615;
      this.PictureBox442.TabStop = false;
      this.PictureBox443.BackColor = Color.White;
      this.PictureBox443.Cursor = Cursors.Help;
      PictureBox pictureBox443_1 = this.PictureBox443;
      point1 = new Point(460, 578);
      Point point321 = point1;
      pictureBox443_1.Location = point321;
      this.PictureBox443.Name = "PictureBox443";
      PictureBox pictureBox443_2 = this.PictureBox443;
      size1 = new Size(3, 3);
      Size size321 = size1;
      pictureBox443_2.Size = size321;
      this.PictureBox443.TabIndex = 1614;
      this.PictureBox443.TabStop = false;
      this.PictureBox444.BackColor = Color.White;
      this.PictureBox444.Cursor = Cursors.Help;
      PictureBox pictureBox444_1 = this.PictureBox444;
      point1 = new Point(460, 578);
      Point point322 = point1;
      pictureBox444_1.Location = point322;
      this.PictureBox444.Name = "PictureBox444";
      PictureBox pictureBox444_2 = this.PictureBox444;
      size1 = new Size(3, 3);
      Size size322 = size1;
      pictureBox444_2.Size = size322;
      this.PictureBox444.TabIndex = 1613;
      this.PictureBox444.TabStop = false;
      this.PictureBox445.BackColor = Color.White;
      this.PictureBox445.Cursor = Cursors.Help;
      PictureBox pictureBox445_1 = this.PictureBox445;
      point1 = new Point(460, 578);
      Point point323 = point1;
      pictureBox445_1.Location = point323;
      this.PictureBox445.Name = "PictureBox445";
      PictureBox pictureBox445_2 = this.PictureBox445;
      size1 = new Size(3, 3);
      Size size323 = size1;
      pictureBox445_2.Size = size323;
      this.PictureBox445.TabIndex = 1612;
      this.PictureBox445.TabStop = false;
      this.PictureBox446.BackColor = Color.White;
      this.PictureBox446.Cursor = Cursors.Help;
      PictureBox pictureBox446_1 = this.PictureBox446;
      point1 = new Point(460, 578);
      Point point324 = point1;
      pictureBox446_1.Location = point324;
      this.PictureBox446.Name = "PictureBox446";
      PictureBox pictureBox446_2 = this.PictureBox446;
      size1 = new Size(3, 3);
      Size size324 = size1;
      pictureBox446_2.Size = size324;
      this.PictureBox446.TabIndex = 1611;
      this.PictureBox446.TabStop = false;
      this.PictureBox447.BackColor = Color.White;
      this.PictureBox447.Cursor = Cursors.Help;
      PictureBox pictureBox447_1 = this.PictureBox447;
      point1 = new Point(460, 578);
      Point point325 = point1;
      pictureBox447_1.Location = point325;
      this.PictureBox447.Name = "PictureBox447";
      PictureBox pictureBox447_2 = this.PictureBox447;
      size1 = new Size(3, 3);
      Size size325 = size1;
      pictureBox447_2.Size = size325;
      this.PictureBox447.TabIndex = 1610;
      this.PictureBox447.TabStop = false;
      this.PictureBox448.BackColor = Color.White;
      this.PictureBox448.Cursor = Cursors.Help;
      PictureBox pictureBox448_1 = this.PictureBox448;
      point1 = new Point(460, 578);
      Point point326 = point1;
      pictureBox448_1.Location = point326;
      this.PictureBox448.Name = "PictureBox448";
      PictureBox pictureBox448_2 = this.PictureBox448;
      size1 = new Size(3, 3);
      Size size326 = size1;
      pictureBox448_2.Size = size326;
      this.PictureBox448.TabIndex = 1609;
      this.PictureBox448.TabStop = false;
      this.PictureBox113.BackColor = Color.White;
      this.PictureBox113.Cursor = Cursors.Help;
      PictureBox pictureBox113_1 = this.PictureBox113;
      point1 = new Point(460, 578);
      Point point327 = point1;
      pictureBox113_1.Location = point327;
      this.PictureBox113.Name = "PictureBox113";
      PictureBox pictureBox113_2 = this.PictureBox113;
      size1 = new Size(3, 3);
      Size size327 = size1;
      pictureBox113_2.Size = size327;
      this.PictureBox113.TabIndex = 1608;
      this.PictureBox113.TabStop = false;
      this.PictureBox114.BackColor = Color.White;
      this.PictureBox114.Cursor = Cursors.Help;
      PictureBox pictureBox114_1 = this.PictureBox114;
      point1 = new Point(460, 578);
      Point point328 = point1;
      pictureBox114_1.Location = point328;
      this.PictureBox114.Name = "PictureBox114";
      PictureBox pictureBox114_2 = this.PictureBox114;
      size1 = new Size(3, 3);
      Size size328 = size1;
      pictureBox114_2.Size = size328;
      this.PictureBox114.TabIndex = 1607;
      this.PictureBox114.TabStop = false;
      this.PictureBox115.BackColor = Color.White;
      this.PictureBox115.Cursor = Cursors.Help;
      PictureBox pictureBox115_1 = this.PictureBox115;
      point1 = new Point(460, 578);
      Point point329 = point1;
      pictureBox115_1.Location = point329;
      this.PictureBox115.Name = "PictureBox115";
      PictureBox pictureBox115_2 = this.PictureBox115;
      size1 = new Size(3, 3);
      Size size329 = size1;
      pictureBox115_2.Size = size329;
      this.PictureBox115.TabIndex = 1606;
      this.PictureBox115.TabStop = false;
      this.PictureBox116.BackColor = Color.White;
      this.PictureBox116.Cursor = Cursors.Help;
      PictureBox pictureBox116_1 = this.PictureBox116;
      point1 = new Point(460, 578);
      Point point330 = point1;
      pictureBox116_1.Location = point330;
      this.PictureBox116.Name = "PictureBox116";
      PictureBox pictureBox116_2 = this.PictureBox116;
      size1 = new Size(3, 3);
      Size size330 = size1;
      pictureBox116_2.Size = size330;
      this.PictureBox116.TabIndex = 1605;
      this.PictureBox116.TabStop = false;
      this.PictureBox117.BackColor = Color.White;
      this.PictureBox117.Cursor = Cursors.Help;
      PictureBox pictureBox117_1 = this.PictureBox117;
      point1 = new Point(460, 578);
      Point point331 = point1;
      pictureBox117_1.Location = point331;
      this.PictureBox117.Name = "PictureBox117";
      PictureBox pictureBox117_2 = this.PictureBox117;
      size1 = new Size(3, 3);
      Size size331 = size1;
      pictureBox117_2.Size = size331;
      this.PictureBox117.TabIndex = 1604;
      this.PictureBox117.TabStop = false;
      this.PictureBox118.BackColor = Color.White;
      this.PictureBox118.Cursor = Cursors.Help;
      PictureBox pictureBox118_1 = this.PictureBox118;
      point1 = new Point(460, 578);
      Point point332 = point1;
      pictureBox118_1.Location = point332;
      this.PictureBox118.Name = "PictureBox118";
      PictureBox pictureBox118_2 = this.PictureBox118;
      size1 = new Size(3, 3);
      Size size332 = size1;
      pictureBox118_2.Size = size332;
      this.PictureBox118.TabIndex = 1603;
      this.PictureBox118.TabStop = false;
      this.PictureBox119.BackColor = Color.White;
      this.PictureBox119.Cursor = Cursors.Help;
      PictureBox pictureBox119_1 = this.PictureBox119;
      point1 = new Point(460, 578);
      Point point333 = point1;
      pictureBox119_1.Location = point333;
      this.PictureBox119.Name = "PictureBox119";
      PictureBox pictureBox119_2 = this.PictureBox119;
      size1 = new Size(3, 3);
      Size size333 = size1;
      pictureBox119_2.Size = size333;
      this.PictureBox119.TabIndex = 1602;
      this.PictureBox119.TabStop = false;
      this.PictureBox120.BackColor = Color.White;
      this.PictureBox120.Cursor = Cursors.Help;
      PictureBox pictureBox120_1 = this.PictureBox120;
      point1 = new Point(460, 578);
      Point point334 = point1;
      pictureBox120_1.Location = point334;
      this.PictureBox120.Name = "PictureBox120";
      PictureBox pictureBox120_2 = this.PictureBox120;
      size1 = new Size(3, 3);
      Size size334 = size1;
      pictureBox120_2.Size = size334;
      this.PictureBox120.TabIndex = 1601;
      this.PictureBox120.TabStop = false;
      this.PictureBox121.BackColor = Color.White;
      this.PictureBox121.Cursor = Cursors.Help;
      PictureBox pictureBox121_1 = this.PictureBox121;
      point1 = new Point(460, 578);
      Point point335 = point1;
      pictureBox121_1.Location = point335;
      this.PictureBox121.Name = "PictureBox121";
      PictureBox pictureBox121_2 = this.PictureBox121;
      size1 = new Size(3, 3);
      Size size335 = size1;
      pictureBox121_2.Size = size335;
      this.PictureBox121.TabIndex = 1600;
      this.PictureBox121.TabStop = false;
      this.PictureBox122.BackColor = Color.White;
      this.PictureBox122.Cursor = Cursors.Help;
      PictureBox pictureBox122_1 = this.PictureBox122;
      point1 = new Point(460, 578);
      Point point336 = point1;
      pictureBox122_1.Location = point336;
      this.PictureBox122.Name = "PictureBox122";
      PictureBox pictureBox122_2 = this.PictureBox122;
      size1 = new Size(3, 3);
      Size size336 = size1;
      pictureBox122_2.Size = size336;
      this.PictureBox122.TabIndex = 1599;
      this.PictureBox122.TabStop = false;
      this.PictureBox123.BackColor = Color.White;
      this.PictureBox123.Cursor = Cursors.Help;
      PictureBox pictureBox123_1 = this.PictureBox123;
      point1 = new Point(460, 578);
      Point point337 = point1;
      pictureBox123_1.Location = point337;
      this.PictureBox123.Name = "PictureBox123";
      PictureBox pictureBox123_2 = this.PictureBox123;
      size1 = new Size(3, 3);
      Size size337 = size1;
      pictureBox123_2.Size = size337;
      this.PictureBox123.TabIndex = 1598;
      this.PictureBox123.TabStop = false;
      this.PictureBox124.BackColor = Color.White;
      this.PictureBox124.Cursor = Cursors.Help;
      PictureBox pictureBox124_1 = this.PictureBox124;
      point1 = new Point(460, 578);
      Point point338 = point1;
      pictureBox124_1.Location = point338;
      this.PictureBox124.Name = "PictureBox124";
      PictureBox pictureBox124_2 = this.PictureBox124;
      size1 = new Size(3, 3);
      Size size338 = size1;
      pictureBox124_2.Size = size338;
      this.PictureBox124.TabIndex = 1597;
      this.PictureBox124.TabStop = false;
      this.PictureBox125.BackColor = Color.White;
      this.PictureBox125.Cursor = Cursors.Help;
      PictureBox pictureBox125_1 = this.PictureBox125;
      point1 = new Point(460, 578);
      Point point339 = point1;
      pictureBox125_1.Location = point339;
      this.PictureBox125.Name = "PictureBox125";
      PictureBox pictureBox125_2 = this.PictureBox125;
      size1 = new Size(3, 3);
      Size size339 = size1;
      pictureBox125_2.Size = size339;
      this.PictureBox125.TabIndex = 1596;
      this.PictureBox125.TabStop = false;
      this.PictureBox126.BackColor = Color.White;
      this.PictureBox126.Cursor = Cursors.Help;
      PictureBox pictureBox126_1 = this.PictureBox126;
      point1 = new Point(460, 578);
      Point point340 = point1;
      pictureBox126_1.Location = point340;
      this.PictureBox126.Name = "PictureBox126";
      PictureBox pictureBox126_2 = this.PictureBox126;
      size1 = new Size(3, 3);
      Size size340 = size1;
      pictureBox126_2.Size = size340;
      this.PictureBox126.TabIndex = 1595;
      this.PictureBox126.TabStop = false;
      this.PictureBox127.BackColor = Color.White;
      this.PictureBox127.Cursor = Cursors.Help;
      PictureBox pictureBox127_1 = this.PictureBox127;
      point1 = new Point(460, 578);
      Point point341 = point1;
      pictureBox127_1.Location = point341;
      this.PictureBox127.Name = "PictureBox127";
      PictureBox pictureBox127_2 = this.PictureBox127;
      size1 = new Size(3, 3);
      Size size341 = size1;
      pictureBox127_2.Size = size341;
      this.PictureBox127.TabIndex = 1594;
      this.PictureBox127.TabStop = false;
      this.PictureBox128.BackColor = Color.White;
      this.PictureBox128.Cursor = Cursors.Help;
      PictureBox pictureBox128_1 = this.PictureBox128;
      point1 = new Point(460, 578);
      Point point342 = point1;
      pictureBox128_1.Location = point342;
      this.PictureBox128.Name = "PictureBox128";
      PictureBox pictureBox128_2 = this.PictureBox128;
      size1 = new Size(3, 3);
      Size size342 = size1;
      pictureBox128_2.Size = size342;
      this.PictureBox128.TabIndex = 1593;
      this.PictureBox128.TabStop = false;
      this.PictureBox129.BackColor = Color.White;
      this.PictureBox129.Cursor = Cursors.Help;
      PictureBox pictureBox129_1 = this.PictureBox129;
      point1 = new Point(460, 578);
      Point point343 = point1;
      pictureBox129_1.Location = point343;
      this.PictureBox129.Name = "PictureBox129";
      PictureBox pictureBox129_2 = this.PictureBox129;
      size1 = new Size(3, 3);
      Size size343 = size1;
      pictureBox129_2.Size = size343;
      this.PictureBox129.TabIndex = 1592;
      this.PictureBox129.TabStop = false;
      this.PictureBox130.BackColor = Color.White;
      this.PictureBox130.Cursor = Cursors.Help;
      PictureBox pictureBox130_1 = this.PictureBox130;
      point1 = new Point(460, 578);
      Point point344 = point1;
      pictureBox130_1.Location = point344;
      this.PictureBox130.Name = "PictureBox130";
      PictureBox pictureBox130_2 = this.PictureBox130;
      size1 = new Size(3, 3);
      Size size344 = size1;
      pictureBox130_2.Size = size344;
      this.PictureBox130.TabIndex = 1591;
      this.PictureBox130.TabStop = false;
      this.PictureBox131.BackColor = Color.White;
      this.PictureBox131.Cursor = Cursors.Help;
      PictureBox pictureBox131_1 = this.PictureBox131;
      point1 = new Point(460, 578);
      Point point345 = point1;
      pictureBox131_1.Location = point345;
      this.PictureBox131.Name = "PictureBox131";
      PictureBox pictureBox131_2 = this.PictureBox131;
      size1 = new Size(3, 3);
      Size size345 = size1;
      pictureBox131_2.Size = size345;
      this.PictureBox131.TabIndex = 1590;
      this.PictureBox131.TabStop = false;
      this.PictureBox132.BackColor = Color.White;
      this.PictureBox132.Cursor = Cursors.Help;
      PictureBox pictureBox132_1 = this.PictureBox132;
      point1 = new Point(460, 578);
      Point point346 = point1;
      pictureBox132_1.Location = point346;
      this.PictureBox132.Name = "PictureBox132";
      PictureBox pictureBox132_2 = this.PictureBox132;
      size1 = new Size(3, 3);
      Size size346 = size1;
      pictureBox132_2.Size = size346;
      this.PictureBox132.TabIndex = 1589;
      this.PictureBox132.TabStop = false;
      this.PictureBox133.BackColor = Color.White;
      this.PictureBox133.Cursor = Cursors.Help;
      PictureBox pictureBox133_1 = this.PictureBox133;
      point1 = new Point(460, 578);
      Point point347 = point1;
      pictureBox133_1.Location = point347;
      this.PictureBox133.Name = "PictureBox133";
      PictureBox pictureBox133_2 = this.PictureBox133;
      size1 = new Size(3, 3);
      Size size347 = size1;
      pictureBox133_2.Size = size347;
      this.PictureBox133.TabIndex = 1588;
      this.PictureBox133.TabStop = false;
      this.PictureBox134.BackColor = Color.White;
      this.PictureBox134.Cursor = Cursors.Help;
      PictureBox pictureBox134_1 = this.PictureBox134;
      point1 = new Point(460, 578);
      Point point348 = point1;
      pictureBox134_1.Location = point348;
      this.PictureBox134.Name = "PictureBox134";
      PictureBox pictureBox134_2 = this.PictureBox134;
      size1 = new Size(3, 3);
      Size size348 = size1;
      pictureBox134_2.Size = size348;
      this.PictureBox134.TabIndex = 1587;
      this.PictureBox134.TabStop = false;
      this.PictureBox135.BackColor = Color.White;
      this.PictureBox135.Cursor = Cursors.Help;
      PictureBox pictureBox135_1 = this.PictureBox135;
      point1 = new Point(460, 578);
      Point point349 = point1;
      pictureBox135_1.Location = point349;
      this.PictureBox135.Name = "PictureBox135";
      PictureBox pictureBox135_2 = this.PictureBox135;
      size1 = new Size(3, 3);
      Size size349 = size1;
      pictureBox135_2.Size = size349;
      this.PictureBox135.TabIndex = 1586;
      this.PictureBox135.TabStop = false;
      this.PictureBox136.BackColor = Color.White;
      this.PictureBox136.Cursor = Cursors.Help;
      PictureBox pictureBox136_1 = this.PictureBox136;
      point1 = new Point(460, 578);
      Point point350 = point1;
      pictureBox136_1.Location = point350;
      this.PictureBox136.Name = "PictureBox136";
      PictureBox pictureBox136_2 = this.PictureBox136;
      size1 = new Size(3, 3);
      Size size350 = size1;
      pictureBox136_2.Size = size350;
      this.PictureBox136.TabIndex = 1585;
      this.PictureBox136.TabStop = false;
      this.PictureBox137.BackColor = Color.White;
      this.PictureBox137.Cursor = Cursors.Help;
      PictureBox pictureBox137_1 = this.PictureBox137;
      point1 = new Point(460, 578);
      Point point351 = point1;
      pictureBox137_1.Location = point351;
      this.PictureBox137.Name = "PictureBox137";
      PictureBox pictureBox137_2 = this.PictureBox137;
      size1 = new Size(3, 3);
      Size size351 = size1;
      pictureBox137_2.Size = size351;
      this.PictureBox137.TabIndex = 1584;
      this.PictureBox137.TabStop = false;
      this.PictureBox138.BackColor = Color.White;
      this.PictureBox138.Cursor = Cursors.Help;
      PictureBox pictureBox138_1 = this.PictureBox138;
      point1 = new Point(460, 578);
      Point point352 = point1;
      pictureBox138_1.Location = point352;
      this.PictureBox138.Name = "PictureBox138";
      PictureBox pictureBox138_2 = this.PictureBox138;
      size1 = new Size(3, 3);
      Size size352 = size1;
      pictureBox138_2.Size = size352;
      this.PictureBox138.TabIndex = 1583;
      this.PictureBox138.TabStop = false;
      this.PictureBox139.BackColor = Color.White;
      this.PictureBox139.Cursor = Cursors.Help;
      PictureBox pictureBox139_1 = this.PictureBox139;
      point1 = new Point(460, 578);
      Point point353 = point1;
      pictureBox139_1.Location = point353;
      this.PictureBox139.Name = "PictureBox139";
      PictureBox pictureBox139_2 = this.PictureBox139;
      size1 = new Size(3, 3);
      Size size353 = size1;
      pictureBox139_2.Size = size353;
      this.PictureBox139.TabIndex = 1582;
      this.PictureBox139.TabStop = false;
      this.PictureBox140.BackColor = Color.White;
      this.PictureBox140.Cursor = Cursors.Help;
      PictureBox pictureBox140_1 = this.PictureBox140;
      point1 = new Point(460, 578);
      Point point354 = point1;
      pictureBox140_1.Location = point354;
      this.PictureBox140.Name = "PictureBox140";
      PictureBox pictureBox140_2 = this.PictureBox140;
      size1 = new Size(3, 3);
      Size size354 = size1;
      pictureBox140_2.Size = size354;
      this.PictureBox140.TabIndex = 1581;
      this.PictureBox140.TabStop = false;
      this.PictureBox141.BackColor = Color.White;
      this.PictureBox141.Cursor = Cursors.Help;
      PictureBox pictureBox141_1 = this.PictureBox141;
      point1 = new Point(460, 578);
      Point point355 = point1;
      pictureBox141_1.Location = point355;
      this.PictureBox141.Name = "PictureBox141";
      PictureBox pictureBox141_2 = this.PictureBox141;
      size1 = new Size(3, 3);
      Size size355 = size1;
      pictureBox141_2.Size = size355;
      this.PictureBox141.TabIndex = 1580;
      this.PictureBox141.TabStop = false;
      this.PictureBox142.BackColor = Color.White;
      this.PictureBox142.Cursor = Cursors.Help;
      PictureBox pictureBox142_1 = this.PictureBox142;
      point1 = new Point(460, 578);
      Point point356 = point1;
      pictureBox142_1.Location = point356;
      this.PictureBox142.Name = "PictureBox142";
      PictureBox pictureBox142_2 = this.PictureBox142;
      size1 = new Size(3, 3);
      Size size356 = size1;
      pictureBox142_2.Size = size356;
      this.PictureBox142.TabIndex = 1579;
      this.PictureBox142.TabStop = false;
      this.PictureBox143.BackColor = Color.White;
      this.PictureBox143.Cursor = Cursors.Help;
      PictureBox pictureBox143_1 = this.PictureBox143;
      point1 = new Point(460, 578);
      Point point357 = point1;
      pictureBox143_1.Location = point357;
      this.PictureBox143.Name = "PictureBox143";
      PictureBox pictureBox143_2 = this.PictureBox143;
      size1 = new Size(3, 3);
      Size size357 = size1;
      pictureBox143_2.Size = size357;
      this.PictureBox143.TabIndex = 1578;
      this.PictureBox143.TabStop = false;
      this.PictureBox144.BackColor = Color.White;
      this.PictureBox144.Cursor = Cursors.Help;
      PictureBox pictureBox144_1 = this.PictureBox144;
      point1 = new Point(460, 578);
      Point point358 = point1;
      pictureBox144_1.Location = point358;
      this.PictureBox144.Name = "PictureBox144";
      PictureBox pictureBox144_2 = this.PictureBox144;
      size1 = new Size(3, 3);
      Size size358 = size1;
      pictureBox144_2.Size = size358;
      this.PictureBox144.TabIndex = 1577;
      this.PictureBox144.TabStop = false;
      this.PictureBox145.BackColor = Color.White;
      this.PictureBox145.Cursor = Cursors.Help;
      PictureBox pictureBox145_1 = this.PictureBox145;
      point1 = new Point(460, 578);
      Point point359 = point1;
      pictureBox145_1.Location = point359;
      this.PictureBox145.Name = "PictureBox145";
      PictureBox pictureBox145_2 = this.PictureBox145;
      size1 = new Size(3, 3);
      Size size359 = size1;
      pictureBox145_2.Size = size359;
      this.PictureBox145.TabIndex = 1576;
      this.PictureBox145.TabStop = false;
      this.PictureBox146.BackColor = Color.White;
      this.PictureBox146.Cursor = Cursors.Help;
      PictureBox pictureBox146_1 = this.PictureBox146;
      point1 = new Point(460, 578);
      Point point360 = point1;
      pictureBox146_1.Location = point360;
      this.PictureBox146.Name = "PictureBox146";
      PictureBox pictureBox146_2 = this.PictureBox146;
      size1 = new Size(3, 3);
      Size size360 = size1;
      pictureBox146_2.Size = size360;
      this.PictureBox146.TabIndex = 1575;
      this.PictureBox146.TabStop = false;
      this.PictureBox147.BackColor = Color.White;
      this.PictureBox147.Cursor = Cursors.Help;
      PictureBox pictureBox147_1 = this.PictureBox147;
      point1 = new Point(460, 578);
      Point point361 = point1;
      pictureBox147_1.Location = point361;
      this.PictureBox147.Name = "PictureBox147";
      PictureBox pictureBox147_2 = this.PictureBox147;
      size1 = new Size(3, 3);
      Size size361 = size1;
      pictureBox147_2.Size = size361;
      this.PictureBox147.TabIndex = 1574;
      this.PictureBox147.TabStop = false;
      this.PictureBox148.BackColor = Color.White;
      this.PictureBox148.Cursor = Cursors.Help;
      PictureBox pictureBox148_1 = this.PictureBox148;
      point1 = new Point(460, 578);
      Point point362 = point1;
      pictureBox148_1.Location = point362;
      this.PictureBox148.Name = "PictureBox148";
      PictureBox pictureBox148_2 = this.PictureBox148;
      size1 = new Size(3, 3);
      Size size362 = size1;
      pictureBox148_2.Size = size362;
      this.PictureBox148.TabIndex = 1573;
      this.PictureBox148.TabStop = false;
      this.PictureBox149.BackColor = Color.White;
      this.PictureBox149.Cursor = Cursors.Help;
      PictureBox pictureBox149_1 = this.PictureBox149;
      point1 = new Point(460, 578);
      Point point363 = point1;
      pictureBox149_1.Location = point363;
      this.PictureBox149.Name = "PictureBox149";
      PictureBox pictureBox149_2 = this.PictureBox149;
      size1 = new Size(3, 3);
      Size size363 = size1;
      pictureBox149_2.Size = size363;
      this.PictureBox149.TabIndex = 1572;
      this.PictureBox149.TabStop = false;
      this.PictureBox150.BackColor = Color.White;
      this.PictureBox150.Cursor = Cursors.Help;
      PictureBox pictureBox150_1 = this.PictureBox150;
      point1 = new Point(460, 578);
      Point point364 = point1;
      pictureBox150_1.Location = point364;
      this.PictureBox150.Name = "PictureBox150";
      PictureBox pictureBox150_2 = this.PictureBox150;
      size1 = new Size(3, 3);
      Size size364 = size1;
      pictureBox150_2.Size = size364;
      this.PictureBox150.TabIndex = 1571;
      this.PictureBox150.TabStop = false;
      this.PictureBox151.BackColor = Color.White;
      this.PictureBox151.Cursor = Cursors.Help;
      PictureBox pictureBox151_1 = this.PictureBox151;
      point1 = new Point(460, 578);
      Point point365 = point1;
      pictureBox151_1.Location = point365;
      this.PictureBox151.Name = "PictureBox151";
      PictureBox pictureBox151_2 = this.PictureBox151;
      size1 = new Size(3, 3);
      Size size365 = size1;
      pictureBox151_2.Size = size365;
      this.PictureBox151.TabIndex = 1570;
      this.PictureBox151.TabStop = false;
      this.PictureBox152.BackColor = Color.White;
      this.PictureBox152.Cursor = Cursors.Help;
      PictureBox pictureBox152_1 = this.PictureBox152;
      point1 = new Point(460, 578);
      Point point366 = point1;
      pictureBox152_1.Location = point366;
      this.PictureBox152.Name = "PictureBox152";
      PictureBox pictureBox152_2 = this.PictureBox152;
      size1 = new Size(3, 3);
      Size size366 = size1;
      pictureBox152_2.Size = size366;
      this.PictureBox152.TabIndex = 1569;
      this.PictureBox152.TabStop = false;
      this.PictureBox153.BackColor = Color.White;
      this.PictureBox153.Cursor = Cursors.Help;
      PictureBox pictureBox153_1 = this.PictureBox153;
      point1 = new Point(460, 578);
      Point point367 = point1;
      pictureBox153_1.Location = point367;
      this.PictureBox153.Name = "PictureBox153";
      PictureBox pictureBox153_2 = this.PictureBox153;
      size1 = new Size(3, 3);
      Size size367 = size1;
      pictureBox153_2.Size = size367;
      this.PictureBox153.TabIndex = 1568;
      this.PictureBox153.TabStop = false;
      this.PictureBox154.BackColor = Color.White;
      this.PictureBox154.Cursor = Cursors.Help;
      PictureBox pictureBox154_1 = this.PictureBox154;
      point1 = new Point(460, 578);
      Point point368 = point1;
      pictureBox154_1.Location = point368;
      this.PictureBox154.Name = "PictureBox154";
      PictureBox pictureBox154_2 = this.PictureBox154;
      size1 = new Size(3, 3);
      Size size368 = size1;
      pictureBox154_2.Size = size368;
      this.PictureBox154.TabIndex = 1567;
      this.PictureBox154.TabStop = false;
      this.PictureBox155.BackColor = Color.White;
      this.PictureBox155.Cursor = Cursors.Help;
      PictureBox pictureBox155_1 = this.PictureBox155;
      point1 = new Point(460, 578);
      Point point369 = point1;
      pictureBox155_1.Location = point369;
      this.PictureBox155.Name = "PictureBox155";
      PictureBox pictureBox155_2 = this.PictureBox155;
      size1 = new Size(3, 3);
      Size size369 = size1;
      pictureBox155_2.Size = size369;
      this.PictureBox155.TabIndex = 1566;
      this.PictureBox155.TabStop = false;
      this.PictureBox156.BackColor = Color.White;
      this.PictureBox156.Cursor = Cursors.Help;
      PictureBox pictureBox156_1 = this.PictureBox156;
      point1 = new Point(460, 578);
      Point point370 = point1;
      pictureBox156_1.Location = point370;
      this.PictureBox156.Name = "PictureBox156";
      PictureBox pictureBox156_2 = this.PictureBox156;
      size1 = new Size(3, 3);
      Size size370 = size1;
      pictureBox156_2.Size = size370;
      this.PictureBox156.TabIndex = 1565;
      this.PictureBox156.TabStop = false;
      this.PictureBox157.BackColor = Color.White;
      this.PictureBox157.Cursor = Cursors.Help;
      PictureBox pictureBox157_1 = this.PictureBox157;
      point1 = new Point(460, 578);
      Point point371 = point1;
      pictureBox157_1.Location = point371;
      this.PictureBox157.Name = "PictureBox157";
      PictureBox pictureBox157_2 = this.PictureBox157;
      size1 = new Size(3, 3);
      Size size371 = size1;
      pictureBox157_2.Size = size371;
      this.PictureBox157.TabIndex = 1564;
      this.PictureBox157.TabStop = false;
      this.PictureBox158.BackColor = Color.White;
      this.PictureBox158.Cursor = Cursors.Help;
      PictureBox pictureBox158_1 = this.PictureBox158;
      point1 = new Point(460, 578);
      Point point372 = point1;
      pictureBox158_1.Location = point372;
      this.PictureBox158.Name = "PictureBox158";
      PictureBox pictureBox158_2 = this.PictureBox158;
      size1 = new Size(3, 3);
      Size size372 = size1;
      pictureBox158_2.Size = size372;
      this.PictureBox158.TabIndex = 1563;
      this.PictureBox158.TabStop = false;
      this.PictureBox159.BackColor = Color.White;
      this.PictureBox159.Cursor = Cursors.Help;
      PictureBox pictureBox159_1 = this.PictureBox159;
      point1 = new Point(460, 578);
      Point point373 = point1;
      pictureBox159_1.Location = point373;
      this.PictureBox159.Name = "PictureBox159";
      PictureBox pictureBox159_2 = this.PictureBox159;
      size1 = new Size(3, 3);
      Size size373 = size1;
      pictureBox159_2.Size = size373;
      this.PictureBox159.TabIndex = 1562;
      this.PictureBox159.TabStop = false;
      this.PictureBox160.BackColor = Color.White;
      this.PictureBox160.Cursor = Cursors.Help;
      PictureBox pictureBox160_1 = this.PictureBox160;
      point1 = new Point(460, 578);
      Point point374 = point1;
      pictureBox160_1.Location = point374;
      this.PictureBox160.Name = "PictureBox160";
      PictureBox pictureBox160_2 = this.PictureBox160;
      size1 = new Size(3, 3);
      Size size374 = size1;
      pictureBox160_2.Size = size374;
      this.PictureBox160.TabIndex = 1561;
      this.PictureBox160.TabStop = false;
      this.PictureBox161.BackColor = Color.White;
      this.PictureBox161.Cursor = Cursors.Help;
      PictureBox pictureBox161_1 = this.PictureBox161;
      point1 = new Point(460, 578);
      Point point375 = point1;
      pictureBox161_1.Location = point375;
      this.PictureBox161.Name = "PictureBox161";
      PictureBox pictureBox161_2 = this.PictureBox161;
      size1 = new Size(3, 3);
      Size size375 = size1;
      pictureBox161_2.Size = size375;
      this.PictureBox161.TabIndex = 1560;
      this.PictureBox161.TabStop = false;
      this.PictureBox162.BackColor = Color.White;
      this.PictureBox162.Cursor = Cursors.Help;
      PictureBox pictureBox162_1 = this.PictureBox162;
      point1 = new Point(460, 578);
      Point point376 = point1;
      pictureBox162_1.Location = point376;
      this.PictureBox162.Name = "PictureBox162";
      PictureBox pictureBox162_2 = this.PictureBox162;
      size1 = new Size(3, 3);
      Size size376 = size1;
      pictureBox162_2.Size = size376;
      this.PictureBox162.TabIndex = 1559;
      this.PictureBox162.TabStop = false;
      this.PictureBox163.BackColor = Color.White;
      this.PictureBox163.Cursor = Cursors.Help;
      PictureBox pictureBox163_1 = this.PictureBox163;
      point1 = new Point(460, 578);
      Point point377 = point1;
      pictureBox163_1.Location = point377;
      this.PictureBox163.Name = "PictureBox163";
      PictureBox pictureBox163_2 = this.PictureBox163;
      size1 = new Size(3, 3);
      Size size377 = size1;
      pictureBox163_2.Size = size377;
      this.PictureBox163.TabIndex = 1558;
      this.PictureBox163.TabStop = false;
      this.PictureBox164.BackColor = Color.White;
      this.PictureBox164.Cursor = Cursors.Help;
      PictureBox pictureBox164_1 = this.PictureBox164;
      point1 = new Point(460, 578);
      Point point378 = point1;
      pictureBox164_1.Location = point378;
      this.PictureBox164.Name = "PictureBox164";
      PictureBox pictureBox164_2 = this.PictureBox164;
      size1 = new Size(3, 3);
      Size size378 = size1;
      pictureBox164_2.Size = size378;
      this.PictureBox164.TabIndex = 1557;
      this.PictureBox164.TabStop = false;
      this.PictureBox165.BackColor = Color.White;
      this.PictureBox165.Cursor = Cursors.Help;
      PictureBox pictureBox165_1 = this.PictureBox165;
      point1 = new Point(460, 578);
      Point point379 = point1;
      pictureBox165_1.Location = point379;
      this.PictureBox165.Name = "PictureBox165";
      PictureBox pictureBox165_2 = this.PictureBox165;
      size1 = new Size(3, 3);
      Size size379 = size1;
      pictureBox165_2.Size = size379;
      this.PictureBox165.TabIndex = 1556;
      this.PictureBox165.TabStop = false;
      this.PictureBox166.BackColor = Color.White;
      this.PictureBox166.Cursor = Cursors.Help;
      PictureBox pictureBox166_1 = this.PictureBox166;
      point1 = new Point(460, 578);
      Point point380 = point1;
      pictureBox166_1.Location = point380;
      this.PictureBox166.Name = "PictureBox166";
      PictureBox pictureBox166_2 = this.PictureBox166;
      size1 = new Size(3, 3);
      Size size380 = size1;
      pictureBox166_2.Size = size380;
      this.PictureBox166.TabIndex = 1555;
      this.PictureBox166.TabStop = false;
      this.PictureBox167.BackColor = Color.White;
      this.PictureBox167.Cursor = Cursors.Help;
      PictureBox pictureBox167_1 = this.PictureBox167;
      point1 = new Point(460, 578);
      Point point381 = point1;
      pictureBox167_1.Location = point381;
      this.PictureBox167.Name = "PictureBox167";
      PictureBox pictureBox167_2 = this.PictureBox167;
      size1 = new Size(3, 3);
      Size size381 = size1;
      pictureBox167_2.Size = size381;
      this.PictureBox167.TabIndex = 1554;
      this.PictureBox167.TabStop = false;
      this.PictureBox168.BackColor = Color.White;
      this.PictureBox168.Cursor = Cursors.Help;
      PictureBox pictureBox168_1 = this.PictureBox168;
      point1 = new Point(460, 578);
      Point point382 = point1;
      pictureBox168_1.Location = point382;
      this.PictureBox168.Name = "PictureBox168";
      PictureBox pictureBox168_2 = this.PictureBox168;
      size1 = new Size(3, 3);
      Size size382 = size1;
      pictureBox168_2.Size = size382;
      this.PictureBox168.TabIndex = 1553;
      this.PictureBox168.TabStop = false;
      this.PictureBox169.BackColor = Color.White;
      this.PictureBox169.Cursor = Cursors.Help;
      PictureBox pictureBox169_1 = this.PictureBox169;
      point1 = new Point(460, 578);
      Point point383 = point1;
      pictureBox169_1.Location = point383;
      this.PictureBox169.Name = "PictureBox169";
      PictureBox pictureBox169_2 = this.PictureBox169;
      size1 = new Size(3, 3);
      Size size383 = size1;
      pictureBox169_2.Size = size383;
      this.PictureBox169.TabIndex = 1552;
      this.PictureBox169.TabStop = false;
      this.PictureBox170.BackColor = Color.White;
      this.PictureBox170.Cursor = Cursors.Help;
      PictureBox pictureBox170_1 = this.PictureBox170;
      point1 = new Point(460, 578);
      Point point384 = point1;
      pictureBox170_1.Location = point384;
      this.PictureBox170.Name = "PictureBox170";
      PictureBox pictureBox170_2 = this.PictureBox170;
      size1 = new Size(3, 3);
      Size size384 = size1;
      pictureBox170_2.Size = size384;
      this.PictureBox170.TabIndex = 1551;
      this.PictureBox170.TabStop = false;
      this.PictureBox171.BackColor = Color.White;
      this.PictureBox171.Cursor = Cursors.Help;
      PictureBox pictureBox171_1 = this.PictureBox171;
      point1 = new Point(460, 578);
      Point point385 = point1;
      pictureBox171_1.Location = point385;
      this.PictureBox171.Name = "PictureBox171";
      PictureBox pictureBox171_2 = this.PictureBox171;
      size1 = new Size(3, 3);
      Size size385 = size1;
      pictureBox171_2.Size = size385;
      this.PictureBox171.TabIndex = 1550;
      this.PictureBox171.TabStop = false;
      this.PictureBox172.BackColor = Color.White;
      this.PictureBox172.Cursor = Cursors.Help;
      PictureBox pictureBox172_1 = this.PictureBox172;
      point1 = new Point(460, 578);
      Point point386 = point1;
      pictureBox172_1.Location = point386;
      this.PictureBox172.Name = "PictureBox172";
      PictureBox pictureBox172_2 = this.PictureBox172;
      size1 = new Size(3, 3);
      Size size386 = size1;
      pictureBox172_2.Size = size386;
      this.PictureBox172.TabIndex = 1549;
      this.PictureBox172.TabStop = false;
      this.PictureBox173.BackColor = Color.White;
      this.PictureBox173.Cursor = Cursors.Help;
      PictureBox pictureBox173_1 = this.PictureBox173;
      point1 = new Point(460, 578);
      Point point387 = point1;
      pictureBox173_1.Location = point387;
      this.PictureBox173.Name = "PictureBox173";
      PictureBox pictureBox173_2 = this.PictureBox173;
      size1 = new Size(3, 3);
      Size size387 = size1;
      pictureBox173_2.Size = size387;
      this.PictureBox173.TabIndex = 1548;
      this.PictureBox173.TabStop = false;
      this.PictureBox174.BackColor = Color.White;
      this.PictureBox174.Cursor = Cursors.Help;
      PictureBox pictureBox174_1 = this.PictureBox174;
      point1 = new Point(460, 578);
      Point point388 = point1;
      pictureBox174_1.Location = point388;
      this.PictureBox174.Name = "PictureBox174";
      PictureBox pictureBox174_2 = this.PictureBox174;
      size1 = new Size(3, 3);
      Size size388 = size1;
      pictureBox174_2.Size = size388;
      this.PictureBox174.TabIndex = 1547;
      this.PictureBox174.TabStop = false;
      this.PictureBox175.BackColor = Color.White;
      this.PictureBox175.Cursor = Cursors.Help;
      PictureBox pictureBox175_1 = this.PictureBox175;
      point1 = new Point(460, 578);
      Point point389 = point1;
      pictureBox175_1.Location = point389;
      this.PictureBox175.Name = "PictureBox175";
      PictureBox pictureBox175_2 = this.PictureBox175;
      size1 = new Size(3, 3);
      Size size389 = size1;
      pictureBox175_2.Size = size389;
      this.PictureBox175.TabIndex = 1546;
      this.PictureBox175.TabStop = false;
      this.PictureBox176.BackColor = Color.White;
      this.PictureBox176.Cursor = Cursors.Help;
      PictureBox pictureBox176_1 = this.PictureBox176;
      point1 = new Point(460, 578);
      Point point390 = point1;
      pictureBox176_1.Location = point390;
      this.PictureBox176.Name = "PictureBox176";
      PictureBox pictureBox176_2 = this.PictureBox176;
      size1 = new Size(3, 3);
      Size size390 = size1;
      pictureBox176_2.Size = size390;
      this.PictureBox176.TabIndex = 1545;
      this.PictureBox176.TabStop = false;
      this.PictureBox177.BackColor = Color.White;
      this.PictureBox177.Cursor = Cursors.Help;
      PictureBox pictureBox177_1 = this.PictureBox177;
      point1 = new Point(460, 578);
      Point point391 = point1;
      pictureBox177_1.Location = point391;
      this.PictureBox177.Name = "PictureBox177";
      PictureBox pictureBox177_2 = this.PictureBox177;
      size1 = new Size(3, 3);
      Size size391 = size1;
      pictureBox177_2.Size = size391;
      this.PictureBox177.TabIndex = 1544;
      this.PictureBox177.TabStop = false;
      this.PictureBox178.BackColor = Color.White;
      this.PictureBox178.Cursor = Cursors.Help;
      PictureBox pictureBox178_1 = this.PictureBox178;
      point1 = new Point(460, 578);
      Point point392 = point1;
      pictureBox178_1.Location = point392;
      this.PictureBox178.Name = "PictureBox178";
      PictureBox pictureBox178_2 = this.PictureBox178;
      size1 = new Size(3, 3);
      Size size392 = size1;
      pictureBox178_2.Size = size392;
      this.PictureBox178.TabIndex = 1543;
      this.PictureBox178.TabStop = false;
      this.PictureBox179.BackColor = Color.White;
      this.PictureBox179.Cursor = Cursors.Help;
      PictureBox pictureBox179_1 = this.PictureBox179;
      point1 = new Point(460, 578);
      Point point393 = point1;
      pictureBox179_1.Location = point393;
      this.PictureBox179.Name = "PictureBox179";
      PictureBox pictureBox179_2 = this.PictureBox179;
      size1 = new Size(3, 3);
      Size size393 = size1;
      pictureBox179_2.Size = size393;
      this.PictureBox179.TabIndex = 1542;
      this.PictureBox179.TabStop = false;
      this.PictureBox180.BackColor = Color.White;
      this.PictureBox180.Cursor = Cursors.Help;
      PictureBox pictureBox180_1 = this.PictureBox180;
      point1 = new Point(460, 578);
      Point point394 = point1;
      pictureBox180_1.Location = point394;
      this.PictureBox180.Name = "PictureBox180";
      PictureBox pictureBox180_2 = this.PictureBox180;
      size1 = new Size(3, 3);
      Size size394 = size1;
      pictureBox180_2.Size = size394;
      this.PictureBox180.TabIndex = 1541;
      this.PictureBox180.TabStop = false;
      this.PictureBox181.BackColor = Color.White;
      this.PictureBox181.Cursor = Cursors.Help;
      PictureBox pictureBox181_1 = this.PictureBox181;
      point1 = new Point(460, 578);
      Point point395 = point1;
      pictureBox181_1.Location = point395;
      this.PictureBox181.Name = "PictureBox181";
      PictureBox pictureBox181_2 = this.PictureBox181;
      size1 = new Size(3, 3);
      Size size395 = size1;
      pictureBox181_2.Size = size395;
      this.PictureBox181.TabIndex = 1540;
      this.PictureBox181.TabStop = false;
      this.PictureBox182.BackColor = Color.White;
      this.PictureBox182.Cursor = Cursors.Help;
      PictureBox pictureBox182_1 = this.PictureBox182;
      point1 = new Point(460, 578);
      Point point396 = point1;
      pictureBox182_1.Location = point396;
      this.PictureBox182.Name = "PictureBox182";
      PictureBox pictureBox182_2 = this.PictureBox182;
      size1 = new Size(3, 3);
      Size size396 = size1;
      pictureBox182_2.Size = size396;
      this.PictureBox182.TabIndex = 1539;
      this.PictureBox182.TabStop = false;
      this.PictureBox183.BackColor = Color.White;
      this.PictureBox183.Cursor = Cursors.Help;
      PictureBox pictureBox183_1 = this.PictureBox183;
      point1 = new Point(460, 578);
      Point point397 = point1;
      pictureBox183_1.Location = point397;
      this.PictureBox183.Name = "PictureBox183";
      PictureBox pictureBox183_2 = this.PictureBox183;
      size1 = new Size(3, 3);
      Size size397 = size1;
      pictureBox183_2.Size = size397;
      this.PictureBox183.TabIndex = 1538;
      this.PictureBox183.TabStop = false;
      this.PictureBox184.BackColor = Color.White;
      this.PictureBox184.Cursor = Cursors.Help;
      PictureBox pictureBox184_1 = this.PictureBox184;
      point1 = new Point(460, 578);
      Point point398 = point1;
      pictureBox184_1.Location = point398;
      this.PictureBox184.Name = "PictureBox184";
      PictureBox pictureBox184_2 = this.PictureBox184;
      size1 = new Size(3, 3);
      Size size398 = size1;
      pictureBox184_2.Size = size398;
      this.PictureBox184.TabIndex = 1537;
      this.PictureBox184.TabStop = false;
      this.PictureBox185.BackColor = Color.White;
      this.PictureBox185.Cursor = Cursors.Help;
      PictureBox pictureBox185_1 = this.PictureBox185;
      point1 = new Point(460, 578);
      Point point399 = point1;
      pictureBox185_1.Location = point399;
      this.PictureBox185.Name = "PictureBox185";
      PictureBox pictureBox185_2 = this.PictureBox185;
      size1 = new Size(3, 3);
      Size size399 = size1;
      pictureBox185_2.Size = size399;
      this.PictureBox185.TabIndex = 1536;
      this.PictureBox185.TabStop = false;
      this.PictureBox186.BackColor = Color.White;
      this.PictureBox186.Cursor = Cursors.Help;
      PictureBox pictureBox186_1 = this.PictureBox186;
      point1 = new Point(460, 578);
      Point point400 = point1;
      pictureBox186_1.Location = point400;
      this.PictureBox186.Name = "PictureBox186";
      PictureBox pictureBox186_2 = this.PictureBox186;
      size1 = new Size(3, 3);
      Size size400 = size1;
      pictureBox186_2.Size = size400;
      this.PictureBox186.TabIndex = 1535;
      this.PictureBox186.TabStop = false;
      this.PictureBox187.BackColor = Color.White;
      this.PictureBox187.Cursor = Cursors.Help;
      PictureBox pictureBox187_1 = this.PictureBox187;
      point1 = new Point(460, 578);
      Point point401 = point1;
      pictureBox187_1.Location = point401;
      this.PictureBox187.Name = "PictureBox187";
      PictureBox pictureBox187_2 = this.PictureBox187;
      size1 = new Size(3, 3);
      Size size401 = size1;
      pictureBox187_2.Size = size401;
      this.PictureBox187.TabIndex = 1534;
      this.PictureBox187.TabStop = false;
      this.PictureBox188.BackColor = Color.White;
      this.PictureBox188.Cursor = Cursors.Help;
      PictureBox pictureBox188_1 = this.PictureBox188;
      point1 = new Point(460, 578);
      Point point402 = point1;
      pictureBox188_1.Location = point402;
      this.PictureBox188.Name = "PictureBox188";
      PictureBox pictureBox188_2 = this.PictureBox188;
      size1 = new Size(3, 3);
      Size size402 = size1;
      pictureBox188_2.Size = size402;
      this.PictureBox188.TabIndex = 1533;
      this.PictureBox188.TabStop = false;
      this.PictureBox189.BackColor = Color.White;
      this.PictureBox189.Cursor = Cursors.Help;
      PictureBox pictureBox189_1 = this.PictureBox189;
      point1 = new Point(460, 578);
      Point point403 = point1;
      pictureBox189_1.Location = point403;
      this.PictureBox189.Name = "PictureBox189";
      PictureBox pictureBox189_2 = this.PictureBox189;
      size1 = new Size(3, 3);
      Size size403 = size1;
      pictureBox189_2.Size = size403;
      this.PictureBox189.TabIndex = 1532;
      this.PictureBox189.TabStop = false;
      this.PictureBox190.BackColor = Color.White;
      this.PictureBox190.Cursor = Cursors.Help;
      PictureBox pictureBox190_1 = this.PictureBox190;
      point1 = new Point(460, 578);
      Point point404 = point1;
      pictureBox190_1.Location = point404;
      this.PictureBox190.Name = "PictureBox190";
      PictureBox pictureBox190_2 = this.PictureBox190;
      size1 = new Size(3, 3);
      Size size404 = size1;
      pictureBox190_2.Size = size404;
      this.PictureBox190.TabIndex = 1531;
      this.PictureBox190.TabStop = false;
      this.PictureBox191.BackColor = Color.White;
      this.PictureBox191.Cursor = Cursors.Help;
      PictureBox pictureBox191_1 = this.PictureBox191;
      point1 = new Point(460, 578);
      Point point405 = point1;
      pictureBox191_1.Location = point405;
      this.PictureBox191.Name = "PictureBox191";
      PictureBox pictureBox191_2 = this.PictureBox191;
      size1 = new Size(3, 3);
      Size size405 = size1;
      pictureBox191_2.Size = size405;
      this.PictureBox191.TabIndex = 1530;
      this.PictureBox191.TabStop = false;
      this.PictureBox192.BackColor = Color.White;
      this.PictureBox192.Cursor = Cursors.Help;
      PictureBox pictureBox192_1 = this.PictureBox192;
      point1 = new Point(460, 578);
      Point point406 = point1;
      pictureBox192_1.Location = point406;
      this.PictureBox192.Name = "PictureBox192";
      PictureBox pictureBox192_2 = this.PictureBox192;
      size1 = new Size(3, 3);
      Size size406 = size1;
      pictureBox192_2.Size = size406;
      this.PictureBox192.TabIndex = 1529;
      this.PictureBox192.TabStop = false;
      this.PictureBox193.BackColor = Color.White;
      this.PictureBox193.Cursor = Cursors.Help;
      PictureBox pictureBox193_1 = this.PictureBox193;
      point1 = new Point(460, 578);
      Point point407 = point1;
      pictureBox193_1.Location = point407;
      this.PictureBox193.Name = "PictureBox193";
      PictureBox pictureBox193_2 = this.PictureBox193;
      size1 = new Size(3, 3);
      Size size407 = size1;
      pictureBox193_2.Size = size407;
      this.PictureBox193.TabIndex = 1528;
      this.PictureBox193.TabStop = false;
      this.PictureBox194.BackColor = Color.White;
      this.PictureBox194.Cursor = Cursors.Help;
      PictureBox pictureBox194_1 = this.PictureBox194;
      point1 = new Point(460, 578);
      Point point408 = point1;
      pictureBox194_1.Location = point408;
      this.PictureBox194.Name = "PictureBox194";
      PictureBox pictureBox194_2 = this.PictureBox194;
      size1 = new Size(3, 3);
      Size size408 = size1;
      pictureBox194_2.Size = size408;
      this.PictureBox194.TabIndex = 1527;
      this.PictureBox194.TabStop = false;
      this.PictureBox195.BackColor = Color.White;
      this.PictureBox195.Cursor = Cursors.Help;
      PictureBox pictureBox195_1 = this.PictureBox195;
      point1 = new Point(460, 578);
      Point point409 = point1;
      pictureBox195_1.Location = point409;
      this.PictureBox195.Name = "PictureBox195";
      PictureBox pictureBox195_2 = this.PictureBox195;
      size1 = new Size(3, 3);
      Size size409 = size1;
      pictureBox195_2.Size = size409;
      this.PictureBox195.TabIndex = 1526;
      this.PictureBox195.TabStop = false;
      this.PictureBox196.BackColor = Color.White;
      this.PictureBox196.Cursor = Cursors.Help;
      PictureBox pictureBox196_1 = this.PictureBox196;
      point1 = new Point(460, 578);
      Point point410 = point1;
      pictureBox196_1.Location = point410;
      this.PictureBox196.Name = "PictureBox196";
      PictureBox pictureBox196_2 = this.PictureBox196;
      size1 = new Size(3, 3);
      Size size410 = size1;
      pictureBox196_2.Size = size410;
      this.PictureBox196.TabIndex = 1525;
      this.PictureBox196.TabStop = false;
      this.PictureBox197.BackColor = Color.White;
      this.PictureBox197.Cursor = Cursors.Help;
      PictureBox pictureBox197_1 = this.PictureBox197;
      point1 = new Point(460, 578);
      Point point411 = point1;
      pictureBox197_1.Location = point411;
      this.PictureBox197.Name = "PictureBox197";
      PictureBox pictureBox197_2 = this.PictureBox197;
      size1 = new Size(3, 3);
      Size size411 = size1;
      pictureBox197_2.Size = size411;
      this.PictureBox197.TabIndex = 1524;
      this.PictureBox197.TabStop = false;
      this.PictureBox198.BackColor = Color.White;
      this.PictureBox198.Cursor = Cursors.Help;
      PictureBox pictureBox198_1 = this.PictureBox198;
      point1 = new Point(460, 578);
      Point point412 = point1;
      pictureBox198_1.Location = point412;
      this.PictureBox198.Name = "PictureBox198";
      PictureBox pictureBox198_2 = this.PictureBox198;
      size1 = new Size(3, 3);
      Size size412 = size1;
      pictureBox198_2.Size = size412;
      this.PictureBox198.TabIndex = 1523;
      this.PictureBox198.TabStop = false;
      this.PictureBox199.BackColor = Color.White;
      this.PictureBox199.Cursor = Cursors.Help;
      PictureBox pictureBox199_1 = this.PictureBox199;
      point1 = new Point(460, 578);
      Point point413 = point1;
      pictureBox199_1.Location = point413;
      this.PictureBox199.Name = "PictureBox199";
      PictureBox pictureBox199_2 = this.PictureBox199;
      size1 = new Size(3, 3);
      Size size413 = size1;
      pictureBox199_2.Size = size413;
      this.PictureBox199.TabIndex = 1522;
      this.PictureBox199.TabStop = false;
      this.PictureBox200.BackColor = Color.White;
      this.PictureBox200.Cursor = Cursors.Help;
      PictureBox pictureBox200_1 = this.PictureBox200;
      point1 = new Point(460, 578);
      Point point414 = point1;
      pictureBox200_1.Location = point414;
      this.PictureBox200.Name = "PictureBox200";
      PictureBox pictureBox200_2 = this.PictureBox200;
      size1 = new Size(3, 3);
      Size size414 = size1;
      pictureBox200_2.Size = size414;
      this.PictureBox200.TabIndex = 1521;
      this.PictureBox200.TabStop = false;
      this.PictureBox201.BackColor = Color.White;
      this.PictureBox201.Cursor = Cursors.Help;
      PictureBox pictureBox201_1 = this.PictureBox201;
      point1 = new Point(460, 578);
      Point point415 = point1;
      pictureBox201_1.Location = point415;
      this.PictureBox201.Name = "PictureBox201";
      PictureBox pictureBox201_2 = this.PictureBox201;
      size1 = new Size(3, 3);
      Size size415 = size1;
      pictureBox201_2.Size = size415;
      this.PictureBox201.TabIndex = 1520;
      this.PictureBox201.TabStop = false;
      this.PictureBox202.BackColor = Color.White;
      this.PictureBox202.Cursor = Cursors.Help;
      PictureBox pictureBox202_1 = this.PictureBox202;
      point1 = new Point(460, 578);
      Point point416 = point1;
      pictureBox202_1.Location = point416;
      this.PictureBox202.Name = "PictureBox202";
      PictureBox pictureBox202_2 = this.PictureBox202;
      size1 = new Size(3, 3);
      Size size416 = size1;
      pictureBox202_2.Size = size416;
      this.PictureBox202.TabIndex = 1519;
      this.PictureBox202.TabStop = false;
      this.PictureBox203.BackColor = Color.White;
      this.PictureBox203.Cursor = Cursors.Help;
      PictureBox pictureBox203_1 = this.PictureBox203;
      point1 = new Point(460, 578);
      Point point417 = point1;
      pictureBox203_1.Location = point417;
      this.PictureBox203.Name = "PictureBox203";
      PictureBox pictureBox203_2 = this.PictureBox203;
      size1 = new Size(3, 3);
      Size size417 = size1;
      pictureBox203_2.Size = size417;
      this.PictureBox203.TabIndex = 1518;
      this.PictureBox203.TabStop = false;
      this.PictureBox204.BackColor = Color.White;
      this.PictureBox204.Cursor = Cursors.Help;
      PictureBox pictureBox204_1 = this.PictureBox204;
      point1 = new Point(460, 578);
      Point point418 = point1;
      pictureBox204_1.Location = point418;
      this.PictureBox204.Name = "PictureBox204";
      PictureBox pictureBox204_2 = this.PictureBox204;
      size1 = new Size(3, 3);
      Size size418 = size1;
      pictureBox204_2.Size = size418;
      this.PictureBox204.TabIndex = 1517;
      this.PictureBox204.TabStop = false;
      this.PictureBox205.BackColor = Color.White;
      this.PictureBox205.Cursor = Cursors.Help;
      PictureBox pictureBox205_1 = this.PictureBox205;
      point1 = new Point(460, 578);
      Point point419 = point1;
      pictureBox205_1.Location = point419;
      this.PictureBox205.Name = "PictureBox205";
      PictureBox pictureBox205_2 = this.PictureBox205;
      size1 = new Size(3, 3);
      Size size419 = size1;
      pictureBox205_2.Size = size419;
      this.PictureBox205.TabIndex = 1516;
      this.PictureBox205.TabStop = false;
      this.PictureBox206.BackColor = Color.White;
      this.PictureBox206.Cursor = Cursors.Help;
      PictureBox pictureBox206_1 = this.PictureBox206;
      point1 = new Point(460, 578);
      Point point420 = point1;
      pictureBox206_1.Location = point420;
      this.PictureBox206.Name = "PictureBox206";
      PictureBox pictureBox206_2 = this.PictureBox206;
      size1 = new Size(3, 3);
      Size size420 = size1;
      pictureBox206_2.Size = size420;
      this.PictureBox206.TabIndex = 1515;
      this.PictureBox206.TabStop = false;
      this.PictureBox207.BackColor = Color.White;
      this.PictureBox207.Cursor = Cursors.Help;
      PictureBox pictureBox207_1 = this.PictureBox207;
      point1 = new Point(460, 578);
      Point point421 = point1;
      pictureBox207_1.Location = point421;
      this.PictureBox207.Name = "PictureBox207";
      PictureBox pictureBox207_2 = this.PictureBox207;
      size1 = new Size(3, 3);
      Size size421 = size1;
      pictureBox207_2.Size = size421;
      this.PictureBox207.TabIndex = 1514;
      this.PictureBox207.TabStop = false;
      this.PictureBox208.BackColor = Color.White;
      this.PictureBox208.Cursor = Cursors.Help;
      PictureBox pictureBox208_1 = this.PictureBox208;
      point1 = new Point(460, 578);
      Point point422 = point1;
      pictureBox208_1.Location = point422;
      this.PictureBox208.Name = "PictureBox208";
      PictureBox pictureBox208_2 = this.PictureBox208;
      size1 = new Size(3, 3);
      Size size422 = size1;
      pictureBox208_2.Size = size422;
      this.PictureBox208.TabIndex = 1513;
      this.PictureBox208.TabStop = false;
      this.PictureBox209.BackColor = Color.White;
      this.PictureBox209.Cursor = Cursors.Help;
      PictureBox pictureBox209_1 = this.PictureBox209;
      point1 = new Point(460, 578);
      Point point423 = point1;
      pictureBox209_1.Location = point423;
      this.PictureBox209.Name = "PictureBox209";
      PictureBox pictureBox209_2 = this.PictureBox209;
      size1 = new Size(3, 3);
      Size size423 = size1;
      pictureBox209_2.Size = size423;
      this.PictureBox209.TabIndex = 1512;
      this.PictureBox209.TabStop = false;
      this.PictureBox210.BackColor = Color.White;
      this.PictureBox210.Cursor = Cursors.Help;
      PictureBox pictureBox210_1 = this.PictureBox210;
      point1 = new Point(460, 578);
      Point point424 = point1;
      pictureBox210_1.Location = point424;
      this.PictureBox210.Name = "PictureBox210";
      PictureBox pictureBox210_2 = this.PictureBox210;
      size1 = new Size(3, 3);
      Size size424 = size1;
      pictureBox210_2.Size = size424;
      this.PictureBox210.TabIndex = 1511;
      this.PictureBox210.TabStop = false;
      this.PictureBox211.BackColor = Color.White;
      this.PictureBox211.Cursor = Cursors.Help;
      PictureBox pictureBox211_1 = this.PictureBox211;
      point1 = new Point(460, 578);
      Point point425 = point1;
      pictureBox211_1.Location = point425;
      this.PictureBox211.Name = "PictureBox211";
      PictureBox pictureBox211_2 = this.PictureBox211;
      size1 = new Size(3, 3);
      Size size425 = size1;
      pictureBox211_2.Size = size425;
      this.PictureBox211.TabIndex = 1510;
      this.PictureBox211.TabStop = false;
      this.PictureBox212.BackColor = Color.White;
      this.PictureBox212.Cursor = Cursors.Help;
      PictureBox pictureBox212_1 = this.PictureBox212;
      point1 = new Point(460, 578);
      Point point426 = point1;
      pictureBox212_1.Location = point426;
      this.PictureBox212.Name = "PictureBox212";
      PictureBox pictureBox212_2 = this.PictureBox212;
      size1 = new Size(3, 3);
      Size size426 = size1;
      pictureBox212_2.Size = size426;
      this.PictureBox212.TabIndex = 1509;
      this.PictureBox212.TabStop = false;
      this.PictureBox213.BackColor = Color.White;
      this.PictureBox213.Cursor = Cursors.Help;
      PictureBox pictureBox213_1 = this.PictureBox213;
      point1 = new Point(460, 578);
      Point point427 = point1;
      pictureBox213_1.Location = point427;
      this.PictureBox213.Name = "PictureBox213";
      PictureBox pictureBox213_2 = this.PictureBox213;
      size1 = new Size(3, 3);
      Size size427 = size1;
      pictureBox213_2.Size = size427;
      this.PictureBox213.TabIndex = 1508;
      this.PictureBox213.TabStop = false;
      this.PictureBox214.BackColor = Color.White;
      this.PictureBox214.Cursor = Cursors.Help;
      PictureBox pictureBox214_1 = this.PictureBox214;
      point1 = new Point(460, 578);
      Point point428 = point1;
      pictureBox214_1.Location = point428;
      this.PictureBox214.Name = "PictureBox214";
      PictureBox pictureBox214_2 = this.PictureBox214;
      size1 = new Size(3, 3);
      Size size428 = size1;
      pictureBox214_2.Size = size428;
      this.PictureBox214.TabIndex = 1507;
      this.PictureBox214.TabStop = false;
      this.PictureBox215.BackColor = Color.White;
      this.PictureBox215.Cursor = Cursors.Help;
      PictureBox pictureBox215_1 = this.PictureBox215;
      point1 = new Point(460, 578);
      Point point429 = point1;
      pictureBox215_1.Location = point429;
      this.PictureBox215.Name = "PictureBox215";
      PictureBox pictureBox215_2 = this.PictureBox215;
      size1 = new Size(3, 3);
      Size size429 = size1;
      pictureBox215_2.Size = size429;
      this.PictureBox215.TabIndex = 1506;
      this.PictureBox215.TabStop = false;
      this.PictureBox216.BackColor = Color.White;
      this.PictureBox216.Cursor = Cursors.Help;
      PictureBox pictureBox216_1 = this.PictureBox216;
      point1 = new Point(460, 578);
      Point point430 = point1;
      pictureBox216_1.Location = point430;
      this.PictureBox216.Name = "PictureBox216";
      PictureBox pictureBox216_2 = this.PictureBox216;
      size1 = new Size(3, 3);
      Size size430 = size1;
      pictureBox216_2.Size = size430;
      this.PictureBox216.TabIndex = 1505;
      this.PictureBox216.TabStop = false;
      this.PictureBox217.BackColor = Color.White;
      this.PictureBox217.Cursor = Cursors.Help;
      PictureBox pictureBox217_1 = this.PictureBox217;
      point1 = new Point(460, 578);
      Point point431 = point1;
      pictureBox217_1.Location = point431;
      this.PictureBox217.Name = "PictureBox217";
      PictureBox pictureBox217_2 = this.PictureBox217;
      size1 = new Size(3, 3);
      Size size431 = size1;
      pictureBox217_2.Size = size431;
      this.PictureBox217.TabIndex = 1504;
      this.PictureBox217.TabStop = false;
      this.PictureBox218.BackColor = Color.White;
      this.PictureBox218.Cursor = Cursors.Help;
      PictureBox pictureBox218_1 = this.PictureBox218;
      point1 = new Point(460, 578);
      Point point432 = point1;
      pictureBox218_1.Location = point432;
      this.PictureBox218.Name = "PictureBox218";
      PictureBox pictureBox218_2 = this.PictureBox218;
      size1 = new Size(3, 3);
      Size size432 = size1;
      pictureBox218_2.Size = size432;
      this.PictureBox218.TabIndex = 1503;
      this.PictureBox218.TabStop = false;
      this.PictureBox219.BackColor = Color.White;
      this.PictureBox219.Cursor = Cursors.Help;
      PictureBox pictureBox219_1 = this.PictureBox219;
      point1 = new Point(460, 578);
      Point point433 = point1;
      pictureBox219_1.Location = point433;
      this.PictureBox219.Name = "PictureBox219";
      PictureBox pictureBox219_2 = this.PictureBox219;
      size1 = new Size(3, 3);
      Size size433 = size1;
      pictureBox219_2.Size = size433;
      this.PictureBox219.TabIndex = 1502;
      this.PictureBox219.TabStop = false;
      this.PictureBox220.BackColor = Color.White;
      this.PictureBox220.Cursor = Cursors.Help;
      PictureBox pictureBox220_1 = this.PictureBox220;
      point1 = new Point(460, 578);
      Point point434 = point1;
      pictureBox220_1.Location = point434;
      this.PictureBox220.Name = "PictureBox220";
      PictureBox pictureBox220_2 = this.PictureBox220;
      size1 = new Size(3, 3);
      Size size434 = size1;
      pictureBox220_2.Size = size434;
      this.PictureBox220.TabIndex = 1501;
      this.PictureBox220.TabStop = false;
      this.PictureBox221.BackColor = Color.White;
      this.PictureBox221.Cursor = Cursors.Help;
      PictureBox pictureBox221_1 = this.PictureBox221;
      point1 = new Point(460, 578);
      Point point435 = point1;
      pictureBox221_1.Location = point435;
      this.PictureBox221.Name = "PictureBox221";
      PictureBox pictureBox221_2 = this.PictureBox221;
      size1 = new Size(3, 3);
      Size size435 = size1;
      pictureBox221_2.Size = size435;
      this.PictureBox221.TabIndex = 1500;
      this.PictureBox221.TabStop = false;
      this.PictureBox223.BackColor = Color.White;
      this.PictureBox223.Cursor = Cursors.Help;
      PictureBox pictureBox223_1 = this.PictureBox223;
      point1 = new Point(460, 578);
      Point point436 = point1;
      pictureBox223_1.Location = point436;
      this.PictureBox223.Name = "PictureBox223";
      PictureBox pictureBox223_2 = this.PictureBox223;
      size1 = new Size(3, 3);
      Size size436 = size1;
      pictureBox223_2.Size = size436;
      this.PictureBox223.TabIndex = 1498;
      this.PictureBox223.TabStop = false;
      this.PictureBox222.BackColor = Color.White;
      this.PictureBox222.Cursor = Cursors.Help;
      PictureBox pictureBox222_1 = this.PictureBox222;
      point1 = new Point(460, 578);
      Point point437 = point1;
      pictureBox222_1.Location = point437;
      this.PictureBox222.Name = "PictureBox222";
      PictureBox pictureBox222_2 = this.PictureBox222;
      size1 = new Size(3, 3);
      Size size437 = size1;
      pictureBox222_2.Size = size437;
      this.PictureBox222.TabIndex = 1499;
      this.PictureBox222.TabStop = false;
      this.PictureBox224.BackColor = Color.White;
      this.PictureBox224.Cursor = Cursors.Help;
      PictureBox pictureBox224_1 = this.PictureBox224;
      point1 = new Point(460, 578);
      Point point438 = point1;
      pictureBox224_1.Location = point438;
      this.PictureBox224.Name = "PictureBox224";
      PictureBox pictureBox224_2 = this.PictureBox224;
      size1 = new Size(3, 3);
      Size size438 = size1;
      pictureBox224_2.Size = size438;
      this.PictureBox224.TabIndex = 1497;
      this.PictureBox224.TabStop = false;
      this.PictureBox57.BackColor = Color.White;
      this.PictureBox57.Cursor = Cursors.Help;
      PictureBox pictureBox57_1 = this.PictureBox57;
      point1 = new Point(460, 578);
      Point point439 = point1;
      pictureBox57_1.Location = point439;
      this.PictureBox57.Name = "PictureBox57";
      PictureBox pictureBox57_2 = this.PictureBox57;
      size1 = new Size(3, 3);
      Size size439 = size1;
      pictureBox57_2.Size = size439;
      this.PictureBox57.TabIndex = 1496;
      this.PictureBox57.TabStop = false;
      this.PictureBox58.BackColor = Color.White;
      this.PictureBox58.Cursor = Cursors.Help;
      PictureBox pictureBox58_1 = this.PictureBox58;
      point1 = new Point(460, 578);
      Point point440 = point1;
      pictureBox58_1.Location = point440;
      this.PictureBox58.Name = "PictureBox58";
      PictureBox pictureBox58_2 = this.PictureBox58;
      size1 = new Size(3, 3);
      Size size440 = size1;
      pictureBox58_2.Size = size440;
      this.PictureBox58.TabIndex = 1495;
      this.PictureBox58.TabStop = false;
      this.PictureBox59.BackColor = Color.White;
      this.PictureBox59.Cursor = Cursors.Help;
      PictureBox pictureBox59_1 = this.PictureBox59;
      point1 = new Point(460, 578);
      Point point441 = point1;
      pictureBox59_1.Location = point441;
      this.PictureBox59.Name = "PictureBox59";
      PictureBox pictureBox59_2 = this.PictureBox59;
      size1 = new Size(3, 3);
      Size size441 = size1;
      pictureBox59_2.Size = size441;
      this.PictureBox59.TabIndex = 1494;
      this.PictureBox59.TabStop = false;
      this.PictureBox60.BackColor = Color.White;
      this.PictureBox60.Cursor = Cursors.Help;
      PictureBox pictureBox60_1 = this.PictureBox60;
      point1 = new Point(460, 578);
      Point point442 = point1;
      pictureBox60_1.Location = point442;
      this.PictureBox60.Name = "PictureBox60";
      PictureBox pictureBox60_2 = this.PictureBox60;
      size1 = new Size(3, 3);
      Size size442 = size1;
      pictureBox60_2.Size = size442;
      this.PictureBox60.TabIndex = 1493;
      this.PictureBox60.TabStop = false;
      this.PictureBox61.BackColor = Color.White;
      this.PictureBox61.Cursor = Cursors.Help;
      PictureBox pictureBox61_1 = this.PictureBox61;
      point1 = new Point(460, 578);
      Point point443 = point1;
      pictureBox61_1.Location = point443;
      this.PictureBox61.Name = "PictureBox61";
      PictureBox pictureBox61_2 = this.PictureBox61;
      size1 = new Size(3, 3);
      Size size443 = size1;
      pictureBox61_2.Size = size443;
      this.PictureBox61.TabIndex = 1492;
      this.PictureBox61.TabStop = false;
      this.PictureBox62.BackColor = Color.White;
      this.PictureBox62.Cursor = Cursors.Help;
      PictureBox pictureBox62_1 = this.PictureBox62;
      point1 = new Point(460, 578);
      Point point444 = point1;
      pictureBox62_1.Location = point444;
      this.PictureBox62.Name = "PictureBox62";
      PictureBox pictureBox62_2 = this.PictureBox62;
      size1 = new Size(3, 3);
      Size size444 = size1;
      pictureBox62_2.Size = size444;
      this.PictureBox62.TabIndex = 1491;
      this.PictureBox62.TabStop = false;
      this.PictureBox63.BackColor = Color.White;
      this.PictureBox63.Cursor = Cursors.Help;
      PictureBox pictureBox63_1 = this.PictureBox63;
      point1 = new Point(460, 578);
      Point point445 = point1;
      pictureBox63_1.Location = point445;
      this.PictureBox63.Name = "PictureBox63";
      PictureBox pictureBox63_2 = this.PictureBox63;
      size1 = new Size(3, 3);
      Size size445 = size1;
      pictureBox63_2.Size = size445;
      this.PictureBox63.TabIndex = 1490;
      this.PictureBox63.TabStop = false;
      this.PictureBox64.BackColor = Color.White;
      this.PictureBox64.Cursor = Cursors.Help;
      PictureBox pictureBox64_1 = this.PictureBox64;
      point1 = new Point(460, 578);
      Point point446 = point1;
      pictureBox64_1.Location = point446;
      this.PictureBox64.Name = "PictureBox64";
      PictureBox pictureBox64_2 = this.PictureBox64;
      size1 = new Size(3, 3);
      Size size446 = size1;
      pictureBox64_2.Size = size446;
      this.PictureBox64.TabIndex = 1489;
      this.PictureBox64.TabStop = false;
      this.PictureBox65.BackColor = Color.White;
      this.PictureBox65.Cursor = Cursors.Help;
      PictureBox pictureBox65_1 = this.PictureBox65;
      point1 = new Point(460, 578);
      Point point447 = point1;
      pictureBox65_1.Location = point447;
      this.PictureBox65.Name = "PictureBox65";
      PictureBox pictureBox65_2 = this.PictureBox65;
      size1 = new Size(3, 3);
      Size size447 = size1;
      pictureBox65_2.Size = size447;
      this.PictureBox65.TabIndex = 1488;
      this.PictureBox65.TabStop = false;
      this.PictureBox66.BackColor = Color.White;
      this.PictureBox66.Cursor = Cursors.Help;
      PictureBox pictureBox66_1 = this.PictureBox66;
      point1 = new Point(460, 578);
      Point point448 = point1;
      pictureBox66_1.Location = point448;
      this.PictureBox66.Name = "PictureBox66";
      PictureBox pictureBox66_2 = this.PictureBox66;
      size1 = new Size(3, 3);
      Size size448 = size1;
      pictureBox66_2.Size = size448;
      this.PictureBox66.TabIndex = 1487;
      this.PictureBox66.TabStop = false;
      this.PictureBox67.BackColor = Color.White;
      this.PictureBox67.Cursor = Cursors.Help;
      PictureBox pictureBox67_1 = this.PictureBox67;
      point1 = new Point(460, 578);
      Point point449 = point1;
      pictureBox67_1.Location = point449;
      this.PictureBox67.Name = "PictureBox67";
      PictureBox pictureBox67_2 = this.PictureBox67;
      size1 = new Size(3, 3);
      Size size449 = size1;
      pictureBox67_2.Size = size449;
      this.PictureBox67.TabIndex = 1486;
      this.PictureBox67.TabStop = false;
      this.PictureBox68.BackColor = Color.White;
      this.PictureBox68.Cursor = Cursors.Help;
      PictureBox pictureBox68_1 = this.PictureBox68;
      point1 = new Point(460, 578);
      Point point450 = point1;
      pictureBox68_1.Location = point450;
      this.PictureBox68.Name = "PictureBox68";
      PictureBox pictureBox68_2 = this.PictureBox68;
      size1 = new Size(3, 3);
      Size size450 = size1;
      pictureBox68_2.Size = size450;
      this.PictureBox68.TabIndex = 1485;
      this.PictureBox68.TabStop = false;
      this.PictureBox69.BackColor = Color.White;
      this.PictureBox69.Cursor = Cursors.Help;
      PictureBox pictureBox69_1 = this.PictureBox69;
      point1 = new Point(460, 578);
      Point point451 = point1;
      pictureBox69_1.Location = point451;
      this.PictureBox69.Name = "PictureBox69";
      PictureBox pictureBox69_2 = this.PictureBox69;
      size1 = new Size(3, 3);
      Size size451 = size1;
      pictureBox69_2.Size = size451;
      this.PictureBox69.TabIndex = 1484;
      this.PictureBox69.TabStop = false;
      this.PictureBox70.BackColor = Color.White;
      this.PictureBox70.Cursor = Cursors.Help;
      PictureBox pictureBox70_1 = this.PictureBox70;
      point1 = new Point(460, 578);
      Point point452 = point1;
      pictureBox70_1.Location = point452;
      this.PictureBox70.Name = "PictureBox70";
      PictureBox pictureBox70_2 = this.PictureBox70;
      size1 = new Size(3, 3);
      Size size452 = size1;
      pictureBox70_2.Size = size452;
      this.PictureBox70.TabIndex = 1483;
      this.PictureBox70.TabStop = false;
      this.PictureBox71.BackColor = Color.White;
      this.PictureBox71.Cursor = Cursors.Help;
      PictureBox pictureBox71_1 = this.PictureBox71;
      point1 = new Point(460, 578);
      Point point453 = point1;
      pictureBox71_1.Location = point453;
      this.PictureBox71.Name = "PictureBox71";
      PictureBox pictureBox71_2 = this.PictureBox71;
      size1 = new Size(3, 3);
      Size size453 = size1;
      pictureBox71_2.Size = size453;
      this.PictureBox71.TabIndex = 1482;
      this.PictureBox71.TabStop = false;
      this.PictureBox72.BackColor = Color.White;
      this.PictureBox72.Cursor = Cursors.Help;
      PictureBox pictureBox72_1 = this.PictureBox72;
      point1 = new Point(460, 578);
      Point point454 = point1;
      pictureBox72_1.Location = point454;
      this.PictureBox72.Name = "PictureBox72";
      PictureBox pictureBox72_2 = this.PictureBox72;
      size1 = new Size(3, 3);
      Size size454 = size1;
      pictureBox72_2.Size = size454;
      this.PictureBox72.TabIndex = 1481;
      this.PictureBox72.TabStop = false;
      this.PictureBox73.BackColor = Color.White;
      this.PictureBox73.Cursor = Cursors.Help;
      PictureBox pictureBox73_1 = this.PictureBox73;
      point1 = new Point(460, 578);
      Point point455 = point1;
      pictureBox73_1.Location = point455;
      this.PictureBox73.Name = "PictureBox73";
      PictureBox pictureBox73_2 = this.PictureBox73;
      size1 = new Size(3, 3);
      Size size455 = size1;
      pictureBox73_2.Size = size455;
      this.PictureBox73.TabIndex = 1480;
      this.PictureBox73.TabStop = false;
      this.PictureBox74.BackColor = Color.White;
      this.PictureBox74.Cursor = Cursors.Help;
      PictureBox pictureBox74_1 = this.PictureBox74;
      point1 = new Point(460, 578);
      Point point456 = point1;
      pictureBox74_1.Location = point456;
      this.PictureBox74.Name = "PictureBox74";
      PictureBox pictureBox74_2 = this.PictureBox74;
      size1 = new Size(3, 3);
      Size size456 = size1;
      pictureBox74_2.Size = size456;
      this.PictureBox74.TabIndex = 1479;
      this.PictureBox74.TabStop = false;
      this.PictureBox75.BackColor = Color.White;
      this.PictureBox75.Cursor = Cursors.Help;
      PictureBox pictureBox75_1 = this.PictureBox75;
      point1 = new Point(460, 578);
      Point point457 = point1;
      pictureBox75_1.Location = point457;
      this.PictureBox75.Name = "PictureBox75";
      PictureBox pictureBox75_2 = this.PictureBox75;
      size1 = new Size(3, 3);
      Size size457 = size1;
      pictureBox75_2.Size = size457;
      this.PictureBox75.TabIndex = 1478;
      this.PictureBox75.TabStop = false;
      this.PictureBox76.BackColor = Color.White;
      this.PictureBox76.Cursor = Cursors.Help;
      PictureBox pictureBox76_1 = this.PictureBox76;
      point1 = new Point(460, 578);
      Point point458 = point1;
      pictureBox76_1.Location = point458;
      this.PictureBox76.Name = "PictureBox76";
      PictureBox pictureBox76_2 = this.PictureBox76;
      size1 = new Size(3, 3);
      Size size458 = size1;
      pictureBox76_2.Size = size458;
      this.PictureBox76.TabIndex = 1477;
      this.PictureBox76.TabStop = false;
      this.PictureBox77.BackColor = Color.White;
      this.PictureBox77.Cursor = Cursors.Help;
      PictureBox pictureBox77_1 = this.PictureBox77;
      point1 = new Point(460, 578);
      Point point459 = point1;
      pictureBox77_1.Location = point459;
      this.PictureBox77.Name = "PictureBox77";
      PictureBox pictureBox77_2 = this.PictureBox77;
      size1 = new Size(3, 3);
      Size size459 = size1;
      pictureBox77_2.Size = size459;
      this.PictureBox77.TabIndex = 1476;
      this.PictureBox77.TabStop = false;
      this.PictureBox78.BackColor = Color.White;
      this.PictureBox78.Cursor = Cursors.Help;
      PictureBox pictureBox78_1 = this.PictureBox78;
      point1 = new Point(460, 578);
      Point point460 = point1;
      pictureBox78_1.Location = point460;
      this.PictureBox78.Name = "PictureBox78";
      PictureBox pictureBox78_2 = this.PictureBox78;
      size1 = new Size(3, 3);
      Size size460 = size1;
      pictureBox78_2.Size = size460;
      this.PictureBox78.TabIndex = 1475;
      this.PictureBox78.TabStop = false;
      this.PictureBox79.BackColor = Color.White;
      this.PictureBox79.Cursor = Cursors.Help;
      PictureBox pictureBox79_1 = this.PictureBox79;
      point1 = new Point(460, 578);
      Point point461 = point1;
      pictureBox79_1.Location = point461;
      this.PictureBox79.Name = "PictureBox79";
      PictureBox pictureBox79_2 = this.PictureBox79;
      size1 = new Size(3, 3);
      Size size461 = size1;
      pictureBox79_2.Size = size461;
      this.PictureBox79.TabIndex = 1474;
      this.PictureBox79.TabStop = false;
      this.PictureBox80.BackColor = Color.White;
      this.PictureBox80.Cursor = Cursors.Help;
      PictureBox pictureBox80_1 = this.PictureBox80;
      point1 = new Point(460, 578);
      Point point462 = point1;
      pictureBox80_1.Location = point462;
      this.PictureBox80.Name = "PictureBox80";
      PictureBox pictureBox80_2 = this.PictureBox80;
      size1 = new Size(3, 3);
      Size size462 = size1;
      pictureBox80_2.Size = size462;
      this.PictureBox80.TabIndex = 1473;
      this.PictureBox80.TabStop = false;
      this.PictureBox81.BackColor = Color.White;
      this.PictureBox81.Cursor = Cursors.Help;
      PictureBox pictureBox81_1 = this.PictureBox81;
      point1 = new Point(460, 578);
      Point point463 = point1;
      pictureBox81_1.Location = point463;
      this.PictureBox81.Name = "PictureBox81";
      PictureBox pictureBox81_2 = this.PictureBox81;
      size1 = new Size(3, 3);
      Size size463 = size1;
      pictureBox81_2.Size = size463;
      this.PictureBox81.TabIndex = 1472;
      this.PictureBox81.TabStop = false;
      this.PictureBox82.BackColor = Color.White;
      this.PictureBox82.Cursor = Cursors.Help;
      PictureBox pictureBox82_1 = this.PictureBox82;
      point1 = new Point(460, 578);
      Point point464 = point1;
      pictureBox82_1.Location = point464;
      this.PictureBox82.Name = "PictureBox82";
      PictureBox pictureBox82_2 = this.PictureBox82;
      size1 = new Size(3, 3);
      Size size464 = size1;
      pictureBox82_2.Size = size464;
      this.PictureBox82.TabIndex = 1471;
      this.PictureBox82.TabStop = false;
      this.PictureBox83.BackColor = Color.White;
      this.PictureBox83.Cursor = Cursors.Help;
      PictureBox pictureBox83_1 = this.PictureBox83;
      point1 = new Point(460, 578);
      Point point465 = point1;
      pictureBox83_1.Location = point465;
      this.PictureBox83.Name = "PictureBox83";
      PictureBox pictureBox83_2 = this.PictureBox83;
      size1 = new Size(3, 3);
      Size size465 = size1;
      pictureBox83_2.Size = size465;
      this.PictureBox83.TabIndex = 1470;
      this.PictureBox83.TabStop = false;
      this.PictureBox84.BackColor = Color.White;
      this.PictureBox84.Cursor = Cursors.Help;
      PictureBox pictureBox84_1 = this.PictureBox84;
      point1 = new Point(460, 578);
      Point point466 = point1;
      pictureBox84_1.Location = point466;
      this.PictureBox84.Name = "PictureBox84";
      PictureBox pictureBox84_2 = this.PictureBox84;
      size1 = new Size(3, 3);
      Size size466 = size1;
      pictureBox84_2.Size = size466;
      this.PictureBox84.TabIndex = 1469;
      this.PictureBox84.TabStop = false;
      this.PictureBox85.BackColor = Color.White;
      this.PictureBox85.Cursor = Cursors.Help;
      PictureBox pictureBox85_1 = this.PictureBox85;
      point1 = new Point(460, 578);
      Point point467 = point1;
      pictureBox85_1.Location = point467;
      this.PictureBox85.Name = "PictureBox85";
      PictureBox pictureBox85_2 = this.PictureBox85;
      size1 = new Size(3, 3);
      Size size467 = size1;
      pictureBox85_2.Size = size467;
      this.PictureBox85.TabIndex = 1468;
      this.PictureBox85.TabStop = false;
      this.PictureBox86.BackColor = Color.White;
      this.PictureBox86.Cursor = Cursors.Help;
      PictureBox pictureBox86_1 = this.PictureBox86;
      point1 = new Point(460, 578);
      Point point468 = point1;
      pictureBox86_1.Location = point468;
      this.PictureBox86.Name = "PictureBox86";
      PictureBox pictureBox86_2 = this.PictureBox86;
      size1 = new Size(3, 3);
      Size size468 = size1;
      pictureBox86_2.Size = size468;
      this.PictureBox86.TabIndex = 1467;
      this.PictureBox86.TabStop = false;
      this.PictureBox87.BackColor = Color.White;
      this.PictureBox87.Cursor = Cursors.Help;
      PictureBox pictureBox87_1 = this.PictureBox87;
      point1 = new Point(460, 578);
      Point point469 = point1;
      pictureBox87_1.Location = point469;
      this.PictureBox87.Name = "PictureBox87";
      PictureBox pictureBox87_2 = this.PictureBox87;
      size1 = new Size(3, 3);
      Size size469 = size1;
      pictureBox87_2.Size = size469;
      this.PictureBox87.TabIndex = 1466;
      this.PictureBox87.TabStop = false;
      this.PictureBox88.BackColor = Color.White;
      this.PictureBox88.Cursor = Cursors.Help;
      PictureBox pictureBox88_1 = this.PictureBox88;
      point1 = new Point(460, 578);
      Point point470 = point1;
      pictureBox88_1.Location = point470;
      this.PictureBox88.Name = "PictureBox88";
      PictureBox pictureBox88_2 = this.PictureBox88;
      size1 = new Size(3, 3);
      Size size470 = size1;
      pictureBox88_2.Size = size470;
      this.PictureBox88.TabIndex = 1465;
      this.PictureBox88.TabStop = false;
      this.PictureBox89.BackColor = Color.White;
      this.PictureBox89.Cursor = Cursors.Help;
      PictureBox pictureBox89_1 = this.PictureBox89;
      point1 = new Point(460, 578);
      Point point471 = point1;
      pictureBox89_1.Location = point471;
      this.PictureBox89.Name = "PictureBox89";
      PictureBox pictureBox89_2 = this.PictureBox89;
      size1 = new Size(3, 3);
      Size size471 = size1;
      pictureBox89_2.Size = size471;
      this.PictureBox89.TabIndex = 1464;
      this.PictureBox89.TabStop = false;
      this.PictureBox90.BackColor = Color.White;
      this.PictureBox90.Cursor = Cursors.Help;
      PictureBox pictureBox90_1 = this.PictureBox90;
      point1 = new Point(460, 578);
      Point point472 = point1;
      pictureBox90_1.Location = point472;
      this.PictureBox90.Name = "PictureBox90";
      PictureBox pictureBox90_2 = this.PictureBox90;
      size1 = new Size(3, 3);
      Size size472 = size1;
      pictureBox90_2.Size = size472;
      this.PictureBox90.TabIndex = 1463;
      this.PictureBox90.TabStop = false;
      this.PictureBox91.BackColor = Color.White;
      this.PictureBox91.Cursor = Cursors.Help;
      PictureBox pictureBox91_1 = this.PictureBox91;
      point1 = new Point(460, 578);
      Point point473 = point1;
      pictureBox91_1.Location = point473;
      this.PictureBox91.Name = "PictureBox91";
      PictureBox pictureBox91_2 = this.PictureBox91;
      size1 = new Size(3, 3);
      Size size473 = size1;
      pictureBox91_2.Size = size473;
      this.PictureBox91.TabIndex = 1462;
      this.PictureBox91.TabStop = false;
      this.PictureBox92.BackColor = Color.White;
      this.PictureBox92.Cursor = Cursors.Help;
      PictureBox pictureBox92_1 = this.PictureBox92;
      point1 = new Point(460, 578);
      Point point474 = point1;
      pictureBox92_1.Location = point474;
      this.PictureBox92.Name = "PictureBox92";
      PictureBox pictureBox92_2 = this.PictureBox92;
      size1 = new Size(3, 3);
      Size size474 = size1;
      pictureBox92_2.Size = size474;
      this.PictureBox92.TabIndex = 1461;
      this.PictureBox92.TabStop = false;
      this.PictureBox93.BackColor = Color.White;
      this.PictureBox93.Cursor = Cursors.Help;
      PictureBox pictureBox93_1 = this.PictureBox93;
      point1 = new Point(460, 578);
      Point point475 = point1;
      pictureBox93_1.Location = point475;
      this.PictureBox93.Name = "PictureBox93";
      PictureBox pictureBox93_2 = this.PictureBox93;
      size1 = new Size(3, 3);
      Size size475 = size1;
      pictureBox93_2.Size = size475;
      this.PictureBox93.TabIndex = 1460;
      this.PictureBox93.TabStop = false;
      this.PictureBox94.BackColor = Color.White;
      this.PictureBox94.Cursor = Cursors.Help;
      PictureBox pictureBox94_1 = this.PictureBox94;
      point1 = new Point(460, 578);
      Point point476 = point1;
      pictureBox94_1.Location = point476;
      this.PictureBox94.Name = "PictureBox94";
      PictureBox pictureBox94_2 = this.PictureBox94;
      size1 = new Size(3, 3);
      Size size476 = size1;
      pictureBox94_2.Size = size476;
      this.PictureBox94.TabIndex = 1459;
      this.PictureBox94.TabStop = false;
      this.PictureBox95.BackColor = Color.White;
      this.PictureBox95.Cursor = Cursors.Help;
      PictureBox pictureBox95_1 = this.PictureBox95;
      point1 = new Point(460, 578);
      Point point477 = point1;
      pictureBox95_1.Location = point477;
      this.PictureBox95.Name = "PictureBox95";
      PictureBox pictureBox95_2 = this.PictureBox95;
      size1 = new Size(3, 3);
      Size size477 = size1;
      pictureBox95_2.Size = size477;
      this.PictureBox95.TabIndex = 1458;
      this.PictureBox95.TabStop = false;
      this.PictureBox96.BackColor = Color.White;
      this.PictureBox96.Cursor = Cursors.Help;
      PictureBox pictureBox96_1 = this.PictureBox96;
      point1 = new Point(460, 578);
      Point point478 = point1;
      pictureBox96_1.Location = point478;
      this.PictureBox96.Name = "PictureBox96";
      PictureBox pictureBox96_2 = this.PictureBox96;
      size1 = new Size(3, 3);
      Size size478 = size1;
      pictureBox96_2.Size = size478;
      this.PictureBox96.TabIndex = 1457;
      this.PictureBox96.TabStop = false;
      this.PictureBox97.BackColor = Color.White;
      this.PictureBox97.Cursor = Cursors.Help;
      PictureBox pictureBox97_1 = this.PictureBox97;
      point1 = new Point(460, 578);
      Point point479 = point1;
      pictureBox97_1.Location = point479;
      this.PictureBox97.Name = "PictureBox97";
      PictureBox pictureBox97_2 = this.PictureBox97;
      size1 = new Size(3, 3);
      Size size479 = size1;
      pictureBox97_2.Size = size479;
      this.PictureBox97.TabIndex = 1456;
      this.PictureBox97.TabStop = false;
      this.PictureBox98.BackColor = Color.White;
      this.PictureBox98.Cursor = Cursors.Help;
      PictureBox pictureBox98_1 = this.PictureBox98;
      point1 = new Point(460, 578);
      Point point480 = point1;
      pictureBox98_1.Location = point480;
      this.PictureBox98.Name = "PictureBox98";
      PictureBox pictureBox98_2 = this.PictureBox98;
      size1 = new Size(3, 3);
      Size size480 = size1;
      pictureBox98_2.Size = size480;
      this.PictureBox98.TabIndex = 1455;
      this.PictureBox98.TabStop = false;
      this.PictureBox99.BackColor = Color.White;
      this.PictureBox99.Cursor = Cursors.Help;
      PictureBox pictureBox99_1 = this.PictureBox99;
      point1 = new Point(460, 578);
      Point point481 = point1;
      pictureBox99_1.Location = point481;
      this.PictureBox99.Name = "PictureBox99";
      PictureBox pictureBox99_2 = this.PictureBox99;
      size1 = new Size(3, 3);
      Size size481 = size1;
      pictureBox99_2.Size = size481;
      this.PictureBox99.TabIndex = 1454;
      this.PictureBox99.TabStop = false;
      this.PictureBox100.BackColor = Color.White;
      this.PictureBox100.Cursor = Cursors.Help;
      PictureBox pictureBox100_1 = this.PictureBox100;
      point1 = new Point(460, 578);
      Point point482 = point1;
      pictureBox100_1.Location = point482;
      this.PictureBox100.Name = "PictureBox100";
      PictureBox pictureBox100_2 = this.PictureBox100;
      size1 = new Size(3, 3);
      Size size482 = size1;
      pictureBox100_2.Size = size482;
      this.PictureBox100.TabIndex = 1453;
      this.PictureBox100.TabStop = false;
      this.PictureBox101.BackColor = Color.White;
      this.PictureBox101.Cursor = Cursors.Help;
      PictureBox pictureBox101_1 = this.PictureBox101;
      point1 = new Point(460, 578);
      Point point483 = point1;
      pictureBox101_1.Location = point483;
      this.PictureBox101.Name = "PictureBox101";
      PictureBox pictureBox101_2 = this.PictureBox101;
      size1 = new Size(3, 3);
      Size size483 = size1;
      pictureBox101_2.Size = size483;
      this.PictureBox101.TabIndex = 1452;
      this.PictureBox101.TabStop = false;
      this.PictureBox102.BackColor = Color.White;
      this.PictureBox102.Cursor = Cursors.Help;
      PictureBox pictureBox102_1 = this.PictureBox102;
      point1 = new Point(460, 578);
      Point point484 = point1;
      pictureBox102_1.Location = point484;
      this.PictureBox102.Name = "PictureBox102";
      PictureBox pictureBox102_2 = this.PictureBox102;
      size1 = new Size(3, 3);
      Size size484 = size1;
      pictureBox102_2.Size = size484;
      this.PictureBox102.TabIndex = 1451;
      this.PictureBox102.TabStop = false;
      this.PictureBox103.BackColor = Color.White;
      this.PictureBox103.Cursor = Cursors.Help;
      PictureBox pictureBox103_1 = this.PictureBox103;
      point1 = new Point(460, 578);
      Point point485 = point1;
      pictureBox103_1.Location = point485;
      this.PictureBox103.Name = "PictureBox103";
      PictureBox pictureBox103_2 = this.PictureBox103;
      size1 = new Size(3, 3);
      Size size485 = size1;
      pictureBox103_2.Size = size485;
      this.PictureBox103.TabIndex = 1450;
      this.PictureBox103.TabStop = false;
      this.PictureBox104.BackColor = Color.White;
      this.PictureBox104.Cursor = Cursors.Help;
      PictureBox pictureBox104_1 = this.PictureBox104;
      point1 = new Point(460, 578);
      Point point486 = point1;
      pictureBox104_1.Location = point486;
      this.PictureBox104.Name = "PictureBox104";
      PictureBox pictureBox104_2 = this.PictureBox104;
      size1 = new Size(3, 3);
      Size size486 = size1;
      pictureBox104_2.Size = size486;
      this.PictureBox104.TabIndex = 1449;
      this.PictureBox104.TabStop = false;
      this.PictureBox105.BackColor = Color.White;
      this.PictureBox105.Cursor = Cursors.Help;
      PictureBox pictureBox105_1 = this.PictureBox105;
      point1 = new Point(460, 578);
      Point point487 = point1;
      pictureBox105_1.Location = point487;
      this.PictureBox105.Name = "PictureBox105";
      PictureBox pictureBox105_2 = this.PictureBox105;
      size1 = new Size(3, 3);
      Size size487 = size1;
      pictureBox105_2.Size = size487;
      this.PictureBox105.TabIndex = 1448;
      this.PictureBox105.TabStop = false;
      this.PictureBox106.BackColor = Color.White;
      this.PictureBox106.Cursor = Cursors.Help;
      PictureBox pictureBox106_1 = this.PictureBox106;
      point1 = new Point(460, 578);
      Point point488 = point1;
      pictureBox106_1.Location = point488;
      this.PictureBox106.Name = "PictureBox106";
      PictureBox pictureBox106_2 = this.PictureBox106;
      size1 = new Size(3, 3);
      Size size488 = size1;
      pictureBox106_2.Size = size488;
      this.PictureBox106.TabIndex = 1447;
      this.PictureBox106.TabStop = false;
      this.PictureBox107.BackColor = Color.White;
      this.PictureBox107.Cursor = Cursors.Help;
      PictureBox pictureBox107_1 = this.PictureBox107;
      point1 = new Point(460, 578);
      Point point489 = point1;
      pictureBox107_1.Location = point489;
      this.PictureBox107.Name = "PictureBox107";
      PictureBox pictureBox107_2 = this.PictureBox107;
      size1 = new Size(3, 3);
      Size size489 = size1;
      pictureBox107_2.Size = size489;
      this.PictureBox107.TabIndex = 1446;
      this.PictureBox107.TabStop = false;
      this.PictureBox108.BackColor = Color.White;
      this.PictureBox108.Cursor = Cursors.Help;
      PictureBox pictureBox108_1 = this.PictureBox108;
      point1 = new Point(460, 578);
      Point point490 = point1;
      pictureBox108_1.Location = point490;
      this.PictureBox108.Name = "PictureBox108";
      PictureBox pictureBox108_2 = this.PictureBox108;
      size1 = new Size(3, 3);
      Size size490 = size1;
      pictureBox108_2.Size = size490;
      this.PictureBox108.TabIndex = 1445;
      this.PictureBox108.TabStop = false;
      this.PictureBox109.BackColor = Color.White;
      this.PictureBox109.Cursor = Cursors.Help;
      PictureBox pictureBox109_1 = this.PictureBox109;
      point1 = new Point(460, 578);
      Point point491 = point1;
      pictureBox109_1.Location = point491;
      this.PictureBox109.Name = "PictureBox109";
      PictureBox pictureBox109_2 = this.PictureBox109;
      size1 = new Size(3, 3);
      Size size491 = size1;
      pictureBox109_2.Size = size491;
      this.PictureBox109.TabIndex = 1444;
      this.PictureBox109.TabStop = false;
      this.PictureBox110.BackColor = Color.White;
      this.PictureBox110.Cursor = Cursors.Help;
      PictureBox pictureBox110_1 = this.PictureBox110;
      point1 = new Point(460, 578);
      Point point492 = point1;
      pictureBox110_1.Location = point492;
      this.PictureBox110.Name = "PictureBox110";
      PictureBox pictureBox110_2 = this.PictureBox110;
      size1 = new Size(3, 3);
      Size size492 = size1;
      pictureBox110_2.Size = size492;
      this.PictureBox110.TabIndex = 1443;
      this.PictureBox110.TabStop = false;
      this.PictureBox111.BackColor = Color.White;
      this.PictureBox111.Cursor = Cursors.Help;
      PictureBox pictureBox111_1 = this.PictureBox111;
      point1 = new Point(460, 578);
      Point point493 = point1;
      pictureBox111_1.Location = point493;
      this.PictureBox111.Name = "PictureBox111";
      PictureBox pictureBox111_2 = this.PictureBox111;
      size1 = new Size(3, 3);
      Size size493 = size1;
      pictureBox111_2.Size = size493;
      this.PictureBox111.TabIndex = 1442;
      this.PictureBox111.TabStop = false;
      this.PictureBox112.BackColor = Color.White;
      this.PictureBox112.Cursor = Cursors.Help;
      PictureBox pictureBox112_1 = this.PictureBox112;
      point1 = new Point(460, 578);
      Point point494 = point1;
      pictureBox112_1.Location = point494;
      this.PictureBox112.Name = "PictureBox112";
      PictureBox pictureBox112_2 = this.PictureBox112;
      size1 = new Size(3, 3);
      Size size494 = size1;
      pictureBox112_2.Size = size494;
      this.PictureBox112.TabIndex = 1441;
      this.PictureBox112.TabStop = false;
      this.PictureBox29.BackColor = Color.White;
      this.PictureBox29.Cursor = Cursors.Help;
      PictureBox pictureBox29_1 = this.PictureBox29;
      point1 = new Point(460, 578);
      Point point495 = point1;
      pictureBox29_1.Location = point495;
      this.PictureBox29.Name = "PictureBox29";
      PictureBox pictureBox29_2 = this.PictureBox29;
      size1 = new Size(3, 3);
      Size size495 = size1;
      pictureBox29_2.Size = size495;
      this.PictureBox29.TabIndex = 1440;
      this.PictureBox29.TabStop = false;
      this.PictureBox30.BackColor = Color.White;
      this.PictureBox30.Cursor = Cursors.Help;
      PictureBox pictureBox30_1 = this.PictureBox30;
      point1 = new Point(460, 578);
      Point point496 = point1;
      pictureBox30_1.Location = point496;
      this.PictureBox30.Name = "PictureBox30";
      PictureBox pictureBox30_2 = this.PictureBox30;
      size1 = new Size(3, 3);
      Size size496 = size1;
      pictureBox30_2.Size = size496;
      this.PictureBox30.TabIndex = 1439;
      this.PictureBox30.TabStop = false;
      this.PictureBox31.BackColor = Color.White;
      this.PictureBox31.Cursor = Cursors.Help;
      PictureBox pictureBox31_1 = this.PictureBox31;
      point1 = new Point(460, 578);
      Point point497 = point1;
      pictureBox31_1.Location = point497;
      this.PictureBox31.Name = "PictureBox31";
      PictureBox pictureBox31_2 = this.PictureBox31;
      size1 = new Size(3, 3);
      Size size497 = size1;
      pictureBox31_2.Size = size497;
      this.PictureBox31.TabIndex = 1438;
      this.PictureBox31.TabStop = false;
      this.PictureBox32.BackColor = Color.White;
      this.PictureBox32.Cursor = Cursors.Help;
      PictureBox pictureBox32_1 = this.PictureBox32;
      point1 = new Point(460, 578);
      Point point498 = point1;
      pictureBox32_1.Location = point498;
      this.PictureBox32.Name = "PictureBox32";
      PictureBox pictureBox32_2 = this.PictureBox32;
      size1 = new Size(3, 3);
      Size size498 = size1;
      pictureBox32_2.Size = size498;
      this.PictureBox32.TabIndex = 1437;
      this.PictureBox32.TabStop = false;
      this.PictureBox33.BackColor = Color.White;
      this.PictureBox33.Cursor = Cursors.Help;
      PictureBox pictureBox33_1 = this.PictureBox33;
      point1 = new Point(460, 578);
      Point point499 = point1;
      pictureBox33_1.Location = point499;
      this.PictureBox33.Name = "PictureBox33";
      PictureBox pictureBox33_2 = this.PictureBox33;
      size1 = new Size(3, 3);
      Size size499 = size1;
      pictureBox33_2.Size = size499;
      this.PictureBox33.TabIndex = 1436;
      this.PictureBox33.TabStop = false;
      this.PictureBox34.BackColor = Color.White;
      this.PictureBox34.Cursor = Cursors.Help;
      PictureBox pictureBox34_1 = this.PictureBox34;
      point1 = new Point(460, 578);
      Point point500 = point1;
      pictureBox34_1.Location = point500;
      this.PictureBox34.Name = "PictureBox34";
      PictureBox pictureBox34_2 = this.PictureBox34;
      size1 = new Size(3, 3);
      Size size500 = size1;
      pictureBox34_2.Size = size500;
      this.PictureBox34.TabIndex = 1435;
      this.PictureBox34.TabStop = false;
      this.PictureBox35.BackColor = Color.White;
      this.PictureBox35.Cursor = Cursors.Help;
      PictureBox pictureBox35_1 = this.PictureBox35;
      point1 = new Point(460, 578);
      Point point501 = point1;
      pictureBox35_1.Location = point501;
      this.PictureBox35.Name = "PictureBox35";
      PictureBox pictureBox35_2 = this.PictureBox35;
      size1 = new Size(3, 3);
      Size size501 = size1;
      pictureBox35_2.Size = size501;
      this.PictureBox35.TabIndex = 1434;
      this.PictureBox35.TabStop = false;
      this.PictureBox36.BackColor = Color.White;
      this.PictureBox36.Cursor = Cursors.Help;
      PictureBox pictureBox36_1 = this.PictureBox36;
      point1 = new Point(460, 578);
      Point point502 = point1;
      pictureBox36_1.Location = point502;
      this.PictureBox36.Name = "PictureBox36";
      PictureBox pictureBox36_2 = this.PictureBox36;
      size1 = new Size(3, 3);
      Size size502 = size1;
      pictureBox36_2.Size = size502;
      this.PictureBox36.TabIndex = 1433;
      this.PictureBox36.TabStop = false;
      this.PictureBox37.BackColor = Color.White;
      this.PictureBox37.Cursor = Cursors.Help;
      PictureBox pictureBox37_1 = this.PictureBox37;
      point1 = new Point(460, 578);
      Point point503 = point1;
      pictureBox37_1.Location = point503;
      this.PictureBox37.Name = "PictureBox37";
      PictureBox pictureBox37_2 = this.PictureBox37;
      size1 = new Size(3, 3);
      Size size503 = size1;
      pictureBox37_2.Size = size503;
      this.PictureBox37.TabIndex = 1432;
      this.PictureBox37.TabStop = false;
      this.PictureBox38.BackColor = Color.White;
      this.PictureBox38.Cursor = Cursors.Help;
      PictureBox pictureBox38_1 = this.PictureBox38;
      point1 = new Point(460, 578);
      Point point504 = point1;
      pictureBox38_1.Location = point504;
      this.PictureBox38.Name = "PictureBox38";
      PictureBox pictureBox38_2 = this.PictureBox38;
      size1 = new Size(3, 3);
      Size size504 = size1;
      pictureBox38_2.Size = size504;
      this.PictureBox38.TabIndex = 1431;
      this.PictureBox38.TabStop = false;
      this.PictureBox39.BackColor = Color.White;
      this.PictureBox39.Cursor = Cursors.Help;
      PictureBox pictureBox39_1 = this.PictureBox39;
      point1 = new Point(460, 578);
      Point point505 = point1;
      pictureBox39_1.Location = point505;
      this.PictureBox39.Name = "PictureBox39";
      PictureBox pictureBox39_2 = this.PictureBox39;
      size1 = new Size(3, 3);
      Size size505 = size1;
      pictureBox39_2.Size = size505;
      this.PictureBox39.TabIndex = 1430;
      this.PictureBox39.TabStop = false;
      this.PictureBox40.BackColor = Color.White;
      this.PictureBox40.Cursor = Cursors.Help;
      PictureBox pictureBox40_1 = this.PictureBox40;
      point1 = new Point(460, 578);
      Point point506 = point1;
      pictureBox40_1.Location = point506;
      this.PictureBox40.Name = "PictureBox40";
      PictureBox pictureBox40_2 = this.PictureBox40;
      size1 = new Size(3, 3);
      Size size506 = size1;
      pictureBox40_2.Size = size506;
      this.PictureBox40.TabIndex = 1429;
      this.PictureBox40.TabStop = false;
      this.PictureBox41.BackColor = Color.White;
      this.PictureBox41.Cursor = Cursors.Help;
      PictureBox pictureBox41_1 = this.PictureBox41;
      point1 = new Point(460, 578);
      Point point507 = point1;
      pictureBox41_1.Location = point507;
      this.PictureBox41.Name = "PictureBox41";
      PictureBox pictureBox41_2 = this.PictureBox41;
      size1 = new Size(3, 3);
      Size size507 = size1;
      pictureBox41_2.Size = size507;
      this.PictureBox41.TabIndex = 1428;
      this.PictureBox41.TabStop = false;
      this.PictureBox42.BackColor = Color.White;
      this.PictureBox42.Cursor = Cursors.Help;
      PictureBox pictureBox42_1 = this.PictureBox42;
      point1 = new Point(460, 578);
      Point point508 = point1;
      pictureBox42_1.Location = point508;
      this.PictureBox42.Name = "PictureBox42";
      PictureBox pictureBox42_2 = this.PictureBox42;
      size1 = new Size(3, 3);
      Size size508 = size1;
      pictureBox42_2.Size = size508;
      this.PictureBox42.TabIndex = 1427;
      this.PictureBox42.TabStop = false;
      this.PictureBox43.BackColor = Color.White;
      this.PictureBox43.Cursor = Cursors.Help;
      PictureBox pictureBox43_1 = this.PictureBox43;
      point1 = new Point(460, 578);
      Point point509 = point1;
      pictureBox43_1.Location = point509;
      this.PictureBox43.Name = "PictureBox43";
      PictureBox pictureBox43_2 = this.PictureBox43;
      size1 = new Size(3, 3);
      Size size509 = size1;
      pictureBox43_2.Size = size509;
      this.PictureBox43.TabIndex = 1426;
      this.PictureBox43.TabStop = false;
      this.PictureBox44.BackColor = Color.White;
      this.PictureBox44.Cursor = Cursors.Help;
      PictureBox pictureBox44_1 = this.PictureBox44;
      point1 = new Point(460, 578);
      Point point510 = point1;
      pictureBox44_1.Location = point510;
      this.PictureBox44.Name = "PictureBox44";
      PictureBox pictureBox44_2 = this.PictureBox44;
      size1 = new Size(3, 3);
      Size size510 = size1;
      pictureBox44_2.Size = size510;
      this.PictureBox44.TabIndex = 1425;
      this.PictureBox44.TabStop = false;
      this.PictureBox45.BackColor = Color.White;
      this.PictureBox45.Cursor = Cursors.Help;
      PictureBox pictureBox45_1 = this.PictureBox45;
      point1 = new Point(460, 578);
      Point point511 = point1;
      pictureBox45_1.Location = point511;
      this.PictureBox45.Name = "PictureBox45";
      PictureBox pictureBox45_2 = this.PictureBox45;
      size1 = new Size(3, 3);
      Size size511 = size1;
      pictureBox45_2.Size = size511;
      this.PictureBox45.TabIndex = 1424;
      this.PictureBox45.TabStop = false;
      this.PictureBox46.BackColor = Color.White;
      this.PictureBox46.Cursor = Cursors.Help;
      PictureBox pictureBox46_1 = this.PictureBox46;
      point1 = new Point(460, 578);
      Point point512 = point1;
      pictureBox46_1.Location = point512;
      this.PictureBox46.Name = "PictureBox46";
      PictureBox pictureBox46_2 = this.PictureBox46;
      size1 = new Size(3, 3);
      Size size512 = size1;
      pictureBox46_2.Size = size512;
      this.PictureBox46.TabIndex = 1423;
      this.PictureBox46.TabStop = false;
      this.PictureBox47.BackColor = Color.White;
      this.PictureBox47.Cursor = Cursors.Help;
      PictureBox pictureBox47_1 = this.PictureBox47;
      point1 = new Point(460, 578);
      Point point513 = point1;
      pictureBox47_1.Location = point513;
      this.PictureBox47.Name = "PictureBox47";
      PictureBox pictureBox47_2 = this.PictureBox47;
      size1 = new Size(3, 3);
      Size size513 = size1;
      pictureBox47_2.Size = size513;
      this.PictureBox47.TabIndex = 1422;
      this.PictureBox47.TabStop = false;
      this.PictureBox48.BackColor = Color.White;
      this.PictureBox48.Cursor = Cursors.Help;
      PictureBox pictureBox48_1 = this.PictureBox48;
      point1 = new Point(460, 578);
      Point point514 = point1;
      pictureBox48_1.Location = point514;
      this.PictureBox48.Name = "PictureBox48";
      PictureBox pictureBox48_2 = this.PictureBox48;
      size1 = new Size(3, 3);
      Size size514 = size1;
      pictureBox48_2.Size = size514;
      this.PictureBox48.TabIndex = 1421;
      this.PictureBox48.TabStop = false;
      this.PictureBox49.BackColor = Color.White;
      this.PictureBox49.Cursor = Cursors.Help;
      PictureBox pictureBox49_1 = this.PictureBox49;
      point1 = new Point(460, 578);
      Point point515 = point1;
      pictureBox49_1.Location = point515;
      this.PictureBox49.Name = "PictureBox49";
      PictureBox pictureBox49_2 = this.PictureBox49;
      size1 = new Size(3, 3);
      Size size515 = size1;
      pictureBox49_2.Size = size515;
      this.PictureBox49.TabIndex = 1420;
      this.PictureBox49.TabStop = false;
      this.PictureBox50.BackColor = Color.White;
      this.PictureBox50.Cursor = Cursors.Help;
      PictureBox pictureBox50_1 = this.PictureBox50;
      point1 = new Point(460, 578);
      Point point516 = point1;
      pictureBox50_1.Location = point516;
      this.PictureBox50.Name = "PictureBox50";
      PictureBox pictureBox50_2 = this.PictureBox50;
      size1 = new Size(3, 3);
      Size size516 = size1;
      pictureBox50_2.Size = size516;
      this.PictureBox50.TabIndex = 1419;
      this.PictureBox50.TabStop = false;
      this.PictureBox51.BackColor = Color.White;
      this.PictureBox51.Cursor = Cursors.Help;
      PictureBox pictureBox51_1 = this.PictureBox51;
      point1 = new Point(460, 578);
      Point point517 = point1;
      pictureBox51_1.Location = point517;
      this.PictureBox51.Name = "PictureBox51";
      PictureBox pictureBox51_2 = this.PictureBox51;
      size1 = new Size(3, 3);
      Size size517 = size1;
      pictureBox51_2.Size = size517;
      this.PictureBox51.TabIndex = 1418;
      this.PictureBox51.TabStop = false;
      this.PictureBox52.BackColor = Color.White;
      this.PictureBox52.Cursor = Cursors.Help;
      PictureBox pictureBox52_1 = this.PictureBox52;
      point1 = new Point(460, 578);
      Point point518 = point1;
      pictureBox52_1.Location = point518;
      this.PictureBox52.Name = "PictureBox52";
      PictureBox pictureBox52_2 = this.PictureBox52;
      size1 = new Size(3, 3);
      Size size518 = size1;
      pictureBox52_2.Size = size518;
      this.PictureBox52.TabIndex = 1417;
      this.PictureBox52.TabStop = false;
      this.PictureBox53.BackColor = Color.White;
      this.PictureBox53.Cursor = Cursors.Help;
      PictureBox pictureBox53_1 = this.PictureBox53;
      point1 = new Point(460, 578);
      Point point519 = point1;
      pictureBox53_1.Location = point519;
      this.PictureBox53.Name = "PictureBox53";
      PictureBox pictureBox53_2 = this.PictureBox53;
      size1 = new Size(3, 3);
      Size size519 = size1;
      pictureBox53_2.Size = size519;
      this.PictureBox53.TabIndex = 1416;
      this.PictureBox53.TabStop = false;
      this.PictureBox54.BackColor = Color.White;
      this.PictureBox54.Cursor = Cursors.Help;
      PictureBox pictureBox54_1 = this.PictureBox54;
      point1 = new Point(460, 578);
      Point point520 = point1;
      pictureBox54_1.Location = point520;
      this.PictureBox54.Name = "PictureBox54";
      PictureBox pictureBox54_2 = this.PictureBox54;
      size1 = new Size(3, 3);
      Size size520 = size1;
      pictureBox54_2.Size = size520;
      this.PictureBox54.TabIndex = 1415;
      this.PictureBox54.TabStop = false;
      this.PictureBox55.BackColor = Color.White;
      this.PictureBox55.Cursor = Cursors.Help;
      PictureBox pictureBox55_1 = this.PictureBox55;
      point1 = new Point(460, 578);
      Point point521 = point1;
      pictureBox55_1.Location = point521;
      this.PictureBox55.Name = "PictureBox55";
      PictureBox pictureBox55_2 = this.PictureBox55;
      size1 = new Size(3, 3);
      Size size521 = size1;
      pictureBox55_2.Size = size521;
      this.PictureBox55.TabIndex = 1414;
      this.PictureBox55.TabStop = false;
      this.PictureBox56.BackColor = Color.White;
      this.PictureBox56.Cursor = Cursors.Help;
      PictureBox pictureBox56_1 = this.PictureBox56;
      point1 = new Point(460, 578);
      Point point522 = point1;
      pictureBox56_1.Location = point522;
      this.PictureBox56.Name = "PictureBox56";
      PictureBox pictureBox56_2 = this.PictureBox56;
      size1 = new Size(3, 3);
      Size size522 = size1;
      pictureBox56_2.Size = size522;
      this.PictureBox56.TabIndex = 1413;
      this.PictureBox56.TabStop = false;
      this.PictureBox15.BackColor = Color.White;
      this.PictureBox15.Cursor = Cursors.Help;
      PictureBox pictureBox15_1 = this.PictureBox15;
      point1 = new Point(460, 578);
      Point point523 = point1;
      pictureBox15_1.Location = point523;
      this.PictureBox15.Name = "PictureBox15";
      PictureBox pictureBox15_2 = this.PictureBox15;
      size1 = new Size(3, 3);
      Size size523 = size1;
      pictureBox15_2.Size = size523;
      this.PictureBox15.TabIndex = 1412;
      this.PictureBox15.TabStop = false;
      this.PictureBox16.BackColor = Color.White;
      this.PictureBox16.Cursor = Cursors.Help;
      PictureBox pictureBox16_1 = this.PictureBox16;
      point1 = new Point(460, 578);
      Point point524 = point1;
      pictureBox16_1.Location = point524;
      this.PictureBox16.Name = "PictureBox16";
      PictureBox pictureBox16_2 = this.PictureBox16;
      size1 = new Size(3, 3);
      Size size524 = size1;
      pictureBox16_2.Size = size524;
      this.PictureBox16.TabIndex = 1411;
      this.PictureBox16.TabStop = false;
      this.PictureBox17.BackColor = Color.White;
      this.PictureBox17.Cursor = Cursors.Help;
      PictureBox pictureBox17_1 = this.PictureBox17;
      point1 = new Point(460, 578);
      Point point525 = point1;
      pictureBox17_1.Location = point525;
      this.PictureBox17.Name = "PictureBox17";
      PictureBox pictureBox17_2 = this.PictureBox17;
      size1 = new Size(3, 3);
      Size size525 = size1;
      pictureBox17_2.Size = size525;
      this.PictureBox17.TabIndex = 1410;
      this.PictureBox17.TabStop = false;
      this.PictureBox18.BackColor = Color.White;
      this.PictureBox18.Cursor = Cursors.Help;
      PictureBox pictureBox18_1 = this.PictureBox18;
      point1 = new Point(460, 578);
      Point point526 = point1;
      pictureBox18_1.Location = point526;
      this.PictureBox18.Name = "PictureBox18";
      PictureBox pictureBox18_2 = this.PictureBox18;
      size1 = new Size(3, 3);
      Size size526 = size1;
      pictureBox18_2.Size = size526;
      this.PictureBox18.TabIndex = 1409;
      this.PictureBox18.TabStop = false;
      this.PictureBox19.BackColor = Color.White;
      this.PictureBox19.Cursor = Cursors.Help;
      PictureBox pictureBox19_1 = this.PictureBox19;
      point1 = new Point(460, 578);
      Point point527 = point1;
      pictureBox19_1.Location = point527;
      this.PictureBox19.Name = "PictureBox19";
      PictureBox pictureBox19_2 = this.PictureBox19;
      size1 = new Size(3, 3);
      Size size527 = size1;
      pictureBox19_2.Size = size527;
      this.PictureBox19.TabIndex = 1408;
      this.PictureBox19.TabStop = false;
      this.PictureBox20.BackColor = Color.White;
      this.PictureBox20.Cursor = Cursors.Help;
      PictureBox pictureBox20_1 = this.PictureBox20;
      point1 = new Point(460, 578);
      Point point528 = point1;
      pictureBox20_1.Location = point528;
      this.PictureBox20.Name = "PictureBox20";
      PictureBox pictureBox20_2 = this.PictureBox20;
      size1 = new Size(3, 3);
      Size size528 = size1;
      pictureBox20_2.Size = size528;
      this.PictureBox20.TabIndex = 1407;
      this.PictureBox20.TabStop = false;
      this.PictureBox21.BackColor = Color.White;
      this.PictureBox21.Cursor = Cursors.Help;
      PictureBox pictureBox21_1 = this.PictureBox21;
      point1 = new Point(460, 578);
      Point point529 = point1;
      pictureBox21_1.Location = point529;
      this.PictureBox21.Name = "PictureBox21";
      PictureBox pictureBox21_2 = this.PictureBox21;
      size1 = new Size(3, 3);
      Size size529 = size1;
      pictureBox21_2.Size = size529;
      this.PictureBox21.TabIndex = 1406;
      this.PictureBox21.TabStop = false;
      this.PictureBox22.BackColor = Color.White;
      this.PictureBox22.Cursor = Cursors.Help;
      PictureBox pictureBox22_1 = this.PictureBox22;
      point1 = new Point(460, 578);
      Point point530 = point1;
      pictureBox22_1.Location = point530;
      this.PictureBox22.Name = "PictureBox22";
      PictureBox pictureBox22_2 = this.PictureBox22;
      size1 = new Size(3, 3);
      Size size530 = size1;
      pictureBox22_2.Size = size530;
      this.PictureBox22.TabIndex = 1405;
      this.PictureBox22.TabStop = false;
      this.PictureBox23.BackColor = Color.White;
      this.PictureBox23.Cursor = Cursors.Help;
      PictureBox pictureBox23_1 = this.PictureBox23;
      point1 = new Point(460, 578);
      Point point531 = point1;
      pictureBox23_1.Location = point531;
      this.PictureBox23.Name = "PictureBox23";
      PictureBox pictureBox23_2 = this.PictureBox23;
      size1 = new Size(3, 3);
      Size size531 = size1;
      pictureBox23_2.Size = size531;
      this.PictureBox23.TabIndex = 1404;
      this.PictureBox23.TabStop = false;
      this.PictureBox24.BackColor = Color.White;
      this.PictureBox24.Cursor = Cursors.Help;
      PictureBox pictureBox24_1 = this.PictureBox24;
      point1 = new Point(460, 578);
      Point point532 = point1;
      pictureBox24_1.Location = point532;
      this.PictureBox24.Name = "PictureBox24";
      PictureBox pictureBox24_2 = this.PictureBox24;
      size1 = new Size(3, 3);
      Size size532 = size1;
      pictureBox24_2.Size = size532;
      this.PictureBox24.TabIndex = 1403;
      this.PictureBox24.TabStop = false;
      this.PictureBox25.BackColor = Color.White;
      this.PictureBox25.Cursor = Cursors.Help;
      PictureBox pictureBox25_1 = this.PictureBox25;
      point1 = new Point(460, 578);
      Point point533 = point1;
      pictureBox25_1.Location = point533;
      this.PictureBox25.Name = "PictureBox25";
      PictureBox pictureBox25_2 = this.PictureBox25;
      size1 = new Size(3, 3);
      Size size533 = size1;
      pictureBox25_2.Size = size533;
      this.PictureBox25.TabIndex = 1402;
      this.PictureBox25.TabStop = false;
      this.PictureBox26.BackColor = Color.White;
      this.PictureBox26.Cursor = Cursors.Help;
      PictureBox pictureBox26_1 = this.PictureBox26;
      point1 = new Point(460, 578);
      Point point534 = point1;
      pictureBox26_1.Location = point534;
      this.PictureBox26.Name = "PictureBox26";
      PictureBox pictureBox26_2 = this.PictureBox26;
      size1 = new Size(3, 3);
      Size size534 = size1;
      pictureBox26_2.Size = size534;
      this.PictureBox26.TabIndex = 1401;
      this.PictureBox26.TabStop = false;
      this.PictureBox27.BackColor = Color.White;
      this.PictureBox27.Cursor = Cursors.Help;
      PictureBox pictureBox27_1 = this.PictureBox27;
      point1 = new Point(460, 578);
      Point point535 = point1;
      pictureBox27_1.Location = point535;
      this.PictureBox27.Name = "PictureBox27";
      PictureBox pictureBox27_2 = this.PictureBox27;
      size1 = new Size(3, 3);
      Size size535 = size1;
      pictureBox27_2.Size = size535;
      this.PictureBox27.TabIndex = 1400;
      this.PictureBox27.TabStop = false;
      this.PictureBox28.BackColor = Color.White;
      this.PictureBox28.Cursor = Cursors.Help;
      PictureBox pictureBox28_1 = this.PictureBox28;
      point1 = new Point(460, 578);
      Point point536 = point1;
      pictureBox28_1.Location = point536;
      this.PictureBox28.Name = "PictureBox28";
      PictureBox pictureBox28_2 = this.PictureBox28;
      size1 = new Size(3, 3);
      Size size536 = size1;
      pictureBox28_2.Size = size536;
      this.PictureBox28.TabIndex = 1399;
      this.PictureBox28.TabStop = false;
      this.PictureBox14.BackColor = Color.White;
      this.PictureBox14.Cursor = Cursors.Help;
      PictureBox pictureBox14_1 = this.PictureBox14;
      point1 = new Point(460, 578);
      Point point537 = point1;
      pictureBox14_1.Location = point537;
      this.PictureBox14.Name = "PictureBox14";
      PictureBox pictureBox14_2 = this.PictureBox14;
      size1 = new Size(3, 3);
      Size size537 = size1;
      pictureBox14_2.Size = size537;
      this.PictureBox14.TabIndex = 1398;
      this.PictureBox14.TabStop = false;
      this.PictureBox13.BackColor = Color.White;
      this.PictureBox13.Cursor = Cursors.Help;
      PictureBox pictureBox13_1 = this.PictureBox13;
      point1 = new Point(460, 578);
      Point point538 = point1;
      pictureBox13_1.Location = point538;
      this.PictureBox13.Name = "PictureBox13";
      PictureBox pictureBox13_2 = this.PictureBox13;
      size1 = new Size(3, 3);
      Size size538 = size1;
      pictureBox13_2.Size = size538;
      this.PictureBox13.TabIndex = 1397;
      this.PictureBox13.TabStop = false;
      this.PictureBox12.BackColor = Color.White;
      this.PictureBox12.Cursor = Cursors.Help;
      PictureBox pictureBox12_1 = this.PictureBox12;
      point1 = new Point(460, 578);
      Point point539 = point1;
      pictureBox12_1.Location = point539;
      this.PictureBox12.Name = "PictureBox12";
      PictureBox pictureBox12_2 = this.PictureBox12;
      size1 = new Size(3, 3);
      Size size539 = size1;
      pictureBox12_2.Size = size539;
      this.PictureBox12.TabIndex = 1396;
      this.PictureBox12.TabStop = false;
      this.PictureBox11.BackColor = Color.White;
      this.PictureBox11.Cursor = Cursors.Help;
      PictureBox pictureBox11_1 = this.PictureBox11;
      point1 = new Point(460, 578);
      Point point540 = point1;
      pictureBox11_1.Location = point540;
      this.PictureBox11.Name = "PictureBox11";
      PictureBox pictureBox11_2 = this.PictureBox11;
      size1 = new Size(3, 3);
      Size size540 = size1;
      pictureBox11_2.Size = size540;
      this.PictureBox11.TabIndex = 1395;
      this.PictureBox11.TabStop = false;
      this.PictureBox10.BackColor = Color.White;
      this.PictureBox10.Cursor = Cursors.Help;
      PictureBox pictureBox10_1 = this.PictureBox10;
      point1 = new Point(460, 578);
      Point point541 = point1;
      pictureBox10_1.Location = point541;
      this.PictureBox10.Name = "PictureBox10";
      PictureBox pictureBox10_2 = this.PictureBox10;
      size1 = new Size(3, 3);
      Size size541 = size1;
      pictureBox10_2.Size = size541;
      this.PictureBox10.TabIndex = 1394;
      this.PictureBox10.TabStop = false;
      this.PictureBox9.BackColor = Color.White;
      this.PictureBox9.Cursor = Cursors.Help;
      PictureBox pictureBox9_1 = this.PictureBox9;
      point1 = new Point(460, 578);
      Point point542 = point1;
      pictureBox9_1.Location = point542;
      this.PictureBox9.Name = "PictureBox9";
      PictureBox pictureBox9_2 = this.PictureBox9;
      size1 = new Size(3, 3);
      Size size542 = size1;
      pictureBox9_2.Size = size542;
      this.PictureBox9.TabIndex = 1393;
      this.PictureBox9.TabStop = false;
      this.PictureBox8.BackColor = Color.White;
      this.PictureBox8.Cursor = Cursors.Help;
      PictureBox pictureBox8_1 = this.PictureBox8;
      point1 = new Point(460, 578);
      Point point543 = point1;
      pictureBox8_1.Location = point543;
      this.PictureBox8.Name = "PictureBox8";
      PictureBox pictureBox8_2 = this.PictureBox8;
      size1 = new Size(3, 3);
      Size size543 = size1;
      pictureBox8_2.Size = size543;
      this.PictureBox8.TabIndex = 1392;
      this.PictureBox8.TabStop = false;
      this.PictureBox7.BackColor = Color.White;
      this.PictureBox7.Cursor = Cursors.Help;
      PictureBox pictureBox7_1 = this.PictureBox7;
      point1 = new Point(460, 578);
      Point point544 = point1;
      pictureBox7_1.Location = point544;
      this.PictureBox7.Name = "PictureBox7";
      PictureBox pictureBox7_2 = this.PictureBox7;
      size1 = new Size(3, 3);
      Size size544 = size1;
      pictureBox7_2.Size = size544;
      this.PictureBox7.TabIndex = 1391;
      this.PictureBox7.TabStop = false;
      this.PictureBox6.BackColor = Color.White;
      this.PictureBox6.Cursor = Cursors.Help;
      PictureBox pictureBox6_1 = this.PictureBox6;
      point1 = new Point(460, 578);
      Point point545 = point1;
      pictureBox6_1.Location = point545;
      this.PictureBox6.Name = "PictureBox6";
      PictureBox pictureBox6_2 = this.PictureBox6;
      size1 = new Size(3, 3);
      Size size545 = size1;
      pictureBox6_2.Size = size545;
      this.PictureBox6.TabIndex = 1390;
      this.PictureBox6.TabStop = false;
      this.PictureBox5.BackColor = Color.White;
      this.PictureBox5.Cursor = Cursors.Help;
      PictureBox pictureBox5_1 = this.PictureBox5;
      point1 = new Point(460, 578);
      Point point546 = point1;
      pictureBox5_1.Location = point546;
      this.PictureBox5.Name = "PictureBox5";
      PictureBox pictureBox5_2 = this.PictureBox5;
      size1 = new Size(3, 3);
      Size size546 = size1;
      pictureBox5_2.Size = size546;
      this.PictureBox5.TabIndex = 1389;
      this.PictureBox5.TabStop = false;
      this.PictureBox4.BackColor = Color.White;
      this.PictureBox4.Cursor = Cursors.Help;
      PictureBox pictureBox4_1 = this.PictureBox4;
      point1 = new Point(460, 578);
      Point point547 = point1;
      pictureBox4_1.Location = point547;
      this.PictureBox4.Name = "PictureBox4";
      PictureBox pictureBox4_2 = this.PictureBox4;
      size1 = new Size(3, 3);
      Size size547 = size1;
      pictureBox4_2.Size = size547;
      this.PictureBox4.TabIndex = 1388;
      this.PictureBox4.TabStop = false;
      this.PictureBox3.BackColor = Color.White;
      this.PictureBox3.Cursor = Cursors.Help;
      PictureBox pictureBox3_1 = this.PictureBox3;
      point1 = new Point(460, 578);
      Point point548 = point1;
      pictureBox3_1.Location = point548;
      this.PictureBox3.Name = "PictureBox3";
      PictureBox pictureBox3_2 = this.PictureBox3;
      size1 = new Size(3, 3);
      Size size548 = size1;
      pictureBox3_2.Size = size548;
      this.PictureBox3.TabIndex = 1387;
      this.PictureBox3.TabStop = false;
      this.PictureBox2.BackColor = Color.White;
      this.PictureBox2.Cursor = Cursors.Help;
      PictureBox pictureBox2_1 = this.PictureBox2;
      point1 = new Point(460, 578);
      Point point549 = point1;
      pictureBox2_1.Location = point549;
      this.PictureBox2.Name = "PictureBox2";
      PictureBox pictureBox2_2 = this.PictureBox2;
      size1 = new Size(3, 3);
      Size size549 = size1;
      pictureBox2_2.Size = size549;
      this.PictureBox2.TabIndex = 1386;
      this.PictureBox2.TabStop = false;
      this.PictureBox1.BackColor = Color.White;
      this.PictureBox1.Cursor = Cursors.Help;
      PictureBox pictureBox1_1 = this.PictureBox1;
      point1 = new Point(460, 578);
      Point point550 = point1;
      pictureBox1_1.Location = point550;
      this.PictureBox1.Name = "PictureBox1";
      PictureBox pictureBox1_2 = this.PictureBox1;
      size1 = new Size(3, 3);
      Size size550 = size1;
      pictureBox1_2.Size = size550;
      this.PictureBox1.TabIndex = 1385;
      this.PictureBox1.TabStop = false;
      this.PJ1.BackColor = Color.White;
      this.PJ1.Cursor = Cursors.Help;
      PictureBox pj1_1 = this.PJ1;
      point1 = new Point(508, 570);
      Point point551 = point1;
      pj1_1.Location = point551;
      this.PJ1.Name = "PJ1";
      PictureBox pj1_2 = this.PJ1;
      size1 = new Size(3, 3);
      Size size551 = size1;
      pj1_2.Size = size551;
      this.PJ1.TabIndex = 1367;
      this.PJ1.TabStop = false;
      this.FotoMapa.BackColor = Color.Gray;
      this.FotoMapa.BorderStyle = BorderStyle.Fixed3D;
      PictureBox fotoMapa1 = this.FotoMapa;
      point1 = new Point(10, 32);
      Point point552 = point1;
      fotoMapa1.Location = point552;
      this.FotoMapa.Name = "FotoMapa";
      PictureBox fotoMapa2 = this.FotoMapa;
      size1 = new Size(515, 515);
      Size size552 = size1;
      fotoMapa2.Size = size552;
      this.FotoMapa.TabIndex = 1364;
      this.FotoMapa.TabStop = false;
      this.Reloj.Enabled = true;
      this.Reloj.Interval = 10000;
      this.VerTodosPJ.Cursor = Cursors.Hand;
      this.VerTodosPJ.Font = new Font("Microsoft Sans Serif", 14.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.VerTodosPJ.ItemHeight = 24;
      this.VerTodosPJ.Items.AddRange(new object[1]
      {
        (object) ">>ALL<<"
      });
      ListBox verTodosPj1 = this.VerTodosPJ;
      point1 = new Point(690, 58);
      Point point553 = point1;
      verTodosPj1.Location = point553;
      this.VerTodosPJ.Name = "VerTodosPJ";
      ListBox verTodosPj2 = this.VerTodosPJ;
      size1 = new Size(96, 28);
      Size size553 = size1;
      verTodosPj2.Size = size553;
      this.VerTodosPJ.TabIndex = 1890;
      this.VerTodosPJ.TabStop = false;
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
      Point point554 = point1;
      minimizar1.Location = point554;
      this.Minimizar.Name = "Minimizar";
      Button minimizar2 = this.Minimizar;
      size1 = new Size(13, 13);
      Size size554 = size1;
      minimizar2.Size = size554;
      this.Minimizar.TabIndex = 1891;
      this.Minimizar.TabStop = false;
      this.Minimizar.UseVisualStyleBackColor = false;
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
      point1 = new Point(769, 6);
      Point point555 = point1;
      cerrar1.Location = point555;
      this.Cerrar.Name = "Cerrar";
      Button cerrar2 = this.Cerrar;
      size1 = new Size(13, 13);
      Size size555 = size1;
      cerrar2.Size = size555;
      this.Cerrar.TabIndex = 1892;
      this.Cerrar.TabStop = false;
      this.Cerrar.UseVisualStyleBackColor = false;
      this.Titulo.AutoSize = true;
      this.Titulo.BackColor = Color.Transparent;
      this.Titulo.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Titulo.ForeColor = Color.DarkOrange;
      Label titulo1 = this.Titulo;
      point1 = new Point(62, 6);
      Point point556 = point1;
      titulo1.Location = point556;
      this.Titulo.Name = "Titulo";
      Label titulo2 = this.Titulo;
      size1 = new Size(0, 13);
      Size size556 = size1;
      titulo2.Size = size556;
      this.Titulo.TabIndex = 1893;
      this.Titulo.TextAlign = ContentAlignment.MiddleLeft;
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
      point1 = new Point(756, 505);
      Point point557 = point1;
      buscar1.Location = point557;
      this.Buscar.Name = "Buscar";
      Button buscar2 = this.Buscar;
      size1 = new Size(32, 21);
      Size size557 = size1;
      buscar2.Size = size557;
      this.Buscar.TabIndex = 1894;
      this.Buscar.TabStop = false;
      this.Buscar.UseVisualStyleBackColor = false;
      this.Label3.BorderStyle = BorderStyle.Fixed3D;
      Label label3_1 = this.Label3;
      point1 = new Point(529, 545);
      Point point558 = point1;
      label3_1.Location = point558;
      this.Label3.Name = "Label3";
      Label label3_2 = this.Label3;
      size1 = new Size(163, 2);
      Size size558 = size1;
      label3_2.Size = size558;
      this.Label3.TabIndex = 1895;
      this.Search.BackColor = Color.Transparent;
      this.Search.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Bold, GraphicsUnit.Point, (byte) 0);
      this.Search.ForeColor = Color.DimGray;
      Label search1 = this.Search;
      point1 = new Point(697, 509);
      Point point559 = point1;
      search1.Location = point559;
      this.Search.Name = "Search";
      Label search2 = this.Search;
      size1 = new Size(55, 14);
      Size size559 = size1;
      search2.Size = size559;
      this.Search.TabIndex = 1896;
      this.Search.Text = "Buscar";
      this.Search.TextAlign = ContentAlignment.TopCenter;
      this.AutoScaleMode = AutoScaleMode.Inherit;
      this.BackColor = Color.Black;
      // ISSUE: reference to a compiler-generated method
      this.BackgroundImage = (Image) EmbeddedResources.smethod_88();
      this.CancelButton = (IButtonControl) this.Minimizar;
      size1 = new Size(790, 560);
      this.ClientSize = size1;
      this.Controls.Add((Control) this.Search);
      this.Controls.Add((Control) this.Label3);
      this.Controls.Add((Control) this.Buscar);
      this.Controls.Add((Control) this.Titulo);
      this.Controls.Add((Control) this.Cerrar);
      this.Controls.Add((Control) this.Minimizar);
      this.Controls.Add((Control) this.PJOnline);
      this.Controls.Add((Control) this.VerTodosPJ);
      this.Controls.Add((Control) this.Label2);
      this.Controls.Add((Control) this.GameMaster);
      this.Controls.Add((Control) this.Reload);
      this.Controls.Add((Control) this.PictureBox500);
      this.Controls.Add((Control) this.PictureBox499);
      this.Controls.Add((Control) this.PictureBox498);
      this.Controls.Add((Control) this.PictureBox497);
      this.Controls.Add((Control) this.PictureBox496);
      this.Controls.Add((Control) this.PictureBox495);
      this.Controls.Add((Control) this.PictureBox494);
      this.Controls.Add((Control) this.PictureBox493);
      this.Controls.Add((Control) this.PictureBox492);
      this.Controls.Add((Control) this.PictureBox491);
      this.Controls.Add((Control) this.PictureBox490);
      this.Controls.Add((Control) this.PictureBox489);
      this.Controls.Add((Control) this.PictureBox488);
      this.Controls.Add((Control) this.PictureBox487);
      this.Controls.Add((Control) this.PictureBox486);
      this.Controls.Add((Control) this.PictureBox485);
      this.Controls.Add((Control) this.PictureBox484);
      this.Controls.Add((Control) this.PictureBox483);
      this.Controls.Add((Control) this.PictureBox482);
      this.Controls.Add((Control) this.PictureBox481);
      this.Controls.Add((Control) this.PictureBox480);
      this.Controls.Add((Control) this.PictureBox479);
      this.Controls.Add((Control) this.PictureBox478);
      this.Controls.Add((Control) this.PictureBox477);
      this.Controls.Add((Control) this.PictureBox476);
      this.Controls.Add((Control) this.PictureBox475);
      this.Controls.Add((Control) this.PictureBox474);
      this.Controls.Add((Control) this.PictureBox473);
      this.Controls.Add((Control) this.PictureBox472);
      this.Controls.Add((Control) this.PictureBox471);
      this.Controls.Add((Control) this.PictureBox470);
      this.Controls.Add((Control) this.PictureBox469);
      this.Controls.Add((Control) this.PictureBox468);
      this.Controls.Add((Control) this.PictureBox467);
      this.Controls.Add((Control) this.PictureBox466);
      this.Controls.Add((Control) this.PictureBox465);
      this.Controls.Add((Control) this.PictureBox464);
      this.Controls.Add((Control) this.PictureBox463);
      this.Controls.Add((Control) this.PictureBox462);
      this.Controls.Add((Control) this.PictureBox461);
      this.Controls.Add((Control) this.PictureBox460);
      this.Controls.Add((Control) this.PictureBox459);
      this.Controls.Add((Control) this.PictureBox458);
      this.Controls.Add((Control) this.PictureBox457);
      this.Controls.Add((Control) this.PictureBox456);
      this.Controls.Add((Control) this.PictureBox455);
      this.Controls.Add((Control) this.PictureBox454);
      this.Controls.Add((Control) this.PictureBox453);
      this.Controls.Add((Control) this.PictureBox452);
      this.Controls.Add((Control) this.PictureBox451);
      this.Controls.Add((Control) this.Label23);
      this.Controls.Add((Control) this.PictureBox450);
      this.Controls.Add((Control) this.PictureBox449);
      this.Controls.Add((Control) this.PictureBox225);
      this.Controls.Add((Control) this.PictureBox226);
      this.Controls.Add((Control) this.PictureBox227);
      this.Controls.Add((Control) this.PictureBox228);
      this.Controls.Add((Control) this.PictureBox229);
      this.Controls.Add((Control) this.PictureBox230);
      this.Controls.Add((Control) this.PictureBox231);
      this.Controls.Add((Control) this.PictureBox232);
      this.Controls.Add((Control) this.PictureBox233);
      this.Controls.Add((Control) this.PictureBox234);
      this.Controls.Add((Control) this.PictureBox235);
      this.Controls.Add((Control) this.PictureBox236);
      this.Controls.Add((Control) this.PictureBox237);
      this.Controls.Add((Control) this.PictureBox238);
      this.Controls.Add((Control) this.PictureBox239);
      this.Controls.Add((Control) this.PictureBox240);
      this.Controls.Add((Control) this.PictureBox241);
      this.Controls.Add((Control) this.PictureBox242);
      this.Controls.Add((Control) this.PictureBox243);
      this.Controls.Add((Control) this.PictureBox244);
      this.Controls.Add((Control) this.PictureBox245);
      this.Controls.Add((Control) this.PictureBox246);
      this.Controls.Add((Control) this.PictureBox247);
      this.Controls.Add((Control) this.PictureBox248);
      this.Controls.Add((Control) this.PictureBox249);
      this.Controls.Add((Control) this.PictureBox250);
      this.Controls.Add((Control) this.PictureBox251);
      this.Controls.Add((Control) this.PictureBox252);
      this.Controls.Add((Control) this.PictureBox253);
      this.Controls.Add((Control) this.PictureBox254);
      this.Controls.Add((Control) this.PictureBox255);
      this.Controls.Add((Control) this.PictureBox256);
      this.Controls.Add((Control) this.PictureBox257);
      this.Controls.Add((Control) this.PictureBox258);
      this.Controls.Add((Control) this.PictureBox259);
      this.Controls.Add((Control) this.PictureBox260);
      this.Controls.Add((Control) this.PictureBox261);
      this.Controls.Add((Control) this.PictureBox262);
      this.Controls.Add((Control) this.PictureBox263);
      this.Controls.Add((Control) this.PictureBox264);
      this.Controls.Add((Control) this.PictureBox265);
      this.Controls.Add((Control) this.PictureBox266);
      this.Controls.Add((Control) this.PictureBox267);
      this.Controls.Add((Control) this.PictureBox268);
      this.Controls.Add((Control) this.PictureBox269);
      this.Controls.Add((Control) this.PictureBox270);
      this.Controls.Add((Control) this.PictureBox271);
      this.Controls.Add((Control) this.PictureBox272);
      this.Controls.Add((Control) this.PictureBox273);
      this.Controls.Add((Control) this.PictureBox274);
      this.Controls.Add((Control) this.PictureBox275);
      this.Controls.Add((Control) this.PictureBox276);
      this.Controls.Add((Control) this.PictureBox277);
      this.Controls.Add((Control) this.PictureBox278);
      this.Controls.Add((Control) this.PictureBox279);
      this.Controls.Add((Control) this.PictureBox280);
      this.Controls.Add((Control) this.PictureBox281);
      this.Controls.Add((Control) this.PictureBox282);
      this.Controls.Add((Control) this.PictureBox283);
      this.Controls.Add((Control) this.PictureBox284);
      this.Controls.Add((Control) this.PictureBox285);
      this.Controls.Add((Control) this.PictureBox286);
      this.Controls.Add((Control) this.PictureBox287);
      this.Controls.Add((Control) this.PictureBox288);
      this.Controls.Add((Control) this.PictureBox289);
      this.Controls.Add((Control) this.PictureBox290);
      this.Controls.Add((Control) this.PictureBox291);
      this.Controls.Add((Control) this.PictureBox292);
      this.Controls.Add((Control) this.PictureBox293);
      this.Controls.Add((Control) this.PictureBox294);
      this.Controls.Add((Control) this.PictureBox295);
      this.Controls.Add((Control) this.PictureBox296);
      this.Controls.Add((Control) this.PictureBox297);
      this.Controls.Add((Control) this.PictureBox298);
      this.Controls.Add((Control) this.PictureBox299);
      this.Controls.Add((Control) this.PictureBox300);
      this.Controls.Add((Control) this.PictureBox301);
      this.Controls.Add((Control) this.PictureBox302);
      this.Controls.Add((Control) this.PictureBox303);
      this.Controls.Add((Control) this.PictureBox304);
      this.Controls.Add((Control) this.PictureBox305);
      this.Controls.Add((Control) this.PictureBox306);
      this.Controls.Add((Control) this.PictureBox307);
      this.Controls.Add((Control) this.PictureBox308);
      this.Controls.Add((Control) this.PictureBox309);
      this.Controls.Add((Control) this.PictureBox310);
      this.Controls.Add((Control) this.PictureBox311);
      this.Controls.Add((Control) this.PictureBox312);
      this.Controls.Add((Control) this.PictureBox313);
      this.Controls.Add((Control) this.PictureBox314);
      this.Controls.Add((Control) this.PictureBox315);
      this.Controls.Add((Control) this.PictureBox316);
      this.Controls.Add((Control) this.PictureBox317);
      this.Controls.Add((Control) this.PictureBox318);
      this.Controls.Add((Control) this.PictureBox319);
      this.Controls.Add((Control) this.PictureBox320);
      this.Controls.Add((Control) this.PictureBox321);
      this.Controls.Add((Control) this.PictureBox322);
      this.Controls.Add((Control) this.PictureBox323);
      this.Controls.Add((Control) this.PictureBox324);
      this.Controls.Add((Control) this.PictureBox325);
      this.Controls.Add((Control) this.PictureBox326);
      this.Controls.Add((Control) this.PictureBox327);
      this.Controls.Add((Control) this.PictureBox328);
      this.Controls.Add((Control) this.PictureBox329);
      this.Controls.Add((Control) this.PictureBox330);
      this.Controls.Add((Control) this.PictureBox331);
      this.Controls.Add((Control) this.PictureBox332);
      this.Controls.Add((Control) this.PictureBox333);
      this.Controls.Add((Control) this.PictureBox334);
      this.Controls.Add((Control) this.PictureBox335);
      this.Controls.Add((Control) this.PictureBox336);
      this.Controls.Add((Control) this.PictureBox337);
      this.Controls.Add((Control) this.PictureBox338);
      this.Controls.Add((Control) this.PictureBox339);
      this.Controls.Add((Control) this.PictureBox340);
      this.Controls.Add((Control) this.PictureBox341);
      this.Controls.Add((Control) this.PictureBox342);
      this.Controls.Add((Control) this.PictureBox343);
      this.Controls.Add((Control) this.PictureBox344);
      this.Controls.Add((Control) this.PictureBox345);
      this.Controls.Add((Control) this.PictureBox346);
      this.Controls.Add((Control) this.PictureBox347);
      this.Controls.Add((Control) this.PictureBox348);
      this.Controls.Add((Control) this.PictureBox349);
      this.Controls.Add((Control) this.PictureBox350);
      this.Controls.Add((Control) this.PictureBox351);
      this.Controls.Add((Control) this.PictureBox352);
      this.Controls.Add((Control) this.PictureBox353);
      this.Controls.Add((Control) this.PictureBox354);
      this.Controls.Add((Control) this.PictureBox355);
      this.Controls.Add((Control) this.PictureBox356);
      this.Controls.Add((Control) this.PictureBox357);
      this.Controls.Add((Control) this.PictureBox358);
      this.Controls.Add((Control) this.PictureBox359);
      this.Controls.Add((Control) this.PictureBox360);
      this.Controls.Add((Control) this.PictureBox361);
      this.Controls.Add((Control) this.PictureBox362);
      this.Controls.Add((Control) this.PictureBox363);
      this.Controls.Add((Control) this.PictureBox364);
      this.Controls.Add((Control) this.PictureBox365);
      this.Controls.Add((Control) this.PictureBox366);
      this.Controls.Add((Control) this.PictureBox367);
      this.Controls.Add((Control) this.PictureBox368);
      this.Controls.Add((Control) this.PictureBox369);
      this.Controls.Add((Control) this.PictureBox370);
      this.Controls.Add((Control) this.PictureBox371);
      this.Controls.Add((Control) this.PictureBox372);
      this.Controls.Add((Control) this.PictureBox373);
      this.Controls.Add((Control) this.PictureBox374);
      this.Controls.Add((Control) this.PictureBox375);
      this.Controls.Add((Control) this.PictureBox376);
      this.Controls.Add((Control) this.PictureBox377);
      this.Controls.Add((Control) this.PictureBox378);
      this.Controls.Add((Control) this.PictureBox379);
      this.Controls.Add((Control) this.PictureBox380);
      this.Controls.Add((Control) this.PictureBox381);
      this.Controls.Add((Control) this.PictureBox382);
      this.Controls.Add((Control) this.PictureBox383);
      this.Controls.Add((Control) this.PictureBox384);
      this.Controls.Add((Control) this.PictureBox385);
      this.Controls.Add((Control) this.PictureBox386);
      this.Controls.Add((Control) this.PictureBox387);
      this.Controls.Add((Control) this.PictureBox388);
      this.Controls.Add((Control) this.PictureBox389);
      this.Controls.Add((Control) this.PictureBox390);
      this.Controls.Add((Control) this.PictureBox391);
      this.Controls.Add((Control) this.PictureBox392);
      this.Controls.Add((Control) this.PictureBox393);
      this.Controls.Add((Control) this.PictureBox394);
      this.Controls.Add((Control) this.PictureBox395);
      this.Controls.Add((Control) this.PictureBox396);
      this.Controls.Add((Control) this.PictureBox397);
      this.Controls.Add((Control) this.PictureBox398);
      this.Controls.Add((Control) this.PictureBox399);
      this.Controls.Add((Control) this.PictureBox400);
      this.Controls.Add((Control) this.PictureBox401);
      this.Controls.Add((Control) this.PictureBox402);
      this.Controls.Add((Control) this.PictureBox403);
      this.Controls.Add((Control) this.PictureBox404);
      this.Controls.Add((Control) this.PictureBox405);
      this.Controls.Add((Control) this.PictureBox406);
      this.Controls.Add((Control) this.PictureBox407);
      this.Controls.Add((Control) this.PictureBox408);
      this.Controls.Add((Control) this.PictureBox409);
      this.Controls.Add((Control) this.PictureBox410);
      this.Controls.Add((Control) this.PictureBox411);
      this.Controls.Add((Control) this.PictureBox412);
      this.Controls.Add((Control) this.PictureBox413);
      this.Controls.Add((Control) this.PictureBox414);
      this.Controls.Add((Control) this.PictureBox415);
      this.Controls.Add((Control) this.PictureBox416);
      this.Controls.Add((Control) this.PictureBox417);
      this.Controls.Add((Control) this.PictureBox418);
      this.Controls.Add((Control) this.PictureBox419);
      this.Controls.Add((Control) this.PictureBox420);
      this.Controls.Add((Control) this.PictureBox421);
      this.Controls.Add((Control) this.PictureBox422);
      this.Controls.Add((Control) this.PictureBox423);
      this.Controls.Add((Control) this.PictureBox424);
      this.Controls.Add((Control) this.PictureBox425);
      this.Controls.Add((Control) this.PictureBox426);
      this.Controls.Add((Control) this.PictureBox427);
      this.Controls.Add((Control) this.PictureBox428);
      this.Controls.Add((Control) this.PictureBox429);
      this.Controls.Add((Control) this.PictureBox430);
      this.Controls.Add((Control) this.PictureBox431);
      this.Controls.Add((Control) this.PictureBox432);
      this.Controls.Add((Control) this.PictureBox433);
      this.Controls.Add((Control) this.PictureBox434);
      this.Controls.Add((Control) this.PictureBox435);
      this.Controls.Add((Control) this.PictureBox436);
      this.Controls.Add((Control) this.PictureBox437);
      this.Controls.Add((Control) this.PictureBox438);
      this.Controls.Add((Control) this.PictureBox439);
      this.Controls.Add((Control) this.PictureBox440);
      this.Controls.Add((Control) this.PictureBox441);
      this.Controls.Add((Control) this.PictureBox442);
      this.Controls.Add((Control) this.PictureBox443);
      this.Controls.Add((Control) this.PictureBox444);
      this.Controls.Add((Control) this.PictureBox445);
      this.Controls.Add((Control) this.PictureBox446);
      this.Controls.Add((Control) this.PictureBox447);
      this.Controls.Add((Control) this.PictureBox448);
      this.Controls.Add((Control) this.PictureBox113);
      this.Controls.Add((Control) this.PictureBox114);
      this.Controls.Add((Control) this.PictureBox115);
      this.Controls.Add((Control) this.PictureBox116);
      this.Controls.Add((Control) this.PictureBox117);
      this.Controls.Add((Control) this.PictureBox118);
      this.Controls.Add((Control) this.PictureBox119);
      this.Controls.Add((Control) this.PictureBox120);
      this.Controls.Add((Control) this.PictureBox121);
      this.Controls.Add((Control) this.PictureBox122);
      this.Controls.Add((Control) this.PictureBox123);
      this.Controls.Add((Control) this.PictureBox124);
      this.Controls.Add((Control) this.PictureBox125);
      this.Controls.Add((Control) this.PictureBox126);
      this.Controls.Add((Control) this.PictureBox127);
      this.Controls.Add((Control) this.PictureBox128);
      this.Controls.Add((Control) this.PictureBox129);
      this.Controls.Add((Control) this.PictureBox130);
      this.Controls.Add((Control) this.PictureBox131);
      this.Controls.Add((Control) this.PictureBox132);
      this.Controls.Add((Control) this.PictureBox133);
      this.Controls.Add((Control) this.PictureBox134);
      this.Controls.Add((Control) this.PictureBox135);
      this.Controls.Add((Control) this.PictureBox136);
      this.Controls.Add((Control) this.PictureBox137);
      this.Controls.Add((Control) this.PictureBox138);
      this.Controls.Add((Control) this.PictureBox139);
      this.Controls.Add((Control) this.PictureBox140);
      this.Controls.Add((Control) this.PictureBox141);
      this.Controls.Add((Control) this.PictureBox142);
      this.Controls.Add((Control) this.PictureBox143);
      this.Controls.Add((Control) this.PictureBox144);
      this.Controls.Add((Control) this.PictureBox145);
      this.Controls.Add((Control) this.PictureBox146);
      this.Controls.Add((Control) this.PictureBox147);
      this.Controls.Add((Control) this.PictureBox148);
      this.Controls.Add((Control) this.PictureBox149);
      this.Controls.Add((Control) this.PictureBox150);
      this.Controls.Add((Control) this.PictureBox151);
      this.Controls.Add((Control) this.PictureBox152);
      this.Controls.Add((Control) this.PictureBox153);
      this.Controls.Add((Control) this.PictureBox154);
      this.Controls.Add((Control) this.PictureBox155);
      this.Controls.Add((Control) this.PictureBox156);
      this.Controls.Add((Control) this.PictureBox157);
      this.Controls.Add((Control) this.PictureBox158);
      this.Controls.Add((Control) this.PictureBox159);
      this.Controls.Add((Control) this.PictureBox160);
      this.Controls.Add((Control) this.PictureBox161);
      this.Controls.Add((Control) this.PictureBox162);
      this.Controls.Add((Control) this.PictureBox163);
      this.Controls.Add((Control) this.PictureBox164);
      this.Controls.Add((Control) this.PictureBox165);
      this.Controls.Add((Control) this.PictureBox166);
      this.Controls.Add((Control) this.PictureBox167);
      this.Controls.Add((Control) this.PictureBox168);
      this.Controls.Add((Control) this.PictureBox169);
      this.Controls.Add((Control) this.PictureBox170);
      this.Controls.Add((Control) this.PictureBox171);
      this.Controls.Add((Control) this.PictureBox172);
      this.Controls.Add((Control) this.PictureBox173);
      this.Controls.Add((Control) this.PictureBox174);
      this.Controls.Add((Control) this.PictureBox175);
      this.Controls.Add((Control) this.PictureBox176);
      this.Controls.Add((Control) this.PictureBox177);
      this.Controls.Add((Control) this.PictureBox178);
      this.Controls.Add((Control) this.PictureBox179);
      this.Controls.Add((Control) this.PictureBox180);
      this.Controls.Add((Control) this.PictureBox181);
      this.Controls.Add((Control) this.PictureBox182);
      this.Controls.Add((Control) this.PictureBox183);
      this.Controls.Add((Control) this.PictureBox184);
      this.Controls.Add((Control) this.PictureBox185);
      this.Controls.Add((Control) this.PictureBox186);
      this.Controls.Add((Control) this.PictureBox187);
      this.Controls.Add((Control) this.PictureBox188);
      this.Controls.Add((Control) this.PictureBox189);
      this.Controls.Add((Control) this.PictureBox190);
      this.Controls.Add((Control) this.PictureBox191);
      this.Controls.Add((Control) this.PictureBox192);
      this.Controls.Add((Control) this.PictureBox193);
      this.Controls.Add((Control) this.PictureBox194);
      this.Controls.Add((Control) this.PictureBox195);
      this.Controls.Add((Control) this.PictureBox196);
      this.Controls.Add((Control) this.PictureBox197);
      this.Controls.Add((Control) this.PictureBox198);
      this.Controls.Add((Control) this.PictureBox199);
      this.Controls.Add((Control) this.PictureBox200);
      this.Controls.Add((Control) this.PictureBox201);
      this.Controls.Add((Control) this.PictureBox202);
      this.Controls.Add((Control) this.PictureBox203);
      this.Controls.Add((Control) this.PictureBox204);
      this.Controls.Add((Control) this.PictureBox205);
      this.Controls.Add((Control) this.PictureBox206);
      this.Controls.Add((Control) this.PictureBox207);
      this.Controls.Add((Control) this.PictureBox208);
      this.Controls.Add((Control) this.PictureBox209);
      this.Controls.Add((Control) this.PictureBox210);
      this.Controls.Add((Control) this.PictureBox211);
      this.Controls.Add((Control) this.PictureBox212);
      this.Controls.Add((Control) this.PictureBox213);
      this.Controls.Add((Control) this.PictureBox214);
      this.Controls.Add((Control) this.PictureBox215);
      this.Controls.Add((Control) this.PictureBox216);
      this.Controls.Add((Control) this.PictureBox217);
      this.Controls.Add((Control) this.PictureBox218);
      this.Controls.Add((Control) this.PictureBox219);
      this.Controls.Add((Control) this.PictureBox220);
      this.Controls.Add((Control) this.PictureBox221);
      this.Controls.Add((Control) this.PictureBox223);
      this.Controls.Add((Control) this.PictureBox222);
      this.Controls.Add((Control) this.PictureBox224);
      this.Controls.Add((Control) this.PictureBox57);
      this.Controls.Add((Control) this.PictureBox58);
      this.Controls.Add((Control) this.PictureBox59);
      this.Controls.Add((Control) this.PictureBox60);
      this.Controls.Add((Control) this.PictureBox61);
      this.Controls.Add((Control) this.PictureBox62);
      this.Controls.Add((Control) this.PictureBox63);
      this.Controls.Add((Control) this.PictureBox64);
      this.Controls.Add((Control) this.PictureBox65);
      this.Controls.Add((Control) this.PictureBox66);
      this.Controls.Add((Control) this.PictureBox67);
      this.Controls.Add((Control) this.PictureBox68);
      this.Controls.Add((Control) this.PictureBox69);
      this.Controls.Add((Control) this.PictureBox70);
      this.Controls.Add((Control) this.PictureBox71);
      this.Controls.Add((Control) this.PictureBox72);
      this.Controls.Add((Control) this.PictureBox73);
      this.Controls.Add((Control) this.PictureBox74);
      this.Controls.Add((Control) this.PictureBox75);
      this.Controls.Add((Control) this.PictureBox76);
      this.Controls.Add((Control) this.PictureBox77);
      this.Controls.Add((Control) this.PictureBox78);
      this.Controls.Add((Control) this.PictureBox79);
      this.Controls.Add((Control) this.PictureBox80);
      this.Controls.Add((Control) this.PictureBox81);
      this.Controls.Add((Control) this.PictureBox82);
      this.Controls.Add((Control) this.PictureBox83);
      this.Controls.Add((Control) this.PictureBox84);
      this.Controls.Add((Control) this.PictureBox85);
      this.Controls.Add((Control) this.PictureBox86);
      this.Controls.Add((Control) this.PictureBox87);
      this.Controls.Add((Control) this.PictureBox88);
      this.Controls.Add((Control) this.PictureBox89);
      this.Controls.Add((Control) this.PictureBox90);
      this.Controls.Add((Control) this.PictureBox91);
      this.Controls.Add((Control) this.PictureBox92);
      this.Controls.Add((Control) this.PictureBox93);
      this.Controls.Add((Control) this.PictureBox94);
      this.Controls.Add((Control) this.PictureBox95);
      this.Controls.Add((Control) this.PictureBox96);
      this.Controls.Add((Control) this.PictureBox97);
      this.Controls.Add((Control) this.PictureBox98);
      this.Controls.Add((Control) this.PictureBox99);
      this.Controls.Add((Control) this.PictureBox100);
      this.Controls.Add((Control) this.PictureBox101);
      this.Controls.Add((Control) this.PictureBox102);
      this.Controls.Add((Control) this.PictureBox103);
      this.Controls.Add((Control) this.PictureBox104);
      this.Controls.Add((Control) this.PictureBox105);
      this.Controls.Add((Control) this.PictureBox106);
      this.Controls.Add((Control) this.PictureBox107);
      this.Controls.Add((Control) this.PictureBox108);
      this.Controls.Add((Control) this.PictureBox109);
      this.Controls.Add((Control) this.PictureBox110);
      this.Controls.Add((Control) this.PictureBox111);
      this.Controls.Add((Control) this.PictureBox112);
      this.Controls.Add((Control) this.PictureBox29);
      this.Controls.Add((Control) this.PictureBox30);
      this.Controls.Add((Control) this.PictureBox31);
      this.Controls.Add((Control) this.PictureBox32);
      this.Controls.Add((Control) this.PictureBox33);
      this.Controls.Add((Control) this.PictureBox34);
      this.Controls.Add((Control) this.PictureBox35);
      this.Controls.Add((Control) this.PictureBox36);
      this.Controls.Add((Control) this.PictureBox37);
      this.Controls.Add((Control) this.PictureBox38);
      this.Controls.Add((Control) this.PictureBox39);
      this.Controls.Add((Control) this.PictureBox40);
      this.Controls.Add((Control) this.PictureBox41);
      this.Controls.Add((Control) this.PictureBox42);
      this.Controls.Add((Control) this.PictureBox43);
      this.Controls.Add((Control) this.PictureBox44);
      this.Controls.Add((Control) this.PictureBox45);
      this.Controls.Add((Control) this.PictureBox46);
      this.Controls.Add((Control) this.PictureBox47);
      this.Controls.Add((Control) this.PictureBox48);
      this.Controls.Add((Control) this.PictureBox49);
      this.Controls.Add((Control) this.PictureBox50);
      this.Controls.Add((Control) this.PictureBox51);
      this.Controls.Add((Control) this.PictureBox52);
      this.Controls.Add((Control) this.PictureBox53);
      this.Controls.Add((Control) this.PictureBox54);
      this.Controls.Add((Control) this.PictureBox55);
      this.Controls.Add((Control) this.PictureBox56);
      this.Controls.Add((Control) this.PictureBox15);
      this.Controls.Add((Control) this.PictureBox16);
      this.Controls.Add((Control) this.PictureBox17);
      this.Controls.Add((Control) this.PictureBox18);
      this.Controls.Add((Control) this.PictureBox19);
      this.Controls.Add((Control) this.PictureBox20);
      this.Controls.Add((Control) this.PictureBox21);
      this.Controls.Add((Control) this.PictureBox22);
      this.Controls.Add((Control) this.PictureBox23);
      this.Controls.Add((Control) this.PictureBox24);
      this.Controls.Add((Control) this.PictureBox25);
      this.Controls.Add((Control) this.PictureBox26);
      this.Controls.Add((Control) this.PictureBox27);
      this.Controls.Add((Control) this.PictureBox28);
      this.Controls.Add((Control) this.PictureBox14);
      this.Controls.Add((Control) this.PictureBox13);
      this.Controls.Add((Control) this.PictureBox12);
      this.Controls.Add((Control) this.PictureBox11);
      this.Controls.Add((Control) this.PictureBox10);
      this.Controls.Add((Control) this.PictureBox9);
      this.Controls.Add((Control) this.PictureBox8);
      this.Controls.Add((Control) this.PictureBox7);
      this.Controls.Add((Control) this.PictureBox6);
      this.Controls.Add((Control) this.PictureBox5);
      this.Controls.Add((Control) this.PictureBox4);
      this.Controls.Add((Control) this.PictureBox3);
      this.Controls.Add((Control) this.PictureBox2);
      this.Controls.Add((Control) this.PictureBox1);
      this.Controls.Add((Control) this.Label7);
      this.Controls.Add((Control) this.PersonajeSearch);
      this.Controls.Add((Control) this.Todos);
      this.Controls.Add((Control) this.Charts);
      this.Controls.Add((Control) this.PJ1);
      this.Controls.Add((Control) this.Maps);
      this.Controls.Add((Control) this.FotoMapa);
      this.Controls.Add((Control) this.Label1);
      this.Controls.Add((Control) this.Baneados);
      this.Controls.Add((Control) this.ListaMapas);
      this.Controls.Add((Control) this.GroupBox1);
      this.Controls.Add((Control) this.GroupBox2);
      this.Controls.Add((Control) this.XXYY);
      this.Controls.Add((Control) this.Label19);
      this.ForeColor = Color.DimGray;
      this.FormBorderStyle = FormBorderStyle.None;
      this.Icon = (Icon) componentResourceManager.GetObject("$this.Icon");
      this.MaximizeBox = false;
      this.MinimizeBox = false;
      this.Name = "MoveMaker";
      this.StartPosition = FormStartPosition.CenterScreen;
      this.Text = "MoveMaker";
      this.GroupBox1.ResumeLayout(false);
      this.GroupBox1.PerformLayout();
      this.GroupBox2.ResumeLayout(false);
      this.GroupBox2.PerformLayout();
      ((ISupportInitialize) this.OnlineOFF).EndInit();
      ((ISupportInitialize) this.OnlineON).EndInit();
      this.XXYY.ResumeLayout(false);
      ((ISupportInitialize) this.PictureBox500).EndInit();
      ((ISupportInitialize) this.PictureBox499).EndInit();
      ((ISupportInitialize) this.PictureBox498).EndInit();
      ((ISupportInitialize) this.PictureBox497).EndInit();
      ((ISupportInitialize) this.PictureBox496).EndInit();
      ((ISupportInitialize) this.PictureBox495).EndInit();
      ((ISupportInitialize) this.PictureBox494).EndInit();
      ((ISupportInitialize) this.PictureBox493).EndInit();
      ((ISupportInitialize) this.PictureBox492).EndInit();
      ((ISupportInitialize) this.PictureBox491).EndInit();
      ((ISupportInitialize) this.PictureBox490).EndInit();
      ((ISupportInitialize) this.PictureBox489).EndInit();
      ((ISupportInitialize) this.PictureBox488).EndInit();
      ((ISupportInitialize) this.PictureBox487).EndInit();
      ((ISupportInitialize) this.PictureBox486).EndInit();
      ((ISupportInitialize) this.PictureBox485).EndInit();
      ((ISupportInitialize) this.PictureBox484).EndInit();
      ((ISupportInitialize) this.PictureBox483).EndInit();
      ((ISupportInitialize) this.PictureBox482).EndInit();
      ((ISupportInitialize) this.PictureBox481).EndInit();
      ((ISupportInitialize) this.PictureBox480).EndInit();
      ((ISupportInitialize) this.PictureBox479).EndInit();
      ((ISupportInitialize) this.PictureBox478).EndInit();
      ((ISupportInitialize) this.PictureBox477).EndInit();
      ((ISupportInitialize) this.PictureBox476).EndInit();
      ((ISupportInitialize) this.PictureBox475).EndInit();
      ((ISupportInitialize) this.PictureBox474).EndInit();
      ((ISupportInitialize) this.PictureBox473).EndInit();
      ((ISupportInitialize) this.PictureBox472).EndInit();
      ((ISupportInitialize) this.PictureBox471).EndInit();
      ((ISupportInitialize) this.PictureBox470).EndInit();
      ((ISupportInitialize) this.PictureBox469).EndInit();
      ((ISupportInitialize) this.PictureBox468).EndInit();
      ((ISupportInitialize) this.PictureBox467).EndInit();
      ((ISupportInitialize) this.PictureBox466).EndInit();
      ((ISupportInitialize) this.PictureBox465).EndInit();
      ((ISupportInitialize) this.PictureBox464).EndInit();
      ((ISupportInitialize) this.PictureBox463).EndInit();
      ((ISupportInitialize) this.PictureBox462).EndInit();
      ((ISupportInitialize) this.PictureBox461).EndInit();
      ((ISupportInitialize) this.PictureBox460).EndInit();
      ((ISupportInitialize) this.PictureBox459).EndInit();
      ((ISupportInitialize) this.PictureBox458).EndInit();
      ((ISupportInitialize) this.PictureBox457).EndInit();
      ((ISupportInitialize) this.PictureBox456).EndInit();
      ((ISupportInitialize) this.PictureBox455).EndInit();
      ((ISupportInitialize) this.PictureBox454).EndInit();
      ((ISupportInitialize) this.PictureBox453).EndInit();
      ((ISupportInitialize) this.PictureBox452).EndInit();
      ((ISupportInitialize) this.PictureBox451).EndInit();
      ((ISupportInitialize) this.PictureBox450).EndInit();
      ((ISupportInitialize) this.PictureBox449).EndInit();
      ((ISupportInitialize) this.PictureBox225).EndInit();
      ((ISupportInitialize) this.PictureBox226).EndInit();
      ((ISupportInitialize) this.PictureBox227).EndInit();
      ((ISupportInitialize) this.PictureBox228).EndInit();
      ((ISupportInitialize) this.PictureBox229).EndInit();
      ((ISupportInitialize) this.PictureBox230).EndInit();
      ((ISupportInitialize) this.PictureBox231).EndInit();
      ((ISupportInitialize) this.PictureBox232).EndInit();
      ((ISupportInitialize) this.PictureBox233).EndInit();
      ((ISupportInitialize) this.PictureBox234).EndInit();
      ((ISupportInitialize) this.PictureBox235).EndInit();
      ((ISupportInitialize) this.PictureBox236).EndInit();
      ((ISupportInitialize) this.PictureBox237).EndInit();
      ((ISupportInitialize) this.PictureBox238).EndInit();
      ((ISupportInitialize) this.PictureBox239).EndInit();
      ((ISupportInitialize) this.PictureBox240).EndInit();
      ((ISupportInitialize) this.PictureBox241).EndInit();
      ((ISupportInitialize) this.PictureBox242).EndInit();
      ((ISupportInitialize) this.PictureBox243).EndInit();
      ((ISupportInitialize) this.PictureBox244).EndInit();
      ((ISupportInitialize) this.PictureBox245).EndInit();
      ((ISupportInitialize) this.PictureBox246).EndInit();
      ((ISupportInitialize) this.PictureBox247).EndInit();
      ((ISupportInitialize) this.PictureBox248).EndInit();
      ((ISupportInitialize) this.PictureBox249).EndInit();
      ((ISupportInitialize) this.PictureBox250).EndInit();
      ((ISupportInitialize) this.PictureBox251).EndInit();
      ((ISupportInitialize) this.PictureBox252).EndInit();
      ((ISupportInitialize) this.PictureBox253).EndInit();
      ((ISupportInitialize) this.PictureBox254).EndInit();
      ((ISupportInitialize) this.PictureBox255).EndInit();
      ((ISupportInitialize) this.PictureBox256).EndInit();
      ((ISupportInitialize) this.PictureBox257).EndInit();
      ((ISupportInitialize) this.PictureBox258).EndInit();
      ((ISupportInitialize) this.PictureBox259).EndInit();
      ((ISupportInitialize) this.PictureBox260).EndInit();
      ((ISupportInitialize) this.PictureBox261).EndInit();
      ((ISupportInitialize) this.PictureBox262).EndInit();
      ((ISupportInitialize) this.PictureBox263).EndInit();
      ((ISupportInitialize) this.PictureBox264).EndInit();
      ((ISupportInitialize) this.PictureBox265).EndInit();
      ((ISupportInitialize) this.PictureBox266).EndInit();
      ((ISupportInitialize) this.PictureBox267).EndInit();
      ((ISupportInitialize) this.PictureBox268).EndInit();
      ((ISupportInitialize) this.PictureBox269).EndInit();
      ((ISupportInitialize) this.PictureBox270).EndInit();
      ((ISupportInitialize) this.PictureBox271).EndInit();
      ((ISupportInitialize) this.PictureBox272).EndInit();
      ((ISupportInitialize) this.PictureBox273).EndInit();
      ((ISupportInitialize) this.PictureBox274).EndInit();
      ((ISupportInitialize) this.PictureBox275).EndInit();
      ((ISupportInitialize) this.PictureBox276).EndInit();
      ((ISupportInitialize) this.PictureBox277).EndInit();
      ((ISupportInitialize) this.PictureBox278).EndInit();
      ((ISupportInitialize) this.PictureBox279).EndInit();
      ((ISupportInitialize) this.PictureBox280).EndInit();
      ((ISupportInitialize) this.PictureBox281).EndInit();
      ((ISupportInitialize) this.PictureBox282).EndInit();
      ((ISupportInitialize) this.PictureBox283).EndInit();
      ((ISupportInitialize) this.PictureBox284).EndInit();
      ((ISupportInitialize) this.PictureBox285).EndInit();
      ((ISupportInitialize) this.PictureBox286).EndInit();
      ((ISupportInitialize) this.PictureBox287).EndInit();
      ((ISupportInitialize) this.PictureBox288).EndInit();
      ((ISupportInitialize) this.PictureBox289).EndInit();
      ((ISupportInitialize) this.PictureBox290).EndInit();
      ((ISupportInitialize) this.PictureBox291).EndInit();
      ((ISupportInitialize) this.PictureBox292).EndInit();
      ((ISupportInitialize) this.PictureBox293).EndInit();
      ((ISupportInitialize) this.PictureBox294).EndInit();
      ((ISupportInitialize) this.PictureBox295).EndInit();
      ((ISupportInitialize) this.PictureBox296).EndInit();
      ((ISupportInitialize) this.PictureBox297).EndInit();
      ((ISupportInitialize) this.PictureBox298).EndInit();
      ((ISupportInitialize) this.PictureBox299).EndInit();
      ((ISupportInitialize) this.PictureBox300).EndInit();
      ((ISupportInitialize) this.PictureBox301).EndInit();
      ((ISupportInitialize) this.PictureBox302).EndInit();
      ((ISupportInitialize) this.PictureBox303).EndInit();
      ((ISupportInitialize) this.PictureBox304).EndInit();
      ((ISupportInitialize) this.PictureBox305).EndInit();
      ((ISupportInitialize) this.PictureBox306).EndInit();
      ((ISupportInitialize) this.PictureBox307).EndInit();
      ((ISupportInitialize) this.PictureBox308).EndInit();
      ((ISupportInitialize) this.PictureBox309).EndInit();
      ((ISupportInitialize) this.PictureBox310).EndInit();
      ((ISupportInitialize) this.PictureBox311).EndInit();
      ((ISupportInitialize) this.PictureBox312).EndInit();
      ((ISupportInitialize) this.PictureBox313).EndInit();
      ((ISupportInitialize) this.PictureBox314).EndInit();
      ((ISupportInitialize) this.PictureBox315).EndInit();
      ((ISupportInitialize) this.PictureBox316).EndInit();
      ((ISupportInitialize) this.PictureBox317).EndInit();
      ((ISupportInitialize) this.PictureBox318).EndInit();
      ((ISupportInitialize) this.PictureBox319).EndInit();
      ((ISupportInitialize) this.PictureBox320).EndInit();
      ((ISupportInitialize) this.PictureBox321).EndInit();
      ((ISupportInitialize) this.PictureBox322).EndInit();
      ((ISupportInitialize) this.PictureBox323).EndInit();
      ((ISupportInitialize) this.PictureBox324).EndInit();
      ((ISupportInitialize) this.PictureBox325).EndInit();
      ((ISupportInitialize) this.PictureBox326).EndInit();
      ((ISupportInitialize) this.PictureBox327).EndInit();
      ((ISupportInitialize) this.PictureBox328).EndInit();
      ((ISupportInitialize) this.PictureBox329).EndInit();
      ((ISupportInitialize) this.PictureBox330).EndInit();
      ((ISupportInitialize) this.PictureBox331).EndInit();
      ((ISupportInitialize) this.PictureBox332).EndInit();
      ((ISupportInitialize) this.PictureBox333).EndInit();
      ((ISupportInitialize) this.PictureBox334).EndInit();
      ((ISupportInitialize) this.PictureBox335).EndInit();
      ((ISupportInitialize) this.PictureBox336).EndInit();
      ((ISupportInitialize) this.PictureBox337).EndInit();
      ((ISupportInitialize) this.PictureBox338).EndInit();
      ((ISupportInitialize) this.PictureBox339).EndInit();
      ((ISupportInitialize) this.PictureBox340).EndInit();
      ((ISupportInitialize) this.PictureBox341).EndInit();
      ((ISupportInitialize) this.PictureBox342).EndInit();
      ((ISupportInitialize) this.PictureBox343).EndInit();
      ((ISupportInitialize) this.PictureBox344).EndInit();
      ((ISupportInitialize) this.PictureBox345).EndInit();
      ((ISupportInitialize) this.PictureBox346).EndInit();
      ((ISupportInitialize) this.PictureBox347).EndInit();
      ((ISupportInitialize) this.PictureBox348).EndInit();
      ((ISupportInitialize) this.PictureBox349).EndInit();
      ((ISupportInitialize) this.PictureBox350).EndInit();
      ((ISupportInitialize) this.PictureBox351).EndInit();
      ((ISupportInitialize) this.PictureBox352).EndInit();
      ((ISupportInitialize) this.PictureBox353).EndInit();
      ((ISupportInitialize) this.PictureBox354).EndInit();
      ((ISupportInitialize) this.PictureBox355).EndInit();
      ((ISupportInitialize) this.PictureBox356).EndInit();
      ((ISupportInitialize) this.PictureBox357).EndInit();
      ((ISupportInitialize) this.PictureBox358).EndInit();
      ((ISupportInitialize) this.PictureBox359).EndInit();
      ((ISupportInitialize) this.PictureBox360).EndInit();
      ((ISupportInitialize) this.PictureBox361).EndInit();
      ((ISupportInitialize) this.PictureBox362).EndInit();
      ((ISupportInitialize) this.PictureBox363).EndInit();
      ((ISupportInitialize) this.PictureBox364).EndInit();
      ((ISupportInitialize) this.PictureBox365).EndInit();
      ((ISupportInitialize) this.PictureBox366).EndInit();
      ((ISupportInitialize) this.PictureBox367).EndInit();
      ((ISupportInitialize) this.PictureBox368).EndInit();
      ((ISupportInitialize) this.PictureBox369).EndInit();
      ((ISupportInitialize) this.PictureBox370).EndInit();
      ((ISupportInitialize) this.PictureBox371).EndInit();
      ((ISupportInitialize) this.PictureBox372).EndInit();
      ((ISupportInitialize) this.PictureBox373).EndInit();
      ((ISupportInitialize) this.PictureBox374).EndInit();
      ((ISupportInitialize) this.PictureBox375).EndInit();
      ((ISupportInitialize) this.PictureBox376).EndInit();
      ((ISupportInitialize) this.PictureBox377).EndInit();
      ((ISupportInitialize) this.PictureBox378).EndInit();
      ((ISupportInitialize) this.PictureBox379).EndInit();
      ((ISupportInitialize) this.PictureBox380).EndInit();
      ((ISupportInitialize) this.PictureBox381).EndInit();
      ((ISupportInitialize) this.PictureBox382).EndInit();
      ((ISupportInitialize) this.PictureBox383).EndInit();
      ((ISupportInitialize) this.PictureBox384).EndInit();
      ((ISupportInitialize) this.PictureBox385).EndInit();
      ((ISupportInitialize) this.PictureBox386).EndInit();
      ((ISupportInitialize) this.PictureBox387).EndInit();
      ((ISupportInitialize) this.PictureBox388).EndInit();
      ((ISupportInitialize) this.PictureBox389).EndInit();
      ((ISupportInitialize) this.PictureBox390).EndInit();
      ((ISupportInitialize) this.PictureBox391).EndInit();
      ((ISupportInitialize) this.PictureBox392).EndInit();
      ((ISupportInitialize) this.PictureBox393).EndInit();
      ((ISupportInitialize) this.PictureBox394).EndInit();
      ((ISupportInitialize) this.PictureBox395).EndInit();
      ((ISupportInitialize) this.PictureBox396).EndInit();
      ((ISupportInitialize) this.PictureBox397).EndInit();
      ((ISupportInitialize) this.PictureBox398).EndInit();
      ((ISupportInitialize) this.PictureBox399).EndInit();
      ((ISupportInitialize) this.PictureBox400).EndInit();
      ((ISupportInitialize) this.PictureBox401).EndInit();
      ((ISupportInitialize) this.PictureBox402).EndInit();
      ((ISupportInitialize) this.PictureBox403).EndInit();
      ((ISupportInitialize) this.PictureBox404).EndInit();
      ((ISupportInitialize) this.PictureBox405).EndInit();
      ((ISupportInitialize) this.PictureBox406).EndInit();
      ((ISupportInitialize) this.PictureBox407).EndInit();
      ((ISupportInitialize) this.PictureBox408).EndInit();
      ((ISupportInitialize) this.PictureBox409).EndInit();
      ((ISupportInitialize) this.PictureBox410).EndInit();
      ((ISupportInitialize) this.PictureBox411).EndInit();
      ((ISupportInitialize) this.PictureBox412).EndInit();
      ((ISupportInitialize) this.PictureBox413).EndInit();
      ((ISupportInitialize) this.PictureBox414).EndInit();
      ((ISupportInitialize) this.PictureBox415).EndInit();
      ((ISupportInitialize) this.PictureBox416).EndInit();
      ((ISupportInitialize) this.PictureBox417).EndInit();
      ((ISupportInitialize) this.PictureBox418).EndInit();
      ((ISupportInitialize) this.PictureBox419).EndInit();
      ((ISupportInitialize) this.PictureBox420).EndInit();
      ((ISupportInitialize) this.PictureBox421).EndInit();
      ((ISupportInitialize) this.PictureBox422).EndInit();
      ((ISupportInitialize) this.PictureBox423).EndInit();
      ((ISupportInitialize) this.PictureBox424).EndInit();
      ((ISupportInitialize) this.PictureBox425).EndInit();
      ((ISupportInitialize) this.PictureBox426).EndInit();
      ((ISupportInitialize) this.PictureBox427).EndInit();
      ((ISupportInitialize) this.PictureBox428).EndInit();
      ((ISupportInitialize) this.PictureBox429).EndInit();
      ((ISupportInitialize) this.PictureBox430).EndInit();
      ((ISupportInitialize) this.PictureBox431).EndInit();
      ((ISupportInitialize) this.PictureBox432).EndInit();
      ((ISupportInitialize) this.PictureBox433).EndInit();
      ((ISupportInitialize) this.PictureBox434).EndInit();
      ((ISupportInitialize) this.PictureBox435).EndInit();
      ((ISupportInitialize) this.PictureBox436).EndInit();
      ((ISupportInitialize) this.PictureBox437).EndInit();
      ((ISupportInitialize) this.PictureBox438).EndInit();
      ((ISupportInitialize) this.PictureBox439).EndInit();
      ((ISupportInitialize) this.PictureBox440).EndInit();
      ((ISupportInitialize) this.PictureBox441).EndInit();
      ((ISupportInitialize) this.PictureBox442).EndInit();
      ((ISupportInitialize) this.PictureBox443).EndInit();
      ((ISupportInitialize) this.PictureBox444).EndInit();
      ((ISupportInitialize) this.PictureBox445).EndInit();
      ((ISupportInitialize) this.PictureBox446).EndInit();
      ((ISupportInitialize) this.PictureBox447).EndInit();
      ((ISupportInitialize) this.PictureBox448).EndInit();
      ((ISupportInitialize) this.PictureBox113).EndInit();
      ((ISupportInitialize) this.PictureBox114).EndInit();
      ((ISupportInitialize) this.PictureBox115).EndInit();
      ((ISupportInitialize) this.PictureBox116).EndInit();
      ((ISupportInitialize) this.PictureBox117).EndInit();
      ((ISupportInitialize) this.PictureBox118).EndInit();
      ((ISupportInitialize) this.PictureBox119).EndInit();
      ((ISupportInitialize) this.PictureBox120).EndInit();
      ((ISupportInitialize) this.PictureBox121).EndInit();
      ((ISupportInitialize) this.PictureBox122).EndInit();
      ((ISupportInitialize) this.PictureBox123).EndInit();
      ((ISupportInitialize) this.PictureBox124).EndInit();
      ((ISupportInitialize) this.PictureBox125).EndInit();
      ((ISupportInitialize) this.PictureBox126).EndInit();
      ((ISupportInitialize) this.PictureBox127).EndInit();
      ((ISupportInitialize) this.PictureBox128).EndInit();
      ((ISupportInitialize) this.PictureBox129).EndInit();
      ((ISupportInitialize) this.PictureBox130).EndInit();
      ((ISupportInitialize) this.PictureBox131).EndInit();
      ((ISupportInitialize) this.PictureBox132).EndInit();
      ((ISupportInitialize) this.PictureBox133).EndInit();
      ((ISupportInitialize) this.PictureBox134).EndInit();
      ((ISupportInitialize) this.PictureBox135).EndInit();
      ((ISupportInitialize) this.PictureBox136).EndInit();
      ((ISupportInitialize) this.PictureBox137).EndInit();
      ((ISupportInitialize) this.PictureBox138).EndInit();
      ((ISupportInitialize) this.PictureBox139).EndInit();
      ((ISupportInitialize) this.PictureBox140).EndInit();
      ((ISupportInitialize) this.PictureBox141).EndInit();
      ((ISupportInitialize) this.PictureBox142).EndInit();
      ((ISupportInitialize) this.PictureBox143).EndInit();
      ((ISupportInitialize) this.PictureBox144).EndInit();
      ((ISupportInitialize) this.PictureBox145).EndInit();
      ((ISupportInitialize) this.PictureBox146).EndInit();
      ((ISupportInitialize) this.PictureBox147).EndInit();
      ((ISupportInitialize) this.PictureBox148).EndInit();
      ((ISupportInitialize) this.PictureBox149).EndInit();
      ((ISupportInitialize) this.PictureBox150).EndInit();
      ((ISupportInitialize) this.PictureBox151).EndInit();
      ((ISupportInitialize) this.PictureBox152).EndInit();
      ((ISupportInitialize) this.PictureBox153).EndInit();
      ((ISupportInitialize) this.PictureBox154).EndInit();
      ((ISupportInitialize) this.PictureBox155).EndInit();
      ((ISupportInitialize) this.PictureBox156).EndInit();
      ((ISupportInitialize) this.PictureBox157).EndInit();
      ((ISupportInitialize) this.PictureBox158).EndInit();
      ((ISupportInitialize) this.PictureBox159).EndInit();
      ((ISupportInitialize) this.PictureBox160).EndInit();
      ((ISupportInitialize) this.PictureBox161).EndInit();
      ((ISupportInitialize) this.PictureBox162).EndInit();
      ((ISupportInitialize) this.PictureBox163).EndInit();
      ((ISupportInitialize) this.PictureBox164).EndInit();
      ((ISupportInitialize) this.PictureBox165).EndInit();
      ((ISupportInitialize) this.PictureBox166).EndInit();
      ((ISupportInitialize) this.PictureBox167).EndInit();
      ((ISupportInitialize) this.PictureBox168).EndInit();
      ((ISupportInitialize) this.PictureBox169).EndInit();
      ((ISupportInitialize) this.PictureBox170).EndInit();
      ((ISupportInitialize) this.PictureBox171).EndInit();
      ((ISupportInitialize) this.PictureBox172).EndInit();
      ((ISupportInitialize) this.PictureBox173).EndInit();
      ((ISupportInitialize) this.PictureBox174).EndInit();
      ((ISupportInitialize) this.PictureBox175).EndInit();
      ((ISupportInitialize) this.PictureBox176).EndInit();
      ((ISupportInitialize) this.PictureBox177).EndInit();
      ((ISupportInitialize) this.PictureBox178).EndInit();
      ((ISupportInitialize) this.PictureBox179).EndInit();
      ((ISupportInitialize) this.PictureBox180).EndInit();
      ((ISupportInitialize) this.PictureBox181).EndInit();
      ((ISupportInitialize) this.PictureBox182).EndInit();
      ((ISupportInitialize) this.PictureBox183).EndInit();
      ((ISupportInitialize) this.PictureBox184).EndInit();
      ((ISupportInitialize) this.PictureBox185).EndInit();
      ((ISupportInitialize) this.PictureBox186).EndInit();
      ((ISupportInitialize) this.PictureBox187).EndInit();
      ((ISupportInitialize) this.PictureBox188).EndInit();
      ((ISupportInitialize) this.PictureBox189).EndInit();
      ((ISupportInitialize) this.PictureBox190).EndInit();
      ((ISupportInitialize) this.PictureBox191).EndInit();
      ((ISupportInitialize) this.PictureBox192).EndInit();
      ((ISupportInitialize) this.PictureBox193).EndInit();
      ((ISupportInitialize) this.PictureBox194).EndInit();
      ((ISupportInitialize) this.PictureBox195).EndInit();
      ((ISupportInitialize) this.PictureBox196).EndInit();
      ((ISupportInitialize) this.PictureBox197).EndInit();
      ((ISupportInitialize) this.PictureBox198).EndInit();
      ((ISupportInitialize) this.PictureBox199).EndInit();
      ((ISupportInitialize) this.PictureBox200).EndInit();
      ((ISupportInitialize) this.PictureBox201).EndInit();
      ((ISupportInitialize) this.PictureBox202).EndInit();
      ((ISupportInitialize) this.PictureBox203).EndInit();
      ((ISupportInitialize) this.PictureBox204).EndInit();
      ((ISupportInitialize) this.PictureBox205).EndInit();
      ((ISupportInitialize) this.PictureBox206).EndInit();
      ((ISupportInitialize) this.PictureBox207).EndInit();
      ((ISupportInitialize) this.PictureBox208).EndInit();
      ((ISupportInitialize) this.PictureBox209).EndInit();
      ((ISupportInitialize) this.PictureBox210).EndInit();
      ((ISupportInitialize) this.PictureBox211).EndInit();
      ((ISupportInitialize) this.PictureBox212).EndInit();
      ((ISupportInitialize) this.PictureBox213).EndInit();
      ((ISupportInitialize) this.PictureBox214).EndInit();
      ((ISupportInitialize) this.PictureBox215).EndInit();
      ((ISupportInitialize) this.PictureBox216).EndInit();
      ((ISupportInitialize) this.PictureBox217).EndInit();
      ((ISupportInitialize) this.PictureBox218).EndInit();
      ((ISupportInitialize) this.PictureBox219).EndInit();
      ((ISupportInitialize) this.PictureBox220).EndInit();
      ((ISupportInitialize) this.PictureBox221).EndInit();
      ((ISupportInitialize) this.PictureBox223).EndInit();
      ((ISupportInitialize) this.PictureBox222).EndInit();
      ((ISupportInitialize) this.PictureBox224).EndInit();
      ((ISupportInitialize) this.PictureBox57).EndInit();
      ((ISupportInitialize) this.PictureBox58).EndInit();
      ((ISupportInitialize) this.PictureBox59).EndInit();
      ((ISupportInitialize) this.PictureBox60).EndInit();
      ((ISupportInitialize) this.PictureBox61).EndInit();
      ((ISupportInitialize) this.PictureBox62).EndInit();
      ((ISupportInitialize) this.PictureBox63).EndInit();
      ((ISupportInitialize) this.PictureBox64).EndInit();
      ((ISupportInitialize) this.PictureBox65).EndInit();
      ((ISupportInitialize) this.PictureBox66).EndInit();
      ((ISupportInitialize) this.PictureBox67).EndInit();
      ((ISupportInitialize) this.PictureBox68).EndInit();
      ((ISupportInitialize) this.PictureBox69).EndInit();
      ((ISupportInitialize) this.PictureBox70).EndInit();
      ((ISupportInitialize) this.PictureBox71).EndInit();
      ((ISupportInitialize) this.PictureBox72).EndInit();
      ((ISupportInitialize) this.PictureBox73).EndInit();
      ((ISupportInitialize) this.PictureBox74).EndInit();
      ((ISupportInitialize) this.PictureBox75).EndInit();
      ((ISupportInitialize) this.PictureBox76).EndInit();
      ((ISupportInitialize) this.PictureBox77).EndInit();
      ((ISupportInitialize) this.PictureBox78).EndInit();
      ((ISupportInitialize) this.PictureBox79).EndInit();
      ((ISupportInitialize) this.PictureBox80).EndInit();
      ((ISupportInitialize) this.PictureBox81).EndInit();
      ((ISupportInitialize) this.PictureBox82).EndInit();
      ((ISupportInitialize) this.PictureBox83).EndInit();
      ((ISupportInitialize) this.PictureBox84).EndInit();
      ((ISupportInitialize) this.PictureBox85).EndInit();
      ((ISupportInitialize) this.PictureBox86).EndInit();
      ((ISupportInitialize) this.PictureBox87).EndInit();
      ((ISupportInitialize) this.PictureBox88).EndInit();
      ((ISupportInitialize) this.PictureBox89).EndInit();
      ((ISupportInitialize) this.PictureBox90).EndInit();
      ((ISupportInitialize) this.PictureBox91).EndInit();
      ((ISupportInitialize) this.PictureBox92).EndInit();
      ((ISupportInitialize) this.PictureBox93).EndInit();
      ((ISupportInitialize) this.PictureBox94).EndInit();
      ((ISupportInitialize) this.PictureBox95).EndInit();
      ((ISupportInitialize) this.PictureBox96).EndInit();
      ((ISupportInitialize) this.PictureBox97).EndInit();
      ((ISupportInitialize) this.PictureBox98).EndInit();
      ((ISupportInitialize) this.PictureBox99).EndInit();
      ((ISupportInitialize) this.PictureBox100).EndInit();
      ((ISupportInitialize) this.PictureBox101).EndInit();
      ((ISupportInitialize) this.PictureBox102).EndInit();
      ((ISupportInitialize) this.PictureBox103).EndInit();
      ((ISupportInitialize) this.PictureBox104).EndInit();
      ((ISupportInitialize) this.PictureBox105).EndInit();
      ((ISupportInitialize) this.PictureBox106).EndInit();
      ((ISupportInitialize) this.PictureBox107).EndInit();
      ((ISupportInitialize) this.PictureBox108).EndInit();
      ((ISupportInitialize) this.PictureBox109).EndInit();
      ((ISupportInitialize) this.PictureBox110).EndInit();
      ((ISupportInitialize) this.PictureBox111).EndInit();
      ((ISupportInitialize) this.PictureBox112).EndInit();
      ((ISupportInitialize) this.PictureBox29).EndInit();
      ((ISupportInitialize) this.PictureBox30).EndInit();
      ((ISupportInitialize) this.PictureBox31).EndInit();
      ((ISupportInitialize) this.PictureBox32).EndInit();
      ((ISupportInitialize) this.PictureBox33).EndInit();
      ((ISupportInitialize) this.PictureBox34).EndInit();
      ((ISupportInitialize) this.PictureBox35).EndInit();
      ((ISupportInitialize) this.PictureBox36).EndInit();
      ((ISupportInitialize) this.PictureBox37).EndInit();
      ((ISupportInitialize) this.PictureBox38).EndInit();
      ((ISupportInitialize) this.PictureBox39).EndInit();
      ((ISupportInitialize) this.PictureBox40).EndInit();
      ((ISupportInitialize) this.PictureBox41).EndInit();
      ((ISupportInitialize) this.PictureBox42).EndInit();
      ((ISupportInitialize) this.PictureBox43).EndInit();
      ((ISupportInitialize) this.PictureBox44).EndInit();
      ((ISupportInitialize) this.PictureBox45).EndInit();
      ((ISupportInitialize) this.PictureBox46).EndInit();
      ((ISupportInitialize) this.PictureBox47).EndInit();
      ((ISupportInitialize) this.PictureBox48).EndInit();
      ((ISupportInitialize) this.PictureBox49).EndInit();
      ((ISupportInitialize) this.PictureBox50).EndInit();
      ((ISupportInitialize) this.PictureBox51).EndInit();
      ((ISupportInitialize) this.PictureBox52).EndInit();
      ((ISupportInitialize) this.PictureBox53).EndInit();
      ((ISupportInitialize) this.PictureBox54).EndInit();
      ((ISupportInitialize) this.PictureBox55).EndInit();
      ((ISupportInitialize) this.PictureBox56).EndInit();
      ((ISupportInitialize) this.PictureBox15).EndInit();
      ((ISupportInitialize) this.PictureBox16).EndInit();
      ((ISupportInitialize) this.PictureBox17).EndInit();
      ((ISupportInitialize) this.PictureBox18).EndInit();
      ((ISupportInitialize) this.PictureBox19).EndInit();
      ((ISupportInitialize) this.PictureBox20).EndInit();
      ((ISupportInitialize) this.PictureBox21).EndInit();
      ((ISupportInitialize) this.PictureBox22).EndInit();
      ((ISupportInitialize) this.PictureBox23).EndInit();
      ((ISupportInitialize) this.PictureBox24).EndInit();
      ((ISupportInitialize) this.PictureBox25).EndInit();
      ((ISupportInitialize) this.PictureBox26).EndInit();
      ((ISupportInitialize) this.PictureBox27).EndInit();
      ((ISupportInitialize) this.PictureBox28).EndInit();
      ((ISupportInitialize) this.PictureBox14).EndInit();
      ((ISupportInitialize) this.PictureBox13).EndInit();
      ((ISupportInitialize) this.PictureBox12).EndInit();
      ((ISupportInitialize) this.PictureBox11).EndInit();
      ((ISupportInitialize) this.PictureBox10).EndInit();
      ((ISupportInitialize) this.PictureBox9).EndInit();
      ((ISupportInitialize) this.PictureBox8).EndInit();
      ((ISupportInitialize) this.PictureBox7).EndInit();
      ((ISupportInitialize) this.PictureBox6).EndInit();
      ((ISupportInitialize) this.PictureBox5).EndInit();
      ((ISupportInitialize) this.PictureBox4).EndInit();
      ((ISupportInitialize) this.PictureBox3).EndInit();
      ((ISupportInitialize) this.PictureBox2).EndInit();
      ((ISupportInitialize) this.PictureBox1).EndInit();
      ((ISupportInitialize) this.PJ1).EndInit();
      ((ISupportInitialize) this.FotoMapa).EndInit();
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

    public object CargarMapas()
    {
      this.ListaMapas.Items.Clear();
      int num1 = 1;
      int num2 = Conversions.ToInteger(GameDataArrays.string_2);
      int num3 = num1;
      while (num3 <= num2)
      {
        this.ListaMapas.Items.Add((object) (GameDataArrays.string_0[checked (num3 - 1)] + " " + GameDataArrays.string_1[checked (num3 - 1)]));
        checked { ++num3; }
      }
      return (object) true;
    }

    public object OcultarXY()
    {
      this.PJ1.Visible = false;
      this.PictureBox1.Visible = false;
      this.PictureBox2.Visible = false;
      this.PictureBox3.Visible = false;
      this.PictureBox4.Visible = false;
      this.PictureBox5.Visible = false;
      this.PictureBox6.Visible = false;
      this.PictureBox7.Visible = false;
      this.PictureBox8.Visible = false;
      this.PictureBox9.Visible = false;
      this.PictureBox10.Visible = false;
      this.PictureBox11.Visible = false;
      this.PictureBox12.Visible = false;
      this.PictureBox13.Visible = false;
      this.PictureBox14.Visible = false;
      this.PictureBox15.Visible = false;
      this.PictureBox16.Visible = false;
      this.PictureBox17.Visible = false;
      this.PictureBox18.Visible = false;
      this.PictureBox19.Visible = false;
      this.PictureBox20.Visible = false;
      this.PictureBox21.Visible = false;
      this.PictureBox22.Visible = false;
      this.PictureBox23.Visible = false;
      this.PictureBox24.Visible = false;
      this.PictureBox25.Visible = false;
      this.PictureBox26.Visible = false;
      this.PictureBox27.Visible = false;
      this.PictureBox28.Visible = false;
      this.PictureBox29.Visible = false;
      this.PictureBox30.Visible = false;
      this.PictureBox31.Visible = false;
      this.PictureBox32.Visible = false;
      this.PictureBox33.Visible = false;
      this.PictureBox34.Visible = false;
      this.PictureBox35.Visible = false;
      this.PictureBox36.Visible = false;
      this.PictureBox37.Visible = false;
      this.PictureBox38.Visible = false;
      this.PictureBox39.Visible = false;
      this.PictureBox40.Visible = false;
      this.PictureBox41.Visible = false;
      this.PictureBox42.Visible = false;
      this.PictureBox43.Visible = false;
      this.PictureBox44.Visible = false;
      this.PictureBox45.Visible = false;
      this.PictureBox46.Visible = false;
      this.PictureBox47.Visible = false;
      this.PictureBox48.Visible = false;
      this.PictureBox49.Visible = false;
      this.PictureBox50.Visible = false;
      this.PictureBox51.Visible = false;
      this.PictureBox52.Visible = false;
      this.PictureBox53.Visible = false;
      this.PictureBox54.Visible = false;
      this.PictureBox55.Visible = false;
      this.PictureBox56.Visible = false;
      this.PictureBox57.Visible = false;
      this.PictureBox58.Visible = false;
      this.PictureBox59.Visible = false;
      this.PictureBox60.Visible = false;
      this.PictureBox61.Visible = false;
      this.PictureBox62.Visible = false;
      this.PictureBox63.Visible = false;
      this.PictureBox64.Visible = false;
      this.PictureBox65.Visible = false;
      this.PictureBox66.Visible = false;
      this.PictureBox67.Visible = false;
      this.PictureBox68.Visible = false;
      this.PictureBox69.Visible = false;
      this.PictureBox70.Visible = false;
      this.PictureBox71.Visible = false;
      this.PictureBox72.Visible = false;
      this.PictureBox73.Visible = false;
      this.PictureBox74.Visible = false;
      this.PictureBox75.Visible = false;
      this.PictureBox76.Visible = false;
      this.PictureBox77.Visible = false;
      this.PictureBox78.Visible = false;
      this.PictureBox79.Visible = false;
      this.PictureBox80.Visible = false;
      this.PictureBox81.Visible = false;
      this.PictureBox82.Visible = false;
      this.PictureBox83.Visible = false;
      this.PictureBox84.Visible = false;
      this.PictureBox85.Visible = false;
      this.PictureBox86.Visible = false;
      this.PictureBox87.Visible = false;
      this.PictureBox88.Visible = false;
      this.PictureBox89.Visible = false;
      this.PictureBox90.Visible = false;
      this.PictureBox91.Visible = false;
      this.PictureBox92.Visible = false;
      this.PictureBox93.Visible = false;
      this.PictureBox94.Visible = false;
      this.PictureBox95.Visible = false;
      this.PictureBox96.Visible = false;
      this.PictureBox97.Visible = false;
      this.PictureBox98.Visible = false;
      this.PictureBox99.Visible = false;
      this.PictureBox100.Visible = false;
      this.PictureBox101.Visible = false;
      this.PictureBox102.Visible = false;
      this.PictureBox103.Visible = false;
      this.PictureBox104.Visible = false;
      this.PictureBox105.Visible = false;
      this.PictureBox106.Visible = false;
      this.PictureBox107.Visible = false;
      this.PictureBox108.Visible = false;
      this.PictureBox109.Visible = false;
      this.PictureBox110.Visible = false;
      this.PictureBox111.Visible = false;
      this.PictureBox112.Visible = false;
      this.PictureBox113.Visible = false;
      this.PictureBox114.Visible = false;
      this.PictureBox115.Visible = false;
      this.PictureBox116.Visible = false;
      this.PictureBox117.Visible = false;
      this.PictureBox118.Visible = false;
      this.PictureBox119.Visible = false;
      this.PictureBox120.Visible = false;
      this.PictureBox121.Visible = false;
      this.PictureBox122.Visible = false;
      this.PictureBox123.Visible = false;
      this.PictureBox124.Visible = false;
      this.PictureBox125.Visible = false;
      this.PictureBox126.Visible = false;
      this.PictureBox127.Visible = false;
      this.PictureBox128.Visible = false;
      this.PictureBox129.Visible = false;
      this.PictureBox130.Visible = false;
      this.PictureBox131.Visible = false;
      this.PictureBox132.Visible = false;
      this.PictureBox133.Visible = false;
      this.PictureBox134.Visible = false;
      this.PictureBox135.Visible = false;
      this.PictureBox136.Visible = false;
      this.PictureBox137.Visible = false;
      this.PictureBox138.Visible = false;
      this.PictureBox139.Visible = false;
      this.PictureBox140.Visible = false;
      this.PictureBox141.Visible = false;
      this.PictureBox142.Visible = false;
      this.PictureBox143.Visible = false;
      this.PictureBox144.Visible = false;
      this.PictureBox145.Visible = false;
      this.PictureBox146.Visible = false;
      this.PictureBox147.Visible = false;
      this.PictureBox148.Visible = false;
      this.PictureBox149.Visible = false;
      this.PictureBox150.Visible = false;
      this.PictureBox151.Visible = false;
      this.PictureBox152.Visible = false;
      this.PictureBox153.Visible = false;
      this.PictureBox154.Visible = false;
      this.PictureBox155.Visible = false;
      this.PictureBox156.Visible = false;
      this.PictureBox157.Visible = false;
      this.PictureBox158.Visible = false;
      this.PictureBox159.Visible = false;
      this.PictureBox160.Visible = false;
      this.PictureBox161.Visible = false;
      this.PictureBox162.Visible = false;
      this.PictureBox163.Visible = false;
      this.PictureBox164.Visible = false;
      this.PictureBox165.Visible = false;
      this.PictureBox166.Visible = false;
      this.PictureBox167.Visible = false;
      this.PictureBox168.Visible = false;
      this.PictureBox169.Visible = false;
      this.PictureBox170.Visible = false;
      this.PictureBox171.Visible = false;
      this.PictureBox172.Visible = false;
      this.PictureBox173.Visible = false;
      this.PictureBox174.Visible = false;
      this.PictureBox175.Visible = false;
      this.PictureBox176.Visible = false;
      this.PictureBox177.Visible = false;
      this.PictureBox178.Visible = false;
      this.PictureBox179.Visible = false;
      this.PictureBox180.Visible = false;
      this.PictureBox181.Visible = false;
      this.PictureBox182.Visible = false;
      this.PictureBox183.Visible = false;
      this.PictureBox184.Visible = false;
      this.PictureBox185.Visible = false;
      this.PictureBox186.Visible = false;
      this.PictureBox187.Visible = false;
      this.PictureBox188.Visible = false;
      this.PictureBox189.Visible = false;
      this.PictureBox190.Visible = false;
      this.PictureBox191.Visible = false;
      this.PictureBox192.Visible = false;
      this.PictureBox193.Visible = false;
      this.PictureBox194.Visible = false;
      this.PictureBox195.Visible = false;
      this.PictureBox196.Visible = false;
      this.PictureBox197.Visible = false;
      this.PictureBox198.Visible = false;
      this.PictureBox199.Visible = false;
      this.PictureBox201.Visible = false;
      this.PictureBox202.Visible = false;
      this.PictureBox203.Visible = false;
      this.PictureBox204.Visible = false;
      this.PictureBox205.Visible = false;
      this.PictureBox206.Visible = false;
      this.PictureBox207.Visible = false;
      this.PictureBox208.Visible = false;
      this.PictureBox209.Visible = false;
      this.PictureBox210.Visible = false;
      this.PictureBox211.Visible = false;
      this.PictureBox212.Visible = false;
      this.PictureBox213.Visible = false;
      this.PictureBox214.Visible = false;
      this.PictureBox215.Visible = false;
      this.PictureBox216.Visible = false;
      this.PictureBox217.Visible = false;
      this.PictureBox218.Visible = false;
      this.PictureBox219.Visible = false;
      this.PictureBox220.Visible = false;
      this.PictureBox221.Visible = false;
      this.PictureBox222.Visible = false;
      this.PictureBox223.Visible = false;
      this.PictureBox224.Visible = false;
      this.PictureBox225.Visible = false;
      this.PictureBox226.Visible = false;
      this.PictureBox227.Visible = false;
      this.PictureBox228.Visible = false;
      this.PictureBox229.Visible = false;
      this.PictureBox230.Visible = false;
      this.PictureBox231.Visible = false;
      this.PictureBox232.Visible = false;
      this.PictureBox233.Visible = false;
      this.PictureBox234.Visible = false;
      this.PictureBox235.Visible = false;
      this.PictureBox236.Visible = false;
      this.PictureBox237.Visible = false;
      this.PictureBox238.Visible = false;
      this.PictureBox239.Visible = false;
      this.PictureBox240.Visible = false;
      this.PictureBox241.Visible = false;
      this.PictureBox242.Visible = false;
      this.PictureBox243.Visible = false;
      this.PictureBox244.Visible = false;
      this.PictureBox245.Visible = false;
      this.PictureBox246.Visible = false;
      this.PictureBox247.Visible = false;
      this.PictureBox248.Visible = false;
      this.PictureBox249.Visible = false;
      this.PictureBox250.Visible = false;
      this.PictureBox251.Visible = false;
      this.PictureBox252.Visible = false;
      this.PictureBox253.Visible = false;
      this.PictureBox254.Visible = false;
      this.PictureBox255.Visible = false;
      this.PictureBox256.Visible = false;
      this.PictureBox257.Visible = false;
      this.PictureBox258.Visible = false;
      this.PictureBox259.Visible = false;
      this.PictureBox260.Visible = false;
      this.PictureBox261.Visible = false;
      this.PictureBox262.Visible = false;
      this.PictureBox263.Visible = false;
      this.PictureBox264.Visible = false;
      this.PictureBox265.Visible = false;
      this.PictureBox266.Visible = false;
      this.PictureBox267.Visible = false;
      this.PictureBox268.Visible = false;
      this.PictureBox269.Visible = false;
      this.PictureBox270.Visible = false;
      this.PictureBox271.Visible = false;
      this.PictureBox272.Visible = false;
      this.PictureBox273.Visible = false;
      this.PictureBox274.Visible = false;
      this.PictureBox275.Visible = false;
      this.PictureBox276.Visible = false;
      this.PictureBox277.Visible = false;
      this.PictureBox278.Visible = false;
      this.PictureBox279.Visible = false;
      this.PictureBox280.Visible = false;
      this.PictureBox281.Visible = false;
      this.PictureBox282.Visible = false;
      this.PictureBox283.Visible = false;
      this.PictureBox284.Visible = false;
      this.PictureBox285.Visible = false;
      this.PictureBox286.Visible = false;
      this.PictureBox287.Visible = false;
      this.PictureBox288.Visible = false;
      this.PictureBox289.Visible = false;
      this.PictureBox290.Visible = false;
      this.PictureBox291.Visible = false;
      this.PictureBox292.Visible = false;
      this.PictureBox293.Visible = false;
      this.PictureBox294.Visible = false;
      this.PictureBox295.Visible = false;
      this.PictureBox296.Visible = false;
      this.PictureBox297.Visible = false;
      this.PictureBox298.Visible = false;
      this.PictureBox299.Visible = false;
      this.PictureBox301.Visible = false;
      this.PictureBox302.Visible = false;
      this.PictureBox303.Visible = false;
      this.PictureBox304.Visible = false;
      this.PictureBox305.Visible = false;
      this.PictureBox306.Visible = false;
      this.PictureBox307.Visible = false;
      this.PictureBox308.Visible = false;
      this.PictureBox309.Visible = false;
      this.PictureBox310.Visible = false;
      this.PictureBox311.Visible = false;
      this.PictureBox312.Visible = false;
      this.PictureBox313.Visible = false;
      this.PictureBox314.Visible = false;
      this.PictureBox315.Visible = false;
      this.PictureBox316.Visible = false;
      this.PictureBox317.Visible = false;
      this.PictureBox318.Visible = false;
      this.PictureBox319.Visible = false;
      this.PictureBox320.Visible = false;
      this.PictureBox321.Visible = false;
      this.PictureBox322.Visible = false;
      this.PictureBox323.Visible = false;
      this.PictureBox324.Visible = false;
      this.PictureBox325.Visible = false;
      this.PictureBox326.Visible = false;
      this.PictureBox327.Visible = false;
      this.PictureBox328.Visible = false;
      this.PictureBox329.Visible = false;
      this.PictureBox330.Visible = false;
      this.PictureBox331.Visible = false;
      this.PictureBox332.Visible = false;
      this.PictureBox333.Visible = false;
      this.PictureBox334.Visible = false;
      this.PictureBox335.Visible = false;
      this.PictureBox336.Visible = false;
      this.PictureBox337.Visible = false;
      this.PictureBox338.Visible = false;
      this.PictureBox339.Visible = false;
      this.PictureBox340.Visible = false;
      this.PictureBox341.Visible = false;
      this.PictureBox342.Visible = false;
      this.PictureBox343.Visible = false;
      this.PictureBox344.Visible = false;
      this.PictureBox345.Visible = false;
      this.PictureBox346.Visible = false;
      this.PictureBox347.Visible = false;
      this.PictureBox348.Visible = false;
      this.PictureBox349.Visible = false;
      this.PictureBox350.Visible = false;
      this.PictureBox351.Visible = false;
      this.PictureBox352.Visible = false;
      this.PictureBox353.Visible = false;
      this.PictureBox354.Visible = false;
      this.PictureBox355.Visible = false;
      this.PictureBox356.Visible = false;
      this.PictureBox357.Visible = false;
      this.PictureBox358.Visible = false;
      this.PictureBox359.Visible = false;
      this.PictureBox360.Visible = false;
      this.PictureBox361.Visible = false;
      this.PictureBox362.Visible = false;
      this.PictureBox363.Visible = false;
      this.PictureBox364.Visible = false;
      this.PictureBox365.Visible = false;
      this.PictureBox366.Visible = false;
      this.PictureBox367.Visible = false;
      this.PictureBox368.Visible = false;
      this.PictureBox369.Visible = false;
      this.PictureBox370.Visible = false;
      this.PictureBox371.Visible = false;
      this.PictureBox372.Visible = false;
      this.PictureBox373.Visible = false;
      this.PictureBox374.Visible = false;
      this.PictureBox375.Visible = false;
      this.PictureBox376.Visible = false;
      this.PictureBox377.Visible = false;
      this.PictureBox378.Visible = false;
      this.PictureBox379.Visible = false;
      this.PictureBox380.Visible = false;
      this.PictureBox381.Visible = false;
      this.PictureBox382.Visible = false;
      this.PictureBox383.Visible = false;
      this.PictureBox384.Visible = false;
      this.PictureBox385.Visible = false;
      this.PictureBox386.Visible = false;
      this.PictureBox387.Visible = false;
      this.PictureBox388.Visible = false;
      this.PictureBox389.Visible = false;
      this.PictureBox390.Visible = false;
      this.PictureBox391.Visible = false;
      this.PictureBox392.Visible = false;
      this.PictureBox393.Visible = false;
      this.PictureBox394.Visible = false;
      this.PictureBox395.Visible = false;
      this.PictureBox396.Visible = false;
      this.PictureBox397.Visible = false;
      this.PictureBox398.Visible = false;
      this.PictureBox399.Visible = false;
      this.PictureBox401.Visible = false;
      this.PictureBox402.Visible = false;
      this.PictureBox403.Visible = false;
      this.PictureBox404.Visible = false;
      this.PictureBox405.Visible = false;
      this.PictureBox406.Visible = false;
      this.PictureBox407.Visible = false;
      this.PictureBox408.Visible = false;
      this.PictureBox409.Visible = false;
      this.PictureBox410.Visible = false;
      this.PictureBox411.Visible = false;
      this.PictureBox412.Visible = false;
      this.PictureBox413.Visible = false;
      this.PictureBox414.Visible = false;
      this.PictureBox415.Visible = false;
      this.PictureBox416.Visible = false;
      this.PictureBox417.Visible = false;
      this.PictureBox418.Visible = false;
      this.PictureBox419.Visible = false;
      this.PictureBox420.Visible = false;
      this.PictureBox421.Visible = false;
      this.PictureBox422.Visible = false;
      this.PictureBox423.Visible = false;
      this.PictureBox424.Visible = false;
      this.PictureBox425.Visible = false;
      this.PictureBox426.Visible = false;
      this.PictureBox427.Visible = false;
      this.PictureBox428.Visible = false;
      this.PictureBox429.Visible = false;
      this.PictureBox430.Visible = false;
      this.PictureBox431.Visible = false;
      this.PictureBox432.Visible = false;
      this.PictureBox433.Visible = false;
      this.PictureBox434.Visible = false;
      this.PictureBox435.Visible = false;
      this.PictureBox436.Visible = false;
      this.PictureBox437.Visible = false;
      this.PictureBox438.Visible = false;
      this.PictureBox439.Visible = false;
      this.PictureBox440.Visible = false;
      this.PictureBox441.Visible = false;
      this.PictureBox442.Visible = false;
      this.PictureBox443.Visible = false;
      this.PictureBox444.Visible = false;
      this.PictureBox445.Visible = false;
      this.PictureBox446.Visible = false;
      this.PictureBox447.Visible = false;
      this.PictureBox448.Visible = false;
      this.PictureBox449.Visible = false;
      this.PictureBox450.Visible = false;
      this.PictureBox451.Visible = false;
      this.PictureBox452.Visible = false;
      this.PictureBox453.Visible = false;
      this.PictureBox454.Visible = false;
      this.PictureBox455.Visible = false;
      this.PictureBox456.Visible = false;
      this.PictureBox457.Visible = false;
      this.PictureBox458.Visible = false;
      this.PictureBox459.Visible = false;
      this.PictureBox460.Visible = false;
      this.PictureBox461.Visible = false;
      this.PictureBox462.Visible = false;
      this.PictureBox463.Visible = false;
      this.PictureBox464.Visible = false;
      this.PictureBox465.Visible = false;
      this.PictureBox466.Visible = false;
      this.PictureBox467.Visible = false;
      this.PictureBox468.Visible = false;
      this.PictureBox469.Visible = false;
      this.PictureBox470.Visible = false;
      this.PictureBox471.Visible = false;
      this.PictureBox472.Visible = false;
      this.PictureBox473.Visible = false;
      this.PictureBox474.Visible = false;
      this.PictureBox475.Visible = false;
      this.PictureBox476.Visible = false;
      this.PictureBox477.Visible = false;
      this.PictureBox478.Visible = false;
      this.PictureBox479.Visible = false;
      this.PictureBox480.Visible = false;
      this.PictureBox481.Visible = false;
      this.PictureBox482.Visible = false;
      this.PictureBox483.Visible = false;
      this.PictureBox484.Visible = false;
      this.PictureBox485.Visible = false;
      this.PictureBox486.Visible = false;
      this.PictureBox487.Visible = false;
      this.PictureBox488.Visible = false;
      this.PictureBox489.Visible = false;
      this.PictureBox490.Visible = false;
      this.PictureBox491.Visible = false;
      this.PictureBox492.Visible = false;
      this.PictureBox493.Visible = false;
      this.PictureBox494.Visible = false;
      this.PictureBox495.Visible = false;
      this.PictureBox496.Visible = false;
      this.PictureBox497.Visible = false;
      this.PictureBox498.Visible = false;
      this.PictureBox499.Visible = false;
      this.PictureBox500.Visible = false;
      return (object) true;
    }

    public object RestriccionesON()
    {
      this.PK.Enabled = false;
      this.PN.Enabled = false;
      this.PH.Enabled = false;
      this.Desconectador.Enabled = true;
      this.BanUnBan.Enabled = true;
      this.Aplicar.Enabled = true;
      return (object) true;
    }

    public object RestriccionesOFF()
    {
      this.PK.Enabled = true;
      this.PN.Enabled = true;
      this.PH.Enabled = true;
      this.Desconectador.Enabled = false;
      this.BanUnBan.Enabled = false;
      this.Aplicar.Enabled = false;
      return (object) true;
    }

    private void method_0(object sender, EventArgs e)
    {
      if (Conversions.ToDouble(this.XX.Text) > (double) byte.MaxValue)
        this.XX.Text = Conversions.ToString((int) byte.MaxValue);
      if (Conversions.ToDouble(this.XX.Text) >= 0.0)
        return;
      this.XX.Text = Conversions.ToString(0);
    }

    private void method_1(object sender, EventArgs e)
    {
      if (Conversions.ToDouble(this.YY.Text) > (double) byte.MaxValue)
        this.YY.Text = Conversions.ToString((int) byte.MaxValue);
      if (Conversions.ToDouble(this.YY.Text) >= 0.0)
        return;
      this.YY.Text = Conversions.ToString(0);
    }

    private void method_2(object sender, EventArgs e)
    {
      if (Conversions.ToDouble(this.XXX.Text) > (double) byte.MaxValue)
        this.XXX.Text = Conversions.ToString((int) byte.MaxValue);
      if (Conversions.ToDouble(this.XXX.Text) >= 0.0)
        return;
      this.XXX.Text = Conversions.ToString(0);
    }

    private void method_3(object sender, EventArgs e)
    {
      if (Conversions.ToDouble(this.YYY.Text) > (double) byte.MaxValue)
        this.YYY.Text = Conversions.ToString((int) byte.MaxValue);
      if (Conversions.ToDouble(this.YYY.Text) >= 0.0)
        return;
      this.YYY.Text = Conversions.ToString(0);
    }

    public object ResetXY()
    {
      PictureBox pj1 = this.PJ1;
      Point point1 = new Point(-4, -4);
      Point point2 = point1;
      pj1.Location = point2;
      PictureBox pictureBox1 = this.PictureBox1;
      point1 = new Point(-4, -4);
      Point point3 = point1;
      pictureBox1.Location = point3;
      PictureBox pictureBox2 = this.PictureBox2;
      point1 = new Point(-4, -4);
      Point point4 = point1;
      pictureBox2.Location = point4;
      PictureBox pictureBox3 = this.PictureBox3;
      point1 = new Point(-4, -4);
      Point point5 = point1;
      pictureBox3.Location = point5;
      PictureBox pictureBox4 = this.PictureBox4;
      point1 = new Point(-4, -4);
      Point point6 = point1;
      pictureBox4.Location = point6;
      PictureBox pictureBox5 = this.PictureBox5;
      point1 = new Point(-4, -4);
      Point point7 = point1;
      pictureBox5.Location = point7;
      PictureBox pictureBox6 = this.PictureBox6;
      point1 = new Point(-4, -4);
      Point point8 = point1;
      pictureBox6.Location = point8;
      PictureBox pictureBox7 = this.PictureBox7;
      point1 = new Point(-4, -4);
      Point point9 = point1;
      pictureBox7.Location = point9;
      PictureBox pictureBox8 = this.PictureBox8;
      point1 = new Point(-4, -4);
      Point point10 = point1;
      pictureBox8.Location = point10;
      PictureBox pictureBox9 = this.PictureBox9;
      point1 = new Point(-4, -4);
      Point point11 = point1;
      pictureBox9.Location = point11;
      PictureBox pictureBox10 = this.PictureBox10;
      point1 = new Point(-4, -4);
      Point point12 = point1;
      pictureBox10.Location = point12;
      PictureBox pictureBox11 = this.PictureBox11;
      point1 = new Point(-4, -4);
      Point point13 = point1;
      pictureBox11.Location = point13;
      PictureBox pictureBox12 = this.PictureBox12;
      point1 = new Point(-4, -4);
      Point point14 = point1;
      pictureBox12.Location = point14;
      PictureBox pictureBox13 = this.PictureBox13;
      point1 = new Point(-4, -4);
      Point point15 = point1;
      pictureBox13.Location = point15;
      PictureBox pictureBox14 = this.PictureBox14;
      point1 = new Point(-4, -4);
      Point point16 = point1;
      pictureBox14.Location = point16;
      PictureBox pictureBox15 = this.PictureBox15;
      point1 = new Point(-4, -4);
      Point point17 = point1;
      pictureBox15.Location = point17;
      PictureBox pictureBox16 = this.PictureBox16;
      point1 = new Point(-4, -4);
      Point point18 = point1;
      pictureBox16.Location = point18;
      PictureBox pictureBox17 = this.PictureBox17;
      point1 = new Point(-4, -4);
      Point point19 = point1;
      pictureBox17.Location = point19;
      PictureBox pictureBox18 = this.PictureBox18;
      point1 = new Point(-4, -4);
      Point point20 = point1;
      pictureBox18.Location = point20;
      PictureBox pictureBox19 = this.PictureBox19;
      point1 = new Point(-4, -4);
      Point point21 = point1;
      pictureBox19.Location = point21;
      PictureBox pictureBox20 = this.PictureBox20;
      point1 = new Point(-4, -4);
      Point point22 = point1;
      pictureBox20.Location = point22;
      PictureBox pictureBox21 = this.PictureBox21;
      point1 = new Point(-4, -4);
      Point point23 = point1;
      pictureBox21.Location = point23;
      PictureBox pictureBox22 = this.PictureBox22;
      point1 = new Point(-4, -4);
      Point point24 = point1;
      pictureBox22.Location = point24;
      PictureBox pictureBox23 = this.PictureBox23;
      point1 = new Point(-4, -4);
      Point point25 = point1;
      pictureBox23.Location = point25;
      PictureBox pictureBox24 = this.PictureBox24;
      point1 = new Point(-4, -4);
      Point point26 = point1;
      pictureBox24.Location = point26;
      PictureBox pictureBox25 = this.PictureBox25;
      point1 = new Point(-4, -4);
      Point point27 = point1;
      pictureBox25.Location = point27;
      PictureBox pictureBox26 = this.PictureBox26;
      point1 = new Point(-4, -4);
      Point point28 = point1;
      pictureBox26.Location = point28;
      PictureBox pictureBox27 = this.PictureBox27;
      point1 = new Point(-4, -4);
      Point point29 = point1;
      pictureBox27.Location = point29;
      PictureBox pictureBox28 = this.PictureBox28;
      point1 = new Point(-4, -4);
      Point point30 = point1;
      pictureBox28.Location = point30;
      PictureBox pictureBox29 = this.PictureBox29;
      point1 = new Point(-4, -4);
      Point point31 = point1;
      pictureBox29.Location = point31;
      PictureBox pictureBox30 = this.PictureBox30;
      point1 = new Point(-4, -4);
      Point point32 = point1;
      pictureBox30.Location = point32;
      PictureBox pictureBox31 = this.PictureBox31;
      point1 = new Point(-4, -4);
      Point point33 = point1;
      pictureBox31.Location = point33;
      PictureBox pictureBox32 = this.PictureBox32;
      point1 = new Point(-4, -4);
      Point point34 = point1;
      pictureBox32.Location = point34;
      PictureBox pictureBox33 = this.PictureBox33;
      point1 = new Point(-4, -4);
      Point point35 = point1;
      pictureBox33.Location = point35;
      PictureBox pictureBox34 = this.PictureBox34;
      point1 = new Point(-4, -4);
      Point point36 = point1;
      pictureBox34.Location = point36;
      PictureBox pictureBox35 = this.PictureBox35;
      point1 = new Point(-4, -4);
      Point point37 = point1;
      pictureBox35.Location = point37;
      PictureBox pictureBox36 = this.PictureBox36;
      point1 = new Point(-4, -4);
      Point point38 = point1;
      pictureBox36.Location = point38;
      PictureBox pictureBox37 = this.PictureBox37;
      point1 = new Point(-4, -4);
      Point point39 = point1;
      pictureBox37.Location = point39;
      PictureBox pictureBox38 = this.PictureBox38;
      point1 = new Point(-4, -4);
      Point point40 = point1;
      pictureBox38.Location = point40;
      PictureBox pictureBox39 = this.PictureBox39;
      point1 = new Point(-4, -4);
      Point point41 = point1;
      pictureBox39.Location = point41;
      PictureBox pictureBox40 = this.PictureBox40;
      point1 = new Point(-4, -4);
      Point point42 = point1;
      pictureBox40.Location = point42;
      PictureBox pictureBox41 = this.PictureBox41;
      point1 = new Point(-4, -4);
      Point point43 = point1;
      pictureBox41.Location = point43;
      PictureBox pictureBox42 = this.PictureBox42;
      point1 = new Point(-4, -4);
      Point point44 = point1;
      pictureBox42.Location = point44;
      PictureBox pictureBox43 = this.PictureBox43;
      point1 = new Point(-4, -4);
      Point point45 = point1;
      pictureBox43.Location = point45;
      PictureBox pictureBox44 = this.PictureBox44;
      point1 = new Point(-4, -4);
      Point point46 = point1;
      pictureBox44.Location = point46;
      PictureBox pictureBox45 = this.PictureBox45;
      point1 = new Point(-4, -4);
      Point point47 = point1;
      pictureBox45.Location = point47;
      PictureBox pictureBox46 = this.PictureBox46;
      point1 = new Point(-4, -4);
      Point point48 = point1;
      pictureBox46.Location = point48;
      PictureBox pictureBox47 = this.PictureBox47;
      point1 = new Point(-4, -4);
      Point point49 = point1;
      pictureBox47.Location = point49;
      PictureBox pictureBox48 = this.PictureBox48;
      point1 = new Point(-4, -4);
      Point point50 = point1;
      pictureBox48.Location = point50;
      PictureBox pictureBox49 = this.PictureBox49;
      point1 = new Point(-4, -4);
      Point point51 = point1;
      pictureBox49.Location = point51;
      PictureBox pictureBox50 = this.PictureBox50;
      point1 = new Point(-4, -4);
      Point point52 = point1;
      pictureBox50.Location = point52;
      PictureBox pictureBox51 = this.PictureBox51;
      point1 = new Point(-4, -4);
      Point point53 = point1;
      pictureBox51.Location = point53;
      PictureBox pictureBox52 = this.PictureBox52;
      point1 = new Point(-4, -4);
      Point point54 = point1;
      pictureBox52.Location = point54;
      PictureBox pictureBox53 = this.PictureBox53;
      point1 = new Point(-4, -4);
      Point point55 = point1;
      pictureBox53.Location = point55;
      PictureBox pictureBox54 = this.PictureBox54;
      point1 = new Point(-4, -4);
      Point point56 = point1;
      pictureBox54.Location = point56;
      PictureBox pictureBox55 = this.PictureBox55;
      point1 = new Point(-4, -4);
      Point point57 = point1;
      pictureBox55.Location = point57;
      PictureBox pictureBox56 = this.PictureBox56;
      point1 = new Point(-4, -4);
      Point point58 = point1;
      pictureBox56.Location = point58;
      PictureBox pictureBox57 = this.PictureBox57;
      point1 = new Point(-4, -4);
      Point point59 = point1;
      pictureBox57.Location = point59;
      PictureBox pictureBox58 = this.PictureBox58;
      point1 = new Point(-4, -4);
      Point point60 = point1;
      pictureBox58.Location = point60;
      PictureBox pictureBox59 = this.PictureBox59;
      point1 = new Point(-4, -4);
      Point point61 = point1;
      pictureBox59.Location = point61;
      PictureBox pictureBox60 = this.PictureBox60;
      point1 = new Point(-4, -4);
      Point point62 = point1;
      pictureBox60.Location = point62;
      PictureBox pictureBox61 = this.PictureBox61;
      point1 = new Point(-4, -4);
      Point point63 = point1;
      pictureBox61.Location = point63;
      PictureBox pictureBox62 = this.PictureBox62;
      point1 = new Point(-4, -4);
      Point point64 = point1;
      pictureBox62.Location = point64;
      PictureBox pictureBox63 = this.PictureBox63;
      point1 = new Point(-4, -4);
      Point point65 = point1;
      pictureBox63.Location = point65;
      PictureBox pictureBox64 = this.PictureBox64;
      point1 = new Point(-4, -4);
      Point point66 = point1;
      pictureBox64.Location = point66;
      PictureBox pictureBox65 = this.PictureBox65;
      point1 = new Point(-4, -4);
      Point point67 = point1;
      pictureBox65.Location = point67;
      PictureBox pictureBox66 = this.PictureBox66;
      point1 = new Point(-4, -4);
      Point point68 = point1;
      pictureBox66.Location = point68;
      PictureBox pictureBox67 = this.PictureBox67;
      point1 = new Point(-4, -4);
      Point point69 = point1;
      pictureBox67.Location = point69;
      PictureBox pictureBox68 = this.PictureBox68;
      point1 = new Point(-4, -4);
      Point point70 = point1;
      pictureBox68.Location = point70;
      PictureBox pictureBox69 = this.PictureBox69;
      point1 = new Point(-4, -4);
      Point point71 = point1;
      pictureBox69.Location = point71;
      PictureBox pictureBox70 = this.PictureBox70;
      point1 = new Point(-4, -4);
      Point point72 = point1;
      pictureBox70.Location = point72;
      PictureBox pictureBox71 = this.PictureBox71;
      point1 = new Point(-4, -4);
      Point point73 = point1;
      pictureBox71.Location = point73;
      PictureBox pictureBox72 = this.PictureBox72;
      point1 = new Point(-4, -4);
      Point point74 = point1;
      pictureBox72.Location = point74;
      PictureBox pictureBox73 = this.PictureBox73;
      point1 = new Point(-4, -4);
      Point point75 = point1;
      pictureBox73.Location = point75;
      PictureBox pictureBox74 = this.PictureBox74;
      point1 = new Point(-4, -4);
      Point point76 = point1;
      pictureBox74.Location = point76;
      PictureBox pictureBox75 = this.PictureBox75;
      point1 = new Point(-4, -4);
      Point point77 = point1;
      pictureBox75.Location = point77;
      PictureBox pictureBox76 = this.PictureBox76;
      point1 = new Point(-4, -4);
      Point point78 = point1;
      pictureBox76.Location = point78;
      PictureBox pictureBox77 = this.PictureBox77;
      point1 = new Point(-4, -4);
      Point point79 = point1;
      pictureBox77.Location = point79;
      PictureBox pictureBox78 = this.PictureBox78;
      point1 = new Point(-4, -4);
      Point point80 = point1;
      pictureBox78.Location = point80;
      PictureBox pictureBox79 = this.PictureBox79;
      point1 = new Point(-4, -4);
      Point point81 = point1;
      pictureBox79.Location = point81;
      PictureBox pictureBox80 = this.PictureBox80;
      point1 = new Point(-4, -4);
      Point point82 = point1;
      pictureBox80.Location = point82;
      PictureBox pictureBox81 = this.PictureBox81;
      point1 = new Point(-4, -4);
      Point point83 = point1;
      pictureBox81.Location = point83;
      PictureBox pictureBox82 = this.PictureBox82;
      point1 = new Point(-4, -4);
      Point point84 = point1;
      pictureBox82.Location = point84;
      PictureBox pictureBox83 = this.PictureBox83;
      point1 = new Point(-4, -4);
      Point point85 = point1;
      pictureBox83.Location = point85;
      PictureBox pictureBox84 = this.PictureBox84;
      point1 = new Point(-4, -4);
      Point point86 = point1;
      pictureBox84.Location = point86;
      PictureBox pictureBox85 = this.PictureBox85;
      point1 = new Point(-4, -4);
      Point point87 = point1;
      pictureBox85.Location = point87;
      PictureBox pictureBox86 = this.PictureBox86;
      point1 = new Point(-4, -4);
      Point point88 = point1;
      pictureBox86.Location = point88;
      PictureBox pictureBox87 = this.PictureBox87;
      point1 = new Point(-4, -4);
      Point point89 = point1;
      pictureBox87.Location = point89;
      PictureBox pictureBox88 = this.PictureBox88;
      point1 = new Point(-4, -4);
      Point point90 = point1;
      pictureBox88.Location = point90;
      PictureBox pictureBox89 = this.PictureBox89;
      point1 = new Point(-4, -4);
      Point point91 = point1;
      pictureBox89.Location = point91;
      PictureBox pictureBox90 = this.PictureBox90;
      point1 = new Point(-4, -4);
      Point point92 = point1;
      pictureBox90.Location = point92;
      PictureBox pictureBox91 = this.PictureBox91;
      point1 = new Point(-4, -4);
      Point point93 = point1;
      pictureBox91.Location = point93;
      PictureBox pictureBox92 = this.PictureBox92;
      point1 = new Point(-4, -4);
      Point point94 = point1;
      pictureBox92.Location = point94;
      PictureBox pictureBox93 = this.PictureBox93;
      point1 = new Point(-4, -4);
      Point point95 = point1;
      pictureBox93.Location = point95;
      PictureBox pictureBox94 = this.PictureBox94;
      point1 = new Point(-4, -4);
      Point point96 = point1;
      pictureBox94.Location = point96;
      PictureBox pictureBox95 = this.PictureBox95;
      point1 = new Point(-4, -4);
      Point point97 = point1;
      pictureBox95.Location = point97;
      PictureBox pictureBox96 = this.PictureBox96;
      point1 = new Point(-4, -4);
      Point point98 = point1;
      pictureBox96.Location = point98;
      PictureBox pictureBox97 = this.PictureBox97;
      point1 = new Point(-4, -4);
      Point point99 = point1;
      pictureBox97.Location = point99;
      PictureBox pictureBox98 = this.PictureBox98;
      point1 = new Point(-4, -4);
      Point point100 = point1;
      pictureBox98.Location = point100;
      PictureBox pictureBox99 = this.PictureBox99;
      point1 = new Point(-4, -4);
      Point point101 = point1;
      pictureBox99.Location = point101;
      PictureBox pictureBox100 = this.PictureBox100;
      point1 = new Point(-4, -4);
      Point point102 = point1;
      pictureBox100.Location = point102;
      PictureBox pictureBox101 = this.PictureBox101;
      point1 = new Point(-4, -4);
      Point point103 = point1;
      pictureBox101.Location = point103;
      PictureBox pictureBox102 = this.PictureBox102;
      point1 = new Point(-4, -4);
      Point point104 = point1;
      pictureBox102.Location = point104;
      PictureBox pictureBox103 = this.PictureBox103;
      point1 = new Point(-4, -4);
      Point point105 = point1;
      pictureBox103.Location = point105;
      PictureBox pictureBox104 = this.PictureBox104;
      point1 = new Point(-4, -4);
      Point point106 = point1;
      pictureBox104.Location = point106;
      PictureBox pictureBox105 = this.PictureBox105;
      point1 = new Point(-4, -4);
      Point point107 = point1;
      pictureBox105.Location = point107;
      PictureBox pictureBox106 = this.PictureBox106;
      point1 = new Point(-4, -4);
      Point point108 = point1;
      pictureBox106.Location = point108;
      PictureBox pictureBox107 = this.PictureBox107;
      point1 = new Point(-4, -4);
      Point point109 = point1;
      pictureBox107.Location = point109;
      PictureBox pictureBox108 = this.PictureBox108;
      point1 = new Point(-4, -4);
      Point point110 = point1;
      pictureBox108.Location = point110;
      PictureBox pictureBox109 = this.PictureBox109;
      point1 = new Point(-4, -4);
      Point point111 = point1;
      pictureBox109.Location = point111;
      PictureBox pictureBox110 = this.PictureBox110;
      point1 = new Point(-4, -4);
      Point point112 = point1;
      pictureBox110.Location = point112;
      PictureBox pictureBox111 = this.PictureBox111;
      point1 = new Point(-4, -4);
      Point point113 = point1;
      pictureBox111.Location = point113;
      PictureBox pictureBox112 = this.PictureBox112;
      point1 = new Point(-4, -4);
      Point point114 = point1;
      pictureBox112.Location = point114;
      PictureBox pictureBox113 = this.PictureBox113;
      point1 = new Point(-4, -4);
      Point point115 = point1;
      pictureBox113.Location = point115;
      PictureBox pictureBox114 = this.PictureBox114;
      point1 = new Point(-4, -4);
      Point point116 = point1;
      pictureBox114.Location = point116;
      PictureBox pictureBox115 = this.PictureBox115;
      point1 = new Point(-4, -4);
      Point point117 = point1;
      pictureBox115.Location = point117;
      PictureBox pictureBox116 = this.PictureBox116;
      point1 = new Point(-4, -4);
      Point point118 = point1;
      pictureBox116.Location = point118;
      PictureBox pictureBox117 = this.PictureBox117;
      point1 = new Point(-4, -4);
      Point point119 = point1;
      pictureBox117.Location = point119;
      PictureBox pictureBox118 = this.PictureBox118;
      point1 = new Point(-4, -4);
      Point point120 = point1;
      pictureBox118.Location = point120;
      PictureBox pictureBox119 = this.PictureBox119;
      point1 = new Point(-4, -4);
      Point point121 = point1;
      pictureBox119.Location = point121;
      PictureBox pictureBox120 = this.PictureBox120;
      point1 = new Point(-4, -4);
      Point point122 = point1;
      pictureBox120.Location = point122;
      PictureBox pictureBox121 = this.PictureBox121;
      point1 = new Point(-4, -4);
      Point point123 = point1;
      pictureBox121.Location = point123;
      PictureBox pictureBox122 = this.PictureBox122;
      point1 = new Point(-4, -4);
      Point point124 = point1;
      pictureBox122.Location = point124;
      PictureBox pictureBox123 = this.PictureBox123;
      point1 = new Point(-4, -4);
      Point point125 = point1;
      pictureBox123.Location = point125;
      PictureBox pictureBox124 = this.PictureBox124;
      point1 = new Point(-4, -4);
      Point point126 = point1;
      pictureBox124.Location = point126;
      PictureBox pictureBox125 = this.PictureBox125;
      point1 = new Point(-4, -4);
      Point point127 = point1;
      pictureBox125.Location = point127;
      PictureBox pictureBox126 = this.PictureBox126;
      point1 = new Point(-4, -4);
      Point point128 = point1;
      pictureBox126.Location = point128;
      PictureBox pictureBox127 = this.PictureBox127;
      point1 = new Point(-4, -4);
      Point point129 = point1;
      pictureBox127.Location = point129;
      PictureBox pictureBox128 = this.PictureBox128;
      point1 = new Point(-4, -4);
      Point point130 = point1;
      pictureBox128.Location = point130;
      PictureBox pictureBox129 = this.PictureBox129;
      point1 = new Point(-4, -4);
      Point point131 = point1;
      pictureBox129.Location = point131;
      PictureBox pictureBox130 = this.PictureBox130;
      point1 = new Point(-4, -4);
      Point point132 = point1;
      pictureBox130.Location = point132;
      PictureBox pictureBox131 = this.PictureBox131;
      point1 = new Point(-4, -4);
      Point point133 = point1;
      pictureBox131.Location = point133;
      PictureBox pictureBox132 = this.PictureBox132;
      point1 = new Point(-4, -4);
      Point point134 = point1;
      pictureBox132.Location = point134;
      PictureBox pictureBox133 = this.PictureBox133;
      point1 = new Point(-4, -4);
      Point point135 = point1;
      pictureBox133.Location = point135;
      PictureBox pictureBox134 = this.PictureBox134;
      point1 = new Point(-4, -4);
      Point point136 = point1;
      pictureBox134.Location = point136;
      PictureBox pictureBox135 = this.PictureBox135;
      point1 = new Point(-4, -4);
      Point point137 = point1;
      pictureBox135.Location = point137;
      PictureBox pictureBox136 = this.PictureBox136;
      point1 = new Point(-4, -4);
      Point point138 = point1;
      pictureBox136.Location = point138;
      PictureBox pictureBox137 = this.PictureBox137;
      point1 = new Point(-4, -4);
      Point point139 = point1;
      pictureBox137.Location = point139;
      PictureBox pictureBox138 = this.PictureBox138;
      point1 = new Point(-4, -4);
      Point point140 = point1;
      pictureBox138.Location = point140;
      PictureBox pictureBox139 = this.PictureBox139;
      point1 = new Point(-4, -4);
      Point point141 = point1;
      pictureBox139.Location = point141;
      PictureBox pictureBox140 = this.PictureBox140;
      point1 = new Point(-4, -4);
      Point point142 = point1;
      pictureBox140.Location = point142;
      PictureBox pictureBox141 = this.PictureBox141;
      point1 = new Point(-4, -4);
      Point point143 = point1;
      pictureBox141.Location = point143;
      PictureBox pictureBox142 = this.PictureBox142;
      point1 = new Point(-4, -4);
      Point point144 = point1;
      pictureBox142.Location = point144;
      PictureBox pictureBox143 = this.PictureBox143;
      point1 = new Point(-4, -4);
      Point point145 = point1;
      pictureBox143.Location = point145;
      PictureBox pictureBox144 = this.PictureBox144;
      point1 = new Point(-4, -4);
      Point point146 = point1;
      pictureBox144.Location = point146;
      PictureBox pictureBox145 = this.PictureBox145;
      point1 = new Point(-4, -4);
      Point point147 = point1;
      pictureBox145.Location = point147;
      PictureBox pictureBox146 = this.PictureBox146;
      point1 = new Point(-4, -4);
      Point point148 = point1;
      pictureBox146.Location = point148;
      PictureBox pictureBox147 = this.PictureBox147;
      point1 = new Point(-4, -4);
      Point point149 = point1;
      pictureBox147.Location = point149;
      PictureBox pictureBox148 = this.PictureBox148;
      point1 = new Point(-4, -4);
      Point point150 = point1;
      pictureBox148.Location = point150;
      PictureBox pictureBox149 = this.PictureBox149;
      point1 = new Point(-4, -4);
      Point point151 = point1;
      pictureBox149.Location = point151;
      PictureBox pictureBox150 = this.PictureBox150;
      point1 = new Point(-4, -4);
      Point point152 = point1;
      pictureBox150.Location = point152;
      PictureBox pictureBox151 = this.PictureBox151;
      point1 = new Point(-4, -4);
      Point point153 = point1;
      pictureBox151.Location = point153;
      PictureBox pictureBox152 = this.PictureBox152;
      point1 = new Point(-4, -4);
      Point point154 = point1;
      pictureBox152.Location = point154;
      PictureBox pictureBox153 = this.PictureBox153;
      point1 = new Point(-4, -4);
      Point point155 = point1;
      pictureBox153.Location = point155;
      PictureBox pictureBox154 = this.PictureBox154;
      point1 = new Point(-4, -4);
      Point point156 = point1;
      pictureBox154.Location = point156;
      PictureBox pictureBox155 = this.PictureBox155;
      point1 = new Point(-4, -4);
      Point point157 = point1;
      pictureBox155.Location = point157;
      PictureBox pictureBox156 = this.PictureBox156;
      point1 = new Point(-4, -4);
      Point point158 = point1;
      pictureBox156.Location = point158;
      PictureBox pictureBox157 = this.PictureBox157;
      point1 = new Point(-4, -4);
      Point point159 = point1;
      pictureBox157.Location = point159;
      PictureBox pictureBox158 = this.PictureBox158;
      point1 = new Point(-4, -4);
      Point point160 = point1;
      pictureBox158.Location = point160;
      PictureBox pictureBox159 = this.PictureBox159;
      point1 = new Point(-4, -4);
      Point point161 = point1;
      pictureBox159.Location = point161;
      PictureBox pictureBox160 = this.PictureBox160;
      point1 = new Point(-4, -4);
      Point point162 = point1;
      pictureBox160.Location = point162;
      PictureBox pictureBox161 = this.PictureBox161;
      point1 = new Point(-4, -4);
      Point point163 = point1;
      pictureBox161.Location = point163;
      PictureBox pictureBox162 = this.PictureBox162;
      point1 = new Point(-4, -4);
      Point point164 = point1;
      pictureBox162.Location = point164;
      PictureBox pictureBox163 = this.PictureBox163;
      point1 = new Point(-4, -4);
      Point point165 = point1;
      pictureBox163.Location = point165;
      PictureBox pictureBox164 = this.PictureBox164;
      point1 = new Point(-4, -4);
      Point point166 = point1;
      pictureBox164.Location = point166;
      PictureBox pictureBox165 = this.PictureBox165;
      point1 = new Point(-4, -4);
      Point point167 = point1;
      pictureBox165.Location = point167;
      PictureBox pictureBox166 = this.PictureBox166;
      point1 = new Point(-4, -4);
      Point point168 = point1;
      pictureBox166.Location = point168;
      PictureBox pictureBox167 = this.PictureBox167;
      point1 = new Point(-4, -4);
      Point point169 = point1;
      pictureBox167.Location = point169;
      PictureBox pictureBox168 = this.PictureBox168;
      point1 = new Point(-4, -4);
      Point point170 = point1;
      pictureBox168.Location = point170;
      PictureBox pictureBox169 = this.PictureBox169;
      point1 = new Point(-4, -4);
      Point point171 = point1;
      pictureBox169.Location = point171;
      PictureBox pictureBox170 = this.PictureBox170;
      point1 = new Point(-4, -4);
      Point point172 = point1;
      pictureBox170.Location = point172;
      PictureBox pictureBox171 = this.PictureBox171;
      point1 = new Point(-4, -4);
      Point point173 = point1;
      pictureBox171.Location = point173;
      PictureBox pictureBox172 = this.PictureBox172;
      point1 = new Point(-4, -4);
      Point point174 = point1;
      pictureBox172.Location = point174;
      PictureBox pictureBox173 = this.PictureBox173;
      point1 = new Point(-4, -4);
      Point point175 = point1;
      pictureBox173.Location = point175;
      PictureBox pictureBox174 = this.PictureBox174;
      point1 = new Point(-4, -4);
      Point point176 = point1;
      pictureBox174.Location = point176;
      PictureBox pictureBox175 = this.PictureBox175;
      point1 = new Point(-4, -4);
      Point point177 = point1;
      pictureBox175.Location = point177;
      PictureBox pictureBox176 = this.PictureBox176;
      point1 = new Point(-4, -4);
      Point point178 = point1;
      pictureBox176.Location = point178;
      PictureBox pictureBox177 = this.PictureBox177;
      point1 = new Point(-4, -4);
      Point point179 = point1;
      pictureBox177.Location = point179;
      PictureBox pictureBox178 = this.PictureBox178;
      point1 = new Point(-4, -4);
      Point point180 = point1;
      pictureBox178.Location = point180;
      PictureBox pictureBox179 = this.PictureBox179;
      point1 = new Point(-4, -4);
      Point point181 = point1;
      pictureBox179.Location = point181;
      PictureBox pictureBox180 = this.PictureBox180;
      point1 = new Point(-4, -4);
      Point point182 = point1;
      pictureBox180.Location = point182;
      PictureBox pictureBox181 = this.PictureBox181;
      point1 = new Point(-4, -4);
      Point point183 = point1;
      pictureBox181.Location = point183;
      PictureBox pictureBox182 = this.PictureBox182;
      point1 = new Point(-4, -4);
      Point point184 = point1;
      pictureBox182.Location = point184;
      PictureBox pictureBox183 = this.PictureBox183;
      point1 = new Point(-4, -4);
      Point point185 = point1;
      pictureBox183.Location = point185;
      PictureBox pictureBox184 = this.PictureBox184;
      point1 = new Point(-4, -4);
      Point point186 = point1;
      pictureBox184.Location = point186;
      PictureBox pictureBox185 = this.PictureBox185;
      point1 = new Point(-4, -4);
      Point point187 = point1;
      pictureBox185.Location = point187;
      PictureBox pictureBox186 = this.PictureBox186;
      point1 = new Point(-4, -4);
      Point point188 = point1;
      pictureBox186.Location = point188;
      PictureBox pictureBox187 = this.PictureBox187;
      point1 = new Point(-4, -4);
      Point point189 = point1;
      pictureBox187.Location = point189;
      PictureBox pictureBox188 = this.PictureBox188;
      point1 = new Point(-4, -4);
      Point point190 = point1;
      pictureBox188.Location = point190;
      PictureBox pictureBox189 = this.PictureBox189;
      point1 = new Point(-4, -4);
      Point point191 = point1;
      pictureBox189.Location = point191;
      PictureBox pictureBox190 = this.PictureBox190;
      point1 = new Point(-4, -4);
      Point point192 = point1;
      pictureBox190.Location = point192;
      PictureBox pictureBox191 = this.PictureBox191;
      point1 = new Point(-4, -4);
      Point point193 = point1;
      pictureBox191.Location = point193;
      PictureBox pictureBox192 = this.PictureBox192;
      point1 = new Point(-4, -4);
      Point point194 = point1;
      pictureBox192.Location = point194;
      PictureBox pictureBox193 = this.PictureBox193;
      point1 = new Point(-4, -4);
      Point point195 = point1;
      pictureBox193.Location = point195;
      PictureBox pictureBox194 = this.PictureBox194;
      point1 = new Point(-4, -4);
      Point point196 = point1;
      pictureBox194.Location = point196;
      PictureBox pictureBox195 = this.PictureBox195;
      point1 = new Point(-4, -4);
      Point point197 = point1;
      pictureBox195.Location = point197;
      PictureBox pictureBox196 = this.PictureBox196;
      point1 = new Point(-4, -4);
      Point point198 = point1;
      pictureBox196.Location = point198;
      PictureBox pictureBox197 = this.PictureBox197;
      point1 = new Point(-4, -4);
      Point point199 = point1;
      pictureBox197.Location = point199;
      PictureBox pictureBox198 = this.PictureBox198;
      point1 = new Point(-4, -4);
      Point point200 = point1;
      pictureBox198.Location = point200;
      PictureBox pictureBox199 = this.PictureBox199;
      point1 = new Point(-4, -4);
      Point point201 = point1;
      pictureBox199.Location = point201;
      PictureBox pictureBox200 = this.PictureBox200;
      point1 = new Point(-4, -4);
      Point point202 = point1;
      pictureBox200.Location = point202;
      PictureBox pictureBox201 = this.PictureBox201;
      point1 = new Point(-4, -4);
      Point point203 = point1;
      pictureBox201.Location = point203;
      PictureBox pictureBox202 = this.PictureBox202;
      point1 = new Point(-4, -4);
      Point point204 = point1;
      pictureBox202.Location = point204;
      PictureBox pictureBox203 = this.PictureBox203;
      point1 = new Point(-4, -4);
      Point point205 = point1;
      pictureBox203.Location = point205;
      PictureBox pictureBox204 = this.PictureBox204;
      point1 = new Point(-4, -4);
      Point point206 = point1;
      pictureBox204.Location = point206;
      PictureBox pictureBox205 = this.PictureBox205;
      point1 = new Point(-4, -4);
      Point point207 = point1;
      pictureBox205.Location = point207;
      PictureBox pictureBox206 = this.PictureBox206;
      point1 = new Point(-4, -4);
      Point point208 = point1;
      pictureBox206.Location = point208;
      PictureBox pictureBox207 = this.PictureBox207;
      point1 = new Point(-4, -4);
      Point point209 = point1;
      pictureBox207.Location = point209;
      PictureBox pictureBox208 = this.PictureBox208;
      point1 = new Point(-4, -4);
      Point point210 = point1;
      pictureBox208.Location = point210;
      PictureBox pictureBox209 = this.PictureBox209;
      point1 = new Point(-4, -4);
      Point point211 = point1;
      pictureBox209.Location = point211;
      PictureBox pictureBox210 = this.PictureBox210;
      point1 = new Point(-4, -4);
      Point point212 = point1;
      pictureBox210.Location = point212;
      PictureBox pictureBox211 = this.PictureBox211;
      point1 = new Point(-4, -4);
      Point point213 = point1;
      pictureBox211.Location = point213;
      PictureBox pictureBox212 = this.PictureBox212;
      point1 = new Point(-4, -4);
      Point point214 = point1;
      pictureBox212.Location = point214;
      PictureBox pictureBox213 = this.PictureBox213;
      point1 = new Point(-4, -4);
      Point point215 = point1;
      pictureBox213.Location = point215;
      PictureBox pictureBox214 = this.PictureBox214;
      point1 = new Point(-4, -4);
      Point point216 = point1;
      pictureBox214.Location = point216;
      PictureBox pictureBox215 = this.PictureBox215;
      point1 = new Point(-4, -4);
      Point point217 = point1;
      pictureBox215.Location = point217;
      PictureBox pictureBox216 = this.PictureBox216;
      point1 = new Point(-4, -4);
      Point point218 = point1;
      pictureBox216.Location = point218;
      PictureBox pictureBox217 = this.PictureBox217;
      point1 = new Point(-4, -4);
      Point point219 = point1;
      pictureBox217.Location = point219;
      PictureBox pictureBox218 = this.PictureBox218;
      point1 = new Point(-4, -4);
      Point point220 = point1;
      pictureBox218.Location = point220;
      PictureBox pictureBox219 = this.PictureBox219;
      point1 = new Point(-4, -4);
      Point point221 = point1;
      pictureBox219.Location = point221;
      PictureBox pictureBox220 = this.PictureBox220;
      point1 = new Point(-4, -4);
      Point point222 = point1;
      pictureBox220.Location = point222;
      PictureBox pictureBox221 = this.PictureBox221;
      point1 = new Point(-4, -4);
      Point point223 = point1;
      pictureBox221.Location = point223;
      PictureBox pictureBox222 = this.PictureBox222;
      point1 = new Point(-4, -4);
      Point point224 = point1;
      pictureBox222.Location = point224;
      PictureBox pictureBox223 = this.PictureBox223;
      point1 = new Point(-4, -4);
      Point point225 = point1;
      pictureBox223.Location = point225;
      PictureBox pictureBox224 = this.PictureBox224;
      point1 = new Point(-4, -4);
      Point point226 = point1;
      pictureBox224.Location = point226;
      PictureBox pictureBox225 = this.PictureBox225;
      point1 = new Point(-4, -4);
      Point point227 = point1;
      pictureBox225.Location = point227;
      PictureBox pictureBox226 = this.PictureBox226;
      point1 = new Point(-4, -4);
      Point point228 = point1;
      pictureBox226.Location = point228;
      PictureBox pictureBox227 = this.PictureBox227;
      point1 = new Point(-4, -4);
      Point point229 = point1;
      pictureBox227.Location = point229;
      PictureBox pictureBox228 = this.PictureBox228;
      point1 = new Point(-4, -4);
      Point point230 = point1;
      pictureBox228.Location = point230;
      PictureBox pictureBox229 = this.PictureBox229;
      point1 = new Point(-4, -4);
      Point point231 = point1;
      pictureBox229.Location = point231;
      PictureBox pictureBox230 = this.PictureBox230;
      point1 = new Point(-4, -4);
      Point point232 = point1;
      pictureBox230.Location = point232;
      PictureBox pictureBox231 = this.PictureBox231;
      point1 = new Point(-4, -4);
      Point point233 = point1;
      pictureBox231.Location = point233;
      PictureBox pictureBox232 = this.PictureBox232;
      point1 = new Point(-4, -4);
      Point point234 = point1;
      pictureBox232.Location = point234;
      PictureBox pictureBox233 = this.PictureBox233;
      point1 = new Point(-4, -4);
      Point point235 = point1;
      pictureBox233.Location = point235;
      PictureBox pictureBox234 = this.PictureBox234;
      point1 = new Point(-4, -4);
      Point point236 = point1;
      pictureBox234.Location = point236;
      PictureBox pictureBox235 = this.PictureBox235;
      point1 = new Point(-4, -4);
      Point point237 = point1;
      pictureBox235.Location = point237;
      PictureBox pictureBox236 = this.PictureBox236;
      point1 = new Point(-4, -4);
      Point point238 = point1;
      pictureBox236.Location = point238;
      PictureBox pictureBox237 = this.PictureBox237;
      point1 = new Point(-4, -4);
      Point point239 = point1;
      pictureBox237.Location = point239;
      PictureBox pictureBox238 = this.PictureBox238;
      point1 = new Point(-4, -4);
      Point point240 = point1;
      pictureBox238.Location = point240;
      PictureBox pictureBox239 = this.PictureBox239;
      point1 = new Point(-4, -4);
      Point point241 = point1;
      pictureBox239.Location = point241;
      PictureBox pictureBox240 = this.PictureBox240;
      point1 = new Point(-4, -4);
      Point point242 = point1;
      pictureBox240.Location = point242;
      PictureBox pictureBox241 = this.PictureBox241;
      point1 = new Point(-4, -4);
      Point point243 = point1;
      pictureBox241.Location = point243;
      PictureBox pictureBox242 = this.PictureBox242;
      point1 = new Point(-4, -4);
      Point point244 = point1;
      pictureBox242.Location = point244;
      PictureBox pictureBox243 = this.PictureBox243;
      point1 = new Point(-4, -4);
      Point point245 = point1;
      pictureBox243.Location = point245;
      PictureBox pictureBox244 = this.PictureBox244;
      point1 = new Point(-4, -4);
      Point point246 = point1;
      pictureBox244.Location = point246;
      PictureBox pictureBox245 = this.PictureBox245;
      point1 = new Point(-4, -4);
      Point point247 = point1;
      pictureBox245.Location = point247;
      PictureBox pictureBox246 = this.PictureBox246;
      point1 = new Point(-4, -4);
      Point point248 = point1;
      pictureBox246.Location = point248;
      PictureBox pictureBox247 = this.PictureBox247;
      point1 = new Point(-4, -4);
      Point point249 = point1;
      pictureBox247.Location = point249;
      PictureBox pictureBox248 = this.PictureBox248;
      point1 = new Point(-4, -4);
      Point point250 = point1;
      pictureBox248.Location = point250;
      PictureBox pictureBox249 = this.PictureBox249;
      point1 = new Point(-4, -4);
      Point point251 = point1;
      pictureBox249.Location = point251;
      PictureBox pictureBox250 = this.PictureBox250;
      point1 = new Point(-4, -4);
      Point point252 = point1;
      pictureBox250.Location = point252;
      PictureBox pictureBox251 = this.PictureBox251;
      point1 = new Point(-4, -4);
      Point point253 = point1;
      pictureBox251.Location = point253;
      PictureBox pictureBox252 = this.PictureBox252;
      point1 = new Point(-4, -4);
      Point point254 = point1;
      pictureBox252.Location = point254;
      PictureBox pictureBox253 = this.PictureBox253;
      point1 = new Point(-4, -4);
      Point point255 = point1;
      pictureBox253.Location = point255;
      PictureBox pictureBox254 = this.PictureBox254;
      point1 = new Point(-4, -4);
      Point point256 = point1;
      pictureBox254.Location = point256;
      PictureBox pictureBox255 = this.PictureBox255;
      point1 = new Point(-4, -4);
      Point point257 = point1;
      pictureBox255.Location = point257;
      PictureBox pictureBox256 = this.PictureBox256;
      point1 = new Point(-4, -4);
      Point point258 = point1;
      pictureBox256.Location = point258;
      PictureBox pictureBox257 = this.PictureBox257;
      point1 = new Point(-4, -4);
      Point point259 = point1;
      pictureBox257.Location = point259;
      PictureBox pictureBox258 = this.PictureBox258;
      point1 = new Point(-4, -4);
      Point point260 = point1;
      pictureBox258.Location = point260;
      PictureBox pictureBox259 = this.PictureBox259;
      point1 = new Point(-4, -4);
      Point point261 = point1;
      pictureBox259.Location = point261;
      PictureBox pictureBox260 = this.PictureBox260;
      point1 = new Point(-4, -4);
      Point point262 = point1;
      pictureBox260.Location = point262;
      PictureBox pictureBox261 = this.PictureBox261;
      point1 = new Point(-4, -4);
      Point point263 = point1;
      pictureBox261.Location = point263;
      PictureBox pictureBox262 = this.PictureBox262;
      point1 = new Point(-4, -4);
      Point point264 = point1;
      pictureBox262.Location = point264;
      PictureBox pictureBox263 = this.PictureBox263;
      point1 = new Point(-4, -4);
      Point point265 = point1;
      pictureBox263.Location = point265;
      PictureBox pictureBox264 = this.PictureBox264;
      point1 = new Point(-4, -4);
      Point point266 = point1;
      pictureBox264.Location = point266;
      PictureBox pictureBox265 = this.PictureBox265;
      point1 = new Point(-4, -4);
      Point point267 = point1;
      pictureBox265.Location = point267;
      PictureBox pictureBox266 = this.PictureBox266;
      point1 = new Point(-4, -4);
      Point point268 = point1;
      pictureBox266.Location = point268;
      PictureBox pictureBox267 = this.PictureBox267;
      point1 = new Point(-4, -4);
      Point point269 = point1;
      pictureBox267.Location = point269;
      PictureBox pictureBox268 = this.PictureBox268;
      point1 = new Point(-4, -4);
      Point point270 = point1;
      pictureBox268.Location = point270;
      PictureBox pictureBox269 = this.PictureBox269;
      point1 = new Point(-4, -4);
      Point point271 = point1;
      pictureBox269.Location = point271;
      PictureBox pictureBox270 = this.PictureBox270;
      point1 = new Point(-4, -4);
      Point point272 = point1;
      pictureBox270.Location = point272;
      PictureBox pictureBox271 = this.PictureBox271;
      point1 = new Point(-4, -4);
      Point point273 = point1;
      pictureBox271.Location = point273;
      PictureBox pictureBox272 = this.PictureBox272;
      point1 = new Point(-4, -4);
      Point point274 = point1;
      pictureBox272.Location = point274;
      PictureBox pictureBox273 = this.PictureBox273;
      point1 = new Point(-4, -4);
      Point point275 = point1;
      pictureBox273.Location = point275;
      PictureBox pictureBox274 = this.PictureBox274;
      point1 = new Point(-4, -4);
      Point point276 = point1;
      pictureBox274.Location = point276;
      PictureBox pictureBox275 = this.PictureBox275;
      point1 = new Point(-4, -4);
      Point point277 = point1;
      pictureBox275.Location = point277;
      PictureBox pictureBox276 = this.PictureBox276;
      point1 = new Point(-4, -4);
      Point point278 = point1;
      pictureBox276.Location = point278;
      PictureBox pictureBox277 = this.PictureBox277;
      point1 = new Point(-4, -4);
      Point point279 = point1;
      pictureBox277.Location = point279;
      PictureBox pictureBox278 = this.PictureBox278;
      point1 = new Point(-4, -4);
      Point point280 = point1;
      pictureBox278.Location = point280;
      PictureBox pictureBox279 = this.PictureBox279;
      point1 = new Point(-4, -4);
      Point point281 = point1;
      pictureBox279.Location = point281;
      PictureBox pictureBox280 = this.PictureBox280;
      point1 = new Point(-4, -4);
      Point point282 = point1;
      pictureBox280.Location = point282;
      PictureBox pictureBox281 = this.PictureBox281;
      point1 = new Point(-4, -4);
      Point point283 = point1;
      pictureBox281.Location = point283;
      PictureBox pictureBox282 = this.PictureBox282;
      point1 = new Point(-4, -4);
      Point point284 = point1;
      pictureBox282.Location = point284;
      PictureBox pictureBox283 = this.PictureBox283;
      point1 = new Point(-4, -4);
      Point point285 = point1;
      pictureBox283.Location = point285;
      PictureBox pictureBox284 = this.PictureBox284;
      point1 = new Point(-4, -4);
      Point point286 = point1;
      pictureBox284.Location = point286;
      PictureBox pictureBox285 = this.PictureBox285;
      point1 = new Point(-4, -4);
      Point point287 = point1;
      pictureBox285.Location = point287;
      PictureBox pictureBox286 = this.PictureBox286;
      point1 = new Point(-4, -4);
      Point point288 = point1;
      pictureBox286.Location = point288;
      PictureBox pictureBox287 = this.PictureBox287;
      point1 = new Point(-4, -4);
      Point point289 = point1;
      pictureBox287.Location = point289;
      PictureBox pictureBox288 = this.PictureBox288;
      point1 = new Point(-4, -4);
      Point point290 = point1;
      pictureBox288.Location = point290;
      PictureBox pictureBox289 = this.PictureBox289;
      point1 = new Point(-4, -4);
      Point point291 = point1;
      pictureBox289.Location = point291;
      PictureBox pictureBox290 = this.PictureBox290;
      point1 = new Point(-4, -4);
      Point point292 = point1;
      pictureBox290.Location = point292;
      PictureBox pictureBox291 = this.PictureBox291;
      point1 = new Point(-4, -4);
      Point point293 = point1;
      pictureBox291.Location = point293;
      PictureBox pictureBox292 = this.PictureBox292;
      point1 = new Point(-4, -4);
      Point point294 = point1;
      pictureBox292.Location = point294;
      PictureBox pictureBox293 = this.PictureBox293;
      point1 = new Point(-4, -4);
      Point point295 = point1;
      pictureBox293.Location = point295;
      PictureBox pictureBox294 = this.PictureBox294;
      point1 = new Point(-4, -4);
      Point point296 = point1;
      pictureBox294.Location = point296;
      PictureBox pictureBox295 = this.PictureBox295;
      point1 = new Point(-4, -4);
      Point point297 = point1;
      pictureBox295.Location = point297;
      PictureBox pictureBox296 = this.PictureBox296;
      point1 = new Point(-4, -4);
      Point point298 = point1;
      pictureBox296.Location = point298;
      PictureBox pictureBox297 = this.PictureBox297;
      point1 = new Point(-4, -4);
      Point point299 = point1;
      pictureBox297.Location = point299;
      PictureBox pictureBox298 = this.PictureBox298;
      point1 = new Point(-4, -4);
      Point point300 = point1;
      pictureBox298.Location = point300;
      PictureBox pictureBox299 = this.PictureBox299;
      point1 = new Point(-4, -4);
      Point point301 = point1;
      pictureBox299.Location = point301;
      PictureBox pictureBox300 = this.PictureBox300;
      point1 = new Point(-4, -4);
      Point point302 = point1;
      pictureBox300.Location = point302;
      PictureBox pictureBox301 = this.PictureBox301;
      point1 = new Point(-4, -4);
      Point point303 = point1;
      pictureBox301.Location = point303;
      PictureBox pictureBox302 = this.PictureBox302;
      point1 = new Point(-4, -4);
      Point point304 = point1;
      pictureBox302.Location = point304;
      PictureBox pictureBox303 = this.PictureBox303;
      point1 = new Point(-4, -4);
      Point point305 = point1;
      pictureBox303.Location = point305;
      PictureBox pictureBox304 = this.PictureBox304;
      point1 = new Point(-4, -4);
      Point point306 = point1;
      pictureBox304.Location = point306;
      PictureBox pictureBox305 = this.PictureBox305;
      point1 = new Point(-4, -4);
      Point point307 = point1;
      pictureBox305.Location = point307;
      PictureBox pictureBox306 = this.PictureBox306;
      point1 = new Point(-4, -4);
      Point point308 = point1;
      pictureBox306.Location = point308;
      PictureBox pictureBox307 = this.PictureBox307;
      point1 = new Point(-4, -4);
      Point point309 = point1;
      pictureBox307.Location = point309;
      PictureBox pictureBox308 = this.PictureBox308;
      point1 = new Point(-4, -4);
      Point point310 = point1;
      pictureBox308.Location = point310;
      PictureBox pictureBox309 = this.PictureBox309;
      point1 = new Point(-4, -4);
      Point point311 = point1;
      pictureBox309.Location = point311;
      PictureBox pictureBox310 = this.PictureBox310;
      point1 = new Point(-4, -4);
      Point point312 = point1;
      pictureBox310.Location = point312;
      PictureBox pictureBox311 = this.PictureBox311;
      point1 = new Point(-4, -4);
      Point point313 = point1;
      pictureBox311.Location = point313;
      PictureBox pictureBox312 = this.PictureBox312;
      point1 = new Point(-4, -4);
      Point point314 = point1;
      pictureBox312.Location = point314;
      PictureBox pictureBox313 = this.PictureBox313;
      point1 = new Point(-4, -4);
      Point point315 = point1;
      pictureBox313.Location = point315;
      PictureBox pictureBox314 = this.PictureBox314;
      point1 = new Point(-4, -4);
      Point point316 = point1;
      pictureBox314.Location = point316;
      PictureBox pictureBox315 = this.PictureBox315;
      point1 = new Point(-4, -4);
      Point point317 = point1;
      pictureBox315.Location = point317;
      PictureBox pictureBox316 = this.PictureBox316;
      point1 = new Point(-4, -4);
      Point point318 = point1;
      pictureBox316.Location = point318;
      PictureBox pictureBox317 = this.PictureBox317;
      point1 = new Point(-4, -4);
      Point point319 = point1;
      pictureBox317.Location = point319;
      PictureBox pictureBox318 = this.PictureBox318;
      point1 = new Point(-4, -4);
      Point point320 = point1;
      pictureBox318.Location = point320;
      PictureBox pictureBox319 = this.PictureBox319;
      point1 = new Point(-4, -4);
      Point point321 = point1;
      pictureBox319.Location = point321;
      PictureBox pictureBox320 = this.PictureBox320;
      point1 = new Point(-4, -4);
      Point point322 = point1;
      pictureBox320.Location = point322;
      PictureBox pictureBox321 = this.PictureBox321;
      point1 = new Point(-4, -4);
      Point point323 = point1;
      pictureBox321.Location = point323;
      PictureBox pictureBox322 = this.PictureBox322;
      point1 = new Point(-4, -4);
      Point point324 = point1;
      pictureBox322.Location = point324;
      PictureBox pictureBox323 = this.PictureBox323;
      point1 = new Point(-4, -4);
      Point point325 = point1;
      pictureBox323.Location = point325;
      PictureBox pictureBox324 = this.PictureBox324;
      point1 = new Point(-4, -4);
      Point point326 = point1;
      pictureBox324.Location = point326;
      PictureBox pictureBox325 = this.PictureBox325;
      point1 = new Point(-4, -4);
      Point point327 = point1;
      pictureBox325.Location = point327;
      PictureBox pictureBox326 = this.PictureBox326;
      point1 = new Point(-4, -4);
      Point point328 = point1;
      pictureBox326.Location = point328;
      PictureBox pictureBox327 = this.PictureBox327;
      point1 = new Point(-4, -4);
      Point point329 = point1;
      pictureBox327.Location = point329;
      PictureBox pictureBox328 = this.PictureBox328;
      point1 = new Point(-4, -4);
      Point point330 = point1;
      pictureBox328.Location = point330;
      PictureBox pictureBox329 = this.PictureBox329;
      point1 = new Point(-4, -4);
      Point point331 = point1;
      pictureBox329.Location = point331;
      PictureBox pictureBox330 = this.PictureBox330;
      point1 = new Point(-4, -4);
      Point point332 = point1;
      pictureBox330.Location = point332;
      PictureBox pictureBox331 = this.PictureBox331;
      point1 = new Point(-4, -4);
      Point point333 = point1;
      pictureBox331.Location = point333;
      PictureBox pictureBox332 = this.PictureBox332;
      point1 = new Point(-4, -4);
      Point point334 = point1;
      pictureBox332.Location = point334;
      PictureBox pictureBox333 = this.PictureBox333;
      point1 = new Point(-4, -4);
      Point point335 = point1;
      pictureBox333.Location = point335;
      PictureBox pictureBox334 = this.PictureBox334;
      point1 = new Point(-4, -4);
      Point point336 = point1;
      pictureBox334.Location = point336;
      PictureBox pictureBox335 = this.PictureBox335;
      point1 = new Point(-4, -4);
      Point point337 = point1;
      pictureBox335.Location = point337;
      PictureBox pictureBox336 = this.PictureBox336;
      point1 = new Point(-4, -4);
      Point point338 = point1;
      pictureBox336.Location = point338;
      PictureBox pictureBox337 = this.PictureBox337;
      point1 = new Point(-4, -4);
      Point point339 = point1;
      pictureBox337.Location = point339;
      PictureBox pictureBox338 = this.PictureBox338;
      point1 = new Point(-4, -4);
      Point point340 = point1;
      pictureBox338.Location = point340;
      PictureBox pictureBox339 = this.PictureBox339;
      point1 = new Point(-4, -4);
      Point point341 = point1;
      pictureBox339.Location = point341;
      PictureBox pictureBox340 = this.PictureBox340;
      point1 = new Point(-4, -4);
      Point point342 = point1;
      pictureBox340.Location = point342;
      PictureBox pictureBox341 = this.PictureBox341;
      point1 = new Point(-4, -4);
      Point point343 = point1;
      pictureBox341.Location = point343;
      PictureBox pictureBox342 = this.PictureBox342;
      point1 = new Point(-4, -4);
      Point point344 = point1;
      pictureBox342.Location = point344;
      PictureBox pictureBox343 = this.PictureBox343;
      point1 = new Point(-4, -4);
      Point point345 = point1;
      pictureBox343.Location = point345;
      PictureBox pictureBox344 = this.PictureBox344;
      point1 = new Point(-4, -4);
      Point point346 = point1;
      pictureBox344.Location = point346;
      PictureBox pictureBox345 = this.PictureBox345;
      point1 = new Point(-4, -4);
      Point point347 = point1;
      pictureBox345.Location = point347;
      PictureBox pictureBox346 = this.PictureBox346;
      point1 = new Point(-4, -4);
      Point point348 = point1;
      pictureBox346.Location = point348;
      PictureBox pictureBox347 = this.PictureBox347;
      point1 = new Point(-4, -4);
      Point point349 = point1;
      pictureBox347.Location = point349;
      PictureBox pictureBox348 = this.PictureBox348;
      point1 = new Point(-4, -4);
      Point point350 = point1;
      pictureBox348.Location = point350;
      PictureBox pictureBox349 = this.PictureBox349;
      point1 = new Point(-4, -4);
      Point point351 = point1;
      pictureBox349.Location = point351;
      PictureBox pictureBox350 = this.PictureBox350;
      point1 = new Point(-4, -4);
      Point point352 = point1;
      pictureBox350.Location = point352;
      PictureBox pictureBox351 = this.PictureBox351;
      point1 = new Point(-4, -4);
      Point point353 = point1;
      pictureBox351.Location = point353;
      PictureBox pictureBox352 = this.PictureBox352;
      point1 = new Point(-4, -4);
      Point point354 = point1;
      pictureBox352.Location = point354;
      PictureBox pictureBox353 = this.PictureBox353;
      point1 = new Point(-4, -4);
      Point point355 = point1;
      pictureBox353.Location = point355;
      PictureBox pictureBox354 = this.PictureBox354;
      point1 = new Point(-4, -4);
      Point point356 = point1;
      pictureBox354.Location = point356;
      PictureBox pictureBox355 = this.PictureBox355;
      point1 = new Point(-4, -4);
      Point point357 = point1;
      pictureBox355.Location = point357;
      PictureBox pictureBox356 = this.PictureBox356;
      point1 = new Point(-4, -4);
      Point point358 = point1;
      pictureBox356.Location = point358;
      PictureBox pictureBox357 = this.PictureBox357;
      point1 = new Point(-4, -4);
      Point point359 = point1;
      pictureBox357.Location = point359;
      PictureBox pictureBox358 = this.PictureBox358;
      point1 = new Point(-4, -4);
      Point point360 = point1;
      pictureBox358.Location = point360;
      PictureBox pictureBox359 = this.PictureBox359;
      point1 = new Point(-4, -4);
      Point point361 = point1;
      pictureBox359.Location = point361;
      PictureBox pictureBox360 = this.PictureBox360;
      point1 = new Point(-4, -4);
      Point point362 = point1;
      pictureBox360.Location = point362;
      PictureBox pictureBox361 = this.PictureBox361;
      point1 = new Point(-4, -4);
      Point point363 = point1;
      pictureBox361.Location = point363;
      PictureBox pictureBox362 = this.PictureBox362;
      point1 = new Point(-4, -4);
      Point point364 = point1;
      pictureBox362.Location = point364;
      PictureBox pictureBox363 = this.PictureBox363;
      point1 = new Point(-4, -4);
      Point point365 = point1;
      pictureBox363.Location = point365;
      PictureBox pictureBox364 = this.PictureBox364;
      point1 = new Point(-4, -4);
      Point point366 = point1;
      pictureBox364.Location = point366;
      PictureBox pictureBox365 = this.PictureBox365;
      point1 = new Point(-4, -4);
      Point point367 = point1;
      pictureBox365.Location = point367;
      PictureBox pictureBox366 = this.PictureBox366;
      point1 = new Point(-4, -4);
      Point point368 = point1;
      pictureBox366.Location = point368;
      PictureBox pictureBox367 = this.PictureBox367;
      point1 = new Point(-4, -4);
      Point point369 = point1;
      pictureBox367.Location = point369;
      PictureBox pictureBox368 = this.PictureBox368;
      point1 = new Point(-4, -4);
      Point point370 = point1;
      pictureBox368.Location = point370;
      PictureBox pictureBox369 = this.PictureBox369;
      point1 = new Point(-4, -4);
      Point point371 = point1;
      pictureBox369.Location = point371;
      PictureBox pictureBox370 = this.PictureBox370;
      point1 = new Point(-4, -4);
      Point point372 = point1;
      pictureBox370.Location = point372;
      PictureBox pictureBox371 = this.PictureBox371;
      point1 = new Point(-4, -4);
      Point point373 = point1;
      pictureBox371.Location = point373;
      PictureBox pictureBox372 = this.PictureBox372;
      point1 = new Point(-4, -4);
      Point point374 = point1;
      pictureBox372.Location = point374;
      PictureBox pictureBox373 = this.PictureBox373;
      point1 = new Point(-4, -4);
      Point point375 = point1;
      pictureBox373.Location = point375;
      PictureBox pictureBox374 = this.PictureBox374;
      point1 = new Point(-4, -4);
      Point point376 = point1;
      pictureBox374.Location = point376;
      PictureBox pictureBox375 = this.PictureBox375;
      point1 = new Point(-4, -4);
      Point point377 = point1;
      pictureBox375.Location = point377;
      PictureBox pictureBox376 = this.PictureBox376;
      point1 = new Point(-4, -4);
      Point point378 = point1;
      pictureBox376.Location = point378;
      PictureBox pictureBox377 = this.PictureBox377;
      point1 = new Point(-4, -4);
      Point point379 = point1;
      pictureBox377.Location = point379;
      PictureBox pictureBox378 = this.PictureBox378;
      point1 = new Point(-4, -4);
      Point point380 = point1;
      pictureBox378.Location = point380;
      PictureBox pictureBox379 = this.PictureBox379;
      point1 = new Point(-4, -4);
      Point point381 = point1;
      pictureBox379.Location = point381;
      PictureBox pictureBox380 = this.PictureBox380;
      point1 = new Point(-4, -4);
      Point point382 = point1;
      pictureBox380.Location = point382;
      PictureBox pictureBox381 = this.PictureBox381;
      point1 = new Point(-4, -4);
      Point point383 = point1;
      pictureBox381.Location = point383;
      PictureBox pictureBox382 = this.PictureBox382;
      point1 = new Point(-4, -4);
      Point point384 = point1;
      pictureBox382.Location = point384;
      PictureBox pictureBox383 = this.PictureBox383;
      point1 = new Point(-4, -4);
      Point point385 = point1;
      pictureBox383.Location = point385;
      PictureBox pictureBox384 = this.PictureBox384;
      point1 = new Point(-4, -4);
      Point point386 = point1;
      pictureBox384.Location = point386;
      PictureBox pictureBox385 = this.PictureBox385;
      point1 = new Point(-4, -4);
      Point point387 = point1;
      pictureBox385.Location = point387;
      PictureBox pictureBox386 = this.PictureBox386;
      point1 = new Point(-4, -4);
      Point point388 = point1;
      pictureBox386.Location = point388;
      PictureBox pictureBox387 = this.PictureBox387;
      point1 = new Point(-4, -4);
      Point point389 = point1;
      pictureBox387.Location = point389;
      PictureBox pictureBox388 = this.PictureBox388;
      point1 = new Point(-4, -4);
      Point point390 = point1;
      pictureBox388.Location = point390;
      PictureBox pictureBox389 = this.PictureBox389;
      point1 = new Point(-4, -4);
      Point point391 = point1;
      pictureBox389.Location = point391;
      PictureBox pictureBox390 = this.PictureBox390;
      point1 = new Point(-4, -4);
      Point point392 = point1;
      pictureBox390.Location = point392;
      PictureBox pictureBox391 = this.PictureBox391;
      point1 = new Point(-4, -4);
      Point point393 = point1;
      pictureBox391.Location = point393;
      PictureBox pictureBox392 = this.PictureBox392;
      point1 = new Point(-4, -4);
      Point point394 = point1;
      pictureBox392.Location = point394;
      PictureBox pictureBox393 = this.PictureBox393;
      point1 = new Point(-4, -4);
      Point point395 = point1;
      pictureBox393.Location = point395;
      PictureBox pictureBox394 = this.PictureBox394;
      point1 = new Point(-4, -4);
      Point point396 = point1;
      pictureBox394.Location = point396;
      PictureBox pictureBox395 = this.PictureBox395;
      point1 = new Point(-4, -4);
      Point point397 = point1;
      pictureBox395.Location = point397;
      PictureBox pictureBox396 = this.PictureBox396;
      point1 = new Point(-4, -4);
      Point point398 = point1;
      pictureBox396.Location = point398;
      PictureBox pictureBox397 = this.PictureBox397;
      point1 = new Point(-4, -4);
      Point point399 = point1;
      pictureBox397.Location = point399;
      PictureBox pictureBox398 = this.PictureBox398;
      point1 = new Point(-4, -4);
      Point point400 = point1;
      pictureBox398.Location = point400;
      PictureBox pictureBox399 = this.PictureBox399;
      point1 = new Point(-4, -4);
      Point point401 = point1;
      pictureBox399.Location = point401;
      PictureBox pictureBox400 = this.PictureBox400;
      point1 = new Point(-4, -4);
      Point point402 = point1;
      pictureBox400.Location = point402;
      PictureBox pictureBox401 = this.PictureBox401;
      point1 = new Point(-4, -4);
      Point point403 = point1;
      pictureBox401.Location = point403;
      PictureBox pictureBox402 = this.PictureBox402;
      point1 = new Point(-4, -4);
      Point point404 = point1;
      pictureBox402.Location = point404;
      PictureBox pictureBox403 = this.PictureBox403;
      point1 = new Point(-4, -4);
      Point point405 = point1;
      pictureBox403.Location = point405;
      PictureBox pictureBox404 = this.PictureBox404;
      point1 = new Point(-4, -4);
      Point point406 = point1;
      pictureBox404.Location = point406;
      PictureBox pictureBox405 = this.PictureBox405;
      point1 = new Point(-4, -4);
      Point point407 = point1;
      pictureBox405.Location = point407;
      PictureBox pictureBox406 = this.PictureBox406;
      point1 = new Point(-4, -4);
      Point point408 = point1;
      pictureBox406.Location = point408;
      PictureBox pictureBox407 = this.PictureBox407;
      point1 = new Point(-4, -4);
      Point point409 = point1;
      pictureBox407.Location = point409;
      PictureBox pictureBox408 = this.PictureBox408;
      point1 = new Point(-4, -4);
      Point point410 = point1;
      pictureBox408.Location = point410;
      PictureBox pictureBox409 = this.PictureBox409;
      point1 = new Point(-4, -4);
      Point point411 = point1;
      pictureBox409.Location = point411;
      PictureBox pictureBox410 = this.PictureBox410;
      point1 = new Point(-4, -4);
      Point point412 = point1;
      pictureBox410.Location = point412;
      PictureBox pictureBox411 = this.PictureBox411;
      point1 = new Point(-4, -4);
      Point point413 = point1;
      pictureBox411.Location = point413;
      PictureBox pictureBox412 = this.PictureBox412;
      point1 = new Point(-4, -4);
      Point point414 = point1;
      pictureBox412.Location = point414;
      PictureBox pictureBox413 = this.PictureBox413;
      point1 = new Point(-4, -4);
      Point point415 = point1;
      pictureBox413.Location = point415;
      PictureBox pictureBox414 = this.PictureBox414;
      point1 = new Point(-4, -4);
      Point point416 = point1;
      pictureBox414.Location = point416;
      PictureBox pictureBox415 = this.PictureBox415;
      point1 = new Point(-4, -4);
      Point point417 = point1;
      pictureBox415.Location = point417;
      PictureBox pictureBox416 = this.PictureBox416;
      point1 = new Point(-4, -4);
      Point point418 = point1;
      pictureBox416.Location = point418;
      PictureBox pictureBox417 = this.PictureBox417;
      point1 = new Point(-4, -4);
      Point point419 = point1;
      pictureBox417.Location = point419;
      PictureBox pictureBox418 = this.PictureBox418;
      point1 = new Point(-4, -4);
      Point point420 = point1;
      pictureBox418.Location = point420;
      PictureBox pictureBox419 = this.PictureBox419;
      point1 = new Point(-4, -4);
      Point point421 = point1;
      pictureBox419.Location = point421;
      PictureBox pictureBox420 = this.PictureBox420;
      point1 = new Point(-4, -4);
      Point point422 = point1;
      pictureBox420.Location = point422;
      PictureBox pictureBox421 = this.PictureBox421;
      point1 = new Point(-4, -4);
      Point point423 = point1;
      pictureBox421.Location = point423;
      PictureBox pictureBox422 = this.PictureBox422;
      point1 = new Point(-4, -4);
      Point point424 = point1;
      pictureBox422.Location = point424;
      PictureBox pictureBox423 = this.PictureBox423;
      point1 = new Point(-4, -4);
      Point point425 = point1;
      pictureBox423.Location = point425;
      PictureBox pictureBox424 = this.PictureBox424;
      point1 = new Point(-4, -4);
      Point point426 = point1;
      pictureBox424.Location = point426;
      PictureBox pictureBox425 = this.PictureBox425;
      point1 = new Point(-4, -4);
      Point point427 = point1;
      pictureBox425.Location = point427;
      PictureBox pictureBox426 = this.PictureBox426;
      point1 = new Point(-4, -4);
      Point point428 = point1;
      pictureBox426.Location = point428;
      PictureBox pictureBox427 = this.PictureBox427;
      point1 = new Point(-4, -4);
      Point point429 = point1;
      pictureBox427.Location = point429;
      PictureBox pictureBox428 = this.PictureBox428;
      point1 = new Point(-4, -4);
      Point point430 = point1;
      pictureBox428.Location = point430;
      PictureBox pictureBox429 = this.PictureBox429;
      point1 = new Point(-4, -4);
      Point point431 = point1;
      pictureBox429.Location = point431;
      PictureBox pictureBox430 = this.PictureBox430;
      point1 = new Point(-4, -4);
      Point point432 = point1;
      pictureBox430.Location = point432;
      PictureBox pictureBox431 = this.PictureBox431;
      point1 = new Point(-4, -4);
      Point point433 = point1;
      pictureBox431.Location = point433;
      PictureBox pictureBox432 = this.PictureBox432;
      point1 = new Point(-4, -4);
      Point point434 = point1;
      pictureBox432.Location = point434;
      PictureBox pictureBox433 = this.PictureBox433;
      point1 = new Point(-4, -4);
      Point point435 = point1;
      pictureBox433.Location = point435;
      PictureBox pictureBox434 = this.PictureBox434;
      point1 = new Point(-4, -4);
      Point point436 = point1;
      pictureBox434.Location = point436;
      PictureBox pictureBox435 = this.PictureBox435;
      point1 = new Point(-4, -4);
      Point point437 = point1;
      pictureBox435.Location = point437;
      PictureBox pictureBox436 = this.PictureBox436;
      point1 = new Point(-4, -4);
      Point point438 = point1;
      pictureBox436.Location = point438;
      PictureBox pictureBox437 = this.PictureBox437;
      point1 = new Point(-4, -4);
      Point point439 = point1;
      pictureBox437.Location = point439;
      PictureBox pictureBox438 = this.PictureBox438;
      point1 = new Point(-4, -4);
      Point point440 = point1;
      pictureBox438.Location = point440;
      PictureBox pictureBox439 = this.PictureBox439;
      point1 = new Point(-4, -4);
      Point point441 = point1;
      pictureBox439.Location = point441;
      PictureBox pictureBox440 = this.PictureBox440;
      point1 = new Point(-4, -4);
      Point point442 = point1;
      pictureBox440.Location = point442;
      PictureBox pictureBox441 = this.PictureBox441;
      point1 = new Point(-4, -4);
      Point point443 = point1;
      pictureBox441.Location = point443;
      PictureBox pictureBox442 = this.PictureBox442;
      point1 = new Point(-4, -4);
      Point point444 = point1;
      pictureBox442.Location = point444;
      PictureBox pictureBox443 = this.PictureBox443;
      point1 = new Point(-4, -4);
      Point point445 = point1;
      pictureBox443.Location = point445;
      PictureBox pictureBox444 = this.PictureBox444;
      point1 = new Point(-4, -4);
      Point point446 = point1;
      pictureBox444.Location = point446;
      PictureBox pictureBox445 = this.PictureBox445;
      point1 = new Point(-4, -4);
      Point point447 = point1;
      pictureBox445.Location = point447;
      PictureBox pictureBox446 = this.PictureBox446;
      point1 = new Point(-4, -4);
      Point point448 = point1;
      pictureBox446.Location = point448;
      PictureBox pictureBox447 = this.PictureBox447;
      point1 = new Point(-4, -4);
      Point point449 = point1;
      pictureBox447.Location = point449;
      PictureBox pictureBox448 = this.PictureBox448;
      point1 = new Point(-4, -4);
      Point point450 = point1;
      pictureBox448.Location = point450;
      PictureBox pictureBox449 = this.PictureBox449;
      point1 = new Point(-4, -4);
      Point point451 = point1;
      pictureBox449.Location = point451;
      PictureBox pictureBox450 = this.PictureBox450;
      point1 = new Point(-4, -4);
      Point point452 = point1;
      pictureBox450.Location = point452;
      PictureBox pictureBox451 = this.PictureBox451;
      point1 = new Point(-4, -4);
      Point point453 = point1;
      pictureBox451.Location = point453;
      PictureBox pictureBox452 = this.PictureBox452;
      point1 = new Point(-4, -4);
      Point point454 = point1;
      pictureBox452.Location = point454;
      PictureBox pictureBox453 = this.PictureBox453;
      point1 = new Point(-4, -4);
      Point point455 = point1;
      pictureBox453.Location = point455;
      PictureBox pictureBox454 = this.PictureBox454;
      point1 = new Point(-4, -4);
      Point point456 = point1;
      pictureBox454.Location = point456;
      PictureBox pictureBox455 = this.PictureBox455;
      point1 = new Point(-4, -4);
      Point point457 = point1;
      pictureBox455.Location = point457;
      PictureBox pictureBox456 = this.PictureBox456;
      point1 = new Point(-4, -4);
      Point point458 = point1;
      pictureBox456.Location = point458;
      PictureBox pictureBox457 = this.PictureBox457;
      point1 = new Point(-4, -4);
      Point point459 = point1;
      pictureBox457.Location = point459;
      PictureBox pictureBox458 = this.PictureBox458;
      point1 = new Point(-4, -4);
      Point point460 = point1;
      pictureBox458.Location = point460;
      PictureBox pictureBox459 = this.PictureBox459;
      point1 = new Point(-4, -4);
      Point point461 = point1;
      pictureBox459.Location = point461;
      PictureBox pictureBox460 = this.PictureBox460;
      point1 = new Point(-4, -4);
      Point point462 = point1;
      pictureBox460.Location = point462;
      PictureBox pictureBox461 = this.PictureBox461;
      point1 = new Point(-4, -4);
      Point point463 = point1;
      pictureBox461.Location = point463;
      PictureBox pictureBox462 = this.PictureBox462;
      point1 = new Point(-4, -4);
      Point point464 = point1;
      pictureBox462.Location = point464;
      PictureBox pictureBox463 = this.PictureBox463;
      point1 = new Point(-4, -4);
      Point point465 = point1;
      pictureBox463.Location = point465;
      PictureBox pictureBox464 = this.PictureBox464;
      point1 = new Point(-4, -4);
      Point point466 = point1;
      pictureBox464.Location = point466;
      PictureBox pictureBox465 = this.PictureBox465;
      point1 = new Point(-4, -4);
      Point point467 = point1;
      pictureBox465.Location = point467;
      PictureBox pictureBox466 = this.PictureBox466;
      point1 = new Point(-4, -4);
      Point point468 = point1;
      pictureBox466.Location = point468;
      PictureBox pictureBox467 = this.PictureBox467;
      point1 = new Point(-4, -4);
      Point point469 = point1;
      pictureBox467.Location = point469;
      PictureBox pictureBox468 = this.PictureBox468;
      point1 = new Point(-4, -4);
      Point point470 = point1;
      pictureBox468.Location = point470;
      PictureBox pictureBox469 = this.PictureBox469;
      point1 = new Point(-4, -4);
      Point point471 = point1;
      pictureBox469.Location = point471;
      PictureBox pictureBox470 = this.PictureBox470;
      point1 = new Point(-4, -4);
      Point point472 = point1;
      pictureBox470.Location = point472;
      PictureBox pictureBox471 = this.PictureBox471;
      point1 = new Point(-4, -4);
      Point point473 = point1;
      pictureBox471.Location = point473;
      PictureBox pictureBox472 = this.PictureBox472;
      point1 = new Point(-4, -4);
      Point point474 = point1;
      pictureBox472.Location = point474;
      PictureBox pictureBox473 = this.PictureBox473;
      point1 = new Point(-4, -4);
      Point point475 = point1;
      pictureBox473.Location = point475;
      PictureBox pictureBox474 = this.PictureBox474;
      point1 = new Point(-4, -4);
      Point point476 = point1;
      pictureBox474.Location = point476;
      PictureBox pictureBox475 = this.PictureBox475;
      point1 = new Point(-4, -4);
      Point point477 = point1;
      pictureBox475.Location = point477;
      PictureBox pictureBox476 = this.PictureBox476;
      point1 = new Point(-4, -4);
      Point point478 = point1;
      pictureBox476.Location = point478;
      PictureBox pictureBox477 = this.PictureBox477;
      point1 = new Point(-4, -4);
      Point point479 = point1;
      pictureBox477.Location = point479;
      PictureBox pictureBox478 = this.PictureBox478;
      point1 = new Point(-4, -4);
      Point point480 = point1;
      pictureBox478.Location = point480;
      PictureBox pictureBox479 = this.PictureBox479;
      point1 = new Point(-4, -4);
      Point point481 = point1;
      pictureBox479.Location = point481;
      PictureBox pictureBox480 = this.PictureBox480;
      point1 = new Point(-4, -4);
      Point point482 = point1;
      pictureBox480.Location = point482;
      PictureBox pictureBox481 = this.PictureBox481;
      point1 = new Point(-4, -4);
      Point point483 = point1;
      pictureBox481.Location = point483;
      PictureBox pictureBox482 = this.PictureBox482;
      point1 = new Point(-4, -4);
      Point point484 = point1;
      pictureBox482.Location = point484;
      PictureBox pictureBox483 = this.PictureBox483;
      point1 = new Point(-4, -4);
      Point point485 = point1;
      pictureBox483.Location = point485;
      PictureBox pictureBox484 = this.PictureBox484;
      point1 = new Point(-4, -4);
      Point point486 = point1;
      pictureBox484.Location = point486;
      PictureBox pictureBox485 = this.PictureBox485;
      point1 = new Point(-4, -4);
      Point point487 = point1;
      pictureBox485.Location = point487;
      PictureBox pictureBox486 = this.PictureBox486;
      point1 = new Point(-4, -4);
      Point point488 = point1;
      pictureBox486.Location = point488;
      PictureBox pictureBox487 = this.PictureBox487;
      point1 = new Point(-4, -4);
      Point point489 = point1;
      pictureBox487.Location = point489;
      PictureBox pictureBox488 = this.PictureBox488;
      point1 = new Point(-4, -4);
      Point point490 = point1;
      pictureBox488.Location = point490;
      PictureBox pictureBox489 = this.PictureBox489;
      point1 = new Point(-4, -4);
      Point point491 = point1;
      pictureBox489.Location = point491;
      PictureBox pictureBox490 = this.PictureBox490;
      point1 = new Point(-4, -4);
      Point point492 = point1;
      pictureBox490.Location = point492;
      PictureBox pictureBox491 = this.PictureBox491;
      point1 = new Point(-4, -4);
      Point point493 = point1;
      pictureBox491.Location = point493;
      PictureBox pictureBox492 = this.PictureBox492;
      point1 = new Point(-4, -4);
      Point point494 = point1;
      pictureBox492.Location = point494;
      PictureBox pictureBox493 = this.PictureBox493;
      point1 = new Point(-4, -4);
      Point point495 = point1;
      pictureBox493.Location = point495;
      PictureBox pictureBox494 = this.PictureBox494;
      point1 = new Point(-4, -4);
      Point point496 = point1;
      pictureBox494.Location = point496;
      PictureBox pictureBox495 = this.PictureBox495;
      point1 = new Point(-4, -4);
      Point point497 = point1;
      pictureBox495.Location = point497;
      PictureBox pictureBox496 = this.PictureBox496;
      point1 = new Point(-4, -4);
      Point point498 = point1;
      pictureBox496.Location = point498;
      PictureBox pictureBox497 = this.PictureBox497;
      point1 = new Point(-4, -4);
      Point point499 = point1;
      pictureBox497.Location = point499;
      PictureBox pictureBox498 = this.PictureBox498;
      point1 = new Point(-4, -4);
      Point point500 = point1;
      pictureBox498.Location = point500;
      PictureBox pictureBox500 = this.PictureBox500;
      point1 = new Point(-4, -4);
      Point point501 = point1;
      pictureBox500.Location = point501;
      return (object) true;
    }

    public object DatosPJSelect()
    {
      if (Operators.CompareString(AccountData.CurrentCharacter.string_1, "ALL", false) != 0)
      {
        this.ResetXY();
        Color color = Color.Transparent;
        this.Acount.Text = AccountData.CurrentCharacter.string_0;
        this.Personajes.Text = AccountData.CurrentCharacter.string_1;
        this.level.Text = AccountData.CurrentCharacter.string_2;
        this.X.Text = Conversions.ToString(AccountData.CurrentCharacter.int_1);
        this.Y.Text = Conversions.ToString(AccountData.CurrentCharacter.int_2);
        this.Baneado.Text = Conversions.ToDouble(AccountData.CurrentCharacter.string_15) != 1.0 ? "No Baned" : "Baned";
        string str1 = Conversions.ToString(checked (AccountData.CurrentCharacter.int_1 * 2 + MapImageHelper.int_0));
        string str2 = Conversions.ToString(checked (512 - AccountData.CurrentCharacter.int_2 * 2 + MapImageHelper.int_1));
        this.PictureBox1.Visible = true;
        this.PictureBox1.Location = new Point(Conversions.ToInteger(str1), Conversions.ToInteger(str2));
        if (Conversions.ToDouble(AccountData.CurrentCharacter.string_15) <= 2.0)
          color = Color.DeepSkyBlue;
        if (Conversions.ToDouble(AccountData.CurrentCharacter.string_15) >= 3.0 & Conversions.ToDouble(AccountData.CurrentCharacter.string_15) <= 4.0)
          color = Color.Silver;
        if (Conversions.ToDouble(AccountData.CurrentCharacter.string_15) >= 5.0)
          color = Color.Red;
        this.PictureBox1.BackColor = color;
        this.Emergente.SetToolTip((Control) this.PictureBox1, AccountData.CurrentCharacter.string_1);
      }
      else
      {
        this.Acount.Text = "";
        this.Personajes.Text = "";
        this.level.Text = "";
        this.Baneado.Text = "";
        this.X.Text = "";
        this.Y.Text = "";
      }
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

    private void method_4()
    {
      ConnectionManager.smethod_1();
      try
      {
        SqlConnectionPool.sqlConnection_2.Open();
        SqlConnectionPool.sqlCommand_2.Connection = SqlConnectionPool.sqlConnection_2;
        int num1 = 0;
        string str = "";
        if (this.Baneados.Checked)
          str = "CtlCode='1' OR CtlCode='17' AND";
        if (this.GameMaster.Checked)
          str = "CtlCode='32' OR CtlCode='8' AND";
        if (this.PH.Checked)
          checked { ++num1; }
        if (this.PN.Checked)
          checked { ++num1; }
        if (this.PK.Checked)
          checked { ++num1; }
        if (num1 == 1)
        {
          if (this.PH.Checked)
            SqlConnectionPool.sqlCommand_2.CommandText = "SELECT * FROM Character WHERE " + str + " PkLevel<='2' AND MapNumber='" + Conversions.ToString(this.ListaMapas.SelectedIndex) + "'";
          if (this.PN.Checked)
            SqlConnectionPool.sqlCommand_2.CommandText = "SELECT * FROM Character WHERE " + str + " (PkLevel>='3' AND PkLevel<='4') AND MapNumber='" + Conversions.ToString(this.ListaMapas.SelectedIndex) + "'";
          if (this.PK.Checked)
            SqlConnectionPool.sqlCommand_2.CommandText = "SELECT * FROM Character WHERE " + str + " PkLevel>='5' AND MapNumber='" + Conversions.ToString(this.ListaMapas.SelectedIndex) + "'";
        }
        if (num1 == 2)
        {
          if (this.PH.Checked & this.PN.Checked)
            SqlConnectionPool.sqlCommand_2.CommandText = "SELECT * FROM Character WHERE " + str + " PkLevel<='4' AND MapNumber='" + Conversions.ToString(this.ListaMapas.SelectedIndex) + "'";
          if (this.PN.Checked & this.PK.Checked)
            SqlConnectionPool.sqlCommand_2.CommandText = "SELECT * FROM Character WHERE " + str + " PkLevel>='3' AND MapNumber='" + Conversions.ToString(this.ListaMapas.SelectedIndex) + "'";
          if (this.PK.Checked & this.PH.Checked)
            SqlConnectionPool.sqlCommand_2.CommandText = "SELECT * FROM Character WHERE " + str + " (PkLevel<='2' OR PkLevel>='5') AND MapNumber='" + Conversions.ToString(this.ListaMapas.SelectedIndex) + "'";
        }
        if (num1 == 3)
          SqlConnectionPool.sqlCommand_2.CommandText = "SELECT * FROM Character WHERE " + str + " MapNumber='" + Conversions.ToString(this.ListaMapas.SelectedIndex) + "'";
        this.PJOnline.Items.Clear();
        SqlConnectionPool.sqlDataReader_2 = SqlConnectionPool.sqlCommand_2.ExecuteReader();
        while (SqlConnectionPool.sqlDataReader_2.Read())
          this.PJOnline.Items.Add((object) SqlConnectionPool.sqlDataReader_2[1].ToString());
        SqlConnectionPool.sqlDataReader_2.Close();
        int num2 = 1;
        this.ResetXY();
        this.OcultarXY();
        Color color = Color.Transparent;
        SqlConnectionPool.sqlDataReader_2 = SqlConnectionPool.sqlCommand_2.ExecuteReader();
        while (SqlConnectionPool.sqlDataReader_2.Read())
        {
          this.Acount.Text = SqlConnectionPool.sqlDataReader_2[0].ToString();
          this.Personajes.Text = SqlConnectionPool.sqlDataReader_2[1].ToString();
          this.level.Text = SqlConnectionPool.sqlDataReader_2[2].ToString();
          this.X.Text = SqlConnectionPool.sqlDataReader_2[18].ToString();
          this.Y.Text = SqlConnectionPool.sqlDataReader_2[19].ToString();
          this.Baneado.Text = Conversions.ToDouble(SqlConnectionPool.sqlDataReader_2[26].ToString()) != 1.0 ? "No Baned" : "Baned";
          int x = checked ((int) Math.Round(unchecked (Conversions.ToDouble(SqlConnectionPool.sqlDataReader_2[18].ToString()) * 2.0 + (double) MapImageHelper.int_0)));
          int y = checked ((int) Math.Round(unchecked (512.0 - Conversions.ToDouble(SqlConnectionPool.sqlDataReader_2[19].ToString()) * 2.0 + (double) MapImageHelper.int_1)));
          if (Conversions.ToDouble(SqlConnectionPool.sqlDataReader_2[22].ToString()) <= 2.0)
            color = Color.DeepSkyBlue;
          if (Conversions.ToDouble(SqlConnectionPool.sqlDataReader_2[22].ToString()) >= 3.0 & Conversions.ToDouble(SqlConnectionPool.sqlDataReader_2[22].ToString()) <= 4.0)
            color = Color.Silver;
          if (Conversions.ToDouble(SqlConnectionPool.sqlDataReader_2[22].ToString()) >= 5.0)
            color = Color.Red;
          Point point1;
          switch (num2)
          {
            case 1:
              this.PictureBox1.Visible = true;
              PictureBox pictureBox1 = this.PictureBox1;
              point1 = new Point(x, y);
              Point point2 = point1;
              pictureBox1.Location = point2;
              this.PictureBox1.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox1, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 2:
              this.PictureBox2.Visible = true;
              PictureBox pictureBox2 = this.PictureBox2;
              point1 = new Point(x, y);
              Point point3 = point1;
              pictureBox2.Location = point3;
              this.PictureBox2.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox2, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 3:
              this.PictureBox3.Visible = true;
              PictureBox pictureBox3 = this.PictureBox3;
              point1 = new Point(x, y);
              Point point4 = point1;
              pictureBox3.Location = point4;
              this.PictureBox3.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox3, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 4:
              this.PictureBox4.Visible = true;
              PictureBox pictureBox4 = this.PictureBox4;
              point1 = new Point(x, y);
              Point point5 = point1;
              pictureBox4.Location = point5;
              this.PictureBox4.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox4, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 5:
              this.PictureBox5.Visible = true;
              PictureBox pictureBox5 = this.PictureBox5;
              point1 = new Point(x, y);
              Point point6 = point1;
              pictureBox5.Location = point6;
              this.PictureBox5.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox5, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 6:
              this.PictureBox6.Visible = true;
              PictureBox pictureBox6 = this.PictureBox6;
              point1 = new Point(x, y);
              Point point7 = point1;
              pictureBox6.Location = point7;
              this.PictureBox6.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox6, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 7:
              this.PictureBox7.Visible = true;
              PictureBox pictureBox7 = this.PictureBox7;
              point1 = new Point(x, y);
              Point point8 = point1;
              pictureBox7.Location = point8;
              this.PictureBox7.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox7, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 8:
              this.PictureBox8.Visible = true;
              PictureBox pictureBox8 = this.PictureBox8;
              point1 = new Point(x, y);
              Point point9 = point1;
              pictureBox8.Location = point9;
              this.PictureBox8.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox8, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 9:
              this.PictureBox9.Visible = true;
              PictureBox pictureBox9 = this.PictureBox9;
              point1 = new Point(x, y);
              Point point10 = point1;
              pictureBox9.Location = point10;
              this.PictureBox9.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox9, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 10:
              this.PictureBox10.Visible = true;
              PictureBox pictureBox10 = this.PictureBox10;
              point1 = new Point(x, y);
              Point point11 = point1;
              pictureBox10.Location = point11;
              this.PictureBox10.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox10, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 11:
              this.PictureBox11.Visible = true;
              PictureBox pictureBox11 = this.PictureBox11;
              point1 = new Point(x, y);
              Point point12 = point1;
              pictureBox11.Location = point12;
              this.PictureBox11.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox11, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 12:
              this.PictureBox12.Visible = true;
              PictureBox pictureBox12 = this.PictureBox12;
              point1 = new Point(x, y);
              Point point13 = point1;
              pictureBox12.Location = point13;
              this.PictureBox12.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox12, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 13:
              this.PictureBox13.Visible = true;
              PictureBox pictureBox13 = this.PictureBox13;
              point1 = new Point(x, y);
              Point point14 = point1;
              pictureBox13.Location = point14;
              this.PictureBox13.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox13, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 14:
              this.PictureBox14.Visible = true;
              PictureBox pictureBox14 = this.PictureBox14;
              point1 = new Point(x, y);
              Point point15 = point1;
              pictureBox14.Location = point15;
              this.PictureBox14.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox14, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 15:
              this.PictureBox15.Visible = true;
              PictureBox pictureBox15 = this.PictureBox15;
              point1 = new Point(x, y);
              Point point16 = point1;
              pictureBox15.Location = point16;
              this.PictureBox15.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox15, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 16:
              this.PictureBox16.Visible = true;
              PictureBox pictureBox16 = this.PictureBox16;
              point1 = new Point(x, y);
              Point point17 = point1;
              pictureBox16.Location = point17;
              this.PictureBox16.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox16, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 17:
              this.PictureBox17.Visible = true;
              PictureBox pictureBox17 = this.PictureBox17;
              point1 = new Point(x, y);
              Point point18 = point1;
              pictureBox17.Location = point18;
              this.PictureBox17.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox17, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 18:
              this.PictureBox18.Visible = true;
              PictureBox pictureBox18 = this.PictureBox18;
              point1 = new Point(x, y);
              Point point19 = point1;
              pictureBox18.Location = point19;
              this.PictureBox18.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox18, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 19:
              this.PictureBox19.Visible = true;
              PictureBox pictureBox19 = this.PictureBox19;
              point1 = new Point(x, y);
              Point point20 = point1;
              pictureBox19.Location = point20;
              this.PictureBox19.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox19, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 20:
              this.PictureBox20.Visible = true;
              PictureBox pictureBox20 = this.PictureBox20;
              point1 = new Point(x, y);
              Point point21 = point1;
              pictureBox20.Location = point21;
              this.PictureBox20.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox20, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 21:
              this.PictureBox21.Visible = true;
              PictureBox pictureBox21 = this.PictureBox21;
              point1 = new Point(x, y);
              Point point22 = point1;
              pictureBox21.Location = point22;
              this.PictureBox21.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox21, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 22:
              this.PictureBox22.Visible = true;
              PictureBox pictureBox22 = this.PictureBox22;
              point1 = new Point(x, y);
              Point point23 = point1;
              pictureBox22.Location = point23;
              this.PictureBox22.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox22, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 23:
              this.PictureBox23.Visible = true;
              PictureBox pictureBox23 = this.PictureBox23;
              point1 = new Point(x, y);
              Point point24 = point1;
              pictureBox23.Location = point24;
              this.PictureBox23.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox23, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 24:
              this.PictureBox24.Visible = true;
              PictureBox pictureBox24 = this.PictureBox24;
              point1 = new Point(x, y);
              Point point25 = point1;
              pictureBox24.Location = point25;
              this.PictureBox24.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox24, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 25:
              this.PictureBox25.Visible = true;
              PictureBox pictureBox25 = this.PictureBox25;
              point1 = new Point(x, y);
              Point point26 = point1;
              pictureBox25.Location = point26;
              this.PictureBox25.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox25, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 26:
              this.PictureBox26.Visible = true;
              PictureBox pictureBox26 = this.PictureBox26;
              point1 = new Point(x, y);
              Point point27 = point1;
              pictureBox26.Location = point27;
              this.PictureBox26.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox26, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 27:
              this.PictureBox27.Visible = true;
              PictureBox pictureBox27 = this.PictureBox27;
              point1 = new Point(x, y);
              Point point28 = point1;
              pictureBox27.Location = point28;
              this.PictureBox27.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox27, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 28:
              this.PictureBox28.Visible = true;
              PictureBox pictureBox28 = this.PictureBox28;
              point1 = new Point(x, y);
              Point point29 = point1;
              pictureBox28.Location = point29;
              this.PictureBox28.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox28, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 29:
              this.PictureBox29.Visible = true;
              PictureBox pictureBox29 = this.PictureBox29;
              point1 = new Point(x, y);
              Point point30 = point1;
              pictureBox29.Location = point30;
              this.PictureBox29.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox29, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 30:
              this.PictureBox30.Visible = true;
              PictureBox pictureBox30 = this.PictureBox30;
              point1 = new Point(x, y);
              Point point31 = point1;
              pictureBox30.Location = point31;
              this.PictureBox30.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox30, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 31:
              this.PictureBox31.Visible = true;
              PictureBox pictureBox31 = this.PictureBox31;
              point1 = new Point(x, y);
              Point point32 = point1;
              pictureBox31.Location = point32;
              this.PictureBox31.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox31, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 32:
              this.PictureBox32.Visible = true;
              PictureBox pictureBox32 = this.PictureBox32;
              point1 = new Point(x, y);
              Point point33 = point1;
              pictureBox32.Location = point33;
              this.PictureBox32.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox32, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 33:
              this.PictureBox33.Visible = true;
              PictureBox pictureBox33 = this.PictureBox33;
              point1 = new Point(x, y);
              Point point34 = point1;
              pictureBox33.Location = point34;
              this.PictureBox33.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox33, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 34:
              this.PictureBox34.Visible = true;
              PictureBox pictureBox34 = this.PictureBox34;
              point1 = new Point(x, y);
              Point point35 = point1;
              pictureBox34.Location = point35;
              this.PictureBox34.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox34, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 35:
              this.PictureBox35.Visible = true;
              PictureBox pictureBox35 = this.PictureBox35;
              point1 = new Point(x, y);
              Point point36 = point1;
              pictureBox35.Location = point36;
              this.PictureBox35.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox35, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 36:
              this.PictureBox36.Visible = true;
              PictureBox pictureBox36 = this.PictureBox36;
              point1 = new Point(x, y);
              Point point37 = point1;
              pictureBox36.Location = point37;
              this.PictureBox36.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox36, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 37:
              this.PictureBox37.Visible = true;
              PictureBox pictureBox37 = this.PictureBox37;
              point1 = new Point(x, y);
              Point point38 = point1;
              pictureBox37.Location = point38;
              this.PictureBox37.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox37, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 38:
              this.PictureBox38.Visible = true;
              PictureBox pictureBox38 = this.PictureBox38;
              point1 = new Point(x, y);
              Point point39 = point1;
              pictureBox38.Location = point39;
              this.PictureBox38.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox38, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 39:
              this.PictureBox39.Visible = true;
              PictureBox pictureBox39 = this.PictureBox39;
              point1 = new Point(x, y);
              Point point40 = point1;
              pictureBox39.Location = point40;
              this.PictureBox39.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox39, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 40:
              this.PictureBox40.Visible = true;
              PictureBox pictureBox40 = this.PictureBox40;
              point1 = new Point(x, y);
              Point point41 = point1;
              pictureBox40.Location = point41;
              this.PictureBox40.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox40, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 41:
              this.PictureBox41.Visible = true;
              PictureBox pictureBox41 = this.PictureBox41;
              point1 = new Point(x, y);
              Point point42 = point1;
              pictureBox41.Location = point42;
              this.PictureBox41.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox41, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 42:
              this.PictureBox42.Visible = true;
              PictureBox pictureBox42 = this.PictureBox42;
              point1 = new Point(x, y);
              Point point43 = point1;
              pictureBox42.Location = point43;
              this.PictureBox42.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox42, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 43:
              this.PictureBox43.Visible = true;
              PictureBox pictureBox43 = this.PictureBox43;
              point1 = new Point(x, y);
              Point point44 = point1;
              pictureBox43.Location = point44;
              this.PictureBox43.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox43, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 44:
              this.PictureBox44.Visible = true;
              PictureBox pictureBox44 = this.PictureBox44;
              point1 = new Point(x, y);
              Point point45 = point1;
              pictureBox44.Location = point45;
              this.PictureBox44.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox44, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 45:
              this.PictureBox45.Visible = true;
              PictureBox pictureBox45 = this.PictureBox45;
              point1 = new Point(x, y);
              Point point46 = point1;
              pictureBox45.Location = point46;
              this.PictureBox45.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox45, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 46:
              this.PictureBox46.Visible = true;
              PictureBox pictureBox46 = this.PictureBox46;
              point1 = new Point(x, y);
              Point point47 = point1;
              pictureBox46.Location = point47;
              this.PictureBox46.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox46, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 47:
              this.PictureBox47.Visible = true;
              PictureBox pictureBox47 = this.PictureBox47;
              point1 = new Point(x, y);
              Point point48 = point1;
              pictureBox47.Location = point48;
              this.PictureBox47.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox47, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 48:
              this.PictureBox48.Visible = true;
              PictureBox pictureBox48 = this.PictureBox48;
              point1 = new Point(x, y);
              Point point49 = point1;
              pictureBox48.Location = point49;
              this.PictureBox48.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox48, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 49:
              this.PictureBox49.Visible = true;
              PictureBox pictureBox49 = this.PictureBox49;
              point1 = new Point(x, y);
              Point point50 = point1;
              pictureBox49.Location = point50;
              this.PictureBox49.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox49, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 50:
              this.PictureBox50.Visible = true;
              PictureBox pictureBox50 = this.PictureBox50;
              point1 = new Point(x, y);
              Point point51 = point1;
              pictureBox50.Location = point51;
              this.PictureBox50.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox50, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 51:
              this.PictureBox51.Visible = true;
              PictureBox pictureBox51 = this.PictureBox51;
              point1 = new Point(x, y);
              Point point52 = point1;
              pictureBox51.Location = point52;
              this.PictureBox51.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox51, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 52:
              this.PictureBox52.Visible = true;
              PictureBox pictureBox52 = this.PictureBox52;
              point1 = new Point(x, y);
              Point point53 = point1;
              pictureBox52.Location = point53;
              this.PictureBox52.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox52, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 53:
              this.PictureBox53.Visible = true;
              PictureBox pictureBox53 = this.PictureBox53;
              point1 = new Point(x, y);
              Point point54 = point1;
              pictureBox53.Location = point54;
              this.PictureBox53.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox53, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 54:
              this.PictureBox54.Visible = true;
              PictureBox pictureBox54 = this.PictureBox54;
              point1 = new Point(x, y);
              Point point55 = point1;
              pictureBox54.Location = point55;
              this.PictureBox54.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox54, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 55:
              this.PictureBox55.Visible = true;
              PictureBox pictureBox55 = this.PictureBox55;
              point1 = new Point(x, y);
              Point point56 = point1;
              pictureBox55.Location = point56;
              this.PictureBox55.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox55, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 56:
              this.PictureBox56.Visible = true;
              PictureBox pictureBox56 = this.PictureBox56;
              point1 = new Point(x, y);
              Point point57 = point1;
              pictureBox56.Location = point57;
              this.PictureBox56.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox56, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 57:
              this.PictureBox57.Visible = true;
              PictureBox pictureBox57 = this.PictureBox57;
              point1 = new Point(x, y);
              Point point58 = point1;
              pictureBox57.Location = point58;
              this.PictureBox57.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox57, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 58:
              this.PictureBox58.Visible = true;
              PictureBox pictureBox58 = this.PictureBox58;
              point1 = new Point(x, y);
              Point point59 = point1;
              pictureBox58.Location = point59;
              this.PictureBox58.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox58, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 59:
              this.PictureBox59.Visible = true;
              PictureBox pictureBox59 = this.PictureBox59;
              point1 = new Point(x, y);
              Point point60 = point1;
              pictureBox59.Location = point60;
              this.PictureBox59.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox59, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 60:
              this.PictureBox60.Visible = true;
              PictureBox pictureBox60 = this.PictureBox60;
              point1 = new Point(x, y);
              Point point61 = point1;
              pictureBox60.Location = point61;
              this.PictureBox60.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox60, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 61:
              this.PictureBox61.Visible = true;
              PictureBox pictureBox61 = this.PictureBox61;
              point1 = new Point(x, y);
              Point point62 = point1;
              pictureBox61.Location = point62;
              this.PictureBox61.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox61, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 62:
              this.PictureBox62.Visible = true;
              PictureBox pictureBox62 = this.PictureBox62;
              point1 = new Point(x, y);
              Point point63 = point1;
              pictureBox62.Location = point63;
              this.PictureBox62.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox62, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 63:
              this.PictureBox63.Visible = true;
              PictureBox pictureBox63 = this.PictureBox63;
              point1 = new Point(x, y);
              Point point64 = point1;
              pictureBox63.Location = point64;
              this.PictureBox63.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox63, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 64:
              this.PictureBox64.Visible = true;
              PictureBox pictureBox64 = this.PictureBox64;
              point1 = new Point(x, y);
              Point point65 = point1;
              pictureBox64.Location = point65;
              this.PictureBox64.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox64, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 65:
              this.PictureBox65.Visible = true;
              PictureBox pictureBox65 = this.PictureBox65;
              point1 = new Point(x, y);
              Point point66 = point1;
              pictureBox65.Location = point66;
              this.PictureBox65.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox65, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 66:
              this.PictureBox66.Visible = true;
              PictureBox pictureBox66 = this.PictureBox66;
              point1 = new Point(x, y);
              Point point67 = point1;
              pictureBox66.Location = point67;
              this.PictureBox66.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox66, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 67:
              this.PictureBox67.Visible = true;
              PictureBox pictureBox67 = this.PictureBox67;
              point1 = new Point(x, y);
              Point point68 = point1;
              pictureBox67.Location = point68;
              this.PictureBox67.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox67, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 68:
              this.PictureBox68.Visible = true;
              PictureBox pictureBox68 = this.PictureBox68;
              point1 = new Point(x, y);
              Point point69 = point1;
              pictureBox68.Location = point69;
              this.PictureBox68.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox68, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 69:
              this.PictureBox69.Visible = true;
              PictureBox pictureBox69 = this.PictureBox69;
              point1 = new Point(x, y);
              Point point70 = point1;
              pictureBox69.Location = point70;
              this.PictureBox69.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox69, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 70:
              this.PictureBox70.Visible = true;
              PictureBox pictureBox70 = this.PictureBox70;
              point1 = new Point(x, y);
              Point point71 = point1;
              pictureBox70.Location = point71;
              this.PictureBox70.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox70, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 71:
              this.PictureBox71.Visible = true;
              PictureBox pictureBox71 = this.PictureBox71;
              point1 = new Point(x, y);
              Point point72 = point1;
              pictureBox71.Location = point72;
              this.PictureBox71.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox71, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 72:
              this.PictureBox72.Visible = true;
              PictureBox pictureBox72 = this.PictureBox72;
              point1 = new Point(x, y);
              Point point73 = point1;
              pictureBox72.Location = point73;
              this.PictureBox72.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox72, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 73:
              this.PictureBox73.Visible = true;
              PictureBox pictureBox73 = this.PictureBox73;
              point1 = new Point(x, y);
              Point point74 = point1;
              pictureBox73.Location = point74;
              this.PictureBox73.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox73, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 74:
              this.PictureBox74.Visible = true;
              PictureBox pictureBox74 = this.PictureBox74;
              point1 = new Point(x, y);
              Point point75 = point1;
              pictureBox74.Location = point75;
              this.PictureBox74.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox74, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 75:
              this.PictureBox75.Visible = true;
              PictureBox pictureBox75 = this.PictureBox75;
              point1 = new Point(x, y);
              Point point76 = point1;
              pictureBox75.Location = point76;
              this.PictureBox75.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox75, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 76:
              this.PictureBox76.Visible = true;
              PictureBox pictureBox76 = this.PictureBox76;
              point1 = new Point(x, y);
              Point point77 = point1;
              pictureBox76.Location = point77;
              this.PictureBox76.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox76, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 77:
              this.PictureBox77.Visible = true;
              PictureBox pictureBox77 = this.PictureBox77;
              point1 = new Point(x, y);
              Point point78 = point1;
              pictureBox77.Location = point78;
              this.PictureBox77.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox77, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 78:
              this.PictureBox78.Visible = true;
              PictureBox pictureBox78 = this.PictureBox78;
              point1 = new Point(x, y);
              Point point79 = point1;
              pictureBox78.Location = point79;
              this.PictureBox78.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox78, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 79:
              this.PictureBox79.Visible = true;
              PictureBox pictureBox79 = this.PictureBox79;
              point1 = new Point(x, y);
              Point point80 = point1;
              pictureBox79.Location = point80;
              this.PictureBox79.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox79, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 80:
              this.PictureBox80.Visible = true;
              PictureBox pictureBox80 = this.PictureBox80;
              point1 = new Point(x, y);
              Point point81 = point1;
              pictureBox80.Location = point81;
              this.PictureBox80.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox80, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 81:
              this.PictureBox81.Visible = true;
              PictureBox pictureBox81 = this.PictureBox81;
              point1 = new Point(x, y);
              Point point82 = point1;
              pictureBox81.Location = point82;
              this.PictureBox81.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox81, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 82:
              this.PictureBox82.Visible = true;
              PictureBox pictureBox82 = this.PictureBox82;
              point1 = new Point(x, y);
              Point point83 = point1;
              pictureBox82.Location = point83;
              this.PictureBox82.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox82, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 83:
              this.PictureBox83.Visible = true;
              PictureBox pictureBox83 = this.PictureBox83;
              point1 = new Point(x, y);
              Point point84 = point1;
              pictureBox83.Location = point84;
              this.PictureBox83.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox83, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 84:
              this.PictureBox84.Visible = true;
              PictureBox pictureBox84 = this.PictureBox84;
              point1 = new Point(x, y);
              Point point85 = point1;
              pictureBox84.Location = point85;
              this.PictureBox84.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox84, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 85:
              this.PictureBox85.Visible = true;
              PictureBox pictureBox85 = this.PictureBox85;
              point1 = new Point(x, y);
              Point point86 = point1;
              pictureBox85.Location = point86;
              this.PictureBox85.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox85, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 86:
              this.PictureBox86.Visible = true;
              PictureBox pictureBox86 = this.PictureBox86;
              point1 = new Point(x, y);
              Point point87 = point1;
              pictureBox86.Location = point87;
              this.PictureBox86.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox86, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 87:
              this.PictureBox87.Visible = true;
              PictureBox pictureBox87 = this.PictureBox87;
              point1 = new Point(x, y);
              Point point88 = point1;
              pictureBox87.Location = point88;
              this.PictureBox87.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox87, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 88:
              this.PictureBox88.Visible = true;
              PictureBox pictureBox88 = this.PictureBox88;
              point1 = new Point(x, y);
              Point point89 = point1;
              pictureBox88.Location = point89;
              this.PictureBox88.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox88, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 89:
              this.PictureBox89.Visible = true;
              PictureBox pictureBox89 = this.PictureBox89;
              point1 = new Point(x, y);
              Point point90 = point1;
              pictureBox89.Location = point90;
              this.PictureBox89.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox89, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 90:
              this.PictureBox90.Visible = true;
              PictureBox pictureBox90 = this.PictureBox90;
              point1 = new Point(x, y);
              Point point91 = point1;
              pictureBox90.Location = point91;
              this.PictureBox90.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox90, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 91:
              this.PictureBox91.Visible = true;
              PictureBox pictureBox91 = this.PictureBox91;
              point1 = new Point(x, y);
              Point point92 = point1;
              pictureBox91.Location = point92;
              this.PictureBox91.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox91, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 92:
              this.PictureBox92.Visible = true;
              PictureBox pictureBox92 = this.PictureBox92;
              point1 = new Point(x, y);
              Point point93 = point1;
              pictureBox92.Location = point93;
              this.PictureBox92.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox92, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 93:
              this.PictureBox93.Visible = true;
              PictureBox pictureBox93 = this.PictureBox93;
              point1 = new Point(x, y);
              Point point94 = point1;
              pictureBox93.Location = point94;
              this.PictureBox93.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox93, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 94:
              this.PictureBox94.Visible = true;
              PictureBox pictureBox94 = this.PictureBox94;
              point1 = new Point(x, y);
              Point point95 = point1;
              pictureBox94.Location = point95;
              this.PictureBox94.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox94, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 95:
              this.PictureBox95.Visible = true;
              PictureBox pictureBox95 = this.PictureBox95;
              point1 = new Point(x, y);
              Point point96 = point1;
              pictureBox95.Location = point96;
              this.PictureBox95.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox95, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 96:
              this.PictureBox96.Visible = true;
              PictureBox pictureBox96 = this.PictureBox96;
              point1 = new Point(x, y);
              Point point97 = point1;
              pictureBox96.Location = point97;
              this.PictureBox96.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox96, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 97:
              this.PictureBox97.Visible = true;
              PictureBox pictureBox97 = this.PictureBox97;
              point1 = new Point(x, y);
              Point point98 = point1;
              pictureBox97.Location = point98;
              this.PictureBox97.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox97, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 98:
              this.PictureBox98.Visible = true;
              PictureBox pictureBox98 = this.PictureBox98;
              point1 = new Point(x, y);
              Point point99 = point1;
              pictureBox98.Location = point99;
              this.PictureBox98.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox98, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 99:
              this.PictureBox99.Visible = true;
              PictureBox pictureBox99 = this.PictureBox99;
              point1 = new Point(x, y);
              Point point100 = point1;
              pictureBox99.Location = point100;
              this.PictureBox99.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox99, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 100:
              this.PictureBox100.Visible = true;
              PictureBox pictureBox100 = this.PictureBox100;
              point1 = new Point(x, y);
              Point point101 = point1;
              pictureBox100.Location = point101;
              this.PictureBox100.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox100, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 101:
              this.PictureBox101.Visible = true;
              PictureBox pictureBox101 = this.PictureBox101;
              point1 = new Point(x, y);
              Point point102 = point1;
              pictureBox101.Location = point102;
              this.PictureBox101.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox101, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 102:
              this.PictureBox102.Visible = true;
              PictureBox pictureBox102 = this.PictureBox102;
              point1 = new Point(x, y);
              Point point103 = point1;
              pictureBox102.Location = point103;
              this.PictureBox102.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox102, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 103:
              this.PictureBox103.Visible = true;
              PictureBox pictureBox103 = this.PictureBox103;
              point1 = new Point(x, y);
              Point point104 = point1;
              pictureBox103.Location = point104;
              this.PictureBox103.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox103, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 104:
              this.PictureBox104.Visible = true;
              PictureBox pictureBox104 = this.PictureBox104;
              point1 = new Point(x, y);
              Point point105 = point1;
              pictureBox104.Location = point105;
              this.PictureBox104.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox104, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 105:
              this.PictureBox105.Visible = true;
              PictureBox pictureBox105 = this.PictureBox105;
              point1 = new Point(x, y);
              Point point106 = point1;
              pictureBox105.Location = point106;
              this.PictureBox105.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox105, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 106:
              this.PictureBox106.Visible = true;
              PictureBox pictureBox106 = this.PictureBox106;
              point1 = new Point(x, y);
              Point point107 = point1;
              pictureBox106.Location = point107;
              this.PictureBox106.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox106, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 107:
              this.PictureBox107.Visible = true;
              PictureBox pictureBox107 = this.PictureBox107;
              point1 = new Point(x, y);
              Point point108 = point1;
              pictureBox107.Location = point108;
              this.PictureBox107.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox107, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 108:
              this.PictureBox108.Visible = true;
              PictureBox pictureBox108 = this.PictureBox108;
              point1 = new Point(x, y);
              Point point109 = point1;
              pictureBox108.Location = point109;
              this.PictureBox108.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox108, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 109:
              this.PictureBox109.Visible = true;
              PictureBox pictureBox109 = this.PictureBox109;
              point1 = new Point(x, y);
              Point point110 = point1;
              pictureBox109.Location = point110;
              this.PictureBox109.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox109, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 110:
              this.PictureBox110.Visible = true;
              PictureBox pictureBox110 = this.PictureBox110;
              point1 = new Point(x, y);
              Point point111 = point1;
              pictureBox110.Location = point111;
              this.PictureBox110.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox110, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 111:
              this.PictureBox111.Visible = true;
              PictureBox pictureBox111 = this.PictureBox111;
              point1 = new Point(x, y);
              Point point112 = point1;
              pictureBox111.Location = point112;
              this.PictureBox111.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox111, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 112:
              this.PictureBox112.Visible = true;
              PictureBox pictureBox112 = this.PictureBox112;
              point1 = new Point(x, y);
              Point point113 = point1;
              pictureBox112.Location = point113;
              this.PictureBox112.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox112, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 113:
              this.PictureBox113.Visible = true;
              PictureBox pictureBox113 = this.PictureBox113;
              point1 = new Point(x, y);
              Point point114 = point1;
              pictureBox113.Location = point114;
              this.PictureBox113.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox113, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 114:
              this.PictureBox114.Visible = true;
              PictureBox pictureBox114 = this.PictureBox114;
              point1 = new Point(x, y);
              Point point115 = point1;
              pictureBox114.Location = point115;
              this.PictureBox114.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox114, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 115:
              this.PictureBox115.Visible = true;
              PictureBox pictureBox115 = this.PictureBox115;
              point1 = new Point(x, y);
              Point point116 = point1;
              pictureBox115.Location = point116;
              this.PictureBox115.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox115, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 116:
              this.PictureBox116.Visible = true;
              PictureBox pictureBox116 = this.PictureBox116;
              point1 = new Point(x, y);
              Point point117 = point1;
              pictureBox116.Location = point117;
              this.PictureBox116.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox116, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 117:
              this.PictureBox117.Visible = true;
              PictureBox pictureBox117 = this.PictureBox117;
              point1 = new Point(x, y);
              Point point118 = point1;
              pictureBox117.Location = point118;
              this.PictureBox117.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox117, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 118:
              this.PictureBox118.Visible = true;
              PictureBox pictureBox118 = this.PictureBox118;
              point1 = new Point(x, y);
              Point point119 = point1;
              pictureBox118.Location = point119;
              this.PictureBox118.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox118, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 119:
              this.PictureBox119.Visible = true;
              PictureBox pictureBox119 = this.PictureBox119;
              point1 = new Point(x, y);
              Point point120 = point1;
              pictureBox119.Location = point120;
              this.PictureBox119.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox119, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 120:
              this.PictureBox120.Visible = true;
              PictureBox pictureBox120 = this.PictureBox120;
              point1 = new Point(x, y);
              Point point121 = point1;
              pictureBox120.Location = point121;
              this.PictureBox120.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox120, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 121:
              this.PictureBox121.Visible = true;
              PictureBox pictureBox121 = this.PictureBox121;
              point1 = new Point(x, y);
              Point point122 = point1;
              pictureBox121.Location = point122;
              this.PictureBox121.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox121, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 122:
              this.PictureBox122.Visible = true;
              PictureBox pictureBox122 = this.PictureBox122;
              point1 = new Point(x, y);
              Point point123 = point1;
              pictureBox122.Location = point123;
              this.PictureBox122.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox122, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 123:
              this.PictureBox123.Visible = true;
              PictureBox pictureBox123 = this.PictureBox123;
              point1 = new Point(x, y);
              Point point124 = point1;
              pictureBox123.Location = point124;
              this.PictureBox123.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox123, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 124:
              this.PictureBox124.Visible = true;
              PictureBox pictureBox124 = this.PictureBox124;
              point1 = new Point(x, y);
              Point point125 = point1;
              pictureBox124.Location = point125;
              this.PictureBox124.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox124, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 125:
              this.PictureBox125.Visible = true;
              PictureBox pictureBox125 = this.PictureBox125;
              point1 = new Point(x, y);
              Point point126 = point1;
              pictureBox125.Location = point126;
              this.PictureBox125.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox125, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 126:
              this.PictureBox126.Visible = true;
              PictureBox pictureBox126 = this.PictureBox126;
              point1 = new Point(x, y);
              Point point127 = point1;
              pictureBox126.Location = point127;
              this.PictureBox126.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox126, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case (int) sbyte.MaxValue:
              this.PictureBox127.Visible = true;
              PictureBox pictureBox127 = this.PictureBox127;
              point1 = new Point(x, y);
              Point point128 = point1;
              pictureBox127.Location = point128;
              this.PictureBox127.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox127, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 128:
              this.PictureBox128.Visible = true;
              PictureBox pictureBox128 = this.PictureBox128;
              point1 = new Point(x, y);
              Point point129 = point1;
              pictureBox128.Location = point129;
              this.PictureBox128.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox128, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 129:
              this.PictureBox129.Visible = true;
              PictureBox pictureBox129 = this.PictureBox129;
              point1 = new Point(x, y);
              Point point130 = point1;
              pictureBox129.Location = point130;
              this.PictureBox129.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox129, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 130:
              this.PictureBox130.Visible = true;
              PictureBox pictureBox130 = this.PictureBox130;
              point1 = new Point(x, y);
              Point point131 = point1;
              pictureBox130.Location = point131;
              this.PictureBox130.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox130, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 131:
              this.PictureBox131.Visible = true;
              PictureBox pictureBox131 = this.PictureBox131;
              point1 = new Point(x, y);
              Point point132 = point1;
              pictureBox131.Location = point132;
              this.PictureBox131.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox131, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 132:
              this.PictureBox132.Visible = true;
              PictureBox pictureBox132 = this.PictureBox132;
              point1 = new Point(x, y);
              Point point133 = point1;
              pictureBox132.Location = point133;
              this.PictureBox132.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox132, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 133:
              this.PictureBox133.Visible = true;
              PictureBox pictureBox133 = this.PictureBox133;
              point1 = new Point(x, y);
              Point point134 = point1;
              pictureBox133.Location = point134;
              this.PictureBox133.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox133, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 134:
              this.PictureBox134.Visible = true;
              PictureBox pictureBox134 = this.PictureBox134;
              point1 = new Point(x, y);
              Point point135 = point1;
              pictureBox134.Location = point135;
              this.PictureBox134.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox134, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 135:
              this.PictureBox135.Visible = true;
              PictureBox pictureBox135 = this.PictureBox135;
              point1 = new Point(x, y);
              Point point136 = point1;
              pictureBox135.Location = point136;
              this.PictureBox135.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox135, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 136:
              this.PictureBox136.Visible = true;
              PictureBox pictureBox136 = this.PictureBox136;
              point1 = new Point(x, y);
              Point point137 = point1;
              pictureBox136.Location = point137;
              this.PictureBox136.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox136, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 137:
              this.PictureBox137.Visible = true;
              PictureBox pictureBox137 = this.PictureBox137;
              point1 = new Point(x, y);
              Point point138 = point1;
              pictureBox137.Location = point138;
              this.PictureBox137.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox137, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 138:
              this.PictureBox138.Visible = true;
              PictureBox pictureBox138 = this.PictureBox138;
              point1 = new Point(x, y);
              Point point139 = point1;
              pictureBox138.Location = point139;
              this.PictureBox138.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox138, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 139:
              this.PictureBox139.Visible = true;
              PictureBox pictureBox139 = this.PictureBox139;
              point1 = new Point(x, y);
              Point point140 = point1;
              pictureBox139.Location = point140;
              this.PictureBox139.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox139, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 140:
              this.PictureBox140.Visible = true;
              PictureBox pictureBox140 = this.PictureBox140;
              point1 = new Point(x, y);
              Point point141 = point1;
              pictureBox140.Location = point141;
              this.PictureBox140.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox140, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 141:
              this.PictureBox141.Visible = true;
              PictureBox pictureBox141 = this.PictureBox141;
              point1 = new Point(x, y);
              Point point142 = point1;
              pictureBox141.Location = point142;
              this.PictureBox141.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox141, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 142:
              this.PictureBox142.Visible = true;
              PictureBox pictureBox142 = this.PictureBox142;
              point1 = new Point(x, y);
              Point point143 = point1;
              pictureBox142.Location = point143;
              this.PictureBox142.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox142, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 143:
              this.PictureBox143.Visible = true;
              PictureBox pictureBox143 = this.PictureBox143;
              point1 = new Point(x, y);
              Point point144 = point1;
              pictureBox143.Location = point144;
              this.PictureBox143.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox143, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 144:
              this.PictureBox144.Visible = true;
              PictureBox pictureBox144 = this.PictureBox144;
              point1 = new Point(x, y);
              Point point145 = point1;
              pictureBox144.Location = point145;
              this.PictureBox144.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox144, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 145:
              this.PictureBox145.Visible = true;
              PictureBox pictureBox145 = this.PictureBox145;
              point1 = new Point(x, y);
              Point point146 = point1;
              pictureBox145.Location = point146;
              this.PictureBox145.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox145, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 146:
              this.PictureBox146.Visible = true;
              PictureBox pictureBox146 = this.PictureBox146;
              point1 = new Point(x, y);
              Point point147 = point1;
              pictureBox146.Location = point147;
              this.PictureBox146.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox146, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 147:
              this.PictureBox147.Visible = true;
              PictureBox pictureBox147 = this.PictureBox147;
              point1 = new Point(x, y);
              Point point148 = point1;
              pictureBox147.Location = point148;
              this.PictureBox147.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox147, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 148:
              this.PictureBox148.Visible = true;
              PictureBox pictureBox148 = this.PictureBox148;
              point1 = new Point(x, y);
              Point point149 = point1;
              pictureBox148.Location = point149;
              this.PictureBox148.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox148, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 149:
              this.PictureBox149.Visible = true;
              PictureBox pictureBox149 = this.PictureBox149;
              point1 = new Point(x, y);
              Point point150 = point1;
              pictureBox149.Location = point150;
              this.PictureBox149.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox149, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 150:
              this.PictureBox150.Visible = true;
              PictureBox pictureBox150 = this.PictureBox150;
              point1 = new Point(x, y);
              Point point151 = point1;
              pictureBox150.Location = point151;
              this.PictureBox150.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox150, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 151:
              this.PictureBox151.Visible = true;
              PictureBox pictureBox151 = this.PictureBox151;
              point1 = new Point(x, y);
              Point point152 = point1;
              pictureBox151.Location = point152;
              this.PictureBox151.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox151, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 152:
              this.PictureBox152.Visible = true;
              PictureBox pictureBox152 = this.PictureBox152;
              point1 = new Point(x, y);
              Point point153 = point1;
              pictureBox152.Location = point153;
              this.PictureBox152.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox152, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 153:
              this.PictureBox153.Visible = true;
              PictureBox pictureBox153 = this.PictureBox153;
              point1 = new Point(x, y);
              Point point154 = point1;
              pictureBox153.Location = point154;
              this.PictureBox153.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox153, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 154:
              this.PictureBox154.Visible = true;
              PictureBox pictureBox154 = this.PictureBox154;
              point1 = new Point(x, y);
              Point point155 = point1;
              pictureBox154.Location = point155;
              this.PictureBox154.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox154, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 155:
              this.PictureBox155.Visible = true;
              PictureBox pictureBox155 = this.PictureBox155;
              point1 = new Point(x, y);
              Point point156 = point1;
              pictureBox155.Location = point156;
              this.PictureBox155.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox155, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 156:
              this.PictureBox156.Visible = true;
              PictureBox pictureBox156 = this.PictureBox156;
              point1 = new Point(x, y);
              Point point157 = point1;
              pictureBox156.Location = point157;
              this.PictureBox156.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox156, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 157:
              this.PictureBox157.Visible = true;
              PictureBox pictureBox157 = this.PictureBox157;
              point1 = new Point(x, y);
              Point point158 = point1;
              pictureBox157.Location = point158;
              this.PictureBox157.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox157, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 158:
              this.PictureBox158.Visible = true;
              PictureBox pictureBox158 = this.PictureBox158;
              point1 = new Point(x, y);
              Point point159 = point1;
              pictureBox158.Location = point159;
              this.PictureBox158.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox158, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 159:
              this.PictureBox159.Visible = true;
              PictureBox pictureBox159 = this.PictureBox159;
              point1 = new Point(x, y);
              Point point160 = point1;
              pictureBox159.Location = point160;
              this.PictureBox159.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox159, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 160:
              this.PictureBox160.Visible = true;
              PictureBox pictureBox160 = this.PictureBox160;
              point1 = new Point(x, y);
              Point point161 = point1;
              pictureBox160.Location = point161;
              this.PictureBox160.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox160, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 161:
              this.PictureBox161.Visible = true;
              PictureBox pictureBox161 = this.PictureBox161;
              point1 = new Point(x, y);
              Point point162 = point1;
              pictureBox161.Location = point162;
              this.PictureBox161.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox161, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 162:
              this.PictureBox162.Visible = true;
              PictureBox pictureBox162 = this.PictureBox162;
              point1 = new Point(x, y);
              Point point163 = point1;
              pictureBox162.Location = point163;
              this.PictureBox162.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox162, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 163:
              this.PictureBox163.Visible = true;
              PictureBox pictureBox163 = this.PictureBox163;
              point1 = new Point(x, y);
              Point point164 = point1;
              pictureBox163.Location = point164;
              this.PictureBox163.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox163, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 164:
              this.PictureBox164.Visible = true;
              PictureBox pictureBox164 = this.PictureBox164;
              point1 = new Point(x, y);
              Point point165 = point1;
              pictureBox164.Location = point165;
              this.PictureBox164.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox164, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 165:
              this.PictureBox165.Visible = true;
              PictureBox pictureBox165 = this.PictureBox165;
              point1 = new Point(x, y);
              Point point166 = point1;
              pictureBox165.Location = point166;
              this.PictureBox165.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox165, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 166:
              this.PictureBox166.Visible = true;
              PictureBox pictureBox166 = this.PictureBox166;
              point1 = new Point(x, y);
              Point point167 = point1;
              pictureBox166.Location = point167;
              this.PictureBox166.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox166, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 167:
              this.PictureBox167.Visible = true;
              PictureBox pictureBox167 = this.PictureBox167;
              point1 = new Point(x, y);
              Point point168 = point1;
              pictureBox167.Location = point168;
              this.PictureBox167.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox167, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 168:
              this.PictureBox168.Visible = true;
              PictureBox pictureBox168 = this.PictureBox168;
              point1 = new Point(x, y);
              Point point169 = point1;
              pictureBox168.Location = point169;
              this.PictureBox168.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox168, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 169:
              this.PictureBox169.Visible = true;
              PictureBox pictureBox169 = this.PictureBox169;
              point1 = new Point(x, y);
              Point point170 = point1;
              pictureBox169.Location = point170;
              this.PictureBox169.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox169, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 170:
              this.PictureBox170.Visible = true;
              PictureBox pictureBox170 = this.PictureBox170;
              point1 = new Point(x, y);
              Point point171 = point1;
              pictureBox170.Location = point171;
              this.PictureBox170.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox170, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 171:
              this.PictureBox171.Visible = true;
              PictureBox pictureBox171 = this.PictureBox171;
              point1 = new Point(x, y);
              Point point172 = point1;
              pictureBox171.Location = point172;
              this.PictureBox171.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox171, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 172:
              this.PictureBox172.Visible = true;
              PictureBox pictureBox172 = this.PictureBox172;
              point1 = new Point(x, y);
              Point point173 = point1;
              pictureBox172.Location = point173;
              this.PictureBox172.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox172, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 173:
              this.PictureBox173.Visible = true;
              PictureBox pictureBox173 = this.PictureBox173;
              point1 = new Point(x, y);
              Point point174 = point1;
              pictureBox173.Location = point174;
              this.PictureBox173.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox173, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 174:
              this.PictureBox174.Visible = true;
              PictureBox pictureBox174 = this.PictureBox174;
              point1 = new Point(x, y);
              Point point175 = point1;
              pictureBox174.Location = point175;
              this.PictureBox174.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox174, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 175:
              this.PictureBox175.Visible = true;
              PictureBox pictureBox175 = this.PictureBox175;
              point1 = new Point(x, y);
              Point point176 = point1;
              pictureBox175.Location = point176;
              this.PictureBox175.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox175, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 176:
              this.PictureBox176.Visible = true;
              PictureBox pictureBox176 = this.PictureBox176;
              point1 = new Point(x, y);
              Point point177 = point1;
              pictureBox176.Location = point177;
              this.PictureBox176.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox176, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 177:
              this.PictureBox177.Visible = true;
              PictureBox pictureBox177 = this.PictureBox177;
              point1 = new Point(x, y);
              Point point178 = point1;
              pictureBox177.Location = point178;
              this.PictureBox177.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox177, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 178:
              this.PictureBox178.Visible = true;
              PictureBox pictureBox178 = this.PictureBox178;
              point1 = new Point(x, y);
              Point point179 = point1;
              pictureBox178.Location = point179;
              this.PictureBox178.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox178, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 179:
              this.PictureBox179.Visible = true;
              PictureBox pictureBox179 = this.PictureBox179;
              point1 = new Point(x, y);
              Point point180 = point1;
              pictureBox179.Location = point180;
              this.PictureBox179.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox179, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 180:
              this.PictureBox180.Visible = true;
              PictureBox pictureBox180 = this.PictureBox180;
              point1 = new Point(x, y);
              Point point181 = point1;
              pictureBox180.Location = point181;
              this.PictureBox180.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox180, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 181:
              this.PictureBox181.Visible = true;
              PictureBox pictureBox181 = this.PictureBox181;
              point1 = new Point(x, y);
              Point point182 = point1;
              pictureBox181.Location = point182;
              this.PictureBox181.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox181, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 182:
              this.PictureBox182.Visible = true;
              PictureBox pictureBox182 = this.PictureBox182;
              point1 = new Point(x, y);
              Point point183 = point1;
              pictureBox182.Location = point183;
              this.PictureBox182.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox182, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 183:
              this.PictureBox183.Visible = true;
              PictureBox pictureBox183 = this.PictureBox183;
              point1 = new Point(x, y);
              Point point184 = point1;
              pictureBox183.Location = point184;
              this.PictureBox183.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox183, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 184:
              this.PictureBox184.Visible = true;
              PictureBox pictureBox184 = this.PictureBox184;
              point1 = new Point(x, y);
              Point point185 = point1;
              pictureBox184.Location = point185;
              this.PictureBox184.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox184, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 185:
              this.PictureBox185.Visible = true;
              PictureBox pictureBox185 = this.PictureBox185;
              point1 = new Point(x, y);
              Point point186 = point1;
              pictureBox185.Location = point186;
              this.PictureBox185.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox185, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 186:
              this.PictureBox186.Visible = true;
              PictureBox pictureBox186 = this.PictureBox186;
              point1 = new Point(x, y);
              Point point187 = point1;
              pictureBox186.Location = point187;
              this.PictureBox186.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox186, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 187:
              this.PictureBox187.Visible = true;
              PictureBox pictureBox187 = this.PictureBox187;
              point1 = new Point(x, y);
              Point point188 = point1;
              pictureBox187.Location = point188;
              this.PictureBox187.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox187, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 188:
              this.PictureBox188.Visible = true;
              PictureBox pictureBox188 = this.PictureBox188;
              point1 = new Point(x, y);
              Point point189 = point1;
              pictureBox188.Location = point189;
              this.PictureBox188.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox188, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 189:
              this.PictureBox189.Visible = true;
              PictureBox pictureBox189 = this.PictureBox189;
              point1 = new Point(x, y);
              Point point190 = point1;
              pictureBox189.Location = point190;
              this.PictureBox189.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox189, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 190:
              this.PictureBox190.Visible = true;
              PictureBox pictureBox190 = this.PictureBox190;
              point1 = new Point(x, y);
              Point point191 = point1;
              pictureBox190.Location = point191;
              this.PictureBox190.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox190, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 191:
              this.PictureBox191.Visible = true;
              PictureBox pictureBox191 = this.PictureBox191;
              point1 = new Point(x, y);
              Point point192 = point1;
              pictureBox191.Location = point192;
              this.PictureBox191.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox191, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 192:
              this.PictureBox192.Visible = true;
              PictureBox pictureBox192 = this.PictureBox192;
              point1 = new Point(x, y);
              Point point193 = point1;
              pictureBox192.Location = point193;
              this.PictureBox192.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox192, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 193:
              this.PictureBox193.Visible = true;
              PictureBox pictureBox193 = this.PictureBox193;
              point1 = new Point(x, y);
              Point point194 = point1;
              pictureBox193.Location = point194;
              this.PictureBox193.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox193, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 194:
              this.PictureBox194.Visible = true;
              PictureBox pictureBox194 = this.PictureBox194;
              point1 = new Point(x, y);
              Point point195 = point1;
              pictureBox194.Location = point195;
              this.PictureBox194.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox194, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 195:
              this.PictureBox195.Visible = true;
              PictureBox pictureBox195 = this.PictureBox195;
              point1 = new Point(x, y);
              Point point196 = point1;
              pictureBox195.Location = point196;
              this.PictureBox195.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox195, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 196:
              this.PictureBox196.Visible = true;
              PictureBox pictureBox196 = this.PictureBox196;
              point1 = new Point(x, y);
              Point point197 = point1;
              pictureBox196.Location = point197;
              this.PictureBox196.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox196, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 197:
              this.PictureBox197.Visible = true;
              PictureBox pictureBox197 = this.PictureBox197;
              point1 = new Point(x, y);
              Point point198 = point1;
              pictureBox197.Location = point198;
              this.PictureBox197.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox197, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 198:
              this.PictureBox198.Visible = true;
              PictureBox pictureBox198 = this.PictureBox198;
              point1 = new Point(x, y);
              Point point199 = point1;
              pictureBox198.Location = point199;
              this.PictureBox198.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox198, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 199:
              this.PictureBox199.Visible = true;
              PictureBox pictureBox199 = this.PictureBox199;
              point1 = new Point(x, y);
              Point point200 = point1;
              pictureBox199.Location = point200;
              this.PictureBox199.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox199, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 200:
              this.PictureBox200.Visible = true;
              PictureBox pictureBox200 = this.PictureBox200;
              point1 = new Point(x, y);
              Point point201 = point1;
              pictureBox200.Location = point201;
              this.PictureBox200.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox200, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 201:
              this.PictureBox201.Visible = true;
              PictureBox pictureBox201 = this.PictureBox201;
              point1 = new Point(x, y);
              Point point202 = point1;
              pictureBox201.Location = point202;
              this.PictureBox201.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox201, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 202:
              this.PictureBox202.Visible = true;
              PictureBox pictureBox202 = this.PictureBox202;
              point1 = new Point(x, y);
              Point point203 = point1;
              pictureBox202.Location = point203;
              this.PictureBox202.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox202, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 203:
              this.PictureBox203.Visible = true;
              PictureBox pictureBox203 = this.PictureBox203;
              point1 = new Point(x, y);
              Point point204 = point1;
              pictureBox203.Location = point204;
              this.PictureBox203.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox203, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 204:
              this.PictureBox204.Visible = true;
              PictureBox pictureBox204 = this.PictureBox204;
              point1 = new Point(x, y);
              Point point205 = point1;
              pictureBox204.Location = point205;
              this.PictureBox204.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox204, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 205:
              this.PictureBox205.Visible = true;
              PictureBox pictureBox205 = this.PictureBox205;
              point1 = new Point(x, y);
              Point point206 = point1;
              pictureBox205.Location = point206;
              this.PictureBox205.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox205, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 206:
              this.PictureBox206.Visible = true;
              PictureBox pictureBox206 = this.PictureBox206;
              point1 = new Point(x, y);
              Point point207 = point1;
              pictureBox206.Location = point207;
              this.PictureBox206.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox206, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 207:
              this.PictureBox207.Visible = true;
              PictureBox pictureBox207 = this.PictureBox207;
              point1 = new Point(x, y);
              Point point208 = point1;
              pictureBox207.Location = point208;
              this.PictureBox207.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox207, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 208:
              this.PictureBox208.Visible = true;
              PictureBox pictureBox208 = this.PictureBox208;
              point1 = new Point(x, y);
              Point point209 = point1;
              pictureBox208.Location = point209;
              this.PictureBox208.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox208, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 209:
              this.PictureBox209.Visible = true;
              PictureBox pictureBox209 = this.PictureBox209;
              point1 = new Point(x, y);
              Point point210 = point1;
              pictureBox209.Location = point210;
              this.PictureBox209.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox209, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 210:
              this.PictureBox210.Visible = true;
              PictureBox pictureBox210 = this.PictureBox210;
              point1 = new Point(x, y);
              Point point211 = point1;
              pictureBox210.Location = point211;
              this.PictureBox210.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox210, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 211:
              this.PictureBox211.Visible = true;
              PictureBox pictureBox211 = this.PictureBox211;
              point1 = new Point(x, y);
              Point point212 = point1;
              pictureBox211.Location = point212;
              this.PictureBox211.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox211, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 212:
              this.PictureBox212.Visible = true;
              PictureBox pictureBox212 = this.PictureBox212;
              point1 = new Point(x, y);
              Point point213 = point1;
              pictureBox212.Location = point213;
              this.PictureBox212.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox212, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 213:
              this.PictureBox213.Visible = true;
              PictureBox pictureBox213 = this.PictureBox213;
              point1 = new Point(x, y);
              Point point214 = point1;
              pictureBox213.Location = point214;
              this.PictureBox213.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox213, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 214:
              this.PictureBox214.Visible = true;
              PictureBox pictureBox214 = this.PictureBox214;
              point1 = new Point(x, y);
              Point point215 = point1;
              pictureBox214.Location = point215;
              this.PictureBox214.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox214, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 215:
              this.PictureBox215.Visible = true;
              PictureBox pictureBox215 = this.PictureBox215;
              point1 = new Point(x, y);
              Point point216 = point1;
              pictureBox215.Location = point216;
              this.PictureBox215.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox215, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 216:
              this.PictureBox216.Visible = true;
              PictureBox pictureBox216 = this.PictureBox216;
              point1 = new Point(x, y);
              Point point217 = point1;
              pictureBox216.Location = point217;
              this.PictureBox216.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox216, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 217:
              this.PictureBox217.Visible = true;
              PictureBox pictureBox217 = this.PictureBox217;
              point1 = new Point(x, y);
              Point point218 = point1;
              pictureBox217.Location = point218;
              this.PictureBox217.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox217, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 218:
              this.PictureBox218.Visible = true;
              PictureBox pictureBox218 = this.PictureBox218;
              point1 = new Point(x, y);
              Point point219 = point1;
              pictureBox218.Location = point219;
              this.PictureBox218.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox218, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 219:
              this.PictureBox219.Visible = true;
              PictureBox pictureBox219 = this.PictureBox219;
              point1 = new Point(x, y);
              Point point220 = point1;
              pictureBox219.Location = point220;
              this.PictureBox219.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox219, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 220:
              this.PictureBox220.Visible = true;
              PictureBox pictureBox220 = this.PictureBox220;
              point1 = new Point(x, y);
              Point point221 = point1;
              pictureBox220.Location = point221;
              this.PictureBox220.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox220, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 221:
              this.PictureBox221.Visible = true;
              PictureBox pictureBox221 = this.PictureBox221;
              point1 = new Point(x, y);
              Point point222 = point1;
              pictureBox221.Location = point222;
              this.PictureBox221.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox221, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 222:
              this.PictureBox222.Visible = true;
              PictureBox pictureBox222 = this.PictureBox222;
              point1 = new Point(x, y);
              Point point223 = point1;
              pictureBox222.Location = point223;
              this.PictureBox222.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox222, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 223:
              this.PictureBox223.Visible = true;
              PictureBox pictureBox223 = this.PictureBox223;
              point1 = new Point(x, y);
              Point point224 = point1;
              pictureBox223.Location = point224;
              this.PictureBox223.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox223, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 224:
              this.PictureBox224.Visible = true;
              PictureBox pictureBox224 = this.PictureBox224;
              point1 = new Point(x, y);
              Point point225 = point1;
              pictureBox224.Location = point225;
              this.PictureBox224.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox224, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 225:
              this.PictureBox225.Visible = true;
              PictureBox pictureBox225 = this.PictureBox225;
              point1 = new Point(x, y);
              Point point226 = point1;
              pictureBox225.Location = point226;
              this.PictureBox225.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox225, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 226:
              this.PictureBox226.Visible = true;
              PictureBox pictureBox226 = this.PictureBox226;
              point1 = new Point(x, y);
              Point point227 = point1;
              pictureBox226.Location = point227;
              this.PictureBox226.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox226, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 227:
              this.PictureBox227.Visible = true;
              PictureBox pictureBox227 = this.PictureBox227;
              point1 = new Point(x, y);
              Point point228 = point1;
              pictureBox227.Location = point228;
              this.PictureBox227.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox227, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 228:
              this.PictureBox228.Visible = true;
              PictureBox pictureBox228 = this.PictureBox228;
              point1 = new Point(x, y);
              Point point229 = point1;
              pictureBox228.Location = point229;
              this.PictureBox228.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox228, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 229:
              this.PictureBox229.Visible = true;
              PictureBox pictureBox229 = this.PictureBox229;
              point1 = new Point(x, y);
              Point point230 = point1;
              pictureBox229.Location = point230;
              this.PictureBox229.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox229, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 230:
              this.PictureBox230.Visible = true;
              PictureBox pictureBox230 = this.PictureBox230;
              point1 = new Point(x, y);
              Point point231 = point1;
              pictureBox230.Location = point231;
              this.PictureBox230.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox230, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 231:
              this.PictureBox231.Visible = true;
              PictureBox pictureBox231 = this.PictureBox231;
              point1 = new Point(x, y);
              Point point232 = point1;
              pictureBox231.Location = point232;
              this.PictureBox231.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox231, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 232:
              this.PictureBox232.Visible = true;
              PictureBox pictureBox232 = this.PictureBox232;
              point1 = new Point(x, y);
              Point point233 = point1;
              pictureBox232.Location = point233;
              this.PictureBox232.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox232, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 233:
              this.PictureBox233.Visible = true;
              PictureBox pictureBox233 = this.PictureBox233;
              point1 = new Point(x, y);
              Point point234 = point1;
              pictureBox233.Location = point234;
              this.PictureBox233.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox233, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 234:
              this.PictureBox234.Visible = true;
              PictureBox pictureBox234 = this.PictureBox234;
              point1 = new Point(x, y);
              Point point235 = point1;
              pictureBox234.Location = point235;
              this.PictureBox234.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox234, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 235:
              this.PictureBox235.Visible = true;
              PictureBox pictureBox235 = this.PictureBox235;
              point1 = new Point(x, y);
              Point point236 = point1;
              pictureBox235.Location = point236;
              this.PictureBox235.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox235, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 236:
              this.PictureBox236.Visible = true;
              PictureBox pictureBox236 = this.PictureBox236;
              point1 = new Point(x, y);
              Point point237 = point1;
              pictureBox236.Location = point237;
              this.PictureBox236.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox236, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 237:
              this.PictureBox237.Visible = true;
              PictureBox pictureBox237 = this.PictureBox237;
              point1 = new Point(x, y);
              Point point238 = point1;
              pictureBox237.Location = point238;
              this.PictureBox237.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox237, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 238:
              this.PictureBox238.Visible = true;
              PictureBox pictureBox238 = this.PictureBox238;
              point1 = new Point(x, y);
              Point point239 = point1;
              pictureBox238.Location = point239;
              this.PictureBox238.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox238, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 239:
              this.PictureBox239.Visible = true;
              PictureBox pictureBox239 = this.PictureBox239;
              point1 = new Point(x, y);
              Point point240 = point1;
              pictureBox239.Location = point240;
              this.PictureBox239.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox239, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 240:
              this.PictureBox240.Visible = true;
              PictureBox pictureBox240 = this.PictureBox240;
              point1 = new Point(x, y);
              Point point241 = point1;
              pictureBox240.Location = point241;
              this.PictureBox240.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox240, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 241:
              this.PictureBox241.Visible = true;
              PictureBox pictureBox241 = this.PictureBox241;
              point1 = new Point(x, y);
              Point point242 = point1;
              pictureBox241.Location = point242;
              this.PictureBox241.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox241, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 242:
              this.PictureBox242.Visible = true;
              PictureBox pictureBox242 = this.PictureBox242;
              point1 = new Point(x, y);
              Point point243 = point1;
              pictureBox242.Location = point243;
              this.PictureBox242.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox242, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 243:
              this.PictureBox243.Visible = true;
              PictureBox pictureBox243 = this.PictureBox243;
              point1 = new Point(x, y);
              Point point244 = point1;
              pictureBox243.Location = point244;
              this.PictureBox243.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox243, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 244:
              this.PictureBox244.Visible = true;
              PictureBox pictureBox244 = this.PictureBox244;
              point1 = new Point(x, y);
              Point point245 = point1;
              pictureBox244.Location = point245;
              this.PictureBox244.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox244, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 245:
              this.PictureBox245.Visible = true;
              PictureBox pictureBox245 = this.PictureBox245;
              point1 = new Point(x, y);
              Point point246 = point1;
              pictureBox245.Location = point246;
              this.PictureBox245.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox245, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 246:
              this.PictureBox246.Visible = true;
              PictureBox pictureBox246 = this.PictureBox246;
              point1 = new Point(x, y);
              Point point247 = point1;
              pictureBox246.Location = point247;
              this.PictureBox246.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox246, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 247:
              this.PictureBox247.Visible = true;
              PictureBox pictureBox247 = this.PictureBox247;
              point1 = new Point(x, y);
              Point point248 = point1;
              pictureBox247.Location = point248;
              this.PictureBox247.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox247, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 248:
              this.PictureBox248.Visible = true;
              PictureBox pictureBox248 = this.PictureBox248;
              point1 = new Point(x, y);
              Point point249 = point1;
              pictureBox248.Location = point249;
              this.PictureBox248.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox248, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 249:
              this.PictureBox249.Visible = true;
              PictureBox pictureBox249 = this.PictureBox249;
              point1 = new Point(x, y);
              Point point250 = point1;
              pictureBox249.Location = point250;
              this.PictureBox249.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox249, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 250:
              this.PictureBox250.Visible = true;
              PictureBox pictureBox250 = this.PictureBox250;
              point1 = new Point(x, y);
              Point point251 = point1;
              pictureBox250.Location = point251;
              this.PictureBox250.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox250, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 251:
              this.PictureBox251.Visible = true;
              PictureBox pictureBox251 = this.PictureBox251;
              point1 = new Point(x, y);
              Point point252 = point1;
              pictureBox251.Location = point252;
              this.PictureBox251.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox251, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 252:
              this.PictureBox252.Visible = true;
              PictureBox pictureBox252 = this.PictureBox252;
              point1 = new Point(x, y);
              Point point253 = point1;
              pictureBox252.Location = point253;
              this.PictureBox252.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox252, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 253:
              this.PictureBox253.Visible = true;
              PictureBox pictureBox253 = this.PictureBox253;
              point1 = new Point(x, y);
              Point point254 = point1;
              pictureBox253.Location = point254;
              this.PictureBox253.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox253, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 254:
              this.PictureBox254.Visible = true;
              PictureBox pictureBox254 = this.PictureBox254;
              point1 = new Point(x, y);
              Point point255 = point1;
              pictureBox254.Location = point255;
              this.PictureBox254.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox254, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case (int) byte.MaxValue:
              this.PictureBox255.Visible = true;
              PictureBox pictureBox255 = this.PictureBox255;
              point1 = new Point(x, y);
              Point point256 = point1;
              pictureBox255.Location = point256;
              this.PictureBox255.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox255, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 256:
              this.PictureBox256.Visible = true;
              PictureBox pictureBox256 = this.PictureBox256;
              point1 = new Point(x, y);
              Point point257 = point1;
              pictureBox256.Location = point257;
              this.PictureBox256.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox256, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 257:
              this.PictureBox257.Visible = true;
              PictureBox pictureBox257 = this.PictureBox257;
              point1 = new Point(x, y);
              Point point258 = point1;
              pictureBox257.Location = point258;
              this.PictureBox257.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox257, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 258:
              this.PictureBox258.Visible = true;
              PictureBox pictureBox258 = this.PictureBox258;
              point1 = new Point(x, y);
              Point point259 = point1;
              pictureBox258.Location = point259;
              this.PictureBox258.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox258, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 259:
              this.PictureBox259.Visible = true;
              PictureBox pictureBox259 = this.PictureBox259;
              point1 = new Point(x, y);
              Point point260 = point1;
              pictureBox259.Location = point260;
              this.PictureBox259.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox259, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 260:
              this.PictureBox260.Visible = true;
              PictureBox pictureBox260 = this.PictureBox260;
              point1 = new Point(x, y);
              Point point261 = point1;
              pictureBox260.Location = point261;
              this.PictureBox260.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox260, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 261:
              this.PictureBox261.Visible = true;
              PictureBox pictureBox261 = this.PictureBox261;
              point1 = new Point(x, y);
              Point point262 = point1;
              pictureBox261.Location = point262;
              this.PictureBox261.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox261, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 262:
              this.PictureBox262.Visible = true;
              PictureBox pictureBox262 = this.PictureBox262;
              point1 = new Point(x, y);
              Point point263 = point1;
              pictureBox262.Location = point263;
              this.PictureBox262.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox262, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 263:
              this.PictureBox263.Visible = true;
              PictureBox pictureBox263 = this.PictureBox263;
              point1 = new Point(x, y);
              Point point264 = point1;
              pictureBox263.Location = point264;
              this.PictureBox263.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox263, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 264:
              this.PictureBox264.Visible = true;
              PictureBox pictureBox264 = this.PictureBox264;
              point1 = new Point(x, y);
              Point point265 = point1;
              pictureBox264.Location = point265;
              this.PictureBox264.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox264, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 265:
              this.PictureBox265.Visible = true;
              PictureBox pictureBox265 = this.PictureBox265;
              point1 = new Point(x, y);
              Point point266 = point1;
              pictureBox265.Location = point266;
              this.PictureBox265.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox265, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 266:
              this.PictureBox266.Visible = true;
              PictureBox pictureBox266 = this.PictureBox266;
              point1 = new Point(x, y);
              Point point267 = point1;
              pictureBox266.Location = point267;
              this.PictureBox266.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox266, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 267:
              this.PictureBox267.Visible = true;
              PictureBox pictureBox267 = this.PictureBox267;
              point1 = new Point(x, y);
              Point point268 = point1;
              pictureBox267.Location = point268;
              this.PictureBox267.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox267, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 268:
              this.PictureBox268.Visible = true;
              PictureBox pictureBox268 = this.PictureBox268;
              point1 = new Point(x, y);
              Point point269 = point1;
              pictureBox268.Location = point269;
              this.PictureBox268.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox268, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 269:
              this.PictureBox269.Visible = true;
              PictureBox pictureBox269 = this.PictureBox269;
              point1 = new Point(x, y);
              Point point270 = point1;
              pictureBox269.Location = point270;
              this.PictureBox269.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox269, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 270:
              this.PictureBox270.Visible = true;
              PictureBox pictureBox270 = this.PictureBox270;
              point1 = new Point(x, y);
              Point point271 = point1;
              pictureBox270.Location = point271;
              this.PictureBox270.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox270, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 271:
              this.PictureBox271.Visible = true;
              PictureBox pictureBox271 = this.PictureBox271;
              point1 = new Point(x, y);
              Point point272 = point1;
              pictureBox271.Location = point272;
              this.PictureBox271.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox271, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 272:
              this.PictureBox272.Visible = true;
              PictureBox pictureBox272 = this.PictureBox272;
              point1 = new Point(x, y);
              Point point273 = point1;
              pictureBox272.Location = point273;
              this.PictureBox272.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox272, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 273:
              this.PictureBox273.Visible = true;
              PictureBox pictureBox273 = this.PictureBox273;
              point1 = new Point(x, y);
              Point point274 = point1;
              pictureBox273.Location = point274;
              this.PictureBox273.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox273, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 274:
              this.PictureBox274.Visible = true;
              PictureBox pictureBox274 = this.PictureBox274;
              point1 = new Point(x, y);
              Point point275 = point1;
              pictureBox274.Location = point275;
              this.PictureBox274.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox274, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 275:
              this.PictureBox275.Visible = true;
              PictureBox pictureBox275 = this.PictureBox275;
              point1 = new Point(x, y);
              Point point276 = point1;
              pictureBox275.Location = point276;
              this.PictureBox275.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox275, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 276:
              this.PictureBox276.Visible = true;
              PictureBox pictureBox276 = this.PictureBox276;
              point1 = new Point(x, y);
              Point point277 = point1;
              pictureBox276.Location = point277;
              this.PictureBox276.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox276, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 277:
              this.PictureBox277.Visible = true;
              PictureBox pictureBox277 = this.PictureBox277;
              point1 = new Point(x, y);
              Point point278 = point1;
              pictureBox277.Location = point278;
              this.PictureBox277.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox277, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 278:
              this.PictureBox278.Visible = true;
              PictureBox pictureBox278 = this.PictureBox278;
              point1 = new Point(x, y);
              Point point279 = point1;
              pictureBox278.Location = point279;
              this.PictureBox278.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox278, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 279:
              this.PictureBox279.Visible = true;
              PictureBox pictureBox279 = this.PictureBox279;
              point1 = new Point(x, y);
              Point point280 = point1;
              pictureBox279.Location = point280;
              this.PictureBox279.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox279, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 280:
              this.PictureBox280.Visible = true;
              PictureBox pictureBox280 = this.PictureBox280;
              point1 = new Point(x, y);
              Point point281 = point1;
              pictureBox280.Location = point281;
              this.PictureBox280.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox280, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 281:
              this.PictureBox281.Visible = true;
              PictureBox pictureBox281 = this.PictureBox281;
              point1 = new Point(x, y);
              Point point282 = point1;
              pictureBox281.Location = point282;
              this.PictureBox281.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox281, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 282:
              this.PictureBox282.Visible = true;
              PictureBox pictureBox282 = this.PictureBox282;
              point1 = new Point(x, y);
              Point point283 = point1;
              pictureBox282.Location = point283;
              this.PictureBox282.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox282, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 283:
              this.PictureBox283.Visible = true;
              PictureBox pictureBox283 = this.PictureBox283;
              point1 = new Point(x, y);
              Point point284 = point1;
              pictureBox283.Location = point284;
              this.PictureBox283.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox283, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 284:
              this.PictureBox284.Visible = true;
              PictureBox pictureBox284 = this.PictureBox284;
              point1 = new Point(x, y);
              Point point285 = point1;
              pictureBox284.Location = point285;
              this.PictureBox284.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox284, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 285:
              this.PictureBox285.Visible = true;
              PictureBox pictureBox285 = this.PictureBox285;
              point1 = new Point(x, y);
              Point point286 = point1;
              pictureBox285.Location = point286;
              this.PictureBox285.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox285, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 286:
              this.PictureBox286.Visible = true;
              PictureBox pictureBox286 = this.PictureBox286;
              point1 = new Point(x, y);
              Point point287 = point1;
              pictureBox286.Location = point287;
              this.PictureBox286.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox286, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 287:
              this.PictureBox287.Visible = true;
              PictureBox pictureBox287 = this.PictureBox287;
              point1 = new Point(x, y);
              Point point288 = point1;
              pictureBox287.Location = point288;
              this.PictureBox287.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox287, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 288:
              this.PictureBox288.Visible = true;
              PictureBox pictureBox288 = this.PictureBox288;
              point1 = new Point(x, y);
              Point point289 = point1;
              pictureBox288.Location = point289;
              this.PictureBox288.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox288, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 289:
              this.PictureBox289.Visible = true;
              PictureBox pictureBox289 = this.PictureBox289;
              point1 = new Point(x, y);
              Point point290 = point1;
              pictureBox289.Location = point290;
              this.PictureBox289.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox289, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 290:
              this.PictureBox290.Visible = true;
              PictureBox pictureBox290 = this.PictureBox290;
              point1 = new Point(x, y);
              Point point291 = point1;
              pictureBox290.Location = point291;
              this.PictureBox290.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox290, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 291:
              this.PictureBox291.Visible = true;
              PictureBox pictureBox291 = this.PictureBox291;
              point1 = new Point(x, y);
              Point point292 = point1;
              pictureBox291.Location = point292;
              this.PictureBox291.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox291, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 292:
              this.PictureBox292.Visible = true;
              PictureBox pictureBox292 = this.PictureBox292;
              point1 = new Point(x, y);
              Point point293 = point1;
              pictureBox292.Location = point293;
              this.PictureBox292.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox292, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 293:
              this.PictureBox293.Visible = true;
              PictureBox pictureBox293 = this.PictureBox293;
              point1 = new Point(x, y);
              Point point294 = point1;
              pictureBox293.Location = point294;
              this.PictureBox293.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox293, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 294:
              this.PictureBox294.Visible = true;
              PictureBox pictureBox294 = this.PictureBox294;
              point1 = new Point(x, y);
              Point point295 = point1;
              pictureBox294.Location = point295;
              this.PictureBox294.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox294, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 295:
              this.PictureBox295.Visible = true;
              PictureBox pictureBox295 = this.PictureBox295;
              point1 = new Point(x, y);
              Point point296 = point1;
              pictureBox295.Location = point296;
              this.PictureBox295.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox295, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 296:
              this.PictureBox296.Visible = true;
              PictureBox pictureBox296 = this.PictureBox296;
              point1 = new Point(x, y);
              Point point297 = point1;
              pictureBox296.Location = point297;
              this.PictureBox296.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox296, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 297:
              this.PictureBox297.Visible = true;
              PictureBox pictureBox297 = this.PictureBox297;
              point1 = new Point(x, y);
              Point point298 = point1;
              pictureBox297.Location = point298;
              this.PictureBox297.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox297, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 298:
              this.PictureBox298.Visible = true;
              PictureBox pictureBox298 = this.PictureBox298;
              point1 = new Point(x, y);
              Point point299 = point1;
              pictureBox298.Location = point299;
              this.PictureBox298.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox298, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 299:
              this.PictureBox299.Visible = true;
              PictureBox pictureBox299 = this.PictureBox299;
              point1 = new Point(x, y);
              Point point300 = point1;
              pictureBox299.Location = point300;
              this.PictureBox299.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox299, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 300:
              this.PictureBox300.Visible = true;
              PictureBox pictureBox300 = this.PictureBox300;
              point1 = new Point(x, y);
              Point point301 = point1;
              pictureBox300.Location = point301;
              this.PictureBox300.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox300, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 301:
              this.PictureBox301.Visible = true;
              PictureBox pictureBox301 = this.PictureBox301;
              point1 = new Point(x, y);
              Point point302 = point1;
              pictureBox301.Location = point302;
              this.PictureBox301.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox301, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 302:
              this.PictureBox302.Visible = true;
              PictureBox pictureBox302 = this.PictureBox302;
              point1 = new Point(x, y);
              Point point303 = point1;
              pictureBox302.Location = point303;
              this.PictureBox302.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox302, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 303:
              this.PictureBox303.Visible = true;
              PictureBox pictureBox303 = this.PictureBox303;
              point1 = new Point(x, y);
              Point point304 = point1;
              pictureBox303.Location = point304;
              this.PictureBox303.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox303, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 304:
              this.PictureBox304.Visible = true;
              PictureBox pictureBox304 = this.PictureBox304;
              point1 = new Point(x, y);
              Point point305 = point1;
              pictureBox304.Location = point305;
              this.PictureBox304.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox304, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 305:
              this.PictureBox305.Visible = true;
              PictureBox pictureBox305 = this.PictureBox305;
              point1 = new Point(x, y);
              Point point306 = point1;
              pictureBox305.Location = point306;
              this.PictureBox305.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox305, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 306:
              this.PictureBox306.Visible = true;
              PictureBox pictureBox306 = this.PictureBox306;
              point1 = new Point(x, y);
              Point point307 = point1;
              pictureBox306.Location = point307;
              this.PictureBox306.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox306, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 307:
              this.PictureBox307.Visible = true;
              PictureBox pictureBox307 = this.PictureBox307;
              point1 = new Point(x, y);
              Point point308 = point1;
              pictureBox307.Location = point308;
              this.PictureBox307.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox307, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 308:
              this.PictureBox308.Visible = true;
              PictureBox pictureBox308 = this.PictureBox308;
              point1 = new Point(x, y);
              Point point309 = point1;
              pictureBox308.Location = point309;
              this.PictureBox308.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox308, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 309:
              this.PictureBox309.Visible = true;
              PictureBox pictureBox309 = this.PictureBox309;
              point1 = new Point(x, y);
              Point point310 = point1;
              pictureBox309.Location = point310;
              this.PictureBox309.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox309, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 310:
              this.PictureBox310.Visible = true;
              PictureBox pictureBox310 = this.PictureBox310;
              point1 = new Point(x, y);
              Point point311 = point1;
              pictureBox310.Location = point311;
              this.PictureBox310.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox310, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 311:
              this.PictureBox311.Visible = true;
              PictureBox pictureBox311 = this.PictureBox311;
              point1 = new Point(x, y);
              Point point312 = point1;
              pictureBox311.Location = point312;
              this.PictureBox311.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox311, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 312:
              this.PictureBox312.Visible = true;
              PictureBox pictureBox312 = this.PictureBox312;
              point1 = new Point(x, y);
              Point point313 = point1;
              pictureBox312.Location = point313;
              this.PictureBox312.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox312, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 313:
              this.PictureBox313.Visible = true;
              PictureBox pictureBox313 = this.PictureBox313;
              point1 = new Point(x, y);
              Point point314 = point1;
              pictureBox313.Location = point314;
              this.PictureBox313.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox313, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 314:
              this.PictureBox314.Visible = true;
              PictureBox pictureBox314 = this.PictureBox314;
              point1 = new Point(x, y);
              Point point315 = point1;
              pictureBox314.Location = point315;
              this.PictureBox314.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox314, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 315:
              this.PictureBox315.Visible = true;
              PictureBox pictureBox315 = this.PictureBox315;
              point1 = new Point(x, y);
              Point point316 = point1;
              pictureBox315.Location = point316;
              this.PictureBox315.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox315, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 316:
              this.PictureBox316.Visible = true;
              PictureBox pictureBox316 = this.PictureBox316;
              point1 = new Point(x, y);
              Point point317 = point1;
              pictureBox316.Location = point317;
              this.PictureBox316.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox316, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 317:
              this.PictureBox317.Visible = true;
              PictureBox pictureBox317 = this.PictureBox317;
              point1 = new Point(x, y);
              Point point318 = point1;
              pictureBox317.Location = point318;
              this.PictureBox317.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox317, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 318:
              this.PictureBox318.Visible = true;
              PictureBox pictureBox318 = this.PictureBox318;
              point1 = new Point(x, y);
              Point point319 = point1;
              pictureBox318.Location = point319;
              this.PictureBox318.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox318, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 319:
              this.PictureBox319.Visible = true;
              PictureBox pictureBox319 = this.PictureBox319;
              point1 = new Point(x, y);
              Point point320 = point1;
              pictureBox319.Location = point320;
              this.PictureBox319.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox319, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 320:
              this.PictureBox320.Visible = true;
              PictureBox pictureBox320 = this.PictureBox320;
              point1 = new Point(x, y);
              Point point321 = point1;
              pictureBox320.Location = point321;
              this.PictureBox320.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox320, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 321:
              this.PictureBox321.Visible = true;
              PictureBox pictureBox321 = this.PictureBox321;
              point1 = new Point(x, y);
              Point point322 = point1;
              pictureBox321.Location = point322;
              this.PictureBox321.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox321, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 322:
              this.PictureBox322.Visible = true;
              PictureBox pictureBox322 = this.PictureBox322;
              point1 = new Point(x, y);
              Point point323 = point1;
              pictureBox322.Location = point323;
              this.PictureBox322.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox322, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 323:
              this.PictureBox323.Visible = true;
              PictureBox pictureBox323 = this.PictureBox323;
              point1 = new Point(x, y);
              Point point324 = point1;
              pictureBox323.Location = point324;
              this.PictureBox323.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox323, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 324:
              this.PictureBox324.Visible = true;
              PictureBox pictureBox324 = this.PictureBox324;
              point1 = new Point(x, y);
              Point point325 = point1;
              pictureBox324.Location = point325;
              this.PictureBox324.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox324, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 325:
              this.PictureBox325.Visible = true;
              PictureBox pictureBox325 = this.PictureBox325;
              point1 = new Point(x, y);
              Point point326 = point1;
              pictureBox325.Location = point326;
              this.PictureBox325.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox325, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 326:
              this.PictureBox326.Visible = true;
              PictureBox pictureBox326 = this.PictureBox326;
              point1 = new Point(x, y);
              Point point327 = point1;
              pictureBox326.Location = point327;
              this.PictureBox326.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox326, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 327:
              this.PictureBox327.Visible = true;
              PictureBox pictureBox327 = this.PictureBox327;
              point1 = new Point(x, y);
              Point point328 = point1;
              pictureBox327.Location = point328;
              this.PictureBox327.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox327, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 328:
              this.PictureBox328.Visible = true;
              PictureBox pictureBox328 = this.PictureBox328;
              point1 = new Point(x, y);
              Point point329 = point1;
              pictureBox328.Location = point329;
              this.PictureBox328.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox328, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 329:
              this.PictureBox329.Visible = true;
              PictureBox pictureBox329 = this.PictureBox329;
              point1 = new Point(x, y);
              Point point330 = point1;
              pictureBox329.Location = point330;
              this.PictureBox329.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox329, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 330:
              this.PictureBox330.Visible = true;
              PictureBox pictureBox330 = this.PictureBox330;
              point1 = new Point(x, y);
              Point point331 = point1;
              pictureBox330.Location = point331;
              this.PictureBox330.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox330, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 331:
              this.PictureBox331.Visible = true;
              PictureBox pictureBox331 = this.PictureBox331;
              point1 = new Point(x, y);
              Point point332 = point1;
              pictureBox331.Location = point332;
              this.PictureBox331.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox331, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 332:
              this.PictureBox332.Visible = true;
              PictureBox pictureBox332 = this.PictureBox332;
              point1 = new Point(x, y);
              Point point333 = point1;
              pictureBox332.Location = point333;
              this.PictureBox332.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox332, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 333:
              this.PictureBox333.Visible = true;
              PictureBox pictureBox333 = this.PictureBox333;
              point1 = new Point(x, y);
              Point point334 = point1;
              pictureBox333.Location = point334;
              this.PictureBox333.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox333, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 334:
              this.PictureBox334.Visible = true;
              PictureBox pictureBox334 = this.PictureBox334;
              point1 = new Point(x, y);
              Point point335 = point1;
              pictureBox334.Location = point335;
              this.PictureBox334.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox334, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 335:
              this.PictureBox335.Visible = true;
              PictureBox pictureBox335 = this.PictureBox335;
              point1 = new Point(x, y);
              Point point336 = point1;
              pictureBox335.Location = point336;
              this.PictureBox335.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox335, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 336:
              this.PictureBox336.Visible = true;
              PictureBox pictureBox336 = this.PictureBox336;
              point1 = new Point(x, y);
              Point point337 = point1;
              pictureBox336.Location = point337;
              this.PictureBox336.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox336, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 337:
              this.PictureBox337.Visible = true;
              PictureBox pictureBox337 = this.PictureBox337;
              point1 = new Point(x, y);
              Point point338 = point1;
              pictureBox337.Location = point338;
              this.PictureBox337.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox337, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 338:
              this.PictureBox338.Visible = true;
              PictureBox pictureBox338 = this.PictureBox338;
              point1 = new Point(x, y);
              Point point339 = point1;
              pictureBox338.Location = point339;
              this.PictureBox338.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox338, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 339:
              this.PictureBox339.Visible = true;
              PictureBox pictureBox339 = this.PictureBox339;
              point1 = new Point(x, y);
              Point point340 = point1;
              pictureBox339.Location = point340;
              this.PictureBox339.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox339, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 340:
              this.PictureBox340.Visible = true;
              PictureBox pictureBox340 = this.PictureBox340;
              point1 = new Point(x, y);
              Point point341 = point1;
              pictureBox340.Location = point341;
              this.PictureBox340.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox340, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 341:
              this.PictureBox341.Visible = true;
              PictureBox pictureBox341 = this.PictureBox341;
              point1 = new Point(x, y);
              Point point342 = point1;
              pictureBox341.Location = point342;
              this.PictureBox341.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox341, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 342:
              this.PictureBox342.Visible = true;
              PictureBox pictureBox342 = this.PictureBox342;
              point1 = new Point(x, y);
              Point point343 = point1;
              pictureBox342.Location = point343;
              this.PictureBox342.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox342, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 343:
              this.PictureBox343.Visible = true;
              PictureBox pictureBox343 = this.PictureBox343;
              point1 = new Point(x, y);
              Point point344 = point1;
              pictureBox343.Location = point344;
              this.PictureBox343.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox343, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 344:
              this.PictureBox344.Visible = true;
              PictureBox pictureBox344 = this.PictureBox344;
              point1 = new Point(x, y);
              Point point345 = point1;
              pictureBox344.Location = point345;
              this.PictureBox344.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox344, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 345:
              this.PictureBox345.Visible = true;
              PictureBox pictureBox345 = this.PictureBox345;
              point1 = new Point(x, y);
              Point point346 = point1;
              pictureBox345.Location = point346;
              this.PictureBox345.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox345, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 346:
              this.PictureBox346.Visible = true;
              PictureBox pictureBox346 = this.PictureBox346;
              point1 = new Point(x, y);
              Point point347 = point1;
              pictureBox346.Location = point347;
              this.PictureBox346.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox346, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 347:
              this.PictureBox347.Visible = true;
              PictureBox pictureBox347 = this.PictureBox347;
              point1 = new Point(x, y);
              Point point348 = point1;
              pictureBox347.Location = point348;
              this.PictureBox347.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox347, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 348:
              this.PictureBox348.Visible = true;
              PictureBox pictureBox348 = this.PictureBox348;
              point1 = new Point(x, y);
              Point point349 = point1;
              pictureBox348.Location = point349;
              this.PictureBox348.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox348, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 349:
              this.PictureBox349.Visible = true;
              PictureBox pictureBox349 = this.PictureBox349;
              point1 = new Point(x, y);
              Point point350 = point1;
              pictureBox349.Location = point350;
              this.PictureBox349.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox349, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 350:
              this.PictureBox350.Visible = true;
              PictureBox pictureBox350 = this.PictureBox350;
              point1 = new Point(x, y);
              Point point351 = point1;
              pictureBox350.Location = point351;
              this.PictureBox350.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox350, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 351:
              this.PictureBox351.Visible = true;
              PictureBox pictureBox351 = this.PictureBox351;
              point1 = new Point(x, y);
              Point point352 = point1;
              pictureBox351.Location = point352;
              this.PictureBox351.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox351, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 352:
              this.PictureBox352.Visible = true;
              PictureBox pictureBox352 = this.PictureBox352;
              point1 = new Point(x, y);
              Point point353 = point1;
              pictureBox352.Location = point353;
              this.PictureBox352.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox352, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 353:
              this.PictureBox353.Visible = true;
              PictureBox pictureBox353 = this.PictureBox353;
              point1 = new Point(x, y);
              Point point354 = point1;
              pictureBox353.Location = point354;
              this.PictureBox353.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox353, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 354:
              this.PictureBox354.Visible = true;
              PictureBox pictureBox354 = this.PictureBox354;
              point1 = new Point(x, y);
              Point point355 = point1;
              pictureBox354.Location = point355;
              this.PictureBox354.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox354, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 355:
              this.PictureBox355.Visible = true;
              PictureBox pictureBox355 = this.PictureBox355;
              point1 = new Point(x, y);
              Point point356 = point1;
              pictureBox355.Location = point356;
              this.PictureBox355.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox355, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 356:
              this.PictureBox356.Visible = true;
              PictureBox pictureBox356 = this.PictureBox356;
              point1 = new Point(x, y);
              Point point357 = point1;
              pictureBox356.Location = point357;
              this.PictureBox356.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox356, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 357:
              this.PictureBox357.Visible = true;
              PictureBox pictureBox357 = this.PictureBox357;
              point1 = new Point(x, y);
              Point point358 = point1;
              pictureBox357.Location = point358;
              this.PictureBox357.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox357, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 358:
              this.PictureBox358.Visible = true;
              PictureBox pictureBox358 = this.PictureBox358;
              point1 = new Point(x, y);
              Point point359 = point1;
              pictureBox358.Location = point359;
              this.PictureBox358.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox358, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 359:
              this.PictureBox359.Visible = true;
              PictureBox pictureBox359 = this.PictureBox359;
              point1 = new Point(x, y);
              Point point360 = point1;
              pictureBox359.Location = point360;
              this.PictureBox359.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox359, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 360:
              this.PictureBox360.Visible = true;
              PictureBox pictureBox360 = this.PictureBox360;
              point1 = new Point(x, y);
              Point point361 = point1;
              pictureBox360.Location = point361;
              this.PictureBox360.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox360, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 361:
              this.PictureBox361.Visible = true;
              PictureBox pictureBox361 = this.PictureBox361;
              point1 = new Point(x, y);
              Point point362 = point1;
              pictureBox361.Location = point362;
              this.PictureBox361.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox361, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 362:
              this.PictureBox362.Visible = true;
              PictureBox pictureBox362 = this.PictureBox362;
              point1 = new Point(x, y);
              Point point363 = point1;
              pictureBox362.Location = point363;
              this.PictureBox362.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox362, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 363:
              this.PictureBox363.Visible = true;
              PictureBox pictureBox363 = this.PictureBox363;
              point1 = new Point(x, y);
              Point point364 = point1;
              pictureBox363.Location = point364;
              this.PictureBox363.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox363, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 364:
              this.PictureBox364.Visible = true;
              PictureBox pictureBox364 = this.PictureBox364;
              point1 = new Point(x, y);
              Point point365 = point1;
              pictureBox364.Location = point365;
              this.PictureBox364.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox364, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 365:
              this.PictureBox365.Visible = true;
              PictureBox pictureBox365 = this.PictureBox365;
              point1 = new Point(x, y);
              Point point366 = point1;
              pictureBox365.Location = point366;
              this.PictureBox365.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox365, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 366:
              this.PictureBox366.Visible = true;
              PictureBox pictureBox366 = this.PictureBox366;
              point1 = new Point(x, y);
              Point point367 = point1;
              pictureBox366.Location = point367;
              this.PictureBox366.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox366, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 367:
              this.PictureBox367.Visible = true;
              PictureBox pictureBox367 = this.PictureBox367;
              point1 = new Point(x, y);
              Point point368 = point1;
              pictureBox367.Location = point368;
              this.PictureBox367.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox367, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 368:
              this.PictureBox368.Visible = true;
              PictureBox pictureBox368 = this.PictureBox368;
              point1 = new Point(x, y);
              Point point369 = point1;
              pictureBox368.Location = point369;
              this.PictureBox368.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox368, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 369:
              this.PictureBox369.Visible = true;
              PictureBox pictureBox369 = this.PictureBox369;
              point1 = new Point(x, y);
              Point point370 = point1;
              pictureBox369.Location = point370;
              this.PictureBox369.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox369, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 370:
              this.PictureBox370.Visible = true;
              PictureBox pictureBox370 = this.PictureBox370;
              point1 = new Point(x, y);
              Point point371 = point1;
              pictureBox370.Location = point371;
              this.PictureBox370.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox370, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 371:
              this.PictureBox371.Visible = true;
              PictureBox pictureBox371 = this.PictureBox371;
              point1 = new Point(x, y);
              Point point372 = point1;
              pictureBox371.Location = point372;
              this.PictureBox371.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox371, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 372:
              this.PictureBox372.Visible = true;
              PictureBox pictureBox372 = this.PictureBox372;
              point1 = new Point(x, y);
              Point point373 = point1;
              pictureBox372.Location = point373;
              this.PictureBox372.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox372, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 373:
              this.PictureBox373.Visible = true;
              PictureBox pictureBox373 = this.PictureBox373;
              point1 = new Point(x, y);
              Point point374 = point1;
              pictureBox373.Location = point374;
              this.PictureBox373.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox373, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 374:
              this.PictureBox374.Visible = true;
              PictureBox pictureBox374 = this.PictureBox374;
              point1 = new Point(x, y);
              Point point375 = point1;
              pictureBox374.Location = point375;
              this.PictureBox374.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox374, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 375:
              this.PictureBox375.Visible = true;
              PictureBox pictureBox375 = this.PictureBox375;
              point1 = new Point(x, y);
              Point point376 = point1;
              pictureBox375.Location = point376;
              this.PictureBox375.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox375, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 376:
              this.PictureBox376.Visible = true;
              PictureBox pictureBox376 = this.PictureBox376;
              point1 = new Point(x, y);
              Point point377 = point1;
              pictureBox376.Location = point377;
              this.PictureBox376.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox376, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 377:
              this.PictureBox377.Visible = true;
              PictureBox pictureBox377 = this.PictureBox377;
              point1 = new Point(x, y);
              Point point378 = point1;
              pictureBox377.Location = point378;
              this.PictureBox377.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox377, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 378:
              this.PictureBox378.Visible = true;
              PictureBox pictureBox378 = this.PictureBox378;
              point1 = new Point(x, y);
              Point point379 = point1;
              pictureBox378.Location = point379;
              this.PictureBox378.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox378, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 379:
              this.PictureBox379.Visible = true;
              PictureBox pictureBox379 = this.PictureBox379;
              point1 = new Point(x, y);
              Point point380 = point1;
              pictureBox379.Location = point380;
              this.PictureBox379.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox379, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 380:
              this.PictureBox380.Visible = true;
              PictureBox pictureBox380 = this.PictureBox380;
              point1 = new Point(x, y);
              Point point381 = point1;
              pictureBox380.Location = point381;
              this.PictureBox380.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox380, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 381:
              this.PictureBox381.Visible = true;
              PictureBox pictureBox381 = this.PictureBox381;
              point1 = new Point(x, y);
              Point point382 = point1;
              pictureBox381.Location = point382;
              this.PictureBox381.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox381, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 382:
              this.PictureBox382.Visible = true;
              PictureBox pictureBox382 = this.PictureBox382;
              point1 = new Point(x, y);
              Point point383 = point1;
              pictureBox382.Location = point383;
              this.PictureBox382.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox382, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 383:
              this.PictureBox383.Visible = true;
              PictureBox pictureBox383 = this.PictureBox383;
              point1 = new Point(x, y);
              Point point384 = point1;
              pictureBox383.Location = point384;
              this.PictureBox383.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox383, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 384:
              this.PictureBox384.Visible = true;
              PictureBox pictureBox384 = this.PictureBox384;
              point1 = new Point(x, y);
              Point point385 = point1;
              pictureBox384.Location = point385;
              this.PictureBox384.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox384, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 385:
              this.PictureBox385.Visible = true;
              PictureBox pictureBox385 = this.PictureBox385;
              point1 = new Point(x, y);
              Point point386 = point1;
              pictureBox385.Location = point386;
              this.PictureBox385.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox385, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 386:
              this.PictureBox386.Visible = true;
              PictureBox pictureBox386 = this.PictureBox386;
              point1 = new Point(x, y);
              Point point387 = point1;
              pictureBox386.Location = point387;
              this.PictureBox386.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox386, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 387:
              this.PictureBox387.Visible = true;
              PictureBox pictureBox387 = this.PictureBox387;
              point1 = new Point(x, y);
              Point point388 = point1;
              pictureBox387.Location = point388;
              this.PictureBox387.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox387, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 388:
              this.PictureBox388.Visible = true;
              PictureBox pictureBox388 = this.PictureBox388;
              point1 = new Point(x, y);
              Point point389 = point1;
              pictureBox388.Location = point389;
              this.PictureBox388.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox388, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 389:
              this.PictureBox389.Visible = true;
              PictureBox pictureBox389 = this.PictureBox389;
              point1 = new Point(x, y);
              Point point390 = point1;
              pictureBox389.Location = point390;
              this.PictureBox389.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox389, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 390:
              this.PictureBox390.Visible = true;
              PictureBox pictureBox390 = this.PictureBox390;
              point1 = new Point(x, y);
              Point point391 = point1;
              pictureBox390.Location = point391;
              this.PictureBox390.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox390, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 391:
              this.PictureBox391.Visible = true;
              PictureBox pictureBox391 = this.PictureBox391;
              point1 = new Point(x, y);
              Point point392 = point1;
              pictureBox391.Location = point392;
              this.PictureBox391.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox391, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 392:
              this.PictureBox392.Visible = true;
              PictureBox pictureBox392 = this.PictureBox392;
              point1 = new Point(x, y);
              Point point393 = point1;
              pictureBox392.Location = point393;
              this.PictureBox392.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox392, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 393:
              this.PictureBox393.Visible = true;
              PictureBox pictureBox393 = this.PictureBox393;
              point1 = new Point(x, y);
              Point point394 = point1;
              pictureBox393.Location = point394;
              this.PictureBox393.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox393, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 394:
              this.PictureBox394.Visible = true;
              PictureBox pictureBox394 = this.PictureBox394;
              point1 = new Point(x, y);
              Point point395 = point1;
              pictureBox394.Location = point395;
              this.PictureBox394.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox394, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 395:
              this.PictureBox395.Visible = true;
              PictureBox pictureBox395 = this.PictureBox395;
              point1 = new Point(x, y);
              Point point396 = point1;
              pictureBox395.Location = point396;
              this.PictureBox395.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox395, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 396:
              this.PictureBox396.Visible = true;
              PictureBox pictureBox396 = this.PictureBox396;
              point1 = new Point(x, y);
              Point point397 = point1;
              pictureBox396.Location = point397;
              this.PictureBox396.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox396, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 397:
              this.PictureBox397.Visible = true;
              PictureBox pictureBox397 = this.PictureBox397;
              point1 = new Point(x, y);
              Point point398 = point1;
              pictureBox397.Location = point398;
              this.PictureBox397.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox397, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 398:
              this.PictureBox398.Visible = true;
              PictureBox pictureBox398 = this.PictureBox398;
              point1 = new Point(x, y);
              Point point399 = point1;
              pictureBox398.Location = point399;
              this.PictureBox398.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox398, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 399:
              this.PictureBox399.Visible = true;
              PictureBox pictureBox399 = this.PictureBox399;
              point1 = new Point(x, y);
              Point point400 = point1;
              pictureBox399.Location = point400;
              this.PictureBox399.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox399, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 400:
              this.PictureBox400.Visible = true;
              PictureBox pictureBox400 = this.PictureBox400;
              point1 = new Point(x, y);
              Point point401 = point1;
              pictureBox400.Location = point401;
              this.PictureBox400.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox400, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 401:
              this.PictureBox401.Visible = true;
              PictureBox pictureBox401 = this.PictureBox401;
              point1 = new Point(x, y);
              Point point402 = point1;
              pictureBox401.Location = point402;
              this.PictureBox401.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox401, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 402:
              this.PictureBox402.Visible = true;
              PictureBox pictureBox402 = this.PictureBox402;
              point1 = new Point(x, y);
              Point point403 = point1;
              pictureBox402.Location = point403;
              this.PictureBox402.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox402, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 403:
              this.PictureBox403.Visible = true;
              PictureBox pictureBox403 = this.PictureBox403;
              point1 = new Point(x, y);
              Point point404 = point1;
              pictureBox403.Location = point404;
              this.PictureBox403.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox403, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 404:
              this.PictureBox404.Visible = true;
              PictureBox pictureBox404 = this.PictureBox404;
              point1 = new Point(x, y);
              Point point405 = point1;
              pictureBox404.Location = point405;
              this.PictureBox404.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox404, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 405:
              this.PictureBox405.Visible = true;
              PictureBox pictureBox405 = this.PictureBox405;
              point1 = new Point(x, y);
              Point point406 = point1;
              pictureBox405.Location = point406;
              this.PictureBox405.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox405, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 406:
              this.PictureBox406.Visible = true;
              PictureBox pictureBox406 = this.PictureBox406;
              point1 = new Point(x, y);
              Point point407 = point1;
              pictureBox406.Location = point407;
              this.PictureBox406.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox406, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 407:
              this.PictureBox407.Visible = true;
              PictureBox pictureBox407 = this.PictureBox407;
              point1 = new Point(x, y);
              Point point408 = point1;
              pictureBox407.Location = point408;
              this.PictureBox407.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox407, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 408:
              this.PictureBox408.Visible = true;
              PictureBox pictureBox408 = this.PictureBox408;
              point1 = new Point(x, y);
              Point point409 = point1;
              pictureBox408.Location = point409;
              this.PictureBox408.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox408, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 409:
              this.PictureBox409.Visible = true;
              PictureBox pictureBox409 = this.PictureBox409;
              point1 = new Point(x, y);
              Point point410 = point1;
              pictureBox409.Location = point410;
              this.PictureBox409.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox409, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 410:
              this.PictureBox410.Visible = true;
              PictureBox pictureBox410 = this.PictureBox410;
              point1 = new Point(x, y);
              Point point411 = point1;
              pictureBox410.Location = point411;
              this.PictureBox410.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox410, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 411:
              this.PictureBox411.Visible = true;
              PictureBox pictureBox411 = this.PictureBox411;
              point1 = new Point(x, y);
              Point point412 = point1;
              pictureBox411.Location = point412;
              this.PictureBox411.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox411, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 412:
              this.PictureBox412.Visible = true;
              PictureBox pictureBox412 = this.PictureBox412;
              point1 = new Point(x, y);
              Point point413 = point1;
              pictureBox412.Location = point413;
              this.PictureBox412.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox412, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 413:
              this.PictureBox413.Visible = true;
              PictureBox pictureBox413 = this.PictureBox413;
              point1 = new Point(x, y);
              Point point414 = point1;
              pictureBox413.Location = point414;
              this.PictureBox413.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox413, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 414:
              this.PictureBox414.Visible = true;
              PictureBox pictureBox414 = this.PictureBox414;
              point1 = new Point(x, y);
              Point point415 = point1;
              pictureBox414.Location = point415;
              this.PictureBox414.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox414, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 415:
              this.PictureBox415.Visible = true;
              PictureBox pictureBox415 = this.PictureBox415;
              point1 = new Point(x, y);
              Point point416 = point1;
              pictureBox415.Location = point416;
              this.PictureBox415.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox415, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 416:
              this.PictureBox416.Visible = true;
              PictureBox pictureBox416 = this.PictureBox416;
              point1 = new Point(x, y);
              Point point417 = point1;
              pictureBox416.Location = point417;
              this.PictureBox416.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox416, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 417:
              this.PictureBox417.Visible = true;
              PictureBox pictureBox417 = this.PictureBox417;
              point1 = new Point(x, y);
              Point point418 = point1;
              pictureBox417.Location = point418;
              this.PictureBox417.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox417, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 418:
              this.PictureBox418.Visible = true;
              PictureBox pictureBox418 = this.PictureBox418;
              point1 = new Point(x, y);
              Point point419 = point1;
              pictureBox418.Location = point419;
              this.PictureBox418.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox418, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 419:
              this.PictureBox419.Visible = true;
              PictureBox pictureBox419 = this.PictureBox419;
              point1 = new Point(x, y);
              Point point420 = point1;
              pictureBox419.Location = point420;
              this.PictureBox419.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox419, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 420:
              this.PictureBox420.Visible = true;
              PictureBox pictureBox420 = this.PictureBox420;
              point1 = new Point(x, y);
              Point point421 = point1;
              pictureBox420.Location = point421;
              this.PictureBox420.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox420, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 421:
              this.PictureBox421.Visible = true;
              PictureBox pictureBox421 = this.PictureBox421;
              point1 = new Point(x, y);
              Point point422 = point1;
              pictureBox421.Location = point422;
              this.PictureBox421.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox421, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 422:
              this.PictureBox422.Visible = true;
              PictureBox pictureBox422 = this.PictureBox422;
              point1 = new Point(x, y);
              Point point423 = point1;
              pictureBox422.Location = point423;
              this.PictureBox422.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox422, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 423:
              this.PictureBox423.Visible = true;
              PictureBox pictureBox423 = this.PictureBox423;
              point1 = new Point(x, y);
              Point point424 = point1;
              pictureBox423.Location = point424;
              this.PictureBox423.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox423, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 424:
              this.PictureBox424.Visible = true;
              PictureBox pictureBox424 = this.PictureBox424;
              point1 = new Point(x, y);
              Point point425 = point1;
              pictureBox424.Location = point425;
              this.PictureBox424.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox424, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 425:
              this.PictureBox425.Visible = true;
              PictureBox pictureBox425 = this.PictureBox425;
              point1 = new Point(x, y);
              Point point426 = point1;
              pictureBox425.Location = point426;
              this.PictureBox425.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox425, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 426:
              this.PictureBox426.Visible = true;
              PictureBox pictureBox426 = this.PictureBox426;
              point1 = new Point(x, y);
              Point point427 = point1;
              pictureBox426.Location = point427;
              this.PictureBox426.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox426, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 427:
              this.PictureBox427.Visible = true;
              PictureBox pictureBox427 = this.PictureBox427;
              point1 = new Point(x, y);
              Point point428 = point1;
              pictureBox427.Location = point428;
              this.PictureBox427.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox427, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 428:
              this.PictureBox428.Visible = true;
              PictureBox pictureBox428 = this.PictureBox428;
              point1 = new Point(x, y);
              Point point429 = point1;
              pictureBox428.Location = point429;
              this.PictureBox428.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox428, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 429:
              this.PictureBox429.Visible = true;
              PictureBox pictureBox429 = this.PictureBox429;
              point1 = new Point(x, y);
              Point point430 = point1;
              pictureBox429.Location = point430;
              this.PictureBox429.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox429, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 430:
              this.PictureBox430.Visible = true;
              PictureBox pictureBox430 = this.PictureBox430;
              point1 = new Point(x, y);
              Point point431 = point1;
              pictureBox430.Location = point431;
              this.PictureBox430.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox430, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 431:
              this.PictureBox431.Visible = true;
              PictureBox pictureBox431 = this.PictureBox431;
              point1 = new Point(x, y);
              Point point432 = point1;
              pictureBox431.Location = point432;
              this.PictureBox431.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox431, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 432:
              this.PictureBox432.Visible = true;
              PictureBox pictureBox432 = this.PictureBox432;
              point1 = new Point(x, y);
              Point point433 = point1;
              pictureBox432.Location = point433;
              this.PictureBox432.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox432, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 433:
              this.PictureBox433.Visible = true;
              PictureBox pictureBox433 = this.PictureBox433;
              point1 = new Point(x, y);
              Point point434 = point1;
              pictureBox433.Location = point434;
              this.PictureBox433.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox433, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 434:
              this.PictureBox434.Visible = true;
              PictureBox pictureBox434 = this.PictureBox434;
              point1 = new Point(x, y);
              Point point435 = point1;
              pictureBox434.Location = point435;
              this.PictureBox434.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox434, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 435:
              this.PictureBox435.Visible = true;
              PictureBox pictureBox435 = this.PictureBox435;
              point1 = new Point(x, y);
              Point point436 = point1;
              pictureBox435.Location = point436;
              this.PictureBox435.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox435, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 436:
              this.PictureBox436.Visible = true;
              PictureBox pictureBox436 = this.PictureBox436;
              point1 = new Point(x, y);
              Point point437 = point1;
              pictureBox436.Location = point437;
              this.PictureBox436.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox436, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 437:
              this.PictureBox437.Visible = true;
              PictureBox pictureBox437 = this.PictureBox437;
              point1 = new Point(x, y);
              Point point438 = point1;
              pictureBox437.Location = point438;
              this.PictureBox437.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox437, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 438:
              this.PictureBox438.Visible = true;
              PictureBox pictureBox438 = this.PictureBox438;
              point1 = new Point(x, y);
              Point point439 = point1;
              pictureBox438.Location = point439;
              this.PictureBox438.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox438, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 439:
              this.PictureBox439.Visible = true;
              PictureBox pictureBox439 = this.PictureBox439;
              point1 = new Point(x, y);
              Point point440 = point1;
              pictureBox439.Location = point440;
              this.PictureBox439.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox439, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 440:
              this.PictureBox440.Visible = true;
              PictureBox pictureBox440 = this.PictureBox440;
              point1 = new Point(x, y);
              Point point441 = point1;
              pictureBox440.Location = point441;
              this.PictureBox440.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox440, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 441:
              this.PictureBox441.Visible = true;
              PictureBox pictureBox441 = this.PictureBox441;
              point1 = new Point(x, y);
              Point point442 = point1;
              pictureBox441.Location = point442;
              this.PictureBox441.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox441, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 442:
              this.PictureBox442.Visible = true;
              PictureBox pictureBox442 = this.PictureBox442;
              point1 = new Point(x, y);
              Point point443 = point1;
              pictureBox442.Location = point443;
              this.PictureBox442.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox442, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 443:
              this.PictureBox443.Visible = true;
              PictureBox pictureBox443 = this.PictureBox443;
              point1 = new Point(x, y);
              Point point444 = point1;
              pictureBox443.Location = point444;
              this.PictureBox443.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox443, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 444:
              this.PictureBox444.Visible = true;
              PictureBox pictureBox444 = this.PictureBox444;
              point1 = new Point(x, y);
              Point point445 = point1;
              pictureBox444.Location = point445;
              this.PictureBox444.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox444, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 445:
              this.PictureBox445.Visible = true;
              PictureBox pictureBox445 = this.PictureBox445;
              point1 = new Point(x, y);
              Point point446 = point1;
              pictureBox445.Location = point446;
              this.PictureBox445.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox445, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 446:
              this.PictureBox446.Visible = true;
              PictureBox pictureBox446 = this.PictureBox446;
              point1 = new Point(x, y);
              Point point447 = point1;
              pictureBox446.Location = point447;
              this.PictureBox446.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox446, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 447:
              this.PictureBox447.Visible = true;
              PictureBox pictureBox447 = this.PictureBox447;
              point1 = new Point(x, y);
              Point point448 = point1;
              pictureBox447.Location = point448;
              this.PictureBox447.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox447, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 448:
              this.PictureBox448.Visible = true;
              PictureBox pictureBox448 = this.PictureBox448;
              point1 = new Point(x, y);
              Point point449 = point1;
              pictureBox448.Location = point449;
              this.PictureBox448.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox448, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 449:
              this.PictureBox449.Visible = true;
              PictureBox pictureBox449 = this.PictureBox449;
              point1 = new Point(x, y);
              Point point450 = point1;
              pictureBox449.Location = point450;
              this.PictureBox449.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox449, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 450:
              this.PictureBox450.Visible = true;
              PictureBox pictureBox450 = this.PictureBox450;
              point1 = new Point(x, y);
              Point point451 = point1;
              pictureBox450.Location = point451;
              this.PictureBox450.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox450, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 451:
              this.PictureBox451.Visible = true;
              PictureBox pictureBox451 = this.PictureBox451;
              point1 = new Point(x, y);
              Point point452 = point1;
              pictureBox451.Location = point452;
              this.PictureBox451.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox451, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 452:
              this.PictureBox452.Visible = true;
              PictureBox pictureBox452 = this.PictureBox452;
              point1 = new Point(x, y);
              Point point453 = point1;
              pictureBox452.Location = point453;
              this.PictureBox452.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox452, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 453:
              this.PictureBox453.Visible = true;
              PictureBox pictureBox453 = this.PictureBox453;
              point1 = new Point(x, y);
              Point point454 = point1;
              pictureBox453.Location = point454;
              this.PictureBox453.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox453, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 454:
              this.PictureBox454.Visible = true;
              PictureBox pictureBox454 = this.PictureBox454;
              point1 = new Point(x, y);
              Point point455 = point1;
              pictureBox454.Location = point455;
              this.PictureBox454.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox454, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 455:
              this.PictureBox455.Visible = true;
              PictureBox pictureBox455 = this.PictureBox455;
              point1 = new Point(x, y);
              Point point456 = point1;
              pictureBox455.Location = point456;
              this.PictureBox455.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox455, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 456:
              this.PictureBox456.Visible = true;
              PictureBox pictureBox456 = this.PictureBox456;
              point1 = new Point(x, y);
              Point point457 = point1;
              pictureBox456.Location = point457;
              this.PictureBox456.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox456, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 457:
              this.PictureBox457.Visible = true;
              PictureBox pictureBox457 = this.PictureBox457;
              point1 = new Point(x, y);
              Point point458 = point1;
              pictureBox457.Location = point458;
              this.PictureBox457.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox457, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 458:
              this.PictureBox458.Visible = true;
              PictureBox pictureBox458 = this.PictureBox458;
              point1 = new Point(x, y);
              Point point459 = point1;
              pictureBox458.Location = point459;
              this.PictureBox458.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox458, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 459:
              this.PictureBox459.Visible = true;
              PictureBox pictureBox459 = this.PictureBox459;
              point1 = new Point(x, y);
              Point point460 = point1;
              pictureBox459.Location = point460;
              this.PictureBox459.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox459, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 460:
              this.PictureBox460.Visible = true;
              PictureBox pictureBox460 = this.PictureBox460;
              point1 = new Point(x, y);
              Point point461 = point1;
              pictureBox460.Location = point461;
              this.PictureBox460.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox460, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 461:
              this.PictureBox461.Visible = true;
              PictureBox pictureBox461 = this.PictureBox461;
              point1 = new Point(x, y);
              Point point462 = point1;
              pictureBox461.Location = point462;
              this.PictureBox461.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox461, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 462:
              this.PictureBox462.Visible = true;
              PictureBox pictureBox462 = this.PictureBox462;
              point1 = new Point(x, y);
              Point point463 = point1;
              pictureBox462.Location = point463;
              this.PictureBox462.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox462, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 463:
              this.PictureBox463.Visible = true;
              PictureBox pictureBox463 = this.PictureBox463;
              point1 = new Point(x, y);
              Point point464 = point1;
              pictureBox463.Location = point464;
              this.PictureBox463.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox463, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 464:
              this.PictureBox464.Visible = true;
              PictureBox pictureBox464 = this.PictureBox464;
              point1 = new Point(x, y);
              Point point465 = point1;
              pictureBox464.Location = point465;
              this.PictureBox464.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox464, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 465:
              this.PictureBox465.Visible = true;
              PictureBox pictureBox465 = this.PictureBox465;
              point1 = new Point(x, y);
              Point point466 = point1;
              pictureBox465.Location = point466;
              this.PictureBox465.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox465, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 466:
              this.PictureBox466.Visible = true;
              PictureBox pictureBox466 = this.PictureBox466;
              point1 = new Point(x, y);
              Point point467 = point1;
              pictureBox466.Location = point467;
              this.PictureBox466.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox466, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 467:
              this.PictureBox467.Visible = true;
              PictureBox pictureBox467 = this.PictureBox467;
              point1 = new Point(x, y);
              Point point468 = point1;
              pictureBox467.Location = point468;
              this.PictureBox467.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox467, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 468:
              this.PictureBox468.Visible = true;
              PictureBox pictureBox468 = this.PictureBox468;
              point1 = new Point(x, y);
              Point point469 = point1;
              pictureBox468.Location = point469;
              this.PictureBox468.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox468, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 469:
              this.PictureBox469.Visible = true;
              PictureBox pictureBox469 = this.PictureBox469;
              point1 = new Point(x, y);
              Point point470 = point1;
              pictureBox469.Location = point470;
              this.PictureBox469.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox469, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 470:
              this.PictureBox470.Visible = true;
              PictureBox pictureBox470 = this.PictureBox470;
              point1 = new Point(x, y);
              Point point471 = point1;
              pictureBox470.Location = point471;
              this.PictureBox470.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox470, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 471:
              this.PictureBox471.Visible = true;
              PictureBox pictureBox471 = this.PictureBox471;
              point1 = new Point(x, y);
              Point point472 = point1;
              pictureBox471.Location = point472;
              this.PictureBox471.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox471, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 472:
              this.PictureBox472.Visible = true;
              PictureBox pictureBox472 = this.PictureBox472;
              point1 = new Point(x, y);
              Point point473 = point1;
              pictureBox472.Location = point473;
              this.PictureBox472.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox472, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 473:
              this.PictureBox473.Visible = true;
              PictureBox pictureBox473 = this.PictureBox473;
              point1 = new Point(x, y);
              Point point474 = point1;
              pictureBox473.Location = point474;
              this.PictureBox473.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox473, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 474:
              this.PictureBox474.Visible = true;
              PictureBox pictureBox474 = this.PictureBox474;
              point1 = new Point(x, y);
              Point point475 = point1;
              pictureBox474.Location = point475;
              this.PictureBox474.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox474, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 475:
              this.PictureBox475.Visible = true;
              PictureBox pictureBox475 = this.PictureBox475;
              point1 = new Point(x, y);
              Point point476 = point1;
              pictureBox475.Location = point476;
              this.PictureBox475.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox475, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 476:
              this.PictureBox476.Visible = true;
              PictureBox pictureBox476 = this.PictureBox476;
              point1 = new Point(x, y);
              Point point477 = point1;
              pictureBox476.Location = point477;
              this.PictureBox476.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox476, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 477:
              this.PictureBox477.Visible = true;
              PictureBox pictureBox477 = this.PictureBox477;
              point1 = new Point(x, y);
              Point point478 = point1;
              pictureBox477.Location = point478;
              this.PictureBox477.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox477, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 478:
              this.PictureBox478.Visible = true;
              PictureBox pictureBox478 = this.PictureBox478;
              point1 = new Point(x, y);
              Point point479 = point1;
              pictureBox478.Location = point479;
              this.PictureBox478.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox478, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 479:
              this.PictureBox479.Visible = true;
              PictureBox pictureBox479 = this.PictureBox479;
              point1 = new Point(x, y);
              Point point480 = point1;
              pictureBox479.Location = point480;
              this.PictureBox479.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox479, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 480:
              this.PictureBox480.Visible = true;
              PictureBox pictureBox480 = this.PictureBox480;
              point1 = new Point(x, y);
              Point point481 = point1;
              pictureBox480.Location = point481;
              this.PictureBox480.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox480, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 481:
              this.PictureBox481.Visible = true;
              PictureBox pictureBox481 = this.PictureBox481;
              point1 = new Point(x, y);
              Point point482 = point1;
              pictureBox481.Location = point482;
              this.PictureBox481.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox481, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 482:
              this.PictureBox482.Visible = true;
              PictureBox pictureBox482 = this.PictureBox482;
              point1 = new Point(x, y);
              Point point483 = point1;
              pictureBox482.Location = point483;
              this.PictureBox482.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox482, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 483:
              this.PictureBox483.Visible = true;
              PictureBox pictureBox483 = this.PictureBox483;
              point1 = new Point(x, y);
              Point point484 = point1;
              pictureBox483.Location = point484;
              this.PictureBox483.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox483, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 484:
              this.PictureBox484.Visible = true;
              PictureBox pictureBox484 = this.PictureBox484;
              point1 = new Point(x, y);
              Point point485 = point1;
              pictureBox484.Location = point485;
              this.PictureBox484.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox484, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 485:
              this.PictureBox485.Visible = true;
              PictureBox pictureBox485 = this.PictureBox485;
              point1 = new Point(x, y);
              Point point486 = point1;
              pictureBox485.Location = point486;
              this.PictureBox485.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox485, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 486:
              this.PictureBox486.Visible = true;
              PictureBox pictureBox486 = this.PictureBox486;
              point1 = new Point(x, y);
              Point point487 = point1;
              pictureBox486.Location = point487;
              this.PictureBox486.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox486, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 487:
              this.PictureBox487.Visible = true;
              PictureBox pictureBox487 = this.PictureBox487;
              point1 = new Point(x, y);
              Point point488 = point1;
              pictureBox487.Location = point488;
              this.PictureBox487.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox487, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 488:
              this.PictureBox488.Visible = true;
              PictureBox pictureBox488 = this.PictureBox488;
              point1 = new Point(x, y);
              Point point489 = point1;
              pictureBox488.Location = point489;
              this.PictureBox488.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox488, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 489:
              this.PictureBox489.Visible = true;
              PictureBox pictureBox489 = this.PictureBox489;
              point1 = new Point(x, y);
              Point point490 = point1;
              pictureBox489.Location = point490;
              this.PictureBox489.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox489, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 490:
              this.PictureBox490.Visible = true;
              PictureBox pictureBox490 = this.PictureBox490;
              point1 = new Point(x, y);
              Point point491 = point1;
              pictureBox490.Location = point491;
              this.PictureBox490.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox490, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 491:
              this.PictureBox491.Visible = true;
              PictureBox pictureBox491 = this.PictureBox491;
              point1 = new Point(x, y);
              Point point492 = point1;
              pictureBox491.Location = point492;
              this.PictureBox491.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox491, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 492:
              this.PictureBox492.Visible = true;
              PictureBox pictureBox492 = this.PictureBox492;
              point1 = new Point(x, y);
              Point point493 = point1;
              pictureBox492.Location = point493;
              this.PictureBox492.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox492, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 493:
              this.PictureBox493.Visible = true;
              PictureBox pictureBox493 = this.PictureBox493;
              point1 = new Point(x, y);
              Point point494 = point1;
              pictureBox493.Location = point494;
              this.PictureBox493.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox493, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 494:
              this.PictureBox494.Visible = true;
              PictureBox pictureBox494 = this.PictureBox494;
              point1 = new Point(x, y);
              Point point495 = point1;
              pictureBox494.Location = point495;
              this.PictureBox494.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox494, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 495:
              this.PictureBox495.Visible = true;
              PictureBox pictureBox495 = this.PictureBox495;
              point1 = new Point(x, y);
              Point point496 = point1;
              pictureBox495.Location = point496;
              this.PictureBox495.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox495, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 496:
              this.PictureBox496.Visible = true;
              PictureBox pictureBox496 = this.PictureBox496;
              point1 = new Point(x, y);
              Point point497 = point1;
              pictureBox496.Location = point497;
              this.PictureBox496.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox496, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 497:
              this.PictureBox497.Visible = true;
              PictureBox pictureBox497 = this.PictureBox497;
              point1 = new Point(x, y);
              Point point498 = point1;
              pictureBox497.Location = point498;
              this.PictureBox497.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox497, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 498:
              this.PictureBox498.Visible = true;
              PictureBox pictureBox498 = this.PictureBox498;
              point1 = new Point(x, y);
              Point point499 = point1;
              pictureBox498.Location = point499;
              this.PictureBox498.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox498, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 499:
              this.PictureBox499.Visible = true;
              PictureBox pictureBox499 = this.PictureBox499;
              point1 = new Point(x, y);
              Point point500 = point1;
              pictureBox499.Location = point500;
              this.PictureBox499.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox499, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
            case 500:
              this.PictureBox500.Visible = true;
              PictureBox pictureBox500 = this.PictureBox500;
              point1 = new Point(x, y);
              Point point501 = point1;
              pictureBox500.Location = point501;
              this.PictureBox500.BackColor = color;
              this.Emergente.SetToolTip((Control) this.PictureBox500, SqlConnectionPool.sqlDataReader_2[1].ToString());
              break;
          }
          if (num2 < 500)
            checked { ++num2; }
          else
            break;
        }
        SqlConnectionPool.sqlDataReader_2.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_6();
    }

    public object Traducir()
    {
      this.Maps.Text = Conversions.ToString(LocalizedStrings.object_74);
      this.Search.Text = Conversions.ToString(LocalizedStrings.object_4);
      this.Account.Text = Conversions.ToString(LocalizedStrings.object_5);
      this.Chart.Text = Conversions.ToString(LocalizedStrings.object_6);
      this.Charts.Text = Conversions.ToString(LocalizedStrings.object_6);
      this.Aplicar.Text = Conversions.ToString(LocalizedStrings.object_75);
      this.Text = Conversions.ToString(Operators.ConcatenateObject((object) (this.Text + " - "), Configuration.object_18));
      this.Titulo.Text = this.Text;
      return (object) true;
    }

    private void MoveMaker_Load(object sender, EventArgs e)
    {
      VentanaBarraLoad.DefInstance.Carga.Value = 10;
      IniHelper.smethod_47();
      GameDataLoader.smethod_4();
      VentanaBarraLoad.DefInstance.Carga.Value = 20;
      this.CargarMapas();
      VentanaBarraLoad.DefInstance.Carga.Value = 40;
      this.ListaMapas.SelectedIndex = 0;
      VentanaBarraLoad.DefInstance.Carga.Value = 60;
      this.Traducir();
      VentanaBarraLoad.DefInstance.Carga.Value = 80;
      AccountData.CurrentCharacter.string_1 = "ALL";
      this.RestriccionesOFF();
      this.method_4();
      DatabaseOperations.smethod_11();
      this.DatosPJSelect();
      VentanaBarraLoad.DefInstance.Carga.Value = 100;
      VentanaBarraLoad.DefInstance.Hide();
      this.VerTodosPJ.SelectedIndex = 0;
    }

    private void ListaMapas_SelectedIndexChanged(object sender, EventArgs e)
    {
      this.FotoMapa.Image = (Image) new Bitmap(IniHelper.smethod_30(IniHelper.smethod_31((object) Conversions.ToString(MapImageHelper.smethod_0(RuntimeHelpers.GetObjectValue(this.ListaMapas.SelectedItem))))));
      this.method_4();
      DatabaseOperations.smethod_11();
      this.DatosPJSelect();
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

    private void method_5(object sender, EventArgs e)
    {
      if (Operators.CompareString(AccountData.CurrentCharacter.string_1, "ALL", false) == 0)
      {
        this.method_4();
        DatabaseOperations.smethod_11();
        this.DatosPJSelect();
      }
      else
      {
        DatabaseOperations.smethod_11();
        this.DatosPJSelect();
        AccountStatusManager.smethod_0();
      }
    }

    private void Desconectador_Click(object sender, EventArgs e)
    {
      this.PJOnline.Focus();
      AccountStatusManager.smethod_1();
      AccountStatusManager.smethod_0();
    }

    private void BanUnBan_Click(object sender, EventArgs e)
    {
      this.PJOnline.Focus();
      AccountStatusManager.smethod_2((object) this.Baneado.Text, (object) this.Acount.Text);
      AccountData.CurrentCharacter.string_1 = "ALL";
      this.RestriccionesOFF();
      this.method_4();
      DatabaseOperations.smethod_11();
      this.DatosPJSelect();
    }

    private void Aplicar_Click(object sender, EventArgs e)
    {
      ConnectionManager.smethod_0();
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        if (Operators.ConditionalCompareObjectNotEqual(this.ListaMapas.SelectedItem, (object) "999 [ UNKNOWN ]", false))
        {
          SqlConnectionPool.sqlCommand_1.CommandText = "UPDATE Character SET MapNumber=" + Conversions.ToString(this.ListaMapas.SelectedIndex) + ", MapPosX=" + this.XX.Text + ", MapPosY=" + this.YY.Text + "  WHERE AccountID='" + AccountData.CurrentCharacter.string_0 + "' AND Name='" + AccountData.CurrentCharacter.string_1 + "'";
          SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
          SqlConnectionPool.sqlDataReader_1.Close();
        }
        else
        {
          int num = (int) Interaction.MsgBox(RuntimeHelpers.GetObjectValue(LocalizedStrings.object_99), MsgBoxStyle.OkOnly, (object) null);
        }
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
      AccountData.CurrentCharacter.string_1 = "ALL";
      this.RestriccionesOFF();
      this.method_4();
      DatabaseOperations.smethod_11();
      this.DatosPJSelect();
    }

    private void method_6(object sender, EventArgs e)
    {
      this.PJOnline.Focus();
      if (this.PersonajeSearch.Text.Length <= 0)
        return;
      ConnectionManager.smethod_0();
      try
      {
        SqlConnectionPool.sqlConnection_1.Open();
        SqlConnectionPool.sqlCommand_1.Connection = SqlConnectionPool.sqlConnection_1;
        SqlConnectionPool.sqlCommand_1.CommandText = "SELECT MapNumber FROM Character WHERE Name='" + this.PersonajeSearch.Text + "'";
        SqlConnectionPool.sqlDataReader_1 = SqlConnectionPool.sqlCommand_1.ExecuteReader();
        SqlConnectionPool.sqlDataReader_1.Read();
        this.ListaMapas.SelectedIndex = Conversions.ToInteger(SqlConnectionPool.sqlDataReader_1[0].ToString());
        SqlConnectionPool.sqlDataReader_1.Close();
      }
      catch (Exception ex)
      {
        ProjectData.SetProjectError(ex);
        int num = (int) Interaction.MsgBox((object) ex.Message, MsgBoxStyle.OkOnly, (object) null);
        ProjectData.ClearProjectError();
      }
      ConnectionManager.smethod_5();
      AccountData.CurrentCharacter.string_1 = this.PersonajeSearch.Text;
      this.PJOnline.SelectedItem = (object) this.PersonajeSearch.Text;
    }

    private void method_7(object sender, EventArgs e)
    {
      MoveMaker.DefInstance.WindowState = FormWindowState.Minimized;
    }

    private void method_8(object sender, EventArgs e)
    {
      this.Close();
    }

    private void method_9(object sender, MouseEventArgs e)
    {
      this.XX.Text = Conversions.ToString(Conversion.Int((double) e.X / 2.0));
      this.YY.Text = Conversions.ToString((double) byte.MaxValue - Conversion.Int((double) e.Y / 2.0));
    }

    private void method_10(object sender, MouseEventArgs e)
    {
      this.XX.Text = Conversions.ToString(Conversion.Int((double) e.X / 2.0));
      this.YY.Text = Conversions.ToString((double) byte.MaxValue - Conversion.Int((double) e.Y / 2.0));
    }

    private void method_11(object sender, MouseEventArgs e)
    {
      this.XXX.Text = Conversions.ToString(Conversion.Int((double) e.X / 2.0));
      this.YYY.Text = Conversions.ToString((double) byte.MaxValue - Conversion.Int((double) e.Y / 2.0));
    }

    private void PN_CheckedChanged(object sender, EventArgs e)
    {
      if (!this.PH.Checked & !this.PK.Checked)
        this.PN.Checked = true;
      AccountData.CurrentCharacter.string_1 = "ALL";
      this.method_4();
      DatabaseOperations.smethod_11();
      this.DatosPJSelect();
    }

    private void PH_CheckedChanged(object sender, EventArgs e)
    {
      if (!this.PN.Checked & !this.PK.Checked)
        this.PH.Checked = true;
      AccountData.CurrentCharacter.string_1 = "ALL";
      this.method_4();
      DatabaseOperations.smethod_11();
      this.DatosPJSelect();
    }

    private void PK_CheckedChanged(object sender, EventArgs e)
    {
      if (!this.PH.Checked & !this.PN.Checked)
        this.PK.Checked = true;
      AccountData.CurrentCharacter.string_1 = "ALL";
      this.method_4();
      DatabaseOperations.smethod_11();
      this.DatosPJSelect();
    }

    private void Todos_CheckedChanged(object sender, EventArgs e)
    {
      AccountData.CurrentCharacter.string_1 = "ALL";
      this.method_4();
      DatabaseOperations.smethod_11();
      this.DatosPJSelect();
    }

    private void Baneados_CheckedChanged(object sender, EventArgs e)
    {
      AccountData.CurrentCharacter.string_1 = "ALL";
      this.method_4();
      DatabaseOperations.smethod_11();
      this.DatosPJSelect();
    }

    private void GameMaster_CheckedChanged(object sender, EventArgs e)
    {
      AccountData.CurrentCharacter.string_1 = "ALL";
      this.RestriccionesOFF();
      this.method_4();
      DatabaseOperations.smethod_11();
      this.DatosPJSelect();
    }

    private void VerTodosPJ_SelectedIndexChanged(object sender, EventArgs e)
    {
      AccountData.CurrentCharacter.string_1 = "ALL";
      this.RestriccionesOFF();
      this.method_4();
      DatabaseOperations.smethod_11();
      this.DatosPJSelect();
    }

    private void PJOnline_SelectedIndexChanged(object sender, EventArgs e)
    {
      AccountData.CurrentCharacter.string_1 = Conversions.ToString(this.PJOnline.SelectedItem);
      AccountData.CurrentCharacter.int_0 = this.ListaMapas.SelectedIndex;
      this.RestriccionesON();
      DatabaseOperations.smethod_11();
      this.DatosPJSelect();
      AccountStatusManager.smethod_0();
      this.CheckOnLine();
    }

    private void method_12(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Buscar.BackgroundImage = (Image) EmbeddedResources.smethod_12();
    }

    private void method_13(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Buscar.BackgroundImage = (Image) EmbeddedResources.smethod_13();
    }

    private void method_14(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Reload.BackgroundImage = (Image) EmbeddedResources.smethod_100();
    }

    private void method_15(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Reload.BackgroundImage = (Image) EmbeddedResources.smethod_101();
    }

    private void method_16(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Minimizar.BackgroundImage = (Image) EmbeddedResources.smethod_86();
    }

    private void method_17(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Minimizar.BackgroundImage = (Image) EmbeddedResources.smethod_87();
    }

    private void method_18(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) EmbeddedResources.smethod_39();
    }

    private void method_19(object sender, MouseEventArgs e)
    {
      // ISSUE: reference to a compiler-generated method
      this.Cerrar.BackgroundImage = (Image) EmbeddedResources.smethod_40();
    }

    private void MoveMaker_Closing(object sender, CancelEventArgs e)
    {
      IniHelper.smethod_34();
    }

    private void PersonajeSearch_KeyPress(object sender, KeyPressEventArgs e)
    {
      if ((int) checked ((short) Strings.Asc(e.KeyChar)) != 13)
        return;
      this.method_6(RuntimeHelpers.GetObjectValue(sender), (EventArgs) e);
    }
  }
}
