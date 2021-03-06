#include "Player.h"
#include "Custom.h"

void Player::PlayerGossip(uint32 sender, uint32 action, std::string code)
{
    PlayerTalkClass->CloseGossip();

    if (sender == GOSSIP_SENDER_FIRSTLOGIN)
    {
        // Warrior
        if (action == 1)
        { // Warrior - Arms
            AddItemSet(750);
        }
        else if (action == 2)
        { // Warrior - Fury
            AddItemSet(750);
        }
        else if (action == 3)
        { // Warrior - Protection
            AddItemSet(750);
        }
        // Paladin
        else if (action == 4)
        { // Paladin - Holy
            AddItemSet(751);
        }
        else if (action == 5)
        { // Paladin - Protection
            AddItemSet(752);
        }
        else if (action == 6)
        { // Paladin - Retribution
            AddItemSet(752);
        }
        // Hunter
        else if (action == 7)
        { // Hunter - Beast Mastery
            AddItemSet(749);
        }
        else if (action == 8)
        { // Hunter - Marksmanship
            AddItemSet(749);
        }
        else if (action == 9)
        { // Hunter - Survival
            AddItemSet(749);
        }
        // Rogue
        else if (action == 10)
        { // Rogue - Assassination
            AddItemSet(745);
        }
        else if (action == 11)
        { // Rogue - Combat
            AddItemSet(745);
        }
        else if (action == 12)
        { // Rogue - Subtlety
            AddItemSet(745);
        }
        // Priest
        else if (action == 13)
        { // Priest - Discipline
            AddItemSet(739);
        }
        else if (action == 14)
        { // Priest - Holy
            AddItemSet(739);
        }
        else if (action == 15)
        { // Priest - Shadow
            AddItemSet(740);
        }
        // Shaman
        else if (action == 16)
        { // Shaman - Elemental
            AddItemSet(739);
        }
        else if (action == 17)
        { // Shaman - Enhancement
            AddItemSet(746);
        }
        else if (action == 18)
        { // Shaman - Restoration
            AddItemSet(747);
        }
        // Mage
        else if (action == 19)
        { // Mage - Arcane
            AddItemSet(741);
        }
        else if (action == 20)
        { // Mage - Fire
            AddItemSet(741);
        }
        else if (action == 21)
        { // Mage - Frost
            AddItemSet(741);
        }
        // Warlock
        else if (action == 22)
        { // Warlock - Affliction
            AddItemSet(738);
        }
        else if (action == 23)
        { // Warlock - Demonology
            AddItemSet(738);
        }
        else if (action == 24)
        { // Warlock - Destruction
            AddItemSet(738);
        }
        // Druid
        else if (action == 25)
        { // Druid - Balance
            AddItemSet(743);
        }
        else if (action == 26)
        { // Druid - Feral
            AddItemSet(742);
        }
        else if (action == 27)
        { // Druid - Restoration
            AddItemSet(744);
        }
    }
}