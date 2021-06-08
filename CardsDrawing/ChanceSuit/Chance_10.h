#ifndef CARDS_DRAWING_CHANCE_SUIT_CHANCE_10_H
#define CARDS_DRAWING_CHANCE_SUIT_CHANCE_10_H

#include "../Chance.h"
#include "../../Player/Player.h"

class Player;

class Chance_10 :public Chance
{
public:
	Chance_10() :Chance("×¢ÒâËØÖÊ(ËðÊ§500)", 3) {}
	void doEvent(Player* player) { player->setMoney(player->getMoney() - 500); }
};

#endif
