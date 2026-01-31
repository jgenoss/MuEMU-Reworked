#pragma once

struct LICENSE
{
	unsigned long  TempSerial;
	unsigned long  Key;
};

extern LICENSE pLicense;

void ReadyLicense();
void TimeProtection();
bool MACProtection();

