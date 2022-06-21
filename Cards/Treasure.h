//
// Created by User on 08.06.2022.
//

#ifndef EX4_MAIN_TREASURE_H
#define EX4_MAIN_TREASURE_H

#include "Card.h"

class Treasure: public Card{
    static const int COINS_TO_ADD=10;
public:
    Treasure();
    Treasure(const Treasure&)=default;
    Treasure& operator=(const Treasure&)=default;
    ~Treasure() override =default;
    void applyEncounter(Player& player) const override;
};


#endif //EX4_MAIN_TREASURE_H
