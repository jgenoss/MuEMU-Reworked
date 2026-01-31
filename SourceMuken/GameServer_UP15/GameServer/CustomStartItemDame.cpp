#include "stdafx.h"
#include "Util.h"
#include "User.h"
#include "CustomStartItemDame.h"
#include "CashShop.h"
#include "MemScript.h"
#include "Notice.h"
#include "DSProtocol.h"
#include "ItemManager.h"
#include "ServerInfo.h"
#include "SocketItemType.h"
#include "Message.h"
#include "ObjectManager.h"

CCustomStartItemDame gCustomStartItemDame;

CCustomStartItemDame::CCustomStartItemDame() // OK
{
	this->Init();
}

CCustomStartItemDame::~CCustomStartItemDame() // OK
{

}

void CCustomStartItemDame::Init() // OK
{
	for (int n = 0; n < MAX_CLASS; n++)
	{
		this->m_CustomStartItemDameInfo[n].Class = -1;
		this->m_CustomStartItemDameInfo[n].ItemDameStart.clear();
	}
}

void CCustomStartItemDame::LoadItemDame(char* path) // OK
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

	this->Init();

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
					CUSTOM_START_ITEM_DAME_INFO Items;

					int Class = lpMemScript->GetNumber();

					Items.ItemType = lpMemScript->GetAsNumber();

					Items.ItemIndex = lpMemScript->GetAsNumber();

					Items.ItemLevel = lpMemScript->GetAsNumber();

					Items.ItemLuck = lpMemScript->GetAsNumber();

					Items.ItemDurability = lpMemScript->GetAsNumber();

					Items.ItemSkill = lpMemScript->GetAsNumber();

					Items.ItemOption = lpMemScript->GetAsNumber();

					Items.ItemExcellent = lpMemScript->GetAsNumber();

					Items.TypeBuff = lpMemScript->GetAsNumber();

					Items.EffectBuff = lpMemScript->GetAsNumber();

					Items.DupeDame = lpMemScript->GetAsNumber();

					Items.TripDame = lpMemScript->GetAsNumber();

					Items.DameRate = lpMemScript->GetAsNumber();

					Items.DefDameRate = lpMemScript->GetAsNumber();

					Items.Power1Buff = lpMemScript->GetAsNumber();

					Items.Power2Buff = lpMemScript->GetAsNumber();

					Items.TimeBuff = lpMemScript->GetAsNumber();

					this->m_CustomStartItemDameInfo[Class].ItemDameStart.push_back(Items);
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



