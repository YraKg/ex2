#include "Gang.h"

#include <utilities.h>
#include "Players/Player.h"
Gang::Gang(std::vector<std::shared_ptr<BattleCard>> gang):
        Card("Gang"), m_gang(std::move(gang))
{}

void Gang::applyEncounter(Player &player) const {
    bool lost=false;
    for(const std::shared_ptr<BattleCard>& monster:this->m_gang) {
       if(!lost)
       {
           lost=!monster->fight(player);
       }

       else
        {
            monster->applyDebuff(player);
        }
    }
    if(!lost)
    {
        player.levelUp();
        printWinBattle(player.getName(),this->m_name);
    }
}

