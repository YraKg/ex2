
#include "Pitfall.h"
#include "Players/Rogue.h"
#include "utilities.h"
Pitfall::Pitfall():
        Card("Pitfall")
{}


void Pitfall::applyEncounter(Player &player) const {

    bool is_rogue=true;
    try{
        dynamic_cast<Rogue&>(player);
    }
    catch (std::bad_cast)
    {
        is_rogue=false;
    }
    if(!is_rogue)
        player.damage(Pitfall::DAMAGE_ON_FALL);
    printPitfallMessage(is_rogue);
}