#ifndef CARDS_DRAWING_CARDS_SUIT_H
#define CARDS_DRAWING_CARDS_SUIT_H

#include"../Player/Person.h"

extern Person* players;


//牌库类
class CardsSuit
{
public:
	virtual void Show() = 0;			//显示牌库的信息
	void getLuckVal(int player);		//计算幸运值，幸运值与抽到的卡片有关
};


#endif // !CARDS_DRAWING_CARDS_SUIT_H
