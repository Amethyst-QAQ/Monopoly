#ifndef GROUND_BEGINNING_H
#define GROUND_BEGINNING_H

#include "Ground.h"
#include "../Player/Player.h"

//起点格子
class Beginning :public Ground
{
public:
	void onPassed(Player& a)
	{
		a.setMoney(a.getMoney() + 2000);
	}
	void onLeaved(Player& a)                   //离开起点时调用
	{
		a.setMoney(a.getMoney() + 2000);
	}
};

#endif
