#include"Card.h"
int luck;

Card::Card(std::string _event, int _val)
{
	event = _event;
	val = _val;
}

double Card::LuckVal()  //��������ֵ������ֵ��鵽�Ŀ�Ƭ�й�
{
	luck = 1 - luck * 0.9;  //����luckֵ
	//�ÿ������������
	return luck;
}