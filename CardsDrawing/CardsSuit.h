#ifndef CARDSSUIT_H
#define CARDSSUIT_H

#include"../Player/Person.h"
#include"ChanceSuit/Chance_1.h"


//�ƿ���
class CardsSuit
{
private:
	Chance_1 c_1;
public:
	virtual void Show();             //��ʾ������Ϣ
	virtual Card* Draw();            //�鿨
	void LuckVal(Person& a);         //��������ֵ������ֵ��鵽�Ŀ�Ƭ�й�
};


#endif // !CARDSSUIT_H
