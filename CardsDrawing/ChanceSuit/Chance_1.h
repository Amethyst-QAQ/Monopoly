#ifndef  CHANCE_1_H
#define CHANCE_1_H

#include "../Chance.h"
#include"../../Player/Person.h"

class Chance_1 :public Chance
{
public:
	Chance_1() :Chance("ɨ���ж�", 0, 0) {}     //���캯������ʼ��Chance_1�����¼����ơ�����ֵ�����
	void doEvent(Person& a)
	{
		
	}
};

#endif // ! CHANCE_1_H
