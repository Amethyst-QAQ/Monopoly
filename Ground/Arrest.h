#ifndef GROUND_ARREST_H
#define GROUND_ARREST_H

#include "Prison.h"
#include "Ground.h"
#include "../Player/Person.h"

//��������
class Arrest
{
public:
	void onStepped(Person& a, Prison* b) 
	{ 
		a.setPosition(b); 
		b->beArrest(a); 
	}
};

#endif