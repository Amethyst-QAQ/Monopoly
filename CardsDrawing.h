#ifndef CARD_DRAWING_H
#define CARD_DRAWING_H

#include"Person.h"
#include "Card.h"
#include<iostream>
#include<ctime>

//�ƿ�ͳ鿨ϵͳ

class CardsDrawing
{
private:
	//�˴�Ӧ����
public:
	void LuckVal(Person& a);
	Card* Draw(Person& a);
};

#endif