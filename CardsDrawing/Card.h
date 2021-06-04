#ifndef CARDS_DRAWING_CARD_H
#define CARDS_DRAWING_CARD_H

#include<iostream>
#include<string>

///卡片类
class Card
{
private:
	std::string m_name;				                           //存放事件名称
	int m_val;					  	                           //卡的好坏,分为0~5共6个等级,数字越小越坏

public:
	Card(std::string name,int val):m_name(name),m_val(val){}   //构造函数，初始化卡的事件名称与幸运值
	
	std::string getName() { return m_name; }                   //获得卡的名称
	int getVal() { return m_val; }                             //获得卡的幸运值
	
	virtual void doEvent() {};                                 //卡的执行操作，设为虚函数，需要子类重写
}; 

#endif
