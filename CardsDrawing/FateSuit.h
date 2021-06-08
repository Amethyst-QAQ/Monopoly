#ifndef CARDS_DRAWING_FATE_SUIT_H
#define CARDS_DRAWING_FATE_SUIT_H

#include <list>
#include "Fate.h"
#include "CardsSuit.h"
#include "../Player/Player.h"

//命运牌库
class FateSuit : public CardsSuit
{
private:
	Fate* card;
	std::list<Fate> suit;

public:
	static Output* instance;
	void show ();				//输出牌库
	Fate* draw(Player* player);		//抽卡函数
	void add(Fate* ChanceCard) { suit.push_back(*card); }	//向牌库中添加牌
};

#endif // !CARDSDRAWING_FATESUIT_H