#ifndef CARDS_DRAWING_CHANCE_SUIT_CHANCE_2_H
#define CARDS_DRAWING_CHANCE_SUIT_CHANCE_2_H

#include "../Chance.h"
#include "../../Player/Player.h"

class Player;

class Chance_2 :public Chance
{
public:
	Chance_2() : Chance("¿ÉÁ¯µÄÌæ×ïÑò(ËðÊ§2000Ôª)", 0) {}
	void doEvent(Player* player) { player->setMoney(player->getMoney() - 2000); }
};

#endif