#include <cassert>
#include "Card.h"
#include "Player.h"


Card::Card(CardType type,const CardStats& stats):m_effect(type)
{
   this->m_stats = CardStats(stats.force,stats.hpLossOnDefeat,stats.cost,stats.heal,stats.buff,stats.loot);
}

void Card::applyEncounter(Player& player) const
{
    switch (this->m_effect)
    {
        case CardType::Battle:
            assert(this->m_stats.force>=0);
            if(player.getAttackStrength()>=this->m_stats.force)
            {
                player.levelUp();
                player.addCoins(this->m_stats.loot);
                printBattleResult(true);
            }
            else
            {
                assert(this->m_stats.hpLossOnDefeat>=0);
                player.damage(this->m_stats.hpLossOnDefeat);
                printBattleResult(false);
            }
            break;
        case CardType::Buff:
            assert(this->m_stats.buff>=0);
            if(player.pay(this->m_stats.cost))
                player.buff(this->m_stats.buff);
            break;
        case CardType::Heal:
            assert(this->m_stats.heal>=0);
            if(player.pay(this->m_stats.cost))
                player.heal(this->m_stats.heal);
            break;
        case CardType::Treasure:
            assert(this->m_stats.loot>=0);
            player.addCoins(this->m_stats.loot);
            break;

    }

}

void Card::printInfo() const
{
    switch (this->m_effect)
    {
        case CardType::Battle:
            printBattleCardInfo(this->m_stats);
            break;
        case CardType::Buff:
            printBuffCardInfo(this->m_stats);
            break;
        case CardType::Heal:
            printHealCardInfo(this->m_stats);
            break;
        case CardType::Treasure:
            printTreasureCardInfo(this->m_stats);
            break;

    }

}