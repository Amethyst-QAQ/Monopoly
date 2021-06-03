#ifndef ARREST_H
#define ARREST_H

#include "Prison.h"
#include "Ground.h"
#include "Person.h"

//ШыгќИёзг
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