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

Card* CardsDrawing::Draw (Person &a)
{
	srand((unsigned int)time(NULL));             //����ϵͳʱ�����������
	if (a.getLuck() >= 0.6 && a.getLuck() <= 1)
	{
		//n��ʾ�������˵ȼ���0~5��6��
		//Ϊ���������Ϸ����У���n=4/5ʱ���鵽�Ŀ���Ϊ3����
		//                    ��n=6/7ʱ���鵽�Ŀ���Ϊ4����
		int n = rand() % 9;			           	//���һ��0-8�������
		if (n == 4 || n == 5)	n = 3;              
		if (n == 6 || n == 7)	n = 4;
		if (n == 8) n = 5;

		int m;                                  //m��ʾ������ճ鵽�Ŀ�
		if (n == 0)
		{
			m = 0;                              //�ȼ�Ϊ0�Ŀ��ƹ���1��
		}
		if (n == 1)
		{
			m = rand() % 2;                     //�ȼ�Ϊ1�Ŀ��ƹ���2��
		}
		if (n == 2)
		{
			m = rand() % 3;                     //�ȼ�Ϊ2�Ŀ��ƹ���3��
		}
		if (n == 3)
		{
			m = rand() % 7;                     //�ȼ�Ϊ3�Ŀ��ƹ���8��
		}
		if (n == 4)
		{
			m = rand() % 7;                     //�ȼ�Ϊ4�Ŀ��ƹ���8��
		}
		if (n == 5)
		{
			m = rand() % 3;                     //�ȼ�Ϊ5�Ŀ��ƹ���3��
		}

		setVal(n);                              //����鵽���Ƶĵȼ�
		setNum(m);                              //����鵽���Ƶı��
	}
}