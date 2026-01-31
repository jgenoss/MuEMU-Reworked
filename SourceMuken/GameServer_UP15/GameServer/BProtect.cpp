#include "stdafx.h"
#include "CommandManager.h"
#include "BProtect.h"
#include "GensSystem.h"
#include "Log.h"
#include "Map.h"
#include "MapManager.h"
#include "MemScript.h"
#include "Message.h"
#include "Notice.h"
#include "ServerInfo.h"
#include "Util.h"
#include "Skill.h"
#include "SkillManager.h"
#include "EffectManager.h"
#include "DSProtocol.h"
#include "GameMain.h"


CBProtect gBProtect;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBProtect::CBProtect() // OK
{
	ZeroMemory(Speed, sizeof(Speed));
	ZeroMemory(Animation, sizeof(Animation));
	ZeroMemory(AttackCountSpeed, sizeof(AttackCountSpeed));
	ZeroMemory(SetTimeRsAttack, sizeof(SetTimeRsAttack));
	this->AttackDelay_Enable = 0;
	this->AttackDelay_Debug = 0;
	//===Move
	this->m_AntiMoveSpeed.Enabled = 0;
	this->m_AntiMoveSpeed.GateMove = -1;
	this->m_AntiMoveSpeed.DongBang = -1;
	this->m_AntiMoveSpeed.SpeedNormal = 8;
	this->m_AntiMoveSpeed.SpeedPet = 9;
	this->m_AntiMoveSpeed.SpeedWing = 9;
	//=== ANimagtionPlayer
	this->Animation_Enable = 0;
	this->Animation_Debug = 0;
	this->m_AntiAnimation.clear();
	ZeroMemory(SetTimeRsAnimation, sizeof(SetTimeRsAnimation));
	ZeroMemory(AnimationCountSpeed, sizeof(AnimationCountSpeed));
	ZeroMemory(AnimationSkillLast, sizeof(AnimationSkillLast));
	ZeroMemory(SetTimeAnimation, sizeof(SetTimeAnimation));
}

CBProtect::~CBProtect() // OK
{

}


