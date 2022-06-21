#include "Player.h"

#include <utility>
#include "utilities.h"

#include "Fighter.h"
#include "Rogue.h"
#include "Wizard.h"

Player::Player(std::string name) :  m_name(name),
                                    m_HP(DEFAULT_HP),
                                    m_force(DEFAULT_FORCE),
                                    m_level(STARTING_LEVEL),
                                    m_coins(STARTING_COINS){}

Player::Player(const Player &player) = default;

std::ostream& operator<<(std::ostream& os,const Player& player){

    std::string player_class;
    try{
        player_class="Fighter";
        dynamic_cast<const Fighter&>(player);

    }
    catch (std::bad_cast){
        try{
            player_class="Rogue";
            dynamic_cast<const Rogue&>(player);
        }
        catch(std::bad_cast) {
            player_class="Wizard";
        }
    }


    printPlayerDetails(os,player.m_name,player_class,player.m_level,player.m_force,player.m_HP.getMHp(),player.m_coins);

    return std::cout;
}

void Player::levelUp()
{

    //assert(this->m_level < MAX_LEVEL);
    if (this->m_level < MAX_LEVEL)
        this->m_level++;

}

int Player::getLevel() const
{
    return this->m_level;
}

void Player::buff(int toAdd)
{
    if(m_force>=1)
        this->m_force += toAdd;
}

void Player::heal(int toHeal)
{
    if (toHeal > 0)
        this->m_HP+=toHeal;
}

void Player::damage(int toDamage)
{
    if (toDamage > 0)
        this->m_HP-=toDamage;
}

bool Player::isKnockedOut() const
{
    return (this->m_HP.getMHp() == 0);
}

void Player::addCoins(int toAdd)
{
    if (toAdd > 0)
        this->m_coins += toAdd;
}

bool Player::pay(int toPay)
{
    if (toPay > 0 && this->m_coins >= toPay)
    {
            this->m_coins -= toPay;
            return true;
    }

    if (toPay <= 0)
        return true;

    return false;
}

int Player::getAttackStrength() const
{
    return (this->m_force + this->m_level);
}

const std::string &Player::getName() const {
    return m_name;
}

int Player::getCoins() const {
    return m_coins;
}

int Player::getHP() const {
    return m_HP.getMHp();
}







