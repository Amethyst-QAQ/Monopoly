#ifndef CARD_DRAWING_H
#define CARD_DRAWING_H

#include"../Player/Person.h"
#include "Card.h"
#include<iostream>
#include<ctime>

///�ƿ�ͳ鿨ϵͳ

class CardsDrawing
{
private:
	int m_val;   //�鵽���Ƶĵȼ�
	int m_num;   //�鵽���Ƶı��
public:
	void LuckVal(Person& a);
	Card* Draw(Person& a);
	void setVal(int num) { m_val = num; }  //����鵽���Ƶĵȼ�
	void setNum(int num) { m_num = num; }  //����鵽���Ƶı��
	int getVal() { return m_val; }         //��ȡ�鵽���Ƶĵȼ�
	int getNum() { return m_num; }         //��ȡ�鵽���Ƶı��
};

#endif