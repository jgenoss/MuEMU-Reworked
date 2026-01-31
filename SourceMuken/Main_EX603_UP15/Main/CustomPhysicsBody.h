#pragma once

#define CPhysicsCloth_Create               ((int(__thiscall*)(int This, int a2, int Joint, float X, float Z, float Y, int a7, int a8, float Width, float Height, int a11, int a12, int a13)) 0x0051D460)
#define CPhysicsCloth_Create2               ((int(__thiscall*)(int This, int a2, int GroupMesh, int Joint, float X, float Z, float Y, int a8, int a9, float Width, float Height, int a12, int a13, int a14, int a15)) 0x0051F6A0)
#define CPhysicsCloth_Create3               ((int(__thiscall*)(int This, int a2, int GroupMesh, int Joint, int a5, int a6)) 0x0051F100)
#define CPhysicsCloth_AddCollisionSphere      ((int(__thiscall*)(int This, float a1, float a2, float a3, float a4, int a5)) 0x0051EEF0)

class CustomPhysicsBody
{
public:
   /*CustomPhysicsBody(void);
   ~CustomPhysicsBody(void);*/
   static void CPhysicsBodyID();
   static void CPhysicsBody();
   void Load();
};
extern CustomPhysicsBody gCustomPhysicsBody;