
#ifndef EX2_MAIN_PLAYER_H
#define EX2_MAIN_PLAYER_H

#include <string>
#include "utilities.h"

class Player {
    static const int DEFAULT_HP = 100;
    static const int DEFAULT_FORCE = 5;
    static const int MAX_LEVEL = 10;
    static const int STARTING_LEVEL = 1;
    static const int STARTING_COINS = 0;
private:
    const char *m_name;//TODO maybe string??
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

public:


    /*
         * C'tor of Player class
         *
         * @param name - The name of the player
         * @param HP - The HP of the player at the start
         * @param force - The force of the player at the start
    */
    Player(const char * name, int HP, int force);


    /*
        * C'tor of Player class
        *
        * @param name - The name of the player
        * @param HP - The HP of the player at the start
   */
    Player(const char * name, int HP);


    /*
          * C'tor of Player class
          *
          * @param name - The name of the player
     */
    Player(const char * name);


    /*
         * Telling the compiler to use the default destructor and operator=
    */
    ~Player() = default;
    Player& operator=(const Player& other) = default;


    /*
         * Prints the player info
         *
         * @return
         *      void
    */
    void printInfo() const;


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
    void heal(int toHeal);


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
    void addCoins(int toAdd);


    /*
      * Returns player's attack strength(level+force)
      *
      * @return
      *      Player's total strength(level+force)
   */
    int getAttackStrength() const;


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
};

#endif //EX2_MAIN_PLAYER_H
