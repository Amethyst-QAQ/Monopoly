#ifndef CARD_H
#define CARD_H

#include<iostream>
#include<string>

//��Ƭ��
class Card
{
private:
	std::string event;				            //����¼�����
	int val;						            //���ĺû�
	int num;                                    //���
public:
	Card(std::string _event, int _val,int _num);
	std::string doEvent() { return event; }	   //�¼���������
};

#endif
