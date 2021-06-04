#ifndef GROUND_TRANSPORTATION_H
#define GROUND_TRANSPORTATION_H

#include<string>
#include "Ground.h"
#include "../Player/Person.h"

//收费站格子
class Transportation :public Ground
{
private:
	std::string name;                //收费站名称
	int toll;                        //基础过路费
	int dice;                        //骰子点数
public:
	Transportation(std::string _name, int _toll) :name(_name), toll(_toll), dice(0) {}

	void onStepped(Person& a)        //路过时调用
	{
		a.setMoney(a.getMoney() - toll * dice);
	}
	void setDice(int _dice) { dice = _dice; }
	std::string	getName() { return name; }
	int getToll() { return toll; }
};

#endif
