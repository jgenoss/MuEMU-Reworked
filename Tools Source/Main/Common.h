#pragma once

void InitCommon();
BOOL CheckGensBattleMap(int map);
BOOL CheckGensMoveIndex(int idx);
void LoginTab();
void CheckMasterLevel();
void CompareGensMoveIndex();

extern BYTE GensBattleMapCount;
extern BYTE GensMoveIndexCount;
extern BYTE GensBattleMap[120];
extern BYTE GensMoveIndex[120];

extern int DisableStaticEffect;
extern int DisableDynamicEffect;
extern int DisableSkillEffect;
extern int DisableGlowEffect;
extern int Anisotropy;
extern int MaxAnisotropy;
extern int Linear;
extern int GMT;
extern int Fog;
extern int Tron;
extern int MiniMap;
extern int MiniMapActive;
extern int DisablePing;