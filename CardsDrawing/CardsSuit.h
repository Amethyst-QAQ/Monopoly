#ifndef CARDSSUIT_H
#define CARDSSUIT_H

#include"../Player/Person.h"


//牌库类
class CardsSuit
{
public:
	virtual void Show();             //显示卡的信息
	virtual Card* Draw();            //抽卡
	void LuckVal(Person& a);         //计算幸运值，幸运值与抽到的卡片有关
};


#endif // !CARDSSUIT_H
