#ifndef FATE_H
#define FATE_H
#include"Fate.h"
#include<iostream>
#include "../Player/Person.h/"

class Fate_1 :public Fate                   //���糧+1
{
public:
	Fate_1() :Fate("Ϊ������", 5,0) {}         //���캯������ʼ��Fate_1�����¼����ơ�����ֵ�����

	void doEvent(Person& a)
	{
		std::cout << getName() << endl;
		a.buyPowerStation();
	}
};

#endif // !FATE_H