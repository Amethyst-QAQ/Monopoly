#ifndef FATE_H
#define FATE_H

#include"Card.h"

//命运类  （坏牌多）
class Fate :public Card
{
public:
	Fate(std::string _name, int _val) : Card (_name, _val) {}  	//构造函数，初始化事件名称，设置这张卡的幸运值
};

#endif // !FATE_H