#include"Card.h"
int luck;

Card::Card(std::string _event, int _val)
{
	event = _event;
	val = _val;
}

double Card::LuckVal()  //计算幸运值，幸运值与抽到的卡片有关
{
	luck = 1 - luck * 0.9;  //计算luck值
	//好卡坏卡交替出现
	return luck;
}