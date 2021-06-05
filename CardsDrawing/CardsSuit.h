#ifndef CARDSSUIT_H
#define CARDSSUIT_H

#include"ChanceSuit.h"
#include"FateSuit.h"

class ChanceSuit
{
private:
	Chance_1 c_1;
public:
	void Show();   //显示卡的信息
};

class FateSuit
{
private:
	Fate_1 f_1;
public:
	void Show();   //显示卡的名称
};


#endif // !CARDSSUIT_H
