#include "CardsSuit.h"

void CardsSuit::getLuckVal(int player)   //��������ֵ������ֵ��鵽�Ŀ�Ƭ�й�
{
	Person& p = players[player];
	float luck = p.getLuck();
	luck = 1 - luck * 0.9;              //����luckֵ
										//�ÿ������������
	p.setLuck(luck);                    //����Person��Luckֵ
}