#ifndef EX3_HEALTHPOINTS_H
#define EX3_HEALTHPOINTS_H

#include <string>
#include <fstream>
//#include <exception>
#include <iostream>


class HealthPoints {
    static const int DEFAULT_HP = 100;
private:
    int m_HP;
    int m_maxHP;

    friend bool operator==(const HealthPoints& hp1, const HealthPoints& hp2);
    friend bool operator>(const HealthPoints& hp1, const HealthPoints& hp2);

    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& hp);

public:

    class InvalidArgument {};

    explicit HealthPoints(int max_HP=DEFAULT_HP);
    ~HealthPoints() = default;

    void operator+=(int num);
    void operator-=(int num);

    int getMHp() const;
};

HealthPoints operator+(const HealthPoints& hp, const int toDecrease);
HealthPoints operator+(const int toDecrease, const HealthPoints& hp);
HealthPoints operator-(const HealthPoints& hp, const int toDecrease);

bool operator==(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator>(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator<(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator>=(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator<=(const HealthPoints& hp1, const HealthPoints& hp2);

std::ostream& operator<<(std::ostream& os, const HealthPoints& hp);

#endif //EX3_HEALTHPOINTS_H
