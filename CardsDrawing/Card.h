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
	int num;

public:
	Card(std::string _name, 
		 int _val, 
		 int _num) : name(_name), 
					 val(_val), 
					 num(_num) {}

	int getVal() { return val; }
	std::string getName() { return name; }

	void show();
	virtual void doEvent() {};
}; 

#endif