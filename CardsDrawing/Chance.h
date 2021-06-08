#ifndef CARDS_DRAWING_CHANCE_H
#define CARDS_DRAWING_CHANCE_H

#include "Card.h"
#include "../IO/Output.h"

///机会类 （好牌多）
class Chance : public Card
{
public:
	Chance(std::string name, int val) :Card(name, val) {}          //构造函数，初始化Chance卡的事件名称与幸运值
	virtual void doEvent() { Card::doEvent(); }
};

#endif