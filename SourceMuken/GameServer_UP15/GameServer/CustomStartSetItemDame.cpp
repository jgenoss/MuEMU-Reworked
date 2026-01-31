#include "StdAfx.h"
#include "CustomStartSetItemDame.h"
#include "DSProtocol.h"
#include "MemScript.h"
#include "Util.h"
#include "ItemManager.h"
#include "CashShop.h"
#include "User.h"
#include "Notice.h"
#include "Message.h"
#include "ServerInfo.h"
#include "Path.h"
#include "ObjectManager.h"

#if(BUFF_SET_ICON)

CCustomStartSetItemDame gCustomStartSetItemDame;

CCustomStartSetItemDame::CCustomStartSetItemDame()
{
	this->Init();
}

CCustomStartSetItemDame::~CCustomStartSetItemDame()
{
}

void CCustomStartSetItemDame::Init()
{
	this->itemdata.clear();
}

void CCustomStartSetItemDame::Load()
{
	this->Init();
	this->Read(gPath.GetFullPath("Custom\\CustomStartSetItemDame.txt"));
}

void CCustomStartSetItemDame::Read(char* path)
{
	CMemScript* lpMemScript = new CMemScript;

	if (lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR, path);
		return;
	}

	if (lpMemScript->SetBuffer(path) == 0)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	try
	{
		while (true)
		{
			if (lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			int section = lpMemScript->GetNumber();

			while (true)
			{
				if (section == 0)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					CustomStartSetItemDame_Data info;

					info.ItemType = lpMemScript->GetNumber();

					info.ItemIndex = lpMemScript->GetAsNumber();

					info.Effect = lpMemScript->GetAsNumber();

					info.Level = lpMemScript->GetAsNumber();

					info.Option = lpMemScript->GetAsNumber();

					info.Dame = lpMemScript->GetAsNumber();

					info.IncSD = lpMemScript->GetAsNumber();

					info.IncLife = lpMemScript->GetAsNumber();

					info.IncMana = lpMemScript->GetAsNumber();

					info.Defense = lpMemScript->GetAsNumber();



					info.ExcellentDamageRate = lpMemScript->GetAsNumber();

					info.CriticalDamageRate = lpMemScript->GetAsNumber();

					info.DoubleDamageRate = lpMemScript->GetAsNumber();

					info.IncResistDoubleDamage = lpMemScript->GetAsNumber();

					info.IncResistIgnoreDefense = lpMemScript->GetAsNumber();

					info.IncResistIgnoreSD = lpMemScript->GetAsNumber();

					info.IncResistCriticalDamage = lpMemScript->GetAsNumber();

					info.IncResisteExcellentDamage = lpMemScript->GetAsNumber();

					info.IncBlockStuck = lpMemScript->GetAsNumber();

					info.IncReflectRate = lpMemScript->GetAsNumber();

					info.Time = lpMemScript->GetAsNumber();

					this->itemdata.push_back(info);
				}
				else if (section == 1)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					CustomStartSetItemDame_Data info;

					info.ItemType = lpMemScript->GetNumber();

					info.ItemIndex = lpMemScript->GetAsNumber();

					info.Effect = lpMemScript->GetAsNumber();

					info.Level = lpMemScript->GetAsNumber();

					info.Option = lpMemScript->GetAsNumber();

					info.Dame = lpMemScript->GetAsNumber();

					info.IncSD = lpMemScript->GetAsNumber();

					info.IncLife = lpMemScript->GetAsNumber();

					info.IncMana = lpMemScript->GetAsNumber();

					info.Defense = lpMemScript->GetAsNumber();

					info.ExcellentDamageRate = lpMemScript->GetAsNumber();

					info.CriticalDamageRate = lpMemScript->GetAsNumber();

					info.DoubleDamageRate = lpMemScript->GetAsNumber();

					info.IncResistDoubleDamage = lpMemScript->GetAsNumber();

					info.IncResistIgnoreDefense = lpMemScript->GetAsNumber();

					info.IncResistIgnoreSD = lpMemScript->GetAsNumber();

					info.IncResistCriticalDamage = lpMemScript->GetAsNumber();

					info.IncResisteExcellentDamage = lpMemScript->GetAsNumber();

					info.IncBlockStuck = lpMemScript->GetAsNumber();

					info.IncReflectRate = lpMemScript->GetAsNumber();

					info.Time = lpMemScript->GetAsNumber();

					this->itemdata.push_back(info);
				}

				else if (section == 2)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					CustomStartSetItemDame_Data info;

					info.ItemType = lpMemScript->GetNumber();

					info.ItemIndex = lpMemScript->GetAsNumber();

					info.Effect = lpMemScript->GetAsNumber();

					info.Level = lpMemScript->GetAsNumber();

					info.Option = lpMemScript->GetAsNumber();

					info.Dame = lpMemScript->GetAsNumber();

					info.IncSD = lpMemScript->GetAsNumber();

					info.IncLife = lpMemScript->GetAsNumber();

					info.IncMana = lpMemScript->GetAsNumber();

					info.Defense = lpMemScript->GetAsNumber();

					info.ExcellentDamageRate = lpMemScript->GetAsNumber();

					info.CriticalDamageRate = lpMemScript->GetAsNumber();

					info.DoubleDamageRate = lpMemScript->GetAsNumber();


					info.IncResistDoubleDamage = lpMemScript->GetAsNumber();

					info.IncResistIgnoreDefense = lpMemScript->GetAsNumber();

					info.IncResistIgnoreSD = lpMemScript->GetAsNumber();

					info.IncResistCriticalDamage = lpMemScript->GetAsNumber();

					info.IncResisteExcellentDamage = lpMemScript->GetAsNumber();

					info.IncBlockStuck = lpMemScript->GetAsNumber();

					info.IncReflectRate = lpMemScript->GetAsNumber();

					info.Time = lpMemScript->GetAsNumber();

					this->itemdata.push_back(info);
				}


				else if (section == 3)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					CustomStartSetItemDame_Data info;

					info.ItemType = lpMemScript->GetNumber();

					info.ItemIndex = lpMemScript->GetAsNumber();

					info.Effect = lpMemScript->GetAsNumber();

					info.Level = lpMemScript->GetAsNumber();

					info.Option = lpMemScript->GetAsNumber();

					info.Dame = lpMemScript->GetAsNumber();

					info.IncSD = lpMemScript->GetAsNumber();

					info.IncLife = lpMemScript->GetAsNumber();

					info.IncMana = lpMemScript->GetAsNumber();

					info.Defense = lpMemScript->GetAsNumber();

					info.ExcellentDamageRate = lpMemScript->GetAsNumber();

					info.CriticalDamageRate = lpMemScript->GetAsNumber();

					info.DoubleDamageRate = lpMemScript->GetAsNumber();

					info.IncResistDoubleDamage = lpMemScript->GetAsNumber();

					info.IncResistIgnoreDefense = lpMemScript->GetAsNumber();

					info.IncResistIgnoreSD = lpMemScript->GetAsNumber();

					info.IncResistCriticalDamage = lpMemScript->GetAsNumber();

					info.IncResisteExcellentDamage = lpMemScript->GetAsNumber();

					info.IncBlockStuck = lpMemScript->GetAsNumber();

					info.IncReflectRate = lpMemScript->GetAsNumber();

					info.Time = lpMemScript->GetAsNumber();

					this->itemdata.push_back(info);
				}


				else
				{
					break;
				}
			}
		}
	}
	catch (...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void CCustomStartSetItemDame::CalcCustomSetItemOption(LPOBJ lpObj, bool flag)
{
	if (flag != 0)
	{
		return;
	}

	//2 mũ 3 áo 4 quần 5 găng 6 giầy
	CItem* lpItemHelm = &lpObj->Inventory[2];
	CItem* lpItemArmor = &lpObj->Inventory[3];
	CItem* lpItemPant = &lpObj->Inventory[4];
	CItem* lpItemGloves = &lpObj->Inventory[5];
	CItem* lpItemBoot = &lpObj->Inventory[6];

	CItem* lpItemWing = &lpObj->Inventory[7];
	CItem* lpItemKhien = &lpObj->Inventory[1];

	CItem* lpItemPen = &lpObj->Inventory[9];
	CItem* lpItemRing1 = &lpObj->Inventory[10];
	CItem* lpItemRing2 = &lpObj->Inventory[11];


	for (std::vector<CustomStartSetItemDame_Data>::iterator it = gCustomStartSetItemDame.itemdata.begin(); it != gCustomStartSetItemDame.itemdata.end(); it++)
	{
		//-----
		if (lpItemHelm->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemHelm->m_Level >= it->Level && lpItemHelm->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				//--
				lpObj->MagicDamageMax += it->Dame;
				lpObj->MagicDamageMin += it->Dame;
				//--
				lpObj->AddShield += it->IncSD;
				//--
				lpObj->AddLife += it->IncLife;

				lpObj->AddMana += it->IncMana;
				//--
				lpObj->Defense += it->Defense;
				//--
				lpObj->ExcellentDamageRate += it->ExcellentDamageRate;
				//--
				lpObj->CriticalDamageRate += it->CriticalDamageRate;
				//--
				lpObj->DoubleDamageRate += it->DoubleDamageRate;
				//--
				lpObj->ResistDoubleDamageRate += it->IncResistDoubleDamage;
				//--
				lpObj->ResistIgnoreDefenseRate += it->IncResistIgnoreDefense;
				//--
				lpObj->ResistIgnoreShieldGaugeRate += it->IncResistIgnoreSD;
				//--
				lpObj->ResistCriticalDamageRate += it->IncResistCriticalDamage;
				//--
				lpObj->ResistExcellentDamageRate += it->IncResisteExcellentDamage;
				//--
				lpObj->ResistStunRate += it->IncBlockStuck;
				//--
				lpObj->DamageReflect += it->IncReflectRate;
			}
		}
		//-----
		if (lpItemArmor->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemArmor->m_Level >= it->Level && lpItemArmor->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				//--
				lpObj->MagicDamageMax += it->Dame;
				lpObj->MagicDamageMin += it->Dame;
				//--
				lpObj->AddShield += it->IncSD;
				//--
				lpObj->AddLife += it->IncLife;

				lpObj->AddMana += it->IncMana;
				//--
				lpObj->Defense += it->Defense;
				//--
				lpObj->ExcellentDamageRate += it->ExcellentDamageRate;
				//--
				lpObj->CriticalDamageRate += it->CriticalDamageRate;
				//--
				lpObj->DoubleDamageRate += it->DoubleDamageRate;
				//--
				lpObj->ResistDoubleDamageRate += it->IncResistDoubleDamage;
				//--
				lpObj->ResistIgnoreDefenseRate += it->IncResistIgnoreDefense;
				//--
				lpObj->ResistIgnoreShieldGaugeRate += it->IncResistIgnoreSD;
				//--
				lpObj->ResistCriticalDamageRate += it->IncResistCriticalDamage;
				//--
				lpObj->ResistExcellentDamageRate += it->IncResisteExcellentDamage;
				//--
				lpObj->ResistStunRate += it->IncBlockStuck;
				//--
				lpObj->DamageReflect += it->IncReflectRate;
			}
		}
		//-----
		if (lpItemPant->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemPant->m_Level >= it->Level && lpItemPant->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				//--
				lpObj->MagicDamageMax += it->Dame;
				lpObj->MagicDamageMin += it->Dame;
				//--
				lpObj->AddShield += it->IncSD;
				//--
				lpObj->AddLife += it->IncLife;

				lpObj->AddMana += it->IncMana;
				//--
				lpObj->Defense += it->Defense;
				//--
				lpObj->ExcellentDamageRate += it->ExcellentDamageRate;
				//--
				lpObj->CriticalDamageRate += it->CriticalDamageRate;
				//--
				lpObj->DoubleDamageRate += it->DoubleDamageRate;
				//--
				lpObj->ResistDoubleDamageRate += it->IncResistDoubleDamage;
				//--
				lpObj->ResistIgnoreDefenseRate += it->IncResistIgnoreDefense;
				//--
				lpObj->ResistIgnoreShieldGaugeRate += it->IncResistIgnoreSD;
				//--
				lpObj->ResistCriticalDamageRate += it->IncResistCriticalDamage;
				//--
				lpObj->ResistExcellentDamageRate += it->IncResisteExcellentDamage;
				//--
				lpObj->ResistStunRate += it->IncBlockStuck;
				//--
				lpObj->DamageReflect += it->IncReflectRate;
			}
		}
		//-----
		if (lpItemGloves->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemGloves->m_Level >= it->Level && lpItemGloves->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				//--
				lpObj->MagicDamageMax += it->Dame;
				lpObj->MagicDamageMin += it->Dame;
				//--
				lpObj->AddShield += it->IncSD;
				//--
				lpObj->AddLife += it->IncLife;

				lpObj->AddMana += it->IncMana;
				//--
				lpObj->Defense += it->Defense;
				//--
				lpObj->ExcellentDamageRate += it->ExcellentDamageRate;
				//--
				lpObj->CriticalDamageRate += it->CriticalDamageRate;
				//--
				lpObj->DoubleDamageRate += it->DoubleDamageRate;
				//--
				lpObj->ResistDoubleDamageRate += it->IncResistDoubleDamage;
				//--
				lpObj->ResistIgnoreDefenseRate += it->IncResistIgnoreDefense;
				//--
				lpObj->ResistIgnoreShieldGaugeRate += it->IncResistIgnoreSD;
				//--
				lpObj->ResistCriticalDamageRate += it->IncResistCriticalDamage;
				//--
				lpObj->ResistExcellentDamageRate += it->IncResisteExcellentDamage;
				//--
				lpObj->ResistStunRate += it->IncBlockStuck;
				//--
				lpObj->DamageReflect += it->IncReflectRate;
			}
		}
		//-----
		if (lpItemBoot->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemBoot->m_Level >= it->Level && lpItemBoot->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				//--
				lpObj->MagicDamageMax += it->Dame;
				lpObj->MagicDamageMin += it->Dame;
				//--
				lpObj->AddShield += it->IncSD;
				//--
				lpObj->AddLife += it->IncLife;

				lpObj->AddMana += it->IncMana;
				//--
				lpObj->Defense += it->Defense;
				//--
				lpObj->ExcellentDamageRate += it->ExcellentDamageRate;
				//--
				lpObj->CriticalDamageRate += it->CriticalDamageRate;
				//--
				lpObj->DoubleDamageRate += it->DoubleDamageRate;
				//--
				lpObj->ResistDoubleDamageRate += it->IncResistDoubleDamage;
				//--
				lpObj->ResistIgnoreDefenseRate += it->IncResistIgnoreDefense;
				//--
				lpObj->ResistIgnoreShieldGaugeRate += it->IncResistIgnoreSD;
				//--
				lpObj->ResistCriticalDamageRate += it->IncResistCriticalDamage;
				//--
				lpObj->ResistExcellentDamageRate += it->IncResisteExcellentDamage;
				//--
				lpObj->ResistStunRate += it->IncBlockStuck;
				//--
				lpObj->DamageReflect += it->IncReflectRate;
			}
		}
		//-----
		if (lpItemWing->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemWing->m_Level >= it->Level && lpItemWing->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				//--
				lpObj->MagicDamageMax += it->Dame;
				lpObj->MagicDamageMin += it->Dame;
				//--
				lpObj->AddShield += it->IncSD;
				//--
				lpObj->AddLife += it->IncLife;

				lpObj->AddMana += it->IncMana;
				//--
				lpObj->Defense += it->Defense;
				//--
				lpObj->ExcellentDamageRate += it->ExcellentDamageRate;
				//--
				lpObj->CriticalDamageRate += it->CriticalDamageRate;
				//--
				lpObj->DoubleDamageRate += it->DoubleDamageRate;
				//--
				lpObj->ResistDoubleDamageRate += it->IncResistDoubleDamage;
				//--
				lpObj->ResistIgnoreDefenseRate += it->IncResistIgnoreDefense;
				//--
				lpObj->ResistIgnoreShieldGaugeRate += it->IncResistIgnoreSD;
				//--
				lpObj->ResistCriticalDamageRate += it->IncResistCriticalDamage;
				//--
				lpObj->ResistExcellentDamageRate += it->IncResisteExcellentDamage;
				//--
				lpObj->ResistStunRate += it->IncBlockStuck;
				//--
				lpObj->DamageReflect += it->IncReflectRate;
			}
		}
		//-----

		if (lpItemKhien->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemKhien->m_Level >= it->Level && lpItemKhien->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				//--
				lpObj->MagicDamageMax += it->Dame;
				lpObj->MagicDamageMin += it->Dame;
				//--
				lpObj->AddShield += it->IncSD;
				//--
				lpObj->AddLife += it->IncLife;

				lpObj->AddMana += it->IncMana;
				//--
				lpObj->Defense += it->Defense;
				//--
				lpObj->ExcellentDamageRate += it->ExcellentDamageRate;
				//--
				lpObj->CriticalDamageRate += it->CriticalDamageRate;
				//--
				lpObj->DoubleDamageRate += it->DoubleDamageRate;
				//--
				lpObj->ResistDoubleDamageRate += it->IncResistDoubleDamage;
				//--
				lpObj->ResistIgnoreDefenseRate += it->IncResistIgnoreDefense;
				//--
				lpObj->ResistIgnoreShieldGaugeRate += it->IncResistIgnoreSD;
				//--
				lpObj->ResistCriticalDamageRate += it->IncResistCriticalDamage;
				//--
				lpObj->ResistExcellentDamageRate += it->IncResisteExcellentDamage;
				//--
				lpObj->ResistStunRate += it->IncBlockStuck;
				//--
				lpObj->DamageReflect += it->IncReflectRate;
			}
		}






		//-----
		if (lpItemPen->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemPen->m_Level >= it->Level && lpItemPen->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				//--
				lpObj->MagicDamageMax += it->Dame;
				lpObj->MagicDamageMin += it->Dame;
				//--
				lpObj->AddShield += it->IncSD;
				//--
				lpObj->AddLife += it->IncLife;

				lpObj->AddMana += it->IncMana;
				//--
				lpObj->Defense += it->Defense;
				//--
				lpObj->ExcellentDamageRate += it->ExcellentDamageRate;
				//--
				lpObj->CriticalDamageRate += it->CriticalDamageRate;
				//--
				lpObj->DoubleDamageRate += it->DoubleDamageRate;
				//--
				lpObj->ResistDoubleDamageRate += it->IncResistDoubleDamage;
				//--
				lpObj->ResistIgnoreDefenseRate += it->IncResistIgnoreDefense;
				//--
				lpObj->ResistIgnoreShieldGaugeRate += it->IncResistIgnoreSD;
				//--
				lpObj->ResistCriticalDamageRate += it->IncResistCriticalDamage;
				//--
				lpObj->ResistExcellentDamageRate += it->IncResisteExcellentDamage;
				//--
				lpObj->ResistStunRate += it->IncBlockStuck;
				//--
				lpObj->DamageReflect += it->IncReflectRate;
			}
		}
		//-----
		if (lpItemRing1->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemRing1->m_Level >= it->Level && lpItemRing1->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				//--
				lpObj->MagicDamageMax += it->Dame;
				lpObj->MagicDamageMin += it->Dame;
				//--
				lpObj->AddShield += it->IncSD;
				//--
				lpObj->AddLife += it->IncLife;

				lpObj->AddMana += it->IncMana;
				//--
				lpObj->Defense += it->Defense;
				//--
				lpObj->ExcellentDamageRate += it->ExcellentDamageRate;
				//--
				lpObj->CriticalDamageRate += it->CriticalDamageRate;
				//--
				lpObj->DoubleDamageRate += it->DoubleDamageRate;
				//--
				lpObj->ResistDoubleDamageRate += it->IncResistDoubleDamage;
				//--
				lpObj->ResistIgnoreDefenseRate += it->IncResistIgnoreDefense;
				//--
				lpObj->ResistIgnoreShieldGaugeRate += it->IncResistIgnoreSD;
				//--
				lpObj->ResistCriticalDamageRate += it->IncResistCriticalDamage;
				//--
				lpObj->ResistExcellentDamageRate += it->IncResisteExcellentDamage;
				//--
				lpObj->ResistStunRate += it->IncBlockStuck;
				//--
				lpObj->DamageReflect += it->IncReflectRate;
			}
		}
		//-----
		if (lpItemRing2->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		{
			if (lpItemRing2->m_Level >= it->Level && lpItemRing2->m_NewOption >= it->Option) //  & it->ItemNewOption) == 0)
			{
				lpObj->PhysiDamageMinLeft += it->Dame;
				lpObj->PhysiDamageMinRight += it->Dame;
				lpObj->PhysiDamageMaxLeft += it->Dame;
				lpObj->PhysiDamageMaxRight += it->Dame;
				//--
				lpObj->MagicDamageMax += it->Dame;
				lpObj->MagicDamageMin += it->Dame;
				//--
				lpObj->AddShield += it->IncSD;
				//--
				lpObj->AddLife += it->IncLife;

				lpObj->AddMana += it->IncMana;
				//--
				lpObj->Defense += it->Defense;
				//--
				lpObj->ExcellentDamageRate += it->ExcellentDamageRate;
				//--
				lpObj->CriticalDamageRate += it->CriticalDamageRate;
				//--
				lpObj->DoubleDamageRate += it->DoubleDamageRate;
				//--
				lpObj->ResistDoubleDamageRate += it->IncResistDoubleDamage;
				//--
				lpObj->ResistIgnoreDefenseRate += it->IncResistIgnoreDefense;
				//--
				lpObj->ResistIgnoreShieldGaugeRate += it->IncResistIgnoreSD;
				//--
				lpObj->ResistCriticalDamageRate += it->IncResistCriticalDamage;
				//--
				lpObj->ResistExcellentDamageRate += it->IncResisteExcellentDamage;
				//--
				lpObj->ResistStunRate += it->IncBlockStuck;
				//--
				lpObj->DamageReflect += it->IncReflectRate;
			}
		}
		//-----

	}
}

#endif