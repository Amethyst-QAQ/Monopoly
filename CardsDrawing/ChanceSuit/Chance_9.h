#ifndef CARDS_DRAWING_CHANCE_SUIT_CHANCE_9_H
#define CARDS_DRAWING_CHANCE_SUIT_CHANCE_9_H

#include "../Chance.h"
#include "../../Player/Player.h"

//暂停3回合
class Player;

class Chance_9 :public Chance
{
public:
	Chance_9() :Chance("遵纪守法(损失500)", 3) {}
	void doEvent(Player* player) { player->setMoney(player->getMoney() - 500); }
};

#endif
