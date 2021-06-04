#ifndef GROUND_GROUND_H
#define GROUND_GROUND_H

//格子类
class Ground
{
public:
	virtual void onStepped(int player) {};	//路过的时候调用，虚函数
	virtual void onPassed(int player) {};		//经过的时候调用，虚函数
};

#endif