#ifndef CARD_H
#define CARD_H

#include<iostream>

//��Ƭ��
class Card
{
private:
	std::string m_Eventname[10];  //����¼�����
public:
	virtual void doEvent() = 0;  //�¼�����
	float LuckVal();  //��������ֵ������ֵ��鵽�Ŀ�Ƭ�й�
};

#endif
