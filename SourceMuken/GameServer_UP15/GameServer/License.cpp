#include "StdAfx.h"
#include "License.h"
#include <cstdlib>
#include "ThemidaSDK.h"
#include "ServerInfo.h"


License gLicense;

bool License::CheckingGetComputerHardwareId(LPCSTR HDWID)
{
	CLEAR_START

	VM_START

	char ComputerHardwareId[20][36] ={HWID_VPS}; // HARDWARE ID PC
	//char ComputerHardwareId[20][36] ={"480F7186-8CF2C9A7-F45B606B-8F4BD8E7"}; // HARDWARE ID PC
	//char ComputerHardwareId[20][36] = gServerInfo.m_CustomerHardwareId[36]; // HARDWARE ID PC
	

	for(int x=0; x<20; x++)
	{
		if(!strcmp(HDWID,ComputerHardwareId[x]))
		{
			return true;
		}
	}
	return false;

	VM_END

	CLEAR_END

}
bool License::GetComputerHardwareId() // OK
{
	CLEAR_START

	VM_START

	DWORD VolumeSerialNumber;

	if(GetVolumeInformation("C:\\",0,0,&VolumeSerialNumber,0,0,0,0) == 0)
	{
		return 0;
	}

	UUID uuid;

	UuidCreateSequential(&uuid);

	SYSTEM_INFO SystemInfo;

	GetSystemInfo(&SystemInfo);

	DWORD ComputerHardwareId1 = VolumeSerialNumber ^ 0x12B586FE;

	DWORD ComputerHardwareId2 = *(DWORD*)(&uuid.Data4[2]) ^ 0x5D78A569;

	DWORD ComputerHardwareId3 = ((*(WORD*)(&uuid.Data4[6]) & 0xFFFF) | (SystemInfo.wProcessorArchitecture << 16)) ^ 0xF45BC123;

	DWORD ComputerHardwareId4 = ((SystemInfo.wProcessorLevel & 0xFFFF) | (SystemInfo.wProcessorRevision << 16)) ^ 0xB542D8E1;

	wsprintf(this->ComputerHardware,"%08X-%08X-%08X-%08X",ComputerHardwareId1,ComputerHardwareId2,ComputerHardwareId3,ComputerHardwareId4);

	if(CheckingGetComputerHardwareId(this->ComputerHardware))
	{
		return true;
	}
	else
	{
		this->ErrorMessageBox();

		return false;
	}

	VM_END

	CLEAR_END
}

inline void License::ErrorMessageBox() // OK
{
	CLEAR_START

	VM_START

	memset(this->ComputerHardware,0,sizeof(this->ComputerHardware));

	MessageBox(0,"Error Ban Phai Can Co License","Lien He Hai Dai Su",MB_ICONSTOP|MB_OK);

	this->SafeExitProcess();

	VM_END

	CLEAR_END

}

inline void License::SafeExitProcess() // OK
{
	CLEAR_START

	VM_START

	while(true)
	{
		TerminateProcess(GetCurrentProcess(),0);
		CRASH_APPLICATION_MACRO
	}

	VM_END

	CLEAR_END


}
