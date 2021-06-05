#ifndef GROUND_TRANSPORTATION_H
#define GROUND_TRANSPORTATION_H

#include<string>
#include "Ground.h"
#include "../Player/Person.h"

//收费站格子

class Transportation :public Ground
{
protected:
	int toll;                        //基础过路费
	int dice;                        //骰子点数
public:
	Transportation() : toll(0), dice(0) {}

	void onStepped(int player)        //路过时调用
	{
		Ground::onStepped(player);
		
		a.setMoney(a.getMoney() - toll * dice);
	}
	void setDice(int _dice) { dice = _dice; }
	int getToll() { return toll; }
};

#endif
