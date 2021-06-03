#ifndef FATEGROUND_H
#define FATEGROUND_H
#include"Ground.h"

//命运格子类
class FateGround:public Ground
{
public:
	bool onFground() { return 1; }         //经过命运格子
	bool Not_onFground() { return 0; }     //路过命运格子
};
#endif // !FATEGROUND_H

