#pragma once

#pragma pack(pop)
#include "SkillManager.h"

struct SpeedPlayer
{
	DWORD m_Tick;
	DWORD m_DCount;
	DWORD m_Time;
	DWORD m_CheckTick;
};

struct AnimationPlayer
{
	DWORD m_DCount;
	DWORD m_XDameCount;
	DWORD m_XDameTick;
};
struct ANTIATTACKDELAY_DATA
{
	int Index;
	int MinSpeed;
	int MaxSpeed;
	int MaxCount;
	int MsClass[7];
};


struct CalSpeedNew
{
	int Index;
	int aIndex;
	int MSTime;
};

struct ANTIMOVESPEED_DATA
{
	int Enabled;
	int Debug;
	int SpeedNormal;
	int SpeedPet;
	int SpeedWing;
	int GateMove;
	int DongBang;

};

struct ANTIANIMATION_DATA
{
	int Index;
	int SkillIndex;
	int TypeSkill;
	float AnimationSpeed;
	int XDameMinMS;
	int LimitSpeed;
	int MaxCount;
};

class CBProtect
{
public:
	CBProtect();
	virtual ~CBProtect();


	void	LoadConfig(char* path);

	char* GetMessage(int index);
	bool	CheckPhamViSkill(int aIndex, int bIndex, int SkillIndex);
	BOOL 	AntiDelayAttack(int aIndex);
	SpeedPlayer Speed[1000];
	AnimationPlayer Animation[1000];
	DWORD	CheckTimeAttack[1000];

	int GetAttackMS(int aIndex, int Number); //Attack Thuong
	void 	KiemTraDiChuyen(int aIndex);
	ANTIMOVESPEED_DATA  m_AntiMoveSpeed;
	//==
	bool AttackDelay_Enable;
	bool AttackDelay_Debug;
	///=== ANimation
	bool Animation_Enable;
	bool Animation_Debug;
	BOOL	    CheckAnimationSkill(int aIndex, int SkillIndex, int Type);

	//
	BOOL	    AntiAutoSkill(int aIndex, int bIndex);


	//=== New Protect Skill 2022
	bool mSkillFloat_Enable;
	int mSkillFloat_Debug;
	int mSkillFloat_SkillID;
	int mSkillFloat_MaxHit;
	int mSkillFloatHit[1000];
	//void bpLoadSkillList(char* File);
	void bpSetNewEx(int nskillID, int nSkillType, int nDelayCountMin, int nDelayMinMs, int nDelayType, int nDelayValue, int nDelayGroup);
	void CalculateSkillFloat(int aIndex);
	BOOL bpSpeedHackCheck(int aIndex, int bIndex, WORD functionID, WORD mskill);
	BOOL BProtectPacketRecv(BYTE head, BYTE* recvlpMsg, int size, int aIndex, int encrypt, int serial);

	int m_Damage[MAX_SKILL];	// 4
	int m_SkillType[MAX_SKILL];
	int m_DelayCountMin[MAX_SKILL];
	int m_DelayMinMs[MAX_SKILL];
	int m_DelayType[MAX_SKILL];
	int m_DelayValue[MAX_SKILL];
	int m_DelayGroup[MAX_SKILL];
	//
	void 		BQuetDupe(int aIndex);
private:
	std::map<int, ANTIATTACKDELAY_DATA> m_AntiAttackDelay;
	bool GetAttackDelayBySpeed(int Speed, ANTIATTACKDELAY_DATA* lpInfo);
	bool KiemTraDelayInSkill(LPOBJ lpObj, int SkillIndex);
	//====Animation
	std::map<int, ANTIANIMATION_DATA>   m_AntiAnimation;
	bool GetAnimationBySkill(int SkillIndex, ANTIANIMATION_DATA* lpInfo);

	//=====================
	std::map<int, CalSpeedNew> m_AttackDamageSize[1000];
	int AttackCountSpeed[1000];
	DWORD SetTimeRsAttack[1000];

	//=====================
	int AnimationCountSpeed[1000];
	int AnimationSkillLast[1000];
	DWORD SetTimeAnimation[1000];
	DWORD SetTimeRsAnimation[1000];

	//===Move new
	double CalSpeedMS(double a1);

};

extern CBProtect gBProtect;