#include "Player.h"
Player::Player(const char * name, int HP, int force)
{
    if(HP<=0)
        HP = DEFAULT_HP;

    if(force > 10 || force<0)
        force = DEFAULT_FORCE;

    this->m_name = name;
    this->m_HP = HP;
    this->m_maxHP = HP;
    this->m_force = force;

    m_level = STARTING_LEVEL;
    m_coins = STARTING_COINS;
}

Player::Player(const char * name, int HP)
{
    if(HP<=0)
        HP = DEFAULT_HP;

    this->m_name = name;
    this->m_HP = HP;
    this->m_maxHP = HP;

    m_force = DEFAULT_FORCE;
    m_level = STARTING_LEVEL;
    m_coins = STARTING_COINS;
}

Player::Player(const char * name)
{
    this->m_name = name;

    m_HP = DEFAULT_HP;
    m_maxHP = DEFAULT_HP;
    m_force = DEFAULT_FORCE;
    m_level = STARTING_LEVEL;
    m_coins = STARTING_COINS;
}

void Player::printInfo() const
{
    printPlayerInfo(this->m_name, this->m_level, this->m_force, this->m_HP, this->m_coins);
}

void Player::levelUp()
{
    if(!(this->m_level>=MAX_LEVEL))
        this->m_level++;
}

int Player::getLevel() const
{
    return this->m_level;
}

void Player::buff(int toAdd)
{
    if(toAdd > 0)
        this->m_force+=toAdd;
}

void Player::heal(int toHeal)
{
    if(toHeal > 0){
        if(this->m_HP + toHeal > this->m_maxHP)
            this->m_HP = this->m_maxHP;
        else
            this->m_HP+=toHeal;
    }
}

void Player::damage(int toDamage)
{
    if(toDamage > 0){
        if(this->m_HP - toDamage < 0)
            this->m_HP = 0;
        else
            this->m_HP -= toDamage;
    }
}

bool Player::isKnockedOut() const
{
    return (this->m_HP == 0);
}

void Player::addCoins(int toAdd)
{
    if(toAdd > 0)
        this->m_coins+=toAdd;
}

bool Player::pay(int toPay)
{
    if(toPay > 0){
        if(this->m_coins >= toPay){
            this->m_coins-=toPay;
            return true;
        }
    }

    return false;
}

int Player::getAttackStrength() const
{
    return (this->m_force + this->m_level);
}


