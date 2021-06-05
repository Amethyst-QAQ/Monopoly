#ifndef GROUND_CAR_H
#define GROUND_CAR_H

#include <string>
#include "Transportation.h"
#include "../Player/Player.h"

class Car :public Transportation         //汽车收费站，基础过路费400
{
public:
	Car() { toll = 400; }
};

#endif