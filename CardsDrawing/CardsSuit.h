#ifndef CARDSSUIT_H
#define CARDSSUIT_H

#include"../Player/Person.h"
#include"ChanceSuit/Chance_1.h"

extern Person* players;


//�ƿ���
class CardsSuit
{
public:
	virtual void Show() = 0;			//��ʾ�ƿ����Ϣ
	virtual Card* Draw(int player) = 0;	//�鿨
	void getLuckVal(int player);		//��������ֵ������ֵ��鵽�Ŀ�Ƭ�й�
};


#endif // !CARDSSUIT_H
