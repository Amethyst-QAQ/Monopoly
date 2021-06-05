#ifndef FATE_H
#define FATE_H
#include"Fate.h"
#include<iostream>
#include "../Player/Person.h/"

class Fate_1 :public Fate                   //发电厂+1
{
public:
	Fate_1() :Fate("为爱发电", 5,0) {}         //构造函数，初始化Fate_1卡的事件名称、幸运值、编号

	void doEvent(Person& a)
	{
		std::cout << getName() << endl;
		a.buyPowerStation();
	}
};

#endif // !FATE_H