void CBProtect::LoadConfig(char* path)
{
	ZeroMemory(Speed, sizeof(Speed));
	ZeroMemory(Animation, sizeof(Animation));
	ZeroMemory(AttackCountSpeed, sizeof(AttackCountSpeed));
	ZeroMemory(SetTimeRsAttack, sizeof(SetTimeRsAttack));
	this->AttackDelay_Enable = 0;
	//===Move
	this->m_AntiMoveSpeed.Enabled = 0;
	this->m_AntiMoveSpeed.GateMove = -1;
	this->m_AntiMoveSpeed.DongBang = -1;
	this->m_AntiMoveSpeed.SpeedNormal = 8;
	this->m_AntiMoveSpeed.SpeedPet = 9;
	this->m_AntiMoveSpeed.SpeedWing = 9;
	//=== ANimagtionPlayer
	this->Animation_Enable = 0;
	this->m_AntiAnimation.clear();
	ZeroMemory(SetTimeRsAnimation, sizeof(SetTimeRsAnimation));
	ZeroMemory(AnimationCountSpeed, sizeof(AnimationCountSpeed));
	ZeroMemory(SetTimeAnimation, sizeof(SetTimeAnimation));
	ZeroMemory(AnimationSkillLast, sizeof(AnimationSkillLast));

	int Count1 = 0;
	this->m_AntiAttackDelay.clear();

	//========================
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(path);
	if (res.status != pugi::status_ok){
		ErrorMessageBox("File %s load fail. Error: %s", path, res.description());
		return;
	}
	pugi::xml_node oSpeedCheck = file.child("SpeedCheck");



	//====MOve
	pugi::xml_node eAntiMoveSpeed = oSpeedCheck.child("AntiMoveSpeed");
	//--
	this->m_AntiMoveSpeed.Enabled = eAntiMoveSpeed.attribute("Enabled").as_int();
	this->m_AntiMoveSpeed.Debug = eAntiMoveSpeed.attribute("Debug").as_int();
	this->m_AntiMoveSpeed.GateMove = eAntiMoveSpeed.attribute("GateMove").as_int();
	this->m_AntiMoveSpeed.DongBang = eAntiMoveSpeed.attribute("DongBang").as_int();
	this->m_AntiMoveSpeed.SpeedNormal = eAntiMoveSpeed.attribute("SpeedNormal").as_int();
	this->m_AntiMoveSpeed.SpeedPet = eAntiMoveSpeed.attribute("SpeedPet").as_int();
	this->m_AntiMoveSpeed.SpeedWing = eAntiMoveSpeed.attribute("SpeedWing").as_int();
	//==
	//====Animation
	pugi::xml_node eAntiAnimation = oSpeedCheck.child("AntiAnimation");
	//--
	this->Animation_Enable = eAntiAnimation.attribute("Enabled").as_bool();
	this->Animation_Debug = eAntiAnimation.attribute("Debug").as_bool();
	int AnimationCount = 0;
	for (pugi::xml_node rAntiAnimation = eAntiAnimation.child("Config"); rAntiAnimation; rAntiAnimation = rAntiAnimation.next_sibling()){
		ANTIANIMATION_DATA info;
		info.Index = AnimationCount;
		info.SkillIndex = rAntiAnimation.attribute("SkillIndex").as_int();
		info.AnimationSpeed = rAntiAnimation.attribute("AnimationSpeed").as_float();
		info.LimitSpeed = rAntiAnimation.attribute("LimitSpeed").as_int();
		info.XDameMinMS = rAntiAnimation.attribute("XDameMinMS").as_int();
		info.TypeSkill = rAntiAnimation.attribute("TypeSkill").as_int();
		info.MaxCount = rAntiAnimation.attribute("MaxCount").as_int();
		this->m_AntiAnimation.insert(std::pair<int, ANTIANIMATION_DATA>(info.Index, info));
		AnimationCount++;
	}
	//==
	pugi::xml_node eAntiAttackDelay = oSpeedCheck.child("AntiAttackDelay");
	this->AttackDelay_Enable = eAntiAttackDelay.attribute("Enabled").as_bool();
	this->AttackDelay_Debug = eAntiAttackDelay.attribute("Debug").as_bool();
	for (pugi::xml_node rAntiAttackDelay = eAntiAttackDelay.child("Config"); rAntiAttackDelay; rAntiAttackDelay = rAntiAttackDelay.next_sibling()){
		ANTIATTACKDELAY_DATA info;
		info.Index = Count1;
		info.MinSpeed = rAntiAttackDelay.attribute("MinSpeed").as_int();
		info.MaxSpeed = rAntiAttackDelay.attribute("MaxSpeed").as_int();
		info.MaxCount = rAntiAttackDelay.attribute("MaxCount").as_int();
		info.MsClass[0] = rAntiAttackDelay.attribute("DW").as_int();
		info.MsClass[1] = rAntiAttackDelay.attribute("DK").as_int();
		info.MsClass[2] = rAntiAttackDelay.attribute("ELF").as_int();
		info.MsClass[3] = rAntiAttackDelay.attribute("MG").as_int();
		info.MsClass[4] = rAntiAttackDelay.attribute("DL").as_int();
		info.MsClass[5] = rAntiAttackDelay.attribute("SUM").as_int();
		info.MsClass[6] = rAntiAttackDelay.attribute("RF").as_int();
		this->m_AntiAttackDelay.insert(std::pair<int, ANTIATTACKDELAY_DATA>(info.Index, info));
		Count1++;
	}
	//--
	//==== New Antihack 2022
	ZeroMemory(m_Damage, sizeof(m_Damage));
	ZeroMemory(m_SkillType, sizeof(m_SkillType));
	ZeroMemory(m_DelayType, sizeof(m_DelayType));
	ZeroMemory(m_DelayValue, sizeof(m_DelayValue));
	ZeroMemory(m_DelayGroup, sizeof(m_DelayGroup));
	ZeroMemory(m_DelayCountMin, sizeof(m_DelayCountMin));
	ZeroMemory(m_DelayMinMs, sizeof(m_DelayMinMs));
	this->mSkillFloat_Enable = false;
	this->mSkillFloat_Debug = 0;
	this->mSkillFloat_MaxHit = 0;
	this->mSkillFloat_SkillID = -1;
	pugi::xml_node eAntiSkillFloat = oSpeedCheck.child("AntiSkillFloat");
	this->mSkillFloat_Enable = eAntiSkillFloat.attribute("Enabled").as_bool();
	this->mSkillFloat_Debug = eAntiSkillFloat.attribute("Debug").as_int();
	this->mSkillFloat_MaxHit = eAntiSkillFloat.attribute("MaxHit").as_int(10);
	int skillID;
	int SkillType;
	int DelayType;
	int DelayValue;
	int DelayGroup;
	int DelayMinMs;
	int DelayCountMin;

	for (pugi::xml_node rAntiSkillFloat = eAntiSkillFloat.child("Config"); rAntiSkillFloat; rAntiSkillFloat = rAntiSkillFloat.next_sibling())
	{
		skillID = rAntiSkillFloat.attribute("Skill").as_int();
		SkillType = rAntiSkillFloat.attribute("SkillType").as_int();
		DelayCountMin = rAntiSkillFloat.attribute("CountMin").as_int();
		DelayMinMs = rAntiSkillFloat.attribute("DelayMinMs").as_int();
		DelayType = rAntiSkillFloat.attribute("DelayType").as_int();
		DelayValue = rAntiSkillFloat.attribute("DelayValue").as_int();
		DelayGroup = rAntiSkillFloat.attribute("DelayGroup").as_int();
		this->bpSetNewEx(skillID, SkillType, DelayCountMin, DelayMinMs, DelayType, DelayValue, DelayGroup);
	}
	LogAdd(LOG_BLUE, "[BProtect]Load Config Attack[%d]/Skill[%d]", Count1, AnimationCount);

}


