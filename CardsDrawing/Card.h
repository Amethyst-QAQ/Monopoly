#ifndef CARD_H
#define CARD_H

#include<iostream>
#include<string>

//卡片类
class Card
{
private:
	std::string event;				            //存放事件名称
	int val;						            //卡的好坏,分为6个等级

public:
	Card(std::string _event, int _val,int _num) : event(_event), val(_val) {}
	virtual void doEvent() {}					//事件操作名称
};

#endif
