#ifndef GROUND_BEGINNING_H
#define GROUND_BEGINNING_H

#include "Ground.h"
#include "../Player/Player.h"

extern Player* players;
//������

class Beginning :public Ground
{
public:
	void onPassed(int player)
	{
		Ground::onPassed(player);
		Player& p = players[player];
		p.setMoney(p.getMoney() + 2000);
	}

	void onLeft(int player)                   //�뿪���ʱ����
	{
		Player& p = players[player];
		p.setMoney(p.getMoney() + 2000);
	}
};

#endif
