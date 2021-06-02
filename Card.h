#pragma once
#include<iostream>  

//卡片类
class Card
{
protected:
	std::string m_Eventname[10];  //存放事件名称
public:
	virtual void doEvent();  //事件操作
	double LuckVal();  //计算幸运值，幸运值与抽到的卡片有关
};