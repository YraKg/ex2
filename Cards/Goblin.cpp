
#include "Goblin.h"
#include "Players/Player.h"
#include "utilities.h"

Goblin::Goblin():
        BattleCard("Goblin",Goblin::DEFAULT_FORCE,Goblin::DEFAULT_DAMAGE,Goblin::DEFAULT_LOOT)
{}

void Goblin::applyDebuff(Player& player) const{
    player.damage(this->m_damage);
    printLossBattle(player.getName(),this->m_name);
}
void Goblin::applyEncounter(Player &player) const {
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