#include <cassert>
#include "Mtmchkin.h"
#include "Card.h"
#include "Player.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards):
    m_game_status(GameStatus::MidGame),
    m_numCards(numOfCards),
    m_curr_card(0)
{
    this->m_player=new Player(playerName);
    this->m_cardArray=new Card[numOfCards];
    for(int i=0;i<numOfCards;i++)
       this->m_cardArray[i]=cardsArray[i];
}

Mtmchkin::~Mtmchkin()
{
    delete this->m_player;
    delete this->m_cardArray;
}



bool Mtmchkin::isOver()
{
    if(this->m_player->getLevel()==Player::MAX_LEVEL)
    {
        this->m_game_status=GameStatus::Win;
        return true;
    }
    else if(this->m_player->isKnockedOut())
    {
        this->m_game_status=GameStatus::Loss;
    }
    return false;
}

GameStatus Mtmchkin::getGameStatus() const
{
    return this->m_game_status;
}

void Mtmchkin::playNextCard()
{
    this->m_cardArray[m_curr_card].printInfo();
    this->m_cardArray[m_curr_card].applyEncounter(*(this->m_player));
    this->m_player->printInfo();
    this->m_curr_card=(this->m_curr_card+1)%this->m_numCards;

}