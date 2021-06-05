#ifndef GROUND_ARREST_H
#define GROUND_ARREST_H

#include "Prison.h"
#include "Ground.h"
#include "../Player/Person.h"

///ШыгќИёзг
class Arrest : public Ground
{
public:
	void onStepped(Person& a, Prison* b) 
	{ 
		a.setPosition(b); 
		b->beArrest(a); 
	}
};

#endif