#ifndef CARDS_DRAWING_CHANCE_H
#define CARDS_DRAWING_CHANCE_H

#include "Card.h"
#include "../IO/Output.h"

///������ �����ƶࣩ
class Chance : public Card
{
public:
	Chance(std::string name, int val,int num) :Card(name, val,num) {}          //���캯������ʼ��Chance�����¼�����������ֵ
	virtual void doEvent() { Card::doEvent(); }
};

#endif