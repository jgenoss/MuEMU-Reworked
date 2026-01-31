#pragma once

#define MAX_MAIN_VIEWPORT 400

struct NEW_HEALTH_BAR
{
	WORD index;
	BYTE type;
	BYTE rate;
	BYTE rate2;
#if(VANTHANH_FLAG == 1)
	BYTE bHasManyFlag;
#endif

};

void ClearNewHealthBar();
void InsertNewHealthBar(WORD index, BYTE type, BYTE rate, BYTE rate2, BYTE bHasManyFlag);
NEW_HEALTH_BAR* GetNewHealthBar(WORD index, BYTE type);
void DrawNewHealthBar();

#if(VANTHANH_FLAG == 1)
bool PlayerHasManyFlag(WORD index);
#endif