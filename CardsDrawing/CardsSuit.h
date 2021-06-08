#ifndef CARDS_DRAWING_CARDS_SUIT_H
#define CARDS_DRAWING_CARDS_SUIT_H

#include"../Player/Player.h"

extern Player* players;


//牌库类
class CardsSuit
{
public:
	virtual void show() = 0;					//显示牌库的信息
	void getLuckVal(int player,int _val);	//计算幸运值，幸运值与抽到的卡片有关
};


#endif // !CARDS_DRAWING_CARDS_SUIT_H
