#ifndef GROUND_CAR_H
#define GROUND_CAR_H

#include <iostream>
#include <string>
#include "Transportation.h"
#include "../Player/Person.h"

class Car :public Transportation         //�����շ�վ��������·��400
{
public:
	Car() { toll = 400; }
};

#endif