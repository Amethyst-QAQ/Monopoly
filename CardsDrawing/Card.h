#ifndef CARDS_DRAWING_CARD_H
#define CARDS_DRAWING_CARD_H

#include "../IO/Output.h"

/**
* @brief ��Ƭ��
* doEvent()��������ִ�п�Ƭ���ݣ���Ҫ������������
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