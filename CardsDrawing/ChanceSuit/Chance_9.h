#ifndef CARDS_DRAWING_CHANCE_SUIT_CHANCE_9_H
#define CARDS_DRAWING_CHANCE_SUIT_CHANCE_9_H

#include "../Chance.h"
#include "../../Player/Player.h"

//��ͣ3�غ�
class Player;

class Chance_9 :public Chance
{
public:
	Chance_9() :Chance("����ط�(��ʧ500)", 3) {}
	void doEvent(Player* player) { player->setMoney(player->getMoney() - 500); }
};

#endif