bool CBProtect::GetAttackDelayBySpeed(int Speed, ANTIATTACKDELAY_DATA* lpInfo) // OK
{
	for (std::map<int, ANTIATTACKDELAY_DATA>::iterator it = this->m_AntiAttackDelay.begin(); it != this->m_AntiAttackDelay.end(); it++)
	{
		if (Speed >= it->second.MinSpeed && (Speed <= it->second.MaxSpeed || it->second.MaxSpeed == -1))
		{
			(*lpInfo) = it->second;
			return 1;
		}
	}

	return 0;
}
//===Animation
bool CBProtect::GetAnimationBySkill(int SkillIndex, ANTIANIMATION_DATA* lpInfo) // OK
{
	for (std::map<int, ANTIANIMATION_DATA>::iterator it = this->m_AntiAnimation.begin(); it != this->m_AntiAnimation.end(); it++)
	{
		if (SkillIndex == it->second.SkillIndex || it->second.SkillIndex == -1)
		{
			(*lpInfo) = it->second;
			return 1;
		}
	}

	return 0;
}

int CBProtect::GetAttackMS(int aIndex, int Number) // OK
{
	int ALLMSTime = 0;
	for (std::map<int, CalSpeedNew>::iterator it = this->m_AttackDamageSize[Number].begin(); it != this->m_AttackDamageSize[Number].end(); it++)
	{
		if (aIndex == it->second.aIndex)
		{
			ALLMSTime += it->second.MSTime;
		}
	}

	return ALLMSTime;
}
double CBProtect::CalSpeedMS(double a1)
{
	unsigned int v2; // eax
	double v3; // st6

	v2 = 2;
	v3 = 1.0;
	while (1)
	{
		if ((v2 & 1) != 0)
			v3 = v3 * a1;
		v2 >>= 1;
		if (!v2)
			break;
		a1 = a1 * a1;
	}
	return v3;
}

void CBProtect::KiemTraDiChuyen(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];
	//== Clear XDmg/S
	gObj[aIndex].bp_DetectCount = 0;
	int Number = aIndex - OBJECT_START_USER;

	this->mSkillFloatHit[Number] = 0;
	this->AttackCountSpeed[Number] = 0;
	this->m_AttackDamageSize[Number].clear();

	//====================================	
	if (!this->m_AntiMoveSpeed.Enabled || gObj[aIndex].Type != OBJECT_USER || gObj[aIndex].m_OfflineMode != 0 || gObj[aIndex].IsFakeOnline != 0)
	{
		goto Exit;
	}

	if (gObj[aIndex].RegenOk > 0 || gObj[aIndex].Teleport != 0)
	{
		goto Exit;
	}
	float PhamViChoPhep = 0.0f;

	if (gObj[aIndex].Map >= 18 && (gObj[aIndex].Map <= 23 || gObj[aIndex].Map == 53))
	{
		goto Exit;
	}
	else
	{
		if (gObj[aIndex].BProtect_MAP == gObj[aIndex].Map)
		{
			if ((GetTickCount() - gObj[aIndex].BProtectMove_Time) >= 3000)
			{
				float PhamViDiChuyen = sqrt(
					gBProtect.CalSpeedMS((double)(gObj[aIndex].X - gObj[aIndex].BProtect_X))
					+ gBProtect.CalSpeedMS((double)(gObj[aIndex].Y - gObj[aIndex].BProtect_Y)));

				if (gObj[aIndex].Inventory[7].IsItem())
				{
					PhamViChoPhep = this->m_AntiMoveSpeed.SpeedWing;
				}
				else if (gObj[aIndex].Inventory[8].m_Index == 6660 || gObj[aIndex].Inventory[8].m_Index == 6693) //Chien Ma, Soi TInh
				{
					PhamViChoPhep = this->m_AntiMoveSpeed.SpeedPet;
				}
				else
				{
					PhamViChoPhep = this->m_AntiMoveSpeed.SpeedNormal;
				}

				if (PhamViDiChuyen > PhamViChoPhep && !lpObj->isMove)
				{
					if (this->m_AntiMoveSpeed.GateMove != -1)
					{
						gObjMoveGate(aIndex, this->m_AntiMoveSpeed.GateMove);
					}

					if (this->m_AntiMoveSpeed.DongBang != -1)
					{
						LPOBJ lpObj = &gObj[aIndex];
						gEffectManager.AddEffect(lpObj, 0, 61, this->m_AntiMoveSpeed.DongBang, 0, 0, 0, 0);
					}

					gLog.Output(LOG_HACK, "[AntiSpeedMove][%s][%s]Move : [%f > %f] ToaDoCu: (%d/%d) ToaDoMoi: (%d/%d)", gObj[aIndex].Account, gObj[aIndex].Name, PhamViDiChuyen, PhamViChoPhep, gObj[aIndex].BProtect_X, gObj[aIndex].BProtect_Y, gObj[aIndex].X, gObj[aIndex].Y);
				}

				if (lpObj->isMove)
				{
					lpObj->isMove = false;
					PhamViDiChuyen = PhamViChoPhep;
				}

				if (this->m_AntiMoveSpeed.Debug == 1)
				{
					gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[AntiSpeedMove][%s][%s]Move : [%d > %d] ToaDoCu: (%d/%d) ToaDoMoi: (%d/%d)", gObj[aIndex].Account, gObj[aIndex].Name, PhamViDiChuyen, PhamViChoPhep, gObj[aIndex].BProtect_X, gObj[aIndex].BProtect_Y, gObj[aIndex].X, gObj[aIndex].Y);
				}
			}
		}
	}

