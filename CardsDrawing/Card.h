#ifndef CARDS_DRAWING_CARD_H
#define CARDS_DRAWING_CARD_H

#include<iostream>
#include<string>

///��Ƭ��
class Card
{
private:
	std::string m_name;				                           //����¼�����
	int m_val;					  	                           //���ĺû�,��Ϊ0~5��6���ȼ�,����ԽСԽ��

public:
	Card(std::string name,int val):m_name(name),m_val(val){}   //���캯������ʼ�������¼�����������ֵ
	
	std::string getName() { return m_name; }                   //��ÿ�������
	int getVal() { return m_val; }                             //��ÿ�������ֵ
	
	virtual void doEvent() {};                                 //����ִ�в�������Ϊ�麯������Ҫ������д
}; 

#endif
