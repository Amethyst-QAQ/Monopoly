#ifndef GROUND_TRANSPORTATION_H
#define GROUND_TRANSPORTATION_H

#include<string>
#include "Ground.h"
#include "../Player/Person.h"

//�շ�վ����

class Transportation :public Ground
{
protected:
	int toll;                        //������·��
	int dice;                        //���ӵ���
public:
	Transportation() : toll(0), dice(0) {}

	void onStepped(int player)        //·��ʱ����
	{
		Ground::onStepped(player);
		
		a.setMoney(a.getMoney() - toll * dice);
	}
	void setDice(int _dice) { dice = _dice; }
	int getToll() { return toll; }
};

#endif
