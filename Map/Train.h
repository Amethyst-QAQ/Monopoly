#ifndef GROUND_TRAIN_H
#define GROUND_TRAIN_H

#include <string>
#include "Transportation.h"
#include "../Player/Player.h"

class Train :public Transportation         //���շ�վ��������·��200
{
public:
	Train() { toll = 200; }
};

#endif
