#ifndef GROUND_PLANE_H
#define GROUND_PLANE_H

#include <iostream>
#include <string>
#include "Transportation.h"
#include "../Player/Person.h"

class Plane :public Transportation         //�ɻ��շ�վ��������·��800
{
public:
	Plane() { toll = 800; }
};

#endif
