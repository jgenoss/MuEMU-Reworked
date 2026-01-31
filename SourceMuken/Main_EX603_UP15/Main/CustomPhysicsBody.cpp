#include "StdAfx.h"
#include "CustomPhysicsBody.h"
#include "Item.h"
#include "TMemory.h"
#include "Import.h"
#include "Util.h"
#include "Defines.h"
#include "Import.h"
#include "Defines.h"
// chinh sua cai quan cho no bay  bay
CustomPhysicsBody gCustomPhysicsBody;



DWORD CapeBodyThis;
DWORD CapeBodya1;
DWORD CapeBodya2;
DWORD CapeBodyModel;

void CustomPhysicsBody::Load()
{
   SetCompleteHook(0xE9, 0x0061027A, &CPhysicsBody);
   SetCompleteHook(0xE9, 0x0060FFCC, &CPhysicsBodyID);
}
   


Naked(CustomPhysicsBody::CPhysicsBodyID)
{
   static DWORD CReturn = 0x0060FFD3;
   _asm
   {
         CMP DWORD PTR SS:[EBP-0x54],0x16A9//Dark Soul Pants
         je ReturnLoad
         CMP DWORD PTR SS:[EBP-0x54],ITEM2(9,165)//Blue Eye Wizard Pants(Descompilado S15)
         je ReturnLoad
         CMP DWORD PTR SS:[EBP-0x54],ITEM2(9,52)//Hades Pants(TEST)
         je ReturnLoad
         // ---
      ReturnLoad :
      // ---
      jmp CReturn
   }
}

Naked(CustomPhysicsBody::CPhysicsBody)
{
   static DWORD CReturn = 0x00610339;
   _asm
   {
   MOV EAX,DWORD PTR SS:[EBP-0x64]
   MOV EAX,DWORD PTR SS:[EBP-0x64]
   MOV DWORD PTR SS:[EBP-0x48],EAX
   MOV DWORD PTR SS:[EBP-0x4],-1
   MOV ECX,DWORD PTR SS:[EBP-0x48]
   MOV DWORD PTR SS:[EBP-0x28],ECX
   MOV CapeBodyThis, EAX
   MOV EDX,DWORD PTR SS:[EBP+0xC]
   MOV CapeBodya2, EDX
   MOV EAX,DWORD PTR SS:[EBP-0x14]
   MOV CapeBodyModel, EAX
   MOV EAX,DWORD PTR SS:[EBP+0x8]
   MOV CapeBodya1, EAX
   }
//
   if (CapeBodya2 == ITEM2(9,22))//Dark Soul Pants
   {
   CPhysicsCloth_Create2(CapeBodyThis, CapeBodya1, 2, 17, 0.0, 9.0, 7.0, 7, 5, 50.0, 100.0, *(DWORD *)(*(DWORD *)(CapeBodyModel + 56) + 4 * *(WORD *)(*(DWORD *)(CapeBodyModel + 40) + 210)), *(DWORD *)(*(DWORD *)(CapeBodyModel + 56) + 4 * *(WORD *)(*(DWORD *)(CapeBodyModel + 40) + 210)), 5126, CapeBodya2);
   CPhysicsCloth_AddCollisionSphere(CapeBodyThis, 0.0, -15.0, -20.0, 30.0, 2);
   }
   if (CapeBodya2 == ITEM2(9,165))//Blue Eye Wizard Pants(Descompilado S15)
   {
   CPhysicsCloth_Create2(CapeBodyThis, CapeBodya1, 5, 2, 0.0, 18.0, -2.0, 5, 4, 36.0, 50.0, *(DWORD *)(*(DWORD *)(CapeBodyModel + 56) + 4 * *(WORD *)(*(DWORD *)(CapeBodyModel + 40) + 210)), *(DWORD *)(*(DWORD *)(CapeBodyModel + 56) + 4 * *(WORD *)(*(DWORD *)(CapeBodyModel + 40) + 210)), 5122, CapeBodya2);
   CPhysicsCloth_AddCollisionSphere(CapeBodyThis, 0.0, 10.0, 0.0, 25.0, 2);
   }
   if (CapeBodya2 == ITEM2(9,52))//Hades Pants(TEST)
   {
      CPhysicsCloth_Create3(CapeBodyThis, CapeBodya1, 1, 2, 536871936, CapeBodya2);
      CPhysicsCloth_AddCollisionSphere(CapeBodyThis, 0.0, 0.0, -15.0, 22.0, 2);
      CPhysicsCloth_AddCollisionSphere(CapeBodyThis, 0.0, 0.0, -27.0, 23.0, 2);
      CPhysicsCloth_AddCollisionSphere(CapeBodyThis, 0.0, 0.0, -40.0, 24.0, 2);
      CPhysicsCloth_AddCollisionSphere(CapeBodyThis, 0.0, 0.0, -54.0, 25.0, 2);
      CPhysicsCloth_AddCollisionSphere(CapeBodyThis, 0.0, 0.0, -69.0, 26.0, 2);
   }
//
   _asm
   {
      Jmp CReturn
   }
}