#ifndef CARDS_DRAWING_FATE_H
#define CARDS_DRAWING_FATE_H

#include"Card.h"

//������  �����ƶࣩ
class Fate :public Card
{
public:
	Fate(std::string _name, int _val,int _num) :Card(_name, _val,_num) {}  	//���캯������ʼ���¼����ƣ��������ſ�������ֵ
};

#endif // !FATE_H