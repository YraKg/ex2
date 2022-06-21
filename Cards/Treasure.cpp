//
// Created by User on 08.06.2022.
//

#include "Treasure.h"
#include "Players/Player.h"
#include "utilities.h"
Treasure::Treasure():
        Card("Treasure")
{}

void Treasure::applyEncounter(Player &player) const {
    player.addCoins(Treasure::COINS_TO_ADD);
    printTreasureMessage();
}