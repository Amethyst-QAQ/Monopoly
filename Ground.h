#ifndef GROUND_H
#define GROUND_H

class Ground
{
public:
	virtual void onStepped() = 0;	//·����ʱ����ã����麯��
	virtual void passed() = 0;		//������ʱ����ã����麯��
};

#endif