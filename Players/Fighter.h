#ifndef EX4_MAIN_FIGHTER_H
#define EX4_MAIN_FIGHTER_H

#include "Player.h"

class Fighter: public Player {
public:
    Fighter(std::string name);

    ~Fighter() = default;
    Fighter& operator=(const Fighter& other) = default;

    int getAttackStrength() const override;
    void printInfo() const override;
};

#endif //EX4_MAIN_FIGHTER_H
