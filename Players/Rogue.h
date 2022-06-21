#ifndef EX4_MAIN_ROGUE_H
#define EX4_MAIN_ROGUE_H

#include "Player.h"

class Rogue: public Player {

public:
    Rogue(std::string name);

    ~Rogue() = default;
    Rogue& operator=(const Rogue& other) = default;

    void addCoins(int toAdd) override;
    void printInfo() const override;
};

#endif //EX4_MAIN_ROGUE_H
