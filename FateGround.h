#ifndef FATEGROUND_H
#define FATEGROUND_H
#include"Ground.h"

//���˸�����
class FateGround:public Ground
{
public:
	bool onFground() { return 1; }         //�������˸���
	bool Not_onFground() { return 0; }     //·�����˸���
};
#endif // !FATEGROUND_H

