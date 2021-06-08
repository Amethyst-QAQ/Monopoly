#ifndef CARDS_DRAWING_CHANCE_SUIT_CHANCE_4_H
#define CARDS_DRAWING_CHANCE_SUIT_CHANCE_4_H

#include "../Chance.h"
#include "../../Player/Player.h"

class Player;

class Chance_4 :public Chance
{
public:
	Chance_4() :Chance("记得学会垃圾分类(损失1000)", 2) {}
	void doEvent(Player* player) { player->setMoney(player->getMoney() - 1000); }
};

#endif