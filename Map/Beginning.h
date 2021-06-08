#ifndef GROUND_BEGINNING_H
#define GROUND_BEGINNING_H

#include "Ground.h"
#include "../Player/Player.h"

extern Player* players;
//起点格子

class Beginning :public Ground
{
public:
	void onPassed(int player)
	{
		Ground::onPassed(player);
		Player& p = players[player];
		p.setMoney(p.getMoney() + 2000);
	}

	void onLeft(int player)                   //离开起点时调用
	{
		Player& p = players[player];
		p.setMoney(p.getMoney() + 2000);
	}
};

#endif
