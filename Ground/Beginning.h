#ifndef GROUND_BEGINNING_H
#define GROUND_BEGINNING_H

#include "Ground.h"
#include "../Player/Person.h"

//������
class Beginning :public Ground
{
public:
	void onPassed(Person& a)
	{
		a.setMoney(a.getMoney() + 2000);
	}
	void onLeaved(Person& a)                   //�뿪���ʱ����
	{
		a.setMoney(a.getMoney() + 2000);
	}
};

#endif
