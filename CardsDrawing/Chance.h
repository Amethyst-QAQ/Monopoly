#ifndef CHANCE_H
#define CHANCE_H

#include"Card.h"

//������ �����ƶࣩ
class Chance : public Card
{
public:
	Chance(std::string _name, int _val): Card(_name, _val) {}  	//���캯������ʼ���¼����ƣ��������ſ�������ֵ
};

#endif