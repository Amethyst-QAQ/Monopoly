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
	int m_num;                                                 //����ÿ���ȼ��еı��
public:
	Card(std::string name,int val,int num):m_name(name),m_val(val),m_num(num){}   
	                                                           //���캯������ʼ�������¼�����������ֵ
	std::string getName() { return m_name; }                   //��ÿ�������
	int getVal() { return m_val; }                             //��ÿ�������ֵ
	int getNum() { return m_num; }                             //��ÿ��ı��
	virtual void doEvent() {};                                 //����ִ�в�������Ϊ�麯������Ҫ������д
}; 

#endif