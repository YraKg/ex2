#include "Mtmchkin.h"

#include "utilities.h"
#include "Exception.h"

#include "Barfight.h"
#include "Pitfall.h"
#include "Dragon.h"
#include "Fairy.h"
#include "Goblin.h"
#include "Merchant.h"
#include "Treasure.h"
#include "Vampire.h"
#include "Gang.h"

#include "Fighter.h"
#include "Rogue.h"
#include "Wizard.h"

#include <algorithm>

int initialize_team(){
    int team_size = 0;

    printEnterTeamSizeMessage();                //Team Size initialization
    cin >> team_size;

    while(team_size<2 || team_size>6){
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        cin >> team_size;
    }

    return team_size;
}

bool validClass(const std::string& cl){
    return cl == "Fighter" || cl == "Wizard" || cl == "Rogue";
}

bool validName(const std::string& name){
    if(name.length()>15 || name.empty())
        return false;
    else{
        for(char i:name){
            if(i<65 || i>122)
                return false;
        }
    }

    return true;
}

void initialize_player(vector<std::string> &current_player){
    std::string player_name;
    std::string player_class;

    printInsertPlayerMessage();
    std::cin >> player_name;
    std::cin >> player_class;


    while(!validName(player_name) || !validClass(player_class)){
        if(!validName(player_name)){
            printInvalidName();
            std::cin >> player_name;
            cin >> player_class;
        }else{
            printInvalidClass();
            std::cin >> player_name;
            cin >> player_class;
        }
    }

    current_player.push_back(player_name);
    current_player.push_back(player_class);
}

shared_ptr<BattleCard> initializeMonster(std::string current_card, int deque_size){
    if(current_card == "Dragon")
        return shared_ptr<Dragon>(new Dragon());
    else if(std::string(current_card) == "Goblin")
        return shared_ptr<Goblin>(new Goblin());
    else if(std::string(current_card) == "Vampire")
        return shared_ptr<Vampire>(new Vampire());
    else
        throw(DeckFileFormatError(deque_size+1));
}

Mtmchkin::Mtmchkin(const std::string& fileName): m_players(vector<std::shared_ptr<Player>>()),
                                                m_winners(vector<std::shared_ptr<Player>>()),
                                                m_losers(vector<std::shared_ptr<Player>>()),
                                                m_deque(deque<std::shared_ptr<Card>>()),
                                                m_rounds(0)
{
    //INITIALIZING M_DECK
    std::ifstream indata(fileName);

    if(!indata)
        throw(DeckFileNotFound());

    char current_card[256];

    while(indata.getline(current_card, sizeof(current_card))){
        if(std::string(current_card) == "Barfight")
            this->m_deque.push_back(shared_ptr<Barfight>(new Barfight()));
        else if(std::string(current_card) == "Pitfall")
            this->m_deque.push_back(shared_ptr<Pitfall>(new Pitfall()));
        else if(std::string(current_card) == "Dragon")
            this->m_deque.push_back(shared_ptr<Dragon>(new Dragon()));
        else if(std::string(current_card) == "Fairy")
            this->m_deque.push_back(shared_ptr<Fairy>(new Fairy()));
        else if(std::string(current_card) == "Goblin")
            this->m_deque.push_back(shared_ptr<Goblin>(new Goblin()));
        else if(std::string(current_card) == "Merchant")
            this->m_deque.push_back(shared_ptr<Merchant>(new Merchant()));
        else if(std::string(current_card) == "Treasure")
            this->m_deque.push_back(shared_ptr<Treasure>(new Treasure()));
        else if(std::string(current_card) == "Vampire")
            this->m_deque.push_back(shared_ptr<Vampire>(new Vampire()));
        else if(std::string(current_card) == "Gang")
        {
            vector<shared_ptr<BattleCard>> gang;
            while(indata.getline(current_card, sizeof(current_card))&&std::string(current_card) != "EndGang")
            {
                try
                {
                    gang.push_back(initializeMonster(current_card, this->m_deque.size()));
                }catch(DeckFileFormatError& e)
                {
                    throw(DeckFileFormatError(int(this->m_deque.size())+1));
                }
            }
            this->m_deque.push_back(shared_ptr<Gang>(new Gang(gang)));
        }

        else
            throw(DeckFileFormatError(int(this->m_deque.size())+1));
    }

    if(this->m_deque.size()<5)
        throw(DeckFileInvalidSize());

    //INITIALIZING M_PLAYERS
    printStartGameMessage();

    int team_size = initialize_team();

    for(int i = 0; i<team_size;i++){
        vector<std::string> current_player;
        initialize_player(current_player);

        if(current_player.back() == "Fighter")
            this->m_players.push_back( shared_ptr<Fighter>(new Fighter(current_player.front())));
        else if((current_player.back().compare("Rogue")) == 0)
            this->m_players.push_back( shared_ptr<Rogue>(new Rogue(current_player.front())));
        else if((current_player.back().compare("Wizard")) == 0)
            this->m_players.push_back( shared_ptr<Wizard>(new Wizard(current_player.front())));
    }
}



void Mtmchkin::playRound() {
    printRoundStartMessage(this->getNumberOfRounds()+1);
    for(const shared_ptr<Player>& player:this->m_players)
    {
        if(!this->isWinnerOrLoser(player))
        {
            printTurnStartMessage(player->getName());
            shared_ptr<Card> card=this->m_deque.front();
            this->m_deque.pop_front();
            this->m_deque.push_back(card);
            card->applyEncounter(*player);

            if(player->getLevel() == 10)
                this->m_winners.push_back(player);
            else if(player->getHP() == 0)
                this->m_losers.insert(this->m_losers.begin(), player);
        }
    }
    if(this->isGameOver())
    {
        printGameEndMessage();
        //printLeaderBoard();
    }
    this->m_rounds++;
}

bool Mtmchkin::isWinnerOrLoser(const std::shared_ptr<Player>& player) const {
    for(const shared_ptr<Player>& winner:this->m_winners){
        if(winner==player)
            return true;
    }
    for(const shared_ptr<Player>& loser:this->m_losers){
        if(loser==player)
            return true;
    }
    return false;
}

void Mtmchkin::printLeaderBoard() const{
    printLeaderBoardStartMessage();
    vector<shared_ptr<Player>> tmp;


    for(shared_ptr<Player> p: this->m_players){
        if(!this->isWinnerOrLoser(p)){
            tmp.push_back(p);
        }
    }

    //std::sort(tmp.begin(), tmp.end(), Player::CompareByHP());
    tmp.insert(tmp.begin(),this->m_winners.begin(), this->m_winners.end());
    tmp.insert(tmp.end(),this->m_losers.begin(), this->m_losers.end());

    int count = 1;

    for(shared_ptr<Player> p : tmp){
        printPlayerLeaderBoard(count, *p);
        count++;
    }

}

bool Mtmchkin::isGameOver() const {
    return this->m_players.size() == (this->m_winners.size() + this->m_losers.size());
}

int Mtmchkin::getNumberOfRounds() const {
    return this->m_rounds;
}

