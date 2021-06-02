#include"Card.h"
int luck;

double Card::LuckVal()  //计算幸运值，幸运值与抽到的卡片有关
{
	luck = 1 - luck * 0.9;  //计算luck值
	//好卡坏卡交替出现
	return luck;
}