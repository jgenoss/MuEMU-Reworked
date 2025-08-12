#pragma once
#include <string>

class CustomInterface
{
public:
    
    
    CustomInterface();
    ~CustomInterface();
    // Inicializa la interfaz
    bool Initialize();

    static int __fastcall DrawInterface(void* this_ptr);

    static void setWindowText();


    // Limpia recursos
    void Cleanup();

private:
    bool initialized;
};

extern CustomInterface gCustomInterface;