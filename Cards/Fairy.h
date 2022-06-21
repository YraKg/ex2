//
// Created by User on 08.06.2022.
//

#ifndef EX4_MAIN_FAIRY_H
#define EX4_MAIN_FAIRY_H

#include "Card.h"

class Fairy: public Card {
    static const int HEAL_AMOUNT=10;
public:
    Fairy();
    Fairy(const Fairy&)=default;
    Fairy& operator=(const Fairy&)=default;
    ~Fairy() override =default;
    void applyEncounter(Player& player) const override;
};


#endif //EX4_MAIN_FAIRY_H
