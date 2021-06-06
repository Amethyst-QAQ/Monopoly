#ifndef  CHANCE_1_H
#define CHANCE_1_H

#include "../Chance.h"
#include"../../Player/Player.h"

class Chance_1 :public Chance
{
public:
	Chance_1() :Chance("扫黄行动", 0, 0) {}     //构造函数，初始化Chance_1卡的事件名称、幸运值、编号
	void doEvent(Player& a)
	{
		Chance::doEvent();
	}
};

#endif // ! CHANCE_1_H
