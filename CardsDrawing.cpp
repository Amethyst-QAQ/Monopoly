#include"Person.h"
#include<iostream>
#include<ctime>
using namespace std;

//�鿨ϵͳ

void LuckVal(Person &a)          //��������ֵ������ֵ��鵽�Ŀ�Ƭ�й�
{
	float luck= a.getLuck();
	luck = 1 - luck * 0.9;        //����luckֵ
	                              //�ÿ������������
	a.setLuck(luck);              //����Person��Luckֵ
}

float CardsDrawing(Person &a)
{
	srand((unsigned int)time(NULL));                //����ϵͳʱ�����������
	if (a.getLuck() >= 0.65 && a.getLuck() <= 1)    //�ÿ�
	{
		//Chance�У��ÿ�7�ţ�����3��
		//Fate�У��ÿ�3�ţ�����7��
		if()
		cout << "The number of the card you draw is " << 1 + rand() % 10 << endl;
		LuckVal(a);                                 //�鿨���������ֵ
	}
	if (a.getLuck() >= 0 && a.getLuck() < 0.65)
	{
		cout << "The number of the card you draw is " << 1 + rand() %  << endl;
	}
}