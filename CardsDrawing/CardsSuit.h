#ifndef CARDSSUIT_H
#define CARDSSUIT_H

#include"../Player/Person.h"


//�ƿ���
class CardsSuit
{
public:
	virtual void Show();             //��ʾ������Ϣ
	virtual Card* Draw();            //�鿨
	void LuckVal(Person& a);         //��������ֵ������ֵ��鵽�Ŀ�Ƭ�й�
};


#endif // !CARDSSUIT_H
