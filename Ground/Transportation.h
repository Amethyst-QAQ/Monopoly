#ifndef GROUND_TRANSPORTATION_H
#define GROUND_TRANSPORTATION_H

#include<string>
#include "Ground.h"
#include "../Player/Person.h"

//�շ�վ����
class Transportation :public Ground
{
private:
	std::string name;                //�շ�վ����
	int toll;                        //������·��
	int dice;                        //���ӵ���
public:
	Transportation(std::string _name, int _toll) :name(_name), toll(_toll), dice(0) {}

	void onStepped(Person& a)        //·��ʱ����
	{
		a.setMoney(a.getMoney() - toll * dice);
	}
	void setDice(int _dice) { dice = _dice; }
	std::string	getName() { return name; }
	int getToll() { return toll; }
};

#endif
