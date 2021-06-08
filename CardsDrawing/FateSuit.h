#ifndef CARDS_DRAWING_FATE_SUIT_H
#define CARDS_DRAWING_FATE_SUIT_H

#include <list>
#include "Fate.h"
#include "CardsSuit.h"
#include "../Player/Player.h"

/**
* @brief 命运牌库类，用于命运格子抽卡和输出牌库信息
* draw()函数用于抽卡，可以根据玩家的幸运值进行自动抽卡并执行相关操作
* show()函数用于输出牌库中含有的牌数和每张牌的信息
* add()函数用于向牌库中添加牌
*/

class FateSuit : public CardsSuit
{
private:
	std::list<Fate> suit;

public:
	static Output* instance;
	void show ();
	void draw(Player* player);
	void add(Fate* ChanceCard) { suit.push_back(*ChanceCard); }
};

#endif // !CARDSDRAWING_FATESUIT_H