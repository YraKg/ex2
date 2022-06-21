#ifndef EX2_MAIN_PLAYER_H
#define EX2_MAIN_PLAYER_H

#include <string>
#include "memory"
#include "HealthPoints.h"

enum class type {PLAYER, FIGHTER, WIZARD, ROGUE};
class Card;

class Player {
    static const int DEFAULT_HP = 100;
    static const int DEFAULT_FORCE = 5;
    static const int STARTING_LEVEL = 1;
    static const int STARTING_COINS = 10;

protected:
    int m_force;
    int m_level;

public:
    int getCoins() const;

protected:
    int m_coins;

    HealthPoints m_HP;
    std::string m_name;

public:
    static const int MAX_LEVEL = 10;

    //Player(std::string name);
    explicit Player(std::string name);

    Player(const Player &player);


    /*
         * Telling the compiler to use the default destructor and operator=
    */
    virtual ~Player() = default;
    Player& operator=(const Player& other) = default;


    /*
         * Prints the player info
         *
         * @return
         *      void
    */
    virtual void printInfo() const = 0;


    /*
        * Levels up the player in case his level is less than MAX_LEVEL
        *
        * @return
        *      void
   */
    void levelUp();


    /*
        * Returns player's level
        *
        * @return
        *      level of the player
   */
    int getLevel() const;


    /*
        * Buffs player's force by the given param
        *
        * @param toAdd - amount of force to be increased by
        *
        * @return
        *      void
    */
    void buff(int toAdd);

    /*
      * Increases player's HP by the given param. Limited by player's MAX_HP
      *
      * @param toHeal -  amount of HP to be restored
      *
      * @return
      *      void
  */
    virtual void heal(int toHeal);


    /*
      * Decreases player's HP by the given param
      *
      * @param toDamage -  amount of HP to be increased
      *
      * @return
      *      void
   */
    void damage(int toDamage);


    /*
     * Increases player's coins amount by the given param
     *
     * @param toAdd -  amount of coins to be added
     *
     * @return
     *      void
  */
    virtual void addCoins(int toAdd);


    /*
      * Returns player's attack strength(level+force)
      *
      * @return
      *      Player's total strength(level+force)
   */
    virtual int getAttackStrength() const;


    /*
      * Returns if player is knocked out(hp==0)
      *
      * @return
      *      true in case player's hp == 0
      *      false in otherwise
   */
    bool isKnockedOut() const;


    /*
      * Decreases player's amount of coins by the given param
      *
      *   @param toPay - amount of coins to be decreased
      *
      * @return
      *      true in case player is able to pay the given amount
      *      false  otherwise
   */
    bool pay(int toPay);

    const std::string &getName() const;

    int getHP() const;

    void setMLevel(int mLevel);

    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    class CompareByHP {
    public:
        bool operator()(const std::shared_ptr<Player> p1, const std::shared_ptr<Player> p2) const
        {
            return p1->m_HP < p2->m_HP;
        }
    };

};


#endif //EX2_MAIN_PLAYER_H
