#ifndef GROUND_PLANE_H
#define GROUND_PLANE_H

#include <string>
#include "Transportation.h"
#include "../Player/Player.h"

class Plane :public Transportation         //�ɻ��շ�վ��������·��800
{
public:
	Plane() { toll = 800; }
};

#endif
