//
// Created by User on 08.06.2022.
//

#ifndef EX4_MAIN_GOBLIN_H
#define EX4_MAIN_GOBLIN_H

#include "Cards/BattleCard.h"

class Goblin: public BattleCard{

    static const int DEFAULT_FORCE = 6;
    static const int DEFAULT_LOOT = 2;
    static const int DEFAULT_DAMAGE = 10;

public:
    Goblin();
    Goblin(const Goblin&)=default;
    Goblin& operator=(const Goblin&)=default;
    ~Goblin() override =default;
    void  applyEncounter(Player& player) const override;
    virtual void applyDebuff(Player& player) const override;

};


#endif //EX4_MAIN_GOBLIN_H
