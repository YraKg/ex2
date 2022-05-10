#include <cassert>
#include "Mtmchkin.h"
#include "Card.h"
#include "Player.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards):
    m_cardArray(cardsArray),
    m_game_status(GameStatus::MidGame),
    m_numCards(numOfCards),
    m_curr_card(0)
{
    m_player=new Player(playerName);
}

Mtmchkin::~Mtmchkin()
{

}

bool Mtmchkin::isOver()
{
    if(this->m_game_status!=GameStatus::MidGame)
        return true;
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