#ifndef CARDS_DRAWING_CHANCE_SUIT_CHANCE_2_H
#define CARDS_DRAWING_CHANCE_SUIT_CHANCE_2_H

#include "../Chance.h"
#include "../../Player/Player.h"

class Player;

class Chance_2 :public Chance
{
public:
	Chance_2() : Chance("һ��������˾����(��ʧ800Ԫ)", 3) {}
	void doEvent(Player* player) { player->setMoney(player->getMoney() - 800); }
};

#endif