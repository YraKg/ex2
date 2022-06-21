
#include "Card.h"
#include "BattleCard.h"
#include "utilities.h"

Card::Card(std::string name) :m_name(name)
{}
std::ostream& operator<<(std::ostream& os,const Card& card){
    printCardDetails(os,card.m_name);

    bool isBattleCard=true;

    try{
        const BattleCard& battleCard=dynamic_cast<const BattleCard&>(card);

    }
    catch(std::bad_cast)
    {
            isBattleCard= false;
    }
    if(isBattleCard)
    {
        dynamic_cast<const BattleCard&>(card).printInfo();
    }

    printEndOfCardDetails(os);

    return std::cout;
}
