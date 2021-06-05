#ifndef GROUND_BEGINNING_H
#define GROUND_BEGINNING_H

#include "Ground.h"
#include "../Player/Player.h"

//������
class Beginning :public Ground
{
public:
	void onPassed(Player& a)
	{
		a.setMoney(a.getMoney() + 2000);
	}
	void onLeaved(Player& a)                   //�뿪���ʱ����
	{
		a.setMoney(a.getMoney() + 2000);
	}
};

#endif
