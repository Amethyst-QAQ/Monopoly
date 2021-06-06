#ifndef CARDS_DRWING_CHANCE_SUIT_H
#define CARDS_DRWING_CHANCE_SUIT_H

#include <list>
#include"Chance.h"
#include"CardsSuit.h"
#include "../Player/Player.h"

extern Player* players;

///机会牌库
class ChanceSuit : public CardsSuit, public Chance
{
private:
	std::set<Chance> suit;
	Chance* card;
	std::list<Chance> suit;

public:
	void show ();					//输出牌库
	Chance* draw(int player);		//抽卡函数

	void add(Chance* ChanceCard) { suit.push_back(*card); }	//向牌库中添加牌
};

#endif // !CARDSDRWING_CHANCESUIT_H

