
#include "Merchant.h"
#include "Players/Player.h"
#include "utilities.h"
Merchant::Merchant():
        Card("Merchant")
{}

void Merchant::applyEncounter(Player &player) const {


  printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getCoins());

  int choice;
  std::string saveline;
  try
  {
      std::getline(std::cin,saveline);
      choice=stoi(saveline);
  }catch(std::invalid_argument& e)
  {
      throw e;
  }


  while(choice>=int(Shop_choices::end_of_enum) || choice<0)
  {
      printInvalidInput();
      std::cin>>choice;
  }

  bool successful_buy;
  int cost=0;

  switch((Shop_choices)choice)
    {
        default:
            break;
        case Shop_choices::Force_Buff:

            successful_buy=player.pay(10);
            if(successful_buy)
            {
                player.buff(1);
                cost=10;
            }

            else
            {
                printMerchantInsufficientCoins(std::cout);
            }

            break;
        case Shop_choices::Heal:
            successful_buy=player.pay(5);
            if(successful_buy)

            {
                player.heal(1);
                cost=5;
            }

            else
            {
                printMerchantInsufficientCoins(std::cout);
            }
            break;
    }

    printMerchantSummary(std::cout,player.getName(),choice,cost);
}