#ifndef CARDS_DRAWING_CARDS_SUIT_H
#define CARDS_DRAWING_CARDS_SUIT_H

#include"../Player/Person.h"

extern Person* players;


//�ƿ���
class CardsSuit
{
public:
	virtual void Show() = 0;			//��ʾ�ƿ����Ϣ
	void getLuckVal(int player);		//��������ֵ������ֵ��鵽�Ŀ�Ƭ�й�
};


#endif // !CARDS_DRAWING_CARDS_SUIT_H
