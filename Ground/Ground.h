#ifndef GROUND_GROUND_H
#define GROUND_GROUND_H

//������
class Ground
{
public:
	virtual void onStepped(int player) {};	//·����ʱ����ã��麯��
	virtual void onPassed(int player) {};		//������ʱ����ã��麯��
};

#endif