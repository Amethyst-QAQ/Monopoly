#include"Person.h"

void LuckVal(Person &a)          //��������ֵ������ֵ��鵽�Ŀ�Ƭ�й�
{
	float luck= a.getLuck();
	luck = 1 - luck * 0.9;        //����luckֵ
	                              //�ÿ������������
	a.setLuck(luck);              //����Person��Luckֵ
}