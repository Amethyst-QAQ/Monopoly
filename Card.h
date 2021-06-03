#ifndef CARD_H
#define CARD_H

#include<iostream>

//卡片类
class Card
{
private:
	std::string m_Eventname[10];  //存放事件名称
public:
	virtual void doEvent() = 0;  //事件操作
	float LuckVal();  //计算幸运值，幸运值与抽到的卡片有关
};

#endif
