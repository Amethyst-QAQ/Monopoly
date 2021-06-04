#ifndef CARD_DRAWING_H
#define CARD_DRAWING_H

#include"../Player/Person.h"
#include "Card.h"
#include<iostream>
#include<ctime>

///�ƿ�ͳ鿨ϵͳ

class CardsDrawing
{
public:
	void LuckVal(Person& a);
	Card* Draw(Person& a);
};

#endif