#ifndef GROUND_H
#define GROUND_H

class Ground
{
public:
	virtual void onStepped() {};	//路过的时候调用，纯虚函数
	virtual void onPassed() {};		//经过的时候调用，纯虚函数
};

#endif