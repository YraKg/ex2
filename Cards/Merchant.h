//
// Created by User on 08.06.2022.
//

#ifndef EX4_MAIN_MERCHANT_H
#define EX4_MAIN_MERCHANT_H

#include "Card.h"

enum class Shop_choices {Leave,Heal,Force_Buff,end_of_enum};

class Merchant: public Card{
    static const int BUFF_PAYMENT=10;
    static const int HEAL_PAYMENT=5;
public:
    Merchant();
    Merchant(const Merchant&)=default;
    Merchant& operator=(const Merchant&)=default;
    ~Merchant() override =default;
    void applyEncounter(Player& player) const override;
};


#endif //EX4_MAIN_MERCHANT_H
