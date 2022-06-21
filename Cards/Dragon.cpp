
#include "Dragon.h"
#include "Players/Player.h"
#include "utilities.h"
Dragon::Dragon():
        BattleCard("Dragon",Dragon::DEFAULT_FORCE,Dragon::DEFAULT_DAMAGE,Dragon::DEFAULT_LOOT)
{}
void Dragon::applyDebuff(Player &player) const{
    while(!player.isKnockedOut())
        player.damage(m_damage);
    printLossBattle(player.getName(),this->m_name);
}
void Dragon::applyEncounter(Player &player) const {
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