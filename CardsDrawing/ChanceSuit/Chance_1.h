#ifndef CARDS_DRAWING_CHANCE_SUIT_CHANCE_1_H
#define CARDS_DRAWING_CHANCE_SUIT_CHANCE_1_H

#include "../Chance.h"
#include"../../Player/Player.h"

class Player;

class Chance_1 :public Chance
{
public:
	Chance_1() : Chance("Poor child!(Lose 2000 yuan)", 2) {}
	void doEvent(Player* player) { player->setMoney(player->getMoney() - 2000); }
};

#endif // ! CHANCE_1_H
