#ifndef FATE_1_H
#define FATE_1_H

#include"../Fate.h"
#include"../../Player/Player.h"

class Fate_1 :public Fate                   //���糧+1
{
public:
	Fate_1() :Fate("Ϊ������", 5) {}         //���캯������ʼ��Fate_1�����¼����ơ�����ֵ�����

	void doEvent(Player& a)
	{
		Fate::doEvent();
	}
};

#endif // !FATE_1_H
