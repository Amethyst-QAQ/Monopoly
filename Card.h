#pragma once
#include<iostream>  

//��Ƭ��
class Card
{
protected:
	std::string m_Eventname[10];  //����¼�����
public:
	virtual void doEvent();  //�¼�����
	double LuckVal();  //��������ֵ������ֵ��鵽�Ŀ�Ƭ�й�
};