bool CCustomStartItemDame::CheckSkillEffectDame(int m_index) // OK
{
	bool skill = false;
	switch (m_index)
	{
	case EFFECT_GREATER_DAMAGE:
		skill = true;
		break;
	case EFFECT_GREATER_DEFENSE:
		skill = true;
		break;
	case EFFECT_ELF_BUFFER:
		skill = true;
		break;
	case EFFECT_MANA_SHIELD:
		skill = true;
		break;
	case EFFECT_GREATER_CRITICAL_DAMAGE:
		skill = true;
		break;
	case EFFECT_INFINITY_ARROW:
		break;
	case EFFECT_BP_RECOVERY:
		break;
	case EFFECT_GREATER_LIFE:
		skill = true;
		break;
	case EFFECT_GREATER_MANA:
		skill = true;
		break;
	case EFFECT_BLESS_POTION:
		break;
	case EFFECT_SOUL_POTION:
		break;
	case EFFECT_DISABLE_MAGIC:
		break;
	case EFFECT_CASTLE_GATE_STATE:
		break;
	case EFFECT_GUILD_STATE1:
		break;
	case EFFECT_GUILD_STATE2:
		break;
	case EFFECT_GUILD_STATE3:
		break;
	case EFFECT_GUILD_STATE4:
		break;
	case EFFECT_INVISIBILITY:
		break;
	case EFFECT_GUILD_STATE5:
		break;
	case EFFECT_CASTLE_CROWN_STATE:
		break;
	case EFFECT_CRYWOLF_STATE1:
		break;
	case EFFECT_CRYWOLF_STATE2:
		break;
	case EFFECT_CRYWOLF_STATE3:
		break;
	case EFFECT_CRYWOLF_STATE4:
		break;
	case EFFECT_CRYWOLF_STATE5:
		break;
	case EFFECT_CRYWOLF_STATE6:
		break;
	case EFFECT_CRYWOLF_STATE7:
		break;
	case EFFECT_GAME_MASTER:
		break;
	case EFFECT_SEAL_OF_ASCENSION1:
		break;
	case EFFECT_SEAL_OF_WEALTH1:
		break;
	case EFFECT_SEAL_OF_SUSTENANCE1:
		break;
	case EFFECT_ORDER_OF_SPEED:
		break;
	case EFFECT_ORDER_OF_SUBLIMATION:
		break;
	case EFFECT_ORDER_OF_PROTECTION:
		break;
	case EFFECT_HALLOWEEN1:
		break;
	case EFFECT_HALLOWEEN2:
		break;
	case EFFECT_HALLOWEEN3:
		break;
	case EFFECT_HALLOWEEN4:
		break;
	case EFFECT_HALLOWEEN5:
		break;
	case EFFECT_SEAL_OF_ASCENSION2:
		break;
	case EFFECT_SEAL_OF_WEALTH2:
		break;
	case EFFECT_SEAL_OF_SUSTENANCE2:
		break;
	case EFFECT_SEAL_OF_MOVEMENT:
		break;
	case EFFECT_SCROLL_OF_QUICK:
		break;
	case EFFECT_SCROLL_OF_DEFENSE:
		break;
	case EFFECT_SCROLL_OF_DAMAGE:
		break;
	case EFFECT_SCROLL_OF_MAGIC_DAMAGE:
		break;
	case EFFECT_SCROLL_OF_LIFE:
		break;
	case EFFECT_SCROLL_OF_MANA:
		break;
	case EFFECT_ELIXIR_OF_STRENGTH:
		break;
	case EFFECT_ELIXIR_OF_DEXTERITY:
		break;
	case EFFECT_ELIXIR_OF_VITALITY:
		break;
	case EFFECT_ELIXIR_OF_ENERGY:
		break;
	case EFFECT_ELIXIR_OF_LEADERSHIP:
		break;
	case EFFECT_POISON:
		break;
	case EFFECT_ICE:
		break;
	case EFFECT_ICE_ARROW:
		break;
	case EFFECT_FIRE_SLASH:
		break;
	case EFFECT_PHYSI_DAMAGE_IMMUNITY:
		break;
	case EFFECT_MAGIC_DAMAGE_IMMUNITY:
		break;
	case EFFECT_STERN:
		break;
	case EFFECT_MAGIC_DEFENSE:
		break;
	case EFFECT_MONSTER_PHYSI_DAMAGE_IMMUNITY:
		break;
	case EFFECT_MONSTER_MAGIC_DAMAGE_IMMUNITY:
		break;
	case EFFECT_ORDER_OF_RESTRAINT:
		break;
	case EFFECT_CRYWOLF_STATE8:
		break;
	case EFFECT_CRYWOLF_STATE9:
		break;
	case EFFECT_CRYWOLF_STATE10:
		break;
	case EFFECT_CRYWOLF_STATE11:
		break;
	case EFFECT_CRYWOLF_STATE12:
		break;
	case EFFECT_DAMAGE_REFLECT:
		skill = true;
		break;
	case EFFECT_SLEEP:
		break;
	case EFFECT_BLIND:
		skill = true;
		break;
	case EFFECT_NEIL:
		break;
	case EFFECT_SAHAMUTT:
		break;
	case EFFECT_LESSER_DAMAGE:
		skill = true;
		break;
	case EFFECT_LESSER_DEFENSE:
		skill = true;
		break;
	case EFFECT_CHERRY_BLOSSOM1:
		break;
	case EFFECT_CHERRY_BLOSSOM2:
		break;
	case EFFECT_CHERRY_BLOSSOM3:
		break;
	case EFFECT_SWORD_POWER:
		skill = true;
		break;
	case EFFECT_MAGIC_CIRCLE:
		skill = true;
		break;
	case EFFECT_SWORD_SLASH:
		break;
		break;
	case EFFECT_RED_STORM:
		skill = true;
		break;
	case EFFECT_FROZEN_STAB:
		skill = true;
		break;
	case EFFECT_SEAL_OF_LIFE:
		break;
	case EFFECT_SEAL_OF_MANA:
		break;
	case EFFECT_SCROLL_OF_BATTLE:
		break;
	case EFFECT_SCROLL_OF_STRENGTH:
		break;
	case EFFECT_CHRISTMAS1:
		break;
	case EFFECT_CHRISTMAS2:
		break;
	case EFFECT_CHRISTMAS3:
		break;
	case EFFECT_CHRISTMAS4:
		break;
	case EFFECT_CHRISTMAS5:
		break;
	case EFFECT_CHRISTMAS6:
		break;
	case EFFECT_CHRISTMAS7:
		break;
	case EFFECT_DUEL_ARENA_WATCH:
		break;
	case EFFECT_TALISMAN_OF_GUARDIAN:
		break;
	case EFFECT_TALISMAN_OF_PROTECTION:
		break;
	case EFFECT_MASTER_SEAL_OF_ASCENSION:
		break;
	case EFFECT_MASTER_SEAL_OF_WEALTH:
		break;
	case EFFECT_GLADIATORS_GLORY:
		break;
	case EFFECT_PARTY_EXPERIENCE_BONUS:
		break;
	case EFFECT_MAX_AG_BOOST_AURA:
		break;
	case EFFECT_MAX_SD_BOOST_AURA:
		break;
	case EFFECT_SCROLL_OF_HEALING:
		break;
	case EFFECT_HAWK_FIGURINE:
		break;
	case EFFECT_GOAT_FIGURINE:
		break;
	case EFFECT_OAK_CHARM:
		break;
	case EFFECT_MAPLE_CHARM:
		break;
	case EFFECT_GOLDEN_OAK_CHARM:
		break;
	case EFFECT_GOLDEN_MAPLE_CHARM:
		break;
	case EFFECT_WORN_HORSESHOE:
		break;
	case EFFECT_GREATER_IGNORE_DEFENSE_RATE:
		skill = true;
		break;
	case EFFECT_FITNESS:
		skill = true;
		break;
	case EFFECT_GREATER_DEFENSE_SUCCESS_RATE:
		skill = true;
		break;
	case EFFECT_IRON_DEFENSE:
		skill = true;
		break;
	case EFFECT_GREATER_LIFE_ENHANCED:
		skill = true;
		break;
	case EFFECT_GREATER_LIFE_MASTERED:
		skill = true;
		break;
	case EFFECT_DEATH_STAB_ENHANCED:
		skill = true;
		break;
	case EFFECT_MAGIC_CIRCLE_IMPROVED:
		skill = true;
		break;
	case EFFECT_MAGIC_CIRCLE_ENHANCED:
		skill = true;
		break;
	case EFFECT_MANA_SHIELD_MASTERED:
		skill = true;
		break;
	case EFFECT_FROZEN_STAB_MASTERED:
		skill = true;
		break;
	case EFFECT_BLESS:
		break;
	case EFFECT_INFINITY_ARROW_IMPROVED:
		skill = true;
		break;
	case EFFECT_BLIND_IMPROVED:
		skill = true;
		break;
	case EFFECT_DRAIN_LIFE_ENHANCED:
		skill = true;
		break;
	case EFFECT_ICE_STORM_ENHANCED:
		skill = true;
		break;
	case EFFECT_EARTH_PRISON:
		skill = true;
		break;
	case EFFECT_GREATER_CRITICAL_DAMAGE_MASTERED:
		skill = true;
		break;
	case EFFECT_GREATER_CRITICAL_DAMAGE_EXTENDED:
		skill = true;
		break;
	case EFFECT_SWORD_POWER_IMPROVED:
		skill = true;
		break;
	case EFFECT_SWORD_POWER_ENHANCED:
		skill = true;
		break;
	case EFFECT_SWORD_POWER_MASTERED:
		skill = true;
		break;
	case EFFECT_GREATER_DEFENSE_SUCCESS_RATE_IMPROVED:
		skill = true;
		break;
	case EFFECT_GREATER_DEFENSE_SUCCESS_RATE_ENHANCED:
		skill = true;
		break;
	case EFFECT_FITNESS_IMPROVED:
		skill = true;
		break;
	case EFFECT_DRAGON_ROAR_ENHANCED:
		skill = true;
		break;
	case EFFECT_CHAIN_DRIVER_ENHANCED:
		skill = true;
		break;
	case EFFECT_POISON_ARROW:
		skill = true;
		break;
	case EFFECT_POISON_ARROW_IMPROVED:
		skill = true;
		break;
	case EFFECT_BLESS_IMPROVED:
		break;
	case EFFECT_LESSER_DAMAGE_IMPROVED:
		skill = true;
		break;
	case EFFECT_LESSER_DEFENSE_IMPROVED:
		skill = true;
		break;
	case EFFECT_FIRE_SLASH_ENHANCED:
		skill = true;
		break;
	case EFFECT_IRON_DEFENSE_IMPROVED:
		skill = true;
		break;
	case EFFECT_BLOOD_HOWLING:
		break;
	case EFFECT_BLOOD_HOWLING_IMPROVED:
		break;
	case EFFECT_PENTAGRAM_JEWEL_HALF_SD:
		break;
	case EFFECT_PENTAGRAM_JEWEL_HALF_MP:
		break;
	case EFFECT_PENTAGRAM_JEWEL_HALF_SPEED:
		break;
	case EFFECT_PENTAGRAM_JEWEL_HALF_HP:
		break;
	case EFFECT_PENTAGRAM_JEWEL_STUN:
		break;
	case EFFECT_PENTAGRAM_JEWEL_SLOW:
		break;
	case EFFECT_TALISMAN_OF_ASCENSION1:
		break;
	case EFFECT_TALISMAN_OF_ASCENSION2:
		skill = true;
		break;
	case EFFECT_TALISMAN_OF_ASCENSION3:
		break;
	case EFFECT_SEAL_OF_ASCENSION3:
		break;
	case EFFECT_MASTER_SEAL_OF_ASCENSION2:
		break;
	case EFFECT_BLESSING_OF_LIGHT:
		break;
	case EFFECT_MASTER_SCROLL_OF_DEFENSE:
		break;
	case EFFECT_MASTER_SCROLL_OF_MAGIC_DAMAGE:
		break;
	case EFFECT_MASTER_SCROLL_OF_LIFE:
		break;
	case EFFECT_MASTER_SCROLL_OF_MANA:
		break;
	case EFFECT_MASTER_SCROLL_OF_DAMAGE:
		break;
	case EFFECT_MASTER_SCROLL_OF_HEALING:
		break;
	case EFFECT_MASTER_SCROLL_OF_BATTLE:
		break;
	case EFFECT_MASTER_SCROLL_OF_STRENGTH:
		break;
	case EFFECT_MASTER_SCROLL_OF_QUICK:
		break;
	case EFFECT_DAME_ITEM_SWICH:
		break;
	}

	return skill;
}

