#pragma once
#include"Card.h"

//机会类  好的多
class Chance :public Card
{
public:
	Chance();  //构造函数，初始化事件名称
	void Func();  //事件具体操作
};