#ifndef CARDS_DRAWING_CHANCE_H
#define CARDS_DRAWING_CHANCE_H

#include"Card.h"

//������ �����ƶࣩ
class Chance : public Card
{
public:
	Chance(std::string _name, int _val, int _num):Card(_name, _val, _num){}  	//���캯������ʼ���¼����ƣ��������ſ�������ֵ
};

#endif