#include "CardsSuit.h"
#include"../Player/Person.h"
using namespace std;

///抽卡系统
void CardsSuit::LuckVal(Person &a)   //计算幸运值，幸运值与抽到的卡片有关
{
	float luck= a.getLuck();
	luck = 1 - luck * 0.9;              //计算luck值
	                                    //好卡坏卡交替出现
	a.setLuck(luck);                    //更新Person的Luck值
}

Card* CardsDrawing::Draw (Person &a)
{
	srand((unsigned int)time(NULL));             //根据系统时间生成随机数
	if (a.getLuck() >= 0.6 && a.getLuck() <= 1)
	{
		//n表示卡的幸运等级，0~5共6级
		//为增加玩家游戏体验感，当n=4/5时，抽到的卡牌为3级；
		//                    当n=6/7时，抽到的卡牌为4级；
		int n = rand() % 9;			           	//输出一个0-8的随机数
		if (n == 4 || n == 5)	n = 3;              
		if (n == 6 || n == 7)	n = 4;
		if (n == 8) n = 5;

		int m;                                  //m表示玩家最终抽到的卡
		if (n == 0)
		{
			m = 0;                              //等级为0的卡牌共有1张
		}
		if (n == 1)
		{
			m = rand() % 2;                     //等级为1的卡牌共有2张
		}
		if (n == 2)
		{
			m = rand() % 3;                     //等级为2的卡牌共有3张
		}
		if (n == 3)
		{
			m = rand() % 7;                     //等级为3的卡牌共有8张
		}
		if (n == 4)
		{
			m = rand() % 7;                     //等级为4的卡牌共有8张
		}
		if (n == 5)
		{
			m = rand() % 3;                     //等级为5的卡牌共有3张
		}

		setVal(n);                              //输入抽到的牌的等级
		setNum(m);                              //输入抽到的牌的编号
	}
}