#ifndef EX4_GANG_H
#define EX4_GANG_H

#include "Cards/BattleCard.h"
#include "vector"

class Gang: public Card{
    std::vector<std::shared_ptr<BattleCard>> m_gang;

public:
    explicit Gang(std::vector<std::shared_ptr<BattleCard>> gang);
    Gang(const Gang&)=default;
    Gang& operator=(const Gang&)=default;
    ~Gang() override =default;
    void  applyEncounter(Player& player) const override;

};


#endif //EX4_GANG_H
