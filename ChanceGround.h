#ifndef CHANCEGROUND_H
#define CHANCEGROUND_H

//命运格子类
class ChanceGround
{
public:
	bool onCground() { return 1; }         //经过命运格子
	bool Not_onCground() { return 0; }     //路过命运格子
};
#endif // !CHANCEGROUND_H

