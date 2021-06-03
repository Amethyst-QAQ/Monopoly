#include "CardsDrawing.h"

using namespace std;

//抽卡系统

void LuckVal(Person &a)          //计算幸运值，幸运值与抽到的卡片有关
{
	float luck= a.getLuck();
	luck = 1 - luck * 0.9;        //计算luck值
	                              //好卡坏卡交替出现
	a.setLuck(luck);              //更新Person的Luck值
}

Card* CardsDrawing(Person &a)
{
	srand((unsigned int)time(NULL));                //根据系统时间生成随机数
	if (a.getLuck() >= 0.6 && a.getLuck() <= 1)
	{
		int n = rand() % 8;								//输出一个0-8的随机数
		if (n == 4 || n == 5)	n = 3;
		if (n == 6 || n == 7) n = 4;
		if (n == 8) n = 5;
		int m = rand() % 3;//输出一个0-3的随机数
	}
}