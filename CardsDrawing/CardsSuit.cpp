#include "CardsSuit.h"
#include"../Player/Person.h"

using namespace std;

///�鿨ϵͳ
void CardsSuit::LuckVal(Person &a)   //��������ֵ������ֵ��鵽�Ŀ�Ƭ�й�
{
	float luck= a.getLuck();
	luck = 1 - luck * 0.9;              //����luckֵ
	                                    //�ÿ������������
	a.setLuck(luck);                    //����Person��Luckֵ
}

