#include"Person.h"
#include<iostream>
#include<ctime>
using namespace std;

//抽卡系统

void LuckVal(Person &a)          //计算幸运值，幸运值与抽到的卡片有关
{
	float luck= a.getLuck();
	luck = 1 - luck * 0.9;        //计算luck值
	                              //好卡坏卡交替出现
	a.setLuck(luck);              //更新Person的Luck值
}

float CardsDrawing(Person &a)
{
	srand((unsigned int)time(NULL));                //根据系统时间生成随机数
	if (a.getLuck() >= 0.65 && a.getLuck() <= 1)    //好卡
	{
		//Chance中：好卡7张，坏卡3张
		//Fate中：好卡3张，坏卡7张
		if()
		cout << "The number of the card you draw is " << 1 + rand() % 10 << endl;
		LuckVal(a);                                 //抽卡后更改幸运值
	}
	if (a.getLuck() >= 0 && a.getLuck() < 0.65)
	{
		cout << "The number of the card you draw is " << 1 + rand() %  << endl;
	}
}