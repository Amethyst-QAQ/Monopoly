#include"Card.h"
int luck;

double Card::LuckVal()  //��������ֵ������ֵ��鵽�Ŀ�Ƭ�й�
{
	luck = 1 - luck * 0.9;  //����luckֵ
	//�ÿ������������
	return luck;
}