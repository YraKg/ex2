
#include "Fairy.h"
#include "Players/Wizard.h"
#include "utilities.h"

Fairy::Fairy():
Card("Fairy")
{}

void Fairy::applyEncounter(Player &player) const {
    bool is_wizard = true;
    try{
        dynamic_cast<Wizard&>(player);
    }
    catch(std::bad_cast){
        is_wizard=false;
    }
    if(is_wizard)
    {
        player.heal(HEAL_AMOUNT);
    }
    printFairyMessage(is_wizard);
}