#ifndef FATE_H
#define FATE_H

#include"Card.h"

//������  �����Ķࣩ
class Fate :public Card
{
public:
	Fate(std::string _name, int _val,int _num) :Card(_name, _val,_num) {}  	//���캯������ʼ���¼����ƣ��������ſ�������ֵ
};

#endif // !FATE_H