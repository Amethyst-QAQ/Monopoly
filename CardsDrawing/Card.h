#ifndef CARDS_DRAWING_CARD_H
#define CARDS_DRAWING_CARD_H

#include "../Player/Output.h"

///��Ƭ��

class Card
{
private:
	std::string name;	//����¼�����
	int val;			//���ĵȼ�,��Ϊ0~5��6���ȼ�,����ԽСԽ��
	int num;			//����ÿ���ȼ��еı��

public:
	Card(std::string _name, 
		 int _val, 
		 int _num) : name(_name), 
					 val(_val), 
					 num(_num) {}

	int getVal() { return val; }			//��ÿ�������ֵ
	int getNum() { return num; }			//��ÿ��ı��

	virtual void show();					//�������������Ϣ
	virtual void doEvent() = 0;				//����ִ�в�������Ϊ�麯������Ҫ������д
}; 

#endif