//
// Created by User on 08.06.2022.
//

#ifndef EX4_MAIN_VAMPIRE_H
#define EX4_MAIN_VAMPIRE_H

#include "Cards/BattleCard.h"

class Vampire: public BattleCard{
    static const int DEFAULT_FORCE = 10;
    static const int DEFAULT_LOOT = 2;
    static const int DEFAULT_DAMAGE = 10;

public:
    Vampire();
    Vampire(const Vampire&)=default;
    Vampire& operator=(const Vampire&)=default;
    ~Vampire() override =default;
    void  applyEncounter(Player& player) const override;
    void applyDebuff(Player& player) const override ;

};


#endif //EX4_MAIN_VAMPIRE_H
