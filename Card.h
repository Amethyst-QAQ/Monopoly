#ifndef CARD_H
#define CARD_H

#include<iostream>
#include<string>

//��Ƭ��
class Card
{
private:
	std::string event;				//����¼�����
	int val;						//���ĺû�

public:
	Card(std::string _event, int _val);
	std::string doEvent() { return event; };	//�¼�����
	float LuckVal();							//��������ֵ������ֵ��鵽�Ŀ�Ƭ�й�
};

#endif
