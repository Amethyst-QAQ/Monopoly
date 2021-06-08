#ifndef CARDS_DRWING_CHANCE_SUIT_H
#define CARDS_DRWING_CHANCE_SUIT_H

#include <list>
#include"Chance.h"
#include"CardsSuit.h"
#include "../Player/Player.h"

///机会牌库
class ChanceSuit : public CardsSuit
{
private:
	std::list<Chance> suit;

public:
	static Output* instance;

	void show ();						//输出牌库
	Chance* draw(Player* player);		//抽卡函数
	void add(Chance* ChanceCard) { suit.push_back(*ChanceCard); }	//向牌库中添加牌
};

#endif // !CARDSDRWING_CHANCESUIT_H