#ifndef FATE_1_H
#define FATE_1_H

#include"../Fate.h"
#include"../../Player/Person.h"

class Fate_1 :public Fate                   //���糧+1
{
public:
	Fate_1() :Fate("Ϊ������", 5, 0) {}         //���캯������ʼ��Fate_1�����¼����ơ�����ֵ�����

	void doEvent(Person& a)
	{
		std::cout << getName() << std::endl;
		a.buyPowerStation();
	}
	void Show()
	{
		std::cout << getName() << std::endl;
	}
};

#endif // !FATE_1_H
