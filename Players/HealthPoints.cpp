#include "HealthPoints.h"

HealthPoints::HealthPoints(int max_HP) : m_HP(max_HP),
                                         m_maxHP(max_HP)
{
    if (max_HP <= 0)
        throw InvalidArgument();

}


void HealthPoints::operator+=(const int toAdd) {
    if(toAdd < 0){
        if(this->m_HP + toAdd > 0)
            this->m_HP += toAdd;
        else
            this->m_HP = 0;
    } else {
        if((this->m_HP + toAdd) < (this->m_maxHP))
            this->m_HP += toAdd;
        else
            this->m_HP = this->m_maxHP;
    }

}

void HealthPoints::operator-=(const int toDecrease) {
    if(toDecrease < 0){
        *this+=(-1*toDecrease);
    } else {
        if(this->m_HP - toDecrease > 0)
            this->m_HP -= toDecrease;
        else
            this->m_HP = 0;
    }
}


HealthPoints operator+(const int toAdd, const HealthPoints& hp) {
    HealthPoints result = hp;
    result += toAdd;
    return result;
}

HealthPoints operator+(const HealthPoints& hp, const int toAdd) {
    HealthPoints result = hp;
    result += toAdd;
    return result;
}

HealthPoints operator-(const HealthPoints& hp, const int toDecrease) {
    HealthPoints result = hp;
    result -= toDecrease;
    return result;
}

bool operator==(const HealthPoints& hp1, const HealthPoints& hp2) {
    return (hp1.m_HP == hp2.m_HP);
}

bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2) {
    return !(hp1 == hp2);
}

bool operator>(const HealthPoints& hp1, const HealthPoints& hp2) {
    return (hp1.m_HP > hp2.m_HP);
}

bool operator<(const HealthPoints& hp1, const HealthPoints& hp2) {
    return (!(hp1> hp2) && !(hp1 == hp2));
}

bool operator>=(const HealthPoints& hp1, const HealthPoints& hp2) {
    return (hp1>hp2 || hp1 == hp2);
}

bool operator<=(const HealthPoints& hp1, const HealthPoints& hp2) {
    return (hp1<hp2 || hp1 == hp2);
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& hp) {
    os << hp.m_HP << "(" << hp.m_maxHP << ")";
    return os;
}

int HealthPoints::getMHp() const {
    return m_HP;
}