Exit:
	gObj[aIndex].BProtect_MAP = gObj[aIndex].Map;
	gObj[aIndex].BProtect_X = gObj[aIndex].X;
	gObj[aIndex].BProtect_Y = gObj[aIndex].Y;
	return;
}
BOOL CBProtect::AntiDelayAttack(int aIndex)
{
	if (!this->AttackDelay_Enable || gObj[aIndex].Type != OBJECT_USER || gObj[aIndex].m_OfflineMode != 0 || gObj[aIndex].IsFakeOnline != 0) {
		return 1;

	}
	if (gObj[aIndex].CloseType != -1) {

		return 0;
	}

	ANTIATTACKDELAY_DATA HackAttacklInfo;

	if (this->GetAttackDelayBySpeed(gObj[aIndex].PhysiSpeed, &HackAttacklInfo) == 0)
	{
		return 1;
	}
	int Number = aIndex - OBJECT_START_USER;
	DWORD CTimeAttack = GetTickCount() - gBProtect.Speed[Number].m_Time;

	DWORD SkillTimeAttack = GetTickCount() - gObj[aIndex].BProtectAnimationTime;
	DWORD AnimationTime = (GetTickCount() - this->SetTimeAnimation[Number]);
	if (SkillTimeAttack < 500 || AnimationTime < 500)
	{
		return 0;
	}

	gBProtect.Speed[Number].m_Time = GetTickCount();
	//===============================

	if (GetTickCount() - this->SetTimeRsAttack[Number] > 1000)
	{
		this->SetTimeRsAttack[Number] = GetTickCount();
		this->AttackCountSpeed[Number] = 0;
		this->m_AttackDamageSize[Number].clear();
	}
	CalSpeedNew infoSpeed;
	infoSpeed.Index = this->AttackCountSpeed[Number];
	infoSpeed.aIndex = aIndex;
	infoSpeed.MSTime = CTimeAttack;
	this->m_AttackDamageSize[Number].insert(std::pair<int, CalSpeedNew>(infoSpeed.Index, infoSpeed));
	this->AttackCountSpeed[Number]++;
	//================================
	int MSTrungBinh = (float)(this->GetAttackMS(aIndex, Number) / this->m_AttackDamageSize[Number].size());
	int CountSize = this->m_AttackDamageSize[Number].size();

	int count = 1000 / HackAttacklInfo.MsClass[gObj[aIndex].Class];


	if (count > HackAttacklInfo.MaxCount)
	{
		count = HackAttacklInfo.MaxCount;
	}
	if (this->AttackDelay_Debug == 1)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "AT : [%d]/[%d] (Count: %d/%d)", MSTrungBinh, HackAttacklInfo.MsClass[gObj[aIndex].Class], CountSize, count);
	}

	if ((CountSize - count) > 30)
	{
		return 0;
	}
	if (CountSize > count + 1)
	{
		return 0;
	}

	if (MSTrungBinh < HackAttacklInfo.MsClass[gObj[aIndex].Class])
	{
		return 0;
	}
	return 1;
}
//========= Animation Speed  New By Cuong beo =)) ==========//
BOOL CBProtect::CheckAnimationSkill(int aIndex, int SkillIndex, int Type)
{

	if (!this->Animation_Enable || gObj[aIndex].Type != OBJECT_USER || gObj[aIndex].m_OfflineMode != 0 || gObj[aIndex].IsFakeOnline != 0) {
		return 1;
	}

	if (gObj[aIndex].CloseType != -1) {

		return 0;
	}
	LPOBJ lpUser = &gObj[aIndex];

	int Number = aIndex - OBJECT_START_USER;

	ANTIANIMATION_DATA SpeedSkill;

	if (SkillIndex == 0)
	{
		return 1;
	}
	if (this->Animation_Debug && this->GetAnimationBySkill(SkillIndex, &SpeedSkill) == 0)
	{
		SpeedSkill.SkillIndex = -1;
		SpeedSkill.TypeSkill = -1;
		SpeedSkill.XDameMinMS = 0;
		SpeedSkill.AnimationSpeed = 6.0;
		SpeedSkill.LimitSpeed = 0;
		SpeedSkill.MaxCount = 30;
	}
	//===== Animation Anti
	//=======================================
	if (SpeedSkill.TypeSkill != -1 && SpeedSkill.TypeSkill != Type)
	{
		return 1;
	}

	int TimeCheck = (GetTickCount() - this->SetTimeAnimation[Number]);
	this->SetTimeAnimation[Number] = GetTickCount();

	if (this->AnimationSkillLast[Number] != SkillIndex && TimeCheck < 100)
	{
		return 0;
	}
	this->AnimationSkillLast[Number] = SkillIndex;


	DWORD CTimeAttack = GetTickCount() - gBProtect.Speed[Number].m_Time;
	if (CTimeAttack < 500)
	{
		return 0;
	}

	if (GetTickCount() - this->SetTimeRsAnimation[Number] > 1000)
	{
		this->SetTimeRsAnimation[Number] = GetTickCount();
		this->AnimationCountSpeed[Number] = 0;
	}

	float CalAnimation = 1000.0f;



	if (gObj[aIndex].Class == CLASS_WIZARD)
	{
		CalAnimation = (float)1000.0f / (((lpUser->PhysiSpeed) * 0.0142333198777464) + SpeedSkill.AnimationSpeed);
	}
	else
	{
		CalAnimation = (float)1000.0f / (((lpUser->PhysiSpeed) * 0.0109365655658977) + SpeedSkill.AnimationSpeed);
	}

	if (CalAnimation < SpeedSkill.LimitSpeed)
	{
		CalAnimation = SpeedSkill.LimitSpeed;
	}

	int count = 1000.0f / CalAnimation;



	if (count > SpeedSkill.MaxCount)
	{
		count = SpeedSkill.MaxCount;
	}
	if (this->Animation_Debug == 1) {
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[%d]Skill %d Ms(%d) %d (%d/%d)", Type, SkillIndex, TimeCheck, (int)CalAnimation, this->AnimationCountSpeed[Number], count);
	}
	if (lpUser->MultiSkillCount == 0)
	{
		this->AnimationCountSpeed[Number]++;
	}
	//fixxxxxxxxxxxxxxxx
	if ((this->AnimationCountSpeed[Number] - count) > 20)
	{
		return 0;
	}


	if (this->AnimationCountSpeed[Number] > count + 1)
	{
		return 0;
	}
	if (SpeedSkill.XDameMinMS != 0)
	{
		if ((int)CalAnimation > SpeedSkill.XDameMinMS &&  TimeCheck == 0)
		{
			return 0;
		}
	}
	//////////////////////////////////////////////////
	if (TimeCheck == 0 && SpeedSkill.LimitSpeed > 0)
	{
		return 0;
	}

	if (TimeCheck < (int)CalAnimation && TimeCheck != 0)
	{
		return 0;
	}


	return 1;
	//========================================

}

