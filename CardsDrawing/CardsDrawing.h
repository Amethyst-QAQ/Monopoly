#ifndef CARD_DRAWING_H
#define CARD_DRAWING_H

#include"../Player/Person.h"
#include "Card.h"
#include<iostream>
#include<ctime>

///牌库和抽卡系统

class CardsDrawing
{
private:
	int m_val;   //抽到的牌的等级
	int m_num;   //抽到的牌的编号
public:
	void LuckVal(Person& a);
	Card* Draw(Person& a);
	void setVal(int num) { m_val = num; }  //输入抽到的牌的等级
	void setNum(int num) { m_num = num; }  //输入抽到的牌的编号
	int getVal() { return m_val; }         //获取抽到的牌的等级
	int getNum() { return m_num; }         //获取抽到的牌的编号
};

#endif