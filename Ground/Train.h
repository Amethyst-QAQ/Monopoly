#ifndef GROUND_TRAIN_H
#define GROUND_TRAIN_H

#include <iostream>
#include <string>
#include "Transportation.h"
#include "../Player/Person.h"

class Train :public Transportation         //���շ�վ��������·��200
{
public:
	Train() { toll = 200; }
};

#endif
