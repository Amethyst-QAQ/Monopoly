#ifndef GROUND_PLANE_H
#define GROUND_PLANE_H

#include <iostream>
#include <string>
#include "Transportation.h"
#include "../Player/Person.h"

class Plane :public Transportation         //�ɻ��շ�վ��������·��800
{
public:
	Plane(std::string _name) :Transportation(_name, 800) {}
};

#endif
