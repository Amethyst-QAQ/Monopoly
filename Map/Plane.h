#ifndef GROUND_PLANE_H
#define GROUND_PLANE_H

#include <string>
#include "Transportation.h"
#include "../Player/Player.h"

class Plane :public Transportation         //飞机收费站，基础过路费800
{
public:
	Plane() { toll = 800; }
};

#endif
