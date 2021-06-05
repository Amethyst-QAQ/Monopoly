#ifndef CARDS_DRWING_CHANCE_SUIT_H
#define CARDS_DRWING_CHANCE_SUIT_H

#include <set>
#include"Chance.h"
#include"CardsSuit.h"
#include "../Player/Person.h"

extern Person* players;

///机会牌库
class ChanceSuit : public CardsSuit, public Chance
{
private:
	Chance* card;
	std::set<Chance> suit;

public:
	void show ();					//输出牌库
	Chance* draw(int player);		//抽卡函数

	void add(Chance* ChanceCard) { suit.insert(*card); }	//向牌库中添加牌
};

#endif // !CARDSDRWING_CHANCESUIT_H

