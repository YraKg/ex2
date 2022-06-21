#include "Fighter.h"
#include "utilities.h"

Fighter::Fighter(std::string name) :  Player(name){}

void Fighter::printInfo() const
{
    std::string job = "Fighter";
    printPlayerDetails(std::cout, this->m_name, job, this->m_level, this->m_force, this->m_HP.getMHp(),this->m_coins);
}

int Fighter::getAttackStrength() const
{
    return (2*this->m_force + this->m_level);
}


