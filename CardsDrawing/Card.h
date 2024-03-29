#ifndef CARDS_DRAWING_CARD_H
#define CARDS_DRAWING_CARD_H

#include "../IO/Output.h"

/**
* @brief 卡片类
* doEvent()函数用于执行卡片内容，需要在子类中重载
*/
class Card
{
private:
	std::string name;
	int val;

public:
	Card(std::string _name, 
		 int _val): 
		name(_name), 
		val(_val) {}

	int getVal() { return val; }
	std::string getName() { return name; }

	void show();
	virtual void doEvent() {};
}; 

#endif