#ifndef CHANCE_H
#define CHANCE_H

#include"Card.h"

//������ ���õĶࣩ
class Chance : public Card
{
public:
	Chance(std::string _name, int _val, int _num):Card(_name, _val, _num){}  	//���캯������ʼ���¼����ƣ��������ſ�������ֵ
};

#endif