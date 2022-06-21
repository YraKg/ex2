//
// Created by User on 08.06.2022.
//

#ifndef EX4_MAIN_CARD_H
#define EX4_MAIN_CARD_H

#include "string"
#include "Players/Player.h"

class Card {

protected:
    std::string m_name;


public:
    //Card& operator=(const Card& )=delete;
    explicit Card(std::string name);
    virtual ~Card()=default;
    virtual void  applyEncounter(Player& player) const=0;

    friend std::ostream& operator<<(std::ostream& os,const Card& card);
};


#endif //EX4_MAIN_CARD_H
