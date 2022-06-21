//
// Created by User on 08.06.2022.
//

#ifndef EX4_MAIN_BARFIGHT_H
#define EX4_MAIN_BARFIGHT_H

#include "Card.h"
class Barfight: public Card{
    static const int DAMAGE_AMOUNT=10;
public:
    Barfight();
    Barfight(const Barfight&)=default;
    Barfight& operator=(const Barfight&)=default;
    ~Barfight() override =default;
    void applyEncounter(Player& player) const override;
};


#endif //EX4_MAIN_BARFIGHT_H
