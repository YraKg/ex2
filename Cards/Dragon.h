//
// Created by User on 08.06.2022.
//

#ifndef EX4_MAIN_DRAGON_H
#define EX4_MAIN_DRAGON_H

#include "Cards/BattleCard.h"

class Dragon: public BattleCard{
    static const int DEFAULT_FORCE = 25;
    static const int DEFAULT_LOOT = 1000;
    static const int DEFAULT_DAMAGE = 100;

public:
    Dragon();
    Dragon(const Dragon&)=default;
    Dragon& operator=(const Dragon&)=default;
    ~Dragon() override =default;
    void  applyEncounter(Player& player) const override;
    virtual void applyDebuff(Player &player) const override;

};


#endif //EX4_MAIN_DRAGON_H
