#ifndef CARDS_DRAWING_FATE_SUIT_H
#define CARDS_DRAWING_FATE_SUIT_H

#include <set>
#include "Fate.h"
#include "CardsSuit.h"
#include "../Player/Person.h/"

extern Person* players;

//命运牌库
class FateSuit : public CardsSuit, public Fate
{
private:
	Fate* card;
	std::set<Fate> suit;

public:
	void show ();				//输出牌库
	Fate* draw(int player);		//抽卡函数

	void add(Fate* ChanceCard) { suit.insert(*card); }	//向牌库中添加牌
};

#endif // !CARDSDRAWING_FATESUIT_H