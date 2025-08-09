#pragma once

void InitCommon();
void CreateConsole();
BOOL CheckGensBattleMap(int map);
BOOL CheckGensMoveIndex(int idx);
void LoginTab();
void CheckMasterLevel();
void CompareGensMoveIndex();

extern BYTE GensBattleMapCount;
extern BYTE GensMoveIndexCount;
extern BYTE GensBattleMap[120];
extern BYTE GensMoveIndex[120];

extern int DisablePing;