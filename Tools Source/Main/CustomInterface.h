#pragma once

class CustomInterface
{
public:
    CustomInterface();
    ~CustomInterface();

    // Inicializa la interfaz
    bool Initialize();

    static int __fastcall RunHook(void* this_ptr);

    // Limpia recursos
    void Cleanup();

private:
    bool initialized;
};

extern CustomInterface gCustomInterface;