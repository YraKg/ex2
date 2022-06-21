
#include "Cards/Vampire.h"
#include "Players/Player.h"
#include "utilities.h"
Vampire::Vampire():
        BattleCard("Vampire",Vampire::DEFAULT_FORCE,Vampire::DEFAULT_DAMAGE,Vampire::DEFAULT_LOOT)
{}


void Vampire::applyDebuff(Player& player) const{
    player.damage(this->m_damage);
    player.buff(-1);
    printLossBattle(player.getName(),this->m_name);

}
void Vampire::applyEncounter(Player &player) const {
    if(player.getAttackStrength()>=this->m_force)
    {
        player.levelUp();
        player.addCoins(this->m_loot);
        printWinBattle(player.getName(),this->m_name);

    }
    else
    {
        this->applyDebuff(player);

    }



}