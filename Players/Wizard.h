#ifndef EX4_MAIN_WIZARD_H
#define EX4_MAIN_WIZARD_H

#include "Player.h"


class Wizard: public Player {
public:
    Wizard(std::string name);

    ~Wizard() = default;
    Wizard& operator=(const Wizard& other) = default;

    void heal(int toHeal) override;
    void printInfo() const override;
};


#endif //EX4_MAIN_WIZARD_H