void CBProtect::bpSetNewEx(int nskillID, int nSkillType, int nDelayCountMin, int nDelayMinMs, int nDelayType, int nDelayValue, int nDelayGroup) //
{
	if (nskillID <0 || nskillID > MAX_SKILL - 1)
	{
		//MsgBox(("Limit error : (%s %d)"), __FILE__, __LINE__);
		return;
	}

	if (this->m_Damage[nskillID] == -1)
	{
		//MsgBox(("Limit error : (%s %d)"), __FILE__, __LINE__);
		return;
	}


	this->m_SkillType[nskillID] = nSkillType;
	this->m_DelayCountMin[nskillID] = nDelayCountMin;
	this->m_DelayMinMs[nskillID] = nDelayMinMs;
	this->m_DelayType[nskillID] = nDelayType;
	this->m_DelayValue[nskillID] = nDelayValue;
	this->m_DelayGroup[nskillID] = nDelayGroup;

	//-----------

}
void CBProtect::CalculateSkillFloat(int aIndex)
{
	LPOBJ lpUser = &gObj[aIndex];
	float nAttack1 = lpUser->PhysiSpeed * 0.004000000189989805;	//dword ptr [ebp-0x10]
	float nAttack2 = lpUser->PhysiSpeed * 0.002000000094994903;	//dword ptr [ebp-0x8]
	float nMagic1 = lpUser->MagicSpeed * 0.004000000189989805;	//dword ptr [ebp-0xC]
	float nMagic2 = lpUser->MagicSpeed * 0.002000000094994903;	//dword ptr [ebp-0x4]

	for (int n = 0; n < 256; n++)
	{
		lpUser->GroupSkill[n] = 0;
	}

	lpUser->GroupSkill[51] = nAttack1 + 0.300000011920929;
	lpUser->GroupSkill[60] = nAttack1 + 0.300000011920929;
	lpUser->GroupSkill[61] = nAttack1 + 0.300000011920929;
	lpUser->GroupSkill[62] = nAttack1 + 0.2700000107288361;
	lpUser->GroupSkill[63] = nAttack1 + 0.300000011920929;
	lpUser->GroupSkill[64] = nAttack1 + 0.239999994635582;
	lpUser->GroupSkill[65] = nAttack1 + 0.239999994635582;
	lpUser->GroupSkill[66] = 0.3799999952316284;
	lpUser->GroupSkill[67] = 0.3400000035762787;
	lpUser->GroupSkill[71] = nAttack1 + 0.25;
	lpUser->GroupSkill[80] = nAttack1 + 0.25;
	lpUser->GroupSkill[131] = nAttack1 + 0.300000011920929;
	lpUser->GroupSkill[136] = nAttack1 + 0.4000000059604645;
	lpUser->GroupSkill[137] = nAttack1 + 0.300000011920929;
	lpUser->GroupSkill[138] = nAttack1 + 0.2000000029802322;
	lpUser->GroupSkill[145] = nAttack1 + 0.25;
	lpUser->GroupSkill[146] = nMagic2 + 0.2899999916553497;
	lpUser->GroupSkill[147] = nMagic2 + 0.2899999916553497;
	lpUser->GroupSkill[150] = nMagic1 + 0.25;
	lpUser->GroupSkill[152] = nMagic2 + 0.4000000059604645;
	lpUser->GroupSkill[153] = nMagic2 + 0.6000000238418579;
	lpUser->GroupSkill[154] = nMagic2 + 0.5;
	lpUser->GroupSkill[156] = nMagic2 + 0.300000011920929;
	lpUser->GroupSkill[160] = nMagic2 + 0.25;
	lpUser->GroupSkill[168] = nMagic2 + 0.25;
	lpUser->GroupSkill[176] = 0.300000011920929;
	lpUser->GroupSkill[183] = nMagic1 + 0.550000011920929;
	lpUser->GroupSkill[184] = nMagic2 + 0.6899999976158142;
	lpUser->GroupSkill[185] = nMagic2 + 0.3499999940395355;
	lpUser->GroupSkill[247] = nAttack2 + 0.4000000059604645;
	lpUser->GroupSkill[248] = nAttack2 + 0.4000000059604645;
	lpUser->GroupSkill[249] = nAttack2 + 0.4000000059604645;
	lpUser->GroupSkill[250] = nAttack2 + 0.300000011920929;
	lpUser->GroupSkill[253] = nAttack2 + 0.300000011920929;
	lpUser->GroupSkill[255] = 0.3499999940395355;
}

