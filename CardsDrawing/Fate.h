#ifndef CARDS_DRAWING_FATE_H
#define CARDS_DRAWING_FATE_H

#include"Card.h"

//������  �����ƶࣩ
class Fate :public Card
{
public:
	Fate(std::string name, int val) :Card(name, val) {}          //���캯������ʼ��Fate�����¼�����������ֵ
};

#endif // !FATE_H