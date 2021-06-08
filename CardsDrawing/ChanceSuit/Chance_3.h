#ifndef CARDS_DRAWING_CHANCE_SUIT_CHANCE_3_H
#define CARDS_DRAWING_CHANCE_SUIT_CHANCE_3_H

#include "../Chance.h"
#include "../../Player/Player.h"

class Player;

class Chance_3 :public Chance
{
public:
	Chance_3() :Chance("出门记得戴眼镜", 1) {}
	void doEvent(Player* player) { player->setMoney(player->getMoney() - 500); }
};

#endif