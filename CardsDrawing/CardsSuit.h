#ifndef CARDS_DRAWING_CARDS_SUIT_H
#define CARDS_DRAWING_CARDS_SUIT_H

#include"../Player/Player.h"

extern Player* players;


//�ƿ���
class CardsSuit
{
public:
	virtual void show() = 0;					//��ʾ�ƿ����Ϣ
};


#endif // !CARDS_DRAWING_CARDS_SUIT_H
