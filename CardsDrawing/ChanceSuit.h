#ifndef CHANCESUIT_H
#define CHANCESUIT_H

#include"Chance.h"
#include<iostream>
#include "../Player/Person.h/"

class Chance_1 :public Chance                       
{
public:
	Chance_1() :Chance("ɨ���ж�", 0,0) {}     //���캯������ʼ��Chance_1�����¼����ơ�����ֵ�����
	void doEvent(Person& a)
	{
		
	}
};

#endif // !CHANCESUIT_H

