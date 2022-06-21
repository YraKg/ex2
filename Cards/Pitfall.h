
#ifndef EX4_MAIN_PITFALL_H
#define EX4_MAIN_PITFALL_H

#include "Card.h"

class Pitfall: public Card{
    static const int DAMAGE_ON_FALL=10;
public:
    Pitfall();
    Pitfall(const Pitfall&)=default;
    Pitfall& operator=(const Pitfall&)=default;
    ~Pitfall() override =default;
    void applyEncounter(Player& player) const override;
};


#endif //EX4_MAIN_PITFALL_H
