#include "CardsDrawing.h"

using namespace std;

//�鿨ϵͳ

void LuckVal(Person &a)          //��������ֵ������ֵ��鵽�Ŀ�Ƭ�й�
{
	float luck= a.getLuck();
	luck = 1 - luck * 0.9;        //����luckֵ
	                              //�ÿ������������
	a.setLuck(luck);              //����Person��Luckֵ
}

Card* CardsDrawing(Person &a)
{
	srand((unsigned int)time(NULL));                //����ϵͳʱ�����������
	if (a.getLuck() >= 0.6 && a.getLuck() <= 1)
	{
		int n = rand() % 8;								//���һ��0-8�������
		if (n == 4 || n == 5)	n = 3;
		if (n == 6 || n == 7) n = 4;
		if (n == 8) n = 5;
		int m = rand() % 3;//���һ��0-3�������
	}
}