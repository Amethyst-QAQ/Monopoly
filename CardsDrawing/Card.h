#ifndef CARDS_DRAWING_CARD_H
#define CARDS_DRAWING_CARD_H

#include<iostream>
#include<string>

//��Ƭ��
class Card
{
private:
	std::string event;				            //����¼�����
	int val;						            //���ĺû�,��Ϊ6���ȼ�

public:
	Card(std::string _event, int _val,int _num) : event(_event), val(_val) {}
	virtual void doEvent() {}					//�¼���������
};

#endif
