#ifndef CARDS_DRAWING_CARD_H
#define CARDS_DRAWING_CARD_H

#include "../Player/Output.h"

///卡片类

class Card
{
private:
	std::string name;	//存放事件名称
	int val;			//卡的等级,分为0~5共6个等级,数字越小越坏
	int num;			//卡在每个等级中的编号

public:
	Card(std::string _name, 
		 int _val, 
		 int _num) : name(_name), 
					 val(_val), 
					 num(_num) {}

	int getVal() { return val; }			//获得卡的幸运值
	int getNum() { return num; }			//获得卡的编号

	virtual void show();					//用于输出卡的信息
	virtual void doEvent() = 0;				//卡的执行操作，设为虚函数，需要子类重写
}; 

#endif