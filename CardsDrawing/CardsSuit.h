#ifndef CARDSSUIT_H
#define CARDSSUIT_H

#include"ChanceSuit.h"
#include"FateSuit.h"

class ChanceSuit
{
private:
	Chance_1 c_1;
public:
	void Show();   //��ʾ������Ϣ
};

class FateSuit
{
private:
	Fate_1 f_1;
public:
	void Show();   //��ʾ��������
};


#endif // !CARDSSUIT_H
