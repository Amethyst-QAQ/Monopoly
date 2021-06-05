#ifndef CARDSSUIT_H
#define CARDSSUIT_H

#include"../Player/Person.h"
#include"ChanceSuit/Chance_1.h"

extern Person* players;


//牌库类
class CardsSuit
{
public:
	virtual void Show() = 0;			//显示牌库的信息
	virtual Card* Draw(int player) = 0;	//抽卡
	void getLuckVal(int player);		//计算幸运值，幸运值与抽到的卡片有关
};


#endif // !CARDSSUIT_H
