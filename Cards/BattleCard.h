

//
// Created by User on 08.06.2022.
//

#ifndef EX4_MAIN_BATTLECARD_H
#define EX4_MAIN_BATTLECARD_H
#include "Card.h"





class BattleCard: public Card {
protected:
    int m_force;
    int m_damage;
    int m_loot;
public:

    BattleCard(const BattleCard& card)=default;
    BattleCard& operator=(const BattleCard& card)=default;
    BattleCard(std::string name, int force,int damage, int loot);
    virtual ~BattleCard() override =default;
    void printInfo()const;
    virtual void  applyEncounter(Player& player) const override =0;
    bool fight(Player& player);
    virtual void applyDebuff(Player& player) const=0;


};


#endif //EX4_MAIN_BATTLECARD_H
