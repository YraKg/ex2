
#include "Barfight.h"
#include "Players/Fighter.h"
#include "utilities.h"

Barfight::Barfight():
        Card("Barfight")
{}

void Barfight::applyEncounter(Player &player) const {
    bool is_fighter=true;
    try{
        dynamic_cast<Fighter&>(player);
    }
    catch(std::bad_cast){
        is_fighter=false;
    }
    if(!is_fighter)
        player.damage(Barfight::DAMAGE_AMOUNT);
    printBarfightMessage(is_fighter);
}