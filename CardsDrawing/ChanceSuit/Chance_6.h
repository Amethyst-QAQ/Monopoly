#ifndef CARDS_DRAWING_CHANCE_SUIT_CHANCE_6_H
#define CARDS_DRAWING_CHANCE_SUIT_CHANCE_6_H

#include "../Chance.h"
#include "../../Player/Player.h"

class Player;

class Chance_6 :public Chance
{
public:
	Chance_6() :Chance("Ñø¶ù·ÀÀÏ(ËðÊ§500)", 3) {}
	void doEvent(Player* player) { player->setMoney(player->getMoney() - 500); }
};

#endif
