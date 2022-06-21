#include "BattleCard.h"



#include "utilities.h"

BattleCard::BattleCard(std::string name, int force, int damage, int loot):
Card(name),
m_force(force),
m_damage(damage),
m_loot(loot)
{}
void BattleCard::printInfo() const
{   //dragons damage value is set to be -1
    printMonsterDetails(std::cout,this->m_force,this->m_damage,this->m_loot,(this->m_damage==-1));
}
 bool BattleCard::fight(Player &player) {
    if(player.getAttackStrength()>=this->m_force)
    {
        player.addCoins(this->m_loot);
        return true;
    }

    else{
        this->applyDebuff(player);
        return false;
    }

}