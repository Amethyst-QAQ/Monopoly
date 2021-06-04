#ifndef CARD_DRAWING_H
#define CARD_DRAWING_H

#include"../Player/Person.h"
#include "Card.h"
#include<iostream>
#include<ctime>

//牌库和抽卡系统

class CardsDrawing
{
private:
	//此处应有牌
public:
	void LuckVal(Person& a);
	Card* Draw(Person& a);
};

#endif