void CCustomStartItemDame::CaclCharacter(LPOBJ lpObj, bool flag)
{
	if (flag != 0)
	{
		return;
	}

	/*if (!lpObj->Inventory[0].IsItem())
	{
	return;
	}*/

	CItem* lpItem = &lpObj->Inventory[0];
	CItem* lpItem1 = &lpObj->Inventory[1];

	for (std::vector<CUSTOM_START_ITEM_DAME_INFO>::iterator it = this->m_CustomStartItemDameInfo[lpObj->Class].ItemDameStart.begin(); it != this->m_CustomStartItemDameInfo[lpObj->Class].ItemDameStart.end(); it++)
	{
		if (lpObj->Inventory[0].m_Index == GET_ITEM(it->ItemType, it->ItemIndex) || lpObj->Inventory[1].m_Index == GET_ITEM(it->ItemType, it->ItemIndex))
		//if (lpItem->m_Index == GET_ITEM(it->ItemType, it->ItemIndex)) /*|| lpItem1->m_Index == GET_ITEM(it->ItemType, it->ItemIndex))*/
		{
			if (lpItem->m_Level >= it->ItemLevel && lpItem->m_NewOption >= it->ItemOption || lpItem1->m_Level >= it->ItemLevel && lpItem1->m_NewOption >= it->ItemOption)
			{
				lpObj->DoubleDamageRate += it->DupeDame;//
				lpObj->TripleDamageRate += it->TripDame;//

				lpObj->PhysiDamageMinLeft += it->DameRate;//
				lpObj->PhysiDamageMinRight += it->DameRate;//
				lpObj->PhysiDamageMaxLeft += it->DameRate;//
				lpObj->PhysiDamageMaxRight += it->DameRate;//

				lpObj->MagicDamageMax += it->DameRate;//
				lpObj->MagicDamageMin += it->DameRate;//

				lpObj->DefensePvP += it->DefDameRate;//
			}
		}
	}
}