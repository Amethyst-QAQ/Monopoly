#ifndef CHANCE_H
#define CHANCE_H

#include"Card.h"

//机会类 （好的多）
class Chance :public Card
{
public:
	Chance(std::string _name, int _val) { Card(_name, _val); };  //构造函数，初始化事件名称
};

#endif