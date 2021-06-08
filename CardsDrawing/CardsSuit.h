#ifndef CARDS_DRAWING_CARDS_SUIT_H
#define CARDS_DRAWING_CARDS_SUIT_H

#include"../Player/Player.h"

extern Player* players;


//牌库类
class CardsSuit
{
public:
	virtual void show() = 0;					//显示牌库的信息
};


#endif // !CARDS_DRAWING_CARDS_SUIT_H
