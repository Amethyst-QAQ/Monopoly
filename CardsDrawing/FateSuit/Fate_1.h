#ifndef FATE_1_H
#define FATE_1_H

#include"../Fate.h"
#include"../../Player/Player.h"

class Fate_1 :public Fate                   //发电厂+1
{
public:
	Fate_1() :Fate("为爱发电", 5) {}         //构造函数，初始化Fate_1卡的事件名称、幸运值、编号

	void doEvent(Player& a)
	{
		Fate::doEvent();
	}
};

#endif // !FATE_1_H