BOOL CBProtect::AntiAutoSkill(int aIndex, int bIndex)
{
	//============ Auto Skill Target
	if (OBJECT_RANGE(bIndex) != 0 && gObj[bIndex].Type == OBJECT_USER && bIndex != aIndex)
	{
		if (gMap[gObj[bIndex].Map].CheckAttr(gObj[bIndex].X, gObj[bIndex].Y, 4) != 0 && gMap[gObj[bIndex].Map].CheckAttr(gObj[bIndex].X, gObj[bIndex].Y, 8) != 0)
		{

			return 0;
		}
	}
	//LogAdd(LOG_RED, "MAXHIT :[%d] / [%d]", this->mSkillFloatHit , this->mSkillFloat_MaxHit);
	int Number = aIndex - OBJECT_START_USER;
	if (this->mSkillFloatHit[Number] > this->mSkillFloat_MaxHit)
	{
		return 0;
	}
	//=============================
	return 1;
}

//====NEW TEST
BOOL CBProtect::bpSpeedHackCheck(int aIndex, int bIndex, WORD functionID, WORD mskill)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnected(aIndex) == 0)
	{
		return false;
	}

	if (!this->mSkillFloat_Enable || lpObj->Type != OBJECT_USER || lpObj->m_OfflineMode != 0 || lpObj->IsFakeOnline != 0)
	{
		return true;
	}

	if (bIndex > MAX_OBJECT && bIndex != 65535)
	{
		return false;
	}

	if (aIndex == bIndex) //Su dung skill len nguoi minh thi bo qua check speed
	{
		return true;
	}
	int iType;
	int iValue;
	int iGroup;
	int iskill = mskill;

	if (functionID == 0 || iskill == 0)		//Attack by Hand
	{
		//147 Phep
		iGroup = 80;
		iValue = 6;
		iType = 1;
	}

	if (iskill > MAX_SKILL)
	{
		iGroup = 0;
		iType = 0;
	}

	if (iskill < MAX_SKILL)
	{
		iType = this->m_DelayType[iskill];
		iValue = this->m_DelayValue[iskill];
		iGroup = this->m_DelayGroup[iskill];
	}
	char sBuff[255] = { 0 };
	DWORD nTimeCalc = GetTickCount() - lpObj->bp_LastAttackTime[functionID];

	lpObj->bp_LastAttackTime[functionID] = GetTickCount();

	//if (this->mSkillFloat_SkillID != iskill && nTimeCalc < 100)
	//{
	//	if (gCustomCombo.CheckSkillPrimary(iskill) == 0 && gCustomCombo.CheckSkillSecundary(iskill) == 0 &&
	//		gCustomCombo.CheckSkillPrimary(this->mSkillFloat_SkillID) == 0 && gCustomCombo.CheckSkillSecundary(this->mSkillFloat_SkillID) == 0)
	//	{
	//		return false;
	//	}
	//}
	
	if (this->mSkillFloat_SkillID != iskill)
	{
		this->mSkillFloat_SkillID = iskill;
		return true;
	}

	//if (nTimeCalc >= 3000)
	//{
	//	lpObj->bp_DetectCount = 0;
	//}

	if (iGroup != 0 && iType == 1 && (functionID == this->m_SkillType[iskill] || this->m_SkillType[iskill] == -1))
	{
		this->CalculateSkillFloat(aIndex);
		int i;
		float k = lpObj->GroupSkill[iGroup];
		if (k != 0)
		{

			//LogAdd(LOG_BLUE, "Hack:(%d,%d,%d) %f", iType, iValue, iGroup, k);
			for (i = 0; k <= iValue; i++)
			{
				k = k + lpObj->GroupSkill[iGroup];
			}

			int itimeskill = i * 30;		// 30ms is time of a loop in client


			if (this->mSkillFloat_Debug == 1)
			{
				LogAdd(LOG_RED, "[%d]Type %d Target[%d] Skill [%d] Calc [%d~%d] Min (%d) Sp (%f/%d) i= %d, XDmg = %d", functionID, iType, bIndex, iskill, nTimeCalc, itimeskill, this->m_DelayMinMs[iskill], k, iValue, i, lpObj->bp_DetectCount);
			}

			if (nTimeCalc > 0)
			{
				//=== Nho Hon MS Calc && != X
				if ((nTimeCalc < itimeskill) && i > 0)
				{
					return false;
				}
				//if(nTimeCalc < this->m_DelayMinMs[iskill] )
				//{
				//	return false;
				//}
				//return true;
			} 
			else 
			{
				if (i > 0)
				{
					return false;
				}
			}


			//if (lpObj->bp_DetectCount > 10)
			//{
			//	return false;
			//}

		}
	} 
	else if (iType == 2)
	{
		if (this->mSkillFloat_Debug == 1)
		{
			LogAdd(LOG_RED, "[%d]Type %d Target[%d] Skill [%d]  , Delay %d / %d, Detect = %d", functionID, iType, bIndex, iskill, nTimeCalc, iValue, lpObj->bp_DetectCount);
		}
		if (nTimeCalc < iValue)
		{
			return false;
		}
	}
	else 
	{

		if (this->mSkillFloat_Debug == 1)
		{
			LogAdd(LOG_BLUE, "[OK][%d]Type %d Target[%d] Skill [%d]  , Delay %d / %d, Detect = %d", functionID, iType, bIndex, iskill,  nTimeCalc, iValue, lpObj->bp_DetectCount);
		}
	}

	//========= MS Minium Get
	int Number = aIndex - OBJECT_START_USER;

	//=========Get Min
	if (this->m_DelayMinMs[iskill] > 0)
	{
		CalSpeedNew infoSpeed;
		infoSpeed.Index = this->AttackCountSpeed[Number];
		infoSpeed.aIndex = aIndex;
		infoSpeed.MSTime = nTimeCalc;
		this->m_AttackDamageSize[Number].insert(std::pair<int, CalSpeedNew>(infoSpeed.Index, infoSpeed));
		this->AttackCountSpeed[Number]++;
		//================================
		int MSTrungBinh = (float)(this->GetAttackMS(aIndex, Number) / this->m_AttackDamageSize[Number].size());
		int CountSize = this->m_AttackDamageSize[Number].size();
		if (this->mSkillFloat_Debug == 2)
		{
			//gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[%d]MS : [%d]/[%d] (Count: %d/%d)", iskill, MSTrungBinh, this->m_DelayMinMs[iskill], CountSize,this->m_DelayCountMin[iskill]);
			LogAdd(LOG_ALERT, "[%s][%s] Skill [%d]MS : [%d]/[%d] (Count: %d/%d)", lpObj->Account, lpObj->Name, iskill, MSTrungBinh, this->m_DelayMinMs[iskill], CountSize, this->m_DelayCountMin[iskill]);
		}
		//if (MSTrungBinh < this->m_DelayMinMs[iskill])
		//{
		//	this->mSkillFloatHit[Number]++;
		//	return false;
		//}
		if (CountSize > this->m_DelayCountMin[iskill] && this->m_DelayCountMin[iskill] > 0)
		{
			this->mSkillFloatHit[Number]++;
			return false;
		}
	}
	//==================
	//======XDame Get
	if (nTimeCalc == 0)
	{
		//== XDmg
		if (lpObj->bp_DetectCount < 3)
		{
			lpObj->bp_DetectCount++;
		}
		else
		{
			//LogAdd(LOG_RED, "Xdame False");
			return false;
		}
	}
	else 
	{
		lpObj->bp_DetectCount = 0;
	}
	this->mSkillFloat_SkillID = iskill;
	return true;
}


