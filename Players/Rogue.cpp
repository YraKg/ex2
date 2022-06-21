#include "Rogue.h"
#include "utilities.h"

Rogue::Rogue(std::string name) :  Player(name){}

void Rogue::printInfo() const
{
    std::string job = "Rogue";
    printPlayerDetails(std::cout, this->m_name, job, this->m_level, this->m_force, this->m_HP.getMHp(),this->m_coins);
}

void Rogue::addCoins(int toAdd)
{
    if (toAdd > 0)
        this->m_coins += 2*toAdd;
}