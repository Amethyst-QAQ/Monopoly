#ifndef FATE_H
#define FATE_H

#include"Card.h"

//������  �����ƶࣩ
class Fate :public Card
{
public:
	Fate(std::string _name, int _val) : Card (_name, _val) {}  	//���캯������ʼ���¼����ƣ��������ſ�������ֵ
};

#endif // !FATE_H