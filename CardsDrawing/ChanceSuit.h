#ifndef CARDS_DRWING_CHANCE_SUIT_H
#define CARDS_DRWING_CHANCE_SUIT_H

#include <list>
#include"Chance.h"
#include"CardsSuit.h"
#include "../Player/Player.h"

/**
* @brief 机会牌库类，用于机会格子抽卡和输出牌库信息
* draw()函数用于抽卡，可以根据玩家的幸运值进行自动抽卡并执行相关操作
* show()函数用于输出牌库中含有的牌数和每张牌的信息
* add()函数用于向牌库中添加牌
*/

class ChanceSuit : public CardsSuit
{
private:
	std::list<Chance> suit;
public:
	static Output* instance;

	void show ();						
	void draw(Player* player);
	void add(Chance* ChanceCard) { suit.push_back(*ChanceCard); }
};

#endif // !CARDSDRWING_CHANCESUIT_H