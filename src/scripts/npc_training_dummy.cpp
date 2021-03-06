#include "Precompiled.h"

struct MANGOS_DLL_DECL npc_training_dummyAI : public Scripted_NoMovementAI
{
    npc_training_dummyAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature){}

    typedef UNORDERED_MAP<ObjectGuid, uint32> AttackerMap;
    AttackerMap m_AttackerMap;

    void Reset() {}

    void DamageTaken(Unit* pDealer, uint32& uiDamage)
    {
        if (pDealer->GetTypeId() == TYPEID_PLAYER)
            m_AttackerMap[pDealer->GetObjectGuid()] = 5000;

        m_creature->SetHealth(m_creature->GetMaxHealth() * 0.2f);
        //m_creature->SetTargetGuid(m_creature->GetObjectGuid());
    }

    void UpdateAI(const uint32 diff)
    {
        for (AttackerMap::iterator itr = m_AttackerMap.begin(); itr != m_AttackerMap.end();)
        {
            if (itr->second < diff)
            {
                if (Player* pAttacker = m_creature->GetMap()->GetPlayer(itr->first))
                {
                    pAttacker->CombatStop(true);
                    pAttacker->AttackStop(false);
                    pAttacker->CombatStopWithPets(true);
                    pAttacker->ClearInCombat();
                }

                itr = m_AttackerMap.erase(itr);

                if (m_AttackerMap.empty())
                {
                    EnterEvadeMode();
                    m_creature->SetHealth(m_creature->GetMaxHealth());
                }
            }
            else
            {
                itr->second -= diff;
                ++itr;
            }
        }
    }
};

CreatureAI* GetAI_npc_training_dummy(Creature* pCreature)
{
    return new npc_training_dummyAI(pCreature);
}


void AddSC_npc_training_dummy()
{
    Script* pNewScript;

    pNewScript                  = new Script;
    pNewScript->Name            = "npc_training_dummy";
    pNewScript->GetAI           = &GetAI_npc_training_dummy;
    pNewScript->RegisterSelf();
}