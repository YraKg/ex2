#include "Mtmchkin.h"
#include "Exception.h"

int main( int argc, char** args){

    if(argc < 2)
    {
        return 0;
    }

    try{
        Mtmchkin game= Mtmchkin(string(args[1]));
        while(!game.isGameOver()){
            game.playRound();
            game.printLeaderBoard();
        }
    } catch(exception& e){
        std::cout<<e.what()<<endl;
        return 0;
    }

    return 1;

}