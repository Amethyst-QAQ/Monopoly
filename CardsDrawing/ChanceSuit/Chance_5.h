#ifndef CARDS_DRAWING_CHANCE_SUIT_CHANCE_5_H
#define CARDS_DRAWING_CHANCE_SUIT_CHANCE_5_H

#include "../Chance.h"
#include "../../Player/Player.h"

class Player;

class Chance_5 :public Chance
{
public:
	Chance_5() :Chance("С���ӹ���ͦ����(��ʧ800)", 3) {}
	void doEvent(Player* player) { player->setMoney(player->getMoney() - 800); }
};

#endif