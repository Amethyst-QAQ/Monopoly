#ifndef CARDS_DRAWING_FATE_H
#define CARDS_DRAWING_FATE_H

#include"Card.h"

//命运类  （坏牌多）
class Fate :public Card
{
public:
	Fate(std::string _name, int _val,int _num) :Card(_name, _val,_num) {}  	//构造函数，初始化事件名称，设置这张卡的幸运值
};

#endif // !FATE_H