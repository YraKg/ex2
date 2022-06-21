#include "Wizard.h"
#include "utilities.h"

Wizard::Wizard(std::string name) :  Player(name){}

void Wizard::printInfo() const
{
    std::string job = "Wizard";
    printPlayerDetails(std::cout, this->m_name, job, this->m_level, this->m_force, this->m_HP.getMHp(),this->m_coins);
}

void Wizard::heal(int toHeal) {
    if (toHeal > 0)
        this->m_HP += 2*toHeal;
}



