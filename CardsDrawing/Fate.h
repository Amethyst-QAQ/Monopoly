#ifndef CARDS_DRAWING_FATE_H
#define CARDS_DRAWING_FATE_H

#include"Card.h"

///命运类  （坏牌多）
class Fate :public Card
{
public:
	Fate(std::string name, int val,int num) :Card(name, val,num) {}          //构造函数，初始化Fate卡的事件名称与幸运值
};

#endif // !FATE_H