//====NEW TEST
void CBProtect::BQuetDupe(int aIndex)
{
	if (gObj[aIndex].Type != OBJECT_USER || gObj[aIndex].m_OfflineMode != 0 || gObj[aIndex].IsFakeOnline != 0) {
		return;
	}
	bool CheckNameOK = true;
	//=== Check Ten Nhan Vat (Hack Disk, Clone Dupe)
	int count = strlen(gObj[aIndex].Name);

	if (count > 10)
	{
		GCCloseClientSend(aIndex, 2); //Kick Khoi Game
		return;
	}
	for (int i = 0; i < count; ++i) {

		if (gObj[aIndex].Name[i] < 97 && gObj[aIndex].Name[i] > 122 && gObj[aIndex].Name[i] < 65 && gObj[aIndex].Name[i] > 90 && gObj[aIndex].Name[i] < 48 && gObj[aIndex].Name[i] > 57)
		{
			GCCloseClientSend(aIndex, 2); //Kick Khoi Game
			return;
		}
	}
	//====Scan
	if (gObj[aIndex].Transaction == 1 && gObj[aIndex].Interface.type == 0)
	{
		gObjInventoryRollback(aIndex);
	}
}

#include "Attack.h"
BOOL CBProtect::BProtectPacketRecv(BYTE head, BYTE* recvlpMsg, int size, int aIndex, int encrypt, int serial)
{

	int bIndex = 65535;
	int skill = 0;
	switch (head)
	{
	case PROTOCOL_CODE2:
	{
		PMSG_ATTACK_RECV* lpMsg = (PMSG_ATTACK_RECV*)recvlpMsg;
		bIndex = MAKE_NUMBERW(lpMsg->index[0], lpMsg->index[1]);

		if (!this->bpSpeedHackCheck(aIndex, bIndex, 0, skill))
		{
			return false;
		}
	}
	break;
	case 0x4A:
	{
		PMSG_RAGE_FIGHTER_SKILL_ATTACK_RECV* lpMsg = (PMSG_RAGE_FIGHTER_SKILL_ATTACK_RECV*)recvlpMsg;
		bIndex = MAKE_NUMBERW(lpMsg->index[0], lpMsg->index[1]);
		skill = MAKE_NUMBERW(lpMsg->skill[0], lpMsg->skill[1]);
		if (!this->bpSpeedHackCheck(aIndex, bIndex, 1, skill))
		{
			return false;
		}
	}
	break;
	case 0x4B:
	{
		PMSG_SKILL_DARK_SIDE_RECV* lpMsg = (PMSG_SKILL_DARK_SIDE_RECV*)recvlpMsg;
		bIndex = MAKE_NUMBERW(lpMsg->index[0], lpMsg->index[1]);
		skill = MAKE_NUMBERW(lpMsg->skill[0], lpMsg->skill[1]);
		if (!this->bpSpeedHackCheck(aIndex, bIndex, 2, skill))
		{
			return false;
		}
	}
	break;
	case 0x19:
	{
		PMSG_SKILL_ATTACK_RECV* lpMsg = (PMSG_SKILL_ATTACK_RECV*)recvlpMsg;
		bIndex = MAKE_NUMBERW(lpMsg->index[0], lpMsg->index[1]);
		skill = MAKE_NUMBERW(lpMsg->skill[0], lpMsg->skill[1]);
		if (!this->bpSpeedHackCheck(aIndex, bIndex, 3, skill))
		{
			return false;
		}
	}
	break;
	case PROTOCOL_CODE4:
	{
		PMSG_MULTI_SKILL_ATTACK_RECV* lpMsg = (PMSG_MULTI_SKILL_ATTACK_RECV*)recvlpMsg;
		skill = MAKE_NUMBERW(lpMsg->skill[0], lpMsg->skill[1]);
		if (!this->bpSpeedHackCheck(aIndex, bIndex, 4, skill))
		{
			return false;
		}
	}

	break;
	case 0x1E:
	{

		PMSG_DURATION_SKILL_ATTACK_RECV* lpMsg = (PMSG_DURATION_SKILL_ATTACK_RECV*)recvlpMsg;
		bIndex = MAKE_NUMBERW(lpMsg->index[0], lpMsg->index[1]);
		skill = MAKE_NUMBERW(lpMsg->skill[0], lpMsg->skill[1]);
		if (!this->bpSpeedHackCheck(aIndex, bIndex, 5, skill))
		{
			return false;
		}
	}
	break;
	}


	return true;
}
