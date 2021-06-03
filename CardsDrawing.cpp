#include"Person.h"

void LuckVal(Person &a)          //计算幸运值，幸运值与抽到的卡片有关
{
	float luck= a.getLuck();
	luck = 1 - luck * 0.9;        //计算luck值
	                              //好卡坏卡交替出现
	a.setLuck(luck);              //更新Person的Luck值
}