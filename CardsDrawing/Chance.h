#ifndef CARDS_DRAWING_CHANCE_H
#define CARDS_DRAWING_CHANCE_H

#include"Card.h"

///������ �����ƶࣩ
class Chance :public Card
{
public:
	Chance(std::string name, int val) :Card(name, val) {}          //���캯������ʼ��Chance�����¼�����������ֵ
};

#endif